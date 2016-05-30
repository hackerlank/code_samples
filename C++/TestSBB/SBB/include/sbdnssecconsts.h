#ifndef __INC_SBDNSSECCONSTS
#define __INC_SBDNSSECCONSTS

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
#define SB_DNS_ALGORITHM_RSAMD5 	1
#define SB_DNS_ALGORITHM_DH 	2
#define SB_DNS_ALGORITHM_DSASHA1 	3
#define SB_DNS_ALGORITHM_ECC 	4
#define SB_DNS_ALGORITHM_RSASHA1 	5
#define SB_DNS_ALGORITHM_DSA_NSEC3_SHA1 	6
#define SB_DNS_ALGORITHM_RSASHA1_NSEC3_SHA1 	7
#define SB_DNS_ALGORITHM_RSASHA256 	8
#define SB_DNS_ALGORITHM_RSASHA512 	10
#define SB_DNS_ALGORITHM_INDIRECT 	252
#define SB_DNS_ALGORITHM_PRIVATEDNS 	253
#define SB_DNS_ALGORITHM_PRIVATEOID 	254
#define SB_DNS_DIGEST_SHA1 	1
#define SB_DNS_DIGEST_SHA256 	2
#define SB_DNS_CODE_BASE 	42752
#define SB_DNS_RESULT_SUCCESS 	0
#define SB_DNS_RESULT_FIRST 	42752
#define SB_DNS_RESULT_LAST 	42755
#define SB_DNS_RESULT_NAME_NOT_FOUND 	42752
#define SB_DNS_RESULT_INFO_NOT_FOUND 	42753
#define SB_DNS_RESULT_SERVER_FAILURE 	42754
#define SB_DNS_RESULT_TIMEOUT 	42755
#define SB_DNS_VERIFY_SUCCESS 	0
#define SB_DNS_VERIFY_FIRST 	42768
#define SB_DNS_VERIFY_NO_SIGNATURE 	42768
#define SB_DNS_VERIFY_NO_SIGNED_RECORDS 	42769
#define SB_DNS_VERIFY_INVALID_SIGNER 	42770
#define SB_DNS_VERIFY_SIGNATURE_EXPIRED 	42771
#define SB_DNS_VERIFY_SIGNATURE_NOT_YET_VALID 	42772
#define SB_DNS_VERIFY_UNKNOWN_ALGORITHM 	42773
#define SB_DNS_VERIFY_NO_KEY 	42774
#define SB_DNS_VERIFY_INVALID_KEY 	42775
#define SB_DNS_VERIFY_INVALID_SIGNATURE 	42776
#define SB_DNS_VERIFY_FAILED 	42777
#define SB_DNS_VERIFY_NOT_CHECKED 	42778
#define SB_DNS_VERIFY_TIMEOUT 	42779
#define SB_DNS_VERIFY_INSECURE 	42780
#define SB_DNS_VERIFY_INDETERMINATE 	42781
#define SB_DNS_VERIFY_BOGUS 	42782
#define SB_DNS_VERIFY_LAST 	42782
#define SB_DNS_ERROR_BASE 	42800
#define SB_DNS_OUT_OF_BUFFER 	42800
#define SB_DNS_INVALID_MESSAGE_SIZE 	42801
#define SB_DNS_INVALID_RESOURCE_TYPE 	42802
#define SB_DNS_INVALID_OPERATION_CODE 	42803
#define SB_DNS_INVALID_RESPONSE_CODE 	42804
#define SB_DNS_UNKNOWN_QUESTION_CLASS 	42805
#define SB_DNS_INVALID_IPv4_DATA_SIZE 	42806
#define SB_DNS_INVALID_IPv6_DATA_SIZE 	42807
#define SB_DNS_INVALID_INDEX 	42808
#define SB_DNS_INVALID_WKS_DATA_SIZE 	42809
#define SB_DNS_INVALID_PUBLIC_KEY_DATA_SIZE 	42810
#define SB_DNS_INVALID_SIGNATURE_DATA_SIZE 	42811
#define SB_DNS_INVALID_DELEGATION_SIGNER_DATA_SIZE 	42812
#define SB_DNS_INVALID_SERVICE_LOCATION_FORMAT 	42813
#define SB_DNS_SIGNATURE_NOT_FOUND 	42814
#define SB_DNS_NO_RESOURCE_DATA 	42815
#define SB_DNS_INVALID_IPv4_ADDRESS 	42816
#define SB_DNS_INVALID_IPv6_ADDRESS 	42817
#define SB_DNS_ERROR_UNASSIGNED_HANDLER 	42832
#define SB_DNS_ERROR_TIMEOUT 	42833
#define SB_DNS_ERROR_SECURITY_FAILURE 	42834
#define SB_SDNSErrorOutOfBuffer 	"Out of buffer. Offset: %d. Buffer size: %d"
#define SB_SDNSErrorInvalidMessageSize 	"Invalid DNS message size: %d (expected at least 12 bytes)"
#define SB_SDNSErrorUnknownQuestionClass 	"Unknown question class: %d (0x%0:.4x)"
#define SB_SDNSErrorInvalidIPv4DataSize 	"Invalid IPv4 (A) record data size: %d (expected 4 bytes)"
#define SB_SDNSErrorInvalidIPv6DataSize 	"Invalid IPv6 (AAAA) record data size: %d (expected 16 bytes)"
#define SB_SDNSErrorInvalidIndex 	"Invalid index value: %d"
#define SB_SDNSErrorInvalidWKSDataSize 	"Invalid Well-Known-Service (WKS) record data size: %d (expected at least 5 bytes)"
#define SB_SDNSErrorInvalidPublicKeyDataSize 	"Invalid Public Key (DNSKEY) record data size: %d (expected at least 4 bytes)"
#define SB_SDNSErrorInvalidSignatureDataSize 	"Invalid Signature (RRSIG) record data size: %d (expected at least 19 bytes)"
#define SB_SDNSErrorInvalidDelegationSignerDataSize 	"Invalid Delegation Signer (DS) record data size: %d (expected at least 4 bytes)"
#define SB_SDNSErrorInvalidServiceLocationFormat 	"Invalid Service Location name format: %s (expected _SERVICE._PROTOCOL.DOMAIN.NAME)"
#define SB_SDNSErrorInvalidIPv4Address 	"Invalid IPv4 address: %s"
#define SB_SDNSErrorInvalidIPv6Address 	"Invalid IPv6 address or unsupported format: %s"
#define SB_SDNSErrorInvalidVerificationCode 	"Invalid verification code: %d"
#define SB_SDNSErrorSecurityFailure 	"Host name was resolved with unacceptable security status: %s"
#define SB_SDNSErrorInvalidSecurityStatus 	"Invalid security status: %s"
#define SB_SDNSErrorInvalidResourceType 	"Invalid resource type"
#define SB_SDNSErrorInvalidOperationCode 	"Invalid operation code"
#define SB_SDNSErrorInvalidResponseCode 	"Invalid response code"
#define SB_SDNSErrorSocketError 	"Socket error"
#define SB_SDNSErrorSocketTimeout 	"Socket timed out"
#define SB_SDNSErrorSignatureNotFound 	"The signature not found in the message"
#define SB_SDNSErrorNoResourceData 	"No resource data to store into the stream"
#define SB_SDNSErrorNoServers 	"DNS server(s) not specified"
#define SB_SDNSErrorVerifyFailure 	"Internal error while verifying signatures"
#define SB_SDNSErrorUnassignedHandler 	"DNS key validation handler is not assigned. Please handle the OnDNSKeyValidate event and implement proper key validation code there."
#define SB_SDNSErrorTimeout 	"Timeout occured while resolving a host name"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDNSSECCONSTS */

