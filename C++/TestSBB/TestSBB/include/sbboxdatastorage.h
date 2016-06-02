#ifndef __INC_SBBOXDATASTORAGE
#define __INC_SBBOXDATASTORAGE

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
typedef TElClassHandle TElBoxDataStorageHandle;

typedef TElClassHandle TElBoxDataStorageObjectHandle;

typedef TElClassHandle TElBoxFileHandle;

typedef TElClassHandle TElBoxFolderHandle;

typedef TElClassHandle TElBoxGroupHandle;

typedef TElClassHandle TElBoxUserHandle;

typedef TElClassHandle TElBoxEnterpriseHandle;

typedef TElClassHandle TElBoxUserEmailAliasHandle;

typedef TElClassHandle TElBoxUserEmailAliasesHandle;

typedef TElClassHandle TElBoxGroupMembershipHandle;

typedef TElClassHandle TElBoxGroupMembershipsHandle;

typedef TElClassHandle TElBoxUserInfoHandle;

typedef TElClassHandle TElBoxUsersHandle;

typedef TElClassHandle TElBoxGroupMemberHandle;

typedef TElClassHandle TElBoxGroupMembersHandle;

typedef TElClassHandle TElBoxGroupInfoHandle;

typedef TElClassHandle TElBoxGroupsHandle;

typedef TElClassHandle TElBoxSharedLinkHandle;

typedef TElClassHandle TElBoxSharedLinkPermissionsHandle;

typedef TElClassHandle TElBoxCollaborationHandle;

typedef TElClassHandle TElBoxCollaborationsHandle;

typedef TElClassHandle TElBoxDataStorageObjectPermissionsHandle;

typedef TElClassHandle TElBoxCommentHandle;

typedef TElClassHandle TElBoxCommentsHandle;

typedef uint8_t TSBBoxGroupRoleRaw;

typedef enum
{
	bgrUnknown = 0,
	bgrMember = 1,
	bgrAdmin = 2
} TSBBoxGroupRole;

typedef uint8_t TSBBoxUserRoleRaw;

typedef enum
{
	burUnknown = 0,
	burAdmin = 1,
	burCoadmin = 2,
	burUser = 3
} TSBBoxUserRole;

typedef uint8_t TSBBoxUserStatusRaw;

typedef enum
{
	busUnknown = 0,
	busActive = 1,
	busInactive = 2
} TSBBoxUserStatus;

typedef uint8_t TSBBoxSyncStateRaw;

typedef enum
{
	bssUnknown = 0,
	bssNotSynced = 1,
	bssPartiallySynced = 2,
	bssSynced = 3
} TSBBoxSyncState;

typedef uint8_t TSBBoxSharedLinkAccessRaw;

typedef enum
{
	bslUnknown = 0,
	bslOpen = 1,
	bslCollaborators = 2,
	bslCompany = 3
} TSBBoxSharedLinkAccess;

typedef uint8_t TSBBoxObjectStatusRaw;

typedef enum
{
	bosUnknown = 0,
	bosActive = 1,
	bosTrashed = 2
} TSBBoxObjectStatus;

typedef uint8_t TSBBoxCollaborationStatusRaw;

typedef enum
{
	bcsUnknown = 0,
	bcsPending = 1,
	bcsRejected = 2,
	bcsAccepted = 3
} TSBBoxCollaborationStatus;

typedef uint8_t TSBBoxCollaborationRoleRaw;

typedef enum
{
	bcrUnknown = 0,
	bcrEditor = 1,
	bcrViewer = 2,
	bcrPreviewer = 3,
	bcrUploader = 4,
	bcrPreviewerUploader = 5,
	bcrViewerUploader = 6,
	bcrCoOwner = 7
} TSBBoxCollaborationRole;

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_StartAuthorization(TElBoxDataStorageHandle _Handle, const char * pcRedirectURL, int32_t szRedirectURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_CompleteAuthorization(TElBoxDataStorageHandle _Handle, const char * pcAuthorizationCode, int32_t szAuthorizationCode);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_CloseSession(TElBoxDataStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_AcquireFile(TElBoxDataStorageHandle _Handle, const char * pcID, int32_t szID, TElBoxFileHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_AcquireFolder(TElBoxDataStorageHandle _Handle, const char * pcID, int32_t szID, TElBoxFolderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_CopyObject(TElBoxDataStorageHandle _Handle, TElBoxDataStorageObjectHandle Obj, TElBoxFolderHandle Destination, TElBoxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_CopyObject_1(TElBoxDataStorageHandle _Handle, TElBoxDataStorageObjectHandle Obj, TElBoxFolderHandle Destination, const char * pcNewName, int32_t szNewName, TElBoxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_GetAccountInfo(TElBoxDataStorageHandle _Handle, TElBoxUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_ListTrashed(TElBoxDataStorageHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_PurgeObject(TElBoxDataStorageHandle _Handle, TElBoxDataStorageObjectHandle * Obj);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_RestoreObject(TElBoxDataStorageHandle _Handle, TElBoxDataStorageObjectHandle Obj);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_RestoreObject_1(TElBoxDataStorageHandle _Handle, TElBoxDataStorageObjectHandle Obj, TElBoxFolderHandle NewParent, const char * pcNewName, int32_t szNewName);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_AccessToken(TElBoxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_Groups(TElBoxDataStorageHandle _Handle, TElBoxGroupsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_Users(TElBoxDataStorageHandle _Handle, TElBoxUsersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_ClientID(TElBoxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_set_ClientID(TElBoxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_ClientSecret(TElBoxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_set_ClientSecret(TElBoxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_HTTPClient(TElBoxDataStorageHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_set_HTTPClient(TElBoxDataStorageHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_PassthroughMode(TElBoxDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_set_PassthroughMode(TElBoxDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_RefreshToken(TElBoxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_set_RefreshToken(TElBoxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_get_UseETags(TElBoxDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_set_UseETags(TElBoxDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorage_Create(TComponentHandle AOwner, TElBoxDataStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_Assign(TElBoxDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_Copy(TElBoxDataStorageObjectHandle _Handle, TElBoxFolderHandle Destination, TElBoxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_Copy_1(TElBoxDataStorageObjectHandle _Handle, TElBoxFolderHandle Destination, const char * pcNewName, int32_t szNewName, TElBoxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_Delete(TElBoxDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_Move(TElBoxDataStorageObjectHandle _Handle, TElBoxFolderHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_Rename(TElBoxDataStorageObjectHandle _Handle, const char * pcNewName, int32_t szNewName);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_Purge(TElBoxDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_TransferOwnership(TElBoxDataStorageObjectHandle _Handle, TElBoxUserInfoHandle NewOwner);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_ContentCreatedAt(TElBoxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_ContentModifiedAt(TElBoxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_CreatedAt(TElBoxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_CreatedBy(TElBoxDataStorageObjectHandle _Handle, TElBoxUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_Description(TElBoxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_set_Description(TElBoxDataStorageObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_ETag(TElBoxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_ID(TElBoxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_ModifiedAt(TElBoxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_ModifiedBy(TElBoxDataStorageObjectHandle _Handle, TElBoxUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_OwnedBy(TElBoxDataStorageObjectHandle _Handle, TElBoxUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_ParentID(TElBoxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_PurgedAt(TElBoxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_SequenceID(TElBoxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_SharedLink(TElBoxDataStorageObjectHandle _Handle, TElBoxSharedLinkHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_Size(TElBoxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_Status(TElBoxDataStorageObjectHandle _Handle, TSBBoxObjectStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_get_TrashedAt(TElBoxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObject_Create(TElBoxDataStorageHandle AStorage, TElBoxDataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELBOXFILE
SB_IMPORT uint32_t SB_APIENTRY TElBoxFile_Assign(TElBoxFileHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFile_Clone(TElBoxFileHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFile_Write(TElBoxFileHandle _Handle, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFile_Write_1(TElBoxFileHandle _Handle, TStreamHandle Data, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFile_get_Comments(TElBoxFileHandle _Handle, TElBoxCommentsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFile_get_Sha1(TElBoxFileHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFile_get_VersionNumber(TElBoxFileHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFile_Create(TElBoxDataStorageHandle AStorage, TElBoxFileHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXFILE */

#ifdef SB_USE_CLASS_TELBOXFOLDER
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_Assign(TElBoxFolderHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_Clone(TElBoxFolderHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_CreateFolder(TElBoxFolderHandle _Handle, const char * pcName, int32_t szName, TElBoxFolderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_CreateObject(TElBoxFolderHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler, TElBoxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_CreateObject_1(TElBoxFolderHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Data, int64_t DataCreatedAt, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandlerHandle Handler, TElBoxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_Delete(TElBoxFolderHandle _Handle, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_List(TElBoxFolderHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_get_Collaborations(TElBoxFolderHandle _Handle, TElBoxCollaborationsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_get_SyncState(TElBoxFolderHandle _Handle, TSBBoxSyncStateRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_set_SyncState(TElBoxFolderHandle _Handle, TSBBoxSyncStateRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxFolder_Create(TElBoxDataStorageHandle AStorage, TElBoxFolderHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXFOLDER */

#ifdef SB_USE_CLASS_TELBOXGROUPINFO
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupInfo_get_ID(TElBoxGroupInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupInfo_get_Name(TElBoxGroupInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupInfo_Create(TElBoxGroupInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXGROUPINFO */

#ifdef SB_USE_CLASS_TELBOXUSERINFO
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserInfo_Assign(TElBoxUserInfoHandle _Handle, TElBoxUserInfoHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserInfo_Clone(TElBoxUserInfoHandle _Handle, TElBoxUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserInfo_get_ID(TElBoxUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserInfo_get_Login(TElBoxUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserInfo_get_Name(TElBoxUserInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserInfo_Create(TElBoxUserInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

#ifdef SB_USE_CLASS_TELBOXENTERPRISE
SB_IMPORT uint32_t SB_APIENTRY TElBoxEnterprise_get_ID(TElBoxEnterpriseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxEnterprise_get_Name(TElBoxEnterpriseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxEnterprise_Create(TElBoxEnterpriseHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXENTERPRISE */

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAlias_Delete(TElBoxUserEmailAliasHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAlias_MakePrimary(TElBoxUserEmailAliasHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAlias_get_Email(TElBoxUserEmailAliasHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAlias_get_ID(TElBoxUserEmailAliasHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAlias_get_IsConfirmed(TElBoxUserEmailAliasHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAlias_get_IsPrimary(TElBoxUserEmailAliasHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAlias_get_Owner(TElBoxUserEmailAliasHandle _Handle, TElBoxUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAlias_Create(TElBoxUserHandle AOwner, TElBoxUserEmailAliasHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIASES
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAliases_Add(TElBoxUserEmailAliasesHandle _Handle, const char * pcEmail, int32_t szEmail, TElBoxUserEmailAliasHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAliases_IndexOf(TElBoxUserEmailAliasesHandle _Handle, TElBoxUserEmailAliasHandle Alias, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAliases_IndexOf_1(TElBoxUserEmailAliasesHandle _Handle, const char * pcID, int32_t szID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAliases_Refresh(TElBoxUserEmailAliasesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAliases_get_Count(TElBoxUserEmailAliasesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAliases_get_Items(TElBoxUserEmailAliasesHandle _Handle, int32_t Index, TElBoxUserEmailAliasHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUserEmailAliases_Create(TElBoxUserHandle AOwner, TElBoxUserEmailAliasesHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIASES */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIP
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembership_Discontinue(TElBoxGroupMembershipHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembership_get_GroupID(TElBoxGroupMembershipHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembership_get_GroupName(TElBoxGroupMembershipHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembership_get_ID(TElBoxGroupMembershipHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembership_get_JoinedAt(TElBoxGroupMembershipHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembership_get_Role(TElBoxGroupMembershipHandle _Handle, TSBBoxGroupRoleRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembership_set_Role(TElBoxGroupMembershipHandle _Handle, TSBBoxGroupRoleRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembership_Create(TElBoxUserHandle AOwner, TElBoxGroupMembershipHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIP */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMemberships_Join(TElBoxGroupMembershipsHandle _Handle, TElBoxGroupHandle Group, TElBoxGroupMembershipHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMemberships_Refresh(TElBoxGroupMembershipsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMemberships_get_Count(TElBoxGroupMembershipsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMemberships_get_Items(TElBoxGroupMembershipsHandle _Handle, int32_t Index, TElBoxGroupMembershipHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMemberships_Create(TElBoxUserHandle AOwner, TElBoxGroupMembershipsHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS */

#ifdef SB_USE_CLASS_TELBOXUSER
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_Assign(TElBoxUserHandle _Handle, TElBoxUserInfoHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_BeginUpdate(TElBoxUserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_Clone(TElBoxUserHandle _Handle, TElBoxUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_Delete(TElBoxUserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_EndUpdate(TElBoxUserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_Refresh(TElBoxUserHandle _Handle, int8_t RequestSpecialFields);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_RemoveFromEnterprise(TElBoxUserHandle _Handle, int8_t Notify);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_RequestPasswordReset(TElBoxUserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Address(TElBoxUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_Address(TElBoxUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_CanSeeManagedUsers(TElBoxUserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_CanSeeManagedUsers(TElBoxUserHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_EmailAliases(TElBoxUserHandle _Handle, TElBoxUserEmailAliasesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Enterprise(TElBoxUserHandle _Handle, TElBoxEnterpriseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_ID(TElBoxUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_IsExemptFromDeviceLimits(TElBoxUserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_IsExemptFromDeviceLimits(TElBoxUserHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_IsExemptFromLoginVerification(TElBoxUserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_IsExemptFromLoginVerification(TElBoxUserHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_IsSyncEnabled(TElBoxUserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_IsSyncEnabled(TElBoxUserHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Login(TElBoxUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Memberships(TElBoxUserHandle _Handle, TElBoxGroupMembershipsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Name(TElBoxUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_Name(TElBoxUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_JobTitle(TElBoxUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_JobTitle(TElBoxUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Language(TElBoxUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_Language(TElBoxUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Phone(TElBoxUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_Phone(TElBoxUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Role(TElBoxUserHandle _Handle, TSBBoxUserRoleRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_Role(TElBoxUserHandle _Handle, TSBBoxUserRoleRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_SpaceAmount(TElBoxUserHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_SpaceAmount(TElBoxUserHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_SpaceUsed(TElBoxUserHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_get_Status(TElBoxUserHandle _Handle, TSBBoxUserStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_set_Status(TElBoxUserHandle _Handle, TSBBoxUserStatusRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUser_Create(TElBoxDataStorageHandle AStorage, TElBoxUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXUSER */

#ifdef SB_USE_CLASS_TELBOXUSERS
SB_IMPORT uint32_t SB_APIENTRY TElBoxUsers_Add(TElBoxUsersHandle _Handle, const char * pcLogin, int32_t szLogin, const char * pcName, int32_t szName, TElBoxUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUsers_Clear(TElBoxUsersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUsers_IndexOf(TElBoxUsersHandle _Handle, TElBoxUserHandle User, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUsers_IndexOf_1(TElBoxUsersHandle _Handle, const char * pcID, int32_t szID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUsers_Refresh(TElBoxUsersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUsers_get_Count(TElBoxUsersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUsers_get_Items(TElBoxUsersHandle _Handle, int32_t Index, TElBoxUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxUsers_Create(TElBoxDataStorageHandle AStorage, TElBoxUsersHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXUSERS */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBER
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_Refresh(TElBoxGroupMemberHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_Remove(TElBoxGroupMemberHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_get_ID(TElBoxGroupMemberHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_get_JoinedAt(TElBoxGroupMemberHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_get_Role(TElBoxGroupMemberHandle _Handle, TSBBoxGroupRoleRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_set_Role(TElBoxGroupMemberHandle _Handle, TSBBoxGroupRoleRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_get_UserID(TElBoxGroupMemberHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_get_UserLogin(TElBoxGroupMemberHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_get_UserName(TElBoxGroupMemberHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMember_Create(TElBoxGroupHandle AOwner, TElBoxGroupMemberHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBER */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERS
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembers_Add(TElBoxGroupMembersHandle _Handle, TElBoxUserHandle User, TElBoxGroupMemberHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembers_Refresh(TElBoxGroupMembersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembers_get_Count(TElBoxGroupMembersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembers_get_Items(TElBoxGroupMembersHandle _Handle, int32_t Index, TElBoxGroupMemberHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroupMembers_Create(TElBoxGroupHandle AOwner, TElBoxGroupMembersHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERS */

#ifdef SB_USE_CLASS_TELBOXGROUP
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroup_Delete(TElBoxGroupHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroup_Refresh(TElBoxGroupHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroup_get_CreatedAt(TElBoxGroupHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroup_get_Members(TElBoxGroupHandle _Handle, TElBoxGroupMembersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroup_get_ModifiedAt(TElBoxGroupHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroup_get_Name(TElBoxGroupHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroup_set_Name(TElBoxGroupHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroup_Create(TElBoxDataStorageHandle AStorage, TElBoxGroupHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXGROUP */

#ifdef SB_USE_CLASS_TELBOXGROUPS
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroups_Add(TElBoxGroupsHandle _Handle, const char * pcName, int32_t szName, TElBoxGroupHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroups_IndexOf(TElBoxGroupsHandle _Handle, const char * pcID, int32_t szID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroups_IndexOf_1(TElBoxGroupsHandle _Handle, TElBoxGroupHandle Group, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroups_Refresh(TElBoxGroupsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroups_get_Count(TElBoxGroupsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroups_get_Item(TElBoxGroupsHandle _Handle, int32_t Index, TElBoxGroupHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxGroups_Create(TElBoxDataStorageHandle AStorage, TElBoxGroupsHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXGROUPS */

#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_Assign(TElBoxSharedLinkHandle _Handle, TElBoxSharedLinkHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_Clone(TElBoxSharedLinkHandle _Handle, TElBoxSharedLinkHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_Access(TElBoxSharedLinkHandle _Handle, TSBBoxSharedLinkAccessRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_DownloadCount(TElBoxSharedLinkHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_DownloadURL(TElBoxSharedLinkHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_IsPasswordEnabled(TElBoxSharedLinkHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_Permissions(TElBoxSharedLinkHandle _Handle, TElBoxSharedLinkPermissionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_PreviewCount(TElBoxSharedLinkHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_UnsharedAt(TElBoxSharedLinkHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_URL(TElBoxSharedLinkHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_get_VanityURL(TElBoxSharedLinkHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLink_Create(TElBoxDataStorageObjectHandle AOwner, TElBoxSharedLinkHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */

#ifdef SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLinkPermissions_Assign(TElBoxSharedLinkPermissionsHandle _Handle, TElBoxSharedLinkPermissionsHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLinkPermissions_Clone(TElBoxSharedLinkPermissionsHandle _Handle, TElBoxSharedLinkPermissionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLinkPermissions_get_CanDownload(TElBoxSharedLinkPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLinkPermissions_get_CanPreview(TElBoxSharedLinkPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxSharedLinkPermissions_Create(TElBoxSharedLinkHandle AOwner, TElBoxSharedLinkPermissionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_Accept(TElBoxCollaborationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_Delete(TElBoxCollaborationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_Refresh(TElBoxCollaborationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_Reject(TElBoxCollaborationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_AcknowledgedAt(TElBoxCollaborationHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_CreatedAt(TElBoxCollaborationHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_CreatedBy(TElBoxCollaborationHandle _Handle, TElBoxUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_ExpiresAt(TElBoxCollaborationHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_Group(TElBoxCollaborationHandle _Handle, TElBoxGroupInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_ID(TElBoxCollaborationHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_ModifiedAt(TElBoxCollaborationHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_Role(TElBoxCollaborationHandle _Handle, TSBBoxCollaborationRoleRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_set_Role(TElBoxCollaborationHandle _Handle, TSBBoxCollaborationRoleRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_Status(TElBoxCollaborationHandle _Handle, TSBBoxCollaborationStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_get_User(TElBoxCollaborationHandle _Handle, TElBoxUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaboration_Create(TElBoxFolderHandle AOwner, TElBoxCollaborationHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATIONS
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_Add(TElBoxCollaborationsHandle _Handle, TElBoxGroupInfoHandle Group, TSBBoxCollaborationRoleRaw Role, int8_t Notify, TElBoxCollaborationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_Add_1(TElBoxCollaborationsHandle _Handle, TElBoxUserInfoHandle User, TSBBoxCollaborationRoleRaw Role, int8_t Notify, TElBoxCollaborationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_Add_2(TElBoxCollaborationsHandle _Handle, const char * pcUserLogin, int32_t szUserLogin, TSBBoxCollaborationRoleRaw Role, int8_t Notify, TElBoxCollaborationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_IndexOf(TElBoxCollaborationsHandle _Handle, const char * pcID, int32_t szID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_IndexOf_1(TElBoxCollaborationsHandle _Handle, TElBoxCollaborationHandle Collaboration, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_Refresh(TElBoxCollaborationsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_get_Count(TElBoxCollaborationsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_get_Item(TElBoxCollaborationsHandle _Handle, int32_t Index, TElBoxCollaborationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxCollaborations_Create(TElBoxFolderHandle AOwner, TElBoxCollaborationsHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXCOLLABORATIONS */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECTPERMISSIONS
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_Assign(TElBoxDataStorageObjectPermissionsHandle _Handle, TElBoxDataStorageObjectPermissionsHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_Clone(TElBoxDataStorageObjectPermissionsHandle _Handle, TElBoxDataStorageObjectPermissionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanComment(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanDelete(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanDownload(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanInviteCollaborator(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanPreview(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanRename(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanSetShareAccess(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanShare(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_get_CanUpload(TElBoxDataStorageObjectPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxDataStorageObjectPermissions_Create(TElBoxDataStorageObjectHandle AOwner, TElBoxDataStorageObjectPermissionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECTPERMISSIONS */

#ifdef SB_USE_CLASS_TELBOXCOMMENT
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_Clone(TElBoxCommentHandle _Handle, TElBoxCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_Delete(TElBoxCommentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_Refresh(TElBoxCommentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_Reply(TElBoxCommentHandle _Handle, const char * pcMessage, int32_t szMessage, TElBoxCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_get_CreatedAt(TElBoxCommentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_get_CreatedBy(TElBoxCommentHandle _Handle, TElBoxUserInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_get_ID(TElBoxCommentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_get_IsReply(TElBoxCommentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_get_Message(TElBoxCommentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_set_Message(TElBoxCommentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_get_ModifiedAt(TElBoxCommentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_get_TaggedMessage(TElBoxCommentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComment_Create(TElBoxFileHandle AOwner, TElBoxCommentHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

#ifdef SB_USE_CLASS_TELBOXCOMMENTS
SB_IMPORT uint32_t SB_APIENTRY TElBoxComments_Add(TElBoxCommentsHandle _Handle, const char * pcMessage, int32_t szMessage, TElBoxCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComments_IndexOf(TElBoxCommentsHandle _Handle, const char * pcID, int32_t szID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComments_IndexOf_1(TElBoxCommentsHandle _Handle, TElBoxCommentHandle Comment, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComments_Refresh(TElBoxCommentsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComments_get_Count(TElBoxCommentsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComments_get_Item(TElBoxCommentsHandle _Handle, int32_t Index, TElBoxCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBoxComments_Create(TElBoxFileHandle AOwner, TElBoxCommentsHandle * OutResult);
#endif /* SB_USE_CLASS_TELBOXCOMMENTS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBoxDataStorage;
class TElBoxDataStorageObject;
class TElBoxFile;
class TElBoxFolder;
class TElBoxGroup;
class TElBoxUser;
class TElBoxEnterprise;
class TElBoxUserEmailAlias;
class TElBoxUserEmailAliases;
class TElBoxGroupMembership;
class TElBoxGroupMemberships;
class TElBoxUserInfo;
class TElBoxUsers;
class TElBoxGroupMember;
class TElBoxGroupMembers;
class TElBoxGroupInfo;
class TElBoxGroups;
class TElBoxSharedLink;
class TElBoxSharedLinkPermissions;
class TElBoxCollaboration;
class TElBoxCollaborations;
class TElBoxDataStorageObjectPermissions;
class TElBoxComment;
class TElBoxComments;

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
class TElBoxDataStorage: public TElCustomDataStorage
{
	private:
		SB_DISABLE_COPY(TElBoxDataStorage)
#ifdef SB_USE_CLASS_TELBOXGROUPS
		TElBoxGroups* _Inst_Groups;
#endif /* SB_USE_CLASS_TELBOXGROUPS */
#ifdef SB_USE_CLASS_TELBOXUSERS
		TElBoxUsers* _Inst_Users;
#endif /* SB_USE_CLASS_TELBOXUSERS */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		void StartAuthorization(const std::string &RedirectURL, std::string &OutResult);

		void CompleteAuthorization(const std::string &AuthorizationCode);

		void CloseSession();

#ifdef SB_USE_CLASS_TELBOXFILE
		TElBoxFileHandle AcquireFile(const std::string &ID);
#endif /* SB_USE_CLASS_TELBOXFILE */

#ifdef SB_USE_CLASS_TELBOXFOLDER
		TElBoxFolderHandle AcquireFolder(const std::string &ID);
#endif /* SB_USE_CLASS_TELBOXFOLDER */

#ifdef SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER
		TElBoxDataStorageObjectHandle CopyObject(TElBoxDataStorageObject &Obj, TElBoxFolder &Destination);

		TElBoxDataStorageObjectHandle CopyObject(TElBoxDataStorageObject *Obj, TElBoxFolder *Destination);
#endif /* SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER */

#ifdef SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER
		TElBoxDataStorageObjectHandle CopyObject(TElBoxDataStorageObject &Obj, TElBoxFolder &Destination, const std::string &NewName);

		TElBoxDataStorageObjectHandle CopyObject(TElBoxDataStorageObject *Obj, TElBoxFolder *Destination, const std::string &NewName);
#endif /* SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER */

#ifdef SB_USE_CLASS_TELBOXUSER
		TElBoxUserHandle GetAccountInfo();
#endif /* SB_USE_CLASS_TELBOXUSER */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void ListTrashed(TElDataStorageObjectList &Objects);

		void ListTrashed(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
		void PurgeObject(TElBoxDataStorageObject &Obj);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
		void RestoreObject(TElBoxDataStorageObject &Obj);

		void RestoreObject(TElBoxDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER
		void RestoreObject(TElBoxDataStorageObject &Obj, TElBoxFolder &NewParent, const std::string &NewName);

		void RestoreObject(TElBoxDataStorageObject *Obj, TElBoxFolder *NewParent, const std::string &NewName);
#endif /* SB_USE_CLASSES_TELBOXDATASTORAGEOBJECT_AND_TELBOXFOLDER */

		virtual void get_AccessToken(std::string &OutResult);

#ifdef SB_USE_CLASS_TELBOXGROUPS
		virtual TElBoxGroups* get_Groups();

		SB_DECLARE_PROPERTY_GET(TElBoxGroups*, get_Groups, TElBoxDataStorage, Groups);
#endif /* SB_USE_CLASS_TELBOXGROUPS */

#ifdef SB_USE_CLASS_TELBOXUSERS
		virtual TElBoxUsers* get_Users();

		SB_DECLARE_PROPERTY_GET(TElBoxUsers*, get_Users, TElBoxDataStorage, Users);
#endif /* SB_USE_CLASS_TELBOXUSERS */

		virtual void get_ClientID(std::string &OutResult);

		virtual void set_ClientID(const std::string &Value);

		virtual void get_ClientSecret(std::string &OutResult);

		virtual void set_ClientSecret(const std::string &Value);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElBoxDataStorage, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual bool get_PassthroughMode();

		virtual void set_PassthroughMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassthroughMode, set_PassthroughMode, TElBoxDataStorage, PassthroughMode);

		virtual void get_RefreshToken(std::string &OutResult);

		virtual void set_RefreshToken(const std::string &Value);

		virtual bool get_UseETags();

		virtual void set_UseETags(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseETags, set_UseETags, TElBoxDataStorage, UseETags);

		TElBoxDataStorage(TElBoxDataStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElBoxDataStorage(TComponent &AOwner);

		explicit TElBoxDataStorage(TComponent *AOwner);

		virtual ~TElBoxDataStorage();

};
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
class TElBoxDataStorageObject: public TElCustomDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElBoxDataStorageObject)
#ifdef SB_USE_CLASS_TELBOXUSERINFO
		TElBoxUserInfo* _Inst_CreatedBy;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
		TElBoxUserInfo* _Inst_ModifiedBy;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
		TElBoxUserInfo* _Inst_OwnedBy;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
		TElBoxSharedLink* _Inst_SharedLink;
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

#ifdef SB_USE_CLASS_TELBOXFOLDER
		TElBoxDataStorageObjectHandle Copy(TElBoxFolder &Destination);

		TElBoxDataStorageObjectHandle Copy(TElBoxFolder *Destination);
#endif /* SB_USE_CLASS_TELBOXFOLDER */

#ifdef SB_USE_CLASS_TELBOXFOLDER
		TElBoxDataStorageObjectHandle Copy(TElBoxFolder &Destination, const std::string &NewName);

		TElBoxDataStorageObjectHandle Copy(TElBoxFolder *Destination, const std::string &NewName);
#endif /* SB_USE_CLASS_TELBOXFOLDER */

		void Delete();

#ifdef SB_USE_CLASS_TELBOXFOLDER
		void Move(TElBoxFolder &Destination);

		void Move(TElBoxFolder *Destination);
#endif /* SB_USE_CLASS_TELBOXFOLDER */

		void Rename(const std::string &NewName);

		void Purge();

#ifdef SB_USE_CLASS_TELBOXUSERINFO
		void TransferOwnership(TElBoxUserInfo &NewOwner);

		void TransferOwnership(TElBoxUserInfo *NewOwner);
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

		virtual int64_t get_ContentCreatedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ContentCreatedAt, TElBoxDataStorageObject, ContentCreatedAt);

		virtual int64_t get_ContentModifiedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ContentModifiedAt, TElBoxDataStorageObject, ContentModifiedAt);

		virtual int64_t get_CreatedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedAt, TElBoxDataStorageObject, CreatedAt);

#ifdef SB_USE_CLASS_TELBOXUSERINFO
		virtual TElBoxUserInfo* get_CreatedBy();

		SB_DECLARE_PROPERTY_GET(TElBoxUserInfo*, get_CreatedBy, TElBoxDataStorageObject, CreatedBy);
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

		virtual void get_Description(std::string &OutResult);

		virtual void set_Description(const std::string &Value);

		virtual void get_ETag(std::string &OutResult);

		virtual void get_ID(std::string &OutResult);

		virtual int64_t get_ModifiedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ModifiedAt, TElBoxDataStorageObject, ModifiedAt);

#ifdef SB_USE_CLASS_TELBOXUSERINFO
		virtual TElBoxUserInfo* get_ModifiedBy();

		SB_DECLARE_PROPERTY_GET(TElBoxUserInfo*, get_ModifiedBy, TElBoxDataStorageObject, ModifiedBy);
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

#ifdef SB_USE_CLASS_TELBOXUSERINFO
		virtual TElBoxUserInfo* get_OwnedBy();

		SB_DECLARE_PROPERTY_GET(TElBoxUserInfo*, get_OwnedBy, TElBoxDataStorageObject, OwnedBy);
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

		virtual void get_ParentID(std::string &OutResult);

		virtual int64_t get_PurgedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_PurgedAt, TElBoxDataStorageObject, PurgedAt);

		virtual void get_SequenceID(std::string &OutResult);

#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
		virtual TElBoxSharedLink* get_SharedLink();

		SB_DECLARE_PROPERTY_GET(TElBoxSharedLink*, get_SharedLink, TElBoxDataStorageObject, SharedLink);
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElBoxDataStorageObject, Size);

		virtual TSBBoxObjectStatus get_Status();

		SB_DECLARE_PROPERTY_GET(TSBBoxObjectStatus, get_Status, TElBoxDataStorageObject, Status);

		virtual int64_t get_TrashedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TrashedAt, TElBoxDataStorageObject, TrashedAt);

		TElBoxDataStorageObject(TElBoxDataStorageObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
		explicit TElBoxDataStorageObject(TElBoxDataStorage &AStorage);

		explicit TElBoxDataStorageObject(TElBoxDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

		virtual ~TElBoxDataStorageObject();

};
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELBOXFILE
class TElBoxFile: public TElBoxDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElBoxFile)
#ifdef SB_USE_CLASS_TELBOXCOMMENTS
		TElBoxComments* _Inst_Comments;
#endif /* SB_USE_CLASS_TELBOXCOMMENTS */

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual TElCustomDataStorageObjectHandle Clone();

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(TStream &Data, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELBOXCOMMENTS
		virtual TElBoxComments* get_Comments();

		SB_DECLARE_PROPERTY_GET(TElBoxComments*, get_Comments, TElBoxFile, Comments);
#endif /* SB_USE_CLASS_TELBOXCOMMENTS */

		virtual void get_Sha1(std::string &OutResult);

		virtual void get_VersionNumber(std::string &OutResult);

		TElBoxFile(TElBoxFileHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
		explicit TElBoxFile(TElBoxDataStorage &AStorage);

		explicit TElBoxFile(TElBoxDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

		virtual ~TElBoxFile();

};
#endif /* SB_USE_CLASS_TELBOXFILE */

#ifdef SB_USE_CLASS_TELBOXFOLDER
class TElBoxFolder: public TElBoxDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElBoxFolder)
#ifdef SB_USE_CLASS_TELBOXCOLLABORATIONS
		TElBoxCollaborations* _Inst_Collaborations;
#endif /* SB_USE_CLASS_TELBOXCOLLABORATIONS */

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual TElCustomDataStorageObjectHandle Clone();

		TElBoxFolderHandle CreateFolder(const std::string &Name);

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		TElBoxDataStorageObjectHandle CreateObject(const std::string &Name, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		TElBoxDataStorageObjectHandle CreateObject(const std::string &Name, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		TElBoxDataStorageObjectHandle CreateObject(const std::string &Name, TStream &Data, int64_t DataCreatedAt, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandler &Handler);

		TElBoxDataStorageObjectHandle CreateObject(const std::string &Name, TStream *Data, int64_t DataCreatedAt, int64_t DataModifiedAt, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

		void Delete(bool Recursive);

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(TElDataStorageObjectList &Objects);

		void List(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATIONS
		virtual TElBoxCollaborations* get_Collaborations();

		SB_DECLARE_PROPERTY_GET(TElBoxCollaborations*, get_Collaborations, TElBoxFolder, Collaborations);
#endif /* SB_USE_CLASS_TELBOXCOLLABORATIONS */

		virtual TSBBoxSyncState get_SyncState();

		virtual void set_SyncState(TSBBoxSyncState Value);

		SB_DECLARE_PROPERTY(TSBBoxSyncState, get_SyncState, set_SyncState, TElBoxFolder, SyncState);

		TElBoxFolder(TElBoxFolderHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
		explicit TElBoxFolder(TElBoxDataStorage &AStorage);

		explicit TElBoxFolder(TElBoxDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

		virtual ~TElBoxFolder();

};
#endif /* SB_USE_CLASS_TELBOXFOLDER */

#ifdef SB_USE_CLASS_TELBOXGROUPINFO
class TElBoxGroupInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxGroupInfo)
	public:
		virtual void get_ID(std::string &OutResult);

		virtual void get_Name(std::string &OutResult);

		TElBoxGroupInfo(TElBoxGroupInfoHandle handle, TElOwnHandle ownHandle);

		TElBoxGroupInfo();

};
#endif /* SB_USE_CLASS_TELBOXGROUPINFO */

#ifdef SB_USE_CLASS_TELBOXUSERINFO
class TElBoxUserInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxUserInfo)
	public:
		virtual void Assign(TElBoxUserInfo &Source);

		virtual void Assign(TElBoxUserInfo *Source);

		virtual TElBoxUserInfoHandle Clone();

		virtual void get_ID(std::string &OutResult);

		virtual void get_Login(std::string &OutResult);

		virtual void get_Name(std::string &OutResult);

		TElBoxUserInfo(TElBoxUserInfoHandle handle, TElOwnHandle ownHandle);

		TElBoxUserInfo();

};
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

#ifdef SB_USE_CLASS_TELBOXENTERPRISE
class TElBoxEnterprise: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxEnterprise)
	public:
		virtual void get_ID(std::string &OutResult);

		virtual void get_Name(std::string &OutResult);

		TElBoxEnterprise(TElBoxEnterpriseHandle handle, TElOwnHandle ownHandle);

		TElBoxEnterprise();

};
#endif /* SB_USE_CLASS_TELBOXENTERPRISE */

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
class TElBoxUserEmailAlias: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxUserEmailAlias)
#ifdef SB_USE_CLASS_TELBOXUSER
		TElBoxUser* _Inst_Owner;
#endif /* SB_USE_CLASS_TELBOXUSER */

		void initInstances();

	public:
		void Delete();

		void MakePrimary();

		virtual void get_Email(std::string &OutResult);

		virtual void get_ID(std::string &OutResult);

		virtual bool get_IsConfirmed();

		SB_DECLARE_PROPERTY_GET(bool, get_IsConfirmed, TElBoxUserEmailAlias, IsConfirmed);

		virtual bool get_IsPrimary();

		SB_DECLARE_PROPERTY_GET(bool, get_IsPrimary, TElBoxUserEmailAlias, IsPrimary);

#ifdef SB_USE_CLASS_TELBOXUSER
		virtual TElBoxUser* get_Owner();

		SB_DECLARE_PROPERTY_GET(TElBoxUser*, get_Owner, TElBoxUserEmailAlias, Owner);
#endif /* SB_USE_CLASS_TELBOXUSER */

		TElBoxUserEmailAlias(TElBoxUserEmailAliasHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXUSER
		explicit TElBoxUserEmailAlias(TElBoxUser &AOwner);

		explicit TElBoxUserEmailAlias(TElBoxUser *AOwner);
#endif /* SB_USE_CLASS_TELBOXUSER */

		virtual ~TElBoxUserEmailAlias();

};
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIASES
class TElBoxUserEmailAliases: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxUserEmailAliases)
#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
		TElBoxUserEmailAlias* _Inst_Items;
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
		TElBoxUserEmailAliasHandle Add(const std::string &Email);
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
		int32_t IndexOf(TElBoxUserEmailAlias &Alias);

		int32_t IndexOf(TElBoxUserEmailAlias *Alias);
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

		int32_t IndexOf(const std::string &ID);

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElBoxUserEmailAliases, Count);

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIAS
		virtual TElBoxUserEmailAlias* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIAS */

		TElBoxUserEmailAliases(TElBoxUserEmailAliasesHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXUSER
		explicit TElBoxUserEmailAliases(TElBoxUser &AOwner);

		explicit TElBoxUserEmailAliases(TElBoxUser *AOwner);
#endif /* SB_USE_CLASS_TELBOXUSER */

		virtual ~TElBoxUserEmailAliases();

};
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIASES */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIP
class TElBoxGroupMembership: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxGroupMembership)
	public:
		void Discontinue();

		virtual void get_GroupID(std::string &OutResult);

		virtual void get_GroupName(std::string &OutResult);

		virtual void get_ID(std::string &OutResult);

		virtual int64_t get_JoinedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_JoinedAt, TElBoxGroupMembership, JoinedAt);

		virtual TSBBoxGroupRole get_Role();

		virtual void set_Role(TSBBoxGroupRole Value);

		SB_DECLARE_PROPERTY(TSBBoxGroupRole, get_Role, set_Role, TElBoxGroupMembership, Role);

		TElBoxGroupMembership(TElBoxGroupMembershipHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXUSER
		explicit TElBoxGroupMembership(TElBoxUser &AOwner);

		explicit TElBoxGroupMembership(TElBoxUser *AOwner);
#endif /* SB_USE_CLASS_TELBOXUSER */

};
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIP */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS
class TElBoxGroupMemberships: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxGroupMemberships)
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIP
		TElBoxGroupMembership* _Inst_Items;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIP */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELBOXGROUP_AND_TELBOXGROUPMEMBERSHIP
		TElBoxGroupMembershipHandle Join(TElBoxGroup &Group);

		TElBoxGroupMembershipHandle Join(TElBoxGroup *Group);
#endif /* SB_USE_CLASSES_TELBOXGROUP_AND_TELBOXGROUPMEMBERSHIP */

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElBoxGroupMemberships, Count);

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIP
		virtual TElBoxGroupMembership* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIP */

		TElBoxGroupMemberships(TElBoxGroupMembershipsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXUSER
		explicit TElBoxGroupMemberships(TElBoxUser &AOwner);

		explicit TElBoxGroupMemberships(TElBoxUser *AOwner);
#endif /* SB_USE_CLASS_TELBOXUSER */

		virtual ~TElBoxGroupMemberships();

};
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS */

#ifdef SB_USE_CLASS_TELBOXUSER
class TElBoxUser: public TElBoxUserInfo
{
	private:
		SB_DISABLE_COPY(TElBoxUser)
#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIASES
		TElBoxUserEmailAliases* _Inst_EmailAliases;
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIASES */
#ifdef SB_USE_CLASS_TELBOXENTERPRISE
		TElBoxEnterprise* _Inst_Enterprise;
#endif /* SB_USE_CLASS_TELBOXENTERPRISE */
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS
		TElBoxGroupMemberships* _Inst_Memberships;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS */

		void initInstances();

	public:
		virtual void Assign(TElBoxUserInfo &Source);

		virtual void Assign(TElBoxUserInfo *Source);

		void BeginUpdate();

		virtual TElBoxUserInfoHandle Clone();

		void Delete();

		void EndUpdate();

		void Refresh(bool RequestSpecialFields);

		void RemoveFromEnterprise(bool Notify);

		void RequestPasswordReset();

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual bool get_CanSeeManagedUsers();

		virtual void set_CanSeeManagedUsers(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanSeeManagedUsers, set_CanSeeManagedUsers, TElBoxUser, CanSeeManagedUsers);

#ifdef SB_USE_CLASS_TELBOXUSEREMAILALIASES
		virtual TElBoxUserEmailAliases* get_EmailAliases();

		SB_DECLARE_PROPERTY_GET(TElBoxUserEmailAliases*, get_EmailAliases, TElBoxUser, EmailAliases);
#endif /* SB_USE_CLASS_TELBOXUSEREMAILALIASES */

#ifdef SB_USE_CLASS_TELBOXENTERPRISE
		virtual TElBoxEnterprise* get_Enterprise();

		SB_DECLARE_PROPERTY_GET(TElBoxEnterprise*, get_Enterprise, TElBoxUser, Enterprise);
#endif /* SB_USE_CLASS_TELBOXENTERPRISE */

		virtual void get_ID(std::string &OutResult);

		virtual bool get_IsExemptFromDeviceLimits();

		virtual void set_IsExemptFromDeviceLimits(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsExemptFromDeviceLimits, set_IsExemptFromDeviceLimits, TElBoxUser, IsExemptFromDeviceLimits);

		virtual bool get_IsExemptFromLoginVerification();

		virtual void set_IsExemptFromLoginVerification(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsExemptFromLoginVerification, set_IsExemptFromLoginVerification, TElBoxUser, IsExemptFromLoginVerification);

		virtual bool get_IsSyncEnabled();

		virtual void set_IsSyncEnabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsSyncEnabled, set_IsSyncEnabled, TElBoxUser, IsSyncEnabled);

		virtual void get_Login(std::string &OutResult);

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS
		virtual TElBoxGroupMemberships* get_Memberships();

		SB_DECLARE_PROPERTY_GET(TElBoxGroupMemberships*, get_Memberships, TElBoxUser, Memberships);
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERSHIPS */

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_JobTitle(std::string &OutResult);

		virtual void set_JobTitle(const std::string &Value);

		virtual void get_Language(std::string &OutResult);

		virtual void set_Language(const std::string &Value);

		virtual void get_Phone(std::string &OutResult);

		virtual void set_Phone(const std::string &Value);

		virtual TSBBoxUserRole get_Role();

		virtual void set_Role(TSBBoxUserRole Value);

		SB_DECLARE_PROPERTY(TSBBoxUserRole, get_Role, set_Role, TElBoxUser, Role);

		virtual int64_t get_SpaceAmount();

		virtual void set_SpaceAmount(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SpaceAmount, set_SpaceAmount, TElBoxUser, SpaceAmount);

		virtual int64_t get_SpaceUsed();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SpaceUsed, TElBoxUser, SpaceUsed);

		virtual TSBBoxUserStatus get_Status();

		virtual void set_Status(TSBBoxUserStatus Value);

		SB_DECLARE_PROPERTY(TSBBoxUserStatus, get_Status, set_Status, TElBoxUser, Status);

		TElBoxUser(TElBoxUserHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
		explicit TElBoxUser(TElBoxDataStorage &AStorage);

		explicit TElBoxUser(TElBoxDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

		virtual ~TElBoxUser();

};
#endif /* SB_USE_CLASS_TELBOXUSER */

#ifdef SB_USE_CLASS_TELBOXUSERS
class TElBoxUsers: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxUsers)
#ifdef SB_USE_CLASS_TELBOXUSER
		TElBoxUser* _Inst_Items;
#endif /* SB_USE_CLASS_TELBOXUSER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELBOXUSER
		TElBoxUserHandle Add(const std::string &Login, const std::string &Name);
#endif /* SB_USE_CLASS_TELBOXUSER */

		void Clear();

#ifdef SB_USE_CLASS_TELBOXUSER
		int32_t IndexOf(TElBoxUser &User);

		int32_t IndexOf(TElBoxUser *User);
#endif /* SB_USE_CLASS_TELBOXUSER */

		int32_t IndexOf(const std::string &ID);

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElBoxUsers, Count);

#ifdef SB_USE_CLASS_TELBOXUSER
		virtual TElBoxUser* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELBOXUSER */

		TElBoxUsers(TElBoxUsersHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
		explicit TElBoxUsers(TElBoxDataStorage &AStorage);

		explicit TElBoxUsers(TElBoxDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

		virtual ~TElBoxUsers();

};
#endif /* SB_USE_CLASS_TELBOXUSERS */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBER
class TElBoxGroupMember: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxGroupMember)
	public:
		void Refresh();

		void Remove();

		virtual void get_ID(std::string &OutResult);

		virtual int64_t get_JoinedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_JoinedAt, TElBoxGroupMember, JoinedAt);

		virtual TSBBoxGroupRole get_Role();

		virtual void set_Role(TSBBoxGroupRole Value);

		SB_DECLARE_PROPERTY(TSBBoxGroupRole, get_Role, set_Role, TElBoxGroupMember, Role);

		virtual void get_UserID(std::string &OutResult);

		virtual void get_UserLogin(std::string &OutResult);

		virtual void get_UserName(std::string &OutResult);

		TElBoxGroupMember(TElBoxGroupMemberHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXGROUP
		explicit TElBoxGroupMember(TElBoxGroup &AOwner);

		explicit TElBoxGroupMember(TElBoxGroup *AOwner);
#endif /* SB_USE_CLASS_TELBOXGROUP */

};
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBER */

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERS
class TElBoxGroupMembers: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxGroupMembers)
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBER
		TElBoxGroupMember* _Inst_Items;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBER */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELBOXGROUPMEMBER_AND_TELBOXUSER
		TElBoxGroupMemberHandle Add(TElBoxUser &User);

		TElBoxGroupMemberHandle Add(TElBoxUser *User);
#endif /* SB_USE_CLASSES_TELBOXGROUPMEMBER_AND_TELBOXUSER */

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElBoxGroupMembers, Count);

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBER
		virtual TElBoxGroupMember* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBER */

		TElBoxGroupMembers(TElBoxGroupMembersHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXGROUP
		explicit TElBoxGroupMembers(TElBoxGroup &AOwner);

		explicit TElBoxGroupMembers(TElBoxGroup *AOwner);
#endif /* SB_USE_CLASS_TELBOXGROUP */

		virtual ~TElBoxGroupMembers();

};
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERS */

#ifdef SB_USE_CLASS_TELBOXGROUP
class TElBoxGroup: public TElBoxGroupInfo
{
	private:
		SB_DISABLE_COPY(TElBoxGroup)
#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERS
		TElBoxGroupMembers* _Inst_Members;
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERS */

		void initInstances();

	public:
		void Delete();

		void Refresh();

		virtual int64_t get_CreatedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedAt, TElBoxGroup, CreatedAt);

#ifdef SB_USE_CLASS_TELBOXGROUPMEMBERS
		virtual TElBoxGroupMembers* get_Members();

		SB_DECLARE_PROPERTY_GET(TElBoxGroupMembers*, get_Members, TElBoxGroup, Members);
#endif /* SB_USE_CLASS_TELBOXGROUPMEMBERS */

		virtual int64_t get_ModifiedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ModifiedAt, TElBoxGroup, ModifiedAt);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		TElBoxGroup(TElBoxGroupHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
		explicit TElBoxGroup(TElBoxDataStorage &AStorage);

		explicit TElBoxGroup(TElBoxDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

		virtual ~TElBoxGroup();

};
#endif /* SB_USE_CLASS_TELBOXGROUP */

#ifdef SB_USE_CLASS_TELBOXGROUPS
class TElBoxGroups: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxGroups)
#ifdef SB_USE_CLASS_TELBOXGROUP
		TElBoxGroup* _Inst_Item;
#endif /* SB_USE_CLASS_TELBOXGROUP */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELBOXGROUP
		TElBoxGroupHandle Add(const std::string &Name);
#endif /* SB_USE_CLASS_TELBOXGROUP */

		int32_t IndexOf(const std::string &ID);

#ifdef SB_USE_CLASS_TELBOXGROUP
		int32_t IndexOf(TElBoxGroup &Group);

		int32_t IndexOf(TElBoxGroup *Group);
#endif /* SB_USE_CLASS_TELBOXGROUP */

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElBoxGroups, Count);

#ifdef SB_USE_CLASS_TELBOXGROUP
		virtual TElBoxGroup* get_Item(int32_t Index);
#endif /* SB_USE_CLASS_TELBOXGROUP */

		TElBoxGroups(TElBoxGroupsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGE
		explicit TElBoxGroups(TElBoxDataStorage &AStorage);

		explicit TElBoxGroups(TElBoxDataStorage *AStorage);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGE */

		virtual ~TElBoxGroups();

};
#endif /* SB_USE_CLASS_TELBOXGROUPS */

#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
class TElBoxSharedLink: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxSharedLink)
#ifdef SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS
		TElBoxSharedLinkPermissions* _Inst_Permissions;
#endif /* SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS */

		void initInstances();

	public:
		void Assign(TElBoxSharedLink &Source);

		void Assign(TElBoxSharedLink *Source);

		TElBoxSharedLinkHandle Clone();

		virtual TSBBoxSharedLinkAccess get_Access();

		SB_DECLARE_PROPERTY_GET(TSBBoxSharedLinkAccess, get_Access, TElBoxSharedLink, Access);

		virtual int64_t get_DownloadCount();

		SB_DECLARE_PROPERTY_GET(int64_t, get_DownloadCount, TElBoxSharedLink, DownloadCount);

		virtual void get_DownloadURL(std::string &OutResult);

		virtual bool get_IsPasswordEnabled();

		SB_DECLARE_PROPERTY_GET(bool, get_IsPasswordEnabled, TElBoxSharedLink, IsPasswordEnabled);

#ifdef SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS
		virtual TElBoxSharedLinkPermissions* get_Permissions();

		SB_DECLARE_PROPERTY_GET(TElBoxSharedLinkPermissions*, get_Permissions, TElBoxSharedLink, Permissions);
#endif /* SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS */

		virtual int64_t get_PreviewCount();

		SB_DECLARE_PROPERTY_GET(int64_t, get_PreviewCount, TElBoxSharedLink, PreviewCount);

		virtual int64_t get_UnsharedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_UnsharedAt, TElBoxSharedLink, UnsharedAt);

		virtual void get_URL(std::string &OutResult);

		virtual void get_VanityURL(std::string &OutResult);

		TElBoxSharedLink(TElBoxSharedLinkHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
		explicit TElBoxSharedLink(TElBoxDataStorageObject &AOwner);

		explicit TElBoxSharedLink(TElBoxDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

		virtual ~TElBoxSharedLink();

};
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */

#ifdef SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS
class TElBoxSharedLinkPermissions: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxSharedLinkPermissions)
	public:
		void Assign(TElBoxSharedLinkPermissions &Source);

		void Assign(TElBoxSharedLinkPermissions *Source);

		TElBoxSharedLinkPermissionsHandle Clone();

		virtual bool get_CanDownload();

		SB_DECLARE_PROPERTY_GET(bool, get_CanDownload, TElBoxSharedLinkPermissions, CanDownload);

		virtual bool get_CanPreview();

		SB_DECLARE_PROPERTY_GET(bool, get_CanPreview, TElBoxSharedLinkPermissions, CanPreview);

		TElBoxSharedLinkPermissions(TElBoxSharedLinkPermissionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXSHAREDLINK
		explicit TElBoxSharedLinkPermissions(TElBoxSharedLink &AOwner);

		explicit TElBoxSharedLinkPermissions(TElBoxSharedLink *AOwner);
#endif /* SB_USE_CLASS_TELBOXSHAREDLINK */

};
#endif /* SB_USE_CLASS_TELBOXSHAREDLINKPERMISSIONS */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
class TElBoxCollaboration: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxCollaboration)
#ifdef SB_USE_CLASS_TELBOXUSERINFO
		TElBoxUserInfo* _Inst_CreatedBy;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */
#ifdef SB_USE_CLASS_TELBOXGROUPINFO
		TElBoxGroupInfo* _Inst_Group;
#endif /* SB_USE_CLASS_TELBOXGROUPINFO */
#ifdef SB_USE_CLASS_TELBOXUSERINFO
		TElBoxUserInfo* _Inst_User;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

		void initInstances();

	public:
		void Accept();

		void Delete();

		void Refresh();

		void Reject();

		virtual int64_t get_AcknowledgedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_AcknowledgedAt, TElBoxCollaboration, AcknowledgedAt);

		virtual int64_t get_CreatedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedAt, TElBoxCollaboration, CreatedAt);

#ifdef SB_USE_CLASS_TELBOXUSERINFO
		virtual TElBoxUserInfo* get_CreatedBy();

		SB_DECLARE_PROPERTY_GET(TElBoxUserInfo*, get_CreatedBy, TElBoxCollaboration, CreatedBy);
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

		virtual int64_t get_ExpiresAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ExpiresAt, TElBoxCollaboration, ExpiresAt);

#ifdef SB_USE_CLASS_TELBOXGROUPINFO
		virtual TElBoxGroupInfo* get_Group();

		SB_DECLARE_PROPERTY_GET(TElBoxGroupInfo*, get_Group, TElBoxCollaboration, Group);
#endif /* SB_USE_CLASS_TELBOXGROUPINFO */

		virtual void get_ID(std::string &OutResult);

		virtual int64_t get_ModifiedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ModifiedAt, TElBoxCollaboration, ModifiedAt);

		virtual TSBBoxCollaborationRole get_Role();

		virtual void set_Role(TSBBoxCollaborationRole Value);

		SB_DECLARE_PROPERTY(TSBBoxCollaborationRole, get_Role, set_Role, TElBoxCollaboration, Role);

		virtual TSBBoxCollaborationStatus get_Status();

		SB_DECLARE_PROPERTY_GET(TSBBoxCollaborationStatus, get_Status, TElBoxCollaboration, Status);

#ifdef SB_USE_CLASS_TELBOXUSERINFO
		virtual TElBoxUserInfo* get_User();

		SB_DECLARE_PROPERTY_GET(TElBoxUserInfo*, get_User, TElBoxCollaboration, User);
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

		TElBoxCollaboration(TElBoxCollaborationHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXFOLDER
		explicit TElBoxCollaboration(TElBoxFolder &AOwner);

		explicit TElBoxCollaboration(TElBoxFolder *AOwner);
#endif /* SB_USE_CLASS_TELBOXFOLDER */

		virtual ~TElBoxCollaboration();

};
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATIONS
class TElBoxCollaborations: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxCollaborations)
#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
		TElBoxCollaboration* _Inst_Item;
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELBOXCOLLABORATION_AND_TELBOXGROUPINFO
		TElBoxCollaborationHandle Add(TElBoxGroupInfo &Group, TSBBoxCollaborationRole Role, bool Notify);

		TElBoxCollaborationHandle Add(TElBoxGroupInfo *Group, TSBBoxCollaborationRole Role, bool Notify);
#endif /* SB_USE_CLASSES_TELBOXCOLLABORATION_AND_TELBOXGROUPINFO */

#ifdef SB_USE_CLASSES_TELBOXCOLLABORATION_AND_TELBOXUSERINFO
		TElBoxCollaborationHandle Add(TElBoxUserInfo &User, TSBBoxCollaborationRole Role, bool Notify);

		TElBoxCollaborationHandle Add(TElBoxUserInfo *User, TSBBoxCollaborationRole Role, bool Notify);
#endif /* SB_USE_CLASSES_TELBOXCOLLABORATION_AND_TELBOXUSERINFO */

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
		TElBoxCollaborationHandle Add(const std::string &UserLogin, TSBBoxCollaborationRole Role, bool Notify);
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

		int32_t IndexOf(const std::string &ID);

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
		int32_t IndexOf(TElBoxCollaboration &Collaboration);

		int32_t IndexOf(TElBoxCollaboration *Collaboration);
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElBoxCollaborations, Count);

#ifdef SB_USE_CLASS_TELBOXCOLLABORATION
		virtual TElBoxCollaboration* get_Item(int32_t Index);
#endif /* SB_USE_CLASS_TELBOXCOLLABORATION */

		TElBoxCollaborations(TElBoxCollaborationsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXFOLDER
		explicit TElBoxCollaborations(TElBoxFolder &AOwner);

		explicit TElBoxCollaborations(TElBoxFolder *AOwner);
#endif /* SB_USE_CLASS_TELBOXFOLDER */

		virtual ~TElBoxCollaborations();

};
#endif /* SB_USE_CLASS_TELBOXCOLLABORATIONS */

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECTPERMISSIONS
class TElBoxDataStorageObjectPermissions: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxDataStorageObjectPermissions)
	public:
		void Assign(TElBoxDataStorageObjectPermissions &Source);

		void Assign(TElBoxDataStorageObjectPermissions *Source);

		TElBoxDataStorageObjectPermissionsHandle Clone();

		virtual bool get_CanComment();

		SB_DECLARE_PROPERTY_GET(bool, get_CanComment, TElBoxDataStorageObjectPermissions, CanComment);

		virtual bool get_CanDelete();

		SB_DECLARE_PROPERTY_GET(bool, get_CanDelete, TElBoxDataStorageObjectPermissions, CanDelete);

		virtual bool get_CanDownload();

		SB_DECLARE_PROPERTY_GET(bool, get_CanDownload, TElBoxDataStorageObjectPermissions, CanDownload);

		virtual bool get_CanInviteCollaborator();

		SB_DECLARE_PROPERTY_GET(bool, get_CanInviteCollaborator, TElBoxDataStorageObjectPermissions, CanInviteCollaborator);

		virtual bool get_CanPreview();

		SB_DECLARE_PROPERTY_GET(bool, get_CanPreview, TElBoxDataStorageObjectPermissions, CanPreview);

		virtual bool get_CanRename();

		SB_DECLARE_PROPERTY_GET(bool, get_CanRename, TElBoxDataStorageObjectPermissions, CanRename);

		virtual bool get_CanSetShareAccess();

		SB_DECLARE_PROPERTY_GET(bool, get_CanSetShareAccess, TElBoxDataStorageObjectPermissions, CanSetShareAccess);

		virtual bool get_CanShare();

		SB_DECLARE_PROPERTY_GET(bool, get_CanShare, TElBoxDataStorageObjectPermissions, CanShare);

		virtual bool get_CanUpload();

		SB_DECLARE_PROPERTY_GET(bool, get_CanUpload, TElBoxDataStorageObjectPermissions, CanUpload);

		TElBoxDataStorageObjectPermissions(TElBoxDataStorageObjectPermissionsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXDATASTORAGEOBJECT
		explicit TElBoxDataStorageObjectPermissions(TElBoxDataStorageObject &AOwner);

		explicit TElBoxDataStorageObjectPermissions(TElBoxDataStorageObject *AOwner);
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECT */

};
#endif /* SB_USE_CLASS_TELBOXDATASTORAGEOBJECTPERMISSIONS */

#ifdef SB_USE_CLASS_TELBOXCOMMENT
class TElBoxComment: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxComment)
#ifdef SB_USE_CLASS_TELBOXUSERINFO
		TElBoxUserInfo* _Inst_CreatedBy;
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

		void initInstances();

	public:
		TElBoxCommentHandle Clone();

		void Delete();

		void Refresh();

		TElBoxCommentHandle Reply(const std::string &Message);

		virtual int64_t get_CreatedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreatedAt, TElBoxComment, CreatedAt);

#ifdef SB_USE_CLASS_TELBOXUSERINFO
		virtual TElBoxUserInfo* get_CreatedBy();

		SB_DECLARE_PROPERTY_GET(TElBoxUserInfo*, get_CreatedBy, TElBoxComment, CreatedBy);
#endif /* SB_USE_CLASS_TELBOXUSERINFO */

		virtual void get_ID(std::string &OutResult);

		virtual bool get_IsReply();

		SB_DECLARE_PROPERTY_GET(bool, get_IsReply, TElBoxComment, IsReply);

		virtual void get_Message(std::string &OutResult);

		virtual void set_Message(const std::string &Value);

		virtual int64_t get_ModifiedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ModifiedAt, TElBoxComment, ModifiedAt);

		virtual void get_TaggedMessage(std::string &OutResult);

		TElBoxComment(TElBoxCommentHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXFILE
		explicit TElBoxComment(TElBoxFile &AOwner);

		explicit TElBoxComment(TElBoxFile *AOwner);
#endif /* SB_USE_CLASS_TELBOXFILE */

		virtual ~TElBoxComment();

};
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

#ifdef SB_USE_CLASS_TELBOXCOMMENTS
class TElBoxComments: public TObject
{
	private:
		SB_DISABLE_COPY(TElBoxComments)
#ifdef SB_USE_CLASS_TELBOXCOMMENT
		TElBoxComment* _Inst_Item;
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELBOXCOMMENT
		TElBoxCommentHandle Add(const std::string &Message);
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

		int32_t IndexOf(const std::string &ID);

#ifdef SB_USE_CLASS_TELBOXCOMMENT
		int32_t IndexOf(TElBoxComment &Comment);

		int32_t IndexOf(TElBoxComment *Comment);
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

		void Refresh();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElBoxComments, Count);

#ifdef SB_USE_CLASS_TELBOXCOMMENT
		virtual TElBoxComment* get_Item(int32_t Index);
#endif /* SB_USE_CLASS_TELBOXCOMMENT */

		TElBoxComments(TElBoxCommentsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELBOXFILE
		explicit TElBoxComments(TElBoxFile &AOwner);

		explicit TElBoxComments(TElBoxFile *AOwner);
#endif /* SB_USE_CLASS_TELBOXFILE */

		virtual ~TElBoxComments();

};
#endif /* SB_USE_CLASS_TELBOXCOMMENTS */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBBOXDATASTORAGE */

