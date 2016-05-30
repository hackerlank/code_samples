#ifndef __INC_SBWEBDAVCLIENT
#define __INC_SBWEBDAVCLIENT

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
#include "sbxmldefs.h"
#include "sbxmlutils.h"
#include "sbxmlcore.h"
#include "sbxmlcharsets.h"
#include "sbhttpscommon.h"
#include "sbencoding.h"
#include "sbhttpsconstants.h"
#include "sbhttpsclient.h"
#include "sbwebdavcommon.h"
#include "sbhttpswebdavclient.h"
#include "sbdiskfsadapter.h"
#include "sbcustomfsadapter.h"
#include "sbvcard.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SHTTPSWebDavClientNotSet 	"You must set HTTPSWebDAVClient property first"
#define SB_SHTTPSWebDavClientPrecondFailed 	"Precondition failed: "
#define SB_SHTTPSWebDavClientProtectedOrInheritedACE 	"Protected and inherited ACEs can\'t be used in ACL change request"
#define SB_WEBDAV_CLIENT_ERROR_COLLECTION_EXPECTED 	1
#define SB_WEBDAV_CLIENT_ERROR_DOCUMENT_EXPECTED 	2
#define SB_WEBDAV_CLIENT_ERROR_HTTPSWEBDAVCLIENT 	3
#define SB_WEBDAV_CLIENT_ERROR_STATUSCODE 	4
#define SB_WEBDAV_CLIENT_ERROR_FILESIZE 	5
#define SB_WEBDAV_CLIENT_ERROR_OFFSET_TOO_LARGE 	6
#define SB_WEBDAV_CLIENT_ERROR_PRECONDITION_FAILED 	7
#define SB_WEBDAV_CLIENT_ERROR_PROTECTED_OR_INHERITED_ACE 	7
#define SB_WEBDAV_MULTI_STATUS_RESPONSE 	207
#define SB_WEBDAV_NO_CONTENT_RESPONSE 	204

typedef TElClassHandle TElWebDAVClientHandle;

typedef TElWebDAVClientHandle ElWebDAVClientHandle;

typedef TElClassHandle TElWebDAVLockListHandle;

typedef TElWebDAVLockListHandle ElWebDAVLockListHandle;

typedef TElClassHandle TElWebDAVMultistatusResponseHandle;

typedef TElWebDAVMultistatusResponseHandle ElWebDAVMultistatusResponseHandle;

typedef TElClassHandle TElWebDavErrorHandle;

typedef TElClassHandle TElWebDavPrivilegeSetHandle;

typedef TElClassHandle TElWebDavSupportedPrivilegeHandle;

typedef TElClassHandle TElWebDavSupportedPrivilegeSetHandle;

typedef TElClassHandle TElWebDAVPrincipalSearchPropertySetResponseHandle;

typedef TElClassHandle TElWebDAVStorageObjectHandle;

typedef TElWebDAVStorageObjectHandle ElWebDAVStorageObjectHandle;

typedef TElClassHandle TElWebDavErrorResponseHandle;

typedef TElWebDavErrorResponseHandle ElWebDAVErrorResponseHandle;

typedef TElClassHandle TElWebDavObjectListHandle;

typedef TElWebDavObjectListHandle ElWebDavObjectListHandle;

typedef TElClassHandle TElWebDavErrorListHandle;

typedef TElWebDavErrorListHandle ElWebDavErrorListHandle;

typedef TElClassHandle SBWebDAVClient_TElWebDavPrincipalHandle;

typedef TElClassHandle TElWebDavPrincipalListHandle;

typedef TElClassHandle TElCardDavSupportedAddressDataHandle;

typedef TElClassHandle TElCardDavAddressBookInfoHandle;

typedef TElClassHandle TElCardDavReportContextHandle;

typedef uint8_t TSBWebDavClassRaw;

typedef enum
{
	wdcOne = 0,
	wdcTwo = 1,
	wdcThree = 2
} TSBWebDavClass;

typedef uint32_t TSBWebDavClassesRaw;

typedef enum 
{
	f_wdcOne = 1,
	f_wdcTwo = 2,
	f_wdcThree = 4
} TSBWebDavClasses;

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_List(TElWebDAVClientHandle _Handle, TElWebDavObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_List_1(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_List_2(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavObjectListHandle Objects, TSBWebDavDepthRaw Depth);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_List_3(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CreateCollection(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CreateCollection_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Parent, const char * pcName, int32_t szName);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_DeleteObject(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_DeleteObject_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CopyObject(TElWebDAVClientHandle _Handle, const char * pcSrcURL, int32_t szSrcURL, const char * pcDestURL, int32_t szDestURL, int8_t Overwrite, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CopyObject_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Src, TElWebDAVStorageObjectHandle Dest, int8_t Overwrite, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_MoveObject(TElWebDAVClientHandle _Handle, const char * pcSrcURL, int32_t szSrcURL, const char * pcDestURL, int32_t szDestURL, int8_t Overwrite, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_MoveObject_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Src, TElWebDAVStorageObjectHandle Dest, int8_t Overwrite, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Rename(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcNewName, int32_t szNewName, int8_t MoveToRename, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Rename_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, const char * pcNewName, int32_t szNewName, int8_t MoveToRename);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ChangeProperties(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle SetProperties, TElWebDavPropertyInfoListHandle RemoveProperties, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ChangeProperties_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavPropertyInfoListHandle SetProperties, TElWebDavPropertyInfoListHandle RemoveProperties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_SetProperty(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoHandle PropInfo, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_SetProperty_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavPropertyInfoHandle PropInfo);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_RemoveProperty(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoHandle PropInfo, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_RemoveProperty_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavPropertyInfoHandle PropInfo);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ReadProperties(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ReadProperties_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavPropertyInfoListHandle Properties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ReadProperty(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcPropName, int32_t szPropName, TElWebDavPropertyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ReadProperty_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, const char * pcPropName, int32_t szPropName, TElWebDavPropertyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_GetSupportedProperties(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_GetSupportedProperties_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavPropertyInfoListHandle Properties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ReadSupportedProperties(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ReadSupportedProperties_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavPropertyInfoListHandle Properties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ReadAllProperties(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ReadAllProperties_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TElWebDavPropertyInfoListHandle Properties);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Upload(TElWebDAVClientHandle _Handle, const char * pcFilePath, int32_t szFilePath, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Upload_1(TElWebDAVClientHandle _Handle, const char * pcFilePath, int32_t szFilePath, TElWebDAVStorageObjectHandle Dest, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Upload_2(TElWebDAVClientHandle _Handle, const char * pcFilePath, int32_t szFilePath, const char * pcDestURL, int32_t szDestURL, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Upload_3(TElWebDAVClientHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count, const char * pcDestURL, int32_t szDestURL, int64_t RestartFrom, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Upload_4(TElWebDAVClientHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count, TElWebDAVStorageObjectHandle Dest, int64_t RestartFrom, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Upload_5(TElWebDAVClientHandle _Handle, TStreamHandle Stream, const char * pcDestURL, int32_t szDestURL, int64_t RestartFrom, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Upload_6(TElWebDAVClientHandle _Handle, TStreamHandle Stream, TElWebDAVStorageObjectHandle Dest, int64_t RestartFrom, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Download(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcFilePath, int32_t szFilePath, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Download_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, const char * pcFilePath, int32_t szFilePath, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Download_2(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Stream, int32_t Count, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Download_3(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TStreamHandle Stream, int32_t Count, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Download_4(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Download_5(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, TStreamHandle Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_DownloadFile(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcLocalFileName, int32_t szLocalFileName);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_DownloadFile_1(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcLocalFileName, int32_t szLocalFileName, TSBFileTransferModeRaw Mode);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_DownloadFile_2(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcLocalFileName, int32_t szLocalFileName, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_DownloadStream(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle LocalStream, TSBFileTransferModeRaw Mode);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_DownloadStream_1(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle LocalStream, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_UploadFile(TElWebDAVClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcURL, int32_t szURL, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_UploadFile_1(TElWebDAVClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcURL, int32_t szURL, TSBFileTransferModeRaw Mode, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_UploadFile_2(TElWebDAVClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcURL, int32_t szURL, TSBFileTransferModeRaw Mode, int64_t RestartFrom, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_UploadStream(TElWebDAVClientHandle _Handle, TStreamHandle LocalStream, const char * pcURL, int32_t szURL, TSBFileTransferModeRaw Mode, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_UploadStream_1(TElWebDAVClientHandle _Handle, TStreamHandle LocalStream, const char * pcURL, int32_t szURL, TSBFileTransferModeRaw Mode, int64_t RestartFrom, TElWebDAVLockListHandle Locks, TElWebDavErrorListHandle Errors);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CancelRequest(TElWebDAVClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_GetFullURL(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_GetFileSize(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_GetFileSize_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_GetResourceType(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TSBFileTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Lock(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcOwner, int32_t szOwner, TSBWebDavLockScopeRaw Scope, TSBWebDavDepthRaw Depth, int32_t Timeout, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Lock_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Obj, const char * pcOwner, int32_t szOwner, TSBWebDavLockScopeRaw Scope, TSBWebDavDepthRaw Depth, int32_t Timeout, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Unlock(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDAVLockHandle Lock);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_RefreshLock(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDAVLockHandle Lock);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_PrincipalCollectionSet(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle URLs);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_PrincipalCollectionSet(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle URLs);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_ListPrincipals(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPrincipalListHandle List, TSBWebDavDepthRaw Depth);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AclPrincipalPropSetFirst(TElWebDAVClientHandle _Handle, void * * Ctx, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AclPrincipalPropSetNext(TElWebDAVClientHandle _Handle, void * Ctx, TElWebDavPropertyInfoListHandle Properties, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AclPrincipalPropSetClose(TElWebDAVClientHandle _Handle, void * Ctx);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_PrincipalPropertySearchFirst(TElWebDAVClientHandle _Handle, void * * Ctx, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle MatchProperties, TStringListHandle Matches, TElWebDavPropertyInfoListHandle Properties, int8_t ApplyToPrincipalCollectionSet, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_PrincipalPropertySearchFirst(TElWebDAVClientHandle _Handle, void * * Ctx, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle MatchProperties, TElStringListHandle Matches, TElWebDavPropertyInfoListHandle Properties, int8_t ApplyToPrincipalCollectionSet, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_PrincipalPropertySearchNext(TElWebDAVClientHandle _Handle, void * Ctx, TElWebDavPropertyInfoListHandle Properties, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_PrincipalPropertySearchClose(TElWebDAVClientHandle _Handle, void * Ctx);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_PrincipalMatch(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoHandle PrincipalProperty, TElWebDavPropertyInfoListHandle Properties, TElWebDavObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_PrincipalSearchPropertySet(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_InheritedAclSet(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle URLs);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_InheritedAclSet(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle URLs);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AclRestrictions(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavACLRestrictionsHandle Restrictions);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_SupportedPrivilegeSet(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavSupportedPrivilegeSetHandle PrivilegeSet);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CurrentUserPrivilegeSet(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * Privileges);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_GetAcl(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavACLHandle CurrentAcl);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_SetAcl(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebDavACLHandle NewAcl);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CreateAddressBook(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcDisplayName, int32_t szDisplayName, const char * pcDescription, int32_t szDescription, const char * pcLang, int32_t szLang, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CreateAddressBook_1(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Parent, const char * pcName, int32_t szName, const char * pcDisplayName, int32_t szDisplayName, const char * pcDescription, int32_t szDescription, const char * pcLang, int32_t szLang);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CreateAddressBook_2(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcDisplayName, int32_t szDisplayName, const char * pcDescription, int32_t szDescription, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_CreateAddressBook_3(TElWebDAVClientHandle _Handle, TElWebDAVStorageObjectHandle Parent, const char * pcName, int32_t szName, const char * pcDisplayName, int32_t szDisplayName, const char * pcDescription, int32_t szDescription);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_UploadVCard(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Strm, char * pcETag, int32_t * szETag, TElWebDavErrorListHandle Errors, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_UploadVCard_1(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElVCardHandle VCard, char * pcETag, int32_t * szETag, TElWebDavErrorListHandle Errors, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_DownloadVCard(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElVCardHandle * VCard, TElWebDAVLockListHandle Locks);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_GetAddressBookInfo(TElWebDAVClientHandle _Handle, const char * pcURL, int32_t szURL, TElCardDavAddressBookInfoHandle Info);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AddressBookQueryFirst(TElWebDAVClientHandle _Handle, void * * Ctx, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, TStringListHandle AddressDataProps, TElCardDavFilterHandle Filter, int32_t Limit, int8_t All, TSBWebDavDepthRaw Depth, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AddressBookQueryFirst(TElWebDAVClientHandle _Handle, void * * Ctx, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, TElStringListHandle AddressDataProps, TElCardDavFilterHandle Filter, int32_t Limit, int8_t All, TSBWebDavDepthRaw Depth, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AddressBookQueryNext(TElWebDAVClientHandle _Handle, void * Ctx, TElWebDavPropertyInfoListHandle Properties, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AddressBookQueryClose(TElWebDAVClientHandle _Handle, void * Ctx);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AddressBookMultigetFirst(TElWebDAVClientHandle _Handle, void * * Ctx, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, TStringListHandle AddressDataProps, TStringListHandle Hrefs, int8_t All, TSBWebDavDepthRaw Depth, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AddressBookMultigetFirst(TElWebDAVClientHandle _Handle, void * * Ctx, const char * pcURL, int32_t szURL, TElWebDavPropertyInfoListHandle Properties, TElStringListHandle AddressDataProps, TElStringListHandle Hrefs, int8_t All, TSBWebDavDepthRaw Depth, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AddressBookMultigetNext(TElWebDAVClientHandle _Handle, void * Ctx, TElWebDavPropertyInfoListHandle Properties, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_AddressBookMultigetClose(TElWebDAVClientHandle _Handle, void * Ctx);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_CurrentUserPrincipal(TElWebDAVClientHandle _Handle, SBWebDAVClient_TElWebDavPrincipalHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_Authenticated(TElWebDAVClientHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_AddressBookURLs(TElWebDAVClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_AddressBookURLs(TElWebDAVClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_HTTPSWebDAVClient(TElWebDAVClientHandle _Handle, TElHTTPSWebDAVClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_set_HTTPSWebDAVClient(TElWebDAVClientHandle _Handle, TElHTTPSWebDAVClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_FileSystemAdapter(TElWebDAVClientHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_set_FileSystemAdapter(TElWebDAVClientHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_BaseURL(TElWebDAVClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_set_BaseURL(TElWebDAVClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_Owner_AnsiString(TElWebDAVClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_set_Owner_AnsiString(TElWebDAVClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_LastListedURL(TElWebDAVClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_IncludeBackLinks(TElWebDAVClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_set_IncludeBackLinks(TElWebDAVClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_EncodeURL(TElWebDAVClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_set_EncodeURL(TElWebDAVClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_get_SupportedClasses(TElWebDAVClientHandle _Handle, TSBWebDavClassesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVClient_Create(TComponentHandle AOwner, TElWebDAVClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLockList_Merge(TElWebDAVLockListHandle _Handle, const TElWebDAVLockListHandle List);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLockList_Clone(TElWebDAVLockListHandle _Handle, TElWebDAVLockListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLockList_Add(TElWebDAVLockListHandle _Handle, const TElWebDAVLockHandle Lock);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLockList_Remove(TElWebDAVLockListHandle _Handle, const TElWebDAVLockHandle Lock);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLockList_get_Locks(TElWebDAVLockListHandle _Handle, int32_t Idx, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLockList_get_Count(TElWebDAVLockListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLockList_get_ToIfHeader(TElWebDAVLockListHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVLockList_Create(TComponentHandle AOwner, TElWebDAVLockListHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVMULTISTATUSRESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMultistatusResponse_LoadFromStream(TElWebDAVMultistatusResponseHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMultistatusResponse_get_Responses(TElWebDAVMultistatusResponseHandle _Handle, int32_t Idx, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMultistatusResponse_get_Count(TElWebDAVMultistatusResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVMultistatusResponse_Create(TElWebDAVMultistatusResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVMULTISTATUSRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVERROR
SB_IMPORT uint32_t SB_APIENTRY TElWebDavError_LoadFromXML(TElWebDavErrorHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavError_get_NS(TElWebDavErrorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavError_set_NS(TElWebDavErrorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavError_get_Value(TElWebDavErrorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavError_set_Value(TElWebDavErrorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavError_Create(TElWebDavErrorHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVERROR */

#ifdef SB_USE_CLASS_TELWEBDAVPRIVILEGESET
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrivilegeSet_LoadFromXML(TElWebDavPrivilegeSetHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrivilegeSet_get_Value(TElWebDavPrivilegeSetHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrivilegeSet_set_Value(TElWebDavPrivilegeSetHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrivilegeSet_Create(TElWebDavPrivilegeSetHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVPRIVILEGESET */

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_LoadFromXML(TElWebDavSupportedPrivilegeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_get_NS(TElWebDavSupportedPrivilegeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_set_NS(TElWebDavSupportedPrivilegeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_get_Name(TElWebDavSupportedPrivilegeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_set_Name(TElWebDavSupportedPrivilegeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_get_Description(TElWebDavSupportedPrivilegeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_set_Description(TElWebDavSupportedPrivilegeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_get_DescLang(TElWebDavSupportedPrivilegeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_set_DescLang(TElWebDavSupportedPrivilegeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_get__Abstract(TElWebDavSupportedPrivilegeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_set__Abstract(TElWebDavSupportedPrivilegeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_get_Value(TElWebDavSupportedPrivilegeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_set_Value(TElWebDavSupportedPrivilegeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_get_AggregatedPrivileges(TElWebDavSupportedPrivilegeHandle _Handle, int32_t Index, TElWebDavSupportedPrivilegeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_get_AggregatedPrivilegeCount(TElWebDavSupportedPrivilegeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilege_Create(TElWebDavSupportedPrivilegeHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE */

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilegeSet_LoadFromXML(TElWebDavSupportedPrivilegeSetHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilegeSet_IsAbstract(TElWebDavSupportedPrivilegeSetHandle _Handle, int32_t Privilege, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilegeSet_get_AggregatedPrivileges(TElWebDavSupportedPrivilegeSetHandle _Handle, int32_t Index, TElWebDavSupportedPrivilegeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilegeSet_get_AggregatedPrivilegeCount(TElWebDavSupportedPrivilegeSetHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavSupportedPrivilegeSet_Create(TElWebDavSupportedPrivilegeSetHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALSEARCHPROPERTYSETRESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVPrincipalSearchPropertySetResponse_LoadFromStream(TElWebDAVPrincipalSearchPropertySetResponseHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVPrincipalSearchPropertySetResponse_get_Responses(TElWebDAVPrincipalSearchPropertySetResponseHandle _Handle, int32_t Idx, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVPrincipalSearchPropertySetResponse_get_Count(TElWebDAVPrincipalSearchPropertySetResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVPrincipalSearchPropertySetResponse_Create(TElWebDAVPrincipalSearchPropertySetResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALSEARCHPROPERTYSETRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_Clone(TElWebDAVStorageObjectHandle _Handle, TElWebDAVStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_ReadFromXML(TElWebDAVStorageObjectHandle _Handle, TElXMLDOMNodeHandle Node, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_Lock(TElWebDAVStorageObjectHandle _Handle, TSBWebDavLockScopeRaw Scope, TSBWebDavDepthRaw Depth, int32_t Timeout, TElWebDAVLockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_Unlock(TElWebDAVStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_Unlock_1(TElWebDAVStorageObjectHandle _Handle, int32_t Idx);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_GetIfHeader(TElWebDAVStorageObjectHandle _Handle, int8_t WithETag, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_Storage(TElWebDAVStorageObjectHandle _Handle, TElWebDAVClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_ParentURL(TElWebDAVStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_URL(TElWebDAVStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_FullURL(TElWebDAVStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_CreationDate(TElWebDAVStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_DisplayName(TElWebDAVStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_ContentLanguage(TElWebDAVStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_ContentLength(TElWebDAVStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_ContentType(TElWebDAVStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_ETag(TElWebDAVStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_LastModified(TElWebDAVStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_ResourceType(TElWebDAVStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_Collection(TElWebDAVStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_IsAddressBook(TElWebDAVStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_BackLink(TElWebDAVStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_SupportsExclusiveLock(TElWebDAVStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_SupportsSharedLock(TElWebDAVStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_get_Locks(TElWebDAVStorageObjectHandle _Handle, TElWebDAVLockListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_Create(const TElWebDAVClientHandle Storage, const char * pcURL, int32_t szURL, TElWebDAVStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDAVStorageObject_Create_1(const TElWebDAVClientHandle Storage, const char * pcURL, int32_t szURL, int8_t HrefOnly, TElWebDAVStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVERRORRESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorResponse_get_URL(TElWebDavErrorResponseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorResponse_get_Status(TElWebDavErrorResponseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorResponse_get_Error(TElWebDavErrorResponseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorResponse_get_Description(TElWebDavErrorResponseHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorResponse_Create(const TElXMLDOMNodeHandle Node, TElWebDavErrorResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVERRORRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST
SB_IMPORT uint32_t SB_APIENTRY TElWebDavObjectList_Clear(TElWebDavObjectListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavObjectList_get_Objects(TElWebDavObjectListHandle _Handle, int32_t Index, TElWebDAVStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavObjectList_get_Count(TElWebDavObjectListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavObjectList_Create(TElWebDavObjectListHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASS_TELWEBDAVERRORLIST
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorList_Clear(TElWebDavErrorListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorList_get_Objects(TElWebDavErrorListHandle _Handle, int32_t Index, TElWebDavErrorResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorList_get_Count(TElWebDavErrorListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavErrorList_Create(TElWebDavErrorListHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVERRORLIST */

#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_ReadFromXML(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TElXMLDOMNodeHandle Node, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_DisplayName(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_URL(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_PrincipalURL(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_AlternateURISet(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_GroupMemberSet(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_GroupMembership(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_AddressbookHomeSet(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_AlternateURISet(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_GroupMemberSet(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_GroupMembership(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_AddressbookHomeSet(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_AddressURL(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_get_IsGroup(SBWebDAVClient_TElWebDavPrincipalHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_TElWebDavPrincipal_Create(SBWebDAVClient_TElWebDavPrincipalHandle * OutResult);
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALLIST
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalList_Clear(TElWebDavPrincipalListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalList_get_Principals(TElWebDavPrincipalListHandle _Handle, int32_t Index, SBWebDAVClient_TElWebDavPrincipalHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalList_get_Count(TElWebDavPrincipalListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWebDavPrincipalList_Create(TElWebDavPrincipalListHandle * OutResult);
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALLIST */

#ifdef SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA
SB_IMPORT uint32_t SB_APIENTRY TElCardDavSupportedAddressData_get_ContentType(TElCardDavSupportedAddressDataHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavSupportedAddressData_get_Version(TElCardDavSupportedAddressDataHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavSupportedAddressData_Create(TElCardDavSupportedAddressDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA */

#ifdef SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO
SB_IMPORT uint32_t SB_APIENTRY TElCardDavAddressBookInfo_get_Description(TElCardDavAddressBookInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavAddressBookInfo_get_SupportedAddressDataCount(TElCardDavAddressBookInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavAddressBookInfo_get_SupportedAddressData(TElCardDavAddressBookInfoHandle _Handle, int32_t Index, TElCardDavSupportedAddressDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavAddressBookInfo_get_MaxResourceSize(TElCardDavAddressBookInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCardDavAddressBookInfo_Create(TElCardDavAddressBookInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO */

#ifdef SB_USE_CLASS_TELCARDDAVREPORTCONTEXT
SB_IMPORT uint32_t SB_APIENTRY TElCardDavReportContext_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCARDDAVREPORTCONTEXT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElWebDAVClient;
typedef TElWebDAVClient ElWebDAVClient;
class TElWebDAVLockList;
typedef TElWebDAVLockList ElWebDAVLockList;
class TElWebDAVMultistatusResponse;
typedef TElWebDAVMultistatusResponse ElWebDAVMultistatusResponse;
class TElWebDavError;
class TElWebDavPrivilegeSet;
class TElWebDavSupportedPrivilege;
class TElWebDavSupportedPrivilegeSet;
class TElWebDAVPrincipalSearchPropertySetResponse;
class TElWebDAVStorageObject;
typedef TElWebDAVStorageObject ElWebDAVStorageObject;
class TElWebDavErrorResponse;
typedef TElWebDavErrorResponse ElWebDAVErrorResponse;
class TElWebDavObjectList;
typedef TElWebDavObjectList ElWebDavObjectList;
class TElWebDavErrorList;
typedef TElWebDavErrorList ElWebDavErrorList;
class SBWebDAVClient_TElWebDavPrincipal;
class TElWebDavPrincipalList;
class TElCardDavSupportedAddressData;
class TElCardDavAddressBookInfo;
class TElCardDavReportContext;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBWebDavClasses)

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
class TElWebDAVClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElWebDAVClient)
#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
		SBWebDAVClient_TElWebDavPrincipal* _Inst_CurrentUserPrincipal;
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AddressBookURLs;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AddressBookURLs;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELHTTPSWEBDAVCLIENT
		TElHTTPSWebDAVClient* _Inst_HTTPSWebDAVClient;
#endif /* SB_USE_CLASS_TELHTTPSWEBDAVCLIENT */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST
		void List(TElWebDavObjectList &Objects);

		void List(TElWebDavObjectList *Objects);
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST
		void List(const std::string &URL, TElWebDavObjectList &Objects);

		void List(const std::string &URL, TElWebDavObjectList *Objects);
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST
		void List(const std::string &URL, TElWebDavObjectList &Objects, TSBWebDavDepth Depth);

		void List(const std::string &URL, TElWebDavObjectList *Objects, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVOBJECTLIST_AND_TELWEBDAVSTORAGEOBJECT
		void List(TElWebDAVStorageObject &Obj, TElWebDavObjectList &Objects);

		void List(TElWebDAVStorageObject *Obj, TElWebDavObjectList *Objects);
#endif /* SB_USE_CLASSES_TELWEBDAVOBJECTLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
		void CreateCollection(const std::string &URL, TElWebDAVLockList &Locks);

		void CreateCollection(const std::string &URL, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
		void CreateCollection(TElWebDAVStorageObject &Parent, const std::string &Name);

		void CreateCollection(TElWebDAVStorageObject *Parent, const std::string &Name);
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void DeleteObject(const std::string &URL, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void DeleteObject(const std::string &URL, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
		void DeleteObject(TElWebDAVStorageObject &Obj, TElWebDavErrorList &Errors);

		void DeleteObject(TElWebDAVStorageObject *Obj, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void CopyObject(const std::string &SrcURL, const std::string &DestURL, bool Overwrite, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void CopyObject(const std::string &SrcURL, const std::string &DestURL, bool Overwrite, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
		void CopyObject(TElWebDAVStorageObject &Src, TElWebDAVStorageObject &Dest, bool Overwrite, TElWebDavErrorList &Errors);

		void CopyObject(TElWebDAVStorageObject *Src, TElWebDAVStorageObject *Dest, bool Overwrite, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void MoveObject(const std::string &SrcURL, const std::string &DestURL, bool Overwrite, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void MoveObject(const std::string &SrcURL, const std::string &DestURL, bool Overwrite, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
		void MoveObject(TElWebDAVStorageObject &Src, TElWebDAVStorageObject &Dest, bool Overwrite, TElWebDavErrorList &Errors);

		void MoveObject(TElWebDAVStorageObject *Src, TElWebDAVStorageObject *Dest, bool Overwrite, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
		void Rename(const std::string &URL, const std::string &NewName, bool MoveToRename, TElWebDAVLockList &Locks);

		void Rename(const std::string &URL, const std::string &NewName, bool MoveToRename, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
		void Rename(TElWebDAVStorageObject &Obj, const std::string &NewName, bool MoveToRename);

		void Rename(TElWebDAVStorageObject *Obj, const std::string &NewName, bool MoveToRename);
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFOLIST
		void ChangeProperties(const std::string &URL, TElWebDavPropertyInfoList &SetProperties, TElWebDavPropertyInfoList &RemoveProperties, TElWebDAVLockList &Locks);

		void ChangeProperties(const std::string &URL, TElWebDavPropertyInfoList *SetProperties, TElWebDavPropertyInfoList *RemoveProperties, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
		void ChangeProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &SetProperties, TElWebDavPropertyInfoList &RemoveProperties);

		void ChangeProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *SetProperties, TElWebDavPropertyInfoList *RemoveProperties);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFO
		void SetProperty(const std::string &URL, TElWebDavPropertyInfo &PropInfo, TElWebDAVLockList &Locks);

		void SetProperty(const std::string &URL, TElWebDavPropertyInfo *PropInfo, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT
		void SetProperty(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfo &PropInfo);

		void SetProperty(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfo *PropInfo);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFO
		void RemoveProperty(const std::string &URL, TElWebDavPropertyInfo &PropInfo, TElWebDAVLockList &Locks);

		void RemoveProperty(const std::string &URL, TElWebDavPropertyInfo *PropInfo, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT
		void RemoveProperty(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfo &PropInfo);

		void RemoveProperty(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfo *PropInfo);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		void ReadProperties(const std::string &URL, TElWebDavPropertyInfoList &Properties);

		void ReadProperties(const std::string &URL, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
		void ReadProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &Properties);

		void ReadProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFO
		TElWebDavPropertyInfoHandle ReadProperty(const std::string &URL, const std::string &PropName);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFO */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT
		TElWebDavPropertyInfoHandle ReadProperty(TElWebDAVStorageObject &Obj, const std::string &PropName);

		TElWebDavPropertyInfoHandle ReadProperty(TElWebDAVStorageObject *Obj, const std::string &PropName);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		void GetSupportedProperties(const std::string &URL, TElWebDavPropertyInfoList &Properties);

		void GetSupportedProperties(const std::string &URL, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
		void GetSupportedProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &Properties);

		void GetSupportedProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		void ReadSupportedProperties(const std::string &URL, TElWebDavPropertyInfoList &Properties);

		void ReadSupportedProperties(const std::string &URL, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
		void ReadSupportedProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &Properties);

		void ReadSupportedProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		void ReadAllProperties(const std::string &URL, TElWebDavPropertyInfoList &Properties);

		void ReadAllProperties(const std::string &URL, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT
		void ReadAllProperties(TElWebDAVStorageObject &Obj, TElWebDavPropertyInfoList &Properties);

		void ReadAllProperties(TElWebDAVStorageObject *Obj, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void Upload(const std::string &FilePath, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void Upload(const std::string &FilePath, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
		void Upload(const std::string &FilePath, TElWebDAVStorageObject &Dest, TElWebDavErrorList &Errors);

		void Upload(const std::string &FilePath, TElWebDAVStorageObject *Dest, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void Upload(const std::string &FilePath, const std::string &DestURL, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void Upload(const std::string &FilePath, const std::string &DestURL, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void Upload(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, const std::string &DestURL, int64_t RestartFrom, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void Upload(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, const std::string &DestURL, int64_t RestartFrom, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT
		void Upload(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, TElWebDAVStorageObject &Dest, int64_t RestartFrom, TElWebDavErrorList &Errors);

		void Upload(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, TElWebDAVStorageObject *Dest, int64_t RestartFrom, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM
		void Upload(TStream &Stream, const std::string &DestURL, int64_t RestartFrom, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void Upload(TStream *Stream, const std::string &DestURL, int64_t RestartFrom, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM
		void Upload(TStream &Stream, TElWebDAVStorageObject &Dest, int64_t RestartFrom, TElWebDavErrorList &Errors);

		void Upload(TStream *Stream, TElWebDAVStorageObject *Dest, int64_t RestartFrom, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM */

		void Download(const std::string &URL, const std::string &FilePath, bool Overwrite);

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
		void Download(TElWebDAVStorageObject &Obj, const std::string &FilePath, bool Overwrite);

		void Download(TElWebDAVStorageObject *Obj, const std::string &FilePath, bool Overwrite);
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TSTREAM
		void Download(const std::string &URL, TStream &Stream, int32_t Count, int64_t RestartFrom);

		void Download(const std::string &URL, TStream *Stream, int32_t Count, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM
		void Download(TElWebDAVStorageObject &Obj, TStream &Stream, int32_t Count, int64_t RestartFrom);

		void Download(TElWebDAVStorageObject *Obj, TStream *Stream, int32_t Count, int64_t RestartFrom);
#endif /* SB_USE_CLASSES_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TSTREAM
		void Download(const std::string &URL, TStream &Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockList &Locks);

		void Download(const std::string &URL, TStream *Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM
		void Download(TElWebDAVStorageObject &Obj, TStream &Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockList &Locks);

		void Download(TElWebDAVStorageObject *Obj, TStream *Stream, int32_t Count, int64_t RestartFrom, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASSES_TELWEBDAVLOCKLIST_AND_TELWEBDAVSTORAGEOBJECT_AND_TSTREAM */

		void DownloadFile(const std::string &URL, const std::string &LocalFileName);

		void DownloadFile(const std::string &URL, const std::string &LocalFileName, TSBFileTransferMode Mode);

		void DownloadFile(const std::string &URL, const std::string &LocalFileName, TSBFileTransferMode Mode, int64_t RestartFrom);

#ifdef SB_USE_CLASS_TSTREAM
		void DownloadStream(const std::string &URL, TStream &LocalStream, TSBFileTransferMode Mode);

		void DownloadStream(const std::string &URL, TStream *LocalStream, TSBFileTransferMode Mode);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void DownloadStream(const std::string &URL, TStream &LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom);

		void DownloadStream(const std::string &URL, TStream *LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void UploadFile(const std::string &LocalFileName, const std::string &URL, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void UploadFile(const std::string &LocalFileName, const std::string &URL, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void UploadFile(const std::string &LocalFileName, const std::string &URL, TSBFileTransferMode Mode, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void UploadFile(const std::string &LocalFileName, const std::string &URL, TSBFileTransferMode Mode, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void UploadFile(const std::string &LocalFileName, const std::string &URL, TSBFileTransferMode Mode, int64_t RestartFrom, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void UploadFile(const std::string &LocalFileName, const std::string &URL, TSBFileTransferMode Mode, int64_t RestartFrom, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM
		void UploadStream(TStream &LocalStream, const std::string &URL, TSBFileTransferMode Mode, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void UploadStream(TStream *LocalStream, const std::string &URL, TSBFileTransferMode Mode, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM
		void UploadStream(TStream &LocalStream, const std::string &URL, TSBFileTransferMode Mode, int64_t RestartFrom, TElWebDAVLockList &Locks, TElWebDavErrorList &Errors);

		void UploadStream(TStream *LocalStream, const std::string &URL, TSBFileTransferMode Mode, int64_t RestartFrom, TElWebDAVLockList *Locks, TElWebDavErrorList *Errors);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM */

		void CancelRequest();

		void GetFullURL(const std::string &URL, std::string &OutResult);

		int64_t GetFileSize(const std::string &URL);

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
		int64_t GetFileSize(TElWebDAVStorageObject &Obj);

		int64_t GetFileSize(TElWebDAVStorageObject *Obj);
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

		TSBFileType GetResourceType(const std::string &URL);

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		TElWebDAVLockHandle Lock(const std::string &URL, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASSES_TELWEBDAVLOCK_AND_TELWEBDAVSTORAGEOBJECT
		TElWebDAVLockHandle Lock(TElWebDAVStorageObject &Obj, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout);

		TElWebDAVLockHandle Lock(TElWebDAVStorageObject *Obj, const std::string &Owner, TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout);
#endif /* SB_USE_CLASSES_TELWEBDAVLOCK_AND_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		void Unlock(const std::string &URL, TElWebDAVLock &Lock);

		void Unlock(const std::string &URL, TElWebDAVLock *Lock);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		void RefreshLock(const std::string &URL, TElWebDAVLock &Lock);

		void RefreshLock(const std::string &URL, TElWebDAVLock *Lock);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void PrincipalCollectionSet(const std::string &URL, TStringList &URLs);

		void PrincipalCollectionSet(const std::string &URL, TStringList *URLs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void PrincipalCollectionSet(const std::string &URL, TElStringList &URLs);

		void PrincipalCollectionSet(const std::string &URL, TElStringList *URLs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALLIST
		void ListPrincipals(const std::string &URL, TElWebDavPrincipalList &List, TSBWebDavDepth Depth);

		void ListPrincipals(const std::string &URL, TElWebDavPrincipalList *List, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALLIST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		bool AclPrincipalPropSetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties);

		bool AclPrincipalPropSetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		bool AclPrincipalPropSetNext(void * Ctx, TElWebDavPropertyInfoList &Properties);

		bool AclPrincipalPropSetNext(void * Ctx, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

		void AclPrincipalPropSetClose(void * Ctx);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
		bool PrincipalPropertySearchFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &MatchProperties, TStringList &Matches, TElWebDavPropertyInfoList &Properties, bool ApplyToPrincipalCollectionSet);

		bool PrincipalPropertySearchFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *MatchProperties, TStringList *Matches, TElWebDavPropertyInfoList *Properties, bool ApplyToPrincipalCollectionSet);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
		bool PrincipalPropertySearchFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &MatchProperties, TElStringList &Matches, TElWebDavPropertyInfoList &Properties, bool ApplyToPrincipalCollectionSet);

		bool PrincipalPropertySearchFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *MatchProperties, TElStringList *Matches, TElWebDavPropertyInfoList *Properties, bool ApplyToPrincipalCollectionSet);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		bool PrincipalPropertySearchNext(void * Ctx, TElWebDavPropertyInfoList &Properties);

		bool PrincipalPropertySearchNext(void * Ctx, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

		void PrincipalPropertySearchClose(void * Ctx);

#ifdef SB_USE_CLASSES_TELWEBDAVOBJECTLIST_AND_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVPROPERTYINFOLIST
		void PrincipalMatch(const std::string &URL, TElWebDavPropertyInfo &PrincipalProperty, TElWebDavPropertyInfoList &Properties, TElWebDavObjectList &Objects);

		void PrincipalMatch(const std::string &URL, TElWebDavPropertyInfo *PrincipalProperty, TElWebDavPropertyInfoList *Properties, TElWebDavObjectList *Objects);
#endif /* SB_USE_CLASSES_TELWEBDAVOBJECTLIST_AND_TELWEBDAVPROPERTYINFO_AND_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		void PrincipalSearchPropertySet(const std::string &URL, TElWebDavPropertyInfoList &Properties);

		void PrincipalSearchPropertySet(const std::string &URL, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void InheritedAclSet(const std::string &URL, TStringList &URLs);

		void InheritedAclSet(const std::string &URL, TStringList *URLs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void InheritedAclSet(const std::string &URL, TElStringList &URLs);

		void InheritedAclSet(const std::string &URL, TElStringList *URLs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS
		void AclRestrictions(const std::string &URL, TElWebDavACLRestrictions &Restrictions);

		void AclRestrictions(const std::string &URL, TElWebDavACLRestrictions *Restrictions);
#endif /* SB_USE_CLASS_TELWEBDAVACLRESTRICTIONS */

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET
		void SupportedPrivilegeSet(const std::string &URL, TElWebDavSupportedPrivilegeSet &PrivilegeSet);

		void SupportedPrivilegeSet(const std::string &URL, TElWebDavSupportedPrivilegeSet *PrivilegeSet);
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET */

		void CurrentUserPrivilegeSet(const std::string &URL, int32_t &Privileges);

#ifdef SB_USE_CLASS_TELWEBDAVACL
		void GetAcl(const std::string &URL, TElWebDavACL &CurrentAcl);

		void GetAcl(const std::string &URL, TElWebDavACL *CurrentAcl);
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVACL
		void SetAcl(const std::string &URL, TElWebDavACL &NewAcl);

		void SetAcl(const std::string &URL, TElWebDavACL *NewAcl);
#endif /* SB_USE_CLASS_TELWEBDAVACL */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
		void CreateAddressBook(const std::string &URL, const std::string &DisplayName, const std::string &Description, const std::string &Lang, TElWebDAVLockList &Locks);

		void CreateAddressBook(const std::string &URL, const std::string &DisplayName, const std::string &Description, const std::string &Lang, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
		void CreateAddressBook(TElWebDAVStorageObject &Parent, const std::string &Name, const std::string &DisplayName, const std::string &Description, const std::string &Lang);

		void CreateAddressBook(TElWebDAVStorageObject *Parent, const std::string &Name, const std::string &DisplayName, const std::string &Description, const std::string &Lang);
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
		void CreateAddressBook(const std::string &URL, const std::string &DisplayName, const std::string &Description, TElWebDAVLockList &Locks);

		void CreateAddressBook(const std::string &URL, const std::string &DisplayName, const std::string &Description, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
		void CreateAddressBook(TElWebDAVStorageObject &Parent, const std::string &Name, const std::string &DisplayName, const std::string &Description);

		void CreateAddressBook(TElWebDAVStorageObject *Parent, const std::string &Name, const std::string &DisplayName, const std::string &Description);
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM
		void UploadVCard(const std::string &URL, TStream &Strm, std::string &ETag, TElWebDavErrorList &Errors, TElWebDAVLockList &Locks);

		void UploadVCard(const std::string &URL, TStream *Strm, std::string &ETag, TElWebDavErrorList *Errors, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASSES_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELVCARD_AND_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST
		void UploadVCard(const std::string &URL, TElVCard &VCard, std::string &ETag, TElWebDavErrorList &Errors, TElWebDAVLockList &Locks);

		void UploadVCard(const std::string &URL, TElVCard *VCard, std::string &ETag, TElWebDavErrorList *Errors, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASSES_TELVCARD_AND_TELWEBDAVERRORLIST_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASSES_TELVCARD_AND_TELWEBDAVLOCKLIST
		void DownloadVCard(const std::string &URL, TElVCard &VCard, TElWebDAVLockList &Locks);

		void DownloadVCard(const std::string &URL, TElVCard &VCard, TElWebDAVLockList *Locks);
#endif /* SB_USE_CLASSES_TELVCARD_AND_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO
		void GetAddressBookInfo(const std::string &URL, TElCardDavAddressBookInfo &Info);

		void GetAddressBookInfo(const std::string &URL, TElCardDavAddressBookInfo *Info);
#endif /* SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
		bool AddressBookQueryFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties, TStringList &AddressDataProps, TElCardDavFilter &Filter, int32_t Limit, bool All, TSBWebDavDepth Depth);

		bool AddressBookQueryFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties, TStringList *AddressDataProps, TElCardDavFilter *Filter, int32_t Limit, bool All, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
		bool AddressBookQueryFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties, TElStringList &AddressDataProps, TElCardDavFilter &Filter, int32_t Limit, bool All, TSBWebDavDepth Depth);

		bool AddressBookQueryFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties, TElStringList *AddressDataProps, TElCardDavFilter *Filter, int32_t Limit, bool All, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASSES_TELCARDDAVFILTER_AND_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		bool AddressBookQueryNext(void * Ctx, TElWebDavPropertyInfoList &Properties);

		bool AddressBookQueryNext(void * Ctx, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

		void AddressBookQueryClose(void * Ctx);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST
		bool AddressBookMultigetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties, TStringList &AddressDataProps, TStringList &Hrefs, bool All, TSBWebDavDepth Depth);

		bool AddressBookMultigetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties, TStringList *AddressDataProps, TStringList *Hrefs, bool All, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASSES_TELWEBDAVPROPERTYINFOLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST
		bool AddressBookMultigetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList &Properties, TElStringList &AddressDataProps, TElStringList &Hrefs, bool All, TSBWebDavDepth Depth);

		bool AddressBookMultigetFirst(void * &Ctx, const std::string &URL, TElWebDavPropertyInfoList *Properties, TElStringList *AddressDataProps, TElStringList *Hrefs, bool All, TSBWebDavDepth Depth);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWEBDAVPROPERTYINFOLIST */
#endif

#ifdef SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST
		bool AddressBookMultigetNext(void * Ctx, TElWebDavPropertyInfoList &Properties);

		bool AddressBookMultigetNext(void * Ctx, TElWebDavPropertyInfoList *Properties);
#endif /* SB_USE_CLASS_TELWEBDAVPROPERTYINFOLIST */

		void AddressBookMultigetClose(void * Ctx);

#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
		virtual SBWebDAVClient_TElWebDavPrincipal* get_CurrentUserPrincipal();

		SB_DECLARE_PROPERTY_GET(SBWebDAVClient_TElWebDavPrincipal*, get_CurrentUserPrincipal, TElWebDAVClient, CurrentUserPrincipal);
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */

		virtual bool get_Authenticated();

		SB_DECLARE_PROPERTY_GET(bool, get_Authenticated, TElWebDAVClient, Authenticated);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AddressBookURLs();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AddressBookURLs, TElWebDAVClient, AddressBookURLs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AddressBookURLs();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AddressBookURLs, TElWebDAVClient, AddressBookURLs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELHTTPSWEBDAVCLIENT
		virtual TElHTTPSWebDAVClient* get_HTTPSWebDAVClient();

		virtual void set_HTTPSWebDAVClient(TElHTTPSWebDAVClient &Value);

		virtual void set_HTTPSWebDAVClient(TElHTTPSWebDAVClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSWebDAVClient*, get_HTTPSWebDAVClient, set_HTTPSWebDAVClient, TElWebDAVClient, HTTPSWebDAVClient);
#endif /* SB_USE_CLASS_TELHTTPSWEBDAVCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElWebDAVClient, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual void get_BaseURL(std::string &OutResult);

		virtual void set_BaseURL(const std::string &Value);

		virtual void get_Owner_AnsiString(std::string &OutResult);

		virtual void set_Owner_AnsiString(const std::string &Value);

		virtual void get_LastListedURL(std::string &OutResult);

		virtual bool get_IncludeBackLinks();

		virtual void set_IncludeBackLinks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeBackLinks, set_IncludeBackLinks, TElWebDAVClient, IncludeBackLinks);

		virtual bool get_EncodeURL();

		virtual void set_EncodeURL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncodeURL, set_EncodeURL, TElWebDAVClient, EncodeURL);

		virtual TSBWebDavClasses get_SupportedClasses();

		SB_DECLARE_PROPERTY_GET(TSBWebDavClasses, get_SupportedClasses, TElWebDAVClient, SupportedClasses);

		TElWebDAVClient(TElWebDAVClientHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDAVClient(TComponent &AOwner);

		explicit TElWebDAVClient(TComponent *AOwner);

		virtual ~TElWebDAVClient();

};
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
class TElWebDAVLockList: public TComponent
{
	private:
		SB_DISABLE_COPY(TElWebDAVLockList)
#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		TElWebDAVLock* _Inst_Locks;
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		void initInstances();

	public:
		void Merge(const TElWebDAVLockList &List);

		void Merge(const TElWebDAVLockList *List);

		TElWebDAVLockListHandle Clone();

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		void Add(const TElWebDAVLock &Lock);

		void Add(const TElWebDAVLock *Lock);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		void Remove(const TElWebDAVLock &Lock);

		void Remove(const TElWebDAVLock *Lock);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		virtual TElWebDAVLock* get_Locks(int32_t Idx);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDAVLockList, Count);

		virtual void get_ToIfHeader(std::string &OutResult);

		TElWebDAVLockList(TElWebDAVLockListHandle handle, TElOwnHandle ownHandle);

		explicit TElWebDAVLockList(TComponent &AOwner);

		explicit TElWebDAVLockList(TComponent *AOwner);

		virtual ~TElWebDAVLockList();

};
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

#ifdef SB_USE_CLASS_TELWEBDAVMULTISTATUSRESPONSE
class TElWebDAVMultistatusResponse: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDAVMultistatusResponse)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_Responses;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Strm);

		void LoadFromStream(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_Responses(int32_t Idx);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDAVMultistatusResponse, Count);

		TElWebDAVMultistatusResponse(TElWebDAVMultistatusResponseHandle handle, TElOwnHandle ownHandle);

		TElWebDAVMultistatusResponse();

		virtual ~TElWebDAVMultistatusResponse();

};
#endif /* SB_USE_CLASS_TELWEBDAVMULTISTATUSRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVERROR
class TElWebDavError: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavError)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual void get_NS(std::string &OutResult);

		virtual void set_NS(const std::string &Value);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		TElWebDavError(TElWebDavErrorHandle handle, TElOwnHandle ownHandle);

		TElWebDavError();

};
#endif /* SB_USE_CLASS_TELWEBDAVERROR */

#ifdef SB_USE_CLASS_TELWEBDAVPRIVILEGESET
class TElWebDavPrivilegeSet: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavPrivilegeSet)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual int32_t get_Value();

		virtual void set_Value(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Value, set_Value, TElWebDavPrivilegeSet, Value);

		TElWebDavPrivilegeSet(TElWebDavPrivilegeSetHandle handle, TElOwnHandle ownHandle);

		TElWebDavPrivilegeSet();

};
#endif /* SB_USE_CLASS_TELWEBDAVPRIVILEGESET */

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE
class TElWebDavSupportedPrivilege: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavSupportedPrivilege)
		TElWebDavSupportedPrivilege* _Inst_AggregatedPrivileges;

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual void get_NS(std::string &OutResult);

		virtual void set_NS(const std::string &Value);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Description(std::string &OutResult);

		virtual void set_Description(const std::string &Value);

		virtual void get_DescLang(std::string &OutResult);

		virtual void set_DescLang(const std::string &Value);

		virtual bool get__Abstract();

		virtual void set__Abstract(bool Value);

		SB_DECLARE_PROPERTY(bool, get__Abstract, set__Abstract, TElWebDavSupportedPrivilege, _Abstract);

		virtual int32_t get_Value();

		virtual void set_Value(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Value, set_Value, TElWebDavSupportedPrivilege, Value);

		virtual TElWebDavSupportedPrivilege* get_AggregatedPrivileges(int32_t Index);

		virtual int32_t get_AggregatedPrivilegeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AggregatedPrivilegeCount, TElWebDavSupportedPrivilege, AggregatedPrivilegeCount);

		TElWebDavSupportedPrivilege(TElWebDavSupportedPrivilegeHandle handle, TElOwnHandle ownHandle);

		TElWebDavSupportedPrivilege();

		virtual ~TElWebDavSupportedPrivilege();

};
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE */

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET
class TElWebDavSupportedPrivilegeSet: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavSupportedPrivilegeSet)
#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE
		TElWebDavSupportedPrivilege* _Inst_AggregatedPrivileges;
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Element);

		void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		bool IsAbstract(int32_t Privilege);

#ifdef SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE
		virtual TElWebDavSupportedPrivilege* get_AggregatedPrivileges(int32_t Index);
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGE */

		virtual int32_t get_AggregatedPrivilegeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AggregatedPrivilegeCount, TElWebDavSupportedPrivilegeSet, AggregatedPrivilegeCount);

		TElWebDavSupportedPrivilegeSet(TElWebDavSupportedPrivilegeSetHandle handle, TElOwnHandle ownHandle);

		TElWebDavSupportedPrivilegeSet();

		virtual ~TElWebDavSupportedPrivilegeSet();

};
#endif /* SB_USE_CLASS_TELWEBDAVSUPPORTEDPRIVILEGESET */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALSEARCHPROPERTYSETRESPONSE
class TElWebDAVPrincipalSearchPropertySetResponse: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDAVPrincipalSearchPropertySetResponse)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_Responses;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Strm);

		void LoadFromStream(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_Responses(int32_t Idx);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDAVPrincipalSearchPropertySetResponse, Count);

		TElWebDAVPrincipalSearchPropertySetResponse(TElWebDAVPrincipalSearchPropertySetResponseHandle handle, TElOwnHandle ownHandle);

		TElWebDAVPrincipalSearchPropertySetResponse();

		virtual ~TElWebDAVPrincipalSearchPropertySetResponse();

};
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALSEARCHPROPERTYSETRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
class TElWebDAVStorageObject: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDAVStorageObject)
#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
		TElWebDAVClient* _Inst_Storage;
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */
#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
		TElWebDAVLockList* _Inst_Locks;
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

		void initInstances();

	public:
		virtual TElWebDAVStorageObjectHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual bool ReadFromXML(TElXMLDOMNode &Node);

		virtual bool ReadFromXML(TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELWEBDAVLOCK
		TElWebDAVLockHandle Lock(TSBWebDavLockScope Scope, TSBWebDavDepth Depth, int32_t Timeout);
#endif /* SB_USE_CLASS_TELWEBDAVLOCK */

		void Unlock();

		void Unlock(int32_t Idx);

		void GetIfHeader(bool WithETag, std::string &OutResult);

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
		virtual TElWebDAVClient* get_Storage();

		SB_DECLARE_PROPERTY_GET(TElWebDAVClient*, get_Storage, TElWebDAVStorageObject, Storage);
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

		virtual void get_ParentURL(std::string &OutResult);

		virtual void get_URL(std::string &OutResult);

		virtual void get_FullURL(std::string &OutResult);

		virtual int64_t get_CreationDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreationDate, TElWebDAVStorageObject, CreationDate);

		virtual void get_DisplayName(std::string &OutResult);

		virtual void get_ContentLanguage(std::string &OutResult);

		virtual int64_t get_ContentLength();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ContentLength, TElWebDAVStorageObject, ContentLength);

		virtual void get_ContentType(std::string &OutResult);

		virtual void get_ETag(std::string &OutResult);

		virtual int64_t get_LastModified();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LastModified, TElWebDAVStorageObject, LastModified);

		virtual void get_ResourceType(std::string &OutResult);

		virtual bool get_Collection();

		SB_DECLARE_PROPERTY_GET(bool, get_Collection, TElWebDAVStorageObject, Collection);

		virtual bool get_IsAddressBook();

		SB_DECLARE_PROPERTY_GET(bool, get_IsAddressBook, TElWebDAVStorageObject, IsAddressBook);

		virtual bool get_BackLink();

		SB_DECLARE_PROPERTY_GET(bool, get_BackLink, TElWebDAVStorageObject, BackLink);

		virtual bool get_SupportsExclusiveLock();

		SB_DECLARE_PROPERTY_GET(bool, get_SupportsExclusiveLock, TElWebDAVStorageObject, SupportsExclusiveLock);

		virtual bool get_SupportsSharedLock();

		SB_DECLARE_PROPERTY_GET(bool, get_SupportsSharedLock, TElWebDAVStorageObject, SupportsSharedLock);

#ifdef SB_USE_CLASS_TELWEBDAVLOCKLIST
		virtual TElWebDAVLockList* get_Locks();

		SB_DECLARE_PROPERTY_GET(TElWebDAVLockList*, get_Locks, TElWebDAVStorageObject, Locks);
#endif /* SB_USE_CLASS_TELWEBDAVLOCKLIST */

		TElWebDAVStorageObject(TElWebDAVStorageObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
		TElWebDAVStorageObject(const TElWebDAVClient &Storage, const std::string &URL);

		TElWebDAVStorageObject(const TElWebDAVClient *Storage, const std::string &URL);
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

#ifdef SB_USE_CLASS_TELWEBDAVCLIENT
		TElWebDAVStorageObject(const TElWebDAVClient &Storage, const std::string &URL, bool HrefOnly);

		TElWebDAVStorageObject(const TElWebDAVClient *Storage, const std::string &URL, bool HrefOnly);
#endif /* SB_USE_CLASS_TELWEBDAVCLIENT */

		virtual ~TElWebDAVStorageObject();

};
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWEBDAVERRORRESPONSE
class TElWebDavErrorResponse: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavErrorResponse)
	public:
		virtual void get_URL(std::string &OutResult);

		virtual void get_Status(std::string &OutResult);

		virtual void get_Error(std::string &OutResult);

		virtual void get_Description(std::string &OutResult);

		TElWebDavErrorResponse(TElWebDavErrorResponseHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		explicit TElWebDavErrorResponse(const TElXMLDOMNode &Node);

		explicit TElWebDavErrorResponse(const TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

};
#endif /* SB_USE_CLASS_TELWEBDAVERRORRESPONSE */

#ifdef SB_USE_CLASS_TELWEBDAVOBJECTLIST
class TElWebDavObjectList: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavObjectList)
#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
		TElWebDAVStorageObject* _Inst_Objects;
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT
		virtual TElWebDAVStorageObject* get_Objects(int32_t Index);
#endif /* SB_USE_CLASS_TELWEBDAVSTORAGEOBJECT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDavObjectList, Count);

		TElWebDavObjectList(TElWebDavObjectListHandle handle, TElOwnHandle ownHandle);

		TElWebDavObjectList();

		virtual ~TElWebDavObjectList();

};
#endif /* SB_USE_CLASS_TELWEBDAVOBJECTLIST */

#ifdef SB_USE_CLASS_TELWEBDAVERRORLIST
class TElWebDavErrorList: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavErrorList)
#ifdef SB_USE_CLASS_TELWEBDAVERRORRESPONSE
		TElWebDavErrorResponse* _Inst_Objects;
#endif /* SB_USE_CLASS_TELWEBDAVERRORRESPONSE */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELWEBDAVERRORRESPONSE
		virtual TElWebDavErrorResponse* get_Objects(int32_t Index);
#endif /* SB_USE_CLASS_TELWEBDAVERRORRESPONSE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDavErrorList, Count);

		TElWebDavErrorList(TElWebDavErrorListHandle handle, TElOwnHandle ownHandle);

		TElWebDavErrorList();

		virtual ~TElWebDavErrorList();

};
#endif /* SB_USE_CLASS_TELWEBDAVERRORLIST */

#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
class SBWebDAVClient_TElWebDavPrincipal: public TObject
{
	private:
		SB_DISABLE_COPY(SBWebDAVClient_TElWebDavPrincipal)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AlternateURISet;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_GroupMemberSet;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_GroupMembership;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AddressbookHomeSet;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AlternateURISet;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_GroupMemberSet;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_GroupMembership;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AddressbookHomeSet;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual bool ReadFromXML(TElXMLDOMNode &Node);

		virtual bool ReadFromXML(TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		virtual void get_DisplayName(std::string &OutResult);

		virtual void get_URL(std::string &OutResult);

		virtual void get_PrincipalURL(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AlternateURISet();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AlternateURISet, SBWebDAVClient_TElWebDavPrincipal, AlternateURISet);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AlternateURISet();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AlternateURISet, SBWebDAVClient_TElWebDavPrincipal, AlternateURISet);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_GroupMemberSet();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_GroupMemberSet, SBWebDAVClient_TElWebDavPrincipal, GroupMemberSet);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_GroupMemberSet();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_GroupMemberSet, SBWebDAVClient_TElWebDavPrincipal, GroupMemberSet);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_GroupMembership();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_GroupMembership, SBWebDAVClient_TElWebDavPrincipal, GroupMembership);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_GroupMembership();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_GroupMembership, SBWebDAVClient_TElWebDavPrincipal, GroupMembership);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AddressbookHomeSet();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AddressbookHomeSet, SBWebDAVClient_TElWebDavPrincipal, AddressbookHomeSet);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AddressbookHomeSet();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AddressbookHomeSet, SBWebDAVClient_TElWebDavPrincipal, AddressbookHomeSet);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_AddressURL(std::string &OutResult);

		virtual bool get_IsGroup();

		SB_DECLARE_PROPERTY_GET(bool, get_IsGroup, SBWebDAVClient_TElWebDavPrincipal, IsGroup);

		SBWebDAVClient_TElWebDavPrincipal(SBWebDAVClient_TElWebDavPrincipalHandle handle, TElOwnHandle ownHandle);

		SBWebDAVClient_TElWebDavPrincipal();

		virtual ~SBWebDAVClient_TElWebDavPrincipal();

};
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */

#ifdef SB_USE_CLASS_TELWEBDAVPRINCIPALLIST
class TElWebDavPrincipalList: public TObject
{
	private:
		SB_DISABLE_COPY(TElWebDavPrincipalList)
#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
		SBWebDAVClient_TElWebDavPrincipal* _Inst_Principals;
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL
		virtual SBWebDAVClient_TElWebDavPrincipal* get_Principals(int32_t Index);
#endif /* SB_USE_CLASS_SBWEBDAVCLIENT_TELWEBDAVPRINCIPAL */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWebDavPrincipalList, Count);

		TElWebDavPrincipalList(TElWebDavPrincipalListHandle handle, TElOwnHandle ownHandle);

		TElWebDavPrincipalList();

		virtual ~TElWebDavPrincipalList();

};
#endif /* SB_USE_CLASS_TELWEBDAVPRINCIPALLIST */

#ifdef SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA
class TElCardDavSupportedAddressData: public TObject
{
	private:
		SB_DISABLE_COPY(TElCardDavSupportedAddressData)
	public:
		virtual void get_ContentType(std::string &OutResult);

		virtual void get_Version(std::string &OutResult);

		TElCardDavSupportedAddressData(TElCardDavSupportedAddressDataHandle handle, TElOwnHandle ownHandle);

		TElCardDavSupportedAddressData();

};
#endif /* SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA */

#ifdef SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO
class TElCardDavAddressBookInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElCardDavAddressBookInfo)
#ifdef SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA
		TElCardDavSupportedAddressData* _Inst_SupportedAddressData;
#endif /* SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA */

		void initInstances();

	public:
		virtual void get_Description(std::string &OutResult);

		virtual int32_t get_SupportedAddressDataCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SupportedAddressDataCount, TElCardDavAddressBookInfo, SupportedAddressDataCount);

#ifdef SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA
		virtual TElCardDavSupportedAddressData* get_SupportedAddressData(int32_t Index);
#endif /* SB_USE_CLASS_TELCARDDAVSUPPORTEDADDRESSDATA */

		virtual int32_t get_MaxResourceSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MaxResourceSize, TElCardDavAddressBookInfo, MaxResourceSize);

		TElCardDavAddressBookInfo(TElCardDavAddressBookInfoHandle handle, TElOwnHandle ownHandle);

		TElCardDavAddressBookInfo();

		virtual ~TElCardDavAddressBookInfo();

};
#endif /* SB_USE_CLASS_TELCARDDAVADDRESSBOOKINFO */

#ifdef SB_USE_CLASS_TELCARDDAVREPORTCONTEXT
class TElCardDavReportContext: public TObject
{
	private:
		SB_DISABLE_COPY(TElCardDavReportContext)
	public:
		TElCardDavReportContext(TElCardDavReportContextHandle handle, TElOwnHandle ownHandle);

		TElCardDavReportContext();

};
#endif /* SB_USE_CLASS_TELCARDDAVREPORTCONTEXT */

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVCLIENT

void AddSlash(const std::string &s, std::string &OutResult);

bool HTTPSuccess(int32_t Res);

#endif /* SB_USE_GLOBAL_PROCS_WEBDAVCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_WEBDAVCLIENT
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_AddSlash(const char * pcs, int32_t szs, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBWebDAVClient_HTTPSuccess(int32_t Res, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_WEBDAVCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWEBDAVCLIENT */
