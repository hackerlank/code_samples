#include "sbdtlsclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDTLSCLIENT

SB_INLINE int32_t TElDTLSClient::get_DatagramSize()
{
	int32_t OutResult;
	SBCheckError(TElDTLSClient_get_DatagramSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDTLSClient::set_DatagramSize(int32_t Value)
{
	SBCheckError(TElDTLSClient_set_DatagramSize(_Handle, Value));
}

SB_INLINE int32_t TElDTLSClient::get_MaxDataSize()
{
	int32_t OutResult;
	SBCheckError(TElDTLSClient_get_MaxDataSize(_Handle, &OutResult));
	return OutResult;
}

bool TElDTLSClient::get_SplitLongData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDTLSClient_get_SplitLongData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDTLSClient::set_SplitLongData(bool Value)
{
	SBCheckError(TElDTLSClient_set_SplitLongData(_Handle, (int8_t)Value));
}

bool TElDTLSClient::get_UseRetransmissionTimer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDTLSClient_get_UseRetransmissionTimer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDTLSClient::set_UseRetransmissionTimer(bool Value)
{
	SBCheckError(TElDTLSClient_set_UseRetransmissionTimer(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElDTLSClient::get_TimerValue()
{
	int32_t OutResult;
	SBCheckError(TElDTLSClient_get_TimerValue(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDTLSClient::set_TimerValue(int32_t Value)
{
	SBCheckError(TElDTLSClient_set_TimerValue(_Handle, Value));
}

bool TElDTLSClient::get_AutoAdjustTimerValue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDTLSClient_get_AutoAdjustTimerValue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDTLSClient::set_AutoAdjustTimerValue(bool Value)
{
	SBCheckError(TElDTLSClient_set_AutoAdjustTimerValue(_Handle, (int8_t)Value));
}

TElDTLSClient::TElDTLSClient(TElDTLSClientHandle handle, TElOwnHandle ownHandle) : TElSSLClient(handle, ownHandle)
{
}

TElDTLSClient::TElDTLSClient(TComponent &Owner) : TElSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDTLSClient_Create(Owner.getHandle(), &_Handle));
}

TElDTLSClient::TElDTLSClient(TComponent *Owner) : TElSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDTLSClient_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELDTLSCLIENT */

};	/* namespace SecureBlackbox */

