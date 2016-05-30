#include "csmacceltic.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACCELTIC

void TPlMacCeltic::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacCeltic_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1625528494, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacCeltic::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacCeltic_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(614002753, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacCeltic::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacCeltic_ClassType(&OutResult));
	return OutResult;
}

TPlMacCeltic::TPlMacCeltic(TPlMacCelticHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacCeltic::TPlMacCeltic() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacCeltic_Create(&_Handle));
}

TPlMacCeltic TPlMacCeltic::CreateForFinalize()
{
	TPlMacCelticHandle _Handle;
	SBCheckError(TPlMacCeltic_CreateForFinalize(&_Handle));
	return TPlMacCeltic(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACCELTIC */

};	/* namespace SecureBlackbox */

