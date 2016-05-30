#include "sbecmath.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ECMATH

SB_INLINE void GetFieldByP(PLInt &P, int32_t &Field, int32_t &FldType)
{
	SBCheckError(SBECMath_GetFieldByP(&P, &Field, &FldType));
}

SB_INLINE void GetBinaryFieldK(PLInt P, int32_t &M, int32_t &K1, int32_t &K2, int32_t &K3)
{
	SBCheckError(SBECMath_GetBinaryFieldK(P, &M, &K1, &K2, &K3));
}

SB_INLINE void SetBinaryFieldK(PLInt &P, int32_t M, int32_t K1, int32_t K2, int32_t K3)
{
	SBCheckError(SBECMath_SetBinaryFieldK(&P, M, K1, K2, K3));
}

bool ECPFpDecompress(int32_t yp, PLInt X, PLInt A, PLInt B, PLInt P, PLInt &Y, int32_t Field)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECMath_ECPFpDecompress(yp, X, A, B, P, &Y, Field, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ECPF2mPDecompress(int32_t yp, PLInt X, PLInt A, PLInt B, PLInt P, PLInt &Y, int32_t Field)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECMath_ECPF2mPDecompress(yp, X, A, B, P, &Y, Field, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t ECPF2mPGetYpBit(PLInt X, PLInt Y, PLInt P, int32_t Field)
{
	int32_t OutResult;
	SBCheckError(SBECMath_ECPF2mPGetYpBit(X, Y, P, Field, &OutResult));
	return OutResult;
}

SB_INLINE void FpZero(PLInt &A, PLInt P)
{
	SBCheckError(SBECMath_FpZero(&A, P));
}

SB_INLINE void FpOne(PLInt &A, PLInt P)
{
	SBCheckError(SBECMath_FpOne(&A, P));
}

SB_INLINE void FpInt(PLInt &A, PLInt P, uint32_t C)
{
	SBCheckError(SBECMath_FpInt(&A, P, C));
}

SB_INLINE int32_t FpCmp(PLInt A, PLInt B, PLInt P)
{
	int32_t OutResult;
	SBCheckError(SBECMath_FpCmp(A, B, P, &OutResult));
	return OutResult;
}

SB_INLINE void FpAdd(PLInt A, PLInt B, PLInt P, PLInt &C)
{
	SBCheckError(SBECMath_FpAdd(A, B, P, &C));
}

SB_INLINE void FpSub(PLInt A, PLInt B, PLInt P, PLInt &C)
{
	SBCheckError(SBECMath_FpSub(A, B, P, &C));
}

bool FpIsOne(PLInt A, PLInt P)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECMath_FpIsOne(A, P, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool FpIsZero(PLInt A, PLInt P)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECMath_FpIsZero(A, P, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void FpReduce(PLInt &A, PLInt P, PLInt T1, PLInt T2, int32_t Field)
{
	SBCheckError(SBECMath_FpReduce(&A, P, T1, T2, Field));
}

SB_INLINE void FpMul(PLInt A, PLInt B, PLInt P, PLInt T1, PLInt T2, PLInt &C, int32_t Field)
{
	SBCheckError(SBECMath_FpMul(A, B, P, T1, T2, &C, Field));
}

SB_INLINE void FpSqr(PLInt A, PLInt P, PLInt T1, PLInt T2, PLInt &C, int32_t Field)
{
	SBCheckError(SBECMath_FpSqr(A, P, T1, T2, &C, Field));
}

SB_INLINE void FpDiv2(PLInt A, PLInt P, PLInt &C)
{
	SBCheckError(SBECMath_FpDiv2(A, P, &C));
}

SB_INLINE void FpInv(PLInt A, PLInt P, PLInt &C, int32_t Field)
{
	SBCheckError(SBECMath_FpInv(A, P, &C, Field));
}

SB_INLINE void FpDiv(PLInt A, PLInt B, PLInt P, PLInt &C, int32_t Field)
{
	SBCheckError(SBECMath_FpDiv(A, B, P, &C, Field));
}

SB_INLINE void F2mPZero(PLInt &A, PLInt P)
{
	SBCheckError(SBECMath_F2mPZero(&A, P));
}

SB_INLINE void F2mPOne(PLInt &A, PLInt P)
{
	SBCheckError(SBECMath_F2mPOne(&A, P));
}

bool F2mPIsZero(PLInt A, PLInt P)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECMath_F2mPIsZero(A, P, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool F2mPIsOne(PLInt A, PLInt P)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECMath_F2mPIsOne(A, P, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t F2mPCmp(PLInt A, PLInt B, PLInt P)
{
	int32_t OutResult;
	SBCheckError(SBECMath_F2mPCmp(A, B, P, &OutResult));
	return OutResult;
}

SB_INLINE void F2mPAdd(PLInt A, PLInt B, PLInt P, PLInt &C)
{
	SBCheckError(SBECMath_F2mPAdd(A, B, P, &C));
}

SB_INLINE void F2mPReduce(PLInt &A, PLInt P, int32_t Field)
{
	SBCheckError(SBECMath_F2mPReduce(&A, P, Field));
}

SB_INLINE void F2mPMul(PLInt A, PLInt B, PLInt P, PLInt &T1, PLInt &C, int32_t Field)
{
	SBCheckError(SBECMath_F2mPMul(A, B, P, &T1, &C, Field));
}

SB_INLINE void F2mPSqr(PLInt A, PLInt P, PLInt &C, int32_t Field)
{
	SBCheckError(SBECMath_F2mPSqr(A, P, &C, Field));
}

SB_INLINE void F2mPDivX(PLInt A, PLInt P, PLInt &C)
{
	SBCheckError(SBECMath_F2mPDivX(A, P, &C));
}

SB_INLINE void F2mPDiv(PLInt A, PLInt B, PLInt P, PLInt &C)
{
	SBCheckError(SBECMath_F2mPDiv(A, B, P, &C));
}

SB_INLINE void F2mPInv(PLInt A, PLInt P, PLInt &C)
{
	SBCheckError(SBECMath_F2mPInv(A, P, &C));
}

SB_INLINE void ECPFpDouble(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt &x3, PLInt &y3, int32_t Field)
{
	SBCheckError(SBECMath_ECPFpDouble(x1, y1, P, A, &x3, &y3, Field));
}

SB_INLINE void ECPFpAdd(PLInt x1, PLInt y1, PLInt x2, PLInt y2, PLInt P, PLInt A, PLInt &x3, PLInt &y3, int32_t Field)
{
	SBCheckError(SBECMath_ECPFpAdd(x1, y1, x2, y2, P, A, &x3, &y3, Field));
}

SB_INLINE void ECPFpJDouble(PLInt X1, PLInt Y1, PLInt Z1, PLInt P, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field)
{
	SBCheckError(SBECMath_ECPFpJDouble(X1, Y1, Z1, P, &X3, &Y3, &Z3, Field));
}

SB_INLINE void ECPFpJDouble(PLInt X1, PLInt Y1, PLInt Z1, PLInt P, PLInt A, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field)
{
	SBCheckError(SBECMath_ECPFpJDouble_1(X1, Y1, Z1, P, A, &X3, &Y3, &Z3, Field));
}

SB_INLINE void ECPFpJAAdd(PLInt X1, PLInt Y1, PLInt Z1, PLInt x2, PLInt y2, PLInt P, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field)
{
	SBCheckError(SBECMath_ECPFpJAAdd(X1, Y1, Z1, x2, y2, P, &X3, &Y3, &Z3, Field));
}

SB_INLINE void ECPFpExpJA(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt n, PLInt &xr, PLInt &yr, int32_t Field)
{
	SBCheckError(SBECMath_ECPFpExpJA(x1, y1, P, A, n, &xr, &yr, Field));
}

SB_INLINE void ECPFpExp(PLInt x1, PLInt y1, PLInt P, PLInt A, PLInt n, PLInt &xr, PLInt &yr, int32_t Field)
{
	SBCheckError(SBECMath_ECPFpExp(x1, y1, P, A, n, &xr, &yr, Field));
}

SB_INLINE void ECPFpJ2A(PLInt X, PLInt Y, PLInt Z, PLInt P, PLInt &xr, PLInt &yr, int32_t Field)
{
	SBCheckError(SBECMath_ECPFpJ2A(X, Y, Z, P, &xr, &yr, Field));
}

bool ECPFpPointOnCurve(PLInt X, PLInt Y, PLInt A, PLInt B, PLInt P, int32_t Field)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECMath_ECPFpPointOnCurve(X, Y, A, B, P, Field, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void ECPF2mPDouble(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt &x3, PLInt &y3, int32_t Field)
{
	SBCheckError(SBECMath_ECPF2mPDouble(x1, y1, a, b, P, &x3, &y3, Field));
}

SB_INLINE void ECPF2mPAdd(PLInt x1, PLInt y1, PLInt x2, PLInt y2, PLInt a, PLInt b, PLInt P, PLInt &x3, PLInt &y3, int32_t Field)
{
	SBCheckError(SBECMath_ECPF2mPAdd(x1, y1, x2, y2, a, b, P, &x3, &y3, Field));
}

SB_INLINE void ECPF2mPLDDouble(PLInt X1, PLInt Y1, PLInt Z1, PLInt a, PLInt b, PLInt P, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field)
{
	SBCheckError(SBECMath_ECPF2mPLDDouble(X1, Y1, Z1, a, b, P, &X3, &Y3, &Z3, Field));
}

SB_INLINE void ECPF2mPLDAAdd(PLInt X1, PLInt Y1, PLInt Z1, PLInt x2, PLInt y2, PLInt a, PLInt b, PLInt P, PLInt &X3, PLInt &Y3, PLInt &Z3, int32_t Field)
{
	SBCheckError(SBECMath_ECPF2mPLDAAdd(X1, Y1, Z1, x2, y2, a, b, P, &X3, &Y3, &Z3, Field));
}

SB_INLINE void ECPF2mPExpLDA(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt n, PLInt &xr, PLInt &yr, int32_t Field)
{
	SBCheckError(SBECMath_ECPF2mPExpLDA(x1, y1, a, b, P, n, &xr, &yr, Field));
}

SB_INLINE void ECPF2mPExp(PLInt x1, PLInt y1, PLInt a, PLInt b, PLInt P, PLInt n, PLInt &xr, PLInt &yr, int32_t Field)
{
	SBCheckError(SBECMath_ECPF2mPExp(x1, y1, a, b, P, n, &xr, &yr, Field));
}

SB_INLINE void ECPF2mPLD2A(PLInt X, PLInt Y, PLInt Z, PLInt P, PLInt &xr, PLInt &yr, int32_t Field)
{
	SBCheckError(SBECMath_ECPF2mPLD2A(X, Y, Z, P, &xr, &yr, Field));
}

bool ECPF2mPPointOnCurve(PLInt X, PLInt Y, PLInt A, PLInt B, PLInt P, int32_t Field)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECMath_ECPF2mPPointOnCurve(X, Y, A, B, P, Field, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void CryptoScalarMult(const std::vector<uint8_t> &N, const std::vector<uint8_t> &P, const std::vector<uint8_t> &Q)
{
	SBCheckError(SBECMath_CryptoScalarMult(SB_STD_VECTOR_FRONT_ADR(N), (int32_t)N.size(), SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), SB_STD_VECTOR_FRONT_ADR(Q), (int32_t)Q.size()));
}

#endif /* SB_USE_GLOBAL_PROCS_ECMATH */

};	/* namespace SecureBlackbox */

