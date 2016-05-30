#ifndef __INC_SBMD
#define __INC_SBMD

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(1)
typedef struct 
{
	int64_t Size;
	uint8_t Buffer[64];
	uint32_t BufSize;
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
} TMD5Context;

#pragma pack(1)
typedef struct 
{
	int64_t Size;
	uint8_t Checksum[16];
	uint8_t Buffer[16];
	int32_t BufSize;
	uint8_t State[16];
} TMD2Context;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_MD

void InitializeMD5(TMD5Context &Context);

void FinalizeMD5(TMD5Context &Context, TMessageDigest128 &OutResult);

void HashMD5(void * Buffer, uint32_t Size, TMessageDigest128 &OutResult);

void HashMD5(const std::vector<uint8_t> &Buffer, TMessageDigest128 &OutResult);

void HashMD5(TMD5Context &Context, void * Chunk, uint32_t Size);

void InitializeMD2(TMD2Context &Context);

void FinalizeMD2(TMD2Context &Context, TMessageDigest128 &OutResult);

void HashMD2(void * Buffer, uint32_t Size, TMessageDigest128 &OutResult);

void HashMD2(const std::vector<uint8_t> &S, TMessageDigest128 &OutResult);

void HashMD2(TMD2Context &Context, void * Buffer, int32_t Size);

#endif /* SB_USE_GLOBAL_PROCS_MD */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_MD
SB_IMPORT uint32_t SB_APIENTRY SBMD_InitializeMD5(TMD5Context * Context);
SB_IMPORT uint32_t SB_APIENTRY SBMD_FinalizeMD5(TMD5Context * Context, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMD_HashMD5(void * Buffer, uint32_t Size, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMD_HashMD5_1(const uint8_t pBuffer[], int32_t szBuffer, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMD_HashMD5_2(TMD5Context * Context, void * Chunk, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBMD_InitializeMD2(TMD2Context * Context);
SB_IMPORT uint32_t SB_APIENTRY SBMD_FinalizeMD2(TMD2Context * Context, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMD_HashMD2(void * Buffer, uint32_t Size, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMD_HashMD2_1(const uint8_t pS[], int32_t szS, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMD_HashMD2_2(TMD2Context * Context, void * Buffer, int32_t Size);
#endif /* SB_USE_GLOBAL_PROCS_MD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBMD */

