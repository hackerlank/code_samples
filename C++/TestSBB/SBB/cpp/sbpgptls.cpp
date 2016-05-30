#include "sbpgptls.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSLPGPCERTIFICATETYPEHANDLER

TElSSLCertificateType TElSSLPGPCertificateTypeHandler::GetCertificateType()
{
	TElSSLCertificateTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLPGPCertificateTypeHandler_GetCertificateType(_Handle, &OutResultRaw));
	return (TElSSLCertificateType)OutResultRaw;
}

bool TElSSLPGPCertificateTypeHandler::ValidateRemoteCert(const std::vector<uint8_t> &Data, int32_t Optional)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSLPGPCertificateTypeHandler_ValidateRemoteCert(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), Optional, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELKEYMATERIAL
void TElSSLPGPCertificateTypeHandler::GetRemoteKeyMaterial(const std::vector<uint8_t> &Data, int32_t KeyType, int32_t &PKType, int32_t &KeyAlgorithm, TElKeyMaterial &KeyMaterial)
{
	TElClassHandle hKeyMaterial = KeyMaterial.getHandle();
	SBCheckError(TElSSLPGPCertificateTypeHandler_GetRemoteKeyMaterial(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), KeyType, &PKType, &KeyAlgorithm, &hKeyMaterial));
	KeyMaterial.updateHandle(hKeyMaterial);
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE TElKeyMaterialHandle TElSSLPGPCertificateTypeHandler::GetKeyMaterial()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElSSLPGPCertificateTypeHandler_GetKeyMaterial(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

SB_INLINE int32_t TElSSLPGPCertificateTypeHandler::GetPublicKeySize()
{
	int32_t OutResult;
	SBCheckError(TElSSLPGPCertificateTypeHandler_GetPublicKeySize(_Handle, &OutResult));
	return OutResult;
}

int32_t TElSSLPGPCertificateTypeHandler::GetDataForRemote(int32_t CipherSuite, TSBKeyExchangeAlgorithm KeyExchange, std::vector<uint8_t> &Data, int32_t Optional)
{
	int32_t OutResult;
	int32_t szData = (int32_t)Data.size();
	uint32_t _err = TElSSLPGPCertificateTypeHandler_GetDataForRemote(_Handle, CipherSuite, (TSBKeyExchangeAlgorithmRaw)KeyExchange, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Data), &szData, Optional, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Data.resize(szData);
		SBCheckError(SBGetLastReturnBuffer(2083141646, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Data), &szData));
	}
	else
		SBCheckError(_err);

	Data.resize(szData);
	return OutResult;
}

SB_INLINE int32_t TElSSLPGPCertificateTypeHandler::GetPublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSSLPGPCertificateTypeHandler_GetPublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElSSLPGPCertificateTypeHandler::get_Keyring()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSLPGPCertificateTypeHandler_get_Keyring(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keyring)
		this->_Inst_Keyring = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_Keyring->updateHandle(hOutResult);
	return this->_Inst_Keyring;
}

SB_INLINE void TElSSLPGPCertificateTypeHandler::set_Keyring(TElPGPKeyring &Value)
{
	SBCheckError(TElSSLPGPCertificateTypeHandler_set_Keyring(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSLPGPCertificateTypeHandler::set_Keyring(TElPGPKeyring *Value)
{
	SBCheckError(TElSSLPGPCertificateTypeHandler_set_Keyring(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

SB_INLINE void TElSSLPGPCertificateTypeHandler::get_OnKeyFind(TElPGPSSLKeyFindEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLPGPCertificateTypeHandler_get_OnKeyFind(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLPGPCertificateTypeHandler::set_OnKeyFind(TElPGPSSLKeyFindEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLPGPCertificateTypeHandler_set_OnKeyFind(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSLPGPCertificateTypeHandler::get_OnKeyValidate(TElPGPSSLKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSLPGPCertificateTypeHandler_get_OnKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSLPGPCertificateTypeHandler::set_OnKeyValidate(TElPGPSSLKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSLPGPCertificateTypeHandler_set_OnKeyValidate(_Handle, pMethodValue, pDataValue));
}

void TElSSLPGPCertificateTypeHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}

TElSSLPGPCertificateTypeHandler::TElSSLPGPCertificateTypeHandler(TElSSLPGPCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle) : TElSSLCertificateTypeHandler(handle, ownHandle)
{
	initInstances();
}

TElSSLPGPCertificateTypeHandler::TElSSLPGPCertificateTypeHandler(TComponent &AOwner) : TElSSLCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLPGPCertificateTypeHandler_Create(AOwner.getHandle(), &_Handle));
}

TElSSLPGPCertificateTypeHandler::TElSSLPGPCertificateTypeHandler(TComponent *AOwner) : TElSSLCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSLPGPCertificateTypeHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSLPGPCertificateTypeHandler::~TElSSLPGPCertificateTypeHandler()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_Keyring;
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}
#endif /* SB_USE_CLASS_TELSSLPGPCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCLIENTPGPCERTIFICATETYPEHANDLER

TElSSLClientPGPCertificateTypeHandler::TElSSLClientPGPCertificateTypeHandler(TElSSLClientPGPCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle) : TElSSLPGPCertificateTypeHandler(handle, ownHandle)
{
}

TElSSLClientPGPCertificateTypeHandler::TElSSLClientPGPCertificateTypeHandler(TComponent &AOwner) : TElSSLPGPCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLClientPGPCertificateTypeHandler_Create(AOwner.getHandle(), &_Handle));
}

TElSSLClientPGPCertificateTypeHandler::TElSSLClientPGPCertificateTypeHandler(TComponent *AOwner) : TElSSLPGPCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLClientPGPCertificateTypeHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSLCLIENTPGPCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLSERVERPGPCERTIFICATETYPEHANDLER

TSBPGPKeyDescriptorType TElSSLServerPGPCertificateTypeHandler::get_KeyDescriptorType()
{
	TSBPGPKeyDescriptorTypeRaw OutResultRaw = 0;
	SBCheckError(TElSSLServerPGPCertificateTypeHandler_get_KeyDescriptorType(_Handle, &OutResultRaw));
	return (TSBPGPKeyDescriptorType)OutResultRaw;
}

SB_INLINE void TElSSLServerPGPCertificateTypeHandler::set_KeyDescriptorType(TSBPGPKeyDescriptorType Value)
{
	SBCheckError(TElSSLServerPGPCertificateTypeHandler_set_KeyDescriptorType(_Handle, (TSBPGPKeyDescriptorTypeRaw)Value));
}

TElSSLServerPGPCertificateTypeHandler::TElSSLServerPGPCertificateTypeHandler(TElSSLServerPGPCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle) : TElSSLPGPCertificateTypeHandler(handle, ownHandle)
{
}

TElSSLServerPGPCertificateTypeHandler::TElSSLServerPGPCertificateTypeHandler(TComponent &AOwner) : TElSSLPGPCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLServerPGPCertificateTypeHandler_Create(AOwner.getHandle(), &_Handle));
}

TElSSLServerPGPCertificateTypeHandler::TElSSLServerPGPCertificateTypeHandler(TComponent *AOwner) : TElSSLPGPCertificateTypeHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSLServerPGPCertificateTypeHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSLSERVERPGPCERTIFICATETYPEHANDLER */

};	/* namespace SecureBlackbox */

