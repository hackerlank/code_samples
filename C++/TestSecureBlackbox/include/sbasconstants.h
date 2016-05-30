#ifndef __INC_SBASCONSTANTS
#define __INC_SBASCONSTANTS

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
#define SB_AS_ERROR_BASE 	9984
#define SB_AS_ERROR_INTERNAL 	9984
#define SB_AS_ERROR_CANNOT_OPEN_INPUT 	9985
#define SB_AS_ERROR_CANNOT_OPEN_OUTPUT 	9986
#define SB_AS_ERROR_INVALID_ENCRYPTION_ALGORITHM 	9987
#define SB_AS_ERROR_INVALID_BITS_NUMBER 	9988
#define SB_AS_ERROR_NO_RECEIPT_TARGET 	9989
#define SB_AS_ERROR_NO_ENCRYPTING_CERTIFICATES 	9990
#define SB_AS_ERROR_NO_SIGNING_CERTIFICATES 	9991
#define SB_AS_ERROR_INVALID_ORIGINATOR 	9992
#define SB_AS_ERROR_INVALID_RECIPIENT 	9993
#define SB_AS_ERROR_HEADER_ASSEMBLING_FAILED 	9994
#define SB_AS_ERROR_NO_OUTPUT_STREAM 	9995
#define SB_AS_ERROR_FILE_NOT_EXISTS 	9996
#define SB_AS_ERROR_INVALID_MESSAGE_HEADER 	9997
#define SB_AS_ERROR_INVALID_MESSAGE_HEADER_CHARSET 	9998
#define SB_AS_ERROR_INVALID_MESSAGE_DATE 	9999
#define SB_AS_ERROR_INVALID_VERSION 	10000
#define SB_AS_ERROR_NO_VERSION 	10001
#define SB_AS_ERROR_NO_MESSAGE_ID 	10002
#define SB_AS_ERROR_NO_SMIME_TYPE 	10003
#define SB_AS_ERROR_INVALID_SMIME_TYPE 	10004
#define SB_AS_ERROR_NO_ENCRYPTION_TRANSFER_ENCODING 	10005
#define SB_AS_ERROR_INVALID_ENCRYPTION_TRANSFER_ENCODING 	10006
#define SB_AS_ERROR_NO_ENCRYPTION_DISPOSITION 	10007
#define SB_AS_ERROR_INVALID_ENCRYPTION_DISPOSITION 	10008
#define SB_AS_ERROR_NO_CONTENT_TYPE 	10009
#define SB_AS_ERROR_INVALID_CONTENT_TYPE 	10037
#define SB_AS_ERROR_NO_CONTENT_DISPOSITION 	10010
#define SB_AS_ERROR_INVALID_CONTENT_DISPOSITION 	10011
#define SB_AS_ERROR_NO_FILE_NAME 	10012
#define SB_AS_ERROR_NO_FILE_CREATION_DATE 	10013
#define SB_AS_ERROR_INVALID_FILE_CREATION_DATE 	10014
#define SB_AS_ERROR_NO_FILE_MODIFICATION_DATE 	10015
#define SB_AS_ERROR_INVALID_FILE_MODIFICATION_DATE 	10016
#define SB_AS_ERROR_NO_CONTENT_TRANSFER_ENCODING 	10017
#define SB_AS_ERROR_INVALID_CONTENT_TRANSFER_ENCODING 	10018
#define SB_AS_MIME_INVALID_RECEIPT_REQUEST_OPTIONS 	10019
#define SB_AS_ERROR_NO_RECEIPT_SIGNATURE_PROTOCOL 	10020
#define SB_AS_ERROR_INVALID_RECEIPT_SIGNATURE_PROTOCOL 	10021
#define SB_AS_ERROR_NO_RECEIPT_SIGNATURE_PROTOCOL_REQUIREMENT 	10022
#define SB_AS_ERROR_INVALID_RECEIPT_SIGNATURE_PROTOCOL_REQUIREMENT 	10023
#define SB_AS_ERROR_NO_RECEIPT_DIGEST_ALGORITHM 	10024
#define SB_AS_ERROR_NO_RECEIPT_DIGEST_ALGORITHM_REQUIREMENT 	10025
#define SB_AS_ERROR_INVALID_RECEIPT_DIGEST_ALGORITHM 	10026
#define SB_AS_ERROR_INVALID_RECEIPT_DIGEST_ALGORITHM_REQUIREMENT 	10027
#define SB_AS_ERROR_NO_SIGNATURE_PROTOCOL 	10028
#define SB_AS_ERROR_INVALID_SIGNATURE_PROTOCOL 	10029
#define SB_AS_ERROR_NO_SIGNATURE_MICALG 	10030
#define SB_AS_ERROR_INVALID_SIGNATURE_MICALG 	10031
#define SB_AS_ERROR_NO_SIGNATURE_BOUNDARY 	10032
#define SB_AS_ERROR_INVALID_MESSAGE_CHARSET 	10033
#define SB_AS_ERROR_INVALID_MESSAGE_FORMAT 	10034
#define SB_AS_ERROR_DECRYPTION_FAILED 	10035
#define SB_AS_ERROR_NO_REPORT_TYPE 	10038
#define SB_AS_ERROR_INVALID_REPORT_TYPE 	10039
#define SB_AS_ERROR_NO_REPORT_BOUNDARY 	10040
#define SB_AS_ERROR_INVALID_RECEIPT_DISPOSITION_FORMAT 	10041
#define SB_AS_ERROR_INVALID_DISPOSITION_ACTION_MODE 	10042
#define SB_AS_ERROR_INVALID_DISPOSITION_SENDING_MODE 	10043
#define SB_AS_ERROR_INVALID_DISPOSITION_STATUS 	10044
#define SB_AS_ERROR_INVALID_DISPOSITION_MODIFIER 	10045
#define SB_AS_ERROR_INVALID_SIGNATURE_DIGEST_ALGORITHM 	10046
#define SB_AS_ERROR_INVALID_COMPRESSION_LEVEL 	10047
#define SB_AS_ERROR_DECOMPRESSION_FAILED 	10048
#define SB_AS_ERROR_NO_COMPRESSION_DISPOSITION 	10049
#define SB_AS_ERROR_INVALID_COMPRESSION_DISPOSITION 	10050
#define SB_AS_ERROR_NO_COMPRESSION_TRANSFER_ENCODING 	10051
#define SB_AS_ERROR_INVALID_COMPRESSION_TRANSFER_ENCODING 	10052
#define SB_AS_MIME_DELIMITER 	": "
#define SB_AS_MIME_DEFAULT_CHARSET 	"us-ascii"
#define SB_AS_MIME_DEFAULT_CONTENT_TYPE 	"application/octet-stream"
#define SB_AS_MIME_DEFAULT_ENVELOPE_FILENAME 	"smime.p7m"
#define SB_AS_MIME_DEFAULT_SIGNATURE_FILENAME 	"smime.p7s"
#define SB_AS_MIME_DEFAULT_COMPRESSED_FILENAME 	"smime.p7z"
#define SB_AS_MIME_OPTIONAL 	"optional"
#define SB_AS_MIME_REQUIRED 	"required"
#define SB_AS_MIME_PKCS7_SIGNATURE 	"pkcs7-signature"
#define SB_AS_MIME_SHA1 	"sha1"
#define SB_AS_MIME_MD5 	"md5"
#define SB_AS_MIME_SHA_1 	"sha-1"
#define SB_AS_MIME_SHA_224 	"sha-224"
#define SB_AS_MIME_SHA_256 	"sha-256"
#define SB_AS_MIME_SHA_384 	"sha-384"
#define SB_AS_MIME_SHA_512 	"sha-512"
#define SB_AS_MIME_SHA224 	"sha224"
#define SB_AS_MIME_SHA256 	"sha256"
#define SB_AS_MIME_SHA384 	"sha384"
#define SB_AS_MIME_SHA512 	"sha512"
#define SB_AS_MIME_SIGNED_RECEIPT_PROTOCOL 	"signed-receipt-protocol"
#define SB_AS_MIME_SIGNED_RECEIPT_MICALG 	"signed-receipt-micalg"
#define SB_AS_MIME_APPLICATION_EDIFACT 	"application/edifact"
#define SB_AS_MIME_APPLICATION_EDI_X12 	"application/edi-x12"
#define SB_AS_MIME_APPLICATION_XML 	"application/xml"
#define SB_AS_MIME_APPLICATION_OCTET_STREAM 	"application/octet-stream"
#define SB_AS_MIME_APPLICATION_PKCS7_MIME 	"application/pkcs7-mime"
#define SB_AS_MIME_APPLICATION_PKCS7_SIGNATURE 	"application/pkcs7-signature"
#define SB_AS_MIME_MULTIPART_SIGNED 	"multipart/signed"
#define SB_AS_MIME_SMIME_TYPE 	"smime-type"
#define SB_AS_MIME_ENVELOPED_DATA 	"enveloped-data"
#define SB_AS_MIME_COMPRESSED_DATA 	"compressed-data"
#define SB_AS_MIME_ATTACHMENT 	"attachment"
#define SB_AS_MIME_INLINE 	"inline"
#define SB_AS_MIME_FILENAME 	"filename"
#define SB_AS_MIME_PROTOCOL 	"protocol"
#define SB_AS_MIME_MICALG 	"micalg"
#define SB_AS_MIME_BOUNDARY 	"boundary"
#define SB_AS_MIME_CREATION_DATE 	"creation-date"
#define SB_AS_MIME_MODIFICATION_DATE 	"modification-date"
#define SB_AS_MIME_NAME 	"name"
#define SB_AS_MIME_7BIT 	"7bit"
#define SB_AS_MIME_8BIT 	"8bit"
#define SB_AS_MIME_BINARY 	"binary"
#define SB_AS_MIME_BASE64 	"base64"
#define SB_AS_MIME_QUOTED_PRINTABLE 	"quoted-printable"
#define SB_AS_MIME_1_0 	"1.0"
#define SB_AS_MIME_1_1 	"1.1"
#define SB_AS_MIME_1_2 	"1.2"
#define SB_AS_MIME_MULTIPART_REPORT 	"multipart/report"
#define SB_AS_MIME_REPORT_TYPE 	"report-type"
#define SB_AS_MIME_DISPOSITION_NOTIFICATION 	"disposition-notification"
#define SB_AS_MIME_TEXT_PLAIN 	"text/plain"
#define SB_AS_MIME_MESSAGE_DISPOSITION_NOTIFICATION 	"message/disposition-notification"
#define SB_AS_MIME_CHARSET 	"charset"
#define SB_AS_MIME_MANUAL_ACTION 	"manual-action"
#define SB_AS_MIME_AUTOMATIC_ACTION 	"automatic-action"
#define SB_AS_MIME_MDN_SENT_MANUALLY 	"MDN-sent-manually"
#define SB_AS_MIME_MDN_SENT_AUTOMATICALLY 	"MDN-sent-automatically"
#define SB_AS_MIME_PROCESSED 	"processed"
#define SB_AS_MIME_FAILED 	"failed"
#define SB_AS_MIME_WARNING 	"warning"
#define SB_AS_MIME_ERROR 	"error"
#define SB_AS_MIME_FAILURE 	"failure"
#define SB_AS_MIME_CODE 	"code"
#define SB_AS_MIME_DESCRIPTION 	"description"
#define SB_AS_MIME_FROM 	"From"
#define SB_AS_MIME_TO 	"To"
#define SB_AS_MIME_DATE 	"Date"
#define SB_AS_MIME_SUBJECT 	"Subject"
#define SB_AS_MIME_MESSAGE_ID 	"Message-ID"
#define SB_AS_MIME_CONTENT_TYPE 	"Content-Type"
#define SB_AS_MIME_CONTENT_DISPOSITION 	"Content-Disposition"
#define SB_AS_MIME_CONTENT_TRANSFER_ENCODING 	"Content-Transfer-Encoding"
#define SB_AS_MIME_DISPOSITION_NOTIFICATION_TO 	"Disposition-Notification-To"
#define SB_AS_MIME_DISPOSITION_NOTIFICATION_OPTIONS 	"Disposition-Notification-Options"
#define SB_AS_MIME_RECEIPT_DELIVERY_OPTION 	"Receipt-Delivery-Option"
#define SB_AS_MIME_AS2_FROM 	"AS2-From"
#define SB_AS_MIME_AS2_TO 	"AS2-To"
#define SB_AS_MIME_AS2_VERSION 	"AS2-Version"
#define SB_AS_MIME_AS3_FROM 	"AS3-From"
#define SB_AS_MIME_AS3_TO 	"AS3-To"
#define SB_AS_MIME_AS3_VERSION 	"AS3-Version"
#define SB_AS_MIME_VERSION 	"MIME-Version"
#define SB_AS_MIME_FINAL_RECIPIENT 	"Final-Recipient"
#define SB_AS_MIME_MDN_GATEWAY 	"MDN-Gateway"
#define SB_AS_MIME_ORIGINAL_MESSAGE_ID 	"Original-Message-ID"
#define SB_AS_MIME_ORIGINAL_RECIPIENT 	"Original-Recipient"
#define SB_AS_MIME_REPORTING_UA 	"Reporting-UA"
#define SB_AS_MIME_RECEIVED_CONTENT_MIC 	"Received-Content-MIC"
#define SB_AS_MIME_DISPOSITION 	"Disposition"
#define SB_AS_MIME_FIELD_WARNING 	"Warning"
#define SB_AS_MIME_FIELD_ERROR 	"Error"
#define SB_AS_MIME_FIELD_FAILURE 	"Failure"
#define SB_AS_MIME_X_SB_DETAILS 	"X-SB-Details"
#define SB_AS_MIME_EDIINT_FEATURES 	"EDIINT-Features"
#define SB_AS_MDN_UNSUPPORTED_FORMAT 	"unsupported format"
#define SB_AS_MDN_UNSUPPORTED_MIC_ALGORITHMS 	"unsupported mic-algorithms"
#define SB_AS_MDN_AUTHENTICATION_FAILED 	"authentication-failed"
#define SB_AS_MDN_DECOMPRESSION_FAILED 	"decompression-failed"
#define SB_AS_MDN_DECRYPTION_FAILED 	"decryption-failed"
#define SB_AS_MDN_INSUFFICIENT_MESSAGE_SECURITY 	"insufficient-message-security"
#define SB_AS_MDN_INTEGRITY_CHECK_FAILED 	"integrity-check-failed"
#define SB_AS_MDN_UNEXPECTED_PROCESSING_ERROR 	"unexpected-processing-error"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBASCONSTANTS */
