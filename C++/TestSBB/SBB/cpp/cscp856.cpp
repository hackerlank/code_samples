#include "cscp856.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP856

void TPlCP856::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP856_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1797771332, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP856::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP856_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(33345639, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP856::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP856_ClassType(&OutResult));
	return OutResult;
}

TPlCP856::TPlCP856(TPlCP856Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP856::TPlCP856() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP856_Create(&_Handle));
}

TPlCP856 TPlCP856::CreateForFinalize()
{
	TPlCP856Handle _Handle;
	SBCheckError(TPlCP856_CreateForFinalize(&_Handle));
	return TPlCP856(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP856 */

};	/* namespace SecureBlackbox */

