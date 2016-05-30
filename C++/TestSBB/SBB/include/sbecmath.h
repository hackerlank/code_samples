#ifndef __INC_SBECMATH
#define __INC_SBECMATH

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbmath.h"
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

#ifdef SB_USE_GLOBAL_PROCS_ECMATH

void GetFieldByP(PLInt &P, int32_t &Field, int32_t &FldType);

void GetBinaryFieldK(PLInt P, int32_t &M, int32_t &K1, int32_t &K2, int32_t &K3);

void SetBinaryFieldK(PLInt &P, int32_t M, int32_t K1, int32_t K2, int32_t K3);

bool ECPFpDecompress(int32_t yp, PLInt X, PLInt A, PLInt B, PLInt P, PLInt &Y, int32_t Field);

bool ECPF2mPDecompress(int32_t yp, PLInt X, PLInt A, PLInt B, PLInt P, PLInt &Y, int32_t Field);

int32_t ECPF2mPGetYpBit(PLInt X, PLInt Y, PLInt P, int32_t Field);

void FpZero(PLInt &A, PLInt P);

void FpOne(PLInt &A, PLInt P);

void FpInt(PLInt &A, PLInt P, uint32_t C);

int32_t FpCmp(PLInt A, PLInt B, PLInt P);

void FpAdd(PLInt A, PLInt B, PLInt P, PLInt &C);

void FpSub(PLInt A, PLInt B, PLInt P, PLInt &C);

bool FpIsOne(PLInt A, PLInt P);

bool FpIsZero(PLInt A, PLInt P);

void FpReduce(PLInt &A, PLInt P, PLInt T1, PLInt T2, int32_t Field);

void FpMul(PLInt A, PLInt B, PLInt P, PLInt T1, PLInt T2, PLInt &C, int32_t Field);

void FpSqr(PLInt A, PLInt P, PLInt T1, PLInt T2, PLInt &C, int32_t Field);

void FpDiv2(PLInt A, PLInt P, PLInt &C);

void FpInv(PLInt A, PLInt P, PLInt &C, int32_t Field);

void FpDiv(PLInt A, PLInt B, PLInt P, PLInt &C, int32_t Field);

void F2mPZero(PLInt &A, PLInt P);

void F2mPOne(PLInt &A, PLInt P);

bool F2mPIsZero(PLInt A, PLInt P);

bool F2mPIsOne(PLInt A, PLInt P);

int32_t F2mPCmp(PLInt A, PLInt B, PLInt P);

void F2mPAdd(PLInt A, PLInt B, PLInt P, PLInt &C);

void F2mPReduce(PLInt &A, PLInt P, int32_t Field);

void F2mPMul(PLInt A, PLInt B, PLInt P, PLInt &T1, PLInt &C, int32_t Field);

void F2mPSqr(PLInt A, PLInt P, PLInt &C, int32_t Field);

void F2mPDivX(PLInt A, PLInt P, PLInt &C);

void F2mPDiv(PLInt A, PLInt B, PLInt P, PLInt &C);

void F2mPInv(PLInt A, PLInt P, PLInt &C);

void ECPFpDouble(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt &x3, PLInt &y3, int32_t Field);

void ECPFpAdd(PLInt x1, PLInt y1, PLInt x2, PLInt y2, PLInt P, PLInt A, PLInt &x3, PLInt &y3, int32_t Field);

void ECPFpJDouble(PLInt X1, PLInt Y1, PLInt Z1, PLInt P, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field);

void ECPFpJDouble(PLInt X1, PLInt Y1, PLInt Z1, PLInt P, PLInt A, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field);

void ECPFpJAAdd(PLInt X1, PLInt Y1, PLInt Z1, PLInt x2, PLInt y2, PLInt P, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field);

void ECPFpExpJA(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt n, PLInt &xr, PLInt &yr, int32_t Field);

void ECPFpExp(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt n, PLInt &xr, PLInt &yr, int32_t Field);

void ECPFpJ2A(PLInt X, PLInt Y, PLInt Z, PLInt P, PLInt &xr, PLInt &yr, int32_t Field);

bool ECPFpPointOnCurve(PLInt X, PLInt Y, PLInt A, PLInt B, PLInt P, int32_t Field);

void ECPF2mPDouble(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt &x3, PLInt &y3, int32_t Field);

void ECPF2mPAdd(PLInt x1, PLInt y1, PLInt x2, PLInt y2, PLInt a, PLInt b, PLInt P, PLInt &x3, PLInt &y3, int32_t Field);

void ECPF2mPLDDouble(PLInt X1, PLInt Y1, PLInt Z1, PLInt a, PLInt b, PLInt P, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field);

void ECPF2mPLDAAdd(PLInt X1, PLInt Y1, PLInt Z1, PLInt x2, PLInt y2, PLInt a, PLInt b, PLInt P, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field);

void ECPF2mPExpLDA(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt n, PLInt &xr, PLInt &yr, int32_t Field);

void ECPF2mPExp(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt n, PLInt &xr, PLInt &yr, int32_t Field);

void ECPF2mPLD2A(PLInt X, PLInt Y, PLInt Z, PLInt P, PLInt &xr, PLInt &yr, int32_t Field);

bool ECPF2mPPointOnCurve(PLInt X, PLInt Y, PLInt A, PLInt B, PLInt P, int32_t Field);

void CryptoScalarMult(const std::vector<uint8_t> &N, const std::vector<uint8_t> &P, const std::vector<uint8_t> &Q);

#endif /* SB_USE_GLOBAL_PROCS_ECMATH */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ECMATH
SB_IMPORT uint32_t SB_APIENTRY SBECMath_GetFieldByP(PLInt * P, int32_t * Field, int32_t * FldType);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_GetBinaryFieldK(PLInt P, int32_t * M, int32_t * K1, int32_t * K2, int32_t * K3);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_SetBinaryFieldK(PLInt * P, int32_t M, int32_t K1, int32_t K2, int32_t K3);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpDecompress(int32_t yp, PLInt X, PLInt A, PLInt B, PLInt P, PLInt * Y, int32_t Field, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPDecompress(int32_t yp, PLInt X, PLInt A, PLInt B, PLInt P, PLInt * Y, int32_t Field, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPGetYpBit(PLInt X, PLInt Y, PLInt P, int32_t Field, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpZero(PLInt * A, PLInt P);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpOne(PLInt * A, PLInt P);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpInt(PLInt * A, PLInt P, uint32_t C);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpCmp(PLInt A, PLInt B, PLInt P, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpAdd(PLInt A, PLInt B, PLInt P, PLInt * C);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpSub(PLInt A, PLInt B, PLInt P, PLInt * C);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpIsOne(PLInt A, PLInt P, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpIsZero(PLInt A, PLInt P, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpReduce(PLInt * A, PLInt P, PLInt T1, PLInt T2, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpMul(PLInt A, PLInt B, PLInt P, PLInt T1, PLInt T2, PLInt * C, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpSqr(PLInt A, PLInt P, PLInt T1, PLInt T2, PLInt * C, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpDiv2(PLInt A, PLInt P, PLInt * C);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpInv(PLInt A, PLInt P, PLInt * C, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_FpDiv(PLInt A, PLInt B, PLInt P, PLInt * C, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPZero(PLInt * A, PLInt P);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPOne(PLInt * A, PLInt P);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPIsZero(PLInt A, PLInt P, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPIsOne(PLInt A, PLInt P, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPCmp(PLInt A, PLInt B, PLInt P, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPAdd(PLInt A, PLInt B, PLInt P, PLInt * C);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPReduce(PLInt * A, PLInt P, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPMul(PLInt A, PLInt B, PLInt P, PLInt * T1, PLInt * C, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPSqr(PLInt A, PLInt P, PLInt * C, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPDivX(PLInt A, PLInt P, PLInt * C);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPDiv(PLInt A, PLInt B, PLInt P, PLInt * C);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_F2mPInv(PLInt A, PLInt P, PLInt * C);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpDouble(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt * x3, PLInt * y3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpAdd(PLInt x1, PLInt y1, PLInt x2, PLInt y2, PLInt P, PLInt A, PLInt * x3, PLInt * y3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpJDouble(PLInt X1, PLInt Y1, PLInt Z1, PLInt P, PLInt * X3, PLInt * Y3, PLInt * Z3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpJDouble_1(PLInt X1, PLInt Y1, PLInt Z1, PLInt P, PLInt A, PLInt * X3, PLInt * Y3, PLInt * Z3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpJAAdd(PLInt X1, PLInt Y1, PLInt Z1, PLInt x2, PLInt y2, PLInt P, PLInt * X3, PLInt * Y3, PLInt * Z3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpExpJA(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt n, PLInt * xr, PLInt * yr, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpExp(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt n, PLInt * xr, PLInt * yr, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpJ2A(PLInt X, PLInt Y, PLInt Z, PLInt P, PLInt * xr, PLInt * yr, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPFpPointOnCurve(PLInt X, PLInt Y, PLInt A, PLInt B, PLInt P, int32_t Field, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPDouble(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt * x3, PLInt * y3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPAdd(PLInt x1, PLInt y1, PLInt x2, PLInt y2, PLInt a, PLInt b, PLInt P, PLInt * x3, PLInt * y3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPLDDouble(PLInt X1, PLInt Y1, PLInt Z1, PLInt a, PLInt b, PLInt P, PLInt * X3, PLInt * Y3, PLInt * Z3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPLDAAdd(PLInt X1, PLInt Y1, PLInt Z1, PLInt x2, PLInt y2, PLInt a, PLInt b, PLInt P, PLInt * X3, PLInt * Y3, PLInt * Z3, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPExpLDA(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt n, PLInt * xr, PLInt * yr, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPExp(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt n, PLInt * xr, PLInt * yr, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPLD2A(PLInt X, PLInt Y, PLInt Z, PLInt P, PLInt * xr, PLInt * yr, int32_t Field);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_ECPF2mPPointOnCurve(PLInt X, PLInt Y, PLInt A, PLInt B, PLInt P, int32_t Field, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECMath_CryptoScalarMult(const uint8_t pN[], int32_t szN, const uint8_t pP[], int32_t szP, const uint8_t pQ[], int32_t szQ);
#endif /* SB_USE_GLOBAL_PROCS_ECMATH */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBECMATH */

