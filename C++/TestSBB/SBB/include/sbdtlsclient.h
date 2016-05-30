#ifndef __INC_SBDTLSCLIENT
#define __INC_SBDTLSCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsslclient.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDTLSClientHandle;

typedef TElDTLSClientHandle ElDTLSClientHandle;

#ifdef SB_USE_CLASS_TELDTLSCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_get_DatagramSize(TElDTLSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_set_DatagramSize(TElDTLSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_get_MaxDataSize(TElDTLSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_get_SplitLongData(TElDTLSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_set_SplitLongData(TElDTLSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_get_UseRetransmissionTimer(TElDTLSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_set_UseRetransmissionTimer(TElDTLSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_get_TimerValue(TElDTLSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_set_TimerValue(TElDTLSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_get_AutoAdjustTimerValue(TElDTLSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_set_AutoAdjustTimerValue(TElDTLSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSClient_Create(TComponentHandle Owner, TElDTLSClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELDTLSCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDTLSClient;
typedef TElDTLSClient ElDTLSClient;

#ifdef SB_USE_CLASS_TELDTLSCLIENT
class TElDTLSClient: public TElSSLClient
{
	private:
		SB_DISABLE_COPY(TElDTLSClient)
	public:
		virtual int32_t get_DatagramSize();

		virtual void set_DatagramSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DatagramSize, set_DatagramSize, TElDTLSClient, DatagramSize);

		virtual int32_t get_MaxDataSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MaxDataSize, TElDTLSClient, MaxDataSize);

		virtual bool get_SplitLongData();

		virtual void set_SplitLongData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SplitLongData, set_SplitLongData, TElDTLSClient, SplitLongData);

		virtual bool get_UseRetransmissionTimer();

		virtual void set_UseRetransmissionTimer(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseRetransmissionTimer, set_UseRetransmissionTimer, TElDTLSClient, UseRetransmissionTimer);

		virtual int32_t get_TimerValue();

		virtual void set_TimerValue(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TimerValue, set_TimerValue, TElDTLSClient, TimerValue);

		virtual bool get_AutoAdjustTimerValue();

		virtual void set_AutoAdjustTimerValue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustTimerValue, set_AutoAdjustTimerValue, TElDTLSClient, AutoAdjustTimerValue);

		TElDTLSClient(TElDTLSClientHandle handle, TElOwnHandle ownHandle);

		explicit TElDTLSClient(TComponent &Owner);

		explicit TElDTLSClient(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELDTLSCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDTLSCLIENT */

