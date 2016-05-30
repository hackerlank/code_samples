#ifndef __INC_SBCONSTANTS
#define __INC_SBCONSTANTS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_CRLFStr 	"\r\n"
#define SB_CRStr 	'\r'
#define SB_LFStr 	'\n'
#define SB_LFLFStr 	"\n\n"
#define SB_CRLFCRLFStr 	"\r\n\r\n"
#define SB_CRLFCRLFZeroStr 	"\r\n\r\n\x00"
#define SB_CRLFTABStr 	"\r\n\t"
#define SB_CRLFSPACEStr 	"\r\n "
#define SB_TwoDashesStr 	"--"
#define SB_SpaceStr 	' '
#define SB_EqualCharStr 	'='
#define SB_TabByte 	9
#define SB_CRByte 	13
#define SB_LFByte 	10
#define SB_SpaceByte 	32
#define SB_DoubleQuoteByte 	34
#define SB_ColonByte 	58
#define SB_BackslashByte 	92
#define SB_SecondsInDay 	86400
#define SB_SecondsInHour 	3600
#define SB_SecondsInMinute 	60
#define SB_HoursInDay 	24
#define SB_MinutesInHour 	60
#define SB_MinutesInDay 	1440
#define SB_AnsiStrStartOffset 	1
#define SB_AnsiStrStartInvOffset 	0
#define SB_StringStartOffset 	1
#define SB_StringStartInvOffset 	0
#ifndef LINUX
#define SB_cSBPathSeparator 	'\\'
#else
#define SB_cSBPathSeparator 	'/'
#endif
#define SB_CERT_ALGORITHM_ID_RSA_ENCRYPTION 	0
#define SB_CERT_ALGORITHM_MD2_RSA_ENCRYPTION 	1
#define SB_CERT_ALGORITHM_MD5_RSA_ENCRYPTION 	2
#define SB_CERT_ALGORITHM_SHA1_RSA_ENCRYPTION 	3
#define SB_CERT_ALGORITHM_ID_DSA 	4
#define SB_CERT_ALGORITHM_ID_DSA_SHA1 	5
#define SB_CERT_ALGORITHM_DH_PUBLIC 	6
#define SB_CERT_ALGORITHM_SHA224_RSA_ENCRYPTION 	7
#define SB_CERT_ALGORITHM_SHA256_RSA_ENCRYPTION 	8
#define SB_CERT_ALGORITHM_SHA384_RSA_ENCRYPTION 	9
#define SB_CERT_ALGORITHM_SHA512_RSA_ENCRYPTION 	10
#define SB_CERT_ALGORITHM_ID_RSAPSS 	11
#define SB_CERT_ALGORITHM_ID_RSAOAEP 	12
#define SB_CERT_ALGORITHM_RSASIGNATURE_RIPEMD160 	13
#define SB_CERT_ALGORITHM_ID_ELGAMAL 	14
#define SB_CERT_ALGORITHM_SHA1_ECDSA 	15
#define SB_CERT_ALGORITHM_RECOMMENDED_ECDSA 	16
#define SB_CERT_ALGORITHM_SHA224_ECDSA 	17
#define SB_CERT_ALGORITHM_SHA256_ECDSA 	18
#define SB_CERT_ALGORITHM_SHA384_ECDSA 	19
#define SB_CERT_ALGORITHM_SHA512_ECDSA 	20
#define SB_CERT_ALGORITHM_EC 	21
#define SB_CERT_ALGORITHM_SPECIFIED_ECDSA 	22
#define SB_CERT_ALGORITHM_GOST_R3410_1994 	23
#define SB_CERT_ALGORITHM_GOST_R3410_2001 	24
#define SB_CERT_ALGORITHM_GOST_R3411_WITH_R3410_1994 	25
#define SB_CERT_ALGORITHM_GOST_R3411_WITH_R3410_2001 	26
#define SB_CERT_ALGORITHM_SHA1_ECDSA_PLAIN 	27
#define SB_CERT_ALGORITHM_SHA224_ECDSA_PLAIN 	28
#define SB_CERT_ALGORITHM_SHA256_ECDSA_PLAIN 	29
#define SB_CERT_ALGORITHM_SHA384_ECDSA_PLAIN 	30
#define SB_CERT_ALGORITHM_SHA512_ECDSA_PLAIN 	31
#define SB_CERT_ALGORITHM_RIPEMD160_ECDSA_PLAIN 	32
#define SB_CERT_ALGORITHM_WHIRLPOOL_RSA_ENCRYPTION 	33
#define SB_CERT_ALGORITHM_ID_DSA_SHA224 	34
#define SB_CERT_ALGORITHM_ID_DSA_SHA256 	35
#define SB_CERT_MGF1 	513
#define SB_CERT_MGF1_SHA1 	514
#define SB_CERT_MGF1_SHA224 	515
#define SB_CERT_MGF1_SHA256 	516
#define SB_CERT_MGF1_SHA384 	517
#define SB_CERT_MGF1_SHA512 	518
#define SB_CERT_MGF1_RIPEMD160 	519
#define SB_CERT_MGF1_WHIRLPOOL 	520
#define SB_CERT_ALGORITHM_UNKNOWN 	65535
#define SB_ALGORITHM_CNT_BASE 	28672
#define SB_ALGORITHM_CNT_RC4 	28673
#define SB_ALGORITHM_CNT_DES 	28674
#define SB_ALGORITHM_CNT_3DES 	28675
#define SB_ALGORITHM_CNT_RC2 	28676
#define SB_ALGORITHM_CNT_AES128 	28677
#define SB_ALGORITHM_CNT_AES192 	28678
#define SB_ALGORITHM_CNT_AES256 	28679
#define SB_ALGORITHM_CNT_IDENTITY 	28682
#define SB_ALGORITHM_CNT_BLOWFISH 	28688
#define SB_ALGORITHM_CNT_TWOFISH 	28689
#define SB_ALGORITHM_CNT_CAMELLIA 	28690
#define SB_ALGORITHM_CNT_CAST128 	28691
#define SB_ALGORITHM_CNT_IDEA 	28692
#define SB_ALGORITHM_CNT_SERPENT 	28693
#define SB_ALGORITHM_CNT_TWOFISH128 	28694
#define SB_ALGORITHM_CNT_TWOFISH192 	28695
#define SB_ALGORITHM_CNT_TWOFISH256 	28696
#define SB_ALGORITHM_CNT_CAMELLIA128 	28697
#define SB_ALGORITHM_CNT_CAMELLIA192 	28698
#define SB_ALGORITHM_CNT_CAMELLIA256 	28699
#define SB_ALGORITHM_CNT_SERPENT128 	28700
#define SB_ALGORITHM_CNT_SERPENT192 	28701
#define SB_ALGORITHM_CNT_SERPENT256 	28702
#define SB_ALGORITHM_CNT_SEED 	28704
#define SB_ALGORITHM_CNT_RABBIT 	28705
#define SB_ALGORITHM_CNT_SYMMETRIC 	28706
#define SB_ALGORITHM_CNT_GOST_28147_1989 	28707
#define SB_ALGORITHM_CNT_CHACHA20 	28708
#define SB_ALGORITHM_PK_BASE 	29696
#define SB_ALGORITHM_PK_RSA 	29697
#define SB_ALGORITHM_PK_DSA 	29698
#define SB_ALGORITHM_PK_ELGAMAL 	29699
#define SB_ALGORITHM_PK_GOST_R3410_1994 	29700
#define SB_ALGORITHM_PK_EC 	29701
#define SB_ALGORITHM_PK_ECDSA 	29702
#define SB_ALGORITHM_PK_DH 	29703
#define SB_ALGORITHM_PK_SRP 	29704
#define SB_ALGORITHM_PK_ECDH 	29705
#define SB_ALGORITHM_PK_GOST_R3410_2001 	29706
#define SB_ALGORITHM_DGST_BASE 	28928
#define SB_ALGORITHM_DGST_SHA1 	28929
#define SB_ALGORITHM_DGST_MD5 	28930
#define SB_ALGORITHM_DGST_MD2 	28931
#define SB_ALGORITHM_DGST_SHA256 	28932
#define SB_ALGORITHM_DGST_SHA384 	28933
#define SB_ALGORITHM_DGST_SHA512 	28934
#define SB_ALGORITHM_DGST_SHA224 	28935
#define SB_ALGORITHM_DGST_MD4 	28936
#define SB_ALGORITHM_DGST_RIPEMD160 	28937
#define SB_ALGORITHM_DGST_CRC32 	28938
#define SB_ALGORITHM_DGST_SSL3 	28939
#define SB_ALGORITHM_DGST_GOST_R3411_1994 	28940
#define SB_ALGORITHM_DGST_WHIRLPOOL 	28941
#define SB_ALGORITHM_DGST_POLY1305 	28942
#define SB_ALGORITHM_PBE_BASE 	29184
#define SB_ALGORITHM_PBE_SHA1_RC4_128 	29185
#define SB_ALGORITHM_PBE_SHA1_RC4_40 	29186
#define SB_ALGORITHM_PBE_SHA1_3DES 	29187
#define SB_ALGORITHM_PBE_SHA1_RC2_128 	29188
#define SB_ALGORITHM_PBE_SHA1_RC2_40 	29189
#define SB_ALGORITHM_P5_PBE_MD2_DES 	29217
#define SB_ALGORITHM_P5_PBE_MD2_RC2 	29218
#define SB_ALGORITHM_P5_PBE_MD5_DES 	29219
#define SB_ALGORITHM_P5_PBE_MD5_RC2 	29220
#define SB_ALGORITHM_P5_PBE_SHA1_DES 	29221
#define SB_ALGORITHM_P5_PBE_SHA1_RC2 	29222
#define SB_ALGORITHM_P5_PBES1 	29249
#define SB_ALGORITHM_P5_PBES2 	29250
#define SB_ALGORITHM_P5_PBKDF1 	29265
#define SB_ALGORITHM_P5_PBKDF2 	29266
#define SB_ALGORITHM_P5_PBMAC1 	29281
#define SB_ALGORITHM_MAC_BASE 	29440
#define SB_ALGORITHM_MAC_HMACSHA1 	29441
#define SB_ALGORITHM_MAC_HMACSHA224 	29442
#define SB_ALGORITHM_MAC_HMACSHA256 	29443
#define SB_ALGORITHM_MAC_HMACSHA384 	29444
#define SB_ALGORITHM_MAC_HMACSHA512 	29445
#define SB_ALGORITHM_MAC_HMACMD5 	29446
#define SB_ALGORITHM_MAC_HMACRIPEMD 	29447
#define SB_ALGORITHM_HMAC 	29448
#define SB_ALGORITHM_UMAC32 	29456
#define SB_ALGORITHM_UMAC64 	29457
#define SB_ALGORITHM_UMAC96 	29458
#define SB_ALGORITHM_UMAC128 	29459
#define SB_ALGORITHM_MAC_GOST_28147_1989 	29460
#define SB_ALGORITHM_HMAC_GOST_R3411_1994 	29461
#define SB_ALGORITHM_MAC_POLY1305 	29462
#define SB_ALGORITHM_AEAD_BASE 	29952
#define SB_ALGORITHM_AEAD_CHACHA20_POLY1305 	29953
#define SB_ALGORITHM_UNKNOWN 	32767
#define SB_ALG_CLASS_DATA_ENCRYPT 	24576
#define SB_ALG_TYPE_BLOCK 	1536
#define SB_ALG_TYPE_STREAM 	2048
#define SB_ALG_SID_DES 	1
#define SB_ALG_SID_3DES 	3
#define SB_ALG_SID_RC2 	2
#define SB_ALG_SID_RC4 	1
#define SB_CALG_DES 	26113
#define SB_CALG_3DES 	26115
#define SB_CALG_RC2 	26114
#define SB_CALG_RC4 	26625
#define SB_EC_FLD_TYPE_BASE 	24576
#define SB_EC_FLD_TYPE_UNKNOWN 	24576
#define SB_EC_FLD_TYPE_FP 	24577
#define SB_EC_FLD_TYPE_F2MP 	24578
#define SB_EC_FLD_TYPE_F2MN 	24579
#define SB_EC_FLD_BASE 	24832
#define SB_EC_FLD_FIRST 	24832
#define SB_EC_FLD_CUSTOM 	24832
#define SB_EC_FLD_NIST_P192S 	24833
#define SB_EC_FLD_NIST_P224S 	24834
#define SB_EC_FLD_NIST_P256S 	24835
#define SB_EC_FLD_NIST_P384 	24836
#define SB_EC_FLD_NIST_P521 	24837
#define SB_EC_FLD_NIST_B163 	24838
#define SB_EC_FLD_NIST_B233 	24839
#define SB_EC_FLD_NIST_B283 	24840
#define SB_EC_FLD_NIST_B409 	24841
#define SB_EC_FLD_NIST_B571 	24842
#define SB_EC_FLD_LAST 	24842
#define SB_ECDSA_WRAP_SHIFT 	0
#define SB_ECDSA_WRAP_MOD_N 	1
#define SB_EC_BASE 	25088
#define SB_EC_FIRST 	25088
#define SB_EC_CUSTOM 	25088
#define SB_EC_SECP112R1 	25089
#define SB_EC_SECP112R2 	25090
#define SB_EC_SECP128R1 	25091
#define SB_EC_SECP128R2 	25092
#define SB_EC_SECP160K1 	25093
#define SB_EC_SECP160R1 	25094
#define SB_EC_SECP160R2 	25095
#define SB_EC_SECP192K1 	25096
#define SB_EC_SECP192R1 	25097
#define SB_EC_SECP224K1 	25098
#define SB_EC_SECP224R1 	25099
#define SB_EC_SECP256K1 	25100
#define SB_EC_SECP256R1 	25101
#define SB_EC_SECP384R1 	25102
#define SB_EC_SECP521R1 	25103
#define SB_EC_SECT113R1 	25104
#define SB_EC_SECT113R2 	25105
#define SB_EC_SECT131R1 	25106
#define SB_EC_SECT131R2 	25107
#define SB_EC_SECT163K1 	25108
#define SB_EC_SECT163R1 	25109
#define SB_EC_SECT163R2 	25110
#define SB_EC_SECT193R1 	25111
#define SB_EC_SECT193R2 	25112
#define SB_EC_SECT233K1 	25113
#define SB_EC_SECT233R1 	25114
#define SB_EC_SECT239K1 	25115
#define SB_EC_SECT283K1 	25116
#define SB_EC_SECT283R1 	25117
#define SB_EC_SECT409K1 	25118
#define SB_EC_SECT409R1 	25119
#define SB_EC_SECT571K1 	25120
#define SB_EC_SECT571R1 	25121
#define SB_EC_PRIME192V1 	25097
#define SB_EC_PRIME192V2 	25122
#define SB_EC_PRIME192V3 	25123
#define SB_EC_PRIME239V1 	25124
#define SB_EC_PRIME239V2 	25125
#define SB_EC_PRIME239V3 	25126
#define SB_EC_PRIME256V1 	25101
#define SB_EC_C2PNB163V1 	25127
#define SB_EC_C2PNB163V2 	25128
#define SB_EC_C2PNB163V3 	25129
#define SB_EC_C2PNB176W1 	25130
#define SB_EC_C2TNB191V1 	25131
#define SB_EC_C2TNB191V2 	25132
#define SB_EC_C2TNB191V3 	25133
#define SB_EC_C2ONB191V4 	25134
#define SB_EC_C2ONB191V5 	25135
#define SB_EC_C2PNB208W1 	25136
#define SB_EC_C2TNB239V1 	25137
#define SB_EC_C2TNB239V2 	25138
#define SB_EC_C2TNB239V3 	25139
#define SB_EC_C2ONB239V4 	25140
#define SB_EC_C2ONB239V5 	25141
#define SB_EC_C2PNB272W1 	25142
#define SB_EC_C2PNB304W1 	25143
#define SB_EC_C2TNB359V1 	25144
#define SB_EC_C2PNB368W1 	25145
#define SB_EC_C2TNB431R1 	25146
#define SB_EC_NIST_P192 	25097
#define SB_EC_NIST_P224 	25099
#define SB_EC_NIST_P256 	25101
#define SB_EC_NIST_P384 	25102
#define SB_EC_NIST_P521 	25103
#define SB_EC_NIST_B163 	25110
#define SB_EC_NIST_B233 	25114
#define SB_EC_NIST_B283 	25117
#define SB_EC_NIST_B409 	25119
#define SB_EC_NIST_B571 	25121
#define SB_EC_NIST_K163 	25108
#define SB_EC_NIST_K233 	25113
#define SB_EC_NIST_K283 	25116
#define SB_EC_NIST_K409 	25118
#define SB_EC_NIST_K571 	25120
#define SB_EC_GOST_CP_TEST 	25147
#define SB_EC_GOST_CP_A 	25148
#define SB_EC_GOST_CP_B 	25149
#define SB_EC_GOST_CP_C 	25150
#define SB_EC_GOST_CP_XCHA 	25151
#define SB_EC_GOST_CP_XCHB 	25152
#define SB_EC_BRAINPOOLP160R1 	25153
#define SB_EC_BRAINPOOLP160T1 	25154
#define SB_EC_BRAINPOOLP192R1 	25155
#define SB_EC_BRAINPOOLP192T1 	25156
#define SB_EC_BRAINPOOLP224R1 	25157
#define SB_EC_BRAINPOOLP224T1 	25158
#define SB_EC_BRAINPOOLP256R1 	25159
#define SB_EC_BRAINPOOLP256T1 	25160
#define SB_EC_BRAINPOOLP320R1 	25161
#define SB_EC_BRAINPOOLP320T1 	25162
#define SB_EC_BRAINPOOLP384R1 	25163
#define SB_EC_BRAINPOOLP384T1 	25164
#define SB_EC_BRAINPOOLP512R1 	25165
#define SB_EC_BRAINPOOLP512T1 	25166
#define SB_EC_CURVE25519 	25167
#define SB_EC_LAST 	25167
#define SB_GOST_PARAM_BASE 	25344
#define SB_GOST_PARAM_NONE 	25344
#define SB_GOST_PARAM_CUSTOM 	25345
#define SB_GOST_28147_1989_PARAM_CP_TEST 	25346
#define SB_GOST_28147_1989_PARAM_CP_A 	25347
#define SB_GOST_28147_1989_PARAM_CP_B 	25348
#define SB_GOST_28147_1989_PARAM_CP_C 	25349
#define SB_GOST_28147_1989_PARAM_CP_D 	25350
#define SB_GOST_28147_1989_PARAM_CP_OSCAR_11 	25351
#define SB_GOST_28147_1989_PARAM_CP_OSCAR_10 	25352
#define SB_GOST_28147_1989_PARAM_CP_RIC_1 	25353
#define SB_GOST_R3411_1994_PARAM_CP_TEST 	25354
#define SB_GOST_R3411_1994_PARAM_CP 	25355
#define SB_GOST_R3410_1994_PARAM_CP_TEST 	25356
#define SB_GOST_R3410_1994_PARAM_CP_A 	25357
#define SB_GOST_R3410_1994_PARAM_CP_B 	25358
#define SB_GOST_R3410_1994_PARAM_CP_C 	25359
#define SB_GOST_R3410_1994_PARAM_CP_D 	25360
#define SB_GOST_R3410_1994_PARAM_CP_XCHA 	25361
#define SB_GOST_R3410_1994_PARAM_CP_XCHB 	25362
#define SB_GOST_R3410_1994_PARAM_CP_XCHC 	25363
#define SB_LowerAlphabet 	"0123456789abcdef"
#define SB_UpperAlphabet 	"0123456789ABCDEF"
#define SB_SAddressNotSet 	"Address property is not set"
#define SB_SConnAlreadyEstablished 	"Connection already established"
#define SB_SConnNotPresent 	"Connection not present"
#define SB_SConnLost 	"Connection lost"
#define SB_SConnTimeout 	"Connection timeout"
#define SB_SConnFailed 	"Connection failed due to error (%d)"
#define SB_SConnError 	"Connection error (%d)"
#define SB_OID_RC4 	"*\x86""H\x86""\xF7""\r\x03""\x04"
#define SB_OID_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x01"
#define SB_OID_EA_RSA 	"U\b\x01""\x01"
#define SB_OID_RSAPSS 	"*\x86""H\x86""\xF7""\r\x01""\x01""\n"
#define SB_OID_RSAOAEP 	"*\x86""H\x86""\xF7""\r\x01""\x01""\a"
#define SB_OID_DSA 	"*\x86""H\xCE""8\x04""\x01"
#define SB_OID_DSA_SHA1 	"*\x86""H\xCE""8\x04""\x03"
#define SB_OID_DSA_SHA224 	"`\x86""H\x01""e\x03""\x04""\x03""\x01"
#define SB_OID_DSA_SHA256 	"`\x86""H\x01""e\x03""\x04""\x03""\x02"
#define SB_OID_DSA_ALT 	"+\x0E""\x03""\x02""\f"
#define SB_OID_DSA_SHA1_ALT 	"+\x0E""\x03""\x02""\r"
#define SB_OID_DH 	"*\x86""H\xCE"">\x02""\x01"
#define SB_OID_DES_EDE3_CBC 	"*\x86""H\x86""\xF7""\r\x03""\a"
#define SBConstants_SB_OID_PKCS7_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x01"
#define SB_OID_RC2_CBC 	"*\x86""H\x86""\xF7""\r\x03""\x02"
#define SB_OID_DES_CBC 	"+\x0E""\x03""\x02""\a"
#define SB_OID_SHA1_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x05"
#define SB_OID_SHA1_RSAENCRYPTION2 	"+\x0E""\x03""\x02""\x1D"
#define SB_OID_SHA224_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x0E"
#define SB_OID_SHA256_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\v"
#define SB_OID_SHA384_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\f"
#define SB_OID_SHA512_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\r"
#define SB_OID_RSASIGNATURE_RIPEMD160 	"+$\x03""\x03""\x01""\x02"
#define SB_OID_TSTINFO 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x01""\x04"
#define SB_OID_AES128_CBC 	"`\x86""H\x01""e\x03""\x04""\x01""\x02"
#define SB_OID_AES192_CBC 	"`\x86""H\x01""e\x03""\x04""\x01""\x16"
#define SB_OID_AES256_CBC 	"`\x86""H\x01""e\x03""\x04""\x01""*"
#define SB_OID_SERPENT128_CBC 	"+\x06""\x01""\x04""\x01""\xDA""G\r\x02""\x02"
#define SB_OID_SERPENT192_CBC 	"+\x06""\x01""\x04""\x01""\xDA""G\r\x02""\x16"
#define SB_OID_SERPENT256_CBC 	"+\x06""\x01""\x04""\x01""\xDA""G\r\x02""*"
#define SB_OID_CAST5_CBC 	"*\x86""H\x86""\xF6""}\aB\n"
#define SB_OID_BLOWFISH_CBC 	"+\x06""\x01""\x04""\x01""\x97""U\x01""\x01""\x02"
#define SB_OID_CAMELLIA128_CBC 	"*\x83""\b\x8C""\x9A""K=\x01""\x01""\x01""\x02"
#define SB_OID_CAMELLIA192_CBC 	"*\x83""\b\x8C""\x9A""K=\x01""\x01""\x01""\x03"
#define SB_OID_CAMELLIA256_CBC 	"*\x83""\b\x8C""\x9A""K=\x01""\x01""\x01""\x04"
#define SB_OID_SEED 	"*\x83""\x1A""\x8C""\x9A""D\x01""\x04""\x05""\x00"
#define SB_OID_RABBIT 	'\x00'
#define SB_OID_IDENTITY 	"identity@eldos.com"
#define SB_OID_IDENTITY_ELDOS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x03""\x01"
#define SB_OID_TWOFISH128_ELDOS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x03""\x05"
#define SB_OID_TWOFISH256_ELDOS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x03""\x06"
#define SB_OID_TWOFISH192_ELDOS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x03""\a"
#define SB_OID_CHACHA20_ELDOS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x03""\b"
#define SB_OID_RSASIGNATURE_RIPEMD160_ISO9796 	"+$\x03""\x04""\x03""\x02""\x02"
#define SB_OID_WHIRLPOOL_RSAENCRYPTION_ELDOS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x02""\x01"
#define SB_OID_MGF1 	"*\x86""H\x86""\xF7""\r\x01""\x01""\b"
#define SB_OID_MGF1_SHA1 	"mgf1-sha1@eldos.com"
#define SB_OID_MGF1_SHA224 	"mgf1-sha224@eldos.com"
#define SB_OID_MGF1_SHA256 	"mgf1-sha256@eldos.com"
#define SB_OID_MGF1_SHA384 	"mgf1-sha384@eldos.com"
#define SB_OID_MGF1_SHA512 	"mgf1-sha512@eldos.com"
#define SB_OID_MGF1_RIPEMD160 	"mgf1-ripemd160@eldos.com"
#define SB_OID_MGF1_WHIRLPOOL 	"mgf1-whirlpool@eldos.com"
#define SB_OID_OAEP_SRC_SPECIFIED 	"*\x86""H\x86""\xF7""\r\x01""\x01""\t"
#define SB_OID_PBE_MD2_DES 	"*\x86""H\x86""\xF7""\r\x01""\x05""\x01"
#define SB_OID_PBE_MD2_RC2 	"*\x86""H\x86""\xF7""\r\x01""\x05""\x04"
#define SB_OID_PBE_MD5_DES 	"*\x86""H\x86""\xF7""\r\x01""\x05""\x03"
#define SB_OID_PBE_MD5_RC2 	"*\x86""H\x86""\xF7""\r\x01""\x05""\x03"
#define SB_OID_PBE_SHA1_DES 	"*\x86""H\x86""\xF7""\r\x01""\x05""\n"
#define SB_OID_PBE_SHA1_RC2 	"*\x86""H\x86""\xF7""\r\x01""\x05""\v"
#define SB_OID_PBES2 	"*\x86""H\x86""\xF7""\r\x01""\x05""\r"
#define SB_OID_PBKDF2 	"*\x86""H\x86""\xF7""\r\x01""\x05""\f"
#define SB_OID_PBMAC1 	"*\x86""H\x86""\xF7""\r\x01""\x05""\x0E"
#define SB_OID_PBE_SHA1_RC4_128 	"*\x86""H\x86""\xF7""\r\x01""\f\x01""\x01"
#define SB_OID_PBE_SHA1_RC4_40 	"*\x86""H\x86""\xF7""\r\x01""\f\x01""\x02"
#define SB_OID_PBE_SHA1_3DES 	"*\x86""H\x86""\xF7""\r\x01""\f\x01""\x03"
#define SB_OID_PBE_SHA1_RC2_128 	"*\x86""H\x86""\xF7""\r\x01""\f\x01""\x05"
#define SB_OID_PBE_SHA1_RC2_40 	"*\x86""H\x86""\xF7""\r\x01""\f\x01""\x06"
#define SB_OID_MD2_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x02"
#define SB_OID_MD4_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x03"
#define SB_OID_MD5_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x04"
#define SB_OID_SHA1_RSA 	"+\x0E""\x03""\x02""\x1D"
#define SB_OID_SHA1_DSA 	"*\x86""H\xCE""8\x04""\x03"
#define SB_OID_PKCS15 	"*\x86""H\x86""\xF7""\r\x01""\x0F""\x03""\x01"
#define SB_OID_PWRI_KEK 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x03""\t"
#define SB_OID_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x01"
#define SB_OID_MD2 	"*\x86""H\x86""\xF7""\r\x02""\x02"
#define SB_OID_MD4 	"*\x86""H\x86""\xF7""\r\x02""\x04"
#define SB_OID_MD5 	"*\x86""H\x86""\xF7""\r\x02""\x05"
#define SB_OID_SHA1 	"+\x0E""\x03""\x02""\x1A"
#define SB_OID_SHA224 	"`\x86""H\x01""e\x03""\x04""\x02""\x04"
#define SB_OID_SHA256 	"`\x86""H\x01""e\x03""\x04""\x02""\x01"
#define SB_OID_SHA384 	"`\x86""H\x01""e\x03""\x04""\x02""\x02"
#define SB_OID_SHA512 	"`\x86""H\x01""e\x03""\x04""\x02""\x03"
#define SB_OID_RIPEMD160 	"+$\x03""\x02""\x01"
#define SB_OID_SSL3 	"ssl-hash@eldos.com"
#define SB_OID_WHIRLPOOL 	"(\xCF""\x06""\x03""\x00""7"
#define SB_OID_POLY1305_ELDOS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x04""\x01"
#define SB_OID_HMACSHA1 	"+\x06""\x01""\x05""\x05""\b\x01""\x02"
#define SB_OID_HMACSHA1_PKCS 	"*\x86""H\x86""\xF7""\r\x02""\a"
#define SB_OID_HMACSHA224 	"+\x06""\x01""\x05""\x05""\b\x01""\b"
#define SB_OID_HMACSHA256 	"+\x06""\x01""\x05""\x05""\b\x01""\t"
#define SB_OID_HMACSHA384 	"+\x06""\x01""\x05""\x05""\b\x01""\n"
#define SB_OID_HMACSHA512 	"+\x06""\x01""\x05""\x05""\b\x01""\v"
#define SB_OID_RSA_HMACSHA1 	"*\x86""H\x86""\xF7""\r\x02""\a"
#define SB_OID_UMAC32 	"umac32@eldos.com"
#define SB_OID_UMAC64 	"umac64@eldos.com"
#define SB_OID_UMAC96 	"umac96@eldos.com"
#define SB_OID_UMAC128 	"umac128@eldos.com"
#define SB_OID_CONTENT_TYPE 	"*\x86""H\x86""\xF7""\r\x01""\t\x03"
#define SB_OID_MESSAGE_DIGEST 	"*\x86""H\x86""\xF7""\r\x01""\t\x04"
#define SB_OID_SIGNING_TIME 	"*\x86""H\x86""\xF7""\r\x01""\t\x05"
#define SB_OID_COUNTER_SIGNATURE 	"*\x86""H\x86""\xF7""\r\x01""\t\x06"
#define SB_OID_SMIME_CAPABILITIES 	"*\x86""H\x86""\xF7""\r\x01""\t\x0F"
#define SB_OID_TIMESTAMP_TOKEN 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x0E"
#define SB_OID_SIGNING_CERTIFICATE 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\f"
#define SB_OID_SIGNING_CERTIFICATEV2 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""/"
#define SB_OID_CONTENT_HINTS 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x04"
#define SB_OID_MIME_TYPE 	"\x04""\x00""\x8D""E\x02""\x01"
#define SB_OID_CONTENT_IDENTIFIER 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\a"
#define SB_OID_CONTENT_REFERENCE 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\n"
#define SB_OID_SIGNATURE_POLICY 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x0F"
#define SB_OID_COMMITMENT_TYPE 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x10"
#define SB_OID_SIGNER_LOCATION 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x11"
#define SB_OID_SIGNER_ATTRIBUTES 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x12"
#define SB_OID_SIGNER_ATTRIBUTESV2 	"\x04""\x00""\x81""\x95""2\x01""\x01"
#define SB_OID_CONTENT_TIMESTAMP 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x14"
#define SB_OID_CERTIFICATE_REFS 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x15"
#define SB_OID_REVOCATION_REFS 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x16"
#define SB_OID_CERTIFICATE_VALUES 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x17"
#define SB_OID_REVOCATION_VALUES 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x18"
#define SB_OID_ESCTIMESTAMP 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x19"
#define SB_OID_CERTCRLTIMESTAMP 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x1A"
#define SB_OID_ARCHIVETIMESTAMP 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""\x1B"
#define SB_OID_ARCHIVETIMESTAMP2 	"*\x86""H\x86""\xF7""\r\x01""\t\x10""\x02""0"
#define SB_OID_ARCHIVETIMESTAMP3 	"\x04""\x00""\x8D""E\x02""\x04"
#define SB_OID_ATSHASHINDEX 	"\x04""\x00""\x8D""E\x02""\x05"
#define SB_OID_SIGNATURE_POLICY_STORE 	"\x04""\x00""\x81""\x95""2\x01""\x03"
#define SB_OID_ATSHASHINDEXV2 	"\x04""\x00""\x81""\x95""2\x01""\x04"
#define SB_OID_SPC_INDIRECT_DATA 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x04"
#define SB_OID_SPC_SP_AGENCY_INFO 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\n"
#define SB_OID_SPC_STATEMENT_TYPE_OBJID 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\n"
#define SB_OID_SPC_STATEMENT_TYPE 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\v"
#define SB_OID_SPC_SP_OPUS_INFO 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\f"
#define SB_OID_SPC_PE_IMAGE_DATA 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x0F"
#define SB_OID_SPC_MINIMAL_CRITERIA 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x1A"
#define SB_OID_SPC_FINANCIAL_CRITERIA 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x1B"
#define SB_OID_SPC_LINK 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x1C"
#define SB_OID_SPC_HASH_INFO 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x1D"
#define SB_OID_SPC_SIPINFO 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x1E"
#define SB_OID_SPC_CERT_EXTENSIONS 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x0E"
#define SB_OID_SPC_RAW_FILE_DATA 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x12"
#define SB_OID_SPC_STRUCTURED_STORAGE_DATA 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x13"
#define SB_OID_SPC_JAVA_CLASS_DATA 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x14"
#define SB_OID_SPC_INDIVIDUAL_SP_KEY_PURPOSE 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x15"
#define SB_OID_SPC_COMMERCIAL_SP_KEY_PURPOSE 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x16"
#define SB_OID_SPC_CAB_DATA 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x19"
#define SB_OID_QT_CPS 	"+\x06""\x01""\x05""\x05""\a\x02""\x01"
#define SB_OID_QT_UNOTICE 	"+\x06""\x01""\x05""\x05""\a\x02""\x02"
#define SB_OID_SERVER_AUTH 	"+\x06""\x01""\x05""\x05""\a\x03""\x01"
#define SB_OID_CLIENT_AUTH 	"+\x06""\x01""\x05""\x05""\a\x03""\x02"
#define SB_OID_CODE_SIGNING 	"+\x06""\x01""\x05""\x05""\a\x03""\x03"
#define SB_OID_EMAIL_PROT 	"+\x06""\x01""\x05""\x05""\a\x03""\x04"
#define SB_OID_TIME_STAMPING 	"+\x06""\x01""\x05""\x05""\a\x03""\b"
#define SB_OID_OCSP_SIGNING 	"+\x06""\x01""\x05""\x05""\a\x03""\t"
#define SB_OID_ACCESS_METHOD_OCSP 	"+\x06""\x01""\x05""\x05""\a0\x01"
#define SB_OID_ACCESS_METHOD_CAISSUER 	"+\x06""\x01""\x05""\x05""\a0\x02"
#define SB_OID_UNSTRUCTURED_NAME 	"*\x86""H\x86""\xF7""\r\x01""\t\x02"
#define SB_OID_CERT_EXTENSIONS 	"*\x86""H\x86""\xF7""\r\x01""\t\x0E"
#define SB_OID_CERT_EXTENSIONS_MS 	"+\x06""\x01""\x04""\x01""\x82""7\x02""\x01""\x0E"
#define SB_OID_GOST_28147_1989 	"*\x85""\x03""\x02""\x02""\x15"
#define SB_OID_GOST_28147_1989_MAC 	"*\x85""\x03""\x02""\x02""\x16"
#define SB_OID_GOST_R3410_2001 	"*\x85""\x03""\x02""\x02""\x13"
#define SB_OID_GOST_R3410_1994 	"*\x85""\x03""\x02""\x02""\x14"
#define SB_OID_GOST_R3410_1994_DH 	"*\x85""\x03""\x02""\x02""c"
#define SB_OID_GOST_R3411_1994_WITH_GOST_R3410_2001 	"*\x85""\x03""\x02""\x02""\x03"
#define SB_OID_GOST_R3411_1994_WITH_GOST_R3410_1994 	"*\x85""\x03""\x02""\x02""\x04"
#define SB_OID_GOST_R3411_1994 	"*\x85""\x03""\x02""\x02""\t"
#define SB_OID_GOST_R3411_1994_HMAC 	"*\x85""\x03""\x02""\x02""\n"
#define SB_OID_GOST_28147_1989_PARAM_CP_TEST 	"*\x85""\x03""\x02""\x02""\x1F""\x00"
#define SB_OID_GOST_28147_1989_PARAM_CP_A 	"*\x85""\x03""\x02""\x02""\x1F""\x01"
#define SB_OID_GOST_28147_1989_PARAM_CP_B 	"*\x85""\x03""\x02""\x02""\x1F""\x02"
#define SB_OID_GOST_28147_1989_PARAM_CP_C 	"*\x85""\x03""\x02""\x02""\x1F""\x03"
#define SB_OID_GOST_28147_1989_PARAM_CP_D 	"*\x85""\x03""\x02""\x02""\x1F""\x04"
#define SB_OID_GOST_28147_1989_PARAM_CP_OSCAR_11 	"*\x85""\x03""\x02""\x02""\x1F""\x05"
#define SB_OID_GOST_28147_1989_PARAM_CP_OSCAR_10 	"*\x85""\x03""\x02""\x02""\x1F""\x06"
#define SB_OID_GOST_28147_1989_PARAM_CP_RIC_1 	"*\x85""\x03""\x02""\x02""\x1F""\a"
#define SB_OID_GOST_R3411_1994_PARAM_CP_TEST 	"*\x85""\x03""\x02""\x02""\x1E""\x00"
#define SB_OID_GOST_R3411_1994_PARAM_CP 	"*\x85""\x03""\x02""\x02""\x1E""\x01"
#define SB_OID_GOST_R3410_1994_PARAM_CP_TEST 	"*\x85""\x03""\x02""\x02"" \x00"
#define SB_OID_GOST_R3410_1994_PARAM_CP_A 	"*\x85""\x03""\x02""\x02"" \x02"
#define SB_OID_GOST_R3410_1994_PARAM_CP_B 	"*\x85""\x03""\x02""\x02"" \x03"
#define SB_OID_GOST_R3410_1994_PARAM_CP_C 	"*\x85""\x03""\x02""\x02"" \x04"
#define SB_OID_GOST_R3410_1994_PARAM_CP_D 	"*\x85""\x03""\x02""\x02"" \x05"
#define SB_OID_GOST_R3410_1994_PARAM_CP_XCHA 	"*\x85""\x03""\x02""\x02"" \x01"
#define SB_OID_GOST_R3410_1994_PARAM_CP_XCHB 	"*\x85""\x03""\x02""\x02"" \x02"
#define SB_OID_GOST_R3410_1994_PARAM_CP_XCHC 	"*\x85""\x03""\x02""\x02"" \x03"
#define SB_OID_FLD_CUSTOM 	"fld-custom@eldos.com"
#define SB_OID_FLD_TYPE_FP 	"*\x86""H\xCE""=\x01""\x01"
#define SB_OID_FLD_TYPE_F2M 	"*\x86""H\xCE""=\x01""\x02"
#define SB_OID_FLD_BASIS_N 	"*\x86""H\xCE""=\x01""\x02""\x03""\x01"
#define SB_OID_FLD_BASIS_T 	"*\x86""H\xCE""=\x01""\x02""\x03""\x02"
#define SB_OID_FLD_BASIS_P 	"*\x86""H\xCE""=\x01""\x02""\x03""\x03"
#define SB_OID_EC_KEY 	"*\x86""H\xCE""=\x02""\x01"
#define SB_OID_ECDH 	"+\x81""\x04""\x01""\f"
#define SB_OID_ECMQV 	"+\x81""\x04""\x01""\r"
#define SB_OID_ECDSA_SHA1 	"*\x86""H\xCE""=\x04""\x01"
#define SB_OID_ECDSA_RECOMMENDED 	"*\x86""H\xCE""=\x04""\x02"
#define SB_OID_ECDSA_SHA224 	"*\x86""H\xCE""=\x04""\x03""\x01"
#define SB_OID_ECDSA_SHA256 	"*\x86""H\xCE""=\x04""\x03""\x02"
#define SB_OID_ECDSA_SHA384 	"*\x86""H\xCE""=\x04""\x03""\x03"
#define SB_OID_ECDSA_SHA512 	"*\x86""H\xCE""=\x04""\x03""\x04"
#define SB_OID_ECDSA_SPECIFIED 	"*\x86""H\xCE""=\x04""\x03"
#define SB_OID_ECDSA_PLAIN_SHA1 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x01"
#define SB_OID_ECDSA_PLAIN_SHA224 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x02"
#define SB_OID_ECDSA_PLAIN_SHA256 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x03"
#define SB_OID_ECDSA_PLAIN_SHA384 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x04"
#define SB_OID_ECDSA_PLAIN_SHA512 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x05"
#define SB_OID_ECDSA_PLAIN_RIPEMD160 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x06"
#define SB_OID_EC_CUSTOM 	"ec-custom@eldos.com"
#define SB_OID_EC_C2PNB163V1 	"*\x86""H\xCE""=\x03""\x00""\x01"
#define SB_OID_EC_C2PNB163V2 	"*\x86""H\xCE""=\x03""\x00""\x02"
#define SB_OID_EC_C2PNB163V3 	"*\x86""H\xCE""=\x03""\x00""\x03"
#define SB_OID_EC_C2PNB176W1 	"*\x86""H\xCE""=\x03""\x00""\x04"
#define SB_OID_EC_C2TNB191V1 	"*\x86""H\xCE""=\x03""\x00""\x05"
#define SB_OID_EC_C2TNB191V2 	"*\x86""H\xCE""=\x03""\x00""\x06"
#define SB_OID_EC_C2TNB191V3 	"*\x86""H\xCE""=\x03""\x00""\a"
#define SB_OID_EC_C2ONB191V4 	"*\x86""H\xCE""=\x03""\x00""\b"
#define SB_OID_EC_C2ONB191V5 	"*\x86""H\xCE""=\x03""\x00""\t"
#define SB_OID_EC_C2PNB208W1 	"*\x86""H\xCE""=\x03""\x00""\n"
#define SB_OID_EC_C2TNB239V1 	"*\x86""H\xCE""=\x03""\x00""\v"
#define SB_OID_EC_C2TNB239V2 	"*\x86""H\xCE""=\x03""\x00""\f"
#define SB_OID_EC_C2TNB239V3 	"*\x86""H\xCE""=\x03""\x00""\r"
#define SB_OID_EC_C2ONB239V4 	"*\x86""H\xCE""=\x03""\x00""\x0E"
#define SB_OID_EC_C2ONB239V5 	"*\x86""H\xCE""=\x03""\x00""\x0F"
#define SB_OID_EC_C2PNB272W1 	"*\x86""H\xCE""=\x03""\x00""\x10"
#define SB_OID_EC_C2PNB304W1 	"*\x86""H\xCE""=\x03""\x00""\x11"
#define SB_OID_EC_C2TNB359V1 	"*\x86""H\xCE""=\x03""\x00""\x12"
#define SB_OID_EC_C2PNB368W1 	"*\x86""H\xCE""=\x03""\x00""\x13"
#define SB_OID_EC_C2TNB431R1 	"*\x86""H\xCE""=\x03""\x00""\x14"
#define SB_OID_EC_PRIME192V1 	"*\x86""H\xCE""=\x03""\x01""\x01"
#define SB_OID_EC_PRIME192V2 	"*\x86""H\xCE""=\x03""\x01""\x02"
#define SB_OID_EC_PRIME192V3 	"*\x86""H\xCE""=\x03""\x01""\x03"
#define SB_OID_EC_PRIME239V1 	"*\x86""H\xCE""=\x03""\x01""\x04"
#define SB_OID_EC_PRIME239V2 	"*\x86""H\xCE""=\x03""\x01""\x05"
#define SB_OID_EC_PRIME239V3 	"*\x86""H\xCE""=\x03""\x01""\x06"
#define SB_OID_EC_PRIME256V1 	"*\x86""H\xCE""=\x03""\x01""\a"
#define SB_OID_EC_SECP112R1 	"+\x81""\x04""\x00""\x06"
#define SB_OID_EC_SECP112R2 	"+\x81""\x04""\x00""\a"
#define SB_OID_EC_SECP128R1 	"+\x81""\x04""\x00""\x1C"
#define SB_OID_EC_SECP128R2 	"+\x81""\x04""\x00""\x1D"
#define SB_OID_EC_SECP160K1 	"+\x81""\x04""\x00""\t"
#define SB_OID_EC_SECP160R1 	"+\x81""\x04""\x00""\b"
#define SB_OID_EC_SECP160R2 	"+\x81""\x04""\x00""\x1E"
#define SB_OID_EC_SECP192K1 	"+\x81""\x04""\x00""\x1F"
#define SB_OID_EC_SECP192R1 	"*\x86""H\xCE""=\x03""\x01""\x01"
#define SB_OID_EC_SECP224K1 	"+\x81""\x04""\x00"" "
#define SB_OID_EC_SECP224R1 	"+\x81""\x04""\x00""!"
#define SB_OID_EC_SECP256K1 	"+\x81""\x04""\x00""\n"
#define SB_OID_EC_SECP256R1 	"*\x86""H\xCE""=\x03""\x01""\a"
#define SB_OID_EC_SECP384R1 	"+\x81""\x04""\x00""\""
#define SB_OID_EC_SECP521R1 	"+\x81""\x04""\x00""#"
#define SB_OID_EC_SECT113R1 	"+\x81""\x04""\x00""\x04"
#define SB_OID_EC_SECT113R2 	"+\x81""\x04""\x00""\x05"
#define SB_OID_EC_SECT131R1 	"+\x81""\x04""\x00""\x16"
#define SB_OID_EC_SECT131R2 	"+\x81""\x04""\x00""\x17"
#define SB_OID_EC_SECT163K1 	"+\x81""\x04""\x00""\x01"
#define SB_OID_EC_SECT163R1 	"+\x81""\x04""\x00""\x02"
#define SB_OID_EC_SECT163R2 	"+\x81""\x04""\x00""\x0F"
#define SB_OID_EC_SECT193R1 	"+\x81""\x04""\x00""\x18"
#define SB_OID_EC_SECT193R2 	"+\x81""\x04""\x00""\x19"
#define SB_OID_EC_SECT233K1 	"+\x81""\x04""\x00""\x1A"
#define SB_OID_EC_SECT233R1 	"+\x81""\x04""\x00""\x1B"
#define SB_OID_EC_SECT239K1 	"+\x81""\x04""\x00""\x03"
#define SB_OID_EC_SECT283K1 	"+\x81""\x04""\x00""\x10"
#define SB_OID_EC_SECT283R1 	"+\x81""\x04""\x00""\x11"
#define SB_OID_EC_SECT409K1 	"+\x81""\x04""\x00""$"
#define SB_OID_EC_SECT409R1 	"+\x81""\x04""\x00""%"
#define SB_OID_EC_SECT571K1 	"+\x81""\x04""\x00""&"
#define SB_OID_EC_SECT571R1 	"+\x81""\x04""\x00""\'"
#define SB_OID_EC_GOST_CP_TEST 	"*\x85""\x03""\x02""\x02""#\x00"
#define SB_OID_EC_GOST_CP_A 	"*\x85""\x03""\x02""\x02""#\x01"
#define SB_OID_EC_GOST_CP_B 	"*\x85""\x03""\x02""\x02""#\x02"
#define SB_OID_EC_GOST_CP_C 	"*\x85""\x03""\x02""\x02""#\x03"
#define SB_OID_EC_GOST_CP_XCHA 	"*\x85""\x03""\x02""\x02""$\x00"
#define SB_OID_EC_GOST_CP_XCHB 	"*\x85""\x03""\x02""\x02""$\x01"
#define SB_OID_EC_BRAINPOOLP160R1 	"+$\x03""\x03""\x02""\b\x01""\x01""\x01"
#define SB_OID_EC_BRAINPOOLP160T1 	"+$\x03""\x03""\x02""\b\x01""\x01""\x02"
#define SB_OID_EC_BRAINPOOLP192R1 	"+$\x03""\x03""\x02""\b\x01""\x01""\x03"
#define SB_OID_EC_BRAINPOOLP192T1 	"+$\x03""\x03""\x02""\b\x01""\x01""\x04"
#define SB_OID_EC_BRAINPOOLP224R1 	"+$\x03""\x03""\x02""\b\x01""\x01""\x05"
#define SB_OID_EC_BRAINPOOLP224T1 	"+$\x03""\x03""\x02""\b\x01""\x01""\x06"
#define SB_OID_EC_BRAINPOOLP256R1 	"+$\x03""\x03""\x02""\b\x01""\x01""\a"
#define SB_OID_EC_BRAINPOOLP256T1 	"+$\x03""\x03""\x02""\b\x01""\x01""\b"
#define SB_OID_EC_BRAINPOOLP320R1 	"+$\x03""\x03""\x02""\b\x01""\x01""\t"
#define SB_OID_EC_BRAINPOOLP320T1 	"+$\x03""\x03""\x02""\b\x01""\x01""\n"
#define SB_OID_EC_BRAINPOOLP384R1 	"+$\x03""\x03""\x02""\b\x01""\x01""\v"
#define SB_OID_EC_BRAINPOOLP384T1 	"+$\x03""\x03""\x02""\b\x01""\x01""\f"
#define SB_OID_EC_BRAINPOOLP512R1 	"+$\x03""\x03""\x02""\b\x01""\x01""\r"
#define SB_OID_EC_BRAINPOOLP512T1 	"+$\x03""\x03""\x02""\b\x01""\x01""\x0E"
#define SB_OID_EC_CURVE25519 	"\x01""\x03""\x06""\x01""\x04""\x01""\x1E""\x1D""\x01""\x05""\x01"
#define SB_OID_ELDOSCORP_BASE 	"+\x06""\x01""\x04""\x01""\x82""\x90""\""
#define SB_OID_ELDOS_PKI 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x01"
#define SB_OID_ELDOS_ALGS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02"
#define SB_OID_ELDOS_DATASTORAGE 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\a"
#define SB_OID_ELDOS_ALGS_NULL 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x01"
#define SB_OID_ELDOS_ALGS_PKEY 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x02"
#define SB_OID_ELDOS_ALGS_SKEY 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x03"
#define SB_OID_ELDOS_ALGS_SKEY_AEAD 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x03""@"
#define SB_OID_ELDOS_ALGS_DGST 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x04"
#define SB_OID_ELDOS_ALGS_HMAC 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x05"
#define SB_OID_ELDOS_ALGS_COMPR 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x06"
#define SB_CERT_OID_COMMON_NAME 	"U\x04""\x03"
#define SB_CERT_OID_SURNAME 	"U\x04""\x04"
#define SB_CERT_OID_COUNTRY 	"U\x04""\x06"
#define SB_CERT_OID_LOCALITY 	"U\x04""\a"
#define SB_CERT_OID_STATE_OR_PROVINCE 	"U\x04""\b"
#define SB_CERT_OID_ORGANIZATION 	"U\x04""\n"
#define SB_CERT_OID_ORGANIZATION_UNIT 	"U\x04""\v"
#define SB_CERT_OID_TITLE 	"U\x04""\f"
#define SB_CERT_OID_NAME 	"U\x04"")"
#define SB_CERT_OID_GIVEN_NAME 	"U\x04""*"
#define SB_CERT_OID_INITIALS 	"U\x04""+"
#define SB_CERT_OID_GENERATION_QUALIFIER 	"U\x04"","
#define SB_CERT_OID_DN_QUALIFIER 	"U\x04""."
#define SB_CERT_OID_EMAIL 	"*\x86""H\x86""\xF7""\r\x01""\t\x01"
#define SB_CERT_OID_STREET_ADDRESS 	"U\x04""\t"
#define SB_CERT_OID_POSTAL_ADDRESS 	"U\x04""\x10"
#define SB_CERT_OID_POSTAL_CODE 	"U\x04""\x11"
#define SB_CERT_OID_POST_OFFICE_BOX 	"U\x04""\x12"
#define SB_CERT_OID_PHYSICAL_DELIVERY_OFFICE_NAME 	"U\x04""\x13"
#define SB_CERT_OID_TELEPHONE_NUMBER 	"U\x04""\x14"
#define SB_CERT_OID_TELEX_NUMBER 	"U\x04""\x15"
#define SB_CERT_OID_TELEX_TERMINAL_ID 	"U\x04""\x16"
#define SB_CERT_OID_FACIMILE_PHONE_NUMBER 	"U\x04""\x17"
#define SB_CERT_OID_X12_ADDRESS 	"U\x04""\x18"
#define SB_CERT_OID_INTERNATIONAL_ISDN_NUMBER 	"U\x04""\x19"
#define SB_CERT_OID_REGISTERED_ADDRESS 	"U\x04""\x1A"
#define SB_CERT_OID_DESTINATION_INDICATOR 	"U\x04""\x1B"
#define SB_CERT_OID_PREFERRED_DELIVERY_METHOD 	"U\x04""\x1C"
#define SB_CERT_OID_PRESENTATION_ADDRESS 	"U\x04""\x1D"
#define SB_CERT_OID_SUPPORTED_APPLICATION_CONTEXT 	"U\x04""\x1E"
#define SB_CERT_OID_MEMBER 	"U\x04""\x1F"
#define SB_CERT_OID_OWNER 	"U\x04"" "
#define SB_CERT_OID_ROLE_OCCUPENT 	"U\x04""!"
#define SB_CERT_OID_SEE_ALSO 	"U\x04""\""
#define SB_CERT_OID_USER_PASSWORD 	"U\x04""#"
#define SB_CERT_OID_USER_CERTIFICATE 	"U\x04""$"
#define SB_CERT_OID_CA_CERTIFICATE 	"U\x04""%"
#define SB_CERT_OID_AUTHORITY_REVOCATION_LIST 	"U\x04""&"
#define SB_CERT_OID_CERTIFICATE_REVOCATION_LIST 	"U\x04""\'"
#define SB_CERT_OID_CERTIFICATE_PAIR 	"U\x04""("
#define SB_CERT_OID_UNIQUE_IDENTIFIER 	"U\x04""-"
#define SB_CERT_OID_ENHANCED_SEARCH_GUIDE 	"U\x04""/"
#define SB_CERT_OID_OBJECT_CLASS 	"U\x04""\x00"
#define SB_CERT_OID_ALIASED_ENTRY_NAME 	"U\x04""\x01"
#define SB_CERT_OID_KNOWLEDGE_INFORMATION 	"U\x04""\x02"
#define SB_CERT_OID_SERIAL_NUMBER 	"U\x04""\x05"
#define SB_CERT_OID_DESCRIPTION 	"U\x04""\r"
#define SB_CERT_OID_SEARCH_GUIDE 	"U\x04""\x0E"
#define SB_CERT_OID_BUSINESS_CATEGORY 	"U\x04""\x0F"
#define SB_CERT_OID_PROTOCOL_INFORMATION 	"U\x04""0"
#define SB_CERT_OID_DISTINGUISHED_NAME 	"U\x04""1"
#define SB_CERT_OID_UNIQUE_MEMBER 	"U\x04""2"
#define SB_CERT_OID_HOUSE_IDENTIFIER 	"U\x04""3"
#define SB_CERT_OID_SUPPORTED_ALGORITHMS 	"U\x04""4"
#define SB_CERT_OID_DELTA_REVOCATION_LIST 	"U\x04""5"
#define SB_CERT_OID_ATTRIBUTE_CERTIFICATE 	"U\x04"":"
#define SB_CERT_OID_PSEUDONYM 	"U\x04""A"
#define SB_CERT_OID_PERMANENT_IDENTIFIER 	"+\x06""\x01""\x05""\x05""\a\x00""\x12""\b\x03"
#define SB_CERT_OID_USER_ID 	"\t\x92""&\x89""\x93""\xF2"",d\x01""\x01"
#define SB_CERT_OID_DOMAIN_COMPONENT 	"\t\x92""&\x89""\x93""\xF2"",d\x01""\x19"
#define SB_CERT_OID_CA_OCSP 	"+\x06""\x01""\x05""\x05""\a0\x01"
#define SB_CERT_OID_CA_ISSUER 	"+\x06""\x01""\x05""\x05""\a0\x02"
#define SB_CERT_OID_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x01"
#define SB_CERT_OID_RSAOAEP 	"*\x86""H\x86""\xF7""\r\x01""\x01""\a"
#define SB_CERT_OID_RSAPSS 	"*\x86""H\x86""\xF7""\r\x01""\x01""\n"
#define SB_CERT_OID_DSA 	"*\x86""H\xCE""8\x04""\x01"
#define SB_CERT_OID_DH 	"*\x86""H\xCE"">\x02""\x01"
#define SB_CERT_OID_DSA_SHA1 	"*\x86""H\xCE""8\x04""\x03"
#define SB_CERT_OID_DSA_SHA224 	"*\x86""H\xCE""8\x04""\x03"
#define SB_CERT_OID_DSA_SHA256 	"*\x86""H\xCE""8\x04""\x03"
#define SB_CERT_OID_MD2_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x02"
#define SB_CERT_OID_MD5_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x04"
#define SB_CERT_OID_SHA1_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x05"
#define SB_CERT_OID_SHA224_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\x0E"
#define SB_CERT_OID_SHA256_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\v"
#define SB_CERT_OID_SHA384_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\f"
#define SB_CERT_OID_SHA512_RSAENCRYPTION 	"*\x86""H\x86""\xF7""\r\x01""\x01""\r"
#define SB_CERT_OID_ECDSA_SHA1 	"*\x86""H\xCE""=\x04""\x01"
#define SB_CERT_OID_ECDSA_RECOMMENDED 	"*\x86""H\xCE""=\x04""\x02"
#define SB_CERT_OID_ECDSA_SHA224 	"*\x86""H\xCE""=\x04""\x03""\x01"
#define SB_CERT_OID_ECDSA_SHA256 	"*\x86""H\xCE""=\x04""\x03""\x02"
#define SB_CERT_OID_ECDSA_SHA384 	"*\x86""H\xCE""=\x04""\x03""\x03"
#define SB_CERT_OID_ECDSA_SHA512 	"*\x86""H\xCE""=\x04""\x03""\x04"
#define SB_CERT_OID_ECDSA_SPECIFIED 	"*\x86""H\xCE""=\x04""\x03"
#define SB_CERT_OID_ECDSA_PLAIN_SHA1 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x01"
#define SB_CERT_OID_ECDSA_PLAIN_SHA224 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x02"
#define SB_CERT_OID_ECDSA_PLAIN_SHA256 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x03"
#define SB_CERT_OID_ECDSA_PLAIN_SHA384 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x04"
#define SB_CERT_OID_ECDSA_PLAIN_SHA512 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x05"
#define SB_CERT_OID_ECDSA_PLAIN_RIPEMD160 	"\x04""\x00""\x00""\a\x01""\x01""\x04""\x01""\x06"
#define SB_CERT_OID_GOST_R3410_1994 	"*\x85""\x03""\x02""\x02""\x14"
#define SB_CERT_OID_GOST_R3410_2001 	"*\x85""\x03""\x02""\x02""\x13"
#define SB_CERT_OID_GOST_R3411_WITH_GOST3410_1994 	"*\x85""\x03""\x02""\x02""\x04"
#define SB_CERT_OID_GOST_R3411_WITH_GOST3410_2001 	"*\x85""\x03""\x02""\x02""\x03"
#define SB_CERT_OID_SHA1_RSA 	"+\x0E""\x03""\x02""\x1D"
#define SB_CERT_OID_SHA1_DSA 	"*\x86""H\xCE""8\x04""\x03"
#define SB_CERT_OID_SHA1 	"+\x0E""\x03""\x02""\x1A"
#define SB_CERT_OID_MD2 	"*\x86""H\x86""\xF7""\r\x02""\x02"
#define SB_CERT_OID_MD5 	"*\x86""H\x86""\xF7""\r\x02""\x05"
#define SB_CMC_OID_PKI_DATA 	"+\x06""\x01""\x05""\x05""\a\f\x02"
#define SB_CMC_OID_PKI_RESPONSE 	"+\x06""\x01""\x05""\x05""\a\f\x03"
#define SB_CMC_OID_STATUS_INFO 	"+\x06""\x01""\x05""\x05""\a\a\x01"
#define SB_CMC_OID_IDENTIFICATION 	"+\x06""\x01""\x05""\x05""\a\a\x02"
#define SB_CMC_OID_IDENTITY_PROOF 	"+\x06""\x01""\x05""\x05""\a\a\x03"
#define SB_CMC_OID_DATA_RETURN 	"+\x06""\x01""\x05""\x05""\a\a\x04"
#define SB_CMC_OID_TRANSACTION_ID 	"+\x06""\x01""\x05""\x05""\a\a\x05"
#define SB_CMC_OID_SENDER_NONCE 	"+\x06""\x01""\x05""\x05""\a\a\x06"
#define SB_CMC_OID_RECIPIENT_NONCE 	"+\x06""\x01""\x05""\x05""\a\a\a"
#define SB_CMC_OID_ADD_EXTENSIONS 	"+\x06""\x01""\x05""\x05""\a\a\b"
#define SB_CMC_OID_ENCRYPTED_POP 	"+\x06""\x01""\x05""\x05""\a\a\t"
#define SB_CMC_OID_DECRYPTED_POP 	"+\x06""\x01""\x05""\x05""\a\a\n"
#define SB_CMC_OID_LRA_POP_WITNESS 	"+\x06""\x01""\x05""\x05""\a\a\v"
#define SB_CMC_OID_GET_CERT 	"+\x06""\x01""\x05""\x05""\a\a\x0F"
#define SB_CMC_OID_GET_CRL 	"+\x06""\x01""\x05""\x05""\a\a\x10"
#define SB_CMC_OID_REVOKE_REQUEST 	"+\x06""\x01""\x05""\x05""\a\a\x11"
#define SB_CMC_OID_REG_INFO 	"+\x06""\x01""\x05""\x05""\a\a\x12"
#define SB_CMC_OID_RESPONSE_INFO 	"+\x06""\x01""\x05""\x05""\a\a\x13"
#define SB_CMC_OID_QUERY_PENDING 	"+\x06""\x01""\x05""\x05""\a\a\x15"
#define SB_CMC_OID_POP_LINK_RANDOM 	"+\x06""\x01""\x05""\x05""\a\a\x16"
#define SB_CMC_OID_POP_LINK_WITNESS 	"+\x06""\x01""\x05""\x05""\a\a\x17"
#define SB_CMC_OID_POP_LINK_WITNESS_V2 	"+\x06""\x01""\x05""\x05""\a\a!"
#define SB_CMC_OID_CONFIRM_CERT_ACCEPTANCE 	"+\x06""\x01""\x05""\x05""\a\a\x18"
#define SB_CMC_OID_STATUS_INFO_V2 	"+\x06""\x01""\x05""\x05""\a\a\x19"
#define SB_CMC_OID_TRUSTED_ANCHORS 	"+\x06""\x01""\x05""\x05""\a\a\x1A"
#define SB_CMC_OID_AUTH_DATA 	"+\x06""\x01""\x05""\x05""\a\a\x1B"
#define SB_CMC_OID_BATCH_REQUESTS 	"+\x06""\x01""\x05""\x05""\a\a\x1C"
#define SB_CMC_OID_BATCH_RESPONSES 	"+\x06""\x01""\x05""\x05""\a\a\x1D"
#define SB_CMC_OID_PUBLISH_CERT 	"+\x06""\x01""\x05""\x05""\a\a\x1E"
#define SB_CMC_OID_MOD_CERT_TEMPLATE 	"+\x06""\x01""\x05""\x05""\a\a\x1F"
#define SB_CMC_OID_CONTROL_PROCESSED 	"+\x06""\x01""\x05""\x05""\a\a "
#define SB_CMC_OID_IDENTITY_PROOF_V2 	"+\x06""\x01""\x05""\x05""\a\a\""
#define SB_OID_AEAD_CHACHA20_POLY1305_ELDOS 	"+\x06""\x01""\x04""\x01""\x82""\x90""\"\x02""\x03""@\x01"
#define SB_SpaceByteArray 	' '
#define SB_CommaByteArray 	','
#define SB_SlashByteArray 	'/'
#define SB_ColonByteArray 	':'
#define SB_EqualCharByteArray 	'='
#define SB_DashByteArray 	'-'
#define SB_LFByteArray 	'\n'
#define SB_CRByteArray 	'\r'
#define SB_LFLFByteArray 	"\n\n"
#define SB_CRLFByteArray 	"\r\n"
#define SB_CRLFCRLFByteArray 	"\r\n\r\n"
#define SB_CRCRLFByteArray 	"\r\r\n"
#define SB_CRLFTABByteArray 	"\r\n\t"
#define SB_CRLFSPACEByteArray 	"\r\n "
#define SB_CRCRLFCRCRLFByteArray 	"\r\r\n\r\r\n"
#define SB_TwoDashesByteArray 	"--"
#define SB_FiveDashesByteArray 	"-----"
#define SB_BeginLineByteArray 	"-----BEGIN "
#define SB_LFEndLineByteArray 	"\n-----END "
#define SB_CREndLineByteArray 	"\r-----END "
#define SB_UTF8BOMByteArray 	"\xEF""\xBB""\xBF"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_CONSTANTS

int32_t GetPBEAlgorithmByOID(const std::vector<uint8_t> &OID);

void GetOIDByPBEAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult);

int32_t GetPKAlgorithmByOID(const std::vector<uint8_t> &OID);

void GetOIDByPKAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult);

int32_t GetSigAlgorithmByOID(const std::vector<uint8_t> &OID);

void GetOIDBySigAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult);

int32_t GetHashAlgorithmByOID(const std::vector<uint8_t> &OID);

void GetOIDByHashAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult);

int32_t GetAlgorithmByOID(const std::vector<uint8_t> &OID, bool UseCryptoProvConstants);

void GetOIDByAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult);

void GetAlgorithmNameByAlgorithm(int32_t Algorithm, std::string &OutResult);

void GetAlgorithmNameByOID(const std::vector<uint8_t> &OID, std::string &OutResult);

int32_t GetHashAlgorithmBySigAlgorithm(int32_t Algorithm);

int32_t GetHMACAlgorithmByHashAlgorithm(int32_t Algorithm);

int32_t GetHashAlgorithmByHMACAlgorithm(int32_t Algorithm);

int32_t GetSigAlgorithmByHashAlgorithm(int32_t BasePKAlg, int32_t HashAlg);

int32_t GetKeyAlgorithmBySigAlgorithm(int32_t SigAlg);

int32_t GetSigAlgorithmByKeyAlgorithm(int32_t KeyAlg);

bool IsSymmetricKeyAlgorithm(int32_t Algorithm);

bool IsHashAlgorithm(int32_t Algorithm);

bool IsMACAlgorithm(int32_t Algorithm);

bool IsPublicKeyAlgorithm(int32_t Algorithm);

int32_t NormalizeAlgorithmConstant(int32_t Value);

int32_t MGF1AlgorithmByHash(int32_t Value);

int32_t HashAlgorithmByMGF1(int32_t Value);

#endif /* SB_USE_GLOBAL_PROCS_CONSTANTS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CONSTANTS
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetPBEAlgorithmByOID(const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetOIDByPBEAlgorithm(int32_t Algorithm, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetPKAlgorithmByOID(const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetOIDByPKAlgorithm(int32_t Algorithm, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetSigAlgorithmByOID(const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetOIDBySigAlgorithm(int32_t Algorithm, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetHashAlgorithmByOID(const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetOIDByHashAlgorithm(int32_t Algorithm, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetAlgorithmByOID(const uint8_t pOID[], int32_t szOID, int8_t UseCryptoProvConstants, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetOIDByAlgorithm(int32_t Algorithm, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetAlgorithmNameByAlgorithm(int32_t Algorithm, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetAlgorithmNameByOID(const uint8_t pOID[], int32_t szOID, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetHashAlgorithmBySigAlgorithm(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetHMACAlgorithmByHashAlgorithm(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetHashAlgorithmByHMACAlgorithm(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetSigAlgorithmByHashAlgorithm(int32_t BasePKAlg, int32_t HashAlg, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetKeyAlgorithmBySigAlgorithm(int32_t SigAlg, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_GetSigAlgorithmByKeyAlgorithm(int32_t KeyAlg, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_IsSymmetricKeyAlgorithm(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_IsHashAlgorithm(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_IsMACAlgorithm(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_IsPublicKeyAlgorithm(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_NormalizeAlgorithmConstant(int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_MGF1AlgorithmByHash(int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBConstants_HashAlgorithmByMGF1(int32_t Value, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CONSTANTS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCONSTANTS */
