#include "cscp850.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP850

void TPlCP850::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP850_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1111621992, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP850::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP850_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1486323537, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP850::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP850_ClassType(&OutResult));
	return OutResult;
}

TPlCP850::TPlCP850(TPlCP850Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP850::TPlCP850() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP850_Create(&_Handle));
}

TPlCP850 TPlCP850::CreateForFinalize()
{
	TPlCP850Handle _Handle;
	SBCheckError(TPlCP850_CreateForFinalize(&_Handle));
	return TPlCP850(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP850 */

};	/* namespace SecureBlackbox */

