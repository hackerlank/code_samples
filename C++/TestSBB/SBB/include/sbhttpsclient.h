#ifndef __INC_SBHTTPSCLIENT
#define __INC_SBHTTPSCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbsslcommon.h"
#include "sbsimplessl.h"
#include "sbcustomcertstorage.h"
#include "sbcookiemgr.h"
#include "sbdictionary.h"
#include "sbhttpsconstants.h"
#include "sbsslconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbstreams.h"
#include "sbhttpscommon.h"
#include "sbwebsocketcommon.h"
#include "sbwebsocketclient.h"
#include "sbhttpauth.h"
#include "sbsocket.h"
#include "sboauth2.h"
#include "sbsslclient.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SCannotSend 	"Cannot perform \"send\" on socket."
#define SB_SSocketError 	"Socket error occured. Code is %d."
#define SB_SDNSError 	"DNS error occured. Code is %d."
#ifndef SB_WINCE_OR_NOT_WINDOWS
#define SB_SInvalidNTLMResponse 	"Cannot get valid NTLM response from server."
#endif
#define SB_SInvalidDigestResponse 	"Cannot get valid Digest response from server."
#define SB_SInvalidDate 	"Invalid date/time value"
#define SB_SConnectionLost 	"Connection lost"
#define SB_WEBSOCKET_SUCCESS 	101

typedef TElClassHandle TElHTTPRequestParamsHandle;

typedef TElHTTPRequestParamsHandle ElHTTPRequestParamsHandle;

typedef TElClassHandle TElHTTPSClientHandle;

typedef TElHTTPSClientHandle ElHTTPSClientHandle;

typedef TElClassHandle SBHTTPSClient_TElStringValueHandle;

typedef void (SB_CALLBACK *TSBHTTPDynamicDataNeededEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pBuffer[], int32_t szBuffer, int32_t ToRead, int32_t * Read);

typedef void (SB_CALLBACK *TSBHTTPRedirectionEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOldURL, int32_t szOldURL, char * pcNewURL, int32_t * szNewURL, int8_t * AllowRedirection);

typedef void (SB_CALLBACK *TSBHTTPCookieEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcCookieText, int32_t szCookieText);

#ifdef SB_WINDOWS
typedef void (SB_CALLBACK *TSBHTTPOAuth2BrowseEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, TStringListHandle ResponseHeaders);
#else
typedef void (SB_CALLBACK *TSBHTTPOAuth2BrowseEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, TElStringListHandle ResponseHeaders);
#endif

typedef void (SB_CALLBACK *TSBHTTPUnsupportedTransferEncoding)(void * _ObjectData, TObjectHandle Sender, const char * pcEncoding, int32_t szEncoding, TElHTTPEncodingProcessorHandle * Processor, int8_t * Success);

typedef uint8_t TSBHTTPClientConnStageRaw;

typedef enum
{
	csHandshake = 0,
	csRequest = 1,
	csResponse = 2
} TSBHTTPClientConnStage;

typedef uint8_t TSBHTTPKeepAlivePolicyRaw;

typedef enum
{
	kapStandardDefined = 0,
	kapPreferKeepAlive = 1,
	kapRelyOnServer = 2,
	kapKeepAlivesDisabled = 3
} TSBHTTPKeepAlivePolicy;

typedef void (SB_CALLBACK *TSecureClientMethod)(void * _ObjectData);

typedef void (SB_CALLBACK *TSBHTTPBeforeWebSocketClientUsedEvent)(void * _ObjectData, TObjectHandle Sender, TElWebSocketClientHandle WSClient, TElHTTPSClientHandle HTTPClient);

typedef void (SB_CALLBACK *SBHTTPSClient_TSBHTTPWebSocketConnectionEstablishedEvent)(void * _ObjectData, TObjectHandle Sender, TElWebSocketClientHandle WSClient);

#ifdef SB_USE_CLASS_TELHTTPREQUESTPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRequestParams_get_Cookie(TElHTTPRequestParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRequestParams_set_Cookie(TElHTTPRequestParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPRequestParams_Create(TElHTTPCustomRequestParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_StartWS(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TElWebSocketClientHandle * WSClient, TElSocketHandle * Socket, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_CustomRequest(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcMethod, int32_t szMethod, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_CustomRequest_1(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcMethod, int32_t szMethod, TStreamHandle Content, int8_t CloseStream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Get(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Head(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Options(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Delete(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Trace(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Post(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Post_1(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcContent, int32_t szContent, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Post_2(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, const uint8_t pContent[], int32_t szContent, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Post_3(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Content, int8_t CloseStream, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_PostWebForm(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle Fields, const char * pcFileField, int32_t szFileField, const char * pcFileName, int32_t szFileName, TStreamHandle FileStream, const char * pcContentType, int32_t szContentType, int8_t CloseStream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_PostWebForm_1(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TStringListHandle Fields, const char * pcFileField, int32_t szFileField, const char * pcFileName, int32_t szFileName, TStreamHandle FileStream, const char * pcContentType, int32_t szContentType, int8_t CloseStream, const char * pcCharset, int32_t szCharset, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_PostWebForm(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle Fields, const char * pcFileField, int32_t szFileField, const char * pcFileName, int32_t szFileName, TStreamHandle FileStream, const char * pcContentType, int32_t szContentType, int8_t CloseStream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_PostWebForm_1(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TElStringListHandle Fields, const char * pcFileField, int32_t szFileField, const char * pcFileName, int32_t szFileName, TStreamHandle FileStream, const char * pcContentType, int32_t szContentType, int8_t CloseStream, const char * pcCharset, int32_t szCharset, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_PostMultipart(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TSBHTTPMultipartModeRaw MultipartMode, TElHTTPMultipartListHandle PartsList, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_PostMultipart_1(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TSBHTTPMultipartModeRaw MultipartMode, const char * pcRelatedStart, int32_t szRelatedStart, const char * pcRelatedStartInfo, int32_t szRelatedStartInfo, const char * pcRelatedType, int32_t szRelatedType, TElHTTPMultipartListHandle PartsList, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_PostMultipart_2(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TSBHTTPMultipartModeRaw MultipartMode, const char * pcRelatedStart, int32_t szRelatedStart, const char * pcRelatedStartInfo, int32_t szRelatedStartInfo, const char * pcRelatedType, int32_t szRelatedType, TElHTTPMultipartListHandle PartsList, const char * pcCharset, int32_t szCharset, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Put(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Put_1(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, const char * pcContent, int32_t szContent, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Put_2(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, const uint8_t pContent[], int32_t szContent, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Put_3(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, const uint8_t pContent[], int32_t szContent, int32_t StartIndex, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Put_4(TElHTTPSClientHandle _Handle, const char * pcURL, int32_t szURL, TStreamHandle Content, int8_t CloseStream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_CancelRequest(TElHTTPSClientHandle _Handle);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_GetHeaderByName(TElHTTPSClientHandle _Handle, TStringListHandle Headers, const char * pcHeader, int32_t szHeader, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_GetHeadersByName(TElHTTPSClientHandle _Handle, TStringListHandle Headers, const char * pcHeader, int32_t szHeader, TStringListHandle Res);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_SetHeaderByName(TElHTTPSClientHandle _Handle, TStringListHandle Headers, const char * pcHeader, int32_t szHeader, const char * pcValue, int32_t szValue);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_GetHeaderByName(TElHTTPSClientHandle _Handle, TElStringListHandle Headers, const char * pcHeader, int32_t szHeader, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_GetHeadersByName(TElHTTPSClientHandle _Handle, TElStringListHandle Headers, const char * pcHeader, int32_t szHeader, TElStringListHandle Res);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_SetHeaderByName(TElHTTPSClientHandle _Handle, TElStringListHandle Headers, const char * pcHeader, int32_t szHeader, const char * pcValue, int32_t szValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_SetRequestHeader(TElHTTPSClientHandle _Handle, const char * pcHeader, int32_t szHeader, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_ClearRequest(TElHTTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_ClearResponse(TElHTTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_ClearAuthCache(TElHTTPSClientHandle _Handle);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_RequestHeaders(TElHTTPSClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_ResponseHeaders(TElHTTPSClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_RequestCookies(TElHTTPSClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_ResponseCookies(TElHTTPSClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_RequestHeaders(TElHTTPSClientHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_ResponseHeaders(TElHTTPSClientHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_RequestCookies(TElHTTPSClientHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_ResponseCookies(TElHTTPSClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_ServerStatusCode(TElHTTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_ServerReasonPhrase(TElHTTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_ContentLength(TElHTTPSClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_Date(TElHTTPSClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OutputStream(TElHTTPSClientHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OutputStream(TElHTTPSClientHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_SSLEnabled(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_SSLEnabled(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_RequestParameters(TElHTTPSClientHandle _Handle, TElHTTPRequestParamsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_RequestParameters(TElHTTPSClientHandle _Handle, TElHTTPRequestParamsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_RequestCompressionLevel(TElHTTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_RequestCompressionLevel(TElHTTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_RequestCompressionGZip(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_RequestCompressionGZip(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_KeepAlivePolicy(TElHTTPSClientHandle _Handle, TSBHTTPKeepAlivePolicyRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_KeepAlivePolicy(TElHTTPSClientHandle _Handle, TSBHTTPKeepAlivePolicyRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_MaxRedirections(TElHTTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_MaxRedirections(TElHTTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_SuppressRedirectionContent(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_SuppressRedirectionContent(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_HTTPVersion(TElHTTPSClientHandle _Handle, TSBHTTPVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_HTTPVersion(TElHTTPSClientHandle _Handle, TSBHTTPVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_UseNTLMAuth(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_UseNTLMAuth(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_UseDigestAuth(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_UseDigestAuth(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_PersistentAuthHeader(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_PersistentAuthHeader(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_ForceNTLMAuth(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_ForceNTLMAuth(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_SendBufferSize(TElHTTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_SendBufferSize(TElHTTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_UseCompression(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_UseCompression(TElHTTPSClientHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_UseIPv6(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_UseIPv6(TElHTTPSClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_CookieManager(TElHTTPSClientHandle _Handle, TElCookieManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_CookieManager(TElHTTPSClientHandle _Handle, TElCookieManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_Use100Continue(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_Use100Continue(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OAuth2(TElHTTPSClientHandle _Handle, TElOAuth2SettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OAuth2(TElHTTPSClientHandle _Handle, TElOAuth2SettingsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_SAMLAdapter(TElHTTPSClientHandle _Handle, TElCustomSAMLAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_SAMLAdapter(TElHTTPSClientHandle _Handle, TElCustomSAMLAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_HTTPProxyUsername(TElHTTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_HTTPProxyUsername(TElHTTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_HTTPProxyPassword(TElHTTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_HTTPProxyPassword(TElHTTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_HTTPProxyHost(TElHTTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_HTTPProxyHost(TElHTTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_HTTPProxyPort(TElHTTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_HTTPProxyPort(TElHTTPSClientHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_HTTPProxyRequestHeaders(TElHTTPSClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_HTTPProxyRequestHeaders(TElHTTPSClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_HTTPProxyAuthentication(TElHTTPSClientHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_HTTPProxyAuthentication(TElHTTPSClientHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_UseHTTPProxy(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_UseHTTPProxy(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_IgnoreUnknownTransferEncodings(TElHTTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_IgnoreUnknownTransferEncodings(TElHTTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnBeforeWebSocketClientUsed(TElHTTPSClientHandle _Handle, TSBHTTPBeforeWebSocketClientUsedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnBeforeWebSocketClientUsed(TElHTTPSClientHandle _Handle, TSBHTTPBeforeWebSocketClientUsedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnWebSocketConnectionEstablished(TElHTTPSClientHandle _Handle, SBHTTPSClient_TSBHTTPWebSocketConnectionEstablishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnWebSocketConnectionEstablished(TElHTTPSClientHandle _Handle, SBHTTPSClient_TSBHTTPWebSocketConnectionEstablishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnCookie(TElHTTPSClientHandle _Handle, TSBHTTPCookieEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnCookie(TElHTTPSClientHandle _Handle, TSBHTTPCookieEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnData(TElHTTPSClientHandle _Handle, TSBDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnData(TElHTTPSClientHandle _Handle, TSBDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnDocumentBegin(TElHTTPSClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnDocumentBegin(TElHTTPSClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnDocumentEnd(TElHTTPSClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnDocumentEnd(TElHTTPSClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnReceivingHeaders(TElHTTPSClientHandle _Handle, TSBHTTPHeadersEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnReceivingHeaders(TElHTTPSClientHandle _Handle, TSBHTTPHeadersEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnPreparedHeaders(TElHTTPSClientHandle _Handle, TSBHTTPHeadersEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnPreparedHeaders(TElHTTPSClientHandle _Handle, TSBHTTPHeadersEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnProgress(TElHTTPSClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnProgress(TElHTTPSClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnRedirection(TElHTTPSClientHandle _Handle, TSBHTTPRedirectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnRedirection(TElHTTPSClientHandle _Handle, TSBHTTPRedirectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnSendData(TElHTTPSClientHandle _Handle, TSBDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnSendData(TElHTTPSClientHandle _Handle, TSBDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnDynamicDataNeeded(TElHTTPSClientHandle _Handle, TSBHTTPDynamicDataNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnDynamicDataNeeded(TElHTTPSClientHandle _Handle, TSBHTTPDynamicDataNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnOAuth2Browse(TElHTTPSClientHandle _Handle, TSBHTTPOAuth2BrowseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnOAuth2Browse(TElHTTPSClientHandle _Handle, TSBHTTPOAuth2BrowseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnUnsupportedTransferEncoding(TElHTTPSClientHandle _Handle, TSBHTTPUnsupportedTransferEncoding * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnUnsupportedTransferEncoding(TElHTTPSClientHandle _Handle, TSBHTTPUnsupportedTransferEncoding pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnCertificateChoose(TElHTTPSClientHandle _Handle, TSBChooseCertificateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnCertificateChoose(TElHTTPSClientHandle _Handle, TSBChooseCertificateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnCertificateNeededEx(TElHTTPSClientHandle _Handle, TSBCertificateNeededExEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnCertificateNeededEx(TElHTTPSClientHandle _Handle, TSBCertificateNeededExEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnCertificateValidate(TElHTTPSClientHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnCertificateValidate(TElHTTPSClientHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnCiphersNegotiated(TElHTTPSClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnCiphersNegotiated(TElHTTPSClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnCloseConnection(TElHTTPSClientHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnCloseConnection(TElHTTPSClientHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnError(TElHTTPSClientHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnError(TElHTTPSClientHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnExtensionsReceived(TElHTTPSClientHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnExtensionsReceived(TElHTTPSClientHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnExtensionsPrepared(TElHTTPSClientHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnExtensionsPrepared(TElHTTPSClientHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnCertificateStatus(TElHTTPSClientHandle _Handle, TSBCertificateStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnCertificateStatus(TElHTTPSClientHandle _Handle, TSBCertificateStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnKeyNeeded(TElHTTPSClientHandle _Handle, TSBClientKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnKeyNeeded(TElHTTPSClientHandle _Handle, TSBClientKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_get_OnRenegotiationRequest(TElHTTPSClientHandle _Handle, TSBRenegotiationRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_set_OnRenegotiationRequest(TElHTTPSClientHandle _Handle, TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElHTTPSClient_Create(TComponentHandle AOwner, TElHTTPSClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#ifdef SB_USE_CLASS_SBHTTPSCLIENT_TELSTRINGVALUE
SB_IMPORT uint32_t SB_APIENTRY SBHTTPSClient_TElStringValue_get_Value(SBHTTPSClient_TElStringValueHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBHTTPSClient_TElStringValue_set_Value(SBHTTPSClient_TElStringValueHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBHTTPSClient_TElStringValue_Create(const char * pcValue, int32_t szValue, SBHTTPSClient_TElStringValueHandle * OutResult);
#endif /* SB_USE_CLASS_SBHTTPSCLIENT_TELSTRINGVALUE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElHTTPRequestParams;
typedef TElHTTPRequestParams ElHTTPRequestParams;
class TElHTTPSClient;
typedef TElHTTPSClient ElHTTPSClient;
class SBHTTPSClient_TElStringValue;

#ifdef SB_USE_CLASS_TELHTTPREQUESTPARAMS
class TElHTTPRequestParams: public TElHTTPCustomRequestParams
{
	private:
		SB_DISABLE_COPY(TElHTTPRequestParams)
	public:
		virtual void get_Cookie(std::string &OutResult);

		virtual void set_Cookie(const std::string &Value);

		TElHTTPRequestParams(TElHTTPRequestParamsHandle handle, TElOwnHandle ownHandle);

		TElHTTPRequestParams();

};
#endif /* SB_USE_CLASS_TELHTTPREQUESTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENT
class TElHTTPSClient: public TElCustomSimpleSSLClient
{
	private:
		SB_DISABLE_COPY(TElHTTPSClient)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_RequestHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ResponseHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_RequestCookies;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ResponseCookies;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_RequestHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ResponseHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_RequestCookies;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ResponseCookies;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_OutputStream;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELHTTPREQUESTPARAMS
		TElHTTPRequestParams* _Inst_RequestParameters;
#endif /* SB_USE_CLASS_TELHTTPREQUESTPARAMS */
#ifdef SB_USE_CLASS_TELCOOKIEMANAGER
		TElCookieManager* _Inst_CookieManager;
#endif /* SB_USE_CLASS_TELCOOKIEMANAGER */
#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
		TElOAuth2Settings* _Inst_OAuth2;
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMSAMLADAPTER
		TElCustomSAMLAdapter* _Inst_SAMLAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMSAMLADAPTER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_HTTPProxyRequestHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_HTTPProxyRequestHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELSOCKET_AND_TELWEBSOCKETCLIENT
		int32_t StartWS(const std::string &URL, TElWebSocketClient &WSClient, TElSocket &Socket);
#endif /* SB_USE_CLASSES_TELSOCKET_AND_TELWEBSOCKETCLIENT */

		int32_t CustomRequest(const std::string &URL, const std::string &Method);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t CustomRequest(const std::string &URL, const std::string &Method, TStream &Content, bool CloseStream);

		int32_t CustomRequest(const std::string &URL, const std::string &Method, TStream *Content, bool CloseStream);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t Get(const std::string &URL);

		int32_t Head(const std::string &URL);

		int32_t Options(const std::string &URL);

		int32_t Delete(const std::string &URL);

		int32_t Trace(const std::string &URL);

		int32_t Post(const std::string &URL);

		int32_t Post(const std::string &URL, const std::string &Content);

		int32_t Post(const std::string &URL, const std::vector<uint8_t> &Content);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Post(const std::string &URL, TStream &Content, bool CloseStream);

		int32_t Post(const std::string &URL, TStream *Content, bool CloseStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		int32_t PostWebForm(const std::string &URL, TStringList &Fields, const std::string &FileField, const std::string &FileName, TStream &FileStream, const std::string &ContentType, bool CloseStream);

		int32_t PostWebForm(const std::string &URL, TStringList *Fields, const std::string &FileField, const std::string &FileName, TStream *FileStream, const std::string &ContentType, bool CloseStream);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		int32_t PostWebForm(const std::string &URL, TElStringList &Fields, const std::string &FileField, const std::string &FileName, TStream &FileStream, const std::string &ContentType, bool CloseStream);

		int32_t PostWebForm(const std::string &URL, TElStringList *Fields, const std::string &FileField, const std::string &FileName, TStream *FileStream, const std::string &ContentType, bool CloseStream);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
		int32_t PostWebForm(const std::string &URL, TStringList &Fields, const std::string &FileField, const std::string &FileName, TStream &FileStream, const std::string &ContentType, bool CloseStream, const std::string &Charset);

		int32_t PostWebForm(const std::string &URL, TStringList *Fields, const std::string &FileField, const std::string &FileName, TStream *FileStream, const std::string &ContentType, bool CloseStream, const std::string &Charset);
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
		int32_t PostWebForm(const std::string &URL, TElStringList &Fields, const std::string &FileField, const std::string &FileName, TStream &FileStream, const std::string &ContentType, bool CloseStream, const std::string &Charset);

		int32_t PostWebForm(const std::string &URL, TElStringList *Fields, const std::string &FileField, const std::string &FileName, TStream *FileStream, const std::string &ContentType, bool CloseStream, const std::string &Charset);
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
		int32_t PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, TElHTTPMultipartList &PartsList);

		int32_t PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, TElHTTPMultipartList *PartsList);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
		int32_t PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, const std::string &RelatedStart, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList &PartsList);

		int32_t PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, const std::string &RelatedStart, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList *PartsList);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

#ifdef SB_USE_CLASS_TELHTTPMULTIPARTLIST
		int32_t PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, const std::string &RelatedStart, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList &PartsList, const std::string &Charset);

		int32_t PostMultipart(const std::string &URL, TSBHTTPMultipartMode MultipartMode, const std::string &RelatedStart, const std::string &RelatedStartInfo, const std::string &RelatedType, TElHTTPMultipartList *PartsList, const std::string &Charset);
#endif /* SB_USE_CLASS_TELHTTPMULTIPARTLIST */

		int32_t Put(const std::string &URL);

		int32_t Put(const std::string &URL, const std::string &Content);

		int32_t Put(const std::string &URL, const std::vector<uint8_t> &Content);

		int32_t Put(const std::string &URL, const std::vector<uint8_t> &Content, int32_t StartIndex, int32_t Count);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Put(const std::string &URL, TStream &Content, bool CloseStream);

		int32_t Put(const std::string &URL, TStream *Content, bool CloseStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void CancelRequest();

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetHeaderByName(TStringList &Headers, const std::string &Header, std::string &OutResult);

		void GetHeaderByName(TStringList *Headers, const std::string &Header, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetHeaderByName(TElStringList &Headers, const std::string &Header, std::string &OutResult);

		void GetHeaderByName(TElStringList *Headers, const std::string &Header, std::string &OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetHeadersByName(TStringList &Headers, const std::string &Header, TStringList &Res);

		void GetHeadersByName(TStringList *Headers, const std::string &Header, TStringList *Res);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetHeadersByName(TElStringList &Headers, const std::string &Header, TElStringList &Res);

		void GetHeadersByName(TElStringList *Headers, const std::string &Header, TElStringList *Res);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void SetHeaderByName(TStringList &Headers, const std::string &Header, const std::string &Value);

		void SetHeaderByName(TStringList *Headers, const std::string &Header, const std::string &Value);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void SetHeaderByName(TElStringList &Headers, const std::string &Header, const std::string &Value);

		void SetHeaderByName(TElStringList *Headers, const std::string &Header, const std::string &Value);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void SetRequestHeader(const std::string &Header, const std::string &Value);

		void ClearRequest();

		void ClearResponse();

		void ClearAuthCache();

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_RequestHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_RequestHeaders, TElHTTPSClient, RequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_RequestHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_RequestHeaders, TElHTTPSClient, RequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ResponseHeaders, TElHTTPSClient, ResponseHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_ResponseHeaders, TElHTTPSClient, ResponseHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_RequestCookies();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_RequestCookies, TElHTTPSClient, RequestCookies);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_RequestCookies();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_RequestCookies, TElHTTPSClient, RequestCookies);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ResponseCookies();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ResponseCookies, TElHTTPSClient, ResponseCookies);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ResponseCookies();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_ResponseCookies, TElHTTPSClient, ResponseCookies);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual int32_t get_ServerStatusCode();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ServerStatusCode, TElHTTPSClient, ServerStatusCode);

		virtual void get_ServerReasonPhrase(std::string &OutResult);

		virtual int64_t get_ContentLength();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ContentLength, TElHTTPSClient, ContentLength);

		virtual int64_t get_Date();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Date, TElHTTPSClient, Date);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_OutputStream();

		virtual void set_OutputStream(TStream &Value);

		virtual void set_OutputStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_OutputStream, set_OutputStream, TElHTTPSClient, OutputStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool get_SSLEnabled();

		virtual void set_SSLEnabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SSLEnabled, set_SSLEnabled, TElHTTPSClient, SSLEnabled);

#ifdef SB_USE_CLASS_TELHTTPREQUESTPARAMS
		virtual TElHTTPRequestParams* get_RequestParameters();

		virtual void set_RequestParameters(TElHTTPRequestParams &Value);

		virtual void set_RequestParameters(TElHTTPRequestParams *Value);

		SB_DECLARE_PROPERTY(TElHTTPRequestParams*, get_RequestParameters, set_RequestParameters, TElHTTPSClient, RequestParameters);
#endif /* SB_USE_CLASS_TELHTTPREQUESTPARAMS */

		virtual int32_t get_RequestCompressionLevel();

		virtual void set_RequestCompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RequestCompressionLevel, set_RequestCompressionLevel, TElHTTPSClient, RequestCompressionLevel);

		virtual bool get_RequestCompressionGZip();

		virtual void set_RequestCompressionGZip(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestCompressionGZip, set_RequestCompressionGZip, TElHTTPSClient, RequestCompressionGZip);

		virtual TSBHTTPKeepAlivePolicy get_KeepAlivePolicy();

		virtual void set_KeepAlivePolicy(TSBHTTPKeepAlivePolicy Value);

		SB_DECLARE_PROPERTY(TSBHTTPKeepAlivePolicy, get_KeepAlivePolicy, set_KeepAlivePolicy, TElHTTPSClient, KeepAlivePolicy);

		virtual int32_t get_MaxRedirections();

		virtual void set_MaxRedirections(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxRedirections, set_MaxRedirections, TElHTTPSClient, MaxRedirections);

		virtual bool get_SuppressRedirectionContent();

		virtual void set_SuppressRedirectionContent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SuppressRedirectionContent, set_SuppressRedirectionContent, TElHTTPSClient, SuppressRedirectionContent);

		virtual TSBHTTPVersion get_HTTPVersion();

		virtual void set_HTTPVersion(TSBHTTPVersion Value);

		SB_DECLARE_PROPERTY(TSBHTTPVersion, get_HTTPVersion, set_HTTPVersion, TElHTTPSClient, HTTPVersion);

		virtual bool get_UseNTLMAuth();

		virtual void set_UseNTLMAuth(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNTLMAuth, set_UseNTLMAuth, TElHTTPSClient, UseNTLMAuth);

		virtual bool get_UseDigestAuth();

		virtual void set_UseDigestAuth(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDigestAuth, set_UseDigestAuth, TElHTTPSClient, UseDigestAuth);

		virtual bool get_PersistentAuthHeader();

		virtual void set_PersistentAuthHeader(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PersistentAuthHeader, set_PersistentAuthHeader, TElHTTPSClient, PersistentAuthHeader);

		virtual bool get_ForceNTLMAuth();

		virtual void set_ForceNTLMAuth(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceNTLMAuth, set_ForceNTLMAuth, TElHTTPSClient, ForceNTLMAuth);

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElHTTPSClient, SendBufferSize);

		virtual bool get_UseCompression();

		virtual void set_UseCompression(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCompression, set_UseCompression, TElHTTPSClient, UseCompression);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElHTTPSClient, UseIPv6);
#endif

#ifdef SB_USE_CLASS_TELCOOKIEMANAGER
		virtual TElCookieManager* get_CookieManager();

		virtual void set_CookieManager(TElCookieManager &Value);

		virtual void set_CookieManager(TElCookieManager *Value);

		SB_DECLARE_PROPERTY(TElCookieManager*, get_CookieManager, set_CookieManager, TElHTTPSClient, CookieManager);
#endif /* SB_USE_CLASS_TELCOOKIEMANAGER */

		virtual bool get_Use100Continue();

		virtual void set_Use100Continue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Use100Continue, set_Use100Continue, TElHTTPSClient, Use100Continue);

#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
		virtual TElOAuth2Settings* get_OAuth2();

		virtual void set_OAuth2(TElOAuth2Settings &Value);

		virtual void set_OAuth2(TElOAuth2Settings *Value);

		SB_DECLARE_PROPERTY(TElOAuth2Settings*, get_OAuth2, set_OAuth2, TElHTTPSClient, OAuth2);
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */

#ifdef SB_USE_CLASS_TELCUSTOMSAMLADAPTER
		virtual TElCustomSAMLAdapter* get_SAMLAdapter();

		virtual void set_SAMLAdapter(TElCustomSAMLAdapter &Value);

		virtual void set_SAMLAdapter(TElCustomSAMLAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomSAMLAdapter*, get_SAMLAdapter, set_SAMLAdapter, TElHTTPSClient, SAMLAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMSAMLADAPTER */

		virtual void get_HTTPProxyUsername(std::string &OutResult);

		virtual void set_HTTPProxyUsername(const std::string &Value);

		virtual void get_HTTPProxyPassword(std::string &OutResult);

		virtual void set_HTTPProxyPassword(const std::string &Value);

		virtual void get_HTTPProxyHost(std::string &OutResult);

		virtual void set_HTTPProxyHost(const std::string &Value);

		virtual int32_t get_HTTPProxyPort();

		virtual void set_HTTPProxyPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HTTPProxyPort, set_HTTPProxyPort, TElHTTPSClient, HTTPProxyPort);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_HTTPProxyRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_HTTPProxyRequestHeaders, TElHTTPSClient, HTTPProxyRequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_HTTPProxyRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_HTTPProxyRequestHeaders, TElHTTPSClient, HTTPProxyRequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TElWebTunnelAuthentication get_HTTPProxyAuthentication();

		virtual void set_HTTPProxyAuthentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_HTTPProxyAuthentication, set_HTTPProxyAuthentication, TElHTTPSClient, HTTPProxyAuthentication);

		virtual bool get_UseHTTPProxy();

		virtual void set_UseHTTPProxy(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseHTTPProxy, set_UseHTTPProxy, TElHTTPSClient, UseHTTPProxy);

		virtual bool get_IgnoreUnknownTransferEncodings();

		virtual void set_IgnoreUnknownTransferEncodings(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreUnknownTransferEncodings, set_IgnoreUnknownTransferEncodings, TElHTTPSClient, IgnoreUnknownTransferEncodings);

		virtual void get_OnBeforeWebSocketClientUsed(TSBHTTPBeforeWebSocketClientUsedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeWebSocketClientUsed(TSBHTTPBeforeWebSocketClientUsedEvent pMethodValue, void * pDataValue);

		virtual void get_OnWebSocketConnectionEstablished(SBHTTPSClient_TSBHTTPWebSocketConnectionEstablishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWebSocketConnectionEstablished(SBHTTPSClient_TSBHTTPWebSocketConnectionEstablishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCookie(TSBHTTPCookieEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCookie(TSBHTTPCookieEvent pMethodValue, void * pDataValue);

		virtual void get_OnData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnData(TSBDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnDocumentBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDocumentBegin(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnDocumentEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDocumentEnd(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceivingHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceivingHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue);

		virtual void get_OnPreparedHeaders(TSBHTTPHeadersEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPreparedHeaders(TSBHTTPHeadersEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnRedirection(TSBHTTPRedirectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRedirection(TSBHTTPRedirectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnSendData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSendData(TSBDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnDynamicDataNeeded(TSBHTTPDynamicDataNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDynamicDataNeeded(TSBHTTPDynamicDataNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnOAuth2Browse(TSBHTTPOAuth2BrowseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOAuth2Browse(TSBHTTPOAuth2BrowseEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnsupportedTransferEncoding(TSBHTTPUnsupportedTransferEncoding &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnsupportedTransferEncoding(TSBHTTPUnsupportedTransferEncoding pMethodValue, void * pDataValue);

		virtual void get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);

		TElHTTPSClient(TElHTTPSClientHandle handle, TElOwnHandle ownHandle);

		explicit TElHTTPSClient(TComponent &AOwner);

		explicit TElHTTPSClient(TComponent *AOwner);

		virtual ~TElHTTPSClient();

};
#endif /* SB_USE_CLASS_TELHTTPSCLIENT */

#ifdef SB_USE_CLASS_SBHTTPSCLIENT_TELSTRINGVALUE
class SBHTTPSClient_TElStringValue: public TObject
{
	private:
		SB_DISABLE_COPY(SBHTTPSClient_TElStringValue)
	public:
		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		SBHTTPSClient_TElStringValue(SBHTTPSClient_TElStringValueHandle handle, TElOwnHandle ownHandle);

		explicit SBHTTPSClient_TElStringValue(const std::string &Value);

};
#endif /* SB_USE_CLASS_SBHTTPSCLIENT_TELSTRINGVALUE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPSCLIENT */
