#ifndef __INC_SBWINCRYPT
#define __INC_SBWINCRYPT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#ifdef SB_WINDOWS
#include "sbtypes.h"
#include "sbutils.h"
#include "sbrandom.h"
#include "sbconstants.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef SB_WINDOWS
#define SB_CERT_STORE_ADD_NEW 	1
#define SB_CERT_STORE_ADD_REPLACE_EXISTING 	3
#define SB_CERT_STORE_ADD_ALWAYS 	4
#define SB_CERT_STORE_READONLY_FLAG 	32768
#define SB_CRYPT_ASN_ENCODING 	1
#define SB_CRYPT_NDR_ENCODING 	2
#define SB_CRYPT_E_UNKNOWN_ALGO 	2148077570
#define SB_CRYPT_E_EXISTS 	2148081669
#define SB_X509_ASN_ENCODING 	1
#define SB_X509_NDR_ENCODING 	2
#define SB_PKCS_7_ASN_ENCODING 	65536
#define SB_PKCS_7_NDR_ENCODING 	131072
#define SB_CERT_INFO_VERSION_FLAG 	1
#define SB_CERT_INFO_SERIAL_NUMBER_FLAG 	2
#define SB_CERT_INFO_SIGNATURE_ALGORITHM_FLAG 	3
#define SB_CERT_INFO_ISSUER_FLAG 	4
#define SB_CERT_INFO_NOT_BEFORE_FLAG 	5
#define SB_CERT_INFO_NOT_AFTER_FLAG 	6
#define SB_CERT_INFO_SUBJECT_FLAG 	7
#define SB_CERT_INFO_SUBJECT_PUBLIC_KEY_INFO_FLAG 	8
#define SB_CERT_INFO_ISSUER_UNIQUE_ID_FLAG 	9
#define SB_CERT_INFO_SUBJECT_UNIQUE_ID_FLAG 	10
#define SB_CERT_INFO_EXTENSION_FLAG 	11
#define SB_CERT_COMPARE_SHIFT 	16
#define SB_CERT_COMPARE_ANY 	0
#define SB_CERT_COMPARE_SHA1_HASH 	1
#define SB_CERT_COMPARE_NAME 	2
#define SB_CERT_COMPARE_ATTR 	3
#define SB_CERT_COMPARE_MD5_HASH 	4
#define SB_CERT_COMPARE_PROPERTY 	5
#define SB_CERT_COMPARE_PUBLIC_KEY 	6
#define SB_CERT_COMPARE_HASH 	1
#define SB_CERT_COMPARE_NAME_STR_A 	7
#define SB_CERT_COMPARE_NAME_STR_W 	8
#define SB_CERT_COMPARE_KEY_SPEC 	9
#define SB_CERT_COMPARE_ENHKEY_USAGE 	10
#define SB_CERT_COMPARE_CTL_USAGE 	10
#define SB_CERT_FIND_ANY 	0
#define SB_CERT_FIND_SHA1_HASH 	65536
#define SB_CERT_FIND_MD5_HASH 	262144
#define SB_CERT_FIND_HASH 	65536
#define SB_CERT_FIND_PROPERTY 	327680
#define SB_CERT_FIND_PUBLIC_KEY 	393216
#define SB_CERT_FIND_SUBJECT_NAME 	131079
#define SB_CERT_FIND_SUBJECT_ATTR 	196615
#define SB_CERT_FIND_ISSUER_NAME 	131076
#define SB_CERT_FIND_ISSUER_ATTR 	196612
#define SB_CERT_FIND_SUBJECT_STR_A 	458759
#define SB_CERT_FIND_SUBJECT_STR_W 	524295
#define SB_CERT_FIND_SUBJECT_STR 	524295
#define SB_CERT_FIND_ISSUER_STR_A 	458756
#define SB_CERT_FIND_ISSUER_STR_W 	524292
#define SB_CERT_FIND_ISSUER_STR 	524292
#define SB_CERT_FIND_KEY_SPEC 	589824
#define SB_CERT_FIND_ENHKEY_USAGE 	655360
#define SB_CERT_FIND_CTL_USAGE 	655360
#define SB_CERT_SYSTEM_STORE_LOCATION_MASK 	16711680
#define SB_CERT_SYSTEM_STORE_LOCATION_SHIFT 	16
#define SB_CERT_SYSTEM_STORE_CURRENT_USER_ID 	1
#define SB_CERT_SYSTEM_STORE_LOCAL_MACHINE_ID 	2
#define SB_CERT_SYSTEM_STORE_CURRENT_SERVICE_ID 	4
#define SB_CERT_SYSTEM_STORE_SERVICES_ID 	5
#define SB_CERT_SYSTEM_STORE_USERS_ID 	6
#define SB_CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID 	7
#define SB_CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID 	8
#define SB_CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID 	9
#define SB_CERT_SYSTEM_STORE_CURRENT_USER 	65536
#define SB_CERT_SYSTEM_STORE_LOCAL_MACHINE 	131072
#define SB_CERT_SYSTEM_STORE_CURRENT_SERVICE 	262144
#define SB_CERT_SYSTEM_STORE_SERVICES 	327680
#define SB_CERT_SYSTEM_STORE_USERS 	393216
#define SB_CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY 	458752
#define SB_CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE 	589824
#define SB_CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY 	524288
#define SB_CERT_STORE_OPEN_EXISTING_FLAG 	16384
#define SB_CERT_STORE_CREATE_NEW_FLAG 	8192
#define SB_CERT_STORE_DELETE_FLAG 	16
#define SB_CRYPT_OID_OPEN_STORE_PROV_FUNC 	"CertDllOpenStoreProv"
#define SB_CERT_STORE_PROV_PHYSICAL 	14
#define SB_CERT_KEY_PROV_INFO_PROP_ID 	2
#define SB_CERT_KEY_CONTEXT_PROP_ID 	5
#define SB_CERT_KEY_SPEC_PROP_ID 	6
#define SB_CERT_FRIENDLY_NAME_PROP_ID 	11
#define SB_CERT_NCRYPT_KEY_HANDLE_TRANSFER_PROP_ID 	99
#define SB_AT_KEYEXCHANGE 	1
#define SB_AT_SIGNATURE 	2
#define SB_PUBLICKEYBLOB 	6
#define SB_PRIVATEKEYBLOB 	7
#define SB_PLAINTEXTKEYBLOB 	8
#define SB_CRYPT_SILENT 	64
#define SB_CRYPT_MESSAGE_SILENT_KEYSET_FLAG 	64
#define SB_szOID_RSA_MD5 	"1.2.840.113549.2.5"
#define SB_CRYPT_MODE_CBC 	1
#define SB_CRYPT_MODE_ECB 	2
#define SB_CRYPT_MODE_OFB 	3
#define SB_CRYPT_MODE_CFB 	4
#define SB_CRYPT_MODE_CTS 	5
#define SB_ALG_CLASS_HASH 	32768
#define SB_ALG_CLASS_KEY_EXCHANGE 	40960
#define SB_ALG_CLASS_SIGNATURE 	8192
#define SB_ALG_CLASS_MSG_ENCRYPT 	16384
#define SB_ALG_TYPE_ANY 	0
#define SB_ALG_TYPE_DH 	2560
#define SB_ALG_TYPE_DSS 	512
#define SB_ALG_TYPE_RSA 	1024
#define SB_ALG_TYPE_SECURECHANNEL 	3072
#define SB_ALG_TYPE_GR3410 	3584
#define SB_ALG_SID_SSL3SHAMD5 	8
#define SB_ALG_SID_SHA1 	4
#define SB_ALG_SID_MD2 	1
#define SB_ALG_SID_MD4 	2
#define SB_ALG_SID_MD5 	3
#define SB_ALG_SID_MAC 	5
#define SB_CALG_SSL3_SHAMD5 	32776
#define SB_CALG_SHA1 	32772
#define SB_CALG_MAC 	32773
#define SB_CALG_MD2 	32769
#define SB_CALG_MD4 	32770
#define SB_CALG_MD5 	32771
#define SB_ALG_SID_AES 	17
#define SB_ALG_SID_AES_128 	14
#define SB_ALG_SID_AES_192 	15
#define SB_ALG_SID_AES_256 	16
#define SB_ALG_SID_SHA_256 	12
#define SB_ALG_SID_SHA_384 	13
#define SB_ALG_SID_SHA_512 	14
#define SB_ALG_SID_DH_EPHEM 	2
#define SB_ALG_SID_DSS_ANY 	0
#define SB_ALG_SID_RSA_ANY 	0
#define SB_ALG_SID_SHA 	4
#define SB_ALG_SID_ANY 	0
#define SB_ALG_SID_3DES_112 	9
#define SB_ALG_SID_DESX 	4
#define SB_ALG_SID_SEAL 	2
#define SB_ALG_SID_DH_SANDF 	1
#define SB_ALG_SID_AGREED_KEY_ANY 	3
#define SB_ALG_SID_KEA 	4
#define SB_ALG_SID_SKIPJACK 	10
#define SB_ALG_SID_TEK 	11
#define SB_ALG_SID_CYLINK_MEK 	12
#define SB_ALG_SID_SSL3_MASTER 	1
#define SB_ALG_SID_SCHANNEL_MASTER_HASH 	2
#define SB_ALG_SID_SCHANNEL_MAC_KEY 	3
#define SB_ALG_SID_SCHANNEL_ENC_KEY 	7
#define SB_ALG_SID_PCT1_MASTER 	4
#define SB_ALG_SID_SSL2_MASTER 	5
#define SB_ALG_SID_TLS1_MASTER 	6
#define SB_ALG_SID_RC5 	13
#define SB_ALG_SID_HMAC 	9
#define SB_ALG_SID_TLS1PRF 	10
#define SB_ALG_SID_HASH_REPLACE_OWF 	11
#define SB_ALG_SID_GR3411 	30
#define SB_ALG_SID_GR3410 	30
#define SB_ALG_SID_GR3410EL 	35
#define SB_ALG_SID_G28147 	30
#define SB_ALG_SID_PRODIVERS 	38
#define SB_ALG_SID_PRO_EXP 	31
#define SB_CALG_3DES 	26115
#define SB_CALG_AES 	26129
#define SB_CALG_AES_128 	26126
#define SB_CALG_AES_192 	26127
#define SB_CALG_AES_256 	26128
#define SB_CALG_SHA_256 	32780
#define SB_CALG_SHA_384 	32781
#define SB_CALG_SHA_512 	32782
#define SB_CALG_DH_EPHEM 	43522
#define SB_CALG_DSS_SIGN 	8704
#define SB_CALG_RSA_KEYX 	41984
#define SB_CALG_RSA_SIGN 	9216
#define SB_CALG_SHA 	32772
#define SB_CALG_NO_SIGN 	8192
#define SB_CALG_3DES_112 	26121
#define SB_CALG_DESX 	26116
#define SB_CALG_SEAL 	26626
#define SB_CALG_DH_SF 	43521
#define SB_CALG_AGREEDKEY_ANY 	43523
#define SB_CALG_KEA_KEYX 	43524
#define SB_CALG_HUGHES_MD5 	40963
#define SB_CALG_SKIPJACK 	26122
#define SB_CALG_TEK 	26123
#define SB_CALG_CYLINK_MEK 	26124
#define SB_CALG_SSL3_MASTER 	19457
#define SB_CALG_SCHANNEL_MASTER_HASH 	19458
#define SB_CALG_SCHANNEL_MAC_KEY 	19459
#define SB_CALG_SCHANNEL_ENC_KEY 	19463
#define SB_CALG_PCT1_MASTER 	19460
#define SB_CALG_SSL2_MASTER 	19461
#define SB_CALG_TLS1_MASTER 	19462
#define SB_CALG_RC5 	26125
#define SB_CALG_HMAC 	32777
#define SB_CALG_TLS1PRF 	32778
#define SB_CALG_HASH_REPLACE_OWF 	32779
#define SB_CALG_ECDH 	43525
#define SB_CALG_ECDSA 	8707
#define SB_CALG_GR3411 	32798
#define SB_CALG_GR3410 	11806
#define SB_CALG_GR3410EL 	11811
#define SB_CALG_G28147 	26142
#define SB_CALG_PRO_DIVERS 	26150
#define SB_CALG_PRO_EXPORT 	26143
#define SB_HP_HASHSIZE 	4
#define SB_HP_HASHVAL 	2
#define SB_HP_HMAC_INFO 	5
#define SB_KP_KEYLEN 	9
#define SB_KP_ALGID 	7
#define SB_KP_BLOCKLEN 	8
#define SB_KP_PERMISSIONS 	6
#define SB_KP_CERTIFICATE 	26
#define SB_CRYPT_E_UNEXPECTED_MSG_TYPE 	2148081674
#define SB__NTE_BAD_ALGID 	2148073480
#define SB_CRYPT_E_NO_DECRYPT_CERT 	2148081676
#define SB_CRYPT_IPSEC_HMAC_KEY 	256
#define SB_NTE_BAD_SIGNATURE 	2148073478
#define SB_NTE_INVALID_HANDLE 	2148073510
#define SB_PP_ENUMALGS 	1
#define SB_PP_ENUMCONTAINERS 	2
#define SB_PP_KEYEXCHANGE_PIN 	32
#define SB_PP_SIGNATURE_PIN 	33
#define SB_CRYPT_FIRST 	1
#define SB_CRYPT_NEXT 	2
#define SB_CRYPT_EXPORTABLE 	1
#define SB_CRYPT_USER_PROTECTED 	2
#define SB_CRYPT_NO_SALT 	16
#define SB_CRYPT_VERIFYCONTEXT 	4026531840
#define SB_PROV_RSA 	1
#define SB_PROV_DSS 	3
#define SB_PROV_SSL 	6
#define SB_PROV_RSA_SCHANNEL 	12
#define SB_PROV_RSA_SIG 	2
#define SB_PROV_DSS_DH 	13
#define SB_PROV_DH_SCHANNEL 	18
#define SB_PROV_RSA_AES 	24
#define SB_PROV_RSA_FULL 	1
#define SB_PROV_EC_ECDSA_SIG 	14
#define SB_PROV_EC_ECNRA_SIG 	15
#define SB_PROV_EC_ECDSA_FULL 	16
#define SB_PROV_EC_ECNRA_FULL 	17
#define SB_PROV_GOST_94_DH 	71
#define SB_PROV_GOST_2001_DH 	75
#define SB_CRYPT_NEWKEYSET 	8
#define SB_CRYPT_MACHINE_KEYSET 	32
#define SB_CRYPT_DELETEKEYSET 	16
#define SB_CERT_KEY_PROV_HANDLE_PROP_ID 	1
#define SB_CERT_STORE_PROV_MSG 	1
#define SB_CERT_STORE_PROV_MEMORY 	2
#define SB_CERT_STORE_PROV_FILE 	3
#define SB_CERT_STORE_PROV_REG 	4
#define SB_CERT_STORE_PROV_PKCS7 	5
#define SB_CERT_STORE_PROV_SERIALIZED 	6
#define SB_CERT_STORE_PROV_FILENAME_A 	7
#define SB_CERT_STORE_PROV_FILENAME_W 	8
#define SB_CERT_STORE_PROV_FILENAME 	8
#define SB_CERT_STORE_PROV_SYSTEM_A 	9
#define SB_CERT_STORE_PROV_SYSTEM_W 	10
#define SB_CERT_STORE_PROV_SYSTEM 	10
#define SB_CERT_STORE_PROV_LDAP_W 	16
#define SB_CERT_STORE_PROV_LDAP 	16
#define SB_CRYPT_MACHINE_DEFAULT 	1
#define SB_CRYPT_USER_DEFAULT 	2
#define SB_PP_NAME 	4
#define SB_MS_DEF_PROV 	"Microsoft Base Cryptographic Provider v1.0"
#define SB_MS_ENHANCED_PROV 	"Microsoft Enhanced Cryptographic Provider v1.0"
#define SB_MS_ENH_DSS_DH_PROV 	"Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"
#define SB_MS_DEF_RSA_SIG_PROV 	"Microsoft RSA Signature Cryptographic Provider"
#define SB_MS_DEF_RSA_SCHANNEL_PROV 	"Microsoft RSA SChannel Cryptographic Provider"
#define SB_MS_ENHANCED_RSA_SCHANNEL_PROV 	"Microsoft Enhanced RSA SChannel Cryptographic Provider"
#define SB_MS_DEF_DSS_PROV 	"Microsoft Base DSS Cryptographic Provider"
#define SB_MS_DEF_DSS_DH_PROV 	"Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"
#define SB_MS_ENH_RSA_AES_PROV 	"Microsoft Enhanced RSA and AES Cryptographic Provider"
#define SB_MS_ENH_RSA_AES_PROV_XP 	"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
#define SB_MS_SCARD_PROV 	"Microsoft Base Smart Card Crypto Provider"
#define SB_MS_STRONG_PROV 	"Microsoft Strong Cryptographic Provider"
#define SB_MS_DEF_DH_SCHANNEL_PROV 	"Microsoft DH SChannel Cryptographic Provider"
#define SB_CP_GR3410_94_PROV 	"Crypto-Pro GOST R 34.10-94 Cryptographic Service Provider"
#define SB_CP_GR3410_2001_PROV 	"Crypto-Pro GOST R 34.10-2001 Cryptographic Service Provider"
#define SB_BCRYPT_SHA1_ALGORITHM 	"SHA1"
#define SB_BCRYPT_SHA256_ALGORITHM 	"SHA256"
#define SB_BCRYPT_SHA384_ALGORITHM 	"SHA384"
#define SB_BCRYPT_SHA512_ALGORITHM 	"SHA512"
#define SB_BCRYPT_MD2_ALGORITHM 	"MD2"
#define SB_BCRYPT_MD5_ALGORITHM 	"MD5"
#define SB_BCRYPT_ECDSA_PUBLIC_P256_MAGIC 	827540293
#define SB_BCRYPT_ECDSA_PUBLIC_P384_MAGIC 	861094725
#define SB_BCRYPT_ECDSA_PUBLIC_P521_MAGIC 	894649157
#define SB_BCRYPT_ECCPUBLIC_BLOB 	"ECCPUBLICBLOB"
#define SB_BCRYPT_PAD_NONE 	1
#define SB_BCRYPT_PAD_PKCS1 	2
#define SB_BCRYPT_PAD_OAEP 	4
#define SB_BCRYPT_PAD_PSS 	8
#define SB_NCRYPT_PAD_PKCS1_FLAG 	2
#define SB_NCRYPT_ALLOW_DECRYPT_FLAG 	1
#define SB_NCRYPT_ALLOW_SIGNING_FLAG 	2

typedef Pointer HCRYPTOIDFUNCADDR;

typedef Pointer HCERTSTOREPROV;

#pragma pack(4)
typedef struct 
{
	uint32_t cbData;
	uint8_t * pbData;
} CRYPTOAPI_BLOB, * PCRYPTOAPI_BLOB, * PCRYPT_INTEGER_BLOB, * PCRYPT_UINT_BLOB, * PCRYPT_OBJID_BLOB, * PCERT_NAME_BLOB, * PCERT_RDN_VALUE_BLOB, * PCERT_BLOB, * PCRL_BLOB, * PDATA_BLOB, * PCRYPT_DATA_BLOB, * PCRYPT_HASH_BLOB, * PCRYPT_DIGEST_BLOB, * PCRYPT_DER_BLOB, * PCRYPT_ATTR_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_INTEGER_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_UINT_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_OBJID_BLOB;

typedef CRYPTOAPI_BLOB CERT_NAME_BLOB;

typedef CRYPTOAPI_BLOB CERT_RDN_VALUE_BLOB;

typedef CRYPTOAPI_BLOB CERT_BLOB;

typedef CRYPTOAPI_BLOB CRL_BLOB;

typedef CRYPTOAPI_BLOB DATA_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_DATA_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_HASH_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_DIGEST_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_DER_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_ATTR_BLOB;

#pragma pack(4)
typedef struct 
{
	uint32_t cbData;
	uint8_t * pbData;
	uint32_t cUnusedBits;
} CRYPT_BIT_BLOB, * PCRYPT_BIT_BLOB;

#pragma pack(4)
typedef struct 
{
	char * pszObjId;
	CRYPTOAPI_BLOB Parameters;
} CRYPT_ALGORITHM_IDENTIFIER, * PCRYPT_ALGORITHM_IDENTIFIER;

#pragma pack(4)
typedef struct 
{
	CRYPT_ALGORITHM_IDENTIFIER Algorithm;
	CRYPT_BIT_BLOB PublicKey;
} CERT_PUBLIC_KEY_INFO, * PCERT_PUBLIC_KEY_INFO;

#pragma pack(4)
typedef struct 
{
	char * pszObjId;
	int32_t fCritical;
	CRYPTOAPI_BLOB Value;
} CERT_EXTENSION, * PCERT_EXTENSION;

#pragma pack(4)
typedef struct 
{
	uint32_t dwVersion;
	CRYPTOAPI_BLOB SerialNumber;
	CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
	CRYPTOAPI_BLOB Issuer;
	windows_FILETIME NotBefore;
	windows_FILETIME NotAfter;
	CRYPTOAPI_BLOB Subject;
	CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
	CRYPT_BIT_BLOB IssuerUniqueId;
	CRYPT_BIT_BLOB SubjectUniqueId;
	uint32_t cExtension;
	PCERT_EXTENSION rgExtension;
} CERT_INFO, * PCERT_INFO;

typedef Pointer SBWinCrypt_PVOID;

typedef PChar LPAWSTR;

typedef Pointer HCERTSTORE;

#pragma pack(4)
typedef struct 
{
	uint32_t dwCertEncodingType;
	uint8_t * pbCertEncoded;
	uint32_t cbCertEncoded;
	PCERT_INFO pCertInfo;
	void * hCertStore;
} CERT_CONTEXT, * PCERT_CONTEXT, * PCCERT_CONTEXT;

#pragma pack(4)
typedef struct 
{
	uint32_t dwSize;
	uint32_t hwndParent;
	uint32_t dwFlags;
	sb_char16_t * szTitle;
	PCCERT_CONTEXT pCertContext;
	char * rgszPurposes;
	uint32_t cPurposes;
	void * Union;
	int32_t fpCryptProviderDataTrustedUsage;
	uint32_t idxSigner;
	uint32_t idxCert;
	int32_t fCounterSigner;
	uint32_t idxCounterSigner;
	uint32_t cStores;
	void * (* rghStores);
	uint32_t cPropSheetPages;
	void * rgPropSheetPages;
	uint32_t nStartPage;
} CRYPTUI_VIEWCERTIFICATE_STRUCT, * PCRYPTUI_VIEWCERTIFICATE_STRUCT, * PCCRYPTUI_VIEWCERTIFICATE_STRUCT;

#pragma pack(4)
typedef struct 
{
	uint32_t dwSize;
	uint32_t hwndParent;
	uint32_t dwFlags;
	sb_char16_t * szTitle;
	uint32_t dwDontUseColumn;
	sb_char16_t * szDisplayString;
	void * pFilterCallback;
	void * pDisplayCallback;
	void * pvCallbackData;
	uint32_t cDisplayStores;
	void * (* rghDisplayStores);
	uint32_t cStores;
	void * (* rghStores);
	uint32_t cPropSheetPages;
	void * rgPropSheetPages;
	void * hSelectedCertStore;
} CRYPTUI_SELECTCERTIFICATE_STRUCT, * PCRYPTUI_SELECTCERTIFICATE_STRUCT, * PCCRYPTUI_SELECTCERTIFICATE_STRUCT;

#ifndef CPU64
typedef uint32_t * PHCRYPTPROV;
#else
typedef int64_t * PHCRYPTPROV;
#endif

#ifndef CPU64
typedef uint32_t * PHCRYPTKEY;
#else
typedef int64_t * PHCRYPTKEY;
#endif

#ifndef CPU64
typedef uint32_t * PHCRYPTHASH;
#else
typedef int64_t * PHCRYPTHASH;
#endif

#pragma pack(4)
typedef struct 
{
	uint32_t cbSize;
} _CERT_SYSTEM_STORE_INFO, * PCERT_SYSTEM_STORE_INFO;

typedef _CERT_SYSTEM_STORE_INFO CERT_SYSTEM_STORE_INFO;

typedef _CERT_SYSTEM_STORE_INFO TCertSystemStoreInfo;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * pwszContainerName;
	sb_char16_t * pwszProvName;
	uint32_t dwProvType;
	uint32_t dwFlags;
	uint32_t cProvParam;
	void * rgProvParam;
	uint32_t dwKeySpec;
} _CRYPT_KEY_PROV_INFO, * PCRYPT_KEY_PROV_INFO;

typedef _CRYPT_KEY_PROV_INFO CRYPT_KEY_PROV_INFO;

#pragma pack(4)
typedef struct 
{
	char * pszObjId;
	uint32_t cValue;
	PCRYPT_ATTR_BLOB rgValue;
} _CRYPT_ATTRIBUTE, * PCRYPT_ATTRIBUTE;

typedef _CRYPT_ATTRIBUTE CRYPT_ATTRIBUTE;

#pragma pack(4)
typedef struct 
{
	uint32_t cbSize;
	uint32_t dwMsgEncodingType;
	PCCERT_CONTEXT pSigningCert;
	CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
	void * pvHashAuxInfo;
	uint32_t cMsgCert;
	PCCERT_CONTEXT (* rgpMsgCert);
	uint32_t cMsgCrl;
	PCCERT_CONTEXT (* rgpMsgCrl);
	uint32_t cAuthAttr;
	PCRYPT_ATTRIBUTE rgAuthAttr;
	uint32_t cUnauthAttr;
	PCRYPT_ATTRIBUTE rgUnauthAttr;
	uint32_t dwFlags;
	uint32_t dwInnerContentType;
	CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
	void * pvHashEncryptionAuxInfo;
} _CRYPT_SIGN_MESSAGE_PARA, * PCRYPT_SIGN_MESSAGE_PARA;

typedef _CRYPT_SIGN_MESSAGE_PARA CRYPT_SIGN_MESSAGE_PARA;

#pragma pack(4)
typedef struct 
{
	uint32_t cbSize;
	uint32_t dwMsgAndCertEncodingType;
	uint32_t cCertStore;
	void * (* rghCertStore);
} _CRYPT_DECRYPT_MESSAGE_PARA, * PCRYPT_DECRYPT_MESSAGE_PARA;

typedef _CRYPT_DECRYPT_MESSAGE_PARA CRYPT_DECRYPT_MESSAGE_PARA;

#pragma pack(4)
typedef struct 
{
	uint32_t aiAlgId;
	uint32_t dwBitLen;
	uint32_t dwNameLen;
	char szName[20];
} _PROV_ENUMALGS, * PPROV_ENUMALGS;

typedef _PROV_ENUMALGS PROV_ENUMALGS;

#pragma pack(4)
typedef struct 
{
	char * pszOID;
	void * pvFuncAddr;
} _CRYPT_OID_FUNC_ENTRY, * PCRYPT_OID_FUNC_ENTRY;

typedef _CRYPT_OID_FUNC_ENTRY CRYPT_OID_FUNC_ENTRY;

#pragma pack(4)
typedef struct 
{
	uint32_t cbSize;
	uint32_t cStoreProvFunc;
	void * rgpvStoreProvFunc;
	void * hStoreProv;
	uint32_t dwStoreProvFlags;
	void * hStoreProvFuncAddr2;
} _CERT_STORE_PROV_INFO, * PCERT_STORE_PROV_INFO;

typedef _CERT_STORE_PROV_INFO CERT_STORE_PROV_INFO;

typedef void (SB_CALLBACK *PFN_CERT_ENUM_SYSTEM_STORE)(void * pvSystemStore, uint32_t dwFlags, PCERT_SYSTEM_STORE_INFO pStoreInfo, void * pvReserved, void * pvArg, int32_t * OutResult);

typedef PFN_CERT_ENUM_SYSTEM_STORE PfnCertEnumSystemStore;

typedef void (SB_CALLBACK *TCertEnumSystemStore)(uint32_t dwFlags, void * pvSystemStoreLocationPara, void * pvArg, PFN_CERT_ENUM_SYSTEM_STORE pfnEnum, int32_t * OutResult);

typedef void (SB_CALLBACK *PFN_CERT_ENUM_PHYSICAL_STORE)(void * pvSystemStore, uint32_t dwFlags, sb_char16_t * pwszStoreName, PCERT_SYSTEM_STORE_INFO pStoreInfo, void * pvReserver, void * pvArg, int32_t * OutResult);

typedef void (SB_CALLBACK *TCertEnumPhysicalStore)(void * pvSystemStore, uint32_t dwFlags, void * pvArg, PFN_CERT_ENUM_PHYSICAL_STORE pfnEnum, int32_t * OutResult);

typedef void (SB_CALLBACK *TCryptSignMessage)(PCRYPT_SIGN_MESSAGE_PARA pSignPara, int32_t fDetachedSignature, uint32_t cToBeSigned, const uint8_t * (* rgpbToBeSigned), uint32_t * rgcbToBeSigned, uint8_t * pbSignedBlob, uint32_t * pcbSignedBlob, int32_t * OutResult);

typedef void (SB_CALLBACK *TCryptFindLocalizedName)(const sb_char16_t * pwszCryptName, sb_char16_t * (* OutResult));

#ifndef CPU64
typedef void (SB_CALLBACK *TCryptAcquireCertificatePrivateKey)(PCCERT_CONTEXT pCert, uint32_t dwFlags, void * pvReserved, uint32_t * phCryptProv, uint32_t * pdwKeySpec, int32_t * pfCallerFreeProv, int32_t * OutResult);
#else
typedef void (SB_CALLBACK *TCryptAcquireCertificatePrivateKey)(PCCERT_CONTEXT pCert, uint32_t dwFlags, void * pvReserved, int64_t * phCryptProv, uint32_t * pdwKeySpec, int32_t * pfCallerFreeProv, int32_t * OutResult);
#endif

typedef Pointer PLPSTR;

typedef Pointer PPCERT_INFO;

typedef Pointer SBWinCrypt_PPVOID;

typedef Pointer PPCCTL_CONTEXT;

typedef Pointer PPCCRL_CONTEXT;

typedef Pointer HCRYPTMSG;

#pragma pack(4)
typedef struct 
{
	uint32_t cUsageIdentifier;
	void * rgpszUsageIdentifier;
} CTL_USAGE, * PCTL_USAGE;

#pragma pack(4)
typedef struct 
{
	CRYPTOAPI_BLOB SubjectIdentifier;
	uint32_t cAttribute;
	PCRYPT_ATTRIBUTE rgAttribute;
} CTL_ENTRY, * PCTL_ENTRY;

#pragma pack(4)
typedef struct 
{
	CRYPTOAPI_BLOB SerialNumber;
	windows_FILETIME RevocationDate;
	uint32_t cExtension;
	PCERT_EXTENSION rgExtension;
} CRL_ENTRY, * PCRL_ENTRY;

#pragma pack(4)
typedef struct 
{
	uint32_t dwVersion;
	CTL_USAGE SubjectUsage;
	CRYPTOAPI_BLOB ListIdentifier;
	CRYPTOAPI_BLOB SequenceNumber;
	windows_FILETIME ThisUpdate;
	windows_FILETIME NextUpdate;
	CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
	uint32_t cCTLEntry;
	PCTL_ENTRY rgCTLEntry;
	uint32_t cExtension;
	PCERT_EXTENSION rgExtension;
} CTL_INFO, * PCTL_INFO;

#pragma pack(4)
typedef struct 
{
	uint32_t dwVersion;
	CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
	CRYPTOAPI_BLOB Issuer;
	windows_FILETIME ThisUpdate;
	windows_FILETIME NextUpdate;
	uint32_t cCRLEntry;
	PCRL_ENTRY rgCRLEntry;
	uint32_t cExtension;
	PCERT_EXTENSION rgExtension;
} CRL_INFO, * PCRL_INFO;

#pragma pack(4)
typedef struct 
{
	uint32_t dwCertEncodingType;
	uint8_t * pbCrlEncoded;
	uint32_t cbCrlEncoded;
	PCRL_INFO pCrlInfo;
	void * hCertStore;
} CRL_CONTEXT, * PCRL_CONTEXT, * PCCRL_CONTEXT;

#pragma pack(4)
typedef struct 
{
	uint32_t dwMsgAndCertEncodingType;
	uint8_t * pbCtlEncoded;
	uint32_t cbCtlEncoded;
	PCTL_INFO pCtlInfo;
	void * hCertStore;
	void * hCryptMsg;
	uint8_t * pbCtlContent;
	uint32_t cbCtlContent;
} CTL_CONTEXT, * PCTL_CONTEXT, * PCCTL_CONTEXT;

#pragma pack(4)
typedef struct 
{
	uint32_t cbSize;
	uint32_t dwMsgAndCertEncodingType;
	uint32_t dwFindFlags;
	uint32_t dwFindType;
	void * pvFindPara;
} CERT_STORE_PROV_FIND_INFO, * PCERT_STORE_PROV_FIND_INFO, * PCCERT_STORE_PROV_FIND_INFO;

typedef CERT_STORE_PROV_FIND_INFO CCERT_STORE_PROV_FIND_INFO;

#pragma pack(4)
typedef struct 
{
	uint32_t Data1;
	uint16_t Data2;
	uint16_t Data3;
	uint8_t Data4[8];
} SBWinCrypt__GUID, * PGUID;

typedef SBWinCrypt__GUID SBWinCrypt_GUID;

#pragma pack(4)
typedef struct 
{
	uint32_t HashAlgid;
	uint8_t * pbInnerString;
	uint32_t cbInnerString;
	uint8_t * pbOuterString;
	uint32_t cbOuterString;
} HMAC_INFO;

typedef uint32_t * SBWinCrypt_ULONG_PTR;

typedef SBWinCrypt_ULONG_PTR NCRYPT_HANDLE;

typedef SBWinCrypt_ULONG_PTR NCRYPT_PROV_HANDLE;

typedef SBWinCrypt_ULONG_PTR NCRYPT_KEY_HANDLE;

typedef SBWinCrypt_ULONG_PTR NCRYPT_HASH_HANDLE;

typedef SBWinCrypt_ULONG_PTR NCRYPT_SECRET_HANDLE;

#pragma pack(4)
typedef struct 
{
	uint32_t cbBuffer;
	uint32_t BufferType;
	void * pvBuffer;
} NCryptBuffer, * PNCryptBuffer;

#pragma pack(4)
typedef struct 
{
	uint32_t ulVersion;
	uint32_t cBuffers;
	PNCryptBuffer pBuffers;
} NCryptBufferDesc, * PNCryptBufferDesc;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * pszName;
	uint32_t dwClass;
	uint32_t dwAlgOperations;
	uint32_t dwFlags;
} NCryptAlgorithmName, * PNCryptAlgorithmName;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * pszName;
	sb_char16_t * pszAlgid;
	uint32_t dwLegacyKeySpec;
	uint32_t dwFlags;
} NCryptKeyName, * PNCryptKeyName;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * pszName;
	sb_char16_t * pszComment;
} NCryptProviderName, * PNCryptProviderName;

#pragma pack(4)
typedef struct 
{
	sb_char16_t * pszAlgId;
} BCRYPT_PKCS1_PADDING_INFO;

typedef uint8_t * (* PPBYTE);

typedef void * (* PHCERTSTORE);

typedef PCCERT_CONTEXT (* PPCCERT_CONTEXT);

typedef PCERT_SYSTEM_STORE_INFO PCertSystemStoreInfo;

typedef uint32_t * (* PNCRYPT_HANDLE);

typedef uint32_t * (* PNCRYPT_PROV_HANDLE);

typedef uint32_t * (* PNCRYPT_KEY_HANDLE);

typedef uint32_t * (* PNCRYPT_HASH_HANDLE);

typedef uint32_t * (* PNCRYPT_SECRET_HANDLE);

typedef PNCryptAlgorithmName (* PPNCryptAlgorithmName);

typedef PNCryptKeyName (* PPNCryptKeyName);

typedef PNCryptProviderName (* PPNCryptProviderName);

typedef void * (* SBWinCrypt_PPointer);

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_WINCRYPT

#ifndef CPU64
void * CertOpenSystemStore(uint32_t hProv, char * szSubsystemProtocol);
#else
void * CertOpenSystemStore(int64_t hProv, char * szSubsystemProtocol);
#endif

PCCERT_CONTEXT CertFindCertificateInStore(void * hCertStore, uint32_t dwCertEncodingType, uint32_t dwFindFlags, uint32_t dwFindType, const void * pvFindPara, PCCERT_CONTEXT pPrevCertContext);

bool CertCloseStore(void * hCertStore, uint32_t dwFlags);

bool CertEnumSystemStore(uint32_t dwFlags, void * pvSystemStoreLocationPara, void * pvArg, PFN_CERT_ENUM_SYSTEM_STORE pfnEnum);

bool CertAddEncodedCertificateToStore(void * hCertStore, uint32_t dwCertEncodingType, const uint8_t * pbCertEncoded, uint32_t cbCertEncoded, uint32_t dwAddDisposition, PCCERT_CONTEXT &ppCertContext);

bool CertFreeCertificateContext(PCCERT_CONTEXT pCertContext);

bool CertDeleteCertificateFromStore(PCCERT_CONTEXT pCertContext);

PCCERT_CONTEXT CertEnumCertificatesInStore(void * hCertStore, PCCERT_CONTEXT pPrevCertContext);

PCCERT_CONTEXT CertDuplicateCertificateContext(PCCERT_CONTEXT pCertContext);

bool CertEnumPhysicalStore(void * pvSystemStore, uint32_t dwFlags, void * pvArg, PFN_CERT_ENUM_PHYSICAL_STORE pfnEnum);

#ifndef CPU64
void * CertOpenStore(char * lpszStoreProvider, uint32_t dwMsgAndCertEncodingType, uint32_t hCryptProv, uint32_t dwFlags, const void * pvPara);
#else
void * CertOpenStore(char * lpszStoreProvider, uint32_t dwMsgAndCertEncodingType, int64_t hCryptProv, uint32_t dwFlags, const void * pvPara);
#endif

bool CertGetCertificateContextProperty(PCCERT_CONTEXT pCertContext, uint32_t dwPropId, void * pvData, uint32_t * pcbData);

bool CertSetCertificateContextProperty(PCCERT_CONTEXT pCertContext, uint32_t dwPropId, uint32_t dwFlags, void * pvData);

#ifndef CPU64
bool CryptAcquireContext(uint32_t * hProv, char * pszContainer, char * pszProvider, uint32_t dwProvType, uint32_t dwFlags);
#else
bool CryptAcquireContext(int64_t * hProv, char * pszContainer, char * pszProvider, uint32_t dwProvType, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptContextAddRef(uint32_t hProv, uint32_t * pdwReserved, uint32_t dwFlags);
#else
bool CryptContextAddRef(int64_t hProv, uint32_t * pdwReserved, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptGetUserKey(uint32_t hProv, uint32_t dwKeySpec, uint32_t * phUserKey);
#else
bool CryptGetUserKey(int64_t hProv, uint32_t dwKeySpec, int64_t * phUserKey);
#endif

#ifndef CPU64
bool CryptDestroyKey(uint32_t hKey);
#else
bool CryptDestroyKey(int64_t hKey);
#endif

#ifndef CPU64
bool CryptReleaseContext(uint32_t hProv, uint32_t dwFlags);
#else
bool CryptReleaseContext(int64_t hProv, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptExportKey(uint32_t hKey, uint32_t hExpKey, uint32_t dwBlobType, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen);
#else
bool CryptExportKey(int64_t hKey, int64_t hExpKey, uint32_t dwBlobType, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen);
#endif

#ifndef CPU64
bool CryptImportKey(uint32_t hProv, uint8_t * pbData, uint32_t dwDataLen, uint32_t hPubKey, uint32_t dwFlags, uint32_t * phKey);
#else
bool CryptImportKey(int64_t hProv, uint8_t * pbData, uint32_t dwDataLen, int64_t hPubKey, uint32_t dwFlags, int64_t * phKey);
#endif

bool CryptSignMessage(PCRYPT_SIGN_MESSAGE_PARA pSignPara, bool fDetachedSignature, uint32_t cToBeSigned, const uint8_t * (* rgpbToBeSigned), uint32_t * rgcbToBeSigned, uint8_t * pbSignedBlob, uint32_t * pcbSignedBlob);

#ifndef CPU64
bool CryptAcquireCertificatePrivateKey(PCCERT_CONTEXT pCert, uint32_t dwFlags, void * pvReserved, uint32_t * phCryptProv, uint32_t * pdwKeySpec, int32_t * pfCallerFreeProv);
#else
bool CryptAcquireCertificatePrivateKey(PCCERT_CONTEXT pCert, uint32_t dwFlags, void * pvReserved, int64_t * phCryptProv, uint32_t * pdwKeySpec, int32_t * pfCallerFreeProv);
#endif

#ifndef CPU64
bool CryptCreateHash(uint32_t hProv, uint32_t AlgId, uint32_t hKey, uint32_t dwFlags, uint32_t * phHash);
#else
bool CryptCreateHash(int64_t hProv, uint32_t AlgId, int64_t hKey, uint32_t dwFlags, int64_t * phHash);
#endif

#ifndef CPU64
bool CryptSetHashParam(uint32_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags);
#else
bool CryptSetHashParam(int64_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptGetHashParam(uint32_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t &pdwDataLen, uint32_t dwFlags);
#else
bool CryptGetHashParam(int64_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t &pdwDataLen, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptSignHash(uint32_t hHash, uint32_t dwKeySpec, char * sDescription, uint32_t dwFlags, uint8_t * pbSignature, uint32_t * pdwSigLen);
#else
bool CryptSignHash(int64_t hHash, uint32_t dwKeySpec, char * sDescription, uint32_t dwFlags, uint8_t * pbSignature, uint32_t * pdwSigLen);
#endif

#ifndef CPU64
bool CryptDestroyHash(uint32_t hHash);
#else
bool CryptDestroyHash(int64_t hHash);
#endif

#ifndef CPU64
bool CryptHashData(uint32_t hHash, uint8_t * pbData, uint32_t dwDataLen, uint32_t dwFlags);
#else
bool CryptHashData(int64_t hHash, uint8_t * pbData, uint32_t dwDataLen, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptVerifySignature(uint32_t hHash, uint8_t * pbSignature, uint32_t dwSigLen, uint32_t hPubKey, char * sDescription, uint32_t dwFlags);
#else
bool CryptVerifySignature(int64_t hHash, uint8_t * pbSignature, uint32_t dwSigLen, int64_t hPubKey, char * sDescription, uint32_t dwFlags);
#endif

sb_char16_t * CryptFindLocalizedName(const sb_char16_t * pwszCryptName);

bool CryptDecryptMessage(PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara, uint8_t * pbEncryptedBlob, uint32_t cbEncryptedBlob, uint8_t * pbDecrypted, uint32_t * pcbDecrypted, PCCERT_CONTEXT (* ppXchgCert));

#ifndef CPU64
bool CryptDecrypt(uint32_t hKey, uint32_t hHash, bool Final, uint32_t dwFlags, uint8_t * pbData, uint32_t &pdwDataLen);
#else
bool CryptDecrypt(int64_t hKey, int64_t hHash, bool Final, uint32_t dwFlags, uint8_t * pbData, uint32_t &pdwDataLen);
#endif

#ifndef CPU64
bool CryptEncrypt(uint32_t hKey, uint32_t hHash, bool Final, uint32_t dwFlags, uint8_t * pbData, uint32_t &pdwDataLen, uint32_t dwBufLen);
#else
bool CryptEncrypt(int64_t hKey, int64_t hHash, bool Final, uint32_t dwFlags, uint8_t * pbData, uint32_t &pdwDataLen, uint32_t dwBufLen);
#endif

#ifndef CPU64
bool CryptDuplicateKey(uint32_t hKey, uint32_t * pdwReserved, uint32_t dwFlags, uint32_t &phKey);
#else
bool CryptDuplicateKey(int64_t hKey, uint32_t * pdwReserved, uint32_t dwFlags, int64_t &phKey);
#endif

PCCERT_CONTEXT CertCreateCertificateContext(uint32_t dwCertEncodingType, const uint8_t * pbCertEncoded, uint32_t cbCertEncoded);

#ifndef CPU64
bool CryptGetProvParam(uint32_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t * pwdDataLen, uint32_t dwFlags);
#else
bool CryptGetProvParam(int64_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t * pwdDataLen, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptGetKeyParam(uint32_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwFlags);
#else
bool CryptGetKeyParam(int64_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptDeriveKey(uint32_t hProv, uint32_t Algid, uint32_t hBaseData, uint32_t dwFlags, uint32_t * phKey);
#else
bool CryptDeriveKey(int64_t hProv, uint32_t Algid, int64_t hBaseData, uint32_t dwFlags, int64_t * phKey);
#endif

#ifndef CPU64
bool CryptGenKey(uint32_t hProv, uint32_t Algid, uint32_t dwFlags, uint32_t * phKey);
#else
bool CryptGenKey(int64_t hProv, uint32_t Algid, uint32_t dwFlags, int64_t * phKey);
#endif

bool CryptRegisterOIDFunction(uint32_t dwEncodingType, char * pszFuncName, char * pszOID, sb_char16_t * pwszDll, char * pszOverrideFuncName);

bool CryptUnregisterOIDFunction(uint32_t dwEncodingType, char * pszFuncName, char * pszOID);

bool CryptInstallOIDFunctionAddress(uint32_t hModule, uint32_t dwEncodingType, char * pszFuncName, uint32_t cFuncEntry, PCRYPT_OID_FUNC_ENTRY rgFuncEntry, uint32_t dwFlags);

int32_t CoCreateGuid(PGUID guid);

void GetProcedureAddress(void * &P, const std::string &ModuleName, const std::string &ProcName);

#ifndef CPU64
bool CryptSetProvParam(uint32_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags);
#else
bool CryptSetProvParam(int64_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags);
#endif

#ifndef CPU64
bool CryptSetKeyParam(uint32_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags);
#else
bool CryptSetKeyParam(int64_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags);
#endif

bool CryptUIDlgViewCertificate(PCCRYPTUI_VIEWCERTIFICATE_STRUCT pCertViewInfo, int32_t * pfPropertiesChanged);

PCCERT_CONTEXT CryptUIDlgSelectCertificate(PCCRYPTUI_SELECTCERTIFICATE_STRUCT pcsc);

bool CryptUIWizImport(uint32_t dwFlags, uint32_t hwndParent, sb_char16_t * pwszWizardTitle, void * pImportSrc, void * hDestCertStore);

uint32_t NCryptCreatePersistedKey(uint32_t * hProvider, uint32_t * (* phKey), sb_char16_t * pszAlgId, sb_char16_t * pszKeyName, uint32_t dwLegacyKeySpec, uint32_t dwFlags);

uint32_t NCryptDecrypt(uint32_t * hKey, uint8_t * pbInput, uint32_t cbInput, void * pPaddingInfo, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags);

uint32_t NCryptDeleteKey(uint32_t * hKey, uint32_t dwFlags);

uint32_t NCryptDeriveKey(uint32_t * hSharedSecret, sb_char16_t * pwszKDF, PNCryptBufferDesc pParameterList, uint8_t * pbDerivedKey, uint32_t cbDerivedKey, uint32_t * pcbResult, uint32_t dwFlags);

uint32_t NCryptEncrypt(uint32_t * hKey, uint8_t * pbInput, uint32_t cbInput, void * pPaddingInfo, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags);

uint32_t NCryptEnumAlgorithms(uint32_t * hProvider, uint32_t dwAlgOperations, uint32_t * pdwAlgCount, PNCryptAlgorithmName (* ppAlgList), uint32_t dwFlags);

uint32_t NCryptEnumKeys(uint32_t * hProvider, sb_char16_t * pszScope, PNCryptKeyName (* ppKeyName), void * (* ppEnumState), uint32_t dwFlags);

uint32_t NCryptEnumStorageProviders(uint32_t * pdwProviderCount, PNCryptProviderName (* ppProviderList), uint32_t dwFlags);

uint32_t NCryptExportKey(uint32_t * hKey, uint32_t * hExportKey, sb_char16_t * pszBlobType, PNCryptBufferDesc pParameterList, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags);

uint32_t NCryptFinalizeKey(uint32_t * hKey, uint32_t dwFlags);

uint32_t NCryptFreeBuffer(void * pvInput);

uint32_t NCryptFreeObject(uint32_t * hObject);

uint32_t NCryptGetProperty(uint32_t * hObject, sb_char16_t * pszProperty, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags);

uint32_t NCryptImportKey(uint32_t * hProvider, uint32_t * hImportKey, sb_char16_t * pszBlobType, PNCryptBufferDesc pParameterList, uint32_t * (* phKey), uint8_t * pbData, uint32_t cbData, uint32_t dwFlags);

uint32_t NCryptIsAlgSupported(uint32_t * hProvider, sb_char16_t * pszAlgId, uint32_t dwFlags);

bool NCryptIsKeyHandle(uint32_t * hKey);

uint32_t NCryptKeyDerivation(uint32_t * hProvider, uint32_t * hKey, sb_char16_t * pswzDerivedKeyAlg, uint32_t cbDerivedKeyLength, PNCryptBufferDesc pParameterList, uint32_t * (* phDerivedKey), uint32_t dwFlags);

uint32_t NCryptNotifyChangeKey(uint32_t * hProvider, uint32_t * phEvent, uint32_t dwFlags);

uint32_t NCryptOpenKey(uint32_t * hProvider, uint32_t * (* phKey), sb_char16_t * pszKeyName, uint32_t dwLegacyKeySpec, uint32_t dwFlags);

uint32_t NCryptOpenStorageProvider(uint32_t * (* phProvider), sb_char16_t * pszProviderName, uint32_t dwFlags);

uint32_t NCryptSecretAgreement(uint32_t * hPrivKey, uint32_t * hPubKey, uint32_t * (* phSecret), uint32_t dwFlags);

uint32_t NCryptSetProperty(uint32_t * hObject, sb_char16_t * pszProperty, uint8_t * pbInput, uint32_t cbInput, uint32_t dwFlags);

uint32_t NCryptSignHash(uint32_t * hKey, void * pPaddingInfo, uint8_t * pbHashValue, uint32_t cbHashValue, uint8_t * pbSignature, uint32_t cbSignature, uint32_t * pcbResult, uint32_t dwFlags);

#ifndef CPU64
uint32_t NCryptTranslateHandle(uint32_t * (* phProvider), uint32_t * (* phKey), uint32_t hLegacyProv, uint32_t hLegacyKey, uint32_t dwLegacyKeySpec, uint32_t dwFlags);
#else
uint32_t NCryptTranslateHandle(uint32_t * (* phProvider), uint32_t * (* phKey), int64_t hLegacyProv, int64_t hLegacyKey, uint32_t dwLegacyKeySpec, uint32_t dwFlags);
#endif

uint32_t NCryptVerifySignature(uint32_t * hKey, void * pPaddingInfo, uint8_t * pbHashValue, uint32_t cbHashValue, uint8_t * pbSignature, uint32_t cbSignature, uint32_t dwFlags);

#endif /* SB_USE_GLOBAL_PROCS_WINCRYPT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_WINCRYPT
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertOpenSystemStore(uint32_t hProv, char * szSubsystemProtocol, void * * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertOpenSystemStore(int64_t hProv, char * szSubsystemProtocol, void * * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertFindCertificateInStore(void * hCertStore, uint32_t dwCertEncodingType, uint32_t dwFindFlags, uint32_t dwFindType, const void * pvFindPara, PCCERT_CONTEXT pPrevCertContext, PCCERT_CONTEXT * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertCloseStore(void * hCertStore, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertEnumSystemStore(uint32_t dwFlags, void * pvSystemStoreLocationPara, void * pvArg, PFN_CERT_ENUM_SYSTEM_STORE pfnEnum, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertAddEncodedCertificateToStore(void * hCertStore, uint32_t dwCertEncodingType, const uint8_t * pbCertEncoded, uint32_t cbCertEncoded, uint32_t dwAddDisposition, PCCERT_CONTEXT * ppCertContext, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertFreeCertificateContext(PCCERT_CONTEXT pCertContext, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertDeleteCertificateFromStore(PCCERT_CONTEXT pCertContext, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertEnumCertificatesInStore(void * hCertStore, PCCERT_CONTEXT pPrevCertContext, PCCERT_CONTEXT * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertDuplicateCertificateContext(PCCERT_CONTEXT pCertContext, PCCERT_CONTEXT * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertEnumPhysicalStore(void * pvSystemStore, uint32_t dwFlags, void * pvArg, PFN_CERT_ENUM_PHYSICAL_STORE pfnEnum, int32_t * OutResult);
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertOpenStore(char * lpszStoreProvider, uint32_t dwMsgAndCertEncodingType, uint32_t hCryptProv, uint32_t dwFlags, const void * pvPara, void * * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertOpenStore(char * lpszStoreProvider, uint32_t dwMsgAndCertEncodingType, int64_t hCryptProv, uint32_t dwFlags, const void * pvPara, void * * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertGetCertificateContextProperty(PCCERT_CONTEXT pCertContext, uint32_t dwPropId, void * pvData, uint32_t * pcbData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertSetCertificateContextProperty(PCCERT_CONTEXT pCertContext, uint32_t dwPropId, uint32_t dwFlags, void * pvData, int32_t * OutResult);
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptAcquireContext(uint32_t * hProv, char * pszContainer, char * pszProvider, uint32_t dwProvType, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptContextAddRef(uint32_t hProv, uint32_t * pdwReserved, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGetUserKey(uint32_t hProv, uint32_t dwKeySpec, uint32_t * phUserKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDestroyKey(uint32_t hKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptReleaseContext(uint32_t hProv, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptExportKey(uint32_t hKey, uint32_t hExpKey, uint32_t dwBlobType, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptImportKey(uint32_t hProv, uint8_t * pbData, uint32_t dwDataLen, uint32_t hPubKey, uint32_t dwFlags, uint32_t * phKey, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptAcquireContext(int64_t * hProv, char * pszContainer, char * pszProvider, uint32_t dwProvType, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptContextAddRef(int64_t hProv, uint32_t * pdwReserved, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGetUserKey(int64_t hProv, uint32_t dwKeySpec, int64_t * phUserKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDestroyKey(int64_t hKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptReleaseContext(int64_t hProv, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptExportKey(int64_t hKey, int64_t hExpKey, uint32_t dwBlobType, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptImportKey(int64_t hProv, uint8_t * pbData, uint32_t dwDataLen, int64_t hPubKey, uint32_t dwFlags, int64_t * phKey, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSignMessage(PCRYPT_SIGN_MESSAGE_PARA pSignPara, int32_t fDetachedSignature, uint32_t cToBeSigned, const uint8_t * (* rgpbToBeSigned), uint32_t * rgcbToBeSigned, uint8_t * pbSignedBlob, uint32_t * pcbSignedBlob, int32_t * OutResult);
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptAcquireCertificatePrivateKey(PCCERT_CONTEXT pCert, uint32_t dwFlags, void * pvReserved, uint32_t * phCryptProv, uint32_t * pdwKeySpec, int32_t * pfCallerFreeProv, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptCreateHash(uint32_t hProv, uint32_t AlgId, uint32_t hKey, uint32_t dwFlags, uint32_t * phHash, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSetHashParam(uint32_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGetHashParam(uint32_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSignHash(uint32_t hHash, uint32_t dwKeySpec, char * sDescription, uint32_t dwFlags, uint8_t * pbSignature, uint32_t * pdwSigLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDestroyHash(uint32_t hHash, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptHashData(uint32_t hHash, uint8_t * pbData, uint32_t dwDataLen, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptVerifySignature(uint32_t hHash, uint8_t * pbSignature, uint32_t dwSigLen, uint32_t hPubKey, char * sDescription, uint32_t dwFlags, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptAcquireCertificatePrivateKey(PCCERT_CONTEXT pCert, uint32_t dwFlags, void * pvReserved, int64_t * phCryptProv, uint32_t * pdwKeySpec, int32_t * pfCallerFreeProv, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptCreateHash(int64_t hProv, uint32_t AlgId, int64_t hKey, uint32_t dwFlags, int64_t * phHash, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSetHashParam(int64_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGetHashParam(int64_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSignHash(int64_t hHash, uint32_t dwKeySpec, char * sDescription, uint32_t dwFlags, uint8_t * pbSignature, uint32_t * pdwSigLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDestroyHash(int64_t hHash, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptHashData(int64_t hHash, uint8_t * pbData, uint32_t dwDataLen, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptVerifySignature(int64_t hHash, uint8_t * pbSignature, uint32_t dwSigLen, int64_t hPubKey, char * sDescription, uint32_t dwFlags, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptFindLocalizedName(const sb_char16_t * pwszCryptName, sb_char16_t * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDecryptMessage(PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara, uint8_t * pbEncryptedBlob, uint32_t cbEncryptedBlob, uint8_t * pbDecrypted, uint32_t * pcbDecrypted, PCCERT_CONTEXT (* ppXchgCert), int32_t * OutResult);
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDecrypt(uint32_t hKey, uint32_t hHash, int32_t Final, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptEncrypt(uint32_t hKey, uint32_t hHash, int32_t Final, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwBufLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDuplicateKey(uint32_t hKey, uint32_t * pdwReserved, uint32_t dwFlags, uint32_t * phKey, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDecrypt(int64_t hKey, int64_t hHash, int32_t Final, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptEncrypt(int64_t hKey, int64_t hHash, int32_t Final, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwBufLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDuplicateKey(int64_t hKey, uint32_t * pdwReserved, uint32_t dwFlags, int64_t * phKey, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CertCreateCertificateContext(uint32_t dwCertEncodingType, const uint8_t * pbCertEncoded, uint32_t cbCertEncoded, PCCERT_CONTEXT * OutResult);
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGetProvParam(uint32_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t * pwdDataLen, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGetKeyParam(uint32_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDeriveKey(uint32_t hProv, uint32_t Algid, uint32_t hBaseData, uint32_t dwFlags, uint32_t * phKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGenKey(uint32_t hProv, uint32_t Algid, uint32_t dwFlags, uint32_t * phKey, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGetProvParam(int64_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t * pwdDataLen, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGetKeyParam(int64_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptDeriveKey(int64_t hProv, uint32_t Algid, int64_t hBaseData, uint32_t dwFlags, int64_t * phKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptGenKey(int64_t hProv, uint32_t Algid, uint32_t dwFlags, int64_t * phKey, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptRegisterOIDFunction(uint32_t dwEncodingType, char * pszFuncName, char * pszOID, sb_char16_t * pwszDll, char * pszOverrideFuncName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptUnregisterOIDFunction(uint32_t dwEncodingType, char * pszFuncName, char * pszOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptInstallOIDFunctionAddress(uint32_t hModule, uint32_t dwEncodingType, char * pszFuncName, uint32_t cFuncEntry, PCRYPT_OID_FUNC_ENTRY rgFuncEntry, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CoCreateGuid(PGUID guid, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_GetProcedureAddress(void * * P, const char * pcModuleName, int32_t szModuleName, const char * pcProcName, int32_t szProcName);
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSetProvParam(uint32_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSetKeyParam(uint32_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSetProvParam(int64_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptSetKeyParam(int64_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptUIDlgViewCertificate(PCCRYPTUI_VIEWCERTIFICATE_STRUCT pCertViewInfo, int32_t * pfPropertiesChanged, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptUIDlgSelectCertificate(PCCRYPTUI_SELECTCERTIFICATE_STRUCT pcsc, PCCERT_CONTEXT * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_CryptUIWizImport(uint32_t dwFlags, uint32_t hwndParent, sb_char16_t * pwszWizardTitle, void * pImportSrc, void * hDestCertStore, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptCreatePersistedKey(uint32_t * hProvider, uint32_t * (* phKey), sb_char16_t * pszAlgId, sb_char16_t * pszKeyName, uint32_t dwLegacyKeySpec, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptDecrypt(uint32_t * hKey, uint8_t * pbInput, uint32_t cbInput, void * pPaddingInfo, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptDeleteKey(uint32_t * hKey, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptDeriveKey(uint32_t * hSharedSecret, sb_char16_t * pwszKDF, PNCryptBufferDesc pParameterList, uint8_t * pbDerivedKey, uint32_t cbDerivedKey, uint32_t * pcbResult, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptEncrypt(uint32_t * hKey, uint8_t * pbInput, uint32_t cbInput, void * pPaddingInfo, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptEnumAlgorithms(uint32_t * hProvider, uint32_t dwAlgOperations, uint32_t * pdwAlgCount, PNCryptAlgorithmName (* ppAlgList), uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptEnumKeys(uint32_t * hProvider, sb_char16_t * pszScope, PNCryptKeyName (* ppKeyName), void * (* ppEnumState), uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptEnumStorageProviders(uint32_t * pdwProviderCount, PNCryptProviderName (* ppProviderList), uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptExportKey(uint32_t * hKey, uint32_t * hExportKey, sb_char16_t * pszBlobType, PNCryptBufferDesc pParameterList, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptFinalizeKey(uint32_t * hKey, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptFreeBuffer(void * pvInput, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptFreeObject(uint32_t * hObject, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptGetProperty(uint32_t * hObject, sb_char16_t * pszProperty, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptImportKey(uint32_t * hProvider, uint32_t * hImportKey, sb_char16_t * pszBlobType, PNCryptBufferDesc pParameterList, uint32_t * (* phKey), uint8_t * pbData, uint32_t cbData, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptIsAlgSupported(uint32_t * hProvider, sb_char16_t * pszAlgId, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptIsKeyHandle(uint32_t * hKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptKeyDerivation(uint32_t * hProvider, uint32_t * hKey, sb_char16_t * pswzDerivedKeyAlg, uint32_t cbDerivedKeyLength, PNCryptBufferDesc pParameterList, uint32_t * (* phDerivedKey), uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptNotifyChangeKey(uint32_t * hProvider, uint32_t * phEvent, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptOpenKey(uint32_t * hProvider, uint32_t * (* phKey), sb_char16_t * pszKeyName, uint32_t dwLegacyKeySpec, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptOpenStorageProvider(uint32_t * (* phProvider), sb_char16_t * pszProviderName, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptSecretAgreement(uint32_t * hPrivKey, uint32_t * hPubKey, uint32_t * (* phSecret), uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptSetProperty(uint32_t * hObject, sb_char16_t * pszProperty, uint8_t * pbInput, uint32_t cbInput, uint32_t dwFlags, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptSignHash(uint32_t * hKey, void * pPaddingInfo, uint8_t * pbHashValue, uint32_t cbHashValue, uint8_t * pbSignature, uint32_t cbSignature, uint32_t * pcbResult, uint32_t dwFlags, uint32_t * OutResult);
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptTranslateHandle(uint32_t * (* phProvider), uint32_t * (* phKey), uint32_t hLegacyProv, uint32_t hLegacyKey, uint32_t dwLegacyKeySpec, uint32_t dwFlags, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptTranslateHandle(uint32_t * (* phProvider), uint32_t * (* phKey), int64_t hLegacyProv, int64_t hLegacyKey, uint32_t dwLegacyKeySpec, uint32_t dwFlags, uint32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWinCrypt_NCryptVerifySignature(uint32_t * hKey, void * pPaddingInfo, uint8_t * pbHashValue, uint32_t cbHashValue, uint8_t * pbSignature, uint32_t cbSignature, uint32_t dwFlags, uint32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_WINCRYPT */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWINCRYPT */
