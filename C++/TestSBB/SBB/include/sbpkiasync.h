#ifndef __INC_SBPKIASYNC
#define __INC_SBPKIASYNC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbelgamal.h"
#include "sbdsa.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbmath.h"
#include "sbrsa.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPublicKeyAsyncCalculatorHandle;

typedef TElClassHandle TElPublicKeyComputationTokenHandle;

typedef uint8_t TSBPublicKeyComputationTokenTypeRaw;

typedef enum
{
	ttElgamalEncrypt = 0,
	ttElgamalSign = 1,
	ttDSASign = 2,
	ttPrimeGeneration = 3,
	ttDSAGeneration = 4,
	ttRSAGeneration = 5,
	ttElgamalGeneration = 6
} TSBPublicKeyComputationTokenType;

#ifdef SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_BeginElgamalEncryption(TElPublicKeyAsyncCalculatorHandle _Handle, PLInt P, PLInt G, PLInt Y, TElPublicKeyComputationTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndElgamalEncryption(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, PLInt Src, PLInt A, PLInt B);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_BeginElgamalSigning(TElPublicKeyAsyncCalculatorHandle _Handle, PLInt P, PLInt G, TElPublicKeyComputationTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndElgamalSigning(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, PLInt X, PLInt Src, PLInt A, PLInt B);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_BeginPrimeGeneration(TElPublicKeyAsyncCalculatorHandle _Handle, int32_t Bits, TElPublicKeyComputationTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndPrimeGeneration(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, PLInt Prime);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_BeginDSASigning(TElPublicKeyAsyncCalculatorHandle _Handle, PLInt P, PLInt Q, PLInt G, TElPublicKeyComputationTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndDSASigning(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, PLInt X, void * Hash, int32_t HashSize, PLInt R, PLInt S);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_BeginRSAGeneration(TElPublicKeyAsyncCalculatorHandle _Handle, int32_t Bits, TElPublicKeyComputationTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndRSAGeneration(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, PLInt M, PLInt PrivE, PLInt PubE, PLInt Prime1, PLInt Prime2, PLInt Exp1, PLInt Exp2, PLInt Coeff);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndRSAGeneration_1(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, void * Blob, int32_t * BlobSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_BeginDSAGeneration(TElPublicKeyAsyncCalculatorHandle _Handle, int32_t Bits, TElPublicKeyComputationTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndDSAGeneration(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, PLInt P, PLInt Q, PLInt G, PLInt X, PLInt Y);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndDSAGeneration_1(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, void * Blob, int32_t * BlobSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_BeginElgamalGeneration(TElPublicKeyAsyncCalculatorHandle _Handle, int32_t Bits, TElPublicKeyComputationTokenHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_EndElgamalGeneration(TElPublicKeyAsyncCalculatorHandle _Handle, TElPublicKeyComputationTokenHandle Token, PLInt P, PLInt G, PLInt X, PLInt Y);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_get_Priority(TElPublicKeyAsyncCalculatorHandle _Handle, TThreadPriorityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_set_Priority(TElPublicKeyAsyncCalculatorHandle _Handle, TThreadPriorityRaw Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyAsyncCalculator_Create(TComponentHandle AOwner, TElPublicKeyAsyncCalculatorHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyComputationToken_Cancel(TElPublicKeyComputationTokenHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyComputationToken_get_TokenType(TElPublicKeyComputationTokenHandle _Handle, TSBPublicKeyComputationTokenTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyComputationToken_get_Finished(TElPublicKeyComputationTokenHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyComputationToken_get_Data(TElPublicKeyComputationTokenHandle _Handle, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyComputationToken_set_Data(TElPublicKeyComputationTokenHandle _Handle, void * Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeyComputationToken_Create(TSBPublicKeyComputationTokenTypeRaw TokenType, TElPublicKeyAsyncCalculatorHandle Owner, TElPublicKeyComputationTokenHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPublicKeyAsyncCalculator;
class TElPublicKeyComputationToken;

#ifdef SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR
class TElPublicKeyAsyncCalculator: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPublicKeyAsyncCalculator)
	public:
#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		TElPublicKeyComputationTokenHandle BeginElgamalEncryption(PLInt P, PLInt G, PLInt Y);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		void EndElgamalEncryption(TElPublicKeyComputationToken &Token, PLInt Src, PLInt A, PLInt B);

		void EndElgamalEncryption(TElPublicKeyComputationToken *Token, PLInt Src, PLInt A, PLInt B);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		TElPublicKeyComputationTokenHandle BeginElgamalSigning(PLInt P, PLInt G);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		void EndElgamalSigning(TElPublicKeyComputationToken &Token, PLInt X, PLInt Src, PLInt A, PLInt B);

		void EndElgamalSigning(TElPublicKeyComputationToken *Token, PLInt X, PLInt Src, PLInt A, PLInt B);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		TElPublicKeyComputationTokenHandle BeginPrimeGeneration(int32_t Bits);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		void EndPrimeGeneration(TElPublicKeyComputationToken &Token, PLInt Prime);

		void EndPrimeGeneration(TElPublicKeyComputationToken *Token, PLInt Prime);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		TElPublicKeyComputationTokenHandle BeginDSASigning(PLInt P, PLInt Q, PLInt G);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		void EndDSASigning(TElPublicKeyComputationToken &Token, PLInt X, void * Hash, int32_t HashSize, PLInt R, PLInt S);

		void EndDSASigning(TElPublicKeyComputationToken *Token, PLInt X, void * Hash, int32_t HashSize, PLInt R, PLInt S);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		TElPublicKeyComputationTokenHandle BeginRSAGeneration(int32_t Bits);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		void EndRSAGeneration(TElPublicKeyComputationToken &Token, PLInt M, PLInt PrivE, PLInt PubE, PLInt Prime1, PLInt Prime2, PLInt Exp1, PLInt Exp2, PLInt Coeff);

		void EndRSAGeneration(TElPublicKeyComputationToken *Token, PLInt M, PLInt PrivE, PLInt PubE, PLInt Prime1, PLInt Prime2, PLInt Exp1, PLInt Exp2, PLInt Coeff);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		bool EndRSAGeneration(TElPublicKeyComputationToken &Token, void * Blob, int32_t &BlobSize);

		bool EndRSAGeneration(TElPublicKeyComputationToken *Token, void * Blob, int32_t &BlobSize);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		TElPublicKeyComputationTokenHandle BeginDSAGeneration(int32_t Bits);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		void EndDSAGeneration(TElPublicKeyComputationToken &Token, PLInt P, PLInt Q, PLInt G, PLInt X, PLInt Y);

		void EndDSAGeneration(TElPublicKeyComputationToken *Token, PLInt P, PLInt Q, PLInt G, PLInt X, PLInt Y);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		bool EndDSAGeneration(TElPublicKeyComputationToken &Token, void * Blob, int32_t &BlobSize);

		bool EndDSAGeneration(TElPublicKeyComputationToken *Token, void * Blob, int32_t &BlobSize);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		TElPublicKeyComputationTokenHandle BeginElgamalGeneration(int32_t Bits);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
		void EndElgamalGeneration(TElPublicKeyComputationToken &Token, PLInt P, PLInt G, PLInt X, PLInt Y);

		void EndElgamalGeneration(TElPublicKeyComputationToken *Token, PLInt P, PLInt G, PLInt X, PLInt Y);
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_WINDOWS
		virtual TThreadPriority get_Priority();

		virtual void set_Priority(TThreadPriority Value);

		SB_DECLARE_PROPERTY(TThreadPriority, get_Priority, set_Priority, TElPublicKeyAsyncCalculator, Priority);
#endif

		TElPublicKeyAsyncCalculator(TElPublicKeyAsyncCalculatorHandle handle, TElOwnHandle ownHandle);

		explicit TElPublicKeyAsyncCalculator(TComponent &AOwner);

		explicit TElPublicKeyAsyncCalculator(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
class TElPublicKeyComputationToken: public TObject
{
	private:
		SB_DISABLE_COPY(TElPublicKeyComputationToken)
	public:
		void Cancel();

		virtual TSBPublicKeyComputationTokenType get_TokenType();

		SB_DECLARE_PROPERTY_GET(TSBPublicKeyComputationTokenType, get_TokenType, TElPublicKeyComputationToken, TokenType);

		virtual bool get_Finished();

		SB_DECLARE_PROPERTY_GET(bool, get_Finished, TElPublicKeyComputationToken, Finished);

		virtual void * get_Data();

		virtual void set_Data(void * Value);

		SB_DECLARE_PROPERTY(void *, get_Data, set_Data, TElPublicKeyComputationToken, Data);

		TElPublicKeyComputationToken(TElPublicKeyComputationTokenHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR
		TElPublicKeyComputationToken(TSBPublicKeyComputationTokenType TokenType, TElPublicKeyAsyncCalculator &Owner);

		TElPublicKeyComputationToken(TSBPublicKeyComputationTokenType TokenType, TElPublicKeyAsyncCalculator *Owner);
#endif /* SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR */

};
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_GLOBAL_PROCS_PKIASYNC

#ifdef SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR
TElPublicKeyAsyncCalculatorHandle GetGlobalAsyncCalculator();
#endif /* SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR */

#endif /* SB_USE_GLOBAL_PROCS_PKIASYNC */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PKIASYNC
SB_IMPORT uint32_t SB_APIENTRY SBPKIAsync_GetGlobalAsyncCalculator(TElPublicKeyAsyncCalculatorHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_PKIASYNC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKIASYNC */
