#ifndef __INC_SBHTTPTSPCLIENT
#define __INC_SBHTTPTSPCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbsha.h"
#include "sbpkcs7.h"
#include "sbmessages.h"
#include "sbpkicommon.h"
#include "sbtspcommon.h"
#include "sbtspclient.h"
#include "sbhttpsclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElHTTPTSPClientHandle;

typedef TElHTTPTSPClientHandle ElHTTPTSPClientHandle;

typedef void (SB_CALLBACK *TSBHTTPTSPErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ResponseCode);

#ifdef SB_USE_CLASS_TELHTTPTSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElHTTPTSPClient_Timestamp(TElHTTPTSPClientHandle _Handle, const uint8_t pHashedData[], int32_t szHashedData, TSBPKIStatusRaw * ServerResult, int32_t * FailureInfo, uint8_t pReplyCMS[], int32_t * szReplyCMS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPTSPClient_get_HTTPClient(TElHTTPTSPClientHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPTSPClient_set_HTTPClient(TElHTTPTSPClientHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPTSPClient_get_URL(TElHTTPTSPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPTSPClient_set_URL(TElHTTPTSPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPTSPClient_get_OnHTTPError(TElHTTPTSPClientHandle _Handle, TSBHTTPTSPErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPTSPClient_set_OnHTTPError(TElHTTPTSPClientHandle _Handle, TSBHTTPTSPErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPTSPClient_Create(TComponentHandle AOwner, TElHTTPTSPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPTSPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHTTPTSPClient;
typedef TElHTTPTSPClient ElHTTPTSPClient;

#ifdef SB_USE_CLASS_TELHTTPTSPCLIENT
class TElHTTPTSPClient: public TElCustomTSPClient
{
	private:
		SB_DISABLE_COPY(TElHTTPTSPClient)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		virtual int32_t Timestamp(const std::vector<uint8_t> &HashedData, TSBPKIStatus &ServerResult, int32_t &FailureInfo, std::vector<uint8_t> &ReplyCMS);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElHTTPTSPClient, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_OnHTTPError(TSBHTTPTSPErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHTTPError(TSBHTTPTSPErrorEvent pMethodValue, void * pDataValue);

		TElHTTPTSPClient(TElHTTPTSPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElHTTPTSPClient(TComponent &AOwner);

		explicit TElHTTPTSPClient(TComponent *AOwner);

		virtual ~TElHTTPTSPClient();

};
#endif /* SB_USE_CLASS_TELHTTPTSPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPTSPCLIENT */

