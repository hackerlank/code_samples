#ifndef __INC_SBAWSDATASTORAGE
#define __INC_SBAWSDATASTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbhttpscommon.h"
#include "sbhttpsclient.h"
#include "sbhttpsconstants.h"
#include "sbxmlutils.h"
#include "sbxmlcore.h"
#include "sbhashfunction.h"
#include "sbconstants.h"
#include "sbstringlist.h"
#include "sbstreams.h"
#include "sbencoding.h"
#include "sbdatastorage.h"
#include "sbdatastorageutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElAWSS3DataStorageHandle;

typedef TElClassHandle TElAWSS3DataStorageObjectHandle;

typedef TElClassHandle TElAWSS3DataStorageListStateHandle;

typedef TElClassHandle TElAWSS3AccessControlGrantHandle;

typedef TElClassHandle TElAWSS3AccessControlPolicyHandle;

typedef TElClassHandle TElAWSS3DataStorageBucketHandle;

typedef TElClassHandle TElAWSS3DataStorageBucketListHandle;

typedef uint8_t TSBAWSProtocolRaw;

typedef enum
{
	awspREST = 0,
	awspSOAP = 1
} TSBAWSProtocol;

typedef uint8_t TSBAWSAuthTypeRaw;

typedef enum
{
	awsaAccessKey = 0,
	awsaCertificate = 1
} TSBAWSAuthType;

typedef uint8_t TSBAWSS3ReadObjectConditionRaw;

typedef enum
{
	awsrNone = 0,
	awsrIfModifiedSince = 1,
	awsrIfUnmodifiedSince = 2,
	awsrIfMatch = 3,
	awsrIfNoneMatch = 4
} TSBAWSS3ReadObjectCondition;

typedef uint8_t TSBAWSS3BucketAccessTypeRaw;

typedef enum
{
	awsbatAuto = 0,
	awsbatVirtualHost = 1,
	awsbatVirtualPath = 2
} TSBAWSS3BucketAccessType;

typedef uint8_t TSBAWSS3AccessControlGranteeTypeRaw;

typedef enum
{
	acqtUnknown = 0,
	acgtCanonicalUser = 1,
	acgtAmazonCustomerByEmail = 2,
	acgtGroup = 3,
	acgtAuthenticatedUsersGroup = 4,
	acgtAllUsersGroup = 5,
	acgtLogDeliveryGroup = 6
} TSBAWSS3AccessControlGranteeType;

typedef uint8_t TSBAWSS3AccessControlPermissionRaw;

typedef enum
{
	acpUnknown = 0,
	acpRead = 1,
	acpWrite = 2,
	acpReadACP = 3,
	acpWriteACP = 4,
	acpFullControl = 5
} TSBAWSS3AccessControlPermission;

typedef uint8_t TSBAWSS3BucketVersioningRaw;

typedef enum
{
	bvEnabled = 0,
	bvSuspended = 1,
	bvDisabled = 2
} TSBAWSS3BucketVersioning;

typedef uint8_t TSBAWSS3DataStorageOptionRaw;

typedef enum
{
	awsoptDetailedList = 0,
	awsoptUseHeadRequests = 1,
	awsoptLiberalBucketNaming = 2
} TSBAWSS3DataStorageOption;

typedef uint32_t TSBAWSS3DataStorageOptionsRaw;

typedef enum 
{
	f_awsoptDetailedList = 1,
	f_awsoptUseHeadRequests = 2,
	f_awsoptLiberalBucketNaming = 4
} TSBAWSS3DataStorageOptions;

typedef uint8_t TSBAWSS3RegionRaw;

typedef enum
{
	awsrCustom = 0,
	awsrDefault = 1,
	awsrUSStandard = 2,
	awsrUSWestOregon = 3,
	awsrUSWestNCalifornia = 4,
	awsrEUIreland = 5,
	awsrEUFrankfurt = 6,
	awsrAPSingapore = 7,
	awsrAPSydney = 8,
	awsrAPTokyo = 9,
	awsrSASaoPaulo = 10,
	awsrAPSeoul = 11
} TSBAWSS3Region;

typedef void (SB_CALLBACK *TSBAWSS3BeforeRequestSigningEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPSClientHandle HttpClient);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_AcquireObject(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElAWSS3DataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_AcquireObject_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStringListHandle Headers, TElAWSS3DataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_AcquireObject_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElStringListHandle Headers, TElAWSS3DataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_AcquireObject_2(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, const char * pcKey, int32_t szKey, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_List(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElDataStorageObjectListHandle Objects);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_List_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElDataStorageObjectListHandle Objects, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_List_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElDataStorageObjectListHandle Objects, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_List_2(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TElDataStorageObjectListHandle Objects);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_List_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_List_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListInit(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3DataStorageListStateHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListInit_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TStringListHandle Prefixes, TStringListHandle Headers, TElAWSS3DataStorageListStateHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListInit_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TElStringListHandle Prefixes, TElStringListHandle Headers, TElAWSS3DataStorageListStateHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListNext(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageListStateHandle State, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListNext_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageListStateHandle State, TElDataStorageObjectListHandle Objects, int32_t MaxCount);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListFinal(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageListStateHandle * State);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcObjName, int32_t szObjName, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, const char * pcObjName, int32_t szObjName, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcObjName, int32_t szObjName, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_3(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, const char * pcObjName, int32_t szObjName, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_6(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateObject_6(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteObject(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteObject_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle * Obj);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteObject_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteObject_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ObjectExists(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ObjectExists_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ObjectExists_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStringListHandle Headers, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ObjectExists_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElStringListHandle Headers, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_RefreshObject(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_RefreshObject_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_RefreshObject_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, char * pcNewETag, int32_t * szNewETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_5(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_6(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_7(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler, char * pcNewETag, int32_t * szNewETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_5(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_6(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_WriteObject_7(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageSecurityHandlerHandle Handler);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_2(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_5(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_6(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_5(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadObject_6(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_2(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_5(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_6(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, TStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_5(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReadBlock_6(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, TElStringListHandle Headers, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CopyObject(TElAWSS3DataStorageHandle _Handle, const char * pcSourceBucketName, int32_t szSourceBucketName, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CopyObject_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CopyObject_2(TElAWSS3DataStorageHandle _Handle, const char * pcSourceBucketName, int32_t szSourceBucketName, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CopyObject_3(TElAWSS3DataStorageHandle _Handle, const char * pcSourceBucketName, int32_t szSourceBucketName, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int8_t PreserveMetadata, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CopyObject_4(TElAWSS3DataStorageHandle _Handle, const char * pcSourceBucketName, int32_t szSourceBucketName, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, const char * pcStorageClass, int32_t szStorageClass, int8_t PreserveMetadata, TStringListHandle Metadata, TStringListHandle Headers, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CopyObject_2(TElAWSS3DataStorageHandle _Handle, const char * pcSourceBucketName, int32_t szSourceBucketName, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CopyObject_3(TElAWSS3DataStorageHandle _Handle, const char * pcSourceBucketName, int32_t szSourceBucketName, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CopyObject_4(TElAWSS3DataStorageHandle _Handle, const char * pcSourceBucketName, int32_t szSourceBucketName, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, const char * pcStorageClass, int32_t szStorageClass, int8_t PreserveMetadata, TElStringListHandle Metadata, TElStringListHandle Headers, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectACL(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectACL_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectACL_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectACL_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectACL_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElAWSS3AccessControlPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectACL_4(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TElAWSS3AccessControlPolicyHandle Policy);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectACL_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElAWSS3AccessControlPolicyHandle Policy, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectACL_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElAWSS3AccessControlPolicyHandle Policy, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetObjectACL(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, const char * pcACL, int32_t szACL);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetObjectACL_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, const char * pcACL, int32_t szACL);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetObjectACL_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, const char * pcACL, int32_t szACL, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetObjectACL_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, const char * pcACL, int32_t szACL, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetObjectACL_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElAWSS3AccessControlPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetObjectACL_4(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TElAWSS3AccessControlPolicyHandle Policy);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetObjectACL_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElAWSS3AccessControlPolicyHandle Policy, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetObjectACL_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElAWSS3AccessControlPolicyHandle Policy, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetLocalETag(TElAWSS3DataStorageHandle _Handle, TStreamHandle Stream, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetLocalETag_1(TElAWSS3DataStorageHandle _Handle, const char * pcFilename, int32_t szFilename, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetRemoteETag(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetRemoteETag_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetRemoteETag_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetRemoteETag_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectTorrent(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectTorrent_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageObjectHandle Obj, TStreamHandle Stream);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectTorrent_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TStringListHandle Headers, TStreamHandle Stream);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetObjectTorrent_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElStringListHandle Headers, TStreamHandle Stream);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_AcquireBucket(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3DataStorageBucketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ReleaseBucket(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle * Bucket);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateBucket(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3DataStorageBucketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateBucket_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcLocation, int32_t szLocation, TElAWSS3DataStorageBucketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateBucket_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcLocation, int32_t szLocation, const char * pcACL, int32_t szACL, TElAWSS3DataStorageBucketHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateBucket_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcLocation, int32_t szLocation, TStringListHandle Headers, TElAWSS3DataStorageBucketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateBucket_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcLocation, int32_t szLocation, const char * pcACL, int32_t szACL, TStringListHandle Headers, TElAWSS3DataStorageBucketHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateBucket_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcLocation, int32_t szLocation, TElStringListHandle Headers, TElAWSS3DataStorageBucketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_CreateBucket_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcLocation, int32_t szLocation, const char * pcACL, int32_t szACL, TElStringListHandle Headers, TElAWSS3DataStorageBucketHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucket(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucket_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle * Bucket);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucket_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucket_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_BucketExists(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_BucketExists_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_BucketExists_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_BucketExists_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketLocation(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketLocation_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketLocation_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketLocation_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketACL(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketACL_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketACL_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketACL_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketACL_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3AccessControlPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketACL_4(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TElAWSS3AccessControlPolicyHandle Policy);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketACL_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3AccessControlPolicyHandle Policy, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketACL_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3AccessControlPolicyHandle Policy, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketACL(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcACL, int32_t szACL);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketACL_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, const char * pcACL, int32_t szACL);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketACL_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcACL, int32_t szACL, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketACL_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcACL, int32_t szACL, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketACL_3(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3AccessControlPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketACL_4(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TElAWSS3AccessControlPolicyHandle Policy);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketACL_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3AccessControlPolicyHandle Policy, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketACL_5(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElAWSS3AccessControlPolicyHandle Policy, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketPolicy(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketPolicy_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketPolicy_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketPolicy_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPolicy(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcPolicy, int32_t szPolicy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPolicy_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, const char * pcPolicy, int32_t szPolicy);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPolicy_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcPolicy, int32_t szPolicy, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPolicy_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcPolicy, int32_t szPolicy, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucketPolicy(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucketPolicy_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucketPolicy_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucketPolicy_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPaymentConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcPaymentConfig, int32_t szPaymentConfig);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPaymentConfiguration_1(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, int8_t RequesterPays);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPaymentConfiguration_2(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, const char * pcPaymentConfig, int32_t szPaymentConfig);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPaymentConfiguration_3(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, int8_t RequesterPays);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPaymentConfiguration_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcPaymentConfig, int32_t szPaymentConfig, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketPaymentConfiguration_4(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcPaymentConfig, int32_t szPaymentConfig, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketPaymentConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketPaymentConfiguration_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketPaymentConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketPaymentConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_IsRequesterPaysBucket(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_IsRequesterPaysBucket_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_IsRequesterPaysBucket_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers, int8_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_IsRequesterPaysBucket_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketVersioning(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TSBAWSS3BucketVersioningRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketVersioning_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TSBAWSS3BucketVersioningRaw * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketVersioning_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers, TSBAWSS3BucketVersioningRaw * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketVersioning_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers, TSBAWSS3BucketVersioningRaw * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketVersioning(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TSBAWSS3BucketVersioningRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketVersioning_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TSBAWSS3BucketVersioningRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketVersioning_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TSBAWSS3BucketVersioningRaw Value, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketNotificationConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Topics, TStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketNotificationConfiguration_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TStringListHandle Topics, TStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketNotificationConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Topics, TStringListHandle Events, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketNotificationConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Topics, TStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketNotificationConfiguration_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TStringListHandle Topics, TStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketNotificationConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Topics, TStringListHandle Events, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketVersioning_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TSBAWSS3BucketVersioningRaw Value, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketNotificationConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Topics, TElStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketNotificationConfiguration_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TElStringListHandle Topics, TElStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketNotificationConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Topics, TElStringListHandle Events, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketNotificationConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Topics, TElStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketNotificationConfiguration_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, TElStringListHandle Topics, TElStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketNotificationConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Topics, TElStringListHandle Events, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketWebSiteConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, char * pcIndexDocument, int32_t * szIndexDocument, char * pcErrorDocument, int32_t * szErrorDocument);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketWebSiteConfiguration_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, char * pcIndexDocument, int32_t * szIndexDocument, char * pcErrorDocument, int32_t * szErrorDocument);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketWebSiteConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, char * pcIndexDocument, int32_t * szIndexDocument, char * pcErrorDocument, int32_t * szErrorDocument, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_GetBucketWebSiteConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, char * pcIndexDocument, int32_t * szIndexDocument, char * pcErrorDocument, int32_t * szErrorDocument, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketWebSiteConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcIndexDocument, int32_t szIndexDocument, const char * pcErrorDocument, int32_t szErrorDocument);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketWebSiteConfiguration_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket, const char * pcIndexDocument, int32_t szIndexDocument, const char * pcErrorDocument, int32_t szErrorDocument);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketWebSiteConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcIndexDocument, int32_t szIndexDocument, const char * pcErrorDocument, int32_t szErrorDocument, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_SetBucketWebSiteConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, const char * pcIndexDocument, int32_t szIndexDocument, const char * pcErrorDocument, int32_t szErrorDocument, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_1(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketHandle Bucket);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListBuckets(TElAWSS3DataStorageHandle _Handle, TStringListHandle Buckets);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListBuckets_1(TElAWSS3DataStorageHandle _Handle, TStringListHandle Buckets, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_DeleteBucketWebSiteConfiguration_2(TElAWSS3DataStorageHandle _Handle, const char * pcBucketName, int32_t szBucketName, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListBuckets(TElAWSS3DataStorageHandle _Handle, TElStringListHandle Buckets);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListBuckets_1(TElAWSS3DataStorageHandle _Handle, TElStringListHandle Buckets, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListBuckets_2(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketListHandle Buckets);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListBuckets_3(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketListHandle Buckets, TStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_PerformIAMRequest(TElAWSS3DataStorageHandle _Handle, const char * pcAddress, int32_t szAddress, TStringListHandle Parameters, TStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_ListBuckets_3(TElAWSS3DataStorageHandle _Handle, TElAWSS3DataStorageBucketListHandle Buckets, TElStringListHandle Headers);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_PerformIAMRequest(TElAWSS3DataStorageHandle _Handle, const char * pcAddress, int32_t szAddress, TElStringListHandle Parameters, TElStringListHandle Headers, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_OutputStream(TElAWSS3DataStorageHandle _Handle, TMemoryStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_Protocol(TElAWSS3DataStorageHandle _Handle, TSBAWSProtocolRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_Protocol(TElAWSS3DataStorageHandle _Handle, TSBAWSProtocolRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_AuthType(TElAWSS3DataStorageHandle _Handle, TSBAWSAuthTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_AuthType(TElAWSS3DataStorageHandle _Handle, TSBAWSAuthTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_KeyID(TElAWSS3DataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_KeyID(TElAWSS3DataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_AccessKey(TElAWSS3DataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_AccessKey(TElAWSS3DataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_SecurityToken(TElAWSS3DataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_SecurityToken(TElAWSS3DataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_UseSSL(TElAWSS3DataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_UseSSL(TElAWSS3DataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_HTTPClient(TElAWSS3DataStorageHandle _Handle, TElHTTPSClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_HTTPClient(TElAWSS3DataStorageHandle _Handle, TElHTTPSClientHandle Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_AWSHeaders(TElAWSS3DataStorageHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_AWSHeaders(TElAWSS3DataStorageHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_UseCRCCheck(TElAWSS3DataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_UseCRCCheck(TElAWSS3DataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_UseDelayedPut(TElAWSS3DataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_UseDelayedPut(TElAWSS3DataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_UseURLEncoding(TElAWSS3DataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_UseURLEncoding(TElAWSS3DataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_UseVersion4Signatures(TElAWSS3DataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_UseVersion4Signatures(TElAWSS3DataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_Version4SignatureHashAlgorithm(TElAWSS3DataStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_Version4SignatureHashAlgorithm(TElAWSS3DataStorageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_SecMetadataID(TElAWSS3DataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_SecMetadataID(TElAWSS3DataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_MultipartUploadPartSize(TElAWSS3DataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_MultipartUploadPartSize(TElAWSS3DataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_MultipartUploadThreshold(TElAWSS3DataStorageHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_MultipartUploadThreshold(TElAWSS3DataStorageHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_RetryCount(TElAWSS3DataStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_RetryCount(TElAWSS3DataStorageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_Options(TElAWSS3DataStorageHandle _Handle, TSBAWSS3DataStorageOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_Options(TElAWSS3DataStorageHandle _Handle, TSBAWSS3DataStorageOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_Overwrite(TElAWSS3DataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_Overwrite(TElAWSS3DataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_PassthroughMode(TElAWSS3DataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_PassthroughMode(TElAWSS3DataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_BucketAccessType(TElAWSS3DataStorageHandle _Handle, TSBAWSS3BucketAccessTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_BucketAccessType(TElAWSS3DataStorageHandle _Handle, TSBAWSS3BucketAccessTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_EmbeddedMetadataMode(TElAWSS3DataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_EmbeddedMetadataMode(TElAWSS3DataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_BaseURL(TElAWSS3DataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_BaseURL(TElAWSS3DataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_RegionID(TElAWSS3DataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_RegionID(TElAWSS3DataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_Region(TElAWSS3DataStorageHandle _Handle, TSBAWSS3RegionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_Region(TElAWSS3DataStorageHandle _Handle, TSBAWSS3RegionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_get_OnBeforeRequestSigning(TElAWSS3DataStorageHandle _Handle, TSBAWSS3BeforeRequestSigningEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_set_OnBeforeRequestSigning(TElAWSS3DataStorageHandle _Handle, TSBAWSS3BeforeRequestSigningEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorage_Create(TComponentHandle AOwner, TElAWSS3DataStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Assign(TElAWSS3DataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Clone(TElAWSS3DataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Delete(TElAWSS3DataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Exists(TElAWSS3DataStorageObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Refresh(TElAWSS3DataStorageObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Write(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Write_1(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Write_2(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Write_3(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Write_1(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Write_2(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Write_3(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Read(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Read_1(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Read_2(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Read_3(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Read_2(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Read_3(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_ReadBlock(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_ReadBlock_1(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_ReadBlock_2(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_ReadBlock_3(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_ReadBlock_2(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_ReadBlock_3(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Copy(TElAWSS3DataStorageObjectHandle _Handle, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Copy_1(TElAWSS3DataStorageObjectHandle _Handle, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Copy_2(TElAWSS3DataStorageObjectHandle _Handle, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Copy_3(TElAWSS3DataStorageObjectHandle _Handle, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, const char * pcStorageClass, int32_t szStorageClass, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Copy_1(TElAWSS3DataStorageObjectHandle _Handle, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Copy_2(TElAWSS3DataStorageObjectHandle _Handle, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Copy_3(TElAWSS3DataStorageObjectHandle _Handle, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, const char * pcStorageClass, int32_t szStorageClass, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_GetACL(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_GetACL_1(TElAWSS3DataStorageObjectHandle _Handle, TElAWSS3AccessControlPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_SetACL(TElAWSS3DataStorageObjectHandle _Handle, const char * pcACL, int32_t szACL);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_SetACL_1(TElAWSS3DataStorageObjectHandle _Handle, TElAWSS3AccessControlPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_GetLocalETag(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Stream, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_GetLocalETag_1(TElAWSS3DataStorageObjectHandle _Handle, const char * pcFilename, int32_t szFilename, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_GetRemoteETag(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_GetTorrent(TElAWSS3DataStorageObjectHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_BucketName(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_Key(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_LastModified(TElAWSS3DataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_ETag(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_Size(TElAWSS3DataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_StorageClass(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_OwnerID(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_OwnerDisplayName(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_ContentType(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_ContentDisposition(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_ContentEncoding(TElAWSS3DataStorageObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_Metadata(TElAWSS3DataStorageObjectHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_CustomHeaders(TElAWSS3DataStorageObjectHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_Metadata(TElAWSS3DataStorageObjectHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_get_CustomHeaders(TElAWSS3DataStorageObjectHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Create(TElAWSS3DataStorageHandle Storage, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageObject_Create_1(TElAWSS3DataStorageHandle Storage, const char * pcBucketName, int32_t szBucketName, const char * pcKey, int32_t szKey, TElAWSS3DataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageListState_Completed(TElAWSS3DataStorageListStateHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageListState_Create(const char * pcBucketName, int32_t szBucketName, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TStringListHandle Prefixes, TStringListHandle Headers, TElAWSS3DataStorageListStateHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageListState_Create(const char * pcBucketName, int32_t szBucketName, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TElStringListHandle Prefixes, TElStringListHandle Headers, TElAWSS3DataStorageListStateHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_Reset(TElAWSS3AccessControlGrantHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_SaveToXML(TElAWSS3AccessControlGrantHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_LoadFromXML(TElAWSS3AccessControlGrantHandle _Handle, const char * pcXml, int32_t szXml);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_LoadFromXML_1(TElAWSS3AccessControlGrantHandle _Handle, TStreamHandle XmlStream);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_LoadFromXML_2(TElAWSS3AccessControlGrantHandle _Handle, TElXMLDOMElementHandle Elem);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_get_GranteeType(TElAWSS3AccessControlGrantHandle _Handle, TSBAWSS3AccessControlGranteeTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_set_GranteeType(TElAWSS3AccessControlGrantHandle _Handle, TSBAWSS3AccessControlGranteeTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_get_UserID(TElAWSS3AccessControlGrantHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_set_UserID(TElAWSS3AccessControlGrantHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_get_UserDisplayName(TElAWSS3AccessControlGrantHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_set_UserDisplayName(TElAWSS3AccessControlGrantHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_get_GroupURI(TElAWSS3AccessControlGrantHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_set_GroupURI(TElAWSS3AccessControlGrantHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_get_Email(TElAWSS3AccessControlGrantHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_set_Email(TElAWSS3AccessControlGrantHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_get_Permission(TElAWSS3AccessControlGrantHandle _Handle, TSBAWSS3AccessControlPermissionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_set_Permission(TElAWSS3AccessControlGrantHandle _Handle, TSBAWSS3AccessControlPermissionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_get_CustomPermission(TElAWSS3AccessControlGrantHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_set_CustomPermission(TElAWSS3AccessControlGrantHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_get_CustomGrantee(TElAWSS3AccessControlGrantHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_set_CustomGrantee(TElAWSS3AccessControlGrantHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlGrant_Create(TElAWSS3AccessControlGrantHandle * OutResult);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT */

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_AddGrant(TElAWSS3AccessControlPolicyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_RemoveGrant(TElAWSS3AccessControlPolicyHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_ClearGrants(TElAWSS3AccessControlPolicyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_SaveToXML(TElAWSS3AccessControlPolicyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_LoadFromXML(TElAWSS3AccessControlPolicyHandle _Handle, const char * pcXml, int32_t szXml);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_LoadFromXML_1(TElAWSS3AccessControlPolicyHandle _Handle, TStreamHandle XmlStream);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_Reset(TElAWSS3AccessControlPolicyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_get_Grants(TElAWSS3AccessControlPolicyHandle _Handle, int32_t Index, TElAWSS3AccessControlGrantHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_get_GrantCount(TElAWSS3AccessControlPolicyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_get_OwnerID(TElAWSS3AccessControlPolicyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_set_OwnerID(TElAWSS3AccessControlPolicyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_get_OwnerDisplayName(TElAWSS3AccessControlPolicyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_set_OwnerDisplayName(TElAWSS3AccessControlPolicyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3AccessControlPolicy_Create(TElAWSS3AccessControlPolicyHandle * OutResult);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_AcquireObject(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_List(TElAWSS3DataStorageBucketHandle _Handle, TElDataStorageObjectListHandle Objects);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_List_1(TElAWSS3DataStorageBucketHandle _Handle, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TStringListHandle Prefixes, TStringListHandle Headers);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_List_1(TElAWSS3DataStorageBucketHandle _Handle, TElDataStorageObjectListHandle Objects, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, int32_t MaxCount, TElStringListHandle Prefixes, TElStringListHandle Headers);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ListInit(TElAWSS3DataStorageBucketHandle _Handle, TElAWSS3DataStorageListStateHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ListInit_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TStringListHandle Prefixes, TStringListHandle Headers, TElAWSS3DataStorageListStateHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ListInit_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcPrefix, int32_t szPrefix, const char * pcDelimiter, int32_t szDelimiter, TElStringListHandle Prefixes, TElStringListHandle Headers, TElAWSS3DataStorageListStateHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ListNext(TElAWSS3DataStorageBucketHandle _Handle, TElAWSS3DataStorageListStateHandle State, TElDataStorageObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ListNext_1(TElAWSS3DataStorageBucketHandle _Handle, TElAWSS3DataStorageListStateHandle State, TElDataStorageObjectListHandle Objects, int32_t MaxCount);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ListFinal(TElAWSS3DataStorageBucketHandle _Handle, TElAWSS3DataStorageListStateHandle * State);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CreateObject(TElAWSS3DataStorageBucketHandle _Handle, const char * pcObjName, int32_t szObjName, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CreateObject_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcObjName, int32_t szObjName, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CreateObject_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CreateObject_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CreateObject_4(TElAWSS3DataStorageBucketHandle _Handle, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CreateObject_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CreateObject_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CreateObject_4(TElAWSS3DataStorageBucketHandle _Handle, const char * pcObjName, int32_t szObjName, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler, TElAWSS3DataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_DeleteObject(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ObjectExists(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_WriteObject(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Data, TElCustomDataStorageSecurityHandlerHandle Handler);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_WriteObject_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_WriteObject_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_WriteObject_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_WriteObject_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_WriteObject_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_WriteObject_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Data, const char * pcContentType, int32_t szContentType, const char * pcContentDisposition, int32_t szContentDisposition, const char * pcContentEncoding, int32_t szContentEncoding, const char * pcStorageClass, int32_t szStorageClass, TElStringListHandle Metadata, TElCustomDataStorageSecurityHandlerHandle Handler);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadObject(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadObject_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadObject_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadObject_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadObject_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadObject_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadBlock(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadBlock_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadBlock_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadBlock_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadBlock_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjETag, int32_t * szObjETag);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_ReadBlock_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, TStreamHandle Strm, int64_t Offset, int64_t Size, int64_t * Read, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, TElStringListHandle Metadata, char * pcObjContentType, int32_t * szObjContentType, char * pcObjContentDisposition, int32_t * szObjContentDisposition, char * pcObjContentEncoding, int32_t * szObjContentEncoding, char * pcObjETag, int32_t * szObjETag);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CopyObject(TElAWSS3DataStorageBucketHandle _Handle, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TElCustomDataStorageSecurityHandlerHandle NewHandler, TElCustomDataStorageObjectHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CopyObject_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CopyObject_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CopyObject_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, const char * pcStorageClass, int32_t szStorageClass, int8_t PreserveMetadata, TStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CopyObject_1(TElAWSS3DataStorageBucketHandle _Handle, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CopyObject_2(TElAWSS3DataStorageBucketHandle _Handle, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_CopyObject_3(TElAWSS3DataStorageBucketHandle _Handle, const char * pcSourceKey, int32_t szSourceKey, const char * pcDestBucketName, int32_t szDestBucketName, const char * pcDestKey, int32_t szDestKey, TSBAWSS3ReadObjectConditionRaw Condition, int64_t DateTime, const char * pcETag, int32_t szETag, const char * pcStorageClass, int32_t szStorageClass, int8_t PreserveMetadata, TElStringListHandle Metadata, TElCustomDataStorageObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetObjectACL(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetObjectACL(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, const char * pcACL, int32_t szACL);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetRemoteETag(TElAWSS3DataStorageBucketHandle _Handle, const char * pcKey, int32_t szKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_Delete(TElAWSS3DataStorageBucketHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_Exists(TElAWSS3DataStorageBucketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetLocation(TElAWSS3DataStorageBucketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetACL(TElAWSS3DataStorageBucketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetACL_1(TElAWSS3DataStorageBucketHandle _Handle, TElAWSS3AccessControlPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetACL(TElAWSS3DataStorageBucketHandle _Handle, const char * pcACL, int32_t szACL);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetACL_1(TElAWSS3DataStorageBucketHandle _Handle, TElAWSS3AccessControlPolicyHandle Policy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetPolicy(TElAWSS3DataStorageBucketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetPolicy(TElAWSS3DataStorageBucketHandle _Handle, const char * pcPolicy, int32_t szPolicy);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_DeletePolicy(TElAWSS3DataStorageBucketHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetPaymentConfiguration(TElAWSS3DataStorageBucketHandle _Handle, const char * pcPaymentConfig, int32_t szPaymentConfig);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetPaymentConfiguration_1(TElAWSS3DataStorageBucketHandle _Handle, int8_t RequesterPays);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetPaymentConfiguration(TElAWSS3DataStorageBucketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_IsRequesterPaysBucket(TElAWSS3DataStorageBucketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetVersioning(TElAWSS3DataStorageBucketHandle _Handle, TSBAWSS3BucketVersioningRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetVersioning(TElAWSS3DataStorageBucketHandle _Handle, TSBAWSS3BucketVersioningRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetNotificationConfiguration(TElAWSS3DataStorageBucketHandle _Handle, TStringListHandle Topics, TStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetNotificationConfiguration(TElAWSS3DataStorageBucketHandle _Handle, TStringListHandle Topics, TStringListHandle Events);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetNotificationConfiguration(TElAWSS3DataStorageBucketHandle _Handle, TElStringListHandle Topics, TElStringListHandle Events);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetNotificationConfiguration(TElAWSS3DataStorageBucketHandle _Handle, TElStringListHandle Topics, TElStringListHandle Events);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_GetWebSiteConfiguration(TElAWSS3DataStorageBucketHandle _Handle, char * pcIndexDocument, int32_t * szIndexDocument, char * pcErrorDocument, int32_t * szErrorDocument);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_SetWebSiteConfiguration(TElAWSS3DataStorageBucketHandle _Handle, const char * pcIndexDocument, int32_t szIndexDocument, const char * pcErrorDocument, int32_t szErrorDocument);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_DeleteWebSiteConfiguration(TElAWSS3DataStorageBucketHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_get_Name(TElAWSS3DataStorageBucketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_get_CreationDate(TElAWSS3DataStorageBucketHandle _Handle, int64_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_get_CustomHeaders(TElAWSS3DataStorageBucketHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_get_CustomHeaders(TElAWSS3DataStorageBucketHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_Create(TElAWSS3DataStorageBucketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucket_Create_1(TElAWSS3DataStorageHandle Storage, TElAWSS3DataStorageBucketHandle * OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucketList_get_Buckets(TElAWSS3DataStorageBucketListHandle _Handle, int32_t Index, TElAWSS3DataStorageBucketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucketList_get_Count(TElAWSS3DataStorageBucketListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucketList_get_OwnerID(TElAWSS3DataStorageBucketListHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucketList_get_OwnerDisplayName(TElAWSS3DataStorageBucketListHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucketList_Create(TElAWSS3DataStorageBucketListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAWSS3DataStorageBucketList_Create_1(TElAWSS3DataStorageHandle Storage, TElAWSS3DataStorageBucketListHandle * OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElAWSS3DataStorage;
class TElAWSS3DataStorageObject;
class TElAWSS3DataStorageListState;
class TElAWSS3AccessControlGrant;
class TElAWSS3AccessControlPolicy;
class TElAWSS3DataStorageBucket;
class TElAWSS3DataStorageBucketList;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBAWSS3DataStorageOptions)

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
class TElAWSS3DataStorage: public TElCustomDataStorage
{
	private:
		SB_DISABLE_COPY(TElAWSS3DataStorage)
#ifdef SB_USE_CLASS_TMEMORYSTREAM
		TMemoryStream* _Inst_OutputStream;
#endif /* SB_USE_CLASS_TMEMORYSTREAM */
#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		TElHTTPSClient* _Inst_HTTPClient;
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AWSHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AWSHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		TElAWSS3DataStorageObjectHandle AcquireObject(const std::string &BucketName, const std::string &Key);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTRINGLIST
		TElAWSS3DataStorageObjectHandle AcquireObject(const std::string &BucketName, const std::string &Key, TStringList &Headers);

		TElAWSS3DataStorageObjectHandle AcquireObject(const std::string &BucketName, const std::string &Key, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElAWSS3DataStorageObjectHandle AcquireObject(const std::string &BucketName, const std::string &Key, TElStringList &Headers);

		TElAWSS3DataStorageObjectHandle AcquireObject(const std::string &BucketName, const std::string &Key, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT
		TElAWSS3DataStorageObjectHandle AcquireObject(TElAWSS3DataStorageBucket &Bucket, const std::string &Key);

		TElAWSS3DataStorageObjectHandle AcquireObject(TElAWSS3DataStorageBucket *Bucket, const std::string &Key);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
		void List(const std::string &BucketName, TElDataStorageObjectList &Objects);

		void List(const std::string &BucketName, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &BucketName, TElDataStorageObjectList &Objects, TStringList &Headers);

		void List(const std::string &BucketName, TElDataStorageObjectList *Objects, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &BucketName, TElDataStorageObjectList &Objects, TElStringList &Headers);

		void List(const std::string &BucketName, TElDataStorageObjectList *Objects, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELDATASTORAGEOBJECTLIST
		void List(TElAWSS3DataStorageBucket &Bucket, TElDataStorageObjectList &Objects);

		void List(TElAWSS3DataStorageBucket *Bucket, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST
		void List(const std::string &BucketName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList &Prefixes, TStringList &Headers);

		void List(const std::string &BucketName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST
		void List(const std::string &BucketName, TElDataStorageObjectList &Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList &Prefixes, TElStringList &Headers);

		void List(const std::string &BucketName, TElDataStorageObjectList *Objects, const std::string &Prefix, const std::string &Delimiter, int32_t MaxCount, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELDATASTORAGEOBJECTLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
		TElAWSS3DataStorageListStateHandle ListInit(const std::string &BucketName);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TSTRINGLIST
		TElAWSS3DataStorageListStateHandle ListInit(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers);

		TElAWSS3DataStorageListStateHandle ListInit(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELSTRINGLIST
		TElAWSS3DataStorageListStateHandle ListInit(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers);

		TElAWSS3DataStorageListStateHandle ListInit(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST
		void ListNext(TElAWSS3DataStorageListState &State, TElDataStorageObjectList &Objects);

		void ListNext(TElAWSS3DataStorageListState *State, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST
		void ListNext(TElAWSS3DataStorageListState &State, TElDataStorageObjectList &Objects, int32_t MaxCount);

		void ListNext(TElAWSS3DataStorageListState *State, TElDataStorageObjectList *Objects, int32_t MaxCount);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
		void ListFinal(TElAWSS3DataStorageListState &State);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT
		TElAWSS3DataStorageObjectHandle CreateObject(TElAWSS3DataStorageBucket &Bucket, const std::string &ObjName);

		TElAWSS3DataStorageObjectHandle CreateObject(TElAWSS3DataStorageBucket *Bucket, const std::string &ObjName);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElAWSS3DataStorageObjectHandle CreateObject(TElAWSS3DataStorageBucket &Bucket, const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(TElAWSS3DataStorageBucket *Bucket, const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &BucketName, const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

		void DeleteObject(const std::string &BucketName, const std::string &Key);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		void DeleteObject(TElAWSS3DataStorageObject &Obj);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void DeleteObject(const std::string &BucketName, const std::string &Key, TStringList &Headers);

		void DeleteObject(const std::string &BucketName, const std::string &Key, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void DeleteObject(const std::string &BucketName, const std::string &Key, TElStringList &Headers);

		void DeleteObject(const std::string &BucketName, const std::string &Key, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool ObjectExists(const std::string &BucketName, const std::string &Key);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		bool ObjectExists(TElAWSS3DataStorageObject &Obj);

		bool ObjectExists(TElAWSS3DataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		bool ObjectExists(const std::string &BucketName, const std::string &Key, TStringList &Headers);

		bool ObjectExists(const std::string &BucketName, const std::string &Key, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		bool ObjectExists(const std::string &BucketName, const std::string &Key, TElStringList &Headers);

		bool ObjectExists(const std::string &BucketName, const std::string &Key, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		void RefreshObject(TElAWSS3DataStorageObject &Obj);

		void RefreshObject(TElAWSS3DataStorageObject *Obj);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTRINGLIST
		void RefreshObject(TElAWSS3DataStorageObject &Obj, TStringList &Headers);

		void RefreshObject(TElAWSS3DataStorageObject *Obj, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST
		void RefreshObject(TElAWSS3DataStorageObject &Obj, TElStringList &Headers);

		void RefreshObject(TElAWSS3DataStorageObject *Obj, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, std::string &NewETag);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, std::string &NewETag);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &BucketName, const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler, std::string &NewETag);

		void WriteObject(const std::string &BucketName, const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler, std::string &NewETag);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(TElAWSS3DataStorageObject &Obj, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElStringList &Headers, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElAWSS3DataStorageObject *Obj, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElStringList *Headers, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm);

		void ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);

		void ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);

		void ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &BucketName, const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadObject(const std::string &BucketName, const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(TElAWSS3DataStorageObject &Obj, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadObject(TElAWSS3DataStorageObject *Obj, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);

		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM
		void ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);

		void ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadBlock(const std::string &BucketName, const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, TStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, TStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(TElAWSS3DataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, TElStringList &Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadBlock(TElAWSS3DataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, TElStringList *Headers, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(TElAWSS3DataStorageObject &Obj, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(TElAWSS3DataStorageObject *Obj, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList &Metadata, TStringList &Headers);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList *Metadata, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList &Metadata, TElStringList &Headers);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceBucketName, const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList *Metadata, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

		void GetObjectACL(const std::string &BucketName, const std::string &Key, std::string &OutResult);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		void GetObjectACL(TElAWSS3DataStorageObject &Obj, std::string &OutResult);

		void GetObjectACL(TElAWSS3DataStorageObject *Obj, std::string &OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetObjectACL(const std::string &BucketName, const std::string &Key, TStringList &Headers, std::string &OutResult);

		void GetObjectACL(const std::string &BucketName, const std::string &Key, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetObjectACL(const std::string &BucketName, const std::string &Key, TElStringList &Headers, std::string &OutResult);

		void GetObjectACL(const std::string &BucketName, const std::string &Key, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
		void GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy);

		void GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEOBJECT
		void GetObjectACL(TElAWSS3DataStorageObject &Obj, TElAWSS3AccessControlPolicy &Policy);

		void GetObjectACL(TElAWSS3DataStorageObject *Obj, TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST
		void GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy, TStringList &Headers);

		void GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST
		void GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy, TElStringList &Headers);

		void GetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST */
#endif

		void SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		void SetObjectACL(TElAWSS3DataStorageObject &Obj, const std::string &ACL);

		void SetObjectACL(TElAWSS3DataStorageObject *Obj, const std::string &ACL);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL, TStringList &Headers);

		void SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL, TElStringList &Headers);

		void SetObjectACL(const std::string &BucketName, const std::string &Key, const std::string &ACL, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
		void SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy);

		void SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEOBJECT
		void SetObjectACL(TElAWSS3DataStorageObject &Obj, TElAWSS3AccessControlPolicy &Policy);

		void SetObjectACL(TElAWSS3DataStorageObject *Obj, TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST
		void SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy, TStringList &Headers);

		void SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST
		void SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy &Policy, TElStringList &Headers);

		void SetObjectACL(const std::string &BucketName, const std::string &Key, TElAWSS3AccessControlPolicy *Policy, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void GetLocalETag(TStream &Stream, std::string &OutResult);

		void GetLocalETag(TStream *Stream, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

		void GetLocalETag(const std::string &Filename, std::string &OutResult);

		void GetRemoteETag(const std::string &BucketName, const std::string &Key, std::string &OutResult);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		void GetRemoteETag(TElAWSS3DataStorageObject &Obj, std::string &OutResult);

		void GetRemoteETag(TElAWSS3DataStorageObject *Obj, std::string &OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetRemoteETag(const std::string &BucketName, const std::string &Key, TStringList &Headers, std::string &OutResult);

		void GetRemoteETag(const std::string &BucketName, const std::string &Key, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetRemoteETag(const std::string &BucketName, const std::string &Key, TElStringList &Headers, std::string &OutResult);

		void GetRemoteETag(const std::string &BucketName, const std::string &Key, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void GetObjectTorrent(const std::string &BucketName, const std::string &Key, TStream &Stream);

		void GetObjectTorrent(const std::string &BucketName, const std::string &Key, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM
		void GetObjectTorrent(TElAWSS3DataStorageObject &Obj, TStream &Stream);

		void GetObjectTorrent(TElAWSS3DataStorageObject *Obj, TStream *Stream);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void GetObjectTorrent(const std::string &BucketName, const std::string &Key, TStringList &Headers, TStream &Stream);

		void GetObjectTorrent(const std::string &BucketName, const std::string &Key, TStringList *Headers, TStream *Stream);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void GetObjectTorrent(const std::string &BucketName, const std::string &Key, TElStringList &Headers, TStream &Stream);

		void GetObjectTorrent(const std::string &BucketName, const std::string &Key, TElStringList *Headers, TStream *Stream);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		TElAWSS3DataStorageBucketHandle AcquireBucket(const std::string &BucketName);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void ReleaseBucket(TElAWSS3DataStorageBucket &Bucket);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST
		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, TStringList &Headers);

		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST
		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, TElStringList &Headers);

		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST
		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL, TStringList &Headers);

		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST
		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL, TElStringList &Headers);

		TElAWSS3DataStorageBucketHandle CreateBucket(const std::string &BucketName, const std::string &Location, const std::string &ACL, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST */
#endif

		void DeleteBucket(const std::string &BucketName);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void DeleteBucket(TElAWSS3DataStorageBucket &Bucket);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void DeleteBucket(const std::string &BucketName, TStringList &Headers);

		void DeleteBucket(const std::string &BucketName, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void DeleteBucket(const std::string &BucketName, TElStringList &Headers);

		void DeleteBucket(const std::string &BucketName, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool BucketExists(const std::string &BucketName);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		bool BucketExists(TElAWSS3DataStorageBucket &Bucket);

		bool BucketExists(TElAWSS3DataStorageBucket *Bucket);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		bool BucketExists(const std::string &BucketName, TStringList &Headers);

		bool BucketExists(const std::string &BucketName, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		bool BucketExists(const std::string &BucketName, TElStringList &Headers);

		bool BucketExists(const std::string &BucketName, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void GetBucketLocation(const std::string &BucketName, std::string &OutResult);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void GetBucketLocation(TElAWSS3DataStorageBucket &Bucket, std::string &OutResult);

		void GetBucketLocation(TElAWSS3DataStorageBucket *Bucket, std::string &OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetBucketLocation(const std::string &BucketName, TStringList &Headers, std::string &OutResult);

		void GetBucketLocation(const std::string &BucketName, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetBucketLocation(const std::string &BucketName, TElStringList &Headers, std::string &OutResult);

		void GetBucketLocation(const std::string &BucketName, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void GetBucketACL(const std::string &BucketName, std::string &OutResult);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void GetBucketACL(TElAWSS3DataStorageBucket &Bucket, std::string &OutResult);

		void GetBucketACL(TElAWSS3DataStorageBucket *Bucket, std::string &OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetBucketACL(const std::string &BucketName, TStringList &Headers, std::string &OutResult);

		void GetBucketACL(const std::string &BucketName, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetBucketACL(const std::string &BucketName, TElStringList &Headers, std::string &OutResult);

		void GetBucketACL(const std::string &BucketName, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
		void GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy);

		void GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEBUCKET
		void GetBucketACL(TElAWSS3DataStorageBucket &Bucket, TElAWSS3AccessControlPolicy &Policy);

		void GetBucketACL(TElAWSS3DataStorageBucket *Bucket, TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST
		void GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy, TStringList &Headers);

		void GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST
		void GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy, TElStringList &Headers);

		void GetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST */
#endif

		void SetBucketACL(const std::string &BucketName, const std::string &ACL);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void SetBucketACL(TElAWSS3DataStorageBucket &Bucket, const std::string &ACL);

		void SetBucketACL(TElAWSS3DataStorageBucket *Bucket, const std::string &ACL);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetBucketACL(const std::string &BucketName, const std::string &ACL, TStringList &Headers);

		void SetBucketACL(const std::string &BucketName, const std::string &ACL, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetBucketACL(const std::string &BucketName, const std::string &ACL, TElStringList &Headers);

		void SetBucketACL(const std::string &BucketName, const std::string &ACL, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
		void SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy);

		void SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEBUCKET
		void SetBucketACL(TElAWSS3DataStorageBucket &Bucket, TElAWSS3AccessControlPolicy &Policy);

		void SetBucketACL(TElAWSS3DataStorageBucket *Bucket, TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST
		void SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy, TStringList &Headers);

		void SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST
		void SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy &Policy, TElStringList &Headers);

		void SetBucketACL(const std::string &BucketName, TElAWSS3AccessControlPolicy *Policy, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3ACCESSCONTROLPOLICY_AND_TELSTRINGLIST */
#endif

		void GetBucketPolicy(const std::string &BucketName, std::string &OutResult);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void GetBucketPolicy(TElAWSS3DataStorageBucket &Bucket, std::string &OutResult);

		void GetBucketPolicy(TElAWSS3DataStorageBucket *Bucket, std::string &OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetBucketPolicy(const std::string &BucketName, TStringList &Headers, std::string &OutResult);

		void GetBucketPolicy(const std::string &BucketName, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetBucketPolicy(const std::string &BucketName, TElStringList &Headers, std::string &OutResult);

		void GetBucketPolicy(const std::string &BucketName, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void SetBucketPolicy(const std::string &BucketName, const std::string &Policy);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void SetBucketPolicy(TElAWSS3DataStorageBucket &Bucket, const std::string &Policy);

		void SetBucketPolicy(TElAWSS3DataStorageBucket *Bucket, const std::string &Policy);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetBucketPolicy(const std::string &BucketName, const std::string &Policy, TStringList &Headers);

		void SetBucketPolicy(const std::string &BucketName, const std::string &Policy, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetBucketPolicy(const std::string &BucketName, const std::string &Policy, TElStringList &Headers);

		void SetBucketPolicy(const std::string &BucketName, const std::string &Policy, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void DeleteBucketPolicy(const std::string &BucketName);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void DeleteBucketPolicy(TElAWSS3DataStorageBucket &Bucket);

		void DeleteBucketPolicy(TElAWSS3DataStorageBucket *Bucket);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void DeleteBucketPolicy(const std::string &BucketName, TStringList &Headers);

		void DeleteBucketPolicy(const std::string &BucketName, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void DeleteBucketPolicy(const std::string &BucketName, TElStringList &Headers);

		void DeleteBucketPolicy(const std::string &BucketName, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig);

		void SetBucketPaymentConfiguration(const std::string &BucketName, bool RequesterPays);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void SetBucketPaymentConfiguration(TElAWSS3DataStorageBucket &Bucket, const std::string &PaymentConfig);

		void SetBucketPaymentConfiguration(TElAWSS3DataStorageBucket *Bucket, const std::string &PaymentConfig);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void SetBucketPaymentConfiguration(TElAWSS3DataStorageBucket &Bucket, bool RequesterPays);

		void SetBucketPaymentConfiguration(TElAWSS3DataStorageBucket *Bucket, bool RequesterPays);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig, TStringList &Headers);

		void SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig, TElStringList &Headers);

		void SetBucketPaymentConfiguration(const std::string &BucketName, const std::string &PaymentConfig, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void GetBucketPaymentConfiguration(const std::string &BucketName, std::string &OutResult);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void GetBucketPaymentConfiguration(TElAWSS3DataStorageBucket &Bucket, std::string &OutResult);

		void GetBucketPaymentConfiguration(TElAWSS3DataStorageBucket *Bucket, std::string &OutResult);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetBucketPaymentConfiguration(const std::string &BucketName, TStringList &Headers, std::string &OutResult);

		void GetBucketPaymentConfiguration(const std::string &BucketName, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetBucketPaymentConfiguration(const std::string &BucketName, TElStringList &Headers, std::string &OutResult);

		void GetBucketPaymentConfiguration(const std::string &BucketName, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool IsRequesterPaysBucket(const std::string &BucketName);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		bool IsRequesterPaysBucket(TElAWSS3DataStorageBucket &Bucket);

		bool IsRequesterPaysBucket(TElAWSS3DataStorageBucket *Bucket);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		bool IsRequesterPaysBucket(const std::string &BucketName, TStringList &Headers);

		bool IsRequesterPaysBucket(const std::string &BucketName, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		bool IsRequesterPaysBucket(const std::string &BucketName, TElStringList &Headers);

		bool IsRequesterPaysBucket(const std::string &BucketName, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TSBAWSS3BucketVersioning GetBucketVersioning(const std::string &BucketName);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		TSBAWSS3BucketVersioning GetBucketVersioning(TElAWSS3DataStorageBucket &Bucket);

		TSBAWSS3BucketVersioning GetBucketVersioning(TElAWSS3DataStorageBucket *Bucket);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TSBAWSS3BucketVersioning GetBucketVersioning(const std::string &BucketName, TStringList &Headers);

		TSBAWSS3BucketVersioning GetBucketVersioning(const std::string &BucketName, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TSBAWSS3BucketVersioning GetBucketVersioning(const std::string &BucketName, TElStringList &Headers);

		TSBAWSS3BucketVersioning GetBucketVersioning(const std::string &BucketName, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void SetBucketVersioning(TElAWSS3DataStorageBucket &Bucket, TSBAWSS3BucketVersioning Value);

		void SetBucketVersioning(TElAWSS3DataStorageBucket *Bucket, TSBAWSS3BucketVersioning Value);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value, TStringList &Headers);

		void SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value, TElStringList &Headers);

		void SetBucketVersioning(const std::string &BucketName, TSBAWSS3BucketVersioning Value, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetBucketNotificationConfiguration(const std::string &BucketName, TStringList &Topics, TStringList &Events);

		void GetBucketNotificationConfiguration(const std::string &BucketName, TStringList *Topics, TStringList *Events);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetBucketNotificationConfiguration(const std::string &BucketName, TElStringList &Topics, TElStringList &Events);

		void GetBucketNotificationConfiguration(const std::string &BucketName, TElStringList *Topics, TElStringList *Events);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST
		void GetBucketNotificationConfiguration(TElAWSS3DataStorageBucket &Bucket, TStringList &Topics, TStringList &Events);

		void GetBucketNotificationConfiguration(TElAWSS3DataStorageBucket *Bucket, TStringList *Topics, TStringList *Events);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST
		void GetBucketNotificationConfiguration(TElAWSS3DataStorageBucket &Bucket, TElStringList &Topics, TElStringList &Events);

		void GetBucketNotificationConfiguration(TElAWSS3DataStorageBucket *Bucket, TElStringList *Topics, TElStringList *Events);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetBucketNotificationConfiguration(const std::string &BucketName, TStringList &Topics, TStringList &Events, TStringList &Headers);

		void GetBucketNotificationConfiguration(const std::string &BucketName, TStringList *Topics, TStringList *Events, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetBucketNotificationConfiguration(const std::string &BucketName, TElStringList &Topics, TElStringList &Events, TElStringList &Headers);

		void GetBucketNotificationConfiguration(const std::string &BucketName, TElStringList *Topics, TElStringList *Events, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetBucketNotificationConfiguration(const std::string &BucketName, TStringList &Topics, TStringList &Events);

		void SetBucketNotificationConfiguration(const std::string &BucketName, TStringList *Topics, TStringList *Events);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetBucketNotificationConfiguration(const std::string &BucketName, TElStringList &Topics, TElStringList &Events);

		void SetBucketNotificationConfiguration(const std::string &BucketName, TElStringList *Topics, TElStringList *Events);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST
		void SetBucketNotificationConfiguration(TElAWSS3DataStorageBucket &Bucket, TStringList &Topics, TStringList &Events);

		void SetBucketNotificationConfiguration(TElAWSS3DataStorageBucket *Bucket, TStringList *Topics, TStringList *Events);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST
		void SetBucketNotificationConfiguration(TElAWSS3DataStorageBucket &Bucket, TElStringList &Topics, TElStringList &Events);

		void SetBucketNotificationConfiguration(TElAWSS3DataStorageBucket *Bucket, TElStringList *Topics, TElStringList *Events);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKET_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetBucketNotificationConfiguration(const std::string &BucketName, TStringList &Topics, TStringList &Events, TStringList &Headers);

		void SetBucketNotificationConfiguration(const std::string &BucketName, TStringList *Topics, TStringList *Events, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetBucketNotificationConfiguration(const std::string &BucketName, TElStringList &Topics, TElStringList &Events, TElStringList &Headers);

		void SetBucketNotificationConfiguration(const std::string &BucketName, TElStringList *Topics, TElStringList *Events, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void GetBucketWebSiteConfiguration(TElAWSS3DataStorageBucket &Bucket, std::string &IndexDocument, std::string &ErrorDocument);

		void GetBucketWebSiteConfiguration(TElAWSS3DataStorageBucket *Bucket, std::string &IndexDocument, std::string &ErrorDocument);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument, TStringList &Headers);

		void GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument, TElStringList &Headers);

		void GetBucketWebSiteConfiguration(const std::string &BucketName, std::string &IndexDocument, std::string &ErrorDocument, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void SetBucketWebSiteConfiguration(TElAWSS3DataStorageBucket &Bucket, const std::string &IndexDocument, const std::string &ErrorDocument);

		void SetBucketWebSiteConfiguration(TElAWSS3DataStorageBucket *Bucket, const std::string &IndexDocument, const std::string &ErrorDocument);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument, TStringList &Headers);

		void SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument, TElStringList &Headers);

		void SetBucketWebSiteConfiguration(const std::string &BucketName, const std::string &IndexDocument, const std::string &ErrorDocument, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void DeleteBucketWebSiteConfiguration(const std::string &BucketName);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		void DeleteBucketWebSiteConfiguration(TElAWSS3DataStorageBucket &Bucket);

		void DeleteBucketWebSiteConfiguration(TElAWSS3DataStorageBucket *Bucket);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void DeleteBucketWebSiteConfiguration(const std::string &BucketName, TStringList &Headers);

		void DeleteBucketWebSiteConfiguration(const std::string &BucketName, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void DeleteBucketWebSiteConfiguration(const std::string &BucketName, TElStringList &Headers);

		void DeleteBucketWebSiteConfiguration(const std::string &BucketName, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void ListBuckets(TStringList &Buckets);

		void ListBuckets(TStringList *Buckets);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void ListBuckets(TElStringList &Buckets);

		void ListBuckets(TElStringList *Buckets);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void ListBuckets(TStringList &Buckets, TStringList &Headers);

		void ListBuckets(TStringList *Buckets, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void ListBuckets(TElStringList &Buckets, TElStringList &Headers);

		void ListBuckets(TElStringList *Buckets, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST
		void ListBuckets(TElAWSS3DataStorageBucketList &Buckets);

		void ListBuckets(TElAWSS3DataStorageBucketList *Buckets);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKETLIST_AND_TSTRINGLIST
		void ListBuckets(TElAWSS3DataStorageBucketList &Buckets, TStringList &Headers);

		void ListBuckets(TElAWSS3DataStorageBucketList *Buckets, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKETLIST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKETLIST_AND_TELSTRINGLIST
		void ListBuckets(TElAWSS3DataStorageBucketList &Buckets, TElStringList &Headers);

		void ListBuckets(TElAWSS3DataStorageBucketList *Buckets, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEBUCKETLIST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void PerformIAMRequest(const std::string &Address, TStringList &Parameters, TStringList &Headers, std::string &OutResult);

		void PerformIAMRequest(const std::string &Address, TStringList *Parameters, TStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void PerformIAMRequest(const std::string &Address, TElStringList &Parameters, TElStringList &Headers, std::string &OutResult);

		void PerformIAMRequest(const std::string &Address, TElStringList *Parameters, TElStringList *Headers, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TMEMORYSTREAM
		virtual TMemoryStream* get_OutputStream();

		SB_DECLARE_PROPERTY_GET(TMemoryStream*, get_OutputStream, TElAWSS3DataStorage, OutputStream);
#endif /* SB_USE_CLASS_TMEMORYSTREAM */

		virtual TSBAWSProtocol get_Protocol();

		virtual void set_Protocol(TSBAWSProtocol Value);

		SB_DECLARE_PROPERTY(TSBAWSProtocol, get_Protocol, set_Protocol, TElAWSS3DataStorage, Protocol);

		virtual TSBAWSAuthType get_AuthType();

		virtual void set_AuthType(TSBAWSAuthType Value);

		SB_DECLARE_PROPERTY(TSBAWSAuthType, get_AuthType, set_AuthType, TElAWSS3DataStorage, AuthType);

		virtual void get_KeyID(std::string &OutResult);

		virtual void set_KeyID(const std::string &Value);

		virtual void get_AccessKey(std::string &OutResult);

		virtual void set_AccessKey(const std::string &Value);

		virtual void get_SecurityToken(std::string &OutResult);

		virtual void set_SecurityToken(const std::string &Value);

		virtual bool get_UseSSL();

		virtual void set_UseSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSL, set_UseSSL, TElAWSS3DataStorage, UseSSL);

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
		virtual TElHTTPSClient* get_HTTPClient();

		virtual void set_HTTPClient(TElHTTPSClient &Value);

		virtual void set_HTTPClient(TElHTTPSClient *Value);

		SB_DECLARE_PROPERTY(TElHTTPSClient*, get_HTTPClient, set_HTTPClient, TElAWSS3DataStorage, HTTPClient);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AWSHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AWSHeaders, TElAWSS3DataStorage, AWSHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AWSHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AWSHeaders, TElAWSS3DataStorage, AWSHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_UseCRCCheck();

		virtual void set_UseCRCCheck(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCRCCheck, set_UseCRCCheck, TElAWSS3DataStorage, UseCRCCheck);

		virtual bool get_UseDelayedPut();

		virtual void set_UseDelayedPut(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDelayedPut, set_UseDelayedPut, TElAWSS3DataStorage, UseDelayedPut);

		virtual bool get_UseURLEncoding();

		virtual void set_UseURLEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseURLEncoding, set_UseURLEncoding, TElAWSS3DataStorage, UseURLEncoding);

		virtual bool get_UseVersion4Signatures();

		virtual void set_UseVersion4Signatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseVersion4Signatures, set_UseVersion4Signatures, TElAWSS3DataStorage, UseVersion4Signatures);

		virtual int32_t get_Version4SignatureHashAlgorithm();

		virtual void set_Version4SignatureHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version4SignatureHashAlgorithm, set_Version4SignatureHashAlgorithm, TElAWSS3DataStorage, Version4SignatureHashAlgorithm);

		virtual void get_SecMetadataID(std::string &OutResult);

		virtual void set_SecMetadataID(const std::string &Value);

		virtual int64_t get_MultipartUploadPartSize();

		virtual void set_MultipartUploadPartSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MultipartUploadPartSize, set_MultipartUploadPartSize, TElAWSS3DataStorage, MultipartUploadPartSize);

		virtual int64_t get_MultipartUploadThreshold();

		virtual void set_MultipartUploadThreshold(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MultipartUploadThreshold, set_MultipartUploadThreshold, TElAWSS3DataStorage, MultipartUploadThreshold);

		virtual int32_t get_RetryCount();

		virtual void set_RetryCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RetryCount, set_RetryCount, TElAWSS3DataStorage, RetryCount);

		virtual TSBAWSS3DataStorageOptions get_Options();

		virtual void set_Options(TSBAWSS3DataStorageOptions Value);

		SB_DECLARE_PROPERTY(TSBAWSS3DataStorageOptions, get_Options, set_Options, TElAWSS3DataStorage, Options);

		virtual bool get_Overwrite();

		virtual void set_Overwrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Overwrite, set_Overwrite, TElAWSS3DataStorage, Overwrite);

		virtual bool get_PassthroughMode();

		virtual void set_PassthroughMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassthroughMode, set_PassthroughMode, TElAWSS3DataStorage, PassthroughMode);

		virtual TSBAWSS3BucketAccessType get_BucketAccessType();

		virtual void set_BucketAccessType(TSBAWSS3BucketAccessType Value);

		SB_DECLARE_PROPERTY(TSBAWSS3BucketAccessType, get_BucketAccessType, set_BucketAccessType, TElAWSS3DataStorage, BucketAccessType);

		virtual bool get_EmbeddedMetadataMode();

		virtual void set_EmbeddedMetadataMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EmbeddedMetadataMode, set_EmbeddedMetadataMode, TElAWSS3DataStorage, EmbeddedMetadataMode);

		virtual void get_BaseURL(std::string &OutResult);

		virtual void set_BaseURL(const std::string &Value);

		virtual void get_RegionID(std::string &OutResult);

		virtual void set_RegionID(const std::string &Value);

		virtual TSBAWSS3Region get_Region();

		virtual void set_Region(TSBAWSS3Region Value);

		SB_DECLARE_PROPERTY(TSBAWSS3Region, get_Region, set_Region, TElAWSS3DataStorage, Region);

		virtual void get_OnBeforeRequestSigning(TSBAWSS3BeforeRequestSigningEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeRequestSigning(TSBAWSS3BeforeRequestSigningEvent pMethodValue, void * pDataValue);

		TElAWSS3DataStorage(TElAWSS3DataStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElAWSS3DataStorage(TComponent &AOwner);

		explicit TElAWSS3DataStorage(TComponent *AOwner);

		virtual ~TElAWSS3DataStorage();

};
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
class TElAWSS3DataStorageObject: public TElCustomDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElAWSS3DataStorageObject)
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

		bool Exists();

		void Refresh();

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void Write(TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void Write(TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void Write(TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Strm);

		void Read(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);

		void Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void Read(TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void Read(TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadBlock(TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle Copy(const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void GetACL(std::string &OutResult);

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
		void GetACL(TElAWSS3AccessControlPolicy &Policy);

		void GetACL(TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

		void SetACL(const std::string &ACL);

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
		void SetACL(TElAWSS3AccessControlPolicy &Policy);

		void SetACL(TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASS_TSTREAM
		void GetLocalETag(TStream &Stream, std::string &OutResult);

		void GetLocalETag(TStream *Stream, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

		void GetLocalETag(const std::string &Filename, std::string &OutResult);

		void GetRemoteETag(std::string &OutResult);

#ifdef SB_USE_CLASS_TSTREAM
		void GetTorrent(TStream &Stream);

		void GetTorrent(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_BucketName(std::string &OutResult);

		virtual void get_Key(std::string &OutResult);

		virtual int64_t get_LastModified();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LastModified, TElAWSS3DataStorageObject, LastModified);

		virtual void get_ETag(std::string &OutResult);

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElAWSS3DataStorageObject, Size);

		virtual void get_StorageClass(std::string &OutResult);

		virtual void get_OwnerID(std::string &OutResult);

		virtual void get_OwnerDisplayName(std::string &OutResult);

		virtual void get_ContentType(std::string &OutResult);

		virtual void get_ContentDisposition(std::string &OutResult);

		virtual void get_ContentEncoding(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Metadata();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Metadata, TElAWSS3DataStorageObject, Metadata);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Metadata();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Metadata, TElAWSS3DataStorageObject, Metadata);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_CustomHeaders, TElAWSS3DataStorageObject, CustomHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_CustomHeaders, TElAWSS3DataStorageObject, CustomHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElAWSS3DataStorageObject(TElAWSS3DataStorageObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
		explicit TElAWSS3DataStorageObject(TElAWSS3DataStorage &Storage);

		explicit TElAWSS3DataStorageObject(TElAWSS3DataStorage *Storage);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
		TElAWSS3DataStorageObject(TElAWSS3DataStorage &Storage, const std::string &BucketName, const std::string &Key);

		TElAWSS3DataStorageObject(TElAWSS3DataStorage *Storage, const std::string &BucketName, const std::string &Key);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

		virtual ~TElAWSS3DataStorageObject();

};
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
class TElAWSS3DataStorageListState: public TObject
{
	private:
		SB_DISABLE_COPY(TElAWSS3DataStorageListState)
	public:
		bool Completed();

		TElAWSS3DataStorageListState(TElAWSS3DataStorageListStateHandle handle, TElOwnHandle ownHandle);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TElAWSS3DataStorageListState(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers);

		TElAWSS3DataStorageListState(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElAWSS3DataStorageListState(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers);

		TElAWSS3DataStorageListState(const std::string &BucketName, const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

};
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT
class TElAWSS3AccessControlGrant: public TObject
{
	private:
		SB_DISABLE_COPY(TElAWSS3AccessControlGrant)
	public:
		void Reset();

		void SaveToXML(std::string &OutResult);

		void LoadFromXML(const std::string &Xml);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromXML(TStream &XmlStream);

		void LoadFromXML(TStream *XmlStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		void LoadFromXML(TElXMLDOMElement &Elem);

		void LoadFromXML(TElXMLDOMElement *Elem);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual TSBAWSS3AccessControlGranteeType get_GranteeType();

		virtual void set_GranteeType(TSBAWSS3AccessControlGranteeType Value);

		SB_DECLARE_PROPERTY(TSBAWSS3AccessControlGranteeType, get_GranteeType, set_GranteeType, TElAWSS3AccessControlGrant, GranteeType);

		virtual void get_UserID(std::string &OutResult);

		virtual void set_UserID(const std::string &Value);

		virtual void get_UserDisplayName(std::string &OutResult);

		virtual void set_UserDisplayName(const std::string &Value);

		virtual void get_GroupURI(std::string &OutResult);

		virtual void set_GroupURI(const std::string &Value);

		virtual void get_Email(std::string &OutResult);

		virtual void set_Email(const std::string &Value);

		virtual TSBAWSS3AccessControlPermission get_Permission();

		virtual void set_Permission(TSBAWSS3AccessControlPermission Value);

		SB_DECLARE_PROPERTY(TSBAWSS3AccessControlPermission, get_Permission, set_Permission, TElAWSS3AccessControlGrant, Permission);

		virtual void get_CustomPermission(std::string &OutResult);

		virtual void set_CustomPermission(const std::string &Value);

		virtual void get_CustomGrantee(std::string &OutResult);

		virtual void set_CustomGrantee(const std::string &Value);

		TElAWSS3AccessControlGrant(TElAWSS3AccessControlGrantHandle handle, TElOwnHandle ownHandle);

		TElAWSS3AccessControlGrant();

};
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT */

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
class TElAWSS3AccessControlPolicy: public TObject
{
	private:
		SB_DISABLE_COPY(TElAWSS3AccessControlPolicy)
#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT
		TElAWSS3AccessControlGrant* _Inst_Grants;
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT */

		void initInstances();

	public:
		int32_t AddGrant();

		void RemoveGrant(int32_t Index);

		void ClearGrants();

		void SaveToXML(std::string &OutResult);

		void LoadFromXML(const std::string &Xml);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromXML(TStream &XmlStream);

		void LoadFromXML(TStream *XmlStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Reset();

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT
		virtual TElAWSS3AccessControlGrant* get_Grants(int32_t Index);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLGRANT */

		virtual int32_t get_GrantCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_GrantCount, TElAWSS3AccessControlPolicy, GrantCount);

		virtual void get_OwnerID(std::string &OutResult);

		virtual void set_OwnerID(const std::string &Value);

		virtual void get_OwnerDisplayName(std::string &OutResult);

		virtual void set_OwnerDisplayName(const std::string &Value);

		TElAWSS3AccessControlPolicy(TElAWSS3AccessControlPolicyHandle handle, TElOwnHandle ownHandle);

		TElAWSS3AccessControlPolicy();

		virtual ~TElAWSS3AccessControlPolicy();

};
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
class TElAWSS3DataStorageBucket: public TObject
{
	private:
		SB_DISABLE_COPY(TElAWSS3DataStorageBucket)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		TElAWSS3DataStorageObjectHandle AcquireObject(const std::string &Key);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

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

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
		TElAWSS3DataStorageListStateHandle ListInit();
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TSTRINGLIST
		TElAWSS3DataStorageListStateHandle ListInit(const std::string &Prefix, const std::string &Delimiter, TStringList &Prefixes, TStringList &Headers);

		TElAWSS3DataStorageListStateHandle ListInit(const std::string &Prefix, const std::string &Delimiter, TStringList *Prefixes, TStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELSTRINGLIST
		TElAWSS3DataStorageListStateHandle ListInit(const std::string &Prefix, const std::string &Delimiter, TElStringList &Prefixes, TElStringList &Headers);

		TElAWSS3DataStorageListStateHandle ListInit(const std::string &Prefix, const std::string &Delimiter, TElStringList *Prefixes, TElStringList *Headers);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST
		void ListNext(TElAWSS3DataStorageListState &State, TElDataStorageObjectList &Objects);

		void ListNext(TElAWSS3DataStorageListState *State, TElDataStorageObjectList *Objects);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST
		void ListNext(TElAWSS3DataStorageListState &State, TElDataStorageObjectList &Objects, int32_t MaxCount);

		void ListNext(TElAWSS3DataStorageListState *State, TElDataStorageObjectList *Objects, int32_t MaxCount);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGELISTSTATE_AND_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE
		void ListFinal(TElAWSS3DataStorageListState &State);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGELISTSTATE */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST
		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		TElAWSS3DataStorageObjectHandle CreateObject(const std::string &ObjName, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELAWSS3DATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST */
#endif

		void DeleteObject(const std::string &Key);

		bool ObjectExists(const std::string &Key);

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &Key, TStream &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Key, TStream *Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST
		void WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM
		void WriteObject(const std::string &Key, TStream &Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList &Metadata, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &Key, TStream *Data, const std::string &ContentType, const std::string &ContentDisposition, const std::string &ContentEncoding, const std::string &StorageClass, TElStringList *Metadata, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Key, TStream &Strm);

		void ReadObject(const std::string &Key, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);

		void ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadObject(const std::string &Key, TStream &Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadObject(const std::string &Key, TStream *Strm, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read);

		void ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);

		void ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);

		void ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		void ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		void ReadBlock(const std::string &Key, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList &Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);

		void ReadBlock(const std::string &Key, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, TElStringList *Metadata, std::string &ObjContentType, std::string &ObjContentDisposition, std::string &ObjContentEncoding, std::string &ObjETag);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler &NewHandler);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TElCustomDataStorageSecurityHandler *NewHandler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST
		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList &Metadata);

		TElCustomDataStorageObjectHandle CopyObject(const std::string &SourceKey, const std::string &DestBucketName, const std::string &DestKey, TSBAWSS3ReadObjectCondition Condition, int64_t DateTime, const std::string &ETag, const std::string &StorageClass, bool PreserveMetadata, TElStringList *Metadata);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELSTRINGLIST */
#endif

		void GetObjectACL(const std::string &Key, std::string &OutResult);

		void SetObjectACL(const std::string &Key, const std::string &ACL);

		void GetRemoteETag(const std::string &Key, std::string &OutResult);

		void Delete();

		bool Exists();

		void GetLocation(std::string &OutResult);

		void GetACL(std::string &OutResult);

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
		void GetACL(TElAWSS3AccessControlPolicy &Policy);

		void GetACL(TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

		void SetACL(const std::string &ACL);

#ifdef SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY
		void SetACL(TElAWSS3AccessControlPolicy &Policy);

		void SetACL(TElAWSS3AccessControlPolicy *Policy);
#endif /* SB_USE_CLASS_TELAWSS3ACCESSCONTROLPOLICY */

		void GetPolicy(std::string &OutResult);

		void SetPolicy(const std::string &Policy);

		void DeletePolicy();

		void SetPaymentConfiguration(const std::string &PaymentConfig);

		void SetPaymentConfiguration(bool RequesterPays);

		void GetPaymentConfiguration(std::string &OutResult);

		bool IsRequesterPaysBucket();

		TSBAWSS3BucketVersioning GetVersioning();

		void SetVersioning(TSBAWSS3BucketVersioning Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetNotificationConfiguration(TStringList &Topics, TStringList &Events);

		void GetNotificationConfiguration(TStringList *Topics, TStringList *Events);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetNotificationConfiguration(TElStringList &Topics, TElStringList &Events);

		void GetNotificationConfiguration(TElStringList *Topics, TElStringList *Events);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetNotificationConfiguration(TStringList &Topics, TStringList &Events);

		void SetNotificationConfiguration(TStringList *Topics, TStringList *Events);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetNotificationConfiguration(TElStringList &Topics, TElStringList &Events);

		void SetNotificationConfiguration(TElStringList *Topics, TElStringList *Events);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void GetWebSiteConfiguration(std::string &IndexDocument, std::string &ErrorDocument);

		void SetWebSiteConfiguration(const std::string &IndexDocument, const std::string &ErrorDocument);

		void DeleteWebSiteConfiguration();

		virtual void get_Name(std::string &OutResult);

		virtual int64_t get_CreationDate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CreationDate, TElAWSS3DataStorageBucket, CreationDate);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_CustomHeaders, TElAWSS3DataStorageBucket, CustomHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_CustomHeaders, TElAWSS3DataStorageBucket, CustomHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElAWSS3DataStorageBucket(TElAWSS3DataStorageBucketHandle handle, TElOwnHandle ownHandle);

		TElAWSS3DataStorageBucket();

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
		explicit TElAWSS3DataStorageBucket(TElAWSS3DataStorage &Storage);

		explicit TElAWSS3DataStorageBucket(TElAWSS3DataStorage *Storage);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

		virtual ~TElAWSS3DataStorageBucket();

};
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST
class TElAWSS3DataStorageBucketList: public TObject
{
	private:
		SB_DISABLE_COPY(TElAWSS3DataStorageBucketList)
#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		TElAWSS3DataStorageBucket* _Inst_Buckets;
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET
		virtual TElAWSS3DataStorageBucket* get_Buckets(int32_t Index);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKET */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElAWSS3DataStorageBucketList, Count);

		virtual void get_OwnerID(std::string &OutResult);

		virtual void get_OwnerDisplayName(std::string &OutResult);

		TElAWSS3DataStorageBucketList(TElAWSS3DataStorageBucketListHandle handle, TElOwnHandle ownHandle);

		TElAWSS3DataStorageBucketList();

#ifdef SB_USE_CLASS_TELAWSS3DATASTORAGE
		explicit TElAWSS3DataStorageBucketList(TElAWSS3DataStorage &Storage);

		explicit TElAWSS3DataStorageBucketList(TElAWSS3DataStorage *Storage);
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGE */

		virtual ~TElAWSS3DataStorageBucketList();

};
#endif /* SB_USE_CLASS_TELAWSS3DATASTORAGEBUCKETLIST */

#ifdef SB_USE_GLOBAL_PROCS_AWSDATASTORAGE

#ifdef SB_USE_CLASS_TELXMLDOMNODE
void GetNodeInnerXML(TElXMLDOMNode &XmlNode, std::string &OutResult);
void GetNodeInnerXML(TElXMLDOMNode *XmlNode, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#endif /* SB_USE_GLOBAL_PROCS_AWSDATASTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_AWSDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY SBAWSDataStorage_GetNodeInnerXML(TElXMLDOMNodeHandle XmlNode, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_AWSDATASTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBAWSDATASTORAGE */
