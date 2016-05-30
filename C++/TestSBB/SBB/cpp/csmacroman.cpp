#include "csmacroman.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACROMAN

void TPlMacRoman::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacRoman_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1619456752, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacRoman::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacRoman_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1520827287, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacRoman::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacRoman_ClassType(&OutResult));
	return OutResult;
}

TPlMacRoman::TPlMacRoman(TPlMacRomanHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacRoman::TPlMacRoman() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacRoman_Create(&_Handle));
}

TPlMacRoman TPlMacRoman::CreateForFinalize()
{
	TPlMacRomanHandle _Handle;
	SBCheckError(TPlMacRoman_CreateForFinalize(&_Handle));
	return TPlMacRoman(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACROMAN */

};	/* namespace SecureBlackbox */

