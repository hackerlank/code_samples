#include "sbimapclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELIMAPLITERALCONTEXT

void TElIMAPLiteralContext::get_Line(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPLiteralContext_get_Line(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1067686195, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElIMAPLiteralContext::set_Line(const std::string &Value)
{
	SBCheckError(TElIMAPLiteralContext_set_Line(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElIMAPLiteralContext::get_IsLiteral()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPLiteralContext_get_IsLiteral(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIMAPLiteralContext::set_IsLiteral(bool Value)
{
	SBCheckError(TElIMAPLiteralContext_set_IsLiteral(_Handle, (int8_t)Value));
}

TElIMAPLiteralContext::TElIMAPLiteralContext(TElIMAPLiteralContextHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElIMAPLiteralContext::TElIMAPLiteralContext(const std::string &Line) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPLiteralContext_Create(Line.data(), (int32_t)Line.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELIMAPLITERALCONTEXT */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE

SB_INLINE void TElIMAPMailBoxState::Clear()
{
	SBCheckError(TElIMAPMailBoxState_Clear(_Handle));
}

SB_INLINE void TElIMAPMailBoxState::CopyFrom(TElIMAPMailBoxState &Source)
{
	SBCheckError(TElIMAPMailBoxState_CopyFrom(_Handle, Source.getHandle()));
}

SB_INLINE void TElIMAPMailBoxState::CopyFrom(TElIMAPMailBoxState *Source)
{
	SBCheckError(TElIMAPMailBoxState_CopyFrom(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElIMAPMailBoxState::get_ReadWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPMailBoxState_get_ReadWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIMAPMailBoxState::set_ReadWrite(bool Value)
{
	SBCheckError(TElIMAPMailBoxState_set_ReadWrite(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElIMAPMailBoxState::get_TotalMessages()
{
	int32_t OutResult;
	SBCheckError(TElIMAPMailBoxState_get_TotalMessages(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElIMAPMailBoxState::set_TotalMessages(int32_t Value)
{
	SBCheckError(TElIMAPMailBoxState_set_TotalMessages(_Handle, Value));
}

SB_INLINE int32_t TElIMAPMailBoxState::get_RecentMessages()
{
	int32_t OutResult;
	SBCheckError(TElIMAPMailBoxState_get_RecentMessages(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElIMAPMailBoxState::set_RecentMessages(int32_t Value)
{
	SBCheckError(TElIMAPMailBoxState_set_RecentMessages(_Handle, Value));
}

SB_INLINE int32_t TElIMAPMailBoxState::get_UnseenMessages()
{
	int32_t OutResult;
	SBCheckError(TElIMAPMailBoxState_get_UnseenMessages(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElIMAPMailBoxState::set_UnseenMessages(int32_t Value)
{
	SBCheckError(TElIMAPMailBoxState_set_UnseenMessages(_Handle, Value));
}

TSBIMAPMessageFlags TElIMAPMailBoxState::get_Flags()
{
	TSBIMAPMessageFlagsRaw OutResultRaw = 0;
	SBCheckError(TElIMAPMailBoxState_get_Flags(_Handle, &OutResultRaw));
	return (TSBIMAPMessageFlags)OutResultRaw;
}

SB_INLINE void TElIMAPMailBoxState::set_Flags(TSBIMAPMessageFlags Value)
{
	SBCheckError(TElIMAPMailBoxState_set_Flags(_Handle, (TSBIMAPMessageFlagsRaw)Value));
}

TSBIMAPMessageFlags TElIMAPMailBoxState::get_PermanentFlags()
{
	TSBIMAPMessageFlagsRaw OutResultRaw = 0;
	SBCheckError(TElIMAPMailBoxState_get_PermanentFlags(_Handle, &OutResultRaw));
	return (TSBIMAPMessageFlags)OutResultRaw;
}

SB_INLINE void TElIMAPMailBoxState::set_PermanentFlags(TSBIMAPMessageFlags Value)
{
	SBCheckError(TElIMAPMailBoxState_set_PermanentFlags(_Handle, (TSBIMAPMessageFlagsRaw)Value));
}

SB_INLINE int32_t TElIMAPMailBoxState::get_NextUID()
{
	int32_t OutResult;
	SBCheckError(TElIMAPMailBoxState_get_NextUID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElIMAPMailBoxState::set_NextUID(int32_t Value)
{
	SBCheckError(TElIMAPMailBoxState_set_NextUID(_Handle, Value));
}

SB_INLINE int32_t TElIMAPMailBoxState::get_UIDValidity()
{
	int32_t OutResult;
	SBCheckError(TElIMAPMailBoxState_get_UIDValidity(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElIMAPMailBoxState::set_UIDValidity(int32_t Value)
{
	SBCheckError(TElIMAPMailBoxState_set_UIDValidity(_Handle, Value));
}

TElIMAPMailBoxState::TElIMAPMailBoxState(TElIMAPMailBoxStateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElIMAPMailBoxState::TElIMAPMailBoxState() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPMailBoxState_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXINFO

TElIMAPMailBoxAttributes TElIMAPMailBoxInfo::get_Attributes()
{
	TElIMAPMailBoxAttributesRaw OutResultRaw = 0;
	SBCheckError(TElIMAPMailBoxInfo_get_Attributes(_Handle, &OutResultRaw));
	return (TElIMAPMailBoxAttributes)OutResultRaw;
}

void TElIMAPMailBoxInfo::get_Delimiter(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPMailBoxInfo_get_Delimiter(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1361772936, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElIMAPMailBoxInfo::get_Delimiter(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElIMAPMailBoxInfo_get_Delimiter(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1361772936, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElIMAPMailBoxInfo::get_Name(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPMailBoxInfo_get_Name(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(690021164, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElIMAPMailBoxInfo::get_Name(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElIMAPMailBoxInfo_get_Name(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(690021164, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElIMAPMailBoxInfo::TElIMAPMailBoxInfo(TElIMAPMailBoxInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElIMAPMailBoxInfo::TElIMAPMailBoxInfo(TElIMAPMailBoxAttributes AAttributes, const sb_u16string &ADelimiter, const sb_u16string &AName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPMailBoxInfo_Create((TElIMAPMailBoxAttributesRaw)AAttributes, ADelimiter.data(), (int32_t)ADelimiter.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElIMAPMailBoxInfo::TElIMAPMailBoxInfo(TElIMAPMailBoxAttributes AAttributes, const std::wstring &ADelimiter, const std::wstring &AName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ADelimiter;
	sb_to_u16string(ADelimiter, u16ADelimiter);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElIMAPMailBoxInfo_Create((TElIMAPMailBoxAttributesRaw)AAttributes, reinterpret_cast<const sb_char16_t*>(u16ADelimiter.data()), (int32_t)u16ADelimiter.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXINFO */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXESLIST

#ifdef SB_USE_CLASS_TELIMAPMAILBOXINFO
SB_INLINE void TElIMAPMailBoxesList::Add(TElIMAPMailBoxInfo &Item)
{
	SBCheckError(TElIMAPMailBoxesList_Add(_Handle, Item.getHandle()));
}

SB_INLINE void TElIMAPMailBoxesList::Add(TElIMAPMailBoxInfo *Item)
{
	SBCheckError(TElIMAPMailBoxesList_Add(_Handle, (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELIMAPMAILBOXINFO */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXINFO
SB_INLINE TElIMAPMailBoxInfoHandle TElIMAPMailBoxesList::Get(int32_t Index)
{
	TElIMAPMailBoxInfoHandle OutResult;
	SBCheckError(TElIMAPMailBoxesList_Get(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELIMAPMAILBOXINFO */

SB_INLINE void TElIMAPMailBoxesList::Clear()
{
	SBCheckError(TElIMAPMailBoxesList_Clear(_Handle));
}

SB_INLINE int32_t TElIMAPMailBoxesList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElIMAPMailBoxesList_get_Count(_Handle, &OutResult));
	return OutResult;
}

TElIMAPMailBoxesList::TElIMAPMailBoxesList(TElIMAPMailBoxesListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElIMAPMailBoxesList::TElIMAPMailBoxesList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPMailBoxesList_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELIMAPMAILBOXESLIST */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM

SB_INLINE void TElIMAPFetchResponseItem::SetData(const std::string &AName, const std::string &AValue)
{
	SBCheckError(TElIMAPFetchResponseItem_SetData(_Handle, AName.data(), (int32_t)AName.length(), AValue.data(), (int32_t)AValue.length()));
}

TElIMAPFetchResponseItemType TElIMAPFetchResponseItem::get_ItemType()
{
	TElIMAPFetchResponseItemTypeRaw OutResultRaw = 0;
	SBCheckError(TElIMAPFetchResponseItem_get_ItemType(_Handle, &OutResultRaw));
	return (TElIMAPFetchResponseItemType)OutResultRaw;
}

void TElIMAPFetchResponseItem::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPFetchResponseItem_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-611588635, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElIMAPFetchResponseItem::get_RawValue(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPFetchResponseItem_get_RawValue(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1172411412, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElIMAPFetchResponseItem::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPFetchResponseItem_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-151802656, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElIMAPFetchResponseItem::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElIMAPFetchResponseItem_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-151802656, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElIMAPFetchResponseItem::get_DateTime()
{
	int64_t OutResult;
	SBCheckError(TElIMAPFetchResponseItem_get_DateTime(_Handle, &OutResult));
	return OutResult;
}

TSBIMAPMessageFlags TElIMAPFetchResponseItem::get_Flags()
{
	TSBIMAPMessageFlagsRaw OutResultRaw = 0;
	SBCheckError(TElIMAPFetchResponseItem_get_Flags(_Handle, &OutResultRaw));
	return (TSBIMAPMessageFlags)OutResultRaw;
}

SB_INLINE int64_t TElIMAPFetchResponseItem::get_Number()
{
	int64_t OutResult;
	SBCheckError(TElIMAPFetchResponseItem_get_Number(_Handle, &OutResult));
	return OutResult;
}

bool TElIMAPFetchResponseItem::get_Streamed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPFetchResponseItem_get_Streamed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElIMAPFetchResponseItem::TElIMAPFetchResponseItem(TElIMAPFetchResponseItemHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElIMAPFetchResponseItem::TElIMAPFetchResponseItem(const std::string &AName, const std::string &AValue) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPFetchResponseItem_Create(AName.data(), (int32_t)AName.length(), AValue.data(), (int32_t)AValue.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
SB_INLINE void TElIMAPFetchResponseLine::Add(TElIMAPFetchResponseItem &Item)
{
	SBCheckError(TElIMAPFetchResponseLine_Add(_Handle, Item.getHandle()));
}

SB_INLINE void TElIMAPFetchResponseLine::Add(TElIMAPFetchResponseItem *Item)
{
	SBCheckError(TElIMAPFetchResponseLine_Add(_Handle, (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
SB_INLINE TElIMAPFetchResponseItemHandle TElIMAPFetchResponseLine::Get(int32_t Index)
{
	TElIMAPFetchResponseItemHandle OutResult;
	SBCheckError(TElIMAPFetchResponseLine_Get(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
SB_INLINE TElIMAPFetchResponseItemHandle TElIMAPFetchResponseLine::GetByName(const std::string &Name)
{
	TElIMAPFetchResponseItemHandle OutResult;
	SBCheckError(TElIMAPFetchResponseLine_GetByName(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

SB_INLINE void TElIMAPFetchResponseLine::CopyFrom(TElIMAPFetchResponseLine &Source)
{
	SBCheckError(TElIMAPFetchResponseLine_CopyFrom(_Handle, Source.getHandle()));
}

SB_INLINE void TElIMAPFetchResponseLine::CopyFrom(TElIMAPFetchResponseLine *Source)
{
	SBCheckError(TElIMAPFetchResponseLine_CopyFrom(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElIMAPFetchResponseLine::Clear()
{
	SBCheckError(TElIMAPFetchResponseLine_Clear(_Handle));
}

SB_INLINE int32_t TElIMAPFetchResponseLine::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElIMAPFetchResponseLine_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElIMAPFetchResponseLine::get_ID()
{
	int32_t OutResult;
	SBCheckError(TElIMAPFetchResponseLine_get_ID(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
TElIMAPFetchResponseItem* TElIMAPFetchResponseLine::get_Items(const std::string &Name)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIMAPFetchResponseLine_get_Items(_Handle, Name.data(), (int32_t)Name.length(), &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElIMAPFetchResponseItem(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */

void TElIMAPFetchResponseLine::initInstances()
{
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */
}

TElIMAPFetchResponseLine::TElIMAPFetchResponseLine(TElIMAPFetchResponseLineHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElIMAPFetchResponseLine::TElIMAPFetchResponseLine(int32_t ID) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElIMAPFetchResponseLine_Create(ID, &_Handle));
}

TElIMAPFetchResponseLine::~TElIMAPFetchResponseLine()
{
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSEITEM */
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
SB_INLINE void TElIMAPFetchResponse::Add(TElIMAPFetchResponseLine &Line)
{
	SBCheckError(TElIMAPFetchResponse_Add(_Handle, Line.getHandle()));
}

SB_INLINE void TElIMAPFetchResponse::Add(TElIMAPFetchResponseLine *Line)
{
	SBCheckError(TElIMAPFetchResponse_Add(_Handle, (Line != NULL) ? Line->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
SB_INLINE TElIMAPFetchResponseLineHandle TElIMAPFetchResponse::Get(int32_t Index)
{
	TElIMAPFetchResponseLineHandle OutResult;
	SBCheckError(TElIMAPFetchResponse_Get(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
SB_INLINE TElIMAPFetchResponseLineHandle TElIMAPFetchResponse::GetByID(int32_t ID)
{
	TElIMAPFetchResponseLineHandle OutResult;
	SBCheckError(TElIMAPFetchResponse_GetByID(_Handle, ID, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

SB_INLINE void TElIMAPFetchResponse::Append(TElIMAPFetchResponse &Source)
{
	SBCheckError(TElIMAPFetchResponse_Append(_Handle, Source.getHandle()));
}

SB_INLINE void TElIMAPFetchResponse::Append(TElIMAPFetchResponse *Source)
{
	SBCheckError(TElIMAPFetchResponse_Append(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElIMAPFetchResponse::Clear()
{
	SBCheckError(TElIMAPFetchResponse_Clear(_Handle));
}

SB_INLINE int32_t TElIMAPFetchResponse::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElIMAPFetchResponse_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElIMAPFetchResponse::get_UID()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPFetchResponse_get_UID(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
TElIMAPFetchResponseLine* TElIMAPFetchResponse::get_Lines(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIMAPFetchResponse_get_Lines(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Lines)
		this->_Inst_Lines = new TElIMAPFetchResponseLine(hOutResult, ohFalse);
	else
		this->_Inst_Lines->updateHandle(hOutResult);
	return this->_Inst_Lines;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */

void TElIMAPFetchResponse::initInstances()
{
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
	this->_Inst_Lines = NULL;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */
}

TElIMAPFetchResponse::TElIMAPFetchResponse(TElIMAPFetchResponseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElIMAPFetchResponse::TElIMAPFetchResponse(bool UID) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElIMAPFetchResponse_Create((int8_t)UID, &_Handle));
}

TElIMAPFetchResponse::~TElIMAPFetchResponse()
{
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSELINE
	delete this->_Inst_Lines;
	this->_Inst_Lines = NULL;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSELINE */
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPIDLEUPDATE

SB_INLINE void TElIMAPIdleUpdate::Add(TElIMAPIdleUpdate &Update)
{
	SBCheckError(TElIMAPIdleUpdate_Add(_Handle, Update.getHandle()));
}

SB_INLINE void TElIMAPIdleUpdate::Add(TElIMAPIdleUpdate *Update)
{
	SBCheckError(TElIMAPIdleUpdate_Add(_Handle, (Update != NULL) ? Update->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElIMAPIdleUpdate::Clear()
{
	SBCheckError(TElIMAPIdleUpdate_Clear(_Handle));
}

TSBIMAPToken TElIMAPIdleUpdate::get_Token()
{
	TSBIMAPTokenRaw OutResultRaw = 0;
	SBCheckError(TElIMAPIdleUpdate_get_Token(_Handle, &OutResultRaw));
	return (TSBIMAPToken)OutResultRaw;
}

SB_INLINE void TElIMAPIdleUpdate::set_Token(TSBIMAPToken Value)
{
	SBCheckError(TElIMAPIdleUpdate_set_Token(_Handle, (TSBIMAPTokenRaw)Value));
}

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
TElIMAPMailBoxState* TElIMAPIdleUpdate::get_MailBoxState()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIMAPIdleUpdate_get_MailBoxState(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MailBoxState)
		this->_Inst_MailBoxState = new TElIMAPMailBoxState(hOutResult, ohFalse);
	else
		this->_Inst_MailBoxState->updateHandle(hOutResult);
	return this->_Inst_MailBoxState;
}
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
TElIMAPFetchResponse* TElIMAPIdleUpdate::get_ChangedMessages()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIMAPIdleUpdate_get_ChangedMessages(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ChangedMessages)
		this->_Inst_ChangedMessages = new TElIMAPFetchResponse(hOutResult, ohFalse);
	else
		this->_Inst_ChangedMessages->updateHandle(hOutResult);
	return this->_Inst_ChangedMessages;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
TElIMAPFetchResponse* TElIMAPIdleUpdate::get_ExpungedMessages()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIMAPIdleUpdate_get_ExpungedMessages(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExpungedMessages)
		this->_Inst_ExpungedMessages = new TElIMAPFetchResponse(hOutResult, ohFalse);
	else
		this->_Inst_ExpungedMessages->updateHandle(hOutResult);
	return this->_Inst_ExpungedMessages;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

void TElIMAPIdleUpdate::initInstances()
{
#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
	this->_Inst_MailBoxState = NULL;
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
	this->_Inst_ChangedMessages = NULL;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
	this->_Inst_ExpungedMessages = NULL;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */
}

TElIMAPIdleUpdate::TElIMAPIdleUpdate(TElIMAPIdleUpdateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElIMAPIdleUpdate::TElIMAPIdleUpdate() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElIMAPIdleUpdate_Create(&_Handle));
}

TElIMAPIdleUpdate::~TElIMAPIdleUpdate()
{
#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
	delete this->_Inst_MailBoxState;
	this->_Inst_MailBoxState = NULL;
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
	delete this->_Inst_ChangedMessages;
	this->_Inst_ChangedMessages = NULL;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */
#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
	delete this->_Inst_ExpungedMessages;
	this->_Inst_ExpungedMessages = NULL;
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */
}
#endif /* SB_USE_CLASS_TELIMAPIDLEUPDATE */

#ifdef SB_USE_CLASS_TELIMAPIDLETHREAD

SB_INLINE void TElIMAPIdleThread::Execute()
{
	SBCheckError(TElIMAPIdleThread_Execute(_Handle));
}

SB_INLINE void TElIMAPIdleThread::Start()
{
	SBCheckError(TElIMAPIdleThread_Start(_Handle));
}

SB_INLINE void TElIMAPIdleThread::WaitStop()
{
	SBCheckError(TElIMAPIdleThread_WaitStop(_Handle));
}

SB_INLINE void TElIMAPIdleThread::TryCallEvents()
{
	SBCheckError(TElIMAPIdleThread_TryCallEvents(_Handle));
}

TElIMAPIdleThread::TElIMAPIdleThread(TElIMAPIdleThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELIMAPCLIENT
TElIMAPIdleThread::TElIMAPIdleThread(TElIMAPClient &Client) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPIdleThread_Create(Client.getHandle(), &_Handle));
}

TElIMAPIdleThread::TElIMAPIdleThread(TElIMAPClient *Client) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPIdleThread_Create((Client != NULL) ? Client->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELIMAPCLIENT */

#endif /* SB_USE_CLASS_TELIMAPIDLETHREAD */

#ifdef SB_USE_CLASS_TELIMAPTIMEOUTTHREAD

SB_INLINE void TElIMAPTimeoutThread::Execute()
{
	SBCheckError(TElIMAPTimeoutThread_Execute(_Handle));
}

SB_INLINE void TElIMAPTimeoutThread::Start()
{
	SBCheckError(TElIMAPTimeoutThread_Start(_Handle));
}

SB_INLINE void TElIMAPTimeoutThread::Stop()
{
	SBCheckError(TElIMAPTimeoutThread_Stop(_Handle));
}

TElIMAPTimeoutThread::TElIMAPTimeoutThread(TElIMAPTimeoutThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELIMAPCLIENT
TElIMAPTimeoutThread::TElIMAPTimeoutThread(TElIMAPClient &Client) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPTimeoutThread_Create(Client.getHandle(), &_Handle));
}

TElIMAPTimeoutThread::TElIMAPTimeoutThread(TElIMAPClient *Client) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPTimeoutThread_Create((Client != NULL) ? Client->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELIMAPCLIENT */

#endif /* SB_USE_CLASS_TELIMAPTIMEOUTTHREAD */

#ifdef SB_USE_CLASS_TELIMAPCLIENT

SB_INLINE void TElIMAPClient::Open()
{
	SBCheckError(TElIMAPClient_Open(_Handle));
}

SB_INLINE void TElIMAPClient::ObtainCapabilities()
{
	SBCheckError(TElIMAPClient_ObtainCapabilities(_Handle));
}

SB_INLINE void TElIMAPClient::Login()
{
	SBCheckError(TElIMAPClient_Login(_Handle));
}

SB_INLINE void TElIMAPClient::Close(bool Silent)
{
	SBCheckError(TElIMAPClient_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElIMAPClient::Noop()
{
	SBCheckError(TElIMAPClient_Noop(_Handle));
}

#ifdef SB_USE_CLASS_TELIMAPMAILBOXESLIST
SB_INLINE void TElIMAPClient::List(const sb_u16string &RefName, const sb_u16string &MailBox, TElIMAPMailBoxesList &List)
{
	SBCheckError(TElIMAPClient_List(_Handle, RefName.data(), (int32_t)RefName.length(), MailBox.data(), (int32_t)MailBox.length(), List.getHandle()));
}

SB_INLINE void TElIMAPClient::List(const sb_u16string &RefName, const sb_u16string &MailBox, TElIMAPMailBoxesList *List)
{
	SBCheckError(TElIMAPClient_List(_Handle, RefName.data(), (int32_t)RefName.length(), MailBox.data(), (int32_t)MailBox.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::List(const std::wstring &RefName, const std::wstring &MailBox, TElIMAPMailBoxesList &List)
{
	std::string u16RefName;
	sb_to_u16string(RefName, u16RefName);
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_List(_Handle, reinterpret_cast<const sb_char16_t*>(u16RefName.data()), (int32_t)u16RefName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1, List.getHandle()));
}

SB_INLINE void TElIMAPClient::List(const std::wstring &RefName, const std::wstring &MailBox, TElIMAPMailBoxesList *List)
{
	std::string u16RefName;
	sb_to_u16string(RefName, u16RefName);
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_List(_Handle, reinterpret_cast<const sb_char16_t*>(u16RefName.data()), (int32_t)u16RefName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXESLIST */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXESLIST
SB_INLINE void TElIMAPClient::LSub(const sb_u16string &RefName, const sb_u16string &MailBox, TElIMAPMailBoxesList &List)
{
	SBCheckError(TElIMAPClient_LSub(_Handle, RefName.data(), (int32_t)RefName.length(), MailBox.data(), (int32_t)MailBox.length(), List.getHandle()));
}

SB_INLINE void TElIMAPClient::LSub(const sb_u16string &RefName, const sb_u16string &MailBox, TElIMAPMailBoxesList *List)
{
	SBCheckError(TElIMAPClient_LSub(_Handle, RefName.data(), (int32_t)RefName.length(), MailBox.data(), (int32_t)MailBox.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::LSub(const std::wstring &RefName, const std::wstring &MailBox, TElIMAPMailBoxesList &List)
{
	std::string u16RefName;
	sb_to_u16string(RefName, u16RefName);
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_LSub(_Handle, reinterpret_cast<const sb_char16_t*>(u16RefName.data()), (int32_t)u16RefName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1, List.getHandle()));
}

SB_INLINE void TElIMAPClient::LSub(const std::wstring &RefName, const std::wstring &MailBox, TElIMAPMailBoxesList *List)
{
	std::string u16RefName;
	sb_to_u16string(RefName, u16RefName);
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_LSub(_Handle, reinterpret_cast<const sb_char16_t*>(u16RefName.data()), (int32_t)u16RefName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXESLIST */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
SB_INLINE TElIMAPMailBoxStateHandle TElIMAPClient::SelectBox(const sb_u16string &MailBox)
{
	TElIMAPMailBoxStateHandle OutResult;
	SBCheckError(TElIMAPClient_SelectBox(_Handle, MailBox.data(), (int32_t)MailBox.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElIMAPMailBoxStateHandle TElIMAPClient::SelectBox(const std::wstring &MailBox)
{
	TElIMAPMailBoxStateHandle OutResult;
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_SelectBox(_Handle, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
SB_INLINE TElIMAPMailBoxStateHandle TElIMAPClient::ExamineBox(const sb_u16string &MailBox)
{
	TElIMAPMailBoxStateHandle OutResult;
	SBCheckError(TElIMAPClient_ExamineBox(_Handle, MailBox.data(), (int32_t)MailBox.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElIMAPMailBoxStateHandle TElIMAPClient::ExamineBox(const std::wstring &MailBox)
{
	TElIMAPMailBoxStateHandle OutResult;
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_ExamineBox(_Handle, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
SB_INLINE TElIMAPMailBoxStateHandle TElIMAPClient::StatusBox(const sb_u16string &MailBox, TSBIMAPStatusItems Items)
{
	TElIMAPMailBoxStateHandle OutResult;
	SBCheckError(TElIMAPClient_StatusBox(_Handle, MailBox.data(), (int32_t)MailBox.length(), (TSBIMAPStatusItemsRaw)Items, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElIMAPMailBoxStateHandle TElIMAPClient::StatusBox(const std::wstring &MailBox, TSBIMAPStatusItems Items)
{
	TElIMAPMailBoxStateHandle OutResult;
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_StatusBox(_Handle, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1, (TSBIMAPStatusItemsRaw)Items, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

SB_INLINE void TElIMAPClient::CloseBox()
{
	SBCheckError(TElIMAPClient_CloseBox(_Handle));
}

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_INLINE TElIMAPFetchResponseHandle TElIMAPClient::Fetch(int32_t First, int32_t Last, bool UID, const std::string &DataItemNames)
{
	TElIMAPFetchResponseHandle OutResult;
	SBCheckError(TElIMAPClient_Fetch(_Handle, First, Last, (int8_t)UID, DataItemNames.data(), (int32_t)DataItemNames.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_INLINE TElIMAPFetchResponseHandle TElIMAPClient::Fetch(TElIMAPFetchResponse &Sequence, const std::string &DataItemNames)
{
	TElIMAPFetchResponseHandle OutResult;
	SBCheckError(TElIMAPClient_Fetch_1(_Handle, Sequence.getHandle(), DataItemNames.data(), (int32_t)DataItemNames.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElIMAPFetchResponseHandle TElIMAPClient::Fetch(TElIMAPFetchResponse *Sequence, const std::string &DataItemNames)
{
	TElIMAPFetchResponseHandle OutResult;
	SBCheckError(TElIMAPClient_Fetch_1(_Handle, (Sequence != NULL) ? Sequence->getHandle() : SB_NULL_HANDLE, DataItemNames.data(), (int32_t)DataItemNames.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_INLINE void TElIMAPClient::Store(int32_t First, int32_t Last, bool UID, TSBIMAPStoreFlagsOperation Operation, TSBIMAPMessageFlags Flags, bool Silent, TElIMAPFetchResponse &Response)
{
	SBCheckError(TElIMAPClient_Store(_Handle, First, Last, (int8_t)UID, (TSBIMAPStoreFlagsOperationRaw)Operation, (TSBIMAPMessageFlagsRaw)Flags, (int8_t)Silent, Response.getHandle()));
}

SB_INLINE void TElIMAPClient::Store(int32_t First, int32_t Last, bool UID, TSBIMAPStoreFlagsOperation Operation, TSBIMAPMessageFlags Flags, bool Silent, TElIMAPFetchResponse *Response)
{
	SBCheckError(TElIMAPClient_Store(_Handle, First, Last, (int8_t)UID, (TSBIMAPStoreFlagsOperationRaw)Operation, (TSBIMAPMessageFlagsRaw)Flags, (int8_t)Silent, (Response != NULL) ? Response->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_INLINE void TElIMAPClient::Store(TElIMAPFetchResponse &Sequence, TSBIMAPStoreFlagsOperation Operation, TSBIMAPMessageFlags Flags, bool Silent, TElIMAPFetchResponse &Response)
{
	SBCheckError(TElIMAPClient_Store_1(_Handle, Sequence.getHandle(), (TSBIMAPStoreFlagsOperationRaw)Operation, (TSBIMAPMessageFlagsRaw)Flags, (int8_t)Silent, Response.getHandle()));
}

SB_INLINE void TElIMAPClient::Store(TElIMAPFetchResponse *Sequence, TSBIMAPStoreFlagsOperation Operation, TSBIMAPMessageFlags Flags, bool Silent, TElIMAPFetchResponse *Response)
{
	SBCheckError(TElIMAPClient_Store_1(_Handle, (Sequence != NULL) ? Sequence->getHandle() : SB_NULL_HANDLE, (TSBIMAPStoreFlagsOperationRaw)Operation, (TSBIMAPMessageFlagsRaw)Flags, (int8_t)Silent, (Response != NULL) ? Response->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_INLINE void TElIMAPClient::Expunge(TElIMAPFetchResponse &Response)
{
	SBCheckError(TElIMAPClient_Expunge(_Handle, Response.getHandle()));
}

SB_INLINE void TElIMAPClient::Expunge(TElIMAPFetchResponse *Response)
{
	SBCheckError(TElIMAPClient_Expunge(_Handle, (Response != NULL) ? Response->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

SB_INLINE void TElIMAPClient::Copy(int32_t First, int32_t Last, bool UID, const sb_u16string &MailBox)
{
	SBCheckError(TElIMAPClient_Copy(_Handle, First, Last, (int8_t)UID, MailBox.data(), (int32_t)MailBox.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::Copy(int32_t First, int32_t Last, bool UID, const std::wstring &MailBox)
{
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_Copy(_Handle, First, Last, (int8_t)UID, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_INLINE void TElIMAPClient::Copy(TElIMAPFetchResponse &Sequence, const sb_u16string &MailBox)
{
	SBCheckError(TElIMAPClient_Copy_1(_Handle, Sequence.getHandle(), MailBox.data(), (int32_t)MailBox.length()));
}

SB_INLINE void TElIMAPClient::Copy(TElIMAPFetchResponse *Sequence, const sb_u16string &MailBox)
{
	SBCheckError(TElIMAPClient_Copy_1(_Handle, (Sequence != NULL) ? Sequence->getHandle() : SB_NULL_HANDLE, MailBox.data(), (int32_t)MailBox.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::Copy(TElIMAPFetchResponse &Sequence, const std::wstring &MailBox)
{
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_Copy_1(_Handle, Sequence.getHandle(), reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1));
}

SB_INLINE void TElIMAPClient::Copy(TElIMAPFetchResponse *Sequence, const std::wstring &MailBox)
{
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_Copy_1(_Handle, (Sequence != NULL) ? Sequence->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElIMAPClient::FetchMessage(int32_t ID, bool UID, TStream &Stream)
{
	SBCheckError(TElIMAPClient_FetchMessage(_Handle, ID, (int8_t)UID, Stream.getHandle()));
}

SB_INLINE void TElIMAPClient::FetchMessage(int32_t ID, bool UID, TStream *Stream)
{
	SBCheckError(TElIMAPClient_FetchMessage(_Handle, ID, (int8_t)UID, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELMESSAGE
int32_t TElIMAPClient::FetchMessage(int32_t ID, bool UID, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions Options, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool ActivatePartHandlers, TElMessage &Message)
{
	int32_t OutResult;
	TElClassHandle hMessage = SB_NULL_HANDLE;
	SBCheckError(TElIMAPClient_FetchMessage_1(_Handle, ID, (int8_t)UID, HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)Options, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)ActivatePartHandlers, &hMessage, &OutResult));
	Message.updateHandle(hMessage);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMESSAGE */

SB_INLINE void TElIMAPClient::CreateBox(const sb_u16string &MailBox)
{
	SBCheckError(TElIMAPClient_CreateBox(_Handle, MailBox.data(), (int32_t)MailBox.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::CreateBox(const std::wstring &MailBox)
{
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_CreateBox(_Handle, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElIMAPClient::RenameBox(const sb_u16string &MailBox, const sb_u16string &NewName)
{
	SBCheckError(TElIMAPClient_RenameBox(_Handle, MailBox.data(), (int32_t)MailBox.length(), NewName.data(), (int32_t)NewName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::RenameBox(const std::wstring &MailBox, const std::wstring &NewName)
{
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	std::string u16NewName;
	sb_to_u16string(NewName, u16NewName);
	SBCheckError(TElIMAPClient_RenameBox(_Handle, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NewName.data()), (int32_t)u16NewName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElIMAPClient::DeleteBox(const sb_u16string &MailBox)
{
	SBCheckError(TElIMAPClient_DeleteBox(_Handle, MailBox.data(), (int32_t)MailBox.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::DeleteBox(const std::wstring &MailBox)
{
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_DeleteBox(_Handle, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElIMAPClient::Check()
{
	SBCheckError(TElIMAPClient_Check(_Handle));
}

SB_INLINE void TElIMAPClient::SubscribeBox(const sb_u16string &MailBox)
{
	SBCheckError(TElIMAPClient_SubscribeBox(_Handle, MailBox.data(), (int32_t)MailBox.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::SubscribeBox(const std::wstring &MailBox)
{
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_SubscribeBox(_Handle, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElIMAPClient::UnsubscribeBox(const sb_u16string &MailBox)
{
	SBCheckError(TElIMAPClient_UnsubscribeBox(_Handle, MailBox.data(), (int32_t)MailBox.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElIMAPClient::UnsubscribeBox(const std::wstring &MailBox)
{
	std::string u16MailBox;
	sb_to_u16string(MailBox, u16MailBox);
	SBCheckError(TElIMAPClient_UnsubscribeBox(_Handle, reinterpret_cast<const sb_char16_t*>(u16MailBox.data()), (int32_t)u16MailBox.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_INLINE TElIMAPFetchResponseHandle TElIMAPClient::Search(bool UID, const sb_u16string &Criteria)
{
	TElIMAPFetchResponseHandle OutResult;
	SBCheckError(TElIMAPClient_Search(_Handle, (int8_t)UID, Criteria.data(), (int32_t)Criteria.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElIMAPFetchResponseHandle TElIMAPClient::Search(bool UID, const std::wstring &Criteria)
{
	TElIMAPFetchResponseHandle OutResult;
	std::string u16Criteria;
	sb_to_u16string(Criteria, u16Criteria);
	SBCheckError(TElIMAPClient_Search(_Handle, (int8_t)UID, reinterpret_cast<const sb_char16_t*>(u16Criteria.data()), (int32_t)u16Criteria.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

#ifdef SB_USE_CLASS_TELIMAPFETCHRESPONSE
SB_INLINE TElIMAPFetchResponseHandle TElIMAPClient::Search(bool UID, const std::string &Criteria, const std::string &Charset)
{
	TElIMAPFetchResponseHandle OutResult;
	SBCheckError(TElIMAPClient_Search_1(_Handle, (int8_t)UID, Criteria.data(), (int32_t)Criteria.length(), Charset.data(), (int32_t)Charset.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELIMAPFETCHRESPONSE */

SB_INLINE void TElIMAPClient::Idle()
{
	SBCheckError(TElIMAPClient_Idle(_Handle));
}

SB_INLINE void TElIMAPClient::IdleDone()
{
	SBCheckError(TElIMAPClient_IdleDone(_Handle));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElIMAPClient::get_Capabilities()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIMAPClient_get_Capabilities(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Capabilities)
		this->_Inst_Capabilities = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Capabilities->updateHandle(hOutResult);
	return this->_Inst_Capabilities;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElIMAPClient::get_Capabilities()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIMAPClient_get_Capabilities(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Capabilities)
		this->_Inst_Capabilities = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Capabilities->updateHandle(hOutResult);
	return this->_Inst_Capabilities;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElIMAPClient::get_LoginDisabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPClient_get_LoginDisabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElIMAPClient::get_MailBox(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPClient_get_MailBox(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1647449821, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElIMAPClient::get_MailBox(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElIMAPClient_get_MailBox(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1647449821, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
TElIMAPMailBoxState* TElIMAPClient::get_MailBoxState()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIMAPClient_get_MailBoxState(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MailBoxState)
		this->_Inst_MailBoxState = new TElIMAPMailBoxState(hOutResult, ohFalse);
	else
		this->_Inst_MailBoxState->updateHandle(hOutResult);
	return this->_Inst_MailBoxState;
}
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */

bool TElIMAPClient::get_IdleSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPClient_get_IdleSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElIMAPClient::get_IdleActive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPClient_get_IdleActive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElIMAPClient::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPClient_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-240198217, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElIMAPClient::set_Address(const std::string &Value)
{
	SBCheckError(TElIMAPClient_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElIMAPClient::get_MaxLineLength()
{
	int32_t OutResult;
	SBCheckError(TElIMAPClient_get_MaxLineLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElIMAPClient::set_MaxLineLength(int32_t Value)
{
	SBCheckError(TElIMAPClient_set_MaxLineLength(_Handle, Value));
}

SB_INLINE int32_t TElIMAPClient::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElIMAPClient_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElIMAPClient::set_Port(int32_t Value)
{
	SBCheckError(TElIMAPClient_set_Port(_Handle, Value));
}

TSBSSLMode TElIMAPClient::get_SSLMode()
{
	TSBSSLModeRaw OutResultRaw = 0;
	SBCheckError(TElIMAPClient_get_SSLMode(_Handle, &OutResultRaw));
	return (TSBSSLMode)OutResultRaw;
}

SB_INLINE void TElIMAPClient::set_SSLMode(TSBSSLMode Value)
{
	SBCheckError(TElIMAPClient_set_SSLMode(_Handle, (TSBSSLModeRaw)Value));
}

TSBIMAPAutoCAPAMode TElIMAPClient::get_AutoCAPA()
{
	TSBIMAPAutoCAPAModeRaw OutResultRaw = 0;
	SBCheckError(TElIMAPClient_get_AutoCAPA(_Handle, &OutResultRaw));
	return (TSBIMAPAutoCAPAMode)OutResultRaw;
}

SB_INLINE void TElIMAPClient::set_AutoCAPA(TSBIMAPAutoCAPAMode Value)
{
	SBCheckError(TElIMAPClient_set_AutoCAPA(_Handle, (TSBIMAPAutoCAPAModeRaw)Value));
}

#ifdef SB_WINDOWS
bool TElIMAPClient::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPClient_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIMAPClient::set_UseIPv6(bool Value)
{
	SBCheckError(TElIMAPClient_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElIMAPClient::get_UseSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPClient_get_UseSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIMAPClient::set_UseSSL(bool Value)
{
	SBCheckError(TElIMAPClient_set_UseSSL(_Handle, (int8_t)Value));
}

void TElIMAPClient::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPClient_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-451240751, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElIMAPClient::set_Username(const std::string &Value)
{
	SBCheckError(TElIMAPClient_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElIMAPClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(679926899, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElIMAPClient::set_Password(const std::string &Value)
{
	SBCheckError(TElIMAPClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElIMAPClient::get_IdleAuto()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPClient_get_IdleAuto(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIMAPClient::set_IdleAuto(bool Value)
{
	SBCheckError(TElIMAPClient_set_IdleAuto(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElIMAPClient::get_IdleTimeout()
{
	int32_t OutResult;
	SBCheckError(TElIMAPClient_get_IdleTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElIMAPClient::set_IdleTimeout(int32_t Value)
{
	SBCheckError(TElIMAPClient_set_IdleTimeout(_Handle, Value));
}

SB_INLINE void TElIMAPClient::get_OnCapability(TSBIMAPTextLineEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnCapability(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnCapability(TSBIMAPTextLineEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnCapability(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnLog(TSBIMAPLogEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnLog(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnLog(TSBIMAPLogEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnLog(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnIdle(TSBIMAPIdleEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnIdle(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnIdle(TSBIMAPIdleEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnIdle(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnCertificateChoose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnCertificateChoose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnCertificateNeededEx(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnCertificateNeededEx(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnCertificateStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnCertificateStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnRenegotiationRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnRenegotiationRequest(_Handle, pMethodValue, pDataValue));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElIMAPClient::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElIMAPClient::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElIMAPClient_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElIMAPClient::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElIMAPClient_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

void TElIMAPClient::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Capabilities = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Capabilities = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
	this->_Inst_MailBoxState = NULL;
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */
}

TElIMAPClient::TElIMAPClient(TElIMAPClientHandle handle, TElOwnHandle ownHandle) : TElCustomSimpleSSLClient(handle, ownHandle)
{
	initInstances();
}

TElIMAPClient::TElIMAPClient(TComponent &AOwner) : TElCustomSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElIMAPClient_Create(AOwner.getHandle(), &_Handle));
}

TElIMAPClient::TElIMAPClient(TComponent *AOwner) : TElCustomSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElIMAPClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElIMAPClient::~TElIMAPClient()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Capabilities;
	this->_Inst_Capabilities = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Capabilities;
	this->_Inst_Capabilities = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELIMAPMAILBOXSTATE
	delete this->_Inst_MailBoxState;
	this->_Inst_MailBoxState = NULL;
#endif /* SB_USE_CLASS_TELIMAPMAILBOXSTATE */
}
#endif /* SB_USE_CLASS_TELIMAPCLIENT */

};	/* namespace SecureBlackbox */
