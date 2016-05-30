#include "cscp1258.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1258

void TPlCP1258::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1258_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(775800270, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1258::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1258_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1034789167, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1258::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1258_ClassType(&OutResult));
	return OutResult;
}

TPlCP1258::TPlCP1258(TPlCP1258Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1258::TPlCP1258() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1258_Create(&_Handle));
}

TPlCP1258 TPlCP1258::CreateForFinalize()
{
	TPlCP1258Handle _Handle;
	SBCheckError(TPlCP1258_CreateForFinalize(&_Handle));
	return TPlCP1258(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1258 */

};	/* namespace SecureBlackbox */

