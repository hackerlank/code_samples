#include "csgeorgianacademy.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLGEORGIANACADEMY

void TPlGeorgianAcademy::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGeorgianAcademy_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1978419377, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlGeorgianAcademy::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGeorgianAcademy_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1850411514, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlGeorgianAcademy::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGeorgianAcademy_ClassType(&OutResult));
	return OutResult;
}

TPlGeorgianAcademy::TPlGeorgianAcademy(TPlGeorgianAcademyHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlGeorgianAcademy::TPlGeorgianAcademy() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGeorgianAcademy_Create(&_Handle));
}

TPlGeorgianAcademy TPlGeorgianAcademy::CreateForFinalize()
{
	TPlGeorgianAcademyHandle _Handle;
	SBCheckError(TPlGeorgianAcademy_CreateForFinalize(&_Handle));
	return TPlGeorgianAcademy(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGEORGIANACADEMY */

};	/* namespace SecureBlackbox */

