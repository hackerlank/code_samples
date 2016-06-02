#ifndef __INC_SBXMLADESINTF
#define __INC_SBXMLADESINTF

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbcustomcertstorage.h"
#include "sbcertvalidator.h"
#include "sbcrl.h"
#include "sbcrlstorage.h"
#include "sbocspclient.h"
#include "sbtspclient.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbxmlades.h"
#include "sbxmlcore.h"
#include "sbxmldefs.h"
#include "sbxmlsec.h"
#include "sbxmlutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElXAdESProcessorHandle;

typedef TElXAdESProcessorHandle ElXAdESProcessorHandle;

typedef TElClassHandle TElXAdESSignerHandle;

typedef TElXAdESSignerHandle ElXAdESSignerHandle;

typedef TElClassHandle TElXAdESVerifierHandle;

typedef TElXAdESVerifierHandle ElXAdESVerifierHandle;

typedef uint8_t TElXAdESIncludedPropertyRaw;

typedef enum
{
	xipSignerRole = 0,
	xipProductionPlace = 1
} TElXAdESIncludedProperty;

typedef uint32_t TElXAdESIncludedPropertiesRaw;

typedef enum 
{
	f_xipSignerRole = 1,
	f_xipProductionPlace = 2
} TElXAdESIncludedProperties;

typedef TElXAdESIncludedProperty ElXAdESIncludedProperty;

typedef TElXAdESIncludedProperties ElXAdESIncludedProperties;

typedef uint8_t TSBXAdESOptionRaw;

typedef enum
{
	xoUseHexSerialNumber = 0
} TSBXAdESOption;

typedef uint32_t TSBXAdESOptionsRaw;

typedef enum 
{
	f_xoUseHexSerialNumber = 1
} TSBXAdESOptions;

typedef uint8_t TSBXAdESValidityRaw;

typedef enum
{
	xsvInvalid = 0,
	xsvIncomplete = 1,
	xsvValid = 2
} TSBXAdESValidity;

typedef uint8_t TSBXAdESValidityReasonRaw;

typedef enum
{
	xvrInternalError = 0,
	xvrNotSigned = 1,
	xvrNoSigningCertificate = 2,
	xvrSigningCertificateNotSigned = 3,
	xvrSigningCertificateIncomplete = 4,
	xvrSigningCertificateInvalid = 5,
	xvrIndividualDataObjectsTimestampInvalid = 6,
	xvrIndividualDataObjectsTimestampIncomplete = 7,
	xvrAllDataObjectsTimestampInvalid = 8,
	xvrAllDataObjectsTimestampIncomplete = 9,
	xvrSignatureTimestampInvalid = 10,
	xvrSignatureTimestampIncomplete = 11,
	xvrRefsOnlyTimestampInvalid = 12,
	xvrRefsOnlyTimestampIncomplete = 13,
	xvrSigAndRefsTimestampInvalid = 14,
	xvrSigAndRefsTimestampIncomplete = 15,
	xvrArchiveTimestampInvalid = 16,
	xvrArchiveTimestampIncomplete = 17,
	xvrInconsistentSigningCertificate = 18
} TSBXAdESValidityReason;

typedef uint32_t TSBXAdESValidityReasonsRaw;

typedef enum 
{
	f_xvrInternalError = 1,
	f_xvrNotSigned = 2,
	f_xvrNoSigningCertificate = 4,
	f_xvrSigningCertificateNotSigned = 8,
	f_xvrSigningCertificateIncomplete = 16,
	f_xvrSigningCertificateInvalid = 32,
	f_xvrIndividualDataObjectsTimestampInvalid = 64,
	f_xvrIndividualDataObjectsTimestampIncomplete = 128,
	f_xvrAllDataObjectsTimestampInvalid = 256,
	f_xvrAllDataObjectsTimestampIncomplete = 512,
	f_xvrSignatureTimestampInvalid = 1024,
	f_xvrSignatureTimestampIncomplete = 2048,
	f_xvrRefsOnlyTimestampInvalid = 4096,
	f_xvrRefsOnlyTimestampIncomplete = 8192,
	f_xvrSigAndRefsTimestampInvalid = 16384,
	f_xvrSigAndRefsTimestampIncomplete = 32768,
	f_xvrArchiveTimestampInvalid = 65536,
	f_xvrArchiveTimestampIncomplete = 131072,
	f_xvrInconsistentSigningCertificate = 262144
} TSBXAdESValidityReasons;

typedef void (SB_CALLBACK *TSBXAdESCertificateNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElCertificateLookupHandle Lookup, TElX509CertificateHandle * Cert);

typedef void (SB_CALLBACK *TSBXAdESBeforeCertificateValidateEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle Cert, TElX509CertificateValidatorHandle CertValidator);

typedef void (SB_CALLBACK *TSBXAdESAfterCertificateValidateEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle Cert, TElX509CertificateValidatorHandle CertValidator, TSBCertificateValidityRaw Validity, TSBCertificateValidityReasonRaw Reason);

typedef void (SB_CALLBACK *TSBXAdESStoreCertificateEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle Cert, sb_char16_t * pcURI, int32_t * szURI);

typedef void (SB_CALLBACK *TSBXAdESStoreCRLEvent)(void * _ObjectData, TObjectHandle Sender, TElCertificateRevocationListHandle CRL, sb_char16_t * pcURI, int32_t * szURI);

typedef void (SB_CALLBACK *TSBXAdESStoreOCSPResponseEvent)(void * _ObjectData, TObjectHandle Sender, TElOCSPResponseHandle OCSPResponse, sb_char16_t * pcURI, int32_t * szURI);

typedef void (SB_CALLBACK *TSBXAdESRetrieveCertificateEvent)(void * _ObjectData, TObjectHandle Sender, const sb_char16_t * pcURI, int32_t szURI, TElXMLCertIDHandle CertID, TElX509CertificateHandle * Cert, int8_t * ReleaseObj);

typedef void (SB_CALLBACK *TSBXAdESRetrieveCRLEvent)(void * _ObjectData, TObjectHandle Sender, const sb_char16_t * pcURI, int32_t szURI, TElXMLCRLRefHandle CRLRef, TElCertificateRevocationListHandle * CRL, int8_t * ReleaseObj);

typedef void (SB_CALLBACK *TSBXAdESRetrieveOCSPResponseEvent)(void * _ObjectData, TObjectHandle Sender, const sb_char16_t * pcURI, int32_t szURI, TElXMLOCSPRefHandle OCSPRef, TElOCSPResponseHandle * OCSPResponse, int8_t * ReleaseObj);

typedef void (SB_CALLBACK *TSBXAdESBeforeSaveUnsignedPropertyEvent)(void * _ObjectData, TObjectHandle Sender, TElXMLAdESElementHandle Element);

#ifdef SB_USE_CLASS_TELXADESPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddTimestampValidationData(TElXAdESProcessorHandle _Handle, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddTimestampValidationData_1(TElXAdESProcessorHandle _Handle, TElXMLCustomFormatterHandle Formatter, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddTimestampValidationData_2(TElXAdESProcessorHandle _Handle, TElClientTSPInfoHandle TSPInfo, const sb_char16_t * pcURI, int32_t szURI, TElXMLCustomFormatterHandle Formatter, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddTimestampValidationData_3(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddTimestampValidationData_4(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses, const sb_char16_t * pcURI, int32_t szURI, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddCounterSignature(TElXAdESProcessorHandle _Handle, TElXMLProcessorHandle Signer);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddCounterSignature_1(TElXAdESProcessorHandle _Handle, TElXMLProcessorHandle Signer, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddSignatureTimestamp(TElXAdESProcessorHandle _Handle, TElCustomTSPClientHandle ATSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddSignatureTimestamp_1(TElXAdESProcessorHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddRefsOnlyTimestamp(TElXAdESProcessorHandle _Handle, TElCustomTSPClientHandle ATSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddRefsOnlyTimestamp_1(TElXAdESProcessorHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddSigAndRefsTimestamp(TElXAdESProcessorHandle _Handle, TElCustomTSPClientHandle ATSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddSigAndRefsTimestamp_1(TElXAdESProcessorHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddArchiveTimestamp(TElXAdESProcessorHandle _Handle, TElCustomTSPClientHandle ATSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddArchiveTimestamp_1(TElXAdESProcessorHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddAttributeCertificateRefs(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddAttributeCertificateRefs_1(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs, TElXMLDigestMethodRaw DigestMethod, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddCompleteCertificateRefs(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddCompleteCertificateRefs_1(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs, TElXMLDigestMethodRaw DigestMethod, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddAttributeRevocationRefs(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddAttributeRevocationRefs_1(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses, TElXMLDigestMethodRaw DigestMethod, int8_t ResponderIdByKey, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddCompleteRevocationRefs(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddCompleteRevocationRefs_1(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses, TElXMLDigestMethodRaw DigestMethod, int8_t ResponderIdByKey, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddValidationDataRefs(TElXAdESProcessorHandle _Handle, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddValidationDataRefs_1(TElXAdESProcessorHandle _Handle, TElX509CertificateHandle SigningCertificate, TElXMLDigestMethodRaw DigestMethod, int8_t ResponderIdByKey, TElXMLCustomFormatterHandle Formatter, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddValidationDataRefs_2(TElXAdESProcessorHandle _Handle, TElX509CertificateHandle SigningCertificate, int8_t IncludeCRL, int8_t IncludeOCSP, TElXMLDigestMethodRaw DigestMethod, int8_t ResponderIdByKey, TElXMLCustomFormatterHandle Formatter, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddAttrAuthoritiesCertValues(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddAttrAuthoritiesCertValues_1(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddCertificateValues(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddCertificateValues_1(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddAttributeRevocationValues(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddAttributeRevocationValues_1(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddRevocationValues(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddRevocationValues_1(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs, TListHandle OCSPResponses, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddValidationDataValues(TElXAdESProcessorHandle _Handle, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddValidationDataValues_1(TElXAdESProcessorHandle _Handle, TElX509CertificateHandle SigningCertificate, TElXMLCustomFormatterHandle Formatter, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_AddValidationDataValues_2(TElXAdESProcessorHandle _Handle, TElX509CertificateHandle SigningCertificate, int8_t IncludeCRL, int8_t IncludeOCSP, TElXMLCustomFormatterHandle Formatter, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_GetSignerCertificate(TElXAdESProcessorHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_ClearPKICache(TElXAdESProcessorHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_ExtractAllCertificates(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Certs);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_ExtractAllCRLs(TElXAdESProcessorHandle _Handle, TElCustomCRLStorageHandle CRLs);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_ExtractAllOCSPResponses(TElXAdESProcessorHandle _Handle, TListHandle OCSPResponses);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_GracePeriod(TElXAdESProcessorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_GracePeriod(TElXAdESProcessorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_OfflineMode(TElXAdESProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_OfflineMode(TElXAdESProcessorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_TimestampCanonicalizationMethod(TElXAdESProcessorHandle _Handle, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_TimestampCanonicalizationMethod(TElXAdESProcessorHandle _Handle, TElXMLCanonicalizationMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_XAdESOptions(TElXAdESProcessorHandle _Handle, TSBXAdESOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_XAdESOptions(TElXAdESProcessorHandle _Handle, TSBXAdESOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_ValidationMoment(TElXAdESProcessorHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_ValidationMoment(TElXAdESProcessorHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_ForceCompleteChainValidation(TElXAdESProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_ForceCompleteChainValidation(TElXAdESProcessorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_IgnoreChainValidationErrors(TElXAdESProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_IgnoreChainValidationErrors(TElXAdESProcessorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_TrustedCertificates(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_TrustedCertificates(TElXAdESProcessorHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_CryptoProviderManager(TElXAdESProcessorHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_CryptoProviderManager(TElXAdESProcessorHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_CertificateValidator(TElXAdESProcessorHandle _Handle, TElX509CertificateValidatorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_CertificateValidator(TElXAdESProcessorHandle _Handle, TElX509CertificateValidatorHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_OnBeforeSaveUnsignedProperty(TElXAdESProcessorHandle _Handle, TSBXAdESBeforeSaveUnsignedPropertyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_OnBeforeSaveUnsignedProperty(TElXAdESProcessorHandle _Handle, TSBXAdESBeforeSaveUnsignedPropertyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_OnBeforeCertificateValidate(TElXAdESProcessorHandle _Handle, TSBXAdESBeforeCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_OnBeforeCertificateValidate(TElXAdESProcessorHandle _Handle, TSBXAdESBeforeCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_OnAfterCertificateValidate(TElXAdESProcessorHandle _Handle, TSBXAdESAfterCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_OnAfterCertificateValidate(TElXAdESProcessorHandle _Handle, TSBXAdESAfterCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_OnCertificateNeeded(TElXAdESProcessorHandle _Handle, TSBXAdESCertificateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_OnCertificateNeeded(TElXAdESProcessorHandle _Handle, TSBXAdESCertificateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_OnStoreCertificate(TElXAdESProcessorHandle _Handle, TSBXAdESStoreCertificateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_OnStoreCertificate(TElXAdESProcessorHandle _Handle, TSBXAdESStoreCertificateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_OnStoreCRL(TElXAdESProcessorHandle _Handle, TSBXAdESStoreCRLEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_OnStoreCRL(TElXAdESProcessorHandle _Handle, TSBXAdESStoreCRLEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_get_OnStoreOCSPResponse(TElXAdESProcessorHandle _Handle, TSBXAdESStoreOCSPResponseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_set_OnStoreOCSPResponse(TElXAdESProcessorHandle _Handle, TSBXAdESStoreOCSPResponseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESProcessor_Create(TComponentHandle AOwner, TElXAdESProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

#ifdef SB_USE_CLASS_TELXADESSIGNER
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_TimestampDataObjects(TElXAdESSignerHandle _Handle, TElXMLReferenceListHandle AReferences, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_AddUnsignedObjects(TElXAdESSignerHandle _Handle, TElXMLDOMElementHandle SignedInfo, TElXMLDOMElementHandle SignatureValue, TElXMLKeyInfoHandle KeyInfo, TElXMLReferenceListHandle AReferences, TObjectHandle AObjects, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_SetSigningCertificates(TElXAdESSignerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_SetTSPClient(TElXAdESSignerHandle _Handle, TElCustomTSPClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_SetXAdESForm(TElXAdESSignerHandle _Handle, TSBXAdESFormRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_SetXAdESVersion(TElXAdESSignerHandle _Handle, TSBXAdESVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_Clear(TElXAdESSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_Generate(TElXAdESSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_Generate_1(TElXAdESSignerHandle _Handle, TSBXAdESFormRaw AXAdESForm);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_AddCounterSignature(TElXAdESSignerHandle _Handle, TElXMLProcessorHandle Signer, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_AddAllDataObjectsTimestamp(TElXAdESSignerHandle _Handle, TElCustomTSPClientHandle ATSPClient);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_AddSignatureTimestamp(TElXAdESSignerHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_AddRefsOnlyTimestamp(TElXAdESSignerHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_AddSigAndRefsTimestamp(TElXAdESSignerHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_AddArchiveTimestamp(TElXAdESSignerHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_PolicyId(TElXAdESSignerHandle _Handle, TElXMLSignaturePolicyIdHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_PolicyId(TElXAdESSignerHandle _Handle, TElXMLSignaturePolicyIdHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_ProductionPlace(TElXAdESSignerHandle _Handle, TElXMLSignatureProductionPlaceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_ProductionPlace(TElXAdESSignerHandle _Handle, TElXMLSignatureProductionPlaceHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_SignerRole(TElXAdESSignerHandle _Handle, TElXMLSignerRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_SignerRole(TElXAdESSignerHandle _Handle, TElXMLSignerRoleHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_QualifyingProperties(TElXAdESSignerHandle _Handle, TElXMLQualifyingPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_QualifyingProperties(TElXAdESSignerHandle _Handle, TElXMLQualifyingPropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_QualifyingPropertiesReferences(TElXAdESSignerHandle _Handle, TElXMLQualifyingPropertiesReferenceListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_OwnSigningCertificates(TElXAdESSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_OwnSigningCertificates(TElXAdESSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_SigningCertificates(TElXAdESSignerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_SigningCertificates(TElXAdESSignerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_SigningTime(TElXAdESSignerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_SigningTime(TElXAdESSignerHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_SigningCertificatesDigestMethod(TElXAdESSignerHandle _Handle, TElXMLDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_SigningCertificatesDigestMethod(TElXAdESSignerHandle _Handle, TElXMLDigestMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_Included(TElXAdESSignerHandle _Handle, TElXAdESIncludedPropertiesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_Included(TElXAdESSignerHandle _Handle, TElXAdESIncludedPropertiesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_TSPClient(TElXAdESSignerHandle _Handle, TElCustomTSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_TSPClient(TElXAdESSignerHandle _Handle, TElCustomTSPClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_IgnoreTimestampFailure(TElXAdESSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_IgnoreTimestampFailure(TElXAdESSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_XAdESForm(TElXAdESSignerHandle _Handle, TSBXAdESFormRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_XAdESForm(TElXAdESSignerHandle _Handle, TSBXAdESFormRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_get_XAdESVersion(TElXAdESSignerHandle _Handle, TSBXAdESVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_set_XAdESVersion(TElXAdESSignerHandle _Handle, TSBXAdESVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESSigner_Create(TComponentHandle AOwner, TElXAdESSignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELXADESSIGNER */

#ifdef SB_USE_CLASS_TELXADESVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_Load(TElXAdESVerifierHandle _Handle, TElXMLProcessorHandle Verifier);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_AddCounterSignature(TElXAdESVerifierHandle _Handle, TElXMLProcessorHandle Signer, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_AddSignatureTimestamp(TElXAdESVerifierHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_AddRefsOnlyTimestamp(TElXAdESVerifierHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_AddSigAndRefsTimestamp(TElXAdESVerifierHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_AddArchiveTimestamp(TElXAdESVerifierHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_AddArchiveTimestampV141(TElXAdESVerifierHandle _Handle, TElCustomTSPClientHandle ATSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_AddArchiveTimestampV141_1(TElXAdESVerifierHandle _Handle, TElCustomTSPClientHandle ATSPClient, TElXMLCustomFormatterHandle Formatter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_AddTimestampValidationData(TElXAdESVerifierHandle _Handle, TElXMLCustomFormatterHandle Formatter, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_CheckTimestamp(TElXAdESVerifierHandle _Handle, TElClientTSPInfoHandle Info, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_ExtractAllCertificates(TElXAdESVerifierHandle _Handle, TElCustomCertStorageHandle Certs);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_UpgradeToXAdESv141(TElXAdESVerifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_Validate(TElXAdESVerifierHandle _Handle, TSBXAdESValidityReasonsRaw * Reasons, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_Validate_1(TElXAdESVerifierHandle _Handle, TElX509CertificateHandle SigningCertificate, TSBXAdESValidityReasonsRaw * Reasons, TSBXAdESValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_IsEnabled(TElXAdESVerifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_Included(TElXAdESVerifierHandle _Handle, TElXAdESIncludedPropertiesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_CertIDs(TElXAdESVerifierHandle _Handle, int32_t Index, TElXMLCertIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_CertIDCount(TElXAdESVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_PolicyId(TElXAdESVerifierHandle _Handle, TElXMLSignaturePolicyIdHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_ProductionPlace(TElXAdESVerifierHandle _Handle, TElXMLSignatureProductionPlaceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_SignerRole(TElXAdESVerifierHandle _Handle, TElXMLSignerRoleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_SigningCertificates(TElXAdESVerifierHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_SigningTime(TElXAdESVerifierHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_CertifiedSigningTime(TElXAdESVerifierHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_LastArchivalTime(TElXAdESVerifierHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_Timestamp(TElXAdESVerifierHandle _Handle, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_IndividualDataObjectsTimestampCount(TElXAdESVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_IndividualDataObjectsTimestamps(TElXAdESVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_AllDataObjectsTimestampCount(TElXAdESVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_AllDataObjectsTimestamps(TElXAdESVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_SignatureTimestampCount(TElXAdESVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_SignatureTimestamps(TElXAdESVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_RefsOnlyTimestampCount(TElXAdESVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_RefsOnlyTimestamps(TElXAdESVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_SigAndRefsTimestampCount(TElXAdESVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_SigAndRefsTimestamps(TElXAdESVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_ArchiveTimestampCount(TElXAdESVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_ArchiveTimestamps(TElXAdESVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_TimeStampValidationDataList(TElXAdESVerifierHandle _Handle, TElXMLTimeStampValidationDataListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_QualifyingProperties(TElXAdESVerifierHandle _Handle, TElXMLQualifyingPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_QualifyingPropertiesReferences(TElXAdESVerifierHandle _Handle, TElXMLQualifyingPropertiesReferenceListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_XAdESForm(TElXAdESVerifierHandle _Handle, TSBXAdESFormRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_XAdESVersion(TElXAdESVerifierHandle _Handle, TSBXAdESVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_CertStorage(TElXAdESVerifierHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_set_CertStorage(TElXAdESVerifierHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_OnRetrieveCertificate(TElXAdESVerifierHandle _Handle, TSBXAdESRetrieveCertificateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_set_OnRetrieveCertificate(TElXAdESVerifierHandle _Handle, TSBXAdESRetrieveCertificateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_OnRetrieveCRL(TElXAdESVerifierHandle _Handle, TSBXAdESRetrieveCRLEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_set_OnRetrieveCRL(TElXAdESVerifierHandle _Handle, TSBXAdESRetrieveCRLEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_get_OnRetrieveOCSPResponse(TElXAdESVerifierHandle _Handle, TSBXAdESRetrieveOCSPResponseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_set_OnRetrieveOCSPResponse(TElXAdESVerifierHandle _Handle, TSBXAdESRetrieveOCSPResponseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXAdESVerifier_Create(TComponentHandle AOwner, TElXAdESVerifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELXADESVERIFIER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXAdESProcessor;
typedef TElXAdESProcessor ElXAdESProcessor;
class TElXAdESSigner;
typedef TElXAdESSigner ElXAdESSigner;
class TElXAdESVerifier;
typedef TElXAdESVerifier ElXAdESVerifier;

SB_DEFINE_ENUM_FLAG_OPERATORS(TElXAdESIncludedProperties)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBXAdESOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBXAdESValidityReasons)

#ifdef SB_USE_CLASS_TELXADESPROCESSOR
class TElXAdESProcessor: public TComponent
{
	private:
		SB_DISABLE_COPY(TElXAdESProcessor)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_TrustedCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR
		TElX509CertificateValidator* _Inst_CertificateValidator;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */

		void initInstances();

	public:
		TSBXAdESValidity AddTimestampValidationData();

#ifdef SB_USE_CLASS_TELXMLCUSTOMFORMATTER
		virtual TSBXAdESValidity AddTimestampValidationData(TElXMLCustomFormatter &Formatter);

		virtual TSBXAdESValidity AddTimestampValidationData(TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASS_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELXMLCUSTOMFORMATTER
		TSBXAdESValidity AddTimestampValidationData(TElClientTSPInfo &TSPInfo, const sb_u16string &URI, TElXMLCustomFormatter &Formatter);

		TSBXAdESValidity AddTimestampValidationData(TElClientTSPInfo *TSPInfo, const sb_u16string &URI, TElXMLCustomFormatter *Formatter);
#ifdef SB_U16STRING_USED
		TSBXAdESValidity AddTimestampValidationData(TElClientTSPInfo &TSPInfo, const std::wstring &URI, TElXMLCustomFormatter &Formatter);

		TSBXAdESValidity AddTimestampValidationData(TElClientTSPInfo *TSPInfo, const std::wstring &URI, TElXMLCustomFormatter *Formatter);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
		void AddTimestampValidationData(TElCustomCertStorage &Certs, TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLCustomFormatter &Formatter);

		void AddTimestampValidationData(TElCustomCertStorage *Certs, TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
		void AddTimestampValidationData(TElCustomCertStorage &Certs, TElCustomCRLStorage &CRLs, TList &OCSPResponses, const sb_u16string &URI, TElXMLCustomFormatter &Formatter);

		void AddTimestampValidationData(TElCustomCertStorage *Certs, TElCustomCRLStorage *CRLs, TList *OCSPResponses, const sb_u16string &URI, TElXMLCustomFormatter *Formatter);
#ifdef SB_U16STRING_USED
		void AddTimestampValidationData(TElCustomCertStorage &Certs, TElCustomCRLStorage &CRLs, TList &OCSPResponses, const std::wstring &URI, TElXMLCustomFormatter &Formatter);

		void AddTimestampValidationData(TElCustomCertStorage *Certs, TElCustomCRLStorage *CRLs, TList *OCSPResponses, const std::wstring &URI, TElXMLCustomFormatter *Formatter);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

#ifdef SB_USE_CLASS_TELXMLPROCESSOR
		void AddCounterSignature(TElXMLProcessor &Signer);

		void AddCounterSignature(TElXMLProcessor *Signer);
#endif /* SB_USE_CLASS_TELXMLPROCESSOR */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR
		virtual void AddCounterSignature(TElXMLProcessor &Signer, TElXMLCustomFormatter &Formatter);

		virtual void AddCounterSignature(TElXMLProcessor *Signer, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddSignatureTimestamp(TElCustomTSPClient &ATSPClient);

		int32_t AddSignatureTimestamp(TElCustomTSPClient *ATSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddSignatureTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddSignatureTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddRefsOnlyTimestamp(TElCustomTSPClient &ATSPClient);

		int32_t AddRefsOnlyTimestamp(TElCustomTSPClient *ATSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddRefsOnlyTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddRefsOnlyTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddSigAndRefsTimestamp(TElCustomTSPClient &ATSPClient);

		int32_t AddSigAndRefsTimestamp(TElCustomTSPClient *ATSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddSigAndRefsTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddSigAndRefsTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddArchiveTimestamp(TElCustomTSPClient &ATSPClient);

		int32_t AddArchiveTimestamp(TElCustomTSPClient *ATSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddArchiveTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddArchiveTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void AddAttributeCertificateRefs(TElCustomCertStorage &Certs);

		void AddAttributeCertificateRefs(TElCustomCertStorage *Certs);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER
		virtual void AddAttributeCertificateRefs(TElCustomCertStorage &Certs, TElXMLDigestMethod DigestMethod, TElXMLCustomFormatter &Formatter);

		virtual void AddAttributeCertificateRefs(TElCustomCertStorage *Certs, TElXMLDigestMethod DigestMethod, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void AddCompleteCertificateRefs(TElCustomCertStorage &Certs);

		void AddCompleteCertificateRefs(TElCustomCertStorage *Certs);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER
		virtual void AddCompleteCertificateRefs(TElCustomCertStorage &Certs, TElXMLDigestMethod DigestMethod, TElXMLCustomFormatter &Formatter);

		virtual void AddCompleteCertificateRefs(TElCustomCertStorage *Certs, TElXMLDigestMethod DigestMethod, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST
		void AddAttributeRevocationRefs(TElCustomCRLStorage &CRLs, TList &OCSPResponses);

		void AddAttributeRevocationRefs(TElCustomCRLStorage *CRLs, TList *OCSPResponses);
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
		void AddAttributeRevocationRefs(TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter &Formatter);

		void AddAttributeRevocationRefs(TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST
		void AddCompleteRevocationRefs(TElCustomCRLStorage &CRLs, TList &OCSPResponses);

		void AddCompleteRevocationRefs(TElCustomCRLStorage *CRLs, TList *OCSPResponses);
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
		void AddCompleteRevocationRefs(TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter &Formatter);

		void AddCompleteRevocationRefs(TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

		TSBXAdESValidity AddValidationDataRefs();

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER
		virtual TSBXAdESValidity AddValidationDataRefs(TElX509Certificate &SigningCertificate, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter &Formatter);

		virtual TSBXAdESValidity AddValidationDataRefs(TElX509Certificate *SigningCertificate, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER
		virtual TSBXAdESValidity AddValidationDataRefs(TElX509Certificate &SigningCertificate, bool IncludeCRL, bool IncludeOCSP, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter &Formatter);

		virtual TSBXAdESValidity AddValidationDataRefs(TElX509Certificate *SigningCertificate, bool IncludeCRL, bool IncludeOCSP, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void AddAttrAuthoritiesCertValues(TElCustomCertStorage &Certs);

		void AddAttrAuthoritiesCertValues(TElCustomCertStorage *Certs);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER
		void AddAttrAuthoritiesCertValues(TElCustomCertStorage &Certs, TElXMLCustomFormatter &Formatter);

		void AddAttrAuthoritiesCertValues(TElCustomCertStorage *Certs, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void AddCertificateValues(TElCustomCertStorage &Certs);

		void AddCertificateValues(TElCustomCertStorage *Certs);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER
		void AddCertificateValues(TElCustomCertStorage &Certs, TElXMLCustomFormatter &Formatter);

		void AddCertificateValues(TElCustomCertStorage *Certs, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST
		void AddAttributeRevocationValues(TElCustomCRLStorage &CRLs, TList &OCSPResponses);

		void AddAttributeRevocationValues(TElCustomCRLStorage *CRLs, TList *OCSPResponses);
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
		void AddAttributeRevocationValues(TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLCustomFormatter &Formatter);

		void AddAttributeRevocationValues(TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST
		void AddRevocationValues(TElCustomCRLStorage &CRLs, TList &OCSPResponses);

		void AddRevocationValues(TElCustomCRLStorage *CRLs, TList *OCSPResponses);
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
		void AddRevocationValues(TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLCustomFormatter &Formatter);

		void AddRevocationValues(TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

		TSBXAdESValidity AddValidationDataValues();

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER
		virtual TSBXAdESValidity AddValidationDataValues(TElX509Certificate &SigningCertificate, TElXMLCustomFormatter &Formatter);

		virtual TSBXAdESValidity AddValidationDataValues(TElX509Certificate *SigningCertificate, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER
		virtual TSBXAdESValidity AddValidationDataValues(TElX509Certificate &SigningCertificate, bool IncludeCRL, bool IncludeOCSP, TElXMLCustomFormatter &Formatter);

		virtual TSBXAdESValidity AddValidationDataValues(TElX509Certificate *SigningCertificate, bool IncludeCRL, bool IncludeOCSP, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509CertificateHandle GetSignerCertificate();
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void ClearPKICache();

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual void ExtractAllCertificates(TElCustomCertStorage &Certs);

		virtual void ExtractAllCertificates(TElCustomCertStorage *Certs);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
		void ExtractAllCRLs(TElCustomCRLStorage &CRLs);

		void ExtractAllCRLs(TElCustomCRLStorage *CRLs);
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */

#ifdef SB_USE_CLASS_TLIST
		void ExtractAllOCSPResponses(TList &OCSPResponses);

		void ExtractAllOCSPResponses(TList *OCSPResponses);
#endif /* SB_USE_CLASS_TLIST */

		virtual int32_t get_GracePeriod();

		virtual void set_GracePeriod(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_GracePeriod, set_GracePeriod, TElXAdESProcessor, GracePeriod);

		virtual bool get_OfflineMode();

		virtual void set_OfflineMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OfflineMode, set_OfflineMode, TElXAdESProcessor, OfflineMode);

		virtual TElXMLCanonicalizationMethod get_TimestampCanonicalizationMethod();

		virtual void set_TimestampCanonicalizationMethod(TElXMLCanonicalizationMethod Value);

		SB_DECLARE_PROPERTY(TElXMLCanonicalizationMethod, get_TimestampCanonicalizationMethod, set_TimestampCanonicalizationMethod, TElXAdESProcessor, TimestampCanonicalizationMethod);

		virtual TSBXAdESOptions get_XAdESOptions();

		virtual void set_XAdESOptions(TSBXAdESOptions Value);

		SB_DECLARE_PROPERTY(TSBXAdESOptions, get_XAdESOptions, set_XAdESOptions, TElXAdESProcessor, XAdESOptions);

		virtual int64_t get_ValidationMoment();

		virtual void set_ValidationMoment(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidationMoment, set_ValidationMoment, TElXAdESProcessor, ValidationMoment);

		virtual bool get_ForceCompleteChainValidation();

		virtual void set_ForceCompleteChainValidation(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCompleteChainValidation, set_ForceCompleteChainValidation, TElXAdESProcessor, ForceCompleteChainValidation);

		virtual bool get_IgnoreChainValidationErrors();

		virtual void set_IgnoreChainValidationErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreChainValidationErrors, set_IgnoreChainValidationErrors, TElXAdESProcessor, IgnoreChainValidationErrors);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_TrustedCertificates();

		virtual void set_TrustedCertificates(TElCustomCertStorage &Value);

		virtual void set_TrustedCertificates(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_TrustedCertificates, set_TrustedCertificates, TElXAdESProcessor, TrustedCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElXAdESProcessor, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR
		virtual TElX509CertificateValidator* get_CertificateValidator();

		virtual void set_CertificateValidator(TElX509CertificateValidator &Value);

		virtual void set_CertificateValidator(TElX509CertificateValidator *Value);

		SB_DECLARE_PROPERTY(TElX509CertificateValidator*, get_CertificateValidator, set_CertificateValidator, TElXAdESProcessor, CertificateValidator);
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */

		virtual void get_OnBeforeSaveUnsignedProperty(TSBXAdESBeforeSaveUnsignedPropertyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSaveUnsignedProperty(TSBXAdESBeforeSaveUnsignedPropertyEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeCertificateValidate(TSBXAdESBeforeCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeCertificateValidate(TSBXAdESBeforeCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnAfterCertificateValidate(TSBXAdESAfterCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAfterCertificateValidate(TSBXAdESAfterCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeeded(TSBXAdESCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeeded(TSBXAdESCertificateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnStoreCertificate(TSBXAdESStoreCertificateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStoreCertificate(TSBXAdESStoreCertificateEvent pMethodValue, void * pDataValue);

		virtual void get_OnStoreCRL(TSBXAdESStoreCRLEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStoreCRL(TSBXAdESStoreCRLEvent pMethodValue, void * pDataValue);

		virtual void get_OnStoreOCSPResponse(TSBXAdESStoreOCSPResponseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStoreOCSPResponse(TSBXAdESStoreOCSPResponseEvent pMethodValue, void * pDataValue);

		TElXAdESProcessor(TElXAdESProcessorHandle handle, TElOwnHandle ownHandle);

		explicit TElXAdESProcessor(TComponent &AOwner);

		explicit TElXAdESProcessor(TComponent *AOwner);

		virtual ~TElXAdESProcessor();

};
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

#ifdef SB_USE_CLASS_TELXADESSIGNER
class TElXAdESSigner: public TElXAdESProcessor
{
	private:
		SB_DISABLE_COPY(TElXAdESSigner)
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
		TElXMLSignaturePolicyId* _Inst_PolicyId;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
		TElXMLSignatureProductionPlace* _Inst_ProductionPlace;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
		TElXMLSignerRole* _Inst_SignerRole;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
		TElXMLQualifyingProperties* _Inst_QualifyingProperties;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
		TElXMLQualifyingPropertiesReferenceList* _Inst_QualifyingPropertiesReferences;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_SigningCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		TElCustomTSPClient* _Inst_TSPClient;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLREFERENCELIST
		int32_t TimestampDataObjects(TElXMLReferenceList &AReferences, TElXMLCustomFormatter &Formatter);

		int32_t TimestampDataObjects(TElXMLReferenceList *AReferences, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFO_AND_TELXMLREFERENCELIST
		int32_t AddUnsignedObjects(TElXMLDOMElement &SignedInfo, TElXMLDOMElement &SignatureValue, TElXMLKeyInfo &KeyInfo, TElXMLReferenceList &AReferences, TObject &AObjects, TElXMLCustomFormatter &Formatter);

		int32_t AddUnsignedObjects(TElXMLDOMElement *SignedInfo, TElXMLDOMElement *SignatureValue, TElXMLKeyInfo *KeyInfo, TElXMLReferenceList *AReferences, TObject *AObjects, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFO_AND_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void SetSigningCertificates(TElCustomCertStorage &Value);

		void SetSigningCertificates(TElCustomCertStorage *Value);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		void SetTSPClient(TElCustomTSPClient &Value);

		void SetTSPClient(TElCustomTSPClient *Value);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		void SetXAdESForm(TSBXAdESForm Value);

		void SetXAdESVersion(TSBXAdESVersion Value);

		void Clear();

		void Generate();

		void Generate(TSBXAdESForm AXAdESForm);

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR
		virtual void AddCounterSignature(TElXMLProcessor &Signer, TElXMLCustomFormatter &Formatter);

		virtual void AddCounterSignature(TElXMLProcessor *Signer, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		void AddAllDataObjectsTimestamp(TElCustomTSPClient &ATSPClient);

		void AddAllDataObjectsTimestamp(TElCustomTSPClient *ATSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddSignatureTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddSignatureTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddRefsOnlyTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddRefsOnlyTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddSigAndRefsTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddSigAndRefsTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddArchiveTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddArchiveTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
		virtual TElXMLSignaturePolicyId* get_PolicyId();

		virtual void set_PolicyId(TElXMLSignaturePolicyId &Value);

		virtual void set_PolicyId(TElXMLSignaturePolicyId *Value);

		SB_DECLARE_PROPERTY(TElXMLSignaturePolicyId*, get_PolicyId, set_PolicyId, TElXAdESSigner, PolicyId);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
		virtual TElXMLSignatureProductionPlace* get_ProductionPlace();

		virtual void set_ProductionPlace(TElXMLSignatureProductionPlace &Value);

		virtual void set_ProductionPlace(TElXMLSignatureProductionPlace *Value);

		SB_DECLARE_PROPERTY(TElXMLSignatureProductionPlace*, get_ProductionPlace, set_ProductionPlace, TElXAdESSigner, ProductionPlace);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
		virtual TElXMLSignerRole* get_SignerRole();

		virtual void set_SignerRole(TElXMLSignerRole &Value);

		virtual void set_SignerRole(TElXMLSignerRole *Value);

		SB_DECLARE_PROPERTY(TElXMLSignerRole*, get_SignerRole, set_SignerRole, TElXAdESSigner, SignerRole);
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
		virtual TElXMLQualifyingProperties* get_QualifyingProperties();

		virtual void set_QualifyingProperties(TElXMLQualifyingProperties &Value);

		virtual void set_QualifyingProperties(TElXMLQualifyingProperties *Value);

		SB_DECLARE_PROPERTY(TElXMLQualifyingProperties*, get_QualifyingProperties, set_QualifyingProperties, TElXAdESSigner, QualifyingProperties);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
		virtual TElXMLQualifyingPropertiesReferenceList* get_QualifyingPropertiesReferences();

		SB_DECLARE_PROPERTY_GET(TElXMLQualifyingPropertiesReferenceList*, get_QualifyingPropertiesReferences, TElXAdESSigner, QualifyingPropertiesReferences);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

		virtual bool get_OwnSigningCertificates();

		virtual void set_OwnSigningCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnSigningCertificates, set_OwnSigningCertificates, TElXAdESSigner, OwnSigningCertificates);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_SigningCertificates();

		virtual void set_SigningCertificates(TElCustomCertStorage &Value);

		virtual void set_SigningCertificates(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_SigningCertificates, set_SigningCertificates, TElXAdESSigner, SigningCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual int64_t get_SigningTime();

		virtual void set_SigningTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SigningTime, set_SigningTime, TElXAdESSigner, SigningTime);

		virtual TElXMLDigestMethod get_SigningCertificatesDigestMethod();

		virtual void set_SigningCertificatesDigestMethod(TElXMLDigestMethod Value);

		SB_DECLARE_PROPERTY(TElXMLDigestMethod, get_SigningCertificatesDigestMethod, set_SigningCertificatesDigestMethod, TElXAdESSigner, SigningCertificatesDigestMethod);

		virtual TElXAdESIncludedProperties get_Included();

		virtual void set_Included(TElXAdESIncludedProperties Value);

		SB_DECLARE_PROPERTY(TElXAdESIncludedProperties, get_Included, set_Included, TElXAdESSigner, Included);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		virtual TElCustomTSPClient* get_TSPClient();

		virtual void set_TSPClient(TElCustomTSPClient &Value);

		virtual void set_TSPClient(TElCustomTSPClient *Value);

		SB_DECLARE_PROPERTY(TElCustomTSPClient*, get_TSPClient, set_TSPClient, TElXAdESSigner, TSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		virtual bool get_IgnoreTimestampFailure();

		virtual void set_IgnoreTimestampFailure(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreTimestampFailure, set_IgnoreTimestampFailure, TElXAdESSigner, IgnoreTimestampFailure);

		virtual TSBXAdESForm get_XAdESForm();

		virtual void set_XAdESForm(TSBXAdESForm Value);

		SB_DECLARE_PROPERTY(TSBXAdESForm, get_XAdESForm, set_XAdESForm, TElXAdESSigner, XAdESForm);

		virtual TSBXAdESVersion get_XAdESVersion();

		virtual void set_XAdESVersion(TSBXAdESVersion Value);

		SB_DECLARE_PROPERTY(TSBXAdESVersion, get_XAdESVersion, set_XAdESVersion, TElXAdESSigner, XAdESVersion);

		TElXAdESSigner(TElXAdESSignerHandle handle, TElOwnHandle ownHandle);

		explicit TElXAdESSigner(TComponent &AOwner);

		explicit TElXAdESSigner(TComponent *AOwner);

		virtual ~TElXAdESSigner();

};
#endif /* SB_USE_CLASS_TELXADESSIGNER */

#ifdef SB_USE_CLASS_TELXADESVERIFIER
class TElXAdESVerifier: public TElXAdESProcessor
{
	private:
		SB_DISABLE_COPY(TElXAdESVerifier)
#ifdef SB_USE_CLASS_TELXMLCERTID
		TElXMLCertID* _Inst_CertIDs;
#endif /* SB_USE_CLASS_TELXMLCERTID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
		TElXMLSignaturePolicyId* _Inst_PolicyId;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
		TElXMLSignatureProductionPlace* _Inst_ProductionPlace;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
		TElXMLSignerRole* _Inst_SignerRole;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_SigningCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_Timestamp;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_IndividualDataObjectsTimestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_AllDataObjectsTimestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_SignatureTimestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_RefsOnlyTimestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_SigAndRefsTimestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_ArchiveTimestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
		TElXMLTimeStampValidationDataList* _Inst_TimeStampValidationDataList;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
		TElXMLQualifyingProperties* _Inst_QualifyingProperties;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
		TElXMLQualifyingPropertiesReferenceList* _Inst_QualifyingPropertiesReferences;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLPROCESSOR
		void Load(TElXMLProcessor &Verifier);

		void Load(TElXMLProcessor *Verifier);
#endif /* SB_USE_CLASS_TELXMLPROCESSOR */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR
		virtual void AddCounterSignature(TElXMLProcessor &Signer, TElXMLCustomFormatter &Formatter);

		virtual void AddCounterSignature(TElXMLProcessor *Signer, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddSignatureTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddSignatureTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddRefsOnlyTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddRefsOnlyTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddSigAndRefsTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddSigAndRefsTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		virtual int32_t AddArchiveTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		virtual int32_t AddArchiveTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddArchiveTimestampV141(TElCustomTSPClient &ATSPClient);

		int32_t AddArchiveTimestampV141(TElCustomTSPClient *ATSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
		int32_t AddArchiveTimestampV141(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter);

		int32_t AddArchiveTimestampV141(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELXMLCUSTOMFORMATTER
		virtual TSBXAdESValidity AddTimestampValidationData(TElXMLCustomFormatter &Formatter);

		virtual TSBXAdESValidity AddTimestampValidationData(TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASS_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		bool CheckTimestamp(TElClientTSPInfo &Info);

		bool CheckTimestamp(TElClientTSPInfo *Info);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual void ExtractAllCertificates(TElCustomCertStorage &Certs);

		virtual void ExtractAllCertificates(TElCustomCertStorage *Certs);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void UpgradeToXAdESv141();

		TSBXAdESValidity Validate(TSBXAdESValidityReasons &Reasons);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TSBXAdESValidity Validate(TElX509Certificate &SigningCertificate, TSBXAdESValidityReasons &Reasons);

		TSBXAdESValidity Validate(TElX509Certificate *SigningCertificate, TSBXAdESValidityReasons &Reasons);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual bool get_IsEnabled();

		SB_DECLARE_PROPERTY_GET(bool, get_IsEnabled, TElXAdESVerifier, IsEnabled);

		virtual TElXAdESIncludedProperties get_Included();

		SB_DECLARE_PROPERTY_GET(TElXAdESIncludedProperties, get_Included, TElXAdESVerifier, Included);

#ifdef SB_USE_CLASS_TELXMLCERTID
		virtual TElXMLCertID* get_CertIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLCERTID */

		virtual int32_t get_CertIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertIDCount, TElXAdESVerifier, CertIDCount);

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
		virtual TElXMLSignaturePolicyId* get_PolicyId();

		SB_DECLARE_PROPERTY_GET(TElXMLSignaturePolicyId*, get_PolicyId, TElXAdESVerifier, PolicyId);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
		virtual TElXMLSignatureProductionPlace* get_ProductionPlace();

		SB_DECLARE_PROPERTY_GET(TElXMLSignatureProductionPlace*, get_ProductionPlace, TElXAdESVerifier, ProductionPlace);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
		virtual TElXMLSignerRole* get_SignerRole();

		SB_DECLARE_PROPERTY_GET(TElXMLSignerRole*, get_SignerRole, TElXAdESVerifier, SignerRole);
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_SigningCertificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_SigningCertificates, TElXAdESVerifier, SigningCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual int64_t get_SigningTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SigningTime, TElXAdESVerifier, SigningTime);

		virtual int64_t get_CertifiedSigningTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CertifiedSigningTime, TElXAdESVerifier, CertifiedSigningTime);

		virtual int64_t get_LastArchivalTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LastArchivalTime, TElXAdESVerifier, LastArchivalTime);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_Timestamp();

		SB_DECLARE_PROPERTY_GET(TElClientTSPInfo*, get_Timestamp, TElXAdESVerifier, Timestamp);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_IndividualDataObjectsTimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_IndividualDataObjectsTimestampCount, TElXAdESVerifier, IndividualDataObjectsTimestampCount);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_IndividualDataObjectsTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_AllDataObjectsTimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AllDataObjectsTimestampCount, TElXAdESVerifier, AllDataObjectsTimestampCount);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_AllDataObjectsTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_SignatureTimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureTimestampCount, TElXAdESVerifier, SignatureTimestampCount);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_SignatureTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_RefsOnlyTimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RefsOnlyTimestampCount, TElXAdESVerifier, RefsOnlyTimestampCount);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_RefsOnlyTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_SigAndRefsTimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SigAndRefsTimestampCount, TElXAdESVerifier, SigAndRefsTimestampCount);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_SigAndRefsTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_ArchiveTimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ArchiveTimestampCount, TElXAdESVerifier, ArchiveTimestampCount);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_ArchiveTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
		virtual TElXMLTimeStampValidationDataList* get_TimeStampValidationDataList();

		SB_DECLARE_PROPERTY_GET(TElXMLTimeStampValidationDataList*, get_TimeStampValidationDataList, TElXAdESVerifier, TimeStampValidationDataList);
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
		virtual TElXMLQualifyingProperties* get_QualifyingProperties();

		SB_DECLARE_PROPERTY_GET(TElXMLQualifyingProperties*, get_QualifyingProperties, TElXAdESVerifier, QualifyingProperties);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
		virtual TElXMLQualifyingPropertiesReferenceList* get_QualifyingPropertiesReferences();

		SB_DECLARE_PROPERTY_GET(TElXMLQualifyingPropertiesReferenceList*, get_QualifyingPropertiesReferences, TElXAdESVerifier, QualifyingPropertiesReferences);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

		virtual TSBXAdESForm get_XAdESForm();

		SB_DECLARE_PROPERTY_GET(TSBXAdESForm, get_XAdESForm, TElXAdESVerifier, XAdESForm);

		virtual TSBXAdESVersion get_XAdESVersion();

		SB_DECLARE_PROPERTY_GET(TSBXAdESVersion, get_XAdESVersion, TElXAdESVerifier, XAdESVersion);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElXAdESVerifier, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_OnRetrieveCertificate(TSBXAdESRetrieveCertificateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRetrieveCertificate(TSBXAdESRetrieveCertificateEvent pMethodValue, void * pDataValue);

		virtual void get_OnRetrieveCRL(TSBXAdESRetrieveCRLEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRetrieveCRL(TSBXAdESRetrieveCRLEvent pMethodValue, void * pDataValue);

		virtual void get_OnRetrieveOCSPResponse(TSBXAdESRetrieveOCSPResponseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRetrieveOCSPResponse(TSBXAdESRetrieveOCSPResponseEvent pMethodValue, void * pDataValue);

		TElXAdESVerifier(TElXAdESVerifierHandle handle, TElOwnHandle ownHandle);

		explicit TElXAdESVerifier(TComponent &AOwner);

		explicit TElXAdESVerifier(TComponent *AOwner);

		virtual ~TElXAdESVerifier();

};
#endif /* SB_USE_CLASS_TELXADESVERIFIER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLADESINTF */

