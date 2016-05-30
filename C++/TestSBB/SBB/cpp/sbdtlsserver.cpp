#include "sbdtlsserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDTLSSERVER

bool TElDTLSServer::get_UseClientVerification()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDTLSServer_get_UseClientVerification(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDTLSServer::set_UseClientVerification(bool Value)
{
	SBCheckError(TElDTLSServer_set_UseClientVerification(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElDTLSServer::get_DatagramSize()
{
	int32_t OutResult;
	SBCheckError(TElDTLSServer_get_DatagramSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDTLSServer::set_DatagramSize(int32_t Value)
{
	SBCheckError(TElDTLSServer_set_DatagramSize(_Handle, Value));
}

SB_INLINE int32_t TElDTLSServer::get_MaxDataSize()
{
	int32_t OutResult;
	SBCheckError(TElDTLSServer_get_MaxDataSize(_Handle, &OutResult));
	return OutResult;
}

bool TElDTLSServer::get_SplitLongData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDTLSServer_get_SplitLongData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDTLSServer::set_SplitLongData(bool Value)
{
	SBCheckError(TElDTLSServer_set_SplitLongData(_Handle, (int8_t)Value));
}

bool TElDTLSServer::get_UseRetransmissionTimer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDTLSServer_get_UseRetransmissionTimer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDTLSServer::set_UseRetransmissionTimer(bool Value)
{
	SBCheckError(TElDTLSServer_set_UseRetransmissionTimer(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElDTLSServer::get_TimerValue()
{
	int32_t OutResult;
	SBCheckError(TElDTLSServer_get_TimerValue(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDTLSServer::set_TimerValue(int32_t Value)
{
	SBCheckError(TElDTLSServer_set_TimerValue(_Handle, Value));
}

bool TElDTLSServer::get_AutoAdjustTimerValue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDTLSServer_get_AutoAdjustTimerValue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDTLSServer::set_AutoAdjustTimerValue(bool Value)
{
	SBCheckError(TElDTLSServer_set_AutoAdjustTimerValue(_Handle, (int8_t)Value));
}

TElDTLSServer::TElDTLSServer(TElDTLSServerHandle handle, TElOwnHandle ownHandle) : TElSSLServer(handle, ownHandle)
{
}

TElDTLSServer::TElDTLSServer(TComponent &Owner) : TElSSLServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDTLSServer_Create(Owner.getHandle(), &_Handle));
}

TElDTLSServer::TElDTLSServer(TComponent *Owner) : TElSSLServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDTLSServer_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELDTLSSERVER */

#ifdef SB_USE_CLASS_TELDTLSSERVERFACTORY

SB_INLINE void TElDTLSServerFactory::ProcessRequest(void * Buffer, int32_t Size, const std::vector<uint8_t> &ClientID)
{
	SBCheckError(TElDTLSServerFactory_ProcessRequest(_Handle, Buffer, Size, SB_STD_VECTOR_FRONT_ADR(ClientID), (int32_t)ClientID.size()));
}

SB_INLINE void TElDTLSServerFactory::get_OnSend(TSBDTLSSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDTLSServerFactory_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDTLSServerFactory::set_OnSend(TSBDTLSSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDTLSServerFactory_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDTLSServerFactory::get_OnServerCreated(TSBDTLSServerCreatedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDTLSServerFactory_get_OnServerCreated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDTLSServerFactory::set_OnServerCreated(TSBDTLSServerCreatedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDTLSServerFactory_set_OnServerCreated(_Handle, pMethodValue, pDataValue));
}

TElDTLSServerFactory::TElDTLSServerFactory(TElDTLSServerFactoryHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElDTLSServerFactory::TElDTLSServerFactory(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDTLSServerFactory_Create(AOwner.getHandle(), &_Handle));
}

TElDTLSServerFactory::TElDTLSServerFactory(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDTLSServerFactory_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELDTLSSERVERFACTORY */

};	/* namespace SecureBlackbox */

