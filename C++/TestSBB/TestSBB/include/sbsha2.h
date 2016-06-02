#ifndef __INC_SBSHA2
#define __INC_SBSHA2

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbmath.h"
#include "sbconstants.h"

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
	uint32_t E;
	uint32_t F;
	uint32_t G;
	uint32_t H;
} TSHA256Context;

#pragma pack(1)
typedef struct 
{
	int64_t Size;
	uint8_t Buffer[128];
	uint32_t BufSize;
	int64_t A;
	int64_t B;
	int64_t C;
	int64_t D;
	int64_t E;
	int64_t F;
	int64_t G;
	int64_t H;
} TSHA512Context;

typedef TSHA512Context TSHA384Context;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_SHA2

void InitializeSHA224(TSHA256Context &Context);

void HashSHA224(TSHA256Context &Context, void * Chunk, uint32_t Size);

void HashSHA224(void * Buffer, uint32_t Size, TMessageDigest224 &OutResult);

void HashSHA224(const std::vector<uint8_t> &S, TMessageDigest224 &OutResult);

void FinalizeSHA224(TSHA256Context &Context, TMessageDigest224 &OutResult);

void InitializeSHA256(TSHA256Context &Context);

void HashSHA256(TSHA256Context &Context, void * Chunk, uint32_t Size);

void HashSHA256(void * Buffer, uint32_t Size, TMessageDigest256 &OutResult);

void HashSHA256(const std::vector<uint8_t> &S, TMessageDigest256 &OutResult);

void FinalizeSHA256(TSHA256Context &Context, TMessageDigest256 &OutResult);

void InitializeSHA384(TSHA512Context &Context);

void HashSHA384(TSHA512Context &Context, void * Chunk, uint32_t Size);

void HashSHA384(void * Buffer, uint32_t Size, TMessageDigest384 &OutResult);

void HashSHA384(const std::vector<uint8_t> &S, TMessageDigest384 &OutResult);

void FinalizeSHA384(TSHA512Context &Context, TMessageDigest384 &OutResult);

void InitializeSHA512(TSHA512Context &Context);

void HashSHA512(TSHA512Context &Context, void * Chunk, uint32_t Size);

void HashSHA512(void * Buffer, uint32_t Size, TMessageDigest512 &OutResult);

void HashSHA512(const std::vector<uint8_t> &S, TMessageDigest512 &OutResult);

void FinalizeSHA512(TSHA512Context &Context, TMessageDigest512 &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_SHA2 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SHA2
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_InitializeSHA224(TSHA256Context * Context);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA224(TSHA256Context * Context, void * Chunk, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA224_1(void * Buffer, uint32_t Size, TMessageDigest224 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA224_2(const uint8_t pS[], int32_t szS, TMessageDigest224 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_FinalizeSHA224(TSHA256Context * Context, TMessageDigest224 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_InitializeSHA256(TSHA256Context * Context);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA256(TSHA256Context * Context, void * Chunk, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA256_1(void * Buffer, uint32_t Size, TMessageDigest256 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA256_2(const uint8_t pS[], int32_t szS, TMessageDigest256 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_FinalizeSHA256(TSHA256Context * Context, TMessageDigest256 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_InitializeSHA384(TSHA512Context * Context);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA384(TSHA512Context * Context, void * Chunk, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA384_1(void * Buffer, uint32_t Size, TMessageDigest384 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA384_2(const uint8_t pS[], int32_t szS, TMessageDigest384 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_FinalizeSHA384(TSHA512Context * Context, TMessageDigest384 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_InitializeSHA512(TSHA512Context * Context);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA512(TSHA512Context * Context, void * Chunk, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA512_1(void * Buffer, uint32_t Size, TMessageDigest512 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_HashSHA512_2(const uint8_t pS[], int32_t szS, TMessageDigest512 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSHA2_FinalizeSHA512(TSHA512Context * Context, TMessageDigest512 * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_SHA2 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSHA2 */

