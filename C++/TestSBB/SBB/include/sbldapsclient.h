#ifndef __INC_SBLDAPSCLIENT
#define __INC_SBLDAPSCLIENT

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
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbstringlist.h"
#include "sbencoding.h"
#include "sbsocket.h"
#include "sbsasl.h"
#include "sbldapscore.h"
#include "sbx509.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_LDAP_PORT 	389

typedef TElClassHandle TElLDAPSSearchFilterHandle;

typedef TElLDAPSSearchFilterHandle ElLDAPSSearchFilterHandle;

typedef TElClassHandle TElLDAPResponseHandle;

typedef TElLDAPResponseHandle ElLDAPResponseHandle;

typedef TElClassHandle TElLDAPURLHandle;

typedef TElLDAPURLHandle ElLDAPURLHandle;

typedef TElClassHandle TElLDAPSClientHandle;

typedef TElLDAPSClientHandle ElLDAPSClientHandle;

typedef uint8_t TSBLDAPAuthenticationTypeRaw;

typedef enum
{
	autSimple = 0,
	autSASL = 1
} TSBLDAPAuthenticationType;

typedef uint8_t TSBLDAPSEqualityRaw;

typedef enum
{
	leEqual = 0,
	leNotEqual = 1,
	leAny = 2,
	leContains = 3,
	leDoesNotContain = 4,
	leLessOrEqual = 5,
	leGreaterOrEqual = 6,
	leApproximately = 7
} TSBLDAPSEquality;

typedef uint8_t TSBLDAPSLogicalOperatorRaw;

typedef enum
{
	loAnd = 0,
	loOr = 1
} TSBLDAPSLogicalOperator;

#ifdef SB_USE_CLASS_TELLDAPSSEARCHFILTER
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSSearchFilter_ToString(TElLDAPSSearchFilterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSSearchFilter_AddCondition(TElLDAPSSearchFilterHandle _Handle, TSBLDAPSLogicalOperatorRaw LogicalOperator, const char * pcAttribute, int32_t szAttribute, TSBLDAPSEqualityRaw Equality, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSSearchFilter_get_IsEmpty(TElLDAPSSearchFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSSearchFilter_Create(TElLDAPSSearchFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSSearchFilter_Create_1(TSBLDAPSLogicalOperatorRaw LogicalOperator, const char * pcAttribute, int32_t szAttribute, TSBLDAPSEqualityRaw Equality, const char * pcValue, int32_t szValue, TElLDAPSSearchFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSSEARCHFILTER */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResponse_Add(TElLDAPResponseHandle _Handle, TElLDAPMessageHandle * Msg);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResponse_Remove(TElLDAPResponseHandle _Handle, TElLDAPMessageHandle * Msg);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResponse_get_Messages(TElLDAPResponseHandle _Handle, int32_t Index, TElLDAPMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResponse_get_Count(TElLDAPResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResponse_Create(TElLDAPResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

#ifdef SB_USE_CLASS_TELLDAPURL
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_URL(TElLDAPURLHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_Host(TElLDAPURLHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_Port(TElLDAPURLHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_DN(TElLDAPURLHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_Attributes(TElLDAPURLHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_Attributes(TElLDAPURLHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_Scope(TElLDAPURLHandle _Handle, TSBLDAPScopeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_Filter(TElLDAPURLHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_get_Extensions(TElLDAPURLHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPURL_Create(const char * pcURL, int32_t szURL, TElLDAPURLHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPURL */

#ifdef SB_USE_CLASS_TELLDAPSCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Bind(TElLDAPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Unbind(TElLDAPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Search(TElLDAPSClientHandle _Handle, const char * pcBaseDN, int32_t szBaseDN, TSBLDAPScopeRaw Scope, const char * pcFilter, int32_t szFilter, const TStringListHandle Attrs, int8_t AttrsOnly, TElLDAPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Search_1(TElLDAPSClientHandle _Handle, const char * pcBaseDN, int32_t szBaseDN, TSBLDAPScopeRaw Scope, const TElLDAPSSearchFilterHandle Filter, const TStringListHandle Attrs, int8_t AttrsOnly, TElLDAPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Search_2(TElLDAPSClientHandle _Handle, TElLDAPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_SearchURL(const char * pcURL, int32_t szURL, TElLDAPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_SearchURL_1(TElLDAPSClientHandle _Handle, const char * pcURL, int32_t szURL, TElLDAPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Remove(TElLDAPSClientHandle _Handle, const char * pcDN, int32_t szDN);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Add(TElLDAPSClientHandle _Handle, const char * pcDN, int32_t szDN, const TElLDAPPartialAttributeHandle pAttrs[], int32_t szAttrs);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Modify(TElLDAPSClientHandle _Handle, const char * pcDN, int32_t szDN, const TElLDAPPartialAttributeHandle pAttrs[], int32_t szAttrs);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_ReceiveTimeout(TElLDAPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_ReceiveTimeout(TElLDAPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_LDAPDN(TElLDAPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_LDAPDN(TElLDAPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_Password(TElLDAPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_Password(TElLDAPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_AuthType(TElLDAPSClientHandle _Handle, TSBLDAPAuthenticationTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_AuthType(TElLDAPSClientHandle _Handle, TSBLDAPAuthenticationTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_SASLMechanism(TElLDAPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_SASLMechanism(TElLDAPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_BaseDN(TElLDAPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_BaseDN(TElLDAPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_Scope(TElLDAPSClientHandle _Handle, TSBLDAPScopeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_Scope(TElLDAPSClientHandle _Handle, TSBLDAPScopeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_Filter(TElLDAPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_Filter(TElLDAPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_Attributes(TElLDAPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_Attributes(TElLDAPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_get_AttributesOnly(TElLDAPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_set_AttributesOnly(TElLDAPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSClient_Create(TComponentHandle AOwner, TElLDAPSClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElLDAPSSearchFilter;
typedef TElLDAPSSearchFilter ElLDAPSSearchFilter;
class TElLDAPResponse;
typedef TElLDAPResponse ElLDAPResponse;
class TElLDAPURL;
typedef TElLDAPURL ElLDAPURL;
class TElLDAPSClient;
typedef TElLDAPSClient ElLDAPSClient;

#ifdef SB_USE_CLASS_TELLDAPSSEARCHFILTER
class TElLDAPSSearchFilter: public TObject
{
	private:
		SB_DISABLE_COPY(TElLDAPSSearchFilter)
	public:
		void ToString(std::string &OutResult);

		void AddCondition(TSBLDAPSLogicalOperator LogicalOperator, const std::string &Attribute, TSBLDAPSEquality Equality, const std::string &Value);

		virtual bool get_IsEmpty();

		SB_DECLARE_PROPERTY_GET(bool, get_IsEmpty, TElLDAPSSearchFilter, IsEmpty);

		TElLDAPSSearchFilter(TElLDAPSSearchFilterHandle handle, TElOwnHandle ownHandle);

		TElLDAPSSearchFilter();

		TElLDAPSSearchFilter(TSBLDAPSLogicalOperator LogicalOperator, const std::string &Attribute, TSBLDAPSEquality Equality, const std::string &Value);

};
#endif /* SB_USE_CLASS_TELLDAPSSEARCHFILTER */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE
class TElLDAPResponse: public TObject
{
	private:
		SB_DISABLE_COPY(TElLDAPResponse)
#ifdef SB_USE_CLASS_TELLDAPMESSAGE
		TElLDAPMessage* _Inst_Messages;
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELLDAPMESSAGE
		void Add(TElLDAPMessage &Msg);
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPMESSAGE
		void Remove(TElLDAPMessage &Msg);
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPMESSAGE
		virtual TElLDAPMessage* get_Messages(int32_t Index);
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElLDAPResponse, Count);

		TElLDAPResponse(TElLDAPResponseHandle handle, TElOwnHandle ownHandle);

		TElLDAPResponse();

		virtual ~TElLDAPResponse();

};
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

#ifdef SB_USE_CLASS_TELLDAPURL
class TElLDAPURL: public TObject
{
	private:
		SB_DISABLE_COPY(TElLDAPURL)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Attributes;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void get_URL(std::string &OutResult);

		virtual void get_Host(std::string &OutResult);

		virtual uint16_t get_Port();

		SB_DECLARE_PROPERTY_GET(uint16_t, get_Port, TElLDAPURL, Port);

		virtual void get_DN(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Attributes, TElLDAPURL, Attributes);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Attributes, TElLDAPURL, Attributes);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TSBLDAPScope get_Scope();

		SB_DECLARE_PROPERTY_GET(TSBLDAPScope, get_Scope, TElLDAPURL, Scope);

		virtual void get_Filter(std::string &OutResult);

		virtual void get_Extensions(std::string &OutResult);

		TElLDAPURL(TElLDAPURLHandle handle, TElOwnHandle ownHandle);

		explicit TElLDAPURL(const std::string &URL);

		virtual ~TElLDAPURL();

};
#endif /* SB_USE_CLASS_TELLDAPURL */

#ifdef SB_USE_CLASS_TELLDAPSCLIENT
class TElLDAPSClient: public TElSimpleSSLClient
{
	private:
		SB_DISABLE_COPY(TElLDAPSClient)
	public:
		void Bind();

		void Unbind();

#ifdef SB_USE_CLASSES_TELLDAPRESPONSE_AND_TSTRINGLIST
		virtual TElLDAPResponseHandle Search(const std::string &BaseDN, TSBLDAPScope Scope, const std::string &Filter, const TStringList &Attrs, bool AttrsOnly);
#endif /* SB_USE_CLASSES_TELLDAPRESPONSE_AND_TSTRINGLIST */

#ifdef SB_USE_CLASSES_TELLDAPRESPONSE_AND_TELLDAPSSEARCHFILTER_AND_TSTRINGLIST
		virtual TElLDAPResponseHandle Search(const std::string &BaseDN, TSBLDAPScope Scope, const TElLDAPSSearchFilter &Filter, const TStringList &Attrs, bool AttrsOnly);

		virtual TElLDAPResponseHandle Search(const std::string &BaseDN, TSBLDAPScope Scope, const TElLDAPSSearchFilter *Filter, const TStringList &Attrs, bool AttrsOnly);
#endif /* SB_USE_CLASSES_TELLDAPRESPONSE_AND_TELLDAPSSEARCHFILTER_AND_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE
		virtual TElLDAPResponseHandle Search();
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE
		static TElLDAPResponseHandle SearchURL(const std::string &URL);
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

#ifdef SB_USE_CLASS_TELLDAPRESPONSE
		TElLDAPResponseHandle SearchURL_Inst(const std::string &URL);
#endif /* SB_USE_CLASS_TELLDAPRESPONSE */

		void Remove(const std::string &DN);

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
		void Add(const std::string &DN, const std::vector<TElLDAPPartialAttributeHandle> &Attrs);
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
		virtual void Modify(const std::string &DN, const std::vector<TElLDAPPartialAttributeHandle> &Attrs);
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

		virtual int32_t get_ReceiveTimeout();

		virtual void set_ReceiveTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ReceiveTimeout, set_ReceiveTimeout, TElLDAPSClient, ReceiveTimeout);

		virtual void get_LDAPDN(std::string &OutResult);

		virtual void set_LDAPDN(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual TSBLDAPAuthenticationType get_AuthType();

		virtual void set_AuthType(TSBLDAPAuthenticationType Value);

		SB_DECLARE_PROPERTY(TSBLDAPAuthenticationType, get_AuthType, set_AuthType, TElLDAPSClient, AuthType);

		virtual void get_SASLMechanism(std::string &OutResult);

		virtual void set_SASLMechanism(const std::string &Value);

		virtual void get_BaseDN(std::string &OutResult);

		virtual void set_BaseDN(const std::string &Value);

		virtual TSBLDAPScope get_Scope();

		virtual void set_Scope(TSBLDAPScope Value);

		SB_DECLARE_PROPERTY(TSBLDAPScope, get_Scope, set_Scope, TElLDAPSClient, Scope);

		virtual void get_Filter(std::string &OutResult);

		virtual void set_Filter(const std::string &Value);

		virtual void get_Attributes(std::string &OutResult);

		virtual void set_Attributes(const std::string &Value);

		virtual bool get_AttributesOnly();

		virtual void set_AttributesOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AttributesOnly, set_AttributesOnly, TElLDAPSClient, AttributesOnly);

		TElLDAPSClient(TElLDAPSClientHandle handle, TElOwnHandle ownHandle);

		explicit TElLDAPSClient(TComponent &AOwner);

		explicit TElLDAPSClient(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELLDAPSCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBLDAPSCLIENT */
