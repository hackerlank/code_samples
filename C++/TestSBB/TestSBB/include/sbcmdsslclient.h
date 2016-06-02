#ifndef __INC_SBCMDSSLCLIENT
#define __INC_SBCMDSSLCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbcrc.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbcustomcertstorage.h"
#include "sbsslcommon.h"
#include "sbconstants.h"
#include "sbsharedresource.h"
#include "sbsslclient.h"
#include "sbsimplessl.h"
#include "sbsocket.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCommandSSLClientHandle;

typedef TElCommandSSLClientHandle ElCommandSSLClientHandle;

#ifdef SB_USE_CLASS_TELCOMMANDSSLCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSLClient_SendCmd(TElCommandSSLClientHandle _Handle, const char * pcCommand, int32_t szCommand, const int16_t pAcceptCodes[], int32_t szAcceptCodes, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSLClient_get_LastReply(TElCommandSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSLClient_get_OnSent(TElCommandSSLClientHandle _Handle, TSBTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSLClient_set_OnSent(TElCommandSSLClientHandle _Handle, TSBTextDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSLClient_get_OnReceived(TElCommandSSLClientHandle _Handle, TSBTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSLClient_set_OnReceived(TElCommandSSLClientHandle _Handle, TSBTextDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSLClient_Create(TComponentHandle AOwner, TElCommandSSLClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMMANDSSLCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCommandSSLClient;
typedef TElCommandSSLClient ElCommandSSLClient;

#ifdef SB_USE_CLASS_TELCOMMANDSSLCLIENT
class TElCommandSSLClient: public TElSimpleSSLClient
{
	private:
		SB_DISABLE_COPY(TElCommandSSLClient)
	public:
		int16_t SendCmd(const std::string &Command, const std::vector<int16_t> &AcceptCodes);

		virtual void get_LastReply(std::string &OutResult);

		virtual void get_OnSent(TSBTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSent(TSBTextDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceived(TSBTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceived(TSBTextDataEvent pMethodValue, void * pDataValue);

		TElCommandSSLClient(TElCommandSSLClientHandle handle, TElOwnHandle ownHandle);

		explicit TElCommandSSLClient(TComponent &AOwner);

		explicit TElCommandSSLClient(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELCOMMANDSSLCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCMDSSLCLIENT */

