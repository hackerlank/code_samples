#include "sbxmlsoapclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLSOAPCLIENT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLSOAPClient::ProcessReply(int32_t AHTTPStatusCode, TStream &AResponseStream)
{
	SBCheckError(TElXMLSOAPClient_ProcessReply(_Handle, AHTTPStatusCode, AResponseStream.getHandle()));
}

SB_INLINE void TElXMLSOAPClient::ProcessReply(int32_t AHTTPStatusCode, TStream *AResponseStream)
{
	SBCheckError(TElXMLSOAPClient_ProcessReply(_Handle, AHTTPStatusCode, (AResponseStream != NULL) ? AResponseStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElXMLSOAPClient::Clear()
{
	SBCheckError(TElXMLSOAPClient_Clear(_Handle));
}

SB_INLINE void TElXMLSOAPClient::ClearResponse()
{
	SBCheckError(TElXMLSOAPClient_ClearResponse(_Handle));
}

SB_INLINE void TElXMLSOAPClient::GenerateMessage()
{
	SBCheckError(TElXMLSOAPClient_GenerateMessage(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE void TElXMLSOAPClient::LoadMessage(TElXMLDOMDocument &ADocument)
{
	SBCheckError(TElXMLSOAPClient_LoadMessage(_Handle, ADocument.getHandle()));
}

SB_INLINE void TElXMLSOAPClient::LoadMessage(TElXMLDOMDocument *ADocument)
{
	SBCheckError(TElXMLSOAPClient_LoadMessage(_Handle, (ADocument != NULL) ? ADocument->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLSOAPClient::LoadMessage(TStream &AStream)
{
	SBCheckError(TElXMLSOAPClient_LoadMessage_1(_Handle, AStream.getHandle()));
}

SB_INLINE void TElXMLSOAPClient::LoadMessage(TStream *AStream)
{
	SBCheckError(TElXMLSOAPClient_LoadMessage_1(_Handle, (AStream != NULL) ? AStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElXMLSOAPClient::LoadMessage(const std::string &AFileName)
{
	SBCheckError(TElXMLSOAPClient_LoadMessage_2(_Handle, AFileName.data(), (int32_t)AFileName.length()));
}

SB_INLINE void TElXMLSOAPClient::SendMessage()
{
	SBCheckError(TElXMLSOAPClient_SendMessage(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLSOAPClient::SendMessageWithAttachment(const std::string &PrimaryMessageID, const std::string &ContentID, const std::string &ContentType, TStream &ContentStream, bool CloseStream)
{
	SBCheckError(TElXMLSOAPClient_SendMessageWithAttachment(_Handle, PrimaryMessageID.data(), (int32_t)PrimaryMessageID.length(), ContentID.data(), (int32_t)ContentID.length(), ContentType.data(), (int32_t)ContentType.length(), ContentStream.getHandle(), (int8_t)CloseStream));
}

SB_INLINE void TElXMLSOAPClient::SendMessageWithAttachment(const std::string &PrimaryMessageID, const std::string &ContentID, const std::string &ContentType, TStream *ContentStream, bool CloseStream)
{
	SBCheckError(TElXMLSOAPClient_SendMessageWithAttachment(_Handle, PrimaryMessageID.data(), (int32_t)PrimaryMessageID.length(), ContentID.data(), (int32_t)ContentID.length(), ContentType.data(), (int32_t)ContentType.length(), (ContentStream != NULL) ? ContentStream->getHandle() : SB_NULL_HANDLE, (int8_t)CloseStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
SB_INLINE void TElXMLSOAPClient::SendMessageWithAttachments(const std::string &PrimaryMessageID, TElHTTPMultipartList &PartsList)
{
	SBCheckError(TElXMLSOAPClient_SendMessageWithAttachments(_Handle, PrimaryMessageID.data(), (int32_t)PrimaryMessageID.length(), PartsList.getHandle()));
}

SB_INLINE void TElXMLSOAPClient::SendMessageWithAttachments(const std::string &PrimaryMessageID, TElHTTPMultipartList *PartsList)
{
	SBCheckError(TElXMLSOAPClient_SendMessageWithAttachments(_Handle, PrimaryMessageID.data(), (int32_t)PrimaryMessageID.length(), (PartsList != NULL) ? PartsList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
SB_INLINE void TElXMLSOAPClient::SendMessageWithAttachments(const std::string &PrimaryMessageID, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList &PartsList)
{
	SBCheckError(TElXMLSOAPClient_SendMessageWithAttachments_1(_Handle, PrimaryMessageID.data(), (int32_t)PrimaryMessageID.length(), RelatedStartInfo.data(), (int32_t)RelatedStartInfo.length(), RelatedType.data(), (int32_t)RelatedType.length(), PartsList.getHandle()));
}

SB_INLINE void TElXMLSOAPClient::SendMessageWithAttachments(const std::string &PrimaryMessageID, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList *PartsList)
{
	SBCheckError(TElXMLSOAPClient_SendMessageWithAttachments_1(_Handle, PrimaryMessageID.data(), (int32_t)PrimaryMessageID.length(), RelatedStartInfo.data(), (int32_t)RelatedStartInfo.length(), RelatedType.data(), (int32_t)RelatedType.length(), (PartsList != NULL) ? PartsList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELXMLSOAPBASEPARAMETER
SB_INLINE int32_t TElXMLSOAPClient::AddParameter(TElXMLSOAPBaseParameter &Param)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddParameter(_Handle, Param.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPClient::AddParameter(TElXMLSOAPBaseParameter *Param)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddParameter(_Handle, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLSOAPBASEPARAMETER */

SB_INLINE int32_t TElXMLSOAPClient::AddStringParameter(const sb_u16string &ParamName, const sb_u16string &Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddStringParameter(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value.data(), (int32_t)Value.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddStringParameter(const std::wstring &ParamName, const std::wstring &Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_AddStringParameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddStringParameter(const sb_u16string &ParamName, const sb_u16string &Value, bool NormalizeNEL)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddStringParameter_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value.data(), (int32_t)Value.length(), (int8_t)NormalizeNEL, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddStringParameter(const std::wstring &ParamName, const std::wstring &Value, bool NormalizeNEL)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_AddStringParameter_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (int8_t)NormalizeNEL, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddStringParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const sb_u16string &Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddStringParameter_2(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value.data(), (int32_t)Value.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddStringParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::wstring &Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_AddStringParameter_2(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddStringParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const sb_u16string &Value, bool NormalizeNEL)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddStringParameter_3(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value.data(), (int32_t)Value.length(), (int8_t)NormalizeNEL, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddStringParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::wstring &Value, bool NormalizeNEL)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_AddStringParameter_3(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (int8_t)NormalizeNEL, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddBooleanParameter(const sb_u16string &ParamName, bool Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddBooleanParameter(_Handle, ParamName.data(), (int32_t)ParamName.length(), (int8_t)Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddBooleanParameter(const std::wstring &ParamName, bool Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPClient_AddBooleanParameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, (int8_t)Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddBooleanParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, bool Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddBooleanParameter_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), (int8_t)Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddBooleanParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, bool Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPClient_AddBooleanParameter_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, (int8_t)Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddIntegerParameter(const sb_u16string &ParamName, int32_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddIntegerParameter(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddIntegerParameter(const std::wstring &ParamName, int32_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPClient_AddIntegerParameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddIntegerParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int32_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddIntegerParameter_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddIntegerParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int32_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPClient_AddIntegerParameter_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddInt64Parameter(const sb_u16string &ParamName, int64_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddInt64Parameter(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddInt64Parameter(const std::wstring &ParamName, int64_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPClient_AddInt64Parameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddInt64Parameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int64_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddInt64Parameter_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddInt64Parameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int64_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPClient_AddInt64Parameter_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddDoubleParameter(const sb_u16string &ParamName, double Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddDoubleParameter(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddDoubleParameter(const std::wstring &ParamName, double Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPClient_AddDoubleParameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddDoubleParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, double Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddDoubleParameter_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddDoubleParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, double Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPClient_AddDoubleParameter_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddDateTimeParameter(const sb_u16string &ParamName, int64_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddDateTimeParameter(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddDateTimeParameter(const std::wstring &ParamName, int64_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPClient_AddDateTimeParameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddDateTimeParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int64_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddDateTimeParameter_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddDateTimeParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int64_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPClient_AddDateTimeParameter_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddBase64BinaryParameter(const sb_u16string &ParamName, const std::vector<uint8_t> &Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddBase64BinaryParameter(_Handle, ParamName.data(), (int32_t)ParamName.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddBase64BinaryParameter(const std::wstring &ParamName, const std::vector<uint8_t> &Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPClient_AddBase64BinaryParameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddBase64BinaryParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const std::vector<uint8_t> &Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddBase64BinaryParameter_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddBase64BinaryParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::vector<uint8_t> &Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPClient_AddBase64BinaryParameter_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddCompoundParameter(const sb_u16string &ParamName)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddCompoundParameter(_Handle, ParamName.data(), (int32_t)ParamName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddCompoundParameter(const std::wstring &ParamName)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPClient_AddCompoundParameter(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPClient::AddCompoundParameter(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_AddCompoundParameter_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPClient::AddCompoundParameter(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPClient_AddCompoundParameter_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLSOAPClient::DeleteParameter(int32_t Index)
{
	SBCheckError(TElXMLSOAPClient_DeleteParameter(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLDOMDocument* TElXMLSOAPClient::get_XMLDocument()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_XMLDocument(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLDocument)
		this->_Inst_XMLDocument = new TElXMLDOMDocument(hOutResult, ohFalse);
	else
		this->_Inst_XMLDocument->updateHandle(hOutResult);
	return this->_Inst_XMLDocument;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
TElXMLSOAPMessage* TElXMLSOAPClient::get_SOAPMessage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_SOAPMessage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SOAPMessage)
		this->_Inst_SOAPMessage = new TElXMLSOAPMessage(hOutResult, ohFalse);
	else
		this->_Inst_SOAPMessage->updateHandle(hOutResult);
	return this->_Inst_SOAPMessage;
}
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

TSBXMLSOAPVersion TElXMLSOAPClient::get_SOAPVersion()
{
	TSBXMLSOAPVersionRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPClient_get_SOAPVersion(_Handle, &OutResultRaw));
	return (TSBXMLSOAPVersion)OutResultRaw;
}

SB_INLINE void TElXMLSOAPClient::set_SOAPVersion(TSBXMLSOAPVersion Value)
{
	SBCheckError(TElXMLSOAPClient_set_SOAPVersion(_Handle, (TSBXMLSOAPVersionRaw)Value));
}

void TElXMLSOAPClient::get_SOAPPrefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_SOAPPrefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(486049253, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_SOAPPrefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_SOAPPrefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(486049253, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPClient::set_SOAPPrefix(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPClient_set_SOAPPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPClient::set_SOAPPrefix(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_set_SOAPPrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
TElXMLNamespaceMap* TElXMLSOAPClient::get_MessageNamespaces()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_MessageNamespaces(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MessageNamespaces)
		this->_Inst_MessageNamespaces = new TElXMLNamespaceMap(hOutResult, ohFalse);
	else
		this->_Inst_MessageNamespaces->updateHandle(hOutResult);
	return this->_Inst_MessageNamespaces;
}
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

void TElXMLSOAPClient::get_OperationName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_OperationName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1289608842, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_OperationName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_OperationName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1289608842, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPClient::set_OperationName(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPClient_set_OperationName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPClient::set_OperationName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_set_OperationName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPClient::get_OperationNamespaceURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_OperationNamespaceURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(746178164, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_OperationNamespaceURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_OperationNamespaceURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(746178164, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPClient::set_OperationNamespaceURI(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPClient_set_OperationNamespaceURI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPClient::set_OperationNamespaceURI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_set_OperationNamespaceURI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPClient::get_OperationResponseName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_OperationResponseName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1451354747, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_OperationResponseName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_OperationResponseName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1451354747, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPClient::set_OperationResponseName(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPClient_set_OperationResponseName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPClient::set_OperationResponseName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_set_OperationResponseName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPClient::get_OperationResponseNamespaceURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_OperationResponseNamespaceURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1353519923, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_OperationResponseNamespaceURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_OperationResponseNamespaceURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1353519923, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPClient::set_OperationResponseNamespaceURI(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPClient_set_OperationResponseNamespaceURI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPClient::set_OperationResponseNamespaceURI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPClient_set_OperationResponseNamespaceURI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPClient::get_Encoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_Encoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1048648140, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLSOAPClient::set_Encoding(const std::string &Value)
{
	SBCheckError(TElXMLSOAPClient_set_Encoding(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElXMLSOAPClient::get_SOAPAction(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_SOAPAction(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-930770951, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLSOAPClient::set_SOAPAction(const std::string &Value)
{
	SBCheckError(TElXMLSOAPClient_set_SOAPAction(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
TElXMLSOAPCompoundParameter* TElXMLSOAPClient::get_RootParameter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_RootParameter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RootParameter)
		this->_Inst_RootParameter = new TElXMLSOAPCompoundParameter(hOutResult, ohFalse);
	else
		this->_Inst_RootParameter->updateHandle(hOutResult);
	return this->_Inst_RootParameter;
}
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */

SB_INLINE int32_t TElXMLSOAPClient::get_ParameterCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_get_ParameterCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
TElXMLSOAPCustomParameter* TElXMLSOAPClient::get_Parameters(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_Parameters(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parameters)
		this->_Inst_Parameters = new TElXMLSOAPCustomParameter(hOutResult, ohFalse);
	else
		this->_Inst_Parameters->updateHandle(hOutResult);
	return this->_Inst_Parameters;
}
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */

void TElXMLSOAPClient::get_ParameterNames(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_ParameterNames(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1803679385, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_ParameterNames(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_ParameterNames(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1803679385, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPClient::get_ParameterValues(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_ParameterValues(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1601101375, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_ParameterValues(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_ParameterValues(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1601101375, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElXMLSOAPClient::get_HTTPStatusCode()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_get_HTTPStatusCode(_Handle, &OutResult));
	return OutResult;
}

TSBXMLSOAPResponseType TElXMLSOAPClient::get_ResponseType()
{
	TSBXMLSOAPResponseTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPClient_get_ResponseType(_Handle, &OutResultRaw));
	return (TSBXMLSOAPResponseType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TMEMORYSTREAM
TMemoryStream* TElXMLSOAPClient::get_ResponseStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_ResponseStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseStream)
		this->_Inst_ResponseStream = new TMemoryStream(hOutResult, ohFalse);
	else
		this->_Inst_ResponseStream->updateHandle(hOutResult);
	return this->_Inst_ResponseStream;
}
#endif /* SB_USE_CLASS_TMEMORYSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLDOMDocument* TElXMLSOAPClient::get_ResponseXMLDocument()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_ResponseXMLDocument(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseXMLDocument)
		this->_Inst_ResponseXMLDocument = new TElXMLDOMDocument(hOutResult, ohFalse);
	else
		this->_Inst_ResponseXMLDocument->updateHandle(hOutResult);
	return this->_Inst_ResponseXMLDocument;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
TElXMLSOAPMessage* TElXMLSOAPClient::get_ResponseSOAPMessage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_ResponseSOAPMessage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseSOAPMessage)
		this->_Inst_ResponseSOAPMessage = new TElXMLSOAPMessage(hOutResult, ohFalse);
	else
		this->_Inst_ResponseSOAPMessage->updateHandle(hOutResult);
	return this->_Inst_ResponseSOAPMessage;
}
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLSOAPClient::get_OperationResponseXMLElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_OperationResponseXMLElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OperationResponseXMLElement)
		this->_Inst_OperationResponseXMLElement = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_OperationResponseXMLElement->updateHandle(hOutResult);
	return this->_Inst_OperationResponseXMLElement;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
TElXMLSOAPCompoundParameter* TElXMLSOAPClient::get_ResponseRootParameter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_ResponseRootParameter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseRootParameter)
		this->_Inst_ResponseRootParameter = new TElXMLSOAPCompoundParameter(hOutResult, ohFalse);
	else
		this->_Inst_ResponseRootParameter->updateHandle(hOutResult);
	return this->_Inst_ResponseRootParameter;
}
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */

SB_INLINE int32_t TElXMLSOAPClient::get_ResponseParameterCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_get_ResponseParameterCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
TElXMLSOAPCustomParameter* TElXMLSOAPClient::get_ResponseParameters(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_ResponseParameters(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseParameters)
		this->_Inst_ResponseParameters = new TElXMLSOAPCustomParameter(hOutResult, ohFalse);
	else
		this->_Inst_ResponseParameters->updateHandle(hOutResult);
	return this->_Inst_ResponseParameters;
}
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */

void TElXMLSOAPClient::get_ResponseParameterNames(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_ResponseParameterNames(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(645936781, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_ResponseParameterNames(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_ResponseParameterNames(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(645936781, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPClient::get_ResponseParameterValues(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_ResponseParameterValues(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1173949316, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_ResponseParameterValues(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_ResponseParameterValues(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1173949316, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElXMLSOAPClient::get_FaultCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPClient_get_FaultCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLSOAPFAULT
TElXMLSOAPFault* TElXMLSOAPClient::get_Faults(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_Faults(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Faults)
		this->_Inst_Faults = new TElXMLSOAPFault(hOutResult, ohFalse);
	else
		this->_Inst_Faults->updateHandle(hOutResult);
	return this->_Inst_Faults;
}
#endif /* SB_USE_CLASS_TELXMLSOAPFAULT */

void TElXMLSOAPClient::get_FaultActor(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_FaultActor(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(267577333, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_FaultActor(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_FaultActor(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(267577333, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPClient::get_FaultCode(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_FaultCode(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-82179173, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_FaultCode(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_FaultCode(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-82179173, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPClient::get_FaultString(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_FaultString(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1161926334, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPClient::get_FaultString(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPClient_get_FaultString(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1161926334, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
TElHTTPSClient* TElXMLSOAPClient::get_HTTPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPClient_get_HTTPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPClient)
		this->_Inst_HTTPClient = new TElHTTPSClient(hOutResult, ohFalse);
	else
		this->_Inst_HTTPClient->updateHandle(hOutResult);
	return this->_Inst_HTTPClient;
}

SB_INLINE void TElXMLSOAPClient::set_HTTPClient(TElHTTPSClient &Value)
{
	SBCheckError(TElXMLSOAPClient_set_HTTPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLSOAPClient::set_HTTPClient(TElHTTPSClient *Value)
{
	SBCheckError(TElXMLSOAPClient_set_HTTPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

void TElXMLSOAPClient::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPClient_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1027062817, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLSOAPClient::set_URL(const std::string &Value)
{
	SBCheckError(TElXMLSOAPClient_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElXMLSOAPClient::get_OnFormatElement(TSBXMLFormatElementEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLSOAPClient_get_OnFormatElement(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLSOAPClient::set_OnFormatElement(TSBXMLFormatElementEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLSOAPClient_set_OnFormatElement(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXMLSOAPClient::get_OnFormatText(TSBXMLFormatTextEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXMLSOAPClient_get_OnFormatText(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXMLSOAPClient::set_OnFormatText(TSBXMLFormatTextEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXMLSOAPClient_set_OnFormatText(_Handle, pMethodValue, pDataValue));
}

void TElXMLSOAPClient::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	this->_Inst_XMLDocument = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
	this->_Inst_SOAPMessage = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
	this->_Inst_MessageNamespaces = NULL;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */
#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
	this->_Inst_RootParameter = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
	this->_Inst_Parameters = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */
#ifdef SB_USE_CLASS_TMEMORYSTREAM
	this->_Inst_ResponseStream = NULL;
#endif /* SB_USE_CLASS_TMEMORYSTREAM */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	this->_Inst_ResponseXMLDocument = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
	this->_Inst_ResponseSOAPMessage = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_OperationResponseXMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
	this->_Inst_ResponseRootParameter = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
	this->_Inst_ResponseParameters = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPFAULT
	this->_Inst_Faults = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPFAULT */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}

TElXMLSOAPClient::TElXMLSOAPClient(TElXMLSOAPClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElXMLSOAPClient::TElXMLSOAPClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPClient_Create(AOwner.getHandle(), &_Handle));
}

TElXMLSOAPClient::TElXMLSOAPClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLSOAPClient::~TElXMLSOAPClient()
{
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	delete this->_Inst_XMLDocument;
	this->_Inst_XMLDocument = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
	delete this->_Inst_SOAPMessage;
	this->_Inst_SOAPMessage = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
	delete this->_Inst_MessageNamespaces;
	this->_Inst_MessageNamespaces = NULL;
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */
#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
	delete this->_Inst_RootParameter;
	this->_Inst_RootParameter = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
	delete this->_Inst_Parameters;
	this->_Inst_Parameters = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */
#ifdef SB_USE_CLASS_TMEMORYSTREAM
	delete this->_Inst_ResponseStream;
	this->_Inst_ResponseStream = NULL;
#endif /* SB_USE_CLASS_TMEMORYSTREAM */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	delete this->_Inst_ResponseXMLDocument;
	this->_Inst_ResponseXMLDocument = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPMESSAGE
	delete this->_Inst_ResponseSOAPMessage;
	this->_Inst_ResponseSOAPMessage = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPMESSAGE */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_OperationResponseXMLElement;
	this->_Inst_OperationResponseXMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER
	delete this->_Inst_ResponseRootParameter;
	this->_Inst_ResponseRootParameter = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER
	delete this->_Inst_ResponseParameters;
	this->_Inst_ResponseParameters = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */
#ifdef SB_USE_CLASS_TELXMLSOAPFAULT
	delete this->_Inst_Faults;
	this->_Inst_Faults = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPFAULT */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
	delete this->_Inst_HTTPClient;
	this->_Inst_HTTPClient = NULL;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
}
#endif /* SB_USE_CLASS_TELXMLSOAPCLIENT */

#ifdef SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCustomParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCustomParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCustomParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCustomParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCustomParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCustomParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCustomParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCustomParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCustomParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCustomParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSOAPCustomParameter::Clear()
{
	SBCheckError(TElXMLSOAPCustomParameter_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPCustomParameter::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPCustomParameter_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPCustomParameter::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPCustomParameter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSOAPCustomParameter::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPCustomParameter_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSOAPCustomParameter::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPCustomParameter_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE TClassHandle TElXMLSOAPCustomParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPCustomParameter_ClassType(&OutResult));
	return OutResult;
}

void TElXMLSOAPCustomParameter::get_ParameterName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPCustomParameter_get_ParameterName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1923093934, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPCustomParameter::get_ParameterName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPCustomParameter_get_ParameterName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1923093934, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPCustomParameter::set_ParameterName(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPCustomParameter_set_ParameterName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPCustomParameter::set_ParameterName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPCustomParameter_set_ParameterName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPCustomParameter::get_ParameterNamespaceURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPCustomParameter_get_ParameterNamespaceURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(580935204, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPCustomParameter::get_ParameterNamespaceURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPCustomParameter_get_ParameterNamespaceURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(580935204, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPCustomParameter::set_ParameterNamespaceURI(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPCustomParameter_set_ParameterNamespaceURI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPCustomParameter::set_ParameterNamespaceURI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPCustomParameter_set_ParameterNamespaceURI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPCustomParameter::TElXMLSOAPCustomParameter(TElXMLSOAPCustomParameterHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLSOAPCustomParameter::TElXMLSOAPCustomParameter() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPCustomParameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPCUSTOMPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASEPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBaseParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBaseParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBaseParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBaseParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBaseParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBaseParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBaseParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBaseParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBaseParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBaseParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSOAPBaseParameter::Clear()
{
	SBCheckError(TElXMLSOAPBaseParameter_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBaseParameter::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPBaseParameter_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPBaseParameter::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPBaseParameter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSOAPBaseParameter::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPBaseParameter_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSOAPBaseParameter::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPBaseParameter_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE TClassHandle TElXMLSOAPBaseParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPBaseParameter_ClassType(&OutResult));
	return OutResult;
}

void TElXMLSOAPBaseParameter::get_StringValue(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPBaseParameter_get_StringValue(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-979675507, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPBaseParameter::get_StringValue(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPBaseParameter_get_StringValue(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-979675507, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPBaseParameter::set_StringValue(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPBaseParameter_set_StringValue(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPBaseParameter::set_StringValue(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPBaseParameter_set_StringValue(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPBaseParameter::TElXMLSOAPBaseParameter(TElXMLSOAPBaseParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPCustomParameter(handle, ownHandle)
{
}

TElXMLSOAPBaseParameter::TElXMLSOAPBaseParameter() : TElXMLSOAPCustomParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPBaseParameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPBASEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPSTRINGPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPStringParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPStringParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPStringParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPStringParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPStringParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPStringParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPStringParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPStringParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPStringParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPStringParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElXMLSOAPStringParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPStringParameter_ClassType(&OutResult));
	return OutResult;
}

void TElXMLSOAPStringParameter::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPStringParameter_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1113256555, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPStringParameter::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPStringParameter_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1113256555, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPStringParameter::set_Value(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPStringParameter_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPStringParameter::set_Value(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPStringParameter_set_Value(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPStringParameter::TElXMLSOAPStringParameter(TElXMLSOAPStringParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseParameter(handle, ownHandle)
{
}

TElXMLSOAPStringParameter::TElXMLSOAPStringParameter() : TElXMLSOAPBaseParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPStringParameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPSTRINGPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBOOLEANPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBooleanParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBooleanParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBooleanParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBooleanParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBooleanParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBooleanParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBooleanParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBooleanParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBooleanParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBooleanParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBooleanParameter::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPBooleanParameter_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPBooleanParameter::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPBooleanParameter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TClassHandle TElXMLSOAPBooleanParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPBooleanParameter_ClassType(&OutResult));
	return OutResult;
}

bool TElXMLSOAPBooleanParameter::get_Value()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSOAPBooleanParameter_get_Value(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLSOAPBooleanParameter::set_Value(bool Value)
{
	SBCheckError(TElXMLSOAPBooleanParameter_set_Value(_Handle, (int8_t)Value));
}

TElXMLSOAPBooleanParameter::TElXMLSOAPBooleanParameter(TElXMLSOAPBooleanParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseParameter(handle, ownHandle)
{
}

TElXMLSOAPBooleanParameter::TElXMLSOAPBooleanParameter() : TElXMLSOAPBaseParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPBooleanParameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPBOOLEANPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPINTEGERPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPIntegerParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPIntegerParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPIntegerParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPIntegerParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPIntegerParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPIntegerParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPIntegerParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPIntegerParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPIntegerParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPIntegerParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPIntegerParameter::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPIntegerParameter_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPIntegerParameter::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPIntegerParameter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TClassHandle TElXMLSOAPIntegerParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPIntegerParameter_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPIntegerParameter::get_Value()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPIntegerParameter_get_Value(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSOAPIntegerParameter::set_Value(int32_t Value)
{
	SBCheckError(TElXMLSOAPIntegerParameter_set_Value(_Handle, Value));
}

TElXMLSOAPIntegerParameter::TElXMLSOAPIntegerParameter(TElXMLSOAPIntegerParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseParameter(handle, ownHandle)
{
}

TElXMLSOAPIntegerParameter::TElXMLSOAPIntegerParameter() : TElXMLSOAPBaseParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPIntegerParameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPINTEGERPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPINT64PARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPInt64Parameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPInt64Parameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPInt64Parameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPInt64Parameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPInt64Parameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPInt64Parameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPInt64Parameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPInt64Parameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPInt64Parameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPInt64Parameter_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPInt64Parameter::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPInt64Parameter_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPInt64Parameter::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPInt64Parameter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TClassHandle TElXMLSOAPInt64Parameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPInt64Parameter_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int64_t TElXMLSOAPInt64Parameter::get_Value()
{
	int64_t OutResult;
	SBCheckError(TElXMLSOAPInt64Parameter_get_Value(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSOAPInt64Parameter::set_Value(int64_t Value)
{
	SBCheckError(TElXMLSOAPInt64Parameter_set_Value(_Handle, Value));
}

TElXMLSOAPInt64Parameter::TElXMLSOAPInt64Parameter(TElXMLSOAPInt64ParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseParameter(handle, ownHandle)
{
}

TElXMLSOAPInt64Parameter::TElXMLSOAPInt64Parameter() : TElXMLSOAPBaseParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPInt64Parameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPINT64PARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPDOUBLEPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDoubleParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDoubleParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDoubleParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDoubleParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDoubleParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDoubleParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDoubleParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDoubleParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDoubleParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDoubleParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPDoubleParameter::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPDoubleParameter_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPDoubleParameter::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPDoubleParameter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TClassHandle TElXMLSOAPDoubleParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPDoubleParameter_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE double TElXMLSOAPDoubleParameter::get_Value()
{
	double OutResult;
	SBCheckError(TElXMLSOAPDoubleParameter_get_Value(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSOAPDoubleParameter::set_Value(double Value)
{
	SBCheckError(TElXMLSOAPDoubleParameter_set_Value(_Handle, Value));
}

TElXMLSOAPDoubleParameter::TElXMLSOAPDoubleParameter(TElXMLSOAPDoubleParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseParameter(handle, ownHandle)
{
}

TElXMLSOAPDoubleParameter::TElXMLSOAPDoubleParameter() : TElXMLSOAPBaseParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPDoubleParameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPDOUBLEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPDATETIMEPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDateTimeParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDateTimeParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDateTimeParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDateTimeParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDateTimeParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDateTimeParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDateTimeParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDateTimeParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPDateTimeParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPDateTimeParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPDateTimeParameter::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPDateTimeParameter_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPDateTimeParameter::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPDateTimeParameter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TClassHandle TElXMLSOAPDateTimeParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPDateTimeParameter_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int64_t TElXMLSOAPDateTimeParameter::get_Value()
{
	int64_t OutResult;
	SBCheckError(TElXMLSOAPDateTimeParameter_get_Value(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLSOAPDateTimeParameter::set_Value(int64_t Value)
{
	SBCheckError(TElXMLSOAPDateTimeParameter_set_Value(_Handle, Value));
}

TSBXMLDateTimeFormat TElXMLSOAPDateTimeParameter::get_DateTimeFormat()
{
	TSBXMLDateTimeFormatRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPDateTimeParameter_get_DateTimeFormat(_Handle, &OutResultRaw));
	return (TSBXMLDateTimeFormat)OutResultRaw;
}

SB_INLINE void TElXMLSOAPDateTimeParameter::set_DateTimeFormat(TSBXMLDateTimeFormat Value)
{
	SBCheckError(TElXMLSOAPDateTimeParameter_set_DateTimeFormat(_Handle, (TSBXMLDateTimeFormatRaw)Value));
}

bool TElXMLSOAPDateTimeParameter::get_IncludeTimeZone()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLSOAPDateTimeParameter_get_IncludeTimeZone(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLSOAPDateTimeParameter::set_IncludeTimeZone(bool Value)
{
	SBCheckError(TElXMLSOAPDateTimeParameter_set_IncludeTimeZone(_Handle, (int8_t)Value));
}

TElXMLSOAPDateTimeParameter::TElXMLSOAPDateTimeParameter(TElXMLSOAPDateTimeParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseParameter(handle, ownHandle)
{
}

TElXMLSOAPDateTimeParameter::TElXMLSOAPDateTimeParameter() : TElXMLSOAPBaseParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPDateTimeParameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPDATETIMEPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPBASE64BINARYPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBase64BinaryParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBase64BinaryParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBase64BinaryParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBase64BinaryParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBase64BinaryParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBase64BinaryParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBase64BinaryParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBase64BinaryParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPBase64BinaryParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPBase64BinaryParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElXMLSOAPBase64BinaryParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPBase64BinaryParameter_ClassType(&OutResult));
	return OutResult;
}

void TElXMLSOAPBase64BinaryParameter::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLSOAPBase64BinaryParameter_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1138675766, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLSOAPBase64BinaryParameter::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLSOAPBase64BinaryParameter_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElXMLSOAPBase64BinaryParameter::TElXMLSOAPBase64BinaryParameter(TElXMLSOAPBase64BinaryParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseParameter(handle, ownHandle)
{
}

TElXMLSOAPBase64BinaryParameter::TElXMLSOAPBase64BinaryParameter() : TElXMLSOAPBaseParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPBase64BinaryParameter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPBASE64BINARYPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCompoundParameter::CreateFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_CreateFromXML(Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCompoundParameter::CreateFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_CreateFromXML((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCompoundParameter::CreateFromXML_Inst(TElXMLDOMElement &Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_CreateFromXML_1(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCompoundParameter::CreateFromXML_Inst(TElXMLDOMElement *Element)
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_CreateFromXML_1(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE TElXMLSOAPCustomParameterHandle TElXMLSOAPCompoundParameter::Clone()
{
	TElXMLSOAPCustomParameterHandle OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPCompoundParameter::Add(TElXMLSOAPCustomParameter &Param)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_Add(_Handle, Param.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPCompoundParameter::Add(TElXMLSOAPCustomParameter *Param)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_Add(_Handle, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddString(const sb_u16string &ParamName, const sb_u16string &Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddString(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value.data(), (int32_t)Value.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddString(const std::wstring &ParamName, const std::wstring &Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPCompoundParameter_AddString(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddString(const sb_u16string &ParamName, const sb_u16string &Value, bool NormalizeNEL)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddString_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value.data(), (int32_t)Value.length(), (int8_t)NormalizeNEL, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddString(const std::wstring &ParamName, const std::wstring &Value, bool NormalizeNEL)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPCompoundParameter_AddString_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (int8_t)NormalizeNEL, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddString(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const sb_u16string &Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddString_2(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value.data(), (int32_t)Value.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddString(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::wstring &Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPCompoundParameter_AddString_2(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddString(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const sb_u16string &Value, bool NormalizeNEL)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddString_3(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value.data(), (int32_t)Value.length(), (int8_t)NormalizeNEL, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddString(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::wstring &Value, bool NormalizeNEL)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPCompoundParameter_AddString_3(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (int8_t)NormalizeNEL, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddBoolean(const sb_u16string &ParamName, bool Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddBoolean(_Handle, ParamName.data(), (int32_t)ParamName.length(), (int8_t)Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddBoolean(const std::wstring &ParamName, bool Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPCompoundParameter_AddBoolean(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, (int8_t)Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddBoolean(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, bool Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddBoolean_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), (int8_t)Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddBoolean(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, bool Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPCompoundParameter_AddBoolean_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, (int8_t)Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddInteger(const sb_u16string &ParamName, int32_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddInteger(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddInteger(const std::wstring &ParamName, int32_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPCompoundParameter_AddInteger(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddInteger(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int32_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddInteger_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddInteger(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int32_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPCompoundParameter_AddInteger_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddInt64(const sb_u16string &ParamName, int64_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddInt64(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddInt64(const std::wstring &ParamName, int64_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPCompoundParameter_AddInt64(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddInt64(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int64_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddInt64_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddInt64(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int64_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPCompoundParameter_AddInt64_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddDouble(const sb_u16string &ParamName, double Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddDouble(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddDouble(const std::wstring &ParamName, double Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPCompoundParameter_AddDouble(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddDouble(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, double Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddDouble_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddDouble(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, double Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPCompoundParameter_AddDouble_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddDateTime(const sb_u16string &ParamName, int64_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddDateTime(_Handle, ParamName.data(), (int32_t)ParamName.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddDateTime(const std::wstring &ParamName, int64_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPCompoundParameter_AddDateTime(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddDateTime(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, int64_t Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddDateTime_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), Value, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddDateTime(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, int64_t Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPCompoundParameter_AddDateTime_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, Value, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddBase64Binary(const sb_u16string &ParamName, const std::vector<uint8_t> &Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddBase64Binary(_Handle, ParamName.data(), (int32_t)ParamName.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddBase64Binary(const std::wstring &ParamName, const std::vector<uint8_t> &Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPCompoundParameter_AddBase64Binary(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddBase64Binary(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI, const std::vector<uint8_t> &Value)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddBase64Binary_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddBase64Binary(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI, const std::vector<uint8_t> &Value)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPCompoundParameter_AddBase64Binary_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddCompound(const sb_u16string &ParamName)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddCompound(_Handle, ParamName.data(), (int32_t)ParamName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddCompound(const std::wstring &ParamName)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	SBCheckError(TElXMLSOAPCompoundParameter_AddCompound(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddCompound(const sb_u16string &ParamName, const sb_u16string &ParamNamespaceURI)
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_AddCompound_1(_Handle, ParamName.data(), (int32_t)ParamName.length(), ParamNamespaceURI.data(), (int32_t)ParamNamespaceURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElXMLSOAPCompoundParameter::AddCompound(const std::wstring &ParamName, const std::wstring &ParamNamespaceURI)
{
	int32_t OutResult;
	std::string u16ParamName;
	sb_to_u16string(ParamName, u16ParamName);
	std::string u16ParamNamespaceURI;
	sb_to_u16string(ParamNamespaceURI, u16ParamNamespaceURI);
	SBCheckError(TElXMLSOAPCompoundParameter_AddCompound_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ParamName.data()), (int32_t)u16ParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ParamNamespaceURI.data()), (int32_t)u16ParamNamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLSOAPCompoundParameter::Delete(int32_t Index)
{
	SBCheckError(TElXMLSOAPCompoundParameter_Delete(_Handle, Index));
}

SB_INLINE void TElXMLSOAPCompoundParameter::Clear()
{
	SBCheckError(TElXMLSOAPCompoundParameter_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPCompoundParameter::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPCompoundParameter_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPCompoundParameter::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPCompoundParameter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSOAPCompoundParameter::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSOAPCompoundParameter::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE TClassHandle TElXMLSOAPCompoundParameter::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLSOAPCompoundParameter::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPCompoundParameter_get_Count(_Handle, &OutResult));
	return OutResult;
}

TElXMLSOAPCustomParameter* TElXMLSOAPCompoundParameter::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPCompoundParameter_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElXMLSOAPCustomParameter(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}

void TElXMLSOAPCompoundParameter::initInstances()
{
	this->_Inst_Items = NULL;
}

TElXMLSOAPCompoundParameter::TElXMLSOAPCompoundParameter(TElXMLSOAPCompoundParameterHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPCustomParameter(handle, ownHandle)
{
	initInstances();
}

TElXMLSOAPCompoundParameter::TElXMLSOAPCompoundParameter() : TElXMLSOAPCustomParameter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPCompoundParameter_Create(&_Handle));
}

TElXMLSOAPCompoundParameter::~TElXMLSOAPCompoundParameter()
{
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
}
#endif /* SB_USE_CLASS_TELXMLSOAPCOMPOUNDPARAMETER */

#ifdef SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER

SB_INLINE void TElXMLSOAPParametersManager::Add(TElXMLSOAPParameterClassHandle AParamClass)
{
	SBCheckError(TElXMLSOAPParametersManager_Add(_Handle, AParamClass));
}

SB_INLINE void TElXMLSOAPParametersManager::Add(const sb_u16string &AParamName, const sb_u16string &AParamNamespaceURI, TElXMLSOAPParameterClassHandle AParamClass)
{
	SBCheckError(TElXMLSOAPParametersManager_Add_1(_Handle, AParamName.data(), (int32_t)AParamName.length(), AParamNamespaceURI.data(), (int32_t)AParamNamespaceURI.length(), AParamClass));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPParametersManager::Add(const std::wstring &AParamName, const std::wstring &AParamNamespaceURI, TElXMLSOAPParameterClassHandle AParamClass)
{
	std::string u16AParamName;
	sb_to_u16string(AParamName, u16AParamName);
	std::string u16AParamNamespaceURI;
	sb_to_u16string(AParamNamespaceURI, u16AParamNamespaceURI);
	SBCheckError(TElXMLSOAPParametersManager_Add_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16AParamName.data()), (int32_t)u16AParamName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AParamNamespaceURI.data()), (int32_t)u16AParamNamespaceURI.length() >> 1, AParamClass));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLSOAPParametersManager::RemoveAt(int32_t Index)
{
	SBCheckError(TElXMLSOAPParametersManager_RemoveAt(_Handle, Index));
}

SB_INLINE int32_t TElXMLSOAPParametersManager::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPParametersManager_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElXMLSOAPParametersManager::get_ParamNames(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPParametersManager_get_ParamNames(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-601338353, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPParametersManager::get_ParamNames(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPParametersManager_get_ParamNames(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-601338353, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPParametersManager::get_ParamNamespaceURIs(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPParametersManager_get_ParamNamespaceURIs(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-966225287, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPParametersManager::get_ParamNamespaceURIs(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPParametersManager_get_ParamNamespaceURIs(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-966225287, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE TElXMLSOAPParameterClassHandle TElXMLSOAPParametersManager::get_ParamClasses(int32_t Index)
{
	TElXMLSOAPParameterClassHandle OutResult;
	SBCheckError(TElXMLSOAPParametersManager_get_ParamClasses(_Handle, Index, &OutResult));
	return OutResult;
}

TElXMLSOAPParametersManager::TElXMLSOAPParametersManager(TElXMLSOAPParametersManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXMLSOAPParametersManager::TElXMLSOAPParametersManager() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPParametersManager_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER */

#ifdef SB_USE_CLASS_TELXMLSOAPFAULT

SB_INLINE void TElXMLSOAPFault::Clear()
{
	SBCheckError(TElXMLSOAPFault_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPFault::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPFault_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPFault::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPFault_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSOAPFault::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPFault_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSOAPFault::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPFault_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSOAPFault::get_FaultActor(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPFault_get_FaultActor(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1822930881, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPFault::get_FaultActor(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPFault_get_FaultActor(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1822930881, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPFault::set_FaultActor(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPFault_set_FaultActor(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPFault::set_FaultActor(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPFault_set_FaultActor(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPFault::get_FaultCode(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPFault_get_FaultCode(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1488152671, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPFault::get_FaultCode(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPFault_get_FaultCode(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1488152671, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPFault::set_FaultCode(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPFault_set_FaultCode(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPFault::set_FaultCode(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPFault_set_FaultCode(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPFault::get_FaultString(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPFault_get_FaultString(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1047271359, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPFault::get_FaultString(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPFault_get_FaultString(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1047271359, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPFault::set_FaultString(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPFault_set_FaultString(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPFault::set_FaultString(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPFault_set_FaultString(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPFault::get_Detail(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPFault_get_Detail(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1694189969, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPFault::get_Detail(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPFault_get_Detail(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1694189969, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPFault::set_Detail(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPFault_set_Detail(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPFault::set_Detail(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPFault_set_Detail(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPFault::TElXMLSOAPFault(TElXMLSOAPFaultHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPElement(handle, ownHandle)
{
}

TElXMLSOAPFault::TElXMLSOAPFault(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPFault_Create((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPFault::TElXMLSOAPFault(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPFault_Create((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPFault::TElXMLSOAPFault(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPFault_Create_1((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPFault::TElXMLSOAPFault(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPFault_Create_1((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPFault::TElXMLSOAPFault(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPFault_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

TElXMLSOAPFault::TElXMLSOAPFault(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPFault_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPFault::TElXMLSOAPFault(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPFault_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

TElXMLSOAPFault::TElXMLSOAPFault(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPFault_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPFault::TElXMLSOAPFault(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPFault_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLSOAPFault::TElXMLSOAPFault(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPFault_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPFault::TElXMLSOAPFault(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPFault_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLSOAPFault::TElXMLSOAPFault(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPFault_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLSOAPFAULT */

#ifdef SB_USE_GLOBAL_PROCS_XMLSOAPCLIENT

#ifdef SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER
SB_INLINE TElXMLSOAPParametersManagerHandle SOAPParametersManager()
{
	TElXMLSOAPParametersManagerHandle OutResult;
	SBCheckError(SBXMLSOAPClient_SOAPParametersManager(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLSOAPPARAMETERSMANAGER */

#endif /* SB_USE_GLOBAL_PROCS_XMLSOAPCLIENT */

};	/* namespace SecureBlackbox */

