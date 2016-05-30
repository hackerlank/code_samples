#include "cskoi8r.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLKOI8R

void TPlKOI8R::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlKOI8R_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(530556557, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlKOI8R::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlKOI8R_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1461994327, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlKOI8R::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlKOI8R_ClassType(&OutResult));
	return OutResult;
}

TPlKOI8R::TPlKOI8R(TPlKOI8RHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlKOI8R::TPlKOI8R() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlKOI8R_Create(&_Handle));
}

TPlKOI8R TPlKOI8R::CreateForFinalize()
{
	TPlKOI8RHandle _Handle;
	SBCheckError(TPlKOI8R_CreateForFinalize(&_Handle));
	return TPlKOI8R(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLKOI8R */

};	/* namespace SecureBlackbox */

