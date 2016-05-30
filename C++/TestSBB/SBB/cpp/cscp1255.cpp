#include "cscp1255.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1255

void TPlCP1255::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1255_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-238927228, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1255::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1255_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2076261125, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1255::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1255_ClassType(&OutResult));
	return OutResult;
}

TPlCP1255::TPlCP1255(TPlCP1255Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1255::TPlCP1255() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1255_Create(&_Handle));
}

TPlCP1255 TPlCP1255::CreateForFinalize()
{
	TPlCP1255Handle _Handle;
	SBCheckError(TPlCP1255_CreateForFinalize(&_Handle));
	return TPlCP1255(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1255 */

};	/* namespace SecureBlackbox */

