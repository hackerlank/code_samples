#include "csmacicelandic.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACICELANDIC

void TPlMacIcelandic::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacIcelandic_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1846707032, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacIcelandic::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacIcelandic_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-836127086, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacIcelandic::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacIcelandic_ClassType(&OutResult));
	return OutResult;
}

TPlMacIcelandic::TPlMacIcelandic(TPlMacIcelandicHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacIcelandic::TPlMacIcelandic() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacIcelandic_Create(&_Handle));
}

TPlMacIcelandic TPlMacIcelandic::CreateForFinalize()
{
	TPlMacIcelandicHandle _Handle;
	SBCheckError(TPlMacIcelandic_CreateForFinalize(&_Handle));
	return TPlMacIcelandic(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACICELANDIC */

};	/* namespace SecureBlackbox */

