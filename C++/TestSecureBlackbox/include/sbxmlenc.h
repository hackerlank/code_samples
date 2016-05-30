#ifndef __INC_SBXMLENC
#define __INC_SBXMLENC

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
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmlcharsets.h"
#include "sbxmltransform.h"
#include "sbxmlutils.h"
#include "sbcryptoprov.h"
#include "sbpublickeycrypto.h"
#include "sbsymmetriccrypto.h"
#include "sbx509.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_XML_ENC_ERROR_OK 	0
#define SB_XML_ENC_ERROR_NO_ENCRYPTEDDATA 	34049
#define SB_XML_ENC_ERROR_BAD_DECRYPTED_DATA 	34050
#define SB_XML_ENC_ERROR_UNSUPPORTED_HASH_ALGORITHM 	34053
#define SB_XML_ENC_ERROR_BAD_KEYSIZE 	34054
#define SB_XML_ENC_ERROR_BAD_KEY_LENGTH 	34055
#define SB_XML_ENC_ERROR_NO_DOCUMENT 	34056
#define SB_XML_ENC_ERROR_INVALID_KEY 	34096
#define SB_XML_ENC_ERROR_NO_KEY_DATA 	34098
#define SB_XML_ENC_ERROR_INVALID_KEY_DATA 	34099
#define SB_XML_ENC_ERROR_INVALID_KEK 	34128
#define SB_XML_ENC_ERROR_KEK_NO_KEY_DATA 	34130
#define SB_XML_ENC_ERROR_KEK_INVALID_KEY_DATA 	34131
#define SB_XML_ENC_ERROR_UNKNOWN 	34303

typedef TElClassHandle TElXMLEncryptedDataHandle;

typedef TElXMLEncryptedDataHandle ElXMLEncryptedDataHandle;

typedef TElClassHandle TElXMLEncProcessorHandle;

typedef TElXMLEncProcessorHandle ElXMLEncProcessorHandle;

typedef TElClassHandle TElXMLEncryptorHandle;

typedef TElXMLEncryptorHandle ElXMLEncryptorHandle;

typedef TElClassHandle TElXMLDecryptorHandle;

typedef TElXMLDecryptorHandle ElXMLDecryptorHandle;

typedef TElClassHandle TElXMLCipherReferenceHandle;

typedef TElXMLCipherReferenceHandle ElXMLCipherReferenceHandle;

typedef TElClassHandle TElXMLCipherDataHandle;

typedef TElXMLCipherDataHandle ElXMLCipherDataHandle;

typedef TElClassHandle TElXMLEncryptionMethodTypeHandle;

typedef TElXMLEncryptionMethodTypeHandle ElXMLEncryptionMethodTypeHandle;

typedef TElClassHandle TElXMLEncryptionPropertiesHandle;

typedef TElXMLEncryptionPropertiesHandle ElXMLEncryptionPropertiesHandle;

typedef TElClassHandle TElXMLEncryptedTypeHandle;

typedef TElXMLEncryptedTypeHandle ElXMLEncryptedTypeHandle;

typedef TElClassHandle TElXMLEncryptedKeyHandle;

typedef TElXMLEncryptedKeyHandle ElXMLEncryptedKeyHandle;

typedef TElClassHandle TElXMLDecryptionExceptHandle;

typedef TElXMLDecryptionExceptHandle ElXMLDecryptionExceptHandle;

typedef TElClassHandle TElXMLCustomDecryptionTransformHandle;

typedef TElXMLCustomDecryptionTransformHandle ElXMLCustomDecryptionTransformHandle;

typedef TElClassHandle TElXMLDecryptionTransformHandle;

typedef TElXMLDecryptionTransformHandle ElXMLDecryptionTransformHandle;

typedef TElClassHandle TElXMLBinaryDecryptionTransformHandle;

typedef TElXMLBinaryDecryptionTransformHandle ElXMLBinaryDecryptionTransformHandle;

typedef void (SB_CALLBACK *TSBXMLDecryptKeyDataEvent)(void * _ObjectData, TObjectHandle Sender, TElXMLDOMElementHandle EncryptedData, TElXMLDecryptorHandle Decryptor, int32_t PrevResult, TElXMLKeyInfoDataHandle * KeyData, int8_t * OutResult);

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDTYPE
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_Clear(TElXMLEncryptedTypeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_IsEmpty(TElXMLEncryptedTypeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_LoadFromXML(TElXMLEncryptedTypeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_SaveToXML(TElXMLEncryptedTypeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_EncryptionMethod(TElXMLEncryptedTypeHandle _Handle, TElXMLEncryptionMethodTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_EncryptionMethod(TElXMLEncryptedTypeHandle _Handle, TElXMLEncryptionMethodTypeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_CipherData(TElXMLEncryptedTypeHandle _Handle, TElXMLCipherDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_CipherData(TElXMLEncryptedTypeHandle _Handle, TElXMLCipherDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_KeyInfo(TElXMLEncryptedTypeHandle _Handle, TElXMLKeyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_KeyInfo(TElXMLEncryptedTypeHandle _Handle, TElXMLKeyInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_EncryptionProperties(TElXMLEncryptedTypeHandle _Handle, TElXMLEncryptionPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_EncryptionProperties(TElXMLEncryptedTypeHandle _Handle, TElXMLEncryptionPropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_ID(TElXMLEncryptedTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_ID(TElXMLEncryptedTypeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_DataType(TElXMLEncryptedTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_DataType(TElXMLEncryptedTypeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_MimeType(TElXMLEncryptedTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_MimeType(TElXMLEncryptedTypeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_Encoding(TElXMLEncryptedTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_Encoding(TElXMLEncryptedTypeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_get_CryptoProviderManager(TElXMLEncryptedTypeHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_set_CryptoProviderManager(TElXMLEncryptedTypeHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedType_Create(TElXMLEncryptedTypeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDTYPE */

#ifdef SB_USE_CLASS_TELXMLENCPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncProcessor_get_KeyEncryptionKeyData(TElXMLEncProcessorHandle _Handle, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncProcessor_set_KeyEncryptionKeyData(TElXMLEncProcessorHandle _Handle, TElXMLKeyInfoDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncProcessor_get_EncryptedData(TElXMLEncProcessorHandle _Handle, TElXMLEncryptedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncProcessor_set_EncryptedData(TElXMLEncProcessorHandle _Handle, TElXMLEncryptedDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncProcessor_Create(TComponentHandle AOwner, TElXMLEncProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLENCRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_Encrypt(TElXMLEncryptorHandle _Handle, const TElXMLDOMNodeHandle Data);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_Encrypt_1(TElXMLEncryptorHandle _Handle, const TElXMLDOMNodeListHandle Data);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_Encrypt_2(TElXMLEncryptorHandle _Handle, const uint8_t pData[], int32_t szData);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_Save(TElXMLEncryptorHandle _Handle, const TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_SaveToDocument(TElXMLEncryptorHandle _Handle, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_KeyData(TElXMLEncryptorHandle _Handle, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_KeyData(TElXMLEncryptorHandle _Handle, TElXMLKeyInfoDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_EncryptKey(TElXMLEncryptorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_EncryptKey(TElXMLEncryptorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_KeyName(TElXMLEncryptorHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_KeyName(TElXMLEncryptorHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_EncryptedDataType(TElXMLEncryptorHandle _Handle, TElXMLEncryptedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_EncryptedDataType(TElXMLEncryptorHandle _Handle, TElXMLEncryptedDataTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_EncryptionMethod(TElXMLEncryptorHandle _Handle, TElXMLEncryptionMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_EncryptionMethod(TElXMLEncryptorHandle _Handle, TElXMLEncryptionMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_KeyEncryptionType(TElXMLEncryptorHandle _Handle, TElXMLKeyEncryptionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_KeyEncryptionType(TElXMLEncryptorHandle _Handle, TElXMLKeyEncryptionTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_KeyTransportMethod(TElXMLEncryptorHandle _Handle, TElXMLKeyTransportMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_KeyTransportMethod(TElXMLEncryptorHandle _Handle, TElXMLKeyTransportMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_KeyWrapMethod(TElXMLEncryptorHandle _Handle, TElXMLKeyWrapMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_KeyWrapMethod(TElXMLEncryptorHandle _Handle, TElXMLKeyWrapMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_IncludeKeyEncryptionKey(TElXMLEncryptorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_IncludeKeyEncryptionKey(TElXMLEncryptorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_MimeType(TElXMLEncryptorHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_MimeType(TElXMLEncryptorHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_OnFormatElement(TElXMLEncryptorHandle _Handle, TSBXMLFormatElementEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_OnFormatElement(TElXMLEncryptorHandle _Handle, TSBXMLFormatElementEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_get_OnFormatText(TElXMLEncryptorHandle _Handle, TSBXMLFormatTextEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_set_OnFormatText(TElXMLEncryptorHandle _Handle, TSBXMLFormatTextEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptor_Create(TComponentHandle AOwner, TElXMLEncryptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCRYPTOR */

#ifdef SB_USE_CLASS_TELXMLDECRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_Decrypt(TElXMLDecryptorHandle _Handle, const TElXMLDOMDocumentHandle OwnerDocument, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_Load(TElXMLDecryptorHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_Load_1(TElXMLDecryptorHandle _Handle, TElXMLDOMDocumentHandle Document);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_DecryptedNode(TElXMLDecryptorHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_set_DecryptedNode(TElXMLDecryptorHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_DecryptedNodeList(TElXMLDecryptorHandle _Handle, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_set_DecryptedNodeList(TElXMLDecryptorHandle _Handle, TElXMLDOMNodeListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_DecryptedData(TElXMLDecryptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_set_DecryptedData(TElXMLDecryptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_EncryptedDataType(TElXMLDecryptorHandle _Handle, TElXMLEncryptedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_EncryptionMethod(TElXMLDecryptorHandle _Handle, TElXMLEncryptionMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_EncryptKey(TElXMLDecryptorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_KeyName(TElXMLDecryptorHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_KeyEncryptionType(TElXMLDecryptorHandle _Handle, TElXMLKeyEncryptionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_KeyTransportMethod(TElXMLDecryptorHandle _Handle, TElXMLKeyTransportMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_KeyWrapMethod(TElXMLDecryptorHandle _Handle, TElXMLKeyWrapMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_MimeType(TElXMLDecryptorHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_get_KeyData(TElXMLDecryptorHandle _Handle, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_set_KeyData(TElXMLDecryptorHandle _Handle, TElXMLKeyInfoDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptor_Create(TComponentHandle AOwner, TElXMLDecryptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDECRYPTOR */

#ifdef SB_USE_CLASS_TELXMLCIPHERREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_Clear(TElXMLCipherReferenceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_IsEmpty(TElXMLCipherReferenceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_LoadFromXML(TElXMLCipherReferenceHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_SaveToXML(TElXMLCipherReferenceHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_get_CipherValue(TElXMLCipherReferenceHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_set_CipherValue(TElXMLCipherReferenceHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_get_TransformChain(TElXMLCipherReferenceHandle _Handle, TElXMLTransformChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_set_TransformChain(TElXMLCipherReferenceHandle _Handle, TElXMLTransformChainHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_get_URI(TElXMLCipherReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_set_URI(TElXMLCipherReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherReference_Create(TElXMLCipherReferenceHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCIPHERREFERENCE */

#ifdef SB_USE_CLASS_TELXMLCIPHERDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_Clear(TElXMLCipherDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_IsEmpty(TElXMLCipherDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_LoadFromXML(TElXMLCipherDataHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_SaveToXML(TElXMLCipherDataHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_get_CipherValue(TElXMLCipherDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_set_CipherValue(TElXMLCipherDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_get_CipherReference(TElXMLCipherDataHandle _Handle, TElXMLCipherReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_set_CipherReference(TElXMLCipherDataHandle _Handle, TElXMLCipherReferenceHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCipherData_Create(TElXMLCipherDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCIPHERDATA */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_Clear(TElXMLEncryptionMethodTypeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_IsEmpty(TElXMLEncryptionMethodTypeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_LoadFromXML(TElXMLEncryptionMethodTypeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_SaveToXML(TElXMLEncryptionMethodTypeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_get_Algorithm(TElXMLEncryptionMethodTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_set_Algorithm(TElXMLEncryptionMethodTypeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_get_KeySize(TElXMLEncryptionMethodTypeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_set_KeySize(TElXMLEncryptionMethodTypeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_get_OAEPparams(TElXMLEncryptionMethodTypeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_set_OAEPparams(TElXMLEncryptionMethodTypeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_get_DigestMethod(TElXMLEncryptionMethodTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_set_DigestMethod(TElXMLEncryptionMethodTypeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionMethodType_Create(TElXMLEncryptionMethodTypeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptionProperties_Create(TElXMLEncryptionPropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_Clear(TElXMLEncryptedDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_IsEmpty(TElXMLEncryptedDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_LoadFromXML(TElXMLEncryptedDataHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_SaveToXML(TElXMLEncryptedDataHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_get_EncryptionPrefix(TElXMLEncryptedDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_set_EncryptionPrefix(TElXMLEncryptedDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_get_SignaturePrefix(TElXMLEncryptedDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_set_SignaturePrefix(TElXMLEncryptedDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_get_EncryptedKey(TElXMLEncryptedDataHandle _Handle, TElXMLEncryptedKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_set_EncryptedKey(TElXMLEncryptedDataHandle _Handle, TElXMLEncryptedKeyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedData_Create(TElXMLEncryptedDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDDATA */

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDKEY
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_Clear(TElXMLEncryptedKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_IsEmpty(TElXMLEncryptedKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_LoadFromXML(TElXMLEncryptedKeyHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_SaveToXML(TElXMLEncryptedKeyHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_get_CarriedKeyName(TElXMLEncryptedKeyHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_set_CarriedKeyName(TElXMLEncryptedKeyHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_get_Recipient(TElXMLEncryptedKeyHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_set_Recipient(TElXMLEncryptedKeyHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLEncryptedKey_Create(TElXMLEncryptedKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDKEY */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionExcept_Clone(TElXMLDecryptionExceptHandle _Handle, TElXMLDecryptionExceptHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionExcept_get_ID(TElXMLDecryptionExceptHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionExcept_set_ID(TElXMLDecryptionExceptHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionExcept_get_URI(TElXMLDecryptionExceptHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionExcept_set_URI(TElXMLDecryptionExceptHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionExcept_Create(TElXMLDecryptionExceptHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMDECRYPTIONTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_LoadFromXML(TElXMLCustomDecryptionTransformHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_SaveToXML(TElXMLCustomDecryptionTransformHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_Add(TElXMLCustomDecryptionTransformHandle _Handle, TElXMLDecryptionExceptHandle AExcept, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_Add_1(TElXMLCustomDecryptionTransformHandle _Handle, const sb_char16_t * pcExceptID, int32_t szExceptID, const sb_char16_t * pcExceptURI, int32_t szExceptURI, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_Insert(TElXMLCustomDecryptionTransformHandle _Handle, int32_t Index, TElXMLDecryptionExceptHandle AExcept);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_Delete(TElXMLCustomDecryptionTransformHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_Clear(TElXMLCustomDecryptionTransformHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_get_Count(TElXMLCustomDecryptionTransformHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_get_Excepts(TElXMLCustomDecryptionTransformHandle _Handle, int32_t Index, TElXMLDecryptionExceptHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_get_KeyData(TElXMLCustomDecryptionTransformHandle _Handle, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_set_KeyData(TElXMLCustomDecryptionTransformHandle _Handle, TElXMLKeyInfoDataHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_get_OnKeyData(TElXMLCustomDecryptionTransformHandle _Handle, TSBXMLDecryptKeyDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_set_OnKeyData(TElXMLCustomDecryptionTransformHandle _Handle, TSBXMLDecryptKeyDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomDecryptionTransform_Create(TElXMLCustomDecryptionTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCUSTOMDECRYPTIONTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_GetDefaultTransformAlgorithmURI_1(TElXMLDecryptionTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_IsTransformAlgorithmSupported_1(TElXMLDecryptionTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_TransformData(TElXMLDecryptionTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_TransformData_1(TElXMLDecryptionTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_TransformData_2(TElXMLDecryptionTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDecryptionTransform_Create(TElXMLCustomDecryptionTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLBINARYDECRYPTIONTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_GetDefaultTransformAlgorithmURI_1(TElXMLBinaryDecryptionTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_IsTransformAlgorithmSupported_1(TElXMLBinaryDecryptionTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_TransformData(TElXMLBinaryDecryptionTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_TransformData_1(TElXMLBinaryDecryptionTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_TransformData_2(TElXMLBinaryDecryptionTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBinaryDecryptionTransform_Create(TElXMLCustomDecryptionTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLBINARYDECRYPTIONTRANSFORM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLEncryptedData;
typedef TElXMLEncryptedData ElXMLEncryptedData;
class TElXMLEncProcessor;
typedef TElXMLEncProcessor ElXMLEncProcessor;
class TElXMLEncryptor;
typedef TElXMLEncryptor ElXMLEncryptor;
class TElXMLDecryptor;
typedef TElXMLDecryptor ElXMLDecryptor;
class TElXMLCipherReference;
typedef TElXMLCipherReference ElXMLCipherReference;
class TElXMLCipherData;
typedef TElXMLCipherData ElXMLCipherData;
class TElXMLEncryptionMethodType;
typedef TElXMLEncryptionMethodType ElXMLEncryptionMethodType;
class TElXMLEncryptionProperties;
typedef TElXMLEncryptionProperties ElXMLEncryptionProperties;
class TElXMLEncryptedType;
typedef TElXMLEncryptedType ElXMLEncryptedType;
class TElXMLEncryptedKey;
typedef TElXMLEncryptedKey ElXMLEncryptedKey;
class TElXMLDecryptionExcept;
typedef TElXMLDecryptionExcept ElXMLDecryptionExcept;
class TElXMLCustomDecryptionTransform;
typedef TElXMLCustomDecryptionTransform ElXMLCustomDecryptionTransform;
class TElXMLDecryptionTransform;
typedef TElXMLDecryptionTransform ElXMLDecryptionTransform;
class TElXMLBinaryDecryptionTransform;
typedef TElXMLBinaryDecryptionTransform ElXMLBinaryDecryptionTransform;

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDTYPE
class TElXMLEncryptedType: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLEncryptedType)
#ifdef SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE
		TElXMLEncryptionMethodType* _Inst_EncryptionMethod;
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE */
#ifdef SB_USE_CLASS_TELXMLCIPHERDATA
		TElXMLCipherData* _Inst_CipherData;
#endif /* SB_USE_CLASS_TELXMLCIPHERDATA */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
		TElXMLKeyInfo* _Inst_KeyInfo;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES
		TElXMLEncryptionProperties* _Inst_EncryptionProperties;
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

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

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE
		virtual TElXMLEncryptionMethodType* get_EncryptionMethod();

		virtual void set_EncryptionMethod(TElXMLEncryptionMethodType &Value);

		virtual void set_EncryptionMethod(TElXMLEncryptionMethodType *Value);

		SB_DECLARE_PROPERTY(TElXMLEncryptionMethodType*, get_EncryptionMethod, set_EncryptionMethod, TElXMLEncryptedType, EncryptionMethod);
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLCIPHERDATA
		virtual TElXMLCipherData* get_CipherData();

		virtual void set_CipherData(TElXMLCipherData &Value);

		virtual void set_CipherData(TElXMLCipherData *Value);

		SB_DECLARE_PROPERTY(TElXMLCipherData*, get_CipherData, set_CipherData, TElXMLEncryptedType, CipherData);
#endif /* SB_USE_CLASS_TELXMLCIPHERDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFO
		virtual TElXMLKeyInfo* get_KeyInfo();

		virtual void set_KeyInfo(TElXMLKeyInfo &Value);

		virtual void set_KeyInfo(TElXMLKeyInfo *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfo*, get_KeyInfo, set_KeyInfo, TElXMLEncryptedType, KeyInfo);
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES
		virtual TElXMLEncryptionProperties* get_EncryptionProperties();

		virtual void set_EncryptionProperties(TElXMLEncryptionProperties &Value);

		virtual void set_EncryptionProperties(TElXMLEncryptionProperties *Value);

		SB_DECLARE_PROPERTY(TElXMLEncryptionProperties*, get_EncryptionProperties, set_EncryptionProperties, TElXMLEncryptedType, EncryptionProperties);
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_DataType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DataType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DataType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DataType(const std::wstring &Value);

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
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElXMLEncryptedType, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		TElXMLEncryptedType(TElXMLEncryptedTypeHandle handle, TElOwnHandle ownHandle);

		TElXMLEncryptedType();

		virtual ~TElXMLEncryptedType();

};
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDTYPE */

#ifdef SB_USE_CLASS_TELXMLENCPROCESSOR
class TElXMLEncProcessor: public TElXMLProcessor
{
	private:
		SB_DISABLE_COPY(TElXMLEncProcessor)
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		TElXMLKeyInfoData* _Inst_KeyEncryptionKeyData;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELXMLENCRYPTEDDATA
		TElXMLEncryptedData* _Inst_EncryptedData;
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDDATA */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		virtual TElXMLKeyInfoData* get_KeyEncryptionKeyData();

		virtual void set_KeyEncryptionKeyData(TElXMLKeyInfoData &Value);

		virtual void set_KeyEncryptionKeyData(TElXMLKeyInfoData *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfoData*, get_KeyEncryptionKeyData, set_KeyEncryptionKeyData, TElXMLEncProcessor, KeyEncryptionKeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDDATA
		virtual TElXMLEncryptedData* get_EncryptedData();

		virtual void set_EncryptedData(TElXMLEncryptedData &Value);

		virtual void set_EncryptedData(TElXMLEncryptedData *Value);

		SB_DECLARE_PROPERTY(TElXMLEncryptedData*, get_EncryptedData, set_EncryptedData, TElXMLEncProcessor, EncryptedData);
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDDATA */

		TElXMLEncProcessor(TElXMLEncProcessorHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLEncProcessor(TComponent &AOwner);

		explicit TElXMLEncProcessor(TComponent *AOwner);

		virtual ~TElXMLEncProcessor();

};
#endif /* SB_USE_CLASS_TELXMLENCPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLENCRYPTOR
class TElXMLEncryptor: public TElXMLEncProcessor
{
	private:
		SB_DISABLE_COPY(TElXMLEncryptor)
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		TElXMLKeyInfoData* _Inst_KeyData;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		void Encrypt(const TElXMLDOMNode &Data);

		void Encrypt(const TElXMLDOMNode *Data);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		void Encrypt(const TElXMLDOMNodeList &Data);

		void Encrypt(const TElXMLDOMNodeList *Data);
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

		void Encrypt(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		TElXMLDOMElementHandle Save(const TElXMLDOMDocument &Document);

		TElXMLDOMElementHandle Save(const TElXMLDOMDocument *Document);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLDOMDocumentHandle SaveToDocument();
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		virtual TElXMLKeyInfoData* get_KeyData();

		virtual void set_KeyData(TElXMLKeyInfoData &Value);

		virtual void set_KeyData(TElXMLKeyInfoData *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfoData*, get_KeyData, set_KeyData, TElXMLEncryptor, KeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

		virtual bool get_EncryptKey();

		virtual void set_EncryptKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncryptKey, set_EncryptKey, TElXMLEncryptor, EncryptKey);

		virtual void get_KeyName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_KeyName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_KeyName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_KeyName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TElXMLEncryptedDataType get_EncryptedDataType();

		virtual void set_EncryptedDataType(TElXMLEncryptedDataType Value);

		SB_DECLARE_PROPERTY(TElXMLEncryptedDataType, get_EncryptedDataType, set_EncryptedDataType, TElXMLEncryptor, EncryptedDataType);

		virtual TElXMLEncryptionMethod get_EncryptionMethod();

		virtual void set_EncryptionMethod(TElXMLEncryptionMethod Value);

		SB_DECLARE_PROPERTY(TElXMLEncryptionMethod, get_EncryptionMethod, set_EncryptionMethod, TElXMLEncryptor, EncryptionMethod);

		virtual TElXMLKeyEncryptionType get_KeyEncryptionType();

		virtual void set_KeyEncryptionType(TElXMLKeyEncryptionType Value);

		SB_DECLARE_PROPERTY(TElXMLKeyEncryptionType, get_KeyEncryptionType, set_KeyEncryptionType, TElXMLEncryptor, KeyEncryptionType);

		virtual TElXMLKeyTransportMethod get_KeyTransportMethod();

		virtual void set_KeyTransportMethod(TElXMLKeyTransportMethod Value);

		SB_DECLARE_PROPERTY(TElXMLKeyTransportMethod, get_KeyTransportMethod, set_KeyTransportMethod, TElXMLEncryptor, KeyTransportMethod);

		virtual TElXMLKeyWrapMethod get_KeyWrapMethod();

		virtual void set_KeyWrapMethod(TElXMLKeyWrapMethod Value);

		SB_DECLARE_PROPERTY(TElXMLKeyWrapMethod, get_KeyWrapMethod, set_KeyWrapMethod, TElXMLEncryptor, KeyWrapMethod);

		virtual bool get_IncludeKeyEncryptionKey();

		virtual void set_IncludeKeyEncryptionKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeKeyEncryptionKey, set_IncludeKeyEncryptionKey, TElXMLEncryptor, IncludeKeyEncryptionKey);

		virtual void get_MimeType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_MimeType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_MimeType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_MimeType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_OnFormatElement(TSBXMLFormatElementEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFormatElement(TSBXMLFormatElementEvent pMethodValue, void * pDataValue);

		virtual void get_OnFormatText(TSBXMLFormatTextEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFormatText(TSBXMLFormatTextEvent pMethodValue, void * pDataValue);

		TElXMLEncryptor(TElXMLEncryptorHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLEncryptor(TComponent &AOwner);

		explicit TElXMLEncryptor(TComponent *AOwner);

		virtual ~TElXMLEncryptor();

};
#endif /* SB_USE_CLASS_TELXMLENCRYPTOR */

#ifdef SB_USE_CLASS_TELXMLDECRYPTOR
class TElXMLDecryptor: public TElXMLEncProcessor
{
	private:
		SB_DISABLE_COPY(TElXMLDecryptor)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_DecryptedNode;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		TElXMLDOMNodeList* _Inst_DecryptedNodeList;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		TElXMLKeyInfoData* _Inst_KeyData;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		int32_t Decrypt(const TElXMLDOMDocument &OwnerDocument);

		int32_t Decrypt(const TElXMLDOMDocument *OwnerDocument);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void Load(TElXMLDOMElement &Element);

		void Load(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		void Load(TElXMLDOMDocument &Document);

		void Load(TElXMLDOMDocument *Document);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_DecryptedNode();

		virtual void set_DecryptedNode(TElXMLDOMNode &Value);

		virtual void set_DecryptedNode(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_DecryptedNode, set_DecryptedNode, TElXMLDecryptor, DecryptedNode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		virtual TElXMLDOMNodeList* get_DecryptedNodeList();

		virtual void set_DecryptedNodeList(TElXMLDOMNodeList &Value);

		virtual void set_DecryptedNodeList(TElXMLDOMNodeList *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNodeList*, get_DecryptedNodeList, set_DecryptedNodeList, TElXMLDecryptor, DecryptedNodeList);
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

		virtual void get_DecryptedData(std::vector<uint8_t> &OutResult);

		virtual void set_DecryptedData(const std::vector<uint8_t> &Value);

		virtual TElXMLEncryptedDataType get_EncryptedDataType();

		SB_DECLARE_PROPERTY_GET(TElXMLEncryptedDataType, get_EncryptedDataType, TElXMLDecryptor, EncryptedDataType);

		virtual TElXMLEncryptionMethod get_EncryptionMethod();

		SB_DECLARE_PROPERTY_GET(TElXMLEncryptionMethod, get_EncryptionMethod, TElXMLDecryptor, EncryptionMethod);

		virtual bool get_EncryptKey();

		SB_DECLARE_PROPERTY_GET(bool, get_EncryptKey, TElXMLDecryptor, EncryptKey);

		virtual void get_KeyName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_KeyName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual TElXMLKeyEncryptionType get_KeyEncryptionType();

		SB_DECLARE_PROPERTY_GET(TElXMLKeyEncryptionType, get_KeyEncryptionType, TElXMLDecryptor, KeyEncryptionType);

		virtual TElXMLKeyTransportMethod get_KeyTransportMethod();

		SB_DECLARE_PROPERTY_GET(TElXMLKeyTransportMethod, get_KeyTransportMethod, TElXMLDecryptor, KeyTransportMethod);

		virtual TElXMLKeyWrapMethod get_KeyWrapMethod();

		SB_DECLARE_PROPERTY_GET(TElXMLKeyWrapMethod, get_KeyWrapMethod, TElXMLDecryptor, KeyWrapMethod);

		virtual void get_MimeType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_MimeType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		virtual TElXMLKeyInfoData* get_KeyData();

		virtual void set_KeyData(TElXMLKeyInfoData &Value);

		virtual void set_KeyData(TElXMLKeyInfoData *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfoData*, get_KeyData, set_KeyData, TElXMLDecryptor, KeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

		TElXMLDecryptor(TElXMLDecryptorHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLDecryptor(TComponent &AOwner);

		explicit TElXMLDecryptor(TComponent *AOwner);

		virtual ~TElXMLDecryptor();

};
#endif /* SB_USE_CLASS_TELXMLDECRYPTOR */

#ifdef SB_USE_CLASS_TELXMLCIPHERREFERENCE
class TElXMLCipherReference: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLCipherReference)
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		TElXMLTransformChain* _Inst_TransformChain;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

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

		virtual void get_CipherValue(std::vector<uint8_t> &OutResult);

		virtual void set_CipherValue(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		virtual TElXMLTransformChain* get_TransformChain();

		virtual void set_TransformChain(TElXMLTransformChain &Value);

		virtual void set_TransformChain(TElXMLTransformChain *Value);

		SB_DECLARE_PROPERTY(TElXMLTransformChain*, get_TransformChain, set_TransformChain, TElXMLCipherReference, TransformChain);
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLCipherReference(TElXMLCipherReferenceHandle handle, TElOwnHandle ownHandle);

		TElXMLCipherReference();

		virtual ~TElXMLCipherReference();

};
#endif /* SB_USE_CLASS_TELXMLCIPHERREFERENCE */

#ifdef SB_USE_CLASS_TELXMLCIPHERDATA
class TElXMLCipherData: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLCipherData)
#ifdef SB_USE_CLASS_TELXMLCIPHERREFERENCE
		TElXMLCipherReference* _Inst_CipherReference;
#endif /* SB_USE_CLASS_TELXMLCIPHERREFERENCE */

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

		virtual void get_CipherValue(std::vector<uint8_t> &OutResult);

		virtual void set_CipherValue(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELXMLCIPHERREFERENCE
		virtual TElXMLCipherReference* get_CipherReference();

		virtual void set_CipherReference(TElXMLCipherReference &Value);

		virtual void set_CipherReference(TElXMLCipherReference *Value);

		SB_DECLARE_PROPERTY(TElXMLCipherReference*, get_CipherReference, set_CipherReference, TElXMLCipherData, CipherReference);
#endif /* SB_USE_CLASS_TELXMLCIPHERREFERENCE */

		TElXMLCipherData(TElXMLCipherDataHandle handle, TElOwnHandle ownHandle);

		TElXMLCipherData();

		virtual ~TElXMLCipherData();

};
#endif /* SB_USE_CLASS_TELXMLCIPHERDATA */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE
class TElXMLEncryptionMethodType: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLEncryptionMethodType)
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
		virtual int32_t get_KeySize();

		virtual void set_KeySize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeySize, set_KeySize, TElXMLEncryptionMethodType, KeySize);

		virtual void get_OAEPparams(std::vector<uint8_t> &OutResult);

		virtual void set_OAEPparams(const std::vector<uint8_t> &Value);

		virtual void get_DigestMethod(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DigestMethod(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DigestMethod(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DigestMethod(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLEncryptionMethodType(TElXMLEncryptionMethodTypeHandle handle, TElOwnHandle ownHandle);

		TElXMLEncryptionMethodType();

};
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONMETHODTYPE */

#ifdef SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES
class TElXMLEncryptionProperties: public TElXMLProperties
{
	private:
		SB_DISABLE_COPY(TElXMLEncryptionProperties)
	public:
		TElXMLEncryptionProperties(TElXMLEncryptionPropertiesHandle handle, TElOwnHandle ownHandle);

		TElXMLEncryptionProperties();

};
#endif /* SB_USE_CLASS_TELXMLENCRYPTIONPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDDATA
class TElXMLEncryptedData: public TElXMLEncryptedType
{
	private:
		SB_DISABLE_COPY(TElXMLEncryptedData)
#ifdef SB_USE_CLASS_TELXMLENCRYPTEDKEY
		TElXMLEncryptedKey* _Inst_EncryptedKey;
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDKEY */

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

		virtual void get_EncryptionPrefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_EncryptionPrefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_EncryptionPrefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_EncryptionPrefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SignaturePrefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignaturePrefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignaturePrefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignaturePrefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLENCRYPTEDKEY
		virtual TElXMLEncryptedKey* get_EncryptedKey();

		virtual void set_EncryptedKey(TElXMLEncryptedKey &Value);

		virtual void set_EncryptedKey(TElXMLEncryptedKey *Value);

		SB_DECLARE_PROPERTY(TElXMLEncryptedKey*, get_EncryptedKey, set_EncryptedKey, TElXMLEncryptedData, EncryptedKey);
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDKEY */

		TElXMLEncryptedData(TElXMLEncryptedDataHandle handle, TElOwnHandle ownHandle);

		TElXMLEncryptedData();

		virtual ~TElXMLEncryptedData();

};
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDDATA */

#ifdef SB_USE_CLASS_TELXMLENCRYPTEDKEY
class TElXMLEncryptedKey: public TElXMLEncryptedType
{
	private:
		SB_DISABLE_COPY(TElXMLEncryptedKey)
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

		virtual void get_CarriedKeyName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CarriedKeyName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CarriedKeyName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_CarriedKeyName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Recipient(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Recipient(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Recipient(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Recipient(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLEncryptedKey(TElXMLEncryptedKeyHandle handle, TElOwnHandle ownHandle);

		TElXMLEncryptedKey();

};
#endif /* SB_USE_CLASS_TELXMLENCRYPTEDKEY */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
class TElXMLDecryptionExcept: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLDecryptionExcept)
	public:
		TElXMLDecryptionExceptHandle Clone();

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
		TElXMLDecryptionExcept(TElXMLDecryptionExceptHandle handle, TElOwnHandle ownHandle);

		TElXMLDecryptionExcept();

};
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

#ifdef SB_USE_CLASS_TELXMLCUSTOMDECRYPTIONTRANSFORM
class TElXMLCustomDecryptionTransform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElXMLCustomDecryptionTransform)
#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
		TElXMLDecryptionExcept* _Inst_Excepts;
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		TElXMLKeyInfoData* _Inst_KeyData;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
		int32_t Add(TElXMLDecryptionExcept &AExcept);

		int32_t Add(TElXMLDecryptionExcept *AExcept);
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

		int32_t Add(const sb_u16string &ExceptID, const sb_u16string &ExceptURI);
#ifdef SB_U16STRING_USED
		int32_t Add(const std::wstring &ExceptID, const std::wstring &ExceptURI);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
		void Insert(int32_t Index, TElXMLDecryptionExcept &AExcept);

		void Insert(int32_t Index, TElXMLDecryptionExcept *AExcept);
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

		void Delete(int32_t Index);

		virtual void Clear();

		static TClassHandle ClassType();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLCustomDecryptionTransform, Count);

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT
		virtual TElXMLDecryptionExcept* get_Excepts(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONEXCEPT */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		virtual TElXMLKeyInfoData* get_KeyData();

		virtual void set_KeyData(TElXMLKeyInfoData &Value);

		virtual void set_KeyData(TElXMLKeyInfoData *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfoData*, get_KeyData, set_KeyData, TElXMLCustomDecryptionTransform, KeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

		virtual void get_OnKeyData(TSBXMLDecryptKeyDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyData(TSBXMLDecryptKeyDataEvent pMethodValue, void * pDataValue);

		TElXMLCustomDecryptionTransform(TElXMLCustomDecryptionTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLCustomDecryptionTransform();

		virtual ~TElXMLCustomDecryptionTransform();

};
#endif /* SB_USE_CLASS_TELXMLCUSTOMDECRYPTIONTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLDECRYPTIONTRANSFORM
class TElXMLDecryptionTransform: public TElXMLCustomDecryptionTransform
{
	private:
		SB_DISABLE_COPY(TElXMLDecryptionTransform)
	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

		TElXMLDecryptionTransform(TElXMLDecryptionTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLDecryptionTransform();

};
#endif /* SB_USE_CLASS_TELXMLDECRYPTIONTRANSFORM */

#ifdef SB_USE_CLASS_TELXMLBINARYDECRYPTIONTRANSFORM
class TElXMLBinaryDecryptionTransform: public TElXMLCustomDecryptionTransform
{
	private:
		SB_DISABLE_COPY(TElXMLBinaryDecryptionTransform)
	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

		static TClassHandle ClassType();

		TElXMLBinaryDecryptionTransform(TElXMLBinaryDecryptionTransformHandle handle, TElOwnHandle ownHandle);

		TElXMLBinaryDecryptionTransform();

};
#endif /* SB_USE_CLASS_TELXMLBINARYDECRYPTIONTRANSFORM */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLENC */

