#ifndef __INC_SBXMLSAMLCORE
#define __INC_SBXMLSAMLCORE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbcertvalidator.h"
#include "sbcustomcertstorage.h"
#include "sbx509.h"
#include "sbsharedresource.h"
#include "sbxmlcore.h"
#include "sbxmlsig.h"
#include "sbxmlenc.h"
#include "sbxmlsec.h"
#include "sbxmlutils.h"
#include "sbxmldefs.h"
#include "sbxmltransform.h"
#include "sbxmlcharsets.h"
#include "sbstreams.h"
#include "sbstrutils.h"
#include "sbrandom.h"
#include "sbutils.h"
#include "sbtypes.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_BUF_SZ 	102400
#define SB_SAML_TIMEZONE_UTC 	0
#define SB_SAML_TIMEZONE_LOCAL 	-1
#define SB_SAMLVersion 	"2.0"
#define SB_xmlSAMLAssertionNamespace 	"urn:oasis:names:tc:SAML:2.0:assertion"
#define SB_xmlSAMLProtocolNamespace 	"urn:oasis:names:tc:SAML:2.0:protocol"
#define SB_xmlSAMLMetadataNamespace 	"urn:oasis:names:tc:SAML:2.0:metadata"
#define SB_xmlSAMLMDPrefix 	"md"
#define SB_xmlSAMLNameIDFormatUnspecified 	"urn:oasis:names:tc:SAML:1.1:nameid-format:unspecified"
#define SB_xmlSAMLNameIDFormatEmailAddress11 	"urn:oasis:names:tc:SAML:1.1:nameid-format:emailAddress"
#define SB_xmlSAMLNameIDFormatEmailAddress 	"urn:oasis:names:tc:SAML:2.0:nameid-format:email"
#define SB_xmlSAMLNameIDFormatX509SubjectName 	"urn:oasis:names:tc:SAML:1.1:nameid-format:X509SubjectName"
#define SB_xmlSAMLNameIDFormatWindowsDomainQualifiedName 	"urn:oasis:names:tc:SAML:1.1:nameid-format:WindowsDomainQualifiedName"
#define SB_xmlSAMLNameIDFormatKerberos 	"urn:oasis:names:tc:SAML:2.0:nameid-format:kerberos"
#define SB_xmlSAMLNameIDFormatEntity 	"urn:oasis:names:tc:SAML:2.0:nameid-format:entity"
#define SB_xmlSAMLNameIDFormatPersistent 	"urn:oasis:names:tc:SAML:2.0:nameid-format:persistent"
#define SB_xmlSAMLNameIDFormatTransient 	"urn:oasis:names:tc:SAML:2.0:nameid-format:transient"
#define SB_xmlSAMLKeyInfoConfirmationDataType 	"saml:KeyInfoConfirmationDataType"
#define SB_xmlSAMLPrefix 	"saml"
#define SB_xmlSAMLProtocolPrefix 	"samlp"
#define SB_SNotImplemented 	"Not implemented"
#define SB_SMissingAttribute 	"Missing required attribute"
#define SB_SMissingElement 	"Missing required element"
#define SB_SInvalidAttributeValue 	"Invalid attribute value"
#define SB_SEncryptionError 	"Encryption error"
#ifndef SB_SDecryptionError
#define SB_SDecryptionError 	"Decryption error %d"
#endif
#define SB_SInvalidTypeCast 	"Invalid type cast"
#ifndef SB_SInvalidSignature
#define SB_SInvalidSignature 	"Element signature is invalid"
#endif
#define SB_SPermit 	"Permit"
#define SB_SDeny 	"Deny"
#define SB_SIndeterminate 	"Indeterminate"
#define SB_STrue1 	"true"
#define SB_STrue2 	"1"
#define SB_SFalse1 	"false"
#define SB_SFalse2 	"0"

typedef TElClassHandle TElSAMLSubjectElementHandle;

typedef TElClassHandle TElSAMLConditionsElementHandle;

typedef TElClassHandle TElSAMLAdviceElementHandle;

typedef TElClassHandle TElSAMLSubjectConfirmationDataElementHandle;

typedef TElClassHandle TElSAMLStatementAbstractTypeHandle;

typedef TElClassHandle TElSAMLSubjectConfirmationElementHandle;

typedef TElClassHandle TElSAMLSecurityHandlerHandle;

typedef TElClassHandle TElSAMLSignatureHandlerHandle;

typedef TElClassHandle TElSAMLEncryptionHandlerHandle;

typedef TElClassHandle TElSAMLElementHandle;

typedef TElClassHandle TElSAMLIDHandle;

typedef TElClassHandle TElSAMLBaseIDElementHandle;

typedef TElClassHandle TElSAMLNameIDElementHandle;

typedef TElClassHandle TElSAMLEncryptedElementHandle;

typedef TElClassHandle TElSAMLEncryptedIDElementHandle;

typedef TElClassHandle TElSAMLIssuerElementHandle;

typedef TElClassHandle TElSAMLAssertionTypeHandle;

typedef TElClassHandle TElSAMLAssertionIDRefElementHandle;

typedef TElClassHandle TElSAMLAssertionURIRefElementHandle;

typedef TElClassHandle TElSAMLAssertionElementHandle;

typedef TElClassHandle TElSAMLEncryptedAssertionElementHandle;

typedef TElClassHandle TElSAMLConditionAbstractTypeHandle;

typedef TElClassHandle TElSAMLAudienceElementHandle;

typedef TElClassHandle TElSAMLAudienceRestrictionElementHandle;

typedef TElClassHandle TElSAMLOneTimeUseElementHandle;

typedef TElClassHandle TElSAMLProxyRestrictionElementHandle;

typedef TElClassHandle TElSAMLSubjectLocalityElementHandle;

typedef TElSAMLElementHandle TElSAMLAuthnContextDeclHandle;

typedef TElClassHandle TElSAMLAuthnContextElementHandle;

typedef TElClassHandle TElSAMLAuthnStatementElementHandle;

typedef TElClassHandle TElSAMLAttributeTypeHandle;

typedef TElClassHandle TElSAMLAttributeValueHandle;

typedef TElClassHandle TElSAMLAttributeElementHandle;

typedef TElClassHandle TElSAMLEncryptedAttributeElementHandle;

typedef TElClassHandle TElSAMLAttributeStatementElementHandle;

typedef TElClassHandle TElSAMLActionElementHandle;

typedef TElClassHandle TElSAMLEvidenceElementHandle;

typedef TElClassHandle TElSAMLAuthzDecisionStatementElementHandle;

typedef void (SB_CALLBACK *TSBSAMLCertValidatorPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateValidatorHandle * CertValidator, TElX509CertificateHandle Cert);

typedef void (SB_CALLBACK *TSBSAMLXMLSignerPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElXMLSignerHandle * Signer);

typedef void (SB_CALLBACK *TSBSAMLXMLVerifierPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElXMLVerifierHandle * Verifier);

typedef void (SB_CALLBACK *TSBSAMLXMLEncryptorPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElXMLEncryptorHandle * Encryptor);

typedef void (SB_CALLBACK *TSBSAMLXMLDecryptorPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElXMLDecryptorHandle * Decryptor);

typedef uint8_t TSBSAMLAuthnContextChoiceRaw;

typedef enum
{
	sacV1 = 0,
	sacV2 = 1
} TSBSAMLAuthnContextChoice;

typedef uint8_t TSBSAMLDecisionRaw;

typedef enum
{
	sadnPermit = 0,
	sadnDeny = 1,
	sadnIndeterminate = 2
} TSBSAMLDecision;

#ifdef SB_USE_CLASS_TELSAMLELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_Assign(TElSAMLElementHandle _Handle, TElSAMLElementHandle Other);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_LoadFromXML(TElSAMLElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_SaveToXML(TElSAMLElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_get_Tag(TElSAMLElementHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_set_Tag(TElSAMLElementHandle _Handle, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_get_Handler(TElSAMLElementHandle _Handle, TElSAMLSecurityHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_set_Handler(TElSAMLElementHandle _Handle, TElSAMLSecurityHandlerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_get_TextValue(TElSAMLElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_Clear(TElSAMLConditionsElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_LoadFromXML(TElSAMLConditionsElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_SaveToXML(TElSAMLConditionsElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_AddCondition(TElSAMLConditionsElementHandle _Handle, TElSAMLConditionAbstractTypeHandle Cond, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_RemoveCondition(TElSAMLConditionsElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_get_OneTimeUse(TElSAMLConditionsElementHandle _Handle, TElSAMLOneTimeUseElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_get_ProxyRestriction(TElSAMLConditionsElementHandle _Handle, TElSAMLProxyRestrictionElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_get_NotBefore(TElSAMLConditionsElementHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_set_NotBefore(TElSAMLConditionsElementHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_get_NotOnOrAfter(TElSAMLConditionsElementHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_set_NotOnOrAfter(TElSAMLConditionsElementHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_get_Conditions(TElSAMLConditionsElementHandle _Handle, int32_t Index, TElSAMLConditionAbstractTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_get_ConditionCount(TElSAMLConditionsElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionsElement_Create(TElSAMLConditionsElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLADVICEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_Clear(TElSAMLAdviceElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_LoadFromXML(TElSAMLAdviceElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_SaveToXML(TElSAMLAdviceElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_AddAssertion(TElSAMLAdviceElementHandle _Handle, TElSAMLAssertionTypeHandle Assertion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_RemoveAssertion(TElSAMLAdviceElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_get_Others(TElSAMLAdviceElementHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_get_Assertions(TElSAMLAdviceElementHandle _Handle, int32_t Index, TElSAMLAssertionTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_get_AssertionCount(TElSAMLAdviceElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdviceElement_Create(TElSAMLAdviceElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLADVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_Clear(TElSAMLSubjectConfirmationDataElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_LoadFromXML(TElSAMLSubjectConfirmationDataElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_SaveToXML(TElSAMLSubjectConfirmationDataElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_AddArbitraryElement(TElSAMLSubjectConfirmationDataElementHandle _Handle, TElXMLCustomElementHandle Elem, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_AddArbitraryAttribute(TElSAMLSubjectConfirmationDataElementHandle _Handle, TElXMLDOMAttrHandle Attr, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_RemoveArbitraryElement(TElSAMLSubjectConfirmationDataElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_RemoveArbitraryAttribute(TElSAMLSubjectConfirmationDataElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_AType(TElSAMLSubjectConfirmationDataElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_set_AType(TElSAMLSubjectConfirmationDataElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_NotBefore(TElSAMLSubjectConfirmationDataElementHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_set_NotBefore(TElSAMLSubjectConfirmationDataElementHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_NotOnOrAfter(TElSAMLSubjectConfirmationDataElementHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_set_NotOnOrAfter(TElSAMLSubjectConfirmationDataElementHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_Recipient(TElSAMLSubjectConfirmationDataElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_set_Recipient(TElSAMLSubjectConfirmationDataElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_InResponseTo(TElSAMLSubjectConfirmationDataElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_set_InResponseTo(TElSAMLSubjectConfirmationDataElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_Address(TElSAMLSubjectConfirmationDataElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_set_Address(TElSAMLSubjectConfirmationDataElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_ArbitraryElements(TElSAMLSubjectConfirmationDataElementHandle _Handle, int32_t Index, TElXMLCustomElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_ArbitraryAttributes(TElSAMLSubjectConfirmationDataElementHandle _Handle, int32_t Index, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_ArbitraryElementCount(TElSAMLSubjectConfirmationDataElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_get_ArbitraryAttributeCount(TElSAMLSubjectConfirmationDataElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationDataElement_Create(TElSAMLSubjectConfirmationDataElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatementAbstractType_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_Clear(TElSAMLSubjectConfirmationElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_LoadFromXML(TElSAMLSubjectConfirmationElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_SaveToXML(TElSAMLSubjectConfirmationElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_get_ID(TElSAMLSubjectConfirmationElementHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_set_ID(TElSAMLSubjectConfirmationElementHandle _Handle, TElSAMLIDHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_get_SubjectConfirmationData(TElSAMLSubjectConfirmationElementHandle _Handle, TElSAMLSubjectConfirmationDataElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_set_SubjectConfirmationData(TElSAMLSubjectConfirmationElementHandle _Handle, TElSAMLSubjectConfirmationDataElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_get__Method(TElSAMLSubjectConfirmationElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_set__Method(TElSAMLSubjectConfirmationElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectConfirmationElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSecurityHandler_Protect(TElSAMLSecurityHandlerHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle Node, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSecurityHandler_Unprotect(TElSAMLSecurityHandlerHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle Input, TElXMLDOMElementHandle * Output, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSecurityHandler_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELSAMLSIGNATUREHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_Protect(TElSAMLSignatureHandlerHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle Elem, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_Unprotect(TElSAMLSignatureHandlerHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle Input, TElXMLDOMElementHandle * Output, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_CertStorage(TElSAMLSignatureHandlerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_CertStorage(TElSAMLSignatureHandlerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_Certificate(TElSAMLSignatureHandlerHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_Certificate(TElSAMLSignatureHandlerHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_VerificationResult(TElSAMLSignatureHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_ValidateCertificate(TElSAMLSignatureHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_ValidateCertificate(TElSAMLSignatureHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_ValidateReferences(TElSAMLSignatureHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_ValidateReferences(TElSAMLSignatureHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_CanonicalizationMethod(TElSAMLSignatureHandlerHandle _Handle, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_CanonicalizationMethod(TElSAMLSignatureHandlerHandle _Handle, TElXMLCanonicalizationMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_SignatureAfterIssuer(TElSAMLSignatureHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_SignatureAfterIssuer(TElSAMLSignatureHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_OnValidatorPrepared(TElSAMLSignatureHandlerHandle _Handle, TSBSAMLCertValidatorPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_OnValidatorPrepared(TElSAMLSignatureHandlerHandle _Handle, TSBSAMLCertValidatorPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_OnSignerPrepared(TElSAMLSignatureHandlerHandle _Handle, TSBSAMLXMLSignerPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_OnSignerPrepared(TElSAMLSignatureHandlerHandle _Handle, TSBSAMLXMLSignerPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_get_OnVerifierPrepared(TElSAMLSignatureHandlerHandle _Handle, TSBSAMLXMLVerifierPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_set_OnVerifierPrepared(TElSAMLSignatureHandlerHandle _Handle, TSBSAMLXMLVerifierPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSignatureHandler_Create(TElSAMLSignatureHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_Protect(TElSAMLEncryptionHandlerHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle Elem, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_Unprotect(TElSAMLEncryptionHandlerHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle Input, TElXMLDOMElementHandle * Output, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_get_Certificate(TElSAMLEncryptionHandlerHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_set_Certificate(TElSAMLEncryptionHandlerHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_get_DecryptionResult(TElSAMLEncryptionHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_set_DecryptionResult(TElSAMLEncryptionHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_get_OnXMLEncryptorPrepared(TElSAMLEncryptionHandlerHandle _Handle, TSBSAMLXMLEncryptorPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_set_OnXMLEncryptorPrepared(TElSAMLEncryptionHandlerHandle _Handle, TSBSAMLXMLEncryptorPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_get_OnXMLDecryptorPrepared(TElSAMLEncryptionHandlerHandle _Handle, TSBSAMLXMLDecryptorPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_set_OnXMLDecryptorPrepared(TElSAMLEncryptionHandlerHandle _Handle, TSBSAMLXMLDecryptorPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptionHandler_Create(TElSAMLEncryptionHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_Clear(TElSAMLSubjectElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_LoadFromXML(TElSAMLSubjectElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_SaveToXML(TElSAMLSubjectElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_AddSubjectConfirmation(TElSAMLSubjectElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_RemoveSubjectConfirmation(TElSAMLSubjectElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_get_Sequence(TElSAMLSubjectElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_get_ID(TElSAMLSubjectElementHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_set_ID(TElSAMLSubjectElementHandle _Handle, TElSAMLIDHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_get_SubjectConfirmations(TElSAMLSubjectElementHandle _Handle, int32_t Index, TElSAMLSubjectConfirmationElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_get_SubjectConfirmationCount(TElSAMLSubjectElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectElement_Create(TElSAMLSubjectElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID
SB_IMPORT uint32_t SB_APIENTRY TElSAMLID_CompareTo(TElSAMLIDHandle _Handle, TElSAMLIDHandle Other, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLID_CreateByName(const char * pcName, int32_t szName, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLID_CreateByName_1(TElSAMLIDHandle _Handle, const char * pcName, int32_t szName, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLID_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLBASEIDELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_Clear(TElSAMLBaseIDElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_CompareTo(TElSAMLBaseIDElementHandle _Handle, TElSAMLIDHandle Other, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_LoadFromXML(TElSAMLBaseIDElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_SaveToXML(TElSAMLBaseIDElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_get_NameQualifier(TElSAMLBaseIDElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_set_NameQualifier(TElSAMLBaseIDElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_get_SPNameQualifier(TElSAMLBaseIDElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_set_SPNameQualifier(TElSAMLBaseIDElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBaseIDElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLBASEIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_Assign(TElSAMLNameIDElementHandle _Handle, TElSAMLElementHandle Other);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_Clear(TElSAMLNameIDElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_CompareTo(TElSAMLNameIDElementHandle _Handle, TElSAMLIDHandle Other, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_LoadFromXML(TElSAMLNameIDElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_SaveToXML(TElSAMLNameIDElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_get_Value(TElSAMLNameIDElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_set_Value(TElSAMLNameIDElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_get_NameQualifier(TElSAMLNameIDElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_set_NameQualifier(TElSAMLNameIDElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_get_SPNameQualifier(TElSAMLNameIDElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_set_SPNameQualifier(TElSAMLNameIDElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_get_Format(TElSAMLNameIDElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_set_Format(TElSAMLNameIDElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_get_SPProvidedID(TElSAMLNameIDElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_set_SPProvidedID(TElSAMLNameIDElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDElement_Create(TElSAMLNameIDElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLNAMEIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_Clear(TElSAMLEncryptedElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_LoadFromXML(TElSAMLEncryptedElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_SaveToXML(TElSAMLEncryptedElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_Encrypt(TElSAMLEncryptedElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_Decrypt(TElSAMLEncryptedElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_get_ElementName(TElSAMLEncryptedElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_set_ElementName(TElSAMLEncryptedElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_get_Decrypted(TElSAMLEncryptedElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_set_Decrypted(TElSAMLEncryptedElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedElement_Create(TElSAMLEncryptedElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDIDELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_Clear(TElSAMLEncryptedIDElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_CompareTo(TElSAMLEncryptedIDElementHandle _Handle, TElSAMLIDHandle Other, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_LoadFromXML(TElSAMLEncryptedIDElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_SaveToXML(TElSAMLEncryptedIDElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_Encrypt(TElSAMLEncryptedIDElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_Decrypt(TElSAMLEncryptedIDElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_get_EncryptedElement(TElSAMLEncryptedIDElementHandle _Handle, TElSAMLEncryptedElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_set_EncryptedElement(TElSAMLEncryptedIDElementHandle _Handle, TElSAMLEncryptedElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_get_ID(TElSAMLEncryptedIDElementHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_set_ID(TElSAMLEncryptedIDElementHandle _Handle, TElSAMLIDHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedIDElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIssuerElement_LoadFromXML(TElSAMLIssuerElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIssuerElement_Create(TElSAMLIssuerElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionType_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRefElement_Clear(TElSAMLAssertionIDRefElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRefElement_LoadFromXML(TElSAMLAssertionIDRefElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRefElement_SaveToXML(TElSAMLAssertionIDRefElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRefElement_get_Value(TElSAMLAssertionIDRefElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRefElement_set_Value(TElSAMLAssertionIDRefElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRefElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONURIREFELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionURIRefElement_Clear(TElSAMLAssertionURIRefElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionURIRefElement_LoadFromXML(TElSAMLAssertionURIRefElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionURIRefElement_SaveToXML(TElSAMLAssertionURIRefElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionURIRefElement_get_Value(TElSAMLAssertionURIRefElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionURIRefElement_set_Value(TElSAMLAssertionURIRefElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionURIRefElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONURIREFELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_Clear(TElSAMLAssertionElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_LoadFromXML(TElSAMLAssertionElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_LoadFromXML_1(TElSAMLAssertionElementHandle _Handle, TElXMLDOMElementHandle Element, int8_t ClearBefore);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_SaveToXML(TElSAMLAssertionElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_AddStatement(TElSAMLAssertionElementHandle _Handle, TElSAMLStatementAbstractTypeHandle St, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_RemoveStatement(TElSAMLAssertionElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_Signed(TElSAMLAssertionElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_set_Signed(TElSAMLAssertionElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_Version(TElSAMLAssertionElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_set_Version(TElSAMLAssertionElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_ID(TElSAMLAssertionElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_set_ID(TElSAMLAssertionElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_IssueInstant(TElSAMLAssertionElementHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_set_IssueInstant(TElSAMLAssertionElementHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_Issuer(TElSAMLAssertionElementHandle _Handle, TElSAMLIssuerElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_set_Issuer(TElSAMLAssertionElementHandle _Handle, TElSAMLIssuerElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_Signature(TElSAMLAssertionElementHandle _Handle, TElXMLSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_Subject(TElSAMLAssertionElementHandle _Handle, TElSAMLSubjectElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_set_Subject(TElSAMLAssertionElementHandle _Handle, TElSAMLSubjectElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_Conditions(TElSAMLAssertionElementHandle _Handle, TElSAMLConditionsElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_set_Conditions(TElSAMLAssertionElementHandle _Handle, TElSAMLConditionsElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_Advice(TElSAMLAssertionElementHandle _Handle, TElSAMLAdviceElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_set_Advice(TElSAMLAssertionElementHandle _Handle, TElSAMLAdviceElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_Statements(TElSAMLAssertionElementHandle _Handle, int32_t Index, TElSAMLStatementAbstractTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_get_StatementCount(TElSAMLAssertionElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionElement_Create(TElSAMLAssertionElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDASSERTIONELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAssertionElement_Clear(TElSAMLEncryptedAssertionElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAssertionElement_LoadFromXML(TElSAMLEncryptedAssertionElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAssertionElement_SaveToXML(TElSAMLEncryptedAssertionElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAssertionElement_Decrypt(TElSAMLEncryptedAssertionElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAssertionElement_get_Decrypted(TElSAMLEncryptedAssertionElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAssertionElement_get_EncryptedElement(TElSAMLEncryptedAssertionElementHandle _Handle, TElSAMLEncryptedElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAssertionElement_Create(TElSAMLEncryptedAssertionElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLConditionAbstractType_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceElement_Clear(TElSAMLAudienceElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceElement_LoadFromXML(TElSAMLAudienceElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceElement_SaveToXML(TElSAMLAudienceElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceElement_get_Value(TElSAMLAudienceElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceElement_set_Value(TElSAMLAudienceElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUDIENCERESTRICTIONELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceRestrictionElement_Clear(TElSAMLAudienceRestrictionElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceRestrictionElement_LoadFromXML(TElSAMLAudienceRestrictionElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceRestrictionElement_SaveToXML(TElSAMLAudienceRestrictionElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceRestrictionElement_AddAudience(TElSAMLAudienceRestrictionElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceRestrictionElement_RemoveAudience(TElSAMLAudienceRestrictionElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceRestrictionElement_get_AudienceList(TElSAMLAudienceRestrictionElementHandle _Handle, int32_t Index, TElSAMLAudienceElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceRestrictionElement_get_AudienceCount(TElSAMLAudienceRestrictionElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAudienceRestrictionElement_Create(TElSAMLAudienceRestrictionElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLAUDIENCERESTRICTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLOneTimeUseElement_LoadFromXML(TElSAMLOneTimeUseElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLOneTimeUseElement_SaveToXML(TElSAMLOneTimeUseElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLOneTimeUseElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_Clear(TElSAMLProxyRestrictionElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_LoadFromXML(TElSAMLProxyRestrictionElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_SaveToXML(TElSAMLProxyRestrictionElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_AddAudience(TElSAMLProxyRestrictionElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_RemoveAudience(TElSAMLProxyRestrictionElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_get_Count(TElSAMLProxyRestrictionElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_get_AudienceList(TElSAMLProxyRestrictionElementHandle _Handle, int32_t Index, TElSAMLAudienceElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_get_AudienceCount(TElSAMLProxyRestrictionElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLProxyRestrictionElement_Create(TElSAMLProxyRestrictionElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectLocalityElement_Clear(TElSAMLSubjectLocalityElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectLocalityElement_LoadFromXML(TElSAMLSubjectLocalityElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectLocalityElement_SaveToXML(TElSAMLSubjectLocalityElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectLocalityElement_get_Address(TElSAMLSubjectLocalityElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectLocalityElement_set_Address(TElSAMLSubjectLocalityElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectLocalityElement_get_DNSName(TElSAMLSubjectLocalityElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectLocalityElement_set_DNSName(TElSAMLSubjectLocalityElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectLocalityElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_Clear(TElSAMLAuthnContextElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_LoadFromXML(TElSAMLAuthnContextElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_SaveToXML(TElSAMLAuthnContextElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_get_Choice(TElSAMLAuthnContextElementHandle _Handle, TSBSAMLAuthnContextChoiceRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_set_Choice(TElSAMLAuthnContextElementHandle _Handle, TSBSAMLAuthnContextChoiceRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_get_AuthnContextClassRef(TElSAMLAuthnContextElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_set_AuthnContextClassRef(TElSAMLAuthnContextElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_get_AuthnContextDecl(TElSAMLAuthnContextElementHandle _Handle, TElSAMLElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_set_AuthnContextDecl(TElSAMLAuthnContextElementHandle _Handle, TElSAMLElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_get_AuthnContextDeclRef(TElSAMLAuthnContextElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_set_AuthnContextDeclRef(TElSAMLAuthnContextElementHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_get_AuthenticatingAuthorities(TElSAMLAuthnContextElementHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_get_AuthenticatingAuthorities(TElSAMLAuthnContextElementHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnContextElement_Create(TElSAMLAuthnContextElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNSTATEMENTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_Clear(TElSAMLAuthnStatementElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_LoadFromXML(TElSAMLAuthnStatementElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_SaveToXML(TElSAMLAuthnStatementElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_get_AuthnInstant(TElSAMLAuthnStatementElementHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_set_AuthnInstant(TElSAMLAuthnStatementElementHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_get_SessionIndex(TElSAMLAuthnStatementElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_set_SessionIndex(TElSAMLAuthnStatementElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_get_SessionNotOnOrAfter(TElSAMLAuthnStatementElementHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_set_SessionNotOnOrAfter(TElSAMLAuthnStatementElementHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_get_SubjectLocality(TElSAMLAuthnStatementElementHandle _Handle, TElSAMLSubjectLocalityElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_set_SubjectLocality(TElSAMLAuthnStatementElementHandle _Handle, TElSAMLSubjectLocalityElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_get_AuthnContext(TElSAMLAuthnStatementElementHandle _Handle, TElSAMLAuthnContextElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_set_AuthnContext(TElSAMLAuthnStatementElementHandle _Handle, TElSAMLAuthnContextElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnStatementElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLAUTHNSTATEMENTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeType_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEVALUE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeValue_Clear(TElSAMLAttributeValueHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeValue_LoadFromXML(TElSAMLAttributeValueHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeValue_SaveToXML(TElSAMLAttributeValueHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeValue_get_Value(TElSAMLAttributeValueHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeValue_set_Value(TElSAMLAttributeValueHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeValue_get_ContentType(TElSAMLAttributeValueHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeValue_set_ContentType(TElSAMLAttributeValueHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeValue_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_Clear(TElSAMLAttributeElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_LoadFromXML(TElSAMLAttributeElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_SaveToXML(TElSAMLAttributeElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_AddArbitraryAttribute(TElSAMLAttributeElementHandle _Handle, TElXMLDOMAttrHandle Attr, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_RemoveArbitraryAttribute(TElSAMLAttributeElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_AddValue(TElSAMLAttributeElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_RemoveValue(TElSAMLAttributeElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_get_Name(TElSAMLAttributeElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_set_Name(TElSAMLAttributeElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_get_NameFormat(TElSAMLAttributeElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_set_NameFormat(TElSAMLAttributeElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_get_FriendlyName(TElSAMLAttributeElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_set_FriendlyName(TElSAMLAttributeElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_get_Values(TElSAMLAttributeElementHandle _Handle, int32_t Index, TElSAMLAttributeValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_get_ValueCount(TElSAMLAttributeElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_get_ArbitraryAttributes(TElSAMLAttributeElementHandle _Handle, int32_t Index, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_get_ArbitraryAttributeCount(TElSAMLAttributeElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeElement_Create(TElSAMLAttributeElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDATTRIBUTEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAttributeElement_Clear(TElSAMLEncryptedAttributeElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAttributeElement_LoadFromXML(TElSAMLEncryptedAttributeElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAttributeElement_SaveToXML(TElSAMLEncryptedAttributeElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAttributeElement_get_EncryptedElement(TElSAMLEncryptedAttributeElementHandle _Handle, TElSAMLEncryptedElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAttributeElement_set_EncryptedElement(TElSAMLEncryptedAttributeElementHandle _Handle, TElSAMLEncryptedElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEncryptedAttributeElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTESTATEMENTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeStatementElement_Clear(TElSAMLAttributeStatementElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeStatementElement_LoadFromXML(TElSAMLAttributeStatementElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeStatementElement_SaveToXML(TElSAMLAttributeStatementElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeStatementElement_AddAttribute(TElSAMLAttributeStatementElementHandle _Handle, TElSAMLAttributeTypeHandle Attr, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeStatementElement_RemoveAttribute(TElSAMLAttributeStatementElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeStatementElement_get_Attributes(TElSAMLAttributeStatementElementHandle _Handle, int32_t Index, TElSAMLAttributeTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeStatementElement_get_AttributeCount(TElSAMLAttributeStatementElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeStatementElement_Create(TElSAMLAttributeStatementElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTESTATEMENTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLActionElement_Clear(TElSAMLActionElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLActionElement_LoadFromXML(TElSAMLActionElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLActionElement_SaveToXML(TElSAMLActionElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLActionElement_get__Namespace(TElSAMLActionElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLActionElement_set__Namespace(TElSAMLActionElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLActionElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEvidenceElement_Clear(TElSAMLEvidenceElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEvidenceElement_LoadFromXML(TElSAMLEvidenceElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEvidenceElement_SaveToXML(TElSAMLEvidenceElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEvidenceElement_AddAssertion(TElSAMLEvidenceElementHandle _Handle, TElSAMLAssertionTypeHandle Assertion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEvidenceElement_RemoveAssertion(TElSAMLEvidenceElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEvidenceElement_get_Assertions(TElSAMLEvidenceElementHandle _Handle, int32_t Index, TElSAMLAssertionTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEvidenceElement_get_AssertionCount(TElSAMLEvidenceElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLEvidenceElement_Create(TElSAMLEvidenceElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHZDECISIONSTATEMENTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_Clear(TElSAMLAuthzDecisionStatementElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_LoadFromXML(TElSAMLAuthzDecisionStatementElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_SaveToXML(TElSAMLAuthzDecisionStatementElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_AddAction(TElSAMLAuthzDecisionStatementElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_RemoveAction(TElSAMLAuthzDecisionStatementElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_get_Resource(TElSAMLAuthzDecisionStatementElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_set_Resource(TElSAMLAuthzDecisionStatementElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_get_Decision(TElSAMLAuthzDecisionStatementElementHandle _Handle, TSBSAMLDecisionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_set_Decision(TElSAMLAuthzDecisionStatementElementHandle _Handle, TSBSAMLDecisionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_get_Evidence(TElSAMLAuthzDecisionStatementElementHandle _Handle, TElSAMLEvidenceElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_set_Evidence(TElSAMLAuthzDecisionStatementElementHandle _Handle, TElSAMLEvidenceElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_get_Actions(TElSAMLAuthzDecisionStatementElementHandle _Handle, int32_t Index, TElSAMLActionElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_get_ActionCount(TElSAMLAuthzDecisionStatementElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionStatementElement_Create(TElSAMLAuthzDecisionStatementElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLAUTHZDECISIONSTATEMENTELEMENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSAMLSubjectElement;
class TElSAMLConditionsElement;
class TElSAMLAdviceElement;
class TElSAMLSubjectConfirmationDataElement;
class TElSAMLStatementAbstractType;
class TElSAMLSubjectConfirmationElement;
class TElSAMLSecurityHandler;
class TElSAMLSignatureHandler;
class TElSAMLEncryptionHandler;
class TElSAMLElement;
class TElSAMLID;
class TElSAMLBaseIDElement;
class TElSAMLNameIDElement;
class TElSAMLEncryptedElement;
class TElSAMLEncryptedIDElement;
class TElSAMLIssuerElement;
class TElSAMLAssertionType;
class TElSAMLAssertionIDRefElement;
class TElSAMLAssertionURIRefElement;
class TElSAMLAssertionElement;
class TElSAMLEncryptedAssertionElement;
class TElSAMLConditionAbstractType;
class TElSAMLAudienceElement;
class TElSAMLAudienceRestrictionElement;
class TElSAMLOneTimeUseElement;
class TElSAMLProxyRestrictionElement;
class TElSAMLSubjectLocalityElement;
typedef TElSAMLElement TElSAMLAuthnContextDecl;
class TElSAMLAuthnContextElement;
class TElSAMLAuthnStatementElement;
class TElSAMLAttributeType;
class TElSAMLAttributeValue;
class TElSAMLAttributeElement;
class TElSAMLEncryptedAttributeElement;
class TElSAMLAttributeStatementElement;
class TElSAMLActionElement;
class TElSAMLEvidenceElement;
class TElSAMLAuthzDecisionStatementElement;

#ifdef SB_USE_CLASS_TELSAMLELEMENT
class TElSAMLElement: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElSAMLElement)
		TObject* _Inst_Tag;
#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
		TElSAMLSecurityHandler* _Inst_Handler;
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */

		void initInstances();

	public:
		virtual void Assign(TElSAMLElement &Other);

		virtual void Assign(TElSAMLElement *Other);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TObject* get_Tag();

		virtual void set_Tag(TObject &Value);

		virtual void set_Tag(TObject *Value);

		SB_DECLARE_PROPERTY(TObject*, get_Tag, set_Tag, TElSAMLElement, Tag);

#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
		virtual TElSAMLSecurityHandler* get_Handler();

		virtual void set_Handler(TElSAMLSecurityHandler &Value);

		virtual void set_Handler(TElSAMLSecurityHandler *Value);

		SB_DECLARE_PROPERTY(TElSAMLSecurityHandler*, get_Handler, set_Handler, TElSAMLElement, Handler);
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */

		virtual void get_TextValue(std::string &OutResult);

		TElSAMLElement(TElSAMLElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLElement();

		virtual ~TElSAMLElement();

};
#endif /* SB_USE_CLASS_TELSAMLELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
class TElSAMLConditionsElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLConditionsElement)
#ifdef SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT
		TElSAMLOneTimeUseElement* _Inst_OneTimeUse;
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT
		TElSAMLProxyRestrictionElement* _Inst_ProxyRestriction;
#endif /* SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
		TElSAMLConditionAbstractType* _Inst_Conditions;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
		int32_t AddCondition(TElSAMLConditionAbstractType &Cond);

		int32_t AddCondition(TElSAMLConditionAbstractType *Cond);
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */

		void RemoveCondition(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT
		virtual TElSAMLOneTimeUseElement* get_OneTimeUse();

		SB_DECLARE_PROPERTY_GET(TElSAMLOneTimeUseElement*, get_OneTimeUse, TElSAMLConditionsElement, OneTimeUse);
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT
		virtual TElSAMLProxyRestrictionElement* get_ProxyRestriction();

		SB_DECLARE_PROPERTY_GET(TElSAMLProxyRestrictionElement*, get_ProxyRestriction, TElSAMLConditionsElement, ProxyRestriction);
#endif /* SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT */

		virtual int64_t get_NotBefore();

		virtual void set_NotBefore(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotBefore, set_NotBefore, TElSAMLConditionsElement, NotBefore);

		virtual int64_t get_NotOnOrAfter();

		virtual void set_NotOnOrAfter(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotOnOrAfter, set_NotOnOrAfter, TElSAMLConditionsElement, NotOnOrAfter);

#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
		virtual TElSAMLConditionAbstractType* get_Conditions(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */

		virtual int32_t get_ConditionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ConditionCount, TElSAMLConditionsElement, ConditionCount);

		TElSAMLConditionsElement(TElSAMLConditionsElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLConditionsElement();

		virtual ~TElSAMLConditionsElement();

};
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLADVICEELEMENT
class TElSAMLAdviceElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLAdviceElement)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_Others;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
		TElSAMLAssertionType* _Inst_Assertions;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
		int32_t AddAssertion(TElSAMLAssertionType &Assertion);

		int32_t AddAssertion(TElSAMLAssertionType *Assertion);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

		void RemoveAssertion(int32_t Index);

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_Others();

		SB_DECLARE_PROPERTY_GET(TList*, get_Others, TElSAMLAdviceElement, Others);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
		virtual TElSAMLAssertionType* get_Assertions(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

		virtual int32_t get_AssertionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AssertionCount, TElSAMLAdviceElement, AssertionCount);

		TElSAMLAdviceElement(TElSAMLAdviceElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAdviceElement();

		virtual ~TElSAMLAdviceElement();

};
#endif /* SB_USE_CLASS_TELSAMLADVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT
class TElSAMLSubjectConfirmationDataElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLSubjectConfirmationDataElement)
		TElXMLCustomElement* _Inst_ArbitraryElements;
#ifdef SB_USE_CLASS_TELXMLDOMATTR
		TElXMLDOMAttr* _Inst_ArbitraryAttributes;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		int32_t AddArbitraryElement(TElXMLCustomElement &Elem);

		int32_t AddArbitraryElement(TElXMLCustomElement *Elem);

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		int32_t AddArbitraryAttribute(TElXMLDOMAttr &Attr);

		int32_t AddArbitraryAttribute(TElXMLDOMAttr *Attr);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

		void RemoveArbitraryElement(int32_t Index);

		void RemoveArbitraryAttribute(int32_t Index);

		virtual void get_AType(std::string &OutResult);

		virtual void set_AType(const std::string &Value);

		virtual int64_t get_NotBefore();

		virtual void set_NotBefore(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotBefore, set_NotBefore, TElSAMLSubjectConfirmationDataElement, NotBefore);

		virtual int64_t get_NotOnOrAfter();

		virtual void set_NotOnOrAfter(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotOnOrAfter, set_NotOnOrAfter, TElSAMLSubjectConfirmationDataElement, NotOnOrAfter);

		virtual void get_Recipient(std::string &OutResult);

		virtual void set_Recipient(const std::string &Value);

		virtual void get_InResponseTo(std::string &OutResult);

		virtual void set_InResponseTo(const std::string &Value);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual TElXMLCustomElement* get_ArbitraryElements(int32_t Index);

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		virtual TElXMLDOMAttr* get_ArbitraryAttributes(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

		virtual int32_t get_ArbitraryElementCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ArbitraryElementCount, TElSAMLSubjectConfirmationDataElement, ArbitraryElementCount);

		virtual int32_t get_ArbitraryAttributeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ArbitraryAttributeCount, TElSAMLSubjectConfirmationDataElement, ArbitraryAttributeCount);

		TElSAMLSubjectConfirmationDataElement(TElSAMLSubjectConfirmationDataElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLSubjectConfirmationDataElement();

		virtual ~TElSAMLSubjectConfirmationDataElement();

};
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
class TElSAMLStatementAbstractType: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLStatementAbstractType)
	public:
		TElSAMLStatementAbstractType(TElSAMLStatementAbstractTypeHandle handle, TElOwnHandle ownHandle);

		TElSAMLStatementAbstractType();

};
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT
class TElSAMLSubjectConfirmationElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLSubjectConfirmationElement)
#ifdef SB_USE_CLASS_TELSAMLID
		TElSAMLID* _Inst_ID;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT
		TElSAMLSubjectConfirmationDataElement* _Inst_SubjectConfirmationData;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID
		virtual TElSAMLID* get_ID();

		virtual void set_ID(TElSAMLID &Value);

		virtual void set_ID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_ID, set_ID, TElSAMLSubjectConfirmationElement, ID);
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT
		virtual TElSAMLSubjectConfirmationDataElement* get_SubjectConfirmationData();

		virtual void set_SubjectConfirmationData(TElSAMLSubjectConfirmationDataElement &Value);

		virtual void set_SubjectConfirmationData(TElSAMLSubjectConfirmationDataElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLSubjectConfirmationDataElement*, get_SubjectConfirmationData, set_SubjectConfirmationData, TElSAMLSubjectConfirmationElement, SubjectConfirmationData);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONDATAELEMENT */

		virtual void get__Method(std::string &OutResult);

		virtual void set__Method(const std::string &Value);

		TElSAMLSubjectConfirmationElement(TElSAMLSubjectConfirmationElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLSubjectConfirmationElement();

		virtual ~TElSAMLSubjectConfirmationElement();

};
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSECURITYHANDLER
class TElSAMLSecurityHandler: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLSecurityHandler)
	public:
#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle Protect(TElXMLDOMDocument &Document, TElXMLDOMElement &Node);

		virtual TElXMLDOMElementHandle Protect(TElXMLDOMDocument *Document, TElXMLDOMElement *Node);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual bool Unprotect(TElXMLDOMDocument &Document, TElXMLDOMElement &Input, TElXMLDOMElement &Output);

		virtual bool Unprotect(TElXMLDOMDocument *Document, TElXMLDOMElement *Input, TElXMLDOMElement &Output);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		TElSAMLSecurityHandler(TElSAMLSecurityHandlerHandle handle, TElOwnHandle ownHandle);

		TElSAMLSecurityHandler();

};
#endif /* SB_USE_CLASS_TELSAMLSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELSAMLSIGNATUREHANDLER
class TElSAMLSignatureHandler: public TElSAMLSecurityHandler
{
	private:
		SB_DISABLE_COPY(TElSAMLSignatureHandler)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle Protect(TElXMLDOMDocument &Document, TElXMLDOMElement &Elem);

		virtual TElXMLDOMElementHandle Protect(TElXMLDOMDocument *Document, TElXMLDOMElement *Elem);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual bool Unprotect(TElXMLDOMDocument &Document, TElXMLDOMElement &Input, TElXMLDOMElement &Output);

		virtual bool Unprotect(TElXMLDOMDocument *Document, TElXMLDOMElement *Input, TElXMLDOMElement &Output);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElSAMLSignatureHandler, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificate();

		virtual void set_Certificate(TElX509Certificate &Value);

		virtual void set_Certificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_Certificate, set_Certificate, TElSAMLSignatureHandler, Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void get_VerificationResult(std::string &OutResult);

		virtual bool get_ValidateCertificate();

		virtual void set_ValidateCertificate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ValidateCertificate, set_ValidateCertificate, TElSAMLSignatureHandler, ValidateCertificate);

		virtual bool get_ValidateReferences();

		virtual void set_ValidateReferences(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ValidateReferences, set_ValidateReferences, TElSAMLSignatureHandler, ValidateReferences);

		virtual TElXMLCanonicalizationMethod get_CanonicalizationMethod();

		virtual void set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value);

		SB_DECLARE_PROPERTY(TElXMLCanonicalizationMethod, get_CanonicalizationMethod, set_CanonicalizationMethod, TElSAMLSignatureHandler, CanonicalizationMethod);

		virtual bool get_SignatureAfterIssuer();

		virtual void set_SignatureAfterIssuer(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignatureAfterIssuer, set_SignatureAfterIssuer, TElSAMLSignatureHandler, SignatureAfterIssuer);

		virtual void get_OnValidatorPrepared(TSBSAMLCertValidatorPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnValidatorPrepared(TSBSAMLCertValidatorPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignerPrepared(TSBSAMLXMLSignerPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignerPrepared(TSBSAMLXMLSignerPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifierPrepared(TSBSAMLXMLVerifierPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifierPrepared(TSBSAMLXMLVerifierPreparedEvent pMethodValue, void * pDataValue);

		TElSAMLSignatureHandler(TElSAMLSignatureHandlerHandle handle, TElOwnHandle ownHandle);

		TElSAMLSignatureHandler();

		virtual ~TElSAMLSignatureHandler();

};
#endif /* SB_USE_CLASS_TELSAMLSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTIONHANDLER
class TElSAMLEncryptionHandler: public TElSAMLSecurityHandler
{
	private:
		SB_DISABLE_COPY(TElSAMLEncryptionHandler)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle Protect(TElXMLDOMDocument &Document, TElXMLDOMElement &Elem);

		virtual TElXMLDOMElementHandle Protect(TElXMLDOMDocument *Document, TElXMLDOMElement *Elem);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual bool Unprotect(TElXMLDOMDocument &Document, TElXMLDOMElement &Input, TElXMLDOMElement &Output);

		virtual bool Unprotect(TElXMLDOMDocument *Document, TElXMLDOMElement *Input, TElXMLDOMElement &Output);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificate();

		virtual void set_Certificate(TElX509Certificate &Value);

		virtual void set_Certificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_Certificate, set_Certificate, TElSAMLEncryptionHandler, Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual int32_t get_DecryptionResult();

		virtual void set_DecryptionResult(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DecryptionResult, set_DecryptionResult, TElSAMLEncryptionHandler, DecryptionResult);

		virtual void get_OnXMLEncryptorPrepared(TSBSAMLXMLEncryptorPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnXMLEncryptorPrepared(TSBSAMLXMLEncryptorPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnXMLDecryptorPrepared(TSBSAMLXMLDecryptorPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnXMLDecryptorPrepared(TSBSAMLXMLDecryptorPreparedEvent pMethodValue, void * pDataValue);

		TElSAMLEncryptionHandler(TElSAMLEncryptionHandlerHandle handle, TElOwnHandle ownHandle);

		TElSAMLEncryptionHandler();

		virtual ~TElSAMLEncryptionHandler();

};
#endif /* SB_USE_CLASS_TELSAMLENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
class TElSAMLSubjectElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLSubjectElement)
#ifdef SB_USE_CLASS_TELSAMLID
		TElSAMLID* _Inst_ID;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT
		TElSAMLSubjectConfirmationElement* _Inst_SubjectConfirmations;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		int32_t AddSubjectConfirmation();

		void RemoveSubjectConfirmation(int32_t Index);

		virtual bool get_Sequence();

		SB_DECLARE_PROPERTY_GET(bool, get_Sequence, TElSAMLSubjectElement, Sequence);

#ifdef SB_USE_CLASS_TELSAMLID
		virtual TElSAMLID* get_ID();

		virtual void set_ID(TElSAMLID &Value);

		virtual void set_ID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_ID, set_ID, TElSAMLSubjectElement, ID);
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT
		virtual TElSAMLSubjectConfirmationElement* get_SubjectConfirmations(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTCONFIRMATIONELEMENT */

		virtual int32_t get_SubjectConfirmationCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SubjectConfirmationCount, TElSAMLSubjectElement, SubjectConfirmationCount);

		TElSAMLSubjectElement(TElSAMLSubjectElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLSubjectElement();

		virtual ~TElSAMLSubjectElement();

};
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLID
class TElSAMLID: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLID)
	public:
		virtual bool CompareTo(TElSAMLID &Other);

		virtual bool CompareTo(TElSAMLID *Other);

		static TElSAMLIDHandle CreateByName(const std::string &Name);

		TElSAMLIDHandle CreateByName_Inst(const std::string &Name);

		TElSAMLID(TElSAMLIDHandle handle, TElOwnHandle ownHandle);

		TElSAMLID();

};
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLBASEIDELEMENT
class TElSAMLBaseIDElement: public TElSAMLID
{
	private:
		SB_DISABLE_COPY(TElSAMLBaseIDElement)
	public:
		virtual void Clear();

		virtual bool CompareTo(TElSAMLID &Other);

		virtual bool CompareTo(TElSAMLID *Other);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_NameQualifier(std::string &OutResult);

		virtual void set_NameQualifier(const std::string &Value);

		virtual void get_SPNameQualifier(std::string &OutResult);

		virtual void set_SPNameQualifier(const std::string &Value);

		TElSAMLBaseIDElement(TElSAMLBaseIDElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLBaseIDElement();

};
#endif /* SB_USE_CLASS_TELSAMLBASEIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDELEMENT
class TElSAMLNameIDElement: public TElSAMLID
{
	private:
		SB_DISABLE_COPY(TElSAMLNameIDElement)
	public:
		virtual void Assign(TElSAMLElement &Other);

		virtual void Assign(TElSAMLElement *Other);

		virtual void Clear();

		virtual bool CompareTo(TElSAMLID &Other);

		virtual bool CompareTo(TElSAMLID *Other);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		virtual void get_NameQualifier(std::string &OutResult);

		virtual void set_NameQualifier(const std::string &Value);

		virtual void get_SPNameQualifier(std::string &OutResult);

		virtual void set_SPNameQualifier(const std::string &Value);

		virtual void get_Format(std::string &OutResult);

		virtual void set_Format(const std::string &Value);

		virtual void get_SPProvidedID(std::string &OutResult);

		virtual void set_SPProvidedID(const std::string &Value);

		TElSAMLNameIDElement(TElSAMLNameIDElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLNameIDElement();

};
#endif /* SB_USE_CLASS_TELSAMLNAMEIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
class TElSAMLEncryptedElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLEncryptedElement)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		void Encrypt();

		void Decrypt();

		virtual void get_ElementName(std::string &OutResult);

		virtual void set_ElementName(const std::string &Value);

		virtual bool get_Decrypted();

		virtual void set_Decrypted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Decrypted, set_Decrypted, TElSAMLEncryptedElement, Decrypted);

		TElSAMLEncryptedElement(TElSAMLEncryptedElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLEncryptedElement();

};
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDIDELEMENT
class TElSAMLEncryptedIDElement: public TElSAMLID
{
	private:
		SB_DISABLE_COPY(TElSAMLEncryptedIDElement)
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
		TElSAMLEncryptedElement* _Inst_EncryptedElement;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
		TElSAMLID* _Inst_ID;

		void initInstances();

	public:
		virtual void Clear();

		virtual bool CompareTo(TElSAMLID &Other);

		virtual bool CompareTo(TElSAMLID *Other);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		void Encrypt();

		void Decrypt();

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
		virtual TElSAMLEncryptedElement* get_EncryptedElement();

		virtual void set_EncryptedElement(TElSAMLEncryptedElement &Value);

		virtual void set_EncryptedElement(TElSAMLEncryptedElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLEncryptedElement*, get_EncryptedElement, set_EncryptedElement, TElSAMLEncryptedIDElement, EncryptedElement);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

		virtual TElSAMLID* get_ID();

		virtual void set_ID(TElSAMLID &Value);

		virtual void set_ID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_ID, set_ID, TElSAMLEncryptedIDElement, ID);

		TElSAMLEncryptedIDElement(TElSAMLEncryptedIDElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLEncryptedIDElement();

		virtual ~TElSAMLEncryptedIDElement();

};
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDIDELEMENT */

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
class TElSAMLIssuerElement: public TElSAMLNameIDElement
{
	private:
		SB_DISABLE_COPY(TElSAMLIssuerElement)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElSAMLIssuerElement(TElSAMLIssuerElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLIssuerElement();

};
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
class TElSAMLAssertionType: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLAssertionType)
	public:
		TElSAMLAssertionType(TElSAMLAssertionTypeHandle handle, TElOwnHandle ownHandle);

		TElSAMLAssertionType();

};
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT
class TElSAMLAssertionIDRefElement: public TElSAMLAssertionType
{
	private:
		SB_DISABLE_COPY(TElSAMLAssertionIDRefElement)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		TElSAMLAssertionIDRefElement(TElSAMLAssertionIDRefElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAssertionIDRefElement();

};
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONURIREFELEMENT
class TElSAMLAssertionURIRefElement: public TElSAMLAssertionType
{
	private:
		SB_DISABLE_COPY(TElSAMLAssertionURIRefElement)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		TElSAMLAssertionURIRefElement(TElSAMLAssertionURIRefElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAssertionURIRefElement();

};
#endif /* SB_USE_CLASS_TELSAMLASSERTIONURIREFELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
class TElSAMLAssertionElement: public TElSAMLAssertionType
{
	private:
		SB_DISABLE_COPY(TElSAMLAssertionElement)
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
		TElSAMLIssuerElement* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
		TElXMLSignature* _Inst_Signature;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
		TElSAMLSubjectElement* _Inst_Subject;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
		TElSAMLConditionsElement* _Inst_Conditions;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLADVICEELEMENT
		TElSAMLAdviceElement* _Inst_Advice;
#endif /* SB_USE_CLASS_TELSAMLADVICEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
		TElSAMLStatementAbstractType* _Inst_Statements;
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element, bool ClearBefore);

		void LoadFromXML(TElXMLDOMElement *Element, bool ClearBefore);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
		int32_t AddStatement(TElSAMLStatementAbstractType &St);

		int32_t AddStatement(TElSAMLStatementAbstractType *St);
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */

		void RemoveStatement(int32_t Index);

		virtual bool get_Signed();

		virtual void set_Signed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Signed, set_Signed, TElSAMLAssertionElement, Signed);

		virtual void get_Version(std::string &OutResult);

		virtual void set_Version(const std::string &Value);

		virtual void get_ID(std::string &OutResult);

		virtual void set_ID(const std::string &Value);

		virtual int64_t get_IssueInstant();

		virtual void set_IssueInstant(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_IssueInstant, set_IssueInstant, TElSAMLAssertionElement, IssueInstant);

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
		virtual TElSAMLIssuerElement* get_Issuer();

		virtual void set_Issuer(TElSAMLIssuerElement &Value);

		virtual void set_Issuer(TElSAMLIssuerElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLIssuerElement*, get_Issuer, set_Issuer, TElSAMLAssertionElement, Issuer);
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
		virtual TElXMLSignature* get_Signature();

		SB_DECLARE_PROPERTY_GET(TElXMLSignature*, get_Signature, TElSAMLAssertionElement, Signature);
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
		virtual TElSAMLSubjectElement* get_Subject();

		virtual void set_Subject(TElSAMLSubjectElement &Value);

		virtual void set_Subject(TElSAMLSubjectElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLSubjectElement*, get_Subject, set_Subject, TElSAMLAssertionElement, Subject);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
		virtual TElSAMLConditionsElement* get_Conditions();

		virtual void set_Conditions(TElSAMLConditionsElement &Value);

		virtual void set_Conditions(TElSAMLConditionsElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLConditionsElement*, get_Conditions, set_Conditions, TElSAMLAssertionElement, Conditions);
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLADVICEELEMENT
		virtual TElSAMLAdviceElement* get_Advice();

		virtual void set_Advice(TElSAMLAdviceElement &Value);

		virtual void set_Advice(TElSAMLAdviceElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLAdviceElement*, get_Advice, set_Advice, TElSAMLAssertionElement, Advice);
#endif /* SB_USE_CLASS_TELSAMLADVICEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE
		virtual TElSAMLStatementAbstractType* get_Statements(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLSTATEMENTABSTRACTTYPE */

		virtual int32_t get_StatementCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_StatementCount, TElSAMLAssertionElement, StatementCount);

		TElSAMLAssertionElement(TElSAMLAssertionElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAssertionElement();

		virtual ~TElSAMLAssertionElement();

};
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDASSERTIONELEMENT
class TElSAMLEncryptedAssertionElement: public TElSAMLAssertionElement
{
	private:
		SB_DISABLE_COPY(TElSAMLEncryptedAssertionElement)
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
		TElSAMLEncryptedElement* _Inst_EncryptedElement;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		void Decrypt();

		virtual bool get_Decrypted();

		SB_DECLARE_PROPERTY_GET(bool, get_Decrypted, TElSAMLEncryptedAssertionElement, Decrypted);

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
		virtual TElSAMLEncryptedElement* get_EncryptedElement();

		SB_DECLARE_PROPERTY_GET(TElSAMLEncryptedElement*, get_EncryptedElement, TElSAMLEncryptedAssertionElement, EncryptedElement);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

		TElSAMLEncryptedAssertionElement(TElSAMLEncryptedAssertionElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLEncryptedAssertionElement();

		virtual ~TElSAMLEncryptedAssertionElement();

};
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE
class TElSAMLConditionAbstractType: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLConditionAbstractType)
	public:
		TElSAMLConditionAbstractType(TElSAMLConditionAbstractTypeHandle handle, TElOwnHandle ownHandle);

		TElSAMLConditionAbstractType();

};
#endif /* SB_USE_CLASS_TELSAMLCONDITIONABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
class TElSAMLAudienceElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLAudienceElement)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		TElSAMLAudienceElement(TElSAMLAudienceElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAudienceElement();

};
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUDIENCERESTRICTIONELEMENT
class TElSAMLAudienceRestrictionElement: public TElSAMLConditionAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAudienceRestrictionElement)
#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
		TElSAMLAudienceElement* _Inst_AudienceList;
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		int32_t AddAudience();

		void RemoveAudience(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
		virtual TElSAMLAudienceElement* get_AudienceList(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

		virtual int32_t get_AudienceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AudienceCount, TElSAMLAudienceRestrictionElement, AudienceCount);

		TElSAMLAudienceRestrictionElement(TElSAMLAudienceRestrictionElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAudienceRestrictionElement();

		virtual ~TElSAMLAudienceRestrictionElement();

};
#endif /* SB_USE_CLASS_TELSAMLAUDIENCERESTRICTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT
class TElSAMLOneTimeUseElement: public TElSAMLConditionAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLOneTimeUseElement)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		TElSAMLOneTimeUseElement(TElSAMLOneTimeUseElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLOneTimeUseElement();

};
#endif /* SB_USE_CLASS_TELSAMLONETIMEUSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT
class TElSAMLProxyRestrictionElement: public TElSAMLConditionAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLProxyRestrictionElement)
#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
		TElSAMLAudienceElement* _Inst_AudienceList;
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		int32_t AddAudience();

		void RemoveAudience(int32_t Index);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElSAMLProxyRestrictionElement, Count);

#ifdef SB_USE_CLASS_TELSAMLAUDIENCEELEMENT
		virtual TElSAMLAudienceElement* get_AudienceList(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLAUDIENCEELEMENT */

		virtual int32_t get_AudienceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AudienceCount, TElSAMLProxyRestrictionElement, AudienceCount);

		TElSAMLProxyRestrictionElement(TElSAMLProxyRestrictionElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLProxyRestrictionElement();

		virtual ~TElSAMLProxyRestrictionElement();

};
#endif /* SB_USE_CLASS_TELSAMLPROXYRESTRICTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT
class TElSAMLSubjectLocalityElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLSubjectLocalityElement)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual void get_DNSName(std::string &OutResult);

		virtual void set_DNSName(const std::string &Value);

		TElSAMLSubjectLocalityElement(TElSAMLSubjectLocalityElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLSubjectLocalityElement();

};
#endif /* SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT
class TElSAMLAuthnContextElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLAuthnContextElement)
		TElSAMLElement* _Inst_AuthnContextDecl;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AuthenticatingAuthorities;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AuthenticatingAuthorities;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TSBSAMLAuthnContextChoice get_Choice();

		virtual void set_Choice(TSBSAMLAuthnContextChoice Value);

		SB_DECLARE_PROPERTY(TSBSAMLAuthnContextChoice, get_Choice, set_Choice, TElSAMLAuthnContextElement, Choice);

		virtual void get_AuthnContextClassRef(std::string &OutResult);

		virtual void set_AuthnContextClassRef(const std::string &Value);

		virtual TElSAMLElement* get_AuthnContextDecl();

		virtual void set_AuthnContextDecl(TElSAMLElement &Value);

		virtual void set_AuthnContextDecl(TElSAMLElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLElement*, get_AuthnContextDecl, set_AuthnContextDecl, TElSAMLAuthnContextElement, AuthnContextDecl);

		virtual void get_AuthnContextDeclRef(std::string &OutResult);

		virtual void set_AuthnContextDeclRef(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AuthenticatingAuthorities();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AuthenticatingAuthorities, TElSAMLAuthnContextElement, AuthenticatingAuthorities);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AuthenticatingAuthorities();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AuthenticatingAuthorities, TElSAMLAuthnContextElement, AuthenticatingAuthorities);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElSAMLAuthnContextElement(TElSAMLAuthnContextElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAuthnContextElement();

		virtual ~TElSAMLAuthnContextElement();

};
#endif /* SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNSTATEMENTELEMENT
class TElSAMLAuthnStatementElement: public TElSAMLStatementAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAuthnStatementElement)
#ifdef SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT
		TElSAMLSubjectLocalityElement* _Inst_SubjectLocality;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT */
#ifdef SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT
		TElSAMLAuthnContextElement* _Inst_AuthnContext;
#endif /* SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int64_t get_AuthnInstant();

		virtual void set_AuthnInstant(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_AuthnInstant, set_AuthnInstant, TElSAMLAuthnStatementElement, AuthnInstant);

		virtual void get_SessionIndex(std::string &OutResult);

		virtual void set_SessionIndex(const std::string &Value);

		virtual int64_t get_SessionNotOnOrAfter();

		virtual void set_SessionNotOnOrAfter(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SessionNotOnOrAfter, set_SessionNotOnOrAfter, TElSAMLAuthnStatementElement, SessionNotOnOrAfter);

#ifdef SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT
		virtual TElSAMLSubjectLocalityElement* get_SubjectLocality();

		virtual void set_SubjectLocality(TElSAMLSubjectLocalityElement &Value);

		virtual void set_SubjectLocality(TElSAMLSubjectLocalityElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLSubjectLocalityElement*, get_SubjectLocality, set_SubjectLocality, TElSAMLAuthnStatementElement, SubjectLocality);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTLOCALITYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT
		virtual TElSAMLAuthnContextElement* get_AuthnContext();

		virtual void set_AuthnContext(TElSAMLAuthnContextElement &Value);

		virtual void set_AuthnContext(TElSAMLAuthnContextElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLAuthnContextElement*, get_AuthnContext, set_AuthnContext, TElSAMLAuthnStatementElement, AuthnContext);
#endif /* SB_USE_CLASS_TELSAMLAUTHNCONTEXTELEMENT */

		TElSAMLAuthnStatementElement(TElSAMLAuthnStatementElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAuthnStatementElement();

		virtual ~TElSAMLAuthnStatementElement();

};
#endif /* SB_USE_CLASS_TELSAMLAUTHNSTATEMENTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
class TElSAMLAttributeType: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLAttributeType)
	public:
		TElSAMLAttributeType(TElSAMLAttributeTypeHandle handle, TElOwnHandle ownHandle);

		TElSAMLAttributeType();

};
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEVALUE
class TElSAMLAttributeValue: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLAttributeValue)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		virtual void get_ContentType(std::string &OutResult);

		virtual void set_ContentType(const std::string &Value);

		TElSAMLAttributeValue(TElSAMLAttributeValueHandle handle, TElOwnHandle ownHandle);

		TElSAMLAttributeValue();

};
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
class TElSAMLAttributeElement: public TElSAMLAttributeType
{
	private:
		SB_DISABLE_COPY(TElSAMLAttributeElement)
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEVALUE
		TElSAMLAttributeValue* _Inst_Values;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEVALUE */
#ifdef SB_USE_CLASS_TELXMLDOMATTR
		TElXMLDOMAttr* _Inst_ArbitraryAttributes;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		int32_t AddArbitraryAttribute(TElXMLDOMAttr &Attr);

		int32_t AddArbitraryAttribute(TElXMLDOMAttr *Attr);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

		void RemoveArbitraryAttribute(int32_t Index);

		int32_t AddValue();

		void RemoveValue(int32_t Index);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_NameFormat(std::string &OutResult);

		virtual void set_NameFormat(const std::string &Value);

		virtual void get_FriendlyName(std::string &OutResult);

		virtual void set_FriendlyName(const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEVALUE
		virtual TElSAMLAttributeValue* get_Values(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEVALUE */

		virtual int32_t get_ValueCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ValueCount, TElSAMLAttributeElement, ValueCount);

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		virtual TElXMLDOMAttr* get_ArbitraryAttributes(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

		virtual int32_t get_ArbitraryAttributeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ArbitraryAttributeCount, TElSAMLAttributeElement, ArbitraryAttributeCount);

		TElSAMLAttributeElement(TElSAMLAttributeElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAttributeElement();

		virtual ~TElSAMLAttributeElement();

};
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDATTRIBUTEELEMENT
class TElSAMLEncryptedAttributeElement: public TElSAMLAttributeType
{
	private:
		SB_DISABLE_COPY(TElSAMLEncryptedAttributeElement)
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
		TElSAMLEncryptedElement* _Inst_EncryptedElement;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
		virtual TElSAMLEncryptedElement* get_EncryptedElement();

		virtual void set_EncryptedElement(TElSAMLEncryptedElement &Value);

		virtual void set_EncryptedElement(TElSAMLEncryptedElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLEncryptedElement*, get_EncryptedElement, set_EncryptedElement, TElSAMLEncryptedAttributeElement, EncryptedElement);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

		TElSAMLEncryptedAttributeElement(TElSAMLEncryptedAttributeElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLEncryptedAttributeElement();

		virtual ~TElSAMLEncryptedAttributeElement();

};
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDATTRIBUTEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTESTATEMENTELEMENT
class TElSAMLAttributeStatementElement: public TElSAMLStatementAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAttributeStatementElement)
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
		TElSAMLAttributeType* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
		int32_t AddAttribute(TElSAMLAttributeType &Attr);

		int32_t AddAttribute(TElSAMLAttributeType *Attr);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */

		void RemoveAttribute(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTETYPE
		virtual TElSAMLAttributeType* get_Attributes(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTETYPE */

		virtual int32_t get_AttributeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AttributeCount, TElSAMLAttributeStatementElement, AttributeCount);

		TElSAMLAttributeStatementElement(TElSAMLAttributeStatementElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAttributeStatementElement();

		virtual ~TElSAMLAttributeStatementElement();

};
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTESTATEMENTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
class TElSAMLActionElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLActionElement)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get__Namespace(std::string &OutResult);

		virtual void set__Namespace(const std::string &Value);

		TElSAMLActionElement(TElSAMLActionElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLActionElement();

};
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
class TElSAMLEvidenceElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLEvidenceElement)
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
		TElSAMLAssertionType* _Inst_Assertions;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
		int32_t AddAssertion(TElSAMLAssertionType &Assertion);

		int32_t AddAssertion(TElSAMLAssertionType *Assertion);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

		void RemoveAssertion(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
		virtual TElSAMLAssertionType* get_Assertions(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

		virtual int32_t get_AssertionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AssertionCount, TElSAMLEvidenceElement, AssertionCount);

		TElSAMLEvidenceElement(TElSAMLEvidenceElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLEvidenceElement();

		virtual ~TElSAMLEvidenceElement();

};
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHZDECISIONSTATEMENTELEMENT
class TElSAMLAuthzDecisionStatementElement: public TElSAMLStatementAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAuthzDecisionStatementElement)
#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
		TElSAMLEvidenceElement* _Inst_Evidence;
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
		TElSAMLActionElement* _Inst_Actions;
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		int32_t AddAction();

		void RemoveAction(int32_t Index);

		virtual void get_Resource(std::string &OutResult);

		virtual void set_Resource(const std::string &Value);

		virtual TSBSAMLDecision get_Decision();

		virtual void set_Decision(TSBSAMLDecision Value);

		SB_DECLARE_PROPERTY(TSBSAMLDecision, get_Decision, set_Decision, TElSAMLAuthzDecisionStatementElement, Decision);

#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
		virtual TElSAMLEvidenceElement* get_Evidence();

		virtual void set_Evidence(TElSAMLEvidenceElement &Value);

		virtual void set_Evidence(TElSAMLEvidenceElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLEvidenceElement*, get_Evidence, set_Evidence, TElSAMLAuthzDecisionStatementElement, Evidence);
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
		virtual TElSAMLActionElement* get_Actions(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */

		virtual int32_t get_ActionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ActionCount, TElSAMLAuthzDecisionStatementElement, ActionCount);

		TElSAMLAuthzDecisionStatementElement(TElSAMLAuthzDecisionStatementElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAuthzDecisionStatementElement();

		virtual ~TElSAMLAuthzDecisionStatementElement();

};
#endif /* SB_USE_CLASS_TELSAMLAUTHZDECISIONSTATEMENTELEMENT */

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLCORE

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
TElXMLNamespaceMapHandle GetSAMLNSMap();
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
void SetSAMLNSMap(TElXMLNamespaceMap &Value);
void SetSAMLNSMap(TElXMLNamespaceMap *Value);
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
TElXMLDOMElementHandle CreateElementNS(TElXMLDOMDocument &Document, const std::string &URI, const std::string &Name);
TElXMLDOMElementHandle CreateElementNS(TElXMLDOMDocument *Document, const std::string &URI, const std::string &Name);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TSTREAM
void StreamToStr(TStream &Input, std::string &OutResult);
void StreamToStr(TStream *Input, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamToStrUTF8(TStream &Input, std::string &OutResult);
void StreamToStrUTF8(TStream *Input, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamToArray(TStream &Input, std::vector<uint8_t> &OutResult);
void StreamToArray(TStream *Input, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement &Element, const sb_u16string &Name, const sb_u16string &NamespaceURI);
TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement *Element, const sb_u16string &Name, const sb_u16string &NamespaceURI);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement &Element, const std::wstring &Name, const std::wstring &NamespaceURI);
TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement *Element, const std::wstring &Name, const std::wstring &NamespaceURI);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
void FreeList(TList &List);
void FreeList(TList *List);
#endif /* SB_USE_CLASS_TLIST */

bool XMLStrToBool(const std::string &S);

void BoolToXMLStr(bool B, std::string &OutResult);

void GenerateID(int32_t Len, std::string &OutResult);

void GenerateID(std::string &OutResult);

void RandomString(int32_t Len, std::string &OutResult);

void RandomString(std::string &OutResult);

void SBXMLSAMLCore_DateTimeToString(int64_t DT, std::string &OutResult);

int64_t CurrentDateTime();

#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLCORE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLCORE
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_GetSAMLNSMap(TElXMLNamespaceMapHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_SetSAMLNSMap(TElXMLNamespaceMapHandle Value);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_CreateElementNS(TElXMLDOMDocumentHandle Document, const char * pcURI, int32_t szURI, const char * pcName, int32_t szName, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_StreamToStr(TStreamHandle Input, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_StreamToStrUTF8(TStreamHandle Input, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_StreamToArray(TStreamHandle Input, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_FindChildElement(const TElXMLDOMElementHandle Element, const sb_char16_t * pcName, int32_t szName, const sb_char16_t * pcNamespaceURI, int32_t szNamespaceURI, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_FreeList(TListHandle List);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_XMLStrToBool(const char * pcS, int32_t szS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_BoolToXMLStr(int8_t B, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_GenerateID(int32_t Len, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_GenerateID_1(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_RandomString(int32_t Len, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_RandomString_1(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_DateTimeToString(int64_t DT, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCore_CurrentDateTime(int64_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLCORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSAMLCORE */
