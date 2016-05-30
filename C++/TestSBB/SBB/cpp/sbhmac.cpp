#include "sbhmac.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_HMAC

SB_INLINE void InitializeMACMD5(TMACMD5Context &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBHMAC_InitializeMACMD5(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void FinalizeMACMD5(TMACMD5Context &Context, TMessageDigest128 &OutResult)
{
	SBCheckError(SBHMAC_FinalizeMACMD5(&Context, &OutResult));
}

SB_INLINE void HashMACMD5(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest128 &OutResult)
{
	SBCheckError(SBHMAC_HashMACMD5(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void HashMACMD5(TStream &Stream, const std::vector<uint8_t> &Key, uint32_t Count, TMessageDigest128 &OutResult)
{
	SBCheckError(SBHMAC_HashMACMD5_1(Stream.getHandle(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), Count, &OutResult));
}
SB_INLINE void HashMACMD5(TStream *Stream, const std::vector<uint8_t> &Key, uint32_t Count, TMessageDigest128 &OutResult)
{
	SBCheckError(SBHMAC_HashMACMD5_1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), Count, &OutResult));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void HashMACMD5(void * Buffer, uint32_t Size, const std::vector<uint8_t> &Key, TMessageDigest128 &OutResult)
{
	SBCheckError(SBHMAC_HashMACMD5_2(Buffer, Size, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
}

SB_INLINE void HashMACMD5(TMACMD5Context &Context, void * Chunk, uint32_t Size)
{
	SBCheckError(SBHMAC_HashMACMD5_3(&Context, Chunk, Size));
}

SB_INLINE void InitializeMACSHA1(TMACSHA1Context &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBHMAC_InitializeMACSHA1(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void FinalizeMACSHA1(TMACSHA1Context &Context, TMessageDigest160 &OutResult)
{
	SBCheckError(SBHMAC_FinalizeMACSHA1(&Context, &OutResult));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void HashMACSHA1(TStream &Stream, const std::vector<uint8_t> &Key, uint32_t Count, TMessageDigest160 &OutResult)
{
	SBCheckError(SBHMAC_HashMACSHA1(Stream.getHandle(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), Count, &OutResult));
}
SB_INLINE void HashMACSHA1(TStream *Stream, const std::vector<uint8_t> &Key, uint32_t Count, TMessageDigest160 &OutResult)
{
	SBCheckError(SBHMAC_HashMACSHA1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), Count, &OutResult));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void HashMACSHA1(void * Buffer, uint32_t Size, const std::vector<uint8_t> &Key, TMessageDigest160 &OutResult)
{
	SBCheckError(SBHMAC_HashMACSHA1_1(Buffer, Size, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
}

SB_INLINE void HashMACSHA1(TMACSHA1Context &Context, void * Chunk, uint32_t Size)
{
	SBCheckError(SBHMAC_HashMACSHA1_2(&Context, Chunk, Size));
}

SB_INLINE void HashMACSHA1(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest160 &OutResult)
{
	SBCheckError(SBHMAC_HashMACSHA1_3(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
}

SB_INLINE void InitializeMACSHA256(TMACSHA256Context &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBHMAC_InitializeMACSHA256(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void FinalizeMACSHA256(TMACSHA256Context &Context, TMessageDigest256 &OutResult)
{
	SBCheckError(SBHMAC_FinalizeMACSHA256(&Context, &OutResult));
}

SB_INLINE void HashMACSHA256(TMACSHA256Context &Context, void * Chunk, int32_t Size)
{
	SBCheckError(SBHMAC_HashMACSHA256(&Context, Chunk, Size));
}

SB_INLINE void HashMACSHA256(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest256 &OutResult)
{
	SBCheckError(SBHMAC_HashMACSHA256_1(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
}

SB_INLINE void InitializeMACSHA512(TMACSHA512Context &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBHMAC_InitializeMACSHA512(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void FinalizeMACSHA512(TMACSHA512Context &Context, TMessageDigest512 &OutResult)
{
	SBCheckError(SBHMAC_FinalizeMACSHA512(&Context, &OutResult));
}

SB_INLINE void HashMACSHA512(TMACSHA512Context &Context, void * Chunk, int32_t Size)
{
	SBCheckError(SBHMAC_HashMACSHA512(&Context, Chunk, Size));
}

SB_INLINE void HashMACSHA512(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest512 &OutResult)
{
	SBCheckError(SBHMAC_HashMACSHA512_1(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
}

SB_INLINE void InitializeMACSHA224(TMACSHA256Context &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBHMAC_InitializeMACSHA224(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void FinalizeMACSHA224(TMACSHA256Context &Context, TMessageDigest224 &OutResult)
{
	SBCheckError(SBHMAC_FinalizeMACSHA224(&Context, &OutResult));
}

SB_INLINE void HashMACSHA224(TMACSHA256Context &Context, void * Chunk, int32_t Size)
{
	SBCheckError(SBHMAC_HashMACSHA224(&Context, Chunk, Size));
}

SB_INLINE void HashMACSHA224(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest224 &OutResult)
{
	SBCheckError(SBHMAC_HashMACSHA224_1(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
}

SB_INLINE void InitializeMACSHA384(TMACSHA512Context &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBHMAC_InitializeMACSHA384(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void FinalizeMACSHA384(TMACSHA512Context &Context, TMessageDigest384 &OutResult)
{
	SBCheckError(SBHMAC_FinalizeMACSHA384(&Context, &OutResult));
}

SB_INLINE void HashMACSHA384(TMACSHA512Context &Context, void * Chunk, int32_t Size)
{
	SBCheckError(SBHMAC_HashMACSHA384(&Context, Chunk, Size));
}

SB_INLINE void HashMACSHA384(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest384 &OutResult)
{
	SBCheckError(SBHMAC_HashMACSHA384_1(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
}

#endif /* SB_USE_GLOBAL_PROCS_HMAC */

};	/* namespace SecureBlackbox */

