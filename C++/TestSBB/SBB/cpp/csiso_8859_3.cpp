#include "csiso_8859_3.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_3

void TPlISO_8859_3::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_3_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1335363755, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_3::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_3_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-368892109, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_3::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_3_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_3::TPlISO_8859_3(TPlISO_8859_3Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_3::TPlISO_8859_3() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_3_Create(&_Handle));
}

TPlISO_8859_3 TPlISO_8859_3::CreateForFinalize()
{
	TPlISO_8859_3Handle _Handle;
	SBCheckError(TPlISO_8859_3_CreateForFinalize(&_Handle));
	return TPlISO_8859_3(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_3 */

};	/* namespace SecureBlackbox */

