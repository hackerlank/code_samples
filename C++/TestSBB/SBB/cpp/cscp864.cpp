#include "cscp864.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP864

void TPlCP864::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP864_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1787028537, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP864::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP864_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-402962351, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP864::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP864_ClassType(&OutResult));
	return OutResult;
}

TPlCP864::TPlCP864(TPlCP864Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP864::TPlCP864() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP864_Create(&_Handle));
}

TPlCP864 TPlCP864::CreateForFinalize()
{
	TPlCP864Handle _Handle;
	SBCheckError(TPlCP864_CreateForFinalize(&_Handle));
	return TPlCP864(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP864 */

};	/* namespace SecureBlackbox */

