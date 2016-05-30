#include "sbsimplemime.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT

SB_INLINE void TElSimpleMIMEAttachment::AttachFile(const std::string &FileName)
{
	SBCheckError(TElSimpleMIMEAttachment_AttachFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

void TElSimpleMIMEAttachment::get_ContentDisposition(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEAttachment_get_ContentDisposition(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1318055655, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleMIMEAttachment::set_ContentDisposition(const std::string &Value)
{
	SBCheckError(TElSimpleMIMEAttachment_set_ContentDisposition(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleMIMEAttachment::get_ContentId(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEAttachment_get_ContentId(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(308664784, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleMIMEAttachment::set_ContentId(const std::string &Value)
{
	SBCheckError(TElSimpleMIMEAttachment_set_ContentId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElSimpleMIMEAttachment::get_ContentStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEAttachment_get_ContentStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentStream)
		this->_Inst_ContentStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_ContentStream->updateHandle(hOutResult);
	return this->_Inst_ContentStream;
}

SB_INLINE void TElSimpleMIMEAttachment::set_ContentStream(TStream &Value)
{
	SBCheckError(TElSimpleMIMEAttachment_set_ContentStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEAttachment::set_ContentStream(TStream *Value)
{
	SBCheckError(TElSimpleMIMEAttachment_set_ContentStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElSimpleMIMEAttachment::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEAttachment_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-631378358, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleMIMEAttachment::set_ContentType(const std::string &Value)
{
	SBCheckError(TElSimpleMIMEAttachment_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleMIMEAttachment::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEAttachment_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(368940734, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleMIMEAttachment::set_Name(const std::string &Value)
{
	SBCheckError(TElSimpleMIMEAttachment_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleMIMEAttachment::get_DisposeStream()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleMIMEAttachment_get_DisposeStream(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleMIMEAttachment::set_DisposeStream(bool Value)
{
	SBCheckError(TElSimpleMIMEAttachment_set_DisposeStream(_Handle, (int8_t)Value));
}

void TElSimpleMIMEAttachment::initInstances()
{
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_ContentStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElSimpleMIMEAttachment::TElSimpleMIMEAttachment(TElSimpleMIMEAttachmentHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElSimpleMIMEAttachment::TElSimpleMIMEAttachment() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleMIMEAttachment_Create(&_Handle));
}

TElSimpleMIMEAttachment::~TElSimpleMIMEAttachment()
{
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_ContentStream;
	this->_Inst_ContentStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEMESSAGE

SB_INLINE int32_t TElSimpleMIMEMessage::AddAttachment()
{
	int32_t OutResult;
	SBCheckError(TElSimpleMIMEMessage_AddAttachment(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleMIMEMessage::DeleteAttachment(int32_t Index)
{
	SBCheckError(TElSimpleMIMEMessage_DeleteAttachment(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
SB_INLINE int32_t TElSimpleMIMEMessage::IndexOfAttachment(TElSimpleMIMEAttachment &Attachment)
{
	int32_t OutResult;
	SBCheckError(TElSimpleMIMEMessage_IndexOfAttachment(_Handle, Attachment.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSimpleMIMEMessage::IndexOfAttachment(TElSimpleMIMEAttachment *Attachment)
{
	int32_t OutResult;
	SBCheckError(TElSimpleMIMEMessage_IndexOfAttachment(_Handle, (Attachment != NULL) ? Attachment->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
SB_INLINE void TElSimpleMIMEMessage::RemoveAttachment(TElSimpleMIMEAttachment &Attachment)
{
	SBCheckError(TElSimpleMIMEMessage_RemoveAttachment(_Handle, Attachment.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::RemoveAttachment(TElSimpleMIMEAttachment *Attachment)
{
	SBCheckError(TElSimpleMIMEMessage_RemoveAttachment(_Handle, (Attachment != NULL) ? Attachment->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleMIMEMessage::SaveToStream(TStream &Stream)
{
	SBCheckError(TElSimpleMIMEMessage_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::SaveToStream(TStream *Stream)
{
	SBCheckError(TElSimpleMIMEMessage_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElSimpleMIMEMessage::SaveToText(TStrings &Text)
{
	SBCheckError(TElSimpleMIMEMessage_SaveToText(_Handle, Text.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::SaveToText(TStrings *Text)
{
	SBCheckError(TElSimpleMIMEMessage_SaveToText(_Handle, (Text != NULL) ? Text->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
TElSimpleMIMEAttachment* TElSimpleMIMEMessage::get_Attachments(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_Attachments(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attachments)
		this->_Inst_Attachments = new TElSimpleMIMEAttachment(hOutResult, ohFalse);
	else
		this->_Inst_Attachments->updateHandle(hOutResult);
	return this->_Inst_Attachments;
}
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

void TElSimpleMIMEMessage::get_AttachEncoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEMessage_get_AttachEncoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-153050594, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleMIMEMessage::set_AttachEncoding(const std::string &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_AttachEncoding(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleMIMEMessage::get_AttachmentCount()
{
	int32_t OutResult;
	SBCheckError(TElSimpleMIMEMessage_get_AttachmentCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleMIMEMessage::get_BCC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_BCC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BCC)
		this->_Inst_BCC = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_BCC->updateHandle(hOutResult);
	return this->_Inst_BCC;
}

SB_INLINE void TElSimpleMIMEMessage::set_BCC(TStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BCC(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_BCC(TStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BCC(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleMIMEMessage::get_BCC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_BCC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BCC)
		this->_Inst_BCC = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_BCC->updateHandle(hOutResult);
	return this->_Inst_BCC;
}

SB_INLINE void TElSimpleMIMEMessage::set_BCC(TElStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BCC(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_BCC(TElStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BCC(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSimpleMIMEMessage::get_BodyEncoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEMessage_get_BodyEncoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-908704486, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyEncoding(const std::string &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyEncoding(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleMIMEMessage::get_BodyHTML()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_BodyHTML(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BodyHTML)
		this->_Inst_BodyHTML = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_BodyHTML->updateHandle(hOutResult);
	return this->_Inst_BodyHTML;
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyHTML(TStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyHTML(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyHTML(TStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyHTML(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleMIMEMessage::get_BodyHTML()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_BodyHTML(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BodyHTML)
		this->_Inst_BodyHTML = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_BodyHTML->updateHandle(hOutResult);
	return this->_Inst_BodyHTML;
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyHTML(TElStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyHTML(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyHTML(TElStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyHTML(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleMIMEMessage::get_BodyPlain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_BodyPlain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BodyPlain)
		this->_Inst_BodyPlain = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_BodyPlain->updateHandle(hOutResult);
	return this->_Inst_BodyPlain;
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyPlain(TStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyPlain(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyPlain(TStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyPlain(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleMIMEMessage::get_BodyPlain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_BodyPlain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BodyPlain)
		this->_Inst_BodyPlain = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_BodyPlain->updateHandle(hOutResult);
	return this->_Inst_BodyPlain;
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyPlain(TElStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyPlain(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_BodyPlain(TElStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_BodyPlain(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleMIMEMessage::get_CC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_CC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CC)
		this->_Inst_CC = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_CC->updateHandle(hOutResult);
	return this->_Inst_CC;
}

SB_INLINE void TElSimpleMIMEMessage::set_CC(TStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_CC(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_CC(TStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_CC(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleMIMEMessage::get_CC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_CC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CC)
		this->_Inst_CC = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_CC->updateHandle(hOutResult);
	return this->_Inst_CC;
}

SB_INLINE void TElSimpleMIMEMessage::set_CC(TElStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_CC(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_CC(TElStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_CC(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSimpleMIMEMessage::get_Charset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEMessage_get_Charset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1394330445, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleMIMEMessage::set_Charset(const std::string &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_Charset(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleMIMEMessage::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}

SB_INLINE void TElSimpleMIMEMessage::set_CustomHeaders(TStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_CustomHeaders(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_CustomHeaders(TStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_CustomHeaders(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleMIMEMessage::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}

SB_INLINE void TElSimpleMIMEMessage::set_CustomHeaders(TElStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_CustomHeaders(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_CustomHeaders(TElStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_CustomHeaders(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELDOMAINKEYSSIGNER
TElDomainKeysSigner* TElSimpleMIMEMessage::get_DomainKeysSigner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_DomainKeysSigner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DomainKeysSigner)
		this->_Inst_DomainKeysSigner = new TElDomainKeysSigner(hOutResult, ohFalse);
	else
		this->_Inst_DomainKeysSigner->updateHandle(hOutResult);
	return this->_Inst_DomainKeysSigner;
}

SB_INLINE void TElSimpleMIMEMessage::set_DomainKeysSigner(TElDomainKeysSigner &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_DomainKeysSigner(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_DomainKeysSigner(TElDomainKeysSigner *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_DomainKeysSigner(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDOMAINKEYSSIGNER */

void TElSimpleMIMEMessage::get_From(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEMessage_get_From(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(573694778, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElSimpleMIMEMessage::get_From(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElSimpleMIMEMessage_get_From(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(573694778, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElSimpleMIMEMessage::set_From(const sb_u16string &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_From(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElSimpleMIMEMessage::set_From(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElSimpleMIMEMessage_set_From(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElHeaderEncoding TElSimpleMIMEMessage::get_HeaderEncoding()
{
	TElHeaderEncodingRaw OutResultRaw = 0;
	SBCheckError(TElSimpleMIMEMessage_get_HeaderEncoding(_Handle, &OutResultRaw));
	return (TElHeaderEncoding)OutResultRaw;
}

SB_INLINE void TElSimpleMIMEMessage::set_HeaderEncoding(TElHeaderEncoding Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_HeaderEncoding(_Handle, (TElHeaderEncodingRaw)Value));
}

void TElSimpleMIMEMessage::get_InReplyTo(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEMessage_get_InReplyTo(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1395510002, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElSimpleMIMEMessage::get_InReplyTo(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElSimpleMIMEMessage_get_InReplyTo(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1395510002, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElSimpleMIMEMessage::set_InReplyTo(const sb_u16string &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_InReplyTo(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElSimpleMIMEMessage::set_InReplyTo(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElSimpleMIMEMessage_set_InReplyTo(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
bool TElSimpleMIMEMessage::get_IsHTML()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleMIMEMessage_get_IsHTML(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleMIMEMessage::set_IsHTML(bool Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_IsHTML(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleMIMEMessage::get_To_()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_To_(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_To_)
		this->_Inst_To_ = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_To_->updateHandle(hOutResult);
	return this->_Inst_To_;
}

SB_INLINE void TElSimpleMIMEMessage::set_To_(TStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_To_(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_To_(TStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_To_(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleMIMEMessage::get_To_()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleMIMEMessage_get_To_(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_To_)
		this->_Inst_To_ = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_To_->updateHandle(hOutResult);
	return this->_Inst_To_;
}

SB_INLINE void TElSimpleMIMEMessage::set_To_(TElStringList &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_To_(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleMIMEMessage::set_To_(TElStringList *Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_To_(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TElMIMEMessagePriority TElSimpleMIMEMessage::get_Priority()
{
	TElMIMEMessagePriorityRaw OutResultRaw = 0;
	SBCheckError(TElSimpleMIMEMessage_get_Priority(_Handle, &OutResultRaw));
	return (TElMIMEMessagePriority)OutResultRaw;
}

SB_INLINE void TElSimpleMIMEMessage::set_Priority(TElMIMEMessagePriority Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_Priority(_Handle, (TElMIMEMessagePriorityRaw)Value));
}

bool TElSimpleMIMEMessage::get_RequestDeliveryReceipt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleMIMEMessage_get_RequestDeliveryReceipt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleMIMEMessage::set_RequestDeliveryReceipt(bool Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_RequestDeliveryReceipt(_Handle, (int8_t)Value));
}

bool TElSimpleMIMEMessage::get_RequestReadReceipt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleMIMEMessage_get_RequestReadReceipt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleMIMEMessage::set_RequestReadReceipt(bool Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_RequestReadReceipt(_Handle, (int8_t)Value));
}

void TElSimpleMIMEMessage::get_ReplyTo(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEMessage_get_ReplyTo(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2100978945, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElSimpleMIMEMessage::get_ReplyTo(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElSimpleMIMEMessage_get_ReplyTo(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2100978945, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElSimpleMIMEMessage::set_ReplyTo(const sb_u16string &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_ReplyTo(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElSimpleMIMEMessage::set_ReplyTo(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElSimpleMIMEMessage_set_ReplyTo(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElSimpleMIMEMessage::get_Sender(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEMessage_get_Sender(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1935850456, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElSimpleMIMEMessage::get_Sender(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElSimpleMIMEMessage_get_Sender(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1935850456, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElSimpleMIMEMessage::set_Sender(const sb_u16string &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_Sender(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElSimpleMIMEMessage::set_Sender(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElSimpleMIMEMessage_set_Sender(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElSimpleMIMEMessage::get_Subject(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleMIMEMessage_get_Subject(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(393296674, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElSimpleMIMEMessage::get_Subject(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElSimpleMIMEMessage_get_Subject(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(393296674, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElSimpleMIMEMessage::set_Subject(const sb_u16string &Value)
{
	SBCheckError(TElSimpleMIMEMessage_set_Subject(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElSimpleMIMEMessage::set_Subject(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElSimpleMIMEMessage_set_Subject(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElSimpleMIMEMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
	this->_Inst_Attachments = NULL;
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_BCC = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_BCC = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_BodyHTML = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_BodyHTML = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_BodyPlain = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_BodyPlain = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_CC = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_CC = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELDOMAINKEYSSIGNER
	this->_Inst_DomainKeysSigner = NULL;
#endif /* SB_USE_CLASS_TELDOMAINKEYSSIGNER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_To_ = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_To_ = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSimpleMIMEMessage::TElSimpleMIMEMessage(TElSimpleMIMEMessageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSimpleMIMEMessage::TElSimpleMIMEMessage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleMIMEMessage_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleMIMEMessage::TElSimpleMIMEMessage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleMIMEMessage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimpleMIMEMessage::~TElSimpleMIMEMessage()
{
#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
	delete this->_Inst_Attachments;
	this->_Inst_Attachments = NULL;
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_BCC;
	this->_Inst_BCC = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_BCC;
	this->_Inst_BCC = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_BodyHTML;
	this->_Inst_BodyHTML = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_BodyHTML;
	this->_Inst_BodyHTML = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_BodyPlain;
	this->_Inst_BodyPlain = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_BodyPlain;
	this->_Inst_BodyPlain = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_CC;
	this->_Inst_CC = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_CC;
	this->_Inst_CC = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_CustomHeaders;
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_CustomHeaders;
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELDOMAINKEYSSIGNER
	delete this->_Inst_DomainKeysSigner;
	this->_Inst_DomainKeysSigner = NULL;
#endif /* SB_USE_CLASS_TELDOMAINKEYSSIGNER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_To_;
	this->_Inst_To_ = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_To_;
	this->_Inst_To_ = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSIMPLEMIMEMESSAGE */

};	/* namespace SecureBlackbox */
