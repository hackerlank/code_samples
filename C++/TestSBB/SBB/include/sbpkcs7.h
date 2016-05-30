#ifndef __INC_SBPKCS7
#define __INC_SBPKCS7

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbasn1tree.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbrdn.h"
#include "sbpkcs7utils.h"
#include "sbstreams.h"
#include "sbalgorithmidentifier.h"
#include "sbcrl.h"
#include "sbcrlstorage.h"
#include "sbocspcommon.h"
#include "sbocspclient.h"
#include "sbocspstorage.h"
#include "sbcustomcertstorage.h"
#include "sbpem.h"
#include "sbencoding.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SBPKCS7_SB_OID_PKCS7_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x01"
#define SB_OID_PKCS7_SIGNED_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x02"
#define SB_OID_PKCS7_ENVELOPED_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x03"
#define SB_OID_PKCS7_SIGNED_AND_ENVELOPED_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x04"
#define SB_OID_PKCS7_DIGESTED_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x05"
#define SB_OID_PKCS7_ENCRYPTED_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x06"
#define SB_OID_PKCS7_AUTHENTICATED_DATA 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x01""\x02"
#define SB_OID_PKCS7_COMPRESSED_DATA 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x01""\t"
#define SB_OID_PKCS7_TIMESTAMPED_DATA 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x01""\x1F"
#define SB_OID_PKCS7_COMPRESSION_ZLIB 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x03""\b"

typedef TElClassHandle TElPKCS7RecipientHandle;

typedef TElClassHandle TElPKCS7ContentPartHandle;

typedef TElClassHandle TElPKCS7EncryptedContentHandle;

typedef TElClassHandle TElPKCS7MessageHandle;

typedef TElClassHandle TElPKCS7EnvelopedDataHandle;

typedef TElClassHandle TElPKCS7CompressedDataHandle;

typedef TElClassHandle TElPKCS7SignerHandle;

typedef TElClassHandle TElPKCS7SignedDataHandle;

typedef TElClassHandle TElPKCS7DigestedDataHandle;

typedef TElClassHandle TElPKCS7EncryptedDataHandle;

typedef TElClassHandle TElPKCS7SignedAndEnvelopedDataHandle;

typedef TElClassHandle TElPKCS7AuthenticatedDataHandle;

typedef TElClassHandle TElPKCS7TimestampAndCRLHandle;

typedef TElClassHandle TElPKCS7TimestampedDataHandle;

typedef uint8_t TSBPKCS7ContentTypeRaw;

typedef enum
{
	ctData = 0,
	ctSignedData = 1,
	ctEnvelopedData = 2,
	ctSignedAndEnvelopedData = 3,
	ctDigestedData = 4,
	ctEncryptedData = 5,
	ctAuthenticatedData = 6,
	ctCompressedData = 7,
	ctTimestampedData = 8,
	ctUnknown = 9
} TSBPKCS7ContentType;

typedef TElClassHandle IElPKCS7SignedDataCommonHandle;

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_get_Version(TElPKCS7RecipientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_set_Version(TElPKCS7RecipientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_get_Issuer(TElPKCS7RecipientHandle _Handle, TElPKCS7IssuerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_get_KeyEncryptionAlgorithm(TElPKCS7RecipientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_set_KeyEncryptionAlgorithm(TElPKCS7RecipientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_get_KeyEncryptionAlgorithmParams(TElPKCS7RecipientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_set_KeyEncryptionAlgorithmParams(TElPKCS7RecipientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_get_KeyEncryptionAlgorithmIdentifier(TElPKCS7RecipientHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_set_KeyEncryptionAlgorithmIdentifier(TElPKCS7RecipientHandle _Handle, TElAlgorithmIdentifierHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_get_EncryptedKey(TElPKCS7RecipientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_set_EncryptedKey(TElPKCS7RecipientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Recipient_Create(TElPKCS7RecipientHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELPKCS7CONTENTPART
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7ContentPart_Read(TElPKCS7ContentPartHandle _Handle, void * Buffer, int32_t Size, int32_t StartOffset, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7ContentPart_get_Size(TElPKCS7ContentPartHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7ContentPart_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7CONTENTPART */

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_AddContentPart(TElPKCS7EncryptedContentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_ClearContentParts(TElPKCS7EncryptedContentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_get_ContentType(TElPKCS7EncryptedContentHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_set_ContentType(TElPKCS7EncryptedContentHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_get_ContentEncryptionAlgorithm(TElPKCS7EncryptedContentHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_set_ContentEncryptionAlgorithm(TElPKCS7EncryptedContentHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_get_ContentEncryptionAlgorithmParams(TElPKCS7EncryptedContentHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_set_ContentEncryptionAlgorithmParams(TElPKCS7EncryptedContentHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_get_EncryptedContent(TElPKCS7EncryptedContentHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_set_EncryptedContent(TElPKCS7EncryptedContentHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_get_EncryptedContentParts(TElPKCS7EncryptedContentHandle _Handle, int32_t Index, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_get_EncryptedContentPartCount(TElPKCS7EncryptedContentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_get_DataSource(TElPKCS7EncryptedContentHandle _Handle, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_get_UseImplicitContentEncoding(TElPKCS7EncryptedContentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_set_UseImplicitContentEncoding(TElPKCS7EncryptedContentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedContent_Create(TElPKCS7EncryptedContentHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

#ifdef SB_USE_CLASS_TELPKCS7MESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_Reset(TElPKCS7MessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_LoadFromBuffer(TElPKCS7MessageHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_SaveToBuffer(TElPKCS7MessageHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_LoadFromStream(TElPKCS7MessageHandle _Handle, TStreamHandle Stream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_SaveToStream(TElPKCS7MessageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_ContentType(TElPKCS7MessageHandle _Handle, TSBPKCS7ContentTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_set_ContentType(TElPKCS7MessageHandle _Handle, TSBPKCS7ContentTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_Data(TElPKCS7MessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_set_Data(TElPKCS7MessageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_EnvelopedData(TElPKCS7MessageHandle _Handle, TElPKCS7EnvelopedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_CompressedData(TElPKCS7MessageHandle _Handle, TElPKCS7CompressedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_SignedData(TElPKCS7MessageHandle _Handle, TElPKCS7SignedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_DigestedData(TElPKCS7MessageHandle _Handle, TElPKCS7DigestedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_EncryptedData(TElPKCS7MessageHandle _Handle, TElPKCS7EncryptedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_SignedAndEnvelopedData(TElPKCS7MessageHandle _Handle, TElPKCS7SignedAndEnvelopedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_AuthenticatedData(TElPKCS7MessageHandle _Handle, TElPKCS7AuthenticatedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_TimestampedData(TElPKCS7MessageHandle _Handle, TElPKCS7TimestampedDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_UseImplicitContent(TElPKCS7MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_set_UseImplicitContent(TElPKCS7MessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_UseUndefSize(TElPKCS7MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_set_UseUndefSize(TElPKCS7MessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_NoOuterContentInfo(TElPKCS7MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_set_NoOuterContentInfo(TElPKCS7MessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_AllowUnknownContentTypes(TElPKCS7MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_set_AllowUnknownContentTypes(TElPKCS7MessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_get_CustomContentType(TElPKCS7MessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_set_CustomContentType(TElPKCS7MessageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Message_Create(TElPKCS7MessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7MESSAGE */

#ifdef SB_USE_CLASS_TELPKCS7ENVELOPEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_AddRecipient(TElPKCS7EnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_RemoveRecipient(TElPKCS7EnvelopedDataHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_SaveToBuffer(TElPKCS7EnvelopedDataHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_Version(TElPKCS7EnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_set_Version(TElPKCS7EnvelopedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_Recipients(TElPKCS7EnvelopedDataHandle _Handle, int32_t Index, TElPKCS7RecipientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_RecipientCount(TElPKCS7EnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_EncryptedContent(TElPKCS7EnvelopedDataHandle _Handle, TElPKCS7EncryptedContentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_set_EncryptedContent(TElPKCS7EnvelopedDataHandle _Handle, TElPKCS7EncryptedContentHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_ContentEncryptionAlgorithm(TElPKCS7EnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_set_ContentEncryptionAlgorithm(TElPKCS7EnvelopedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_CMSFormat(TElPKCS7EnvelopedDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_set_CMSFormat(TElPKCS7EnvelopedDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_OriginatorCertificates(TElPKCS7EnvelopedDataHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_OriginatorCRLs(TElPKCS7EnvelopedDataHandle _Handle, TElMemoryCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_get_UnprotectedAttributes(TElPKCS7EnvelopedDataHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EnvelopedData_Create(TElPKCS7EnvelopedDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7ENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7COMPRESSEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_SaveToBuffer(TElPKCS7CompressedDataHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_get_Version(TElPKCS7CompressedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_set_Version(TElPKCS7CompressedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_get_ContentType(TElPKCS7CompressedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_set_ContentType(TElPKCS7CompressedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_get_CompressedContent(TElPKCS7CompressedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_set_CompressedContent(TElPKCS7CompressedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_get_CompressedContentParts(TElPKCS7CompressedDataHandle _Handle, int32_t Index, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_get_CompressedContentPartCount(TElPKCS7CompressedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_get_FragmentSize(TElPKCS7CompressedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_set_FragmentSize(TElPKCS7CompressedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_get_DataSource(TElPKCS7CompressedDataHandle _Handle, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7CompressedData_Create(TElPKCS7CompressedDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7COMPRESSEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_RecalculateAuthenticatedAttributes(TElPKCS7SignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_RecalculateAuthenticatedAttributes_1(TElPKCS7SignerHandle _Handle, int8_t Reorder);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_Recalculate(TElPKCS7SignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_Reset(TElPKCS7SignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_Assign(TElPKCS7SignerHandle _Handle, TElPKCS7SignerHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_Version(TElPKCS7SignerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_set_Version(TElPKCS7SignerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_Issuer(TElPKCS7SignerHandle _Handle, TElPKCS7IssuerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_DigestAlgorithm(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_set_DigestAlgorithm(TElPKCS7SignerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_DigestAlgorithmParams(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_set_DigestAlgorithmParams(TElPKCS7SignerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_DigestEncryptionAlgorithm(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_set_DigestEncryptionAlgorithm(TElPKCS7SignerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_DigestEncryptionAlgorithmParams(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_set_DigestEncryptionAlgorithmParams(TElPKCS7SignerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_AuthenticatedAttributes(TElPKCS7SignerHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_UnauthenticatedAttributes(TElPKCS7SignerHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_EncryptedDigest(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_set_EncryptedDigest(TElPKCS7SignerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_AuthenticatedAttributesPlain(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_Content(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_EncodedValue(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_get_ArchivalEncodedValue(TElPKCS7SignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Signer_Create(TElPKCS7SignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_AddContentPart(TElPKCS7SignedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_ClearContentParts(TElPKCS7SignedDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_AddSigner(TElPKCS7SignedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_RemoveSigner(TElPKCS7SignedDataHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_SaveToBuffer(TElPKCS7SignedDataHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_SaveToStream(TElPKCS7SignedDataHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_PreSerialize(TElPKCS7SignedDataHandle _Handle, int8_t SerializeContent, int8_t SerializeCertsAndCrls);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_Version(TElPKCS7SignedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_set_Version(TElPKCS7SignedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_Signers(TElPKCS7SignedDataHandle _Handle, int32_t Index, TElPKCS7SignerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_ContentParts(TElPKCS7SignedDataHandle _Handle, int32_t Index, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_SignerCount(TElPKCS7SignedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_Certificates(TElPKCS7SignedDataHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_CRLs(TElPKCS7SignedDataHandle _Handle, TElMemoryCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_OCSPs(TElPKCS7SignedDataHandle _Handle, TElOCSPResponseStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_Content(TElPKCS7SignedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_set_Content(TElPKCS7SignedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_ContentType(TElPKCS7SignedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_set_ContentType(TElPKCS7SignedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_ContentPartCount(TElPKCS7SignedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_DataSource(TElPKCS7SignedDataHandle _Handle, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_EncodedCertificates(TElPKCS7SignedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_EncodedCRLs(TElPKCS7SignedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_EnvelopedContentPrefix(TElPKCS7SignedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_EnvelopedContentPostfix(TElPKCS7SignedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_IsMultipart(TElPKCS7SignedDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_RawMultipartContent(TElPKCS7SignedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_PreserveCachedContent(TElPKCS7SignedDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_set_PreserveCachedContent(TElPKCS7SignedDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_get_PreserveCachedElements(TElPKCS7SignedDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_set_PreserveCachedElements(TElPKCS7SignedDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedData_Create(TElPKCS7SignedDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7DIGESTEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_get_DigestAlgorithm(TElPKCS7DigestedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_set_DigestAlgorithm(TElPKCS7DigestedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_get_DigestAlgorithmParams(TElPKCS7DigestedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_set_DigestAlgorithmParams(TElPKCS7DigestedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_get_Content(TElPKCS7DigestedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_set_Content(TElPKCS7DigestedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_get_Digest(TElPKCS7DigestedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_set_Digest(TElPKCS7DigestedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_get_Version(TElPKCS7DigestedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_set_Version(TElPKCS7DigestedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7DigestedData_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7DIGESTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedData_SaveToBuffer(TElPKCS7EncryptedDataHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedData_get_Version(TElPKCS7EncryptedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedData_set_Version(TElPKCS7EncryptedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedData_get_EncryptedContent(TElPKCS7EncryptedDataHandle _Handle, TElPKCS7EncryptedContentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7EncryptedData_Create(TElPKCS7EncryptedDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_GetRecipient(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t Index, TElPKCS7RecipientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_GetSigner(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t Index, TElPKCS7SignerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_AddRecipient(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_AddSigner(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_RemoveRecipient(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_RemoveSigner(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_PreSerialize(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int8_t SerializeContent, int8_t SerializeCertsAndCrls);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_Version(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_set_Version(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_ContentType(TElPKCS7SignedAndEnvelopedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_set_ContentType(TElPKCS7SignedAndEnvelopedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_Recipients(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t Index, TElPKCS7RecipientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_Signers(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t Index, TElPKCS7SignerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_RecipientCount(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_EncryptedContent(TElPKCS7SignedAndEnvelopedDataHandle _Handle, TElPKCS7EncryptedContentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_Certificates(TElPKCS7SignedAndEnvelopedDataHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_CRLs(TElPKCS7SignedAndEnvelopedDataHandle _Handle, TElMemoryCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_OCSPs(TElPKCS7SignedAndEnvelopedDataHandle _Handle, TElOCSPResponseStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_EncodedCertificates(TElPKCS7SignedAndEnvelopedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_EncodedCRLs(TElPKCS7SignedAndEnvelopedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_EnvelopedContentPrefix(TElPKCS7SignedAndEnvelopedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_EnvelopedContentPostfix(TElPKCS7SignedAndEnvelopedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_SignerCount(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_get_PreserveCachedElements(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_set_PreserveCachedElements(TElPKCS7SignedAndEnvelopedDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7SignedAndEnvelopedData_Create(TElPKCS7SignedAndEnvelopedDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_AddRecipient(TElPKCS7AuthenticatedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_RemoveRecipient(TElPKCS7AuthenticatedDataHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_RecalculateAuthenticatedAttributes(TElPKCS7AuthenticatedDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_Version(TElPKCS7AuthenticatedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_set_Version(TElPKCS7AuthenticatedDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_OriginatorCerts(TElPKCS7AuthenticatedDataHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_Recipients(TElPKCS7AuthenticatedDataHandle _Handle, int32_t Index, TElPKCS7RecipientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_ContentParts(TElPKCS7AuthenticatedDataHandle _Handle, int32_t Index, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_RecipientCount(TElPKCS7AuthenticatedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_MacAlgorithm(TElPKCS7AuthenticatedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_set_MacAlgorithm(TElPKCS7AuthenticatedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_DigestAlgorithm(TElPKCS7AuthenticatedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_set_DigestAlgorithm(TElPKCS7AuthenticatedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_ContentType(TElPKCS7AuthenticatedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_set_ContentType(TElPKCS7AuthenticatedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_Content(TElPKCS7AuthenticatedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_set_Content(TElPKCS7AuthenticatedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_AuthenticatedAttributes(TElPKCS7AuthenticatedDataHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_UnauthenticatedAttributes(TElPKCS7AuthenticatedDataHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_Mac(TElPKCS7AuthenticatedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_set_Mac(TElPKCS7AuthenticatedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_AuthenticatedAttributesPlain(TElPKCS7AuthenticatedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_ContentPartCount(TElPKCS7AuthenticatedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_get_DataSource(TElPKCS7AuthenticatedDataHandle _Handle, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7AuthenticatedData_Create(TElPKCS7AuthenticatedDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_SetEncodedTimestamp(TElPKCS7TimestampAndCRLHandle _Handle, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_SetEncodedCRL(TElPKCS7TimestampAndCRLHandle _Handle, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_SetEncodedValue(TElPKCS7TimestampAndCRLHandle _Handle, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_get_EncodedTimestamp(TElPKCS7TimestampAndCRLHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_set_EncodedTimestamp(TElPKCS7TimestampAndCRLHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_get_EncodedCRL(TElPKCS7TimestampAndCRLHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_set_EncodedCRL(TElPKCS7TimestampAndCRLHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_get_EncodedValue(TElPKCS7TimestampAndCRLHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_set_EncodedValue(TElPKCS7TimestampAndCRLHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampAndCRL_Create(TElPKCS7TimestampAndCRLHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_AddTimestamp(TElPKCS7TimestampedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_RemoveTimestamp(TElPKCS7TimestampedDataHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_ClearTimestamps(TElPKCS7TimestampedDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_WriteMetadata(TElPKCS7TimestampedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_WriteTimestampAndCRL(TElPKCS7TimestampedDataHandle _Handle, TElPKCS7TimestampAndCRLHandle Ts, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_DataURI(TElPKCS7TimestampedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_set_DataURI(TElPKCS7TimestampedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_HashProtected(TElPKCS7TimestampedDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_set_HashProtected(TElPKCS7TimestampedDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_FileName(TElPKCS7TimestampedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_set_FileName(TElPKCS7TimestampedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_MediaType(TElPKCS7TimestampedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_set_MediaType(TElPKCS7TimestampedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_MetaDataAvailable(TElPKCS7TimestampedDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_set_MetaDataAvailable(TElPKCS7TimestampedDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_Timestamps(TElPKCS7TimestampedDataHandle _Handle, int32_t Index, TElPKCS7TimestampAndCRLHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_TimestampCount(TElPKCS7TimestampedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_Content(TElPKCS7TimestampedDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_set_Content(TElPKCS7TimestampedDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_ContentParts(TElPKCS7TimestampedDataHandle _Handle, int32_t Index, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_ContentPartCount(TElPKCS7TimestampedDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_get_DataSource(TElPKCS7TimestampedDataHandle _Handle, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7TimestampedData_Create(TElPKCS7TimestampedDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS7Recipient;
class TElPKCS7ContentPart;
class TElPKCS7EncryptedContent;
class TElPKCS7Message;
class TElPKCS7EnvelopedData;
class TElPKCS7CompressedData;
class TElPKCS7Signer;
class TElPKCS7SignedData;
class TElPKCS7DigestedData;
class TElPKCS7EncryptedData;
class TElPKCS7SignedAndEnvelopedData;
class TElPKCS7AuthenticatedData;
class TElPKCS7TimestampAndCRL;
class TElPKCS7TimestampedData;

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
class TElPKCS7Recipient: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7Recipient)
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		TElPKCS7Issuer* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_KeyEncryptionAlgorithmIdentifier;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void initInstances();

	public:
		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7Recipient, Version);

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		virtual TElPKCS7Issuer* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Issuer*, get_Issuer, TElPKCS7Recipient, Issuer);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

		virtual void get_KeyEncryptionAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_KeyEncryptionAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_KeyEncryptionAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_KeyEncryptionAlgorithmParams(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_KeyEncryptionAlgorithmIdentifier();

		virtual void set_KeyEncryptionAlgorithmIdentifier(TElAlgorithmIdentifier &Value);

		virtual void set_KeyEncryptionAlgorithmIdentifier(TElAlgorithmIdentifier *Value);

		SB_DECLARE_PROPERTY(TElAlgorithmIdentifier*, get_KeyEncryptionAlgorithmIdentifier, set_KeyEncryptionAlgorithmIdentifier, TElPKCS7Recipient, KeyEncryptionAlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_EncryptedKey(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedKey(const std::vector<uint8_t> &Value);

		TElPKCS7Recipient(TElPKCS7RecipientHandle handle, TElOwnHandle ownHandle);

		TElPKCS7Recipient();

		virtual ~TElPKCS7Recipient();

};
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELPKCS7CONTENTPART
class TElPKCS7ContentPart: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7ContentPart)
	public:
		int32_t Read(void * Buffer, int32_t Size, int32_t StartOffset);

		virtual int32_t get_Size();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Size, TElPKCS7ContentPart, Size);

		TElPKCS7ContentPart(TElPKCS7ContentPartHandle handle, TElOwnHandle ownHandle);

		TElPKCS7ContentPart();

};
#endif /* SB_USE_CLASS_TELPKCS7CONTENTPART */

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
class TElPKCS7EncryptedContent: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7EncryptedContent)
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_EncryptedContentParts;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_DataSource;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		void initInstances();

	public:
		int32_t AddContentPart();

		void ClearContentParts();

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual void get_ContentEncryptionAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_ContentEncryptionAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_ContentEncryptionAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_ContentEncryptionAlgorithmParams(const std::vector<uint8_t> &Value);

		virtual void get_EncryptedContent(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedContent(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_EncryptedContentParts(int32_t Index);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		virtual int32_t get_EncryptedContentPartCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_EncryptedContentPartCount, TElPKCS7EncryptedContent, EncryptedContentPartCount);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_DataSource();

		SB_DECLARE_PROPERTY_GET(TElASN1DataSource*, get_DataSource, TElPKCS7EncryptedContent, DataSource);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		virtual bool get_UseImplicitContentEncoding();

		virtual void set_UseImplicitContentEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseImplicitContentEncoding, set_UseImplicitContentEncoding, TElPKCS7EncryptedContent, UseImplicitContentEncoding);

		TElPKCS7EncryptedContent(TElPKCS7EncryptedContentHandle handle, TElOwnHandle ownHandle);

		TElPKCS7EncryptedContent();

		virtual ~TElPKCS7EncryptedContent();

};
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

#ifdef SB_USE_CLASS_TELPKCS7MESSAGE
class TElPKCS7Message: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7Message)
#ifdef SB_USE_CLASS_TELPKCS7ENVELOPEDDATA
		TElPKCS7EnvelopedData* _Inst_EnvelopedData;
#endif /* SB_USE_CLASS_TELPKCS7ENVELOPEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7COMPRESSEDDATA
		TElPKCS7CompressedData* _Inst_CompressedData;
#endif /* SB_USE_CLASS_TELPKCS7COMPRESSEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
		TElPKCS7SignedData* _Inst_SignedData;
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7DIGESTEDDATA
		TElPKCS7DigestedData* _Inst_DigestedData;
#endif /* SB_USE_CLASS_TELPKCS7DIGESTEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA
		TElPKCS7EncryptedData* _Inst_EncryptedData;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
		TElPKCS7SignedAndEnvelopedData* _Inst_SignedAndEnvelopedData;
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA
		TElPKCS7AuthenticatedData* _Inst_AuthenticatedData;
#endif /* SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA
		TElPKCS7TimestampedData* _Inst_TimestampedData;
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA */

		void initInstances();

	public:
		void Reset();

		int32_t LoadFromBuffer(void * Buffer, int32_t Size);

		bool SaveToBuffer(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStream(TStream &Stream, int32_t Count);

		int32_t LoadFromStream(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual TSBPKCS7ContentType get_ContentType();

		virtual void set_ContentType(TSBPKCS7ContentType Value);

		SB_DECLARE_PROPERTY(TSBPKCS7ContentType, get_ContentType, set_ContentType, TElPKCS7Message, ContentType);

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual void set_Data(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELPKCS7ENVELOPEDDATA
		virtual TElPKCS7EnvelopedData* get_EnvelopedData();

		SB_DECLARE_PROPERTY_GET(TElPKCS7EnvelopedData*, get_EnvelopedData, TElPKCS7Message, EnvelopedData);
#endif /* SB_USE_CLASS_TELPKCS7ENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7COMPRESSEDDATA
		virtual TElPKCS7CompressedData* get_CompressedData();

		SB_DECLARE_PROPERTY_GET(TElPKCS7CompressedData*, get_CompressedData, TElPKCS7Message, CompressedData);
#endif /* SB_USE_CLASS_TELPKCS7COMPRESSEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
		virtual TElPKCS7SignedData* get_SignedData();

		SB_DECLARE_PROPERTY_GET(TElPKCS7SignedData*, get_SignedData, TElPKCS7Message, SignedData);
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7DIGESTEDDATA
		virtual TElPKCS7DigestedData* get_DigestedData();

		SB_DECLARE_PROPERTY_GET(TElPKCS7DigestedData*, get_DigestedData, TElPKCS7Message, DigestedData);
#endif /* SB_USE_CLASS_TELPKCS7DIGESTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA
		virtual TElPKCS7EncryptedData* get_EncryptedData();

		SB_DECLARE_PROPERTY_GET(TElPKCS7EncryptedData*, get_EncryptedData, TElPKCS7Message, EncryptedData);
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
		virtual TElPKCS7SignedAndEnvelopedData* get_SignedAndEnvelopedData();

		SB_DECLARE_PROPERTY_GET(TElPKCS7SignedAndEnvelopedData*, get_SignedAndEnvelopedData, TElPKCS7Message, SignedAndEnvelopedData);
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA
		virtual TElPKCS7AuthenticatedData* get_AuthenticatedData();

		SB_DECLARE_PROPERTY_GET(TElPKCS7AuthenticatedData*, get_AuthenticatedData, TElPKCS7Message, AuthenticatedData);
#endif /* SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA
		virtual TElPKCS7TimestampedData* get_TimestampedData();

		SB_DECLARE_PROPERTY_GET(TElPKCS7TimestampedData*, get_TimestampedData, TElPKCS7Message, TimestampedData);
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA */

		virtual bool get_UseImplicitContent();

		virtual void set_UseImplicitContent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseImplicitContent, set_UseImplicitContent, TElPKCS7Message, UseImplicitContent);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElPKCS7Message, UseUndefSize);

		virtual bool get_NoOuterContentInfo();

		virtual void set_NoOuterContentInfo(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoOuterContentInfo, set_NoOuterContentInfo, TElPKCS7Message, NoOuterContentInfo);

		virtual bool get_AllowUnknownContentTypes();

		virtual void set_AllowUnknownContentTypes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowUnknownContentTypes, set_AllowUnknownContentTypes, TElPKCS7Message, AllowUnknownContentTypes);

		virtual void get_CustomContentType(std::vector<uint8_t> &OutResult);

		virtual void set_CustomContentType(const std::vector<uint8_t> &Value);

		TElPKCS7Message(TElPKCS7MessageHandle handle, TElOwnHandle ownHandle);

		TElPKCS7Message();

		virtual ~TElPKCS7Message();

};
#endif /* SB_USE_CLASS_TELPKCS7MESSAGE */

#ifdef SB_USE_CLASS_TELPKCS7ENVELOPEDDATA
class TElPKCS7EnvelopedData: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7EnvelopedData)
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
		TElPKCS7Recipient* _Inst_Recipients;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
		TElPKCS7EncryptedContent* _Inst_EncryptedContent;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_OriginatorCertificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		TElMemoryCRLStorage* _Inst_OriginatorCRLs;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_UnprotectedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		void initInstances();

	public:
		int32_t AddRecipient();

		bool RemoveRecipient(int32_t Index);

		bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7EnvelopedData, Version);

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
		virtual TElPKCS7Recipient* get_Recipients(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

		virtual int32_t get_RecipientCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RecipientCount, TElPKCS7EnvelopedData, RecipientCount);

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
		virtual TElPKCS7EncryptedContent* get_EncryptedContent();

		virtual void set_EncryptedContent(TElPKCS7EncryptedContent &Value);

		virtual void set_EncryptedContent(TElPKCS7EncryptedContent *Value);

		SB_DECLARE_PROPERTY(TElPKCS7EncryptedContent*, get_EncryptedContent, set_EncryptedContent, TElPKCS7EnvelopedData, EncryptedContent);
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

		virtual int32_t get_ContentEncryptionAlgorithm();

		virtual void set_ContentEncryptionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ContentEncryptionAlgorithm, set_ContentEncryptionAlgorithm, TElPKCS7EnvelopedData, ContentEncryptionAlgorithm);

		virtual bool get_CMSFormat();

		virtual void set_CMSFormat(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CMSFormat, set_CMSFormat, TElPKCS7EnvelopedData, CMSFormat);

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_OriginatorCertificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_OriginatorCertificates, TElPKCS7EnvelopedData, OriginatorCertificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		virtual TElMemoryCRLStorage* get_OriginatorCRLs();

		SB_DECLARE_PROPERTY_GET(TElMemoryCRLStorage*, get_OriginatorCRLs, TElPKCS7EnvelopedData, OriginatorCRLs);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_UnprotectedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_UnprotectedAttributes, TElPKCS7EnvelopedData, UnprotectedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		TElPKCS7EnvelopedData(TElPKCS7EnvelopedDataHandle handle, TElOwnHandle ownHandle);

		TElPKCS7EnvelopedData();

		virtual ~TElPKCS7EnvelopedData();

};
#endif /* SB_USE_CLASS_TELPKCS7ENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7COMPRESSEDDATA
class TElPKCS7CompressedData: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7CompressedData)
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_CompressedContentParts;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_DataSource;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		void initInstances();

	public:
		bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7CompressedData, Version);

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual void get_CompressedContent(std::vector<uint8_t> &OutResult);

		virtual void set_CompressedContent(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_CompressedContentParts(int32_t Index);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		virtual int32_t get_CompressedContentPartCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CompressedContentPartCount, TElPKCS7CompressedData, CompressedContentPartCount);

		virtual int32_t get_FragmentSize();

		virtual void set_FragmentSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FragmentSize, set_FragmentSize, TElPKCS7CompressedData, FragmentSize);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_DataSource();

		SB_DECLARE_PROPERTY_GET(TElASN1DataSource*, get_DataSource, TElPKCS7CompressedData, DataSource);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		TElPKCS7CompressedData(TElPKCS7CompressedDataHandle handle, TElOwnHandle ownHandle);

		TElPKCS7CompressedData();

		virtual ~TElPKCS7CompressedData();

};
#endif /* SB_USE_CLASS_TELPKCS7COMPRESSEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
class TElPKCS7Signer: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7Signer)
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		TElPKCS7Issuer* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_AuthenticatedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_UnauthenticatedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		void initInstances();

	public:
		void RecalculateAuthenticatedAttributes();

		void RecalculateAuthenticatedAttributes(bool Reorder);

		void Recalculate();

		void Reset();

		void Assign(TElPKCS7Signer &Source);

		void Assign(TElPKCS7Signer *Source);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7Signer, Version);

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		virtual TElPKCS7Issuer* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Issuer*, get_Issuer, TElPKCS7Signer, Issuer);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

		virtual void get_DigestAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_DigestAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_DigestAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_DigestAlgorithmParams(const std::vector<uint8_t> &Value);

		virtual void get_DigestEncryptionAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_DigestEncryptionAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_DigestEncryptionAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_DigestEncryptionAlgorithmParams(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_AuthenticatedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_AuthenticatedAttributes, TElPKCS7Signer, AuthenticatedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_UnauthenticatedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_UnauthenticatedAttributes, TElPKCS7Signer, UnauthenticatedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual void get_EncryptedDigest(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedDigest(const std::vector<uint8_t> &Value);

		virtual void get_AuthenticatedAttributesPlain(std::vector<uint8_t> &OutResult);

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual void get_EncodedValue(std::vector<uint8_t> &OutResult);

		virtual void get_ArchivalEncodedValue(std::vector<uint8_t> &OutResult);

		TElPKCS7Signer(TElPKCS7SignerHandle handle, TElOwnHandle ownHandle);

		TElPKCS7Signer();

		virtual ~TElPKCS7Signer();

};
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
class TElPKCS7SignedData: public TInterfacedPersistent
{
	private:
		SB_DISABLE_COPY(TElPKCS7SignedData)
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
		TElPKCS7Signer* _Inst_Signers;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_ContentParts;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		TElMemoryCRLStorage* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
		TElOCSPResponseStorage* _Inst_OCSPs;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_DataSource;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		void initInstances();

	public:
		int32_t AddContentPart();

		void ClearContentParts();

		int32_t AddSigner();

		bool RemoveSigner(int32_t Index);

		bool SaveToBuffer(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void PreSerialize(bool SerializeContent, bool SerializeCertsAndCrls);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7SignedData, Version);

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
		virtual TElPKCS7Signer* get_Signers(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_ContentParts(int32_t Index);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		virtual int32_t get_SignerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignerCount, TElPKCS7SignedData, SignerCount);

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_Certificates, TElPKCS7SignedData, Certificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		virtual TElMemoryCRLStorage* get_CRLs();

		SB_DECLARE_PROPERTY_GET(TElMemoryCRLStorage*, get_CRLs, TElPKCS7SignedData, CRLs);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
		virtual TElOCSPResponseStorage* get_OCSPs();

		SB_DECLARE_PROPERTY_GET(TElOCSPResponseStorage*, get_OCSPs, TElPKCS7SignedData, OCSPs);
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual void set_Content(const std::vector<uint8_t> &Value);

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual int32_t get_ContentPartCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ContentPartCount, TElPKCS7SignedData, ContentPartCount);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_DataSource();

		SB_DECLARE_PROPERTY_GET(TElASN1DataSource*, get_DataSource, TElPKCS7SignedData, DataSource);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		virtual void get_EncodedCertificates(std::vector<uint8_t> &OutResult);

		virtual void get_EncodedCRLs(std::vector<uint8_t> &OutResult);

		virtual void get_EnvelopedContentPrefix(std::vector<uint8_t> &OutResult);

		virtual void get_EnvelopedContentPostfix(std::vector<uint8_t> &OutResult);

		virtual bool get_IsMultipart();

		SB_DECLARE_PROPERTY_GET(bool, get_IsMultipart, TElPKCS7SignedData, IsMultipart);

		virtual void get_RawMultipartContent(std::vector<uint8_t> &OutResult);

		virtual bool get_PreserveCachedContent();

		virtual void set_PreserveCachedContent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveCachedContent, set_PreserveCachedContent, TElPKCS7SignedData, PreserveCachedContent);

		virtual bool get_PreserveCachedElements();

		virtual void set_PreserveCachedElements(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveCachedElements, set_PreserveCachedElements, TElPKCS7SignedData, PreserveCachedElements);

		TElPKCS7SignedData(TElPKCS7SignedDataHandle handle, TElOwnHandle ownHandle);

		TElPKCS7SignedData();

		virtual ~TElPKCS7SignedData();

};
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7DIGESTEDDATA
class TElPKCS7DigestedData: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7DigestedData)
	public:
		virtual void get_DigestAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_DigestAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_DigestAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_DigestAlgorithmParams(const std::vector<uint8_t> &Value);

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual void set_Content(const std::vector<uint8_t> &Value);

		virtual void get_Digest(std::vector<uint8_t> &OutResult);

		virtual void set_Digest(const std::vector<uint8_t> &Value);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7DigestedData, Version);

		TElPKCS7DigestedData(TElPKCS7DigestedDataHandle handle, TElOwnHandle ownHandle);

		TElPKCS7DigestedData();

};
#endif /* SB_USE_CLASS_TELPKCS7DIGESTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA
class TElPKCS7EncryptedData: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7EncryptedData)
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
		TElPKCS7EncryptedContent* _Inst_EncryptedContent;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

		void initInstances();

	public:
		bool SaveToBuffer(void * Buffer, int32_t &Size);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7EncryptedData, Version);

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
		virtual TElPKCS7EncryptedContent* get_EncryptedContent();

		SB_DECLARE_PROPERTY_GET(TElPKCS7EncryptedContent*, get_EncryptedContent, TElPKCS7EncryptedData, EncryptedContent);
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

		TElPKCS7EncryptedData(TElPKCS7EncryptedDataHandle handle, TElOwnHandle ownHandle);

		TElPKCS7EncryptedData();

		virtual ~TElPKCS7EncryptedData();

};
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
class TElPKCS7SignedAndEnvelopedData: public TInterfacedPersistent
{
	private:
		SB_DISABLE_COPY(TElPKCS7SignedAndEnvelopedData)
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
		TElPKCS7Recipient* _Inst_Recipients;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
		TElPKCS7Signer* _Inst_Signers;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
		TElPKCS7EncryptedContent* _Inst_EncryptedContent;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		TElMemoryCRLStorage* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
		TElOCSPResponseStorage* _Inst_OCSPs;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
		TElPKCS7RecipientHandle GetRecipient(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
		TElPKCS7SignerHandle GetSigner(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

		int32_t AddRecipient();

		int32_t AddSigner();

		bool RemoveRecipient(int32_t Index);

		bool RemoveSigner(int32_t Index);

		void PreSerialize(bool SerializeContent, bool SerializeCertsAndCrls);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7SignedAndEnvelopedData, Version);

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
		virtual TElPKCS7Recipient* get_Recipients(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
		virtual TElPKCS7Signer* get_Signers(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

		virtual int32_t get_RecipientCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RecipientCount, TElPKCS7SignedAndEnvelopedData, RecipientCount);

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
		virtual TElPKCS7EncryptedContent* get_EncryptedContent();

		SB_DECLARE_PROPERTY_GET(TElPKCS7EncryptedContent*, get_EncryptedContent, TElPKCS7SignedAndEnvelopedData, EncryptedContent);
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_Certificates, TElPKCS7SignedAndEnvelopedData, Certificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		virtual TElMemoryCRLStorage* get_CRLs();

		SB_DECLARE_PROPERTY_GET(TElMemoryCRLStorage*, get_CRLs, TElPKCS7SignedAndEnvelopedData, CRLs);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
		virtual TElOCSPResponseStorage* get_OCSPs();

		SB_DECLARE_PROPERTY_GET(TElOCSPResponseStorage*, get_OCSPs, TElPKCS7SignedAndEnvelopedData, OCSPs);
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

		virtual void get_EncodedCertificates(std::vector<uint8_t> &OutResult);

		virtual void get_EncodedCRLs(std::vector<uint8_t> &OutResult);

		virtual void get_EnvelopedContentPrefix(std::vector<uint8_t> &OutResult);

		virtual void get_EnvelopedContentPostfix(std::vector<uint8_t> &OutResult);

		virtual int32_t get_SignerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignerCount, TElPKCS7SignedAndEnvelopedData, SignerCount);

		virtual bool get_PreserveCachedElements();

		virtual void set_PreserveCachedElements(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveCachedElements, set_PreserveCachedElements, TElPKCS7SignedAndEnvelopedData, PreserveCachedElements);

		TElPKCS7SignedAndEnvelopedData(TElPKCS7SignedAndEnvelopedDataHandle handle, TElOwnHandle ownHandle);

		TElPKCS7SignedAndEnvelopedData();

		virtual ~TElPKCS7SignedAndEnvelopedData();

};
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA
class TElPKCS7AuthenticatedData: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7AuthenticatedData)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_OriginatorCerts;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
		TElPKCS7Recipient* _Inst_Recipients;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_ContentParts;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_AuthenticatedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_UnauthenticatedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_DataSource;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		void initInstances();

	public:
		int32_t AddRecipient();

		bool RemoveRecipient(int32_t Index);

		void RecalculateAuthenticatedAttributes();

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPKCS7AuthenticatedData, Version);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_OriginatorCerts();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_OriginatorCerts, TElPKCS7AuthenticatedData, OriginatorCerts);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
		virtual TElPKCS7Recipient* get_Recipients(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_ContentParts(int32_t Index);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		virtual int32_t get_RecipientCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RecipientCount, TElPKCS7AuthenticatedData, RecipientCount);

		virtual void get_MacAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_MacAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_DigestAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_DigestAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual void set_Content(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_AuthenticatedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_AuthenticatedAttributes, TElPKCS7AuthenticatedData, AuthenticatedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_UnauthenticatedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_UnauthenticatedAttributes, TElPKCS7AuthenticatedData, UnauthenticatedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual void get_Mac(std::vector<uint8_t> &OutResult);

		virtual void set_Mac(const std::vector<uint8_t> &Value);

		virtual void get_AuthenticatedAttributesPlain(std::vector<uint8_t> &OutResult);

		virtual int32_t get_ContentPartCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ContentPartCount, TElPKCS7AuthenticatedData, ContentPartCount);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_DataSource();

		SB_DECLARE_PROPERTY_GET(TElASN1DataSource*, get_DataSource, TElPKCS7AuthenticatedData, DataSource);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		TElPKCS7AuthenticatedData(TElPKCS7AuthenticatedDataHandle handle, TElOwnHandle ownHandle);

		TElPKCS7AuthenticatedData();

		virtual ~TElPKCS7AuthenticatedData();

};
#endif /* SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
class TElPKCS7TimestampAndCRL: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7TimestampAndCRL)
	public:
		void SetEncodedTimestamp(const std::vector<uint8_t> &V);

		void SetEncodedCRL(const std::vector<uint8_t> &V);

		void SetEncodedValue(const std::vector<uint8_t> &V);

		virtual void get_EncodedTimestamp(std::vector<uint8_t> &OutResult);

		virtual void set_EncodedTimestamp(const std::vector<uint8_t> &Value);

		virtual void get_EncodedCRL(std::vector<uint8_t> &OutResult);

		virtual void set_EncodedCRL(const std::vector<uint8_t> &Value);

		virtual void get_EncodedValue(std::vector<uint8_t> &OutResult);

		virtual void set_EncodedValue(const std::vector<uint8_t> &Value);

		TElPKCS7TimestampAndCRL(TElPKCS7TimestampAndCRLHandle handle, TElOwnHandle ownHandle);

		TElPKCS7TimestampAndCRL();

};
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA
class TElPKCS7TimestampedData: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7TimestampedData)
#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
		TElPKCS7TimestampAndCRL* _Inst_Timestamps;
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_ContentParts;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_DataSource;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		void initInstances();

	public:
		int32_t AddTimestamp();

		bool RemoveTimestamp(int32_t Index);

		void ClearTimestamps();

		void WriteMetadata(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
		void WriteTimestampAndCRL(TElPKCS7TimestampAndCRL &Ts, std::vector<uint8_t> &OutResult);

		void WriteTimestampAndCRL(TElPKCS7TimestampAndCRL *Ts, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */

		virtual void get_DataURI(std::vector<uint8_t> &OutResult);

		virtual void set_DataURI(const std::vector<uint8_t> &Value);

		virtual bool get_HashProtected();

		virtual void set_HashProtected(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HashProtected, set_HashProtected, TElPKCS7TimestampedData, HashProtected);

		virtual void get_FileName(std::vector<uint8_t> &OutResult);

		virtual void set_FileName(const std::vector<uint8_t> &Value);

		virtual void get_MediaType(std::vector<uint8_t> &OutResult);

		virtual void set_MediaType(const std::vector<uint8_t> &Value);

		virtual bool get_MetaDataAvailable();

		virtual void set_MetaDataAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_MetaDataAvailable, set_MetaDataAvailable, TElPKCS7TimestampedData, MetaDataAvailable);

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
		virtual TElPKCS7TimestampAndCRL* get_Timestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */

		virtual int32_t get_TimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TimestampCount, TElPKCS7TimestampedData, TimestampCount);

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual void set_Content(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_ContentParts(int32_t Index);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		virtual int32_t get_ContentPartCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ContentPartCount, TElPKCS7TimestampedData, ContentPartCount);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_DataSource();

		SB_DECLARE_PROPERTY_GET(TElASN1DataSource*, get_DataSource, TElPKCS7TimestampedData, DataSource);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		TElPKCS7TimestampedData(TElPKCS7TimestampedDataHandle handle, TElOwnHandle ownHandle);

		TElPKCS7TimestampedData();

		virtual ~TElPKCS7TimestampedData();

};
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA */

#ifdef SB_USE_GLOBAL_PROCS_PKCS7

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
bool ProcessContentInfo(TElASN1ConstrainedTag &Tag, void * Buffer, int32_t &Size, std::vector<uint8_t> &ContentType);
bool ProcessContentInfo(TElASN1ConstrainedTag *Tag, void * Buffer, int32_t &Size, std::vector<uint8_t> &ContentType);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TOBJECT
bool ProcessContentInfo(TElASN1ConstrainedTag &Tag, TObject &PKCS7Data, std::vector<uint8_t> &ContentType);
bool ProcessContentInfo(TElASN1ConstrainedTag *Tag, TObject *PKCS7Data, std::vector<uint8_t> &ContentType);
#endif /* SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TOBJECT */

#ifdef SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TELPKCS7SIGNER
void SaveSignerInfo(TElASN1ConstrainedTag &Tag, TElPKCS7Signer &Signer);
void SaveSignerInfo(TElASN1ConstrainedTag *Tag, TElPKCS7Signer *Signer);
#endif /* SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TELPKCS7SIGNER */

#ifdef SB_USE_CLASSES_TELASN1CUSTOMTAG_AND_TELPKCS7SIGNER
int32_t ProcessSignerInfo(TElASN1CustomTag &Tag, TElPKCS7Signer &SignerInfo);
int32_t ProcessSignerInfo(TElASN1CustomTag *Tag, TElPKCS7Signer *SignerInfo);
#endif /* SB_USE_CLASSES_TELASN1CUSTOMTAG_AND_TELPKCS7SIGNER */

void RaisePKCS7Error(int32_t ErrorCode);

#endif /* SB_USE_GLOBAL_PROCS_PKCS7 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PKCS7
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7_ProcessContentInfo(TElASN1ConstrainedTagHandle Tag, void * Buffer, int32_t * Size, uint8_t pContentType[], int32_t * szContentType, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7_ProcessContentInfo_1(TElASN1ConstrainedTagHandle Tag, TObjectHandle PKCS7Data, uint8_t pContentType[], int32_t * szContentType, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7_SaveSignerInfo(TElASN1ConstrainedTagHandle Tag, TElPKCS7SignerHandle Signer);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7_ProcessSignerInfo(TElASN1CustomTagHandle Tag, TElPKCS7SignerHandle SignerInfo, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7_RaisePKCS7Error(int32_t ErrorCode);
#endif /* SB_USE_GLOBAL_PROCS_PKCS7 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS7 */

