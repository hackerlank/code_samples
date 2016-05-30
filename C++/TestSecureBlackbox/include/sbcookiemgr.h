#ifndef __INC_SBCOOKIEMGR
#define __INC_SBCOOKIEMGR

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbxmlcore.h"
#include "sbsharedresource.h"
#include "sbhttpsconstants.h"
#include "sbhttpscommon.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_cpComment 	1
#define SB_cpCommentURL 	2
#define SB_cpExpires 	4
#define SB_cpDiscard 	8
#define SB_cpDomain 	16
#define SB_cpPath 	32
#define SB_cpPort 	64
#define SB_cpSecure 	128
#define SB_cpVersion 	256
#define SB_cpHostOnly 	512
#define SB_cpHttpOnly 	1024
#define SB_cpFormat 	2048
#define SB_cfUndefined 	0
#define SB_cfNetscape 	1
#define SB_cfRFC2109 	2
#define SB_cfRFC2965 	3
#define SB_cfRFC6265 	4

typedef TElClassHandle TElCookieHandle;

typedef TElClassHandle TElCookieDomainHandle;

typedef TElClassHandle TElCookieManagerHandle;

typedef TElCookieManagerHandle ElCookieManagerHandle;

#ifdef SB_USE_CLASS_TELCOOKIE
SB_IMPORT uint32_t SB_APIENTRY TElCookie_AssembleClientCookie(TElCookieHandle _Handle, int32_t Format, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_ParseServerCookie(TElCookieHandle _Handle, const char * pcACookie, int32_t szACookie, int64_t ReceivedAt, int8_t * DiscardCookie);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Included(TElCookieHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Persistent(TElCookieHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Persistent(TElCookieHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Name(TElCookieHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Name(TElCookieHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Value(TElCookieHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Value(TElCookieHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Comment(TElCookieHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Comment(TElCookieHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_CommentURL(TElCookieHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_CommentURL(TElCookieHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Domain(TElCookieHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Domain(TElCookieHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Expires(TElCookieHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Expires(TElCookieHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Format(TElCookieHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Format(TElCookieHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_HostOnly(TElCookieHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_HostOnly(TElCookieHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_HTTPOnly(TElCookieHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_HTTPOnly(TElCookieHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Path(TElCookieHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Path(TElCookieHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Port(TElCookieHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Port(TElCookieHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Secure(TElCookieHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Secure(TElCookieHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_get_Version(TElCookieHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_set_Version(TElCookieHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCookie_Create(TElCookieHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOOKIE */

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_AddCookie(TElCookieDomainHandle _Handle, TElCookieHandle ACookie);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_Clear(TElCookieDomainHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_RemoveCookie(TElCookieDomainHandle _Handle, TElCookieHandle ACookie);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_DeleteCookie(TElCookieDomainHandle _Handle, int32_t index);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_FindSameCookie(TElCookieDomainHandle _Handle, TElCookieHandle Cookie, TElCookieHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_get_Cookies(TElCookieDomainHandle _Handle, int32_t Index, TElCookieHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_get_CookieCount(TElCookieDomainHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_get_Domain(TElCookieDomainHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_set_Domain(TElCookieDomainHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCookieDomain_Create(TElCookieDomainHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

#ifdef SB_USE_CLASS_TELCOOKIEMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_Clear(TElCookieManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_AddDomain(TElCookieManagerHandle _Handle, TElCookieDomainHandle Domain);
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_DeleteDomain(TElCookieManagerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_RemoveDomain(TElCookieManagerHandle _Handle, TElCookieDomainHandle Domain);
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_LoadFromStream(TElCookieManagerHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_SaveToStream(TElCookieManagerHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_GetCookiesForURL(TElCookieManagerHandle _Handle, const char * pcURL, int32_t szURL, int8_t SecureSession, int32_t * Format, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_SetCookiesForURL(TElCookieManagerHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle CookieList, int64_t ReceivedAt, int32_t ForceFormat);
#else
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_SetCookiesForURL(TElCookieManagerHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle CookieList, int64_t ReceivedAt, int32_t ForceFormat);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_get_DomainCount(TElCookieManagerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_get_Domains(TElCookieManagerHandle _Handle, int32_t Index, TElCookieDomainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCookieManager_Create(TComponentHandle AOwner, TElCookieManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOOKIEMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCookie;
class TElCookieDomain;
class TElCookieManager;
typedef TElCookieManager ElCookieManager;

#ifdef SB_USE_CLASS_TELCOOKIE
class TElCookie: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElCookie)
	public:
		void AssembleClientCookie(int32_t Format, std::string &OutResult);

		void ParseServerCookie(const std::string &ACookie, int64_t ReceivedAt, bool &DiscardCookie);

		virtual int32_t get_Included();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Included, TElCookie, Included);

		virtual bool get_Persistent();

		virtual void set_Persistent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Persistent, set_Persistent, TElCookie, Persistent);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		virtual void get_Comment(std::string &OutResult);

		virtual void set_Comment(const std::string &Value);

		virtual void get_CommentURL(std::string &OutResult);

		virtual void set_CommentURL(const std::string &Value);

		virtual void get_Domain(std::string &OutResult);

		virtual void set_Domain(const std::string &Value);

		virtual int64_t get_Expires();

		virtual void set_Expires(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Expires, set_Expires, TElCookie, Expires);

		virtual int32_t get_Format();

		virtual void set_Format(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Format, set_Format, TElCookie, Format);

		virtual bool get_HostOnly();

		virtual void set_HostOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HostOnly, set_HostOnly, TElCookie, HostOnly);

		virtual bool get_HTTPOnly();

		virtual void set_HTTPOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HTTPOnly, set_HTTPOnly, TElCookie, HTTPOnly);

		virtual void get_Path(std::string &OutResult);

		virtual void set_Path(const std::string &Value);

		virtual void get_Port(std::string &OutResult);

		virtual void set_Port(const std::string &Value);

		virtual bool get_Secure();

		virtual void set_Secure(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Secure, set_Secure, TElCookie, Secure);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElCookie, Version);

		TElCookie(TElCookieHandle handle, TElOwnHandle ownHandle);

		TElCookie();

};
#endif /* SB_USE_CLASS_TELCOOKIE */

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
class TElCookieDomain: public TObject
{
	private:
		SB_DISABLE_COPY(TElCookieDomain)
#ifdef SB_USE_CLASS_TELCOOKIE
		TElCookie* _Inst_Cookies;
#endif /* SB_USE_CLASS_TELCOOKIE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCOOKIE
		void AddCookie(TElCookie &ACookie);

		void AddCookie(TElCookie *ACookie);
#endif /* SB_USE_CLASS_TELCOOKIE */

		void Clear();

#ifdef SB_USE_CLASS_TELCOOKIE
		void RemoveCookie(TElCookie &ACookie);

		void RemoveCookie(TElCookie *ACookie);
#endif /* SB_USE_CLASS_TELCOOKIE */

		void DeleteCookie(int32_t index);

#ifdef SB_USE_CLASS_TELCOOKIE
		TElCookieHandle FindSameCookie(TElCookie &Cookie);

		TElCookieHandle FindSameCookie(TElCookie *Cookie);
#endif /* SB_USE_CLASS_TELCOOKIE */

#ifdef SB_USE_CLASS_TELCOOKIE
		virtual TElCookie* get_Cookies(int32_t Index);
#endif /* SB_USE_CLASS_TELCOOKIE */

		virtual int32_t get_CookieCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CookieCount, TElCookieDomain, CookieCount);

		virtual void get_Domain(std::string &OutResult);

		virtual void set_Domain(const std::string &Value);

		TElCookieDomain(TElCookieDomainHandle handle, TElOwnHandle ownHandle);

		TElCookieDomain();

		virtual ~TElCookieDomain();

};
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

#ifdef SB_USE_CLASS_TELCOOKIEMANAGER
class TElCookieManager: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCookieManager)
#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
		TElCookieDomain* _Inst_Domains;
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
		void AddDomain(TElCookieDomain &Domain);

		void AddDomain(TElCookieDomain *Domain);
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

		void DeleteDomain(int32_t Index);

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
		void RemoveDomain(TElCookieDomain &Domain);

		void RemoveDomain(TElCookieDomain *Domain);
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void GetCookiesForURL(const std::string &URL, bool SecureSession, int32_t &Format, std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetCookiesForURL(const std::string &URL, TStringList &CookieList, int64_t ReceivedAt, int32_t ForceFormat);

		void SetCookiesForURL(const std::string &URL, TStringList *CookieList, int64_t ReceivedAt, int32_t ForceFormat);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetCookiesForURL(const std::string &URL, TElStringList &CookieList, int64_t ReceivedAt, int32_t ForceFormat);

		void SetCookiesForURL(const std::string &URL, TElStringList *CookieList, int64_t ReceivedAt, int32_t ForceFormat);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual int32_t get_DomainCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_DomainCount, TElCookieManager, DomainCount);

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
		virtual TElCookieDomain* get_Domains(int32_t Index);
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

		TElCookieManager(TElCookieManagerHandle handle, TElOwnHandle ownHandle);

		explicit TElCookieManager(TComponent &AOwner);

		explicit TElCookieManager(TComponent *AOwner);

		virtual ~TElCookieManager();

};
#endif /* SB_USE_CLASS_TELCOOKIEMANAGER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCOOKIEMGR */
