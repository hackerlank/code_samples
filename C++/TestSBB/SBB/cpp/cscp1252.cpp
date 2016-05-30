#include "cscp1252.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1252

void TPlCP1252::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1252_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1408387673, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1252::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1252_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-25850577, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1252::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1252_ClassType(&OutResult));
	return OutResult;
}

TPlCP1252::TPlCP1252(TPlCP1252Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1252::TPlCP1252() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1252_Create(&_Handle));
}

TPlCP1252 TPlCP1252::CreateForFinalize()
{
	TPlCP1252Handle _Handle;
	SBCheckError(TPlCP1252_CreateForFinalize(&_Handle));
	return TPlCP1252(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1252 */

};	/* namespace SecureBlackbox */

