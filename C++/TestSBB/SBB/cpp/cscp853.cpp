#include "cscp853.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP853

void TPlCP853::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP853_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1458629118, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP853::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP853_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1948428490, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP853::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP853_ClassType(&OutResult));
	return OutResult;
}

TPlCP853::TPlCP853(TPlCP853Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP853::TPlCP853() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP853_Create(&_Handle));
}

TPlCP853 TPlCP853::CreateForFinalize()
{
	TPlCP853Handle _Handle;
	SBCheckError(TPlCP853_CreateForFinalize(&_Handle));
	return TPlCP853(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP853 */

};	/* namespace SecureBlackbox */

