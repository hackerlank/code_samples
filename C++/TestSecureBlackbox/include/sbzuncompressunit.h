#ifndef __INC_SBZUNCOMPRESSUNIT
#define __INC_SBZUNCOMPRESSUNIT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbzcommonunit.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_MANY 	1440
#define SB_DEF_WBITS 	16
#define SB_BMAX 	15

#pragma pack(1)
typedef struct 
{
	uint8_t op;
	uint8_t bits;
	uint32_t val;
} code, * PCode;

typedef uint32_t TArrShr[321];

typedef TArrShr * PArrShr;

typedef uint32_t TArrShr288[289];

typedef TArrShr * PArrShr288;

typedef code TArrCds[2049];

typedef TArrCds * PArrCds;

typedef code TArrCds31[32];

typedef TArrCds31 * PArrCds31;

typedef code TArrCds511[512];

typedef TArrCds511 * PArrCds511;

typedef uint8_t inflate_modeRaw;

typedef enum
{
	SB_HEAD = 0,
	SB_DICTID = 1,
	SB_DICT = 2,
	SB_TYPEB = 3,
	SB_TYPEDO = 4,
	SB_STORED = 5,
	SB_COPY = 6,
	SB_TABLE = 7,
	SB_LENLENS = 8,
	SB_CODELENS = 9,
	SB_LEN = 10,
	SB_LENEXT = 11,
	SB_DIST = 12,
	SB_DISTEXT = 13,
	SB_MATCH = 14,
	SB_LIT = 15,
	SB_CHECK = 16,
	SB_DONE = 17,
	SB_BAD = 18,
	SB_MEM = 19,
	SB_SYNC = 20
} inflate_mode;

#pragma pack(4)
typedef struct 
{
	inflate_modeRaw mode;
	int8_t _dummy0;
	int16_t _dummy1;
	int32_t last;
	int32_t wrap;
	int32_t havedict;
	uint32_t check;
	uint32_t total;
	uint32_t wbits;
	uint32_t wsize;
	uint32_t whave;
	uint32_t Write;
	uint32_t hold;
	uint32_t bits;
	uint32_t Length;
	uint32_t offset;
	uint32_t extra;
	char * window;
	PArrCds511 lencode;
	PArrCds31 distcode;
	uint32_t lenbits;
	uint32_t distbits;
	uint32_t ncode;
	uint32_t nlen;
	uint32_t ndist;
	uint32_t have;
	PCode next;
	uint32_t lens[321];
	uint32_t work[289];
	code codes[2049];
} inflate_state_s, * inflate_state;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_ZUNCOMPRESSUNIT

int32_t inflateReset(TZStreamRec &z);

int32_t inflateInit_(TZStreamRec &z, const std::vector<uint8_t> &version, int32_t stream_size);

int32_t inflateInit2_(TZStreamRec &z, int32_t w, const std::vector<uint8_t> &version, int32_t stream_size);

int32_t inflateEnd(TZStreamRec &z);

int32_t inflate(TZStreamRec &z, int32_t f);

int32_t uncompress(ArrayPtr &dest, uint32_t &destLen, ArrayPtr source, uint32_t sourceLen);

#endif /* SB_USE_GLOBAL_PROCS_ZUNCOMPRESSUNIT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ZUNCOMPRESSUNIT
SB_IMPORT uint32_t SB_APIENTRY SBZUncompressUnit_inflateReset(TZStreamRec * z, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZUncompressUnit_inflateInit_(TZStreamRec * z, const uint8_t pversion[], int32_t szversion, int32_t stream_size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZUncompressUnit_inflateInit2_(TZStreamRec * z, int32_t w, const uint8_t pversion[], int32_t szversion, int32_t stream_size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZUncompressUnit_inflateEnd(TZStreamRec * z, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZUncompressUnit_inflate(TZStreamRec * z, int32_t f, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZUncompressUnit_uncompress(ArrayPtr * dest, uint32_t * destLen, ArrayPtr source, uint32_t sourceLen, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_ZUNCOMPRESSUNIT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBZUNCOMPRESSUNIT */

