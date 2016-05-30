#include "sbwebsocketcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE

SB_INLINE TElWebSocketMessageHandle TElWebSocketMessage::Clone()
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketMessage_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebSocketMessage::Clear()
{
	SBCheckError(TElWebSocketMessage_Clear(_Handle));
}

bool TElWebSocketMessage::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElWebSocketMessage_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1196885365, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

bool TElWebSocketMessage::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketMessage_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebSocketMessage::get_IsFinal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketMessage_get_IsFinal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebSocketMessage::set_IsFinal(bool Value)
{
	SBCheckError(TElWebSocketMessage_set_IsFinal(_Handle, (int8_t)Value));
}

bool TElWebSocketMessage::get_RSV1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketMessage_get_RSV1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebSocketMessage::set_RSV1(bool Value)
{
	SBCheckError(TElWebSocketMessage_set_RSV1(_Handle, (int8_t)Value));
}

bool TElWebSocketMessage::get_RSV2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketMessage_get_RSV2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebSocketMessage::set_RSV2(bool Value)
{
	SBCheckError(TElWebSocketMessage_set_RSV2(_Handle, (int8_t)Value));
}

bool TElWebSocketMessage::get_RSV3()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketMessage_get_RSV3(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebSocketMessage::set_RSV3(bool Value)
{
	SBCheckError(TElWebSocketMessage_set_RSV3(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElWebSocketMessage::get_OpCode()
{
	uint8_t OutResult;
	SBCheckError(TElWebSocketMessage_get_OpCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebSocketMessage::set_OpCode(uint8_t Value)
{
	SBCheckError(TElWebSocketMessage_set_OpCode(_Handle, Value));
}

bool TElWebSocketMessage::get_Mask()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketMessage_get_Mask(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebSocketMessage::set_Mask(bool Value)
{
	SBCheckError(TElWebSocketMessage_set_Mask(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElWebSocketMessage::get_PayloadLen()
{
	int64_t OutResult;
	SBCheckError(TElWebSocketMessage_get_PayloadLen(_Handle, &OutResult));
	return OutResult;
}

bool TElWebSocketMessage::get_Fragmented()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketMessage_get_Fragmented(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElWebSocketMessage::get_MaskKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElWebSocketMessage_get_MaskKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-354037792, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebSocketMessage::set_MaskKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElWebSocketMessage_set_MaskKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElWebSocketMessage::get_PayloadData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElWebSocketMessage_get_PayloadData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1052436182, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebSocketMessage::set_PayloadData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElWebSocketMessage_set_PayloadData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElWebSocketMessage::get_FullSize()
{
	int32_t OutResult;
	SBCheckError(TElWebSocketMessage_get_FullSize(_Handle, &OutResult));
	return OutResult;
}

TElWebSocketMessage::TElWebSocketMessage(TElWebSocketMessageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebSocketMessage::TElWebSocketMessage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketMessage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

#ifdef SB_USE_CLASS_TELWEBSOCKETOPTION

SB_INLINE void TElWebSocketOption::Assign(TElWebSocketOption &Option)
{
	SBCheckError(TElWebSocketOption_Assign(_Handle, Option.getHandle()));
}

SB_INLINE void TElWebSocketOption::Assign(TElWebSocketOption *Option)
{
	SBCheckError(TElWebSocketOption_Assign(_Handle, (Option != NULL) ? Option->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElWebSocketOptionHandle TElWebSocketOption::Clone()
{
	TElWebSocketOptionHandle OutResult;
	SBCheckError(TElWebSocketOption_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElWebSocketOption::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketOption_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(678188887, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElWebSocketOption::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketOption_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebSocketOption::set_Active(bool Value)
{
	SBCheckError(TElWebSocketOption_set_Active(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElWebSocketOption::get_Priority()
{
	int32_t OutResult;
	SBCheckError(TElWebSocketOption_get_Priority(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebSocketOption::set_Priority(int32_t Value)
{
	SBCheckError(TElWebSocketOption_set_Priority(_Handle, Value));
}

void TElWebSocketOption::get_ParamStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketOption_get_ParamStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-16014019, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebSocketOption::set_ParamStr(const std::string &Value)
{
	SBCheckError(TElWebSocketOption_set_ParamStr(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebSocketOption::TElWebSocketOption(TElWebSocketOptionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebSocketOption::TElWebSocketOption() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketOption_Create(&_Handle));
}

TElWebSocketOption::TElWebSocketOption(int32_t APriority) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketOption_Create_1(APriority, &_Handle));
}

#endif /* SB_USE_CLASS_TELWEBSOCKETOPTION */

#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSION

SB_INLINE void TElWebSocketExtension::Clone(TElWebSocketExtensionHandle &OutResult)
{
	SBCheckError(TElWebSocketExtension_Clone(_Handle, &OutResult));
}

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
SB_INLINE TElWebSocketMessageHandle TElWebSocketExtension::Encode(TElWebSocketMessage &Msg)
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketExtension_Encode(_Handle, Msg.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebSocketMessageHandle TElWebSocketExtension::Encode(TElWebSocketMessage *Msg)
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketExtension_Encode(_Handle, (Msg != NULL) ? Msg->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
SB_INLINE TElWebSocketMessageHandle TElWebSocketExtension::Decode(TElWebSocketMessage &Msg)
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketExtension_Decode(_Handle, Msg.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebSocketMessageHandle TElWebSocketExtension::Decode(TElWebSocketMessage *Msg)
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketExtension_Decode(_Handle, (Msg != NULL) ? Msg->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

TElWebSocketExtension::TElWebSocketExtension(TElWebSocketExtensionHandle handle, TElOwnHandle ownHandle) : TElWebSocketOption(handle, ownHandle)
{
}

TElWebSocketExtension::TElWebSocketExtension() : TElWebSocketOption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketExtension_Create(&_Handle));
}

TElWebSocketExtension::TElWebSocketExtension(int32_t APriority) : TElWebSocketOption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketExtension_Create_1(APriority, &_Handle));
}

#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSION */

#ifdef SB_USE_CLASS_TELWEBSOCKETBASE

#ifdef SB_USE_CLASS_TELSSLCLASS
SB_INLINE void TElWebSocketBase::SetControl(TElSSLClass &Control)
{
	SBCheckError(TElWebSocketBase_SetControl(_Handle, Control.getHandle()));
}

SB_INLINE void TElWebSocketBase::SetControl(TElSSLClass *Control)
{
	SBCheckError(TElWebSocketBase_SetControl(_Handle, (Control != NULL) ? Control->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

void TElWebSocketBase::CreateWebSocketAccept(const std::string &Key, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketBase_CreateWebSocketAccept(Key.data(), (int32_t)Key.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1877254269, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebSocketBase::CreateWebSocketAccept_Inst(const std::string &Key, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketBase_CreateWebSocketAccept_1(_Handle, Key.data(), (int32_t)Key.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1877254269, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebSocketBase::Close(bool Silent)
{
	SBCheckError(TElWebSocketBase_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElWebSocketBase::Close(bool Silent, int32_t CloseDescription)
{
	SBCheckError(TElWebSocketBase_Close_1(_Handle, (int8_t)Silent, CloseDescription));
}

SB_INLINE void TElWebSocketBase::SendData(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElWebSocketBase_SendData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

SB_INLINE void TElWebSocketBase::SendData(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count)
{
	SBCheckError(TElWebSocketBase_SendData_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebSocketBase::SendData(const TStream &Strm)
{
	SBCheckError(TElWebSocketBase_SendData_2(_Handle, Strm.getHandle()));
}

SB_INLINE void TElWebSocketBase::SendData(const TStream *Strm)
{
	SBCheckError(TElWebSocketBase_SendData_2(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebSocketBase::SendData(const TStream &Strm, int32_t OpCode)
{
	SBCheckError(TElWebSocketBase_SendData_3(_Handle, Strm.getHandle(), OpCode));
}

SB_INLINE void TElWebSocketBase::SendData(const TStream *Strm, int32_t OpCode)
{
	SBCheckError(TElWebSocketBase_SendData_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, OpCode));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElWebSocketBase::SendText(const std::string &Text)
{
	SBCheckError(TElWebSocketBase_SendText(_Handle, Text.data(), (int32_t)Text.length()));
}

SB_INLINE void TElWebSocketBase::Ping()
{
	SBCheckError(TElWebSocketBase_Ping(_Handle));
}

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS
TElWebSocketSubProtocols* TElWebSocketBase::get_SubProtocols()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebSocketBase_get_SubProtocols(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubProtocols)
		this->_Inst_SubProtocols = new TElWebSocketSubProtocols(hOutResult, ohFalse);
	else
		this->_Inst_SubProtocols->updateHandle(hOutResult);
	return this->_Inst_SubProtocols;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS */

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
TElWebSocketSubProtocol* TElWebSocketBase::get_SubProtocol()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebSocketBase_get_SubProtocol(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubProtocol)
		this->_Inst_SubProtocol = new TElWebSocketSubProtocol(hOutResult, ohFalse);
	else
		this->_Inst_SubProtocol->updateHandle(hOutResult);
	return this->_Inst_SubProtocol;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSIONS
TElWebSocketExtensions* TElWebSocketBase::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebSocketBase_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElWebSocketExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSIONS */

TObject* TElWebSocketBase::get_Tag()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebSocketBase_get_Tag(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tag)
		this->_Inst_Tag = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Tag->updateHandle(hOutResult);
	return this->_Inst_Tag;
}

SB_INLINE void TElWebSocketBase::set_Tag(TObject &Value)
{
	SBCheckError(TElWebSocketBase_set_Tag(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebSocketBase::set_Tag(TObject *Value)
{
	SBCheckError(TElWebSocketBase_set_Tag(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

bool TElWebSocketBase::get_OwnTag()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketBase_get_OwnTag(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebSocketBase::set_OwnTag(bool Value)
{
	SBCheckError(TElWebSocketBase_set_OwnTag(_Handle, (int8_t)Value));
}

bool TElWebSocketBase::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebSocketBase_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElWebSocketBase::get_ProtocolStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketBase_get_ProtocolStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1414099983, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebSocketBase::get_PeerSubProtocolStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketBase_get_PeerSubProtocolStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-181925215, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebSocketBase::set_PeerSubProtocolStr(const std::string &Value)
{
	SBCheckError(TElWebSocketBase_set_PeerSubProtocolStr(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebSocketBase::get_ExtensionsStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketBase_get_ExtensionsStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1348538133, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebSocketBase::get_PeerExtensionsStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebSocketBase_get_PeerExtensionsStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-63096740, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebSocketBase::set_PeerExtensionsStr(const std::string &Value)
{
	SBCheckError(TElWebSocketBase_set_PeerExtensionsStr(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElWebSocketBase::get_FrameLength()
{
	int32_t OutResult;
	SBCheckError(TElWebSocketBase_get_FrameLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebSocketBase::set_FrameLength(int32_t Value)
{
	SBCheckError(TElWebSocketBase_set_FrameLength(_Handle, Value));
}

SB_INLINE void TElWebSocketBase::get_OnBeforeMessageSend(TSBWSBeforeMsgSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebSocketBase_get_OnBeforeMessageSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebSocketBase::set_OnBeforeMessageSend(TSBWSBeforeMsgSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebSocketBase_set_OnBeforeMessageSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebSocketBase::get_OnMessageReceived(TSBWSMsgReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebSocketBase_get_OnMessageReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebSocketBase::set_OnMessageReceived(TSBWSMsgReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebSocketBase_set_OnMessageReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebSocketBase::get_OnBinaryData(TSBWSBinaryDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebSocketBase_get_OnBinaryData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebSocketBase::set_OnBinaryData(TSBWSBinaryDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebSocketBase_set_OnBinaryData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebSocketBase::get_OnTextData(TSBWSTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebSocketBase_get_OnTextData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebSocketBase::set_OnTextData(TSBWSTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebSocketBase_set_OnTextData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebSocketBase::get_OnPong(TSBWSPongEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebSocketBase_get_OnPong(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebSocketBase::set_OnPong(TSBWSPongEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebSocketBase_set_OnPong(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebSocketBase::get_OnCloseConnection(TSBWSCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebSocketBase_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebSocketBase::set_OnCloseConnection(TSBWSCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebSocketBase_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

void TElWebSocketBase::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS
	this->_Inst_SubProtocols = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS */
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
	this->_Inst_SubProtocol = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */
#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSIONS */
	this->_Inst_Tag = NULL;
}

TElWebSocketBase::TElWebSocketBase(TElWebSocketBaseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebSocketBase::TElWebSocketBase() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebSocketBase_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELSSLCLASS
TElWebSocketBase::TElWebSocketBase(TElSSLClass &Control) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebSocketBase_Create_1(Control.getHandle(), &_Handle));
}

TElWebSocketBase::TElWebSocketBase(TElSSLClass *Control) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebSocketBase_Create_1((Control != NULL) ? Control->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

TElWebSocketBase::~TElWebSocketBase()
{
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS
	delete this->_Inst_SubProtocols;
	this->_Inst_SubProtocols = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS */
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
	delete this->_Inst_SubProtocol;
	this->_Inst_SubProtocol = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */
#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSIONS */
	delete this->_Inst_Tag;
	this->_Inst_Tag = NULL;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL

SB_INLINE void TElWebSocketSubProtocol::Clone(TElWebSocketSubProtocolHandle &OutResult)
{
	SBCheckError(TElWebSocketSubProtocol_Clone(_Handle, &OutResult));
}

#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
TElWebSocketBase* TElWebSocketSubProtocol::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebSocketSubProtocol_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElWebSocketBase(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

SB_INLINE void TElWebSocketSubProtocol::get_OnMessageReceived(TSBWSMsgReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebSocketSubProtocol_get_OnMessageReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebSocketSubProtocol::set_OnMessageReceived(TSBWSMsgReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebSocketSubProtocol_set_OnMessageReceived(_Handle, pMethodValue, pDataValue));
}

void TElWebSocketSubProtocol::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */
}

TElWebSocketSubProtocol::TElWebSocketSubProtocol(TElWebSocketSubProtocolHandle handle, TElOwnHandle ownHandle) : TElWebSocketOption(handle, ownHandle)
{
	initInstances();
}

TElWebSocketSubProtocol::TElWebSocketSubProtocol() : TElWebSocketOption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebSocketSubProtocol_Create(&_Handle));
}

TElWebSocketSubProtocol::TElWebSocketSubProtocol(int32_t APriority) : TElWebSocketOption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebSocketSubProtocol_Create_1(APriority, &_Handle));
}

TElWebSocketSubProtocol::~TElWebSocketSubProtocol()
{
#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */
}
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

#ifdef SB_USE_CLASS_TELWEBSOCKETEXTENSIONS

SB_INLINE void TElWebSocketExtensions::CopyTo(TElWebSocketExtensions &Exts)
{
	SBCheckError(TElWebSocketExtensions_CopyTo(_Handle, Exts.getHandle()));
}

SB_INLINE void TElWebSocketExtensions::CopyTo(TElWebSocketExtensions *Exts)
{
	SBCheckError(TElWebSocketExtensions_CopyTo(_Handle, (Exts != NULL) ? Exts->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
SB_INLINE TElWebSocketMessageHandle TElWebSocketExtensions::Encode(TElWebSocketMessage &Msg)
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketExtensions_Encode(_Handle, Msg.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebSocketMessageHandle TElWebSocketExtensions::Encode(TElWebSocketMessage *Msg)
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketExtensions_Encode(_Handle, (Msg != NULL) ? Msg->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

#ifdef SB_USE_CLASS_TELWEBSOCKETMESSAGE
SB_INLINE TElWebSocketMessageHandle TElWebSocketExtensions::Decode(TElWebSocketMessage &Msg)
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketExtensions_Decode(_Handle, Msg.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebSocketMessageHandle TElWebSocketExtensions::Decode(TElWebSocketMessage *Msg)
{
	TElWebSocketMessageHandle OutResult;
	SBCheckError(TElWebSocketExtensions_Decode(_Handle, (Msg != NULL) ? Msg->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETMESSAGE */

SB_INLINE int32_t TElWebSocketExtensions::Add(TElWebSocketExtension &Ext)
{
	int32_t OutResult;
	SBCheckError(TElWebSocketExtensions_Add(_Handle, Ext.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElWebSocketExtensions::Add(TElWebSocketExtension *Ext)
{
	int32_t OutResult;
	SBCheckError(TElWebSocketExtensions_Add(_Handle, (Ext != NULL) ? Ext->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebSocketExtensions::Remove(int32_t Index)
{
	SBCheckError(TElWebSocketExtensions_Remove(_Handle, Index));
}

SB_INLINE void TElWebSocketExtensions::Sort()
{
	SBCheckError(TElWebSocketExtensions_Sort(_Handle));
}

TElWebSocketExtension* TElWebSocketExtensions::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebSocketExtensions_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElWebSocketExtension(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}

SB_INLINE int32_t TElWebSocketExtensions::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebSocketExtensions_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebSocketExtensions::initInstances()
{
	this->_Inst_Items = NULL;
}

TElWebSocketExtensions::TElWebSocketExtensions(TElWebSocketExtensionsHandle handle, TElOwnHandle ownHandle) : TElWebSocketExtension(handle, ownHandle)
{
	initInstances();
}

TElWebSocketExtensions::TElWebSocketExtensions() : TElWebSocketExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebSocketExtensions_Create(&_Handle));
}

TElWebSocketExtensions::~TElWebSocketExtensions()
{
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETEXTENSIONS */

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS

SB_INLINE void TElWebSocketSubProtocols::CopyTo(TElWebSocketSubProtocols &Protos)
{
	SBCheckError(TElWebSocketSubProtocols_CopyTo(_Handle, Protos.getHandle()));
}

SB_INLINE void TElWebSocketSubProtocols::CopyTo(TElWebSocketSubProtocols *Protos)
{
	SBCheckError(TElWebSocketSubProtocols_CopyTo(_Handle, (Protos != NULL) ? Protos->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
SB_INLINE int32_t TElWebSocketSubProtocols::Add(TElWebSocketSubProtocol &Proto)
{
	int32_t OutResult;
	SBCheckError(TElWebSocketSubProtocols_Add(_Handle, Proto.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElWebSocketSubProtocols::Add(TElWebSocketSubProtocol *Proto)
{
	int32_t OutResult;
	SBCheckError(TElWebSocketSubProtocols_Add(_Handle, (Proto != NULL) ? Proto->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

SB_INLINE void TElWebSocketSubProtocols::Remove(int32_t Index)
{
	SBCheckError(TElWebSocketSubProtocols_Remove(_Handle, Index));
}

SB_INLINE void TElWebSocketSubProtocols::Sort()
{
	SBCheckError(TElWebSocketSubProtocols_Sort(_Handle));
}

#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
TElWebSocketSubProtocol* TElWebSocketSubProtocols::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebSocketSubProtocols_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElWebSocketSubProtocol(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */

SB_INLINE int32_t TElWebSocketSubProtocols::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebSocketSubProtocols_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
TElWebSocketBase* TElWebSocketSubProtocols::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebSocketSubProtocols_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElWebSocketBase(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */

void TElWebSocketSubProtocols::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */
#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */
}

TElWebSocketSubProtocols::TElWebSocketSubProtocols(TElWebSocketSubProtocolsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebSocketSubProtocols::TElWebSocketSubProtocols() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebSocketSubProtocols_Create(&_Handle));
}

TElWebSocketSubProtocols::~TElWebSocketSubProtocols()
{
#ifdef SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOL */
#ifdef SB_USE_CLASS_TELWEBSOCKETBASE
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELWEBSOCKETBASE */
}
#endif /* SB_USE_CLASS_TELWEBSOCKETSUBPROTOCOLS */

};	/* namespace SecureBlackbox */

