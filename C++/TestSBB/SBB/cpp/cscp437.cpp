#include "cscp437.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP437

void TPlCP437::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP437_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(520275543, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP437::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP437_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(650605672, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP437::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP437_ClassType(&OutResult));
	return OutResult;
}

TPlCP437::TPlCP437(TPlCP437Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP437::TPlCP437() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP437_Create(&_Handle));
}

TPlCP437 TPlCP437::CreateForFinalize()
{
	TPlCP437Handle _Handle;
	SBCheckError(TPlCP437_CreateForFinalize(&_Handle));
	return TPlCP437(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP437 */

};	/* namespace SecureBlackbox */

