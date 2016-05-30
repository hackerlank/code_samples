#ifndef __INC_SBWEBSOCKETSERVER
#define __INC_SBWEBSOCKETSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcustomcertstorage.h"
#include "sbsslconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbstreams.h"
#include "sbhttpscommon.h"
#include "sbhttpauth.h"
#include "sbsocket.h"
#include "sboauth2.h"
#include "sbsslcommon.h"
#include "sbsslserver.h"
#include "sbwebsocketcommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElWebSocketServerHandle;

#ifdef SB_USE_CLASS_TELWEBSOCKETSERVER
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketServer_Create(TElWebSocketServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketServer_Create_1(TElSSLClassHandle Control, TElWebSocketServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElWebSocketServer;

#ifdef SB_USE_CLASS_TELWEBSOCKETSERVER
class TElWebSocketServer: public TElWebSocketBase
{
	private:
		SB_DISABLE_COPY(TElWebSocketServer)
	public:
		TElWebSocketServer(TElWebSocketServerHandle handle, TElOwnHandle ownHandle);

		TElWebSocketServer();

#ifdef SB_USE_CLASS_TELSSLCLASS
		explicit TElWebSocketServer(TElSSLClass &Control);

		explicit TElWebSocketServer(TElSSLClass *Control);
#endif /* SB_USE_CLASS_TELSSLCLASS */

};
#endif /* SB_USE_CLASS_TELWEBSOCKETSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWEBSOCKETSERVER */

