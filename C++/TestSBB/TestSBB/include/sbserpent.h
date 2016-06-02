#ifndef __INC_SBSERPENT
#define __INC_SBSERPENT

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
typedef uint8_t TSerpentBuffer[16];

typedef uint32_t TSerpentExpandedKey[33][4];

typedef TSerpentExpandedKey * PSerpentExpandedKey;

typedef uint32_t TSerpentExpandedKeyEx[132];

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_SERPENT

void ExpandKey(const std::vector<uint8_t> &Key, TSerpentExpandedKey &ExpandedKey);

void EncryptBlock(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TSerpentExpandedKey &ExpandedKey);

void DecryptBlock(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TSerpentExpandedKey &ExpandedKey);

#endif /* SB_USE_GLOBAL_PROCS_SERPENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SERPENT
SB_IMPORT uint32_t SB_APIENTRY SBSerpent_ExpandKey(const uint8_t pKey[], int32_t szKey, TSerpentExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBSerpent_EncryptBlock(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TSerpentExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBSerpent_DecryptBlock(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TSerpentExpandedKey * ExpandedKey);
#endif /* SB_USE_GLOBAL_PROCS_SERPENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSERPENT */

