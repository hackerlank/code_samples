#include "csbigfive.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLBIGFIVE

void TPlBigFive::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlBigFive_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(173090699, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlBigFive::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlBigFive_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(501522666, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlBigFive::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlBigFive_ClassType(&OutResult));
	return OutResult;
}

TPlBigFive::TPlBigFive(TPlBigFiveHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlBigFive::TPlBigFive() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlBigFive_Create(&_Handle));
}

TPlBigFive TPlBigFive::CreateForFinalize()
{
	TPlBigFiveHandle _Handle;
	SBCheckError(TPlBigFive_CreateForFinalize(&_Handle));
	return TPlBigFive(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLBIGFIVE */

};	/* namespace SecureBlackbox */

