#ifndef __INC_SBHTTPSCOMMON
#define __INC_SBHTTPSCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbzcommonunit.h"
#include "sbzuncompressunit.h"
#include "sbzcompressunit.h"
#include "sbzlib.h"
#include "sbcrc.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbstringlist.h"
#include "sbstreams.h"
#include "sbhttpsconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SCannotParseGZHeader 	"Invalid GZIP header."
#define SB_SCannotInflateCompressedData 	"Cannot inflate compressed data."
#define SB_ERROR_FACILITY_HTTP 	98304
#define SB_ERROR_HTTP_PROTOCOL_ERROR_FLAG 	2048
#define SB_HTTP_ERROR_CONNECT_FAILED 	100353
#define SB_HTTP_ERROR_REQUEST_NOT_COMPLETED 	100354
#define SB_HTTP_ERROR_INVALID_PROTOCOL_IN_URI 	100355
#define SB_HTTP_ERROR_DATETIME_PARSING_ERROR 	100356
#define SB_HTTP_ERROR_COMPRESSION_ERROR 	100357
#define SB_HTTP_ERROR_AUTH_FAILURE 	100358
#define SB_HTTP_ERROR_CANT_PARSE_RESPONSE 	100359
#define SB_HTTP_ERROR_CANT_PARSE_REQUEST 	100360
#define SB_HTTP_ERROR_UNKNOWN_TRANSFER_ENCODING 	100361
#define SB_HTTP_ERROR_TRANSFER_DECODING 	100362
#define SB_HEAD_CRC 	2
#define SB_EXTRA_FIELD 	4
#define SB_ORIG_NAME 	8
#define SB_COMMENT 	16
#define SB_RESERVED 	224

typedef TElClassHandle TElHTTPSClientParamsHandle;

typedef TElClassHandle TElCustomSAMLAdapterHandle;

typedef TElClassHandle TElHTTPRangesHandle;

typedef TElClassHandle TElHTTPParamsHandle;

typedef TElHTTPParamsHandle ElHTTPParamsHandle;

typedef TElClassHandle TElHTTPCustomRequestParamsHandle;

typedef TElHTTPCustomRequestParamsHandle ElHTTPCustomRequestParamsHandle;

typedef TElClassHandle TElHTTPMultipartPartHandle;

typedef TElClassHandle TElHTTPMultipartListHandle;

typedef TElClassHandle TElHTTPEncodingProcessorHandle;

typedef TElClassHandle TElHTTPChunkedProcessorHandle;

typedef TElClassHandle TElHTTPCompressedProcessorHandle;

typedef TElClassHandle TElHTTPUtilsHandle;

typedef uint8_t TGZHeaderSkippedRaw;

typedef enum
{
	gzNone = 0,
	gzMagic = 1,
	gzMethod = 2,
	gzFlags = 3,
	gzTimeXFlagsOSCode = 4,
	gzExtra = 5,
	gzFileName = 6,
	gzFileComment = 7,
	gzCRC = 8,
	gzAll = 9
} TGZHeaderSkipped;

typedef uint8_t SBHTTPSCommon_TSBHTTPChunkStateRaw;

typedef enum
{
	_chSize = 0,
	_chLineFeed = 1,
	_chData = 2,
	_chHeader = 3
} SBHTTPSCommon_TSBHTTPChunkState;

typedef uint8_t TSBHTTPMethodRaw;

typedef enum
{
	hmGet = 0,
	hmPost = 1,
	hmHead = 2,
	hmOptions = 3,
	hmDelete = 4,
	hmTrace = 5,
	hmPut = 6,
	hmConnect = 7,
	hmCustom = 8
} TSBHTTPMethod;

typedef uint8_t TSBHTTPMultipartModeRaw;

typedef enum
{
	hmpFormData = 0,
	hmpRelated = 1,
	hmpCustom = 2
} TSBHTTPMultipartMode;

#ifdef SB_WINDOWS
typedef void (SB_CALLBACK *TSBHTTPHeadersEvent)(void * _ObjectData, TObjectHandle Sender, TStringListHandle Headers);
#else
typedef void (SB_CALLBACK *TSBHTTPHeadersEvent)(void * _ObjectData, TObjectHandle Sender, TElStringListHandle Headers);
#endif

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_DoReconnect(TElHTTPSClientParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_DoReconnect(TElHTTPSClientParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_IntoDataRedirection(TElHTTPSClientParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_IntoDataRedirection(TElHTTPSClientParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_RelocationURL(TElHTTPSClientParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_RelocationURL(TElHTTPSClientParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_RequestMethod(TElHTTPSClientParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_RequestMethod(TElHTTPSClientParamsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_ContentLength(TElHTTPSClientParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_ContentLength(TElHTTPSClientParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_ContentType(TElHTTPSClientParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_ContentType(TElHTTPSClientParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_SentStreams(TElHTTPSClientParamsHandle _Handle, TSBObjectListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_SentStreams(TElHTTPSClientParamsHandle _Handle, TSBObjectListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_DataStreams(TElHTTPSClientParamsHandle _Handle, TSBObjectListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_DataStreams(TElHTTPSClientParamsHandle _Handle, TSBObjectListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_AllowRedirection(TElHTTPSClientParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_AllowRedirection(TElHTTPSClientParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_NewURL(TElHTTPSClientParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_NewURL(TElHTTPSClientParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_ServerStatusCode(TElHTTPSClientParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_ServerStatusCode(TElHTTPSClientParamsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_get_URL(TElHTTPSClientParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_set_URL(TElHTTPSClientParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClientParams_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELCUSTOMSAMLADAPTER
SB_IMPORT uint32_t SB_APIENTRY TElCustomSAMLAdapter_HandleDocumentEnd(TElCustomSAMLAdapterHandle _Handle, TElHTTPSClientParamsHandle Param);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSAMLAdapter_HandlePerformExchange(TElCustomSAMLAdapterHandle _Handle, TElHTTPSClientParamsHandle Param);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSAMLAdapter_HandleRedirection(TElCustomSAMLAdapterHandle _Handle, TElHTTPSClientParamsHandle Param);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSAMLAdapter_HandleReadyData(TElCustomSAMLAdapterHandle _Handle, const uint8_t pBuf[], int32_t szBuf);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSAMLAdapter_Reset(TElCustomSAMLAdapterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSAMLAdapter_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSAMLADAPTER */

#ifdef SB_USE_CLASS_TELHTTPRANGES
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_Assign(TElHTTPRangesHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_Clone(TElHTTPRangesHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_get_RangeCount(TElHTTPRangesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_set_RangeCount(TElHTTPRangesHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_get_RangeEnd(TElHTTPRangesHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_set_RangeEnd(TElHTTPRangesHandle _Handle, int32_t Index, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_get_RangeStart(TElHTTPRangesHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_set_RangeStart(TElHTTPRangesHandle _Handle, int32_t Index, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRanges_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPRANGES */

#ifdef SB_USE_CLASS_TELHTTPPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_Assign(TElHTTPParamsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_Clone(TElHTTPParamsHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_ContentLength(TElHTTPParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_set_ContentLength(TElHTTPParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_ContentRangeStart(TElHTTPParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_set_ContentRangeStart(TElHTTPParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_ContentRangeEnd(TElHTTPParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_set_ContentRangeEnd(TElHTTPParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_ContentRangeFullSize(TElHTTPParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_set_ContentRangeFullSize(TElHTTPParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_ContentType(TElHTTPParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_set_ContentType(TElHTTPParamsHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_Cookies(TElHTTPParamsHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_CustomHeaders(TElHTTPParamsHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_Cookies(TElHTTPParamsHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_CustomHeaders(TElHTTPParamsHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_get_Date(TElHTTPParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_set_Date(TElHTTPParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPParams_Create(TElHTTPParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPPARAMS */

#ifdef SB_USE_CLASS_TELHTTPCUSTOMREQUESTPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_Assign(TElHTTPCustomRequestParamsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_Clone(TElHTTPCustomRequestParamsHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_Accept(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_Accept(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_AcceptCharset(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_AcceptCharset(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_AcceptLanguage(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_AcceptLanguage(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_AcceptRanges(TElHTTPCustomRequestParamsHandle _Handle, TElHTTPRangesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_Authorization(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_Authorization(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_Connection(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_Connection(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_IfMatch(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_IfMatch(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_IfModifiedSince(TElHTTPCustomRequestParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_IfModifiedSince(TElHTTPCustomRequestParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_IfNoneMatch(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_IfNoneMatch(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_IfUnmodifiedSince(TElHTTPCustomRequestParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_IfUnmodifiedSince(TElHTTPCustomRequestParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_From(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_From(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_Username(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_Username(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_Password(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_Password(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_Referer(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_Referer(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_UserAgent(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_UserAgent(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_get_Host(TElHTTPCustomRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_set_Host(TElHTTPCustomRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCustomRequestParams_Create(TElHTTPCustomRequestParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPCUSTOMREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_ContentType(TElHTTPMultipartPartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_ContentType(TElHTTPMultipartPartHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_ContentTransferEncoding(TElHTTPMultipartPartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_ContentTransferEncoding(TElHTTPMultipartPartHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_CustomHeaders(TElHTTPMultipartPartHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_CustomHeaders(TElHTTPMultipartPartHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_Stream(TElHTTPMultipartPartHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_Stream(TElHTTPMultipartPartHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_CloseStream(TElHTTPMultipartPartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_CloseStream(TElHTTPMultipartPartHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_FieldName(TElHTTPMultipartPartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_FieldName(TElHTTPMultipartPartHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_FieldValue(TElHTTPMultipartPartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_FieldValue(TElHTTPMultipartPartHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_Filename(TElHTTPMultipartPartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_Filename(TElHTTPMultipartPartHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_ContentID(TElHTTPMultipartPartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_ContentID(TElHTTPMultipartPartHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_ContentDescription(TElHTTPMultipartPartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_ContentDescription(TElHTTPMultipartPartHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_get_ContentDisposition(TElHTTPMultipartPartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_set_ContentDisposition(TElHTTPMultipartPartHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartPart_Create(TElHTTPMultipartPartHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_AddFormField(TElHTTPMultipartListHandle _Handle, const char * pcFieldName, int32_t szFieldName, const char * pcFieldValue, int32_t szFieldValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_AddFormFile(TElHTTPMultipartListHandle _Handle, const char * pcFieldName, int32_t szFieldName, const char * pcFilename, int32_t szFilename, const char * pcContentType, int32_t szContentType, TStreamHandle FileStream, int8_t CloseStream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_AddContentStream(TElHTTPMultipartListHandle _Handle, const char * pcContentID, int32_t szContentID, const char * pcContentType, int32_t szContentType, TStreamHandle AStream, int8_t CloseStream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_Add(TElHTTPMultipartListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_Add_1(TElHTTPMultipartListHandle _Handle, TElHTTPMultipartPartHandle APart, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_Insert(TElHTTPMultipartListHandle _Handle, int32_t Index, TElHTTPMultipartPartHandle APart);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_Delete(TElHTTPMultipartListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_Clear(TElHTTPMultipartListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_get_Count(TElHTTPMultipartListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_get_Parts(TElHTTPMultipartListHandle _Handle, int32_t Index, TElHTTPMultipartPartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPMultipartList_Create(TElHTTPMultipartListHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPENCODINGPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElHTTPEncodingProcessor_Initialize(TElHTTPEncodingProcessorHandle _Handle, int8_t AsEncoder);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPEncodingProcessor_DecodeData(TElHTTPEncodingProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, int32_t * Processed, int8_t * EndReached, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPEncodingProcessor_EncodeData(TElHTTPEncodingProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPEncodingProcessor_get_BytesEncoded(TElHTTPEncodingProcessorHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPEncodingProcessor_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPENCODINGPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPCHUNKEDPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElHTTPChunkedProcessor_Initialize(TElHTTPChunkedProcessorHandle _Handle, int8_t AsEncoder);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPChunkedProcessor_DecodeData(TElHTTPChunkedProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, int32_t * Processed, int8_t * EndReached, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPChunkedProcessor_EncodeData(TElHTTPChunkedProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPChunkedProcessor_EncodeLastData(TElHTTPChunkedProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPChunkedProcessor_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPCHUNKEDPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPCOMPRESSEDPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_Initialize(TElHTTPCompressedProcessorHandle _Handle, int8_t AsEncoder);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_Reset(TElHTTPCompressedProcessorHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_DecodeData(TElHTTPCompressedProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, int32_t * Processed, int8_t * EndReached, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_EncodeData(TElHTTPCompressedProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_get_Deflated(TElHTTPCompressedProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_set_Deflated(TElHTTPCompressedProcessorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_get_Gzipped(TElHTTPCompressedProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_set_Gzipped(TElHTTPCompressedProcessorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_get_CompressionLevel(TElHTTPCompressedProcessorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_set_CompressionLevel(TElHTTPCompressedProcessorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPCompressedProcessor_Create(TElHTTPCompressedProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPCOMPRESSEDPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPUTILS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_DateTimeToHTTPTime(int64_t D, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_DateTimeToHTTPTime_1(TElHTTPUtilsHandle _Handle, int64_t D, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_HTTPTimeToDateTime(const char * pcS, int32_t szS, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_HTTPTimeToDateTime_1(TElHTTPUtilsHandle _Handle, const char * pcS, int32_t szS, int64_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_SetHeaderByName(TStringListHandle Headers, const char * pcHeader, int32_t szHeader, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_SetHeaderByName_1(TElHTTPUtilsHandle _Handle, TStringListHandle Headers, const char * pcHeader, int32_t szHeader, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_GetHeaderByName(TStringListHandle Headers, const char * pcHeader, int32_t szHeader, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_GetHeaderByName_1(TElHTTPUtilsHandle _Handle, TStringListHandle Headers, const char * pcHeader, int32_t szHeader, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_MergeHeaders(TStringListHandle Source, TStringListHandle Target);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_MergeHeaders_1(TElHTTPUtilsHandle _Handle, TStringListHandle Source, TStringListHandle Target);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_SetHeaderByName(TElStringListHandle Headers, const char * pcHeader, int32_t szHeader, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_SetHeaderByName_1(TElHTTPUtilsHandle _Handle, TElStringListHandle Headers, const char * pcHeader, int32_t szHeader, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_GetHeaderByName(TElStringListHandle Headers, const char * pcHeader, int32_t szHeader, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_GetHeaderByName_1(TElHTTPUtilsHandle _Handle, TElStringListHandle Headers, const char * pcHeader, int32_t szHeader, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_MergeHeaders(TElStringListHandle Source, TElStringListHandle Target);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_MergeHeaders_1(TElHTTPUtilsHandle _Handle, TElStringListHandle Source, TElStringListHandle Target);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPUtils_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHTTPSClientParams;
class TElCustomSAMLAdapter;
class TElHTTPRanges;
class TElHTTPParams;
typedef TElHTTPParams ElHTTPParams;
class TElHTTPCustomRequestParams;
typedef TElHTTPCustomRequestParams ElHTTPCustomRequestParams;
class TElHTTPMultipartPart;
class TElHTTPMultipartList;
class TElHTTPEncodingProcessor;
class TElHTTPChunkedProcessor;
class TElHTTPCompressedProcessor;
class TElHTTPUtils;

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
class TElHTTPSClientParams: public TObject
{
	private:
		SB_DISABLE_COPY(TElHTTPSClientParams)
#ifdef SB_USE_CLASS_TSBOBJECTLIST
		TSBObjectList* _Inst_SentStreams;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
#ifdef SB_USE_CLASS_TSBOBJECTLIST
		TSBObjectList* _Inst_DataStreams;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

		void initInstances();

	public:
		virtual bool get_DoReconnect();

		virtual void set_DoReconnect(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DoReconnect, set_DoReconnect, TElHTTPSClientParams, DoReconnect);

		virtual bool get_IntoDataRedirection();

		virtual void set_IntoDataRedirection(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IntoDataRedirection, set_IntoDataRedirection, TElHTTPSClientParams, IntoDataRedirection);

		virtual void get_RelocationURL(std::string &OutResult);

		virtual void set_RelocationURL(const std::string &Value);

		virtual int32_t get_RequestMethod();

		virtual void set_RequestMethod(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RequestMethod, set_RequestMethod, TElHTTPSClientParams, RequestMethod);

		virtual int64_t get_ContentLength();

		virtual void set_ContentLength(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ContentLength, set_ContentLength, TElHTTPSClientParams, ContentLength);

		virtual void get_ContentType(std::string &OutResult);

		virtual void set_ContentType(const std::string &Value);

#ifdef SB_USE_CLASS_TSBOBJECTLIST
		virtual TSBObjectList* get_SentStreams();

		virtual void set_SentStreams(TSBObjectList &Value);

		virtual void set_SentStreams(TSBObjectList *Value);

		SB_DECLARE_PROPERTY(TSBObjectList*, get_SentStreams, set_SentStreams, TElHTTPSClientParams, SentStreams);
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

#ifdef SB_USE_CLASS_TSBOBJECTLIST
		virtual TSBObjectList* get_DataStreams();

		virtual void set_DataStreams(TSBObjectList &Value);

		virtual void set_DataStreams(TSBObjectList *Value);

		SB_DECLARE_PROPERTY(TSBObjectList*, get_DataStreams, set_DataStreams, TElHTTPSClientParams, DataStreams);
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

		virtual bool get_AllowRedirection();

		virtual void set_AllowRedirection(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowRedirection, set_AllowRedirection, TElHTTPSClientParams, AllowRedirection);

		virtual void get_NewURL(std::string &OutResult);

		virtual void set_NewURL(const std::string &Value);

		virtual int32_t get_ServerStatusCode();

		virtual void set_ServerStatusCode(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ServerStatusCode, set_ServerStatusCode, TElHTTPSClientParams, ServerStatusCode);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		TElHTTPSClientParams(TElHTTPSClientParamsHandle handle, TElOwnHandle ownHandle);

		TElHTTPSClientParams();

		virtual ~TElHTTPSClientParams();

};
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELCUSTOMSAMLADAPTER
class TElCustomSAMLAdapter: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomSAMLAdapter)
	public:
#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
		virtual void HandleDocumentEnd(TElHTTPSClientParams &Param);

		virtual void HandleDocumentEnd(TElHTTPSClientParams *Param);
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
		virtual void HandlePerformExchange(TElHTTPSClientParams &Param);

		virtual void HandlePerformExchange(TElHTTPSClientParams *Param);
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
		virtual void HandleRedirection(TElHTTPSClientParams &Param);

		virtual void HandleRedirection(TElHTTPSClientParams *Param);
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

		virtual void HandleReadyData(const std::vector<uint8_t> &Buf);

		virtual void Reset();

		TElCustomSAMLAdapter(TElCustomSAMLAdapterHandle handle, TElOwnHandle ownHandle);

		TElCustomSAMLAdapter();

};
#endif /* SB_USE_CLASS_TELCUSTOMSAMLADAPTER */

#ifdef SB_USE_CLASS_TELHTTPRANGES
class TElHTTPRanges: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElHTTPRanges)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		TObjectHandle Clone();

		virtual int32_t get_RangeCount();

		virtual void set_RangeCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RangeCount, set_RangeCount, TElHTTPRanges, RangeCount);

		virtual int64_t get_RangeEnd(int32_t Index);

		virtual void set_RangeEnd(int32_t Index, int64_t Value);

		virtual int64_t get_RangeStart(int32_t Index);

		virtual void set_RangeStart(int32_t Index, int64_t Value);

		TElHTTPRanges(TElHTTPRangesHandle handle, TElOwnHandle ownHandle);

		TElHTTPRanges();

};
#endif /* SB_USE_CLASS_TELHTTPRANGES */

#ifdef SB_USE_CLASS_TELHTTPPARAMS
class TElHTTPParams: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElHTTPParams)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Cookies;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Cookies;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TObjectHandle Clone();

		virtual int64_t get_ContentLength();

		virtual void set_ContentLength(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ContentLength, set_ContentLength, TElHTTPParams, ContentLength);

		virtual int64_t get_ContentRangeStart();

		virtual void set_ContentRangeStart(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ContentRangeStart, set_ContentRangeStart, TElHTTPParams, ContentRangeStart);

		virtual int64_t get_ContentRangeEnd();

		virtual void set_ContentRangeEnd(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ContentRangeEnd, set_ContentRangeEnd, TElHTTPParams, ContentRangeEnd);

		virtual int64_t get_ContentRangeFullSize();

		virtual void set_ContentRangeFullSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ContentRangeFullSize, set_ContentRangeFullSize, TElHTTPParams, ContentRangeFullSize);

		virtual void get_ContentType(std::string &OutResult);

		virtual void set_ContentType(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Cookies();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Cookies, TElHTTPParams, Cookies);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Cookies();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Cookies, TElHTTPParams, Cookies);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_CustomHeaders, TElHTTPParams, CustomHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_CustomHeaders, TElHTTPParams, CustomHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual int64_t get_Date();

		virtual void set_Date(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Date, set_Date, TElHTTPParams, Date);

		TElHTTPParams(TElHTTPParamsHandle handle, TElOwnHandle ownHandle);

		TElHTTPParams();

		virtual ~TElHTTPParams();

};
#endif /* SB_USE_CLASS_TELHTTPPARAMS */

#ifdef SB_USE_CLASS_TELHTTPCUSTOMREQUESTPARAMS
class TElHTTPCustomRequestParams: public TElHTTPParams
{
	private:
		SB_DISABLE_COPY(TElHTTPCustomRequestParams)
#ifdef SB_USE_CLASS_TELHTTPRANGES
		TElHTTPRanges* _Inst_AcceptRanges;
#endif /* SB_USE_CLASS_TELHTTPRANGES */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TObjectHandle Clone();

		virtual void get_Accept(std::string &OutResult);

		virtual void set_Accept(const std::string &Value);

		virtual void get_AcceptCharset(std::string &OutResult);

		virtual void set_AcceptCharset(const std::string &Value);

		virtual void get_AcceptLanguage(std::string &OutResult);

		virtual void set_AcceptLanguage(const std::string &Value);

#ifdef SB_USE_CLASS_TELHTTPRANGES
		virtual TElHTTPRanges* get_AcceptRanges();

		SB_DECLARE_PROPERTY_GET(TElHTTPRanges*, get_AcceptRanges, TElHTTPCustomRequestParams, AcceptRanges);
#endif /* SB_USE_CLASS_TELHTTPRANGES */

		virtual void get_Authorization(std::string &OutResult);

		virtual void set_Authorization(const std::string &Value);

		virtual void get_Connection(std::string &OutResult);

		virtual void set_Connection(const std::string &Value);

		virtual void get_IfMatch(std::string &OutResult);

		virtual void set_IfMatch(const std::string &Value);

		virtual int64_t get_IfModifiedSince();

		virtual void set_IfModifiedSince(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_IfModifiedSince, set_IfModifiedSince, TElHTTPCustomRequestParams, IfModifiedSince);

		virtual void get_IfNoneMatch(std::string &OutResult);

		virtual void set_IfNoneMatch(const std::string &Value);

		virtual int64_t get_IfUnmodifiedSince();

		virtual void set_IfUnmodifiedSince(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_IfUnmodifiedSince, set_IfUnmodifiedSince, TElHTTPCustomRequestParams, IfUnmodifiedSince);

		virtual void get_From(std::string &OutResult);

		virtual void set_From(const std::string &Value);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_Referer(std::string &OutResult);

		virtual void set_Referer(const std::string &Value);

		virtual void get_UserAgent(std::string &OutResult);

		virtual void set_UserAgent(const std::string &Value);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		TElHTTPCustomRequestParams(TElHTTPCustomRequestParamsHandle handle, TElOwnHandle ownHandle);

		TElHTTPCustomRequestParams();

		virtual ~TElHTTPCustomRequestParams();

};
#endif /* SB_USE_CLASS_TELHTTPCUSTOMREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
class TElHTTPMultipartPart: public TObject
{
	private:
		SB_DISABLE_COPY(TElHTTPMultipartPart)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_Stream;
#endif /* SB_USE_CLASS_TSTREAM */

		void initInstances();

	public:
		virtual void get_ContentType(std::string &OutResult);

		virtual void set_ContentType(const std::string &Value);

		virtual void get_ContentTransferEncoding(std::string &OutResult);

		virtual void set_ContentTransferEncoding(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_CustomHeaders, TElHTTPMultipartPart, CustomHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CustomHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_CustomHeaders, TElHTTPMultipartPart, CustomHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_Stream();

		virtual void set_Stream(TStream &Value);

		virtual void set_Stream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_Stream, set_Stream, TElHTTPMultipartPart, Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool get_CloseStream();

		virtual void set_CloseStream(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CloseStream, set_CloseStream, TElHTTPMultipartPart, CloseStream);

		virtual void get_FieldName(std::string &OutResult);

		virtual void set_FieldName(const std::string &Value);

		virtual void get_FieldValue(std::string &OutResult);

		virtual void set_FieldValue(const std::string &Value);

		virtual void get_Filename(std::string &OutResult);

		virtual void set_Filename(const std::string &Value);

		virtual void get_ContentID(std::string &OutResult);

		virtual void set_ContentID(const std::string &Value);

		virtual void get_ContentDescription(std::string &OutResult);

		virtual void set_ContentDescription(const std::string &Value);

		virtual void get_ContentDisposition(std::string &OutResult);

		virtual void set_ContentDisposition(const std::string &Value);

		TElHTTPMultipartPart(TElHTTPMultipartPartHandle handle, TElOwnHandle ownHandle);

		TElHTTPMultipartPart();

		virtual ~TElHTTPMultipartPart();

};
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
class TElHTTPMultipartList: public TObject
{
	private:
		SB_DISABLE_COPY(TElHTTPMultipartList)
#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
		TElHTTPMultipartPart* _Inst_Parts;
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

		void initInstances();

	public:
		int32_t AddFormField(const std::string &FieldName, const std::string &FieldValue);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t AddFormFile(const std::string &FieldName, const std::string &Filename, const std::string &ContentType, TStream &FileStream, bool CloseStream);

		int32_t AddFormFile(const std::string &FieldName, const std::string &Filename, const std::string &ContentType, TStream *FileStream, bool CloseStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t AddContentStream(const std::string &ContentID, const std::string &ContentType, TStream &AStream, bool CloseStream);

		int32_t AddContentStream(const std::string &ContentID, const std::string &ContentType, TStream *AStream, bool CloseStream);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t Add();

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
		int32_t Add(TElHTTPMultipartPart &APart);

		int32_t Add(TElHTTPMultipartPart *APart);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
		void Insert(int32_t Index, TElHTTPMultipartPart &APart);

		void Insert(int32_t Index, TElHTTPMultipartPart *APart);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElHTTPMultipartList, Count);

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTPART
		virtual TElHTTPMultipartPart* get_Parts(int32_t Index);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTPART */

		TElHTTPMultipartList(TElHTTPMultipartListHandle handle, TElOwnHandle ownHandle);

		TElHTTPMultipartList();

		virtual ~TElHTTPMultipartList();

};
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPENCODINGPROCESSOR
class TElHTTPEncodingProcessor: public TObject
{
	private:
		SB_DISABLE_COPY(TElHTTPEncodingProcessor)
	public:
		virtual void Initialize(bool AsEncoder);

		virtual void DecodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, int32_t &Processed, bool &EndReached, std::vector<uint8_t> &OutResult);

		virtual void EncodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult);

		virtual int64_t get_BytesEncoded();

		SB_DECLARE_PROPERTY_GET(int64_t, get_BytesEncoded, TElHTTPEncodingProcessor, BytesEncoded);

		TElHTTPEncodingProcessor(TElHTTPEncodingProcessorHandle handle, TElOwnHandle ownHandle);

		TElHTTPEncodingProcessor();

};
#endif /* SB_USE_CLASS_TELHTTPENCODINGPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPCHUNKEDPROCESSOR
class TElHTTPChunkedProcessor: public TElHTTPEncodingProcessor
{
	private:
		SB_DISABLE_COPY(TElHTTPChunkedProcessor)
	public:
		virtual void Initialize(bool AsEncoder);

		virtual void DecodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, int32_t &Processed, bool &EndReached, std::vector<uint8_t> &OutResult);

		virtual void EncodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult);

		void EncodeLastData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult);

		TElHTTPChunkedProcessor(TElHTTPChunkedProcessorHandle handle, TElOwnHandle ownHandle);

		TElHTTPChunkedProcessor();

};
#endif /* SB_USE_CLASS_TELHTTPCHUNKEDPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPCOMPRESSEDPROCESSOR
class TElHTTPCompressedProcessor: public TElHTTPEncodingProcessor
{
	private:
		SB_DISABLE_COPY(TElHTTPCompressedProcessor)
	public:
		virtual void Initialize(bool AsEncoder);

		void Reset();

		virtual void DecodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, int32_t &Processed, bool &EndReached, std::vector<uint8_t> &OutResult);

		virtual void EncodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult);

		virtual bool get_Deflated();

		virtual void set_Deflated(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Deflated, set_Deflated, TElHTTPCompressedProcessor, Deflated);

		virtual bool get_Gzipped();

		virtual void set_Gzipped(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Gzipped, set_Gzipped, TElHTTPCompressedProcessor, Gzipped);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElHTTPCompressedProcessor, CompressionLevel);

		TElHTTPCompressedProcessor(TElHTTPCompressedProcessorHandle handle, TElOwnHandle ownHandle);

		TElHTTPCompressedProcessor();

};
#endif /* SB_USE_CLASS_TELHTTPCOMPRESSEDPROCESSOR */

#ifdef SB_USE_CLASS_TELHTTPUTILS
class TElHTTPUtils: public TObject
{
	private:
		SB_DISABLE_COPY(TElHTTPUtils)
	public:
		static void DateTimeToHTTPTime(int64_t D, std::string &OutResult);

		void DateTimeToHTTPTime_Inst(int64_t D, std::string &OutResult);

		static int64_t HTTPTimeToDateTime(const std::string &S);

		int64_t HTTPTimeToDateTime_Inst(const std::string &S);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		static void SetHeaderByName(TStringList &Headers, const std::string &Header, const std::string &Value);

		static void SetHeaderByName(TStringList *Headers, const std::string &Header, const std::string &Value);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		static void SetHeaderByName(TElStringList &Headers, const std::string &Header, const std::string &Value);

		static void SetHeaderByName(TElStringList *Headers, const std::string &Header, const std::string &Value);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetHeaderByName_Inst(TStringList &Headers, const std::string &Header, const std::string &Value);

		void SetHeaderByName_Inst(TStringList *Headers, const std::string &Header, const std::string &Value);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetHeaderByName_Inst(TElStringList &Headers, const std::string &Header, const std::string &Value);

		void SetHeaderByName_Inst(TElStringList *Headers, const std::string &Header, const std::string &Value);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		static void GetHeaderByName(TStringList &Headers, const std::string &Header, std::string &OutResult);

		static void GetHeaderByName(TStringList *Headers, const std::string &Header, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		static void GetHeaderByName(TElStringList &Headers, const std::string &Header, std::string &OutResult);

		static void GetHeaderByName(TElStringList *Headers, const std::string &Header, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetHeaderByName_Inst(TStringList &Headers, const std::string &Header, std::string &OutResult);

		void GetHeaderByName_Inst(TStringList *Headers, const std::string &Header, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetHeaderByName_Inst(TElStringList &Headers, const std::string &Header, std::string &OutResult);

		void GetHeaderByName_Inst(TElStringList *Headers, const std::string &Header, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		static void MergeHeaders(TStringList &Source, TStringList &Target);

		static void MergeHeaders(TStringList *Source, TStringList *Target);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		static void MergeHeaders(TElStringList &Source, TElStringList &Target);

		static void MergeHeaders(TElStringList *Source, TElStringList *Target);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void MergeHeaders_Inst(TStringList &Source, TStringList &Target);

		void MergeHeaders_Inst(TStringList *Source, TStringList *Target);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void MergeHeaders_Inst(TElStringList &Source, TElStringList &Target);

		void MergeHeaders_Inst(TElStringList *Source, TElStringList *Target);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElHTTPUtils(TElHTTPUtilsHandle handle, TElOwnHandle ownHandle);

		TElHTTPUtils();

};
#endif /* SB_USE_CLASS_TELHTTPUTILS */

#ifdef SB_USE_GLOBAL_PROCS_HTTPSCOMMON

bool HTTPHeaderGetDelimiter(const std::vector<uint8_t> &Header, int32_t Index, int32_t Length, std::vector<uint8_t> &Delimiter, int32_t &EndHeaderIndex);

#endif /* SB_USE_GLOBAL_PROCS_HTTPSCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_HTTPSCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBHTTPSCommon_HTTPHeaderGetDelimiter(const uint8_t pHeader[], int32_t szHeader, int32_t Index, int32_t Length, uint8_t pDelimiter[], int32_t * szDelimiter, int32_t * EndHeaderIndex, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_HTTPSCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPSCOMMON */
