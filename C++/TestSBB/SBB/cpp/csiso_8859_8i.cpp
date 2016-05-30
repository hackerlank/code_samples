#include "csiso_8859_8i.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_8I

void TPlISO_8859_8i::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_8i_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1802415690, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_8i::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_8i_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-508195480, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_8i::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_8i_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_8i::TPlISO_8859_8i(TPlISO_8859_8iHandle handle, TElOwnHandle ownHandle) : TPlISO_8859_8(handle, ownHandle)
{
}

TPlISO_8859_8i::TPlISO_8859_8i() : TPlISO_8859_8(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_8i_Create(&_Handle));
}

TPlISO_8859_8i TPlISO_8859_8i::CreateForFinalize()
{
	TPlISO_8859_8iHandle _Handle;
	SBCheckError(TPlISO_8859_8i_CreateForFinalize(&_Handle));
	return TPlISO_8859_8i(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_8I */

};	/* namespace SecureBlackbox */

