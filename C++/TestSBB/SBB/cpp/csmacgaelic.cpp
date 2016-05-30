#include "csmacgaelic.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACGAELIC

void TPlMacGaelic::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacGaelic_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2042094171, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacGaelic::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacGaelic_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(115256206, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacGaelic::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacGaelic_ClassType(&OutResult));
	return OutResult;
}

TPlMacGaelic::TPlMacGaelic(TPlMacGaelicHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacGaelic::TPlMacGaelic() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacGaelic_Create(&_Handle));
}

TPlMacGaelic TPlMacGaelic::CreateForFinalize()
{
	TPlMacGaelicHandle _Handle;
	SBCheckError(TPlMacGaelic_CreateForFinalize(&_Handle));
	return TPlMacGaelic(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACGAELIC */

};	/* namespace SecureBlackbox */

