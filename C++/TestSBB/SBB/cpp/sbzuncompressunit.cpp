#include "sbzuncompressunit.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ZUNCOMPRESSUNIT

SB_INLINE int32_t inflateReset(TZStreamRec &z)
{
	int32_t OutResult;
	SBCheckError(SBZUncompressUnit_inflateReset(&z, &OutResult));
	return OutResult;
}

SB_INLINE int32_t inflateInit_(TZStreamRec &z, const std::vector<uint8_t> &version, int32_t stream_size)
{
	int32_t OutResult;
	SBCheckError(SBZUncompressUnit_inflateInit_(&z, SB_STD_VECTOR_FRONT_ADR(version), (int32_t)version.size(), stream_size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t inflateInit2_(TZStreamRec &z, int32_t w, const std::vector<uint8_t> &version, int32_t stream_size)
{
	int32_t OutResult;
	SBCheckError(SBZUncompressUnit_inflateInit2_(&z, w, SB_STD_VECTOR_FRONT_ADR(version), (int32_t)version.size(), stream_size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t inflateEnd(TZStreamRec &z)
{
	int32_t OutResult;
	SBCheckError(SBZUncompressUnit_inflateEnd(&z, &OutResult));
	return OutResult;
}

SB_INLINE int32_t inflate(TZStreamRec &z, int32_t f)
{
	int32_t OutResult;
	SBCheckError(SBZUncompressUnit_inflate(&z, f, &OutResult));
	return OutResult;
}

SB_INLINE int32_t uncompress(ArrayPtr &dest, uint32_t &destLen, ArrayPtr source, uint32_t sourceLen)
{
	int32_t OutResult;
	SBCheckError(SBZUncompressUnit_uncompress(&dest, &destLen, source, sourceLen, &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_ZUNCOMPRESSUNIT */

};	/* namespace SecureBlackbox */

