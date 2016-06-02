#ifndef __INC_SBBZIP2COMMON
#define __INC_SBBZIP2COMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbbzlib.h"
#include "sbbzip2basetypes.h"
#include "sbbzip2types.h"
#include "sbbzip2utils.h"

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

#ifdef SB_USE_GLOBAL_PROCS_BZIP2COMMON

#ifdef SB_USE_CLASS_ESTATE
void BZ2_compressBlock(EState &s, bool is_last_block);
void BZ2_compressBlock(EState *s, bool is_last_block);
#endif /* SB_USE_CLASS_ESTATE */

#ifdef SB_USE_CLASS_DSTATE
int32_t BZ2_decompress(DState &s);
int32_t BZ2_decompress(DState *s);
#endif /* SB_USE_CLASS_DSTATE */

#endif /* SB_USE_GLOBAL_PROCS_BZIP2COMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_BZIP2COMMON
SB_IMPORT uint32_t SB_APIENTRY SBBzip2Common_BZ2_compressBlock(EStateHandle s, int8_t is_last_block);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2Common_BZ2_decompress(DStateHandle s, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_BZIP2COMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBBZIP2COMMON */

