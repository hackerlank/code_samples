#ifndef __INC_SBWEBDAVCOMMON
#define __INC_SBWEBDAVCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbencoding.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsharedresource.h"
#include "sbhttpscommon.h"
#include "sbstringlist.h"
#include "sbxmldefs.h"
#include "sbxmlutils.h"
#include "sbxmlcore.h"
#include "sbxmlcharsets.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SNotImplemented 	"Not implemented"
#ifndef SB_SInternalError
#define SB_SInternalError 	"Internal error"
#endif
#define SB_SNotAllPropertiesSet 	"Not all standard WebDav property classes set"
#define SB_SNotAllPropertyHandlersSet 	"Not all WebDav property handlers set"
#define SB_SFSAdapterNotSet 	"FileSystemAdapter property is not set"
#define SB_SFSAdapterEventsNotSet 	"FileSystemAdapter events are not set"
#define SB_SInvalidDepthParameter 	"Invalid depth parameter"
#define SB_SInvalidMethodParameters 	"Invalid method parameters"
#define SB_SInvalidScopeParameter 	"Invalid scope parameter"
#define SB_SInvalidXML 	"Invalid XML structure"
#define SB_SInvalidLocksXML 	"Invalid serialized XML structure"
#define SB_SCollectionExpected 	"Collection object or URL is expected as a parameter"
#define SB_SDocumentExpected 	"Document object or URL is expected as a parameter"
#define SB_SInvalidTimeout 	"Invalid timeout"
#define SB_SHttpError 	"HTTP error"
#define SB_SWrongFileSize 	"Can not read file size"
#define SB_SResumeOffsetTooLarge 	"Resume offset is too large"
#define SB_SErrorStatusCode 	"Status code error: %s"
#define SB_SUsernameNotFound 	"Username not found"
#define SB_SGroupNotFound 	"Group name not found"
#define SB_SPreconditionError 	"Precondition error"
#define SB_SVCardContentType 	"text/vcard"
#define SB_SResourceAlreadyExistsOrProtected 	"Resource already exists or is protected"
#define SB_SFileSystemError 	"File system error: %s"
#define SB_wdpcRead 	1
#define SB_wdpcWrite 	2
#define SB_wdpcAll 	4
#define SB_wdpcCalReadFreeBusy 	2048
#define SB_WEBDAV_DEFAULT_PROPERTY_NAMESPACE 	"DAV:"
#define SB_CARDDAV_DEFAULT_PROPERTY_NAMESPACE 	"urn:ietf:params:xml:ns:carddav"
#define SB_CALDAV_DEFAULT_PROPERTY_NAMESPACE 	"urn:ietf:params:xml:ns:caldav"
#define SB_WEBDAV_LOCK_INFINITE_TIMEOUT 	0
#define SB_WEBDAV_LOCK_TOKEN_LEN 	32
#define SB_WEBDAV_ETAG_LEN 	20
#define SB_WEBDAV_IF_HEADER_MAX_RESOURCES 	256
#define SB_WEBDAV_ERROR_INVALID_XML 	0
#define SB_WEBDAV_ERROR_INVALID_DEPTH 	1
#define SB_WEBDAV_ERROR_INVALID_SCOPE 	2
#define SB_WEBDAV_ERROR_INVALID_TIMEOUT 	3
#define SB_WEBDAV_ERROR_INVALID_LOCKS_XML 	4
#define SB_WEBDAV_PRECOND_ERROR_SUPPORTED_COLLATION 	5
#define SB_WEBDAV_ERROR_RESOUCE_EXISTS_OR_PROTECTED 	6
#define SB_WEBDAV_ERROR_FILESYSTEM 	7
#define SB_WEBDAV_ERROR_INTERNAL 	8
#define SB_WEBDAV_PROPERTY_FIRST 	1
#define SB_WEBDAV_PROPERTY_LAST 	10
#define SB_WEBDAV_PROTECTED_PROPERTY_FIRST 	1
#define SB_WEBDAV_PROTECTED_PROPERTY_LAST 	19
#define SB_WEBDAV_ACL_PROPERTY_FIRST 	1
#define SB_WEBDAV_ACL_PROPERTY_LAST 	12
#define SB_WEBDAV_PRINCIPAL_PROPERTY_FIRST 	1
#define SB_WEBDAV_PRINCIPAL_PROPERTY_LAST 	3

typedef TElClassHandle TElWebDavPropertyInfoHandle;

typedef TElWebDavPropertyInfoHandle ElWebDavPropertyInfoHandle;

typedef TElClassHandle TElWebDavPropertyInfoListHandle;

typedef TElWebDavPropertyInfoListHandle ElWebDavPropertyInfoListHandle;

typedef TElClassHandle TElWebDavNamespacePrefixMapHandle;

typedef TElWebDavNamespacePrefixMapHandle ElWebDavNamespacePrefixMapHandle;

typedef TElClassHandle TElWebDAVLockHandle;

typedef TElWebDAVLockHandle ElWebDAVLockHandle;

typedef TElClassHandle TElWebDavFilterHandle;

typedef TElClassHandle TElWebDavTextMatchFilterHandle;

typedef TElClassHandle TElCardDavTextMatchFilterHandle;

typedef TElClassHandle TElCardDavPropFilterHandle;

typedef TElClassHandle TElCardDavFilterHandle;

typedef TElClassHandle TElCardDavParamFilterHandle;

typedef TElClassHandle TElWebDavACEHandle;

typedef TElClassHandle TElWebDavACLHandle;

typedef TElClassHandle TElWebDavACLRestrictionsHandle;

typedef uint8_t TSBWebDavDepthRaw;

typedef enum
{
	wddZero = 0,
	wddOne = 1,
	wddInfinity = 2
} TSBWebDavDepth;

typedef uint8_t TSBWebDavLockScopeRaw;

typedef enum
{
	wlsExclusive = 0,
	wlsShared = 1
} TSBWebDavLockScope;

typedef uint8_t TSBWebDavFilterTestRaw;

typedef enum
{
	wdftAnyOf = 0,
	wdftAllOf = 1
} TSBWebDavFilterTest;

typedef uint8_t TSBWebDavFilterTextMatchCollationRaw;

typedef enum
{
	wdfcAscii = 0,
	wdfcUnicode = 1,
	wdfcOctet = 2
} TSBWebDavFilterTextMatchCollation;

typedef uint8_t TSBWebDavFilterTextMatchTypeRaw;

typedef enum
{
	wdfmEquals = 0,
	wdfmContains = 1,
	wdfmStartsWith = 2,
	wdfmEndsWith = 3
} TSBWebDavFilterTextMatchType;

typedef uint8_t TSBPrincipalTypeRaw;

typedef enum
{
	wptNone = 0,
	wptAll = 1,
	wptAuthenticated = 2,
	wptUnauthenticated = 3,
	wptSelf = 4,
	wptHref = 5,
	wptProperty = 6,
	wptPropertyOwner = 7,
	wptPropertyGroup = 8
} TSBPrincipalType;

typedef uint8_t TSBWebDavACLErrorRaw;

typedef enum
{
	waeNone = 0,
	waeNoACEConflict = 1,
	waeNoProtectedACEConflict = 2,
	waeNoInheritedACEConflict = 3,
	waeLimitedNumberOfACEs = 4,
	waeDenyBeforeGrant = 5,
	waeGrantOnly = 6,
	waeNoInvert = 7,
	waeNoAbstract = 8,
	waeNoSupportedPrivilege = 9,
	waeMissingRequiredPrincipal = 10,
	waeRecognizedPrincipal = 11,
	wasAllowedPrincipal = 12
} TSBWebDavACLError;

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_Clone(TElWebDavPropertyInfoHandle _Handle, TElWebDavPropertyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_get_Inited(TElWebDavPropertyInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_set_Inited(TElWebDavPropertyInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_get_NS(TElWebDavPropertyInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_set_NS(TElWebDavPropertyInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_get_Name(TElWebDavPropertyInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_set_Name(TElWebDavPropertyInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_get_Value(TElWebDavPropertyInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_set_Value(TElWebDavPropertyInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_get_Status(TElWebDavPropertyInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_set_Status(TElWebDavPropertyInfoHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_get_Hrefs(TElWebDavPropertyInfoHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_get_Hrefs(TElWebDavPropertyInfoHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_get_Description(TElWebDavPropertyInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_set_Description(TElWebDavPropertyInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfo_Create(const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue, TElWebDavPropertyInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfoList_Clear(TElWebDavPropertyInfoListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfoList_Add(TElWebDavPropertyInfoListHandle _Handle, const TElWebDavPropertyInfoHandle PropInfo);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfoList_Remove(TElWebDavPropertyInfoListHandle _Handle, const TElWebDavPropertyInfoHandle PropInfo);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfoList_Find(TElWebDavPropertyInfoListHandle _Handle, const char * pcNS, int32_t szNS, const char * pcName, int32_t szName, TElWebDavPropertyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfoList_get_Count(TElWebDavPropertyInfoListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfoList_get_Item(TElWebDavPropertyInfoListHandle _Handle, int32_t index, TElWebDavPropertyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPropertyInfoList_Create(TElWebDavPropertyInfoListHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASS_TELWEBDAVNAMESPACEPREFIXMAP
SB_IMPORT uint32_t SB_APIENTRY TElWebDavNamespacePrefixMap_Clear(TElWebDavNamespacePrefixMapHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavNamespacePrefixMap_AddNS(TElWebDavNamespacePrefixMapHandle _Handle, const char * pcNS, int32_t szNS);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavNamespacePrefixMap_RemoveNS(TElWebDavNamespacePrefixMapHandle _Handle, const char * pcNS, int32_t szNS);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavNamespacePrefixMap_GetPrefix(TElWebDavNamespacePrefixMapHandle _Handle, const char * pcNS, int32_t szNS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavNamespacePrefixMap_Create(int8_t WithDAV, TElWebDavNamespacePrefixMapHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVNAMESPACEPREFIXMAP */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_TimeoutToString(int32_t Timeout, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_TimeoutToString_1(TElWebDAVLockHandle _Handle, int32_t Timeout, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_StringToTimeout(const char * pcS, int32_t szS, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_StringToTimeout_1(TElWebDAVLockHandle _Handle, const char * pcS, int32_t szS, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_ReadTokenFromXML(TStreamHandle Strm, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_ReadTokenFromXML_1(TElWebDAVLockHandle _Handle, TStreamHandle Strm, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_LoadFromXML(TElXMLDOMElementHandle Elem, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_LoadFromXML_1(TElWebDAVLockHandle _Handle, TElXMLDOMElementHandle Elem, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_Clone(TElWebDAVLockHandle _Handle, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_ToXML(TElWebDAVLockHandle _Handle, int8_t WithToken, const char * pcNS, int32_t szNS, int8_t EncodeURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_SaveToXML(TElWebDAVLockHandle _Handle, const TElXMLDOMDocumentHandle Doc, const TElXMLDOMNodeHandle Base, int8_t WithToken, int8_t EncodeURL);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_LocksURL(TElWebDAVLockHandle _Handle, const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_CompatibleWith(TElWebDAVLockHandle _Handle, const TElWebDAVLockHandle Lock, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_ConflictsWith(TElWebDAVLockHandle _Handle, const TElWebDAVLockHandle Lock, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_Refresh(TElWebDAVLockHandle _Handle, int64_t Timeout);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_Unlock(TElWebDAVLockHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_BeginUse(TElWebDAVLockHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_EndUse(TElWebDAVLockHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_ToString(TElWebDAVLockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_URL(TElWebDAVLockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_Owner(TElWebDAVLockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_Token(TElWebDAVLockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_Scope(TElWebDAVLockHandle _Handle, TSBWebDavLockScopeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_Depth(TElWebDAVLockHandle _Handle, TSBWebDavDepthRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_TTL(TElWebDAVLockHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_Timeout(TElWebDAVLockHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_UnlockTime(TElWebDAVLockHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_Unlocked(TElWebDAVLockHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_InUse(TElWebDAVLockHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_get_ToIfHeader(TElWebDAVLockHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLock_Create(const char * pcURL, int32_t szURL, const char * pcOwner, int32_t szOwner, TSBWebDavLockScopeRaw Scope, TSBWebDavDepthRaw Depth, int64_t Timeout, const char * pcToken, int32_t szToken, TElWebDAVLockHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVFILTER
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_LoadFromXML(TElWebDavFilterHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_SaveToXML(TElWebDavFilterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_get_Parent(TElWebDavFilterHandle _Handle, TElWebDavFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_set_Parent(TElWebDavFilterHandle _Handle, TElWebDavFilterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_get_Name(TElWebDavFilterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_set_Name(TElWebDavFilterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_get_FullPath(TElWebDavFilterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_get_Empty(TElWebDavFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavFilter_Create(TElWebDavFilterHandle Parent, TElWebDavFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVTEXTMATCHFILTER
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_LoadFromXML(TElWebDavTextMatchFilterHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_SaveToXML(TElWebDavTextMatchFilterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_get_Collation(TElWebDavTextMatchFilterHandle _Handle, TSBWebDavFilterTextMatchCollationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_set_Collation(TElWebDavTextMatchFilterHandle _Handle, TSBWebDavFilterTextMatchCollationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_get_MatchType(TElWebDavTextMatchFilterHandle _Handle, TSBWebDavFilterTextMatchTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_set_MatchType(TElWebDavTextMatchFilterHandle _Handle, TSBWebDavFilterTextMatchTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_get_NegateCondition(TElWebDavTextMatchFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_set_NegateCondition(TElWebDavTextMatchFilterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_get_Value(TElWebDavTextMatchFilterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_set_Value(TElWebDavTextMatchFilterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavTextMatchFilter_Create(TElWebDavFilterHandle Parent, TElWebDavTextMatchFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER
SB_IMPORT uint32_t SB_APIENTRY TElCardDavTextMatchFilter_Create(TElWebDavFilterHandle Parent, TElCardDavTextMatchFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_LoadFromXML(TElCardDavPropFilterHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_SaveToXML(TElCardDavPropFilterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_AddSubFilter(TElCardDavPropFilterHandle _Handle, TElWebDavFilterHandle Filter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_RemoveSubFilter(TElCardDavPropFilterHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_get_Test(TElCardDavPropFilterHandle _Handle, TSBWebDavFilterTestRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_set_Test(TElCardDavPropFilterHandle _Handle, TSBWebDavFilterTestRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_get_IsNotDefined(TElCardDavPropFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_set_IsNotDefined(TElCardDavPropFilterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_get_SubFilterCount(TElCardDavPropFilterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_get_SubFilters(TElCardDavPropFilterHandle _Handle, int32_t Index, TElWebDavFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavPropFilter_Create(TElWebDavFilterHandle Parent, TElCardDavPropFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVFILTER
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_LoadFromXML(TElCardDavFilterHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_SaveToXML(TElCardDavFilterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_AddPropFilter(TElCardDavFilterHandle _Handle, TElCardDavPropFilterHandle PropFilter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_RemovePropFilter(TElCardDavFilterHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_get_Test(TElCardDavFilterHandle _Handle, TSBWebDavFilterTestRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_set_Test(TElCardDavFilterHandle _Handle, TSBWebDavFilterTestRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_get_PropFilterCount(TElCardDavFilterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_get_PropFilters(TElCardDavFilterHandle _Handle, int32_t Index, TElCardDavPropFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavFilter_Create(TElCardDavFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCARDDAVFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVPARAMFILTER
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_LoadFromXML(TElCardDavParamFilterHandle _Handle, TElXMLDOMElementHandle Element, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_SaveToXML(TElCardDavParamFilterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_get_TextMatch(TElCardDavParamFilterHandle _Handle, TElCardDavTextMatchFilterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_set_TextMatch(TElCardDavParamFilterHandle _Handle, TElCardDavTextMatchFilterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_get_OwnTextMatch(TElCardDavParamFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_set_OwnTextMatch(TElCardDavParamFilterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_get_IsNotDefined(TElCardDavParamFilterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_set_IsNotDefined(TElCardDavParamFilterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavParamFilter_Create(TElWebDavFilterHandle Parent, TElCardDavParamFilterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCARDDAVPARAMFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVACE
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_LoadFromXML(TElWebDavACEHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_SaveToXML(TElWebDavACEHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get_PrincipalType(TElWebDavACEHandle _Handle, TSBPrincipalTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set_PrincipalType(TElWebDavACEHandle _Handle, TSBPrincipalTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get_Value(TElWebDavACEHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set_Value(TElWebDavACEHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get__Property(TElWebDavACEHandle _Handle, TElWebDavPropertyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set__Property(TElWebDavACEHandle _Handle, TElWebDavPropertyInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get_Invert(TElWebDavACEHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set_Invert(TElWebDavACEHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get__Protected(TElWebDavACEHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set__Protected(TElWebDavACEHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get__Inherited(TElWebDavACEHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set__Inherited(TElWebDavACEHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get_InheritedHref(TElWebDavACEHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set_InheritedHref(TElWebDavACEHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get_Grant(TElWebDavACEHandle _Handle, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set_Grant(TElWebDavACEHandle _Handle, int16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_get_Deny(TElWebDavACEHandle _Handle, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_set_Deny(TElWebDavACEHandle _Handle, int16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACE_Create(TElWebDavACEHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVACE */

#ifdef SB_USE_CLASS_TELWEBDAVACL
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACL_Add(TElWebDavACLHandle _Handle, TElWebDavACEHandle Ace, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACL_Remove(TElWebDavACLHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACL_LoadFromXML(TElWebDavACLHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACL_SaveToXML(TElWebDavACLHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACL_get_Count(TElWebDavACLHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACL_get_ACEs(TElWebDavACLHandle _Handle, int32_t Index, TElWebDavACEHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACL_Create(TElWebDavACLHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_LoadFromXML(TElWebDavACLRestrictionsHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_SaveToXML(TElWebDavACLRestrictionsHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_get_GrantOnly(TElWebDavACLRestrictionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_set_GrantOnly(TElWebDavACLRestrictionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_get_NoInvert(TElWebDavACLRestrictionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_set_NoInvert(TElWebDavACLRestrictionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_get_DenyBeforeGrant(TElWebDavACLRestrictionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_set_DenyBeforeGrant(TElWebDavACLRestrictionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_get_RequiredPrincipal(TElWebDavACLRestrictionsHandle _Handle, TSBPrincipalTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_set_RequiredPrincipal(TElWebDavACLRestrictionsHandle _Handle, TSBPrincipalTypeRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_get_Hrefs(TElWebDavACLRestrictionsHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_get_Hrefs(TElWebDavACLRestrictionsHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_get_Properties(TElWebDavACLRestrictionsHandle _Handle, TElWebDavPropertyInfoListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavACLRestrictions_Create(TElWebDavACLRestrictionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElWebDavPropertyInfo;
typedef TElWebDavPropertyInfo ElWebDavPropertyInfo;
class TElWebDavPropertyInfoList;
typedef TElWebDavPropertyInfoList ElWebDavPropertyInfoList;
class TElWebDavNamespacePrefixMap;
typedef TElWebDavNamespacePrefixMap ElWebDavNamespacePrefixMap;
class TElWebDAVLock;
typedef TElWebDAVLock ElWebDAVLock;
class TElWebDavFilter;
class TElWebDavTextMatchFilter;
class TElCardDavTextMatchFilter;
class TElCardDavPropFilter;
class TElCardDavFilter;
class TElCardDavParamFilter;
class TElWebDavACE;
class TElWebDavACL;
class TElWebDavACLRestrictions;

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
class TElWebDavPropertyInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavPropertyInfo)
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
		TElWebDavPropertyInfoHandle Clone();

		virtual bool get_Inited();

		virtual void set_Inited(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Inited, set_Inited, TElWebDavPropertyInfo, Inited);

		virtual void get_NS(std::string &OutResult);

		virtual void set_NS(const std::string &Value);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		virtual void get_Status(std::string &OutResult);

		virtual void set_Status(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Hrefs();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Hrefs, TElWebDavPropertyInfo, Hrefs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Hrefs();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Hrefs, TElWebDavPropertyInfo, Hrefs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_Description(std::string &OutResult);

		virtual void set_Description(const std::string &Value);

		TElWebDavPropertyInfo(TElWebDavPropertyInfoHandle handle, TElOwnHandle ownHandle);

		TElWebDavPropertyInfo(const std::string &NS, const std::string &Name, const std::string &Value);

		virtual ~TElWebDavPropertyInfo();

};
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
class TElWebDavPropertyInfoList: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavPropertyInfoList)
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
		TElWebDavPropertyInfo* _Inst_Item;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
		void Add(const TElWebDavPropertyInfo &PropInfo);

		void Add(const TElWebDavPropertyInfo *PropInfo);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
		void Remove(const TElWebDavPropertyInfo &PropInfo);

		void Remove(const TElWebDavPropertyInfo *PropInfo);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
		TElWebDavPropertyInfoHandle Find(const std::string &NS, const std::string &Name);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDavPropertyInfoList, Count);

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
		virtual TElWebDavPropertyInfo* get_Item(int32_t index);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

		TElWebDavPropertyInfoList(TElWebDavPropertyInfoListHandle handle, TElOwnHandle ownHandle);

		TElWebDavPropertyInfoList();

		virtual ~TElWebDavPropertyInfoList();

};
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASS_TELWEBDAVNAMESPACEPREFIXMAP
class TElWebDavNamespacePrefixMap: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavNamespacePrefixMap)
	public:
		void Clear();

		void AddNS(const std::string &NS);

		void RemoveNS(const std::string &NS);

		void GetPrefix(const std::string &NS, std::string &OutResult);

		TElWebDavNamespacePrefixMap(TElWebDavNamespacePrefixMapHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDavNamespacePrefixMap(bool WithDAV);

};
#endif /* SB_USE_CLASS_TELWEBDAVNAMESPACEPREFIXMAP */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
class TElWebDAVLock: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDAVLock)
	public:
		static void TimeoutToString(int32_t Timeout, std::string &OutResult);

		void TimeoutToString_Inst(int32_t Timeout, std::string &OutResult);

		static int64_t StringToTimeout(const std::string &S);

		int64_t StringToTimeout_Inst(const std::string &S);

#ifdef SB_USE_CLASS_TSTREAM
		static void ReadTokenFromXML(TStream &Strm, std::string &OutResult);

		static void ReadTokenFromXML(TStream *Strm, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadTokenFromXML_Inst(TStream &Strm, std::string &OutResult);

		void ReadTokenFromXML_Inst(TStream *Strm, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		static TElWebDAVLockHandle LoadFromXML(TElXMLDOMElement &Elem);

		static TElWebDAVLockHandle LoadFromXML(TElXMLDOMElement *Elem);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElWebDAVLockHandle LoadFromXML_Inst(TElXMLDOMElement &Elem);

		TElWebDAVLockHandle LoadFromXML_Inst(TElXMLDOMElement *Elem);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElWebDAVLockHandle Clone();

		void ToXML(bool WithToken, const std::string &NS, bool EncodeURL, std::string &OutResult);

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODE
		void SaveToXML(const TElXMLDOMDocument &Doc, const TElXMLDOMNode &Base, bool WithToken, bool EncodeURL);

		void SaveToXML(const TElXMLDOMDocument *Doc, const TElXMLDOMNode *Base, bool WithToken, bool EncodeURL);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODE */

		bool LocksURL(const std::string &URL);

		bool CompatibleWith(const TElWebDAVLock &Lock);

		bool CompatibleWith(const TElWebDAVLock *Lock);

		bool ConflictsWith(const TElWebDAVLock &Lock);

		bool ConflictsWith(const TElWebDAVLock *Lock);

		void Refresh(int64_t Timeout);

		void Unlock();

		bool BeginUse();

		void EndUse();

		void ToString(std::string &OutResult);

		virtual void get_URL(std::string &OutResult);

		virtual void get_Owner(std::string &OutResult);

		virtual void get_Token(std::string &OutResult);

		virtual TSBWebDavLockScope get_Scope();

		SB_DECLARE_PROPERTY_GET(TSBWebDavLockScope, get_Scope, TElWebDAVLock, Scope);

		virtual TSBWebDavDepth get_Depth();

		SB_DECLARE_PROPERTY_GET(TSBWebDavDepth, get_Depth, TElWebDAVLock, Depth);

		virtual int64_t get_TTL();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TTL, TElWebDAVLock, TTL);

		virtual int64_t get_Timeout();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Timeout, TElWebDAVLock, Timeout);

		virtual int64_t get_UnlockTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_UnlockTime, TElWebDAVLock, UnlockTime);

		virtual bool get_Unlocked();

		SB_DECLARE_PROPERTY_GET(bool, get_Unlocked, TElWebDAVLock, Unlocked);

		virtual bool get_InUse();

		SB_DECLARE_PROPERTY_GET(bool, get_InUse, TElWebDAVLock, InUse);

		virtual void get_ToIfHeader(std::string &OutResult);

		TElWebDAVLock(TElWebDAVLockHandle handle, TElOwnHandle ownHandle);

		TElWebDAVLock(const std::string &URL, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int64_t Timeout, const std::string &Token);

};
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVFILTER
class TElWebDavFilter: public TObject
{
	private:
		TElWebDavFilter* _Inst_Parent;

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void SaveToXML(TElXMLDOMElement &Element);

		virtual void SaveToXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TElWebDavFilter* get_Parent();

		virtual void set_Parent(TElWebDavFilter &Value);

		virtual void set_Parent(TElWebDavFilter *Value);

		SB_DECLARE_PROPERTY(TElWebDavFilter*, get_Parent, set_Parent, TElWebDavFilter, Parent);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_FullPath(std::string &OutResult);

		virtual bool get_Empty();

		SB_DECLARE_PROPERTY_GET(bool, get_Empty, TElWebDavFilter, Empty);

		TElWebDavFilter(TElWebDavFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDavFilter(TElWebDavFilter &Parent);

		explicit TElWebDavFilter(TElWebDavFilter *Parent);

		virtual ~TElWebDavFilter();

};
#endif /* SB_USE_CLASS_TELWEBDAVFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVTEXTMATCHFILTER
class TElWebDavTextMatchFilter: public TElWebDavFilter
{
	private:
		SB_DISABLE_COPY(TElWebDavTextMatchFilter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void SaveToXML(TElXMLDOMElement &Element);

		virtual void SaveToXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TSBWebDavFilterTextMatchCollation get_Collation();

		virtual void set_Collation(TSBWebDavFilterTextMatchCollation Value);

		SB_DECLARE_PROPERTY(TSBWebDavFilterTextMatchCollation, get_Collation, set_Collation, TElWebDavTextMatchFilter, Collation);

		virtual TSBWebDavFilterTextMatchType get_MatchType();

		virtual void set_MatchType(TSBWebDavFilterTextMatchType Value);

		SB_DECLARE_PROPERTY(TSBWebDavFilterTextMatchType, get_MatchType, set_MatchType, TElWebDavTextMatchFilter, MatchType);

		virtual bool get_NegateCondition();

		virtual void set_NegateCondition(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NegateCondition, set_NegateCondition, TElWebDavTextMatchFilter, NegateCondition);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		TElWebDavTextMatchFilter(TElWebDavTextMatchFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDavTextMatchFilter(TElWebDavFilter &Parent);

		explicit TElWebDavTextMatchFilter(TElWebDavFilter *Parent);

};
#endif /* SB_USE_CLASS_TELWEBDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER
class TElCardDavTextMatchFilter: public TElWebDavTextMatchFilter
{
	private:
		SB_DISABLE_COPY(TElCardDavTextMatchFilter)
	public:
		TElCardDavTextMatchFilter(TElCardDavTextMatchFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElCardDavTextMatchFilter(TElWebDavFilter &Parent);

		explicit TElCardDavTextMatchFilter(TElWebDavFilter *Parent);

};
#endif /* SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
class TElCardDavPropFilter: public TElWebDavFilter
{
	private:
		SB_DISABLE_COPY(TElCardDavPropFilter)
		TElWebDavFilter* _Inst_SubFilters;

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void SaveToXML(TElXMLDOMElement &Element);

		virtual void SaveToXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		int32_t AddSubFilter(TElWebDavFilter &Filter);

		int32_t AddSubFilter(TElWebDavFilter *Filter);

		void RemoveSubFilter(int32_t Index);

		virtual TSBWebDavFilterTest get_Test();

		virtual void set_Test(TSBWebDavFilterTest Value);

		SB_DECLARE_PROPERTY(TSBWebDavFilterTest, get_Test, set_Test, TElCardDavPropFilter, Test);

		virtual bool get_IsNotDefined();

		virtual void set_IsNotDefined(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsNotDefined, set_IsNotDefined, TElCardDavPropFilter, IsNotDefined);

		virtual int32_t get_SubFilterCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SubFilterCount, TElCardDavPropFilter, SubFilterCount);

		virtual TElWebDavFilter* get_SubFilters(int32_t Index);

		TElCardDavPropFilter(TElCardDavPropFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElCardDavPropFilter(TElWebDavFilter &Parent);

		explicit TElCardDavPropFilter(TElWebDavFilter *Parent);

		virtual ~TElCardDavPropFilter();

};
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVFILTER
class TElCardDavFilter: public TElWebDavFilter
{
	private:
		SB_DISABLE_COPY(TElCardDavFilter)
#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
		TElCardDavPropFilter* _Inst_PropFilters;
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void SaveToXML(TElXMLDOMElement &Element);

		virtual void SaveToXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
		int32_t AddPropFilter(TElCardDavPropFilter &PropFilter);

		int32_t AddPropFilter(TElCardDavPropFilter *PropFilter);
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */

		void RemovePropFilter(int32_t Index);

		virtual TSBWebDavFilterTest get_Test();

		virtual void set_Test(TSBWebDavFilterTest Value);

		SB_DECLARE_PROPERTY(TSBWebDavFilterTest, get_Test, set_Test, TElCardDavFilter, Test);

		virtual int32_t get_PropFilterCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PropFilterCount, TElCardDavFilter, PropFilterCount);

#ifdef SB_USE_CLASS_TELCARDDAVPROPFILTER
		virtual TElCardDavPropFilter* get_PropFilters(int32_t Index);
#endif /* SB_USE_CLASS_TELCARDDAVPROPFILTER */

		TElCardDavFilter(TElCardDavFilterHandle handle, TElOwnHandle ownHandle);

		TElCardDavFilter();

		virtual ~TElCardDavFilter();

};
#endif /* SB_USE_CLASS_TELCARDDAVFILTER */

#ifdef SB_USE_CLASS_TELCARDDAVPARAMFILTER
class TElCardDavParamFilter: public TElWebDavFilter
{
	private:
		SB_DISABLE_COPY(TElCardDavParamFilter)
#ifdef SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER
		TElCardDavTextMatchFilter* _Inst_TextMatch;
#endif /* SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual bool LoadFromXML(TElXMLDOMElement &Element);

		virtual bool LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void SaveToXML(TElXMLDOMElement &Element);

		virtual void SaveToXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER
		virtual TElCardDavTextMatchFilter* get_TextMatch();

		virtual void set_TextMatch(TElCardDavTextMatchFilter &Value);

		virtual void set_TextMatch(TElCardDavTextMatchFilter *Value);

		SB_DECLARE_PROPERTY(TElCardDavTextMatchFilter*, get_TextMatch, set_TextMatch, TElCardDavParamFilter, TextMatch);
#endif /* SB_USE_CLASS_TELCARDDAVTEXTMATCHFILTER */

		virtual bool get_OwnTextMatch();

		virtual void set_OwnTextMatch(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnTextMatch, set_OwnTextMatch, TElCardDavParamFilter, OwnTextMatch);

		virtual bool get_IsNotDefined();

		virtual void set_IsNotDefined(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsNotDefined, set_IsNotDefined, TElCardDavParamFilter, IsNotDefined);

		TElCardDavParamFilter(TElCardDavParamFilterHandle handle, TElOwnHandle ownHandle);

		explicit TElCardDavParamFilter(TElWebDavFilter &Parent);

		explicit TElCardDavParamFilter(TElWebDavFilter *Parent);

		virtual ~TElCardDavParamFilter();

};
#endif /* SB_USE_CLASS_TELCARDDAVPARAMFILTER */

#ifdef SB_USE_CLASS_TELWEBDAVACE
class TElWebDavACE: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavACE)
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
		TElWebDavPropertyInfo* _Inst__Property;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void SaveToXML(TElXMLDOMElement &Element);

		void SaveToXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TSBPrincipalType get_PrincipalType();

		virtual void set_PrincipalType(TSBPrincipalType Value);

		SB_DECLARE_PROPERTY(TSBPrincipalType, get_PrincipalType, set_PrincipalType, TElWebDavACE, PrincipalType);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
		virtual TElWebDavPropertyInfo* get__Property();

		virtual void set__Property(TElWebDavPropertyInfo &Value);

		virtual void set__Property(TElWebDavPropertyInfo *Value);

		SB_DECLARE_PROPERTY(TElWebDavPropertyInfo*, get__Property, set__Property, TElWebDavACE, _Property);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

		virtual bool get_Invert();

		virtual void set_Invert(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Invert, set_Invert, TElWebDavACE, Invert);

		virtual bool get__Protected();

		virtual void set__Protected(bool Value);

		SB_DECLARE_PROPERTY(bool, get__Protected, set__Protected, TElWebDavACE, _Protected);

		virtual bool get__Inherited();

		virtual void set__Inherited(bool Value);

		SB_DECLARE_PROPERTY(bool, get__Inherited, set__Inherited, TElWebDavACE, _Inherited);

		virtual void get_InheritedHref(std::string &OutResult);

		virtual void set_InheritedHref(const std::string &Value);

		virtual int16_t get_Grant();

		virtual void set_Grant(int16_t Value);

		SB_DECLARE_PROPERTY(int16_t, get_Grant, set_Grant, TElWebDavACE, Grant);

		virtual int16_t get_Deny();

		virtual void set_Deny(int16_t Value);

		SB_DECLARE_PROPERTY(int16_t, get_Deny, set_Deny, TElWebDavACE, Deny);

		TElWebDavACE(TElWebDavACEHandle handle, TElOwnHandle ownHandle);

		TElWebDavACE();

		virtual ~TElWebDavACE();

};
#endif /* SB_USE_CLASS_TELWEBDAVACE */

#ifdef SB_USE_CLASS_TELWEBDAVACL
class TElWebDavACL: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavACL)
#ifdef SB_USE_CLASS_TELWEBDAVACE
		TElWebDavACE* _Inst_ACEs;
#endif /* SB_USE_CLASS_TELWEBDAVACE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELWEBDAVACE
		int32_t Add(TElWebDavACE &Ace);

		int32_t Add(TElWebDavACE *Ace);
#endif /* SB_USE_CLASS_TELWEBDAVACE */

		void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void SaveToXML(TElXMLDOMElement &Element);

		void SaveToXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDavACL, Count);

#ifdef SB_USE_CLASS_TELWEBDAVACE
		virtual TElWebDavACE* get_ACEs(int32_t Index);
#endif /* SB_USE_CLASS_TELWEBDAVACE */

		TElWebDavACL(TElWebDavACLHandle handle, TElOwnHandle ownHandle);

		TElWebDavACL();

		virtual ~TElWebDavACL();

};
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS
class TElWebDavACLRestrictions: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavACLRestrictions)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Hrefs;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Hrefs;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		TElWebDavPropertyInfoList* _Inst_Properties;
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void SaveToXML(TElXMLDOMElement &Element);

		void SaveToXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual bool get_GrantOnly();

		virtual void set_GrantOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GrantOnly, set_GrantOnly, TElWebDavACLRestrictions, GrantOnly);

		virtual bool get_NoInvert();

		virtual void set_NoInvert(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoInvert, set_NoInvert, TElWebDavACLRestrictions, NoInvert);

		virtual bool get_DenyBeforeGrant();

		virtual void set_DenyBeforeGrant(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DenyBeforeGrant, set_DenyBeforeGrant, TElWebDavACLRestrictions, DenyBeforeGrant);

		virtual TSBPrincipalType get_RequiredPrincipal();

		virtual void set_RequiredPrincipal(TSBPrincipalType Value);

		SB_DECLARE_PROPERTY(TSBPrincipalType, get_RequiredPrincipal, set_RequiredPrincipal, TElWebDavACLRestrictions, RequiredPrincipal);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Hrefs();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Hrefs, TElWebDavACLRestrictions, Hrefs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Hrefs();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Hrefs, TElWebDavACLRestrictions, Hrefs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		virtual TElWebDavPropertyInfoList* get_Properties();

		SB_DECLARE_PROPERTY_GET(TElWebDavPropertyInfoList*, get_Properties, TElWebDavACLRestrictions, Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

		TElWebDavACLRestrictions(TElWebDavACLRestrictionsHandle handle, TElOwnHandle ownHandle);

		TElWebDavACLRestrictions();

		virtual ~TElWebDavACLRestrictions();

};
#endif /* SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS */

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVCOMMON

int64_t ISOTimeToDateTime(const std::string &s);

void DateTimeToISOTime(int64_t DT, std::string &OutResult);

void DepthToStr(TSBWebDavDepth Depth, std::string &OutResult);

TSBWebDavDepth StrToDepth(const std::string &Depth);

void ScopeToStr(TSBWebDavLockScope Scope, std::string &OutResult);

TSBWebDavLockScope StrToScope(const std::string &Scope);

void Substring(const std::string &S, int32_t StartIndex, int32_t EndIndex, std::string &OutResult);

bool URLComparePaths(const std::string &URL1, const std::string &URL2);

bool URLChild(const std::string &URL, const std::string &SubURL);

void URLExtractParent(const std::string &s, std::string &OutResult);

void URLExtractExtension(const std::string &s, std::string &OutResult);

void URLExtractResourceName(const std::string &s, std::string &OutResult);

bool CollectionURL(const std::string &URL);

void URLExtractPath(const std::string &URL, std::string &OutResult);

void URLCalculateDestPath(const std::string &SrcURL, const std::string &DestURL, const std::string &URL, std::string &OutResult);

void URLAddPrefixSlash(const std::string &URL, std::string &OutResult);

void URLAddPostfixSlash(const std::string &URL, std::string &OutResult);

void URLRemoveSlash(const std::string &URL, std::string &OutResult);

void URLFixSlashes(const std::string &URL, std::string &OutResult);

void URLEncodeEx(const std::string &Data, std::string &OutResult);

void URLConcat(const std::string &URL, const std::string &Path, std::string &OutResult);

bool CheckStatusCode(const std::string &S);

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
TElXMLDOMElementHandle SingleChildElement(TElXMLDOMNode &Elem);
TElXMLDOMElementHandle SingleChildElement(TElXMLDOMNode *Elem);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

int64_t MaxDateTime();

void GenerateRandomStr(int32_t Len, std::string &OutResult);

int16_t StrToPrivilege(const std::string &S);

void PrivilegeToStr(int16_t Privilege, std::string &OutResult);

void PrivilegesArray(int16_t Privileges, bool IncludeAll, bool IncludeRead, bool IncludeWrite, std::vector<int16_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_WEBDAVCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_ISOTimeToDateTime(const char * pcs, int32_t szs, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_DateTimeToISOTime(int64_t DT, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_DepthToStr(TSBWebDavDepthRaw Depth, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_StrToDepth(const char * pcDepth, int32_t szDepth, TSBWebDavDepthRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_ScopeToStr(TSBWebDavLockScopeRaw Scope, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_StrToScope(const char * pcScope, int32_t szScope, TSBWebDavLockScopeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_Substring(const char * pcS, int32_t szS, int32_t StartIndex, int32_t EndIndex, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLComparePaths(const char * pcURL1, int32_t szURL1, const char * pcURL2, int32_t szURL2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLChild(const char * pcURL, int32_t szURL, const char * pcSubURL, int32_t szSubURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLExtractParent(const char * pcs, int32_t szs, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLExtractExtension(const char * pcs, int32_t szs, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLExtractResourceName(const char * pcs, int32_t szs, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_CollectionURL(const char * pcURL, int32_t szURL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLExtractPath(const char * pcURL, int32_t szURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLCalculateDestPath(const char * pcSrcURL, int32_t szSrcURL, const char * pcDestURL, int32_t szDestURL, const char * pcURL, int32_t szURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLAddPrefixSlash(const char * pcURL, int32_t szURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLAddPostfixSlash(const char * pcURL, int32_t szURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLRemoveSlash(const char * pcURL, int32_t szURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLFixSlashes(const char * pcURL, int32_t szURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLEncodeEx(const char * pcData, int32_t szData, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_URLConcat(const char * pcURL, int32_t szURL, const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_CheckStatusCode(const char * pcS, int32_t szS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_SingleChildElement(TElXMLDOMNodeHandle Elem, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_MaxDateTime(int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_GenerateRandomStr(int32_t Len, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_StrToPrivilege(const char * pcS, int32_t szS, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_PrivilegeToStr(int16_t Privilege, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVCommon_PrivilegesArray(int16_t Privileges, int8_t IncludeAll, int8_t IncludeRead, int8_t IncludeWrite, int16_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_WEBDAVCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWEBDAVCOMMON */
