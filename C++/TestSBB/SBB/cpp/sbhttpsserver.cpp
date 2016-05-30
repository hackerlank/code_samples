#include "sbhttpsserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS

SB_INLINE void TElHTTPServerRequestParams::Assign(TPersistent &Source)
{
	SBCheckError(TElHTTPServerRequestParams_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElHTTPServerRequestParams::Assign(TPersistent *Source)
{
	SBCheckError(TElHTTPServerRequestParams_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TObjectHandle TElHTTPServerRequestParams::Clone()
{
	TObjectHandle OutResult;
	SBCheckError(TElHTTPServerRequestParams_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElHTTPServerRequestParams::get_CustomMethod(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPServerRequestParams_get_CustomMethod(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1050929965, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPServerRequestParams::set_CustomMethod(const std::string &Value)
{
	SBCheckError(TElHTTPServerRequestParams_set_CustomMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElHTTPServerRequestParams::get_Expects100Continue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_Expects100Continue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPServerRequestParams::set_Expects100Continue(bool Value)
{
	SBCheckError(TElHTTPServerRequestParams_set_Expects100Continue(_Handle, (int8_t)Value));
}

TSBHTTPVersion TElHTTPServerRequestParams::get_HTTPVersion()
{
	TSBHTTPVersionRaw OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_HTTPVersion(_Handle, &OutResultRaw));
	return (TSBHTTPVersion)OutResultRaw;
}

SB_INLINE void TElHTTPServerRequestParams::set_HTTPVersion(TSBHTTPVersion Value)
{
	SBCheckError(TElHTTPServerRequestParams_set_HTTPVersion(_Handle, (TSBHTTPVersionRaw)Value));
}

bool TElHTTPServerRequestParams::get_KeepAlive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_KeepAlive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPServerRequestParams::set_KeepAlive(bool Value)
{
	SBCheckError(TElHTTPServerRequestParams_set_KeepAlive(_Handle, (int8_t)Value));
}

TSBHTTPMethod TElHTTPServerRequestParams::get_Method()
{
	TSBHTTPMethodRaw OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_Method(_Handle, &OutResultRaw));
	return (TSBHTTPMethod)OutResultRaw;
}

SB_INLINE void TElHTTPServerRequestParams::set_Method(TSBHTTPMethod Value)
{
	SBCheckError(TElHTTPServerRequestParams_set_Method(_Handle, (TSBHTTPMethodRaw)Value));
}

void TElHTTPServerRequestParams::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPServerRequestParams_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1553247309, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPServerRequestParams::set_URL(const std::string &Value)
{
	SBCheckError(TElHTTPServerRequestParams_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElHTTPServerRequestParams::get_Chunked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_Chunked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHTTPServerRequestParams::get_PreferGzip()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_PreferGzip(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHTTPServerRequestParams::get_AcceptGZip()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_AcceptGZip(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHTTPServerRequestParams::get_AcceptDeflate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_AcceptDeflate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHTTPServerRequestParams::get_AcceptChunked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_AcceptChunked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHTTPServerRequestParams::get_AcceptIdentity()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_AcceptIdentity(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElHTTPServerRequestParams::get_AuthMethod(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPServerRequestParams_get_AuthMethod(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(550301345, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElHTTPServerRequestParams::get_RequireAuth()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_RequireAuth(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPServerRequestParams::set_RequireAuth(bool Value)
{
	SBCheckError(TElHTTPServerRequestParams_set_RequireAuth(_Handle, (int8_t)Value));
}

bool TElHTTPServerRequestParams::get_WebSocketRequest()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerRequestParams_get_WebSocketRequest(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElHTTPServerRequestParams::TElHTTPServerRequestParams(TElHTTPServerRequestParamsHandle handle, TElOwnHandle ownHandle) : TElHTTPCustomRequestParams(handle, ownHandle)
{
}

TElHTTPServerRequestParams::TElHTTPServerRequestParams() : TElHTTPCustomRequestParams(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPServerRequestParams_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSERVERRESPONSEPARAMS

SB_INLINE void TElHTTPServerResponseParams::Assign(TPersistent &Source)
{
	SBCheckError(TElHTTPServerResponseParams_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElHTTPServerResponseParams::Assign(TPersistent *Source)
{
	SBCheckError(TElHTTPServerResponseParams_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TObjectHandle TElHTTPServerResponseParams::Clone()
{
	TObjectHandle OutResult;
	SBCheckError(TElHTTPServerResponseParams_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElHTTPServerResponseParams::get_AcceptRanges()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerResponseParams_get_AcceptRanges(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPServerResponseParams::set_AcceptRanges(bool Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_AcceptRanges(_Handle, (int8_t)Value));
}

void TElHTTPServerResponseParams::get_Location(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPServerResponseParams_get_Location(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(372728797, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPServerResponseParams::set_Location(const std::string &Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_Location(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElHTTPServerResponseParams::get_StatusCode()
{
	int32_t OutResult;
	SBCheckError(TElHTTPServerResponseParams_get_StatusCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPServerResponseParams::set_StatusCode(int32_t Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_StatusCode(_Handle, Value));
}

SB_INLINE int64_t TElHTTPServerResponseParams::get_Expires()
{
	int64_t OutResult;
	SBCheckError(TElHTTPServerResponseParams_get_Expires(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPServerResponseParams::set_Expires(int64_t Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_Expires(_Handle, Value));
}

SB_INLINE int64_t TElHTTPServerResponseParams::get_LastModified()
{
	int64_t OutResult;
	SBCheckError(TElHTTPServerResponseParams_get_LastModified(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPServerResponseParams::set_LastModified(int64_t Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_LastModified(_Handle, Value));
}

void TElHTTPServerResponseParams::get_ReasonPhrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPServerResponseParams_get_ReasonPhrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1422587965, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPServerResponseParams::set_ReasonPhrase(const std::string &Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_ReasonPhrase(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPServerResponseParams::get_Server(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPServerResponseParams_get_Server(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-495555636, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPServerResponseParams::set_Server(const std::string &Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_Server(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElHTTPServerResponseParams::get_UseChunkedTransfer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerResponseParams_get_UseChunkedTransfer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPServerResponseParams::set_UseChunkedTransfer(bool Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_UseChunkedTransfer(_Handle, (int8_t)Value));
}

bool TElHTTPServerResponseParams::get_UseCompression()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerResponseParams_get_UseCompression(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPServerResponseParams::set_UseCompression(bool Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_UseCompression(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElHTTPServerResponseParams::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElHTTPServerResponseParams_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPServerResponseParams::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_CompressionLevel(_Handle, Value));
}

bool TElHTTPServerResponseParams::get_UseKeepAlive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerResponseParams_get_UseKeepAlive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPServerResponseParams::set_UseKeepAlive(bool Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_UseKeepAlive(_Handle, (int8_t)Value));
}

bool TElHTTPServerResponseParams::get_WebSocketResponse()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPServerResponseParams_get_WebSocketResponse(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPServerResponseParams::set_WebSocketResponse(bool Value)
{
	SBCheckError(TElHTTPServerResponseParams_set_WebSocketResponse(_Handle, (int8_t)Value));
}

TElHTTPServerResponseParams::TElHTTPServerResponseParams(TElHTTPServerResponseParamsHandle handle, TElOwnHandle ownHandle) : TElHTTPParams(handle, ownHandle)
{
}

TElHTTPServerResponseParams::TElHTTPServerResponseParams() : TElHTTPParams(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPServerResponseParams_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPSERVERRESPONSEPARAMS */

#ifdef SB_USE_CLASS_TELMULTIPARTFORMDATA

SB_INLINE void TElMultipartFormData::Parse(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElMultipartFormData_Parse(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElMultipartFormData::ParseStream(TStream &Stream, const std::string &Boundary)
{
	SBCheckError(TElMultipartFormData_ParseStream(_Handle, Stream.getHandle(), Boundary.data(), (int32_t)Boundary.length()));
}

SB_INLINE void TElMultipartFormData::ParseStream(TStream *Stream, const std::string &Boundary)
{
	SBCheckError(TElMultipartFormData_ParseStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Boundary.data(), (int32_t)Boundary.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElMultipartFormData::get_Headers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMultipartFormData_get_Headers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Headers)
		this->_Inst_Headers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Headers->updateHandle(hOutResult);
	return this->_Inst_Headers;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElMultipartFormData::get_Headers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMultipartFormData_get_Headers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Headers)
		this->_Inst_Headers = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Headers->updateHandle(hOutResult);
	return this->_Inst_Headers;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElMultipartFormData::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMultipartFormData_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1127716300, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElMultipartFormData::get_ContentStartPos()
{
	int64_t OutResult;
	SBCheckError(TElMultipartFormData_get_ContentStartPos(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElMultipartFormData::get_ContentSize()
{
	int64_t OutResult;
	SBCheckError(TElMultipartFormData_get_ContentSize(_Handle, &OutResult));
	return OutResult;
}

bool TElMultipartFormData::get_IsMultipart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultipartFormData_get_IsMultipart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElMultipartFormData::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMultipartFormData_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2129993056, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElMultipartFormData::get_FileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMultipartFormData_get_FileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1935593124, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElMultipartFormData::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElMultipartFormData::TElMultipartFormData(TElMultipartFormDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElMultipartFormData::TElMultipartFormData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMultipartFormData_Create(&_Handle));
}

TElMultipartFormData::~TElMultipartFormData()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Headers;
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Headers;
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELMULTIPARTFORMDATA */

#ifdef SB_USE_CLASS_TELMULTIPARTFORMLIST

SB_INLINE void TElMultipartFormList::Assign(TElMultipartFormData &Src)
{
	SBCheckError(TElMultipartFormList_Assign(_Handle, Src.getHandle()));
}

SB_INLINE void TElMultipartFormList::Assign(TElMultipartFormData *Src)
{
	SBCheckError(TElMultipartFormList_Assign(_Handle, (Src != NULL) ? Src->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS
SB_INLINE void TElMultipartFormList::Parse(TElHTTPServerRequestParams &RequestInfo, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElMultipartFormList_Parse(_Handle, RequestInfo.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElMultipartFormList::Parse(TElHTTPServerRequestParams *RequestInfo, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElMultipartFormList_Parse(_Handle, (RequestInfo != NULL) ? RequestInfo->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}
#endif /* SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS */

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TSTREAM
SB_INLINE void TElMultipartFormList::ParseStream(TElHTTPServerRequestParams &RequestInfo, TStream &Stream)
{
	SBCheckError(TElMultipartFormList_ParseStream(_Handle, RequestInfo.getHandle(), Stream.getHandle()));
}

SB_INLINE void TElMultipartFormList::ParseStream(TElHTTPServerRequestParams *RequestInfo, TStream *Stream)
{
	SBCheckError(TElMultipartFormList_ParseStream(_Handle, (RequestInfo != NULL) ? RequestInfo->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TSTREAM */

TElMultipartFormData* TElMultipartFormList::get_ValuesByName(const std::string &Name)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMultipartFormList_get_ValuesByName(_Handle, Name.data(), (int32_t)Name.length(), &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ValuesByName)
		this->_Inst_ValuesByName = new TElMultipartFormData(hOutResult, ohFalse);
	else
		this->_Inst_ValuesByName->updateHandle(hOutResult);
	return this->_Inst_ValuesByName;
}

TElMultipartFormData* TElMultipartFormList::get_ValuesByFileName(const std::string &Name)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMultipartFormList_get_ValuesByFileName(_Handle, Name.data(), (int32_t)Name.length(), &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ValuesByFileName)
		this->_Inst_ValuesByFileName = new TElMultipartFormData(hOutResult, ohFalse);
	else
		this->_Inst_ValuesByFileName->updateHandle(hOutResult);
	return this->_Inst_ValuesByFileName;
}

TElMultipartFormData* TElMultipartFormList::get_ValuesByIndex(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMultipartFormList_get_ValuesByIndex(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ValuesByIndex)
		this->_Inst_ValuesByIndex = new TElMultipartFormData(hOutResult, ohFalse);
	else
		this->_Inst_ValuesByIndex->updateHandle(hOutResult);
	return this->_Inst_ValuesByIndex;
}

SB_INLINE int32_t TElMultipartFormList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElMultipartFormList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElMultipartFormList::initInstances()
{
	this->_Inst_ValuesByName = NULL;
	this->_Inst_ValuesByFileName = NULL;
	this->_Inst_ValuesByIndex = NULL;
}

TElMultipartFormList::TElMultipartFormList(TElMultipartFormListHandle handle, TElOwnHandle ownHandle) : TElMultipartFormData(handle, ownHandle)
{
	initInstances();
}

TElMultipartFormList::TElMultipartFormList() : TElMultipartFormData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMultipartFormList_Create(&_Handle));
}

TElMultipartFormList::~TElMultipartFormList()
{
	delete this->_Inst_ValuesByName;
	this->_Inst_ValuesByName = NULL;
	delete this->_Inst_ValuesByFileName;
	this->_Inst_ValuesByFileName = NULL;
	delete this->_Inst_ValuesByIndex;
	this->_Inst_ValuesByIndex = NULL;
}
#endif /* SB_USE_CLASS_TELMULTIPARTFORMLIST */

#ifdef SB_USE_CLASS_TELHTTPSSERVER

SB_INLINE void TElHTTPSServer::Open()
{
	SBCheckError(TElHTTPSServer_Open(_Handle));
}

SB_INLINE void TElHTTPSServer::DataAvailable()
{
	SBCheckError(TElHTTPSServer_DataAvailable(_Handle));
}

SB_INLINE void TElHTTPSServer::Send100Continue()
{
	SBCheckError(TElHTTPSServer_Send100Continue(_Handle));
}

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELHTTPSERVERRESPONSEPARAMS
SB_INLINE void TElHTTPSServer::SendResponseHeaders(TElHTTPServerRequestParams &RequestParameters, TElHTTPServerResponseParams &ResponseParameters)
{
	SBCheckError(TElHTTPSServer_SendResponseHeaders(_Handle, RequestParameters.getHandle(), ResponseParameters.getHandle()));
}

SB_INLINE void TElHTTPSServer::SendResponseHeaders(TElHTTPServerRequestParams *RequestParameters, TElHTTPServerResponseParams *ResponseParameters)
{
	SBCheckError(TElHTTPSServer_SendResponseHeaders(_Handle, (RequestParameters != NULL) ? RequestParameters->getHandle() : SB_NULL_HANDLE, (ResponseParameters != NULL) ? ResponseParameters->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELHTTPSERVERRESPONSEPARAMS */

SB_INLINE void TElHTTPSServer::SendResponseData(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElHTTPSServer_SendResponseData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

SB_INLINE void TElHTTPSServer::SendResponseData(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count)
{
	SBCheckError(TElHTTPSServer_SendResponseData_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count));
}

SB_INLINE void TElHTTPSServer::SendResponseData(void * Buffer, int32_t Size)
{
	SBCheckError(TElHTTPSServer_SendResponseData_2(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElHTTPSServer::SendResponseData(TStream &Strm)
{
	SBCheckError(TElHTTPSServer_SendResponseData_3(_Handle, Strm.getHandle()));
}

SB_INLINE void TElHTTPSServer::SendResponseData(TStream *Strm)
{
	SBCheckError(TElHTTPSServer_SendResponseData_3(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElHTTPSServer::ResponseComplete()
{
	SBCheckError(TElHTTPSServer_ResponseComplete(_Handle));
}

SB_INLINE void TElHTTPSServer::Close(bool Silent)
{
	SBCheckError(TElHTTPSServer_Close(_Handle, (int8_t)Silent));
}

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST
SB_INLINE TElMultipartFormListHandle TElHTTPSServer::ParseMultipartFormData(TElHTTPServerRequestParams &RequestParameters, const std::vector<uint8_t> &Buffer)
{
	TElMultipartFormListHandle OutResult;
	SBCheckError(TElHTTPSServer_ParseMultipartFormData(_Handle, RequestParameters.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &OutResult));
	return OutResult;
}

SB_INLINE TElMultipartFormListHandle TElHTTPSServer::ParseMultipartFormData(TElHTTPServerRequestParams *RequestParameters, const std::vector<uint8_t> &Buffer)
{
	TElMultipartFormListHandle OutResult;
	SBCheckError(TElHTTPSServer_ParseMultipartFormData(_Handle, (RequestParameters != NULL) ? RequestParameters->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST */

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST_AND_TSTREAM
SB_INLINE TElMultipartFormListHandle TElHTTPSServer::ParseMultipartFormData(TElHTTPServerRequestParams &RequestParameters, TStream &Strm)
{
	TElMultipartFormListHandle OutResult;
	SBCheckError(TElHTTPSServer_ParseMultipartFormData_1(_Handle, RequestParameters.getHandle(), Strm.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElMultipartFormListHandle TElHTTPSServer::ParseMultipartFormData(TElHTTPServerRequestParams *RequestParameters, TStream *Strm)
{
	TElMultipartFormListHandle OutResult;
	SBCheckError(TElHTTPSServer_ParseMultipartFormData_1(_Handle, (RequestParameters != NULL) ? RequestParameters->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST_AND_TSTREAM
SB_INLINE TElMultipartFormListHandle TElHTTPSServer::ParseMultipartFormData(TElHTTPServerRequestParams &RequestParameters, TStream &Strm, bool LoadData)
{
	TElMultipartFormListHandle OutResult;
	SBCheckError(TElHTTPSServer_ParseMultipartFormData_2(_Handle, RequestParameters.getHandle(), Strm.getHandle(), (int8_t)LoadData, &OutResult));
	return OutResult;
}

SB_INLINE TElMultipartFormListHandle TElHTTPSServer::ParseMultipartFormData(TElHTTPServerRequestParams *RequestParameters, TStream *Strm, bool LoadData)
{
	TElMultipartFormListHandle OutResult;
	SBCheckError(TElHTTPSServer_ParseMultipartFormData_2(_Handle, (RequestParameters != NULL) ? RequestParameters->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (int8_t)LoadData, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELSSLCLASS
SB_INLINE TElSSLClassHandle TElHTTPSServer::GetControl()
{
	TElSSLClassHandle OutResult;
	SBCheckError(TElHTTPSServer_GetControl(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_INLINE void TElHTTPSServer::AddCertTypeHandler(TElSSLCertificateTypeHandler &Handler)
{
	SBCheckError(TElHTTPSServer_AddCertTypeHandler(_Handle, Handler.getHandle()));
}

SB_INLINE void TElHTTPSServer::AddCertTypeHandler(TElSSLCertificateTypeHandler *Handler)
{
	SBCheckError(TElHTTPSServer_AddCertTypeHandler(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_INLINE void TElHTTPSServer::RemoveCertTypeHandler(TElSSLCertificateTypeHandler &Handler)
{
	SBCheckError(TElHTTPSServer_RemoveCertTypeHandler(_Handle, Handler.getHandle()));
}

SB_INLINE void TElHTTPSServer::RemoveCertTypeHandler(TElSSLCertificateTypeHandler *Handler)
{
	SBCheckError(TElHTTPSServer_RemoveCertTypeHandler(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_INLINE TElSSLCertificateTypeHandlerHandle TElHTTPSServer::GetCertTypeHandler(TElSSLCertificateType CertType)
{
	TElSSLCertificateTypeHandlerHandle OutResult;
	SBCheckError(TElHTTPSServer_GetCertTypeHandler(_Handle, (TElSSLCertificateTypeRaw)CertType, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLSERVER
SB_INLINE void TElHTTPSServer::AssignTLSParamsFromTemplate(TElSSLServer &Tpl)
{
	SBCheckError(TElHTTPSServer_AssignTLSParamsFromTemplate(_Handle, Tpl.getHandle()));
}

SB_INLINE void TElHTTPSServer::AssignTLSParamsFromTemplate(TElSSLServer *Tpl)
{
	SBCheckError(TElHTTPSServer_AssignTLSParamsFromTemplate(_Handle, (Tpl != NULL) ? Tpl->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLSERVER */

SB_INLINE void TElHTTPSServer::ConfigureTLS(TSBServerSSLPredefinedConfiguration Configuration)
{
	SBCheckError(TElHTTPSServer_ConfigureTLS(_Handle, (TSBServerSSLPredefinedConfigurationRaw)Configuration));
}

SB_INLINE uint8_t TElHTTPSServer::get_SSLCipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElHTTPSServer_get_SSLCipherSuite(_Handle, &OutResult));
	return OutResult;
}

bool TElHTTPSServer::get_SSLCipherSuites(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLCipherSuites(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_SSLCipherSuites(uint8_t Index, bool Value)
{
	SBCheckError(TElHTTPSServer_set_SSLCipherSuites(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElHTTPSServer::get_SSLCipherSuitePriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElHTTPSServer_get_SSLCipherSuitePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSServer::set_SSLCipherSuitePriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElHTTPSServer_set_SSLCipherSuitePriorities(_Handle, Index, Value));
}

bool TElHTTPSServer::get_SSLCompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLCompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_SSLCompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElHTTPSServer_set_SSLCompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

TSBVersion TElHTTPSServer::get_SSLVersion()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLVersion(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

SB_INLINE uint8_t TElHTTPSServer::get_SSLCompressionAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElHTTPSServer_get_SSLCompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
TElSSLConnectionInfo* TElHTTPSServer::get_SSLConnectionInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSServer_get_SSLConnectionInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSLConnectionInfo)
		this->_Inst_SSLConnectionInfo = new TElSSLConnectionInfo(hOutResult, ohFalse);
	else
		this->_Inst_SSLConnectionInfo->updateHandle(hOutResult);
	return this->_Inst_SSLConnectionInfo;
}
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

bool TElHTTPSServer::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHTTPSServer::get_AllowKeepAlive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_AllowKeepAlive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_AllowKeepAlive(bool Value)
{
	SBCheckError(TElHTTPSServer_set_AllowKeepAlive(_Handle, (int8_t)Value));
}

void TElHTTPSServer::get_AuthRealm(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSServer_get_AuthRealm(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1170929697, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPSServer::set_AuthRealm(const std::string &Value)
{
	SBCheckError(TElHTTPSServer_set_AuthRealm(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElHTTPSServer::get_AuthBasic()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_AuthBasic(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_AuthBasic(bool Value)
{
	SBCheckError(TElHTTPSServer_set_AuthBasic(_Handle, (int8_t)Value));
}

bool TElHTTPSServer::get_AuthDigest()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_AuthDigest(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_AuthDigest(bool Value)
{
	SBCheckError(TElHTTPSServer_set_AuthDigest(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElHTTPSServer::get_AuthDigestExpire()
{
	int32_t OutResult;
	SBCheckError(TElHTTPSServer_get_AuthDigestExpire(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSServer::set_AuthDigestExpire(int32_t Value)
{
	SBCheckError(TElHTTPSServer_set_AuthDigestExpire(_Handle, Value));
}

bool TElHTTPSServer::get_CloseConnectionOnUnauthorizedData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_CloseConnectionOnUnauthorizedData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_CloseConnectionOnUnauthorizedData(bool Value)
{
	SBCheckError(TElHTTPSServer_set_CloseConnectionOnUnauthorizedData(_Handle, (int8_t)Value));
}

bool TElHTTPSServer::get_SendForbiddenAuto()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SendForbiddenAuto(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_SendForbiddenAuto(bool Value)
{
	SBCheckError(TElHTTPSServer_set_SendForbiddenAuto(_Handle, (int8_t)Value));
}

bool TElHTTPSServer::get_SSLMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_SSLMode(bool Value)
{
	SBCheckError(TElHTTPSServer_set_SSLMode(_Handle, (int8_t)Value));
}

bool TElHTTPSServer::get_SSLClientAuthentication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLClientAuthentication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_SSLClientAuthentication(bool Value)
{
	SBCheckError(TElHTTPSServer_set_SSLClientAuthentication(_Handle, (int8_t)Value));
}

TSBAuthenticationLevel TElHTTPSServer::get_SSLAuthenticationLevel()
{
	TSBAuthenticationLevelRaw OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLAuthenticationLevel(_Handle, &OutResultRaw));
	return (TSBAuthenticationLevel)OutResultRaw;
}

SB_INLINE void TElHTTPSServer::set_SSLAuthenticationLevel(TSBAuthenticationLevel Value)
{
	SBCheckError(TElHTTPSServer_set_SSLAuthenticationLevel(_Handle, (TSBAuthenticationLevelRaw)Value));
}

bool TElHTTPSServer::get_SSLForceCertificateChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLForceCertificateChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSServer::set_SSLForceCertificateChain(bool Value)
{
	SBCheckError(TElHTTPSServer_set_SSLForceCertificateChain(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElHTTPSServer::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSServer_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElHTTPSServer::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElHTTPSServer_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSServer::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElHTTPSServer_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
TElSessionPool* TElHTTPSServer::get_SSLSessionPool()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSServer_get_SSLSessionPool(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSLSessionPool)
		this->_Inst_SSLSessionPool = new TElSessionPool(hOutResult, ohFalse);
	else
		this->_Inst_SSLSessionPool->updateHandle(hOutResult);
	return this->_Inst_SSLSessionPool;
}

SB_INLINE void TElHTTPSServer::set_SSLSessionPool(TElSessionPool &Value)
{
	SBCheckError(TElHTTPSServer_set_SSLSessionPool(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSServer::set_SSLSessionPool(TElSessionPool *Value)
{
	SBCheckError(TElHTTPSServer_set_SSLSessionPool(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElHTTPSServer::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSServer_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElHTTPSServer::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElHTTPSServer_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSServer::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElHTTPSServer_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

TSBVersions TElHTTPSServer::get_SSLVersions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLVersions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElHTTPSServer::set_SSLVersions(TSBVersions Value)
{
	SBCheckError(TElHTTPSServer_set_SSLVersions(_Handle, (TSBVersionsRaw)Value));
}

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
TElServerSSLExtensions* TElHTTPSServer::get_SSLExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSServer_get_SSLExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSLExtensions)
		this->_Inst_SSLExtensions = new TElServerSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_SSLExtensions->updateHandle(hOutResult);
	return this->_Inst_SSLExtensions;
}
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
TElCustomSSLExtensions* TElHTTPSServer::get_SSLPeerExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSServer_get_SSLPeerExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSLPeerExtensions)
		this->_Inst_SSLPeerExtensions = new TElCustomSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_SSLPeerExtensions->updateHandle(hOutResult);
	return this->_Inst_SSLPeerExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

TSBSSLOptions TElHTTPSServer::get_SSLOptions()
{
	TSBSSLOptionsRaw OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_SSLOptions(_Handle, &OutResultRaw));
	return (TSBSSLOptions)OutResultRaw;
}

SB_INLINE void TElHTTPSServer::set_SSLOptions(TSBSSLOptions Value)
{
	SBCheckError(TElHTTPSServer_set_SSLOptions(_Handle, (TSBSSLOptionsRaw)Value));
}

TSBRenegotiationAttackPreventionMode TElHTTPSServer::get_RenegotiationAttackPreventionMode()
{
	TSBRenegotiationAttackPreventionModeRaw OutResultRaw = 0;
	SBCheckError(TElHTTPSServer_get_RenegotiationAttackPreventionMode(_Handle, &OutResultRaw));
	return (TSBRenegotiationAttackPreventionMode)OutResultRaw;
}

SB_INLINE void TElHTTPSServer::set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value)
{
	SBCheckError(TElHTTPSServer_set_RenegotiationAttackPreventionMode(_Handle, (TSBRenegotiationAttackPreventionModeRaw)Value));
}

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
TElSRPCredentialStore* TElHTTPSServer::get_SRPCredentialStore()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSServer_get_SRPCredentialStore(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SRPCredentialStore)
		this->_Inst_SRPCredentialStore = new TElSRPCredentialStore(hOutResult, ohFalse);
	else
		this->_Inst_SRPCredentialStore->updateHandle(hOutResult);
	return this->_Inst_SRPCredentialStore;
}

SB_INLINE void TElHTTPSServer::set_SRPCredentialStore(TElSRPCredentialStore &Value)
{
	SBCheckError(TElHTTPSServer_set_SRPCredentialStore(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSServer::set_SRPCredentialStore(TElSRPCredentialStore *Value)
{
	SBCheckError(TElHTTPSServer_set_SRPCredentialStore(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

SB_INLINE void TElHTTPSServer::get_OnGetSrpDb(TSBServerSrpDbNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnGetSrpDb(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnGetSrpDb(TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnGetSrpDb(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnSend(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnData(TSBDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnSSLError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnSSLError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnKeyNeeded(TSBServerKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnKeyNeeded(TSBServerKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnRenegotiationStart(TSBRenegotiationStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnRenegotiationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnRenegotiationStart(TSBRenegotiationStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnRenegotiationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnCertificateURLs(TSBCertificateURLsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnCertificateURLs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnCertificateURLs(TSBCertificateURLsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnCertificateURLs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnPreparedHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnPreparedHeaders(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnPreparedHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnPreparedHeaders(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnRequestHeadersReceived(TSBHTTPRequestHeadersEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnRequestHeadersReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnRequestHeadersReceived(TSBHTTPRequestHeadersEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnRequestHeadersReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnAfterAuthorization(TSBHTTPAfterAuthorizationEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnAfterAuthorization(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnAfterAuthorization(TSBHTTPAfterAuthorizationEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnAfterAuthorization(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnRequestBodyReceived(TSBHTTPRequestBodyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnRequestBodyReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnRequestBodyReceived(TSBHTTPRequestBodyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnRequestBodyReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnGetUserPassword(TSBOnGetUserPasswordEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnGetUserPassword(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnGetUserPassword(TSBOnGetUserPasswordEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnGetUserPassword(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnBeforeWebSocketServerUsed(TSBHTTPBeforeWebSocketServerUsedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnBeforeWebSocketServerUsed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnBeforeWebSocketServerUsed(TSBHTTPBeforeWebSocketServerUsedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnBeforeWebSocketServerUsed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElHTTPSServer::get_OnWebSocketConnectionEstablished(SBHTTPSServer_TSBHTTPWebSocketConnectionEstablishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElHTTPSServer_get_OnWebSocketConnectionEstablished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElHTTPSServer::set_OnWebSocketConnectionEstablished(SBHTTPSServer_TSBHTTPWebSocketConnectionEstablishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElHTTPSServer_set_OnWebSocketConnectionEstablished(_Handle, pMethodValue, pDataValue));
}

void TElHTTPSServer::initInstances()
{
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	this->_Inst_SSLConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
	this->_Inst_SSLSessionPool = NULL;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
	this->_Inst_SSLExtensions = NULL;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	this->_Inst_SSLPeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
	this->_Inst_SRPCredentialStore = NULL;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */
}

TElHTTPSServer::TElHTTPSServer(TElHTTPSServerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElHTTPSServer::TElHTTPSServer(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPSServer_Create(AOwner.getHandle(), &_Handle));
}

TElHTTPSServer::TElHTTPSServer(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPSServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElHTTPSServer::~TElHTTPSServer()
{
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	delete this->_Inst_SSLConnectionInfo;
	this->_Inst_SSLConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
	delete this->_Inst_SSLSessionPool;
	this->_Inst_SSLSessionPool = NULL;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
	delete this->_Inst_SSLExtensions;
	this->_Inst_SSLExtensions = NULL;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	delete this->_Inst_SSLPeerExtensions;
	this->_Inst_SSLPeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
	delete this->_Inst_SRPCredentialStore;
	this->_Inst_SRPCredentialStore = NULL;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */
}
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

#ifdef SB_USE_CLASS_TELDIGESTAUTH

SB_INLINE void TElDigestAuth::Init(const std::string &UserParams)
{
	SBCheckError(TElDigestAuth_Init(_Handle, UserParams.data(), (int32_t)UserParams.length()));
}

void TElDigestAuth::CalcHash(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDigestAuth_CalcHash(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1928485436, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDigestAuth::get_Nonce(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDigestAuth_get_Nonce(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1024403189, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDigestAuth::set_Nonce(const std::string &Value)
{
	SBCheckError(TElDigestAuth_set_Nonce(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDigestAuth::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDigestAuth_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-369553194, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDigestAuth::set_Password(const std::string &Value)
{
	SBCheckError(TElDigestAuth_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDigestAuth::get_RequestMethod(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDigestAuth_get_RequestMethod(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-460508610, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDigestAuth::set_RequestMethod(const std::string &Value)
{
	SBCheckError(TElDigestAuth_set_RequestMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDigestAuth::get_RequestURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDigestAuth_get_RequestURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-562501640, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDigestAuth::set_RequestURI(const std::string &Value)
{
	SBCheckError(TElDigestAuth_set_RequestURI(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDigestAuth::get_Response(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDigestAuth_get_Response(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-499098120, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDigestAuth::set_Response(const std::string &Value)
{
	SBCheckError(TElDigestAuth_set_Response(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDigestAuth::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDigestAuth_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2074607798, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDigestAuth::set_UserName(const std::string &Value)
{
	SBCheckError(TElDigestAuth_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDigestAuth::TElDigestAuth(TElDigestAuthHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDigestAuth::TElDigestAuth() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDigestAuth_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDIGESTAUTH */

#ifdef SB_USE_GLOBAL_PROCS_HTTPSSERVER

void GetDefaultReasonPhrase(int32_t ResponseCode, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBHTTPSServer_GetDefaultReasonPhrase(ResponseCode, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1066204037, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_HTTPSSERVER */

};	/* namespace SecureBlackbox */
