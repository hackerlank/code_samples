#include "sbsamlserviceprovider.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSAMLSPSESSION

SB_INLINE void TElSAMLSPSession::Generate(int32_t TTL)
{
	SBCheckError(TElSAMLSPSession_Generate(_Handle, TTL));
}

TSBSAMLSPStage TElSAMLSPSession::get_Stage()
{
	TSBSAMLSPStageRaw OutResultRaw = 0;
	SBCheckError(TElSAMLSPSession_get_Stage(_Handle, &OutResultRaw));
	return (TSBSAMLSPStage)OutResultRaw;
}

SB_INLINE void TElSAMLSPSession::set_Stage(TSBSAMLSPStage Value)
{
	SBCheckError(TElSAMLSPSession_set_Stage(_Handle, (TSBSAMLSPStageRaw)Value));
}

void TElSAMLSPSession::get_SAMLSession(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSPSession_get_SAMLSession(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2027473726, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSPSession::set_SAMLSession(const std::string &Value)
{
	SBCheckError(TElSAMLSPSession_set_SAMLSession(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLSPSession::get_AuthnRequestID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSPSession_get_AuthnRequestID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(383902417, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSPSession::set_AuthnRequestID(const std::string &Value)
{
	SBCheckError(TElSAMLSPSession_set_AuthnRequestID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLSPSession::get_LogoutRequestID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSPSession_get_LogoutRequestID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-731126010, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSPSession::set_LogoutRequestID(const std::string &Value)
{
	SBCheckError(TElSAMLSPSession_set_LogoutRequestID(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLSPSession::get_SAMLCookieSet()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSPSession_get_SAMLCookieSet(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSPSession::set_SAMLCookieSet(bool Value)
{
	SBCheckError(TElSAMLSPSession_set_SAMLCookieSet(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSAMLID
TElSAMLID* TElSAMLSPSession::get_NameID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSPSession_get_NameID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameID)
		this->_Inst_NameID = new TElSAMLID(hOutResult, ohFalse);
	else
		this->_Inst_NameID->updateHandle(hOutResult);
	return this->_Inst_NameID;
}

SB_INLINE void TElSAMLSPSession::set_NameID(TElSAMLID &Value)
{
	SBCheckError(TElSAMLSPSession_set_NameID(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLSPSession::set_NameID(TElSAMLID *Value)
{
	SBCheckError(TElSAMLSPSession_set_NameID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLID */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLSPSession::get_SessionIndexes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSPSession_get_SessionIndexes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionIndexes)
		this->_Inst_SessionIndexes = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_SessionIndexes->updateHandle(hOutResult);
	return this->_Inst_SessionIndexes;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLSPSession::get_SessionIndexes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSPSession_get_SessionIndexes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionIndexes)
		this->_Inst_SessionIndexes = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_SessionIndexes->updateHandle(hOutResult);
	return this->_Inst_SessionIndexes;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElSAMLSPSession::get_Redirected()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSPSession_get_Redirected(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSPSession::set_Redirected(bool Value)
{
	SBCheckError(TElSAMLSPSession_set_Redirected(_Handle, (int8_t)Value));
}

void TElSAMLSPSession::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLID
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_SessionIndexes = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_SessionIndexes = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSAMLSPSession::TElSAMLSPSession(TElSAMLSPSessionHandle handle, TElOwnHandle ownHandle) : TElSAMLSession(handle, ownHandle)
{
	initInstances();
}

TElSAMLSPSession::TElSAMLSPSession() : TElSAMLSession(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSPSession_Create(&_Handle));
}

TElSAMLSPSession::~TElSAMLSPSession()
{
#ifdef SB_USE_CLASS_TELSAMLID
	delete this->_Inst_NameID;
	this->_Inst_NameID = NULL;
#endif /* SB_USE_CLASS_TELSAMLID */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_SessionIndexes;
	this->_Inst_SessionIndexes = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_SessionIndexes;
	this->_Inst_SessionIndexes = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSAMLSPSESSION */

#ifdef SB_USE_CLASS_TELSAMLREQUESTRESULT

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLDOMDocument* TElSAMLRequestResult::get_Doc()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRequestResult_get_Doc(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Doc)
		this->_Inst_Doc = new TElXMLDOMDocument(hOutResult, ohFalse);
	else
		this->_Inst_Doc->updateHandle(hOutResult);
	return this->_Inst_Doc;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE
TElSAMLStatusResponseType* TElSAMLRequestResult::get_Response()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRequestResult_get_Response(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Response)
		this->_Inst_Response = new TElSAMLStatusResponseType(hOutResult, ohFalse);
	else
		this->_Inst_Response->updateHandle(hOutResult);
	return this->_Inst_Response;
}
#endif /* SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE */

void TElSAMLRequestResult::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	this->_Inst_Doc = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE
	this->_Inst_Response = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE */
}

TElSAMLRequestResult::TElSAMLRequestResult(TElSAMLRequestResultHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASSES_TELSAMLSTATUSRESPONSETYPE_AND_TELXMLDOMDOCUMENT
TElSAMLRequestResult::TElSAMLRequestResult(TElXMLDOMDocument &Doc, TElSAMLStatusResponseType &Response) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLRequestResult_Create(Doc.getHandle(), Response.getHandle(), &_Handle));
}

TElSAMLRequestResult::TElSAMLRequestResult(TElXMLDOMDocument *Doc, TElSAMLStatusResponseType *Response) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLRequestResult_Create((Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (Response != NULL) ? Response->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELSAMLSTATUSRESPONSETYPE_AND_TELXMLDOMDOCUMENT */

TElSAMLRequestResult::~TElSAMLRequestResult()
{
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	delete this->_Inst_Doc;
	this->_Inst_Doc = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE
	delete this->_Inst_Response;
	this->_Inst_Response = NULL;
#endif /* SB_USE_CLASS_TELSAMLSTATUSRESPONSETYPE */
}
#endif /* SB_USE_CLASS_TELSAMLREQUESTRESULT */

#ifdef SB_USE_CLASS_TELSAMLONETIMEUSERECORD

void TElSAMLOneTimeUseRecord::get_ID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLOneTimeUseRecord_get_ID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1213105755, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLOneTimeUseRecord::set_ID(const std::string &Value)
{
	SBCheckError(TElSAMLOneTimeUseRecord_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSAMLOneTimeUseRecord::get_IssueInstant()
{
	int64_t OutResult;
	SBCheckError(TElSAMLOneTimeUseRecord_get_IssueInstant(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLOneTimeUseRecord::set_IssueInstant(int64_t Value)
{
	SBCheckError(TElSAMLOneTimeUseRecord_set_IssueInstant(_Handle, Value));
}

TElSAMLOneTimeUseRecord::TElSAMLOneTimeUseRecord(TElSAMLOneTimeUseRecordHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLOneTimeUseRecord::TElSAMLOneTimeUseRecord() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLOneTimeUseRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLONETIMEUSERECORD */

#ifdef SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE

SB_INLINE void TElSAMLCustomOneTimeUseCache::Lock()
{
	SBCheckError(TElSAMLCustomOneTimeUseCache_Lock(_Handle));
}

SB_INLINE void TElSAMLCustomOneTimeUseCache::Unlock()
{
	SBCheckError(TElSAMLCustomOneTimeUseCache_Unlock(_Handle));
}

SB_INLINE void TElSAMLCustomOneTimeUseCache::Clear()
{
	SBCheckError(TElSAMLCustomOneTimeUseCache_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
SB_INLINE int32_t TElSAMLCustomOneTimeUseCache::Add(TElSAMLAssertionElement &Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLCustomOneTimeUseCache_Add(_Handle, Assertion.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLCustomOneTimeUseCache::Add(TElSAMLAssertionElement *Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLCustomOneTimeUseCache_Add(_Handle, (Assertion != NULL) ? Assertion->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
bool TElSAMLCustomOneTimeUseCache::Find(TElSAMLAssertionElement &Assertion)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLCustomOneTimeUseCache_Find(_Handle, Assertion.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSAMLCustomOneTimeUseCache::Find(TElSAMLAssertionElement *Assertion)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLCustomOneTimeUseCache_Find(_Handle, (Assertion != NULL) ? Assertion->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

TElSAMLCustomOneTimeUseCache::TElSAMLCustomOneTimeUseCache(TElSAMLCustomOneTimeUseCacheHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLCustomOneTimeUseCache::TElSAMLCustomOneTimeUseCache() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLCustomOneTimeUseCache_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE */

#ifdef SB_USE_CLASS_TELSAMLMEMORYONETIMEUSECACHE

SB_INLINE void TElSAMLMemoryOneTimeUseCache::Lock()
{
	SBCheckError(TElSAMLMemoryOneTimeUseCache_Lock(_Handle));
}

SB_INLINE void TElSAMLMemoryOneTimeUseCache::Unlock()
{
	SBCheckError(TElSAMLMemoryOneTimeUseCache_Unlock(_Handle));
}

SB_INLINE void TElSAMLMemoryOneTimeUseCache::Clear()
{
	SBCheckError(TElSAMLMemoryOneTimeUseCache_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
SB_INLINE int32_t TElSAMLMemoryOneTimeUseCache::Add(TElSAMLAssertionElement &Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLMemoryOneTimeUseCache_Add(_Handle, Assertion.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLMemoryOneTimeUseCache::Add(TElSAMLAssertionElement *Assertion)
{
	int32_t OutResult;
	SBCheckError(TElSAMLMemoryOneTimeUseCache_Add(_Handle, (Assertion != NULL) ? Assertion->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

#ifdef SB_USE_CLASS_TELSAMLASSERTIONELEMENT
bool TElSAMLMemoryOneTimeUseCache::Find(TElSAMLAssertionElement &Assertion)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLMemoryOneTimeUseCache_Find(_Handle, Assertion.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSAMLMemoryOneTimeUseCache::Find(TElSAMLAssertionElement *Assertion)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLMemoryOneTimeUseCache_Find(_Handle, (Assertion != NULL) ? Assertion->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSAMLASSERTIONELEMENT */

TElSAMLMemoryOneTimeUseCache::TElSAMLMemoryOneTimeUseCache(TElSAMLMemoryOneTimeUseCacheHandle handle, TElOwnHandle ownHandle) : TElSAMLCustomOneTimeUseCache(handle, ownHandle)
{
}

TElSAMLMemoryOneTimeUseCache::TElSAMLMemoryOneTimeUseCache() : TElSAMLCustomOneTimeUseCache(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLMemoryOneTimeUseCache_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLMEMORYONETIMEUSECACHE */

#ifdef SB_USE_CLASS_TELSAMLSERVICEPROVIDER

SB_INLINE void TElSAMLServiceProvider::LoadMetadata(const std::string &URI)
{
	SBCheckError(TElSAMLServiceProvider_LoadMetadata(_Handle, URI.data(), (int32_t)URI.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSAMLServiceProvider::SaveMetadata(TStream &Strm)
{
	SBCheckError(TElSAMLServiceProvider_SaveMetadata(_Handle, Strm.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::SaveMetadata(TStream *Strm)
{
	SBCheckError(TElSAMLServiceProvider_SaveMetadata(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElSAMLServiceProvider::Open()
{
	SBCheckError(TElSAMLServiceProvider_Open(_Handle));
}

SB_INLINE void TElSAMLServiceProvider::DataAvailable()
{
	SBCheckError(TElSAMLServiceProvider_DataAvailable(_Handle));
}

SB_INLINE void TElSAMLServiceProvider::Close(bool Silent)
{
	SBCheckError(TElSAMLServiceProvider_Close(_Handle, (int8_t)Silent));
}

#ifdef SB_USE_CLASSES_TELSAMLREQUESTABSTRACTTYPE_AND_TELSAMLREQUESTRESULT
SB_INLINE TElSAMLRequestResultHandle TElSAMLServiceProvider::SendRequest(TElSAMLRequestAbstractType &Request)
{
	TElSAMLRequestResultHandle OutResult;
	SBCheckError(TElSAMLServiceProvider_SendRequest(_Handle, Request.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElSAMLRequestResultHandle TElSAMLServiceProvider::SendRequest(TElSAMLRequestAbstractType *Request)
{
	TElSAMLRequestResultHandle OutResult;
	SBCheckError(TElSAMLServiceProvider_SendRequest(_Handle, (Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSAMLREQUESTABSTRACTTYPE_AND_TELSAMLREQUESTRESULT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE int32_t TElSAMLServiceProvider::AddIDPSingleSignOnService(TElSAMLEndpoint &Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_AddIDPSingleSignOnService(_Handle, Endpoint.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProvider::AddIDPSingleSignOnService(TElSAMLEndpoint *Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_AddIDPSingleSignOnService(_Handle, (Endpoint != NULL) ? Endpoint->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE int32_t TElSAMLServiceProvider::AddIDPSingleLogoutService(TElSAMLEndpoint &Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_AddIDPSingleLogoutService(_Handle, Endpoint.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProvider::AddIDPSingleLogoutService(TElSAMLEndpoint *Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_AddIDPSingleLogoutService(_Handle, (Endpoint != NULL) ? Endpoint->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE int32_t TElSAMLServiceProvider::AddIDPArtifactResolutionService(TElSAMLEndpoint &Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_AddIDPArtifactResolutionService(_Handle, Endpoint.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProvider::AddIDPArtifactResolutionService(TElSAMLEndpoint *Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_AddIDPArtifactResolutionService(_Handle, (Endpoint != NULL) ? Endpoint->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
SB_INLINE int32_t TElSAMLServiceProvider::AddIDPAttributeQueryService(TElSAMLEndpoint &Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_AddIDPAttributeQueryService(_Handle, Endpoint.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProvider::AddIDPAttributeQueryService(TElSAMLEndpoint *Endpoint)
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_AddIDPAttributeQueryService(_Handle, (Endpoint != NULL) ? Endpoint->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

SB_INLINE void TElSAMLServiceProvider::RemoveIDPSingleSignOnService(int32_t Index)
{
	SBCheckError(TElSAMLServiceProvider_RemoveIDPSingleSignOnService(_Handle, Index));
}

SB_INLINE void TElSAMLServiceProvider::RemoveIDPSingleLogoutService(int32_t Index)
{
	SBCheckError(TElSAMLServiceProvider_RemoveIDPSingleLogoutService(_Handle, Index));
}

SB_INLINE void TElSAMLServiceProvider::RemoveIDPArtifactResolutionService(int32_t Index)
{
	SBCheckError(TElSAMLServiceProvider_RemoveIDPArtifactResolutionService(_Handle, Index));
}

SB_INLINE void TElSAMLServiceProvider::RemoveIDPAttributeQueryService(int32_t Index)
{
	SBCheckError(TElSAMLServiceProvider_RemoveIDPAttributeQueryService(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELHTTPSSERVER
TElHTTPSServer* TElSAMLServiceProvider::get_Control()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_Control(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Control)
		this->_Inst_Control = new TElHTTPSServer(hOutResult, ohFalse);
	else
		this->_Inst_Control->updateHandle(hOutResult);
	return this->_Inst_Control;
}
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLServiceProvider::get_ProtectedResources()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_ProtectedResources(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProtectedResources)
		this->_Inst_ProtectedResources = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ProtectedResources->updateHandle(hOutResult);
	return this->_Inst_ProtectedResources;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLServiceProvider::get_ProtectedResources()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_ProtectedResources(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProtectedResources)
		this->_Inst_ProtectedResources = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ProtectedResources->updateHandle(hOutResult);
	return this->_Inst_ProtectedResources;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
TElSAMLEndpoint* TElSAMLServiceProvider::get_IDPSingleSignOnServices(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPSingleSignOnServices(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPSingleSignOnServices)
		this->_Inst_IDPSingleSignOnServices = new TElSAMLEndpoint(hOutResult, ohFalse);
	else
		this->_Inst_IDPSingleSignOnServices->updateHandle(hOutResult);
	return this->_Inst_IDPSingleSignOnServices;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
TElSAMLEndpoint* TElSAMLServiceProvider::get_IDPSingleLogoutServices(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPSingleLogoutServices(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPSingleLogoutServices)
		this->_Inst_IDPSingleLogoutServices = new TElSAMLEndpoint(hOutResult, ohFalse);
	else
		this->_Inst_IDPSingleLogoutServices->updateHandle(hOutResult);
	return this->_Inst_IDPSingleLogoutServices;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
TElSAMLEndpoint* TElSAMLServiceProvider::get_IDPArtifactResolutionServices(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPArtifactResolutionServices(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPArtifactResolutionServices)
		this->_Inst_IDPArtifactResolutionServices = new TElSAMLEndpoint(hOutResult, ohFalse);
	else
		this->_Inst_IDPArtifactResolutionServices->updateHandle(hOutResult);
	return this->_Inst_IDPArtifactResolutionServices;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

#ifdef SB_USE_CLASS_TELSAMLENDPOINT
TElSAMLEndpoint* TElSAMLServiceProvider::get_IDPAttributeQueryServices(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPAttributeQueryServices(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPAttributeQueryServices)
		this->_Inst_IDPAttributeQueryServices = new TElSAMLEndpoint(hOutResult, ohFalse);
	else
		this->_Inst_IDPAttributeQueryServices->updateHandle(hOutResult);
	return this->_Inst_IDPAttributeQueryServices;
}
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */

SB_INLINE int32_t TElSAMLServiceProvider::get_IDPSignleSignOnServiceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_get_IDPSignleSignOnServiceCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProvider::get_IDPSingleLogoutServiceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_get_IDPSingleLogoutServiceCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProvider::get_IDPArtifactResolutionServiceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_get_IDPArtifactResolutionServiceCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSAMLServiceProvider::get_IDPAttributeQueryServiceCount()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_get_IDPAttributeQueryServiceCount(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLServiceProvider::get_SourceID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLServiceProvider_get_SourceID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-313494713, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_SourceID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SourceID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSAMLServiceProvider::get_IDPSourceID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLServiceProvider_get_IDPSourceID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(763768788, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_IDPSourceID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPSourceID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElSAMLServiceProvider::get_AutoIDPSourceID()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_AutoIDPSourceID(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLServiceProvider::set_AutoIDPSourceID(bool Value)
{
	SBCheckError(TElSAMLServiceProvider_set_AutoIDPSourceID(_Handle, (int8_t)Value));
}

bool TElSAMLServiceProvider::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSAMLServiceProvider::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLServiceProvider::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SendBufferSize(_Handle, Value));
}

void TElSAMLServiceProvider::get_ServerName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_ServerName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1473456000, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_ServerName(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_ServerName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
TElCustomSessionManager* TElSAMLServiceProvider::get_SessionManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_SessionManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionManager)
		this->_Inst_SessionManager = new TElCustomSessionManager(hOutResult, ohFalse);
	else
		this->_Inst_SessionManager->updateHandle(hOutResult);
	return this->_Inst_SessionManager;
}

SB_INLINE void TElSAMLServiceProvider::set_SessionManager(TElCustomSessionManager &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SessionManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_SessionManager(TElCustomSessionManager *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SessionManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */

#ifdef SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE
TElSAMLCustomOneTimeUseCache* TElSAMLServiceProvider::get_AssertionsOneTimeUseCache()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_AssertionsOneTimeUseCache(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AssertionsOneTimeUseCache)
		this->_Inst_AssertionsOneTimeUseCache = new TElSAMLCustomOneTimeUseCache(hOutResult, ohFalse);
	else
		this->_Inst_AssertionsOneTimeUseCache->updateHandle(hOutResult);
	return this->_Inst_AssertionsOneTimeUseCache;
}

SB_INLINE void TElSAMLServiceProvider::set_AssertionsOneTimeUseCache(TElSAMLCustomOneTimeUseCache &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_AssertionsOneTimeUseCache(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_AssertionsOneTimeUseCache(TElSAMLCustomOneTimeUseCache *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_AssertionsOneTimeUseCache(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE */

void TElSAMLServiceProvider::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-546249886, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_URL(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBSAMLBindingType TElSAMLServiceProvider::get_SPToIDPBinding()
{
	TSBSAMLBindingTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_SPToIDPBinding(_Handle, &OutResultRaw));
	return (TSBSAMLBindingType)OutResultRaw;
}

SB_INLINE void TElSAMLServiceProvider::set_SPToIDPBinding(TSBSAMLBindingType Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SPToIDPBinding(_Handle, (TSBSAMLBindingTypeRaw)Value));
}

TSBSAMLBindingType TElSAMLServiceProvider::get_PrefferedIDPToSPBinding()
{
	TSBSAMLBindingTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_PrefferedIDPToSPBinding(_Handle, &OutResultRaw));
	return (TSBSAMLBindingType)OutResultRaw;
}

SB_INLINE void TElSAMLServiceProvider::set_PrefferedIDPToSPBinding(TSBSAMLBindingType Value)
{
	SBCheckError(TElSAMLServiceProvider_set_PrefferedIDPToSPBinding(_Handle, (TSBSAMLBindingTypeRaw)Value));
}

TSBSAMLBindingTypes TElSAMLServiceProvider::get_SingleLogoutServiceBindings()
{
	TSBSAMLBindingTypesRaw OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_SingleLogoutServiceBindings(_Handle, &OutResultRaw));
	return (TSBSAMLBindingTypes)OutResultRaw;
}

SB_INLINE void TElSAMLServiceProvider::set_SingleLogoutServiceBindings(TSBSAMLBindingTypes Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SingleLogoutServiceBindings(_Handle, (TSBSAMLBindingTypesRaw)Value));
}

TSBSAMLBindingTypes TElSAMLServiceProvider::get_AssertionConsumerServiceBindings()
{
	TSBSAMLBindingTypesRaw OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_AssertionConsumerServiceBindings(_Handle, &OutResultRaw));
	return (TSBSAMLBindingTypes)OutResultRaw;
}

SB_INLINE void TElSAMLServiceProvider::set_AssertionConsumerServiceBindings(TSBSAMLBindingTypes Value)
{
	SBCheckError(TElSAMLServiceProvider_set_AssertionConsumerServiceBindings(_Handle, (TSBSAMLBindingTypesRaw)Value));
}

TSBSAMLBindingTypes TElSAMLServiceProvider::get_ArtifactResolutionServiceBindings()
{
	TSBSAMLBindingTypesRaw OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_ArtifactResolutionServiceBindings(_Handle, &OutResultRaw));
	return (TSBSAMLBindingTypes)OutResultRaw;
}

void TElSAMLServiceProvider::get_MetadataURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_MetadataURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(431635571, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_MetadataURL(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_MetadataURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLServiceProvider::get_AssertionConsumerService(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_AssertionConsumerService(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(623889844, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_AssertionConsumerService(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_AssertionConsumerService(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLServiceProvider::get_SingleLogoutService(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_SingleLogoutService(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-533321819, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_SingleLogoutService(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SingleLogoutService(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLServiceProvider::get_ArtifactResolutionService(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_ArtifactResolutionService(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-947703476, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_ArtifactResolutionService(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_ArtifactResolutionService(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLServiceProvider::get_LogoutPage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_LogoutPage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(351972916, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_LogoutPage(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_LogoutPage(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLServiceProvider::get_Issuer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_Issuer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1169963160, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_Issuer(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_Issuer(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLServiceProvider::get_SessionCookieName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_SessionCookieName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1705694562, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_SessionCookieName(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SessionCookieName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLServiceProvider::get_SAMLSessionCookieName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_SAMLSessionCookieName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(640800212, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_SAMLSessionCookieName(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SAMLSessionCookieName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProvider::get_IDPSigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPSigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPSigningCertificate)
		this->_Inst_IDPSigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_IDPSigningCertificate->updateHandle(hOutResult);
	return this->_Inst_IDPSigningCertificate;
}

SB_INLINE void TElSAMLServiceProvider::set_IDPSigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPSigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_IDPSigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPSigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProvider::get_IDPEncryptionCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPEncryptionCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPEncryptionCertificate)
		this->_Inst_IDPEncryptionCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_IDPEncryptionCertificate->updateHandle(hOutResult);
	return this->_Inst_IDPEncryptionCertificate;
}

SB_INLINE void TElSAMLServiceProvider::set_IDPEncryptionCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPEncryptionCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_IDPEncryptionCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPEncryptionCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProvider::get_IDPMetaSigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPMetaSigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPMetaSigningCertificate)
		this->_Inst_IDPMetaSigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_IDPMetaSigningCertificate->updateHandle(hOutResult);
	return this->_Inst_IDPMetaSigningCertificate;
}

SB_INLINE void TElSAMLServiceProvider::set_IDPMetaSigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPMetaSigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_IDPMetaSigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPMetaSigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElSAMLServiceProvider::get_IDPAllowCreateIdentifier()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_IDPAllowCreateIdentifier(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLServiceProvider::set_IDPAllowCreateIdentifier(bool Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPAllowCreateIdentifier(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSAMLServiceProvider::get_IDPNameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPNameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPNameIDFormats)
		this->_Inst_IDPNameIDFormats = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_IDPNameIDFormats->updateHandle(hOutResult);
	return this->_Inst_IDPNameIDFormats;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSAMLServiceProvider::get_IDPNameIDFormats()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_IDPNameIDFormats(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IDPNameIDFormats)
		this->_Inst_IDPNameIDFormats = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_IDPNameIDFormats->updateHandle(hOutResult);
	return this->_Inst_IDPNameIDFormats;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int32_t TElSAMLServiceProvider::get_IDPNameIDFormatIndex()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_get_IDPNameIDFormatIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLServiceProvider::set_IDPNameIDFormatIndex(int32_t Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPNameIDFormatIndex(_Handle, Value));
}

void TElSAMLServiceProvider::get_IDPPrefferedNameIDFormat(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_IDPPrefferedNameIDFormat(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-776982876, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_IDPPrefferedNameIDFormat(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPPrefferedNameIDFormat(_Handle, Value.data(), (int32_t)Value.length()));
}

SBSAMLServiceProvider_TSBSAMLAccessLevel TElSAMLServiceProvider::get_AccessLevel()
{
	SBSAMLServiceProvider_TSBSAMLAccessLevelRaw OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_AccessLevel(_Handle, &OutResultRaw));
	return (SBSAMLServiceProvider_TSBSAMLAccessLevel)OutResultRaw;
}

SB_INLINE void TElSAMLServiceProvider::set_AccessLevel(SBSAMLServiceProvider_TSBSAMLAccessLevel Value)
{
	SBCheckError(TElSAMLServiceProvider_set_AccessLevel(_Handle, (SBSAMLServiceProvider_TSBSAMLAccessLevelRaw)Value));
}

SB_INLINE int32_t TElSAMLServiceProvider::get_SessionTTL()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_get_SessionTTL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLServiceProvider::set_SessionTTL(int32_t Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SessionTTL(_Handle, Value));
}

SB_INLINE int32_t TElSAMLServiceProvider::get_MaxIssueInstantTimeDiff()
{
	int32_t OutResult;
	SBCheckError(TElSAMLServiceProvider_get_MaxIssueInstantTimeDiff(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLServiceProvider::set_MaxIssueInstantTimeDiff(int32_t Value)
{
	SBCheckError(TElSAMLServiceProvider_set_MaxIssueInstantTimeDiff(_Handle, Value));
}

bool TElSAMLServiceProvider::get_SignAuthnRequests()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_SignAuthnRequests(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLServiceProvider::set_SignAuthnRequests(bool Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SignAuthnRequests(_Handle, (int8_t)Value));
}

bool TElSAMLServiceProvider::get_SignLogoutRequests()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_SignLogoutRequests(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLServiceProvider::set_SignLogoutRequests(bool Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SignLogoutRequests(_Handle, (int8_t)Value));
}

bool TElSAMLServiceProvider::get_SignArtifactResolveRequests()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_SignArtifactResolveRequests(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLServiceProvider::set_SignArtifactResolveRequests(bool Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SignArtifactResolveRequests(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSAMLServiceProvider::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElSAMLServiceProvider::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProvider::get_SigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_SigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificate)
		this->_Inst_SigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificate->updateHandle(hOutResult);
	return this->_Inst_SigningCertificate;
}

SB_INLINE void TElSAMLServiceProvider::set_SigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_SigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProvider::get_EncryptionCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_EncryptionCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionCertificate)
		this->_Inst_EncryptionCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionCertificate->updateHandle(hOutResult);
	return this->_Inst_EncryptionCertificate;
}

SB_INLINE void TElSAMLServiceProvider::set_EncryptionCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_EncryptionCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_EncryptionCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_EncryptionCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSAMLServiceProvider::get_MetaSigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_MetaSigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MetaSigningCertificate)
		this->_Inst_MetaSigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_MetaSigningCertificate->updateHandle(hOutResult);
	return this->_Inst_MetaSigningCertificate;
}

SB_INLINE void TElSAMLServiceProvider::set_MetaSigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_MetaSigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_MetaSigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_MetaSigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElSAMLServiceProvider::get_RedirectOnLogoutPage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_RedirectOnLogoutPage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1483970691, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_RedirectOnLogoutPage(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_RedirectOnLogoutPage(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
TElCustomArtifactStorage* TElSAMLServiceProvider::get_ArtifactStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLServiceProvider_get_ArtifactStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArtifactStorage)
		this->_Inst_ArtifactStorage = new TElCustomArtifactStorage(hOutResult, ohFalse);
	else
		this->_Inst_ArtifactStorage->updateHandle(hOutResult);
	return this->_Inst_ArtifactStorage;
}

SB_INLINE void TElSAMLServiceProvider::set_ArtifactStorage(TElCustomArtifactStorage &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_ArtifactStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLServiceProvider::set_ArtifactStorage(TElCustomArtifactStorage *Value)
{
	SBCheckError(TElSAMLServiceProvider_set_ArtifactStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

bool TElSAMLServiceProvider::get_RedirectToSuppliedResource()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_RedirectToSuppliedResource(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLServiceProvider::set_RedirectToSuppliedResource(bool Value)
{
	SBCheckError(TElSAMLServiceProvider_set_RedirectToSuppliedResource(_Handle, (int8_t)Value));
}

bool TElSAMLServiceProvider::get_SignMetadata()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLServiceProvider_get_SignMetadata(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLServiceProvider::set_SignMetadata(bool Value)
{
	SBCheckError(TElSAMLServiceProvider_set_SignMetadata(_Handle, (int8_t)Value));
}

void TElSAMLServiceProvider::get_IDPEntityID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLServiceProvider_get_IDPEntityID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(901471432, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLServiceProvider::set_IDPEntityID(const std::string &Value)
{
	SBCheckError(TElSAMLServiceProvider_set_IDPEntityID(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElSAMLServiceProvider::get_OnSessionCreate(SBSAMLServiceProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnSessionCreate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnSessionCreate(SBSAMLServiceProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnSessionCreate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnSessionDestroy(SBSAMLServiceProvider_TSBSAMLSessionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnSessionDestroy(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnSessionDestroy(SBSAMLServiceProvider_TSBSAMLSessionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnSessionDestroy(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnLogout(SBSAMLServiceProvider_TSBSAMLLogoutEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnLogout(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnLogout(SBSAMLServiceProvider_TSBSAMLLogoutEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnLogout(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnBeforeHTTPSServerUse(SBXMLSAMLCommon_TSBSAMLBeforeHTTPSServerUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnBeforeHTTPSServerUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnBeforeHTTPSServerUse(SBXMLSAMLCommon_TSBSAMLBeforeHTTPSServerUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnBeforeHTTPSServerUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnBeforeHTTPSClientUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnBeforeHTTPSClientUse(TSBSAMLBeforeHTTPSClientUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnBeforeHTTPSClientUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnRequestPrepared(TSBSAMLRequestPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnRequestPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnRequestPrepared(TSBSAMLRequestPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnRequestPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnResponsePrepared(TSBSAMLResponsePreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnResponsePrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnResponsePrepared(TSBSAMLResponsePreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnResponsePrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnResponseReceived(TSBSAMLResponseReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnResponseReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnResponseReceived(TSBSAMLResponseReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnResponseReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnRequestReceived(TSBSAMLRequestReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnRequestReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnRequestReceived(TSBSAMLRequestReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnRequestReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnChangeSessionStage(TSBSAMLChangeSPSessionStageEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnChangeSessionStage(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnChangeSessionStage(TSBSAMLChangeSPSessionStageEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnChangeSessionStage(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnMetadataPrepared(TSBSAMLMetadataPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnMetadataPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnMetadataPrepared(TSBSAMLMetadataPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnMetadataPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnResourceOpen(TSBSAMLResourceOpenEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnResourceOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnResourceOpen(TSBSAMLResourceOpenEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnResourceOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnResourceRead(TSBSAMLResourceReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnResourceRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnResourceRead(TSBSAMLResourceReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnResourceRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnResourceClose(TSBSAMLResourceCloseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnResourceClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnResourceClose(TSBSAMLResourceCloseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnResourceClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnSend(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnSSLError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnSSLError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnBindingXMLPrepared(TSBSAMLBindingXMLPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnBindingXMLPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnBindingXMLPrepared(TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnBindingXMLPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnBeforeBindingUse(TSBSAMLBeforeBindingUseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnBeforeBindingUse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnBeforeBindingUse(TSBSAMLBeforeBindingUseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnBeforeBindingUse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnChooseMetadataIDPDescriptor(TSBSAMLChooseMetadataDescriptorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnChooseMetadataIDPDescriptor(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnChooseMetadataIDPDescriptor(TSBSAMLChooseMetadataDescriptorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnChooseMetadataIDPDescriptor(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnChooseNameIDPolicy(TSBSAMLChooseNameIDPolicyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnChooseNameIDPolicy(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnChooseNameIDPolicy(TSBSAMLChooseNameIDPolicyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnChooseNameIDPolicy(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnResponderError(TSBSAMLResponderErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnResponderError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnResponderError(TSBSAMLResponderErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnResponderError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLServiceProvider::get_OnResponseStatusCode(TSBSAMLResponseStatusCodeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLServiceProvider_get_OnResponseStatusCode(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLServiceProvider::set_OnResponseStatusCode(TSBSAMLResponseStatusCodeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLServiceProvider_set_OnResponseStatusCode(_Handle, pMethodValue, pDataValue));
}

void TElSAMLServiceProvider::initInstances()
{
#ifdef SB_USE_CLASS_TELHTTPSSERVER
	this->_Inst_Control = NULL;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ProtectedResources = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ProtectedResources = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	this->_Inst_IDPSingleSignOnServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	this->_Inst_IDPSingleLogoutServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	this->_Inst_IDPArtifactResolutionServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	this->_Inst_IDPAttributeQueryServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
	this->_Inst_SessionManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */
#ifdef SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE
	this->_Inst_AssertionsOneTimeUseCache = NULL;
#endif /* SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_IDPSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_IDPEncryptionCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_IDPMetaSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_IDPNameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_IDPNameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_EncryptionCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_MetaSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
	this->_Inst_ArtifactStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */
}

TElSAMLServiceProvider::TElSAMLServiceProvider(TElSAMLServiceProviderHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSAMLServiceProvider::TElSAMLServiceProvider(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLServiceProvider_Create(AOwner.getHandle(), &_Handle));
}

TElSAMLServiceProvider::TElSAMLServiceProvider(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLServiceProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSAMLServiceProvider::~TElSAMLServiceProvider()
{
#ifdef SB_USE_CLASS_TELHTTPSSERVER
	delete this->_Inst_Control;
	this->_Inst_Control = NULL;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ProtectedResources;
	this->_Inst_ProtectedResources = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ProtectedResources;
	this->_Inst_ProtectedResources = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	delete this->_Inst_IDPSingleSignOnServices;
	this->_Inst_IDPSingleSignOnServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	delete this->_Inst_IDPSingleLogoutServices;
	this->_Inst_IDPSingleLogoutServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	delete this->_Inst_IDPArtifactResolutionServices;
	this->_Inst_IDPArtifactResolutionServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELSAMLENDPOINT
	delete this->_Inst_IDPAttributeQueryServices;
	this->_Inst_IDPAttributeQueryServices = NULL;
#endif /* SB_USE_CLASS_TELSAMLENDPOINT */
#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
	delete this->_Inst_SessionManager;
	this->_Inst_SessionManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */
#ifdef SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE
	delete this->_Inst_AssertionsOneTimeUseCache;
	this->_Inst_AssertionsOneTimeUseCache = NULL;
#endif /* SB_USE_CLASS_TELSAMLCUSTOMONETIMEUSECACHE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_IDPSigningCertificate;
	this->_Inst_IDPSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_IDPEncryptionCertificate;
	this->_Inst_IDPEncryptionCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_IDPMetaSigningCertificate;
	this->_Inst_IDPMetaSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_IDPNameIDFormats;
	this->_Inst_IDPNameIDFormats = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_IDPNameIDFormats;
	this->_Inst_IDPNameIDFormats = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SigningCertificate;
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_EncryptionCertificate;
	this->_Inst_EncryptionCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_MetaSigningCertificate;
	this->_Inst_MetaSigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
	delete this->_Inst_ArtifactStorage;
	this->_Inst_ArtifactStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */
}
#endif /* SB_USE_CLASS_TELSAMLSERVICEPROVIDER */

};	/* namespace SecureBlackbox */
