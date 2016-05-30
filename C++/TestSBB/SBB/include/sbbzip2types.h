#ifndef __INC_SBBZIP2TYPES
#define __INC_SBBZIP2TYPES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbbzip2basetypes.h"
#include "sbbzip2utils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_CRLF 	"\r\n"
#define SB_BZ_HDR_B 	66
#define SB_BZ_HDR_Z 	90
#define SB_BZ_HDR_h 	104
#define SB_BZ_HDR_0 	48
#define SB_BZ_MAX_ALPHA_SIZE 	258
#define SB_BZ_MAX_CODE_LEN 	23
#define SB_BZ_RUNA 	0
#define SB_BZ_RUNB 	1
#define SB_BZ_N_GROUPS 	6
#define SB_BZ_G_SIZE 	50
#define SB_BZ_N_ITERS 	4
#define SB_BZ_MAX_SELECTORS 	18002
#define SB_BZ_LESSER_ICOST 	0
#define SB_BZ_GREATER_ICOST 	15
#define SB_BZ_RUN 	0
#define SB_BZ_FLUSH 	1
#define SB_BZ_FINISH 	2
#define SB_BZ_OK 	0
#define SB_BZ_RUN_OK 	1
#define SB_BZ_FLUSH_OK 	2
#define SB_BZ_FINISH_OK 	3
#define SB_BZ_STREAM_END 	4
#define SB_BZ_SEQUENCE_ERROR 	-1
#define SB_BZ_PARAM_ERROR 	-2
#define SB_BZ_MEM_ERROR 	-3
#define SB_BZ_DATA_ERROR 	-4
#define SB_BZ_DATA_ERROR_MAGIC 	-5
#define SB_BZ_IO_ERROR 	-6
#define SB_BZ_UNEXPECTED_EOF 	-7
#define SB_BZ_OUTBUFF_FULL 	-8
#define SB_BZ_CONFIG_ERROR 	-9
#define SB_BZ_NULL 	-999
#define SB_BZ_M_IDLE 	1
#define SB_BZ_M_RUNNING 	2
#define SB_BZ_M_FLUSHING 	3
#define SB_BZ_M_FINISHING 	4
#define SB_BZ_S_OUTPUT 	1
#define SB_BZ_S_INPUT 	2
#define SB_BZ_N_RADIX 	2
#define SB_BZ_N_QSORT 	12
#define SB_BZ_N_SHELL 	18
#define SB_BZ_N_OVERSHOOT 	34
#define SB_BZ_X_IDLE 	1
#define SB_BZ_X_OUTPUT 	2
#define SB_BZ_X_MAGIC_1 	10
#define SB_BZ_X_MAGIC_2 	11
#define SB_BZ_X_MAGIC_3 	12
#define SB_BZ_X_MAGIC_4 	13
#define SB_BZ_X_BLKHDR_1 	14
#define SB_BZ_X_BLKHDR_2 	15
#define SB_BZ_X_BLKHDR_3 	16
#define SB_BZ_X_BLKHDR_4 	17
#define SB_BZ_X_BLKHDR_5 	18
#define SB_BZ_X_BLKHDR_6 	19
#define SB_BZ_X_BCRC_1 	20
#define SB_BZ_X_BCRC_2 	21
#define SB_BZ_X_BCRC_3 	22
#define SB_BZ_X_BCRC_4 	23
#define SB_BZ_X_RANDBIT 	24
#define SB_BZ_X_ORIGPTR_1 	25
#define SB_BZ_X_ORIGPTR_2 	26
#define SB_BZ_X_ORIGPTR_3 	27
#define SB_BZ_X_MAPPING_1 	28
#define SB_BZ_X_MAPPING_2 	29
#define SB_BZ_X_SELECTOR_1 	30
#define SB_BZ_X_SELECTOR_2 	31
#define SB_BZ_X_SELECTOR_3 	32
#define SB_BZ_X_CODING_1 	33
#define SB_BZ_X_CODING_2 	34
#define SB_BZ_X_CODING_3 	35
#define SB_BZ_X_MTF_1 	36
#define SB_BZ_X_MTF_2 	37
#define SB_BZ_X_MTF_3 	38
#define SB_BZ_X_MTF_4 	39
#define SB_BZ_X_MTF_5 	40
#define SB_BZ_X_MTF_6 	41
#define SB_BZ_X_ENDHDR_2 	42
#define SB_BZ_X_ENDHDR_3 	43
#define SB_BZ_X_ENDHDR_4 	44
#define SB_BZ_X_ENDHDR_5 	45
#define SB_BZ_X_ENDHDR_6 	46
#define SB_BZ_X_CCRC_1 	47
#define SB_BZ_X_CCRC_2 	48
#define SB_BZ_X_CCRC_3 	49
#define SB_BZ_X_CCRC_4 	50
#define SB_MTFA_SIZE 	4096
#define SB_MTFL_SIZE 	16
#define SB_BZ_MAX_UNUSED 	5000
#define SB_NOFILE 	-1

typedef TElClassHandle EStateHandle;

typedef TElClassHandle DStateHandle;

typedef TElClassHandle bz_streamHandle;

#ifdef SB_USE_CLASS_ESTATE
SB_IMPORT uint32_t SB_APIENTRY EState_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_ESTATE */

#ifdef SB_USE_CLASS_DSTATE
SB_IMPORT uint32_t SB_APIENTRY DState_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_DSTATE */

#ifdef SB_USE_CLASS_BZ_STREAM
SB_IMPORT uint32_t SB_APIENTRY bz_stream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_BZ_STREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class EState;
class DState;
class bz_stream;

#ifdef SB_USE_CLASS_ESTATE
class EState: public TObject
{
	private:
		SB_DISABLE_COPY(EState)
	public:
		EState(EStateHandle handle, TElOwnHandle ownHandle);

		EState();

};
#endif /* SB_USE_CLASS_ESTATE */

#ifdef SB_USE_CLASS_DSTATE
class DState: public TObject
{
	private:
		SB_DISABLE_COPY(DState)
	public:
		DState(DStateHandle handle, TElOwnHandle ownHandle);

		DState();

};
#endif /* SB_USE_CLASS_DSTATE */

#ifdef SB_USE_CLASS_BZ_STREAM
class bz_stream: public TObject
{
	private:
		SB_DISABLE_COPY(bz_stream)
	public:
		bz_stream(bz_streamHandle handle, TElOwnHandle ownHandle);

		bz_stream();

};
#endif /* SB_USE_CLASS_BZ_STREAM */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBBZIP2TYPES */

