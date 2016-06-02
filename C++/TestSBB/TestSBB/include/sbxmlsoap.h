#ifndef __INC_SBXMLSOAP
#define __INC_SBXMLSOAP

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbcryptoprov.h"
#include "sbcustomcertstorage.h"
#include "sbdc.h"
#include "sbdcdef.h"
#include "sbrandom.h"
#include "sbstreams.h"
#include "sbstrutils.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbx509.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmlsig.h"
#include "sbxmlutils.h"
#include "sbxmlades.h"
#include "sbxmladesintf.h"
#include "sbxmlsoapcore.h"
#include "sbxmlwsscore.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SSOAPMessageNotLoaded 	"SOAP message is not loaded"
#define SB_SSOAPSecurityHandlerAlreadyRegistered 	"Security handler already registered"
#define SB_SSOAPNoCertificate 	"No certificate"
#define SB_SSOAPNoKeyData 	"No key data"
#define SB_SSOAPCannotValidateSignatureNotCalculated 	"Cannot validate (signature is not calculated)"
#define SB_SSOAPCannotSignSignatureCalculated 	"Cannot sign (signature already calculated)"
#define SB_SSOAPSignatureHandlerNotAttached 	"The signature handler is not attached to the envelope"
#define SB_SSOAPNothingToSign 	"Nothing to sign"
#define SB_SSOAPUnsupportedCertificatePublicKeyAlg 	"Unsupported certificate public key algorithm"
#define SB_SSOAPCannotCompleteAsyncSignNoSignature 	"Cannot complete async sign (no signature)"
#define SB_SSOAPNotImplemented 	"Not implemented"
#define SB_SSOAPTargetElementHasNoId 	"The target element doesn\'t have an Id"

typedef TElClassHandle TElXMLSOAPMessageHandle;

typedef TElClassHandle TElXMLSOAPCustomSignatureHandlerHandle;

typedef TElClassHandle TElXMLSOAPBaseSignatureHandlerHandle;

typedef TElClassHandle TElXMLSOAPSignatureHandlerClassHandle;

typedef uint8_t TSBXMLSOAPSignatureValidationStatusRaw;

typedef enum
{
	ssvsUnknown = 0,
	ssvsValid = 1,
	ssvsInvalidSignature = 2,
	ssvsInvalidReferenceDigest = 3,
	ssvsNoKey = 4
} TSBXMLSOAPSignatureValidationStatus;

typedef void (SB_CALLBACK *TSBXMLSOAPSignEvent)(void * _ObjectData, TObjectHandle Sender, TElXMLSignerHandle Signer);

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_Clear(TElXMLSOAPMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_CreateEnvelope(TElXMLSOAPMessageHandle _Handle, TElXMLDOMDocumentHandle Document, TSBXMLSOAPVersionRaw Version);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_CreateEnvelope_1(TElXMLSOAPMessageHandle _Handle, TElXMLDOMDocumentHandle Document, TSBXMLSOAPVersionRaw Version, const sb_char16_t * pcSOAPPrefix, int32_t szSOAPPrefix);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_CreateEnvelope_2(TElXMLSOAPMessageHandle _Handle, TElXMLDOMElementHandle ParentElement, TSBXMLSOAPVersionRaw Version);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_CreateEnvelope_3(TElXMLSOAPMessageHandle _Handle, TElXMLDOMElementHandle ParentElement, TSBXMLSOAPVersionRaw Version, const sb_char16_t * pcSOAPPrefix, int32_t szSOAPPrefix);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_LoadFromXML(TElXMLSOAPMessageHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_LoadFromXML_1(TElXMLSOAPMessageHandle _Handle, TElXMLDOMDocumentHandle Document);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_CompleteAsyncSign(TElXMLSOAPMessageHandle _Handle, TElXMLSOAPCustomSignatureHandlerHandle Handler, TElDCAsyncStateHandle State);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_AddSignature(TElXMLSOAPMessageHandle _Handle, TElXMLSOAPCustomSignatureHandlerHandle Handler, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_AddSignature_1(TElXMLSOAPMessageHandle _Handle, TElXMLSOAPCustomSignatureHandlerHandle Handler, int8_t OwnHandler, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_RemoveSignature(TElXMLSOAPMessageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_AddSecurityHeader(TElXMLSOAPMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_RemoveSecurityHeader(TElXMLSOAPMessageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_get_Envelope(TElXMLSOAPMessageHandle _Handle, TElXMLSOAPEnvelopeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_get_SOAPVersion(TElXMLSOAPMessageHandle _Handle, TSBXMLSOAPVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_get_IsSigned(TElXMLSOAPMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_get_SignatureHandlerCount(TElXMLSOAPMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_get_SecurityHeaderCount(TElXMLSOAPMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_get_SignatureHandlers(TElXMLSOAPMessageHandle _Handle, int32_t Index, TElXMLSOAPCustomSignatureHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_get_SecurityHeaders(TElXMLSOAPMessageHandle _Handle, int32_t Index, TElXMLWSSESecurityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPMessage_Create(TComponentHandle AOwner, TElXMLSOAPMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_GetName_1(TElXMLSOAPCustomSignatureHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_LoadFromXML(TElXMLSOAPCustomSignatureHandlerHandle _Handle, TElXMLDOMElementHandle SignatureElement, TElXMLSOAPMessageHandle Msg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_Reset(TElXMLSOAPCustomSignatureHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_CompleteAsyncSign(TElXMLSOAPCustomSignatureHandlerHandle _Handle, TElDCAsyncStateHandle State);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_get_SOAPMessage(TElXMLSOAPCustomSignatureHandlerHandle _Handle, TElXMLSOAPMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_get_XMLElement(TElXMLSOAPCustomSignatureHandlerHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_get_CryptoProviderManager(TElXMLSOAPCustomSignatureHandlerHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_set_CryptoProviderManager(TElXMLSOAPCustomSignatureHandlerHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_get_IsCalculated(TElXMLSOAPCustomSignatureHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPCustomSignatureHandler_Create(TComponentHandle Owner, TElXMLSOAPCustomSignatureHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASESIGNATUREHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_GetName_1(TElXMLSOAPBaseSignatureHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_LoadFromXML(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle SignatureElement, TElXMLSOAPMessageHandle Msg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Reset(TElXMLSOAPBaseSignatureHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_1(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_2(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, int8_t IncludeKey, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_3(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_4(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_5(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_6(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_InitiateAsyncSign_7(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t IncludeKey, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_CompleteAsyncSign(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElDCAsyncStateHandle State);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Sign(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Sign_1(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, int8_t IncludeKey);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Sign_2(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Sign_3(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Sign_4(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Sign_5(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Sign_6(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t IncludeKey);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Validate(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TSBXMLSOAPSignatureValidationStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Validate_1(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TSBXMLSOAPSignatureValidationStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Validate_2(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLKeyInfoDataHandle KeyData, TSBXMLSOAPSignatureValidationStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_AddReference(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle Element, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_AddReference_1(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle Element, int8_t AutoGenerateId, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_AddReference_2(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDOMElementHandle Element, const sb_char16_t * pcCustomId, int32_t szCustomId, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_AddReference_3(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLCustomElementHandle Element, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_AddReference_4(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLCustomElementHandle Element, int8_t AutoGenerateId, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_AddReference_5(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLCustomElementHandle Element, const sb_char16_t * pcCustomId, int32_t szCustomId, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_AddReference_6(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TStreamHandle Stream, const sb_char16_t * pcFileNameURI, int32_t szFileNameURI, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_Verifier(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLVerifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_References(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLReferenceListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_Certificates(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_KeyName(TElXMLSOAPBaseSignatureHandlerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_set_KeyName(TElXMLSOAPBaseSignatureHandlerHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_SignerCertificate(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_SignerKeyData(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_ReferencesDigestMethod(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_set_ReferencesDigestMethod(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXMLDigestMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_XAdESProcessor(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXAdESProcessorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_set_XAdESProcessor(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TElXAdESProcessorHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_OwnXAdESProcessor(TElXMLSOAPBaseSignatureHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_set_OwnXAdESProcessor(TElXMLSOAPBaseSignatureHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_OnPrepareSignature(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TSBXMLSOAPSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_set_OnPrepareSignature(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TSBXMLSOAPSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_OnBeforeSign(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TSBXMLSOAPSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_set_OnBeforeSign(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TSBXMLSOAPSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_get_OnAfterSign(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TSBXMLSOAPSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_set_OnAfterSign(TElXMLSOAPBaseSignatureHandlerHandle _Handle, TSBXMLSOAPSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBaseSignatureHandler_Create(TComponentHandle Owner, TElXMLSOAPBaseSignatureHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPBASESIGNATUREHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLSOAPMessage;
class TElXMLSOAPCustomSignatureHandler;
class TElXMLSOAPBaseSignatureHandler;

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
class TElXMLSOAPMessage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPMessage)
#ifdef SB_USE_CLASS_TELXMLSOAPENVELOPE
		TElXMLSOAPEnvelope* _Inst_Envelope;
#endif /* SB_USE_CLASS_TELXMLSOAPENVELOPE */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
		TElXMLSOAPCustomSignatureHandler* _Inst_SignatureHandlers;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
		TElXMLWSSESecurity* _Inst_SecurityHeaders;
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		void CreateEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion Version);

		void CreateEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion Version);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		void CreateEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion Version, const sb_u16string &SOAPPrefix);

		void CreateEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion Version, const sb_u16string &SOAPPrefix);
#ifdef SB_U16STRING_USED
		void CreateEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion Version, const std::wstring &SOAPPrefix);

		void CreateEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion Version, const std::wstring &SOAPPrefix);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void CreateEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion Version);

		void CreateEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion Version);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void CreateEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion Version, const sb_u16string &SOAPPrefix);

		void CreateEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion Version, const sb_u16string &SOAPPrefix);
#ifdef SB_U16STRING_USED
		void CreateEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion Version, const std::wstring &SOAPPrefix);

		void CreateEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion Version, const std::wstring &SOAPPrefix);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		void LoadFromXML(TElXMLDOMDocument &Document);

		void LoadFromXML(TElXMLDOMDocument *Document);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLSOAPCUSTOMSIGNATUREHANDLER
		void CompleteAsyncSign(TElXMLSOAPCustomSignatureHandler &Handler, TElDCAsyncState &State);

		void CompleteAsyncSign(TElXMLSOAPCustomSignatureHandler *Handler, TElDCAsyncState *State);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
		int32_t AddSignature(TElXMLSOAPCustomSignatureHandler &Handler);

		int32_t AddSignature(TElXMLSOAPCustomSignatureHandler *Handler);
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
		int32_t AddSignature(TElXMLSOAPCustomSignatureHandler &Handler, bool OwnHandler);

		int32_t AddSignature(TElXMLSOAPCustomSignatureHandler *Handler, bool OwnHandler);
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

		void RemoveSignature(int32_t Index);

		int32_t AddSecurityHeader();

		void RemoveSecurityHeader(int32_t Index);

#ifdef SB_USE_CLASS_TELXMLSOAPENVELOPE
		virtual TElXMLSOAPEnvelope* get_Envelope();

		SB_DECLARE_PROPERTY_GET(TElXMLSOAPEnvelope*, get_Envelope, TElXMLSOAPMessage, Envelope);
#endif /* SB_USE_CLASS_TELXMLSOAPENVELOPE */

		virtual TSBXMLSOAPVersion get_SOAPVersion();

		SB_DECLARE_PROPERTY_GET(TSBXMLSOAPVersion, get_SOAPVersion, TElXMLSOAPMessage, SOAPVersion);

		virtual bool get_IsSigned();

		SB_DECLARE_PROPERTY_GET(bool, get_IsSigned, TElXMLSOAPMessage, IsSigned);

		virtual int32_t get_SignatureHandlerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureHandlerCount, TElXMLSOAPMessage, SignatureHandlerCount);

		virtual int32_t get_SecurityHeaderCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SecurityHeaderCount, TElXMLSOAPMessage, SecurityHeaderCount);

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
		virtual TElXMLSOAPCustomSignatureHandler* get_SignatureHandlers(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
		virtual TElXMLWSSESecurity* get_SecurityHeaders(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

		TElXMLSOAPMessage(TElXMLSOAPMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSOAPMessage(TComponent &AOwner);

		explicit TElXMLSOAPMessage(TComponent *AOwner);

		virtual ~TElXMLSOAPMessage();

};
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER
class TElXMLSOAPCustomSignatureHandler: public TComponent
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPCustomSignatureHandler)
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
		TElXMLSOAPMessage* _Inst_SOAPMessage;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_XMLElement;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE
		virtual void LoadFromXML(TElXMLDOMElement &SignatureElement, TElXMLSOAPMessage &Msg);

		virtual void LoadFromXML(TElXMLDOMElement *SignatureElement, TElXMLSOAPMessage *Msg);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE */

		virtual void Reset();

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		virtual void CompleteAsyncSign(TElDCAsyncState &State);

		virtual void CompleteAsyncSign(TElDCAsyncState *State);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
		virtual TElXMLSOAPMessage* get_SOAPMessage();

		SB_DECLARE_PROPERTY_GET(TElXMLSOAPMessage*, get_SOAPMessage, TElXMLSOAPCustomSignatureHandler, SOAPMessage);
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_XMLElement();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMElement*, get_XMLElement, TElXMLSOAPCustomSignatureHandler, XMLElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElXMLSOAPCustomSignatureHandler, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual bool get_IsCalculated();

		SB_DECLARE_PROPERTY_GET(bool, get_IsCalculated, TElXMLSOAPCustomSignatureHandler, IsCalculated);

		TElXMLSOAPCustomSignatureHandler(TElXMLSOAPCustomSignatureHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSOAPCustomSignatureHandler(TComponent &Owner);

		explicit TElXMLSOAPCustomSignatureHandler(TComponent *Owner);

		virtual ~TElXMLSOAPCustomSignatureHandler();

};
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASESIGNATUREHANDLER
class TElXMLSOAPBaseSignatureHandler: public TElXMLSOAPCustomSignatureHandler
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPBaseSignatureHandler)
#ifdef SB_USE_CLASS_TELXMLVERIFIER
		TElXMLVerifier* _Inst_Verifier;
#endif /* SB_USE_CLASS_TELXMLVERIFIER */
#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		TElXMLReferenceList* _Inst_References;
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_SignerCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		TElXMLKeyInfoData* _Inst_SignerKeyData;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
		TElXAdESProcessor* _Inst_XAdESProcessor;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

		void initInstances();

	public:
		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE
		virtual void LoadFromXML(TElXMLDOMElement &SignatureElement, TElXMLSOAPMessage &Msg);

		virtual void LoadFromXML(TElXMLDOMElement *SignatureElement, TElXMLSOAPMessage *Msg);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE */

		virtual void Reset();

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement);

		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate);

		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey);

		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage);

		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey);

		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		virtual void CompleteAsyncSign(TElDCAsyncState &State);

		virtual void CompleteAsyncSign(TElDCAsyncState *State);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		void Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate);

		void Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		void Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey);

		void Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		virtual void Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
		void Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage);

		void Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
		void Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey);

		void Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
		virtual void Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
		virtual void Sign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

		TSBXMLSOAPSignatureValidationStatus Validate();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TSBXMLSOAPSignatureValidationStatus Validate(TElX509Certificate &Certificate);

		TSBXMLSOAPSignatureValidationStatus Validate(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		TSBXMLSOAPSignatureValidationStatus Validate(TElXMLKeyInfoData &KeyData);

		TSBXMLSOAPSignatureValidationStatus Validate(TElXMLKeyInfoData *KeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		int32_t AddReference(TElXMLDOMElement &Element);

		int32_t AddReference(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		int32_t AddReference(TElXMLDOMElement &Element, bool AutoGenerateId);

		int32_t AddReference(TElXMLDOMElement *Element, bool AutoGenerateId);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		int32_t AddReference(TElXMLDOMElement &Element, const sb_u16string &CustomId);

		int32_t AddReference(TElXMLDOMElement *Element, const sb_u16string &CustomId);
#ifdef SB_U16STRING_USED
		int32_t AddReference(TElXMLDOMElement &Element, const std::wstring &CustomId);

		int32_t AddReference(TElXMLDOMElement *Element, const std::wstring &CustomId);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT
		int32_t AddReference(TElXMLCustomElement &Element);

		int32_t AddReference(TElXMLCustomElement *Element);
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT
		int32_t AddReference(TElXMLCustomElement &Element, bool AutoGenerateId);

		int32_t AddReference(TElXMLCustomElement *Element, bool AutoGenerateId);
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT
		int32_t AddReference(TElXMLCustomElement &Element, const sb_u16string &CustomId);

		int32_t AddReference(TElXMLCustomElement *Element, const sb_u16string &CustomId);
#ifdef SB_U16STRING_USED
		int32_t AddReference(TElXMLCustomElement &Element, const std::wstring &CustomId);

		int32_t AddReference(TElXMLCustomElement *Element, const std::wstring &CustomId);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t AddReference(TStream &Stream, const sb_u16string &FileNameURI);

		int32_t AddReference(TStream *Stream, const sb_u16string &FileNameURI);
#ifdef SB_U16STRING_USED
		int32_t AddReference(TStream &Stream, const std::wstring &FileNameURI);

		int32_t AddReference(TStream *Stream, const std::wstring &FileNameURI);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TSTREAM */

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELXMLVERIFIER
		virtual TElXMLVerifier* get_Verifier();

		SB_DECLARE_PROPERTY_GET(TElXMLVerifier*, get_Verifier, TElXMLSOAPBaseSignatureHandler, Verifier);
#endif /* SB_USE_CLASS_TELXMLVERIFIER */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		virtual TElXMLReferenceList* get_References();

		SB_DECLARE_PROPERTY_GET(TElXMLReferenceList*, get_References, TElXMLSOAPBaseSignatureHandler, References);
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_Certificates, TElXMLSOAPBaseSignatureHandler, Certificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_KeyName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_KeyName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_KeyName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_KeyName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_SignerCertificate();

		SB_DECLARE_PROPERTY_GET(TElX509Certificate*, get_SignerCertificate, TElXMLSOAPBaseSignatureHandler, SignerCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		virtual TElXMLKeyInfoData* get_SignerKeyData();

		SB_DECLARE_PROPERTY_GET(TElXMLKeyInfoData*, get_SignerKeyData, TElXMLSOAPBaseSignatureHandler, SignerKeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

		virtual TElXMLDigestMethod get_ReferencesDigestMethod();

		virtual void set_ReferencesDigestMethod(TElXMLDigestMethod Value);

		SB_DECLARE_PROPERTY(TElXMLDigestMethod, get_ReferencesDigestMethod, set_ReferencesDigestMethod, TElXMLSOAPBaseSignatureHandler, ReferencesDigestMethod);

#ifdef SB_USE_CLASS_TELXADESPROCESSOR
		virtual TElXAdESProcessor* get_XAdESProcessor();

		virtual void set_XAdESProcessor(TElXAdESProcessor &Value);

		virtual void set_XAdESProcessor(TElXAdESProcessor *Value);

		SB_DECLARE_PROPERTY(TElXAdESProcessor*, get_XAdESProcessor, set_XAdESProcessor, TElXMLSOAPBaseSignatureHandler, XAdESProcessor);
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

		virtual bool get_OwnXAdESProcessor();

		virtual void set_OwnXAdESProcessor(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnXAdESProcessor, set_OwnXAdESProcessor, TElXMLSOAPBaseSignatureHandler, OwnXAdESProcessor);

		virtual void get_OnPrepareSignature(TSBXMLSOAPSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPrepareSignature(TSBXMLSOAPSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeSign(TSBXMLSOAPSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSign(TSBXMLSOAPSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnAfterSign(TSBXMLSOAPSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAfterSign(TSBXMLSOAPSignEvent pMethodValue, void * pDataValue);

		TElXMLSOAPBaseSignatureHandler(TElXMLSOAPBaseSignatureHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSOAPBaseSignatureHandler(TComponent &Owner);

		explicit TElXMLSOAPBaseSignatureHandler(TComponent *Owner);

		virtual ~TElXMLSOAPBaseSignatureHandler();

};
#endif /* SB_USE_CLASS_TELXMLSOAPBASESIGNATUREHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLSOAP
SB_IMPORT uint32_t SB_APIENTRY SBXMLSOAP_RegisterSecurityHandler(TElXMLSOAPSignatureHandlerClassHandle HandlerClass);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSOAP_UnregisterSecurityHandler(TElXMLSOAPSignatureHandlerClassHandle HandlerClass);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSOAP_Initialize(void);
#endif /* SB_USE_GLOBAL_PROCS_XMLSOAP */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSOAP */

