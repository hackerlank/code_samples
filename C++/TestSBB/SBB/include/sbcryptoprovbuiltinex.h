#ifndef __INC_SBCRYPTOPROVBUILTINEX
#define __INC_SBCRYPTOPROVBUILTINEX

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovbuiltin.h"
#include "sbcryptoprovbuiltinsym.h"
#include "sbcryptoprovrs.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbidea.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElBuiltInExtendedCryptoProviderHandle;

typedef TElClassHandle TElBuiltInExtendedSymmetricCryptoFactoryHandle;

typedef TElClassHandle TElBuiltInIDEASymmetricCryptoHandle;

#ifdef SB_USE_CLASS_TELBUILTINEXTENDEDCRYPTOPROVIDER
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInExtendedCryptoProvider_GetDefaultInstance(TElBuiltInExtendedCryptoProviderHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInExtendedCryptoProvider_SetAsDefault();
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInExtendedCryptoProvider_SetAsDefault_1(TElBuiltInExtendedCryptoProviderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInExtendedCryptoProvider_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInExtendedCryptoProvider_Create(TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInExtendedCryptoProvider_Create_1(TElCustomCryptoProviderOptionsHandle Options, TComponentHandle AOwner, TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINEXTENDEDCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELBUILTINEXTENDEDSYMMETRICCRYPTOFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInExtendedSymmetricCryptoFactory_Create(TElBuiltInSymmetricCryptoFactoryHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINEXTENDEDSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELBUILTINIDEASYMMETRICCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIDEASymmetricCrypto_InitializeEncryption(TElBuiltInIDEASymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIDEASymmetricCrypto_InitializeDecryption(TElBuiltInIDEASymmetricCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIDEASymmetricCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIDEASymmetricCrypto_Create(int32_t AlgID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInIDEASymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIDEASymmetricCrypto_Create_1(const uint8_t pAlgOID[], int32_t szAlgOID, TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInIDEASymmetricCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInIDEASymmetricCrypto_Create_2(TSBBuiltInSymmetricCryptoModeRaw Mode, TElBuiltInIDEASymmetricCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINIDEASYMMETRICCRYPTO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBuiltInExtendedCryptoProvider;
class TElBuiltInExtendedSymmetricCryptoFactory;
class TElBuiltInIDEASymmetricCrypto;

#ifdef SB_USE_CLASS_TELBUILTINEXTENDEDCRYPTOPROVIDER
class TElBuiltInExtendedCryptoProvider: public TElBuiltInCryptoProvider
{
	private:
		SB_DISABLE_COPY(TElBuiltInExtendedCryptoProvider)
	public:
		virtual TElCustomCryptoProviderHandle GetDefaultInstance();

		static void SetAsDefault();

		virtual void SetAsDefault_Inst();

		static TClassHandle ClassType();

		TElBuiltInExtendedCryptoProvider(TElBuiltInExtendedCryptoProviderHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInExtendedCryptoProvider(TComponent &AOwner);

		explicit TElBuiltInExtendedCryptoProvider(TComponent *AOwner);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
		TElBuiltInExtendedCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner);

		TElBuiltInExtendedCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

};
#endif /* SB_USE_CLASS_TELBUILTINEXTENDEDCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELBUILTINEXTENDEDSYMMETRICCRYPTOFACTORY
class TElBuiltInExtendedSymmetricCryptoFactory: public TElBuiltInSymmetricCryptoFactory
{
	private:
		SB_DISABLE_COPY(TElBuiltInExtendedSymmetricCryptoFactory)
	public:
		TElBuiltInExtendedSymmetricCryptoFactory(TElBuiltInExtendedSymmetricCryptoFactoryHandle handle, TElOwnHandle ownHandle);

		TElBuiltInExtendedSymmetricCryptoFactory();

};
#endif /* SB_USE_CLASS_TELBUILTINEXTENDEDSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELBUILTINIDEASYMMETRICCRYPTO
class TElBuiltInIDEASymmetricCrypto: public TElBuiltInSymmetricCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInIDEASymmetricCrypto)
	public:
		virtual void InitializeEncryption();

		virtual void InitializeDecryption();

		static TClassHandle ClassType();

		TElBuiltInIDEASymmetricCrypto(TElBuiltInIDEASymmetricCryptoHandle handle, TElOwnHandle ownHandle);

		TElBuiltInIDEASymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode);

		TElBuiltInIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode);

		explicit TElBuiltInIDEASymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode);

};
#endif /* SB_USE_CLASS_TELBUILTINIDEASYMMETRICCRYPTO */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTINEX

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProviderHandle BuiltInCryptoProviderEx();
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTINEX */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTINEX
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvBuiltInEx_BuiltInCryptoProviderEx(TElCustomCryptoProviderHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTINEX */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVBUILTINEX */

