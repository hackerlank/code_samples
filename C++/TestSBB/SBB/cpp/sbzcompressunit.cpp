#include "sbzcompressunit.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ZCOMPRESSUNIT

SB_INLINE int32_t deflateInit_(TZStreamRec &strm, int32_t level, const std::vector<uint8_t> &version, int32_t recsize)
{
	int32_t OutResult;
	SBCheckError(SBZCompressUnit_deflateInit_(&strm, level, SB_STD_VECTOR_FRONT_ADR(version), (int32_t)version.size(), recsize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t deflateInit2_(TZStreamRec &strm, int32_t level, int32_t method, int32_t windowBits, int32_t memLevel, int32_t strategy, const std::vector<uint8_t> &version, int32_t recsize)
{
	int32_t OutResult;
	SBCheckError(SBZCompressUnit_deflateInit2_(&strm, level, method, windowBits, memLevel, strategy, SB_STD_VECTOR_FRONT_ADR(version), (int32_t)version.size(), recsize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t deflateEnd(TZStreamRec &strm)
{
	int32_t OutResult;
	SBCheckError(SBZCompressUnit_deflateEnd(&strm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t deflate(TZStreamRec &strm, int32_t flush)
{
	int32_t OutResult;
	SBCheckError(SBZCompressUnit_deflate(&strm, flush, &OutResult));
	return OutResult;
}

SB_INLINE int32_t deflateReset(TZStreamRec &strm)
{
	int32_t OutResult;
	SBCheckError(SBZCompressUnit_deflateReset(&strm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t deflateSetDictionary(TZStreamRec &strm, char * dictionary, uint32_t dictLength)
{
	int32_t OutResult;
	SBCheckError(SBZCompressUnit_deflateSetDictionary(&strm, dictionary, dictLength, &OutResult));
	return OutResult;
}

SB_INLINE void CompressBuf(const void * InBuf, int32_t InBytes, void * &OutBuf, int32_t &OutBytes)
{
	SBCheckError(SBZCompressUnit_CompressBuf(InBuf, InBytes, &OutBuf, &OutBytes));
}

#endif /* SB_USE_GLOBAL_PROCS_ZCOMPRESSUNIT */

};	/* namespace SecureBlackbox */

