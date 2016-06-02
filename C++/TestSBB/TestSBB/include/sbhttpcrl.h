#ifndef __INC_SBHTTPCRL
#define __INC_SBHTTPCRL

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbcrl.h"
#include "sbcrlstorage.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbhttpsclient.h"
#include "sbcertvalidator.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElHTTPCRLRetrieverHandle;

typedef TElClassHandle TElHTTPCRLRetrieverFactoryHandle;

#ifdef SB_USE_CLASS_TELHTTPCRLRETRIEVER
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCRLRetriever_Supports(TElHTTPCRLRetrieverHandle _Handle, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCRLRetriever_GetCRL(TElHTTPCRLRetrieverHandle _Handle, TElX509CertificateHandle Certificate, TElX509CertificateHandle CACertificate, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, TElCertificateRevocationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCRLRetriever_get_HTTPClient(TElHTTPCRLRetrieverHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCRLRetriever_Create(TComponentHandle AOwner, TElHTTPCRLRetrieverHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELHTTPCRLRETRIEVERFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCRLRetrieverFactory_Supports(TElHTTPCRLRetrieverFactoryHandle _Handle, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCRLRetrieverFactory_GetRetrieverInstance(TElHTTPCRLRetrieverFactoryHandle _Handle, TObjectHandle Validator, TElCustomCRLRetrieverHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCRLRetrieverFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPCRLRETRIEVERFACTORY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHTTPCRLRetriever;
class TElHTTPCRLRetrieverFactory;

#ifdef SB_USE_CLASS_TELHTTPCRLRETRIEVER
class TElHTTPCRLRetriever: public TElCustomCRLRetriever
{
	private:
		SB_DISABLE_COPY(TElHTTPCRLRetriever)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		virtual bool Supports(TSBGeneralName NameType, const std::string &Location);

#ifdef SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE
		virtual TElCertificateRevocationListHandle GetCRL(TElX509Certificate &Certificate, TElX509Certificate &CACertificate, TSBGeneralName NameType, const std::string &Location);

		virtual TElCertificateRevocationListHandle GetCRL(TElX509Certificate *Certificate, TElX509Certificate *CACertificate, TSBGeneralName NameType, const std::string &Location);
#endif /* SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		SB_DECLARE_PROPERTY_GET(TElHTTPSClient*, get_HTTPClient, TElHTTPCRLRetriever, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		TElHTTPCRLRetriever(TElHTTPCRLRetrieverHandle handle, TElOwnHandle ownHandle);

		explicit TElHTTPCRLRetriever(TComponent &AOwner);

		explicit TElHTTPCRLRetriever(TComponent *AOwner);

		virtual ~TElHTTPCRLRetriever();

};
#endif /* SB_USE_CLASS_TELHTTPCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELHTTPCRLRETRIEVERFACTORY
class TElHTTPCRLRetrieverFactory: public TElCustomCRLRetrieverFactory
{
	private:
		SB_DISABLE_COPY(TElHTTPCRLRetrieverFactory)
	public:
		virtual bool Supports(TSBGeneralName NameType, const std::string &Location);

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
		virtual TElCustomCRLRetrieverHandle GetRetrieverInstance(TObject &Validator);

		virtual TElCustomCRLRetrieverHandle GetRetrieverInstance(TObject *Validator);
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

		TElHTTPCRLRetrieverFactory(TElHTTPCRLRetrieverFactoryHandle handle, TElOwnHandle ownHandle);

		TElHTTPCRLRetrieverFactory();

};
#endif /* SB_USE_CLASS_TELHTTPCRLRETRIEVERFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_HTTPCRL

void RegisterHTTPCRLRetrieverFactory();

#endif /* SB_USE_GLOBAL_PROCS_HTTPCRL */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_HTTPCRL
SB_IMPORT uint32_t SB_APIENTRY SBHTTPCRL_RegisterHTTPCRLRetrieverFactory(void);
#endif /* SB_USE_GLOBAL_PROCS_HTTPCRL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPCRL */

