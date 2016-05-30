#ifndef __INC_SBCAST128
#define __INC_SBCAST128

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef uint8_t TCAST128Key[16];

typedef TCAST128Key * PCAST128Key;

typedef uint32_t TCAST128ExpandedKey[32];

typedef uint8_t TCAST128Buffer[8];

typedef TCAST128Buffer * PCAST128Buffer;

typedef uint32_t * SBCAST128_PUInt32;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_CAST128

void ExpandKey(const TCAST128Key &Key, TCAST128ExpandedKey &ExpandedKey);

void Encrypt16(uint32_t &B0, uint32_t &B1, TCAST128ExpandedKey &ExpandedKey);

void Decrypt16(uint32_t &B0, uint32_t &B1, TCAST128ExpandedKey &ExpandedKey);

#endif /* SB_USE_GLOBAL_PROCS_CAST128 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CAST128
SB_IMPORT uint32_t SB_APIENTRY SBCAST128_ExpandKey(const TCAST128Key * Key, TCAST128ExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBCAST128_Encrypt16(uint32_t * B0, uint32_t * B1, TCAST128ExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBCAST128_Decrypt16(uint32_t * B0, uint32_t * B1, TCAST128ExpandedKey * ExpandedKey);
#endif /* SB_USE_GLOBAL_PROCS_CAST128 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCAST128 */

