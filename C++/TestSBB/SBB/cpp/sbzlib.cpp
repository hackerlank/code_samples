#include "sbzlib.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ZLIB

SB_INLINE void InitializeCompression(TZlibContext &Context, int32_t CompressionLevel)
{
	SBCheckError(SBZlib_InitializeCompression(&Context, CompressionLevel));
}

SB_INLINE void InitializeDecompression(TZlibContext &Context)
{
	SBCheckError(SBZlib_InitializeDecompression(&Context));
}

SB_INLINE void InitializeDecompression64(TZlibContext &Context)
{
	SBCheckError(SBZlib_InitializeDecompression64(&Context));
}

SB_INLINE void InitializeCompressionEx(TZlibContext &Context, int32_t Level)
{
	SBCheckError(SBZlib_InitializeCompressionEx(&Context, Level));
}

SB_INLINE void InitializeCompressionEx(TZlibContext &Context, int32_t Level, int32_t WindowBits)
{
	SBCheckError(SBZlib_InitializeCompressionEx_1(&Context, Level, WindowBits));
}

SB_INLINE void InitializeDecompressionEx(TZlibContext &Context, bool UseZLib)
{
	SBCheckError(SBZlib_InitializeDecompressionEx(&Context, (int8_t)UseZLib));
}

SB_INLINE void InitializeDecompressionEx64(TZlibContext &Context, bool UseZLib)
{
	SBCheckError(SBZlib_InitializeDecompressionEx64(&Context, (int8_t)UseZLib));
}

SB_INLINE void FinalizeCompressionEx(TZlibContext &Context, void * OutBuffer, uint32_t &OutSize)
{
	SBCheckError(SBZlib_FinalizeCompressionEx(&Context, OutBuffer, &OutSize));
}

SB_INLINE void FinalizeDecompressionEx(TZlibContext &Context)
{
	SBCheckError(SBZlib_FinalizeDecompressionEx(&Context));
}

SB_INLINE void Compress(TZlibContext &Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t &OutSize)
{
	SBCheckError(SBZlib_Compress(&Context, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void Decompress(TZlibContext &Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t &OutSize)
{
	SBCheckError(SBZlib_Decompress(&Context, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void CompressEx(TZlibContext &Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t &OutSize)
{
	SBCheckError(SBZlib_CompressEx(&Context, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void DecompressEx(TZlibContext &Context, void * InBuffer, uint32_t InSize, TSBZLibOutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param)
{
	SBCheckError(SBZlib_DecompressEx(&Context, InBuffer, InSize, pMethodOutputFunc, pDataOutputFunc, Param));
}

#endif /* SB_USE_GLOBAL_PROCS_ZLIB */

};	/* namespace SecureBlackbox */

