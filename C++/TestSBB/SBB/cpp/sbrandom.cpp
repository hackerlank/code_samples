#include "sbrandom.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELRANDOM

SB_INLINE void TElRandom::Randomize(const std::vector<uint8_t> &Seed)
{
	SBCheckError(TElRandom_Randomize(_Handle, SB_STD_VECTOR_FRONT_ADR(Seed), (int32_t)Seed.size()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElRandom::Randomize(TStream &Stream, int32_t Count)
{
	SBCheckError(TElRandom_Randomize_1(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElRandom::Randomize(TStream *Stream, int32_t Count)
{
	SBCheckError(TElRandom_Randomize_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */
#endif

SB_INLINE void TElRandom::Randomize(void * Buffer, int32_t Count)
{
#ifdef SB_WINDOWS
	SBCheckError(TElRandom_Randomize_2(_Handle, Buffer, Count));
#else
	SBCheckError(TElRandom_Randomize_1(_Handle, Buffer, Count));
#endif
}

void TElRandom::Generate(int32_t Count, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRandom_Generate(_Handle, Count, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-457773418, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRandom::Generate(void * Buffer, int32_t Count)
{
	SBCheckError(TElRandom_Generate_1(_Handle, Buffer, Count));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElRandom::Generate(TStream &Stream, int32_t Count)
{
	SBCheckError(TElRandom_Generate_2(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElRandom::Generate(TStream *Stream, int32_t Count)
{
	SBCheckError(TElRandom_Generate_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */
#endif

SB_INLINE void TElRandom::Seed(void * Buffer, int32_t Count)
{
	SBCheckError(TElRandom_Seed(_Handle, Buffer, Count));
}

TElRandom::TElRandom(TElRandomHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElRandom::TElRandom() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRandom_Create(&_Handle));
}

TElRandom::TElRandom(uint32_t TimeSeed) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRandom_Create_1(TimeSeed, &_Handle));
}

#endif /* SB_USE_CLASS_TELRANDOM */

#ifdef SB_USE_GLOBAL_PROCS_RANDOM

SB_INLINE int32_t SBRndTimeSeed()
{
	int32_t OutResult;
	SBCheckError(SBRandom_SBRndTimeSeed(&OutResult));
	return OutResult;
}

SB_INLINE void SBRndInit()
{
	SBCheckError(SBRandom_SBRndInit());
}

SB_INLINE void SBRndInitOnDemand()
{
	SBCheckError(SBRandom_SBRndInitOnDemand());
}

SB_INLINE void SBRndCreate()
{
	SBCheckError(SBRandom_SBRndCreate());
}

SB_INLINE void SBRndDestroy()
{
	SBCheckError(SBRandom_SBRndDestroy());
}

SB_INLINE void SBRndSeed(const std::string &Salt)
{
	SBCheckError(SBRandom_SBRndSeed(Salt.data(), (int32_t)Salt.length()));
}

SB_INLINE void SBRndSeed(void * Buffer, int32_t Size)
{
	SBCheckError(SBRandom_SBRndSeed_1(Buffer, Size));
}

SB_INLINE void SBRndSeedTime()
{
	SBCheckError(SBRandom_SBRndSeedTime());
}

SB_INLINE void SBRndGenerate(void * Buffer, int32_t Size)
{
	SBCheckError(SBRandom_SBRndGenerate(Buffer, Size));
}

SB_INLINE uint32_t SBRndGenerate(uint32_t UpperBound)
{
	uint32_t OutResult;
	SBCheckError(SBRandom_SBRndGenerate_1(UpperBound, &OutResult));
	return OutResult;
}

SB_INLINE void SBRndGenerateLInt(PLInt A, int32_t Bytes)
{
	SBCheckError(SBRandom_SBRndGenerateLInt(A, Bytes));
}

SB_INLINE void SBRndRandomize(const std::vector<uint8_t> &Seed)
{
	SBCheckError(SBRandom_SBRndRandomize(SB_STD_VECTOR_FRONT_ADR(Seed), (int32_t)Seed.size()));
}

void SBRndString(int32_t Len, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRandom_SBRndString(Len, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-416397672, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBRndString(int32_t Len, const std::string &Alphabet, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRandom_SBRndString_1(Len, Alphabet.data(), (int32_t)Alphabet.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1429144796, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_RANDOM */

};	/* namespace SecureBlackbox */
