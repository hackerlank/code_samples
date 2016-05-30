#ifndef __INC_SBWHIRLPOOL
#define __INC_SBWHIRLPOOL

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
#pragma pack(1)
typedef struct 
{
	void * BitsHashed;
	void * Buffer;
	uint32_t BufferSize;
	void * State;
} TWhirlpoolContext;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_WHIRLPOOL

void InitializeWhirlpool(TWhirlpoolContext &Context);

void HashWhirlpool(TWhirlpoolContext &Context, void * Chunk, uint32_t ChunkSize);

void HashWhirlpool(TWhirlpoolContext &Context, const std::vector<uint8_t> &Chunk, uint32_t ChunkOffset, uint32_t ChunkSize);

void FinalizeWhirlpool(TWhirlpoolContext &Context, TMessageDigest512 &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_WHIRLPOOL */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_WHIRLPOOL
SB_IMPORT uint32_t SB_APIENTRY SBWhirlpool_InitializeWhirlpool(TWhirlpoolContext * Context);
SB_IMPORT uint32_t SB_APIENTRY SBWhirlpool_HashWhirlpool(TWhirlpoolContext * Context, void * Chunk, uint32_t ChunkSize);
SB_IMPORT uint32_t SB_APIENTRY SBWhirlpool_HashWhirlpool_1(TWhirlpoolContext * Context, const uint8_t pChunk[], int32_t szChunk, uint32_t ChunkOffset, uint32_t ChunkSize);
SB_IMPORT uint32_t SB_APIENTRY SBWhirlpool_FinalizeWhirlpool(TWhirlpoolContext * Context, TMessageDigest512 * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_WHIRLPOOL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWHIRLPOOL */

