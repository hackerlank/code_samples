#include "cskoi8u.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLKOI8U

void TPlKOI8U::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlKOI8U_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(982790099, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlKOI8U::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlKOI8U_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1559470889, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlKOI8U::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlKOI8U_ClassType(&OutResult));
	return OutResult;
}

TPlKOI8U::TPlKOI8U(TPlKOI8UHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlKOI8U::TPlKOI8U() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlKOI8U_Create(&_Handle));
}

TPlKOI8U TPlKOI8U::CreateForFinalize()
{
	TPlKOI8UHandle _Handle;
	SBCheckError(TPlKOI8U_CreateForFinalize(&_Handle));
	return TPlKOI8U(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLKOI8U */

};	/* namespace SecureBlackbox */

