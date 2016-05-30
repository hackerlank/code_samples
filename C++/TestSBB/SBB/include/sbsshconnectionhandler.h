#ifndef __INC_SBSSHCONNECTIONHANDLER
#define __INC_SBSSHCONNECTIONHANDLER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsshcommon.h"
#include "sbsharedresource.h"
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
typedef TElClassHandle TElSSHConnectionHandlerHandle;

typedef TElSSHConnectionHandlerHandle ElSSHConnectionHandlerHandle;

#ifdef SB_USE_CLASS_TELSSHCONNECTIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_Disconnect(TElSSHConnectionHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_SendData(TElSSHConnectionHandlerHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_SendExtendedData(TElSSHConnectionHandlerHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_ReceiveData(TElSSHConnectionHandlerHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_ReceiveLength(TElSSHConnectionHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_get_Connected(TElSSHConnectionHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_get_Connection(TElSSHConnectionHandlerHandle _Handle, TElSSHTunnelConnectionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_get_OnDisconnect(TElSSHConnectionHandlerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_set_OnDisconnect(TElSSHConnectionHandlerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHConnectionHandler_Create(TElSSHTunnelConnectionHandle Connection, TElSSHConnectionHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHCONNECTIONHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHConnectionHandler;
typedef TElSSHConnectionHandler ElSSHConnectionHandler;

#ifdef SB_USE_CLASS_TELSSHCONNECTIONHANDLER
class TElSSHConnectionHandler: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHConnectionHandler)
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		TElSSHTunnelConnection* _Inst_Connection;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		void initInstances();

	public:
		void Disconnect();

		void SendData(void * Buffer, int32_t Size);

		void SendExtendedData(void * Buffer, int32_t Size);

		int32_t ReceiveData(void * Buffer, int32_t Size);

		int32_t ReceiveLength();

		virtual bool get_Connected();

		SB_DECLARE_PROPERTY_GET(bool, get_Connected, TElSSHConnectionHandler, Connected);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		virtual TElSSHTunnelConnection* get_Connection();

		SB_DECLARE_PROPERTY_GET(TElSSHTunnelConnection*, get_Connection, TElSSHConnectionHandler, Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		virtual void get_OnDisconnect(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDisconnect(TNotifyEvent pMethodValue, void * pDataValue);

		TElSSHConnectionHandler(TElSSHConnectionHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElSSHConnectionHandler(TElSSHTunnelConnection &Connection);

		explicit TElSSHConnectionHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		virtual ~TElSSHConnectionHandler();

};
#endif /* SB_USE_CLASS_TELSSHCONNECTIONHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHCONNECTIONHANDLER */

