#include "cscp875.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP875

void TPlCP875::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP875_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-655703549, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP875::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP875_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1746382318, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP875::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP875_ClassType(&OutResult));
	return OutResult;
}

TPlCP875::TPlCP875(TPlCP875Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCP875::TPlCP875() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP875_Create(&_Handle));
}

TPlCP875 TPlCP875::CreateForFinalize()
{
	TPlCP875Handle _Handle;
	SBCheckError(TPlCP875_CreateForFinalize(&_Handle));
	return TPlCP875(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP875 */

};	/* namespace SecureBlackbox */

