#include "cscp500.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP500

void TPlCP500::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP500_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1539835212, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP500::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP500_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-857701630, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP500::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP500_ClassType(&OutResult));
	return OutResult;
}

TPlCP500::TPlCP500(TPlCP500Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCP500::TPlCP500() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP500_Create(&_Handle));
}

TPlCP500 TPlCP500::CreateForFinalize()
{
	TPlCP500Handle _Handle;
	SBCheckError(TPlCP500_CreateForFinalize(&_Handle));
	return TPlCP500(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP500 */

};	/* namespace SecureBlackbox */

