#include "csarmscii_8.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLARMSCII_8

void TPlARMSCII_8::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlARMSCII_8_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(777739256, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlARMSCII_8::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlARMSCII_8_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(325975349, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlARMSCII_8::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlARMSCII_8_ClassType(&OutResult));
	return OutResult;
}

TPlARMSCII_8::TPlARMSCII_8(TPlARMSCII_8Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlARMSCII_8::TPlARMSCII_8() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlARMSCII_8_Create(&_Handle));
}

TPlARMSCII_8 TPlARMSCII_8::CreateForFinalize()
{
	TPlARMSCII_8Handle _Handle;
	SBCheckError(TPlARMSCII_8_CreateForFinalize(&_Handle));
	return TPlARMSCII_8(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLARMSCII_8 */

};	/* namespace SecureBlackbox */

