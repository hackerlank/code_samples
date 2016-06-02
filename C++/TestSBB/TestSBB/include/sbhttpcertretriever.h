#ifndef __INC_SBHTTPCERTRETRIEVER
#define __INC_SBHTTPCERTRETRIEVER

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
#include "sbcertretriever.h"
#include "sbhttpsclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElHTTPCertificateRetrieverHandle;

typedef TElHTTPCertificateRetrieverHandle ElHTTPCertificateRetrieverHandle;

typedef TElClassHandle TElHTTPCertificateRetrieverFactoryHandle;

#ifdef SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVER
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCertificateRetriever_SupportsLocation(TElHTTPCertificateRetrieverHandle _Handle, TSBGeneralNameRaw NameType, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCertificateRetriever_RetrieveCertificate(TElHTTPCertificateRetrieverHandle _Handle, TElX509CertificateHandle Certificate, TSBGeneralNameRaw NameType, const char * pcURL, int32_t szURL, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCertificateRetriever_get_HTTPClient(TElHTTPCertificateRetrieverHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCertificateRetriever_set_HTTPClient(TElHTTPCertificateRetrieverHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCertificateRetriever_Create(TComponentHandle Owner, TElCustomCertificateRetrieverHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVERFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCertificateRetrieverFactory_SupportsLocation(TElHTTPCertificateRetrieverFactoryHandle _Handle, TSBGeneralNameRaw NameType, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCertificateRetrieverFactory_GetClientInstance(TElHTTPCertificateRetrieverFactoryHandle _Handle, TObjectHandle Validator, TElCustomCertificateRetrieverHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCertificateRetrieverFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVERFACTORY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHTTPCertificateRetriever;
typedef TElHTTPCertificateRetriever ElHTTPCertificateRetriever;
class TElHTTPCertificateRetrieverFactory;

#ifdef SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVER
class TElHTTPCertificateRetriever: public TElCustomCertificateRetriever
{
	private:
		SB_DISABLE_COPY(TElHTTPCertificateRetriever)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		virtual bool SupportsLocation(TSBGeneralName NameType, const std::string &URI);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509CertificateHandle RetrieveCertificate(TElX509Certificate &Certificate, TSBGeneralName NameType, const std::string &URL);

		virtual TElX509CertificateHandle RetrieveCertificate(TElX509Certificate *Certificate, TSBGeneralName NameType, const std::string &URL);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElHTTPCertificateRetriever, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		TElHTTPCertificateRetriever(TElHTTPCertificateRetrieverHandle handle, TElOwnHandle ownHandle);

		explicit TElHTTPCertificateRetriever(TComponent &Owner);

		explicit TElHTTPCertificateRetriever(TComponent *Owner);

		virtual ~TElHTTPCertificateRetriever();

};
#endif /* SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVERFACTORY
class TElHTTPCertificateRetrieverFactory: public TElCustomCertificateRetrieverFactory
{
	private:
		SB_DISABLE_COPY(TElHTTPCertificateRetrieverFactory)
	public:
		virtual bool SupportsLocation(TSBGeneralName NameType, const std::string &URI);

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
		virtual TElCustomCertificateRetrieverHandle GetClientInstance(TObject &Validator);

		virtual TElCustomCertificateRetrieverHandle GetClientInstance(TObject *Validator);
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

		TElHTTPCertificateRetrieverFactory(TElHTTPCertificateRetrieverFactoryHandle handle, TElOwnHandle ownHandle);

		TElHTTPCertificateRetrieverFactory();

};
#endif /* SB_USE_CLASS_TELHTTPCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_HTTPCERTRETRIEVER

void RegisterHTTPCertificateRetrieverFactory();

#endif /* SB_USE_GLOBAL_PROCS_HTTPCERTRETRIEVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_HTTPCERTRETRIEVER
SB_IMPORT uint32_t SB_APIENTRY SBHTTPCertRetriever_RegisterHTTPCertificateRetrieverFactory(void);
#endif /* SB_USE_GLOBAL_PROCS_HTTPCERTRETRIEVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPCERTRETRIEVER */

