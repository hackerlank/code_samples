#include "cscp1257.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP1257

void TPlCP1257::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1257_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(11341491, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP1257::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP1257_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1617323217, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP1257::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP1257_ClassType(&OutResult));
	return OutResult;
}

TPlCP1257::TPlCP1257(TPlCP1257Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP1257::TPlCP1257() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP1257_Create(&_Handle));
}

TPlCP1257 TPlCP1257::CreateForFinalize()
{
	TPlCP1257Handle _Handle;
	SBCheckError(TPlCP1257_CreateForFinalize(&_Handle));
	return TPlCP1257(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP1257 */

};	/* namespace SecureBlackbox */

