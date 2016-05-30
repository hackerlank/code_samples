#ifndef __INC_SBSEED
#define __INC_SBSEED

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
#define SB_SEED_ENCODE 	0
#define SB_SEED_DECODE 	1

typedef uint8_t TSEEDKey[16];

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_SEED

void SeedCoding(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TSEEDKey &Key, uint8_t Direction);

#endif /* SB_USE_GLOBAL_PROCS_SEED */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SEED
SB_IMPORT uint32_t SB_APIENTRY SBSeed_SeedCoding(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TSEEDKey * Key, uint8_t Direction);
#endif /* SB_USE_GLOBAL_PROCS_SEED */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSEED */

