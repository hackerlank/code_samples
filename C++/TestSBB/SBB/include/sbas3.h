#ifndef __INC_SBAS3
#define __INC_SBAS3

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbcustomcertstorage.h"
#include "sbx509.h"
#include "sbsocket.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbsslclient.h"
#include "sbsimpleftps.h"
#include "sbmime.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssecconsts.h"
#include "sbdnssectypes.h"
#endif
#include "sbascommon.h"
#include "sbasutils.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElAS3ReceiptRequestHandle;

typedef TElClassHandle TElAS3EncryptionHandle;

typedef TElClassHandle TElAS3SignatureHandle;

typedef TElClassHandle TElAS3CompressionHandle;

typedef TElClassHandle TElAS3ReceiptHandle;

typedef TElClassHandle TElAS3MessageHandle;

typedef TElClassHandle TElAS3SocksOptionsHandle;

typedef TElClassHandle TElAS3SSLOptionsHandle;

typedef TElClassHandle TElAS3WebTunnelOptionsHandle;

typedef TElClassHandle TElAS3FTPOptionsHandle;

typedef TElClassHandle TElAS3ProxyOptionsHandle;

typedef TElClassHandle TElAS3SocketOptionsHandle;

typedef TElClassHandle TElAS3ClientHandle;

typedef uint8_t TSBAS3VersionRaw;

typedef enum
{
	as3Ver10 = 0,
	as3Ver11 = 1,
	as3Ver12 = 2
} TSBAS3Version;

#ifdef SB_USE_CLASS_TELAS3RECEIPTREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_Assign(TElAS3ReceiptRequestHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_get_DigestAlgorithm(TElAS3ReceiptRequestHandle _Handle, TSBASSignatureDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_set_DigestAlgorithm(TElAS3ReceiptRequestHandle _Handle, TSBASSignatureDigestAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_get_DigestAlgorithmOnly(TElAS3ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_set_DigestAlgorithmOnly(TElAS3ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_get_DigestAlgorithmRequired(TElAS3ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_set_DigestAlgorithmRequired(TElAS3ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_get_Enabled(TElAS3ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_set_Enabled(TElAS3ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_get_SignatureProtocolRequired(TElAS3ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_set_SignatureProtocolRequired(TElAS3ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_get_Signed(TElAS3ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_set_Signed(TElAS3ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_get_URL(TElAS3ReceiptRequestHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_set_URL(TElAS3ReceiptRequestHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ReceiptRequest_Create(TElAS3ReceiptRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS3ENCRYPTION
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_get_Algorithm(TElAS3EncryptionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_set_Algorithm(TElAS3EncryptionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_get_AlignEncryptedKey(TElAS3EncryptionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_set_AlignEncryptedKey(TElAS3EncryptionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_get_BitsInKey(TElAS3EncryptionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_set_BitsInKey(TElAS3EncryptionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_get_CertStorage(TElAS3EncryptionHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_set_CertStorage(TElAS3EncryptionHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_get_Enabled(TElAS3EncryptionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_set_Enabled(TElAS3EncryptionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_get_Encoding(TElAS3EncryptionHandle _Handle, TSBASEncryptionTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_set_Encoding(TElAS3EncryptionHandle _Handle, TSBASEncryptionTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_get_UseUndefSize(TElAS3EncryptionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_set_UseUndefSize(TElAS3EncryptionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Encryption_Create(TComponentHandle AOwner, TElASSMIMEEncryptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3ENCRYPTION */

#ifdef SB_USE_CLASS_TELAS3SIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_VerificationResult(TElAS3SignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_CertStorage(TElAS3SignatureHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_CertStorage(TElAS3SignatureHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_Compressed(TElAS3SignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_Compressed(TElAS3SignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_DigestAlgorithm(TElAS3SignatureHandle _Handle, TSBASSignatureDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_DigestAlgorithm(TElAS3SignatureHandle _Handle, TSBASSignatureDigestAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_Enabled(TElAS3SignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_Enabled(TElAS3SignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_Encoding(TElAS3SignatureHandle _Handle, TSBASSignatureTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_Encoding(TElAS3SignatureHandle _Handle, TSBASSignatureTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_IncludeChain(TElAS3SignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_IncludeChain(TElAS3SignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_Time(TElAS3SignatureHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_Time(TElAS3SignatureHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_UseUndefSize(TElAS3SignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_UseUndefSize(TElAS3SignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_get_VerificationOptions(TElAS3SignatureHandle _Handle, TSBASSMIMEVerificationOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_set_VerificationOptions(TElAS3SignatureHandle _Handle, TSBASSMIMEVerificationOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Signature_Create(TComponentHandle AOwner, TElASSMIMESignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

#ifdef SB_USE_CLASS_TELAS3COMPRESSION
SB_IMPORT uint32_t SB_APIENTRY TElAS3Compression_get_Enabled(TElAS3CompressionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Compression_set_Enabled(TElAS3CompressionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Compression_get_Encoding(TElAS3CompressionHandle _Handle, TSBASCompressionTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Compression_set_Encoding(TElAS3CompressionHandle _Handle, TSBASCompressionTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Compression_get_Level(TElAS3CompressionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Compression_set_Level(TElAS3CompressionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Compression_Create(TComponentHandle AOwner, TElASSMIMECompressionHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3COMPRESSION */

#ifdef SB_USE_CLASS_TELAS3RECEIPT
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_Assign(TElAS3ReceiptHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_Errors(TElAS3ReceiptHandle _Handle, TElASMessageErrorListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_ReceivedContentDigest(TElAS3ReceiptHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_ReceivedContentDigest(TElAS3ReceiptHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_ReceivedContentDigestAlgorithm(TElAS3ReceiptHandle _Handle, TSBASSignatureDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_ReceivedContentDigestAlgorithm(TElAS3ReceiptHandle _Handle, TSBASSignatureDigestAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_ActionMode(TElAS3ReceiptHandle _Handle, TSBASDispositionActionModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_ActionMode(TElAS3ReceiptHandle _Handle, TSBASDispositionActionModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_AS3From(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_AS3From(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_AS3To(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_AS3To(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_Date(TElAS3ReceiptHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_Date(TElAS3ReceiptHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_DetailedErrors(TElAS3ReceiptHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_DetailedErrors(TElAS3ReceiptHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_FinalRecipient(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_FinalRecipient(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_MDNGateway(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_MDNGateway(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_MessageID(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_MessageID(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OriginalMessageID(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OriginalMessageID(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OriginalRecipient(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OriginalRecipient(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_ReportCharset(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_ReportCharset(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_ReportCharsetMode(TElAS3ReceiptHandle _Handle, TSBASCharsetModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_ReportCharsetMode(TElAS3ReceiptHandle _Handle, TSBASCharsetModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_ReportEncoding(TElAS3ReceiptHandle _Handle, TSBASHeaderTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_ReportEncoding(TElAS3ReceiptHandle _Handle, TSBASHeaderTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_ReportingUA(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_ReportingUA(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_SendingMode(TElAS3ReceiptHandle _Handle, TSBASDispositionSendingModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_SendingMode(TElAS3ReceiptHandle _Handle, TSBASDispositionSendingModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_Signature(TElAS3ReceiptHandle _Handle, TElAS3SignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_Signature(TElAS3ReceiptHandle _Handle, TElAS3SignatureHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_SortErrors(TElAS3ReceiptHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_SortErrors(TElAS3ReceiptHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_Subject(TElAS3ReceiptHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_Subject(TElAS3ReceiptHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_Text(TElAS3ReceiptHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_Text(TElAS3ReceiptHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_TextCharset(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_TextCharset(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_TextCharsetMode(TElAS3ReceiptHandle _Handle, TSBASCharsetModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_TextCharsetMode(TElAS3ReceiptHandle _Handle, TSBASCharsetModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_TextContentType(TElAS3ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_TextContentType(TElAS3ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_TextEncoding(TElAS3ReceiptHandle _Handle, TSBASHeaderTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_TextEncoding(TElAS3ReceiptHandle _Handle, TSBASHeaderTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_Version(TElAS3ReceiptHandle _Handle, TSBAS3VersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_Version(TElAS3ReceiptHandle _Handle, TSBAS3VersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnError(TElAS3ReceiptHandle _Handle, TSBASReceiptErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnError(TElAS3ReceiptHandle _Handle, TSBASReceiptErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnHeaderAssembled(TElAS3ReceiptHandle _Handle, TSBASHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnHeaderAssembled(TElAS3ReceiptHandle _Handle, TSBASHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnHeaderParsed(TElAS3ReceiptHandle _Handle, TSBASHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnHeaderParsed(TElAS3ReceiptHandle _Handle, TSBASHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnSign(TElAS3ReceiptHandle _Handle, TSBASMessageSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnSign(TElAS3ReceiptHandle _Handle, TSBASMessageSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnSigning(TElAS3ReceiptHandle _Handle, TSBASMessageSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnSigning(TElAS3ReceiptHandle _Handle, TSBASMessageSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnStepStart(TElAS3ReceiptHandle _Handle, TSBASProcessingStepStart * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnStepStart(TElAS3ReceiptHandle _Handle, TSBASProcessingStepStart pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnVerify(TElAS3ReceiptHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnVerify(TElAS3ReceiptHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnVerifyIDs(TElAS3ReceiptHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnVerifyIDs(TElAS3ReceiptHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_get_OnVerifying(TElAS3ReceiptHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_set_OnVerifying(TElAS3ReceiptHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Receipt_Create(TComponentHandle AOwner, TElAS3ReceiptHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3RECEIPT */

#ifdef SB_USE_CLASS_TELAS3MESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_Assign(TElAS3MessageHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Cancelled(TElAS3MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_ContentDigest(TElAS3MessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_ContentDigestAlgorithm(TElAS3MessageHandle _Handle, TSBASSignatureDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Errors(TElAS3MessageHandle _Handle, TElASMessageErrorListHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Features(TElAS3MessageHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Features(TElAS3MessageHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_AS3From(TElAS3MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_AS3From(TElAS3MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_AS3To(TElAS3MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_AS3To(TElAS3MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Charset(TElAS3MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_Charset(TElAS3MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_CharsetMode(TElAS3MessageHandle _Handle, TSBASCharsetModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_CharsetMode(TElAS3MessageHandle _Handle, TSBASCharsetModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_ContentType(TElAS3MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_ContentType(TElAS3MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Compression(TElAS3MessageHandle _Handle, TElAS3CompressionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_Compression(TElAS3MessageHandle _Handle, TElAS3CompressionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_DataEncoding(TElAS3MessageHandle _Handle, TSBASDataTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_DataEncoding(TElAS3MessageHandle _Handle, TSBASDataTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Date(TElAS3MessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_Date(TElAS3MessageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Encryption(TElAS3MessageHandle _Handle, TElAS3EncryptionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_Encryption(TElAS3MessageHandle _Handle, TElAS3EncryptionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_FileCreated(TElAS3MessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_FileCreated(TElAS3MessageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_FileModified(TElAS3MessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_FileModified(TElAS3MessageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_FileName(TElAS3MessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_FileName(TElAS3MessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_HeaderEncoding(TElAS3MessageHandle _Handle, TSBASHeaderTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_HeaderEncoding(TElAS3MessageHandle _Handle, TSBASHeaderTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_IgnoreFileWarnings(TElAS3MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_IgnoreFileWarnings(TElAS3MessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_MessageID(TElAS3MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_MessageID(TElAS3MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_ReceiptRequest(TElAS3MessageHandle _Handle, TElAS3ReceiptRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_ReceiptRequest(TElAS3MessageHandle _Handle, TElAS3ReceiptRequestHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Signature(TElAS3MessageHandle _Handle, TElAS3SignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_Signature(TElAS3MessageHandle _Handle, TElAS3SignatureHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Subject(TElAS3MessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_Subject(TElAS3MessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_Version(TElAS3MessageHandle _Handle, TSBAS3VersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_Version(TElAS3MessageHandle _Handle, TSBAS3VersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnDecrypt(TElAS3MessageHandle _Handle, TSBASMessageDecryptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnDecrypt(TElAS3MessageHandle _Handle, TSBASMessageDecryptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnDecryptIDs(TElAS3MessageHandle _Handle, TSBASMessageDecryptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnDecryptIDs(TElAS3MessageHandle _Handle, TSBASMessageDecryptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnDecrypting(TElAS3MessageHandle _Handle, TSBASMessageDecryptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnDecrypting(TElAS3MessageHandle _Handle, TSBASMessageDecryptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnError(TElAS3MessageHandle _Handle, TSBASMessageErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnError(TElAS3MessageHandle _Handle, TSBASMessageErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnHeaderAssembled(TElAS3MessageHandle _Handle, TSBASHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnHeaderAssembled(TElAS3MessageHandle _Handle, TSBASHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnHeaderParsed(TElAS3MessageHandle _Handle, TSBASHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnHeaderParsed(TElAS3MessageHandle _Handle, TSBASHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnProgress(TElAS3MessageHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnProgress(TElAS3MessageHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnSign(TElAS3MessageHandle _Handle, TSBASMessageSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnSign(TElAS3MessageHandle _Handle, TSBASMessageSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnSigning(TElAS3MessageHandle _Handle, TSBASMessageSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnSigning(TElAS3MessageHandle _Handle, TSBASMessageSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnStepStart(TElAS3MessageHandle _Handle, TSBASProcessingStepStart * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnStepStart(TElAS3MessageHandle _Handle, TSBASProcessingStepStart pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnTempRelease(TElAS3MessageHandle _Handle, TSBASStreamReleaseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnTempRelease(TElAS3MessageHandle _Handle, TSBASStreamReleaseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnTempRequest(TElAS3MessageHandle _Handle, TSBASStreamRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnTempRequest(TElAS3MessageHandle _Handle, TSBASStreamRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnVerify(TElAS3MessageHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnVerify(TElAS3MessageHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnVerifyIDs(TElAS3MessageHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnVerifyIDs(TElAS3MessageHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_get_OnVerifying(TElAS3MessageHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_set_OnVerifying(TElAS3MessageHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Message_Create(TComponentHandle AOwner, TElAS3MessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3MESSAGE */

#ifdef SB_USE_CLASS_TELAS3SOCKSOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_Assign(TElAS3SocksOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_Authentication(TElAS3SocksOptionsHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_Authentication(TElAS3SocksOptionsHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_Enabled(TElAS3SocksOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_Enabled(TElAS3SocksOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_Host(TElAS3SocksOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_Host(TElAS3SocksOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_Password(TElAS3SocksOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_Password(TElAS3SocksOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_Port(TElAS3SocksOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_Port(TElAS3SocksOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_ResolveAddress(TElAS3SocksOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_ResolveAddress(TElAS3SocksOptionsHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_UseIPv6(TElAS3SocksOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_UseIPv6(TElAS3SocksOptionsHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_UserCode(TElAS3SocksOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_UserCode(TElAS3SocksOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_get_Version(TElAS3SocksOptionsHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_set_Version(TElAS3SocksOptionsHandle _Handle, TElSocksVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocksOptions_Create(TElSimpleFTPSClientHandle AClient, TElAS3SocksOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SSLOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_Assign(TElAS3SSLOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_InternalValidate(TElAS3SSLOptionsHandle _Handle, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_RenegotiateCiphers(TElAS3SSLOptionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_Active(TElAS3SSLOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_CurrentCipherSuite(TElAS3SSLOptionsHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_CurrentCompression(TElAS3SSLOptionsHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_CurrentVersion(TElAS3SSLOptionsHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_Extensions(TElAS3SSLOptionsHandle _Handle, TElClientSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_ServerExtensions(TElAS3SSLOptionsHandle _Handle, TElCustomSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_CipherSuitePriorities(TElAS3SSLOptionsHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_CipherSuitePriorities(TElAS3SSLOptionsHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_CipherSuites(TElAS3SSLOptionsHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_CipherSuites(TElAS3SSLOptionsHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_CompressionAlgorithms(TElAS3SSLOptionsHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_CompressionAlgorithms(TElAS3SSLOptionsHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_CertStorage(TElAS3SSLOptionsHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_CertStorage(TElAS3SSLOptionsHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_ClientCertStorage(TElAS3SSLOptionsHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_ClientCertStorage(TElAS3SSLOptionsHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_Enabled(TElAS3SSLOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_Enabled(TElAS3SSLOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_EncryptData(TElAS3SSLOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_EncryptData(TElAS3SSLOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_Mode(TElAS3SSLOptionsHandle _Handle, TSBSSLModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_Mode(TElAS3SSLOptionsHandle _Handle, TSBSSLModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_ResumeSessions(TElAS3SSLOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_ResumeSessions(TElAS3SSLOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_get_Versions(TElAS3SSLOptionsHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_set_Versions(TElAS3SSLOptionsHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SSLOptions_Create(TElSimpleFTPSClientHandle AClient, TElAS3SSLOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_Assign(TElAS3WebTunnelOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_get_ServerResult(TElAS3WebTunnelOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_get_Authentication(TElAS3WebTunnelOptionsHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_set_Authentication(TElAS3WebTunnelOptionsHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_get_Enabled(TElAS3WebTunnelOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_set_Enabled(TElAS3WebTunnelOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_get_Host(TElAS3WebTunnelOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_set_Host(TElAS3WebTunnelOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_get_Password(TElAS3WebTunnelOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_set_Password(TElAS3WebTunnelOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_get_Port(TElAS3WebTunnelOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_set_Port(TElAS3WebTunnelOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_get_UserID(TElAS3WebTunnelOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_set_UserID(TElAS3WebTunnelOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3WebTunnelOptions_Create(TElSimpleFTPSClientHandle AClient, TElAS3WebTunnelOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS */

#ifdef SB_USE_CLASS_TELAS3FTPOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_Assign(TElAS3FTPOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ExtMDTMSupported(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ExtMLSTSupported(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ExtRESTSupported(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ExtSIZESupported(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ExtXCRCSupported(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ExtXMD5Supported(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ExtXSHA1Supported(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_LastReply(TElAS3FTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ModeZSupported(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_AccountInfo(TElAS3FTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_AccountInfo(TElAS3FTPOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_AdjustPasvAddress(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_AdjustPasvAddress(TElAS3FTPOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_AuthCmd(TElAS3FTPOptionsHandle _Handle, TSBFTPAuthCmdRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_AuthCmd(TElAS3FTPOptionsHandle _Handle, TSBFTPAuthCmdRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_LocalCharset(TElAS3FTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_LocalCharset(TElAS3FTPOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ModeZ(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_ModeZ(TElAS3FTPOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_ModeZLevel(TElAS3FTPOptionsHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_ModeZLevel(TElAS3FTPOptionsHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_Options(TElAS3FTPOptionsHandle _Handle, TSBFTPOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_Options(TElAS3FTPOptionsHandle _Handle, TSBFTPOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_PassiveMode(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_PassiveMode(TElAS3FTPOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_Password(TElAS3FTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_Password(TElAS3FTPOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_RemoteCharset(TElAS3FTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_RemoteCharset(TElAS3FTPOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_TransferType(TElAS3FTPOptionsHandle _Handle, TSBFTPTransferTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_TransferType(TElAS3FTPOptionsHandle _Handle, TSBFTPTransferTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_UseFEATCmd(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_UseFEATCmd(TElAS3FTPOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_UserName(TElAS3FTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_UserName(TElAS3FTPOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_get_UseSIZECmd(TElAS3FTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_set_UseSIZECmd(TElAS3FTPOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3FTPOptions_Create(TElSimpleFTPSClientHandle AClient, TElAS3FTPOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3FTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS3PROXYOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_Assign(TElAS3ProxyOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_get_Host(TElAS3ProxyOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_set_Host(TElAS3ProxyOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_get_Password(TElAS3ProxyOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_set_Password(TElAS3ProxyOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_get_Port(TElAS3ProxyOptionsHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_set_Port(TElAS3ProxyOptionsHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_get_ProxyType(TElAS3ProxyOptionsHandle _Handle, TSBFTPProxyTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_set_ProxyType(TElAS3ProxyOptionsHandle _Handle, TSBFTPProxyTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_get_UserName(TElAS3ProxyOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_set_UserName(TElAS3ProxyOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3ProxyOptions_Create(TElSimpleFTPSClientHandle AClient, TElAS3ProxyOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SOCKETOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_Assign(TElAS3SocketOptionsHandle _Handle, TPersistentHandle Source);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_UsingIPv6(TElAS3SocketOptionsHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_Address(TElAS3SocketOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_Address(TElAS3SocketOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_BufferSize(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_BufferSize(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_CommandBinding(TElAS3SocketOptionsHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_CommandBinding(TElAS3SocketOptionsHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_ConcurrentConnections(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_ConcurrentConnections(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_DataBinding(TElAS3SocketOptionsHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_DataBinding(TElAS3SocketOptionsHandle _Handle, TElClientSocketBindingHandle Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_DNS(TElAS3SocketOptionsHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_DNS(TElAS3SocketOptionsHandle _Handle, TElDNSSettingsHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_IncomingSpeedLimit(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_IncomingSpeedLimit(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_ListenTimeout(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_ListenTimeout(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_MinSizeForConcurrentDownload(TElAS3SocketOptionsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_MinSizeForConcurrentDownload(TElAS3SocketOptionsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_OutgoingSpeedLimit(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_OutgoingSpeedLimit(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_Port(TElAS3SocketOptionsHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_Port(TElAS3SocketOptionsHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_Timeout(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_Timeout(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_TransferTimeout(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_TransferTimeout(TElAS3SocketOptionsHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_UseIPv6(TElAS3SocketOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_UseIPv6(TElAS3SocketOptionsHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_UseProxyForData(TElAS3SocketOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_UseProxyForData(TElAS3SocketOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_AutoAdjustBuffersSize(TElAS3SocketOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_AutoAdjustBuffersSize(TElAS3SocketOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_BuffersAdjustStep(TElAS3SocketOptionsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_BuffersAdjustStep(TElAS3SocketOptionsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_MaxBufferSize(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_MaxBufferSize(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_MinBufferSize(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_MinBufferSize(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_RecvBufferSize(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_RecvBufferSize(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_get_SendBufferSize(TElAS3SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_set_SendBufferSize(TElAS3SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3SocketOptions_Create(TElSimpleFTPSClientHandle AClient, TElAS3SocketOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS3CLIENT
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Abort(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Acct(TElAS3ClientHandle _Handle, const char * pcAcctInfo, int32_t szAcctInfo);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Allocate(TElAS3ClientHandle _Handle, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_CDUp(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_ClearCommandChannel(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_ClearCommandChannel_1(TElAS3ClientHandle _Handle, int8_t GracefulSSLClosure);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Close(TElAS3ClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Cwd(TElAS3ClientHandle _Handle, const char * pcAPath, int32_t szAPath);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Delete(TElAS3ClientHandle _Handle, const char * pcAFileName, int32_t szAFileName);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetCurrentDir(TElAS3ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetFileList(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetFileSize(TElAS3ClientHandle _Handle, const char * pcAFileName, int32_t szAFileName, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetFileTime(TElAS3ClientHandle _Handle, const char * pcAFileName, int32_t szAFileName, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetLocalChecksum(TElAS3ClientHandle _Handle, const char * pcAFileName, int32_t szAFileName, TSBFTPCheckMethodRaw CheckMethod, int64_t StartPoint, int64_t EndPoint, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetNameList(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetNameList_1(TElAS3ClientHandle _Handle, const char * pcParameters, int32_t szParameters);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetRemoteChecksum(TElAS3ClientHandle _Handle, const char * pcAFileName, int32_t szAFileName, TSBFTPCheckMethodRaw CheckMethod, int64_t StartPoint, int64_t EndPoint, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_GetServerSystem(TElAS3ClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_InternalValidate(TElAS3ClientHandle _Handle, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Login(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_MakeDir(TElAS3ClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_MLSD(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_MountStruct(TElAS3ClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_NoOp(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Open(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Receive(TElAS3ClientHandle _Handle, const char * pcFileName, int32_t szFileName, int64_t StartPos, int64_t EndPos);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Receive_1(TElAS3ClientHandle _Handle, const char * pcFileName, int32_t szFileName, TStreamHandle Stream, int64_t StartPos, int64_t EndPos);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Reinitialize(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_RemoveDir(TElAS3ClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Rename(TElAS3ClientHandle _Handle, const char * pcSourceFile, int32_t szSourceFile, const char * pcDestFile, int32_t szDestFile);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_RenegotiateCiphers(TElAS3ClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_SendCmd(TElAS3ClientHandle _Handle, const char * pcCommand, int32_t szCommand, const int16_t pAcceptCodes[], int32_t szAcceptCodes, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Send(TElAS3ClientHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, int64_t StartPos, int64_t EndPos, int8_t Append, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Send_1(TElAS3ClientHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Send_2(TElAS3ClientHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_FTP(TElAS3ClientHandle _Handle, TElAS3FTPOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_FTP(TElAS3ClientHandle _Handle, TElAS3FTPOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_Proxy(TElAS3ClientHandle _Handle, TElAS3ProxyOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_Proxy(TElAS3ClientHandle _Handle, TElAS3ProxyOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_Sockets(TElAS3ClientHandle _Handle, TElAS3SocketOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_Sockets(TElAS3ClientHandle _Handle, TElAS3SocketOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_Socks(TElAS3ClientHandle _Handle, TElAS3SocksOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_Socks(TElAS3ClientHandle _Handle, TElAS3SocksOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_SSL(TElAS3ClientHandle _Handle, TElAS3SSLOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_SSL(TElAS3ClientHandle _Handle, TElAS3SSLOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_WebTunnel(TElAS3ClientHandle _Handle, TElAS3WebTunnelOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_WebTunnel(TElAS3ClientHandle _Handle, TElAS3WebTunnelOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnBinaryData(TElAS3ClientHandle _Handle, TSBFTPSBinaryDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnBinaryData(TElAS3ClientHandle _Handle, TSBFTPSBinaryDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnCertificateNeededEx(TElAS3ClientHandle _Handle, TSBCertificateNeededExEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnCertificateNeededEx(TElAS3ClientHandle _Handle, TSBCertificateNeededExEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnCertificateStatus(TElAS3ClientHandle _Handle, TSBCertificateStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnCertificateStatus(TElAS3ClientHandle _Handle, TSBCertificateStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnCertificateValidate(TElAS3ClientHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnCertificateValidate(TElAS3ClientHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnCiphersNegotiated(TElAS3ClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnCiphersNegotiated(TElAS3ClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnControlSend(TElAS3ClientHandle _Handle, TSBFTPSTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnControlSend(TElAS3ClientHandle _Handle, TSBFTPSTextDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnControlReceive(TElAS3ClientHandle _Handle, TSBFTPSTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnControlReceive(TElAS3ClientHandle _Handle, TSBFTPSTextDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnError(TElAS3ClientHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnError(TElAS3ClientHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnExtensionsReceived(TElAS3ClientHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnExtensionsReceived(TElAS3ClientHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnExtensionsPrepared(TElAS3ClientHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnExtensionsPrepared(TElAS3ClientHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnInnerClientCreated(TElAS3ClientHandle _Handle, TSBFTPSInnerClientEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnInnerClientCreated(TElAS3ClientHandle _Handle, TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnInnerClientDestroyed(TElAS3ClientHandle _Handle, TSBFTPSInnerClientEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnInnerClientDestroyed(TElAS3ClientHandle _Handle, TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnInnerClientLoggedIn(TElAS3ClientHandle _Handle, TSBFTPSInnerClientEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnInnerClientLoggedIn(TElAS3ClientHandle _Handle, TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnKeyNeeded(TElAS3ClientHandle _Handle, TSBClientKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnKeyNeeded(TElAS3ClientHandle _Handle, TSBClientKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnProgress(TElAS3ClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnProgress(TElAS3ClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnTextDataLine(TElAS3ClientHandle _Handle, TSBFTPSTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnTextDataLine(TElAS3ClientHandle _Handle, TSBFTPSTextDataEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnDNSKeyNeded(TElAS3ClientHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnDNSKeyNeded(TElAS3ClientHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnDNSKeyValidate(TElAS3ClientHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnDNSKeyValidate(TElAS3ClientHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_get_OnDNSResolve(TElAS3ClientHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_set_OnDNSResolve(TElAS3ClientHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS3Client_Create(TComponentHandle AOwner, TElAS3ClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS3CLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElAS3ReceiptRequest;
class TElAS3Encryption;
class TElAS3Signature;
class TElAS3Compression;
class TElAS3Receipt;
class TElAS3Message;
class TElAS3SocksOptions;
class TElAS3SSLOptions;
class TElAS3WebTunnelOptions;
class TElAS3FTPOptions;
class TElAS3ProxyOptions;
class TElAS3SocketOptions;
class TElAS3Client;

#ifdef SB_USE_CLASS_TELAS3RECEIPTREQUEST
class TElAS3ReceiptRequest: public TElASReceiptRequest
{
	private:
		SB_DISABLE_COPY(TElAS3ReceiptRequest)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TSBASSignatureDigestAlgorithm get_DigestAlgorithm();

		virtual void set_DigestAlgorithm(TSBASSignatureDigestAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBASSignatureDigestAlgorithm, get_DigestAlgorithm, set_DigestAlgorithm, TElAS3ReceiptRequest, DigestAlgorithm);

		virtual bool get_DigestAlgorithmOnly();

		virtual void set_DigestAlgorithmOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DigestAlgorithmOnly, set_DigestAlgorithmOnly, TElAS3ReceiptRequest, DigestAlgorithmOnly);

		virtual bool get_DigestAlgorithmRequired();

		virtual void set_DigestAlgorithmRequired(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DigestAlgorithmRequired, set_DigestAlgorithmRequired, TElAS3ReceiptRequest, DigestAlgorithmRequired);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS3ReceiptRequest, Enabled);

		virtual bool get_SignatureProtocolRequired();

		virtual void set_SignatureProtocolRequired(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignatureProtocolRequired, set_SignatureProtocolRequired, TElAS3ReceiptRequest, SignatureProtocolRequired);

		virtual bool get_Signed();

		virtual void set_Signed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Signed, set_Signed, TElAS3ReceiptRequest, Signed);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		TElAS3ReceiptRequest(TElAS3ReceiptRequestHandle handle, TElOwnHandle ownHandle);

		TElAS3ReceiptRequest();

};
#endif /* SB_USE_CLASS_TELAS3RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS3ENCRYPTION
class TElAS3Encryption: public TElASSMIMEEncryption
{
	private:
		SB_DISABLE_COPY(TElAS3Encryption)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElAS3Encryption, Algorithm);

		virtual bool get_AlignEncryptedKey();

		virtual void set_AlignEncryptedKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AlignEncryptedKey, set_AlignEncryptedKey, TElAS3Encryption, AlignEncryptedKey);

		virtual int32_t get_BitsInKey();

		virtual void set_BitsInKey(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BitsInKey, set_BitsInKey, TElAS3Encryption, BitsInKey);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElAS3Encryption, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS3Encryption, Enabled);

		virtual TSBASEncryptionTransferEncoding get_Encoding();

		virtual void set_Encoding(TSBASEncryptionTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASEncryptionTransferEncoding, get_Encoding, set_Encoding, TElAS3Encryption, Encoding);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElAS3Encryption, UseUndefSize);

		TElAS3Encryption(TElAS3EncryptionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElAS3Encryption(TComponent &AOwner);

		explicit TElAS3Encryption(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

		virtual ~TElAS3Encryption();

};
#endif /* SB_USE_CLASS_TELAS3ENCRYPTION */

#ifdef SB_USE_CLASS_TELAS3SIGNATURE
class TElAS3Signature: public TElASSMIMESignature
{
	private:
		SB_DISABLE_COPY(TElAS3Signature)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		virtual int32_t get_VerificationResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_VerificationResult, TElAS3Signature, VerificationResult);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElAS3Signature, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_Compressed();

		virtual void set_Compressed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Compressed, set_Compressed, TElAS3Signature, Compressed);

		virtual TSBASSignatureDigestAlgorithm get_DigestAlgorithm();

		virtual void set_DigestAlgorithm(TSBASSignatureDigestAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBASSignatureDigestAlgorithm, get_DigestAlgorithm, set_DigestAlgorithm, TElAS3Signature, DigestAlgorithm);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS3Signature, Enabled);

		virtual TSBASSignatureTransferEncoding get_Encoding();

		virtual void set_Encoding(TSBASSignatureTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASSignatureTransferEncoding, get_Encoding, set_Encoding, TElAS3Signature, Encoding);

		virtual bool get_IncludeChain();

		virtual void set_IncludeChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeChain, set_IncludeChain, TElAS3Signature, IncludeChain);

		virtual int64_t get_Time();

		virtual void set_Time(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Time, set_Time, TElAS3Signature, Time);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElAS3Signature, UseUndefSize);

		virtual TSBASSMIMEVerificationOptions get_VerificationOptions();

		virtual void set_VerificationOptions(TSBASSMIMEVerificationOptions Value);

		SB_DECLARE_PROPERTY(TSBASSMIMEVerificationOptions, get_VerificationOptions, set_VerificationOptions, TElAS3Signature, VerificationOptions);

		TElAS3Signature(TElAS3SignatureHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElAS3Signature(TComponent &AOwner);

		explicit TElAS3Signature(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

		virtual ~TElAS3Signature();

};
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

#ifdef SB_USE_CLASS_TELAS3COMPRESSION
class TElAS3Compression: public TElASSMIMECompression
{
	private:
		SB_DISABLE_COPY(TElAS3Compression)
	public:
		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS3Compression, Enabled);

		virtual TSBASCompressionTransferEncoding get_Encoding();

		virtual void set_Encoding(TSBASCompressionTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASCompressionTransferEncoding, get_Encoding, set_Encoding, TElAS3Compression, Encoding);

		virtual int32_t get_Level();

		virtual void set_Level(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Level, set_Level, TElAS3Compression, Level);

		TElAS3Compression(TElAS3CompressionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElAS3Compression(TComponent &AOwner);

		explicit TElAS3Compression(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

};
#endif /* SB_USE_CLASS_TELAS3COMPRESSION */

#ifdef SB_USE_CLASS_TELAS3RECEIPT
class TElAS3Receipt: public TElASReceipt
{
	private:
		SB_DISABLE_COPY(TElAS3Receipt)
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
		TElASMessageErrorList* _Inst_Errors;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_USE_CLASS_TELAS3SIGNATURE
		TElAS3Signature* _Inst_Signature;
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
		virtual TElASMessageErrorList* get_Errors();

		SB_DECLARE_PROPERTY_GET(TElASMessageErrorList*, get_Errors, TElAS3Receipt, Errors);
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

		virtual void get_ReceivedContentDigest(std::vector<uint8_t> &OutResult);

		virtual void set_ReceivedContentDigest(const std::vector<uint8_t> &Value);

		virtual TSBASSignatureDigestAlgorithm get_ReceivedContentDigestAlgorithm();

		virtual void set_ReceivedContentDigestAlgorithm(TSBASSignatureDigestAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBASSignatureDigestAlgorithm, get_ReceivedContentDigestAlgorithm, set_ReceivedContentDigestAlgorithm, TElAS3Receipt, ReceivedContentDigestAlgorithm);

		virtual TSBASDispositionActionMode get_ActionMode();

		virtual void set_ActionMode(TSBASDispositionActionMode Value);

		SB_DECLARE_PROPERTY(TSBASDispositionActionMode, get_ActionMode, set_ActionMode, TElAS3Receipt, ActionMode);

		virtual void get_AS3From(std::string &OutResult);

		virtual void set_AS3From(const std::string &Value);

		virtual void get_AS3To(std::string &OutResult);

		virtual void set_AS3To(const std::string &Value);

		virtual int64_t get_Date();

		virtual void set_Date(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Date, set_Date, TElAS3Receipt, Date);

		virtual bool get_DetailedErrors();

		virtual void set_DetailedErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DetailedErrors, set_DetailedErrors, TElAS3Receipt, DetailedErrors);

		virtual void get_FinalRecipient(std::string &OutResult);

		virtual void set_FinalRecipient(const std::string &Value);

		virtual void get_MDNGateway(std::string &OutResult);

		virtual void set_MDNGateway(const std::string &Value);

		virtual void get_MessageID(std::string &OutResult);

		virtual void set_MessageID(const std::string &Value);

		virtual void get_OriginalMessageID(std::string &OutResult);

		virtual void set_OriginalMessageID(const std::string &Value);

		virtual void get_OriginalRecipient(std::string &OutResult);

		virtual void set_OriginalRecipient(const std::string &Value);

		virtual void get_ReportCharset(std::string &OutResult);

		virtual void set_ReportCharset(const std::string &Value);

		virtual TSBASCharsetMode get_ReportCharsetMode();

		virtual void set_ReportCharsetMode(TSBASCharsetMode Value);

		SB_DECLARE_PROPERTY(TSBASCharsetMode, get_ReportCharsetMode, set_ReportCharsetMode, TElAS3Receipt, ReportCharsetMode);

		virtual TSBASHeaderTransferEncoding get_ReportEncoding();

		virtual void set_ReportEncoding(TSBASHeaderTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASHeaderTransferEncoding, get_ReportEncoding, set_ReportEncoding, TElAS3Receipt, ReportEncoding);

		virtual void get_ReportingUA(std::string &OutResult);

		virtual void set_ReportingUA(const std::string &Value);

		virtual TSBASDispositionSendingMode get_SendingMode();

		virtual void set_SendingMode(TSBASDispositionSendingMode Value);

		SB_DECLARE_PROPERTY(TSBASDispositionSendingMode, get_SendingMode, set_SendingMode, TElAS3Receipt, SendingMode);

#ifdef SB_USE_CLASS_TELAS3SIGNATURE
		virtual TElAS3Signature* get_Signature();

		virtual void set_Signature(TElAS3Signature &Value);

		virtual void set_Signature(TElAS3Signature *Value);

		SB_DECLARE_PROPERTY(TElAS3Signature*, get_Signature, set_Signature, TElAS3Receipt, Signature);
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

		virtual bool get_SortErrors();

		virtual void set_SortErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SortErrors, set_SortErrors, TElAS3Receipt, SortErrors);

		virtual void get_Subject(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Subject(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Subject(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Subject(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Text(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Text(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Text(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Text(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_TextCharset(std::string &OutResult);

		virtual void set_TextCharset(const std::string &Value);

		virtual TSBASCharsetMode get_TextCharsetMode();

		virtual void set_TextCharsetMode(TSBASCharsetMode Value);

		SB_DECLARE_PROPERTY(TSBASCharsetMode, get_TextCharsetMode, set_TextCharsetMode, TElAS3Receipt, TextCharsetMode);

		virtual void get_TextContentType(std::string &OutResult);

		virtual void set_TextContentType(const std::string &Value);

		virtual TSBASHeaderTransferEncoding get_TextEncoding();

		virtual void set_TextEncoding(TSBASHeaderTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASHeaderTransferEncoding, get_TextEncoding, set_TextEncoding, TElAS3Receipt, TextEncoding);

		virtual TSBAS3Version get_Version();

		virtual void set_Version(TSBAS3Version Value);

		SB_DECLARE_PROPERTY(TSBAS3Version, get_Version, set_Version, TElAS3Receipt, Version);

		virtual void get_OnError(TSBASReceiptErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBASReceiptErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnHeaderAssembled(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHeaderAssembled(TSBASHeaderEvent pMethodValue, void * pDataValue);

		virtual void get_OnHeaderParsed(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHeaderParsed(TSBASHeaderEvent pMethodValue, void * pDataValue);

		virtual void get_OnSign(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSign(TSBASMessageSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnSigning(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSigning(TSBASMessageSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnStepStart(TSBASProcessingStepStart &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStepStart(TSBASProcessingStepStart pMethodValue, void * pDataValue);

		virtual void get_OnVerify(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerify(TSBASMessageVerifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifyIDs(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifyIDs(TSBASMessageVerifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifying(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifying(TSBASMessageVerifyEvent pMethodValue, void * pDataValue);

		TElAS3Receipt(TElAS3ReceiptHandle handle, TElOwnHandle ownHandle);

		explicit TElAS3Receipt(TComponent &AOwner);

		explicit TElAS3Receipt(TComponent *AOwner);

		virtual ~TElAS3Receipt();

};
#endif /* SB_USE_CLASS_TELAS3RECEIPT */

#ifdef SB_USE_CLASS_TELAS3MESSAGE
class TElAS3Message: public TElASMessage
{
	private:
		SB_DISABLE_COPY(TElAS3Message)
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
		TElASMessageErrorList* _Inst_Errors;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Features;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Features;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELAS3COMPRESSION
		TElAS3Compression* _Inst_Compression;
#endif /* SB_USE_CLASS_TELAS3COMPRESSION */
#ifdef SB_USE_CLASS_TELAS3ENCRYPTION
		TElAS3Encryption* _Inst_Encryption;
#endif /* SB_USE_CLASS_TELAS3ENCRYPTION */
#ifdef SB_USE_CLASS_TELAS3RECEIPTREQUEST
		TElAS3ReceiptRequest* _Inst_ReceiptRequest;
#endif /* SB_USE_CLASS_TELAS3RECEIPTREQUEST */
#ifdef SB_USE_CLASS_TELAS3SIGNATURE
		TElAS3Signature* _Inst_Signature;
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool get_Cancelled();

		SB_DECLARE_PROPERTY_GET(bool, get_Cancelled, TElAS3Message, Cancelled);

		virtual void get_ContentDigest(std::vector<uint8_t> &OutResult);

		virtual TSBASSignatureDigestAlgorithm get_ContentDigestAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBASSignatureDigestAlgorithm, get_ContentDigestAlgorithm, TElAS3Message, ContentDigestAlgorithm);

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
		virtual TElASMessageErrorList* get_Errors();

		SB_DECLARE_PROPERTY_GET(TElASMessageErrorList*, get_Errors, TElAS3Message, Errors);
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Features();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Features, TElAS3Message, Features);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Features();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Features, TElAS3Message, Features);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_AS3From(std::string &OutResult);

		virtual void set_AS3From(const std::string &Value);

		virtual void get_AS3To(std::string &OutResult);

		virtual void set_AS3To(const std::string &Value);

		virtual void get_Charset(std::string &OutResult);

		virtual void set_Charset(const std::string &Value);

		virtual TSBASCharsetMode get_CharsetMode();

		virtual void set_CharsetMode(TSBASCharsetMode Value);

		SB_DECLARE_PROPERTY(TSBASCharsetMode, get_CharsetMode, set_CharsetMode, TElAS3Message, CharsetMode);

		virtual void get_ContentType(std::string &OutResult);

		virtual void set_ContentType(const std::string &Value);

#ifdef SB_USE_CLASS_TELAS3COMPRESSION
		virtual TElAS3Compression* get_Compression();

		virtual void set_Compression(TElAS3Compression &Value);

		virtual void set_Compression(TElAS3Compression *Value);

		SB_DECLARE_PROPERTY(TElAS3Compression*, get_Compression, set_Compression, TElAS3Message, Compression);
#endif /* SB_USE_CLASS_TELAS3COMPRESSION */

		virtual TSBASDataTransferEncoding get_DataEncoding();

		virtual void set_DataEncoding(TSBASDataTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASDataTransferEncoding, get_DataEncoding, set_DataEncoding, TElAS3Message, DataEncoding);

		virtual int64_t get_Date();

		virtual void set_Date(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Date, set_Date, TElAS3Message, Date);

#ifdef SB_USE_CLASS_TELAS3ENCRYPTION
		virtual TElAS3Encryption* get_Encryption();

		virtual void set_Encryption(TElAS3Encryption &Value);

		virtual void set_Encryption(TElAS3Encryption *Value);

		SB_DECLARE_PROPERTY(TElAS3Encryption*, get_Encryption, set_Encryption, TElAS3Message, Encryption);
#endif /* SB_USE_CLASS_TELAS3ENCRYPTION */

		virtual int64_t get_FileCreated();

		virtual void set_FileCreated(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileCreated, set_FileCreated, TElAS3Message, FileCreated);

		virtual int64_t get_FileModified();

		virtual void set_FileModified(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileModified, set_FileModified, TElAS3Message, FileModified);

		virtual void get_FileName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FileName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_FileName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_FileName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TSBASHeaderTransferEncoding get_HeaderEncoding();

		virtual void set_HeaderEncoding(TSBASHeaderTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASHeaderTransferEncoding, get_HeaderEncoding, set_HeaderEncoding, TElAS3Message, HeaderEncoding);

		virtual bool get_IgnoreFileWarnings();

		virtual void set_IgnoreFileWarnings(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreFileWarnings, set_IgnoreFileWarnings, TElAS3Message, IgnoreFileWarnings);

		virtual void get_MessageID(std::string &OutResult);

		virtual void set_MessageID(const std::string &Value);

#ifdef SB_USE_CLASS_TELAS3RECEIPTREQUEST
		virtual TElAS3ReceiptRequest* get_ReceiptRequest();

		virtual void set_ReceiptRequest(TElAS3ReceiptRequest &Value);

		virtual void set_ReceiptRequest(TElAS3ReceiptRequest *Value);

		SB_DECLARE_PROPERTY(TElAS3ReceiptRequest*, get_ReceiptRequest, set_ReceiptRequest, TElAS3Message, ReceiptRequest);
#endif /* SB_USE_CLASS_TELAS3RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS3SIGNATURE
		virtual TElAS3Signature* get_Signature();

		virtual void set_Signature(TElAS3Signature &Value);

		virtual void set_Signature(TElAS3Signature *Value);

		SB_DECLARE_PROPERTY(TElAS3Signature*, get_Signature, set_Signature, TElAS3Message, Signature);
#endif /* SB_USE_CLASS_TELAS3SIGNATURE */

		virtual void get_Subject(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Subject(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Subject(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Subject(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TSBAS3Version get_Version();

		virtual void set_Version(TSBAS3Version Value);

		SB_DECLARE_PROPERTY(TSBAS3Version, get_Version, set_Version, TElAS3Message, Version);

		virtual void get_OnDecrypt(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecrypt(TSBASMessageDecryptEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptIDs(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptIDs(TSBASMessageDecryptEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecrypting(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecrypting(TSBASMessageDecryptEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBASMessageErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBASMessageErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnHeaderAssembled(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHeaderAssembled(TSBASHeaderEvent pMethodValue, void * pDataValue);

		virtual void get_OnHeaderParsed(TSBASHeaderEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHeaderParsed(TSBASHeaderEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnSign(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSign(TSBASMessageSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnSigning(TSBASMessageSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSigning(TSBASMessageSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnStepStart(TSBASProcessingStepStart &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStepStart(TSBASProcessingStepStart pMethodValue, void * pDataValue);

		virtual void get_OnTempRelease(TSBASStreamReleaseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTempRelease(TSBASStreamReleaseEvent pMethodValue, void * pDataValue);

		virtual void get_OnTempRequest(TSBASStreamRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTempRequest(TSBASStreamRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerify(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerify(TSBASMessageVerifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifyIDs(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifyIDs(TSBASMessageVerifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifying(TSBASMessageVerifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifying(TSBASMessageVerifyEvent pMethodValue, void * pDataValue);

		TElAS3Message(TElAS3MessageHandle handle, TElOwnHandle ownHandle);

		explicit TElAS3Message(TComponent &AOwner);

		explicit TElAS3Message(TComponent *AOwner);

		virtual ~TElAS3Message();

};
#endif /* SB_USE_CLASS_TELAS3MESSAGE */

#ifdef SB_USE_CLASS_TELAS3SOCKSOPTIONS
class TElAS3SocksOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS3SocksOptions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TElSocksAuthentication get_Authentication();

		virtual void set_Authentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_Authentication, set_Authentication, TElAS3SocksOptions, Authentication);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS3SocksOptions, Enabled);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElAS3SocksOptions, Port);

		virtual bool get_ResolveAddress();

		virtual void set_ResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ResolveAddress, set_ResolveAddress, TElAS3SocksOptions, ResolveAddress);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElAS3SocksOptions, UseIPv6);
#endif

		virtual void get_UserCode(std::string &OutResult);

		virtual void set_UserCode(const std::string &Value);

		virtual TElSocksVersion get_Version();

		virtual void set_Version(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_Version, set_Version, TElAS3SocksOptions, Version);

		TElAS3SocksOptions(TElAS3SocksOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
		explicit TElAS3SocksOptions(TElSimpleFTPSClient &AClient);

		explicit TElAS3SocksOptions(TElSimpleFTPSClient *AClient);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELAS3SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SSLOPTIONS
class TElAS3SSLOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS3SSLOptions)
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		TElClientSSLExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		TElCustomSSLExtensions* _Inst_ServerExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason);

		void RenegotiateCiphers();

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElAS3SSLOptions, Active);

		virtual uint8_t get_CurrentCipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CurrentCipherSuite, TElAS3SSLOptions, CurrentCipherSuite);

		virtual uint8_t get_CurrentCompression();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CurrentCompression, TElAS3SSLOptions, CurrentCompression);

		virtual TSBVersion get_CurrentVersion();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_CurrentVersion, TElAS3SSLOptions, CurrentVersion);

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		virtual TElClientSSLExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElClientSSLExtensions*, get_Extensions, TElAS3SSLOptions, Extensions);
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		virtual TElCustomSSLExtensions* get_ServerExtensions();

		SB_DECLARE_PROPERTY_GET(TElCustomSSLExtensions*, get_ServerExtensions, TElAS3SSLOptions, ServerExtensions);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

		virtual int32_t get_CipherSuitePriorities(uint8_t Index);

		virtual void set_CipherSuitePriorities(uint8_t Index, int32_t Value);

		virtual bool get_CipherSuites(uint8_t Index);

		virtual void set_CipherSuites(uint8_t Index, bool Value);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElAS3SSLOptions, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElAS3SSLOptions, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS3SSLOptions, Enabled);

		virtual bool get_EncryptData();

		virtual void set_EncryptData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncryptData, set_EncryptData, TElAS3SSLOptions, EncryptData);

		virtual TSBSSLMode get_Mode();

		virtual void set_Mode(TSBSSLMode Value);

		SB_DECLARE_PROPERTY(TSBSSLMode, get_Mode, set_Mode, TElAS3SSLOptions, Mode);

		virtual bool get_ResumeSessions();

		virtual void set_ResumeSessions(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ResumeSessions, set_ResumeSessions, TElAS3SSLOptions, ResumeSessions);

		virtual TSBVersions get_Versions();

		virtual void set_Versions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_Versions, set_Versions, TElAS3SSLOptions, Versions);

		TElAS3SSLOptions(TElAS3SSLOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
		explicit TElAS3SSLOptions(TElSimpleFTPSClient &AClient);

		explicit TElAS3SSLOptions(TElSimpleFTPSClient *AClient);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

		virtual ~TElAS3SSLOptions();

};
#endif /* SB_USE_CLASS_TELAS3SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS
class TElAS3WebTunnelOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS3WebTunnelOptions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual int32_t get_ServerResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ServerResult, TElAS3WebTunnelOptions, ServerResult);

		virtual TElWebTunnelAuthentication get_Authentication();

		virtual void set_Authentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_Authentication, set_Authentication, TElAS3WebTunnelOptions, Authentication);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS3WebTunnelOptions, Enabled);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElAS3WebTunnelOptions, Port);

		virtual void get_UserID(std::string &OutResult);

		virtual void set_UserID(const std::string &Value);

		TElAS3WebTunnelOptions(TElAS3WebTunnelOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
		explicit TElAS3WebTunnelOptions(TElSimpleFTPSClient &AClient);

		explicit TElAS3WebTunnelOptions(TElSimpleFTPSClient *AClient);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS */

#ifdef SB_USE_CLASS_TELAS3FTPOPTIONS
class TElAS3FTPOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS3FTPOptions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool get_ExtMDTMSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtMDTMSupported, TElAS3FTPOptions, ExtMDTMSupported);

		virtual bool get_ExtMLSTSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtMLSTSupported, TElAS3FTPOptions, ExtMLSTSupported);

		virtual bool get_ExtRESTSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtRESTSupported, TElAS3FTPOptions, ExtRESTSupported);

		virtual bool get_ExtSIZESupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtSIZESupported, TElAS3FTPOptions, ExtSIZESupported);

		virtual bool get_ExtXCRCSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtXCRCSupported, TElAS3FTPOptions, ExtXCRCSupported);

		virtual bool get_ExtXMD5Supported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtXMD5Supported, TElAS3FTPOptions, ExtXMD5Supported);

		virtual bool get_ExtXSHA1Supported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtXSHA1Supported, TElAS3FTPOptions, ExtXSHA1Supported);

		virtual void get_LastReply(std::string &OutResult);

		virtual bool get_ModeZSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ModeZSupported, TElAS3FTPOptions, ModeZSupported);

		virtual void get_AccountInfo(std::string &OutResult);

		virtual void set_AccountInfo(const std::string &Value);

		virtual bool get_AdjustPasvAddress();

		virtual void set_AdjustPasvAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AdjustPasvAddress, set_AdjustPasvAddress, TElAS3FTPOptions, AdjustPasvAddress);

		virtual TSBFTPAuthCmd get_AuthCmd();

		virtual void set_AuthCmd(TSBFTPAuthCmd Value);

		SB_DECLARE_PROPERTY(TSBFTPAuthCmd, get_AuthCmd, set_AuthCmd, TElAS3FTPOptions, AuthCmd);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

		virtual bool get_ModeZ();

		virtual void set_ModeZ(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ModeZ, set_ModeZ, TElAS3FTPOptions, ModeZ);

		virtual uint8_t get_ModeZLevel();

		virtual void set_ModeZLevel(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_ModeZLevel, set_ModeZLevel, TElAS3FTPOptions, ModeZLevel);

		virtual TSBFTPOptions get_Options();

		virtual void set_Options(TSBFTPOptions Value);

		SB_DECLARE_PROPERTY(TSBFTPOptions, get_Options, set_Options, TElAS3FTPOptions, Options);

		virtual bool get_PassiveMode();

		virtual void set_PassiveMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassiveMode, set_PassiveMode, TElAS3FTPOptions, PassiveMode);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		virtual TSBFTPTransferType get_TransferType();

		virtual void set_TransferType(TSBFTPTransferType Value);

		SB_DECLARE_PROPERTY(TSBFTPTransferType, get_TransferType, set_TransferType, TElAS3FTPOptions, TransferType);

		virtual bool get_UseFEATCmd();

		virtual void set_UseFEATCmd(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseFEATCmd, set_UseFEATCmd, TElAS3FTPOptions, UseFEATCmd);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		virtual bool get_UseSIZECmd();

		virtual void set_UseSIZECmd(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSIZECmd, set_UseSIZECmd, TElAS3FTPOptions, UseSIZECmd);

		TElAS3FTPOptions(TElAS3FTPOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
		explicit TElAS3FTPOptions(TElSimpleFTPSClient &AClient);

		explicit TElAS3FTPOptions(TElSimpleFTPSClient *AClient);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELAS3FTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS3PROXYOPTIONS
class TElAS3ProxyOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS3ProxyOptions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual uint16_t get_Port();

		virtual void set_Port(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Port, set_Port, TElAS3ProxyOptions, Port);

		virtual TSBFTPProxyType get_ProxyType();

		virtual void set_ProxyType(TSBFTPProxyType Value);

		SB_DECLARE_PROPERTY(TSBFTPProxyType, get_ProxyType, set_ProxyType, TElAS3ProxyOptions, ProxyType);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElAS3ProxyOptions(TElAS3ProxyOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
		explicit TElAS3ProxyOptions(TElSimpleFTPSClient &AClient);

		explicit TElAS3ProxyOptions(TElSimpleFTPSClient *AClient);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELAS3PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SOCKETOPTIONS
class TElAS3SocketOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS3SocketOptions)
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_CommandBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_DataBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		TElDNSSettings* _Inst_DNS;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElAS3SocketOptions, UsingIPv6);
#endif

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual int32_t get_BufferSize();

		virtual void set_BufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BufferSize, set_BufferSize, TElAS3SocketOptions, BufferSize);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_CommandBinding();

		virtual void set_CommandBinding(TElClientSocketBinding &Value);

		virtual void set_CommandBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_CommandBinding, set_CommandBinding, TElAS3SocketOptions, CommandBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		virtual int32_t get_ConcurrentConnections();

		virtual void set_ConcurrentConnections(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ConcurrentConnections, set_ConcurrentConnections, TElAS3SocketOptions, ConcurrentConnections);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_DataBinding();

		virtual void set_DataBinding(TElClientSocketBinding &Value);

		virtual void set_DataBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_DataBinding, set_DataBinding, TElAS3SocketOptions, DataBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElAS3SocketOptions, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElAS3SocketOptions, IncomingSpeedLimit);

		virtual int32_t get_ListenTimeout();

		virtual void set_ListenTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ListenTimeout, set_ListenTimeout, TElAS3SocketOptions, ListenTimeout);

		virtual int64_t get_MinSizeForConcurrentDownload();

		virtual void set_MinSizeForConcurrentDownload(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MinSizeForConcurrentDownload, set_MinSizeForConcurrentDownload, TElAS3SocketOptions, MinSizeForConcurrentDownload);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElAS3SocketOptions, OutgoingSpeedLimit);

		virtual uint16_t get_Port();

		virtual void set_Port(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Port, set_Port, TElAS3SocketOptions, Port);

		virtual int32_t get_Timeout();

		virtual void set_Timeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Timeout, set_Timeout, TElAS3SocketOptions, Timeout);

		virtual int32_t get_TransferTimeout();

		virtual void set_TransferTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TransferTimeout, set_TransferTimeout, TElAS3SocketOptions, TransferTimeout);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElAS3SocketOptions, UseIPv6);
#endif

		virtual bool get_UseProxyForData();

		virtual void set_UseProxyForData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseProxyForData, set_UseProxyForData, TElAS3SocketOptions, UseProxyForData);

		virtual bool get_AutoAdjustBuffersSize();

		virtual void set_AutoAdjustBuffersSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustBuffersSize, set_AutoAdjustBuffersSize, TElAS3SocketOptions, AutoAdjustBuffersSize);

		virtual double get_BuffersAdjustStep();

		virtual void set_BuffersAdjustStep(double Value);

		SB_DECLARE_PROPERTY(double, get_BuffersAdjustStep, set_BuffersAdjustStep, TElAS3SocketOptions, BuffersAdjustStep);

		virtual int32_t get_MaxBufferSize();

		virtual void set_MaxBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxBufferSize, set_MaxBufferSize, TElAS3SocketOptions, MaxBufferSize);

		virtual int32_t get_MinBufferSize();

		virtual void set_MinBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinBufferSize, set_MinBufferSize, TElAS3SocketOptions, MinBufferSize);

		virtual int32_t get_RecvBufferSize();

		virtual void set_RecvBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RecvBufferSize, set_RecvBufferSize, TElAS3SocketOptions, RecvBufferSize);

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElAS3SocketOptions, SendBufferSize);

		TElAS3SocketOptions(TElAS3SocketOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
		explicit TElAS3SocketOptions(TElSimpleFTPSClient &AClient);

		explicit TElAS3SocketOptions(TElSimpleFTPSClient *AClient);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

		virtual ~TElAS3SocketOptions();

};
#endif /* SB_USE_CLASS_TELAS3SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS3CLIENT
class TElAS3Client: public TComponent
{
	private:
		SB_DISABLE_COPY(TElAS3Client)
#ifdef SB_USE_CLASS_TELAS3FTPOPTIONS
		TElAS3FTPOptions* _Inst_FTP;
#endif /* SB_USE_CLASS_TELAS3FTPOPTIONS */
#ifdef SB_USE_CLASS_TELAS3PROXYOPTIONS
		TElAS3ProxyOptions* _Inst_Proxy;
#endif /* SB_USE_CLASS_TELAS3PROXYOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SOCKETOPTIONS
		TElAS3SocketOptions* _Inst_Sockets;
#endif /* SB_USE_CLASS_TELAS3SOCKETOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SOCKSOPTIONS
		TElAS3SocksOptions* _Inst_Socks;
#endif /* SB_USE_CLASS_TELAS3SOCKSOPTIONS */
#ifdef SB_USE_CLASS_TELAS3SSLOPTIONS
		TElAS3SSLOptions* _Inst_SSL;
#endif /* SB_USE_CLASS_TELAS3SSLOPTIONS */
#ifdef SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS
		TElAS3WebTunnelOptions* _Inst_WebTunnel;
#endif /* SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS */

		void initInstances();

	public:
		void Abort();

		void Acct(const std::string &AcctInfo);

		void Allocate(int32_t Size);

		void CDUp();

		void ClearCommandChannel();

		void ClearCommandChannel(bool GracefulSSLClosure);

		void Close(bool Silent);

		void Cwd(const std::string &APath);

		void Delete(const std::string &AFileName);

		void GetCurrentDir(std::string &OutResult);

		void GetFileList();

		int64_t GetFileSize(const std::string &AFileName);

		int64_t GetFileTime(const std::string &AFileName);

		void GetLocalChecksum(const std::string &AFileName, TSBFTPCheckMethod CheckMethod, int64_t StartPoint, int64_t EndPoint, std::string &OutResult);

		void GetNameList();

		void GetNameList(const std::string &Parameters);

		void GetRemoteChecksum(const std::string &AFileName, TSBFTPCheckMethod CheckMethod, int64_t StartPoint, int64_t EndPoint, std::string &OutResult);

		void GetServerSystem(std::string &OutResult);

		void InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason);

		void Login();

		void MakeDir(const std::string &Path);

		void MLSD();

		void MountStruct(const std::string &Path);

		void NoOp();

		void Open();

		void Receive(const std::string &FileName, int64_t StartPos, int64_t EndPos);

#ifdef SB_USE_CLASS_TSTREAM
		void Receive(const std::string &FileName, TStream &Stream, int64_t StartPos, int64_t EndPos);

		void Receive(const std::string &FileName, TStream *Stream, int64_t StartPos, int64_t EndPos);
#endif /* SB_USE_CLASS_TSTREAM */

		void Reinitialize();

		void RemoveDir(const std::string &Path);

		void Rename(const std::string &SourceFile, const std::string &DestFile);

		void RenegotiateCiphers();

		int16_t SendCmd(const std::string &Command, const std::vector<int16_t> &AcceptCodes);

#ifdef SB_USE_CLASS_TSTREAM
		void Send(TStream &Stream, const std::string &FileName, int64_t StartPos, int64_t EndPos, bool Append, int64_t RestartFrom);

		void Send(TStream *Stream, const std::string &FileName, int64_t StartPos, int64_t EndPos, bool Append, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Send(TStream &Stream, const std::string &FileName, int64_t RestartFrom);

		void Send(TStream *Stream, const std::string &FileName, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Send(TStream &Stream, const std::string &FileName);

		void Send(TStream *Stream, const std::string &FileName);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELAS3FTPOPTIONS
		virtual TElAS3FTPOptions* get_FTP();

		virtual void set_FTP(TElAS3FTPOptions &Value);

		virtual void set_FTP(TElAS3FTPOptions *Value);

		SB_DECLARE_PROPERTY(TElAS3FTPOptions*, get_FTP, set_FTP, TElAS3Client, FTP);
#endif /* SB_USE_CLASS_TELAS3FTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS3PROXYOPTIONS
		virtual TElAS3ProxyOptions* get_Proxy();

		virtual void set_Proxy(TElAS3ProxyOptions &Value);

		virtual void set_Proxy(TElAS3ProxyOptions *Value);

		SB_DECLARE_PROPERTY(TElAS3ProxyOptions*, get_Proxy, set_Proxy, TElAS3Client, Proxy);
#endif /* SB_USE_CLASS_TELAS3PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SOCKETOPTIONS
		virtual TElAS3SocketOptions* get_Sockets();

		virtual void set_Sockets(TElAS3SocketOptions &Value);

		virtual void set_Sockets(TElAS3SocketOptions *Value);

		SB_DECLARE_PROPERTY(TElAS3SocketOptions*, get_Sockets, set_Sockets, TElAS3Client, Sockets);
#endif /* SB_USE_CLASS_TELAS3SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SOCKSOPTIONS
		virtual TElAS3SocksOptions* get_Socks();

		virtual void set_Socks(TElAS3SocksOptions &Value);

		virtual void set_Socks(TElAS3SocksOptions *Value);

		SB_DECLARE_PROPERTY(TElAS3SocksOptions*, get_Socks, set_Socks, TElAS3Client, Socks);
#endif /* SB_USE_CLASS_TELAS3SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS3SSLOPTIONS
		virtual TElAS3SSLOptions* get_SSL();

		virtual void set_SSL(TElAS3SSLOptions &Value);

		virtual void set_SSL(TElAS3SSLOptions *Value);

		SB_DECLARE_PROPERTY(TElAS3SSLOptions*, get_SSL, set_SSL, TElAS3Client, SSL);
#endif /* SB_USE_CLASS_TELAS3SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS
		virtual TElAS3WebTunnelOptions* get_WebTunnel();

		virtual void set_WebTunnel(TElAS3WebTunnelOptions &Value);

		virtual void set_WebTunnel(TElAS3WebTunnelOptions *Value);

		SB_DECLARE_PROPERTY(TElAS3WebTunnelOptions*, get_WebTunnel, set_WebTunnel, TElAS3Client, WebTunnel);
#endif /* SB_USE_CLASS_TELAS3WEBTUNNELOPTIONS */

		virtual void get_OnBinaryData(TSBFTPSBinaryDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBinaryData(TSBFTPSBinaryDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnControlSend(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnControlSend(TSBFTPSTextDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnControlReceive(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnControlReceive(TSBFTPSTextDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnInnerClientCreated(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInnerClientCreated(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);

		virtual void get_OnInnerClientDestroyed(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInnerClientDestroyed(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);

		virtual void get_OnInnerClientLoggedIn(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInnerClientLoggedIn(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnTextDataLine(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTextDataLine(TSBFTPSTextDataEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSKeyNeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElAS3Client(TElAS3ClientHandle handle, TElOwnHandle ownHandle);

		explicit TElAS3Client(TComponent &AOwner);

		explicit TElAS3Client(TComponent *AOwner);

		virtual ~TElAS3Client();

};
#endif /* SB_USE_CLASS_TELAS3CLIENT */

#ifdef SB_USE_GLOBAL_PROCS_AS3

bool AS3NameNeedsQuoting(const std::string &AS3Name);

void DequoteAS3Name(const std::string &Value, std::string &OutResult);

void QuoteAS3Name(const std::string &AS3Name, std::string &OutResult);

bool ValidAS3Name(const std::string &Name);

#endif /* SB_USE_GLOBAL_PROCS_AS3 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_AS3
SB_IMPORT uint32_t SB_APIENTRY SBAS3_AS3NameNeedsQuoting(const char * pcAS3Name, int32_t szAS3Name, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAS3_DequoteAS3Name(const char * pcValue, int32_t szValue, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAS3_QuoteAS3Name(const char * pcAS3Name, int32_t szAS3Name, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAS3_ValidAS3Name(const char * pcName, int32_t szName, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_AS3 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBAS3 */
