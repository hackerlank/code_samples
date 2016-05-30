#include "cscp1006.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1006

void TPlCP1006::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1006_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1622737838, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1006::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1006_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1416211636, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1006::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1006_ClassType(&OutResult));
	return OutResult;
}

TPlCP1006::TPlCP1006(TPlCP1006Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1006::TPlCP1006() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1006_Create(&_Handle));
}

TPlCP1006 TPlCP1006::CreateForFinalize()
{
	TPlCP1006Handle _Handle;
	SBCheckError(TPlCP1006_CreateForFinalize(&_Handle));
	return TPlCP1006(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1006 */

};	/* namespace SecureBlackbox */

