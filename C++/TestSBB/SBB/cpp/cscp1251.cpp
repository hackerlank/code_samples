#include "cscp1251.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1251

void TPlCP1251::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1251_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-932324181, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1251::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1251_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1744928016, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1251::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1251_ClassType(&OutResult));
	return OutResult;
}

TPlCP1251::TPlCP1251(TPlCP1251Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1251::TPlCP1251() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1251_Create(&_Handle));
}

TPlCP1251 TPlCP1251::CreateForFinalize()
{
	TPlCP1251Handle _Handle;
	SBCheckError(TPlCP1251_CreateForFinalize(&_Handle));
	return TPlCP1251(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1251 */

};	/* namespace SecureBlackbox */

