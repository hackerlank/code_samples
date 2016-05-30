#include "csmacthai.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACTHAI

void TPlMacThai::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacThai_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1991736170, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacThai::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacThai_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1496583527, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacThai::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacThai_ClassType(&OutResult));
	return OutResult;
}

TPlMacThai::TPlMacThai(TPlMacThaiHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacThai::TPlMacThai() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacThai_Create(&_Handle));
}

TPlMacThai TPlMacThai::CreateForFinalize()
{
	TPlMacThaiHandle _Handle;
	SBCheckError(TPlMacThai_CreateForFinalize(&_Handle));
	return TPlMacThai(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACTHAI */

};	/* namespace SecureBlackbox */

