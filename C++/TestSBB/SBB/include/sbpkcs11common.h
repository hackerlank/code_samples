#ifndef __INC_SBPKCS11COMMON
#define __INC_SBPKCS11COMMON

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
#define SB_PKCS11_FUNC_FIRST 	0
#define SB_PKCS11_Initialize 	0
#define SB_PKCS11_Finalize 	1
#define SB_PKCS11_GetInfo 	2
#define SB_PKCS11_GetFunctionList 	3
#define SB_PKCS11_GetSlotList 	4
#define SB_PKCS11_GetSlotInfo 	5
#define SB_PKCS11_GetTokenInfo 	6
#define SB_PKCS11_GetMechanismList 	7
#define SB_PKCS11_GetMechanismInfo 	8
#define SB_PKCS11_InitToken 	9
#define SB_PKCS11_InitPIN 	10
#define SB_PKCS11_SetPIN 	11
#define SB_PKCS11_OpenSession 	12
#define SB_PKCS11_CloseSession 	13
#define SB_PKCS11_CloseAllSessions 	14
#define SB_PKCS11_GetSessionInfo 	15
#define SB_PKCS11_GetOperationState 	16
#define SB_PKCS11_SetOperationState 	17
#define SB_PKCS11_Login 	18
#define SB_PKCS11_Logout 	19
#define SB_PKCS11_CreateObject 	20
#define SB_PKCS11_CopyObject 	21
#define SB_PKCS11_DestroyObject 	22
#define SB_PKCS11_GetObjectSize 	23
#define SB_PKCS11_GetAttributeValue 	24
#define SB_PKCS11_SetAttributeValue 	25
#define SB_PKCS11_FindObjectsInit 	26
#define SB_PKCS11_FindObjects 	27
#define SB_PKCS11_FindObjectsFinal 	28
#define SB_PKCS11_EncryptInit 	29
#define SB_PKCS11_Encrypt 	30
#define SB_PKCS11_EncryptUpdate 	31
#define SB_PKCS11_EncryptFinal 	32
#define SB_PKCS11_DecryptInit 	33
#define SB_PKCS11_Decrypt 	34
#define SB_PKCS11_DecryptUpdate 	35
#define SB_PKCS11_DecryptFinal 	36
#define SB_PKCS11_DigestInit 	37
#define SB_PKCS11_Digest 	38
#define SB_PKCS11_DigestUpdate 	39
#define SB_PKCS11_DigestKey 	40
#define SB_PKCS11_DigestFinal 	41
#define SB_PKCS11_SignInit 	42
#define SB_PKCS11_Sign 	43
#define SB_PKCS11_SignUpdate 	44
#define SB_PKCS11_SignFinal 	45
#define SB_PKCS11_SignRecoverInit 	46
#define SB_PKCS11_SignRecover 	47
#define SB_PKCS11_VerifyInit 	48
#define SB_PKCS11_Verify 	49
#define SB_PKCS11_VerifyUpdate 	50
#define SB_PKCS11_VerifyFinal 	51
#define SB_PKCS11_VerifyRecoverInit 	52
#define SB_PKCS11_VerifyRecover 	53
#define SB_PKCS11_DigestEncryptUpdate 	54
#define SB_PKCS11_DecryptDigestUpdate 	55
#define SB_PKCS11_SignEncryptUpdate 	56
#define SB_PKCS11_DecryptVerifyUpdate 	57
#define SB_PKCS11_GenerateKey 	58
#define SB_PKCS11_GenerateKeyPair 	59
#define SB_PKCS11_WrapKey 	60
#define SB_PKCS11_UnwrapKey 	61
#define SB_PKCS11_DeriveKey 	62
#define SB_PKCS11_SeedRandom 	63
#define SB_PKCS11_GenerateRandom 	64
#define SB_PKCS11_GetFunctionStatus 	65
#define SB_PKCS11_CancelFunction 	66
#define SB_PKCS11_WaitForSlotEvent 	67
#define SB_PKCS11_FUNC_LAST 	67
#define SB_CK_TRUE 	1
#define SB_CK_FALSE 	0
#define SB_CKR_OK 	0
#define SB_CKR_CANCEL 	1
#define SB_CKR_HOST_MEMORY 	2
#define SB_CKR_SLOT_ID_INVALID 	3
#define SB_CKR_GENERAL_ERROR 	5
#define SB_CKR_FUNCTION_FAILED 	6
#define SB_CKR_ARGUMENTS_BAD 	7
#define SB_CKR_NO_EVENT 	8
#define SB_CKR_NEED_TO_CREATE_THREADS 	9
#define SB_CKR_CANT_LOCK 	10
#define SB_CKR_ATTRIBUTE_READ_ONLY 	16
#define SB_CKR_ATTRIBUTE_SENSITIVE 	17
#define SB_CKR_ATTRIBUTE_TYPE_INVALID 	18
#define SB_CKR_ATTRIBUTE_VALUE_INVALID 	19
#define SB_CKR_DATA_INVALID 	32
#define SB_CKR_DATA_LEN_RANGE 	33
#define SB_CKR_DEVICE_ERROR 	48
#define SB_CKR_DEVICE_MEMORY 	49
#define SB_CKR_DEVICE_REMOVED 	50
#define SB_CKR_ENCRYPTED_DATA_INVALID 	64
#define SB_CKR_ENCRYPTED_DATA_LEN_RANGE 	65
#define SB_CKR_FUNCTION_CANCELED 	80
#define SB_CKR_FUNCTION_NOT_PARALLEL 	81
#define SB_CKR_FUNCTION_NOT_SUPPORTED 	84
#define SB_CKR_KEY_HANDLE_INVALID 	96
#define SB_CKR_KEY_SIZE_RANGE 	98
#define SB_CKR_KEY_TYPE_INCONSISTENT 	99
#define SB_CKR_KEY_NOT_NEEDED 	100
#define SB_CKR_KEY_CHANGED 	101
#define SB_CKR_KEY_NEEDED 	102
#define SB_CKR_KEY_INDIGESTIBLE 	103
#define SB_CKR_KEY_FUNCTION_NOT_PERMITTED 	104
#define SB_CKR_KEY_NOT_WRAPPABLE 	105
#define SB_CKR_KEY_UNEXTRACTABLE 	106
#define SB_CKR_MECHANISM_INVALID 	112
#define SB_CKR_MECHANISM_PARAM_INVALID 	113
#define SB_CKR_OBJECT_HANDLE_INVALID 	130
#define SB_CKR_OPERATION_ACTIVE 	144
#define SB_CKR_OPERATION_NOT_INITIALIZED 	145
#define SB_CKR_PIN_INCORRECT 	160
#define SB_CKR_PIN_INVALID 	161
#define SB_CKR_PIN_LEN_RANGE 	162
#define SB_CKR_PIN_EXPIRED 	163
#define SB_CKR_PIN_LOCKED 	164
#define SB_CKR_SESSION_CLOSED 	176
#define SB_CKR_SESSION_COUNT 	177
#define SB_CKR_SESSION_HANDLE_INVALID 	179
#define SB_CKR_SESSION_PARALLEL_NOT_SUPPORTED 	180
#define SB_CKR_SESSION_READ_ONLY 	181
#define SB_CKR_SESSION_EXISTS 	182
#define SB_CKR_SESSION_READ_ONLY_EXISTS 	183
#define SB_CKR_SESSION_READ_WRITE_SO_EXISTS 	184
#define SB_CKR_SIGNATURE_INVALID 	192
#define SB_CKR_SIGNATURE_LEN_RANGE 	193
#define SB_CKR_TEMPLATE_INCOMPLETE 	208
#define SB_CKR_TEMPLATE_INCONSISTENT 	209
#define SB_CKR_TOKEN_NOT_PRESENT 	224
#define SB_CKR_TOKEN_NOT_RECOGNIZED 	225
#define SB_CKR_TOKEN_WRITE_PROTECTED 	226
#define SB_CKR_UNWRAPPING_KEY_HANDLE_INVALID 	240
#define SB_CKR_UNWRAPPING_KEY_SIZE_RANGE 	241
#define SB_CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT 	242
#define SB_CKR_USER_ALREADY_LOGGED_IN 	256
#define SB_CKR_USER_NOT_LOGGED_IN 	257
#define SB_CKR_USER_PIN_NOT_INITIALIZED 	258
#define SB_CKR_USER_TYPE_INVALID 	259
#define SB_CKR_USER_ANOTHER_ALREADY_LOGGED_IN 	260
#define SB_CKR_USER_TOO_MANY_TYPES 	261
#define SB_CKR_WRAPPED_KEY_INVALID 	272
#define SB_CKR_WRAPPED_KEY_LEN_RANGE 	274
#define SB_CKR_WRAPPING_KEY_HANDLE_INVALID 	275
#define SB_CKR_WRAPPING_KEY_SIZE_RANGE 	276
#define SB_CKR_WRAPPING_KEY_TYPE_INCONSISTENT 	277
#define SB_CKR_RANDOM_SEED_NOT_SUPPORTED 	288
#define SB_CKR_RANDOM_NO_RNG 	289
#define SB_CKR_BUFFER_TOO_SMALL 	336
#define SB_CKR_SAVED_STATE_INVALID 	352
#define SB_CKR_INFORMATION_SENSITIVE 	368
#define SB_CKR_STATE_UNSAVEABLE 	384
#define SB_CKR_CRYPTOKI_NOT_INITIALIZED 	400
#define SB_CKR_CRYPTOKI_ALREADY_INITIALIZED 	401
#define SB_CKR_MUTEX_BAD 	416
#define SB_CKR_MUTEX_NOT_LOCKED 	417
#define SB_CKR_VENDOR_DEFINED 	2147483648
#define SB_CKR_SBPKCS11PROXY_UNHANDLED_EXCEPTION 	2147483649
#define SB_PKCS11_VENDOR_DEFINED 	2147483648
#define SB_CKF_TOKEN_PRESENT 	1
#define SB_CKF_REMOVABLE_DEVICE 	2
#define SB_CKF_HW_SLOT 	4
#define SB_CKF_DONT_BLOCK 	1
#define SB_CKF_RNG 	1
#define SB_CKF_WRITE_PROTECTED 	2
#define SB_CKF_LOGIN_REQUIRED 	4
#define SB_CKF_USER_PIN_INITIALIZED 	8
#define SB_CKF_RESTORE_KEY_NOT_NEEDED 	32
#define SB_CKF_CLOCK_ON_TOKEN 	64
#define SB_CKF_PROTECTED_AUTHENTICATION_PATH 	256
#define SB_CKF_DUAL_CRYPTO_OPERATIONS 	512
#define SB_CKF_TOKEN_INITIALIZED 	1024
#define SB_CKF_SECONDARY_AUTHENTICATION 	2048
#define SB_CKF_USER_PIN_COUNT_LOW 	65536
#define SB_CKF_USER_PIN_FINAL_TRY 	131072
#define SB_CKF_USER_PIN_LOCKED 	262144
#define SB_CKF_USER_PIN_TO_BE_CHANGED 	524288
#define SB_CKF_SO_PIN_COUNT_LOW 	1048576
#define SB_CKF_SO_PIN_FINAL_TRY 	2097152
#define SB_CKF_SO_PIN_LOCKED 	4194304
#define SB_CKF_SO_PIN_TO_BE_CHANGED 	8388608
#define SB_CKM_RSA_PKCS_KEY_PAIR_GEN 	0
#define SB_CKM_RSA_PKCS 	1
#define SB_CKM_RSA_9796 	2
#define SB_CKM_RSA_X_509 	3
#define SB_CKM_MD2_RSA_PKCS 	4
#define SB_CKM_MD5_RSA_PKCS 	5
#define SB_CKM_SHA1_RSA_PKCS 	6
#define SB_CKM_RIPEMD128_RSA_PKCS 	7
#define SB_CKM_RIPEMD160_RSA_PKCS 	8
#define SB_CKM_RSA_PKCS_OAEP 	9
#define SB_CKM_RSA_X9_31_KEY_PAIR_GEN 	10
#define SB_CKM_RSA_X9_31 	11
#define SB_CKM_SHA1_RSA_X9_31 	12
#define SB_CKM_RSA_PKCS_PSS 	13
#define SB_CKM_SHA1_RSA_PKCS_PSS 	14
#define SB_CKM_DSA_KEY_PAIR_GEN 	16
#define SB_CKM_DSA 	17
#define SB_CKM_DSA_SHA1 	18
#define SB_CKM_DH_PKCS_KEY_PAIR_GEN 	32
#define SB_CKM_DH_PKCS_DERIVE 	33
#define SB_CKM_X9_42_DH_KEY_PAIR_GEN 	48
#define SB_CKM_X9_42_DH_DERIVE 	49
#define SB_CKM_X9_42_DH_HYBRID_DERIVE 	50
#define SB_CKM_X9_42_MQV_DERIVE 	51
#define SB_CKM_SHA256_RSA_PKCS 	64
#define SB_CKM_SHA384_RSA_PKCS 	65
#define SB_CKM_SHA512_RSA_PKCS 	66
#define SB_CKM_SHA256_RSA_PKCS_PSS 	67
#define SB_CKM_SHA384_RSA_PKCS_PSS 	68
#define SB_CKM_SHA512_RSA_PKCS_PSS 	69
#define SB_CKM_RC2_KEY_GEN 	256
#define SB_CKM_RC2_ECB 	257
#define SB_CKM_RC2_CBC 	258
#define SB_CKM_RC2_MAC 	259
#define SB_CKM_RC2_MAC_GENERAL 	260
#define SB_CKM_RC2_CBC_PAD 	261
#define SB_CKM_RC4_KEY_GEN 	272
#define SB_CKM_RC4 	273
#define SB_CKM_DES_KEY_GEN 	288
#define SB_CKM_DES_ECB 	289
#define SB_CKM_DES_CBC 	290
#define SB_CKM_DES_MAC 	291
#define SB_CKM_DES_MAC_GENERAL 	292
#define SB_CKM_DES_CBC_PAD 	293
#define SB_CKM_DES2_KEY_GEN 	304
#define SB_CKM_DES3_KEY_GEN 	305
#define SB_CKM_DES3_ECB 	306
#define SB_CKM_DES3_CBC 	307
#define SB_CKM_DES3_MAC 	308
#define SB_CKM_DES3_MAC_GENERAL 	309
#define SB_CKM_DES3_CBC_PAD 	310
#define SB_CKM_CDMF_KEY_GEN 	320
#define SB_CKM_CDMF_ECB 	321
#define SB_CKM_CDMF_CBC 	322
#define SB_CKM_CDMF_MAC 	323
#define SB_CKM_CDMF_MAC_GENERAL 	324
#define SB_CKM_CDMF_CBC_PAD 	325
#define SB_CKM_MD2 	512
#define SB_CKM_MD2_HMAC 	513
#define SB_CKM_MD2_HMAC_GENERAL 	514
#define SB_CKM_MD5 	528
#define SB_CKM_MD5_HMAC 	529
#define SB_CKM_MD5_HMAC_GENERAL 	530
#define SB_CKM_SHA_1 	544
#define SB_CKM_SHA_1_HMAC 	545
#define SB_CKM_SHA_1_HMAC_GENERAL 	546
#define SB_CKM_RIPEMD128 	560
#define SB_CKM_RIPEMD128_HMAC 	561
#define SB_CKM_RIPEMD128_HMAC_GENERAL 	562
#define SB_CKM_RIPEMD160 	576
#define SB_CKM_RIPEMD160_HMAC 	577
#define SB_CKM_RIPEMD160_HMAC_GENERAL 	578
#define SB_CKM_CAST_KEY_GEN 	768
#define SB_CKM_CAST_ECB 	769
#define SB_CKM_CAST_CBC 	770
#define SB_CKM_CAST_MAC 	771
#define SB_CKM_CAST_MAC_GENERAL 	772
#define SB_CKM_CAST_CBC_PAD 	773
#define SB_CKM_CAST3_KEY_GEN 	784
#define SB_CKM_CAST3_ECB 	785
#define SB_CKM_CAST3_CBC 	786
#define SB_CKM_CAST3_MAC 	787
#define SB_CKM_CAST3_MAC_GENERAL 	788
#define SB_CKM_CAST3_CBC_PAD 	789
#define SB_CKM_CAST5_KEY_GEN 	800
#define SB_CKM_CAST128_KEY_GEN 	800
#define SB_CKM_CAST5_ECB 	801
#define SB_CKM_CAST128_ECB 	801
#define SB_CKM_CAST5_CBC 	802
#define SB_CKM_CAST128_CBC 	802
#define SB_CKM_CAST5_MAC 	803
#define SB_CKM_CAST128_MAC 	803
#define SB_CKM_CAST5_MAC_GENERAL 	804
#define SB_CKM_CAST128_MAC_GENERAL 	804
#define SB_CKM_CAST5_CBC_PAD 	805
#define SB_CKM_CAST128_CBC_PAD 	805
#define SB_CKM_RC5_KEY_GEN 	816
#define SB_CKM_RC5_ECB 	817
#define SB_CKM_RC5_CBC 	818
#define SB_CKM_RC5_MAC 	819
#define SB_CKM_RC5_MAC_GENERAL 	820
#define SB_CKM_RC5_CBC_PAD 	821
#define SB_CKM_IDEA_KEY_GEN 	832
#define SB_CKM_IDEA_ECB 	833
#define SB_CKM_IDEA_CBC 	834
#define SB_CKM_IDEA_MAC 	835
#define SB_CKM_IDEA_MAC_GENERAL 	836
#define SB_CKM_IDEA_CBC_PAD 	837
#define SB_CKM_GENERIC_SECRET_KEY_GEN 	848
#define SB_CKM_CONCATENATE_BASE_AND_KEY 	864
#define SB_CKM_CONCATENATE_BASE_AND_DATA 	866
#define SB_CKM_CONCATENATE_DATA_AND_BASE 	867
#define SB_CKM_XOR_BASE_AND_DATA 	868
#define SB_CKM_EXTRACT_KEY_FROM_KEY 	869
#define SB_CKM_SSL3_PRE_MASTER_KEY_GEN 	880
#define SB_CKM_SSL3_MASTER_KEY_DERIVE 	881
#define SB_CKM_SSL3_KEY_AND_MAC_DERIVE 	882
#define SB_CKM_SSL3_MASTER_KEY_DERIVE_DH 	883
#define SB_CKM_TLS_PRE_MASTER_KEY_GEN 	884
#define SB_CKM_TLS_MASTER_KEY_DERIVE 	885
#define SB_CKM_TLS_KEY_AND_MAC_DERIVE 	886
#define SB_CKM_TLS_MASTER_KEY_DERIVE_DH 	887
#define SB_CKM_SSL3_MD5_MAC 	896
#define SB_CKM_SSL3_SHA1_MAC 	897
#define SB_CKM_MD5_KEY_DERIVATION 	912
#define SB_CKM_MD2_KEY_DERIVATION 	913
#define SB_CKM_SHA1_KEY_DERIVATION 	914
#define SB_CKM_PBE_MD2_DES_CBC 	928
#define SB_CKM_PBE_MD5_DES_CBC 	929
#define SB_CKM_PBE_MD5_CAST_CBC 	930
#define SB_CKM_PBE_MD5_CAST3_CBC 	931
#define SB_CKM_PBE_MD5_CAST5_CBC 	932
#define SB_CKM_PBE_MD5_CAST128_CBC 	932
#define SB_CKM_PBE_SHA1_CAST5_CBC 	933
#define SB_CKM_PBE_SHA1_CAST128_CBC 	933
#define SB_CKM_PBE_SHA1_RC4_128 	934
#define SB_CKM_PBE_SHA1_RC4_40 	935
#define SB_CKM_PBE_SHA1_DES3_EDE_CBC 	936
#define SB_CKM_PBE_SHA1_DES2_EDE_CBC 	937
#define SB_CKM_PBE_SHA1_RC2_128_CBC 	938
#define SB_CKM_PBE_SHA1_RC2_40_CBC 	939
#define SB_CKM_PKCS5_PBKD2 	944
#define SB_CKM_PBA_SHA1_WITH_SHA1_HMAC 	960
#define SB_CKM_KEY_WRAP_LYNKS 	1024
#define SB_CKM_KEY_WRAP_SET_OAEP 	1025
#define SB_CKM_CMS_SIG 	1280
#define SB_CKM_SKIPJACK_KEY_GEN 	4096
#define SB_CKM_SKIPJACK_ECB64 	4097
#define SB_CKM_SKIPJACK_CBC64 	4098
#define SB_CKM_SKIPJACK_OFB64 	4099
#define SB_CKM_SKIPJACK_CFB64 	4100
#define SB_CKM_SKIPJACK_CFB32 	4101
#define SB_CKM_SKIPJACK_CFB16 	4102
#define SB_CKM_SKIPJACK_CFB8 	4103
#define SB_CKM_SKIPJACK_WRAP 	4104
#define SB_CKM_SKIPJACK_PRIVATE_WRAP 	4105
#define SB_CKM_SKIPJACK_RELAYX 	4106
#define SB_CKM_KEA_KEY_PAIR_GEN 	4112
#define SB_CKM_KEA_KEY_DERIVE 	4113
#define SB_CKM_FORTEZZA_TIMESTAMP 	4128
#define SB_CKM_BATON_KEY_GEN 	4144
#define SB_CKM_BATON_ECB128 	4145
#define SB_CKM_BATON_ECB96 	4146
#define SB_CKM_BATON_CBC128 	4147
#define SB_CKM_BATON_COUNTER 	4148
#define SB_CKM_BATON_SHUFFLE 	4149
#define SB_CKM_BATON_WRAP 	4150
#define SB_CKM_ECDSA_KEY_PAIR_GEN 	4160
#define SB_CKM_EC_KEY_PAIR_GEN 	4160
#define SB_CKM_ECDSA 	4161
#define SB_CKM_ECDSA_SHA1 	4162
#define SB_CKM_ECDH1_DERIVE 	4176
#define SB_CKM_ECDH1_COFACTOR_DERIVE 	4177
#define SB_CKM_ECMQV_DERIVE 	4178
#define SB_CKM_JUNIPER_KEY_GEN 	4192
#define SB_CKM_JUNIPER_ECB128 	4193
#define SB_CKM_JUNIPER_CBC128 	4194
#define SB_CKM_JUNIPER_COUNTER 	4195
#define SB_CKM_JUNIPER_SHUFFLE 	4196
#define SB_CKM_JUNIPER_WRAP 	4197
#define SB_CKM_FASTHASH 	4208
#define SB_CKM_AES_KEY_GEN 	4224
#define SB_CKM_AES_ECB 	4225
#define SB_CKM_AES_CBC 	4226
#define SB_CKM_AES_MAC 	4227
#define SB_CKM_AES_MAC_GENERAL 	4228
#define SB_CKM_AES_CBC_PAD 	4229
#define SB_CKM_DSA_PARAMETER_GEN 	8192
#define SB_CKM_DH_PKCS_PARAMETER_GEN 	8193
#define SB_CKM_X9_42_DH_PARAMETER_GEN 	8194
#define SB_CKM_SHA256 	592
#define SB_CKM_SHA256_HMAC 	593
#define SB_CKM_SHA256_HMAC_GENERAL 	594
#define SB_CKM_SHA384 	608
#define SB_CKM_SHA384_HMAC 	609
#define SB_CKM_SHA384_HMAC_GENERAL 	610
#define SB_CKM_SHA512 	624
#define SB_CKM_SHA512_HMAC 	625
#define SB_CKM_SHA512_HMAC_GENERAL 	626
#define SB_CKM_VENDOR_DEFINED 	2147483648
#define SB_CK_B_FALSE 	0
#define SB_CK_B_TRUE 	255
#define SB_CK_INVALID_HANDLE 	0
#define SB_CKA_CLASS 	0
#define SB_CKA_TOKEN 	1
#define SB_CKA_PRIVATE 	2
#define SB_CKA_MODIFIABLE 	368
#define SB_CKA_LABEL 	3
#define SB_CKA_APPLICATION 	16
#define SB_CKA_VALUE 	17
#define SB_CKA_OBJECT_ID 	18
#define SB_CKA_CERTIFICATE_TYPE 	128
#define SB_CKA_ISSUER 	129
#define SB_CKA_SERIAL_NUMBER 	130
#define SB_CKA_AC_ISSUER 	131
#define SB_CKA_OWNER 	132
#define SB_CKA_ATTR_TYPES 	133
#define SB_CKA_VALUE_LEN 	353
#define SB_CKA_TRUSTED 	134
#define SB_CKA_CERTIFICATE_CATEGORY 	135
#define SB_CKA_URL 	136
#define SB_CKA_KEY_TYPE 	256
#define SB_CKA_SUBJECT 	257
#define SB_CKA_ID 	258
#define SB_CKA_SENSITIVE 	259
#define SB_CKA_ENCRYPT 	260
#define SB_CKA_DECRYPT 	261
#define SB_CKA_WRAP 	262
#define SB_CKA_UNWRAP 	263
#define SB_CKA_SIGN 	264
#define SB_CKA_SIGN_RECOVER 	265
#define SB_CKA_VERIFY 	266
#define SB_CKA_VERIFY_RECOVER 	267
#define SB_CKA_DERIVE 	268
#define SB_CKA_START_DATE 	272
#define SB_CKA_END_DATE 	273
#define SB_CKA_LOCAL 	355
#define SB_CKA_MODULUS 	288
#define SB_CKA_MODULUS_BITS 	289
#define SB_CKA_PUBLIC_EXPONENT 	290
#define SB_CKA_PRIVATE_EXPONENT 	291
#define SB_CKA_PRIME_1 	292
#define SB_CKA_PRIME_2 	293
#define SB_CKA_EXPONENT_1 	294
#define SB_CKA_EXPONENT_2 	295
#define SB_CKA_COEFFICIENT 	296
#define SB_CKA_PRIME 	304
#define SB_CKA_SUBPRIME 	305
#define SB_CKA_BASE 	306
#define SB_CKA_EXTRACTABLE 	354
#define SB_CKA_NEVER_EXTRACTABLE 	356
#define SB_CKA_ALWAYS_SENSITIVE 	357
#define SB_CKA_WRAP_WITH_TRUSTED 	528
#define SB_CKA_CHECK_VALUE 	144
#define SB_CKA_PRIME_BITS 	307
#define SB_CKA_SUBPRIME_BITS 	308
#define SB_CKA_ALWAYS_AUTHENTICATE 	514
#define SB_CKA_HASH_OF_SUBJECT_PUBLIC_KEY 	138
#define SB_CKA_HASH_OF_ISSUER_PUBLIC_KEY 	139
#define SB_CKA_JAVA_MIDP_SECURITY_DOMAIN 	136
#define SB_CKA_ECDSA_PARAMS 	384
#define SB_CKA_EC_PARAMS 	384
#define SB_CKA_EC_POINT 	385
#define SB_CKA_UNDEFINED 	4294967295
#define SB_CKC_X_509 	0
#define SB_CKC_X_509_ATTR_CERT 	1
#define SB_CKC_WTLS 	2
#define SB_CKC_VENDOR_DEFINED 	2147483648
#define SB_CKF_OS_LOCKING_OK 	2
#define SB_CKF_RW_SESSION 	2
#define SB_CKF_SERIAL_SESSION 	4
#define SB_CKK_RSA 	0
#define SB_CKK_DSA 	1
#define SB_CKK_DH 	2
#define SB_CKK_ECDSA 	3
#define SB_CKK_EC 	3
#define SB_CKK_X9_42_DH 	4
#define SB_CKK_KEA 	5
#define SB_CKK_GENERIC_SECRET 	16
#define SB_CKK_RC2 	17
#define SB_CKK_RC4 	18
#define SB_CKK_DES 	19
#define SB_CKK_DES2 	20
#define SB_CKK_DES3 	21
#define SB_CKK_CAST 	22
#define SB_CKK_CAST3 	23
#define SB_CKK_CAST5 	24
#define SB_CKK_CAST128 	24
#define SB_CKK_RC5 	25
#define SB_CKK_IDEA 	26
#define SB_CKK_SKIPJACK 	27
#define SB_CKK_BATON 	28
#define SB_CKK_JUNIPER 	29
#define SB_CKK_CDMF 	30
#define SB_CKK_AES 	31
#define SB_CKK_BLOWFISH 	32
#define SB_CKK_TWOFISH 	33
#define SB_CKK_VENDOR_DEFINED 	2147483648
#define SB_CKN_SURRENDER 	0
#define SB_CKO_DATA 	0
#define SB_CKO_CERTIFICATE 	1
#define SB_CKO_PUBLIC_KEY 	2
#define SB_CKO_PRIVATE_KEY 	3
#define SB_CKO_SECRET_KEY 	4
#define SB_CKO_HW_FEATURE 	5
#define SB_CKO_DOMAIN_PARAMETERS 	6
#define SB_CKO_MECHANISM 	7
#define SB_CKO_VENDOR_DEFINED 	2147483648
#define SB_CKO_UNKNOWN 	4294967295
#define SB_CKS_RO_PUBLIC_SESSION 	0
#define SB_CKS_RO_USER_FUNCTIONS 	1
#define SB_CKS_RW_PUBLIC_SESSION 	2
#define SB_CKS_RW_USER_FUNCTIONS 	3
#define SB_CKS_RW_SO_FUNCTIONS 	4
#define SB_CKU_SO 	0
#define SB_CKU_USER 	1
#define SB_CKU_CONTEXT_SPECIFIC 	2
#define SB_NULL_PTR 	0

typedef void * (TPKCS11FuncArray[68]);

#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef uint32_t SB_CK_SLOT_ID_ARRAY[1];
#else
typedef int64_t SB_CK_SLOT_ID_ARRAY[1];
#endif

typedef Pointer SB_CK_VOID_PTR;

#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef uint32_t * SB_CK_SLOT_ID_PTR;
#else
typedef int64_t * SB_CK_SLOT_ID_PTR;
#endif

typedef PChar SB_CK_UTF8CHAR_PTR;

#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef uint32_t SB_CK_OBJECT_HANDLE_ARRAY[1];
#else
typedef int64_t SB_CK_OBJECT_HANDLE_ARRAY[1];
#endif

typedef uint8_t * SB_CK_CHAR_PTR;

typedef Pointer SB_CK_VOID;

typedef uint8_t * SB_CK_BYTE_PTR;

#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef uint32_t * SB_CK_ULONG_PTR;
#else
typedef int64_t * SB_CK_ULONG_PTR;
#endif

#pragma pack(1)
typedef struct 
{
	uint8_t Major;
	uint8_t Minor;
} TPKCS11Version;

#pragma pack(1)
typedef struct 
{
	TPKCS11Version Version;
	void * C_Initialize;
	void * C_Finalize;
	void * C_GetInfo;
	void * C_GetFunctionList;
	void * C_GetSlotList;
	void * C_GetSlotInfo;
	void * C_GetTokenInfo;
	void * C_GetMechanismList;
	void * C_GetMechanismInfo;
	void * C_InitToken;
	void * C_InitPIN;
	void * C_SetPIN;
	void * C_OpenSession;
	void * C_CloseSession;
	void * C_CloseAllSessions;
	void * C_GetSessionInfo;
	void * C_GetOperationState;
	void * C_SetOperationState;
	void * C_Login;
	void * C_Logout;
	void * C_CreateObject;
	void * C_CopyObject;
	void * C_DestroyObject;
	void * C_GetObjectSize;
	void * C_GetAttributeValue;
	void * C_SetAttributeValue;
	void * C_FindObjectsInit;
	void * C_FindObjects;
	void * C_FindObjectsFinal;
	void * C_EncryptInit;
	void * C_Encrypt;
	void * C_EncryptUpdate;
	void * C_EncryptFinal;
	void * C_DecryptInit;
	void * C_Decrypt;
	void * C_DecryptUpdate;
	void * C_DecryptFinal;
	void * C_DigestInit;
	void * C_Digest;
	void * C_DigestUpdate;
	void * C_DigestKey;
	void * C_DigestFinal;
	void * C_SignInit;
	void * C_Sign;
	void * C_SignUpdate;
	void * C_SignFinal;
	void * C_SignRecoverInit;
	void * C_SignRecover;
	void * C_VerifyInit;
	void * C_Verify;
	void * C_VerifyUpdate;
	void * C_VerifyFinal;
	void * C_VerifyRecoverInit;
	void * C_VerifyRecover;
	void * C_DigestEncryptUpdate;
	void * C_DecryptDigestUpdate;
	void * C_SignEncryptUpdate;
	void * C_DecryptVerifyUpdate;
	void * C_GenerateKey;
	void * C_GenerateKeyPair;
	void * C_WrapKey;
	void * C_UnwrapKey;
	void * C_DeriveKey;
	void * C_SeedRandom;
	void * C_GenerateRandom;
	void * C_GetFunctionStatus;
	void * C_CancelFunction;
	void * C_WaitForSlotEvent;
} TPKCS11FunctionList, * PPKCS11FunctionList, * SB_CK_FUNCTION_LIST_PTR;

typedef TPKCS11FunctionList SB_CK_FUNCTION_LIST;

#pragma pack(1)
typedef struct 
{
	void * CreateMutex;
	void * DestroyMutex;
	void * LockMutex;
	void * UnlockMutex;
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t flags;
#else
	int64_t flags;
#endif
	void * pReserved;
} TPKCS11InitializeArgs, * PPKCS11InitializeArgs, * SB_CK_C_INITIALIZE_ARGS_PTR;

typedef TPKCS11InitializeArgs SB_CK_C_INITIALIZE_ARGS;

#pragma pack(1)
typedef struct 
{
	void * CreateMutex;
	void * DestroyMutex;
	void * LockMutex;
	void * UnlockMutex;
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t flags;
#else
	int64_t flags;
#endif
	uint8_t * LibraryParams;
	void * pReserved;
} TPKCS11InitializeArgsNSS, * PPKCS11InitializeArgsNSS, * SB_CK_C_INITIALIZE_ARGS_NSS_PTR;

typedef TPKCS11InitializeArgsNSS SB_CK_C_INITIALIZE_ARGS_NSS;

#pragma pack(1)
typedef struct 
{
	TPKCS11Version cryptokiVersion;
	char manufacturerID[32];
	uint32_t flags;
	char libraryDescription[32];
	TPKCS11Version libraryVersion;
} TPKCS11Info, * PPKCS11Info, * SB_CK_INFO_PTR;

typedef TPKCS11Info SB_CK_INFO;

#pragma pack(1)
typedef struct 
{
	char slotDescription[64];
	char manufacturerID[32];
	uint32_t flags;
	TPKCS11Version hardwareVersion;
	TPKCS11Version firmwareVersion;
} TPKCS11SlotInfo, * PPKCS11SlotInfo, * SB_CK_SLOT_INFO_PTR;

typedef TPKCS11SlotInfo SB_CK_SLOT_INFO;

#pragma pack(1)
typedef struct 
{
	char _label[32];
	char manufacturerID[32];
	char model[16];
	char serialNumber[16];
	uint32_t flags;
	uint32_t ulMaxSessionCount;
	uint32_t ulSessionCount;
	uint32_t ulMaxRwSessionCount;
	uint32_t ulRwSessionCount;
	uint32_t ulMaxPinLen;
	uint32_t ulMinPinLen;
	uint32_t ulTotalPublicMemory;
	uint32_t ulFreePublicMemory;
	uint32_t ulTotalPrivateMemory;
	uint32_t ulFreePrivateMemory;
	TPKCS11Version hardwareVersion;
	TPKCS11Version firmwareVersion;
	char utcTime[16];
} TPKCS11TokenInfo, * PPKCS11TokenInfo, * SB_CK_TOKEN_INFO_PTR;

typedef TPKCS11TokenInfo SB_CK_TOKEN_INFO;

#pragma pack(1)
typedef struct 
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t slotID;
	uint32_t state;
	uint32_t flags;
	uint32_t ulDeviceError;
#else
	int64_t slotID;
	int64_t state;
	int64_t flags;
	int64_t ulDeviceError;
#endif
} TPKCS11SessionInfo, * PPKCS11SessionInfo, * SB_CK_SESSION_INFO_PTR;

typedef TPKCS11SessionInfo SB_CK_SESSION_INFO;

#pragma pack(1)
typedef struct 
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t _type;
#else
	int64_t _type;
#endif
	void * pValue;
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t ulValueLen;
#else
	int64_t ulValueLen;
#endif
} TPKCS11Attribute, * PPKCS11Attribute, * SB_CK_ATTRIBUTE_PTR;

typedef TPKCS11Attribute SB_CK_ATTRIBUTE;

typedef TPKCS11Attribute SB_CK_ATTRIBUTE_ARRAY[65537];

#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef uint32_t * SB_CK_MECHANISM_TYPE_PTR;
#else
typedef int64_t * SB_CK_MECHANISM_TYPE_PTR;
#endif

#pragma pack(1)
typedef struct 
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t mechanism;
#else
	int64_t mechanism;
#endif
	void * pParameter;
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t ulParameterLen;
#else
	int64_t ulParameterLen;
#endif
} SB_CK_MECHANISM, * SB_CK_MECHANISM_PTR;

#pragma pack(1)
typedef struct 
{
#ifdef SB_NOT_CPU64_OR_WINDOWS
	uint32_t ulMinKeySize;
	uint32_t ulMaxKeySize;
	uint32_t flags;
#else
	int64_t ulMinKeySize;
	int64_t ulMaxKeySize;
	int64_t flags;
#endif
} TPKCS11MechanismInfo, * PPKCS11MechanismInfo, * SB_CK_MECHANISM_INFO_PTR;

typedef TPKCS11MechanismInfo SB_CK_MECHANISM_INFO;

typedef void * (* SB_CK_VOID_PTR_PTR);

typedef SB_CK_FUNCTION_LIST_PTR (* SB_CK_FUNCTION_LIST_PTR_PTR);

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS11COMMON */
