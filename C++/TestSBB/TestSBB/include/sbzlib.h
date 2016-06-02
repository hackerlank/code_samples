#ifndef __INC_SBZLIB
#define __INC_SBZLIB

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbzcompressunit.h"
#include "sbzcommonunit.h"
#include "sbzuncompressunit.h"
#include "sbstrutils.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(4)
typedef struct 
{
	TZStreamRec strm;
} TZlibContext;

typedef void (SB_CALLBACK *TSBZLibOutputFunc)(void * _ObjectData, void * Buffer, int32_t Size, void * Param, int8_t * OutResult);

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_ZLIB

void InitializeCompression(TZlibContext &Context, int32_t CompressionLevel);

void InitializeDecompression(TZlibContext &Context);

void InitializeDecompression64(TZlibContext &Context);

void InitializeCompressionEx(TZlibContext &Context, int32_t Level);

void InitializeCompressionEx(TZlibContext &Context, int32_t Level, int32_t WindowBits);

void InitializeDecompressionEx(TZlibContext &Context, bool UseZLib);

void InitializeDecompressionEx64(TZlibContext &Context, bool UseZLib);

void FinalizeCompressionEx(TZlibContext &Context, void * OutBuffer, uint32_t &OutSize);

void FinalizeDecompressionEx(TZlibContext &Context);

void Compress(TZlibContext &Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t &OutSize);

void Decompress(TZlibContext &Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t &OutSize);

void CompressEx(TZlibContext &Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t &OutSize);

void DecompressEx(TZlibContext &Context, void * InBuffer, uint32_t InSize, TSBZLibOutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);

#endif /* SB_USE_GLOBAL_PROCS_ZLIB */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ZLIB
SB_IMPORT uint32_t SB_APIENTRY SBZlib_InitializeCompression(TZlibContext * Context, int32_t CompressionLevel);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_InitializeDecompression(TZlibContext * Context);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_InitializeDecompression64(TZlibContext * Context);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_InitializeCompressionEx(TZlibContext * Context, int32_t Level);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_InitializeCompressionEx_1(TZlibContext * Context, int32_t Level, int32_t WindowBits);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_InitializeDecompressionEx(TZlibContext * Context, int8_t UseZLib);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_InitializeDecompressionEx64(TZlibContext * Context, int8_t UseZLib);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_FinalizeCompressionEx(TZlibContext * Context, void * OutBuffer, uint32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_FinalizeDecompressionEx(TZlibContext * Context);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_Compress(TZlibContext * Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_Decompress(TZlibContext * Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_CompressEx(TZlibContext * Context, void * InBuffer, uint32_t InSize, void * OutBuffer, uint32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY SBZlib_DecompressEx(TZlibContext * Context, void * InBuffer, uint32_t InSize, TSBZLibOutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);
#endif /* SB_USE_GLOBAL_PROCS_ZLIB */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBZLIB */

