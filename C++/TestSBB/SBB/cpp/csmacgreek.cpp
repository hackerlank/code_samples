#include "csmacgreek.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACGREEK

void TPlMacGreek::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacGreek_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1390902356, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacGreek::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacGreek_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1599647792, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacGreek::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacGreek_ClassType(&OutResult));
	return OutResult;
}

TPlMacGreek::TPlMacGreek(TPlMacGreekHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacGreek::TPlMacGreek() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacGreek_Create(&_Handle));
}

TPlMacGreek TPlMacGreek::CreateForFinalize()
{
	TPlMacGreekHandle _Handle;
	SBCheckError(TPlMacGreek_CreateForFinalize(&_Handle));
	return TPlMacGreek(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACGREEK */

};	/* namespace SecureBlackbox */

