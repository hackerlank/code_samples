#include "cscp855.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP855

void TPlCP855::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP855_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2140485842, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP855::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP855_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(759760892, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP855::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP855_ClassType(&OutResult));
	return OutResult;
}

TPlCP855::TPlCP855(TPlCP855Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP855::TPlCP855() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP855_Create(&_Handle));
}

TPlCP855 TPlCP855::CreateForFinalize()
{
	TPlCP855Handle _Handle;
	SBCheckError(TPlCP855_CreateForFinalize(&_Handle));
	return TPlCP855(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP855 */

};	/* namespace SecureBlackbox */

