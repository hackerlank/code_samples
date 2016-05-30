#include "cscp1131.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1131

void TPlCP1131::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1131_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1125283519, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1131::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1131_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1005815455, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1131::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1131_ClassType(&OutResult));
	return OutResult;
}

TPlCP1131::TPlCP1131(TPlCP1131Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCP1131::TPlCP1131() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1131_Create(&_Handle));
}

TPlCP1131 TPlCP1131::CreateForFinalize()
{
	TPlCP1131Handle _Handle;
	SBCheckError(TPlCP1131_CreateForFinalize(&_Handle));
	return TPlCP1131(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1131 */

};	/* namespace SecureBlackbox */

