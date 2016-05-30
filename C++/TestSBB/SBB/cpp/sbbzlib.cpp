#include "sbbzlib.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_BZLIB

SB_INLINE void AssertH(bool Condition, int32_t Err_Code)
{
	SBCheckError(SBBzlib_AssertH((int8_t)Condition, Err_Code));
}

SB_INLINE void AssertD(bool Condition, const std::string &Err_Text)
{
	SBCheckError(SBBzlib_AssertD((int8_t)Condition, Err_Text.data(), (int32_t)Err_Text.length()));
}

int32_t BZ2_indexIntoF(int32_t indx, std::vector<int32_t> &cftab)
{
	int32_t OutResult;
	int32_t szcftab = (int32_t)cftab.size() * 4;
	uint32_t _err = SBBzlib_BZ2_indexIntoF(indx, (int32_t *)SB_STD_VECTOR_FRONT_ADR(cftab), &szcftab, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		cftab.resize(szcftab / 4);
		SBCheckError(SBGetLastReturnBuffer(511896834, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(cftab), &szcftab));
	}
	else
		SBCheckError(_err);

	cftab.resize(szcftab / 4);
	return OutResult;
}

#ifdef SB_USE_CLASS_BZ_STREAM
SB_INLINE int32_t BZ2_bzCompressInit(bz_stream &strm, int32_t blockSize100k, int32_t verbosity, int32_t workFactor)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzCompressInit(strm.getHandle(), blockSize100k, verbosity, workFactor, &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_bzCompressInit(bz_stream *strm, int32_t blockSize100k, int32_t verbosity, int32_t workFactor)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzCompressInit((strm != NULL) ? strm->getHandle() : SB_NULL_HANDLE, blockSize100k, verbosity, workFactor, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
SB_INLINE int32_t BZ2_bzCompress(bz_stream &strm, int32_t action)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzCompress(strm.getHandle(), action, &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_bzCompress(bz_stream *strm, int32_t action)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzCompress((strm != NULL) ? strm->getHandle() : SB_NULL_HANDLE, action, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
SB_INLINE int32_t BZ2_bzCompressEnd(bz_stream &strm)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzCompressEnd(strm.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_bzCompressEnd(bz_stream *strm)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzCompressEnd((strm != NULL) ? strm->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
SB_INLINE int32_t BZ2_bzDecompressInit(bz_stream &strm, int32_t verbosity, bool Small)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzDecompressInit(strm.getHandle(), verbosity, (int8_t)Small, &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_bzDecompressInit(bz_stream *strm, int32_t verbosity, bool Small)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzDecompressInit((strm != NULL) ? strm->getHandle() : SB_NULL_HANDLE, verbosity, (int8_t)Small, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
SB_INLINE int32_t BZ2_bzDecompress(bz_stream &strm)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzDecompress(strm.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_bzDecompress(bz_stream *strm)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzDecompress((strm != NULL) ? strm->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
SB_INLINE int32_t BZ2_bzDecompressEnd(bz_stream &strm)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzDecompressEnd(strm.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_bzDecompressEnd(bz_stream *strm)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzDecompressEnd((strm != NULL) ? strm->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_TSBBYTEARRAY
SB_INLINE int32_t BZ2_bzBuffToBuffCompress(TSBByteArray &dest, uint32_t &destLen, TSBByteArray &source, uint32_t sourceLen, int32_t blockSize100k, int32_t verbosity, int32_t workFactor)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzBuffToBuffCompress(dest.getHandle(), &destLen, source.getHandle(), sourceLen, blockSize100k, verbosity, workFactor, &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_bzBuffToBuffCompress(TSBByteArray *dest, uint32_t &destLen, TSBByteArray *source, uint32_t sourceLen, int32_t blockSize100k, int32_t verbosity, int32_t workFactor)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzBuffToBuffCompress((dest != NULL) ? dest->getHandle() : SB_NULL_HANDLE, &destLen, (source != NULL) ? source->getHandle() : SB_NULL_HANDLE, sourceLen, blockSize100k, verbosity, workFactor, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSBBYTEARRAY */

#ifdef SB_USE_CLASS_TSBBYTEARRAY
SB_INLINE int32_t BZ2_bzBuffToBuffDecompress(TSBByteArray &dest, uint32_t &destLen, TSBByteArray &source, uint32_t sourceLen, bool Small, int32_t verbosity)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzBuffToBuffDecompress(dest.getHandle(), &destLen, source.getHandle(), sourceLen, (int8_t)Small, verbosity, &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_bzBuffToBuffDecompress(TSBByteArray *dest, uint32_t &destLen, TSBByteArray *source, uint32_t sourceLen, bool Small, int32_t verbosity)
{
	int32_t OutResult;
	SBCheckError(SBBzlib_BZ2_bzBuffToBuffDecompress((dest != NULL) ? dest->getHandle() : SB_NULL_HANDLE, &destLen, (source != NULL) ? source->getHandle() : SB_NULL_HANDLE, sourceLen, (int8_t)Small, verbosity, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSBBYTEARRAY */

#endif /* SB_USE_GLOBAL_PROCS_BZLIB */

};	/* namespace SecureBlackbox */

