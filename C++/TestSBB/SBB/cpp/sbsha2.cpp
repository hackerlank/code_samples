#include "sbsha2.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_SHA2

SB_INLINE void InitializeSHA224(TSHA256Context &Context)
{
	SBCheckError(SBSHA2_InitializeSHA224(&Context));
}

SB_INLINE void HashSHA224(TSHA256Context &Context, void * Chunk, uint32_t Size)
{
	SBCheckError(SBSHA2_HashSHA224(&Context, Chunk, Size));
}

SB_INLINE void HashSHA224(void * Buffer, uint32_t Size, TMessageDigest224 &OutResult)
{
	SBCheckError(SBSHA2_HashSHA224_1(Buffer, Size, &OutResult));
}

SB_INLINE void HashSHA224(const std::vector<uint8_t> &S, TMessageDigest224 &OutResult)
{
	SBCheckError(SBSHA2_HashSHA224_2(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), &OutResult));
}

SB_INLINE void FinalizeSHA224(TSHA256Context &Context, TMessageDigest224 &OutResult)
{
	SBCheckError(SBSHA2_FinalizeSHA224(&Context, &OutResult));
}

SB_INLINE void InitializeSHA256(TSHA256Context &Context)
{
	SBCheckError(SBSHA2_InitializeSHA256(&Context));
}

SB_INLINE void HashSHA256(TSHA256Context &Context, void * Chunk, uint32_t Size)
{
	SBCheckError(SBSHA2_HashSHA256(&Context, Chunk, Size));
}

SB_INLINE void HashSHA256(void * Buffer, uint32_t Size, TMessageDigest256 &OutResult)
{
	SBCheckError(SBSHA2_HashSHA256_1(Buffer, Size, &OutResult));
}

SB_INLINE void HashSHA256(const std::vector<uint8_t> &S, TMessageDigest256 &OutResult)
{
	SBCheckError(SBSHA2_HashSHA256_2(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), &OutResult));
}

SB_INLINE void FinalizeSHA256(TSHA256Context &Context, TMessageDigest256 &OutResult)
{
	SBCheckError(SBSHA2_FinalizeSHA256(&Context, &OutResult));
}

SB_INLINE void InitializeSHA384(TSHA512Context &Context)
{
	SBCheckError(SBSHA2_InitializeSHA384(&Context));
}

SB_INLINE void HashSHA384(TSHA512Context &Context, void * Chunk, uint32_t Size)
{
	SBCheckError(SBSHA2_HashSHA384(&Context, Chunk, Size));
}

SB_INLINE void HashSHA384(void * Buffer, uint32_t Size, TMessageDigest384 &OutResult)
{
	SBCheckError(SBSHA2_HashSHA384_1(Buffer, Size, &OutResult));
}

SB_INLINE void HashSHA384(const std::vector<uint8_t> &S, TMessageDigest384 &OutResult)
{
	SBCheckError(SBSHA2_HashSHA384_2(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), &OutResult));
}

SB_INLINE void FinalizeSHA384(TSHA512Context &Context, TMessageDigest384 &OutResult)
{
	SBCheckError(SBSHA2_FinalizeSHA384(&Context, &OutResult));
}

SB_INLINE void InitializeSHA512(TSHA512Context &Context)
{
	SBCheckError(SBSHA2_InitializeSHA512(&Context));
}

SB_INLINE void HashSHA512(TSHA512Context &Context, void * Chunk, uint32_t Size)
{
	SBCheckError(SBSHA2_HashSHA512(&Context, Chunk, Size));
}

SB_INLINE void HashSHA512(void * Buffer, uint32_t Size, TMessageDigest512 &OutResult)
{
	SBCheckError(SBSHA2_HashSHA512_1(Buffer, Size, &OutResult));
}

SB_INLINE void HashSHA512(const std::vector<uint8_t> &S, TMessageDigest512 &OutResult)
{
	SBCheckError(SBSHA2_HashSHA512_2(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), &OutResult));
}

SB_INLINE void FinalizeSHA512(TSHA512Context &Context, TMessageDigest512 &OutResult)
{
	SBCheckError(SBSHA2_FinalizeSHA512(&Context, &OutResult));
}

#endif /* SB_USE_GLOBAL_PROCS_SHA2 */

};	/* namespace SecureBlackbox */

