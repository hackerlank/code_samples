#include "sbhttpsclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHTTPREQUESTPARAMS

void TElHTTPRequestParams::get_Cookie(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPRequestParams_get_Cookie(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1261829690, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPRequestParams::set_Cookie(const std::string &Value)
{
	SBCheckError(TElHTTPRequestParams_set_Cookie(_Handle, Value.data(), (int32_t)Value.length()));
}

TElHTTPRequestParams::TElHTTPRequestParams(TElHTTPRequestParamsHandle handle, TElOwnHandle ownHandle) : TElHTTPCustomRequestParams(handle, ownHandle)
{
}

TElHTTPRequestParams::TElHTTPRequestParams() : TElHTTPCustomRequestParams(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPRequestParams_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT

#ifdef SB_USE_CLASSES_TELSOCKET_AND_TELWEBSOCKETCLIENT
int32_t TElHTTPSClient::StartWS(const std::string &URL, TElWebSocketClient &WSClient, TElSocket &Socket)
{
	int32_t OutResult;
	TElClassHandle hWSClient = SB_NULL_HANDLE;
	TElClassHandle hSocket = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_StartWS(_Handle, URL.data(), (int32_t)URL.length(), &hWSClient, &hSocket, &OutResult));
	WSClient.updateHandle(hWSClient);
	Socket.updateHandle(hSocket);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSOCKET_AND_TELWEBSOCKETCLIENT */

SB_INLINE int32_t TElHTTPSClient::CustomRequest(const std::string &URL, const std::string &Method)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_CustomRequest(_Handle, URL.data(), (int32_t)URL.length(), Method.data(), (int32_t)Method.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElHTTPSClient::CustomRequest(const std::string &URL, const std::string &Method, TStream &Content, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_CustomRequest_1(_Handle, URL.data(), (int32_t)URL.length(), Method.data(), (int32_t)Method.length(), Content.getHandle(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::CustomRequest(const std::string &URL, const std::string &Method, TStream *Content, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_CustomRequest_1(_Handle, URL.data(), (int32_t)URL.length(), Method.data(), (int32_t)Method.length(), (Content != NULL) ? Content->getHandle() : SB_NULL_HANDLE, (int8_t)CloseStream, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElHTTPSClient::Get(const std::string &URL)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Get(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Head(const std::string &URL)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Head(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Options(const std::string &URL)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Options(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Delete(const std::string &URL)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Delete(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Trace(const std::string &URL)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Trace(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Post(const std::string &URL)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Post(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Post(const std::string &URL, const std::string &Content)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Post_1(_Handle, URL.data(), (int32_t)URL.length(), Content.data(), (int32_t)Content.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Post(const std::string &URL, const std::vector<uint8_t> &Content)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Post_2(_Handle, URL.data(), (int32_t)URL.length(), SB_STD_VECTOR_FRONT_ADR(Content), (int32_t)Content.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElHTTPSClient::Post(const std::string &URL, TStream &Content, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Post_3(_Handle, URL.data(), (int32_t)URL.length(), Content.getHandle(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Post(const std::string &URL, TStream *Content, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Post_3(_Handle, URL.data(), (int32_t)URL.length(), (Content != NULL) ? Content->getHandle() : SB_NULL_HANDLE, (int8_t)CloseStream, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE int32_t TElHTTPSClient::PostWebForm(const std::string &URL, TStringList &Fields, const std::string &FileField, const std::string &FileName, TStream &FileStream, const std::string &ContentType, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostWebForm(_Handle, URL.data(), (int32_t)URL.length(), Fields.getHandle(), FileField.data(), (int32_t)FileField.length(), FileName.data(), (int32_t)FileName.length(), FileStream.getHandle(), ContentType.data(), (int32_t)ContentType.length(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::PostWebForm(const std::string &URL, TStringList *Fields, const std::string &FileField, const std::string &FileName, TStream *FileStream, const std::string &ContentType, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostWebForm(_Handle, URL.data(), (int32_t)URL.length(), (Fields != NULL) ? Fields->getHandle() : SB_NULL_HANDLE, FileField.data(), (int32_t)FileField.length(), FileName.data(), (int32_t)FileName.length(), (FileStream != NULL) ? FileStream->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE int32_t TElHTTPSClient::PostWebForm(const std::string &URL, TElStringList &Fields, const std::string &FileField, const std::string &FileName, TStream &FileStream, const std::string &ContentType, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostWebForm(_Handle, URL.data(), (int32_t)URL.length(), Fields.getHandle(), FileField.data(), (int32_t)FileField.length(), FileName.data(), (int32_t)FileName.length(), FileStream.getHandle(), ContentType.data(), (int32_t)ContentType.length(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::PostWebForm(const std::string &URL, TElStringList *Fields, const std::string &FileField, const std::string &FileName, TStream *FileStream, const std::string &ContentType, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostWebForm(_Handle, URL.data(), (int32_t)URL.length(), (Fields != NULL) ? Fields->getHandle() : SB_NULL_HANDLE, FileField.data(), (int32_t)FileField.length(), FileName.data(), (int32_t)FileName.length(), (FileStream != NULL) ? FileStream->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE int32_t TElHTTPSClient::PostWebForm(const std::string &URL, TStringList &Fields, const std::string &FileField, const std::string &FileName, TStream &FileStream, const std::string &ContentType, bool CloseStream, const std::string &Charset)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostWebForm_1(_Handle, URL.data(), (int32_t)URL.length(), Fields.getHandle(), FileField.data(), (int32_t)FileField.length(), FileName.data(), (int32_t)FileName.length(), FileStream.getHandle(), ContentType.data(), (int32_t)ContentType.length(), (int8_t)CloseStream, Charset.data(), (int32_t)Charset.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::PostWebForm(const std::string &URL, TStringList *Fields, const std::string &FileField, const std::string &FileName, TStream *FileStream, const std::string &ContentType, bool CloseStream, const std::string &Charset)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostWebForm_1(_Handle, URL.data(), (int32_t)URL.length(), (Fields != NULL) ? Fields->getHandle() : SB_NULL_HANDLE, FileField.data(), (int32_t)FileField.length(), FileName.data(), (int32_t)FileName.length(), (FileStream != NULL) ? FileStream->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), (int8_t)CloseStream, Charset.data(), (int32_t)Charset.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE int32_t TElHTTPSClient::PostWebForm(const std::string &URL, TElStringList &Fields, const std::string &FileField, const std::string &FileName, TStream &FileStream, const std::string &ContentType, bool CloseStream, const std::string &Charset)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostWebForm_1(_Handle, URL.data(), (int32_t)URL.length(), Fields.getHandle(), FileField.data(), (int32_t)FileField.length(), FileName.data(), (int32_t)FileName.length(), FileStream.getHandle(), ContentType.data(), (int32_t)ContentType.length(), (int8_t)CloseStream, Charset.data(), (int32_t)Charset.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::PostWebForm(const std::string &URL, TElStringList *Fields, const std::string &FileField, const std::string &FileName, TStream *FileStream, const std::string &ContentType, bool CloseStream, const std::string &Charset)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostWebForm_1(_Handle, URL.data(), (int32_t)URL.length(), (Fields != NULL) ? Fields->getHandle() : SB_NULL_HANDLE, FileField.data(), (int32_t)FileField.length(), FileName.data(), (int32_t)FileName.length(), (FileStream != NULL) ? FileStream->getHandle() : SB_NULL_HANDLE, ContentType.data(), (int32_t)ContentType.length(), (int8_t)CloseStream, Charset.data(), (int32_t)Charset.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
SB_INLINE int32_t TElHTTPSClient::PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, TElHTTPMultipartList &PartsList)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostMultipart(_Handle, URL.data(), (int32_t)URL.length(), (TSBHTTPMultipartModeRaw)MultipartMode, PartsList.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, TElHTTPMultipartList *PartsList)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostMultipart(_Handle, URL.data(), (int32_t)URL.length(), (TSBHTTPMultipartModeRaw)MultipartMode, (PartsList != NULL) ? PartsList->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
SB_INLINE int32_t TElHTTPSClient::PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, const std::string &RelatedStart, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList &PartsList)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostMultipart_1(_Handle, URL.data(), (int32_t)URL.length(), (TSBHTTPMultipartModeRaw)MultipartMode, RelatedStart.data(), (int32_t)RelatedStart.length(), RelatedStartInfo.data(), (int32_t)RelatedStartInfo.length(), RelatedType.data(), (int32_t)RelatedType.length(), PartsList.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, const std::string &RelatedStart, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList *PartsList)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostMultipart_1(_Handle, URL.data(), (int32_t)URL.length(), (TSBHTTPMultipartModeRaw)MultipartMode, RelatedStart.data(), (int32_t)RelatedStart.length(), RelatedStartInfo.data(), (int32_t)RelatedStartInfo.length(), RelatedType.data(), (int32_t)RelatedType.length(), (PartsList != NULL) ? PartsList->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
SB_INLINE int32_t TElHTTPSClient::PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, const std::string &RelatedStart, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList &PartsList, const std::string &Charset)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostMultipart_2(_Handle, URL.data(), (int32_t)URL.length(), (TSBHTTPMultipartModeRaw)MultipartMode, RelatedStart.data(), (int32_t)RelatedStart.length(), RelatedStartInfo.data(), (int32_t)RelatedStartInfo.length(), RelatedType.data(), (int32_t)RelatedType.length(), PartsList.getHandle(), Charset.data(), (int32_t)Charset.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, const std::string &RelatedStart, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList *PartsList, const std::string &Charset)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_PostMultipart_2(_Handle, URL.data(), (int32_t)URL.length(), (TSBHTTPMultipartModeRaw)MultipartMode, RelatedStart.data(), (int32_t)RelatedStart.length(), RelatedStartInfo.data(), (int32_t)RelatedStartInfo.length(), RelatedType.data(), (int32_t)RelatedType.length(), (PartsList != NULL) ? PartsList->getHandle() : SB_NULL_HANDLE, Charset.data(), (int32_t)Charset.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

SB_INLINE int32_t TElHTTPSClient::Put(const std::string &URL)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Put(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Put(const std::string &URL, const std::string &Content)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Put_1(_Handle, URL.data(), (int32_t)URL.length(), Content.data(), (int32_t)Content.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Put(const std::string &URL, const std::vector<uint8_t> &Content)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Put_2(_Handle, URL.data(), (int32_t)URL.length(), SB_STD_VECTOR_FRONT_ADR(Content), (int32_t)Content.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Put(const std::string &URL, const std::vector<uint8_t> &Content, int32_t StartIndex, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Put_3(_Handle, URL.data(), (int32_t)URL.length(), SB_STD_VECTOR_FRONT_ADR(Content), (int32_t)Content.size(), StartIndex, Count, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElHTTPSClient::Put(const std::string &URL, TStream &Content, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Put_4(_Handle, URL.data(), (int32_t)URL.length(), Content.getHandle(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPSClient::Put(const std::string &URL, TStream *Content, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_Put_4(_Handle, URL.data(), (int32_t)URL.length(), (Content != NULL) ? Content->getHandle() : SB_NULL_HANDLE, (int8_t)CloseStream, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElHTTPSClient::CancelRequest()
{
	SBCheckError(TElHTTPSClient_CancelRequest(_Handle));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElHTTPSClient::GetHeaderByName(TStringList &Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClient_GetHeaderByName(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1481289670, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHTTPSClient::GetHeaderByName(TStringList *Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClient_GetHeaderByName(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1481289670, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElHTTPSClient::GetHeaderByName(TElStringList &Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClient_GetHeaderByName(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1643282953, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHTTPSClient::GetHeaderByName(TElStringList *Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClient_GetHeaderByName(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1643282953, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElHTTPSClient::GetHeadersByName(TStringList &Headers, const std::string &Header, TStringList &Res)
{
	SBCheckError(TElHTTPSClient_GetHeadersByName(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), Res.getHandle()));
}

SB_INLINE void TElHTTPSClient::GetHeadersByName(TStringList *Headers, const std::string &Header, TStringList *Res)
{
	SBCheckError(TElHTTPSClient_GetHeadersByName(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), (Res != NULL) ? Res->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElHTTPSClient::GetHeadersByName(TElStringList &Headers, const std::string &Header, TElStringList &Res)
{
	SBCheckError(TElHTTPSClient_GetHeadersByName(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), Res.getHandle()));
}

SB_INLINE void TElHTTPSClient::GetHeadersByName(TElStringList *Headers, const std::string &Header, TElStringList *Res)
{
	SBCheckError(TElHTTPSClient_GetHeadersByName(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), (Res != NULL) ? Res->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElHTTPSClient::SetHeaderByName(TStringList &Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPSClient_SetHeaderByName(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElHTTPSClient::SetHeaderByName(TStringList *Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPSClient_SetHeaderByName(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElHTTPSClient::SetHeaderByName(TElStringList &Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPSClient_SetHeaderByName(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElHTTPSClient::SetHeaderByName(TElStringList *Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPSClient_SetHeaderByName(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void TElHTTPSClient::SetRequestHeader(const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPSClient_SetRequestHeader(_Handle, Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElHTTPSClient::ClearRequest()
{
	SBCheckError(TElHTTPSClient_ClearRequest(_Handle));
}

SB_INLINE void TElHTTPSClient::ClearResponse()
{
	SBCheckError(TElHTTPSClient_ClearResponse(_Handle));
}

SB_INLINE void TElHTTPSClient::ClearAuthCache()
{
	SBCheckError(TElHTTPSClient_ClearAuthCache(_Handle));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElHTTPSClient::get_RequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_RequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestHeaders)
		this->_Inst_RequestHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequestHeaders->updateHandle(hOutResult);
	return this->_Inst_RequestHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElHTTPSClient::get_RequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_RequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestHeaders)
		this->_Inst_RequestHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequestHeaders->updateHandle(hOutResult);
	return this->_Inst_RequestHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElHTTPSClient::get_ResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_ResponseHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseHeaders)
		this->_Inst_ResponseHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ResponseHeaders->updateHandle(hOutResult);
	return this->_Inst_ResponseHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElHTTPSClient::get_ResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_ResponseHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseHeaders)
		this->_Inst_ResponseHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ResponseHeaders->updateHandle(hOutResult);
	return this->_Inst_ResponseHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElHTTPSClient::get_RequestCookies()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_RequestCookies(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestCookies)
		this->_Inst_RequestCookies = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequestCookies->updateHandle(hOutResult);
	return this->_Inst_RequestCookies;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElHTTPSClient::get_RequestCookies()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_RequestCookies(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestCookies)
		this->_Inst_RequestCookies = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequestCookies->updateHandle(hOutResult);
	return this->_Inst_RequestCookies;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElHTTPSClient::get_ResponseCookies()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_ResponseCookies(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseCookies)
		this->_Inst_ResponseCookies = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ResponseCookies->updateHandle(hOutResult);
	return this->_Inst_ResponseCookies;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElHTTPSClient::get_ResponseCookies()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_ResponseCookies(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponseCookies)
		this->_Inst_ResponseCookies = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ResponseCookies->updateHandle(hOutResult);
	return this->_Inst_ResponseCookies;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int32_t TElHTTPSClient::get_ServerStatusCode()
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_get_ServerStatusCode(_Handle, &OutResult));
	return OutResult;
}

void TElHTTPSClient::get_ServerReasonPhrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClient_get_ServerReasonPhrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1928374283, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElHTTPSClient::get_ContentLength()
{
	int64_t OutResult;
	SBCheckError(TElHTTPSClient_get_ContentLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElHTTPSClient::get_Date()
{
	int64_t OutResult;
	SBCheckError(TElHTTPSClient_get_Date(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElHTTPSClient::get_OutputStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_OutputStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OutputStream)
		this->_Inst_OutputStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_OutputStream->updateHandle(hOutResult);
	return this->_Inst_OutputStream;
}

SB_INLINE void TElHTTPSClient::set_OutputStream(TStream &Value)
{
	SBCheckError(TElHTTPSClient_set_OutputStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSClient::set_OutputStream(TStream *Value)
{
	SBCheckError(TElHTTPSClient_set_OutputStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElHTTPSClient::get_SSLEnabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_SSLEnabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_SSLEnabled(bool Value)
{
	SBCheckError(TElHTTPSClient_set_SSLEnabled(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELHTTPREQUESTPARAMS
TElHTTPRequestParams* TElHTTPSClient::get_RequestParameters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_RequestParameters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestParameters)
		this->_Inst_RequestParameters = new TElHTTPRequestParams(hOutResult, ohFalse);
	else
		this->_Inst_RequestParameters->updateHandle(hOutResult);
	return this->_Inst_RequestParameters;
}

SB_INLINE void TElHTTPSClient::set_RequestParameters(TElHTTPRequestParams &Value)
{
	SBCheckError(TElHTTPSClient_set_RequestParameters(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSClient::set_RequestParameters(TElHTTPRequestParams *Value)
{
	SBCheckError(TElHTTPSClient_set_RequestParameters(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPREQUESTPARAMS */

SB_INLINE int32_t TElHTTPSClient::get_RequestCompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_get_RequestCompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSClient::set_RequestCompressionLevel(int32_t Value)
{
	SBCheckError(TElHTTPSClient_set_RequestCompressionLevel(_Handle, Value));
}

bool TElHTTPSClient::get_RequestCompressionGZip()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_RequestCompressionGZip(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_RequestCompressionGZip(bool Value)
{
	SBCheckError(TElHTTPSClient_set_RequestCompressionGZip(_Handle, (int8_t)Value));
}

TSBHTTPKeepAlivePolicy TElHTTPSClient::get_KeepAlivePolicy()
{
	TSBHTTPKeepAlivePolicyRaw OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_KeepAlivePolicy(_Handle, &OutResultRaw));
	return (TSBHTTPKeepAlivePolicy)OutResultRaw;
}

SB_INLINE void TElHTTPSClient::set_KeepAlivePolicy(TSBHTTPKeepAlivePolicy Value)
{
	SBCheckError(TElHTTPSClient_set_KeepAlivePolicy(_Handle, (TSBHTTPKeepAlivePolicyRaw)Value));
}

SB_INLINE int32_t TElHTTPSClient::get_MaxRedirections()
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_get_MaxRedirections(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSClient::set_MaxRedirections(int32_t Value)
{
	SBCheckError(TElHTTPSClient_set_MaxRedirections(_Handle, Value));
}

bool TElHTTPSClient::get_SuppressRedirectionContent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_SuppressRedirectionContent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_SuppressRedirectionContent(bool Value)
{
	SBCheckError(TElHTTPSClient_set_SuppressRedirectionContent(_Handle, (int8_t)Value));
}

TSBHTTPVersion TElHTTPSClient::get_HTTPVersion()
{
	TSBHTTPVersionRaw OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_HTTPVersion(_Handle, &OutResultRaw));
	return (TSBHTTPVersion)OutResultRaw;
}

SB_INLINE void TElHTTPSClient::set_HTTPVersion(TSBHTTPVersion Value)
{
	SBCheckError(TElHTTPSClient_set_HTTPVersion(_Handle, (TSBHTTPVersionRaw)Value));
}

bool TElHTTPSClient::get_UseNTLMAuth()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_UseNTLMAuth(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_UseNTLMAuth(bool Value)
{
	SBCheckError(TElHTTPSClient_set_UseNTLMAuth(_Handle, (int8_t)Value));
}

bool TElHTTPSClient::get_UseDigestAuth()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_UseDigestAuth(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_UseDigestAuth(bool Value)
{
	SBCheckError(TElHTTPSClient_set_UseDigestAuth(_Handle, (int8_t)Value));
}

bool TElHTTPSClient::get_PersistentAuthHeader()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_PersistentAuthHeader(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_PersistentAuthHeader(bool Value)
{
	SBCheckError(TElHTTPSClient_set_PersistentAuthHeader(_Handle, (int8_t)Value));
}

bool TElHTTPSClient::get_ForceNTLMAuth()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_ForceNTLMAuth(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_ForceNTLMAuth(bool Value)
{
	SBCheckError(TElHTTPSClient_set_ForceNTLMAuth(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElHTTPSClient::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSClient::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElHTTPSClient_set_SendBufferSize(_Handle, Value));
}

bool TElHTTPSClient::get_UseCompression()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_UseCompression(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_UseCompression(bool Value)
{
	SBCheckError(TElHTTPSClient_set_UseCompression(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
bool TElHTTPSClient::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_UseIPv6(bool Value)
{
	SBCheckError(TElHTTPSClient_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

#ifdef SB_USE_CLASS_TELCOOKIEMANAGER
TElCookieManager* TElHTTPSClient::get_CookieManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_CookieManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CookieManager)
		this->_Inst_CookieManager = new TElCookieManager(hOutResult, ohFalse);
	else
		this->_Inst_CookieManager->updateHandle(hOutResult);
	return this->_Inst_CookieManager;
}

SB_INLINE void TElHTTPSClient::set_CookieManager(TElCookieManager &Value)
{
	SBCheckError(TElHTTPSClient_set_CookieManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSClient::set_CookieManager(TElCookieManager *Value)
{
	SBCheckError(TElHTTPSClient_set_CookieManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCOOKIEMANAGER */

bool TElHTTPSClient::get_Use100Continue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_Use100Continue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_Use100Continue(bool Value)
{
	SBCheckError(TElHTTPSClient_set_Use100Continue(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
TElOAuth2Settings* TElHTTPSClient::get_OAuth2()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_OAuth2(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OAuth2)
		this->_Inst_OAuth2 = new TElOAuth2Settings(hOutResult, ohFalse);
	else
		this->_Inst_OAuth2->updateHandle(hOutResult);
	return this->_Inst_OAuth2;
}

SB_INLINE void TElHTTPSClient::set_OAuth2(TElOAuth2Settings &Value)
{
	SBCheckError(TElHTTPSClient_set_OAuth2(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSClient::set_OAuth2(TElOAuth2Settings *Value)
{
	SBCheckError(TElHTTPSClient_set_OAuth2(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */

#ifdef SB_USE_CLASS_TELCUSTOMSAMLADAPTER
TElCustomSAMLAdapter* TElHTTPSClient::get_SAMLAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_SAMLAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SAMLAdapter)
		this->_Inst_SAMLAdapter = new TElCustomSAMLAdapter(hOutResult, ohFalse);
	else
		this->_Inst_SAMLAdapter->updateHandle(hOutResult);
	return this->_Inst_SAMLAdapter;
}

SB_INLINE void TElHTTPSClient::set_SAMLAdapter(TElCustomSAMLAdapter &Value)
{
	SBCheckError(TElHTTPSClient_set_SAMLAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSClient::set_SAMLAdapter(TElCustomSAMLAdapter *Value)
{
	SBCheckError(TElHTTPSClient_set_SAMLAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMSAMLADAPTER */

void TElHTTPSClient::get_HTTPProxyUsername(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClient_get_HTTPProxyUsername(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2066344506, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPSClient::set_HTTPProxyUsername(const std::string &Value)
{
	SBCheckError(TElHTTPSClient_set_HTTPProxyUsername(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPSClient::get_HTTPProxyPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClient_get_HTTPProxyPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1229608292, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPSClient::set_HTTPProxyPassword(const std::string &Value)
{
	SBCheckError(TElHTTPSClient_set_HTTPProxyPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPSClient::get_HTTPProxyHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClient_get_HTTPProxyHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-534601838, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPSClient::set_HTTPProxyHost(const std::string &Value)
{
	SBCheckError(TElHTTPSClient_set_HTTPProxyHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElHTTPSClient::get_HTTPProxyPort()
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClient_get_HTTPProxyPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSClient::set_HTTPProxyPort(int32_t Value)
{
	SBCheckError(TElHTTPSClient_set_HTTPProxyPort(_Handle, Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElHTTPSClient::get_HTTPProxyRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_HTTPProxyRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPProxyRequestHeaders)
		this->_Inst_HTTPProxyRequestHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_HTTPProxyRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_HTTPProxyRequestHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElHTTPSClient::get_HTTPProxyRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClient_get_HTTPProxyRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HTTPProxyRequestHeaders)
		this->_Inst_HTTPProxyRequestHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_HTTPProxyRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_HTTPProxyRequestHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TElWebTunnelAuthentication TElHTTPSClient::get_HTTPProxyAuthentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_HTTPProxyAuthentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElHTTPSClient::set_HTTPProxyAuthentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElHTTPSClient_set_HTTPProxyAuthentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

bool TElHTTPSClient::get_UseHTTPProxy()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_UseHTTPProxy(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_UseHTTPProxy(bool Value)
{
	SBCheckError(TElHTTPSClient_set_UseHTTPProxy(_Handle, (int8_t)Value));
}

bool TElHTTPSClient::get_IgnoreUnknownTransferEncodings()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClient_get_IgnoreUnknownTransferEncodings(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClient::set_IgnoreUnknownTransferEncodings(bool Value)
{
	SBCheckError(TElHTTPSClient_set_IgnoreUnknownTransferEncodings(_Handle, (int8_t)Value));
}

SB_INLINE void TElHTTPSClient::get_OnBeforeWebSocketClientUsed(TSBHTTPBeforeWebSocketClientUsedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnBeforeWebSocketClientUsed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnBeforeWebSocketClientUsed(TSBHTTPBeforeWebSocketClientUsedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnBeforeWebSocketClientUsed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnWebSocketConnectionEstablished(SBHTTPSClient_TSBHTTPWebSocketConnectionEstablishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnWebSocketConnectionEstablished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnWebSocketConnectionEstablished(SBHTTPSClient_TSBHTTPWebSocketConnectionEstablishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnWebSocketConnectionEstablished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnCookie(TSBHTTPCookieEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnCookie(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnCookie(TSBHTTPCookieEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnCookie(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnData(TSBDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnDocumentBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnDocumentBegin(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnDocumentBegin(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnDocumentBegin(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnDocumentEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnDocumentEnd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnDocumentEnd(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnDocumentEnd(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnReceivingHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnReceivingHeaders(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnReceivingHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnReceivingHeaders(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnPreparedHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnPreparedHeaders(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnPreparedHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnPreparedHeaders(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnRedirection(TSBHTTPRedirectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnRedirection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnRedirection(TSBHTTPRedirectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnRedirection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnSendData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnSendData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnSendData(TSBDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnSendData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnDynamicDataNeeded(TSBHTTPDynamicDataNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnDynamicDataNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnDynamicDataNeeded(TSBHTTPDynamicDataNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnDynamicDataNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnOAuth2Browse(TSBHTTPOAuth2BrowseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnOAuth2Browse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnOAuth2Browse(TSBHTTPOAuth2BrowseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnOAuth2Browse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnUnsupportedTransferEncoding(TSBHTTPUnsupportedTransferEncoding &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnUnsupportedTransferEncoding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnUnsupportedTransferEncoding(TSBHTTPUnsupportedTransferEncoding pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnUnsupportedTransferEncoding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnCertificateChoose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnCertificateChoose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnCertificateNeededEx(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnCertificateNeededEx(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnCertificateStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnCertificateStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSClient::get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSClient_get_OnRenegotiationRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSClient::set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSClient_set_OnRenegotiationRequest(_Handle, pMethodValue, pDataValue));
}

void TElHTTPSClient::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_RequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_RequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_RequestCookies = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_RequestCookies = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ResponseCookies = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ResponseCookies = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_OutputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELHTTPREQUESTPARAMS
	this->_Inst_RequestParameters = NULL;
#endif /* SB_USE_CLASS_TELHTTPREQUESTPARAMS */
#ifdef SB_USE_CLASS_TELCOOKIEMANAGER
	this->_Inst_CookieManager = NULL;
#endif /* SB_USE_CLASS_TELCOOKIEMANAGER */
#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
	this->_Inst_OAuth2 = NULL;
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMSAMLADAPTER
	this->_Inst_SAMLAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSAMLADAPTER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_HTTPProxyRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_HTTPProxyRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElHTTPSClient::TElHTTPSClient(TElHTTPSClientHandle handle, TElOwnHandle ownHandle) : TElCustomSimpleSSLClient(handle, ownHandle)
{
	initInstances();
}

TElHTTPSClient::TElHTTPSClient(TComponent &AOwner) : TElCustomSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPSClient_Create(AOwner.getHandle(), &_Handle));
}

TElHTTPSClient::TElHTTPSClient(TComponent *AOwner) : TElCustomSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPSClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElHTTPSClient::~TElHTTPSClient()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_RequestHeaders;
	this->_Inst_RequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_RequestHeaders;
	this->_Inst_RequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ResponseHeaders;
	this->_Inst_ResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ResponseHeaders;
	this->_Inst_ResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_RequestCookies;
	this->_Inst_RequestCookies = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_RequestCookies;
	this->_Inst_RequestCookies = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ResponseCookies;
	this->_Inst_ResponseCookies = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ResponseCookies;
	this->_Inst_ResponseCookies = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_OutputStream;
	this->_Inst_OutputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELHTTPREQUESTPARAMS
	delete this->_Inst_RequestParameters;
	this->_Inst_RequestParameters = NULL;
#endif /* SB_USE_CLASS_TELHTTPREQUESTPARAMS */
#ifdef SB_USE_CLASS_TELCOOKIEMANAGER
	delete this->_Inst_CookieManager;
	this->_Inst_CookieManager = NULL;
#endif /* SB_USE_CLASS_TELCOOKIEMANAGER */
#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
	delete this->_Inst_OAuth2;
	this->_Inst_OAuth2 = NULL;
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMSAMLADAPTER
	delete this->_Inst_SAMLAdapter;
	this->_Inst_SAMLAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSAMLADAPTER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_HTTPProxyRequestHeaders;
	this->_Inst_HTTPProxyRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_HTTPProxyRequestHeaders;
	this->_Inst_HTTPProxyRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#ifdef SB_USE_CLASS_SBHTTPSCLIENT_TELSTRINGVALUE

void SBHTTPSClient_TElStringValue::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBHTTPSClient_TElStringValue_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1883466558, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SBHTTPSClient_TElStringValue::set_Value(const std::string &Value)
{
	SBCheckError(SBHTTPSClient_TElStringValue_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

SBHTTPSClient_TElStringValue::SBHTTPSClient_TElStringValue(SBHTTPSClient_TElStringValueHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

SBHTTPSClient_TElStringValue::SBHTTPSClient_TElStringValue(const std::string &Value) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(SBHTTPSClient_TElStringValue_Create(Value.data(), (int32_t)Value.length(), &_Handle));
}

#endif /* SB_USE_CLASS_SBHTTPSCLIENT_TELSTRINGVALUE */

};	/* namespace SecureBlackbox */
