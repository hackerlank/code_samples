#include "cscp862.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP862

void TPlCP862::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP862_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1139160341, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP862::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP862_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1097799833, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP862::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP862_ClassType(&OutResult));
	return OutResult;
}

TPlCP862::TPlCP862(TPlCP862Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP862::TPlCP862() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP862_Create(&_Handle));
}

TPlCP862 TPlCP862::CreateForFinalize()
{
	TPlCP862Handle _Handle;
	SBCheckError(TPlCP862_CreateForFinalize(&_Handle));
	return TPlCP862(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP862 */

};	/* namespace SecureBlackbox */

