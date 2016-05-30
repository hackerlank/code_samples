#include "sbpkiasync.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE TElPublicKeyComputationTokenHandle TElPublicKeyAsyncCalculator::BeginElgamalEncryption(PLInt P, PLInt G, PLInt Y)
{
	TElPublicKeyComputationTokenHandle OutResult;
	SBCheckError(TElPublicKeyAsyncCalculator_BeginElgamalEncryption(_Handle, P, G, Y, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE void TElPublicKeyAsyncCalculator::EndElgamalEncryption(TElPublicKeyComputationToken &Token, PLInt Src, PLInt A, PLInt B)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndElgamalEncryption(_Handle, Token.getHandle(), Src, A, B));
}

SB_INLINE void TElPublicKeyAsyncCalculator::EndElgamalEncryption(TElPublicKeyComputationToken *Token, PLInt Src, PLInt A, PLInt B)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndElgamalEncryption(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, Src, A, B));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE TElPublicKeyComputationTokenHandle TElPublicKeyAsyncCalculator::BeginElgamalSigning(PLInt P, PLInt G)
{
	TElPublicKeyComputationTokenHandle OutResult;
	SBCheckError(TElPublicKeyAsyncCalculator_BeginElgamalSigning(_Handle, P, G, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE void TElPublicKeyAsyncCalculator::EndElgamalSigning(TElPublicKeyComputationToken &Token, PLInt X, PLInt Src, PLInt A, PLInt B)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndElgamalSigning(_Handle, Token.getHandle(), X, Src, A, B));
}

SB_INLINE void TElPublicKeyAsyncCalculator::EndElgamalSigning(TElPublicKeyComputationToken *Token, PLInt X, PLInt Src, PLInt A, PLInt B)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndElgamalSigning(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, X, Src, A, B));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE TElPublicKeyComputationTokenHandle TElPublicKeyAsyncCalculator::BeginPrimeGeneration(int32_t Bits)
{
	TElPublicKeyComputationTokenHandle OutResult;
	SBCheckError(TElPublicKeyAsyncCalculator_BeginPrimeGeneration(_Handle, Bits, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE void TElPublicKeyAsyncCalculator::EndPrimeGeneration(TElPublicKeyComputationToken &Token, PLInt Prime)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndPrimeGeneration(_Handle, Token.getHandle(), Prime));
}

SB_INLINE void TElPublicKeyAsyncCalculator::EndPrimeGeneration(TElPublicKeyComputationToken *Token, PLInt Prime)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndPrimeGeneration(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, Prime));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE TElPublicKeyComputationTokenHandle TElPublicKeyAsyncCalculator::BeginDSASigning(PLInt P, PLInt Q, PLInt G)
{
	TElPublicKeyComputationTokenHandle OutResult;
	SBCheckError(TElPublicKeyAsyncCalculator_BeginDSASigning(_Handle, P, Q, G, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE void TElPublicKeyAsyncCalculator::EndDSASigning(TElPublicKeyComputationToken &Token, PLInt X, void * Hash, int32_t HashSize, PLInt R, PLInt S)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndDSASigning(_Handle, Token.getHandle(), X, Hash, HashSize, R, S));
}

SB_INLINE void TElPublicKeyAsyncCalculator::EndDSASigning(TElPublicKeyComputationToken *Token, PLInt X, void * Hash, int32_t HashSize, PLInt R, PLInt S)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndDSASigning(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, X, Hash, HashSize, R, S));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE TElPublicKeyComputationTokenHandle TElPublicKeyAsyncCalculator::BeginRSAGeneration(int32_t Bits)
{
	TElPublicKeyComputationTokenHandle OutResult;
	SBCheckError(TElPublicKeyAsyncCalculator_BeginRSAGeneration(_Handle, Bits, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE void TElPublicKeyAsyncCalculator::EndRSAGeneration(TElPublicKeyComputationToken &Token, PLInt M, PLInt PrivE, PLInt PubE, PLInt Prime1, PLInt Prime2, PLInt Exp1, PLInt Exp2, PLInt Coeff)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndRSAGeneration(_Handle, Token.getHandle(), M, PrivE, PubE, Prime1, Prime2, Exp1, Exp2, Coeff));
}

SB_INLINE void TElPublicKeyAsyncCalculator::EndRSAGeneration(TElPublicKeyComputationToken *Token, PLInt M, PLInt PrivE, PLInt PubE, PLInt Prime1, PLInt Prime2, PLInt Exp1, PLInt Exp2, PLInt Coeff)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndRSAGeneration(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, M, PrivE, PubE, Prime1, Prime2, Exp1, Exp2, Coeff));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
bool TElPublicKeyAsyncCalculator::EndRSAGeneration(TElPublicKeyComputationToken &Token, void * Blob, int32_t &BlobSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyAsyncCalculator_EndRSAGeneration_1(_Handle, Token.getHandle(), Blob, &BlobSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPublicKeyAsyncCalculator::EndRSAGeneration(TElPublicKeyComputationToken *Token, void * Blob, int32_t &BlobSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyAsyncCalculator_EndRSAGeneration_1(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, Blob, &BlobSize, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE TElPublicKeyComputationTokenHandle TElPublicKeyAsyncCalculator::BeginDSAGeneration(int32_t Bits)
{
	TElPublicKeyComputationTokenHandle OutResult;
	SBCheckError(TElPublicKeyAsyncCalculator_BeginDSAGeneration(_Handle, Bits, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE void TElPublicKeyAsyncCalculator::EndDSAGeneration(TElPublicKeyComputationToken &Token, PLInt P, PLInt Q, PLInt G, PLInt X, PLInt Y)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndDSAGeneration(_Handle, Token.getHandle(), P, Q, G, X, Y));
}

SB_INLINE void TElPublicKeyAsyncCalculator::EndDSAGeneration(TElPublicKeyComputationToken *Token, PLInt P, PLInt Q, PLInt G, PLInt X, PLInt Y)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndDSAGeneration(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, P, Q, G, X, Y));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
bool TElPublicKeyAsyncCalculator::EndDSAGeneration(TElPublicKeyComputationToken &Token, void * Blob, int32_t &BlobSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyAsyncCalculator_EndDSAGeneration_1(_Handle, Token.getHandle(), Blob, &BlobSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPublicKeyAsyncCalculator::EndDSAGeneration(TElPublicKeyComputationToken *Token, void * Blob, int32_t &BlobSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyAsyncCalculator_EndDSAGeneration_1(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, Blob, &BlobSize, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE TElPublicKeyComputationTokenHandle TElPublicKeyAsyncCalculator::BeginElgamalGeneration(int32_t Bits)
{
	TElPublicKeyComputationTokenHandle OutResult;
	SBCheckError(TElPublicKeyAsyncCalculator_BeginElgamalGeneration(_Handle, Bits, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN
SB_INLINE void TElPublicKeyAsyncCalculator::EndElgamalGeneration(TElPublicKeyComputationToken &Token, PLInt P, PLInt G, PLInt X, PLInt Y)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndElgamalGeneration(_Handle, Token.getHandle(), P, G, X, Y));
}

SB_INLINE void TElPublicKeyAsyncCalculator::EndElgamalGeneration(TElPublicKeyComputationToken *Token, PLInt P, PLInt G, PLInt X, PLInt Y)
{
	SBCheckError(TElPublicKeyAsyncCalculator_EndElgamalGeneration(_Handle, (Token != NULL) ? Token->getHandle() : SB_NULL_HANDLE, P, G, X, Y));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_WINDOWS
TThreadPriority TElPublicKeyAsyncCalculator::get_Priority()
{
	TThreadPriorityRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyAsyncCalculator_get_Priority(_Handle, &OutResultRaw));
	return (TThreadPriority)OutResultRaw;
}

SB_INLINE void TElPublicKeyAsyncCalculator::set_Priority(TThreadPriority Value)
{
	SBCheckError(TElPublicKeyAsyncCalculator_set_Priority(_Handle, (TThreadPriorityRaw)Value));
}
#endif

TElPublicKeyAsyncCalculator::TElPublicKeyAsyncCalculator(TElPublicKeyAsyncCalculatorHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElPublicKeyAsyncCalculator::TElPublicKeyAsyncCalculator(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyAsyncCalculator_Create(AOwner.getHandle(), &_Handle));
}

TElPublicKeyAsyncCalculator::TElPublicKeyAsyncCalculator(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyAsyncCalculator_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR */

#ifdef SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN

SB_INLINE void TElPublicKeyComputationToken::Cancel()
{
	SBCheckError(TElPublicKeyComputationToken_Cancel(_Handle));
}

TSBPublicKeyComputationTokenType TElPublicKeyComputationToken::get_TokenType()
{
	TSBPublicKeyComputationTokenTypeRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeyComputationToken_get_TokenType(_Handle, &OutResultRaw));
	return (TSBPublicKeyComputationTokenType)OutResultRaw;
}

bool TElPublicKeyComputationToken::get_Finished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicKeyComputationToken_get_Finished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void * TElPublicKeyComputationToken::get_Data()
{
	void * OutResult;
	SBCheckError(TElPublicKeyComputationToken_get_Data(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPublicKeyComputationToken::set_Data(void * Value)
{
	SBCheckError(TElPublicKeyComputationToken_set_Data(_Handle, Value));
}

TElPublicKeyComputationToken::TElPublicKeyComputationToken(TElPublicKeyComputationTokenHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR
TElPublicKeyComputationToken::TElPublicKeyComputationToken(TSBPublicKeyComputationTokenType TokenType, TElPublicKeyAsyncCalculator &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyComputationToken_Create((TSBPublicKeyComputationTokenTypeRaw)TokenType, Owner.getHandle(), &_Handle));
}

TElPublicKeyComputationToken::TElPublicKeyComputationToken(TSBPublicKeyComputationTokenType TokenType, TElPublicKeyAsyncCalculator *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPublicKeyComputationToken_Create((TSBPublicKeyComputationTokenTypeRaw)TokenType, (Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR */

#endif /* SB_USE_CLASS_TELPUBLICKEYCOMPUTATIONTOKEN */

#ifdef SB_USE_GLOBAL_PROCS_PKIASYNC

#ifdef SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR
SB_INLINE TElPublicKeyAsyncCalculatorHandle GetGlobalAsyncCalculator()
{
	TElPublicKeyAsyncCalculatorHandle OutResult;
	SBCheckError(SBPKIAsync_GetGlobalAsyncCalculator(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYASYNCCALCULATOR */

#endif /* SB_USE_GLOBAL_PROCS_PKIASYNC */

};	/* namespace SecureBlackbox */
