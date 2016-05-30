#include "sbchacha20.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_CHACHA20

SB_INLINE void QuarterRound(int32_t a, int32_t b, int32_t c, int32_t d, TSBChaCha20State &State)
{
	SBCheckError(SBChaCha20_QuarterRound(a, b, c, d, &State));
}

SB_INLINE void InnerBlock(TSBChaCha20State &State)
{
	SBCheckError(SBChaCha20_InnerBlock(&State));
}

void ChaCha20Block(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, uint32_t Counter, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBChaCha20_ChaCha20Block(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), Counter, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1503672178, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ChaCha20Encrypt(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, uint32_t Counter, const std::vector<uint8_t> &Msg, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBChaCha20_ChaCha20Encrypt(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), Counter, SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-946546312, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ChaCha20Decrypt(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, uint32_t Counter, const std::vector<uint8_t> &Msg, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBChaCha20_ChaCha20Decrypt(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), Counter, SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2003403102, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Poly1305KeyGen(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBChaCha20_Poly1305KeyGen(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(527109665, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void AEADEncrypt(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, const std::vector<uint8_t> &Msg, const std::vector<uint8_t> &AAD, TSBPoly1305Mode Mode, TSBPoly1305Tag &Tag, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBChaCha20_AEADEncrypt(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), SB_STD_VECTOR_FRONT_ADR(AAD), (int32_t)AAD.size(), (TSBPoly1305ModeRaw)Mode, &Tag, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(475517173, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool AEADDecrypt(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, const std::vector<uint8_t> &EMsg, const std::vector<uint8_t> &AAD, const TSBPoly1305Tag &Tag, TSBPoly1305Mode Mode, std::vector<uint8_t> &DMsg)
{
	int32_t szDMsg = (int32_t)DMsg.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBChaCha20_AEADDecrypt(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), SB_STD_VECTOR_FRONT_ADR(EMsg), (int32_t)EMsg.size(), SB_STD_VECTOR_FRONT_ADR(AAD), (int32_t)AAD.size(), &Tag, (TSBPoly1305ModeRaw)Mode, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(DMsg), &szDMsg, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DMsg.resize(szDMsg);
		SBCheckError(SBGetLastReturnBuffer(-536313408, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(DMsg), &szDMsg));
	}
	else
		SBCheckError(_err);

	DMsg.resize(szDMsg);
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_CHACHA20 */

};	/* namespace SecureBlackbox */

