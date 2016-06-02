#ifndef __INC_SBXMLSIG
#define __INC_SBXMLSIG

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
#include "sbhashfunction.h"
#include "sbpublickeycrypto.h"
#include "sbcryptoprov.h"
#include "sbx509.h"
#include "sbdc.h"
#include "sbdcdef.h"
#include "sbdcpkiconstants.h"
#include "sbxmlades.h"
#include "sbxmladesintf.h"
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
typedef TElClassHandle TElXMLSignatureHandle;

typedef TElXMLSignatureHandle ElXMLSignatureHandle;

typedef TElClassHandle TElXMLSigProcessorHandle;

typedef TElXMLSigProcessorHandle ElXMLSigProcessorHandle;

typedef TElClassHandle TElXMLSignerHandle;

typedef TElXMLSignerHandle ElXMLSignerHandle;

typedef TElClassHandle TElXMLVerifierHandle;

typedef TElXMLVerifierHandle ElXMLVerifierHandle;

typedef TElClassHandle TElXMLSignatureMethodTypeHandle;

typedef TElXMLSignatureMethodTypeHandle ElXMLSignatureMethodTypeHandle;

typedef TElClassHandle TElXMLSignedInfoHandle;

typedef TElXMLSignedInfoHandle ElXMLSignedInfoHandle;

typedef TElClassHandle TElXMLManifestHandle;

typedef TElXMLManifestHandle ElXMLManifestHandle;

typedef TElClassHandle TElXMLSignaturePropertiesHandle;

typedef TElXMLSignaturePropertiesHandle ElXMLSignaturePropertiesHandle;

typedef TElClassHandle TElXMLObjectHandle;

typedef TElXMLObjectHandle ElXMLObjectHandle;

typedef TElClassHandle TElXMLObjectListHandle;

typedef TElXMLObjectListHandle ElXMLObjectListHandle;

typedef TElClassHandle TElXMLSignatureValueHandle;

typedef TElXMLSignatureValueHandle ElXMLSignatureValueHandle;

typedef void (SB_CALLBACK *TSBXMLRemoteSignEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pHash[], int32_t szHash, uint8_t pSignedHash[], int32_t * szSignedHash);

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_Clear(TElXMLSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_IsEmpty(TElXMLSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_LoadFromXML(TElXMLSignatureHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_SaveToXML(TElXMLSignatureHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_ID(TElXMLSignatureHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_ID(TElXMLSignatureHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_SignedInfo(TElXMLSignatureHandle _Handle, TElXMLSignedInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_SignedInfo(TElXMLSignatureHandle _Handle, TElXMLSignedInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_SignatureValue(TElXMLSignatureHandle _Handle, TElXMLSignatureValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_SignatureValue(TElXMLSignatureHandle _Handle, TElXMLSignatureValueHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_KeyInfo(TElXMLSignatureHandle _Handle, TElXMLKeyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_KeyInfo(TElXMLSignatureHandle _Handle, TElXMLKeyInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_Objects(TElXMLSignatureHandle _Handle, TElXMLObjectListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_Objects(TElXMLSignatureHandle _Handle, TElXMLObjectListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_SignaturePrefix(TElXMLSignatureHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_SignaturePrefix(TElXMLSignatureHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_SignatureCompliance(TElXMLSignatureHandle _Handle, TElXMLSignatureComplianceRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_SignatureCompliance(TElXMLSignatureHandle _Handle, TElXMLSignatureComplianceRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_CryptoProviderManager(TElXMLSignatureHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_CryptoProviderManager(TElXMLSignatureHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_QualifyingProperties(TElXMLSignatureHandle _Handle, TElXMLQualifyingPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_set_QualifyingProperties(TElXMLSignatureHandle _Handle, TElXMLQualifyingPropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_get_QualifyingPropertiesReferences(TElXMLSignatureHandle _Handle, TElXMLQualifyingPropertiesReferenceListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignature_Create(TElXMLSignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLSIGPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigProcessor_ClearSignatureMethodParameters(TElXMLSigProcessorHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigProcessor_get_KeyData(TElXMLSigProcessorHandle _Handle, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigProcessor_set_KeyData(TElXMLSigProcessorHandle _Handle, TElXMLKeyInfoDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigProcessor_get_Signature(TElXMLSigProcessorHandle _Handle, TElXMLSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigProcessor_set_Signature(TElXMLSigProcessorHandle _Handle, TElXMLSignatureHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigProcessor_get_SignatureMethodParameters(TElXMLSigProcessorHandle _Handle, TElXMLAlgorithmParametersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigProcessor_set_SignatureMethodParameters(TElXMLSigProcessorHandle _Handle, TElXMLAlgorithmParametersHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigProcessor_Create(TComponentHandle AOwner, TElXMLSigProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLSIGNER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_CompleteAsyncSign(TElXMLSignerHandle _Handle, TElXMLDOMDocumentHandle Document, TElDCAsyncStateHandle State);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_InitiateAsyncSign(TElXMLSignerHandle _Handle, TElXMLDOMNodeHandle * Node, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_GenerateSignature(TElXMLSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_GenerateSignatureAsync(TElXMLSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_Sign(TElXMLSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_Save(TElXMLSignerHandle _Handle, TElXMLDOMNodeHandle * Node);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_SaveDetached(TElXMLSignerHandle _Handle, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_SaveEnveloped(TElXMLSignerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_SaveEnveloping(TElXMLSignerHandle _Handle, TElXMLDOMNodeHandle EnvelopingNode, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_UpdateReferencesDigest(TElXMLSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_References(TElXMLSignerHandle _Handle, TElXMLReferenceListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_References(TElXMLSignerHandle _Handle, TElXMLReferenceListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_RemoteSigningParams(TElXMLSignerHandle _Handle, TElRemoteSigningParamsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_XAdESProcessor(TElXMLSignerHandle _Handle, TElXAdESSignerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_XAdESProcessor(TElXMLSignerHandle _Handle, TElXAdESSignerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_CanonicalizationMethod(TElXMLSignerHandle _Handle, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_CanonicalizationMethod(TElXMLSignerHandle _Handle, TElXMLCanonicalizationMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_InclusiveNamespacesPrefixList(TElXMLSignerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_InclusiveNamespacesPrefixList(TElXMLSignerHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_SignatureType(TElXMLSignerHandle _Handle, TElXMLSignatureTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_SignatureType(TElXMLSignerHandle _Handle, TElXMLSignatureTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_SignatureCompliance(TElXMLSignerHandle _Handle, TElXMLSignatureComplianceRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_SignatureCompliance(TElXMLSignerHandle _Handle, TElXMLSignatureComplianceRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_SignatureMethodType(TElXMLSignerHandle _Handle, TElXMLSigMethodTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_SignatureMethodType(TElXMLSignerHandle _Handle, TElXMLSigMethodTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_MACMethod(TElXMLSignerHandle _Handle, TElXMLMACMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_MACMethod(TElXMLSignerHandle _Handle, TElXMLMACMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_SignatureMethod(TElXMLSignerHandle _Handle, TElXMLSignatureMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_SignatureMethod(TElXMLSignerHandle _Handle, TElXMLSignatureMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_IncludeKey(TElXMLSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_IncludeKey(TElXMLSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_KeyName(TElXMLSignerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_KeyName(TElXMLSignerHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_EnvelopingObjectID(TElXMLSignerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_EnvelopingObjectID(TElXMLSignerHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_OnFormatElement(TElXMLSignerHandle _Handle, TSBXMLFormatElementEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_OnFormatElement(TElXMLSignerHandle _Handle, TSBXMLFormatElementEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_OnFormatText(TElXMLSignerHandle _Handle, TSBXMLFormatTextEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_OnFormatText(TElXMLSignerHandle _Handle, TSBXMLFormatTextEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_get_OnRemoteSign(TElXMLSignerHandle _Handle, TSBXMLRemoteSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_set_OnRemoteSign(TElXMLSignerHandle _Handle, TSBXMLRemoteSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSigner_Create(TComponentHandle AOwner, TElXMLSignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNER */

#ifdef SB_USE_CLASS_TELXMLVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_Load(TElXMLVerifierHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_ValidateSignature(TElXMLVerifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_ValidateReference(TElXMLVerifierHandle _Handle, TElXMLReferenceHandle Reference, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_ValidateReferences(TElXMLVerifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_RemoveSignature(TElXMLVerifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_HMACKey(TElXMLVerifierHandle _Handle, TElXMLKeyInfoHMACDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_set_HMACKey(TElXMLVerifierHandle _Handle, TElXMLKeyInfoHMACDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_References(TElXMLVerifierHandle _Handle, TElXMLReferenceListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_CanonicalizationMethod(TElXMLVerifierHandle _Handle, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_InclusiveNamespacesPrefixList(TElXMLVerifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_SignatureType(TElXMLVerifierHandle _Handle, TElXMLSignatureTypesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_SignatureCompliance(TElXMLVerifierHandle _Handle, TElXMLSignatureComplianceRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_SignatureMethodType(TElXMLVerifierHandle _Handle, TElXMLSigMethodTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_MACMethod(TElXMLVerifierHandle _Handle, TElXMLMACMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_SignatureMethod(TElXMLVerifierHandle _Handle, TElXMLSignatureMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_KeyDataNeeded(TElXMLVerifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_KeyName(TElXMLVerifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_SignerCertificate(TElXMLVerifierHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_SignerKeyData(TElXMLVerifierHandle _Handle, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_get_XAdESProcessor(TElXMLVerifierHandle _Handle, TElXAdESVerifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_set_XAdESProcessor(TElXMLVerifierHandle _Handle, TElXAdESVerifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLVerifier_Create(TComponentHandle AOwner, TElXMLVerifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLVERIFIER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_Clear(TElXMLSignatureMethodTypeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_IsEmpty(TElXMLSignatureMethodTypeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_LoadFromXML(TElXMLSignatureMethodTypeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_SaveToXML(TElXMLSignatureMethodTypeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_get_Algorithm(TElXMLSignatureMethodTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_set_Algorithm(TElXMLSignatureMethodTypeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_get_HMACOutputLength(TElXMLSignatureMethodTypeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_set_HMACOutputLength(TElXMLSignatureMethodTypeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_get_Parameters(TElXMLSignatureMethodTypeHandle _Handle, TElXMLAlgorithmParametersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_set_Parameters(TElXMLSignatureMethodTypeHandle _Handle, TElXMLAlgorithmParametersHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureMethodType_Create(TElXMLSignatureMethodTypeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLSIGNEDINFO
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_Clear(TElXMLSignedInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_IsEmpty(TElXMLSignedInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_LoadFromXML(TElXMLSignedInfoHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_SaveToXML(TElXMLSignedInfoHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_get_ID(TElXMLSignedInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_set_ID(TElXMLSignedInfoHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_get_CanonicalizationMethod(TElXMLSignedInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_set_CanonicalizationMethod(TElXMLSignedInfoHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_get_ExclusiveCanonicalizationPrefix(TElXMLSignedInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_set_ExclusiveCanonicalizationPrefix(TElXMLSignedInfoHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_get_InclusiveNamespacesPrefixList(TElXMLSignedInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_set_InclusiveNamespacesPrefixList(TElXMLSignedInfoHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_get_SignatureMethod(TElXMLSignedInfoHandle _Handle, TElXMLSignatureMethodTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_set_SignatureMethod(TElXMLSignedInfoHandle _Handle, TElXMLSignatureMethodTypeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_get_References(TElXMLSignedInfoHandle _Handle, TElXMLReferenceListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_set_References(TElXMLSignedInfoHandle _Handle, TElXMLReferenceListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_get_SigPropRef(TElXMLSignedInfoHandle _Handle, TElXMLReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignedInfo_Create(TElXMLSignedInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNEDINFO */

#ifdef SB_USE_CLASS_TELXMLMANIFEST
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_Clear(TElXMLManifestHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_IsEmpty(TElXMLManifestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_LoadFromXML(TElXMLManifestHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_SaveToXML(TElXMLManifestHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_get_XMLElement(TElXMLManifestHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_set_XMLElement(TElXMLManifestHandle _Handle, TElXMLDOMElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_get_ID(TElXMLManifestHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_set_ID(TElXMLManifestHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLManifest_Create(TElXMLManifestHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLMANIFEST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureProperties_Create(TElXMLSignaturePropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_Clear(TElXMLObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_IsEmpty(TElXMLObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_LoadFromXML(TElXMLObjectHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_SaveToXML(TElXMLObjectHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_get_ID(TElXMLObjectHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_set_ID(TElXMLObjectHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_get_MimeType(TElXMLObjectHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_set_MimeType(TElXMLObjectHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_get_Encoding(TElXMLObjectHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_set_Encoding(TElXMLObjectHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_get_DataList(TElXMLObjectHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObject_Create(TElXMLObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLOBJECT */

#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectList_Add(TElXMLObjectListHandle _Handle, TElXMLObjectHandle AObject, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectList_Clear(TElXMLObjectListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectList_Delete(TElXMLObjectListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectList_Insert(TElXMLObjectListHandle _Handle, int32_t Index, TElXMLObjectHandle AObject);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectList_get_Count(TElXMLObjectListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectList_get_Objects(TElXMLObjectListHandle _Handle, int32_t Index, TElXMLObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLObjectList_Create(TElXMLObjectListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREVALUE
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_Clear(TElXMLSignatureValueHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_IsEmpty(TElXMLSignatureValueHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_LoadFromXML(TElXMLSignatureValueHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_SaveToXML(TElXMLSignatureValueHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_get_ID(TElXMLSignatureValueHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_set_ID(TElXMLSignatureValueHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_get_Value(TElXMLSignatureValueHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_set_Value(TElXMLSignatureValueHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSignatureValue_Create(TElXMLSignatureValueHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREVALUE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLSignature;
typedef TElXMLSignature ElXMLSignature;
class TElXMLSigProcessor;
typedef TElXMLSigProcessor ElXMLSigProcessor;
class TElXMLSigner;
typedef TElXMLSigner ElXMLSigner;
class TElXMLVerifier;
typedef TElXMLVerifier ElXMLVerifier;
class TElXMLSignatureMethodType;
typedef TElXMLSignatureMethodType ElXMLSignatureMethodType;
class TElXMLSignedInfo;
typedef TElXMLSignedInfo ElXMLSignedInfo;
class TElXMLManifest;
typedef TElXMLManifest ElXMLManifest;
class TElXMLSignatureProperties;
typedef TElXMLSignatureProperties ElXMLSignatureProperties;
class TElXMLObject;
typedef TElXMLObject ElXMLObject;
class TElXMLObjectList;
typedef TElXMLObjectList ElXMLObjectList;
class TElXMLSignatureValue;
typedef TElXMLSignatureValue ElXMLSignatureValue;

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
class TElXMLSignature: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignature)
#ifdef SB_USE_CLASS_TELXMLSIGNEDINFO
		TElXMLSignedInfo* _Inst_SignedInfo;
#endif /* SB_USE_CLASS_TELXMLSIGNEDINFO */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREVALUE
		TElXMLSignatureValue* _Inst_SignatureValue;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREVALUE */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
		TElXMLKeyInfo* _Inst_KeyInfo;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
		TElXMLObjectList* _Inst_Objects;
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
		TElXMLQualifyingProperties* _Inst_QualifyingProperties;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
		TElXMLQualifyingPropertiesReferenceList* _Inst_QualifyingPropertiesReferences;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

		void initInstances();

	public:
		virtual void Clear();

		bool IsEmpty();

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
#ifdef SB_USE_CLASS_TELXMLSIGNEDINFO
		virtual TElXMLSignedInfo* get_SignedInfo();

		virtual void set_SignedInfo(TElXMLSignedInfo &Value);

		virtual void set_SignedInfo(TElXMLSignedInfo *Value);

		SB_DECLARE_PROPERTY(TElXMLSignedInfo*, get_SignedInfo, set_SignedInfo, TElXMLSignature, SignedInfo);
#endif /* SB_USE_CLASS_TELXMLSIGNEDINFO */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREVALUE
		virtual TElXMLSignatureValue* get_SignatureValue();

		virtual void set_SignatureValue(TElXMLSignatureValue &Value);

		virtual void set_SignatureValue(TElXMLSignatureValue *Value);

		SB_DECLARE_PROPERTY(TElXMLSignatureValue*, get_SignatureValue, set_SignatureValue, TElXMLSignature, SignatureValue);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREVALUE */

#ifdef SB_USE_CLASS_TELXMLKEYINFO
		virtual TElXMLKeyInfo* get_KeyInfo();

		virtual void set_KeyInfo(TElXMLKeyInfo &Value);

		virtual void set_KeyInfo(TElXMLKeyInfo *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfo*, get_KeyInfo, set_KeyInfo, TElXMLSignature, KeyInfo);
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
		virtual TElXMLObjectList* get_Objects();

		virtual void set_Objects(TElXMLObjectList &Value);

		virtual void set_Objects(TElXMLObjectList *Value);

		SB_DECLARE_PROPERTY(TElXMLObjectList*, get_Objects, set_Objects, TElXMLSignature, Objects);
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */

		virtual void get_SignaturePrefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignaturePrefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignaturePrefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignaturePrefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TElXMLSignatureCompliance get_SignatureCompliance();

		virtual void set_SignatureCompliance(TElXMLSignatureCompliance Value);

		SB_DECLARE_PROPERTY(TElXMLSignatureCompliance, get_SignatureCompliance, set_SignatureCompliance, TElXMLSignature, SignatureCompliance);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElXMLSignature, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
		virtual TElXMLQualifyingProperties* get_QualifyingProperties();

		virtual void set_QualifyingProperties(TElXMLQualifyingProperties &Value);

		virtual void set_QualifyingProperties(TElXMLQualifyingProperties *Value);

		SB_DECLARE_PROPERTY(TElXMLQualifyingProperties*, get_QualifyingProperties, set_QualifyingProperties, TElXMLSignature, QualifyingProperties);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
		virtual TElXMLQualifyingPropertiesReferenceList* get_QualifyingPropertiesReferences();

		SB_DECLARE_PROPERTY_GET(TElXMLQualifyingPropertiesReferenceList*, get_QualifyingPropertiesReferences, TElXMLSignature, QualifyingPropertiesReferences);
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

		TElXMLSignature(TElXMLSignatureHandle handle, TElOwnHandle ownHandle);

		TElXMLSignature();

		virtual ~TElXMLSignature();

};
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLSIGPROCESSOR
class TElXMLSigProcessor: public TElXMLProcessor
{
	private:
		SB_DISABLE_COPY(TElXMLSigProcessor)
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		TElXMLKeyInfoData* _Inst_KeyData;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
		TElXMLSignature* _Inst_Signature;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
		TElXMLAlgorithmParameters* _Inst_SignatureMethodParameters;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

		void initInstances();

	public:
		void ClearSignatureMethodParameters();

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		virtual TElXMLKeyInfoData* get_KeyData();

		virtual void set_KeyData(TElXMLKeyInfoData &Value);

		virtual void set_KeyData(TElXMLKeyInfoData *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfoData*, get_KeyData, set_KeyData, TElXMLSigProcessor, KeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
		virtual TElXMLSignature* get_Signature();

		virtual void set_Signature(TElXMLSignature &Value);

		virtual void set_Signature(TElXMLSignature *Value);

		SB_DECLARE_PROPERTY(TElXMLSignature*, get_Signature, set_Signature, TElXMLSigProcessor, Signature);
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
		virtual TElXMLAlgorithmParameters* get_SignatureMethodParameters();

		virtual void set_SignatureMethodParameters(TElXMLAlgorithmParameters &Value);

		virtual void set_SignatureMethodParameters(TElXMLAlgorithmParameters *Value);

		SB_DECLARE_PROPERTY(TElXMLAlgorithmParameters*, get_SignatureMethodParameters, set_SignatureMethodParameters, TElXMLSigProcessor, SignatureMethodParameters);
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

		TElXMLSigProcessor(TElXMLSigProcessorHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSigProcessor(TComponent &AOwner);

		explicit TElXMLSigProcessor(TComponent *AOwner);

		virtual ~TElXMLSigProcessor();

};
#endif /* SB_USE_CLASS_TELXMLSIGPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLSIGNER
class TElXMLSigner: public TElXMLSigProcessor
{
	private:
		SB_DISABLE_COPY(TElXMLSigner)
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		TElXMLReferenceList* _Inst_References;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
		TElRemoteSigningParams* _Inst_RemoteSigningParams;
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */
#ifdef SB_USE_CLASS_TELXADESSIGNER
		TElXAdESSigner* _Inst_XAdESProcessor;
#endif /* SB_USE_CLASS_TELXADESSIGNER */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMDOCUMENT
		void CompleteAsyncSign(TElXMLDOMDocument &Document, TElDCAsyncState &State);

		void CompleteAsyncSign(TElXMLDOMDocument *Document, TElDCAsyncState *State);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMNODE
		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMNode &Node);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMNODE */

		void GenerateSignature();

		void GenerateSignatureAsync();

		void Sign();

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		void Save(TElXMLDOMNode &Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLDOMDocumentHandle SaveDetached();
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElementHandle SaveEnveloped(TElXMLDOMElement &ParentElement);

		TElXMLDOMElementHandle SaveEnveloped(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
		TElXMLDOMElementHandle SaveEnveloping(TElXMLDOMNode &EnvelopingNode);

		TElXMLDOMElementHandle SaveEnveloping(TElXMLDOMNode *EnvelopingNode);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

		void UpdateReferencesDigest();

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		virtual TElXMLReferenceList* get_References();

		virtual void set_References(TElXMLReferenceList &Value);

		virtual void set_References(TElXMLReferenceList *Value);

		SB_DECLARE_PROPERTY(TElXMLReferenceList*, get_References, set_References, TElXMLSigner, References);
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
		virtual TElRemoteSigningParams* get_RemoteSigningParams();

		SB_DECLARE_PROPERTY_GET(TElRemoteSigningParams*, get_RemoteSigningParams, TElXMLSigner, RemoteSigningParams);
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */

#ifdef SB_USE_CLASS_TELXADESSIGNER
		virtual TElXAdESSigner* get_XAdESProcessor();

		virtual void set_XAdESProcessor(TElXAdESSigner &Value);

		virtual void set_XAdESProcessor(TElXAdESSigner *Value);

		SB_DECLARE_PROPERTY(TElXAdESSigner*, get_XAdESProcessor, set_XAdESProcessor, TElXMLSigner, XAdESProcessor);
#endif /* SB_USE_CLASS_TELXADESSIGNER */

		virtual TElXMLCanonicalizationMethod get_CanonicalizationMethod();

		virtual void set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value);

		SB_DECLARE_PROPERTY(TElXMLCanonicalizationMethod, get_CanonicalizationMethod, set_CanonicalizationMethod, TElXMLSigner, CanonicalizationMethod);

		virtual void get_InclusiveNamespacesPrefixList(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_InclusiveNamespacesPrefixList(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_InclusiveNamespacesPrefixList(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_InclusiveNamespacesPrefixList(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TElXMLSignatureType get_SignatureType();

		virtual void set_SignatureType(TElXMLSignatureType Value);

		SB_DECLARE_PROPERTY(TElXMLSignatureType, get_SignatureType, set_SignatureType, TElXMLSigner, SignatureType);

		virtual TElXMLSignatureCompliance get_SignatureCompliance();

		virtual void set_SignatureCompliance(TElXMLSignatureCompliance Value);

		SB_DECLARE_PROPERTY(TElXMLSignatureCompliance, get_SignatureCompliance, set_SignatureCompliance, TElXMLSigner, SignatureCompliance);

		virtual TElXMLSigMethodType get_SignatureMethodType();

		virtual void set_SignatureMethodType(TElXMLSigMethodType Value);

		SB_DECLARE_PROPERTY(TElXMLSigMethodType, get_SignatureMethodType, set_SignatureMethodType, TElXMLSigner, SignatureMethodType);

		virtual TElXMLMACMethod get_MACMethod();

		virtual void set_MACMethod(TElXMLMACMethod Value);

		SB_DECLARE_PROPERTY(TElXMLMACMethod, get_MACMethod, set_MACMethod, TElXMLSigner, MACMethod);

		virtual TElXMLSignatureMethod get_SignatureMethod();

		virtual void set_SignatureMethod(TElXMLSignatureMethod Value);

		SB_DECLARE_PROPERTY(TElXMLSignatureMethod, get_SignatureMethod, set_SignatureMethod, TElXMLSigner, SignatureMethod);

		virtual bool get_IncludeKey();

		virtual void set_IncludeKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeKey, set_IncludeKey, TElXMLSigner, IncludeKey);

		virtual void get_KeyName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_KeyName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_KeyName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_KeyName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_EnvelopingObjectID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_EnvelopingObjectID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_EnvelopingObjectID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_EnvelopingObjectID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_OnFormatElement(TSBXMLFormatElementEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFormatElement(TSBXMLFormatElementEvent pMethodValue, void * pDataValue);

		virtual void get_OnFormatText(TSBXMLFormatTextEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFormatText(TSBXMLFormatTextEvent pMethodValue, void * pDataValue);

		virtual void get_OnRemoteSign(TSBXMLRemoteSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRemoteSign(TSBXMLRemoteSignEvent pMethodValue, void * pDataValue);

		TElXMLSigner(TElXMLSignerHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSigner(TComponent &AOwner);

		explicit TElXMLSigner(TComponent *AOwner);

		virtual ~TElXMLSigner();

};
#endif /* SB_USE_CLASS_TELXMLSIGNER */

#ifdef SB_USE_CLASS_TELXMLVERIFIER
class TElXMLVerifier: public TElXMLSigProcessor
{
	private:
		SB_DISABLE_COPY(TElXMLVerifier)
#ifdef SB_USE_CLASS_TELXMLKEYINFOHMACDATA
		TElXMLKeyInfoHMACData* _Inst_HMACKey;
#endif /* SB_USE_CLASS_TELXMLKEYINFOHMACDATA */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		TElXMLReferenceList* _Inst_References;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_SignerCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		TElXMLKeyInfoData* _Inst_SignerKeyData;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXADESVERIFIER
		TElXAdESVerifier* _Inst_XAdESProcessor;
#endif /* SB_USE_CLASS_TELXADESVERIFIER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void Load(TElXMLDOMElement &Element);

		void Load(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		bool ValidateSignature();

#ifdef SB_USE_CLASS_TELXMLREFERENCE
		bool ValidateReference(TElXMLReference &Reference);

		bool ValidateReference(TElXMLReference *Reference);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		bool ValidateReferences();

		void RemoveSignature();

#ifdef SB_USE_CLASS_TELXMLKEYINFOHMACDATA
		virtual TElXMLKeyInfoHMACData* get_HMACKey();

		virtual void set_HMACKey(TElXMLKeyInfoHMACData &Value);

		virtual void set_HMACKey(TElXMLKeyInfoHMACData *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfoHMACData*, get_HMACKey, set_HMACKey, TElXMLVerifier, HMACKey);
#endif /* SB_USE_CLASS_TELXMLKEYINFOHMACDATA */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		virtual TElXMLReferenceList* get_References();

		SB_DECLARE_PROPERTY_GET(TElXMLReferenceList*, get_References, TElXMLVerifier, References);
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

		virtual TElXMLCanonicalizationMethod get_CanonicalizationMethod();

		SB_DECLARE_PROPERTY_GET(TElXMLCanonicalizationMethod, get_CanonicalizationMethod, TElXMLVerifier, CanonicalizationMethod);

		virtual void get_InclusiveNamespacesPrefixList(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_InclusiveNamespacesPrefixList(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual TElXMLSignatureTypes get_SignatureType();

		SB_DECLARE_PROPERTY_GET(TElXMLSignatureTypes, get_SignatureType, TElXMLVerifier, SignatureType);

		virtual TElXMLSignatureCompliance get_SignatureCompliance();

		SB_DECLARE_PROPERTY_GET(TElXMLSignatureCompliance, get_SignatureCompliance, TElXMLVerifier, SignatureCompliance);

		virtual TElXMLSigMethodType get_SignatureMethodType();

		SB_DECLARE_PROPERTY_GET(TElXMLSigMethodType, get_SignatureMethodType, TElXMLVerifier, SignatureMethodType);

		virtual TElXMLMACMethod get_MACMethod();

		SB_DECLARE_PROPERTY_GET(TElXMLMACMethod, get_MACMethod, TElXMLVerifier, MACMethod);

		virtual TElXMLSignatureMethod get_SignatureMethod();

		SB_DECLARE_PROPERTY_GET(TElXMLSignatureMethod, get_SignatureMethod, TElXMLVerifier, SignatureMethod);

		virtual bool get_KeyDataNeeded();

		SB_DECLARE_PROPERTY_GET(bool, get_KeyDataNeeded, TElXMLVerifier, KeyDataNeeded);

		virtual void get_KeyName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_KeyName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_SignerCertificate();

		SB_DECLARE_PROPERTY_GET(TElX509Certificate*, get_SignerCertificate, TElXMLVerifier, SignerCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		virtual TElXMLKeyInfoData* get_SignerKeyData();

		SB_DECLARE_PROPERTY_GET(TElXMLKeyInfoData*, get_SignerKeyData, TElXMLVerifier, SignerKeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXADESVERIFIER
		virtual TElXAdESVerifier* get_XAdESProcessor();

		virtual void set_XAdESProcessor(TElXAdESVerifier &Value);

		virtual void set_XAdESProcessor(TElXAdESVerifier *Value);

		SB_DECLARE_PROPERTY(TElXAdESVerifier*, get_XAdESProcessor, set_XAdESProcessor, TElXMLVerifier, XAdESProcessor);
#endif /* SB_USE_CLASS_TELXADESVERIFIER */

		TElXMLVerifier(TElXMLVerifierHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLVerifier(TComponent &AOwner);

		explicit TElXMLVerifier(TComponent *AOwner);

		virtual ~TElXMLVerifier();

};
#endif /* SB_USE_CLASS_TELXMLVERIFIER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE
class TElXMLSignatureMethodType: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignatureMethodType)
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
		TElXMLAlgorithmParameters* _Inst_Parameters;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

		void initInstances();

	public:
		virtual void Clear();

		bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Algorithm(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Algorithm(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Algorithm(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Algorithm(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_HMACOutputLength();

		virtual void set_HMACOutputLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HMACOutputLength, set_HMACOutputLength, TElXMLSignatureMethodType, HMACOutputLength);

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
		virtual TElXMLAlgorithmParameters* get_Parameters();

		virtual void set_Parameters(TElXMLAlgorithmParameters &Value);

		virtual void set_Parameters(TElXMLAlgorithmParameters *Value);

		SB_DECLARE_PROPERTY(TElXMLAlgorithmParameters*, get_Parameters, set_Parameters, TElXMLSignatureMethodType, Parameters);
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

		TElXMLSignatureMethodType(TElXMLSignatureMethodTypeHandle handle, TElOwnHandle ownHandle);

		TElXMLSignatureMethodType();

		virtual ~TElXMLSignatureMethodType();

};
#endif /* SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLSIGNEDINFO
class TElXMLSignedInfo: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignedInfo)
#ifdef SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE
		TElXMLSignatureMethodType* _Inst_SignatureMethod;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		TElXMLReferenceList* _Inst_References;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELXMLREFERENCE
		TElXMLReference* _Inst_SigPropRef;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		void initInstances();

	public:
		virtual void Clear();

		bool IsEmpty();

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
		virtual void get_CanonicalizationMethod(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CanonicalizationMethod(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CanonicalizationMethod(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_CanonicalizationMethod(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ExclusiveCanonicalizationPrefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ExclusiveCanonicalizationPrefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ExclusiveCanonicalizationPrefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ExclusiveCanonicalizationPrefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_InclusiveNamespacesPrefixList(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_InclusiveNamespacesPrefixList(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_InclusiveNamespacesPrefixList(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_InclusiveNamespacesPrefixList(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE
		virtual TElXMLSignatureMethodType* get_SignatureMethod();

		virtual void set_SignatureMethod(TElXMLSignatureMethodType &Value);

		virtual void set_SignatureMethod(TElXMLSignatureMethodType *Value);

		SB_DECLARE_PROPERTY(TElXMLSignatureMethodType*, get_SignatureMethod, set_SignatureMethod, TElXMLSignedInfo, SignatureMethod);
#endif /* SB_USE_CLASS_TELXMLSIGNATUREMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		virtual TElXMLReferenceList* get_References();

		virtual void set_References(TElXMLReferenceList &Value);

		virtual void set_References(TElXMLReferenceList *Value);

		SB_DECLARE_PROPERTY(TElXMLReferenceList*, get_References, set_References, TElXMLSignedInfo, References);
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
		virtual TElXMLReference* get_SigPropRef();

		SB_DECLARE_PROPERTY_GET(TElXMLReference*, get_SigPropRef, TElXMLSignedInfo, SigPropRef);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		TElXMLSignedInfo(TElXMLSignedInfoHandle handle, TElOwnHandle ownHandle);

		TElXMLSignedInfo();

		virtual ~TElXMLSignedInfo();

};
#endif /* SB_USE_CLASS_TELXMLSIGNEDINFO */

#ifdef SB_USE_CLASS_TELXMLMANIFEST
class TElXMLManifest: public TElXMLReferenceList
{
	private:
		SB_DISABLE_COPY(TElXMLManifest)
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_XMLElement;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		void initInstances();

	public:
		virtual void Clear();

		bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_XMLElement();

		virtual void set_XMLElement(TElXMLDOMElement &Value);

		virtual void set_XMLElement(TElXMLDOMElement *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMElement*, get_XMLElement, set_XMLElement, TElXMLManifest, XMLElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLManifest(TElXMLManifestHandle handle, TElOwnHandle ownHandle);

		TElXMLManifest();

		virtual ~TElXMLManifest();

};
#endif /* SB_USE_CLASS_TELXMLMANIFEST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPROPERTIES
class TElXMLSignatureProperties: public TElXMLProperties
{
	private:
		SB_DISABLE_COPY(TElXMLSignatureProperties)
	public:
		TElXMLSignatureProperties(TElXMLSignaturePropertiesHandle handle, TElOwnHandle ownHandle);

		TElXMLSignatureProperties();

};
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLOBJECT
class TElXMLObject: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLObject)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_DataList;
#endif /* SB_USE_CLASS_TLIST */

		void initInstances();

	public:
		virtual void Clear();

		bool IsEmpty();

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
#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_DataList();

		SB_DECLARE_PROPERTY_GET(TList*, get_DataList, TElXMLObject, DataList);
#endif /* SB_USE_CLASS_TLIST */

		TElXMLObject(TElXMLObjectHandle handle, TElOwnHandle ownHandle);

		TElXMLObject();

		virtual ~TElXMLObject();

};
#endif /* SB_USE_CLASS_TELXMLOBJECT */

#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
class TElXMLObjectList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLObjectList)
#ifdef SB_USE_CLASS_TELXMLOBJECT
		TElXMLObject* _Inst_Objects;
#endif /* SB_USE_CLASS_TELXMLOBJECT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLOBJECT
		int32_t Add(TElXMLObject &AObject);

		int32_t Add(TElXMLObject *AObject);
#endif /* SB_USE_CLASS_TELXMLOBJECT */

		void Clear();

		void Delete(int32_t Index);

#ifdef SB_USE_CLASS_TELXMLOBJECT
		void Insert(int32_t Index, TElXMLObject &AObject);

		void Insert(int32_t Index, TElXMLObject *AObject);
#endif /* SB_USE_CLASS_TELXMLOBJECT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLObjectList, Count);

#ifdef SB_USE_CLASS_TELXMLOBJECT
		virtual TElXMLObject* get_Objects(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLOBJECT */

		TElXMLObjectList(TElXMLObjectListHandle handle, TElOwnHandle ownHandle);

		TElXMLObjectList();

		virtual ~TElXMLObjectList();

};
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREVALUE
class TElXMLSignatureValue: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLSignatureValue)
	public:
		virtual void Clear();

		bool IsEmpty();

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
		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElXMLSignatureValue(TElXMLSignatureValueHandle handle, TElOwnHandle ownHandle);

		TElXMLSignatureValue();

};
#endif /* SB_USE_CLASS_TELXMLSIGNATUREVALUE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSIG */

