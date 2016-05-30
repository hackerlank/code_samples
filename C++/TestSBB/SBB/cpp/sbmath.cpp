#include "sbmath.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_MATH

SB_INLINE void LShl(PLInt &Num)
{
	SBCheckError(SBMath_LShl(&Num));
}

SB_INLINE void LShlEx(PLInt &Num, int32_t Bits)
{
	SBCheckError(SBMath_LShlEx(&Num, Bits));
}

SB_INLINE void LShlNum(PLInt Src, PLInt Dest, int32_t Bits)
{
	SBCheckError(SBMath_LShlNum(Src, Dest, Bits));
}

SB_INLINE void LShr(PLInt &Num)
{
	SBCheckError(SBMath_LShr(&Num));
}

SB_INLINE void LShrEx(PLInt &Num, int32_t Bits)
{
	SBCheckError(SBMath_LShrEx(&Num, Bits));
}

SB_INLINE void LShrNum(PLInt X, PLInt &Res, uint32_t Bits)
{
	SBCheckError(SBMath_LShrNum(X, &Res, Bits));
}

SB_INLINE void LShiftLeft(PLInt &A, uint32_t N)
{
	SBCheckError(SBMath_LShiftLeft(&A, N));
}

SB_INLINE void LAdd(PLInt A, PLInt B, PLInt C)
{
	SBCheckError(SBMath_LAdd(A, B, C));
}

SB_INLINE void LAdd(PLInt A, uint32_t B, PLInt C)
{
	SBCheckError(SBMath_LAdd_1(A, B, C));
}

SB_INLINE void LSub(PLInt A, PLInt B, PLInt &PTm)
{
	SBCheckError(SBMath_LSub(A, B, &PTm));
}

SB_INLINE void LSub(PLInt A, uint32_t B, PLInt &PTm)
{
	SBCheckError(SBMath_LSub_1(A, B, &PTm));
}

SB_INLINE void LDec(PLInt &A)
{
	SBCheckError(SBMath_LDec(&A));
}

SB_INLINE void LInc(PLInt &A)
{
	SBCheckError(SBMath_LInc(&A));
}

SB_INLINE void LMultSh(PLInt A, uint32_t B, PLInt Res)
{
	SBCheckError(SBMath_LMultSh(A, B, Res));
}

SB_INLINE void LMult(PLInt A, PLInt B, PLInt &Res)
{
	SBCheckError(SBMath_LMult(A, B, &Res));
}

SB_INLINE void LModSh(PLInt A, uint32_t B, uint32_t &Res)
{
	SBCheckError(SBMath_LModSh(A, B, &Res));
}

SB_INLINE void LMod(PLInt X, PLInt N, PLInt &Res)
{
	SBCheckError(SBMath_LMod(X, N, &Res));
}

SB_INLINE void LModEx(PLInt X, PLInt N, PLInt &Res)
{
	SBCheckError(SBMath_LModEx(X, N, &Res));
}

SB_INLINE void LDivSh(PLInt A, uint32_t B, PLInt Q, PLInt R)
{
	SBCheckError(SBMath_LDivSh(A, B, Q, R));
}

SB_INLINE void LDiv(PLInt A, PLInt B, PLInt &C, PLInt &D)
{
	SBCheckError(SBMath_LDiv(A, B, &C, &D));
}

SB_INLINE void LModPower(PLInt A, PLInt E, PLInt N, PLInt &Res)
{
	SBCheckError(SBMath_LModPower(A, E, N, &Res));
}

SB_INLINE void LMontgomery(PLInt A, PLInt B, PLInt N, PLInt &Res)
{
	SBCheckError(SBMath_LMontgomery(A, B, N, &Res));
}

SB_INLINE void LGCD(PLInt B, PLInt A, PLInt &C, PLInt &D)
{
	SBCheckError(SBMath_LGCD(B, A, &C, &D));
}

SB_INLINE void LSwap(PLInt &A, PLInt &B)
{
	SBCheckError(SBMath_LSwap(&A, &B));
}

SB_INLINE uint32_t LBitCount(PLInt A)
{
	uint32_t OutResult;
	SBCheckError(SBMath_LBitCount(A, &OutResult));
	return OutResult;
}

bool LBitSet(PLInt A, int32_t n)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMath_LBitSet(A, n, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void LSetBit(PLInt &A, int32_t n, bool Value)
{
	SBCheckError(SBMath_LSetBit(&A, n, (int8_t)Value));
}

SB_INLINE void LBitTruncate(PLInt &A, int32_t Bits)
{
	SBCheckError(SBMath_LBitTruncate(&A, Bits));
}

bool LGreater(PLInt A, PLInt B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMath_LGreater(A, B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool LEqual(PLInt A, PLInt B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMath_LEqual(A, B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool LEven(PLInt A)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMath_LEven(A, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool LNull(PLInt A)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMath_LNull(A, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void LCopy(PLInt &P, PLInt A)
{
	SBCheckError(SBMath_LCopy(&P, A));
}

SB_INLINE void LZero(PLInt &A)
{
	SBCheckError(SBMath_LZero(&A));
}

void LToStr(PLInt A, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBMath_LToStr(A, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1181400013, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void LToBase64(PLInt A, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBMath_LToBase64(A, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1591964350, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void LInit(PLInt &P, const std::string &Num)
{
	SBCheckError(SBMath_LInit(&P, Num.data(), (int32_t)Num.length()));
}

SB_INLINE void LInit(PLInt &P, uint32_t Num)
{
	SBCheckError(SBMath_LInit_1(&P, Num));
}

SB_INLINE void LInit(PLInt &P, int64_t Num)
{
	SBCheckError(SBMath_LInit_2(&P, Num));
}

SB_INLINE void LGenerate(PLInt &R, int32_t Len)
{
	SBCheckError(SBMath_LGenerate(&R, Len));
}

SB_INLINE void LCreate(PLInt &A)
{
	SBCheckError(SBMath_LCreate(&A));
}

SB_INLINE void LDestroy(PLInt &P)
{
	SBCheckError(SBMath_LDestroy(&P));
}

SB_INLINE void LTrim(PLInt &A)
{
	SBCheckError(SBMath_LTrim(&A));
}

SB_INLINE void LSanitize(PLInt &A, int32_t Digits)
{
	SBCheckError(SBMath_LSanitize(&A, Digits));
}

SB_INLINE int32_t HexToDecDigit(char A)
{
	int32_t OutResult;
	SBCheckError(SBMath_HexToDecDigit(A, &OutResult));
	return OutResult;
}

SB_INLINE char DecToHexDigit(int32_t A)
{
	char OutResult;
	SBCheckError(SBMath_DecToHexDigit(A, &OutResult));
	return OutResult;
}

void DecToHex(uint32_t A, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBMath_DecToHex(A, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1759151854, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void LBAddPowB(PLInt Src, PLInt Dest, uint32_t Bases)
{
	SBCheckError(SBMath_LBAddPowB(Src, Dest, Bases));
}

SB_INLINE void LBM(PLInt SrcMod, PLInt Dest, uint32_t Bits)
{
	SBCheckError(SBMath_LBM(SrcMod, Dest, Bits));
}

SB_INLINE void LBDivPowB(PLInt Src, PLInt Dest, uint32_t Bases)
{
	SBCheckError(SBMath_LBDivPowB(Src, Dest, Bases));
}

SB_INLINE void LBModPowB(PLInt Src, PLInt Dest, uint32_t Bases)
{
	SBCheckError(SBMath_LBModPowB(Src, Dest, Bases));
}

SB_INLINE void LBMul(PLInt SrcA, PLInt SrcB, PLInt Dest, uint32_t FromBases, uint32_t ToBases)
{
	SBCheckError(SBMath_LBMul(SrcA, SrcB, Dest, FromBases, ToBases));
}

SB_INLINE void LBMod(PLInt Src, PLInt SrcMod, PLInt SrcM, PLInt &Dest, uint32_t Bits)
{
	SBCheckError(SBMath_LBMod(Src, SrcMod, SrcM, &Dest, Bits));
}

SB_INLINE void LBPowMod(PLInt SrcA, PLInt SrcB, PLInt SrcMod, PLInt &Dest, PLInt ModInv)
{
	SBCheckError(SBMath_LBPowMod(SrcA, SrcB, SrcMod, &Dest, ModInv));
}

SB_INLINE void LMMul(PLInt A, PLInt B, PLInt N, PLInt &Res)
{
	SBCheckError(SBMath_LMMul(A, B, N, &Res));
}

SB_INLINE void LMModPower(PLInt X, PLInt E, PLInt N, PLInt &Res, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel)
{
	SBCheckError(SBMath_LMModPower(X, E, N, &Res, pMethodProgressFunc, pDataProgressFunc, Data, (int8_t)RaiseExceptionOnCancel));
}

bool LRabinMillerPrimeTest(PLInt P, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMath_LRabinMillerPrimeTest(P, pMethodProgressFunc, pDataProgressFunc, Data, (int8_t)RaiseExceptionOnCancel, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool LIsPrime(PLInt P, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMath_LIsPrime(P, pMethodProgressFunc, pDataProgressFunc, Data, (int8_t)RaiseExceptionOnCancel, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void LGenPrime(PLInt P, int32_t Len, bool RSAPrime, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel)
{
	SBCheckError(SBMath_LGenPrime(P, Len, (int8_t)RSAPrime, pMethodProgressFunc, pDataProgressFunc, Data, (int8_t)RaiseExceptionOnCancel));
}

SB_INLINE void LGenPrimeEx(PLInt P, int32_t Bits, bool RSAPrime, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel)
{
	SBCheckError(SBMath_LGenPrimeEx(P, Bits, (int8_t)RSAPrime, pMethodProgressFunc, pDataProgressFunc, Data, (int8_t)RaiseExceptionOnCancel));
}

SB_INLINE void LRC4Randomize(TRC4RandomContext &Ctx, PLInt Key)
{
	SBCheckError(SBMath_LRC4Randomize(&Ctx, Key));
}

SB_INLINE void LRC4Init(TRC4RandomContext &Ctx)
{
	SBCheckError(SBMath_LRC4Init(&Ctx));
}

SB_INLINE uint8_t LRC4RandomByte(TRC4RandomContext &Ctx)
{
	uint8_t OutResult;
	SBCheckError(SBMath_LRC4RandomByte(&Ctx, &OutResult));
	return OutResult;
}

SB_INLINE void LRandom(TRC4RandomContext &Ctx, PLInt A, int32_t Bytes)
{
	SBCheckError(SBMath_LRandom(&Ctx, A, Bytes));
}

bool MathOperationCanceled(TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMath_MathOperationCanceled(pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_MATH */

};	/* namespace SecureBlackbox */

