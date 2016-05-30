#include "sbsshterm.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELTERMINALINFO

void TElTerminalInfo::GetTerminalType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTerminalInfo_GetTerminalType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(659168158, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTerminalInfo::SetTerminalType(const std::string &AValue)
{
	SBCheckError(TElTerminalInfo_SetTerminalType(_Handle, AValue.data(), (int32_t)AValue.length()));
}

SB_INLINE void TElTerminalInfo::SetDefaultOpcodes()
{
	SBCheckError(TElTerminalInfo_SetDefaultOpcodes(_Handle));
}

SB_INLINE void TElTerminalInfo::AddChangeNotification(const TSBTerminalChangeNotificationEvent pMethodValue, const void * pDataValue)
{
	SBCheckError(TElTerminalInfo_AddChangeNotification(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTerminalInfo::RemoveChangeNotification(TSBTerminalChangeNotificationEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTerminalInfo_RemoveChangeNotification(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTerminalInfo::BeginUpdate()
{
	SBCheckError(TElTerminalInfo_BeginUpdate(_Handle));
}

SB_INLINE void TElTerminalInfo::EndUpdate()
{
	SBCheckError(TElTerminalInfo_EndUpdate(_Handle));
}

SB_INLINE void TElTerminalInfo::ClearOpcodes()
{
	SBCheckError(TElTerminalInfo_ClearOpcodes(_Handle));
}

SB_INLINE int16_t TElTerminalInfo::get_Opcodes(int8_t Index)
{
	int16_t OutResult;
	SBCheckError(TElTerminalInfo_get_Opcodes(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElTerminalInfo::set_Opcodes(int8_t Index, int16_t Value)
{
	SBCheckError(TElTerminalInfo_set_Opcodes(_Handle, Index, Value));
}

void TElTerminalInfo::get_TerminalType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTerminalInfo_get_TerminalType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(832209224, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTerminalInfo::set_TerminalType(const std::string &Value)
{
	SBCheckError(TElTerminalInfo_set_TerminalType(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElTerminalInfo::get_Cols()
{
	int32_t OutResult;
	SBCheckError(TElTerminalInfo_get_Cols(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTerminalInfo::set_Cols(int32_t Value)
{
	SBCheckError(TElTerminalInfo_set_Cols(_Handle, Value));
}

SB_INLINE int32_t TElTerminalInfo::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElTerminalInfo_get_Width(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTerminalInfo::set_Width(int32_t Value)
{
	SBCheckError(TElTerminalInfo_set_Width(_Handle, Value));
}

SB_INLINE int32_t TElTerminalInfo::get_Rows()
{
	int32_t OutResult;
	SBCheckError(TElTerminalInfo_get_Rows(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTerminalInfo::set_Rows(int32_t Value)
{
	SBCheckError(TElTerminalInfo_set_Rows(_Handle, Value));
}

SB_INLINE int32_t TElTerminalInfo::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElTerminalInfo_get_Height(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTerminalInfo::set_Height(int32_t Value)
{
	SBCheckError(TElTerminalInfo_set_Height(_Handle, Value));
}

TElTerminalInfo::TElTerminalInfo(TElTerminalInfoHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElTerminalInfo::TElTerminalInfo(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTerminalInfo_Create(AOwner.getHandle(), &_Handle));
}

TElTerminalInfo::TElTerminalInfo(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTerminalInfo_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELTERMINALINFO */

};	/* namespace SecureBlackbox */

