#include "sbsslclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCLIENTSSLCONNECTIONINFO

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElClientSSLConnectionInfo::Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession)
{
	SBCheckError(TElClientSSLConnectionInfo_Initialize(_Handle, (TSBVersionRaw)Version, Ciphersuite, ServerChain.getHandle(), ClientChain.getHandle(), SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession));
}

SB_INLINE void TElClientSSLConnectionInfo::Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession)
{
	SBCheckError(TElClientSSLConnectionInfo_Initialize(_Handle, (TSBVersionRaw)Version, Ciphersuite, (ServerChain != NULL) ? ServerChain->getHandle() : SB_NULL_HANDLE, (ClientChain != NULL) ? ClientChain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATECHAIN
SB_INLINE void TElClientSSLConnectionInfo::Initialize2(TSBVersion Version, uint8_t Ciphersuite, TElX509CertificateChain &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession, int32_t ECCurve)
{
	SBCheckError(TElClientSSLConnectionInfo_Initialize2(_Handle, (TSBVersionRaw)Version, Ciphersuite, ServerChain.getHandle(), ClientChain.getHandle(), SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession, ECCurve));
}

SB_INLINE void TElClientSSLConnectionInfo::Initialize2(TSBVersion Version, uint8_t Ciphersuite, TElX509CertificateChain *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession, int32_t ECCurve)
{
	SBCheckError(TElClientSSLConnectionInfo_Initialize2(_Handle, (TSBVersionRaw)Version, Ciphersuite, (ServerChain != NULL) ? ServerChain->getHandle() : SB_NULL_HANDLE, (ClientChain != NULL) ? ClientChain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession, ECCurve));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATECHAIN */

SB_INLINE void TElClientSSLConnectionInfo::Reset()
{
	SBCheckError(TElClientSSLConnectionInfo_Reset(_Handle));
}

TElClientSSLConnectionInfo::TElClientSSLConnectionInfo(TElClientSSLConnectionInfoHandle handle, TElOwnHandle ownHandle) : TElSSLConnectionInfo(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSLCLASS
TElClientSSLConnectionInfo::TElClientSSLConnectionInfo(TElSSLClass &Owner) : TElSSLConnectionInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElClientSSLConnectionInfo_Create(Owner.getHandle(), &_Handle));
}

TElClientSSLConnectionInfo::TElClientSSLConnectionInfo(TElSSLClass *Owner) : TElSSLConnectionInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElClientSSLConnectionInfo_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

#endif /* SB_USE_CLASS_TELCLIENTSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLCLIENT

SB_INLINE void TElSSLClient::Open()
{
	SBCheckError(TElSSLClient_Open(_Handle));
}

SB_INLINE void TElSSLClient::Close(bool Silent)
{
	SBCheckError(TElSSLClient_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElSSLClient::DataAvailable()
{
	SBCheckError(TElSSLClient_DataAvailable(_Handle));
}

SB_INLINE void TElSSLClient::SendData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSLClient_SendData(_Handle, Buffer, Size));
}

SB_INLINE void TElSSLClient::SendText(const std::vector<uint8_t> &S)
{
	SBCheckError(TElSSLClient_SendText(_Handle, SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size()));
}

bool TElSSLClient::SendKeepAlive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClient_SendKeepAlive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSSLClient::InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElSSLClient_InternalValidate(_Handle, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

SB_INLINE void TElSSLClient::Resume()
{
	SBCheckError(TElSSLClient_Resume(_Handle));
}

SB_INLINE void TElSSLClient::Join(TElSSLClient &ElSecureClient)
{
	SBCheckError(TElSSLClient_Join(_Handle, ElSecureClient.getHandle()));
}

SB_INLINE void TElSSLClient::Join(TElSSLClient *ElSecureClient)
{
	SBCheckError(TElSSLClient_Join(_Handle, (ElSecureClient != NULL) ? ElSecureClient->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSSLClient::RenegotiateCiphers()
{
	SBCheckError(TElSSLClient_RenegotiateCiphers(_Handle));
}

SB_INLINE void TElSSLClient::AddCertificateType(TElSSLCertificateType C_Type)
{
	SBCheckError(TElSSLClient_AddCertificateType(_Handle, (TElSSLCertificateTypeRaw)C_Type));
}

SB_INLINE void TElSSLClient::DelCertificateType(TElSSLCertificateType C_Type)
{
	SBCheckError(TElSSLClient_DelCertificateType(_Handle, (TElSSLCertificateTypeRaw)C_Type));
}

SB_INLINE int32_t TElSSLClient::GetCertTypesCount()
{
	int32_t OutResult;
	SBCheckError(TElSSLClient_GetCertTypesCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLClient::ClearCertificateType()
{
	SBCheckError(TElSSLClient_ClearCertificateType(_Handle));
}

SB_INLINE void TElSSLClient::AddClientCertificateType(TElSSLCertificateType C_Type)
{
	SBCheckError(TElSSLClient_AddClientCertificateType(_Handle, (TElSSLCertificateTypeRaw)C_Type));
}

SB_INLINE void TElSSLClient::DelClientCertificateType(TElSSLCertificateType C_Type)
{
	SBCheckError(TElSSLClient_DelClientCertificateType(_Handle, (TElSSLCertificateTypeRaw)C_Type));
}

SB_INLINE int32_t TElSSLClient::GetClientCertTypesCount()
{
	int32_t OutResult;
	SBCheckError(TElSSLClient_GetClientCertTypesCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLClient::ClearClientCertificateType()
{
	SBCheckError(TElSSLClient_ClearClientCertificateType(_Handle));
}

SB_INLINE uint8_t TElSSLClient::get_CipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElSSLClient_get_CipherSuite(_Handle, &OutResult));
	return OutResult;
}

TElSSLCertificateType TElSSLClient::get_CertTypes(int32_t Index)
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_CertTypes(_Handle, Index, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

SB_INLINE void TElSSLClient::set_CertTypes(int32_t Index, TElSSLCertificateType Value)
{
	SBCheckError(TElSSLClient_set_CertTypes(_Handle, Index, (TElSSLCertificateTypeRaw)Value));
}

TElSSLCertificateType TElSSLClient::get_ClientCertTypes(int32_t Index)
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_ClientCertTypes(_Handle, Index, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

SB_INLINE void TElSSLClient::set_ClientCertTypes(int32_t Index, TElSSLCertificateType Value)
{
	SBCheckError(TElSSLClient_set_ClientCertTypes(_Handle, Index, (TElSSLCertificateTypeRaw)Value));
}

bool TElSSLClient::get_ECCurves(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_ECCurves(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLClient::set_ECCurves(int32_t Index, bool Enabled)
{
	SBCheckError(TElSSLClient_set_ECCurves(_Handle, Index, (int8_t)Enabled));
}

bool TElSSLClient::get_ECPoints(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_ECPoints(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLClient::set_ECPoints(int32_t Index, bool Enabled)
{
	SBCheckError(TElSSLClient_set_ECPoints(_Handle, Index, (int8_t)Enabled));
}

bool TElSSLClient::get_CanResume()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_CanResume(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSSL3State TElSSLClient::get_ClientState()
{
	TSSL3StateRaw OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_ClientState(_Handle, &OutResultRaw));
	return (TSSL3State)OutResultRaw;
}

bool TElSSLClient::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLClient::set_Enabled(bool Value)
{
	SBCheckError(TElSSLClient_set_Enabled(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSSLClient::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLClient_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSSLClient::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSSLClient_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLClient::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSSLClient_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

TSBCertificateTypeExtension TElSSLClient::get_UsedCertificateTypeExtension()
{
	TSBCertificateTypeExtensionRaw OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_UsedCertificateTypeExtension(_Handle, &OutResultRaw));
	return (TSBCertificateTypeExtension)OutResultRaw;
}

SB_INLINE void TElSSLClient::set_UsedCertificateTypeExtension(TSBCertificateTypeExtension Value)
{
	SBCheckError(TElSSLClient_set_UsedCertificateTypeExtension(_Handle, (TSBCertificateTypeExtensionRaw)Value));
}

bool TElSSLClient::get_UseExtendedMasterSecret()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClient_get_UseExtendedMasterSecret(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLClient::set_UseExtendedMasterSecret(bool Value)
{
	SBCheckError(TElSSLClient_set_UseExtendedMasterSecret(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSSLClient::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLClient_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElSSLClient::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSSLClient_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLClient::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSSLClient_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSSLClient::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLClient_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElSSLClient::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSSLClient_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLClient::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSSLClient_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
TElKeyMaterialStorage* TElSSLClient::get_ClientRawKeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLClient_get_ClientRawKeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientRawKeyStorage)
		this->_Inst_ClientRawKeyStorage = new TElKeyMaterialStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientRawKeyStorage->updateHandle(hOutResult);
	return this->_Inst_ClientRawKeyStorage;
}

SB_INLINE void TElSSLClient::set_ClientRawKeyStorage(TElKeyMaterialStorage &Value)
{
	SBCheckError(TElSSLClient_set_ClientRawKeyStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLClient::set_ClientRawKeyStorage(TElKeyMaterialStorage *Value)
{
	SBCheckError(TElSSLClient_set_ClientRawKeyStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
TElClientSSLExtensions* TElSSLClient::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLClient_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElClientSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
TElServerSSLExtensions* TElSSLClient::get_PeerExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLClient_get_PeerExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PeerExtensions)
		this->_Inst_PeerExtensions = new TElServerSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_PeerExtensions->updateHandle(hOutResult);
	return this->_Inst_PeerExtensions;
}
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

void TElSSLClient::get_SRPUsername(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSLClient_get_SRPUsername(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-269969591, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSLClient::set_SRPUsername(const std::string &Value)
{
	SBCheckError(TElSSLClient_set_SRPUsername(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSLClient::get_SRPPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSLClient_get_SRPPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(578082795, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSLClient::set_SRPPassword(const std::string &Value)
{
	SBCheckError(TElSSLClient_set_SRPPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElSSLClient::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClient_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClient::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClient_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClient::get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClient_get_OnCertificateChoose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClient::set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClient_set_OnCertificateChoose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClient::get_OnCertificateNeeded(TSBCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClient_get_OnCertificateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClient::set_OnCertificateNeeded(TSBCertificateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClient_set_OnCertificateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClient::get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClient_get_OnCertificateNeededEx(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClient::set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClient_set_OnCertificateNeededEx(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClient::get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClient_get_OnCertificateStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClient::set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClient_set_OnCertificateStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClient::get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClient_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClient::set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClient_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClient::get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClient_get_OnRenegotiationRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClient::set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClient_set_OnRenegotiationRequest(_Handle, pMethodValue, pDataValue));
}

void TElSSLClient::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
	this->_Inst_ClientRawKeyStorage = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
	this->_Inst_PeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
}

TElSSLClient::TElSSLClient(TElSSLClientHandle handle, TElOwnHandle ownHandle) : TElSSLClass(handle, ownHandle)
{
	initInstances();
}

TElSSLClient::TElSSLClient(TComponent &Owner) : TElSSLClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLClient_Create(Owner.getHandle(), &_Handle));
}

TElSSLClient::TElSSLClient(TComponent *Owner) : TElSSLClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLClient_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSLClient::~TElSSLClient()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
	delete this->_Inst_ClientRawKeyStorage;
	this->_Inst_ClientRawKeyStorage = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
	delete this->_Inst_PeerExtensions;
	this->_Inst_PeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELSSLCLIENT */

#ifdef SB_USE_CLASS_TELCLIENTSSLCONNECTIONSETTINGS

SB_INLINE void TElClientSSLConnectionSettings::ActivatePredefinedConfiguration(TSBClientSSLPredefinedConfiguration Config)
{
	SBCheckError(TElClientSSLConnectionSettings_ActivatePredefinedConfiguration(_Handle, (TSBClientSSLPredefinedConfigurationRaw)Config));
}

SB_INLINE void TElClientSSLConnectionSettings::EnableAllCiphers()
{
	SBCheckError(TElClientSSLConnectionSettings_EnableAllCiphers(_Handle));
}

SB_INLINE void TElClientSSLConnectionSettings::EnableAllCiphers(bool ExcludeInsecure)
{
	SBCheckError(TElClientSSLConnectionSettings_EnableAllCiphers_1(_Handle, (int8_t)ExcludeInsecure));
}

SB_INLINE void TElClientSSLConnectionSettings::EnableCiphers(int32_t MinLevel, int32_t MaxLevel)
{
	SBCheckError(TElClientSSLConnectionSettings_EnableCiphers(_Handle, MinLevel, MaxLevel));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableAllCiphers()
{
	SBCheckError(TElClientSSLConnectionSettings_DisableAllCiphers(_Handle));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableCiphers(int32_t MinLevel, int32_t MaxLevel)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableCiphers(_Handle, MinLevel, MaxLevel));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableEncryptionAlgorithm(TSBEncryptAlgorithm Algorithm)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableEncryptionAlgorithm(_Handle, (TSBEncryptAlgorithmRaw)Algorithm));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableEncryptionAlgorithm(TSBEncryptAlgorithm Algorithm, bool Inverted)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableEncryptionAlgorithm_1(_Handle, (TSBEncryptAlgorithmRaw)Algorithm, (int8_t)Inverted));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableKeyExchangeAlgorithm(TSBKeyExchangeAlgorithm Algorithm)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableKeyExchangeAlgorithm(_Handle, (TSBKeyExchangeAlgorithmRaw)Algorithm));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableKeyExchangeAlgorithm(TSBKeyExchangeAlgorithm Algorithm, bool Inverted)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableKeyExchangeAlgorithm_1(_Handle, (TSBKeyExchangeAlgorithmRaw)Algorithm, (int8_t)Inverted));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableDigestAlgorithm(TSBDigestAlgorithm Algorithm)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableDigestAlgorithm(_Handle, (TSBDigestAlgorithmRaw)Algorithm));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableDigestAlgorithm(TSBDigestAlgorithm Algorithm, bool Inverted)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableDigestAlgorithm_1(_Handle, (TSBDigestAlgorithmRaw)Algorithm, (int8_t)Inverted));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableSignatureAlgorithm(TSBSignatureAlgorithm Algorithm)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableSignatureAlgorithm(_Handle, (TSBSignatureAlgorithmRaw)Algorithm));
}

SB_INLINE void TElClientSSLConnectionSettings::DisableSignatureAlgorithm(TSBSignatureAlgorithm Algorithm, bool Inverted)
{
	SBCheckError(TElClientSSLConnectionSettings_DisableSignatureAlgorithm_1(_Handle, (TSBSignatureAlgorithmRaw)Algorithm, (int8_t)Inverted));
}

SB_INLINE void TElClientSSLConnectionSettings::Load(const std::string &S)
{
	SBCheckError(TElClientSSLConnectionSettings_Load(_Handle, S.data(), (int32_t)S.length()));
}

void TElClientSSLConnectionSettings::Save(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElClientSSLConnectionSettings_Save(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1748379183, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBVersions TElClientSSLConnectionSettings::get_Versions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElClientSSLConnectionSettings_get_Versions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElClientSSLConnectionSettings::set_Versions(TSBVersions Value)
{
	SBCheckError(TElClientSSLConnectionSettings_set_Versions(_Handle, (TSBVersionsRaw)Value));
}

TElClientSSLConnectionSettings::TElClientSSLConnectionSettings(TElClientSSLConnectionSettingsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSLCLIENT
TElClientSSLConnectionSettings::TElClientSSLConnectionSettings(TElSSLClient &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElClientSSLConnectionSettings_Create(Owner.getHandle(), &_Handle));
}

TElClientSSLConnectionSettings::TElClientSSLConnectionSettings(TElSSLClient *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElClientSSLConnectionSettings_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSLCLIENT */

#endif /* SB_USE_CLASS_TELCLIENTSSLCONNECTIONSETTINGS */

};	/* namespace SecureBlackbox */

