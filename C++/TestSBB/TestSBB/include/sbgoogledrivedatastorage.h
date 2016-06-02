#ifndef __INC_SBGOOGLEDRIVEDATASTORAGE
#define __INC_SBGOOGLEDRIVEDATASTORAGE

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
#include "sbstringlist.h"
#include "sbdatastorage.h"
#include "sbdatastorageutils.h"
#include "sbstrutils.h"
#include "sbjson.h"
#include "sbhttpsconstants.h"
#include "sbhttpscommon.h"
#include "sbhttpsclient.h"
#include "sboauth2.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElGoogleDriveDataStorageHandle;

typedef TElClassHandle TElGoogleDriveDataStorageObjectHandle;

typedef TElClassHandle TElGoogleDriveFolderHandle;

typedef TElClassHandle TElGoogleDrivePropertiesHandle;

typedef TElClassHandle TElGoogleDriveCommentHandle;

typedef TElClassHandle TElGoogleDriveRepliesHandle;

typedef TElClassHandle TElGoogleDriveUserHandle;

typedef TElClassHandle TElGoogleDriveAccountInfoHandle;

typedef TElClassHandle TElGoogleDriveCommentsHandle;

typedef TElClassHandle TElGoogleDriveReplyHandle;

typedef TElClassHandle TElGoogleDrivePropertyHandle;

typedef TElClassHandle TElGoogleDrivePermissionHandle;

typedef TElClassHandle TElGoogleDrivePermissionsHandle;

typedef TElClassHandle TElGoogleDriveCustomFileHandle;

typedef TElClassHandle TElGoogleDriveFileHandle;

typedef TElClassHandle TElGoogleDocumentHandle;

typedef uint8_t TSBGoogleDriveRootRaw;

typedef enum
{
	gdrDrive = 0,
	gdrAppFolder = 1
} TSBGoogleDriveRoot;

typedef uint8_t TSBGoogleDriveMetadataLocationRaw;

typedef enum
{
	gdmlColocatedObjects = 0,
	gdmlMetadataSubdir = 1,
	gdmlMetadataDir = 2
} TSBGoogleDriveMetadataLocation;

typedef uint8_t TSBGoogleDrivePropertyVisibilityRaw;

typedef enum
{
	gdpvPrivate = 0,
	gdpvPublic = 1
} TSBGoogleDrivePropertyVisibility;

typedef uint8_t TSBGoogleDriveUserRoleRaw;

typedef enum
{
	gdurReader = 0,
	gdurWriter = 1,
	gdurOwner = 2
} TSBGoogleDriveUserRole;

typedef uint8_t TSBGoogleDrivePermissionScopeRaw;

typedef enum
{
	gdpsUser = 0,
	gdpsGroup = 1,
	gdpsDomain = 2,
	gdpsAnyone = 3
} TSBGoogleDrivePermissionScope;

typedef uint8_t TSBGoogleDriveCommentStatusRaw;

typedef enum
{
	gdcsOpen = 0,
	gdcsResolved = 1
} TSBGoogleDriveCommentStatus;

typedef uint8_t TSBGoogleDriveReplyActionRaw;

typedef enum
{
	gdraNoAction = 0,
	gdraResolve = 1,
	gdraReopen = 2
} TSBGoogleDriveReplyAction;

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_StartAuthorization(TElGoogleDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_CompleteAuthorization(TElGoogleDriveDataStorageHandle _Handle, const char * pcAuthorizationCode, int32_t szAuthorizationCode);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_AcquireObject(TElGoogleDriveDataStorageHandle _Handle, const char * pcObjectID, int32_t szObjectID, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_CloseSession(TElGoogleDriveDataStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_CopyObject(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveDataStorageObjectHandle Obj, TElGoogleDriveFolderHandle Destination, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_CopyObject_1(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveDataStorageObjectHandle Obj, const char * pcNewName, int32_t szNewName, const char * pcNewDescription, int32_t szNewDescription, TElGoogleDriveFolderHandle Destination, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_CreateFolder(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveFolderHandle AParent, const char * pcAName, int32_t szAName, const char * pcADescription, int32_t szADescription, TElGoogleDriveFolderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_CreateObject(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveFolderHandle AParent, const char * pcAName, int32_t szAName, const char * pcADescription, int32_t szADescription, const char * pcAMimeType, int32_t szAMimeType, int8_t AHidden, int8_t ARestricted, int8_t AStarred, TElCustomDataStorageSecurityHandlerHandle Handler, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_GetAccountInfo(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveAccountInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_GetObjectThumbnail(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveDataStorageObjectHandle Obj, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_List(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveFolderHandle Folder, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_MoveObject(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveDataStorageObjectHandle Obj, TElGoogleDriveFolderHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_MoveObject_1(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveDataStorageObjectHandle Obj, const TElGoogleDriveFolderHandle pDestinations[], int32_t szDestinations);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_RenameObject(TElGoogleDriveDataStorageHandle _Handle, TElGoogleDriveDataStorageObjectHandle Obj, const char * pcNewName, int32_t szNewName);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_Search(TElGoogleDriveDataStorageHandle _Handle, const char * pcQuery, int32_t szQuery, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_AccessToken(TElGoogleDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_ChunkedUploadChunkSize(TElGoogleDriveDataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_ChunkedUploadChunkSize(TElGoogleDriveDataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_ChunkedUploadThreshold(TElGoogleDriveDataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_ChunkedUploadThreshold(TElGoogleDriveDataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_ClientID(TElGoogleDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_ClientID(TElGoogleDriveDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_ClientSecret(TElGoogleDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_ClientSecret(TElGoogleDriveDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_HTTPClient(TElGoogleDriveDataStorageHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_HTTPClient(TElGoogleDriveDataStorageHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_PassthroughMode(TElGoogleDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_PassthroughMode(TElGoogleDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_ReadOnly(TElGoogleDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_ReadOnly(TElGoogleDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_RedirectURL(TElGoogleDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_RedirectURL(TElGoogleDriveDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_RefreshToken(TElGoogleDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_RefreshToken(TElGoogleDriveDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_Root(TElGoogleDriveDataStorageHandle _Handle, TSBGoogleDriveRootRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_Root(TElGoogleDriveDataStorageHandle _Handle, TSBGoogleDriveRootRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_UpdateViewedDateOnAcquire(TElGoogleDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_UpdateViewedDateOnAcquire(TElGoogleDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_UpdateViewedDateOnWrite(TElGoogleDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_UpdateViewedDateOnWrite(TElGoogleDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_UseETags(TElGoogleDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_UseETags(TElGoogleDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_get_UsePatchMethod(TElGoogleDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_set_UsePatchMethod(TElGoogleDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorage_Create(TComponentHandle AOwner, TElGoogleDriveDataStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Assign(TElGoogleDriveDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Clear(TElGoogleDriveDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Copy(TElGoogleDriveDataStorageObjectHandle _Handle, TElGoogleDriveFolderHandle Destination, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Delete(TElGoogleDriveDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_GetThumbnail(TElGoogleDriveDataStorageObjectHandle _Handle, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Move(TElGoogleDriveDataStorageObjectHandle _Handle, TElGoogleDriveFolderHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Move_1(TElGoogleDriveDataStorageObjectHandle _Handle, const TElGoogleDriveFolderHandle pDestinations[], int32_t szDestinations);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Refresh(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t UpdateViewedDate);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Rename(TElGoogleDriveDataStorageObjectHandle _Handle, const char * pcNewName, int32_t szNewName);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Touch(TElGoogleDriveDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Trash(TElGoogleDriveDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Untrash(TElGoogleDriveDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_AlternateLink(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_AppDataContents(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Comments(TElGoogleDriveDataStorageObjectHandle _Handle, TElGoogleDriveCommentsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_CreatedDate(TElGoogleDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Description(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_set_Description(TElGoogleDriveDataStorageObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Editable(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_ETag(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_ExplicitlyTrashed(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Hidden(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_set_Hidden(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_IconLink(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_ID(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Kind(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_LastModifyingUser(TElGoogleDriveDataStorageObjectHandle _Handle, TElGoogleDriveUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_LastModifyingUserName(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_LastViewedByMeDate(TElGoogleDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_MimeType(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_ModifiedByMeDate(TElGoogleDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_ModifiedDate(TElGoogleDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_set_ModifiedDate(TElGoogleDriveDataStorageObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_OwnerNames(TElGoogleDriveDataStorageObjectHandle _Handle, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_OwnerCount(TElGoogleDriveDataStorageObjectHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Owners(TElGoogleDriveDataStorageObjectHandle _Handle, int32_t Index, TElGoogleDriveUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Parent(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Parents(TElGoogleDriveDataStorageObjectHandle _Handle, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Permissions(TElGoogleDriveDataStorageObjectHandle _Handle, TElGoogleDrivePermissionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Properties(TElGoogleDriveDataStorageObjectHandle _Handle, TElGoogleDrivePropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_QuotaBytesUsed(TElGoogleDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Restricted(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_set_Restricted(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_SelfLink(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Shared(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_SharedWithMeDate(TElGoogleDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Starred(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_set_Starred(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_ThumbnailLink(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Trashed(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_Viewed(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_WebContentLink(TElGoogleDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_get_WritersCanShare(TElGoogleDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveDataStorageObject_Create(TElGoogleDriveDataStorageHandle AStorage, TElGoogleDriveDataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_Assign(TElGoogleDriveFolderHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_Clear(TElGoogleDriveFolderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_CreateFolder(TElGoogleDriveFolderHandle _Handle, const char * pcName, int32_t szName, const char * pcDescription, int32_t szDescription, TElGoogleDriveFolderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_CreateObject(TElGoogleDriveFolderHandle _Handle, const char * pcName, int32_t szName, const char * pcDescription, int32_t szDescription, const char * pcMimeType, int32_t szMimeType, int8_t Hidden, int8_t Restricted, int8_t Starred, TElCustomDataStorageSecurityHandlerHandle Handler, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_Clone(TElGoogleDriveFolderHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_List(TElGoogleDriveFolderHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_ListFolders(TElGoogleDriveFolderHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_get_WebViewLink(TElGoogleDriveFolderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFolder_Create(TElGoogleDriveDataStorageHandle Storage, TElGoogleDriveFolderHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_Add(TElGoogleDrivePropertiesHandle _Handle, const char * pcKey, int32_t szKey, TSBGoogleDrivePropertyVisibilityRaw Visibility, const char * pcValue, int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_Exists(TElGoogleDrivePropertiesHandle _Handle, const char * pcKey, int32_t szKey, TSBGoogleDrivePropertyVisibilityRaw Visibility, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_IndexOf(TElGoogleDrivePropertiesHandle _Handle, TElGoogleDrivePropertyHandle Prop, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_IndexOf_1(TElGoogleDrivePropertiesHandle _Handle, const char * pcKey, int32_t szKey, TSBGoogleDrivePropertyVisibilityRaw Visibility, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_Refresh(TElGoogleDrivePropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_ValueByKey(TElGoogleDrivePropertiesHandle _Handle, const char * pcKey, int32_t szKey, TSBGoogleDrivePropertyVisibilityRaw Visibility, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_get_Count(TElGoogleDrivePropertiesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_get_ETag(TElGoogleDrivePropertiesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_get_Items(TElGoogleDrivePropertiesHandle _Handle, int32_t Index, TElGoogleDrivePropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_get_Owner(TElGoogleDrivePropertiesHandle _Handle, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperties_Create(TElGoogleDriveDataStorageObjectHandle AOwner, TElGoogleDrivePropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_Assign(TElGoogleDriveCommentHandle _Handle, TElGoogleDriveCommentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_Clone(TElGoogleDriveCommentHandle _Handle, TElGoogleDriveCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_Delete(TElGoogleDriveCommentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_Refresh(TElGoogleDriveCommentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_Author(TElGoogleDriveCommentHandle _Handle, TElGoogleDriveUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_Content(TElGoogleDriveCommentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_set_Content(TElGoogleDriveCommentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_CreatedDate(TElGoogleDriveCommentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_Deleted(TElGoogleDriveCommentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_HtmlContent(TElGoogleDriveCommentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_ID(TElGoogleDriveCommentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_ModifiedDate(TElGoogleDriveCommentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_Owner(TElGoogleDriveCommentHandle _Handle, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_Replies(TElGoogleDriveCommentHandle _Handle, TElGoogleDriveRepliesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_get_Status(TElGoogleDriveCommentHandle _Handle, TSBGoogleDriveCommentStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComment_Create(TElGoogleDriveDataStorageObjectHandle AOwner, TElGoogleDriveCommentHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLIES
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReplies_Add(TElGoogleDriveRepliesHandle _Handle, const char * pcContent, int32_t szContent, TSBGoogleDriveReplyActionRaw Action, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReplies_Refresh(TElGoogleDriveRepliesHandle _Handle, int8_t IncludeDeleted);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReplies_get_Count(TElGoogleDriveRepliesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReplies_get_Items(TElGoogleDriveRepliesHandle _Handle, int32_t Index, TElGoogleDriveReplyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReplies_Create(TElGoogleDriveCommentHandle AOwner, TElGoogleDriveRepliesHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLIES */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveUser_Clone(TElGoogleDriveUserHandle _Handle, TElGoogleDriveUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveUser_get_DisplayName(TElGoogleDriveUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveUser_get_IsAuthenticated(TElGoogleDriveUserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveUser_get_PermissionID(TElGoogleDriveUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveUser_get_PictureURL(TElGoogleDriveUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveUser_Create(TElGoogleDriveUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_Refresh(TElGoogleDriveAccountInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_DomainSharingPolicy(TElGoogleDriveAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_ETag(TElGoogleDriveAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_LanguageCode(TElGoogleDriveAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_LargestChangeID(TElGoogleDriveAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_Name(TElGoogleDriveAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_PermissionID(TElGoogleDriveAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_QuotaBytesTotal(TElGoogleDriveAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_QuotaBytesUsed(TElGoogleDriveAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_QuotaBytesUsedAggregate(TElGoogleDriveAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_QuotaBytesUsedInTrash(TElGoogleDriveAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_RemainingChangeIDs(TElGoogleDriveAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_RootFolderID(TElGoogleDriveAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_get_User(TElGoogleDriveAccountInfoHandle _Handle, TElGoogleDriveUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveAccountInfo_Create(TElGoogleDriveDataStorageHandle AStorage, TElGoogleDriveAccountInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComments_Add(TElGoogleDriveCommentsHandle _Handle, const char * pcContent, int32_t szContent, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComments_Refresh(TElGoogleDriveCommentsHandle _Handle, int8_t IncludeDeleted);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComments_Refresh_1(TElGoogleDriveCommentsHandle _Handle, int64_t UpdatedAfter, int8_t IncludeDeleted);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComments_get_Count(TElGoogleDriveCommentsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComments_get_Items(TElGoogleDriveCommentsHandle _Handle, int32_t Index, TElGoogleDriveCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComments_get_Owner(TElGoogleDriveCommentsHandle _Handle, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveComments_Create(TElGoogleDriveDataStorageObjectHandle AOwner, TElGoogleDriveCommentsHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLY
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_Assign(TElGoogleDriveReplyHandle _Handle, TElGoogleDriveReplyHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_Clone(TElGoogleDriveReplyHandle _Handle, TElGoogleDriveReplyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_Delete(TElGoogleDriveReplyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_get_Author(TElGoogleDriveReplyHandle _Handle, TElGoogleDriveUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_get_Content(TElGoogleDriveReplyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_set_Content(TElGoogleDriveReplyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_get_CreatedDate(TElGoogleDriveReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_get_Deleted(TElGoogleDriveReplyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_get_HtmlContent(TElGoogleDriveReplyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_get_ID(TElGoogleDriveReplyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_get_ModifiedDate(TElGoogleDriveReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_get_Owner(TElGoogleDriveReplyHandle _Handle, TElGoogleDriveCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveReply_Create(TElGoogleDriveCommentHandle AOwner, TElGoogleDriveReplyHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLY */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_Clone(TElGoogleDrivePropertyHandle _Handle, TElGoogleDrivePropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_Delete(TElGoogleDrivePropertyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_Refresh(TElGoogleDrivePropertyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_get_ETag(TElGoogleDrivePropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_get_Key(TElGoogleDrivePropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_get_Value(TElGoogleDrivePropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_set_Value(TElGoogleDrivePropertyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_get_Visibility(TElGoogleDrivePropertyHandle _Handle, TSBGoogleDrivePropertyVisibilityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveProperty_Create(TElGoogleDriveDataStorageObjectHandle AOwner, TElGoogleDrivePropertyHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_Clone(TElGoogleDrivePermissionHandle _Handle, TElGoogleDrivePermissionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_Delete(TElGoogleDrivePermissionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_Refresh(TElGoogleDrivePermissionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_TransferOwnership(TElGoogleDrivePermissionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_AuthKey(TElGoogleDrivePermissionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_Commenter(TElGoogleDrivePermissionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_set_Commenter(TElGoogleDrivePermissionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_ETag(TElGoogleDrivePermissionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_ID(TElGoogleDrivePermissionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_Name(TElGoogleDrivePermissionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_Owner(TElGoogleDrivePermissionHandle _Handle, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_PhotoLink(TElGoogleDrivePermissionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_Role(TElGoogleDrivePermissionHandle _Handle, TSBGoogleDriveUserRoleRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_set_Role(TElGoogleDrivePermissionHandle _Handle, TSBGoogleDriveUserRoleRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_Scope(TElGoogleDrivePermissionHandle _Handle, TSBGoogleDrivePermissionScopeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_Value(TElGoogleDrivePermissionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_get_WithLink(TElGoogleDrivePermissionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermission_Create(TElGoogleDriveDataStorageObjectHandle AOwner, TElGoogleDrivePermissionHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermissions_Add(TElGoogleDrivePermissionsHandle _Handle, TSBGoogleDriveUserRoleRaw Role, TSBGoogleDrivePermissionScopeRaw AccountType, const char * pcValue, int32_t szValue, int8_t CanComment, int8_t WithLink, int8_t SendNotificationEMails, const char * pcEMailMessage, int32_t szEMailMessage, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermissions_Refresh(TElGoogleDrivePermissionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermissions_get_Count(TElGoogleDrivePermissionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermissions_get_ETag(TElGoogleDrivePermissionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermissions_get_Items(TElGoogleDrivePermissionsHandle _Handle, int32_t Index, TElGoogleDrivePermissionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermissions_get_Owner(TElGoogleDrivePermissionsHandle _Handle, TElGoogleDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDrivePermissions_Create(TElGoogleDriveDataStorageObjectHandle AOwner, TElGoogleDrivePermissionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECUSTOMFILE
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveCustomFile_Create(TElGoogleDriveDataStorageHandle AStorage, TElGoogleDriveDataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECUSTOMFILE */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFILE
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_Assign(TElGoogleDriveFileHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_Clear(TElGoogleDriveFileHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_Clone(TElGoogleDriveFileHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_Read(TElGoogleDriveFileHandle _Handle, TStreamHandle Data);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_Write(TElGoogleDriveFileHandle _Handle, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_get_DownloadURL(TElGoogleDriveFileHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_get_FileExtension(TElGoogleDriveFileHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_get_FileSize(TElGoogleDriveFileHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_get_MD5Checksum(TElGoogleDriveFileHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_get_OriginalFileName(TElGoogleDriveFileHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDriveFile_Create(TElGoogleDriveDataStorageHandle AStorage, TElGoogleDriveFileHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFILE */

#ifdef SB_USE_CLASS_TELGOOGLEDOCUMENT
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDocument_Assign(TElGoogleDocumentHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDocument_Clear(TElGoogleDocumentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDocument_Clone(TElGoogleDocumentHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDocument_get_EmbedLink(TElGoogleDocumentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGoogleDocument_Create(TElGoogleDriveDataStorageHandle AStorage, TElGoogleDocumentHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOOGLEDOCUMENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElGoogleDriveDataStorage;
class TElGoogleDriveDataStorageObject;
class TElGoogleDriveFolder;
class TElGoogleDriveProperties;
class TElGoogleDriveComment;
class TElGoogleDriveReplies;
class TElGoogleDriveUser;
class TElGoogleDriveAccountInfo;
class TElGoogleDriveComments;
class TElGoogleDriveReply;
class TElGoogleDriveProperty;
class TElGoogleDrivePermission;
class TElGoogleDrivePermissions;
class TElGoogleDriveCustomFile;
class TElGoogleDriveFile;
class TElGoogleDocument;

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
class TElGoogleDriveDataStorage: public TElCustomDataStorage
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveDataStorage)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		void StartAuthorization(std::string &OutResult);

		void CompleteAuthorization(const std::string &AuthorizationCode);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		TElGoogleDriveDataStorageObjectHandle AcquireObject(const std::string &ObjectID);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		void CloseSession();

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
		TElGoogleDriveDataStorageObjectHandle CopyObject(TElGoogleDriveDataStorageObject &Obj, TElGoogleDriveFolder &Destination);

		TElGoogleDriveDataStorageObjectHandle CopyObject(TElGoogleDriveDataStorageObject *Obj, TElGoogleDriveFolder *Destination);
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
		TElGoogleDriveDataStorageObjectHandle CopyObject(TElGoogleDriveDataStorageObject &Obj, const std::string &NewName, const std::string &NewDescription, TElGoogleDriveFolder &Destination);

		TElGoogleDriveDataStorageObjectHandle CopyObject(TElGoogleDriveDataStorageObject *Obj, const std::string &NewName, const std::string &NewDescription, TElGoogleDriveFolder *Destination);
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
		TElGoogleDriveFolderHandle CreateFolder(TElGoogleDriveFolder &AParent, const std::string &AName, const std::string &ADescription);

		TElGoogleDriveFolderHandle CreateFolder(TElGoogleDriveFolder *AParent, const std::string &AName, const std::string &ADescription);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
		TElGoogleDriveDataStorageObjectHandle CreateObject(TElGoogleDriveFolder &AParent, const std::string &AName, const std::string &ADescription, const std::string &AMimeType, bool AHidden, bool ARestricted, bool AStarred, TElCustomDataStorageSecurityHandler &Handler);

		TElGoogleDriveDataStorageObjectHandle CreateObject(TElGoogleDriveFolder *AParent, const std::string &AName, const std::string &ADescription, const std::string &AMimeType, bool AHidden, bool ARestricted, bool AStarred, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO
		TElGoogleDriveAccountInfoHandle GetAccountInfo();
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO */

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TSTREAM
		bool GetObjectThumbnail(TElGoogleDriveDataStorageObject &Obj, TStream &Stream);

		bool GetObjectThumbnail(TElGoogleDriveDataStorageObject *Obj, TStream *Stream);
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDRIVEFOLDER
		void List(TElGoogleDriveFolder &Folder, TElDataStorageObjectList &Objects);

		void List(TElGoogleDriveFolder *Folder, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
		void MoveObject(TElGoogleDriveDataStorageObject &Obj, TElGoogleDriveFolder &Destination);

		void MoveObject(TElGoogleDriveDataStorageObject *Obj, TElGoogleDriveFolder *Destination);
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER
		void MoveObject(TElGoogleDriveDataStorageObject &Obj, const std::vector<TElGoogleDriveFolderHandle> &Destinations);

		void MoveObject(TElGoogleDriveDataStorageObject *Obj, const std::vector<TElGoogleDriveFolderHandle> &Destinations);
#endif /* SB_USE_CLASSES_TELGOOGLEDRIVEDATASTORAGEOBJECT_AND_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		void RenameObject(TElGoogleDriveDataStorageObject &Obj, const std::string &NewName);

		void RenameObject(TElGoogleDriveDataStorageObject *Obj, const std::string &NewName);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void Search(const std::string &Query, TElDataStorageObjectList &Objects);

		void Search(const std::string &Query, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

		virtual void get_AccessToken(std::string &OutResult);

		virtual int64_t get_ChunkedUploadChunkSize();

		virtual void set_ChunkedUploadChunkSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ChunkedUploadChunkSize, set_ChunkedUploadChunkSize, TElGoogleDriveDataStorage, ChunkedUploadChunkSize);

		virtual int64_t get_ChunkedUploadThreshold();

		virtual void set_ChunkedUploadThreshold(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ChunkedUploadThreshold, set_ChunkedUploadThreshold, TElGoogleDriveDataStorage, ChunkedUploadThreshold);

		virtual void get_ClientID(std::string &OutResult);

		virtual void set_ClientID(const std::string &Value);

		virtual void get_ClientSecret(std::string &OutResult);

		virtual void set_ClientSecret(const std::string &Value);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElGoogleDriveDataStorage, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual bool get_PassthroughMode();

		virtual void set_PassthroughMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassthroughMode, set_PassthroughMode, TElGoogleDriveDataStorage, PassthroughMode);

		virtual bool get_ReadOnly();

		virtual void set_ReadOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadOnly, set_ReadOnly, TElGoogleDriveDataStorage, ReadOnly);

		virtual void get_RedirectURL(std::string &OutResult);

		virtual void set_RedirectURL(const std::string &Value);

		virtual void get_RefreshToken(std::string &OutResult);

		virtual void set_RefreshToken(const std::string &Value);

		virtual TSBGoogleDriveRoot get_Root();

		virtual void set_Root(TSBGoogleDriveRoot Value);

		SB_DECLARE_PROPERTY(TSBGoogleDriveRoot, get_Root, set_Root, TElGoogleDriveDataStorage, Root);

		virtual bool get_UpdateViewedDateOnAcquire();

		virtual void set_UpdateViewedDateOnAcquire(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UpdateViewedDateOnAcquire, set_UpdateViewedDateOnAcquire, TElGoogleDriveDataStorage, UpdateViewedDateOnAcquire);

		virtual bool get_UpdateViewedDateOnWrite();

		virtual void set_UpdateViewedDateOnWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UpdateViewedDateOnWrite, set_UpdateViewedDateOnWrite, TElGoogleDriveDataStorage, UpdateViewedDateOnWrite);

		virtual bool get_UseETags();

		virtual void set_UseETags(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseETags, set_UseETags, TElGoogleDriveDataStorage, UseETags);

		virtual bool get_UsePatchMethod();

		virtual void set_UsePatchMethod(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UsePatchMethod, set_UsePatchMethod, TElGoogleDriveDataStorage, UsePatchMethod);

		TElGoogleDriveDataStorage(TElGoogleDriveDataStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElGoogleDriveDataStorage(TComponent &AOwner);

		explicit TElGoogleDriveDataStorage(TComponent *AOwner);

		virtual ~TElGoogleDriveDataStorage();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
class TElGoogleDriveDataStorageObject: public TElCustomDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveDataStorageObject)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS
		TElGoogleDriveComments* _Inst_Comments;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		TElGoogleDriveUser* _Inst_LastModifyingUser;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		TElGoogleDriveUser* _Inst_Owners;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS
		TElGoogleDrivePermissions* _Inst_Permissions;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES
		TElGoogleDriveProperties* _Inst_Properties;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES */

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
		TElGoogleDriveDataStorageObjectHandle Copy(TElGoogleDriveFolder &Destination);

		TElGoogleDriveDataStorageObjectHandle Copy(TElGoogleDriveFolder *Destination);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

		void Delete();

#ifdef SB_USE_CLASS_TSTREAM
		bool GetThumbnail(TStream &Stream);

		bool GetThumbnail(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
		void Move(TElGoogleDriveFolder &Destination);

		void Move(TElGoogleDriveFolder *Destination);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
		void Move(const std::vector<TElGoogleDriveFolderHandle> &Destinations);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

		void Refresh(bool UpdateViewedDate);

		void Rename(const std::string &NewName);

		void Touch();

		void Trash();

		void Untrash();

		virtual void get_AlternateLink(std::string &OutResult);

		virtual bool get_AppDataContents();

		SB_DECLARE_PROPERTY_GET(bool, get_AppDataContents, TElGoogleDriveDataStorageObject, AppDataContents);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS
		virtual TElGoogleDriveComments* get_Comments();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveComments*, get_Comments, TElGoogleDriveDataStorageObject, Comments);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS */

		virtual int64_t get_CreatedDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedDate, TElGoogleDriveDataStorageObject, CreatedDate);

		virtual void get_Description(std::string &OutResult);

		virtual void set_Description(const std::string &Value);

		virtual bool get_Editable();

		SB_DECLARE_PROPERTY_GET(bool, get_Editable, TElGoogleDriveDataStorageObject, Editable);

		virtual void get_ETag(std::string &OutResult);

		virtual bool get_ExplicitlyTrashed();

		SB_DECLARE_PROPERTY_GET(bool, get_ExplicitlyTrashed, TElGoogleDriveDataStorageObject, ExplicitlyTrashed);

		virtual bool get_Hidden();

		virtual void set_Hidden(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Hidden, set_Hidden, TElGoogleDriveDataStorageObject, Hidden);

		virtual void get_IconLink(std::string &OutResult);

		virtual void get_ID(std::string &OutResult);

		virtual void get_Kind(std::string &OutResult);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		virtual TElGoogleDriveUser* get_LastModifyingUser();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveUser*, get_LastModifyingUser, TElGoogleDriveDataStorageObject, LastModifyingUser);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

		virtual void get_LastModifyingUserName(std::string &OutResult);

		virtual int64_t get_LastViewedByMeDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LastViewedByMeDate, TElGoogleDriveDataStorageObject, LastViewedByMeDate);

		virtual void get_MimeType(std::string &OutResult);

		virtual int64_t get_ModifiedByMeDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ModifiedByMeDate, TElGoogleDriveDataStorageObject, ModifiedByMeDate);

		virtual int64_t get_ModifiedDate();

		virtual void set_ModifiedDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ModifiedDate, set_ModifiedDate, TElGoogleDriveDataStorageObject, ModifiedDate);

		virtual void get_OwnerNames(TStringList &OutResult);

		virtual int32_t get_OwnerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OwnerCount, TElGoogleDriveDataStorageObject, OwnerCount);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		virtual TElGoogleDriveUser* get_Owners(int32_t Index);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

		virtual void get_Parent(std::string &OutResult);

		virtual void get_Parents(TStringList &OutResult);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS
		virtual TElGoogleDrivePermissions* get_Permissions();

		SB_DECLARE_PROPERTY_GET(TElGoogleDrivePermissions*, get_Permissions, TElGoogleDriveDataStorageObject, Permissions);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES
		virtual TElGoogleDriveProperties* get_Properties();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveProperties*, get_Properties, TElGoogleDriveDataStorageObject, Properties);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES */

		virtual int64_t get_QuotaBytesUsed();

		SB_DECLARE_PROPERTY_GET(int64_t, get_QuotaBytesUsed, TElGoogleDriveDataStorageObject, QuotaBytesUsed);

		virtual bool get_Restricted();

		virtual void set_Restricted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Restricted, set_Restricted, TElGoogleDriveDataStorageObject, Restricted);

		virtual void get_SelfLink(std::string &OutResult);

		virtual bool get_Shared();

		SB_DECLARE_PROPERTY_GET(bool, get_Shared, TElGoogleDriveDataStorageObject, Shared);

		virtual int64_t get_SharedWithMeDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SharedWithMeDate, TElGoogleDriveDataStorageObject, SharedWithMeDate);

		virtual bool get_Starred();

		virtual void set_Starred(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Starred, set_Starred, TElGoogleDriveDataStorageObject, Starred);

		virtual void get_ThumbnailLink(std::string &OutResult);

		virtual bool get_Trashed();

		SB_DECLARE_PROPERTY_GET(bool, get_Trashed, TElGoogleDriveDataStorageObject, Trashed);

		virtual bool get_Viewed();

		SB_DECLARE_PROPERTY_GET(bool, get_Viewed, TElGoogleDriveDataStorageObject, Viewed);

		virtual void get_WebContentLink(std::string &OutResult);

		virtual bool get_WritersCanShare();

		SB_DECLARE_PROPERTY_GET(bool, get_WritersCanShare, TElGoogleDriveDataStorageObject, WritersCanShare);

		TElGoogleDriveDataStorageObject(TElGoogleDriveDataStorageObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
		explicit TElGoogleDriveDataStorageObject(TElGoogleDriveDataStorage &AStorage);

		explicit TElGoogleDriveDataStorageObject(TElGoogleDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

		virtual ~TElGoogleDriveDataStorageObject();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFOLDER
class TElGoogleDriveFolder: public TElGoogleDriveDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveFolder)
	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

		TElGoogleDriveFolderHandle CreateFolder(const std::string &Name, const std::string &Description);

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElGoogleDriveDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &Description, const std::string &MimeType, bool Hidden, bool Restricted, bool Starred, TElCustomDataStorageSecurityHandler &Handler);

		TElGoogleDriveDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &Description, const std::string &MimeType, bool Hidden, bool Restricted, bool Starred, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

		virtual TElCustomDataStorageObjectHandle Clone();

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(TElDataStorageObjectList &Objects);

		void List(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void ListFolders(TElDataStorageObjectList &Objects);

		void ListFolders(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

		virtual void get_WebViewLink(std::string &OutResult);

		TElGoogleDriveFolder(TElGoogleDriveFolderHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
		explicit TElGoogleDriveFolder(TElGoogleDriveDataStorage &Storage);

		explicit TElGoogleDriveFolder(TElGoogleDriveDataStorage *Storage);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES
class TElGoogleDriveProperties: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveProperties)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
		TElGoogleDriveProperty* _Inst_Items;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		TElGoogleDriveDataStorageObject* _Inst_Owner;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		void initInstances();

	public:
		int32_t Add(const std::string &Key, TSBGoogleDrivePropertyVisibility Visibility, const std::string &Value);

		bool Exists(const std::string &Key, TSBGoogleDrivePropertyVisibility Visibility);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
		int32_t IndexOf(TElGoogleDriveProperty &Prop);

		int32_t IndexOf(TElGoogleDriveProperty *Prop);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */

		int32_t IndexOf(const std::string &Key, TSBGoogleDrivePropertyVisibility Visibility);

		void Refresh();

		void ValueByKey(const std::string &Key, TSBGoogleDrivePropertyVisibility Visibility, std::string &OutResult);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElGoogleDriveProperties, Count);

		virtual void get_ETag(std::string &OutResult);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
		virtual TElGoogleDriveProperty* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		virtual TElGoogleDriveDataStorageObject* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveDataStorageObject*, get_Owner, TElGoogleDriveProperties, Owner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		TElGoogleDriveProperties(TElGoogleDrivePropertiesHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		explicit TElGoogleDriveProperties(TElGoogleDriveDataStorageObject &AOwner);

		explicit TElGoogleDriveProperties(TElGoogleDriveDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		virtual ~TElGoogleDriveProperties();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTIES */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
class TElGoogleDriveComment: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveComment)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		TElGoogleDriveUser* _Inst_Author;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		TElGoogleDriveDataStorageObject* _Inst_Owner;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLIES
		TElGoogleDriveReplies* _Inst_Replies;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLIES */

		void initInstances();

	public:
		void Assign(TElGoogleDriveComment &Source);

		void Assign(TElGoogleDriveComment *Source);

		TElGoogleDriveCommentHandle Clone();

		void Delete();

		void Refresh();

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		virtual TElGoogleDriveUser* get_Author();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveUser*, get_Author, TElGoogleDriveComment, Author);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

		virtual void get_Content(std::string &OutResult);

		virtual void set_Content(const std::string &Value);

		virtual int64_t get_CreatedDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedDate, TElGoogleDriveComment, CreatedDate);

		virtual bool get_Deleted();

		SB_DECLARE_PROPERTY_GET(bool, get_Deleted, TElGoogleDriveComment, Deleted);

		virtual void get_HtmlContent(std::string &OutResult);

		virtual void get_ID(std::string &OutResult);

		virtual int64_t get_ModifiedDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ModifiedDate, TElGoogleDriveComment, ModifiedDate);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		virtual TElGoogleDriveDataStorageObject* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveDataStorageObject*, get_Owner, TElGoogleDriveComment, Owner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLIES
		virtual TElGoogleDriveReplies* get_Replies();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveReplies*, get_Replies, TElGoogleDriveComment, Replies);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLIES */

		virtual TSBGoogleDriveCommentStatus get_Status();

		SB_DECLARE_PROPERTY_GET(TSBGoogleDriveCommentStatus, get_Status, TElGoogleDriveComment, Status);

		TElGoogleDriveComment(TElGoogleDriveCommentHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		explicit TElGoogleDriveComment(TElGoogleDriveDataStorageObject &AOwner);

		explicit TElGoogleDriveComment(TElGoogleDriveDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		virtual ~TElGoogleDriveComment();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLIES
class TElGoogleDriveReplies: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveReplies)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLY
		TElGoogleDriveReply* _Inst_Items;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLY */

		void initInstances();

	public:
		int32_t Add(const std::string &Content, TSBGoogleDriveReplyAction Action);

		void Refresh(bool IncludeDeleted);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElGoogleDriveReplies, Count);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLY
		virtual TElGoogleDriveReply* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLY */

		TElGoogleDriveReplies(TElGoogleDriveRepliesHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
		explicit TElGoogleDriveReplies(TElGoogleDriveComment &AOwner);

		explicit TElGoogleDriveReplies(TElGoogleDriveComment *AOwner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

		virtual ~TElGoogleDriveReplies();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLIES */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
class TElGoogleDriveUser: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveUser)
	public:
		TElGoogleDriveUserHandle Clone();

		virtual void get_DisplayName(std::string &OutResult);

		virtual bool get_IsAuthenticated();

		SB_DECLARE_PROPERTY_GET(bool, get_IsAuthenticated, TElGoogleDriveUser, IsAuthenticated);

		virtual void get_PermissionID(std::string &OutResult);

		virtual void get_PictureURL(std::string &OutResult);

		TElGoogleDriveUser(TElGoogleDriveUserHandle handle, TElOwnHandle ownHandle);

		TElGoogleDriveUser();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO
class TElGoogleDriveAccountInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveAccountInfo)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		TElGoogleDriveUser* _Inst_User;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

		void initInstances();

	public:
		void Refresh();

		virtual void get_DomainSharingPolicy(std::string &OutResult);

		virtual void get_ETag(std::string &OutResult);

		virtual void get_LanguageCode(std::string &OutResult);

		virtual int64_t get_LargestChangeID();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LargestChangeID, TElGoogleDriveAccountInfo, LargestChangeID);

		virtual void get_Name(std::string &OutResult);

		virtual void get_PermissionID(std::string &OutResult);

		virtual int64_t get_QuotaBytesTotal();

		SB_DECLARE_PROPERTY_GET(int64_t, get_QuotaBytesTotal, TElGoogleDriveAccountInfo, QuotaBytesTotal);

		virtual int64_t get_QuotaBytesUsed();

		SB_DECLARE_PROPERTY_GET(int64_t, get_QuotaBytesUsed, TElGoogleDriveAccountInfo, QuotaBytesUsed);

		virtual int64_t get_QuotaBytesUsedAggregate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_QuotaBytesUsedAggregate, TElGoogleDriveAccountInfo, QuotaBytesUsedAggregate);

		virtual int64_t get_QuotaBytesUsedInTrash();

		SB_DECLARE_PROPERTY_GET(int64_t, get_QuotaBytesUsedInTrash, TElGoogleDriveAccountInfo, QuotaBytesUsedInTrash);

		virtual int64_t get_RemainingChangeIDs();

		SB_DECLARE_PROPERTY_GET(int64_t, get_RemainingChangeIDs, TElGoogleDriveAccountInfo, RemainingChangeIDs);

		virtual void get_RootFolderID(std::string &OutResult);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		virtual TElGoogleDriveUser* get_User();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveUser*, get_User, TElGoogleDriveAccountInfo, User);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

		TElGoogleDriveAccountInfo(TElGoogleDriveAccountInfoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
		explicit TElGoogleDriveAccountInfo(TElGoogleDriveDataStorage &AStorage);

		explicit TElGoogleDriveAccountInfo(TElGoogleDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

		virtual ~TElGoogleDriveAccountInfo();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEACCOUNTINFO */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS
class TElGoogleDriveComments: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveComments)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
		TElGoogleDriveComment* _Inst_Items;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		TElGoogleDriveDataStorageObject* _Inst_Owner;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		void initInstances();

	public:
		int32_t Add(const std::string &Content);

		void Refresh(bool IncludeDeleted);

		void Refresh(int64_t UpdatedAfter, bool IncludeDeleted);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElGoogleDriveComments, Count);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
		virtual TElGoogleDriveComment* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		virtual TElGoogleDriveDataStorageObject* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveDataStorageObject*, get_Owner, TElGoogleDriveComments, Owner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		TElGoogleDriveComments(TElGoogleDriveCommentsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		explicit TElGoogleDriveComments(TElGoogleDriveDataStorageObject &AOwner);

		explicit TElGoogleDriveComments(TElGoogleDriveDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		virtual ~TElGoogleDriveComments();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENTS */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEREPLY
class TElGoogleDriveReply: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveReply)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		TElGoogleDriveUser* _Inst_Author;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
		TElGoogleDriveComment* _Inst_Owner;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

		void initInstances();

	public:
		void Assign(TElGoogleDriveReply &Source);

		void Assign(TElGoogleDriveReply *Source);

		TElGoogleDriveReplyHandle Clone();

		void Delete();

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEUSER
		virtual TElGoogleDriveUser* get_Author();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveUser*, get_Author, TElGoogleDriveReply, Author);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEUSER */

		virtual void get_Content(std::string &OutResult);

		virtual void set_Content(const std::string &Value);

		virtual int64_t get_CreatedDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedDate, TElGoogleDriveReply, CreatedDate);

		virtual bool get_Deleted();

		SB_DECLARE_PROPERTY_GET(bool, get_Deleted, TElGoogleDriveReply, Deleted);

		virtual void get_HtmlContent(std::string &OutResult);

		virtual void get_ID(std::string &OutResult);

		virtual int64_t get_ModifiedDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ModifiedDate, TElGoogleDriveReply, ModifiedDate);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
		virtual TElGoogleDriveComment* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveComment*, get_Owner, TElGoogleDriveReply, Owner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

		TElGoogleDriveReply(TElGoogleDriveReplyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECOMMENT
		explicit TElGoogleDriveReply(TElGoogleDriveComment &AOwner);

		explicit TElGoogleDriveReply(TElGoogleDriveComment *AOwner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECOMMENT */

		virtual ~TElGoogleDriveReply();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEREPLY */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY
class TElGoogleDriveProperty: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveProperty)
	public:
		TElGoogleDrivePropertyHandle Clone();

		void Delete();

		void Refresh();

		virtual void get_ETag(std::string &OutResult);

		virtual void get_Key(std::string &OutResult);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		virtual TSBGoogleDrivePropertyVisibility get_Visibility();

		SB_DECLARE_PROPERTY_GET(TSBGoogleDrivePropertyVisibility, get_Visibility, TElGoogleDriveProperty, Visibility);

		TElGoogleDriveProperty(TElGoogleDrivePropertyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		explicit TElGoogleDriveProperty(TElGoogleDriveDataStorageObject &AOwner);

		explicit TElGoogleDriveProperty(TElGoogleDriveDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPROPERTY */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION
class TElGoogleDrivePermission: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDrivePermission)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		TElGoogleDriveDataStorageObject* _Inst_Owner;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		void initInstances();

	public:
		TElGoogleDrivePermissionHandle Clone();

		void Delete();

		void Refresh();

		void TransferOwnership();

		virtual void get_AuthKey(std::string &OutResult);

		virtual bool get_Commenter();

		virtual void set_Commenter(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Commenter, set_Commenter, TElGoogleDrivePermission, Commenter);

		virtual void get_ETag(std::string &OutResult);

		virtual void get_ID(std::string &OutResult);

		virtual void get_Name(std::string &OutResult);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		virtual TElGoogleDriveDataStorageObject* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveDataStorageObject*, get_Owner, TElGoogleDrivePermission, Owner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		virtual void get_PhotoLink(std::string &OutResult);

		virtual TSBGoogleDriveUserRole get_Role();

		virtual void set_Role(TSBGoogleDriveUserRole Value);

		SB_DECLARE_PROPERTY(TSBGoogleDriveUserRole, get_Role, set_Role, TElGoogleDrivePermission, Role);

		virtual TSBGoogleDrivePermissionScope get_Scope();

		SB_DECLARE_PROPERTY_GET(TSBGoogleDrivePermissionScope, get_Scope, TElGoogleDrivePermission, Scope);

		virtual void get_Value(std::string &OutResult);

		virtual bool get_WithLink();

		SB_DECLARE_PROPERTY_GET(bool, get_WithLink, TElGoogleDrivePermission, WithLink);

		TElGoogleDrivePermission(TElGoogleDrivePermissionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		explicit TElGoogleDrivePermission(TElGoogleDriveDataStorageObject &AOwner);

		explicit TElGoogleDrivePermission(TElGoogleDriveDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		virtual ~TElGoogleDrivePermission();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS
class TElGoogleDrivePermissions: public TObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDrivePermissions)
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION
		TElGoogleDrivePermission* _Inst_Items;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION */
#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		TElGoogleDriveDataStorageObject* _Inst_Owner;
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		void initInstances();

	public:
		int32_t Add(TSBGoogleDriveUserRole Role, TSBGoogleDrivePermissionScope AccountType, const std::string &Value, bool CanComment, bool WithLink, bool SendNotificationEMails, const std::string &EMailMessage);

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElGoogleDrivePermissions, Count);

		virtual void get_ETag(std::string &OutResult);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION
		virtual TElGoogleDrivePermission* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSION */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		virtual TElGoogleDriveDataStorageObject* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElGoogleDriveDataStorageObject*, get_Owner, TElGoogleDrivePermissions, Owner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		TElGoogleDrivePermissions(TElGoogleDrivePermissionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT
		explicit TElGoogleDrivePermissions(TElGoogleDriveDataStorageObject &AOwner);

		explicit TElGoogleDrivePermissions(TElGoogleDriveDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGEOBJECT */

		virtual ~TElGoogleDrivePermissions();

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEPERMISSIONS */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVECUSTOMFILE
class TElGoogleDriveCustomFile: public TElGoogleDriveDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveCustomFile)
	public:
		TElGoogleDriveCustomFile(TElGoogleDriveCustomFileHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
		explicit TElGoogleDriveCustomFile(TElGoogleDriveDataStorage &AStorage);

		explicit TElGoogleDriveCustomFile(TElGoogleDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVECUSTOMFILE */

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEFILE
class TElGoogleDriveFile: public TElGoogleDriveCustomFile
{
	private:
		SB_DISABLE_COPY(TElGoogleDriveFile)
	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

		virtual TElCustomDataStorageObjectHandle Clone();

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Data);

		void Read(TStream *Data);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

		virtual void get_DownloadURL(std::string &OutResult);

		virtual void get_FileExtension(std::string &OutResult);

		virtual int64_t get_FileSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_FileSize, TElGoogleDriveFile, FileSize);

		virtual void get_MD5Checksum(std::string &OutResult);

		virtual void get_OriginalFileName(std::string &OutResult);

		TElGoogleDriveFile(TElGoogleDriveFileHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
		explicit TElGoogleDriveFile(TElGoogleDriveDataStorage &AStorage);

		explicit TElGoogleDriveFile(TElGoogleDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEFILE */

#ifdef SB_USE_CLASS_TELGOOGLEDOCUMENT
class TElGoogleDocument: public TElGoogleDriveCustomFile
{
	private:
		SB_DISABLE_COPY(TElGoogleDocument)
	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

		virtual TElCustomDataStorageObjectHandle Clone();

		virtual void get_EmbedLink(std::string &OutResult);

		TElGoogleDocument(TElGoogleDocumentHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE
		explicit TElGoogleDocument(TElGoogleDriveDataStorage &AStorage);

		explicit TElGoogleDocument(TElGoogleDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELGOOGLEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELGOOGLEDOCUMENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGOOGLEDRIVEDATASTORAGE */

