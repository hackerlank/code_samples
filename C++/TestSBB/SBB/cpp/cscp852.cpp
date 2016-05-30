#include "cscp852.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP852

void TPlCP852::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP852_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1520349580, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP852::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP852_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-647948164, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP852::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP852_ClassType(&OutResult));
	return OutResult;
}

TPlCP852::TPlCP852(TPlCP852Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP852::TPlCP852() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP852_Create(&_Handle));
}

TPlCP852 TPlCP852::CreateForFinalize()
{
	TPlCP852Handle _Handle;
	SBCheckError(TPlCP852_CreateForFinalize(&_Handle));
	return TPlCP852(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP852 */

};	/* namespace SecureBlackbox */

