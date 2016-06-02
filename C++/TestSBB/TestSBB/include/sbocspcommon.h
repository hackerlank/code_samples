#ifndef __INC_SBOCSPCOMMON
#define __INC_SBOCSPCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbcustomcertstorage.h"
#include "sbasn1.h"
#include "sbasn1tree.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_OCSP 	77824
#define SB_ERROR_OCSP_PROTOCOL_ERROR_FLAG 	2048
#define SB_OCSP_ERROR_NO_CERTIFICATES 	79873
#define SB_OCSP_ERROR_NO_ISSUER_CERTIFICATES 	79874
#define SB_OCSP_ERROR_WRONG_DATA 	79875
#define SB_OCSP_ERROR_NO_EVENT_HANDLER 	79876
#define SB_OCSP_ERROR_NO_PARAMETERS 	79877
#define SB_OCSP_ERROR_NO_REPLY 	79878
#define SB_OCSP_ERROR_WRONG_SIGNATURE 	79879
#define SB_OCSP_ERROR_UNSUPPORTED_ALGORITHM 	79880
#define SB_OCSP_ERROR_INVALID_RESPONSE 	79881
#define SB_OCSP_OID_BASIC_RESPONSE 	"+\x06""\x01""\x05""\x05""\a0\x01""\x01"
#define SB_OCSP_OID_NONCE 	"+\x06""\x01""\x05""\x05""\a0\x01""\x02"
#define SB_OCSP_OID_OCSP_RESPONSE 	"+\x06""\x01""\x05""\x05""\a0\x01""\x04"
#define SB_OID_OCSP_RESPONSE 	"+\x06""\x01""\x05""\x05""\a\x10""\x02"

typedef TElClassHandle TElOCSPClassHandle;

typedef TElOCSPClassHandle ElOCSPClassHandle;

typedef uint8_t TElOCSPServerErrorRaw;

typedef enum
{
	oseSuccessful = 0,
	oseMalformedRequest = 1,
	oseInternalError = 2,
	oseTryLater = 3,
	oseUnused1 = 4,
	oseSigRequired = 5,
	oseUnauthorized = 6
} TElOCSPServerError;

typedef uint8_t TElOCSPCertificateStatusRaw;

typedef enum
{
	csGood = 0,
	csRevoked = 1,
	csUnknown = 2
} TElOCSPCertificateStatus;

typedef uint8_t TElResponderIDTypeRaw;

typedef enum
{
	ritName = 0,
	ritKeyHash = 1
} TElResponderIDType;

typedef void (SB_CALLBACK *TSBCertificateOCSPCheckEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pHashAlgOID[], int32_t szHashAlgOID, const uint8_t pIssuerNameHash[], int32_t szIssuerNameHash, const uint8_t pIssuerKeyHash[], int32_t szIssuerKeyHash, const uint8_t pCertificateSerial[], int32_t szCertificateSerial, TElOCSPCertificateStatusRaw * CertStatus, TSBCRLReasonFlagRaw * Reason, int64_t * RevocationTime, int64_t * ThisUpdate, int64_t * NextUpdate);

typedef void (SB_CALLBACK *TSBOCSPSignatureValidateEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * Valid);

typedef void (SB_CALLBACK *TSBOCSPCertificateNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle * Certificate);

#ifdef SB_USE_CLASS_TELOCSPCLASS
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClass_get_RequestorName(TElOCSPClassHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClass_get_IncludeCertificates(TElOCSPClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClass_set_IncludeCertificates(TElOCSPClassHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClass_get_SigningCertStorage(TElOCSPClassHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClass_set_SigningCertStorage(TElOCSPClassHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClass_get_OnCertificateNeeded(TElOCSPClassHandle _Handle, TSBOCSPCertificateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClass_set_OnCertificateNeeded(TElOCSPClassHandle _Handle, TSBOCSPCertificateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClass_Create(TComponentHandle Owner, TElOCSPClassHandle * OutResult);
#endif /* SB_USE_CLASS_TELOCSPCLASS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOCSPClass;
typedef TElOCSPClass ElOCSPClass;

#ifdef SB_USE_CLASS_TELOCSPCLASS
class TElOCSPClass: public TComponent
{
	private:
		SB_DISABLE_COPY(TElOCSPClass)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_RequestorName;
#endif /* SB_USE_CLASS_TELGENERALNAME */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_SigningCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_RequestorName();

		SB_DECLARE_PROPERTY_GET(TElGeneralName*, get_RequestorName, TElOCSPClass, RequestorName);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		virtual bool get_IncludeCertificates();

		virtual void set_IncludeCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeCertificates, set_IncludeCertificates, TElOCSPClass, IncludeCertificates);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_SigningCertStorage();

		virtual void set_SigningCertStorage(TElCustomCertStorage &Value);

		virtual void set_SigningCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_SigningCertStorage, set_SigningCertStorage, TElOCSPClass, SigningCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_OnCertificateNeeded(TSBOCSPCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeeded(TSBOCSPCertificateNeededEvent pMethodValue, void * pDataValue);

		TElOCSPClass(TElOCSPClassHandle handle, TElOwnHandle ownHandle);

		explicit TElOCSPClass(TComponent &Owner);

		explicit TElOCSPClass(TComponent *Owner);

		virtual ~TElOCSPClass();

};
#endif /* SB_USE_CLASS_TELOCSPCLASS */

#ifdef SB_USE_GLOBAL_PROCS_OCSPCOMMON

int32_t ReasonFlagToEnum(TSBCRLReasonFlag Value);

TSBCRLReasonFlag EnumToReasonFlag(int32_t Value);

void ReadAsnInteger(const std::vector<uint8_t> &IntBuf, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_OCSPCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_OCSPCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBOCSPCommon_ReasonFlagToEnum(TSBCRLReasonFlagRaw Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOCSPCommon_EnumToReasonFlag(int32_t Value, TSBCRLReasonFlagRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOCSPCommon_ReadAsnInteger(const uint8_t pIntBuf[], int32_t szIntBuf, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_OCSPCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOCSPCOMMON */

