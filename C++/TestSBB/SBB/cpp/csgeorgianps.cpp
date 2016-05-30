#include "csgeorgianps.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLGEORGIANPS

void TPlGeorgianPS::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGeorgianPS_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(659496093, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlGeorgianPS::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGeorgianPS_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1490243650, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlGeorgianPS::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGeorgianPS_ClassType(&OutResult));
	return OutResult;
}

TPlGeorgianPS::TPlGeorgianPS(TPlGeorgianPSHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlGeorgianPS::TPlGeorgianPS() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGeorgianPS_Create(&_Handle));
}

TPlGeorgianPS TPlGeorgianPS::CreateForFinalize()
{
	TPlGeorgianPSHandle _Handle;
	SBCheckError(TPlGeorgianPS_CreateForFinalize(&_Handle));
	return TPlGeorgianPS(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGEORGIANPS */

};	/* namespace SecureBlackbox */

