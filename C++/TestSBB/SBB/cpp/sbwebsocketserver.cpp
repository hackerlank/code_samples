#include "sbwebsocketserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELWEBSOCKETSERVER

TElWebSocketServer::TElWebSocketServer(TElWebSocketServerHandle handle, TElOwnHandle ownHandle) : TElWebSocketBase(handle, ownHandle)
{
}

TElWebSocketServer::TElWebSocketServer() : TElWebSocketBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketServer_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELSSLCLASS
TElWebSocketServer::TElWebSocketServer(TElSSLClass &Control) : TElWebSocketBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketServer_Create_1(Control.getHandle(), &_Handle));
}

TElWebSocketServer::TElWebSocketServer(TElSSLClass *Control) : TElWebSocketBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElWebSocketServer_Create_1((Control != NULL) ? Control->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSLCLASS */

#endif /* SB_USE_CLASS_TELWEBSOCKETSERVER */

};	/* namespace SecureBlackbox */

