#ifndef __INC_SBSSHFORWARDINGHANDLERS
#define __INC_SBSSHFORWARDINGHANDLERS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsshcommon.h"
#include "sbsshhandlers.h"
#include "sbsocket.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElTCPForwardingSSHSubsystemHandlerHandle;

typedef TElTCPForwardingSSHSubsystemHandlerHandle ElTCPForwardingSSHSubsystemHandlerHandle;

typedef TElClassHandle TElClientTCPForwardingSSHSubsystemHandlerHandle;

typedef TElClientTCPForwardingSSHSubsystemHandlerHandle ElClientTCPForwardingSSHSubsystemHandlerHandle;

typedef TElClassHandle TElServerTCPForwardingSSHSubsystemHandlerHandle;

typedef TElServerTCPForwardingSSHSubsystemHandlerHandle ElServerTCPForwardingSSHSubsystemHandlerHandle;

typedef TElClassHandle TElBuiltinTCPForwardingSSHSubsystemHandlerHandle;

typedef TElBuiltinTCPForwardingSSHSubsystemHandlerHandle ElBuiltinTCPForwardingSSHSubsystemHandlerHandle;

typedef TElClassHandle TElBuiltinClientTCPForwardingSSHSubsystemHandlerHandle;

typedef TElBuiltinClientTCPForwardingSSHSubsystemHandlerHandle ElBuiltinClientTCPForwardingSSHSubsystemHandlerHandle;

typedef TElClassHandle TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle;

typedef TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle ElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle;

#ifdef SB_USE_CLASS_TELTCPFORWARDINGSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElTCPForwardingSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTCPForwardingSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTCPForwardingSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElClientTCPForwardingSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTCPForwardingSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTCPForwardingSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElServerTCPForwardingSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTCPForwardingSSHSubsystemHandler_get_Socket(TElServerTCPForwardingSSHSubsystemHandlerHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTCPForwardingSSHSubsystemHandler_set_Socket(TElServerTCPForwardingSSHSubsystemHandlerHandle _Handle, TElSocketHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElServerTCPForwardingSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTCPForwardingSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINTCPFORWARDINGSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinTCPForwardingSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinTCPForwardingSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinTCPForwardingSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinClientTCPForwardingSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinClientTCPForwardingSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinClientTCPForwardingSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinServerTCPForwardingSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinServerTCPForwardingSSHSubsystemHandler_get_Socket(TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinServerTCPForwardingSSHSubsystemHandler_set_Socket(TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle _Handle, TElSocketHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinServerTCPForwardingSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltinServerTCPForwardingSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElTCPForwardingSSHSubsystemHandler;
typedef TElTCPForwardingSSHSubsystemHandler ElTCPForwardingSSHSubsystemHandler;
class TElClientTCPForwardingSSHSubsystemHandler;
typedef TElClientTCPForwardingSSHSubsystemHandler ElClientTCPForwardingSSHSubsystemHandler;
class TElServerTCPForwardingSSHSubsystemHandler;
typedef TElServerTCPForwardingSSHSubsystemHandler ElServerTCPForwardingSSHSubsystemHandler;
class TElBuiltinTCPForwardingSSHSubsystemHandler;
typedef TElBuiltinTCPForwardingSSHSubsystemHandler ElBuiltinTCPForwardingSSHSubsystemHandler;
class TElBuiltinClientTCPForwardingSSHSubsystemHandler;
typedef TElBuiltinClientTCPForwardingSSHSubsystemHandler ElBuiltinClientTCPForwardingSSHSubsystemHandler;
class TElBuiltinServerTCPForwardingSSHSubsystemHandler;
typedef TElBuiltinServerTCPForwardingSSHSubsystemHandler ElBuiltinServerTCPForwardingSSHSubsystemHandler;

#ifdef SB_USE_CLASS_TELTCPFORWARDINGSSHSUBSYSTEMHANDLER
class TElTCPForwardingSSHSubsystemHandler: public TElCustomSocketForwardingSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElTCPForwardingSSHSubsystemHandler)
	public:
		static TClassHandle ClassType();

		TElTCPForwardingSSHSubsystemHandler(TElTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

};
#endif /* SB_USE_CLASS_TELTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER
class TElClientTCPForwardingSSHSubsystemHandler: public TElTCPForwardingSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElClientTCPForwardingSSHSubsystemHandler)
	public:
		static TClassHandle ClassType();

		TElClientTCPForwardingSSHSubsystemHandler(TElClientTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElClientTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElClientTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElClientTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElClientTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

};
#endif /* SB_USE_CLASS_TELCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
class TElServerTCPForwardingSSHSubsystemHandler: public TElTCPForwardingSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElServerTCPForwardingSSHSubsystemHandler)
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */

		void initInstances();

	public:
		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		virtual void set_Socket(TElSocket &Value);

		virtual void set_Socket(TElSocket *Value);

		SB_DECLARE_PROPERTY(TElSocket*, get_Socket, set_Socket, TElServerTCPForwardingSSHSubsystemHandler, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		TElServerTCPForwardingSSHSubsystemHandler(TElServerTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElServerTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElServerTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElServerTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElServerTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		virtual ~TElServerTCPForwardingSSHSubsystemHandler();

};
#endif /* SB_USE_CLASS_TELSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINTCPFORWARDINGSSHSUBSYSTEMHANDLER
class TElBuiltinTCPForwardingSSHSubsystemHandler: public TElCustomSocketForwardingSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElBuiltinTCPForwardingSSHSubsystemHandler)
	public:
		static TClassHandle ClassType();

		TElBuiltinTCPForwardingSSHSubsystemHandler(TElBuiltinTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElBuiltinTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElBuiltinTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElBuiltinTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElBuiltinTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

};
#endif /* SB_USE_CLASS_TELBUILTINTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER
class TElBuiltinClientTCPForwardingSSHSubsystemHandler: public TElBuiltinTCPForwardingSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElBuiltinClientTCPForwardingSSHSubsystemHandler)
	public:
		static TClassHandle ClassType();

		TElBuiltinClientTCPForwardingSSHSubsystemHandler(TElBuiltinClientTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElBuiltinClientTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElBuiltinClientTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElBuiltinClientTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElBuiltinClientTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

};
#endif /* SB_USE_CLASS_TELBUILTINCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
class TElBuiltinServerTCPForwardingSSHSubsystemHandler: public TElBuiltinTCPForwardingSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElBuiltinServerTCPForwardingSSHSubsystemHandler)
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */

		void initInstances();

	public:
		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		virtual void set_Socket(TElSocket &Value);

		virtual void set_Socket(TElSocket *Value);

		SB_DECLARE_PROPERTY(TElSocket*, get_Socket, set_Socket, TElBuiltinServerTCPForwardingSSHSubsystemHandler, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		TElBuiltinServerTCPForwardingSSHSubsystemHandler(TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElBuiltinServerTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElBuiltinServerTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElBuiltinServerTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElBuiltinServerTCPForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		virtual ~TElBuiltinServerTCPForwardingSSHSubsystemHandler();

};
#endif /* SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHFORWARDINGHANDLERS */

