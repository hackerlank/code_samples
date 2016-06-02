#ifndef __INC_SBGOST341001
#define __INC_SBGOST341001

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbecmath.h"
#include "sbeccommon.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_GOST341001

bool Generate(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize);

bool Sign(void * hash, int32_t hashSize, void * d, int32_t dSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * R, int32_t &RSize, void * S, int32_t &SSize);

bool Verify(void * hash, int32_t hashSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * R, int32_t RSize, void * S, int32_t SSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld);

bool DeriveKey(void * ukm, int32_t ukmSize, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * R, int32_t &RSize, void * S, int32_t &SSize);

#endif /* SB_USE_GLOBAL_PROCS_GOST341001 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_GOST341001
SB_IMPORT uint32_t SB_APIENTRY SBGOST341001_Generate(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * D, int32_t * DSize, void * Qx, int32_t * QxSize, void * Qy, int32_t * QySize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGOST341001_Sign(void * hash, int32_t hashSize, void * d, int32_t dSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * R, int32_t * RSize, void * S, int32_t * SSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGOST341001_Verify(void * hash, int32_t hashSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * R, int32_t RSize, void * S, int32_t SSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGOST341001_DeriveKey(void * ukm, int32_t ukmSize, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * R, int32_t * RSize, void * S, int32_t * SSize, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_GOST341001 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGOST341001 */

