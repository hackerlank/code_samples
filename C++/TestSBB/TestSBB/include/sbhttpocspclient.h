#ifndef __INC_SBHTTPOCSPCLIENT
#define __INC_SBHTTPOCSPCLIENT

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
#include "sbcrl.h"
#include "sbpkcs7.h"
#include "sbmessages.h"
#include "sbpkicommon.h"
#include "sbocspcommon.h"
#include "sbocspclient.h"
#include "sbhttpsclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElHTTPOCSPClientHandle;

typedef TElHTTPOCSPClientHandle ElHTTPOCSPClientHandle;

typedef TElClassHandle TElHTTPOCSPClientFactoryHandle;

#ifdef SB_USE_CLASS_TELHTTPOCSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElHTTPOCSPClient_SupportsLocation(TElHTTPOCSPClientHandle _Handle, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPOCSPClient_PerformRequest(TElHTTPOCSPClientHandle _Handle, TElOCSPServerErrorRaw * ServerResult, uint8_t pReply[], int32_t * szReply, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPOCSPClient_get_HTTPClient(TElHTTPOCSPClientHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPOCSPClient_set_HTTPClient(TElHTTPOCSPClientHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPOCSPClient_Create(TComponentHandle Owner, TElOCSPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPOCSPCLIENT */

#ifdef SB_USE_CLASS_TELHTTPOCSPCLIENTFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElHTTPOCSPClientFactory_SupportsLocation(TElHTTPOCSPClientFactoryHandle _Handle, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPOCSPClientFactory_GetClientInstance(TElHTTPOCSPClientFactoryHandle _Handle, TObjectHandle Validator, TElOCSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPOCSPClientFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPOCSPCLIENTFACTORY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHTTPOCSPClient;
typedef TElHTTPOCSPClient ElHTTPOCSPClient;
class TElHTTPOCSPClientFactory;

#ifdef SB_USE_CLASS_TELHTTPOCSPCLIENT
class TElHTTPOCSPClient: public TElOCSPClient
{
	private:
		SB_DISABLE_COPY(TElHTTPOCSPClient)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		virtual bool SupportsLocation(const std::string &URI);

		virtual int32_t PerformRequest(TElOCSPServerError &ServerResult, std::vector<uint8_t> &Reply);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElHTTPOCSPClient, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		TElHTTPOCSPClient(TElHTTPOCSPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElHTTPOCSPClient(TComponent &Owner);

		explicit TElHTTPOCSPClient(TComponent *Owner);

		virtual ~TElHTTPOCSPClient();

};
#endif /* SB_USE_CLASS_TELHTTPOCSPCLIENT */

#ifdef SB_USE_CLASS_TELHTTPOCSPCLIENTFACTORY
class TElHTTPOCSPClientFactory: public TElCustomOCSPClientFactory
{
	private:
		SB_DISABLE_COPY(TElHTTPOCSPClientFactory)
	public:
		virtual bool SupportsLocation(const std::string &URI);

#ifdef SB_USE_CLASS_TELOCSPCLIENT
		virtual TElOCSPClientHandle GetClientInstance(TObject &Validator);

		virtual TElOCSPClientHandle GetClientInstance(TObject *Validator);
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

		TElHTTPOCSPClientFactory(TElHTTPOCSPClientFactoryHandle handle, TElOwnHandle ownHandle);

		TElHTTPOCSPClientFactory();

};
#endif /* SB_USE_CLASS_TELHTTPOCSPCLIENTFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_HTTPOCSPCLIENT

void RegisterHTTPOCSPClientFactory();

#endif /* SB_USE_GLOBAL_PROCS_HTTPOCSPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_HTTPOCSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY SBHTTPOCSPClient_RegisterHTTPOCSPClientFactory(void);
#endif /* SB_USE_GLOBAL_PROCS_HTTPOCSPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPOCSPCLIENT */

