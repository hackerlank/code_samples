#include "sbwebdavserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWEBDAVSERVER

SB_INLINE void TElWebDAVServer::Open()
{
	SBCheckError(TElWebDAVServer_Open(_Handle));
}

SB_INLINE void TElWebDAVServer::DataAvailable()
{
	SBCheckError(TElWebDAVServer_DataAvailable(_Handle));
}

SB_INLINE void TElWebDAVServer::Close(bool Silent)
{
	SBCheckError(TElWebDAVServer_Close(_Handle, (int8_t)Silent));
}

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
bool TElWebDAVServer::AddProperty(const TElWebDavProperty &Prop)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_AddProperty(_Handle, Prop.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVServer::AddProperty(const TElWebDavProperty *Prop)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_AddProperty(_Handle, (Prop != NULL) ? Prop->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
SB_INLINE TElWebDavPropertyHandle TElWebDAVServer::GetProperty(const std::string &NS, const std::string &Name)
{
	TElWebDavPropertyHandle OutResult;
	SBCheckError(TElWebDAVServer_GetProperty(_Handle, NS.data(), (int32_t)NS.length(), Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
bool TElWebDAVServer::RemoveProperty(const TElWebDavProperty &Prop)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_RemoveProperty(_Handle, Prop.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVServer::RemoveProperty(const TElWebDavProperty *Prop)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_RemoveProperty(_Handle, (Prop != NULL) ? Prop->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

SB_INLINE void TElWebDAVServer::CreateCollection(const std::string &URL)
{
	SBCheckError(TElWebDAVServer_CreateCollection(_Handle, URL.data(), (int32_t)URL.length()));
}

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_INLINE void TElWebDAVServer::CreateAddressBook(const std::string &URL, const std::string &Description, SBWebDAVServer_TElWebDavPrincipal &Owner)
{
	SBCheckError(TElWebDAVServer_CreateAddressBook(_Handle, URL.data(), (int32_t)URL.length(), Description.data(), (int32_t)Description.length(), Owner.getHandle()));
}

SB_INLINE void TElWebDAVServer::CreateAddressBook(const std::string &URL, const std::string &Description, SBWebDAVServer_TElWebDavPrincipal *Owner)
{
	SBCheckError(TElWebDAVServer_CreateAddressBook(_Handle, URL.data(), (int32_t)URL.length(), Description.data(), (int32_t)Description.length(), (Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_INLINE void TElWebDAVServer::CreateCalendar(const std::string &URL, const std::string &Description, SBWebDAVServer_TElWebDavPrincipal &Owner)
{
	SBCheckError(TElWebDAVServer_CreateCalendar(_Handle, URL.data(), (int32_t)URL.length(), Description.data(), (int32_t)Description.length(), Owner.getHandle()));
}

SB_INLINE void TElWebDAVServer::CreateCalendar(const std::string &URL, const std::string &Description, SBWebDAVServer_TElWebDavPrincipal *Owner)
{
	SBCheckError(TElWebDAVServer_CreateCalendar(_Handle, URL.data(), (int32_t)URL.length(), Description.data(), (int32_t)Description.length(), (Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVServer::PutVCard(const std::string &URL, TStream &Strm)
{
	SBCheckError(TElWebDAVServer_PutVCard(_Handle, URL.data(), (int32_t)URL.length(), Strm.getHandle()));
}

SB_INLINE void TElWebDAVServer::PutVCard(const std::string &URL, TStream *Strm)
{
	SBCheckError(TElWebDAVServer_PutVCard(_Handle, URL.data(), (int32_t)URL.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELVCARD
SB_INLINE void TElWebDAVServer::PutVCard(const std::string &URL, TElVCard &VCard)
{
	SBCheckError(TElWebDAVServer_PutVCard_1(_Handle, URL.data(), (int32_t)URL.length(), VCard.getHandle()));
}

SB_INLINE void TElWebDAVServer::PutVCard(const std::string &URL, TElVCard *VCard)
{
	SBCheckError(TElWebDAVServer_PutVCard_1(_Handle, URL.data(), (int32_t)URL.length(), (VCard != NULL) ? VCard->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELVCARD */

SB_INLINE void TElWebDAVServer::PutVCard(const std::string &URL, const std::string &FileName)
{
	SBCheckError(TElWebDAVServer_PutVCard_2(_Handle, URL.data(), (int32_t)URL.length(), FileName.data(), (int32_t)FileName.length()));
}

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_INLINE void TElWebDAVServer::AddCertTypeHandler(TElSSLCertificateTypeHandler &Handler)
{
	SBCheckError(TElWebDAVServer_AddCertTypeHandler(_Handle, Handler.getHandle()));
}

SB_INLINE void TElWebDAVServer::AddCertTypeHandler(TElSSLCertificateTypeHandler *Handler)
{
	SBCheckError(TElWebDAVServer_AddCertTypeHandler(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_INLINE void TElWebDAVServer::RemoveCertTypeHandler(TElSSLCertificateTypeHandler &Handler)
{
	SBCheckError(TElWebDAVServer_RemoveCertTypeHandler(_Handle, Handler.getHandle()));
}

SB_INLINE void TElWebDAVServer::RemoveCertTypeHandler(TElSSLCertificateTypeHandler *Handler)
{
	SBCheckError(TElWebDAVServer_RemoveCertTypeHandler(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_INLINE TElSSLCertificateTypeHandlerHandle TElWebDAVServer::GetCertTypeHandler(TElSSLCertificateType CertType)
{
	TElSSLCertificateTypeHandlerHandle OutResult;
	SBCheckError(TElWebDAVServer_GetCertTypeHandler(_Handle, (TElSSLCertificateTypeRaw)CertType, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDAVServer::get_MIMETypesMap()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_MIMETypesMap(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MIMETypesMap)
		this->_Inst_MIMETypesMap = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_MIMETypesMap->updateHandle(hOutResult);
	return this->_Inst_MIMETypesMap;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDAVServer::get_MIMETypesMap()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_MIMETypesMap(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MIMETypesMap)
		this->_Inst_MIMETypesMap = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_MIMETypesMap->updateHandle(hOutResult);
	return this->_Inst_MIMETypesMap;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
TElWebDavProperty* TElWebDAVServer::get_Properties(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_Properties(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Properties)
		this->_Inst_Properties = new TElWebDavProperty(hOutResult, ohFalse);
	else
		this->_Inst_Properties->updateHandle(hOutResult);
	return this->_Inst_Properties;
}
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

SB_INLINE int32_t TElWebDAVServer::get_PropertiesCount()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVServer_get_PropertiesCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELHTTPSSERVER
TElHTTPSServer* TElWebDAVServer::get_Control()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_Control(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Control)
		this->_Inst_Control = new TElHTTPSServer(hOutResult, ohFalse);
	else
		this->_Inst_Control->updateHandle(hOutResult);
	return this->_Inst_Control;
}
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

#ifdef SB_USE_CLASS_TELWEBDAVACLOPTIONS
TElWebDAVACLOptions* TElWebDAVServer::get_ACLOptions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_ACLOptions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ACLOptions)
		this->_Inst_ACLOptions = new TElWebDAVACLOptions(hOutResult, ohFalse);
	else
		this->_Inst_ACLOptions->updateHandle(hOutResult);
	return this->_Inst_ACLOptions;
}
#endif /* SB_USE_CLASS_TELWEBDAVACLOPTIONS */

#ifdef SB_USE_CLASS_TELCARDDAVOPTIONS
TElCardDAVOptions* TElWebDAVServer::get_CardDAVOptions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_CardDAVOptions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CardDAVOptions)
		this->_Inst_CardDAVOptions = new TElCardDAVOptions(hOutResult, ohFalse);
	else
		this->_Inst_CardDAVOptions->updateHandle(hOutResult);
	return this->_Inst_CardDAVOptions;
}
#endif /* SB_USE_CLASS_TELCARDDAVOPTIONS */

#ifdef SB_USE_CLASS_TELCALDAVOPTIONS
TElCalDAVOptions* TElWebDAVServer::get_CalDAVOptions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_CalDAVOptions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CalDAVOptions)
		this->_Inst_CalDAVOptions = new TElCalDAVOptions(hOutResult, ohFalse);
	else
		this->_Inst_CalDAVOptions->updateHandle(hOutResult);
	return this->_Inst_CalDAVOptions;
}
#endif /* SB_USE_CLASS_TELCALDAVOPTIONS */

bool TElWebDAVServer::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDAVServer::get_SSLMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_SSLMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVServer::set_SSLMode(bool Value)
{
	SBCheckError(TElWebDAVServer_set_SSLMode(_Handle, (int8_t)Value));
}

bool TElWebDAVServer::get_SSLClientAuthentication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_SSLClientAuthentication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVServer::set_SSLClientAuthentication(bool Value)
{
	SBCheckError(TElWebDAVServer_set_SSLClientAuthentication(_Handle, (int8_t)Value));
}

TSBAuthenticationLevel TElWebDAVServer::get_SSLAuthenticationLevel()
{
	TSBAuthenticationLevelRaw OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_SSLAuthenticationLevel(_Handle, &OutResultRaw));
	return (TSBAuthenticationLevel)OutResultRaw;
}

SB_INLINE void TElWebDAVServer::set_SSLAuthenticationLevel(TSBAuthenticationLevel Value)
{
	SBCheckError(TElWebDAVServer_set_SSLAuthenticationLevel(_Handle, (TSBAuthenticationLevelRaw)Value));
}

bool TElWebDAVServer::get_SSLForceCertificateChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_SSLForceCertificateChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVServer::set_SSLForceCertificateChain(bool Value)
{
	SBCheckError(TElWebDAVServer_set_SSLForceCertificateChain(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElWebDAVServer::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElWebDAVServer::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElWebDAVServer_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVServer::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElWebDAVServer_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
TElSessionPool* TElWebDAVServer::get_SSLSessionPool()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_SSLSessionPool(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSLSessionPool)
		this->_Inst_SSLSessionPool = new TElSessionPool(hOutResult, ohFalse);
	else
		this->_Inst_SSLSessionPool->updateHandle(hOutResult);
	return this->_Inst_SSLSessionPool;
}

SB_INLINE void TElWebDAVServer::set_SSLSessionPool(TElSessionPool &Value)
{
	SBCheckError(TElWebDAVServer_set_SSLSessionPool(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVServer::set_SSLSessionPool(TElSessionPool *Value)
{
	SBCheckError(TElWebDAVServer_set_SSLSessionPool(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElWebDAVServer::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElWebDAVServer::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElWebDAVServer_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVServer::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElWebDAVServer_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

TSBVersions TElWebDAVServer::get_SSLVersions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_SSLVersions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElWebDAVServer::set_SSLVersions(TSBVersions Value)
{
	SBCheckError(TElWebDAVServer_set_SSLVersions(_Handle, (TSBVersionsRaw)Value));
}

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
TElServerSSLExtensions* TElWebDAVServer::get_SSLExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_SSLExtensions(_Handle, &hOutResult));
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
TElCustomSSLExtensions* TElWebDAVServer::get_SSLPeerExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_SSLPeerExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSLPeerExtensions)
		this->_Inst_SSLPeerExtensions = new TElCustomSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_SSLPeerExtensions->updateHandle(hOutResult);
	return this->_Inst_SSLPeerExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
TElSRPCredentialStore* TElWebDAVServer::get_SSLSRPCredentialStore()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_SSLSRPCredentialStore(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SSLSRPCredentialStore)
		this->_Inst_SSLSRPCredentialStore = new TElSRPCredentialStore(hOutResult, ohFalse);
	else
		this->_Inst_SSLSRPCredentialStore->updateHandle(hOutResult);
	return this->_Inst_SSLSRPCredentialStore;
}

SB_INLINE void TElWebDAVServer::set_SSLSRPCredentialStore(TElSRPCredentialStore &Value)
{
	SBCheckError(TElWebDAVServer_set_SSLSRPCredentialStore(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVServer::set_SSLSRPCredentialStore(TElSRPCredentialStore *Value)
{
	SBCheckError(TElWebDAVServer_set_SSLSRPCredentialStore(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElWebDAVServer::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElWebDAVServer::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElWebDAVServer_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVServer::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElWebDAVServer_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST
TElWebDAVCustomLockList* TElWebDAVServer::get_GlobalLockList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVServer_get_GlobalLockList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GlobalLockList)
		this->_Inst_GlobalLockList = new TElWebDAVCustomLockList(hOutResult, ohFalse);
	else
		this->_Inst_GlobalLockList->updateHandle(hOutResult);
	return this->_Inst_GlobalLockList;
}

SB_INLINE void TElWebDAVServer::set_GlobalLockList(TElWebDAVCustomLockList &Value)
{
	SBCheckError(TElWebDAVServer_set_GlobalLockList(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVServer::set_GlobalLockList(TElWebDAVCustomLockList *Value)
{
	SBCheckError(TElWebDAVServer_set_GlobalLockList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST */

SB_INLINE int32_t TElWebDAVServer::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVServer_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebDAVServer::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElWebDAVServer_set_SendBufferSize(_Handle, Value));
}

SB_INLINE int64_t TElWebDAVServer::get_DefaultLockTimeout()
{
	int64_t OutResult;
	SBCheckError(TElWebDAVServer_get_DefaultLockTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebDAVServer::set_DefaultLockTimeout(int64_t Value)
{
	SBCheckError(TElWebDAVServer_set_DefaultLockTimeout(_Handle, Value));
}

bool TElWebDAVServer::get_AllowInfinity()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_AllowInfinity(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVServer::set_AllowInfinity(bool Value)
{
	SBCheckError(TElWebDAVServer_set_AllowInfinity(_Handle, (int8_t)Value));
}

bool TElWebDAVServer::get_PublishExclusiveLocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_PublishExclusiveLocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVServer::set_PublishExclusiveLocks(bool Value)
{
	SBCheckError(TElWebDAVServer_set_PublishExclusiveLocks(_Handle, (int8_t)Value));
}

bool TElWebDAVServer::get_PublishSharedLocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_PublishSharedLocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVServer::set_PublishSharedLocks(bool Value)
{
	SBCheckError(TElWebDAVServer_set_PublishSharedLocks(_Handle, (int8_t)Value));
}

void TElWebDAVServer::get_ResponseContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVServer_get_ResponseContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-691375627, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDAVServer::set_ResponseContentType(const std::string &Value)
{
	SBCheckError(TElWebDAVServer_set_ResponseContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElWebDAVServer::get_MicrosoftCompatible()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_MicrosoftCompatible(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVServer::set_MicrosoftCompatible(bool Value)
{
	SBCheckError(TElWebDAVServer_set_MicrosoftCompatible(_Handle, (int8_t)Value));
}

void TElWebDAVServer::get_ServerName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVServer_get_ServerName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-609983871, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDAVServer::set_ServerName(const std::string &Value)
{
	SBCheckError(TElWebDAVServer_set_ServerName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElWebDAVServer::get_UseWellKnownURIs()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVServer_get_UseWellKnownURIs(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVServer::set_UseWellKnownURIs(bool Value)
{
	SBCheckError(TElWebDAVServer_set_UseWellKnownURIs(_Handle, (int8_t)Value));
}

SB_INLINE void TElWebDAVServer::get_OnGetSrpDb(TSBServerSrpDbNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnGetSrpDb(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnGetSrpDb(TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnGetSrpDb(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnBeforeRequest(TSBWebDavBeforeRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnBeforeRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnBeforeRequest(TSBWebDavBeforeRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnBeforeRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnRequest(TSBWebDavRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnRequest(TSBWebDavRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnResponse(TSBWebDavResponseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnResponse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnResponse(TSBWebDavResponseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnResponse(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnStatusCode(TSBWebDavStatusCodeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnStatusCode(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnStatusCode(TSBWebDavStatusCodeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnStatusCode(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnBeforeUpload(TSBWebDavBeforeUploadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnBeforeUpload(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnBeforeUpload(TSBWebDavBeforeUploadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnBeforeUpload(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnBeforeDownload(TSBWebDavBeforeDownloadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnBeforeDownload(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnBeforeDownload(TSBWebDavBeforeDownloadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnBeforeDownload(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnTransferFinished(TSBWebDavTransferFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnTransferFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnTransferFinished(TSBWebDavTransferFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnTransferFinished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnGetUserPassword(TSBOnGetUserPasswordEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnGetUserPassword(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnGetUserPassword(TSBOnGetUserPasswordEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnGetUserPassword(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnSend(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnSSLError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnSSLError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnKeyNeeded(TSBServerKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnKeyNeeded(TSBServerKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnRenegotiationStart(TSBRenegotiationStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnRenegotiationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnRenegotiationStart(TSBRenegotiationStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnRenegotiationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVServer::get_OnCertificateURLs(TSBCertificateURLsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVServer_get_OnCertificateURLs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVServer::set_OnCertificateURLs(TSBCertificateURLsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVServer_set_OnCertificateURLs(_Handle, pMethodValue, pDataValue));
}

void TElWebDAVServer::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_MIMETypesMap = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_MIMETypesMap = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */
#ifdef SB_USE_CLASS_TELHTTPSSERVER
	this->_Inst_Control = NULL;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_USE_CLASS_TELWEBDAVACLOPTIONS
	this->_Inst_ACLOptions = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVACLOPTIONS */
#ifdef SB_USE_CLASS_TELCARDDAVOPTIONS
	this->_Inst_CardDAVOptions = NULL;
#endif /* SB_USE_CLASS_TELCARDDAVOPTIONS */
#ifdef SB_USE_CLASS_TELCALDAVOPTIONS
	this->_Inst_CalDAVOptions = NULL;
#endif /* SB_USE_CLASS_TELCALDAVOPTIONS */
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
	this->_Inst_SSLSRPCredentialStore = NULL;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST
	this->_Inst_GlobalLockList = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST */
}

TElWebDAVServer::TElWebDAVServer(TElWebDAVServerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElWebDAVServer::TElWebDAVServer(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVServer_Create(AOwner.getHandle(), &_Handle));
}

TElWebDAVServer::TElWebDAVServer(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWebDAVServer::~TElWebDAVServer()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_MIMETypesMap;
	this->_Inst_MIMETypesMap = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_MIMETypesMap;
	this->_Inst_MIMETypesMap = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
	delete this->_Inst_Properties;
	this->_Inst_Properties = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */
#ifdef SB_USE_CLASS_TELHTTPSSERVER
	delete this->_Inst_Control;
	this->_Inst_Control = NULL;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_USE_CLASS_TELWEBDAVACLOPTIONS
	delete this->_Inst_ACLOptions;
	this->_Inst_ACLOptions = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVACLOPTIONS */
#ifdef SB_USE_CLASS_TELCARDDAVOPTIONS
	delete this->_Inst_CardDAVOptions;
	this->_Inst_CardDAVOptions = NULL;
#endif /* SB_USE_CLASS_TELCARDDAVOPTIONS */
#ifdef SB_USE_CLASS_TELCALDAVOPTIONS
	delete this->_Inst_CalDAVOptions;
	this->_Inst_CalDAVOptions = NULL;
#endif /* SB_USE_CLASS_TELCALDAVOPTIONS */
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
	delete this->_Inst_SSLSRPCredentialStore;
	this->_Inst_SSLSRPCredentialStore = NULL;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST
	delete this->_Inst_GlobalLockList;
	this->_Inst_GlobalLockList = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST */
}
#endif /* SB_USE_CLASS_TELWEBDAVSERVER */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL

bool SBWebDAVServer_TElWebDavPrincipal::MemberOf(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_MemberOf(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBWebDAVServer_TElWebDavPrincipal::AddToGroup(SBWebDAVServer_TElWebDavPrincipal &Principal)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_AddToGroup(_Handle, Principal.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBWebDAVServer_TElWebDavPrincipal::AddToGroup(SBWebDAVServer_TElWebDavPrincipal *Principal)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_AddToGroup(_Handle, (Principal != NULL) ? Principal->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

void SBWebDAVServer_TElWebDavPrincipal::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVServer_TElWebDavPrincipal_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1965314985, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SBWebDAVServer_TElWebDavPrincipal::set_Username(const std::string &Value)
{
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

void SBWebDAVServer_TElWebDavPrincipal::get_DisplayName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVServer_TElWebDavPrincipal_get_DisplayName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1763303380, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SBWebDAVServer_TElWebDavPrincipal::set_DisplayName(const std::string &Value)
{
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_set_DisplayName(_Handle, Value.data(), (int32_t)Value.length()));
}

void SBWebDAVServer_TElWebDavPrincipal::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVServer_TElWebDavPrincipal_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1475568091, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SBWebDAVServer_TElWebDavPrincipal::set_URL(const std::string &Value)
{
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* SBWebDAVServer_TElWebDavPrincipal::get_AlternateURISet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_get_AlternateURISet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AlternateURISet)
		this->_Inst_AlternateURISet = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AlternateURISet->updateHandle(hOutResult);
	return this->_Inst_AlternateURISet;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* SBWebDAVServer_TElWebDavPrincipal::get_AlternateURISet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_get_AlternateURISet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AlternateURISet)
		this->_Inst_AlternateURISet = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AlternateURISet->updateHandle(hOutResult);
	return this->_Inst_AlternateURISet;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* SBWebDAVServer_TElWebDavPrincipal::get_Groups()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_get_Groups(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Groups)
		this->_Inst_Groups = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Groups->updateHandle(hOutResult);
	return this->_Inst_Groups;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* SBWebDAVServer_TElWebDavPrincipal::get_Groups()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_get_Groups(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Groups)
		this->_Inst_Groups = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Groups->updateHandle(hOutResult);
	return this->_Inst_Groups;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool SBWebDAVServer_TElWebDavPrincipal::get_IsGroup()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_get_IsGroup(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void SBWebDAVServer_TElWebDavPrincipal::set_IsGroup(bool Value)
{
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_set_IsGroup(_Handle, (int8_t)Value));
}

void SBWebDAVServer_TElWebDavPrincipal::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVServer_TElWebDavPrincipal_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2132166047, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SBWebDAVServer_TElWebDavPrincipal::set_Address(const std::string &Value)
{
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

void SBWebDAVServer_TElWebDavPrincipal::get_ETag(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBWebDAVServer_TElWebDavPrincipal_get_ETag(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1237418748, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SBWebDAVServer_TElWebDavPrincipal::set_ETag(const std::string &Value)
{
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_set_ETag(_Handle, Value.data(), (int32_t)Value.length()));
}

void SBWebDAVServer_TElWebDavPrincipal::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AlternateURISet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AlternateURISet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Groups = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Groups = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

SBWebDAVServer_TElWebDavPrincipal::SBWebDAVServer_TElWebDavPrincipal(SBWebDAVServer_TElWebDavPrincipalHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

SBWebDAVServer_TElWebDavPrincipal::SBWebDAVServer_TElWebDavPrincipal() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(SBWebDAVServer_TElWebDavPrincipal_Create(&_Handle));
}

SBWebDAVServer_TElWebDavPrincipal::~SBWebDAVServer_TElWebDavPrincipal()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AlternateURISet;
	this->_Inst_AlternateURISet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AlternateURISet;
	this->_Inst_AlternateURISet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Groups;
	this->_Inst_Groups = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Groups;
	this->_Inst_Groups = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVINMEMORYPRINCIPAL

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDavInMemoryPrincipal::get_AddressBookHomeSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavInMemoryPrincipal_get_AddressBookHomeSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressBookHomeSet)
		this->_Inst_AddressBookHomeSet = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AddressBookHomeSet->updateHandle(hOutResult);
	return this->_Inst_AddressBookHomeSet;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDavInMemoryPrincipal::get_AddressBookHomeSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavInMemoryPrincipal_get_AddressBookHomeSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressBookHomeSet)
		this->_Inst_AddressBookHomeSet = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AddressBookHomeSet->updateHandle(hOutResult);
	return this->_Inst_AddressBookHomeSet;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDavInMemoryPrincipal::get_CalendarHomeSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavInMemoryPrincipal_get_CalendarHomeSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CalendarHomeSet)
		this->_Inst_CalendarHomeSet = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_CalendarHomeSet->updateHandle(hOutResult);
	return this->_Inst_CalendarHomeSet;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDavInMemoryPrincipal::get_CalendarHomeSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavInMemoryPrincipal_get_CalendarHomeSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CalendarHomeSet)
		this->_Inst_CalendarHomeSet = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_CalendarHomeSet->updateHandle(hOutResult);
	return this->_Inst_CalendarHomeSet;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElWebDavInMemoryPrincipal::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AddressBookHomeSet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AddressBookHomeSet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_CalendarHomeSet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_CalendarHomeSet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElWebDavInMemoryPrincipal::TElWebDavInMemoryPrincipal(TElWebDavInMemoryPrincipalHandle handle, TElOwnHandle ownHandle) : SBWebDAVServer_TElWebDavPrincipal(handle, ownHandle)
{
	initInstances();
}

TElWebDavInMemoryPrincipal::TElWebDavInMemoryPrincipal() : SBWebDAVServer_TElWebDavPrincipal(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavInMemoryPrincipal_Create(&_Handle));
}

TElWebDavInMemoryPrincipal::~TElWebDavInMemoryPrincipal()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AddressBookHomeSet;
	this->_Inst_AddressBookHomeSet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AddressBookHomeSet;
	this->_Inst_AddressBookHomeSet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_CalendarHomeSet;
	this->_Inst_CalendarHomeSet = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_CalendarHomeSet;
	this->_Inst_CalendarHomeSet = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELWEBDAVINMEMORYPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND

SB_INLINE void TElWebDavPrincipalBackend::BeginRead()
{
	SBCheckError(TElWebDavPrincipalBackend_BeginRead(_Handle));
}

SB_INLINE void TElWebDavPrincipalBackend::BeginWrite()
{
	SBCheckError(TElWebDavPrincipalBackend_BeginWrite(_Handle));
}

SB_INLINE void TElWebDavPrincipalBackend::Done()
{
	SBCheckError(TElWebDavPrincipalBackend_Done(_Handle));
}

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_INLINE int64_t TElWebDavPrincipalBackend::AddPrincipal(SBWebDAVServer_TElWebDavPrincipal &Principal)
{
	int64_t OutResult;
	SBCheckError(TElWebDavPrincipalBackend_AddPrincipal(_Handle, Principal.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWebDavPrincipalBackend::AddPrincipal(SBWebDAVServer_TElWebDavPrincipal *Principal)
{
	int64_t OutResult;
	SBCheckError(TElWebDavPrincipalBackend_AddPrincipal(_Handle, (Principal != NULL) ? Principal->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
bool TElWebDavPrincipalBackend::RemovePrincipal(SBWebDAVServer_TElWebDavPrincipal &Principal)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_RemovePrincipal(_Handle, Principal.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::RemovePrincipal(SBWebDAVServer_TElWebDavPrincipal *Principal)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_RemovePrincipal(_Handle, (Principal != NULL) ? Principal->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

bool TElWebDavPrincipalBackend::RemovePrincipal(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_RemovePrincipal_1(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::PrincipalExists(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_PrincipalExists(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_INLINE SBWebDAVServer_TElWebDavPrincipalHandle TElWebDavPrincipalBackend::FindPrincipalByURL(const std::string &URL)
{
	SBWebDAVServer_TElWebDavPrincipalHandle OutResult;
	SBCheckError(TElWebDavPrincipalBackend_FindPrincipalByURL(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_INLINE SBWebDAVServer_TElWebDavPrincipalHandle TElWebDavPrincipalBackend::FindPrincipalByName(const std::string &Name)
{
	SBWebDAVServer_TElWebDavPrincipalHandle OutResult;
	SBCheckError(TElWebDavPrincipalBackend_FindPrincipalByName(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalBackend::GetGroupMemberSet(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetGroupMemberSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetGroupMemberSet(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetGroupMemberSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalBackend::GetGroupMemberSet(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetGroupMemberSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetGroupMemberSet(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetGroupMemberSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalBackend::GetGroupMembership(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetGroupMembership(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetGroupMembership(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetGroupMembership(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalBackend::GetGroupMembership(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetGroupMembership(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetGroupMembership(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetGroupMembership(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalBackend::GetPrincipalCollectionSet(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetPrincipalCollectionSet(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalBackend::GetPrincipalCollectionSet(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetPrincipalCollectionSet(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalBackend::GetPrincipalAddressBookHomeSet(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalAddressBookHomeSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetPrincipalAddressBookHomeSet(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalAddressBookHomeSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalBackend::GetPrincipalAddressBookHomeSet(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalAddressBookHomeSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetPrincipalAddressBookHomeSet(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalAddressBookHomeSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalBackend::GetPrincipalCalendarHomeSet(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalCalendarHomeSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetPrincipalCalendarHomeSet(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalCalendarHomeSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalBackend::GetPrincipalCalendarHomeSet(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalCalendarHomeSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::GetPrincipalCalendarHomeSet(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_GetPrincipalCalendarHomeSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalBackend::EnumPrincipals(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_EnumPrincipals(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::EnumPrincipals(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_EnumPrincipals(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalBackend::EnumPrincipals(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_EnumPrincipals(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalBackend::EnumPrincipals(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_EnumPrincipals(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElWebDavPrincipalBackend::CollectionExists(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalBackend_CollectionExists(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

TElWebDavPrincipalBackend::TElWebDavPrincipalBackend(TElWebDavPrincipalBackendHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDavPrincipalBackend::TElWebDavPrincipalBackend() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavPrincipalBackend_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALMEMORYBACKEND

SB_INLINE void TElWebDavPrincipalMemoryBackend::BeginRead()
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_BeginRead(_Handle));
}

SB_INLINE void TElWebDavPrincipalMemoryBackend::BeginWrite()
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_BeginWrite(_Handle));
}

SB_INLINE void TElWebDavPrincipalMemoryBackend::Done()
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_Done(_Handle));
}

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_INLINE int64_t TElWebDavPrincipalMemoryBackend::AddPrincipal(SBWebDAVServer_TElWebDavPrincipal &Principal)
{
	int64_t OutResult;
	SBCheckError(TElWebDavPrincipalMemoryBackend_AddPrincipal(_Handle, Principal.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWebDavPrincipalMemoryBackend::AddPrincipal(SBWebDAVServer_TElWebDavPrincipal *Principal)
{
	int64_t OutResult;
	SBCheckError(TElWebDavPrincipalMemoryBackend_AddPrincipal(_Handle, (Principal != NULL) ? Principal->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
bool TElWebDavPrincipalMemoryBackend::RemovePrincipal(SBWebDAVServer_TElWebDavPrincipal &Principal)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_RemovePrincipal(_Handle, Principal.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::RemovePrincipal(SBWebDAVServer_TElWebDavPrincipal *Principal)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_RemovePrincipal(_Handle, (Principal != NULL) ? Principal->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

bool TElWebDavPrincipalMemoryBackend::RemovePrincipal(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_RemovePrincipal_1(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::PrincipalExists(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_PrincipalExists(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_INLINE SBWebDAVServer_TElWebDavPrincipalHandle TElWebDavPrincipalMemoryBackend::FindPrincipalByURL(const std::string &URL)
{
	SBWebDAVServer_TElWebDavPrincipalHandle OutResult;
	SBCheckError(TElWebDavPrincipalMemoryBackend_FindPrincipalByURL(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_INLINE SBWebDAVServer_TElWebDavPrincipalHandle TElWebDavPrincipalMemoryBackend::FindPrincipalByName(const std::string &Name)
{
	SBWebDAVServer_TElWebDavPrincipalHandle OutResult;
	SBCheckError(TElWebDavPrincipalMemoryBackend_FindPrincipalByName(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetGroupMemberSet(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetGroupMemberSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetGroupMemberSet(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetGroupMemberSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetGroupMemberSet(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetGroupMemberSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetGroupMemberSet(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetGroupMemberSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetGroupMembership(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetGroupMembership(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetGroupMembership(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetGroupMembership(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetGroupMembership(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetGroupMembership(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetGroupMembership(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetGroupMembership(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetPrincipalCollectionSet(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetPrincipalCollectionSet(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetPrincipalCollectionSet(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetPrincipalCollectionSet(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalCollectionSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetPrincipalAddressBookHomeSet(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalAddressBookHomeSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetPrincipalAddressBookHomeSet(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalAddressBookHomeSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetPrincipalAddressBookHomeSet(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalAddressBookHomeSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetPrincipalAddressBookHomeSet(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalAddressBookHomeSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetPrincipalCalendarHomeSet(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalCalendarHomeSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetPrincipalCalendarHomeSet(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalCalendarHomeSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::GetPrincipalCalendarHomeSet(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalCalendarHomeSet(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::GetPrincipalCalendarHomeSet(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_GetPrincipalCalendarHomeSet(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::EnumPrincipals(const std::string &URL, TStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_EnumPrincipals(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::EnumPrincipals(const std::string &URL, TStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_EnumPrincipals(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElWebDavPrincipalMemoryBackend::EnumPrincipals(const std::string &URL, TElStringList &List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_EnumPrincipals(_Handle, URL.data(), (int32_t)URL.length(), List.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavPrincipalMemoryBackend::EnumPrincipals(const std::string &URL, TElStringList *List)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavPrincipalMemoryBackend_EnumPrincipals(_Handle, URL.data(), (int32_t)URL.length(), (List != NULL) ? List->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElWebDavPrincipalMemoryBackend::get_CardDAVPrefix(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPrincipalMemoryBackend_get_CardDAVPrefix(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(869611482, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPrincipalMemoryBackend::set_CardDAVPrefix(const std::string &Value)
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_set_CardDAVPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavPrincipalMemoryBackend::get_CalDAVPrefix(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPrincipalMemoryBackend_get_CalDAVPrefix(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-924986638, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPrincipalMemoryBackend::set_CalDAVPrefix(const std::string &Value)
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_set_CalDAVPrefix(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavPrincipalMemoryBackend::get_PrincipalBaseURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPrincipalMemoryBackend_get_PrincipalBaseURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(803674432, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPrincipalMemoryBackend::set_PrincipalBaseURL(const std::string &Value)
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_set_PrincipalBaseURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavPrincipalMemoryBackend::get_GroupBaseURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPrincipalMemoryBackend_get_GroupBaseURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1026126359, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPrincipalMemoryBackend::set_GroupBaseURL(const std::string &Value)
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_set_GroupBaseURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavPrincipalMemoryBackend::get_ContactFileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavPrincipalMemoryBackend_get_ContactFileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1175130762, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavPrincipalMemoryBackend::set_ContactFileName(const std::string &Value)
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_set_ContactFileName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebDavPrincipalMemoryBackend::TElWebDavPrincipalMemoryBackend(TElWebDavPrincipalMemoryBackendHandle handle, TElOwnHandle ownHandle) : TElWebDavPrincipalBackend(handle, ownHandle)
{
}

TElWebDavPrincipalMemoryBackend::TElWebDavPrincipalMemoryBackend() : TElWebDavPrincipalBackend(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavPrincipalMemoryBackend_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALMEMORYBACKEND */

#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER

TElCalDavTextMatchFilter::TElCalDavTextMatchFilter(TElCalDavTextMatchFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavTextMatchFilter(handle, ownHandle)
{
}

TElCalDavTextMatchFilter::TElCalDavTextMatchFilter(TElWebDavFilter &Parent) : TElWebDavTextMatchFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCalDavTextMatchFilter_Create(Parent.getHandle(), &_Handle));
}

TElCalDavTextMatchFilter::TElCalDavTextMatchFilter(TElWebDavFilter *Parent) : TElWebDavTextMatchFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCalDavTextMatchFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCALDAVPARAMFILTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElCalDavParamFilter::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDavParamFilter_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCalDavParamFilter::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDavParamFilter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

bool TElCalDavParamFilter::get_IsNotDefined()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDavParamFilter_get_IsNotDefined(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
TElCalDavTextMatchFilter* TElCalDavParamFilter::get_TextMatch()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCalDavParamFilter_get_TextMatch(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TextMatch)
		this->_Inst_TextMatch = new TElCalDavTextMatchFilter(hOutResult, ohFalse);
	else
		this->_Inst_TextMatch->updateHandle(hOutResult);
	return this->_Inst_TextMatch;
}
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

void TElCalDavParamFilter::initInstances()
{
#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
	this->_Inst_TextMatch = NULL;
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */
}

TElCalDavParamFilter::TElCalDavParamFilter(TElCalDavParamFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavFilter(handle, ownHandle)
{
	initInstances();
}

TElCalDavParamFilter::TElCalDavParamFilter(TElWebDavFilter &Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCalDavParamFilter_Create(Parent.getHandle(), &_Handle));
}

TElCalDavParamFilter::TElCalDavParamFilter(TElWebDavFilter *Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCalDavParamFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCalDavParamFilter::~TElCalDavParamFilter()
{
#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
	delete this->_Inst_TextMatch;
	this->_Inst_TextMatch = NULL;
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */
}
#endif /* SB_USE_CLASS_TELCALDAVPARAMFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGEBASE

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElWebDavTimeRangeBase::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavTimeRangeBase_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavTimeRangeBase::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavTimeRangeBase_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE int64_t TElWebDavTimeRangeBase::get_Start()
{
	int64_t OutResult;
	SBCheckError(TElWebDavTimeRangeBase_get_Start(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWebDavTimeRangeBase::get_End_()
{
	int64_t OutResult;
	SBCheckError(TElWebDavTimeRangeBase_get_End_(_Handle, &OutResult));
	return OutResult;
}

TElWebDavTimeRangeBase::TElWebDavTimeRangeBase(TElWebDavTimeRangeBaseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDavTimeRangeBase::TElWebDavTimeRangeBase() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavTimeRangeBase_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGEBASE */

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE

TElWebDavTimeRange::TElWebDavTimeRange(TElWebDavTimeRangeHandle handle, TElOwnHandle ownHandle) : TElWebDavTimeRangeBase(handle, ownHandle)
{
}

TElWebDavTimeRange::TElWebDavTimeRange() : TElWebDavTimeRangeBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavTimeRange_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */

#ifdef SB_USE_CLASS_TELCALDAVPROPFILTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElCalDavPropFilter::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDavPropFilter_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCalDavPropFilter::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDavPropFilter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElCalDavPropFilter::get_SubFilters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCalDavPropFilter_get_SubFilters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubFilters)
		this->_Inst_SubFilters = new TList(hOutResult, ohFalse);
	else
		this->_Inst_SubFilters->updateHandle(hOutResult);
	return this->_Inst_SubFilters;
}
#endif /* SB_USE_CLASS_TLIST */

bool TElCalDavPropFilter::get_IsNotDefined()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDavPropFilter_get_IsNotDefined(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
TElWebDavTimeRange* TElCalDavPropFilter::get_TimeRange()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCalDavPropFilter_get_TimeRange(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TimeRange)
		this->_Inst_TimeRange = new TElWebDavTimeRange(hOutResult, ohFalse);
	else
		this->_Inst_TimeRange->updateHandle(hOutResult);
	return this->_Inst_TimeRange;
}
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */

#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
TElCalDavTextMatchFilter* TElCalDavPropFilter::get_TextMatch()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCalDavPropFilter_get_TextMatch(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TextMatch)
		this->_Inst_TextMatch = new TElCalDavTextMatchFilter(hOutResult, ohFalse);
	else
		this->_Inst_TextMatch->updateHandle(hOutResult);
	return this->_Inst_TextMatch;
}
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

void TElCalDavPropFilter::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_SubFilters = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
	this->_Inst_TimeRange = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */
#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
	this->_Inst_TextMatch = NULL;
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */
}

TElCalDavPropFilter::TElCalDavPropFilter(TElCalDavPropFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavFilter(handle, ownHandle)
{
	initInstances();
}

TElCalDavPropFilter::TElCalDavPropFilter(TElWebDavFilter &Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCalDavPropFilter_Create(Parent.getHandle(), &_Handle));
}

TElCalDavPropFilter::TElCalDavPropFilter(TElWebDavFilter *Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCalDavPropFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCalDavPropFilter::~TElCalDavPropFilter()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_SubFilters;
	this->_Inst_SubFilters = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
	delete this->_Inst_TimeRange;
	this->_Inst_TimeRange = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */
#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
	delete this->_Inst_TextMatch;
	this->_Inst_TextMatch = NULL;
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */
}
#endif /* SB_USE_CLASS_TELCALDAVPROPFILTER */

#ifdef SB_USE_CLASS_TELCALDAVCOMPFILTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElCalDAVCompFilter::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDAVCompFilter_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCalDAVCompFilter::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDAVCompFilter_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
TList* TElCalDAVCompFilter::get_SubFilters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCalDAVCompFilter_get_SubFilters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubFilters)
		this->_Inst_SubFilters = new TList(hOutResult, ohFalse);
	else
		this->_Inst_SubFilters->updateHandle(hOutResult);
	return this->_Inst_SubFilters;
}
#endif /* SB_USE_CLASS_TLIST */

bool TElCalDAVCompFilter::get_IsNotDefined()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDAVCompFilter_get_IsNotDefined(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
TElWebDavTimeRange* TElCalDAVCompFilter::get_TimeRange()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCalDAVCompFilter_get_TimeRange(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TimeRange)
		this->_Inst_TimeRange = new TElWebDavTimeRange(hOutResult, ohFalse);
	else
		this->_Inst_TimeRange->updateHandle(hOutResult);
	return this->_Inst_TimeRange;
}
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */

void TElCalDAVCompFilter::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_SubFilters = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
	this->_Inst_TimeRange = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */
}

TElCalDAVCompFilter::TElCalDAVCompFilter(TElCalDAVCompFilterHandle handle, TElOwnHandle ownHandle) : TElWebDavFilter(handle, ownHandle)
{
	initInstances();
}

TElCalDAVCompFilter::TElCalDAVCompFilter(TElWebDavFilter &Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCalDAVCompFilter_Create(Parent.getHandle(), &_Handle));
}

TElCalDAVCompFilter::TElCalDAVCompFilter(TElWebDavFilter *Parent) : TElWebDavFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCalDAVCompFilter_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCalDAVCompFilter::~TElCalDAVCompFilter()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_SubFilters;
	this->_Inst_SubFilters = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
	delete this->_Inst_TimeRange;
	this->_Inst_TimeRange = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */
}
#endif /* SB_USE_CLASS_TELCALDAVCOMPFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVEXTENDEDREQUEST

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElWebDavExtendedRequest::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavExtendedRequest_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavExtendedRequest::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavExtendedRequest_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElWebDavExtendedRequest::get_ReportName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavExtendedRequest_get_ReportName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-527613685, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavExtendedRequest::set_ReportName(const std::string &Value)
{
	SBCheckError(TElWebDavExtendedRequest_set_ReportName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDavExtendedRequest::get_Hrefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavExtendedRequest_get_Hrefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Hrefs)
		this->_Inst_Hrefs = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Hrefs->updateHandle(hOutResult);
	return this->_Inst_Hrefs;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDavExtendedRequest::get_Hrefs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavExtendedRequest_get_Hrefs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Hrefs)
		this->_Inst_Hrefs = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Hrefs->updateHandle(hOutResult);
	return this->_Inst_Hrefs;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElWebDavExtendedRequest::get_AllProp()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavExtendedRequest_get_AllProp(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavExtendedRequest::set_AllProp(bool Value)
{
	SBCheckError(TElWebDavExtendedRequest_set_AllProp(_Handle, (int8_t)Value));
}

bool TElWebDavExtendedRequest::get_EvaluationResult()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavExtendedRequest_get_EvaluationResult(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavExtendedRequest::set_EvaluationResult(bool Value)
{
	SBCheckError(TElWebDavExtendedRequest_set_EvaluationResult(_Handle, (int8_t)Value));
}

void TElWebDavExtendedRequest::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElWebDavExtendedRequest::TElWebDavExtendedRequest(TElWebDavExtendedRequestHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavExtendedRequest::TElWebDavExtendedRequest() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavExtendedRequest_Create(&_Handle));
}

TElWebDavExtendedRequest::~TElWebDavExtendedRequest()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Hrefs;
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Hrefs;
	this->_Inst_Hrefs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELWEBDAVEXTENDEDREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVADDRESSBOOKREQUEST

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElWebDavAddressBookRequest::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavAddressBookRequest_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavAddressBookRequest::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavAddressBookRequest_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TSBWebDavFilterTest TElWebDavAddressBookRequest::get_Test()
{
	TSBWebDavFilterTestRaw OutResultRaw = 0;
	SBCheckError(TElWebDavAddressBookRequest_get_Test(_Handle, &OutResultRaw));
	return (TSBWebDavFilterTest)OutResultRaw;
}

SB_INLINE void TElWebDavAddressBookRequest::set_Test(TSBWebDavFilterTest Value)
{
	SBCheckError(TElWebDavAddressBookRequest_set_Test(_Handle, (TSBWebDavFilterTestRaw)Value));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElWebDavAddressBookRequest::get_Filters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavAddressBookRequest_get_Filters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Filters)
		this->_Inst_Filters = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Filters->updateHandle(hOutResult);
	return this->_Inst_Filters;
}
#endif /* SB_USE_CLASS_TLIST */

SB_INLINE int32_t TElWebDavAddressBookRequest::get_Limit()
{
	int32_t OutResult;
	SBCheckError(TElWebDavAddressBookRequest_get_Limit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebDavAddressBookRequest::set_Limit(int32_t Value)
{
	SBCheckError(TElWebDavAddressBookRequest_set_Limit(_Handle, Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDavAddressBookRequest::get_Names()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavAddressBookRequest_get_Names(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Names)
		this->_Inst_Names = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Names->updateHandle(hOutResult);
	return this->_Inst_Names;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDavAddressBookRequest::get_Names()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavAddressBookRequest_get_Names(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Names)
		this->_Inst_Names = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Names->updateHandle(hOutResult);
	return this->_Inst_Names;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElWebDavAddressBookRequest::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Filters = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Names = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Names = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElWebDavAddressBookRequest::TElWebDavAddressBookRequest(TElWebDavAddressBookRequestHandle handle, TElOwnHandle ownHandle) : TElWebDavExtendedRequest(handle, ownHandle)
{
	initInstances();
}

TElWebDavAddressBookRequest::TElWebDavAddressBookRequest() : TElWebDavExtendedRequest(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavAddressBookRequest_Create(&_Handle));
}

TElWebDavAddressBookRequest::~TElWebDavAddressBookRequest()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Filters;
	this->_Inst_Filters = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Names;
	this->_Inst_Names = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Names;
	this->_Inst_Names = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELWEBDAVADDRESSBOOKREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET

TElWebDavLimitRecurrenceSet::TElWebDavLimitRecurrenceSet(TElWebDavLimitRecurrenceSetHandle handle, TElOwnHandle ownHandle) : TElWebDavTimeRangeBase(handle, ownHandle)
{
}

TElWebDavLimitRecurrenceSet::TElWebDavLimitRecurrenceSet() : TElWebDavTimeRangeBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavLimitRecurrenceSet_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET */

#ifdef SB_USE_CLASS_TELWEBDAVEXPAND

TElWebDavExpand::TElWebDavExpand(TElWebDavExpandHandle handle, TElOwnHandle ownHandle) : TElWebDavTimeRangeBase(handle, ownHandle)
{
}

TElWebDavExpand::TElWebDavExpand() : TElWebDavTimeRangeBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavExpand_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVEXPAND */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET

TElWebDavLimitFreeBusySet::TElWebDavLimitFreeBusySet(TElWebDavLimitFreeBusySetHandle handle, TElOwnHandle ownHandle) : TElWebDavTimeRangeBase(handle, ownHandle)
{
}

TElWebDavLimitFreeBusySet::TElWebDavLimitFreeBusySet() : TElWebDavTimeRangeBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavLimitFreeBusySet_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET */

#ifdef SB_USE_CLASS_TELWEBDAVCOMP

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElWebDavComp::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavComp_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavComp::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavComp_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

TElWebDavComp* TElWebDavComp::get_Parent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavComp_get_Parent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parent)
		this->_Inst_Parent = new TElWebDavComp(hOutResult, ohFalse);
	else
		this->_Inst_Parent->updateHandle(hOutResult);
	return this->_Inst_Parent;
}

void TElWebDavComp::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavComp_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1181735039, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavComp::set_Name(const std::string &Value)
{
	SBCheckError(TElWebDavComp_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElWebDavComp::get_AllProp()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavComp_get_AllProp(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavComp::set_AllProp(bool Value)
{
	SBCheckError(TElWebDavComp_set_AllProp(_Handle, (int8_t)Value));
}

bool TElWebDavComp::get_AllComp()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavComp_get_AllComp(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavComp::set_AllComp(bool Value)
{
	SBCheckError(TElWebDavComp_set_AllComp(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElWebDavComp::get_Props()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavComp_get_Props(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Props)
		this->_Inst_Props = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Props->updateHandle(hOutResult);
	return this->_Inst_Props;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElWebDavComp::get_Props()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavComp_get_Props(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Props)
		this->_Inst_Props = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Props->updateHandle(hOutResult);
	return this->_Inst_Props;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
TList* TElWebDavComp::get_Comps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavComp_get_Comps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Comps)
		this->_Inst_Comps = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Comps->updateHandle(hOutResult);
	return this->_Inst_Comps;
}
#endif /* SB_USE_CLASS_TLIST */

void TElWebDavComp::get_FullPath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavComp_get_FullPath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1056526818, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDavComp::initInstances()
{
	this->_Inst_Parent = NULL;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Props = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Props = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Comps = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElWebDavComp::TElWebDavComp(TElWebDavCompHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavComp::TElWebDavComp(TElWebDavComp &Parent) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavComp_Create(Parent.getHandle(), &_Handle));
}

TElWebDavComp::TElWebDavComp(TElWebDavComp *Parent) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavComp_Create((Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWebDavComp::~TElWebDavComp()
{
	delete this->_Inst_Parent;
	this->_Inst_Parent = NULL;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Props;
	this->_Inst_Props = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Props;
	this->_Inst_Props = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Comps;
	this->_Inst_Comps = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELWEBDAVCOMP */

#ifdef SB_USE_CLASS_TELWEBDAVCALENDARREQUEST

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElWebDavCalendarRequest::LoadFromXML(TElXMLDOMElement &Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavCalendarRequest_LoadFromXML(_Handle, Element.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavCalendarRequest::LoadFromXML(TElXMLDOMElement *Element)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavCalendarRequest_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCALDAVCOMPFILTER
TElCalDAVCompFilter* TElWebDavCalendarRequest::get_CompFilter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavCalendarRequest_get_CompFilter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CompFilter)
		this->_Inst_CompFilter = new TElCalDAVCompFilter(hOutResult, ohFalse);
	else
		this->_Inst_CompFilter->updateHandle(hOutResult);
	return this->_Inst_CompFilter;
}
#endif /* SB_USE_CLASS_TELCALDAVCOMPFILTER */

#ifdef SB_USE_CLASS_TELVCALENDAR
TElVCalendar* TElWebDavCalendarRequest::get_Timezone()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavCalendarRequest_get_Timezone(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timezone)
		this->_Inst_Timezone = new TElVCalendar(hOutResult, ohFalse);
	else
		this->_Inst_Timezone->updateHandle(hOutResult);
	return this->_Inst_Timezone;
}
#endif /* SB_USE_CLASS_TELVCALENDAR */

#ifdef SB_USE_CLASS_TELWEBDAVCOMP
TElWebDavComp* TElWebDavCalendarRequest::get_Comp()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavCalendarRequest_get_Comp(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Comp)
		this->_Inst_Comp = new TElWebDavComp(hOutResult, ohFalse);
	else
		this->_Inst_Comp->updateHandle(hOutResult);
	return this->_Inst_Comp;
}
#endif /* SB_USE_CLASS_TELWEBDAVCOMP */

#ifdef SB_USE_CLASS_TELWEBDAVEXPAND
TElWebDavExpand* TElWebDavCalendarRequest::get_Expand()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavCalendarRequest_get_Expand(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Expand)
		this->_Inst_Expand = new TElWebDavExpand(hOutResult, ohFalse);
	else
		this->_Inst_Expand->updateHandle(hOutResult);
	return this->_Inst_Expand;
}
#endif /* SB_USE_CLASS_TELWEBDAVEXPAND */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET
TElWebDavLimitRecurrenceSet* TElWebDavCalendarRequest::get_LimitRecurrenceSet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavCalendarRequest_get_LimitRecurrenceSet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LimitRecurrenceSet)
		this->_Inst_LimitRecurrenceSet = new TElWebDavLimitRecurrenceSet(hOutResult, ohFalse);
	else
		this->_Inst_LimitRecurrenceSet->updateHandle(hOutResult);
	return this->_Inst_LimitRecurrenceSet;
}
#endif /* SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET
TElWebDavLimitFreeBusySet* TElWebDavCalendarRequest::get_LimitFreebusySet()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavCalendarRequest_get_LimitFreebusySet(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LimitFreebusySet)
		this->_Inst_LimitFreebusySet = new TElWebDavLimitFreeBusySet(hOutResult, ohFalse);
	else
		this->_Inst_LimitFreebusySet->updateHandle(hOutResult);
	return this->_Inst_LimitFreebusySet;
}
#endif /* SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET */

void TElWebDavCalendarRequest::initInstances()
{
#ifdef SB_USE_CLASS_TELCALDAVCOMPFILTER
	this->_Inst_CompFilter = NULL;
#endif /* SB_USE_CLASS_TELCALDAVCOMPFILTER */
#ifdef SB_USE_CLASS_TELVCALENDAR
	this->_Inst_Timezone = NULL;
#endif /* SB_USE_CLASS_TELVCALENDAR */
#ifdef SB_USE_CLASS_TELWEBDAVCOMP
	this->_Inst_Comp = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVCOMP */
#ifdef SB_USE_CLASS_TELWEBDAVEXPAND
	this->_Inst_Expand = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVEXPAND */
#ifdef SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET
	this->_Inst_LimitRecurrenceSet = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET */
#ifdef SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET
	this->_Inst_LimitFreebusySet = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET */
}

TElWebDavCalendarRequest::TElWebDavCalendarRequest(TElWebDavCalendarRequestHandle handle, TElOwnHandle ownHandle) : TElWebDavExtendedRequest(handle, ownHandle)
{
	initInstances();
}

TElWebDavCalendarRequest::TElWebDavCalendarRequest() : TElWebDavExtendedRequest(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavCalendarRequest_Create(&_Handle));
}

TElWebDavCalendarRequest::~TElWebDavCalendarRequest()
{
#ifdef SB_USE_CLASS_TELCALDAVCOMPFILTER
	delete this->_Inst_CompFilter;
	this->_Inst_CompFilter = NULL;
#endif /* SB_USE_CLASS_TELCALDAVCOMPFILTER */
#ifdef SB_USE_CLASS_TELVCALENDAR
	delete this->_Inst_Timezone;
	this->_Inst_Timezone = NULL;
#endif /* SB_USE_CLASS_TELVCALENDAR */
#ifdef SB_USE_CLASS_TELWEBDAVCOMP
	delete this->_Inst_Comp;
	this->_Inst_Comp = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVCOMP */
#ifdef SB_USE_CLASS_TELWEBDAVEXPAND
	delete this->_Inst_Expand;
	this->_Inst_Expand = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVEXPAND */
#ifdef SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET
	delete this->_Inst_LimitRecurrenceSet;
	this->_Inst_LimitRecurrenceSet = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET */
#ifdef SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET
	delete this->_Inst_LimitFreebusySet;
	this->_Inst_LimitFreebusySet = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET */
}
#endif /* SB_USE_CLASS_TELWEBDAVCALENDARREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY

bool TElWebDavProperty::Write(const std::string &URL, const std::string &Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_Write(_Handle, URL.data(), (int32_t)URL.length(), Value.data(), (int32_t)Value.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::Read(const std::string &URL, std::string &Value)
{
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElWebDavProperty_Read(_Handle, URL.data(), (int32_t)URL.length(), (char *)Value.data(), &szValue, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringA(1166657834, 2, (char *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Value.resize(szValue);
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
bool TElWebDavProperty::Read(const std::string &URL, std::string &Value, TElXMLDOMElement &Element, TObject &Param)
{
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElWebDavProperty_Read_1(_Handle, URL.data(), (int32_t)URL.length(), (char *)Value.data(), &szValue, Element.getHandle(), Param.getHandle(), &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringA(-1674070, 2, (char *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Value.resize(szValue);
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::Read(const std::string &URL, std::string &Value, TElXMLDOMElement *Element, TObject *Param)
{
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElWebDavProperty_Read_1(_Handle, URL.data(), (int32_t)URL.length(), (char *)Value.data(), &szValue, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (Param != NULL) ? Param->getHandle() : SB_NULL_HANDLE, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringA(-1674070, 2, (char *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Value.resize(szValue);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

bool TElWebDavProperty::Remove(const std::string &URL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_Remove(_Handle, URL.data(), (int32_t)URL.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElWebDavProperty::get_NS(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavProperty_get_NS(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-675426007, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElWebDavProperty::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavProperty_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2146835415, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElWebDavProperty::get_Live()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_Live(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::get_Protect()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_Protect(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::get_AsXML()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_AsXML(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::get_PrincipalMatch()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_PrincipalMatch(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::get_Principal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_Principal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::get_AddressBook()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_AddressBook(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::get_Calendar()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_Calendar(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::get_Copy()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_Copy(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavProperty::get_Search()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavProperty_get_Search(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDavProperty::set_Search(bool Value)
{
	SBCheckError(TElWebDavProperty_set_Search(_Handle, (int8_t)Value));
}

void TElWebDavProperty::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavProperty_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-56741582, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavProperty::set_Description(const std::string &Value)
{
	SBCheckError(TElWebDavProperty_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElWebDavProperty::get_DescLang(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavProperty_get_DescLang(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1254145527, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElWebDavProperty::set_DescLang(const std::string &Value)
{
	SBCheckError(TElWebDavProperty_set_DescLang(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElWebDavProperty::get_OnReadValue(TSBWebDavPropertyReadValueEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDavProperty_get_OnReadValue(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDavProperty::set_OnReadValue(TSBWebDavPropertyReadValueEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDavProperty_set_OnReadValue(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDavProperty::get_OnReadExValue(TSBWebDavPropertyReadExValueEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDavProperty_get_OnReadExValue(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDavProperty::set_OnReadExValue(TSBWebDavPropertyReadExValueEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDavProperty_set_OnReadExValue(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDavProperty::get_OnWriteValue(TSBWebDavPropertyWriteValueEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDavProperty_get_OnWriteValue(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDavProperty::set_OnWriteValue(TSBWebDavPropertyWriteValueEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDavProperty_set_OnWriteValue(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDavProperty::get_OnAfterReadValue(TSBWebDavPropertyAfterReadValueEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDavProperty_get_OnAfterReadValue(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDavProperty::set_OnAfterReadValue(TSBWebDavPropertyAfterReadValueEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDavProperty_set_OnAfterReadValue(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDavProperty::get_OnBeforeWriteValue(TSBWebDavPropertyBeforeWriteValueEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDavProperty_get_OnBeforeWriteValue(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDavProperty::set_OnBeforeWriteValue(TSBWebDavPropertyBeforeWriteValueEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDavProperty_set_OnBeforeWriteValue(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDavProperty::get_OnRemove(TSBWebDavPropertyRemoveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDavProperty_get_OnRemove(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDavProperty::set_OnRemove(TSBWebDavPropertyRemoveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDavProperty_set_OnRemove(_Handle, pMethodValue, pDataValue));
}

TElWebDavProperty::TElWebDavProperty(TElWebDavPropertyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELWEBDAVSERVER
TElWebDavProperty::TElWebDavProperty(TElWebDAVServer &Server, const std::string &NS, const std::string &Name, bool Live, bool Protect, bool AsXML, bool PrincipalMatch, bool Principal, bool AddressBook, bool Calendar, bool Copy) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavProperty_Create(Server.getHandle(), NS.data(), (int32_t)NS.length(), Name.data(), (int32_t)Name.length(), (int8_t)Live, (int8_t)Protect, (int8_t)AsXML, (int8_t)PrincipalMatch, (int8_t)Principal, (int8_t)AddressBook, (int8_t)Calendar, (int8_t)Copy, &_Handle));
}

TElWebDavProperty::TElWebDavProperty(TElWebDAVServer *Server, const std::string &NS, const std::string &Name, bool Live, bool Protect, bool AsXML, bool PrincipalMatch, bool Principal, bool AddressBook, bool Calendar, bool Copy) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavProperty_Create((Server != NULL) ? Server->getHandle() : SB_NULL_HANDLE, NS.data(), (int32_t)NS.length(), Name.data(), (int32_t)Name.length(), (int8_t)Live, (int8_t)Protect, (int8_t)AsXML, (int8_t)PrincipalMatch, (int8_t)Principal, (int8_t)AddressBook, (int8_t)Calendar, (int8_t)Copy, &_Handle));
}
#endif /* SB_USE_CLASS_TELWEBDAVSERVER */

#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

#ifdef SB_USE_CLASS_TELWEBDAVIFSTATE

TSBWebDavIfStateType TElWebDavIfState::get_AType()
{
	TSBWebDavIfStateTypeRaw OutResultRaw = 0;
	SBCheckError(TElWebDavIfState_get_AType(_Handle, &OutResultRaw));
	return (TSBWebDavIfStateType)OutResultRaw;
}

bool TElWebDavIfState::get_Condition()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavIfState_get_Condition(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElWebDavIfState::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavIfState_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1402584241, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElWebDavIfState::TElWebDavIfState(TElWebDavIfStateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDavIfState::TElWebDavIfState(TSBWebDavIfStateType AType, bool Condition, const std::string &Value) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavIfState_Create((TSBWebDavIfStateTypeRaw)AType, (int8_t)Condition, Value.data(), (int32_t)Value.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVIFSTATE */

#ifdef SB_USE_CLASS_TELWEBDAVIFRESOURCE

void TElWebDavIfResource::get_URI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDavIfResource_get_URI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2094075176, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELWEBDAVIFSTATE
TElWebDavIfState* TElWebDavIfResource::get_States(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDavIfResource_get_States(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_States)
		this->_Inst_States = new TElWebDavIfState(hOutResult, ohFalse);
	else
		this->_Inst_States->updateHandle(hOutResult);
	return this->_Inst_States;
}
#endif /* SB_USE_CLASS_TELWEBDAVIFSTATE */

SB_INLINE int32_t TElWebDavIfResource::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDavIfResource_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDavIfResource::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVIFSTATE
	this->_Inst_States = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVIFSTATE */
}

TElWebDavIfResource::TElWebDavIfResource(TElWebDavIfResourceHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDavIfResource::TElWebDavIfResource(const std::string &URI) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDavIfResource_Create(URI.data(), (int32_t)URI.length(), &_Handle));
}

TElWebDavIfResource::~TElWebDavIfResource()
{
#ifdef SB_USE_CLASS_TELWEBDAVIFSTATE
	delete this->_Inst_States;
	this->_Inst_States = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVIFSTATE */
}
#endif /* SB_USE_CLASS_TELWEBDAVIFRESOURCE */

#ifdef SB_USE_CLASS_TELWEBDAVIFHEADER

bool TElWebDAVIfHeader::Process(const std::string &S)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVIfHeader_Process(_Handle, S.data(), (int32_t)S.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElWebDAVIfHeader::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElWebDAVIfHeader_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1136815267, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELWEBDAVIFRESOURCE
TElWebDavIfResource* TElWebDAVIfHeader::get_Resources(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVIfHeader_get_Resources(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Resources)
		this->_Inst_Resources = new TElWebDavIfResource(hOutResult, ohFalse);
	else
		this->_Inst_Resources->updateHandle(hOutResult);
	return this->_Inst_Resources;
}
#endif /* SB_USE_CLASS_TELWEBDAVIFRESOURCE */

SB_INLINE int32_t TElWebDAVIfHeader::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVIfHeader_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVIfHeader::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVIFRESOURCE
	this->_Inst_Resources = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVIFRESOURCE */
}

TElWebDAVIfHeader::TElWebDAVIfHeader(TElWebDAVIfHeaderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDAVIfHeader::TElWebDAVIfHeader(const std::string &URL) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVIfHeader_Create(URL.data(), (int32_t)URL.length(), &_Handle));
}

TElWebDAVIfHeader::~TElWebDAVIfHeader()
{
#ifdef SB_USE_CLASS_TELWEBDAVIFRESOURCE
	delete this->_Inst_Resources;
	this->_Inst_Resources = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVIFRESOURCE */
}
#endif /* SB_USE_CLASS_TELWEBDAVIFHEADER */

#ifdef SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST

SB_INLINE void TElWebDAVCustomLockList::Enter(bool ReadOnly)
{
	SBCheckError(TElWebDAVCustomLockList_Enter(_Handle, (int8_t)ReadOnly));
}

SB_INLINE void TElWebDAVCustomLockList::Done()
{
	SBCheckError(TElWebDAVCustomLockList_Done(_Handle));
}

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE void TElWebDAVCustomLockList::Add(const TElWebDAVLock &Lock)
{
	SBCheckError(TElWebDAVCustomLockList_Add(_Handle, Lock.getHandle()));
}

SB_INLINE void TElWebDAVCustomLockList::Add(const TElWebDAVLock *Lock)
{
	SBCheckError(TElWebDAVCustomLockList_Add(_Handle, (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE void TElWebDAVCustomLockList::Remove(const TElWebDAVLock &Lock)
{
	SBCheckError(TElWebDAVCustomLockList_Remove(_Handle, Lock.getHandle()));
}

SB_INLINE void TElWebDAVCustomLockList::Remove(const TElWebDAVLock *Lock)
{
	SBCheckError(TElWebDAVCustomLockList_Remove(_Handle, (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE TElWebDAVLockHandle TElWebDAVCustomLockList::Find(const std::string &Token)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVCustomLockList_Find(_Handle, Token.data(), (int32_t)Token.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElWebDAVCustomLockList::FindAll(const std::string &URL)
{
	TListHandle OutResult;
	SBCheckError(TElWebDAVCustomLockList_FindAll(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
TElWebDAVLockHandle TElWebDAVCustomLockList::FindFirst(TObject &Handle, const std::string &URL)
{
	TElWebDAVLockHandle OutResult;
	TElClassHandle hHandle = Handle.getHandle();
	SBCheckError(TElWebDAVCustomLockList_FindFirst(_Handle, &hHandle, URL.data(), (int32_t)URL.length(), &OutResult));
	Handle.updateHandle(hHandle);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE TElWebDAVLockHandle TElWebDAVCustomLockList::FindNext(TObject &Handle)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVCustomLockList_FindNext(_Handle, Handle.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebDAVLockHandle TElWebDAVCustomLockList::FindNext(TObject *Handle)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVCustomLockList_FindNext(_Handle, (Handle != NULL) ? Handle->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

SB_INLINE void TElWebDAVCustomLockList::FindClose(TObject &Handle)
{
	SBCheckError(TElWebDAVCustomLockList_FindClose(_Handle, Handle.getHandle()));
}

SB_INLINE void TElWebDAVCustomLockList::FindClose(TObject *Handle)
{
	SBCheckError(TElWebDAVCustomLockList_FindClose(_Handle, (Handle != NULL) ? Handle->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVCustomLockList::LoadFromStream(TStream &Stream, bool Clear)
{
	SBCheckError(TElWebDAVCustomLockList_LoadFromStream(_Handle, Stream.getHandle(), (int8_t)Clear));
}

SB_INLINE void TElWebDAVCustomLockList::LoadFromStream(TStream *Stream, bool Clear)
{
	SBCheckError(TElWebDAVCustomLockList_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)Clear));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVCustomLockList::SaveToStream(TStream &Stream)
{
	SBCheckError(TElWebDAVCustomLockList_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElWebDAVCustomLockList::SaveToStream(TStream *Stream)
{
	SBCheckError(TElWebDAVCustomLockList_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
TElWebDAVLock* TElWebDAVCustomLockList::get_Locks(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVCustomLockList_get_Locks(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Locks)
		this->_Inst_Locks = new TElWebDAVLock(hOutResult, ohFalse);
	else
		this->_Inst_Locks->updateHandle(hOutResult);
	return this->_Inst_Locks;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

SB_INLINE int32_t TElWebDAVCustomLockList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVCustomLockList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVCustomLockList::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
	this->_Inst_Locks = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */
}

TElWebDAVCustomLockList::TElWebDAVCustomLockList(TElWebDAVCustomLockListHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElWebDAVCustomLockList::TElWebDAVCustomLockList(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVCustomLockList_Create(AOwner.getHandle(), &_Handle));
}

TElWebDAVCustomLockList::TElWebDAVCustomLockList(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVCustomLockList_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWebDAVCustomLockList::~TElWebDAVCustomLockList()
{
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
	delete this->_Inst_Locks;
	this->_Inst_Locks = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */
}
#endif /* SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVFINDMEMORYLOCKHANDLE

TElWebDavFindMemoryLockHandle::TElWebDavFindMemoryLockHandle(TElWebDavFindMemoryLockHandleHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDavFindMemoryLockHandle::TElWebDavFindMemoryLockHandle() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavFindMemoryLockHandle_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVFINDMEMORYLOCKHANDLE */

#ifdef SB_USE_CLASS_TELWEBDAVMEMORYLOCKLIST

SB_INLINE void TElWebDAVMemoryLockList::Enter(bool ReadOnly)
{
	SBCheckError(TElWebDAVMemoryLockList_Enter(_Handle, (int8_t)ReadOnly));
}

SB_INLINE void TElWebDAVMemoryLockList::Done()
{
	SBCheckError(TElWebDAVMemoryLockList_Done(_Handle));
}

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE void TElWebDAVMemoryLockList::Add(const TElWebDAVLock &Lock)
{
	SBCheckError(TElWebDAVMemoryLockList_Add(_Handle, Lock.getHandle()));
}

SB_INLINE void TElWebDAVMemoryLockList::Add(const TElWebDAVLock *Lock)
{
	SBCheckError(TElWebDAVMemoryLockList_Add(_Handle, (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE void TElWebDAVMemoryLockList::Remove(const TElWebDAVLock &Lock)
{
	SBCheckError(TElWebDAVMemoryLockList_Remove(_Handle, Lock.getHandle()));
}

SB_INLINE void TElWebDAVMemoryLockList::Remove(const TElWebDAVLock *Lock)
{
	SBCheckError(TElWebDAVMemoryLockList_Remove(_Handle, (Lock != NULL) ? Lock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE TElWebDAVLockHandle TElWebDAVMemoryLockList::Find(const std::string &Token)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVMemoryLockList_Find(_Handle, Token.data(), (int32_t)Token.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE TListHandle TElWebDAVMemoryLockList::FindAll(const std::string &URL)
{
	TListHandle OutResult;
	SBCheckError(TElWebDAVMemoryLockList_FindAll(_Handle, URL.data(), (int32_t)URL.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
TElWebDAVLockHandle TElWebDAVMemoryLockList::FindFirst(TObject &Handle, const std::string &URL)
{
	TElWebDAVLockHandle OutResult;
	TElClassHandle hHandle = Handle.getHandle();
	SBCheckError(TElWebDAVMemoryLockList_FindFirst(_Handle, &hHandle, URL.data(), (int32_t)URL.length(), &OutResult));
	Handle.updateHandle(hHandle);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_INLINE TElWebDAVLockHandle TElWebDAVMemoryLockList::FindNext(TObject &Handle)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVMemoryLockList_FindNext(_Handle, Handle.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElWebDAVLockHandle TElWebDAVMemoryLockList::FindNext(TObject *Handle)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(TElWebDAVMemoryLockList_FindNext(_Handle, (Handle != NULL) ? Handle->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

SB_INLINE void TElWebDAVMemoryLockList::FindClose(TObject &Handle)
{
	SBCheckError(TElWebDAVMemoryLockList_FindClose(_Handle, Handle.getHandle()));
}

SB_INLINE void TElWebDAVMemoryLockList::FindClose(TObject *Handle)
{
	SBCheckError(TElWebDAVMemoryLockList_FindClose(_Handle, (Handle != NULL) ? Handle->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVMemoryLockList::LoadFromStream(TStream &Stream, bool Clear)
{
	SBCheckError(TElWebDAVMemoryLockList_LoadFromStream(_Handle, Stream.getHandle(), (int8_t)Clear));
}

SB_INLINE void TElWebDAVMemoryLockList::LoadFromStream(TStream *Stream, bool Clear)
{
	SBCheckError(TElWebDAVMemoryLockList_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)Clear));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElWebDAVMemoryLockList::SaveToStream(TStream &Stream)
{
	SBCheckError(TElWebDAVMemoryLockList_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElWebDAVMemoryLockList::SaveToStream(TStream *Stream)
{
	SBCheckError(TElWebDAVMemoryLockList_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElWebDAVMemoryLockList::Cleanup()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVMemoryLockList_Cleanup(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
TElWebDAVLock* TElWebDAVMemoryLockList::get_Locks(int32_t Idx)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVMemoryLockList_get_Locks(_Handle, Idx, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Locks)
		this->_Inst_Locks = new TElWebDAVLock(hOutResult, ohFalse);
	else
		this->_Inst_Locks->updateHandle(hOutResult);
	return this->_Inst_Locks;
}
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

SB_INLINE int32_t TElWebDAVMemoryLockList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVMemoryLockList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElWebDAVMemoryLockList::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
	this->_Inst_Locks = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */
}

TElWebDAVMemoryLockList::TElWebDAVMemoryLockList(TElWebDAVMemoryLockListHandle handle, TElOwnHandle ownHandle) : TElWebDAVCustomLockList(handle, ownHandle)
{
	initInstances();
}

TElWebDAVMemoryLockList::TElWebDAVMemoryLockList(TComponent &AOwner) : TElWebDAVCustomLockList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVMemoryLockList_Create(AOwner.getHandle(), &_Handle));
}

TElWebDAVMemoryLockList::TElWebDAVMemoryLockList(TComponent *AOwner) : TElWebDAVCustomLockList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVMemoryLockList_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElWebDAVMemoryLockList::~TElWebDAVMemoryLockList()
{
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
	delete this->_Inst_Locks;
	this->_Inst_Locks = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */
}
#endif /* SB_USE_CLASS_TELWEBDAVMEMORYLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVACLOPTIONS

bool TElWebDAVACLOptions::get_UseACL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDAVACLOptions_get_UseACL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElWebDAVACLOptions::set_UseACL(bool Value)
{
	SBCheckError(TElWebDAVACLOptions_set_UseACL(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND
TElWebDavPrincipalBackend* TElWebDAVACLOptions::get_PrincipalBackend()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWebDAVACLOptions_get_PrincipalBackend(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PrincipalBackend)
		this->_Inst_PrincipalBackend = new TElWebDavPrincipalBackend(hOutResult, ohFalse);
	else
		this->_Inst_PrincipalBackend->updateHandle(hOutResult);
	return this->_Inst_PrincipalBackend;
}

SB_INLINE void TElWebDAVACLOptions::set_PrincipalBackend(TElWebDavPrincipalBackend &Value)
{
	SBCheckError(TElWebDAVACLOptions_set_PrincipalBackend(_Handle, Value.getHandle()));
}

SB_INLINE void TElWebDAVACLOptions::set_PrincipalBackend(TElWebDavPrincipalBackend *Value)
{
	SBCheckError(TElWebDAVACLOptions_set_PrincipalBackend(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND */

void TElWebDAVACLOptions::get_AbstractPrivileges(std::vector<int16_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 2;
	uint32_t _err = TElWebDAVACLOptions_get_AbstractPrivileges(_Handle, (int16_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 2);
		SBCheckError(SBGetLastReturnBuffer(-490070984, 1, (int16_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 2);
}

SB_INLINE void TElWebDAVACLOptions::set_AbstractPrivileges(const std::vector<int16_t> &Value)
{
	SBCheckError(TElWebDAVACLOptions_set_AbstractPrivileges(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElWebDAVACLOptions::get_MatchingPrincipalsLimit()
{
	int32_t OutResult;
	SBCheckError(TElWebDAVACLOptions_get_MatchingPrincipalsLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWebDAVACLOptions::set_MatchingPrincipalsLimit(int32_t Value)
{
	SBCheckError(TElWebDAVACLOptions_set_MatchingPrincipalsLimit(_Handle, Value));
}

SB_INLINE void TElWebDAVACLOptions::get_OnReadCurrentUserPrivileges(TSBWebDavReadPrivilegesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVACLOptions_get_OnReadCurrentUserPrivileges(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVACLOptions::set_OnReadCurrentUserPrivileges(TSBWebDavReadPrivilegesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVACLOptions_set_OnReadCurrentUserPrivileges(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVACLOptions::get_OnReadSupportedPrivileges(TSBWebDavReadSupportedPrivilegesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVACLOptions_get_OnReadSupportedPrivileges(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVACLOptions::set_OnReadSupportedPrivileges(TSBWebDavReadSupportedPrivilegesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVACLOptions_set_OnReadSupportedPrivileges(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVACLOptions::get_OnReadOwner(TSBWebDavReadOwnerEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVACLOptions_get_OnReadOwner(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVACLOptions::set_OnReadOwner(TSBWebDavReadOwnerEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVACLOptions_set_OnReadOwner(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVACLOptions::get_OnGetPrivilegeDescription(TSBWebDavGetPrivilegeDescriptionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVACLOptions_get_OnGetPrivilegeDescription(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVACLOptions::set_OnGetPrivilegeDescription(TSBWebDavGetPrivilegeDescriptionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVACLOptions_set_OnGetPrivilegeDescription(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVACLOptions::get_OnGetACLRestrictions(TSBWebDavGetACLRestrictionsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVACLOptions_get_OnGetACLRestrictions(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVACLOptions::set_OnGetACLRestrictions(TSBWebDavGetACLRestrictionsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVACLOptions_set_OnGetACLRestrictions(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVACLOptions::get_OnGetACL(TSBWebDavGetACLEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVACLOptions_get_OnGetACL(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVACLOptions::set_OnGetACL(TSBWebDavGetACLEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVACLOptions_set_OnGetACL(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVACLOptions::get_OnSetACL(TSBWebDavSetACLEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVACLOptions_get_OnSetACL(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVACLOptions::set_OnSetACL(TSBWebDavSetACLEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVACLOptions_set_OnSetACL(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElWebDAVACLOptions::get_OnGetInheritedACLSet(TSBWebDavGetURLSetEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElWebDAVACLOptions_get_OnGetInheritedACLSet(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElWebDAVACLOptions::set_OnGetInheritedACLSet(TSBWebDavGetURLSetEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElWebDAVACLOptions_set_OnGetInheritedACLSet(_Handle, pMethodValue, pDataValue));
}

void TElWebDAVACLOptions::initInstances()
{
#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND
	this->_Inst_PrincipalBackend = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND */
}

TElWebDAVACLOptions::TElWebDAVACLOptions(TElWebDAVACLOptionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElWebDAVACLOptions::TElWebDAVACLOptions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWebDAVACLOptions_Create(&_Handle));
}

TElWebDAVACLOptions::~TElWebDAVACLOptions()
{
#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND
	delete this->_Inst_PrincipalBackend;
	this->_Inst_PrincipalBackend = NULL;
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND */
}
#endif /* SB_USE_CLASS_TELWEBDAVACLOPTIONS */

#ifdef SB_USE_CLASS_TELCARDDAVOPTIONS

bool TElCardDAVOptions::get_UseCardDAV()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDAVOptions_get_UseCardDAV(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCardDAVOptions::set_UseCardDAV(bool Value)
{
	SBCheckError(TElCardDAVOptions_set_UseCardDAV(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElCardDAVOptions::get_AddressBookURLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCardDAVOptions_get_AddressBookURLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressBookURLs)
		this->_Inst_AddressBookURLs = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AddressBookURLs->updateHandle(hOutResult);
	return this->_Inst_AddressBookURLs;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElCardDAVOptions::get_AddressBookURLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCardDAVOptions_get_AddressBookURLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AddressBookURLs)
		this->_Inst_AddressBookURLs = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AddressBookURLs->updateHandle(hOutResult);
	return this->_Inst_AddressBookURLs;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int32_t TElCardDAVOptions::get_MaxResourceSize()
{
	int32_t OutResult;
	SBCheckError(TElCardDAVOptions_get_MaxResourceSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCardDAVOptions::set_MaxResourceSize(int32_t Value)
{
	SBCheckError(TElCardDAVOptions_set_MaxResourceSize(_Handle, Value));
}

SB_INLINE int32_t TElCardDAVOptions::get_NumberOfMatchesLimit()
{
	int32_t OutResult;
	SBCheckError(TElCardDAVOptions_get_NumberOfMatchesLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCardDAVOptions::set_NumberOfMatchesLimit(int32_t Value)
{
	SBCheckError(TElCardDAVOptions_set_NumberOfMatchesLimit(_Handle, Value));
}

bool TElCardDAVOptions::get_AllowExtendedMkCol()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCardDAVOptions_get_AllowExtendedMkCol(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCardDAVOptions::set_AllowExtendedMkCol(bool Value)
{
	SBCheckError(TElCardDAVOptions_set_AllowExtendedMkCol(_Handle, (int8_t)Value));
}

SB_INLINE void TElCardDAVOptions::get_OnCheckIfAddressBook(TSBWebDavCheckIfAddressBookEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCardDAVOptions_get_OnCheckIfAddressBook(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCardDAVOptions::set_OnCheckIfAddressBook(TSBWebDavCheckIfAddressBookEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCardDAVOptions_set_OnCheckIfAddressBook(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCardDAVOptions::get_OnSetAsAddressBook(TSBWebDavSetAsAddressBookEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCardDAVOptions_get_OnSetAsAddressBook(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCardDAVOptions::set_OnSetAsAddressBook(TSBWebDavSetAsAddressBookEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCardDAVOptions_set_OnSetAsAddressBook(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCardDAVOptions::get_OnCheckUIDUniqueness(TSBCheckUIDUniquenessEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCardDAVOptions_get_OnCheckUIDUniqueness(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCardDAVOptions::set_OnCheckUIDUniqueness(TSBCheckUIDUniquenessEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCardDAVOptions_set_OnCheckUIDUniqueness(_Handle, pMethodValue, pDataValue));
}

void TElCardDAVOptions::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AddressBookURLs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AddressBookURLs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElCardDAVOptions::TElCardDAVOptions(TElCardDAVOptionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCardDAVOptions::TElCardDAVOptions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCardDAVOptions_Create(&_Handle));
}

TElCardDAVOptions::~TElCardDAVOptions()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AddressBookURLs;
	this->_Inst_AddressBookURLs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AddressBookURLs;
	this->_Inst_AddressBookURLs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELCARDDAVOPTIONS */

#ifdef SB_USE_CLASS_TELCALDAVOPTIONS

bool TElCalDAVOptions::get_UseCalDAV()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCalDAVOptions_get_UseCalDAV(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCalDAVOptions::set_UseCalDAV(bool Value)
{
	SBCheckError(TElCalDAVOptions_set_UseCalDAV(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElCalDAVOptions::get_MaxResourceSize()
{
	int32_t OutResult;
	SBCheckError(TElCalDAVOptions_get_MaxResourceSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCalDAVOptions::set_MaxResourceSize(int32_t Value)
{
	SBCheckError(TElCalDAVOptions_set_MaxResourceSize(_Handle, Value));
}

SB_INLINE int64_t TElCalDAVOptions::get_MinDateTime()
{
	int64_t OutResult;
	SBCheckError(TElCalDAVOptions_get_MinDateTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCalDAVOptions::set_MinDateTime(int64_t Value)
{
	SBCheckError(TElCalDAVOptions_set_MinDateTime(_Handle, Value));
}

SB_INLINE int64_t TElCalDAVOptions::get_MaxDateTime()
{
	int64_t OutResult;
	SBCheckError(TElCalDAVOptions_get_MaxDateTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCalDAVOptions::set_MaxDateTime(int64_t Value)
{
	SBCheckError(TElCalDAVOptions_set_MaxDateTime(_Handle, Value));
}

SB_INLINE int32_t TElCalDAVOptions::get_MaxRecurrenceInstances()
{
	int32_t OutResult;
	SBCheckError(TElCalDAVOptions_get_MaxRecurrenceInstances(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCalDAVOptions::set_MaxRecurrenceInstances(int32_t Value)
{
	SBCheckError(TElCalDAVOptions_set_MaxRecurrenceInstances(_Handle, Value));
}

SB_INLINE int32_t TElCalDAVOptions::get_MaxAttendeesPerInstance()
{
	int32_t OutResult;
	SBCheckError(TElCalDAVOptions_get_MaxAttendeesPerInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCalDAVOptions::set_MaxAttendeesPerInstance(int32_t Value)
{
	SBCheckError(TElCalDAVOptions_set_MaxAttendeesPerInstance(_Handle, Value));
}

SB_INLINE void TElCalDAVOptions::get_OnCheckIfCalendar(TSBWebDavCheckIfCalendarEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCalDAVOptions_get_OnCheckIfCalendar(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCalDAVOptions::set_OnCheckIfCalendar(TSBWebDavCheckIfCalendarEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCalDAVOptions_set_OnCheckIfCalendar(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCalDAVOptions::get_OnSetAsCalendar(TSBWebDavSetAsCalendarEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCalDAVOptions_get_OnSetAsCalendar(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCalDAVOptions::set_OnSetAsCalendar(TSBWebDavSetAsCalendarEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCalDAVOptions_set_OnSetAsCalendar(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCalDAVOptions::get_OnCheckUIDUniqueness(TSBCheckUIDUniquenessEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCalDAVOptions_get_OnCheckUIDUniqueness(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCalDAVOptions::set_OnCheckUIDUniqueness(TSBCheckUIDUniquenessEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCalDAVOptions_set_OnCheckUIDUniqueness(_Handle, pMethodValue, pDataValue));
}

TElCalDAVOptions::TElCalDAVOptions(TElCalDAVOptionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCalDAVOptions::TElCalDAVOptions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCalDAVOptions_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCALDAVOPTIONS */

#ifdef SB_USE_CLASS_TELWEBDAVCOLLATION

SB_INLINE TElWebDavCollationHandle TElWebDavCollation::CreateInstance(TSBWebDavFilterTextMatchCollation Collation)
{
	TElWebDavCollationHandle OutResult;
	SBCheckError(TElWebDavCollation_CreateInstance((TSBWebDavFilterTextMatchCollationRaw)Collation, &OutResult));
	return OutResult;
}

SB_INLINE TElWebDavCollationHandle TElWebDavCollation::CreateInstance_Inst(TSBWebDavFilterTextMatchCollation Collation)
{
	TElWebDavCollationHandle OutResult;
	SBCheckError(TElWebDavCollation_CreateInstance_1(_Handle, (TSBWebDavFilterTextMatchCollationRaw)Collation, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElWebDavCollation::Compare(const std::string &S1, const std::string &S2)
{
	int32_t OutResult;
	SBCheckError(TElWebDavCollation_Compare(_Handle, S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResult));
	return OutResult;
}

bool TElWebDavCollation::StartsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavCollation_StartsWith(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavCollation::EndsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavCollation_EndsWith(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavCollation::Equals(const std::string &S1, const std::string &S2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavCollation_Equals(_Handle, S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElWebDavCollation::IndexOf(const std::string &S, const std::string &SubS)
{
	int32_t OutResult;
	SBCheckError(TElWebDavCollation_IndexOf(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResult));
	return OutResult;
}

TElWebDavCollation::TElWebDavCollation(TElWebDavCollationHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElWebDavCollation::TElWebDavCollation() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavCollation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVCOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVUNICODECOLLATION

SB_INLINE int32_t TElWebDavUnicodeCollation::Compare(const std::string &S1, const std::string &S2)
{
	int32_t OutResult;
	SBCheckError(TElWebDavUnicodeCollation_Compare(_Handle, S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResult));
	return OutResult;
}

bool TElWebDavUnicodeCollation::StartsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavUnicodeCollation_StartsWith(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavUnicodeCollation::EndsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavUnicodeCollation_EndsWith(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavUnicodeCollation::Equals(const std::string &S1, const std::string &S2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavUnicodeCollation_Equals(_Handle, S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElWebDavUnicodeCollation::IndexOf(const std::string &S, const std::string &SubS)
{
	int32_t OutResult;
	SBCheckError(TElWebDavUnicodeCollation_IndexOf(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResult));
	return OutResult;
}

TElWebDavUnicodeCollation::TElWebDavUnicodeCollation(TElWebDavUnicodeCollationHandle handle, TElOwnHandle ownHandle) : TElWebDavCollation(handle, ownHandle)
{
}

TElWebDavUnicodeCollation::TElWebDavUnicodeCollation() : TElWebDavCollation(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavUnicodeCollation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVUNICODECOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVASCIICOLLATION

SB_INLINE int32_t TElWebDavAsciiCollation::Compare(const std::string &S1, const std::string &S2)
{
	int32_t OutResult;
	SBCheckError(TElWebDavAsciiCollation_Compare(_Handle, S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResult));
	return OutResult;
}

bool TElWebDavAsciiCollation::StartsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavAsciiCollation_StartsWith(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavAsciiCollation::EndsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavAsciiCollation_EndsWith(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavAsciiCollation::Equals(const std::string &S1, const std::string &S2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavAsciiCollation_Equals(_Handle, S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElWebDavAsciiCollation::IndexOf(const std::string &S, const std::string &SubS)
{
	int32_t OutResult;
	SBCheckError(TElWebDavAsciiCollation_IndexOf(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResult));
	return OutResult;
}

TElWebDavAsciiCollation::TElWebDavAsciiCollation(TElWebDavAsciiCollationHandle handle, TElOwnHandle ownHandle) : TElWebDavCollation(handle, ownHandle)
{
}

TElWebDavAsciiCollation::TElWebDavAsciiCollation() : TElWebDavCollation(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavAsciiCollation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVASCIICOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVOCTETCOLLATION

SB_INLINE int32_t TElWebDavOctetCollation::Compare(const std::string &S1, const std::string &S2)
{
	int32_t OutResult;
	SBCheckError(TElWebDavOctetCollation_Compare(_Handle, S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResult));
	return OutResult;
}

bool TElWebDavOctetCollation::StartsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavOctetCollation_StartsWith(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavOctetCollation::EndsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavOctetCollation_EndsWith(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElWebDavOctetCollation::Equals(const std::string &S1, const std::string &S2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElWebDavOctetCollation_Equals(_Handle, S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElWebDavOctetCollation::IndexOf(const std::string &S, const std::string &SubS)
{
	int32_t OutResult;
	SBCheckError(TElWebDavOctetCollation_IndexOf(_Handle, S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResult));
	return OutResult;
}

TElWebDavOctetCollation::TElWebDavOctetCollation(TElWebDavOctetCollationHandle handle, TElOwnHandle ownHandle) : TElWebDavCollation(handle, ownHandle)
{
}

TElWebDavOctetCollation::TElWebDavOctetCollation() : TElWebDavCollation(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebDavOctetCollation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELWEBDAVOCTETCOLLATION */

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVSERVER

#ifdef SB_USE_CLASSES_TELWEBDAVLOCK_AND_TLIST
SB_INLINE TElWebDAVLockHandle FindLockInList(const TList &List, const std::string &Token)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(SBWebDAVServer_FindLockInList(List.getHandle(), Token.data(), (int32_t)Token.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElWebDAVLockHandle FindLockInList(const TList *List, const std::string &Token)
{
	TElWebDAVLockHandle OutResult;
	SBCheckError(SBWebDAVServer_FindLockInList((List != NULL) ? List->getHandle() : SB_NULL_HANDLE, Token.data(), (int32_t)Token.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELWEBDAVLOCK_AND_TLIST */

#endif /* SB_USE_GLOBAL_PROCS_WEBDAVSERVER */

};	/* namespace SecureBlackbox */
