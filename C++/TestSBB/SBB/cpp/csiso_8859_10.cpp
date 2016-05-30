#include "csiso_8859_10.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_10

void TPlISO_8859_10::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_10_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1527273504, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_10::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_10_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1139625658, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_10::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_10_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_10::TPlISO_8859_10(TPlISO_8859_10Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_10::TPlISO_8859_10() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_10_Create(&_Handle));
}

TPlISO_8859_10 TPlISO_8859_10::CreateForFinalize()
{
	TPlISO_8859_10Handle _Handle;
	SBCheckError(TPlISO_8859_10_CreateForFinalize(&_Handle));
	return TPlISO_8859_10(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_10 */

};	/* namespace SecureBlackbox */

