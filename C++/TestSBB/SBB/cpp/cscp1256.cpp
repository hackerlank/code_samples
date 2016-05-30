#include "cscp1256.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1256

void TPlCP1256::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1256_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1784534136, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1256::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1256_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-306853062, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1256::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1256_ClassType(&OutResult));
	return OutResult;
}

TPlCP1256::TPlCP1256(TPlCP1256Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1256::TPlCP1256() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1256_Create(&_Handle));
}

TPlCP1256 TPlCP1256::CreateForFinalize()
{
	TPlCP1256Handle _Handle;
	SBCheckError(TPlCP1256_CreateForFinalize(&_Handle));
	return TPlCP1256(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1256 */

};	/* namespace SecureBlackbox */

