#ifndef __INC_SBAS2
#define __INC_SBAS2

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbconstants.h"
#include "sbsocket.h"
#include "sbcustomcertstorage.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbsslclient.h"
#include "sbx509.h"
#include "sbmime.h"
#include "sbhttpscommon.h"
#include "sbhttpsclient.h"
#include "sbhttpsconstants.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssecconsts.h"
#include "sbdnssectypes.h"
#endif
#include "sbascommon.h"
#include "sbasutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElAS2ReceiptRequestHandle;

typedef TElClassHandle TElAS2EncryptionHandle;

typedef TElClassHandle TElAS2SignatureHandle;

typedef TElClassHandle TElAS2CompressionHandle;

typedef TElClassHandle TElAS2ReceiptHandle;

typedef TElClassHandle TElAS2MessageHandle;

typedef TElClassHandle TElAS2HTTPOptionsHandle;

typedef TElClassHandle TElAS2ProxyOptionsHandle;

typedef TElClassHandle TElAS2SocketOptionsHandle;

typedef TElClassHandle TElAS2SocksOptionsHandle;

typedef TElClassHandle TElAS2SSLOptionsHandle;

typedef TElClassHandle TElAS2WebTunnelOptionsHandle;

typedef TElClassHandle TElAS2ClientHandle;

typedef uint8_t TSBAS2VersionRaw;

typedef enum
{
	as2Ver10 = 0,
	as2Ver11 = 1,
	as2Ver12 = 2
} TSBAS2Version;

#ifdef SB_USE_CLASS_TELAS2RECEIPTREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_Assign(TElAS2ReceiptRequestHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_get_AsyncReceipt(TElAS2ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_set_AsyncReceipt(TElAS2ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_get_DigestAlgorithm(TElAS2ReceiptRequestHandle _Handle, TSBASSignatureDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_set_DigestAlgorithm(TElAS2ReceiptRequestHandle _Handle, TSBASSignatureDigestAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_get_DigestAlgorithmOnly(TElAS2ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_set_DigestAlgorithmOnly(TElAS2ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_get_DigestAlgorithmRequired(TElAS2ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_set_DigestAlgorithmRequired(TElAS2ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_get_Enabled(TElAS2ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_set_Enabled(TElAS2ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_get_SignatureProtocolRequired(TElAS2ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_set_SignatureProtocolRequired(TElAS2ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_get_Signed(TElAS2ReceiptRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_set_Signed(TElAS2ReceiptRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_get_URL(TElAS2ReceiptRequestHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_set_URL(TElAS2ReceiptRequestHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ReceiptRequest_Create(TElAS2ReceiptRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS2ENCRYPTION
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_get_Algorithm(TElAS2EncryptionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_set_Algorithm(TElAS2EncryptionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_get_AlignEncryptedKey(TElAS2EncryptionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_set_AlignEncryptedKey(TElAS2EncryptionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_get_BitsInKey(TElAS2EncryptionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_set_BitsInKey(TElAS2EncryptionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_get_CertStorage(TElAS2EncryptionHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_set_CertStorage(TElAS2EncryptionHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_get_Enabled(TElAS2EncryptionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_set_Enabled(TElAS2EncryptionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_get_Encoding(TElAS2EncryptionHandle _Handle, TSBASEncryptionTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_set_Encoding(TElAS2EncryptionHandle _Handle, TSBASEncryptionTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_get_UseUndefSize(TElAS2EncryptionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_set_UseUndefSize(TElAS2EncryptionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Encryption_Create(TComponentHandle AOwner, TElASSMIMEEncryptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2ENCRYPTION */

#ifdef SB_USE_CLASS_TELAS2SIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_VerificationResult(TElAS2SignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_CertStorage(TElAS2SignatureHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_CertStorage(TElAS2SignatureHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_Compressed(TElAS2SignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_Compressed(TElAS2SignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_DigestAlgorithm(TElAS2SignatureHandle _Handle, TSBASSignatureDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_DigestAlgorithm(TElAS2SignatureHandle _Handle, TSBASSignatureDigestAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_Enabled(TElAS2SignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_Enabled(TElAS2SignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_Encoding(TElAS2SignatureHandle _Handle, TSBASSignatureTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_Encoding(TElAS2SignatureHandle _Handle, TSBASSignatureTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_IncludeChain(TElAS2SignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_IncludeChain(TElAS2SignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_Time(TElAS2SignatureHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_Time(TElAS2SignatureHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_UseUndefSize(TElAS2SignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_UseUndefSize(TElAS2SignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_get_VerificationOptions(TElAS2SignatureHandle _Handle, TSBASSMIMEVerificationOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_set_VerificationOptions(TElAS2SignatureHandle _Handle, TSBASSMIMEVerificationOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Signature_Create(TComponentHandle AOwner, TElASSMIMESignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

#ifdef SB_USE_CLASS_TELAS2COMPRESSION
SB_IMPORT uint32_t SB_APIENTRY TElAS2Compression_get_Enabled(TElAS2CompressionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Compression_set_Enabled(TElAS2CompressionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Compression_get_Encoding(TElAS2CompressionHandle _Handle, TSBASCompressionTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Compression_set_Encoding(TElAS2CompressionHandle _Handle, TSBASCompressionTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Compression_get_Level(TElAS2CompressionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Compression_set_Level(TElAS2CompressionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Compression_Create(TComponentHandle AOwner, TElASSMIMECompressionHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2COMPRESSION */

#ifdef SB_USE_CLASS_TELAS2RECEIPT
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_Assign(TElAS2ReceiptHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_Errors(TElAS2ReceiptHandle _Handle, TElASMessageErrorListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_ReceivedContentDigest(TElAS2ReceiptHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_ReceivedContentDigest(TElAS2ReceiptHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_ReceivedContentDigestAlgorithm(TElAS2ReceiptHandle _Handle, TSBASSignatureDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_ReceivedContentDigestAlgorithm(TElAS2ReceiptHandle _Handle, TSBASSignatureDigestAlgorithmRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_ActionMode(TElAS2ReceiptHandle _Handle, TSBASDispositionActionModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_ActionMode(TElAS2ReceiptHandle _Handle, TSBASDispositionActionModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_AS2From(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_AS2From(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_AS2To(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_AS2To(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_Date(TElAS2ReceiptHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_Date(TElAS2ReceiptHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_DetailedErrors(TElAS2ReceiptHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_DetailedErrors(TElAS2ReceiptHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_FinalRecipient(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_FinalRecipient(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_MDNGateway(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_MDNGateway(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_MessageID(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_MessageID(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OriginalMessageID(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OriginalMessageID(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OriginalRecipient(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OriginalRecipient(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_ReportCharset(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_ReportCharset(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_ReportCharsetMode(TElAS2ReceiptHandle _Handle, TSBASCharsetModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_ReportCharsetMode(TElAS2ReceiptHandle _Handle, TSBASCharsetModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_ReportEncoding(TElAS2ReceiptHandle _Handle, TSBASHeaderTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_ReportEncoding(TElAS2ReceiptHandle _Handle, TSBASHeaderTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_ReportingUA(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_ReportingUA(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_SendingMode(TElAS2ReceiptHandle _Handle, TSBASDispositionSendingModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_SendingMode(TElAS2ReceiptHandle _Handle, TSBASDispositionSendingModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_Signature(TElAS2ReceiptHandle _Handle, TElAS2SignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_Signature(TElAS2ReceiptHandle _Handle, TElAS2SignatureHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_SortErrors(TElAS2ReceiptHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_SortErrors(TElAS2ReceiptHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_Subject(TElAS2ReceiptHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_Subject(TElAS2ReceiptHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_Text(TElAS2ReceiptHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_Text(TElAS2ReceiptHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_TextCharset(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_TextCharset(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_TextCharsetMode(TElAS2ReceiptHandle _Handle, TSBASCharsetModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_TextCharsetMode(TElAS2ReceiptHandle _Handle, TSBASCharsetModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_TextContentType(TElAS2ReceiptHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_TextContentType(TElAS2ReceiptHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_TextEncoding(TElAS2ReceiptHandle _Handle, TSBASHeaderTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_TextEncoding(TElAS2ReceiptHandle _Handle, TSBASHeaderTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_UseFolding(TElAS2ReceiptHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_UseFolding(TElAS2ReceiptHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_Version(TElAS2ReceiptHandle _Handle, TSBAS2VersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_Version(TElAS2ReceiptHandle _Handle, TSBAS2VersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnError(TElAS2ReceiptHandle _Handle, TSBASReceiptErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnError(TElAS2ReceiptHandle _Handle, TSBASReceiptErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnHeaderAssembled(TElAS2ReceiptHandle _Handle, TSBASHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnHeaderAssembled(TElAS2ReceiptHandle _Handle, TSBASHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnHeaderParsed(TElAS2ReceiptHandle _Handle, TSBASHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnHeaderParsed(TElAS2ReceiptHandle _Handle, TSBASHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnSign(TElAS2ReceiptHandle _Handle, TSBASMessageSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnSign(TElAS2ReceiptHandle _Handle, TSBASMessageSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnSigning(TElAS2ReceiptHandle _Handle, TSBASMessageSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnSigning(TElAS2ReceiptHandle _Handle, TSBASMessageSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnStepStart(TElAS2ReceiptHandle _Handle, TSBASProcessingStepStart * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnStepStart(TElAS2ReceiptHandle _Handle, TSBASProcessingStepStart pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnVerify(TElAS2ReceiptHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnVerify(TElAS2ReceiptHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnVerifyIDs(TElAS2ReceiptHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnVerifyIDs(TElAS2ReceiptHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_get_OnVerifying(TElAS2ReceiptHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_set_OnVerifying(TElAS2ReceiptHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Receipt_Create(TComponentHandle AOwner, TElAS2ReceiptHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2RECEIPT */

#ifdef SB_USE_CLASS_TELAS2MESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_Assign(TElAS2MessageHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Cancelled(TElAS2MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_ContentDigest(TElAS2MessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_ContentDigestAlgorithm(TElAS2MessageHandle _Handle, TSBASSignatureDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Errors(TElAS2MessageHandle _Handle, TElASMessageErrorListHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Features(TElAS2MessageHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Features(TElAS2MessageHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_AS2From(TElAS2MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_AS2From(TElAS2MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_AS2To(TElAS2MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_AS2To(TElAS2MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Charset(TElAS2MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_Charset(TElAS2MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_CharsetMode(TElAS2MessageHandle _Handle, TSBASCharsetModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_CharsetMode(TElAS2MessageHandle _Handle, TSBASCharsetModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Compression(TElAS2MessageHandle _Handle, TElAS2CompressionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_Compression(TElAS2MessageHandle _Handle, TElAS2CompressionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_ContentType(TElAS2MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_ContentType(TElAS2MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_DataEncoding(TElAS2MessageHandle _Handle, TSBASDataTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_DataEncoding(TElAS2MessageHandle _Handle, TSBASDataTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Date(TElAS2MessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_Date(TElAS2MessageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Encryption(TElAS2MessageHandle _Handle, TElAS2EncryptionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_Encryption(TElAS2MessageHandle _Handle, TElAS2EncryptionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_FileCreated(TElAS2MessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_FileCreated(TElAS2MessageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_FileModified(TElAS2MessageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_FileModified(TElAS2MessageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_FileName(TElAS2MessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_FileName(TElAS2MessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_HeaderEncoding(TElAS2MessageHandle _Handle, TSBASHeaderTransferEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_HeaderEncoding(TElAS2MessageHandle _Handle, TSBASHeaderTransferEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_IgnoreFileWarnings(TElAS2MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_IgnoreFileWarnings(TElAS2MessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_MessageID(TElAS2MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_MessageID(TElAS2MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_ReceiptRequest(TElAS2MessageHandle _Handle, TElAS2ReceiptRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_ReceiptRequest(TElAS2MessageHandle _Handle, TElAS2ReceiptRequestHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Signature(TElAS2MessageHandle _Handle, TElAS2SignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_Signature(TElAS2MessageHandle _Handle, TElAS2SignatureHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Subject(TElAS2MessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_Subject(TElAS2MessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_UseFolding(TElAS2MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_UseFolding(TElAS2MessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_Version(TElAS2MessageHandle _Handle, TSBAS2VersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_Version(TElAS2MessageHandle _Handle, TSBAS2VersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnDecrypt(TElAS2MessageHandle _Handle, TSBASMessageDecryptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnDecrypt(TElAS2MessageHandle _Handle, TSBASMessageDecryptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnDecryptIDs(TElAS2MessageHandle _Handle, TSBASMessageDecryptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnDecryptIDs(TElAS2MessageHandle _Handle, TSBASMessageDecryptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnDecrypting(TElAS2MessageHandle _Handle, TSBASMessageDecryptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnDecrypting(TElAS2MessageHandle _Handle, TSBASMessageDecryptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnEncrypt(TElAS2MessageHandle _Handle, TSBASMessageEncryptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnEncrypt(TElAS2MessageHandle _Handle, TSBASMessageEncryptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnEncrypting(TElAS2MessageHandle _Handle, TSBASMessageEncryptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnEncrypting(TElAS2MessageHandle _Handle, TSBASMessageEncryptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnError(TElAS2MessageHandle _Handle, TSBASMessageErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnError(TElAS2MessageHandle _Handle, TSBASMessageErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnHeaderAssembled(TElAS2MessageHandle _Handle, TSBASHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnHeaderAssembled(TElAS2MessageHandle _Handle, TSBASHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnHeaderParsed(TElAS2MessageHandle _Handle, TSBASHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnHeaderParsed(TElAS2MessageHandle _Handle, TSBASHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnProgress(TElAS2MessageHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnProgress(TElAS2MessageHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnSign(TElAS2MessageHandle _Handle, TSBASMessageSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnSign(TElAS2MessageHandle _Handle, TSBASMessageSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnSigning(TElAS2MessageHandle _Handle, TSBASMessageSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnSigning(TElAS2MessageHandle _Handle, TSBASMessageSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnStepStart(TElAS2MessageHandle _Handle, TSBASProcessingStepStart * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnStepStart(TElAS2MessageHandle _Handle, TSBASProcessingStepStart pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnTempRelease(TElAS2MessageHandle _Handle, TSBASStreamReleaseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnTempRelease(TElAS2MessageHandle _Handle, TSBASStreamReleaseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnTempRequest(TElAS2MessageHandle _Handle, TSBASStreamRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnTempRequest(TElAS2MessageHandle _Handle, TSBASStreamRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnVerify(TElAS2MessageHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnVerify(TElAS2MessageHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnVerifyIDs(TElAS2MessageHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnVerifyIDs(TElAS2MessageHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_get_OnVerifying(TElAS2MessageHandle _Handle, TSBASMessageVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_set_OnVerifying(TElAS2MessageHandle _Handle, TSBASMessageVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Message_Create(TComponentHandle AOwner, TElAS2MessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2MESSAGE */

#ifdef SB_USE_CLASS_TELAS2HTTPOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_Assign(TElAS2HTTPOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_KeepAlivePolicy(TElAS2HTTPOptionsHandle _Handle, TSBHTTPKeepAlivePolicyRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_KeepAlivePolicy(TElAS2HTTPOptionsHandle _Handle, TSBHTTPKeepAlivePolicyRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_MaxRedirections(TElAS2HTTPOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_MaxRedirections(TElAS2HTTPOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_Password(TElAS2HTTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_Password(TElAS2HTTPOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_UseCompression(TElAS2HTTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_UseCompression(TElAS2HTTPOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_UseDigestAuth(TElAS2HTTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_UseDigestAuth(TElAS2HTTPOptionsHandle _Handle, int8_t Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_UseNTLMAuth(TElAS2HTTPOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_UseNTLMAuth(TElAS2HTTPOptionsHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_UserAgent(TElAS2HTTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_UserAgent(TElAS2HTTPOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_UserName(TElAS2HTTPOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_UserName(TElAS2HTTPOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_get_Version(TElAS2HTTPOptionsHandle _Handle, TSBHTTPVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_set_Version(TElAS2HTTPOptionsHandle _Handle, TSBHTTPVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2HTTPOptions_Create(TElHTTPSClientHandle AClient, TElAS2HTTPOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2HTTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS2PROXYOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_Assign(TElAS2ProxyOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_get_Enabled(TElAS2ProxyOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_set_Enabled(TElAS2ProxyOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_get_Host(TElAS2ProxyOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_set_Host(TElAS2ProxyOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_get_Password(TElAS2ProxyOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_set_Password(TElAS2ProxyOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_get_Port(TElAS2ProxyOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_set_Port(TElAS2ProxyOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_get_UserName(TElAS2ProxyOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_set_UserName(TElAS2ProxyOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2ProxyOptions_Create(TElHTTPSClientHandle AClient, TElAS2ProxyOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKETOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_Assign(TElAS2SocketOptionsHandle _Handle, TPersistentHandle Source);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_UsingIPv6(TElAS2SocketOptionsHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_Binding(TElAS2SocketOptionsHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_Binding(TElAS2SocketOptionsHandle _Handle, TElClientSocketBindingHandle Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_DNS(TElAS2SocketOptionsHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_DNS(TElAS2SocketOptionsHandle _Handle, TElDNSSettingsHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_IncomingSpeedLimit(TElAS2SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_IncomingSpeedLimit(TElAS2SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_OutgoingSpeedLimit(TElAS2SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_OutgoingSpeedLimit(TElAS2SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_Timeout(TElAS2SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_Timeout(TElAS2SocketOptionsHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_UseIPv6(TElAS2SocketOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_UseIPv6(TElAS2SocketOptionsHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_AutoAdjustBuffersSize(TElAS2SocketOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_AutoAdjustBuffersSize(TElAS2SocketOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_BuffersAdjustStep(TElAS2SocketOptionsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_BuffersAdjustStep(TElAS2SocketOptionsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_MaxBufferSize(TElAS2SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_MaxBufferSize(TElAS2SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_MinBufferSize(TElAS2SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_MinBufferSize(TElAS2SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_RecvBufferSize(TElAS2SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_RecvBufferSize(TElAS2SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_get_SendBufferSize(TElAS2SocketOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_set_SendBufferSize(TElAS2SocketOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocketOptions_Create(TElHTTPSClientHandle AClient, TElAS2SocketOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKSOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_Assign(TElAS2SocksOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_Authentication(TElAS2SocksOptionsHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_Authentication(TElAS2SocksOptionsHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_Enabled(TElAS2SocksOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_Enabled(TElAS2SocksOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_Host(TElAS2SocksOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_Host(TElAS2SocksOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_Password(TElAS2SocksOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_Password(TElAS2SocksOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_Port(TElAS2SocksOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_Port(TElAS2SocksOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_ResolveAddress(TElAS2SocksOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_ResolveAddress(TElAS2SocksOptionsHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_UseIPv6(TElAS2SocksOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_UseIPv6(TElAS2SocksOptionsHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_UserCode(TElAS2SocksOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_UserCode(TElAS2SocksOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_get_Version(TElAS2SocksOptionsHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_set_Version(TElAS2SocksOptionsHandle _Handle, TElSocksVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SocksOptions_Create(TElHTTPSClientHandle AClient, TElAS2SocksOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SSLOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_Assign(TElAS2SSLOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_InternalValidate(TElAS2SSLOptionsHandle _Handle, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_RenegotiateCiphers(TElAS2SSLOptionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_Active(TElAS2SSLOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_CurrentCipherSuite(TElAS2SSLOptionsHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_CurrentCompression(TElAS2SSLOptionsHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_CurrentVersion(TElAS2SSLOptionsHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_ServerExtensions(TElAS2SSLOptionsHandle _Handle, TElCustomSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_ServerExtensions(TElAS2SSLOptionsHandle _Handle, TElCustomSSLExtensionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_Extensions(TElAS2SSLOptionsHandle _Handle, TElClientSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_Extensions(TElAS2SSLOptionsHandle _Handle, TElClientSSLExtensionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_Options(TElAS2SSLOptionsHandle _Handle, TSBSSLOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_Options(TElAS2SSLOptionsHandle _Handle, TSBSSLOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_CipherSuitePriorities(TElAS2SSLOptionsHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_CipherSuitePriorities(TElAS2SSLOptionsHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_CipherSuites(TElAS2SSLOptionsHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_CipherSuites(TElAS2SSLOptionsHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_CompressionAlgorithms(TElAS2SSLOptionsHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_CompressionAlgorithms(TElAS2SSLOptionsHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_CertStorage(TElAS2SSLOptionsHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_CertStorage(TElAS2SSLOptionsHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_ClientCertStorage(TElAS2SSLOptionsHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_ClientCertStorage(TElAS2SSLOptionsHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_SRPPassword(TElAS2SSLOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_SRPPassword(TElAS2SSLOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_SRPUserName(TElAS2SSLOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_SRPUserName(TElAS2SSLOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_Versions(TElAS2SSLOptionsHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_Versions(TElAS2SSLOptionsHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_get_RenegotiationAttackPreventionMode(TElAS2SSLOptionsHandle _Handle, TSBRenegotiationAttackPreventionModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_set_RenegotiationAttackPreventionMode(TElAS2SSLOptionsHandle _Handle, TSBRenegotiationAttackPreventionModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2SSLOptions_Create(TElHTTPSClientHandle AClient, TElAS2SSLOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_Assign(TElAS2WebTunnelOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_get_ServerResult(TElAS2WebTunnelOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_get_Authentication(TElAS2WebTunnelOptionsHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_set_Authentication(TElAS2WebTunnelOptionsHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_get_Enabled(TElAS2WebTunnelOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_set_Enabled(TElAS2WebTunnelOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_get_Host(TElAS2WebTunnelOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_set_Host(TElAS2WebTunnelOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_get_Password(TElAS2WebTunnelOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_set_Password(TElAS2WebTunnelOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_get_Port(TElAS2WebTunnelOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_set_Port(TElAS2WebTunnelOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_get_UserID(TElAS2WebTunnelOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_set_UserID(TElAS2WebTunnelOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2WebTunnelOptions_Create(TElHTTPSClientHandle AClient, TElAS2WebTunnelOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS */

#ifdef SB_USE_CLASS_TELAS2CLIENT
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_Send(TElAS2ClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Message, TStreamHandle Receipt, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_Send_1(TElAS2ClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcMessageFile, int32_t szMessageFile, const char * pcReceiptFile, int32_t szReceiptFile, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_SendReceipt(TElAS2ClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Receipt, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_SendReceipt_1(TElAS2ClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcReceiptFile, int32_t szReceiptFile, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_HTTP(TElAS2ClientHandle _Handle, TElAS2HTTPOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_HTTP(TElAS2ClientHandle _Handle, TElAS2HTTPOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_Proxy(TElAS2ClientHandle _Handle, TElAS2ProxyOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_Proxy(TElAS2ClientHandle _Handle, TElAS2ProxyOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_Socket(TElAS2ClientHandle _Handle, TElAS2SocketOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_Socket(TElAS2ClientHandle _Handle, TElAS2SocketOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_Socks(TElAS2ClientHandle _Handle, TElAS2SocksOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_Socks(TElAS2ClientHandle _Handle, TElAS2SocksOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_SSL(TElAS2ClientHandle _Handle, TElAS2SSLOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_SSL(TElAS2ClientHandle _Handle, TElAS2SSLOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_WebTunnel(TElAS2ClientHandle _Handle, TElAS2WebTunnelOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_WebTunnel(TElAS2ClientHandle _Handle, TElAS2WebTunnelOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnCertificateChoose(TElAS2ClientHandle _Handle, TSBChooseCertificateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnCertificateChoose(TElAS2ClientHandle _Handle, TSBChooseCertificateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnCertificateNeededEx(TElAS2ClientHandle _Handle, TSBCertificateNeededExEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnCertificateNeededEx(TElAS2ClientHandle _Handle, TSBCertificateNeededExEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnCertificateStatus(TElAS2ClientHandle _Handle, TSBCertificateStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnCertificateStatus(TElAS2ClientHandle _Handle, TSBCertificateStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnCertificateValidate(TElAS2ClientHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnCertificateValidate(TElAS2ClientHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnCiphersNegotiated(TElAS2ClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnCiphersNegotiated(TElAS2ClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnCloseConnection(TElAS2ClientHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnCloseConnection(TElAS2ClientHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnCookie(TElAS2ClientHandle _Handle, TSBHTTPCookieEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnCookie(TElAS2ClientHandle _Handle, TSBHTTPCookieEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnData(TElAS2ClientHandle _Handle, TSBDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnData(TElAS2ClientHandle _Handle, TSBDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnDocumentBegin(TElAS2ClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnDocumentBegin(TElAS2ClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnDocumentEnd(TElAS2ClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnDocumentEnd(TElAS2ClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnError(TElAS2ClientHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnError(TElAS2ClientHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnExtensionsReceived(TElAS2ClientHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnExtensionsReceived(TElAS2ClientHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnExtensionsPrepared(TElAS2ClientHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnExtensionsPrepared(TElAS2ClientHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnKeyNeeded(TElAS2ClientHandle _Handle, TSBClientKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnKeyNeeded(TElAS2ClientHandle _Handle, TSBClientKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnPreparedHeaders(TElAS2ClientHandle _Handle, TSBHTTPHeadersEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnPreparedHeaders(TElAS2ClientHandle _Handle, TSBHTTPHeadersEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnProgress(TElAS2ClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnProgress(TElAS2ClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnReceivingHeaders(TElAS2ClientHandle _Handle, TSBHTTPHeadersEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnReceivingHeaders(TElAS2ClientHandle _Handle, TSBHTTPHeadersEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnRedirection(TElAS2ClientHandle _Handle, TSBHTTPRedirectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnRedirection(TElAS2ClientHandle _Handle, TSBHTTPRedirectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnRenegotiationRequest(TElAS2ClientHandle _Handle, TSBRenegotiationRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnRenegotiationRequest(TElAS2ClientHandle _Handle, TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnDNSKeyNeded(TElAS2ClientHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnDNSKeyNeded(TElAS2ClientHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnDNSKeyValidate(TElAS2ClientHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnDNSKeyValidate(TElAS2ClientHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_get_OnDNSResolve(TElAS2ClientHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_set_OnDNSResolve(TElAS2ClientHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAS2Client_Create(TComponentHandle AOwner, TElAS2ClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELAS2CLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElAS2ReceiptRequest;
class TElAS2Encryption;
class TElAS2Signature;
class TElAS2Compression;
class TElAS2Receipt;
class TElAS2Message;
class TElAS2HTTPOptions;
class TElAS2ProxyOptions;
class TElAS2SocketOptions;
class TElAS2SocksOptions;
class TElAS2SSLOptions;
class TElAS2WebTunnelOptions;
class TElAS2Client;

#ifdef SB_USE_CLASS_TELAS2RECEIPTREQUEST
class TElAS2ReceiptRequest: public TElASReceiptRequest
{
	private:
		SB_DISABLE_COPY(TElAS2ReceiptRequest)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool get_AsyncReceipt();

		virtual void set_AsyncReceipt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AsyncReceipt, set_AsyncReceipt, TElAS2ReceiptRequest, AsyncReceipt);

		virtual TSBASSignatureDigestAlgorithm get_DigestAlgorithm();

		virtual void set_DigestAlgorithm(TSBASSignatureDigestAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBASSignatureDigestAlgorithm, get_DigestAlgorithm, set_DigestAlgorithm, TElAS2ReceiptRequest, DigestAlgorithm);

		virtual bool get_DigestAlgorithmOnly();

		virtual void set_DigestAlgorithmOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DigestAlgorithmOnly, set_DigestAlgorithmOnly, TElAS2ReceiptRequest, DigestAlgorithmOnly);

		virtual bool get_DigestAlgorithmRequired();

		virtual void set_DigestAlgorithmRequired(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DigestAlgorithmRequired, set_DigestAlgorithmRequired, TElAS2ReceiptRequest, DigestAlgorithmRequired);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS2ReceiptRequest, Enabled);

		virtual bool get_SignatureProtocolRequired();

		virtual void set_SignatureProtocolRequired(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignatureProtocolRequired, set_SignatureProtocolRequired, TElAS2ReceiptRequest, SignatureProtocolRequired);

		virtual bool get_Signed();

		virtual void set_Signed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Signed, set_Signed, TElAS2ReceiptRequest, Signed);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		TElAS2ReceiptRequest(TElAS2ReceiptRequestHandle handle, TElOwnHandle ownHandle);

		TElAS2ReceiptRequest();

};
#endif /* SB_USE_CLASS_TELAS2RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS2ENCRYPTION
class TElAS2Encryption: public TElASSMIMEEncryption
{
	private:
		SB_DISABLE_COPY(TElAS2Encryption)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElAS2Encryption, Algorithm);

		virtual bool get_AlignEncryptedKey();

		virtual void set_AlignEncryptedKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AlignEncryptedKey, set_AlignEncryptedKey, TElAS2Encryption, AlignEncryptedKey);

		virtual int32_t get_BitsInKey();

		virtual void set_BitsInKey(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BitsInKey, set_BitsInKey, TElAS2Encryption, BitsInKey);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElAS2Encryption, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS2Encryption, Enabled);

		virtual TSBASEncryptionTransferEncoding get_Encoding();

		virtual void set_Encoding(TSBASEncryptionTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASEncryptionTransferEncoding, get_Encoding, set_Encoding, TElAS2Encryption, Encoding);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElAS2Encryption, UseUndefSize);

		TElAS2Encryption(TElAS2EncryptionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElAS2Encryption(TComponent &AOwner);

		explicit TElAS2Encryption(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

		virtual ~TElAS2Encryption();

};
#endif /* SB_USE_CLASS_TELAS2ENCRYPTION */

#ifdef SB_USE_CLASS_TELAS2SIGNATURE
class TElAS2Signature: public TElASSMIMESignature
{
	private:
		SB_DISABLE_COPY(TElAS2Signature)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		virtual int32_t get_VerificationResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_VerificationResult, TElAS2Signature, VerificationResult);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElAS2Signature, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_Compressed();

		virtual void set_Compressed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Compressed, set_Compressed, TElAS2Signature, Compressed);

		virtual TSBASSignatureDigestAlgorithm get_DigestAlgorithm();

		virtual void set_DigestAlgorithm(TSBASSignatureDigestAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBASSignatureDigestAlgorithm, get_DigestAlgorithm, set_DigestAlgorithm, TElAS2Signature, DigestAlgorithm);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS2Signature, Enabled);

		virtual TSBASSignatureTransferEncoding get_Encoding();

		virtual void set_Encoding(TSBASSignatureTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASSignatureTransferEncoding, get_Encoding, set_Encoding, TElAS2Signature, Encoding);

		virtual bool get_IncludeChain();

		virtual void set_IncludeChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeChain, set_IncludeChain, TElAS2Signature, IncludeChain);

		virtual int64_t get_Time();

		virtual void set_Time(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Time, set_Time, TElAS2Signature, Time);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElAS2Signature, UseUndefSize);

		virtual TSBASSMIMEVerificationOptions get_VerificationOptions();

		virtual void set_VerificationOptions(TSBASSMIMEVerificationOptions Value);

		SB_DECLARE_PROPERTY(TSBASSMIMEVerificationOptions, get_VerificationOptions, set_VerificationOptions, TElAS2Signature, VerificationOptions);

		TElAS2Signature(TElAS2SignatureHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElAS2Signature(TComponent &AOwner);

		explicit TElAS2Signature(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

		virtual ~TElAS2Signature();

};
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

#ifdef SB_USE_CLASS_TELAS2COMPRESSION
class TElAS2Compression: public TElASSMIMECompression
{
	private:
		SB_DISABLE_COPY(TElAS2Compression)
	public:
		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS2Compression, Enabled);

		virtual TSBASCompressionTransferEncoding get_Encoding();

		virtual void set_Encoding(TSBASCompressionTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASCompressionTransferEncoding, get_Encoding, set_Encoding, TElAS2Compression, Encoding);

		virtual int32_t get_Level();

		virtual void set_Level(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Level, set_Level, TElAS2Compression, Level);

		TElAS2Compression(TElAS2CompressionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElAS2Compression(TComponent &AOwner);

		explicit TElAS2Compression(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

};
#endif /* SB_USE_CLASS_TELAS2COMPRESSION */

#ifdef SB_USE_CLASS_TELAS2RECEIPT
class TElAS2Receipt: public TElASReceipt
{
	private:
		SB_DISABLE_COPY(TElAS2Receipt)
#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
		TElASMessageErrorList* _Inst_Errors;
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */
#ifdef SB_USE_CLASS_TELAS2SIGNATURE
		TElAS2Signature* _Inst_Signature;
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
		virtual TElASMessageErrorList* get_Errors();

		SB_DECLARE_PROPERTY_GET(TElASMessageErrorList*, get_Errors, TElAS2Receipt, Errors);
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

		virtual void get_ReceivedContentDigest(std::vector<uint8_t> &OutResult);

		virtual void set_ReceivedContentDigest(const std::vector<uint8_t> &Value);

		virtual TSBASSignatureDigestAlgorithm get_ReceivedContentDigestAlgorithm();

		virtual void set_ReceivedContentDigestAlgorithm(TSBASSignatureDigestAlgorithm Value);

		SB_DECLARE_PROPERTY(TSBASSignatureDigestAlgorithm, get_ReceivedContentDigestAlgorithm, set_ReceivedContentDigestAlgorithm, TElAS2Receipt, ReceivedContentDigestAlgorithm);

		virtual TSBASDispositionActionMode get_ActionMode();

		virtual void set_ActionMode(TSBASDispositionActionMode Value);

		SB_DECLARE_PROPERTY(TSBASDispositionActionMode, get_ActionMode, set_ActionMode, TElAS2Receipt, ActionMode);

		virtual void get_AS2From(std::string &OutResult);

		virtual void set_AS2From(const std::string &Value);

		virtual void get_AS2To(std::string &OutResult);

		virtual void set_AS2To(const std::string &Value);

		virtual int64_t get_Date();

		virtual void set_Date(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Date, set_Date, TElAS2Receipt, Date);

		virtual bool get_DetailedErrors();

		virtual void set_DetailedErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DetailedErrors, set_DetailedErrors, TElAS2Receipt, DetailedErrors);

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

		SB_DECLARE_PROPERTY(TSBASCharsetMode, get_ReportCharsetMode, set_ReportCharsetMode, TElAS2Receipt, ReportCharsetMode);

		virtual TSBASHeaderTransferEncoding get_ReportEncoding();

		virtual void set_ReportEncoding(TSBASHeaderTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASHeaderTransferEncoding, get_ReportEncoding, set_ReportEncoding, TElAS2Receipt, ReportEncoding);

		virtual void get_ReportingUA(std::string &OutResult);

		virtual void set_ReportingUA(const std::string &Value);

		virtual TSBASDispositionSendingMode get_SendingMode();

		virtual void set_SendingMode(TSBASDispositionSendingMode Value);

		SB_DECLARE_PROPERTY(TSBASDispositionSendingMode, get_SendingMode, set_SendingMode, TElAS2Receipt, SendingMode);

#ifdef SB_USE_CLASS_TELAS2SIGNATURE
		virtual TElAS2Signature* get_Signature();

		virtual void set_Signature(TElAS2Signature &Value);

		virtual void set_Signature(TElAS2Signature *Value);

		SB_DECLARE_PROPERTY(TElAS2Signature*, get_Signature, set_Signature, TElAS2Receipt, Signature);
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

		virtual bool get_SortErrors();

		virtual void set_SortErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SortErrors, set_SortErrors, TElAS2Receipt, SortErrors);

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

		SB_DECLARE_PROPERTY(TSBASCharsetMode, get_TextCharsetMode, set_TextCharsetMode, TElAS2Receipt, TextCharsetMode);

		virtual void get_TextContentType(std::string &OutResult);

		virtual void set_TextContentType(const std::string &Value);

		virtual TSBASHeaderTransferEncoding get_TextEncoding();

		virtual void set_TextEncoding(TSBASHeaderTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASHeaderTransferEncoding, get_TextEncoding, set_TextEncoding, TElAS2Receipt, TextEncoding);

		virtual bool get_UseFolding();

		virtual void set_UseFolding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseFolding, set_UseFolding, TElAS2Receipt, UseFolding);

		virtual TSBAS2Version get_Version();

		virtual void set_Version(TSBAS2Version Value);

		SB_DECLARE_PROPERTY(TSBAS2Version, get_Version, set_Version, TElAS2Receipt, Version);

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

		TElAS2Receipt(TElAS2ReceiptHandle handle, TElOwnHandle ownHandle);

		explicit TElAS2Receipt(TComponent &AOwner);

		explicit TElAS2Receipt(TComponent *AOwner);

		virtual ~TElAS2Receipt();

};
#endif /* SB_USE_CLASS_TELAS2RECEIPT */

#ifdef SB_USE_CLASS_TELAS2MESSAGE
class TElAS2Message: public TElASMessage
{
	private:
		SB_DISABLE_COPY(TElAS2Message)
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
#ifdef SB_USE_CLASS_TELAS2COMPRESSION
		TElAS2Compression* _Inst_Compression;
#endif /* SB_USE_CLASS_TELAS2COMPRESSION */
#ifdef SB_USE_CLASS_TELAS2ENCRYPTION
		TElAS2Encryption* _Inst_Encryption;
#endif /* SB_USE_CLASS_TELAS2ENCRYPTION */
#ifdef SB_USE_CLASS_TELAS2RECEIPTREQUEST
		TElAS2ReceiptRequest* _Inst_ReceiptRequest;
#endif /* SB_USE_CLASS_TELAS2RECEIPTREQUEST */
#ifdef SB_USE_CLASS_TELAS2SIGNATURE
		TElAS2Signature* _Inst_Signature;
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool get_Cancelled();

		SB_DECLARE_PROPERTY_GET(bool, get_Cancelled, TElAS2Message, Cancelled);

		virtual void get_ContentDigest(std::vector<uint8_t> &OutResult);

		virtual TSBASSignatureDigestAlgorithm get_ContentDigestAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBASSignatureDigestAlgorithm, get_ContentDigestAlgorithm, TElAS2Message, ContentDigestAlgorithm);

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
		virtual TElASMessageErrorList* get_Errors();

		SB_DECLARE_PROPERTY_GET(TElASMessageErrorList*, get_Errors, TElAS2Message, Errors);
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Features();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Features, TElAS2Message, Features);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Features();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Features, TElAS2Message, Features);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_AS2From(std::string &OutResult);

		virtual void set_AS2From(const std::string &Value);

		virtual void get_AS2To(std::string &OutResult);

		virtual void set_AS2To(const std::string &Value);

		virtual void get_Charset(std::string &OutResult);

		virtual void set_Charset(const std::string &Value);

		virtual TSBASCharsetMode get_CharsetMode();

		virtual void set_CharsetMode(TSBASCharsetMode Value);

		SB_DECLARE_PROPERTY(TSBASCharsetMode, get_CharsetMode, set_CharsetMode, TElAS2Message, CharsetMode);

#ifdef SB_USE_CLASS_TELAS2COMPRESSION
		virtual TElAS2Compression* get_Compression();

		virtual void set_Compression(TElAS2Compression &Value);

		virtual void set_Compression(TElAS2Compression *Value);

		SB_DECLARE_PROPERTY(TElAS2Compression*, get_Compression, set_Compression, TElAS2Message, Compression);
#endif /* SB_USE_CLASS_TELAS2COMPRESSION */

		virtual void get_ContentType(std::string &OutResult);

		virtual void set_ContentType(const std::string &Value);

		virtual TSBASDataTransferEncoding get_DataEncoding();

		virtual void set_DataEncoding(TSBASDataTransferEncoding Value);

		SB_DECLARE_PROPERTY(TSBASDataTransferEncoding, get_DataEncoding, set_DataEncoding, TElAS2Message, DataEncoding);

		virtual int64_t get_Date();

		virtual void set_Date(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Date, set_Date, TElAS2Message, Date);

#ifdef SB_USE_CLASS_TELAS2ENCRYPTION
		virtual TElAS2Encryption* get_Encryption();

		virtual void set_Encryption(TElAS2Encryption &Value);

		virtual void set_Encryption(TElAS2Encryption *Value);

		SB_DECLARE_PROPERTY(TElAS2Encryption*, get_Encryption, set_Encryption, TElAS2Message, Encryption);
#endif /* SB_USE_CLASS_TELAS2ENCRYPTION */

		virtual int64_t get_FileCreated();

		virtual void set_FileCreated(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileCreated, set_FileCreated, TElAS2Message, FileCreated);

		virtual int64_t get_FileModified();

		virtual void set_FileModified(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileModified, set_FileModified, TElAS2Message, FileModified);

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

		SB_DECLARE_PROPERTY(TSBASHeaderTransferEncoding, get_HeaderEncoding, set_HeaderEncoding, TElAS2Message, HeaderEncoding);

		virtual bool get_IgnoreFileWarnings();

		virtual void set_IgnoreFileWarnings(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreFileWarnings, set_IgnoreFileWarnings, TElAS2Message, IgnoreFileWarnings);

		virtual void get_MessageID(std::string &OutResult);

		virtual void set_MessageID(const std::string &Value);

#ifdef SB_USE_CLASS_TELAS2RECEIPTREQUEST
		virtual TElAS2ReceiptRequest* get_ReceiptRequest();

		virtual void set_ReceiptRequest(TElAS2ReceiptRequest &Value);

		virtual void set_ReceiptRequest(TElAS2ReceiptRequest *Value);

		SB_DECLARE_PROPERTY(TElAS2ReceiptRequest*, get_ReceiptRequest, set_ReceiptRequest, TElAS2Message, ReceiptRequest);
#endif /* SB_USE_CLASS_TELAS2RECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELAS2SIGNATURE
		virtual TElAS2Signature* get_Signature();

		virtual void set_Signature(TElAS2Signature &Value);

		virtual void set_Signature(TElAS2Signature *Value);

		SB_DECLARE_PROPERTY(TElAS2Signature*, get_Signature, set_Signature, TElAS2Message, Signature);
#endif /* SB_USE_CLASS_TELAS2SIGNATURE */

		virtual void get_Subject(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Subject(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Subject(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Subject(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual bool get_UseFolding();

		virtual void set_UseFolding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseFolding, set_UseFolding, TElAS2Message, UseFolding);

		virtual TSBAS2Version get_Version();

		virtual void set_Version(TSBAS2Version Value);

		SB_DECLARE_PROPERTY(TSBAS2Version, get_Version, set_Version, TElAS2Message, Version);

		virtual void get_OnDecrypt(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecrypt(TSBASMessageDecryptEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptIDs(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptIDs(TSBASMessageDecryptEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecrypting(TSBASMessageDecryptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecrypting(TSBASMessageDecryptEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncrypt(TSBASMessageEncryptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncrypt(TSBASMessageEncryptEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncrypting(TSBASMessageEncryptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncrypting(TSBASMessageEncryptEvent pMethodValue, void * pDataValue);

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

		TElAS2Message(TElAS2MessageHandle handle, TElOwnHandle ownHandle);

		explicit TElAS2Message(TComponent &AOwner);

		explicit TElAS2Message(TComponent *AOwner);

		virtual ~TElAS2Message();

};
#endif /* SB_USE_CLASS_TELAS2MESSAGE */

#ifdef SB_USE_CLASS_TELAS2HTTPOPTIONS
class TElAS2HTTPOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS2HTTPOptions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TSBHTTPKeepAlivePolicy get_KeepAlivePolicy();

		virtual void set_KeepAlivePolicy(TSBHTTPKeepAlivePolicy Value);

		SB_DECLARE_PROPERTY(TSBHTTPKeepAlivePolicy, get_KeepAlivePolicy, set_KeepAlivePolicy, TElAS2HTTPOptions, KeepAlivePolicy);

		virtual int32_t get_MaxRedirections();

		virtual void set_MaxRedirections(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxRedirections, set_MaxRedirections, TElAS2HTTPOptions, MaxRedirections);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual bool get_UseCompression();

		virtual void set_UseCompression(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCompression, set_UseCompression, TElAS2HTTPOptions, UseCompression);

		virtual bool get_UseDigestAuth();

		virtual void set_UseDigestAuth(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDigestAuth, set_UseDigestAuth, TElAS2HTTPOptions, UseDigestAuth);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual bool get_UseNTLMAuth();

		virtual void set_UseNTLMAuth(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNTLMAuth, set_UseNTLMAuth, TElAS2HTTPOptions, UseNTLMAuth);
#endif

		virtual void get_UserAgent(std::string &OutResult);

		virtual void set_UserAgent(const std::string &Value);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		virtual TSBHTTPVersion get_Version();

		virtual void set_Version(TSBHTTPVersion Value);

		SB_DECLARE_PROPERTY(TSBHTTPVersion, get_Version, set_Version, TElAS2HTTPOptions, Version);

		TElAS2HTTPOptions(TElAS2HTTPOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		explicit TElAS2HTTPOptions(TElHTTPSClient &AClient);

		explicit TElAS2HTTPOptions(TElHTTPSClient *AClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELAS2HTTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS2PROXYOPTIONS
class TElAS2ProxyOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS2ProxyOptions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS2ProxyOptions, Enabled);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElAS2ProxyOptions, Port);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElAS2ProxyOptions(TElAS2ProxyOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		explicit TElAS2ProxyOptions(TElHTTPSClient &AClient);

		explicit TElAS2ProxyOptions(TElHTTPSClient *AClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELAS2PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKETOPTIONS
class TElAS2SocketOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS2SocketOptions)
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_Binding;
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

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElAS2SocketOptions, UsingIPv6);
#endif

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_Binding();

		virtual void set_Binding(TElClientSocketBinding &Value);

		virtual void set_Binding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_Binding, set_Binding, TElAS2SocketOptions, Binding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElAS2SocketOptions, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElAS2SocketOptions, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElAS2SocketOptions, OutgoingSpeedLimit);

		virtual int32_t get_Timeout();

		virtual void set_Timeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Timeout, set_Timeout, TElAS2SocketOptions, Timeout);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElAS2SocketOptions, UseIPv6);
#endif

		virtual bool get_AutoAdjustBuffersSize();

		virtual void set_AutoAdjustBuffersSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustBuffersSize, set_AutoAdjustBuffersSize, TElAS2SocketOptions, AutoAdjustBuffersSize);

		virtual double get_BuffersAdjustStep();

		virtual void set_BuffersAdjustStep(double Value);

		SB_DECLARE_PROPERTY(double, get_BuffersAdjustStep, set_BuffersAdjustStep, TElAS2SocketOptions, BuffersAdjustStep);

		virtual int32_t get_MaxBufferSize();

		virtual void set_MaxBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxBufferSize, set_MaxBufferSize, TElAS2SocketOptions, MaxBufferSize);

		virtual int32_t get_MinBufferSize();

		virtual void set_MinBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinBufferSize, set_MinBufferSize, TElAS2SocketOptions, MinBufferSize);

		virtual int32_t get_RecvBufferSize();

		virtual void set_RecvBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RecvBufferSize, set_RecvBufferSize, TElAS2SocketOptions, RecvBufferSize);

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElAS2SocketOptions, SendBufferSize);

		TElAS2SocketOptions(TElAS2SocketOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		explicit TElAS2SocketOptions(TElHTTPSClient &AClient);

		explicit TElAS2SocketOptions(TElHTTPSClient *AClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual ~TElAS2SocketOptions();

};
#endif /* SB_USE_CLASS_TELAS2SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKSOPTIONS
class TElAS2SocksOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS2SocksOptions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TElSocksAuthentication get_Authentication();

		virtual void set_Authentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_Authentication, set_Authentication, TElAS2SocksOptions, Authentication);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS2SocksOptions, Enabled);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElAS2SocksOptions, Port);

		virtual bool get_ResolveAddress();

		virtual void set_ResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ResolveAddress, set_ResolveAddress, TElAS2SocksOptions, ResolveAddress);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElAS2SocksOptions, UseIPv6);
#endif

		virtual void get_UserCode(std::string &OutResult);

		virtual void set_UserCode(const std::string &Value);

		virtual TElSocksVersion get_Version();

		virtual void set_Version(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_Version, set_Version, TElAS2SocksOptions, Version);

		TElAS2SocksOptions(TElAS2SocksOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		explicit TElAS2SocksOptions(TElHTTPSClient &AClient);

		explicit TElAS2SocksOptions(TElHTTPSClient *AClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELAS2SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SSLOPTIONS
class TElAS2SSLOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS2SSLOptions)
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		TElCustomSSLExtensions* _Inst_ServerExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		TElClientSSLExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
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

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElAS2SSLOptions, Active);

		virtual uint8_t get_CurrentCipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CurrentCipherSuite, TElAS2SSLOptions, CurrentCipherSuite);

		virtual uint8_t get_CurrentCompression();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CurrentCompression, TElAS2SSLOptions, CurrentCompression);

		virtual TSBVersion get_CurrentVersion();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_CurrentVersion, TElAS2SSLOptions, CurrentVersion);

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		virtual TElCustomSSLExtensions* get_ServerExtensions();

		virtual void set_ServerExtensions(TElCustomSSLExtensions &Value);

		virtual void set_ServerExtensions(TElCustomSSLExtensions *Value);

		SB_DECLARE_PROPERTY(TElCustomSSLExtensions*, get_ServerExtensions, set_ServerExtensions, TElAS2SSLOptions, ServerExtensions);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		virtual TElClientSSLExtensions* get_Extensions();

		virtual void set_Extensions(TElClientSSLExtensions &Value);

		virtual void set_Extensions(TElClientSSLExtensions *Value);

		SB_DECLARE_PROPERTY(TElClientSSLExtensions*, get_Extensions, set_Extensions, TElAS2SSLOptions, Extensions);
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

		virtual TSBSSLOptions get_Options();

		virtual void set_Options(TSBSSLOptions Value);

		SB_DECLARE_PROPERTY(TSBSSLOptions, get_Options, set_Options, TElAS2SSLOptions, Options);

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

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElAS2SSLOptions, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElAS2SSLOptions, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_SRPPassword(std::string &OutResult);

		virtual void set_SRPPassword(const std::string &Value);

		virtual void get_SRPUserName(std::string &OutResult);

		virtual void set_SRPUserName(const std::string &Value);

		virtual TSBVersions get_Versions();

		virtual void set_Versions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_Versions, set_Versions, TElAS2SSLOptions, Versions);

		virtual TSBRenegotiationAttackPreventionMode get_RenegotiationAttackPreventionMode();

		virtual void set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value);

		SB_DECLARE_PROPERTY(TSBRenegotiationAttackPreventionMode, get_RenegotiationAttackPreventionMode, set_RenegotiationAttackPreventionMode, TElAS2SSLOptions, RenegotiationAttackPreventionMode);

		TElAS2SSLOptions(TElAS2SSLOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		explicit TElAS2SSLOptions(TElHTTPSClient &AClient);

		explicit TElAS2SSLOptions(TElHTTPSClient *AClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual ~TElAS2SSLOptions();

};
#endif /* SB_USE_CLASS_TELAS2SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS
class TElAS2WebTunnelOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAS2WebTunnelOptions)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual int32_t get_ServerResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ServerResult, TElAS2WebTunnelOptions, ServerResult);

		virtual TElWebTunnelAuthentication get_Authentication();

		virtual void set_Authentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_Authentication, set_Authentication, TElAS2WebTunnelOptions, Authentication);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElAS2WebTunnelOptions, Enabled);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElAS2WebTunnelOptions, Port);

		virtual void get_UserID(std::string &OutResult);

		virtual void set_UserID(const std::string &Value);

		TElAS2WebTunnelOptions(TElAS2WebTunnelOptionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		explicit TElAS2WebTunnelOptions(TElHTTPSClient &AClient);

		explicit TElAS2WebTunnelOptions(TElHTTPSClient *AClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS */

#ifdef SB_USE_CLASS_TELAS2CLIENT
class TElAS2Client: public TComponent
{
	private:
		SB_DISABLE_COPY(TElAS2Client)
#ifdef SB_USE_CLASS_TELAS2HTTPOPTIONS
		TElAS2HTTPOptions* _Inst_HTTP;
#endif /* SB_USE_CLASS_TELAS2HTTPOPTIONS */
#ifdef SB_USE_CLASS_TELAS2PROXYOPTIONS
		TElAS2ProxyOptions* _Inst_Proxy;
#endif /* SB_USE_CLASS_TELAS2PROXYOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SOCKETOPTIONS
		TElAS2SocketOptions* _Inst_Socket;
#endif /* SB_USE_CLASS_TELAS2SOCKETOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SOCKSOPTIONS
		TElAS2SocksOptions* _Inst_Socks;
#endif /* SB_USE_CLASS_TELAS2SOCKSOPTIONS */
#ifdef SB_USE_CLASS_TELAS2SSLOPTIONS
		TElAS2SSLOptions* _Inst_SSL;
#endif /* SB_USE_CLASS_TELAS2SSLOPTIONS */
#ifdef SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS
		TElAS2WebTunnelOptions* _Inst_WebTunnel;
#endif /* SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		int32_t Send(const std::string &URL, TStream &Message, TStream &Receipt);

		int32_t Send(const std::string &URL, TStream *Message, TStream *Receipt);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t Send(const std::string &URL, const std::string &MessageFile, const std::string &ReceiptFile);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SendReceipt(const std::string &URL, TStream &Receipt);

		int32_t SendReceipt(const std::string &URL, TStream *Receipt);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t SendReceipt(const std::string &URL, const std::string &ReceiptFile);

#ifdef SB_USE_CLASS_TELAS2HTTPOPTIONS
		virtual TElAS2HTTPOptions* get_HTTP();

		virtual void set_HTTP(TElAS2HTTPOptions &Value);

		virtual void set_HTTP(TElAS2HTTPOptions *Value);

		SB_DECLARE_PROPERTY(TElAS2HTTPOptions*, get_HTTP, set_HTTP, TElAS2Client, HTTP);
#endif /* SB_USE_CLASS_TELAS2HTTPOPTIONS */

#ifdef SB_USE_CLASS_TELAS2PROXYOPTIONS
		virtual TElAS2ProxyOptions* get_Proxy();

		virtual void set_Proxy(TElAS2ProxyOptions &Value);

		virtual void set_Proxy(TElAS2ProxyOptions *Value);

		SB_DECLARE_PROPERTY(TElAS2ProxyOptions*, get_Proxy, set_Proxy, TElAS2Client, Proxy);
#endif /* SB_USE_CLASS_TELAS2PROXYOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKETOPTIONS
		virtual TElAS2SocketOptions* get_Socket();

		virtual void set_Socket(TElAS2SocketOptions &Value);

		virtual void set_Socket(TElAS2SocketOptions *Value);

		SB_DECLARE_PROPERTY(TElAS2SocketOptions*, get_Socket, set_Socket, TElAS2Client, Socket);
#endif /* SB_USE_CLASS_TELAS2SOCKETOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SOCKSOPTIONS
		virtual TElAS2SocksOptions* get_Socks();

		virtual void set_Socks(TElAS2SocksOptions &Value);

		virtual void set_Socks(TElAS2SocksOptions *Value);

		SB_DECLARE_PROPERTY(TElAS2SocksOptions*, get_Socks, set_Socks, TElAS2Client, Socks);
#endif /* SB_USE_CLASS_TELAS2SOCKSOPTIONS */

#ifdef SB_USE_CLASS_TELAS2SSLOPTIONS
		virtual TElAS2SSLOptions* get_SSL();

		virtual void set_SSL(TElAS2SSLOptions &Value);

		virtual void set_SSL(TElAS2SSLOptions *Value);

		SB_DECLARE_PROPERTY(TElAS2SSLOptions*, get_SSL, set_SSL, TElAS2Client, SSL);
#endif /* SB_USE_CLASS_TELAS2SSLOPTIONS */

#ifdef SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS
		virtual TElAS2WebTunnelOptions* get_WebTunnel();

		virtual void set_WebTunnel(TElAS2WebTunnelOptions &Value);

		virtual void set_WebTunnel(TElAS2WebTunnelOptions *Value);

		SB_DECLARE_PROPERTY(TElAS2WebTunnelOptions*, get_WebTunnel, set_WebTunnel, TElAS2Client, WebTunnel);
#endif /* SB_USE_CLASS_TELAS2WEBTUNNELOPTIONS */

		virtual void get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCookie(TSBHTTPCookieEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCookie(TSBHTTPCookieEvent pMethodValue, void * pDataValue);

		virtual void get_OnData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnData(TSBDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnDocumentBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDocumentBegin(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnDocumentEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDocumentEnd(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnPreparedHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPreparedHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceivingHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceivingHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue);

		virtual void get_OnRedirection(TSBHTTPRedirectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRedirection(TSBHTTPRedirectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSKeyNeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElAS2Client(TElAS2ClientHandle handle, TElOwnHandle ownHandle);

		explicit TElAS2Client(TComponent &AOwner);

		explicit TElAS2Client(TComponent *AOwner);

		virtual ~TElAS2Client();

};
#endif /* SB_USE_CLASS_TELAS2CLIENT */

#ifdef SB_USE_GLOBAL_PROCS_AS2

bool AS2NameNeedsQuoting(const std::string &AS2Name);

void DequoteAS2Name(const std::string &Value, std::string &OutResult);

void QuoteAS2Name(const std::string &AS2Name, std::string &OutResult);

bool ValidAS2Name(const std::string &Name);

#endif /* SB_USE_GLOBAL_PROCS_AS2 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_AS2
SB_IMPORT uint32_t SB_APIENTRY SBAS2_AS2NameNeedsQuoting(const char * pcAS2Name, int32_t szAS2Name, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAS2_DequoteAS2Name(const char * pcValue, int32_t szValue, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAS2_QuoteAS2Name(const char * pcAS2Name, int32_t szAS2Name, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAS2_ValidAS2Name(const char * pcName, int32_t szName, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_AS2 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBAS2 */
