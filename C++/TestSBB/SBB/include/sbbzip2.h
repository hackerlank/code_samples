#ifndef __INC_SBBZIP2
#define __INC_SBBZIP2

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbbzlib.h"
#include "sbbzip2types.h"
#include "sbbzip2utils.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

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
	bz_streamHandle strm;
} TBzip2Context;

typedef void (SB_CALLBACK *TSBBzip2OutputFunc)(void * _ObjectData, void * Buffer, int32_t Size, void * Param, int8_t * OutResult);

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_BZIP2

void InitializeCompression(TBzip2Context &Context, int32_t CompressionLevel, uint32_t Verbosity, uint32_t WorkFactor);

void InitializeDecompression(TBzip2Context &Context, uint32_t Verbosity, bool Small);

void Compress(TBzip2Context &Context, void * InBuffer, uint32_t InSize, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);

void Decompress(TBzip2Context &Context, void * InBuffer, uint32_t InSize, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);

void FinalizeCompression(TBzip2Context &Context, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);

void FinalizeDecompression(TBzip2Context &Context, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);

#endif /* SB_USE_GLOBAL_PROCS_BZIP2 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_BZIP2
SB_IMPORT uint32_t SB_APIENTRY SBBzip2_InitializeCompression(TBzip2Context * Context, int32_t CompressionLevel, uint32_t Verbosity, uint32_t WorkFactor);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2_InitializeDecompression(TBzip2Context * Context, uint32_t Verbosity, int8_t Small);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2_Compress(TBzip2Context * Context, void * InBuffer, uint32_t InSize, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2_Decompress(TBzip2Context * Context, void * InBuffer, uint32_t InSize, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2_FinalizeCompression(TBzip2Context * Context, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2_FinalizeDecompression(TBzip2Context * Context, TSBBzip2OutputFunc pMethodOutputFunc, void * pDataOutputFunc, void * Param);
#endif /* SB_USE_GLOBAL_PROCS_BZIP2 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBBZIP2 */

