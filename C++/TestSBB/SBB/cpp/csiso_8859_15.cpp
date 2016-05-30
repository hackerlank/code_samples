#include "csiso_8859_15.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_15

void TPlISO_8859_15::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_15_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1799619346, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_15::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_15_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-385663029, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_15::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_15_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_15::TPlISO_8859_15(TPlISO_8859_15Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_15::TPlISO_8859_15() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_15_Create(&_Handle));
}

TPlISO_8859_15 TPlISO_8859_15::CreateForFinalize()
{
	TPlISO_8859_15Handle _Handle;
	SBCheckError(TPlISO_8859_15_CreateForFinalize(&_Handle));
	return TPlISO_8859_15(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_15 */

};	/* namespace SecureBlackbox */

