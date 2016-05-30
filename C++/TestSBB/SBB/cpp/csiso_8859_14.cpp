#include "csiso_8859_14.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_8859_14

void TPlISO_8859_14::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_14_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1077023390, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_14::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_14_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-885709522, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_14::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_14_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_14::TPlISO_8859_14(TPlISO_8859_14Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_14::TPlISO_8859_14() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_14_Create(&_Handle));
}

TPlISO_8859_14 TPlISO_8859_14::CreateForFinalize()
{
	TPlISO_8859_14Handle _Handle;
	SBCheckError(TPlISO_8859_14_CreateForFinalize(&_Handle));
	return TPlISO_8859_14(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_14 */

};	/* namespace SecureBlackbox */

