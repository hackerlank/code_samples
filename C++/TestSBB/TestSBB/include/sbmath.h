#ifndef __INC_SBMATH
#define __INC_SBMATH

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_MAXDIGIT 	768
#define SB_RandKeyLength 	2
#define SB_sNumberTooLarge 	"Number too large"
#define SB_sDivisionByZero 	"Division by zero"

#pragma pack(4)
typedef struct 
{
	uint8_t S[256];
	int32_t I;
	int32_t J;
} TRC4Random;

#pragma pack(4)
typedef struct 
{
	uint8_t S[256];
	int32_t I;
	int32_t J;
	int8_t RandomInit;
} TRC4RandomContext;

typedef void (SB_CALLBACK *TSBMathProgressFunc)(void * _ObjectData, void * Data, int8_t * OutResult);

#pragma pack(4)
typedef struct 
{
	int32_t Length;
	uint32_t Digits[768];
	int8_t Sign;
	int8_t Disposed;
} TLInt, * PLInt;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_MATH

void LShl(PLInt &Num);

void LShlEx(PLInt &Num, int32_t Bits);

void LShlNum(PLInt Src, PLInt Dest, int32_t Bits);

void LShr(PLInt &Num);

void LShrEx(PLInt &Num, int32_t Bits);

void LShrNum(PLInt X, PLInt &Res, uint32_t Bits);

void LShiftLeft(PLInt &A, uint32_t N);

void LAdd(PLInt A, PLInt B, PLInt C);

void LAdd(PLInt A, uint32_t B, PLInt C);

void LSub(PLInt A, PLInt B, PLInt &PTm);

void LSub(PLInt A, uint32_t B, PLInt &PTm);

void LDec(PLInt &A);

void LInc(PLInt &A);

void LMultSh(PLInt A, uint32_t B, PLInt Res);

void LMult(PLInt A, PLInt B, PLInt &Res);

void LModSh(PLInt A, uint32_t B, uint32_t &Res);

void LMod(PLInt X, PLInt N, PLInt &Res);

void LModEx(PLInt X, PLInt N, PLInt &Res);

void LDivSh(PLInt A, uint32_t B, PLInt Q, PLInt R);

void LDiv(PLInt A, PLInt B, PLInt &C, PLInt &D);

void LModPower(PLInt A, PLInt E, PLInt N, PLInt &Res);

void LMontgomery(PLInt A, PLInt B, PLInt N, PLInt &Res);

void LGCD(PLInt B, PLInt A, PLInt &C, PLInt &D);

void LSwap(PLInt &A, PLInt &B);

uint32_t LBitCount(PLInt A);

bool LBitSet(PLInt A, int32_t n);

void LSetBit(PLInt &A, int32_t n, bool Value);

void LBitTruncate(PLInt &A, int32_t Bits);

bool LGreater(PLInt A, PLInt B);

bool LEqual(PLInt A, PLInt B);

bool LEven(PLInt A);

bool LNull(PLInt A);

void LCopy(PLInt &P, PLInt A);

void LZero(PLInt &A);

void LToStr(PLInt A, std::string &OutResult);

void LToBase64(PLInt A, std::string &OutResult);

void LInit(PLInt &P, const std::string &Num);

void LInit(PLInt &P, uint32_t Num);

void LInit(PLInt &P, int64_t Num);

void LGenerate(PLInt &R, int32_t Len);

void LCreate(PLInt &A);

void LDestroy(PLInt &P);

void LTrim(PLInt &A);

void LSanitize(PLInt &A, int32_t Digits);

int32_t HexToDecDigit(char A);

char DecToHexDigit(int32_t A);

void DecToHex(uint32_t A, std::string &OutResult);

void LBAddPowB(PLInt Src, PLInt Dest, uint32_t Bases);

void LBM(PLInt SrcMod, PLInt Dest, uint32_t Bits);

void LBDivPowB(PLInt Src, PLInt Dest, uint32_t Bases);

void LBModPowB(PLInt Src, PLInt Dest, uint32_t Bases);

void LBMul(PLInt SrcA, PLInt SrcB, PLInt Dest, uint32_t FromBases, uint32_t ToBases);

void LBMod(PLInt Src, PLInt SrcMod, PLInt SrcM, PLInt &Dest, uint32_t Bits);

void LBPowMod(PLInt SrcA, PLInt SrcB, PLInt SrcMod, PLInt &Dest, PLInt ModInv);

void LMMul(PLInt A, PLInt B, PLInt N, PLInt &Res);

void LMModPower(PLInt X, PLInt E, PLInt N, PLInt &Res, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel);

bool LRabinMillerPrimeTest(PLInt P, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel);

bool LIsPrime(PLInt P, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel);

void LGenPrime(PLInt P, int32_t Len, bool RSAPrime, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel);

void LGenPrimeEx(PLInt P, int32_t Bits, bool RSAPrime, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, bool RaiseExceptionOnCancel);

void LRC4Randomize(TRC4RandomContext &Ctx, PLInt Key);

void LRC4Init(TRC4RandomContext &Ctx);

uint8_t LRC4RandomByte(TRC4RandomContext &Ctx);

void LRandom(TRC4RandomContext &Ctx, PLInt A, int32_t Bytes);

bool MathOperationCanceled(TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

#endif /* SB_USE_GLOBAL_PROCS_MATH */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_MATH
SB_IMPORT uint32_t SB_APIENTRY SBMath_LShl(PLInt * Num);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LShlEx(PLInt * Num, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LShlNum(PLInt Src, PLInt Dest, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LShr(PLInt * Num);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LShrEx(PLInt * Num, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LShrNum(PLInt X, PLInt * Res, uint32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LShiftLeft(PLInt * A, uint32_t N);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LAdd(PLInt A, PLInt B, PLInt C);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LAdd_1(PLInt A, uint32_t B, PLInt C);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LSub(PLInt A, PLInt B, PLInt * PTm);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LSub_1(PLInt A, uint32_t B, PLInt * PTm);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LDec(PLInt * A);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LInc(PLInt * A);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LMultSh(PLInt A, uint32_t B, PLInt Res);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LMult(PLInt A, PLInt B, PLInt * Res);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LModSh(PLInt A, uint32_t B, uint32_t * Res);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LMod(PLInt X, PLInt N, PLInt * Res);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LModEx(PLInt X, PLInt N, PLInt * Res);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LDivSh(PLInt A, uint32_t B, PLInt Q, PLInt R);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LDiv(PLInt A, PLInt B, PLInt * C, PLInt * D);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LModPower(PLInt A, PLInt E, PLInt N, PLInt * Res);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LMontgomery(PLInt A, PLInt B, PLInt N, PLInt * Res);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LGCD(PLInt B, PLInt A, PLInt * C, PLInt * D);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LSwap(PLInt * A, PLInt * B);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBitCount(PLInt A, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBitSet(PLInt A, int32_t n, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LSetBit(PLInt * A, int32_t n, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBitTruncate(PLInt * A, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LGreater(PLInt A, PLInt B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LEqual(PLInt A, PLInt B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LEven(PLInt A, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LNull(PLInt A, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LCopy(PLInt * P, PLInt A);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LZero(PLInt * A);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LToStr(PLInt A, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LToBase64(PLInt A, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LInit(PLInt * P, const char * pcNum, int32_t szNum);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LInit_1(PLInt * P, uint32_t Num);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LInit_2(PLInt * P, int64_t Num);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LGenerate(PLInt * R, int32_t Len);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LCreate(PLInt * A);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LDestroy(PLInt * P);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LTrim(PLInt * A);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LSanitize(PLInt * A, int32_t Digits);
SB_IMPORT uint32_t SB_APIENTRY SBMath_HexToDecDigit(char A, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_DecToHexDigit(int32_t A, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_DecToHex(uint32_t A, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBAddPowB(PLInt Src, PLInt Dest, uint32_t Bases);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBM(PLInt SrcMod, PLInt Dest, uint32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBDivPowB(PLInt Src, PLInt Dest, uint32_t Bases);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBModPowB(PLInt Src, PLInt Dest, uint32_t Bases);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBMul(PLInt SrcA, PLInt SrcB, PLInt Dest, uint32_t FromBases, uint32_t ToBases);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBMod(PLInt Src, PLInt SrcMod, PLInt SrcM, PLInt * Dest, uint32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LBPowMod(PLInt SrcA, PLInt SrcB, PLInt SrcMod, PLInt * Dest, PLInt ModInv);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LMMul(PLInt A, PLInt B, PLInt N, PLInt * Res);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LMModPower(PLInt X, PLInt E, PLInt N, PLInt * Res, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t RaiseExceptionOnCancel);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LRabinMillerPrimeTest(PLInt P, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t RaiseExceptionOnCancel, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LIsPrime(PLInt P, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t RaiseExceptionOnCancel, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LGenPrime(PLInt P, int32_t Len, int8_t RSAPrime, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t RaiseExceptionOnCancel);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LGenPrimeEx(PLInt P, int32_t Bits, int8_t RSAPrime, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t RaiseExceptionOnCancel);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LRC4Randomize(TRC4RandomContext * Ctx, PLInt Key);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LRC4Init(TRC4RandomContext * Ctx);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LRC4RandomByte(TRC4RandomContext * Ctx, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMath_LRandom(TRC4RandomContext * Ctx, PLInt A, int32_t Bytes);
SB_IMPORT uint32_t SB_APIENTRY SBMath_MathOperationCanceled(TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_MATH */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBMATH */

