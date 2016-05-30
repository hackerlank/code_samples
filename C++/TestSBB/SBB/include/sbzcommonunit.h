#ifndef __INC_SBZCOMMONUNIT
#define __INC_SBZCOMMONUNIT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ENOUGH 	2048
#define SB_MAXD 	592
#define SB_LENGTH_CODES 	29
#define SB_LITERALS 	256
#define SB_L_CODES 	286
#define SB_HEAP_SIZE 	573
#define SB_D_CODES 	30
#define SB_BL_CODES 	19
#define SB_MAX_BITS 	15
#define SB_ZLIB_VERNUM 	4640
#define SB_Z_NO_FLUSH 	0
#define SB_Z_PARTIAL_FLUSH 	1
#define SB_Z_SYNC_FLUSH 	2
#define SB_Z_FULL_FLUSH 	3
#define SB_Z_FINISH 	4
#define SB_Z_BLOCK 	5
#define SB_Z_OK 	0
#define SB_Z_STREAM_END 	1
#define SB_Z_NEED_DICT 	2
#define SB_Z_STREAM_ERROR 	-2
#define SB_Z_DATA_ERROR 	-3
#define SB_Z_MEM_ERROR 	-4
#define SB_Z_BUF_ERROR 	-5
#define SB_Z_VERSION_ERROR 	-6
#define SB_Z_NULL 	NULL
#define SB_MAX_PTR 	10
#define SB_MAX_WBITS 	16
#define SB_Z_RLE 	3
#define SB_Z_FIXED 	4
#define SB_Z_DEFLATED 	8
#define SB_PRESET_DICT 	32

#pragma pack(4)
typedef struct 
{
	union
	{
		struct
		{
			int32_t Freq;
			int32_t Dad;
		} S1;
		struct
		{
			int32_t Code;
			int32_t Len;
		} S2;
	};
} ct_data_s;

typedef ct_data_s ct_data;

typedef uint8_t Arrayfff[4096];

typedef Arrayfff * ArrayPtr;

typedef uint16_t ArrayWord[65536];

typedef ArrayWord * ArrayWordPtr;

typedef int32_t ArrayInt[65536];

typedef ArrayInt * ArrayIntPtr;

typedef uint32_t ArrayuInt[65536];

typedef ArrayuInt * ArrayuIntPtr;

typedef ct_data_s ArrayCt[65536];

typedef ArrayCt * ArrayCtPtr;

typedef ArrayPtr Bytef;

typedef ArrayWordPtr Posf;

typedef ArrayIntPtr Intf;

typedef ArrayPtr uchf;

typedef ArrayWordPtr ushf;

typedef ArrayuIntPtr uIntf;

typedef ArrayuIntPtr uLongf;

typedef uint32_t * PuInt;

typedef void (SB_CALLBACK *voidpf)();

typedef void (SB_CALLBACK *TAlloc)(void * AppData, int32_t Items, int32_t Size, void * (* OutResult));

typedef void (SB_CALLBACK *TFree)(void * AppData, void * Block);

#pragma pack(1)
typedef struct 
{
	char * next_in;
	int32_t avail_in;
	int32_t total_in;
	char * next_out;
	int32_t avail_out;
	int32_t total_out;
	char * msg;
	void * internal;
	void * zalloc;
	void * zfree;
	void * AppData;
	int32_t data_type;
	uint32_t adler;
	int32_t reserved;
	int8_t deflate64;
} TZStreamRec, * PZStreamRec;

#pragma pack(4)
typedef struct 
{
	ArrayCtPtr static_tree;
	ArrayIntPtr extra_bits;
	int32_t extra_base;
	int32_t elems;
	int32_t max_length;
} static_tree_desc_s;

typedef static_tree_desc_s static_tree_desc;

#pragma pack(4)
typedef struct 
{
	ArrayCtPtr dyn_tree;
	int32_t max_code;
	static_tree_desc_s stat_desc;
} tree_desc_s;

typedef tree_desc_s tree_desc;

#pragma pack(4)
typedef struct 
{
	void * org_ptr;
	void * new_ptr;
} ptr_table_s;

typedef ptr_table_s ptr_table;

typedef ArrayPtr (* PBytef);

typedef ArrayPtr (* Bytefp);

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_ZCOMMONUNIT

void zlibVersion(std::vector<uint8_t> &OutResult);

uint32_t adler32(uint32_t adler, void * buf, uint32_t len);

void * zlibAllocMem(void * AppData, int32_t Items, int32_t Size);

void zlibFreeMem(void * AppData, void * Block);

int32_t CCheck(int32_t code);

void ZlibMemCpy(void * dest, void * source, int32_t count);

#endif /* SB_USE_GLOBAL_PROCS_ZCOMMONUNIT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ZCOMMONUNIT
SB_IMPORT uint32_t SB_APIENTRY SBZCommonUnit_zlibVersion(uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCommonUnit_adler32(uint32_t adler, void * buf, uint32_t len, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCommonUnit_zlibAllocMem(void * AppData, int32_t Items, int32_t Size, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCommonUnit_zlibFreeMem(void * AppData, void * Block);
SB_IMPORT uint32_t SB_APIENTRY SBZCommonUnit_CCheck(int32_t code, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZCommonUnit_ZlibMemCpy(void * dest, void * source, int32_t count);
#endif /* SB_USE_GLOBAL_PROCS_ZCOMMONUNIT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBZCOMMONUNIT */

