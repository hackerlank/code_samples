#ifndef __INC_SBDROPBOXDATASTORAGE
#define __INC_SBDROPBOXDATASTORAGE

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
#include "sbrandom.h"
#include "sbhashfunction.h"
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
typedef TElClassHandle TElDropboxDataStorageHandle;

typedef TElClassHandle TElDropboxDataStorageObjectHandle;

typedef TElClassHandle TElDropboxAccountInfoHandle;

typedef uint8_t TSBDropboxImageSizeRaw;

typedef enum
{
	disDefault = 0,
	disXS = 1,
	disS = 2,
	disM = 3,
	disL = 4,
	disXL = 5
} TSBDropboxImageSize;

typedef void (SB_CALLBACK *TSBDropboxBeforeRequestSigningEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPSClientHandle HttpClient);

typedef uint8_t TSBDropboxMetadataLocationRaw;

typedef enum
{
	dmlColocatedObjects = 0,
	dmlMetadataSubdir = 1,
	dmlMetadataDir = 2
} TSBDropboxMetadataLocation;

typedef uint8_t TSBDropboxSignatureMethodRaw;

typedef enum
{
	dsmHMACSHA1 = 0
} TSBDropboxSignatureMethod;

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_StartAuthorization(TElDropboxDataStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetAuthorizationURL(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetAuthorizationURL_1(TElDropboxDataStorageHandle _Handle, const char * pcCallback, int32_t szCallback, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetAuthorizationURL_2(TElDropboxDataStorageHandle _Handle, const char * pcCallback, int32_t szCallback, const char * pcLocale, int32_t szLocale, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_RequestAccessToken(TElDropboxDataStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_StartAuthorization2(TElDropboxDataStorageHandle _Handle, const char * pcRedirectURL, int32_t szRedirectURL, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CompleteAuthorization2(TElDropboxDataStorageHandle _Handle, const char * pcAuthorizationCode, int32_t szAuthorizationCode);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CancelAuthorization2(TElDropboxDataStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetAccountInfoStr(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetAccountInfoStr_1(TElDropboxDataStorageHandle _Handle, const char * pcLocale, int32_t szLocale, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetAccountInfo(TElDropboxDataStorageHandle _Handle, TElDropboxAccountInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetAccountInfo_1(TElDropboxDataStorageHandle _Handle, const char * pcLocale, int32_t szLocale, TElDropboxAccountInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_AcquireObject(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TElDropboxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_AcquireObject_1(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, const char * pcRev, int32_t szRev, TElDropboxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_List(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_List_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Dir, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CreateObject(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TElDropboxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CreateObject_1(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TElCustomDataStorageSecurityHandlerHandle Handler, TElDropboxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_DeleteObject(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_DeleteObject_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle * Obj);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ObjectExists(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ObjectExists_1(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, const char * pcRev, int32_t szRev, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ObjectExists_2(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_RefreshObject(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_WriteObject(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, int8_t Overwrite, const char * pcParentRev, int32_t szParentRev, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_WriteObject_1(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_WriteObject_2(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ReadObject(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ReadObject_1(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, const char * pcRev, int32_t szRev, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ReadObject_2(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ReadObject_3(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, const char * pcRev, int32_t szRev, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ReadBlock(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ReadBlock_1(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, const char * pcRev, int32_t szRev);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_Search(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, const char * pcQuery, int32_t szQuery, int8_t IncludeDeleted, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_Search_1(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, const char * pcQuery, int32_t szQuery, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CopyObject(TElDropboxDataStorageHandle _Handle, const char * pcSourcePath, int32_t szSourcePath, const char * pcDestPath, int32_t szDestPath, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CopyObject_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, const char * pcDestPath, int32_t szDestPath, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CopyObject_2(TElDropboxDataStorageHandle _Handle, const char * pcSourcePath, int32_t szSourcePath, const char * pcDestPath, int32_t szDestPath, TElCustomDataStorageSecurityHandlerHandle NewHandler, int8_t AcquireObject, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CopyObject_3(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, const char * pcDestPath, int32_t szDestPath, TElCustomDataStorageSecurityHandlerHandle NewHandler, int8_t AcquireObject, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CopyObjectFromRef(TElDropboxDataStorageHandle _Handle, const char * pcCopyRef, int32_t szCopyRef, const char * pcDestPath, int32_t szDestPath, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CopyObjectFromRef_1(TElDropboxDataStorageHandle _Handle, const char * pcCopyRef, int32_t szCopyRef, const char * pcDestPath, int32_t szDestPath, TElCustomDataStorageSecurityHandlerHandle NewHandler, int8_t AcquireObject, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CreateCopyReference(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CreateCopyReference_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetDirectLink(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetDirectLink_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetPreviewLink(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, int8_t Short, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetPreviewLink_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, int8_t Short, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetThumbnail(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, const char * pcImageFormat, int32_t szImageFormat, TSBDropboxImageSizeRaw Size, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_GetThumbnail_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, const char * pcFormat, int32_t szFormat, TSBDropboxImageSizeRaw Size, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_CreateFolder(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_RenameObject(TElDropboxDataStorageHandle _Handle, const char * pcSourcePath, int32_t szSourcePath, const char * pcDestPath, int32_t szDestPath);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_RenameObject_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, const char * pcDestPath, int32_t szDestPath);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_RestoreObject(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, const char * pcRev, int32_t szRev, TElDropboxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_RestoreObject_1(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, const char * pcRev, int32_t szRev, int8_t AcquireObject, TElDropboxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ListRevisions(TElDropboxDataStorageHandle _Handle, const char * pcPath, int32_t szPath, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_ListRevisions_1(TElDropboxDataStorageHandle _Handle, TElDropboxDataStorageObjectHandle Obj, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_HTTPClient(TElDropboxDataStorageHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_HTTPClient(TElDropboxDataStorageHandle _Handle, TElHTTPSClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_AccessToken(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_AccessToken(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_AppKey(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_AppKey(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_AppSecret(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_AppSecret(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_AuthToken(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_AuthToken(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_AuthTokenSecret(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_AuthTokenSecret(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_Root(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_Root(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_MetadataLocation(TElDropboxDataStorageHandle _Handle, TSBDropboxMetadataLocationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_MetadataLocation(TElDropboxDataStorageHandle _Handle, TSBDropboxMetadataLocationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_MetadataExtension(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_MetadataExtension(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_MetadataDirName(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_MetadataDirName(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_SignatureMethod(TElDropboxDataStorageHandle _Handle, TSBDropboxSignatureMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_SignatureMethod(TElDropboxDataStorageHandle _Handle, TSBDropboxSignatureMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_ChunkedUploadThreshold(TElDropboxDataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_ChunkedUploadThreshold(TElDropboxDataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_ChunkedUploadChunkSize(TElDropboxDataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_ChunkedUploadChunkSize(TElDropboxDataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_DefaultLocale(TElDropboxDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_DefaultLocale(TElDropboxDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_HideMetadataObjects(TElDropboxDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_HideMetadataObjects(TElDropboxDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_PickMetadataOnList(TElDropboxDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_PickMetadataOnList(TElDropboxDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_Overwrite(TElDropboxDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_Overwrite(TElDropboxDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_PassthroughMode(TElDropboxDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_PassthroughMode(TElDropboxDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_EmbeddedMetadataMode(TElDropboxDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_EmbeddedMetadataMode(TElDropboxDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_get_OnBeforeRequestSigning(TElDropboxDataStorageHandle _Handle, TSBDropboxBeforeRequestSigningEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_set_OnBeforeRequestSigning(TElDropboxDataStorageHandle _Handle, TSBDropboxBeforeRequestSigningEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorage_Create(TComponentHandle AOwner, TElDropboxDataStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGE */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Assign(TElDropboxDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Clone(TElDropboxDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Clear(TElDropboxDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_IsMetadataObject(TElDropboxDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_IsMetadataDirectory(TElDropboxDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Delete(TElDropboxDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Exists(TElDropboxDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Refresh(TElDropboxDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Write(TElDropboxDataStorageObjectHandle _Handle, int8_t Overwrite, const char * pcParentRev, int32_t szParentRev, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Write_1(TElDropboxDataStorageObjectHandle _Handle, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Read(TElDropboxDataStorageObjectHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Read_1(TElDropboxDataStorageObjectHandle _Handle, const char * pcRev, int32_t szRev, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_ReadBlock(TElDropboxDataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Copy(TElDropboxDataStorageObjectHandle _Handle, const char * pcDestPath, int32_t szDestPath, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_CreateCopyReference(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_GetDirectLink(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_GetPreviewLink(TElDropboxDataStorageObjectHandle _Handle, int8_t Short, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_GetThumbnail(TElDropboxDataStorageObjectHandle _Handle, const char * pcFormat, int32_t szFormat, TSBDropboxImageSizeRaw Size, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Rename(TElDropboxDataStorageObjectHandle _Handle, const char * pcDestPath, int32_t szDestPath);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Restore(TElDropboxDataStorageObjectHandle _Handle, const char * pcRev, int32_t szRev);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_ListRevisions(TElDropboxDataStorageObjectHandle _Handle, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Path(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Locale(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Rev(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_SizeStr(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_ThumbExists(TElDropboxDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Size(TElDropboxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Modified(TElDropboxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_ClientModified(TElDropboxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Directory(TElDropboxDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Icon(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Root(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_MimeType(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Revision(TElDropboxDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_IsDeleted(TElDropboxDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Hash(TElDropboxDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Listed(TElDropboxDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Objects(TElDropboxDataStorageObjectHandle _Handle, int32_t Index, TElDropboxDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_get_Count(TElDropboxDataStorageObjectHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxDataStorageObject_Create(TElDropboxDataStorageHandle Owner, TElDropboxDataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXACCOUNTINFO
SB_IMPORT uint32_t SB_APIENTRY TElDropboxAccountInfo_get_DisplayName(TElDropboxAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxAccountInfo_get_UID(TElDropboxAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxAccountInfo_get_Country(TElDropboxAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxAccountInfo_get_ReferralLink(TElDropboxAccountInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxAccountInfo_get_QuotaAvailable(TElDropboxAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxAccountInfo_get_RegularFiles(TElDropboxAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxAccountInfo_get_SharedFiles(TElDropboxAccountInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDropboxAccountInfo_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELDROPBOXACCOUNTINFO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDropboxDataStorage;
class TElDropboxDataStorageObject;
class TElDropboxAccountInfo;

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGE
class TElDropboxDataStorage: public TElCustomDataStorage
{
	private:
		SB_DISABLE_COPY(TElDropboxDataStorage)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		void initInstances();

	public:
		void StartAuthorization();

		void GetAuthorizationURL(std::string &OutResult);

		void GetAuthorizationURL(const std::string &Callback, std::string &OutResult);

		void GetAuthorizationURL(const std::string &Callback, const std::string &Locale, std::string &OutResult);

		void RequestAccessToken();

		void StartAuthorization2(const std::string &RedirectURL, std::string &OutResult);

		void CompleteAuthorization2(const std::string &AuthorizationCode);

		void CancelAuthorization2();

		void GetAccountInfoStr(std::string &OutResult);

		void GetAccountInfoStr(const std::string &Locale, std::string &OutResult);

#ifdef SB_USE_CLASS_TELDROPBOXACCOUNTINFO
		TElDropboxAccountInfoHandle GetAccountInfo();
#endif /* SB_USE_CLASS_TELDROPBOXACCOUNTINFO */

#ifdef SB_USE_CLASS_TELDROPBOXACCOUNTINFO
		TElDropboxAccountInfoHandle GetAccountInfo(const std::string &Locale);
#endif /* SB_USE_CLASS_TELDROPBOXACCOUNTINFO */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		TElDropboxDataStorageObjectHandle AcquireObject(const std::string &Path);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		TElDropboxDataStorageObjectHandle AcquireObject(const std::string &Path, const std::string &Rev);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(const std::string &Path, TElDataStorageObjectList &Objects);

		void List(const std::string &Path, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELDROPBOXDATASTORAGEOBJECT
		void List(TElDropboxDataStorageObject &Dir, TElDataStorageObjectList &Objects);

		void List(TElDropboxDataStorageObject *Dir, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		TElDropboxDataStorageObjectHandle CreateObject(const std::string &Path);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT
		TElDropboxDataStorageObjectHandle CreateObject(const std::string &Path, TElCustomDataStorageSecurityHandler &Handler);

		TElDropboxDataStorageObjectHandle CreateObject(const std::string &Path, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT */

		void DeleteObject(const std::string &Path);

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		void DeleteObject(TElDropboxDataStorageObject &Obj);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

		bool ObjectExists(const std::string &Path);

		bool ObjectExists(const std::string &Path, const std::string &Rev);

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		bool ObjectExists(TElDropboxDataStorageObject &Obj);

		bool ObjectExists(TElDropboxDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		void RefreshObject(TElDropboxDataStorageObject &Obj);

		void RefreshObject(TElDropboxDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &Path, bool Overwrite, const std::string &ParentRev, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Path, bool Overwrite, const std::string &ParentRev, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &Path, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Path, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElDropboxDataStorageObject &Obj, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElDropboxDataStorageObject *Obj, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Path, TStream &Strm);

		void ReadObject(const std::string &Path, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Path, const std::string &Rev, TStream &Strm);

		void ReadObject(const std::string &Path, const std::string &Rev, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElDropboxDataStorageObject &Obj, TStream &Strm);

		void ReadObject(TElDropboxDataStorageObject *Obj, TStream *Strm);
#endif /* SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElDropboxDataStorageObject &Obj, const std::string &Rev, TStream &Strm);

		void ReadObject(TElDropboxDataStorageObject *Obj, const std::string &Rev, TStream *Strm);
#endif /* SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &Path, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(const std::string &Path, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &Path, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, const std::string &Rev);

		void ReadBlock(const std::string &Path, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, const std::string &Rev);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void Search(const std::string &Path, const std::string &Query, bool IncludeDeleted, TElDataStorageObjectList &Objects);

		void Search(const std::string &Path, const std::string &Query, bool IncludeDeleted, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void Search(const std::string &Path, const std::string &Query, TElDataStorageObjectList &Objects);

		void Search(const std::string &Path, const std::string &Query, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourcePath, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourcePath, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT
		TElCustomDataStorageObjectHandle CopyObject(TElDropboxDataStorageObject &Obj, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(TElDropboxDataStorageObject *Obj, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourcePath, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler, bool AcquireObject);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourcePath, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler, bool AcquireObject);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT
		TElCustomDataStorageObjectHandle CopyObject(TElDropboxDataStorageObject &Obj, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler, bool AcquireObject);

		TElCustomDataStorageObjectHandle CopyObject(TElDropboxDataStorageObject *Obj, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler, bool AcquireObject);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObjectFromRef(const std::string &CopyRef, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObjectFromRef(const std::string &CopyRef, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObjectFromRef(const std::string &CopyRef, const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler, bool AcquireObject);

		TElCustomDataStorageObjectHandle CopyObjectFromRef(const std::string &CopyRef, const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler, bool AcquireObject);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

		void CreateCopyReference(const std::string &Path, std::string &OutResult);

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		void CreateCopyReference(TElDropboxDataStorageObject &Obj, std::string &OutResult);

		void CreateCopyReference(TElDropboxDataStorageObject *Obj, std::string &OutResult);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

		void GetDirectLink(const std::string &Path, std::string &OutResult);

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		void GetDirectLink(TElDropboxDataStorageObject &Obj, std::string &OutResult);

		void GetDirectLink(TElDropboxDataStorageObject *Obj, std::string &OutResult);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

		void GetPreviewLink(const std::string &Path, bool Short, std::string &OutResult);

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		void GetPreviewLink(TElDropboxDataStorageObject &Obj, bool Short, std::string &OutResult);

		void GetPreviewLink(TElDropboxDataStorageObject *Obj, bool Short, std::string &OutResult);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TSTREAM
		void GetThumbnail(const std::string &Path, const std::string &ImageFormat, TSBDropboxImageSize Size, TStream &Stream);

		void GetThumbnail(const std::string &Path, const std::string &ImageFormat, TSBDropboxImageSize Size, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM
		void GetThumbnail(TElDropboxDataStorageObject &Obj, const std::string &Format, TSBDropboxImageSize Size, TStream &Stream);

		void GetThumbnail(TElDropboxDataStorageObject *Obj, const std::string &Format, TSBDropboxImageSize Size, TStream *Stream);
#endif /* SB_USE_CLASSES_TELDROPBOXDATASTORAGEOBJECT_AND_TSTREAM */

		void CreateFolder(const std::string &Path);

		void RenameObject(const std::string &SourcePath, const std::string &DestPath);

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		void RenameObject(TElDropboxDataStorageObject &Obj, const std::string &DestPath);

		void RenameObject(TElDropboxDataStorageObject *Obj, const std::string &DestPath);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		TElDropboxDataStorageObjectHandle RestoreObject(const std::string &Path, const std::string &Rev);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
		TElDropboxDataStorageObjectHandle RestoreObject(const std::string &Path, const std::string &Rev, bool AcquireObject);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void ListRevisions(const std::string &Path, TElDataStorageObjectList &Objects);

		void ListRevisions(const std::string &Path, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELDROPBOXDATASTORAGEOBJECT
		void ListRevisions(TElDropboxDataStorageObject &Obj, TElDataStorageObjectList &Objects);

		void ListRevisions(TElDropboxDataStorageObject *Obj, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElDropboxDataStorage, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

		virtual void get_AccessToken(std::string &OutResult);

		virtual void set_AccessToken(const std::string &Value);

		virtual void get_AppKey(std::string &OutResult);

		virtual void set_AppKey(const std::string &Value);

		virtual void get_AppSecret(std::string &OutResult);

		virtual void set_AppSecret(const std::string &Value);

		virtual void get_AuthToken(std::string &OutResult);

		virtual void set_AuthToken(const std::string &Value);

		virtual void get_AuthTokenSecret(std::string &OutResult);

		virtual void set_AuthTokenSecret(const std::string &Value);

		virtual void get_Root(std::string &OutResult);

		virtual void set_Root(const std::string &Value);

		virtual TSBDropboxMetadataLocation get_MetadataLocation();

		virtual void set_MetadataLocation(TSBDropboxMetadataLocation Value);

		SB_DECLARE_PROPERTY(TSBDropboxMetadataLocation, get_MetadataLocation, set_MetadataLocation, TElDropboxDataStorage, MetadataLocation);

		virtual void get_MetadataExtension(std::string &OutResult);

		virtual void set_MetadataExtension(const std::string &Value);

		virtual void get_MetadataDirName(std::string &OutResult);

		virtual void set_MetadataDirName(const std::string &Value);

		virtual TSBDropboxSignatureMethod get_SignatureMethod();

		virtual void set_SignatureMethod(TSBDropboxSignatureMethod Value);

		SB_DECLARE_PROPERTY(TSBDropboxSignatureMethod, get_SignatureMethod, set_SignatureMethod, TElDropboxDataStorage, SignatureMethod);

		virtual int64_t get_ChunkedUploadThreshold();

		virtual void set_ChunkedUploadThreshold(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ChunkedUploadThreshold, set_ChunkedUploadThreshold, TElDropboxDataStorage, ChunkedUploadThreshold);

		virtual int64_t get_ChunkedUploadChunkSize();

		virtual void set_ChunkedUploadChunkSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ChunkedUploadChunkSize, set_ChunkedUploadChunkSize, TElDropboxDataStorage, ChunkedUploadChunkSize);

		virtual void get_DefaultLocale(std::string &OutResult);

		virtual void set_DefaultLocale(const std::string &Value);

		virtual bool get_HideMetadataObjects();

		virtual void set_HideMetadataObjects(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HideMetadataObjects, set_HideMetadataObjects, TElDropboxDataStorage, HideMetadataObjects);

		virtual bool get_PickMetadataOnList();

		virtual void set_PickMetadataOnList(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PickMetadataOnList, set_PickMetadataOnList, TElDropboxDataStorage, PickMetadataOnList);

		virtual bool get_Overwrite();

		virtual void set_Overwrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Overwrite, set_Overwrite, TElDropboxDataStorage, Overwrite);

		virtual bool get_PassthroughMode();

		virtual void set_PassthroughMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassthroughMode, set_PassthroughMode, TElDropboxDataStorage, PassthroughMode);

		virtual bool get_EmbeddedMetadataMode();

		virtual void set_EmbeddedMetadataMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EmbeddedMetadataMode, set_EmbeddedMetadataMode, TElDropboxDataStorage, EmbeddedMetadataMode);

		virtual void get_OnBeforeRequestSigning(TSBDropboxBeforeRequestSigningEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeRequestSigning(TSBDropboxBeforeRequestSigningEvent pMethodValue, void * pDataValue);

		TElDropboxDataStorage(TElDropboxDataStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElDropboxDataStorage(TComponent &AOwner);

		explicit TElDropboxDataStorage(TComponent *AOwner);

		virtual ~TElDropboxDataStorage();

};
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGE */

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT
class TElDropboxDataStorageObject: public TElCustomDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElDropboxDataStorageObject)
		TElDropboxDataStorageObject* _Inst_Objects;

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual TElCustomDataStorageObjectHandle Clone();

		void Clear();

		bool IsMetadataObject();

		bool IsMetadataDirectory();

		void Delete();

		bool Exists();

		void Refresh();

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(bool Overwrite, const std::string &ParentRev, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void Write(bool Overwrite, const std::string &ParentRev, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Strm);

		void Read(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Read(const std::string &Rev, TStream &Strm);

		void Read(const std::string &Rev, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle Copy(const std::string &DestPath, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestPath, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

		void CreateCopyReference(std::string &OutResult);

		void GetDirectLink(std::string &OutResult);

		void GetPreviewLink(bool Short, std::string &OutResult);

#ifdef SB_USE_CLASS_TSTREAM
		void GetThumbnail(const std::string &Format, TSBDropboxImageSize Size, TStream &Stream);

		void GetThumbnail(const std::string &Format, TSBDropboxImageSize Size, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Rename(const std::string &DestPath);

		void Restore(const std::string &Rev);

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void ListRevisions(TElDataStorageObjectList &Objects);

		void ListRevisions(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

		virtual void get_Path(std::string &OutResult);

		virtual void get_Locale(std::string &OutResult);

		virtual void get_Rev(std::string &OutResult);

		virtual void get_SizeStr(std::string &OutResult);

		virtual bool get_ThumbExists();

		SB_DECLARE_PROPERTY_GET(bool, get_ThumbExists, TElDropboxDataStorageObject, ThumbExists);

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElDropboxDataStorageObject, Size);

		virtual int64_t get_Modified();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Modified, TElDropboxDataStorageObject, Modified);

		virtual int64_t get_ClientModified();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ClientModified, TElDropboxDataStorageObject, ClientModified);

		virtual bool get_Directory();

		SB_DECLARE_PROPERTY_GET(bool, get_Directory, TElDropboxDataStorageObject, Directory);

		virtual void get_Icon(std::string &OutResult);

		virtual void get_Root(std::string &OutResult);

		virtual void get_MimeType(std::string &OutResult);

		virtual int64_t get_Revision();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Revision, TElDropboxDataStorageObject, Revision);

		virtual bool get_IsDeleted();

		SB_DECLARE_PROPERTY_GET(bool, get_IsDeleted, TElDropboxDataStorageObject, IsDeleted);

		virtual void get_Hash(std::string &OutResult);

		virtual bool get_Listed();

		SB_DECLARE_PROPERTY_GET(bool, get_Listed, TElDropboxDataStorageObject, Listed);

		virtual TElDropboxDataStorageObject* get_Objects(int32_t Index);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElDropboxDataStorageObject, Count);

		TElDropboxDataStorageObject(TElDropboxDataStorageObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELDROPBOXDATASTORAGE
		explicit TElDropboxDataStorageObject(TElDropboxDataStorage &Owner);

		explicit TElDropboxDataStorageObject(TElDropboxDataStorage *Owner);
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGE */

		virtual ~TElDropboxDataStorageObject();

};
#endif /* SB_USE_CLASS_TELDROPBOXDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDROPBOXACCOUNTINFO
class TElDropboxAccountInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElDropboxAccountInfo)
	public:
		virtual void get_DisplayName(std::string &OutResult);

		virtual int64_t get_UID();

		SB_DECLARE_PROPERTY_GET(int64_t, get_UID, TElDropboxAccountInfo, UID);

		virtual void get_Country(std::string &OutResult);

		virtual void get_ReferralLink(std::string &OutResult);

		virtual int64_t get_QuotaAvailable();

		SB_DECLARE_PROPERTY_GET(int64_t, get_QuotaAvailable, TElDropboxAccountInfo, QuotaAvailable);

		virtual int64_t get_RegularFiles();

		SB_DECLARE_PROPERTY_GET(int64_t, get_RegularFiles, TElDropboxAccountInfo, RegularFiles);

		virtual int64_t get_SharedFiles();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SharedFiles, TElDropboxAccountInfo, SharedFiles);

		TElDropboxAccountInfo(TElDropboxAccountInfoHandle handle, TElOwnHandle ownHandle);

		TElDropboxAccountInfo();

};
#endif /* SB_USE_CLASS_TELDROPBOXACCOUNTINFO */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDROPBOXDATASTORAGE */

