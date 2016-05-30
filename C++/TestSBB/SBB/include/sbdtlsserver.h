#ifndef __INC_SBDTLSSERVER
#define __INC_SBDTLSSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsslserver.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbhashfunction.h"
#include "sbsharedresource.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDTLSServerHandle;

typedef TElDTLSServerHandle ElDTLSServerHandle;

typedef TElClassHandle TElDTLSServerFactoryHandle;

typedef TElDTLSServerFactoryHandle ElDTLSServerFactoryHandle;

typedef void (SB_CALLBACK *TSBDTLSServerCreatedEvent)(void * _ObjectData, TObjectHandle Sender, TElDTLSServerHandle Server, const uint8_t pClientID[], int32_t szClientID);

typedef void (SB_CALLBACK *TSBDTLSSendEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size, const uint8_t pClientID[], int32_t szClientID);

#ifdef SB_USE_CLASS_TELDTLSSERVER
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_get_UseClientVerification(TElDTLSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_set_UseClientVerification(TElDTLSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_get_DatagramSize(TElDTLSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_set_DatagramSize(TElDTLSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_get_MaxDataSize(TElDTLSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_get_SplitLongData(TElDTLSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_set_SplitLongData(TElDTLSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_get_UseRetransmissionTimer(TElDTLSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_set_UseRetransmissionTimer(TElDTLSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_get_TimerValue(TElDTLSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_set_TimerValue(TElDTLSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_get_AutoAdjustTimerValue(TElDTLSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_set_AutoAdjustTimerValue(TElDTLSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServer_Create(TComponentHandle Owner, TElDTLSServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDTLSSERVER */

#ifdef SB_USE_CLASS_TELDTLSSERVERFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServerFactory_ProcessRequest(TElDTLSServerFactoryHandle _Handle, void * Buffer, int32_t Size, const uint8_t pClientID[], int32_t szClientID);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServerFactory_get_OnSend(TElDTLSServerFactoryHandle _Handle, TSBDTLSSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServerFactory_set_OnSend(TElDTLSServerFactoryHandle _Handle, TSBDTLSSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServerFactory_get_OnServerCreated(TElDTLSServerFactoryHandle _Handle, TSBDTLSServerCreatedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServerFactory_set_OnServerCreated(TElDTLSServerFactoryHandle _Handle, TSBDTLSServerCreatedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSServerFactory_Create(TComponentHandle AOwner, TElDTLSServerFactoryHandle * OutResult);
#endif /* SB_USE_CLASS_TELDTLSSERVERFACTORY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDTLSServer;
typedef TElDTLSServer ElDTLSServer;
class TElDTLSServerFactory;
typedef TElDTLSServerFactory ElDTLSServerFactory;

#ifdef SB_USE_CLASS_TELDTLSSERVER
class TElDTLSServer: public TElSSLServer
{
	private:
		SB_DISABLE_COPY(TElDTLSServer)
	public:
		virtual bool get_UseClientVerification();

		virtual void set_UseClientVerification(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseClientVerification, set_UseClientVerification, TElDTLSServer, UseClientVerification);

		virtual int32_t get_DatagramSize();

		virtual void set_DatagramSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DatagramSize, set_DatagramSize, TElDTLSServer, DatagramSize);

		virtual int32_t get_MaxDataSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MaxDataSize, TElDTLSServer, MaxDataSize);

		virtual bool get_SplitLongData();

		virtual void set_SplitLongData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SplitLongData, set_SplitLongData, TElDTLSServer, SplitLongData);

		virtual bool get_UseRetransmissionTimer();

		virtual void set_UseRetransmissionTimer(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseRetransmissionTimer, set_UseRetransmissionTimer, TElDTLSServer, UseRetransmissionTimer);

		virtual int32_t get_TimerValue();

		virtual void set_TimerValue(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TimerValue, set_TimerValue, TElDTLSServer, TimerValue);

		virtual bool get_AutoAdjustTimerValue();

		virtual void set_AutoAdjustTimerValue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustTimerValue, set_AutoAdjustTimerValue, TElDTLSServer, AutoAdjustTimerValue);

		TElDTLSServer(TElDTLSServerHandle handle, TElOwnHandle ownHandle);

		explicit TElDTLSServer(TComponent &Owner);

		explicit TElDTLSServer(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELDTLSSERVER */

#ifdef SB_USE_CLASS_TELDTLSSERVERFACTORY
class TElDTLSServerFactory: public TComponent
{
	private:
		SB_DISABLE_COPY(TElDTLSServerFactory)
	public:
		void ProcessRequest(void * Buffer, int32_t Size, const std::vector<uint8_t> &ClientID);

		virtual void get_OnSend(TSBDTLSSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSBDTLSSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnServerCreated(TSBDTLSServerCreatedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnServerCreated(TSBDTLSServerCreatedEvent pMethodValue, void * pDataValue);

		TElDTLSServerFactory(TElDTLSServerFactoryHandle handle, TElOwnHandle ownHandle);

		explicit TElDTLSServerFactory(TComponent &AOwner);

		explicit TElDTLSServerFactory(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELDTLSSERVERFACTORY */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDTLSSERVER */

