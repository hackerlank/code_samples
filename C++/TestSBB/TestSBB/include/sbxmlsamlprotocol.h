#ifndef __INC_SBXMLSAMLPROTOCOL
#define __INC_SBXMLSAMLPROTOCOL

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbxmlcore.h"
#include "sbxmlsig.h"
#include "sbxmlenc.h"
#include "sbxmlsec.h"
#include "sbxmlutils.h"
#include "sbxmldefs.h"
#include "sbxmlcharsets.h"
#include "sbxmlsamlcore.h"
#include "sbstreams.h"
#include "sbstrutils.h"
#include "sbutils.h"
#include "sbtypes.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_xmlSAMLStatusSuccess 	"urn:oasis:names:tc:SAML:2.0:status:Success"
#define SB_xmlSAMLStatusRequester 	"urn:oasis:names:tc:SAML:2.0:status:Requester"
#define SB_xmlSAMLStatusResponder 	"urn:oasis:names:tc:SAML:2.0:status:Responder"
#define SB_xmlSAMLStatusVersionMismatch 	"urn:oasis:names:tc:SAML:2.0:status:VersionMismatch"
#define SB_xmlSAMLConsentUnspecified 	"urn:oasis:names:tc:SAML:2.0:consent:unspecified"
#define SB_xmlSAMLConsentObtained 	"urn:oasis:names:tc:SAML:2.0:consent:obtained"
#define SB_xmlSAMLConsentPrior 	"urn:oasis:names:tc:SAML:2.0:consent:prior"
#define SB_xmlSAMLConsentImplicit 	"urn:oasis:names:tc:SAML:2.0:consent:current-implicit"
#define SB_xmlSAMLConsentExplicit 	"urn:oasis:names:tc:SAML:2.0:consent:current-explicit"
#define SB_xmlSAMLConsentUnavailable 	"urn:oasis:names:tc:SAML:2.0:consent:unavailable"
#define SB_xmlSAMLConsentInapplicable 	"urn:oasis:names:tc:SAML:2.0:consent:inapplicable"
#define SB_xmlSAMLStatusAuthnFailed 	"urn:oasis:names:tc:SAML:2.0:status:AuthnFailed"
#define SB_xmlSAMLStatusInvalidAttrNameOrValue 	"urn:oasis:names:tc:SAML:2.0:status:InvalidAttrNameOrValue"
#define SB_xmlSAMLStatusInvalidNameIDPolicy 	"urn:oasis:names:tc:SAML:2.0:status:InvalidNameIDPolicy"
#define SB_xmlSAMLStatusNoAuthnContext 	"urn:oasis:names:tc:SAML:2.0:status:NoAuthnContext"
#define SB_xmlSAMLStatusNoAvailableIDP 	"urn:oasis:names:tc:SAML:2.0:status:NoAvailableIDP"
#define SB_xmlSAMLStatusNoPassive 	"urn:oasis:names:tc:SAML:2.0:status:NoPassive"
#define SB_xmlSAMLStatusNoSupportedIDP 	"urn:oasis:names:tc:SAML:2.0:status:NoSupportedIDP"
#define SB_xmlSAMLStatusPartialLogout 	"urn:oasis:names:tc:SAML:2.0:status:PartialLogout"
#define SB_xmlSAMLStatusProxyCountExceeded 	"urn:oasis:names:tc:SAML:2.0:status:ProxyCountExceeded"
#define SB_xmlSAMLStatusRequestDenied 	"urn:oasis:names:tc:SAML:2.0:status:RequestDenied"
#define SB_xmlSAMLStatusRequestUnsupported 	"urn:oasis:names:tc:SAML:2.0:status:RequestUnsupported"
#define SB_xmlSAMLStatusRequestVersionDeprecated 	"urn:oasis:names:tc:SAML:2.0:status:RequestVersionDeprecated"
#define SB_xmlSAMLStatusRequestVersionTooHigh 	"urn:oasis:names:tc:SAML:2.0:status:RequestVersionTooHigh"
#define SB_xmlSAMLStatusRequestVersionTooLow 	"urn:oasis:names:tc:SAML:2.0:status:RequestVersionTooLow"
#define SB_xmlSAMLStatusResourceNotRecognized 	"urn:oasis:names:tc:SAML:2.0:status:ResourceNotRecognized"
#define SB_xmlSAMLStatusTooManyResponses 	"urn:oasis:names:tc:SAML:2.0:status:TooManyResponses"
#define SB_xmlSAMLStatusUnknownAttrProfile 	"urn:oasis:names:tc:SAML:2.0:status:UnknownAttrProfile"
#define SB_xmlSAMLStatusUnknownPrincipal 	"urn:oasis:names:tc:SAML:2.0:status:UnknownPrincipal"
#define SB_xmlSAMLStatusUnsupportedBinding 	"urn:oasis:names:tc:SAML:2.0:status:UnsupportedBinding"
#define SB_xmlSAMLNameIDPolicyFormatUnspecified 	"urn:oasis:names:tc:SAML:2.0:nameidformat:unspecified"
#define SB_xmlSAMLNameIDPolicyFormatEncrypted 	"urn:oasis:names:tc:SAML:2.0:nameid-format:encrypted"
#define SB_xmlSAMLConfirmationHolderOfKey 	"urn:oasis:names:tc:SAML:2.0:cm:holder-of-key"
#define SB_xmlSAMLConfirmationMethodSenderVouches 	"urn:oasis:names:tc:SAML:2.0:cm:sender-vouches"
#define SB_xmlSAMLConfirmationMethodBearer 	"urn:oasis:names:tc:SAML:2.0:cm:bearer"
#define SB_xmlSAMLLogoutReasonUser 	"urn:oasis:names:tc:SAML:2.0:logout:user"
#define SB_xmlSAMLLogoutReasonAdmin 	"urn:oasis:names:tc:SAML:2.0:logout:admin"
#define SB_xmlSAMLAuthnContextClassInternetProtocol 	"urn:oasis:names:tc:SAML:2.0:ac:classes:InternetProtocol"
#define SB_xmlSAMLAuthnContextClassInternetProtocolPassword 	"urn:oasis:names:tc:SAML:2.0:ac:classes:InternetProtocolPassword"
#define SB_xmlSAMLAuthnContextClassPassword 	"urn:oasis:names:tc:SAML:2.0:ac:classes:Password"
#define SB_xmlSAMLAuthnContextClassPasswordProtectedTransport 	"urn:oasis:names:tc:SAML:2.0:ac:classes:PasswordProtectedTransport"
#define SB_xmlSAMLAuthnContextClassTLSClient 	"urn:oasis:names:tc:SAML:2.0:ac:classes:TLSClient"
#define SB_xmlSAMLAuthnContextClassUnspecified 	"urn:oasis:names:tc:SAML:2.0:ac:classes:unspecified"
#define SB_SExact 	"exact"
#define SB_SMinimum 	"minimum"
#define SB_SMaximum 	"maximum"
#define SB_SBetter 	"better"
#define SB_SUnknownRequestType 	"Unknown request type"
#define SB_SUnknownResponseType 	"Unknown response type"
#define SB_SWrongResponseName 	"Wrong response name"
#define SB_SWrongRequestType 	"Wrong request type"

typedef TElClassHandle TElSAMLExtensionsElementHandle;

typedef TElClassHandle TElSAMLRequestAbstractTypeHandle;

typedef TElClassHandle TElSAMLStatusCodeElementHandle;

typedef TElClassHandle TElSAMLStatusMessageElementHandle;

typedef TElClassHandle TElSAMLStatusDetailElementHandle;

typedef TElClassHandle TElSAMLStatusElementHandle;

typedef TElClassHandle TElSAMLStatusResponseTypeHandle;

typedef TElClassHandle TElSAMLAssertionIDRequestElementHandle;

typedef TElClassHandle TElSAMLSubjectQueryAbstractTypeHandle;

typedef TElClassHandle TElSAMLSubjectQueryElementHandle;

typedef TElClassHandle TElSAMLRequestedAuthnContextElementHandle;

typedef TElClassHandle TElSAMLAuthnQueryElementHandle;

typedef TElClassHandle TElSAMLAttributeQueryElementHandle;

typedef TElClassHandle TElSAMLAuthzDecisionQueryElementHandle;

typedef TElClassHandle TElSAMLResponseElementHandle;

typedef TElClassHandle TElSAMLNameIDPolicyElementHandle;

typedef TElClassHandle TElSAMLIDPEntryElementHandle;

typedef TElClassHandle TElSAMLIDPListElementHandle;

typedef TElClassHandle TElSAMLScopingElementHandle;

typedef TElClassHandle TElSAMLAuthnRequestElementHandle;

typedef TElClassHandle TElSAMLArtifactResolveElementHandle;

typedef TElClassHandle TElSAMLArtifactResponseElementHandle;

typedef TElClassHandle TElSAMLManageNameIDRequestElementHandle;

typedef TElClassHandle TElSAMLManageNameIDResponseElementHandle;

typedef TElClassHandle TElSAMLLogoutRequestElementHandle;

typedef TElClassHandle TElSAMLLogoutResponseElementHandle;

typedef TElClassHandle TElSAMLNameIDMappingRequestElementHandle;

typedef TElClassHandle TElSAMLNameIDMappingResponseElementHandle;

typedef uint8_t TSBSAMLAuthnContextComparisonTypeRaw;

typedef enum
{
	acctNone = 0,
	acctExact = 1,
	acctMinimum = 2,
	acctMaximum = 3,
	acctBetter = 4
} TSBSAMLAuthnContextComparisonType;

typedef uint8_t TSBSAMLAuthnContextRefTypeRaw;

typedef enum
{
	acrtUnknown = 0,
	acrtClass = 1,
	acrtDecl = 2
} TSBSAMLAuthnContextRefType;

typedef uint8_t TSBSAMLConsentRaw;

typedef enum
{
	sctUnspecified = 0,
	sctObtained = 1,
	sctPrior = 2,
	sctImplicit = 3,
	sctExplicit = 4,
	sctUnavailable = 5,
	sctInapplicable = 6
} TSBSAMLConsent;

#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLExtensionsElement_LoadFromXML(TElSAMLExtensionsElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLExtensionsElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_GetInstance(TElXMLDOMDocumentHandle Doc, TElSAMLRequestAbstractTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_GetInstance_1(TElSAMLRequestAbstractTypeHandle _Handle, TElXMLDOMDocumentHandle Doc, TElSAMLRequestAbstractTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_Clear(TElSAMLRequestAbstractTypeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_LoadFromXML(TElSAMLRequestAbstractTypeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_SaveToXML(TElSAMLRequestAbstractTypeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_ElementName(TElSAMLRequestAbstractTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_ElementName(TElSAMLRequestAbstractTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_Signed(TElSAMLRequestAbstractTypeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_Signed(TElSAMLRequestAbstractTypeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_ID(TElSAMLRequestAbstractTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_ID(TElSAMLRequestAbstractTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_Version(TElSAMLRequestAbstractTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_Version(TElSAMLRequestAbstractTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_IssueInstant(TElSAMLRequestAbstractTypeHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_IssueInstant(TElSAMLRequestAbstractTypeHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_Destination(TElSAMLRequestAbstractTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_Destination(TElSAMLRequestAbstractTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_Consent(TElSAMLRequestAbstractTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_Consent(TElSAMLRequestAbstractTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_Issuer(TElSAMLRequestAbstractTypeHandle _Handle, TElSAMLIssuerElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_Issuer(TElSAMLRequestAbstractTypeHandle _Handle, TElSAMLIssuerElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_Signature(TElSAMLRequestAbstractTypeHandle _Handle, TElXMLSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_get_Extensions(TElSAMLRequestAbstractTypeHandle _Handle, TElSAMLExtensionsElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_set_Extensions(TElSAMLRequestAbstractTypeHandle _Handle, TElSAMLExtensionsElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestAbstractType_Create(TElSAMLRequestAbstractTypeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_Assign(TElSAMLStatusCodeElementHandle _Handle, TElSAMLElementHandle Other);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_Clear(TElSAMLStatusCodeElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_LoadFromXML(TElSAMLStatusCodeElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_SaveToXML(TElSAMLStatusCodeElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_get_Value(TElSAMLStatusCodeElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_set_Value(TElSAMLStatusCodeElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_get_SubValue(TElSAMLStatusCodeElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_set_SubValue(TElSAMLStatusCodeElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusCodeElement_Create(TElSAMLStatusCodeElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusMessageElement_Assign(TElSAMLStatusMessageElementHandle _Handle, TElSAMLElementHandle Other);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusMessageElement_Clear(TElSAMLStatusMessageElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusMessageElement_LoadFromXML(TElSAMLStatusMessageElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusMessageElement_SaveToXML(TElSAMLStatusMessageElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusMessageElement_get_StatusMessage(TElSAMLStatusMessageElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusMessageElement_set_StatusMessage(TElSAMLStatusMessageElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusMessageElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_Assign(TElSAMLStatusDetailElementHandle _Handle, TElSAMLElementHandle Other);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_Clear(TElSAMLStatusDetailElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_LoadFromXML(TElSAMLStatusDetailElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_SaveToXML(TElSAMLStatusDetailElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_AddElement(TElSAMLStatusDetailElementHandle _Handle, TElSAMLElementHandle Elem, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_RemoveElement(TElSAMLStatusDetailElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_get_Elements(TElSAMLStatusDetailElementHandle _Handle, int32_t Index, TElSAMLElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_get_ElementCount(TElSAMLStatusDetailElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusDetailElement_Create(TElSAMLStatusDetailElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_Assign(TElSAMLStatusElementHandle _Handle, TElSAMLElementHandle Other);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_Clear(TElSAMLStatusElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_LoadFromXML(TElSAMLStatusElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_SaveToXML(TElSAMLStatusElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_get_StatusCode(TElSAMLStatusElementHandle _Handle, TElSAMLStatusCodeElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_set_StatusCode(TElSAMLStatusElementHandle _Handle, TElSAMLStatusCodeElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_get_StatusMessage(TElSAMLStatusElementHandle _Handle, TElSAMLStatusMessageElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_set_StatusMessage(TElSAMLStatusElementHandle _Handle, TElSAMLStatusMessageElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_get_StatusDetail(TElSAMLStatusElementHandle _Handle, TElSAMLStatusDetailElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_set_StatusDetail(TElSAMLStatusElementHandle _Handle, TElSAMLStatusDetailElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSTATUSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_Clear(TElSAMLStatusResponseTypeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_CreateByName(const char * pcName, int32_t szName, TElSAMLStatusResponseTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_CreateByName_1(TElSAMLStatusResponseTypeHandle _Handle, const char * pcName, int32_t szName, TElSAMLStatusResponseTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_CreateByRequest(TElSAMLRequestAbstractTypeHandle Req, TElSAMLStatusResponseTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_CreateByRequest_1(TElSAMLStatusResponseTypeHandle _Handle, TElSAMLRequestAbstractTypeHandle Req, TElSAMLStatusResponseTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_LoadFromXML(TElSAMLStatusResponseTypeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_SaveToXML(TElSAMLStatusResponseTypeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_ElementName(TElSAMLStatusResponseTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_ElementName(TElSAMLStatusResponseTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_Signed(TElSAMLStatusResponseTypeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_Signed(TElSAMLStatusResponseTypeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_ID(TElSAMLStatusResponseTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_ID(TElSAMLStatusResponseTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_InResponseTo(TElSAMLStatusResponseTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_InResponseTo(TElSAMLStatusResponseTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_Version(TElSAMLStatusResponseTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_Version(TElSAMLStatusResponseTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_IssueInstant(TElSAMLStatusResponseTypeHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_IssueInstant(TElSAMLStatusResponseTypeHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_Destination(TElSAMLStatusResponseTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_Destination(TElSAMLStatusResponseTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_Consent(TElSAMLStatusResponseTypeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_Consent(TElSAMLStatusResponseTypeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_Issuer(TElSAMLStatusResponseTypeHandle _Handle, TElSAMLIssuerElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_Issuer(TElSAMLStatusResponseTypeHandle _Handle, TElSAMLIssuerElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_Signature(TElSAMLStatusResponseTypeHandle _Handle, TElXMLSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_Extensions(TElSAMLStatusResponseTypeHandle _Handle, TElSAMLExtensionsElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_Extensions(TElSAMLStatusResponseTypeHandle _Handle, TElSAMLExtensionsElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_get_Status(TElSAMLStatusResponseTypeHandle _Handle, TElSAMLStatusElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_set_Status(TElSAMLStatusResponseTypeHandle _Handle, TElSAMLStatusElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLStatusResponseType_Create(TElSAMLStatusResponseTypeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREQUESTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRequestElement_Clear(TElSAMLAssertionIDRequestElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRequestElement_LoadFromXML(TElSAMLAssertionIDRequestElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRequestElement_SaveToXML(TElSAMLAssertionIDRequestElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRequestElement_AddReference(TElSAMLAssertionIDRequestElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRequestElement_RemoveReference(TElSAMLAssertionIDRequestElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRequestElement_get_References(TElSAMLAssertionIDRequestElementHandle _Handle, int32_t Index, TElSAMLAssertionIDRefElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRequestElement_get_ReferenceCount(TElSAMLAssertionIDRequestElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAssertionIDRequestElement_Create(TElSAMLAssertionIDRequestElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTQUERYABSTRACTTYPE
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectQueryAbstractType_Clear(TElSAMLSubjectQueryAbstractTypeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectQueryAbstractType_LoadFromXML(TElSAMLSubjectQueryAbstractTypeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectQueryAbstractType_SaveToXML(TElSAMLSubjectQueryAbstractTypeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectQueryAbstractType_get_Subject(TElSAMLSubjectQueryAbstractTypeHandle _Handle, TElSAMLSubjectElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectQueryAbstractType_set_Subject(TElSAMLSubjectQueryAbstractTypeHandle _Handle, TElSAMLSubjectElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectQueryAbstractType_Create(TElSAMLSubjectQueryAbstractTypeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTQUERYABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTQUERYELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSubjectQueryElement_Create(TElSAMLSubjectQueryElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_Clear(TElSAMLRequestedAuthnContextElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_LoadFromXML(TElSAMLRequestedAuthnContextElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_SaveToXML(TElSAMLRequestedAuthnContextElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_get_RefType(TElSAMLRequestedAuthnContextElementHandle _Handle, TSBSAMLAuthnContextRefTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_set_RefType(TElSAMLRequestedAuthnContextElementHandle _Handle, TSBSAMLAuthnContextRefTypeRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_get_List(TElSAMLRequestedAuthnContextElementHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_get_List(TElSAMLRequestedAuthnContextElementHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_get_Comparison(TElSAMLRequestedAuthnContextElementHandle _Handle, TSBSAMLAuthnContextComparisonTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_set_Comparison(TElSAMLRequestedAuthnContextElementHandle _Handle, TSBSAMLAuthnContextComparisonTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRequestedAuthnContextElement_Create(TElSAMLRequestedAuthnContextElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNQUERYELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnQueryElement_Clear(TElSAMLAuthnQueryElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnQueryElement_LoadFromXML(TElSAMLAuthnQueryElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnQueryElement_SaveToXML(TElSAMLAuthnQueryElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnQueryElement_get_RequestedAuthnContext(TElSAMLAuthnQueryElementHandle _Handle, TElSAMLRequestedAuthnContextElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnQueryElement_set_RequestedAuthnContext(TElSAMLAuthnQueryElementHandle _Handle, TElSAMLRequestedAuthnContextElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnQueryElement_get_SessionIndex(TElSAMLAuthnQueryElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnQueryElement_set_SessionIndex(TElSAMLAuthnQueryElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnQueryElement_Create(TElSAMLAuthnQueryElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLAUTHNQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEQUERYELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeQueryElement_Clear(TElSAMLAttributeQueryElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeQueryElement_LoadFromXML(TElSAMLAttributeQueryElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeQueryElement_SaveToXML(TElSAMLAttributeQueryElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeQueryElement_AddAttribute(TElSAMLAttributeQueryElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeQueryElement_RemoveAttribute(TElSAMLAttributeQueryElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeQueryElement_get_Attributes(TElSAMLAttributeQueryElementHandle _Handle, int32_t Index, TElSAMLAttributeElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeQueryElement_get_AttributeCount(TElSAMLAttributeQueryElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAttributeQueryElement_Create(TElSAMLAttributeQueryElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHZDECISIONQUERYELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_Clear(TElSAMLAuthzDecisionQueryElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_LoadFromXML(TElSAMLAuthzDecisionQueryElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_SaveToXML(TElSAMLAuthzDecisionQueryElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_AddAction(TElSAMLAuthzDecisionQueryElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_RemoveAction(TElSAMLAuthzDecisionQueryElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_get_Resource(TElSAMLAuthzDecisionQueryElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_set_Resource(TElSAMLAuthzDecisionQueryElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_get_Evidence(TElSAMLAuthzDecisionQueryElementHandle _Handle, TElSAMLEvidenceElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_set_Evidence(TElSAMLAuthzDecisionQueryElementHandle _Handle, TElSAMLEvidenceElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_get_Actions(TElSAMLAuthzDecisionQueryElementHandle _Handle, int32_t Index, TElSAMLActionElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_get_ActionCount(TElSAMLAuthzDecisionQueryElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthzDecisionQueryElement_Create(TElSAMLAuthzDecisionQueryElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLAUTHZDECISIONQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLRESPONSEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_GetInstance(TElXMLDOMDocumentHandle Doc, TElSAMLStatusResponseTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_GetInstance_1(TElSAMLResponseElementHandle _Handle, TElXMLDOMDocumentHandle Doc, TElSAMLStatusResponseTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_Clear(TElSAMLResponseElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_LoadFromXML(TElSAMLResponseElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_SaveToXML(TElSAMLResponseElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_AddAssertion(TElSAMLResponseElementHandle _Handle, TElSAMLAssertionTypeHandle Assertion, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_RemoveAssertion(TElSAMLResponseElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_get_Assertions(TElSAMLResponseElementHandle _Handle, int32_t Index, TElSAMLAssertionTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_get_AssertionCount(TElSAMLResponseElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLResponseElement_Create(TElSAMLResponseElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_Clear(TElSAMLNameIDPolicyElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_LoadFromXML(TElSAMLNameIDPolicyElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_SaveToXML(TElSAMLNameIDPolicyElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_get_Format(TElSAMLNameIDPolicyElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_set_Format(TElSAMLNameIDPolicyElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_get_SPNameQualifier(TElSAMLNameIDPolicyElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_set_SPNameQualifier(TElSAMLNameIDPolicyElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_get_AllowCreate(TElSAMLNameIDPolicyElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_set_AllowCreate(TElSAMLNameIDPolicyElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_get_UseAllowCreate(TElSAMLNameIDPolicyElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_set_UseAllowCreate(TElSAMLNameIDPolicyElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDPolicyElement_Create(TElSAMLNameIDPolicyElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLIDPENTRYELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_Clear(TElSAMLIDPEntryElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_LoadFromXML(TElSAMLIDPEntryElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_SaveToXML(TElSAMLIDPEntryElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_get_ProviderID(TElSAMLIDPEntryElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_set_ProviderID(TElSAMLIDPEntryElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_get_Name(TElSAMLIDPEntryElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_set_Name(TElSAMLIDPEntryElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_get_Loc(TElSAMLIDPEntryElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_set_Loc(TElSAMLIDPEntryElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPEntryElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLIDPENTRYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLIDPLISTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_Clear(TElSAMLIDPListElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_LoadFromXML(TElSAMLIDPListElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_SaveToXML(TElSAMLIDPListElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_AddIDPEntry(TElSAMLIDPListElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_RemoveIDPEntry(TElSAMLIDPListElementHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_get_GetComplete(TElSAMLIDPListElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_set_GetComplete(TElSAMLIDPListElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_get_IDPEntries(TElSAMLIDPListElementHandle _Handle, int32_t Index, TElSAMLIDPEntryElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_get_IDPEntryCount(TElSAMLIDPListElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLIDPListElement_Create(TElSAMLIDPListElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLIDPLISTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSCOPINGELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_Clear(TElSAMLScopingElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_LoadFromXML(TElSAMLScopingElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_SaveToXML(TElSAMLScopingElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_get_ProxyCount(TElSAMLScopingElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_set_ProxyCount(TElSAMLScopingElementHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_get_IDPList(TElSAMLScopingElementHandle _Handle, TElSAMLIDPListElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_set_IDPList(TElSAMLScopingElementHandle _Handle, TElSAMLIDPListElementHandle Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_get_RequesterIDs(TElSAMLScopingElementHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_get_RequesterIDs(TElSAMLScopingElementHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLScopingElement_Create(TElSAMLScopingElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSCOPINGELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNREQUESTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_Clear(TElSAMLAuthnRequestElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_LoadFromXML(TElSAMLAuthnRequestElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_SaveToXML(TElSAMLAuthnRequestElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_ForceAuthn(TElSAMLAuthnRequestElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_ForceAuthn(TElSAMLAuthnRequestElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_IsPassive(TElSAMLAuthnRequestElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_IsPassive(TElSAMLAuthnRequestElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_UseForceAuthn(TElSAMLAuthnRequestElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_UseForceAuthn(TElSAMLAuthnRequestElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_UseIsPassive(TElSAMLAuthnRequestElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_UseIsPassive(TElSAMLAuthnRequestElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_ProtocolBinding(TElSAMLAuthnRequestElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_ProtocolBinding(TElSAMLAuthnRequestElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_AssertionConsumerServiceIndex(TElSAMLAuthnRequestElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_AssertionConsumerServiceIndex(TElSAMLAuthnRequestElementHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_AssertionConsumerServiceURL(TElSAMLAuthnRequestElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_AssertionConsumerServiceURL(TElSAMLAuthnRequestElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_AttributeConsumingServiceIndex(TElSAMLAuthnRequestElementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_AttributeConsumingServiceIndex(TElSAMLAuthnRequestElementHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_ProviderName(TElSAMLAuthnRequestElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_ProviderName(TElSAMLAuthnRequestElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_Subject(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLSubjectElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_Subject(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLSubjectElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_NameIDPolicy(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLNameIDPolicyElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_NameIDPolicy(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLNameIDPolicyElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_Conditions(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLConditionsElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_Conditions(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLConditionsElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_RequestedAuthnContext(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLRequestedAuthnContextElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_RequestedAuthnContext(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLRequestedAuthnContextElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_get_Scoping(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLScopingElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_set_Scoping(TElSAMLAuthnRequestElementHandle _Handle, TElSAMLScopingElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAuthnRequestElement_Create(TElSAMLAuthnRequestElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLAUTHNREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLARTIFACTRESOLVEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResolveElement_Clear(TElSAMLArtifactResolveElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResolveElement_LoadFromXML(TElSAMLArtifactResolveElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResolveElement_SaveToXML(TElSAMLArtifactResolveElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResolveElement_get_Artifact(TElSAMLArtifactResolveElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResolveElement_set_Artifact(TElSAMLArtifactResolveElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResolveElement_Create(TElSAMLArtifactResolveElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLARTIFACTRESOLVEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLARTIFACTRESPONSEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResponseElement_Clear(TElSAMLArtifactResponseElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResponseElement_LoadFromXML(TElSAMLArtifactResponseElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResponseElement_SaveToXML(TElSAMLArtifactResponseElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResponseElement_get_Optional(TElSAMLArtifactResponseElementHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResponseElement_set_Optional(TElSAMLArtifactResponseElementHandle _Handle, TElXMLDOMElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifactResponseElement_Create(TElSAMLArtifactResponseElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLARTIFACTRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLMANAGENAMEIDREQUESTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_Clear(TElSAMLManageNameIDRequestElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_LoadFromXML(TElSAMLManageNameIDRequestElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_SaveToXML(TElSAMLManageNameIDRequestElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_get_NameID(TElSAMLManageNameIDRequestElementHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_set_NameID(TElSAMLManageNameIDRequestElementHandle _Handle, TElSAMLIDHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_get_NewID(TElSAMLManageNameIDRequestElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_set_NewID(TElSAMLManageNameIDRequestElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_get_NewEncryptedID(TElSAMLManageNameIDRequestElementHandle _Handle, TElSAMLEncryptedElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_set_NewEncryptedID(TElSAMLManageNameIDRequestElementHandle _Handle, TElSAMLEncryptedElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_get_Terminate(TElSAMLManageNameIDRequestElementHandle _Handle, TElSAMLElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_set_Terminate(TElSAMLManageNameIDRequestElementHandle _Handle, TElSAMLElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDRequestElement_Create(TElSAMLManageNameIDRequestElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLMANAGENAMEIDREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLMANAGENAMEIDRESPONSEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLManageNameIDResponseElement_Create(TElSAMLManageNameIDResponseElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLMANAGENAMEIDRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLLOGOUTREQUESTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_Clear(TElSAMLLogoutRequestElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_LoadFromXML(TElSAMLLogoutRequestElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_SaveToXML(TElSAMLLogoutRequestElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_get_NameID(TElSAMLLogoutRequestElementHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_set_NameID(TElSAMLLogoutRequestElementHandle _Handle, TElSAMLIDHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_get_Reason(TElSAMLLogoutRequestElementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_set_Reason(TElSAMLLogoutRequestElementHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_get_NotOnOrAfter(TElSAMLLogoutRequestElementHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_set_NotOnOrAfter(TElSAMLLogoutRequestElementHandle _Handle, int64_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_get_SessionIndexes(TElSAMLLogoutRequestElementHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_get_SessionIndexes(TElSAMLLogoutRequestElementHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutRequestElement_Create(TElSAMLLogoutRequestElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLLOGOUTREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLLOGOUTRESPONSEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLLogoutResponseElement_Create(TElSAMLLogoutResponseElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLLOGOUTRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDMAPPINGREQUESTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingRequestElement_Clear(TElSAMLNameIDMappingRequestElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingRequestElement_LoadFromXML(TElSAMLNameIDMappingRequestElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingRequestElement_SaveToXML(TElSAMLNameIDMappingRequestElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingRequestElement_get_NameID(TElSAMLNameIDMappingRequestElementHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingRequestElement_set_NameID(TElSAMLNameIDMappingRequestElementHandle _Handle, TElSAMLIDHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingRequestElement_get_NameIDPolicy(TElSAMLNameIDMappingRequestElementHandle _Handle, TElSAMLNameIDPolicyElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingRequestElement_set_NameIDPolicy(TElSAMLNameIDMappingRequestElementHandle _Handle, TElSAMLNameIDPolicyElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingRequestElement_Create(TElSAMLNameIDMappingRequestElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLNAMEIDMAPPINGREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDMAPPINGRESPONSEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingResponseElement_Clear(TElSAMLNameIDMappingResponseElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingResponseElement_LoadFromXML(TElSAMLNameIDMappingResponseElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingResponseElement_SaveToXML(TElSAMLNameIDMappingResponseElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingResponseElement_get_NameID(TElSAMLNameIDMappingResponseElementHandle _Handle, TElSAMLIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingResponseElement_set_NameID(TElSAMLNameIDMappingResponseElementHandle _Handle, TElSAMLIDHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLNameIDMappingResponseElement_Create(TElSAMLNameIDMappingResponseElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLNAMEIDMAPPINGRESPONSEELEMENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSAMLExtensionsElement;
class TElSAMLRequestAbstractType;
class TElSAMLStatusCodeElement;
class TElSAMLStatusMessageElement;
class TElSAMLStatusDetailElement;
class TElSAMLStatusElement;
class TElSAMLStatusResponseType;
class TElSAMLAssertionIDRequestElement;
class TElSAMLSubjectQueryAbstractType;
class TElSAMLSubjectQueryElement;
class TElSAMLRequestedAuthnContextElement;
class TElSAMLAuthnQueryElement;
class TElSAMLAttributeQueryElement;
class TElSAMLAuthzDecisionQueryElement;
class TElSAMLResponseElement;
class TElSAMLNameIDPolicyElement;
class TElSAMLIDPEntryElement;
class TElSAMLIDPListElement;
class TElSAMLScopingElement;
class TElSAMLAuthnRequestElement;
class TElSAMLArtifactResolveElement;
class TElSAMLArtifactResponseElement;
class TElSAMLManageNameIDRequestElement;
class TElSAMLManageNameIDResponseElement;
class TElSAMLLogoutRequestElement;
class TElSAMLLogoutResponseElement;
class TElSAMLNameIDMappingRequestElement;
class TElSAMLNameIDMappingResponseElement;

#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
class TElSAMLExtensionsElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLExtensionsElement)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElSAMLExtensionsElement(TElSAMLExtensionsElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLExtensionsElement();

};
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
class TElSAMLRequestAbstractType: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLRequestAbstractType)
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
		TElSAMLIssuerElement* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
		TElXMLSignature* _Inst_Signature;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
		TElSAMLExtensionsElement* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		static TElSAMLRequestAbstractTypeHandle GetInstance(TElXMLDOMDocument &Doc);

		static TElSAMLRequestAbstractTypeHandle GetInstance(TElXMLDOMDocument *Doc);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElSAMLRequestAbstractTypeHandle GetInstance_Inst(TElXMLDOMDocument &Doc);

		TElSAMLRequestAbstractTypeHandle GetInstance_Inst(TElXMLDOMDocument *Doc);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ElementName(std::string &OutResult);

		virtual void set_ElementName(const std::string &Value);

		virtual bool get_Signed();

		virtual void set_Signed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Signed, set_Signed, TElSAMLRequestAbstractType, Signed);

		virtual void get_ID(std::string &OutResult);

		virtual void set_ID(const std::string &Value);

		virtual void get_Version(std::string &OutResult);

		virtual void set_Version(const std::string &Value);

		virtual int64_t get_IssueInstant();

		virtual void set_IssueInstant(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_IssueInstant, set_IssueInstant, TElSAMLRequestAbstractType, IssueInstant);

		virtual void get_Destination(std::string &OutResult);

		virtual void set_Destination(const std::string &Value);

		virtual void get_Consent(std::string &OutResult);

		virtual void set_Consent(const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
		virtual TElSAMLIssuerElement* get_Issuer();

		virtual void set_Issuer(TElSAMLIssuerElement &Value);

		virtual void set_Issuer(TElSAMLIssuerElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLIssuerElement*, get_Issuer, set_Issuer, TElSAMLRequestAbstractType, Issuer);
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
		virtual TElXMLSignature* get_Signature();

		SB_DECLARE_PROPERTY_GET(TElXMLSignature*, get_Signature, TElSAMLRequestAbstractType, Signature);
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
		virtual TElSAMLExtensionsElement* get_Extensions();

		virtual void set_Extensions(TElSAMLExtensionsElement &Value);

		virtual void set_Extensions(TElSAMLExtensionsElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLExtensionsElement*, get_Extensions, set_Extensions, TElSAMLRequestAbstractType, Extensions);
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */

		TElSAMLRequestAbstractType(TElSAMLRequestAbstractTypeHandle handle, TElOwnHandle ownHandle);

		TElSAMLRequestAbstractType();

		virtual ~TElSAMLRequestAbstractType();

};
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT
class TElSAMLStatusCodeElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLStatusCodeElement)
	public:
		virtual void Assign(TElSAMLElement &Other);

		virtual void Assign(TElSAMLElement *Other);

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

		virtual void get_SubValue(std::string &OutResult);

		virtual void set_SubValue(const std::string &Value);

		TElSAMLStatusCodeElement(TElSAMLStatusCodeElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLStatusCodeElement();

};
#endif /* SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT
class TElSAMLStatusMessageElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLStatusMessageElement)
	public:
		virtual void Assign(TElSAMLElement &Other);

		virtual void Assign(TElSAMLElement *Other);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_StatusMessage(std::string &OutResult);

		virtual void set_StatusMessage(const std::string &Value);

		TElSAMLStatusMessageElement(TElSAMLStatusMessageElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLStatusMessageElement();

};
#endif /* SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT
class TElSAMLStatusDetailElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLStatusDetailElement)
		TElSAMLElement* _Inst_Elements;

		void initInstances();

	public:
		virtual void Assign(TElSAMLElement &Other);

		virtual void Assign(TElSAMLElement *Other);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		int32_t AddElement(TElSAMLElement &Elem);

		int32_t AddElement(TElSAMLElement *Elem);

		void RemoveElement(int32_t Index);

		virtual TElSAMLElement* get_Elements(int32_t Index);

		virtual int32_t get_ElementCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ElementCount, TElSAMLStatusDetailElement, ElementCount);

		TElSAMLStatusDetailElement(TElSAMLStatusDetailElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLStatusDetailElement();

		virtual ~TElSAMLStatusDetailElement();

};
#endif /* SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSELEMENT
class TElSAMLStatusElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLStatusElement)
#ifdef SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT
		TElSAMLStatusCodeElement* _Inst_StatusCode;
#endif /* SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT
		TElSAMLStatusMessageElement* _Inst_StatusMessage;
#endif /* SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT
		TElSAMLStatusDetailElement* _Inst_StatusDetail;
#endif /* SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT */

		void initInstances();

	public:
		virtual void Assign(TElSAMLElement &Other);

		virtual void Assign(TElSAMLElement *Other);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT
		virtual TElSAMLStatusCodeElement* get_StatusCode();

		virtual void set_StatusCode(TElSAMLStatusCodeElement &Value);

		virtual void set_StatusCode(TElSAMLStatusCodeElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLStatusCodeElement*, get_StatusCode, set_StatusCode, TElSAMLStatusElement, StatusCode);
#endif /* SB_USE_CLASS_TELSAMLSTATUSCODEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT
		virtual TElSAMLStatusMessageElement* get_StatusMessage();

		virtual void set_StatusMessage(TElSAMLStatusMessageElement &Value);

		virtual void set_StatusMessage(TElSAMLStatusMessageElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLStatusMessageElement*, get_StatusMessage, set_StatusMessage, TElSAMLStatusElement, StatusMessage);
#endif /* SB_USE_CLASS_TELSAMLSTATUSMESSAGEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT
		virtual TElSAMLStatusDetailElement* get_StatusDetail();

		virtual void set_StatusDetail(TElSAMLStatusDetailElement &Value);

		virtual void set_StatusDetail(TElSAMLStatusDetailElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLStatusDetailElement*, get_StatusDetail, set_StatusDetail, TElSAMLStatusElement, StatusDetail);
#endif /* SB_USE_CLASS_TELSAMLSTATUSDETAILELEMENT */

		TElSAMLStatusElement(TElSAMLStatusElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLStatusElement();

		virtual ~TElSAMLStatusElement();

};
#endif /* SB_USE_CLASS_TELSAMLSTATUSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE
class TElSAMLStatusResponseType: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLStatusResponseType)
#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
		TElSAMLIssuerElement* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */
#ifdef SB_USE_CLASS_TELXMLSIGNATURE
		TElXMLSignature* _Inst_Signature;
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */
#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
		TElSAMLExtensionsElement* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSELEMENT
		TElSAMLStatusElement* _Inst_Status;
#endif /* SB_USE_CLASS_TELSAMLSTATUSELEMENT */

		void initInstances();

	public:
		virtual void Clear();

		static TElSAMLStatusResponseTypeHandle CreateByName(const std::string &Name);

		TElSAMLStatusResponseTypeHandle CreateByName_Inst(const std::string &Name);

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
		static TElSAMLStatusResponseTypeHandle CreateByRequest(TElSAMLRequestAbstractType &Req);

		static TElSAMLStatusResponseTypeHandle CreateByRequest(TElSAMLRequestAbstractType *Req);
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
		TElSAMLStatusResponseTypeHandle CreateByRequest_Inst(TElSAMLRequestAbstractType &Req);

		TElSAMLStatusResponseTypeHandle CreateByRequest_Inst(TElSAMLRequestAbstractType *Req);
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ElementName(std::string &OutResult);

		virtual void set_ElementName(const std::string &Value);

		virtual bool get_Signed();

		virtual void set_Signed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Signed, set_Signed, TElSAMLStatusResponseType, Signed);

		virtual void get_ID(std::string &OutResult);

		virtual void set_ID(const std::string &Value);

		virtual void get_InResponseTo(std::string &OutResult);

		virtual void set_InResponseTo(const std::string &Value);

		virtual void get_Version(std::string &OutResult);

		virtual void set_Version(const std::string &Value);

		virtual int64_t get_IssueInstant();

		virtual void set_IssueInstant(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_IssueInstant, set_IssueInstant, TElSAMLStatusResponseType, IssueInstant);

		virtual void get_Destination(std::string &OutResult);

		virtual void set_Destination(const std::string &Value);

		virtual void get_Consent(std::string &OutResult);

		virtual void set_Consent(const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLISSUERELEMENT
		virtual TElSAMLIssuerElement* get_Issuer();

		virtual void set_Issuer(TElSAMLIssuerElement &Value);

		virtual void set_Issuer(TElSAMLIssuerElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLIssuerElement*, get_Issuer, set_Issuer, TElSAMLStatusResponseType, Issuer);
#endif /* SB_USE_CLASS_TELSAMLISSUERELEMENT */

#ifdef SB_USE_CLASS_TELXMLSIGNATURE
		virtual TElXMLSignature* get_Signature();

		SB_DECLARE_PROPERTY_GET(TElXMLSignature*, get_Signature, TElSAMLStatusResponseType, Signature);
#endif /* SB_USE_CLASS_TELXMLSIGNATURE */

#ifdef SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT
		virtual TElSAMLExtensionsElement* get_Extensions();

		virtual void set_Extensions(TElSAMLExtensionsElement &Value);

		virtual void set_Extensions(TElSAMLExtensionsElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLExtensionsElement*, get_Extensions, set_Extensions, TElSAMLStatusResponseType, Extensions);
#endif /* SB_USE_CLASS_TELSAMLEXTENSIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSELEMENT
		virtual TElSAMLStatusElement* get_Status();

		virtual void set_Status(TElSAMLStatusElement &Value);

		virtual void set_Status(TElSAMLStatusElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLStatusElement*, get_Status, set_Status, TElSAMLStatusResponseType, Status);
#endif /* SB_USE_CLASS_TELSAMLSTATUSELEMENT */

		TElSAMLStatusResponseType(TElSAMLStatusResponseTypeHandle handle, TElOwnHandle ownHandle);

		TElSAMLStatusResponseType();

		virtual ~TElSAMLStatusResponseType();

};
#endif /* SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREQUESTELEMENT
class TElSAMLAssertionIDRequestElement: public TElSAMLRequestAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAssertionIDRequestElement)
#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT
		TElSAMLAssertionIDRefElement* _Inst_References;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT */

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

		int32_t AddReference();

		void RemoveReference(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT
		virtual TElSAMLAssertionIDRefElement* get_References(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREFELEMENT */

		virtual int32_t get_ReferenceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ReferenceCount, TElSAMLAssertionIDRequestElement, ReferenceCount);

		TElSAMLAssertionIDRequestElement(TElSAMLAssertionIDRequestElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAssertionIDRequestElement();

		virtual ~TElSAMLAssertionIDRequestElement();

};
#endif /* SB_USE_CLASS_TELSAMLASSERTIONIDREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTQUERYABSTRACTTYPE
class TElSAMLSubjectQueryAbstractType: public TElSAMLRequestAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLSubjectQueryAbstractType)
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
		TElSAMLSubjectElement* _Inst_Subject;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

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

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
		virtual TElSAMLSubjectElement* get_Subject();

		virtual void set_Subject(TElSAMLSubjectElement &Value);

		virtual void set_Subject(TElSAMLSubjectElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLSubjectElement*, get_Subject, set_Subject, TElSAMLSubjectQueryAbstractType, Subject);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

		TElSAMLSubjectQueryAbstractType(TElSAMLSubjectQueryAbstractTypeHandle handle, TElOwnHandle ownHandle);

		TElSAMLSubjectQueryAbstractType();

		virtual ~TElSAMLSubjectQueryAbstractType();

};
#endif /* SB_USE_CLASS_TELSAMLSUBJECTQUERYABSTRACTTYPE */

#ifdef SB_USE_CLASS_TELSAMLSUBJECTQUERYELEMENT
class TElSAMLSubjectQueryElement: public TElSAMLSubjectQueryAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLSubjectQueryElement)
	public:
		TElSAMLSubjectQueryElement(TElSAMLSubjectQueryElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLSubjectQueryElement();

};
#endif /* SB_USE_CLASS_TELSAMLSUBJECTQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
class TElSAMLRequestedAuthnContextElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLRequestedAuthnContextElement)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_List;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_List;
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

		virtual TSBSAMLAuthnContextRefType get_RefType();

		virtual void set_RefType(TSBSAMLAuthnContextRefType Value);

		SB_DECLARE_PROPERTY(TSBSAMLAuthnContextRefType, get_RefType, set_RefType, TElSAMLRequestedAuthnContextElement, RefType);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_List();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_List, TElSAMLRequestedAuthnContextElement, List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_List();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_List, TElSAMLRequestedAuthnContextElement, List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TSBSAMLAuthnContextComparisonType get_Comparison();

		virtual void set_Comparison(TSBSAMLAuthnContextComparisonType Value);

		SB_DECLARE_PROPERTY(TSBSAMLAuthnContextComparisonType, get_Comparison, set_Comparison, TElSAMLRequestedAuthnContextElement, Comparison);

		TElSAMLRequestedAuthnContextElement(TElSAMLRequestedAuthnContextElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLRequestedAuthnContextElement();

		virtual ~TElSAMLRequestedAuthnContextElement();

};
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNQUERYELEMENT
class TElSAMLAuthnQueryElement: public TElSAMLSubjectQueryAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAuthnQueryElement)
#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
		TElSAMLRequestedAuthnContextElement* _Inst_RequestedAuthnContext;
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */

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

#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
		virtual TElSAMLRequestedAuthnContextElement* get_RequestedAuthnContext();

		virtual void set_RequestedAuthnContext(TElSAMLRequestedAuthnContextElement &Value);

		virtual void set_RequestedAuthnContext(TElSAMLRequestedAuthnContextElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLRequestedAuthnContextElement*, get_RequestedAuthnContext, set_RequestedAuthnContext, TElSAMLAuthnQueryElement, RequestedAuthnContext);
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */

		virtual void get_SessionIndex(std::string &OutResult);

		virtual void set_SessionIndex(const std::string &Value);

		TElSAMLAuthnQueryElement(TElSAMLAuthnQueryElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAuthnQueryElement();

		virtual ~TElSAMLAuthnQueryElement();

};
#endif /* SB_USE_CLASS_TELSAMLAUTHNQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEQUERYELEMENT
class TElSAMLAttributeQueryElement: public TElSAMLSubjectQueryAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAttributeQueryElement)
#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
		TElSAMLAttributeElement* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

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

		int32_t AddAttribute();

		void RemoveAttribute(int32_t Index);

#ifdef SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT
		virtual TElSAMLAttributeElement* get_Attributes(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEELEMENT */

		virtual int32_t get_AttributeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AttributeCount, TElSAMLAttributeQueryElement, AttributeCount);

		TElSAMLAttributeQueryElement(TElSAMLAttributeQueryElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAttributeQueryElement();

		virtual ~TElSAMLAttributeQueryElement();

};
#endif /* SB_USE_CLASS_TELSAMLATTRIBUTEQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHZDECISIONQUERYELEMENT
class TElSAMLAuthzDecisionQueryElement: public TElSAMLSubjectQueryAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAuthzDecisionQueryElement)
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

#ifdef SB_USE_CLASS_TELSAMLEVIDENCEELEMENT
		virtual TElSAMLEvidenceElement* get_Evidence();

		virtual void set_Evidence(TElSAMLEvidenceElement &Value);

		virtual void set_Evidence(TElSAMLEvidenceElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLEvidenceElement*, get_Evidence, set_Evidence, TElSAMLAuthzDecisionQueryElement, Evidence);
#endif /* SB_USE_CLASS_TELSAMLEVIDENCEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLACTIONELEMENT
		virtual TElSAMLActionElement* get_Actions(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLACTIONELEMENT */

		virtual int32_t get_ActionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ActionCount, TElSAMLAuthzDecisionQueryElement, ActionCount);

		TElSAMLAuthzDecisionQueryElement(TElSAMLAuthzDecisionQueryElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAuthzDecisionQueryElement();

		virtual ~TElSAMLAuthzDecisionQueryElement();

};
#endif /* SB_USE_CLASS_TELSAMLAUTHZDECISIONQUERYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLRESPONSEELEMENT
class TElSAMLResponseElement: public TElSAMLStatusResponseType
{
	private:
		SB_DISABLE_COPY(TElSAMLResponseElement)
#ifdef SB_USE_CLASS_TELSAMLASSERTIONTYPE
		TElSAMLAssertionType* _Inst_Assertions;
#endif /* SB_USE_CLASS_TELSAMLASSERTIONTYPE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		static TElSAMLStatusResponseTypeHandle GetInstance(TElXMLDOMDocument &Doc);

		static TElSAMLStatusResponseTypeHandle GetInstance(TElXMLDOMDocument *Doc);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElSAMLStatusResponseTypeHandle GetInstance_Inst(TElXMLDOMDocument &Doc);

		TElSAMLStatusResponseTypeHandle GetInstance_Inst(TElXMLDOMDocument *Doc);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

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

		SB_DECLARE_PROPERTY_GET(int32_t, get_AssertionCount, TElSAMLResponseElement, AssertionCount);

		TElSAMLResponseElement(TElSAMLResponseElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLResponseElement();

		virtual ~TElSAMLResponseElement();

};
#endif /* SB_USE_CLASS_TELSAMLRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
class TElSAMLNameIDPolicyElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLNameIDPolicyElement)
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

		virtual void get_Format(std::string &OutResult);

		virtual void set_Format(const std::string &Value);

		virtual void get_SPNameQualifier(std::string &OutResult);

		virtual void set_SPNameQualifier(const std::string &Value);

		virtual bool get_AllowCreate();

		virtual void set_AllowCreate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowCreate, set_AllowCreate, TElSAMLNameIDPolicyElement, AllowCreate);

		virtual bool get_UseAllowCreate();

		virtual void set_UseAllowCreate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseAllowCreate, set_UseAllowCreate, TElSAMLNameIDPolicyElement, UseAllowCreate);

		TElSAMLNameIDPolicyElement(TElSAMLNameIDPolicyElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLNameIDPolicyElement();

};
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLIDPENTRYELEMENT
class TElSAMLIDPEntryElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLIDPEntryElement)
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

		virtual void get_ProviderID(std::string &OutResult);

		virtual void set_ProviderID(const std::string &Value);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Loc(std::string &OutResult);

		virtual void set_Loc(const std::string &Value);

		TElSAMLIDPEntryElement(TElSAMLIDPEntryElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLIDPEntryElement();

};
#endif /* SB_USE_CLASS_TELSAMLIDPENTRYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLIDPLISTELEMENT
class TElSAMLIDPListElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLIDPListElement)
#ifdef SB_USE_CLASS_TELSAMLIDPENTRYELEMENT
		TElSAMLIDPEntryElement* _Inst_IDPEntries;
#endif /* SB_USE_CLASS_TELSAMLIDPENTRYELEMENT */

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

		int32_t AddIDPEntry();

		void RemoveIDPEntry(int32_t Index);

		virtual void get_GetComplete(std::string &OutResult);

		virtual void set_GetComplete(const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLIDPENTRYELEMENT
		virtual TElSAMLIDPEntryElement* get_IDPEntries(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLIDPENTRYELEMENT */

		virtual int32_t get_IDPEntryCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_IDPEntryCount, TElSAMLIDPListElement, IDPEntryCount);

		TElSAMLIDPListElement(TElSAMLIDPListElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLIDPListElement();

		virtual ~TElSAMLIDPListElement();

};
#endif /* SB_USE_CLASS_TELSAMLIDPLISTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSCOPINGELEMENT
class TElSAMLScopingElement: public TElSAMLElement
{
	private:
		SB_DISABLE_COPY(TElSAMLScopingElement)
#ifdef SB_USE_CLASS_TELSAMLIDPLISTELEMENT
		TElSAMLIDPListElement* _Inst_IDPList;
#endif /* SB_USE_CLASS_TELSAMLIDPLISTELEMENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_RequesterIDs;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_RequesterIDs;
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

		virtual int32_t get_ProxyCount();

		virtual void set_ProxyCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ProxyCount, set_ProxyCount, TElSAMLScopingElement, ProxyCount);

#ifdef SB_USE_CLASS_TELSAMLIDPLISTELEMENT
		virtual TElSAMLIDPListElement* get_IDPList();

		virtual void set_IDPList(TElSAMLIDPListElement &Value);

		virtual void set_IDPList(TElSAMLIDPListElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLIDPListElement*, get_IDPList, set_IDPList, TElSAMLScopingElement, IDPList);
#endif /* SB_USE_CLASS_TELSAMLIDPLISTELEMENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_RequesterIDs();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_RequesterIDs, TElSAMLScopingElement, RequesterIDs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_RequesterIDs();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_RequesterIDs, TElSAMLScopingElement, RequesterIDs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElSAMLScopingElement(TElSAMLScopingElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLScopingElement();

		virtual ~TElSAMLScopingElement();

};
#endif /* SB_USE_CLASS_TELSAMLSCOPINGELEMENT */

#ifdef SB_USE_CLASS_TELSAMLAUTHNREQUESTELEMENT
class TElSAMLAuthnRequestElement: public TElSAMLRequestAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLAuthnRequestElement)
#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
		TElSAMLSubjectElement* _Inst_Subject;
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
		TElSAMLNameIDPolicyElement* _Inst_NameIDPolicy;
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */
#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
		TElSAMLConditionsElement* _Inst_Conditions;
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */
#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
		TElSAMLRequestedAuthnContextElement* _Inst_RequestedAuthnContext;
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */
#ifdef SB_USE_CLASS_TELSAMLSCOPINGELEMENT
		TElSAMLScopingElement* _Inst_Scoping;
#endif /* SB_USE_CLASS_TELSAMLSCOPINGELEMENT */

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

		virtual bool get_ForceAuthn();

		virtual void set_ForceAuthn(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceAuthn, set_ForceAuthn, TElSAMLAuthnRequestElement, ForceAuthn);

		virtual bool get_IsPassive();

		virtual void set_IsPassive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsPassive, set_IsPassive, TElSAMLAuthnRequestElement, IsPassive);

		virtual bool get_UseForceAuthn();

		virtual void set_UseForceAuthn(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseForceAuthn, set_UseForceAuthn, TElSAMLAuthnRequestElement, UseForceAuthn);

		virtual bool get_UseIsPassive();

		virtual void set_UseIsPassive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIsPassive, set_UseIsPassive, TElSAMLAuthnRequestElement, UseIsPassive);

		virtual void get_ProtocolBinding(std::string &OutResult);

		virtual void set_ProtocolBinding(const std::string &Value);

		virtual int32_t get_AssertionConsumerServiceIndex();

		virtual void set_AssertionConsumerServiceIndex(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AssertionConsumerServiceIndex, set_AssertionConsumerServiceIndex, TElSAMLAuthnRequestElement, AssertionConsumerServiceIndex);

		virtual void get_AssertionConsumerServiceURL(std::string &OutResult);

		virtual void set_AssertionConsumerServiceURL(const std::string &Value);

		virtual int32_t get_AttributeConsumingServiceIndex();

		virtual void set_AttributeConsumingServiceIndex(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AttributeConsumingServiceIndex, set_AttributeConsumingServiceIndex, TElSAMLAuthnRequestElement, AttributeConsumingServiceIndex);

		virtual void get_ProviderName(std::string &OutResult);

		virtual void set_ProviderName(const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLSUBJECTELEMENT
		virtual TElSAMLSubjectElement* get_Subject();

		virtual void set_Subject(TElSAMLSubjectElement &Value);

		virtual void set_Subject(TElSAMLSubjectElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLSubjectElement*, get_Subject, set_Subject, TElSAMLAuthnRequestElement, Subject);
#endif /* SB_USE_CLASS_TELSAMLSUBJECTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
		virtual TElSAMLNameIDPolicyElement* get_NameIDPolicy();

		virtual void set_NameIDPolicy(TElSAMLNameIDPolicyElement &Value);

		virtual void set_NameIDPolicy(TElSAMLNameIDPolicyElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLNameIDPolicyElement*, get_NameIDPolicy, set_NameIDPolicy, TElSAMLAuthnRequestElement, NameIDPolicy);
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */

#ifdef SB_USE_CLASS_TELSAMLCONDITIONSELEMENT
		virtual TElSAMLConditionsElement* get_Conditions();

		virtual void set_Conditions(TElSAMLConditionsElement &Value);

		virtual void set_Conditions(TElSAMLConditionsElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLConditionsElement*, get_Conditions, set_Conditions, TElSAMLAuthnRequestElement, Conditions);
#endif /* SB_USE_CLASS_TELSAMLCONDITIONSELEMENT */

#ifdef SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT
		virtual TElSAMLRequestedAuthnContextElement* get_RequestedAuthnContext();

		virtual void set_RequestedAuthnContext(TElSAMLRequestedAuthnContextElement &Value);

		virtual void set_RequestedAuthnContext(TElSAMLRequestedAuthnContextElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLRequestedAuthnContextElement*, get_RequestedAuthnContext, set_RequestedAuthnContext, TElSAMLAuthnRequestElement, RequestedAuthnContext);
#endif /* SB_USE_CLASS_TELSAMLREQUESTEDAUTHNCONTEXTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLSCOPINGELEMENT
		virtual TElSAMLScopingElement* get_Scoping();

		virtual void set_Scoping(TElSAMLScopingElement &Value);

		virtual void set_Scoping(TElSAMLScopingElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLScopingElement*, get_Scoping, set_Scoping, TElSAMLAuthnRequestElement, Scoping);
#endif /* SB_USE_CLASS_TELSAMLSCOPINGELEMENT */

		TElSAMLAuthnRequestElement(TElSAMLAuthnRequestElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLAuthnRequestElement();

		virtual ~TElSAMLAuthnRequestElement();

};
#endif /* SB_USE_CLASS_TELSAMLAUTHNREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLARTIFACTRESOLVEELEMENT
class TElSAMLArtifactResolveElement: public TElSAMLRequestAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLArtifactResolveElement)
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

		virtual void get_Artifact(std::string &OutResult);

		virtual void set_Artifact(const std::string &Value);

		TElSAMLArtifactResolveElement(TElSAMLArtifactResolveElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLArtifactResolveElement();

};
#endif /* SB_USE_CLASS_TELSAMLARTIFACTRESOLVEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLARTIFACTRESPONSEELEMENT
class TElSAMLArtifactResponseElement: public TElSAMLStatusResponseType
{
	private:
		SB_DISABLE_COPY(TElSAMLArtifactResponseElement)
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_Optional;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

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

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_Optional();

		virtual void set_Optional(TElXMLDOMElement &Value);

		virtual void set_Optional(TElXMLDOMElement *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMElement*, get_Optional, set_Optional, TElSAMLArtifactResponseElement, Optional);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElSAMLArtifactResponseElement(TElSAMLArtifactResponseElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLArtifactResponseElement();

		virtual ~TElSAMLArtifactResponseElement();

};
#endif /* SB_USE_CLASS_TELSAMLARTIFACTRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLMANAGENAMEIDREQUESTELEMENT
class TElSAMLManageNameIDRequestElement: public TElSAMLRequestAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLManageNameIDRequestElement)
#ifdef SB_USE_CLASS_TELSAMLID
		TElSAMLID* _Inst_NameID;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
		TElSAMLEncryptedElement* _Inst_NewEncryptedID;
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */
		TElSAMLElement* _Inst_Terminate;

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
		virtual TElSAMLID* get_NameID();

		virtual void set_NameID(TElSAMLID &Value);

		virtual void set_NameID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_NameID, set_NameID, TElSAMLManageNameIDRequestElement, NameID);
#endif /* SB_USE_CLASS_TELSAMLID */

		virtual void get_NewID(std::string &OutResult);

		virtual void set_NewID(const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT
		virtual TElSAMLEncryptedElement* get_NewEncryptedID();

		virtual void set_NewEncryptedID(TElSAMLEncryptedElement &Value);

		virtual void set_NewEncryptedID(TElSAMLEncryptedElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLEncryptedElement*, get_NewEncryptedID, set_NewEncryptedID, TElSAMLManageNameIDRequestElement, NewEncryptedID);
#endif /* SB_USE_CLASS_TELSAMLENCRYPTEDELEMENT */

		virtual TElSAMLElement* get_Terminate();

		virtual void set_Terminate(TElSAMLElement &Value);

		virtual void set_Terminate(TElSAMLElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLElement*, get_Terminate, set_Terminate, TElSAMLManageNameIDRequestElement, Terminate);

		TElSAMLManageNameIDRequestElement(TElSAMLManageNameIDRequestElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLManageNameIDRequestElement();

		virtual ~TElSAMLManageNameIDRequestElement();

};
#endif /* SB_USE_CLASS_TELSAMLMANAGENAMEIDREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLMANAGENAMEIDRESPONSEELEMENT
class TElSAMLManageNameIDResponseElement: public TElSAMLStatusResponseType
{
	private:
		SB_DISABLE_COPY(TElSAMLManageNameIDResponseElement)
	public:
		TElSAMLManageNameIDResponseElement(TElSAMLManageNameIDResponseElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLManageNameIDResponseElement();

};
#endif /* SB_USE_CLASS_TELSAMLMANAGENAMEIDRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLLOGOUTREQUESTELEMENT
class TElSAMLLogoutRequestElement: public TElSAMLRequestAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLLogoutRequestElement)
#ifdef SB_USE_CLASS_TELSAMLID
		TElSAMLID* _Inst_NameID;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_SessionIndexes;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_SessionIndexes;
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

#ifdef SB_USE_CLASS_TELSAMLID
		virtual TElSAMLID* get_NameID();

		virtual void set_NameID(TElSAMLID &Value);

		virtual void set_NameID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_NameID, set_NameID, TElSAMLLogoutRequestElement, NameID);
#endif /* SB_USE_CLASS_TELSAMLID */

		virtual void get_Reason(std::string &OutResult);

		virtual void set_Reason(const std::string &Value);

		virtual int64_t get_NotOnOrAfter();

		virtual void set_NotOnOrAfter(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotOnOrAfter, set_NotOnOrAfter, TElSAMLLogoutRequestElement, NotOnOrAfter);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_SessionIndexes();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_SessionIndexes, TElSAMLLogoutRequestElement, SessionIndexes);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_SessionIndexes();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_SessionIndexes, TElSAMLLogoutRequestElement, SessionIndexes);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElSAMLLogoutRequestElement(TElSAMLLogoutRequestElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLLogoutRequestElement();

		virtual ~TElSAMLLogoutRequestElement();

};
#endif /* SB_USE_CLASS_TELSAMLLOGOUTREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLLOGOUTRESPONSEELEMENT
class TElSAMLLogoutResponseElement: public TElSAMLStatusResponseType
{
	private:
		SB_DISABLE_COPY(TElSAMLLogoutResponseElement)
	public:
		TElSAMLLogoutResponseElement(TElSAMLLogoutResponseElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLLogoutResponseElement();

};
#endif /* SB_USE_CLASS_TELSAMLLOGOUTRESPONSEELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDMAPPINGREQUESTELEMENT
class TElSAMLNameIDMappingRequestElement: public TElSAMLRequestAbstractType
{
	private:
		SB_DISABLE_COPY(TElSAMLNameIDMappingRequestElement)
#ifdef SB_USE_CLASS_TELSAMLID
		TElSAMLID* _Inst_NameID;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
		TElSAMLNameIDPolicyElement* _Inst_NameIDPolicy;
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */

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
		virtual TElSAMLID* get_NameID();

		virtual void set_NameID(TElSAMLID &Value);

		virtual void set_NameID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_NameID, set_NameID, TElSAMLNameIDMappingRequestElement, NameID);
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT
		virtual TElSAMLNameIDPolicyElement* get_NameIDPolicy();

		virtual void set_NameIDPolicy(TElSAMLNameIDPolicyElement &Value);

		virtual void set_NameIDPolicy(TElSAMLNameIDPolicyElement *Value);

		SB_DECLARE_PROPERTY(TElSAMLNameIDPolicyElement*, get_NameIDPolicy, set_NameIDPolicy, TElSAMLNameIDMappingRequestElement, NameIDPolicy);
#endif /* SB_USE_CLASS_TELSAMLNAMEIDPOLICYELEMENT */

		TElSAMLNameIDMappingRequestElement(TElSAMLNameIDMappingRequestElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLNameIDMappingRequestElement();

		virtual ~TElSAMLNameIDMappingRequestElement();

};
#endif /* SB_USE_CLASS_TELSAMLNAMEIDMAPPINGREQUESTELEMENT */

#ifdef SB_USE_CLASS_TELSAMLNAMEIDMAPPINGRESPONSEELEMENT
class TElSAMLNameIDMappingResponseElement: public TElSAMLStatusResponseType
{
	private:
		SB_DISABLE_COPY(TElSAMLNameIDMappingResponseElement)
#ifdef SB_USE_CLASS_TELSAMLID
		TElSAMLID* _Inst_NameID;
#endif /* SB_USE_CLASS_TELSAMLID */

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
		virtual TElSAMLID* get_NameID();

		virtual void set_NameID(TElSAMLID &Value);

		virtual void set_NameID(TElSAMLID *Value);

		SB_DECLARE_PROPERTY(TElSAMLID*, get_NameID, set_NameID, TElSAMLNameIDMappingResponseElement, NameID);
#endif /* SB_USE_CLASS_TELSAMLID */

		TElSAMLNameIDMappingResponseElement(TElSAMLNameIDMappingResponseElementHandle handle, TElOwnHandle ownHandle);

		TElSAMLNameIDMappingResponseElement();

		virtual ~TElSAMLNameIDMappingResponseElement();

};
#endif /* SB_USE_CLASS_TELSAMLNAMEIDMAPPINGRESPONSEELEMENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSAMLPROTOCOL */
