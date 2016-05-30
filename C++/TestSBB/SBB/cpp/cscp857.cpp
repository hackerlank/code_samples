#include "cscp857.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP857

void TPlCP857::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP857_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1732872246, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP857::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP857_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1396743983, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP857::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP857_ClassType(&OutResult));
	return OutResult;
}

TPlCP857::TPlCP857(TPlCP857Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP857::TPlCP857() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP857_Create(&_Handle));
}

TPlCP857 TPlCP857::CreateForFinalize()
{
	TPlCP857Handle _Handle;
	SBCheckError(TPlCP857_CreateForFinalize(&_Handle));
	return TPlCP857(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP857 */

};	/* namespace SecureBlackbox */

