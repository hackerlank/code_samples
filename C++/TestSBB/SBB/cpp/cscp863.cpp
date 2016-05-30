#include "cscp863.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP863

void TPlCP863::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP863_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1334340967, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP863::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP863_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(332617681, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP863::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP863_ClassType(&OutResult));
	return OutResult;
}

TPlCP863::TPlCP863(TPlCP863Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP863::TPlCP863() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP863_Create(&_Handle));
}

TPlCP863 TPlCP863::CreateForFinalize()
{
	TPlCP863Handle _Handle;
	SBCheckError(TPlCP863_CreateForFinalize(&_Handle));
	return TPlCP863(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP863 */

};	/* namespace SecureBlackbox */

