#include "sbmd.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_MD

SB_INLINE void InitializeMD5(TMD5Context &Context)
{
	SBCheckError(SBMD_InitializeMD5(&Context));
}

SB_INLINE void FinalizeMD5(TMD5Context &Context, TMessageDigest128 &OutResult)
{
	SBCheckError(SBMD_FinalizeMD5(&Context, &OutResult));
}

SB_INLINE void HashMD5(void * Buffer, uint32_t Size, TMessageDigest128 &OutResult)
{
	SBCheckError(SBMD_HashMD5(Buffer, Size, &OutResult));
}

SB_INLINE void HashMD5(const std::vector<uint8_t> &Buffer, TMessageDigest128 &OutResult)
{
	SBCheckError(SBMD_HashMD5_1(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &OutResult));
}

SB_INLINE void HashMD5(TMD5Context &Context, void * Chunk, uint32_t Size)
{
	SBCheckError(SBMD_HashMD5_2(&Context, Chunk, Size));
}

SB_INLINE void InitializeMD2(TMD2Context &Context)
{
	SBCheckError(SBMD_InitializeMD2(&Context));
}

SB_INLINE void FinalizeMD2(TMD2Context &Context, TMessageDigest128 &OutResult)
{
	SBCheckError(SBMD_FinalizeMD2(&Context, &OutResult));
}

SB_INLINE void HashMD2(void * Buffer, uint32_t Size, TMessageDigest128 &OutResult)
{
	SBCheckError(SBMD_HashMD2(Buffer, Size, &OutResult));
}

SB_INLINE void HashMD2(const std::vector<uint8_t> &S, TMessageDigest128 &OutResult)
{
	SBCheckError(SBMD_HashMD2_1(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), &OutResult));
}

SB_INLINE void HashMD2(TMD2Context &Context, void * Buffer, int32_t Size)
{
	SBCheckError(SBMD_HashMD2_2(&Context, Buffer, Size));
}

#endif /* SB_USE_GLOBAL_PROCS_MD */

};	/* namespace SecureBlackbox */

