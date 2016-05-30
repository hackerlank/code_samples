#include "cscp860.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP860

void TPlCP860::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP860_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1530562033, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP860::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP860_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1063682122, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP860::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP860_ClassType(&OutResult));
	return OutResult;
}

TPlCP860::TPlCP860(TPlCP860Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP860::TPlCP860() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP860_Create(&_Handle));
}

TPlCP860 TPlCP860::CreateForFinalize()
{
	TPlCP860Handle _Handle;
	SBCheckError(TPlCP860_CreateForFinalize(&_Handle));
	return TPlCP860(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP860 */

};	/* namespace SecureBlackbox */

