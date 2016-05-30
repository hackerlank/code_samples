#include "csatarist.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLATARIST

void TPlAtariST::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlAtariST_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1734444265, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlAtariST::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlAtariST_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1822905, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlAtariST::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlAtariST_ClassType(&OutResult));
	return OutResult;
}

TPlAtariST::TPlAtariST(TPlAtariSTHandle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlAtariST::TPlAtariST() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlAtariST_Create(&_Handle));
}

TPlAtariST TPlAtariST::CreateForFinalize()
{
	TPlAtariSTHandle _Handle;
	SBCheckError(TPlAtariST_CreateForFinalize(&_Handle));
	return TPlAtariST(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLATARIST */

};	/* namespace SecureBlackbox */

