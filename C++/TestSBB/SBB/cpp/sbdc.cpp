#include "sbdc.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDCBASEMESSAGE

SB_INLINE void TElDCBaseMessage::Assign(TElDCBaseMessage &Source)
{
	SBCheckError(TElDCBaseMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDCBaseMessage::Assign(TElDCBaseMessage *Source)
{
	SBCheckError(TElDCBaseMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDCBaseMessage::InitializeMessage()
{
	SBCheckError(TElDCBaseMessage_InitializeMessage(_Handle));
}

SB_INLINE TElDCBaseMessageHandle TElDCBaseMessage::Clone()
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCBaseMessage_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElDCBaseMessageHandle TElDCBaseMessage::Clone(bool RenegerateID)
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCBaseMessage_Clone_1(_Handle, (int8_t)RenegerateID, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELDCNODE
SB_INLINE void TElDCBaseMessage::SaveToNode(TElDCNode &Node)
{
	SBCheckError(TElDCBaseMessage_SaveToNode(_Handle, Node.getHandle()));
}

SB_INLINE void TElDCBaseMessage::SaveToNode(TElDCNode *Node)
{
	SBCheckError(TElDCBaseMessage_SaveToNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASS_TELDCNODE
SB_INLINE void TElDCBaseMessage::LoadFromNode(TElDCNode &Node)
{
	SBCheckError(TElDCBaseMessage_LoadFromNode(_Handle, Node.getHandle()));
}

SB_INLINE void TElDCBaseMessage::LoadFromNode(TElDCNode *Node)
{
	SBCheckError(TElDCBaseMessage_LoadFromNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCBaseMessage::SaveToStream(TStream &Stream, TElDCEncoding &Encoding, const std::string &RootNodeName)
{
	SBCheckError(TElDCBaseMessage_SaveToStream(_Handle, Stream.getHandle(), Encoding.getHandle(), RootNodeName.data(), (int32_t)RootNodeName.length()));
}

SB_INLINE void TElDCBaseMessage::SaveToStream(TStream *Stream, TElDCEncoding *Encoding, const std::string &RootNodeName)
{
	SBCheckError(TElDCBaseMessage_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE, RootNodeName.data(), (int32_t)RootNodeName.length()));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCBaseMessage::LoadFromStream(TStream &Stream, TElDCEncoding &Encoding, int32_t Count)
{
	SBCheckError(TElDCBaseMessage_LoadFromStream(_Handle, Stream.getHandle(), Encoding.getHandle(), Count));
}

SB_INLINE void TElDCBaseMessage::LoadFromStream(TStream *Stream, TElDCEncoding *Encoding, int32_t Count)
{
	SBCheckError(TElDCBaseMessage_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

SB_INLINE TClassHandle TElDCBaseMessage::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDCBaseMessage_ClassType(&OutResult));
	return OutResult;
}

void TElDCBaseMessage::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCBaseMessage_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(953916284, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCBaseMessage::set_ID(const std::string &Value)
{
	SBCheckError(TElDCBaseMessage_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDCBaseMessage::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCBaseMessage_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1433569182, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCBaseMessage::set_Name(const std::string &Value)
{
	SBCheckError(TElDCBaseMessage_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElDCBaseMessage::get_Pars()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCBaseMessage_get_Pars(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Pars)
		this->_Inst_Pars = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_Pars->updateHandle(hOutResult);
	return this->_Inst_Pars;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

TElDCBaseMessage* TElDCBaseMessage::get_OriginalMessage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCBaseMessage_get_OriginalMessage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginalMessage)
		this->_Inst_OriginalMessage = new TElDCBaseMessage(hOutResult, ohFalse);
	else
		this->_Inst_OriginalMessage->updateHandle(hOutResult);
	return this->_Inst_OriginalMessage;
}

void TElDCBaseMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_Pars = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
	this->_Inst_OriginalMessage = NULL;
}

TElDCBaseMessage::TElDCBaseMessage(TElDCBaseMessageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDCBaseMessage::TElDCBaseMessage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCBaseMessage_Create(&_Handle));
}

TElDCBaseMessage::TElDCBaseMessage(TElDCBaseMessage &OrigMessage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCBaseMessage_Create_1(OrigMessage.getHandle(), &_Handle));
}

TElDCBaseMessage::TElDCBaseMessage(TElDCBaseMessage *OrigMessage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCBaseMessage_Create_1((OrigMessage != NULL) ? OrigMessage->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElDCBaseMessage::~TElDCBaseMessage()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_Pars;
	this->_Inst_Pars = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
	delete this->_Inst_OriginalMessage;
	this->_Inst_OriginalMessage = NULL;
}
#endif /* SB_USE_CLASS_TELDCBASEMESSAGE */

#ifdef SB_USE_CLASS_TELDCUNSUPPORTEDMESSAGE

SB_INLINE void TElDCUnsupportedMessage::Assign(TElDCBaseMessage &Source)
{
	SBCheckError(TElDCUnsupportedMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDCUnsupportedMessage::Assign(TElDCBaseMessage *Source)
{
	SBCheckError(TElDCUnsupportedMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElDCBaseMessageHandle TElDCUnsupportedMessage::Clone()
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCUnsupportedMessage_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElDCUnsupportedMessage::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDCUnsupportedMessage_ClassType(&OutResult));
	return OutResult;
}

TElDCUnsupportedMessage::TElDCUnsupportedMessage(TElDCUnsupportedMessageHandle handle, TElOwnHandle ownHandle) : TElDCBaseMessage(handle, ownHandle)
{
}

TElDCUnsupportedMessage::TElDCUnsupportedMessage() : TElDCBaseMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCUnsupportedMessage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCUNSUPPORTEDMESSAGE */

#ifdef SB_USE_CLASS_TELDCERRORMESSAGE

SB_INLINE void TElDCErrorMessage::Assign(TElDCBaseMessage &Source)
{
	SBCheckError(TElDCErrorMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDCErrorMessage::Assign(TElDCBaseMessage *Source)
{
	SBCheckError(TElDCErrorMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElDCBaseMessageHandle TElDCErrorMessage::Clone()
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCErrorMessage_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElDCErrorMessage::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDCErrorMessage_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCErrorMessage::get_Code()
{
	int32_t OutResult;
	SBCheckError(TElDCErrorMessage_get_Code(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDCErrorMessage::set_Code(int32_t Value)
{
	SBCheckError(TElDCErrorMessage_set_Code(_Handle, Value));
}

void TElDCErrorMessage::get_ErrorMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCErrorMessage_get_ErrorMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1945208040, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCErrorMessage::set_ErrorMessage(const std::string &Value)
{
	SBCheckError(TElDCErrorMessage_set_ErrorMessage(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDCErrorMessage::TElDCErrorMessage(TElDCErrorMessageHandle handle, TElOwnHandle ownHandle) : TElDCBaseMessage(handle, ownHandle)
{
}

TElDCErrorMessage::TElDCErrorMessage() : TElDCBaseMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCErrorMessage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCERRORMESSAGE */

#ifdef SB_USE_CLASS_TELDCOPERATIONREQUESTMESSAGE

SB_INLINE void TElDCOperationRequestMessage::Assign(TElDCBaseMessage &Source)
{
	SBCheckError(TElDCOperationRequestMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDCOperationRequestMessage::Assign(TElDCBaseMessage *Source)
{
	SBCheckError(TElDCOperationRequestMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElDCBaseMessageHandle TElDCOperationRequestMessage::Clone()
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCOperationRequestMessage_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElDCOperationRequestMessage::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDCOperationRequestMessage_ClassType(&OutResult));
	return OutResult;
}

TSBDCOperation TElDCOperationRequestMessage::get_Operation()
{
	TSBDCOperationRaw OutResultRaw = 0;
	SBCheckError(TElDCOperationRequestMessage_get_Operation(_Handle, &OutResultRaw));
	return (TSBDCOperation)OutResultRaw;
}

SB_INLINE void TElDCOperationRequestMessage::set_Operation(TSBDCOperation Value)
{
	SBCheckError(TElDCOperationRequestMessage_set_Operation(_Handle, (TSBDCOperationRaw)Value));
}

void TElDCOperationRequestMessage::get_OperationID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCOperationRequestMessage_get_OperationID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-679929423, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCOperationRequestMessage::set_OperationID(const std::string &Value)
{
	SBCheckError(TElDCOperationRequestMessage_set_OperationID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDCOperationRequestMessage::get_Source(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDCOperationRequestMessage_get_Source(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-593133734, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCOperationRequestMessage::set_Source(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDCOperationRequestMessage_set_Source(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDCOperationRequestMessage::get_HashAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDCOperationRequestMessage_get_HashAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-951433435, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCOperationRequestMessage::set_HashAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDCOperationRequestMessage_set_HashAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElDCOperationRequestMessage::get_IncludeKeysInResponse()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCOperationRequestMessage_get_IncludeKeysInResponse(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDCOperationRequestMessage::set_IncludeKeysInResponse(bool Value)
{
	SBCheckError(TElDCOperationRequestMessage_set_IncludeKeysInResponse(_Handle, (int8_t)Value));
}

TElDCOperationRequestMessage::TElDCOperationRequestMessage(TElDCOperationRequestMessageHandle handle, TElOwnHandle ownHandle) : TElDCBaseMessage(handle, ownHandle)
{
}

TElDCOperationRequestMessage::TElDCOperationRequestMessage() : TElDCBaseMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCOperationRequestMessage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCOPERATIONREQUESTMESSAGE */

#ifdef SB_USE_CLASS_TELDCOPERATIONRESPONSEMESSAGE

SB_INLINE void TElDCOperationResponseMessage::InitializeMessage()
{
	SBCheckError(TElDCOperationResponseMessage_InitializeMessage(_Handle));
}

SB_INLINE void TElDCOperationResponseMessage::Assign(TElDCBaseMessage &Source)
{
	SBCheckError(TElDCOperationResponseMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDCOperationResponseMessage::Assign(TElDCBaseMessage *Source)
{
	SBCheckError(TElDCOperationResponseMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElDCBaseMessageHandle TElDCOperationResponseMessage::Clone()
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCOperationResponseMessage_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElDCOperationResponseMessage::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDCOperationResponseMessage_ClassType(&OutResult));
	return OutResult;
}

TSBDCOperation TElDCOperationResponseMessage::get_Operation()
{
	TSBDCOperationRaw OutResultRaw = 0;
	SBCheckError(TElDCOperationResponseMessage_get_Operation(_Handle, &OutResultRaw));
	return (TSBDCOperation)OutResultRaw;
}

SB_INLINE void TElDCOperationResponseMessage::set_Operation(TSBDCOperation Value)
{
	SBCheckError(TElDCOperationResponseMessage_set_Operation(_Handle, (TSBDCOperationRaw)Value));
}

void TElDCOperationResponseMessage::get_OperationResult(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDCOperationResponseMessage_get_OperationResult(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1053847581, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCOperationResponseMessage::set_OperationResult(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDCOperationResponseMessage_set_OperationResult(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElDCOperationResponseMessage::get_KeysRDN()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCOperationResponseMessage_get_KeysRDN(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeysRDN)
		this->_Inst_KeysRDN = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_KeysRDN->updateHandle(hOutResult);
	return this->_Inst_KeysRDN;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElDCOperationResponseMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_KeysRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElDCOperationResponseMessage::TElDCOperationResponseMessage(TElDCOperationResponseMessageHandle handle, TElOwnHandle ownHandle) : TElDCBaseMessage(handle, ownHandle)
{
	initInstances();
}

TElDCOperationResponseMessage::TElDCOperationResponseMessage() : TElDCBaseMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCOperationResponseMessage_Create(&_Handle));
}

TElDCOperationResponseMessage::TElDCOperationResponseMessage(TElDCBaseMessage &OrigMessage) : TElDCBaseMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCOperationResponseMessage_Create_1(OrigMessage.getHandle(), &_Handle));
}

TElDCOperationResponseMessage::TElDCOperationResponseMessage(TElDCBaseMessage *OrigMessage) : TElDCBaseMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCOperationResponseMessage_Create_1((OrigMessage != NULL) ? OrigMessage->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElDCOperationResponseMessage::~TElDCOperationResponseMessage()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_KeysRDN;
	this->_Inst_KeysRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELDCOPERATIONRESPONSEMESSAGE */

#ifdef SB_USE_CLASS_TELDCBATCHMESSAGE

SB_INLINE void TElDCBatchMessage::Assign(TElDCBaseMessage &Source)
{
	SBCheckError(TElDCBatchMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDCBatchMessage::Assign(TElDCBaseMessage *Source)
{
	SBCheckError(TElDCBatchMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElDCBaseMessageHandle TElDCBatchMessage::Clone()
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCBatchMessage_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCBatchMessage::Add(TElDCBaseMessage &Message, bool CreateCopy)
{
	int32_t OutResult;
	SBCheckError(TElDCBatchMessage_Add(_Handle, Message.getHandle(), (int8_t)CreateCopy, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCBatchMessage::Add(TElDCBaseMessage *Message, bool CreateCopy)
{
	int32_t OutResult;
	SBCheckError(TElDCBatchMessage_Add(_Handle, (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE, (int8_t)CreateCopy, &OutResult));
	return OutResult;
}

SB_INLINE void TElDCBatchMessage::Remove(int32_t Index)
{
	SBCheckError(TElDCBatchMessage_Remove(_Handle, Index));
}

SB_INLINE void TElDCBatchMessage::Clear()
{
	SBCheckError(TElDCBatchMessage_Clear(_Handle));
}

SB_INLINE TClassHandle TElDCBatchMessage::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDCBatchMessage_ClassType(&OutResult));
	return OutResult;
}

TElDCBaseMessage* TElDCBatchMessage::get_Messages(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCBatchMessage_get_Messages(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Messages)
		this->_Inst_Messages = new TElDCBaseMessage(hOutResult, ohFalse);
	else
		this->_Inst_Messages->updateHandle(hOutResult);
	return this->_Inst_Messages;
}

SB_INLINE int32_t TElDCBatchMessage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDCBatchMessage_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElDCBatchMessage::initInstances()
{
	this->_Inst_Messages = NULL;
}

TElDCBatchMessage::TElDCBatchMessage(TElDCBatchMessageHandle handle, TElOwnHandle ownHandle) : TElDCBaseMessage(handle, ownHandle)
{
	initInstances();
}

TElDCBatchMessage::TElDCBatchMessage() : TElDCBaseMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCBatchMessage_Create(&_Handle));
}

TElDCBatchMessage::~TElDCBatchMessage()
{
	delete this->_Inst_Messages;
	this->_Inst_Messages = NULL;
}
#endif /* SB_USE_CLASS_TELDCBATCHMESSAGE */

#ifdef SB_USE_CLASS_TELDCMESSAGEFACTORY

#ifdef SB_USE_CLASSES_TELDCBASEMESSAGE_AND_TELDCENCODING_AND_TSTREAM
SB_INLINE TElDCBaseMessageHandle TElDCMessageFactory::CreateInstance(TStream &Stream, TElDCEncoding &Encoding)
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCMessageFactory_CreateInstance(_Handle, Stream.getHandle(), Encoding.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCBaseMessageHandle TElDCMessageFactory::CreateInstance(TStream *Stream, TElDCEncoding *Encoding)
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCMessageFactory_CreateInstance(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCBASEMESSAGE_AND_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCBASEMESSAGE_AND_TELDCNODE
SB_INLINE TElDCBaseMessageHandle TElDCMessageFactory::CreateInstance(TElDCNode &Node)
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCMessageFactory_CreateInstance_1(_Handle, Node.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCBaseMessageHandle TElDCMessageFactory::CreateInstance(TElDCNode *Node)
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCMessageFactory_CreateInstance_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCBASEMESSAGE_AND_TELDCNODE */

SB_INLINE void TElDCMessageFactory::RegisterClass(TElDCMessageClassHandle Cls)
{
	SBCheckError(TElDCMessageFactory_RegisterClass(_Handle, Cls));
}

TElDCMessageFactory::TElDCMessageFactory(TElDCMessageFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDCMessageFactory::TElDCMessageFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCMessageFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCMESSAGEFACTORY */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE

SB_INLINE TElDCAsyncStateHandle TElDCAsyncState::Clone()
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElDCAsyncState_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELDCNODE
SB_INLINE void TElDCAsyncState::SaveToNode(TElDCNode &Node)
{
	SBCheckError(TElDCAsyncState_SaveToNode(_Handle, Node.getHandle()));
}

SB_INLINE void TElDCAsyncState::SaveToNode(TElDCNode *Node)
{
	SBCheckError(TElDCAsyncState_SaveToNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCAsyncState::SaveToStream(TStream &Stream, TElDCEncoding &Encoding)
{
	SBCheckError(TElDCAsyncState_SaveToStream(_Handle, Stream.getHandle(), Encoding.getHandle()));
}

SB_INLINE void TElDCAsyncState::SaveToStream(TStream *Stream, TElDCEncoding *Encoding)
{
	SBCheckError(TElDCAsyncState_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELDCNODE
SB_INLINE void TElDCAsyncState::LoadFromNode(TElDCNode &Node)
{
	SBCheckError(TElDCAsyncState_LoadFromNode(_Handle, Node.getHandle()));
}

SB_INLINE void TElDCAsyncState::LoadFromNode(TElDCNode *Node)
{
	SBCheckError(TElDCAsyncState_LoadFromNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCAsyncState::LoadFromStream(TStream &Stream, TElDCEncoding &Encoding)
{
	SBCheckError(TElDCAsyncState_LoadFromStream(_Handle, Stream.getHandle(), Encoding.getHandle()));
}

SB_INLINE void TElDCAsyncState::LoadFromStream(TStream *Stream, TElDCEncoding *Encoding)
{
	SBCheckError(TElDCAsyncState_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

bool TElDCAsyncState::SubtypePresent(const std::string &Subtype)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDCAsyncState_SubtypePresent(_Handle, Subtype.data(), (int32_t)Subtype.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELDCBASEMESSAGE
SB_INLINE TElDCBaseMessageHandle TElDCAsyncState::FindMessageByType(TElDCMessageClassHandle MsgType)
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCAsyncState_FindMessageByType(_Handle, MsgType, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCBASEMESSAGE */

#ifdef SB_USE_CLASS_TELDCBASEMESSAGE
SB_INLINE TElDCBaseMessageHandle TElDCAsyncState::FindMessageByName(const std::string &Name)
{
	TElDCBaseMessageHandle OutResult;
	SBCheckError(TElDCAsyncState_FindMessageByName(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCBASEMESSAGE */

#ifdef SB_USE_CLASS_TELDCBATCHMESSAGE
TElDCBatchMessage* TElDCAsyncState::get_Messages()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCAsyncState_get_Messages(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Messages)
		this->_Inst_Messages = new TElDCBatchMessage(hOutResult, ohFalse);
	else
		this->_Inst_Messages->updateHandle(hOutResult);
	return this->_Inst_Messages;
}
#endif /* SB_USE_CLASS_TELDCBATCHMESSAGE */

void TElDCAsyncState::get_StateType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCAsyncState_get_StateType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1751964859, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCAsyncState::set_StateType(const std::string &Value)
{
	SBCheckError(TElDCAsyncState_set_StateType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElDCAsyncState::get_StateSubtypes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCAsyncState_get_StateSubtypes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StateSubtypes)
		this->_Inst_StateSubtypes = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_StateSubtypes->updateHandle(hOutResult);
	return this->_Inst_StateSubtypes;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElDCAsyncState::get_StateSubtypes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCAsyncState_get_StateSubtypes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StateSubtypes)
		this->_Inst_StateSubtypes = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_StateSubtypes->updateHandle(hOutResult);
	return this->_Inst_StateSubtypes;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElDCAsyncState::get_UserData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDCAsyncState_get_UserData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1128690327, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCAsyncState::set_UserData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDCAsyncState_set_UserData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDCAsyncState::get_Generator(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCAsyncState_get_Generator(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1157039279, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElDCAsyncState* TElDCAsyncState::get_InnerState()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCAsyncState_get_InnerState(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InnerState)
		this->_Inst_InnerState = new TElDCAsyncState(hOutResult, ohFalse);
	else
		this->_Inst_InnerState->updateHandle(hOutResult);
	return this->_Inst_InnerState;
}

void TElDCAsyncState::initInstances()
{
#ifdef SB_USE_CLASS_TELDCBATCHMESSAGE
	this->_Inst_Messages = NULL;
#endif /* SB_USE_CLASS_TELDCBATCHMESSAGE */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_StateSubtypes = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_StateSubtypes = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
	this->_Inst_InnerState = NULL;
}

TElDCAsyncState::TElDCAsyncState(TElDCAsyncStateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDCAsyncState::TElDCAsyncState() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCAsyncState_Create(&_Handle));
}

TElDCAsyncState::TElDCAsyncState(TElDCAsyncState &InnerState, bool ReleaseOnDestruction) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCAsyncState_Create_1(InnerState.getHandle(), (int8_t)ReleaseOnDestruction, &_Handle));
}

TElDCAsyncState::TElDCAsyncState(TElDCAsyncState *InnerState, bool ReleaseOnDestruction) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCAsyncState_Create_1((InnerState != NULL) ? InnerState->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseOnDestruction, &_Handle));
}

TElDCAsyncState::~TElDCAsyncState()
{
#ifdef SB_USE_CLASS_TELDCBATCHMESSAGE
	delete this->_Inst_Messages;
	this->_Inst_Messages = NULL;
#endif /* SB_USE_CLASS_TELDCBATCHMESSAGE */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_StateSubtypes;
	this->_Inst_StateSubtypes = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_StateSubtypes;
	this->_Inst_StateSubtypes = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
	delete this->_Inst_InnerState;
	this->_Inst_InnerState = NULL;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATECOLLECTION

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE int32_t TElDCAsyncStateCollection::Add(TElDCAsyncState &State, bool Clone)
{
	int32_t OutResult;
	SBCheckError(TElDCAsyncStateCollection_Add(_Handle, State.getHandle(), (int8_t)Clone, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCAsyncStateCollection::Add(TElDCAsyncState *State, bool Clone)
{
	int32_t OutResult;
	SBCheckError(TElDCAsyncStateCollection_Add(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (int8_t)Clone, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

SB_INLINE void TElDCAsyncStateCollection::Remove(int32_t Index)
{
	SBCheckError(TElDCAsyncStateCollection_Remove(_Handle, Index));
}

SB_INLINE void TElDCAsyncStateCollection::Clear()
{
	SBCheckError(TElDCAsyncStateCollection_Clear(_Handle));
}

SB_INLINE int32_t TElDCAsyncStateCollection::FindState(const std::vector<uint8_t> &UserData)
{
	int32_t OutResult;
	SBCheckError(TElDCAsyncStateCollection_FindState(_Handle, SB_STD_VECTOR_FRONT_ADR(UserData), (int32_t)UserData.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELDCNODE
SB_INLINE void TElDCAsyncStateCollection::SaveToNode(TElDCNode &Node)
{
	SBCheckError(TElDCAsyncStateCollection_SaveToNode(_Handle, Node.getHandle()));
}

SB_INLINE void TElDCAsyncStateCollection::SaveToNode(TElDCNode *Node)
{
	SBCheckError(TElDCAsyncStateCollection_SaveToNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCAsyncStateCollection::SaveToStream(TStream &Stream, TElDCEncoding &Encoding)
{
	SBCheckError(TElDCAsyncStateCollection_SaveToStream(_Handle, Stream.getHandle(), Encoding.getHandle()));
}

SB_INLINE void TElDCAsyncStateCollection::SaveToStream(TStream *Stream, TElDCEncoding *Encoding)
{
	SBCheckError(TElDCAsyncStateCollection_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELDCNODE
SB_INLINE void TElDCAsyncStateCollection::LoadFromNode(TElDCNode &Node)
{
	SBCheckError(TElDCAsyncStateCollection_LoadFromNode(_Handle, Node.getHandle()));
}

SB_INLINE void TElDCAsyncStateCollection::LoadFromNode(TElDCNode *Node)
{
	SBCheckError(TElDCAsyncStateCollection_LoadFromNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCAsyncStateCollection::LoadFromStream(TStream &Stream, TElDCEncoding &Encoding)
{
	SBCheckError(TElDCAsyncStateCollection_LoadFromStream(_Handle, Stream.getHandle(), Encoding.getHandle()));
}

SB_INLINE void TElDCAsyncStateCollection::LoadFromStream(TStream *Stream, TElDCEncoding *Encoding)
{
	SBCheckError(TElDCAsyncStateCollection_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Encoding != NULL) ? Encoding->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

void TElDCAsyncStateCollection::get_UserData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDCAsyncStateCollection_get_UserData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1539652359, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDCAsyncStateCollection::set_UserData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDCAsyncStateCollection_set_UserData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
TElDCAsyncState* TElDCAsyncStateCollection::get_States(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCAsyncStateCollection_get_States(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_States)
		this->_Inst_States = new TElDCAsyncState(hOutResult, ohFalse);
	else
		this->_Inst_States->updateHandle(hOutResult);
	return this->_Inst_States;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

SB_INLINE int32_t TElDCAsyncStateCollection::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDCAsyncStateCollection_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElDCAsyncStateCollection::initInstances()
{
#ifdef SB_USE_CLASS_TELDCASYNCSTATE
	this->_Inst_States = NULL;
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */
}

TElDCAsyncStateCollection::TElDCAsyncStateCollection(TElDCAsyncStateCollectionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDCAsyncStateCollection::TElDCAsyncStateCollection(bool OwnsObjects) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCAsyncStateCollection_Create((int8_t)OwnsObjects, &_Handle));
}

TElDCAsyncStateCollection::~TElDCAsyncStateCollection()
{
#ifdef SB_USE_CLASS_TELDCASYNCSTATE
	delete this->_Inst_States;
	this->_Inst_States = NULL;
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATECOLLECTION */

#ifdef SB_USE_GLOBAL_PROCS_DC

void DCBoolToStr(bool B, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBDC_DCBoolToStr((int8_t)B, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1188342131, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool DCStrToBool(const std::string &S, bool Def)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDC_DCStrToBool(S.data(), (int32_t)S.length(), (int8_t)Def, &OutResultRaw));
	return (OutResultRaw != 0);
}

void DCBoolToByteArray(bool B, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBDC_DCBoolToByteArray((int8_t)B, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1929707623, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool DCByteArrayToBool(const std::vector<uint8_t> &S, bool Def)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDC_DCByteArrayToBool(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), (int8_t)Def, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_DC */

};	/* namespace SecureBlackbox */
