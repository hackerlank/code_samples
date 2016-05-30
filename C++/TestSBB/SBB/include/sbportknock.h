#ifndef __INC_SBPORTKNOCK
#define __INC_SBPORTKNOCK

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbhttpauth.h"
#include "sbstringlist.h"
#include "sbhttpsconstants.h"
#include "sbencoding.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssectypes.h"
#endif
#include "sbsocket.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPortKnockEntryHandle;

typedef TElClassHandle TElPortKnockHandle;

typedef TElPortKnockHandle ElPortKnockHandle;

#ifdef SB_USE_CLASS_TELPORTKNOCKENTRY
SB_IMPORT uint32_t SB_APIENTRY TElPortKnockEntry_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPORTKNOCKENTRY */

#ifdef SB_USE_CLASS_TELPORTKNOCK
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_Knock(TElPortKnockHandle _Handle, const char * pcConnectionAddress, int32_t szConnectionAddress, int8_t KnockToClose);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_UsingIPv6(TElPortKnockHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_InternalSocket(TElPortKnockHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_Address(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_Address(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_BeforeConnectRules(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_BeforeConnectRules(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_AfterDisconnectRules(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_AfterDisconnectRules(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_ProxyResult(TElPortKnockHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocksAuthentication(TElPortKnockHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocksAuthentication(TElPortKnockHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocksPassword(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocksPassword(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocksPort(TElPortKnockHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocksPort(TElPortKnockHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocksResolveAddress(TElPortKnockHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocksResolveAddress(TElPortKnockHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocksServer(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocksServer(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocksUserCode(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocksUserCode(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocksVersion(TElPortKnockHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocksVersion(TElPortKnockHandle _Handle, TElSocksVersionRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocksUseIPv6(TElPortKnockHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocksUseIPv6(TElPortKnockHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_UseIPv6(TElPortKnockHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_UseIPv6(TElPortKnockHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_UseSocks(TElPortKnockHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_UseSocks(TElPortKnockHandle _Handle, int8_t Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_DNS(TElPortKnockHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_DNS(TElPortKnockHandle _Handle, TElDNSSettingsHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_UseWebTunneling(TElPortKnockHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_UseWebTunneling(TElPortKnockHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelAddress(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_WebTunnelAddress(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelAuthentication(TElPortKnockHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_WebTunnelAuthentication(TElPortKnockHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelPassword(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_WebTunnelPassword(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelPort(TElPortKnockHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_WebTunnelPort(TElPortKnockHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelUserId(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_WebTunnelUserId(TElPortKnockHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelRequestHeaders(TElPortKnockHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelResponseHeaders(TElPortKnockHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelRequestHeaders(TElPortKnockHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelResponseHeaders(TElPortKnockHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_WebTunnelResponseBody(TElPortKnockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_SocketBinding(TElPortKnockHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_SocketBinding(TElPortKnockHandle _Handle, TElClientSocketBindingHandle Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_OnDNSKeyNeeded(TElPortKnockHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_OnDNSKeyNeeded(TElPortKnockHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_OnDNSKeyValidate(TElPortKnockHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_OnDNSKeyValidate(TElPortKnockHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_get_OnDNSResolve(TElPortKnockHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_set_OnDNSResolve(TElPortKnockHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPortKnock_Create(TComponentHandle AOwner, TElPortKnockHandle * OutResult);
#endif /* SB_USE_CLASS_TELPORTKNOCK */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPortKnockEntry;
class TElPortKnock;
typedef TElPortKnock ElPortKnock;

#ifdef SB_USE_CLASS_TELPORTKNOCKENTRY
class TElPortKnockEntry: public TObject
{
	private:
		SB_DISABLE_COPY(TElPortKnockEntry)
	public:
		TElPortKnockEntry(TElPortKnockEntryHandle handle, TElOwnHandle ownHandle);

		TElPortKnockEntry();

};
#endif /* SB_USE_CLASS_TELPORTKNOCKENTRY */

#ifdef SB_USE_CLASS_TELPORTKNOCK
class TElPortKnock: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPortKnock)
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_InternalSocket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		TElDNSSettings* _Inst_DNS;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_WebTunnelRequestHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_WebTunnelResponseHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_WebTunnelRequestHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_WebTunnelResponseHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_SocketBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		void initInstances();

	public:
		void Knock(const std::string &ConnectionAddress, bool KnockToClose);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElPortKnock, UsingIPv6);
#endif

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_InternalSocket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_InternalSocket, TElPortKnock, InternalSocket);
#endif /* SB_USE_CLASS_TELSOCKET */

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual void get_BeforeConnectRules(std::string &OutResult);

		virtual void set_BeforeConnectRules(const std::string &Value);

		virtual void get_AfterDisconnectRules(std::string &OutResult);

		virtual void set_AfterDisconnectRules(const std::string &Value);

		virtual int32_t get_ProxyResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ProxyResult, TElPortKnock, ProxyResult);

		virtual TElSocksAuthentication get_SocksAuthentication();

		virtual void set_SocksAuthentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_SocksAuthentication, set_SocksAuthentication, TElPortKnock, SocksAuthentication);

		virtual void get_SocksPassword(std::string &OutResult);

		virtual void set_SocksPassword(const std::string &Value);

		virtual int32_t get_SocksPort();

		virtual void set_SocksPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocksPort, set_SocksPort, TElPortKnock, SocksPort);

		virtual bool get_SocksResolveAddress();

		virtual void set_SocksResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksResolveAddress, set_SocksResolveAddress, TElPortKnock, SocksResolveAddress);

		virtual void get_SocksServer(std::string &OutResult);

		virtual void set_SocksServer(const std::string &Value);

		virtual void get_SocksUserCode(std::string &OutResult);

		virtual void set_SocksUserCode(const std::string &Value);

		virtual TElSocksVersion get_SocksVersion();

		virtual void set_SocksVersion(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_SocksVersion, set_SocksVersion, TElPortKnock, SocksVersion);

#ifdef SB_WINDOWS
		virtual bool get_SocksUseIPv6();

		virtual void set_SocksUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksUseIPv6, set_SocksUseIPv6, TElPortKnock, SocksUseIPv6);

		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElPortKnock, UseIPv6);
#endif

		virtual bool get_UseSocks();

		virtual void set_UseSocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSocks, set_UseSocks, TElPortKnock, UseSocks);

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElPortKnock, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

		virtual bool get_UseWebTunneling();

		virtual void set_UseWebTunneling(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseWebTunneling, set_UseWebTunneling, TElPortKnock, UseWebTunneling);

		virtual void get_WebTunnelAddress(std::string &OutResult);

		virtual void set_WebTunnelAddress(const std::string &Value);

		virtual TElWebTunnelAuthentication get_WebTunnelAuthentication();

		virtual void set_WebTunnelAuthentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_WebTunnelAuthentication, set_WebTunnelAuthentication, TElPortKnock, WebTunnelAuthentication);

		virtual void get_WebTunnelPassword(std::string &OutResult);

		virtual void set_WebTunnelPassword(const std::string &Value);

		virtual int32_t get_WebTunnelPort();

		virtual void set_WebTunnelPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_WebTunnelPort, set_WebTunnelPort, TElPortKnock, WebTunnelPort);

		virtual void get_WebTunnelUserId(std::string &OutResult);

		virtual void set_WebTunnelUserId(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelRequestHeaders, TElPortKnock, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelRequestHeaders, TElPortKnock, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelResponseHeaders, TElPortKnock, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelResponseHeaders, TElPortKnock, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_WebTunnelResponseBody(std::string &OutResult);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_SocketBinding();

		virtual void set_SocketBinding(TElClientSocketBinding &Value);

		virtual void set_SocketBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_SocketBinding, set_SocketBinding, TElPortKnock, SocketBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElPortKnock(TElPortKnockHandle handle, TElOwnHandle ownHandle);

		explicit TElPortKnock(TComponent &AOwner);

		explicit TElPortKnock(TComponent *AOwner);

		virtual ~TElPortKnock();

};
#endif /* SB_USE_CLASS_TELPORTKNOCK */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPORTKNOCK */
