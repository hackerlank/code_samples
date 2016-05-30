#include "cscp1253.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1253

void TPlCP1253::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1253_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(956469404, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1253::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1253_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1940267718, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1253::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1253_ClassType(&OutResult));
	return OutResult;
}

TPlCP1253::TPlCP1253(TPlCP1253Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1253::TPlCP1253() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1253_Create(&_Handle));
}

TPlCP1253 TPlCP1253::CreateForFinalize()
{
	TPlCP1253Handle _Handle;
	SBCheckError(TPlCP1253_CreateForFinalize(&_Handle));
	return TPlCP1253(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1253 */

};	/* namespace SecureBlackbox */

