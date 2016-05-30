#ifndef __INC_SBGOOGLEDATASTORAGE
#define __INC_SBGOOGLEDATASTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbencoding.h"
#include "sbdatastorage.h"
#include "sbdatastorageutils.h"
#include "sbhttpsclient.h"
#include "sbxmlutils.h"
#include "sbxmlcore.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElGoogleDataStorageHandle;

typedef TElClassHandle TElGoogleDataStorageObjectCategoriesHandle;

typedef TElClassHandle TElGoogleDataStorageObjectLinksHandle;

typedef TElClassHandle TElGoogleDataStorageObjectHandle;

typedef TElClassHandle TElGooglePrefixedPostfixedUploadStreamHandle;

typedef TElClassHandle TElGoogleBase64EncodingStreamHandle;

typedef TElClassHandle TElGoogleBase64DecodingStreamHandle;

typedef TElClassHandle TElGooglePrefixedMetadataProcessingStreamHandle;

typedef uint8_t TSBGDataVersionRaw;

typedef enum
{
	gvV2 = 0,
	gvV3 = 1
} TSBGDataVersion;

typedef uint8_t TSBGoogleAuthTypeRaw;

typedef enum
{
	gatClientLogin = 0,
	gatAuthSub = 1,
	gatOAuth = 2
} TSBGoogleAuthType;

typedef uint8_t TSBGoogleEntryOrderRaw;

typedef enum
{
	geoTitle = 0,
	geoStarred = 1,
	geoLastModified = 2,
	geoLastViewed = 3,
	geoUnspecified = 4
} TSBGoogleEntryOrder;

typedef uint8_t TSBGoogleDocTypeRaw;

typedef enum
{
	gdtDocument = 0,
	gdtSpreadsheet = 1,
	gdtPresentation = 2,
	gdtUnknown = 3
} TSBGoogleDocType;

typedef uint8_t TSBGoogleDataStorageEncodingRaw;

typedef enum
{
	gdeNone = 0,
	gdeBase64 = 1
} TSBGoogleDataStorageEncoding;

typedef void (SB_CALLBACK *TSBGoogleAuthAttemptEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBGoogleAuthCaptchaRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcCaptchaUrl, int32_t szCaptchaUrl, const char * pcPageUrl, int32_t szPageUrl, char * pcCaptcha, int32_t * szCaptcha);

typedef void (SB_CALLBACK *TSBGoogleAuthAttemptFailedEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcErrorMsg, int32_t szErrorMsg, const char * pcPageUrl, int32_t szPageUrl, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBGooglePrefixedMetadataProcessingStreamMetadataFunc)(void * _ObjectData, TObjectHandle Sender, const uint8_t pMetadata[], int32_t szMetadata);

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_Authorize(TElGoogleDataStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_SecondaryAuthorize(TElGoogleDataStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_AcquireObject(TElGoogleDataStorageHandle _Handle, const char * pcTitle, int32_t szTitle, TElGoogleDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_AcquireObject_1(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, const char * pcTitle, int32_t szTitle, TElGoogleDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_AcquireObject_2(TElGoogleDataStorageHandle _Handle, TSBGoogleDocTypeRaw DocType, const char * pcDocID, int32_t szDocID, TElGoogleDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_List(TElGoogleDataStorageHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_List_1(TElGoogleDataStorageHandle _Handle, const char * pcQuery, int32_t szQuery, int8_t ShowFolders, int8_t ShowDeleted, TSBGoogleEntryOrderRaw OrderBy, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_List_2(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_List_3(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, const char * pcQuery, int32_t szQuery, int8_t ShowFolders, int8_t ShowDeleted, TSBGoogleEntryOrderRaw OrderBy, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_List_4(TElGoogleDataStorageHandle _Handle, const char * pcQuery, int32_t szQuery, const char * pcAlt, int32_t szAlt, const char * pcAuthor, int32_t szAuthor, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const char * pcCategory, int32_t szCategory, const char * pcTitle, int32_t szTitle, int8_t ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const char * pcOwner, int32_t szOwner, const char * pcWriter, int32_t szWriter, const char * pcReader, int32_t szReader, int8_t ShowFolders, int8_t ShowDeleted, TSBGoogleEntryOrderRaw OrderBy, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_List_5(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, const char * pcQuery, int32_t szQuery, const char * pcAlt, int32_t szAlt, const char * pcAuthor, int32_t szAuthor, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const char * pcCategory, int32_t szCategory, const char * pcTitle, int32_t szTitle, int8_t ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const char * pcOwner, int32_t szOwner, const char * pcWriter, int32_t szWriter, const char * pcReader, int32_t szReader, int8_t ShowFolders, int8_t ShowDeleted, TSBGoogleEntryOrderRaw OrderBy, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_CreateObject(TElGoogleDataStorageHandle _Handle, const char * pcTitle, int32_t szTitle, TSBGoogleDocTypeRaw DocType, const char * pcContentType, int32_t szContentType, TElGoogleDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_CreateFolder(TElGoogleDataStorageHandle _Handle, const char * pcTitle, int32_t szTitle, TElGoogleDataStorageObjectHandle ParentFolder, TElGoogleDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_DeleteObject(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle * Obj);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_DeleteObject_1(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle * Obj, int8_t DeletePermanently);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_DeleteObject_2(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, const char * pcTitle, int32_t szTitle, int8_t DeletePermanently);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_ObjectExists(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_ObjectExists_1(TElGoogleDataStorageHandle _Handle, TSBGoogleDocTypeRaw DocType, const char * pcDocID, int32_t szDocID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_ObjectExists_2(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, const char * pcTitle, int32_t szTitle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_RefreshObject(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_WriteObject(TElGoogleDataStorageHandle _Handle, const char * pcTitle, int32_t szTitle, TStreamHandle Data, TSBGoogleDocTypeRaw DocType, const char * pcContentType, int32_t szContentType, int8_t Convert, TSBGoogleDataStorageEncodingRaw Encoding, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_WriteObject_1(TElGoogleDataStorageHandle _Handle, const char * pcTitle, int32_t szTitle, TStreamHandle Data, TSBGoogleDocTypeRaw DocType, const char * pcContentType, int32_t szContentType, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_WriteObject_2(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj, TStreamHandle Data, int8_t OverwriteChanges, int8_t Append, const char * pcContentType, int32_t szContentType, TSBGoogleDataStorageEncodingRaw Encoding, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_ReadObject(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_ReadObject_1(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj, TStreamHandle Strm, TSBGoogleDataStorageEncodingRaw Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_ReadObject_2(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj, TStreamHandle Strm, const char * pcFormat, int32_t szFormat, TSBGoogleDataStorageEncodingRaw Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_ReadObject_3(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, const char * pcTitle, int32_t szTitle, TStreamHandle Strm, const char * pcFormat, int32_t szFormat, TSBGoogleDataStorageEncodingRaw Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_CopyObject(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj, const char * pcDestTitle, int32_t szDestTitle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_CopyObject_1(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, const char * pcSrcTitle, int32_t szSrcTitle, const char * pcDestTitle, int32_t szDestTitle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_MoveObject(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj, TElGoogleDataStorageObjectHandle DestFolder);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_MoveObject_1(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Folder, const char * pcTitle, int32_t szTitle, TElGoogleDataStorageObjectHandle DestFolder);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_GetObjectFolder(TElGoogleDataStorageHandle _Handle, TElGoogleDataStorageObjectHandle Obj, TElGoogleDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_AuthType(TElGoogleDataStorageHandle _Handle, TSBGoogleAuthTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_AuthType(TElGoogleDataStorageHandle _Handle, TSBGoogleAuthTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_DefObjectEncoding(TElGoogleDataStorageHandle _Handle, TSBGoogleDataStorageEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_DefObjectEncoding(TElGoogleDataStorageHandle _Handle, TSBGoogleDataStorageEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_Version(TElGoogleDataStorageHandle _Handle, TSBGDataVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_Version(TElGoogleDataStorageHandle _Handle, TSBGDataVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_UseSSL(TElGoogleDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_UseSSL(TElGoogleDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_HTTPClient(TElGoogleDataStorageHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_HTTPClient(TElGoogleDataStorageHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_Username(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_Username(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_Password(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_Password(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_ServiceName(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_ServiceName(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_SecondaryServiceName(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_SecondaryServiceName(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_ServerAddress(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_ServerAddress(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_AuthServerAddress(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_AuthServerAddress(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_AuthSource(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_AuthSource(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_AuthToken(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_AuthToken(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_SecondaryAuthToken(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_SecondaryAuthToken(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_MaxAuthAttempts(TElGoogleDataStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_MaxAuthAttempts(TElGoogleDataStorageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_SecMetadataID(TElGoogleDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_SecMetadataID(TElGoogleDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_UseURLEncoding(TElGoogleDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_UseURLEncoding(TElGoogleDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_IgnoreContentSrc(TElGoogleDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_IgnoreContentSrc(TElGoogleDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_OnAuthAttempt(TElGoogleDataStorageHandle _Handle, TSBGoogleAuthAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_OnAuthAttempt(TElGoogleDataStorageHandle _Handle, TSBGoogleAuthAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_OnAuthCaptchaRequest(TElGoogleDataStorageHandle _Handle, TSBGoogleAuthCaptchaRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_OnAuthCaptchaRequest(TElGoogleDataStorageHandle _Handle, TSBGoogleAuthCaptchaRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_get_OnAuthAttemptFailed(TElGoogleDataStorageHandle _Handle, TSBGoogleAuthAttemptFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_set_OnAuthAttemptFailed(TElGoogleDataStorageHandle _Handle, TSBGoogleAuthAttemptFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorage_Create(TComponentHandle AOwner, TElGoogleDataStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGE */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectCategories_Assign(TElGoogleDataStorageObjectCategoriesHandle _Handle, TElGoogleDataStorageObjectCategoriesHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectCategories_Clear(TElGoogleDataStorageObjectCategoriesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectCategories_get_Schemes(TElGoogleDataStorageObjectCategoriesHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectCategories_get_Terms(TElGoogleDataStorageObjectCategoriesHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectCategories_get_Labels(TElGoogleDataStorageObjectCategoriesHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectCategories_get_Count(TElGoogleDataStorageObjectCategoriesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectCategories_Create(TElGoogleDataStorageObjectCategoriesHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectLinks_Assign(TElGoogleDataStorageObjectLinksHandle _Handle, TElGoogleDataStorageObjectLinksHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectLinks_Clear(TElGoogleDataStorageObjectLinksHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectLinks_get_Rels(TElGoogleDataStorageObjectLinksHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectLinks_get_Types(TElGoogleDataStorageObjectLinksHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectLinks_get_Hrefs(TElGoogleDataStorageObjectLinksHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectLinks_get_Titles(TElGoogleDataStorageObjectLinksHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectLinks_get_Count(TElGoogleDataStorageObjectLinksHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObjectLinks_Create(TElGoogleDataStorageObjectLinksHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Assign(TElGoogleDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Clone(TElGoogleDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_ParseEntry(TElGoogleDataStorageObjectHandle _Handle, TElXMLDOMNodeHandle Node);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Clear(TElGoogleDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Delete(TElGoogleDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Delete_1(TElGoogleDataStorageObjectHandle _Handle, int8_t DeletePermanently);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Exists(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Refresh(TElGoogleDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Copy(TElGoogleDataStorageObjectHandle _Handle, const char * pcDestTitle, int32_t szDestTitle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Move(TElGoogleDataStorageObjectHandle _Handle, TElGoogleDataStorageObjectHandle DestFolder);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Write(TElGoogleDataStorageObjectHandle _Handle, TStreamHandle Data, int8_t OverwriteChanges, int8_t Append, const char * pcContentType, int32_t szContentType, TSBGoogleDataStorageEncodingRaw Encoding, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Read(TElGoogleDataStorageObjectHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Read_1(TElGoogleDataStorageObjectHandle _Handle, TStreamHandle Strm, TSBGoogleDataStorageEncodingRaw Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Read_2(TElGoogleDataStorageObjectHandle _Handle, TStreamHandle Strm, const char * pcFormat, int32_t szFormat, TSBGoogleDataStorageEncodingRaw Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_AcquireObject(TElGoogleDataStorageObjectHandle _Handle, const char * pcTitle, int32_t szTitle, TElGoogleDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_ReadObject(TElGoogleDataStorageObjectHandle _Handle, const char * pcTitle, int32_t szTitle, TStreamHandle Strm, const char * pcFormat, int32_t szFormat, TSBGoogleDataStorageEncodingRaw Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_List(TElGoogleDataStorageObjectHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_List_1(TElGoogleDataStorageObjectHandle _Handle, const char * pcQuery, int32_t szQuery, int8_t ShowFolders, int8_t ShowDeleted, TSBGoogleEntryOrderRaw OrderBy, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_List_2(TElGoogleDataStorageObjectHandle _Handle, const char * pcQuery, int32_t szQuery, const char * pcAlt, int32_t szAlt, const char * pcAuthor, int32_t szAuthor, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const char * pcCategory, int32_t szCategory, const char * pcTitle, int32_t szTitle, int8_t ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const char * pcOwner, int32_t szOwner, const char * pcWriter, int32_t szWriter, const char * pcReader, int32_t szReader, int8_t ShowFolders, int8_t ShowDeleted, TSBGoogleEntryOrderRaw OrderBy, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_DeleteObject(TElGoogleDataStorageObjectHandle _Handle, const char * pcTitle, int32_t szTitle, int8_t DeletePermanently);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_ObjectExists(TElGoogleDataStorageObjectHandle _Handle, const char * pcTitle, int32_t szTitle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_CopyObject(TElGoogleDataStorageObjectHandle _Handle, const char * pcSrcTitle, int32_t szSrcTitle, const char * pcDestTitle, int32_t szDestTitle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_MoveObject(TElGoogleDataStorageObjectHandle _Handle, const char * pcTitle, int32_t szTitle, TElGoogleDataStorageObjectHandle DestFolder);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_GetFolder(TElGoogleDataStorageObjectHandle _Handle, TElGoogleDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Folder(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ObjectType(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ID(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Title(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Summary(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ContentSrc(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ContentType(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_AuthorName(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_AuthorEmail(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Categories(TElGoogleDataStorageObjectHandle _Handle, TElGoogleDataStorageObjectCategoriesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_PublicationDate(TElGoogleDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_UpdateDate(TElGoogleDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Links(TElGoogleDataStorageObjectHandle _Handle, TElGoogleDataStorageObjectLinksHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ResourceID(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_CompleteResourceID(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ResourceType(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_LastModifiedByName(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_LastModifiedByEmail(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_LastViewedDate(TElGoogleDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_QuotaBytesUsed(TElGoogleDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_WritersCanInvite(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Starred(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Trashed(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Hidden(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Viewed(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_Mine(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_PrivateObj(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_SharedWithDomain(TElGoogleDataStorageObjectHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ContainingFolders(TElGoogleDataStorageObjectHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ContainingFolders(TElGoogleDataStorageObjectHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_ETag(TElGoogleDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_get_DocType(TElGoogleDataStorageObjectHandle _Handle, TSBGoogleDocTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDataStorageObject_Create(TElGoogleDataStorageHandle Owner, TElGoogleDataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEPREFIXEDPOSTFIXEDUPLOADSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedPostfixedUploadStream_Read(TElGooglePrefixedPostfixedUploadStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedPostfixedUploadStream_Write(TElGooglePrefixedPostfixedUploadStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedPostfixedUploadStream_Seek(TElGooglePrefixedPostfixedUploadStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedPostfixedUploadStream_Seek_1(TElGooglePrefixedPostfixedUploadStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedPostfixedUploadStream_CreateMultipartRelated(TStreamHandle SourceStream, const char * pcBoundary, int32_t szBoundary, const uint8_t pAtomXmlPart[], int32_t szAtomXmlPart, const char * pcContentType, int32_t szContentType, int64_t Count, int8_t ReleaseSourceStream, TElGooglePrefixedPostfixedUploadStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedPostfixedUploadStream_CreatePrefixed(TStreamHandle SourceStream, const uint8_t pPrefix[], int32_t szPrefix, int64_t Count, int8_t ReleaseSourceStream, TElGooglePrefixedPostfixedUploadStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEPREFIXEDPOSTFIXEDUPLOADSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEBASE64ENCODINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64EncodingStream_Read(TElGoogleBase64EncodingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64EncodingStream_Write(TElGoogleBase64EncodingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64EncodingStream_Seek(TElGoogleBase64EncodingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64EncodingStream_Seek_1(TElGoogleBase64EncodingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64EncodingStream_Create(TStreamHandle SourceStream, int64_t Count, int32_t LineLen, TSBEOLMarkerRaw EOL, int8_t ReleaseSourceStream, TElGoogleBase64EncodingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEBASE64ENCODINGSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEBASE64DECODINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64DecodingStream_Read(TElGoogleBase64DecodingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64DecodingStream_Write(TElGoogleBase64DecodingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64DecodingStream_Seek(TElGoogleBase64DecodingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64DecodingStream_Seek_1(TElGoogleBase64DecodingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64DecodingStream_get_DestStream(TElGoogleBase64DecodingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleBase64DecodingStream_Create(TStreamHandle DestStream, int64_t Count, int8_t ReleaseDestStream, TElGoogleBase64DecodingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEBASE64DECODINGSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEPREFIXEDMETADATAPROCESSINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedMetadataProcessingStream_Read(TElGooglePrefixedMetadataProcessingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedMetadataProcessingStream_Write(TElGooglePrefixedMetadataProcessingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedMetadataProcessingStream_Seek(TElGooglePrefixedMetadataProcessingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedMetadataProcessingStream_Seek_1(TElGooglePrefixedMetadataProcessingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedMetadataProcessingStream_get_DestStream(TElGooglePrefixedMetadataProcessingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedMetadataProcessingStream_get_Metadata(TElGooglePrefixedMetadataProcessingStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGooglePrefixedMetadataProcessingStream_Create(TStreamHandle DestStream, const uint8_t pMetadataID[], int32_t szMetadataID, TSBGooglePrefixedMetadataProcessingStreamMetadataFunc pMethodOnMetadata, void * pDataOnMetadata, TNotifyEvent pMethodOnNoMetadata, void * pDataOnNoMetadata, int8_t ReleaseDestStream, TElGooglePrefixedMetadataProcessingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEPREFIXEDMETADATAPROCESSINGSTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElGoogleDataStorage;
class TElGoogleDataStorageObjectCategories;
class TElGoogleDataStorageObjectLinks;
class TElGoogleDataStorageObject;
class TElGooglePrefixedPostfixedUploadStream;
class TElGoogleBase64EncodingStream;
class TElGoogleBase64DecodingStream;
class TElGooglePrefixedMetadataProcessingStream;

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGE
class TElGoogleDataStorage: public TElCustomDataStorage
{
	private:
		SB_DISABLE_COPY(TElGoogleDataStorage)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		void Authorize();

		void SecondaryAuthorize();

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		TElGoogleDataStorageObjectHandle AcquireObject(const std::string &Title);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		TElGoogleDataStorageObjectHandle AcquireObject(TElGoogleDataStorageObject &Folder, const std::string &Title);

		TElGoogleDataStorageObjectHandle AcquireObject(TElGoogleDataStorageObject *Folder, const std::string &Title);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		TElGoogleDataStorageObjectHandle AcquireObject(TSBGoogleDocType DocType, const std::string &DocID);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(TElDataStorageObjectList &Objects);

		void List(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects);

		void List(const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT
		void List(TElGoogleDataStorageObject &Folder, TElDataStorageObjectList &Objects);

		void List(TElGoogleDataStorageObject *Folder, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT
		void List(TElGoogleDataStorageObject &Folder, const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects);

		void List(TElGoogleDataStorageObject *Folder, const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects);

		void List(const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT
		void List(TElGoogleDataStorageObject &Folder, const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects);

		void List(TElGoogleDataStorageObject *Folder, const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		TElGoogleDataStorageObjectHandle CreateObject(const std::string &Title, TSBGoogleDocType DocType, const std::string &ContentType);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		TElGoogleDataStorageObjectHandle CreateFolder(const std::string &Title, TElGoogleDataStorageObject &ParentFolder);

		TElGoogleDataStorageObjectHandle CreateFolder(const std::string &Title, TElGoogleDataStorageObject *ParentFolder);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		void DeleteObject(TElGoogleDataStorageObject &Obj);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		void DeleteObject(TElGoogleDataStorageObject &Obj, bool DeletePermanently);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		void DeleteObject(TElGoogleDataStorageObject &Folder, const std::string &Title, bool DeletePermanently);

		void DeleteObject(TElGoogleDataStorageObject *Folder, const std::string &Title, bool DeletePermanently);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		bool ObjectExists(TElGoogleDataStorageObject &Obj);

		bool ObjectExists(TElGoogleDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

		bool ObjectExists(TSBGoogleDocType DocType, const std::string &DocID);

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		bool ObjectExists(TElGoogleDataStorageObject &Folder, const std::string &Title);

		bool ObjectExists(TElGoogleDataStorageObject *Folder, const std::string &Title);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		void RefreshObject(TElGoogleDataStorageObject &Obj);

		void RefreshObject(TElGoogleDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &Title, TStream &Data, TSBGoogleDocType DocType, const std::string &ContentType, bool Convert, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Title, TStream *Data, TSBGoogleDocType DocType, const std::string &ContentType, bool Convert, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &Title, TStream &Data, TSBGoogleDocType DocType, const std::string &ContentType, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Title, TStream *Data, TSBGoogleDocType DocType, const std::string &ContentType, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElGoogleDataStorageObject &Obj, TStream &Data, bool OverwriteChanges, bool Append, const std::string &ContentType, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElGoogleDataStorageObject *Obj, TStream *Data, bool OverwriteChanges, bool Append, const std::string &ContentType, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElGoogleDataStorageObject &Obj, TStream &Strm);

		void ReadObject(TElGoogleDataStorageObject *Obj, TStream *Strm);
#endif /* SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElGoogleDataStorageObject &Obj, TStream &Strm, TSBGoogleDataStorageEncoding Encoding);

		void ReadObject(TElGoogleDataStorageObject *Obj, TStream *Strm, TSBGoogleDataStorageEncoding Encoding);
#endif /* SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElGoogleDataStorageObject &Obj, TStream &Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding);

		void ReadObject(TElGoogleDataStorageObject *Obj, TStream *Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding);
#endif /* SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElGoogleDataStorageObject &Folder, const std::string &Title, TStream &Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding);

		void ReadObject(TElGoogleDataStorageObject *Folder, const std::string &Title, TStream *Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding);
#endif /* SB_USE_CLASSES_TELGOOGLEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELGOOGLEDATASTORAGEOBJECT
		TElCustomDataStorageObjectHandle CopyObject(TElGoogleDataStorageObject &Obj, const std::string &DestTitle);

		TElCustomDataStorageObjectHandle CopyObject(TElGoogleDataStorageObject *Obj, const std::string &DestTitle);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELGOOGLEDATASTORAGEOBJECT
		TElCustomDataStorageObjectHandle CopyObject(TElGoogleDataStorageObject &Folder, const std::string &SrcTitle, const std::string &DestTitle);

		TElCustomDataStorageObjectHandle CopyObject(TElGoogleDataStorageObject *Folder, const std::string &SrcTitle, const std::string &DestTitle);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		void MoveObject(TElGoogleDataStorageObject &Obj, TElGoogleDataStorageObject &DestFolder);

		void MoveObject(TElGoogleDataStorageObject *Obj, TElGoogleDataStorageObject *DestFolder);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		void MoveObject(TElGoogleDataStorageObject &Folder, const std::string &Title, TElGoogleDataStorageObject &DestFolder);

		void MoveObject(TElGoogleDataStorageObject *Folder, const std::string &Title, TElGoogleDataStorageObject *DestFolder);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
		TElGoogleDataStorageObjectHandle GetObjectFolder(TElGoogleDataStorageObject &Obj);

		TElGoogleDataStorageObjectHandle GetObjectFolder(TElGoogleDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

		virtual TSBGoogleAuthType get_AuthType();

		virtual void set_AuthType(TSBGoogleAuthType Value);

		SB_DECLARE_PROPERTY(TSBGoogleAuthType, get_AuthType, set_AuthType, TElGoogleDataStorage, AuthType);

		virtual TSBGoogleDataStorageEncoding get_DefObjectEncoding();

		virtual void set_DefObjectEncoding(TSBGoogleDataStorageEncoding Value);

		SB_DECLARE_PROPERTY(TSBGoogleDataStorageEncoding, get_DefObjectEncoding, set_DefObjectEncoding, TElGoogleDataStorage, DefObjectEncoding);

		virtual TSBGDataVersion get_Version();

		virtual void set_Version(TSBGDataVersion Value);

		SB_DECLARE_PROPERTY(TSBGDataVersion, get_Version, set_Version, TElGoogleDataStorage, Version);

		virtual bool get_UseSSL();

		virtual void set_UseSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSL, set_UseSSL, TElGoogleDataStorage, UseSSL);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElGoogleDataStorage, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_ServiceName(std::string &OutResult);

		virtual void set_ServiceName(const std::string &Value);

		virtual void get_SecondaryServiceName(std::string &OutResult);

		virtual void set_SecondaryServiceName(const std::string &Value);

		virtual void get_ServerAddress(std::string &OutResult);

		virtual void set_ServerAddress(const std::string &Value);

		virtual void get_AuthServerAddress(std::string &OutResult);

		virtual void set_AuthServerAddress(const std::string &Value);

		virtual void get_AuthSource(std::string &OutResult);

		virtual void set_AuthSource(const std::string &Value);

		virtual void get_AuthToken(std::string &OutResult);

		virtual void set_AuthToken(const std::string &Value);

		virtual void get_SecondaryAuthToken(std::string &OutResult);

		virtual void set_SecondaryAuthToken(const std::string &Value);

		virtual int32_t get_MaxAuthAttempts();

		virtual void set_MaxAuthAttempts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxAuthAttempts, set_MaxAuthAttempts, TElGoogleDataStorage, MaxAuthAttempts);

		virtual void get_SecMetadataID(std::string &OutResult);

		virtual void set_SecMetadataID(const std::string &Value);

		virtual bool get_UseURLEncoding();

		virtual void set_UseURLEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseURLEncoding, set_UseURLEncoding, TElGoogleDataStorage, UseURLEncoding);

		virtual bool get_IgnoreContentSrc();

		virtual void set_IgnoreContentSrc(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreContentSrc, set_IgnoreContentSrc, TElGoogleDataStorage, IgnoreContentSrc);

		virtual void get_OnAuthAttempt(TSBGoogleAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthAttempt(TSBGoogleAuthAttemptEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthCaptchaRequest(TSBGoogleAuthCaptchaRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthCaptchaRequest(TSBGoogleAuthCaptchaRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthAttemptFailed(TSBGoogleAuthAttemptFailedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthAttemptFailed(TSBGoogleAuthAttemptFailedEvent pMethodValue, void * pDataValue);

		TElGoogleDataStorage(TElGoogleDataStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElGoogleDataStorage(TComponent &AOwner);

		explicit TElGoogleDataStorage(TComponent *AOwner);

		virtual ~TElGoogleDataStorage();

};
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGE */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES
class TElGoogleDataStorageObjectCategories: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDataStorageObjectCategories)
	public:
		void Assign(TElGoogleDataStorageObjectCategories &Source);

		void Assign(TElGoogleDataStorageObjectCategories *Source);

		void Clear();

		virtual void get_Schemes(int32_t Index, std::string &OutResult);

		virtual void get_Terms(int32_t Index, std::string &OutResult);

		virtual void get_Labels(int32_t Index, std::string &OutResult);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElGoogleDataStorageObjectCategories, Count);

		TElGoogleDataStorageObjectCategories(TElGoogleDataStorageObjectCategoriesHandle handle, TElOwnHandle ownHandle);

		TElGoogleDataStorageObjectCategories();

};
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS
class TElGoogleDataStorageObjectLinks: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDataStorageObjectLinks)
	public:
		void Assign(TElGoogleDataStorageObjectLinks &Source);

		void Assign(TElGoogleDataStorageObjectLinks *Source);

		void Clear();

		virtual void get_Rels(int32_t Index, std::string &OutResult);

		virtual void get_Types(int32_t Index, std::string &OutResult);

		virtual void get_Hrefs(int32_t Index, std::string &OutResult);

		virtual void get_Titles(int32_t Index, std::string &OutResult);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElGoogleDataStorageObjectLinks, Count);

		TElGoogleDataStorageObjectLinks(TElGoogleDataStorageObjectLinksHandle handle, TElOwnHandle ownHandle);

		TElGoogleDataStorageObjectLinks();

};
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS */

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT
class TElGoogleDataStorageObject: public TElCustomDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDataStorageObject)
#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES
		TElGoogleDataStorageObjectCategories* _Inst_Categories;
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES */
#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS
		TElGoogleDataStorageObjectLinks* _Inst_Links;
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ContainingFolders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ContainingFolders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual TElCustomDataStorageObjectHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		void ParseEntry(TElXMLDOMNode &Node);

		void ParseEntry(TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void Clear();

		void Delete();

		void Delete(bool DeletePermanently);

		bool Exists();

		void Refresh();

		TElCustomDataStorageObjectHandle Copy(const std::string &DestTitle);

		void Move(TElGoogleDataStorageObject &DestFolder);

		void Move(TElGoogleDataStorageObject *DestFolder);

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(TStream &Data, bool OverwriteChanges, bool Append, const std::string &ContentType, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, bool OverwriteChanges, bool Append, const std::string &ContentType, TSBGoogleDataStorageEncoding Encoding, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Strm);

		void Read(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Strm, TSBGoogleDataStorageEncoding Encoding);

		void Read(TStream *Strm, TSBGoogleDataStorageEncoding Encoding);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding);

		void Read(TStream *Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding);
#endif /* SB_USE_CLASS_TSTREAM */

		TElGoogleDataStorageObjectHandle AcquireObject(const std::string &Title);

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Title, TStream &Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding);

		void ReadObject(const std::string &Title, TStream *Strm, const std::string &Format, TSBGoogleDataStorageEncoding Encoding);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(TElDataStorageObjectList &Objects);

		void List(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects);

		void List(const std::string &Query, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList &Objects);

		void List(const std::string &Query, const std::string &Alt, const std::string &Author, int64_t StartIndex, int64_t MaxResults, int64_t UpdatedMin, int64_t UpdatedMax, const std::string &Category, const std::string &Title, bool ExactTitle, int64_t OpenedMin, int64_t OpenedMax, const std::string &Owner, const std::string &Writer, const std::string &Reader, bool ShowFolders, bool ShowDeleted, TSBGoogleEntryOrder OrderBy, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

		void DeleteObject(const std::string &Title, bool DeletePermanently);

		bool ObjectExists(const std::string &Title);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SrcTitle, const std::string &DestTitle);

		void MoveObject(const std::string &Title, TElGoogleDataStorageObject &DestFolder);

		void MoveObject(const std::string &Title, TElGoogleDataStorageObject *DestFolder);

		TElGoogleDataStorageObjectHandle GetFolder();

		virtual bool get_Folder();

		SB_DECLARE_PROPERTY_GET(bool, get_Folder, TElGoogleDataStorageObject, Folder);

		virtual void get_ObjectType(std::string &OutResult);

		virtual void get_ID(std::string &OutResult);

		virtual void get_Title(std::string &OutResult);

		virtual void get_Summary(std::string &OutResult);

		virtual void get_ContentSrc(std::string &OutResult);

		virtual void get_ContentType(std::string &OutResult);

		virtual void get_AuthorName(std::string &OutResult);

		virtual void get_AuthorEmail(std::string &OutResult);

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES
		virtual TElGoogleDataStorageObjectCategories* get_Categories();

		SB_DECLARE_PROPERTY_GET(TElGoogleDataStorageObjectCategories*, get_Categories, TElGoogleDataStorageObject, Categories);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTCATEGORIES */

		virtual int64_t get_PublicationDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_PublicationDate, TElGoogleDataStorageObject, PublicationDate);

		virtual int64_t get_UpdateDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_UpdateDate, TElGoogleDataStorageObject, UpdateDate);

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS
		virtual TElGoogleDataStorageObjectLinks* get_Links();

		SB_DECLARE_PROPERTY_GET(TElGoogleDataStorageObjectLinks*, get_Links, TElGoogleDataStorageObject, Links);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECTLINKS */

		virtual void get_ResourceID(std::string &OutResult);

		virtual void get_CompleteResourceID(std::string &OutResult);

		virtual void get_ResourceType(std::string &OutResult);

		virtual void get_LastModifiedByName(std::string &OutResult);

		virtual void get_LastModifiedByEmail(std::string &OutResult);

		virtual int64_t get_LastViewedDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LastViewedDate, TElGoogleDataStorageObject, LastViewedDate);

		virtual int64_t get_QuotaBytesUsed();

		SB_DECLARE_PROPERTY_GET(int64_t, get_QuotaBytesUsed, TElGoogleDataStorageObject, QuotaBytesUsed);

		virtual bool get_WritersCanInvite();

		SB_DECLARE_PROPERTY_GET(bool, get_WritersCanInvite, TElGoogleDataStorageObject, WritersCanInvite);

		virtual bool get_Starred();

		SB_DECLARE_PROPERTY_GET(bool, get_Starred, TElGoogleDataStorageObject, Starred);

		virtual bool get_Trashed();

		SB_DECLARE_PROPERTY_GET(bool, get_Trashed, TElGoogleDataStorageObject, Trashed);

		virtual bool get_Hidden();

		SB_DECLARE_PROPERTY_GET(bool, get_Hidden, TElGoogleDataStorageObject, Hidden);

		virtual bool get_Viewed();

		SB_DECLARE_PROPERTY_GET(bool, get_Viewed, TElGoogleDataStorageObject, Viewed);

		virtual bool get_Mine();

		SB_DECLARE_PROPERTY_GET(bool, get_Mine, TElGoogleDataStorageObject, Mine);

		virtual bool get_PrivateObj();

		SB_DECLARE_PROPERTY_GET(bool, get_PrivateObj, TElGoogleDataStorageObject, PrivateObj);

		virtual bool get_SharedWithDomain();

		SB_DECLARE_PROPERTY_GET(bool, get_SharedWithDomain, TElGoogleDataStorageObject, SharedWithDomain);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ContainingFolders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ContainingFolders, TElGoogleDataStorageObject, ContainingFolders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ContainingFolders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_ContainingFolders, TElGoogleDataStorageObject, ContainingFolders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_ETag(std::string &OutResult);

		virtual TSBGoogleDocType get_DocType();

		SB_DECLARE_PROPERTY_GET(TSBGoogleDocType, get_DocType, TElGoogleDataStorageObject, DocType);

		TElGoogleDataStorageObject(TElGoogleDataStorageObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDATASTORAGE
		explicit TElGoogleDataStorageObject(TElGoogleDataStorage &Owner);

		explicit TElGoogleDataStorageObject(TElGoogleDataStorage *Owner);
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGE */

		virtual ~TElGoogleDataStorageObject();

};
#endif /* SB_USE_CLASS_TELGOOGLEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEPREFIXEDPOSTFIXEDUPLOADSTREAM
class TElGooglePrefixedPostfixedUploadStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElGooglePrefixedPostfixedUploadStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		TElGooglePrefixedPostfixedUploadStream(TElGooglePrefixedPostfixedUploadStreamHandle handle, TElOwnHandle ownHandle);

		static TElGooglePrefixedPostfixedUploadStream CreateMultipartRelated(TStream &SourceStream, const std::string &Boundary, const std::vector<uint8_t> &AtomXmlPart, const std::string &ContentType, int64_t Count, bool ReleaseSourceStream);

		static TElGooglePrefixedPostfixedUploadStream CreateMultipartRelated(TStream *SourceStream, const std::string &Boundary, const std::vector<uint8_t> &AtomXmlPart, const std::string &ContentType, int64_t Count, bool ReleaseSourceStream);

		static TElGooglePrefixedPostfixedUploadStream CreatePrefixed(TStream &SourceStream, const std::vector<uint8_t> &Prefix, int64_t Count, bool ReleaseSourceStream);

		static TElGooglePrefixedPostfixedUploadStream CreatePrefixed(TStream *SourceStream, const std::vector<uint8_t> &Prefix, int64_t Count, bool ReleaseSourceStream);

};
#endif /* SB_USE_CLASS_TELGOOGLEPREFIXEDPOSTFIXEDUPLOADSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEBASE64ENCODINGSTREAM
class TElGoogleBase64EncodingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElGoogleBase64EncodingStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		TElGoogleBase64EncodingStream(TElGoogleBase64EncodingStreamHandle handle, TElOwnHandle ownHandle);

		TElGoogleBase64EncodingStream(TStream &SourceStream, int64_t Count, int32_t LineLen, TSBEOLMarker EOL, bool ReleaseSourceStream);

		TElGoogleBase64EncodingStream(TStream *SourceStream, int64_t Count, int32_t LineLen, TSBEOLMarker EOL, bool ReleaseSourceStream);

};
#endif /* SB_USE_CLASS_TELGOOGLEBASE64ENCODINGSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEBASE64DECODINGSTREAM
class TElGoogleBase64DecodingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElGoogleBase64DecodingStream)
		TStream* _Inst_DestStream;

		void initInstances();

	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual TStream* get_DestStream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_DestStream, TElGoogleBase64DecodingStream, DestStream);

		TElGoogleBase64DecodingStream(TElGoogleBase64DecodingStreamHandle handle, TElOwnHandle ownHandle);

		TElGoogleBase64DecodingStream(TStream &DestStream, int64_t Count, bool ReleaseDestStream);

		TElGoogleBase64DecodingStream(TStream *DestStream, int64_t Count, bool ReleaseDestStream);

		virtual ~TElGoogleBase64DecodingStream();

};
#endif /* SB_USE_CLASS_TELGOOGLEBASE64DECODINGSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEPREFIXEDMETADATAPROCESSINGSTREAM
class TElGooglePrefixedMetadataProcessingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElGooglePrefixedMetadataProcessingStream)
		TStream* _Inst_DestStream;

		void initInstances();

	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual TStream* get_DestStream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_DestStream, TElGooglePrefixedMetadataProcessingStream, DestStream);

		virtual void get_Metadata(std::vector<uint8_t> &OutResult);

		TElGooglePrefixedMetadataProcessingStream(TElGooglePrefixedMetadataProcessingStreamHandle handle, TElOwnHandle ownHandle);

		TElGooglePrefixedMetadataProcessingStream(TStream &DestStream, const std::vector<uint8_t> &MetadataID, TSBGooglePrefixedMetadataProcessingStreamMetadataFunc pMethodOnMetadata, void * pDataOnMetadata, TNotifyEvent pMethodOnNoMetadata, void * pDataOnNoMetadata, bool ReleaseDestStream);

		TElGooglePrefixedMetadataProcessingStream(TStream *DestStream, const std::vector<uint8_t> &MetadataID, TSBGooglePrefixedMetadataProcessingStreamMetadataFunc pMethodOnMetadata, void * pDataOnMetadata, TNotifyEvent pMethodOnNoMetadata, void * pDataOnNoMetadata, bool ReleaseDestStream);

		virtual ~TElGooglePrefixedMetadataProcessingStream();

};
#endif /* SB_USE_CLASS_TELGOOGLEPREFIXEDMETADATAPROCESSINGSTREAM */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGOOGLEDATASTORAGE */
