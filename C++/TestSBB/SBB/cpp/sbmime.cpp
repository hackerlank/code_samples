#include "sbmime.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELMESSAGE

void TElMessage::GenerateMessageID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_GenerateMessageID((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-728288505, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessage::GenerateMessageID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_GenerateMessageID(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-728288505, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElMessage::GenerateMessageID_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_GenerateMessageID_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-728288505, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessage::GenerateMessageID_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_GenerateMessageID_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-728288505, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessage::Clear(bool bClearMainPart)
{
	SBCheckError(TElMessage_Clear(_Handle, (int8_t)bClearMainPart));
}

SB_INLINE void TElMessage::Assign(TElMessage &Source)
{
	SBCheckError(TElMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElMessage::Assign(TElMessage *Source)
{
	SBCheckError(TElMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessage::ParseMessage(TStream &Source, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElMessage_ParseMessage(_Handle, Source.getHandle(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessage::ParseMessage(TStream *Source, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElMessage_ParseMessage(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessage::AssembleMessage(TStream &Destination, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElMessage_AssembleMessage(_Handle, Destination.getHandle(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessage::AssembleMessage(TStream *Destination, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElMessage_AssembleMessage(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessage::AssembleMessage(TStream &Destination, const std::string &ACharset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElMessage_AssembleMessage_1(_Handle, Destination.getHandle(), ACharset.data(), (int32_t)ACharset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessage::AssembleMessage(TStream *Destination, const std::string &ACharset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElMessage_AssembleMessage_1(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, ACharset.data(), (int32_t)ACharset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int64_t TElMessage::GetMessageSentTime()
{
	int64_t OutResult;
	SBCheckError(TElMessage_GetMessageSentTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElMessage::GetMessageReceivedTime()
{
	int64_t OutResult;
	SBCheckError(TElMessage_GetMessageReceivedTime(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELMAILADDRESS
SB_INLINE TElMailAddressHandle TElMessage::GetReplyToMailAddress()
{
	TElMailAddressHandle OutResult;
	SBCheckError(TElMessage_GetReplyToMailAddress(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetCustomHeader(const sb_u16string &HeaderName, const sb_u16string &HeaderValue)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetCustomHeader(_Handle, HeaderName.data(), (int32_t)HeaderName.length(), HeaderValue.data(), (int32_t)HeaderValue.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetCustomHeader(const std::wstring &HeaderName, const std::wstring &HeaderValue)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16HeaderName;
	sb_to_u16string(HeaderName, u16HeaderName);
	std::string u16HeaderValue;
	sb_to_u16string(HeaderValue, u16HeaderValue);
	SBCheckError(TElMessage_SetCustomHeader(_Handle, reinterpret_cast<const sb_char16_t*>(u16HeaderName.data()), (int32_t)u16HeaderName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16HeaderValue.data()), (int32_t)u16HeaderValue.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetMessageID(const sb_u16string &AMessageID)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetMessageID(_Handle, AMessageID.data(), (int32_t)AMessageID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetMessageID(const std::wstring &AMessageID)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16AMessageID;
	sb_to_u16string(AMessageID, u16AMessageID);
	SBCheckError(TElMessage_SetMessageID(_Handle, reinterpret_cast<const sb_char16_t*>(u16AMessageID.data()), (int32_t)u16AMessageID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetResentMessageID(const sb_u16string &AMessageID)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetResentMessageID(_Handle, AMessageID.data(), (int32_t)AMessageID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetResentMessageID(const std::wstring &AMessageID)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16AMessageID;
	sb_to_u16string(AMessageID, u16AMessageID);
	SBCheckError(TElMessage_SetResentMessageID(_Handle, reinterpret_cast<const sb_char16_t*>(u16AMessageID.data()), (int32_t)u16AMessageID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetInReplyTo(const sb_u16string &AInReplyTo)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetInReplyTo(_Handle, AInReplyTo.data(), (int32_t)AInReplyTo.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetInReplyTo(const std::wstring &AInReplyTo)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16AInReplyTo;
	sb_to_u16string(AInReplyTo, u16AInReplyTo);
	SBCheckError(TElMessage_SetInReplyTo(_Handle, reinterpret_cast<const sb_char16_t*>(u16AInReplyTo.data()), (int32_t)u16AInReplyTo.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetReferences(const sb_u16string &AReferences)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetReferences(_Handle, AReferences.data(), (int32_t)AReferences.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetReferences(const std::wstring &AReferences)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16AReferences;
	sb_to_u16string(AReferences, u16AReferences);
	SBCheckError(TElMessage_SetReferences(_Handle, reinterpret_cast<const sb_char16_t*>(u16AReferences.data()), (int32_t)u16AReferences.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetKeywords(const sb_u16string &AKeywords)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetKeywords(_Handle, AKeywords.data(), (int32_t)AKeywords.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetKeywords(const std::wstring &AKeywords)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16AKeywords;
	sb_to_u16string(AKeywords, u16AKeywords);
	SBCheckError(TElMessage_SetKeywords(_Handle, reinterpret_cast<const sb_char16_t*>(u16AKeywords.data()), (int32_t)u16AKeywords.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetSubject(const sb_u16string &ASubject)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetSubject(_Handle, ASubject.data(), (int32_t)ASubject.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetSubject(const std::wstring &ASubject)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16ASubject;
	sb_to_u16string(ASubject, u16ASubject);
	SBCheckError(TElMessage_SetSubject(_Handle, reinterpret_cast<const sb_char16_t*>(u16ASubject.data()), (int32_t)u16ASubject.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetComments(const sb_u16string &AComments)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetComments(_Handle, AComments.data(), (int32_t)AComments.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetComments(const std::wstring &AComments)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16AComments;
	sb_to_u16string(AComments, u16AComments);
	SBCheckError(TElMessage_SetComments(_Handle, reinterpret_cast<const sb_char16_t*>(u16AComments.data()), (int32_t)u16AComments.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

bool TElMessage::GetDate(int64_t &DateTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessage_GetDate(_Handle, &DateTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetDate(int64_t ADateTime)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetDate(_Handle, ADateTime, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

bool TElMessage::GetResentDate(int64_t &DateTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessage_GetResentDate(_Handle, &DateTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetResentDate(int64_t DateTime)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetResentDate(_Handle, DateTime, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetReturnPath(const sb_u16string &AReturnPath)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessage_SetReturnPath(_Handle, AReturnPath.data(), (int32_t)AReturnPath.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessage::SetReturnPath(const std::wstring &AReturnPath)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16AReturnPath;
	sb_to_u16string(AReturnPath, u16AReturnPath);
	SBCheckError(TElMessage_SetReturnPath(_Handle, reinterpret_cast<const sb_char16_t*>(u16AReturnPath.data()), (int32_t)u16AReturnPath.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEPART
SB_INLINE TElMessagePartHandle TElMessage::SetMainPart(const TElMessagePart &AMainPart, bool bMakeCopy)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessage_SetMainPart(_Handle, AMainPart.getHandle(), (int8_t)bMakeCopy, &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMessage::SetMainPart(const TElMessagePart *AMainPart, bool bMakeCopy)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessage_SetMainPart(_Handle, (AMainPart != NULL) ? AMainPart->getHandle() : SB_NULL_HANDLE, (int8_t)bMakeCopy, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASSES_TELMESSAGEPART_AND_TSTREAM
SB_INLINE TElMessagePartHandle TElMessage::AttachData(const sb_u16string &ContentType, const sb_u16string &FileName, TStream &Stream, int32_t DataSize, bool bMakeCopy)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessage_AttachData(_Handle, ContentType.data(), (int32_t)ContentType.length(), FileName.data(), (int32_t)FileName.length(), Stream.getHandle(), DataSize, (int8_t)bMakeCopy, &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMessage::AttachData(const sb_u16string &ContentType, const sb_u16string &FileName, TStream *Stream, int32_t DataSize, bool bMakeCopy)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessage_AttachData(_Handle, ContentType.data(), (int32_t)ContentType.length(), FileName.data(), (int32_t)FileName.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, DataSize, (int8_t)bMakeCopy, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessagePartHandle TElMessage::AttachData(const std::wstring &ContentType, const std::wstring &FileName, TStream &Stream, int32_t DataSize, bool bMakeCopy)
{
	TElMessagePartHandle OutResult;
	std::string u16ContentType;
	sb_to_u16string(ContentType, u16ContentType);
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	SBCheckError(TElMessage_AttachData(_Handle, reinterpret_cast<const sb_char16_t*>(u16ContentType.data()), (int32_t)u16ContentType.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, Stream.getHandle(), DataSize, (int8_t)bMakeCopy, &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMessage::AttachData(const std::wstring &ContentType, const std::wstring &FileName, TStream *Stream, int32_t DataSize, bool bMakeCopy)
{
	TElMessagePartHandle OutResult;
	std::string u16ContentType;
	sb_to_u16string(ContentType, u16ContentType);
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	SBCheckError(TElMessage_AttachData(_Handle, reinterpret_cast<const sb_char16_t*>(u16ContentType.data()), (int32_t)u16ContentType.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, DataSize, (int8_t)bMakeCopy, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELMESSAGEPART_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELMESSAGEPART
SB_INLINE TElMessagePartHandle TElMessage::AttachData(const sb_u16string &ContentType, const sb_u16string &FileName, const sb_u16string &wsData)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessage_AttachData_1(_Handle, ContentType.data(), (int32_t)ContentType.length(), FileName.data(), (int32_t)FileName.length(), wsData.data(), (int32_t)wsData.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessagePartHandle TElMessage::AttachData(const std::wstring &ContentType, const std::wstring &FileName, const std::wstring &wsData)
{
	TElMessagePartHandle OutResult;
	std::string u16ContentType;
	sb_to_u16string(ContentType, u16ContentType);
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	std::string u16wsData;
	sb_to_u16string(wsData, u16wsData);
	SBCheckError(TElMessage_AttachData_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ContentType.data()), (int32_t)u16ContentType.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16wsData.data()), (int32_t)u16wsData.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASS_TELMESSAGEPART
SB_INLINE TElMessagePartHandle TElMessage::AttachData(const sb_u16string &ContentType, const sb_u16string &FileName, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessage_AttachData_2(_Handle, ContentType.data(), (int32_t)ContentType.length(), FileName.data(), (int32_t)FileName.length(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessagePartHandle TElMessage::AttachData(const std::wstring &ContentType, const std::wstring &FileName, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	TElMessagePartHandle OutResult;
	std::string u16ContentType;
	sb_to_u16string(ContentType, u16ContentType);
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	SBCheckError(TElMessage_AttachData_2(_Handle, reinterpret_cast<const sb_char16_t*>(u16ContentType.data()), (int32_t)u16ContentType.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASS_TELMESSAGEPART
SB_INLINE TElMessagePartHandle TElMessage::AttachFile(const sb_u16string &ContentType, const sb_u16string &FileName)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessage_AttachFile(_Handle, ContentType.data(), (int32_t)ContentType.length(), FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessagePartHandle TElMessage::AttachFile(const std::wstring &ContentType, const std::wstring &FileName)
{
	TElMessagePartHandle OutResult;
	std::string u16ContentType;
	sb_to_u16string(ContentType, u16ContentType);
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	SBCheckError(TElMessage_AttachFile(_Handle, reinterpret_cast<const sb_char16_t*>(u16ContentType.data()), (int32_t)u16ContentType.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEPART */

void TElMessage::get_CustomHeaders(const sb_u16string &HeaderName, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_CustomHeaders(_Handle, HeaderName.data(), (int32_t)HeaderName.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-29417058, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_CustomHeaders(const std::wstring &HeaderName, std::wstring &OutResult)
{
	std::string u16HeaderName;
	sb_to_u16string(HeaderName, u16HeaderName);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_CustomHeaders(_Handle, reinterpret_cast<const sb_char16_t*>(u16HeaderName.data()), (int32_t)u16HeaderName.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-29417058, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMessage::set_CustomHeaders(const sb_u16string &HeaderName, const sb_u16string &HeaderValue)
{
	SBCheckError(TElMessage_set_CustomHeaders(_Handle, HeaderName.data(), (int32_t)HeaderName.length(), HeaderValue.data(), (int32_t)HeaderValue.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMessage::set_CustomHeaders(const std::wstring &HeaderName, const std::wstring &HeaderValue)
{
	std::string u16HeaderName;
	sb_to_u16string(HeaderName, u16HeaderName);
	std::string u16HeaderValue;
	sb_to_u16string(HeaderValue, u16HeaderValue);
	SBCheckError(TElMessage_set_CustomHeaders(_Handle, reinterpret_cast<const sb_char16_t*>(u16HeaderName.data()), (int32_t)u16HeaderName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16HeaderValue.data()), (int32_t)u16HeaderValue.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElMessage::get_MessageID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_MessageID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1589417850, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_MessageID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_MessageID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1589417850, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMessage::set_MessageID(const sb_u16string &Value)
{
	SBCheckError(TElMessage_set_MessageID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMessage::set_MessageID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessage_set_MessageID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElMessage::get_ResentMessageID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_ResentMessageID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1065396100, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_ResentMessageID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_ResentMessageID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1065396100, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessage::get_InReplyTo(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_InReplyTo(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(772997109, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_InReplyTo(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_InReplyTo(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(772997109, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessage::get_References(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_References(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(246692460, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_References(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_References(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(246692460, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessage::get_Keywords(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_Keywords(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-717289914, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_Keywords(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_Keywords(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-717289914, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessage::get_Subject(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_Subject(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-31789808, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_Subject(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_Subject(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-31789808, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessage::get_Comments(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_Comments(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(553526578, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_Comments(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_Comments(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(553526578, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessage::get_ReturnPath(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_ReturnPath(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-353890075, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_ReturnPath(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_ReturnPath(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-353890075, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_ReplyTo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_ReplyTo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReplyTo)
		this->_Inst_ReplyTo = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_ReplyTo->updateHandle(hOutResult);
	return this->_Inst_ReplyTo;
}

SB_INLINE void TElMessage::set_ReplyTo(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_ReplyTo(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_ReplyTo(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_ReplyTo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_ResentReplyTo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_ResentReplyTo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResentReplyTo)
		this->_Inst_ResentReplyTo = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_ResentReplyTo->updateHandle(hOutResult);
	return this->_Inst_ResentReplyTo;
}

SB_INLINE void TElMessage::set_ResentReplyTo(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_ResentReplyTo(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_ResentReplyTo(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_ResentReplyTo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_From()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_From(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_From)
		this->_Inst_From = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_From->updateHandle(hOutResult);
	return this->_Inst_From;
}

SB_INLINE void TElMessage::set_From(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_From(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_From(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_From(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_ResentFrom()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_ResentFrom(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResentFrom)
		this->_Inst_ResentFrom = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_ResentFrom->updateHandle(hOutResult);
	return this->_Inst_ResentFrom;
}

SB_INLINE void TElMessage::set_ResentFrom(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_ResentFrom(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_ResentFrom(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_ResentFrom(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_Sender()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_Sender(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Sender)
		this->_Inst_Sender = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_Sender->updateHandle(hOutResult);
	return this->_Inst_Sender;
}

SB_INLINE void TElMessage::set_Sender(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_Sender(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_Sender(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_Sender(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_ResentSender()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_ResentSender(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResentSender)
		this->_Inst_ResentSender = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_ResentSender->updateHandle(hOutResult);
	return this->_Inst_ResentSender;
}

SB_INLINE void TElMessage::set_ResentSender(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_ResentSender(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_ResentSender(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_ResentSender(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_To_()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_To_(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_To_)
		this->_Inst_To_ = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_To_->updateHandle(hOutResult);
	return this->_Inst_To_;
}

SB_INLINE void TElMessage::set_To_(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_To_(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_To_(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_To_(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_ResentTo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_ResentTo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResentTo)
		this->_Inst_ResentTo = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_ResentTo->updateHandle(hOutResult);
	return this->_Inst_ResentTo;
}

SB_INLINE void TElMessage::set_ResentTo(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_ResentTo(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_ResentTo(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_ResentTo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_CC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_CC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CC)
		this->_Inst_CC = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_CC->updateHandle(hOutResult);
	return this->_Inst_CC;
}

SB_INLINE void TElMessage::set_CC(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_CC(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_CC(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_CC(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_ResentCC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_ResentCC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResentCC)
		this->_Inst_ResentCC = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_ResentCC->updateHandle(hOutResult);
	return this->_Inst_ResentCC;
}

SB_INLINE void TElMessage::set_ResentCC(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_ResentCC(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_ResentCC(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_ResentCC(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_BCC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_BCC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BCC)
		this->_Inst_BCC = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_BCC->updateHandle(hOutResult);
	return this->_Inst_BCC;
}

SB_INLINE void TElMessage::set_BCC(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_BCC(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_BCC(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_BCC(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
TElMailAddressList* TElMessage::get_ResentBCC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_ResentBCC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResentBCC)
		this->_Inst_ResentBCC = new TElMailAddressList(hOutResult, ohFalse);
	else
		this->_Inst_ResentBCC->updateHandle(hOutResult);
	return this->_Inst_ResentBCC;
}

SB_INLINE void TElMessage::set_ResentBCC(TElMailAddressList &Value)
{
	SBCheckError(TElMessage_set_ResentBCC(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessage::set_ResentBCC(TElMailAddressList *Value)
{
	SBCheckError(TElMessage_set_ResentBCC(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMESSAGEPART
TElMessagePart* TElMessage::get_MainPart()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_MainPart(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MainPart)
		this->_Inst_MainPart = new TElMessagePart(hOutResult, ohFalse);
	else
		this->_Inst_MainPart->updateHandle(hOutResult);
	return this->_Inst_MainPart;
}
#endif /* SB_USE_CLASS_TELMESSAGEPART */

SB_INLINE int32_t TElMessage::get_AttachmentsCount()
{
	int32_t OutResult;
	SBCheckError(TElMessage_get_AttachmentsCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELMESSAGEPART
TElMessagePart* TElMessage::get_Attachments(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_Attachments(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attachments)
		this->_Inst_Attachments = new TElMessagePart(hOutResult, ohFalse);
	else
		this->_Inst_Attachments->updateHandle(hOutResult);
	return this->_Inst_Attachments;
}
#endif /* SB_USE_CLASS_TELMESSAGEPART */

bool TElMessage::get_RequestReadReceipt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessage_get_RequestReadReceipt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessage::set_RequestReadReceipt(bool Value)
{
	SBCheckError(TElMessage_set_RequestReadReceipt(_Handle, (int8_t)Value));
}

bool TElMessage::get_RequestDeliveryReceipt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessage_get_RequestDeliveryReceipt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessage::set_RequestDeliveryReceipt(bool Value)
{
	SBCheckError(TElMessage_set_RequestDeliveryReceipt(_Handle, (int8_t)Value));
}

TElMIMEMessagePriority TElMessage::get_Priority()
{
	TElMIMEMessagePriorityRaw OutResultRaw = 0;
	SBCheckError(TElMessage_get_Priority(_Handle, &OutResultRaw));
	return (TElMIMEMessagePriority)OutResultRaw;
}

SB_INLINE void TElMessage::set_Priority(TElMIMEMessagePriority Value)
{
	SBCheckError(TElMessage_set_Priority(_Handle, (TElMIMEMessagePriorityRaw)Value));
}

void TElMessage::get_HeaderFieldValues(const sb_u16string &Name, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_HeaderFieldValues(_Handle, Name.data(), (int32_t)Name.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(721165479, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessage::get_HeaderFieldValues(const std::wstring &Name, std::wstring &OutResult)
{
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessage_get_HeaderFieldValues(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(721165479, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
TElMessageHeaderField* TElMessage::get_HeaderFields(const sb_u16string &AName)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_HeaderFields(_Handle, AName.data(), (int32_t)AName.length(), &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderFields)
		this->_Inst_HeaderFields = new TElMessageHeaderField(hOutResult, ohFalse);
	else
		this->_Inst_HeaderFields->updateHandle(hOutResult);
	return this->_Inst_HeaderFields;
}

#ifdef SB_U16STRING_USED
TElMessageHeaderField* TElMessage::get_HeaderFields(const std::wstring &AName)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessage_get_HeaderFields(_Handle, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderFields)
		this->_Inst_HeaderFields = new TElMessageHeaderField(hOutResult, ohFalse);
	else
		this->_Inst_HeaderFields->updateHandle(hOutResult);
	return this->_Inst_HeaderFields;
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
void TElMessage::get_AttachEncoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_AttachEncoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1223598521, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessage::set_AttachEncoding(const std::string &Value)
{
	SBCheckError(TElMessage_set_AttachEncoding(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElMessage::get_BodyEncoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_BodyEncoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-633985827, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessage::set_BodyEncoding(const std::string &Value)
{
	SBCheckError(TElMessage_set_BodyEncoding(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElMessage::get_Charset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_Charset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1167057537, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessage::set_Charset(const std::string &Value)
{
	SBCheckError(TElMessage_set_Charset(_Handle, Value.data(), (int32_t)Value.length()));
}

TElHeaderEncoding TElMessage::get_HeaderEncoding()
{
	TElHeaderEncodingRaw OutResultRaw = 0;
	SBCheckError(TElMessage_get_HeaderEncoding(_Handle, &OutResultRaw));
	return (TElHeaderEncoding)OutResultRaw;
}

SB_INLINE void TElMessage::set_HeaderEncoding(TElHeaderEncoding Value)
{
	SBCheckError(TElMessage_set_HeaderEncoding(_Handle, (TElHeaderEncodingRaw)Value));
}

TElMessageExtendedOptions TElMessage::get_ExtendedOptions()
{
	TElMessageExtendedOptionsRaw OutResultRaw = 0;
	SBCheckError(TElMessage_get_ExtendedOptions(_Handle, &OutResultRaw));
	return (TElMessageExtendedOptions)OutResultRaw;
}

SB_INLINE void TElMessage::set_ExtendedOptions(TElMessageExtendedOptions Value)
{
	SBCheckError(TElMessage_set_ExtendedOptions(_Handle, (TElMessageExtendedOptionsRaw)Value));
}

void TElMessage::get_MIMEPrefix(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_MIMEPrefix(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1518540061, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessage::set_MIMEPrefix(const std::string &Value)
{
	SBCheckError(TElMessage_set_MIMEPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElMessage::get_DefaultContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessage_get_DefaultContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(357157279, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessage::set_DefaultContentType(const std::string &Value)
{
	SBCheckError(TElMessage_set_DefaultContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElMessage::initInstances()
{
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_ReplyTo = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_ResentReplyTo = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_From = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_ResentFrom = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_Sender = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_ResentSender = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_To_ = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_ResentTo = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_CC = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_ResentCC = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_BCC = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	this->_Inst_ResentBCC = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMESSAGEPART
	this->_Inst_MainPart = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPART */
#ifdef SB_USE_CLASS_TELMESSAGEPART
	this->_Inst_Attachments = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPART */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
}

TElMessage::TElMessage(TElMessageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElMessage::TElMessage(bool bCreateMainPart, const sb_u16string &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessage_Create((int8_t)bCreateMainPart, XMailer.data(), (int32_t)XMailer.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElMessage::TElMessage(bool bCreateMainPart, const std::wstring &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16XMailer;
	sb_to_u16string(XMailer, u16XMailer);
	SBCheckError(TElMessage_Create((int8_t)bCreateMainPart, reinterpret_cast<const sb_char16_t*>(u16XMailer.data()), (int32_t)u16XMailer.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElMessage::TElMessage(TElMessagePartClassHandle AMainPartClass, int32_t Fake, const sb_u16string &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessage_Create_1(AMainPartClass, Fake, XMailer.data(), (int32_t)XMailer.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElMessage::TElMessage(TElMessagePartClassHandle AMainPartClass, int32_t Fake, const std::wstring &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16XMailer;
	sb_to_u16string(XMailer, u16XMailer);
	SBCheckError(TElMessage_Create_1(AMainPartClass, Fake, reinterpret_cast<const sb_char16_t*>(u16XMailer.data()), (int32_t)u16XMailer.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELMESSAGEPART
TElMessage::TElMessage(TElMessagePart &AMainPart, const sb_u16string &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessage_Create_2(AMainPart.getHandle(), XMailer.data(), (int32_t)XMailer.length(), &_Handle));
}

TElMessage::TElMessage(TElMessagePart *AMainPart, const sb_u16string &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessage_Create_2((AMainPart != NULL) ? AMainPart->getHandle() : SB_NULL_HANDLE, XMailer.data(), (int32_t)XMailer.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElMessage::TElMessage(TElMessagePart &AMainPart, const std::wstring &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16XMailer;
	sb_to_u16string(XMailer, u16XMailer);
	SBCheckError(TElMessage_Create_2(AMainPart.getHandle(), reinterpret_cast<const sb_char16_t*>(u16XMailer.data()), (int32_t)u16XMailer.length() >> 1, &_Handle));
}

TElMessage::TElMessage(TElMessagePart *AMainPart, const std::wstring &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16XMailer;
	sb_to_u16string(XMailer, u16XMailer);
	SBCheckError(TElMessage_Create_2((AMainPart != NULL) ? AMainPart->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16XMailer.data()), (int32_t)u16XMailer.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEPART */
TElMessage::TElMessage(const sb_u16string &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessage_Create_3(XMailer.data(), (int32_t)XMailer.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElMessage::TElMessage(const std::wstring &XMailer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16XMailer;
	sb_to_u16string(XMailer, u16XMailer);
	SBCheckError(TElMessage_Create_3(reinterpret_cast<const sb_char16_t*>(u16XMailer.data()), (int32_t)u16XMailer.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElMessage::~TElMessage()
{
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_ReplyTo;
	this->_Inst_ReplyTo = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_ResentReplyTo;
	this->_Inst_ResentReplyTo = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_From;
	this->_Inst_From = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_ResentFrom;
	this->_Inst_ResentFrom = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_Sender;
	this->_Inst_Sender = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_ResentSender;
	this->_Inst_ResentSender = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_To_;
	this->_Inst_To_ = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_ResentTo;
	this->_Inst_ResentTo = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_CC;
	this->_Inst_CC = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_ResentCC;
	this->_Inst_ResentCC = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_BCC;
	this->_Inst_BCC = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
	delete this->_Inst_ResentBCC;
	this->_Inst_ResentBCC = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */
#ifdef SB_USE_CLASS_TELMESSAGEPART
	delete this->_Inst_MainPart;
	this->_Inst_MainPart = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPART */
#ifdef SB_USE_CLASS_TELMESSAGEPART
	delete this->_Inst_Attachments;
	this->_Inst_Attachments = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPART */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	delete this->_Inst_HeaderFields;
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
}
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELMESSAGEHEADER

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessageHeader::SetField(const sb_u16string &Name, const sb_u16string &Value, int32_t Index, bool ClearParams)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessageHeader_SetField(_Handle, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length(), Index, (int8_t)ClearParams, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessageHeader::SetField(const std::wstring &Name, const std::wstring &Value, int32_t Index, bool ClearParams)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessageHeader_SetField(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, Index, (int8_t)ClearParams, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

SB_INLINE void TElMessageHeader::Assign(const TElMessageHeader &Source)
{
	SBCheckError(TElMessageHeader_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElMessageHeader::Assign(const TElMessageHeader *Source)
{
	SBCheckError(TElMessageHeader_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElMessageHeader::Clear()
{
	SBCheckError(TElMessageHeader_Clear(_Handle));
}

SB_INLINE TElMessageHeaderHandle TElMessageHeader::Clone()
{
	TElMessageHeaderHandle OutResult;
	SBCheckError(TElMessageHeader_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessageHeader::AddField(const sb_u16string &Name, const sb_u16string &Value, bool bOverride)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessageHeader_AddField(_Handle, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length(), (int8_t)bOverride, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessageHeader::AddField(const std::wstring &Name, const std::wstring &Value, bool bOverride)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessageHeader_AddField(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (int8_t)bOverride, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

SB_INLINE void TElMessageHeader::DeleteField(int32_t Index)
{
	SBCheckError(TElMessageHeader_DeleteField(_Handle, Index));
}

SB_INLINE void TElMessageHeader::DeleteField(const sb_u16string &Name, int32_t Index)
{
	SBCheckError(TElMessageHeader_DeleteField_1(_Handle, Name.data(), (int32_t)Name.length(), Index));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeader::DeleteField(const std::wstring &Name, int32_t Index)
{
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElMessageHeader_DeleteField_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, Index));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessageHeader::GetField(int32_t Index)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessageHeader_GetField(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
SB_INLINE TElMessageHeaderFieldHandle TElMessageHeader::GetField(const sb_u16string &Name, int32_t Index)
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessageHeader_GetField_1(_Handle, Name.data(), (int32_t)Name.length(), Index, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMessageHeaderFieldHandle TElMessageHeader::GetField(const std::wstring &Name, int32_t Index)
{
	TElMessageHeaderFieldHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElMessageHeader_GetField_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, Index, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

bool TElMessageHeader::FieldExists(const sb_u16string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeader_FieldExists(_Handle, Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElMessageHeader::FieldExists(const std::wstring &Name)
{
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeader_FieldExists(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
SB_INLINE void TElMessageHeader::AddMailAddressList(const TElMailAddressList &Value)
{
	SBCheckError(TElMessageHeader_AddMailAddressList(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageHeader::AddMailAddressList(const TElMailAddressList *Value)
{
	SBCheckError(TElMessageHeader_AddMailAddressList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

SB_INLINE void TElMessageHeader::DeleteMailAddressList(int32_t Index)
{
	SBCheckError(TElMessageHeader_DeleteMailAddressList(_Handle, Index));
}

SB_INLINE void TElMessageHeader::DeleteMailAddressList(const sb_u16string &Name, int32_t Index)
{
	SBCheckError(TElMessageHeader_DeleteMailAddressList_1(_Handle, Name.data(), (int32_t)Name.length(), Index));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeader::DeleteMailAddressList(const std::wstring &Name, int32_t Index)
{
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElMessageHeader_DeleteMailAddressList_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, Index));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
SB_INLINE TElMailAddressListHandle TElMessageHeader::GetMailAddressList(int32_t Index)
{
	TElMailAddressListHandle OutResult;
	SBCheckError(TElMessageHeader_GetMailAddressList(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST
SB_INLINE TElMailAddressListHandle TElMessageHeader::GetMailAddressList(const sb_u16string &Name, int32_t Index)
{
	TElMailAddressListHandle OutResult;
	SBCheckError(TElMessageHeader_GetMailAddressList_1(_Handle, Name.data(), (int32_t)Name.length(), Index, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMailAddressListHandle TElMessageHeader::GetMailAddressList(const std::wstring &Name, int32_t Index)
{
	TElMailAddressListHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElMessageHeader_GetMailAddressList_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, Index, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
int32_t TElMessageHeader::Assemble(std::string &sResult, const std::string &Charset, TElHeaderEncoding Encoding, TElMessagePartHandler &MessagePartHandler)
{
	int32_t OutResult;
	int32_t szsResult = (int32_t)sResult.length();
	uint32_t _err = TElMessageHeader_Assemble(_Handle, (char *)sResult.data(), &szsResult, Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)Encoding, MessagePartHandler.getHandle(), &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sResult.resize(szsResult);
		SBCheckError(SBGetLastReturnStringA(-1664937518, 1, (char *)sResult.data(), &szsResult));
	}
	else
		SBCheckError(_err);

	sResult.resize(szsResult);
	return OutResult;
}

int32_t TElMessageHeader::Assemble(std::string &sResult, const std::string &Charset, TElHeaderEncoding Encoding, TElMessagePartHandler *MessagePartHandler)
{
	int32_t OutResult;
	int32_t szsResult = (int32_t)sResult.length();
	uint32_t _err = TElMessageHeader_Assemble(_Handle, (char *)sResult.data(), &szsResult, Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)Encoding, (MessagePartHandler != NULL) ? MessagePartHandler->getHandle() : SB_NULL_HANDLE, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sResult.resize(szsResult);
		SBCheckError(SBGetLastReturnStringA(-1664937518, 1, (char *)sResult.data(), &szsResult));
	}
	else
		SBCheckError(_err);

	sResult.resize(szsResult);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

int32_t TElMessageHeader::Parse(const std::string &ASource, std::string &Charset, bool IgnoreNativeCharset)
{
	int32_t OutResult;
	int32_t szCharset = (int32_t)Charset.length();
	uint32_t _err = TElMessageHeader_Parse(_Handle, ASource.data(), (int32_t)ASource.length(), (char *)Charset.data(), &szCharset, (int8_t)IgnoreNativeCharset, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Charset.resize(szCharset);
		SBCheckError(SBGetLastReturnStringA(1166257265, 2, (char *)Charset.data(), &szCharset));
	}
	else
		SBCheckError(_err);

	Charset.resize(szCharset);
	return OutResult;
}

#ifdef SB_USE_CLASS_TLIST
TList* TElMessageHeader::get_AddressList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageHeader_get_AddressList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressList)
		this->_Inst_AddressList = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AddressList->updateHandle(hOutResult);
	return this->_Inst_AddressList;
}
#endif /* SB_USE_CLASS_TLIST */

bool TElMessageHeader::get_AllowLongLines()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeader_get_AllowLongLines(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageHeader::set_AllowLongLines(bool Value)
{
	SBCheckError(TElMessageHeader_set_AllowLongLines(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElMessageHeader::get_BodyLen()
{
	int32_t OutResult;
	SBCheckError(TElMessageHeader_get_BodyLen(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageHeader::set_BodyLen(int32_t Value)
{
	SBCheckError(TElMessageHeader_set_BodyLen(_Handle, Value));
}

SB_INLINE int32_t TElMessageHeader::get_FieldsCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageHeader_get_FieldsCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TLIST
TList* TElMessageHeader::get_HeaderFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageHeader_get_HeaderFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderFields)
		this->_Inst_HeaderFields = new TList(hOutResult, ohFalse);
	else
		this->_Inst_HeaderFields->updateHandle(hOutResult);
	return this->_Inst_HeaderFields;
}
#endif /* SB_USE_CLASS_TLIST */

SB_INLINE int32_t TElMessageHeader::get_MailAddressListCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageHeader_get_MailAddressListCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageHeader::get_StreamPosBegin()
{
	int32_t OutResult;
	SBCheckError(TElMessageHeader_get_StreamPosBegin(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageHeader::set_StreamPosBegin(int32_t Value)
{
	SBCheckError(TElMessageHeader_set_StreamPosBegin(_Handle, Value));
}

bool TElMessageHeader::get_ParseAddresses()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeader_get_ParseAddresses(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageHeader::set_ParseAddresses(bool Value)
{
	SBCheckError(TElMessageHeader_set_ParseAddresses(_Handle, (int8_t)Value));
}

bool TElMessageHeader::get_CombineParameters()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeader_get_CombineParameters(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageHeader::set_CombineParameters(bool Value)
{
	SBCheckError(TElMessageHeader_set_CombineParameters(_Handle, (int8_t)Value));
}

void TElMessageHeader::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AddressList = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElMessageHeader::TElMessageHeader(TElMessageHeaderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElMessageHeader::TElMessageHeader() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageHeader_Create(&_Handle));
}

TElMessageHeader::~TElMessageHeader()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AddressList;
	this->_Inst_AddressList = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_HeaderFields;
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD

SB_INLINE void TElMessageHeaderField::Clear()
{
	SBCheckError(TElMessageHeaderField_Clear(_Handle));
}

SB_INLINE TElMessageHeaderFieldHandle TElMessageHeaderField::Clone()
{
	TElMessageHeaderFieldHandle OutResult;
	SBCheckError(TElMessageHeaderField_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageHeaderField::AddParam(const sb_u16string &ParamName, const sb_u16string &ParamValue)
{
	SBCheckError(TElMessageHeaderField_AddParam(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamValue.data(), (int32_t)ParamValue.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeaderField::AddParam(const std::wstring &ParamName, const std::wstring &ParamValue)
{
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamValue;
	sb_to_u16string(ParamValue, u16ParamValue);
	SBCheckError(TElMessageHeaderField_AddParam(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamValue.data()), (int32_t)u16ParamValue.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessageHeaderField::ClearParams()
{
	SBCheckError(TElMessageHeaderField_ClearParams(_Handle));
}

SB_INLINE void TElMessageHeaderField::DeleteParam(int32_t Index)
{
	SBCheckError(TElMessageHeaderField_DeleteParam(_Handle, Index));
}

SB_INLINE void TElMessageHeaderField::DeleteParam(const sb_u16string &ParamName)
{
	SBCheckError(TElMessageHeaderField_DeleteParam_1(_Handle, ParamName.data(), (int32_t)ParamName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeaderField::DeleteParam(const std::wstring &ParamName)
{
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElMessageHeaderField_DeleteParam_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElMessageHeaderField::GetParamIndexByName(const sb_u16string &ParamName)
{
	int32_t OutResult;
	SBCheckError(TElMessageHeaderField_GetParamIndexByName(_Handle, ParamName.data(), (int32_t)ParamName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElMessageHeaderField::GetParamIndexByName(const std::wstring &ParamName)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElMessageHeaderField_GetParamIndexByName(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

void TElMessageHeaderField::GetParamName(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageHeaderField_GetParamName(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-197441657, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessageHeaderField::GetParamName(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessageHeaderField_GetParamName(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-197441657, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElMessageHeaderField::GetParamValue(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageHeaderField_GetParamValue(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1322077368, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessageHeaderField::GetParamValue(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessageHeaderField_GetParamValue(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1322077368, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElMessageHeaderField::GetParamValue(const sb_u16string &ParamName, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageHeaderField_GetParamValue_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1621625455, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessageHeaderField::GetParamValue(const std::wstring &ParamName, std::wstring &OutResult)
{
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessageHeaderField_GetParamValue_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1621625455, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElMessageHeaderField::ParamExists(const sb_u16string &ParamName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeaderField_ParamExists(_Handle, ParamName.data(), (int32_t)ParamName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElMessageHeaderField::ParamExists(const std::wstring &ParamName)
{
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeaderField_ParamExists(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessageHeaderField::SetParamValue(int32_t Index, const sb_u16string &wsValue)
{
	SBCheckError(TElMessageHeaderField_SetParamValue(_Handle, Index, wsValue.data(), (int32_t)wsValue.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeaderField::SetParamValue(int32_t Index, const std::wstring &wsValue)
{
	std::string u16wsValue;
	sb_to_u16string(wsValue, u16wsValue);
	SBCheckError(TElMessageHeaderField_SetParamValue(_Handle, Index, reinterpret_cast<const sb_char16_t*>(u16wsValue.data()), (int32_t)u16wsValue.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessageHeaderField::SetParamValue(const sb_u16string &ParamName, const sb_u16string &wsValue)
{
	SBCheckError(TElMessageHeaderField_SetParamValue_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), wsValue.data(), (int32_t)wsValue.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeaderField::SetParamValue(const std::wstring &ParamName, const std::wstring &wsValue)
{
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16wsValue;
	sb_to_u16string(wsValue, u16wsValue);
	SBCheckError(TElMessageHeaderField_SetParamValue_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16wsValue.data()), (int32_t)u16wsValue.length() >> 1));
}
#endif /* SB_U16STRING_USED */

void TElMessageHeaderField::get_Body(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageHeaderField_get_Body(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-202174510, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessageHeaderField::get_Body(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessageHeaderField_get_Body(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-202174510, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMessageHeaderField::set_Body(const sb_u16string &Value)
{
	SBCheckError(TElMessageHeaderField_set_Body(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeaderField::set_Body(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessageHeaderField_set_Body(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElMessageHeaderField::get_Comments(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageHeaderField_get_Comments(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(772749964, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessageHeaderField::get_Comments(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessageHeaderField_get_Comments(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(772749964, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMessageHeaderField::set_Comments(const sb_u16string &Value)
{
	SBCheckError(TElMessageHeaderField_set_Comments(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeaderField::set_Comments(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessageHeaderField_set_Comments(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
bool TElMessageHeaderField::get_EncodedWords()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeaderField_get_EncodedWords(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageHeaderField::set_EncodedWords(bool Value)
{
	SBCheckError(TElMessageHeaderField_set_EncodedWords(_Handle, (int8_t)Value));
}

bool TElMessageHeaderField::get_QuotedParams()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageHeaderField_get_QuotedParams(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageHeaderField::set_QuotedParams(bool Value)
{
	SBCheckError(TElMessageHeaderField_set_QuotedParams(_Handle, (int8_t)Value));
}

void TElMessageHeaderField::get_Name(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageHeaderField_get_Name(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1987607142, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessageHeaderField::get_Name(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessageHeaderField_get_Name(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1987607142, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMessageHeaderField::set_Name(const sb_u16string &Value)
{
	SBCheckError(TElMessageHeaderField_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeaderField::set_Name(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessageHeaderField_set_Name(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElMessageHeaderField::get_ParamsCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageHeaderField_get_ParamsCount(_Handle, &OutResult));
	return OutResult;
}

void TElMessageHeaderField::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageHeaderField_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2098229787, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessageHeaderField::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessageHeaderField_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2098229787, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMessageHeaderField::set_Value(const sb_u16string &Value)
{
	SBCheckError(TElMessageHeaderField_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMessageHeaderField::set_Value(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessageHeaderField_set_Value(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElMessageHeaderField::TElMessageHeaderField(TElMessageHeaderFieldHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElMessageHeaderField::TElMessageHeaderField() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessageHeaderField_Create(&_Handle));
}

TElMessageHeaderField::TElMessageHeaderField(const sb_u16string &AName, const sb_u16string &AValue) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessageHeaderField_Create_1(AName.data(), (int32_t)AName.length(), AValue.data(), (int32_t)AValue.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElMessageHeaderField::TElMessageHeaderField(const std::wstring &AName, const std::wstring &AValue) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	std::string u16AValue;
	sb_to_u16string(AValue, u16AValue);
	SBCheckError(TElMessageHeaderField_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AValue.data()), (int32_t)u16AValue.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElMessageHeaderField::TElMessageHeaderField(const std::string &Source, int32_t &Offset, const std::string &Charset, bool IgnoreNativeCharset) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessageHeaderField_Create_2(Source.data(), (int32_t)Source.length(), &Offset, Charset.data(), (int32_t)Charset.length(), (int8_t)IgnoreNativeCharset, &_Handle));
}

#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMAILADDRESSGROUP

#ifdef SB_USE_CLASS_TELMAILADDRESS
SB_INLINE TElMailAddressHandle TElMailAddressGroup::AddAddress(const sb_u16string &AAlias, const sb_u16string &AAddress)
{
	TElMailAddressHandle OutResult;
	SBCheckError(TElMailAddressGroup_AddAddress(_Handle, AAlias.data(), (int32_t)AAlias.length(), AAddress.data(), (int32_t)AAddress.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMailAddressHandle TElMailAddressGroup::AddAddress(const std::wstring &AAlias, const std::wstring &AAddress)
{
	TElMailAddressHandle OutResult;
	std::string u16AAlias;
	sb_to_u16string(AAlias, u16AAlias);
	std::string u16AAddress;
	sb_to_u16string(AAddress, u16AAddress);
	SBCheckError(TElMailAddressGroup_AddAddress(_Handle, reinterpret_cast<const sb_char16_t*>(u16AAlias.data()), (int32_t)u16AAlias.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AAddress.data()), (int32_t)u16AAddress.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMAILADDRESS */

SB_INLINE void TElMailAddressGroup::Clear()
{
	SBCheckError(TElMailAddressGroup_Clear(_Handle));
}

SB_INLINE TElMailAddressGroupHandle TElMailAddressGroup::Clone()
{
	TElMailAddressGroupHandle OutResult;
	SBCheckError(TElMailAddressGroup_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMailAddressGroup::DeleteAddress(int32_t Index)
{
	SBCheckError(TElMailAddressGroup_DeleteAddress(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELMAILADDRESS
SB_INLINE int32_t TElMailAddressGroup::IndexOfAddress(TElMailAddress &AAddress)
{
	int32_t OutResult;
	SBCheckError(TElMailAddressGroup_IndexOfAddress(_Handle, AAddress.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMailAddressGroup::IndexOfAddress(TElMailAddress *AAddress)
{
	int32_t OutResult;
	SBCheckError(TElMailAddressGroup_IndexOfAddress(_Handle, (AAddress != NULL) ? AAddress->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMAILADDRESS */

void TElMailAddressGroup::get_Name(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMailAddressGroup_get_Name(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1201065989, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMailAddressGroup::get_Name(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMailAddressGroup_get_Name(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1201065989, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMailAddressGroup::set_Name(const sb_u16string &Value)
{
	SBCheckError(TElMailAddressGroup_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMailAddressGroup::set_Name(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMailAddressGroup_set_Name(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElMailAddressGroup::get_AddressesCount()
{
	int32_t OutResult;
	SBCheckError(TElMailAddressGroup_get_AddressesCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELMAILADDRESS
TElMailAddress* TElMailAddressGroup::get_Address(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMailAddressGroup_get_Address(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Address)
		this->_Inst_Address = new TElMailAddress(hOutResult, ohFalse);
	else
		this->_Inst_Address->updateHandle(hOutResult);
	return this->_Inst_Address;
}
#endif /* SB_USE_CLASS_TELMAILADDRESS */

void TElMailAddressGroup::initInstances()
{
#ifdef SB_USE_CLASS_TELMAILADDRESS
	this->_Inst_Address = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESS */
}

TElMailAddressGroup::TElMailAddressGroup(TElMailAddressGroupHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElMailAddressGroup::TElMailAddressGroup() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMailAddressGroup_Create(&_Handle));
}

TElMailAddressGroup::~TElMailAddressGroup()
{
#ifdef SB_USE_CLASS_TELMAILADDRESS
	delete this->_Inst_Address;
	this->_Inst_Address = NULL;
#endif /* SB_USE_CLASS_TELMAILADDRESS */
}
#endif /* SB_USE_CLASS_TELMAILADDRESSGROUP */

#ifdef SB_USE_CLASS_TELMAILADDRESSLIST

SB_INLINE void TElMailAddressList::Clear()
{
	SBCheckError(TElMailAddressList_Clear(_Handle));
}

SB_INLINE TElMailAddressListHandle TElMailAddressList::Clone()
{
	TElMailAddressListHandle OutResult;
	SBCheckError(TElMailAddressList_Clone(_Handle, &OutResult));
	return OutResult;
}

int32_t TElMailAddressList::Assemble(const sb_u16string &FieldName, std::string &sResult, const std::string &Charset, TElHeaderEncoding Encoding, bool AllowLongHeaderLines)
{
	int32_t OutResult;
	int32_t szsResult = (int32_t)sResult.length();
	uint32_t _err = TElMailAddressList_Assemble(_Handle, FieldName.data(), (int32_t)FieldName.length(), (char *)sResult.data(), &szsResult, Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)Encoding, (int8_t)AllowLongHeaderLines, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sResult.resize(szsResult);
		SBCheckError(SBGetLastReturnStringA(412298409, 2, (char *)sResult.data(), &szsResult));
	}
	else
		SBCheckError(_err);

	sResult.resize(szsResult);
	return OutResult;
}
#ifdef SB_U16STRING_USED
int32_t TElMailAddressList::Assemble(const std::wstring &FieldName, std::string &sResult, const std::string &Charset, TElHeaderEncoding Encoding, bool AllowLongHeaderLines)
{
	int32_t OutResult;
	std::string u16FieldName;
	sb_to_u16string(FieldName, u16FieldName);
	int32_t szsResult = (int32_t)sResult.length();
	uint32_t _err = TElMailAddressList_Assemble(_Handle, reinterpret_cast<const sb_char16_t*>(u16FieldName.data()), (int32_t)u16FieldName.length() >> 1, (char *)sResult.data(), &szsResult, Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)Encoding, (int8_t)AllowLongHeaderLines, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sResult.resize(szsResult);
		SBCheckError(SBGetLastReturnStringA(412298409, 2, (char *)sResult.data(), &szsResult));
	}
	else
		SBCheckError(_err);

	sResult.resize(szsResult);
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElMailAddressList::Parse(const sb_u16string &wsSource)
{
	int32_t OutResult;
	SBCheckError(TElMailAddressList_Parse(_Handle, wsSource.data(), (int32_t)wsSource.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElMailAddressList::Parse(const std::wstring &wsSource)
{
	int32_t OutResult;
	std::string u16wsSource;
	sb_to_u16string(wsSource, u16wsSource);
	SBCheckError(TElMailAddressList_Parse(_Handle, reinterpret_cast<const sb_char16_t*>(u16wsSource.data()), (int32_t)u16wsSource.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElMailAddressList::Parse(const sb_u16string &wsSource, const std::string &Charset, bool IgnoreNativeCharset)
{
	int32_t OutResult;
	SBCheckError(TElMailAddressList_Parse_1(_Handle, wsSource.data(), (int32_t)wsSource.length(), Charset.data(), (int32_t)Charset.length(), (int8_t)IgnoreNativeCharset, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElMailAddressList::Parse(const std::wstring &wsSource, const std::string &Charset, bool IgnoreNativeCharset)
{
	int32_t OutResult;
	std::string u16wsSource;
	sb_to_u16string(wsSource, u16wsSource);
	SBCheckError(TElMailAddressList_Parse_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16wsSource.data()), (int32_t)u16wsSource.length() >> 1, Charset.data(), (int32_t)Charset.length(), (int8_t)IgnoreNativeCharset, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESS
SB_INLINE TElMailAddressHandle TElMailAddressList::AddAddress(const sb_u16string &Alias, const sb_u16string &Address)
{
	TElMailAddressHandle OutResult;
	SBCheckError(TElMailAddressList_AddAddress(_Handle, Alias.data(), (int32_t)Alias.length(), Address.data(), (int32_t)Address.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElMailAddressHandle TElMailAddressList::AddAddress(const std::wstring &Alias, const std::wstring &Address)
{
	TElMailAddressHandle OutResult;
	std::string u16Alias;
	sb_to_u16string(Alias, u16Alias);
	std::string u16Address;
	sb_to_u16string(Address, u16Address);
	SBCheckError(TElMailAddressList_AddAddress(_Handle, reinterpret_cast<const sb_char16_t*>(u16Alias.data()), (int32_t)u16Alias.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Address.data()), (int32_t)u16Address.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMAILADDRESS */

SB_INLINE void TElMailAddressList::DeleteAddress(int32_t Index)
{
	SBCheckError(TElMailAddressList_DeleteAddress(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELMAILADDRESS
SB_INLINE TElMailAddressHandle TElMailAddressList::GetAddress(int32_t Index)
{
	TElMailAddressHandle OutResult;
	SBCheckError(TElMailAddressList_GetAddress(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMAILADDRESS
SB_INLINE int32_t TElMailAddressList::IndexOfAddress(TElMailAddress &Address)
{
	int32_t OutResult;
	SBCheckError(TElMailAddressList_IndexOfAddress(_Handle, Address.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMailAddressList::IndexOfAddress(TElMailAddress *Address)
{
	int32_t OutResult;
	SBCheckError(TElMailAddressList_IndexOfAddress(_Handle, (Address != NULL) ? Address->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMAILADDRESSGROUP
SB_INLINE TElMailAddressGroupHandle TElMailAddressList::AddGroup(TElMailAddressGroup &Group, bool bMakeCopy)
{
	TElMailAddressGroupHandle OutResult;
	SBCheckError(TElMailAddressList_AddGroup(_Handle, Group.getHandle(), (int8_t)bMakeCopy, &OutResult));
	return OutResult;
}

SB_INLINE TElMailAddressGroupHandle TElMailAddressList::AddGroup(TElMailAddressGroup *Group, bool bMakeCopy)
{
	TElMailAddressGroupHandle OutResult;
	SBCheckError(TElMailAddressList_AddGroup(_Handle, (Group != NULL) ? Group->getHandle() : SB_NULL_HANDLE, (int8_t)bMakeCopy, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMAILADDRESSGROUP */

SB_INLINE void TElMailAddressList::DeleteGroup(int32_t Index)
{
	SBCheckError(TElMailAddressList_DeleteGroup(_Handle, Index));
}

SB_INLINE void TElMailAddressList::DeleteGroup(const sb_u16string &GroupName)
{
	SBCheckError(TElMailAddressList_DeleteGroup_1(_Handle, GroupName.data(), (int32_t)GroupName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMailAddressList::DeleteGroup(const std::wstring &GroupName)
{
	std::string u16GroupName;
	sb_to_u16string(GroupName, u16GroupName);
	SBCheckError(TElMailAddressList_DeleteGroup_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16GroupName.data()), (int32_t)u16GroupName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESSGROUP
SB_INLINE TElMailAddressGroupHandle TElMailAddressList::GetGroup(int32_t Index)
{
	TElMailAddressGroupHandle OutResult;
	SBCheckError(TElMailAddressList_GetGroup(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMAILADDRESSGROUP */

void TElMailAddressList::GetGroupName(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMailAddressList_GetGroupName(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1630850597, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMailAddressList::GetGroupName(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMailAddressList_GetGroupName(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1630850597, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELMAILADDRESS
SB_INLINE TElMailAddressHandle TElMailAddressList::GetAddressFromAll(int32_t Index)
{
	TElMailAddressHandle OutResult;
	SBCheckError(TElMailAddressList_GetAddressFromAll(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMAILADDRESS */

SB_INLINE int32_t TElMailAddressList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElMailAddressList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElMailAddressList::get_FieldName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMailAddressList_get_FieldName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2021753910, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMailAddressList::get_FieldName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMailAddressList_get_FieldName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2021753910, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMailAddressList::set_FieldName(const sb_u16string &Value)
{
	SBCheckError(TElMailAddressList_set_FieldName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMailAddressList::set_FieldName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMailAddressList_set_FieldName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElMailAddressList::get_GroupsCount()
{
	int32_t OutResult;
	SBCheckError(TElMailAddressList_get_GroupsCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMailAddressList::get_TotalCount()
{
	int32_t OutResult;
	SBCheckError(TElMailAddressList_get_TotalCount(_Handle, &OutResult));
	return OutResult;
}

TElMailAddressList::TElMailAddressList(TElMailAddressListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElMailAddressList::TElMailAddressList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMailAddressList_Create(&_Handle));
}

TElMailAddressList::TElMailAddressList(const sb_u16string &Source) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMailAddressList_Create_1(Source.data(), (int32_t)Source.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElMailAddressList::TElMailAddressList(const std::wstring &Source) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16Source;
	sb_to_u16string(Source, u16Source);
	SBCheckError(TElMailAddressList_Create_1(reinterpret_cast<const sb_char16_t*>(u16Source.data()), (int32_t)u16Source.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMAILADDRESSLIST */

#ifdef SB_USE_CLASS_TELMAILADDRESS

SB_INLINE void TElMailAddress::Clear()
{
	SBCheckError(TElMailAddress_Clear(_Handle));
}

SB_INLINE TElMailAddressHandle TElMailAddress::Clone()
{
	TElMailAddressHandle OutResult;
	SBCheckError(TElMailAddress_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElMailAddress::IsAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMailAddress_IsAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMailAddress::IsAlias()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMailAddress_IsAlias(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElMailAddress::get_Alias(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMailAddress_get_Alias(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-28242891, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMailAddress::get_Alias(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMailAddress_get_Alias(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-28242891, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMailAddress::set_Alias(const sb_u16string &Value)
{
	SBCheckError(TElMailAddress_set_Alias(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMailAddress::set_Alias(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMailAddress_set_Alias(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElMailAddress::get_Address(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMailAddress_get_Address(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(677190416, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMailAddress::get_Address(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMailAddress_get_Address(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(677190416, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMailAddress::set_Address(const sb_u16string &Value)
{
	SBCheckError(TElMailAddress_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMailAddress::set_Address(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMailAddress_set_Address(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElMailAddress::get_Comments(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMailAddress_get_Comments(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(179423489, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMailAddress::get_Comments(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMailAddress_get_Comments(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(179423489, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMailAddress::set_Comments(const sb_u16string &Value)
{
	SBCheckError(TElMailAddress_set_Comments(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMailAddress::set_Comments(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMailAddress_set_Comments(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElMailAddress::TElMailAddress(TElMailAddressHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElMailAddress::TElMailAddress() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMailAddress_Create(&_Handle));
}

TElMailAddress::TElMailAddress(const sb_u16string &AAlias, const sb_u16string &AAddress) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMailAddress_Create_1(AAlias.data(), (int32_t)AAlias.length(), AAddress.data(), (int32_t)AAddress.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElMailAddress::TElMailAddress(const std::wstring &AAlias, const std::wstring &AAddress) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AAlias;
	sb_to_u16string(AAlias, u16AAlias);
	std::string u16AAddress;
	sb_to_u16string(AAddress, u16AAddress);
	SBCheckError(TElMailAddress_Create_1(reinterpret_cast<const sb_char16_t*>(u16AAlias.data()), (int32_t)u16AAlias.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AAddress.data()), (int32_t)u16AAddress.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMAILADDRESS */

#ifdef SB_USE_CLASS_TELMESSAGEPART

#ifdef SB_USE_CLASSES_TELMESSAGE_AND_TELMESSAGEHEADER
SB_INLINE TElMessagePartHandle TElMessagePart::CreatePartForHeader(TElMessageHeader &Header, TElMessage &AMessage, TElMessagePart &AParent)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessagePart_CreatePartForHeader(Header.getHandle(), AMessage.getHandle(), AParent.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMessagePart::CreatePartForHeader(TElMessageHeader *Header, TElMessage *AMessage, TElMessagePart *AParent)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessagePart_CreatePartForHeader((Header != NULL) ? Header->getHandle() : SB_NULL_HANDLE, (AMessage != NULL) ? AMessage->getHandle() : SB_NULL_HANDLE, (AParent != NULL) ? AParent->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELMESSAGE_AND_TELMESSAGEHEADER */

#ifdef SB_USE_CLASSES_TELMESSAGE_AND_TELMESSAGEHEADER
SB_INLINE TElMessagePartHandle TElMessagePart::CreatePartForHeader_Inst(TElMessageHeader &Header, TElMessage &AMessage, TElMessagePart &AParent)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessagePart_CreatePartForHeader_1(_Handle, Header.getHandle(), AMessage.getHandle(), AParent.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMessagePart::CreatePartForHeader_Inst(TElMessageHeader *Header, TElMessage *AMessage, TElMessagePart *AParent)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessagePart_CreatePartForHeader_1(_Handle, (Header != NULL) ? Header->getHandle() : SB_NULL_HANDLE, (AMessage != NULL) ? AMessage->getHandle() : SB_NULL_HANDLE, (AParent != NULL) ? AParent->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELMESSAGE_AND_TELMESSAGEHEADER */

SB_INLINE void TElMessagePart::Assign(TElMessagePart &Source)
{
	SBCheckError(TElMessagePart_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElMessagePart::Assign(TElMessagePart *Source)
{
	SBCheckError(TElMessagePart_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElMessagePart::Clear()
{
	SBCheckError(TElMessagePart_Clear(_Handle));
}

SB_INLINE TElMessagePartHandle TElMessagePart::Clone()
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessagePart_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM
SB_INLINE int32_t TElMessagePart::Parse(TElMessageHeader &Header, TStream &Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_Parse(_Handle, Header.getHandle(), Source.getHandle(), Boundary.data(), (int32_t)Boundary.length(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessagePart::Parse(TElMessageHeader *Header, TStream *Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_Parse(_Handle, (Header != NULL) ? Header->getHandle() : SB_NULL_HANDLE, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Boundary.data(), (int32_t)Boundary.length(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessagePart::Assemble(TStream &Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_Assemble(_Handle, Destination.getHandle(), Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessagePart::Assemble(TStream *Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_Assemble(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElMessagePart::IsText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsTextPlain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsTextPlain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsTextHtml()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsTextHtml(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsImage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsImage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsAudio()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsAudio(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsVideo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsVideo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsMultipart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsMultipart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsAttachment()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsAttachment(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsInline()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsInline(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePart::IsApplication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_IsApplication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePart::SetFieldValue(const sb_u16string &Name, const sb_u16string &Value, bool ClearParams)
{
	SBCheckError(TElMessagePart_SetFieldValue(_Handle, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length(), (int8_t)ClearParams));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetFieldValue(const std::wstring &Name, const std::wstring &Value, bool ClearParams)
{
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessagePart_SetFieldValue(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (int8_t)ClearParams));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessagePart::SetContentType(const sb_u16string &AValue, bool ClearParams)
{
	SBCheckError(TElMessagePart_SetContentType(_Handle, AValue.data(), (int32_t)AValue.length(), (int8_t)ClearParams));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetContentType(const std::wstring &AValue, bool ClearParams)
{
	std::string u16AValue;
	sb_to_u16string(AValue, u16AValue);
	SBCheckError(TElMessagePart_SetContentType(_Handle, reinterpret_cast<const sb_char16_t*>(u16AValue.data()), (int32_t)u16AValue.length() >> 1, (int8_t)ClearParams));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessagePart::SetContentSubtype(const sb_u16string &AValue, bool ClearParams)
{
	SBCheckError(TElMessagePart_SetContentSubtype(_Handle, AValue.data(), (int32_t)AValue.length(), (int8_t)ClearParams));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetContentSubtype(const std::wstring &AValue, bool ClearParams)
{
	std::string u16AValue;
	sb_to_u16string(AValue, u16AValue);
	SBCheckError(TElMessagePart_SetContentSubtype(_Handle, reinterpret_cast<const sb_char16_t*>(u16AValue.data()), (int32_t)u16AValue.length() >> 1, (int8_t)ClearParams));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessagePart::SetContentTransferEncoding(const sb_u16string &AValue, bool ClearParams)
{
	SBCheckError(TElMessagePart_SetContentTransferEncoding(_Handle, AValue.data(), (int32_t)AValue.length(), (int8_t)ClearParams));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetContentTransferEncoding(const std::wstring &AValue, bool ClearParams)
{
	std::string u16AValue;
	sb_to_u16string(AValue, u16AValue);
	SBCheckError(TElMessagePart_SetContentTransferEncoding(_Handle, reinterpret_cast<const sb_char16_t*>(u16AValue.data()), (int32_t)u16AValue.length() >> 1, (int8_t)ClearParams));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessagePart::SetContentID(const sb_u16string &AValue, bool ClearParams)
{
	SBCheckError(TElMessagePart_SetContentID(_Handle, AValue.data(), (int32_t)AValue.length(), (int8_t)ClearParams));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetContentID(const std::wstring &AValue, bool ClearParams)
{
	std::string u16AValue;
	sb_to_u16string(AValue, u16AValue);
	SBCheckError(TElMessagePart_SetContentID(_Handle, reinterpret_cast<const sb_char16_t*>(u16AValue.data()), (int32_t)u16AValue.length() >> 1, (int8_t)ClearParams));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessagePart::SetContentDisposition(const sb_u16string &AValue, bool ClearParams)
{
	SBCheckError(TElMessagePart_SetContentDisposition(_Handle, AValue.data(), (int32_t)AValue.length(), (int8_t)ClearParams));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetContentDisposition(const std::wstring &AValue, bool ClearParams)
{
	std::string u16AValue;
	sb_to_u16string(AValue, u16AValue);
	SBCheckError(TElMessagePart_SetContentDisposition(_Handle, reinterpret_cast<const sb_char16_t*>(u16AValue.data()), (int32_t)u16AValue.length() >> 1, (int8_t)ClearParams));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessagePart::SetContentDescription(const sb_u16string &AValue, bool ClearParams)
{
	SBCheckError(TElMessagePart_SetContentDescription(_Handle, AValue.data(), (int32_t)AValue.length(), (int8_t)ClearParams));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetContentDescription(const std::wstring &AValue, bool ClearParams)
{
	std::string u16AValue;
	sb_to_u16string(AValue, u16AValue);
	SBCheckError(TElMessagePart_SetContentDescription(_Handle, reinterpret_cast<const sb_char16_t*>(u16AValue.data()), (int32_t)u16AValue.length() >> 1, (int8_t)ClearParams));
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElMessagePart::GetDataSize(int32_t &Size)
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_GetDataSize(_Handle, &Size, &OutResult));
	return OutResult;
}

int32_t TElMessagePart::GetData(sb_u16string &wsData)
{
	int32_t OutResult;
	int32_t szwsData = (int32_t)wsData.length();
	uint32_t _err = TElMessagePart_GetData(_Handle, (sb_char16_t *)wsData.data(), &szwsData, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		wsData.resize(szwsData);
		SBCheckError(SBGetLastReturnStringW(1876634750, 1, (sb_char16_t *)wsData.data(), &szwsData));
	}
	else
		SBCheckError(_err);

	wsData.resize(szwsData);
	return OutResult;
}
#ifdef SB_U16STRING_USED
int32_t TElMessagePart::GetData(std::wstring &wsData)
{
	int32_t OutResult;
	std::string u16wsData;
	sb_to_u16string(wsData, u16wsData);
	int32_t szwsData = (int32_t)u16wsData.length() >> 1;
	uint32_t _err = TElMessagePart_GetData(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16wsData.data()), &szwsData, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16wsData.resize(szwsData << 1);
		SBCheckError(SBGetLastReturnStringW(1876634750, 1, reinterpret_cast<sb_char16_t*>((char*)u16wsData.data()), &szwsData));
	}
	else
		SBCheckError(_err);

	u16wsData.resize(szwsData << 1);
	sb_u16_to_wstring(u16wsData, wsData);
	return OutResult;
}
#endif /* SB_U16STRING_USED */

int32_t TElMessagePart::GetData(std::vector<uint8_t> &Buffer, int32_t &BufferSize)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElMessagePart_GetData_1(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &BufferSize, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1533003613, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessagePart::SaveDataToStream(TStream &Stream)
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_SaveDataToStream(_Handle, Stream.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessagePart::SaveDataToStream(TStream *Stream)
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_SaveDataToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElMessagePart::SaveDataToFile(const sb_u16string &wsFileName)
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_SaveDataToFile(_Handle, wsFileName.data(), (int32_t)wsFileName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElMessagePart::SaveDataToFile(const std::wstring &wsFileName)
{
	int32_t OutResult;
	std::string u16wsFileName;
	sb_to_u16string(wsFileName, u16wsFileName);
	SBCheckError(TElMessagePart_SaveDataToFile(_Handle, reinterpret_cast<const sb_char16_t*>(u16wsFileName.data()), (int32_t)u16wsFileName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElMessagePart::SetData(TStream &Stream, int32_t DataSize, bool bMakeCopy)
{
	SBCheckError(TElMessagePart_SetData(_Handle, Stream.getHandle(), DataSize, (int8_t)bMakeCopy));
}

SB_INLINE void TElMessagePart::SetData(TStream *Stream, int32_t DataSize, bool bMakeCopy)
{
	SBCheckError(TElMessagePart_SetData(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, DataSize, (int8_t)bMakeCopy));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElMessagePart::SetData(const sb_u16string &wsData)
{
	SBCheckError(TElMessagePart_SetData_1(_Handle, wsData.data(), (int32_t)wsData.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetData(const std::wstring &wsData)
{
	std::string u16wsData;
	sb_to_u16string(wsData, u16wsData);
	SBCheckError(TElMessagePart_SetData_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16wsData.data()), (int32_t)u16wsData.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessagePart::SetData(const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	SBCheckError(TElMessagePart_SetData_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count));
}

int32_t TElMessagePart::GetText(sb_u16string &AText)
{
	int32_t OutResult;
	int32_t szAText = (int32_t)AText.length();
	uint32_t _err = TElMessagePart_GetText(_Handle, (sb_char16_t *)AText.data(), &szAText, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		AText.resize(szAText);
		SBCheckError(SBGetLastReturnStringW(-1672392865, 1, (sb_char16_t *)AText.data(), &szAText));
	}
	else
		SBCheckError(_err);

	AText.resize(szAText);
	return OutResult;
}
#ifdef SB_U16STRING_USED
int32_t TElMessagePart::GetText(std::wstring &AText)
{
	int32_t OutResult;
	std::string u16AText;
	sb_to_u16string(AText, u16AText);
	int32_t szAText = (int32_t)u16AText.length() >> 1;
	uint32_t _err = TElMessagePart_GetText(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16AText.data()), &szAText, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16AText.resize(szAText << 1);
		SBCheckError(SBGetLastReturnStringW(-1672392865, 1, reinterpret_cast<sb_char16_t*>((char*)u16AText.data()), &szAText));
	}
	else
		SBCheckError(_err);

	u16AText.resize(szAText << 1);
	sb_u16_to_wstring(u16AText, AText);
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMessagePart::SetText(const sb_u16string &AText)
{
	SBCheckError(TElMessagePart_SetText(_Handle, AText.data(), (int32_t)AText.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::SetText(const std::wstring &AText)
{
	std::string u16AText;
	sb_to_u16string(AText, u16AText);
	SBCheckError(TElMessagePart_SetText(_Handle, reinterpret_cast<const sb_char16_t*>(u16AText.data()), (int32_t)u16AText.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE TElMessagePartHandle TElMessagePart::GetPart(int32_t Index)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessagePart_GetPart(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMessagePart::AddPart(TElMessagePart &Part, bool bMakeCopy, int32_t PartIndex)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessagePart_AddPart(_Handle, Part.getHandle(), (int8_t)bMakeCopy, PartIndex, &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMessagePart::AddPart(TElMessagePart *Part, bool bMakeCopy, int32_t PartIndex)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMessagePart_AddPart(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, (int8_t)bMakeCopy, PartIndex, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePart::AddPart(TElMessagePart &Part)
{
	SBCheckError(TElMessagePart_AddPart_1(_Handle, Part.getHandle()));
}

SB_INLINE void TElMessagePart::AddPart(TElMessagePart *Part)
{
	SBCheckError(TElMessagePart_AddPart_1(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElMessagePart::DeletePart(int32_t Index, bool bDestroy)
{
	SBCheckError(TElMessagePart_DeletePart(_Handle, Index, (int8_t)bDestroy));
}

SB_INLINE void TElMessagePart::DeletePart(TElMessagePart &Part, bool bDestroy)
{
	SBCheckError(TElMessagePart_DeletePart_1(_Handle, Part.getHandle(), (int8_t)bDestroy));
}

SB_INLINE void TElMessagePart::DeletePart(TElMessagePart *Part, bool bDestroy)
{
	SBCheckError(TElMessagePart_DeletePart_1(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, (int8_t)bDestroy));
}

SB_INLINE TClassHandle TElMessagePart::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElMessagePart_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessagePart::get_BodyLen()
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_get_BodyLen(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElMessagePart::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElMessagePart::get_StreamPosBegin()
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_get_StreamPosBegin(_Handle, &OutResult));
	return OutResult;
}

void TElMessagePart::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMessagePart_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(702251841, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessagePart::set_Data(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElMessagePart_set_Data(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElMessagePart::get_DataStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_DataStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataStream)
		this->_Inst_DataStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_DataStream->updateHandle(hOutResult);
	return this->_Inst_DataStream;
}

SB_INLINE void TElMessagePart::set_DataStream(TStream &Value)
{
	SBCheckError(TElMessagePart_set_DataStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePart::set_DataStream(TStream *Value)
{
	SBCheckError(TElMessagePart_set_DataStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElMessagePart::get_DataSize()
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_get_DataSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessagePart::set_DataSize(int32_t Value)
{
	SBCheckError(TElMessagePart_set_DataSize(_Handle, Value));
}

TElMessageParsingOptions TElMessagePart::get_Options()
{
	TElMessageParsingOptionsRaw OutResultRaw = 0;
	SBCheckError(TElMessagePart_get_Options(_Handle, &OutResultRaw));
	return (TElMessageParsingOptions)OutResultRaw;
}

SB_INLINE void TElMessagePart::set_Options(TElMessageParsingOptions Value)
{
	SBCheckError(TElMessagePart_set_Options(_Handle, (TElMessageParsingOptionsRaw)Value));
}

bool TElMessagePart::get_DisposeStream()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_get_DisposeStream(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePart::set_DisposeStream(bool Value)
{
	SBCheckError(TElMessagePart_set_DisposeStream(_Handle, (int8_t)Value));
}

bool TElMessagePart::get_DisposeDataStream()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_get_DisposeDataStream(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessagePart::set_DisposeDataStream(bool Value)
{
	SBCheckError(TElMessagePart_set_DisposeDataStream(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELMESSAGEHEADER
TElMessageHeader* TElMessagePart::get_Header()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_Header(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Header)
		this->_Inst_Header = new TElMessageHeader(hOutResult, ohFalse);
	else
		this->_Inst_Header->updateHandle(hOutResult);
	return this->_Inst_Header;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */

TElMessagePart* TElMessagePart::get_Parent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_Parent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parent)
		this->_Inst_Parent = new TElMessagePart(hOutResult, ohFalse);
	else
		this->_Inst_Parent->updateHandle(hOutResult);
	return this->_Inst_Parent;
}

#ifdef SB_USE_CLASS_TELMESSAGE
TElMessage* TElMessagePart::get_ParentMessage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_ParentMessage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ParentMessage)
		this->_Inst_ParentMessage = new TElMessage(hOutResult, ohFalse);
	else
		this->_Inst_ParentMessage->updateHandle(hOutResult);
	return this->_Inst_ParentMessage;
}
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
TElMessageHeaderField* TElMessagePart::get_HeaderFields(const sb_u16string &wsFieldName)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_HeaderFields(_Handle, wsFieldName.data(), (int32_t)wsFieldName.length(), &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderFields)
		this->_Inst_HeaderFields = new TElMessageHeaderField(hOutResult, ohFalse);
	else
		this->_Inst_HeaderFields->updateHandle(hOutResult);
	return this->_Inst_HeaderFields;
}

#ifdef SB_U16STRING_USED
TElMessageHeaderField* TElMessagePart::get_HeaderFields(const std::wstring &wsFieldName)
{
	std::string u16wsFieldName;
	sb_to_u16string(wsFieldName, u16wsFieldName);
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_HeaderFields(_Handle, reinterpret_cast<const sb_char16_t*>(u16wsFieldName.data()), (int32_t)u16wsFieldName.length() >> 1, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderFields)
		this->_Inst_HeaderFields = new TElMessageHeaderField(hOutResult, ohFalse);
	else
		this->_Inst_HeaderFields->updateHandle(hOutResult);
	return this->_Inst_HeaderFields;
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
TElMessageHeaderField* TElMessagePart::get_HeaderContentTypeField()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_HeaderContentTypeField(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderContentTypeField)
		this->_Inst_HeaderContentTypeField = new TElMessageHeaderField(hOutResult, ohFalse);
	else
		this->_Inst_HeaderContentTypeField->updateHandle(hOutResult);
	return this->_Inst_HeaderContentTypeField;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
TElMessageHeaderField* TElMessagePart::get_HeaderContentDispositionField()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_HeaderContentDispositionField(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderContentDispositionField)
		this->_Inst_HeaderContentDispositionField = new TElMessageHeaderField(hOutResult, ohFalse);
	else
		this->_Inst_HeaderContentDispositionField->updateHandle(hOutResult);
	return this->_Inst_HeaderContentDispositionField;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
TElMessageHeaderField* TElMessagePart::get_HeaderContentTransferEncodingField()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_HeaderContentTransferEncodingField(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderContentTransferEncodingField)
		this->_Inst_HeaderContentTransferEncodingField = new TElMessageHeaderField(hOutResult, ohFalse);
	else
		this->_Inst_HeaderContentTransferEncodingField->updateHandle(hOutResult);
	return this->_Inst_HeaderContentTransferEncodingField;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
TElMessageHeaderField* TElMessagePart::get_HeaderContentLocationField()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_HeaderContentLocationField(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderContentLocationField)
		this->_Inst_HeaderContentLocationField = new TElMessageHeaderField(hOutResult, ohFalse);
	else
		this->_Inst_HeaderContentLocationField->updateHandle(hOutResult);
	return this->_Inst_HeaderContentLocationField;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */

void TElMessagePart::get_ContentType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_ContentType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1987442501, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_ContentType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_ContentType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1987442501, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_ContentSubtype(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_ContentSubtype(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(93865053, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_ContentSubtype(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_ContentSubtype(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(93865053, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_ContentTransferEncoding(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_ContentTransferEncoding(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1327720356, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_ContentTransferEncoding(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_ContentTransferEncoding(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1327720356, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_ContentID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_ContentID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(929221377, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_ContentID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_ContentID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(929221377, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_ContentDisposition(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_ContentDisposition(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1359600624, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_ContentDisposition(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_ContentDisposition(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1359600624, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_ContentDescription(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_ContentDescription(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1890919594, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_ContentDescription(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_ContentDescription(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1890919594, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_FileName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_FileName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1413447473, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_FileName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_FileName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1413447473, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMessagePart::set_FileName(const sb_u16string &Value)
{
	SBCheckError(TElMessagePart_set_FileName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::set_FileName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessagePart_set_FileName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_CharSet(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_CharSet(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1508578017, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_CharSet(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_CharSet(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1508578017, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMessagePart::set_CharSet(const sb_u16string &Value)
{
	SBCheckError(TElMessagePart_set_CharSet(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMessagePart::set_CharSet(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMessagePart_set_CharSet(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_HeaderCharSet(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_HeaderCharSet(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(280464228, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_HeaderCharSet(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_HeaderCharSet(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(280464228, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElMessagePart::get_BodyCharSet(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePart_get_BodyCharSet(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2040351311, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePart::get_BodyCharSet(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePart_get_BodyCharSet(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2040351311, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElMessagePart::get_PartsCount()
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_get_PartsCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessagePart::get_AttachmentsCount()
{
	int32_t OutResult;
	SBCheckError(TElMessagePart_get_AttachmentsCount(_Handle, &OutResult));
	return OutResult;
}

TElMessagePart* TElMessagePart::get_Attachments(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_Attachments(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attachments)
		this->_Inst_Attachments = new TElMessagePart(hOutResult, ohFalse);
	else
		this->_Inst_Attachments->updateHandle(hOutResult);
	return this->_Inst_Attachments;
}

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
TElMessagePartHandler* TElMessagePart::get_MessagePartHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_MessagePartHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MessagePartHandler)
		this->_Inst_MessagePartHandler = new TElMessagePartHandler(hOutResult, ohFalse);
	else
		this->_Inst_MessagePartHandler->updateHandle(hOutResult);
	return this->_Inst_MessagePartHandler;
}

SB_INLINE void TElMessagePart::set_MessagePartHandler(TElMessagePartHandler &Value)
{
	SBCheckError(TElMessagePart_set_MessagePartHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePart::set_MessagePartHandler(TElMessagePartHandler *Value)
{
	SBCheckError(TElMessagePart_set_MessagePartHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
TElMessagePartHandler* TElMessagePart::get_MessageBodyPartHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePart_get_MessageBodyPartHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MessageBodyPartHandler)
		this->_Inst_MessageBodyPartHandler = new TElMessagePartHandler(hOutResult, ohFalse);
	else
		this->_Inst_MessageBodyPartHandler->updateHandle(hOutResult);
	return this->_Inst_MessageBodyPartHandler;
}

SB_INLINE void TElMessagePart::set_MessageBodyPartHandler(TElMessagePartHandler &Value)
{
	SBCheckError(TElMessagePart_set_MessageBodyPartHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePart::set_MessageBodyPartHandler(TElMessagePartHandler *Value)
{
	SBCheckError(TElMessagePart_set_MessageBodyPartHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

bool TElMessagePart::get_IsActivatedMessagePartHandler()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePart_get_IsActivatedMessagePartHandler(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElMessagePart::initInstances()
{
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_DataStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELMESSAGEHEADER
	this->_Inst_Header = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */
	this->_Inst_Parent = NULL;
#ifdef SB_USE_CLASS_TELMESSAGE
	this->_Inst_ParentMessage = NULL;
#endif /* SB_USE_CLASS_TELMESSAGE */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	this->_Inst_HeaderContentTypeField = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	this->_Inst_HeaderContentDispositionField = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	this->_Inst_HeaderContentTransferEncodingField = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	this->_Inst_HeaderContentLocationField = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
	this->_Inst_Attachments = NULL;
#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
	this->_Inst_MessagePartHandler = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */
#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
	this->_Inst_MessageBodyPartHandler = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */
}

TElMessagePart::TElMessagePart(TElMessagePartHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElMessagePart::TElMessagePart() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePart_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELMESSAGE
TElMessagePart::TElMessagePart(TElMessage &AMessage, TElMessagePart &AParent) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePart_Create_1(AMessage.getHandle(), AParent.getHandle(), &_Handle));
}

TElMessagePart::TElMessagePart(TElMessage *AMessage, TElMessagePart *AParent) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePart_Create_1((AMessage != NULL) ? AMessage->getHandle() : SB_NULL_HANDLE, (AParent != NULL) ? AParent->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELMESSAGE */

TElMessagePart::~TElMessagePart()
{
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_DataStream;
	this->_Inst_DataStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELMESSAGEHEADER
	delete this->_Inst_Header;
	this->_Inst_Header = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */
	delete this->_Inst_Parent;
	this->_Inst_Parent = NULL;
#ifdef SB_USE_CLASS_TELMESSAGE
	delete this->_Inst_ParentMessage;
	this->_Inst_ParentMessage = NULL;
#endif /* SB_USE_CLASS_TELMESSAGE */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	delete this->_Inst_HeaderFields;
	this->_Inst_HeaderFields = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	delete this->_Inst_HeaderContentTypeField;
	this->_Inst_HeaderContentTypeField = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	delete this->_Inst_HeaderContentDispositionField;
	this->_Inst_HeaderContentDispositionField = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	delete this->_Inst_HeaderContentTransferEncodingField;
	this->_Inst_HeaderContentTransferEncodingField = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
#ifdef SB_USE_CLASS_TELMESSAGEHEADERFIELD
	delete this->_Inst_HeaderContentLocationField;
	this->_Inst_HeaderContentLocationField = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEHEADERFIELD */
	delete this->_Inst_Attachments;
	this->_Inst_Attachments = NULL;
#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
	delete this->_Inst_MessagePartHandler;
	this->_Inst_MessagePartHandler = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */
#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER
	delete this->_Inst_MessageBodyPartHandler;
	this->_Inst_MessageBodyPartHandler = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */
}
#endif /* SB_USE_CLASS_TELMESSAGEPART */

#ifdef SB_USE_CLASS_TELMULTIPARTLIST

SB_INLINE void TElMultiPartList::Assign(TElMessagePart &Source)
{
	SBCheckError(TElMultiPartList_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElMultiPartList::Assign(TElMessagePart *Source)
{
	SBCheckError(TElMultiPartList_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElMultiPartList::Clear()
{
	SBCheckError(TElMultiPartList_Clear(_Handle));
}

SB_INLINE TElMessagePartHandle TElMultiPartList::Clone()
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMultiPartList_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM
SB_INLINE int32_t TElMultiPartList::Parse(TElMessageHeader &AHeader, TStream &Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElMultiPartList_Parse(_Handle, AHeader.getHandle(), Source.getHandle(), Boundary.data(), (int32_t)Boundary.length(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMultiPartList::Parse(TElMessageHeader *AHeader, TStream *Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElMultiPartList_Parse(_Handle, (AHeader != NULL) ? AHeader->getHandle() : SB_NULL_HANDLE, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Boundary.data(), (int32_t)Boundary.length(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMultiPartList::Assemble(TStream &Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElMultiPartList_Assemble(_Handle, Destination.getHandle(), Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMultiPartList::Assemble(TStream *Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElMultiPartList_Assemble(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE TElMessagePartHandle TElMultiPartList::GetPart(int32_t Index)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMultiPartList_GetPart(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMultiPartList::AddPart(TElMessagePart &Part, bool bMakeCopy, int32_t PartIndex)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMultiPartList_AddPart(_Handle, Part.getHandle(), (int8_t)bMakeCopy, PartIndex, &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandle TElMultiPartList::AddPart(TElMessagePart *Part, bool bMakeCopy, int32_t PartIndex)
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElMultiPartList_AddPart(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, (int8_t)bMakeCopy, PartIndex, &OutResult));
	return OutResult;
}

SB_INLINE void TElMultiPartList::DeletePart(int32_t Index, bool bDestroy)
{
	SBCheckError(TElMultiPartList_DeletePart(_Handle, Index, (int8_t)bDestroy));
}

SB_INLINE void TElMultiPartList::DeletePart(TElMessagePart &Part, bool bDestroy)
{
	SBCheckError(TElMultiPartList_DeletePart_1(_Handle, Part.getHandle(), (int8_t)bDestroy));
}

SB_INLINE void TElMultiPartList::DeletePart(TElMessagePart *Part, bool bDestroy)
{
	SBCheckError(TElMultiPartList_DeletePart_1(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, (int8_t)bDestroy));
}

bool TElMultiPartList::IsText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiPartList_IsText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMultiPartList::IsTextPlain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiPartList_IsTextPlain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMultiPartList::IsMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiPartList_IsMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMultiPartList::IsImage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiPartList_IsImage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMultiPartList::IsAudio()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiPartList_IsAudio(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMultiPartList::IsVideo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiPartList_IsVideo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMultiPartList::IsMultipart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiPartList_IsMultipart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElMultiPartList::GetDataSize(int32_t &Size)
{
	int32_t OutResult;
	SBCheckError(TElMultiPartList_GetDataSize(_Handle, &Size, &OutResult));
	return OutResult;
}

int32_t TElMultiPartList::GetData(sb_u16string &wsData)
{
	int32_t OutResult;
	int32_t szwsData = (int32_t)wsData.length();
	uint32_t _err = TElMultiPartList_GetData(_Handle, (sb_char16_t *)wsData.data(), &szwsData, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		wsData.resize(szwsData);
		SBCheckError(SBGetLastReturnStringW(-1538769126, 1, (sb_char16_t *)wsData.data(), &szwsData));
	}
	else
		SBCheckError(_err);

	wsData.resize(szwsData);
	return OutResult;
}
#ifdef SB_U16STRING_USED
int32_t TElMultiPartList::GetData(std::wstring &wsData)
{
	int32_t OutResult;
	std::string u16wsData;
	sb_to_u16string(wsData, u16wsData);
	int32_t szwsData = (int32_t)u16wsData.length() >> 1;
	uint32_t _err = TElMultiPartList_GetData(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16wsData.data()), &szwsData, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16wsData.resize(szwsData << 1);
		SBCheckError(SBGetLastReturnStringW(-1538769126, 1, reinterpret_cast<sb_char16_t*>((char*)u16wsData.data()), &szwsData));
	}
	else
		SBCheckError(_err);

	u16wsData.resize(szwsData << 1);
	sb_u16_to_wstring(u16wsData, wsData);
	return OutResult;
}
#endif /* SB_U16STRING_USED */

int32_t TElMultiPartList::GetData(std::vector<uint8_t> &Buffer, int32_t &BufferSize)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElMultiPartList_GetData_1(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &BufferSize, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1777407143, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElMultiPartList::SetData(TStream &Stream, int32_t DataSize, bool bMakeCopy)
{
	SBCheckError(TElMultiPartList_SetData(_Handle, Stream.getHandle(), DataSize, (int8_t)bMakeCopy));
}

SB_INLINE void TElMultiPartList::SetData(TStream *Stream, int32_t DataSize, bool bMakeCopy)
{
	SBCheckError(TElMultiPartList_SetData(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, DataSize, (int8_t)bMakeCopy));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElMultiPartList::SetData(const sb_u16string &wsData)
{
	SBCheckError(TElMultiPartList_SetData_1(_Handle, wsData.data(), (int32_t)wsData.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElMultiPartList::SetData(const std::wstring &wsData)
{
	std::string u16wsData;
	sb_to_u16string(wsData, u16wsData);
	SBCheckError(TElMultiPartList_SetData_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16wsData.data()), (int32_t)u16wsData.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElMultiPartList::SetData(const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	SBCheckError(TElMultiPartList_SetData_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count));
}

void TElMultiPartList::GenerateBoundary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMultiPartList_GenerateBoundary((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1783151521, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElMultiPartList::GenerateBoundary_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMultiPartList_GenerateBoundary_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1783151521, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElMultiPartList::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElMultiPartList_ClassType(&OutResult));
	return OutResult;
}

void TElMultiPartList::get_Boundary(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMultiPartList_get_Boundary(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1587612022, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMultiPartList::get_Boundary(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMultiPartList_get_Boundary(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1587612022, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElMultiPartList::set_Boundary(const sb_u16string &Value)
{
	SBCheckError(TElMultiPartList_set_Boundary(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElMultiPartList::set_Boundary(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElMultiPartList_set_Boundary(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElMultiPartList::TElMultiPartList(TElMultiPartListHandle handle, TElOwnHandle ownHandle) : TElMessagePart(handle, ownHandle)
{
}

TElMultiPartList::TElMultiPartList() : TElMessagePart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultiPartList_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELMESSAGE
TElMultiPartList::TElMultiPartList(TElMessage &AMessage, TElMessagePart &AParent) : TElMessagePart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultiPartList_Create_1(AMessage.getHandle(), AParent.getHandle(), &_Handle));
}

TElMultiPartList::TElMultiPartList(TElMessage *AMessage, TElMessagePart *AParent) : TElMessagePart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultiPartList_Create_1((AMessage != NULL) ? AMessage->getHandle() : SB_NULL_HANDLE, (AParent != NULL) ? AParent->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELMESSAGE */

#endif /* SB_USE_CLASS_TELMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELPLAINTEXTPART

SB_INLINE TElMessagePartHandle TElPlainTextPart::Clone()
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElPlainTextPart_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPlainTextPart::Assign(TElMessagePart &Source)
{
	SBCheckError(TElPlainTextPart_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPlainTextPart::Assign(TElMessagePart *Source)
{
	SBCheckError(TElPlainTextPart_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM
SB_INLINE int32_t TElPlainTextPart::Parse(TElMessageHeader &Header, TStream &Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElPlainTextPart_Parse(_Handle, Header.getHandle(), Source.getHandle(), Boundary.data(), (int32_t)Boundary.length(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPlainTextPart::Parse(TElMessageHeader *Header, TStream *Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElPlainTextPart_Parse(_Handle, (Header != NULL) ? Header->getHandle() : SB_NULL_HANDLE, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Boundary.data(), (int32_t)Boundary.length(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElPlainTextPart::Assemble(TStream &Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElPlainTextPart_Assemble(_Handle, Destination.getHandle(), Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPlainTextPart::Assemble(TStream *Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElPlainTextPart_Assemble(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

int32_t TElPlainTextPart::GetText(sb_u16string &AText)
{
	int32_t OutResult;
	int32_t szAText = (int32_t)AText.length();
	uint32_t _err = TElPlainTextPart_GetText(_Handle, (sb_char16_t *)AText.data(), &szAText, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		AText.resize(szAText);
		SBCheckError(SBGetLastReturnStringW(1939574891, 1, (sb_char16_t *)AText.data(), &szAText));
	}
	else
		SBCheckError(_err);

	AText.resize(szAText);
	return OutResult;
}
#ifdef SB_U16STRING_USED
int32_t TElPlainTextPart::GetText(std::wstring &AText)
{
	int32_t OutResult;
	std::string u16AText;
	sb_to_u16string(AText, u16AText);
	int32_t szAText = (int32_t)u16AText.length() >> 1;
	uint32_t _err = TElPlainTextPart_GetText(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16AText.data()), &szAText, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16AText.resize(szAText << 1);
		SBCheckError(SBGetLastReturnStringW(1939574891, 1, reinterpret_cast<sb_char16_t*>((char*)u16AText.data()), &szAText));
	}
	else
		SBCheckError(_err);

	u16AText.resize(szAText << 1);
	sb_u16_to_wstring(u16AText, AText);
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElPlainTextPart::SetText(const sb_u16string &AText)
{
	SBCheckError(TElPlainTextPart_SetText(_Handle, AText.data(), (int32_t)AText.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElPlainTextPart::SetText(const std::wstring &AText)
{
	std::string u16AText;
	sb_to_u16string(AText, u16AText);
	SBCheckError(TElPlainTextPart_SetText(_Handle, reinterpret_cast<const sb_char16_t*>(u16AText.data()), (int32_t)u16AText.length() >> 1));
}
#endif /* SB_U16STRING_USED */

bool TElPlainTextPart::IsText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPlainTextPart_IsText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPlainTextPart::IsTextPlain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPlainTextPart_IsTextPlain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPlainTextPart::IsMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPlainTextPart_IsMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPlainTextPart::IsImage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPlainTextPart_IsImage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPlainTextPart::IsAudio()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPlainTextPart_IsAudio(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPlainTextPart::IsVideo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPlainTextPart_IsVideo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPlainTextPart::IsMultipart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPlainTextPart_IsMultipart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPlainTextPart::IsAttachment()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPlainTextPart_IsAttachment(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPlainTextPart::GetDataSize(int32_t &Size)
{
	int32_t OutResult;
	SBCheckError(TElPlainTextPart_GetDataSize(_Handle, &Size, &OutResult));
	return OutResult;
}

int32_t TElPlainTextPart::GetData(sb_u16string &wsData)
{
	int32_t OutResult;
	int32_t szwsData = (int32_t)wsData.length();
	uint32_t _err = TElPlainTextPart_GetData(_Handle, (sb_char16_t *)wsData.data(), &szwsData, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		wsData.resize(szwsData);
		SBCheckError(SBGetLastReturnStringW(733955808, 1, (sb_char16_t *)wsData.data(), &szwsData));
	}
	else
		SBCheckError(_err);

	wsData.resize(szwsData);
	return OutResult;
}
#ifdef SB_U16STRING_USED
int32_t TElPlainTextPart::GetData(std::wstring &wsData)
{
	int32_t OutResult;
	std::string u16wsData;
	sb_to_u16string(wsData, u16wsData);
	int32_t szwsData = (int32_t)u16wsData.length() >> 1;
	uint32_t _err = TElPlainTextPart_GetData(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16wsData.data()), &szwsData, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16wsData.resize(szwsData << 1);
		SBCheckError(SBGetLastReturnStringW(733955808, 1, reinterpret_cast<sb_char16_t*>((char*)u16wsData.data()), &szwsData));
	}
	else
		SBCheckError(_err);

	u16wsData.resize(szwsData << 1);
	sb_u16_to_wstring(u16wsData, wsData);
	return OutResult;
}
#endif /* SB_U16STRING_USED */

int32_t TElPlainTextPart::GetData(std::vector<uint8_t> &Buffer, int32_t &BufferSize)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElPlainTextPart_GetData_1(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &BufferSize, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-889452775, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPlainTextPart::SetData(TStream &Stream, int32_t DataSize, bool bMakeCopy)
{
	SBCheckError(TElPlainTextPart_SetData(_Handle, Stream.getHandle(), DataSize, (int8_t)bMakeCopy));
}

SB_INLINE void TElPlainTextPart::SetData(TStream *Stream, int32_t DataSize, bool bMakeCopy)
{
	SBCheckError(TElPlainTextPart_SetData(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, DataSize, (int8_t)bMakeCopy));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPlainTextPart::SetData(const sb_u16string &wsData)
{
	SBCheckError(TElPlainTextPart_SetData_1(_Handle, wsData.data(), (int32_t)wsData.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElPlainTextPart::SetData(const std::wstring &wsData)
{
	std::string u16wsData;
	sb_to_u16string(wsData, u16wsData);
	SBCheckError(TElPlainTextPart_SetData_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16wsData.data()), (int32_t)u16wsData.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElPlainTextPart::SetData(const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	SBCheckError(TElPlainTextPart_SetData_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count));
}

SB_INLINE TClassHandle TElPlainTextPart::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPlainTextPart_ClassType(&OutResult));
	return OutResult;
}

TElPlainTextPart::TElPlainTextPart(TElPlainTextPartHandle handle, TElOwnHandle ownHandle) : TElMultiPartList(handle, ownHandle)
{
}

TElPlainTextPart::TElPlainTextPart() : TElMultiPartList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPlainTextPart_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELMESSAGE
TElPlainTextPart::TElPlainTextPart(TElMessage &AMessage, TElMessagePart &AParent) : TElMultiPartList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPlainTextPart_Create_1(AMessage.getHandle(), AParent.getHandle(), &_Handle));
}

TElPlainTextPart::TElPlainTextPart(TElMessage *AMessage, TElMessagePart *AParent) : TElMultiPartList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPlainTextPart_Create_1((AMessage != NULL) ? AMessage->getHandle() : SB_NULL_HANDLE, (AParent != NULL) ? AParent->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELMESSAGE */

#endif /* SB_USE_CLASS_TELPLAINTEXTPART */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLER

SB_INLINE int32_t TElMessagePartHandler::Decode(bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandler_Decode(_Handle, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}

void TElMessagePartHandler::GetDescription(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandler_GetDescription((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-201385311, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandler::GetDescription(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandler_GetDescription(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-201385311, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElMessagePartHandler::GetDescription_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandler_GetDescription_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-201385311, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElMessagePartHandler::GetDescription_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandler_GetDescription_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-201385311, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE TClassHandle TElMessagePartHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElMessagePartHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELMESSAGEPART
TElMessagePart* TElMessagePartHandler::get_DecodedPart()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessagePartHandler_get_DecodedPart(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DecodedPart)
		this->_Inst_DecodedPart = new TElMessagePart(hOutResult, ohFalse);
	else
		this->_Inst_DecodedPart->updateHandle(hOutResult);
	return this->_Inst_DecodedPart;
}

SB_INLINE void TElMessagePartHandler::set_DecodedPart(TElMessagePart &Value)
{
	SBCheckError(TElMessagePartHandler_set_DecodedPart(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessagePartHandler::set_DecodedPart(TElMessagePart *Value)
{
	SBCheckError(TElMessagePartHandler_set_DecodedPart(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMESSAGEPART */

bool TElMessagePartHandler::get_IsDecoderActivated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandler_get_IsDecoderActivated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessagePartHandler::get_IsError()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessagePartHandler_get_IsError(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElMessagePartHandler::get_ErrorText(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessagePartHandler_get_ErrorText(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-47984251, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElMessagePartHandler::get_ErrorText(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElMessagePartHandler_get_ErrorText(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-47984251, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElMessagePartHandler::get_ResultCode()
{
	int32_t OutResult;
	SBCheckError(TElMessagePartHandler_get_ResultCode(_Handle, &OutResult));
	return OutResult;
}

void TElMessagePartHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELMESSAGEPART
	this->_Inst_DecodedPart = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPART */
}

TElMessagePartHandler::TElMessagePartHandler(TElMessagePartHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElMessagePartHandler::TElMessagePartHandler(TObject &aParams) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePartHandler_Create(aParams.getHandle(), &_Handle));
}

TElMessagePartHandler::TElMessagePartHandler(TObject *aParams) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessagePartHandler_Create((aParams != NULL) ? aParams->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessagePartHandler::~TElMessagePartHandler()
{
#ifdef SB_USE_CLASS_TELMESSAGEPART
	delete this->_Inst_DecodedPart;
	this->_Inst_DecodedPart = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEPART */
}
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLER */

#ifdef SB_USE_CLASS_TELCONVERTER

#ifdef SB_USE_CLASS_TSTREAM
void TElConverter::Convert(TStream &Source, TStream &Dest, TPlConvertOptions Options, int32_t MaxChars, bool &OutResult)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElConverter_Convert(_Handle, Source.getHandle(), Dest.getHandle(), (TPlConvertOptionsRaw)Options, MaxChars, &OutResultRaw));
	OutResult = (OutResultRaw != 0);
}

void TElConverter::Convert(TStream *Source, TStream *Dest, TPlConvertOptions Options, int32_t MaxChars, bool &OutResult)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElConverter_Convert(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, (TPlConvertOptionsRaw)Options, MaxChars, &OutResultRaw));
	OutResult = (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElConverter::Convert(const std::string &Source, sb_u16string &Dest, TPlConvertOptions Options)
{
	int32_t szDest = (int32_t)Dest.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElConverter_Convert_1(_Handle, Source.data(), (int32_t)Source.length(), (sb_char16_t *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringW(-1884741074, 2, (sb_char16_t *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElConverter::Convert(const std::string &Source, std::wstring &Dest, TPlConvertOptions Options)
{
	std::string u16Dest;
	sb_to_u16string(Dest, u16Dest);
	int32_t szDest = (int32_t)u16Dest.length() >> 1;
	int8_t OutResultRaw = 0;
	uint32_t _err = TElConverter_Convert_1(_Handle, Source.data(), (int32_t)Source.length(), reinterpret_cast<sb_char16_t*>((char*)u16Dest.data()), &szDest, (TPlConvertOptionsRaw)Options, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Dest.resize(szDest << 1);
		SBCheckError(SBGetLastReturnStringW(-1884741074, 2, reinterpret_cast<sb_char16_t*>((char*)u16Dest.data()), &szDest));
	}
	else
		SBCheckError(_err);

	u16Dest.resize(szDest << 1);
	sb_u16_to_wstring(u16Dest, Dest);
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

TElConverter::TElConverter(TElConverterHandle handle, TElOwnHandle ownHandle) : TPlConverter(handle, ownHandle)
{
}

TElConverter::TElConverter() : TPlConverter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElConverter_Create(&_Handle));
}

TElConverter::TElConverter(const std::string &SrcCharset, const std::string &DstCharset) : TPlConverter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElConverter_Create_1(SrcCharset.data(), (int32_t)SrcCharset.length(), DstCharset.data(), (int32_t)DstCharset.length(), &_Handle));
}

#ifdef SB_USE_CLASS_IPLCHARSET
TElConverter::TElConverter(IPlCharsetHandle SrcCharset, IPlCharsetHandle DstCharset) : TPlConverter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElConverter_Create_2(SrcCharset, DstCharset, &_Handle));
}
#endif /* SB_USE_CLASS_IPLCHARSET */

#endif /* SB_USE_CLASS_TELCONVERTER */

#ifdef SB_USE_CLASS_TELREGISTEREDMESSAGEPARTHANDLERS

SB_INLINE void TElRegisteredMessagePartHandlers::AddHandler(TElMessagePartHandlerClassHandle hc)
{
	SBCheckError(TElRegisteredMessagePartHandlers_AddHandler(_Handle, hc));
}

SB_INLINE int32_t TElRegisteredMessagePartHandlers::GetHandlersCount()
{
	int32_t OutResult;
	SBCheckError(TElRegisteredMessagePartHandlers_GetHandlersCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElMessagePartHandlerClassHandle TElRegisteredMessagePartHandlers::GetHandlerClass(int32_t Index)
{
	TElMessagePartHandlerClassHandle OutResult;
	SBCheckError(TElRegisteredMessagePartHandlers_GetHandlerClass(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElRegisteredMessagePartHandlers::RemoveHandler(TElMessagePartHandlerClassHandle hc)
{
	SBCheckError(TElRegisteredMessagePartHandlers_RemoveHandler(_Handle, hc));
}

TElRegisteredMessagePartHandlers::TElRegisteredMessagePartHandlers(TElRegisteredMessagePartHandlersHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElRegisteredMessagePartHandlers::TElRegisteredMessagePartHandlers() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRegisteredMessagePartHandlers_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELREGISTEREDMESSAGEPARTHANDLERS */

#ifdef SB_USE_CLASS_TELXMLPART

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElXmlPart::Assemble(TStream &Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElXmlPart_Assemble(_Handle, Destination.getHandle(), Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXmlPart::Assemble(TStream *Destination, const std::string &Charset, TElHeaderEncoding HeaderEncoding, const std::string &BodyEncoding, const std::string &AttachEncoding, bool bAssembleSource)
{
	int32_t OutResult;
	SBCheckError(TElXmlPart_Assemble(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE, Charset.data(), (int32_t)Charset.length(), (TElHeaderEncodingRaw)HeaderEncoding, BodyEncoding.data(), (int32_t)BodyEncoding.length(), AttachEncoding.data(), (int32_t)AttachEncoding.length(), (int8_t)bAssembleSource, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE TElMessagePartHandle TElXmlPart::Clone()
{
	TElMessagePartHandle OutResult;
	SBCheckError(TElXmlPart_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElXmlPart::IsText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXmlPart_IsText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXmlPart::IsTextPlain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXmlPart_IsTextPlain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXmlPart::IsTextHtml()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXmlPart_IsTextHtml(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXmlPart::IsMessage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXmlPart_IsMessage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXmlPart::IsImage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXmlPart_IsImage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXmlPart::IsAudio()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXmlPart_IsAudio(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXmlPart::IsVideo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXmlPart_IsVideo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXmlPart::IsMultipart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXmlPart_IsMultipart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM
SB_INLINE int32_t TElXmlPart::Parse(TElMessageHeader &Header, TStream &Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElXmlPart_Parse(_Handle, Header.getHandle(), Source.getHandle(), Boundary.data(), (int32_t)Boundary.length(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXmlPart::Parse(TElMessageHeader *Header, TStream *Source, const std::string &Boundary, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions AOptions, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool bActivatePartHandlers)
{
	int32_t OutResult;
	SBCheckError(TElXmlPart_Parse(_Handle, (Header != NULL) ? Header->getHandle() : SB_NULL_HANDLE, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Boundary.data(), (int32_t)Boundary.length(), HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)AOptions, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)bActivatePartHandlers, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELMESSAGEHEADER_AND_TSTREAM */

SB_INLINE TClassHandle TElXmlPart::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXmlPart_ClassType(&OutResult));
	return OutResult;
}

TElXmlPart::TElXmlPart(TElXmlPartHandle handle, TElOwnHandle ownHandle) : TElMessagePart(handle, ownHandle)
{
}

TElXmlPart::TElXmlPart() : TElMessagePart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXmlPart_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELMESSAGE
TElXmlPart::TElXmlPart(TElMessage &AMessage, TElMessagePart &AParent) : TElMessagePart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXmlPart_Create_1(AMessage.getHandle(), AParent.getHandle(), &_Handle));
}

TElXmlPart::TElXmlPart(TElMessage *AMessage, TElMessagePart *AParent) : TElMessagePart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXmlPart_Create_1((AMessage != NULL) ? AMessage->getHandle() : SB_NULL_HANDLE, (AParent != NULL) ? AParent->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELMESSAGE */

#endif /* SB_USE_CLASS_TELXMLPART */

#ifdef SB_USE_GLOBAL_PROCS_MIME

bool WideSameText(const sb_u16string &S1, const sb_u16string &S2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIME_WideSameText(S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool WideSameText(const std::wstring &S1, const std::wstring &S2)
{
	std::string u16S1;
	sb_to_u16string(S1, u16S1);
	std::string u16S2;
	sb_to_u16string(S2, u16S2);
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIME_WideSameText(reinterpret_cast<const sb_char16_t*>(u16S1.data()), (int32_t)u16S1.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16S2.data()), (int32_t)u16S2.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TSTREAM
void GetHeaderFromStream(const TStream &Source, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBMIME_GetHeaderFromStream(Source.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1710027555, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetHeaderFromStream(const TStream *Source, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBMIME_GetHeaderFromStream((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1710027555, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

void DeleteQuotationMarks(sb_u16string &Str)
{
	int32_t szStr = (int32_t)Str.length();
	uint32_t _err = SBMIME_DeleteQuotationMarks((sb_char16_t *)Str.data(), &szStr);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Str.resize(szStr);
		SBCheckError(SBGetLastReturnStringW(-1489951238, 0, (sb_char16_t *)Str.data(), &szStr));
	}
	else
		SBCheckError(_err);

	Str.resize(szStr);
}
#ifdef SB_U16STRING_USED
void DeleteQuotationMarks(std::wstring &Str)
{
	std::string u16Str;
	sb_to_u16string(Str, u16Str);
	int32_t szStr = (int32_t)u16Str.length() >> 1;
	uint32_t _err = SBMIME_DeleteQuotationMarks(reinterpret_cast<sb_char16_t*>((char*)u16Str.data()), &szStr);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Str.resize(szStr << 1);
		SBCheckError(SBGetLastReturnStringW(-1489951238, 0, reinterpret_cast<sb_char16_t*>((char*)u16Str.data()), &szStr));
	}
	else
		SBCheckError(_err);

	u16Str.resize(szStr << 1);
	sb_u16_to_wstring(u16Str, Str);
}
#endif /* SB_U16STRING_USED */

void SetInQuotationMarks(sb_u16string &Str)
{
	int32_t szStr = (int32_t)Str.length();
	uint32_t _err = SBMIME_SetInQuotationMarks((sb_char16_t *)Str.data(), &szStr);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Str.resize(szStr);
		SBCheckError(SBGetLastReturnStringW(483005085, 0, (sb_char16_t *)Str.data(), &szStr));
	}
	else
		SBCheckError(_err);

	Str.resize(szStr);
}
#ifdef SB_U16STRING_USED
void SetInQuotationMarks(std::wstring &Str)
{
	std::string u16Str;
	sb_to_u16string(Str, u16Str);
	int32_t szStr = (int32_t)u16Str.length() >> 1;
	uint32_t _err = SBMIME_SetInQuotationMarks(reinterpret_cast<sb_char16_t*>((char*)u16Str.data()), &szStr);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Str.resize(szStr << 1);
		SBCheckError(SBGetLastReturnStringW(483005085, 0, reinterpret_cast<sb_char16_t*>((char*)u16Str.data()), &szStr));
	}
	else
		SBCheckError(_err);

	u16Str.resize(szStr << 1);
	sb_u16_to_wstring(u16Str, Str);
}
#endif /* SB_U16STRING_USED */

bool IsAddressListField(const sb_u16string &FieldName, bool CheckPartial)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIME_IsAddressListField(FieldName.data(), (int32_t)FieldName.length(), (int8_t)CheckPartial, &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool IsAddressListField(const std::wstring &FieldName, bool CheckPartial)
{
	std::string u16FieldName;
	sb_to_u16string(FieldName, u16FieldName);
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIME_IsAddressListField(reinterpret_cast<const sb_char16_t*>(u16FieldName.data()), (int32_t)u16FieldName.length() >> 1, (int8_t)CheckPartial, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool IsMessageScopeField(const sb_u16string &FieldName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIME_IsMessageScopeField(FieldName.data(), (int32_t)FieldName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool IsMessageScopeField(const std::wstring &FieldName)
{
	std::string u16FieldName;
	sb_to_u16string(FieldName, u16FieldName);
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIME_IsMessageScopeField(reinterpret_cast<const sb_char16_t*>(u16FieldName.data()), (int32_t)u16FieldName.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool IsUnstructuredField(const sb_u16string &FieldName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIME_IsUnstructuredField(FieldName.data(), (int32_t)FieldName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool IsUnstructuredField(const std::wstring &FieldName)
{
	std::string u16FieldName;
	sb_to_u16string(FieldName, u16FieldName);
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIME_IsUnstructuredField(reinterpret_cast<const sb_char16_t*>(u16FieldName.data()), (int32_t)u16FieldName.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void RegisterUnstructuredField(const sb_u16string &FieldName)
{
	SBCheckError(SBMIME_RegisterUnstructuredField(FieldName.data(), (int32_t)FieldName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void RegisterUnstructuredField(const std::wstring &FieldName)
{
	std::string u16FieldName;
	sb_to_u16string(FieldName, u16FieldName);
	SBCheckError(SBMIME_RegisterUnstructuredField(reinterpret_cast<const sb_char16_t*>(u16FieldName.data()), (int32_t)u16FieldName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void AddRegisteredMIMEMessagePartHandler(TElMessagePartHandlerClassHandle Handler)
{
	SBCheckError(SBMIME_AddRegisteredMIMEMessagePartHandler(Handler));
}

SB_INLINE void RemoveRegisteredMIMEMessagePartHandler(TElMessagePartHandlerClassHandle Handler)
{
	SBCheckError(SBMIME_RemoveRegisteredMIMEMessagePartHandler(Handler));
}

#endif /* SB_USE_GLOBAL_PROCS_MIME */

};	/* namespace SecureBlackbox */

