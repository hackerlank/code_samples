#include "sbsslserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSERVERSSLCONNECTIONINFO

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElServerSSLConnectionInfo::Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession)
{
	SBCheckError(TElServerSSLConnectionInfo_Initialize(_Handle, (TSBVersionRaw)Version, Ciphersuite, ServerChain.getHandle(), ClientChain.getHandle(), SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession));
}

SB_INLINE void TElServerSSLConnectionInfo::Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession)
{
	SBCheckError(TElServerSSLConnectionInfo_Initialize(_Handle, (TSBVersionRaw)Version, Ciphersuite, (ServerChain != NULL) ? ServerChain->getHandle() : SB_NULL_HANDLE, (ClientChain != NULL) ? ClientChain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElServerSSLConnectionInfo::Initialize2(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession, int32_t ECCurve)
{
	SBCheckError(TElServerSSLConnectionInfo_Initialize2(_Handle, (TSBVersionRaw)Version, Ciphersuite, ServerChain.getHandle(), ClientChain.getHandle(), SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession, ECCurve));
}

SB_INLINE void TElServerSSLConnectionInfo::Initialize2(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession, int32_t ECCurve)
{
	SBCheckError(TElServerSSLConnectionInfo_Initialize2(_Handle, (TSBVersionRaw)Version, Ciphersuite, (ServerChain != NULL) ? ServerChain->getHandle() : SB_NULL_HANDLE, (ClientChain != NULL) ? ClientChain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession, ECCurve));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElServerSSLConnectionInfo::Reset()
{
	SBCheckError(TElServerSSLConnectionInfo_Reset(_Handle));
}

TElServerSSLConnectionInfo::TElServerSSLConnectionInfo(TElServerSSLConnectionInfoHandle handle, TElOwnHandle ownHandle) : TElSSLConnectionInfo(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSLCLASS
TElServerSSLConnectionInfo::TElServerSSLConnectionInfo(TElSSLClass &Owner) : TElSSLConnectionInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElServerSSLConnectionInfo_Create(Owner.getHandle(), &_Handle));
}

TElServerSSLConnectionInfo::TElServerSSLConnectionInfo(TElSSLClass *Owner) : TElSSLConnectionInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElServerSSLConnectionInfo_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

#endif /* SB_USE_CLASS_TELSERVERSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLSERVER

SB_INLINE void TElSSLServer::Configure(TSBServerSSLPredefinedConfiguration Configuration)
{
	SBCheckError(TElSSLServer_Configure(_Handle, (TSBServerSSLPredefinedConfigurationRaw)Configuration));
}

SB_INLINE void TElSSLServer::Open()
{
	SBCheckError(TElSSLServer_Open(_Handle));
}

SB_INLINE void TElSSLServer::Close(bool Silent)
{
	SBCheckError(TElSSLServer_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElSSLServer::SendData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSLServer_SendData(_Handle, Buffer, Size));
}

SB_INLINE void TElSSLServer::SendText(const std::vector<uint8_t> &S)
{
	SBCheckError(TElSSLServer_SendText(_Handle, SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size()));
}

bool TElSSLServer::SendKeepAlive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServer_SendKeepAlive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLServer::DataAvailable()
{
	SBCheckError(TElSSLServer_DataAvailable(_Handle));
}

void TElSSLServer::InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElSSLServer_InternalValidate(_Handle, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

SB_INLINE void TElSSLServer::RenegotiateCiphers()
{
	SBCheckError(TElSSLServer_RenegotiateCiphers(_Handle));
}

SB_INLINE void TElSSLServer::AssignFromTemplate(TElSSLClass &Tpl)
{
	SBCheckError(TElSSLServer_AssignFromTemplate(_Handle, Tpl.getHandle()));
}

SB_INLINE void TElSSLServer::AssignFromTemplate(TElSSLClass *Tpl)
{
	SBCheckError(TElSSLServer_AssignFromTemplate(_Handle, (Tpl != NULL) ? Tpl->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElSSLServer::get_CipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElSSLServer_get_CipherSuite(_Handle, &OutResult));
	return OutResult;
}

bool TElSSLServer::get_ECCurves(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServer_get_ECCurves(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLServer::set_ECCurves(int32_t Index, bool Enabled)
{
	SBCheckError(TElSSLServer_set_ECCurves(_Handle, Index, (int8_t)Enabled));
}

bool TElSSLServer::get_ECPoints(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServer_get_ECPoints(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLServer::set_ECPoints(int32_t Index, bool Enabled)
{
	SBCheckError(TElSSLServer_set_ECPoints(_Handle, Index, (int8_t)Enabled));
}

SB_INLINE int32_t TElSSLServer::get_ECCurveType()
{
	int32_t OutResult;
	SBCheckError(TElSSLServer_get_ECCurveType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLServer::set_ECCurveType(int32_t Value)
{
	SBCheckError(TElSSLServer_set_ECCurveType(_Handle, Value));
}

void TElSSLServer::get_SessionID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSLServer_get_SessionID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1810079694, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBServerState TElSSLServer::get_ServerState()
{
	TSBServerStateRaw OutResultRaw = 0;
	SBCheckError(TElSSLServer_get_ServerState(_Handle, &OutResultRaw));
	return (TSBServerState)OutResultRaw;
}

bool TElSSLServer::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServer_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLServer::set_Enabled(bool Value)
{
	SBCheckError(TElSSLServer_set_Enabled(_Handle, (int8_t)Value));
}

bool TElSSLServer::get_ClientAuthentication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServer_get_ClientAuthentication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLServer::set_ClientAuthentication(bool Value)
{
	SBCheckError(TElSSLServer_set_ClientAuthentication(_Handle, (int8_t)Value));
}

TSBAuthenticationLevel TElSSLServer::get_AuthenticationLevel()
{
	TSBAuthenticationLevelRaw OutResultRaw = 0;
	SBCheckError(TElSSLServer_get_AuthenticationLevel(_Handle, &OutResultRaw));
	return (TSBAuthenticationLevel)OutResultRaw;
}

SB_INLINE void TElSSLServer::set_AuthenticationLevel(TSBAuthenticationLevel Value)
{
	SBCheckError(TElSSLServer_set_AuthenticationLevel(_Handle, (TSBAuthenticationLevelRaw)Value));
}

bool TElSSLServer::get_ForceCertificateChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServer_get_ForceCertificateChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLServer::set_ForceCertificateChain(bool Value)
{
	SBCheckError(TElSSLServer_set_ForceCertificateChain(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSSLServer::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLServer_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElSSLServer::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSSLServer_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLServer::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSSLServer_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
TElKeyMaterialStorage* TElSSLServer::get_KeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLServer_get_KeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyStorage)
		this->_Inst_KeyStorage = new TElKeyMaterialStorage(hOutResult, ohFalse);
	else
		this->_Inst_KeyStorage->updateHandle(hOutResult);
	return this->_Inst_KeyStorage;
}

SB_INLINE void TElSSLServer::set_KeyStorage(TElKeyMaterialStorage &Value)
{
	SBCheckError(TElSSLServer_set_KeyStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLServer::set_KeyStorage(TElKeyMaterialStorage *Value)
{
	SBCheckError(TElSSLServer_set_KeyStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
TElSessionPool* TElSSLServer::get_SessionPool()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLServer_get_SessionPool(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionPool)
		this->_Inst_SessionPool = new TElSessionPool(hOutResult, ohFalse);
	else
		this->_Inst_SessionPool->updateHandle(hOutResult);
	return this->_Inst_SessionPool;
}

SB_INLINE void TElSSLServer::set_SessionPool(TElSessionPool &Value)
{
	SBCheckError(TElSSLServer_set_SessionPool(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLServer::set_SessionPool(TElSessionPool *Value)
{
	SBCheckError(TElSSLServer_set_SessionPool(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSSLServer::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLServer_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElSSLServer::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSSLServer_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLServer::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSSLServer_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
TElServerSSLExtensions* TElSSLServer::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLServer_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElServerSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
TElClientSSLExtensions* TElSSLServer::get_PeerExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLServer_get_PeerExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PeerExtensions)
		this->_Inst_PeerExtensions = new TElClientSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_PeerExtensions->updateHandle(hOutResult);
	return this->_Inst_PeerExtensions;
}
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

bool TElSSLServer::get_OnlyWithExtendedMasterSecret()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServer_get_OnlyWithExtendedMasterSecret(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLServer::set_OnlyWithExtendedMasterSecret(bool Value)
{
	SBCheckError(TElSSLServer_set_OnlyWithExtendedMasterSecret(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
TElSRPCredentialStore* TElSSLServer::get_SRPCredentialStore()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLServer_get_SRPCredentialStore(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SRPCredentialStore)
		this->_Inst_SRPCredentialStore = new TElSRPCredentialStore(hOutResult, ohFalse);
	else
		this->_Inst_SRPCredentialStore->updateHandle(hOutResult);
	return this->_Inst_SRPCredentialStore;
}

SB_INLINE void TElSSLServer::set_SRPCredentialStore(TElSRPCredentialStore &Value)
{
	SBCheckError(TElSSLServer_set_SRPCredentialStore(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLServer::set_SRPCredentialStore(TElSRPCredentialStore *Value)
{
	SBCheckError(TElSSLServer_set_SRPCredentialStore(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

SB_INLINE void TElSSLServer::get_OnGetSrpDb(TSBServerSrpDbNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLServer_get_OnGetSrpDb(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLServer::set_OnGetSrpDb(TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLServer_set_OnGetSrpDb(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLServer::get_OnKeyNeeded(TSBServerKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLServer_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLServer::set_OnKeyNeeded(TSBServerKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLServer_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLServer::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLServer_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLServer::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLServer_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLServer::get_OnRenegotiationStart(TSBRenegotiationStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLServer_get_OnRenegotiationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLServer::set_OnRenegotiationStart(TSBRenegotiationStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLServer_set_OnRenegotiationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLServer::get_OnCertificateURLs(TSBCertificateURLsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLServer_get_OnCertificateURLs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLServer::set_OnCertificateURLs(TSBCertificateURLsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLServer_set_OnCertificateURLs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLServer::get_OnSessionReused(TSBServerSessionReusedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLServer_get_OnSessionReused(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLServer::set_OnSessionReused(TSBServerSessionReusedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLServer_set_OnSessionReused(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLServer::get_OnSessionCreated(TSBServerSessionCreatedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLServer_get_OnSessionCreated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLServer::set_OnSessionCreated(TSBServerSessionCreatedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLServer_set_OnSessionCreated(_Handle, pMethodValue, pDataValue));
}

void TElSSLServer::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
	this->_Inst_SessionPool = NULL;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	this->_Inst_PeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
	this->_Inst_SRPCredentialStore = NULL;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */
}

TElSSLServer::TElSSLServer(TElSSLServerHandle handle, TElOwnHandle ownHandle) : TElSSLClass(handle, ownHandle)
{
	initInstances();
}

TElSSLServer::TElSSLServer(TComponent &Owner) : TElSSLClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLServer_Create(Owner.getHandle(), &_Handle));
}

TElSSLServer::TElSSLServer(TComponent *Owner) : TElSSLClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLServer_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSLServer::~TElSSLServer()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
	delete this->_Inst_KeyStorage;
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
	delete this->_Inst_SessionPool;
	this->_Inst_SessionPool = NULL;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	delete this->_Inst_PeerExtensions;
	this->_Inst_PeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
	delete this->_Inst_SRPCredentialStore;
	this->_Inst_SRPCredentialStore = NULL;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */
}
#endif /* SB_USE_CLASS_TELSSLSERVER */

#ifdef SB_USE_CLASS_TELSSLSERVERENVIRONMENT

bool TElSSLServerEnvironment::RegenerateDH()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServerEnvironment_RegenerateDH(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSLServerEnvironment::RegenerateDH(int32_t Bits)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServerEnvironment_RegenerateDH_1(_Handle, Bits, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSLServerEnvironment::get_Bits()
{
	int32_t OutResult;
	SBCheckError(TElSSLServerEnvironment_get_Bits(_Handle, &OutResult));
	return OutResult;
}

bool TElSSLServerEnvironment::get_UseUniqueDHKeys()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLServerEnvironment_get_UseUniqueDHKeys(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLServerEnvironment::set_UseUniqueDHKeys(bool Value)
{
	SBCheckError(TElSSLServerEnvironment_set_UseUniqueDHKeys(_Handle, (int8_t)Value));
}

TElSSLServerEnvironment::TElSSLServerEnvironment(TElSSLServerEnvironmentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSLServerEnvironment::TElSSLServerEnvironment() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLServerEnvironment_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSLSERVERENVIRONMENT */

#ifdef SB_USE_GLOBAL_PROCS_SSLSERVER

#ifdef SB_USE_CLASS_TELSSLSERVER
SB_INLINE TElSSLServerHandle CreateSSLServerTemplate(TSBServerSSLPredefinedConfiguration Config)
{
	TElSSLServerHandle OutResult;
	SBCheckError(SBSSLServer_CreateSSLServerTemplate((TSBServerSSLPredefinedConfigurationRaw)Config, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSLSERVER */

bool GetTLSCipherSuiteByCode(uint8_t B1, uint8_t B2, uint8_t &CipherSuite)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBSSLServer_GetTLSCipherSuiteByCode(B1, B2, &CipherSuite, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void PrepareSSLServerEnvironment()
{
	SBCheckError(SBSSLServer_PrepareSSLServerEnvironment());
}

SB_INLINE int32_t GetSSLDHKeyLength()
{
	int32_t OutResult;
	SBCheckError(SBSSLServer_GetSSLDHKeyLength(&OutResult));
	return OutResult;
}

SB_INLINE void SetSSLDHKeyLength(int32_t Value)
{
	SBCheckError(SBSSLServer_SetSSLDHKeyLength(Value));
}

#endif /* SB_USE_GLOBAL_PROCS_SSLSERVER */

};	/* namespace SecureBlackbox */

