#ifndef __INC_SBASRESOURCES
#define __INC_SBASRESOURCES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SASErrorCannotOpenInputFile 	"Cannot open input file: %s"
#define SB_SASErrorCannotOpenOutputFile 	"Cannot open output file: %s"
#define SB_SASErrorInvalidEncryptionAlgorithm 	"Invalid encryption algorithm: %d (0x%0:.4x)"
#define SB_SASErrorInvalidSignatureDigestAlgorithm 	"Invalid signature digest algorithm: %d (0x%0:.4x)"
#define SB_SASErrorInvalidBitsNumber 	"Invalid key length: %d. Value must be between 32 and 256 and should be multiple of 8"
#define SB_SASErrorHeaderAssemblingFailed 	"Failed to assemble a message header. Scopes: %s"
#define SB_SASErrorFileNotExists 	"The file \'%s\' does not exist"
#define SB_SASErrorInvalidSMIMEType 	"\'%s\' is invalid or not supported SMIME type"
#define SB_SASErrorInvalidEncryptionTransferEncoding 	"\'%s\' is invalid or not supported transfer encoding for encrypted data"
#define SB_SASErrorInvalidCompressionTransferEncoding 	"\'%s\' is invalid or not supported transfer encoding for compressed data"
#define SB_SASErrorInvalidEncryptionDisposition 	"\'%s\' is invalid or not supported disposition for encrypted data"
#define SB_SASErrorInvalidContentType 	"\'%s\' is not a valid content type"
#define SB_SASErrorInvalidContentDisposition 	"\'%s\' is invalid or not supported disposition"
#define SB_SASErrorInvalidFileCreationDate 	"\'%s\' is not valid file creation date"
#define SB_SASErrorInvalidFileModificationDate 	"\'%s\' is not valid file modification date"
#define SB_SASErrorInvalidContentTransferEncoding 	"\'%s\' is invalid or not supported transfer encoding"
#define SB_SASErrorInvalidReceiptSignatureProtocol 	"\'%s\' is not a valid receipt signature protocol"
#define SB_SASErrorInvalidReceiptSignatureProtocolRequirement 	"\'%s\' is not a valid receipt signature protocol requirement"
#define SB_SASErrorInvalidReceiptDigestAlgorithm 	"\'%s\' is not a valid receipt digest algorithm"
#define SB_SASErrorInvalidReceiptDigestAlgorithmRequirement 	"\'%s\' is not a valid receipt digest algorithm requirement"
#define SB_SASErrorInvalidSignatureProtocol 	"\'%s\' is not a valid signature protocol"
#define SB_SASErrorInvalidSignatureMicAlg 	"\'%s\' is not a valid signature digest algorithm"
#define SB_SASErrorDecryptionFailed 	"Message decryption failed with error code: 0x%.4x"
#define SB_SASErrorInvalidReportType 	"\'%s\' is not a valid report type"
#define SB_SASErrorInvalidDispositionActionMode 	"\'%s\' is not a valid report action mode"
#define SB_SASErrorInvalidDispositionSendingMode 	"\'%s\' is not a valid report sending mode"
#define SB_SASErrorInvalidDispositionStatus 	"\'%s\' is not a valid report status"
#define SB_SASErrorInvalidDispositionModifier 	"\'%s\' is not a valid report modifier"
#define SB_SASErrorDecompressionFailed 	"Message decompression failed with error code: 0x%.4x"
#define SB_SASErrorInvalidCompressionDisposition 	"\'%s\' is invalid or not supported disposition for compressed data"
#define SB_SAS2ErrorInvalidOriginator 	"AS2From: \'%s\' is not a valid AS2 name"
#define SB_SAS2ErrorInvalidRecipient 	"AS2To: \'%s\' is not a valid AS2 name"
#define SB_SAS2ErrorInvalidVersion 	"AS2Version: \'%s\' is invalid or not supported AS2 protocol version"
#define SB_SAS3ErrorInvalidOriginator 	"AS3From: \'%s\' is not a valid AS3 name"
#define SB_SAS3ErrorInvalidRecipient 	"AS3To: \'%s\' is not a valid AS3 name"
#define SB_SAS3ErrorInvalidVersion 	"AS3Version: \'%s\' is not a valid AS3 protocol version"
#define SB_SASErrorNoReceiptTarget 	"No receipt request destination address or URL specified"
#define SB_SASErrorNoEncryptingCertificates 	"No certificates for encryption specified"
#define SB_SASErrorNoSigningCertificates 	"No certificates for signing specified"
#define SB_SASErrorSigningFailed 	"Failed to sign data"
#define SB_SASErrorVerificationFailed 	"Failed to verify signatures"
#define SB_SASErrorEncryptionFailed 	"Failed to encrypt data"
#define SB_SASErrorInternal 	"Internal error"
#define SB_SASErrorNoOutputStream 	"There is no output stream specified"
#define SB_SASErrorInvalidMessageHeader 	"Invalid message header"
#define SB_SASErrorInvalidMessageHeaderCharset 	"Invalid charset in message header"
#define SB_SASErrorInvalidMessageDate 	"Invalid message date"
#define SB_SASErrorNoVersion 	"No protocol version specified"
#define SB_SASErrorNoMessageID 	"No message ID specified"
#define SB_SASErrorNoSMIMEType 	"No SMIME type specified"
#define SB_SASErrorNoEncryptionTransferEncoding 	"No transfer encoding specified for encrypted message"
#define SB_SASErrorNoCompressionTransferEncoding 	"No transfer encoding specified for compressed message"
#define SB_SASErrorNoEncryptionDisposition 	"No disposition specified for encrypted message"
#define SB_SASErrorNoContentType 	"No content type specified"
#define SB_SASErrorNoContentDisposition 	"No content disposition specified"
#define SB_SASErrorNoFileName 	"No file name specified"
#define SB_SASErrorNoFileCreationTime 	"No file creation time specified"
#define SB_SASErrorNoFileModificationTime 	"No file modification time specified"
#define SB_SASErrorNoContentTransferEncoding 	"No content transfer encoding specified"
#define SB_SASErrorInvalidReceiptRequestOptions 	"Receipt request options cannot be recognized"
#define SB_SASErrorNoReceiptSignatureProtocol 	"No receipt signature protocol specified"
#define SB_SASErrorNoReceiptSignatureProtocolRequirement 	"No receipt signature protocol requirement specified"
#define SB_SASErrorNoReceiptDigestAlgorithm 	"No supported receipt digest algorithm specified"
#define SB_SASErrorNoReceiptDigestAlgorithmRequirement 	"No receipt digest algorithm requirement specified"
#define SB_SASErrorNoSignatureProtocol 	"No signature protocol specified for signed message"
#define SB_SASErrorNoSignatureMicAlg 	"No signature digest algorithm specified for signed message"
#define SB_SASErrorNoSignatureBoundary 	"No boundary line specified for multipart message"
#define SB_SASErrorErrorsAssemblingFailed 	"Faile to asseble errors information"
#define SB_SASErrorNoReportBoundary 	"No boundary line specified for multipart report"
#define SB_SASErrorInvalidReportDispositionFormat 	"Invalid report disposition field format"
#define SB_SAS1ErrorEmptyOriginator 	"From field cannot be empty"
#define SB_SAS1ErrorEmptyRecipient 	"To field cannot be empty"
#define SB_SAS2ErrorEmptyOriginator 	"AS2From field cannot be empty"
#define SB_SAS2ErrorEmptyRecipient 	"AS2To field cannot be empty"
#define SB_SAS3ErrorEmptyOriginator 	"AS3From field cannot be empty"
#define SB_SAS3ErrorEmptyRecipient 	"AS3To field cannot be empty"
#define SB_SASErrorInvalidMessageCharset 	"Invalid charset in message"
#define SB_SASErrorInvalidMessageFormat 	"Invalid message format"
#define SB_SASErrorNoReportType 	"Report type is not specified"
#define SB_SASErrorInvalidCompressionLevel 	"Compression level must be between 1 (lowest) and 9 (highest)"
#define SB_SASErrorNoCompressionDisposition 	"No disposition specified for compressed message"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBASRESOURCES */

