#include "csiso_8859_4.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_4

void TPlISO_8859_4::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_4_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-347083158, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_4::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_4_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2057032088, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_4::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_4_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_4::TPlISO_8859_4(TPlISO_8859_4Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_4::TPlISO_8859_4() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_4_Create(&_Handle));
}

TPlISO_8859_4 TPlISO_8859_4::CreateForFinalize()
{
	TPlISO_8859_4Handle _Handle;
	SBCheckError(TPlISO_8859_4_CreateForFinalize(&_Handle));
	return TPlISO_8859_4(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_4 */

};	/* namespace SecureBlackbox */

