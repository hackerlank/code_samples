#include "sbtypes.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSTRINGHOLDER

void TElStringHolder::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElStringHolder_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1291958001, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElStringHolder::set_Value(const std::string &Value)
{
	SBCheckError(TElStringHolder_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TElStringHolder::TElStringHolder(TElStringHolderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElStringHolder::TElStringHolder(const std::string &Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElStringHolder_Create(Data.data(), (int32_t)Data.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELSTRINGHOLDER */

#ifdef SB_USE_CLASS_TELBYTEARRAYHOLDER

void TElByteArrayHolder::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElByteArrayHolder_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(725365203, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElByteArrayHolder::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElByteArrayHolder_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElByteArrayHolder::TElByteArrayHolder(TElByteArrayHolderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElByteArrayHolder::TElByteArrayHolder(const std::vector<uint8_t> &Data) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElByteArrayHolder_Create(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &_Handle));
}

#endif /* SB_USE_CLASS_TELBYTEARRAYHOLDER */

};	/* namespace SecureBlackbox */

