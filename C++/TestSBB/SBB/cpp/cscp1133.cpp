#include "cscp1133.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1133

void TPlCP1133::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1133_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1300415864, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1133::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1133_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-542431563, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1133::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1133_ClassType(&OutResult));
	return OutResult;
}

TPlCP1133::TPlCP1133(TPlCP1133Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1133::TPlCP1133() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1133_Create(&_Handle));
}

TPlCP1133 TPlCP1133::CreateForFinalize()
{
	TPlCP1133Handle _Handle;
	SBCheckError(TPlCP1133_CreateForFinalize(&_Handle));
	return TPlCP1133(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1133 */

};	/* namespace SecureBlackbox */

