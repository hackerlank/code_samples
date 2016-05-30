#ifndef __INC_SBSSHPUBKEYHANDLER
#define __INC_SBSSHPUBKEYHANDLER

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
#include "sbsshpubkeycommon.h"
#include "sbsshpubkeyserver.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPublicKeySSHSubsystemHandlerHandle;

typedef TElPublicKeySSHSubsystemHandlerHandle ElPublicKeySSHSubsystemHandlerHandle;

#ifdef SB_USE_CLASS_TELPUBLICKEYSSHSUBSYSTEMHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeySSHSubsystemHandler_HandlerType(TElPublicKeySSHSubsystemHandlerHandle _Handle, TSBSSHSubsystemHandlerTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeySSHSubsystemHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeySSHSubsystemHandler_get_Server(TElPublicKeySSHSubsystemHandlerHandle _Handle, TElSSHPublicKeyServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeySSHSubsystemHandler_set_Server(TElPublicKeySSHSubsystemHandlerHandle _Handle, TElSSHPublicKeyServerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeySSHSubsystemHandler_Create(TElSSHTunnelConnectionHandle Connection, TElPublicKeySSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPublicKeySSHSubsystemHandler_CreateDelayed(TElSSHTunnelConnectionHandle Connection, TElSSHPublicKeyServerHandle Server, TElPublicKeySSHSubsystemHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPUBLICKEYSSHSUBSYSTEMHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPublicKeySSHSubsystemHandler;
typedef TElPublicKeySSHSubsystemHandler ElPublicKeySSHSubsystemHandler;

#ifdef SB_USE_CLASS_TELPUBLICKEYSSHSUBSYSTEMHANDLER
class TElPublicKeySSHSubsystemHandler: public TElCustomSSHSubsystemHandler
{
	private:
		SB_DISABLE_COPY(TElPublicKeySSHSubsystemHandler)
#ifdef SB_USE_CLASS_TELSSHPUBLICKEYSERVER
		TElSSHPublicKeyServer* _Inst_Server;
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYSERVER */

		void initInstances();

	public:
		virtual TSBSSHSubsystemHandlerType HandlerType();

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYSERVER
		virtual TElSSHPublicKeyServer* get_Server();

		virtual void set_Server(TElSSHPublicKeyServer &Value);

		virtual void set_Server(TElSSHPublicKeyServer *Value);

		SB_DECLARE_PROPERTY(TElSSHPublicKeyServer*, get_Server, set_Server, TElPublicKeySSHSubsystemHandler, Server);
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYSERVER */

		TElPublicKeySSHSubsystemHandler(TElPublicKeySSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		explicit TElPublicKeySSHSubsystemHandler(TElSSHTunnelConnection &Connection);

		explicit TElPublicKeySSHSubsystemHandler(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASSES_TELSSHPUBLICKEYSERVER_AND_TELSSHTUNNELCONNECTION
		static TElPublicKeySSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection &Connection, TElSSHPublicKeyServer &Server);

		static TElPublicKeySSHSubsystemHandler CreateDelayed(TElSSHTunnelConnection *Connection, TElSSHPublicKeyServer *Server);
#endif /* SB_USE_CLASSES_TELSSHPUBLICKEYSERVER_AND_TELSSHTUNNELCONNECTION */

		virtual ~TElPublicKeySSHSubsystemHandler();

};
#endif /* SB_USE_CLASS_TELPUBLICKEYSSHSUBSYSTEMHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHPUBKEYHANDLER */

