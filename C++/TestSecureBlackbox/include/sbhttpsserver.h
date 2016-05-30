#ifndef __INC_SBHTTPSSERVER
#define __INC_SBHTTPSSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcustomcertstorage.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrandom.h"
#include "sbencoding.h"
#include "sbx509.h"
#include "sbstringlist.h"
#include "sbconstants.h"
#include "sbsslcommon.h"
#include "sbsslserver.h"
#include "sbsessionpool.h"
#include "sbsslconstants.h"
#include "sbstreams.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbhttpauth.h"
#endif
#include "sbwebsocketcommon.h"
#include "sbwebsocketserver.h"
#include "sbsrp.h"
#include "sbhttpsconstants.h"
#include "sbhashfunction.h"
#include "sbhttpscommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElHTTPServerRequestParamsHandle;

typedef TElHTTPServerRequestParamsHandle ElHTTPServerRequestParamsHandle;

typedef TElClassHandle TElHTTPServerResponseParamsHandle;

typedef TElHTTPServerResponseParamsHandle ElHTTPServerResponseParamsHandle;

typedef TElClassHandle TElMultipartFormDataHandle;

typedef TElMultipartFormDataHandle ElMultipartFormDataHandle;

typedef TElClassHandle TElMultipartFormListHandle;

typedef TElMultipartFormListHandle ElMultipartFormListHandle;

typedef TElClassHandle TElHTTPSServerHandle;

typedef TElHTTPSServerHandle ElHTTPSServerHandle;

typedef TElClassHandle TElDigestAuthHandle;

typedef uint8_t TSBHTTPServerConnStageRaw;

typedef enum
{
	csHeader = 0,
	csBody = 1,
	csTunnel = 2
} TSBHTTPServerConnStage;

typedef void (SB_CALLBACK *TSBHTTPRequestHeadersEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPServerRequestParamsHandle RequestInfo, int8_t * Accepted);

typedef void (SB_CALLBACK *TSBHTTPAfterAuthorizationEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPServerRequestParamsHandle RequestInfo, int8_t * Accepted);

typedef void (SB_CALLBACK *TSBHTTPRequestBodyEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPServerRequestParamsHandle RequestInfo);

typedef void (SB_CALLBACK *TSBHTTPBeforeWebSocketServerUsedEvent)(void * _ObjectData, TObjectHandle Sender, TElWebSocketServerHandle WSServer);

typedef void (SB_CALLBACK *SBHTTPSServer_TSBHTTPWebSocketConnectionEstablishedEvent)(void * _ObjectData, TObjectHandle Sender, TElWebSocketServerHandle WSServer);

typedef void (SB_CALLBACK *TSBOnGetUserPasswordEvent)(void * _ObjectData, TObjectHandle Sender, TElHTTPServerRequestParamsHandle ReqParams, char * pcPassword, int32_t * szPassword, int8_t * Accept);

#ifdef SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_Assign(TElHTTPServerRequestParamsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_Clone(TElHTTPServerRequestParamsHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_CustomMethod(TElHTTPServerRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_set_CustomMethod(TElHTTPServerRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_Expects100Continue(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_set_Expects100Continue(TElHTTPServerRequestParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_HTTPVersion(TElHTTPServerRequestParamsHandle _Handle, TSBHTTPVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_set_HTTPVersion(TElHTTPServerRequestParamsHandle _Handle, TSBHTTPVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_KeepAlive(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_set_KeepAlive(TElHTTPServerRequestParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_Method(TElHTTPServerRequestParamsHandle _Handle, TSBHTTPMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_set_Method(TElHTTPServerRequestParamsHandle _Handle, TSBHTTPMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_URL(TElHTTPServerRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_set_URL(TElHTTPServerRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_Chunked(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_PreferGzip(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_AcceptGZip(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_AcceptDeflate(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_AcceptChunked(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_AcceptIdentity(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_AuthMethod(TElHTTPServerRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_RequireAuth(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_set_RequireAuth(TElHTTPServerRequestParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_get_WebSocketRequest(TElHTTPServerRequestParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerRequestParams_Create(TElHTTPServerRequestParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSERVERRESPONSEPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_Assign(TElHTTPServerResponseParamsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_Clone(TElHTTPServerResponseParamsHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_AcceptRanges(TElHTTPServerResponseParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_AcceptRanges(TElHTTPServerResponseParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_Location(TElHTTPServerResponseParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_Location(TElHTTPServerResponseParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_StatusCode(TElHTTPServerResponseParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_StatusCode(TElHTTPServerResponseParamsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_Expires(TElHTTPServerResponseParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_Expires(TElHTTPServerResponseParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_LastModified(TElHTTPServerResponseParamsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_LastModified(TElHTTPServerResponseParamsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_ReasonPhrase(TElHTTPServerResponseParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_ReasonPhrase(TElHTTPServerResponseParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_Server(TElHTTPServerResponseParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_Server(TElHTTPServerResponseParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_UseChunkedTransfer(TElHTTPServerResponseParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_UseChunkedTransfer(TElHTTPServerResponseParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_UseCompression(TElHTTPServerResponseParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_UseCompression(TElHTTPServerResponseParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_CompressionLevel(TElHTTPServerResponseParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_CompressionLevel(TElHTTPServerResponseParamsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_UseKeepAlive(TElHTTPServerResponseParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_UseKeepAlive(TElHTTPServerResponseParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_get_WebSocketResponse(TElHTTPServerResponseParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_set_WebSocketResponse(TElHTTPServerResponseParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPServerResponseParams_Create(TElHTTPServerResponseParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPSERVERRESPONSEPARAMS */

#ifdef SB_USE_CLASS_TELMULTIPARTFORMDATA
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_Parse(TElMultipartFormDataHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_ParseStream(TElMultipartFormDataHandle _Handle, TStreamHandle Stream, const char * pcBoundary, int32_t szBoundary);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_get_Headers(TElMultipartFormDataHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_get_Headers(TElMultipartFormDataHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_get_Content(TElMultipartFormDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_get_ContentStartPos(TElMultipartFormDataHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_get_ContentSize(TElMultipartFormDataHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_get_IsMultipart(TElMultipartFormDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_get_Name(TElMultipartFormDataHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_get_FileName(TElMultipartFormDataHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormData_Create(TElMultipartFormDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELMULTIPARTFORMDATA */

#ifdef SB_USE_CLASS_TELMULTIPARTFORMLIST
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormList_Assign(TElMultipartFormListHandle _Handle, TElMultipartFormDataHandle Src);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormList_Parse(TElMultipartFormListHandle _Handle, TElHTTPServerRequestParamsHandle RequestInfo, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormList_ParseStream(TElMultipartFormListHandle _Handle, TElHTTPServerRequestParamsHandle RequestInfo, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormList_get_ValuesByName(TElMultipartFormListHandle _Handle, const char * pcName, int32_t szName, TElMultipartFormDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormList_get_ValuesByFileName(TElMultipartFormListHandle _Handle, const char * pcName, int32_t szName, TElMultipartFormDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormList_get_ValuesByIndex(TElMultipartFormListHandle _Handle, int32_t Idx, TElMultipartFormDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormList_get_Count(TElMultipartFormListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartFormList_Create(TElMultipartFormListHandle * OutResult);
#endif /* SB_USE_CLASS_TELMULTIPARTFORMLIST */

#ifdef SB_USE_CLASS_TELHTTPSSERVER
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_Open(TElHTTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_DataAvailable(TElHTTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_Send100Continue(TElHTTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_SendResponseHeaders(TElHTTPSServerHandle _Handle, TElHTTPServerRequestParamsHandle RequestParameters, TElHTTPServerResponseParamsHandle ResponseParameters);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_SendResponseData(TElHTTPSServerHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_SendResponseData_1(TElHTTPSServerHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_SendResponseData_2(TElHTTPSServerHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_SendResponseData_3(TElHTTPSServerHandle _Handle, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_ResponseComplete(TElHTTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_Close(TElHTTPSServerHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_ParseMultipartFormData(TElHTTPSServerHandle _Handle, TElHTTPServerRequestParamsHandle RequestParameters, const uint8_t pBuffer[], int32_t szBuffer, TElMultipartFormListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_ParseMultipartFormData_1(TElHTTPSServerHandle _Handle, TElHTTPServerRequestParamsHandle RequestParameters, TStreamHandle Strm, TElMultipartFormListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_ParseMultipartFormData_2(TElHTTPSServerHandle _Handle, TElHTTPServerRequestParamsHandle RequestParameters, TStreamHandle Strm, int8_t LoadData, TElMultipartFormListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_GetControl(TElHTTPSServerHandle _Handle, TElSSLClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_AddCertTypeHandler(TElHTTPSServerHandle _Handle, TElSSLCertificateTypeHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_RemoveCertTypeHandler(TElHTTPSServerHandle _Handle, TElSSLCertificateTypeHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_GetCertTypeHandler(TElHTTPSServerHandle _Handle, TElSSLCertificateTypeRaw CertType, TElSSLCertificateTypeHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_AssignTLSParamsFromTemplate(TElHTTPSServerHandle _Handle, TElSSLServerHandle Tpl);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_ConfigureTLS(TElHTTPSServerHandle _Handle, TSBServerSSLPredefinedConfigurationRaw Configuration);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLCipherSuite(TElHTTPSServerHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLCipherSuites(TElHTTPSServerHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLCipherSuites(TElHTTPSServerHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLCipherSuitePriorities(TElHTTPSServerHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLCipherSuitePriorities(TElHTTPSServerHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLCompressionAlgorithms(TElHTTPSServerHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLCompressionAlgorithms(TElHTTPSServerHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLVersion(TElHTTPSServerHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLCompressionAlgorithm(TElHTTPSServerHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLConnectionInfo(TElHTTPSServerHandle _Handle, TElSSLConnectionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_Active(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_AllowKeepAlive(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_AllowKeepAlive(TElHTTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_AuthRealm(TElHTTPSServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_AuthRealm(TElHTTPSServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_AuthBasic(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_AuthBasic(TElHTTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_AuthDigest(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_AuthDigest(TElHTTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_AuthDigestExpire(TElHTTPSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_AuthDigestExpire(TElHTTPSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_CloseConnectionOnUnauthorizedData(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_CloseConnectionOnUnauthorizedData(TElHTTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SendForbiddenAuto(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SendForbiddenAuto(TElHTTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLMode(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLMode(TElHTTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLClientAuthentication(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLClientAuthentication(TElHTTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLAuthenticationLevel(TElHTTPSServerHandle _Handle, TSBAuthenticationLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLAuthenticationLevel(TElHTTPSServerHandle _Handle, TSBAuthenticationLevelRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLForceCertificateChain(TElHTTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLForceCertificateChain(TElHTTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_CertStorage(TElHTTPSServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_CertStorage(TElHTTPSServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLSessionPool(TElHTTPSServerHandle _Handle, TElSessionPoolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLSessionPool(TElHTTPSServerHandle _Handle, TElSessionPoolHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_ClientCertStorage(TElHTTPSServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_ClientCertStorage(TElHTTPSServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLVersions(TElHTTPSServerHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLVersions(TElHTTPSServerHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLExtensions(TElHTTPSServerHandle _Handle, TElServerSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLPeerExtensions(TElHTTPSServerHandle _Handle, TElCustomSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SSLOptions(TElHTTPSServerHandle _Handle, TSBSSLOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SSLOptions(TElHTTPSServerHandle _Handle, TSBSSLOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_RenegotiationAttackPreventionMode(TElHTTPSServerHandle _Handle, TSBRenegotiationAttackPreventionModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_RenegotiationAttackPreventionMode(TElHTTPSServerHandle _Handle, TSBRenegotiationAttackPreventionModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_SRPCredentialStore(TElHTTPSServerHandle _Handle, TElSRPCredentialStoreHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_SRPCredentialStore(TElHTTPSServerHandle _Handle, TElSRPCredentialStoreHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnGetSrpDb(TElHTTPSServerHandle _Handle, TSBServerSrpDbNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnGetSrpDb(TElHTTPSServerHandle _Handle, TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnSend(TElHTTPSServerHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnSend(TElHTTPSServerHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnReceive(TElHTTPSServerHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnReceive(TElHTTPSServerHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnData(TElHTTPSServerHandle _Handle, TSBDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnData(TElHTTPSServerHandle _Handle, TSBDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnOpenConnection(TElHTTPSServerHandle _Handle, TSBOpenConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnOpenConnection(TElHTTPSServerHandle _Handle, TSBOpenConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnCertificateValidate(TElHTTPSServerHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnCertificateValidate(TElHTTPSServerHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnCiphersNegotiated(TElHTTPSServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnCiphersNegotiated(TElHTTPSServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnSSLError(TElHTTPSServerHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnSSLError(TElHTTPSServerHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnExtensionsReceived(TElHTTPSServerHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnExtensionsReceived(TElHTTPSServerHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnExtensionsPrepared(TElHTTPSServerHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnExtensionsPrepared(TElHTTPSServerHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnKeyNeeded(TElHTTPSServerHandle _Handle, TSBServerKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnKeyNeeded(TElHTTPSServerHandle _Handle, TSBServerKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnCloseConnection(TElHTTPSServerHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnCloseConnection(TElHTTPSServerHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnRenegotiationStart(TElHTTPSServerHandle _Handle, TSBRenegotiationStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnRenegotiationStart(TElHTTPSServerHandle _Handle, TSBRenegotiationStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnCertificateURLs(TElHTTPSServerHandle _Handle, TSBCertificateURLsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnCertificateURLs(TElHTTPSServerHandle _Handle, TSBCertificateURLsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnPreparedHeaders(TElHTTPSServerHandle _Handle, TSBHTTPHeadersEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnPreparedHeaders(TElHTTPSServerHandle _Handle, TSBHTTPHeadersEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnRequestHeadersReceived(TElHTTPSServerHandle _Handle, TSBHTTPRequestHeadersEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnRequestHeadersReceived(TElHTTPSServerHandle _Handle, TSBHTTPRequestHeadersEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnAfterAuthorization(TElHTTPSServerHandle _Handle, TSBHTTPAfterAuthorizationEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnAfterAuthorization(TElHTTPSServerHandle _Handle, TSBHTTPAfterAuthorizationEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnRequestBodyReceived(TElHTTPSServerHandle _Handle, TSBHTTPRequestBodyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnRequestBodyReceived(TElHTTPSServerHandle _Handle, TSBHTTPRequestBodyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnGetUserPassword(TElHTTPSServerHandle _Handle, TSBOnGetUserPasswordEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnGetUserPassword(TElHTTPSServerHandle _Handle, TSBOnGetUserPasswordEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnBeforeWebSocketServerUsed(TElHTTPSServerHandle _Handle, TSBHTTPBeforeWebSocketServerUsedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnBeforeWebSocketServerUsed(TElHTTPSServerHandle _Handle, TSBHTTPBeforeWebSocketServerUsedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_get_OnWebSocketConnectionEstablished(TElHTTPSServerHandle _Handle, SBHTTPSServer_TSBHTTPWebSocketConnectionEstablishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_set_OnWebSocketConnectionEstablished(TElHTTPSServerHandle _Handle, SBHTTPSServer_TSBHTTPWebSocketConnectionEstablishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSServer_Create(TComponentHandle AOwner, TElHTTPSServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

#ifdef SB_USE_CLASS_TELDIGESTAUTH
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_Init(TElDigestAuthHandle _Handle, const char * pcUserParams, int32_t szUserParams);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_CalcHash(TElDigestAuthHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_get_Nonce(TElDigestAuthHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_set_Nonce(TElDigestAuthHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_get_Password(TElDigestAuthHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_set_Password(TElDigestAuthHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_get_RequestMethod(TElDigestAuthHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_set_RequestMethod(TElDigestAuthHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_get_RequestURI(TElDigestAuthHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_set_RequestURI(TElDigestAuthHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_get_Response(TElDigestAuthHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_set_Response(TElDigestAuthHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_get_UserName(TElDigestAuthHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_set_UserName(TElDigestAuthHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDigestAuth_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELDIGESTAUTH */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHTTPServerRequestParams;
typedef TElHTTPServerRequestParams ElHTTPServerRequestParams;
class TElHTTPServerResponseParams;
typedef TElHTTPServerResponseParams ElHTTPServerResponseParams;
class TElMultipartFormData;
typedef TElMultipartFormData ElMultipartFormData;
class TElMultipartFormList;
typedef TElMultipartFormList ElMultipartFormList;
class TElHTTPSServer;
typedef TElHTTPSServer ElHTTPSServer;
class TElDigestAuth;

#ifdef SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS
class TElHTTPServerRequestParams: public TElHTTPCustomRequestParams
{
	private:
		SB_DISABLE_COPY(TElHTTPServerRequestParams)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TObjectHandle Clone();

		virtual void get_CustomMethod(std::string &OutResult);

		virtual void set_CustomMethod(const std::string &Value);

		virtual bool get_Expects100Continue();

		virtual void set_Expects100Continue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Expects100Continue, set_Expects100Continue, TElHTTPServerRequestParams, Expects100Continue);

		virtual TSBHTTPVersion get_HTTPVersion();

		virtual void set_HTTPVersion(TSBHTTPVersion Value);

		SB_DECLARE_PROPERTY(TSBHTTPVersion, get_HTTPVersion, set_HTTPVersion, TElHTTPServerRequestParams, HTTPVersion);

		virtual bool get_KeepAlive();

		virtual void set_KeepAlive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_KeepAlive, set_KeepAlive, TElHTTPServerRequestParams, KeepAlive);

		virtual TSBHTTPMethod get_Method();

		virtual void set_Method(TSBHTTPMethod Value);

		SB_DECLARE_PROPERTY(TSBHTTPMethod, get_Method, set_Method, TElHTTPServerRequestParams, Method);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual bool get_Chunked();

		SB_DECLARE_PROPERTY_GET(bool, get_Chunked, TElHTTPServerRequestParams, Chunked);

		virtual bool get_PreferGzip();

		SB_DECLARE_PROPERTY_GET(bool, get_PreferGzip, TElHTTPServerRequestParams, PreferGzip);

		virtual bool get_AcceptGZip();

		SB_DECLARE_PROPERTY_GET(bool, get_AcceptGZip, TElHTTPServerRequestParams, AcceptGZip);

		virtual bool get_AcceptDeflate();

		SB_DECLARE_PROPERTY_GET(bool, get_AcceptDeflate, TElHTTPServerRequestParams, AcceptDeflate);

		virtual bool get_AcceptChunked();

		SB_DECLARE_PROPERTY_GET(bool, get_AcceptChunked, TElHTTPServerRequestParams, AcceptChunked);

		virtual bool get_AcceptIdentity();

		SB_DECLARE_PROPERTY_GET(bool, get_AcceptIdentity, TElHTTPServerRequestParams, AcceptIdentity);

		virtual void get_AuthMethod(std::string &OutResult);

		virtual bool get_RequireAuth();

		virtual void set_RequireAuth(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequireAuth, set_RequireAuth, TElHTTPServerRequestParams, RequireAuth);

		virtual bool get_WebSocketRequest();

		SB_DECLARE_PROPERTY_GET(bool, get_WebSocketRequest, TElHTTPServerRequestParams, WebSocketRequest);

		TElHTTPServerRequestParams(TElHTTPServerRequestParamsHandle handle, TElOwnHandle ownHandle);

		TElHTTPServerRequestParams();

};
#endif /* SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSERVERRESPONSEPARAMS
class TElHTTPServerResponseParams: public TElHTTPParams
{
	private:
		SB_DISABLE_COPY(TElHTTPServerResponseParams)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TObjectHandle Clone();

		virtual bool get_AcceptRanges();

		virtual void set_AcceptRanges(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AcceptRanges, set_AcceptRanges, TElHTTPServerResponseParams, AcceptRanges);

		virtual void get_Location(std::string &OutResult);

		virtual void set_Location(const std::string &Value);

		virtual int32_t get_StatusCode();

		virtual void set_StatusCode(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StatusCode, set_StatusCode, TElHTTPServerResponseParams, StatusCode);

		virtual int64_t get_Expires();

		virtual void set_Expires(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Expires, set_Expires, TElHTTPServerResponseParams, Expires);

		virtual int64_t get_LastModified();

		virtual void set_LastModified(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_LastModified, set_LastModified, TElHTTPServerResponseParams, LastModified);

		virtual void get_ReasonPhrase(std::string &OutResult);

		virtual void set_ReasonPhrase(const std::string &Value);

		virtual void get_Server(std::string &OutResult);

		virtual void set_Server(const std::string &Value);

		virtual bool get_UseChunkedTransfer();

		virtual void set_UseChunkedTransfer(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseChunkedTransfer, set_UseChunkedTransfer, TElHTTPServerResponseParams, UseChunkedTransfer);

		virtual bool get_UseCompression();

		virtual void set_UseCompression(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCompression, set_UseCompression, TElHTTPServerResponseParams, UseCompression);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElHTTPServerResponseParams, CompressionLevel);

		virtual bool get_UseKeepAlive();

		virtual void set_UseKeepAlive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseKeepAlive, set_UseKeepAlive, TElHTTPServerResponseParams, UseKeepAlive);

		virtual bool get_WebSocketResponse();

		virtual void set_WebSocketResponse(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WebSocketResponse, set_WebSocketResponse, TElHTTPServerResponseParams, WebSocketResponse);

		TElHTTPServerResponseParams(TElHTTPServerResponseParamsHandle handle, TElOwnHandle ownHandle);

		TElHTTPServerResponseParams();

};
#endif /* SB_USE_CLASS_TELHTTPSERVERRESPONSEPARAMS */

#ifdef SB_USE_CLASS_TELMULTIPARTFORMDATA
class TElMultipartFormData: public TObject
{
	private:
		SB_DISABLE_COPY(TElMultipartFormData)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Headers;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Headers;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		void Parse(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void ParseStream(TStream &Stream, const std::string &Boundary);

		void ParseStream(TStream *Stream, const std::string &Boundary);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Headers();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Headers, TElMultipartFormData, Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Headers();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Headers, TElMultipartFormData, Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual int64_t get_ContentStartPos();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ContentStartPos, TElMultipartFormData, ContentStartPos);

		virtual int64_t get_ContentSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ContentSize, TElMultipartFormData, ContentSize);

		virtual bool get_IsMultipart();

		SB_DECLARE_PROPERTY_GET(bool, get_IsMultipart, TElMultipartFormData, IsMultipart);

		virtual void get_Name(std::string &OutResult);

		virtual void get_FileName(std::string &OutResult);

		TElMultipartFormData(TElMultipartFormDataHandle handle, TElOwnHandle ownHandle);

		TElMultipartFormData();

		virtual ~TElMultipartFormData();

};
#endif /* SB_USE_CLASS_TELMULTIPARTFORMDATA */

#ifdef SB_USE_CLASS_TELMULTIPARTFORMLIST
class TElMultipartFormList: public TElMultipartFormData
{
	private:
		SB_DISABLE_COPY(TElMultipartFormList)
		TElMultipartFormData* _Inst_ValuesByName;
		TElMultipartFormData* _Inst_ValuesByFileName;
		TElMultipartFormData* _Inst_ValuesByIndex;

		void initInstances();

	public:
		void Assign(TElMultipartFormData &Src);

		void Assign(TElMultipartFormData *Src);

#ifdef SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS
		void Parse(TElHTTPServerRequestParams &RequestInfo, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		void Parse(TElHTTPServerRequestParams *RequestInfo, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);
#endif /* SB_USE_CLASS_TELHTTPSERVERREQUESTPARAMS */

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TSTREAM
		void ParseStream(TElHTTPServerRequestParams &RequestInfo, TStream &Stream);

		void ParseStream(TElHTTPServerRequestParams *RequestInfo, TStream *Stream);
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TSTREAM */

		virtual TElMultipartFormData* get_ValuesByName(const std::string &Name);

		virtual TElMultipartFormData* get_ValuesByFileName(const std::string &Name);

		virtual TElMultipartFormData* get_ValuesByIndex(int32_t Idx);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElMultipartFormList, Count);

		TElMultipartFormList(TElMultipartFormListHandle handle, TElOwnHandle ownHandle);

		TElMultipartFormList();

		virtual ~TElMultipartFormList();

};
#endif /* SB_USE_CLASS_TELMULTIPARTFORMLIST */

#ifdef SB_USE_CLASS_TELHTTPSSERVER
class TElHTTPSServer: public TComponent
{
	private:
		SB_DISABLE_COPY(TElHTTPSServer)
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		TElSSLConnectionInfo* _Inst_SSLConnectionInfo;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
		TElSessionPool* _Inst_SSLSessionPool;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
		TElServerSSLExtensions* _Inst_SSLExtensions;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		TElCustomSSLExtensions* _Inst_SSLPeerExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
		TElSRPCredentialStore* _Inst_SRPCredentialStore;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

		void initInstances();

	public:
		void Open();

		void DataAvailable();

		void Send100Continue();

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELHTTPSERVERRESPONSEPARAMS
		void SendResponseHeaders(TElHTTPServerRequestParams &RequestParameters, TElHTTPServerResponseParams &ResponseParameters);

		void SendResponseHeaders(TElHTTPServerRequestParams *RequestParameters, TElHTTPServerResponseParams *ResponseParameters);
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELHTTPSERVERRESPONSEPARAMS */

		void SendResponseData(const std::vector<uint8_t> &Buffer);

		void SendResponseData(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count);

		void SendResponseData(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void SendResponseData(TStream &Strm);

		void SendResponseData(TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

		void ResponseComplete();

		void Close(bool Silent);

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST
		TElMultipartFormListHandle ParseMultipartFormData(TElHTTPServerRequestParams &RequestParameters, const std::vector<uint8_t> &Buffer);

		TElMultipartFormListHandle ParseMultipartFormData(TElHTTPServerRequestParams *RequestParameters, const std::vector<uint8_t> &Buffer);
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST */

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST_AND_TSTREAM
		TElMultipartFormListHandle ParseMultipartFormData(TElHTTPServerRequestParams &RequestParameters, TStream &Strm);

		TElMultipartFormListHandle ParseMultipartFormData(TElHTTPServerRequestParams *RequestParameters, TStream *Strm);
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST_AND_TSTREAM
		TElMultipartFormListHandle ParseMultipartFormData(TElHTTPServerRequestParams &RequestParameters, TStream &Strm, bool LoadData);

		TElMultipartFormListHandle ParseMultipartFormData(TElHTTPServerRequestParams *RequestParameters, TStream *Strm, bool LoadData);
#endif /* SB_USE_CLASSES_TELHTTPSERVERREQUESTPARAMS_AND_TELMULTIPARTFORMLIST_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELSSLCLASS
		TElSSLClassHandle GetControl();
#endif /* SB_USE_CLASS_TELSSLCLASS */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
		void AddCertTypeHandler(TElSSLCertificateTypeHandler &Handler);

		void AddCertTypeHandler(TElSSLCertificateTypeHandler *Handler);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
		void RemoveCertTypeHandler(TElSSLCertificateTypeHandler &Handler);

		void RemoveCertTypeHandler(TElSSLCertificateTypeHandler *Handler);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
		TElSSLCertificateTypeHandlerHandle GetCertTypeHandler(TElSSLCertificateType CertType);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLSERVER
		void AssignTLSParamsFromTemplate(TElSSLServer &Tpl);

		void AssignTLSParamsFromTemplate(TElSSLServer *Tpl);
#endif /* SB_USE_CLASS_TELSSLSERVER */

		void ConfigureTLS(TSBServerSSLPredefinedConfiguration Configuration);

		virtual uint8_t get_SSLCipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SSLCipherSuite, TElHTTPSServer, SSLCipherSuite);

		virtual bool get_SSLCipherSuites(uint8_t Index);

		virtual void set_SSLCipherSuites(uint8_t Index, bool Value);

		virtual int32_t get_SSLCipherSuitePriorities(uint8_t Index);

		virtual void set_SSLCipherSuitePriorities(uint8_t Index, int32_t Value);

		virtual bool get_SSLCompressionAlgorithms(uint8_t Index);

		virtual void set_SSLCompressionAlgorithms(uint8_t Index, bool Value);

		virtual TSBVersion get_SSLVersion();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_SSLVersion, TElHTTPSServer, SSLVersion);

		virtual uint8_t get_SSLCompressionAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SSLCompressionAlgorithm, TElHTTPSServer, SSLCompressionAlgorithm);

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		virtual TElSSLConnectionInfo* get_SSLConnectionInfo();

		SB_DECLARE_PROPERTY_GET(TElSSLConnectionInfo*, get_SSLConnectionInfo, TElHTTPSServer, SSLConnectionInfo);
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElHTTPSServer, Active);

		virtual bool get_AllowKeepAlive();

		virtual void set_AllowKeepAlive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowKeepAlive, set_AllowKeepAlive, TElHTTPSServer, AllowKeepAlive);

		virtual void get_AuthRealm(std::string &OutResult);

		virtual void set_AuthRealm(const std::string &Value);

		virtual bool get_AuthBasic();

		virtual void set_AuthBasic(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AuthBasic, set_AuthBasic, TElHTTPSServer, AuthBasic);

		virtual bool get_AuthDigest();

		virtual void set_AuthDigest(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AuthDigest, set_AuthDigest, TElHTTPSServer, AuthDigest);

		virtual int32_t get_AuthDigestExpire();

		virtual void set_AuthDigestExpire(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthDigestExpire, set_AuthDigestExpire, TElHTTPSServer, AuthDigestExpire);

		virtual bool get_CloseConnectionOnUnauthorizedData();

		virtual void set_CloseConnectionOnUnauthorizedData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CloseConnectionOnUnauthorizedData, set_CloseConnectionOnUnauthorizedData, TElHTTPSServer, CloseConnectionOnUnauthorizedData);

		virtual bool get_SendForbiddenAuto();

		virtual void set_SendForbiddenAuto(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SendForbiddenAuto, set_SendForbiddenAuto, TElHTTPSServer, SendForbiddenAuto);

		virtual bool get_SSLMode();

		virtual void set_SSLMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SSLMode, set_SSLMode, TElHTTPSServer, SSLMode);

		virtual bool get_SSLClientAuthentication();

		virtual void set_SSLClientAuthentication(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SSLClientAuthentication, set_SSLClientAuthentication, TElHTTPSServer, SSLClientAuthentication);

		virtual TSBAuthenticationLevel get_SSLAuthenticationLevel();

		virtual void set_SSLAuthenticationLevel(TSBAuthenticationLevel Value);

		SB_DECLARE_PROPERTY(TSBAuthenticationLevel, get_SSLAuthenticationLevel, set_SSLAuthenticationLevel, TElHTTPSServer, SSLAuthenticationLevel);

		virtual bool get_SSLForceCertificateChain();

		virtual void set_SSLForceCertificateChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SSLForceCertificateChain, set_SSLForceCertificateChain, TElHTTPSServer, SSLForceCertificateChain);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElHTTPSServer, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
		virtual TElSessionPool* get_SSLSessionPool();

		virtual void set_SSLSessionPool(TElSessionPool &Value);

		virtual void set_SSLSessionPool(TElSessionPool *Value);

		SB_DECLARE_PROPERTY(TElSessionPool*, get_SSLSessionPool, set_SSLSessionPool, TElHTTPSServer, SSLSessionPool);
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElHTTPSServer, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual TSBVersions get_SSLVersions();

		virtual void set_SSLVersions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_SSLVersions, set_SSLVersions, TElHTTPSServer, SSLVersions);

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
		virtual TElServerSSLExtensions* get_SSLExtensions();

		SB_DECLARE_PROPERTY_GET(TElServerSSLExtensions*, get_SSLExtensions, TElHTTPSServer, SSLExtensions);
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		virtual TElCustomSSLExtensions* get_SSLPeerExtensions();

		SB_DECLARE_PROPERTY_GET(TElCustomSSLExtensions*, get_SSLPeerExtensions, TElHTTPSServer, SSLPeerExtensions);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

		virtual TSBSSLOptions get_SSLOptions();

		virtual void set_SSLOptions(TSBSSLOptions Value);

		SB_DECLARE_PROPERTY(TSBSSLOptions, get_SSLOptions, set_SSLOptions, TElHTTPSServer, SSLOptions);

		virtual TSBRenegotiationAttackPreventionMode get_RenegotiationAttackPreventionMode();

		virtual void set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value);

		SB_DECLARE_PROPERTY(TSBRenegotiationAttackPreventionMode, get_RenegotiationAttackPreventionMode, set_RenegotiationAttackPreventionMode, TElHTTPSServer, RenegotiationAttackPreventionMode);

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
		virtual TElSRPCredentialStore* get_SRPCredentialStore();

		virtual void set_SRPCredentialStore(TElSRPCredentialStore &Value);

		virtual void set_SRPCredentialStore(TElSRPCredentialStore *Value);

		SB_DECLARE_PROPERTY(TElSRPCredentialStore*, get_SRPCredentialStore, set_SRPCredentialStore, TElHTTPSServer, SRPCredentialStore);
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

		virtual void get_OnGetSrpDb(TSBServerSrpDbNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetSrpDb(TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSBSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnData(TSBDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBServerKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBServerKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenegotiationStart(TSBRenegotiationStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenegotiationStart(TSBRenegotiationStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateURLs(TSBCertificateURLsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateURLs(TSBCertificateURLsEvent pMethodValue, void * pDataValue);

		virtual void get_OnPreparedHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPreparedHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestHeadersReceived(TSBHTTPRequestHeadersEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestHeadersReceived(TSBHTTPRequestHeadersEvent pMethodValue, void * pDataValue);

		virtual void get_OnAfterAuthorization(TSBHTTPAfterAuthorizationEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAfterAuthorization(TSBHTTPAfterAuthorizationEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestBodyReceived(TSBHTTPRequestBodyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestBodyReceived(TSBHTTPRequestBodyEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetUserPassword(TSBOnGetUserPasswordEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetUserPassword(TSBOnGetUserPasswordEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeWebSocketServerUsed(TSBHTTPBeforeWebSocketServerUsedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeWebSocketServerUsed(TSBHTTPBeforeWebSocketServerUsedEvent pMethodValue, void * pDataValue);

		virtual void get_OnWebSocketConnectionEstablished(SBHTTPSServer_TSBHTTPWebSocketConnectionEstablishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWebSocketConnectionEstablished(SBHTTPSServer_TSBHTTPWebSocketConnectionEstablishedEvent pMethodValue, void * pDataValue);

		TElHTTPSServer(TElHTTPSServerHandle handle, TElOwnHandle ownHandle);

		explicit TElHTTPSServer(TComponent &AOwner);

		explicit TElHTTPSServer(TComponent *AOwner);

		virtual ~TElHTTPSServer();

};
#endif /* SB_USE_CLASS_TELHTTPSSERVER */

#ifdef SB_USE_CLASS_TELDIGESTAUTH
class TElDigestAuth: public TObject
{
	private:
		SB_DISABLE_COPY(TElDigestAuth)
	public:
		void Init(const std::string &UserParams);

		void CalcHash(std::string &OutResult);

		virtual void get_Nonce(std::string &OutResult);

		virtual void set_Nonce(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_RequestMethod(std::string &OutResult);

		virtual void set_RequestMethod(const std::string &Value);

		virtual void get_RequestURI(std::string &OutResult);

		virtual void set_RequestURI(const std::string &Value);

		virtual void get_Response(std::string &OutResult);

		virtual void set_Response(const std::string &Value);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		TElDigestAuth(TElDigestAuthHandle handle, TElOwnHandle ownHandle);

		TElDigestAuth();

};
#endif /* SB_USE_CLASS_TELDIGESTAUTH */

#ifdef SB_USE_GLOBAL_PROCS_HTTPSSERVER

void GetDefaultReasonPhrase(int32_t ResponseCode, std::string &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_HTTPSSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_HTTPSSERVER
SB_IMPORT uint32_t SB_APIENTRY SBHTTPSServer_GetDefaultReasonPhrase(int32_t ResponseCode, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_HTTPSSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPSSERVER */
