#ifndef __INC_SBSFTPHANDLER
#define __INC_SBSFTPHANDLER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbsshcommon.h"
#include "sbsshhandlers.h"
#include "sbsftpcommon.h"
#include "sbsftpserver.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSFTPSSHSubsystemHandlerHandle;

typedef TElSFTPSSHSubsystemHandlerHandle ElSFTPSSHSubsystemHandlerHandle;

#ifdef SB_USE_CLASS_TELSFTPSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_HandlerType(TElSFTPSSHSubsystemHandlerHandle _Handle, TSBSSHSubsystemHandlerTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_get_Version(TElSFTPSSHSubsystemHandlerHandle _Handle, TSBSftpVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_get_Versions(TElSFTPSSHSubsystemHandlerHandle _Handle, TSBSftpVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_set_Versions(TElSFTPSSHSubsystemHandlerHandle _Handle, TSBSftpVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_get_NewLineConvention(TElSFTPSSHSubsystemHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_set_NewLineConvention(TElSFTPSSHSubsystemHandlerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_get_Server(TElSFTPSSHSubsystemHandlerHandle _Handle, TElSFTPServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_set_Server(TElSFTPSSHSubsystemHandlerHandle _Handle, TElSFTPServerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElSFTPSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPSSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElSFTPServerHandle Server, TElSFTPSSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPSSHSUBSYSTEMHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSFTPSSHSubsystemHandler;
typedef TElSFTPSSHSubsystemHandler ElSFTPSSHSubsystemHandler;

#ifdef SB_USE_CLASS_TELSFTPSSHSUBSYSTEMHANDLER
class TElSFTPSSHSubsystemHandler: public TElCustomSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElSFTPSSHSubsystemHandler)
#ifdef SB_USE_CLASS_TELSFTPSERVER
		TElSFTPServer* _Inst_Server;
#endif /* SB_USE_CLASS_TELSFTPSERVER */

		void initInstances();

	public:
		virtual TSBSSHSubsystemHandlerType HandlerType();

		static TClassHandle ClassType();

		virtual TSBSftpVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSBSftpVersion, get_Version, TElSFTPSSHSubsystemHandler, Version);

		virtual TSBSftpVersions get_Versions();

		virtual void set_Versions(TSBSftpVersions Value);

		SB_DECLARE_PROPERTY(TSBSftpVersions, get_Versions, set_Versions, TElSFTPSSHSubsystemHandler, Versions);

		virtual void get_NewLineConvention(std::string &OutResult);

		virtual void set_NewLineConvention(const std::string &Value);

#ifdef SB_USE_CLASS_TELSFTPSERVER
		virtual TElSFTPServer* get_Server();

		virtual void set_Server(TElSFTPServer &Value);

		virtual void set_Server(TElSFTPServer *Value);

		SB_DECLARE_PROPERTY(TElSFTPServer*, get_Server, set_Server, TElSFTPSSHSubsystemHandler, Server);
#endif /* SB_USE_CLASS_TELSFTPSERVER */

		TElSFTPSSHSubsystemHandler(TElSFTPSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElSFTPSSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElSFTPSSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASSES_TELSFTPSERVER_AND_TELSSHTUNNELCONNECTION
		static TElSFTPSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection, TElSFTPServer &Server);

		static TElSFTPSSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection, TElSFTPServer *Server);
#endif /* SB_USE_CLASSES_TELSFTPSERVER_AND_TELSSHTUNNELCONNECTION */

		virtual ~TElSFTPSSHSubsystemHandler();

};
#endif /* SB_USE_CLASS_TELSFTPSSHSUBSYSTEMHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSFTPHANDLER */

