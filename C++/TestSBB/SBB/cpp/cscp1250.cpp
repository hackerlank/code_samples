#include "cscp1250.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1250

void TPlCP1250::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1250_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1566767504, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1250::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1250_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(439168261, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1250::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1250_ClassType(&OutResult));
	return OutResult;
}

TPlCP1250::TPlCP1250(TPlCP1250Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1250::TPlCP1250() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1250_Create(&_Handle));
}

TPlCP1250 TPlCP1250::CreateForFinalize()
{
	TPlCP1250Handle _Handle;
	SBCheckError(TPlCP1250_CreateForFinalize(&_Handle));
	return TPlCP1250(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1250 */

};	/* namespace SecureBlackbox */

