#ifndef __INC_SBIDEA
#define __INC_SBIDEA

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
#define SB_TIDEAExpandedKeySize 	104

typedef uint8_t TIDEAKey[16];

typedef TIDEAKey * PIDEAKey;

typedef uint16_t TIDEAExpandedKey[52];

typedef TIDEAExpandedKey * PIDEAExpandedKey;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_IDEA

void ExpandKeyForEncryption(const TIDEAKey &Key, TIDEAExpandedKey &ExpandedKey);

void ExpandKeyForDecryption(const TIDEAExpandedKey &CipherKey, TIDEAExpandedKey &DecipherKey);

void Encrypt(uint32_t &B0, uint32_t &B1, const TIDEAExpandedKey &Key);

#endif /* SB_USE_GLOBAL_PROCS_IDEA */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_IDEA
SB_IMPORT uint32_t SB_APIENTRY SBIDEA_ExpandKeyForEncryption(const TIDEAKey * Key, TIDEAExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBIDEA_ExpandKeyForDecryption(const TIDEAExpandedKey * CipherKey, TIDEAExpandedKey * DecipherKey);
SB_IMPORT uint32_t SB_APIENTRY SBIDEA_Encrypt(uint32_t * B0, uint32_t * B1, const TIDEAExpandedKey * Key);
#endif /* SB_USE_GLOBAL_PROCS_IDEA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBIDEA */

