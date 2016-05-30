#include "cscp865.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP865

void TPlCP865::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP865_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1726856267, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP865::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP865_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1253636327, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP865::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP865_ClassType(&OutResult));
	return OutResult;
}

TPlCP865::TPlCP865(TPlCP865Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP865::TPlCP865() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP865_Create(&_Handle));
}

TPlCP865 TPlCP865::CreateForFinalize()
{
	TPlCP865Handle _Handle;
	SBCheckError(TPlCP865_CreateForFinalize(&_Handle));
	return TPlCP865(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP865 */

};	/* namespace SecureBlackbox */

