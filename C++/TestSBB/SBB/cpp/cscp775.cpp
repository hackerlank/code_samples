#include "cscp775.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP775

void TPlCP775::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP775_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(463132212, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP775::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP775_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1483833486, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP775::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP775_ClassType(&OutResult));
	return OutResult;
}

TPlCP775::TPlCP775(TPlCP775Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP775::TPlCP775() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP775_Create(&_Handle));
}

TPlCP775 TPlCP775::CreateForFinalize()
{
	TPlCP775Handle _Handle;
	SBCheckError(TPlCP775_CreateForFinalize(&_Handle));
	return TPlCP775(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP775 */

};	/* namespace SecureBlackbox */
