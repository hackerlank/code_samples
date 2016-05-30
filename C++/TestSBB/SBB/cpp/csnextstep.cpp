#include "csnextstep.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLNEXTSTEP

void TPlNextStep::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlNextStep_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-989064139, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlNextStep::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlNextStep_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-996970641, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlNextStep::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlNextStep_ClassType(&OutResult));
	return OutResult;
}

TPlNextStep::TPlNextStep(TPlNextStepHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlNextStep::TPlNextStep() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlNextStep_Create(&_Handle));
}

TPlNextStep TPlNextStep::CreateForFinalize()
{
	TPlNextStepHandle _Handle;
	SBCheckError(TPlNextStep_CreateForFinalize(&_Handle));
	return TPlNextStep(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLNEXTSTEP */

};	/* namespace SecureBlackbox */

