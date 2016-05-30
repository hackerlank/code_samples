#ifndef __INC_SBWINAZUREDATASTORAGE
#define __INC_SBWINAZUREDATASTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbdatastorage.h"
#include "sbdatastorageutils.h"
#include "sbstreams.h"
#include "sbencoding.h"
#include "sbhashfunction.h"
#include "sbxmlcore.h"
#include "sbxmlutils.h"
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
typedef TElClassHandle TElWinAzureDataStorageHandle;

typedef TElClassHandle TElWinAzureDataStorageListStateHandle;

typedef TElClassHandle TElWinAzureSingleAccessPolicyHandle;

typedef TElClassHandle TElWinAzureAccessPolicyHandle;

typedef TElClassHandle TElWinAzureDataStorageObjectHandle;

typedef TElClassHandle TElWinAzureDataStorageContainerHandle;

typedef TElClassHandle TElWinAzureDataStorageContainerListHandle;

typedef uint8_t TSBWinAzureObjectAccessConditionRaw;

typedef enum
{
	msoaNone = 0,
	msoaIfModifiedSince = 1,
	msoaIfUnmodifiedSince = 2,
	msoaIfMatch = 3,
	msoaIfNoneMatch = 4,
	msoaIfSequenceNumberIsLessThanOrEqual = 5,
	msoaIfSequenceNumberIsLess = 6,
	msoaIfSequenceNumberIsEqual = 7
} TSBWinAzureObjectAccessCondition;

typedef uint8_t TSBWinAzureContainerAccessLevelRaw;

typedef enum
{
	calUnknown = 0,
	calPrivate = 1,
	calContainer = 2,
	calBlob = 3,
	calTrue = 4
} TSBWinAzureContainerAccessLevel;

typedef void (SB_CALLBACK *TSBWinAzureBeforeRequestSigningEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPSClientHandle HttpClient);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireObject(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, TElWinAzureDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireObject_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, TStringListHandle Headers, TElWinAzureDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireObject_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, TElStringListHandle Headers, TElWinAzureDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireObject_2(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, const char * pcObjName, int32_t szObjName, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireObject_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireObject_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, const char * pcObjName, int32_t szObjName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireObject_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Headers, TElWinAzureDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireObject_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Headers, TElWinAzureDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElDataStorageObjectListHandle Objects);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElDataStorageObjectListHandle Objects, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElDataStorageObjectListHandle Objects, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, TElDataStorageObjectListHandle Objects);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_6(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_7(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_6(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_List_7(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListInit(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElWinAzureDataStorageListStateHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListInit_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TStringListHandle Prefixes, TStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListInit_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListInit_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TElStringListHandle Prefixes, TElStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListInit_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TElStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TElStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListNext(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageListStateHandle State, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListNext_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageListStateHandle State, TElDataStorageObjectListHandle Objects, int32_t MaxCount);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListFinal(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageListStateHandle * State);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, const char * pcObjName, int32_t szObjName, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_3(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, const char * pcObjName, int32_t szObjName, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_4(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_5(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, const char * pcObjName, int32_t szObjName, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_6(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_7(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, const char * pcObjName, int32_t szObjName, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_8(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_9(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_8(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_9(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_10(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_11(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_12(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, int64_t InitialSize, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_13(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_14(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_13(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateObject_14(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteObject(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteObject_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle * Obj);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteObject_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteObject_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteObject_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteObject_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle * Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteObject_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteObject_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ObjectExists(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ObjectExists_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ObjectExists_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStringListHandle Headers, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ObjectExists_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TElStringListHandle Headers, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ObjectExists_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ObjectExists_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ObjectExists_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Headers, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ObjectExists_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Headers, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_RefreshObject(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_RefreshObject_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_RefreshObject_2(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_RefreshObject_3(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_RefreshObject_2(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_RefreshObject_3(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, const char * pcLeaseID, int32_t szLeaseID);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_5(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, const char * pcLeaseID, int32_t szLeaseID);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_5(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_6(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_7(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_8(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_9(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_10(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers, int64_t InitialSize);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_7(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_8(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_9(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_10(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers, int64_t InitialSize);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_11(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_12(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_13(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_14(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_15(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_12(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_13(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_14(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_15(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_16(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_17(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_18(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_19(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_20(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TStringListHandle Headers, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_21(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, const char * pcLeaseID, int32_t szLeaseID);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_17(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_18(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_19(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_20(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElStringListHandle Headers, int64_t InitialSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_WriteObject_21(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, const char * pcLeaseID, int32_t szLeaseID);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_2(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_4(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_5(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_6(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_4(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_5(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_6(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_7(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_8(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_9(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_10(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_11(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_12(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_13(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_10(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_11(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_12(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadObject_13(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_2(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_4(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_5(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_6(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_4(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_5(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_6(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_7(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_8(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_9(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_10(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_11(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_12(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_13(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_10(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_11(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_12(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReadBlock_13(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_2(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_3(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_4(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TStringListHandle Metadata, TStringListHandle Headers, const char * pcLeaseID, int32_t szLeaseID, int8_t Wait, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_2(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_3(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_4(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElStringListHandle Headers, const char * pcLeaseID, int32_t szLeaseID, int8_t Wait, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_5(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_6(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_7(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_8(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_9(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TStringListHandle Metadata, TStringListHandle Headers, const char * pcLeaseID, int32_t szLeaseID, int8_t Wait, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_7(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_8(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CopyObject_9(TElWinAzureDataStorageHandle _Handle, const char * pcSourceContainerName, int32_t szSourceContainerName, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElStringListHandle Headers, const char * pcLeaseID, int32_t szLeaseID, int8_t Wait, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetObjectACL(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetObjectACL_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetObjectACL_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetObjectACL_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetObjectACL(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcACL, int32_t szACL);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetObjectACL_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, const char * pcACL, int32_t szACL);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetObjectACL_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcACL, int32_t szACL, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetObjectACL_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcACL, int32_t szACL, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetLocalETag(TElWinAzureDataStorageHandle _Handle, TStreamHandle Stream, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetLocalETag_1(TElWinAzureDataStorageHandle _Handle, const char * pcFilename, int32_t szFilename, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetRemoteETag(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetRemoteETag_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetRemoteETag_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetRemoteETag_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetObjectAllocatedSize(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetObjectAllocatedSize(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_LockObject(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, int32_t Seconds, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_RenewObjectLock(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, int32_t Seconds, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcLeaseID, int32_t szLeaseID);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_UnlockObject(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcLeaseID, int32_t szLeaseID);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireContainer(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElWinAzureDataStorageContainerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_AcquireContainer_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageContainerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ReleaseContainer(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle * Container);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateContainer(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElWinAzureDataStorageContainerHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateContainer_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TStringListHandle Headers, TElWinAzureDataStorageContainerHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateContainer_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElStringListHandle Headers, TElWinAzureDataStorageContainerHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateContainer_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageContainerHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateContainer_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Headers, TElWinAzureDataStorageContainerHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateContainer_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Headers, TElWinAzureDataStorageContainerHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteContainer(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteContainer_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle * Container);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteContainer_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteContainer_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteContainer_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteContainer_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle * Container, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteContainer_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_DeleteContainer_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ContainerExists(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ContainerExists_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Obj, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ContainerExists_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TStringListHandle Headers, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ContainerExists_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElStringListHandle Headers, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ContainerExists_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ContainerExists_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Obj, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ContainerExists_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Headers, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ContainerExists_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Headers, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetContainerACL(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElWinAzureAccessPolicyHandle Policy, TSBWinAzureContainerAccessLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetContainerACL_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, TElWinAzureAccessPolicyHandle Policy, TSBWinAzureContainerAccessLevelRaw * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetContainerACL_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElWinAzureAccessPolicyHandle Policy, TStringListHandle Headers, TSBWinAzureContainerAccessLevelRaw * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetContainerACL_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElWinAzureAccessPolicyHandle Policy, TElStringListHandle Headers, TSBWinAzureContainerAccessLevelRaw * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetContainerACL_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureAccessPolicyHandle Policy, TSBWinAzureContainerAccessLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetContainerACL_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureAccessPolicyHandle Policy, TSBWinAzureContainerAccessLevelRaw * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetContainerACL_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureAccessPolicyHandle Policy, TStringListHandle Headers, TSBWinAzureContainerAccessLevelRaw * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_GetContainerACL_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureAccessPolicyHandle Policy, TElStringListHandle Headers, TSBWinAzureContainerAccessLevelRaw * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetContainerACL(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TSBWinAzureContainerAccessLevelRaw AccessLevel, TElWinAzureAccessPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetContainerACL_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, TSBWinAzureContainerAccessLevelRaw AccessLevel, TElWinAzureAccessPolicyHandle Policy);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetContainerACL_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TSBWinAzureContainerAccessLevelRaw AccessLevel, TElWinAzureAccessPolicyHandle Policy, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetContainerACL_2(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TSBWinAzureContainerAccessLevelRaw AccessLevel, TElWinAzureAccessPolicyHandle Policy, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetContainerACL_3(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TSBWinAzureContainerAccessLevelRaw AccessLevel, TElWinAzureAccessPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetContainerACL_4(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TSBWinAzureContainerAccessLevelRaw AccessLevel, TElWinAzureAccessPolicyHandle Policy);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetContainerACL_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TSBWinAzureContainerAccessLevelRaw AccessLevel, TElWinAzureAccessPolicyHandle Policy, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers(TElWinAzureDataStorageHandle _Handle, TStringListHandle Containers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_1(TElWinAzureDataStorageHandle _Handle, TStringListHandle Containers, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_SetContainerACL_5(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TSBWinAzureContainerAccessLevelRaw AccessLevel, TElWinAzureAccessPolicyHandle Policy, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers(TElWinAzureDataStorageHandle _Handle, TElStringListHandle Containers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_1(TElWinAzureDataStorageHandle _Handle, TElStringListHandle Containers, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_2(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerListHandle Containers);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_3(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerListHandle Containers, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_4(TElWinAzureDataStorageHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Containers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_5(TElWinAzureDataStorageHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Containers, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_3(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerListHandle Containers, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_4(TElWinAzureDataStorageHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Containers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_5(TElWinAzureDataStorageHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Containers, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_6(TElWinAzureDataStorageHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageContainerListHandle Containers);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_7(TElWinAzureDataStorageHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageContainerListHandle Containers, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_8(TElWinAzureDataStorageHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageContainerListHandle Containers, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_7(TElWinAzureDataStorageHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageContainerListHandle Containers, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainers_8(TElWinAzureDataStorageHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageContainerListHandle Containers, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainersInit(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageListStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainersInit_1(TElWinAzureDataStorageHandle _Handle, const char * pcPrefix, int32_t szPrefix, TElWinAzureDataStorageListStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainersInit_2(TElWinAzureDataStorageHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageListStateHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainersInit_3(TElWinAzureDataStorageHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainersInit_3(TElWinAzureDataStorageHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainersNext(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageListStateHandle State, TElWinAzureDataStorageContainerListHandle Containers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_ListContainersNext_1(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageListStateHandle State, TElWinAzureDataStorageContainerListHandle Containers, int32_t MaxCount);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateSharedAccessSignature(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, const char * pcObjName, int32_t szObjName, TElWinAzureSingleAccessPolicyHandle Policy, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateSharedAccessSignature_1(TElWinAzureDataStorageHandle _Handle, const char * pcContainerName, int32_t szContainerName, TElWinAzureSingleAccessPolicyHandle Policy, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateSharedAccessSignature_2(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageObjectHandle Obj, TElWinAzureSingleAccessPolicyHandle Policy, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_CreateSharedAccessSignature_3(TElWinAzureDataStorageHandle _Handle, TElWinAzureDataStorageContainerHandle Container, TElWinAzureSingleAccessPolicyHandle Policy, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_AccountName(TElWinAzureDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_AccountName(TElWinAzureDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_AccountKey(TElWinAzureDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_AccountKey(TElWinAzureDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_DevMode(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_DevMode(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_UseSSL(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_UseSSL(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_UseCRCCheck(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_UseCRCCheck(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_UsePadding(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_UsePadding(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_UseURLEncoding(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_UseURLEncoding(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_HTTPClient(TElWinAzureDataStorageHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_HTTPClient(TElWinAzureDataStorageHandle _Handle, TElHTTPSClientHandle Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_AzureHeaders(TElWinAzureDataStorageHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_AzureHeaders(TElWinAzureDataStorageHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_UseDelayedPut(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_UseDelayedPut(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_SecMetadataID(TElWinAzureDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_SecMetadataID(TElWinAzureDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_ContentLengthMetadataID(TElWinAzureDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_ContentLengthMetadataID(TElWinAzureDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_DefaultMaxBlobSize(TElWinAzureDataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_DefaultMaxBlobSize(TElWinAzureDataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_CopyTimeout(TElWinAzureDataStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_CopyTimeout(TElWinAzureDataStorageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_Overwrite(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_Overwrite(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_PassthroughMode(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_PassthroughMode(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_EmbeddedMetadataMode(TElWinAzureDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_EmbeddedMetadataMode(TElWinAzureDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_get_OnBeforeRequestSigning(TElWinAzureDataStorageHandle _Handle, TSBWinAzureBeforeRequestSigningEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_set_OnBeforeRequestSigning(TElWinAzureDataStorageHandle _Handle, TSBWinAzureBeforeRequestSigningEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorage_Create(TComponentHandle AOwner, TElWinAzureDataStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageListState_Completed(TElWinAzureDataStorageListStateHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageListState_Create(const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageListState_Create(const char * pcContainerName, int32_t szContainerName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TElStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TElStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_Reset(TElWinAzureSingleAccessPolicyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_PrepareID(TElWinAzureSingleAccessPolicyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_get_ID(TElWinAzureSingleAccessPolicyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_set_ID(TElWinAzureSingleAccessPolicyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_get_StartTime(TElWinAzureSingleAccessPolicyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_set_StartTime(TElWinAzureSingleAccessPolicyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_get_ExpiryTime(TElWinAzureSingleAccessPolicyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_set_ExpiryTime(TElWinAzureSingleAccessPolicyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_get_Permissions(TElWinAzureSingleAccessPolicyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_set_Permissions(TElWinAzureSingleAccessPolicyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureSingleAccessPolicy_Create(TElWinAzureSingleAccessPolicyHandle * OutResult);
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_AddPolicy(TElWinAzureAccessPolicyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_RemovePolicy(TElWinAzureAccessPolicyHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_Clear(TElWinAzureAccessPolicyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_LoadFromXml(TElWinAzureAccessPolicyHandle _Handle, const char * pcXml, int32_t szXml);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_LoadFromXml_1(TElWinAzureAccessPolicyHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_SaveToXml(TElWinAzureAccessPolicyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_SaveToXml_1(TElWinAzureAccessPolicyHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_get_AccessPolicies(TElWinAzureAccessPolicyHandle _Handle, int32_t Index, TElWinAzureSingleAccessPolicyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_get_Count(TElWinAzureAccessPolicyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_get_UseURLEncoding(TElWinAzureAccessPolicyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_set_UseURLEncoding(TElWinAzureAccessPolicyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureAccessPolicy_Create(TElWinAzureAccessPolicyHandle * OutResult);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Assign(TElWinAzureDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Clone(TElWinAzureDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Delete(TElWinAzureDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Delete_1(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Exists(TElWinAzureDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Exists_1(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Refresh(TElWinAzureDataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Refresh_1(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Write(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Write_1(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Write_1(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Write_2(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Write_3(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Write_4(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Write_3(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Write_4(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_1(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_2(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_3(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_2(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_3(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_4(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_5(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_6(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_7(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_6(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Read_7(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_1(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_2(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_3(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_2(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_3(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_4(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_5(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_6(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_7(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_6(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_ReadBlock_7(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy(TElWinAzureDataStorageObjectHandle _Handle, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_1(TElWinAzureDataStorageObjectHandle _Handle, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_2(TElWinAzureDataStorageObjectHandle _Handle, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_1(TElWinAzureDataStorageObjectHandle _Handle, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_2(TElWinAzureDataStorageObjectHandle _Handle, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_3(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_4(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_5(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_4(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Copy_5(TElWinAzureDataStorageObjectHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_GetACL(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_SetACL(TElWinAzureDataStorageObjectHandle _Handle, const char * pcACL, int32_t szACL);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_GetLocalETag(TElWinAzureDataStorageObjectHandle _Handle, TStreamHandle Stream, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_GetLocalETag_1(TElWinAzureDataStorageObjectHandle _Handle, const char * pcFilename, int32_t szFilename, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_GetRemoteETag(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Resize(TElWinAzureDataStorageObjectHandle _Handle, int64_t NewSize);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_CreateSharedAccessSignature(TElWinAzureDataStorageObjectHandle _Handle, TElWinAzureSingleAccessPolicyHandle Policy, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_ContainerName(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_LastModified(TElWinAzureDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_ETag(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_Size(TElWinAzureDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_AllocatedSize(TElWinAzureDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_ContentType(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_ContentEncoding(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_ContentLanguage(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_ContentMD5(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_set_ContentMD5(TElWinAzureDataStorageObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_SequenceNumber(TElWinAzureDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_Locked(TElWinAzureDataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_CopyStatus(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_LeaseStatus(TElWinAzureDataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_Metadata(TElWinAzureDataStorageObjectHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_CustomHeaders(TElWinAzureDataStorageObjectHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_Metadata(TElWinAzureDataStorageObjectHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_get_CustomHeaders(TElWinAzureDataStorageObjectHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Create(TElWinAzureDataStorageHandle Storage, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageObject_Create_1(TElWinAzureDataStorageHandle Storage, const char * pcContainerName, int32_t szContainerName, const char * pcName, int32_t szName, TElWinAzureDataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_AcquireObject(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_AcquireObject_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List(TElWinAzureDataStorageContainerHandle _Handle, TElDataStorageObjectListHandle Objects);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_1(TElWinAzureDataStorageContainerHandle _Handle, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_2(TElWinAzureDataStorageContainerHandle _Handle, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_1(TElWinAzureDataStorageContainerHandle _Handle, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_2(TElWinAzureDataStorageContainerHandle _Handle, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_List_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ListInit(TElWinAzureDataStorageContainerHandle _Handle, TElWinAzureDataStorageListStateHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ListInit_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TStringListHandle Prefixes, TStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ListInit_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ListInit_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TElStringListHandle Prefixes, TElStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ListInit_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TElStringListHandle Prefixes, int8_t IncludeSnapshots, int8_t IncludeMetadata, int8_t IncludeUncommittedBlobs, TElStringListHandle Headers, TElWinAzureDataStorageListStateHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ListNext(TElWinAzureDataStorageContainerHandle _Handle, TElWinAzureDataStorageListStateHandle State, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ListNext_1(TElWinAzureDataStorageContainerHandle _Handle, TElWinAzureDataStorageListStateHandle State, TElDataStorageObjectListHandle Objects, int32_t MaxCount);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ListFinal(TElWinAzureDataStorageContainerHandle _Handle, TElWinAzureDataStorageListStateHandle * State);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, TElWinAzureDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, TElWinAzureDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_6(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_7(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_6(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_7(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_8(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_9(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_10(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_11(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_10(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_11(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_12(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_13(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_14(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_15(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_14(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateObject_15(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int64_t InitialSize, TElWinAzureDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_DeleteObject(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_DeleteObject_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ObjectExists(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ObjectExists_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TStringListHandle Metadata);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_WriteObject_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcContentLanguage, int32_t szContentLanguage, const char * pcContentMD5, int32_t szContentMD5, TElStringListHandle Metadata);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_6(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_7(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_6(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadObject_7(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_6(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_7(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_6(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_ReadBlock_7(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int64_t SeqNum, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjContentLanguage, int32_t * szObjContentLanguage, char * pcObjContentMD5, int32_t * szObjContentMD5, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_2(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_3(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_4(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CopyObject_5(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSourceName, int32_t szSourceName, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, const char * pcDestContainerName, int32_t szDestContainerName, const char * pcDestName, int32_t szDestName, const char * pcDestSharedAccessSignature, int32_t szDestSharedAccessSignature, TSBWinAzureObjectAccessConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TSBWinAzureObjectAccessConditionRaw DestCondition, int64_t DestDateTime, const char * pcDestETag, int32_t szDestETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_GetObjectACL(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_SetObjectACL(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, const char * pcACL, int32_t szACL);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_GetRemoteETag(TElWinAzureDataStorageContainerHandle _Handle, const char * pcName, int32_t szName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_Delete(TElWinAzureDataStorageContainerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_Delete_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_Exists(TElWinAzureDataStorageContainerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_Exists_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_GetACL(TElWinAzureDataStorageContainerHandle _Handle, TElWinAzureAccessPolicyHandle Policy, TSBWinAzureContainerAccessLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_GetACL_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TElWinAzureAccessPolicyHandle Policy, TSBWinAzureContainerAccessLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_SetACL(TElWinAzureDataStorageContainerHandle _Handle, TSBWinAzureContainerAccessLevelRaw Level, TElWinAzureAccessPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_SetACL_1(TElWinAzureDataStorageContainerHandle _Handle, const char * pcSharedAccessSignature, int32_t szSharedAccessSignature, TSBWinAzureContainerAccessLevelRaw Level, TElWinAzureAccessPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_CreateSharedAccessSignature(TElWinAzureDataStorageContainerHandle _Handle, TElWinAzureSingleAccessPolicyHandle Policy, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_get_Name(TElWinAzureDataStorageContainerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_get_Address(TElWinAzureDataStorageContainerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_get_LastModified(TElWinAzureDataStorageContainerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_get_ETag(TElWinAzureDataStorageContainerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_get_Metadata(TElWinAzureDataStorageContainerHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_get_CustomHeaders(TElWinAzureDataStorageContainerHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_get_Metadata(TElWinAzureDataStorageContainerHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_get_CustomHeaders(TElWinAzureDataStorageContainerHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_Create(TElWinAzureDataStorageContainerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainer_Create_1(TElWinAzureDataStorageHandle Storage, TElWinAzureDataStorageContainerHandle * OutResult);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainerList_get_Containers(TElWinAzureDataStorageContainerListHandle _Handle, int32_t Index, TElWinAzureDataStorageContainerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainerList_get_Count(TElWinAzureDataStorageContainerListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainerList_Create(TElWinAzureDataStorageContainerListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWinAzureDataStorageContainerList_Create_1(TElWinAzureDataStorageHandle Storage, TElWinAzureDataStorageContainerListHandle * OutResult);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElWinAzureDataStorage;
class TElWinAzureDataStorageListState;
class TElWinAzureSingleAccessPolicy;
class TElWinAzureAccessPolicy;
class TElWinAzureDataStorageObject;
class TElWinAzureDataStorageContainer;
class TElWinAzureDataStorageContainerList;

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
class TElWinAzureDataStorage: public TElCustomDataStorage
{
	private:
		SB_DISABLE_COPY(TElWinAzureDataStorage)
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AzureHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AzureHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, TStringList &Headers);

		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, TElStringList &Headers);

		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle AcquireObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName);

		TElWinAzureDataStorageObjectHandle AcquireObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle AcquireObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName, const std::string &SharedAccessSignature);

		TElWinAzureDataStorageObjectHandle AcquireObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TStringList &Headers);

		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TElStringList &Headers);

		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(const std::string &ContainerName, TElDataStorageObjectList &Objects);

		void List(const std::string &ContainerName, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &ContainerName, TElDataStorageObjectList &Objects, TStringList &Headers);

		void List(const std::string &ContainerName, TElDataStorageObjectList *Objects, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &ContainerName, TElDataStorageObjectList &Objects, TElStringList &Headers);

		void List(const std::string &ContainerName, TElDataStorageObjectList *Objects, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &ContainerName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers);

		void List(const std::string &ContainerName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &ContainerName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers);

		void List(const std::string &ContainerName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &ContainerName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers);

		void List(const std::string &ContainerName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &ContainerName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers);

		void List(const std::string &ContainerName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGECONTAINER
		void List(TElWinAzureDataStorageContainer &Container, TElDataStorageObjectList &Objects);

		void List(TElWinAzureDataStorageContainer *Container, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, TStringList &Headers);

		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, TElStringList &Headers);

		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers);

		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers);

		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers);

		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers);

		void List(const std::string &ContainerName, const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListInit(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		void ListNext(TElWinAzureDataStorageListState &State, TElDataStorageObjectList &Objects);

		void ListNext(TElWinAzureDataStorageListState *State, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		void ListNext(TElWinAzureDataStorageListState &State, TElDataStorageObjectList &Objects, int32_t MaxCount);

		void ListNext(TElWinAzureDataStorageListState *State, TElDataStorageObjectList *Objects, int32_t MaxCount);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
		void ListFinal(TElWinAzureDataStorageListState &State);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName);

		TElWinAzureDataStorageObjectHandle CreateObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, int64_t InitialSize);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(TElWinAzureDataStorageContainer &Container, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(TElWinAzureDataStorageContainer *Container, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, int64_t InitialSize, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, const std::string &SharedAccessSignature, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, const std::string &SharedAccessSignature, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, const std::string &SharedAccessSignature, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &ContainerName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, const std::string &SharedAccessSignature, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

		void DeleteObject(const std::string &ContainerName, const std::string &Name);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		void DeleteObject(TElWinAzureDataStorageObject &Obj);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void DeleteObject(const std::string &ContainerName, const std::string &Name, TStringList &Headers);

		void DeleteObject(const std::string &ContainerName, const std::string &Name, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void DeleteObject(const std::string &ContainerName, const std::string &Name, TElStringList &Headers);

		void DeleteObject(const std::string &ContainerName, const std::string &Name, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		void DeleteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStringList &Headers);

		void DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TElStringList &Headers);

		void DeleteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool ObjectExists(const std::string &ContainerName, const std::string &Name);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		bool ObjectExists(TElWinAzureDataStorageObject &Obj);

		bool ObjectExists(TElWinAzureDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		bool ObjectExists(const std::string &ContainerName, const std::string &Name, TStringList &Headers);

		bool ObjectExists(const std::string &ContainerName, const std::string &Name, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		bool ObjectExists(const std::string &ContainerName, const std::string &Name, TElStringList &Headers);

		bool ObjectExists(const std::string &ContainerName, const std::string &Name, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		bool ObjectExists(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature);

		bool ObjectExists(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		bool ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStringList &Headers);

		bool ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		bool ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TElStringList &Headers);

		bool ObjectExists(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		void RefreshObject(TElWinAzureDataStorageObject &Obj);

		void RefreshObject(TElWinAzureDataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		void RefreshObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature);

		void RefreshObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		void RefreshObject(TElWinAzureDataStorageObject &Obj, TStringList &Headers);

		void RefreshObject(TElWinAzureDataStorageObject *Obj, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		void RefreshObject(TElWinAzureDataStorageObject &Obj, TElStringList &Headers);

		void RefreshObject(TElWinAzureDataStorageObject *Obj, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		void RefreshObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStringList &Headers);

		void RefreshObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		void RefreshObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TElStringList &Headers);

		void RefreshObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, const std::string &LeaseID);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, const std::string &LeaseID);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, const std::string &LeaseID);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, const std::string &LeaseID);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers);

		void WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers);

		void WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize);

		void WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElWinAzureDataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize);

		void WriteObject(TElWinAzureDataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers);

		void WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers);

		void WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize);

		void WriteObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		void WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, TStringList &Headers, int64_t InitialSize);

		void WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, TStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, TElStringList &Headers, int64_t InitialSize);

		void WriteObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, TElStringList *Headers, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize, const std::string &LeaseID);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize, const std::string &LeaseID);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize, const std::string &LeaseID);

		void WriteObject(const std::string &ContainerName, const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize, const std::string &LeaseID);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm);

		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(const std::string &ContainerName, const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElWinAzureDataStorageObject &Obj, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(TElWinAzureDataStorageObject *Obj, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm);

		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadBlock(TElWinAzureDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM
		void ReadBlock(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElCustomDataStorageObjectHandle CopyObject(TElWinAzureDataStorageObject &Obj, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(TElWinAzureDataStorageObject *Obj, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers, const std::string &LeaseID, bool Wait);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers, const std::string &LeaseID, bool Wait);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers, const std::string &LeaseID, bool Wait);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers, const std::string &LeaseID, bool Wait);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElCustomDataStorageObjectHandle CopyObject(TElWinAzureDataStorageObject &Obj, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(TElWinAzureDataStorageObject *Obj, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers, const std::string &LeaseID, bool Wait);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers, const std::string &LeaseID, bool Wait);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers, const std::string &LeaseID, bool Wait);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceContainerName, const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers, const std::string &LeaseID, bool Wait);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

		void GetObjectACL(const std::string &ContainerName, const std::string &Name, std::string &OutResult);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		void GetObjectACL(TElWinAzureDataStorageObject &Obj, std::string &OutResult);

		void GetObjectACL(TElWinAzureDataStorageObject *Obj, std::string &OutResult);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetObjectACL(const std::string &ContainerName, const std::string &Name, TStringList &Headers, std::string &OutResult);

		void GetObjectACL(const std::string &ContainerName, const std::string &Name, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetObjectACL(const std::string &ContainerName, const std::string &Name, TElStringList &Headers, std::string &OutResult);

		void GetObjectACL(const std::string &ContainerName, const std::string &Name, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		void SetObjectACL(TElWinAzureDataStorageObject &Obj, const std::string &ACL);

		void SetObjectACL(TElWinAzureDataStorageObject *Obj, const std::string &ACL);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL, TStringList &Headers);

		void SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL, TElStringList &Headers);

		void SetObjectACL(const std::string &ContainerName, const std::string &Name, const std::string &ACL, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void GetLocalETag(TStream &Stream, std::string &OutResult);

		void GetLocalETag(TStream *Stream, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

		void GetLocalETag(const std::string &Filename, std::string &OutResult);

		void GetRemoteETag(const std::string &ContainerName, const std::string &Name, std::string &OutResult);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		void GetRemoteETag(TElWinAzureDataStorageObject &Obj, std::string &OutResult);

		void GetRemoteETag(TElWinAzureDataStorageObject *Obj, std::string &OutResult);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetRemoteETag(const std::string &ContainerName, const std::string &Name, TStringList &Headers, std::string &OutResult);

		void GetRemoteETag(const std::string &ContainerName, const std::string &Name, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetRemoteETag(const std::string &ContainerName, const std::string &Name, TElStringList &Headers, std::string &OutResult);

		void GetRemoteETag(const std::string &ContainerName, const std::string &Name, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		int64_t GetObjectAllocatedSize(const std::string &ContainerName, const std::string &Name);

		void SetObjectAllocatedSize(const std::string &ContainerName, const std::string &Name, int64_t Value);

		void LockObject(const std::string &ContainerName, const std::string &Name, int32_t Seconds, const std::string &SharedAccessSignature, std::string &OutResult);

		void RenewObjectLock(const std::string &ContainerName, const std::string &Name, int32_t Seconds, const std::string &SharedAccessSignature, const std::string &LeaseID);

		void UnlockObject(const std::string &ContainerName, const std::string &Name, const std::string &SharedAccessSignature, const std::string &LeaseID);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		TElWinAzureDataStorageContainerHandle AcquireContainer(const std::string &ContainerName);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		TElWinAzureDataStorageContainerHandle AcquireContainer(const std::string &ContainerName, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		void ReleaseContainer(TElWinAzureDataStorageContainer &Container);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TSTRINGLIST
		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, TStringList &Headers);

		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINER
		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, TElStringList &Headers);

		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINER */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TSTRINGLIST
		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList &Headers);

		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINER
		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList &Headers);

		TElWinAzureDataStorageContainerHandle CreateContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINER */
#endif

		void DeleteContainer(const std::string &ContainerName);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		void DeleteContainer(TElWinAzureDataStorageContainer &Container);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void DeleteContainer(const std::string &ContainerName, TStringList &Headers);

		void DeleteContainer(const std::string &ContainerName, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void DeleteContainer(const std::string &ContainerName, TElStringList &Headers);

		void DeleteContainer(const std::string &ContainerName, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		void DeleteContainer(TElWinAzureDataStorageContainer &Container, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList &Headers);

		void DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList &Headers);

		void DeleteContainer(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool ContainerExists(const std::string &ContainerName);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		bool ContainerExists(TElWinAzureDataStorageContainer &Obj);

		bool ContainerExists(TElWinAzureDataStorageContainer *Obj);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		bool ContainerExists(const std::string &ContainerName, TStringList &Headers);

		bool ContainerExists(const std::string &ContainerName, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		bool ContainerExists(const std::string &ContainerName, TElStringList &Headers);

		bool ContainerExists(const std::string &ContainerName, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		bool ContainerExists(TElWinAzureDataStorageContainer &Obj, const std::string &SharedAccessSignature);

		bool ContainerExists(TElWinAzureDataStorageContainer *Obj, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		bool ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList &Headers);

		bool ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		bool ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList &Headers);

		bool ContainerExists(const std::string &ContainerName, const std::string &SharedAccessSignature, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy &Policy);

		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER
		TSBWinAzureContainerAccessLevel GetContainerACL(TElWinAzureDataStorageContainer &Container, TElWinAzureAccessPolicy &Policy);

		TSBWinAzureContainerAccessLevel GetContainerACL(TElWinAzureDataStorageContainer *Container, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST
		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy &Policy, TStringList &Headers);

		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy *Policy, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY
		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy &Policy, TElStringList &Headers);

		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, TElWinAzureAccessPolicy *Policy, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy);

		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER
		TSBWinAzureContainerAccessLevel GetContainerACL(TElWinAzureDataStorageContainer &Container, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy);

		TSBWinAzureContainerAccessLevel GetContainerACL(TElWinAzureDataStorageContainer *Container, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST
		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy, TStringList &Headers);

		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY
		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy, TElStringList &Headers);

		TSBWinAzureContainerAccessLevel GetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
		void SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy);

		void SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER
		void SetContainerACL(TElWinAzureDataStorageContainer &Container, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy);

		void SetContainerACL(TElWinAzureDataStorageContainer *Container, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST
		void SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy, TStringList &Headers);

		void SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY
		void SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy, TElStringList &Headers);

		void SetContainerACL(const std::string &ContainerName, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
		void SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy);

		void SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER
		void SetContainerACL(TElWinAzureDataStorageContainer &Container, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy);

		void SetContainerACL(TElWinAzureDataStorageContainer *Container, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST
		void SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy, TStringList &Headers);

		void SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREACCESSPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY
		void SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy &Policy, TElStringList &Headers);

		void SetContainerACL(const std::string &ContainerName, const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel AccessLevel, TElWinAzureAccessPolicy *Policy, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREACCESSPOLICY */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void ListContainers(TStringList &Containers);

		void ListContainers(TStringList *Containers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void ListContainers(TElStringList &Containers);

		void ListContainers(TElStringList *Containers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void ListContainers(TStringList &Containers, TStringList &Headers);

		void ListContainers(TStringList *Containers, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void ListContainers(TElStringList &Containers, TElStringList &Headers);

		void ListContainers(TElStringList *Containers, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST
		void ListContainers(TElWinAzureDataStorageContainerList &Containers);

		void ListContainers(TElWinAzureDataStorageContainerList *Containers);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST
		void ListContainers(TElWinAzureDataStorageContainerList &Containers, TStringList &Headers);

		void ListContainers(TElWinAzureDataStorageContainerList *Containers, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST
		void ListContainers(TElWinAzureDataStorageContainerList &Containers, TElStringList &Headers);

		void ListContainers(TElWinAzureDataStorageContainerList *Containers, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void ListContainers(const std::string &SharedAccessSignature, TStringList &Containers);

		void ListContainers(const std::string &SharedAccessSignature, TStringList *Containers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void ListContainers(const std::string &SharedAccessSignature, TElStringList &Containers);

		void ListContainers(const std::string &SharedAccessSignature, TElStringList *Containers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void ListContainers(const std::string &SharedAccessSignature, TStringList &Containers, TStringList &Headers);

		void ListContainers(const std::string &SharedAccessSignature, TStringList *Containers, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void ListContainers(const std::string &SharedAccessSignature, TElStringList &Containers, TElStringList &Headers);

		void ListContainers(const std::string &SharedAccessSignature, TElStringList *Containers, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST
		void ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers);

		void ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST
		void ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers, TStringList &Headers);

		void ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST
		void ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers, TElStringList &Headers);

		void ListContainers(const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST
		void ListContainers(const std::string &Prefix, const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers, TStringList &Headers);

		void ListContainers(const std::string &Prefix, const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST
		void ListContainers(const std::string &Prefix, const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList &Containers, TElStringList &Headers);

		void ListContainers(const std::string &Prefix, const std::string &SharedAccessSignature, TElWinAzureDataStorageContainerList *Containers, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGECONTAINERLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListContainersInit();
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListContainersInit(const std::string &Prefix);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
		TElWinAzureDataStorageListStateHandle ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature, TStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature, TElStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListContainersInit(const std::string &Prefix, const std::string &SharedAccessSignature, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		void ListContainersNext(TElWinAzureDataStorageListState &State, TElWinAzureDataStorageContainerList &Containers);

		void ListContainersNext(TElWinAzureDataStorageListState *State, TElWinAzureDataStorageContainerList *Containers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		void ListContainersNext(TElWinAzureDataStorageListState &State, TElWinAzureDataStorageContainerList &Containers, int32_t MaxCount);

		void ListContainersNext(TElWinAzureDataStorageListState *State, TElWinAzureDataStorageContainerList *Containers, int32_t MaxCount);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINERLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
		void CreateSharedAccessSignature(const std::string &ContainerName, const std::string &ObjName, TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult);

		void CreateSharedAccessSignature(const std::string &ContainerName, const std::string &ObjName, TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult);
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
		void CreateSharedAccessSignature(const std::string &ContainerName, TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult);

		void CreateSharedAccessSignature(const std::string &ContainerName, TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult);
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TELWINAZURESINGLEACCESSPOLICY
		void CreateSharedAccessSignature(TElWinAzureDataStorageObject &Obj, TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult);

		void CreateSharedAccessSignature(TElWinAzureDataStorageObject *Obj, TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZURESINGLEACCESSPOLICY
		void CreateSharedAccessSignature(TElWinAzureDataStorageContainer &Container, TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult);

		void CreateSharedAccessSignature(TElWinAzureDataStorageContainer *Container, TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGECONTAINER_AND_TELWINAZURESINGLEACCESSPOLICY */

		virtual void get_AccountName(std::string &OutResult);

		virtual void set_AccountName(const std::string &Value);

		virtual void get_AccountKey(std::string &OutResult);

		virtual void set_AccountKey(const std::string &Value);

		virtual bool get_DevMode();

		virtual void set_DevMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DevMode, set_DevMode, TElWinAzureDataStorage, DevMode);

		virtual bool get_UseSSL();

		virtual void set_UseSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSL, set_UseSSL, TElWinAzureDataStorage, UseSSL);

		virtual bool get_UseCRCCheck();

		virtual void set_UseCRCCheck(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCRCCheck, set_UseCRCCheck, TElWinAzureDataStorage, UseCRCCheck);

		virtual bool get_UsePadding();

		virtual void set_UsePadding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UsePadding, set_UsePadding, TElWinAzureDataStorage, UsePadding);

		virtual bool get_UseURLEncoding();

		virtual void set_UseURLEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseURLEncoding, set_UseURLEncoding, TElWinAzureDataStorage, UseURLEncoding);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElWinAzureDataStorage, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AzureHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AzureHeaders, TElWinAzureDataStorage, AzureHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AzureHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AzureHeaders, TElWinAzureDataStorage, AzureHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_UseDelayedPut();

		virtual void set_UseDelayedPut(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDelayedPut, set_UseDelayedPut, TElWinAzureDataStorage, UseDelayedPut);

		virtual void get_SecMetadataID(std::string &OutResult);

		virtual void set_SecMetadataID(const std::string &Value);

		virtual void get_ContentLengthMetadataID(std::string &OutResult);

		virtual void set_ContentLengthMetadataID(const std::string &Value);

		virtual int64_t get_DefaultMaxBlobSize();

		virtual void set_DefaultMaxBlobSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_DefaultMaxBlobSize, set_DefaultMaxBlobSize, TElWinAzureDataStorage, DefaultMaxBlobSize);

		virtual int32_t get_CopyTimeout();

		virtual void set_CopyTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CopyTimeout, set_CopyTimeout, TElWinAzureDataStorage, CopyTimeout);

		virtual bool get_Overwrite();

		virtual void set_Overwrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Overwrite, set_Overwrite, TElWinAzureDataStorage, Overwrite);

		virtual bool get_PassthroughMode();

		virtual void set_PassthroughMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassthroughMode, set_PassthroughMode, TElWinAzureDataStorage, PassthroughMode);

		virtual bool get_EmbeddedMetadataMode();

		virtual void set_EmbeddedMetadataMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EmbeddedMetadataMode, set_EmbeddedMetadataMode, TElWinAzureDataStorage, EmbeddedMetadataMode);

		virtual void get_OnBeforeRequestSigning(TSBWinAzureBeforeRequestSigningEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeRequestSigning(TSBWinAzureBeforeRequestSigningEvent pMethodValue, void * pDataValue);

		TElWinAzureDataStorage(TElWinAzureDataStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElWinAzureDataStorage(TComponent &AOwner);

		explicit TElWinAzureDataStorage(TComponent *AOwner);

		virtual ~TElWinAzureDataStorage();

};
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
class TElWinAzureDataStorageListState: public TObject
{
	private:
		SB_DISABLE_COPY(TElWinAzureDataStorageListState)
	public:
		bool Completed();

		TElWinAzureDataStorageListState(TElWinAzureDataStorageListStateHandle handle, TElOwnHandle ownHandle);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElWinAzureDataStorageListState(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers);

		TElWinAzureDataStorageListState(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElWinAzureDataStorageListState(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers);

		TElWinAzureDataStorageListState(const std::string &ContainerName, const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

};
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
class TElWinAzureSingleAccessPolicy: public TObject
{
	private:
		SB_DISABLE_COPY(TElWinAzureSingleAccessPolicy)
	public:
		void Reset();

		void PrepareID();

		virtual void get_ID(std::string &OutResult);

		virtual void set_ID(const std::string &Value);

		virtual int64_t get_StartTime();

		virtual void set_StartTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_StartTime, set_StartTime, TElWinAzureSingleAccessPolicy, StartTime);

		virtual int64_t get_ExpiryTime();

		virtual void set_ExpiryTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ExpiryTime, set_ExpiryTime, TElWinAzureSingleAccessPolicy, ExpiryTime);

		virtual void get_Permissions(std::string &OutResult);

		virtual void set_Permissions(const std::string &Value);

		TElWinAzureSingleAccessPolicy(TElWinAzureSingleAccessPolicyHandle handle, TElOwnHandle ownHandle);

		TElWinAzureSingleAccessPolicy();

};
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
class TElWinAzureAccessPolicy: public TObject
{
	private:
		SB_DISABLE_COPY(TElWinAzureAccessPolicy)
#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
		TElWinAzureSingleAccessPolicy* _Inst_AccessPolicies;
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

		void initInstances();

	public:
		int32_t AddPolicy();

		void RemovePolicy(int32_t Index);

		void Clear();

		void LoadFromXml(const std::string &Xml);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromXml(TStream &Stream);

		void LoadFromXml(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void SaveToXml(std::string &OutResult);

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToXml(TStream &Stream);

		void SaveToXml(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
		virtual TElWinAzureSingleAccessPolicy* get_AccessPolicies(int32_t Index);
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWinAzureAccessPolicy, Count);

		virtual bool get_UseURLEncoding();

		virtual void set_UseURLEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseURLEncoding, set_UseURLEncoding, TElWinAzureAccessPolicy, UseURLEncoding);

		TElWinAzureAccessPolicy(TElWinAzureAccessPolicyHandle handle, TElOwnHandle ownHandle);

		TElWinAzureAccessPolicy();

		virtual ~TElWinAzureAccessPolicy();

};
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
class TElWinAzureDataStorageObject: public TElCustomDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElWinAzureDataStorageObject)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Metadata;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Metadata;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual TElCustomDataStorageObjectHandle Clone();

		void Delete();

		void Delete(const std::string &SharedAccessSignature);

		bool Exists();

		bool Exists(const std::string &SharedAccessSignature);

		void Refresh();

		void Refresh(const std::string &SharedAccessSignature);

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void Write(TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void Write(TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(const std::string &SharedAccessSignature, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void Write(const std::string &SharedAccessSignature, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void Write(const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void Write(const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void Write(const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata);

		void Write(const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void Write(const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata);

		void Write(const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Strm);

		void Read(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void Read(TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void Read(TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void Read(const std::string &SharedAccessSignature, TStream &Strm);

		void Read(const std::string &SharedAccessSignature, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void Read(const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void Read(const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void GetACL(std::string &OutResult);

		void SetACL(const std::string &ACL);

#ifdef SB_USE_CLASS_TSTREAM
		void GetLocalETag(TStream &Stream, std::string &OutResult);

		void GetLocalETag(TStream *Stream, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

		void GetLocalETag(const std::string &Filename, std::string &OutResult);

		void GetRemoteETag(std::string &OutResult);

		void Resize(int64_t NewSize);

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
		void CreateSharedAccessSignature(TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult);

		void CreateSharedAccessSignature(TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult);
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

		virtual void get_ContainerName(std::string &OutResult);

		virtual int64_t get_LastModified();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LastModified, TElWinAzureDataStorageObject, LastModified);

		virtual void get_ETag(std::string &OutResult);

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElWinAzureDataStorageObject, Size);

		virtual int64_t get_AllocatedSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_AllocatedSize, TElWinAzureDataStorageObject, AllocatedSize);

		virtual void get_ContentType(std::string &OutResult);

		virtual void get_ContentEncoding(std::string &OutResult);

		virtual void get_ContentLanguage(std::string &OutResult);

		virtual void get_ContentMD5(std::string &OutResult);

		virtual void set_ContentMD5(const std::string &Value);

		virtual int64_t get_SequenceNumber();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SequenceNumber, TElWinAzureDataStorageObject, SequenceNumber);

		virtual bool get_Locked();

		SB_DECLARE_PROPERTY_GET(bool, get_Locked, TElWinAzureDataStorageObject, Locked);

		virtual void get_CopyStatus(std::string &OutResult);

		virtual void get_LeaseStatus(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Metadata();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Metadata, TElWinAzureDataStorageObject, Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Metadata();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Metadata, TElWinAzureDataStorageObject, Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_CustomHeaders, TElWinAzureDataStorageObject, CustomHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_CustomHeaders, TElWinAzureDataStorageObject, CustomHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElWinAzureDataStorageObject(TElWinAzureDataStorageObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
		explicit TElWinAzureDataStorageObject(TElWinAzureDataStorage &Storage);

		explicit TElWinAzureDataStorageObject(TElWinAzureDataStorage *Storage);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
		TElWinAzureDataStorageObject(TElWinAzureDataStorage &Storage, const std::string &ContainerName, const std::string &Name);

		TElWinAzureDataStorageObject(TElWinAzureDataStorage *Storage, const std::string &ContainerName, const std::string &Name);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

		virtual ~TElWinAzureDataStorageObject();

};
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
class TElWinAzureDataStorageContainer: public TObject
{
	private:
		SB_DISABLE_COPY(TElWinAzureDataStorageContainer)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Metadata;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Metadata;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &Name);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle AcquireObject(const std::string &Name, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(TElDataStorageObjectList &Objects);

		void List(TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers);

		void List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers);

		void List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers);

		void List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers);

		void List(TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects);

		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers);

		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers);

		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers);

		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers);

		void List(const std::string &SharedAccessSignature, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListInit();
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListInit(const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListInit(const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListInit(const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		TElWinAzureDataStorageListStateHandle ListInit(const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList &Headers);

		TElWinAzureDataStorageListStateHandle ListInit(const std::string &SharedAccessSignature, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, bool IncludeSnapshots, bool IncludeMetadata, bool IncludeUncommittedBlobs, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */
#endif

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		void ListNext(TElWinAzureDataStorageListState &State, TElDataStorageObjectList &Objects);

		void ListNext(TElWinAzureDataStorageListState *State, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE
		void ListNext(TElWinAzureDataStorageListState &State, TElDataStorageObjectList &Objects, int32_t MaxCount);

		void ListNext(TElWinAzureDataStorageListState *State, TElDataStorageObjectList *Objects, int32_t MaxCount);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE
		void ListFinal(TElWinAzureDataStorageListState &State);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, int64_t InitialSize);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, const std::string &SharedAccessSignature);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, const std::string &SharedAccessSignature);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, const std::string &SharedAccessSignature);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &SharedAccessSignature, int64_t InitialSize);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler &Handler, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, const std::string &SharedAccessSignature, TElCustomDataStorageSecurityHandler *Handler, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata, const std::string &SharedAccessSignature, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata, const std::string &SharedAccessSignature, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELWINAZUREDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT
		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata, const std::string &SharedAccessSignature, int64_t InitialSize);

		TElWinAzureDataStorageObjectHandle CreateObject(const std::string &Name, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata, const std::string &SharedAccessSignature, int64_t InitialSize);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TELWINAZUREDATASTORAGEOBJECT */
#endif

		void DeleteObject(const std::string &Name);

		void DeleteObject(const std::string &Name, const std::string &SharedAccessSignature);

		bool ObjectExists(const std::string &Name);

		bool ObjectExists(const std::string &Name, const std::string &SharedAccessSignature);

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &Name, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Name, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata);

		void WriteObject(const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &Name, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata);

		void WriteObject(const std::string &Name, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList &Metadata);

		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList &Metadata);

		void WriteObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Data, const std::string &ContentType, const std::string &ContentEncoding, const std::string &ContentLanguage, const std::string &ContentMD5, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Name, TStream &Strm);

		void ReadObject(const std::string &Name, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &Name, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(const std::string &Name, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm);

		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadObject(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &Name, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &Name, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);

		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);

		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);

		void ReadBlock(const std::string &Name, const std::string &SharedAccessSignature, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, int64_t SeqNum, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentEncoding, std::string &ObjContentLanguage, std::string &ObjContentMD5, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &DestContainerName, const std::string &DestName, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceName, const std::string &SharedAccessSignature, const std::string &DestContainerName, const std::string &DestName, const std::string &DestSharedAccessSignature, TSBWinAzureObjectAccessCondition Condition, int64_t DateTime, const std::string &ETag, TSBWinAzureObjectAccessCondition DestCondition, int64_t DestDateTime, const std::string &DestETag, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

		void GetObjectACL(const std::string &Name, std::string &OutResult);

		void SetObjectACL(const std::string &Name, const std::string &ACL);

		void GetRemoteETag(const std::string &Name, std::string &OutResult);

		void Delete();

		void Delete(const std::string &SharedAccessSignature);

		bool Exists();

		bool Exists(const std::string &SharedAccessSignature);

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
		TSBWinAzureContainerAccessLevel GetACL(TElWinAzureAccessPolicy &Policy);

		TSBWinAzureContainerAccessLevel GetACL(TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
		TSBWinAzureContainerAccessLevel GetACL(const std::string &SharedAccessSignature, TElWinAzureAccessPolicy &Policy);

		TSBWinAzureContainerAccessLevel GetACL(const std::string &SharedAccessSignature, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
		void SetACL(TSBWinAzureContainerAccessLevel Level, TElWinAzureAccessPolicy &Policy);

		void SetACL(TSBWinAzureContainerAccessLevel Level, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZUREACCESSPOLICY
		void SetACL(const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel Level, TElWinAzureAccessPolicy &Policy);

		void SetACL(const std::string &SharedAccessSignature, TSBWinAzureContainerAccessLevel Level, TElWinAzureAccessPolicy *Policy);
#endif /* SB_USE_CLASS_TELWINAZUREACCESSPOLICY */

#ifdef SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY
		void CreateSharedAccessSignature(TElWinAzureSingleAccessPolicy &Policy, std::string &OutResult);

		void CreateSharedAccessSignature(TElWinAzureSingleAccessPolicy *Policy, std::string &OutResult);
#endif /* SB_USE_CLASS_TELWINAZURESINGLEACCESSPOLICY */

		virtual void get_Name(std::string &OutResult);

		virtual void get_Address(std::string &OutResult);

		virtual int64_t get_LastModified();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LastModified, TElWinAzureDataStorageContainer, LastModified);

		virtual void get_ETag(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Metadata();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Metadata, TElWinAzureDataStorageContainer, Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Metadata();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Metadata, TElWinAzureDataStorageContainer, Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_CustomHeaders, TElWinAzureDataStorageContainer, CustomHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_CustomHeaders, TElWinAzureDataStorageContainer, CustomHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElWinAzureDataStorageContainer(TElWinAzureDataStorageContainerHandle handle, TElOwnHandle ownHandle);

		TElWinAzureDataStorageContainer();

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
		explicit TElWinAzureDataStorageContainer(TElWinAzureDataStorage &Storage);

		explicit TElWinAzureDataStorageContainer(TElWinAzureDataStorage *Storage);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

		virtual ~TElWinAzureDataStorageContainer();

};
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST
class TElWinAzureDataStorageContainerList: public TObject
{
	private:
		SB_DISABLE_COPY(TElWinAzureDataStorageContainerList)
#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		TElWinAzureDataStorageContainer* _Inst_Containers;
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER
		virtual TElWinAzureDataStorageContainer* get_Containers(int32_t Index);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINER */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElWinAzureDataStorageContainerList, Count);

		TElWinAzureDataStorageContainerList(TElWinAzureDataStorageContainerListHandle handle, TElOwnHandle ownHandle);

		TElWinAzureDataStorageContainerList();

#ifdef SB_USE_CLASS_TELWINAZUREDATASTORAGE
		explicit TElWinAzureDataStorageContainerList(TElWinAzureDataStorage &Storage);

		explicit TElWinAzureDataStorageContainerList(TElWinAzureDataStorage *Storage);
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGE */

		virtual ~TElWinAzureDataStorageContainerList();

};
#endif /* SB_USE_CLASS_TELWINAZUREDATASTORAGECONTAINERLIST */

#ifdef SB_USE_GLOBAL_PROCS_WINAZUREDATASTORAGE

#ifdef SB_USE_CLASS_TELXMLDOMNODE
void SBWinAzureDataStorage_GetNodeInnerXML(TElXMLDOMNode &XmlNode, std::string &OutResult);
void SBWinAzureDataStorage_GetNodeInnerXML(TElXMLDOMNode *XmlNode, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#endif /* SB_USE_GLOBAL_PROCS_WINAZUREDATASTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_WINAZUREDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY SBWinAzureDataStorage_GetNodeInnerXML(TElXMLDOMNodeHandle XmlNode, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_WINAZUREDATASTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBWINAZUREDATASTORAGE */
