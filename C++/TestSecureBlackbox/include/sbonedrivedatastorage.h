#ifndef __INC_SBONEDRIVEDATASTORAGE
#define __INC_SBONEDRIVEDATASTORAGE

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
#include "sboauth2.h"
#include "sbhttpsconstants.h"
#include "sbhttpscommon.h"
#include "sbhttpsclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElOneDriveDataStorageHandle;

typedef TElClassHandle TElOneDriveDataStorageObjectHandle;

typedef TElClassHandle TElOneDriveFolderHandle;

typedef TElClassHandle TElOneDriveCommentsHandle;

typedef TElClassHandle TElOneDriveTagsHandle;

typedef TElClassHandle TElOneDriveTaggedObjectHandle;

typedef TElClassHandle TElOneDriveFriendHandle;

typedef TElClassHandle TElOneDriveCommentHandle;

typedef TElClassHandle TElOneDriveFileHandle;

typedef TElClassHandle TElOneDriveTagHandle;

typedef TElClassHandle TElOneDriveNotebookHandle;

typedef TElClassHandle TElOneDriveAudioHandle;

typedef TElClassHandle TElOneDrivePhotoHandle;

typedef TElClassHandle TElOneDrivePhotoImageHandle;

typedef TElClassHandle TElOneDrivePhotoImagesHandle;

typedef TElClassHandle TElOneDriveVideoHandle;

typedef TElClassHandle TElOneDriveAlbumHandle;

typedef TElClassHandle TElOneDriveUserInfoHandle;

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_StartAuthorization(TElOneDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_CompleteAuthorization(TElOneDriveDataStorageHandle _Handle, const char * pcAuthorizationCode, int32_t szAuthorizationCode);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_AcquireObject(TElOneDriveDataStorageHandle _Handle, const char * pcObjectID, int32_t szObjectID, TElOneDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_CloseSession(TElOneDriveDataStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_CopyObject(TElOneDriveDataStorageHandle _Handle, TElOneDriveDataStorageObjectHandle Obj, TElOneDriveFolderHandle Destination, TElOneDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_CreateFolder(TElOneDriveDataStorageHandle _Handle, TElOneDriveFolderHandle Parent, const char * pcName, int32_t szName, const char * pcDescription, int32_t szDescription, TElOneDriveFolderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_CreateObject(TElOneDriveDataStorageHandle _Handle, TElOneDriveFolderHandle Parent, const char * pcName, int32_t szName, int8_t OverwriteIfExists, TElOneDriveFileHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_CreateObject_1(TElOneDriveDataStorageHandle _Handle, TElOneDriveFolderHandle Parent, const char * pcName, int32_t szName, int8_t OverwriteIfExists, TElCustomDataStorageSecurityHandlerHandle Handler, TElOneDriveFileHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_GetQuota(TElOneDriveDataStorageHandle _Handle, int64_t * Total, int64_t * Free);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_GetUserInfo(TElOneDriveDataStorageHandle _Handle, TElOneDriveUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_GetUserInfo_1(TElOneDriveDataStorageHandle _Handle, const char * pcUserID, int32_t szUserID, TElOneDriveUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_List(TElOneDriveDataStorageHandle _Handle, TElOneDriveFolderHandle Dir, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_ListFriendly(TElOneDriveDataStorageHandle _Handle, const char * pcFriendlyName, int32_t szFriendlyName, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_ListRecent(TElOneDriveDataStorageHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_ListShared(TElOneDriveDataStorageHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_MoveObject(TElOneDriveDataStorageHandle _Handle, TElOneDriveDataStorageObjectHandle Obj, TElOneDriveFolderHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_RefreshObject(TElOneDriveDataStorageHandle _Handle, TElOneDriveDataStorageObjectHandle Obj);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_RenameObject(TElOneDriveDataStorageHandle _Handle, TElOneDriveDataStorageObjectHandle Obj, const char * pcNewName, int32_t szNewName);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_Search(TElOneDriveDataStorageHandle _Handle, const char * pcQuery, int32_t szQuery, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_AccessToken(TElOneDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_ClientID(TElOneDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_ClientID(TElOneDriveDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_ClientSecret(TElOneDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_ClientSecret(TElOneDriveDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_HTTPClient(TElOneDriveDataStorageHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_HTTPClient(TElOneDriveDataStorageHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_Locale(TElOneDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_Locale(TElOneDriveDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_Overwrite(TElOneDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_Overwrite(TElOneDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_PassthroughMode(TElOneDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_PassthroughMode(TElOneDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_ReadOnly(TElOneDriveDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_ReadOnly(TElOneDriveDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_RefreshToken(TElOneDriveDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_RefreshToken(TElOneDriveDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_ChunkedUploadChunkSize(TElOneDriveDataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_ChunkedUploadChunkSize(TElOneDriveDataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_get_ChunkedUploadThreshold(TElOneDriveDataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_set_ChunkedUploadThreshold(TElOneDriveDataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorage_Create(TComponentHandle AOwner, TElOneDriveDataStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Assign(TElOneDriveDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Clear(TElOneDriveDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Clone(TElOneDriveDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Copy(TElOneDriveDataStorageObjectHandle _Handle, TElOneDriveFolderHandle Destination, TElOneDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Delete(TElOneDriveDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Move(TElOneDriveDataStorageObjectHandle _Handle, TElOneDriveFolderHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Refresh(TElOneDriveDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Rename(TElOneDriveDataStorageObjectHandle _Handle, const char * pcNewName, int32_t szNewName);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_ClientUpdatedTime(TElOneDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_Comments(TElOneDriveDataStorageObjectHandle _Handle, TElOneDriveCommentsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_CreatedTime(TElOneDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_Description(TElOneDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_set_Description(TElOneDriveDataStorageObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_From(TElOneDriveDataStorageObjectHandle _Handle, TElOneDriveFriendHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_ID(TElOneDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_IsEmbeddable(TElOneDriveDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_Link(TElOneDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_ObjectType(TElOneDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_ParentID(TElOneDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_SharedWith(TElOneDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_Size(TElOneDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_Storage(TElOneDriveDataStorageObjectHandle _Handle, TElOneDriveDataStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_UpdatedTime(TElOneDriveDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_get_UploadLocation(TElOneDriveDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveDataStorageObject_Create(TElOneDriveDataStorageHandle AStorage, TElOneDriveDataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_Assign(TElOneDriveFolderHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_Clear(TElOneDriveFolderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_Clone(TElOneDriveFolderHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_CreateFolder(TElOneDriveFolderHandle _Handle, const char * pcName, int32_t szName, const char * pcDescription, int32_t szDescription, TElOneDriveFolderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_CreateObject(TElOneDriveFolderHandle _Handle, const char * pcName, int32_t szName, int8_t OverwriteIfExists, TElOneDriveFileHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_CreateObject_1(TElOneDriveFolderHandle _Handle, const char * pcName, int32_t szName, int8_t OverwriteIfExists, TElCustomDataStorageSecurityHandlerHandle Handler, TElOneDriveFileHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_List(TElOneDriveFolderHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_ListFolders(TElOneDriveFolderHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_get_Count(TElOneDriveFolderHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFolder_Create(TElOneDriveDataStorageHandle Storage, TElOneDriveFolderHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_Add(TElOneDriveCommentsHandle _Handle, const char * pcMessage, int32_t szMessage, TElOneDriveCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_Assign(TElOneDriveCommentsHandle _Handle, TElOneDriveCommentsHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_Clear(TElOneDriveCommentsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_Refresh(TElOneDriveCommentsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_get_Count(TElOneDriveCommentsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_get_Enabled(TElOneDriveCommentsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_get_Items(TElOneDriveCommentsHandle _Handle, int32_t Index, TElOneDriveCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_get_Owner(TElOneDriveCommentsHandle _Handle, TElOneDriveDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComments_Create(TElOneDriveDataStorageObjectHandle AOwner, TElOneDriveCommentsHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */

#ifdef SB_USE_CLASS_TELONEDRIVETAGS
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTags_Assign(TElOneDriveTagsHandle _Handle, TElOneDriveTagsHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTags_Clear(TElOneDriveTagsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTags_Refresh(TElOneDriveTagsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTags_get_Count(TElOneDriveTagsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTags_get_Enabled(TElOneDriveTagsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTags_get_Items(TElOneDriveTagsHandle _Handle, int32_t Index, TElOneDriveTagHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTags_get_Owner(TElOneDriveTagsHandle _Handle, TElOneDriveTaggedObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTags_Create(TElOneDriveTaggedObjectHandle AOwner, TElOneDriveTagsHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */

#ifdef SB_USE_CLASS_TELONEDRIVEFILE
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_Assign(TElOneDriveFileHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_CancelUpload(TElOneDriveFileHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_Clear(TElOneDriveFileHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_Clone(TElOneDriveFileHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_Read(TElOneDriveFileHandle _Handle, TStreamHandle Target);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_Write(TElOneDriveFileHandle _Handle, TStreamHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_Write_1(TElOneDriveFileHandle _Handle, TStreamHandle Source, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_get_Source(TElOneDriveFileHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFile_Create(TElOneDriveDataStorageHandle AStorage, TElOneDriveFileHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEFILE */

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFriend_Assign(TElOneDriveFriendHandle _Handle, TElOneDriveFriendHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFriend_Clear(TElOneDriveFriendHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFriend_Clone(TElOneDriveFriendHandle _Handle, TElOneDriveFriendHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFriend_get_ID(TElOneDriveFriendHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFriend_get_Name(TElOneDriveFriendHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveFriend_Create(TElOneDriveFriendHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComment_Clone(TElOneDriveCommentHandle _Handle, TElOneDriveCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComment_Delete(TElOneDriveCommentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComment_get_CreatedTime(TElOneDriveCommentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComment_get_From(TElOneDriveCommentHandle _Handle, TElOneDriveFriendHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComment_get_ID(TElOneDriveCommentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComment_get_Message(TElOneDriveCommentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveComment_Create(TElOneDriveCommentsHandle AOwner, TElOneDriveCommentHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTaggedObject_Assign(TElOneDriveTaggedObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTaggedObject_Clear(TElOneDriveTaggedObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTaggedObject_get_Tags(TElOneDriveTaggedObjectHandle _Handle, TElOneDriveTagsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTaggedObject_Create(TElOneDriveDataStorageHandle AStorage, TElOneDriveTaggedObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */

#ifdef SB_USE_CLASS_TELONEDRIVETAG
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTag_Clone(TElOneDriveTagHandle _Handle, TElOneDriveTagHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTag_get_CreatedTime(TElOneDriveTagHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTag_get_ID(TElOneDriveTagHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTag_get_User(TElOneDriveTagHandle _Handle, TElOneDriveFriendHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTag_get_X(TElOneDriveTagHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTag_get_Y(TElOneDriveTagHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveTag_Create(TElOneDriveTagsHandle AOwner, TElOneDriveTagHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVETAG */

#ifdef SB_USE_CLASS_TELONEDRIVENOTEBOOK
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveNotebook_Create(TElOneDriveDataStorageHandle AStorage, TElOneDriveFileHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVENOTEBOOK */

#ifdef SB_USE_CLASS_TELONEDRIVEAUDIO
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_Assign(TElOneDriveAudioHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_Clear(TElOneDriveAudioHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_Clone(TElOneDriveAudioHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_get_Album(TElOneDriveAudioHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_set_Album(TElOneDriveAudioHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_get_AlbumArtist(TElOneDriveAudioHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_set_AlbumArtist(TElOneDriveAudioHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_get_Artist(TElOneDriveAudioHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_set_Artist(TElOneDriveAudioHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_get_Duration(TElOneDriveAudioHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_get_Genre(TElOneDriveAudioHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_set_Genre(TElOneDriveAudioHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_get_Picture(TElOneDriveAudioHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_get_Title(TElOneDriveAudioHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_set_Title(TElOneDriveAudioHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAudio_Create(TElOneDriveDataStorageHandle AStorage, TElOneDriveAudioHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEAUDIO */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTO
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_Assign(TElOneDrivePhotoHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_Clear(TElOneDrivePhotoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_Clone(TElOneDrivePhotoHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_Altitude(TElOneDrivePhotoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_CameraMaker(TElOneDrivePhotoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_CameraModel(TElOneDrivePhotoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_ExposureDenominator(TElOneDrivePhotoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_ExposureNumerator(TElOneDrivePhotoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_FocalLength(TElOneDrivePhotoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_FocalRatio(TElOneDrivePhotoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_Height(TElOneDrivePhotoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_Images(TElOneDrivePhotoHandle _Handle, TElOneDrivePhotoImagesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_Latitude(TElOneDrivePhotoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_Longitude(TElOneDrivePhotoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_Picture(TElOneDrivePhotoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_WhenTaken(TElOneDrivePhotoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_get_Width(TElOneDrivePhotoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhoto_Create(TElOneDriveDataStorageHandle Storage, TElOneDrivePhotoHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTO */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImage_Clear(TElOneDrivePhotoImageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImage_Clone(TElOneDrivePhotoImageHandle _Handle, TElOneDrivePhotoImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImage_get_Height(TElOneDrivePhotoImageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImage_get_ImageType(TElOneDrivePhotoImageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImage_get_Source(TElOneDrivePhotoImageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImage_get_Width(TElOneDrivePhotoImageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImage_Create(TElOneDrivePhotoImageHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_Assign(TElOneDrivePhotoImagesHandle _Handle, TElOneDrivePhotoImagesHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_Clear(TElOneDrivePhotoImagesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_get_Album(TElOneDrivePhotoImagesHandle _Handle, TElOneDrivePhotoImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_get_Count(TElOneDrivePhotoImagesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_get_Full(TElOneDrivePhotoImagesHandle _Handle, TElOneDrivePhotoImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_get_Items(TElOneDrivePhotoImagesHandle _Handle, int32_t Index, TElOneDrivePhotoImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_get_Normal(TElOneDrivePhotoImagesHandle _Handle, TElOneDrivePhotoImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_get_Small(TElOneDrivePhotoImagesHandle _Handle, TElOneDrivePhotoImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDrivePhotoImages_Create(TElOneDrivePhotoImagesHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES */

#ifdef SB_USE_CLASS_TELONEDRIVEVIDEO
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_Assign(TElOneDriveVideoHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_Clear(TElOneDriveVideoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_Clone(TElOneDriveVideoHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_get_Bitrate(TElOneDriveVideoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_get_Duration(TElOneDriveVideoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_get_Height(TElOneDriveVideoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_get_Picture(TElOneDriveVideoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_get_Width(TElOneDriveVideoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveVideo_Create(TElOneDriveDataStorageHandle Storage, TElOneDriveVideoHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEVIDEO */

#ifdef SB_USE_CLASS_TELONEDRIVEALBUM
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAlbum_Clone(TElOneDriveAlbumHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveAlbum_Create(TElOneDriveDataStorageHandle Storage, TElOneDriveFolderHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEALBUM */

#ifdef SB_USE_CLASS_TELONEDRIVEUSERINFO
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_Assign(TElOneDriveUserInfoHandle _Handle, TElOneDriveUserInfoHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_Clear(TElOneDriveUserInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_Clone(TElOneDriveUserInfoHandle _Handle, TElOneDriveUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_Refresh(TElOneDriveUserInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_get_FirstName(TElOneDriveUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_set_FirstName(TElOneDriveUserInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_get_Gender(TElOneDriveUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_set_Gender(TElOneDriveUserInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_get_ID(TElOneDriveUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_set_ID(TElOneDriveUserInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_get_LastName(TElOneDriveUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_set_LastName(TElOneDriveUserInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_get_Link(TElOneDriveUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_set_Link(TElOneDriveUserInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_get_Locale(TElOneDriveUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_set_Locale(TElOneDriveUserInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_get_Name(TElOneDriveUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_set_Name(TElOneDriveUserInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_get_UpdatedTime(TElOneDriveUserInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_set_UpdatedTime(TElOneDriveUserInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOneDriveUserInfo_Create(TElOneDriveDataStorageHandle AStorage, TElOneDriveUserInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELONEDRIVEUSERINFO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOneDriveDataStorage;
class TElOneDriveDataStorageObject;
class TElOneDriveFolder;
class TElOneDriveComments;
class TElOneDriveTags;
class TElOneDriveTaggedObject;
class TElOneDriveFriend;
class TElOneDriveComment;
class TElOneDriveFile;
class TElOneDriveTag;
class TElOneDriveNotebook;
class TElOneDriveAudio;
class TElOneDrivePhoto;
class TElOneDrivePhotoImage;
class TElOneDrivePhotoImages;
class TElOneDriveVideo;
class TElOneDriveAlbum;
class TElOneDriveUserInfo;

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
class TElOneDriveDataStorage: public TElCustomDataStorage
{
	private:
		SB_DISABLE_COPY(TElOneDriveDataStorage)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		void StartAuthorization(std::string &OutResult);

		void CompleteAuthorization(const std::string &AuthorizationCode);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
		TElOneDriveDataStorageObjectHandle AcquireObject(const std::string &ObjectID);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

		void CloseSession();

#ifdef SB_USE_CLASSES_TELONEDRIVEDATASTORAGEOBJECT_AND_TELONEDRIVEFOLDER
		TElOneDriveDataStorageObjectHandle CopyObject(TElOneDriveDataStorageObject &Obj, TElOneDriveFolder &Destination);

		TElOneDriveDataStorageObjectHandle CopyObject(TElOneDriveDataStorageObject *Obj, TElOneDriveFolder *Destination);
#endif /* SB_USE_CLASSES_TELONEDRIVEDATASTORAGEOBJECT_AND_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER
		TElOneDriveFolderHandle CreateFolder(TElOneDriveFolder &Parent, const std::string &Name, const std::string &Description);

		TElOneDriveFolderHandle CreateFolder(TElOneDriveFolder *Parent, const std::string &Name, const std::string &Description);
#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELONEDRIVEFILE_AND_TELONEDRIVEFOLDER
		TElOneDriveFileHandle CreateObject(TElOneDriveFolder &Parent, const std::string &Name, bool OverwriteIfExists);

		TElOneDriveFileHandle CreateObject(TElOneDriveFolder *Parent, const std::string &Name, bool OverwriteIfExists);
#endif /* SB_USE_CLASSES_TELONEDRIVEFILE_AND_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELONEDRIVEFILE_AND_TELONEDRIVEFOLDER
		TElOneDriveFileHandle CreateObject(TElOneDriveFolder &Parent, const std::string &Name, bool OverwriteIfExists, TElCustomDataStorageSecurityHandler &Handler);

		TElOneDriveFileHandle CreateObject(TElOneDriveFolder *Parent, const std::string &Name, bool OverwriteIfExists, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELONEDRIVEFILE_AND_TELONEDRIVEFOLDER */

		void GetQuota(int64_t &Total, int64_t &Free);

#ifdef SB_USE_CLASS_TELONEDRIVEUSERINFO
		TElOneDriveUserInfoHandle GetUserInfo();
#endif /* SB_USE_CLASS_TELONEDRIVEUSERINFO */

#ifdef SB_USE_CLASS_TELONEDRIVEUSERINFO
		TElOneDriveUserInfoHandle GetUserInfo(const std::string &UserID);
#endif /* SB_USE_CLASS_TELONEDRIVEUSERINFO */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELONEDRIVEFOLDER
		void List(TElOneDriveFolder &Dir, TElDataStorageObjectList &Objects);

		void List(TElOneDriveFolder *Dir, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void ListFriendly(const std::string &FriendlyName, TElDataStorageObjectList &Objects);

		void ListFriendly(const std::string &FriendlyName, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void ListRecent(TElDataStorageObjectList &Objects);

		void ListRecent(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void ListShared(TElDataStorageObjectList &Objects);

		void ListShared(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELONEDRIVEDATASTORAGEOBJECT_AND_TELONEDRIVEFOLDER
		void MoveObject(TElOneDriveDataStorageObject &Obj, TElOneDriveFolder &Destination);

		void MoveObject(TElOneDriveDataStorageObject *Obj, TElOneDriveFolder *Destination);
#endif /* SB_USE_CLASSES_TELONEDRIVEDATASTORAGEOBJECT_AND_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
		void RefreshObject(TElOneDriveDataStorageObject &Obj);

		void RefreshObject(TElOneDriveDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
		void RenameObject(TElOneDriveDataStorageObject &Obj, const std::string &NewName);

		void RenameObject(TElOneDriveDataStorageObject *Obj, const std::string &NewName);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void Search(const std::string &Query, TElDataStorageObjectList &Objects);

		void Search(const std::string &Query, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

		virtual void get_AccessToken(std::string &OutResult);

		virtual void get_ClientID(std::string &OutResult);

		virtual void set_ClientID(const std::string &Value);

		virtual void get_ClientSecret(std::string &OutResult);

		virtual void set_ClientSecret(const std::string &Value);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElOneDriveDataStorage, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual void get_Locale(std::string &OutResult);

		virtual void set_Locale(const std::string &Value);

		virtual bool get_Overwrite();

		virtual void set_Overwrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Overwrite, set_Overwrite, TElOneDriveDataStorage, Overwrite);

		virtual bool get_PassthroughMode();

		virtual void set_PassthroughMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassthroughMode, set_PassthroughMode, TElOneDriveDataStorage, PassthroughMode);

		virtual bool get_ReadOnly();

		virtual void set_ReadOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadOnly, set_ReadOnly, TElOneDriveDataStorage, ReadOnly);

		virtual void get_RefreshToken(std::string &OutResult);

		virtual void set_RefreshToken(const std::string &Value);

		virtual int64_t get_ChunkedUploadChunkSize();

		virtual void set_ChunkedUploadChunkSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ChunkedUploadChunkSize, set_ChunkedUploadChunkSize, TElOneDriveDataStorage, ChunkedUploadChunkSize);

		virtual int64_t get_ChunkedUploadThreshold();

		virtual void set_ChunkedUploadThreshold(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ChunkedUploadThreshold, set_ChunkedUploadThreshold, TElOneDriveDataStorage, ChunkedUploadThreshold);

		TElOneDriveDataStorage(TElOneDriveDataStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElOneDriveDataStorage(TComponent &AOwner);

		explicit TElOneDriveDataStorage(TComponent *AOwner);

		virtual ~TElOneDriveDataStorage();

};
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
class TElOneDriveDataStorageObject: public TElCustomDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveDataStorageObject)
#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
		TElOneDriveComments* _Inst_Comments;
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
		TElOneDriveFriend* _Inst_From;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */
#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		TElOneDriveDataStorage* _Inst_Storage;
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

		virtual TElCustomDataStorageObjectHandle Clone();

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER
		TElOneDriveDataStorageObjectHandle Copy(TElOneDriveFolder &Destination);

		TElOneDriveDataStorageObjectHandle Copy(TElOneDriveFolder *Destination);
#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

		void Delete();

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER
		void Move(TElOneDriveFolder &Destination);

		void Move(TElOneDriveFolder *Destination);
#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

		void Refresh();

		void Rename(const std::string &NewName);

		virtual int64_t get_ClientUpdatedTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ClientUpdatedTime, TElOneDriveDataStorageObject, ClientUpdatedTime);

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
		virtual TElOneDriveComments* get_Comments();

		SB_DECLARE_PROPERTY_GET(TElOneDriveComments*, get_Comments, TElOneDriveDataStorageObject, Comments);
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */

		virtual int64_t get_CreatedTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedTime, TElOneDriveDataStorageObject, CreatedTime);

		virtual void get_Description(std::string &OutResult);

		virtual void set_Description(const std::string &Value);

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
		virtual TElOneDriveFriend* get_From();

		SB_DECLARE_PROPERTY_GET(TElOneDriveFriend*, get_From, TElOneDriveDataStorageObject, From);
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

		virtual void get_ID(std::string &OutResult);

		virtual bool get_IsEmbeddable();

		SB_DECLARE_PROPERTY_GET(bool, get_IsEmbeddable, TElOneDriveDataStorageObject, IsEmbeddable);

		virtual void get_Link(std::string &OutResult);

		virtual void get_ObjectType(std::string &OutResult);

		virtual void get_ParentID(std::string &OutResult);

		virtual void get_SharedWith(std::string &OutResult);

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElOneDriveDataStorageObject, Size);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		virtual TElOneDriveDataStorage* get_Storage();

		SB_DECLARE_PROPERTY_GET(TElOneDriveDataStorage*, get_Storage, TElOneDriveDataStorageObject, Storage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

		virtual int64_t get_UpdatedTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_UpdatedTime, TElOneDriveDataStorageObject, UpdatedTime);

		virtual void get_UploadLocation(std::string &OutResult);

		TElOneDriveDataStorageObject(TElOneDriveDataStorageObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveDataStorageObject(TElOneDriveDataStorage &AStorage);

		explicit TElOneDriveDataStorageObject(TElOneDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

		virtual ~TElOneDriveDataStorageObject();

};
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELONEDRIVEFOLDER
class TElOneDriveFolder: public TElOneDriveDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveFolder)
	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

		virtual TElCustomDataStorageObjectHandle Clone();

		TElOneDriveFolderHandle CreateFolder(const std::string &Name, const std::string &Description);

#ifdef SB_USE_CLASS_TELONEDRIVEFILE
		TElOneDriveFileHandle CreateObject(const std::string &Name, bool OverwriteIfExists);
#endif /* SB_USE_CLASS_TELONEDRIVEFILE */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELONEDRIVEFILE
		TElOneDriveFileHandle CreateObject(const std::string &Name, bool OverwriteIfExists, TElCustomDataStorageSecurityHandler &Handler);

		TElOneDriveFileHandle CreateObject(const std::string &Name, bool OverwriteIfExists, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELONEDRIVEFILE */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(TElDataStorageObjectList &Objects);

		void List(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void ListFolders(TElDataStorageObjectList &Objects);

		void ListFolders(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

		virtual uint32_t get_Count();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_Count, TElOneDriveFolder, Count);

		TElOneDriveFolder(TElOneDriveFolderHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveFolder(TElOneDriveDataStorage &Storage);

		explicit TElOneDriveFolder(TElOneDriveDataStorage *Storage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELONEDRIVEFOLDER */

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
class TElOneDriveComments: public TObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveComments)
#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
		TElOneDriveComment* _Inst_Items;
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */
#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
		TElOneDriveDataStorageObject* _Inst_Owner;
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
		TElOneDriveCommentHandle Add(const std::string &Message);
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */

		void Assign(TElOneDriveComments &Source);

		void Assign(TElOneDriveComments *Source);

		void Clear();

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOneDriveComments, Count);

		virtual bool get_Enabled();

		SB_DECLARE_PROPERTY_GET(bool, get_Enabled, TElOneDriveComments, Enabled);

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
		virtual TElOneDriveComment* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
		virtual TElOneDriveDataStorageObject* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElOneDriveDataStorageObject*, get_Owner, TElOneDriveComments, Owner);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

		TElOneDriveComments(TElOneDriveCommentsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT
		explicit TElOneDriveComments(TElOneDriveDataStorageObject &AOwner);

		explicit TElOneDriveComments(TElOneDriveDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGEOBJECT */

		virtual ~TElOneDriveComments();

};
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */

#ifdef SB_USE_CLASS_TELONEDRIVETAGS
class TElOneDriveTags: public TObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveTags)
#ifdef SB_USE_CLASS_TELONEDRIVETAG
		TElOneDriveTag* _Inst_Items;
#endif /* SB_USE_CLASS_TELONEDRIVETAG */
#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
		TElOneDriveTaggedObject* _Inst_Owner;
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */

		void initInstances();

	public:
		void Assign(TElOneDriveTags &Source);

		void Assign(TElOneDriveTags *Source);

		void Clear();

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOneDriveTags, Count);

		virtual bool get_Enabled();

		SB_DECLARE_PROPERTY_GET(bool, get_Enabled, TElOneDriveTags, Enabled);

#ifdef SB_USE_CLASS_TELONEDRIVETAG
		virtual TElOneDriveTag* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELONEDRIVETAG */

#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
		virtual TElOneDriveTaggedObject* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElOneDriveTaggedObject*, get_Owner, TElOneDriveTags, Owner);
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */

		TElOneDriveTags(TElOneDriveTagsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
		explicit TElOneDriveTags(TElOneDriveTaggedObject &AOwner);

		explicit TElOneDriveTags(TElOneDriveTaggedObject *AOwner);
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */

		virtual ~TElOneDriveTags();

};
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */

#ifdef SB_USE_CLASS_TELONEDRIVEFILE
class TElOneDriveFile: public TElOneDriveDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveFile)
	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		void CancelUpload();

		virtual void Clear();

		virtual TElCustomDataStorageObjectHandle Clone();

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Target);

		void Read(TStream *Target);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Write(TStream &Source);

		void Write(TStream *Source);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(TStream &Source, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Source, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

		virtual void get_Source(std::string &OutResult);

		TElOneDriveFile(TElOneDriveFileHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveFile(TElOneDriveDataStorage &AStorage);

		explicit TElOneDriveFile(TElOneDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELONEDRIVEFILE */

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
class TElOneDriveFriend: public TObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveFriend)
	public:
		void Assign(TElOneDriveFriend &Source);

		void Assign(TElOneDriveFriend *Source);

		void Clear();

		TElOneDriveFriendHandle Clone();

		virtual void get_ID(std::string &OutResult);

		virtual void get_Name(std::string &OutResult);

		TElOneDriveFriend(TElOneDriveFriendHandle handle, TElOwnHandle ownHandle);

		TElOneDriveFriend();

};
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENT
class TElOneDriveComment: public TObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveComment)
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
		TElOneDriveFriend* _Inst_From;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

		void initInstances();

	public:
		TElOneDriveCommentHandle Clone();

		void Delete();

		virtual int64_t get_CreatedTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedTime, TElOneDriveComment, CreatedTime);

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
		virtual TElOneDriveFriend* get_From();

		SB_DECLARE_PROPERTY_GET(TElOneDriveFriend*, get_From, TElOneDriveComment, From);
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

		virtual void get_ID(std::string &OutResult);

		virtual void get_Message(std::string &OutResult);

		TElOneDriveComment(TElOneDriveCommentHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVECOMMENTS
		explicit TElOneDriveComment(TElOneDriveComments &AOwner);

		explicit TElOneDriveComment(TElOneDriveComments *AOwner);
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENTS */

		virtual ~TElOneDriveComment();

};
#endif /* SB_USE_CLASS_TELONEDRIVECOMMENT */

#ifdef SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT
class TElOneDriveTaggedObject: public TElOneDriveFile
{
	private:
		SB_DISABLE_COPY(TElOneDriveTaggedObject)
#ifdef SB_USE_CLASS_TELONEDRIVETAGS
		TElOneDriveTags* _Inst_Tags;
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELONEDRIVETAGS
		virtual TElOneDriveTags* get_Tags();

		SB_DECLARE_PROPERTY_GET(TElOneDriveTags*, get_Tags, TElOneDriveTaggedObject, Tags);
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */

		TElOneDriveTaggedObject(TElOneDriveTaggedObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveTaggedObject(TElOneDriveDataStorage &AStorage);

		explicit TElOneDriveTaggedObject(TElOneDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

		virtual ~TElOneDriveTaggedObject();

};
#endif /* SB_USE_CLASS_TELONEDRIVETAGGEDOBJECT */

#ifdef SB_USE_CLASS_TELONEDRIVETAG
class TElOneDriveTag: public TObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveTag)
#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
		TElOneDriveFriend* _Inst_User;
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

		void initInstances();

	public:
		TElOneDriveTagHandle Clone();

		virtual int64_t get_CreatedTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedTime, TElOneDriveTag, CreatedTime);

		virtual void get_ID(std::string &OutResult);

#ifdef SB_USE_CLASS_TELONEDRIVEFRIEND
		virtual TElOneDriveFriend* get_User();

		SB_DECLARE_PROPERTY_GET(TElOneDriveFriend*, get_User, TElOneDriveTag, User);
#endif /* SB_USE_CLASS_TELONEDRIVEFRIEND */

		virtual double get_X();

		SB_DECLARE_PROPERTY_GET(double, get_X, TElOneDriveTag, X);

		virtual double get_Y();

		SB_DECLARE_PROPERTY_GET(double, get_Y, TElOneDriveTag, Y);

		TElOneDriveTag(TElOneDriveTagHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVETAGS
		explicit TElOneDriveTag(TElOneDriveTags &AOwner);

		explicit TElOneDriveTag(TElOneDriveTags *AOwner);
#endif /* SB_USE_CLASS_TELONEDRIVETAGS */

		virtual ~TElOneDriveTag();

};
#endif /* SB_USE_CLASS_TELONEDRIVETAG */

#ifdef SB_USE_CLASS_TELONEDRIVENOTEBOOK
class TElOneDriveNotebook: public TElOneDriveFile
{
	private:
		SB_DISABLE_COPY(TElOneDriveNotebook)
	public:
		TElOneDriveNotebook(TElOneDriveNotebookHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveNotebook(TElOneDriveDataStorage &AStorage);

		explicit TElOneDriveNotebook(TElOneDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELONEDRIVENOTEBOOK */

#ifdef SB_USE_CLASS_TELONEDRIVEAUDIO
class TElOneDriveAudio: public TElOneDriveFile
{
	private:
		SB_DISABLE_COPY(TElOneDriveAudio)
	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

		virtual TElCustomDataStorageObjectHandle Clone();

		virtual void get_Album(std::string &OutResult);

		virtual void set_Album(const std::string &Value);

		virtual void get_AlbumArtist(std::string &OutResult);

		virtual void set_AlbumArtist(const std::string &Value);

		virtual void get_Artist(std::string &OutResult);

		virtual void set_Artist(const std::string &Value);

		virtual int64_t get_Duration();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Duration, TElOneDriveAudio, Duration);

		virtual void get_Genre(std::string &OutResult);

		virtual void set_Genre(const std::string &Value);

		virtual void get_Picture(std::string &OutResult);

		virtual void get_Title(std::string &OutResult);

		virtual void set_Title(const std::string &Value);

		TElOneDriveAudio(TElOneDriveAudioHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveAudio(TElOneDriveDataStorage &AStorage);

		explicit TElOneDriveAudio(TElOneDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELONEDRIVEAUDIO */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTO
class TElOneDrivePhoto: public TElOneDriveTaggedObject
{
	private:
		SB_DISABLE_COPY(TElOneDrivePhoto)
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES
		TElOneDrivePhotoImages* _Inst_Images;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES */

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

		virtual TElCustomDataStorageObjectHandle Clone();

		virtual double get_Altitude();

		SB_DECLARE_PROPERTY_GET(double, get_Altitude, TElOneDrivePhoto, Altitude);

		virtual void get_CameraMaker(std::string &OutResult);

		virtual void get_CameraModel(std::string &OutResult);

		virtual double get_ExposureDenominator();

		SB_DECLARE_PROPERTY_GET(double, get_ExposureDenominator, TElOneDrivePhoto, ExposureDenominator);

		virtual double get_ExposureNumerator();

		SB_DECLARE_PROPERTY_GET(double, get_ExposureNumerator, TElOneDrivePhoto, ExposureNumerator);

		virtual double get_FocalLength();

		SB_DECLARE_PROPERTY_GET(double, get_FocalLength, TElOneDrivePhoto, FocalLength);

		virtual double get_FocalRatio();

		SB_DECLARE_PROPERTY_GET(double, get_FocalRatio, TElOneDrivePhoto, FocalRatio);

		virtual int32_t get_Height();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Height, TElOneDrivePhoto, Height);

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES
		virtual TElOneDrivePhotoImages* get_Images();

		SB_DECLARE_PROPERTY_GET(TElOneDrivePhotoImages*, get_Images, TElOneDrivePhoto, Images);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES */

		virtual double get_Latitude();

		SB_DECLARE_PROPERTY_GET(double, get_Latitude, TElOneDrivePhoto, Latitude);

		virtual double get_Longitude();

		SB_DECLARE_PROPERTY_GET(double, get_Longitude, TElOneDrivePhoto, Longitude);

		virtual void get_Picture(std::string &OutResult);

		virtual int64_t get_WhenTaken();

		SB_DECLARE_PROPERTY_GET(int64_t, get_WhenTaken, TElOneDrivePhoto, WhenTaken);

		virtual int32_t get_Width();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Width, TElOneDrivePhoto, Width);

		TElOneDrivePhoto(TElOneDrivePhotoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDrivePhoto(TElOneDriveDataStorage &Storage);

		explicit TElOneDrivePhoto(TElOneDriveDataStorage *Storage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

		virtual ~TElOneDrivePhoto();

};
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTO */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
class TElOneDrivePhotoImage: public TObject
{
	private:
		SB_DISABLE_COPY(TElOneDrivePhotoImage)
	public:
		void Clear();

		TElOneDrivePhotoImageHandle Clone();

		virtual int32_t get_Height();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Height, TElOneDrivePhotoImage, Height);

		virtual void get_ImageType(std::string &OutResult);

		virtual void get_Source(std::string &OutResult);

		virtual int32_t get_Width();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Width, TElOneDrivePhotoImage, Width);

		TElOneDrivePhotoImage(TElOneDrivePhotoImageHandle handle, TElOwnHandle ownHandle);

		TElOneDrivePhotoImage();

};
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES
class TElOneDrivePhotoImages: public TObject
{
	private:
		SB_DISABLE_COPY(TElOneDrivePhotoImages)
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		TElOneDrivePhotoImage* _Inst_Album;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		TElOneDrivePhotoImage* _Inst_Full;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		TElOneDrivePhotoImage* _Inst_Items;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		TElOneDrivePhotoImage* _Inst_Normal;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */
#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		TElOneDrivePhotoImage* _Inst_Small;
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

		void initInstances();

	public:
		void Assign(TElOneDrivePhotoImages &Source);

		void Assign(TElOneDrivePhotoImages *Source);

		void Clear();

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		virtual TElOneDrivePhotoImage* get_Album();

		SB_DECLARE_PROPERTY_GET(TElOneDrivePhotoImage*, get_Album, TElOneDrivePhotoImages, Album);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOneDrivePhotoImages, Count);

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		virtual TElOneDrivePhotoImage* get_Full();

		SB_DECLARE_PROPERTY_GET(TElOneDrivePhotoImage*, get_Full, TElOneDrivePhotoImages, Full);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		virtual TElOneDrivePhotoImage* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		virtual TElOneDrivePhotoImage* get_Normal();

		SB_DECLARE_PROPERTY_GET(TElOneDrivePhotoImage*, get_Normal, TElOneDrivePhotoImages, Normal);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

#ifdef SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE
		virtual TElOneDrivePhotoImage* get_Small();

		SB_DECLARE_PROPERTY_GET(TElOneDrivePhotoImage*, get_Small, TElOneDrivePhotoImages, Small);
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGE */

		TElOneDrivePhotoImages(TElOneDrivePhotoImagesHandle handle, TElOwnHandle ownHandle);

		TElOneDrivePhotoImages();

		virtual ~TElOneDrivePhotoImages();

};
#endif /* SB_USE_CLASS_TELONEDRIVEPHOTOIMAGES */

#ifdef SB_USE_CLASS_TELONEDRIVEVIDEO
class TElOneDriveVideo: public TElOneDriveTaggedObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveVideo)
	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual void Clear();

		virtual TElCustomDataStorageObjectHandle Clone();

		virtual int32_t get_Bitrate();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Bitrate, TElOneDriveVideo, Bitrate);

		virtual int64_t get_Duration();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Duration, TElOneDriveVideo, Duration);

		virtual int32_t get_Height();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Height, TElOneDriveVideo, Height);

		virtual void get_Picture(std::string &OutResult);

		virtual int32_t get_Width();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Width, TElOneDriveVideo, Width);

		TElOneDriveVideo(TElOneDriveVideoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveVideo(TElOneDriveDataStorage &Storage);

		explicit TElOneDriveVideo(TElOneDriveDataStorage *Storage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELONEDRIVEVIDEO */

#ifdef SB_USE_CLASS_TELONEDRIVEALBUM
class TElOneDriveAlbum: public TElOneDriveFolder
{
	private:
		SB_DISABLE_COPY(TElOneDriveAlbum)
	public:
		virtual TElCustomDataStorageObjectHandle Clone();

		TElOneDriveAlbum(TElOneDriveAlbumHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveAlbum(TElOneDriveDataStorage &Storage);

		explicit TElOneDriveAlbum(TElOneDriveDataStorage *Storage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELONEDRIVEALBUM */

#ifdef SB_USE_CLASS_TELONEDRIVEUSERINFO
class TElOneDriveUserInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElOneDriveUserInfo)
	public:
		void Assign(TElOneDriveUserInfo &Source);

		void Assign(TElOneDriveUserInfo *Source);

		void Clear();

		TElOneDriveUserInfoHandle Clone();

		void Refresh();

		virtual void get_FirstName(std::string &OutResult);

		virtual void set_FirstName(const std::string &Value);

		virtual void get_Gender(std::string &OutResult);

		virtual void set_Gender(const std::string &Value);

		virtual void get_ID(std::string &OutResult);

		virtual void set_ID(const std::string &Value);

		virtual void get_LastName(std::string &OutResult);

		virtual void set_LastName(const std::string &Value);

		virtual void get_Link(std::string &OutResult);

		virtual void set_Link(const std::string &Value);

		virtual void get_Locale(std::string &OutResult);

		virtual void set_Locale(const std::string &Value);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual int64_t get_UpdatedTime();

		virtual void set_UpdatedTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_UpdatedTime, set_UpdatedTime, TElOneDriveUserInfo, UpdatedTime);

		TElOneDriveUserInfo(TElOneDriveUserInfoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELONEDRIVEDATASTORAGE
		explicit TElOneDriveUserInfo(TElOneDriveDataStorage &AStorage);

		explicit TElOneDriveUserInfo(TElOneDriveDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELONEDRIVEDATASTORAGE */

};
#endif /* SB_USE_CLASS_TELONEDRIVEUSERINFO */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBONEDRIVEDATASTORAGE */

