#ifndef __INC_SBWEBDAVSERVER
#define __INC_SBWEBDAVSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstringlist.h"
#include "sbx509.h"
#include "sbcustomcertstorage.h"
#include "sbsslcommon.h"
#include "sbsslserver.h"
#include "sbsessionpool.h"
#include "sbxmldefs.h"
#include "sbxmlutils.h"
#include "sbxmlcore.h"
#include "sbxmlcharsets.h"
#include "sbhttpscommon.h"
#include "sbencoding.h"
#include "sbhttpsconstants.h"
#include "sbhttpsserver.h"
#include "sbsharedresource.h"
#include "sbrandom.h"
#include "sbwebdavcommon.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#include "sbhashfunction.h"
#include "sbsrp.h"
#include "sbsslconstants.h"
#include "sbdictionary.h"
#include "sbvcard.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SServerName 	"EldoS WebDAV Server"
#define SB_SAllowHeader 	"Allow: OPTIONS,PUT,POST,GET,HEAD,DELETE,PROPFIND,PROPPATCH,COPY,MOVE,LOCK,UNLOCK"
#define SB_SMsHeader 	"MS-Author-Via: DAV"
#define SB_SXMLContentType 	"application/xml"
#define SB_SDAV12Header 	"DAV: 1,2,3"
#define SB_SDAV1Header 	"DAV: 1,3"
#define SB_SACLHeader 	",access-control"
#define SB_SCardDAVHeader 	",addressbook"
#define SB_SCalDAVHeader 	",calendar-access"
#define SB_SExtendedMkColHeader 	"DAV: extended-mkcol"
#define SB_SAllowACLHeader 	",REPORT,ACL"
#define SB_SAllowCalDAVHeader 	",MKCALENDAR"
#define SB_SDirContentType 	"httpd/unix-directory"
#define SB_SLockTokenPrefix 	"opaquelocktoken"
#define SB_SSerializeName 	"WebDAVBlackbox"
#define SB_SSerializeNS 	"http://www.eldos.com/sbb/"
#define SB_SLangEn 	"en"
#define SB_SWriteProperties 	"Write properties"
#define SB_SWriteResourceContent 	"Write resource content"
#define SB_SWriteACL 	"Write ACL"
#define SB_SBind 	"Bind"
#define SB_SUnbind 	"Unbind"
#define SB_SReadACL 	"Read ACL"
#define SB_SReadCurrentUserPrivilegeSetProperty 	"Read current user privilege set property"
#define SB_SUnlockResource 	"Unlock resource"
#define SB_SReadAnyObject 	"Read any object"
#define SB_SWriteAnyObject 	"Write any object"
#define SB_SAnyOperation 	"Any operation"
#define SB_wdpCalReadFreeBusy 	256

typedef TElClassHandle TElWebDAVServerHandle;

typedef TElWebDAVServerHandle ElWebDAVServerHandle;

typedef TElClassHandle SBWebDAVServer_TElWebDavPrincipalHandle;

typedef TElClassHandle TElWebDavInMemoryPrincipalHandle;

typedef TElClassHandle TElWebDavPrincipalBackendHandle;

typedef TElClassHandle TElWebDavPrincipalMemoryBackendHandle;

typedef TElClassHandle TElCalDavTextMatchFilterHandle;

typedef TElClassHandle TElCalDavParamFilterHandle;

typedef TElClassHandle TElWebDavTimeRangeBaseHandle;

typedef TElClassHandle TElWebDavTimeRangeHandle;

typedef TElClassHandle TElCalDavPropFilterHandle;

typedef TElClassHandle TElCalDAVCompFilterHandle;

typedef TElClassHandle TElWebDavExtendedRequestHandle;

typedef TElClassHandle TElWebDavAddressBookRequestHandle;

typedef TElClassHandle TElWebDavLimitRecurrenceSetHandle;

typedef TElClassHandle TElWebDavExpandHandle;

typedef TElClassHandle TElWebDavLimitFreeBusySetHandle;

typedef TElClassHandle TElWebDavCompHandle;

typedef TElClassHandle TElWebDavCalendarRequestHandle;

typedef TElClassHandle TElWebDavPropertyHandle;

typedef TElWebDavPropertyHandle ElWebDavPropertyHandle;

typedef TElClassHandle TElWebDavIfStateHandle;

typedef TElWebDavIfStateHandle ElWebDavIfStateHandle;

typedef TElClassHandle TElWebDavIfResourceHandle;

typedef TElWebDavIfResourceHandle ElWebDavIfResourceHandle;

typedef TElClassHandle TElWebDAVIfHeaderHandle;

typedef TElWebDAVIfHeaderHandle ElWebDAVIfHeaderHandle;

typedef TObjectHandle TElWebDavLockFindHandleHandle;

typedef TObjectHandle ElWebDavLockFindHandleHandle;

typedef TElClassHandle TElWebDAVCustomLockListHandle;

typedef TElWebDAVCustomLockListHandle ElWebDAVCustomLockListHandle;

typedef TElClassHandle TElWebDavFindMemoryLockHandleHandle;

typedef TElClassHandle TElWebDAVMemoryLockListHandle;

typedef TElWebDAVMemoryLockListHandle ElWebDAVMemoryLockListHandle;

typedef TElClassHandle TElWebDAVACLOptionsHandle;

typedef TElClassHandle TElCardDAVOptionsHandle;

typedef TElClassHandle TElCalDAVOptionsHandle;

typedef TElClassHandle TElWebDavCollationHandle;

typedef TElClassHandle TElWebDavUnicodeCollationHandle;

typedef TElClassHandle TElWebDavAsciiCollationHandle;

typedef TElClassHandle TElWebDavOctetCollationHandle;

typedef uint8_t TSBWebDavPropfindModeRaw;

typedef enum
{
	pfmProp = 0,
	pfmPropname = 1,
	pfmAllprop = 2
} TSBWebDavPropfindMode;

typedef uint8_t TSBWebDavIfListTypeRaw;

typedef enum
{
	ltNoTagged = 0,
	ltTagged = 1,
	ltUnknown = 2
} TSBWebDavIfListType;

typedef uint8_t TSBWebDavIfStateTypeRaw;

typedef enum
{
	stLockToken = 0,
	stEtag = 1
} TSBWebDavIfStateType;

typedef uint8_t TSBWebDavFileOpenModeRaw;

typedef enum
{
	wdfmOpenRead = 0,
	wdfmOpenWrite = 1
} TSBWebDavFileOpenMode;

typedef void (SB_CALLBACK *TSBWebDavBeforeRequestEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPServerRequestParamsHandle Params, int8_t * Accept, int32_t * StatusCode, char * pcReasonPhrase, int32_t * szReasonPhrase);

typedef void (SB_CALLBACK *TSBWebDavRequestEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPServerRequestParamsHandle Params, TMemoryStreamHandle Data);

typedef void (SB_CALLBACK *TSBWebDavResponseEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPServerResponseParamsHandle Params, TMemoryStreamHandle Data);

typedef void (SB_CALLBACK *TSBWebDavStatusCodeEvent)(void * _ObjectData, TObjectHandle Sender, int32_t StatusCode, TElHTTPServerRequestParamsHandle ReqParams, TElHTTPServerResponseParamsHandle RespParams);

typedef void (SB_CALLBACK *TSBWebDavBeforeDownloadEvent)(void * _ObjectData, TObjectHandle Sender, char * pcURL, int32_t * szURL, int8_t * Allow);

typedef void (SB_CALLBACK *TSBWebDavBeforeUploadEvent)(void * _ObjectData, TObjectHandle Sender, char * pcURL, int32_t * szURL, int8_t * Allow);

typedef void (SB_CALLBACK *TSBWebDavTransferFinishedEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBWebDavPropertyReadValueEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, char * pcValue, int32_t * szValue, TElXMLDOMElementHandle Element, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavPropertyReadExValueEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, char * pcValue, int32_t * szValue, TElXMLDOMElementHandle Element, TObjectHandle Param, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavPropertyAfterReadValueEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, char * pcValue, int32_t * szValue, TElXMLDOMElementHandle Element);

typedef void (SB_CALLBACK *TSBWebDavPropertyBeforeWriteValueEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, char * pcValue, int32_t * szValue, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavPropertyWriteValueEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavPropertyRemoveEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavCheckIfAddressBookEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavSetAsAddressBookEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavCheckIfCalendarEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavSetAsCalendarEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int8_t * Success);

typedef void (SB_CALLBACK *TSBWebDavReadPrivilegesEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int32_t * Privileges);

typedef void (SB_CALLBACK *TSBWebDavReadOwnerEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle * Principal);

typedef void (SB_CALLBACK *TSBWebDavReadSupportedPrivilegesEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int32_t * Privileges);

typedef void (SB_CALLBACK *TSBWebDavGetPrivilegeDescriptionEvent)(void * _ObjectData, TObjectHandle Sender, int16_t Privilege, char * pcDescription, int32_t * szDescription, char * pcLanguage, int32_t * szLanguage);

typedef void (SB_CALLBACK *TSBWebDavGetACLRestrictionsEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, TElWebDavACLRestrictionsHandle Restrictions);

typedef void (SB_CALLBACK *TSBWebDavGetACLEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, TListHandle List, int8_t * OwnList);

typedef void (SB_CALLBACK *TSBWebDavSetACLEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, TListHandle List, TSBWebDavACLErrorRaw * Error, int32_t * StatusCode);

#ifdef SB_WINDOWS
typedef void (SB_CALLBACK *TSBWebDavGetURLSetEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, TStringListHandle List);
#else
typedef void (SB_CALLBACK *TSBWebDavGetURLSetEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, TElStringListHandle List);
#endif

typedef void (SB_CALLBACK *TSBCheckUIDUniquenessEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle Principal, TElDirInfoPropertiesListHandle PropList, int8_t * Unique);

#ifdef SB_USE_CLASS_TELWEBDAVSERVER
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_Open(TElWebDAVServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_DataAvailable(TElWebDAVServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_Close(TElWebDAVServerHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_AddProperty(TElWebDAVServerHandle _Handle, const TElWebDavPropertyHandle Prop, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_GetProperty(TElWebDAVServerHandle _Handle, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, TElWebDavPropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_RemoveProperty(TElWebDAVServerHandle _Handle, const TElWebDavPropertyHandle Prop, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_CreateCollection(TElWebDAVServerHandle _Handle, const char * pcURL, int32_t szURL);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_CreateAddressBook(TElWebDAVServerHandle _Handle, const char * pcURL, int32_t szURL, const char * pcDescription, int32_t szDescription, SBWebDAVServer_TElWebDavPrincipalHandle Owner);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_CreateCalendar(TElWebDAVServerHandle _Handle, const char * pcURL, int32_t szURL, const char * pcDescription, int32_t szDescription, SBWebDAVServer_TElWebDavPrincipalHandle Owner);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_PutVCard(TElWebDAVServerHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_PutVCard_1(TElWebDAVServerHandle _Handle, const char * pcURL, int32_t szURL, TElVCardHandle VCard);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_PutVCard_2(TElWebDAVServerHandle _Handle, const char * pcURL, int32_t szURL, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_AddCertTypeHandler(TElWebDAVServerHandle _Handle, TElSSLCertificateTypeHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_RemoveCertTypeHandler(TElWebDAVServerHandle _Handle, TElSSLCertificateTypeHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_GetCertTypeHandler(TElWebDAVServerHandle _Handle, TElSSLCertificateTypeRaw CertType, TElSSLCertificateTypeHandlerHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_MIMETypesMap(TElWebDAVServerHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_MIMETypesMap(TElWebDAVServerHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_Properties(TElWebDAVServerHandle _Handle, int32_t Idx, TElWebDavPropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_PropertiesCount(TElWebDAVServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_Control(TElWebDAVServerHandle _Handle, TElHTTPSServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_ACLOptions(TElWebDAVServerHandle _Handle, TElWebDAVACLOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_CardDAVOptions(TElWebDAVServerHandle _Handle, TElCardDAVOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_CalDAVOptions(TElWebDAVServerHandle _Handle, TElCalDAVOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_Active(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLMode(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_SSLMode(TElWebDAVServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLClientAuthentication(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_SSLClientAuthentication(TElWebDAVServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLAuthenticationLevel(TElWebDAVServerHandle _Handle, TSBAuthenticationLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_SSLAuthenticationLevel(TElWebDAVServerHandle _Handle, TSBAuthenticationLevelRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLForceCertificateChain(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_SSLForceCertificateChain(TElWebDAVServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_CertStorage(TElWebDAVServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_CertStorage(TElWebDAVServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLSessionPool(TElWebDAVServerHandle _Handle, TElSessionPoolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_SSLSessionPool(TElWebDAVServerHandle _Handle, TElSessionPoolHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_ClientCertStorage(TElWebDAVServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_ClientCertStorage(TElWebDAVServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLVersions(TElWebDAVServerHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_SSLVersions(TElWebDAVServerHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLExtensions(TElWebDAVServerHandle _Handle, TElServerSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLPeerExtensions(TElWebDAVServerHandle _Handle, TElCustomSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SSLSRPCredentialStore(TElWebDAVServerHandle _Handle, TElSRPCredentialStoreHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_SSLSRPCredentialStore(TElWebDAVServerHandle _Handle, TElSRPCredentialStoreHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_FileSystemAdapter(TElWebDAVServerHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_FileSystemAdapter(TElWebDAVServerHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_GlobalLockList(TElWebDAVServerHandle _Handle, TElWebDAVCustomLockListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_GlobalLockList(TElWebDAVServerHandle _Handle, TElWebDAVCustomLockListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_SendBufferSize(TElWebDAVServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_SendBufferSize(TElWebDAVServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_DefaultLockTimeout(TElWebDAVServerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_DefaultLockTimeout(TElWebDAVServerHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_AllowInfinity(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_AllowInfinity(TElWebDAVServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_PublishExclusiveLocks(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_PublishExclusiveLocks(TElWebDAVServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_PublishSharedLocks(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_PublishSharedLocks(TElWebDAVServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_ResponseContentType(TElWebDAVServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_ResponseContentType(TElWebDAVServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_MicrosoftCompatible(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_MicrosoftCompatible(TElWebDAVServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_ServerName(TElWebDAVServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_ServerName(TElWebDAVServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_UseWellKnownURIs(TElWebDAVServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_UseWellKnownURIs(TElWebDAVServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnGetSrpDb(TElWebDAVServerHandle _Handle, TSBServerSrpDbNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnGetSrpDb(TElWebDAVServerHandle _Handle, TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnBeforeRequest(TElWebDAVServerHandle _Handle, TSBWebDavBeforeRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnBeforeRequest(TElWebDAVServerHandle _Handle, TSBWebDavBeforeRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnRequest(TElWebDAVServerHandle _Handle, TSBWebDavRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnRequest(TElWebDAVServerHandle _Handle, TSBWebDavRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnResponse(TElWebDAVServerHandle _Handle, TSBWebDavResponseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnResponse(TElWebDAVServerHandle _Handle, TSBWebDavResponseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnStatusCode(TElWebDAVServerHandle _Handle, TSBWebDavStatusCodeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnStatusCode(TElWebDAVServerHandle _Handle, TSBWebDavStatusCodeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnBeforeUpload(TElWebDAVServerHandle _Handle, TSBWebDavBeforeUploadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnBeforeUpload(TElWebDAVServerHandle _Handle, TSBWebDavBeforeUploadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnBeforeDownload(TElWebDAVServerHandle _Handle, TSBWebDavBeforeDownloadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnBeforeDownload(TElWebDAVServerHandle _Handle, TSBWebDavBeforeDownloadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnTransferFinished(TElWebDAVServerHandle _Handle, TSBWebDavTransferFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnTransferFinished(TElWebDAVServerHandle _Handle, TSBWebDavTransferFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnGetUserPassword(TElWebDAVServerHandle _Handle, TSBOnGetUserPasswordEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnGetUserPassword(TElWebDAVServerHandle _Handle, TSBOnGetUserPasswordEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnSend(TElWebDAVServerHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnSend(TElWebDAVServerHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnReceive(TElWebDAVServerHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnReceive(TElWebDAVServerHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnOpenConnection(TElWebDAVServerHandle _Handle, TSBOpenConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnOpenConnection(TElWebDAVServerHandle _Handle, TSBOpenConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnCertificateValidate(TElWebDAVServerHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnCertificateValidate(TElWebDAVServerHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnCiphersNegotiated(TElWebDAVServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnCiphersNegotiated(TElWebDAVServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnSSLError(TElWebDAVServerHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnSSLError(TElWebDAVServerHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnExtensionsReceived(TElWebDAVServerHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnExtensionsReceived(TElWebDAVServerHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnExtensionsPrepared(TElWebDAVServerHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnExtensionsPrepared(TElWebDAVServerHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnKeyNeeded(TElWebDAVServerHandle _Handle, TSBServerKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnKeyNeeded(TElWebDAVServerHandle _Handle, TSBServerKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnCloseConnection(TElWebDAVServerHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnCloseConnection(TElWebDAVServerHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnRenegotiationStart(TElWebDAVServerHandle _Handle, TSBRenegotiationStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnRenegotiationStart(TElWebDAVServerHandle _Handle, TSBRenegotiationStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_get_OnCertificateURLs(TElWebDAVServerHandle _Handle, TSBCertificateURLsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_set_OnCertificateURLs(TElWebDAVServerHandle _Handle, TSBCertificateURLsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVServer_Create(TComponentHandle AOwner, TElWebDAVServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVSERVER */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_MemberOf(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_AddToGroup(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_Username(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_set_Username(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_DisplayName(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_set_DisplayName(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_URL(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_set_URL(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_AlternateURISet(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_Groups(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_AlternateURISet(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_Groups(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_IsGroup(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_set_IsGroup(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_Address(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_set_Address(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_get_ETag(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_set_ETag(SBWebDAVServer_TElWebDavPrincipalHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_TElWebDavPrincipal_Create(SBWebDAVServer_TElWebDavPrincipalHandle * OutResult);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVINMEMORYPRINCIPAL
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavInMemoryPrincipal_get_AddressBookHomeSet(TElWebDavInMemoryPrincipalHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavInMemoryPrincipal_get_CalendarHomeSet(TElWebDavInMemoryPrincipalHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDavInMemoryPrincipal_get_AddressBookHomeSet(TElWebDavInMemoryPrincipalHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavInMemoryPrincipal_get_CalendarHomeSet(TElWebDavInMemoryPrincipalHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDavInMemoryPrincipal_Create(TElWebDavInMemoryPrincipalHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVINMEMORYPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_BeginRead(TElWebDavPrincipalBackendHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_BeginWrite(TElWebDavPrincipalBackendHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_Done(TElWebDavPrincipalBackendHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_AddPrincipal(TElWebDavPrincipalBackendHandle _Handle, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_RemovePrincipal(TElWebDavPrincipalBackendHandle _Handle, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_RemovePrincipal_1(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_PrincipalExists(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_FindPrincipalByURL(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_FindPrincipalByName(TElWebDavPrincipalBackendHandle _Handle, const char * pcName, int32_t szName, SBWebDAVServer_TElWebDavPrincipalHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetGroupMemberSet(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetGroupMembership(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetPrincipalCollectionSet(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetPrincipalAddressBookHomeSet(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetPrincipalCalendarHomeSet(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_EnumPrincipals(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetGroupMemberSet(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetGroupMembership(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetPrincipalCollectionSet(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetPrincipalAddressBookHomeSet(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_GetPrincipalCalendarHomeSet(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_EnumPrincipals(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_CollectionExists(TElWebDavPrincipalBackendHandle _Handle, const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalBackend_Create(TElWebDavPrincipalBackendHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALMEMORYBACKEND
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_BeginRead(TElWebDavPrincipalMemoryBackendHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_BeginWrite(TElWebDavPrincipalMemoryBackendHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_Done(TElWebDavPrincipalMemoryBackendHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_AddPrincipal(TElWebDavPrincipalMemoryBackendHandle _Handle, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_RemovePrincipal(TElWebDavPrincipalMemoryBackendHandle _Handle, SBWebDAVServer_TElWebDavPrincipalHandle Principal, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_RemovePrincipal_1(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_PrincipalExists(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_FindPrincipalByURL(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, SBWebDAVServer_TElWebDavPrincipalHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_FindPrincipalByName(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcName, int32_t szName, SBWebDAVServer_TElWebDavPrincipalHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetGroupMemberSet(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetGroupMembership(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetPrincipalCollectionSet(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetPrincipalAddressBookHomeSet(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetPrincipalCalendarHomeSet(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_EnumPrincipals(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle List, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetGroupMemberSet(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetGroupMembership(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetPrincipalCollectionSet(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetPrincipalAddressBookHomeSet(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_GetPrincipalCalendarHomeSet(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_EnumPrincipals(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle List, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_get_CardDAVPrefix(TElWebDavPrincipalMemoryBackendHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_set_CardDAVPrefix(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_get_CalDAVPrefix(TElWebDavPrincipalMemoryBackendHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_set_CalDAVPrefix(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_get_PrincipalBaseURL(TElWebDavPrincipalMemoryBackendHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_set_PrincipalBaseURL(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_get_GroupBaseURL(TElWebDavPrincipalMemoryBackendHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_set_GroupBaseURL(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_get_ContactFileName(TElWebDavPrincipalMemoryBackendHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_set_ContactFileName(TElWebDavPrincipalMemoryBackendHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalMemoryBackend_Create(TElWebDavPrincipalMemoryBackendHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALMEMORYBACKEND */

#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
SB_IMPORT uint32_t SB_APIENTRY TElCalDavTextMatchFilter_Create(TElWebDavFilterHandle Parent, TElCalDavTextMatchFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCALDAVPARAMFILTER
SB_IMPORT uint32_t SB_APIENTRY TElCalDavParamFilter_LoadFromXML(TElCalDavParamFilterHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDavParamFilter_get_IsNotDefined(TElCalDavParamFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDavParamFilter_get_TextMatch(TElCalDavParamFilterHandle _Handle, TElCalDavTextMatchFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDavParamFilter_Create(TElWebDavFilterHandle Parent, TElCalDavParamFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCALDAVPARAMFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGEBASE
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTimeRangeBase_LoadFromXML(TElWebDavTimeRangeBaseHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTimeRangeBase_get_Start(TElWebDavTimeRangeBaseHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTimeRangeBase_get_End_(TElWebDavTimeRangeBaseHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTimeRangeBase_Create(TElWebDavTimeRangeBaseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGEBASE */

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTimeRange_Create(TElWebDavTimeRangeBaseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */

#ifdef SB_USE_CLASS_TELCALDAVPROPFILTER
SB_IMPORT uint32_t SB_APIENTRY TElCalDavPropFilter_LoadFromXML(TElCalDavPropFilterHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDavPropFilter_get_SubFilters(TElCalDavPropFilterHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDavPropFilter_get_IsNotDefined(TElCalDavPropFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDavPropFilter_get_TimeRange(TElCalDavPropFilterHandle _Handle, TElWebDavTimeRangeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDavPropFilter_get_TextMatch(TElCalDavPropFilterHandle _Handle, TElCalDavTextMatchFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDavPropFilter_Create(TElWebDavFilterHandle Parent, TElCalDavPropFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCALDAVPROPFILTER */

#ifdef SB_USE_CLASS_TELCALDAVCOMPFILTER
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVCompFilter_LoadFromXML(TElCalDAVCompFilterHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVCompFilter_get_SubFilters(TElCalDAVCompFilterHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVCompFilter_get_IsNotDefined(TElCalDAVCompFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVCompFilter_get_TimeRange(TElCalDAVCompFilterHandle _Handle, TElWebDavTimeRangeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVCompFilter_Create(TElWebDavFilterHandle Parent, TElCalDAVCompFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCALDAVCOMPFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVEXTENDEDREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_LoadFromXML(TElWebDavExtendedRequestHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_get_ReportName(TElWebDavExtendedRequestHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_set_ReportName(TElWebDavExtendedRequestHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_get_Hrefs(TElWebDavExtendedRequestHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_get_Hrefs(TElWebDavExtendedRequestHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_get_AllProp(TElWebDavExtendedRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_set_AllProp(TElWebDavExtendedRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_get_EvaluationResult(TElWebDavExtendedRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_set_EvaluationResult(TElWebDavExtendedRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExtendedRequest_Create(TElWebDavExtendedRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVEXTENDEDREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVADDRESSBOOKREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_LoadFromXML(TElWebDavAddressBookRequestHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_get_Test(TElWebDavAddressBookRequestHandle _Handle, TSBWebDavFilterTestRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_set_Test(TElWebDavAddressBookRequestHandle _Handle, TSBWebDavFilterTestRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_get_Filters(TElWebDavAddressBookRequestHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_get_Limit(TElWebDavAddressBookRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_set_Limit(TElWebDavAddressBookRequestHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_get_Names(TElWebDavAddressBookRequestHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_get_Names(TElWebDavAddressBookRequestHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAddressBookRequest_Create(TElWebDavAddressBookRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVADDRESSBOOKREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET
SB_IMPORT uint32_t SB_APIENTRY TElWebDavLimitRecurrenceSet_Create(TElWebDavTimeRangeBaseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET */

#ifdef SB_USE_CLASS_TELWEBDAVEXPAND
SB_IMPORT uint32_t SB_APIENTRY TElWebDavExpand_Create(TElWebDavTimeRangeBaseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVEXPAND */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET
SB_IMPORT uint32_t SB_APIENTRY TElWebDavLimitFreeBusySet_Create(TElWebDavTimeRangeBaseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET */

#ifdef SB_USE_CLASS_TELWEBDAVCOMP
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_LoadFromXML(TElWebDavCompHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_get_Parent(TElWebDavCompHandle _Handle, TElWebDavCompHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_get_Name(TElWebDavCompHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_set_Name(TElWebDavCompHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_get_AllProp(TElWebDavCompHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_set_AllProp(TElWebDavCompHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_get_AllComp(TElWebDavCompHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_set_AllComp(TElWebDavCompHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_get_Props(TElWebDavCompHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_get_Props(TElWebDavCompHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_get_Comps(TElWebDavCompHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_get_FullPath(TElWebDavCompHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavComp_Create(TElWebDavCompHandle Parent, TElWebDavCompHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVCOMP */

#ifdef SB_USE_CLASS_TELWEBDAVCALENDARREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCalendarRequest_LoadFromXML(TElWebDavCalendarRequestHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCalendarRequest_get_CompFilter(TElWebDavCalendarRequestHandle _Handle, TElCalDAVCompFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCalendarRequest_get_Timezone(TElWebDavCalendarRequestHandle _Handle, TElVCalendarHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCalendarRequest_get_Comp(TElWebDavCalendarRequestHandle _Handle, TElWebDavCompHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCalendarRequest_get_Expand(TElWebDavCalendarRequestHandle _Handle, TElWebDavExpandHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCalendarRequest_get_LimitRecurrenceSet(TElWebDavCalendarRequestHandle _Handle, TElWebDavLimitRecurrenceSetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCalendarRequest_get_LimitFreebusySet(TElWebDavCalendarRequestHandle _Handle, TElWebDavLimitFreeBusySetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCalendarRequest_Create(TElWebDavCalendarRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVCALENDARREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_Write(TElWebDavPropertyHandle _Handle, const char * pcURL, int32_t szURL, const char * pcValue, int32_t szValue, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_Read(TElWebDavPropertyHandle _Handle, const char * pcURL, int32_t szURL, char * pcValue, int32_t * szValue, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_Read_1(TElWebDavPropertyHandle _Handle, const char * pcURL, int32_t szURL, char * pcValue, int32_t * szValue, TElXMLDOMElementHandle Element, TObjectHandle Param, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_Remove(TElWebDavPropertyHandle _Handle, const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_NS(TElWebDavPropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_Name(TElWebDavPropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_Live(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_Protect(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_AsXML(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_PrincipalMatch(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_Principal(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_AddressBook(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_Calendar(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_Copy(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_Search(TElWebDavPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_Search(TElWebDavPropertyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_Description(TElWebDavPropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_Description(TElWebDavPropertyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_DescLang(TElWebDavPropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_DescLang(TElWebDavPropertyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_OnReadValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyReadValueEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_OnReadValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyReadValueEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_OnReadExValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyReadExValueEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_OnReadExValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyReadExValueEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_OnWriteValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyWriteValueEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_OnWriteValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyWriteValueEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_OnAfterReadValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyAfterReadValueEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_OnAfterReadValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyAfterReadValueEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_OnBeforeWriteValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyBeforeWriteValueEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_OnBeforeWriteValue(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyBeforeWriteValueEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_get_OnRemove(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyRemoveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_set_OnRemove(TElWebDavPropertyHandle _Handle, TSBWebDavPropertyRemoveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavProperty_Create(TElWebDAVServerHandle Server, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, int8_t Live, int8_t Protect, int8_t AsXML, int8_t PrincipalMatch, int8_t Principal, int8_t AddressBook, int8_t Calendar, int8_t Copy, TElWebDavPropertyHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

#ifdef SB_USE_CLASS_TELWEBDAVIFSTATE
SB_IMPORT uint32_t SB_APIENTRY TElWebDavIfState_get_AType(TElWebDavIfStateHandle _Handle, TSBWebDavIfStateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavIfState_get_Condition(TElWebDavIfStateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavIfState_get_Value(TElWebDavIfStateHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavIfState_Create(TSBWebDavIfStateTypeRaw AType, int8_t Condition, const char * pcValue, int32_t szValue, TElWebDavIfStateHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVIFSTATE */

#ifdef SB_USE_CLASS_TELWEBDAVIFRESOURCE
SB_IMPORT uint32_t SB_APIENTRY TElWebDavIfResource_get_URI(TElWebDavIfResourceHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavIfResource_get_States(TElWebDavIfResourceHandle _Handle, int32_t Idx, TElWebDavIfStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavIfResource_get_Count(TElWebDavIfResourceHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavIfResource_Create(const char * pcURI, int32_t szURI, TElWebDavIfResourceHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVIFRESOURCE */

#ifdef SB_USE_CLASS_TELWEBDAVIFHEADER
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVIfHeader_Process(TElWebDAVIfHeaderHandle _Handle, const char * pcS, int32_t szS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVIfHeader_get_URL(TElWebDAVIfHeaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVIfHeader_get_Resources(TElWebDAVIfHeaderHandle _Handle, int32_t Idx, TElWebDavIfResourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVIfHeader_get_Count(TElWebDAVIfHeaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVIfHeader_Create(const char * pcURL, int32_t szURL, TElWebDAVIfHeaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVIFHEADER */

#ifdef SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_Enter(TElWebDAVCustomLockListHandle _Handle, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_Done(TElWebDAVCustomLockListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_Add(TElWebDAVCustomLockListHandle _Handle, const TElWebDAVLockHandle Lock);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_Remove(TElWebDAVCustomLockListHandle _Handle, const TElWebDAVLockHandle Lock);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_Find(TElWebDAVCustomLockListHandle _Handle, const char * pcToken, int32_t szToken, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_FindAll(TElWebDAVCustomLockListHandle _Handle, const char * pcURL, int32_t szURL, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_FindFirst(TElWebDAVCustomLockListHandle _Handle, TObjectHandle * Handle, const char * pcURL, int32_t szURL, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_FindNext(TElWebDAVCustomLockListHandle _Handle, TObjectHandle Handle, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_FindClose(TElWebDAVCustomLockListHandle _Handle, TObjectHandle Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_LoadFromStream(TElWebDAVCustomLockListHandle _Handle, TStreamHandle Stream, int8_t Clear);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_SaveToStream(TElWebDAVCustomLockListHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_get_Locks(TElWebDAVCustomLockListHandle _Handle, int32_t Idx, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_get_Count(TElWebDAVCustomLockListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVCustomLockList_Create(TComponentHandle AOwner, TElWebDAVCustomLockListHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVFINDMEMORYLOCKHANDLE
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFindMemoryLockHandle_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVFINDMEMORYLOCKHANDLE */

#ifdef SB_USE_CLASS_TELWEBDAVMEMORYLOCKLIST
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_Enter(TElWebDAVMemoryLockListHandle _Handle, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_Done(TElWebDAVMemoryLockListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_Add(TElWebDAVMemoryLockListHandle _Handle, const TElWebDAVLockHandle Lock);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_Remove(TElWebDAVMemoryLockListHandle _Handle, const TElWebDAVLockHandle Lock);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_Find(TElWebDAVMemoryLockListHandle _Handle, const char * pcToken, int32_t szToken, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_FindAll(TElWebDAVMemoryLockListHandle _Handle, const char * pcURL, int32_t szURL, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_FindFirst(TElWebDAVMemoryLockListHandle _Handle, TObjectHandle * Handle, const char * pcURL, int32_t szURL, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_FindNext(TElWebDAVMemoryLockListHandle _Handle, TObjectHandle Handle, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_FindClose(TElWebDAVMemoryLockListHandle _Handle, TObjectHandle Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_LoadFromStream(TElWebDAVMemoryLockListHandle _Handle, TStreamHandle Stream, int8_t Clear);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_SaveToStream(TElWebDAVMemoryLockListHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_Cleanup(TElWebDAVMemoryLockListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_get_Locks(TElWebDAVMemoryLockListHandle _Handle, int32_t Idx, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_get_Count(TElWebDAVMemoryLockListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMemoryLockList_Create(TComponentHandle AOwner, TElWebDAVMemoryLockListHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVMEMORYLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVACLOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_UseACL(TElWebDAVACLOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_UseACL(TElWebDAVACLOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_PrincipalBackend(TElWebDAVACLOptionsHandle _Handle, TElWebDavPrincipalBackendHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_PrincipalBackend(TElWebDAVACLOptionsHandle _Handle, TElWebDavPrincipalBackendHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_AbstractPrivileges(TElWebDAVACLOptionsHandle _Handle, int16_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_AbstractPrivileges(TElWebDAVACLOptionsHandle _Handle, const int16_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_MatchingPrincipalsLimit(TElWebDAVACLOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_MatchingPrincipalsLimit(TElWebDAVACLOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_OnReadCurrentUserPrivileges(TElWebDAVACLOptionsHandle _Handle, TSBWebDavReadPrivilegesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_OnReadCurrentUserPrivileges(TElWebDAVACLOptionsHandle _Handle, TSBWebDavReadPrivilegesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_OnReadSupportedPrivileges(TElWebDAVACLOptionsHandle _Handle, TSBWebDavReadSupportedPrivilegesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_OnReadSupportedPrivileges(TElWebDAVACLOptionsHandle _Handle, TSBWebDavReadSupportedPrivilegesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_OnReadOwner(TElWebDAVACLOptionsHandle _Handle, TSBWebDavReadOwnerEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_OnReadOwner(TElWebDAVACLOptionsHandle _Handle, TSBWebDavReadOwnerEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_OnGetPrivilegeDescription(TElWebDAVACLOptionsHandle _Handle, TSBWebDavGetPrivilegeDescriptionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_OnGetPrivilegeDescription(TElWebDAVACLOptionsHandle _Handle, TSBWebDavGetPrivilegeDescriptionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_OnGetACLRestrictions(TElWebDAVACLOptionsHandle _Handle, TSBWebDavGetACLRestrictionsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_OnGetACLRestrictions(TElWebDAVACLOptionsHandle _Handle, TSBWebDavGetACLRestrictionsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_OnGetACL(TElWebDAVACLOptionsHandle _Handle, TSBWebDavGetACLEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_OnGetACL(TElWebDAVACLOptionsHandle _Handle, TSBWebDavGetACLEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_OnSetACL(TElWebDAVACLOptionsHandle _Handle, TSBWebDavSetACLEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_OnSetACL(TElWebDAVACLOptionsHandle _Handle, TSBWebDavSetACLEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_get_OnGetInheritedACLSet(TElWebDAVACLOptionsHandle _Handle, TSBWebDavGetURLSetEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_set_OnGetInheritedACLSet(TElWebDAVACLOptionsHandle _Handle, TSBWebDavGetURLSetEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVACLOptions_Create(TElWebDAVACLOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVACLOPTIONS */

#ifdef SB_USE_CLASS_TELCARDDAVOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_UseCardDAV(TElCardDAVOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_set_UseCardDAV(TElCardDAVOptionsHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_AddressBookURLs(TElCardDAVOptionsHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_AddressBookURLs(TElCardDAVOptionsHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_MaxResourceSize(TElCardDAVOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_set_MaxResourceSize(TElCardDAVOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_NumberOfMatchesLimit(TElCardDAVOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_set_NumberOfMatchesLimit(TElCardDAVOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_AllowExtendedMkCol(TElCardDAVOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_set_AllowExtendedMkCol(TElCardDAVOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_OnCheckIfAddressBook(TElCardDAVOptionsHandle _Handle, TSBWebDavCheckIfAddressBookEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_set_OnCheckIfAddressBook(TElCardDAVOptionsHandle _Handle, TSBWebDavCheckIfAddressBookEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_OnSetAsAddressBook(TElCardDAVOptionsHandle _Handle, TSBWebDavSetAsAddressBookEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_set_OnSetAsAddressBook(TElCardDAVOptionsHandle _Handle, TSBWebDavSetAsAddressBookEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_get_OnCheckUIDUniqueness(TElCardDAVOptionsHandle _Handle, TSBCheckUIDUniquenessEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_set_OnCheckUIDUniqueness(TElCardDAVOptionsHandle _Handle, TSBCheckUIDUniquenessEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCardDAVOptions_Create(TElCardDAVOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCARDDAVOPTIONS */

#ifdef SB_USE_CLASS_TELCALDAVOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_UseCalDAV(TElCalDAVOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_UseCalDAV(TElCalDAVOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_MaxResourceSize(TElCalDAVOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_MaxResourceSize(TElCalDAVOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_MinDateTime(TElCalDAVOptionsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_MinDateTime(TElCalDAVOptionsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_MaxDateTime(TElCalDAVOptionsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_MaxDateTime(TElCalDAVOptionsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_MaxRecurrenceInstances(TElCalDAVOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_MaxRecurrenceInstances(TElCalDAVOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_MaxAttendeesPerInstance(TElCalDAVOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_MaxAttendeesPerInstance(TElCalDAVOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_OnCheckIfCalendar(TElCalDAVOptionsHandle _Handle, TSBWebDavCheckIfCalendarEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_OnCheckIfCalendar(TElCalDAVOptionsHandle _Handle, TSBWebDavCheckIfCalendarEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_OnSetAsCalendar(TElCalDAVOptionsHandle _Handle, TSBWebDavSetAsCalendarEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_OnSetAsCalendar(TElCalDAVOptionsHandle _Handle, TSBWebDavSetAsCalendarEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_get_OnCheckUIDUniqueness(TElCalDAVOptionsHandle _Handle, TSBCheckUIDUniquenessEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_set_OnCheckUIDUniqueness(TElCalDAVOptionsHandle _Handle, TSBCheckUIDUniquenessEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCalDAVOptions_Create(TElCalDAVOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCALDAVOPTIONS */

#ifdef SB_USE_CLASS_TELWEBDAVCOLLATION
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCollation_CreateInstance(TSBWebDavFilterTextMatchCollationRaw Collation, TElWebDavCollationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCollation_CreateInstance_1(TElWebDavCollationHandle _Handle, TSBWebDavFilterTextMatchCollationRaw Collation, TElWebDavCollationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCollation_Compare(TElWebDavCollationHandle _Handle, const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCollation_StartsWith(TElWebDavCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCollation_EndsWith(TElWebDavCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCollation_Equals(TElWebDavCollationHandle _Handle, const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCollation_IndexOf(TElWebDavCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavCollation_Create(TElWebDavCollationHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVCOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVUNICODECOLLATION
SB_IMPORT uint32_t SB_APIENTRY TElWebDavUnicodeCollation_Compare(TElWebDavUnicodeCollationHandle _Handle, const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavUnicodeCollation_StartsWith(TElWebDavUnicodeCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavUnicodeCollation_EndsWith(TElWebDavUnicodeCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavUnicodeCollation_Equals(TElWebDavUnicodeCollationHandle _Handle, const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavUnicodeCollation_IndexOf(TElWebDavUnicodeCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavUnicodeCollation_Create(TElWebDavUnicodeCollationHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVUNICODECOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVASCIICOLLATION
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAsciiCollation_Compare(TElWebDavAsciiCollationHandle _Handle, const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAsciiCollation_StartsWith(TElWebDavAsciiCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAsciiCollation_EndsWith(TElWebDavAsciiCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAsciiCollation_Equals(TElWebDavAsciiCollationHandle _Handle, const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAsciiCollation_IndexOf(TElWebDavAsciiCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavAsciiCollation_Create(TElWebDavAsciiCollationHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVASCIICOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVOCTETCOLLATION
SB_IMPORT uint32_t SB_APIENTRY TElWebDavOctetCollation_Compare(TElWebDavOctetCollationHandle _Handle, const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavOctetCollation_StartsWith(TElWebDavOctetCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavOctetCollation_EndsWith(TElWebDavOctetCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavOctetCollation_Equals(TElWebDavOctetCollationHandle _Handle, const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavOctetCollation_IndexOf(TElWebDavOctetCollationHandle _Handle, const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavOctetCollation_Create(TElWebDavOctetCollationHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVOCTETCOLLATION */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElWebDAVServer;
typedef TElWebDAVServer ElWebDAVServer;
class SBWebDAVServer_TElWebDavPrincipal;
class TElWebDavInMemoryPrincipal;
class TElWebDavPrincipalBackend;
class TElWebDavPrincipalMemoryBackend;
class TElCalDavTextMatchFilter;
class TElCalDavParamFilter;
class TElWebDavTimeRangeBase;
class TElWebDavTimeRange;
class TElCalDavPropFilter;
class TElCalDAVCompFilter;
class TElWebDavExtendedRequest;
class TElWebDavAddressBookRequest;
class TElWebDavLimitRecurrenceSet;
class TElWebDavExpand;
class TElWebDavLimitFreeBusySet;
class TElWebDavComp;
class TElWebDavCalendarRequest;
class TElWebDavProperty;
typedef TElWebDavProperty ElWebDavProperty;
class TElWebDavIfState;
typedef TElWebDavIfState ElWebDavIfState;
class TElWebDavIfResource;
typedef TElWebDavIfResource ElWebDavIfResource;
class TElWebDAVIfHeader;
typedef TElWebDAVIfHeader ElWebDAVIfHeader;
typedef TObject TElWebDavLockFindHandle;
typedef TObject ElWebDavLockFindHandle;
class TElWebDAVCustomLockList;
typedef TElWebDAVCustomLockList ElWebDAVCustomLockList;
class TElWebDavFindMemoryLockHandle;
class TElWebDAVMemoryLockList;
typedef TElWebDAVMemoryLockList ElWebDAVMemoryLockList;
class TElWebDAVACLOptions;
class TElCardDAVOptions;
class TElCalDAVOptions;
class TElWebDavCollation;
class TElWebDavUnicodeCollation;
class TElWebDavAsciiCollation;
class TElWebDavOctetCollation;

#ifdef SB_USE_CLASS_TELWEBDAVSERVER
class TElWebDAVServer: public TComponent
{
	private:
		SB_DISABLE_COPY(TElWebDAVServer)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_MIMETypesMap;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_MIMETypesMap;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
		TElWebDavProperty* _Inst_Properties;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */
#ifdef SB_USE_CLASS_TELHTTPSSERVER
		TElHTTPSServer* _Inst_Control;
#endif /* SB_USE_CLASS_TELHTTPSSERVER */
#ifdef SB_USE_CLASS_TELWEBDAVACLOPTIONS
		TElWebDAVACLOptions* _Inst_ACLOptions;
#endif /* SB_USE_CLASS_TELWEBDAVACLOPTIONS */
#ifdef SB_USE_CLASS_TELCARDDAVOPTIONS
		TElCardDAVOptions* _Inst_CardDAVOptions;
#endif /* SB_USE_CLASS_TELCARDDAVOPTIONS */
#ifdef SB_USE_CLASS_TELCALDAVOPTIONS
		TElCalDAVOptions* _Inst_CalDAVOptions;
#endif /* SB_USE_CLASS_TELCALDAVOPTIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
		TElSessionPool* _Inst_SSLSessionPool;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
		TElServerSSLExtensions* _Inst_SSLExtensions;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		TElCustomSSLExtensions* _Inst_SSLPeerExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
		TElSRPCredentialStore* _Inst_SSLSRPCredentialStore;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST
		TElWebDAVCustomLockList* _Inst_GlobalLockList;
#endif /* SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST */

		void initInstances();

	public:
		void Open();

		void DataAvailable();

		void Close(bool Silent);

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
		bool AddProperty(const TElWebDavProperty &Prop);

		bool AddProperty(const TElWebDavProperty *Prop);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
		TElWebDavPropertyHandle GetProperty(const std::string &NS, const std::string &Name);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
		bool RemoveProperty(const TElWebDavProperty &Prop);

		bool RemoveProperty(const TElWebDavProperty *Prop);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

		void CreateCollection(const std::string &URL);

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		void CreateAddressBook(const std::string &URL, const std::string &Description, SBWebDAVServer_TElWebDavPrincipal &Owner);

		void CreateAddressBook(const std::string &URL, const std::string &Description, SBWebDAVServer_TElWebDavPrincipal *Owner);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		void CreateCalendar(const std::string &URL, const std::string &Description, SBWebDAVServer_TElWebDavPrincipal &Owner);

		void CreateCalendar(const std::string &URL, const std::string &Description, SBWebDAVServer_TElWebDavPrincipal *Owner);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_TSTREAM
		void PutVCard(const std::string &URL, TStream &Strm);

		void PutVCard(const std::string &URL, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELVCARD
		void PutVCard(const std::string &URL, TElVCard &VCard);

		void PutVCard(const std::string &URL, TElVCard *VCard);
#endif /* SB_USE_CLASS_TELVCARD */

		void PutVCard(const std::string &URL, const std::string &FileName);

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
		void AddCertTypeHandler(TElSSLCertificateTypeHandler &Handler);

		void AddCertTypeHandler(TElSSLCertificateTypeHandler *Handler);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
		void RemoveCertTypeHandler(TElSSLCertificateTypeHandler &Handler);

		void RemoveCertTypeHandler(TElSSLCertificateTypeHandler *Handler);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
		TElSSLCertificateTypeHandlerHandle GetCertTypeHandler(TElSSLCertificateType CertType);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_MIMETypesMap();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_MIMETypesMap, TElWebDAVServer, MIMETypesMap);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_MIMETypesMap();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_MIMETypesMap, TElWebDAVServer, MIMETypesMap);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
		virtual TElWebDavProperty* get_Properties(int32_t Idx);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

		virtual int32_t get_PropertiesCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PropertiesCount, TElWebDAVServer, PropertiesCount);

#ifdef SB_USE_CLASS_TELHTTPSSERVER
		virtual TElHTTPSServer* get_Control();

		SB_DECLARE_PROPERTY_GET(TElHTTPSServer*, get_Control, TElWebDAVServer, Control);
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

#ifdef SB_USE_CLASS_TELWEBDAVACLOPTIONS
		virtual TElWebDAVACLOptions* get_ACLOptions();

		SB_DECLARE_PROPERTY_GET(TElWebDAVACLOptions*, get_ACLOptions, TElWebDAVServer, ACLOptions);
#endif /* SB_USE_CLASS_TELWEBDAVACLOPTIONS */

#ifdef SB_USE_CLASS_TELCARDDAVOPTIONS
		virtual TElCardDAVOptions* get_CardDAVOptions();

		SB_DECLARE_PROPERTY_GET(TElCardDAVOptions*, get_CardDAVOptions, TElWebDAVServer, CardDAVOptions);
#endif /* SB_USE_CLASS_TELCARDDAVOPTIONS */

#ifdef SB_USE_CLASS_TELCALDAVOPTIONS
		virtual TElCalDAVOptions* get_CalDAVOptions();

		SB_DECLARE_PROPERTY_GET(TElCalDAVOptions*, get_CalDAVOptions, TElWebDAVServer, CalDAVOptions);
#endif /* SB_USE_CLASS_TELCALDAVOPTIONS */

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElWebDAVServer, Active);

		virtual bool get_SSLMode();

		virtual void set_SSLMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SSLMode, set_SSLMode, TElWebDAVServer, SSLMode);

		virtual bool get_SSLClientAuthentication();

		virtual void set_SSLClientAuthentication(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SSLClientAuthentication, set_SSLClientAuthentication, TElWebDAVServer, SSLClientAuthentication);

		virtual TSBAuthenticationLevel get_SSLAuthenticationLevel();

		virtual void set_SSLAuthenticationLevel(TSBAuthenticationLevel Value);

		SB_DECLARE_PROPERTY(TSBAuthenticationLevel, get_SSLAuthenticationLevel, set_SSLAuthenticationLevel, TElWebDAVServer, SSLAuthenticationLevel);

		virtual bool get_SSLForceCertificateChain();

		virtual void set_SSLForceCertificateChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SSLForceCertificateChain, set_SSLForceCertificateChain, TElWebDAVServer, SSLForceCertificateChain);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElWebDAVServer, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
		virtual TElSessionPool* get_SSLSessionPool();

		virtual void set_SSLSessionPool(TElSessionPool &Value);

		virtual void set_SSLSessionPool(TElSessionPool *Value);

		SB_DECLARE_PROPERTY(TElSessionPool*, get_SSLSessionPool, set_SSLSessionPool, TElWebDAVServer, SSLSessionPool);
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElWebDAVServer, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual TSBVersions get_SSLVersions();

		virtual void set_SSLVersions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_SSLVersions, set_SSLVersions, TElWebDAVServer, SSLVersions);

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
		virtual TElServerSSLExtensions* get_SSLExtensions();

		SB_DECLARE_PROPERTY_GET(TElServerSSLExtensions*, get_SSLExtensions, TElWebDAVServer, SSLExtensions);
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		virtual TElCustomSSLExtensions* get_SSLPeerExtensions();

		SB_DECLARE_PROPERTY_GET(TElCustomSSLExtensions*, get_SSLPeerExtensions, TElWebDAVServer, SSLPeerExtensions);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
		virtual TElSRPCredentialStore* get_SSLSRPCredentialStore();

		virtual void set_SSLSRPCredentialStore(TElSRPCredentialStore &Value);

		virtual void set_SSLSRPCredentialStore(TElSRPCredentialStore *Value);

		SB_DECLARE_PROPERTY(TElSRPCredentialStore*, get_SSLSRPCredentialStore, set_SSLSRPCredentialStore, TElWebDAVServer, SSLSRPCredentialStore);
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElWebDAVServer, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST
		virtual TElWebDAVCustomLockList* get_GlobalLockList();

		virtual void set_GlobalLockList(TElWebDAVCustomLockList &Value);

		virtual void set_GlobalLockList(TElWebDAVCustomLockList *Value);

		SB_DECLARE_PROPERTY(TElWebDAVCustomLockList*, get_GlobalLockList, set_GlobalLockList, TElWebDAVServer, GlobalLockList);
#endif /* SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST */

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElWebDAVServer, SendBufferSize);

		virtual int64_t get_DefaultLockTimeout();

		virtual void set_DefaultLockTimeout(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_DefaultLockTimeout, set_DefaultLockTimeout, TElWebDAVServer, DefaultLockTimeout);

		virtual bool get_AllowInfinity();

		virtual void set_AllowInfinity(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowInfinity, set_AllowInfinity, TElWebDAVServer, AllowInfinity);

		virtual bool get_PublishExclusiveLocks();

		virtual void set_PublishExclusiveLocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PublishExclusiveLocks, set_PublishExclusiveLocks, TElWebDAVServer, PublishExclusiveLocks);

		virtual bool get_PublishSharedLocks();

		virtual void set_PublishSharedLocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PublishSharedLocks, set_PublishSharedLocks, TElWebDAVServer, PublishSharedLocks);

		virtual void get_ResponseContentType(std::string &OutResult);

		virtual void set_ResponseContentType(const std::string &Value);

		virtual bool get_MicrosoftCompatible();

		virtual void set_MicrosoftCompatible(bool Value);

		SB_DECLARE_PROPERTY(bool, get_MicrosoftCompatible, set_MicrosoftCompatible, TElWebDAVServer, MicrosoftCompatible);

		virtual void get_ServerName(std::string &OutResult);

		virtual void set_ServerName(const std::string &Value);

		virtual bool get_UseWellKnownURIs();

		virtual void set_UseWellKnownURIs(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseWellKnownURIs, set_UseWellKnownURIs, TElWebDAVServer, UseWellKnownURIs);

		virtual void get_OnGetSrpDb(TSBServerSrpDbNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetSrpDb(TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeRequest(TSBWebDavBeforeRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeRequest(TSBWebDavBeforeRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequest(TSBWebDavRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequest(TSBWebDavRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnResponse(TSBWebDavResponseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnResponse(TSBWebDavResponseEvent pMethodValue, void * pDataValue);

		virtual void get_OnStatusCode(TSBWebDavStatusCodeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStatusCode(TSBWebDavStatusCodeEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeUpload(TSBWebDavBeforeUploadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeUpload(TSBWebDavBeforeUploadEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeDownload(TSBWebDavBeforeDownloadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeDownload(TSBWebDavBeforeDownloadEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferFinished(TSBWebDavTransferFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferFinished(TSBWebDavTransferFinishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetUserPassword(TSBOnGetUserPasswordEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetUserPassword(TSBOnGetUserPasswordEvent pMethodValue, void * pDataValue);

		virtual void get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSBSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBServerKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBServerKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenegotiationStart(TSBRenegotiationStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenegotiationStart(TSBRenegotiationStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateURLs(TSBCertificateURLsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateURLs(TSBCertificateURLsEvent pMethodValue, void * pDataValue);

		TElWebDAVServer(TElWebDAVServerHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDAVServer(TComponent &AOwner);

		explicit TElWebDAVServer(TComponent *AOwner);

		virtual ~TElWebDAVServer();

};
#endif /* SB_USE_CLASS_TELWEBDAVSERVER */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
class SBWebDAVServer_TElWebDavPrincipal: public TObject
{
	private:
		SB_DISABLE_COPY(SBWebDAVServer_TElWebDavPrincipal)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AlternateURISet;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Groups;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AlternateURISet;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Groups;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		bool MemberOf(const std::string &URL);

		bool AddToGroup(SBWebDAVServer_TElWebDavPrincipal &Principal);

		bool AddToGroup(SBWebDAVServer_TElWebDavPrincipal *Principal);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual void get_DisplayName(std::string &OutResult);

		virtual void set_DisplayName(const std::string &Value);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AlternateURISet();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AlternateURISet, SBWebDAVServer_TElWebDavPrincipal, AlternateURISet);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AlternateURISet();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AlternateURISet, SBWebDAVServer_TElWebDavPrincipal, AlternateURISet);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Groups();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Groups, SBWebDAVServer_TElWebDavPrincipal, Groups);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Groups();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Groups, SBWebDAVServer_TElWebDavPrincipal, Groups);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_IsGroup();

		virtual void set_IsGroup(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsGroup, set_IsGroup, SBWebDAVServer_TElWebDavPrincipal, IsGroup);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual void get_ETag(std::string &OutResult);

		virtual void set_ETag(const std::string &Value);

		SBWebDAVServer_TElWebDavPrincipal(SBWebDAVServer_TElWebDavPrincipalHandle handle, TElOwnHandle ownHandle);

		SBWebDAVServer_TElWebDavPrincipal();

		virtual ~SBWebDAVServer_TElWebDavPrincipal();

};
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVINMEMORYPRINCIPAL
class TElWebDavInMemoryPrincipal: public SBWebDAVServer_TElWebDavPrincipal
{
	private:
		SB_DISABLE_COPY(TElWebDavInMemoryPrincipal)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AddressBookHomeSet;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_CalendarHomeSet;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AddressBookHomeSet;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_CalendarHomeSet;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AddressBookHomeSet();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AddressBookHomeSet, TElWebDavInMemoryPrincipal, AddressBookHomeSet);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AddressBookHomeSet();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AddressBookHomeSet, TElWebDavInMemoryPrincipal, AddressBookHomeSet);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CalendarHomeSet();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_CalendarHomeSet, TElWebDavInMemoryPrincipal, CalendarHomeSet);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CalendarHomeSet();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_CalendarHomeSet, TElWebDavInMemoryPrincipal, CalendarHomeSet);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElWebDavInMemoryPrincipal(TElWebDavInMemoryPrincipalHandle handle, TElOwnHandle ownHandle);

		TElWebDavInMemoryPrincipal();

		virtual ~TElWebDavInMemoryPrincipal();

};
#endif /* SB_USE_CLASS_TELWEBDAVINMEMORYPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND
class TElWebDavPrincipalBackend: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavPrincipalBackend)
	public:
		virtual void BeginRead();

		virtual void BeginWrite();

		virtual void Done();

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		virtual int64_t AddPrincipal(SBWebDAVServer_TElWebDavPrincipal &Principal);

		virtual int64_t AddPrincipal(SBWebDAVServer_TElWebDavPrincipal *Principal);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		virtual bool RemovePrincipal(SBWebDAVServer_TElWebDavPrincipal &Principal);

		virtual bool RemovePrincipal(SBWebDAVServer_TElWebDavPrincipal *Principal);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

		virtual bool RemovePrincipal(const std::string &URL);

		virtual bool PrincipalExists(const std::string &URL);

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		virtual SBWebDAVServer_TElWebDavPrincipalHandle FindPrincipalByURL(const std::string &URL);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		virtual SBWebDAVServer_TElWebDavPrincipalHandle FindPrincipalByName(const std::string &Name);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetGroupMemberSet(const std::string &URL, TStringList &List);

		virtual bool GetGroupMemberSet(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetGroupMemberSet(const std::string &URL, TElStringList &List);

		virtual bool GetGroupMemberSet(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetGroupMembership(const std::string &URL, TStringList &List);

		virtual bool GetGroupMembership(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetGroupMembership(const std::string &URL, TElStringList &List);

		virtual bool GetGroupMembership(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetPrincipalCollectionSet(const std::string &URL, TStringList &List);

		virtual bool GetPrincipalCollectionSet(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetPrincipalCollectionSet(const std::string &URL, TElStringList &List);

		virtual bool GetPrincipalCollectionSet(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetPrincipalAddressBookHomeSet(const std::string &URL, TStringList &List);

		virtual bool GetPrincipalAddressBookHomeSet(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetPrincipalAddressBookHomeSet(const std::string &URL, TElStringList &List);

		virtual bool GetPrincipalAddressBookHomeSet(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetPrincipalCalendarHomeSet(const std::string &URL, TStringList &List);

		virtual bool GetPrincipalCalendarHomeSet(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetPrincipalCalendarHomeSet(const std::string &URL, TElStringList &List);

		virtual bool GetPrincipalCalendarHomeSet(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool EnumPrincipals(const std::string &URL, TStringList &List);

		virtual bool EnumPrincipals(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool EnumPrincipals(const std::string &URL, TElStringList &List);

		virtual bool EnumPrincipals(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool CollectionExists(const std::string &URL);

		TElWebDavPrincipalBackend(TElWebDavPrincipalBackendHandle handle, TElOwnHandle ownHandle);

		TElWebDavPrincipalBackend();

};
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALMEMORYBACKEND
class TElWebDavPrincipalMemoryBackend: public TElWebDavPrincipalBackend
{
	private:
		SB_DISABLE_COPY(TElWebDavPrincipalMemoryBackend)
	public:
		virtual void BeginRead();

		virtual void BeginWrite();

		virtual void Done();

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		virtual int64_t AddPrincipal(SBWebDAVServer_TElWebDavPrincipal &Principal);

		virtual int64_t AddPrincipal(SBWebDAVServer_TElWebDavPrincipal *Principal);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		virtual bool RemovePrincipal(SBWebDAVServer_TElWebDavPrincipal &Principal);

		virtual bool RemovePrincipal(SBWebDAVServer_TElWebDavPrincipal *Principal);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

		virtual bool RemovePrincipal(const std::string &URL);

		virtual bool PrincipalExists(const std::string &URL);

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		virtual SBWebDAVServer_TElWebDavPrincipalHandle FindPrincipalByURL(const std::string &URL);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL
		virtual SBWebDAVServer_TElWebDavPrincipalHandle FindPrincipalByName(const std::string &Name);
#endif /* SB_USE_CLASS_SBWEBDAVSERVER_TELWEBDAVPRINCIPAL */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetGroupMemberSet(const std::string &URL, TStringList &List);

		virtual bool GetGroupMemberSet(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetGroupMemberSet(const std::string &URL, TElStringList &List);

		virtual bool GetGroupMemberSet(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetGroupMembership(const std::string &URL, TStringList &List);

		virtual bool GetGroupMembership(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetGroupMembership(const std::string &URL, TElStringList &List);

		virtual bool GetGroupMembership(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetPrincipalCollectionSet(const std::string &URL, TStringList &List);

		virtual bool GetPrincipalCollectionSet(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetPrincipalCollectionSet(const std::string &URL, TElStringList &List);

		virtual bool GetPrincipalCollectionSet(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetPrincipalAddressBookHomeSet(const std::string &URL, TStringList &List);

		virtual bool GetPrincipalAddressBookHomeSet(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetPrincipalAddressBookHomeSet(const std::string &URL, TElStringList &List);

		virtual bool GetPrincipalAddressBookHomeSet(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool GetPrincipalCalendarHomeSet(const std::string &URL, TStringList &List);

		virtual bool GetPrincipalCalendarHomeSet(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool GetPrincipalCalendarHomeSet(const std::string &URL, TElStringList &List);

		virtual bool GetPrincipalCalendarHomeSet(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual bool EnumPrincipals(const std::string &URL, TStringList &List);

		virtual bool EnumPrincipals(const std::string &URL, TStringList *List);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual bool EnumPrincipals(const std::string &URL, TElStringList &List);

		virtual bool EnumPrincipals(const std::string &URL, TElStringList *List);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_CardDAVPrefix(std::string &OutResult);

		virtual void set_CardDAVPrefix(const std::string &Value);

		virtual void get_CalDAVPrefix(std::string &OutResult);

		virtual void set_CalDAVPrefix(const std::string &Value);

		virtual void get_PrincipalBaseURL(std::string &OutResult);

		virtual void set_PrincipalBaseURL(const std::string &Value);

		virtual void get_GroupBaseURL(std::string &OutResult);

		virtual void set_GroupBaseURL(const std::string &Value);

		virtual void get_ContactFileName(std::string &OutResult);

		virtual void set_ContactFileName(const std::string &Value);

		TElWebDavPrincipalMemoryBackend(TElWebDavPrincipalMemoryBackendHandle handle, TElOwnHandle ownHandle);

		TElWebDavPrincipalMemoryBackend();

};
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALMEMORYBACKEND */

#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
class TElCalDavTextMatchFilter: public TElWebDavTextMatchFilter
{
	private:
		SB_DISABLE_COPY(TElCalDavTextMatchFilter)
	public:
		TElCalDavTextMatchFilter(TElCalDavTextMatchFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElCalDavTextMatchFilter(TElWebDavFilter &Parent);

		explicit TElCalDavTextMatchFilter(TElWebDavFilter *Parent);

};
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCALDAVPARAMFILTER
class TElCalDavParamFilter: public TElWebDavFilter
{
	private:
		SB_DISABLE_COPY(TElCalDavParamFilter)
#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
		TElCalDavTextMatchFilter* _Inst_TextMatch;
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual bool get_IsNotDefined();

		SB_DECLARE_PROPERTY_GET(bool, get_IsNotDefined, TElCalDavParamFilter, IsNotDefined);

#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
		virtual TElCalDavTextMatchFilter* get_TextMatch();

		SB_DECLARE_PROPERTY_GET(TElCalDavTextMatchFilter*, get_TextMatch, TElCalDavParamFilter, TextMatch);
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

		TElCalDavParamFilter(TElCalDavParamFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElCalDavParamFilter(TElWebDavFilter &Parent);

		explicit TElCalDavParamFilter(TElWebDavFilter *Parent);

		virtual ~TElCalDavParamFilter();

};
#endif /* SB_USE_CLASS_TELCALDAVPARAMFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGEBASE
class TElWebDavTimeRangeBase: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavTimeRangeBase)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		bool LoadFromXML(TElXMLDOMElement &Element);

		bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual int64_t get_Start();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Start, TElWebDavTimeRangeBase, Start);

		virtual int64_t get_End_();

		SB_DECLARE_PROPERTY_GET(int64_t, get_End_, TElWebDavTimeRangeBase, End_);

		TElWebDavTimeRangeBase(TElWebDavTimeRangeBaseHandle handle, TElOwnHandle ownHandle);

		TElWebDavTimeRangeBase();

};
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGEBASE */

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
class TElWebDavTimeRange: public TElWebDavTimeRangeBase
{
	private:
		SB_DISABLE_COPY(TElWebDavTimeRange)
	public:
		TElWebDavTimeRange(TElWebDavTimeRangeHandle handle, TElOwnHandle ownHandle);

		TElWebDavTimeRange();

};
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */

#ifdef SB_USE_CLASS_TELCALDAVPROPFILTER
class TElCalDavPropFilter: public TElWebDavFilter
{
	private:
		SB_DISABLE_COPY(TElCalDavPropFilter)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_SubFilters;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
		TElWebDavTimeRange* _Inst_TimeRange;
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */
#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
		TElCalDavTextMatchFilter* _Inst_TextMatch;
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_SubFilters();

		SB_DECLARE_PROPERTY_GET(TList*, get_SubFilters, TElCalDavPropFilter, SubFilters);
#endif /* SB_USE_CLASS_TLIST */

		virtual bool get_IsNotDefined();

		SB_DECLARE_PROPERTY_GET(bool, get_IsNotDefined, TElCalDavPropFilter, IsNotDefined);

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
		virtual TElWebDavTimeRange* get_TimeRange();

		SB_DECLARE_PROPERTY_GET(TElWebDavTimeRange*, get_TimeRange, TElCalDavPropFilter, TimeRange);
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */

#ifdef SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER
		virtual TElCalDavTextMatchFilter* get_TextMatch();

		SB_DECLARE_PROPERTY_GET(TElCalDavTextMatchFilter*, get_TextMatch, TElCalDavPropFilter, TextMatch);
#endif /* SB_USE_CLASS_TELCALDAVTEXTMATCHFILTER */

		TElCalDavPropFilter(TElCalDavPropFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElCalDavPropFilter(TElWebDavFilter &Parent);

		explicit TElCalDavPropFilter(TElWebDavFilter *Parent);

		virtual ~TElCalDavPropFilter();

};
#endif /* SB_USE_CLASS_TELCALDAVPROPFILTER */

#ifdef SB_USE_CLASS_TELCALDAVCOMPFILTER
class TElCalDAVCompFilter: public TElWebDavFilter
{
	private:
		SB_DISABLE_COPY(TElCalDAVCompFilter)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_SubFilters;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
		TElWebDavTimeRange* _Inst_TimeRange;
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_SubFilters();

		SB_DECLARE_PROPERTY_GET(TList*, get_SubFilters, TElCalDAVCompFilter, SubFilters);
#endif /* SB_USE_CLASS_TLIST */

		virtual bool get_IsNotDefined();

		SB_DECLARE_PROPERTY_GET(bool, get_IsNotDefined, TElCalDAVCompFilter, IsNotDefined);

#ifdef SB_USE_CLASS_TELWEBDAVTIMERANGE
		virtual TElWebDavTimeRange* get_TimeRange();

		SB_DECLARE_PROPERTY_GET(TElWebDavTimeRange*, get_TimeRange, TElCalDAVCompFilter, TimeRange);
#endif /* SB_USE_CLASS_TELWEBDAVTIMERANGE */

		TElCalDAVCompFilter(TElCalDAVCompFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElCalDAVCompFilter(TElWebDavFilter &Parent);

		explicit TElCalDAVCompFilter(TElWebDavFilter *Parent);

		virtual ~TElCalDAVCompFilter();

};
#endif /* SB_USE_CLASS_TELCALDAVCOMPFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVEXTENDEDREQUEST
class TElWebDavExtendedRequest: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavExtendedRequest)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Hrefs;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Hrefs;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual void get_ReportName(std::string &OutResult);

		virtual void set_ReportName(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Hrefs();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Hrefs, TElWebDavExtendedRequest, Hrefs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Hrefs();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Hrefs, TElWebDavExtendedRequest, Hrefs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_AllProp();

		virtual void set_AllProp(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllProp, set_AllProp, TElWebDavExtendedRequest, AllProp);

		virtual bool get_EvaluationResult();

		virtual void set_EvaluationResult(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EvaluationResult, set_EvaluationResult, TElWebDavExtendedRequest, EvaluationResult);

		TElWebDavExtendedRequest(TElWebDavExtendedRequestHandle handle, TElOwnHandle ownHandle);

		TElWebDavExtendedRequest();

		virtual ~TElWebDavExtendedRequest();

};
#endif /* SB_USE_CLASS_TELWEBDAVEXTENDEDREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVADDRESSBOOKREQUEST
class TElWebDavAddressBookRequest: public TElWebDavExtendedRequest
{
	private:
		SB_DISABLE_COPY(TElWebDavAddressBookRequest)
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_Filters;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Names;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Names;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TSBWebDavFilterTest get_Test();

		virtual void set_Test(TSBWebDavFilterTest Value);

		SB_DECLARE_PROPERTY(TSBWebDavFilterTest, get_Test, set_Test, TElWebDavAddressBookRequest, Test);

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_Filters();

		SB_DECLARE_PROPERTY_GET(TList*, get_Filters, TElWebDavAddressBookRequest, Filters);
#endif /* SB_USE_CLASS_TLIST */

		virtual int32_t get_Limit();

		virtual void set_Limit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Limit, set_Limit, TElWebDavAddressBookRequest, Limit);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Names();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Names, TElWebDavAddressBookRequest, Names);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Names();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Names, TElWebDavAddressBookRequest, Names);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElWebDavAddressBookRequest(TElWebDavAddressBookRequestHandle handle, TElOwnHandle ownHandle);

		TElWebDavAddressBookRequest();

		virtual ~TElWebDavAddressBookRequest();

};
#endif /* SB_USE_CLASS_TELWEBDAVADDRESSBOOKREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET
class TElWebDavLimitRecurrenceSet: public TElWebDavTimeRangeBase
{
	private:
		SB_DISABLE_COPY(TElWebDavLimitRecurrenceSet)
	public:
		TElWebDavLimitRecurrenceSet(TElWebDavLimitRecurrenceSetHandle handle, TElOwnHandle ownHandle);

		TElWebDavLimitRecurrenceSet();

};
#endif /* SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET */

#ifdef SB_USE_CLASS_TELWEBDAVEXPAND
class TElWebDavExpand: public TElWebDavTimeRangeBase
{
	private:
		SB_DISABLE_COPY(TElWebDavExpand)
	public:
		TElWebDavExpand(TElWebDavExpandHandle handle, TElOwnHandle ownHandle);

		TElWebDavExpand();

};
#endif /* SB_USE_CLASS_TELWEBDAVEXPAND */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET
class TElWebDavLimitFreeBusySet: public TElWebDavTimeRangeBase
{
	private:
		SB_DISABLE_COPY(TElWebDavLimitFreeBusySet)
	public:
		TElWebDavLimitFreeBusySet(TElWebDavLimitFreeBusySetHandle handle, TElOwnHandle ownHandle);

		TElWebDavLimitFreeBusySet();

};
#endif /* SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET */

#ifdef SB_USE_CLASS_TELWEBDAVCOMP
class TElWebDavComp: public TObject
{
	private:
		TElWebDavComp* _Inst_Parent;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Props;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Props;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_Comps;
#endif /* SB_USE_CLASS_TLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		bool LoadFromXML(TElXMLDOMElement &Element);

		bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElWebDavComp* get_Parent();

		SB_DECLARE_PROPERTY_GET(TElWebDavComp*, get_Parent, TElWebDavComp, Parent);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual bool get_AllProp();

		virtual void set_AllProp(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllProp, set_AllProp, TElWebDavComp, AllProp);

		virtual bool get_AllComp();

		virtual void set_AllComp(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllComp, set_AllComp, TElWebDavComp, AllComp);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Props();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Props, TElWebDavComp, Props);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Props();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Props, TElWebDavComp, Props);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_Comps();

		SB_DECLARE_PROPERTY_GET(TList*, get_Comps, TElWebDavComp, Comps);
#endif /* SB_USE_CLASS_TLIST */

		virtual void get_FullPath(std::string &OutResult);

		TElWebDavComp(TElWebDavCompHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDavComp(TElWebDavComp &Parent);

		explicit TElWebDavComp(TElWebDavComp *Parent);

		virtual ~TElWebDavComp();

};
#endif /* SB_USE_CLASS_TELWEBDAVCOMP */

#ifdef SB_USE_CLASS_TELWEBDAVCALENDARREQUEST
class TElWebDavCalendarRequest: public TElWebDavExtendedRequest
{
	private:
		SB_DISABLE_COPY(TElWebDavCalendarRequest)
#ifdef SB_USE_CLASS_TELCALDAVCOMPFILTER
		TElCalDAVCompFilter* _Inst_CompFilter;
#endif /* SB_USE_CLASS_TELCALDAVCOMPFILTER */
#ifdef SB_USE_CLASS_TELVCALENDAR
		TElVCalendar* _Inst_Timezone;
#endif /* SB_USE_CLASS_TELVCALENDAR */
#ifdef SB_USE_CLASS_TELWEBDAVCOMP
		TElWebDavComp* _Inst_Comp;
#endif /* SB_USE_CLASS_TELWEBDAVCOMP */
#ifdef SB_USE_CLASS_TELWEBDAVEXPAND
		TElWebDavExpand* _Inst_Expand;
#endif /* SB_USE_CLASS_TELWEBDAVEXPAND */
#ifdef SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET
		TElWebDavLimitRecurrenceSet* _Inst_LimitRecurrenceSet;
#endif /* SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET */
#ifdef SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET
		TElWebDavLimitFreeBusySet* _Inst_LimitFreebusySet;
#endif /* SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCALDAVCOMPFILTER
		virtual TElCalDAVCompFilter* get_CompFilter();

		SB_DECLARE_PROPERTY_GET(TElCalDAVCompFilter*, get_CompFilter, TElWebDavCalendarRequest, CompFilter);
#endif /* SB_USE_CLASS_TELCALDAVCOMPFILTER */

#ifdef SB_USE_CLASS_TELVCALENDAR
		virtual TElVCalendar* get_Timezone();

		SB_DECLARE_PROPERTY_GET(TElVCalendar*, get_Timezone, TElWebDavCalendarRequest, Timezone);
#endif /* SB_USE_CLASS_TELVCALENDAR */

#ifdef SB_USE_CLASS_TELWEBDAVCOMP
		virtual TElWebDavComp* get_Comp();

		SB_DECLARE_PROPERTY_GET(TElWebDavComp*, get_Comp, TElWebDavCalendarRequest, Comp);
#endif /* SB_USE_CLASS_TELWEBDAVCOMP */

#ifdef SB_USE_CLASS_TELWEBDAVEXPAND
		virtual TElWebDavExpand* get_Expand();

		SB_DECLARE_PROPERTY_GET(TElWebDavExpand*, get_Expand, TElWebDavCalendarRequest, Expand);
#endif /* SB_USE_CLASS_TELWEBDAVEXPAND */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET
		virtual TElWebDavLimitRecurrenceSet* get_LimitRecurrenceSet();

		SB_DECLARE_PROPERTY_GET(TElWebDavLimitRecurrenceSet*, get_LimitRecurrenceSet, TElWebDavCalendarRequest, LimitRecurrenceSet);
#endif /* SB_USE_CLASS_TELWEBDAVLIMITRECURRENCESET */

#ifdef SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET
		virtual TElWebDavLimitFreeBusySet* get_LimitFreebusySet();

		SB_DECLARE_PROPERTY_GET(TElWebDavLimitFreeBusySet*, get_LimitFreebusySet, TElWebDavCalendarRequest, LimitFreebusySet);
#endif /* SB_USE_CLASS_TELWEBDAVLIMITFREEBUSYSET */

		TElWebDavCalendarRequest(TElWebDavCalendarRequestHandle handle, TElOwnHandle ownHandle);

		TElWebDavCalendarRequest();

		virtual ~TElWebDavCalendarRequest();

};
#endif /* SB_USE_CLASS_TELWEBDAVCALENDARREQUEST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTY
class TElWebDavProperty: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavProperty)
	public:
		bool Write(const std::string &URL, const std::string &Value);

		bool Read(const std::string &URL, std::string &Value);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		bool Read(const std::string &URL, std::string &Value, TElXMLDOMElement &Element, TObject &Param);

		bool Read(const std::string &URL, std::string &Value, TElXMLDOMElement *Element, TObject *Param);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		bool Remove(const std::string &URL);

		virtual void get_NS(std::string &OutResult);

		virtual void get_Name(std::string &OutResult);

		virtual bool get_Live();

		SB_DECLARE_PROPERTY_GET(bool, get_Live, TElWebDavProperty, Live);

		virtual bool get_Protect();

		SB_DECLARE_PROPERTY_GET(bool, get_Protect, TElWebDavProperty, Protect);

		virtual bool get_AsXML();

		SB_DECLARE_PROPERTY_GET(bool, get_AsXML, TElWebDavProperty, AsXML);

		virtual bool get_PrincipalMatch();

		SB_DECLARE_PROPERTY_GET(bool, get_PrincipalMatch, TElWebDavProperty, PrincipalMatch);

		virtual bool get_Principal();

		SB_DECLARE_PROPERTY_GET(bool, get_Principal, TElWebDavProperty, Principal);

		virtual bool get_AddressBook();

		SB_DECLARE_PROPERTY_GET(bool, get_AddressBook, TElWebDavProperty, AddressBook);

		virtual bool get_Calendar();

		SB_DECLARE_PROPERTY_GET(bool, get_Calendar, TElWebDavProperty, Calendar);

		virtual bool get_Copy();

		SB_DECLARE_PROPERTY_GET(bool, get_Copy, TElWebDavProperty, Copy);

		virtual bool get_Search();

		virtual void set_Search(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Search, set_Search, TElWebDavProperty, Search);

		virtual void get_Description(std::string &OutResult);

		virtual void set_Description(const std::string &Value);

		virtual void get_DescLang(std::string &OutResult);

		virtual void set_DescLang(const std::string &Value);

		virtual void get_OnReadValue(TSBWebDavPropertyReadValueEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadValue(TSBWebDavPropertyReadValueEvent pMethodValue, void * pDataValue);

		virtual void get_OnReadExValue(TSBWebDavPropertyReadExValueEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadExValue(TSBWebDavPropertyReadExValueEvent pMethodValue, void * pDataValue);

		virtual void get_OnWriteValue(TSBWebDavPropertyWriteValueEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWriteValue(TSBWebDavPropertyWriteValueEvent pMethodValue, void * pDataValue);

		virtual void get_OnAfterReadValue(TSBWebDavPropertyAfterReadValueEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAfterReadValue(TSBWebDavPropertyAfterReadValueEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeWriteValue(TSBWebDavPropertyBeforeWriteValueEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeWriteValue(TSBWebDavPropertyBeforeWriteValueEvent pMethodValue, void * pDataValue);

		virtual void get_OnRemove(TSBWebDavPropertyRemoveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRemove(TSBWebDavPropertyRemoveEvent pMethodValue, void * pDataValue);

		TElWebDavProperty(TElWebDavPropertyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELWEBDAVSERVER
		TElWebDavProperty(TElWebDAVServer &Server, const std::string &NS, const std::string &Name, bool Live, bool Protect, bool AsXML, bool PrincipalMatch, bool Principal, bool AddressBook, bool Calendar, bool Copy);

		TElWebDavProperty(TElWebDAVServer *Server, const std::string &NS, const std::string &Name, bool Live, bool Protect, bool AsXML, bool PrincipalMatch, bool Principal, bool AddressBook, bool Calendar, bool Copy);
#endif /* SB_USE_CLASS_TELWEBDAVSERVER */

};
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTY */

#ifdef SB_USE_CLASS_TELWEBDAVIFSTATE
class TElWebDavIfState: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavIfState)
	public:
		virtual TSBWebDavIfStateType get_AType();

		SB_DECLARE_PROPERTY_GET(TSBWebDavIfStateType, get_AType, TElWebDavIfState, AType);

		virtual bool get_Condition();

		SB_DECLARE_PROPERTY_GET(bool, get_Condition, TElWebDavIfState, Condition);

		virtual void get_Value(std::string &OutResult);

		TElWebDavIfState(TElWebDavIfStateHandle handle, TElOwnHandle ownHandle);

		TElWebDavIfState(TSBWebDavIfStateType AType, bool Condition, const std::string &Value);

};
#endif /* SB_USE_CLASS_TELWEBDAVIFSTATE */

#ifdef SB_USE_CLASS_TELWEBDAVIFRESOURCE
class TElWebDavIfResource: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavIfResource)
#ifdef SB_USE_CLASS_TELWEBDAVIFSTATE
		TElWebDavIfState* _Inst_States;
#endif /* SB_USE_CLASS_TELWEBDAVIFSTATE */

		void initInstances();

	public:
		virtual void get_URI(std::string &OutResult);

#ifdef SB_USE_CLASS_TELWEBDAVIFSTATE
		virtual TElWebDavIfState* get_States(int32_t Idx);
#endif /* SB_USE_CLASS_TELWEBDAVIFSTATE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDavIfResource, Count);

		TElWebDavIfResource(TElWebDavIfResourceHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDavIfResource(const std::string &URI);

		virtual ~TElWebDavIfResource();

};
#endif /* SB_USE_CLASS_TELWEBDAVIFRESOURCE */

#ifdef SB_USE_CLASS_TELWEBDAVIFHEADER
class TElWebDAVIfHeader: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDAVIfHeader)
#ifdef SB_USE_CLASS_TELWEBDAVIFRESOURCE
		TElWebDavIfResource* _Inst_Resources;
#endif /* SB_USE_CLASS_TELWEBDAVIFRESOURCE */

		void initInstances();

	public:
		bool Process(const std::string &S);

		virtual void get_URL(std::string &OutResult);

#ifdef SB_USE_CLASS_TELWEBDAVIFRESOURCE
		virtual TElWebDavIfResource* get_Resources(int32_t Idx);
#endif /* SB_USE_CLASS_TELWEBDAVIFRESOURCE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDAVIfHeader, Count);

		TElWebDAVIfHeader(TElWebDAVIfHeaderHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDAVIfHeader(const std::string &URL);

		virtual ~TElWebDAVIfHeader();

};
#endif /* SB_USE_CLASS_TELWEBDAVIFHEADER */

#ifdef SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST
class TElWebDAVCustomLockList: public TComponent
{
	private:
		SB_DISABLE_COPY(TElWebDAVCustomLockList)
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		TElWebDAVLock* _Inst_Locks;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		void initInstances();

	public:
		virtual void Enter(bool ReadOnly);

		virtual void Done();

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual void Add(const TElWebDAVLock &Lock);

		virtual void Add(const TElWebDAVLock *Lock);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual void Remove(const TElWebDAVLock &Lock);

		virtual void Remove(const TElWebDAVLock *Lock);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLockHandle Find(const std::string &Token);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TLIST
		virtual TListHandle FindAll(const std::string &URL);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLockHandle FindFirst(TObject &Handle, const std::string &URL);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLockHandle FindNext(TObject &Handle);

		virtual TElWebDAVLockHandle FindNext(TObject *Handle);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		virtual void FindClose(TObject &Handle);

		virtual void FindClose(TObject *Handle);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void LoadFromStream(TStream &Stream, bool Clear);

		virtual void LoadFromStream(TStream *Stream, bool Clear);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveToStream(TStream &Stream);

		virtual void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLock* get_Locks(int32_t Idx);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDAVCustomLockList, Count);

		TElWebDAVCustomLockList(TElWebDAVCustomLockListHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDAVCustomLockList(TComponent &AOwner);

		explicit TElWebDAVCustomLockList(TComponent *AOwner);

		virtual ~TElWebDAVCustomLockList();

};
#endif /* SB_USE_CLASS_TELWEBDAVCUSTOMLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVFINDMEMORYLOCKHANDLE
class TElWebDavFindMemoryLockHandle: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavFindMemoryLockHandle)
	public:
		TElWebDavFindMemoryLockHandle(TElWebDavFindMemoryLockHandleHandle handle, TElOwnHandle ownHandle);

		TElWebDavFindMemoryLockHandle();

};
#endif /* SB_USE_CLASS_TELWEBDAVFINDMEMORYLOCKHANDLE */

#ifdef SB_USE_CLASS_TELWEBDAVMEMORYLOCKLIST
class TElWebDAVMemoryLockList: public TElWebDAVCustomLockList
{
	private:
		SB_DISABLE_COPY(TElWebDAVMemoryLockList)
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		TElWebDAVLock* _Inst_Locks;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		void initInstances();

	public:
		virtual void Enter(bool ReadOnly);

		virtual void Done();

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual void Add(const TElWebDAVLock &Lock);

		virtual void Add(const TElWebDAVLock *Lock);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual void Remove(const TElWebDAVLock &Lock);

		virtual void Remove(const TElWebDAVLock *Lock);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLockHandle Find(const std::string &Token);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TLIST
		virtual TListHandle FindAll(const std::string &URL);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLockHandle FindFirst(TObject &Handle, const std::string &URL);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLockHandle FindNext(TObject &Handle);

		virtual TElWebDAVLockHandle FindNext(TObject *Handle);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		virtual void FindClose(TObject &Handle);

		virtual void FindClose(TObject *Handle);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void LoadFromStream(TStream &Stream, bool Clear);

		virtual void LoadFromStream(TStream *Stream, bool Clear);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveToStream(TStream &Stream);

		virtual void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t Cleanup();

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLock* get_Locks(int32_t Idx);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDAVMemoryLockList, Count);

		TElWebDAVMemoryLockList(TElWebDAVMemoryLockListHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDAVMemoryLockList(TComponent &AOwner);

		explicit TElWebDAVMemoryLockList(TComponent *AOwner);

		virtual ~TElWebDAVMemoryLockList();

};
#endif /* SB_USE_CLASS_TELWEBDAVMEMORYLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVACLOPTIONS
class TElWebDAVACLOptions: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDAVACLOptions)
#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND
		TElWebDavPrincipalBackend* _Inst_PrincipalBackend;
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND */

		void initInstances();

	public:
		virtual bool get_UseACL();

		virtual void set_UseACL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseACL, set_UseACL, TElWebDAVACLOptions, UseACL);

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND
		virtual TElWebDavPrincipalBackend* get_PrincipalBackend();

		virtual void set_PrincipalBackend(TElWebDavPrincipalBackend &Value);

		virtual void set_PrincipalBackend(TElWebDavPrincipalBackend *Value);

		SB_DECLARE_PROPERTY(TElWebDavPrincipalBackend*, get_PrincipalBackend, set_PrincipalBackend, TElWebDAVACLOptions, PrincipalBackend);
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALBACKEND */

		virtual void get_AbstractPrivileges(std::vector<int16_t> &OutResult);

		virtual void set_AbstractPrivileges(const std::vector<int16_t> &Value);

		virtual int32_t get_MatchingPrincipalsLimit();

		virtual void set_MatchingPrincipalsLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MatchingPrincipalsLimit, set_MatchingPrincipalsLimit, TElWebDAVACLOptions, MatchingPrincipalsLimit);

		virtual void get_OnReadCurrentUserPrivileges(TSBWebDavReadPrivilegesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadCurrentUserPrivileges(TSBWebDavReadPrivilegesEvent pMethodValue, void * pDataValue);

		virtual void get_OnReadSupportedPrivileges(TSBWebDavReadSupportedPrivilegesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadSupportedPrivileges(TSBWebDavReadSupportedPrivilegesEvent pMethodValue, void * pDataValue);

		virtual void get_OnReadOwner(TSBWebDavReadOwnerEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadOwner(TSBWebDavReadOwnerEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetPrivilegeDescription(TSBWebDavGetPrivilegeDescriptionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetPrivilegeDescription(TSBWebDavGetPrivilegeDescriptionEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetACLRestrictions(TSBWebDavGetACLRestrictionsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetACLRestrictions(TSBWebDavGetACLRestrictionsEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetACL(TSBWebDavGetACLEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetACL(TSBWebDavGetACLEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetACL(TSBWebDavSetACLEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetACL(TSBWebDavSetACLEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetInheritedACLSet(TSBWebDavGetURLSetEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetInheritedACLSet(TSBWebDavGetURLSetEvent pMethodValue, void * pDataValue);

		TElWebDAVACLOptions(TElWebDAVACLOptionsHandle handle, TElOwnHandle ownHandle);

		TElWebDAVACLOptions();

		virtual ~TElWebDAVACLOptions();

};
#endif /* SB_USE_CLASS_TELWEBDAVACLOPTIONS */

#ifdef SB_USE_CLASS_TELCARDDAVOPTIONS
class TElCardDAVOptions: public TObject
{
	private:
		SB_DISABLE_COPY(TElCardDAVOptions)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AddressBookURLs;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AddressBookURLs;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual bool get_UseCardDAV();

		virtual void set_UseCardDAV(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCardDAV, set_UseCardDAV, TElCardDAVOptions, UseCardDAV);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AddressBookURLs();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AddressBookURLs, TElCardDAVOptions, AddressBookURLs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AddressBookURLs();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AddressBookURLs, TElCardDAVOptions, AddressBookURLs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual int32_t get_MaxResourceSize();

		virtual void set_MaxResourceSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxResourceSize, set_MaxResourceSize, TElCardDAVOptions, MaxResourceSize);

		virtual int32_t get_NumberOfMatchesLimit();

		virtual void set_NumberOfMatchesLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_NumberOfMatchesLimit, set_NumberOfMatchesLimit, TElCardDAVOptions, NumberOfMatchesLimit);

		virtual bool get_AllowExtendedMkCol();

		virtual void set_AllowExtendedMkCol(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowExtendedMkCol, set_AllowExtendedMkCol, TElCardDAVOptions, AllowExtendedMkCol);

		virtual void get_OnCheckIfAddressBook(TSBWebDavCheckIfAddressBookEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCheckIfAddressBook(TSBWebDavCheckIfAddressBookEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetAsAddressBook(TSBWebDavSetAsAddressBookEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetAsAddressBook(TSBWebDavSetAsAddressBookEvent pMethodValue, void * pDataValue);

		virtual void get_OnCheckUIDUniqueness(TSBCheckUIDUniquenessEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCheckUIDUniqueness(TSBCheckUIDUniquenessEvent pMethodValue, void * pDataValue);

		TElCardDAVOptions(TElCardDAVOptionsHandle handle, TElOwnHandle ownHandle);

		TElCardDAVOptions();

		virtual ~TElCardDAVOptions();

};
#endif /* SB_USE_CLASS_TELCARDDAVOPTIONS */

#ifdef SB_USE_CLASS_TELCALDAVOPTIONS
class TElCalDAVOptions: public TObject
{
	private:
		SB_DISABLE_COPY(TElCalDAVOptions)
	public:
		virtual bool get_UseCalDAV();

		virtual void set_UseCalDAV(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCalDAV, set_UseCalDAV, TElCalDAVOptions, UseCalDAV);

		virtual int32_t get_MaxResourceSize();

		virtual void set_MaxResourceSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxResourceSize, set_MaxResourceSize, TElCalDAVOptions, MaxResourceSize);

		virtual int64_t get_MinDateTime();

		virtual void set_MinDateTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MinDateTime, set_MinDateTime, TElCalDAVOptions, MinDateTime);

		virtual int64_t get_MaxDateTime();

		virtual void set_MaxDateTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MaxDateTime, set_MaxDateTime, TElCalDAVOptions, MaxDateTime);

		virtual int32_t get_MaxRecurrenceInstances();

		virtual void set_MaxRecurrenceInstances(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxRecurrenceInstances, set_MaxRecurrenceInstances, TElCalDAVOptions, MaxRecurrenceInstances);

		virtual int32_t get_MaxAttendeesPerInstance();

		virtual void set_MaxAttendeesPerInstance(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxAttendeesPerInstance, set_MaxAttendeesPerInstance, TElCalDAVOptions, MaxAttendeesPerInstance);

		virtual void get_OnCheckIfCalendar(TSBWebDavCheckIfCalendarEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCheckIfCalendar(TSBWebDavCheckIfCalendarEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetAsCalendar(TSBWebDavSetAsCalendarEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetAsCalendar(TSBWebDavSetAsCalendarEvent pMethodValue, void * pDataValue);

		virtual void get_OnCheckUIDUniqueness(TSBCheckUIDUniquenessEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCheckUIDUniqueness(TSBCheckUIDUniquenessEvent pMethodValue, void * pDataValue);

		TElCalDAVOptions(TElCalDAVOptionsHandle handle, TElOwnHandle ownHandle);

		TElCalDAVOptions();

};
#endif /* SB_USE_CLASS_TELCALDAVOPTIONS */

#ifdef SB_USE_CLASS_TELWEBDAVCOLLATION
class TElWebDavCollation: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavCollation)
	public:
		static TElWebDavCollationHandle CreateInstance(TSBWebDavFilterTextMatchCollation Collation);

		TElWebDavCollationHandle CreateInstance_Inst(TSBWebDavFilterTextMatchCollation Collation);

		virtual int32_t Compare(const std::string &S1, const std::string &S2);

		virtual bool StartsWith(const std::string &S, const std::string &SubS);

		virtual bool EndsWith(const std::string &S, const std::string &SubS);

		virtual bool Equals(const std::string &S1, const std::string &S2);

		virtual int32_t IndexOf(const std::string &S, const std::string &SubS);

		TElWebDavCollation(TElWebDavCollationHandle handle, TElOwnHandle ownHandle);

		TElWebDavCollation();

};
#endif /* SB_USE_CLASS_TELWEBDAVCOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVUNICODECOLLATION
class TElWebDavUnicodeCollation: public TElWebDavCollation
{
	private:
		SB_DISABLE_COPY(TElWebDavUnicodeCollation)
	public:
		virtual int32_t Compare(const std::string &S1, const std::string &S2);

		virtual bool StartsWith(const std::string &S, const std::string &SubS);

		virtual bool EndsWith(const std::string &S, const std::string &SubS);

		virtual bool Equals(const std::string &S1, const std::string &S2);

		virtual int32_t IndexOf(const std::string &S, const std::string &SubS);

		TElWebDavUnicodeCollation(TElWebDavUnicodeCollationHandle handle, TElOwnHandle ownHandle);

		TElWebDavUnicodeCollation();

};
#endif /* SB_USE_CLASS_TELWEBDAVUNICODECOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVASCIICOLLATION
class TElWebDavAsciiCollation: public TElWebDavCollation
{
	private:
		SB_DISABLE_COPY(TElWebDavAsciiCollation)
	public:
		virtual int32_t Compare(const std::string &S1, const std::string &S2);

		virtual bool StartsWith(const std::string &S, const std::string &SubS);

		virtual bool EndsWith(const std::string &S, const std::string &SubS);

		virtual bool Equals(const std::string &S1, const std::string &S2);

		virtual int32_t IndexOf(const std::string &S, const std::string &SubS);

		TElWebDavAsciiCollation(TElWebDavAsciiCollationHandle handle, TElOwnHandle ownHandle);

		TElWebDavAsciiCollation();

};
#endif /* SB_USE_CLASS_TELWEBDAVASCIICOLLATION */

#ifdef SB_USE_CLASS_TELWEBDAVOCTETCOLLATION
class TElWebDavOctetCollation: public TElWebDavCollation
{
	private:
		SB_DISABLE_COPY(TElWebDavOctetCollation)
	public:
		virtual int32_t Compare(const std::string &S1, const std::string &S2);

		virtual bool StartsWith(const std::string &S, const std::string &SubS);

		virtual bool EndsWith(const std::string &S, const std::string &SubS);

		virtual bool Equals(const std::string &S1, const std::string &S2);

		virtual int32_t IndexOf(const std::string &S, const std::string &SubS);

		TElWebDavOctetCollation(TElWebDavOctetCollationHandle handle, TElOwnHandle ownHandle);

		TElWebDavOctetCollation();

};
#endif /* SB_USE_CLASS_TELWEBDAVOCTETCOLLATION */

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVSERVER

#ifdef SB_USE_CLASSES_TELWEBDAVLOCK_AND_TLIST
TElWebDAVLockHandle FindLockInList(const TList &List, const std::string &Token);
TElWebDAVLockHandle FindLockInList(const TList *List, const std::string &Token);
#endif /* SB_USE_CLASSES_TELWEBDAVLOCK_AND_TLIST */

#endif /* SB_USE_GLOBAL_PROCS_WEBDAVSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVSERVER
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVServer_FindLockInList(const TListHandle List, const char * pcToken, int32_t szToken, TElWebDAVLockHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_WEBDAVSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWEBDAVSERVER */
