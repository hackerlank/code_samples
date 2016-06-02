#ifndef __INC_SBZCOMPRESSUNIT
#define __INC_SBZCOMPRESSUNIT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbzcommonunit.h"
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
#define SB_Z_BINARY 	0
#define SB_Z_TEXT 	1
#define SB_Z_ASCII 	1
#define SB_Z_UNKNOWN 	2
#define SB_MAX_MEM_LEVEL 	9
#define SB_DEF_MEM_LEVEL 	8
#define SB_Z_NO_COMPRESSION 	0
#define SB_Z_BEST_SPEED 	1
#define SB_Z_BEST_COMPRESSION 	9
#define SB_Z_DEFAULT_COMPRESSION 	-1
#define SB_Z_FILTERED 	1
#define SB_Z_DEFAULT_STRATEGY 	0
#define SB_Z_HUFFMAN_ONLY 	2
#define SB_need_more 	0
#define SB_block_done 	1
#define SB_finish_started 	2
#define SB_finish_done 	3
#define SB_Buf_size 	16
#define SB_MIN_MATCH 	3
#define SB_MAX_MATCH 	258
#define SB_DIST_CODE_LEN 	512
#define SB_END_BLOCK 	256
#define SB_MAX_BL_BITS 	7
#define SB_TOO_FAR 	4096

typedef uint8_t * BytePtr;

typedef PChar charf;

#pragma pack(4)
typedef struct 
{
	PZStreamRec strm;
	int32_t status;
	ArrayPtr pending_buf;
	ArrayPtr pending_out;
	uint32_t pending_buf_size;
	int32_t pending;
	int32_t wrap;
	uint8_t data_type;
	uint8_t method;
	int16_t _dummy0;
	int32_t last_flush;
	uint32_t w_size;
	uint32_t w_bits;
	uint32_t w_mask;
	ArrayPtr window;
	uint32_t window_size;
	ArrayWordPtr prev;
	ArrayWordPtr head;
	uint32_t ins_h;
	uint32_t hash_size;
	uint32_t hash_bits;
	uint32_t hash_mask;
	uint32_t hash_shift;
	int32_t block_start;
	uint32_t match_length;
	uint32_t prev_match;
	int32_t match_available;
	uint32_t strstart;
	uint32_t match_start;
	uint32_t lookahead;
	uint32_t prev_length;
	uint32_t max_chain_length;
	uint32_t max_lazy_match;
	int32_t level;
	int32_t strategy;
	uint32_t good_match;
	int32_t nice_match;
	ct_data_s dyn_ltree[574];
	ct_data_s dyn_dtree[62];
	ct_data_s bl_tree[40];
	tree_desc_s l_desc;
	tree_desc_s d_desc;
	tree_desc_s bl_desc;
	uint16_t bl_count[17];
	int16_t _dummy1;
	int32_t heap[574];
	int32_t heap_len;
	int32_t heap_max;
	uint8_t depth[574];
	int16_t _dummy2;
	ArrayPtr l_buf;
	uint32_t lit_bufsize;
	uint32_t last_lit;
	ArrayWordPtr d_buf;
	uint32_t opt_len;
	uint32_t static_len;
	uint32_t matches;
	int32_t last_eob_len;
	uint16_t bi_buf;
	int16_t _dummy3;
	int32_t bi_valid;
} internal_state_s, * internal_state;

typedef void (SB_CALLBACK *compress_func)(internal_state_s * s, int32_t * flush, uint8_t * OutResult);

#pragma pack(4)
typedef struct 
{
	uint16_t good_length;
	uint16_t max_lazy;
	uint16_t nice_length;
	uint16_t max_chain;
	void * func;
} config_s;

typedef config_s config;

typedef internal_state (* internal_state_p);

typedef internal_state deflate_state;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_ZCOMPRESSUNIT

int32_t deflateInit_(TZStreamRec &strm, int32_t level, const std::vector<uint8_t> &version, int32_t recsize);

int32_t deflateInit2_(TZStreamRec &strm, int32_t level, int32_t method, int32_t windowBits, int32_t memLevel, int32_t strategy, const std::vector<uint8_t> &version, int32_t recsize);

int32_t deflateEnd(TZStreamRec &strm);

int32_t deflate(TZStreamRec &strm, int32_t flush);

int32_t deflateReset(TZStreamRec &strm);

int32_t deflateSetDictionary(TZStreamRec &strm, char * dictionary, uint32_t dictLength);

void CompressBuf(const void * InBuf, int32_t InBytes, void * &OutBuf, int32_t &OutBytes);

#endif /* SB_USE_GLOBAL_PROCS_ZCOMPRESSUNIT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ZCOMPRESSUNIT
SB_IMPORT uint32_t SB_APIENTRY SBZCompressUnit_deflateInit_(TZStreamRec * strm, int32_t level, const uint8_t pversion[], int32_t szversion, int32_t recsize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCompressUnit_deflateInit2_(TZStreamRec * strm, int32_t level, int32_t method, int32_t windowBits, int32_t memLevel, int32_t strategy, const uint8_t pversion[], int32_t szversion, int32_t recsize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCompressUnit_deflateEnd(TZStreamRec * strm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCompressUnit_deflate(TZStreamRec * strm, int32_t flush, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCompressUnit_deflateReset(TZStreamRec * strm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCompressUnit_deflateSetDictionary(TZStreamRec * strm, char * dictionary, uint32_t dictLength, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCompressUnit_CompressBuf(const void * InBuf, int32_t InBytes, void * * OutBuf, int32_t * OutBytes);
#endif /* SB_USE_GLOBAL_PROCS_ZCOMPRESSUNIT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBZCOMPRESSUNIT */

