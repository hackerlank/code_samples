#ifndef __INC_SBGSSAPIBASE
#define __INC_SBGSSAPIBASE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_GSS_C_DELEG_FLAG 	1
#define SB_GSS_C_MUTUAL_FLAG 	2
#define SB_GSS_C_REPLAY_FLAG 	4
#define SB_GSS_C_SEQUENCE_FLAG 	8
#define SB_GSS_C_CONF_FLAG 	16
#define SB_GSS_C_INTEG_FLAG 	32
#define SB_GSS_C_ANON_FLAG 	64
#define SB_GSS_C_PROT_READY_FLAG 	128
#define SB_GSS_C_TRANS_FLAG 	256
#define SB_GSS_C_BOTH 	0
#define SB_GSS_C_INITIATE 	1
#define SB_GSS_C_ACCEPT 	2
#define SB_GSS_C_GSS_CODE 	1
#define SB_GSS_C_MECH_CODE 	2
#define SB_GSS_C_QOP_DEFAULT 	0
#define SB_GSS_C_INDEFINITE 	4294967295
#define SB_GSS_C_AF_UNSPEC 	0
#define SB_GSS_C_AF_LOCAL 	1
#define SB_GSS_C_AF_INET 	2
#define SB_GSS_C_AF_IMPLINK 	3
#define SB_GSS_C_AF_PUP 	4
#define SB_GSS_C_AF_CHAOS 	5
#define SB_GSS_C_AF_NS 	6
#define SB_GSS_C_AF_NBS 	7
#define SB_GSS_C_AF_ECMA 	8
#define SB_GSS_C_AF_DATAKIT 	9
#define SB_GSS_C_AF_CCITT 	10
#define SB_GSS_C_AF_SNA 	11
#define SB_GSS_C_AF_DECnet 	12
#define SB_GSS_C_AF_DLI 	13
#define SB_GSS_C_AF_LAT 	14
#define SB_GSS_C_AF_HYLINK 	15
#define SB_GSS_C_AF_APPLETALK 	16
#define SB_GSS_C_AF_BSC 	17
#define SB_GSS_C_AF_DSS 	18
#define SB_GSS_C_AF_OSI 	19
#define SB_GSS_C_AF_X25 	21
#define SB_GSS_C_AF_NULLADDR 	255
#define SB_GSS_C_CALLING_ERROR_OFFSET 	24
#define SB_GSS_C_ROUTINE_ERROR_OFFSET 	16
#define SB_GSS_C_SUPPLEMENTARY_OFFSET 	0
#define SB_GSS_C_CALLING_ERROR_MASK 	255
#define SB_GSS_C_ROUTINE_ERROR_MASK 	255
#define SB_GSS_C_SUPPLEMENTARY_MASK 	65535
#define SB_GSS_S_COMPLETE 	0
#define SB_GSS_S_BAD_MECH 	65536
#define SB_GSS_S_BAD_NAME 	131072
#define SB_GSS_S_BAD_NAMETYPE 	196608
#define SB_GSS_S_BAD_BINDINGS 	262144
#define SB_GSS_S_BAD_STATUS 	327680
#define SB_GSS_S_BAD_SIG 	393216
#define SB_GSS_S_NO_CRED 	458752
#define SB_GSS_S_NO_CONTEXT 	524288
#define SB_GSS_S_DEFECTIVE_TOKEN 	589824
#define SB_GSS_S_DEFECTIVE_CREDENTIAL 	655360
#define SB_GSS_S_CREDENTIALS_EXPIRED 	720896
#define SB_GSS_S_CONTEXT_EXPIRED 	786432
#define SB_GSS_S_FAILURE 	851968
#define SB_GSS_S_BAD_QOP 	917504
#define SB_GSS_S_UNAUTHORIZED 	983040
#define SB_GSS_S_UNAVAILABLE 	1048576
#define SB_GSS_S_DUPLICATE_ELEMENT 	1114112
#define SB_GSS_S_NAME_NOT_MN 	1179648
#define SB_GSS_S_BAD_MIC 	393216
#define SB_GSS_S_CRED_UNAVAIL 	851968
#define SB_GSS_S_CONTINUE_NEEDED 	1
#define SB_GSS_S_DUPLICATE_TOKEN 	2
#define SB_GSS_S_OLD_TOKEN 	4
#define SB_GSS_S_UNSEQ_TOKEN 	8
#define SB_GSS_S_GAP_TOKEN 	16
#define SB_GSS_S_CALL_INACCESSIBLE_READ 	16777216
#define SB_GSS_S_CALL_INACCESSIBLE_WRITE 	33554432
#define SB_GSS_S_CALL_BAD_STRUCTURE 	50331648

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_GSSAPIBASE

uint32_t GSS_CALLING_ERROR(uint32_t x);

uint32_t GSS_ROUTINE_ERROR(uint32_t x);

uint32_t GSS_SUPPLEMENTARY_INFO(uint32_t x);

uint32_t GSS_ERROR(uint32_t x);

void DecodeMechOID(const std::vector<uint8_t> &OID, std::vector<uint8_t> &OutResult);

void EncodeMechOID(const std::vector<uint8_t> &OID, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_GSSAPIBASE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_GSSAPIBASE
SB_IMPORT uint32_t SB_APIENTRY SBGSSAPIBase_GSS_CALLING_ERROR(uint32_t x, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGSSAPIBase_GSS_ROUTINE_ERROR(uint32_t x, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGSSAPIBase_GSS_SUPPLEMENTARY_INFO(uint32_t x, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGSSAPIBase_GSS_ERROR(uint32_t x, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGSSAPIBase_DecodeMechOID(const uint8_t pOID[], int32_t szOID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGSSAPIBase_EncodeMechOID(const uint8_t pOID[], int32_t szOID, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_GSSAPIBASE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGSSAPIBASE */

