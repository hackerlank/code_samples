#ifndef __INC_SBGSSWINAUTH
#define __INC_SBGSSWINAUTH

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbgssapibase.h"
#include "sbgssapi.h"
#include "sbsspi.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef SB_WINDOWS
#define SB_GSS_MECH_NTLM 	"+\x06""\x01""\x04""\x82""7\x02""\x02""\n"
#define SB_GSS_MECH_KRB5 	"*\x86""H\x86""\xF7""\x12""\x01""\x02""\x02"

typedef TElClassHandle TElGSSWinContextHandle;

typedef TElClassHandle TElGSSWinNameHandle;

typedef TElClassHandle TElGSSWinAuthMechanismHandle;

typedef uint32_t TElGSSWinAuthProtocolsRaw;

typedef enum 
{
	f_apKerberos = 1,
	f_apNTLM = 2
} TElGSSWinAuthProtocols;

#ifdef SB_USE_CLASS_TELGSSWINCONTEXT
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinContext_Create(TElGSSWinContextHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSWINCONTEXT */

#ifdef SB_USE_CLASS_TELGSSWINNAME
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinName_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSWINNAME */

#ifdef SB_USE_CLASS_TELGSSWINAUTHMECHANISM
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_Initialize(TElGSSWinAuthMechanismHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_AcquireCred(TElGSSWinAuthMechanismHandle _Handle, const uint8_t pMechOID[], int32_t szMechOID, TElGSSCustomContextHandle * Ctx, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_AcceptSecContext(TElGSSWinAuthMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, TElGSSCustomNameHandle SourceName, const uint8_t pInputToken[], int32_t szInputToken, uint8_t pOutputToken[], int32_t * szOutputToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_InitSecContext(TElGSSWinAuthMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, TElGSSCustomNameHandle TargetName, int8_t DelegateCred, const uint8_t pInputToken[], int32_t szInputToken, uint8_t pOutputToken[], int32_t * szOutputToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_ReleaseContext(TElGSSWinAuthMechanismHandle _Handle, TElGSSCustomContextHandle * Ctx, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_ImportName(TElGSSWinAuthMechanismHandle _Handle, const uint8_t pMechOID[], int32_t szMechOID, const char * pcInputName, int32_t szInputName, TElGSSCustomNameHandle * OutputName, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_ReleaseName(TElGSSWinAuthMechanismHandle _Handle, TElGSSCustomNameHandle * Name, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_GetMIC(TElGSSWinAuthMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, const uint8_t pMessageBuffer[], int32_t szMessageBuffer, uint8_t pMessageToken[], int32_t * szMessageToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_VerifyMIC(TElGSSWinAuthMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, const uint8_t pMessageBuffer[], int32_t szMessageBuffer, const uint8_t pMessageToken[], int32_t szMessageToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_get_AuthProtocols(TElGSSWinAuthMechanismHandle _Handle, TElGSSWinAuthProtocolsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_set_AuthProtocols(TElGSSWinAuthMechanismHandle _Handle, TElGSSWinAuthProtocolsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSWinAuthMechanism_Create(TElGSSWinAuthMechanismHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSWINAUTHMECHANISM */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef SB_WINDOWS
#ifdef __cplusplus

// Class forward declaration
class TElGSSWinContext;
class TElGSSWinName;
class TElGSSWinAuthMechanism;

SB_DEFINE_ENUM_FLAG_OPERATORS(TElGSSWinAuthProtocols)

#ifdef SB_USE_CLASS_TELGSSWINCONTEXT
class TElGSSWinContext: public TElGSSCustomContext
{
	private:
		SB_DISABLE_COPY(TElGSSWinContext)
	public:
		TElGSSWinContext(TElGSSWinContextHandle handle, TElOwnHandle ownHandle);

		TElGSSWinContext();

};
#endif /* SB_USE_CLASS_TELGSSWINCONTEXT */

#ifdef SB_USE_CLASS_TELGSSWINNAME
class TElGSSWinName: public TElGSSCustomName
{
	private:
		SB_DISABLE_COPY(TElGSSWinName)
	public:
		TElGSSWinName(TElGSSWinNameHandle handle, TElOwnHandle ownHandle);

		TElGSSWinName();

};
#endif /* SB_USE_CLASS_TELGSSWINNAME */

#ifdef SB_USE_CLASS_TELGSSWINAUTHMECHANISM
class TElGSSWinAuthMechanism: public TElGSSBaseMechanism
{
	private:
		SB_DISABLE_COPY(TElGSSWinAuthMechanism)
	public:
		virtual bool Initialize();

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t AcquireCred(const std::vector<uint8_t> &MechOID, TElGSSCustomContext &Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
		virtual uint32_t AcceptSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);

		virtual uint32_t AcceptSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
		virtual uint32_t InitSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);

		virtual uint32_t InitSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t ReleaseContext(TElGSSCustomContext &Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
		virtual uint32_t ImportName(const std::vector<uint8_t> &MechOID, const std::string &InputName, TElGSSCustomName &OutputName);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
		virtual uint32_t ReleaseName(TElGSSCustomName &Name);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t GetMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken);

		virtual uint32_t GetMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t VerifyMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken);

		virtual uint32_t VerifyMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

		virtual TElGSSWinAuthProtocols get_AuthProtocols();

		virtual void set_AuthProtocols(TElGSSWinAuthProtocols Value);

		SB_DECLARE_PROPERTY(TElGSSWinAuthProtocols, get_AuthProtocols, set_AuthProtocols, TElGSSWinAuthMechanism, AuthProtocols);

		TElGSSWinAuthMechanism(TElGSSWinAuthMechanismHandle handle, TElOwnHandle ownHandle);

		TElGSSWinAuthMechanism();

};
#endif /* SB_USE_CLASS_TELGSSWINAUTHMECHANISM */

#endif  /* __cplusplus */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGSSWINAUTH */
