#ifndef __INC_SBRIPEMD
#define __INC_SBRIPEMD

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef uint32_t TRMD160Buffer[16];

#pragma pack(1)
typedef struct 
{
	uint32_t Buffer[16];
	uint32_t BufSize;
	uint32_t h1;
	uint32_t h2;
	uint32_t h3;
	uint32_t h4;
	uint32_t h5;
	uint32_t MessageSizeLo;
	uint32_t MessageSizeHi;
} TRMD160Context;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_RIPEMD

void InitializeRMD160(TRMD160Context &Context);

void HashRMD160(TRMD160Context &Context, void * Chunk, int32_t Size);

void HashRMD160(void * Buffer, int32_t Size, TMessageDigest160 &OutResult);

void HashRMD160(const std::string &Buffer, TMessageDigest160 &OutResult);

void FinalizeRMD160(TRMD160Context &Context, TMessageDigest160 &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_RIPEMD */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_RIPEMD
SB_IMPORT uint32_t SB_APIENTRY SBRIPEMD_InitializeRMD160(TRMD160Context * Context);
SB_IMPORT uint32_t SB_APIENTRY SBRIPEMD_HashRMD160(TRMD160Context * Context, void * Chunk, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBRIPEMD_HashRMD160_1(void * Buffer, int32_t Size, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRIPEMD_HashRMD160_2(const char * pcBuffer, int32_t szBuffer, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRIPEMD_FinalizeRMD160(TRMD160Context * Context, TMessageDigest160 * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_RIPEMD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBRIPEMD */

