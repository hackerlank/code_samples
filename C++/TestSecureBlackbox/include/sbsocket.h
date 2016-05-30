#ifndef __INC_SBSOCKET
#define __INC_SBSOCKET

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbhttpauth.h"
#include "sbstringlist.h"
#include "sbhttpsconstants.h"
#include "sbencoding.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssectypes.h"
#endif
#include "sbpunycode.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_SOCKET 	94208
#define SB_ERROR_SOCKET_PROTOCOL_ERROR_FLAG 	2048
#define SB_SOCKET_ERROR_WINSOCK_INIT_FAILED 	96257
#define SB_SOCKET_ERROR_WRONG_SOCKET_STATE 	96258
#define SB_SOCKET_ERROR_NOT_A_SOCKET 	96259
#define SB_SOCKET_ERROR_INVALID_ADDRESS 	96260
#define SB_SOCKET_ERROR_ACCEPT_FAILED 	96261
#define SB_SOCKET_ERROR_ADDRESS_FAMILY_MISMATCH 	96262
#define SB_SOCKET_ERROR_INVALID_SOCKET_TYPE 	96263
#define SB_SOCKET_ERROR_SOCKS_NEGOTIATION_FAILED 	96264
#define SB_SOCKET_ERROR_SOCKS_AUTH_FAILED 	96265
#define SB_SOCKET_ERROR_SOCKS_FAILED_TO_RESOLVE_DESTINATION_ADDRESS 	96266
#define SB_SOCKET_ERROR_DNS_SECURITY_FAILURE 	96267
#define SB_SOCKET_ERROR_DNS_TIMEOUT 	96268
#define SB_SOCKET_ERROR_WEBTUNNEL_NEGOTIATION_FAILED 	96269
#define SB_SOCKET_ERROR_TIMEOUT 	96270
#define SB__SSALIGNSIZE 	8
#define SB__SSMAXSIZE 	128
#define SB__SSPAD1SIZE 	6
#define SB__SSPAD2SIZE 	112
#ifdef SB_WINDOWS
#define SB_AF_INET6 	23
#define SB_INVALID_SOCKET 	-1
#define SB_SOCKET_ERROR_CODE_TIMEDOUT 	10060
#endif
#ifdef LINUX
#define SB_MSG_NOSIGNAL 	16384
#endif
#ifdef MACOS
#define SB_SO_NOSIGPIPE 	4130
#endif
#ifndef SB_WINDOWS
#define SB_SOCKET_ERROR_CODE_TIMEDOUT 	110
#endif
#define SB_SOCKET_ERROR_CODE_WOULDBLOCK 	10035
#ifdef SB_WINDOWS
#define SB_SOCKET_ERROR_CODE_CONNRESET 	10054
#define SB_SOCKET_ERROR_CODE_ADDRINUSE 	10048
#define SB_SOCKET_ERROR_CODE_ISCONN 	10056
#define SB_SOCKET_ERROR_CODE_INPROGRESS 	10036
#define SB_SOCKET_ERROR_CODE_SHUTDOWN 	10058
#else
#define SB_SOCKET_ERROR_CODE_CONNRESET 	104
#define SB_SOCKET_ERROR_CODE_ADDRINUSE 	10022
#define SB_SOCKET_ERROR_CODE_ISCONN 	106
#define SB_SOCKET_ERROR_CODE_INPROGRESS 	115
#define SB_SOCKET_ERROR_CODE_SHUTDOWN 	108
#endif

typedef TElClassHandle TElSocketHandle;

typedef TElClassHandle TElCustomSocketBindingHandle;

typedef TElCustomSocketBindingHandle ElCustomSocketBindingHandle;

typedef TElClassHandle TElClientSocketBindingHandle;

typedef TElClientSocketBindingHandle TElSocketBindingHandle;

typedef TElClientSocketBindingHandle ElClientSocketBindingHandle;

typedef TElClientSocketBindingHandle ElSocketBindingHandle;

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef TElClassHandle TElDNSSettingsHandle;
#else
typedef TElClassHandle TElSocketSettingsHandle;
#endif

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef TElClassHandle TElSocketSettingsHandle;

typedef uint8_t TElShutdownDirectionRaw;

typedef enum
{
	sdReceive = 0,
	sdSend = 1,
	sdSendAndReceive = 2
} TElShutdownDirection;

typedef uint8_t TElSocketStateRaw;

typedef enum
{
	issNotASocket = 0,
	issInitializing = 1,
	issInitialized = 2,
	issBound = 3,
	issConnected = 4,
	issListening = 5,
	issConnecting = 6
} TElSocketState;

typedef uint8_t TElSocketTypeRaw;

typedef enum
{
	istStream = 0,
	istDatagram = 1
} TElSocketType;

typedef uint8_t TElSocksVersionRaw;

typedef enum
{
	elSocks4 = 0,
	elSocks5 = 1
} TElSocksVersion;

typedef uint8_t TElSocksAuthenticationRaw;

typedef enum
{
	saNoAuthentication = 0,
	saUsercode = 1
} TElSocksAuthentication;

typedef uint8_t TElWebTunnelAuthenticationRaw;

typedef enum
{
	wtaNoAuthentication = 0,
	wtaBasic = 1,
	wtaDigest = 2,
	wtaNTLM = 3
} TElWebTunnelAuthentication;

typedef uint8_t TElBandwidthPolicyRaw;

typedef enum
{
	bpFlexible = 0,
	bpStrict = 1
} TElBandwidthPolicy;

#else
typedef uint8_t TElShutdownDirectionRaw;

typedef enum
{
	sdReceive = 0,
	sdSend = 1,
	sdSendAndReceive = 2
} TElShutdownDirection;

typedef uint8_t TElSocketStateRaw;

typedef enum
{
	issNotASocket = 0,
	issInitializing = 1,
	issInitialized = 2,
	issBound = 3,
	issConnected = 4,
	issListening = 5,
	issConnecting = 6
} TElSocketState;

typedef uint8_t TElSocketTypeRaw;

typedef enum
{
	istStream = 0,
	istDatagram = 1
} TElSocketType;

typedef uint8_t TElSocksVersionRaw;

typedef enum
{
	elSocks4 = 0,
	elSocks5 = 1
} TElSocksVersion;

typedef uint8_t TElSocksAuthenticationRaw;

typedef enum
{
	saNoAuthentication = 0,
	saUsercode = 1
} TElSocksAuthentication;

typedef uint8_t TElWebTunnelAuthenticationRaw;

typedef enum
{
	wtaNoAuthentication = 0,
	wtaBasic = 1,
	wtaDigest = 2,
	wtaNTLM = 3
} TElWebTunnelAuthentication;

typedef uint8_t TElBandwidthPolicyRaw;

typedef enum
{
	bpFlexible = 0,
	bpStrict = 1
} TElBandwidthPolicy;

#ifndef WINCE
typedef sockaddr_in TSockAddrIn;

typedef uint32_t * PSOCKLEN_T;

#pragma pack(4)
typedef struct 
{
	char * h_name;
	char * (* h_aliases);
	int32_t h_addrtype;
	uint32_t h_length;
	union
	{
		struct
		{
			int64_t _dummy0;
			int64_t _dummy1;
			char * (* h_addr_list);
		} S1;
		struct
		{
			int64_t _dummy0;
			int64_t _dummy1;
			char * (* h_addr);
		} S2;
	};
} hostent, * Phostent;

typedef uint32_t * Pin_addr_t;
#endif
#endif

#pragma pack(1)
typedef struct 
{
	uint16_t ss_family;
	uint8_t __ss_pad1[6];
	int64_t __ss_align;
	uint8_t __ss_pad2[112];
} sockaddr_storage, * PSockAddrStorage;

typedef sockaddr_storage TSockAddrStorage;

typedef void (SB_CALLBACK *TSBSocksAuthMethodChooseEvent)(void * _ObjectData, TObjectHandle Sender, const TElSocksAuthenticationRaw pAuthMethods[], int32_t szAuthMethods, TElSocksAuthenticationRaw * AuthMethod, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBSocksAuthPasswordEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, int8_t * Accept);

typedef void (SB_CALLBACK *TSBSocksConnectEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcDestHost, int32_t szDestHost, int32_t DestPort, int8_t * Allow);

typedef void (SB_CALLBACK *TElSocketSecondaryEvent)(void * _ObjectData, TObjectHandle Sender, TElSocketHandle Socket, int32_t State, int8_t * AbortConnect);

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef void (SB_CALLBACK *TSBDNSResolveEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcHostName, int32_t szHostName, TElDNSResourceRecordSetHandle Response, int32_t ResolveResult, TSBDNSSecurityStatusRaw SecurityStatus);
#endif
#ifndef SB_WINDOWS
typedef in_addr * Pin_addr;
#endif

#ifndef SB_WINDOWS
typedef psockaddr_in PSockAddrIn;

typedef Phostent (* PPhostent);
#endif

#ifdef SB_USE_CLASS_TELSOCKET
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSocket_LoadIPv6Proc(const char * pcProcName, int32_t szProcName, void * * Proc, int32_t * WinsockUsed, int32_t * Wship6Used, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_LoadIPv6Proc_1(TElSocketHandle _Handle, const char * pcProcName, int32_t szProcName, void * * Proc, int32_t * WinsockUsed, int32_t * Wship6Used, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_InitializeIPv6();
SB_IMPORT uint32_t SB_APIENTRY TElSocket_InitializeIPv6_1(TElSocketHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_FinalizeIPv6();
SB_IMPORT uint32_t SB_APIENTRY TElSocket_FinalizeIPv6_1(TElSocketHandle _Handle);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSocket_ShutdownSocket(TElSocketHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_ShutdownSocket_1(TElSocketHandle _Handle, TElShutdownDirectionRaw Direction);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Close(TElSocketHandle _Handle, int8_t Forced);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Close_1(TElSocketHandle _Handle, int8_t Forced, int32_t Timeout);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Close_2(TElSocketHandle _Handle, int8_t Forced, int32_t Timeout, int8_t Gradually);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_StartAsyncConnect(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_AsyncConnect(TElSocketHandle _Handle, int32_t Timeout, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_FinalizeWinSock();
SB_IMPORT uint32_t SB_APIENTRY TElSocket_FinalizeWinSock_1(TElSocketHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_InitializeWinSock();
SB_IMPORT uint32_t SB_APIENTRY TElSocket_InitializeWinSock_1(TElSocketHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_LastNetError(TElSocketHandle _Handle, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSocket_IPFromHost(TElSocketHandle _Handle, const char * pcHost, int32_t szHost, int8_t UseIPv6, char * pcOutResult, int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSocket_IPFromHost(TElSocketHandle _Handle, const char * pcHost, int32_t szHost, char * pcOutResult, int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Receive(TElSocketHandle _Handle, void * Data, int32_t DataLen, int32_t * Received, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Send(TElSocketHandle _Handle, void * Data, int32_t DataLen, int32_t * Sent, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_ReceiveFrom(TElSocketHandle _Handle, void * Data, int32_t DataLen, int32_t * Received, char * pcRemoteAddress, int32_t * szRemoteAddress, uint16_t * RemotePort, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_SendTo(TElSocketHandle _Handle, void * Data, int32_t DataLen, int32_t * Sent, const char * pcRemoteAddress, int32_t szRemoteAddress, uint16_t RemotePort, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_ApplySettings(TElSocketHandle _Handle, TElSocketSettingsHandle Settings);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Connect(TElSocketHandle _Handle, int32_t Timeout, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_CanReceive(TElSocketHandle _Handle, int32_t WaitTime, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_CanSend(TElSocketHandle _Handle, int32_t WaitTime, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_CanAccept(TElSocketHandle _Handle, int32_t WaitTime, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Bind(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Bind_1(TElSocketHandle _Handle, int8_t Outgoing, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Bind_2(TElSocketHandle _Handle, int8_t Outgoing, int8_t ReuseAddress, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Listen(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Accept(TElSocketHandle _Handle, int32_t Timeout, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Accept_1(TElSocketHandle _Handle, int32_t Timeout, TElSocketHandle * Socket);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_AsyncConnectEx(TElSocketHandle _Handle, int32_t Timeout, TElSocketHandle SecondarySocket, int8_t SecSend, int8_t SecRecv, TElSocketSecondaryEvent pMethodSecEvent, void * pDataSecEvent, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_SocksAccept(TElSocketHandle _Handle, int32_t Timeout, TSBSocksAuthMethodChooseEvent pMethodOnAuthMethodChoose, void * pDataOnAuthMethodChoose, TSBSocksAuthPasswordEvent pMethodOnAuthPassword, void * pDataOnAuthPassword, TSBSocksConnectEvent pMethodOnConnect, void * pDataOnConnect, int8_t CloseConnectionOnError, int8_t ResolveAddress);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_LocalHostName(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_RemoteAddress(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_ProxyResult(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocketType(TElSocketHandle _Handle, TElSocketTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocketType(TElSocketHandle _Handle, TElSocketTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_State(TElSocketHandle _Handle, TElSocketStateRaw * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_UsingIPv6(TElSocketHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_BoundPort(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_BoundAddress(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_NativeSocket(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_Address(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_Address(TElSocketHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_Port(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_Port(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_ListenPort(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_ListenPort(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_ListenPortRangeFrom(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_ListenPortRangeFrom(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_ListenPortRangeTo(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_ListenPortRangeTo(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_ListenAddress(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_ListenAddress(TElSocketHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_ListenBinding(TElSocketHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_ListenBinding(TElSocketHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_OutgoingLocalBinding(TElSocketHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_OutgoingLocalBinding(TElSocketHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_IncomingSpeedLimit(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_IncomingSpeedLimit(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_OutgoingSpeedLimit(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_OutgoingSpeedLimit(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocksAuthentication(TElSocketHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocksAuthentication(TElSocketHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocksPassword(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocksPassword(TElSocketHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocksPort(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocksPort(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocksResolveAddress(TElSocketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocksResolveAddress(TElSocketHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocksServer(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocksServer(TElSocketHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocksUseIPv6(TElSocketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocksUseIPv6(TElSocketHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocksUserCode(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocksUserCode(TElSocketHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SocksVersion(TElSocketHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SocksVersion(TElSocketHandle _Handle, TElSocksVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_UseSocks(TElSocketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_UseSocks(TElSocketHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_UseIPv6(TElSocketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_UseIPv6(TElSocketHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_UseNagle(TElSocketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_UseNagle(TElSocketHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_UseWebTunneling(TElSocketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_UseWebTunneling(TElSocketHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelAddress(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_WebTunnelAddress(TElSocketHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelAuthentication(TElSocketHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_WebTunnelAuthentication(TElSocketHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelPassword(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_WebTunnelPassword(TElSocketHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelPort(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_WebTunnelPort(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelUserId(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_WebTunnelUserId(TElSocketHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelRequestHeaders(TElSocketHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_WebTunnelRequestHeaders(TElSocketHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelResponseHeaders(TElSocketHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelRequestHeaders(TElSocketHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_WebTunnelRequestHeaders(TElSocketHandle _Handle, TElStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelResponseHeaders(TElSocketHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_WebTunnelResponseBody(TElSocketHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_AutoAdjustBuffersSize(TElSocketHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_AutoAdjustBuffersSize(TElSocketHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_MinBufferSize(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_MinBufferSize(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_MaxBufferSize(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_MaxBufferSize(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_BuffersAdjustStep(TElSocketHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_BuffersAdjustStep(TElSocketHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_SendBufferSize(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_SendBufferSize(TElSocketHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_RecvBufferSize(TElSocketHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_RecvBufferSize(TElSocketHandle _Handle, int32_t Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_DNS(TElSocketHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_DNS(TElSocketHandle _Handle, TElDNSSettingsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_OnDNSKeyNeeded(TElSocketHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_OnDNSKeyNeeded(TElSocketHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_OnDNSKeyValidate(TElSocketHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_OnDNSKeyValidate(TElSocketHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_get_OnDNSResolve(TElSocketHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_set_OnDNSResolve(TElSocketHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Create(TComponentHandle Owner, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocket_Create_1(TElSocketHandle * OutResult);
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELCUSTOMSOCKETBINDING
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketBinding_Assign(TElCustomSocketBindingHandle _Handle, TElCustomSocketBindingHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketBinding_get_LocalIntfAddress(TElCustomSocketBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketBinding_set_LocalIntfAddress(TElCustomSocketBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketBinding_get_Port(TElCustomSocketBindingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketBinding_set_Port(TElCustomSocketBindingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketBinding_get_ReuseAddress(TElCustomSocketBindingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketBinding_set_ReuseAddress(TElCustomSocketBindingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSocketBinding_Create(TElCustomSocketBindingHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
SB_IMPORT uint32_t SB_APIENTRY TElClientSocketBinding_Assign(TElClientSocketBindingHandle _Handle, TElCustomSocketBindingHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElClientSocketBinding_get_PortRangeFrom(TElClientSocketBindingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSocketBinding_set_PortRangeFrom(TElClientSocketBindingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElClientSocketBinding_get_PortRangeTo(TElClientSocketBindingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSocketBinding_set_PortRangeTo(TElClientSocketBindingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElClientSocketBinding_Create(TElClientSocketBindingHandle * OutResult);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_Assign(TElDNSSettingsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_ResolveHostName(TElDNSSettingsHandle _Handle, const char * pcHostName, int32_t szHostName, int8_t UseIPv6, sockaddr_storage * Addr, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_get_AllowStatuses(TElDNSSettingsHandle _Handle, TSBDNSSecurityStatusesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_set_AllowStatuses(TElDNSSettingsHandle _Handle, TSBDNSSecurityStatusesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_get_Enabled(TElDNSSettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_set_Enabled(TElDNSSettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_get_Port(TElDNSSettingsHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_set_Port(TElDNSSettingsHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_get_Servers(TElDNSSettingsHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_set_Servers(TElDNSSettingsHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_get_QueryTimeout(TElDNSSettingsHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_set_QueryTimeout(TElDNSSettingsHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_get_TotalTimeout(TElDNSSettingsHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_set_TotalTimeout(TElDNSSettingsHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_get_UseIPv6(TElDNSSettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_set_UseIPv6(TElDNSSettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_get_UseSecurity(TElDNSSettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_set_UseSecurity(TElDNSSettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSettings_Create(TElDNSSettingsHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_get_AutoAdjustBuffersSize(TElSocketSettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_set_AutoAdjustBuffersSize(TElSocketSettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_get_MinBufferSize(TElSocketSettingsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_set_MinBufferSize(TElSocketSettingsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_get_MaxBufferSize(TElSocketSettingsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_set_MaxBufferSize(TElSocketSettingsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_get_BuffersAdjustStep(TElSocketSettingsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_set_BuffersAdjustStep(TElSocketSettingsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_get_SendBufferSize(TElSocketSettingsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_set_SendBufferSize(TElSocketSettingsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_get_RecvBufferSize(TElSocketSettingsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_set_RecvBufferSize(TElSocketSettingsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_get_UseNagle(TElSocketSettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_set_UseNagle(TElSocketSettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSocketSettings_Create(TElSocketHandle Socket, TElSocketSettingsHandle * OutResult);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSocket;
class TElCustomSocketBinding;
typedef TElCustomSocketBinding ElCustomSocketBinding;
class TElClientSocketBinding;
typedef TElClientSocketBinding TElSocketBinding;
typedef TElClientSocketBinding ElClientSocketBinding;
typedef TElClientSocketBinding ElSocketBinding;
#ifndef SB_WINCE_OR_NOT_WINDOWS
class TElDNSSettings;
#endif
class TElSocketSettings;

#ifdef SB_USE_CLASS_TELSOCKET
class TElSocket: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSocket)
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_ListenBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_OutgoingLocalBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_WebTunnelRequestHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_WebTunnelResponseHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifndef WINCE
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		TElDNSSettings* _Inst_DNS;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_WebTunnelRequestHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_WebTunnelResponseHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_WINDOWS
		static bool LoadIPv6Proc(const std::string &ProcName, void * &Proc, int32_t &WinsockUsed, int32_t &Wship6Used);

		bool LoadIPv6Proc_Inst(const std::string &ProcName, void * &Proc, int32_t &WinsockUsed, int32_t &Wship6Used);

		static void InitializeIPv6();

		void InitializeIPv6_Inst();

		static void FinalizeIPv6();

		void FinalizeIPv6_Inst();
#endif

		void ShutdownSocket();

		void ShutdownSocket(TElShutdownDirection Direction);

		void Close(bool Forced);

		void Close(bool Forced, int32_t Timeout);

		void Close(bool Forced, int32_t Timeout, bool Gradually);

		int32_t StartAsyncConnect();

		int32_t AsyncConnect(int32_t Timeout);

		static void FinalizeWinSock();

		void FinalizeWinSock_Inst();

		static void InitializeWinSock();

		void InitializeWinSock_Inst();

		int32_t LastNetError();

#ifdef SB_WINDOWS
		void IPFromHost(const std::string &Host, bool UseIPv6, std::string &OutResult);
#else
		void IPFromHost(const std::string &Host, std::string &OutResult);
#endif

		int32_t Receive(void * Data, int32_t DataLen, int32_t &Received);

		int32_t Send(void * Data, int32_t DataLen, int32_t &Sent);

		int32_t ReceiveFrom(void * Data, int32_t DataLen, int32_t &Received, std::string &RemoteAddress, uint16_t &RemotePort);

		int32_t SendTo(void * Data, int32_t DataLen, int32_t &Sent, const std::string &RemoteAddress, uint16_t RemotePort);

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		void ApplySettings(TElSocketSettings &Settings);

		void ApplySettings(TElSocketSettings *Settings);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

		int32_t Connect(int32_t Timeout);

		bool CanReceive(int32_t WaitTime);

		bool CanSend(int32_t WaitTime);

		bool CanAccept(int32_t WaitTime);

		int32_t Bind();

		int32_t Bind(bool Outgoing);

		int32_t Bind(bool Outgoing, bool ReuseAddress);

		int32_t Listen();

		int32_t Accept(int32_t Timeout);

		void Accept(int32_t Timeout, TElSocket &Socket);

		int32_t AsyncConnectEx(int32_t Timeout, TElSocket &SecondarySocket, bool SecSend, bool SecRecv, TElSocketSecondaryEvent pMethodSecEvent, void * pDataSecEvent);

		int32_t AsyncConnectEx(int32_t Timeout, TElSocket *SecondarySocket, bool SecSend, bool SecRecv, TElSocketSecondaryEvent pMethodSecEvent, void * pDataSecEvent);

		void SocksAccept(int32_t Timeout, TSBSocksAuthMethodChooseEvent pMethodOnAuthMethodChoose, void * pDataOnAuthMethodChoose, TSBSocksAuthPasswordEvent pMethodOnAuthPassword, void * pDataOnAuthPassword, TSBSocksConnectEvent pMethodOnConnect, void * pDataOnConnect, bool CloseConnectionOnError, bool ResolveAddress);

		virtual void get_LocalHostName(std::string &OutResult);

		virtual void get_RemoteAddress(std::string &OutResult);

		virtual int32_t get_ProxyResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ProxyResult, TElSocket, ProxyResult);

		virtual TElSocketType get_SocketType();

		virtual void set_SocketType(TElSocketType Value);

		SB_DECLARE_PROPERTY(TElSocketType, get_SocketType, set_SocketType, TElSocket, SocketType);

		virtual TElSocketState get_State();

		SB_DECLARE_PROPERTY_GET(TElSocketState, get_State, TElSocket, State);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElSocket, UsingIPv6);
#endif

		virtual int32_t get_BoundPort();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BoundPort, TElSocket, BoundPort);

		virtual void get_BoundAddress(std::string &OutResult);

		virtual int32_t get_NativeSocket();

		SB_DECLARE_PROPERTY_GET(int32_t, get_NativeSocket, TElSocket, NativeSocket);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSocket, Port);

		virtual int32_t get_ListenPort();

		virtual void set_ListenPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ListenPort, set_ListenPort, TElSocket, ListenPort);

		virtual int32_t get_ListenPortRangeFrom();

		virtual void set_ListenPortRangeFrom(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ListenPortRangeFrom, set_ListenPortRangeFrom, TElSocket, ListenPortRangeFrom);

		virtual int32_t get_ListenPortRangeTo();

		virtual void set_ListenPortRangeTo(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ListenPortRangeTo, set_ListenPortRangeTo, TElSocket, ListenPortRangeTo);

		virtual void get_ListenAddress(std::string &OutResult);

		virtual void set_ListenAddress(const std::string &Value);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_ListenBinding();

		virtual void set_ListenBinding(TElClientSocketBinding &Value);

		virtual void set_ListenBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_ListenBinding, set_ListenBinding, TElSocket, ListenBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_OutgoingLocalBinding();

		virtual void set_OutgoingLocalBinding(TElClientSocketBinding &Value);

		virtual void set_OutgoingLocalBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_OutgoingLocalBinding, set_OutgoingLocalBinding, TElSocket, OutgoingLocalBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElSocket, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElSocket, OutgoingSpeedLimit);

		virtual TElSocksAuthentication get_SocksAuthentication();

		virtual void set_SocksAuthentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_SocksAuthentication, set_SocksAuthentication, TElSocket, SocksAuthentication);

		virtual void get_SocksPassword(std::string &OutResult);

		virtual void set_SocksPassword(const std::string &Value);

		virtual int32_t get_SocksPort();

		virtual void set_SocksPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocksPort, set_SocksPort, TElSocket, SocksPort);

		virtual bool get_SocksResolveAddress();

		virtual void set_SocksResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksResolveAddress, set_SocksResolveAddress, TElSocket, SocksResolveAddress);

		virtual void get_SocksServer(std::string &OutResult);

		virtual void set_SocksServer(const std::string &Value);

#ifdef SB_WINDOWS
		virtual bool get_SocksUseIPv6();

		virtual void set_SocksUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksUseIPv6, set_SocksUseIPv6, TElSocket, SocksUseIPv6);
#endif

		virtual void get_SocksUserCode(std::string &OutResult);

		virtual void set_SocksUserCode(const std::string &Value);

		virtual TElSocksVersion get_SocksVersion();

		virtual void set_SocksVersion(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_SocksVersion, set_SocksVersion, TElSocket, SocksVersion);

		virtual bool get_UseSocks();

		virtual void set_UseSocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSocks, set_UseSocks, TElSocket, UseSocks);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElSocket, UseIPv6);
#endif

		virtual bool get_UseNagle();

		virtual void set_UseNagle(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNagle, set_UseNagle, TElSocket, UseNagle);

		virtual bool get_UseWebTunneling();

		virtual void set_UseWebTunneling(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseWebTunneling, set_UseWebTunneling, TElSocket, UseWebTunneling);

		virtual void get_WebTunnelAddress(std::string &OutResult);

		virtual void set_WebTunnelAddress(const std::string &Value);

		virtual TElWebTunnelAuthentication get_WebTunnelAuthentication();

		virtual void set_WebTunnelAuthentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_WebTunnelAuthentication, set_WebTunnelAuthentication, TElSocket, WebTunnelAuthentication);

		virtual void get_WebTunnelPassword(std::string &OutResult);

		virtual void set_WebTunnelPassword(const std::string &Value);

		virtual int32_t get_WebTunnelPort();

		virtual void set_WebTunnelPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_WebTunnelPort, set_WebTunnelPort, TElSocket, WebTunnelPort);

		virtual void get_WebTunnelUserId(std::string &OutResult);

		virtual void set_WebTunnelUserId(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelRequestHeaders();

		virtual void set_WebTunnelRequestHeaders(TStringList &Value);

		virtual void set_WebTunnelRequestHeaders(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_WebTunnelRequestHeaders, set_WebTunnelRequestHeaders, TElSocket, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelRequestHeaders();

		virtual void set_WebTunnelRequestHeaders(TElStringList &Value);

		virtual void set_WebTunnelRequestHeaders(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_WebTunnelRequestHeaders, set_WebTunnelRequestHeaders, TElSocket, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelResponseHeaders, TElSocket, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelResponseHeaders, TElSocket, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_WebTunnelResponseBody(std::string &OutResult);

		virtual bool get_AutoAdjustBuffersSize();

		virtual void set_AutoAdjustBuffersSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustBuffersSize, set_AutoAdjustBuffersSize, TElSocket, AutoAdjustBuffersSize);

		virtual int32_t get_MinBufferSize();

		virtual void set_MinBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinBufferSize, set_MinBufferSize, TElSocket, MinBufferSize);

		virtual int32_t get_MaxBufferSize();

		virtual void set_MaxBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxBufferSize, set_MaxBufferSize, TElSocket, MaxBufferSize);

		virtual double get_BuffersAdjustStep();

		virtual void set_BuffersAdjustStep(double Value);

		SB_DECLARE_PROPERTY(double, get_BuffersAdjustStep, set_BuffersAdjustStep, TElSocket, BuffersAdjustStep);

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElSocket, SendBufferSize);

		virtual int32_t get_RecvBufferSize();

		virtual void set_RecvBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RecvBufferSize, set_RecvBufferSize, TElSocket, RecvBufferSize);

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElSocket, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */

		virtual void get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElSocket(TElSocketHandle handle, TElOwnHandle ownHandle);

		explicit TElSocket(TComponent &Owner);

		explicit TElSocket(TComponent *Owner);

		TElSocket();

		virtual ~TElSocket();

};
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELCUSTOMSOCKETBINDING
class TElCustomSocketBinding: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElCustomSocketBinding)
	public:
		virtual void Assign(TElCustomSocketBinding &Source);

		virtual void Assign(TElCustomSocketBinding *Source);

		virtual void get_LocalIntfAddress(std::string &OutResult);

		virtual void set_LocalIntfAddress(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElCustomSocketBinding, Port);

		virtual bool get_ReuseAddress();

		virtual void set_ReuseAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReuseAddress, set_ReuseAddress, TElCustomSocketBinding, ReuseAddress);

		TElCustomSocketBinding(TElCustomSocketBindingHandle handle, TElOwnHandle ownHandle);

		TElCustomSocketBinding();

};
#endif /* SB_USE_CLASS_TELCUSTOMSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
class TElClientSocketBinding: public TElCustomSocketBinding
{
	private:
		SB_DISABLE_COPY(TElClientSocketBinding)
	public:
		virtual void Assign(TElCustomSocketBinding &Source);

		virtual void Assign(TElCustomSocketBinding *Source);

		virtual int32_t get_PortRangeFrom();

		virtual void set_PortRangeFrom(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PortRangeFrom, set_PortRangeFrom, TElClientSocketBinding, PortRangeFrom);

		virtual int32_t get_PortRangeTo();

		virtual void set_PortRangeTo(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PortRangeTo, set_PortRangeTo, TElClientSocketBinding, PortRangeTo);

		TElClientSocketBinding(TElClientSocketBindingHandle handle, TElOwnHandle ownHandle);

		TElClientSocketBinding();

};
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
class TElDNSSettings: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDNSSettings)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Servers;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		bool ResolveHostName(const std::string &HostName, bool UseIPv6, sockaddr_storage &Addr);

		virtual TSBDNSSecurityStatuses get_AllowStatuses();

		virtual void set_AllowStatuses(TSBDNSSecurityStatuses Value);

		SB_DECLARE_PROPERTY(TSBDNSSecurityStatuses, get_AllowStatuses, set_AllowStatuses, TElDNSSettings, AllowStatuses);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElDNSSettings, Enabled);

		virtual uint16_t get_Port();

		virtual void set_Port(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Port, set_Port, TElDNSSettings, Port);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Servers();

		virtual void set_Servers(TStringList &Value);

		virtual void set_Servers(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_Servers, set_Servers, TElDNSSettings, Servers);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual uint16_t get_QueryTimeout();

		virtual void set_QueryTimeout(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_QueryTimeout, set_QueryTimeout, TElDNSSettings, QueryTimeout);

		virtual uint16_t get_TotalTimeout();

		virtual void set_TotalTimeout(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_TotalTimeout, set_TotalTimeout, TElDNSSettings, TotalTimeout);

		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElDNSSettings, UseIPv6);

		virtual bool get_UseSecurity();

		virtual void set_UseSecurity(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSecurity, set_UseSecurity, TElDNSSettings, UseSecurity);

		TElDNSSettings(TElDNSSettingsHandle handle, TElOwnHandle ownHandle);

		TElDNSSettings();

		virtual ~TElDNSSettings();

};
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
class TElSocketSettings: public TObject
{
	private:
		SB_DISABLE_COPY(TElSocketSettings)
	public:
		virtual bool get_AutoAdjustBuffersSize();

		virtual void set_AutoAdjustBuffersSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustBuffersSize, set_AutoAdjustBuffersSize, TElSocketSettings, AutoAdjustBuffersSize);

		virtual int32_t get_MinBufferSize();

		virtual void set_MinBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinBufferSize, set_MinBufferSize, TElSocketSettings, MinBufferSize);

		virtual int32_t get_MaxBufferSize();

		virtual void set_MaxBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxBufferSize, set_MaxBufferSize, TElSocketSettings, MaxBufferSize);

		virtual double get_BuffersAdjustStep();

		virtual void set_BuffersAdjustStep(double Value);

		SB_DECLARE_PROPERTY(double, get_BuffersAdjustStep, set_BuffersAdjustStep, TElSocketSettings, BuffersAdjustStep);

		virtual int32_t get_SendBufferSize();

		virtual void set_SendBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SendBufferSize, set_SendBufferSize, TElSocketSettings, SendBufferSize);

		virtual int32_t get_RecvBufferSize();

		virtual void set_RecvBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RecvBufferSize, set_RecvBufferSize, TElSocketSettings, RecvBufferSize);

		virtual bool get_UseNagle();

		virtual void set_UseNagle(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNagle, set_UseNagle, TElSocketSettings, UseNagle);

		TElSocketSettings(TElSocketSettingsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSOCKET
		explicit TElSocketSettings(TElSocket &Socket);

		explicit TElSocketSettings(TElSocket *Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

};
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

#ifdef SB_USE_GLOBAL_PROCS_SOCKET

bool AddressToString(const sockaddr_storage &Addr, std::string &S);

bool StringToAddress(const std::string &S, sockaddr_storage &Addr);

#ifdef SB_WINDOWS
bool IsIPv6Address(const std::string &S);
#endif

#endif /* SB_USE_GLOBAL_PROCS_SOCKET */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SOCKET
SB_IMPORT uint32_t SB_APIENTRY SBSocket_AddressToString(const sockaddr_storage * Addr, char * pcS, int32_t * szS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSocket_StringToAddress(const char * pcS, int32_t szS, sockaddr_storage * Addr, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBSocket_IsIPv6Address(const char * pcS, int32_t szS, int8_t * OutResult);
#endif
#endif /* SB_USE_GLOBAL_PROCS_SOCKET */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSOCKET */
