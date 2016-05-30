#ifndef __INC_SBSMIMECADES
#define __INC_SBSMIMECADES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbmime.h"
#include "sbmimestream.h"
#include "sbsmimecore.h"
#include "sbcustomcertstorage.h"
#include "sbcertvalidator.h"
#include "sbx509.h"
#include "sbpkicommon.h"
#include "sbcades.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SMIME_ERROR_CADES_BASE 	82176
#define SB_SMIME_ERROR_NO_CADESREVOCATION_INFO 	82177

typedef TElClassHandle TElMessagePartHandlerSMimeCAdESHandle;

typedef void (SB_CALLBACK *TSBSMimeCAdESSign)(void * _ObjectData, TObjectHandle Sender, TElCAdESSignatureProcessorHandle Processor);

typedef void (SB_CALLBACK *TSBSMimeCAdESValidate)(void * _ObjectData, TObjectHandle Sender, TElCAdESSignatureProcessorHandle Processor);

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIMECADES
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_GetDescription(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_GetDescription_1(TElMessagePartHandlerSMimeCAdESHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_get_UseCAdES(TElMessagePartHandlerSMimeCAdESHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_set_UseCAdES(TElMessagePartHandlerSMimeCAdESHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_get_CAdESValidity(TElMessagePartHandlerSMimeCAdESHandle _Handle, TSBCAdESSignatureValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_get_CAdESErrorCode(TElMessagePartHandlerSMimeCAdESHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_get_CAdESCertValidity(TElMessagePartHandlerSMimeCAdESHandle _Handle, TSBCertificateValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_get_CAdESReason(TElMessagePartHandlerSMimeCAdESHandle _Handle, TSBCertificateValidityReasonRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_get_OnSign(TElMessagePartHandlerSMimeCAdESHandle _Handle, TSBSMimeCAdESSign * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_set_OnSign(TElMessagePartHandlerSMimeCAdESHandle _Handle, TSBSMimeCAdESSign pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_get_OnValidate(TElMessagePartHandlerSMimeCAdESHandle _Handle, TSBSMimeCAdESValidate * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_set_OnValidate(TElMessagePartHandlerSMimeCAdESHandle _Handle, TSBSMimeCAdESValidate pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMimeCAdES_Create(TObjectHandle aParams, TElMessagePartHandlerSMimeCAdESHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIMECADES */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElMessagePartHandlerSMimeCAdES;

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIMECADES
class TElMessagePartHandlerSMimeCAdES: public TElMessagePartHandlerSMime
{
	private:
		SB_DISABLE_COPY(TElMessagePartHandlerSMimeCAdES)
	public:
		static void GetDescription(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDescription(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDescription_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDescription_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static TClassHandle ClassType();

		virtual bool get_UseCAdES();

		virtual void set_UseCAdES(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCAdES, set_UseCAdES, TElMessagePartHandlerSMimeCAdES, UseCAdES);

		virtual TSBCAdESSignatureValidity get_CAdESValidity();

		SB_DECLARE_PROPERTY_GET(TSBCAdESSignatureValidity, get_CAdESValidity, TElMessagePartHandlerSMimeCAdES, CAdESValidity);

		virtual int32_t get_CAdESErrorCode();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CAdESErrorCode, TElMessagePartHandlerSMimeCAdES, CAdESErrorCode);

		virtual TSBCertificateValidity get_CAdESCertValidity();

		SB_DECLARE_PROPERTY_GET(TSBCertificateValidity, get_CAdESCertValidity, TElMessagePartHandlerSMimeCAdES, CAdESCertValidity);

		virtual TSBCertificateValidityReason get_CAdESReason();

		SB_DECLARE_PROPERTY_GET(TSBCertificateValidityReason, get_CAdESReason, TElMessagePartHandlerSMimeCAdES, CAdESReason);

		virtual void get_OnSign(TSBSMimeCAdESSign &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSign(TSBSMimeCAdESSign pMethodValue, void * pDataValue);

		virtual void get_OnValidate(TSBSMimeCAdESValidate &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnValidate(TSBSMimeCAdESValidate pMethodValue, void * pDataValue);

		TElMessagePartHandlerSMimeCAdES(TElMessagePartHandlerSMimeCAdESHandle handle, TElOwnHandle ownHandle);

		explicit TElMessagePartHandlerSMimeCAdES(TObject &aParams);

		explicit TElMessagePartHandlerSMimeCAdES(TObject *aParams);

};
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIMECADES */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSMIMECADES */

