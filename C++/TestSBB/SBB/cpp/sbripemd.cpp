#include "sbripemd.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_RIPEMD

SB_INLINE void InitializeRMD160(TRMD160Context &Context)
{
	SBCheckError(SBRIPEMD_InitializeRMD160(&Context));
}

SB_INLINE void HashRMD160(TRMD160Context &Context, void * Chunk, int32_t Size)
{
	SBCheckError(SBRIPEMD_HashRMD160(&Context, Chunk, Size));
}

SB_INLINE void HashRMD160(void * Buffer, int32_t Size, TMessageDigest160 &OutResult)
{
	SBCheckError(SBRIPEMD_HashRMD160_1(Buffer, Size, &OutResult));
}

SB_INLINE void HashRMD160(const std::string &Buffer, TMessageDigest160 &OutResult)
{
	SBCheckError(SBRIPEMD_HashRMD160_2(Buffer.data(), (int32_t)Buffer.length(), &OutResult));
}

SB_INLINE void FinalizeRMD160(TRMD160Context &Context, TMessageDigest160 &OutResult)
{
	SBCheckError(SBRIPEMD_FinalizeRMD160(&Context, &OutResult));
}

#endif /* SB_USE_GLOBAL_PROCS_RIPEMD */

};	/* namespace SecureBlackbox */

