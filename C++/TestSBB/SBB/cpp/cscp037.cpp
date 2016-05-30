#include "cscp037.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP037

void TPlCP037::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP037_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(647297894, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP037::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP037_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(441331181, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP037::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP037_ClassType(&OutResult));
	return OutResult;
}

TPlCP037::TPlCP037(TPlCP037Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCP037::TPlCP037() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP037_Create(&_Handle));
}

TPlCP037 TPlCP037::CreateForFinalize()
{
	TPlCP037Handle _Handle;
	SBCheckError(TPlCP037_CreateForFinalize(&_Handle));
	return TPlCP037(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP037 */

};	/* namespace SecureBlackbox */

