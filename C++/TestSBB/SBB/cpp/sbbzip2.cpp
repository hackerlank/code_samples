#include "sbbzip2.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_BZIP2

SB_INLINE void InitializeCompression(TBzip2Context &Context, int32_t CompressionLevel, uint32_t Verbosity, uint32_t WorkFactor)
{
	SBCheckError(SBBzip2_InitializeCompression(&Context, CompressionLevel, Verbosity, WorkFactor));
}

SB_INLINE void InitializeDecompression(TBzip2Context &Context, uint32_t Verbosity, bool Small)
{
	SBCheckError(SBBzip2_InitializeDecompression(&Context, Verbosity, (int8_t)Small));
}

SB_INLINE void Compress(TBzip2Context &Context, void * InBuffer, uint32_t InSize, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param)
{
	SBCheckError(SBBzip2_Compress(&Context, InBuffer, InSize, pMethodOutputFunc, pDataOutputFunc, Param));
}

SB_INLINE void Decompress(TBzip2Context &Context, void * InBuffer, uint32_t InSize, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param)
{
	SBCheckError(SBBzip2_Decompress(&Context, InBuffer, InSize, pMethodOutputFunc, pDataOutputFunc, Param));
}

SB_INLINE void FinalizeCompression(TBzip2Context &Context, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param)
{
	SBCheckError(SBBzip2_FinalizeCompression(&Context, pMethodOutputFunc, pDataOutputFunc, Param));
}

SB_INLINE void FinalizeDecompression(TBzip2Context &Context, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param)
{
	SBCheckError(SBBzip2_FinalizeDecompression(&Context, pMethodOutputFunc, pDataOutputFunc, Param));
}

#endif /* SB_USE_GLOBAL_PROCS_BZIP2 */

};	/* namespace SecureBlackbox */

