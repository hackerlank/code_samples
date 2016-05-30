#include "cscp869.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP869

void TPlCP869::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP869_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(874913299, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP869::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP869_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-126900597, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP869::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP869_ClassType(&OutResult));
	return OutResult;
}

TPlCP869::TPlCP869(TPlCP869Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP869::TPlCP869() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP869_Create(&_Handle));
}

TPlCP869 TPlCP869::CreateForFinalize()
{
	TPlCP869Handle _Handle;
	SBCheckError(TPlCP869_CreateForFinalize(&_Handle));
	return TPlCP869(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP869 */

};	/* namespace SecureBlackbox */

