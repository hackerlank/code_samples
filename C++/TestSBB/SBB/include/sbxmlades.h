#ifndef __INC_SBXMLADES
#define __INC_SBXMLADES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcrl.h"
#include "sbcryptoprov.h"
#include "sbhashfunction.h"
#include "sbtspclient.h"
#include "sbocspcommon.h"
#include "sbocspclient.h"
#include "sbrdn.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbx509.h"
#include "sbpkcs7utils.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmltransform.h"
#include "sbxmlutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_xmlPKIDataEncodingDER 	"http://uri.etsi.org/01903/v1.2.2#DER"
#define SB_xmlPKIDataEncodingBER 	"http://uri.etsi.org/01903/v1.2.2#BER"
#define SB_xmlPKIDataEncodingCER 	"http://uri.etsi.org/01903/v1.2.2#CER"
#define SB_xmlPKIDataEncodingPER 	"http://uri.etsi.org/01903/v1.2.2#PER"
#define SB_xmlPKIDataEncodingXER 	"http://uri.etsi.org/01903/v1.2.2#XER"
#define SB_xmlCTIProofOfOrigin 	"http://uri.etsi.org/01903/v1.2.2#ProofOfOrigin"
#define SB_xmlCTIProofOfReceipt 	"http://uri.etsi.org/01903/v1.2.2#ProofOfReceipt"
#define SB_xmlCTIProofOfDelivery 	"http://uri.etsi.org/01903/v1.2.2#ProofOfDelivery"
#define SB_xmlCTIProofOfSender 	"http://uri.etsi.org/01903/v1.2.2#ProofOfSender"
#define SB_xmlCTIProofOfApproval 	"http://uri.etsi.org/01903/v1.2.2#ProofOfApproval"
#define SB_xmlCTIProofOfCreation 	"http://uri.etsi.org/01903/v1.2.2#ProofOfCreation"
#define SB_SXMLUnsupportedXAdESForm 	"XAdES form not supported by this XAdES version."

typedef TElClassHandle TElXMLAdESElementHandle;

typedef TElXMLAdESElementHandle ElXMLAdESElementHandle;

typedef TElClassHandle TElXMLAnyTypeHandle;

typedef TElXMLAnyTypeHandle ElXMLAnyTypeHandle;

typedef TElClassHandle TElXMLAnyTypeListHandle;

typedef TElXMLAnyTypeListHandle ElXMLAnyTypeListHandle;

typedef TElClassHandle TElXMLObjectIdentifierHandle;

typedef TElXMLObjectIdentifierHandle ElXMLObjectIdentifierHandle;

typedef TElClassHandle TElXMLEncapsulatedPKIDataHandle;

typedef TElXMLEncapsulatedPKIDataHandle ElXMLEncapsulatedPKIDataHandle;

typedef TElClassHandle TElXMLEncapsulatedPKIDataListHandle;

typedef TElXMLEncapsulatedPKIDataListHandle ElXMLEncapsulatedPKIDataListHandle;

typedef TElClassHandle TElXMLHashDataInfoHandle;

typedef TElXMLHashDataInfoHandle ElXMLHashDataInfoHandle;

typedef TElClassHandle TElXMLHashDataInfoListHandle;

typedef TElXMLHashDataInfoListHandle ElXMLHashDataInfoListHandle;

typedef TElClassHandle TElXMLCustomTimestampHandle;

typedef TElXMLCustomTimestampHandle ElXMLCustomTimestampHandle;

typedef TElClassHandle TElXMLCustomTimestampListHandle;

typedef TElXMLCustomTimestampListHandle ElXMLCustomTimestampListHandle;

typedef TElClassHandle TElXMLTimestampHandle;

typedef TElXMLTimestampHandle ElXMLTimestampHandle;

typedef TElClassHandle TElXMLTimestampListHandle;

typedef TElXMLTimestampListHandle ElXMLTimestampListHandle;

typedef TElClassHandle TElXMLIncludeHandle;

typedef TElXMLIncludeHandle ElXMLIncludeHandle;

typedef TElClassHandle TElXMLIncludeListHandle;

typedef TElXMLIncludeListHandle ElXMLIncludeListHandle;

typedef TElClassHandle TElXMLTimestamp_v1_2_2Handle;

typedef TElXMLTimestamp_v1_2_2Handle ElXMLTimestamp_v1_2_2Handle;

typedef TElClassHandle TElXMLTimestampList_v1_2_2Handle;

typedef TElXMLTimestampList_v1_2_2Handle ElXMLTimestampList_v1_2_2Handle;

typedef TElClassHandle TElCustomTSPClientListHandle;

typedef TElCustomTSPClientListHandle ElCustomTSPClientListHandle;

typedef TElClassHandle TElXMLGenericTimestampHandle;

typedef TElXMLGenericTimestampHandle ElXMLGenericTimestampHandle;

typedef TElClassHandle TElXMLGenericTimestampListHandle;

typedef TElXMLGenericTimestampListHandle ElXMLGenericTimestampListHandle;

typedef TElXMLGenericTimestampHandle TElXMLAdESTimestampHandle;

typedef TElXMLGenericTimestampHandle ElXMLXAdESTimestampHandle;

typedef TElXMLGenericTimestampListHandle TElXMLAdESTimestampListHandle;

typedef TElXMLGenericTimestampListHandle ElXMLXAdESTimestampListHandle;

typedef TElClassHandle TElXMLDigestAlgAndValueHandle;

typedef TElXMLDigestAlgAndValueHandle ElXMLDigestAlgAndValueHandle;

typedef TElClassHandle TElXMLCertIDHandle;

typedef TElXMLCertIDHandle ElXMLCertIDHandle;

typedef TElClassHandle TElXMLCertIDListHandle;

typedef TElXMLCertIDListHandle ElXMLCertIDListHandle;

typedef TElClassHandle TElXMLNoticeReferenceHandle;

typedef TElXMLNoticeReferenceHandle ElXMLNoticeReferenceHandle;

typedef TElClassHandle TElXMLSPUserNoticeHandle;

typedef TElXMLSPUserNoticeHandle ElXMLSPUserNoticeHandle;

typedef TElClassHandle TElXMLSPURIHandle;

typedef TElXMLSPURIHandle ElXMLSPURIHandle;

typedef TElClassHandle TElXMLSigPolicyQualifierHandle;

typedef TElXMLSigPolicyQualifierHandle ElXMLSigPolicyQualifierHandle;

typedef TElXMLAnyTypeListHandle TElXMLSigPolicyQualifierListHandle;

typedef TElXMLAnyTypeListHandle ElXMLSigPolicyQualifierListHandle;

typedef TElClassHandle TElXMLSignaturePolicyIdHandle;

typedef TElXMLSignaturePolicyIdHandle ElXMLSignaturePolicyIdHandle;

typedef TElClassHandle TElXMLSignaturePolicyIdentifierHandle;

typedef TElXMLSignaturePolicyIdentifierHandle ElXMLSignaturePolicyIdentifierHandle;

typedef TElClassHandle TElXMLCounterSignatureHandle;

typedef TElXMLCounterSignatureHandle ElXMLCounterSignatureHandle;

typedef TElClassHandle TElXMLCounterSignatureListHandle;

typedef TElXMLCounterSignatureListHandle ElXMLCounterSignatureListHandle;

typedef TElClassHandle TElXMLDataObjectFormatHandle;

typedef TElXMLDataObjectFormatHandle ElXMLDataObjectFormatHandle;

typedef TElClassHandle TElXMLDataObjectFormatListHandle;

typedef TElXMLDataObjectFormatListHandle ElXMLDataObjectFormatListHandle;

typedef TElClassHandle TElXMLCommitmentTypeQualifierHandle;

typedef TElXMLCommitmentTypeQualifierHandle ElXMLCommitmentTypeQualifierHandle;

typedef TElXMLAnyTypeListHandle TElXMLCommitmentTypeQualifierListHandle;

typedef TElXMLAnyTypeListHandle ElXMLCommitmentTypeQualifierListHandle;

typedef TElClassHandle TElXMLCommitmentTypeIndicationHandle;

typedef TElXMLCommitmentTypeIndicationHandle ElXMLCommitmentTypeIndicationHandle;

typedef TElClassHandle TElXMLCommitmentTypeIndicationListHandle;

typedef TElXMLCommitmentTypeIndicationListHandle ElXMLCommitmentTypeIndicationListHandle;

typedef TElClassHandle TElXMLSignatureProductionPlaceHandle;

typedef TElXMLSignatureProductionPlaceHandle ElXMLSignatureProductionPlaceHandle;

typedef TElClassHandle TElXMLEncapsulatedX509CertificatesHandle;

typedef TElXMLEncapsulatedX509CertificatesHandle ElXMLEncapsulatedX509CertificatesHandle;

typedef TElClassHandle TElXMLCertifiedRoleHandle;

typedef TElXMLCertifiedRoleHandle ElXMLCertifiedRoleHandle;

typedef TElClassHandle TElXMLCertifiedRolesListHandle;

typedef TElXMLCertifiedRolesListHandle ElXMLCertifiedRolesListHandle;

typedef TElClassHandle TElXMLClaimedRoleHandle;

typedef TElXMLClaimedRoleHandle ElXMLClaimedRoleHandle;

typedef TElClassHandle TElXMLClaimedRolesListHandle;

typedef TElXMLClaimedRolesListHandle ElXMLClaimedRolesListHandle;

typedef TElClassHandle TElXMLSignerRoleHandle;

typedef TElXMLSignerRoleHandle ElXMLSignerRoleHandle;

typedef TElClassHandle TElXMLCompleteCertificateRefsHandle;

typedef TElXMLCompleteCertificateRefsHandle ElXMLCompleteCertificateRefsHandle;

typedef TElClassHandle TElXMLCRLIdentifierHandle;

typedef TElXMLCRLIdentifierHandle ElXMLCRLIdentifierHandle;

typedef TElClassHandle TElXMLCRLRefHandle;

typedef TElXMLCRLRefHandle ElXMLCRLRefHandle;

typedef TElClassHandle TElXMLCRLRefsHandle;

typedef TElXMLCRLRefsHandle ElXMLCRLRefsHandle;

typedef TElClassHandle TElXMLOCSPIdentifierHandle;

typedef TElXMLOCSPIdentifierHandle ElXMLOCSPIdentifierHandle;

typedef TElClassHandle TElXMLOCSPRefHandle;

typedef TElXMLOCSPRefHandle ElXMLOCSPRefHandle;

typedef TElClassHandle TElXMLOCSPRefsHandle;

typedef TElXMLOCSPRefsHandle ElXMLOCSPRefsHandle;

typedef TElClassHandle TElXMLOtherRefHandle;

typedef TElXMLOtherRefHandle ElXMLOtherRefHandle;

typedef TElXMLAnyTypeListHandle TElXMLOtherCertStatusRefsHandle;

typedef TElXMLAnyTypeListHandle ElXMLOtherCertStatusRefsHandle;

typedef TElClassHandle TElXMLCompleteRevocationRefsHandle;

typedef TElXMLCompleteRevocationRefsHandle ElXMLCompleteRevocationRefsHandle;

typedef TElClassHandle TElXMLCertificateValuesHandle;

typedef TElXMLCertificateValuesHandle ElXMLCertificateValuesHandle;

typedef TElClassHandle TElXMLEncapsulatedCRLValueHandle;

typedef TElXMLEncapsulatedCRLValueHandle ElXMLEncapsulatedCRLValueHandle;

typedef TElClassHandle TElXMLCRLValuesHandle;

typedef TElXMLCRLValuesHandle ElXMLCRLValuesHandle;

typedef TElClassHandle TElXMLEncapsulatedOCSPValueHandle;

typedef TElXMLEncapsulatedOCSPValueHandle ElXMLEncapsulatedOCSPValueHandle;

typedef TElClassHandle TElXMLOCSPValuesHandle;

typedef TElXMLOCSPValuesHandle ElXMLOCSPValuesHandle;

typedef TElXMLAnyTypeListHandle TElXMLOtherCertStatusValuesHandle;

typedef TElXMLAnyTypeListHandle ElXMLOtherCertStatusValuesHandle;

typedef TElClassHandle TElXMLRevocationValuesHandle;

typedef TElXMLRevocationValuesHandle ElXMLRevocationValuesHandle;

typedef TElClassHandle TElXMLTimeStampValidationDataHandle;

typedef TElXMLTimeStampValidationDataHandle ElXMLTimeStampValidationDataHandle;

typedef TElClassHandle TElXMLTimeStampValidationDataListHandle;

typedef TElXMLTimeStampValidationDataListHandle ElXMLTimeStampValidationDataListHandle;

typedef TElClassHandle TElXMLSignedDataObjectPropertiesHandle;

typedef TElXMLSignedDataObjectPropertiesHandle ElXMLSignedDataObjectPropertiesHandle;

typedef TElClassHandle TElXMLUnsignedDataObjectPropertyHandle;

typedef TElXMLUnsignedDataObjectPropertyHandle ElXMLUnsignedDataObjectPropertyHandle;

typedef TElXMLAnyTypeListHandle TElXMLUnsignedDataObjectPropertiesHandle;

typedef TElXMLAnyTypeListHandle ElXMLUnsignedDataObjectPropertiesHandle;

typedef TElClassHandle TElXMLSignedSignaturePropertiesHandle;

typedef TElXMLSignedSignaturePropertiesHandle ElXMLSignedSignaturePropertiesHandle;

typedef TElClassHandle TElXMLUnsignedSignaturePropertiesHandle;

typedef TElXMLUnsignedSignaturePropertiesHandle ElXMLUnsignedSignaturePropertiesHandle;

typedef TElClassHandle TElXMLSignedPropertiesHandle;

typedef TElXMLSignedPropertiesHandle ElXMLSignedPropertiesHandle;

typedef TElClassHandle TElXMLUnsignedPropertiesHandle;

typedef TElXMLUnsignedPropertiesHandle ElXMLUnsignedPropertiesHandle;

typedef TElClassHandle TElXMLQualifyingPropertiesHandle;

typedef TElXMLQualifyingPropertiesHandle ElXMLQualifyingPropertiesHandle;

typedef TElClassHandle TElXMLQualifyingPropertiesReferenceHandle;

typedef TElXMLQualifyingPropertiesReferenceHandle ElXMLQualifyingPropertiesReferenceHandle;

typedef TElClassHandle TElXMLQualifyingPropertiesReferenceListHandle;

typedef TElXMLQualifyingPropertiesReferenceListHandle ElXMLQualifyingPropertiesReferenceListHandle;

typedef uint8_t TSBXAdESVersionRaw;

typedef enum
{
	XAdES_v1_1_1 = 0,
	XAdES_v1_2_2 = 1,
	XAdES_v1_3_2 = 2,
	XAdES_v1_4_1 = 3
} TSBXAdESVersion;

typedef uint8_t TSBXAdESFormRaw;

typedef enum
{
	XAdES = 0,
	XAdES_BES = 1,
	XAdES_EPES = 2,
	XAdES_T = 3,
	XAdES_C = 4,
	XAdES_X = 5,
	XAdES_X_L = 6,
	XAdES_A = 7
} TSBXAdESForm;

typedef uint8_t TSBXAdESQualifierTypeRaw;

typedef enum
{
	xqtNone = 0,
	xqtOIDAsURN = 1,
	xqtOIDAsURI = 2
} TSBXAdESQualifierType;

typedef uint8_t TSBXAdESEncodingMethodRaw;

typedef enum
{
	xemDER = 0,
	xemCER = 1,
	xemBER = 2,
	xemPER = 3,
	xemXER = 4
} TSBXAdESEncodingMethod;

typedef uint8_t TSBXAdESResponderIDTypeRaw;

typedef enum
{
	xrtByName = 0,
	xrtByKey = 1
} TSBXAdESResponderIDType;

#ifdef SB_USE_CLASS_TELXMLADESELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLAdESElement_Assign(TElXMLAdESElementHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAdESElement_IsEmpty(TElXMLAdESElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAdESElement_get_XAdESVersion(TElXMLAdESElementHandle _Handle, TSBXAdESVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAdESElement_Create(TSBXAdESVersionRaw AVersion, TElXMLAdESElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAdESElement_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLAdESElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAdESElement_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLAdESElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLADESELEMENT */

#ifdef SB_USE_CLASS_TELXMLANYTYPE
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_Assign(TElXMLAnyTypeHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_Clear(TElXMLAnyTypeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_IsEmpty(TElXMLAnyTypeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_LoadFromXML(TElXMLAnyTypeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_SaveToXML(TElXMLAnyTypeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_get_Value(TElXMLAnyTypeHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_set_Value(TElXMLAnyTypeHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_Create(TSBXAdESVersionRaw AVersion, TElXMLAdESElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLAdESElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyType_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLAdESElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyTypeList_Assign(TElXMLAnyTypeListHandle _Handle, TElXMLAnyTypeListHandle Source, TSBXAdESVersionRaw AVersion);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyTypeList_Add(TElXMLAnyTypeListHandle _Handle, TElXMLAnyTypeHandle AItem, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyTypeList_Insert(TElXMLAnyTypeListHandle _Handle, int32_t Index, TElXMLAnyTypeHandle AItem);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyTypeList_Delete(TElXMLAnyTypeListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyTypeList_Clear(TElXMLAnyTypeListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyTypeList_get_Count(TElXMLAnyTypeListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyTypeList_get_Item(TElXMLAnyTypeListHandle _Handle, int32_t Index, TElXMLAnyTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAnyTypeList_Create(TElXMLAnyTypeListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_Assign(TElXMLObjectIdentifierHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_Clear(TElXMLObjectIdentifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_IsEmpty(TElXMLObjectIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_LoadFromXML(TElXMLObjectIdentifierHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_SaveToXML(TElXMLObjectIdentifierHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_get_Description(TElXMLObjectIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_set_Description(TElXMLObjectIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_get_DocumentationReferences(TElXMLObjectIdentifierHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_get_Identifier(TElXMLObjectIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_set_Identifier(TElXMLObjectIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_get_IdentifierQualifier(TElXMLObjectIdentifierHandle _Handle, TSBXAdESQualifierTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_set_IdentifierQualifier(TElXMLObjectIdentifierHandle _Handle, TSBXAdESQualifierTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_Create(TSBXAdESVersionRaw AVersion, TElXMLObjectIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLObjectIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectIdentifier_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLObjectIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_Assign(TElXMLEncapsulatedPKIDataHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_Clear(TElXMLEncapsulatedPKIDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_IsEmpty(TElXMLEncapsulatedPKIDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_LoadFromXML(TElXMLEncapsulatedPKIDataHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_SaveToXML(TElXMLEncapsulatedPKIDataHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_get_Data(TElXMLEncapsulatedPKIDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_set_Data(TElXMLEncapsulatedPKIDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_get_ID(TElXMLEncapsulatedPKIDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_set_ID(TElXMLEncapsulatedPKIDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_get_Encoding(TElXMLEncapsulatedPKIDataHandle _Handle, TSBXAdESEncodingMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_set_Encoding(TElXMLEncapsulatedPKIDataHandle _Handle, TSBXAdESEncodingMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_Create(TSBXAdESVersionRaw AVersion, TElXMLEncapsulatedPKIDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLEncapsulatedPKIDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIData_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLEncapsulatedPKIDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIDataList_Assign(TElXMLEncapsulatedPKIDataListHandle _Handle, TElXMLEncapsulatedPKIDataListHandle Source, TSBXAdESVersionRaw AVersion);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIDataList_Add(TElXMLEncapsulatedPKIDataListHandle _Handle, TElXMLEncapsulatedPKIDataHandle APKIData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIDataList_Insert(TElXMLEncapsulatedPKIDataListHandle _Handle, int32_t Index, TElXMLEncapsulatedPKIDataHandle APKIData);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIDataList_Delete(TElXMLEncapsulatedPKIDataListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIDataList_Clear(TElXMLEncapsulatedPKIDataListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIDataList_get_Count(TElXMLEncapsulatedPKIDataListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIDataList_get_PKIData(TElXMLEncapsulatedPKIDataListHandle _Handle, int32_t Index, TElXMLEncapsulatedPKIDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedPKIDataList_Create(TElXMLEncapsulatedPKIDataListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_Clear(TElXMLHashDataInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_IsEmpty(TElXMLHashDataInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_LoadFromXML(TElXMLHashDataInfoHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_SaveToXML(TElXMLHashDataInfoHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_GetHashData(TElXMLHashDataInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_get_TransformChain(TElXMLHashDataInfoHandle _Handle, TElXMLTransformChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_set_TransformChain(TElXMLHashDataInfoHandle _Handle, TElXMLTransformChainHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_get_URI(TElXMLHashDataInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_set_URI(TElXMLHashDataInfoHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_get_URIData(TElXMLHashDataInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_set_URIData(TElXMLHashDataInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_get_URINode(TElXMLHashDataInfoHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_set_URINode(TElXMLHashDataInfoHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_Create(TSBXAdESVersionRaw AVersion, TElXMLHashDataInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLHashDataInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfo_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLHashDataInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFOLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfoList_Add(TElXMLHashDataInfoListHandle _Handle, TElXMLHashDataInfoHandle AHashDataInfo, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfoList_Insert(TElXMLHashDataInfoListHandle _Handle, int32_t Index, TElXMLHashDataInfoHandle AHashDataInfo);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfoList_Delete(TElXMLHashDataInfoListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfoList_Clear(TElXMLHashDataInfoListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfoList_get_Count(TElXMLHashDataInfoListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfoList_get_HashDataInfo(TElXMLHashDataInfoListHandle _Handle, int32_t Index, TElXMLHashDataInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLHashDataInfoList_Create(TElXMLHashDataInfoListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFOLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestamp_GetTimestampInfo(TElXMLCustomTimestampHandle _Handle, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestamp_CheckTimestamp(TElXMLCustomTimestampHandle _Handle, TElClientTSPInfoHandle Info, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestamp_CheckTimestamp_1(TElXMLCustomTimestampHandle _Handle, TElClientTSPInfoHandle Info, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestamp_Timestamp(TElXMLCustomTimestampHandle _Handle, TElCustomTSPClientHandle TSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestamp_Timestamp_1(TElXMLCustomTimestampHandle _Handle, TElCustomTSPClientHandle TSPClient, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestamp_Create(TSBXAdESVersionRaw AVersion, TElXMLAdESElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestamp_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLAdESElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestamp_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLAdESElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestampList_Add(TElXMLCustomTimestampListHandle _Handle, TElXMLCustomTimestampHandle ATimestamp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestampList_Insert(TElXMLCustomTimestampListHandle _Handle, int32_t Index, TElXMLCustomTimestampHandle ATimestamp);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestampList_Delete(TElXMLCustomTimestampListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestampList_Clear(TElXMLCustomTimestampListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestampList_get_Count(TElXMLCustomTimestampListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestampList_get_Timestamp(TElXMLCustomTimestampListHandle _Handle, int32_t Index, TElXMLCustomTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomTimestampList_Create(TElXMLCustomTimestampListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_Clear(TElXMLTimestampHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_IsEmpty(TElXMLTimestampHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_LoadFromXML(TElXMLTimestampHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_SaveToXML(TElXMLTimestampHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_GetTimestampInfo(TElXMLTimestampHandle _Handle, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_CheckTimestamp(TElXMLTimestampHandle _Handle, TElClientTSPInfoHandle Info, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_Timestamp(TElXMLTimestampHandle _Handle, TElCustomTSPClientHandle TSPClient, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_get_HashDataInfos(TElXMLTimestampHandle _Handle, TElXMLHashDataInfoListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_get_EncapsulatedTimestamp(TElXMLTimestampHandle _Handle, TElXMLEncapsulatedPKIDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_set_EncapsulatedTimestamp(TElXMLTimestampHandle _Handle, TElXMLEncapsulatedPKIDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_get_XMLTimestamp(TElXMLTimestampHandle _Handle, TElXMLAnyTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_set_XMLTimestamp(TElXMLTimestampHandle _Handle, TElXMLAnyTypeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_Create(TSBXAdESVersionRaw AVersion, TElXMLTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLTimestampHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestampList_Add(TElXMLTimestampListHandle _Handle, TElXMLTimestampHandle ATimestamp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestampList_Insert(TElXMLTimestampListHandle _Handle, int32_t Index, TElXMLTimestampHandle ATimestamp);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestampList_get_Timestamp_TElXMLTimestamp(TElXMLTimestampListHandle _Handle, int32_t Index, TElXMLTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestampList_Create(TElXMLCustomTimestampListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLINCLUDE
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_Clear(TElXMLIncludeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_IsEmpty(TElXMLIncludeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_LoadFromXML(TElXMLIncludeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_SaveToXML(TElXMLIncludeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_ProcessIncludeData(TElXMLIncludeHandle _Handle, TElXMLCanonicalizationMethodRaw CanonicalizationMethod, TElHashFunctionHandle HashFunc);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_get_ReferencedData(TElXMLIncludeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_set_ReferencedData(TElXMLIncludeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_get_URI(TElXMLIncludeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_set_URI(TElXMLIncludeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_get_URIData(TElXMLIncludeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_set_URIData(TElXMLIncludeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_get_URINode(TElXMLIncludeHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_set_URINode(TElXMLIncludeHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_get_URIReference(TElXMLIncludeHandle _Handle, TElXMLReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_set_URIReference(TElXMLIncludeHandle _Handle, TElXMLReferenceHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_Create(TSBXAdESVersionRaw AVersion, TElXMLIncludeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLIncludeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLInclude_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLIncludeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLIncludeList_Add(TElXMLIncludeListHandle _Handle, TElXMLIncludeHandle AInclude, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIncludeList_Insert(TElXMLIncludeListHandle _Handle, int32_t Index, TElXMLIncludeHandle AInclude);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIncludeList_Delete(TElXMLIncludeListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIncludeList_Clear(TElXMLIncludeListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIncludeList_get_Count(TElXMLIncludeListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIncludeList_get_Includes(TElXMLIncludeListHandle _Handle, int32_t Index, TElXMLIncludeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIncludeList_Create(TElXMLIncludeListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_Clear(TElXMLTimestamp_v1_2_2Handle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_IsEmpty(TElXMLTimestamp_v1_2_2Handle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_LoadFromXML(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_SaveToXML(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_GetTimestampInfo(TElXMLTimestamp_v1_2_2Handle _Handle, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_CheckTimestamp(TElXMLTimestamp_v1_2_2Handle _Handle, TElClientTSPInfoHandle Info, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_Timestamp(TElXMLTimestamp_v1_2_2Handle _Handle, TElCustomTSPClientHandle TSPClient, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_get_ID(TElXMLTimestamp_v1_2_2Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_set_ID(TElXMLTimestamp_v1_2_2Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_get_CanonicalizationMethod(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_set_CanonicalizationMethod(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLCanonicalizationMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_get_EncapsulatedTimestamp(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLEncapsulatedPKIDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_set_EncapsulatedTimestamp(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLEncapsulatedPKIDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_get_XMLTimestamp(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLAnyTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_set_XMLTimestamp(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLAnyTypeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_get_Includes(TElXMLTimestamp_v1_2_2Handle _Handle, TElXMLIncludeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_Create(TSBXAdESVersionRaw AVersion, TElXMLTimestamp_v1_2_2Handle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLTimestamp_v1_2_2Handle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestamp_v1_2_2_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLTimestamp_v1_2_2Handle * OutResult);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPLIST_V1_2_2
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestampList_v1_2_2_Add(TElXMLTimestampList_v1_2_2Handle _Handle, TElXMLTimestamp_v1_2_2Handle ATimestamp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestampList_v1_2_2_Insert(TElXMLTimestampList_v1_2_2Handle _Handle, int32_t Index, TElXMLTimestamp_v1_2_2Handle ATimestamp);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestampList_v1_2_2_get_Timestamp_TElXMLTimestamp_v1_2_2(TElXMLTimestampList_v1_2_2Handle _Handle, int32_t Index, TElXMLTimestamp_v1_2_2Handle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimestampList_v1_2_2_Create(TElXMLCustomTimestampListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPLIST_V1_2_2 */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClientList_Add(TElCustomTSPClientListHandle _Handle, TElCustomTSPClientHandle ATSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClientList_Insert(TElCustomTSPClientListHandle _Handle, int32_t Index, TElCustomTSPClientHandle ATSPClient);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClientList_Delete(TElCustomTSPClientListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClientList_Clear(TElCustomTSPClientListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClientList_get_Count(TElCustomTSPClientListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClientList_get_OwnItems(TElCustomTSPClientListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClientList_get_TSPClients(TElCustomTSPClientListHandle _Handle, int32_t Index, TElCustomTSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClientList_Create(int8_t AOwnItems, TElCustomTSPClientListHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_Clear(TElXMLGenericTimestampHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_IsEmpty(TElXMLGenericTimestampHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_LoadFromXML(TElXMLGenericTimestampHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_SaveToXML(TElXMLGenericTimestampHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_GetTimestampInfo(TElXMLGenericTimestampHandle _Handle, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_GetTimestampInfo_1(TElXMLGenericTimestampHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_AddTimestampData(TElXMLGenericTimestampHandle _Handle, const uint8_t pData[], int32_t szData);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_AddTimestampData_1(TElXMLGenericTimestampHandle _Handle, const TElXMLDOMNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_AddTimestampData_2(TElXMLGenericTimestampHandle _Handle, const TElXMLReferenceHandle Ref);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_StartTimestampCheck(TElXMLGenericTimestampHandle _Handle, TElClientTSPInfoHandle Info);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_FinishTimestampCheck(TElXMLGenericTimestampHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_CheckTimestamp(TElXMLGenericTimestampHandle _Handle, TElClientTSPInfoHandle Info, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_Timestamp(TElXMLGenericTimestampHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_Timestamp_1(TElXMLGenericTimestampHandle _Handle, TElCustomTSPClientHandle TSPClient, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_get_TimestampInfoCount(TElXMLGenericTimestampHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_get_TSPClients(TElXMLGenericTimestampHandle _Handle, TElCustomTSPClientListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_get_CryptoProviderManager(TElXMLGenericTimestampHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_set_CryptoProviderManager(TElXMLGenericTimestampHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_get_ID(TElXMLGenericTimestampHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_set_ID(TElXMLGenericTimestampHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_get_CanonicalizationMethod(TElXMLGenericTimestampHandle _Handle, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_set_CanonicalizationMethod(TElXMLGenericTimestampHandle _Handle, TElXMLCanonicalizationMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_get_EncapsulatedTimestamps(TElXMLGenericTimestampHandle _Handle, TElXMLEncapsulatedPKIDataListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_get_XMLTimestamps(TElXMLGenericTimestampHandle _Handle, TElXMLAnyTypeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_get_Includes(TElXMLGenericTimestampHandle _Handle, TElXMLIncludeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_Create(TSBXAdESVersionRaw AVersion, TElXMLGenericTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLGenericTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestamp_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLGenericTimestampHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMPLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestampList_Add(TElXMLGenericTimestampListHandle _Handle, TElXMLGenericTimestampHandle ATimestamp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestampList_Insert(TElXMLGenericTimestampListHandle _Handle, int32_t Index, TElXMLGenericTimestampHandle ATimestamp);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestampList_get_Timestamp_TElXMLGenericTimestamp(TElXMLGenericTimestampListHandle _Handle, int32_t Index, TElXMLGenericTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGenericTimestampList_Create(TElXMLCustomTimestampListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_Assign(TElXMLDigestAlgAndValueHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_Clear(TElXMLDigestAlgAndValueHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_IsEmpty(TElXMLDigestAlgAndValueHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_LoadFromXML(TElXMLDigestAlgAndValueHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_SaveToXML(TElXMLDigestAlgAndValueHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_get_DigestMethod(TElXMLDigestAlgAndValueHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_set_DigestMethod(TElXMLDigestAlgAndValueHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_get_DigestValue(TElXMLDigestAlgAndValueHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_set_DigestValue(TElXMLDigestAlgAndValueHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_Create(TSBXAdESVersionRaw AVersion, TElXMLDigestAlgAndValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLDigestAlgAndValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDigestAlgAndValue_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLDigestAlgAndValueHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLCERTID
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_Clear(TElXMLCertIDHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_IsEmpty(TElXMLCertIDHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_LoadFromXML(TElXMLCertIDHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_SaveToXML(TElXMLCertIDHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_IsMatch(TElXMLCertIDHandle _Handle, TElX509CertificateHandle Cert, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_IsMatch_1(TElXMLCertIDHandle _Handle, TElX509CertificateHandle Cert, int8_t LiberalMode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_get_CertDigest(TElXMLCertIDHandle _Handle, TElXMLDigestAlgAndValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_set_CertDigest(TElXMLCertIDHandle _Handle, TElXMLDigestAlgAndValueHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_get_IssuerSerial(TElXMLCertIDHandle _Handle, TElXMLIssuerSerialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_set_IssuerSerial(TElXMLCertIDHandle _Handle, TElXMLIssuerSerialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_get_URI(TElXMLCertIDHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_set_URI(TElXMLCertIDHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_Create(TSBXAdESVersionRaw AVersion, TElXMLCertIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCertIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertID_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCertIDHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCERTID */

#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_HasCertificate(TElXMLCertIDListHandle _Handle, TElX509CertificateHandle ACertificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_AddCertificate(TElXMLCertIDListHandle _Handle, TElX509CertificateHandle ACertificate, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_AddCertificate_1(TElXMLCertIDListHandle _Handle, TElX509CertificateHandle ACertificate, TElXMLDigestMethodRaw DigestMethod, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_AddCertificate_2(TElXMLCertIDListHandle _Handle, TElX509CertificateHandle ACertificate, TElXMLDigestMethodRaw DigestMethod, int8_t HexSerialNumber, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_Add(TElXMLCertIDListHandle _Handle, TElXMLCertIDHandle ACertID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_Insert(TElXMLCertIDListHandle _Handle, int32_t Index, TElXMLCertIDHandle ACertID);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_Delete(TElXMLCertIDListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_Clear(TElXMLCertIDListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_get_Count(TElXMLCertIDListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_get_CertIDs(TElXMLCertIDListHandle _Handle, int32_t Index, TElXMLCertIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertIDList_Create(TElXMLCertIDListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */

#ifdef SB_USE_CLASS_TELXMLNOTICEREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_Clear(TElXMLNoticeReferenceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_IsEmpty(TElXMLNoticeReferenceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_LoadFromXML(TElXMLNoticeReferenceHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_SaveToXML(TElXMLNoticeReferenceHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_get_Organization(TElXMLNoticeReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_set_Organization(TElXMLNoticeReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_get_NoticeNumbers(TElXMLNoticeReferenceHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_set_NoticeNumbers(TElXMLNoticeReferenceHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_Create(TSBXAdESVersionRaw AVersion, TElXMLAdESElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLAdESElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNoticeReference_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLAdESElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLNOTICEREFERENCE */

#ifdef SB_USE_CLASS_TELXMLSPUSERNOTICE
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_Clear(TElXMLSPUserNoticeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_IsEmpty(TElXMLSPUserNoticeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_LoadFromXML(TElXMLSPUserNoticeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_SaveToXML(TElXMLSPUserNoticeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_get_NoticeRef(TElXMLSPUserNoticeHandle _Handle, TElXMLNoticeReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_set_NoticeRef(TElXMLSPUserNoticeHandle _Handle, TElXMLNoticeReferenceHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_get_ExplicitTex(TElXMLSPUserNoticeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_set_ExplicitTex(TElXMLSPUserNoticeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_Create(TSBXAdESVersionRaw AVersion, TElXMLSPUserNoticeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSPUserNoticeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPUserNotice_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSPUserNoticeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSPUSERNOTICE */

#ifdef SB_USE_CLASS_TELXMLSPURI
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_Clear(TElXMLSPURIHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_IsEmpty(TElXMLSPURIHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_LoadFromXML(TElXMLSPURIHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_SaveToXML(TElXMLSPURIHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_get_URI(TElXMLSPURIHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_set_URI(TElXMLSPURIHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_Create(TSBXAdESVersionRaw AVersion, TElXMLSPURIHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSPURIHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSPURI_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSPURIHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSPURI */

#ifdef SB_USE_CLASS_TELXMLSIGPOLICYQUALIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigPolicyQualifier_Create(TSBXAdESVersionRaw AVersion, TElXMLSigPolicyQualifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigPolicyQualifier_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSigPolicyQualifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigPolicyQualifier_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSigPolicyQualifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_Assign(TElXMLSignaturePolicyIdHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_Clear(TElXMLSignaturePolicyIdHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_IsEmpty(TElXMLSignaturePolicyIdHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_LoadFromXML(TElXMLSignaturePolicyIdHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_SaveToXML(TElXMLSignaturePolicyIdHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_get_SigPolicyId(TElXMLSignaturePolicyIdHandle _Handle, TElXMLObjectIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_get_SigPolicyHash(TElXMLSignaturePolicyIdHandle _Handle, TElXMLDigestAlgAndValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_get_SigPolicyQualifiers(TElXMLSignaturePolicyIdHandle _Handle, TElXMLAnyTypeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_get_TransformChain(TElXMLSignaturePolicyIdHandle _Handle, TElXMLTransformChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_Create(TSBXAdESVersionRaw AVersion, TElXMLSignaturePolicyIdHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSignaturePolicyIdHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyId_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSignaturePolicyIdHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_Assign(TElXMLSignaturePolicyIdentifierHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_Clear(TElXMLSignaturePolicyIdentifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_IsEmpty(TElXMLSignaturePolicyIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_LoadFromXML(TElXMLSignaturePolicyIdentifierHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_SaveToXML(TElXMLSignaturePolicyIdentifierHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_get_SignaturePolicyId(TElXMLSignaturePolicyIdentifierHandle _Handle, TElXMLSignaturePolicyIdHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_set_SignaturePolicyId(TElXMLSignaturePolicyIdentifierHandle _Handle, TElXMLSignaturePolicyIdHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_get_SignaturePolicyImplied(TElXMLSignaturePolicyIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_set_SignaturePolicyImplied(TElXMLSignaturePolicyIdentifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_Create(TSBXAdESVersionRaw AVersion, TElXMLSignaturePolicyIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSignaturePolicyIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignaturePolicyIdentifier_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSignaturePolicyIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_Clear(TElXMLCounterSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_IsEmpty(TElXMLCounterSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_LoadFromXML(TElXMLCounterSignatureHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_SaveToXML(TElXMLCounterSignatureHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_get_Signature(TElXMLCounterSignatureHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_set_Signature(TElXMLCounterSignatureHandle _Handle, TElXMLDOMElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_Create(TSBXAdESVersionRaw AVersion, TElXMLCounterSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCounterSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignature_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCounterSignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignatureList_Add(TElXMLCounterSignatureListHandle _Handle, TElXMLCounterSignatureHandle ACounterSignature, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignatureList_Insert(TElXMLCounterSignatureListHandle _Handle, int32_t Index, TElXMLCounterSignatureHandle ACounterSignature);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignatureList_Delete(TElXMLCounterSignatureListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignatureList_Clear(TElXMLCounterSignatureListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignatureList_get_Count(TElXMLCounterSignatureListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignatureList_get_CounterSignature(TElXMLCounterSignatureListHandle _Handle, int32_t Index, TElXMLCounterSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCounterSignatureList_Create(TElXMLCounterSignatureListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_Clear(TElXMLDataObjectFormatHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_IsEmpty(TElXMLDataObjectFormatHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_LoadFromXML(TElXMLDataObjectFormatHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_SaveToXML(TElXMLDataObjectFormatHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_get_Description(TElXMLDataObjectFormatHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_set_Description(TElXMLDataObjectFormatHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_get_ObjectIdentifier(TElXMLDataObjectFormatHandle _Handle, TElXMLObjectIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_set_ObjectIdentifier(TElXMLDataObjectFormatHandle _Handle, TElXMLObjectIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_get_MimeType(TElXMLDataObjectFormatHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_set_MimeType(TElXMLDataObjectFormatHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_get_Encoding(TElXMLDataObjectFormatHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_set_Encoding(TElXMLDataObjectFormatHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_get_ObjectReference(TElXMLDataObjectFormatHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_set_ObjectReference(TElXMLDataObjectFormatHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_Create(TSBXAdESVersionRaw AVersion, TElXMLDataObjectFormatHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLDataObjectFormatHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormat_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLDataObjectFormatHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormatList_Add(TElXMLDataObjectFormatListHandle _Handle, TElXMLDataObjectFormatHandle ADataObjectFormat, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormatList_Insert(TElXMLDataObjectFormatListHandle _Handle, int32_t Index, TElXMLDataObjectFormatHandle ADataObjectFormat);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormatList_Delete(TElXMLDataObjectFormatListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormatList_Clear(TElXMLDataObjectFormatListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormatList_get_Count(TElXMLDataObjectFormatListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormatList_get_DataObjectFormat(TElXMLDataObjectFormatListHandle _Handle, int32_t Index, TElXMLDataObjectFormatHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDataObjectFormatList_Create(TElXMLDataObjectFormatListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEQUALIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeQualifier_Create(TSBXAdESVersionRaw AVersion, TElXMLCommitmentTypeQualifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeQualifier_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCommitmentTypeQualifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeQualifier_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCommitmentTypeQualifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEQUALIFIER */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_Clear(TElXMLCommitmentTypeIndicationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_IsEmpty(TElXMLCommitmentTypeIndicationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_LoadFromXML(TElXMLCommitmentTypeIndicationHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_SaveToXML(TElXMLCommitmentTypeIndicationHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_get_AllSignedDataObjects(TElXMLCommitmentTypeIndicationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_set_AllSignedDataObjects(TElXMLCommitmentTypeIndicationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_get_CommitmentTypeId(TElXMLCommitmentTypeIndicationHandle _Handle, TElXMLObjectIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_get_CommitmentTypeQualifiers(TElXMLCommitmentTypeIndicationHandle _Handle, TElXMLAnyTypeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_get_ObjectReference(TElXMLCommitmentTypeIndicationHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_Create(TSBXAdESVersionRaw AVersion, TElXMLCommitmentTypeIndicationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCommitmentTypeIndicationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndication_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCommitmentTypeIndicationHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndicationList_Add(TElXMLCommitmentTypeIndicationListHandle _Handle, TElXMLCommitmentTypeIndicationHandle ACommitmentTypeIndication, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndicationList_Insert(TElXMLCommitmentTypeIndicationListHandle _Handle, int32_t Index, TElXMLCommitmentTypeIndicationHandle ACommitmentTypeIndication);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndicationList_Delete(TElXMLCommitmentTypeIndicationListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndicationList_Clear(TElXMLCommitmentTypeIndicationListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndicationList_get_Count(TElXMLCommitmentTypeIndicationListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndicationList_get_CommitmentTypeIndication(TElXMLCommitmentTypeIndicationListHandle _Handle, int32_t Index, TElXMLCommitmentTypeIndicationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCommitmentTypeIndicationList_Create(TElXMLCommitmentTypeIndicationListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_Assign(TElXMLSignatureProductionPlaceHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_Clear(TElXMLSignatureProductionPlaceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_IsEmpty(TElXMLSignatureProductionPlaceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_LoadFromXML(TElXMLSignatureProductionPlaceHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_SaveToXML(TElXMLSignatureProductionPlaceHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_get_City(TElXMLSignatureProductionPlaceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_set_City(TElXMLSignatureProductionPlaceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_get_StateOrProvince(TElXMLSignatureProductionPlaceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_set_StateOrProvince(TElXMLSignatureProductionPlaceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_get_PostalCode(TElXMLSignatureProductionPlaceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_set_PostalCode(TElXMLSignatureProductionPlaceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_get_CountryName(TElXMLSignatureProductionPlaceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_set_CountryName(TElXMLSignatureProductionPlaceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_Create(TSBXAdESVersionRaw AVersion, TElXMLSignatureProductionPlaceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSignatureProductionPlaceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProductionPlace_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSignatureProductionPlaceHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedX509Certificates_AddCertificate(TElXMLEncapsulatedX509CertificatesHandle _Handle, TElX509CertificateHandle ACert, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedX509Certificates_Clear(TElXMLEncapsulatedX509CertificatesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedX509Certificates_get_Certificates(TElXMLEncapsulatedX509CertificatesHandle _Handle, int32_t Index, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedX509Certificates_Create(TElXMLEncapsulatedX509CertificatesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES */

#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLE
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertifiedRole_Create(TSBXAdESVersionRaw AVersion, TElXMLCertifiedRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertifiedRole_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCertifiedRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertifiedRole_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCertifiedRoleHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLE */

#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertifiedRolesList_Create(TElXMLEncapsulatedX509CertificatesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST */

#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLE
SB_IMPORT uint32_t SB_APIENTRY TElXMLClaimedRole_Create(TSBXAdESVersionRaw AVersion, TElXMLClaimedRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLClaimedRole_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLClaimedRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLClaimedRole_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLClaimedRoleHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLE */

#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLESLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLClaimedRolesList_AddText(TElXMLClaimedRolesListHandle _Handle, TSBXAdESVersionRaw AVersion, TElXMLDOMDocumentHandle OwnerDocument, const sb_char16_t * pcText, int32_t szText, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLClaimedRolesList_Create(TElXMLAnyTypeListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLESLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_Assign(TElXMLSignerRoleHandle _Handle, TElXMLAdESElementHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_Clear(TElXMLSignerRoleHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_IsEmpty(TElXMLSignerRoleHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_LoadFromXML(TElXMLSignerRoleHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_SaveToXML(TElXMLSignerRoleHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_get_ClaimedRoles(TElXMLSignerRoleHandle _Handle, TElXMLClaimedRolesListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_get_CertifiedRoles(TElXMLSignerRoleHandle _Handle, TElXMLCertifiedRolesListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_Create(TSBXAdESVersionRaw AVersion, TElXMLSignerRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSignerRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignerRole_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSignerRoleHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_Clear(TElXMLCompleteCertificateRefsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_IsEmpty(TElXMLCompleteCertificateRefsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_LoadFromXML(TElXMLCompleteCertificateRefsHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_SaveToXML(TElXMLCompleteCertificateRefsHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_get_ID(TElXMLCompleteCertificateRefsHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_set_ID(TElXMLCompleteCertificateRefsHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_get_CertRefs(TElXMLCompleteCertificateRefsHandle _Handle, TElXMLCertIDListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_Create(TSBXAdESVersionRaw AVersion, TElXMLCompleteCertificateRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCompleteCertificateRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteCertificateRefs_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCompleteCertificateRefsHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELXMLCRLIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_Clear(TElXMLCRLIdentifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_IsEmpty(TElXMLCRLIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_LoadFromXML(TElXMLCRLIdentifierHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_SaveToXML(TElXMLCRLIdentifierHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_get_Issuer(TElXMLCRLIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_set_Issuer(TElXMLCRLIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_get_IssueTime(TElXMLCRLIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_set_IssueTime(TElXMLCRLIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_get_IssueTimeUTC(TElXMLCRLIdentifierHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_set_IssueTimeUTC(TElXMLCRLIdentifierHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_get_Number(TElXMLCRLIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_set_Number(TElXMLCRLIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_get_URI(TElXMLCRLIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_set_URI(TElXMLCRLIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_Create(TSBXAdESVersionRaw AVersion, TElXMLCRLIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCRLIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLIdentifier_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCRLIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCRLIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLCRLREF
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_Clear(TElXMLCRLRefHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_IsEmpty(TElXMLCRLRefHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_IsMatch(TElXMLCRLRefHandle _Handle, TElCertificateRevocationListHandle ACRL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_LoadFromXML(TElXMLCRLRefHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_SaveToXML(TElXMLCRLRefHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_get_DigestAlgAndValue(TElXMLCRLRefHandle _Handle, TElXMLDigestAlgAndValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_get_CRLIdentifier(TElXMLCRLRefHandle _Handle, TElXMLCRLIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_set_CRLIdentifier(TElXMLCRLRefHandle _Handle, TElXMLCRLIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_Create(TSBXAdESVersionRaw AVersion, TElXMLCRLRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCRLRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRef_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCRLRefHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCRLREF */

#ifdef SB_USE_CLASS_TELXMLCRLREFS
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_AddCRL(TElXMLCRLRefsHandle _Handle, TElCertificateRevocationListHandle ACRL, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_AddCRL_1(TElXMLCRLRefsHandle _Handle, TElCertificateRevocationListHandle ACRL, TElXMLDigestMethodRaw DigestMethod, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_Add(TElXMLCRLRefsHandle _Handle, TElXMLCRLRefHandle ACRLRef, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_Insert(TElXMLCRLRefsHandle _Handle, int32_t Index, TElXMLCRLRefHandle ACRLRef);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_Delete(TElXMLCRLRefsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_Clear(TElXMLCRLRefsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_get_Count(TElXMLCRLRefsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_get_CRLRef(TElXMLCRLRefsHandle _Handle, int32_t Index, TElXMLCRLRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLRefs_Create(TElXMLCRLRefsHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCRLREFS */

#ifdef SB_USE_CLASS_TELXMLOCSPIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_Clear(TElXMLOCSPIdentifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_IsEmpty(TElXMLOCSPIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_LoadFromXML(TElXMLOCSPIdentifierHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_SaveToXML(TElXMLOCSPIdentifierHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_get_ResponderID(TElXMLOCSPIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_set_ResponderID(TElXMLOCSPIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_get_ProducedAt(TElXMLOCSPIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_set_ProducedAt(TElXMLOCSPIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_get_ProducedAtUTC(TElXMLOCSPIdentifierHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_set_ProducedAtUTC(TElXMLOCSPIdentifierHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_get_URI(TElXMLOCSPIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_set_URI(TElXMLOCSPIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_get_ResponderIDType(TElXMLOCSPIdentifierHandle _Handle, TSBXAdESResponderIDTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_set_ResponderIDType(TElXMLOCSPIdentifierHandle _Handle, TSBXAdESResponderIDTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_Create(TSBXAdESVersionRaw AVersion, TElXMLOCSPIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLOCSPIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPIdentifier_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLOCSPIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLOCSPIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLOCSPREF
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_Clear(TElXMLOCSPRefHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_IsEmpty(TElXMLOCSPRefHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_LoadFromXML(TElXMLOCSPRefHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_SaveToXML(TElXMLOCSPRefHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_IsMatch(TElXMLOCSPRefHandle _Handle, TElOCSPResponseHandle OCSPResponse, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_get_DigestAlgAndValue(TElXMLOCSPRefHandle _Handle, TElXMLDigestAlgAndValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_set_DigestAlgAndValue(TElXMLOCSPRefHandle _Handle, TElXMLDigestAlgAndValueHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_get_OCSPIdentifier(TElXMLOCSPRefHandle _Handle, TElXMLOCSPIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_Create(TSBXAdESVersionRaw AVersion, TElXMLOCSPRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLOCSPRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRef_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLOCSPRefHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

#ifdef SB_USE_CLASS_TELXMLOCSPREFS
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_AddOCSP(TElXMLOCSPRefsHandle _Handle, TElOCSPResponseHandle OCSPResponse, int8_t ByKey, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_AddOCSP_1(TElXMLOCSPRefsHandle _Handle, TElOCSPResponseHandle OCSPResponse, int8_t ByKey, TElXMLDigestMethodRaw DigestMethod, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_Add(TElXMLOCSPRefsHandle _Handle, TElXMLOCSPRefHandle AOCSPRef, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_Insert(TElXMLOCSPRefsHandle _Handle, int32_t Index, TElXMLOCSPRefHandle AOCSPRef);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_Delete(TElXMLOCSPRefsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_Clear(TElXMLOCSPRefsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_get_Count(TElXMLOCSPRefsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_get_OCSPRef(TElXMLOCSPRefsHandle _Handle, int32_t Index, TElXMLOCSPRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPRefs_Create(TElXMLOCSPRefsHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLOCSPREFS */

#ifdef SB_USE_CLASS_TELXMLOTHERREF
SB_IMPORT uint32_t SB_APIENTRY TElXMLOtherRef_Create(TSBXAdESVersionRaw AVersion, TElXMLOtherRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOtherRef_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLOtherRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOtherRef_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLOtherRefHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLOTHERREF */

#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_Clear(TElXMLCompleteRevocationRefsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_IsEmpty(TElXMLCompleteRevocationRefsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_LoadFromXML(TElXMLCompleteRevocationRefsHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_SaveToXML(TElXMLCompleteRevocationRefsHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_get_ID(TElXMLCompleteRevocationRefsHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_set_ID(TElXMLCompleteRevocationRefsHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_get_CRLRefs(TElXMLCompleteRevocationRefsHandle _Handle, TElXMLCRLRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_get_OCSPRefs(TElXMLCompleteRevocationRefsHandle _Handle, TElXMLOCSPRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_get_OtherRefs(TElXMLCompleteRevocationRefsHandle _Handle, TElXMLAnyTypeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_Create(TSBXAdESVersionRaw AVersion, TElXMLCompleteRevocationRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCompleteRevocationRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCompleteRevocationRefs_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCompleteRevocationRefsHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_Clear(TElXMLCertificateValuesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_IsEmpty(TElXMLCertificateValuesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_LoadFromXML(TElXMLCertificateValuesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_SaveToXML(TElXMLCertificateValuesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_get_ID(TElXMLCertificateValuesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_set_ID(TElXMLCertificateValuesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_get_EncapsulatedX509Certificates(TElXMLCertificateValuesHandle _Handle, TElXMLEncapsulatedX509CertificatesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_get_OtherCertificates(TElXMLCertificateValuesHandle _Handle, TElXMLAnyTypeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_Create(TSBXAdESVersionRaw AVersion, TElXMLCertificateValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLCertificateValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCertificateValues_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLCertificateValuesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDCRLVALUE
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedCRLValue_Create(TSBXAdESVersionRaw AVersion, TElXMLEncapsulatedCRLValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedCRLValue_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLEncapsulatedCRLValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedCRLValue_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLEncapsulatedCRLValueHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDCRLVALUE */

#ifdef SB_USE_CLASS_TELXMLCRLVALUES
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLValues_AddCRL(TElXMLCRLValuesHandle _Handle, TElCertificateRevocationListHandle ACRL, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLValues_Clear(TElXMLCRLValuesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLValues_get_CRLs(TElXMLCRLValuesHandle _Handle, int32_t Index, TElCertificateRevocationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCRLValues_Create(TElXMLCRLValuesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCRLVALUES */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDOCSPVALUE
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedOCSPValue_Create(TSBXAdESVersionRaw AVersion, TElXMLEncapsulatedOCSPValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedOCSPValue_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLEncapsulatedOCSPValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncapsulatedOCSPValue_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLEncapsulatedOCSPValueHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDOCSPVALUE */

#ifdef SB_USE_CLASS_TELXMLOCSPVALUES
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPValues_AddOCSPResponse(TElXMLOCSPValuesHandle _Handle, TElOCSPResponseHandle AOCSPResponse, TSBXAdESVersionRaw AXAdESVersion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPValues_Clear(TElXMLOCSPValuesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPValues_get_OCSPResponses(TElXMLOCSPValuesHandle _Handle, int32_t Index, TElOCSPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLOCSPValues_Create(TElXMLOCSPValuesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLOCSPVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_Clear(TElXMLRevocationValuesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_IsEmpty(TElXMLRevocationValuesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_LoadFromXML(TElXMLRevocationValuesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_SaveToXML(TElXMLRevocationValuesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_get_ID(TElXMLRevocationValuesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_set_ID(TElXMLRevocationValuesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_get_CRLValues(TElXMLRevocationValuesHandle _Handle, TElXMLCRLValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_get_OCSPValues(TElXMLRevocationValuesHandle _Handle, TElXMLOCSPValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_get_OtherValues(TElXMLRevocationValuesHandle _Handle, TElXMLAnyTypeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_Create(TSBXAdESVersionRaw AVersion, TElXMLRevocationValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLRevocationValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRevocationValues_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLRevocationValuesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_Clear(TElXMLTimeStampValidationDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_IsEmpty(TElXMLTimeStampValidationDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_LoadFromXML(TElXMLTimeStampValidationDataHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_SaveToXML(TElXMLTimeStampValidationDataHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_get_ID(TElXMLTimeStampValidationDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_set_ID(TElXMLTimeStampValidationDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_get_URI(TElXMLTimeStampValidationDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_set_URI(TElXMLTimeStampValidationDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_get_CertificateValues(TElXMLTimeStampValidationDataHandle _Handle, TElXMLCertificateValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_set_CertificateValues(TElXMLTimeStampValidationDataHandle _Handle, TElXMLCertificateValuesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_get_RevocationValues(TElXMLTimeStampValidationDataHandle _Handle, TElXMLRevocationValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_set_RevocationValues(TElXMLTimeStampValidationDataHandle _Handle, TElXMLRevocationValuesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_Create(TSBXAdESVersionRaw AVersion, TElXMLTimeStampValidationDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLTimeStampValidationDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationData_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLTimeStampValidationDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationDataList_Add(TElXMLTimeStampValidationDataListHandle _Handle, TElXMLTimeStampValidationDataHandle ATSPValidationData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationDataList_Insert(TElXMLTimeStampValidationDataListHandle _Handle, int32_t Index, TElXMLTimeStampValidationDataHandle ATSPValidationData);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationDataList_Delete(TElXMLTimeStampValidationDataListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationDataList_Clear(TElXMLTimeStampValidationDataListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationDataList_get_Count(TElXMLTimeStampValidationDataListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationDataList_get_TimeStampValidationData(TElXMLTimeStampValidationDataListHandle _Handle, int32_t Index, TElXMLTimeStampValidationDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLTimeStampValidationDataList_Create(TElXMLTimeStampValidationDataListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */

#ifdef SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_Clear(TElXMLSignedDataObjectPropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_IsEmpty(TElXMLSignedDataObjectPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_LoadFromXML(TElXMLSignedDataObjectPropertiesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_SaveToXML(TElXMLSignedDataObjectPropertiesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_get_DataObjectFormats(TElXMLSignedDataObjectPropertiesHandle _Handle, TElXMLDataObjectFormatListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_get_CommitmentTypeIndications(TElXMLSignedDataObjectPropertiesHandle _Handle, TElXMLCommitmentTypeIndicationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_get_AllDataObjectsTimestamps(TElXMLSignedDataObjectPropertiesHandle _Handle, TElXMLCustomTimestampListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_get_IndividualDataObjectsTimestamps(TElXMLSignedDataObjectPropertiesHandle _Handle, TElXMLCustomTimestampListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_get_ID(TElXMLSignedDataObjectPropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_set_ID(TElXMLSignedDataObjectPropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_Create(TSBXAdESVersionRaw AVersion, TElXMLSignedDataObjectPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSignedDataObjectPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedDataObjectProperties_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSignedDataObjectPropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDDATAOBJECTPROPERTY
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedDataObjectProperty_Create(TSBXAdESVersionRaw AVersion, TElXMLUnsignedDataObjectPropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedDataObjectProperty_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLUnsignedDataObjectPropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedDataObjectProperty_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLUnsignedDataObjectPropertyHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDDATAOBJECTPROPERTY */

#ifdef SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_Clear(TElXMLSignedSignaturePropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_IsEmpty(TElXMLSignedSignaturePropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_LoadFromXML(TElXMLSignedSignaturePropertiesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_SaveToXML(TElXMLSignedSignaturePropertiesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_get_SignedTime(TElXMLSignedSignaturePropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_set_SignedTime(TElXMLSignedSignaturePropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_get_SignedTimeUTC(TElXMLSignedSignaturePropertiesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_set_SignedTimeUTC(TElXMLSignedSignaturePropertiesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_get_SigningCertificate(TElXMLSignedSignaturePropertiesHandle _Handle, TElXMLCertIDListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_get_SignaturePolicyIdentifier(TElXMLSignedSignaturePropertiesHandle _Handle, TElXMLSignaturePolicyIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_get_SignatureProductionPlace(TElXMLSignedSignaturePropertiesHandle _Handle, TElXMLSignatureProductionPlaceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_set_SignatureProductionPlace(TElXMLSignedSignaturePropertiesHandle _Handle, TElXMLSignatureProductionPlaceHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_get_SignerRole(TElXMLSignedSignaturePropertiesHandle _Handle, TElXMLSignerRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_set_SignerRole(TElXMLSignedSignaturePropertiesHandle _Handle, TElXMLSignerRoleHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_get_ID(TElXMLSignedSignaturePropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_set_ID(TElXMLSignedSignaturePropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_Create(TSBXAdESVersionRaw AVersion, TElXMLSignedSignaturePropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSignedSignaturePropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedSignatureProperties_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSignedSignaturePropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_Clear(TElXMLUnsignedSignaturePropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_IsEmpty(TElXMLUnsignedSignaturePropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_LoadFromXML(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_SaveToXML(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_XAdESForm(TElXMLUnsignedSignaturePropertiesHandle _Handle, TSBXAdESFormRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_XAdESForm(TElXMLUnsignedSignaturePropertiesHandle _Handle, TSBXAdESFormRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_ID(TElXMLUnsignedSignaturePropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_ID(TElXMLUnsignedSignaturePropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_CounterSignatures(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCounterSignatureListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_SignatureTimestamps(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCustomTimestampListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_CompleteCertificateRefs(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCompleteCertificateRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_CompleteCertificateRefs(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCompleteCertificateRefsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_CompleteRevocationRefs(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCompleteRevocationRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_CompleteRevocationRefs(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCompleteRevocationRefsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_AttributeCertificateRefs(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCompleteCertificateRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_AttributeCertificateRefs(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCompleteCertificateRefsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_AttributeRevocationRefs(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCompleteRevocationRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_AttributeRevocationRefs(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCompleteRevocationRefsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_SigAndRefsTimestamps(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCustomTimestampListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_RefsOnlyTimestamps(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCustomTimestampListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_CertificateValues(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCertificateValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_CertificateValues(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCertificateValuesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_RevocationValues(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLRevocationValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_RevocationValues(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLRevocationValuesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_AttrAuthoritiesCertValues(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCertificateValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_AttrAuthoritiesCertValues(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCertificateValuesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_AttributeRevocationValues(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLRevocationValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_set_AttributeRevocationValues(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLRevocationValuesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_ArchiveTimestamps(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCustomTimestampListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_ArchiveTimestampsV141(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLCustomTimestampListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_get_TimeStampValidationDataList(TElXMLUnsignedSignaturePropertiesHandle _Handle, TElXMLTimeStampValidationDataListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_Create(TSBXAdESVersionRaw AVersion, TElXMLUnsignedSignaturePropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLUnsignedSignaturePropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedSignatureProperties_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLUnsignedSignaturePropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLSIGNEDPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_Clear(TElXMLSignedPropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_IsEmpty(TElXMLSignedPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_LoadFromXML(TElXMLSignedPropertiesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_SaveToXML(TElXMLSignedPropertiesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_get_ID(TElXMLSignedPropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_set_ID(TElXMLSignedPropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_get_SignedSignatureProperties(TElXMLSignedPropertiesHandle _Handle, TElXMLSignedSignaturePropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_set_SignedSignatureProperties(TElXMLSignedPropertiesHandle _Handle, TElXMLSignedSignaturePropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_get_SignedDataObjectProperties(TElXMLSignedPropertiesHandle _Handle, TElXMLSignedDataObjectPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_set_SignedDataObjectProperties(TElXMLSignedPropertiesHandle _Handle, TElXMLSignedDataObjectPropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_Create(TSBXAdESVersionRaw AVersion, TElXMLSignedPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLSignedPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedProperties_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLSignedPropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNEDPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_Clear(TElXMLUnsignedPropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_IsEmpty(TElXMLUnsignedPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_LoadFromXML(TElXMLUnsignedPropertiesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_SaveToXML(TElXMLUnsignedPropertiesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_get_ID(TElXMLUnsignedPropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_set_ID(TElXMLUnsignedPropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_get_UnsignedSignatureProperties(TElXMLUnsignedPropertiesHandle _Handle, TElXMLUnsignedSignaturePropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_set_UnsignedSignatureProperties(TElXMLUnsignedPropertiesHandle _Handle, TElXMLUnsignedSignaturePropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_get_UnsignedDataObjectProperties(TElXMLUnsignedPropertiesHandle _Handle, TElXMLAnyTypeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_Create(TSBXAdESVersionRaw AVersion, TElXMLUnsignedPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLUnsignedPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnsignedProperties_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLUnsignedPropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_Clear(TElXMLQualifyingPropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_IsEmpty(TElXMLQualifyingPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_LoadFromXML(TElXMLQualifyingPropertiesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_SaveToXML(TElXMLQualifyingPropertiesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_get_XAdESPrefix(TElXMLQualifyingPropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_set_XAdESPrefix(TElXMLQualifyingPropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_get_XAdESv141Prefix(TElXMLQualifyingPropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_set_XAdESv141Prefix(TElXMLQualifyingPropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_get_ID(TElXMLQualifyingPropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_set_ID(TElXMLQualifyingPropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_get_Target(TElXMLQualifyingPropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_set_Target(TElXMLQualifyingPropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_get_SignedProperties(TElXMLQualifyingPropertiesHandle _Handle, TElXMLSignedPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_set_SignedProperties(TElXMLQualifyingPropertiesHandle _Handle, TElXMLSignedPropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_get_UnsignedProperties(TElXMLQualifyingPropertiesHandle _Handle, TElXMLUnsignedPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_set_UnsignedProperties(TElXMLQualifyingPropertiesHandle _Handle, TElXMLUnsignedPropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_Create(TSBXAdESVersionRaw AVersion, TElXMLQualifyingPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLQualifyingPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingProperties_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLQualifyingPropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_Clear(TElXMLQualifyingPropertiesReferenceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_IsEmpty(TElXMLQualifyingPropertiesReferenceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_LoadFromXML(TElXMLQualifyingPropertiesReferenceHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_SaveToXML(TElXMLQualifyingPropertiesReferenceHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_get_ID(TElXMLQualifyingPropertiesReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_set_ID(TElXMLQualifyingPropertiesReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_get_URI(TElXMLQualifyingPropertiesReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_set_URI(TElXMLQualifyingPropertiesReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_get_TransformChain(TElXMLQualifyingPropertiesReferenceHandle _Handle, TElXMLTransformChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_get_QualifyingProperties(TElXMLQualifyingPropertiesReferenceHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_set_QualifyingProperties(TElXMLQualifyingPropertiesReferenceHandle _Handle, TElXMLDOMElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_Create(TSBXAdESVersionRaw AVersion, TElXMLQualifyingPropertiesReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_Create_1(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, TElXMLQualifyingPropertiesReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReference_Create_2(TSBXAdESVersionRaw AVersion, const sb_char16_t * pcAName, int32_t szAName, int8_t SupportedV141, TElXMLQualifyingPropertiesReferenceHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReferenceList_Add(TElXMLQualifyingPropertiesReferenceListHandle _Handle, TElXMLQualifyingPropertiesReferenceHandle AQualifyingPropertiesRef, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReferenceList_Insert(TElXMLQualifyingPropertiesReferenceListHandle _Handle, int32_t Index, TElXMLQualifyingPropertiesReferenceHandle AQualifyingPropertiesRef);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReferenceList_Delete(TElXMLQualifyingPropertiesReferenceListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReferenceList_Clear(TElXMLQualifyingPropertiesReferenceListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReferenceList_get_Count(TElXMLQualifyingPropertiesReferenceListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReferenceList_get_QualifyingPropertiesReference(TElXMLQualifyingPropertiesReferenceListHandle _Handle, int32_t Index, TElXMLQualifyingPropertiesReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLQualifyingPropertiesReferenceList_Create(TElXMLQualifyingPropertiesReferenceListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLAdESElement;
typedef TElXMLAdESElement ElXMLAdESElement;
class TElXMLAnyType;
typedef TElXMLAnyType ElXMLAnyType;
class TElXMLAnyTypeList;
typedef TElXMLAnyTypeList ElXMLAnyTypeList;
class TElXMLObjectIdentifier;
typedef TElXMLObjectIdentifier ElXMLObjectIdentifier;
class TElXMLEncapsulatedPKIData;
typedef TElXMLEncapsulatedPKIData ElXMLEncapsulatedPKIData;
class TElXMLEncapsulatedPKIDataList;
typedef TElXMLEncapsulatedPKIDataList ElXMLEncapsulatedPKIDataList;
class TElXMLHashDataInfo;
typedef TElXMLHashDataInfo ElXMLHashDataInfo;
class TElXMLHashDataInfoList;
typedef TElXMLHashDataInfoList ElXMLHashDataInfoList;
class TElXMLCustomTimestamp;
typedef TElXMLCustomTimestamp ElXMLCustomTimestamp;
class TElXMLCustomTimestampList;
typedef TElXMLCustomTimestampList ElXMLCustomTimestampList;
class TElXMLTimestamp;
typedef TElXMLTimestamp ElXMLTimestamp;
class TElXMLTimestampList;
typedef TElXMLTimestampList ElXMLTimestampList;
class TElXMLInclude;
typedef TElXMLInclude ElXMLInclude;
class TElXMLIncludeList;
typedef TElXMLIncludeList ElXMLIncludeList;
class TElXMLTimestamp_v1_2_2;
typedef TElXMLTimestamp_v1_2_2 ElXMLTimestamp_v1_2_2;
class TElXMLTimestampList_v1_2_2;
typedef TElXMLTimestampList_v1_2_2 ElXMLTimestampList_v1_2_2;
class TElCustomTSPClientList;
typedef TElCustomTSPClientList ElCustomTSPClientList;
class TElXMLGenericTimestamp;
typedef TElXMLGenericTimestamp ElXMLGenericTimestamp;
class TElXMLGenericTimestampList;
typedef TElXMLGenericTimestampList ElXMLGenericTimestampList;
typedef TElXMLGenericTimestamp TElXMLAdESTimestamp;
typedef TElXMLGenericTimestamp ElXMLXAdESTimestamp;
typedef TElXMLGenericTimestampList TElXMLAdESTimestampList;
typedef TElXMLGenericTimestampList ElXMLXAdESTimestampList;
class TElXMLDigestAlgAndValue;
typedef TElXMLDigestAlgAndValue ElXMLDigestAlgAndValue;
class TElXMLCertID;
typedef TElXMLCertID ElXMLCertID;
class TElXMLCertIDList;
typedef TElXMLCertIDList ElXMLCertIDList;
class TElXMLNoticeReference;
typedef TElXMLNoticeReference ElXMLNoticeReference;
class TElXMLSPUserNotice;
typedef TElXMLSPUserNotice ElXMLSPUserNotice;
class TElXMLSPURI;
typedef TElXMLSPURI ElXMLSPURI;
class TElXMLSigPolicyQualifier;
typedef TElXMLSigPolicyQualifier ElXMLSigPolicyQualifier;
typedef TElXMLAnyTypeList TElXMLSigPolicyQualifierList;
typedef TElXMLAnyTypeList ElXMLSigPolicyQualifierList;
class TElXMLSignaturePolicyId;
typedef TElXMLSignaturePolicyId ElXMLSignaturePolicyId;
class TElXMLSignaturePolicyIdentifier;
typedef TElXMLSignaturePolicyIdentifier ElXMLSignaturePolicyIdentifier;
class TElXMLCounterSignature;
typedef TElXMLCounterSignature ElXMLCounterSignature;
class TElXMLCounterSignatureList;
typedef TElXMLCounterSignatureList ElXMLCounterSignatureList;
class TElXMLDataObjectFormat;
typedef TElXMLDataObjectFormat ElXMLDataObjectFormat;
class TElXMLDataObjectFormatList;
typedef TElXMLDataObjectFormatList ElXMLDataObjectFormatList;
class TElXMLCommitmentTypeQualifier;
typedef TElXMLCommitmentTypeQualifier ElXMLCommitmentTypeQualifier;
typedef TElXMLAnyTypeList TElXMLCommitmentTypeQualifierList;
typedef TElXMLAnyTypeList ElXMLCommitmentTypeQualifierList;
class TElXMLCommitmentTypeIndication;
typedef TElXMLCommitmentTypeIndication ElXMLCommitmentTypeIndication;
class TElXMLCommitmentTypeIndicationList;
typedef TElXMLCommitmentTypeIndicationList ElXMLCommitmentTypeIndicationList;
class TElXMLSignatureProductionPlace;
typedef TElXMLSignatureProductionPlace ElXMLSignatureProductionPlace;
class TElXMLEncapsulatedX509Certificates;
typedef TElXMLEncapsulatedX509Certificates ElXMLEncapsulatedX509Certificates;
class TElXMLCertifiedRole;
typedef TElXMLCertifiedRole ElXMLCertifiedRole;
class TElXMLCertifiedRolesList;
typedef TElXMLCertifiedRolesList ElXMLCertifiedRolesList;
class TElXMLClaimedRole;
typedef TElXMLClaimedRole ElXMLClaimedRole;
class TElXMLClaimedRolesList;
typedef TElXMLClaimedRolesList ElXMLClaimedRolesList;
class TElXMLSignerRole;
typedef TElXMLSignerRole ElXMLSignerRole;
class TElXMLCompleteCertificateRefs;
typedef TElXMLCompleteCertificateRefs ElXMLCompleteCertificateRefs;
class TElXMLCRLIdentifier;
typedef TElXMLCRLIdentifier ElXMLCRLIdentifier;
class TElXMLCRLRef;
typedef TElXMLCRLRef ElXMLCRLRef;
class TElXMLCRLRefs;
typedef TElXMLCRLRefs ElXMLCRLRefs;
class TElXMLOCSPIdentifier;
typedef TElXMLOCSPIdentifier ElXMLOCSPIdentifier;
class TElXMLOCSPRef;
typedef TElXMLOCSPRef ElXMLOCSPRef;
class TElXMLOCSPRefs;
typedef TElXMLOCSPRefs ElXMLOCSPRefs;
class TElXMLOtherRef;
typedef TElXMLOtherRef ElXMLOtherRef;
typedef TElXMLAnyTypeList TElXMLOtherCertStatusRefs;
typedef TElXMLAnyTypeList ElXMLOtherCertStatusRefs;
class TElXMLCompleteRevocationRefs;
typedef TElXMLCompleteRevocationRefs ElXMLCompleteRevocationRefs;
class TElXMLCertificateValues;
typedef TElXMLCertificateValues ElXMLCertificateValues;
class TElXMLEncapsulatedCRLValue;
typedef TElXMLEncapsulatedCRLValue ElXMLEncapsulatedCRLValue;
class TElXMLCRLValues;
typedef TElXMLCRLValues ElXMLCRLValues;
class TElXMLEncapsulatedOCSPValue;
typedef TElXMLEncapsulatedOCSPValue ElXMLEncapsulatedOCSPValue;
class TElXMLOCSPValues;
typedef TElXMLOCSPValues ElXMLOCSPValues;
typedef TElXMLAnyTypeList TElXMLOtherCertStatusValues;
typedef TElXMLAnyTypeList ElXMLOtherCertStatusValues;
class TElXMLRevocationValues;
typedef TElXMLRevocationValues ElXMLRevocationValues;
class TElXMLTimeStampValidationData;
typedef TElXMLTimeStampValidationData ElXMLTimeStampValidationData;
class TElXMLTimeStampValidationDataList;
typedef TElXMLTimeStampValidationDataList ElXMLTimeStampValidationDataList;
class TElXMLSignedDataObjectProperties;
typedef TElXMLSignedDataObjectProperties ElXMLSignedDataObjectProperties;
class TElXMLUnsignedDataObjectProperty;
typedef TElXMLUnsignedDataObjectProperty ElXMLUnsignedDataObjectProperty;
typedef TElXMLAnyTypeList TElXMLUnsignedDataObjectProperties;
typedef TElXMLAnyTypeList ElXMLUnsignedDataObjectProperties;
class TElXMLSignedSignatureProperties;
typedef TElXMLSignedSignatureProperties ElXMLSignedSignatureProperties;
class TElXMLUnsignedSignatureProperties;
typedef TElXMLUnsignedSignatureProperties ElXMLUnsignedSignatureProperties;
class TElXMLSignedProperties;
typedef TElXMLSignedProperties ElXMLSignedProperties;
class TElXMLUnsignedProperties;
typedef TElXMLUnsignedProperties ElXMLUnsignedProperties;
class TElXMLQualifyingProperties;
typedef TElXMLQualifyingProperties ElXMLQualifyingProperties;
class TElXMLQualifyingPropertiesReference;
typedef TElXMLQualifyingPropertiesReference ElXMLQualifyingPropertiesReference;
class TElXMLQualifyingPropertiesReferenceList;
typedef TElXMLQualifyingPropertiesReferenceList ElXMLQualifyingPropertiesReferenceList;

#ifdef SB_USE_CLASS_TELXMLADESELEMENT
class TElXMLAdESElement: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLAdESElement)
	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual bool IsEmpty();

		virtual TSBXAdESVersion get_XAdESVersion();

		SB_DECLARE_PROPERTY_GET(TSBXAdESVersion, get_XAdESVersion, TElXMLAdESElement, XAdESVersion);

		TElXMLAdESElement(TElXMLAdESElementHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLAdESElement(TSBXAdESVersion AVersion);

		TElXMLAdESElement(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLAdESElement(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLAdESElement(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLAdESElement(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLADESELEMENT */

#ifdef SB_USE_CLASS_TELXMLANYTYPE
class TElXMLAnyType: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLAnyType)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_Value;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_Value();

		virtual void set_Value(TElXMLDOMNode &Value);

		virtual void set_Value(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_Value, set_Value, TElXMLAnyType, Value);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		TElXMLAnyType(TElXMLAnyTypeHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLAnyType(TSBXAdESVersion AVersion);

		TElXMLAnyType(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLAnyType(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLAnyType(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLAnyType(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLAnyType();

};
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
class TElXMLAnyTypeList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLAnyTypeList)
#ifdef SB_USE_CLASS_TELXMLANYTYPE
		TElXMLAnyType* _Inst_Item;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

		void initInstances();

	public:
		void Assign(TElXMLAnyTypeList &Source, TSBXAdESVersion AVersion);

		void Assign(TElXMLAnyTypeList *Source, TSBXAdESVersion AVersion);

#ifdef SB_USE_CLASS_TELXMLANYTYPE
		int32_t Add(TElXMLAnyType &AItem);

		int32_t Add(TElXMLAnyType *AItem);
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

#ifdef SB_USE_CLASS_TELXMLANYTYPE
		void Insert(int32_t Index, TElXMLAnyType &AItem);

		void Insert(int32_t Index, TElXMLAnyType *AItem);
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLAnyTypeList, Count);

#ifdef SB_USE_CLASS_TELXMLANYTYPE
		virtual TElXMLAnyType* get_Item(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

		TElXMLAnyTypeList(TElXMLAnyTypeListHandle handle, TElOwnHandle ownHandle);

		TElXMLAnyTypeList();

		virtual ~TElXMLAnyTypeList();

};
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
class TElXMLObjectIdentifier: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLObjectIdentifier)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_DocumentationReferences;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Description(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Description(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Description(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Description(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_DocumentationReferences();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_DocumentationReferences, TElXMLObjectIdentifier, DocumentationReferences);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual void get_Identifier(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Identifier(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Identifier(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Identifier(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TSBXAdESQualifierType get_IdentifierQualifier();

		virtual void set_IdentifierQualifier(TSBXAdESQualifierType Value);

		SB_DECLARE_PROPERTY(TSBXAdESQualifierType, get_IdentifierQualifier, set_IdentifierQualifier, TElXMLObjectIdentifier, IdentifierQualifier);

		TElXMLObjectIdentifier(TElXMLObjectIdentifierHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLObjectIdentifier(TSBXAdESVersion AVersion);

		TElXMLObjectIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLObjectIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLObjectIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLObjectIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLObjectIdentifier();

};
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
class TElXMLEncapsulatedPKIData: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLEncapsulatedPKIData)
	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual void set_Data(const std::vector<uint8_t> &Value);

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TSBXAdESEncodingMethod get_Encoding();

		virtual void set_Encoding(TSBXAdESEncodingMethod Value);

		SB_DECLARE_PROPERTY(TSBXAdESEncodingMethod, get_Encoding, set_Encoding, TElXMLEncapsulatedPKIData, Encoding);

		TElXMLEncapsulatedPKIData(TElXMLEncapsulatedPKIDataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion);

		TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLEncapsulatedPKIData(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST
class TElXMLEncapsulatedPKIDataList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLEncapsulatedPKIDataList)
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
		TElXMLEncapsulatedPKIData* _Inst_PKIData;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

		void initInstances();

	public:
		void Assign(TElXMLEncapsulatedPKIDataList &Source, TSBXAdESVersion AVersion);

		void Assign(TElXMLEncapsulatedPKIDataList *Source, TSBXAdESVersion AVersion);

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
		int32_t Add(TElXMLEncapsulatedPKIData &APKIData);

		int32_t Add(TElXMLEncapsulatedPKIData *APKIData);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
		void Insert(int32_t Index, TElXMLEncapsulatedPKIData &APKIData);

		void Insert(int32_t Index, TElXMLEncapsulatedPKIData *APKIData);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

		void Delete(int32_t Index);

		virtual void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLEncapsulatedPKIDataList, Count);

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
		virtual TElXMLEncapsulatedPKIData* get_PKIData(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

		TElXMLEncapsulatedPKIDataList(TElXMLEncapsulatedPKIDataListHandle handle, TElOwnHandle ownHandle);

		TElXMLEncapsulatedPKIDataList();

		virtual ~TElXMLEncapsulatedPKIDataList();

};
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
class TElXMLHashDataInfo: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLHashDataInfo)
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		TElXMLTransformChain* _Inst_TransformChain;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_URINode;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		void GetHashData(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		virtual TElXMLTransformChain* get_TransformChain();

		virtual void set_TransformChain(TElXMLTransformChain &Value);

		virtual void set_TransformChain(TElXMLTransformChain *Value);

		SB_DECLARE_PROPERTY(TElXMLTransformChain*, get_TransformChain, set_TransformChain, TElXMLHashDataInfo, TransformChain);
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_URIData(std::vector<uint8_t> &OutResult);

		virtual void set_URIData(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_URINode();

		virtual void set_URINode(TElXMLDOMNode &Value);

		virtual void set_URINode(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_URINode, set_URINode, TElXMLHashDataInfo, URINode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		TElXMLHashDataInfo(TElXMLHashDataInfoHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLHashDataInfo(TSBXAdESVersion AVersion);

		TElXMLHashDataInfo(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLHashDataInfo(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLHashDataInfo(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLHashDataInfo(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLHashDataInfo();

};
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFOLIST
class TElXMLHashDataInfoList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLHashDataInfoList)
#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
		TElXMLHashDataInfo* _Inst_HashDataInfo;
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
		int32_t Add(TElXMLHashDataInfo &AHashDataInfo);

		int32_t Add(TElXMLHashDataInfo *AHashDataInfo);
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
		void Insert(int32_t Index, TElXMLHashDataInfo &AHashDataInfo);

		void Insert(int32_t Index, TElXMLHashDataInfo *AHashDataInfo);
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLHashDataInfoList, Count);

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFO
		virtual TElXMLHashDataInfo* get_HashDataInfo(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFO */

		TElXMLHashDataInfoList(TElXMLHashDataInfoListHandle handle, TElOwnHandle ownHandle);

		TElXMLHashDataInfoList();

		virtual ~TElXMLHashDataInfoList();

};
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFOLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
class TElXMLCustomTimestamp: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCustomTimestamp)
	public:
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfoHandle GetTimestampInfo();
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		bool CheckTimestamp(TElClientTSPInfo &Info);

		bool CheckTimestamp(TElClientTSPInfo *Info);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual bool CheckTimestamp(TElClientTSPInfo &Info, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		virtual bool CheckTimestamp(TElClientTSPInfo *Info, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t Timestamp(TElCustomTSPClient &TSPClient);

		int32_t Timestamp(TElCustomTSPClient *TSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT
		virtual int32_t Timestamp(TElCustomTSPClient &TSPClient, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		virtual int32_t Timestamp(TElCustomTSPClient *TSPClient, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT */

		TElXMLCustomTimestamp(TElXMLCustomTimestampHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCustomTimestamp(TSBXAdESVersion AVersion);

		TElXMLCustomTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCustomTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCustomTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCustomTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
class TElXMLCustomTimestampList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLCustomTimestampList)
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
		TElXMLCustomTimestamp* _Inst_Timestamp;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
		virtual int32_t Add(TElXMLCustomTimestamp &ATimestamp);

		virtual int32_t Add(TElXMLCustomTimestamp *ATimestamp);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
		virtual void Insert(int32_t Index, TElXMLCustomTimestamp &ATimestamp);

		virtual void Insert(int32_t Index, TElXMLCustomTimestamp *ATimestamp);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLCustomTimestampList, Count);

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP
		virtual TElXMLCustomTimestamp* get_Timestamp(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMP */

		TElXMLCustomTimestampList(TElXMLCustomTimestampListHandle handle, TElOwnHandle ownHandle);

		TElXMLCustomTimestampList();

		virtual ~TElXMLCustomTimestampList();

};
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
class TElXMLTimestamp: public TElXMLCustomTimestamp
{
	private:
		SB_DISABLE_COPY(TElXMLTimestamp)
#ifdef SB_USE_CLASS_TELXMLHASHDATAINFOLIST
		TElXMLHashDataInfoList* _Inst_HashDataInfos;
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFOLIST */
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
		TElXMLEncapsulatedPKIData* _Inst_EncapsulatedTimestamp;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */
#ifdef SB_USE_CLASS_TELXMLANYTYPE
		TElXMLAnyType* _Inst_XMLTimestamp;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfoHandle GetTimestampInfo();
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual bool CheckTimestamp(TElClientTSPInfo &Info, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		virtual bool CheckTimestamp(TElClientTSPInfo *Info, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT
		virtual int32_t Timestamp(TElCustomTSPClient &TSPClient, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		virtual int32_t Timestamp(TElCustomTSPClient *TSPClient, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELXMLHASHDATAINFOLIST
		virtual TElXMLHashDataInfoList* get_HashDataInfos();

		SB_DECLARE_PROPERTY_GET(TElXMLHashDataInfoList*, get_HashDataInfos, TElXMLTimestamp, HashDataInfos);
#endif /* SB_USE_CLASS_TELXMLHASHDATAINFOLIST */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
		virtual TElXMLEncapsulatedPKIData* get_EncapsulatedTimestamp();

		virtual void set_EncapsulatedTimestamp(TElXMLEncapsulatedPKIData &Value);

		virtual void set_EncapsulatedTimestamp(TElXMLEncapsulatedPKIData *Value);

		SB_DECLARE_PROPERTY(TElXMLEncapsulatedPKIData*, get_EncapsulatedTimestamp, set_EncapsulatedTimestamp, TElXMLTimestamp, EncapsulatedTimestamp);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLANYTYPE
		virtual TElXMLAnyType* get_XMLTimestamp();

		virtual void set_XMLTimestamp(TElXMLAnyType &Value);

		virtual void set_XMLTimestamp(TElXMLAnyType *Value);

		SB_DECLARE_PROPERTY(TElXMLAnyType*, get_XMLTimestamp, set_XMLTimestamp, TElXMLTimestamp, XMLTimestamp);
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

		TElXMLTimestamp(TElXMLTimestampHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLTimestamp(TSBXAdESVersion AVersion);

		TElXMLTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLTimestamp();

};
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPLIST
class TElXMLTimestampList: public TElXMLCustomTimestampList
{
	private:
		SB_DISABLE_COPY(TElXMLTimestampList)
#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
		TElXMLTimestamp* _Inst_Timestamp;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
		int32_t Add(TElXMLTimestamp &ATimestamp);

		int32_t Add(TElXMLTimestamp *ATimestamp);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
		void Insert(int32_t Index, TElXMLTimestamp &ATimestamp);

		void Insert(int32_t Index, TElXMLTimestamp *ATimestamp);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP
		virtual TElXMLTimestamp* get_Timestamp_TElXMLTimestamp(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP */

		TElXMLTimestampList(TElXMLTimestampListHandle handle, TElOwnHandle ownHandle);

		TElXMLTimestampList();

		virtual ~TElXMLTimestampList();

};
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLINCLUDE
class TElXMLInclude: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLInclude)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_URINode;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLREFERENCE
		TElXMLReference* _Inst_URIReference;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELHASHFUNCTION
		void ProcessIncludeData(TElXMLCanonicalizationMethod CanonicalizationMethod, TElHashFunction &HashFunc);

		void ProcessIncludeData(TElXMLCanonicalizationMethod CanonicalizationMethod, TElHashFunction *HashFunc);
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

		virtual bool get_ReferencedData();

		virtual void set_ReferencedData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReferencedData, set_ReferencedData, TElXMLInclude, ReferencedData);

		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_URIData(std::vector<uint8_t> &OutResult);

		virtual void set_URIData(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_URINode();

		virtual void set_URINode(TElXMLDOMNode &Value);

		virtual void set_URINode(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_URINode, set_URINode, TElXMLInclude, URINode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
		virtual TElXMLReference* get_URIReference();

		virtual void set_URIReference(TElXMLReference &Value);

		virtual void set_URIReference(TElXMLReference *Value);

		SB_DECLARE_PROPERTY(TElXMLReference*, get_URIReference, set_URIReference, TElXMLInclude, URIReference);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		TElXMLInclude(TElXMLIncludeHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLInclude(TSBXAdESVersion AVersion);

		TElXMLInclude(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLInclude(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLInclude(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLInclude(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLInclude();

};
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
class TElXMLIncludeList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLIncludeList)
#ifdef SB_USE_CLASS_TELXMLINCLUDE
		TElXMLInclude* _Inst_Includes;
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLINCLUDE
		int32_t Add(TElXMLInclude &AInclude);

		int32_t Add(TElXMLInclude *AInclude);
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

#ifdef SB_USE_CLASS_TELXMLINCLUDE
		void Insert(int32_t Index, TElXMLInclude &AInclude);

		void Insert(int32_t Index, TElXMLInclude *AInclude);
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLIncludeList, Count);

#ifdef SB_USE_CLASS_TELXMLINCLUDE
		virtual TElXMLInclude* get_Includes(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLINCLUDE */

		TElXMLIncludeList(TElXMLIncludeListHandle handle, TElOwnHandle ownHandle);

		TElXMLIncludeList();

		virtual ~TElXMLIncludeList();

};
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
class TElXMLTimestamp_v1_2_2: public TElXMLCustomTimestamp
{
	private:
		SB_DISABLE_COPY(TElXMLTimestamp_v1_2_2)
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
		TElXMLEncapsulatedPKIData* _Inst_EncapsulatedTimestamp;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */
#ifdef SB_USE_CLASS_TELXMLANYTYPE
		TElXMLAnyType* _Inst_XMLTimestamp;
#endif /* SB_USE_CLASS_TELXMLANYTYPE */
#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
		TElXMLIncludeList* _Inst_Includes;
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfoHandle GetTimestampInfo();
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual bool CheckTimestamp(TElClientTSPInfo &Info, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		virtual bool CheckTimestamp(TElClientTSPInfo *Info, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT
		virtual int32_t Timestamp(TElCustomTSPClient &TSPClient, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		virtual int32_t Timestamp(TElCustomTSPClient *TSPClient, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TElXMLCanonicalizationMethod get_CanonicalizationMethod();

		virtual void set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value);

		SB_DECLARE_PROPERTY(TElXMLCanonicalizationMethod, get_CanonicalizationMethod, set_CanonicalizationMethod, TElXMLTimestamp_v1_2_2, CanonicalizationMethod);

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA
		virtual TElXMLEncapsulatedPKIData* get_EncapsulatedTimestamp();

		virtual void set_EncapsulatedTimestamp(TElXMLEncapsulatedPKIData &Value);

		virtual void set_EncapsulatedTimestamp(TElXMLEncapsulatedPKIData *Value);

		SB_DECLARE_PROPERTY(TElXMLEncapsulatedPKIData*, get_EncapsulatedTimestamp, set_EncapsulatedTimestamp, TElXMLTimestamp_v1_2_2, EncapsulatedTimestamp);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATA */

#ifdef SB_USE_CLASS_TELXMLANYTYPE
		virtual TElXMLAnyType* get_XMLTimestamp();

		virtual void set_XMLTimestamp(TElXMLAnyType &Value);

		virtual void set_XMLTimestamp(TElXMLAnyType *Value);

		SB_DECLARE_PROPERTY(TElXMLAnyType*, get_XMLTimestamp, set_XMLTimestamp, TElXMLTimestamp_v1_2_2, XMLTimestamp);
#endif /* SB_USE_CLASS_TELXMLANYTYPE */

#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
		virtual TElXMLIncludeList* get_Includes();

		SB_DECLARE_PROPERTY_GET(TElXMLIncludeList*, get_Includes, TElXMLTimestamp_v1_2_2, Includes);
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

		TElXMLTimestamp_v1_2_2(TElXMLTimestamp_v1_2_2Handle handle, TElOwnHandle ownHandle);

		explicit TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion);

		TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLTimestamp_v1_2_2(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLTimestamp_v1_2_2();

};
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPLIST_V1_2_2
class TElXMLTimestampList_v1_2_2: public TElXMLCustomTimestampList
{
	private:
		SB_DISABLE_COPY(TElXMLTimestampList_v1_2_2)
#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
		TElXMLTimestamp_v1_2_2* _Inst_Timestamp;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
		int32_t Add(TElXMLTimestamp_v1_2_2 &ATimestamp);

		int32_t Add(TElXMLTimestamp_v1_2_2 *ATimestamp);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
		void Insert(int32_t Index, TElXMLTimestamp_v1_2_2 &ATimestamp);

		void Insert(int32_t Index, TElXMLTimestamp_v1_2_2 *ATimestamp);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2
		virtual TElXMLTimestamp_v1_2_2* get_Timestamp_TElXMLTimestamp_v1_2_2(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMP_V1_2_2 */

		TElXMLTimestampList_v1_2_2(TElXMLTimestampList_v1_2_2Handle handle, TElOwnHandle ownHandle);

		TElXMLTimestampList_v1_2_2();

		virtual ~TElXMLTimestampList_v1_2_2();

};
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPLIST_V1_2_2 */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST
class TElCustomTSPClientList: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomTSPClientList)
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		TElCustomTSPClient* _Inst_TSPClients;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t Add(TElCustomTSPClient &ATSPClient);

		int32_t Add(TElCustomTSPClient *ATSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		void Insert(int32_t Index, TElCustomTSPClient &ATSPClient);

		void Insert(int32_t Index, TElCustomTSPClient *ATSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElCustomTSPClientList, Count);

		virtual bool get_OwnItems();

		SB_DECLARE_PROPERTY_GET(bool, get_OwnItems, TElCustomTSPClientList, OwnItems);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		virtual TElCustomTSPClient* get_TSPClients(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		TElCustomTSPClientList(TElCustomTSPClientListHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomTSPClientList(bool AOwnItems);

		virtual ~TElCustomTSPClientList();

};
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
class TElXMLGenericTimestamp: public TElXMLCustomTimestamp
{
	private:
		SB_DISABLE_COPY(TElXMLGenericTimestamp)
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST
		TElCustomTSPClientList* _Inst_TSPClients;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST
		TElXMLEncapsulatedPKIDataList* _Inst_EncapsulatedTimestamps;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		TElXMLAnyTypeList* _Inst_XMLTimestamps;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
		TElXMLIncludeList* _Inst_Includes;
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfoHandle GetTimestampInfo();
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfoHandle GetTimestampInfo(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		void AddTimestampData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		void AddTimestampData(const TElXMLDOMNode &Node);

		void AddTimestampData(const TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
		void AddTimestampData(const TElXMLReference &Ref);

		void AddTimestampData(const TElXMLReference *Ref);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		void StartTimestampCheck(TElClientTSPInfo &Info);

		void StartTimestampCheck(TElClientTSPInfo *Info);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		bool FinishTimestampCheck();

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual bool CheckTimestamp(TElClientTSPInfo &Info, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		virtual bool CheckTimestamp(TElClientTSPInfo *Info, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		int32_t Timestamp();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT
		virtual int32_t Timestamp(TElCustomTSPClient &TSPClient, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		virtual int32_t Timestamp(TElCustomTSPClient *TSPClient, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELCUSTOMTSPCLIENT */

		virtual int32_t get_TimestampInfoCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TimestampInfoCount, TElXMLGenericTimestamp, TimestampInfoCount);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST
		virtual TElCustomTSPClientList* get_TSPClients();

		SB_DECLARE_PROPERTY_GET(TElCustomTSPClientList*, get_TSPClients, TElXMLGenericTimestamp, TSPClients);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENTLIST */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElXMLGenericTimestamp, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TElXMLCanonicalizationMethod get_CanonicalizationMethod();

		virtual void set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value);

		SB_DECLARE_PROPERTY(TElXMLCanonicalizationMethod, get_CanonicalizationMethod, set_CanonicalizationMethod, TElXMLGenericTimestamp, CanonicalizationMethod);

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST
		virtual TElXMLEncapsulatedPKIDataList* get_EncapsulatedTimestamps();

		SB_DECLARE_PROPERTY_GET(TElXMLEncapsulatedPKIDataList*, get_EncapsulatedTimestamps, TElXMLGenericTimestamp, EncapsulatedTimestamps);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDPKIDATALIST */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		virtual TElXMLAnyTypeList* get_XMLTimestamps();

		SB_DECLARE_PROPERTY_GET(TElXMLAnyTypeList*, get_XMLTimestamps, TElXMLGenericTimestamp, XMLTimestamps);
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TELXMLINCLUDELIST
		virtual TElXMLIncludeList* get_Includes();

		SB_DECLARE_PROPERTY_GET(TElXMLIncludeList*, get_Includes, TElXMLGenericTimestamp, Includes);
#endif /* SB_USE_CLASS_TELXMLINCLUDELIST */

		TElXMLGenericTimestamp(TElXMLGenericTimestampHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLGenericTimestamp(TSBXAdESVersion AVersion);

		TElXMLGenericTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLGenericTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLGenericTimestamp(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLGenericTimestamp(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLGenericTimestamp();

};
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMPLIST
class TElXMLGenericTimestampList: public TElXMLCustomTimestampList
{
	private:
		SB_DISABLE_COPY(TElXMLGenericTimestampList)
#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
		TElXMLGenericTimestamp* _Inst_Timestamp;
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
		int32_t Add(TElXMLGenericTimestamp &ATimestamp);

		int32_t Add(TElXMLGenericTimestamp *ATimestamp);
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
		void Insert(int32_t Index, TElXMLGenericTimestamp &ATimestamp);

		void Insert(int32_t Index, TElXMLGenericTimestamp *ATimestamp);
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLGENERICTIMESTAMP
		virtual TElXMLGenericTimestamp* get_Timestamp_TElXMLGenericTimestamp(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMP */

		TElXMLGenericTimestampList(TElXMLGenericTimestampListHandle handle, TElOwnHandle ownHandle);

		TElXMLGenericTimestampList();

		virtual ~TElXMLGenericTimestampList();

};
#endif /* SB_USE_CLASS_TELXMLGENERICTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
class TElXMLDigestAlgAndValue: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLDigestAlgAndValue)
	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_DigestMethod(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DigestMethod(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DigestMethod(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DigestMethod(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_DigestValue(std::vector<uint8_t> &OutResult);

		virtual void set_DigestValue(const std::vector<uint8_t> &Value);

		TElXMLDigestAlgAndValue(TElXMLDigestAlgAndValueHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion);

		TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLDigestAlgAndValue(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLCERTID
class TElXMLCertID: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCertID)
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
		TElXMLDigestAlgAndValue* _Inst_CertDigest;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLISSUERSERIAL
		TElXMLIssuerSerial* _Inst_IssuerSerial;
#endif /* SB_USE_CLASS_TELXMLISSUERSERIAL */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool IsMatch(TElX509Certificate &Cert);

		bool IsMatch(TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool IsMatch(TElX509Certificate &Cert, bool LiberalMode);

		bool IsMatch(TElX509Certificate *Cert, bool LiberalMode);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
		virtual TElXMLDigestAlgAndValue* get_CertDigest();

		virtual void set_CertDigest(TElXMLDigestAlgAndValue &Value);

		virtual void set_CertDigest(TElXMLDigestAlgAndValue *Value);

		SB_DECLARE_PROPERTY(TElXMLDigestAlgAndValue*, get_CertDigest, set_CertDigest, TElXMLCertID, CertDigest);
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLISSUERSERIAL
		virtual TElXMLIssuerSerial* get_IssuerSerial();

		virtual void set_IssuerSerial(TElXMLIssuerSerial &Value);

		virtual void set_IssuerSerial(TElXMLIssuerSerial *Value);

		SB_DECLARE_PROPERTY(TElXMLIssuerSerial*, get_IssuerSerial, set_IssuerSerial, TElXMLCertID, IssuerSerial);
#endif /* SB_USE_CLASS_TELXMLISSUERSERIAL */

		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLCertID(TElXMLCertIDHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCertID(TSBXAdESVersion AVersion);

		TElXMLCertID(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCertID(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCertID(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCertID(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLCertID();

};
#endif /* SB_USE_CLASS_TELXMLCERTID */

#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
class TElXMLCertIDList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLCertIDList)
#ifdef SB_USE_CLASS_TELXMLCERTID
		TElXMLCertID* _Inst_CertIDs;
#endif /* SB_USE_CLASS_TELXMLCERTID */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t HasCertificate(TElX509Certificate &ACertificate);

		int32_t HasCertificate(TElX509Certificate *ACertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddCertificate(TElX509Certificate &ACertificate, TSBXAdESVersion AXAdESVersion);

		int32_t AddCertificate(TElX509Certificate *ACertificate, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddCertificate(TElX509Certificate &ACertificate, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion);

		int32_t AddCertificate(TElX509Certificate *ACertificate, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddCertificate(TElX509Certificate &ACertificate, TElXMLDigestMethod DigestMethod, bool HexSerialNumber, TSBXAdESVersion AXAdESVersion);

		int32_t AddCertificate(TElX509Certificate *ACertificate, TElXMLDigestMethod DigestMethod, bool HexSerialNumber, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLCERTID
		int32_t Add(TElXMLCertID &ACertID);

		int32_t Add(TElXMLCertID *ACertID);
#endif /* SB_USE_CLASS_TELXMLCERTID */

#ifdef SB_USE_CLASS_TELXMLCERTID
		void Insert(int32_t Index, TElXMLCertID &ACertID);

		void Insert(int32_t Index, TElXMLCertID *ACertID);
#endif /* SB_USE_CLASS_TELXMLCERTID */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLCertIDList, Count);

#ifdef SB_USE_CLASS_TELXMLCERTID
		virtual TElXMLCertID* get_CertIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLCERTID */

		TElXMLCertIDList(TElXMLCertIDListHandle handle, TElOwnHandle ownHandle);

		TElXMLCertIDList();

		virtual ~TElXMLCertIDList();

};
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */

#ifdef SB_USE_CLASS_TELXMLNOTICEREFERENCE
class TElXMLNoticeReference: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLNoticeReference)
	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Organization(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Organization(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Organization(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Organization(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_NoticeNumbers(std::vector<int32_t> &OutResult);

		virtual void set_NoticeNumbers(const std::vector<int32_t> &Value);

		TElXMLNoticeReference(TElXMLNoticeReferenceHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLNoticeReference(TSBXAdESVersion AVersion);

		TElXMLNoticeReference(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLNoticeReference(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLNoticeReference(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLNoticeReference(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLNOTICEREFERENCE */

#ifdef SB_USE_CLASS_TELXMLSPUSERNOTICE
class TElXMLSPUserNotice: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSPUserNotice)
#ifdef SB_USE_CLASS_TELXMLNOTICEREFERENCE
		TElXMLNoticeReference* _Inst_NoticeRef;
#endif /* SB_USE_CLASS_TELXMLNOTICEREFERENCE */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLNOTICEREFERENCE
		virtual TElXMLNoticeReference* get_NoticeRef();

		virtual void set_NoticeRef(TElXMLNoticeReference &Value);

		virtual void set_NoticeRef(TElXMLNoticeReference *Value);

		SB_DECLARE_PROPERTY(TElXMLNoticeReference*, get_NoticeRef, set_NoticeRef, TElXMLSPUserNotice, NoticeRef);
#endif /* SB_USE_CLASS_TELXMLNOTICEREFERENCE */

		virtual void get_ExplicitTex(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ExplicitTex(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ExplicitTex(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ExplicitTex(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSPUserNotice(TElXMLSPUserNoticeHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSPUserNotice(TSBXAdESVersion AVersion);

		TElXMLSPUserNotice(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSPUserNotice(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSPUserNotice(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSPUserNotice(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLSPUserNotice();

};
#endif /* SB_USE_CLASS_TELXMLSPUSERNOTICE */

#ifdef SB_USE_CLASS_TELXMLSPURI
class TElXMLSPURI: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSPURI)
	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSPURI(TElXMLSPURIHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSPURI(TSBXAdESVersion AVersion);

		TElXMLSPURI(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSPURI(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSPURI(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSPURI(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLSPURI */

#ifdef SB_USE_CLASS_TELXMLSIGPOLICYQUALIFIER
class TElXMLSigPolicyQualifier: public TElXMLAnyType
{
	private:
		SB_DISABLE_COPY(TElXMLSigPolicyQualifier)
	public:
		TElXMLSigPolicyQualifier(TElXMLSigPolicyQualifierHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion);

		TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSigPolicyQualifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLSIGPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
class TElXMLSignaturePolicyId: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignaturePolicyId)
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
		TElXMLObjectIdentifier* _Inst_SigPolicyId;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
		TElXMLDigestAlgAndValue* _Inst_SigPolicyHash;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		TElXMLAnyTypeList* _Inst_SigPolicyQualifiers;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		TElXMLTransformChain* _Inst_TransformChain;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

		void initInstances();

	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
		virtual TElXMLObjectIdentifier* get_SigPolicyId();

		SB_DECLARE_PROPERTY_GET(TElXMLObjectIdentifier*, get_SigPolicyId, TElXMLSignaturePolicyId, SigPolicyId);
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
		virtual TElXMLDigestAlgAndValue* get_SigPolicyHash();

		SB_DECLARE_PROPERTY_GET(TElXMLDigestAlgAndValue*, get_SigPolicyHash, TElXMLSignaturePolicyId, SigPolicyHash);
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		virtual TElXMLAnyTypeList* get_SigPolicyQualifiers();

		SB_DECLARE_PROPERTY_GET(TElXMLAnyTypeList*, get_SigPolicyQualifiers, TElXMLSignaturePolicyId, SigPolicyQualifiers);
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		virtual TElXMLTransformChain* get_TransformChain();

		SB_DECLARE_PROPERTY_GET(TElXMLTransformChain*, get_TransformChain, TElXMLSignaturePolicyId, TransformChain);
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

		TElXMLSignaturePolicyId(TElXMLSignaturePolicyIdHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSignaturePolicyId(TSBXAdESVersion AVersion);

		TElXMLSignaturePolicyId(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSignaturePolicyId(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSignaturePolicyId(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSignaturePolicyId(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLSignaturePolicyId();

};
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER
class TElXMLSignaturePolicyIdentifier: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignaturePolicyIdentifier)
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
		TElXMLSignaturePolicyId* _Inst_SignaturePolicyId;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

		void initInstances();

	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
		virtual TElXMLSignaturePolicyId* get_SignaturePolicyId();

		virtual void set_SignaturePolicyId(TElXMLSignaturePolicyId &Value);

		virtual void set_SignaturePolicyId(TElXMLSignaturePolicyId *Value);

		SB_DECLARE_PROPERTY(TElXMLSignaturePolicyId*, get_SignaturePolicyId, set_SignaturePolicyId, TElXMLSignaturePolicyIdentifier, SignaturePolicyId);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

		virtual bool get_SignaturePolicyImplied();

		virtual void set_SignaturePolicyImplied(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignaturePolicyImplied, set_SignaturePolicyImplied, TElXMLSignaturePolicyIdentifier, SignaturePolicyImplied);

		TElXMLSignaturePolicyIdentifier(TElXMLSignaturePolicyIdentifierHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion);

		TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSignaturePolicyIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLSignaturePolicyIdentifier();

};
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
class TElXMLCounterSignature: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCounterSignature)
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_Signature;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_Signature();

		virtual void set_Signature(TElXMLDOMElement &Value);

		virtual void set_Signature(TElXMLDOMElement *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMElement*, get_Signature, set_Signature, TElXMLCounterSignature, Signature);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElXMLCounterSignature(TElXMLCounterSignatureHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCounterSignature(TSBXAdESVersion AVersion);

		TElXMLCounterSignature(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCounterSignature(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCounterSignature(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCounterSignature(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLCounterSignature();

};
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST
class TElXMLCounterSignatureList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLCounterSignatureList)
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
		TElXMLCounterSignature* _Inst_CounterSignature;
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
		int32_t Add(TElXMLCounterSignature &ACounterSignature);

		int32_t Add(TElXMLCounterSignature *ACounterSignature);
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
		void Insert(int32_t Index, TElXMLCounterSignature &ACounterSignature);

		void Insert(int32_t Index, TElXMLCounterSignature *ACounterSignature);
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLCounterSignatureList, Count);

#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURE
		virtual TElXMLCounterSignature* get_CounterSignature(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURE */

		TElXMLCounterSignatureList(TElXMLCounterSignatureListHandle handle, TElOwnHandle ownHandle);

		TElXMLCounterSignatureList();

		virtual ~TElXMLCounterSignatureList();

};
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
class TElXMLDataObjectFormat: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLDataObjectFormat)
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
		TElXMLObjectIdentifier* _Inst_ObjectIdentifier;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Description(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Description(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Description(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Description(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
		virtual TElXMLObjectIdentifier* get_ObjectIdentifier();

		virtual void set_ObjectIdentifier(TElXMLObjectIdentifier &Value);

		virtual void set_ObjectIdentifier(TElXMLObjectIdentifier *Value);

		SB_DECLARE_PROPERTY(TElXMLObjectIdentifier*, get_ObjectIdentifier, set_ObjectIdentifier, TElXMLDataObjectFormat, ObjectIdentifier);
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

		virtual void get_MimeType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_MimeType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_MimeType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_MimeType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Encoding(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Encoding(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Encoding(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Encoding(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ObjectReference(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ObjectReference(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ObjectReference(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ObjectReference(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLDataObjectFormat(TElXMLDataObjectFormatHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLDataObjectFormat(TSBXAdESVersion AVersion);

		TElXMLDataObjectFormat(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLDataObjectFormat(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLDataObjectFormat(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLDataObjectFormat(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLDataObjectFormat();

};
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST
class TElXMLDataObjectFormatList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLDataObjectFormatList)
#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
		TElXMLDataObjectFormat* _Inst_DataObjectFormat;
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
		int32_t Add(TElXMLDataObjectFormat &ADataObjectFormat);

		int32_t Add(TElXMLDataObjectFormat *ADataObjectFormat);
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
		void Insert(int32_t Index, TElXMLDataObjectFormat &ADataObjectFormat);

		void Insert(int32_t Index, TElXMLDataObjectFormat *ADataObjectFormat);
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLDataObjectFormatList, Count);

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMAT
		virtual TElXMLDataObjectFormat* get_DataObjectFormat(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMAT */

		TElXMLDataObjectFormatList(TElXMLDataObjectFormatListHandle handle, TElOwnHandle ownHandle);

		TElXMLDataObjectFormatList();

		virtual ~TElXMLDataObjectFormatList();

};
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEQUALIFIER
class TElXMLCommitmentTypeQualifier: public TElXMLAnyType
{
	private:
		SB_DISABLE_COPY(TElXMLCommitmentTypeQualifier)
	public:
		TElXMLCommitmentTypeQualifier(TElXMLCommitmentTypeQualifierHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion);

		TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCommitmentTypeQualifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEQUALIFIER */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
class TElXMLCommitmentTypeIndication: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCommitmentTypeIndication)
#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
		TElXMLObjectIdentifier* _Inst_CommitmentTypeId;
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		TElXMLAnyTypeList* _Inst_CommitmentTypeQualifiers;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ObjectReference;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual bool get_AllSignedDataObjects();

		virtual void set_AllSignedDataObjects(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllSignedDataObjects, set_AllSignedDataObjects, TElXMLCommitmentTypeIndication, AllSignedDataObjects);

#ifdef SB_USE_CLASS_TELXMLOBJECTIDENTIFIER
		virtual TElXMLObjectIdentifier* get_CommitmentTypeId();

		SB_DECLARE_PROPERTY_GET(TElXMLObjectIdentifier*, get_CommitmentTypeId, TElXMLCommitmentTypeIndication, CommitmentTypeId);
#endif /* SB_USE_CLASS_TELXMLOBJECTIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		virtual TElXMLAnyTypeList* get_CommitmentTypeQualifiers();

		SB_DECLARE_PROPERTY_GET(TElXMLAnyTypeList*, get_CommitmentTypeQualifiers, TElXMLCommitmentTypeIndication, CommitmentTypeQualifiers);
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ObjectReference();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ObjectReference, TElXMLCommitmentTypeIndication, ObjectReference);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		TElXMLCommitmentTypeIndication(TElXMLCommitmentTypeIndicationHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion);

		TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCommitmentTypeIndication(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLCommitmentTypeIndication();

};
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST
class TElXMLCommitmentTypeIndicationList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLCommitmentTypeIndicationList)
#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
		TElXMLCommitmentTypeIndication* _Inst_CommitmentTypeIndication;
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
		int32_t Add(TElXMLCommitmentTypeIndication &ACommitmentTypeIndication);

		int32_t Add(TElXMLCommitmentTypeIndication *ACommitmentTypeIndication);
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
		void Insert(int32_t Index, TElXMLCommitmentTypeIndication &ACommitmentTypeIndication);

		void Insert(int32_t Index, TElXMLCommitmentTypeIndication *ACommitmentTypeIndication);
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLCommitmentTypeIndicationList, Count);

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION
		virtual TElXMLCommitmentTypeIndication* get_CommitmentTypeIndication(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATION */

		TElXMLCommitmentTypeIndicationList(TElXMLCommitmentTypeIndicationListHandle handle, TElOwnHandle ownHandle);

		TElXMLCommitmentTypeIndicationList();

		virtual ~TElXMLCommitmentTypeIndicationList();

};
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
class TElXMLSignatureProductionPlace: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignatureProductionPlace)
	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_City(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_City(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_City(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_City(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_StateOrProvince(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_StateOrProvince(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_StateOrProvince(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_StateOrProvince(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_PostalCode(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PostalCode(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_PostalCode(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_PostalCode(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_CountryName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CountryName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CountryName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_CountryName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSignatureProductionPlace(TElXMLSignatureProductionPlaceHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion);

		TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSignatureProductionPlace(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES
class TElXMLEncapsulatedX509Certificates: public TElXMLEncapsulatedPKIDataList
{
	private:
		SB_DISABLE_COPY(TElXMLEncapsulatedX509Certificates)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddCertificate(TElX509Certificate &ACert, TSBXAdESVersion AXAdESVersion);

		int32_t AddCertificate(TElX509Certificate *ACert, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificates(int32_t Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		TElXMLEncapsulatedX509Certificates(TElXMLEncapsulatedX509CertificatesHandle handle, TElOwnHandle ownHandle);

		TElXMLEncapsulatedX509Certificates();

		virtual ~TElXMLEncapsulatedX509Certificates();

};
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES */

#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLE
class TElXMLCertifiedRole: public TElXMLEncapsulatedPKIData
{
	private:
		SB_DISABLE_COPY(TElXMLCertifiedRole)
	public:
		TElXMLCertifiedRole(TElXMLCertifiedRoleHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCertifiedRole(TSBXAdESVersion AVersion);

		TElXMLCertifiedRole(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCertifiedRole(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCertifiedRole(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCertifiedRole(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLE */

#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST
class TElXMLCertifiedRolesList: public TElXMLEncapsulatedX509Certificates
{
	private:
		SB_DISABLE_COPY(TElXMLCertifiedRolesList)
	public:
		TElXMLCertifiedRolesList(TElXMLCertifiedRolesListHandle handle, TElOwnHandle ownHandle);

		TElXMLCertifiedRolesList();

};
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST */

#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLE
class TElXMLClaimedRole: public TElXMLAnyType
{
	private:
		SB_DISABLE_COPY(TElXMLClaimedRole)
	public:
		TElXMLClaimedRole(TElXMLClaimedRoleHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLClaimedRole(TSBXAdESVersion AVersion);

		TElXMLClaimedRole(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLClaimedRole(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLClaimedRole(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLClaimedRole(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLE */

#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLESLIST
class TElXMLClaimedRolesList: public TElXMLAnyTypeList
{
	private:
		SB_DISABLE_COPY(TElXMLClaimedRolesList)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		int32_t AddText(TSBXAdESVersion AVersion, TElXMLDOMDocument &OwnerDocument, const sb_u16string &Text);

		int32_t AddText(TSBXAdESVersion AVersion, TElXMLDOMDocument *OwnerDocument, const sb_u16string &Text);
#ifdef SB_U16STRING_USED
		int32_t AddText(TSBXAdESVersion AVersion, TElXMLDOMDocument &OwnerDocument, const std::wstring &Text);

		int32_t AddText(TSBXAdESVersion AVersion, TElXMLDOMDocument *OwnerDocument, const std::wstring &Text);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		TElXMLClaimedRolesList(TElXMLClaimedRolesListHandle handle, TElOwnHandle ownHandle);

		TElXMLClaimedRolesList();

};
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLESLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
class TElXMLSignerRole: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignerRole)
#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLESLIST
		TElXMLClaimedRolesList* _Inst_ClaimedRoles;
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLESLIST */
#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST
		TElXMLCertifiedRolesList* _Inst_CertifiedRoles;
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST */

		void initInstances();

	public:
		virtual void Assign(TElXMLAdESElement &Source);

		virtual void Assign(TElXMLAdESElement *Source);

		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLCLAIMEDROLESLIST
		virtual TElXMLClaimedRolesList* get_ClaimedRoles();

		SB_DECLARE_PROPERTY_GET(TElXMLClaimedRolesList*, get_ClaimedRoles, TElXMLSignerRole, ClaimedRoles);
#endif /* SB_USE_CLASS_TELXMLCLAIMEDROLESLIST */

#ifdef SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST
		virtual TElXMLCertifiedRolesList* get_CertifiedRoles();

		SB_DECLARE_PROPERTY_GET(TElXMLCertifiedRolesList*, get_CertifiedRoles, TElXMLSignerRole, CertifiedRoles);
#endif /* SB_USE_CLASS_TELXMLCERTIFIEDROLESLIST */

		TElXMLSignerRole(TElXMLSignerRoleHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSignerRole(TSBXAdESVersion AVersion);

		TElXMLSignerRole(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSignerRole(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSignerRole(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSignerRole(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLSignerRole();

};
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
class TElXMLCompleteCertificateRefs: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCompleteCertificateRefs)
#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
		TElXMLCertIDList* _Inst_CertRefs;
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
		virtual TElXMLCertIDList* get_CertRefs();

		SB_DECLARE_PROPERTY_GET(TElXMLCertIDList*, get_CertRefs, TElXMLCompleteCertificateRefs, CertRefs);
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */

		TElXMLCompleteCertificateRefs(TElXMLCompleteCertificateRefsHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion);

		TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCompleteCertificateRefs(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLCompleteCertificateRefs();

};
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELXMLCRLIDENTIFIER
class TElXMLCRLIdentifier: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCRLIdentifier)
	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Issuer(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Issuer(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Issuer(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Issuer(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_IssueTime(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_IssueTime(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_IssueTime(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_IssueTime(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_IssueTimeUTC();

		virtual void set_IssueTimeUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_IssueTimeUTC, set_IssueTimeUTC, TElXMLCRLIdentifier, IssueTimeUTC);

		virtual int32_t get_Number();

		virtual void set_Number(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Number, set_Number, TElXMLCRLIdentifier, Number);

		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLCRLIdentifier(TElXMLCRLIdentifierHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCRLIdentifier(TSBXAdESVersion AVersion);

		TElXMLCRLIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCRLIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCRLIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCRLIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLCRLIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLCRLREF
class TElXMLCRLRef: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCRLRef)
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
		TElXMLDigestAlgAndValue* _Inst_DigestAlgAndValue;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLCRLIDENTIFIER
		TElXMLCRLIdentifier* _Inst_CRLIdentifier;
#endif /* SB_USE_CLASS_TELXMLCRLIDENTIFIER */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		bool IsMatch(TElCertificateRevocationList &ACRL);

		bool IsMatch(TElCertificateRevocationList *ACRL);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
		virtual TElXMLDigestAlgAndValue* get_DigestAlgAndValue();

		SB_DECLARE_PROPERTY_GET(TElXMLDigestAlgAndValue*, get_DigestAlgAndValue, TElXMLCRLRef, DigestAlgAndValue);
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLCRLIDENTIFIER
		virtual TElXMLCRLIdentifier* get_CRLIdentifier();

		virtual void set_CRLIdentifier(TElXMLCRLIdentifier &Value);

		virtual void set_CRLIdentifier(TElXMLCRLIdentifier *Value);

		SB_DECLARE_PROPERTY(TElXMLCRLIdentifier*, get_CRLIdentifier, set_CRLIdentifier, TElXMLCRLRef, CRLIdentifier);
#endif /* SB_USE_CLASS_TELXMLCRLIDENTIFIER */

		TElXMLCRLRef(TElXMLCRLRefHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCRLRef(TSBXAdESVersion AVersion);

		TElXMLCRLRef(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCRLRef(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCRLRef(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCRLRef(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLCRLRef();

};
#endif /* SB_USE_CLASS_TELXMLCRLREF */

#ifdef SB_USE_CLASS_TELXMLCRLREFS
class TElXMLCRLRefs: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLCRLRefs)
#ifdef SB_USE_CLASS_TELXMLCRLREF
		TElXMLCRLRef* _Inst_CRLRef;
#endif /* SB_USE_CLASS_TELXMLCRLREF */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		int32_t AddCRL(TElCertificateRevocationList &ACRL, TSBXAdESVersion AXAdESVersion);

		int32_t AddCRL(TElCertificateRevocationList *ACRL, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		int32_t AddCRL(TElCertificateRevocationList &ACRL, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion);

		int32_t AddCRL(TElCertificateRevocationList *ACRL, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELXMLCRLREF
		int32_t Add(TElXMLCRLRef &ACRLRef);

		int32_t Add(TElXMLCRLRef *ACRLRef);
#endif /* SB_USE_CLASS_TELXMLCRLREF */

#ifdef SB_USE_CLASS_TELXMLCRLREF
		void Insert(int32_t Index, TElXMLCRLRef &ACRLRef);

		void Insert(int32_t Index, TElXMLCRLRef *ACRLRef);
#endif /* SB_USE_CLASS_TELXMLCRLREF */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLCRLRefs, Count);

#ifdef SB_USE_CLASS_TELXMLCRLREF
		virtual TElXMLCRLRef* get_CRLRef(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLCRLREF */

		TElXMLCRLRefs(TElXMLCRLRefsHandle handle, TElOwnHandle ownHandle);

		TElXMLCRLRefs();

		virtual ~TElXMLCRLRefs();

};
#endif /* SB_USE_CLASS_TELXMLCRLREFS */

#ifdef SB_USE_CLASS_TELXMLOCSPIDENTIFIER
class TElXMLOCSPIdentifier: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLOCSPIdentifier)
	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ResponderID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ResponderID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ResponderID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ResponderID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ProducedAt(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ProducedAt(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ProducedAt(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ProducedAt(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_ProducedAtUTC();

		virtual void set_ProducedAtUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ProducedAtUTC, set_ProducedAtUTC, TElXMLOCSPIdentifier, ProducedAtUTC);

		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TSBXAdESResponderIDType get_ResponderIDType();

		virtual void set_ResponderIDType(TSBXAdESResponderIDType Value);

		SB_DECLARE_PROPERTY(TSBXAdESResponderIDType, get_ResponderIDType, set_ResponderIDType, TElXMLOCSPIdentifier, ResponderIDType);

		TElXMLOCSPIdentifier(TElXMLOCSPIdentifierHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLOCSPIdentifier(TSBXAdESVersion AVersion);

		TElXMLOCSPIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLOCSPIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLOCSPIdentifier(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLOCSPIdentifier(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLOCSPIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLOCSPREF
class TElXMLOCSPRef: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLOCSPRef)
#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
		TElXMLDigestAlgAndValue* _Inst_DigestAlgAndValue;
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */
#ifdef SB_USE_CLASS_TELXMLOCSPIDENTIFIER
		TElXMLOCSPIdentifier* _Inst_OCSPIdentifier;
#endif /* SB_USE_CLASS_TELXMLOCSPIDENTIFIER */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		bool IsMatch(TElOCSPResponse &OCSPResponse);

		bool IsMatch(TElOCSPResponse *OCSPResponse);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELXMLDIGESTALGANDVALUE
		virtual TElXMLDigestAlgAndValue* get_DigestAlgAndValue();

		virtual void set_DigestAlgAndValue(TElXMLDigestAlgAndValue &Value);

		virtual void set_DigestAlgAndValue(TElXMLDigestAlgAndValue *Value);

		SB_DECLARE_PROPERTY(TElXMLDigestAlgAndValue*, get_DigestAlgAndValue, set_DigestAlgAndValue, TElXMLOCSPRef, DigestAlgAndValue);
#endif /* SB_USE_CLASS_TELXMLDIGESTALGANDVALUE */

#ifdef SB_USE_CLASS_TELXMLOCSPIDENTIFIER
		virtual TElXMLOCSPIdentifier* get_OCSPIdentifier();

		SB_DECLARE_PROPERTY_GET(TElXMLOCSPIdentifier*, get_OCSPIdentifier, TElXMLOCSPRef, OCSPIdentifier);
#endif /* SB_USE_CLASS_TELXMLOCSPIDENTIFIER */

		TElXMLOCSPRef(TElXMLOCSPRefHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLOCSPRef(TSBXAdESVersion AVersion);

		TElXMLOCSPRef(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLOCSPRef(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLOCSPRef(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLOCSPRef(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLOCSPRef();

};
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

#ifdef SB_USE_CLASS_TELXMLOCSPREFS
class TElXMLOCSPRefs: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLOCSPRefs)
#ifdef SB_USE_CLASS_TELXMLOCSPREF
		TElXMLOCSPRef* _Inst_OCSPRef;
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		int32_t AddOCSP(TElOCSPResponse &OCSPResponse, bool ByKey, TSBXAdESVersion AXAdESVersion);

		int32_t AddOCSP(TElOCSPResponse *OCSPResponse, bool ByKey, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		int32_t AddOCSP(TElOCSPResponse &OCSPResponse, bool ByKey, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion);

		int32_t AddOCSP(TElOCSPResponse *OCSPResponse, bool ByKey, TElXMLDigestMethod DigestMethod, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELXMLOCSPREF
		int32_t Add(TElXMLOCSPRef &AOCSPRef);

		int32_t Add(TElXMLOCSPRef *AOCSPRef);
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

#ifdef SB_USE_CLASS_TELXMLOCSPREF
		void Insert(int32_t Index, TElXMLOCSPRef &AOCSPRef);

		void Insert(int32_t Index, TElXMLOCSPRef *AOCSPRef);
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLOCSPRefs, Count);

#ifdef SB_USE_CLASS_TELXMLOCSPREF
		virtual TElXMLOCSPRef* get_OCSPRef(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLOCSPREF */

		TElXMLOCSPRefs(TElXMLOCSPRefsHandle handle, TElOwnHandle ownHandle);

		TElXMLOCSPRefs();

		virtual ~TElXMLOCSPRefs();

};
#endif /* SB_USE_CLASS_TELXMLOCSPREFS */

#ifdef SB_USE_CLASS_TELXMLOTHERREF
class TElXMLOtherRef: public TElXMLAnyType
{
	private:
		SB_DISABLE_COPY(TElXMLOtherRef)
	public:
		TElXMLOtherRef(TElXMLOtherRefHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLOtherRef(TSBXAdESVersion AVersion);

		TElXMLOtherRef(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLOtherRef(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLOtherRef(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLOtherRef(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLOTHERREF */

#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
class TElXMLCompleteRevocationRefs: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCompleteRevocationRefs)
#ifdef SB_USE_CLASS_TELXMLCRLREFS
		TElXMLCRLRefs* _Inst_CRLRefs;
#endif /* SB_USE_CLASS_TELXMLCRLREFS */
#ifdef SB_USE_CLASS_TELXMLOCSPREFS
		TElXMLOCSPRefs* _Inst_OCSPRefs;
#endif /* SB_USE_CLASS_TELXMLOCSPREFS */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		TElXMLAnyTypeList* _Inst_OtherRefs;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCRLREFS
		virtual TElXMLCRLRefs* get_CRLRefs();

		SB_DECLARE_PROPERTY_GET(TElXMLCRLRefs*, get_CRLRefs, TElXMLCompleteRevocationRefs, CRLRefs);
#endif /* SB_USE_CLASS_TELXMLCRLREFS */

#ifdef SB_USE_CLASS_TELXMLOCSPREFS
		virtual TElXMLOCSPRefs* get_OCSPRefs();

		SB_DECLARE_PROPERTY_GET(TElXMLOCSPRefs*, get_OCSPRefs, TElXMLCompleteRevocationRefs, OCSPRefs);
#endif /* SB_USE_CLASS_TELXMLOCSPREFS */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		virtual TElXMLAnyTypeList* get_OtherRefs();

		SB_DECLARE_PROPERTY_GET(TElXMLAnyTypeList*, get_OtherRefs, TElXMLCompleteRevocationRefs, OtherRefs);
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

		TElXMLCompleteRevocationRefs(TElXMLCompleteRevocationRefsHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion);

		TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCompleteRevocationRefs(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLCompleteRevocationRefs();

};
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
class TElXMLCertificateValues: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLCertificateValues)
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES
		TElXMLEncapsulatedX509Certificates* _Inst_EncapsulatedX509Certificates;
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		TElXMLAnyTypeList* _Inst_OtherCertificates;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES
		virtual TElXMLEncapsulatedX509Certificates* get_EncapsulatedX509Certificates();

		SB_DECLARE_PROPERTY_GET(TElXMLEncapsulatedX509Certificates*, get_EncapsulatedX509Certificates, TElXMLCertificateValues, EncapsulatedX509Certificates);
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDX509CERTIFICATES */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		virtual TElXMLAnyTypeList* get_OtherCertificates();

		SB_DECLARE_PROPERTY_GET(TElXMLAnyTypeList*, get_OtherCertificates, TElXMLCertificateValues, OtherCertificates);
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

		TElXMLCertificateValues(TElXMLCertificateValuesHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLCertificateValues(TSBXAdESVersion AVersion);

		TElXMLCertificateValues(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLCertificateValues(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLCertificateValues(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLCertificateValues(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLCertificateValues();

};
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDCRLVALUE
class TElXMLEncapsulatedCRLValue: public TElXMLEncapsulatedPKIData
{
	private:
		SB_DISABLE_COPY(TElXMLEncapsulatedCRLValue)
	public:
		TElXMLEncapsulatedCRLValue(TElXMLEncapsulatedCRLValueHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion);

		TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLEncapsulatedCRLValue(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDCRLVALUE */

#ifdef SB_USE_CLASS_TELXMLCRLVALUES
class TElXMLCRLValues: public TElXMLEncapsulatedPKIDataList
{
	private:
		SB_DISABLE_COPY(TElXMLCRLValues)
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		TElCertificateRevocationList* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		int32_t AddCRL(TElCertificateRevocationList &ACRL, TSBXAdESVersion AXAdESVersion);

		int32_t AddCRL(TElCertificateRevocationList *ACRL, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual TElCertificateRevocationList* get_CRLs(int32_t Index);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		TElXMLCRLValues(TElXMLCRLValuesHandle handle, TElOwnHandle ownHandle);

		TElXMLCRLValues();

		virtual ~TElXMLCRLValues();

};
#endif /* SB_USE_CLASS_TELXMLCRLVALUES */

#ifdef SB_USE_CLASS_TELXMLENCAPSULATEDOCSPVALUE
class TElXMLEncapsulatedOCSPValue: public TElXMLEncapsulatedPKIData
{
	private:
		SB_DISABLE_COPY(TElXMLEncapsulatedOCSPValue)
	public:
		TElXMLEncapsulatedOCSPValue(TElXMLEncapsulatedOCSPValueHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion);

		TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLEncapsulatedOCSPValue(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLENCAPSULATEDOCSPVALUE */

#ifdef SB_USE_CLASS_TELXMLOCSPVALUES
class TElXMLOCSPValues: public TElXMLEncapsulatedPKIDataList
{
	private:
		SB_DISABLE_COPY(TElXMLOCSPValues)
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		TElOCSPResponse* _Inst_OCSPResponses;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		int32_t AddOCSPResponse(TElOCSPResponse &AOCSPResponse, TSBXAdESVersion AXAdESVersion);

		int32_t AddOCSPResponse(TElOCSPResponse *AOCSPResponse, TSBXAdESVersion AXAdESVersion);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		virtual TElOCSPResponse* get_OCSPResponses(int32_t Index);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		TElXMLOCSPValues(TElXMLOCSPValuesHandle handle, TElOwnHandle ownHandle);

		TElXMLOCSPValues();

		virtual ~TElXMLOCSPValues();

};
#endif /* SB_USE_CLASS_TELXMLOCSPVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
class TElXMLRevocationValues: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLRevocationValues)
#ifdef SB_USE_CLASS_TELXMLCRLVALUES
		TElXMLCRLValues* _Inst_CRLValues;
#endif /* SB_USE_CLASS_TELXMLCRLVALUES */
#ifdef SB_USE_CLASS_TELXMLOCSPVALUES
		TElXMLOCSPValues* _Inst_OCSPValues;
#endif /* SB_USE_CLASS_TELXMLOCSPVALUES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		TElXMLAnyTypeList* _Inst_OtherValues;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCRLVALUES
		virtual TElXMLCRLValues* get_CRLValues();

		SB_DECLARE_PROPERTY_GET(TElXMLCRLValues*, get_CRLValues, TElXMLRevocationValues, CRLValues);
#endif /* SB_USE_CLASS_TELXMLCRLVALUES */

#ifdef SB_USE_CLASS_TELXMLOCSPVALUES
		virtual TElXMLOCSPValues* get_OCSPValues();

		SB_DECLARE_PROPERTY_GET(TElXMLOCSPValues*, get_OCSPValues, TElXMLRevocationValues, OCSPValues);
#endif /* SB_USE_CLASS_TELXMLOCSPVALUES */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		virtual TElXMLAnyTypeList* get_OtherValues();

		SB_DECLARE_PROPERTY_GET(TElXMLAnyTypeList*, get_OtherValues, TElXMLRevocationValues, OtherValues);
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

		TElXMLRevocationValues(TElXMLRevocationValuesHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLRevocationValues(TSBXAdESVersion AVersion);

		TElXMLRevocationValues(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLRevocationValues(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLRevocationValues(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLRevocationValues(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLRevocationValues();

};
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
class TElXMLTimeStampValidationData: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLTimeStampValidationData)
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
		TElXMLCertificateValues* _Inst_CertificateValues;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
		TElXMLRevocationValues* _Inst_RevocationValues;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
		virtual TElXMLCertificateValues* get_CertificateValues();

		virtual void set_CertificateValues(TElXMLCertificateValues &Value);

		virtual void set_CertificateValues(TElXMLCertificateValues *Value);

		SB_DECLARE_PROPERTY(TElXMLCertificateValues*, get_CertificateValues, set_CertificateValues, TElXMLTimeStampValidationData, CertificateValues);
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
		virtual TElXMLRevocationValues* get_RevocationValues();

		virtual void set_RevocationValues(TElXMLRevocationValues &Value);

		virtual void set_RevocationValues(TElXMLRevocationValues *Value);

		SB_DECLARE_PROPERTY(TElXMLRevocationValues*, get_RevocationValues, set_RevocationValues, TElXMLTimeStampValidationData, RevocationValues);
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

		TElXMLTimeStampValidationData(TElXMLTimeStampValidationDataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLTimeStampValidationData(TSBXAdESVersion AVersion);

		TElXMLTimeStampValidationData(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLTimeStampValidationData(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLTimeStampValidationData(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLTimeStampValidationData(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLTimeStampValidationData();

};
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
class TElXMLTimeStampValidationDataList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLTimeStampValidationDataList)
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
		TElXMLTimeStampValidationData* _Inst_TimeStampValidationData;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
		int32_t Add(TElXMLTimeStampValidationData &ATSPValidationData);

		int32_t Add(TElXMLTimeStampValidationData *ATSPValidationData);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
		void Insert(int32_t Index, TElXMLTimeStampValidationData &ATSPValidationData);

		void Insert(int32_t Index, TElXMLTimeStampValidationData *ATSPValidationData);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLTimeStampValidationDataList, Count);

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA
		virtual TElXMLTimeStampValidationData* get_TimeStampValidationData(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATA */

		TElXMLTimeStampValidationDataList(TElXMLTimeStampValidationDataListHandle handle, TElOwnHandle ownHandle);

		TElXMLTimeStampValidationDataList();

		virtual ~TElXMLTimeStampValidationDataList();

};
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */

#ifdef SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES
class TElXMLSignedDataObjectProperties: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignedDataObjectProperties)
#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST
		TElXMLDataObjectFormatList* _Inst_DataObjectFormats;
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST */
#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST
		TElXMLCommitmentTypeIndicationList* _Inst_CommitmentTypeIndications;
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		TElXMLCustomTimestampList* _Inst_AllDataObjectsTimestamps;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		TElXMLCustomTimestampList* _Inst_IndividualDataObjectsTimestamps;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST
		virtual TElXMLDataObjectFormatList* get_DataObjectFormats();

		SB_DECLARE_PROPERTY_GET(TElXMLDataObjectFormatList*, get_DataObjectFormats, TElXMLSignedDataObjectProperties, DataObjectFormats);
#endif /* SB_USE_CLASS_TELXMLDATAOBJECTFORMATLIST */

#ifdef SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST
		virtual TElXMLCommitmentTypeIndicationList* get_CommitmentTypeIndications();

		SB_DECLARE_PROPERTY_GET(TElXMLCommitmentTypeIndicationList*, get_CommitmentTypeIndications, TElXMLSignedDataObjectProperties, CommitmentTypeIndications);
#endif /* SB_USE_CLASS_TELXMLCOMMITMENTTYPEINDICATIONLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		virtual TElXMLCustomTimestampList* get_AllDataObjectsTimestamps();

		SB_DECLARE_PROPERTY_GET(TElXMLCustomTimestampList*, get_AllDataObjectsTimestamps, TElXMLSignedDataObjectProperties, AllDataObjectsTimestamps);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		virtual TElXMLCustomTimestampList* get_IndividualDataObjectsTimestamps();

		SB_DECLARE_PROPERTY_GET(TElXMLCustomTimestampList*, get_IndividualDataObjectsTimestamps, TElXMLSignedDataObjectProperties, IndividualDataObjectsTimestamps);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSignedDataObjectProperties(TElXMLSignedDataObjectPropertiesHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion);

		TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSignedDataObjectProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLSignedDataObjectProperties();

};
#endif /* SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDDATAOBJECTPROPERTY
class TElXMLUnsignedDataObjectProperty: public TElXMLAnyType
{
	private:
		SB_DISABLE_COPY(TElXMLUnsignedDataObjectProperty)
	public:
		TElXMLUnsignedDataObjectProperty(TElXMLUnsignedDataObjectPropertyHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion);

		TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLUnsignedDataObjectProperty(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDDATAOBJECTPROPERTY */

#ifdef SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES
class TElXMLSignedSignatureProperties: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignedSignatureProperties)
#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
		TElXMLCertIDList* _Inst_SigningCertificate;
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER
		TElXMLSignaturePolicyIdentifier* _Inst_SignaturePolicyIdentifier;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
		TElXMLSignatureProductionPlace* _Inst_SignatureProductionPlace;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
		TElXMLSignerRole* _Inst_SignerRole;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_SignedTime(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignedTime(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignedTime(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignedTime(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_SignedTimeUTC();

		virtual void set_SignedTimeUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SignedTimeUTC, set_SignedTimeUTC, TElXMLSignedSignatureProperties, SignedTimeUTC);

#ifdef SB_USE_CLASS_TELXMLCERTIDLIST
		virtual TElXMLCertIDList* get_SigningCertificate();

		SB_DECLARE_PROPERTY_GET(TElXMLCertIDList*, get_SigningCertificate, TElXMLSignedSignatureProperties, SigningCertificate);
#endif /* SB_USE_CLASS_TELXMLCERTIDLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER
		virtual TElXMLSignaturePolicyIdentifier* get_SignaturePolicyIdentifier();

		SB_DECLARE_PROPERTY_GET(TElXMLSignaturePolicyIdentifier*, get_SignaturePolicyIdentifier, TElXMLSignedSignatureProperties, SignaturePolicyIdentifier);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
		virtual TElXMLSignatureProductionPlace* get_SignatureProductionPlace();

		virtual void set_SignatureProductionPlace(TElXMLSignatureProductionPlace &Value);

		virtual void set_SignatureProductionPlace(TElXMLSignatureProductionPlace *Value);

		SB_DECLARE_PROPERTY(TElXMLSignatureProductionPlace*, get_SignatureProductionPlace, set_SignatureProductionPlace, TElXMLSignedSignatureProperties, SignatureProductionPlace);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
		virtual TElXMLSignerRole* get_SignerRole();

		virtual void set_SignerRole(TElXMLSignerRole &Value);

		virtual void set_SignerRole(TElXMLSignerRole *Value);

		SB_DECLARE_PROPERTY(TElXMLSignerRole*, get_SignerRole, set_SignerRole, TElXMLSignedSignatureProperties, SignerRole);
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSignedSignatureProperties(TElXMLSignedSignaturePropertiesHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion);

		TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSignedSignatureProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLSignedSignatureProperties();

};
#endif /* SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES
class TElXMLUnsignedSignatureProperties: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLUnsignedSignatureProperties)
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST
		TElXMLCounterSignatureList* _Inst_CounterSignatures;
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		TElXMLCustomTimestampList* _Inst_SignatureTimestamps;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
		TElXMLCompleteCertificateRefs* _Inst_CompleteCertificateRefs;
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
		TElXMLCompleteRevocationRefs* _Inst_CompleteRevocationRefs;
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
		TElXMLCompleteCertificateRefs* _Inst_AttributeCertificateRefs;
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
		TElXMLCompleteRevocationRefs* _Inst_AttributeRevocationRefs;
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		TElXMLCustomTimestampList* _Inst_SigAndRefsTimestamps;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		TElXMLCustomTimestampList* _Inst_RefsOnlyTimestamps;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
		TElXMLCertificateValues* _Inst_CertificateValues;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
		TElXMLRevocationValues* _Inst_RevocationValues;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
		TElXMLCertificateValues* _Inst_AttrAuthoritiesCertValues;
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */
#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
		TElXMLRevocationValues* _Inst_AttributeRevocationValues;
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		TElXMLCustomTimestampList* _Inst_ArchiveTimestamps;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		TElXMLCustomTimestampList* _Inst_ArchiveTimestampsV141;
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
		TElXMLTimeStampValidationDataList* _Inst_TimeStampValidationDataList;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TSBXAdESForm get_XAdESForm();

		virtual void set_XAdESForm(TSBXAdESForm Value);

		SB_DECLARE_PROPERTY(TSBXAdESForm, get_XAdESForm, set_XAdESForm, TElXMLUnsignedSignatureProperties, XAdESForm);

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST
		virtual TElXMLCounterSignatureList* get_CounterSignatures();

		SB_DECLARE_PROPERTY_GET(TElXMLCounterSignatureList*, get_CounterSignatures, TElXMLUnsignedSignatureProperties, CounterSignatures);
#endif /* SB_USE_CLASS_TELXMLCOUNTERSIGNATURELIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		virtual TElXMLCustomTimestampList* get_SignatureTimestamps();

		SB_DECLARE_PROPERTY_GET(TElXMLCustomTimestampList*, get_SignatureTimestamps, TElXMLUnsignedSignatureProperties, SignatureTimestamps);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
		virtual TElXMLCompleteCertificateRefs* get_CompleteCertificateRefs();

		virtual void set_CompleteCertificateRefs(TElXMLCompleteCertificateRefs &Value);

		virtual void set_CompleteCertificateRefs(TElXMLCompleteCertificateRefs *Value);

		SB_DECLARE_PROPERTY(TElXMLCompleteCertificateRefs*, get_CompleteCertificateRefs, set_CompleteCertificateRefs, TElXMLUnsignedSignatureProperties, CompleteCertificateRefs);
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
		virtual TElXMLCompleteRevocationRefs* get_CompleteRevocationRefs();

		virtual void set_CompleteRevocationRefs(TElXMLCompleteRevocationRefs &Value);

		virtual void set_CompleteRevocationRefs(TElXMLCompleteRevocationRefs *Value);

		SB_DECLARE_PROPERTY(TElXMLCompleteRevocationRefs*, get_CompleteRevocationRefs, set_CompleteRevocationRefs, TElXMLUnsignedSignatureProperties, CompleteRevocationRefs);
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS
		virtual TElXMLCompleteCertificateRefs* get_AttributeCertificateRefs();

		virtual void set_AttributeCertificateRefs(TElXMLCompleteCertificateRefs &Value);

		virtual void set_AttributeCertificateRefs(TElXMLCompleteCertificateRefs *Value);

		SB_DECLARE_PROPERTY(TElXMLCompleteCertificateRefs*, get_AttributeCertificateRefs, set_AttributeCertificateRefs, TElXMLUnsignedSignatureProperties, AttributeCertificateRefs);
#endif /* SB_USE_CLASS_TELXMLCOMPLETECERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS
		virtual TElXMLCompleteRevocationRefs* get_AttributeRevocationRefs();

		virtual void set_AttributeRevocationRefs(TElXMLCompleteRevocationRefs &Value);

		virtual void set_AttributeRevocationRefs(TElXMLCompleteRevocationRefs *Value);

		SB_DECLARE_PROPERTY(TElXMLCompleteRevocationRefs*, get_AttributeRevocationRefs, set_AttributeRevocationRefs, TElXMLUnsignedSignatureProperties, AttributeRevocationRefs);
#endif /* SB_USE_CLASS_TELXMLCOMPLETEREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		virtual TElXMLCustomTimestampList* get_SigAndRefsTimestamps();

		SB_DECLARE_PROPERTY_GET(TElXMLCustomTimestampList*, get_SigAndRefsTimestamps, TElXMLUnsignedSignatureProperties, SigAndRefsTimestamps);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		virtual TElXMLCustomTimestampList* get_RefsOnlyTimestamps();

		SB_DECLARE_PROPERTY_GET(TElXMLCustomTimestampList*, get_RefsOnlyTimestamps, TElXMLUnsignedSignatureProperties, RefsOnlyTimestamps);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
		virtual TElXMLCertificateValues* get_CertificateValues();

		virtual void set_CertificateValues(TElXMLCertificateValues &Value);

		virtual void set_CertificateValues(TElXMLCertificateValues *Value);

		SB_DECLARE_PROPERTY(TElXMLCertificateValues*, get_CertificateValues, set_CertificateValues, TElXMLUnsignedSignatureProperties, CertificateValues);
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
		virtual TElXMLRevocationValues* get_RevocationValues();

		virtual void set_RevocationValues(TElXMLRevocationValues &Value);

		virtual void set_RevocationValues(TElXMLRevocationValues *Value);

		SB_DECLARE_PROPERTY(TElXMLRevocationValues*, get_RevocationValues, set_RevocationValues, TElXMLUnsignedSignatureProperties, RevocationValues);
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELXMLCERTIFICATEVALUES
		virtual TElXMLCertificateValues* get_AttrAuthoritiesCertValues();

		virtual void set_AttrAuthoritiesCertValues(TElXMLCertificateValues &Value);

		virtual void set_AttrAuthoritiesCertValues(TElXMLCertificateValues *Value);

		SB_DECLARE_PROPERTY(TElXMLCertificateValues*, get_AttrAuthoritiesCertValues, set_AttrAuthoritiesCertValues, TElXMLUnsignedSignatureProperties, AttrAuthoritiesCertValues);
#endif /* SB_USE_CLASS_TELXMLCERTIFICATEVALUES */

#ifdef SB_USE_CLASS_TELXMLREVOCATIONVALUES
		virtual TElXMLRevocationValues* get_AttributeRevocationValues();

		virtual void set_AttributeRevocationValues(TElXMLRevocationValues &Value);

		virtual void set_AttributeRevocationValues(TElXMLRevocationValues *Value);

		SB_DECLARE_PROPERTY(TElXMLRevocationValues*, get_AttributeRevocationValues, set_AttributeRevocationValues, TElXMLUnsignedSignatureProperties, AttributeRevocationValues);
#endif /* SB_USE_CLASS_TELXMLREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		virtual TElXMLCustomTimestampList* get_ArchiveTimestamps();

		SB_DECLARE_PROPERTY_GET(TElXMLCustomTimestampList*, get_ArchiveTimestamps, TElXMLUnsignedSignatureProperties, ArchiveTimestamps);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST
		virtual TElXMLCustomTimestampList* get_ArchiveTimestampsV141();

		SB_DECLARE_PROPERTY_GET(TElXMLCustomTimestampList*, get_ArchiveTimestampsV141, TElXMLUnsignedSignatureProperties, ArchiveTimestampsV141);
#endif /* SB_USE_CLASS_TELXMLCUSTOMTIMESTAMPLIST */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
		virtual TElXMLTimeStampValidationDataList* get_TimeStampValidationDataList();

		SB_DECLARE_PROPERTY_GET(TElXMLTimeStampValidationDataList*, get_TimeStampValidationDataList, TElXMLUnsignedSignatureProperties, TimeStampValidationDataList);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */

		TElXMLUnsignedSignatureProperties(TElXMLUnsignedSignaturePropertiesHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion);

		TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLUnsignedSignatureProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLUnsignedSignatureProperties();

};
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLSIGNEDPROPERTIES
class TElXMLSignedProperties: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignedProperties)
#ifdef SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES
		TElXMLSignedSignatureProperties* _Inst_SignedSignatureProperties;
#endif /* SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES
		TElXMLSignedDataObjectProperties* _Inst_SignedDataObjectProperties;
#endif /* SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES
		virtual TElXMLSignedSignatureProperties* get_SignedSignatureProperties();

		virtual void set_SignedSignatureProperties(TElXMLSignedSignatureProperties &Value);

		virtual void set_SignedSignatureProperties(TElXMLSignedSignatureProperties *Value);

		SB_DECLARE_PROPERTY(TElXMLSignedSignatureProperties*, get_SignedSignatureProperties, set_SignedSignatureProperties, TElXMLSignedProperties, SignedSignatureProperties);
#endif /* SB_USE_CLASS_TELXMLSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES
		virtual TElXMLSignedDataObjectProperties* get_SignedDataObjectProperties();

		virtual void set_SignedDataObjectProperties(TElXMLSignedDataObjectProperties &Value);

		virtual void set_SignedDataObjectProperties(TElXMLSignedDataObjectProperties *Value);

		SB_DECLARE_PROPERTY(TElXMLSignedDataObjectProperties*, get_SignedDataObjectProperties, set_SignedDataObjectProperties, TElXMLSignedProperties, SignedDataObjectProperties);
#endif /* SB_USE_CLASS_TELXMLSIGNEDDATAOBJECTPROPERTIES */

		TElXMLSignedProperties(TElXMLSignedPropertiesHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSignedProperties(TSBXAdESVersion AVersion);

		TElXMLSignedProperties(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSignedProperties(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLSignedProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLSignedProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLSignedProperties();

};
#endif /* SB_USE_CLASS_TELXMLSIGNEDPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES
class TElXMLUnsignedProperties: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLUnsignedProperties)
#ifdef SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES
		TElXMLUnsignedSignatureProperties* _Inst_UnsignedSignatureProperties;
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		TElXMLAnyTypeList* _Inst_UnsignedDataObjectProperties;
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES
		virtual TElXMLUnsignedSignatureProperties* get_UnsignedSignatureProperties();

		virtual void set_UnsignedSignatureProperties(TElXMLUnsignedSignatureProperties &Value);

		virtual void set_UnsignedSignatureProperties(TElXMLUnsignedSignatureProperties *Value);

		SB_DECLARE_PROPERTY(TElXMLUnsignedSignatureProperties*, get_UnsignedSignatureProperties, set_UnsignedSignatureProperties, TElXMLUnsignedProperties, UnsignedSignatureProperties);
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLANYTYPELIST
		virtual TElXMLAnyTypeList* get_UnsignedDataObjectProperties();

		SB_DECLARE_PROPERTY_GET(TElXMLAnyTypeList*, get_UnsignedDataObjectProperties, TElXMLUnsignedProperties, UnsignedDataObjectProperties);
#endif /* SB_USE_CLASS_TELXMLANYTYPELIST */

		TElXMLUnsignedProperties(TElXMLUnsignedPropertiesHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLUnsignedProperties(TSBXAdESVersion AVersion);

		TElXMLUnsignedProperties(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLUnsignedProperties(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLUnsignedProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLUnsignedProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLUnsignedProperties();

};
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
class TElXMLQualifyingProperties: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLQualifyingProperties)
#ifdef SB_USE_CLASS_TELXMLSIGNEDPROPERTIES
		TElXMLSignedProperties* _Inst_SignedProperties;
#endif /* SB_USE_CLASS_TELXMLSIGNEDPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES
		TElXMLUnsignedProperties* _Inst_UnsignedProperties;
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_XAdESPrefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_XAdESPrefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_XAdESPrefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_XAdESPrefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_XAdESv141Prefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_XAdESv141Prefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_XAdESv141Prefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_XAdESv141Prefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Target(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Target(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Target(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Target(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLSIGNEDPROPERTIES
		virtual TElXMLSignedProperties* get_SignedProperties();

		virtual void set_SignedProperties(TElXMLSignedProperties &Value);

		virtual void set_SignedProperties(TElXMLSignedProperties *Value);

		SB_DECLARE_PROPERTY(TElXMLSignedProperties*, get_SignedProperties, set_SignedProperties, TElXMLQualifyingProperties, SignedProperties);
#endif /* SB_USE_CLASS_TELXMLSIGNEDPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES
		virtual TElXMLUnsignedProperties* get_UnsignedProperties();

		virtual void set_UnsignedProperties(TElXMLUnsignedProperties &Value);

		virtual void set_UnsignedProperties(TElXMLUnsignedProperties *Value);

		SB_DECLARE_PROPERTY(TElXMLUnsignedProperties*, get_UnsignedProperties, set_UnsignedProperties, TElXMLQualifyingProperties, UnsignedProperties);
#endif /* SB_USE_CLASS_TELXMLUNSIGNEDPROPERTIES */

		TElXMLQualifyingProperties(TElXMLQualifyingPropertiesHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLQualifyingProperties(TSBXAdESVersion AVersion);

		TElXMLQualifyingProperties(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLQualifyingProperties(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLQualifyingProperties(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLQualifyingProperties(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLQualifyingProperties();

};
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
class TElXMLQualifyingPropertiesReference: public TElXMLAdESElement
{
	private:
		SB_DISABLE_COPY(TElXMLQualifyingPropertiesReference)
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		TElXMLTransformChain* _Inst_TransformChain;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_QualifyingProperties;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		void initInstances();

	public:
		virtual void Clear();

		virtual bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		virtual TElXMLTransformChain* get_TransformChain();

		SB_DECLARE_PROPERTY_GET(TElXMLTransformChain*, get_TransformChain, TElXMLQualifyingPropertiesReference, TransformChain);
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_QualifyingProperties();

		virtual void set_QualifyingProperties(TElXMLDOMElement &Value);

		virtual void set_QualifyingProperties(TElXMLDOMElement *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMElement*, get_QualifyingProperties, set_QualifyingProperties, TElXMLQualifyingPropertiesReference, QualifyingProperties);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElXMLQualifyingPropertiesReference(TElXMLQualifyingPropertiesReferenceHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion);

		TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
		TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion, const sb_u16string &AName, bool SupportedV141);

#ifdef SB_U16STRING_USED
		TElXMLQualifyingPropertiesReference(TSBXAdESVersion AVersion, const std::wstring &AName, bool SupportedV141);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLQualifyingPropertiesReference();

};
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
class TElXMLQualifyingPropertiesReferenceList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLQualifyingPropertiesReferenceList)
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
		TElXMLQualifyingPropertiesReference* _Inst_QualifyingPropertiesReference;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
		int32_t Add(TElXMLQualifyingPropertiesReference &AQualifyingPropertiesRef);

		int32_t Add(TElXMLQualifyingPropertiesReference *AQualifyingPropertiesRef);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
		void Insert(int32_t Index, TElXMLQualifyingPropertiesReference &AQualifyingPropertiesRef);

		void Insert(int32_t Index, TElXMLQualifyingPropertiesReference *AQualifyingPropertiesRef);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLQualifyingPropertiesReferenceList, Count);

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE
		virtual TElXMLQualifyingPropertiesReference* get_QualifyingPropertiesReference(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCE */

		TElXMLQualifyingPropertiesReferenceList(TElXMLQualifyingPropertiesReferenceListHandle handle, TElOwnHandle ownHandle);

		TElXMLQualifyingPropertiesReferenceList();

		virtual ~TElXMLQualifyingPropertiesReferenceList();

};
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

#ifdef SB_USE_GLOBAL_PROCS_XMLADES

TSBXAdESVersion GetXAdESVersion(const sb_u16string &NamespaceURI);
#ifdef SB_U16STRING_USED
TSBXAdESVersion GetXAdESVersion(const std::wstring &NamespaceURI);
#endif /* SB_U16STRING_USED */

void GetXAdESNamespaceURI(TSBXAdESVersion Version, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetXAdESNamespaceURI(TSBXAdESVersion Version, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void GetXAdESNamespaceURI(TSBXAdESVersion Version, bool SupportedV141, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetXAdESNamespaceURI(TSBXAdESVersion Version, bool SupportedV141, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void GetXAdESReferenceType(TSBXAdESVersion Version, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetXAdESReferenceType(TSBXAdESVersion Version, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void XAdESVersionToString(TSBXAdESVersion XAdESVersion, std::string &OutResult);

void XAdESFormToString(TSBXAdESForm XAdESForm, std::string &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_XMLADES */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLADES
SB_IMPORT uint32_t SB_APIENTRY SBXMLAdES_GetXAdESVersion(const sb_char16_t * pcNamespaceURI, int32_t szNamespaceURI, TSBXAdESVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLAdES_GetXAdESNamespaceURI(TSBXAdESVersionRaw Version, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLAdES_GetXAdESNamespaceURI_1(TSBXAdESVersionRaw Version, int8_t SupportedV141, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLAdES_GetXAdESReferenceType(TSBXAdESVersionRaw Version, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLAdES_XAdESVersionToString(TSBXAdESVersionRaw XAdESVersion, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLAdES_XAdESFormToString(TSBXAdESFormRaw XAdESForm, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLADES */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLADES */

