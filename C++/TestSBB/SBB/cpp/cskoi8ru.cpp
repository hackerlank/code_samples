#include "cskoi8ru.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLKOI8RU

void TPlKOI8RU::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlKOI8RU_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1610126784, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlKOI8RU::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlKOI8RU_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1834962979, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlKOI8RU::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlKOI8RU_ClassType(&OutResult));
	return OutResult;
}

TPlKOI8RU::TPlKOI8RU(TPlKOI8RUHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlKOI8RU::TPlKOI8RU() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlKOI8RU_Create(&_Handle));
}

TPlKOI8RU TPlKOI8RU::CreateForFinalize()
{
	TPlKOI8RUHandle _Handle;
	SBCheckError(TPlKOI8RU_CreateForFinalize(&_Handle));
	return TPlKOI8RU(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLKOI8RU */

};	/* namespace SecureBlackbox */

