#include "sbsshpubkeyserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYSERVER

SB_INLINE void TElSSHPublicKeyServer::Close()
{
	SBCheckError(TElSSHPublicKeyServer_Close(_Handle));
}

SB_INLINE void TElSSHPublicKeyServer::DataAvailable()
{
	SBCheckError(TElSSHPublicKeyServer_DataAvailable(_Handle));
}

SB_INLINE void TElSSHPublicKeyServer::Open()
{
	SBCheckError(TElSSHPublicKeyServer_Open(_Handle));
}

bool TElSSHPublicKeyServer::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHPublicKeyServer_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSSHPublicKeyServer::get_RemoteVersion()
{
	int32_t OutResult;
	SBCheckError(TElSSHPublicKeyServer_get_RemoteVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHPublicKeyServer::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElSSHPublicKeyServer_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHPublicKeyServer::get_OnReceive(TSBSSHPublicKeyReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnReceive(TSBSSHPublicKeyReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnSend(TSBSSHPublicKeySendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnSend(TSBSSHPublicKeySendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnClose(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnError(TSBSSHPublicKeyErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnError(TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnOpen(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnStatus(TSBSSHPublicKeyStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnStatus(TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnAdd(TSBSSHPublicKeyAddEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnAdd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnAdd(TSBSSHPublicKeyAddEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnAdd(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnRemove(TSBSSHPublicKeyRemoveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnRemove(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnRemove(TSBSSHPublicKeyRemoveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnRemove(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnList(TSBSSHPublicKeyListEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnList(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnList(TSBSSHPublicKeyListEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnList(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnListAttributes(TSBSSHPublicKeyListAttributesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnListAttributes(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnListAttributes(TSBSSHPublicKeyListAttributesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnListAttributes(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSSHPublicKeyServer::get_OnAttributeSupported(TSBSSHPublicKeyAttrubuteSupportedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHPublicKeyServer_get_OnAttributeSupported(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHPublicKeyServer::set_OnAttributeSupported(TSBSSHPublicKeyAttrubuteSupportedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHPublicKeyServer_set_OnAttributeSupported(_Handle, pMethodValue, pDataValue));
}

TElSSHPublicKeyServer::TElSSHPublicKeyServer(TElSSHPublicKeyServerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElSSHPublicKeyServer::TElSSHPublicKeyServer(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHPublicKeyServer_Create(AOwner.getHandle(), &_Handle));
}

TElSSHPublicKeyServer::TElSSHPublicKeyServer(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHPublicKeyServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHPUBLICKEYSERVER */

};	/* namespace SecureBlackbox */

