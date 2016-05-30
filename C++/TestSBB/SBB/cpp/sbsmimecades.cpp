#include "sbsmimecades.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIMECADES

void TElMessagePartHandlerSMimeCAdES::GetDescription(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerSMimeCAdES_GetDescription((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2012487970, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandlerSMimeCAdES::GetDescription(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandlerSMimeCAdES_GetDescription(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2012487970, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElMessagePartHandlerSMimeCAdES::GetDescription_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandlerSMimeCAdES_GetDescription_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2012487970, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandlerSMimeCAdES::GetDescription_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandlerSMimeCAdES_GetDescription_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2012487970, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE TClassHandle TElMessagePartHandlerSMimeCAdES::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElMessagePartHandlerSMimeCAdES_ClassType(&OutResult));
	return OutResult;
}

bool TElMessagePartHandlerSMimeCAdES::get_UseCAdES()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMimeCAdES_get_UseCAdES(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePartHandlerSMimeCAdES::set_UseCAdES(bool Value)
{
	SBCheckError(TElMessagePartHandlerSMimeCAdES_set_UseCAdES(_Handle, (int8_t)Value));
}

TSBCAdESSignatureValidity TElMessagePartHandlerSMimeCAdES::get_CAdESValidity()
{
	TSBCAdESSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMimeCAdES_get_CAdESValidity(_Handle, &OutResultRaw));
	return (TSBCAdESSignatureValidity)OutResultRaw;
}

SB_INLINE int32_t TElMessagePartHandlerSMimeCAdES::get_CAdESErrorCode()
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandlerSMimeCAdES_get_CAdESErrorCode(_Handle, &OutResult));
	return OutResult;
}

TSBCertificateValidity TElMessagePartHandlerSMimeCAdES::get_CAdESCertValidity()
{
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMimeCAdES_get_CAdESCertValidity(_Handle, &OutResultRaw));
	return (TSBCertificateValidity)OutResultRaw;
}

TSBCertificateValidityReason TElMessagePartHandlerSMimeCAdES::get_CAdESReason()
{
	TSBCertificateValidityReasonRaw OutResultRaw = 0;
	SBCheckError(TElMessagePartHandlerSMimeCAdES_get_CAdESReason(_Handle, &OutResultRaw));
	return (TSBCertificateValidityReason)OutResultRaw;
}

SB_INLINE void TElMessagePartHandlerSMimeCAdES::get_OnSign(TSBSMimeCAdESSign &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerSMimeCAdES_get_OnSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerSMimeCAdES::set_OnSign(TSBSMimeCAdESSign pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerSMimeCAdES_set_OnSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElMessagePartHandlerSMimeCAdES::get_OnValidate(TSBSMimeCAdESValidate &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessagePartHandlerSMimeCAdES_get_OnValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessagePartHandlerSMimeCAdES::set_OnValidate(TSBSMimeCAdESValidate pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessagePartHandlerSMimeCAdES_set_OnValidate(_Handle, pMethodValue, pDataValue));
}

TElMessagePartHandlerSMimeCAdES::TElMessagePartHandlerSMimeCAdES(TElMessagePartHandlerSMimeCAdESHandle handle, TElOwnHandle ownHandle) : TElMessagePartHandlerSMime(handle, ownHandle)
{
}

TElMessagePartHandlerSMimeCAdES::TElMessagePartHandlerSMimeCAdES(TObject &aParams) : TElMessagePartHandlerSMime(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessagePartHandlerSMimeCAdES_Create(aParams.getHandle(), &_Handle));
}

TElMessagePartHandlerSMimeCAdES::TElMessagePartHandlerSMimeCAdES(TObject *aParams) : TElMessagePartHandlerSMime(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessagePartHandlerSMimeCAdES_Create((aParams != NULL) ? aParams->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIMECADES */

};	/* namespace SecureBlackbox */

