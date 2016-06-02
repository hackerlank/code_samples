#ifndef __INC_SBSSPI
#define __INC_SBSSPI

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef SB_WINDOWS
#define SB_SECPKG_FLAG_INTEGRITY 	1
#define SB_SECPKG_FLAG_PRIVACY 	2
#define SB_SECPKG_FLAG_TOKEN_ONLY 	4
#define SB_SECPKG_FLAG_DATAGRAM 	8
#define SB_SECPKG_FLAG_CONNECTION 	16
#define SB_SECPKG_FLAG_MULTI_REQUIRED 	32
#define SB_SECPKG_FLAG_CLIENT_ONLY 	64
#define SB_SECPKG_FLAG_EXTENDED_ERROR 	128
#define SB_SECPKG_FLAG_IMPERSONATION 	256
#define SB_SECPKG_FLAG_ACCEPT_WIN32_NAME 	512
#define SB_SECPKG_FLAG_STREAM 	1024
#define SB_SECPKG_FLAG_NEGOTIABLE 	2048
#define SB_SECPKG_FLAG_GSS_COMPATIBLE 	4096
#define SB_SECPKG_FLAG_LOGON 	8192
#define SB_SECPKG_FLAG_ASCII_BUFFERS 	16384
#define SB_SECPKG_FLAG_FRAGMENT 	32768
#define SB_SECPKG_FLAG_MUTUAL_AUTH 	65536
#define SB_SECPKG_FLAG_DELEGATION 	131072
#define SB_SECPKG_FLAG_READONLY_WITH_CHECKSUM 	262144
#define SB_SECPKG_ID_NONE 	65535
#define SB_SECBUFFER_VERSION 	0
#define SB_SECBUFFER_EMPTY 	0
#define SB_SECBUFFER_DATA 	1
#define SB_SECBUFFER_TOKEN 	2
#define SB_SECBUFFER_PKG_PARAMS 	3
#define SB_SECBUFFER_MISSING 	4
#define SB_SECBUFFER_EXTRA 	5
#define SB_SECBUFFER_STREAM_TRAILER 	6
#define SB_SECBUFFER_STREAM_HEADER 	7
#define SB_SECBUFFER_NEGOTIATION_INFO 	8
#define SB_SECBUFFER_PADDING 	9
#define SB_SECBUFFER_STREAM 	10
#define SB_SECBUFFER_MECHLIST 	11
#define SB_SECBUFFER_MECHLIST_SIGNATURE 	12
#define SB_SECBUFFER_TARGET 	13
#define SB_SECBUFFER_CHANNEL_BINDINGS 	14
#define SB_SECBUFFER_ATTRMASK 	4026531840
#define SB_SECBUFFER_READONLY 	2147483648
#define SB_SECBUFFER_READONLY_WITH_CHECKSUM 	268435456
#define SB_SECBUFFER_RESERVED 	1610612736
#define SB_SECURITY_NATIVE_DREP 	16
#define SB_SECURITY_NETWORK_DREP 	0
#define SB_SECPKG_CRED_INBOUND 	1
#define SB_SECPKG_CRED_OUTBOUND 	2
#define SB_SECPKG_CRED_BOTH 	3
#define SB_SECPKG_CRED_DEFAULT 	4
#define SB_SECPKG_CRED_RESERVED 	4026531840
#define SB_ISC_REQ_DELEGATE 	1
#define SB_ISC_REQ_MUTUAL_AUTH 	2
#define SB_ISC_REQ_REPLAY_DETECT 	4
#define SB_ISC_REQ_SEQUENCE_DETECT 	8
#define SB_ISC_REQ_CONFIDENTIALITY 	16
#define SB_ISC_REQ_USE_SESSION_KEY 	32
#define SB_ISC_REQ_PROMPT_FOR_CREDS 	64
#define SB_ISC_REQ_USE_SUPPLIED_CREDS 	128
#define SB_ISC_REQ_ALLOCATE_MEMORY 	256
#define SB_ISC_REQ_USE_DCE_STYLE 	512
#define SB_ISC_REQ_DATAGRAM 	1024
#define SB_ISC_REQ_CONNECTION 	2048
#define SB_ISC_REQ_CALL_LEVEL 	4096
#define SB_ISC_REQ_FRAGMENT_SUPPLIED 	8192
#define SB_ISC_REQ_EXTENDED_ERROR 	16384
#define SB_ISC_REQ_STREAM 	32768
#define SB_ISC_REQ_INTEGRITY 	65536
#define SB_ISC_REQ_IDENTIFY 	131072
#define SB_ISC_REQ_NULL_SESSION 	262144
#define SB_ISC_REQ_MANUAL_CRED_VALIDATION 	524288
#define SB_ISC_REQ_RESERVED1 	1048576
#define SB_ISC_REQ_FRAGMENT_TO_FIT 	2097152
#define SB_ISC_RET_DELEGATE 	1
#define SB_ISC_RET_MUTUAL_AUTH 	2
#define SB_ISC_RET_REPLAY_DETECT 	4
#define SB_ISC_RET_SEQUENCE_DETECT 	8
#define SB_ISC_RET_CONFIDENTIALITY 	16
#define SB_ISC_RET_USE_SESSION_KEY 	32
#define SB_ISC_RET_USED_COLLECTED_CREDS 	64
#define SB_ISC_RET_USED_SUPPLIED_CREDS 	128
#define SB_ISC_RET_ALLOCATED_MEMORY 	256
#define SB_ISC_RET_USED_DCE_STYLE 	512
#define SB_ISC_RET_DATAGRAM 	1024
#define SB_ISC_RET_CONNECTION 	2048
#define SB_ISC_RET_INTERMEDIATE_RETURN 	4096
#define SB_ISC_RET_CALL_LEVEL 	8192
#define SB_ISC_RET_EXTENDED_ERROR 	16384
#define SB_ISC_RET_STREAM 	32768
#define SB_ISC_RET_INTEGRITY 	65536
#define SB_ISC_RET_IDENTIFY 	131072
#define SB_ISC_RET_NULL_SESSION 	262144
#define SB_ISC_RET_MANUAL_CRED_VALIDATION 	524288
#define SB_ISC_RET_RESERVED1 	1048576
#define SB_ISC_RET_FRAGMENT_ONLY 	2097152
#define SB_ASC_REQ_DELEGATE 	1
#define SB_ASC_REQ_MUTUAL_AUTH 	2
#define SB_ASC_REQ_REPLAY_DETECT 	4
#define SB_ASC_REQ_SEQUENCE_DETECT 	8
#define SB_ASC_REQ_CONFIDENTIALITY 	16
#define SB_ASC_REQ_USE_SESSION_KEY 	32
#define SB_ASC_REQ_ALLOCATE_MEMORY 	256
#define SB_ASC_REQ_USE_DCE_STYLE 	512
#define SB_ASC_REQ_DATAGRAM 	1024
#define SB_ASC_REQ_CONNECTION 	2048
#define SB_ASC_REQ_CALL_LEVEL 	4096
#define SB_ASC_REQ_EXTENDED_ERROR 	32768
#define SB_ASC_REQ_STREAM 	65536
#define SB_ASC_REQ_INTEGRITY 	131072
#define SB_ASC_REQ_LICENSING 	262144
#define SB_ASC_REQ_IDENTIFY 	524288
#define SB_ASC_REQ_ALLOW_NULL_SESSION 	1048576
#define SB_ASC_REQ_ALLOW_NON_USER_LOGONS 	2097152
#define SB_ASC_REQ_ALLOW_CONTEXT_REPLAY 	4194304
#define SB_ASC_REQ_FRAGMENT_TO_FIT 	8388608
#define SB_ASC_REQ_FRAGMENT_SUPPLIED 	8192
#define SB_ASC_REQ_NO_TOKEN 	16777216
#define SB_ASC_RET_DELEGATE 	1
#define SB_ASC_RET_MUTUAL_AUTH 	2
#define SB_ASC_RET_REPLAY_DETECT 	4
#define SB_ASC_RET_SEQUENCE_DETECT 	8
#define SB_ASC_RET_CONFIDENTIALITY 	16
#define SB_ASC_RET_USE_SESSION_KEY 	32
#define SB_ASC_RET_ALLOCATED_MEMORY 	256
#define SB_ASC_RET_USED_DCE_STYLE 	512
#define SB_ASC_RET_DATAGRAM 	1024
#define SB_ASC_RET_CONNECTION 	2048
#define SB_ASC_RET_CALL_LEVEL 	8192
#define SB_ASC_RET_THIRD_LEG_FAILED 	16384
#define SB_ASC_RET_EXTENDED_ERROR 	32768
#define SB_ASC_RET_STREAM 	65536
#define SB_ASC_RET_INTEGRITY 	131072
#define SB_ASC_RET_LICENSING 	262144
#define SB_ASC_RET_IDENTIFY 	524288
#define SB_ASC_RET_NULL_SESSION 	1048576
#define SB_ASC_RET_ALLOW_NON_USER_LOGONS 	2097152
#define SB_ASC_RET_ALLOW_CONTEXT_REPLAY 	4194304
#define SB_ASC_RET_FRAGMENT_ONLY 	8388608
#define SB_ASC_RET_NO_TOKEN 	16777216
#define SB_SECPKG_CRED_ATTR_NAMES 	1
#define SB_SECPKG_CRED_ATTR_SSI_PROVIDER 	2
#define SB_SECPKG_ATTR_SIZES 	0
#define SB_SECPKG_ATTR_NAMES 	1
#define SB_SECPKG_ATTR_LIFESPAN 	2
#define SB_SECPKG_ATTR_DCE_INFO 	3
#define SB_SECPKG_ATTR_STREAM_SIZES 	4
#define SB_SECPKG_ATTR_KEY_INFO 	5
#define SB_SECPKG_ATTR_AUTHORITY 	6
#define SB_SECPKG_ATTR_PROTO_INFO 	7
#define SB_SECPKG_ATTR_PASSWORD_EXPIRY 	8
#define SB_SECPKG_ATTR_SESSION_KEY 	9
#define SB_SECPKG_ATTR_PACKAGE_INFO 	10
#define SB_SECPKG_ATTR_USER_FLAGS 	11
#define SB_SECPKG_ATTR_NEGOTIATION_INFO 	12
#define SB_SECPKG_ATTR_NATIVE_NAMES 	13
#define SB_SECPKG_ATTR_FLAGS 	14
#define SB_SECPKG_ATTR_USE_VALIDATED 	15
#define SB_SECPKG_ATTR_CREDENTIAL_NAME 	16
#define SB_SECPKG_ATTR_TARGET_INFORMATION 	17
#define SB_SECPKG_ATTR_ACCESS_TOKEN 	18
#define SB_SECPKG_ATTR_TARGET 	19
#define SB_SECPKG_ATTR_AUTHENTICATION_ID 	20
#define SB_SECPKG_ATTR_LOGOFF_TIME 	21
#define SB_SECPKG_NEGOTIATION_COMPLETE 	0
#define SB_SECPKG_NEGOTIATION_OPTIMISTIC 	1
#define SB_SECPKG_NEGOTIATION_IN_PROGRESS 	2
#define SB_SECPKG_NEGOTIATION_DIRECT 	3
#define SB_SECPKG_NEGOTIATION_TRY_MULTICRED 	4
#define SB_SECPKG_CONTEXT_EXPORT_RESET_NEW 	1
#define SB_SECPKG_CONTEXT_EXPORT_DELETE_OLD 	2
#define SB_SECPKG_CONTEXT_EXPORT_TO_KERNEL 	4
#define SB_SECQOP_WRAP_NO_ENCRYPT 	2147483649
#define SB_SECQOP_WRAP_OOB_DATA 	1073741824
#define SB_SECURITY_ENTRYPOINT_ANSIW 	"InitSecurityInterfaceW"
#define SB_SECURITY_ENTRYPOINT_ANSIA 	"InitSecurityInterfaceA"
#define SB_SECURITY_ENTRYPOINTW 	"InitSecurityInterfaceW"
#define SB_SECURITY_ENTRYPOINTA 	"InitSecurityInterfaceA"
#define SB_SECURITY_ENTRYPOINT16 	"INITSECURITYINTERFACEA"
#define SB_SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION 	1
#define SB_SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_2 	2
#define SB_SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_3 	3
#define SB_SEC_WINNT_AUTH_IDENTITY_ANSI 	1
#define SB_SEC_WINNT_AUTH_IDENTITY_UNICODE 	2
#define SB_SEC_WINNT_AUTH_IDENTITY_VERSION 	512
#define SB_SEC_WINNT_AUTH_IDENTITY_MARSHALLED 	4
#define SB_SEC_WINNT_AUTH_IDENTITY_ONLY 	8
#define SB_SEC_E_OK 	0
#define SB_SEC_E_INSUFFICIENT_MEMORY 	-2146893056
#define SB_SEC_E_INVALID_HANDLE 	-2146893055
#define SB_SEC_E_UNSUPPORTED_FUNCTION 	-2146893054
#define SB_SEC_E_TARGET_UNKNOWN 	-2146893053
#define SB_SEC_E_INTERNAL_ERROR 	-2146893052
#define SB_SEC_E_SECPKG_NOT_FOUND 	-2146893051
#define SB_SEC_E_NOT_OWNER 	-2146893050
#define SB_SEC_E_CANNOT_INSTALL 	-2146893049
#define SB_SEC_E_INVALID_TOKEN 	-2146893048
#define SB_SEC_E_CANNOT_PACK 	-2146893047
#define SB_SEC_E_QOP_NOT_SUPPORTED 	-2146893046
#define SB_SEC_E_NO_IMPERSONATION 	-2146893045
#define SB_SEC_E_LOGON_DENIED 	-2146893044
#define SB_SEC_E_UNKNOWN_CREDENTIALS 	-2146893043
#define SB_SEC_E_NO_CREDENTIALS 	-2146893042
#define SB_SEC_E_MESSAGE_ALTERED 	-2146893041
#define SB_SEC_E_OUT_OF_SEQUENCE 	-2146893040
#define SB_SEC_E_NO_AUTHENTICATING_AUTHORITY 	-2146893039
#define SB_SEC_I_CONTINUE_NEEDED 	590610
#define SB_SEC_I_COMPLETE_NEEDED 	590611
#define SB_SEC_I_COMPLETE_AND_CONTINUE 	590612
#define SB_SEC_I_LOCAL_LOGON 	590613
#define SB_SEC_E_BAD_PKGID 	-2146893034
#define SB_SEC_E_CONTEXT_EXPIRED 	-2146893033
#define SB_SEC_E_INCOMPLETE_MESSAGE 	-2146893032
#define SB_SEC_E_INCOMPLETE_CREDENTIALS 	-2146893024
#define SB_SEC_E_BUFFER_TOO_SMALL 	-2146893023
#define SB_SEC_I_INCOMPLETE_CREDENTIALS 	590624
#define SB_SEC_I_RENEGOTIATE 	590625
#define SB_SEC_E_WRONG_PRINCIPAL 	-2146893022
#define SB_SEC_I_NO_LSA_CONTEXT 	590627
#define SB_SEC_E_TIME_SKEW 	-2146893020
#define SB_SEC_E_UNTRUSTED_ROOT 	-2146893019
#define SB_SEC_E_ILLEGAL_MESSAGE 	-2146893018
#define SB_SEC_E_CERT_UNKNOWN 	-2146893017
#define SB_SEC_E_CERT_EXPIRED 	-2146893016
#define SB_SEC_E_ENCRYPT_FAILURE 	-2146893015
#define SB_SEC_E_DECRYPT_FAILURE 	-2146893008
#define SB_SEC_E_ALGORITHM_MISMATCH 	-2146893007
#define SB_SEC_E_SECURITY_QOS_FAILED 	-2146893006
#define SB_SEC_E_UNFINISHED_CONTEXT_DELETED 	-2146893005
#define SB_SEC_E_NO_TGT_REPLY 	-2146893004
#define SB_SEC_E_NO_IP_ADDRESSES 	-2146893003
#define SB_SEC_E_WRONG_CREDENTIAL_HANDLE 	-2146893002
#define SB_SEC_E_CRYPTO_SYSTEM_INVALID 	-2146893001
#define SB_SEC_E_MAX_REFERRALS_EXCEEDED 	-2146893000
#define SB_SEC_E_MUST_BE_KDC 	-2146892999
#define SB_SEC_E_STRONG_CRYPTO_NOT_SUPPORTED 	-2146892998
#define SB_SEC_E_TOO_MANY_PRINCIPALS 	-2146892997
#define SB_SEC_E_NO_PA_DATA 	-2146892996
#define SB_SEC_E_PKINIT_NAME_MISMATCH 	-2146892995
#define SB_SEC_E_SMARTCARD_LOGON_REQUIRED 	-2146892994
#define SB_SEC_E_SHUTDOWN_IN_PROGRESS 	-2146892993
#define SB_SEC_E_KDC_INVALID_REQUEST 	-2146892992
#define SB_SEC_E_KDC_UNABLE_TO_REFER 	-2146892991
#define SB_SEC_E_KDC_UNKNOWN_ETYPE 	-2146892990
#define SB_SEC_E_UNSUPPORTED_PREAUTH 	-2146892989
#define SB_SEC_E_DELEGATION_REQUIRED 	-2146892987
#define SB_SEC_E_BAD_BINDINGS 	-2146892986
#define SB_SEC_E_MULTIPLE_ACCOUNTS 	-2146892985
#define SB_SEC_E_NO_KERB_KEY 	-2146892984
#define SB_SEC_E_CERT_WRONG_USAGE 	-2146892983
#define SB_SEC_E_DOWNGRADE_DETECTED 	-2146892976
#define SB_SEC_E_SMARTCARD_CERT_REVOKED 	-2146892975
#define SB_SEC_E_ISSUING_CA_UNTRUSTED 	-2146892974
#define SB_SEC_E_REVOCATION_OFFLINE_C 	-2146892973
#define SB_SEC_E_PKINIT_CLIENT_FAILURE 	-2146892972
#define SB_SEC_E_SMARTCARD_CERT_EXPIRED 	-2146892971
#define SB_SEC_E_NO_S4U_PROT_SUPPORT 	-2146892970
#define SB_SEC_E_CROSSREALM_DELEGATION_FAILURE 	-2146892969
#define SB_SEC_E_REVOCATION_OFFLINE_KDC 	-2146892968
#define SB_SEC_E_ISSUING_CA_UNTRUSTED_KDC 	-2146892967
#define SB_SEC_E_KDC_CERT_EXPIRED 	-2146892966
#define SB_SEC_E_KDC_CERT_REVOKED 	-2146892965

typedef uint16_t * PUSHORT;

typedef Pointer SBSSPI_PVOID;

typedef windows_LARGE_INTEGER SECURITY_INTEGER;

typedef windows_LARGE_INTEGER TimeStamp;

typedef PWideChar PSEC_WCHAR;

typedef PChar PSEC_CHAR;

typedef int32_t * PSECURITY_STATUS;

typedef sb_char16_t * SECURITY_PSTR;

#pragma pack(4)
typedef struct 
{
	void * dwLower;
	void * dwUpper;
} SecHandle, * PSecHandle;

#ifndef WINCE
typedef SecHandle SBSSPI_CredHandle;
#else
typedef SecHandle CredHandle;
#endif

#ifndef WINCE
typedef SecHandle SBSSPI_CtxtHandle;
#else
typedef SecHandle CtxtHandle;
#endif

#pragma pack(4)
typedef struct 
{
	uint32_t fCapabilities;
	uint16_t wVersion;
	uint16_t wRPCID;
	uint32_t cbMaxToken;
	sb_char16_t * Name;
	sb_char16_t Comment;
} SecPkgInfoW, * PSecPkgInfoW;

#pragma pack(4)
typedef struct 
{
	uint32_t fCapabilities;
	uint16_t wVersion;
	uint16_t wRPCID;
	uint32_t cbMaxToken;
	char * Name;
	char * Comment;
} SecPkgInfoA, * PSecPkgInfoA;

#pragma pack(4)
typedef struct 
{
	uint32_t cbBuffer;
	uint32_t BufferType;
	void * pvBuffer;
#ifndef WINCE
} SBSSPI_SecBuffer, * SBSSPI_PSecBuffer;
#else
} SecBuffer, * PSecBuffer;
#endif

#pragma pack(4)
typedef struct 
{
	uint32_t ulVersion;
	uint32_t cBuffers;
#ifndef WINCE
	SBSSPI_PSecBuffer pBuffers;
} SBSSPI_SecBufferDesc, * SBSSPI_PSecBufferDesc;
#else
	PSecBuffer pBuffers;
} SecBufferDesc, * PSecBufferDesc;
#endif

#pragma pack(4)
typedef struct 
{
	uint32_t Size;
	uint32_t NameLength;
	sb_char16_t * Name;
	void * Reserved;
} SEC_NEGOTIATION_INFO, * PSEC_NEGOTIATION_INFO;

#pragma pack(4)
typedef struct 
{
	uint32_t dwInitiatorAddrType;
	uint32_t cbInitiatorLength;
	uint32_t dwInitiatorOffset;
	uint32_t dwAcceptorAddrType;
	uint32_t cbAcceptorLength;
	uint32_t dwAcceptorOffset;
	uint32_t cbApplicationDataLength;
	uint32_t dwApplicationDataOffset;
} SEC_CHANNEL_BINDINGS, * PSEC_CHANNEL_BINDINGS;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * sUserName;
} SecPkgCredentials_NamesW, * PSecPkgCredentials_NamesW;

#pragma pack(4)
typedef struct 
{
	char * sUserName;
} SecPkgCredentials_NamesA, * PSecPkgCredentials_NamesA;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * sProviderName;
	uint32_t ProviderInfoLength;
	char * ProviderInfo;
} SecPkgCredentials_SSIProviderW, * PSecPkgCredentials_SSIProviderW;

#pragma pack(4)
typedef struct 
{
	char * sProviderName;
	uint32_t ProviderInfoLength;
	char * ProviderInfo;
} SecPkgCredentials_SSIProviderA, * PSecPkgCredentials_SSIProviderA;

#pragma pack(4)
typedef struct 
{
	uint32_t cbMaxToken;
	uint32_t cbMaxSignature;
	uint32_t cbBlockSize;
	uint32_t cbSecurityTrailer;
} SecPkgContext_Sizes, * PSecPkgContext_Sizes;

#pragma pack(4)
typedef struct 
{
	uint32_t cbHeader;
	uint32_t cbTrailer;
	uint32_t cbMaximumMessage;
	uint32_t cBuffers;
	uint32_t cbBlockSize;
} SecPkgContext_StreamSizes, * PSecPkgContext_StreamSizes;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * sUserName;
} SecPkgContext_NamesW, * PSecPkgContext_NamesW;

#pragma pack(4)
typedef struct 
{
	char * sUserName;
} SecPkgContext_NamesA, * PSecPkgContext_NamesA;

#pragma pack(4)
typedef struct 
{
	windows_LARGE_INTEGER tsStart;
	windows_LARGE_INTEGER tsExpiry;
} SecPkgContext_Lifespan, * PSecPkgContext_Lifespan;

#pragma pack(4)
typedef struct 
{
	uint32_t AuthzSvc;
	void * pPac;
} SecPkgContext_DceInfo, * PSecPkgContext_DceInfo;

#pragma pack(4)
typedef struct 
{
	char * sSignatureAlgorithmName;
	char * sEncryptAlgorithmName;
	uint32_t KeySize;
	uint32_t SignatureAlgorithm;
	uint32_t EncryptAlgorithm;
} SecPkgContext_KeyInfoA, * PSecPkgContext_KeyInfoA;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * sSignatureAlgorithmName;
	sb_char16_t * sEncryptAlgorithmName;
	uint32_t KeySize;
	uint32_t SignatureAlgorithm;
	uint32_t EncryptAlgorithm;
} SecPkgContext_KeyInfoW, * PSecPkgContext_KeyInfoW;

#pragma pack(4)
typedef struct 
{
	char * sAuthorityName;
} SecPkgContext_AuthorityA, * PSecPkgContext_AuthorityA;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * sAuthorityName;
} SecPkgContext_AuthorityW, * PSecPkgContext_AuthorityW;

#pragma pack(4)
typedef struct 
{
	char * sProtocolName;
	uint32_t majorVersion;
	uint32_t minorVersion;
} SecPkgContext_ProtoInfoA, * PSecPkgContext_ProtoInfoA;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * sProtocolName;
	uint32_t majorVersion;
	uint32_t minorVersion;
} SecPkgContext_ProtoInfoW, * PSecPkgContext_ProtoInfoW;

#pragma pack(4)
typedef struct 
{
	windows_LARGE_INTEGER tsPasswordExpires;
} SecPkgContext_PasswordExpiry, * PSecPkgContext_PasswordExpiry;

#pragma pack(4)
typedef struct 
{
	uint32_t SessionKeyLength;
	uint8_t * SessionKey;
} SecPkgContext_SessionKey, * PSecPkgContext_SessionKey;

#pragma pack(4)
typedef struct 
{
	PSecPkgInfoW PackageInfo;
} SecPkgContext_PackageInfoW, * PSecPkgContext_PackageInfoW;

#pragma pack(4)
typedef struct 
{
	PSecPkgInfoA PackageInfo;
} SecPkgContext_PackageInfoA, * PSecPkgContext_PackageInfoA;

#pragma pack(4)
typedef struct 
{
	uint32_t UserFlags;
} SecPkgContext_UserFlags, * PSecPkgContext_UserFlags;

#pragma pack(4)
typedef struct 
{
	uint32_t Flags;
} SecPkgContext_Flags, * PSecPkgContext_Flags;

#pragma pack(4)
typedef struct 
{
	PSecPkgInfoA PackageInfo;
	uint32_t NegotiationState;
} SecPkgContext_NegotiationInfoA, * PSecPkgContext_NegotiationInfoA;

#pragma pack(4)
typedef struct 
{
	PSecPkgInfoW PackageInfo;
	uint32_t NegotiationState;
} SecPkgContext_NegotiationInfoW, * PSecPkgContext_NegotiationInfoW;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * sClientName;
	sb_char16_t * sServerName;
} SecPkgContext_NativeNamesW, * PSecPkgContext_NativeNamesW;

#pragma pack(4)
typedef struct 
{
	char * sClientName;
	char * sServerName;
} SecPkgContext_NativeNamesA, * PSecPkgContext_NativeNamesA;

#pragma pack(4)
typedef struct 
{
	uint32_t CredentialType;
	sb_char16_t * sCredentialName;
} SecPkgContext_CredentialNameW, * PSecPkgContext_CredentialNameW;

#pragma pack(4)
typedef struct 
{
	uint32_t CredentialType;
	char * sCredentialName;
} SecPkgContext_CredentialNameA, * PSecPkgContext_CredentialNameA;

#pragma pack(4)
typedef struct 
{
	void * AccessToken;
} SecPkgContext_AccessToken, * PSecPkgContext_AccessToken;

#pragma pack(4)
typedef struct 
{
	uint32_t MarshalledTargetInfoLength;
	uint8_t * MarshalledTargetInfo;
} SecPkgContext_TargetInformation, * PSecPkgContext_TargetInformation;

#pragma pack(4)
typedef struct 
{
	uint32_t AuthzIDLength;
	char * AuthzID;
} SecPkgContext_AuthzID, * PSecPkgContext_AuthzID;

#pragma pack(4)
typedef struct 
{
	uint32_t TargetLength;
	char * Target;
} SecPkgContext_Target, * PSecPkgContext_Target;

#ifndef WINCE
typedef void (SB_CALLBACK *SBSSPI_SEC_GET_KEY_FN)(void * Arg, void * Principal, uint32_t KeyVer, void * (* Key), int32_t * Status, void * (* OutResult));
#else
typedef void (SB_CALLBACK *SEC_GET_KEY_FN)(void * Arg, void * Principal, uint32_t KeyVer, void * (* Key), int32_t * Status, void * (* OutResult));
#endif

typedef windows_LARGE_INTEGER * PTimeStamp;

#ifndef WINCE
typedef void (SB_CALLBACK *ACQUIRE_CREDENTIALS_HANDLE_FN_W)(sb_char16_t * pszPrincipal, sb_char16_t * pszPackage, uint32_t fCredentialUse, void * pvLogonId, void * pAuthData, SBSSPI_SEC_GET_KEY_FN pGetKeyFn, void * pvGetKeyArgument, PSecHandle phCredential, PTimeStamp ptsExpiry, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *ACQUIRE_CREDENTIALS_HANDLE_FN_W)(sb_char16_t * pszPrincipal, sb_char16_t * pszPackage, uint32_t fCredentialUse, void * pvLogonId, void * pAuthData, SEC_GET_KEY_FN pGetKeyFn, void * pvGetKeyArgument, PSecHandle phCredential, PTimeStamp ptsExpiry, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *ACQUIRE_CREDENTIALS_HANDLE_FN_A)(char * pszPrincipal, char * pszPackage, uint32_t fCredentialUse, void * pvLogonId, void * pAuthData, SBSSPI_SEC_GET_KEY_FN pGetKeyFn, void * pvGetKeyArgument, PSecHandle phCredential, PTimeStamp ptsExpiry, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *ACQUIRE_CREDENTIALS_HANDLE_FN_A)(char * pszPrincipal, char * pszPackage, uint32_t fCredentialUse, void * pvLogonId, void * pAuthData, SEC_GET_KEY_FN pGetKeyFn, void * pvGetKeyArgument, PSecHandle phCredential, PTimeStamp ptsExpiry, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *SBSSPI_FREE_CREDENTIALS_HANDLE_FN)(PSecHandle phCredential, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *FREE_CREDENTIALS_HANDLE_FN)(PSecHandle phCredential, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *ADD_CREDENTIALS_FN_W)(PSecHandle hCredentials, sb_char16_t * pszPrincipal, sb_char16_t * pszPackage, uint32_t fCredentialUse, void * pAuthData, SBSSPI_SEC_GET_KEY_FN pGetKeyFn, void * pvGetKeyArgument, PTimeStamp ptsExpiry, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *ADD_CREDENTIALS_FN_W)(PSecHandle hCredentials, sb_char16_t * pszPrincipal, sb_char16_t * pszPackage, uint32_t fCredentialUse, void * pAuthData, SEC_GET_KEY_FN pGetKeyFn, void * pvGetKeyArgument, PTimeStamp ptsExpiry, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *ADD_CREDENTIALS_FN_A)(PSecHandle hCredentials, char * pszPrincipal, char * pszPackage, uint32_t fCredentialUse, void * pAuthData, SBSSPI_SEC_GET_KEY_FN pGetKeyFn, void * pvGetKeyArgument, PTimeStamp ptsExpiry, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *ADD_CREDENTIALS_FN_A)(PSecHandle hCredentials, char * pszPrincipal, char * pszPackage, uint32_t fCredentialUse, void * pAuthData, SEC_GET_KEY_FN pGetKeyFn, void * pvGetKeyArgument, PTimeStamp ptsExpiry, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *INITIALIZE_SECURITY_CONTEXT_FN_W)(PSecHandle phCredential, PSecHandle phContext, sb_char16_t * pszTargetName, uint32_t fContextReq, uint32_t Reserved1, uint32_t TargetDataRep, SBSSPI_PSecBufferDesc pInput, uint32_t Reserved2, PSecHandle phNewContext, SBSSPI_PSecBufferDesc pOutput, uint32_t * pfContextAttr, PTimeStamp ptsExpiry, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *INITIALIZE_SECURITY_CONTEXT_FN_W)(PSecHandle phCredential, PSecHandle phContext, sb_char16_t * pszTargetName, uint32_t fContextReq, uint32_t Reserved1, uint32_t TargetDataRep, PSecBufferDesc pInput, uint32_t Reserved2, PSecHandle phNewContext, PSecBufferDesc pOutput, uint32_t * pfContextAttr, PTimeStamp ptsExpiry, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *INITIALIZE_SECURITY_CONTEXT_FN_A)(PSecHandle phCredential, PSecHandle phContext, char * pszTargetName, uint32_t fContextReq, uint32_t Reserved1, uint32_t TargetDataRep, SBSSPI_PSecBufferDesc pInput, uint32_t Reserved2, PSecHandle phNewContext, SBSSPI_PSecBufferDesc pOutput, uint32_t * pfContextAttr, PTimeStamp ptsExpiry, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *INITIALIZE_SECURITY_CONTEXT_FN_A)(PSecHandle phCredential, PSecHandle phContext, char * pszTargetName, uint32_t fContextReq, uint32_t Reserved1, uint32_t TargetDataRep, PSecBufferDesc pInput, uint32_t Reserved2, PSecHandle phNewContext, PSecBufferDesc pOutput, uint32_t * pfContextAttr, PTimeStamp ptsExpiry, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *ACCEPT_SECURITY_CONTEXT_FN)(PSecHandle phCredential, PSecHandle phContext, SBSSPI_PSecBufferDesc pInput, uint32_t fContextReq, uint32_t TargetDataRep, PSecHandle phNewContext, SBSSPI_PSecBufferDesc pOutput, uint32_t * pfContextAttr, PTimeStamp ptsExpiry, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *ACCEPT_SECURITY_CONTEXT_FN)(PSecHandle phCredential, PSecHandle phContext, PSecBufferDesc pInput, uint32_t fContextReq, uint32_t TargetDataRep, PSecHandle phNewContext, PSecBufferDesc pOutput, uint32_t * pfContextAttr, PTimeStamp ptsExpiry, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *SBSSPI_COMPLETE_AUTH_TOKEN_FN)(PSecHandle phContext, SBSSPI_PSecBufferDesc pToken, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *COMPLETE_AUTH_TOKEN_FN)(PSecHandle phContext, PSecBufferDesc pToken, int32_t * OutResult);
#endif

typedef void (SB_CALLBACK *IMPERSONATE_SECURITY_CONTEXT_FN)(PSecHandle phContext, int32_t * OutResult);

typedef void (SB_CALLBACK *REVERT_SECURITY_CONTEXT_FN)(PSecHandle phContext, int32_t * OutResult);

typedef void (SB_CALLBACK *QUERY_SECURITY_CONTEXT_TOKEN_FN)(PSecHandle phContext, void * (* Token), int32_t * OutResult);

#ifndef WINCE
typedef void (SB_CALLBACK *SBSSPI_DELETE_SECURITY_CONTEXT_FN)(PSecHandle phContext, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *DELETE_SECURITY_CONTEXT_FN)(PSecHandle phContext, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *APPLY_CONTROL_TOKEN_FN)(PSecHandle phContext, SBSSPI_PSecBufferDesc pInput, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *APPLY_CONTROL_TOKEN_FN)(PSecHandle phContext, PSecBufferDesc pInput, int32_t * OutResult);
#endif

typedef void (SB_CALLBACK *QUERY_CONTEXT_ATTRIBUTES_FN_W)(PSecHandle phContext, uint32_t ulAttribute, void * pBuffer, int32_t * OutResult);

typedef void (SB_CALLBACK *QUERY_CONTEXT_ATTRIBUTES_FN_A)(PSecHandle phContext, uint32_t ulAttribute, void * pBuffer, int32_t * OutResult);

typedef void (SB_CALLBACK *QUERY_CREDENTIALS_ATTRIBUTES_FN_W)(PSecHandle phCredential, uint32_t ulAttribute, void * pBuffer, int32_t * OutResult);

typedef void (SB_CALLBACK *QUERY_CREDENTIALS_ATTRIBUTES_FN_A)(PSecHandle phCredential, uint32_t ulAttribute, void * pBuffer, int32_t * OutResult);

typedef void (SB_CALLBACK *SET_CONTEXT_ATTRIBUTES_FN_W)(PSecHandle phContext, uint32_t ulAttribute, void * pBuffer, uint32_t cbBuffer, int32_t * OutResult);

typedef void (SB_CALLBACK *SET_CONTEXT_ATTRIBUTES_FN_A)(PSecHandle phContext, uint32_t ulAttribute, void * pBuffer, uint32_t cbBuffer, int32_t * OutResult);

typedef void (SB_CALLBACK *SET_CREDENTIALS_ATTRIBUTES_FN_W)(PSecHandle phCredential, uint32_t ulAttribute, void * pBuffer, uint32_t cbBuffer, int32_t * OutResult);

typedef void (SB_CALLBACK *SET_CREDENTIALS_ATTRIBUTES_FN_A)(PSecHandle phCredential, uint32_t ulAttribute, void * pBuffer, uint32_t cbBuffer, int32_t * OutResult);

#ifndef WINCE
typedef void (SB_CALLBACK *SBSSPI_FREE_CONTEXT_BUFFER_FN)(void * pvContextBuffer, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *FREE_CONTEXT_BUFFER_FN)(void * pvContextBuffer, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *MAKE_SIGNATURE_FN)(PSecHandle phContext, uint32_t fQOP, SBSSPI_PSecBufferDesc pMessage, uint32_t MessageSeqNo, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *MAKE_SIGNATURE_FN)(PSecHandle phContext, uint32_t fQOP, PSecBufferDesc pMessage, uint32_t MessageSeqNo, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *VERIFY_SIGNATURE_FN)(PSecHandle phContext, SBSSPI_PSecBufferDesc pMessage, uint32_t MessageSeqNo, uint32_t * pfQOP, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *VERIFY_SIGNATURE_FN)(PSecHandle phContext, PSecBufferDesc pMessage, uint32_t MessageSeqNo, uint32_t * pfQOP, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *ENCRYPT_MESSAGE_FN)(PSecHandle phContext, uint32_t fQOP, SBSSPI_PSecBufferDesc pMessage, uint32_t MessageSeqNo, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *ENCRYPT_MESSAGE_FN)(PSecHandle phContext, uint32_t fQOP, PSecBufferDesc pMessage, uint32_t MessageSeqNo, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *DECRYPT_MESSAGE_FN)(PSecHandle phContext, SBSSPI_PSecBufferDesc pMessage, uint32_t MessageSeqNo, uint32_t * pfQOP, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *DECRYPT_MESSAGE_FN)(PSecHandle phContext, PSecBufferDesc pMessage, uint32_t MessageSeqNo, uint32_t * pfQOP, int32_t * OutResult);
#endif

typedef void (SB_CALLBACK *ENUMERATE_SECURITY_PACKAGES_FN_W)(uint32_t * pcPackages, PSecPkgInfoW (* ppPackageInfo), int32_t * OutResult);

typedef void (SB_CALLBACK *ENUMERATE_SECURITY_PACKAGES_FN_A)(uint32_t * pcPackages, PSecPkgInfoA (* ppPackageInfo), int32_t * OutResult);

typedef void (SB_CALLBACK *QUERY_SECURITY_PACKAGE_INFO_FN_W)(sb_char16_t * pszPackageName, PSecPkgInfoW (* ppPackageInfo), int32_t * OutResult);

typedef void (SB_CALLBACK *QUERY_SECURITY_PACKAGE_INFO_FN_A)(char * pszPackageName, PSecPkgInfoA (* ppPackageInfo), int32_t * OutResult);

typedef uint8_t SecDelegationTypeRaw;

typedef enum
{
	SB_SecFull = 0,
	SB_SecService = 1,
	SB_SecTree = 2,
	SB_SecDirectory = 3,
	SB_SecObject = 4
} SecDelegationType;

typedef SecDelegationTypeRaw * PSecDelegationType;

#ifndef WINCE
typedef void (SB_CALLBACK *DELEGATE_SECURITY_CONTEXT_FN)(PSecHandle phContext, char * pszTarget, SecDelegationTypeRaw DelegationType, PTimeStamp pExpiry, SBSSPI_PSecBuffer pPackageParameters, SBSSPI_PSecBufferDesc pOutput, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *DELEGATE_SECURITY_CONTEXT_FN)(PSecHandle phContext, char * pszTarget, SecDelegationTypeRaw DelegationType, PTimeStamp pExpiry, PSecBuffer pPackageParameters, PSecBufferDesc pOutput, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *EXPORT_SECURITY_CONTEXT_FN)(PSecHandle phContext, uint32_t fFlags, SBSSPI_PSecBuffer pPackedContext, void * (* pToken), int32_t * OutResult);
#else
typedef void (SB_CALLBACK *EXPORT_SECURITY_CONTEXT_FN)(PSecHandle phContext, uint32_t fFlags, PSecBuffer pPackedContext, void * (* pToken), int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *IMPORT_SECURITY_CONTEXT_FN_W)(sb_char16_t * pszPackage, SBSSPI_PSecBuffer pPackedContext, void * Token, PSecHandle phContext, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *IMPORT_SECURITY_CONTEXT_FN_W)(sb_char16_t * pszPackage, PSecBuffer pPackedContext, void * Token, PSecHandle phContext, int32_t * OutResult);
#endif

#ifndef WINCE
typedef void (SB_CALLBACK *IMPORT_SECURITY_CONTEXT_FN_A)(char * pszPackage, SBSSPI_PSecBuffer pPackedContext, void * Token, PSecHandle phContext, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *IMPORT_SECURITY_CONTEXT_FN_A)(char * pszPackage, PSecBuffer pPackedContext, void * Token, PSecHandle phContext, int32_t * OutResult);
#endif

#pragma pack(1)
typedef struct 
{
	uint32_t dwVersion;
	void * EnumerateSecurityPackagesW;
	void * QueryCredentialsAttributesW;
	void * AcquireCredentialsHandleW;
	void * FreeCredentialsHandle;
	void * Reserved2;
	void * InitializeSecurityContextW;
	void * AcceptSecurityContext;
	void * CompleteAuthToken;
	void * DeleteSecurityContext;
	void * ApplyControlToken;
	void * QueryContextAttributesW;
	void * ImpersonateSecurityContext;
	void * RevertSecurityContext;
	void * MakeSignature;
	void * VerifySignature;
	void * FreeContextBuffer;
	void * QuerySecurityPackageInfoW;
	void * Reserved3;
	void * Reserved4;
	void * ExportSecurityContext;
	void * ImportSecurityContextW;
	void * AddCredentialsW;
	void * Reserved8;
	void * QuerySecurityContextToken;
	void * EncryptMessage;
	void * DecryptMessage;
	void * SetContextAttributesW;
	void * SetCredentialsAttributesW;
} SecurityFunctionTableW, * PSecurityFunctionTableW;

#pragma pack(1)
typedef struct 
{
	uint32_t dwVersion;
	void * EnumerateSecurityPackagesA;
	void * QueryCredentialsAttributesA;
	void * AcquireCredentialsHandleA;
	void * FreeCredentialsHandle;
	void * Reserved2;
	void * InitializeSecurityContextA;
	void * AcceptSecurityContext;
	void * CompleteAuthToken;
	void * DeleteSecurityContext;
	void * ApplyControlToken;
	void * QueryContextAttributesA;
	void * ImpersonateSecurityContext;
	void * RevertSecurityContext;
	void * MakeSignature;
	void * VerifySignature;
	void * FreeContextBuffer;
	void * QuerySecurityPackageInfoA;
	void * Reserved3;
	void * Reserved4;
	void * ExportSecurityContext;
	void * ImportSecurityContextA;
	void * AddCredentialsA;
	void * Reserved8;
	void * QuerySecurityContextToken;
	void * EncryptMessage;
	void * DecryptMessage;
	void * SetContextAttributesA;
	void * SetCredentialsAttributesA;
} SecurityFunctionTableA, * PSecurityFunctionTableA;

typedef void (SB_CALLBACK *INIT_SECURITY_INTERFACE_A)(PSecurityFunctionTableA (* OutResult));

typedef void (SB_CALLBACK *INIT_SECURITY_INTERFACE_W)(PSecurityFunctionTableW (* OutResult));

#pragma pack(4)
typedef struct 
{
	sb_char16_t * User;
	uint32_t UserLength;
	sb_char16_t * Domain;
	uint32_t DomainLength;
	sb_char16_t * Password;
	uint32_t PasswordLength;
	uint32_t Flags;
} SBSSPI_SEC_WINNT_AUTH_IDENTITY_W, * SBSSPI_PSEC_WINNT_AUTH_IDENTITY_W;

#pragma pack(4)
typedef struct 
{
	char * User;
	uint32_t UserLength;
	char * Domain;
	uint32_t DomainLength;
	char * Password;
	uint32_t PasswordLength;
	uint32_t Flags;
} SBSSPI_SEC_WINNT_AUTH_IDENTITY_A, * SBSSPI_PSEC_WINNT_AUTH_IDENTITY_A;

#pragma pack(4)
typedef struct 
{
	uint32_t Version;
	uint32_t Length;
	uint16_t * User;
	uint32_t UserLength;
	uint16_t * Domain;
	uint32_t DomainLength;
	uint16_t * Password;
	uint32_t PasswordLength;
	uint32_t Flags;
	uint16_t * PackageList;
	uint32_t PackageListLength;
} SEC_WINNT_AUTH_IDENTITY_EXW, * PSEC_WINNT_AUTH_IDENTITY_EXW;

#pragma pack(4)
typedef struct 
{
	uint32_t Version;
	uint32_t Length;
	uint8_t * User;
	uint32_t UserLength;
	uint8_t * Domain;
	uint32_t DomainLength;
	uint8_t * Password;
	uint32_t PasswordLength;
	uint32_t Flags;
	uint8_t * PackageList;
	uint32_t PackageListLength;
} SEC_WINNT_AUTH_IDENTITY_EXA, * PSEC_WINNT_AUTH_IDENTITY_EXA;

typedef void * (* SBSSPI_PPVOID);

#ifndef WINCE
typedef PSecHandle SBSSPI_PCredHandle;
#else
typedef PSecHandle PCredHandle;
#endif

#ifndef WINCE
typedef PSecHandle SBSSPI_PCtxtHandle;
#else
typedef PSecHandle PCtxtHandle;
#endif

typedef PSecPkgInfoW (* PPSecPkgInfoW);

typedef PSecPkgInfoA (* PPSecPkgInfoA);

#ifdef __cplusplus
};	/* extern "C" */
#endif
#else
#ifdef __cplusplus
};	/* extern "C" */
#endif
#endif

#ifdef SB_WINDOWS
#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_SSPI

bool SEC_SUCCESS(int32_t Status);

void SecInvalidateHandleInt(SecHandle &x);

bool SecIsValidHandleInt(const SecHandle &x);

void FreeAuthLibrary();

#endif /* SB_USE_GLOBAL_PROCS_SSPI */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SSPI
SB_IMPORT uint32_t SB_APIENTRY SBSSPI_SEC_SUCCESS(int32_t Status, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSPI_SecInvalidateHandleInt(SecHandle * x);
SB_IMPORT uint32_t SB_APIENTRY SBSSPI_SecIsValidHandleInt(const SecHandle * x, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSPI_Initialize(void);
SB_IMPORT uint32_t SB_APIENTRY SBSSPI_FreeAuthLibrary(void);
#endif /* SB_USE_GLOBAL_PROCS_SSPI */

#ifdef __cplusplus
};	/* extern "C" */
#endif
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSPI */
