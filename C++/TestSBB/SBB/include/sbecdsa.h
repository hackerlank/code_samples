#ifndef __INC_SBECDSA
#define __INC_SBECDSA

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbmath.h"
#include "sbecmath.h"
#include "sbeccommon.h"
#include "sbtypes.h"
#include "sbstrutils.h"
#include "sbutils.h"
#include "sbasn1.h"
#include "sbasn1tree.h"

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

#ifdef SB_USE_GLOBAL_PROCS_ECDSA

bool GenerateEx(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize);

bool GenerateforSSH(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize);

bool ExternalGenerateEx(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t CurveID, const std::vector<uint8_t> &CurveOID, int32_t FldType, int32_t Fld, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize);

bool SignEx(void * hash, int32_t hashSize, void * d, int32_t dSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, int32_t Flag, void * R, int32_t &RSize, void * S, int32_t &SSize);

bool VerifyEx(void * hash, int32_t hashSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * R, int32_t RSize, void * S, int32_t SSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, int32_t Flags);

bool EncodePrivateKey(void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, int32_t Curve, void * OutBuffer, int32_t &OutSize);

bool DecodePrivateKey(void * Buffer, int32_t Size, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize, int32_t &Curve);

bool SBECDSA_ExternalGenerationSupported();

#endif /* SB_USE_GLOBAL_PROCS_ECDSA */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ECDSA
SB_IMPORT uint32_t SB_APIENTRY SBECDSA_GenerateEx(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, void * D, int32_t * DSize, void * Qx, int32_t * QxSize, void * Qy, int32_t * QySize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECDSA_GenerateforSSH(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, void * D, int32_t * DSize, void * Qx, int32_t * QxSize, void * Qy, int32_t * QySize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECDSA_ExternalGenerateEx(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t CurveID, const uint8_t pCurveOID[], int32_t szCurveOID, int32_t FldType, int32_t Fld, void * D, int32_t * DSize, void * Qx, int32_t * QxSize, void * Qy, int32_t * QySize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECDSA_SignEx(void * hash, int32_t hashSize, void * d, int32_t dSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, int32_t Flag, void * R, int32_t * RSize, void * S, int32_t * SSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECDSA_VerifyEx(void * hash, int32_t hashSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * R, int32_t RSize, void * S, int32_t SSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, int32_t Flags, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECDSA_EncodePrivateKey(void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, int32_t Curve, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECDSA_DecodePrivateKey(void * Buffer, int32_t Size, void * D, int32_t * DSize, void * Qx, int32_t * QxSize, void * Qy, int32_t * QySize, int32_t * Curve, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECDSA_ExternalGenerationSupported(int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_ECDSA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBECDSA */

