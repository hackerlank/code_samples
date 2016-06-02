#ifndef __INC_SBWEBSOCKETCLIENT
#define __INC_SBWEBSOCKETCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsslcommon.h"
#include "sbsimplessl.h"
#include "sbcustomcertstorage.h"
#include "sbcookiemgr.h"
#include "sbhttpsconstants.h"
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
#include "sbrandom.h"
#include "sbsslclient.h"
#include "sbwebsocketcommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElWebSocketClientHandle;

#ifdef SB_USE_CLASS_TELWEBSOCKETCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketClient_DataAvailable(TElWebSocketClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketClient_CreateWebSocketKey(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketClient_CreateWebSocketKey_1(TElWebSocketClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketClient_Create(TElWebSocketClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebSocketClient_Create_1(TElSSLClassHandle Control, TElWebSocketClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBSOCKETCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElWebSocketClient;

#ifdef SB_USE_CLASS_TELWEBSOCKETCLIENT
class TElWebSocketClient: public TElWebSocketBase
{
	private:
		SB_DISABLE_COPY(TElWebSocketClient)
	public:
		void DataAvailable();

		static void CreateWebSocketKey(std::string &OutResult);

		void CreateWebSocketKey_Inst(std::string &OutResult);

		TElWebSocketClient(TElWebSocketClientHandle handle, TElOwnHandle ownHandle);

		TElWebSocketClient();

#ifdef SB_USE_CLASS_TELSSLCLASS
		explicit TElWebSocketClient(TElSSLClass &Control);

		explicit TElWebSocketClient(TElSSLClass *Control);
#endif /* SB_USE_CLASS_TELSSLCLASS */

};
#endif /* SB_USE_CLASS_TELWEBSOCKETCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWEBSOCKETCLIENT */

