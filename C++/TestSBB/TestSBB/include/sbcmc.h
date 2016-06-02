#ifndef __INC_SBCMC
#define __INC_SBCMC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbpkcs10.h"
#include "sbx509.h"
#include "sbx509ex.h"
#include "sbx509ext.h"
#include "sbcrlstorage.h"
#include "sbcustomcertstorage.h"
#include "sbalgorithmidentifier.h"
#include "sbcms.h"
#include "sbencoding.h"
#include "sbrdn.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_CMC_STATUS_SUCCESS 	0
#define SB_CMC_STATUS_RESERVED 	1
#define SB_CMC_STATUS_FAILED 	2
#define SB_CMC_STATUS_PENDING 	3
#define SB_CMC_STATUS_NO_SUPPORT 	4
#define SB_CMC_STATUS_CONFIRM_REQUIRED 	5
#define SB_CMC_STATUS_POP_REQUIRED 	6
#define SB_CMC_STATUS_PARTIAL 	7
#define SB_CMC_FAIL_INFO_BAD_ALG 	0
#define SB_CMC_FAIL_INFO_BAD_MESSAGE_CHECK 	1
#define SB_CMC_FAIL_INFO_BAD_REQUEST 	2
#define SB_CMC_FAIL_INFO_BAD_TIME 	3
#define SB_CMC_FAIL_INFO_BAD_CERT_ID 	4
#define SB_CMC_FAIL_INFO_UNSUPPORTED_EXT 	5
#define SB_CMC_FAIL_INFO_MUST_ARCHIVE_KEYS 	6
#define SB_CMC_FAIL_INFO_BAD_IDENTITY 	7
#define SB_CMC_FAIL_INFO_POP_REQUIRED 	8
#define SB_CMC_FAIL_INFO_POP_FAILED 	9
#define SB_CMC_FAIL_INFO_NO_KEY_REUSE 	10
#define SB_CMC_FAIL_INFO_INTERNAL_CA_ERROR 	11
#define SB_CMC_FAIL_INFO_TRY_LATER 	12
#define SB_CMC_FAIL_INFO_AUTH_DATA_FAIL 	13

typedef TElClassHandle TElAttributeValueHandle;

typedef TElClassHandle TElTaggedAttributeHandle;

typedef TElClassHandle TElTaggedCertificationRequestHandle;

typedef TElClassHandle TElExternallyDefinedCertificationRequestHandle;

typedef TElClassHandle TElTaggedRequestHandle;

typedef TElClassHandle TElContentInfoHandle;

typedef TElClassHandle TElTaggedContentInfoHandle;

typedef TElClassHandle TElOtherMsgHandle;

typedef TElClassHandle TElPKIDataHandle;

typedef TElClassHandle TElPKIResponseHandle;

typedef TElClassHandle TElControlAttributeHandle;

typedef TElClassHandle TElIdentificationAttributeHandle;

typedef TElClassHandle TElPendInfoHandle;

typedef TElClassHandle TElCMCStatusInfoAttributeHandle;

typedef TElClassHandle TElBodyPartReferenceHandle;

typedef TElClassHandle TElBodyPartIDHandle;

typedef TElClassHandle TElBodyPartPathHandle;

typedef TElClassHandle TElExtendedFailInfoHandle;

typedef TElClassHandle TElCMCStatusInfoV2AttributeHandle;

typedef TElClassHandle TElAddExtensionsAttributeHandle;

typedef TElClassHandle TElIdentityProofV2AttributeHandle;

typedef TElClassHandle TElIdentityProofAttributeHandle;

typedef TElClassHandle TElPopLinkWitnessV2AttributeHandle;

typedef TElClassHandle TElPopLinkWitnessAttributeHandle;

typedef TElClassHandle TElDataReturnAttributeHandle;

typedef TElClassHandle TElTransactionIdentifierAttributeHandle;

typedef TElClassHandle TElSenderNonceAttributeHandle;

typedef TElClassHandle TElRecipientNonceAttributeHandle;

typedef TElClassHandle TElEncryptedPopAttributeHandle;

typedef TElClassHandle TElDecryptedPopAttributeHandle;

typedef TElClassHandle TElLraPopWitnessAttributeHandle;

typedef TElClassHandle TElGetCertificateAttributeHandle;

typedef TElClassHandle TElGetCRLAttributeHandle;

typedef TElClassHandle TElRevocationRequestAttributeHandle;

typedef TElClassHandle TElRegistrationInformationAttributeHandle;

typedef TElClassHandle TElResponseInformationAttributeHandle;

typedef TElClassHandle TElQueryPendingAttributeHandle;

typedef TElClassHandle TElConfirmCertAcceptanceAttributeHandle;

typedef TElClassHandle TElPublishTrustAnchorsAttributeHandle;

typedef TElClassHandle TElAuthenticatedDataAttributeHandle;

typedef TElClassHandle TElBatchRequestsAttributeHandle;

typedef TElClassHandle TElBatchResponsesAttributeHandle;

typedef TElClassHandle TElPopLinkRandomAttributeHandle;

typedef TElClassHandle TElSinglePubInfoHandle;

typedef TElClassHandle TElPKIPublicationInfoHandle;

typedef TElClassHandle TElPublicationInformationAttributeHandle;

typedef TElClassHandle TElControlProcessedAttributeHandle;

typedef TElClassHandle TElOptionalValidityHandle;

typedef TElClassHandle TElPublicKeyInfoHandle;

typedef TElClassHandle TElCertTemplateHandle;

typedef TElClassHandle TElModCertificationRequestAttributeHandle;

typedef TElClassHandle TElFullPKIRequestHandle;

typedef TElClassHandle TElFullPKIResponseHandle;

typedef void (SB_CALLBACK *TSBFullPKISignatureEvent)(void * _ObjectData, TObjectHandle Sender, TElCMSSignatureHandle Signature, int8_t * Continue);

typedef uint8_t TSBFullPKIFormatRaw;

typedef enum
{
	fpfBinary = 0,
	fpfBase64 = 1
} TSBFullPKIFormat;

typedef uint8_t TSBTaggedRequestTypeRaw;

typedef enum
{
	trtUnknown = 0,
	trtPKCS10 = 1,
	trtCRMF = 2,
	trtExternal = 3
} TSBTaggedRequestType;

typedef TElClassHandle TElControlAttributeClassHandle;

typedef uint8_t TSBPKIPublicationActionRaw;

typedef enum
{
	ppaDontPublish = 0,
	ppaPleasePublish = 1
} TSBPKIPublicationAction;

typedef uint8_t TSBPKIPublishMethodRaw;

typedef enum
{
	ppmDontCare = 0,
	ppmX500 = 1,
	ppmWeb = 2,
	ppmLDAP = 3
} TSBPKIPublishMethod;

#ifdef SB_USE_CLASS_TELATTRIBUTEVALUE
SB_IMPORT uint32_t SB_APIENTRY TElAttributeValue_get_Value(TElAttributeValueHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAttributeValue_set_Value(TElAttributeValueHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAttributeValue_Create(TElAttributeValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAttributeValue_Create_1(const uint8_t pValue[], int32_t szValue, TElAttributeValueHandle * OutResult);
#endif /* SB_USE_CLASS_TELATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElTaggedAttribute_get_BodyPartId(TElTaggedAttributeHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedAttribute_set_BodyPartId(TElTaggedAttributeHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedAttribute_get_AttrType(TElTaggedAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedAttribute_set_AttrType(TElTaggedAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedAttribute_get_AttrValues(TElTaggedAttributeHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedAttribute_Create(TElTaggedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElTaggedCertificationRequest_get_BodyPartId(TElTaggedCertificationRequestHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedCertificationRequest_set_BodyPartId(TElTaggedCertificationRequestHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedCertificationRequest_get_CertificationRequest(TElTaggedCertificationRequestHandle _Handle, TElCertificateRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedCertificationRequest_set_CertificationRequest(TElTaggedCertificationRequestHandle _Handle, TElCertificateRequestHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedCertificationRequest_Create(TElTaggedCertificationRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST */

#ifdef SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElExternallyDefinedCertificationRequest_get_BodyPartId(TElExternallyDefinedCertificationRequestHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExternallyDefinedCertificationRequest_set_BodyPartId(TElExternallyDefinedCertificationRequestHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExternallyDefinedCertificationRequest_get_MessageType(TElExternallyDefinedCertificationRequestHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExternallyDefinedCertificationRequest_set_MessageType(TElExternallyDefinedCertificationRequestHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElExternallyDefinedCertificationRequest_get_MessageValue(TElExternallyDefinedCertificationRequestHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExternallyDefinedCertificationRequest_set_MessageValue(TElExternallyDefinedCertificationRequestHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElExternallyDefinedCertificationRequest_Create(TElExternallyDefinedCertificationRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST */

#ifdef SB_USE_CLASS_TELTAGGEDREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElTaggedRequest_get_RequestType(TElTaggedRequestHandle _Handle, TSBTaggedRequestTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedRequest_get_TaggedCertificationRequest(TElTaggedRequestHandle _Handle, TElTaggedCertificationRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedRequest_set_TaggedCertificationRequest(TElTaggedRequestHandle _Handle, TElTaggedCertificationRequestHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedRequest_get_CertReqMsg(TElTaggedRequestHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedRequest_set_CertReqMsg(TElTaggedRequestHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedRequest_get_ExternallyDefinedCertificationRequest(TElTaggedRequestHandle _Handle, TElExternallyDefinedCertificationRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedRequest_set_ExternallyDefinedCertificationRequest(TElTaggedRequestHandle _Handle, TElExternallyDefinedCertificationRequestHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedRequest_Create(TElTaggedRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELTAGGEDREQUEST */

#ifdef SB_USE_CLASS_TELCONTENTINFO
SB_IMPORT uint32_t SB_APIENTRY TElContentInfo_get_ContentType(TElContentInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElContentInfo_set_ContentType(TElContentInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElContentInfo_get_Content(TElContentInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElContentInfo_set_Content(TElContentInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElContentInfo_Create(TElContentInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELTAGGEDCONTENTINFO
SB_IMPORT uint32_t SB_APIENTRY TElTaggedContentInfo_LoadFromTag(TElTaggedContentInfoHandle _Handle, TElASN1ConstrainedTagHandle Tag);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedContentInfo_SaveToTag(TElTaggedContentInfoHandle _Handle, TElASN1ConstrainedTagHandle Tag);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedContentInfo_get_BodyPartId(TElTaggedContentInfoHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedContentInfo_set_BodyPartId(TElTaggedContentInfoHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedContentInfo_get_ContentInfo(TElTaggedContentInfoHandle _Handle, TElContentInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedContentInfo_set_ContentInfo(TElTaggedContentInfoHandle _Handle, TElContentInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTaggedContentInfo_Create(TElTaggedContentInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELTAGGEDCONTENTINFO */

#ifdef SB_USE_CLASS_TELOTHERMSG
SB_IMPORT uint32_t SB_APIENTRY TElOtherMsg_get_MsgType(TElOtherMsgHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOtherMsg_set_MsgType(TElOtherMsgHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOtherMsg_get_MsgValue(TElOtherMsgHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOtherMsg_set_MsgValue(TElOtherMsgHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOtherMsg_Create(TElOtherMsgHandle * OutResult);
#endif /* SB_USE_CLASS_TELOTHERMSG */

#ifdef SB_USE_CLASS_TELPKIDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKIData_SaveToBuffer(TElPKIDataHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIData_LoadFromBuffer(TElPKIDataHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPKIData_get_ControlSequence(TElPKIDataHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIData_get_ReqSequence(TElPKIDataHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIData_get_CMSSequence(TElPKIDataHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIData_get_OtherMsgSequence(TElPKIDataHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIData_Create(TElPKIDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKIDATA */

#ifdef SB_USE_CLASS_TELPKIRESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElPKIResponse_SaveToBuffer(TElPKIResponseHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIResponse_LoadFromBuffer(TElPKIResponseHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPKIResponse_get_ControlSequence(TElPKIResponseHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIResponse_get_CMSSequence(TElPKIResponseHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIResponse_get_OtherMsgSequence(TElPKIResponseHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIResponse_Create(TElPKIResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKIRESPONSE */

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_CreateInstance(TElTaggedAttributeHandle Tagged, TElControlAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_CreateInstance_1(TElControlAttributeHandle _Handle, TElTaggedAttributeHandle Tagged, TElControlAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_LoadFromTagged(TElControlAttributeHandle _Handle, TElTaggedAttributeHandle Tagged);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_SaveToBuffer(TElControlAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_LoadFromBuffer(TElControlAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_get_OID(TElControlAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_get_Values(TElControlAttributeHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_get_ValueCount(TElControlAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlAttribute_Create(TElControlAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTIFICATIONATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElIdentificationAttribute_SaveToBuffer(TElIdentificationAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentificationAttribute_LoadFromBuffer(TElIdentificationAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElIdentificationAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentificationAttribute_get_OID(TElIdentificationAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentificationAttribute_get_Content(TElIdentificationAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentificationAttribute_set_Content(TElIdentificationAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElIdentificationAttribute_Create(TElIdentificationAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELIDENTIFICATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELPENDINFO
SB_IMPORT uint32_t SB_APIENTRY TElPendInfo_get_PendToken(TElPendInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPendInfo_set_PendToken(TElPendInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPendInfo_get_PendTime(TElPendInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPendInfo_set_PendTime(TElPendInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPendInfo_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPENDINFO */

#ifdef SB_USE_CLASS_TELCMCSTATUSINFOATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_SaveToBuffer(TElCMCStatusInfoAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_LoadFromBuffer(TElCMCStatusInfoAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_get_OID(TElCMCStatusInfoAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_get_CMCStatus(TElCMCStatusInfoAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_set_CMCStatus(TElCMCStatusInfoAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_get_BodyList(TElCMCStatusInfoAttributeHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_set_BodyList(TElCMCStatusInfoAttributeHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_get_StatusString(TElCMCStatusInfoAttributeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_set_StatusString(TElCMCStatusInfoAttributeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_get_HasPendInfo(TElCMCStatusInfoAttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_set_HasPendInfo(TElCMCStatusInfoAttributeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_get_HasFailInfo(TElCMCStatusInfoAttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_set_HasFailInfo(TElCMCStatusInfoAttributeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_get_FailInfo(TElCMCStatusInfoAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_set_FailInfo(TElCMCStatusInfoAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_get_PendInfo(TElCMCStatusInfoAttributeHandle _Handle, TElPendInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_set_PendInfo(TElCMCStatusInfoAttributeHandle _Handle, TElPendInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoAttribute_Create(TElCMCStatusInfoAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMCSTATUSINFOATTRIBUTE */

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartReference_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

#ifdef SB_USE_CLASS_TELBODYPARTID
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartID_get_BodyPartID(TElBodyPartIDHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartID_set_BodyPartID(TElBodyPartIDHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartID_Create(TElBodyPartIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartID_Create_1(int32_t Value, TElBodyPartIDHandle * OutResult);
#endif /* SB_USE_CLASS_TELBODYPARTID */

#ifdef SB_USE_CLASS_TELBODYPARTPATH
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartPath_get_BodyPartPath(TElBodyPartPathHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartPath_set_BodyPartPath(TElBodyPartPathHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartPath_Create(TElBodyPartPathHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBodyPartPath_Create_1(const int32_t pValue[], int32_t szValue, TElBodyPartPathHandle * OutResult);
#endif /* SB_USE_CLASS_TELBODYPARTPATH */

#ifdef SB_USE_CLASS_TELEXTENDEDFAILINFO
SB_IMPORT uint32_t SB_APIENTRY TElExtendedFailInfo_get_FailInfoOID(TElExtendedFailInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedFailInfo_set_FailInfoOID(TElExtendedFailInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedFailInfo_get_FailInfoValue(TElExtendedFailInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedFailInfo_set_FailInfoValue(TElExtendedFailInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedFailInfo_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELEXTENDEDFAILINFO */

#ifdef SB_USE_CLASS_TELCMCSTATUSINFOV2ATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_SaveToBuffer(TElCMCStatusInfoV2AttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_LoadFromBuffer(TElCMCStatusInfoV2AttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_AddBodyPartReference(TElCMCStatusInfoV2AttributeHandle _Handle, TElBodyPartReferenceHandle Ref, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_RemoveBodyPartReferece(TElCMCStatusInfoV2AttributeHandle _Handle, int32_t Idx);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_OID(TElCMCStatusInfoV2AttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_CMCStatus(TElCMCStatusInfoV2AttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_set_CMCStatus(TElCMCStatusInfoV2AttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_BodyList(TElCMCStatusInfoV2AttributeHandle _Handle, int32_t Index, TElBodyPartReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_BodyListCount(TElCMCStatusInfoV2AttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_StatusString(TElCMCStatusInfoV2AttributeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_set_StatusString(TElCMCStatusInfoV2AttributeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_HasPendInfo(TElCMCStatusInfoV2AttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_set_HasPendInfo(TElCMCStatusInfoV2AttributeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_HasFailInfo(TElCMCStatusInfoV2AttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_set_HasFailInfo(TElCMCStatusInfoV2AttributeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_HasExtendedFailInfo(TElCMCStatusInfoV2AttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_set_HasExtendedFailInfo(TElCMCStatusInfoV2AttributeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_FailInfo(TElCMCStatusInfoV2AttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_set_FailInfo(TElCMCStatusInfoV2AttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_PendInfo(TElCMCStatusInfoV2AttributeHandle _Handle, TElPendInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_set_PendInfo(TElCMCStatusInfoV2AttributeHandle _Handle, TElPendInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_get_ExtendedFailInfo(TElCMCStatusInfoV2AttributeHandle _Handle, TElExtendedFailInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_set_ExtendedFailInfo(TElCMCStatusInfoV2AttributeHandle _Handle, TElExtendedFailInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMCStatusInfoV2Attribute_Create(TElCMCStatusInfoV2AttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMCSTATUSINFOV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELADDEXTENSIONSATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_SaveToBuffer(TElAddExtensionsAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_LoadFromBuffer(TElAddExtensionsAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_get_OID(TElAddExtensionsAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_get_PKIDataReference(TElAddExtensionsAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_set_PKIDataReference(TElAddExtensionsAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_get_CertReferences(TElAddExtensionsAttributeHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_set_CertReferences(TElAddExtensionsAttributeHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_get_Extensions(TElAddExtensionsAttributeHandle _Handle, TElCertificateExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAddExtensionsAttribute_Create(TElAddExtensionsAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELADDEXTENSIONSATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTITYPROOFV2ATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_SaveToBuffer(TElIdentityProofV2AttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_LoadFromBuffer(TElIdentityProofV2AttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_get_OID(TElIdentityProofV2AttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_get_HashAlgID(TElIdentityProofV2AttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_set_HashAlgID(TElIdentityProofV2AttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_get_MacAlgID(TElIdentityProofV2AttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_set_MacAlgID(TElIdentityProofV2AttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_get_Witness(TElIdentityProofV2AttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_set_Witness(TElIdentityProofV2AttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofV2Attribute_Create(TElIdentityProofV2AttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELIDENTITYPROOFV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTITYPROOFATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofAttribute_SaveToBuffer(TElIdentityProofAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofAttribute_LoadFromBuffer(TElIdentityProofAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofAttribute_get_OID(TElIdentityProofAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofAttribute_get_IdentifyProof(TElIdentityProofAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofAttribute_set_IdentifyProof(TElIdentityProofAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElIdentityProofAttribute_Create(TElIdentityProofAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELIDENTITYPROOFATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKWITNESSV2ATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_SaveToBuffer(TElPopLinkWitnessV2AttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_LoadFromBuffer(TElPopLinkWitnessV2AttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_get_OID(TElPopLinkWitnessV2AttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_get_KeyGenAlgID(TElPopLinkWitnessV2AttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_set_KeyGenAlgID(TElPopLinkWitnessV2AttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_get_MacAlgID(TElPopLinkWitnessV2AttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_set_MacAlgID(TElPopLinkWitnessV2AttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_get_Witness(TElPopLinkWitnessV2AttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_set_Witness(TElPopLinkWitnessV2AttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessV2Attribute_Create(TElPopLinkWitnessV2AttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELPOPLINKWITNESSV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKWITNESSATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessAttribute_SaveToBuffer(TElPopLinkWitnessAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessAttribute_LoadFromBuffer(TElPopLinkWitnessAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessAttribute_get_OID(TElPopLinkWitnessAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessAttribute_get_PopLinkWitness(TElPopLinkWitnessAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessAttribute_set_PopLinkWitness(TElPopLinkWitnessAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkWitnessAttribute_Create(TElPopLinkWitnessAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELPOPLINKWITNESSATTRIBUTE */

#ifdef SB_USE_CLASS_TELDATARETURNATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElDataReturnAttribute_SaveToBuffer(TElDataReturnAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDataReturnAttribute_LoadFromBuffer(TElDataReturnAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElDataReturnAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDataReturnAttribute_get_OID(TElDataReturnAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDataReturnAttribute_get_DataReturn(TElDataReturnAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDataReturnAttribute_set_DataReturn(TElDataReturnAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDataReturnAttribute_Create(TElDataReturnAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELDATARETURNATTRIBUTE */

#ifdef SB_USE_CLASS_TELTRANSACTIONIDENTIFIERATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElTransactionIdentifierAttribute_SaveToBuffer(TElTransactionIdentifierAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTransactionIdentifierAttribute_LoadFromBuffer(TElTransactionIdentifierAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElTransactionIdentifierAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTransactionIdentifierAttribute_get_OID(TElTransactionIdentifierAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTransactionIdentifierAttribute_get_TransactionId(TElTransactionIdentifierAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTransactionIdentifierAttribute_set_TransactionId(TElTransactionIdentifierAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTransactionIdentifierAttribute_Create(TElTransactionIdentifierAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELTRANSACTIONIDENTIFIERATTRIBUTE */

#ifdef SB_USE_CLASS_TELSENDERNONCEATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElSenderNonceAttribute_SaveToBuffer(TElSenderNonceAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSenderNonceAttribute_LoadFromBuffer(TElSenderNonceAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSenderNonceAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSenderNonceAttribute_get_OID(TElSenderNonceAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSenderNonceAttribute_get_Nonce(TElSenderNonceAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSenderNonceAttribute_set_Nonce(TElSenderNonceAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSenderNonceAttribute_Create(TElSenderNonceAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSENDERNONCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELRECIPIENTNONCEATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElRecipientNonceAttribute_SaveToBuffer(TElRecipientNonceAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRecipientNonceAttribute_LoadFromBuffer(TElRecipientNonceAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElRecipientNonceAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRecipientNonceAttribute_get_OID(TElRecipientNonceAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRecipientNonceAttribute_get_Nonce(TElRecipientNonceAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRecipientNonceAttribute_set_Nonce(TElRecipientNonceAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRecipientNonceAttribute_Create(TElRecipientNonceAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELRECIPIENTNONCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELENCRYPTEDPOPATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_SaveToBuffer(TElEncryptedPopAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_LoadFromBuffer(TElEncryptedPopAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_get_OID(TElEncryptedPopAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_get_Request(TElEncryptedPopAttributeHandle _Handle, TElTaggedRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_set_Request(TElEncryptedPopAttributeHandle _Handle, TElTaggedRequestHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_get_CMS(TElEncryptedPopAttributeHandle _Handle, TElContentInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_set_CMS(TElEncryptedPopAttributeHandle _Handle, TElContentInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_get_POPAlgID(TElEncryptedPopAttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_set_POPAlgID(TElEncryptedPopAttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_get_WitnessAlgID(TElEncryptedPopAttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_set_WitnessAlgID(TElEncryptedPopAttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_get_Witness(TElEncryptedPopAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_set_Witness(TElEncryptedPopAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElEncryptedPopAttribute_Create(TElEncryptedPopAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELENCRYPTEDPOPATTRIBUTE */

#ifdef SB_USE_CLASS_TELDECRYPTEDPOPATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_SaveToBuffer(TElDecryptedPopAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_LoadFromBuffer(TElDecryptedPopAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_get_OID(TElDecryptedPopAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_get_BodyPartId(TElDecryptedPopAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_set_BodyPartId(TElDecryptedPopAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_get_POPAlgID(TElDecryptedPopAttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_set_POPAlgID(TElDecryptedPopAttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_get_POP(TElDecryptedPopAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_set_POP(TElDecryptedPopAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDecryptedPopAttribute_Create(TElDecryptedPopAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELDECRYPTEDPOPATTRIBUTE */

#ifdef SB_USE_CLASS_TELLRAPOPWITNESSATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_SaveToBuffer(TElLraPopWitnessAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_LoadFromBuffer(TElLraPopWitnessAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_get_OID(TElLraPopWitnessAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_get_BodyPartId(TElLraPopWitnessAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_set_BodyPartId(TElLraPopWitnessAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_get_BodyIds(TElLraPopWitnessAttributeHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_set_BodyIds(TElLraPopWitnessAttributeHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLraPopWitnessAttribute_Create(TElLraPopWitnessAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELLRAPOPWITNESSATTRIBUTE */

#ifdef SB_USE_CLASS_TELGETCERTIFICATEATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_SaveToBuffer(TElGetCertificateAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_LoadFromBuffer(TElGetCertificateAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_get_OID(TElGetCertificateAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_get_IssuerName(TElGetCertificateAttributeHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_set_IssuerName(TElGetCertificateAttributeHandle _Handle, TElGeneralNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_get_SerialNumber(TElGetCertificateAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_set_SerialNumber(TElGetCertificateAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGetCertificateAttribute_Create(TElGetCertificateAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELGETCERTIFICATEATTRIBUTE */

#ifdef SB_USE_CLASS_TELGETCRLATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_SaveToBuffer(TElGetCRLAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_LoadFromBuffer(TElGetCRLAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_get_OID(TElGetCRLAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_get_IssuerName(TElGetCRLAttributeHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_set_IssuerName(TElGetCRLAttributeHandle _Handle, TElRelativeDistinguishedNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_get_CRLName(TElGetCRLAttributeHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_set_CRLName(TElGetCRLAttributeHandle _Handle, TElGeneralNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_get_Time(TElGetCRLAttributeHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_set_Time(TElGetCRLAttributeHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_get_Reasons(TElGetCRLAttributeHandle _Handle, TSBCRLReasonFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_set_Reasons(TElGetCRLAttributeHandle _Handle, TSBCRLReasonFlagsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGetCRLAttribute_Create(TElGetCRLAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELGETCRLATTRIBUTE */

#ifdef SB_USE_CLASS_TELREVOCATIONREQUESTATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_SaveToBuffer(TElRevocationRequestAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_LoadFromBuffer(TElRevocationRequestAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_get_OID(TElRevocationRequestAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_get_IssuerName(TElRevocationRequestAttributeHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_set_IssuerName(TElRevocationRequestAttributeHandle _Handle, TElRelativeDistinguishedNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_get_SerialNumber(TElRevocationRequestAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_set_SerialNumber(TElRevocationRequestAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_get_Reason(TElRevocationRequestAttributeHandle _Handle, TSBCRLReasonFlagRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_set_Reason(TElRevocationRequestAttributeHandle _Handle, TSBCRLReasonFlagRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_get_InvalidityDate(TElRevocationRequestAttributeHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_set_InvalidityDate(TElRevocationRequestAttributeHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_get_SharedSecret(TElRevocationRequestAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_set_SharedSecret(TElRevocationRequestAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_get_Comment(TElRevocationRequestAttributeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_set_Comment(TElRevocationRequestAttributeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationRequestAttribute_Create(TElRevocationRequestAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELREVOCATIONREQUESTATTRIBUTE */

#ifdef SB_USE_CLASS_TELREGISTRATIONINFORMATIONATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElRegistrationInformationAttribute_SaveToBuffer(TElRegistrationInformationAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRegistrationInformationAttribute_LoadFromBuffer(TElRegistrationInformationAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElRegistrationInformationAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRegistrationInformationAttribute_get_OID(TElRegistrationInformationAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRegistrationInformationAttribute_get_RegInfo(TElRegistrationInformationAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRegistrationInformationAttribute_set_RegInfo(TElRegistrationInformationAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRegistrationInformationAttribute_Create(TElRegistrationInformationAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELREGISTRATIONINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELRESPONSEINFORMATIONATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElResponseInformationAttribute_SaveToBuffer(TElResponseInformationAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElResponseInformationAttribute_LoadFromBuffer(TElResponseInformationAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElResponseInformationAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElResponseInformationAttribute_get_OID(TElResponseInformationAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElResponseInformationAttribute_get_ResponseInfo(TElResponseInformationAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElResponseInformationAttribute_set_ResponseInfo(TElResponseInformationAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElResponseInformationAttribute_Create(TElResponseInformationAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELRESPONSEINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELQUERYPENDINGATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElQueryPendingAttribute_SaveToBuffer(TElQueryPendingAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQueryPendingAttribute_LoadFromBuffer(TElQueryPendingAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElQueryPendingAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQueryPendingAttribute_get_OID(TElQueryPendingAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQueryPendingAttribute_get_QueryPending(TElQueryPendingAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQueryPendingAttribute_set_QueryPending(TElQueryPendingAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElQueryPendingAttribute_Create(TElQueryPendingAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELQUERYPENDINGATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONFIRMCERTACCEPTANCEATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_SaveToBuffer(TElConfirmCertAcceptanceAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_LoadFromBuffer(TElConfirmCertAcceptanceAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_get_OID(TElConfirmCertAcceptanceAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_get_IssuerName(TElConfirmCertAcceptanceAttributeHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_set_IssuerName(TElConfirmCertAcceptanceAttributeHandle _Handle, TElGeneralNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_get_SerialNumber(TElConfirmCertAcceptanceAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_set_SerialNumber(TElConfirmCertAcceptanceAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElConfirmCertAcceptanceAttribute_Create(TElConfirmCertAcceptanceAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELCONFIRMCERTACCEPTANCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELPUBLISHTRUSTANCHORSATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_SaveToBuffer(TElPublishTrustAnchorsAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_LoadFromBuffer(TElPublishTrustAnchorsAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_get_OID(TElPublishTrustAnchorsAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_get_SeqNumber(TElPublishTrustAnchorsAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_set_SeqNumber(TElPublishTrustAnchorsAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_get_HashAlgorithm(TElPublishTrustAnchorsAttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_set_HashAlgorithm(TElPublishTrustAnchorsAttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublishTrustAnchorsAttribute_Create(TElPublishTrustAnchorsAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLISHTRUSTANCHORSATTRIBUTE */

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataAttribute_SaveToBuffer(TElAuthenticatedDataAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataAttribute_LoadFromBuffer(TElAuthenticatedDataAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataAttribute_get_OID(TElAuthenticatedDataAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataAttribute_get_AuthPublish(TElAuthenticatedDataAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataAttribute_set_AuthPublish(TElAuthenticatedDataAttributeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataAttribute_Create(TElAuthenticatedDataAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAATTRIBUTE */

#ifdef SB_USE_CLASS_TELBATCHREQUESTSATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElBatchRequestsAttribute_SaveToBuffer(TElBatchRequestsAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBatchRequestsAttribute_LoadFromBuffer(TElBatchRequestsAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBatchRequestsAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBatchRequestsAttribute_get_OID(TElBatchRequestsAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBatchRequestsAttribute_get_BodyPartList(TElBatchRequestsAttributeHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBatchRequestsAttribute_set_BodyPartList(TElBatchRequestsAttributeHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBatchRequestsAttribute_Create(TElBatchRequestsAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELBATCHREQUESTSATTRIBUTE */

#ifdef SB_USE_CLASS_TELBATCHRESPONSESATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElBatchResponsesAttribute_SaveToBuffer(TElBatchResponsesAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBatchResponsesAttribute_LoadFromBuffer(TElBatchResponsesAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBatchResponsesAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBatchResponsesAttribute_get_OID(TElBatchResponsesAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBatchResponsesAttribute_get_BodyPartList(TElBatchResponsesAttributeHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBatchResponsesAttribute_set_BodyPartList(TElBatchResponsesAttributeHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBatchResponsesAttribute_Create(TElBatchResponsesAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELBATCHRESPONSESATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKRANDOMATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkRandomAttribute_SaveToBuffer(TElPopLinkRandomAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkRandomAttribute_LoadFromBuffer(TElPopLinkRandomAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkRandomAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkRandomAttribute_get_OID(TElPopLinkRandomAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkRandomAttribute_get_PopLinkRandom(TElPopLinkRandomAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkRandomAttribute_set_PopLinkRandom(TElPopLinkRandomAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPopLinkRandomAttribute_Create(TElPopLinkRandomAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELPOPLINKRANDOMATTRIBUTE */

#ifdef SB_USE_CLASS_TELSINGLEPUBINFO
SB_IMPORT uint32_t SB_APIENTRY TElSinglePubInfo_get_PubMethod(TElSinglePubInfoHandle _Handle, TSBPKIPublishMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePubInfo_set_PubMethod(TElSinglePubInfoHandle _Handle, TSBPKIPublishMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePubInfo_get_PubLocation(TElSinglePubInfoHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePubInfo_set_PubLocation(TElSinglePubInfoHandle _Handle, TElGeneralNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePubInfo_Create(TElSinglePubInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSINGLEPUBINFO */

#ifdef SB_USE_CLASS_TELPKIPUBLICATIONINFO
SB_IMPORT uint32_t SB_APIENTRY TElPKIPublicationInfo_AddInfo(TElPKIPublicationInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIPublicationInfo_RemoveInfo(TElPKIPublicationInfoHandle _Handle, int32_t Idx);
SB_IMPORT uint32_t SB_APIENTRY TElPKIPublicationInfo_get_Action(TElPKIPublicationInfoHandle _Handle, TSBPKIPublicationActionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIPublicationInfo_set_Action(TElPKIPublicationInfoHandle _Handle, TSBPKIPublicationActionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKIPublicationInfo_get_Infos(TElPKIPublicationInfoHandle _Handle, int32_t Index, TElSinglePubInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIPublicationInfo_get_Count(TElPKIPublicationInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKIPublicationInfo_Create(TElPKIPublicationInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKIPUBLICATIONINFO */

#ifdef SB_USE_CLASS_TELPUBLICATIONINFORMATIONATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElPublicationInformationAttribute_SaveToBuffer(TElPublicationInformationAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicationInformationAttribute_LoadFromBuffer(TElPublicationInformationAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPublicationInformationAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicationInformationAttribute_get_OID(TElPublicationInformationAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicationInformationAttribute_get_HashAlgorithm(TElPublicationInformationAttributeHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicationInformationAttribute_set_HashAlgorithm(TElPublicationInformationAttributeHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicationInformationAttribute_get_PubInfo(TElPublicationInformationAttributeHandle _Handle, TElPKIPublicationInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicationInformationAttribute_Create(TElPublicationInformationAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLICATIONINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONTROLPROCESSEDATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_AddBodyPartReference(TElControlProcessedAttributeHandle _Handle, TElBodyPartReferenceHandle Ref, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_RemoveBodyPartReferece(TElControlProcessedAttributeHandle _Handle, int32_t Idx);
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_SaveToBuffer(TElControlProcessedAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_LoadFromBuffer(TElControlProcessedAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_get_OID(TElControlProcessedAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_get_BodyList(TElControlProcessedAttributeHandle _Handle, int32_t Index, TElBodyPartReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_get_BodyListCount(TElControlProcessedAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElControlProcessedAttribute_Create(TElControlProcessedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELCONTROLPROCESSEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELOPTIONALVALIDITY
SB_IMPORT uint32_t SB_APIENTRY TElOptionalValidity_get_NotBefore(TElOptionalValidityHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOptionalValidity_set_NotBefore(TElOptionalValidityHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOptionalValidity_get_NotAfter(TElOptionalValidityHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOptionalValidity_set_NotAfter(TElOptionalValidityHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOptionalValidity_Create(TElOptionalValidityHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPTIONALVALIDITY */

#ifdef SB_USE_CLASS_TELPUBLICKEYINFO
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyInfo_get_Algorithm(TElPublicKeyInfoHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyInfo_set_Algorithm(TElPublicKeyInfoHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyInfo_get_PublicKey(TElPublicKeyInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyInfo_set_PublicKey(TElPublicKeyInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyInfo_Create(TElPublicKeyInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLICKEYINFO */

#ifdef SB_USE_CLASS_TELCERTTEMPLATE
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_SaveToTag(TElCertTemplateHandle _Handle, TElASN1ConstrainedTagHandle Tag);
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_LoadFromTag(TElCertTemplateHandle _Handle, TElASN1ConstrainedTagHandle Tag);
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_get_Subject(TElCertTemplateHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_set_Subject(TElCertTemplateHandle _Handle, TElRelativeDistinguishedNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_get_SubjectPublicKeyInfo(TElCertTemplateHandle _Handle, TElPublicKeyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_get_Validity(TElCertTemplateHandle _Handle, TElOptionalValidityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_set_Validity(TElCertTemplateHandle _Handle, TElOptionalValidityHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_get_Extensions(TElCertTemplateHandle _Handle, TElCertificateExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertTemplate_Create(TElCertTemplateHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTTEMPLATE */

#ifdef SB_USE_CLASS_TELMODCERTIFICATIONREQUESTATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_SaveToBuffer(TElModCertificationRequestAttributeHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_LoadFromBuffer(TElModCertificationRequestAttributeHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_get_OID(TElModCertificationRequestAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_get_PKIDataReference(TElModCertificationRequestAttributeHandle _Handle, TElBodyPartPathHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_get_CertReferences(TElModCertificationRequestAttributeHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_set_CertReferences(TElModCertificationRequestAttributeHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_get_Replace(TElModCertificationRequestAttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_set_Replace(TElModCertificationRequestAttributeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_get_CertTemplate(TElModCertificationRequestAttributeHandle _Handle, TElCertTemplateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElModCertificationRequestAttribute_Create(TElModCertificationRequestAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELMODCERTIFICATIONREQUESTATTRIBUTE */

#ifdef SB_USE_CLASS_TELFULLPKIREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_CreateSimpleRequest(TElCertificateRequestHandle Request, TElFullPKIRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_CreateSimpleRequest_1(TElFullPKIRequestHandle _Handle, TElCertificateRequestHandle Request, TElFullPKIRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_CreateSimpleRequest_2(TElCertificateRequestHandle Request, TElCustomCertStorageHandle EncryptionCertificates, TElFullPKIRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_CreateSimpleRequest_3(TElFullPKIRequestHandle _Handle, TElCertificateRequestHandle Request, TElCustomCertStorageHandle EncryptionCertificates, TElFullPKIRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_SaveToBuffer(TElFullPKIRequestHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_LoadFromBuffer(TElFullPKIRequestHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_LoadFromStream(TElFullPKIRequestHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_SaveToStream(TElFullPKIRequestHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_SaveToFile(TElFullPKIRequestHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_LoadFromFile(TElFullPKIRequestHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_AddRequest(TElFullPKIRequestHandle _Handle, TElCertificateRequestHandle Req, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_RemoveRequest(TElFullPKIRequestHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_AddControlAttribute(TElFullPKIRequestHandle _Handle, TElControlAttributeHandle Attr, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_RemoveControlAttribute(TElFullPKIRequestHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_AddCMS(TElFullPKIRequestHandle _Handle, const uint8_t pCMS[], int32_t szCMS, const uint8_t pContentType[], int32_t szContentType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_AddCMS_1(TElFullPKIRequestHandle _Handle, TElFullPKIRequestHandle CMS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_RemoveCMS(TElFullPKIRequestHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_AddOtherMsg(TElFullPKIRequestHandle _Handle, const uint8_t pMsg[], int32_t szMsg, const uint8_t pContentType[], int32_t szContentType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_RemoveOtherMsg(TElFullPKIRequestHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_GetBodyPartID(TElFullPKIRequestHandle _Handle, TObjectHandle Part, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_Requests(TElFullPKIRequestHandle _Handle, int32_t Index, TElCertificateRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_ControlAttributes(TElFullPKIRequestHandle _Handle, int32_t Index, TElControlAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_CMSs(TElFullPKIRequestHandle _Handle, int32_t Index, TElContentInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_OtherMessages(TElFullPKIRequestHandle _Handle, int32_t Index, TElOtherMsgHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_RequestCount(TElFullPKIRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_ControlAttributeCount(TElFullPKIRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_CMSCount(TElFullPKIRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_OtherMessageCount(TElFullPKIRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_StoreFormat(TElFullPKIRequestHandle _Handle, TSBFullPKIFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_set_StoreFormat(TElFullPKIRequestHandle _Handle, TSBFullPKIFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_SigningCertificates(TElFullPKIRequestHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_set_SigningCertificates(TElFullPKIRequestHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_EncryptionCertificates(TElFullPKIRequestHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_set_EncryptionCertificates(TElFullPKIRequestHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_MainRequestIndex(TElFullPKIRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_set_MainRequestIndex(TElFullPKIRequestHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_get_OnSignature(TElFullPKIRequestHandle _Handle, TSBFullPKISignatureEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_set_OnSignature(TElFullPKIRequestHandle _Handle, TSBFullPKISignatureEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIRequest_Create(TElFullPKIRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELFULLPKIREQUEST */

#ifdef SB_USE_CLASS_TELFULLPKIRESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_SaveToBuffer(TElFullPKIResponseHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_LoadFromBuffer(TElFullPKIResponseHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_LoadFromStream(TElFullPKIResponseHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_SaveToStream(TElFullPKIResponseHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_SaveToFile(TElFullPKIResponseHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_LoadFromFile(TElFullPKIResponseHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_AddControlAttribute(TElFullPKIResponseHandle _Handle, TElControlAttributeHandle Attr, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_RemoveControlAttribute(TElFullPKIResponseHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_AddCMS(TElFullPKIResponseHandle _Handle, const uint8_t pCMS[], int32_t szCMS, const uint8_t pContentType[], int32_t szContentType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_RemoveCMS(TElFullPKIResponseHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_AddOtherMsg(TElFullPKIResponseHandle _Handle, const uint8_t pMsg[], int32_t szMsg, const uint8_t pContentType[], int32_t szContentType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_RemoveOtherMsg(TElFullPKIResponseHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_GetBodyPartID(TElFullPKIResponseHandle _Handle, TObjectHandle Part, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_ControlAttributes(TElFullPKIResponseHandle _Handle, int32_t Index, TElControlAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_CMSs(TElFullPKIResponseHandle _Handle, int32_t Index, TElContentInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_OtherMessages(TElFullPKIResponseHandle _Handle, int32_t Index, TElOtherMsgHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_ControlAttributeCount(TElFullPKIResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_CMSCount(TElFullPKIResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_OtherMessageCount(TElFullPKIResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_StoreFormat(TElFullPKIResponseHandle _Handle, TSBFullPKIFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_set_StoreFormat(TElFullPKIResponseHandle _Handle, TSBFullPKIFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_SigningCertificates(TElFullPKIResponseHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_set_SigningCertificates(TElFullPKIResponseHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_EncryptionCertificates(TElFullPKIResponseHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_set_EncryptionCertificates(TElFullPKIResponseHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_IssuedCertificates(TElFullPKIResponseHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_IssuerCRLs(TElFullPKIResponseHandle _Handle, TElMemoryCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_get_OnSignature(TElFullPKIResponseHandle _Handle, TSBFullPKISignatureEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_set_OnSignature(TElFullPKIResponseHandle _Handle, TSBFullPKISignatureEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFullPKIResponse_Create(TElFullPKIResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELFULLPKIRESPONSE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElAttributeValue;
class TElTaggedAttribute;
class TElTaggedCertificationRequest;
class TElExternallyDefinedCertificationRequest;
class TElTaggedRequest;
class TElContentInfo;
class TElTaggedContentInfo;
class TElOtherMsg;
class TElPKIData;
class TElPKIResponse;
class TElControlAttribute;
class TElIdentificationAttribute;
class TElPendInfo;
class TElCMCStatusInfoAttribute;
class TElBodyPartReference;
class TElBodyPartID;
class TElBodyPartPath;
class TElExtendedFailInfo;
class TElCMCStatusInfoV2Attribute;
class TElAddExtensionsAttribute;
class TElIdentityProofV2Attribute;
class TElIdentityProofAttribute;
class TElPopLinkWitnessV2Attribute;
class TElPopLinkWitnessAttribute;
class TElDataReturnAttribute;
class TElTransactionIdentifierAttribute;
class TElSenderNonceAttribute;
class TElRecipientNonceAttribute;
class TElEncryptedPopAttribute;
class TElDecryptedPopAttribute;
class TElLraPopWitnessAttribute;
class TElGetCertificateAttribute;
class TElGetCRLAttribute;
class TElRevocationRequestAttribute;
class TElRegistrationInformationAttribute;
class TElResponseInformationAttribute;
class TElQueryPendingAttribute;
class TElConfirmCertAcceptanceAttribute;
class TElPublishTrustAnchorsAttribute;
class TElAuthenticatedDataAttribute;
class TElBatchRequestsAttribute;
class TElBatchResponsesAttribute;
class TElPopLinkRandomAttribute;
class TElSinglePubInfo;
class TElPKIPublicationInfo;
class TElPublicationInformationAttribute;
class TElControlProcessedAttribute;
class TElOptionalValidity;
class TElPublicKeyInfo;
class TElCertTemplate;
class TElModCertificationRequestAttribute;
class TElFullPKIRequest;
class TElFullPKIResponse;

#ifdef SB_USE_CLASS_TELATTRIBUTEVALUE
class TElAttributeValue: public TObject
{
	private:
		SB_DISABLE_COPY(TElAttributeValue)
	public:
		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElAttributeValue(TElAttributeValueHandle handle, TElOwnHandle ownHandle);

		TElAttributeValue();

		explicit TElAttributeValue(const std::vector<uint8_t> &Value);

};
#endif /* SB_USE_CLASS_TELATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE
class TElTaggedAttribute: public TObject
{
	private:
		SB_DISABLE_COPY(TElTaggedAttribute)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_AttrValues;
#endif /* SB_USE_CLASS_TLIST */

		void initInstances();

	public:
		virtual uint32_t get_BodyPartId();

		virtual void set_BodyPartId(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_BodyPartId, set_BodyPartId, TElTaggedAttribute, BodyPartId);

		virtual void get_AttrType(std::vector<uint8_t> &OutResult);

		virtual void set_AttrType(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_AttrValues();

		SB_DECLARE_PROPERTY_GET(TList*, get_AttrValues, TElTaggedAttribute, AttrValues);
#endif /* SB_USE_CLASS_TLIST */

		TElTaggedAttribute(TElTaggedAttributeHandle handle, TElOwnHandle ownHandle);

		TElTaggedAttribute();

		virtual ~TElTaggedAttribute();

};
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST
class TElTaggedCertificationRequest: public TObject
{
	private:
		SB_DISABLE_COPY(TElTaggedCertificationRequest)
#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
		TElCertificateRequest* _Inst_CertificationRequest;
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

		void initInstances();

	public:
		virtual uint32_t get_BodyPartId();

		virtual void set_BodyPartId(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_BodyPartId, set_BodyPartId, TElTaggedCertificationRequest, BodyPartId);

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
		virtual TElCertificateRequest* get_CertificationRequest();

		virtual void set_CertificationRequest(TElCertificateRequest &Value);

		virtual void set_CertificationRequest(TElCertificateRequest *Value);

		SB_DECLARE_PROPERTY(TElCertificateRequest*, get_CertificationRequest, set_CertificationRequest, TElTaggedCertificationRequest, CertificationRequest);
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

		TElTaggedCertificationRequest(TElTaggedCertificationRequestHandle handle, TElOwnHandle ownHandle);

		TElTaggedCertificationRequest();

		virtual ~TElTaggedCertificationRequest();

};
#endif /* SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST */

#ifdef SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST
class TElExternallyDefinedCertificationRequest: public TObject
{
	private:
		SB_DISABLE_COPY(TElExternallyDefinedCertificationRequest)
	public:
		virtual uint32_t get_BodyPartId();

		virtual void set_BodyPartId(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_BodyPartId, set_BodyPartId, TElExternallyDefinedCertificationRequest, BodyPartId);

		virtual void get_MessageType(std::vector<uint8_t> &OutResult);

		virtual void set_MessageType(const std::vector<uint8_t> &Value);

		virtual void get_MessageValue(std::vector<uint8_t> &OutResult);

		virtual void set_MessageValue(const std::vector<uint8_t> &Value);

		TElExternallyDefinedCertificationRequest(TElExternallyDefinedCertificationRequestHandle handle, TElOwnHandle ownHandle);

		TElExternallyDefinedCertificationRequest();

};
#endif /* SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST */

#ifdef SB_USE_CLASS_TELTAGGEDREQUEST
class TElTaggedRequest: public TObject
{
	private:
		SB_DISABLE_COPY(TElTaggedRequest)
#ifdef SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST
		TElTaggedCertificationRequest* _Inst_TaggedCertificationRequest;
#endif /* SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST */
#ifdef SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST
		TElExternallyDefinedCertificationRequest* _Inst_ExternallyDefinedCertificationRequest;
#endif /* SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST */

		void initInstances();

	public:
		virtual TSBTaggedRequestType get_RequestType();

		SB_DECLARE_PROPERTY_GET(TSBTaggedRequestType, get_RequestType, TElTaggedRequest, RequestType);

#ifdef SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST
		virtual TElTaggedCertificationRequest* get_TaggedCertificationRequest();

		virtual void set_TaggedCertificationRequest(TElTaggedCertificationRequest &Value);

		virtual void set_TaggedCertificationRequest(TElTaggedCertificationRequest *Value);

		SB_DECLARE_PROPERTY(TElTaggedCertificationRequest*, get_TaggedCertificationRequest, set_TaggedCertificationRequest, TElTaggedRequest, TaggedCertificationRequest);
#endif /* SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST */

		virtual void get_CertReqMsg(std::vector<uint8_t> &OutResult);

		virtual void set_CertReqMsg(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST
		virtual TElExternallyDefinedCertificationRequest* get_ExternallyDefinedCertificationRequest();

		virtual void set_ExternallyDefinedCertificationRequest(TElExternallyDefinedCertificationRequest &Value);

		virtual void set_ExternallyDefinedCertificationRequest(TElExternallyDefinedCertificationRequest *Value);

		SB_DECLARE_PROPERTY(TElExternallyDefinedCertificationRequest*, get_ExternallyDefinedCertificationRequest, set_ExternallyDefinedCertificationRequest, TElTaggedRequest, ExternallyDefinedCertificationRequest);
#endif /* SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST */

		TElTaggedRequest(TElTaggedRequestHandle handle, TElOwnHandle ownHandle);

		TElTaggedRequest();

		virtual ~TElTaggedRequest();

};
#endif /* SB_USE_CLASS_TELTAGGEDREQUEST */

#ifdef SB_USE_CLASS_TELCONTENTINFO
class TElContentInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElContentInfo)
	public:
		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual void set_Content(const std::vector<uint8_t> &Value);

		TElContentInfo(TElContentInfoHandle handle, TElOwnHandle ownHandle);

		TElContentInfo();

};
#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELTAGGEDCONTENTINFO
class TElTaggedContentInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElTaggedContentInfo)
#ifdef SB_USE_CLASS_TELCONTENTINFO
		TElContentInfo* _Inst_ContentInfo;
#endif /* SB_USE_CLASS_TELCONTENTINFO */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		void LoadFromTag(TElASN1ConstrainedTag &Tag);

		void LoadFromTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		void SaveToTag(TElASN1ConstrainedTag &Tag);

		void SaveToTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		virtual uint32_t get_BodyPartId();

		virtual void set_BodyPartId(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_BodyPartId, set_BodyPartId, TElTaggedContentInfo, BodyPartId);

#ifdef SB_USE_CLASS_TELCONTENTINFO
		virtual TElContentInfo* get_ContentInfo();

		virtual void set_ContentInfo(TElContentInfo &Value);

		virtual void set_ContentInfo(TElContentInfo *Value);

		SB_DECLARE_PROPERTY(TElContentInfo*, get_ContentInfo, set_ContentInfo, TElTaggedContentInfo, ContentInfo);
#endif /* SB_USE_CLASS_TELCONTENTINFO */

		TElTaggedContentInfo(TElTaggedContentInfoHandle handle, TElOwnHandle ownHandle);

		TElTaggedContentInfo();

		virtual ~TElTaggedContentInfo();

};
#endif /* SB_USE_CLASS_TELTAGGEDCONTENTINFO */

#ifdef SB_USE_CLASS_TELOTHERMSG
class TElOtherMsg: public TObject
{
	private:
		SB_DISABLE_COPY(TElOtherMsg)
	public:
		virtual void get_MsgType(std::vector<uint8_t> &OutResult);

		virtual void set_MsgType(const std::vector<uint8_t> &Value);

		virtual void get_MsgValue(std::vector<uint8_t> &OutResult);

		virtual void set_MsgValue(const std::vector<uint8_t> &Value);

		TElOtherMsg(TElOtherMsgHandle handle, TElOwnHandle ownHandle);

		TElOtherMsg();

};
#endif /* SB_USE_CLASS_TELOTHERMSG */

#ifdef SB_USE_CLASS_TELPKIDATA
class TElPKIData: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKIData)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_ControlSequence;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_ReqSequence;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_CMSSequence;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_OtherMsgSequence;
#endif /* SB_USE_CLASS_TLIST */

		void initInstances();

	public:
		bool SaveToBuffer(void * Buffer, int32_t &Size);

		void LoadFromBuffer(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_ControlSequence();

		SB_DECLARE_PROPERTY_GET(TList*, get_ControlSequence, TElPKIData, ControlSequence);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_ReqSequence();

		SB_DECLARE_PROPERTY_GET(TList*, get_ReqSequence, TElPKIData, ReqSequence);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_CMSSequence();

		SB_DECLARE_PROPERTY_GET(TList*, get_CMSSequence, TElPKIData, CMSSequence);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_OtherMsgSequence();

		SB_DECLARE_PROPERTY_GET(TList*, get_OtherMsgSequence, TElPKIData, OtherMsgSequence);
#endif /* SB_USE_CLASS_TLIST */

		TElPKIData(TElPKIDataHandle handle, TElOwnHandle ownHandle);

		TElPKIData();

		virtual ~TElPKIData();

};
#endif /* SB_USE_CLASS_TELPKIDATA */

#ifdef SB_USE_CLASS_TELPKIRESPONSE
class TElPKIResponse: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKIResponse)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_ControlSequence;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_CMSSequence;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_OtherMsgSequence;
#endif /* SB_USE_CLASS_TLIST */

		void initInstances();

	public:
		bool SaveToBuffer(void * Buffer, int32_t &Size);

		void LoadFromBuffer(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_ControlSequence();

		SB_DECLARE_PROPERTY_GET(TList*, get_ControlSequence, TElPKIResponse, ControlSequence);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_CMSSequence();

		SB_DECLARE_PROPERTY_GET(TList*, get_CMSSequence, TElPKIResponse, CMSSequence);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_OtherMsgSequence();

		SB_DECLARE_PROPERTY_GET(TList*, get_OtherMsgSequence, TElPKIResponse, OtherMsgSequence);
#endif /* SB_USE_CLASS_TLIST */

		TElPKIResponse(TElPKIResponseHandle handle, TElOwnHandle ownHandle);

		TElPKIResponse();

		virtual ~TElPKIResponse();

};
#endif /* SB_USE_CLASS_TELPKIRESPONSE */

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
class TElControlAttribute: public TObject
{
	private:
		SB_DISABLE_COPY(TElControlAttribute)
	public:
#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE
		static TElControlAttributeHandle CreateInstance(TElTaggedAttribute &Tagged);

		static TElControlAttributeHandle CreateInstance(TElTaggedAttribute *Tagged);
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE
		TElControlAttributeHandle CreateInstance_Inst(TElTaggedAttribute &Tagged);

		TElControlAttributeHandle CreateInstance_Inst(TElTaggedAttribute *Tagged);
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE
		virtual void LoadFromTagged(TElTaggedAttribute &Tagged);

		virtual void LoadFromTagged(TElTaggedAttribute *Tagged);
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_Values(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual int32_t get_ValueCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ValueCount, TElControlAttribute, ValueCount);

		TElControlAttribute(TElControlAttributeHandle handle, TElOwnHandle ownHandle);

		TElControlAttribute();

};
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTIFICATIONATTRIBUTE
class TElIdentificationAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElIdentificationAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual void set_Content(const std::vector<uint8_t> &Value);

		TElIdentificationAttribute(TElIdentificationAttributeHandle handle, TElOwnHandle ownHandle);

		TElIdentificationAttribute();

};
#endif /* SB_USE_CLASS_TELIDENTIFICATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELPENDINFO
class TElPendInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPendInfo)
	public:
		virtual void get_PendToken(std::vector<uint8_t> &OutResult);

		virtual void set_PendToken(const std::vector<uint8_t> &Value);

		virtual int64_t get_PendTime();

		virtual void set_PendTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_PendTime, set_PendTime, TElPendInfo, PendTime);

		TElPendInfo(TElPendInfoHandle handle, TElOwnHandle ownHandle);

		TElPendInfo();

};
#endif /* SB_USE_CLASS_TELPENDINFO */

#ifdef SB_USE_CLASS_TELCMCSTATUSINFOATTRIBUTE
class TElCMCStatusInfoAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElCMCStatusInfoAttribute)
#ifdef SB_USE_CLASS_TELPENDINFO
		TElPendInfo* _Inst_PendInfo;
#endif /* SB_USE_CLASS_TELPENDINFO */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_CMCStatus();

		virtual void set_CMCStatus(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CMCStatus, set_CMCStatus, TElCMCStatusInfoAttribute, CMCStatus);

		virtual void get_BodyList(std::vector<int32_t> &OutResult);

		virtual void set_BodyList(const std::vector<int32_t> &Value);

		virtual void get_StatusString(std::string &OutResult);

		virtual void set_StatusString(const std::string &Value);

		virtual bool get_HasPendInfo();

		virtual void set_HasPendInfo(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasPendInfo, set_HasPendInfo, TElCMCStatusInfoAttribute, HasPendInfo);

		virtual bool get_HasFailInfo();

		virtual void set_HasFailInfo(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasFailInfo, set_HasFailInfo, TElCMCStatusInfoAttribute, HasFailInfo);

		virtual int32_t get_FailInfo();

		virtual void set_FailInfo(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FailInfo, set_FailInfo, TElCMCStatusInfoAttribute, FailInfo);

#ifdef SB_USE_CLASS_TELPENDINFO
		virtual TElPendInfo* get_PendInfo();

		virtual void set_PendInfo(TElPendInfo &Value);

		virtual void set_PendInfo(TElPendInfo *Value);

		SB_DECLARE_PROPERTY(TElPendInfo*, get_PendInfo, set_PendInfo, TElCMCStatusInfoAttribute, PendInfo);
#endif /* SB_USE_CLASS_TELPENDINFO */

		TElCMCStatusInfoAttribute(TElCMCStatusInfoAttributeHandle handle, TElOwnHandle ownHandle);

		TElCMCStatusInfoAttribute();

		virtual ~TElCMCStatusInfoAttribute();

};
#endif /* SB_USE_CLASS_TELCMCSTATUSINFOATTRIBUTE */

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
class TElBodyPartReference: public TObject
{
	private:
		SB_DISABLE_COPY(TElBodyPartReference)
	public:
		TElBodyPartReference(TElBodyPartReferenceHandle handle, TElOwnHandle ownHandle);

		TElBodyPartReference();

};
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

#ifdef SB_USE_CLASS_TELBODYPARTID
class TElBodyPartID: public TElBodyPartReference
{
	private:
		SB_DISABLE_COPY(TElBodyPartID)
	public:
		virtual int32_t get_BodyPartID();

		virtual void set_BodyPartID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BodyPartID, set_BodyPartID, TElBodyPartID, BodyPartID);

		TElBodyPartID(TElBodyPartIDHandle handle, TElOwnHandle ownHandle);

		TElBodyPartID();

		explicit TElBodyPartID(int32_t Value);

};
#endif /* SB_USE_CLASS_TELBODYPARTID */

#ifdef SB_USE_CLASS_TELBODYPARTPATH
class TElBodyPartPath: public TElBodyPartReference
{
	private:
		SB_DISABLE_COPY(TElBodyPartPath)
	public:
		virtual void get_BodyPartPath(std::vector<int32_t> &OutResult);

		virtual void set_BodyPartPath(const std::vector<int32_t> &Value);

		TElBodyPartPath(TElBodyPartPathHandle handle, TElOwnHandle ownHandle);

		TElBodyPartPath();

		explicit TElBodyPartPath(const std::vector<int32_t> &Value);

};
#endif /* SB_USE_CLASS_TELBODYPARTPATH */

#ifdef SB_USE_CLASS_TELEXTENDEDFAILINFO
class TElExtendedFailInfo: public TElBodyPartReference
{
	private:
		SB_DISABLE_COPY(TElExtendedFailInfo)
	public:
		virtual void get_FailInfoOID(std::vector<uint8_t> &OutResult);

		virtual void set_FailInfoOID(const std::vector<uint8_t> &Value);

		virtual void get_FailInfoValue(std::vector<uint8_t> &OutResult);

		virtual void set_FailInfoValue(const std::vector<uint8_t> &Value);

		TElExtendedFailInfo(TElExtendedFailInfoHandle handle, TElOwnHandle ownHandle);

		TElExtendedFailInfo();

};
#endif /* SB_USE_CLASS_TELEXTENDEDFAILINFO */

#ifdef SB_USE_CLASS_TELCMCSTATUSINFOV2ATTRIBUTE
class TElCMCStatusInfoV2Attribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElCMCStatusInfoV2Attribute)
#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
		TElBodyPartReference* _Inst_BodyList;
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */
#ifdef SB_USE_CLASS_TELPENDINFO
		TElPendInfo* _Inst_PendInfo;
#endif /* SB_USE_CLASS_TELPENDINFO */
#ifdef SB_USE_CLASS_TELEXTENDEDFAILINFO
		TElExtendedFailInfo* _Inst_ExtendedFailInfo;
#endif /* SB_USE_CLASS_TELEXTENDEDFAILINFO */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
		int32_t AddBodyPartReference(TElBodyPartReference &Ref);

		int32_t AddBodyPartReference(TElBodyPartReference *Ref);
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

		void RemoveBodyPartReferece(int32_t Idx);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_CMCStatus();

		virtual void set_CMCStatus(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CMCStatus, set_CMCStatus, TElCMCStatusInfoV2Attribute, CMCStatus);

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
		virtual TElBodyPartReference* get_BodyList(int32_t Index);
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

		virtual int32_t get_BodyListCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BodyListCount, TElCMCStatusInfoV2Attribute, BodyListCount);

		virtual void get_StatusString(std::string &OutResult);

		virtual void set_StatusString(const std::string &Value);

		virtual bool get_HasPendInfo();

		virtual void set_HasPendInfo(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasPendInfo, set_HasPendInfo, TElCMCStatusInfoV2Attribute, HasPendInfo);

		virtual bool get_HasFailInfo();

		virtual void set_HasFailInfo(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasFailInfo, set_HasFailInfo, TElCMCStatusInfoV2Attribute, HasFailInfo);

		virtual bool get_HasExtendedFailInfo();

		virtual void set_HasExtendedFailInfo(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasExtendedFailInfo, set_HasExtendedFailInfo, TElCMCStatusInfoV2Attribute, HasExtendedFailInfo);

		virtual int32_t get_FailInfo();

		virtual void set_FailInfo(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FailInfo, set_FailInfo, TElCMCStatusInfoV2Attribute, FailInfo);

#ifdef SB_USE_CLASS_TELPENDINFO
		virtual TElPendInfo* get_PendInfo();

		virtual void set_PendInfo(TElPendInfo &Value);

		virtual void set_PendInfo(TElPendInfo *Value);

		SB_DECLARE_PROPERTY(TElPendInfo*, get_PendInfo, set_PendInfo, TElCMCStatusInfoV2Attribute, PendInfo);
#endif /* SB_USE_CLASS_TELPENDINFO */

#ifdef SB_USE_CLASS_TELEXTENDEDFAILINFO
		virtual TElExtendedFailInfo* get_ExtendedFailInfo();

		virtual void set_ExtendedFailInfo(TElExtendedFailInfo &Value);

		virtual void set_ExtendedFailInfo(TElExtendedFailInfo *Value);

		SB_DECLARE_PROPERTY(TElExtendedFailInfo*, get_ExtendedFailInfo, set_ExtendedFailInfo, TElCMCStatusInfoV2Attribute, ExtendedFailInfo);
#endif /* SB_USE_CLASS_TELEXTENDEDFAILINFO */

		TElCMCStatusInfoV2Attribute(TElCMCStatusInfoV2AttributeHandle handle, TElOwnHandle ownHandle);

		TElCMCStatusInfoV2Attribute();

		virtual ~TElCMCStatusInfoV2Attribute();

};
#endif /* SB_USE_CLASS_TELCMCSTATUSINFOV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELADDEXTENSIONSATTRIBUTE
class TElAddExtensionsAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElAddExtensionsAttribute)
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		TElCertificateExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_PKIDataReference();

		virtual void set_PKIDataReference(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PKIDataReference, set_PKIDataReference, TElAddExtensionsAttribute, PKIDataReference);

		virtual void get_CertReferences(std::vector<int32_t> &OutResult);

		virtual void set_CertReferences(const std::vector<int32_t> &Value);

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		virtual TElCertificateExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElCertificateExtensions*, get_Extensions, TElAddExtensionsAttribute, Extensions);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		TElAddExtensionsAttribute(TElAddExtensionsAttributeHandle handle, TElOwnHandle ownHandle);

		TElAddExtensionsAttribute();

		virtual ~TElAddExtensionsAttribute();

};
#endif /* SB_USE_CLASS_TELADDEXTENSIONSATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTITYPROOFV2ATTRIBUTE
class TElIdentityProofV2Attribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElIdentityProofV2Attribute)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_HashAlgID;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_MacAlgID;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_HashAlgID();

		virtual void set_HashAlgID(TElAlgorithmIdentifier &Value);

		virtual void set_HashAlgID(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_HashAlgID, set_HashAlgID, TElIdentityProofV2Attribute, HashAlgID);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_MacAlgID();

		virtual void set_MacAlgID(TElAlgorithmIdentifier &Value);

		virtual void set_MacAlgID(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_MacAlgID, set_MacAlgID, TElIdentityProofV2Attribute, MacAlgID);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_Witness(std::vector<uint8_t> &OutResult);

		virtual void set_Witness(const std::vector<uint8_t> &Value);

		TElIdentityProofV2Attribute(TElIdentityProofV2AttributeHandle handle, TElOwnHandle ownHandle);

		TElIdentityProofV2Attribute();

		virtual ~TElIdentityProofV2Attribute();

};
#endif /* SB_USE_CLASS_TELIDENTITYPROOFV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTITYPROOFATTRIBUTE
class TElIdentityProofAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElIdentityProofAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_IdentifyProof(std::vector<uint8_t> &OutResult);

		virtual void set_IdentifyProof(const std::vector<uint8_t> &Value);

		TElIdentityProofAttribute(TElIdentityProofAttributeHandle handle, TElOwnHandle ownHandle);

		TElIdentityProofAttribute();

};
#endif /* SB_USE_CLASS_TELIDENTITYPROOFATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKWITNESSV2ATTRIBUTE
class TElPopLinkWitnessV2Attribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElPopLinkWitnessV2Attribute)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_KeyGenAlgID;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_MacAlgID;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_KeyGenAlgID();

		virtual void set_KeyGenAlgID(TElAlgorithmIdentifier &Value);

		virtual void set_KeyGenAlgID(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_KeyGenAlgID, set_KeyGenAlgID, TElPopLinkWitnessV2Attribute, KeyGenAlgID);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_MacAlgID();

		virtual void set_MacAlgID(TElAlgorithmIdentifier &Value);

		virtual void set_MacAlgID(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_MacAlgID, set_MacAlgID, TElPopLinkWitnessV2Attribute, MacAlgID);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_Witness(std::vector<uint8_t> &OutResult);

		virtual void set_Witness(const std::vector<uint8_t> &Value);

		TElPopLinkWitnessV2Attribute(TElPopLinkWitnessV2AttributeHandle handle, TElOwnHandle ownHandle);

		TElPopLinkWitnessV2Attribute();

		virtual ~TElPopLinkWitnessV2Attribute();

};
#endif /* SB_USE_CLASS_TELPOPLINKWITNESSV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKWITNESSATTRIBUTE
class TElPopLinkWitnessAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElPopLinkWitnessAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_PopLinkWitness(std::vector<uint8_t> &OutResult);

		virtual void set_PopLinkWitness(const std::vector<uint8_t> &Value);

		TElPopLinkWitnessAttribute(TElPopLinkWitnessAttributeHandle handle, TElOwnHandle ownHandle);

		TElPopLinkWitnessAttribute();

};
#endif /* SB_USE_CLASS_TELPOPLINKWITNESSATTRIBUTE */

#ifdef SB_USE_CLASS_TELDATARETURNATTRIBUTE
class TElDataReturnAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElDataReturnAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_DataReturn(std::vector<uint8_t> &OutResult);

		virtual void set_DataReturn(const std::vector<uint8_t> &Value);

		TElDataReturnAttribute(TElDataReturnAttributeHandle handle, TElOwnHandle ownHandle);

		TElDataReturnAttribute();

};
#endif /* SB_USE_CLASS_TELDATARETURNATTRIBUTE */

#ifdef SB_USE_CLASS_TELTRANSACTIONIDENTIFIERATTRIBUTE
class TElTransactionIdentifierAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElTransactionIdentifierAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_TransactionId();

		virtual void set_TransactionId(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TransactionId, set_TransactionId, TElTransactionIdentifierAttribute, TransactionId);

		TElTransactionIdentifierAttribute(TElTransactionIdentifierAttributeHandle handle, TElOwnHandle ownHandle);

		TElTransactionIdentifierAttribute();

};
#endif /* SB_USE_CLASS_TELTRANSACTIONIDENTIFIERATTRIBUTE */

#ifdef SB_USE_CLASS_TELSENDERNONCEATTRIBUTE
class TElSenderNonceAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElSenderNonceAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual void set_Nonce(const std::vector<uint8_t> &Value);

		TElSenderNonceAttribute(TElSenderNonceAttributeHandle handle, TElOwnHandle ownHandle);

		TElSenderNonceAttribute();

};
#endif /* SB_USE_CLASS_TELSENDERNONCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELRECIPIENTNONCEATTRIBUTE
class TElRecipientNonceAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElRecipientNonceAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual void set_Nonce(const std::vector<uint8_t> &Value);

		TElRecipientNonceAttribute(TElRecipientNonceAttributeHandle handle, TElOwnHandle ownHandle);

		TElRecipientNonceAttribute();

};
#endif /* SB_USE_CLASS_TELRECIPIENTNONCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELENCRYPTEDPOPATTRIBUTE
class TElEncryptedPopAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElEncryptedPopAttribute)
#ifdef SB_USE_CLASS_TELTAGGEDREQUEST
		TElTaggedRequest* _Inst_Request;
#endif /* SB_USE_CLASS_TELTAGGEDREQUEST */
#ifdef SB_USE_CLASS_TELCONTENTINFO
		TElContentInfo* _Inst_CMS;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_POPAlgID;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_WitnessAlgID;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELTAGGEDREQUEST
		virtual TElTaggedRequest* get_Request();

		virtual void set_Request(TElTaggedRequest &Value);

		virtual void set_Request(TElTaggedRequest *Value);

		SB_DECLARE_PROPERTY(TElTaggedRequest*, get_Request, set_Request, TElEncryptedPopAttribute, Request);
#endif /* SB_USE_CLASS_TELTAGGEDREQUEST */

#ifdef SB_USE_CLASS_TELCONTENTINFO
		virtual TElContentInfo* get_CMS();

		virtual void set_CMS(TElContentInfo &Value);

		virtual void set_CMS(TElContentInfo *Value);

		SB_DECLARE_PROPERTY(TElContentInfo*, get_CMS, set_CMS, TElEncryptedPopAttribute, CMS);
#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_POPAlgID();

		virtual void set_POPAlgID(TElAlgorithmIdentifier &Value);

		virtual void set_POPAlgID(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_POPAlgID, set_POPAlgID, TElEncryptedPopAttribute, POPAlgID);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_WitnessAlgID();

		virtual void set_WitnessAlgID(TElAlgorithmIdentifier &Value);

		virtual void set_WitnessAlgID(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_WitnessAlgID, set_WitnessAlgID, TElEncryptedPopAttribute, WitnessAlgID);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_Witness(std::vector<uint8_t> &OutResult);

		virtual void set_Witness(const std::vector<uint8_t> &Value);

		TElEncryptedPopAttribute(TElEncryptedPopAttributeHandle handle, TElOwnHandle ownHandle);

		TElEncryptedPopAttribute();

		virtual ~TElEncryptedPopAttribute();

};
#endif /* SB_USE_CLASS_TELENCRYPTEDPOPATTRIBUTE */

#ifdef SB_USE_CLASS_TELDECRYPTEDPOPATTRIBUTE
class TElDecryptedPopAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElDecryptedPopAttribute)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_POPAlgID;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_BodyPartId();

		virtual void set_BodyPartId(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BodyPartId, set_BodyPartId, TElDecryptedPopAttribute, BodyPartId);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_POPAlgID();

		virtual void set_POPAlgID(TElAlgorithmIdentifier &Value);

		virtual void set_POPAlgID(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_POPAlgID, set_POPAlgID, TElDecryptedPopAttribute, POPAlgID);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_POP(std::vector<uint8_t> &OutResult);

		virtual void set_POP(const std::vector<uint8_t> &Value);

		TElDecryptedPopAttribute(TElDecryptedPopAttributeHandle handle, TElOwnHandle ownHandle);

		TElDecryptedPopAttribute();

		virtual ~TElDecryptedPopAttribute();

};
#endif /* SB_USE_CLASS_TELDECRYPTEDPOPATTRIBUTE */

#ifdef SB_USE_CLASS_TELLRAPOPWITNESSATTRIBUTE
class TElLraPopWitnessAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElLraPopWitnessAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_BodyPartId();

		virtual void set_BodyPartId(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BodyPartId, set_BodyPartId, TElLraPopWitnessAttribute, BodyPartId);

		virtual void get_BodyIds(std::vector<int32_t> &OutResult);

		virtual void set_BodyIds(const std::vector<int32_t> &Value);

		TElLraPopWitnessAttribute(TElLraPopWitnessAttributeHandle handle, TElOwnHandle ownHandle);

		TElLraPopWitnessAttribute();

};
#endif /* SB_USE_CLASS_TELLRAPOPWITNESSATTRIBUTE */

#ifdef SB_USE_CLASS_TELGETCERTIFICATEATTRIBUTE
class TElGetCertificateAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElGetCertificateAttribute)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_IssuerName;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_IssuerName();

		virtual void set_IssuerName(TElGeneralName &Value);

		virtual void set_IssuerName(TElGeneralName *Value);

		SB_DECLARE_PROPERTY(TElGeneralName*, get_IssuerName, set_IssuerName, TElGetCertificateAttribute, IssuerName);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		virtual int32_t get_SerialNumber();

		virtual void set_SerialNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SerialNumber, set_SerialNumber, TElGetCertificateAttribute, SerialNumber);

		TElGetCertificateAttribute(TElGetCertificateAttributeHandle handle, TElOwnHandle ownHandle);

		TElGetCertificateAttribute();

		virtual ~TElGetCertificateAttribute();

};
#endif /* SB_USE_CLASS_TELGETCERTIFICATEATTRIBUTE */

#ifdef SB_USE_CLASS_TELGETCRLATTRIBUTE
class TElGetCRLAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElGetCRLAttribute)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_IssuerName;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_CRLName;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_IssuerName();

		virtual void set_IssuerName(TElRelativeDistinguishedName &Value);

		virtual void set_IssuerName(TElRelativeDistinguishedName *Value);

		SB_DECLARE_PROPERTY(TElRelativeDistinguishedName*, get_IssuerName, set_IssuerName, TElGetCRLAttribute, IssuerName);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_CRLName();

		virtual void set_CRLName(TElGeneralName &Value);

		virtual void set_CRLName(TElGeneralName *Value);

		SB_DECLARE_PROPERTY(TElGeneralName*, get_CRLName, set_CRLName, TElGetCRLAttribute, CRLName);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		virtual int64_t get_Time();

		virtual void set_Time(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Time, set_Time, TElGetCRLAttribute, Time);

		virtual TSBCRLReasonFlags get_Reasons();

		virtual void set_Reasons(TSBCRLReasonFlags Value);

		SB_DECLARE_PROPERTY(TSBCRLReasonFlags, get_Reasons, set_Reasons, TElGetCRLAttribute, Reasons);

		TElGetCRLAttribute(TElGetCRLAttributeHandle handle, TElOwnHandle ownHandle);

		TElGetCRLAttribute();

		virtual ~TElGetCRLAttribute();

};
#endif /* SB_USE_CLASS_TELGETCRLATTRIBUTE */

#ifdef SB_USE_CLASS_TELREVOCATIONREQUESTATTRIBUTE
class TElRevocationRequestAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElRevocationRequestAttribute)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_IssuerName;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_IssuerName();

		virtual void set_IssuerName(TElRelativeDistinguishedName &Value);

		virtual void set_IssuerName(TElRelativeDistinguishedName *Value);

		SB_DECLARE_PROPERTY(TElRelativeDistinguishedName*, get_IssuerName, set_IssuerName, TElRevocationRequestAttribute, IssuerName);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual int32_t get_SerialNumber();

		virtual void set_SerialNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SerialNumber, set_SerialNumber, TElRevocationRequestAttribute, SerialNumber);

		virtual TSBCRLReasonFlag get_Reason();

		virtual void set_Reason(TSBCRLReasonFlag Value);

		SB_DECLARE_PROPERTY(TSBCRLReasonFlag, get_Reason, set_Reason, TElRevocationRequestAttribute, Reason);

		virtual int64_t get_InvalidityDate();

		virtual void set_InvalidityDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_InvalidityDate, set_InvalidityDate, TElRevocationRequestAttribute, InvalidityDate);

		virtual void get_SharedSecret(std::vector<uint8_t> &OutResult);

		virtual void set_SharedSecret(const std::vector<uint8_t> &Value);

		virtual void get_Comment(std::string &OutResult);

		virtual void set_Comment(const std::string &Value);

		TElRevocationRequestAttribute(TElRevocationRequestAttributeHandle handle, TElOwnHandle ownHandle);

		TElRevocationRequestAttribute();

		virtual ~TElRevocationRequestAttribute();

};
#endif /* SB_USE_CLASS_TELREVOCATIONREQUESTATTRIBUTE */

#ifdef SB_USE_CLASS_TELREGISTRATIONINFORMATIONATTRIBUTE
class TElRegistrationInformationAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElRegistrationInformationAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_RegInfo(std::vector<uint8_t> &OutResult);

		virtual void set_RegInfo(const std::vector<uint8_t> &Value);

		TElRegistrationInformationAttribute(TElRegistrationInformationAttributeHandle handle, TElOwnHandle ownHandle);

		TElRegistrationInformationAttribute();

};
#endif /* SB_USE_CLASS_TELREGISTRATIONINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELRESPONSEINFORMATIONATTRIBUTE
class TElResponseInformationAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElResponseInformationAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_ResponseInfo(std::vector<uint8_t> &OutResult);

		virtual void set_ResponseInfo(const std::vector<uint8_t> &Value);

		TElResponseInformationAttribute(TElResponseInformationAttributeHandle handle, TElOwnHandle ownHandle);

		TElResponseInformationAttribute();

};
#endif /* SB_USE_CLASS_TELRESPONSEINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELQUERYPENDINGATTRIBUTE
class TElQueryPendingAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElQueryPendingAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_QueryPending(std::vector<uint8_t> &OutResult);

		virtual void set_QueryPending(const std::vector<uint8_t> &Value);

		TElQueryPendingAttribute(TElQueryPendingAttributeHandle handle, TElOwnHandle ownHandle);

		TElQueryPendingAttribute();

};
#endif /* SB_USE_CLASS_TELQUERYPENDINGATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONFIRMCERTACCEPTANCEATTRIBUTE
class TElConfirmCertAcceptanceAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElConfirmCertAcceptanceAttribute)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_IssuerName;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_IssuerName();

		virtual void set_IssuerName(TElGeneralName &Value);

		virtual void set_IssuerName(TElGeneralName *Value);

		SB_DECLARE_PROPERTY(TElGeneralName*, get_IssuerName, set_IssuerName, TElConfirmCertAcceptanceAttribute, IssuerName);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		virtual int32_t get_SerialNumber();

		virtual void set_SerialNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SerialNumber, set_SerialNumber, TElConfirmCertAcceptanceAttribute, SerialNumber);

		TElConfirmCertAcceptanceAttribute(TElConfirmCertAcceptanceAttributeHandle handle, TElOwnHandle ownHandle);

		TElConfirmCertAcceptanceAttribute();

		virtual ~TElConfirmCertAcceptanceAttribute();

};
#endif /* SB_USE_CLASS_TELCONFIRMCERTACCEPTANCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELPUBLISHTRUSTANCHORSATTRIBUTE
class TElPublishTrustAnchorsAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElPublishTrustAnchorsAttribute)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_HashAlgorithm;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_SeqNumber();

		virtual void set_SeqNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SeqNumber, set_SeqNumber, TElPublishTrustAnchorsAttribute, SeqNumber);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_HashAlgorithm();

		virtual void set_HashAlgorithm(TElAlgorithmIdentifier &Value);

		virtual void set_HashAlgorithm(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_HashAlgorithm, set_HashAlgorithm, TElPublishTrustAnchorsAttribute, HashAlgorithm);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		TElPublishTrustAnchorsAttribute(TElPublishTrustAnchorsAttributeHandle handle, TElOwnHandle ownHandle);

		TElPublishTrustAnchorsAttribute();

		virtual ~TElPublishTrustAnchorsAttribute();

};
#endif /* SB_USE_CLASS_TELPUBLISHTRUSTANCHORSATTRIBUTE */

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAATTRIBUTE
class TElAuthenticatedDataAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElAuthenticatedDataAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_AuthPublish();

		virtual void set_AuthPublish(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthPublish, set_AuthPublish, TElAuthenticatedDataAttribute, AuthPublish);

		TElAuthenticatedDataAttribute(TElAuthenticatedDataAttributeHandle handle, TElOwnHandle ownHandle);

		TElAuthenticatedDataAttribute();

};
#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAATTRIBUTE */

#ifdef SB_USE_CLASS_TELBATCHREQUESTSATTRIBUTE
class TElBatchRequestsAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElBatchRequestsAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_BodyPartList(std::vector<int32_t> &OutResult);

		virtual void set_BodyPartList(const std::vector<int32_t> &Value);

		TElBatchRequestsAttribute(TElBatchRequestsAttributeHandle handle, TElOwnHandle ownHandle);

		TElBatchRequestsAttribute();

};
#endif /* SB_USE_CLASS_TELBATCHREQUESTSATTRIBUTE */

#ifdef SB_USE_CLASS_TELBATCHRESPONSESATTRIBUTE
class TElBatchResponsesAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElBatchResponsesAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_BodyPartList(std::vector<int32_t> &OutResult);

		virtual void set_BodyPartList(const std::vector<int32_t> &Value);

		TElBatchResponsesAttribute(TElBatchResponsesAttributeHandle handle, TElOwnHandle ownHandle);

		TElBatchResponsesAttribute();

};
#endif /* SB_USE_CLASS_TELBATCHRESPONSESATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKRANDOMATTRIBUTE
class TElPopLinkRandomAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElPopLinkRandomAttribute)
	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void get_PopLinkRandom(std::vector<uint8_t> &OutResult);

		virtual void set_PopLinkRandom(const std::vector<uint8_t> &Value);

		TElPopLinkRandomAttribute(TElPopLinkRandomAttributeHandle handle, TElOwnHandle ownHandle);

		TElPopLinkRandomAttribute();

};
#endif /* SB_USE_CLASS_TELPOPLINKRANDOMATTRIBUTE */

#ifdef SB_USE_CLASS_TELSINGLEPUBINFO
class TElSinglePubInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElSinglePubInfo)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_PubLocation;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
		virtual TSBPKIPublishMethod get_PubMethod();

		virtual void set_PubMethod(TSBPKIPublishMethod Value);

		SB_DECLARE_PROPERTY(TSBPKIPublishMethod, get_PubMethod, set_PubMethod, TElSinglePubInfo, PubMethod);

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_PubLocation();

		virtual void set_PubLocation(TElGeneralName &Value);

		virtual void set_PubLocation(TElGeneralName *Value);

		SB_DECLARE_PROPERTY(TElGeneralName*, get_PubLocation, set_PubLocation, TElSinglePubInfo, PubLocation);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		TElSinglePubInfo(TElSinglePubInfoHandle handle, TElOwnHandle ownHandle);

		TElSinglePubInfo();

		virtual ~TElSinglePubInfo();

};
#endif /* SB_USE_CLASS_TELSINGLEPUBINFO */

#ifdef SB_USE_CLASS_TELPKIPUBLICATIONINFO
class TElPKIPublicationInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKIPublicationInfo)
#ifdef SB_USE_CLASS_TELSINGLEPUBINFO
		TElSinglePubInfo* _Inst_Infos;
#endif /* SB_USE_CLASS_TELSINGLEPUBINFO */

		void initInstances();

	public:
		int32_t AddInfo();

		void RemoveInfo(int32_t Idx);

		virtual TSBPKIPublicationAction get_Action();

		virtual void set_Action(TSBPKIPublicationAction Value);

		SB_DECLARE_PROPERTY(TSBPKIPublicationAction, get_Action, set_Action, TElPKIPublicationInfo, Action);

#ifdef SB_USE_CLASS_TELSINGLEPUBINFO
		virtual TElSinglePubInfo* get_Infos(int32_t Index);
#endif /* SB_USE_CLASS_TELSINGLEPUBINFO */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElPKIPublicationInfo, Count);

		TElPKIPublicationInfo(TElPKIPublicationInfoHandle handle, TElOwnHandle ownHandle);

		TElPKIPublicationInfo();

		virtual ~TElPKIPublicationInfo();

};
#endif /* SB_USE_CLASS_TELPKIPUBLICATIONINFO */

#ifdef SB_USE_CLASS_TELPUBLICATIONINFORMATIONATTRIBUTE
class TElPublicationInformationAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElPublicationInformationAttribute)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_HashAlgorithm;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELPKIPUBLICATIONINFO
		TElPKIPublicationInfo* _Inst_PubInfo;
#endif /* SB_USE_CLASS_TELPKIPUBLICATIONINFO */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_HashAlgorithm();

		virtual void set_HashAlgorithm(TElAlgorithmIdentifier &Value);

		virtual void set_HashAlgorithm(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_HashAlgorithm, set_HashAlgorithm, TElPublicationInformationAttribute, HashAlgorithm);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELPKIPUBLICATIONINFO
		virtual TElPKIPublicationInfo* get_PubInfo();

		SB_DECLARE_PROPERTY_GET(TElPKIPublicationInfo*, get_PubInfo, TElPublicationInformationAttribute, PubInfo);
#endif /* SB_USE_CLASS_TELPKIPUBLICATIONINFO */

		TElPublicationInformationAttribute(TElPublicationInformationAttributeHandle handle, TElOwnHandle ownHandle);

		TElPublicationInformationAttribute();

		virtual ~TElPublicationInformationAttribute();

};
#endif /* SB_USE_CLASS_TELPUBLICATIONINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONTROLPROCESSEDATTRIBUTE
class TElControlProcessedAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElControlProcessedAttribute)
#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
		TElBodyPartReference* _Inst_BodyList;
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
		int32_t AddBodyPartReference(TElBodyPartReference &Ref);

		int32_t AddBodyPartReference(TElBodyPartReference *Ref);
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

		void RemoveBodyPartReferece(int32_t Idx);

		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
		virtual TElBodyPartReference* get_BodyList(int32_t Index);
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

		virtual int32_t get_BodyListCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BodyListCount, TElControlProcessedAttribute, BodyListCount);

		TElControlProcessedAttribute(TElControlProcessedAttributeHandle handle, TElOwnHandle ownHandle);

		TElControlProcessedAttribute();

		virtual ~TElControlProcessedAttribute();

};
#endif /* SB_USE_CLASS_TELCONTROLPROCESSEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELOPTIONALVALIDITY
class TElOptionalValidity: public TObject
{
	private:
		SB_DISABLE_COPY(TElOptionalValidity)
	public:
		virtual int64_t get_NotBefore();

		virtual void set_NotBefore(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotBefore, set_NotBefore, TElOptionalValidity, NotBefore);

		virtual int64_t get_NotAfter();

		virtual void set_NotAfter(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotAfter, set_NotAfter, TElOptionalValidity, NotAfter);

		TElOptionalValidity(TElOptionalValidityHandle handle, TElOwnHandle ownHandle);

		TElOptionalValidity();

};
#endif /* SB_USE_CLASS_TELOPTIONALVALIDITY */

#ifdef SB_USE_CLASS_TELPUBLICKEYINFO
class TElPublicKeyInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPublicKeyInfo)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_Algorithm;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_Algorithm();

		virtual void set_Algorithm(TElAlgorithmIdentifier &Value);

		virtual void set_Algorithm(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_Algorithm, set_Algorithm, TElPublicKeyInfo, Algorithm);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_PublicKey(std::vector<uint8_t> &OutResult);

		virtual void set_PublicKey(const std::vector<uint8_t> &Value);

		TElPublicKeyInfo(TElPublicKeyInfoHandle handle, TElOwnHandle ownHandle);

		TElPublicKeyInfo();

		virtual ~TElPublicKeyInfo();

};
#endif /* SB_USE_CLASS_TELPUBLICKEYINFO */

#ifdef SB_USE_CLASS_TELCERTTEMPLATE
class TElCertTemplate: public TObject
{
	private:
		SB_DISABLE_COPY(TElCertTemplate)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_Subject;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELPUBLICKEYINFO
		TElPublicKeyInfo* _Inst_SubjectPublicKeyInfo;
#endif /* SB_USE_CLASS_TELPUBLICKEYINFO */
#ifdef SB_USE_CLASS_TELOPTIONALVALIDITY
		TElOptionalValidity* _Inst_Validity;
#endif /* SB_USE_CLASS_TELOPTIONALVALIDITY */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		TElCertificateExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		void SaveToTag(TElASN1ConstrainedTag &Tag);

		void SaveToTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		void LoadFromTag(TElASN1ConstrainedTag &Tag);

		void LoadFromTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_Subject();

		virtual void set_Subject(TElRelativeDistinguishedName &Value);

		virtual void set_Subject(TElRelativeDistinguishedName *Value);

		SB_DECLARE_PROPERTY(TElRelativeDistinguishedName*, get_Subject, set_Subject, TElCertTemplate, Subject);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELPUBLICKEYINFO
		virtual TElPublicKeyInfo* get_SubjectPublicKeyInfo();

		SB_DECLARE_PROPERTY_GET(TElPublicKeyInfo*, get_SubjectPublicKeyInfo, TElCertTemplate, SubjectPublicKeyInfo);
#endif /* SB_USE_CLASS_TELPUBLICKEYINFO */

#ifdef SB_USE_CLASS_TELOPTIONALVALIDITY
		virtual TElOptionalValidity* get_Validity();

		virtual void set_Validity(TElOptionalValidity &Value);

		virtual void set_Validity(TElOptionalValidity *Value);

		SB_DECLARE_PROPERTY(TElOptionalValidity*, get_Validity, set_Validity, TElCertTemplate, Validity);
#endif /* SB_USE_CLASS_TELOPTIONALVALIDITY */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		virtual TElCertificateExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElCertificateExtensions*, get_Extensions, TElCertTemplate, Extensions);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		TElCertTemplate(TElCertTemplateHandle handle, TElOwnHandle ownHandle);

		TElCertTemplate();

		virtual ~TElCertTemplate();

};
#endif /* SB_USE_CLASS_TELCERTTEMPLATE */

#ifdef SB_USE_CLASS_TELMODCERTIFICATIONREQUESTATTRIBUTE
class TElModCertificationRequestAttribute: public TElControlAttribute
{
	private:
		SB_DISABLE_COPY(TElModCertificationRequestAttribute)
#ifdef SB_USE_CLASS_TELBODYPARTPATH
		TElBodyPartPath* _Inst_PKIDataReference;
#endif /* SB_USE_CLASS_TELBODYPARTPATH */
#ifdef SB_USE_CLASS_TELCERTTEMPLATE
		TElCertTemplate* _Inst_CertTemplate;
#endif /* SB_USE_CLASS_TELCERTTEMPLATE */

		void initInstances();

	public:
		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		static TClassHandle ClassType();

		virtual void get_OID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELBODYPARTPATH
		virtual TElBodyPartPath* get_PKIDataReference();

		SB_DECLARE_PROPERTY_GET(TElBodyPartPath*, get_PKIDataReference, TElModCertificationRequestAttribute, PKIDataReference);
#endif /* SB_USE_CLASS_TELBODYPARTPATH */

		virtual void get_CertReferences(std::vector<int32_t> &OutResult);

		virtual void set_CertReferences(const std::vector<int32_t> &Value);

		virtual bool get_Replace();

		virtual void set_Replace(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Replace, set_Replace, TElModCertificationRequestAttribute, Replace);

#ifdef SB_USE_CLASS_TELCERTTEMPLATE
		virtual TElCertTemplate* get_CertTemplate();

		SB_DECLARE_PROPERTY_GET(TElCertTemplate*, get_CertTemplate, TElModCertificationRequestAttribute, CertTemplate);
#endif /* SB_USE_CLASS_TELCERTTEMPLATE */

		TElModCertificationRequestAttribute(TElModCertificationRequestAttributeHandle handle, TElOwnHandle ownHandle);

		TElModCertificationRequestAttribute();

		virtual ~TElModCertificationRequestAttribute();

};
#endif /* SB_USE_CLASS_TELMODCERTIFICATIONREQUESTATTRIBUTE */

#ifdef SB_USE_CLASS_TELFULLPKIREQUEST
class TElFullPKIRequest: public TObject
{
	private:
		SB_DISABLE_COPY(TElFullPKIRequest)
#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
		TElCertificateRequest* _Inst_Requests;
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */
#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
		TElControlAttribute* _Inst_ControlAttributes;
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */
#ifdef SB_USE_CLASS_TELCONTENTINFO
		TElContentInfo* _Inst_CMSs;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELOTHERMSG
		TElOtherMsg* _Inst_OtherMessages;
#endif /* SB_USE_CLASS_TELOTHERMSG */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_SigningCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_EncryptionCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
		static TElFullPKIRequestHandle CreateSimpleRequest(TElCertificateRequest &Request);

		static TElFullPKIRequestHandle CreateSimpleRequest(TElCertificateRequest *Request);
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
		TElFullPKIRequestHandle CreateSimpleRequest_Inst(TElCertificateRequest &Request);

		TElFullPKIRequestHandle CreateSimpleRequest_Inst(TElCertificateRequest *Request);
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef SB_USE_CLASSES_TELCERTIFICATEREQUEST_AND_TELCUSTOMCERTSTORAGE
		static TElFullPKIRequestHandle CreateSimpleRequest(TElCertificateRequest &Request, TElCustomCertStorage &EncryptionCertificates);

		static TElFullPKIRequestHandle CreateSimpleRequest(TElCertificateRequest *Request, TElCustomCertStorage *EncryptionCertificates);
#endif /* SB_USE_CLASSES_TELCERTIFICATEREQUEST_AND_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCERTIFICATEREQUEST_AND_TELCUSTOMCERTSTORAGE
		TElFullPKIRequestHandle CreateSimpleRequest_Inst(TElCertificateRequest &Request, TElCustomCertStorage &EncryptionCertificates);

		TElFullPKIRequestHandle CreateSimpleRequest_Inst(TElCertificateRequest *Request, TElCustomCertStorage *EncryptionCertificates);
#endif /* SB_USE_CLASSES_TELCERTIFICATEREQUEST_AND_TELCUSTOMCERTSTORAGE */

		bool SaveToBuffer(void * Buffer, int32_t &Size);

		void LoadFromBuffer(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Strm);

		void LoadFromStream(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Strm);

		void SaveToStream(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

		void SaveToFile(const std::string &FileName);

		void LoadFromFile(const std::string &FileName);

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
		int32_t AddRequest(TElCertificateRequest &Req);

		int32_t AddRequest(TElCertificateRequest *Req);
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

		void RemoveRequest(int32_t Index);

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
		int32_t AddControlAttribute(TElControlAttribute &Attr);

		int32_t AddControlAttribute(TElControlAttribute *Attr);
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

		void RemoveControlAttribute(int32_t Index);

		int32_t AddCMS(const std::vector<uint8_t> &CMS, const std::vector<uint8_t> &ContentType);

		int32_t AddCMS(TElFullPKIRequest &CMS);

		int32_t AddCMS(TElFullPKIRequest *CMS);

		void RemoveCMS(int32_t Index);

		int32_t AddOtherMsg(const std::vector<uint8_t> &Msg, const std::vector<uint8_t> &ContentType);

		void RemoveOtherMsg(int32_t Index);

		int32_t GetBodyPartID(TObject &Part);

		int32_t GetBodyPartID(TObject *Part);

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
		virtual TElCertificateRequest* get_Requests(int32_t Index);
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
		virtual TElControlAttribute* get_ControlAttributes(int32_t Index);
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONTENTINFO
		virtual TElContentInfo* get_CMSs(int32_t Index);
#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELOTHERMSG
		virtual TElOtherMsg* get_OtherMessages(int32_t Index);
#endif /* SB_USE_CLASS_TELOTHERMSG */

		virtual int32_t get_RequestCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RequestCount, TElFullPKIRequest, RequestCount);

		virtual int32_t get_ControlAttributeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ControlAttributeCount, TElFullPKIRequest, ControlAttributeCount);

		virtual int32_t get_CMSCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CMSCount, TElFullPKIRequest, CMSCount);

		virtual int32_t get_OtherMessageCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OtherMessageCount, TElFullPKIRequest, OtherMessageCount);

		virtual TSBFullPKIFormat get_StoreFormat();

		virtual void set_StoreFormat(TSBFullPKIFormat Value);

		SB_DECLARE_PROPERTY(TSBFullPKIFormat, get_StoreFormat, set_StoreFormat, TElFullPKIRequest, StoreFormat);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_SigningCertificates();

		virtual void set_SigningCertificates(TElCustomCertStorage &Value);

		virtual void set_SigningCertificates(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_SigningCertificates, set_SigningCertificates, TElFullPKIRequest, SigningCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_EncryptionCertificates();

		virtual void set_EncryptionCertificates(TElCustomCertStorage &Value);

		virtual void set_EncryptionCertificates(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_EncryptionCertificates, set_EncryptionCertificates, TElFullPKIRequest, EncryptionCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual int32_t get_MainRequestIndex();

		virtual void set_MainRequestIndex(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MainRequestIndex, set_MainRequestIndex, TElFullPKIRequest, MainRequestIndex);

		virtual void get_OnSignature(TSBFullPKISignatureEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignature(TSBFullPKISignatureEvent pMethodValue, void * pDataValue);

		TElFullPKIRequest(TElFullPKIRequestHandle handle, TElOwnHandle ownHandle);

		TElFullPKIRequest();

		virtual ~TElFullPKIRequest();

};
#endif /* SB_USE_CLASS_TELFULLPKIREQUEST */

#ifdef SB_USE_CLASS_TELFULLPKIRESPONSE
class TElFullPKIResponse: public TObject
{
	private:
		SB_DISABLE_COPY(TElFullPKIResponse)
#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
		TElControlAttribute* _Inst_ControlAttributes;
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */
#ifdef SB_USE_CLASS_TELCONTENTINFO
		TElContentInfo* _Inst_CMSs;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELOTHERMSG
		TElOtherMsg* _Inst_OtherMessages;
#endif /* SB_USE_CLASS_TELOTHERMSG */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_SigningCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_EncryptionCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_IssuedCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		TElMemoryCRLStorage* _Inst_IssuerCRLs;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

		void initInstances();

	public:
		bool SaveToBuffer(void * Buffer, int32_t &Size);

		void LoadFromBuffer(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Strm);

		void LoadFromStream(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Strm);

		void SaveToStream(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

		void SaveToFile(const std::string &FileName);

		void LoadFromFile(const std::string &FileName);

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
		int32_t AddControlAttribute(TElControlAttribute &Attr);

		int32_t AddControlAttribute(TElControlAttribute *Attr);
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

		void RemoveControlAttribute(int32_t Index);

		int32_t AddCMS(const std::vector<uint8_t> &CMS, const std::vector<uint8_t> &ContentType);

		void RemoveCMS(int32_t Index);

		int32_t AddOtherMsg(const std::vector<uint8_t> &Msg, const std::vector<uint8_t> &ContentType);

		void RemoveOtherMsg(int32_t Index);

		int32_t GetBodyPartID(TObject &Part);

		int32_t GetBodyPartID(TObject *Part);

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
		virtual TElControlAttribute* get_ControlAttributes(int32_t Index);
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONTENTINFO
		virtual TElContentInfo* get_CMSs(int32_t Index);
#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELOTHERMSG
		virtual TElOtherMsg* get_OtherMessages(int32_t Index);
#endif /* SB_USE_CLASS_TELOTHERMSG */

		virtual int32_t get_ControlAttributeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ControlAttributeCount, TElFullPKIResponse, ControlAttributeCount);

		virtual int32_t get_CMSCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CMSCount, TElFullPKIResponse, CMSCount);

		virtual int32_t get_OtherMessageCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OtherMessageCount, TElFullPKIResponse, OtherMessageCount);

		virtual TSBFullPKIFormat get_StoreFormat();

		virtual void set_StoreFormat(TSBFullPKIFormat Value);

		SB_DECLARE_PROPERTY(TSBFullPKIFormat, get_StoreFormat, set_StoreFormat, TElFullPKIResponse, StoreFormat);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_SigningCertificates();

		virtual void set_SigningCertificates(TElCustomCertStorage &Value);

		virtual void set_SigningCertificates(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_SigningCertificates, set_SigningCertificates, TElFullPKIResponse, SigningCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_EncryptionCertificates();

		virtual void set_EncryptionCertificates(TElCustomCertStorage &Value);

		virtual void set_EncryptionCertificates(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_EncryptionCertificates, set_EncryptionCertificates, TElFullPKIResponse, EncryptionCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_IssuedCertificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_IssuedCertificates, TElFullPKIResponse, IssuedCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		virtual TElMemoryCRLStorage* get_IssuerCRLs();

		SB_DECLARE_PROPERTY_GET(TElMemoryCRLStorage*, get_IssuerCRLs, TElFullPKIResponse, IssuerCRLs);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

		virtual void get_OnSignature(TSBFullPKISignatureEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignature(TSBFullPKISignatureEvent pMethodValue, void * pDataValue);

		TElFullPKIResponse(TElFullPKIResponseHandle handle, TElOwnHandle ownHandle);

		TElFullPKIResponse();

		virtual ~TElFullPKIResponse();

};
#endif /* SB_USE_CLASS_TELFULLPKIRESPONSE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCMC */

