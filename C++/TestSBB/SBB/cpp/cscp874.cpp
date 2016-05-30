#include "cscp874.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP874

void TPlCP874::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP874_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-729507215, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP874::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP874_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-984343208, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP874::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP874_ClassType(&OutResult));
	return OutResult;
}

TPlCP874::TPlCP874(TPlCP874Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP874::TPlCP874() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP874_Create(&_Handle));
}

TPlCP874 TPlCP874::CreateForFinalize()
{
	TPlCP874Handle _Handle;
	SBCheckError(TPlCP874_CreateForFinalize(&_Handle));
	return TPlCP874(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP874 */

};	/* namespace SecureBlackbox */

