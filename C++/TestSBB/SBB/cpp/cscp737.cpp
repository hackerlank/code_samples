#include "cscp737.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP737

void TPlCP737::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP737_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1765239501, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP737::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP737_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1396355973, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP737::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP737_ClassType(&OutResult));
	return OutResult;
}

TPlCP737::TPlCP737(TPlCP737Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlCP737::TPlCP737() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP737_Create(&_Handle));
}

TPlCP737 TPlCP737::CreateForFinalize()
{
	TPlCP737Handle _Handle;
	SBCheckError(TPlCP737_CreateForFinalize(&_Handle));
	return TPlCP737(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP737 */

};	/* namespace SecureBlackbox */

