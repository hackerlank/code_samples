#include "csviscii.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLVISCII

void TPlVISCII::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlVISCII_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(753037282, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlVISCII::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlVISCII_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1409774592, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlVISCII::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlVISCII_ClassType(&OutResult));
	return OutResult;
}

TPlVISCII::TPlVISCII(TPlVISCIIHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlVISCII::TPlVISCII() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlVISCII_Create(&_Handle));
}

TPlVISCII TPlVISCII::CreateForFinalize()
{
	TPlVISCIIHandle _Handle;
	SBCheckError(TPlVISCII_CreateForFinalize(&_Handle));
	return TPlVISCII(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLVISCII */

};	/* namespace SecureBlackbox */

