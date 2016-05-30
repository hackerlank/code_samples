#ifndef __INC_SBXMLSOAPSECURITY
#define __INC_SBXMLSOAPSECURITY

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcustomcertstorage.h"
#include "sbconstants.h"
#include "sbdc.h"
#include "sbdcdef.h"
#include "sbrandom.h"
#include "sbtypes.h"
#include "sbstrutils.h"
#include "sbutils.h"
#include "sbx509.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmlsig.h"
#include "sbxmltransform.h"
#include "sbxmlutils.h"
#include "sbxmlsoapcore.h"
#include "sbxmlwsscore.h"
#include "sbxmlsoap.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElXMLSOAPSignatureHandlerHandle;

typedef TElClassHandle TElXMLWSSSignatureHandlerHandle;

typedef uint8_t TSBXMLWSSEmbedCertificateRaw;

typedef enum
{
	wecInSignature = 0,
	wecInBinarySecurityToken = 1,
	wecInSignedBinarySecurityToken = 2,
	wecInBinarySecurityTokenAndSignature = 3,
	wecNone = 4
} TSBXMLWSSEmbedCertificate;

#ifdef SB_USE_CLASS_TELXMLSOAPSIGNATUREHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_GetName_1(TElXMLSOAPSignatureHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_LoadFromXML(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLDOMElementHandle SignatureElement, TElXMLSOAPMessageHandle Msg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Reset(TElXMLSOAPSignatureHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign(TElXMLSOAPSignatureHandlerHandle _Handle, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_1(TElXMLSOAPSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_2(TElXMLSOAPSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, int8_t IncludeKey, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_3(TElXMLSOAPSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_4(TElXMLSOAPSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_5(TElXMLSOAPSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_6(TElXMLSOAPSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_7(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t IncludeKey, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_8(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_9(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_InitiateAsyncSign_10(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t IncludeKey, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign(TElXMLSOAPSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_1(TElXMLSOAPSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, int8_t IncludeKey);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_2(TElXMLSOAPSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_3(TElXMLSOAPSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_4(TElXMLSOAPSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_5(TElXMLSOAPSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_6(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t IncludeKey);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_7(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_8(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Sign_9(TElXMLSOAPSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t IncludeKey);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_get_ID(TElXMLSOAPSignatureHandlerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_set_ID(TElXMLSOAPSignatureHandlerHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_get_Actor(TElXMLSOAPSignatureHandlerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_set_Actor(TElXMLSOAPSignatureHandlerHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_get_MustUnderstand(TElXMLSOAPSignatureHandlerHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_set_MustUnderstand(TElXMLSOAPSignatureHandlerHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPSignatureHandler_Create(TComponentHandle Owner, TElXMLSOAPSignatureHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLWSSSIGNATUREHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_GetName_1(TElXMLWSSSignatureHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Reset(TElXMLWSSSignatureHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign(TElXMLWSSSignatureHandlerHandle _Handle, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_1(TElXMLWSSSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_2(TElXMLWSSSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_3(TElXMLWSSSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, const sb_char16_t * pcTokenID, int32_t szTokenID, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_4(TElXMLWSSSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, TSBXMLWSSETokenTypeRaw TokenType, const sb_char16_t * pcTokenID, int32_t szTokenID, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_5(TElXMLWSSSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_6(TElXMLWSSSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_7(TElXMLWSSSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, const sb_char16_t * pcTokenID, int32_t szTokenID, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_8(TElXMLWSSSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, TSBXMLWSSETokenTypeRaw TokenType, const sb_char16_t * pcTokenID, int32_t szTokenID, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_9(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t EmbedKeyInSignature, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_10(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_11(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_InitiateAsyncSign_12(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t IncludeKey, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign(TElXMLWSSSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_1(TElXMLWSSSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TSBXMLWSSEmbedCertificateRaw EmbedCertificate);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_2(TElXMLWSSSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, const sb_char16_t * pcTokenID, int32_t szTokenID);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_3(TElXMLWSSSignatureHandlerHandle _Handle, TElX509CertificateHandle Certificate, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, TSBXMLWSSETokenTypeRaw TokenType, const sb_char16_t * pcTokenID, int32_t szTokenID);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_4(TElXMLWSSSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_5(TElXMLWSSSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, TSBXMLWSSEmbedCertificateRaw EmbedCertificate);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_6(TElXMLWSSSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, const sb_char16_t * pcTokenID, int32_t szTokenID);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_7(TElXMLWSSSignatureHandlerHandle _Handle, TElCustomCertStorageHandle CertStorage, TSBXMLWSSEmbedCertificateRaw EmbedCertificate, TSBXMLWSSETokenTypeRaw TokenType, const sb_char16_t * pcTokenID, int32_t szTokenID);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_8(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t EmbedKeyInSignature);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_9(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElX509CertificateHandle Certificate, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_10(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElCustomCertStorageHandle CertStorage, int8_t IncludeKey, int8_t IncludeKeyValue, TElXMLKeyInfoX509DataParamsRaw IncludeDataParams);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Sign_11(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLDOMElementHandle ParentElement, TElXMLKeyInfoDataHandle KeyData, TElXMLSignatureMethodRaw SignatureMethod, int8_t IncludeKey);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_get_SecurityHeader(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLWSSESecurityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_set_SecurityHeader(TElXMLWSSSignatureHandlerHandle _Handle, TElXMLWSSESecurityHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSSignatureHandler_Create(TComponentHandle Owner, TElXMLSOAPBaseSignatureHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSSIGNATUREHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLSOAPSignatureHandler;
class TElXMLWSSSignatureHandler;

#ifdef SB_USE_CLASS_TELXMLSOAPSIGNATUREHANDLER
class TElXMLSOAPSignatureHandler: public TElXMLSOAPBaseSignatureHandler
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPSignatureHandler)
	public:
		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE
		virtual void LoadFromXML(TElXMLDOMElement &SignatureElement, TElXMLSOAPMessage &Msg);

		virtual void LoadFromXML(TElXMLDOMElement *SignatureElement, TElXMLSOAPMessage *Msg);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE */

		virtual void Reset();

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign();
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate, bool IncludeKey);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage, bool IncludeKey);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA
		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);

		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Sign(TElX509Certificate &Certificate);

		void Sign(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Sign(TElX509Certificate &Certificate, bool IncludeKey);

		void Sign(TElX509Certificate *Certificate, bool IncludeKey);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Sign(TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		void Sign(TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void Sign(TElCustomCertStorage &CertStorage);

		void Sign(TElCustomCertStorage *CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void Sign(TElCustomCertStorage &CertStorage, bool IncludeKey);

		void Sign(TElCustomCertStorage *CertStorage, bool IncludeKey);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void Sign(TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		void Sign(TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		void Sign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);

		void Sign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		virtual void Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
		virtual void Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
		virtual void Sign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

		static TClassHandle ClassType();

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Actor(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Actor(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Actor(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Actor(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_MustUnderstand(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_MustUnderstand(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_MustUnderstand(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_MustUnderstand(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPSignatureHandler(TElXMLSOAPSignatureHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSOAPSignatureHandler(TComponent &Owner);

		explicit TElXMLSOAPSignatureHandler(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELXMLSOAPSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLWSSSIGNATUREHANDLER
class TElXMLWSSSignatureHandler: public TElXMLSOAPBaseSignatureHandler
{
	private:
		SB_DISABLE_COPY(TElXMLWSSSignatureHandler)
#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
		TElXMLWSSESecurity* _Inst_SecurityHeader;
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

		void initInstances();

	public:
		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

		virtual void Reset();

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign();
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID);
#ifdef SB_U16STRING_USED
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID);
#ifdef SB_U16STRING_USED
		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID);

		TElDCAsyncStateHandle InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID);
#ifdef SB_U16STRING_USED
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID);
#ifdef SB_U16STRING_USED
		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID);

		TElDCAsyncStateHandle InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA
		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature);

		TElDCAsyncStateHandle InitiateAsyncSign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);

		virtual TElDCAsyncStateHandle InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Sign(TElX509Certificate &Certificate);

		void Sign(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate);

		void Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID);

		void Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID);
#ifdef SB_U16STRING_USED
		void Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID);

		void Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID);

		void Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID);
#ifdef SB_U16STRING_USED
		void Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID);

		void Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void Sign(TElCustomCertStorage &CertStorage);

		void Sign(TElCustomCertStorage *CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate);

		void Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID);

		void Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID);
#ifdef SB_U16STRING_USED
		void Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID);

		void Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID);

		void Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID);
#ifdef SB_U16STRING_USED
		void Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID);

		void Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		void Sign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature);

		void Sign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
		virtual void Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
		virtual void Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
		virtual void Sign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);

		virtual void Sign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
		virtual TElXMLWSSESecurity* get_SecurityHeader();

		virtual void set_SecurityHeader(TElXMLWSSESecurity &Value);

		virtual void set_SecurityHeader(TElXMLWSSESecurity *Value);

		SB_DECLARE_PROPERTY(TElXMLWSSESecurity*, get_SecurityHeader, set_SecurityHeader, TElXMLWSSSignatureHandler, SecurityHeader);
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

		TElXMLWSSSignatureHandler(TElXMLWSSSignatureHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLWSSSignatureHandler(TComponent &Owner);

		explicit TElXMLWSSSignatureHandler(TComponent *Owner);

		virtual ~TElXMLWSSSignatureHandler();

};
#endif /* SB_USE_CLASS_TELXMLWSSSIGNATUREHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSOAPSECURITY */

