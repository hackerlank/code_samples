#include "cshproman8.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLHPROMAN8

void TPlHPRoman8::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlHPRoman8_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1819550812, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlHPRoman8::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlHPRoman8_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1142811051, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlHPRoman8::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlHPRoman8_ClassType(&OutResult));
	return OutResult;
}

TPlHPRoman8::TPlHPRoman8(TPlHPRoman8Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlHPRoman8::TPlHPRoman8() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlHPRoman8_Create(&_Handle));
}

TPlHPRoman8 TPlHPRoman8::CreateForFinalize()
{
	TPlHPRoman8Handle _Handle;
	SBCheckError(TPlHPRoman8_CreateForFinalize(&_Handle));
	return TPlHPRoman8(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLHPROMAN8 */

};	/* namespace SecureBlackbox */

