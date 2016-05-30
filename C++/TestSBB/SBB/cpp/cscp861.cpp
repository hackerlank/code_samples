#include "cscp861.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP861

void TPlCP861::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP861_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1465179523, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP861::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP861_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1843056388, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP861::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP861_ClassType(&OutResult));
	return OutResult;
}

TPlCP861::TPlCP861(TPlCP861Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP861::TPlCP861() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP861_Create(&_Handle));
}

TPlCP861 TPlCP861::CreateForFinalize()
{
	TPlCP861Handle _Handle;
	SBCheckError(TPlCP861_CreateForFinalize(&_Handle));
	return TPlCP861(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP861 */

};	/* namespace SecureBlackbox */

