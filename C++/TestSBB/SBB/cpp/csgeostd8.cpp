#include "csgeostd8.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLGEOSTD8

void TPlGEOSTD8::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGEOSTD8_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1445358902, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlGEOSTD8::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGEOSTD8_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(231644418, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlGEOSTD8::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGEOSTD8_ClassType(&OutResult));
	return OutResult;
}

TPlGEOSTD8::TPlGEOSTD8(TPlGEOSTD8Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlGEOSTD8::TPlGEOSTD8() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGEOSTD8_Create(&_Handle));
}

TPlGEOSTD8 TPlGEOSTD8::CreateForFinalize()
{
	TPlGEOSTD8Handle _Handle;
	SBCheckError(TPlGEOSTD8_CreateForFinalize(&_Handle));
	return TPlGEOSTD8(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGEOSTD8 */

};	/* namespace SecureBlackbox */

