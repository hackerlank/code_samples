#ifndef __INC_SBHMAC
#define __INC_SBHMAC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsha2.h"
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
	uint8_t NKey[64];
	uint8_t iKey[64];
	uint8_t oKey[80];
	uint32_t Size;
	uint8_t Buffer[64];
	uint32_t BufSize;
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
} TMACMD5Context;

#pragma pack(1)
typedef struct 
{
	uint8_t NKey[64];
	uint8_t iKey[64];
	uint8_t oKey[84];
	uint32_t Size;
	uint8_t Buffer[64];
	uint32_t BufSize;
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
	uint32_t E;
} TMACSHA1Context;

#pragma pack(1)
typedef struct 
{
	uint8_t oKey[64];
	TSHA256Context Ctx;
} TMACSHA256Context;

#pragma pack(1)
typedef struct 
{
	uint8_t oKey[128];
	TSHA512Context Ctx;
} TMACSHA512Context;

typedef TMACSHA256Context TMACSHA224Context;

typedef TMACSHA512Context TMACSHA384Context;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_HMAC

void InitializeMACMD5(TMACMD5Context &Context, const std::vector<uint8_t> &Key);

void FinalizeMACMD5(TMACMD5Context &Context, TMessageDigest128 &OutResult);

void HashMACMD5(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest128 &OutResult);

#ifdef SB_USE_CLASS_TSTREAM
void HashMACMD5(TStream &Stream, const std::vector<uint8_t> &Key, uint32_t Count, TMessageDigest128 &OutResult);
void HashMACMD5(TStream *Stream, const std::vector<uint8_t> &Key, uint32_t Count, TMessageDigest128 &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

void HashMACMD5(void * Buffer, uint32_t Size, const std::vector<uint8_t> &Key, TMessageDigest128 &OutResult);

void HashMACMD5(TMACMD5Context &Context, void * Chunk, uint32_t Size);

void InitializeMACSHA1(TMACSHA1Context &Context, const std::vector<uint8_t> &Key);

void FinalizeMACSHA1(TMACSHA1Context &Context, TMessageDigest160 &OutResult);

#ifdef SB_USE_CLASS_TSTREAM
void HashMACSHA1(TStream &Stream, const std::vector<uint8_t> &Key, uint32_t Count, TMessageDigest160 &OutResult);
void HashMACSHA1(TStream *Stream, const std::vector<uint8_t> &Key, uint32_t Count, TMessageDigest160 &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

void HashMACSHA1(void * Buffer, uint32_t Size, const std::vector<uint8_t> &Key, TMessageDigest160 &OutResult);

void HashMACSHA1(TMACSHA1Context &Context, void * Chunk, uint32_t Size);

void HashMACSHA1(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest160 &OutResult);

void InitializeMACSHA256(TMACSHA256Context &Context, const std::vector<uint8_t> &Key);

void FinalizeMACSHA256(TMACSHA256Context &Context, TMessageDigest256 &OutResult);

void HashMACSHA256(TMACSHA256Context &Context, void * Chunk, int32_t Size);

void HashMACSHA256(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest256 &OutResult);

void InitializeMACSHA512(TMACSHA512Context &Context, const std::vector<uint8_t> &Key);

void FinalizeMACSHA512(TMACSHA512Context &Context, TMessageDigest512 &OutResult);

void HashMACSHA512(TMACSHA512Context &Context, void * Chunk, int32_t Size);

void HashMACSHA512(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest512 &OutResult);

void InitializeMACSHA224(TMACSHA256Context &Context, const std::vector<uint8_t> &Key);

void FinalizeMACSHA224(TMACSHA256Context &Context, TMessageDigest224 &OutResult);

void HashMACSHA224(TMACSHA256Context &Context, void * Chunk, int32_t Size);

void HashMACSHA224(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest224 &OutResult);

void InitializeMACSHA384(TMACSHA512Context &Context, const std::vector<uint8_t> &Key);

void FinalizeMACSHA384(TMACSHA512Context &Context, TMessageDigest384 &OutResult);

void HashMACSHA384(TMACSHA512Context &Context, void * Chunk, int32_t Size);

void HashMACSHA384(const std::vector<uint8_t> &S, const std::vector<uint8_t> &Key, TMessageDigest384 &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_HMAC */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_HMAC
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_InitializeMACMD5(TMACMD5Context * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_FinalizeMACMD5(TMACMD5Context * Context, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACMD5(const uint8_t pS[], int32_t szS, const uint8_t pKey[], int32_t szKey, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACMD5_1(TStreamHandle Stream, const uint8_t pKey[], int32_t szKey, uint32_t Count, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACMD5_2(void * Buffer, uint32_t Size, const uint8_t pKey[], int32_t szKey, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACMD5_3(TMACMD5Context * Context, void * Chunk, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_InitializeMACSHA1(TMACSHA1Context * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_FinalizeMACSHA1(TMACSHA1Context * Context, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA1(TStreamHandle Stream, const uint8_t pKey[], int32_t szKey, uint32_t Count, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA1_1(void * Buffer, uint32_t Size, const uint8_t pKey[], int32_t szKey, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA1_2(TMACSHA1Context * Context, void * Chunk, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA1_3(const uint8_t pS[], int32_t szS, const uint8_t pKey[], int32_t szKey, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_InitializeMACSHA256(TMACSHA256Context * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_FinalizeMACSHA256(TMACSHA256Context * Context, TMessageDigest256 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA256(TMACSHA256Context * Context, void * Chunk, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA256_1(const uint8_t pS[], int32_t szS, const uint8_t pKey[], int32_t szKey, TMessageDigest256 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_InitializeMACSHA512(TMACSHA512Context * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_FinalizeMACSHA512(TMACSHA512Context * Context, TMessageDigest512 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA512(TMACSHA512Context * Context, void * Chunk, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA512_1(const uint8_t pS[], int32_t szS, const uint8_t pKey[], int32_t szKey, TMessageDigest512 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_InitializeMACSHA224(TMACSHA256Context * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_FinalizeMACSHA224(TMACSHA256Context * Context, TMessageDigest224 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA224(TMACSHA256Context * Context, void * Chunk, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA224_1(const uint8_t pS[], int32_t szS, const uint8_t pKey[], int32_t szKey, TMessageDigest224 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_InitializeMACSHA384(TMACSHA512Context * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_FinalizeMACSHA384(TMACSHA512Context * Context, TMessageDigest384 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA384(TMACSHA512Context * Context, void * Chunk, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBHMAC_HashMACSHA384_1(const uint8_t pS[], int32_t szS, const uint8_t pKey[], int32_t szKey, TMessageDigest384 * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_HMAC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHMAC */

