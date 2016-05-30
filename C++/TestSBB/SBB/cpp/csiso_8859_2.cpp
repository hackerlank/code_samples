#include "csiso_8859_2.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_2

void TPlISO_8859_2::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_2_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(813253931, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_2::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_2_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1145943827, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_2::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_2_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_2::TPlISO_8859_2(TPlISO_8859_2Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_2::TPlISO_8859_2() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_2_Create(&_Handle));
}

TPlISO_8859_2 TPlISO_8859_2::CreateForFinalize()
{
	TPlISO_8859_2Handle _Handle;
	SBCheckError(TPlISO_8859_2_CreateForFinalize(&_Handle));
	return TPlISO_8859_2(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_2 */

};	/* namespace SecureBlackbox */

