#include "csiso_8859_8.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_8

void TPlISO_8859_8::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_8_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2041332055, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_8::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_8_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-121052318, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_8::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_8_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_8::TPlISO_8859_8(TPlISO_8859_8Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_8::TPlISO_8859_8() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_8_Create(&_Handle));
}

TPlISO_8859_8 TPlISO_8859_8::CreateForFinalize()
{
	TPlISO_8859_8Handle _Handle;
	SBCheckError(TPlISO_8859_8_CreateForFinalize(&_Handle));
	return TPlISO_8859_8(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_8 */

};	/* namespace SecureBlackbox */

