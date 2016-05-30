#include "cscp1254.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1254

void TPlCP1254::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1254_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1691183039, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1254::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1254_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(166554384, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1254::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1254_ClassType(&OutResult));
	return OutResult;
}

TPlCP1254::TPlCP1254(TPlCP1254Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1254::TPlCP1254() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1254_Create(&_Handle));
}

TPlCP1254 TPlCP1254::CreateForFinalize()
{
	TPlCP1254Handle _Handle;
	SBCheckError(TPlCP1254_CreateForFinalize(&_Handle));
	return TPlCP1254(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1254 */

};	/* namespace SecureBlackbox */

