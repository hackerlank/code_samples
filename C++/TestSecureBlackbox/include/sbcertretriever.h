#ifndef __INC_SBCERTRETRIEVER
#define __INC_SBCERTRETRIEVER

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
#include "sbx509.h"
#include "sbx509ext.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_CERT_RETRIEVER 	110592
#define SB_ERROR_CERT_RETRIEVER_ERROR_FLAG 	2048
#define SB_CERT_RETRIEVER_ERROR_NO_PARAMETERS 	112645
#define SB_CERT_RETRIEVER_ERROR_NO_REPLY 	112646

typedef TElClassHandle TElCustomCertificateRetrieverHandle;

typedef TElClassHandle TElFileCertificateRetrieverHandle;

typedef TElFileCertificateRetrieverHandle ElFileCertificateRetrieverHandle;

typedef TElClassHandle TElCustomCertificateRetrieverFactoryHandle;

typedef TElCustomCertificateRetrieverFactoryHandle ElCustomCertificateRetrieverFactoryHandle;

typedef TElClassHandle TElCertificateRetrieverManagerHandle;

typedef TElCertificateRetrieverManagerHandle ElCertRetrieverManagerHandle;

typedef void (SB_CALLBACK *TSBCertificateRetrievalEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle Certificate, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, TElX509CertificateHandle * CACertificate);

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertificateRetriever_SupportsLocation(TElCustomCertificateRetrieverHandle _Handle, TSBGeneralNameRaw NameType, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertificateRetriever_RetrieveCertificate(TElCustomCertificateRetrieverHandle _Handle, TElX509CertificateHandle Certificate, TSBGeneralNameRaw NameType, const char * pcURL, int32_t szURL, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertificateRetriever_Create(TComponentHandle Owner, TElCustomCertificateRetrieverHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELFILECERTIFICATERETRIEVER
SB_IMPORT uint32_t SB_APIENTRY TElFileCertificateRetriever_RetrieveCertificate(TElFileCertificateRetrieverHandle _Handle, TElX509CertificateHandle Certificate, TSBGeneralNameRaw NameType, const char * pcURL, int32_t szURL, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertificateRetriever_SupportsLocation(TElFileCertificateRetrieverHandle _Handle, TSBGeneralNameRaw NameType, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertificateRetriever_get_OnCertificateNeeded(TElFileCertificateRetrieverHandle _Handle, TSBCertificateRetrievalEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertificateRetriever_set_OnCertificateNeeded(TElFileCertificateRetrieverHandle _Handle, TSBCertificateRetrievalEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertificateRetriever_Create(TComponentHandle Owner, TElCustomCertificateRetrieverHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILECERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertificateRetrieverFactory_SupportsLocation(TElCustomCertificateRetrieverFactoryHandle _Handle, TSBGeneralNameRaw NameType, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertificateRetrieverFactory_GetClientInstance(TElCustomCertificateRetrieverFactoryHandle _Handle, TObjectHandle Validator, TElCustomCertificateRetrieverHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertificateRetrieverFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRetrieverManager_FindCertificateRetrieverByLocation(TElCertificateRetrieverManagerHandle _Handle, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, TObjectHandle Validator, TElCustomCertificateRetrieverHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRetrieverManager_RegisterCertificateRetrieverFactory(TElCertificateRetrieverManagerHandle _Handle, TElCustomCertificateRetrieverFactoryHandle Factory);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRetrieverManager_UnregisterCertificateRetrieverFactory(TElCertificateRetrieverManagerHandle _Handle, TElCustomCertificateRetrieverFactoryHandle Factory);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRetrieverManager_Create(TElCertificateRetrieverManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCustomCertificateRetriever;
class TElFileCertificateRetriever;
typedef TElFileCertificateRetriever ElFileCertificateRetriever;
class TElCustomCertificateRetrieverFactory;
typedef TElCustomCertificateRetrieverFactory ElCustomCertificateRetrieverFactory;
class TElCertificateRetrieverManager;
typedef TElCertificateRetrieverManager ElCertRetrieverManager;

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
class TElCustomCertificateRetriever: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCustomCertificateRetriever)
	public:
		virtual bool SupportsLocation(TSBGeneralName NameType, const std::string &URI);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509CertificateHandle RetrieveCertificate(TElX509Certificate &Certificate, TSBGeneralName NameType, const std::string &URL);

		virtual TElX509CertificateHandle RetrieveCertificate(TElX509Certificate *Certificate, TSBGeneralName NameType, const std::string &URL);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		TElCustomCertificateRetriever(TElCustomCertificateRetrieverHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomCertificateRetriever(TComponent &Owner);

		explicit TElCustomCertificateRetriever(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELFILECERTIFICATERETRIEVER
class TElFileCertificateRetriever: public TElCustomCertificateRetriever
{
	private:
		SB_DISABLE_COPY(TElFileCertificateRetriever)
	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509CertificateHandle RetrieveCertificate(TElX509Certificate &Certificate, TSBGeneralName NameType, const std::string &URL);

		virtual TElX509CertificateHandle RetrieveCertificate(TElX509Certificate *Certificate, TSBGeneralName NameType, const std::string &URL);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual bool SupportsLocation(TSBGeneralName NameType, const std::string &URI);

		virtual void get_OnCertificateNeeded(TSBCertificateRetrievalEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeeded(TSBCertificateRetrievalEvent pMethodValue, void * pDataValue);

		TElFileCertificateRetriever(TElFileCertificateRetrieverHandle handle, TElOwnHandle ownHandle);

		explicit TElFileCertificateRetriever(TComponent &Owner);

		explicit TElFileCertificateRetriever(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELFILECERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY
class TElCustomCertificateRetrieverFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomCertificateRetrieverFactory)
	public:
		virtual bool SupportsLocation(TSBGeneralName NameType, const std::string &URI);

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
		virtual TElCustomCertificateRetrieverHandle GetClientInstance(TObject &Validator);

		virtual TElCustomCertificateRetrieverHandle GetClientInstance(TObject *Validator);
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

		TElCustomCertificateRetrieverFactory(TElCustomCertificateRetrieverFactoryHandle handle, TElOwnHandle ownHandle);

		TElCustomCertificateRetrieverFactory();

};
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER
class TElCertificateRetrieverManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElCertificateRetrieverManager)
	public:
#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
		TElCustomCertificateRetrieverHandle FindCertificateRetrieverByLocation(TSBGeneralName NameType, const std::string &Location, TObject &Validator);

		TElCustomCertificateRetrieverHandle FindCertificateRetrieverByLocation(TSBGeneralName NameType, const std::string &Location, TObject *Validator);
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY
		void RegisterCertificateRetrieverFactory(TElCustomCertificateRetrieverFactory &Factory);

		void RegisterCertificateRetrieverFactory(TElCustomCertificateRetrieverFactory *Factory);
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY
		void UnregisterCertificateRetrieverFactory(TElCustomCertificateRetrieverFactory &Factory);

		void UnregisterCertificateRetrieverFactory(TElCustomCertificateRetrieverFactory *Factory);
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVERFACTORY */

		TElCertificateRetrieverManager(TElCertificateRetrieverManagerHandle handle, TElOwnHandle ownHandle);

		TElCertificateRetrieverManager();

};
#endif /* SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_CERTRETRIEVER

#ifdef SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER
TElCertificateRetrieverManagerHandle CertificateRetrieverManagerAddRef();
#endif /* SB_USE_CLASS_TELCERTIFICATERETRIEVERMANAGER */

void CertificateRetrieverManagerRelease();

#endif /* SB_USE_GLOBAL_PROCS_CERTRETRIEVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CERTRETRIEVER
SB_IMPORT uint32_t SB_APIENTRY SBCertRetriever_CertificateRetrieverManagerAddRef(TElCertificateRetrieverManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCertRetriever_CertificateRetrieverManagerRelease(void);
#endif /* SB_USE_GLOBAL_PROCS_CERTRETRIEVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCERTRETRIEVER */

