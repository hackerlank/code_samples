#include "cscp424.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP424

void TPlCP424::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP424_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1246277495, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP424::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP424_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(685635322, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP424::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP424_ClassType(&OutResult));
	return OutResult;
}

TPlCP424::TPlCP424(TPlCP424Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCP424::TPlCP424() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP424_Create(&_Handle));
}

TPlCP424 TPlCP424::CreateForFinalize()
{
	TPlCP424Handle _Handle;
	SBCheckError(TPlCP424_CreateForFinalize(&_Handle));
	return TPlCP424(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP424 */

};	/* namespace SecureBlackbox */

