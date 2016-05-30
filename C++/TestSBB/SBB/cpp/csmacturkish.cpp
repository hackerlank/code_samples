#include "csmacturkish.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLMACTURKISH

void TPlMacTurkish::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacTurkish_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1592477133, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlMacTurkish::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlMacTurkish_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1479085420, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlMacTurkish::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMacTurkish_ClassType(&OutResult));
	return OutResult;
}

TPlMacTurkish::TPlMacTurkish(TPlMacTurkishHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlMacTurkish::TPlMacTurkish() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMacTurkish_Create(&_Handle));
}

TPlMacTurkish TPlMacTurkish::CreateForFinalize()
{
	TPlMacTurkishHandle _Handle;
	SBCheckError(TPlMacTurkish_CreateForFinalize(&_Handle));
	return TPlMacTurkish(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMACTURKISH */

};	/* namespace SecureBlackbox */

