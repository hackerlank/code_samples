#include "cscp866.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP866

void TPlCP866::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP866_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1918850269, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP866::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP866_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1712140156, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP866::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP866_ClassType(&OutResult));
	return OutResult;
}

TPlCP866::TPlCP866(TPlCP866Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP866::TPlCP866() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP866_Create(&_Handle));
}

TPlCP866 TPlCP866::CreateForFinalize()
{
	TPlCP866Handle _Handle;
	SBCheckError(TPlCP866_CreateForFinalize(&_Handle));
	return TPlCP866(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP866 */

};	/* namespace SecureBlackbox */

