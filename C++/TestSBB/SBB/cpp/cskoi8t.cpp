#include "cskoi8t.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLKOI8T

void TPlKOI8T::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlKOI8T_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(922384289, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlKOI8T::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlKOI8T_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-240118881, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlKOI8T::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlKOI8T_ClassType(&OutResult));
	return OutResult;
}

TPlKOI8T::TPlKOI8T(TPlKOI8THandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlKOI8T::TPlKOI8T() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlKOI8T_Create(&_Handle));
}

TPlKOI8T TPlKOI8T::CreateForFinalize()
{
	TPlKOI8THandle _Handle;
	SBCheckError(TPlKOI8T_CreateForFinalize(&_Handle));
	return TPlKOI8T(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLKOI8T */

};	/* namespace SecureBlackbox */

