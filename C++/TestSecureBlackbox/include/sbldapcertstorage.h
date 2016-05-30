#ifndef __INC_SBLDAPCERTSTORAGE
#define __INC_SBLDAPCERTSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcustomcertstorage.h"
#include "sbstringlist.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbx509.h"
#include "sbldapscore.h"
#include "sbldapsclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SLDAPSClientNotAssigned 	"You must set LDAPSClient property first"

typedef TElClassHandle TElLDAPCertStorageHandle;

typedef TElLDAPCertStorageHandle ElLDAPCertStorageHandle;

#ifdef SB_USE_CLASS_TELLDAPCERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertStorage_Validate(TElLDAPCertStorageHandle _Handle, TElX509CertificateHandle Certificate, TSBCertificateValidityReasonRaw * Reason, int8_t CheckCACertDates, int64_t ValidityMoment, TSBCertificateValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertStorage_Add(TElLDAPCertStorageHandle _Handle, TElX509CertificateHandle X509Certificate, int8_t CopyPrivateKey);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertStorage_Remove(TElLDAPCertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertStorage_get_LDAPSClient(TElLDAPCertStorageHandle _Handle, TElLDAPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertStorage_set_LDAPSClient(TElLDAPCertStorageHandle _Handle, TElLDAPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPCertStorage_Create(TComponentHandle Owner, TElLDAPCertStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPCERTSTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElLDAPCertStorage;
typedef TElLDAPCertStorage ElLDAPCertStorage;

#ifdef SB_USE_CLASS_TELLDAPCERTSTORAGE
class TElLDAPCertStorage: public TElCustomCertStorage
{
	private:
		SB_DISABLE_COPY(TElLDAPCertStorage)
#ifdef SB_USE_CLASS_TELLDAPSCLIENT
		TElLDAPSClient* _Inst_LDAPSClient;
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TSBCertificateValidity Validate(TElX509Certificate &Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment);

		virtual TSBCertificateValidity Validate(TElX509Certificate *Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual void Add(TElX509Certificate &X509Certificate, bool CopyPrivateKey);

		virtual void Add(TElX509Certificate *X509Certificate, bool CopyPrivateKey);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TELLDAPSCLIENT
		virtual TElLDAPSClient* get_LDAPSClient();

		virtual void set_LDAPSClient(TElLDAPSClient &Value);

		virtual void set_LDAPSClient(TElLDAPSClient *Value);

		SB_DECLARE_PROPERTY(TElLDAPSClient*, get_LDAPSClient, set_LDAPSClient, TElLDAPCertStorage, LDAPSClient);
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

		TElLDAPCertStorage(TElLDAPCertStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElLDAPCertStorage(TComponent &Owner);

		explicit TElLDAPCertStorage(TComponent *Owner);

		virtual ~TElLDAPCertStorage();

};
#endif /* SB_USE_CLASS_TELLDAPCERTSTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBLDAPCERTSTORAGE */

