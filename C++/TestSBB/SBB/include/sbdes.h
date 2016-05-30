#ifndef __INC_SBDES
#define __INC_SBDES

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
#define SB_TDESBufferSize 	8
#define SB_TDESKeySize 	8
#define SB_TDESExpandedKeySize 	768
#define SB_T3DESBufferSize 	8
#define SB_T3DESKeySize 	24
#define SB_T3DESExpandedKeySize 	2304

typedef uint32_t TDESExpandedKey[32];

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_DES

void ExpandKeyForEncryption(const std::vector<uint8_t> &Key, TDESExpandedKey &ExpandedKey);

void ExpandKeyForDecryption(const std::vector<uint8_t> &Key, TDESExpandedKey &ExpandedKey);

void Encrypt(uint32_t &B0, uint32_t &B1, const TDESExpandedKey &ExpandedKey);

void EncryptEDE(uint32_t &B0, uint32_t &B1, const TDESExpandedKey &Key1, const TDESExpandedKey &Key2, const TDESExpandedKey &Key3);

#endif /* SB_USE_GLOBAL_PROCS_DES */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_DES
SB_IMPORT uint32_t SB_APIENTRY SBDES_ExpandKeyForEncryption(const uint8_t pKey[], int32_t szKey, TDESExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBDES_ExpandKeyForDecryption(const uint8_t pKey[], int32_t szKey, TDESExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBDES_Encrypt(uint32_t * B0, uint32_t * B1, const TDESExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBDES_EncryptEDE(uint32_t * B0, uint32_t * B1, const TDESExpandedKey * Key1, const TDESExpandedKey * Key2, const TDESExpandedKey * Key3);
#endif /* SB_USE_GLOBAL_PROCS_DES */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDES */

