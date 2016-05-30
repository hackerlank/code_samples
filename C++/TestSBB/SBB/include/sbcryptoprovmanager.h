#ifndef __INC_SBCRYPTOPROVMANAGER
#define __INC_SBCRYPTOPROVMANAGER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsharedresource.h"
#include "sbcryptoprov.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElBuiltInCryptoProviderManagerHandle;

typedef TElClassHandle TElFIPSCompliantCryptoProviderManagerHandle;

typedef uint8_t TSBCryptoEngineTypeRaw;

typedef enum
{
	cetDefault = 0,
	cetFIPS = 1,
	cetCustom = 2
} TSBCryptoEngineType;

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderManager_Init(TElBuiltInCryptoProviderManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderManager_Deinit(TElBuiltInCryptoProviderManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderManager_IsProviderAllowed(TElBuiltInCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle Prov, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderManager_get_EngineType(TElBuiltInCryptoProviderManagerHandle _Handle, TSBCryptoEngineTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderManager_set_EngineType(TElBuiltInCryptoProviderManagerHandle _Handle, TSBCryptoEngineTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderManager_get_BuiltInCryptoProvider(TElBuiltInCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderManager_get_Win32CryptoProvider(TElBuiltInCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInCryptoProviderManager_Create(TComponentHandle AOwner, TElCustomCryptoProviderManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElFIPSCompliantCryptoProviderManager_Init(TElFIPSCompliantCryptoProviderManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFIPSCompliantCryptoProviderManager_Deinit(TElFIPSCompliantCryptoProviderManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFIPSCompliantCryptoProviderManager_IsProviderAllowed(TElFIPSCompliantCryptoProviderManagerHandle _Handle, TElCustomCryptoProviderHandle Prov, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFIPSCompliantCryptoProviderManager_Create(TComponentHandle AOwner, TElCustomCryptoProviderManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBuiltInCryptoProviderManager;
class TElFIPSCompliantCryptoProviderManager;

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER
class TElBuiltInCryptoProviderManager: public TElCustomCryptoProviderManager
{
	private:
		SB_DISABLE_COPY(TElBuiltInCryptoProviderManager)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_BuiltInCryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_Win32CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void initInstances();

	public:
		virtual void Init();

		virtual void Deinit();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual bool IsProviderAllowed(TElCustomCryptoProvider &Prov);

		virtual bool IsProviderAllowed(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual TSBCryptoEngineType get_EngineType();

		virtual void set_EngineType(TSBCryptoEngineType Value);

		SB_DECLARE_PROPERTY(TSBCryptoEngineType, get_EngineType, set_EngineType, TElBuiltInCryptoProviderManager, EngineType);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_BuiltInCryptoProvider();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoProvider*, get_BuiltInCryptoProvider, TElBuiltInCryptoProviderManager, BuiltInCryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_Win32CryptoProvider();

		SB_DECLARE_PROPERTY_GET(TElCustomCryptoProvider*, get_Win32CryptoProvider, TElBuiltInCryptoProviderManager, Win32CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		TElBuiltInCryptoProviderManager(TElBuiltInCryptoProviderManagerHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInCryptoProviderManager(TComponent &AOwner);

		explicit TElBuiltInCryptoProviderManager(TComponent *AOwner);

		virtual ~TElBuiltInCryptoProviderManager();

};
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER
class TElFIPSCompliantCryptoProviderManager: public TElCustomCryptoProviderManager
{
	private:
		SB_DISABLE_COPY(TElFIPSCompliantCryptoProviderManager)
	public:
		virtual void Init();

		virtual void Deinit();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual bool IsProviderAllowed(TElCustomCryptoProvider &Prov);

		virtual bool IsProviderAllowed(TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		TElFIPSCompliantCryptoProviderManager(TElFIPSCompliantCryptoProviderManagerHandle handle, TElOwnHandle ownHandle);

		explicit TElFIPSCompliantCryptoProviderManager(TComponent &AOwner);

		explicit TElFIPSCompliantCryptoProviderManager(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVMANAGER

#ifdef SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER
TElBuiltInCryptoProviderManagerHandle DefaultCryptoProviderManager();
#endif /* SB_USE_CLASS_TELBUILTINCRYPTOPROVIDERMANAGER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER
TElFIPSCompliantCryptoProviderManagerHandle FIPSCompliantCryptoProviderManager();
#endif /* SB_USE_CLASS_TELFIPSCOMPLIANTCRYPTOPROVIDERMANAGER */
#endif

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVMANAGER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVMANAGER
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvManager_DefaultCryptoProviderManager(TElBuiltInCryptoProviderManagerHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvManager_FIPSCompliantCryptoProviderManager(TElFIPSCompliantCryptoProviderManagerHandle * OutResult);
#endif
#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVMANAGER */
