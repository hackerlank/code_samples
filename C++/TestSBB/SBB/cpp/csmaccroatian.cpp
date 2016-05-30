#include "csmaccroatian.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACCROATIAN

void TPlMacCroatian::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacCroatian_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1973089302, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacCroatian::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacCroatian_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1636208451, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacCroatian::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacCroatian_ClassType(&OutResult));
	return OutResult;
}

TPlMacCroatian::TPlMacCroatian(TPlMacCroatianHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacCroatian::TPlMacCroatian() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacCroatian_Create(&_Handle));
}

TPlMacCroatian TPlMacCroatian::CreateForFinalize()
{
	TPlMacCroatianHandle _Handle;
	SBCheckError(TPlMacCroatian_CreateForFinalize(&_Handle));
	return TPlMacCroatian(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACCROATIAN */

};	/* namespace SecureBlackbox */

