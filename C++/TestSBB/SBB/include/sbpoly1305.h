#ifndef __INC_SBPOLY1305
#define __INC_SBPOLY1305

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
#define SB_TPoly1305PartSize 	17
#define SB_TPoly1305KeySize 	32

typedef uint8_t TSBPoly1305Part[17];

typedef TSBPoly1305Part * PSBPoly1305Part;

typedef uint32_t TSBPoly1305MultRes[17];

typedef TSBPoly1305MultRes * PSBPoly1305MultRes;

typedef uint8_t TSBPoly1305Tag[16];

typedef TSBPoly1305Tag * PSBPoly1305Tag;

typedef uint8_t TSBPoly1305ModeRaw;

typedef enum
{
	pmDefault = 0,
	pmOpenSSH = 1,
	pmSSL = 2
} TSBPoly1305Mode;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_POLY1305

void Poly1305Clamp(TSBPoly1305Part &R);

void Poly1305Add(const TSBPoly1305Part &B, TSBPoly1305Part &A);

void Poly1305Mult(const TSBPoly1305Part &B, const TSBPoly1305Part &A, TSBPoly1305MultRes &OutResult);

void Poly1305Squeeze(const TSBPoly1305MultRes &B, TSBPoly1305Part &OutResult);

void Poly1305Final(TSBPoly1305Part &A);

void GeneratePoly1305(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Msg, TSBPoly1305Tag &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_POLY1305 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_POLY1305
SB_IMPORT uint32_t SB_APIENTRY SBPoly1305_Poly1305Clamp(TSBPoly1305Part * R);
SB_IMPORT uint32_t SB_APIENTRY SBPoly1305_Poly1305Add(const TSBPoly1305Part * B, TSBPoly1305Part * A);
SB_IMPORT uint32_t SB_APIENTRY SBPoly1305_Poly1305Mult(const TSBPoly1305Part * B, const TSBPoly1305Part * A, TSBPoly1305MultRes * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPoly1305_Poly1305Squeeze(const TSBPoly1305MultRes * B, TSBPoly1305Part * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPoly1305_Poly1305Final(TSBPoly1305Part * A);
SB_IMPORT uint32_t SB_APIENTRY SBPoly1305_GeneratePoly1305(const uint8_t pKey[], int32_t szKey, const uint8_t pMsg[], int32_t szMsg, TSBPoly1305Tag * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_POLY1305 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPOLY1305 */

