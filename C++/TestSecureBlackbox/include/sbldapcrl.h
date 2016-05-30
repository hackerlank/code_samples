#ifndef __INC_SBLDAPCRL
#define __INC_SBLDAPCRL

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbcrl.h"
#include "sbcrlstorage.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbldapscore.h"
#include "sbldapsclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElLDAPCRLRetrieverHandle;

typedef TElClassHandle TElLDAPCRLRetrieverFactoryHandle;

#ifdef SB_USE_CLASS_TELLDAPCRLRETRIEVER
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetriever_Supports(TElLDAPCRLRetrieverHandle _Handle, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetriever_GetCRL(TElLDAPCRLRetrieverHandle _Handle, TElX509CertificateHandle Certificate, TElX509CertificateHandle CACertificate, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, TElCertificateRevocationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetriever_get_LDAPSClient(TElLDAPCRLRetrieverHandle _Handle, TElLDAPSClientHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetriever_get_ServerList(TElLDAPCRLRetrieverHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetriever_set_ServerList(TElLDAPCRLRetrieverHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetriever_get_ServerList(TElLDAPCRLRetrieverHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetriever_set_ServerList(TElLDAPCRLRetrieverHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetriever_Create(TComponentHandle AOwner, TElLDAPCRLRetrieverHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELLDAPCRLRETRIEVERFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetrieverFactory_Supports(TElLDAPCRLRetrieverFactoryHandle _Handle, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetrieverFactory_GetRetrieverInstance(TElLDAPCRLRetrieverFactoryHandle _Handle, TObjectHandle Validator, TElCustomCRLRetrieverHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCRLRetrieverFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPCRLRETRIEVERFACTORY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElLDAPCRLRetriever;
class TElLDAPCRLRetrieverFactory;

#ifdef SB_USE_CLASS_TELLDAPCRLRETRIEVER
class TElLDAPCRLRetriever: public TElCustomCRLRetriever
{
	private:
		SB_DISABLE_COPY(TElLDAPCRLRetriever)
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
		virtual bool Supports(TSBGeneralName NameType, const std::string &Location);

#ifdef SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE
		virtual TElCertificateRevocationListHandle GetCRL(TElX509Certificate &Certificate, TElX509Certificate &CACertificate, TSBGeneralName NameType, const std::string &Location);

		virtual TElCertificateRevocationListHandle GetCRL(TElX509Certificate *Certificate, TElX509Certificate *CACertificate, TSBGeneralName NameType, const std::string &Location);
#endif /* SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELLDAPSCLIENT
		virtual TElLDAPSClient* get_LDAPSClient();

		SB_DECLARE_PROPERTY_GET(TElLDAPSClient*, get_LDAPSClient, TElLDAPCRLRetriever, LDAPSClient);
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ServerList();

		virtual void set_ServerList(TStringList &Value);

		virtual void set_ServerList(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_ServerList, set_ServerList, TElLDAPCRLRetriever, ServerList);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ServerList();

		virtual void set_ServerList(TElStringList &Value);

		virtual void set_ServerList(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_ServerList, set_ServerList, TElLDAPCRLRetriever, ServerList);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElLDAPCRLRetriever(TElLDAPCRLRetrieverHandle handle, TElOwnHandle ownHandle);

		explicit TElLDAPCRLRetriever(TComponent &AOwner);

		explicit TElLDAPCRLRetriever(TComponent *AOwner);

		virtual ~TElLDAPCRLRetriever();

};
#endif /* SB_USE_CLASS_TELLDAPCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELLDAPCRLRETRIEVERFACTORY
class TElLDAPCRLRetrieverFactory: public TElCustomCRLRetrieverFactory
{
	private:
		SB_DISABLE_COPY(TElLDAPCRLRetrieverFactory)
	public:
		virtual bool Supports(TSBGeneralName NameType, const std::string &Location);

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
		virtual TElCustomCRLRetrieverHandle GetRetrieverInstance(TObject &Validator);

		virtual TElCustomCRLRetrieverHandle GetRetrieverInstance(TObject *Validator);
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

		TElLDAPCRLRetrieverFactory(TElLDAPCRLRetrieverFactoryHandle handle, TElOwnHandle ownHandle);

		TElLDAPCRLRetrieverFactory();

};
#endif /* SB_USE_CLASS_TELLDAPCRLRETRIEVERFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_LDAPCRL

void RegisterLDAPCRLRetrieverFactory();

#endif /* SB_USE_GLOBAL_PROCS_LDAPCRL */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_LDAPCRL
SB_IMPORT uint32_t SB_APIENTRY SBLDAPCRL_RegisterLDAPCRLRetrieverFactory(void);
#endif /* SB_USE_GLOBAL_PROCS_LDAPCRL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBLDAPCRL */
