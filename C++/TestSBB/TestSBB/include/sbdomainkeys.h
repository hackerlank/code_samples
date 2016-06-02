#ifndef __INC_SBDOMAINKEYS
#define __INC_SBDOMAINKEYS

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
#include "sbencoding.h"
#include "sbstreams.h"
#include "sbhashfunction.h"
#include "sbmath.h"
#include "sbmimeenc.h"
#include "sbmime.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_DK_DNS_ERROR_SUCCESS 	0
#define SB_DK_DNS_ERROR_NODATA 	1
#define SB_DK_DNS_ERROR_NOPARAMS 	2
#define SB_DK_DNS_ERROR_NOKEY 	3
#define SB_DK_DNS_ERROR_INVALID_KEYTYPE 	4
#define SB_DK_DNS_ERROR_INVALID_KEYDATA 	5
#define SB_DK_SIGNER_ERROR_SUCCESS 	0
#define SB_DK_SIGNER_ERROR_INVALID_STATE 	1
#define SB_DK_SIGNER_ERROR_INVALID_HEADER 	2
#define SB_DK_SIGNER_ERROR_EMPTY_HEADER 	3
#define SB_DK_SIGNER_ERROR_INVALID_SENDER 	4
#define SB_DK_SIGNER_ERROR_SEVERAL_SENDERS 	5
#define SB_DK_SIGNER_ERROR_NO_DOMAIN 	6
#define SB_DK_SIGNER_ERROR_NO_AUTHOR 	7
#define SB_DK_SIGNER_ERROR_NO_PRIVATE_KEY 	8
#define SB_DK_SIGNER_ERROR_NO_SELECTOR 	9
#define SB_DK_SIGNER_ERROR_FAILURE 	10
#define SB_DK_VERIFIER_ERROR_SUCCESS 	0
#define SB_DK_VERIFIER_ERROR_INVALID_STATE 	1
#define SB_DK_VERIFIER_ERROR_INVALID_HEADER 	2
#define SB_DK_VERIFIER_ERROR_NO_ADDRESS 	3
#define SB_DK_VERIFIER_ERROR_NO_SIGNATURE 	4
#define SB_DK_VERIFIER_ERROR_INVALID_FORMAT 	5
#define SB_DK_VERIFIER_ERROR_UNKNOWN_ALGORITHM 	6
#define SB_DK_VERIFIER_ERROR_FAILURE 	7
#define SB_DK_VERIFIER_ERROR_DOMAIN_MISMATCH 	8
#define SB_DK_VERIFIER_ERROR_INVALID_TIMESTAMP 	9
#define SB_DK_VERIFIER_ERROR_SIGNATURE_EXPIRED 	10
#define SB_SDKInvalidPrivateKey 	"Invalid private key"
#define SB_SDKInvalidSignerState 	"Cannot change property value in the current state"
#define SB_SDKCannotGenerateKey 	"Cannot generate DNS key"

typedef TElClassHandle TElDKPublicKeyHandle;

typedef TElDKPublicKeyHandle ElDKPublicKeyHandle;

typedef TElClassHandle TElDKRSAPublicKeyHandle;

typedef TElDKRSAPublicKeyHandle ElDKRSAPublicKeyHandle;

typedef TElClassHandle TElDKDNSRecordHandle;

typedef TElDKDNSRecordHandle ElDKDNSRecordHandle;

typedef TElClassHandle TElDomainKeysClassHandle;

typedef TElDomainKeysClassHandle ElDomainKeysClassHandle;

typedef TElClassHandle TElDomainKeysSignerHandle;

typedef TElDomainKeysSignerHandle ElDomainKeysSignerHandle;

typedef TElClassHandle TElDomainKeysVerifierHandle;

typedef TElDomainKeysVerifierHandle ElDomainKeysVerifierHandle;

typedef TElClassHandle TElDKSignatureHandle;

typedef TElDKSignatureHandle ElDKSignatureHandle;

typedef uint8_t TSBDKPublicKeyTypeRaw;

typedef enum
{
	dkRSA = 0
} TSBDKPublicKeyType;

typedef uint8_t TSBDKCanonicalizationAlgorithmRaw;

typedef enum
{
	dkSimple = 0,
	dkRelaxed = 1
} TSBDKCanonicalizationAlgorithm;

typedef uint8_t TSBDKDigestAlgorithmRaw;

typedef enum
{
	dkSHA1 = 0,
	dkSHA256 = 1
} TSBDKDigestAlgorithm;

typedef uint8_t TSBDKQueryTypeRaw;

typedef enum
{
	dkDNS = 0
} TSBDKQueryType;

typedef uint8_t TSBDKStatusRaw;

typedef enum
{
	dkNone = 0,
	dkGood = 1,
	dkBad = 2,
	dkNoKey = 3,
	dkRevoked = 4,
	dkNoSignature = 5,
	dkBadFormat = 6,
	dkNonParticipant = 7,
	dkUnknown = 8,
	dkExpired = 9,
	dkNotExact = 10,
	dkBadGranularity = 11
} TSBDKStatus;

typedef uint8_t TSBDomainKeysVerifierStateRaw;

typedef enum
{
	dkvHeaders = 0,
	dkvBody = 1
} TSBDomainKeysVerifierState;

typedef uint8_t TSBDomainKeysVerifierSignatureRaw;

typedef enum
{
	dkvSender = 0,
	dkvAuthor = 1
} TSBDomainKeysVerifierSignature;

typedef uint8_t TSBDomainKeysSignerStateRaw;

typedef enum
{
	dksHeaders = 0,
	dksBody = 1
} TSBDomainKeysSignerState;

#ifdef SB_USE_CLASS_TELDKPUBLICKEY
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_Assign(TElDKPublicKeyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_Clear(TElDKPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_Clone(TElDKPublicKeyHandle _Handle, TElDKPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_Revoke(TElDKPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_Load(TElDKPublicKeyHandle _Handle, const char * pcData, int32_t szData, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_Save(TElDKPublicKeyHandle _Handle, char * pcData, int32_t * szData, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_get_Available(TElDKPublicKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_get_KeyType(TElDKPublicKeyHandle _Handle, TSBDKPublicKeyTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_get_Revoked(TElDKPublicKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKPublicKey_Create(TElDKPublicKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELDKPUBLICKEY */

#ifdef SB_USE_CLASS_TELDKRSAPUBLICKEY
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_Assign(TElDKRSAPublicKeyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_Clear(TElDKRSAPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_Clone(TElDKRSAPublicKeyHandle _Handle, TElDKPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_Generate(TElDKRSAPublicKeyHandle _Handle, int32_t Bits, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_Load(TElDKRSAPublicKeyHandle _Handle, const char * pcData, int32_t szData, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_Save(TElDKRSAPublicKeyHandle _Handle, char * pcData, int32_t * szData, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_get_Exponent(TElDKRSAPublicKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_get_Modulus(TElDKRSAPublicKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKRSAPublicKey_Create(TElDKRSAPublicKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELDKRSAPUBLICKEY */

#ifdef SB_USE_CLASS_TELDKDNSRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_Assign(TElDKDNSRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_Clear(TElDKDNSRecordHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_CreatePublicKey(TElDKDNSRecordHandle _Handle, TSBDKPublicKeyTypeRaw KeyType);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_Load(TElDKDNSRecordHandle _Handle, const char * pcData, int32_t szData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_Save(TElDKDNSRecordHandle _Handle, char * pcData, int32_t * szData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_get_KeyGranularity(TElDKDNSRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_set_KeyGranularity(TElDKDNSRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_get_Notes(TElDKDNSRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_set_Notes(TElDKDNSRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_get_PublicKey(TElDKDNSRecordHandle _Handle, TElDKPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_get_TestMode(TElDKDNSRecordHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_set_TestMode(TElDKDNSRecordHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_get_ExactMode(TElDKDNSRecordHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_set_ExactMode(TElDKDNSRecordHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_get_ServiceType(TElDKDNSRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_set_ServiceType(TElDKDNSRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_get_Version(TElDKDNSRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_set_Version(TElDKDNSRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_get_Algorithms(TElDKDNSRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_set_Algorithms(TElDKDNSRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDKDNSRecord_Create(TElDKDNSRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDKDNSRECORD */

#ifdef SB_USE_CLASS_TELDOMAINKEYSCLASS
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysClass_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELDOMAINKEYSCLASS */

#ifdef SB_USE_CLASS_TELDOMAINKEYSSIGNER
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_AddHash(TElDomainKeysSignerHandle _Handle, void * Data, int32_t DataSize, int8_t BodyHash);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_CanonicalizeBody(TElDomainKeysSignerHandle _Handle, TStringsHandle Body, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_CanonicalizeHeader(TElDomainKeysSignerHandle _Handle, TStringsHandle Header, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_ClearPrivateKey(TElDomainKeysSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_GetHash(TElDomainKeysSignerHandle _Handle, TSBDKDigestAlgorithmRaw HashAlgorithm, int8_t BodyHash, uint8_t pHash[], int32_t * szHash, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_ProcessHeader(TElDomainKeysSignerHandle _Handle, TStringsHandle Header, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_ProcessBodyLine(TElDomainKeysSignerHandle _Handle, const char * pcS, int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_ProcessMessage(TElDomainKeysSignerHandle _Handle, const char * pcMessageText, int32_t szMessageText, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_Reset(TElDomainKeysSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_SetPrivateKey(TElDomainKeysSignerHandle _Handle, void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_SetPrivateKey_1(TElDomainKeysSignerHandle _Handle, void * Buffer, int32_t BufferSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_Sign(TElDomainKeysSignerHandle _Handle, TStringsHandle Signature, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_BodyCanonicalization(TElDomainKeysSignerHandle _Handle, TSBDKCanonicalizationAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_BodyCanonicalization(TElDomainKeysSignerHandle _Handle, TSBDKCanonicalizationAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_HeaderCanonicalization(TElDomainKeysSignerHandle _Handle, TSBDKCanonicalizationAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_HeaderCanonicalization(TElDomainKeysSignerHandle _Handle, TSBDKCanonicalizationAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_DigestAlgorithm(TElDomainKeysSignerHandle _Handle, TSBDKDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_DigestAlgorithm(TElDomainKeysSignerHandle _Handle, TSBDKDigestAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_Domain(TElDomainKeysSignerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_BodyHashLimit(TElDomainKeysSignerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_BodyHashLimit(TElDomainKeysSignerHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_HeaderFields(TElDomainKeysSignerHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_HeaderFields(TElDomainKeysSignerHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_HeaderFields(TElDomainKeysSignerHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_HeaderFields(TElDomainKeysSignerHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_QueryType(TElDomainKeysSignerHandle _Handle, TSBDKQueryTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_QueryType(TElDomainKeysSignerHandle _Handle, TSBDKQueryTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_Selector(TElDomainKeysSignerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_Selector(TElDomainKeysSignerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_SignatureAlgorithm(TElDomainKeysSignerHandle _Handle, TSBDKPublicKeyTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_SignatureAlgorithm(TElDomainKeysSignerHandle _Handle, TSBDKPublicKeyTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_SignatureExpiration(TElDomainKeysSignerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_SignatureExpiration(TElDomainKeysSignerHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_UseCopiedFields(TElDomainKeysSignerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_set_UseCopiedFields(TElDomainKeysSignerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_get_UserIdentity(TElDomainKeysSignerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysSigner_Create(TComponentHandle AOwner, TElDomainKeysSignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDOMAINKEYSSIGNER */

#ifdef SB_USE_CLASS_TELDOMAINKEYSVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_ProcessHeader(TElDomainKeysVerifierHandle _Handle, TStringsHandle Header, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_ProcessHeader_1(TElDomainKeysVerifierHandle _Handle, const char * pcSource, int32_t szSource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_ProcessBodyLine(TElDomainKeysVerifierHandle _Handle, const char * pcS, int32_t szS, int32_t SignatureIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_ProcessMessage(TElDomainKeysVerifierHandle _Handle, TStreamHandle Stream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_Verify(TElDomainKeysVerifierHandle _Handle, int32_t SigIndex, TElDKDNSRecordHandle DNSRec, TSBDKStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_Reset(TElDomainKeysVerifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_get_Signatures(TElDomainKeysVerifierHandle _Handle, int32_t Index, TElDKSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_get_SignaturesCount(TElDomainKeysVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDomainKeysVerifier_Create(TComponentHandle AOwner, TElDomainKeysVerifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELDOMAINKEYSVERIFIER */

#ifdef SB_USE_CLASS_TELDKSIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_Clear(TElDKSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_HashClear(TElDKSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_Verify(TElDKSignatureHandle _Handle, TElDKDNSRecordHandle DNS, TSBDKStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_Available(TElDKSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_HeaderCanonicalization(TElDKSignatureHandle _Handle, TSBDKCanonicalizationAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_BodyCanonicalization(TElDKSignatureHandle _Handle, TSBDKCanonicalizationAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_DigestAlgorithm(TElDKSignatureHandle _Handle, TSBDKDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_Domain(TElDKSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_set_Domain(TElDKSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_Address(TElDKSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_QueryType(TElDKSignatureHandle _Handle, TSBDKQueryTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_Selector(TElDKSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_SignatureAlgorithm(TElDKSignatureHandle _Handle, TSBDKPublicKeyTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_BodyHashLimit(TElDKSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_set_BodyHashLimit(TElDKSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_VerifierBodyHashLimit(TElDKSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_set_VerifierBodyHashLimit(TElDKSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_SignatureTime(TElDKSignatureHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_set_SignatureTime(TElDKSignatureHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_SignatureExpired(TElDKSignatureHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_set_SignatureExpired(TElDKSignatureHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_get_Hashed(TElDKSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_set_Hashed(TElDKSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDKSignature_Create(TElDKSignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELDKSIGNATURE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDKPublicKey;
typedef TElDKPublicKey ElDKPublicKey;
class TElDKRSAPublicKey;
typedef TElDKRSAPublicKey ElDKRSAPublicKey;
class TElDKDNSRecord;
typedef TElDKDNSRecord ElDKDNSRecord;
class TElDomainKeysClass;
typedef TElDomainKeysClass ElDomainKeysClass;
class TElDomainKeysSigner;
typedef TElDomainKeysSigner ElDomainKeysSigner;
class TElDomainKeysVerifier;
typedef TElDomainKeysVerifier ElDomainKeysVerifier;
class TElDKSignature;
typedef TElDKSignature ElDKSignature;

#ifdef SB_USE_CLASS_TELDKPUBLICKEY
class TElDKPublicKey: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDKPublicKey)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		virtual TElDKPublicKeyHandle Clone();

		void Revoke();

		virtual bool Load(const std::string &Data);

		virtual bool Save(std::string &Data);

		virtual bool get_Available();

		SB_DECLARE_PROPERTY_GET(bool, get_Available, TElDKPublicKey, Available);

		virtual TSBDKPublicKeyType get_KeyType();

		SB_DECLARE_PROPERTY_GET(TSBDKPublicKeyType, get_KeyType, TElDKPublicKey, KeyType);

		virtual bool get_Revoked();

		SB_DECLARE_PROPERTY_GET(bool, get_Revoked, TElDKPublicKey, Revoked);

		TElDKPublicKey(TElDKPublicKeyHandle handle, TElOwnHandle ownHandle);

		TElDKPublicKey();

};
#endif /* SB_USE_CLASS_TELDKPUBLICKEY */

#ifdef SB_USE_CLASS_TELDKRSAPUBLICKEY
class TElDKRSAPublicKey: public TElDKPublicKey
{
	private:
		SB_DISABLE_COPY(TElDKRSAPublicKey)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		virtual TElDKPublicKeyHandle Clone();

		void Generate(int32_t Bits, std::vector<uint8_t> &OutResult);

		virtual bool Load(const std::string &Data);

		virtual bool Save(std::string &Data);

		virtual void get_Exponent(std::vector<uint8_t> &OutResult);

		virtual void get_Modulus(std::vector<uint8_t> &OutResult);

		TElDKRSAPublicKey(TElDKRSAPublicKeyHandle handle, TElOwnHandle ownHandle);

		TElDKRSAPublicKey();

};
#endif /* SB_USE_CLASS_TELDKRSAPUBLICKEY */

#ifdef SB_USE_CLASS_TELDKDNSRECORD
class TElDKDNSRecord: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDKDNSRecord)
#ifdef SB_USE_CLASS_TELDKPUBLICKEY
		TElDKPublicKey* _Inst_PublicKey;
#endif /* SB_USE_CLASS_TELDKPUBLICKEY */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Clear();

		void CreatePublicKey(TSBDKPublicKeyType KeyType);

		int32_t Load(const std::string &Data);

		int32_t Save(std::string &Data);

		virtual void get_KeyGranularity(std::string &OutResult);

		virtual void set_KeyGranularity(const std::string &Value);

		virtual void get_Notes(std::string &OutResult);

		virtual void set_Notes(const std::string &Value);

#ifdef SB_USE_CLASS_TELDKPUBLICKEY
		virtual TElDKPublicKey* get_PublicKey();

		SB_DECLARE_PROPERTY_GET(TElDKPublicKey*, get_PublicKey, TElDKDNSRecord, PublicKey);
#endif /* SB_USE_CLASS_TELDKPUBLICKEY */

		virtual bool get_TestMode();

		virtual void set_TestMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TestMode, set_TestMode, TElDKDNSRecord, TestMode);

		virtual bool get_ExactMode();

		virtual void set_ExactMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ExactMode, set_ExactMode, TElDKDNSRecord, ExactMode);

		virtual void get_ServiceType(std::string &OutResult);

		virtual void set_ServiceType(const std::string &Value);

		virtual void get_Version(std::string &OutResult);

		virtual void set_Version(const std::string &Value);

		virtual void get_Algorithms(std::string &OutResult);

		virtual void set_Algorithms(const std::string &Value);

		TElDKDNSRecord(TElDKDNSRecordHandle handle, TElOwnHandle ownHandle);

		TElDKDNSRecord();

		virtual ~TElDKDNSRecord();

};
#endif /* SB_USE_CLASS_TELDKDNSRECORD */

#ifdef SB_USE_CLASS_TELDOMAINKEYSCLASS
class TElDomainKeysClass: public TComponent
{
	private:
		SB_DISABLE_COPY(TElDomainKeysClass)
	public:
		TElDomainKeysClass(TElDomainKeysClassHandle handle, TElOwnHandle ownHandle);

		explicit TElDomainKeysClass(TComponent &AOwner);

		explicit TElDomainKeysClass(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELDOMAINKEYSCLASS */

#ifdef SB_USE_CLASS_TELDOMAINKEYSSIGNER
class TElDomainKeysSigner: public TElDomainKeysClass
{
	private:
		SB_DISABLE_COPY(TElDomainKeysSigner)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_HeaderFields;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_HeaderFields;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		void AddHash(void * Data, int32_t DataSize, bool BodyHash);

#ifdef SB_USE_CLASS_TSTRINGS
		void CanonicalizeBody(TStrings &Body, std::string &OutResult);

		void CanonicalizeBody(TStrings *Body, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
		void CanonicalizeHeader(TStrings &Header, std::string &OutResult);

		void CanonicalizeHeader(TStrings *Header, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGS */

		void ClearPrivateKey();

		int32_t GetHash(TSBDKDigestAlgorithm HashAlgorithm, bool BodyHash, std::vector<uint8_t> &Hash);

#ifdef SB_USE_CLASS_TSTRINGS
		int32_t ProcessHeader(TStrings &Header);

		int32_t ProcessHeader(TStrings *Header);
#endif /* SB_USE_CLASS_TSTRINGS */

		int32_t ProcessBodyLine(const std::string &S);

		int32_t ProcessMessage(const std::string &MessageText);

		void Reset();

		bool SetPrivateKey(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize);

		bool SetPrivateKey(void * Buffer, int32_t BufferSize);

#ifdef SB_USE_CLASS_TSTRINGS
		int32_t Sign(TStrings &Signature);

		int32_t Sign(TStrings *Signature);
#endif /* SB_USE_CLASS_TSTRINGS */

		virtual TSBDKCanonicalizationAlgorithm get_BodyCanonicalization();

		virtual void set_BodyCanonicalization(TSBDKCanonicalizationAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBDKCanonicalizationAlgorithm, get_BodyCanonicalization, set_BodyCanonicalization, TElDomainKeysSigner, BodyCanonicalization);

		virtual TSBDKCanonicalizationAlgorithm get_HeaderCanonicalization();

		virtual void set_HeaderCanonicalization(TSBDKCanonicalizationAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBDKCanonicalizationAlgorithm, get_HeaderCanonicalization, set_HeaderCanonicalization, TElDomainKeysSigner, HeaderCanonicalization);

		virtual TSBDKDigestAlgorithm get_DigestAlgorithm();

		virtual void set_DigestAlgorithm(TSBDKDigestAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBDKDigestAlgorithm, get_DigestAlgorithm, set_DigestAlgorithm, TElDomainKeysSigner, DigestAlgorithm);

		virtual void get_Domain(std::string &OutResult);

		virtual void get_BodyHashLimit(std::string &OutResult);

		virtual void set_BodyHashLimit(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_HeaderFields();

		virtual void set_HeaderFields(TStringList &Value);

		virtual void set_HeaderFields(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_HeaderFields, set_HeaderFields, TElDomainKeysSigner, HeaderFields);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_HeaderFields();

		virtual void set_HeaderFields(TElStringList &Value);

		virtual void set_HeaderFields(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_HeaderFields, set_HeaderFields, TElDomainKeysSigner, HeaderFields);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TSBDKQueryType get_QueryType();

		virtual void set_QueryType(TSBDKQueryType Value);

		SB_DECLARE_PROPERTY(TSBDKQueryType, get_QueryType, set_QueryType, TElDomainKeysSigner, QueryType);

		virtual void get_Selector(std::string &OutResult);

		virtual void set_Selector(const std::string &Value);

		virtual TSBDKPublicKeyType get_SignatureAlgorithm();

		virtual void set_SignatureAlgorithm(TSBDKPublicKeyType Value);

		SB_DECLARE_PROPERTY(TSBDKPublicKeyType, get_SignatureAlgorithm, set_SignatureAlgorithm, TElDomainKeysSigner, SignatureAlgorithm);

		virtual int64_t get_SignatureExpiration();

		virtual void set_SignatureExpiration(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SignatureExpiration, set_SignatureExpiration, TElDomainKeysSigner, SignatureExpiration);

		virtual bool get_UseCopiedFields();

		virtual void set_UseCopiedFields(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCopiedFields, set_UseCopiedFields, TElDomainKeysSigner, UseCopiedFields);

		virtual void get_UserIdentity(std::string &OutResult);

		TElDomainKeysSigner(TElDomainKeysSignerHandle handle, TElOwnHandle ownHandle);

		explicit TElDomainKeysSigner(TComponent &AOwner);

		explicit TElDomainKeysSigner(TComponent *AOwner);

		virtual ~TElDomainKeysSigner();

};
#endif /* SB_USE_CLASS_TELDOMAINKEYSSIGNER */

#ifdef SB_USE_CLASS_TELDOMAINKEYSVERIFIER
class TElDomainKeysVerifier: public TElDomainKeysClass
{
	private:
		SB_DISABLE_COPY(TElDomainKeysVerifier)
#ifdef SB_USE_CLASS_TELDKSIGNATURE
		TElDKSignature* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELDKSIGNATURE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTRINGS
		int32_t ProcessHeader(TStrings &Header);

		int32_t ProcessHeader(TStrings *Header);
#endif /* SB_USE_CLASS_TSTRINGS */

		int32_t ProcessHeader(const std::string &Source);

		int32_t ProcessBodyLine(const std::string &S, int32_t SignatureIndex);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t ProcessMessage(TStream &Stream);

		int32_t ProcessMessage(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELDKDNSRECORD
		TSBDKStatus Verify(int32_t SigIndex, TElDKDNSRecord &DNSRec);

		TSBDKStatus Verify(int32_t SigIndex, TElDKDNSRecord *DNSRec);
#endif /* SB_USE_CLASS_TELDKDNSRECORD */

		void Reset();

#ifdef SB_USE_CLASS_TELDKSIGNATURE
		virtual TElDKSignature* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELDKSIGNATURE */

		virtual int32_t get_SignaturesCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignaturesCount, TElDomainKeysVerifier, SignaturesCount);

		TElDomainKeysVerifier(TElDomainKeysVerifierHandle handle, TElOwnHandle ownHandle);

		explicit TElDomainKeysVerifier(TComponent &AOwner);

		explicit TElDomainKeysVerifier(TComponent *AOwner);

		virtual ~TElDomainKeysVerifier();

};
#endif /* SB_USE_CLASS_TELDOMAINKEYSVERIFIER */

#ifdef SB_USE_CLASS_TELDKSIGNATURE
class TElDKSignature: public TObject
{
	private:
		SB_DISABLE_COPY(TElDKSignature)
	public:
		void Clear();

		void HashClear();

#ifdef SB_USE_CLASS_TELDKDNSRECORD
		TSBDKStatus Verify(TElDKDNSRecord &DNS);

		TSBDKStatus Verify(TElDKDNSRecord *DNS);
#endif /* SB_USE_CLASS_TELDKDNSRECORD */

		virtual bool get_Available();

		SB_DECLARE_PROPERTY_GET(bool, get_Available, TElDKSignature, Available);

		virtual TSBDKCanonicalizationAlgorithm get_HeaderCanonicalization();

		SB_DECLARE_PROPERTY_GET(TSBDKCanonicalizationAlgorithm, get_HeaderCanonicalization, TElDKSignature, HeaderCanonicalization);

		virtual TSBDKCanonicalizationAlgorithm get_BodyCanonicalization();

		SB_DECLARE_PROPERTY_GET(TSBDKCanonicalizationAlgorithm, get_BodyCanonicalization, TElDKSignature, BodyCanonicalization);

		virtual TSBDKDigestAlgorithm get_DigestAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBDKDigestAlgorithm, get_DigestAlgorithm, TElDKSignature, DigestAlgorithm);

		virtual void get_Domain(std::string &OutResult);

		virtual void set_Domain(const std::string &Value);

		virtual void get_Address(std::string &OutResult);

		virtual TSBDKQueryType get_QueryType();

		SB_DECLARE_PROPERTY_GET(TSBDKQueryType, get_QueryType, TElDKSignature, QueryType);

		virtual void get_Selector(std::string &OutResult);

		virtual TSBDKPublicKeyType get_SignatureAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBDKPublicKeyType, get_SignatureAlgorithm, TElDKSignature, SignatureAlgorithm);

		virtual void get_BodyHashLimit(std::string &OutResult);

		virtual void set_BodyHashLimit(const std::string &Value);

		virtual void get_VerifierBodyHashLimit(std::string &OutResult);

		virtual void set_VerifierBodyHashLimit(const std::string &Value);

		virtual int64_t get_SignatureTime();

		virtual void set_SignatureTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SignatureTime, set_SignatureTime, TElDKSignature, SignatureTime);

		virtual int64_t get_SignatureExpired();

		virtual void set_SignatureExpired(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SignatureExpired, set_SignatureExpired, TElDKSignature, SignatureExpired);

		virtual bool get_Hashed();

		virtual void set_Hashed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Hashed, set_Hashed, TElDKSignature, Hashed);

		TElDKSignature(TElDKSignatureHandle handle, TElOwnHandle ownHandle);

		TElDKSignature();

};
#endif /* SB_USE_CLASS_TELDKSIGNATURE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDOMAINKEYS */
