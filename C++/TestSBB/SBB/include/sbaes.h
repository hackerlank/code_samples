#ifndef __INC_SBAES
#define __INC_SBAES

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
#define SB_TAESBufferSize 	16

typedef uint8_t TAESBuffer[16];

typedef TAESBuffer * PAESBuffer;

typedef uint8_t TAESKey128[16];

typedef uint32_t TAESExpandedKey128[44];

typedef TAESKey128 * PAESKey128;

typedef TAESExpandedKey128 * PAESExpandedKey128;

typedef uint8_t TAESKey192[24];

typedef uint32_t TAESExpandedKey192[54];

typedef TAESKey192 * PAESKey192;

typedef TAESExpandedKey192 * PAESExpandedKey192;

typedef uint8_t TAESKey256[32];

typedef uint32_t TAESExpandedKey256[64];

typedef TAESKey256 * PAESKey256;

typedef TAESExpandedKey256 * PAESExpandedKey256;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_AES

void ExpandKeyForEncryption128(const TAESKey128 &Key, TAESExpandedKey128 &ExpandedKey);

void ExpandKeyForEncryption192(const TAESKey192 &Key, TAESExpandedKey192 &ExpandedKey);

void ExpandKeyForEncryption256(const TAESKey256 &Key, TAESExpandedKey256 &ExpandedKey);

void ExpandKeyForDecryption128(TAESExpandedKey128 &ExpandedKey);

void ExpandKeyForDecryption192(TAESExpandedKey192 &ExpandedKey);

void ExpandKeyForDecryption256(TAESExpandedKey256 &ExpandedKey);

void Encrypt128(const TAESBuffer &InBuf, const TAESExpandedKey128 &Key, TAESBuffer &OutBuf);

void Encrypt128(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey128 &Key);

void Encrypt192(const TAESBuffer &InBuf, const TAESExpandedKey192 &Key, TAESBuffer &OutBuf);

void Encrypt192(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey192 &Key);

void Encrypt256(const TAESBuffer &InBuf, const TAESExpandedKey256 &Key, TAESBuffer &OutBuf);

void Encrypt256(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey256 &Key);

void Decrypt128(const TAESBuffer &InBuf, const TAESExpandedKey128 &Key, TAESBuffer &OutBuf);

void Decrypt128(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey128 &Key);

void Decrypt192(const TAESBuffer &InBuf, const TAESExpandedKey192 &Key, TAESBuffer &OutBuf);

void Decrypt192(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey192 &Key);

void Decrypt256(const TAESBuffer &InBuf, const TAESExpandedKey256 &Key, TAESBuffer &OutBuf);

void Decrypt256(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey256 &Key);

#endif /* SB_USE_GLOBAL_PROCS_AES */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_AES
SB_IMPORT uint32_t SB_APIENTRY SBAES_ExpandKeyForEncryption128(const TAESKey128 * Key, TAESExpandedKey128 * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBAES_ExpandKeyForEncryption192(const TAESKey192 * Key, TAESExpandedKey192 * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBAES_ExpandKeyForEncryption256(const TAESKey256 * Key, TAESExpandedKey256 * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBAES_ExpandKeyForDecryption128(TAESExpandedKey128 * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBAES_ExpandKeyForDecryption192(TAESExpandedKey192 * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBAES_ExpandKeyForDecryption256(TAESExpandedKey256 * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Encrypt128(const TAESBuffer * InBuf, const TAESExpandedKey128 * Key, TAESBuffer * OutBuf);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Encrypt128_1(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TAESExpandedKey128 * Key);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Encrypt192(const TAESBuffer * InBuf, const TAESExpandedKey192 * Key, TAESBuffer * OutBuf);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Encrypt192_1(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TAESExpandedKey192 * Key);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Encrypt256(const TAESBuffer * InBuf, const TAESExpandedKey256 * Key, TAESBuffer * OutBuf);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Encrypt256_1(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TAESExpandedKey256 * Key);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Decrypt128(const TAESBuffer * InBuf, const TAESExpandedKey128 * Key, TAESBuffer * OutBuf);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Decrypt128_1(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TAESExpandedKey128 * Key);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Decrypt192(const TAESBuffer * InBuf, const TAESExpandedKey192 * Key, TAESBuffer * OutBuf);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Decrypt192_1(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TAESExpandedKey192 * Key);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Decrypt256(const TAESBuffer * InBuf, const TAESExpandedKey256 * Key, TAESBuffer * OutBuf);
SB_IMPORT uint32_t SB_APIENTRY SBAES_Decrypt256_1(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TAESExpandedKey256 * Key);
#endif /* SB_USE_GLOBAL_PROCS_AES */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBAES */

