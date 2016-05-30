#include "csmaccyrillic.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACCYRILLIC

void TPlMacCyrillic::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacCyrillic_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(82474337, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacCyrillic::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacCyrillic_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1106368762, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacCyrillic::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacCyrillic_ClassType(&OutResult));
	return OutResult;
}

TPlMacCyrillic::TPlMacCyrillic(TPlMacCyrillicHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacCyrillic::TPlMacCyrillic() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacCyrillic_Create(&_Handle));
}

TPlMacCyrillic TPlMacCyrillic::CreateForFinalize()
{
	TPlMacCyrillicHandle _Handle;
	SBCheckError(TPlMacCyrillic_CreateForFinalize(&_Handle));
	return TPlMacCyrillic(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACCYRILLIC */

};	/* namespace SecureBlackbox */

