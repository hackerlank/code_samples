#include "sbsslcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER

TElSSLCertificateType TElSSLCertificateTypeHandler::GetCertificateType()
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLCertificateTypeHandler_GetCertificateType(_Handle, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

int32_t TElSSLCertificateTypeHandler::GetDataForRemote(int32_t CipherSuite, TSBKeyExchangeAlgorithm KeyExchange, std::vector<uint8_t> &Data, int32_t Optional)
{
	int32_t OutResult;
	int32_t szData = (int32_t)Data.size();
	uint32_t _err = TElSSLCertificateTypeHandler_GetDataForRemote(_Handle, CipherSuite, (TSBKeyExchangeAlgorithmRaw)KeyExchange, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Data), &szData, Optional, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Data.resize(szData);
		SBCheckError(SBGetLastReturnBuffer(1961643592, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Data), &szData));
	}
	else
		SBCheckError(_err);

	Data.resize(szData);
	return OutResult;
}

bool TElSSLCertificateTypeHandler::ValidateRemoteCert(const std::vector<uint8_t> &Data, int32_t Optional)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLCertificateTypeHandler_ValidateRemoteCert(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), Optional, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELKEYMATERIAL
void TElSSLCertificateTypeHandler::GetRemoteKeyMaterial(const std::vector<uint8_t> &Data, int32_t KeyType, int32_t &PKType, int32_t &KeyAlgorithm, TElKeyMaterial &KeyMaterial)
{
	TElClassHandle hKeyMaterial = KeyMaterial.getHandle();
	SBCheckError(TElSSLCertificateTypeHandler_GetRemoteKeyMaterial(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), KeyType, &PKType, &KeyAlgorithm, &hKeyMaterial));
	KeyMaterial.updateHandle(hKeyMaterial);
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE TElKeyMaterialHandle TElSSLCertificateTypeHandler::GetKeyMaterial()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElSSLCertificateTypeHandler_GetKeyMaterial(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

SB_INLINE int32_t TElSSLCertificateTypeHandler::GetPublicKeySize()
{
	int32_t OutResult;
	SBCheckError(TElSSLCertificateTypeHandler_GetPublicKeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSLCertificateTypeHandler::GetPublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSSLCertificateTypeHandler_GetPublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSLCertificateTypeHandler::get_KeyIndex()
{
	int32_t OutResult;
	SBCheckError(TElSSLCertificateTypeHandler_get_KeyIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLCertificateTypeHandler::set_KeyIndex(int32_t Value)
{
	SBCheckError(TElSSLCertificateTypeHandler_set_KeyIndex(_Handle, Value));
}

SB_INLINE int32_t TElSSLCertificateTypeHandler::get_KeyCount()
{
	int32_t OutResult;
	SBCheckError(TElSSLCertificateTypeHandler_get_KeyCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_IELSSLCERTIFICATEHANDLERCONTAINER
SB_INLINE IElSSLCertificateHandlerContainerHandle TElSSLCertificateTypeHandler::get_SSLClass()
{
	IElSSLCertificateHandlerContainerHandle OutResult;
	SBCheckError(TElSSLCertificateTypeHandler_get_SSLClass(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLCertificateTypeHandler::set_SSLClass(IElSSLCertificateHandlerContainerHandle Value)
{
	SBCheckError(TElSSLCertificateTypeHandler_set_SSLClass(_Handle, Value));
}
#endif /* SB_USE_CLASS_IELSSLCERTIFICATEHANDLERCONTAINER */

TElSSLCertificateTypeHandler::TElSSLCertificateTypeHandler(TElSSLCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElSSLCertificateTypeHandler::TElSSLCertificateTypeHandler(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLCertificateTypeHandler_Create(AOwner.getHandle(), &_Handle));
}

TElSSLCertificateTypeHandler::TElSSLCertificateTypeHandler(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLCertificateTypeHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSION

SB_INLINE void TElCustomSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElCustomSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCustomSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElCustomSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCustomSSLExtension::Clear()
{
	SBCheckError(TElCustomSSLExtension_Clear(_Handle));
}

SB_INLINE int32_t TElCustomSSLExtension::get_ExtensionType()
{
	int32_t OutResult;
	SBCheckError(TElCustomSSLExtension_get_ExtensionType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSSLExtension::set_ExtensionType(int32_t Value)
{
	SBCheckError(TElCustomSSLExtension_set_ExtensionType(_Handle, Value));
}

void TElCustomSSLExtension::get_ExtensionData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomSSLExtension_get_ExtensionData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-709854037, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSSLExtension::set_ExtensionData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomSSLExtension_set_ExtensionData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElCustomSSLExtension::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSSLExtension_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSSLExtension::set_Enabled(bool Value)
{
	SBCheckError(TElCustomSSLExtension_set_Enabled(_Handle, (int8_t)Value));
}

bool TElCustomSSLExtension::get_Server()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSSLExtension_get_Server(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSSLExtension::set_Server(bool Value)
{
	SBCheckError(TElCustomSSLExtension_set_Server(_Handle, (int8_t)Value));
}

TElCustomSSLExtension::TElCustomSSLExtension(TElCustomSSLExtensionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomSSLExtension::TElCustomSSLExtension() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLCLASS

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_INLINE void TElSSLClass::AddCertTypeHandler(TElSSLCertificateTypeHandler &Handler)
{
	SBCheckError(TElSSLClass_AddCertTypeHandler(_Handle, Handler.getHandle()));
}

SB_INLINE void TElSSLClass::AddCertTypeHandler(TElSSLCertificateTypeHandler *Handler)
{
	SBCheckError(TElSSLClass_AddCertTypeHandler(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_INLINE void TElSSLClass::RemoveCertTypeHandler(TElSSLCertificateTypeHandler &Handler)
{
	SBCheckError(TElSSLClass_RemoveCertTypeHandler(_Handle, Handler.getHandle()));
}

SB_INLINE void TElSSLClass::RemoveCertTypeHandler(TElSSLCertificateTypeHandler *Handler)
{
	SBCheckError(TElSSLClass_RemoveCertTypeHandler(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

SB_INLINE void TElSSLClass::EnterCS()
{
	SBCheckError(TElSSLClass_EnterCS(_Handle));
}

SB_INLINE void TElSSLClass::LeaveCS()
{
	SBCheckError(TElSSLClass_LeaveCS(_Handle));
}

SB_INLINE void TElSSLClass::AssignFromTemplate(TElSSLClass &Tpl)
{
	SBCheckError(TElSSLClass_AssignFromTemplate(_Handle, Tpl.getHandle()));
}

SB_INLINE void TElSSLClass::AssignFromTemplate(TElSSLClass *Tpl)
{
	SBCheckError(TElSSLClass_AssignFromTemplate(_Handle, (Tpl != NULL) ? Tpl->getHandle() : SB_NULL_HANDLE));
}

bool TElSSLClass::get_CipherSuites(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClass_get_CipherSuites(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLClass::set_CipherSuites(uint8_t Index, bool Value)
{
	SBCheckError(TElSSLClass_set_CipherSuites(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElSSLClass::get_CipherSuitePriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSSLClass_get_CipherSuitePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLClass::set_CipherSuitePriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSSLClass_set_CipherSuitePriorities(_Handle, Index, Value));
}

bool TElSSLClass::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClass_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLClass::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSSLClass_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSSLClass::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLClass_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBVersion TElSSLClass::get_CurrentVersion()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElSSLClass_get_CurrentVersion(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

SB_INLINE uint8_t TElSSLClass::get_CompressionAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElSSLClass_get_CompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSSLClass::get_TotalBytesSent()
{
	int64_t OutResult;
	SBCheckError(TElSSLClass_get_TotalBytesSent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSSLClass::get_TotalBytesReceived()
{
	int64_t OutResult;
	SBCheckError(TElSSLClass_get_TotalBytesReceived(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
TElSSLConnectionInfo* TElSSLClass::get_ConnectionInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLClass_get_ConnectionInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ConnectionInfo)
		this->_Inst_ConnectionInfo = new TElSSLConnectionInfo(hOutResult, ohFalse);
	else
		this->_Inst_ConnectionInfo->updateHandle(hOutResult);
	return this->_Inst_ConnectionInfo;
}
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

TSBVersions TElSSLClass::get_Versions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSSLClass_get_Versions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElSSLClass::set_Versions(TSBVersions Value)
{
	SBCheckError(TElSSLClass_set_Versions(_Handle, (TSBVersionsRaw)Value));
}

TSBSSLOptions TElSSLClass::get_Options()
{
	TSBSSLOptionsRaw OutResultRaw = 0;
	SBCheckError(TElSSLClass_get_Options(_Handle, &OutResultRaw));
	return (TSBSSLOptions)OutResultRaw;
}

SB_INLINE void TElSSLClass::set_Options(TSBSSLOptions Value)
{
	SBCheckError(TElSSLClass_set_Options(_Handle, (TSBSSLOptionsRaw)Value));
}

TSBRenegotiationAttackPreventionMode TElSSLClass::get_RenegotiationAttackPreventionMode()
{
	TSBRenegotiationAttackPreventionModeRaw OutResultRaw = 0;
	SBCheckError(TElSSLClass_get_RenegotiationAttackPreventionMode(_Handle, &OutResultRaw));
	return (TSBRenegotiationAttackPreventionMode)OutResultRaw;
}

SB_INLINE void TElSSLClass::set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value)
{
	SBCheckError(TElSSLClass_set_RenegotiationAttackPreventionMode(_Handle, (TSBRenegotiationAttackPreventionModeRaw)Value));
}

SB_INLINE void TElSSLClass::get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnSend(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnData(TSBDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnRawPublicKeyValidate(TSBRawPublicKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnRawPublicKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnRawPublicKeyValidate(TSBRawPublicKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnRawPublicKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLClass::get_OnKeepAliveResponse(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLClass_get_OnKeepAliveResponse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLClass::set_OnKeepAliveResponse(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLClass_set_OnKeepAliveResponse(_Handle, pMethodValue, pDataValue));
}

void TElSSLClass::initInstances()
{
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	this->_Inst_ConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
}

TElSSLClass::TElSSLClass(TElSSLClassHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSSLClass::TElSSLClass(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLClass_Create(Owner.getHandle(), &_Handle));
}

TElSSLClass::TElSSLClass(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLClass_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSLClass::~TElSSLClass()
{
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	delete this->_Inst_ConnectionInfo;
	this->_Inst_ConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO

SB_INLINE void TElSSLConnectionInfo::InitializeNonSecure()
{
	SBCheckError(TElSSLConnectionInfo_InitializeNonSecure(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElSSLConnectionInfo::Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession)
{
	SBCheckError(TElSSLConnectionInfo_Initialize(_Handle, (TSBVersionRaw)Version, Ciphersuite, ServerChain.getHandle(), ClientChain.getHandle(), SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession));
}

SB_INLINE void TElSSLConnectionInfo::Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession)
{
	SBCheckError(TElSSLConnectionInfo_Initialize(_Handle, (TSBVersionRaw)Version, Ciphersuite, (ServerChain != NULL) ? ServerChain->getHandle() : SB_NULL_HANDLE, (ClientChain != NULL) ? ClientChain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)ResumedSession));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElSSLConnectionInfo::Reset()
{
	SBCheckError(TElSSLConnectionInfo_Reset(_Handle));
}

SB_INLINE int32_t TElSSLConnectionInfo::get_Ciphersuite()
{
	int32_t OutResult;
	SBCheckError(TElSSLConnectionInfo_get_Ciphersuite(_Handle, &OutResult));
	return OutResult;
}

void TElSSLConnectionInfo::get_CiphersuiteName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSLConnectionInfo_get_CiphersuiteName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1714360999, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBEncryptAlgorithm TElSSLConnectionInfo::get_EncryptionAlgorithm()
{
	TSBEncryptAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_EncryptionAlgorithm(_Handle, &OutResultRaw));
	return (TSBEncryptAlgorithm)OutResultRaw;
}

TSBKeyExchangeAlgorithm TElSSLConnectionInfo::get_KeyExchangeAlgorithm()
{
	TSBKeyExchangeAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_KeyExchangeAlgorithm(_Handle, &OutResultRaw));
	return (TSBKeyExchangeAlgorithm)OutResultRaw;
}

TSBSignatureAlgorithm TElSSLConnectionInfo::get_SignatureAlgorithm()
{
	TSBSignatureAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_SignatureAlgorithm(_Handle, &OutResultRaw));
	return (TSBSignatureAlgorithm)OutResultRaw;
}

TSBDigestAlgorithm TElSSLConnectionInfo::get_DigestAlgorithm()
{
	TSBDigestAlgorithmRaw OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_DigestAlgorithm(_Handle, &OutResultRaw));
	return (TSBDigestAlgorithm)OutResultRaw;
}

TSBVersion TElSSLConnectionInfo::get_Version()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_Version(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

bool TElSSLConnectionInfo::get_Exportable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_Exportable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSLConnectionInfo::get_SymmetricKeyBits()
{
	int32_t OutResult;
	SBCheckError(TElSSLConnectionInfo_get_SymmetricKeyBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSLConnectionInfo::get_PublicKeyBits()
{
	int32_t OutResult;
	SBCheckError(TElSSLConnectionInfo_get_PublicKeyBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSLConnectionInfo::get_KeyExchangeKeyBits()
{
	int32_t OutResult;
	SBCheckError(TElSSLConnectionInfo_get_KeyExchangeKeyBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSLConnectionInfo::get_SymmetricBlockSize()
{
	int32_t OutResult;
	SBCheckError(TElSSLConnectionInfo_get_SymmetricBlockSize(_Handle, &OutResult));
	return OutResult;
}

bool TElSSLConnectionInfo::get_AEADCipher()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_AEADCipher(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSSLConnectionInfo::get_ClientChain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLConnectionInfo_get_ClientChain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientChain)
		this->_Inst_ClientChain = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientChain->updateHandle(hOutResult);
	return this->_Inst_ClientChain;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSSLConnectionInfo::get_ServerChain()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLConnectionInfo_get_ServerChain(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerChain)
		this->_Inst_ServerChain = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ServerChain->updateHandle(hOutResult);
	return this->_Inst_ServerChain;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElSSLConnectionInfo::get_SessionID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSLConnectionInfo_get_SessionID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1074069997, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSSLConnectionInfo::get_ResumedSession()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_ResumedSession(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSLConnectionInfo::get_ConnectionEstablished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_ConnectionEstablished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSLConnectionInfo::get_PFSCipher()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_PFSCipher(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSLConnectionInfo::get_ClientAuthenticated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_ClientAuthenticated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSLConnectionInfo::get_ServerAuthenticated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_ServerAuthenticated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSLConnectionInfo::get_SecureConnection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLConnectionInfo_get_SecureConnection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSLConnectionInfo::get_NamedECCurve()
{
	int32_t OutResult;
	SBCheckError(TElSSLConnectionInfo_get_NamedECCurve(_Handle, &OutResult));
	return OutResult;
}

void TElSSLConnectionInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientChain = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ServerChain = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElSSLConnectionInfo::TElSSLConnectionInfo(TElSSLConnectionInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSLCLASS
TElSSLConnectionInfo::TElSSLConnectionInfo(TElSSLClass &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLConnectionInfo_Create(Owner.getHandle(), &_Handle));
}

TElSSLConnectionInfo::TElSSLConnectionInfo(TElSSLClass *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLConnectionInfo_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

TElSSLConnectionInfo::~TElSSLConnectionInfo()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientChain;
	this->_Inst_ClientChain = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ServerChain;
	this->_Inst_ServerChain = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLSERVERNAME

TSBSSLServerNameType TElSSLServerName::get_NameType()
{
	TSBSSLServerNameTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLServerName_get_NameType(_Handle, &OutResultRaw));
	return (TSBSSLServerNameType)OutResultRaw;
}

SB_INLINE void TElSSLServerName::set_NameType(TSBSSLServerNameType Value)
{
	SBCheckError(TElSSLServerName_set_NameType(_Handle, (TSBSSLServerNameTypeRaw)Value));
}

void TElSSLServerName::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSLServerName_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-828282214, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSLServerName::set_Name(const std::string &Value)
{
	SBCheckError(TElSSLServerName_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSSLServerName::TElSSLServerName(TElSSLServerNameHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSLServerName::TElSSLServerName() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLServerName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSLSERVERNAME */

#ifdef SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION

SB_INLINE void TElHeartbeatHelloSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElHeartbeatHelloSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElHeartbeatHelloSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElHeartbeatHelloSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElHeartbeatHelloSSLExtension::get_Mode()
{
	uint8_t OutResult;
	SBCheckError(TElHeartbeatHelloSSLExtension_get_Mode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHeartbeatHelloSSLExtension::set_Mode(uint8_t Value)
{
	SBCheckError(TElHeartbeatHelloSSLExtension_set_Mode(_Handle, Value));
}

TElHeartbeatHelloSSLExtension::TElHeartbeatHelloSSLExtension(TElHeartbeatHelloSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElHeartbeatHelloSSLExtension::TElHeartbeatHelloSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHeartbeatHelloSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSERVERNAMESSLEXTENSION

SB_INLINE void TElServerNameSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElServerNameSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElServerNameSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElServerNameSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElServerNameSSLExtension::Add()
{
	int32_t OutResult;
	SBCheckError(TElServerNameSSLExtension_Add(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElServerNameSSLExtension::Remove(int32_t Index)
{
	SBCheckError(TElServerNameSSLExtension_Remove(_Handle, Index));
}

SB_INLINE void TElServerNameSSLExtension::Clear()
{
	SBCheckError(TElServerNameSSLExtension_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELSSLSERVERNAME
TElSSLServerName* TElServerNameSSLExtension::get_Names(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElServerNameSSLExtension_get_Names(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Names)
		this->_Inst_Names = new TElSSLServerName(hOutResult, ohFalse);
	else
		this->_Inst_Names->updateHandle(hOutResult);
	return this->_Inst_Names;
}
#endif /* SB_USE_CLASS_TELSSLSERVERNAME */

SB_INLINE int32_t TElServerNameSSLExtension::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElServerNameSSLExtension_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElServerNameSSLExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELSSLSERVERNAME
	this->_Inst_Names = NULL;
#endif /* SB_USE_CLASS_TELSSLSERVERNAME */
}

TElServerNameSSLExtension::TElServerNameSSLExtension(TElServerNameSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
	initInstances();
}

TElServerNameSSLExtension::TElServerNameSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElServerNameSSLExtension_Create(&_Handle));
}

TElServerNameSSLExtension::~TElServerNameSSLExtension()
{
#ifdef SB_USE_CLASS_TELSSLSERVERNAME
	delete this->_Inst_Names;
	this->_Inst_Names = NULL;
#endif /* SB_USE_CLASS_TELSSLSERVERNAME */
}
#endif /* SB_USE_CLASS_TELSERVERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELUSERNAMESSLEXTENSION

SB_INLINE void TElUserNameSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElUserNameSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElUserNameSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElUserNameSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElUserNameSSLExtension::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElUserNameSSLExtension_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2106159337, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUserNameSSLExtension::set_Name(const std::string &Value)
{
	SBCheckError(TElUserNameSSLExtension_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

TElUserNameSSLExtension::TElUserNameSSLExtension(TElUserNameSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElUserNameSSLExtension::TElUserNameSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUserNameSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELUSERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECCURVESSLEXTENSION

SB_INLINE void TElECCurveSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElECCurveSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElECCurveSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElECCurveSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElECCurveSSLExtension::SetCurves(int32_t Curve, bool Enabled)
{
	SBCheckError(TElECCurveSSLExtension_SetCurves(_Handle, Curve, (int8_t)Enabled));
}

bool TElECCurveSSLExtension::IsCurveEnabled(int32_t Curve)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECCurveSSLExtension_IsCurveEnabled(_Handle, Curve, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElECCurveSSLExtension::GetCurve(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElECCurveSSLExtension_GetCurve(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECCurveSSLExtension::GetCurveCount()
{
	int32_t OutResult;
	SBCheckError(TElECCurveSSLExtension_GetCurveCount(_Handle, &OutResult));
	return OutResult;
}

TElECCurveSSLExtension::TElECCurveSSLExtension(TElECCurveSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElECCurveSSLExtension::TElECCurveSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECCurveSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELECCURVESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECPOINTSSLEXTENSION

SB_INLINE void TElECPointSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElECPointSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElECPointSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElECPointSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElECPointSSLExtension::SetPointType(uint8_t Point, bool Enabled)
{
	SBCheckError(TElECPointSSLExtension_SetPointType(_Handle, Point, (int8_t)Enabled));
}

bool TElECPointSSLExtension::GetPointType(uint8_t Point)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECPointSSLExtension_GetPointType(_Handle, Point, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElECPointSSLExtension::TElECPointSSLExtension(TElECPointSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElECPointSSLExtension::TElECPointSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECPointSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELECPOINTSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE

SB_INLINE void TElCertificateTypeResponse::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElCertificateTypeResponse_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCertificateTypeResponse::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElCertificateTypeResponse_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElSSLCertificateType TElCertificateTypeResponse::get_CertType()
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElCertificateTypeResponse_get_CertType(_Handle, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

SB_INLINE void TElCertificateTypeResponse::set_CertType(TElSSLCertificateType Value)
{
	SBCheckError(TElCertificateTypeResponse_set_CertType(_Handle, (TElSSLCertificateTypeRaw)Value));
}

TElCertificateTypeResponse::TElCertificateTypeResponse(TElCertificateTypeResponseHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElCertificateTypeResponse::TElCertificateTypeResponse() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCertificateTypeResponse_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST

SB_INLINE void TElCertificateTypeRequest::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElCertificateTypeRequest_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCertificateTypeRequest::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElCertificateTypeRequest_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCertificateTypeRequest::AddCertType(TElSSLCertificateType Value)
{
	SBCheckError(TElCertificateTypeRequest_AddCertType(_Handle, (TElSSLCertificateTypeRaw)Value));
}

SB_INLINE void TElCertificateTypeRequest::DelCertType(TElSSLCertificateType Value)
{
	SBCheckError(TElCertificateTypeRequest_DelCertType(_Handle, (TElSSLCertificateTypeRaw)Value));
}

SB_INLINE int32_t TElCertificateTypeRequest::GetCertTypesCount()
{
	int32_t OutResult;
	SBCheckError(TElCertificateTypeRequest_GetCertTypesCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateTypeRequest::ClearCertTypes()
{
	SBCheckError(TElCertificateTypeRequest_ClearCertTypes(_Handle));
}

bool TElCertificateTypeRequest::CheckCertType(TElSSLCertificateType Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateTypeRequest_CheckCertType(_Handle, (TElSSLCertificateTypeRaw)Value, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElSSLCertificateType TElCertificateTypeRequest::GetBaseCertType()
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElCertificateTypeRequest_GetBaseCertType(_Handle, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

TElSSLCertificateType TElCertificateTypeRequest::get_CertTypes(int32_t Index)
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElCertificateTypeRequest_get_CertTypes(_Handle, Index, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

SB_INLINE void TElCertificateTypeRequest::set_CertTypes(int32_t Index, TElSSLCertificateType Value)
{
	SBCheckError(TElCertificateTypeRequest_set_CertTypes(_Handle, Index, (TElSSLCertificateTypeRaw)Value));
}

TElCertificateTypeRequest::TElCertificateTypeRequest(TElCertificateTypeRequestHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElCertificateTypeRequest::TElCertificateTypeRequest() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCertificateTypeRequest_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */

#ifdef SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION

SB_INLINE void TElExtendedMasterSecretExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElExtendedMasterSecretExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElExtendedMasterSecretExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElExtendedMasterSecretExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElExtendedMasterSecretExtension::TElExtendedMasterSecretExtension(TElExtendedMasterSecretExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElExtendedMasterSecretExtension::TElExtendedMasterSecretExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElExtendedMasterSecretExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION */

#ifdef SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION

SB_INLINE void TElMaxFragmentLengthSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElMaxFragmentLengthSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElMaxFragmentLengthSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElMaxFragmentLengthSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElMaxFragmentLengthSSLExtension::Clear()
{
	SBCheckError(TElMaxFragmentLengthSSLExtension_Clear(_Handle));
}

TSBSSLFragmentLength TElMaxFragmentLengthSSLExtension::get_MaxLength()
{
	TSBSSLFragmentLengthRaw OutResultRaw = 0;
	SBCheckError(TElMaxFragmentLengthSSLExtension_get_MaxLength(_Handle, &OutResultRaw));
	return (TSBSSLFragmentLength)OutResultRaw;
}

SB_INLINE void TElMaxFragmentLengthSSLExtension::set_MaxLength(TSBSSLFragmentLength Value)
{
	SBCheckError(TElMaxFragmentLengthSSLExtension_set_MaxLength(_Handle, (TSBSSLFragmentLengthRaw)Value));
}

TElMaxFragmentLengthSSLExtension::TElMaxFragmentLengthSSLExtension(TElMaxFragmentLengthSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElMaxFragmentLengthSSLExtension::TElMaxFragmentLengthSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMaxFragmentLengthSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLCERTURL

void TElSSLCertURL::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSLCertURL_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1706500207, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSLCertURL::set_URL(const std::string &Value)
{
	SBCheckError(TElSSLCertURL_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSLCertURL::get_Hash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSLCertURL_get_Hash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(410778832, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSLCertURL::set_Hash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSLCertURL_set_Hash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
TElPublicKeyMaterial* TElSSLCertURL::get_PrivateKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLCertURL_get_PrivateKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PrivateKey)
		this->_Inst_PrivateKey = new TElPublicKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_PrivateKey->updateHandle(hOutResult);
	return this->_Inst_PrivateKey;
}

SB_INLINE void TElSSLCertURL::set_PrivateKey(TElPublicKeyMaterial &Value)
{
	SBCheckError(TElSSLCertURL_set_PrivateKey(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLCertURL::set_PrivateKey(TElPublicKeyMaterial *Value)
{
	SBCheckError(TElSSLCertURL_set_PrivateKey(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

void TElSSLCertURL::initInstances()
{
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	this->_Inst_PrivateKey = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
}

TElSSLCertURL::TElSSLCertURL(TElSSLCertURLHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSSLCertURL::TElSSLCertURL() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLCertURL_Create(&_Handle));
}

TElSSLCertURL::~TElSSLCertURL()
{
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	delete this->_Inst_PrivateKey;
	this->_Inst_PrivateKey = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELSSLCERTURL */

#ifdef SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION

SB_INLINE void TElClientCertURLsSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElClientCertURLsSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElClientCertURLsSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElClientCertURLsSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElClientCertURLsSSLExtension::Add()
{
	int32_t OutResult;
	SBCheckError(TElClientCertURLsSSLExtension_Add(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElClientCertURLsSSLExtension::Remove(int32_t Index)
{
	SBCheckError(TElClientCertURLsSSLExtension_Remove(_Handle, Index));
}

SB_INLINE void TElClientCertURLsSSLExtension::Clear()
{
	SBCheckError(TElClientCertURLsSSLExtension_Clear(_Handle));
}

TSBCertChainType TElClientCertURLsSSLExtension::get_ChainType()
{
	TSBCertChainTypeRaw OutResultRaw = 0;
	SBCheckError(TElClientCertURLsSSLExtension_get_ChainType(_Handle, &OutResultRaw));
	return (TSBCertChainType)OutResultRaw;
}

SB_INLINE void TElClientCertURLsSSLExtension::set_ChainType(TSBCertChainType Value)
{
	SBCheckError(TElClientCertURLsSSLExtension_set_ChainType(_Handle, (TSBCertChainTypeRaw)Value));
}

#ifdef SB_USE_CLASS_TELSSLCERTURL
TElSSLCertURL* TElClientCertURLsSSLExtension::get_URLs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElClientCertURLsSSLExtension_get_URLs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URLs)
		this->_Inst_URLs = new TElSSLCertURL(hOutResult, ohFalse);
	else
		this->_Inst_URLs->updateHandle(hOutResult);
	return this->_Inst_URLs;
}
#endif /* SB_USE_CLASS_TELSSLCERTURL */

SB_INLINE int32_t TElClientCertURLsSSLExtension::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElClientCertURLsSSLExtension_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElClientCertURLsSSLExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELSSLCERTURL
	this->_Inst_URLs = NULL;
#endif /* SB_USE_CLASS_TELSSLCERTURL */
}

TElClientCertURLsSSLExtension::TElClientCertURLsSSLExtension(TElClientCertURLsSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
	initInstances();
}

TElClientCertURLsSSLExtension::TElClientCertURLsSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElClientCertURLsSSLExtension_Create(&_Handle));
}

TElClientCertURLsSSLExtension::~TElClientCertURLsSSLExtension()
{
#ifdef SB_USE_CLASS_TELSSLCERTURL
	delete this->_Inst_URLs;
	this->_Inst_URLs = NULL;
#endif /* SB_USE_CLASS_TELSSLCERTURL */
}
#endif /* SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLTRUSTEDCA

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElSSLTrustedCA::Import(TElX509Certificate &Cert)
{
	SBCheckError(TElSSLTrustedCA_Import(_Handle, Cert.getHandle()));
}

SB_INLINE void TElSSLTrustedCA::Import(TElX509Certificate *Cert)
{
	SBCheckError(TElSSLTrustedCA_Import(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

TSBCAIdentifierType TElSSLTrustedCA::get_IdentifierType()
{
	TSBCAIdentifierTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLTrustedCA_get_IdentifierType(_Handle, &OutResultRaw));
	return (TSBCAIdentifierType)OutResultRaw;
}

SB_INLINE void TElSSLTrustedCA::set_IdentifierType(TSBCAIdentifierType Value)
{
	SBCheckError(TElSSLTrustedCA_set_IdentifierType(_Handle, (TSBCAIdentifierTypeRaw)Value));
}

void TElSSLTrustedCA::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSLTrustedCA_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1684255819, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSLTrustedCA::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSLTrustedCA_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElSSLTrustedCA::get_RDN()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLTrustedCA_get_RDN(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RDN)
		this->_Inst_RDN = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_RDN->updateHandle(hOutResult);
	return this->_Inst_RDN;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElSSLTrustedCA::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_RDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElSSLTrustedCA::TElSSLTrustedCA(TElSSLTrustedCAHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSSLTrustedCA::TElSSLTrustedCA() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLTrustedCA_Create(&_Handle));
}

TElSSLTrustedCA::~TElSSLTrustedCA()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_RDN;
	this->_Inst_RDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELSSLTRUSTEDCA */

#ifdef SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION

SB_INLINE void TElTrustedCAsSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElTrustedCAsSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElTrustedCAsSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElTrustedCAsSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElTrustedCAsSSLExtension::Add()
{
	int32_t OutResult;
	SBCheckError(TElTrustedCAsSSLExtension_Add(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTrustedCAsSSLExtension::Remove(int32_t Index)
{
	SBCheckError(TElTrustedCAsSSLExtension_Remove(_Handle, Index));
}

SB_INLINE void TElTrustedCAsSSLExtension::Clear()
{
	SBCheckError(TElTrustedCAsSSLExtension_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELSSLTRUSTEDCA
TElSSLTrustedCA* TElTrustedCAsSSLExtension::get_TrustedCAs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTrustedCAsSSLExtension_get_TrustedCAs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedCAs)
		this->_Inst_TrustedCAs = new TElSSLTrustedCA(hOutResult, ohFalse);
	else
		this->_Inst_TrustedCAs->updateHandle(hOutResult);
	return this->_Inst_TrustedCAs;
}
#endif /* SB_USE_CLASS_TELSSLTRUSTEDCA */

SB_INLINE int32_t TElTrustedCAsSSLExtension::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElTrustedCAsSSLExtension_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElTrustedCAsSSLExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELSSLTRUSTEDCA
	this->_Inst_TrustedCAs = NULL;
#endif /* SB_USE_CLASS_TELSSLTRUSTEDCA */
}

TElTrustedCAsSSLExtension::TElTrustedCAsSSLExtension(TElTrustedCAsSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
	initInstances();
}

TElTrustedCAsSSLExtension::TElTrustedCAsSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTrustedCAsSSLExtension_Create(&_Handle));
}

TElTrustedCAsSSLExtension::~TElTrustedCAsSSLExtension()
{
#ifdef SB_USE_CLASS_TELSSLTRUSTEDCA
	delete this->_Inst_TrustedCAs;
	this->_Inst_TrustedCAs = NULL;
#endif /* SB_USE_CLASS_TELSSLTRUSTEDCA */
}
#endif /* SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION */

#ifdef SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION

SB_INLINE void TElTruncatedHMACSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElTruncatedHMACSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElTruncatedHMACSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElTruncatedHMACSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElTruncatedHMACSSLExtension::TElTruncatedHMACSSLExtension(TElTruncatedHMACSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElTruncatedHMACSSLExtension::TElTruncatedHMACSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTruncatedHMACSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST

void TElSSLOCSPStatusRequest::get_ResponderIDs(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSLOCSPStatusRequest_get_ResponderIDs(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1476514730, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSLOCSPStatusRequest::set_ResponderIDs(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSLOCSPStatusRequest_set_ResponderIDs(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElSSLOCSPStatusRequest::get_ResponderIDCount()
{
	int32_t OutResult;
	SBCheckError(TElSSLOCSPStatusRequest_get_ResponderIDCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLOCSPStatusRequest::set_ResponderIDCount(int32_t Value)
{
	SBCheckError(TElSSLOCSPStatusRequest_set_ResponderIDCount(_Handle, Value));
}

void TElSSLOCSPStatusRequest::get_Extensions(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSLOCSPStatusRequest_get_Extensions(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2034806002, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSLOCSPStatusRequest::set_Extensions(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSLOCSPStatusRequest_set_Extensions(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElSSLOCSPStatusRequest::TElSSLOCSPStatusRequest(TElSSLOCSPStatusRequestHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSLOCSPStatusRequest::TElSSLOCSPStatusRequest() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLOCSPStatusRequest_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */

#ifdef SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION

SB_INLINE void TElCertificateStatusSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElCertificateStatusSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCertificateStatusSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElCertificateStatusSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCertificateStatusSSLExtension::Clear()
{
	SBCheckError(TElCertificateStatusSSLExtension_Clear(_Handle));
}

SB_INLINE int32_t TElCertificateStatusSSLExtension::AddOCSPStatusRequest()
{
	int32_t OutResult;
	SBCheckError(TElCertificateStatusSSLExtension_AddOCSPStatusRequest(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateStatusSSLExtension::RemoveOCSPStatusRequest(int32_t Index)
{
	SBCheckError(TElCertificateStatusSSLExtension_RemoveOCSPStatusRequest(_Handle, Index));
}

TSBCertificateStatusType TElCertificateStatusSSLExtension::get_StatusType()
{
	TSBCertificateStatusTypeRaw OutResultRaw = 0;
	SBCheckError(TElCertificateStatusSSLExtension_get_StatusType(_Handle, &OutResultRaw));
	return (TSBCertificateStatusType)OutResultRaw;
}

SB_INLINE void TElCertificateStatusSSLExtension::set_StatusType(TSBCertificateStatusType Value)
{
	SBCheckError(TElCertificateStatusSSLExtension_set_StatusType(_Handle, (TSBCertificateStatusTypeRaw)Value));
}

#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
TElSSLOCSPStatusRequest* TElCertificateStatusSSLExtension::get_OCSPStatusRequest()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateStatusSSLExtension_get_OCSPStatusRequest(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPStatusRequest)
		this->_Inst_OCSPStatusRequest = new TElSSLOCSPStatusRequest(hOutResult, ohFalse);
	else
		this->_Inst_OCSPStatusRequest->updateHandle(hOutResult);
	return this->_Inst_OCSPStatusRequest;
}
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */

#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
TElSSLOCSPStatusRequest* TElCertificateStatusSSLExtension::get_OCSPStatusRequests(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateStatusSSLExtension_get_OCSPStatusRequests(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPStatusRequests)
		this->_Inst_OCSPStatusRequests = new TElSSLOCSPStatusRequest(hOutResult, ohFalse);
	else
		this->_Inst_OCSPStatusRequests->updateHandle(hOutResult);
	return this->_Inst_OCSPStatusRequests;
}
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */

SB_INLINE int32_t TElCertificateStatusSSLExtension::get_OCSPStatusRequestCount()
{
	int32_t OutResult;
	SBCheckError(TElCertificateStatusSSLExtension_get_OCSPStatusRequestCount(_Handle, &OutResult));
	return OutResult;
}

void TElCertificateStatusSSLExtension::get_OCSPResponse(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateStatusSSLExtension_get_OCSPResponse(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(108182410, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCertificateStatusSSLExtension::set_OCSPResponse(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCertificateStatusSSLExtension_set_OCSPResponse(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCertificateStatusSSLExtension::get_OCSPResponses(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateStatusSSLExtension_get_OCSPResponses(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2105687926, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCertificateStatusSSLExtension::set_OCSPResponses(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCertificateStatusSSLExtension_set_OCSPResponses(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElCertificateStatusSSLExtension::get_OCSPResponseCount()
{
	int32_t OutResult;
	SBCheckError(TElCertificateStatusSSLExtension_get_OCSPResponseCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateStatusSSLExtension::set_OCSPResponseCount(int32_t Value)
{
	SBCheckError(TElCertificateStatusSSLExtension_set_OCSPResponseCount(_Handle, Value));
}

void TElCertificateStatusSSLExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
	this->_Inst_OCSPStatusRequest = NULL;
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */
#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
	this->_Inst_OCSPStatusRequests = NULL;
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */
}

TElCertificateStatusSSLExtension::TElCertificateStatusSSLExtension(TElCertificateStatusSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
	initInstances();
}

TElCertificateStatusSSLExtension::TElCertificateStatusSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateStatusSSLExtension_Create(&_Handle));
}

TElCertificateStatusSSLExtension::~TElCertificateStatusSSLExtension()
{
#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
	delete this->_Inst_OCSPStatusRequest;
	this->_Inst_OCSPStatusRequest = NULL;
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */
#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
	delete this->_Inst_OCSPStatusRequests;
	this->_Inst_OCSPStatusRequests = NULL;
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */
}
#endif /* SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSESSIONTICKETSSLEXTENSION

SB_INLINE void TElSessionTicketSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElSessionTicketSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSessionTicketSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElSessionTicketSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSessionTicketSSLExtension::Clear()
{
	SBCheckError(TElSessionTicketSSLExtension_Clear(_Handle));
}

void TElSessionTicketSSLExtension::get_Ticket(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSessionTicketSSLExtension_get_Ticket(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1062732076, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSessionTicketSSLExtension::set_Ticket(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSessionTicketSSLExtension_set_Ticket(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElSessionTicketSSLExtension::TElSessionTicketSSLExtension(TElSessionTicketSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElSessionTicketSSLExtension::TElSessionTicketSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSessionTicketSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSESSIONTICKETSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION

SB_INLINE void TElCertHashTypesSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElCertHashTypesSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCertHashTypesSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElCertHashTypesSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCertHashTypesSSLExtension::Clear()
{
	SBCheckError(TElCertHashTypesSSLExtension_Clear(_Handle));
}

SB_INLINE void TElCertHashTypesSSLExtension::SwitchAll(bool Value)
{
	SBCheckError(TElCertHashTypesSSLExtension_SwitchAll(_Handle, (int8_t)Value));
}

bool TElCertHashTypesSSLExtension::get_MD5()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertHashTypesSSLExtension_get_MD5(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCertHashTypesSSLExtension::set_MD5(bool Value)
{
	SBCheckError(TElCertHashTypesSSLExtension_set_MD5(_Handle, (int8_t)Value));
}

bool TElCertHashTypesSSLExtension::get_SHA1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertHashTypesSSLExtension_get_SHA1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCertHashTypesSSLExtension::set_SHA1(bool Value)
{
	SBCheckError(TElCertHashTypesSSLExtension_set_SHA1(_Handle, (int8_t)Value));
}

bool TElCertHashTypesSSLExtension::get_SHA256()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertHashTypesSSLExtension_get_SHA256(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCertHashTypesSSLExtension::set_SHA256(bool Value)
{
	SBCheckError(TElCertHashTypesSSLExtension_set_SHA256(_Handle, (int8_t)Value));
}

bool TElCertHashTypesSSLExtension::get_SHA384()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertHashTypesSSLExtension_get_SHA384(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCertHashTypesSSLExtension::set_SHA384(bool Value)
{
	SBCheckError(TElCertHashTypesSSLExtension_set_SHA384(_Handle, (int8_t)Value));
}

bool TElCertHashTypesSSLExtension::get_SHA512()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertHashTypesSSLExtension_get_SHA512(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCertHashTypesSSLExtension::set_SHA512(bool Value)
{
	SBCheckError(TElCertHashTypesSSLExtension_set_SHA512(_Handle, (int8_t)Value));
}

TElCertHashTypesSSLExtension::TElCertHashTypesSSLExtension(TElCertHashTypesSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElCertHashTypesSSLExtension::TElCertHashTypesSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCertHashTypesSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION */

#ifdef SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION

SB_INLINE void TElRenegotiationInfoSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElRenegotiationInfoSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElRenegotiationInfoSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElRenegotiationInfoSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElRenegotiationInfoSSLExtension::Clear()
{
	SBCheckError(TElRenegotiationInfoSSLExtension_Clear(_Handle));
}

void TElRenegotiationInfoSSLExtension::get_Info(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRenegotiationInfoSSLExtension_get_Info(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1989620118, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRenegotiationInfoSSLExtension::set_Info(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRenegotiationInfoSSLExtension_set_Info(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElRenegotiationInfoSSLExtension::get_UseSignalingCipherSuite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRenegotiationInfoSSLExtension_get_UseSignalingCipherSuite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRenegotiationInfoSSLExtension::set_UseSignalingCipherSuite(bool Value)
{
	SBCheckError(TElRenegotiationInfoSSLExtension_set_UseSignalingCipherSuite(_Handle, (int8_t)Value));
}

TElRenegotiationInfoSSLExtension::TElRenegotiationInfoSSLExtension(TElRenegotiationInfoSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElRenegotiationInfoSSLExtension::TElRenegotiationInfoSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRenegotiationInfoSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION

SB_INLINE void TElSignatureAlgorithmsSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElSignatureAlgorithmsSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSignatureAlgorithmsSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElSignatureAlgorithmsSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSignatureAlgorithmsSSLExtension::Clear()
{
	SBCheckError(TElSignatureAlgorithmsSSLExtension_Clear(_Handle));
}

SB_INLINE void TElSignatureAlgorithmsSSLExtension::EnableAllSupported()
{
	SBCheckError(TElSignatureAlgorithmsSSLExtension_EnableAllSupported(_Handle));
}

SB_INLINE int32_t TElSignatureAlgorithmsSSLExtension::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElSignatureAlgorithmsSSLExtension_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSignatureAlgorithmsSSLExtension::set_Count(int32_t Value)
{
	SBCheckError(TElSignatureAlgorithmsSSLExtension_set_Count(_Handle, Value));
}

SB_INLINE int32_t TElSignatureAlgorithmsSSLExtension::get_HashAlgorithms(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSignatureAlgorithmsSSLExtension_get_HashAlgorithms(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSignatureAlgorithmsSSLExtension::set_HashAlgorithms(int32_t Index, int32_t Value)
{
	SBCheckError(TElSignatureAlgorithmsSSLExtension_set_HashAlgorithms(_Handle, Index, Value));
}

SB_INLINE int32_t TElSignatureAlgorithmsSSLExtension::get_SignatureAlgorithms(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSignatureAlgorithmsSSLExtension_get_SignatureAlgorithms(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSignatureAlgorithmsSSLExtension::set_SignatureAlgorithms(int32_t Index, int32_t Value)
{
	SBCheckError(TElSignatureAlgorithmsSSLExtension_set_SignatureAlgorithms(_Handle, Index, Value));
}

TElSignatureAlgorithmsSSLExtension::TElSignatureAlgorithmsSSLExtension(TElSignatureAlgorithmsSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElSignatureAlgorithmsSSLExtension::TElSignatureAlgorithmsSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSignatureAlgorithmsSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSRPSSLEXTENSION

SB_INLINE void TElSRPSSLExtension::Assign(TElCustomSSLExtension &Source)
{
	SBCheckError(TElSRPSSLExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSRPSSLExtension::Assign(TElCustomSSLExtension *Source)
{
	SBCheckError(TElSRPSSLExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElSRPSSLExtension::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSRPSSLExtension_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(9968603, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSRPSSLExtension::set_Name(const std::string &Value)
{
	SBCheckError(TElSRPSSLExtension_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSRPSSLExtension::TElSRPSSLExtension(TElSRPSSLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtension(handle, ownHandle)
{
}

TElSRPSSLExtension::TElSRPSSLExtension() : TElCustomSSLExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPSSLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSRPSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS

SB_INLINE void TElCustomSSLExtensions::Assign(TElCustomSSLExtensions &Source)
{
	SBCheckError(TElCustomSSLExtensions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCustomSSLExtensions::Assign(TElCustomSSLExtensions *Source)
{
	SBCheckError(TElCustomSSLExtensions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCustomSSLExtensions::Clear()
{
	SBCheckError(TElCustomSSLExtensions_Clear(_Handle));
}

SB_INLINE void TElCustomSSLExtensions::DisableAll()
{
	SBCheckError(TElCustomSSLExtensions_DisableAll(_Handle));
}

#ifdef SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION
TElCertificateStatusSSLExtension* TElCustomSSLExtensions::get_CertificateStatus()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_CertificateStatus(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateStatus)
		this->_Inst_CertificateStatus = new TElCertificateStatusSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_CertificateStatus->updateHandle(hOutResult);
	return this->_Inst_CertificateStatus;
}
#endif /* SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION
TElClientCertURLsSSLExtension* TElCustomSSLExtensions::get_ClientCertURLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_ClientCertURLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertURLs)
		this->_Inst_ClientCertURLs = new TElClientCertURLsSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertURLs->updateHandle(hOutResult);
	return this->_Inst_ClientCertURLs;
}
#endif /* SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION
TElMaxFragmentLengthSSLExtension* TElCustomSSLExtensions::get_MaxFragmentLength()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_MaxFragmentLength(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MaxFragmentLength)
		this->_Inst_MaxFragmentLength = new TElMaxFragmentLengthSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_MaxFragmentLength->updateHandle(hOutResult);
	return this->_Inst_MaxFragmentLength;
}
#endif /* SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION */

SB_INLINE int32_t TElCustomSSLExtensions::get_OtherCount()
{
	int32_t OutResult;
	SBCheckError(TElCustomSSLExtensions_get_OtherCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSSLExtensions::set_OtherCount(int32_t Value)
{
	SBCheckError(TElCustomSSLExtensions_set_OtherCount(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSION
TElCustomSSLExtension* TElCustomSSLExtensions::get_OtherExtensions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_OtherExtensions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherExtensions)
		this->_Inst_OtherExtensions = new TElCustomSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_OtherExtensions->updateHandle(hOutResult);
	return this->_Inst_OtherExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSERVERNAMESSLEXTENSION
TElServerNameSSLExtension* TElCustomSSLExtensions::get_ServerName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_ServerName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerName)
		this->_Inst_ServerName = new TElServerNameSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_ServerName->updateHandle(hOutResult);
	return this->_Inst_ServerName;
}
#endif /* SB_USE_CLASS_TELSERVERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION
TElTruncatedHMACSSLExtension* TElCustomSSLExtensions::get_TruncatedHMAC()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_TruncatedHMAC(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TruncatedHMAC)
		this->_Inst_TruncatedHMAC = new TElTruncatedHMACSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_TruncatedHMAC->updateHandle(hOutResult);
	return this->_Inst_TruncatedHMAC;
}
#endif /* SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION */

#ifdef SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION
TElTrustedCAsSSLExtension* TElCustomSSLExtensions::get_TrustedCAs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_TrustedCAs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedCAs)
		this->_Inst_TrustedCAs = new TElTrustedCAsSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_TrustedCAs->updateHandle(hOutResult);
	return this->_Inst_TrustedCAs;
}
#endif /* SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION */

#ifdef SB_USE_CLASS_TELUSERNAMESSLEXTENSION
TElUserNameSSLExtension* TElCustomSSLExtensions::get_UserName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_UserName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UserName)
		this->_Inst_UserName = new TElUserNameSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_UserName->updateHandle(hOutResult);
	return this->_Inst_UserName;
}
#endif /* SB_USE_CLASS_TELUSERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECCURVESSLEXTENSION
TElECCurveSSLExtension* TElCustomSSLExtensions::get_ECCurves()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_ECCurves(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ECCurves)
		this->_Inst_ECCurves = new TElECCurveSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_ECCurves->updateHandle(hOutResult);
	return this->_Inst_ECCurves;
}
#endif /* SB_USE_CLASS_TELECCURVESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECPOINTSSLEXTENSION
TElECPointSSLExtension* TElCustomSSLExtensions::get_ECPoints()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_ECPoints(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ECPoints)
		this->_Inst_ECPoints = new TElECPointSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_ECPoints->updateHandle(hOutResult);
	return this->_Inst_ECPoints;
}
#endif /* SB_USE_CLASS_TELECPOINTSSLEXTENSION */

bool TElCustomSSLExtensions::get_StatelessTLS()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSSLExtensions_get_StatelessTLS(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSSLExtensions::set_StatelessTLS(bool Value)
{
	SBCheckError(TElCustomSSLExtensions_set_StatelessTLS(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION
TElCertHashTypesSSLExtension* TElCustomSSLExtensions::get_CertHashTypes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_CertHashTypes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertHashTypes)
		this->_Inst_CertHashTypes = new TElCertHashTypesSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_CertHashTypes->updateHandle(hOutResult);
	return this->_Inst_CertHashTypes;
}
#endif /* SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION */

#ifdef SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION
TElRenegotiationInfoSSLExtension* TElCustomSSLExtensions::get_RenegotiationInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_RenegotiationInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RenegotiationInfo)
		this->_Inst_RenegotiationInfo = new TElRenegotiationInfoSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_RenegotiationInfo->updateHandle(hOutResult);
	return this->_Inst_RenegotiationInfo;
}

SB_INLINE void TElCustomSSLExtensions::set_RenegotiationInfo(TElRenegotiationInfoSSLExtension &Value)
{
	SBCheckError(TElCustomSSLExtensions_set_RenegotiationInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomSSLExtensions::set_RenegotiationInfo(TElRenegotiationInfoSSLExtension *Value)
{
	SBCheckError(TElCustomSSLExtensions_set_RenegotiationInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION
TElHeartbeatHelloSSLExtension* TElCustomSSLExtensions::get_Heartbeat()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_Heartbeat(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Heartbeat)
		this->_Inst_Heartbeat = new TElHeartbeatHelloSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_Heartbeat->updateHandle(hOutResult);
	return this->_Inst_Heartbeat;
}
#endif /* SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION
TElSignatureAlgorithmsSSLExtension* TElCustomSSLExtensions::get_SignatureAlgorithms()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_SignatureAlgorithms(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureAlgorithms)
		this->_Inst_SignatureAlgorithms = new TElSignatureAlgorithmsSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_SignatureAlgorithms->updateHandle(hOutResult);
	return this->_Inst_SignatureAlgorithms;
}
#endif /* SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSRPSSLEXTENSION
TElSRPSSLExtension* TElCustomSSLExtensions::get_SRP()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_SRP(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SRP)
		this->_Inst_SRP = new TElSRPSSLExtension(hOutResult, ohFalse);
	else
		this->_Inst_SRP->updateHandle(hOutResult);
	return this->_Inst_SRP;
}
#endif /* SB_USE_CLASS_TELSRPSSLEXTENSION */

#ifdef SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION
TElExtendedMasterSecretExtension* TElCustomSSLExtensions::get_ExtendedMasterSecret()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSLExtensions_get_ExtendedMasterSecret(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtendedMasterSecret)
		this->_Inst_ExtendedMasterSecret = new TElExtendedMasterSecretExtension(hOutResult, ohFalse);
	else
		this->_Inst_ExtendedMasterSecret->updateHandle(hOutResult);
	return this->_Inst_ExtendedMasterSecret;
}
#endif /* SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION */

void TElCustomSSLExtensions::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION
	this->_Inst_CertificateStatus = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION
	this->_Inst_ClientCertURLs = NULL;
#endif /* SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION
	this->_Inst_MaxFragmentLength = NULL;
#endif /* SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSION
	this->_Inst_OtherExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSERVERNAMESSLEXTENSION
	this->_Inst_ServerName = NULL;
#endif /* SB_USE_CLASS_TELSERVERNAMESSLEXTENSION */
#ifdef SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION
	this->_Inst_TruncatedHMAC = NULL;
#endif /* SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION */
#ifdef SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION
	this->_Inst_TrustedCAs = NULL;
#endif /* SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION */
#ifdef SB_USE_CLASS_TELUSERNAMESSLEXTENSION
	this->_Inst_UserName = NULL;
#endif /* SB_USE_CLASS_TELUSERNAMESSLEXTENSION */
#ifdef SB_USE_CLASS_TELECCURVESSLEXTENSION
	this->_Inst_ECCurves = NULL;
#endif /* SB_USE_CLASS_TELECCURVESSLEXTENSION */
#ifdef SB_USE_CLASS_TELECPOINTSSLEXTENSION
	this->_Inst_ECPoints = NULL;
#endif /* SB_USE_CLASS_TELECPOINTSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION
	this->_Inst_CertHashTypes = NULL;
#endif /* SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION */
#ifdef SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION
	this->_Inst_RenegotiationInfo = NULL;
#endif /* SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION */
#ifdef SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION
	this->_Inst_Heartbeat = NULL;
#endif /* SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION
	this->_Inst_SignatureAlgorithms = NULL;
#endif /* SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSRPSSLEXTENSION
	this->_Inst_SRP = NULL;
#endif /* SB_USE_CLASS_TELSRPSSLEXTENSION */
#ifdef SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION
	this->_Inst_ExtendedMasterSecret = NULL;
#endif /* SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION */
}

TElCustomSSLExtensions::TElCustomSSLExtensions(TElCustomSSLExtensionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCustomSSLExtensions::TElCustomSSLExtensions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomSSLExtensions_Create(&_Handle));
}

TElCustomSSLExtensions::~TElCustomSSLExtensions()
{
#ifdef SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION
	delete this->_Inst_CertificateStatus;
	this->_Inst_CertificateStatus = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION
	delete this->_Inst_ClientCertURLs;
	this->_Inst_ClientCertURLs = NULL;
#endif /* SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION
	delete this->_Inst_MaxFragmentLength;
	this->_Inst_MaxFragmentLength = NULL;
#endif /* SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSION
	delete this->_Inst_OtherExtensions;
	this->_Inst_OtherExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSERVERNAMESSLEXTENSION
	delete this->_Inst_ServerName;
	this->_Inst_ServerName = NULL;
#endif /* SB_USE_CLASS_TELSERVERNAMESSLEXTENSION */
#ifdef SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION
	delete this->_Inst_TruncatedHMAC;
	this->_Inst_TruncatedHMAC = NULL;
#endif /* SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION */
#ifdef SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION
	delete this->_Inst_TrustedCAs;
	this->_Inst_TrustedCAs = NULL;
#endif /* SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION */
#ifdef SB_USE_CLASS_TELUSERNAMESSLEXTENSION
	delete this->_Inst_UserName;
	this->_Inst_UserName = NULL;
#endif /* SB_USE_CLASS_TELUSERNAMESSLEXTENSION */
#ifdef SB_USE_CLASS_TELECCURVESSLEXTENSION
	delete this->_Inst_ECCurves;
	this->_Inst_ECCurves = NULL;
#endif /* SB_USE_CLASS_TELECCURVESSLEXTENSION */
#ifdef SB_USE_CLASS_TELECPOINTSSLEXTENSION
	delete this->_Inst_ECPoints;
	this->_Inst_ECPoints = NULL;
#endif /* SB_USE_CLASS_TELECPOINTSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION
	delete this->_Inst_CertHashTypes;
	this->_Inst_CertHashTypes = NULL;
#endif /* SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION */
#ifdef SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION
	delete this->_Inst_RenegotiationInfo;
	this->_Inst_RenegotiationInfo = NULL;
#endif /* SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION */
#ifdef SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION
	delete this->_Inst_Heartbeat;
	this->_Inst_Heartbeat = NULL;
#endif /* SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION
	delete this->_Inst_SignatureAlgorithms;
	this->_Inst_SignatureAlgorithms = NULL;
#endif /* SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSRPSSLEXTENSION
	delete this->_Inst_SRP;
	this->_Inst_SRP = NULL;
#endif /* SB_USE_CLASS_TELSRPSSLEXTENSION */
#ifdef SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION
	delete this->_Inst_ExtendedMasterSecret;
	this->_Inst_ExtendedMasterSecret = NULL;
#endif /* SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION */
}
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS

SB_INLINE void TElClientSSLExtensions::Assign(TElCustomSSLExtensions &Source)
{
	SBCheckError(TElClientSSLExtensions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElClientSSLExtensions::Assign(TElCustomSSLExtensions *Source)
{
	SBCheckError(TElClientSSLExtensions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElClientSSLExtensions::Clear()
{
	SBCheckError(TElClientSSLExtensions_Clear(_Handle));
}

SB_INLINE void TElClientSSLExtensions::DisableAll()
{
	SBCheckError(TElClientSSLExtensions_DisableAll(_Handle));
}

SB_INLINE void TElClientSSLExtensions::ClearAcceptableCAs()
{
	SBCheckError(TElClientSSLExtensions_ClearAcceptableCAs(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElClientSSLExtensions::AddAcceptableCAs(TElRelativeDistinguishedName &Value)
{
	SBCheckError(TElClientSSLExtensions_AddAcceptableCAs(_Handle, Value.getHandle()));
}

SB_INLINE void TElClientSSLExtensions::AddAcceptableCAs(TElRelativeDistinguishedName *Value)
{
	SBCheckError(TElClientSSLExtensions_AddAcceptableCAs(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElClientSSLExtensions::get_AcceptableCAs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElClientSSLExtensions_get_AcceptableCAs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AcceptableCAs)
		this->_Inst_AcceptableCAs = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_AcceptableCAs->updateHandle(hOutResult);
	return this->_Inst_AcceptableCAs;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE int32_t TElClientSSLExtensions::get_AcceptableCACount()
{
	int32_t OutResult;
	SBCheckError(TElClientSSLExtensions_get_AcceptableCACount(_Handle, &OutResult));
	return OutResult;
}

bool TElClientSSLExtensions::get_FallbackConnection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElClientSSLExtensions_get_FallbackConnection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElClientSSLExtensions::set_FallbackConnection(bool Value)
{
	SBCheckError(TElClientSSLExtensions_set_FallbackConnection(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
TElCertificateTypeRequest* TElClientSSLExtensions::get_ServerCertificateType()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElClientSSLExtensions_get_ServerCertificateType(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerCertificateType)
		this->_Inst_ServerCertificateType = new TElCertificateTypeRequest(hOutResult, ohFalse);
	else
		this->_Inst_ServerCertificateType->updateHandle(hOutResult);
	return this->_Inst_ServerCertificateType;
}
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
TElCertificateTypeRequest* TElClientSSLExtensions::get_ClientCertificateType()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElClientSSLExtensions_get_ClientCertificateType(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertificateType)
		this->_Inst_ClientCertificateType = new TElCertificateTypeRequest(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertificateType->updateHandle(hOutResult);
	return this->_Inst_ClientCertificateType;
}
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */

void TElClientSSLExtensions::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_AcceptableCAs = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
	this->_Inst_ServerCertificateType = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
	this->_Inst_ClientCertificateType = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */
}

TElClientSSLExtensions::TElClientSSLExtensions(TElClientSSLExtensionsHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtensions(handle, ownHandle)
{
	initInstances();
}

TElClientSSLExtensions::TElClientSSLExtensions() : TElCustomSSLExtensions(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElClientSSLExtensions_Create(&_Handle));
}

TElClientSSLExtensions::~TElClientSSLExtensions()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_AcceptableCAs;
	this->_Inst_AcceptableCAs = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
	delete this->_Inst_ServerCertificateType;
	this->_Inst_ServerCertificateType = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
	delete this->_Inst_ClientCertificateType;
	this->_Inst_ClientCertificateType = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */
}
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS

SB_INLINE void TElServerSSLExtensions::Assign(TElCustomSSLExtensions &Source)
{
	SBCheckError(TElServerSSLExtensions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElServerSSLExtensions::Assign(TElCustomSSLExtensions *Source)
{
	SBCheckError(TElServerSSLExtensions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElServerSSLExtensions::Clear()
{
	SBCheckError(TElServerSSLExtensions_Clear(_Handle));
}

SB_INLINE void TElServerSSLExtensions::DisableAll()
{
	SBCheckError(TElServerSSLExtensions_DisableAll(_Handle));
}

bool TElServerSSLExtensions::get_StrictCertRequest()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElServerSSLExtensions_get_StrictCertRequest(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElServerSSLExtensions::set_StrictCertRequest(bool Value)
{
	SBCheckError(TElServerSSLExtensions_set_StrictCertRequest(_Handle, (int8_t)Value));
}

void TElServerSSLExtensions::get_PSKIdentityHint(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElServerSSLExtensions_get_PSKIdentityHint(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1183442600, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElServerSSLExtensions::set_PSKIdentityHint(const std::string &Value)
{
	SBCheckError(TElServerSSLExtensions_set_PSKIdentityHint(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
TElCertificateTypeResponse* TElServerSSLExtensions::get_ServerCertificateType()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElServerSSLExtensions_get_ServerCertificateType(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerCertificateType)
		this->_Inst_ServerCertificateType = new TElCertificateTypeResponse(hOutResult, ohFalse);
	else
		this->_Inst_ServerCertificateType->updateHandle(hOutResult);
	return this->_Inst_ServerCertificateType;
}
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
TElCertificateTypeResponse* TElServerSSLExtensions::get_ClientCertificateType()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElServerSSLExtensions_get_ClientCertificateType(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertificateType)
		this->_Inst_ClientCertificateType = new TElCertificateTypeResponse(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertificateType->updateHandle(hOutResult);
	return this->_Inst_ClientCertificateType;
}
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */

void TElServerSSLExtensions::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
	this->_Inst_ServerCertificateType = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
	this->_Inst_ClientCertificateType = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */
}

TElServerSSLExtensions::TElServerSSLExtensions(TElServerSSLExtensionsHandle handle, TElOwnHandle ownHandle) : TElCustomSSLExtensions(handle, ownHandle)
{
	initInstances();
}

TElServerSSLExtensions::TElServerSSLExtensions() : TElCustomSSLExtensions(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElServerSSLExtensions_Create(&_Handle));
}

TElServerSSLExtensions::~TElServerSSLExtensions()
{
#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
	delete this->_Inst_ServerCertificateType;
	this->_Inst_ServerCertificateType = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
	delete this->_Inst_ClientCertificateType;
	this->_Inst_ClientCertificateType = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */
}
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSSLRETRANSMISSIONTIMER

SB_INLINE void TElSSLRetransmissionTimer::Start()
{
	SBCheckError(TElSSLRetransmissionTimer_Start(_Handle));
}

SB_INLINE void TElSSLRetransmissionTimer::Stop()
{
	SBCheckError(TElSSLRetransmissionTimer_Stop(_Handle));
}

SB_INLINE int32_t TElSSLRetransmissionTimer::get_Interval()
{
	int32_t OutResult;
	SBCheckError(TElSSLRetransmissionTimer_get_Interval(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLRetransmissionTimer::set_Interval(int32_t Value)
{
	SBCheckError(TElSSLRetransmissionTimer_set_Interval(_Handle, Value));
}

bool TElSSLRetransmissionTimer::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLRetransmissionTimer_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLRetransmissionTimer::get_OnTimer(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLRetransmissionTimer_get_OnTimer(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLRetransmissionTimer::set_OnTimer(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLRetransmissionTimer_set_OnTimer(_Handle, pMethodValue, pDataValue));
}

TElSSLRetransmissionTimer::TElSSLRetransmissionTimer(TElSSLRetransmissionTimerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSLRetransmissionTimer::TElSSLRetransmissionTimer() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLRetransmissionTimer_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSLRETRANSMISSIONTIMER */

#ifdef SB_USE_CLASS_TELSSLMEMORYMANAGER

void TElSSLMemoryManager::GetArray(int32_t Len, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSLMemoryManager_GetArray(_Handle, Len, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1115297704, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSSLMemoryManager::ReleaseArray(std::vector<uint8_t> &Arr)
{
	int32_t szArr = (int32_t)Arr.size();
	uint32_t _err = TElSSLMemoryManager_ReleaseArray(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Arr), &szArr);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Arr.resize(szArr);
		SBCheckError(SBGetLastReturnBuffer(1783755229, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Arr), &szArr));
	}
	else
		SBCheckError(_err);

	Arr.resize(szArr);
}

void TElSSLMemoryManager::ResizeArray(std::vector<uint8_t> &Arr, int32_t NewSize)
{
	int32_t szArr = (int32_t)Arr.size();
	uint32_t _err = TElSSLMemoryManager_ResizeArray(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Arr), &szArr, NewSize);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Arr.resize(szArr);
		SBCheckError(SBGetLastReturnBuffer(-1691190772, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Arr), &szArr));
	}
	else
		SBCheckError(_err);

	Arr.resize(szArr);
}

SB_INLINE void TElSSLMemoryManager::ReleaseAll()
{
	SBCheckError(TElSSLMemoryManager_ReleaseAll(_Handle));
}

bool TElSSLMemoryManager::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLMemoryManager_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSLMemoryManager::set_Enabled(bool Value)
{
	SBCheckError(TElSSLMemoryManager_set_Enabled(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSSLMemoryManager::get_MaxCount()
{
	int32_t OutResult;
	SBCheckError(TElSSLMemoryManager_get_MaxCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSLMemoryManager::set_MaxCount(int32_t Value)
{
	SBCheckError(TElSSLMemoryManager_set_MaxCount(_Handle, Value));
}

TElSSLMemoryManager::TElSSLMemoryManager(TElSSLMemoryManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSLMemoryManager::TElSSLMemoryManager() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLMemoryManager_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSLMEMORYMANAGER */

#ifdef SB_USE_CLASS_TELSSLX509CERTIFICATETYPEHANDLER

TElSSLCertificateType TElSSLX509CertificateTypeHandler::GetCertificateType()
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLX509CertificateTypeHandler_GetCertificateType(_Handle, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

int32_t TElSSLX509CertificateTypeHandler::GetDataForRemote(int32_t CipherSuite, TSBKeyExchangeAlgorithm KeyExchange, std::vector<uint8_t> &Data, int32_t Optional)
{
	int32_t OutResult;
	int32_t szData = (int32_t)Data.size();
	uint32_t _err = TElSSLX509CertificateTypeHandler_GetDataForRemote(_Handle, CipherSuite, (TSBKeyExchangeAlgorithmRaw)KeyExchange, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Data), &szData, Optional, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Data.resize(szData);
		SBCheckError(SBGetLastReturnBuffer(-2099965513, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Data), &szData));
	}
	else
		SBCheckError(_err);

	Data.resize(szData);
	return OutResult;
}

bool TElSSLX509CertificateTypeHandler::ValidateRemoteCert(const std::vector<uint8_t> &Data, int32_t Optional)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLX509CertificateTypeHandler_ValidateRemoteCert(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), Optional, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELKEYMATERIAL
void TElSSLX509CertificateTypeHandler::GetRemoteKeyMaterial(const std::vector<uint8_t> &Data, int32_t KeyType, int32_t &PKType, int32_t &KeyAlgorithm, TElKeyMaterial &KeyMaterial)
{
	TElClassHandle hKeyMaterial = KeyMaterial.getHandle();
	SBCheckError(TElSSLX509CertificateTypeHandler_GetRemoteKeyMaterial(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), KeyType, &PKType, &KeyAlgorithm, &hKeyMaterial));
	KeyMaterial.updateHandle(hKeyMaterial);
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE TElKeyMaterialHandle TElSSLX509CertificateTypeHandler::GetKeyMaterial()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElSSLX509CertificateTypeHandler_GetKeyMaterial(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

SB_INLINE int32_t TElSSLX509CertificateTypeHandler::GetPublicKeySize()
{
	int32_t OutResult;
	SBCheckError(TElSSLX509CertificateTypeHandler_GetPublicKeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSLX509CertificateTypeHandler::GetPublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSSLX509CertificateTypeHandler_GetPublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

TElSSLX509CertificateTypeHandler::TElSSLX509CertificateTypeHandler(TElSSLX509CertificateTypeHandlerHandle handle, TElOwnHandle ownHandle) : TElSSLCertificateTypeHandler(handle, ownHandle)
{
}

TElSSLX509CertificateTypeHandler::TElSSLX509CertificateTypeHandler(TComponent &AOwner) : TElSSLCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLX509CertificateTypeHandler_Create(AOwner.getHandle(), &_Handle));
}

TElSSLX509CertificateTypeHandler::TElSSLX509CertificateTypeHandler(TComponent *AOwner) : TElSSLCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLX509CertificateTypeHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSLX509CERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLRAWKEYCERTIFICATETYPEHANDLER

TElSSLCertificateType TElSSLRawKeyCertificateTypeHandler::GetCertificateType()
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLRawKeyCertificateTypeHandler_GetCertificateType(_Handle, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

int32_t TElSSLRawKeyCertificateTypeHandler::GetDataForRemote(int32_t CipherSuite, TSBKeyExchangeAlgorithm KeyExchange, std::vector<uint8_t> &Data, int32_t Optional)
{
	int32_t OutResult;
	int32_t szData = (int32_t)Data.size();
	uint32_t _err = TElSSLRawKeyCertificateTypeHandler_GetDataForRemote(_Handle, CipherSuite, (TSBKeyExchangeAlgorithmRaw)KeyExchange, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Data), &szData, Optional, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Data.resize(szData);
		SBCheckError(SBGetLastReturnBuffer(1903518791, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Data), &szData));
	}
	else
		SBCheckError(_err);

	Data.resize(szData);
	return OutResult;
}

bool TElSSLRawKeyCertificateTypeHandler::ValidateRemoteCert(const std::vector<uint8_t> &Data, int32_t Optional)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLRawKeyCertificateTypeHandler_ValidateRemoteCert(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), Optional, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELKEYMATERIAL
void TElSSLRawKeyCertificateTypeHandler::GetRemoteKeyMaterial(const std::vector<uint8_t> &Data, int32_t KeyType, int32_t &PKType, int32_t &KeyAlgorithm, TElKeyMaterial &KeyMaterial)
{
	TElClassHandle hKeyMaterial = KeyMaterial.getHandle();
	SBCheckError(TElSSLRawKeyCertificateTypeHandler_GetRemoteKeyMaterial(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), KeyType, &PKType, &KeyAlgorithm, &hKeyMaterial));
	KeyMaterial.updateHandle(hKeyMaterial);
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE TElKeyMaterialHandle TElSSLRawKeyCertificateTypeHandler::GetKeyMaterial()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElSSLRawKeyCertificateTypeHandler_GetKeyMaterial(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

SB_INLINE int32_t TElSSLRawKeyCertificateTypeHandler::GetPublicKeySize()
{
	int32_t OutResult;
	SBCheckError(TElSSLRawKeyCertificateTypeHandler_GetPublicKeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSLRawKeyCertificateTypeHandler::GetPublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSSLRawKeyCertificateTypeHandler_GetPublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

TElSSLRawKeyCertificateTypeHandler::TElSSLRawKeyCertificateTypeHandler(TElSSLRawKeyCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle) : TElSSLCertificateTypeHandler(handle, ownHandle)
{
}

TElSSLRawKeyCertificateTypeHandler::TElSSLRawKeyCertificateTypeHandler(TComponent &AOwner) : TElSSLCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLRawKeyCertificateTypeHandler_Create(AOwner.getHandle(), &_Handle));
}

TElSSLRawKeyCertificateTypeHandler::TElSSLRawKeyCertificateTypeHandler(TComponent *AOwner) : TElSSLCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLRawKeyCertificateTypeHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSLRAWKEYCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELDTLSFLIGHTITEM

SB_INLINE int32_t TElDTLSFlightItem::get_Epoch()
{
	int32_t OutResult;
	SBCheckError(TElDTLSFlightItem_get_Epoch(_Handle, &OutResult));
	return OutResult;
}

TSSL3ContentType TElDTLSFlightItem::get_ContentType()
{
	TSSL3ContentTypeRaw OutResultRaw = 0;
	SBCheckError(TElDTLSFlightItem_get_ContentType(_Handle, &OutResultRaw));
	return (TSSL3ContentType)OutResultRaw;
}

void TElDTLSFlightItem::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDTLSFlightItem_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2027356289, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElDTLSFlightItem::get_Length()
{
	int32_t OutResult;
	SBCheckError(TElDTLSFlightItem_get_Length(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDTLSFlightItem::get_MessageSeq()
{
	int32_t OutResult;
	SBCheckError(TElDTLSFlightItem_get_MessageSeq(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDTLSFlightItem::get_FragmentOffset()
{
	int32_t OutResult;
	SBCheckError(TElDTLSFlightItem_get_FragmentOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDTLSFlightItem::get_FragmentLength()
{
	int32_t OutResult;
	SBCheckError(TElDTLSFlightItem_get_FragmentLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDTLSFlightItem::get_HandshakeType()
{
	int32_t OutResult;
	SBCheckError(TElDTLSFlightItem_get_HandshakeType(_Handle, &OutResult));
	return OutResult;
}

TElDTLSFlightItem::TElDTLSFlightItem(TElDTLSFlightItemHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDTLSFlightItem::TElDTLSFlightItem(TSSL3ContentType ContentType, void * Header, int32_t HeaderLen, void * Data, int32_t DataLen, int32_t Epoch) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDTLSFlightItem_Create((TSSL3ContentTypeRaw)ContentType, Header, HeaderLen, Data, DataLen, Epoch, &_Handle));
}

TElDTLSFlightItem::TElDTLSFlightItem(int32_t HandshakeType, int32_t Len, int32_t MessageSeq, int32_t FragmentOffset, int32_t FragmentLength, void * Fragment) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDTLSFlightItem_Create_1(HandshakeType, Len, MessageSeq, FragmentOffset, FragmentLength, Fragment, &_Handle));
}

TElDTLSFlightItem TElDTLSFlightItem::CreateChangeCipherSpec()
{
	TElDTLSFlightItemHandle _Handle;
	SBCheckError(TElDTLSFlightItem_CreateChangeCipherSpec(&_Handle));
	return TElDTLSFlightItem(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TELDTLSFLIGHTITEM */

#ifdef SB_USE_GLOBAL_PROCS_SSLCOMMON

SB_INLINE int32_t ConvertToErrorCode(TSBAlertDescription Desc)
{
	int32_t OutResult;
	SBCheckError(SBSSLCommon_ConvertToErrorCode((TSBAlertDescriptionRaw)Desc, &OutResult));
	return OutResult;
}

TSBAlertDescription ConvertSSLError(uint8_t AD)
{
	TSBAlertDescriptionRaw OutResultRaw = 0;
	SBCheckError(SBSSLCommon_ConvertSSLError(AD, &OutResultRaw));
	return (TSBAlertDescription)OutResultRaw;
}

SB_INLINE uint32_t GetSecondsCount()
{
	uint32_t OutResult;
	SBCheckError(SBSSLCommon_GetSecondsCount(&OutResult));
	return OutResult;
}

SB_INLINE int32_t GetCurveByTlsCurve(int32_t Curve)
{
	int32_t OutResult;
	SBCheckError(SBSSLCommon_GetCurveByTlsCurve(Curve, &OutResult));
	return OutResult;
}

SB_INLINE int32_t GetTlsCurveByCurve(int32_t Curve)
{
	int32_t OutResult;
	SBCheckError(SBSSLCommon_GetTlsCurveByCurve(Curve, &OutResult));
	return OutResult;
}

void ReadLengthPrefixedArray(void * ABuffer, int32_t ASize, int32_t ALenBytes, int32_t &BytesRead, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSLCommon_ReadLengthPrefixedArray(ABuffer, ASize, ALenBytes, &BytesRead, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1475631838, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELSSLMEMORYMANAGER
SB_INLINE TElSSLMemoryManagerHandle SSLMemoryManager()
{
	TElSSLMemoryManagerHandle OutResult;
	SBCheckError(SBSSLCommon_SSLMemoryManager(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSLMEMORYMANAGER */

#endif /* SB_USE_GLOBAL_PROCS_SSLCOMMON */

};	/* namespace SecureBlackbox */

