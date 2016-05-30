#ifndef __INC_SBSHA
#define __INC_SBSHA

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
#pragma pack(1)
typedef struct 
{
	int64_t Size;
	uint8_t Buffer[64];
	uint32_t LChunk[80];
	uint32_t BufSize;
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
	uint32_t E;
} TSHA1Context;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_SHA

void InitializeSHA1(TSHA1Context &Context);

void HashSHA1(const std::vector<uint8_t> &S, TMessageDigest160 &OutResult);

void HashSHA1(TSHA1Context &Context, void * Chunk, uint32_t Size);

void HashSHA1(void * Buffer, uint32_t Size, TMessageDigest160 &OutResult);

void FinalizeSHA1(TSHA1Context &Context, TMessageDigest160 &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_SHA */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SHA
SB_IMPORT uint32_t SB_APIENTRY SBSHA_InitializeSHA1(TSHA1Context * Context);
SB_IMPORT uint32_t SB_APIENTRY SBSHA_HashSHA1(const uint8_t pS[], int32_t szS, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA_HashSHA1_1(TSHA1Context * Context, void * Chunk, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBSHA_HashSHA1_2(void * Buffer, uint32_t Size, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA_FinalizeSHA1(TSHA1Context * Context, TMessageDigest160 * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_SHA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSHA */

