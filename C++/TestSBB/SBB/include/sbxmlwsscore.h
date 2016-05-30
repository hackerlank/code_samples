#ifndef __INC_SBXMLWSSCORE
#define __INC_SBXMLWSSCORE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbcryptoprov.h"
#include "sbcustomcertstorage.h"
#include "sbcrlstorage.h"
#include "sbpkcs7.h"
#include "sbstrutils.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbx509.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmlutils.h"
#include "sbxmlsoapcore.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElXMLWSSEElementHandle;

typedef TElClassHandle TElXMLWSSEBaseTokenHandle;

typedef TElClassHandle TElXMLWSSETextElementHandle;

typedef TElClassHandle TElXMLWSSEPasswordHandle;

typedef TElClassHandle TElXMLWSSENonceHandle;

typedef TElClassHandle TElXMLWSUDateTimeHandle;

typedef TElClassHandle TElXMLWSSEUsernameTokenHandle;

typedef TElClassHandle TElXMLWSUTimestampHandle;

typedef TElClassHandle TElXMLWSSEBinarySecurityTokenHandle;

typedef TElClassHandle TElXMLWSSESecurityHandle;

typedef TElClassHandle TElXMLWSSEReferenceHandle;

typedef TElClassHandle TElXMLWSSEKeyIdentifierHandle;

typedef TElClassHandle TElXMLWSSESecurityTokenReferenceHandle;

typedef uint8_t TElXMLWSSESecurityTokenReferenceTypeRaw;

typedef enum
{
	wsrtNone = 0,
	wsrtReference = 1,
	wsrtKeyIdentifier = 2,
	wsrtEmbeddedReference = 3
} TElXMLWSSESecurityTokenReferenceType;

typedef uint8_t TSBXMLWSSETokenTypeRaw;

typedef enum
{
	wttX509v3 = 0,
	wttPKCS7 = 1,
	wttX509PKIPathv1 = 2,
	wttUnknown = 3
} TSBXMLWSSETokenType;

#ifdef SB_USE_CLASS_TELXMLWSSEELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEElement_LoadFromXML(TElXMLWSSEElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEElement_SaveToXML(TElXMLWSSEElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEElement_Create(TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEElement_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEElement_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEElement_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSEELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBaseToken_get_ID(TElXMLWSSEBaseTokenHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBaseToken_set_ID(TElXMLWSSEBaseTokenHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBaseToken_Create(TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBaseToken_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBaseToken_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBaseToken_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */

#ifdef SB_USE_CLASS_TELXMLWSSETEXTELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSETextElement_get_Data(TElXMLWSSETextElementHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSETextElement_set_Data(TElXMLWSSETextElementHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSETextElement_Create(TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSETextElement_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSETextElement_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSETextElement_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSETEXTELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSEPASSWORD
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEPassword_get_PasswordType(TElXMLWSSEPasswordHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEPassword_set_PasswordType(TElXMLWSSEPasswordHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEPassword_Create(TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEPassword_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEPassword_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEPassword_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSEPASSWORD */

#ifdef SB_USE_CLASS_TELXMLWSSENONCE
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSENonce_get_EncodingType(TElXMLWSSENonceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSENonce_set_EncodingType(TElXMLWSSENonceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSENonce_Create(TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSENonce_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSENonce_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSSEElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSENonce_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSENONCE */

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_get_Value(TElXMLWSUDateTimeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_set_Value(TElXMLWSUDateTimeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_get_ValueType(TElXMLWSUDateTimeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_set_ValueType(TElXMLWSUDateTimeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_get_ValueUTC(TElXMLWSUDateTimeHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_set_ValueUTC(TElXMLWSUDateTimeHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_Create(TElXMLWSUDateTimeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSUDateTimeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSUDateTimeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUDateTime_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSUDateTimeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

#ifdef SB_USE_CLASS_TELXMLWSSEUSERNAMETOKEN
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_Clear(TElXMLWSSEUsernameTokenHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_CreateUsername(TElXMLWSSEUsernameTokenHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_CreatePassword(TElXMLWSSEUsernameTokenHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_CreateNonce(TElXMLWSSEUsernameTokenHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_CreateCreated(TElXMLWSSEUsernameTokenHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_LoadFromXML(TElXMLWSSEUsernameTokenHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_get_Username(TElXMLWSSEUsernameTokenHandle _Handle, TElXMLWSSETextElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_get_Password(TElXMLWSSEUsernameTokenHandle _Handle, TElXMLWSSEPasswordHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_get_Nonce(TElXMLWSSEUsernameTokenHandle _Handle, TElXMLWSSENonceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_get_Created(TElXMLWSSEUsernameTokenHandle _Handle, TElXMLWSUDateTimeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_get_CreatedUTC(TElXMLWSSEUsernameTokenHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_set_CreatedUTC(TElXMLWSSEUsernameTokenHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_Create(TElXMLWSSEUsernameTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEUsernameTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSSEUsernameTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEUsernameToken_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEUsernameTokenHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSEUSERNAMETOKEN */

#ifdef SB_USE_CLASS_TELXMLWSUTIMESTAMP
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_Clear(TElXMLWSUTimestampHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_CreateCreated(TElXMLWSUTimestampHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_CreateExpires(TElXMLWSUTimestampHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_LoadFromXML(TElXMLWSUTimestampHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_get_Created(TElXMLWSUTimestampHandle _Handle, TElXMLWSUDateTimeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_get_CreatedUTC(TElXMLWSUTimestampHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_set_CreatedUTC(TElXMLWSUTimestampHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_get_Expires(TElXMLWSUTimestampHandle _Handle, TElXMLWSUDateTimeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_get_ExpiresUTC(TElXMLWSUTimestampHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_set_ExpiresUTC(TElXMLWSUTimestampHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_Create(TElXMLWSUTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSUTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSUTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSUTimestamp_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSUTimestampHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSUTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLWSSEBINARYSECURITYTOKEN
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_Clear(TElXMLWSSEBinarySecurityTokenHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_LoadFromXML(TElXMLWSSEBinarySecurityTokenHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_ExtractCertificates(TElXMLWSSEBinarySecurityTokenHandle _Handle, TElCustomCertStorageHandle CertStorage);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_SetCertificate(TElXMLWSSEBinarySecurityTokenHandle _Handle, TElX509CertificateHandle Cert);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_SetCertificate_1(TElXMLWSSEBinarySecurityTokenHandle _Handle, TElX509CertificateHandle Cert, TSBXMLWSSETokenTypeRaw TokenType);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_SetCertificates(TElXMLWSSEBinarySecurityTokenHandle _Handle, TElCustomCertStorageHandle CertStorage);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_SetCertificates_1(TElXMLWSSEBinarySecurityTokenHandle _Handle, TElCustomCertStorageHandle CertStorage, TSBXMLWSSETokenTypeRaw TokenType);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_get_Data(TElXMLWSSEBinarySecurityTokenHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_set_Data(TElXMLWSSEBinarySecurityTokenHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_get_EncodingType(TElXMLWSSEBinarySecurityTokenHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_set_EncodingType(TElXMLWSSEBinarySecurityTokenHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_get_ValueType(TElXMLWSSEBinarySecurityTokenHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_set_ValueType(TElXMLWSSEBinarySecurityTokenHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_get_TokenType(TElXMLWSSEBinarySecurityTokenHandle _Handle, TSBXMLWSSETokenTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_Create(TElXMLWSSEBinarySecurityTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEBinarySecurityTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSSEBinarySecurityTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEBinarySecurityToken_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSEBinarySecurityTokenHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSEBINARYSECURITYTOKEN */

#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_Clear(TElXMLWSSESecurityHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_LoadFromXML(TElXMLWSSESecurityHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_LoadFromHeaderBlock(TElXMLWSSESecurityHandle _Handle, TElXMLSOAPHeaderBlockHandle AHeaderBlock);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_AddToken(TElXMLWSSESecurityHandle _Handle, TElXMLWSSEBaseTokenHandle AToken, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_get_HeaderBlock(TElXMLWSSESecurityHandle _Handle, TElXMLSOAPHeaderBlockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_set_HeaderBlock(TElXMLWSSESecurityHandle _Handle, TElXMLSOAPHeaderBlockHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_get_TokenCount(TElXMLWSSESecurityHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_get_Tokens(TElXMLWSSESecurityHandle _Handle, int32_t Index, TElXMLWSSEBaseTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_Create(TElXMLWSSESecurityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_Create_1(const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSESecurityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_Create_2(TElXMLDOMElementHandle ParentElement, TElXMLWSSESecurityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurity_Create_3(TElXMLDOMElementHandle ParentElement, const sb_char16_t * pcAName, int32_t szAName, TElXMLWSSESecurityHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

#ifdef SB_USE_CLASS_TELXMLWSSEREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEReference_Clear(TElXMLWSSEReferenceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEReference_LoadFromXML(TElXMLWSSEReferenceHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEReference_SaveToXML(TElXMLWSSEReferenceHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEReference_get_URI(TElXMLWSSEReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEReference_set_URI(TElXMLWSSEReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEReference_get_ValueType(TElXMLWSSEReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEReference_set_ValueType(TElXMLWSSEReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEReference_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSEREFERENCE */

#ifdef SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_Clear(TElXMLWSSEKeyIdentifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_LoadFromXML(TElXMLWSSEKeyIdentifierHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_SaveToXML(TElXMLWSSEKeyIdentifierHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_get_Data(TElXMLWSSEKeyIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_set_Data(TElXMLWSSEKeyIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_get_Value(TElXMLWSSEKeyIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_set_Value(TElXMLWSSEKeyIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_get_ID(TElXMLWSSEKeyIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_set_ID(TElXMLWSSEKeyIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_get_ValueType(TElXMLWSSEKeyIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_set_ValueType(TElXMLWSSEKeyIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_get_EncodingType(TElXMLWSSEKeyIdentifierHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_set_EncodingType(TElXMLWSSEKeyIdentifierHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSEKeyIdentifier_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLWSSESECURITYTOKENREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_Clear(TElXMLWSSESecurityTokenReferenceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_LoadFromXML(TElXMLWSSESecurityTokenReferenceHandle _Handle, TElXMLDOMNodeHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_SaveToXML(TElXMLWSSESecurityTokenReferenceHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_get_ID(TElXMLWSSESecurityTokenReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_set_ID(TElXMLWSSESecurityTokenReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_get_TokenType(TElXMLWSSESecurityTokenReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_set_TokenType(TElXMLWSSESecurityTokenReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_get_Usage(TElXMLWSSESecurityTokenReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_set_Usage(TElXMLWSSESecurityTokenReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_get_ReferenceType(TElXMLWSSESecurityTokenReferenceHandle _Handle, TElXMLWSSESecurityTokenReferenceTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_set_ReferenceType(TElXMLWSSESecurityTokenReferenceHandle _Handle, TElXMLWSSESecurityTokenReferenceTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_get_Reference(TElXMLWSSESecurityTokenReferenceHandle _Handle, TElXMLWSSEReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_get_KeyIdentifier(TElXMLWSSESecurityTokenReferenceHandle _Handle, TElXMLWSSEKeyIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_get_EmbeddedNode(TElXMLWSSESecurityTokenReferenceHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_set_EmbeddedNode(TElXMLWSSESecurityTokenReferenceHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_Create(int8_t OwnResources, TElXMLWSSESecurityTokenReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLWSSESecurityTokenReference_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLWSSESecurityTokenReferenceHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLWSSESECURITYTOKENREFERENCE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLWSSEElement;
class TElXMLWSSEBaseToken;
class TElXMLWSSETextElement;
class TElXMLWSSEPassword;
class TElXMLWSSENonce;
class TElXMLWSUDateTime;
class TElXMLWSSEUsernameToken;
class TElXMLWSUTimestamp;
class TElXMLWSSEBinarySecurityToken;
class TElXMLWSSESecurity;
class TElXMLWSSEReference;
class TElXMLWSSEKeyIdentifier;
class TElXMLWSSESecurityTokenReference;

#ifdef SB_USE_CLASS_TELXMLWSSEELEMENT
class TElXMLWSSEElement: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSSEElement)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		TElXMLWSSEElement(TElXMLWSSEElementHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSEElement();

		explicit TElXMLWSSEElement(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSSEElement(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSSEElement(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSSEElement(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSSEElement(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSSEElement(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSSEElement(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSSEElement(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLWSSEELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
class TElXMLWSSEBaseToken: public TElXMLWSSEElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSSEBaseToken)
	public:
		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLWSSEBaseToken(TElXMLWSSEBaseTokenHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSEBaseToken();

		explicit TElXMLWSSEBaseToken(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSSEBaseToken(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSSEBaseToken(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSSEBaseToken(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSSEBaseToken(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSSEBaseToken(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSSEBaseToken(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSSEBaseToken(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */

#ifdef SB_USE_CLASS_TELXMLWSSETEXTELEMENT
class TElXMLWSSETextElement: public TElXMLWSSEElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSSETextElement)
	public:
		virtual void get_Data(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Data(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Data(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Data(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLWSSETextElement(TElXMLWSSETextElementHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSETextElement();

		explicit TElXMLWSSETextElement(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSSETextElement(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSSETextElement(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSSETextElement(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSSETextElement(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSSETextElement(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSSETextElement(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSSETextElement(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLWSSETEXTELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSEPASSWORD
class TElXMLWSSEPassword: public TElXMLWSSETextElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSSEPassword)
	public:
		virtual void get_PasswordType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PasswordType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_PasswordType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_PasswordType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLWSSEPassword(TElXMLWSSEPasswordHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSEPassword();

		explicit TElXMLWSSEPassword(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSSEPassword(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSSEPassword(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSSEPassword(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSSEPassword(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSSEPassword(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSSEPassword(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSSEPassword(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLWSSEPASSWORD */

#ifdef SB_USE_CLASS_TELXMLWSSENONCE
class TElXMLWSSENonce: public TElXMLWSSETextElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSSENonce)
	public:
		virtual void get_EncodingType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_EncodingType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_EncodingType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_EncodingType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLWSSENonce(TElXMLWSSENonceHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSENonce();

		explicit TElXMLWSSENonce(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSSENonce(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSSENonce(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSSENonce(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSSENonce(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSSENonce(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSSENonce(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSSENonce(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLWSSENONCE */

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
class TElXMLWSUDateTime: public TElXMLWSSEElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSUDateTime)
	public:
		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Value(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Value(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ValueType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ValueType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ValueType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ValueType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_ValueUTC();

		virtual void set_ValueUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValueUTC, set_ValueUTC, TElXMLWSUDateTime, ValueUTC);

		TElXMLWSUDateTime(TElXMLWSUDateTimeHandle handle, TElOwnHandle ownHandle);

		TElXMLWSUDateTime();

		explicit TElXMLWSUDateTime(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSUDateTime(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSUDateTime(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSUDateTime(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSUDateTime(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSUDateTime(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSUDateTime(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSUDateTime(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

#ifdef SB_USE_CLASS_TELXMLWSSEUSERNAMETOKEN
class TElXMLWSSEUsernameToken: public TElXMLWSSEBaseToken
{
	private:
		SB_DISABLE_COPY(TElXMLWSSEUsernameToken)
#ifdef SB_USE_CLASS_TELXMLWSSETEXTELEMENT
		TElXMLWSSETextElement* _Inst_Username;
#endif /* SB_USE_CLASS_TELXMLWSSETEXTELEMENT */
#ifdef SB_USE_CLASS_TELXMLWSSEPASSWORD
		TElXMLWSSEPassword* _Inst_Password;
#endif /* SB_USE_CLASS_TELXMLWSSEPASSWORD */
#ifdef SB_USE_CLASS_TELXMLWSSENONCE
		TElXMLWSSENonce* _Inst_Nonce;
#endif /* SB_USE_CLASS_TELXMLWSSENONCE */
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
		TElXMLWSUDateTime* _Inst_Created;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

		void initInstances();

	public:
		virtual void Clear();

		void CreateUsername();

		void CreatePassword();

		void CreateNonce();

		void CreateCreated();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSETEXTELEMENT
		virtual TElXMLWSSETextElement* get_Username();

		SB_DECLARE_PROPERTY_GET(TElXMLWSSETextElement*, get_Username, TElXMLWSSEUsernameToken, Username);
#endif /* SB_USE_CLASS_TELXMLWSSETEXTELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSEPASSWORD
		virtual TElXMLWSSEPassword* get_Password();

		SB_DECLARE_PROPERTY_GET(TElXMLWSSEPassword*, get_Password, TElXMLWSSEUsernameToken, Password);
#endif /* SB_USE_CLASS_TELXMLWSSEPASSWORD */

#ifdef SB_USE_CLASS_TELXMLWSSENONCE
		virtual TElXMLWSSENonce* get_Nonce();

		SB_DECLARE_PROPERTY_GET(TElXMLWSSENonce*, get_Nonce, TElXMLWSSEUsernameToken, Nonce);
#endif /* SB_USE_CLASS_TELXMLWSSENONCE */

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
		virtual TElXMLWSUDateTime* get_Created();

		SB_DECLARE_PROPERTY_GET(TElXMLWSUDateTime*, get_Created, TElXMLWSSEUsernameToken, Created);
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

		virtual int64_t get_CreatedUTC();

		virtual void set_CreatedUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CreatedUTC, set_CreatedUTC, TElXMLWSSEUsernameToken, CreatedUTC);

		TElXMLWSSEUsernameToken(TElXMLWSSEUsernameTokenHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSEUsernameToken();

		explicit TElXMLWSSEUsernameToken(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSSEUsernameToken(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSSEUsernameToken(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSSEUsernameToken(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSSEUsernameToken(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSSEUsernameToken(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSSEUsernameToken(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSSEUsernameToken(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
		virtual ~TElXMLWSSEUsernameToken();

};
#endif /* SB_USE_CLASS_TELXMLWSSEUSERNAMETOKEN */

#ifdef SB_USE_CLASS_TELXMLWSUTIMESTAMP
class TElXMLWSUTimestamp: public TElXMLWSSEBaseToken
{
	private:
		SB_DISABLE_COPY(TElXMLWSUTimestamp)
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
		TElXMLWSUDateTime* _Inst_Created;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
		TElXMLWSUDateTime* _Inst_Expires;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

		void initInstances();

	public:
		virtual void Clear();

		void CreateCreated();

		void CreateExpires();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
		virtual TElXMLWSUDateTime* get_Created();

		SB_DECLARE_PROPERTY_GET(TElXMLWSUDateTime*, get_Created, TElXMLWSUTimestamp, Created);
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

		virtual int64_t get_CreatedUTC();

		virtual void set_CreatedUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CreatedUTC, set_CreatedUTC, TElXMLWSUTimestamp, CreatedUTC);

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
		virtual TElXMLWSUDateTime* get_Expires();

		SB_DECLARE_PROPERTY_GET(TElXMLWSUDateTime*, get_Expires, TElXMLWSUTimestamp, Expires);
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

		virtual int64_t get_ExpiresUTC();

		virtual void set_ExpiresUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ExpiresUTC, set_ExpiresUTC, TElXMLWSUTimestamp, ExpiresUTC);

		TElXMLWSUTimestamp(TElXMLWSUTimestampHandle handle, TElOwnHandle ownHandle);

		TElXMLWSUTimestamp();

		explicit TElXMLWSUTimestamp(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSUTimestamp(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSUTimestamp(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSUTimestamp(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSUTimestamp(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSUTimestamp(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSUTimestamp(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSUTimestamp(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
		virtual ~TElXMLWSUTimestamp();

};
#endif /* SB_USE_CLASS_TELXMLWSUTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLWSSEBINARYSECURITYTOKEN
class TElXMLWSSEBinarySecurityToken: public TElXMLWSSEBaseToken
{
	private:
		SB_DISABLE_COPY(TElXMLWSSEBinarySecurityToken)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void ExtractCertificates(TElCustomCertStorage &CertStorage);

		void ExtractCertificates(TElCustomCertStorage *CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void SetCertificate(TElX509Certificate &Cert);

		void SetCertificate(TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void SetCertificate(TElX509Certificate &Cert, TSBXMLWSSETokenType TokenType);

		void SetCertificate(TElX509Certificate *Cert, TSBXMLWSSETokenType TokenType);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void SetCertificates(TElCustomCertStorage &CertStorage);

		void SetCertificates(TElCustomCertStorage *CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void SetCertificates(TElCustomCertStorage &CertStorage, TSBXMLWSSETokenType TokenType);

		void SetCertificates(TElCustomCertStorage *CertStorage, TSBXMLWSSETokenType TokenType);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_Data(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Data(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Data(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Data(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_EncodingType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_EncodingType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_EncodingType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_EncodingType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ValueType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ValueType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ValueType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ValueType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TSBXMLWSSETokenType get_TokenType();

		SB_DECLARE_PROPERTY_GET(TSBXMLWSSETokenType, get_TokenType, TElXMLWSSEBinarySecurityToken, TokenType);

		TElXMLWSSEBinarySecurityToken(TElXMLWSSEBinarySecurityTokenHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSEBinarySecurityToken();

		explicit TElXMLWSSEBinarySecurityToken(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSSEBinarySecurityToken(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSSEBinarySecurityToken(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSSEBinarySecurityToken(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSSEBinarySecurityToken(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSSEBinarySecurityToken(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSSEBinarySecurityToken(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSSEBinarySecurityToken(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLWSSEBINARYSECURITYTOKEN */

#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
class TElXMLWSSESecurity: public TElXMLWSSEElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSSESecurity)
#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
		TElXMLSOAPHeaderBlock* _Inst_HeaderBlock;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */
#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
		TElXMLWSSEBaseToken* _Inst_Tokens;
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
		void LoadFromHeaderBlock(TElXMLSOAPHeaderBlock &AHeaderBlock);

		void LoadFromHeaderBlock(TElXMLSOAPHeaderBlock *AHeaderBlock);
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
		int32_t AddToken(TElXMLWSSEBaseToken &AToken);

		int32_t AddToken(TElXMLWSSEBaseToken *AToken);
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
		virtual TElXMLSOAPHeaderBlock* get_HeaderBlock();

		virtual void set_HeaderBlock(TElXMLSOAPHeaderBlock &Value);

		virtual void set_HeaderBlock(TElXMLSOAPHeaderBlock *Value);

		SB_DECLARE_PROPERTY(TElXMLSOAPHeaderBlock*, get_HeaderBlock, set_HeaderBlock, TElXMLWSSESecurity, HeaderBlock);
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

		virtual int32_t get_TokenCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TokenCount, TElXMLWSSESecurity, TokenCount);

#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
		virtual TElXMLWSSEBaseToken* get_Tokens(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */

		TElXMLWSSESecurity(TElXMLWSSESecurityHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSESecurity();

		explicit TElXMLWSSESecurity(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElXMLWSSESecurity(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		explicit TElXMLWSSESecurity(TElXMLDOMElement &ParentElement);

		explicit TElXMLWSSESecurity(TElXMLDOMElement *ParentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLWSSESecurity(TElXMLDOMElement &ParentElement, const sb_u16string &AName);

		TElXMLWSSESecurity(TElXMLDOMElement *ParentElement, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLWSSESecurity(TElXMLDOMElement &ParentElement, const std::wstring &AName);

		TElXMLWSSESecurity(TElXMLDOMElement *ParentElement, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
		virtual ~TElXMLWSSESecurity();

};
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

#ifdef SB_USE_CLASS_TELXMLWSSEREFERENCE
class TElXMLWSSEReference: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSSEReference)
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

		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ValueType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ValueType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ValueType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ValueType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLWSSEReference(TElXMLWSSEReferenceHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSEReference();

};
#endif /* SB_USE_CLASS_TELXMLWSSEREFERENCE */

#ifdef SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER
class TElXMLWSSEKeyIdentifier: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLWSSEKeyIdentifier)
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

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual void set_Data(const std::vector<uint8_t> &Value);

		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Value(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Value(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ValueType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ValueType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ValueType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ValueType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_EncodingType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_EncodingType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_EncodingType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_EncodingType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLWSSEKeyIdentifier(TElXMLWSSEKeyIdentifierHandle handle, TElOwnHandle ownHandle);

		TElXMLWSSEKeyIdentifier();

};
#endif /* SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLWSSESECURITYTOKENREFERENCE
class TElXMLWSSESecurityTokenReference: public TElXMLKeyInfoData
{
	private:
		SB_DISABLE_COPY(TElXMLWSSESecurityTokenReference)
#ifdef SB_USE_CLASS_TELXMLWSSEREFERENCE
		TElXMLWSSEReference* _Inst_Reference;
#endif /* SB_USE_CLASS_TELXMLWSSEREFERENCE */
#ifdef SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER
		TElXMLWSSEKeyIdentifier* _Inst_KeyIdentifier;
#endif /* SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_EmbeddedNode;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual void LoadFromXML(TElXMLDOMNode &Element);

		virtual void LoadFromXML(TElXMLDOMNode *Element);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODE
		virtual TElXMLDOMNodeHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMNodeHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODE */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_TokenType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_TokenType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_TokenType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_TokenType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Usage(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Usage(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Usage(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Usage(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TElXMLWSSESecurityTokenReferenceType get_ReferenceType();

		virtual void set_ReferenceType(TElXMLWSSESecurityTokenReferenceType Value);

		SB_DECLARE_PROPERTY(TElXMLWSSESecurityTokenReferenceType, get_ReferenceType, set_ReferenceType, TElXMLWSSESecurityTokenReference, ReferenceType);

#ifdef SB_USE_CLASS_TELXMLWSSEREFERENCE
		virtual TElXMLWSSEReference* get_Reference();

		SB_DECLARE_PROPERTY_GET(TElXMLWSSEReference*, get_Reference, TElXMLWSSESecurityTokenReference, Reference);
#endif /* SB_USE_CLASS_TELXMLWSSEREFERENCE */

#ifdef SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER
		virtual TElXMLWSSEKeyIdentifier* get_KeyIdentifier();

		SB_DECLARE_PROPERTY_GET(TElXMLWSSEKeyIdentifier*, get_KeyIdentifier, TElXMLWSSESecurityTokenReference, KeyIdentifier);
#endif /* SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_EmbeddedNode();

		virtual void set_EmbeddedNode(TElXMLDOMNode &Value);

		virtual void set_EmbeddedNode(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_EmbeddedNode, set_EmbeddedNode, TElXMLWSSESecurityTokenReference, EmbeddedNode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		TElXMLWSSESecurityTokenReference(TElXMLWSSESecurityTokenReferenceHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLWSSESecurityTokenReference(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLWSSESecurityTokenReference(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLWSSESecurityTokenReference(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLWSSESecurityTokenReference();

};
#endif /* SB_USE_CLASS_TELXMLWSSESECURITYTOKENREFERENCE */

#ifdef SB_USE_GLOBAL_PROCS_XMLWSSCORE

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void WSUGetElementId(TElXMLDOMElement &Element, sb_u16string &OutResult);
void WSUGetElementId(TElXMLDOMElement *Element, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WSUGetElementId(TElXMLDOMElement &Element, std::wstring &OutResult);
void WSUGetElementId(TElXMLDOMElement *Element, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void WSUSetElementId(TElXMLDOMElement &Element, const sb_u16string &Value);
void WSUSetElementId(TElXMLDOMElement *Element, const sb_u16string &Value);
#ifdef SB_U16STRING_USED
void WSUSetElementId(TElXMLDOMElement &Element, const std::wstring &Value);
void WSUSetElementId(TElXMLDOMElement *Element, const std::wstring &Value);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void WSSETokenTypeToURI(TSBXMLWSSETokenType TokenType, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WSSETokenTypeToURI(TSBXMLWSSETokenType TokenType, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_XMLWSSCORE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLWSSCORE
SB_IMPORT uint32_t SB_APIENTRY SBXMLWSSCore_WSUGetElementId(TElXMLDOMElementHandle Element, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLWSSCore_WSUSetElementId(TElXMLDOMElementHandle Element, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBXMLWSSCore_WSSETokenTypeToURI(TSBXMLWSSETokenTypeRaw TokenType, sb_char16_t * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLWSSCORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLWSSCORE */

