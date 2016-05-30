#include "csmachebrew.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACHEBREW

void TPlMacHebrew::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacHebrew_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1647914966, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacHebrew::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacHebrew_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1664152994, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacHebrew::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacHebrew_ClassType(&OutResult));
	return OutResult;
}

TPlMacHebrew::TPlMacHebrew(TPlMacHebrewHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacHebrew::TPlMacHebrew() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacHebrew_Create(&_Handle));
}

TPlMacHebrew TPlMacHebrew::CreateForFinalize()
{
	TPlMacHebrewHandle _Handle;
	SBCheckError(TPlMacHebrew_CreateForFinalize(&_Handle));
	return TPlMacHebrew(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACHEBREW */

};	/* namespace SecureBlackbox */

