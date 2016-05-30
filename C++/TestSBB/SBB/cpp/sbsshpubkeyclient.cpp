#include "sbsshpubkeyclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYCLIENT

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELSSHPUBLICKEYATTRIBUTES
SB_INLINE void TElSSHPublicKeyClient::Add(TElSSHKey &Key, TElSSHPublicKeyAttributes &Attributes, bool Overwrite)
{
	SBCheckError(TElSSHPublicKeyClient_Add(_Handle, Key.getHandle(), Attributes.getHandle(), (int8_t)Overwrite));
}

SB_INLINE void TElSSHPublicKeyClient::Add(TElSSHKey *Key, TElSSHPublicKeyAttributes *Attributes, bool Overwrite)
{
	SBCheckError(TElSSHPublicKeyClient_Add(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, (int8_t)Overwrite));
}
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELSSHPUBLICKEYATTRIBUTES */

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHPublicKeyClient::Remove(TElSSHKey &Key)
{
	SBCheckError(TElSSHPublicKeyClient_Remove(_Handle, Key.getHandle()));
}

SB_INLINE void TElSSHPublicKeyClient::Remove(TElSSHKey *Key)
{
	SBCheckError(TElSSHPublicKeyClient_Remove(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

SB_INLINE void TElSSHPublicKeyClient::List()
{
	SBCheckError(TElSSHPublicKeyClient_List(_Handle));
}

SB_INLINE void TElSSHPublicKeyClient::ListAttributes()
{
	SBCheckError(TElSSHPublicKeyClient_ListAttributes(_Handle));
}

bool TElSSHPublicKeyClient::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHPublicKeyClient_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSHPublicKeyClient::get_RemoteVersion()
{
	int32_t OutResult;
	SBCheckError(TElSSHPublicKeyClient_get_RemoteVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHPublicKeyClient::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElSSHPublicKeyClient_get_Version(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL
TElSubsystemSSHTunnel* TElSSHPublicKeyClient::get_Tunnel()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHPublicKeyClient_get_Tunnel(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tunnel)
		this->_Inst_Tunnel = new TElSubsystemSSHTunnel(hOutResult, ohFalse);
	else
		this->_Inst_Tunnel->updateHandle(hOutResult);
	return this->_Inst_Tunnel;
}

SB_INLINE void TElSSHPublicKeyClient::set_Tunnel(TElSubsystemSSHTunnel &Value)
{
	SBCheckError(TElSSHPublicKeyClient_set_Tunnel(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHPublicKeyClient::set_Tunnel(TElSubsystemSSHTunnel *Value)
{
	SBCheckError(TElSSHPublicKeyClient_set_Tunnel(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL */

void TElSSHPublicKeyClient::get_Subsystem(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHPublicKeyClient_get_Subsystem(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(196420681, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHPublicKeyClient::set_Subsystem(const std::string &Value)
{
	SBCheckError(TElSSHPublicKeyClient_set_Subsystem(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElSSHPublicKeyClient::get_OnOpenConnection(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyClient_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyClient::set_OnOpenConnection(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyClient_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyClient::get_OnCloseConnection(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyClient_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyClient::set_OnCloseConnection(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyClient_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyClient::get_OnError(TSBSSHPublicKeyErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyClient_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyClient::set_OnError(TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyClient_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyClient::get_OnStatus(TSBSSHPublicKeyStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyClient_get_OnStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyClient::set_OnStatus(TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyClient_set_OnStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyClient::get_OnPublicKey(TSBSSHPublicKeyPublicKeyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyClient_get_OnPublicKey(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyClient::set_OnPublicKey(TSBSSHPublicKeyPublicKeyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyClient_set_OnPublicKey(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyClient::get_OnAttribute(TSBSSHPublicKeyAttributeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyClient_get_OnAttribute(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyClient::set_OnAttribute(TSBSSHPublicKeyAttributeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyClient_set_OnAttribute(_Handle, pMethodValue, pDataValue));
}

void TElSSHPublicKeyClient::initInstances()
{
#ifdef SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL
	this->_Inst_Tunnel = NULL;
#endif /* SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL */
}

TElSSHPublicKeyClient::TElSSHPublicKeyClient(TElSSHPublicKeyClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSSHPublicKeyClient::TElSSHPublicKeyClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHPublicKeyClient_Create(AOwner.getHandle(), &_Handle));
}

TElSSHPublicKeyClient::TElSSHPublicKeyClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHPublicKeyClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSHPublicKeyClient::~TElSSHPublicKeyClient()
{
#ifdef SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL
	delete this->_Inst_Tunnel;
	this->_Inst_Tunnel = NULL;
#endif /* SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL */
}
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYCLIENT */

};	/* namespace SecureBlackbox */

