#include "csmacromanian.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACROMANIAN

void TPlMacRomanian::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacRomanian_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-795844945, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacRomanian::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacRomanian_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1523576862, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacRomanian::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacRomanian_ClassType(&OutResult));
	return OutResult;
}

TPlMacRomanian::TPlMacRomanian(TPlMacRomanianHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacRomanian::TPlMacRomanian() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacRomanian_Create(&_Handle));
}

TPlMacRomanian TPlMacRomanian::CreateForFinalize()
{
	TPlMacRomanianHandle _Handle;
	SBCheckError(TPlMacRomanian_CreateForFinalize(&_Handle));
	return TPlMacRomanian(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACROMANIAN */

};	/* namespace SecureBlackbox */

