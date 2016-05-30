#include "sbgost341194.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGOSTMD

SB_INLINE int32_t TElGOSTMD::DigestSize()
{
	int32_t OutResult;
	SBCheckError(TElGOSTMD_DigestSize(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElGOSTMD::DigestSize_Inst()
{
	int32_t OutResult;
	SBCheckError(TElGOSTMD_DigestSize_1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGOSTMD::Reset()
{
	SBCheckError(TElGOSTMD_Reset(_Handle));
}

SB_INLINE void TElGOSTMD::Clone(TElGOSTBase &Source)
{
	SBCheckError(TElGOSTMD_Clone(_Handle, Source.getHandle()));
}

SB_INLINE void TElGOSTMD::Clone(TElGOSTBase *Source)
{
	SBCheckError(TElGOSTMD_Clone(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGOSTMD::Update(void * In_Buf, uint32_t Len)
{
	SBCheckError(TElGOSTMD_Update(_Handle, In_Buf, Len));
}

SB_INLINE void TElGOSTMD::Update(const std::vector<uint8_t> &In_Buf, uint32_t StartIndex, uint32_t Len)
{
	SBCheckError(TElGOSTMD_Update_1(_Handle, SB_STD_VECTOR_FRONT_ADR(In_Buf), (int32_t)In_Buf.size(), StartIndex, Len));
}

void TElGOSTMD::Final(std::vector<uint8_t> &Digest)
{
	int32_t szDigest = (int32_t)Digest.size();
	uint32_t _err = TElGOSTMD_Final(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Digest), &szDigest);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Digest.resize(szDigest);
		SBCheckError(SBGetLastReturnBuffer(-409579556, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Digest), &szDigest));
	}
	else
		SBCheckError(_err);

	Digest.resize(szDigest);
}

void TElGOSTMD::Calculate(const std::vector<uint8_t> &In_Buf, uint32_t StartIndex, uint32_t Len, std::vector<uint8_t> &Digest)
{
	int32_t szDigest = (int32_t)Digest.size();
	uint32_t _err = TElGOSTMD_Calculate(_Handle, SB_STD_VECTOR_FRONT_ADR(In_Buf), (int32_t)In_Buf.size(), StartIndex, Len, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Digest), &szDigest);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Digest.resize(szDigest);
		SBCheckError(SBGetLastReturnBuffer(-797096280, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Digest), &szDigest));
	}
	else
		SBCheckError(_err);

	Digest.resize(szDigest);
}

#ifdef SB_USE_CLASS_TSTREAM
void TElGOSTMD::Calculate(TStream &Source, uint32_t Count, std::vector<uint8_t> &Digest)
{
	int32_t szDigest = (int32_t)Digest.size();
	uint32_t _err = TElGOSTMD_Calculate_1(_Handle, Source.getHandle(), Count, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Digest), &szDigest);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Digest.resize(szDigest);
		SBCheckError(SBGetLastReturnBuffer(408556909, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Digest), &szDigest));
	}
	else
		SBCheckError(_err);

	Digest.resize(szDigest);
}

void TElGOSTMD::Calculate(TStream *Source, uint32_t Count, std::vector<uint8_t> &Digest)
{
	int32_t szDigest = (int32_t)Digest.size();
	uint32_t _err = TElGOSTMD_Calculate_1(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Count, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Digest), &szDigest);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Digest.resize(szDigest);
		SBCheckError(SBGetLastReturnBuffer(408556909, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Digest), &szDigest));
	}
	else
		SBCheckError(_err);

	Digest.resize(szDigest);
}
#endif /* SB_USE_CLASS_TSTREAM */

TElGOSTMD::TElGOSTMD(TElGOSTMDHandle handle, TElOwnHandle ownHandle) : TElGOSTBase(handle, ownHandle)
{
}

TElGOSTMD::TElGOSTMD() : TElGOSTBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOSTMD_Create(&_Handle));
}

TElGOSTMD::TElGOSTMD(const TElGostSubstBlock &SubstBlock) : TElGOSTBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOSTMD_Create_1(&SubstBlock, &_Handle));
}

#endif /* SB_USE_CLASS_TELGOSTMD */

};	/* namespace SecureBlackbox */

