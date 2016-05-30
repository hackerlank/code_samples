#ifndef __INC_SBSOCKETTSPCLIENT
#define __INC_SBSOCKETTSPCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbencoding.h"
#include "sbconstants.h"
#include "sbpem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbpkcs7.h"
#include "sbpkicommon.h"
#include "sbtspcommon.h"
#include "sbtspclient.h"
#include "sbsocket.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSocketTSPClientHandle;

#ifdef SB_USE_CLASS_TELSOCKETTSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_Timestamp(TElSocketTSPClientHandle _Handle, const uint8_t pHashedData[], int32_t szHashedData, TSBPKIStatusRaw * ServerResult, int32_t * FailureInfo, uint8_t pReplyCMS[], int32_t * szReplyCMS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_get_Socket(TElSocketTSPClientHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_get_ErrorMessage(TElSocketTSPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_get_Address(TElSocketTSPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_set_Address(TElSocketTSPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_get_Port(TElSocketTSPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_set_Port(TElSocketTSPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_get_SocketTimeout(TElSocketTSPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_set_SocketTimeout(TElSocketTSPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketTSPClient_Create(TComponentHandle Owner, TElSocketTSPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSOCKETTSPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSocketTSPClient;

#ifdef SB_USE_CLASS_TELSOCKETTSPCLIENT
class TElSocketTSPClient: public TElCustomTSPClient
{
	private:
		SB_DISABLE_COPY(TElSocketTSPClient)
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */

		void initInstances();

	public:
		virtual int32_t Timestamp(const std::vector<uint8_t> &HashedData, TSBPKIStatus &ServerResult, int32_t &FailureInfo, std::vector<uint8_t> &ReplyCMS);

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_Socket, TElSocketTSPClient, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		virtual void get_ErrorMessage(std::string &OutResult);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSocketTSPClient, Port);

		virtual int32_t get_SocketTimeout();

		virtual void set_SocketTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketTimeout, set_SocketTimeout, TElSocketTSPClient, SocketTimeout);

		TElSocketTSPClient(TElSocketTSPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSocketTSPClient(TComponent &Owner);

		explicit TElSocketTSPClient(TComponent *Owner);

		virtual ~TElSocketTSPClient();

};
#endif /* SB_USE_CLASS_TELSOCKETTSPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSOCKETTSPCLIENT */

