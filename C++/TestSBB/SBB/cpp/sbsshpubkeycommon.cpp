#include "sbsshpubkeycommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYATTRIBUTES

SB_INLINE void TElSSHPublicKeyAttributes::Add(const std::string &AName, const std::string &AValue, bool AMandatory)
{
	SBCheckError(TElSSHPublicKeyAttributes_Add(_Handle, AName.data(), (int32_t)AName.length(), AValue.data(), (int32_t)AValue.length(), (int8_t)AMandatory));
}

SB_INLINE void TElSSHPublicKeyAttributes::Remove(int32_t Index)
{
	SBCheckError(TElSSHPublicKeyAttributes_Remove(_Handle, Index));
}

SB_INLINE void TElSSHPublicKeyAttributes::Clear()
{
	SBCheckError(TElSSHPublicKeyAttributes_Clear(_Handle));
}

SB_INLINE int32_t TElSSHPublicKeyAttributes::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElSSHPublicKeyAttributes_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElSSHPublicKeyAttributes::get_Names(int32_t i, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHPublicKeyAttributes_get_Names(_Handle, i, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-740854253, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHPublicKeyAttributes::set_Names(int32_t i, const std::string &v)
{
	SBCheckError(TElSSHPublicKeyAttributes_set_Names(_Handle, i, v.data(), (int32_t)v.length()));
}

void TElSSHPublicKeyAttributes::get_Values(int32_t i, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHPublicKeyAttributes_get_Values(_Handle, i, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-497863317, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHPublicKeyAttributes::set_Values(int32_t i, const std::string &v)
{
	SBCheckError(TElSSHPublicKeyAttributes_set_Values(_Handle, i, v.data(), (int32_t)v.length()));
}

bool TElSSHPublicKeyAttributes::get_Mandatory(int32_t i)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHPublicKeyAttributes_get_Mandatory(_Handle, i, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHPublicKeyAttributes::set_Mandatory(int32_t i, bool v)
{
	SBCheckError(TElSSHPublicKeyAttributes_set_Mandatory(_Handle, i, (int8_t)v));
}

TElSSHPublicKeyAttributes::TElSSHPublicKeyAttributes(TElSSHPublicKeyAttributesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSHPublicKeyAttributes::TElSSHPublicKeyAttributes() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHPublicKeyAttributes_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSHPUBLICKEYATTRIBUTES */

};	/* namespace SecureBlackbox */

