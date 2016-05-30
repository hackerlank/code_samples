#include "sbwhirlpool.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_WHIRLPOOL

SB_INLINE void InitializeWhirlpool(TWhirlpoolContext &Context)
{
	SBCheckError(SBWhirlpool_InitializeWhirlpool(&Context));
}

SB_INLINE void HashWhirlpool(TWhirlpoolContext &Context, void * Chunk, uint32_t ChunkSize)
{
	SBCheckError(SBWhirlpool_HashWhirlpool(&Context, Chunk, ChunkSize));
}

SB_INLINE void HashWhirlpool(TWhirlpoolContext &Context, const std::vector<uint8_t> &Chunk, uint32_t ChunkOffset, uint32_t ChunkSize)
{
	SBCheckError(SBWhirlpool_HashWhirlpool_1(&Context, SB_STD_VECTOR_FRONT_ADR(Chunk), (int32_t)Chunk.size(), ChunkOffset, ChunkSize));
}

SB_INLINE void FinalizeWhirlpool(TWhirlpoolContext &Context, TMessageDigest512 &OutResult)
{
	SBCheckError(SBWhirlpool_FinalizeWhirlpool(&Context, &OutResult));
}

#endif /* SB_USE_GLOBAL_PROCS_WHIRLPOOL */

};	/* namespace SecureBlackbox */

