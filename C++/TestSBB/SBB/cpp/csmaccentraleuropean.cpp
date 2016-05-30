#include "csmaccentraleuropean.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACCENTRALEUROPEAN

void TPlMacCentralEuropean::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacCentralEuropean_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2016175934, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacCentralEuropean::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacCentralEuropean_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-596638779, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacCentralEuropean::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacCentralEuropean_ClassType(&OutResult));
	return OutResult;
}

TPlMacCentralEuropean::TPlMacCentralEuropean(TPlMacCentralEuropeanHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacCentralEuropean::TPlMacCentralEuropean() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacCentralEuropean_Create(&_Handle));
}

TPlMacCentralEuropean TPlMacCentralEuropean::CreateForFinalize()
{
	TPlMacCentralEuropeanHandle _Handle;
	SBCheckError(TPlMacCentralEuropean_CreateForFinalize(&_Handle));
	return TPlMacCentralEuropean(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACCENTRALEUROPEAN */

};	/* namespace SecureBlackbox */

