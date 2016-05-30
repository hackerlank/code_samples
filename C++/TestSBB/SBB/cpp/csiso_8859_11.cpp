#include "csiso_8859_11.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_11

void TPlISO_8859_11::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_11_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1887324592, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_11::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_11_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1641763935, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_11::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_11_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_11::TPlISO_8859_11(TPlISO_8859_11Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_11::TPlISO_8859_11() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_11_Create(&_Handle));
}

TPlISO_8859_11 TPlISO_8859_11::CreateForFinalize()
{
	TPlISO_8859_11Handle _Handle;
	SBCheckError(TPlISO_8859_11_CreateForFinalize(&_Handle));
	return TPlISO_8859_11(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_11 */

};	/* namespace SecureBlackbox */

