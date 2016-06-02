#ifndef __INC_SBBZLIB
#define __INC_SBBZLIB

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbbzip2types.h"
#include "sbbzip2basetypes.h"
#include "sbbzip2utils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_BZLIB

void AssertH(bool Condition, int32_t Err_Code);

void AssertD(bool Condition, const std::string &Err_Text);

int32_t BZ2_indexIntoF(int32_t indx, std::vector<int32_t> &cftab);

#ifdef SB_USE_CLASS_BZ_STREAM
int32_t BZ2_bzCompressInit(bz_stream &strm, int32_t blockSize100k, int32_t verbosity, int32_t workFactor);
int32_t BZ2_bzCompressInit(bz_stream *strm, int32_t blockSize100k, int32_t verbosity, int32_t workFactor);
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
int32_t BZ2_bzCompress(bz_stream &strm, int32_t action);
int32_t BZ2_bzCompress(bz_stream *strm, int32_t action);
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
int32_t BZ2_bzCompressEnd(bz_stream &strm);
int32_t BZ2_bzCompressEnd(bz_stream *strm);
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
int32_t BZ2_bzDecompressInit(bz_stream &strm, int32_t verbosity, bool Small);
int32_t BZ2_bzDecompressInit(bz_stream *strm, int32_t verbosity, bool Small);
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
int32_t BZ2_bzDecompress(bz_stream &strm);
int32_t BZ2_bzDecompress(bz_stream *strm);
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_BZ_STREAM
int32_t BZ2_bzDecompressEnd(bz_stream &strm);
int32_t BZ2_bzDecompressEnd(bz_stream *strm);
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef SB_USE_CLASS_TSBBYTEARRAY
int32_t BZ2_bzBuffToBuffCompress(TSBByteArray &dest, uint32_t &destLen, TSBByteArray &source, uint32_t sourceLen, int32_t blockSize100k, int32_t verbosity, int32_t workFactor);
int32_t BZ2_bzBuffToBuffCompress(TSBByteArray *dest, uint32_t &destLen, TSBByteArray *source, uint32_t sourceLen, int32_t blockSize100k, int32_t verbosity, int32_t workFactor);
#endif /* SB_USE_CLASS_TSBBYTEARRAY */

#ifdef SB_USE_CLASS_TSBBYTEARRAY
int32_t BZ2_bzBuffToBuffDecompress(TSBByteArray &dest, uint32_t &destLen, TSBByteArray &source, uint32_t sourceLen, bool Small, int32_t verbosity);
int32_t BZ2_bzBuffToBuffDecompress(TSBByteArray *dest, uint32_t &destLen, TSBByteArray *source, uint32_t sourceLen, bool Small, int32_t verbosity);
#endif /* SB_USE_CLASS_TSBBYTEARRAY */

#endif /* SB_USE_GLOBAL_PROCS_BZLIB */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_BZLIB
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_AssertH(int8_t Condition, int32_t Err_Code);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_AssertD(int8_t Condition, const char * pcErr_Text, int32_t szErr_Text);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_indexIntoF(int32_t indx, int32_t pcftab[], int32_t * szcftab, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_bzCompressInit(bz_streamHandle strm, int32_t blockSize100k, int32_t verbosity, int32_t workFactor, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_bzCompress(bz_streamHandle strm, int32_t action, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_bzCompressEnd(bz_streamHandle strm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_bzDecompressInit(bz_streamHandle strm, int32_t verbosity, int8_t Small, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_bzDecompress(bz_streamHandle strm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_bzDecompressEnd(bz_streamHandle strm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_bzBuffToBuffCompress(TSBByteArrayHandle dest, uint32_t * destLen, TSBByteArrayHandle source, uint32_t sourceLen, int32_t blockSize100k, int32_t verbosity, int32_t workFactor, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzlib_BZ2_bzBuffToBuffDecompress(TSBByteArrayHandle dest, uint32_t * destLen, TSBByteArrayHandle source, uint32_t sourceLen, int8_t Small, int32_t verbosity, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_BZLIB */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBBZLIB */

