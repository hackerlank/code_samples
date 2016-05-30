#include "sbumac.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELUMAC

SB_INLINE TElUMACHandle TElUMAC::Clone()
{
	TElUMACHandle OutResult;
	SBCheckError(TElUMAC_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElUMAC::Reset()
{
	SBCheckError(TElUMAC_Reset(_Handle));
}

SB_INLINE void TElUMAC::Update(const std::vector<uint8_t> &In_Buf, uint32_t StartIndex, uint32_t Len)
{
	SBCheckError(TElUMAC_Update(_Handle, SB_STD_VECTOR_FRONT_ADR(In_Buf), (int32_t)In_Buf.size(), StartIndex, Len));
}

SB_INLINE void TElUMAC::Update(void * In_Buf, int32_t Size)
{
	SBCheckError(TElUMAC_Update_1(_Handle, In_Buf, Size));
}

void TElUMAC::Final_(const std::vector<uint8_t> &Nonce, std::vector<uint8_t> &Tag)
{
	int32_t szTag = (int32_t)Tag.size();
	uint32_t _err = TElUMAC_Final_(_Handle, SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Tag), &szTag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Tag.resize(szTag);
		SBCheckError(SBGetLastReturnBuffer(-1367165572, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Tag), &szTag));
	}
	else
		SBCheckError(_err);

	Tag.resize(szTag);
}

void TElUMAC::Calculate(const std::vector<uint8_t> &In_Buf, uint32_t StartIndex, uint32_t Len, const std::vector<uint8_t> &Nonce, std::vector<uint8_t> &Tag)
{
	int32_t szTag = (int32_t)Tag.size();
	uint32_t _err = TElUMAC_Calculate(_Handle, SB_STD_VECTOR_FRONT_ADR(In_Buf), (int32_t)In_Buf.size(), StartIndex, Len, SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Tag), &szTag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Tag.resize(szTag);
		SBCheckError(SBGetLastReturnBuffer(-1154190704, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Tag), &szTag));
	}
	else
		SBCheckError(_err);

	Tag.resize(szTag);
}

void TElUMAC::Calculate(void * In_Buf, uint32_t Len, const std::vector<uint8_t> &Nonce, std::vector<uint8_t> &Tag)
{
	int32_t szTag = (int32_t)Tag.size();
	uint32_t _err = TElUMAC_Calculate_1(_Handle, In_Buf, Len, SB_STD_VECTOR_FRONT_ADR(Nonce), (int32_t)Nonce.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Tag), &szTag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Tag.resize(szTag);
		SBCheckError(SBGetLastReturnBuffer(-1563207301, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Tag), &szTag));
	}
	else
		SBCheckError(_err);

	Tag.resize(szTag);
}

TElUMAC::TElUMAC(TElUMACHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElUMAC::TElUMAC(const std::vector<uint8_t> &Key, int32_t TagLen) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUMAC_Create(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), TagLen, &_Handle));
}

TElUMAC::TElUMAC(const std::string &Key, int32_t TagLen) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUMAC_Create_1(Key.data(), (int32_t)Key.length(), TagLen, &_Handle));
}

#endif /* SB_USE_CLASS_TELUMAC */

};	/* namespace SecureBlackbox */

