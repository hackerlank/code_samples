#ifndef __INC_SBCRC
#define __INC_SBCRC

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
#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_CRC

uint32_t CRC32(void * Buffer, int32_t Size);

uint32_t CRC32(void * Buffer, int32_t Size, uint32_t Start);

#endif /* SB_USE_GLOBAL_PROCS_CRC */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRC
SB_IMPORT uint32_t SB_APIENTRY SBCRC_CRC32(void * Buffer, int32_t Size, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCRC_CRC32_1(void * Buffer, int32_t Size, uint32_t Start, uint32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CRC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRC */

