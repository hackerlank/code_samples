#ifndef __INC_SBMESSAGES
#define __INC_SBMESSAGES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbrdn.h"
#include "sbx509.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbzlib.h"
#include "sbcryptoprov.h"
#include "sbcustomcertstorage.h"
#include "sbcrlstorage.h"
#include "sbpkcs7.h"
#include "sbpkcs7utils.h"
#include "sbasn1tree.h"
#include "sbalgorithmidentifier.h"
#include "sbcustomcrypto.h"
#include "sbsymmetriccrypto.h"
#include "sbpublickeycrypto.h"
#include "sbeccommon.h"
#include "sbgost2814789.h"
#include "sbgost341001.h"
#include "sbtspclient.h"
#include "sbhashfunction.h"
#include "sbstreams.h"
#include "sbdc.h"
#include "sbdcdef.h"
#include "sbdcpkiconstants.h"
#include "sbrandom.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_CMSBASE 	8192
#define SB_MESSAGE_ERROR_NO_ENCRYPTED_DATA 	8193
#define SB_MESSAGE_ERROR_NO_CERTIFICATE 	8194
#define SB_MESSAGE_ERROR_KEY_DECRYPTION_FAILED 	8195
#define SB_MESSAGE_ERROR_BUFFER_TOO_SMALL 	8196
#define SB_MESSAGE_ERROR_CONTENT_DECRYPTION_FAILED 	8197
#define SB_MESSAGE_ERROR_INVALID_FORMAT 	8198
#define SB_MESSAGE_ERROR_NO_RECIPIENTS 	8199
#define SB_MESSAGE_ERROR_UNSUPPORTED_ALGORITHM 	8200
#define SB_MESSAGE_ERROR_ENCRYPTION_FAILED 	8201
#define SB_MESSAGE_ERROR_INVALID_KEY_LENGTH 	8202
#define SB_MESSAGE_ERROR_NO_SIGNED_DATA 	8203
#define SB_MESSAGE_ERROR_INVALID_SIGNATURE 	8204
#define SB_MESSAGE_ERROR_INVALID_DIGEST 	8205
#define SB_MESSAGE_ERROR_SIGNING_FAILED 	8206
#define SB_MESSAGE_ERROR_INTERNAL_ERROR 	8207
#define SB_MESSAGE_ERROR_INVALID_MAC 	8208
#define SB_MESSAGE_ERROR_UNSUPPORTED_SIGNATURE_TYPE 	8209
#define SB_MESSAGE_ERROR_INVALID_COUNTERSIGNATURE 	8210
#define SB_MESSAGE_ERROR_DIGEST_NOT_FOUND 	8211
#define SB_MESSAGE_ERROR_UNSUPPORTED_DIGEST_ALGORITHM 	8212
#define SB_MESSAGE_ERROR_CANCELLED_BY_USER 	8213
#define SB_MESSAGE_ERROR_VERIFICATION_FAILED 	8214
#define SB_MESSAGE_ERROR_DIGEST_CALCULATION_FAILED 	8215
#define SB_MESSAGE_ERROR_MAC_CALCULATION_FAILED 	8216
#define SB_MESSAGE_ERROR_TSPCLIENT_NOT_FOUND 	8217
#define SB_MESSAGE_ERROR_BAD_TIMESTAMP 	8218
#define SB_MESSAGE_ERROR_KEYOP_FAILED_RSA 	8219
#define SB_MESSAGE_ERROR_KEYOP_FAILED_DSA 	8220
#define SB_MESSAGE_ERROR_KEYOP_FAILED_RSA_PSS 	8221
#define SB_MESSAGE_ERROR_NO_COMPRESSED_DATA 	8222
#define SB_MESSAGE_ERROR_KEYOP_FAILED_EC 	8223
#define SB_MESSAGE_ERROR_DC_BAD_ASYNC_STATE 	8224
#define SB_MESSAGE_ERROR_DC_SERVER_ERROR 	8225
#define SB_MESSAGE_ERROR_DC_MODULE_UNAVAILABLE 	8226
#define SB_MESSAGE_ERROR_KEYOP_FAILED_GOST 	8227
#define SB_MESSAGE_ERROR_NO_CONTENT_OR_DATA_URI 	8228
#define SB_MESSAGE_ERROR_TIMESTAMPING_FAILED 	8229
#define SB_MESSAGE_ERROR_NO_TIMESTAMPED_DATA 	8230
#define SB_MESSAGE_ERROR_ASN_LIMIT_EXCEEDED 	8231
#define SB_MESSAGE_ERROR_DATA_NOT_AVAILABLE 	8232

typedef TElClassHandle TElMessageProcessorHandle;

typedef TElMessageProcessorHandle ElMessageProcessorHandle;

typedef TElClassHandle TElMessageEncryptorHandle;

typedef TElMessageEncryptorHandle ElMessageEncryptorHandle;

typedef TElClassHandle TElMessageDecryptorHandle;

typedef TElMessageDecryptorHandle ElMessageDecryptorHandle;

typedef TElClassHandle TElMessageVerifierHandle;

typedef TElMessageVerifierHandle ElMessageVerifierHandle;

typedef TElClassHandle TElMessageSignerHandle;

typedef TElMessageSignerHandle ElMessageSignerHandle;

typedef TElClassHandle TElMessageDecompressorHandle;

typedef TElClassHandle TElMessageCompressorHandle;

typedef TElClassHandle TElMessageTimestamperHandle;

typedef TElClassHandle TElMessageTimestampVerifierHandle;

typedef uint8_t TSBEncryptionOptionRaw;

typedef enum
{
	eoIgnoreSupportedWin32Algorithms = 0,
	eoNoOuterContentInfo = 1
} TSBEncryptionOption;

typedef uint32_t TSBEncryptionOptionsRaw;

typedef enum 
{
	f_eoIgnoreSupportedWin32Algorithms = 1,
	f_eoNoOuterContentInfo = 2
} TSBEncryptionOptions;

typedef void (SB_CALLBACK *TSBCertIDsEvent)(void * _ObjectData, TObjectHandle Sender, TListHandle CertIDs);

typedef uint8_t TSBDecryptionOptionRaw;

typedef enum
{
	doNoOuterContentInfo = 0
} TSBDecryptionOption;

typedef uint32_t TSBDecryptionOptionsRaw;

typedef enum 
{
	f_doNoOuterContentInfo = 1
} TSBDecryptionOptions;

typedef uint8_t TSBMessageSignatureTypeRaw;

typedef enum
{
	mstPublicKey = 0,
	mstMAC = 1
} TSBMessageSignatureType;

typedef uint8_t TSBVerificationOptionRaw;

typedef enum
{
	voUseEmbeddedCerts = 0,
	voUseLocalCerts = 1,
	voVerifyMessageDigests = 2,
	voVerifyTimestamps = 3,
	voNoOuterContentInfo = 4,
	voLiberalMode = 5
} TSBVerificationOption;

typedef uint32_t TSBVerificationOptionsRaw;

typedef enum 
{
	f_voUseEmbeddedCerts = 1,
	f_voUseLocalCerts = 2,
	f_voVerifyMessageDigests = 4,
	f_voVerifyTimestamps = 8,
	f_voNoOuterContentInfo = 16,
	f_voLiberalMode = 32
} TSBVerificationOptions;

typedef uint8_t TSBSigningOptionRaw;

typedef enum
{
	soInsertMessageDigests = 0,
	soIgnoreTimestampFailure = 1,
	soNoOuterContentInfo = 2,
	soRawCountersign = 3,
	soInsertSigningTime = 4,
	soUseGeneralizedTimeFormat = 5,
	soIgnoreBadCountersignatures = 6,
	soUseImplicitContent = 7
} TSBSigningOption;

typedef uint32_t TSBSigningOptionsRaw;

typedef enum 
{
	f_soInsertMessageDigests = 1,
	f_soIgnoreTimestampFailure = 2,
	f_soNoOuterContentInfo = 4,
	f_soRawCountersign = 8,
	f_soInsertSigningTime = 16,
	f_soUseGeneralizedTimeFormat = 32,
	f_soIgnoreBadCountersignatures = 64,
	f_soUseImplicitContent = 128
} TSBSigningOptions;

typedef uint8_t TSBSignOperationTypeRaw;

typedef enum
{
	sotGeneric = 0,
	sotAsyncPrepare = 1,
	sotAsyncComplete = 2
} TSBSignOperationType;

#ifdef SB_USE_CLASS_TELMESSAGEPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElMessageProcessor_get_ErrorInfo(TElMessageProcessorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageProcessor_get_CryptoProviderManager(TElMessageProcessorHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageProcessor_set_CryptoProviderManager(TElMessageProcessorHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageProcessor_get_AlignEncryptedKey(TElMessageProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageProcessor_set_AlignEncryptedKey(TElMessageProcessorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageProcessor_get_OnProgress(TElMessageProcessorHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageProcessor_set_OnProgress(TElMessageProcessorHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageProcessor_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEPROCESSOR */

#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_Encrypt(TElMessageEncryptorHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_Encrypt_1(TElMessageEncryptorHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, void * Key, int32_t KeySize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_Encrypt_2(TElMessageEncryptorHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_Encrypt_3(TElMessageEncryptorHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, void * Key, int32_t KeySize, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_GOSTParamSet(TElMessageEncryptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_GOSTParamSet(TElMessageEncryptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_CertStorage(TElMessageEncryptorHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_CertStorage(TElMessageEncryptorHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_Algorithm(TElMessageEncryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_Algorithm(TElMessageEncryptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_BitsInKey(TElMessageEncryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_BitsInKey(TElMessageEncryptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_UseUndefSize(TElMessageEncryptorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_UseUndefSize(TElMessageEncryptorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_UseOAEP(TElMessageEncryptorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_UseOAEP(TElMessageEncryptorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_EncryptionOptions(TElMessageEncryptorHandle _Handle, TSBEncryptionOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_EncryptionOptions(TElMessageEncryptorHandle _Handle, TSBEncryptionOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_UseImplicitContentEncoding(TElMessageEncryptorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_UseImplicitContentEncoding(TElMessageEncryptorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_OriginatorCertificates(TElMessageEncryptorHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_OriginatorCertificates(TElMessageEncryptorHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_OriginatorCRLs(TElMessageEncryptorHandle _Handle, TElCustomCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_set_OriginatorCRLs(TElMessageEncryptorHandle _Handle, TElCustomCRLStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_get_UnprotectedAttributes(TElMessageEncryptorHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageEncryptor_Create(TComponentHandle AOwner, TElMessageEncryptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_Decrypt(TElMessageDecryptorHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_Decrypt_1(TElMessageDecryptorHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, void * Key, int32_t KeySize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_Decrypt_2(TElMessageDecryptorHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_Decrypt_3(TElMessageDecryptorHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, void * Key, int32_t KeySize, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_IsConventionallyEncrypted(void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_IsConventionallyEncrypted_1(TElMessageDecryptorHandle _Handle, void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_Algorithm(TElMessageDecryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_BitsInKey(TElMessageDecryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_CertIDs(TElMessageDecryptorHandle _Handle, int32_t Index, TElPKCS7IssuerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_CertIDCount(TElMessageDecryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_UsedCertificate(TElMessageDecryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_UseOAEP(TElMessageDecryptorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_OriginatorCertificates(TElMessageDecryptorHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_OriginatorCRLs(TElMessageDecryptorHandle _Handle, TElMemoryCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_UnprotectedAttributes(TElMessageDecryptorHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_CertStorage(TElMessageDecryptorHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_set_CertStorage(TElMessageDecryptorHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_DecryptionOptions(TElMessageDecryptorHandle _Handle, TSBDecryptionOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_set_DecryptionOptions(TElMessageDecryptorHandle _Handle, TSBDecryptionOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_get_OnCertIDs(TElMessageDecryptorHandle _Handle, TSBCertIDsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_set_OnCertIDs(TElMessageDecryptorHandle _Handle, TSBCertIDsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecryptor_Create(TComponentHandle AOwner, TElMessageDecryptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_Verify(TElMessageVerifierHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_Verify_1(TElMessageVerifierHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_VerifyDetached(TElMessageVerifierHandle _Handle, void * Buffer, int32_t Size, void * Signature, int32_t SignatureSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_VerifyDetached_1(TElMessageVerifierHandle _Handle, TStreamHandle InStream, TStreamHandle SigStream, int64_t InCount, int64_t SigCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_IsSignatureDetached(void * Signature, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_IsSignatureDetached_1(TElMessageVerifierHandle _Handle, void * Signature, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_IsSignatureDetached_2(TStreamHandle Signature, int64_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_IsSignatureDetached_3(TElMessageVerifierHandle _Handle, TStreamHandle Signature, int64_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_Certificates(TElMessageVerifierHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_Attributes(TElMessageVerifierHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_HashAlgorithm(TElMessageVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_MacAlgorithm(TElMessageVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_CertIDs(TElMessageVerifierHandle _Handle, int32_t Index, TElPKCS7IssuerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_CountersignatureCertIDs(TElMessageVerifierHandle _Handle, int32_t Index, TElPKCS7IssuerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_CountersignatureVerificationResults(TElMessageVerifierHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_CountersignatureAttributes(TElMessageVerifierHandle _Handle, int32_t Index, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_CertIDCount(TElMessageVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_CountersignatureCertIDCount(TElMessageVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_SignatureType(TElMessageVerifierHandle _Handle, TSBMessageSignatureTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_UsePSS(TElMessageVerifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_InputIsDigest(TElMessageVerifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_set_InputIsDigest(TElMessageVerifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_Timestamps(TElMessageVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_TimestampCount(TElMessageVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_SigningTime(TElMessageVerifierHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_CertStorage(TElMessageVerifierHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_set_CertStorage(TElMessageVerifierHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_VerifyCountersignatures(TElMessageVerifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_set_VerifyCountersignatures(TElMessageVerifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_VerificationOptions(TElMessageVerifierHandle _Handle, TSBVerificationOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_set_VerificationOptions(TElMessageVerifierHandle _Handle, TSBVerificationOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_get_OnCertIDs(TElMessageVerifierHandle _Handle, TSBCertIDsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_set_OnCertIDs(TElMessageVerifierHandle _Handle, TSBCertIDsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageVerifier_Create(TComponentHandle AOwner, TElMessageVerifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELMESSAGESIGNER
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_Sign(TElMessageSignerHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t Detached, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_Sign_1(TElMessageSignerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int8_t Detached, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_InitiateAsyncSign(TElMessageSignerHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t Detached, TElDCAsyncStateHandle * State, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_InitiateAsyncSign_1(TElMessageSignerHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t Detached, TSBDCAsyncSignMethodRaw AsyncSignMethod, TElDCAsyncStateHandle * State, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_InitiateAsyncSign_2(TElMessageSignerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int8_t Detached, TElDCAsyncStateHandle * State, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_InitiateAsyncSign_3(TElMessageSignerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int8_t Detached, TSBDCAsyncSignMethodRaw AsyncSignMethod, TElDCAsyncStateHandle * State, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_CompleteAsyncSign(TElMessageSignerHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElDCAsyncStateHandle AsyncState, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_CompleteAsyncSign_1(TElMessageSignerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, TElDCAsyncStateHandle AsyncState, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_Countersign(TElMessageSignerHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_Countersign_1(TElMessageSignerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_Timestamp(TElMessageSignerHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_Timestamp_1(TElMessageSignerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_TimestampCountersignature(TElMessageSignerHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t SigIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_TimestampCountersignature_1(TElMessageSignerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t SigIndex, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_AuthenticatedAttributes(TElMessageSignerHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_UnauthenticatedAttributes(TElMessageSignerHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_HashAlgorithm(TElMessageSignerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_HashAlgorithm(TElMessageSignerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_MacAlgorithm(TElMessageSignerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_MacAlgorithm(TElMessageSignerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_ContentType(TElMessageSignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_ContentType(TElMessageSignerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_DataHash(TElMessageSignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_DigestEncryptionAlgorithm(TElMessageSignerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_DigestEncryptionAlgorithm(TElMessageSignerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_SigningTime(TElMessageSignerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_SigningTime(TElMessageSignerHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_SignatureType(TElMessageSignerHandle _Handle, TSBMessageSignatureTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_SignatureType(TElMessageSignerHandle _Handle, TSBMessageSignatureTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_CertStorage(TElMessageSignerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_CertStorage(TElMessageSignerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_IncludeCertificates(TElMessageSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_IncludeCertificates(TElMessageSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_IncludeChain(TElMessageSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_IncludeChain(TElMessageSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_RecipientCerts(TElMessageSignerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_RecipientCerts(TElMessageSignerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_UseUndefSize(TElMessageSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_UseUndefSize(TElMessageSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_UsePSS(TElMessageSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_UsePSS(TElMessageSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_SigningOptions(TElMessageSignerHandle _Handle, TSBSigningOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_SigningOptions(TElMessageSignerHandle _Handle, TSBSigningOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_ExtraSpace(TElMessageSignerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_ExtraSpace(TElMessageSignerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_InputIsHash(TElMessageSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_InputIsHash(TElMessageSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_get_TSPClient(TElMessageSignerHandle _Handle, TElCustomTSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_set_TSPClient(TElMessageSignerHandle _Handle, TElCustomTSPClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageSigner_Create(TComponentHandle AOwner, TElMessageSignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELMESSAGEDECOMPRESSOR
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecompressor_Decompress(TElMessageDecompressorHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecompressor_Decompress_1(TElMessageDecompressorHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecompressor_get_ContentType(TElMessageDecompressorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageDecompressor_Create(TComponentHandle AOwner, TElMessageDecompressorHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEDECOMPRESSOR */

#ifdef SB_USE_CLASS_TELMESSAGECOMPRESSOR
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_Compress(TElMessageCompressorHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_Compress_1(TElMessageCompressorHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_get_ContentType(TElMessageCompressorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_set_ContentType(TElMessageCompressorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_get_CompressionLevel(TElMessageCompressorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_set_CompressionLevel(TElMessageCompressorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_get_FragmentSize(TElMessageCompressorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_set_FragmentSize(TElMessageCompressorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_get_UseUndefSize(TElMessageCompressorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_set_UseUndefSize(TElMessageCompressorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageCompressor_Create(TComponentHandle AOwner, TElMessageCompressorHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGECOMPRESSOR */

#ifdef SB_USE_CLASS_TELMESSAGETIMESTAMPER
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_Timestamp(TElMessageTimestamperHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_Timestamp_1(TElMessageTimestamperHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_AddTSPClient(TElMessageTimestamperHandle _Handle, TElCustomTSPClientHandle Client, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_RemoveTSPClient(TElMessageTimestamperHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_RemoveTSPClient_1(TElMessageTimestamperHandle _Handle, TElCustomTSPClientHandle Client);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_TSPClients(TElMessageTimestamperHandle _Handle, int32_t Index, TElCustomTSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_TSPClientsCount(TElMessageTimestamperHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_TSPClient(TElMessageTimestamperHandle _Handle, TElCustomTSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_set_TSPClient(TElMessageTimestamperHandle _Handle, TElCustomTSPClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_IncludeContent(TElMessageTimestamperHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_set_IncludeContent(TElMessageTimestamperHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_ProtectMetadata(TElMessageTimestamperHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_set_ProtectMetadata(TElMessageTimestamperHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_DataURI(TElMessageTimestamperHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_set_DataURI(TElMessageTimestamperHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_FileName(TElMessageTimestamperHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_set_FileName(TElMessageTimestamperHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_MediaType(TElMessageTimestamperHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_set_MediaType(TElMessageTimestamperHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_get_UseUndefSize(TElMessageTimestamperHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_set_UseUndefSize(TElMessageTimestamperHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestamper_Create(TComponentHandle AOwner, TElMessageTimestamperHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGETIMESTAMPER */

#ifdef SB_USE_CLASS_TELMESSAGETIMESTAMPVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_Verify(TElMessageTimestampVerifierHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_Verify_1(TElMessageTimestampVerifierHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_VerifyDetached(TElMessageTimestampVerifierHandle _Handle, void * Buffer, int32_t Size, void * Data, int32_t DataSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_VerifyDetached_1(TElMessageTimestampVerifierHandle _Handle, TStreamHandle InStream, TStreamHandle DataStream, int64_t InCount, int64_t DataCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_IsTimestampDetached(void * Timestamp, int32_t Size, char * pcDataURI, int32_t * szDataURI, char * pcFileName, int32_t * szFileName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_IsTimestampDetached_1(TElMessageTimestampVerifierHandle _Handle, void * Timestamp, int32_t Size, char * pcDataURI, int32_t * szDataURI, char * pcFileName, int32_t * szFileName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_IsTimestampDetached_2(TStreamHandle Timestamp, char * pcDataURI, int32_t * szDataURI, char * pcFileName, int32_t * szFileName, int64_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_IsTimestampDetached_3(TElMessageTimestampVerifierHandle _Handle, TStreamHandle Timestamp, char * pcDataURI, int32_t * szDataURI, char * pcFileName, int32_t * szFileName, int64_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_get_Timestamps(TElMessageTimestampVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_get_TimestampCount(TElMessageTimestampVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_get_DataURI(TElMessageTimestampVerifierHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_get_FileName(TElMessageTimestampVerifierHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_get_MediaType(TElMessageTimestampVerifierHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessageTimestampVerifier_Create(TComponentHandle AOwner, TElMessageTimestampVerifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGETIMESTAMPVERIFIER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElMessageProcessor;
typedef TElMessageProcessor ElMessageProcessor;
class TElMessageEncryptor;
typedef TElMessageEncryptor ElMessageEncryptor;
class TElMessageDecryptor;
typedef TElMessageDecryptor ElMessageDecryptor;
class TElMessageVerifier;
typedef TElMessageVerifier ElMessageVerifier;
class TElMessageSigner;
typedef TElMessageSigner ElMessageSigner;
class TElMessageDecompressor;
class TElMessageCompressor;
class TElMessageTimestamper;
class TElMessageTimestampVerifier;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBEncryptionOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBDecryptionOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBVerificationOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSigningOptions)

#ifdef SB_USE_CLASS_TELMESSAGEPROCESSOR
class TElMessageProcessor: public TComponent
{
	private:
		SB_DISABLE_COPY(TElMessageProcessor)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		virtual void get_ErrorInfo(std::string &OutResult);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElMessageProcessor, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual bool get_AlignEncryptedKey();

		virtual void set_AlignEncryptedKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AlignEncryptedKey, set_AlignEncryptedKey, TElMessageProcessor, AlignEncryptedKey);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElMessageProcessor(TElMessageProcessorHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageProcessor(TComponent &AOwner);

		explicit TElMessageProcessor(TComponent *AOwner);

		virtual ~TElMessageProcessor();

};
#endif /* SB_USE_CLASS_TELMESSAGEPROCESSOR */

#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
class TElMessageEncryptor: public TElMessageProcessor
{
	private:
		SB_DISABLE_COPY(TElMessageEncryptor)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_OriginatorCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
		TElCustomCRLStorage* _Inst_OriginatorCRLs;
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_UnprotectedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		void initInstances();

	public:
		int32_t Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		int32_t Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, void * Key, int32_t KeySize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Encrypt(TStream &InStream, TStream &OutStream, int64_t InCount);

		int32_t Encrypt(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Encrypt(TStream &InStream, TStream &OutStream, void * Key, int32_t KeySize, int64_t InCount);

		int32_t Encrypt(TStream *InStream, TStream *OutStream, void * Key, int32_t KeySize, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_GOSTParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_GOSTParamSet(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElMessageEncryptor, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElMessageEncryptor, Algorithm);

		virtual int32_t get_BitsInKey();

		virtual void set_BitsInKey(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BitsInKey, set_BitsInKey, TElMessageEncryptor, BitsInKey);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElMessageEncryptor, UseUndefSize);

		virtual bool get_UseOAEP();

		virtual void set_UseOAEP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOAEP, set_UseOAEP, TElMessageEncryptor, UseOAEP);

		virtual TSBEncryptionOptions get_EncryptionOptions();

		virtual void set_EncryptionOptions(TSBEncryptionOptions Value);

		SB_DECLARE_PROPERTY(TSBEncryptionOptions, get_EncryptionOptions, set_EncryptionOptions, TElMessageEncryptor, EncryptionOptions);

		virtual bool get_UseImplicitContentEncoding();

		virtual void set_UseImplicitContentEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseImplicitContentEncoding, set_UseImplicitContentEncoding, TElMessageEncryptor, UseImplicitContentEncoding);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_OriginatorCertificates();

		virtual void set_OriginatorCertificates(TElCustomCertStorage &Value);

		virtual void set_OriginatorCertificates(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_OriginatorCertificates, set_OriginatorCertificates, TElMessageEncryptor, OriginatorCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
		virtual TElCustomCRLStorage* get_OriginatorCRLs();

		virtual void set_OriginatorCRLs(TElCustomCRLStorage &Value);

		virtual void set_OriginatorCRLs(TElCustomCRLStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCRLStorage*, get_OriginatorCRLs, set_OriginatorCRLs, TElMessageEncryptor, OriginatorCRLs);
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_UnprotectedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_UnprotectedAttributes, TElMessageEncryptor, UnprotectedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		TElMessageEncryptor(TElMessageEncryptorHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageEncryptor(TComponent &AOwner);

		explicit TElMessageEncryptor(TComponent *AOwner);

		virtual ~TElMessageEncryptor();

};
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
class TElMessageDecryptor: public TElMessageProcessor
{
	private:
		SB_DISABLE_COPY(TElMessageDecryptor)
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		TElPKCS7Issuer* _Inst_CertIDs;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_OriginatorCertificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		TElMemoryCRLStorage* _Inst_OriginatorCRLs;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_UnprotectedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		int32_t Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		int32_t Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, void * Key, int32_t KeySize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Decrypt(TStream &InStream, TStream &OutStream, int64_t InCount);

		int32_t Decrypt(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Decrypt(TStream &InStream, TStream &OutStream, void * Key, int32_t KeySize, int64_t InCount);

		int32_t Decrypt(TStream *InStream, TStream *OutStream, void * Key, int32_t KeySize, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		static bool IsConventionallyEncrypted(void * Buffer, int32_t Size);

		bool IsConventionallyEncrypted_Inst(void * Buffer, int32_t Size);

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElMessageDecryptor, Algorithm);

		virtual int32_t get_BitsInKey();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BitsInKey, TElMessageDecryptor, BitsInKey);

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		virtual TElPKCS7Issuer* get_CertIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

		virtual int32_t get_CertIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertIDCount, TElMessageDecryptor, CertIDCount);

		virtual int32_t get_UsedCertificate();

		SB_DECLARE_PROPERTY_GET(int32_t, get_UsedCertificate, TElMessageDecryptor, UsedCertificate);

		virtual bool get_UseOAEP();

		SB_DECLARE_PROPERTY_GET(bool, get_UseOAEP, TElMessageDecryptor, UseOAEP);

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_OriginatorCertificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_OriginatorCertificates, TElMessageDecryptor, OriginatorCertificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		virtual TElMemoryCRLStorage* get_OriginatorCRLs();

		SB_DECLARE_PROPERTY_GET(TElMemoryCRLStorage*, get_OriginatorCRLs, TElMessageDecryptor, OriginatorCRLs);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_UnprotectedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_UnprotectedAttributes, TElMessageDecryptor, UnprotectedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElMessageDecryptor, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual TSBDecryptionOptions get_DecryptionOptions();

		virtual void set_DecryptionOptions(TSBDecryptionOptions Value);

		SB_DECLARE_PROPERTY(TSBDecryptionOptions, get_DecryptionOptions, set_DecryptionOptions, TElMessageDecryptor, DecryptionOptions);

		virtual void get_OnCertIDs(TSBCertIDsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertIDs(TSBCertIDsEvent pMethodValue, void * pDataValue);

		TElMessageDecryptor(TElMessageDecryptorHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageDecryptor(TComponent &AOwner);

		explicit TElMessageDecryptor(TComponent *AOwner);

		virtual ~TElMessageDecryptor();

};
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
class TElMessageVerifier: public TElMessageProcessor
{
	private:
		SB_DISABLE_COPY(TElMessageVerifier)
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		TElPKCS7Issuer* _Inst_CertIDs;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		TElPKCS7Issuer* _Inst_CountersignatureCertIDs;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_CountersignatureAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_Timestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		virtual int32_t Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Verify(TStream &InStream, TStream &OutStream, int64_t InCount);

		int32_t Verify(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t VerifyDetached(void * Buffer, int32_t Size, void * Signature, int32_t SignatureSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t VerifyDetached(TStream &InStream, TStream &SigStream, int64_t InCount, int64_t SigCount);

		int32_t VerifyDetached(TStream *InStream, TStream *SigStream, int64_t InCount, int64_t SigCount);
#endif /* SB_USE_CLASS_TSTREAM */

		static bool IsSignatureDetached(void * Signature, int32_t Size);

		bool IsSignatureDetached_Inst(void * Signature, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		static bool IsSignatureDetached(TStream &Signature, int64_t Count);

		static bool IsSignatureDetached(TStream *Signature, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool IsSignatureDetached_Inst(TStream &Signature, int64_t Count);

		bool IsSignatureDetached_Inst(TStream *Signature, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_Certificates, TElMessageVerifier, Certificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_Attributes, TElMessageVerifier, Attributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual int32_t get_HashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HashAlgorithm, TElMessageVerifier, HashAlgorithm);

		virtual int32_t get_MacAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MacAlgorithm, TElMessageVerifier, MacAlgorithm);

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		virtual TElPKCS7Issuer* get_CertIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		virtual TElPKCS7Issuer* get_CountersignatureCertIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

		virtual int32_t get_CountersignatureVerificationResults(int32_t Index);

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_CountersignatureAttributes(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual int32_t get_CertIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertIDCount, TElMessageVerifier, CertIDCount);

		virtual int32_t get_CountersignatureCertIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CountersignatureCertIDCount, TElMessageVerifier, CountersignatureCertIDCount);

		virtual TSBMessageSignatureType get_SignatureType();

		SB_DECLARE_PROPERTY_GET(TSBMessageSignatureType, get_SignatureType, TElMessageVerifier, SignatureType);

		virtual bool get_UsePSS();

		SB_DECLARE_PROPERTY_GET(bool, get_UsePSS, TElMessageVerifier, UsePSS);

		virtual bool get_InputIsDigest();

		virtual void set_InputIsDigest(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InputIsDigest, set_InputIsDigest, TElMessageVerifier, InputIsDigest);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_Timestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_TimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TimestampCount, TElMessageVerifier, TimestampCount);

		virtual int64_t get_SigningTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SigningTime, TElMessageVerifier, SigningTime);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElMessageVerifier, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_VerifyCountersignatures();

		virtual void set_VerifyCountersignatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_VerifyCountersignatures, set_VerifyCountersignatures, TElMessageVerifier, VerifyCountersignatures);

		virtual TSBVerificationOptions get_VerificationOptions();

		virtual void set_VerificationOptions(TSBVerificationOptions Value);

		SB_DECLARE_PROPERTY(TSBVerificationOptions, get_VerificationOptions, set_VerificationOptions, TElMessageVerifier, VerificationOptions);

		virtual void get_OnCertIDs(TSBCertIDsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertIDs(TSBCertIDsEvent pMethodValue, void * pDataValue);

		TElMessageVerifier(TElMessageVerifierHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageVerifier(TComponent &AOwner);

		explicit TElMessageVerifier(TComponent *AOwner);

		virtual ~TElMessageVerifier();

};
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELMESSAGESIGNER
class TElMessageSigner: public TElMessageProcessor
{
	private:
		SB_DISABLE_COPY(TElMessageSigner)
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_AuthenticatedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_UnauthenticatedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_RecipientCerts;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		TElCustomTSPClient* _Inst_TSPClient;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		void initInstances();

	public:
		virtual int32_t Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t Sign(TStream &InStream, TStream &OutStream, bool Detached, int64_t InCount);

		virtual int32_t Sign(TStream *InStream, TStream *OutStream, bool Detached, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		int32_t InitiateAsyncSign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached, TElDCAsyncState &State);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		int32_t InitiateAsyncSign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached, TSBDCAsyncSignMethod AsyncSignMethod, TElDCAsyncState &State);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM
		int32_t InitiateAsyncSign(TStream &InStream, TStream &OutStream, bool Detached, TElDCAsyncState &State, int64_t InCount);

		int32_t InitiateAsyncSign(TStream *InStream, TStream *OutStream, bool Detached, TElDCAsyncState &State, int64_t InCount);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM
		int32_t InitiateAsyncSign(TStream &InStream, TStream &OutStream, bool Detached, TSBDCAsyncSignMethod AsyncSignMethod, TElDCAsyncState &State, int64_t InCount);

		int32_t InitiateAsyncSign(TStream *InStream, TStream *OutStream, bool Detached, TSBDCAsyncSignMethod AsyncSignMethod, TElDCAsyncState &State, int64_t InCount);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		int32_t CompleteAsyncSign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElDCAsyncState &AsyncState);

		int32_t CompleteAsyncSign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElDCAsyncState *AsyncState);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM
		int32_t CompleteAsyncSign(TStream &InStream, TStream &OutStream, TElDCAsyncState &AsyncState, int64_t InCount);

		int32_t CompleteAsyncSign(TStream *InStream, TStream *OutStream, TElDCAsyncState *AsyncState, int64_t InCount);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM */

		virtual int32_t Countersign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t Countersign(TStream &InStream, TStream &OutStream, int64_t InCount);

		virtual int32_t Countersign(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t Timestamp(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Timestamp(TStream &InStream, TStream &OutStream, int64_t InCount);

		int32_t Timestamp(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t TimestampCountersignature(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, int32_t SigIndex);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t TimestampCountersignature(TStream &InStream, TStream &OutStream, int32_t SigIndex, int64_t InCount);

		int32_t TimestampCountersignature(TStream *InStream, TStream *OutStream, int32_t SigIndex, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_AuthenticatedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_AuthenticatedAttributes, TElMessageSigner, AuthenticatedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_UnauthenticatedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_UnauthenticatedAttributes, TElMessageSigner, UnauthenticatedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElMessageSigner, HashAlgorithm);

		virtual int32_t get_MacAlgorithm();

		virtual void set_MacAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MacAlgorithm, set_MacAlgorithm, TElMessageSigner, MacAlgorithm);

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual void get_DataHash(std::vector<uint8_t> &OutResult);

		virtual void get_DigestEncryptionAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_DigestEncryptionAlgorithm(const std::vector<uint8_t> &Value);

		virtual int64_t get_SigningTime();

		virtual void set_SigningTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SigningTime, set_SigningTime, TElMessageSigner, SigningTime);

		virtual TSBMessageSignatureType get_SignatureType();

		virtual void set_SignatureType(TSBMessageSignatureType Value);

		SB_DECLARE_PROPERTY(TSBMessageSignatureType, get_SignatureType, set_SignatureType, TElMessageSigner, SignatureType);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElMessageSigner, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_IncludeCertificates();

		virtual void set_IncludeCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeCertificates, set_IncludeCertificates, TElMessageSigner, IncludeCertificates);

		virtual bool get_IncludeChain();

		virtual void set_IncludeChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeChain, set_IncludeChain, TElMessageSigner, IncludeChain);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_RecipientCerts();

		virtual void set_RecipientCerts(TElCustomCertStorage &Value);

		virtual void set_RecipientCerts(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_RecipientCerts, set_RecipientCerts, TElMessageSigner, RecipientCerts);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElMessageSigner, UseUndefSize);

		virtual bool get_UsePSS();

		virtual void set_UsePSS(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UsePSS, set_UsePSS, TElMessageSigner, UsePSS);

		virtual TSBSigningOptions get_SigningOptions();

		virtual void set_SigningOptions(TSBSigningOptions Value);

		SB_DECLARE_PROPERTY(TSBSigningOptions, get_SigningOptions, set_SigningOptions, TElMessageSigner, SigningOptions);

		virtual int32_t get_ExtraSpace();

		virtual void set_ExtraSpace(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ExtraSpace, set_ExtraSpace, TElMessageSigner, ExtraSpace);

		virtual bool get_InputIsHash();

		virtual void set_InputIsHash(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InputIsHash, set_InputIsHash, TElMessageSigner, InputIsHash);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		virtual TElCustomTSPClient* get_TSPClient();

		virtual void set_TSPClient(TElCustomTSPClient &Value);

		virtual void set_TSPClient(TElCustomTSPClient *Value);

		SB_DECLARE_PROPERTY(TElCustomTSPClient*, get_TSPClient, set_TSPClient, TElMessageSigner, TSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		TElMessageSigner(TElMessageSignerHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageSigner(TComponent &AOwner);

		explicit TElMessageSigner(TComponent *AOwner);

		virtual ~TElMessageSigner();

};
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELMESSAGEDECOMPRESSOR
class TElMessageDecompressor: public TElMessageProcessor
{
	private:
		SB_DISABLE_COPY(TElMessageDecompressor)
	public:
		int32_t Decompress(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Decompress(TStream &InStream, TStream &OutStream, int64_t InCount);

		int32_t Decompress(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		TElMessageDecompressor(TElMessageDecompressorHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageDecompressor(TComponent &AOwner);

		explicit TElMessageDecompressor(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELMESSAGEDECOMPRESSOR */

#ifdef SB_USE_CLASS_TELMESSAGECOMPRESSOR
class TElMessageCompressor: public TElMessageProcessor
{
	private:
		SB_DISABLE_COPY(TElMessageCompressor)
	public:
		int32_t Compress(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Compress(TStream &InStream, TStream &OutStream, int64_t InCount);

		int32_t Compress(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElMessageCompressor, CompressionLevel);

		virtual int32_t get_FragmentSize();

		virtual void set_FragmentSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FragmentSize, set_FragmentSize, TElMessageCompressor, FragmentSize);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElMessageCompressor, UseUndefSize);

		TElMessageCompressor(TElMessageCompressorHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageCompressor(TComponent &AOwner);

		explicit TElMessageCompressor(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELMESSAGECOMPRESSOR */

#ifdef SB_USE_CLASS_TELMESSAGETIMESTAMPER
class TElMessageTimestamper: public TElMessageProcessor
{
	private:
		SB_DISABLE_COPY(TElMessageTimestamper)
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		TElCustomTSPClient* _Inst_TSPClients;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		TElCustomTSPClient* _Inst_TSPClient;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		void initInstances();

	public:
		int32_t Timestamp(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Timestamp(TStream &InStream, TStream &OutStream, int64_t InCount);

		int32_t Timestamp(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddTSPClient(TElCustomTSPClient &Client);

		int32_t AddTSPClient(TElCustomTSPClient *Client);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		void RemoveTSPClient(int32_t Index);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		void RemoveTSPClient(TElCustomTSPClient &Client);

		void RemoveTSPClient(TElCustomTSPClient *Client);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		virtual TElCustomTSPClient* get_TSPClients(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		virtual int32_t get_TSPClientsCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TSPClientsCount, TElMessageTimestamper, TSPClientsCount);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		virtual TElCustomTSPClient* get_TSPClient();

		virtual void set_TSPClient(TElCustomTSPClient &Value);

		virtual void set_TSPClient(TElCustomTSPClient *Value);

		SB_DECLARE_PROPERTY(TElCustomTSPClient*, get_TSPClient, set_TSPClient, TElMessageTimestamper, TSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		virtual bool get_IncludeContent();

		virtual void set_IncludeContent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeContent, set_IncludeContent, TElMessageTimestamper, IncludeContent);

		virtual bool get_ProtectMetadata();

		virtual void set_ProtectMetadata(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ProtectMetadata, set_ProtectMetadata, TElMessageTimestamper, ProtectMetadata);

		virtual void get_DataURI(std::string &OutResult);

		virtual void set_DataURI(const std::string &Value);

		virtual void get_FileName(std::string &OutResult);

		virtual void set_FileName(const std::string &Value);

		virtual void get_MediaType(std::string &OutResult);

		virtual void set_MediaType(const std::string &Value);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElMessageTimestamper, UseUndefSize);

		TElMessageTimestamper(TElMessageTimestamperHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageTimestamper(TComponent &AOwner);

		explicit TElMessageTimestamper(TComponent *AOwner);

		virtual ~TElMessageTimestamper();

};
#endif /* SB_USE_CLASS_TELMESSAGETIMESTAMPER */

#ifdef SB_USE_CLASS_TELMESSAGETIMESTAMPVERIFIER
class TElMessageTimestampVerifier: public TElMessageProcessor
{
	private:
		SB_DISABLE_COPY(TElMessageTimestampVerifier)
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_Timestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		void initInstances();

	public:
		virtual int32_t Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Verify(TStream &InStream, TStream &OutStream, int64_t InCount);

		int32_t Verify(TStream *InStream, TStream *OutStream, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t VerifyDetached(void * Buffer, int32_t Size, void * Data, int32_t DataSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t VerifyDetached(TStream &InStream, TStream &DataStream, int64_t InCount, int64_t DataCount);

		int32_t VerifyDetached(TStream *InStream, TStream *DataStream, int64_t InCount, int64_t DataCount);
#endif /* SB_USE_CLASS_TSTREAM */

		static bool IsTimestampDetached(void * Timestamp, int32_t Size, std::string &DataURI, std::string &FileName);

		bool IsTimestampDetached_Inst(void * Timestamp, int32_t Size, std::string &DataURI, std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		static bool IsTimestampDetached(TStream &Timestamp, std::string &DataURI, std::string &FileName, int64_t Count);

		static bool IsTimestampDetached(TStream *Timestamp, std::string &DataURI, std::string &FileName, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool IsTimestampDetached_Inst(TStream &Timestamp, std::string &DataURI, std::string &FileName, int64_t Count);

		bool IsTimestampDetached_Inst(TStream *Timestamp, std::string &DataURI, std::string &FileName, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_Timestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_TimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TimestampCount, TElMessageTimestampVerifier, TimestampCount);

		virtual void get_DataURI(std::string &OutResult);

		virtual void get_FileName(std::string &OutResult);

		virtual void get_MediaType(std::string &OutResult);

		TElMessageTimestampVerifier(TElMessageTimestampVerifierHandle handle, TElOwnHandle ownHandle);

		explicit TElMessageTimestampVerifier(TComponent &AOwner);

		explicit TElMessageTimestampVerifier(TComponent *AOwner);

		virtual ~TElMessageTimestampVerifier();

};
#endif /* SB_USE_CLASS_TELMESSAGETIMESTAMPVERIFIER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBMESSAGES */

