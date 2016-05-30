#include "sbgost2814789.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGOST

SB_INLINE int32_t TElGOST::BlockSize()
{
	int32_t OutResult;
	SBCheckError(TElGOST_BlockSize(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGOST::BlockSize_Inst()
{
	int32_t OutResult;
	SBCheckError(TElGOST_BlockSize_1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGOST::KeySize()
{
	int32_t OutResult;
	SBCheckError(TElGOST_KeySize(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGOST::KeySize_Inst()
{
	int32_t OutResult;
	SBCheckError(TElGOST_KeySize_1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGOST::Reset()
{
	SBCheckError(TElGOST_Reset(_Handle));
}

SB_INLINE void TElGOST::Clone(TElGOSTBase &Source)
{
	SBCheckError(TElGOST_Clone(_Handle, Source.getHandle()));
}

SB_INLINE void TElGOST::Clone(TElGOSTBase *Source)
{
	SBCheckError(TElGOST_Clone(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElGOST::Encrypt_Block(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len, std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx)
{
	int32_t szOutBuf = (int32_t)OutBuf.size();
	uint32_t _err = TElGOST_Encrypt_Block(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuf), (int32_t)InBuf.size(), In_StartIdx, In_Len, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf, &Out_Len, Out_StartIdx);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuf.resize(szOutBuf);
		SBCheckError(SBGetLastReturnBuffer(78299221, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf));
	}
	else
		SBCheckError(_err);

	OutBuf.resize(szOutBuf);
}

void TElGOST::Decrypt_Block(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len, std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx)
{
	int32_t szOutBuf = (int32_t)OutBuf.size();
	uint32_t _err = TElGOST_Decrypt_Block(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuf), (int32_t)InBuf.size(), In_StartIdx, In_Len, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf, &Out_Len, Out_StartIdx);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuf.resize(szOutBuf);
		SBCheckError(SBGetLastReturnBuffer(-1442324031, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf));
	}
	else
		SBCheckError(_err);

	OutBuf.resize(szOutBuf);
}

void TElGOST::Encrypt_Finalize(std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx)
{
	int32_t szOutBuf = (int32_t)OutBuf.size();
	uint32_t _err = TElGOST_Encrypt_Finalize(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf, &Out_Len, Out_StartIdx);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuf.resize(szOutBuf);
		SBCheckError(SBGetLastReturnBuffer(-2106255286, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf));
	}
	else
		SBCheckError(_err);

	OutBuf.resize(szOutBuf);
}

void TElGOST::Decrypt_Finalize(std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx)
{
	int32_t szOutBuf = (int32_t)OutBuf.size();
	uint32_t _err = TElGOST_Decrypt_Finalize(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf, &Out_Len, Out_StartIdx);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuf.resize(szOutBuf);
		SBCheckError(SBGetLastReturnBuffer(-314958895, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf));
	}
	else
		SBCheckError(_err);

	OutBuf.resize(szOutBuf);
}

void TElGOST::EncryptBuf(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len, std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx)
{
	int32_t szOutBuf = (int32_t)OutBuf.size();
	uint32_t _err = TElGOST_EncryptBuf(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuf), (int32_t)InBuf.size(), In_StartIdx, In_Len, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf, &Out_Len, Out_StartIdx);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuf.resize(szOutBuf);
		SBCheckError(SBGetLastReturnBuffer(-202440874, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf));
	}
	else
		SBCheckError(_err);

	OutBuf.resize(szOutBuf);
}

void TElGOST::EncryptBuf(const std::vector<uint8_t> &InBuf, std::vector<uint8_t> &OutBuf)
{
	int32_t szOutBuf = (int32_t)OutBuf.size();
	uint32_t _err = TElGOST_EncryptBuf_1(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuf), (int32_t)InBuf.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuf.resize(szOutBuf);
		SBCheckError(SBGetLastReturnBuffer(1005220696, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf));
	}
	else
		SBCheckError(_err);

	OutBuf.resize(szOutBuf);
}

void TElGOST::DecryptBuf(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len, std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx)
{
	int32_t szOutBuf = (int32_t)OutBuf.size();
	uint32_t _err = TElGOST_DecryptBuf(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuf), (int32_t)InBuf.size(), In_StartIdx, In_Len, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf, &Out_Len, Out_StartIdx);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuf.resize(szOutBuf);
		SBCheckError(SBGetLastReturnBuffer(275298653, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf));
	}
	else
		SBCheckError(_err);

	OutBuf.resize(szOutBuf);
}

void TElGOST::DecryptBuf(const std::vector<uint8_t> &InBuf, std::vector<uint8_t> &OutBuf)
{
	int32_t szOutBuf = (int32_t)OutBuf.size();
	uint32_t _err = TElGOST_DecryptBuf_1(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuf), (int32_t)InBuf.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuf.resize(szOutBuf);
		SBCheckError(SBGetLastReturnBuffer(816127140, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuf), &szOutBuf));
	}
	else
		SBCheckError(_err);

	OutBuf.resize(szOutBuf);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGOST::EncryptStream(TStream &Source, uint32_t Count, TStream &Dest)
{
	SBCheckError(TElGOST_EncryptStream(_Handle, Source.getHandle(), Count, Dest.getHandle()));
}

SB_INLINE void TElGOST::EncryptStream(TStream *Source, uint32_t Count, TStream *Dest)
{
	SBCheckError(TElGOST_EncryptStream(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Count, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGOST::DecryptStream(TStream &Source, uint32_t Count, TStream &Dest)
{
	SBCheckError(TElGOST_DecryptStream(_Handle, Source.getHandle(), Count, Dest.getHandle()));
}

SB_INLINE void TElGOST::DecryptStream(TStream *Source, uint32_t Count, TStream *Dest)
{
	SBCheckError(TElGOST_DecryptStream(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Count, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElGOST::MAC_Block(void * InBuf, int32_t In_Len)
{
	SBCheckError(TElGOST_MAC_Block(_Handle, InBuf, In_Len));
}

SB_INLINE void TElGOST::MAC_Block(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len)
{
	SBCheckError(TElGOST_MAC_Block_1(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuf), (int32_t)InBuf.size(), In_StartIdx, In_Len));
}

void TElGOST::MAC_Finalize(int32_t Qnt_Bits, std::vector<uint8_t> &MAC)
{
	int32_t szMAC = (int32_t)MAC.size();
	uint32_t _err = TElGOST_MAC_Finalize(_Handle, Qnt_Bits, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MAC), &szMAC);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MAC.resize(szMAC);
		SBCheckError(SBGetLastReturnBuffer(709150818, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MAC), &szMAC));
	}
	else
		SBCheckError(_err);

	MAC.resize(szMAC);
}

#ifdef SB_USE_CLASS_TSTREAM
void TElGOST::MAC_Stream(TStream &Source, uint32_t Count, int32_t Qnt_Bits, std::vector<uint8_t> &MAC)
{
	int32_t szMAC = (int32_t)MAC.size();
	uint32_t _err = TElGOST_MAC_Stream(_Handle, Source.getHandle(), Count, Qnt_Bits, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MAC), &szMAC);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MAC.resize(szMAC);
		SBCheckError(SBGetLastReturnBuffer(-1559102780, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MAC), &szMAC));
	}
	else
		SBCheckError(_err);

	MAC.resize(szMAC);
}

void TElGOST::MAC_Stream(TStream *Source, uint32_t Count, int32_t Qnt_Bits, std::vector<uint8_t> &MAC)
{
	int32_t szMAC = (int32_t)MAC.size();
	uint32_t _err = TElGOST_MAC_Stream(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Count, Qnt_Bits, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MAC), &szMAC);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MAC.resize(szMAC);
		SBCheckError(SBGetLastReturnBuffer(-1559102780, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MAC), &szMAC));
	}
	else
		SBCheckError(_err);

	MAC.resize(szMAC);
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElGOST::get_Key(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST_get_Key(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(284135723, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST::set_Key(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST_set_Key(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST::get_IV(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST_get_IV(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1207078281, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST::set_IV(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST_set_IV(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElGOSTMode TElGOST::get_Mode()
{
	TElGOSTModeRaw OutResultRaw = 0;
	SBCheckError(TElGOST_get_Mode(_Handle, &OutResultRaw));
	return (TElGOSTMode)OutResultRaw;
}

SB_INLINE void TElGOST::set_Mode(TElGOSTMode Value)
{
	SBCheckError(TElGOST_set_Mode(_Handle, (TElGOSTModeRaw)Value));
}

TElGOST::TElGOST(TElGOSTHandle handle, TElOwnHandle ownHandle) : TElGOSTBase(handle, ownHandle)
{
}

TElGOST::TElGOST() : TElGOSTBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST_Create(&_Handle));
}

TElGOST::TElGOST(const TElGostSubstBlock &SubstBlock) : TElGOSTBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST_Create_1(&SubstBlock, &_Handle));
}

#endif /* SB_USE_CLASS_TELGOST */

#ifdef SB_USE_GLOBAL_PROCS_GOST2814789

bool KeyWrap28147(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &CEK, const std::vector<uint8_t> &KEK, std::vector<uint8_t> &WCEK, int32_t &WCEKSize, std::vector<uint8_t> &CEK_MAC, int32_t &CEKMACSize)
{
	int32_t szWCEK = (int32_t)WCEK.size();
	int32_t szCEK_MAC = (int32_t)CEK_MAC.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBGOST2814789_KeyWrap28147(SB_STD_VECTOR_FRONT_ADR(UKM), (int32_t)UKM.size(), SB_STD_VECTOR_FRONT_ADR(CEK), (int32_t)CEK.size(), SB_STD_VECTOR_FRONT_ADR(KEK), (int32_t)KEK.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(WCEK), &szWCEK, &WCEKSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(CEK_MAC), &szCEK_MAC, &CEKMACSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		WCEK.resize(szWCEK);
		SBCheckError(SBGetLastReturnBuffer(32356514, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(WCEK), &szWCEK));
		CEK_MAC.resize(szCEK_MAC);
		SBCheckError(SBGetLastReturnBuffer(32356514, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(CEK_MAC), &szCEK_MAC));
	}
	else
		SBCheckError(_err);

	WCEK.resize(szWCEK);
	CEK_MAC.resize(szCEK_MAC);
	return (OutResultRaw != 0);
}

bool KeyUnwrap28147(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &WCEK, const std::vector<uint8_t> &KEK, const std::vector<uint8_t> &CEK_MAC, std::vector<uint8_t> &CEK, int32_t &CEKSize)
{
	int32_t szCEK = (int32_t)CEK.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBGOST2814789_KeyUnwrap28147(SB_STD_VECTOR_FRONT_ADR(UKM), (int32_t)UKM.size(), SB_STD_VECTOR_FRONT_ADR(WCEK), (int32_t)WCEK.size(), SB_STD_VECTOR_FRONT_ADR(KEK), (int32_t)KEK.size(), SB_STD_VECTOR_FRONT_ADR(CEK_MAC), (int32_t)CEK_MAC.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(CEK), &szCEK, &CEKSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		CEK.resize(szCEK);
		SBCheckError(SBGetLastReturnBuffer(-1839010316, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(CEK), &szCEK));
	}
	else
		SBCheckError(_err);

	CEK.resize(szCEK);
	return (OutResultRaw != 0);
}

bool KeyWrapCryptoPro(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &CEK, const std::vector<uint8_t> &KEK, std::vector<uint8_t> &WCEK, int32_t &WCEKSize, std::vector<uint8_t> &CEK_MAC, int32_t &CEKMACSize)
{
	int32_t szWCEK = (int32_t)WCEK.size();
	int32_t szCEK_MAC = (int32_t)CEK_MAC.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBGOST2814789_KeyWrapCryptoPro(SB_STD_VECTOR_FRONT_ADR(UKM), (int32_t)UKM.size(), SB_STD_VECTOR_FRONT_ADR(CEK), (int32_t)CEK.size(), SB_STD_VECTOR_FRONT_ADR(KEK), (int32_t)KEK.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(WCEK), &szWCEK, &WCEKSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(CEK_MAC), &szCEK_MAC, &CEKMACSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		WCEK.resize(szWCEK);
		SBCheckError(SBGetLastReturnBuffer(-994546735, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(WCEK), &szWCEK));
		CEK_MAC.resize(szCEK_MAC);
		SBCheckError(SBGetLastReturnBuffer(-994546735, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(CEK_MAC), &szCEK_MAC));
	}
	else
		SBCheckError(_err);

	WCEK.resize(szWCEK);
	CEK_MAC.resize(szCEK_MAC);
	return (OutResultRaw != 0);
}

bool KeyUnwrapCryptoPro(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &WCEK, const std::vector<uint8_t> &KEK, const std::vector<uint8_t> &CEK_MAC, std::vector<uint8_t> &CEK, int32_t &CEKSize)
{
	int32_t szCEK = (int32_t)CEK.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBGOST2814789_KeyUnwrapCryptoPro(SB_STD_VECTOR_FRONT_ADR(UKM), (int32_t)UKM.size(), SB_STD_VECTOR_FRONT_ADR(WCEK), (int32_t)WCEK.size(), SB_STD_VECTOR_FRONT_ADR(KEK), (int32_t)KEK.size(), SB_STD_VECTOR_FRONT_ADR(CEK_MAC), (int32_t)CEK_MAC.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(CEK), &szCEK, &CEKSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		CEK.resize(szCEK);
		SBCheckError(SBGetLastReturnBuffer(-1611021255, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(CEK), &szCEK));
	}
	else
		SBCheckError(_err);

	CEK.resize(szCEK);
	return (OutResultRaw != 0);
}

void gost28147IMIT(const std::vector<uint8_t> &IV, const std::vector<uint8_t> &K, const std::vector<uint8_t> &D, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBGOST2814789_gost28147IMIT(SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), SB_STD_VECTOR_FRONT_ADR(K), (int32_t)K.size(), SB_STD_VECTOR_FRONT_ADR(D), (int32_t)D.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-265326610, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool KeyDiversifyCryptoPro(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &KEK, std::vector<uint8_t> &DKEK, int32_t &DKEKSize)
{
	int32_t szDKEK = (int32_t)DKEK.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBGOST2814789_KeyDiversifyCryptoPro(SB_STD_VECTOR_FRONT_ADR(UKM), (int32_t)UKM.size(), SB_STD_VECTOR_FRONT_ADR(KEK), (int32_t)KEK.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(DKEK), &szDKEK, &DKEKSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DKEK.resize(szDKEK);
		SBCheckError(SBGetLastReturnBuffer(808986503, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(DKEK), &szDKEK));
	}
	else
		SBCheckError(_err);

	DKEK.resize(szDKEK);
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_GOST2814789 */

};	/* namespace SecureBlackbox */

