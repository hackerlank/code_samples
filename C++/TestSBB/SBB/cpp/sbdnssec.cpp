#include "sbdnssec.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDNSQUESTION

SB_INLINE void TElDNSQuestion::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSQuestion_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSQuestion::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSQuestion_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSQuestion::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSQuestion_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDNSQuestion::Write(TStream &Stream)
{
	SBCheckError(TElDNSQuestion_Write(_Handle, Stream.getHandle()));
}

SB_INLINE void TElDNSQuestion::Write(TStream *Stream)
{
	SBCheckError(TElDNSQuestion_Write(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElDNSQuestion::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSQuestion_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-838839251, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSQuestion::set_Name(const std::string &Value)
{
	SBCheckError(TElDNSQuestion_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint16_t TElDNSQuestion::get_ResourceCode()
{
	uint16_t OutResult;
	SBCheckError(TElDNSQuestion_get_ResourceCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSQuestion::set_ResourceCode(uint16_t Value)
{
	SBCheckError(TElDNSQuestion_set_ResourceCode(_Handle, Value));
}

TSBDNSResourceType TElDNSQuestion::get_ResourceType()
{
	TSBDNSResourceTypeRaw OutResultRaw = 0;
	SBCheckError(TElDNSQuestion_get_ResourceType(_Handle, &OutResultRaw));
	return (TSBDNSResourceType)OutResultRaw;
}

SB_INLINE void TElDNSQuestion::set_ResourceType(TSBDNSResourceType Value)
{
	SBCheckError(TElDNSQuestion_set_ResourceType(_Handle, (TSBDNSResourceTypeRaw)Value));
}

TElDNSQuestion::TElDNSQuestion(TElDNSQuestionHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElDNSQuestion::TElDNSQuestion() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSQuestion_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSQUESTION */

#ifdef SB_USE_CLASS_TELDNSQUESTIONLIST

#ifdef SB_USE_CLASS_TELDNSQUESTION
SB_INLINE TElDNSQuestionHandle TElDNSQuestionList::Add()
{
	TElDNSQuestionHandle OutResult;
	SBCheckError(TElDNSQuestionList_Add(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSQUESTION */

SB_INLINE void TElDNSQuestionList::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSQuestionList_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSQuestionList::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSQuestionList_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSQuestionList::Clear()
{
	SBCheckError(TElDNSQuestionList_Clear(_Handle));
}

SB_INLINE void TElDNSQuestionList::Delete(int32_t Index)
{
	SBCheckError(TElDNSQuestionList_Delete(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELDNSQUESTION
SB_INLINE int32_t TElDNSQuestionList::IndexOf(TElDNSQuestion &Question)
{
	int32_t OutResult;
	SBCheckError(TElDNSQuestionList_IndexOf(_Handle, Question.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSQuestionList::IndexOf(TElDNSQuestion *Question)
{
	int32_t OutResult;
	SBCheckError(TElDNSQuestionList_IndexOf(_Handle, (Question != NULL) ? Question->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSQUESTION */

#ifdef SB_USE_CLASS_TELDNSQUESTION
SB_INLINE TElDNSQuestionHandle TElDNSQuestionList::Insert(int32_t Index)
{
	TElDNSQuestionHandle OutResult;
	SBCheckError(TElDNSQuestionList_Insert(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSQUESTION */

#ifdef SB_USE_CLASS_TELDNSQUESTION
SB_INLINE int32_t TElDNSQuestionList::Remove(TElDNSQuestion &Question)
{
	int32_t OutResult;
	SBCheckError(TElDNSQuestionList_Remove(_Handle, Question.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSQuestionList::Remove(TElDNSQuestion *Question)
{
	int32_t OutResult;
	SBCheckError(TElDNSQuestionList_Remove(_Handle, (Question != NULL) ? Question->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSQUESTION */

SB_INLINE int32_t TElDNSQuestionList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDNSQuestionList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELDNSQUESTION
TElDNSQuestion* TElDNSQuestionList::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSQuestionList_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElDNSQuestion(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELDNSQUESTION */

void TElDNSQuestionList::initInstances()
{
#ifdef SB_USE_CLASS_TELDNSQUESTION
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELDNSQUESTION */
}

TElDNSQuestionList::TElDNSQuestionList(TElDNSQuestionListHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElDNSQuestionList::TElDNSQuestionList() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDNSQuestionList_Create(&_Handle));
}

TElDNSQuestionList::~TElDNSQuestionList()
{
#ifdef SB_USE_CLASS_TELDNSQUESTION
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELDNSQUESTION */
}
#endif /* SB_USE_CLASS_TELDNSQUESTIONLIST */

#ifdef SB_USE_CLASS_TELDNSCACHE

SB_INLINE void TElDNSCache::Add(TElDNSResourceRecordSet &Records)
{
	SBCheckError(TElDNSCache_Add(_Handle, Records.getHandle()));
}

SB_INLINE void TElDNSCache::Add(TElDNSResourceRecordSet *Records)
{
	SBCheckError(TElDNSCache_Add(_Handle, (Records != NULL) ? Records->getHandle() : SB_NULL_HANDLE));
}

TElDNSCache::TElDNSCache(TElDNSCacheHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecordSet(handle, ownHandle)
{
}

TElDNSCache::TElDNSCache() : TElDNSResourceRecordSet(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSCache_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSCACHE */

#ifdef SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS

SB_INLINE void TElDNSMessageExtensions::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSMessageExtensions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSMessageExtensions::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSMessageExtensions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSMessageExtensions::Clear()
{
	SBCheckError(TElDNSMessageExtensions_Clear(_Handle));
}

bool TElDNSMessageExtensions::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessageExtensions_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessageExtensions::set_Enabled(bool Value)
{
	SBCheckError(TElDNSMessageExtensions_set_Enabled(_Handle, (int8_t)Value));
}

bool TElDNSMessageExtensions::get_DNSSECOK()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessageExtensions_get_DNSSECOK(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessageExtensions::set_DNSSECOK(bool Value)
{
	SBCheckError(TElDNSMessageExtensions_set_DNSSECOK(_Handle, (int8_t)Value));
}

SB_INLINE uint16_t TElDNSMessageExtensions::get_Flags()
{
	uint16_t OutResult;
	SBCheckError(TElDNSMessageExtensions_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSMessageExtensions::set_Flags(uint16_t Value)
{
	SBCheckError(TElDNSMessageExtensions_set_Flags(_Handle, Value));
}

SB_INLINE uint16_t TElDNSMessageExtensions::get_PayloadSize()
{
	uint16_t OutResult;
	SBCheckError(TElDNSMessageExtensions_get_PayloadSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSMessageExtensions::set_PayloadSize(uint16_t Value)
{
	SBCheckError(TElDNSMessageExtensions_set_PayloadSize(_Handle, Value));
}

SB_INLINE uint16_t TElDNSMessageExtensions::get_ResponseCode()
{
	uint16_t OutResult;
	SBCheckError(TElDNSMessageExtensions_get_ResponseCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSMessageExtensions::set_ResponseCode(uint16_t Value)
{
	SBCheckError(TElDNSMessageExtensions_set_ResponseCode(_Handle, Value));
}

SB_INLINE uint8_t TElDNSMessageExtensions::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElDNSMessageExtensions_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSMessageExtensions::set_Version(uint8_t Value)
{
	SBCheckError(TElDNSMessageExtensions_set_Version(_Handle, Value));
}

TElDNSMessageExtensions::TElDNSMessageExtensions(TElDNSMessageExtensionsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElDNSMessageExtensions::TElDNSMessageExtensions() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSMessageExtensions_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS */

#ifdef SB_USE_CLASS_TELDNSMESSAGE

SB_INLINE void TElDNSMessage::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSMessage::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSMessage::Clear()
{
	SBCheckError(TElDNSMessage_Clear(_Handle));
}

SB_INLINE void TElDNSMessage::Read(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElDNSMessage_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDNSMessage::Write(TStream &Stream)
{
	SBCheckError(TElDNSMessage_Write(_Handle, Stream.getHandle()));
}

SB_INLINE void TElDNSMessage::Write(TStream *Stream)
{
	SBCheckError(TElDNSMessage_Write(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElDNSMessage::get_Authenticated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_Authenticated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessage::set_Authenticated(bool Value)
{
	SBCheckError(TElDNSMessage_set_Authenticated(_Handle, (int8_t)Value));
}

bool TElDNSMessage::get_Authoritative()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_Authoritative(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessage::set_Authoritative(bool Value)
{
	SBCheckError(TElDNSMessage_set_Authoritative(_Handle, (int8_t)Value));
}

bool TElDNSMessage::get_CheckingDisabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_CheckingDisabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessage::set_CheckingDisabled(bool Value)
{
	SBCheckError(TElDNSMessage_set_CheckingDisabled(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS
TElDNSMessageExtensions* TElDNSMessage::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSMessage_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElDNSMessageExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}

SB_INLINE void TElDNSMessage::set_Extensions(TElDNSMessageExtensions &Value)
{
	SBCheckError(TElDNSMessage_set_Extensions(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSMessage::set_Extensions(TElDNSMessageExtensions *Value)
{
	SBCheckError(TElDNSMessage_set_Extensions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS */

SB_INLINE uint16_t TElDNSMessage::get_ID()
{
	uint16_t OutResult;
	SBCheckError(TElDNSMessage_get_ID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSMessage::set_ID(uint16_t Value)
{
	SBCheckError(TElDNSMessage_set_ID(_Handle, Value));
}

TSBDNSMessageType TElDNSMessage::get_MessageType()
{
	TSBDNSMessageTypeRaw OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_MessageType(_Handle, &OutResultRaw));
	return (TSBDNSMessageType)OutResultRaw;
}

SB_INLINE void TElDNSMessage::set_MessageType(TSBDNSMessageType Value)
{
	SBCheckError(TElDNSMessage_set_MessageType(_Handle, (TSBDNSMessageTypeRaw)Value));
}

SB_INLINE uint8_t TElDNSMessage::get_OpCode()
{
	uint8_t OutResult;
	SBCheckError(TElDNSMessage_get_OpCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSMessage::set_OpCode(uint8_t Value)
{
	SBCheckError(TElDNSMessage_set_OpCode(_Handle, Value));
}

TSBDNSOperationCode TElDNSMessage::get_Operation()
{
	TSBDNSOperationCodeRaw OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_Operation(_Handle, &OutResultRaw));
	return (TSBDNSOperationCode)OutResultRaw;
}

SB_INLINE void TElDNSMessage::set_Operation(TSBDNSOperationCode Value)
{
	SBCheckError(TElDNSMessage_set_Operation(_Handle, (TSBDNSOperationCodeRaw)Value));
}

SB_INLINE uint16_t TElDNSMessage::get_RCode()
{
	uint16_t OutResult;
	SBCheckError(TElDNSMessage_get_RCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSMessage::set_RCode(uint16_t Value)
{
	SBCheckError(TElDNSMessage_set_RCode(_Handle, Value));
}

bool TElDNSMessage::get_RecursionAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_RecursionAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessage::set_RecursionAvailable(bool Value)
{
	SBCheckError(TElDNSMessage_set_RecursionAvailable(_Handle, (int8_t)Value));
}

bool TElDNSMessage::get_RecursionDesired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_RecursionDesired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessage::set_RecursionDesired(bool Value)
{
	SBCheckError(TElDNSMessage_set_RecursionDesired(_Handle, (int8_t)Value));
}

TSBDNSResponseCode TElDNSMessage::get_ResponseCode()
{
	TSBDNSResponseCodeRaw OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_ResponseCode(_Handle, &OutResultRaw));
	return (TSBDNSResponseCode)OutResultRaw;
}

SB_INLINE void TElDNSMessage::set_ResponseCode(TSBDNSResponseCode Value)
{
	SBCheckError(TElDNSMessage_set_ResponseCode(_Handle, (TSBDNSResponseCodeRaw)Value));
}

bool TElDNSMessage::get_Truncated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_Truncated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessage::set_Truncated(bool Value)
{
	SBCheckError(TElDNSMessage_set_Truncated(_Handle, (int8_t)Value));
}

bool TElDNSMessage::get_Z()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSMessage_get_Z(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSMessage::set_Z(bool Value)
{
	SBCheckError(TElDNSMessage_set_Z(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELDNSQUESTIONLIST
TElDNSQuestionList* TElDNSMessage::get_Questions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSMessage_get_Questions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Questions)
		this->_Inst_Questions = new TElDNSQuestionList(hOutResult, ohFalse);
	else
		this->_Inst_Questions->updateHandle(hOutResult);
	return this->_Inst_Questions;
}

SB_INLINE void TElDNSMessage::set_Questions(TElDNSQuestionList &Value)
{
	SBCheckError(TElDNSMessage_set_Questions(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSMessage::set_Questions(TElDNSQuestionList *Value)
{
	SBCheckError(TElDNSMessage_set_Questions(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSQUESTIONLIST */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
TElDNSResourceRecordSet* TElDNSMessage::get_Answers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSMessage_get_Answers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Answers)
		this->_Inst_Answers = new TElDNSResourceRecordSet(hOutResult, ohFalse);
	else
		this->_Inst_Answers->updateHandle(hOutResult);
	return this->_Inst_Answers;
}

SB_INLINE void TElDNSMessage::set_Answers(TElDNSResourceRecordSet &Value)
{
	SBCheckError(TElDNSMessage_set_Answers(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSMessage::set_Answers(TElDNSResourceRecordSet *Value)
{
	SBCheckError(TElDNSMessage_set_Answers(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
TElDNSResourceRecordSet* TElDNSMessage::get_Authorities()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSMessage_get_Authorities(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Authorities)
		this->_Inst_Authorities = new TElDNSResourceRecordSet(hOutResult, ohFalse);
	else
		this->_Inst_Authorities->updateHandle(hOutResult);
	return this->_Inst_Authorities;
}

SB_INLINE void TElDNSMessage::set_Authorities(TElDNSResourceRecordSet &Value)
{
	SBCheckError(TElDNSMessage_set_Authorities(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSMessage::set_Authorities(TElDNSResourceRecordSet *Value)
{
	SBCheckError(TElDNSMessage_set_Authorities(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
TElDNSResourceRecordSet* TElDNSMessage::get_Additionals()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSMessage_get_Additionals(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Additionals)
		this->_Inst_Additionals = new TElDNSResourceRecordSet(hOutResult, ohFalse);
	else
		this->_Inst_Additionals->updateHandle(hOutResult);
	return this->_Inst_Additionals;
}

SB_INLINE void TElDNSMessage::set_Additionals(TElDNSResourceRecordSet &Value)
{
	SBCheckError(TElDNSMessage_set_Additionals(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSMessage::set_Additionals(TElDNSResourceRecordSet *Value)
{
	SBCheckError(TElDNSMessage_set_Additionals(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

void TElDNSMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS */
#ifdef SB_USE_CLASS_TELDNSQUESTIONLIST
	this->_Inst_Questions = NULL;
#endif /* SB_USE_CLASS_TELDNSQUESTIONLIST */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
	this->_Inst_Answers = NULL;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
	this->_Inst_Authorities = NULL;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
	this->_Inst_Additionals = NULL;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */
}

TElDNSMessage::TElDNSMessage(TElDNSMessageHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElDNSMessage::TElDNSMessage() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDNSMessage_Create(&_Handle));
}

TElDNSMessage::~TElDNSMessage()
{
#ifdef SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELDNSMESSAGEEXTENSIONS */
#ifdef SB_USE_CLASS_TELDNSQUESTIONLIST
	delete this->_Inst_Questions;
	this->_Inst_Questions = NULL;
#endif /* SB_USE_CLASS_TELDNSQUESTIONLIST */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
	delete this->_Inst_Answers;
	this->_Inst_Answers = NULL;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
	delete this->_Inst_Authorities;
	this->_Inst_Authorities = NULL;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
	delete this->_Inst_Additionals;
	this->_Inst_Additionals = NULL;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */
}
#endif /* SB_USE_CLASS_TELDNSMESSAGE */

#ifdef SB_USE_CLASS_TELDNSCLIENT

SB_INLINE void TElDNSClient::Activate()
{
	SBCheckError(TElDNSClient_Activate(_Handle));
}

SB_INLINE void TElDNSClient::Deactivate()
{
	SBCheckError(TElDNSClient_Deactivate(_Handle));
}

#ifdef SB_USE_CLASS_TELDNSMESSAGE
void TElDNSClient::Lookup(const std::string &Name, TSBDNSResourceType ResourceType, TElDNSMessage &Response)
{
	TElClassHandle hResponse = Response.getHandle();
	SBCheckError(TElDNSClient_Lookup(_Handle, Name.data(), (int32_t)Name.length(), (TSBDNSResourceTypeRaw)ResourceType, &hResponse));
	Response.updateHandle(hResponse);
}
#endif /* SB_USE_CLASS_TELDNSMESSAGE */

#ifdef SB_USE_CLASS_TELDNSMESSAGE
void TElDNSClient::Lookup(const std::string &Name, uint8_t ResourceCode, TElDNSMessage &Response)
{
	TElClassHandle hResponse = Response.getHandle();
	SBCheckError(TElDNSClient_Lookup_1(_Handle, Name.data(), (int32_t)Name.length(), ResourceCode, &hResponse));
	Response.updateHandle(hResponse);
}
#endif /* SB_USE_CLASS_TELDNSMESSAGE */

bool TElDNSClient::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSClient_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElDNSClient::get_BoundAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSClient_get_BoundAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-676175483, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint16_t TElDNSClient::get_BoundPort()
{
	uint16_t OutResult;
	SBCheckError(TElDNSClient_get_BoundPort(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
bool TElDNSClient::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSClient_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

void TElDNSClient::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSClient_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(800633046, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSClient::set_Address(const std::string &Value)
{
	SBCheckError(TElDNSClient_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElDNSClient::get_Binding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSClient_get_Binding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Binding)
		this->_Inst_Binding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_Binding->updateHandle(hOutResult);
	return this->_Inst_Binding;
}

SB_INLINE void TElDNSClient::set_Binding(TElClientSocketBinding &Value)
{
	SBCheckError(TElDNSClient_set_Binding(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSClient::set_Binding(TElClientSocketBinding *Value)
{
	SBCheckError(TElDNSClient_set_Binding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

SB_INLINE uint16_t TElDNSClient::get_Port()
{
	uint16_t OutResult;
	SBCheckError(TElDNSClient_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSClient::set_Port(uint16_t Value)
{
	SBCheckError(TElDNSClient_set_Port(_Handle, Value));
}

SB_INLINE uint16_t TElDNSClient::get_Timeout()
{
	uint16_t OutResult;
	SBCheckError(TElDNSClient_get_Timeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSClient::set_Timeout(uint16_t Value)
{
	SBCheckError(TElDNSClient_set_Timeout(_Handle, Value));
}

#ifdef SB_WINDOWS
bool TElDNSClient::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSClient_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSClient::set_UseIPv6(bool Value)
{
	SBCheckError(TElDNSClient_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElDNSClient::get_UseRecursion()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSClient_get_UseRecursion(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSClient::set_UseRecursion(bool Value)
{
	SBCheckError(TElDNSClient_set_UseRecursion(_Handle, (int8_t)Value));
}

bool TElDNSClient::get_UseSecurity()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSClient_get_UseSecurity(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSClient::set_UseSecurity(bool Value)
{
	SBCheckError(TElDNSClient_set_UseSecurity(_Handle, (int8_t)Value));
}

SB_INLINE void TElDNSClient::get_OnSending(TSBDNSClientSendingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDNSClient_get_OnSending(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDNSClient::set_OnSending(TSBDNSClientSendingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDNSClient_set_OnSending(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDNSClient::get_OnTimeout(TSBDNSClientTimeoutEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDNSClient_get_OnTimeout(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDNSClient::set_OnTimeout(TSBDNSClientTimeoutEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDNSClient_set_OnTimeout(_Handle, pMethodValue, pDataValue));
}

void TElDNSClient::initInstances()
{
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_Binding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
}

TElDNSClient::TElDNSClient(TElDNSClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElDNSClient::TElDNSClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDNSClient_Create(AOwner.getHandle(), &_Handle));
}

TElDNSClient::TElDNSClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDNSClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElDNSClient::~TElDNSClient()
{
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_Binding;
	this->_Inst_Binding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
}
#endif /* SB_USE_CLASS_TELDNSCLIENT */

#ifdef SB_USE_CLASS_TELDNSRESOLVER

SB_INLINE void TElDNSResolver::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSResolver_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSResolver::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSResolver_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
int32_t TElDNSResolver::Lookup(const std::string &Criteria, TSBDNSResourceType InfoType, TElDNSResourceRecordSet &FoundInfo, TSBDNSSecurityStatus &SecurityStatus)
{
	int32_t OutResult;
	TSBDNSSecurityStatusRaw SecurityStatusRaw = (TSBDNSSecurityStatusRaw)SecurityStatus;
	SBCheckError(TElDNSResolver_Lookup(_Handle, Criteria.data(), (int32_t)Criteria.length(), (TSBDNSResourceTypeRaw)InfoType, FoundInfo.getHandle(), &SecurityStatusRaw, &OutResult));
	SecurityStatus = (TSBDNSSecurityStatus)SecurityStatusRaw;
	return OutResult;
}

int32_t TElDNSResolver::Lookup(const std::string &Criteria, TSBDNSResourceType InfoType, TElDNSResourceRecordSet *FoundInfo, TSBDNSSecurityStatus &SecurityStatus)
{
	int32_t OutResult;
	TSBDNSSecurityStatusRaw SecurityStatusRaw = (TSBDNSSecurityStatusRaw)SecurityStatus;
	SBCheckError(TElDNSResolver_Lookup(_Handle, Criteria.data(), (int32_t)Criteria.length(), (TSBDNSResourceTypeRaw)InfoType, (FoundInfo != NULL) ? FoundInfo->getHandle() : SB_NULL_HANDLE, &SecurityStatusRaw, &OutResult));
	SecurityStatus = (TSBDNSSecurityStatus)SecurityStatusRaw;
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

SB_INLINE uint16_t TElDNSResolver::get_Port()
{
	uint16_t OutResult;
	SBCheckError(TElDNSResolver_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSResolver::set_Port(uint16_t Value)
{
	SBCheckError(TElDNSResolver_set_Port(_Handle, Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElDNSResolver::get_Servers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSResolver_get_Servers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Servers)
		this->_Inst_Servers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Servers->updateHandle(hOutResult);
	return this->_Inst_Servers;
}

SB_INLINE void TElDNSResolver::set_Servers(TStringList &Value)
{
	SBCheckError(TElDNSResolver_set_Servers(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSResolver::set_Servers(TStringList *Value)
{
	SBCheckError(TElDNSResolver_set_Servers(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElDNSResolver::get_Servers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSResolver_get_Servers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Servers)
		this->_Inst_Servers = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Servers->updateHandle(hOutResult);
	return this->_Inst_Servers;
}

SB_INLINE void TElDNSResolver::set_Servers(TElStringList &Value)
{
	SBCheckError(TElDNSResolver_set_Servers(_Handle, Value.getHandle()));
}

SB_INLINE void TElDNSResolver::set_Servers(TElStringList *Value)
{
	SBCheckError(TElDNSResolver_set_Servers(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE uint16_t TElDNSResolver::get_QueryTimeout()
{
	uint16_t OutResult;
	SBCheckError(TElDNSResolver_get_QueryTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSResolver::set_QueryTimeout(uint16_t Value)
{
	SBCheckError(TElDNSResolver_set_QueryTimeout(_Handle, Value));
}

SB_INLINE uint16_t TElDNSResolver::get_TotalTimeout()
{
	uint16_t OutResult;
	SBCheckError(TElDNSResolver_get_TotalTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSResolver::set_TotalTimeout(uint16_t Value)
{
	SBCheckError(TElDNSResolver_set_TotalTimeout(_Handle, Value));
}

#ifdef SB_WINDOWS
bool TElDNSResolver::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSResolver_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSResolver::set_UseIPv6(bool Value)
{
	SBCheckError(TElDNSResolver_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElDNSResolver::get_UseSecurity()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSResolver_get_UseSecurity(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSResolver::set_UseSecurity(bool Value)
{
	SBCheckError(TElDNSResolver_set_UseSecurity(_Handle, (int8_t)Value));
}

SB_INLINE void TElDNSResolver::get_OnError(TSBDNSResolverErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDNSResolver_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDNSResolver::set_OnError(TSBDNSResolverErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDNSResolver_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDNSResolver::get_OnKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDNSResolver_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDNSResolver::set_OnKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDNSResolver_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDNSResolver::get_OnKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDNSResolver_get_OnKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDNSResolver::set_OnKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDNSResolver_set_OnKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDNSResolver::get_OnPrepare(TSBDNSResolverPrepareEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDNSResolver_get_OnPrepare(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDNSResolver::set_OnPrepare(TSBDNSResolverPrepareEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDNSResolver_set_OnPrepare(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDNSResolver::get_OnRequest(TSBDNSResolverRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDNSResolver_get_OnRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDNSResolver::set_OnRequest(TSBDNSResolverRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDNSResolver_set_OnRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDNSResolver::get_OnResponse(TSBDNSResolverResponseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDNSResolver_get_OnResponse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDNSResolver::set_OnResponse(TSBDNSResolverResponseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDNSResolver_set_OnResponse(_Handle, pMethodValue, pDataValue));
}

void TElDNSResolver::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Servers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Servers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElDNSResolver::TElDNSResolver(TElDNSResolverHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElDNSResolver::TElDNSResolver(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDNSResolver_Create(AOwner.getHandle(), &_Handle));
}

TElDNSResolver::TElDNSResolver(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDNSResolver_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElDNSResolver::~TElDNSResolver()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Servers;
	this->_Inst_Servers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Servers;
	this->_Inst_Servers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELDNSRESOLVER */

};	/* namespace SecureBlackbox */
