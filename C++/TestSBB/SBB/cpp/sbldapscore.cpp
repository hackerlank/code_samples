#include "sbldapscore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELLDAPMESSAGE

SB_INLINE void TElLDAPMessage::SaveToBuffer(void * Buf, int32_t &Size)
{
	SBCheckError(TElLDAPMessage_SaveToBuffer(_Handle, Buf, &Size));
}

SB_INLINE int32_t TElLDAPMessage::get_Code()
{
	int32_t OutResult;
	SBCheckError(TElLDAPMessage_get_Code(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElLDAPMessage::get_ID()
{
	int32_t OutResult;
	SBCheckError(TElLDAPMessage_get_ID(_Handle, &OutResult));
	return OutResult;
}

TElLDAPMessage::TElLDAPMessage(TElLDAPMessageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElLDAPMessage::TElLDAPMessage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPMessage_Create(&_Handle));
}

TElLDAPMessage::TElLDAPMessage(int32_t MessageID, int32_t Code) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPMessage_Create_1(MessageID, Code, &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSIMPLEBINDMESSAGE

TElLDAPSimpleBindMessage::TElLDAPSimpleBindMessage(TElLDAPSimpleBindMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
}

TElLDAPSimpleBindMessage::TElLDAPSimpleBindMessage(int32_t MessageID, const std::string &LDAPDN, const std::string &Password) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSimpleBindMessage_Create(MessageID, LDAPDN.data(), (int32_t)LDAPDN.length(), Password.data(), (int32_t)Password.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPSIMPLEBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSASLBINDMESSAGE

TElLDAPSASLBindMessage::TElLDAPSASLBindMessage(TElLDAPSASLBindMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
}

TElLDAPSASLBindMessage::TElLDAPSASLBindMessage(int32_t MessageID, const std::string &LDAPDN, const std::string &Password, const std::string &Mechanism, const std::vector<uint8_t> &Credentials, int32_t CredLen) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSASLBindMessage_Create(MessageID, LDAPDN.data(), (int32_t)LDAPDN.length(), Password.data(), (int32_t)Password.length(), Mechanism.data(), (int32_t)Mechanism.length(), SB_STD_VECTOR_FRONT_ADR(Credentials), (int32_t)Credentials.size(), CredLen, &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPSASLBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPUNBINDMESSAGE

TElLDAPUnbindMessage::TElLDAPUnbindMessage(TElLDAPUnbindMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
}

TElLDAPUnbindMessage::TElLDAPUnbindMessage(int32_t MessageID) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPUnbindMessage_Create(MessageID, &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPUNBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPRESULT

SB_INLINE int32_t TElLDAPResult::get_ResultCode()
{
	int32_t OutResult;
	SBCheckError(TElLDAPResult_get_ResultCode(_Handle, &OutResult));
	return OutResult;
}

void TElLDAPResult::get_MatchedDN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPResult_get_MatchedDN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(335939101, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPResult::get_DiagnosticMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPResult_get_DiagnosticMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1120898225, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElLDAPResult::get_Referal()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPResult_get_Referal(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Referal)
		this->_Inst_Referal = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Referal->updateHandle(hOutResult);
	return this->_Inst_Referal;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElLDAPResult::get_Referal()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPResult_get_Referal(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Referal)
		this->_Inst_Referal = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Referal->updateHandle(hOutResult);
	return this->_Inst_Referal;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElLDAPResult::get_HasReferal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPResult_get_HasReferal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElLDAPResult::get_Success()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPResult_get_Success(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElLDAPResult::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElLDAPResult::TElLDAPResult(TElLDAPResultHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
TElLDAPResult::TElLDAPResult(TElASN1ConstrainedTag &Tag) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	TElClassHandle hTag = Tag.getHandle();
	SBCheckError(TElLDAPResult_Create(&hTag, &_Handle));
	Tag.updateHandle(hTag);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

TElLDAPResult::~TElLDAPResult()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Referal;
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Referal;
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELLDAPRESULT */

#ifdef SB_USE_CLASS_TELLDAPRESULTMESSAGE

SB_INLINE int32_t TElLDAPResultMessage::get_ResultCode()
{
	int32_t OutResult;
	SBCheckError(TElLDAPResultMessage_get_ResultCode(_Handle, &OutResult));
	return OutResult;
}

void TElLDAPResultMessage::get_MatchedDN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPResultMessage_get_MatchedDN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1914530973, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPResultMessage::get_DiagnosticMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPResultMessage_get_DiagnosticMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(388385405, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElLDAPResultMessage::get_Referal()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPResultMessage_get_Referal(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Referal)
		this->_Inst_Referal = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Referal->updateHandle(hOutResult);
	return this->_Inst_Referal;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElLDAPResultMessage::get_Referal()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPResultMessage_get_Referal(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Referal)
		this->_Inst_Referal = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Referal->updateHandle(hOutResult);
	return this->_Inst_Referal;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElLDAPResultMessage::get_HasReferal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPResultMessage_get_HasReferal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElLDAPResultMessage::get_Success()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPResultMessage_get_Success(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElLDAPResultMessage::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElLDAPResultMessage::TElLDAPResultMessage(TElLDAPResultMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
	initInstances();
}

TElLDAPResultMessage::TElLDAPResultMessage(void * Buf, int32_t Size) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPResultMessage_Create(Buf, Size, &_Handle));
}

TElLDAPResultMessage::~TElLDAPResultMessage()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Referal;
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Referal;
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELLDAPRESULTMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPBINDRESPONSEMESSAGE

SB_INLINE int32_t TElLDAPBindResponseMessage::get_ResultCode()
{
	int32_t OutResult;
	SBCheckError(TElLDAPBindResponseMessage_get_ResultCode(_Handle, &OutResult));
	return OutResult;
}

void TElLDAPBindResponseMessage::get_MatchedDN(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPBindResponseMessage_get_MatchedDN(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(833661266, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPBindResponseMessage::get_DiagnosticMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPBindResponseMessage_get_DiagnosticMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-970739861, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElLDAPBindResponseMessage::get_Referal()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPBindResponseMessage_get_Referal(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Referal)
		this->_Inst_Referal = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Referal->updateHandle(hOutResult);
	return this->_Inst_Referal;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElLDAPBindResponseMessage::get_Referal()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPBindResponseMessage_get_Referal(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Referal)
		this->_Inst_Referal = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Referal->updateHandle(hOutResult);
	return this->_Inst_Referal;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElLDAPBindResponseMessage::get_HasReferal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPBindResponseMessage_get_HasReferal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElLDAPBindResponseMessage::get_Success()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPBindResponseMessage_get_Success(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElLDAPBindResponseMessage::get_ServerSaslCreds(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPBindResponseMessage_get_ServerSaslCreds(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1693513638, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPBindResponseMessage::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElLDAPBindResponseMessage::TElLDAPBindResponseMessage(TElLDAPBindResponseMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
	initInstances();
}

TElLDAPBindResponseMessage::TElLDAPBindResponseMessage(void * Buf, int32_t Size) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPBindResponseMessage_Create(Buf, Size, &_Handle));
}

TElLDAPBindResponseMessage::~TElLDAPBindResponseMessage()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Referal;
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Referal;
	this->_Inst_Referal = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELLDAPBINDRESPONSEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHMESSAGE

TElLDAPSearchMessage::TElLDAPSearchMessage(TElLDAPSearchMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TElLDAPSearchMessage::TElLDAPSearchMessage(int32_t MessageID, const std::string &BaseDN, TSBLDAPScope Scope, const std::string &Filter, const TStringList &Attrs, bool AttrsOnly) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSearchMessage_Create(MessageID, BaseDN.data(), (int32_t)BaseDN.length(), (TSBLDAPScopeRaw)Scope, Filter.data(), (int32_t)Filter.length(), Attrs.getHandle(), (int8_t)AttrsOnly, &_Handle));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#endif /* SB_USE_CLASS_TELLDAPSEARCHMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE

void TElLDAPAttributeValue::ToString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPAttributeValue_ToString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2001832453, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPAttributeValue::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElLDAPAttributeValue_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-621316634, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElLDAPAttributeValue::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElLDAPAttributeValue_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElLDAPAttributeValue::TElLDAPAttributeValue(TElLDAPAttributeValueHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElLDAPAttributeValue::TElLDAPAttributeValue(const std::vector<uint8_t> &Value) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPAttributeValue_Create(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE

SB_INLINE void TElLDAPPartialAttribute::Add(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElLDAPPartialAttribute_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
SB_INLINE void TElLDAPPartialAttribute::Add(const TElLDAPAttributeValue &Value)
{
	SBCheckError(TElLDAPPartialAttribute_Add_1(_Handle, Value.getHandle()));
}

SB_INLINE void TElLDAPPartialAttribute::Add(const TElLDAPAttributeValue *Value)
{
	SBCheckError(TElLDAPPartialAttribute_Add_1(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
void TElLDAPPartialAttribute::Save(TElASN1ConstrainedTag &Tag)
{
	TElClassHandle hTag = Tag.getHandle();
	SBCheckError(TElLDAPPartialAttribute_Save(_Handle, &hTag));
	Tag.updateHandle(hTag);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

TSBLDAPModifyOperation TElLDAPPartialAttribute::get_Operation()
{
	TSBLDAPModifyOperationRaw OutResultRaw = 0;
	SBCheckError(TElLDAPPartialAttribute_get_Operation(_Handle, &OutResultRaw));
	return (TSBLDAPModifyOperation)OutResultRaw;
}

bool TElLDAPPartialAttribute::get_Binary()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPPartialAttribute_get_Binary(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElLDAPPartialAttribute::get_Type_(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPPartialAttribute_get_Type_(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(198710722, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElLDAPPartialAttribute::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElLDAPPartialAttribute_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
TElLDAPAttributeValue* TElLDAPPartialAttribute::get_Values(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPPartialAttribute_get_Values(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Values)
		this->_Inst_Values = new TElLDAPAttributeValue(hOutResult, ohFalse);
	else
		this->_Inst_Values->updateHandle(hOutResult);
	return this->_Inst_Values;
}
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */

void TElLDAPPartialAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
	this->_Inst_Values = NULL;
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */
}

TElLDAPPartialAttribute::TElLDAPPartialAttribute(TElLDAPPartialAttributeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElLDAPPartialAttribute::TElLDAPPartialAttribute(const std::string &Type_, TSBLDAPModifyOperation Operation) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPPartialAttribute_Create(Type_.data(), (int32_t)Type_.length(), (TSBLDAPModifyOperationRaw)Operation, &_Handle));
}

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
TElLDAPPartialAttribute::TElLDAPPartialAttribute(TElASN1ConstrainedTag &Tag) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	TElClassHandle hTag = Tag.getHandle();
	SBCheckError(TElLDAPPartialAttribute_Create_1(&hTag, &_Handle));
	Tag.updateHandle(hTag);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

TElLDAPPartialAttribute::~TElLDAPPartialAttribute()
{
#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
	delete this->_Inst_Values;
	this->_Inst_Values = NULL;
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */
}
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHENTRYMESSAGE

void TElLDAPSearchEntryMessage::get_ObjectName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSearchEntryMessage_get_ObjectName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1167646591, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElLDAPSearchEntryMessage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElLDAPSearchEntryMessage_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
TElLDAPPartialAttribute* TElLDAPSearchEntryMessage::get_Attributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPSearchEntryMessage_get_Attributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElLDAPPartialAttribute(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
TElLDAPPartialAttribute* TElLDAPSearchEntryMessage::get_ByType(const std::string &Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPSearchEntryMessage_get_ByType(_Handle, Index.data(), (int32_t)Index.length(), &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ByType)
		this->_Inst_ByType = new TElLDAPPartialAttribute(hOutResult, ohFalse);
	else
		this->_Inst_ByType->updateHandle(hOutResult);
	return this->_Inst_ByType;
}
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

void TElLDAPSearchEntryMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */
#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
	this->_Inst_ByType = NULL;
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */
}

TElLDAPSearchEntryMessage::TElLDAPSearchEntryMessage(TElLDAPSearchEntryMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
	initInstances();
}

TElLDAPSearchEntryMessage::TElLDAPSearchEntryMessage(void * Buf, int32_t Size) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPSearchEntryMessage_Create(Buf, Size, &_Handle));
}

TElLDAPSearchEntryMessage::~TElLDAPSearchEntryMessage()
{
#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */
#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
	delete this->_Inst_ByType;
	this->_Inst_ByType = NULL;
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */
}
#endif /* SB_USE_CLASS_TELLDAPSEARCHENTRYMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHREFERENCEMESSAGE

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElLDAPSearchReferenceMessage::get_URIs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPSearchReferenceMessage_get_URIs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URIs)
		this->_Inst_URIs = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_URIs->updateHandle(hOutResult);
	return this->_Inst_URIs;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElLDAPSearchReferenceMessage::get_URIs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElLDAPSearchReferenceMessage_get_URIs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URIs)
		this->_Inst_URIs = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_URIs->updateHandle(hOutResult);
	return this->_Inst_URIs;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElLDAPSearchReferenceMessage::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_URIs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_URIs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElLDAPSearchReferenceMessage::TElLDAPSearchReferenceMessage(TElLDAPSearchReferenceMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
	initInstances();
}

TElLDAPSearchReferenceMessage::TElLDAPSearchReferenceMessage(void * Buf, int32_t Size) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElLDAPSearchReferenceMessage_Create(Buf, Size, &_Handle));
}

TElLDAPSearchReferenceMessage::~TElLDAPSearchReferenceMessage()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_URIs;
	this->_Inst_URIs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_URIs;
	this->_Inst_URIs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELLDAPSEARCHREFERENCEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPDELETEMESSAGE

TElLDAPDeleteMessage::TElLDAPDeleteMessage(TElLDAPDeleteMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
}

TElLDAPDeleteMessage::TElLDAPDeleteMessage(int32_t MessageID, const std::string &LDAPDN) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPDeleteMessage_Create(MessageID, LDAPDN.data(), (int32_t)LDAPDN.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPDELETEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPMODIFYMESSAGE

TElLDAPModifyMessage::TElLDAPModifyMessage(TElLDAPModifyMessageHandle handle, TElOwnHandle ownHandle) : TElLDAPMessage(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
TElLDAPModifyMessage::TElLDAPModifyMessage(int32_t MessageID, const std::string &DN, const std::vector<TElLDAPPartialAttributeHandle> &Attributes) : TElLDAPMessage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPModifyMessage_Create(MessageID, DN.data(), (int32_t)DN.length(), SB_STD_VECTOR_FRONT_ADR(Attributes), (int32_t)Attributes.size(), &_Handle));
}
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#endif /* SB_USE_CLASS_TELLDAPMODIFYMESSAGE */

#ifdef SB_USE_GLOBAL_PROCS_LDAPSCORE

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
SB_INLINE TElLDAPPartialAttributeHandle AttrFromString(const std::string &Type_, const std::string &Value, TSBLDAPModifyOperation Operation)
{
	TElLDAPPartialAttributeHandle OutResult;
	SBCheckError(SBLDAPSCore_AttrFromString(Type_.data(), (int32_t)Type_.length(), Value.data(), (int32_t)Value.length(), (TSBLDAPModifyOperationRaw)Operation, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
SB_INLINE TElLDAPPartialAttributeHandle AttrFromBuffer(const std::string &Type_, const std::vector<uint8_t> &Value, TSBLDAPModifyOperation Operation)
{
	TElLDAPPartialAttributeHandle OutResult;
	SBCheckError(SBLDAPSCore_AttrFromBuffer(Type_.data(), (int32_t)Type_.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (TSBLDAPModifyOperationRaw)Operation, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
void PutSimpleFilter(TElASN1ConstrainedTag &Tag, const std::string &s)
{
	TElClassHandle hTag = Tag.getHandle();
	SBCheckError(SBLDAPSCore_PutSimpleFilter(&hTag, s.data(), (int32_t)s.length()));
	Tag.updateHandle(hTag);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
void PutSubstringFilter(TElASN1ConstrainedTag &Tag, int32_t TagId, const std::string &Type_, const std::string &Value)
{
	TElClassHandle hTag = Tag.getHandle();
	SBCheckError(SBLDAPSCore_PutSubstringFilter(&hTag, TagId, Type_.data(), (int32_t)Type_.length(), Value.data(), (int32_t)Value.length()));
	Tag.updateHandle(hTag);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void SplitValue(TStringList &List, const std::string &s)
{
	TElClassHandle hList = List.getHandle();
	SBCheckError(SBLDAPSCore_SplitValue(&hList, s.data(), (int32_t)s.length()));
	List.updateHandle(hList);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void SplitValue(TElStringList &List, const std::string &s)
{
	TElClassHandle hList = List.getHandle();
	SBCheckError(SBLDAPSCore_SplitValue(&hList, s.data(), (int32_t)s.length()));
	List.updateHandle(hList);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
void PutFilterList(TElASN1ConstrainedTag &Tag, const std::string &s)
{
	TElClassHandle hTag = Tag.getHandle();
	SBCheckError(SBLDAPSCore_PutFilterList(&hTag, s.data(), (int32_t)s.length()));
	Tag.updateHandle(hTag);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

bool IsDigit(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsDigit(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsHexLower(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsHexLower(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsHexUpper(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsHexUpper(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsHex(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsHex(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsLower(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsLower(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsUpper(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsUpper(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsAlpha(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsAlpha(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsAlnum(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsAlnum(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsLdh(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsLdh(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsSpace(char c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBLDAPSCore_IsSpace(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t Hex2Value(char c)
{
	int32_t OutResult;
	SBCheckError(SBLDAPSCore_Hex2Value(c, &OutResult));
	return OutResult;
}

int32_t GetMessageLenSize(std::vector<uint8_t> &Buf, int32_t Size)
{
	int32_t OutResult;
	int32_t szBuf = (int32_t)Buf.size();
	uint32_t _err = SBLDAPSCore_GetMessageLenSize((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buf), &szBuf, Size, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buf.resize(szBuf);
		SBCheckError(SBGetLastReturnBuffer(-2037887006, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buf), &szBuf));
	}
	else
		SBCheckError(_err);

	Buf.resize(szBuf);
	return OutResult;
}

int32_t GetMessageLen(std::vector<uint8_t> &Buf, int32_t Size)
{
	int32_t OutResult;
	int32_t szBuf = (int32_t)Buf.size();
	uint32_t _err = SBLDAPSCore_GetMessageLen((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buf), &szBuf, Size, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buf.resize(szBuf);
		SBCheckError(SBGetLastReturnBuffer(821225493, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buf), &szBuf));
	}
	else
		SBCheckError(_err);

	Buf.resize(szBuf);
	return OutResult;
}

int32_t GetMessageType(std::vector<uint8_t> &Buf, int32_t Size)
{
	int32_t OutResult;
	int32_t szBuf = (int32_t)Buf.size();
	uint32_t _err = SBLDAPSCore_GetMessageType((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buf), &szBuf, Size, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buf.resize(szBuf);
		SBCheckError(SBGetLastReturnBuffer(-1459204673, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buf), &szBuf));
	}
	else
		SBCheckError(_err);

	Buf.resize(szBuf);
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_LDAPSCORE */

};	/* namespace SecureBlackbox */
