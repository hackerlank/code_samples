#ifndef __INC_SBLDAPSKEYSERVERCLIENT
#define __INC_SBLDAPSKEYSERVERCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbsslcommon.h"
#include "sbsimplessl.h"
#include "sbcustomcertstorage.h"
#include "sbsslconstants.h"
#include "sbstringlist.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbsocket.h"
#include "sbpgpkeys.h"
#include "sbpgpconstants.h"
#include "sbpgputils.h"
#include "sbsasl.h"
#include "sbldapscore.h"
#include "sbldapsclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SUnknownBaseKeyspaceDN 	"Can not get base keyspace DN"
#define SB_SWrongSearchParam 	"Wrong search parameter"
#define SB_SNoSearchConditions 	"Can not use search filter without conditions"
#define SB_LDAP_KEYSERVER_CLIENT_ERROR_BASE 	0
#define SB_LDAP_KEYSERVER_CLIENT_NO_BASE_DN 	1
#define SB_LDAP_KEYSERVER_WRONG_SEARCH_PARAM 	2
#define SB_LDAP_KEYSERVER_NO_SEARCH_CONDITIONS 	3

typedef TElClassHandle TElLDAPSKeyserverSearchFilterHandle;

typedef TElLDAPSKeyserverSearchFilterHandle ElLDAPSKeyserverSearchFilterHandle;

typedef TElClassHandle TElLDAPSKeyserverClientHandle;

typedef TElLDAPSKeyserverClientHandle ElLDAPSKeyserverClientHandle;

typedef uint8_t TSBLDAPSKeyserverAttributeRaw;

typedef enum
{
	lkaCertID = 0,
	lkaDisabled = 1,
	lkaKeyID = 2,
	lkaKeyType = 3,
	lkaUserID = 4,
	lkaKeyCreateTime = 5,
	lkaSignerID = 6,
	lkaRevoked = 7,
	lkaSubKeyID = 8,
	lkaSubKeyID32 = 9,
	lkaKeySize = 10,
	lkaKeyExpireTime = 11
} TSBLDAPSKeyserverAttribute;

typedef uint8_t TSBSearchRequestTypeRaw;

typedef enum
{
	srtEmail = 0,
	srtShortID = 1,
	srtLongID = 2
} TSBSearchRequestType;

#ifdef SB_USE_CLASS_TELLDAPSKEYSERVERSEARCHFILTER
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverSearchFilter_AddCondition(TElLDAPSKeyserverSearchFilterHandle _Handle, TSBLDAPSLogicalOperatorRaw LogicalOperator, TSBLDAPSKeyserverAttributeRaw Attribute, TSBLDAPSEqualityRaw Equality, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverSearchFilter_Create(TElLDAPSKeyserverSearchFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverSearchFilter_Create_1(TSBLDAPSLogicalOperatorRaw LogicalOperator, TSBLDAPSKeyserverAttributeRaw Attribute, TSBLDAPSEqualityRaw Equality, const char * pcValue, int32_t szValue, TElLDAPSKeyserverSearchFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSKEYSERVERSEARCHFILTER */

#ifdef SB_USE_CLASS_TELLDAPSKEYSERVERCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_Search(TElLDAPSKeyserverClientHandle _Handle, const char * pcID, int32_t szID, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_Search_1(TElLDAPSKeyserverClientHandle _Handle, TElPGPKeyringHandle * KeyRing, const char * pcID, int32_t szID);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_Search_2(TElLDAPSKeyserverClientHandle _Handle, const TElLDAPSKeyserverSearchFilterHandle Filter, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_Search_3(TElLDAPSKeyserverClientHandle _Handle, TElPGPKeyringHandle * KeyRing, const TElLDAPSKeyserverSearchFilterHandle Filter);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_Remove(TElLDAPSKeyserverClientHandle _Handle, const TElPGPPublicKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_Remove_1(TElLDAPSKeyserverClientHandle _Handle, const char * pcKeyID, int32_t szKeyID);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_Add(TElLDAPSKeyserverClientHandle _Handle, const TElPGPPublicKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_get_ServerSoftwareName(TElLDAPSKeyserverClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_get_ServerSoftwareVersion(TElLDAPSKeyserverClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_get_KeySearchRetryCount(TElLDAPSKeyserverClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_set_KeySearchRetryCount(TElLDAPSKeyserverClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_get_IncludeSubkeys(TElLDAPSKeyserverClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_set_IncludeSubkeys(TElLDAPSKeyserverClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_get_IncludeDisabledKeys(TElLDAPSKeyserverClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_set_IncludeDisabledKeys(TElLDAPSKeyserverClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_get_IncludeRevokedKeys(TElLDAPSKeyserverClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_set_IncludeRevokedKeys(TElLDAPSKeyserverClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSKeyserverClient_Create(TComponentHandle AOwner, TElLDAPSKeyserverClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSKEYSERVERCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElLDAPSKeyserverSearchFilter;
typedef TElLDAPSKeyserverSearchFilter ElLDAPSKeyserverSearchFilter;
class TElLDAPSKeyserverClient;
typedef TElLDAPSKeyserverClient ElLDAPSKeyserverClient;

#ifdef SB_USE_CLASS_TELLDAPSKEYSERVERSEARCHFILTER
class TElLDAPSKeyserverSearchFilter: public TElLDAPSSearchFilter
{
	private:
		SB_DISABLE_COPY(TElLDAPSKeyserverSearchFilter)
	public:
		void AddCondition(TSBLDAPSLogicalOperator LogicalOperator, TSBLDAPSKeyserverAttribute Attribute, TSBLDAPSEquality Equality, const std::string &Value);

		TElLDAPSKeyserverSearchFilter(TElLDAPSKeyserverSearchFilterHandle handle, TElOwnHandle ownHandle);

		TElLDAPSKeyserverSearchFilter();

		TElLDAPSKeyserverSearchFilter(TSBLDAPSLogicalOperator LogicalOperator, TSBLDAPSKeyserverAttribute Attribute, TSBLDAPSEquality Equality, const std::string &Value);

};
#endif /* SB_USE_CLASS_TELLDAPSKEYSERVERSEARCHFILTER */

#ifdef SB_USE_CLASS_TELLDAPSKEYSERVERCLIENT
class TElLDAPSKeyserverClient: public TElLDAPSClient
{
	private:
		SB_DISABLE_COPY(TElLDAPSKeyserverClient)
	public:
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyringHandle Search(const std::string &ID);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
		void Search(TElPGPKeyring &KeyRing, const std::string &ID);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASSES_TELLDAPSKEYSERVERSEARCHFILTER_AND_TELPGPKEYRING
		TElPGPKeyringHandle Search(const TElLDAPSKeyserverSearchFilter &Filter);

		TElPGPKeyringHandle Search(const TElLDAPSKeyserverSearchFilter *Filter);
#endif /* SB_USE_CLASSES_TELLDAPSKEYSERVERSEARCHFILTER_AND_TELPGPKEYRING */

#ifdef SB_USE_CLASSES_TELLDAPSKEYSERVERSEARCHFILTER_AND_TELPGPKEYRING
		void Search(TElPGPKeyring &KeyRing, const TElLDAPSKeyserverSearchFilter &Filter);

		void Search(TElPGPKeyring &KeyRing, const TElLDAPSKeyserverSearchFilter *Filter);
#endif /* SB_USE_CLASSES_TELLDAPSKEYSERVERSEARCHFILTER_AND_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		void Remove(const TElPGPPublicKey &Key);

		void Remove(const TElPGPPublicKey *Key);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

		void Remove(const std::string &KeyID);

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		void Add(const TElPGPPublicKey &Key);

		void Add(const TElPGPPublicKey *Key);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

		virtual void get_ServerSoftwareName(std::string &OutResult);

		virtual void get_ServerSoftwareVersion(std::string &OutResult);

		virtual int32_t get_KeySearchRetryCount();

		virtual void set_KeySearchRetryCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeySearchRetryCount, set_KeySearchRetryCount, TElLDAPSKeyserverClient, KeySearchRetryCount);

		virtual bool get_IncludeSubkeys();

		virtual void set_IncludeSubkeys(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeSubkeys, set_IncludeSubkeys, TElLDAPSKeyserverClient, IncludeSubkeys);

		virtual bool get_IncludeDisabledKeys();

		virtual void set_IncludeDisabledKeys(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeDisabledKeys, set_IncludeDisabledKeys, TElLDAPSKeyserverClient, IncludeDisabledKeys);

		virtual bool get_IncludeRevokedKeys();

		virtual void set_IncludeRevokedKeys(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeRevokedKeys, set_IncludeRevokedKeys, TElLDAPSKeyserverClient, IncludeRevokedKeys);

		TElLDAPSKeyserverClient(TElLDAPSKeyserverClientHandle handle, TElOwnHandle ownHandle);

		explicit TElLDAPSKeyserverClient(TComponent &AOwner);

		explicit TElLDAPSKeyserverClient(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELLDAPSKEYSERVERCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBLDAPSKEYSERVERCLIENT */

