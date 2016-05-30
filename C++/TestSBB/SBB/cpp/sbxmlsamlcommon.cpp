#include "sbxmlsamlcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSAMLCLIENTSETTINGS

SB_INLINE void TElSAMLClientSettings::Reset()
{
	SBCheckError(TElSAMLClientSettings_Reset(_Handle));
}

bool TElSAMLClientSettings::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLClientSettings_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLClientSettings::set_Enabled(bool Value)
{
	SBCheckError(TElSAMLClientSettings_set_Enabled(_Handle, (int8_t)Value));
}

TSBSAMLClientProfiles TElSAMLClientSettings::get_Profiles()
{
	TSBSAMLClientProfilesRaw OutResultRaw = 0;
	SBCheckError(TElSAMLClientSettings_get_Profiles(_Handle, &OutResultRaw));
	return (TSBSAMLClientProfiles)OutResultRaw;
}

SB_INLINE void TElSAMLClientSettings::set_Profiles(TSBSAMLClientProfiles Value)
{
	SBCheckError(TElSAMLClientSettings_set_Profiles(_Handle, (TSBSAMLClientProfilesRaw)Value));
}

TSBSAMLClientState TElSAMLClientSettings::get_State()
{
	TSBSAMLClientStateRaw OutResultRaw = 0;
	SBCheckError(TElSAMLClientSettings_get_State(_Handle, &OutResultRaw));
	return (TSBSAMLClientState)OutResultRaw;
}

SB_INLINE void TElSAMLClientSettings::set_State(TSBSAMLClientState Value)
{
	SBCheckError(TElSAMLClientSettings_set_State(_Handle, (TSBSAMLClientStateRaw)Value));
}

void TElSAMLClientSettings::get_Proto(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLClientSettings_get_Proto(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1204872647, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLClientSettings::set_Proto(const std::string &Value)
{
	SBCheckError(TElSAMLClientSettings_set_Proto(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLClientSettings::get_IdPURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLClientSettings_get_IdPURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(276895558, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLClientSettings::set_IdPURL(const std::string &Value)
{
	SBCheckError(TElSAMLClientSettings_set_IdPURL(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLClientSettings::get_WebSSOEnabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLClientSettings_get_WebSSOEnabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElSAMLClientSettings::TElSAMLClientSettings(TElSAMLClientSettingsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLClientSettings::TElSAMLClientSettings() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLClientSettings_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLCLIENTSETTINGS */

#ifdef SB_USE_CLASS_TELSAMLSESSION

SB_INLINE void TElSAMLSession::Generate(int32_t TTL)
{
	SBCheckError(TElSAMLSession_Generate(_Handle, TTL));
}

void TElSAMLSession::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSession_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-60097589, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSession::set_URL(const std::string &Value)
{
	SBCheckError(TElSAMLSession_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLSession::get_Session(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSession_get_Session(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(486089150, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSession::set_Session(const std::string &Value)
{
	SBCheckError(TElSAMLSession_set_Session(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLSession::get_CookieSet()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLSession_get_CookieSet(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLSession::set_CookieSet(bool Value)
{
	SBCheckError(TElSAMLSession_set_CookieSet(_Handle, (int8_t)Value));
}

void TElSAMLSession::get_RelayState(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSession_get_RelayState(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1511727574, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLSession::set_RelayState(const std::string &Value)
{
	SBCheckError(TElSAMLSession_set_RelayState(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
TElSAMLRequestAbstractType* TElSAMLSession::get_Request()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLSession_get_Request(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Request)
		this->_Inst_Request = new TElSAMLRequestAbstractType(hOutResult, ohFalse);
	else
		this->_Inst_Request->updateHandle(hOutResult);
	return this->_Inst_Request;
}

SB_INLINE void TElSAMLSession::set_Request(TElSAMLRequestAbstractType &Value)
{
	SBCheckError(TElSAMLSession_set_Request(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLSession::set_Request(TElSAMLRequestAbstractType *Value)
{
	SBCheckError(TElSAMLSession_set_Request(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

SB_INLINE int64_t TElSAMLSession::get_Expires()
{
	int64_t OutResult;
	SBCheckError(TElSAMLSession_get_Expires(_Handle, &OutResult));
	return OutResult;
}

void TElSAMLSession::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
	this->_Inst_Request = NULL;
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */
}

TElSAMLSession::TElSAMLSession(TElSAMLSessionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSAMLSession::TElSAMLSession() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLSession_Create(&_Handle));
}

TElSAMLSession::~TElSAMLSession()
{
#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
	delete this->_Inst_Request;
	this->_Inst_Request = NULL;
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER

SB_INLINE void TElCustomSessionManager::Lock()
{
	SBCheckError(TElCustomSessionManager_Lock(_Handle));
}

SB_INLINE void TElCustomSessionManager::Unlock()
{
	SBCheckError(TElCustomSessionManager_Unlock(_Handle));
}

SB_INLINE void TElCustomSessionManager::Clear()
{
	SBCheckError(TElCustomSessionManager_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_INLINE int32_t TElCustomSessionManager::Add(TElSAMLSession &Session)
{
	int32_t OutResult;
	SBCheckError(TElCustomSessionManager_Add(_Handle, Session.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomSessionManager::Add(TElSAMLSession *Session)
{
	int32_t OutResult;
	SBCheckError(TElCustomSessionManager_Add(_Handle, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_INLINE TElSAMLSessionHandle TElCustomSessionManager::Remove(int32_t Index)
{
	TElSAMLSessionHandle OutResult;
	SBCheckError(TElCustomSessionManager_Remove(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_INLINE TElSAMLSessionHandle TElCustomSessionManager::Remove(const std::string &Session)
{
	TElSAMLSessionHandle OutResult;
	SBCheckError(TElCustomSessionManager_Remove_1(_Handle, Session.data(), (int32_t)Session.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_INLINE TElSAMLSessionHandle TElCustomSessionManager::Find(const std::string &Session)
{
	TElSAMLSessionHandle OutResult;
	SBCheckError(TElCustomSessionManager_Find(_Handle, Session.data(), (int32_t)Session.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

SB_INLINE int32_t TElCustomSessionManager::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCustomSessionManager_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSAMLSESSION
TElSAMLSession* TElCustomSessionManager::get_Sessions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSessionManager_get_Sessions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Sessions)
		this->_Inst_Sessions = new TElSAMLSession(hOutResult, ohFalse);
	else
		this->_Inst_Sessions->updateHandle(hOutResult);
	return this->_Inst_Sessions;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

void TElCustomSessionManager::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLSESSION
	this->_Inst_Sessions = NULL;
#endif /* SB_USE_CLASS_TELSAMLSESSION */
}

TElCustomSessionManager::TElCustomSessionManager(TElCustomSessionManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCustomSessionManager::TElCustomSessionManager() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomSessionManager_Create(&_Handle));
}

TElCustomSessionManager::~TElCustomSessionManager()
{
#ifdef SB_USE_CLASS_TELSAMLSESSION
	delete this->_Inst_Sessions;
	this->_Inst_Sessions = NULL;
#endif /* SB_USE_CLASS_TELSAMLSESSION */
}
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */

#ifdef SB_USE_CLASS_TELMEMORYSESSIONMANAGER

SB_INLINE void TElMemorySessionManager::Lock()
{
	SBCheckError(TElMemorySessionManager_Lock(_Handle));
}

SB_INLINE void TElMemorySessionManager::Unlock()
{
	SBCheckError(TElMemorySessionManager_Unlock(_Handle));
}

SB_INLINE void TElMemorySessionManager::Clear()
{
	SBCheckError(TElMemorySessionManager_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_INLINE int32_t TElMemorySessionManager::Add(TElSAMLSession &Session)
{
	int32_t OutResult;
	SBCheckError(TElMemorySessionManager_Add(_Handle, Session.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMemorySessionManager::Add(TElSAMLSession *Session)
{
	int32_t OutResult;
	SBCheckError(TElMemorySessionManager_Add(_Handle, (Session != NULL) ? Session->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_INLINE TElSAMLSessionHandle TElMemorySessionManager::Remove(int32_t Index)
{
	TElSAMLSessionHandle OutResult;
	SBCheckError(TElMemorySessionManager_Remove(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_INLINE TElSAMLSessionHandle TElMemorySessionManager::Remove(const std::string &Session)
{
	TElSAMLSessionHandle OutResult;
	SBCheckError(TElMemorySessionManager_Remove_1(_Handle, Session.data(), (int32_t)Session.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_INLINE TElSAMLSessionHandle TElMemorySessionManager::Find(const std::string &Session)
{
	TElSAMLSessionHandle OutResult;
	SBCheckError(TElMemorySessionManager_Find(_Handle, Session.data(), (int32_t)Session.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSAMLSESSION */

TElMemorySessionManager::TElMemorySessionManager(TElMemorySessionManagerHandle handle, TElOwnHandle ownHandle) : TElCustomSessionManager(handle, ownHandle)
{
}

TElMemorySessionManager::TElMemorySessionManager() : TElCustomSessionManager(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMemorySessionManager_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELMEMORYSESSIONMANAGER */

#ifdef SB_USE_CLASS_SBXMLSAMLCOMMON_TELSTRINGVALUE

void SBXMLSAMLCommon_TElStringValue::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCommon_TElStringValue_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1501239362, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SBXMLSAMLCommon_TElStringValue::set_Value(const std::string &Value)
{
	SBCheckError(SBXMLSAMLCommon_TElStringValue_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

SBXMLSAMLCommon_TElStringValue::SBXMLSAMLCommon_TElStringValue(SBXMLSAMLCommon_TElStringValueHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

SBXMLSAMLCommon_TElStringValue::SBXMLSAMLCommon_TElStringValue(const std::string &Value) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(SBXMLSAMLCommon_TElStringValue_Create(Value.data(), (int32_t)Value.length(), &_Handle));
}

#endif /* SB_USE_CLASS_SBXMLSAMLCOMMON_TELSTRINGVALUE */

#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE

SB_INLINE void TElCustomArtifactStorage::Clear()
{
	SBCheckError(TElCustomArtifactStorage_Clear(_Handle));
}

bool TElCustomArtifactStorage::Add(const std::vector<uint8_t> &Handle, const std::string &Body)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomArtifactStorage_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Body.data(), (int32_t)Body.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElCustomArtifactStorage::Get(const std::vector<uint8_t> &Handle, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomArtifactStorage_Get(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1008268664, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElCustomArtifactStorage::TElCustomArtifactStorage(TElCustomArtifactStorageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomArtifactStorage::TElCustomArtifactStorage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomArtifactStorage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYARTIFACTSTORAGE

SB_INLINE void TElMemoryArtifactStorage::Clear()
{
	SBCheckError(TElMemoryArtifactStorage_Clear(_Handle));
}

bool TElMemoryArtifactStorage::Add(const std::vector<uint8_t> &Handle, const std::string &Body)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMemoryArtifactStorage_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Body.data(), (int32_t)Body.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElMemoryArtifactStorage::Get(const std::vector<uint8_t> &Handle, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMemoryArtifactStorage_Get(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1536298407, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElMemoryArtifactStorage::TElMemoryArtifactStorage(TElMemoryArtifactStorageHandle handle, TElOwnHandle ownHandle) : TElCustomArtifactStorage(handle, ownHandle)
{
}

TElMemoryArtifactStorage::TElMemoryArtifactStorage() : TElCustomArtifactStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMemoryArtifactStorage_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELMEMORYARTIFACTSTORAGE */

#ifdef SB_USE_CLASS_TELSAMLADAPTER

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
SB_INLINE void TElSAMLAdapter::HandleDocumentEnd(TElHTTPSClientParams &Param)
{
	SBCheckError(TElSAMLAdapter_HandleDocumentEnd(_Handle, Param.getHandle()));
}

SB_INLINE void TElSAMLAdapter::HandleDocumentEnd(TElHTTPSClientParams *Param)
{
	SBCheckError(TElSAMLAdapter_HandleDocumentEnd(_Handle, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

SB_INLINE void TElSAMLAdapter::Reset()
{
	SBCheckError(TElSAMLAdapter_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
SB_INLINE void TElSAMLAdapter::HandlePerformExchange(TElHTTPSClientParams &Param)
{
	SBCheckError(TElSAMLAdapter_HandlePerformExchange(_Handle, Param.getHandle()));
}

SB_INLINE void TElSAMLAdapter::HandlePerformExchange(TElHTTPSClientParams *Param)
{
	SBCheckError(TElSAMLAdapter_HandlePerformExchange(_Handle, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
SB_INLINE void TElSAMLAdapter::HandleRedirection(TElHTTPSClientParams &Param)
{
	SBCheckError(TElSAMLAdapter_HandleRedirection(_Handle, Param.getHandle()));
}

SB_INLINE void TElSAMLAdapter::HandleRedirection(TElHTTPSClientParams *Param)
{
	SBCheckError(TElSAMLAdapter_HandleRedirection(_Handle, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

SB_INLINE void TElSAMLAdapter::HandleReadyData(const std::vector<uint8_t> &Buf)
{
	SBCheckError(TElSAMLAdapter_HandleReadyData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size()));
}

#ifdef SB_USE_CLASS_TELSAMLCLIENTSETTINGS
TElSAMLClientSettings* TElSAMLAdapter::get_SAMLSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLAdapter_get_SAMLSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SAMLSettings)
		this->_Inst_SAMLSettings = new TElSAMLClientSettings(hOutResult, ohFalse);
	else
		this->_Inst_SAMLSettings->updateHandle(hOutResult);
	return this->_Inst_SAMLSettings;
}
#endif /* SB_USE_CLASS_TELSAMLCLIENTSETTINGS */

SB_INLINE void TElSAMLAdapter::get_OnSAMLStateChanged(TSBHTTPSAMLStateChanged &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLAdapter_get_OnSAMLStateChanged(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLAdapter::set_OnSAMLStateChanged(TSBHTTPSAMLStateChanged pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLAdapter_set_OnSAMLStateChanged(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLAdapter::get_OnSAMLParseForm(TSBSAMLPOSTBindingParseForm &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLAdapter_get_OnSAMLParseForm(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLAdapter::set_OnSAMLParseForm(TSBSAMLPOSTBindingParseForm pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLAdapter_set_OnSAMLParseForm(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLAdapter::get_OnSAMLCredentialsChallenge(TSBHTTPSAMLCredentialsChallenge &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLAdapter_get_OnSAMLCredentialsChallenge(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLAdapter::set_OnSAMLCredentialsChallenge(TSBHTTPSAMLCredentialsChallenge pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLAdapter_set_OnSAMLCredentialsChallenge(_Handle, pMethodValue, pDataValue));
}

void TElSAMLAdapter::initInstances()
{
#ifdef SB_USE_CLASS_TELSAMLCLIENTSETTINGS
	this->_Inst_SAMLSettings = NULL;
#endif /* SB_USE_CLASS_TELSAMLCLIENTSETTINGS */
}

TElSAMLAdapter::TElSAMLAdapter(TElSAMLAdapterHandle handle, TElOwnHandle ownHandle) : TElCustomSAMLAdapter(handle, ownHandle)
{
	initInstances();
}

TElSAMLAdapter::TElSAMLAdapter() : TElCustomSAMLAdapter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLAdapter_Create(&_Handle));
}

TElSAMLAdapter::~TElSAMLAdapter()
{
#ifdef SB_USE_CLASS_TELSAMLCLIENTSETTINGS
	delete this->_Inst_SAMLSettings;
	this->_Inst_SAMLSettings = NULL;
#endif /* SB_USE_CLASS_TELSAMLCLIENTSETTINGS */
}
#endif /* SB_USE_CLASS_TELSAMLADAPTER */

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLCOMMON

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void XMLDocToStr(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCommon_XMLDocToStr(Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-483283538, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void XMLDocToStr(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSAMLCommon_XMLDocToStr((Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-483283538, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLCOMMON */

};	/* namespace SecureBlackbox */

