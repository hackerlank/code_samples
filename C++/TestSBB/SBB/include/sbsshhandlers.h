#ifndef __INC_SBSSHHANDLERS
#define __INC_SBSSHHANDLERS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsshcommon.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbsharedresource.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCustomSSHSubsystemHandlerHandle;

typedef TElCustomSSHSubsystemHandlerHandle ElCustomSSHSubsystemHandlerHandle;

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef TElClassHandle TElShellSSHSubsystemHandlerHandle;

typedef TElShellSSHSubsystemHandlerHandle ElShellSSHSubsystemHandlerHandle;
#endif

typedef TElClassHandle TElCustomSocketForwardingSSHSubsystemHandlerHandle;

typedef TElCustomSocketForwardingSSHSubsystemHandlerHandle ElCustomSocketForwardingSSHSubsystemHandlerHandle;

typedef TElClassHandle TElSSHSubsystemThreadHandle;

typedef TElSSHSubsystemThreadHandle ElSSHSubsystemThreadHandle;

typedef uint8_t TSBSSHSubsystemHandlerTypeRaw;

typedef enum
{
	shtSynchronous = 0,
	shtAsynchronous = 1
} TSBSSHSubsystemHandlerType;

typedef void (SB_CALLBACK *TSBSSHSubsystemHandlerTerminateRequest)(void * _ObjectData, TObjectHandle Sender, int8_t * Terminate);

typedef TElClassHandle TElSSHSubsystemHandlerClassHandle;

typedef TElSSHSubsystemHandlerClassHandle ElSSHSubsystemHandlerClassHandle;

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef void (SB_CALLBACK *TSBSSHEncodedStringEvent)(void * _ObjectData, TObjectHandle Sender, uint8_t pBuf[], int32_t * szBuf);
#endif

#ifdef SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_HandlerType(TElCustomSSHSubsystemHandlerHandle _Handle, TSBSSHSubsystemHandlerTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_Run(TElCustomSSHSubsystemHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_Terminate(TElCustomSSHSubsystemHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_WaitForInputData(TElCustomSSHSubsystemHandlerHandle _Handle, int32_t Time, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_get_Connection(TElCustomSSHSubsystemHandlerHandle _Handle, TElSSHTunnelConnectionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_get_FlushCachedData(TElCustomSSHSubsystemHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_set_FlushCachedData(TElCustomSSHSubsystemHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_get_OnTerminateRequest(TElCustomSSHSubsystemHandlerHandle _Handle, TSBSSHSubsystemHandlerTerminateRequest * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_set_OnTerminateRequest(TElCustomSSHSubsystemHandlerHandle _Handle, TSBSSHSubsystemHandlerTerminateRequest pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_get_OnDisconnect(TElCustomSSHSubsystemHandlerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_set_OnDisconnect(TElCustomSSHSubsystemHandlerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_get_OnUnsafeOperationStart(TElCustomSSHSubsystemHandlerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_set_OnUnsafeOperationStart(TElCustomSSHSubsystemHandlerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_get_OnUnsafeOperationEnd(TElCustomSSHSubsystemHandlerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_set_OnUnsafeOperationEnd(TElCustomSSHSubsystemHandlerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_get_OnEOF(TElCustomSSHSubsystemHandlerHandle _Handle, TSSHEOFEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_set_OnEOF(TElCustomSSHSubsystemHandlerHandle _Handle, TSSHEOFEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELSHELLSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_HandlerType(TElShellSSHSubsystemHandlerHandle _Handle, TSBSSHSubsystemHandlerTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_Command(TElShellSSHSubsystemHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_Command(TElShellSSHSubsystemHandlerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_RawCommandLine(TElShellSSHSubsystemHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_RawCommandLine(TElShellSSHSubsystemHandlerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_CurrentDirectory(TElShellSSHSubsystemHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_CurrentDirectory(TElShellSSHSubsystemHandlerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_NoCharacterEncoding(TElShellSSHSubsystemHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_NoCharacterEncoding(TElShellSSHSubsystemHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_UseUTF8(TElShellSSHSubsystemHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_UseUTF8(TElShellSSHSubsystemHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_OutputLines(TElShellSSHSubsystemHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_OutputLines(TElShellSSHSubsystemHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_SendCharactersBack(TElShellSSHSubsystemHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_SendCharactersBack(TElShellSSHSubsystemHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_MaxCacheSize(TElShellSSHSubsystemHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_MaxCacheSize(TElShellSSHSubsystemHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_OnBeforeDecoding(TElShellSSHSubsystemHandlerHandle _Handle, TSBSSHEncodedStringEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_OnBeforeDecoding(TElShellSSHSubsystemHandlerHandle _Handle, TSBSSHEncodedStringEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_get_OnAfterEncoding(TElShellSSHSubsystemHandlerHandle _Handle, TSBSSHEncodedStringEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_set_OnAfterEncoding(TElShellSSHSubsystemHandlerHandle _Handle, TSBSSHEncodedStringEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSHELLSSHSUBSYSTEMHANDLER */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMSOCKETFORWARDINGSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_HandlerType(TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle, TSBSSHSubsystemHandlerTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_get_Host(TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_set_Host(TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_get_Port(TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_set_Port(TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_get_Timeout(TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_set_Timeout(TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketForwardingSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElCustomSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSOCKETFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELSSHSUBSYSTEMTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSSHSubsystemThread_get_Handler(TElSSHSubsystemThreadHandle _Handle, TElCustomSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHSubsystemThread_get_OnTerminateSubsystem(TElSSHSubsystemThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHSubsystemThread_set_OnTerminateSubsystem(TElSSHSubsystemThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHSubsystemThread_Create(TElSSHSubsystemHandlerClassHandle Cls, TElSSHTunnelConnectionHandle Connection, int8_t CreateSuspended, TElSSHSubsystemThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHSUBSYSTEMTHREAD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCustomSSHSubsystemHandler;
typedef TElCustomSSHSubsystemHandler ElCustomSSHSubsystemHandler;
#ifndef SB_WINCE_OR_NOT_WINDOWS
class TElShellSSHSubsystemHandler;
typedef TElShellSSHSubsystemHandler ElShellSSHSubsystemHandler;
#endif
class TElCustomSocketForwardingSSHSubsystemHandler;
typedef TElCustomSocketForwardingSSHSubsystemHandler ElCustomSocketForwardingSSHSubsystemHandler;
class TElSSHSubsystemThread;
typedef TElSSHSubsystemThread ElSSHSubsystemThread;

#ifdef SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER
class TElCustomSSHSubsystemHandler: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomSSHSubsystemHandler)
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		TElSSHTunnelConnection* _Inst_Connection;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		void initInstances();

	public:
		virtual TSBSSHSubsystemHandlerType HandlerType();

		void Run();

		void Terminate();

		bool WaitForInputData(int32_t Time);

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		virtual TElSSHTunnelConnection* get_Connection();

		SB_DECLARE_PROPERTY_GET(TElSSHTunnelConnection*, get_Connection, TElCustomSSHSubsystemHandler, Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		virtual bool get_FlushCachedData();

		virtual void set_FlushCachedData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_FlushCachedData, set_FlushCachedData, TElCustomSSHSubsystemHandler, FlushCachedData);

		virtual void get_OnTerminateRequest(TSBSSHSubsystemHandlerTerminateRequest &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTerminateRequest(TSBSSHSubsystemHandlerTerminateRequest pMethodValue, void * pDataValue);

		virtual void get_OnDisconnect(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDisconnect(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnsafeOperationStart(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnsafeOperationStart(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnsafeOperationEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnsafeOperationEnd(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnEOF(TSSHEOFEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEOF(TSSHEOFEvent pMethodValue, void * pDataValue);

		TElCustomSSHSubsystemHandler(TElCustomSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElCustomSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElCustomSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElCustomSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElCustomSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		virtual ~TElCustomSSHSubsystemHandler();

};
#endif /* SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELSHELLSSHSUBSYSTEMHANDLER
class TElShellSSHSubsystemHandler: public TElCustomSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElShellSSHSubsystemHandler)
	public:
		virtual TSBSSHSubsystemHandlerType HandlerType();

		static TClassHandle ClassType();

		virtual void get_Command(std::string &OutResult);

		virtual void set_Command(const std::string &Value);

		virtual void get_RawCommandLine(std::string &OutResult);

		virtual void set_RawCommandLine(const std::string &Value);

		virtual void get_CurrentDirectory(std::string &OutResult);

		virtual void set_CurrentDirectory(const std::string &Value);

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TElShellSSHSubsystemHandler, NoCharacterEncoding);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElShellSSHSubsystemHandler, UseUTF8);

		virtual bool get_OutputLines();

		virtual void set_OutputLines(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OutputLines, set_OutputLines, TElShellSSHSubsystemHandler, OutputLines);

		virtual bool get_SendCharactersBack();

		virtual void set_SendCharactersBack(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SendCharactersBack, set_SendCharactersBack, TElShellSSHSubsystemHandler, SendCharactersBack);

		virtual int32_t get_MaxCacheSize();

		virtual void set_MaxCacheSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxCacheSize, set_MaxCacheSize, TElShellSSHSubsystemHandler, MaxCacheSize);

		virtual void get_OnBeforeDecoding(TSBSSHEncodedStringEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeDecoding(TSBSSHEncodedStringEvent pMethodValue, void * pDataValue);

		virtual void get_OnAfterEncoding(TSBSSHEncodedStringEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAfterEncoding(TSBSSHEncodedStringEvent pMethodValue, void * pDataValue);

		TElShellSSHSubsystemHandler(TElShellSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElShellSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElShellSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElShellSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElShellSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

};
#endif /* SB_USE_CLASS_TELSHELLSSHSUBSYSTEMHANDLER */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMSOCKETFORWARDINGSSHSUBSYSTEMHANDLER
class TElCustomSocketForwardingSSHSubsystemHandler: public TElCustomSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElCustomSocketForwardingSSHSubsystemHandler)
	public:
		virtual TSBSSHSubsystemHandlerType HandlerType();

		static TClassHandle ClassType();

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElCustomSocketForwardingSSHSubsystemHandler, Port);

		virtual int32_t get_Timeout();

		virtual void set_Timeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Timeout, set_Timeout, TElCustomSocketForwardingSSHSubsystemHandler, Timeout);

		TElCustomSocketForwardingSSHSubsystemHandler(TElCustomSocketForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElCustomSocketForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElCustomSocketForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		static TElCustomSocketForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection);

		static TElCustomSocketForwardingSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

};
#endif /* SB_USE_CLASS_TELCUSTOMSOCKETFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELSSHSUBSYSTEMTHREAD
class TElSSHSubsystemThread: public TThread
{
	private:
		SB_DISABLE_COPY(TElSSHSubsystemThread)
#ifdef SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER
		TElCustomSSHSubsystemHandler* _Inst_Handler;
#endif /* SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER
		virtual TElCustomSSHSubsystemHandler* get_Handler();

		SB_DECLARE_PROPERTY_GET(TElCustomSSHSubsystemHandler*, get_Handler, TElSSHSubsystemThread, Handler);
#endif /* SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER */

		virtual void get_OnTerminateSubsystem(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTerminateSubsystem(TNotifyEvent pMethodValue, void * pDataValue);

		TElSSHSubsystemThread(TElSSHSubsystemThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		TElSSHSubsystemThread(TElSSHSubsystemHandlerClassHandle Cls, TElSSHTunnelConnection &Connection, bool CreateSuspended);

		TElSSHSubsystemThread(TElSSHSubsystemHandlerClassHandle Cls, TElSSHTunnelConnection *Connection, bool CreateSuspended);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		virtual ~TElSSHSubsystemThread();

};
#endif /* SB_USE_CLASS_TELSSHSUBSYSTEMTHREAD */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHHANDLERS */
