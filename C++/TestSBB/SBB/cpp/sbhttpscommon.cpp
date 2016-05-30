#include "sbhttpscommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS

bool TElHTTPSClientParams::get_DoReconnect()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClientParams_get_DoReconnect(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClientParams::set_DoReconnect(bool Value)
{
	SBCheckError(TElHTTPSClientParams_set_DoReconnect(_Handle, (int8_t)Value));
}

bool TElHTTPSClientParams::get_IntoDataRedirection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClientParams_get_IntoDataRedirection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClientParams::set_IntoDataRedirection(bool Value)
{
	SBCheckError(TElHTTPSClientParams_set_IntoDataRedirection(_Handle, (int8_t)Value));
}

void TElHTTPSClientParams::get_RelocationURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClientParams_get_RelocationURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(910926359, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPSClientParams::set_RelocationURL(const std::string &Value)
{
	SBCheckError(TElHTTPSClientParams_set_RelocationURL(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElHTTPSClientParams::get_RequestMethod()
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClientParams_get_RequestMethod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSClientParams::set_RequestMethod(int32_t Value)
{
	SBCheckError(TElHTTPSClientParams_set_RequestMethod(_Handle, Value));
}

SB_INLINE int64_t TElHTTPSClientParams::get_ContentLength()
{
	int64_t OutResult;
	SBCheckError(TElHTTPSClientParams_get_ContentLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSClientParams::set_ContentLength(int64_t Value)
{
	SBCheckError(TElHTTPSClientParams_set_ContentLength(_Handle, Value));
}

void TElHTTPSClientParams::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClientParams_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1465799918, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPSClientParams::set_ContentType(const std::string &Value)
{
	SBCheckError(TElHTTPSClientParams_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSBOBJECTLIST
TSBObjectList* TElHTTPSClientParams::get_SentStreams()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClientParams_get_SentStreams(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SentStreams)
		this->_Inst_SentStreams = new TSBObjectList(hOutResult, ohFalse);
	else
		this->_Inst_SentStreams->updateHandle(hOutResult);
	return this->_Inst_SentStreams;
}

SB_INLINE void TElHTTPSClientParams::set_SentStreams(TSBObjectList &Value)
{
	SBCheckError(TElHTTPSClientParams_set_SentStreams(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSClientParams::set_SentStreams(TSBObjectList *Value)
{
	SBCheckError(TElHTTPSClientParams_set_SentStreams(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

#ifdef SB_USE_CLASS_TSBOBJECTLIST
TSBObjectList* TElHTTPSClientParams::get_DataStreams()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPSClientParams_get_DataStreams(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataStreams)
		this->_Inst_DataStreams = new TSBObjectList(hOutResult, ohFalse);
	else
		this->_Inst_DataStreams->updateHandle(hOutResult);
	return this->_Inst_DataStreams;
}

SB_INLINE void TElHTTPSClientParams::set_DataStreams(TSBObjectList &Value)
{
	SBCheckError(TElHTTPSClientParams_set_DataStreams(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPSClientParams::set_DataStreams(TSBObjectList *Value)
{
	SBCheckError(TElHTTPSClientParams_set_DataStreams(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

bool TElHTTPSClientParams::get_AllowRedirection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPSClientParams_get_AllowRedirection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPSClientParams::set_AllowRedirection(bool Value)
{
	SBCheckError(TElHTTPSClientParams_set_AllowRedirection(_Handle, (int8_t)Value));
}

void TElHTTPSClientParams::get_NewURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClientParams_get_NewURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1104098786, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPSClientParams::set_NewURL(const std::string &Value)
{
	SBCheckError(TElHTTPSClientParams_set_NewURL(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElHTTPSClientParams::get_ServerStatusCode()
{
	int32_t OutResult;
	SBCheckError(TElHTTPSClientParams_get_ServerStatusCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPSClientParams::set_ServerStatusCode(int32_t Value)
{
	SBCheckError(TElHTTPSClientParams_set_ServerStatusCode(_Handle, Value));
}

void TElHTTPSClientParams::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPSClientParams_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(339165224, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPSClientParams::set_URL(const std::string &Value)
{
	SBCheckError(TElHTTPSClientParams_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPSClientParams::initInstances()
{
#ifdef SB_USE_CLASS_TSBOBJECTLIST
	this->_Inst_SentStreams = NULL;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
#ifdef SB_USE_CLASS_TSBOBJECTLIST
	this->_Inst_DataStreams = NULL;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
}

TElHTTPSClientParams::TElHTTPSClientParams(TElHTTPSClientParamsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElHTTPSClientParams::TElHTTPSClientParams() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPSClientParams_Create(&_Handle));
}

TElHTTPSClientParams::~TElHTTPSClientParams()
{
#ifdef SB_USE_CLASS_TSBOBJECTLIST
	delete this->_Inst_SentStreams;
	this->_Inst_SentStreams = NULL;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
#ifdef SB_USE_CLASS_TSBOBJECTLIST
	delete this->_Inst_DataStreams;
	this->_Inst_DataStreams = NULL;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELCUSTOMSAMLADAPTER

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
SB_INLINE void TElCustomSAMLAdapter::HandleDocumentEnd(TElHTTPSClientParams &Param)
{
	SBCheckError(TElCustomSAMLAdapter_HandleDocumentEnd(_Handle, Param.getHandle()));
}

SB_INLINE void TElCustomSAMLAdapter::HandleDocumentEnd(TElHTTPSClientParams *Param)
{
	SBCheckError(TElCustomSAMLAdapter_HandleDocumentEnd(_Handle, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
SB_INLINE void TElCustomSAMLAdapter::HandlePerformExchange(TElHTTPSClientParams &Param)
{
	SBCheckError(TElCustomSAMLAdapter_HandlePerformExchange(_Handle, Param.getHandle()));
}

SB_INLINE void TElCustomSAMLAdapter::HandlePerformExchange(TElHTTPSClientParams *Param)
{
	SBCheckError(TElCustomSAMLAdapter_HandlePerformExchange(_Handle, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
SB_INLINE void TElCustomSAMLAdapter::HandleRedirection(TElHTTPSClientParams &Param)
{
	SBCheckError(TElCustomSAMLAdapter_HandleRedirection(_Handle, Param.getHandle()));
}

SB_INLINE void TElCustomSAMLAdapter::HandleRedirection(TElHTTPSClientParams *Param)
{
	SBCheckError(TElCustomSAMLAdapter_HandleRedirection(_Handle, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

SB_INLINE void TElCustomSAMLAdapter::HandleReadyData(const std::vector<uint8_t> &Buf)
{
	SBCheckError(TElCustomSAMLAdapter_HandleReadyData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size()));
}

SB_INLINE void TElCustomSAMLAdapter::Reset()
{
	SBCheckError(TElCustomSAMLAdapter_Reset(_Handle));
}

TElCustomSAMLAdapter::TElCustomSAMLAdapter(TElCustomSAMLAdapterHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomSAMLAdapter::TElCustomSAMLAdapter() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomSAMLAdapter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMSAMLADAPTER */

#ifdef SB_USE_CLASS_TELHTTPRANGES

SB_INLINE void TElHTTPRanges::Assign(TPersistent &Source)
{
	SBCheckError(TElHTTPRanges_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElHTTPRanges::Assign(TPersistent *Source)
{
	SBCheckError(TElHTTPRanges_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TObjectHandle TElHTTPRanges::Clone()
{
	TObjectHandle OutResult;
	SBCheckError(TElHTTPRanges_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPRanges::get_RangeCount()
{
	int32_t OutResult;
	SBCheckError(TElHTTPRanges_get_RangeCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPRanges::set_RangeCount(int32_t Value)
{
	SBCheckError(TElHTTPRanges_set_RangeCount(_Handle, Value));
}

SB_INLINE int64_t TElHTTPRanges::get_RangeEnd(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElHTTPRanges_get_RangeEnd(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPRanges::set_RangeEnd(int32_t Index, int64_t Value)
{
	SBCheckError(TElHTTPRanges_set_RangeEnd(_Handle, Index, Value));
}

SB_INLINE int64_t TElHTTPRanges::get_RangeStart(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElHTTPRanges_get_RangeStart(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPRanges::set_RangeStart(int32_t Index, int64_t Value)
{
	SBCheckError(TElHTTPRanges_set_RangeStart(_Handle, Index, Value));
}

TElHTTPRanges::TElHTTPRanges(TElHTTPRangesHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElHTTPRanges::TElHTTPRanges() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPRanges_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPRANGES */

#ifdef SB_USE_CLASS_TELHTTPPARAMS

SB_INLINE void TElHTTPParams::Assign(TPersistent &Source)
{
	SBCheckError(TElHTTPParams_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElHTTPParams::Assign(TPersistent *Source)
{
	SBCheckError(TElHTTPParams_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TObjectHandle TElHTTPParams::Clone()
{
	TObjectHandle OutResult;
	SBCheckError(TElHTTPParams_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElHTTPParams::get_ContentLength()
{
	int64_t OutResult;
	SBCheckError(TElHTTPParams_get_ContentLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPParams::set_ContentLength(int64_t Value)
{
	SBCheckError(TElHTTPParams_set_ContentLength(_Handle, Value));
}

SB_INLINE int64_t TElHTTPParams::get_ContentRangeStart()
{
	int64_t OutResult;
	SBCheckError(TElHTTPParams_get_ContentRangeStart(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPParams::set_ContentRangeStart(int64_t Value)
{
	SBCheckError(TElHTTPParams_set_ContentRangeStart(_Handle, Value));
}

SB_INLINE int64_t TElHTTPParams::get_ContentRangeEnd()
{
	int64_t OutResult;
	SBCheckError(TElHTTPParams_get_ContentRangeEnd(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPParams::set_ContentRangeEnd(int64_t Value)
{
	SBCheckError(TElHTTPParams_set_ContentRangeEnd(_Handle, Value));
}

SB_INLINE int64_t TElHTTPParams::get_ContentRangeFullSize()
{
	int64_t OutResult;
	SBCheckError(TElHTTPParams_get_ContentRangeFullSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPParams::set_ContentRangeFullSize(int64_t Value)
{
	SBCheckError(TElHTTPParams_set_ContentRangeFullSize(_Handle, Value));
}

void TElHTTPParams::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPParams_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1578828936, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPParams::set_ContentType(const std::string &Value)
{
	SBCheckError(TElHTTPParams_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElHTTPParams::get_Cookies()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPParams_get_Cookies(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Cookies)
		this->_Inst_Cookies = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Cookies->updateHandle(hOutResult);
	return this->_Inst_Cookies;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElHTTPParams::get_Cookies()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPParams_get_Cookies(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Cookies)
		this->_Inst_Cookies = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Cookies->updateHandle(hOutResult);
	return this->_Inst_Cookies;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElHTTPParams::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPParams_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElHTTPParams::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPParams_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int64_t TElHTTPParams::get_Date()
{
	int64_t OutResult;
	SBCheckError(TElHTTPParams_get_Date(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPParams::set_Date(int64_t Value)
{
	SBCheckError(TElHTTPParams_set_Date(_Handle, Value));
}

void TElHTTPParams::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Cookies = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Cookies = NULL;
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
}

TElHTTPParams::TElHTTPParams(TElHTTPParamsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElHTTPParams::TElHTTPParams() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPParams_Create(&_Handle));
}

TElHTTPParams::~TElHTTPParams()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Cookies;
	this->_Inst_Cookies = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Cookies;
	this->_Inst_Cookies = NULL;
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
}
#endif /* SB_USE_CLASS_TELHTTPPARAMS */

#ifdef SB_USE_CLASS_TELHTTPCUSTOMREQUESTPARAMS

SB_INLINE void TElHTTPCustomRequestParams::Assign(TPersistent &Source)
{
	SBCheckError(TElHTTPCustomRequestParams_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElHTTPCustomRequestParams::Assign(TPersistent *Source)
{
	SBCheckError(TElHTTPCustomRequestParams_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TObjectHandle TElHTTPCustomRequestParams::Clone()
{
	TObjectHandle OutResult;
	SBCheckError(TElHTTPCustomRequestParams_Clone(_Handle, &OutResult));
	return OutResult;
}

void TElHTTPCustomRequestParams::get_Accept(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_Accept(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-394053977, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_Accept(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_Accept(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_AcceptCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_AcceptCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1490518578, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_AcceptCharset(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_AcceptCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_AcceptLanguage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_AcceptLanguage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1556850657, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_AcceptLanguage(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_AcceptLanguage(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELHTTPRANGES
TElHTTPRanges* TElHTTPCustomRequestParams::get_AcceptRanges()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPCustomRequestParams_get_AcceptRanges(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AcceptRanges)
		this->_Inst_AcceptRanges = new TElHTTPRanges(hOutResult, ohFalse);
	else
		this->_Inst_AcceptRanges->updateHandle(hOutResult);
	return this->_Inst_AcceptRanges;
}
#endif /* SB_USE_CLASS_TELHTTPRANGES */

void TElHTTPCustomRequestParams::get_Authorization(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_Authorization(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1783871801, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_Authorization(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_Authorization(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_Connection(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_Connection(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1594449847, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_Connection(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_Connection(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_IfMatch(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_IfMatch(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1693931077, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_IfMatch(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_IfMatch(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElHTTPCustomRequestParams::get_IfModifiedSince()
{
	int64_t OutResult;
	SBCheckError(TElHTTPCustomRequestParams_get_IfModifiedSince(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPCustomRequestParams::set_IfModifiedSince(int64_t Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_IfModifiedSince(_Handle, Value));
}

void TElHTTPCustomRequestParams::get_IfNoneMatch(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_IfNoneMatch(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1590968394, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_IfNoneMatch(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_IfNoneMatch(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElHTTPCustomRequestParams::get_IfUnmodifiedSince()
{
	int64_t OutResult;
	SBCheckError(TElHTTPCustomRequestParams_get_IfUnmodifiedSince(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPCustomRequestParams::set_IfUnmodifiedSince(int64_t Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_IfUnmodifiedSince(_Handle, Value));
}

void TElHTTPCustomRequestParams::get_From(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_From(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1360409200, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_From(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_From(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-219505234, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_Username(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1064754444, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_Password(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_Referer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_Referer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-293357523, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_Referer(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_Referer(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_UserAgent(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_UserAgent(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-303448531, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_UserAgent(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_UserAgent(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPCustomRequestParams_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-657162467, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPCustomRequestParams::set_Host(const std::string &Value)
{
	SBCheckError(TElHTTPCustomRequestParams_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPCustomRequestParams::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPRANGES
	this->_Inst_AcceptRanges = NULL;
#endif /* SB_USE_CLASS_TELHTTPRANGES */
}

TElHTTPCustomRequestParams::TElHTTPCustomRequestParams(TElHTTPCustomRequestParamsHandle handle, TElOwnHandle ownHandle) : TElHTTPParams(handle, ownHandle)
{
	initInstances();
}

TElHTTPCustomRequestParams::TElHTTPCustomRequestParams() : TElHTTPParams(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPCustomRequestParams_Create(&_Handle));
}

TElHTTPCustomRequestParams::~TElHTTPCustomRequestParams()
{
#ifdef SB_USE_CLASS_TELHTTPRANGES
	delete this->_Inst_AcceptRanges;
	this->_Inst_AcceptRanges = NULL;
#endif /* SB_USE_CLASS_TELHTTPRANGES */
}
#endif /* SB_USE_CLASS_TELHTTPCUSTOMREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART

void TElHTTPMultipartPart::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPMultipartPart_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-331243583, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPMultipartPart::set_ContentType(const std::string &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPMultipartPart::get_ContentTransferEncoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPMultipartPart_get_ContentTransferEncoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(405152931, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPMultipartPart::set_ContentTransferEncoding(const std::string &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_ContentTransferEncoding(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElHTTPMultipartPart::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPMultipartPart_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElHTTPMultipartPart::get_CustomHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPMultipartPart_get_CustomHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomHeaders)
		this->_Inst_CustomHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_CustomHeaders->updateHandle(hOutResult);
	return this->_Inst_CustomHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElHTTPMultipartPart::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPMultipartPart_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElHTTPMultipartPart::set_Stream(TStream &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElHTTPMultipartPart::set_Stream(TStream *Value)
{
	SBCheckError(TElHTTPMultipartPart_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElHTTPMultipartPart::get_CloseStream()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPMultipartPart_get_CloseStream(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPMultipartPart::set_CloseStream(bool Value)
{
	SBCheckError(TElHTTPMultipartPart_set_CloseStream(_Handle, (int8_t)Value));
}

void TElHTTPMultipartPart::get_FieldName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPMultipartPart_get_FieldName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1817070622, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPMultipartPart::set_FieldName(const std::string &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_FieldName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPMultipartPart::get_FieldValue(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPMultipartPart_get_FieldValue(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1759445781, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPMultipartPart::set_FieldValue(const std::string &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_FieldValue(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPMultipartPart::get_Filename(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPMultipartPart_get_Filename(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1821469398, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPMultipartPart::set_Filename(const std::string &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_Filename(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPMultipartPart::get_ContentID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPMultipartPart_get_ContentID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-923451957, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPMultipartPart::set_ContentID(const std::string &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_ContentID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPMultipartPart::get_ContentDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPMultipartPart_get_ContentDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1426893875, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPMultipartPart::set_ContentDescription(const std::string &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_ContentDescription(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPMultipartPart::get_ContentDisposition(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPMultipartPart_get_ContentDisposition(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1957712757, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHTTPMultipartPart::set_ContentDisposition(const std::string &Value)
{
	SBCheckError(TElHTTPMultipartPart_set_ContentDisposition(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElHTTPMultipartPart::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_CustomHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElHTTPMultipartPart::TElHTTPMultipartPart(TElHTTPMultipartPartHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElHTTPMultipartPart::TElHTTPMultipartPart() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPMultipartPart_Create(&_Handle));
}

TElHTTPMultipartPart::~TElHTTPMultipartPart()
{
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
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST

SB_INLINE int32_t TElHTTPMultipartList::AddFormField(const std::string &FieldName, const std::string &FieldValue)
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_AddFormField(_Handle, FieldName.data(), (int32_t)FieldName.length(), FieldValue.data(), (int32_t)FieldValue.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElHTTPMultipartList::AddFormFile(const std::string &FieldName, const std::string &Filename, const std::string &ContentType, TStream &FileStream, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_AddFormFile(_Handle, FieldName.data(), (int32_t)FieldName.length(), Filename.data(), (int32_t)Filename.length(), ContentType.data(), (int32_t)ContentType.length(), FileStream.getHandle(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPMultipartList::AddFormFile(const std::string &FieldName, const std::string &Filename, const std::string &ContentType, TStream *FileStream, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_AddFormFile(_Handle, FieldName.data(), (int32_t)FieldName.length(), Filename.data(), (int32_t)Filename.length(), ContentType.data(), (int32_t)ContentType.length(), (FileStream != NULL) ? FileStream->getHandle() : SB_NULL_HANDLE, (int8_t)CloseStream, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElHTTPMultipartList::AddContentStream(const std::string &ContentID, const std::string &ContentType, TStream &AStream, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_AddContentStream(_Handle, ContentID.data(), (int32_t)ContentID.length(), ContentType.data(), (int32_t)ContentType.length(), AStream.getHandle(), (int8_t)CloseStream, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPMultipartList::AddContentStream(const std::string &ContentID, const std::string &ContentType, TStream *AStream, bool CloseStream)
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_AddContentStream(_Handle, ContentID.data(), (int32_t)ContentID.length(), ContentType.data(), (int32_t)ContentType.length(), (AStream != NULL) ? AStream->getHandle() : SB_NULL_HANDLE, (int8_t)CloseStream, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElHTTPMultipartList::Add()
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_Add(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
SB_INLINE int32_t TElHTTPMultipartList::Add(TElHTTPMultipartPart &APart)
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_Add_1(_Handle, APart.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHTTPMultipartList::Add(TElHTTPMultipartPart *APart)
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_Add_1(_Handle, (APart != NULL) ? APart->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
SB_INLINE void TElHTTPMultipartList::Insert(int32_t Index, TElHTTPMultipartPart &APart)
{
	SBCheckError(TElHTTPMultipartList_Insert(_Handle, Index, APart.getHandle()));
}

SB_INLINE void TElHTTPMultipartList::Insert(int32_t Index, TElHTTPMultipartPart *APart)
{
	SBCheckError(TElHTTPMultipartList_Insert(_Handle, Index, (APart != NULL) ? APart->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

SB_INLINE void TElHTTPMultipartList::Delete(int32_t Index)
{
	SBCheckError(TElHTTPMultipartList_Delete(_Handle, Index));
}

SB_INLINE void TElHTTPMultipartList::Clear()
{
	SBCheckError(TElHTTPMultipartList_Clear(_Handle));
}

SB_INLINE int32_t TElHTTPMultipartList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElHTTPMultipartList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
TElHTTPMultipartPart* TElHTTPMultipartList::get_Parts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHTTPMultipartList_get_Parts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parts)
		this->_Inst_Parts = new TElHTTPMultipartPart(hOutResult, ohFalse);
	else
		this->_Inst_Parts->updateHandle(hOutResult);
	return this->_Inst_Parts;
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

void TElHTTPMultipartList::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
	this->_Inst_Parts = NULL;
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */
}

TElHTTPMultipartList::TElHTTPMultipartList(TElHTTPMultipartListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElHTTPMultipartList::TElHTTPMultipartList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHTTPMultipartList_Create(&_Handle));
}

TElHTTPMultipartList::~TElHTTPMultipartList()
{
#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
	delete this->_Inst_Parts;
	this->_Inst_Parts = NULL;
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */
}
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPENCODINGPROCESSOR

SB_INLINE void TElHTTPEncodingProcessor::Initialize(bool AsEncoder)
{
	SBCheckError(TElHTTPEncodingProcessor_Initialize(_Handle, (int8_t)AsEncoder));
}

void TElHTTPEncodingProcessor::DecodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, int32_t &Processed, bool &EndReached, std::vector<uint8_t> &OutResult)
{
	int8_t EndReachedRaw = (int8_t)EndReached;
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHTTPEncodingProcessor_DecodeData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, &Processed, &EndReachedRaw, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-633398217, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	EndReached = (EndReachedRaw != 0);
	OutResult.resize(szOutResult);
}

void TElHTTPEncodingProcessor::EncodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHTTPEncodingProcessor_EncodeData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(489817321, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElHTTPEncodingProcessor::get_BytesEncoded()
{
	int64_t OutResult;
	SBCheckError(TElHTTPEncodingProcessor_get_BytesEncoded(_Handle, &OutResult));
	return OutResult;
}

TElHTTPEncodingProcessor::TElHTTPEncodingProcessor(TElHTTPEncodingProcessorHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElHTTPEncodingProcessor::TElHTTPEncodingProcessor() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPEncodingProcessor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPENCODINGPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPCHUNKEDPROCESSOR

SB_INLINE void TElHTTPChunkedProcessor::Initialize(bool AsEncoder)
{
	SBCheckError(TElHTTPChunkedProcessor_Initialize(_Handle, (int8_t)AsEncoder));
}

void TElHTTPChunkedProcessor::DecodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, int32_t &Processed, bool &EndReached, std::vector<uint8_t> &OutResult)
{
	int8_t EndReachedRaw = (int8_t)EndReached;
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHTTPChunkedProcessor_DecodeData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, &Processed, &EndReachedRaw, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-123412968, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	EndReached = (EndReachedRaw != 0);
	OutResult.resize(szOutResult);
}

void TElHTTPChunkedProcessor::EncodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHTTPChunkedProcessor_EncodeData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(355460841, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHTTPChunkedProcessor::EncodeLastData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHTTPChunkedProcessor_EncodeLastData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-516511120, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElHTTPChunkedProcessor::TElHTTPChunkedProcessor(TElHTTPChunkedProcessorHandle handle, TElOwnHandle ownHandle) : TElHTTPEncodingProcessor(handle, ownHandle)
{
}

TElHTTPChunkedProcessor::TElHTTPChunkedProcessor() : TElHTTPEncodingProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPChunkedProcessor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPCHUNKEDPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPCOMPRESSEDPROCESSOR

SB_INLINE void TElHTTPCompressedProcessor::Initialize(bool AsEncoder)
{
	SBCheckError(TElHTTPCompressedProcessor_Initialize(_Handle, (int8_t)AsEncoder));
}

SB_INLINE void TElHTTPCompressedProcessor::Reset()
{
	SBCheckError(TElHTTPCompressedProcessor_Reset(_Handle));
}

void TElHTTPCompressedProcessor::DecodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, int32_t &Processed, bool &EndReached, std::vector<uint8_t> &OutResult)
{
	int8_t EndReachedRaw = (int8_t)EndReached;
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHTTPCompressedProcessor_DecodeData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, &Processed, &EndReachedRaw, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(267199522, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	EndReached = (EndReachedRaw != 0);
	OutResult.resize(szOutResult);
}

void TElHTTPCompressedProcessor::EncodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHTTPCompressedProcessor_EncodeData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1515715728, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElHTTPCompressedProcessor::get_Deflated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPCompressedProcessor_get_Deflated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPCompressedProcessor::set_Deflated(bool Value)
{
	SBCheckError(TElHTTPCompressedProcessor_set_Deflated(_Handle, (int8_t)Value));
}

bool TElHTTPCompressedProcessor::get_Gzipped()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHTTPCompressedProcessor_get_Gzipped(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElHTTPCompressedProcessor::set_Gzipped(bool Value)
{
	SBCheckError(TElHTTPCompressedProcessor_set_Gzipped(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElHTTPCompressedProcessor::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElHTTPCompressedProcessor_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHTTPCompressedProcessor::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElHTTPCompressedProcessor_set_CompressionLevel(_Handle, Value));
}

TElHTTPCompressedProcessor::TElHTTPCompressedProcessor(TElHTTPCompressedProcessorHandle handle, TElOwnHandle ownHandle) : TElHTTPEncodingProcessor(handle, ownHandle)
{
}

TElHTTPCompressedProcessor::TElHTTPCompressedProcessor() : TElHTTPEncodingProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPCompressedProcessor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPCOMPRESSEDPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPUTILS

void TElHTTPUtils::DateTimeToHTTPTime(int64_t D, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_DateTimeToHTTPTime(D, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-501271202, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHTTPUtils::DateTimeToHTTPTime_Inst(int64_t D, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_DateTimeToHTTPTime_1(_Handle, D, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-501271202, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElHTTPUtils::HTTPTimeToDateTime(const std::string &S)
{
	int64_t OutResult;
	SBCheckError(TElHTTPUtils_HTTPTimeToDateTime(S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElHTTPUtils::HTTPTimeToDateTime_Inst(const std::string &S)
{
	int64_t OutResult;
	SBCheckError(TElHTTPUtils_HTTPTimeToDateTime_1(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElHTTPUtils::SetHeaderByName(TStringList &Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPUtils_SetHeaderByName(Headers.getHandle(), Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElHTTPUtils::SetHeaderByName(TStringList *Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPUtils_SetHeaderByName((Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElHTTPUtils::SetHeaderByName(TElStringList &Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPUtils_SetHeaderByName(Headers.getHandle(), Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElHTTPUtils::SetHeaderByName(TElStringList *Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPUtils_SetHeaderByName((Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElHTTPUtils::SetHeaderByName_Inst(TStringList &Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPUtils_SetHeaderByName_1(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElHTTPUtils::SetHeaderByName_Inst(TStringList *Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPUtils_SetHeaderByName_1(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElHTTPUtils::SetHeaderByName_Inst(TElStringList &Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPUtils_SetHeaderByName_1(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElHTTPUtils::SetHeaderByName_Inst(TElStringList *Headers, const std::string &Header, const std::string &Value)
{
	SBCheckError(TElHTTPUtils_SetHeaderByName_1(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElHTTPUtils::GetHeaderByName(TStringList &Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_GetHeaderByName(Headers.getHandle(), Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(273106011, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHTTPUtils::GetHeaderByName(TStringList *Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_GetHeaderByName((Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(273106011, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElHTTPUtils::GetHeaderByName(TElStringList &Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_GetHeaderByName(Headers.getHandle(), Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1832581725, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHTTPUtils::GetHeaderByName(TElStringList *Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_GetHeaderByName((Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1832581725, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElHTTPUtils::GetHeaderByName_Inst(TStringList &Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_GetHeaderByName_1(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(273106011, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHTTPUtils::GetHeaderByName_Inst(TStringList *Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_GetHeaderByName_1(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(273106011, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElHTTPUtils::GetHeaderByName_Inst(TElStringList &Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_GetHeaderByName_1(_Handle, Headers.getHandle(), Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1832581725, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHTTPUtils::GetHeaderByName_Inst(TElStringList *Headers, const std::string &Header, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHTTPUtils_GetHeaderByName_1(_Handle, (Headers != NULL) ? Headers->getHandle() : SB_NULL_HANDLE, Header.data(), (int32_t)Header.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1832581725, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElHTTPUtils::MergeHeaders(TStringList &Source, TStringList &Target)
{
	SBCheckError(TElHTTPUtils_MergeHeaders(Source.getHandle(), Target.getHandle()));
}

SB_INLINE void TElHTTPUtils::MergeHeaders(TStringList *Source, TStringList *Target)
{
	SBCheckError(TElHTTPUtils_MergeHeaders((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Target != NULL) ? Target->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElHTTPUtils::MergeHeaders(TElStringList &Source, TElStringList &Target)
{
	SBCheckError(TElHTTPUtils_MergeHeaders(Source.getHandle(), Target.getHandle()));
}

SB_INLINE void TElHTTPUtils::MergeHeaders(TElStringList *Source, TElStringList *Target)
{
	SBCheckError(TElHTTPUtils_MergeHeaders((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Target != NULL) ? Target->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElHTTPUtils::MergeHeaders_Inst(TStringList &Source, TStringList &Target)
{
	SBCheckError(TElHTTPUtils_MergeHeaders_1(_Handle, Source.getHandle(), Target.getHandle()));
}

SB_INLINE void TElHTTPUtils::MergeHeaders_Inst(TStringList *Source, TStringList *Target)
{
	SBCheckError(TElHTTPUtils_MergeHeaders_1(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Target != NULL) ? Target->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElHTTPUtils::MergeHeaders_Inst(TElStringList &Source, TElStringList &Target)
{
	SBCheckError(TElHTTPUtils_MergeHeaders_1(_Handle, Source.getHandle(), Target.getHandle()));
}

SB_INLINE void TElHTTPUtils::MergeHeaders_Inst(TElStringList *Source, TElStringList *Target)
{
	SBCheckError(TElHTTPUtils_MergeHeaders_1(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Target != NULL) ? Target->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TElHTTPUtils::TElHTTPUtils(TElHTTPUtilsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElHTTPUtils::TElHTTPUtils() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHTTPUtils_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHTTPUTILS */

#ifdef SB_USE_GLOBAL_PROCS_HTTPSCOMMON

bool HTTPHeaderGetDelimiter(const std::vector<uint8_t> &Header, int32_t Index, int32_t Length, std::vector<uint8_t> &Delimiter, int32_t &EndHeaderIndex)
{
	int32_t szDelimiter = (int32_t)Delimiter.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBHTTPSCommon_HTTPHeaderGetDelimiter(SB_STD_VECTOR_FRONT_ADR(Header), (int32_t)Header.size(), Index, Length, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Delimiter), &szDelimiter, &EndHeaderIndex, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Delimiter.resize(szDelimiter);
		SBCheckError(SBGetLastReturnBuffer(569562451, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Delimiter), &szDelimiter));
	}
	else
		SBCheckError(_err);

	Delimiter.resize(szDelimiter);
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_HTTPSCOMMON */

};	/* namespace SecureBlackbox */
