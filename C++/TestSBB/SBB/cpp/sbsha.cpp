#include "sbsha.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_SHA

SB_INLINE void InitializeSHA1(TSHA1Context &Context)
{
	SBCheckError(SBSHA_InitializeSHA1(&Context));
}

SB_INLINE void HashSHA1(const std::vector<uint8_t> &S, TMessageDigest160 &OutResult)
{
	SBCheckError(SBSHA_HashSHA1(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), &OutResult));
}

SB_INLINE void HashSHA1(TSHA1Context &Context, void * Chunk, uint32_t Size)
{
	SBCheckError(SBSHA_HashSHA1_1(&Context, Chunk, Size));
}

SB_INLINE void HashSHA1(void * Buffer, uint32_t Size, TMessageDigest160 &OutResult)
{
	SBCheckError(SBSHA_HashSHA1_2(Buffer, Size, &OutResult));
}

SB_INLINE void FinalizeSHA1(TSHA1Context &Context, TMessageDigest160 &OutResult)
{
	SBCheckError(SBSHA_FinalizeSHA1(&Context, &OutResult));
}

#endif /* SB_USE_GLOBAL_PROCS_SHA */

};	/* namespace SecureBlackbox */

