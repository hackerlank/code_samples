#ifndef __INC_SBLDAPCERTRETRIEVER
#define __INC_SBLDAPCERTRETRIEVER

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
#include "sbldapscore.h"
#include "sbldapsclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElLDAPCertificateRetrieverHandle;

typedef TElLDAPCertificateRetrieverHandle ElLDAPCertificateRetrieverHandle;

typedef TElClassHandle TElLDAPCertificateRetrieverFactoryHandle;

#ifdef SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVER
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetriever_SupportsLocation(TElLDAPCertificateRetrieverHandle _Handle, TSBGeneralNameRaw NameType, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetriever_RetrieveCertificate(TElLDAPCertificateRetrieverHandle _Handle, TElX509CertificateHandle Certificate, TSBGeneralNameRaw NameType, const char * pcURL, int32_t szURL, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetriever_get_LDAPSClient(TElLDAPCertificateRetrieverHandle _Handle, TElLDAPSClientHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetriever_get_ServerList(TElLDAPCertificateRetrieverHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetriever_get_ServerList(TElLDAPCertificateRetrieverHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetriever_Create(TComponentHandle AOwner, TElLDAPCertificateRetrieverHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVERFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetrieverFactory_SupportsLocation(TElLDAPCertificateRetrieverFactoryHandle _Handle, TSBGeneralNameRaw NameType, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetrieverFactory_GetClientInstance(TElLDAPCertificateRetrieverFactoryHandle _Handle, TObjectHandle Validator, TElCustomCertificateRetrieverHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertificateRetrieverFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVERFACTORY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElLDAPCertificateRetriever;
typedef TElLDAPCertificateRetriever ElLDAPCertificateRetriever;
class TElLDAPCertificateRetrieverFactory;

#ifdef SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVER
class TElLDAPCertificateRetriever: public TElCustomCertificateRetriever
{
	private:
		SB_DISABLE_COPY(TElLDAPCertificateRetriever)
#ifdef SB_USE_CLASS_TELLDAPSCLIENT
		TElLDAPSClient* _Inst_LDAPSClient;
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ServerList;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ServerList;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual bool SupportsLocation(TSBGeneralName NameType, const std::string &URI);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509CertificateHandle RetrieveCertificate(TElX509Certificate &Certificate, TSBGeneralName NameType, const std::string &URL);

		virtual TElX509CertificateHandle RetrieveCertificate(TElX509Certificate *Certificate, TSBGeneralName NameType, const std::string &URL);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELLDAPSCLIENT
		virtual TElLDAPSClient* get_LDAPSClient();

		SB_DECLARE_PROPERTY_GET(TElLDAPSClient*, get_LDAPSClient, TElLDAPCertificateRetriever, LDAPSClient);
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ServerList();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ServerList, TElLDAPCertificateRetriever, ServerList);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ServerList();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_ServerList, TElLDAPCertificateRetriever, ServerList);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElLDAPCertificateRetriever(TElLDAPCertificateRetrieverHandle handle, TElOwnHandle ownHandle);

		explicit TElLDAPCertificateRetriever(TComponent &AOwner);

		explicit TElLDAPCertificateRetriever(TComponent *AOwner);

		virtual ~TElLDAPCertificateRetriever();

};
#endif /* SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVER */

#ifdef SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVERFACTORY
class TElLDAPCertificateRetrieverFactory: public TElCustomCertificateRetrieverFactory
{
	private:
		SB_DISABLE_COPY(TElLDAPCertificateRetrieverFactory)
	public:
		virtual bool SupportsLocation(TSBGeneralName NameType, const std::string &URI);

#ifdef SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER
		virtual TElCustomCertificateRetrieverHandle GetClientInstance(TObject &Validator);

		virtual TElCustomCertificateRetrieverHandle GetClientInstance(TObject *Validator);
#endif /* SB_USE_CLASS_TELCUSTOMCERTIFICATERETRIEVER */

		TElLDAPCertificateRetrieverFactory(TElLDAPCertificateRetrieverFactoryHandle handle, TElOwnHandle ownHandle);

		TElLDAPCertificateRetrieverFactory();

};
#endif /* SB_USE_CLASS_TELLDAPCERTIFICATERETRIEVERFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_LDAPCERTRETRIEVER

void RegisterLDAPCertificateRetrieverFactory();

#endif /* SB_USE_GLOBAL_PROCS_LDAPCERTRETRIEVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_LDAPCERTRETRIEVER
SB_IMPORT uint32_t SB_APIENTRY SBLDAPCertRetriever_RegisterLDAPCertificateRetrieverFactory(void);
#endif /* SB_USE_GLOBAL_PROCS_LDAPCERTRETRIEVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBLDAPCERTRETRIEVER */
