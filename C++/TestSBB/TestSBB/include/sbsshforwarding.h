#ifndef __INC_SBSSHFORWARDING
#define __INC_SBSSHFORWARDING

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbsshcommon.h"
#include "sbsshclient.h"
#include "sbsshkeystorage.h"
#include "sbsharedresource.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssectypes.h"
#include "sbdnssecutils.h"
#endif
#include "sbgssapibase.h"
#include "sbgssapi.h"
#include "sbsocket.h"
#include "sbportknock.h"
#include "sbsshconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_SSH_TCP_CONNECTION_FAILED 	24577
#define SB_ERROR_SSH_TCP_BIND_FAILED 	24578

typedef TElClassHandle TElSSHForwardedConnectionHandle;

typedef TElSSHForwardedConnectionHandle ElSSHForwardedConnectionHandle;

typedef TElClassHandle TElSSHForwardingTunnelHandle;

typedef TElClassHandle TElSSHForwardingSessionHandle;

typedef TElSSHForwardingSessionHandle ElSSHForwardingSessionHandle;

typedef TElClassHandle TElSSHCustomForwardingHandle;

typedef TElSSHCustomForwardingHandle ElSSHCustomForwardingHandle;

typedef TElClassHandle TElSSHForwardingInterceptHandle;

typedef TElClassHandle TElSSHLocalPortForwardingHandle;

typedef TElSSHLocalPortForwardingHandle ElSSHLocalPortForwardingHandle;

typedef TElClassHandle TElSSHRemotePortForwardingHandle;

typedef TElSSHRemotePortForwardingHandle ElSSHRemotePortForwardingHandle;

typedef TElClassHandle TElSSHTunnelStateHandle;

typedef TElClassHandle TElSSHLPFListeningThreadHandle;

typedef TElClassHandle TElSSHLocalTunnelStateHandle;

typedef TElClassHandle TElSSHRemoteTunnelStateHandle;

typedef TElClassHandle TElSSHLocalPortForwardingSessionHandle;

typedef TElSSHLocalPortForwardingSessionHandle ElSSHLocalPortForwardingSessionHandle;

typedef TElClassHandle TElSSHRemotePortForwardingSessionHandle;

typedef TElSSHRemotePortForwardingSessionHandle ElSSHRemotePortForwardingSessionHandle;

typedef TElClassHandle TElSSHScheduledSpecialMessageHandle;

typedef void (SB_CALLBACK *TSBSSHConnectionEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHForwardedConnectionHandle Conn);

typedef void (SB_CALLBACK *TSBSSHConnectionErrorEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHForwardedConnectionHandle Conn, int32_t ErrorCode);

typedef void (SB_CALLBACK *TSBSSHTunnelEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHForwardingTunnelHandle Tunnel);

typedef void (SB_CALLBACK *TSBSSHLPFAcceptEvent)(void * _ObjectData, TObjectHandle Sender, TElSocketHandle Socket);

typedef void (SB_CALLBACK *TSBSSHSocketAcceptEvent)(void * _ObjectData, TObjectHandle Sender, TElSocketHandle Socket, int8_t * Reject);

typedef void (SB_CALLBACK *TSBSSHSocksAuthMethodChooseEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHForwardedConnectionHandle Conn, const TElSocksAuthenticationRaw pAuthMethods[], int32_t szAuthMethods, TElSocksAuthenticationRaw * AuthMethod, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBSSHSocksAuthPasswordEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHForwardedConnectionHandle Conn, const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, int8_t * Accept);

typedef void (SB_CALLBACK *TSBSSHSocksConnectEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHForwardedConnectionHandle Conn, const char * pcDestHost, int32_t szDestHost, int32_t DestPort, int8_t * Allow);

typedef void (SB_CALLBACK *TSBSSHBeforeConnectingEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHClientHandle Client, TElSocketHandle Socket);

typedef uint8_t TSBSSHForwardingPriorityRaw;

typedef enum
{
	sfpLow = 0,
	sfpNormal = 1,
	sfpHigh = 2
} TSBSSHForwardingPriority;

typedef void (SB_CALLBACK *TSBSynchronizeMethod)(void * _ObjectData, void * pMethodMethod, void * pDataMethod);

typedef uint8_t TSBSSHForwardingSocketStateRaw;

typedef enum
{
	fssEstablishing = 0,
	fssActive = 1,
	fssClosing = 2,
	fssClosed = 3
} TSBSSHForwardingSocketState;

typedef uint8_t TSBSSHForwardingChannelStateRaw;

typedef enum
{
	fcsEstablishing = 0,
	fcsActive = 1,
	fcsClosing = 2,
	fcsClosed = 3
} TSBSSHForwardingChannelState;

#ifdef SB_USE_CLASS_TELSSHFORWARDEDCONNECTION
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_Close(TElSSHForwardedConnectionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_AutoAdjustPriority(TElSSHForwardedConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_set_AutoAdjustPriority(TElSSHForwardedConnectionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_Socket(TElSSHForwardedConnectionHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_set_Socket(TElSSHForwardedConnectionHandle _Handle, TElSocketHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ReceivedFromSocket(TElSSHForwardedConnectionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_SentToSocket(TElSSHForwardedConnectionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ReceivedFromChannel(TElSSHForwardedConnectionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_SentToChannel(TElSSHForwardedConnectionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_SocketState(TElSSHForwardedConnectionHandle _Handle, TSBSSHForwardingSocketStateRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ChannelState(TElSSHForwardedConnectionHandle _Handle, TSBSSHForwardingChannelStateRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_Data(TElSSHForwardedConnectionHandle _Handle, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_set_Data(TElSSHForwardedConnectionHandle _Handle, void * Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ForwardedHost(TElSSHForwardedConnectionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ForwardedPort(TElSSHForwardedConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_DestHost(TElSSHForwardedConnectionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_DestPort(TElSSHForwardedConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_BoundPort(TElSSHForwardedConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_KeepAlivePeriod(TElSSHForwardedConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_set_KeepAlivePeriod(TElSSHForwardedConnectionHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_DestUsingIPv6(TElSSHForwardedConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ForwardedUsingIPv6(TElSSHForwardedConnectionHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_SocketReadBufSize(TElSSHForwardedConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_set_SocketReadBufSize(TElSSHForwardedConnectionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_SocketWriteBufSize(TElSSHForwardedConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_set_SocketWriteBufSize(TElSSHForwardedConnectionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_MaxCacheSize(TElSSHForwardedConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_set_MaxCacheSize(TElSSHForwardedConnectionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ExitStatus(TElSSHForwardedConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ExitSignal(TElSSHForwardedConnectionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_get_ExitMessage(TElSSHForwardedConnectionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardedConnection_Create(TElSSHForwardingSessionHandle Owner, TElSSHForwardedConnectionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHFORWARDEDCONNECTION */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_Open(TElSSHForwardingTunnelHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_Close(TElSSHForwardingTunnelHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_Active(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_BoundPort(TElSSHForwardingTunnelHandle _Handle, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_UsingIPv6(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_ForwardedHost(TElSSHForwardingTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_ForwardedHost(TElSSHForwardingTunnelHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_ForwardedPort(TElSSHForwardingTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_ForwardedPort(TElSSHForwardingTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_DestHost(TElSSHForwardingTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_DestHost(TElSSHForwardingTunnelHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_DestPort(TElSSHForwardingTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_DestPort(TElSSHForwardingTunnelHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_DestUseIPv6(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_DestUseIPv6(TElSSHForwardingTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_ForwardedUseIPv6(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_ForwardedUseIPv6(TElSSHForwardingTunnelHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_UseProxySettingsForForwardedConnections(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_UseProxySettingsForForwardedConnections(TElSSHForwardingTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_AutoOpen(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_AutoOpen(TElSSHForwardingTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_UseDefaultBindAddress(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_UseDefaultBindAddress(TElSSHForwardingTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_UseDynamicForwarding(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_UseDynamicForwarding(TElSSHForwardingTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_ResolveDynamicForwardingAddresses(TElSSHForwardingTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_ResolveDynamicForwardingAddresses(TElSSHForwardingTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_SocketReadBufSize(TElSSHForwardingTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_SocketReadBufSize(TElSSHForwardingTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_SocketWriteBufSize(TElSSHForwardingTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_SocketWriteBufSize(TElSSHForwardingTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_get_MaxCacheSize(TElSSHForwardingTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_set_MaxCacheSize(TElSSHForwardingTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingTunnel_Create(TElSSHCustomForwardingHandle Owner, TElSSHForwardingTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGSESSION
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_Username(TElSSHForwardingSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_Username(TElSSHForwardingSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_Password(TElSSHForwardingSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_Password(TElSSHForwardingSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_ForwardedPort(TElSSHForwardingSessionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_ForwardedPort(TElSSHForwardingSessionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_DestHost(TElSSHForwardingSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_DestHost(TElSSHForwardingSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_DestPort(TElSSHForwardingSessionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_DestPort(TElSSHForwardingSessionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_OnConnectionOpen(TElSSHForwardingSessionHandle _Handle, TSBSSHConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_OnConnectionOpen(TElSSHForwardingSessionHandle _Handle, TSBSSHConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_OnConnectionChange(TElSSHForwardingSessionHandle _Handle, TSBSSHConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_OnConnectionChange(TElSSHForwardingSessionHandle _Handle, TSBSSHConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_OnConnectionRemove(TElSSHForwardingSessionHandle _Handle, TSBSSHConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_OnConnectionRemove(TElSSHForwardingSessionHandle _Handle, TSBSSHConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_OnReceive(TElSSHForwardingSessionHandle _Handle, TSSHReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_OnReceive(TElSSHForwardingSessionHandle _Handle, TSSHReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_get_OnSend(TElSSHForwardingSessionHandle _Handle, TSSHSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_set_OnSend(TElSSHForwardingSessionHandle _Handle, TSSHSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingSession_Create(TElSSHCustomForwardingHandle Owner, TElSSHForwardingSessionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_Open(TElSSHCustomForwardingHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_Close(TElSSHCustomForwardingHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_Close_1(TElSSHCustomForwardingHandle _Handle, int8_t Wait);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_RenegotiateCiphers(TElSSHCustomForwardingHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_SendIgnore(TElSSHCustomForwardingHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_AddTunnel(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_RemoveTunnel(TElSSHCustomForwardingHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_ClearTunnels(TElSSHCustomForwardingHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_KexAlgorithm(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_PublicKeyAlgorithm(TElSSHCustomForwardingHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_CompressionAlgorithms(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_CompressionAlgorithms(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_EncryptionAlgorithms(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_EncryptionAlgorithms(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_KexAlgorithms(TElSSHCustomForwardingHandle _Handle, int8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_KexAlgorithms(TElSSHCustomForwardingHandle _Handle, int8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_MacAlgorithms(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_MacAlgorithms(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_PublicKeyAlgorithms(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_PublicKeyAlgorithms(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_AuthTypePriorities(TElSSHCustomForwardingHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_AuthTypePriorities(TElSSHCustomForwardingHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_PublicKeyAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_PublicKeyAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_EncryptionAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_EncryptionAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_CompressionAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_CompressionAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_MacAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_MacAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_KexAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, int8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_KexAlgorithmPriorities(TElSSHCustomForwardingHandle _Handle, int8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Tunnels(TElSSHCustomForwardingHandle _Handle, int32_t Index, TElSSHForwardingTunnelHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Active(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_CompressionAlgorithmServerToClient(TElSSHCustomForwardingHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_CompressionAlgorithmClientToServer(TElSSHCustomForwardingHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_EncryptionAlgorithmServerToClient(TElSSHCustomForwardingHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_EncryptionAlgorithmClientToServer(TElSSHCustomForwardingHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_MacAlgorithmServerToClient(TElSSHCustomForwardingHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_MacAlgorithmClientToServer(TElSSHCustomForwardingHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ServerCloseReason(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ServerSoftwareName(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Version(TElSSHCustomForwardingHandle _Handle, TSSHVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_TunnelCount(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_KbdIntName(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_KbdIntInstruction(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ServerKey(TElSSHCustomForwardingHandle _Handle, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_BoundPort(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_UsingIPv6(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_TotalBytesSent(TElSSHCustomForwardingHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_TotalBytesReceived(TElSSHCustomForwardingHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Address(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_Address(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_AuthenticationTypes(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_AuthenticationTypes(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_AutoAdjustCiphers(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_AutoAdjustCiphers(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ClientHostname(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_ClientHostname(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ClientUsername(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_ClientUsername(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_CompressionLevel(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_CompressionLevel(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_DestHost(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_DestHost(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_DestPort(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_DestPort(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ForceCompression(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_ForceCompression(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ForwardedPort(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_ForwardedPort(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ForwardedHost(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_ForwardedHost(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_KeepAlivePeriod(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_KeepAlivePeriod(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_GlobalKeepAlivePeriod(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_GlobalKeepAlivePeriod(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_KeyStorage(TElSSHCustomForwardingHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_KeyStorage(TElSSHCustomForwardingHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Password(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_Password(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Port(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_Port(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SoftwareName(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SoftwareName(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SynchronizeGUI(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SynchronizeGUI(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Username(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_Username(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Versions(TElSSHCustomForwardingHandle _Handle, TSSHVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_Versions(TElSSHCustomForwardingHandle _Handle, TSSHVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocketTimeout(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocketTimeout(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SessionTimeout(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SessionTimeout(TElSSHCustomForwardingHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_UseIPv6(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_UseIPv6(TElSSHCustomForwardingHandle _Handle, int8_t Value);
#ifndef WINCE
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_DNS(TElSSHCustomForwardingHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_DNS(TElSSHCustomForwardingHandle _Handle, TElDNSSettingsHandle Value);
#endif
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_PortKnock(TElSSHCustomForwardingHandle _Handle, TElPortKnockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_PortKnock(TElSSHCustomForwardingHandle _Handle, TElPortKnockHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocksAuthentication(TElSSHCustomForwardingHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocksAuthentication(TElSSHCustomForwardingHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocksPassword(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocksPassword(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocksPort(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocksPort(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocksResolveAddress(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocksResolveAddress(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocksServer(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocksServer(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocksUseIPv6(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocksUseIPv6(TElSSHCustomForwardingHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocksUserCode(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocksUserCode(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocksVersion(TElSSHCustomForwardingHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocksVersion(TElSSHCustomForwardingHandle _Handle, TElSocksVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_UseSocks(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_UseSocks(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_UseWebTunneling(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_UseWebTunneling(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_WebTunnelAddress(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_WebTunnelAddress(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_WebTunnelAuthentication(TElSSHCustomForwardingHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_WebTunnelAuthentication(TElSSHCustomForwardingHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_WebTunnelPassword(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_WebTunnelPassword(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_WebTunnelPort(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_WebTunnelPort(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_WebTunnelUserId(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_WebTunnelUserId(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_WebTunnelRequestHeaders(TElSSHCustomForwardingHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_WebTunnelRequestHeaders(TElSSHCustomForwardingHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocketSettings(TElSSHCustomForwardingHandle _Handle, TElSocketSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Priority(TElSSHCustomForwardingHandle _Handle, TSBSSHForwardingPriorityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_Priority(TElSSHCustomForwardingHandle _Handle, TSBSSHForwardingPriorityRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_Intercept(TElSSHCustomForwardingHandle _Handle, TElSSHForwardingInterceptHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_Intercept(TElSSHCustomForwardingHandle _Handle, TElSSHForwardingInterceptHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_CloseIfNoActiveTunnels(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_CloseIfNoActiveTunnels(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_UseUTF8(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_UseUTF8(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_RequestPasswordChange(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_RequestPasswordChange(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_CertAuthMode(TElSSHCustomForwardingHandle _Handle, TSBSSHCertAuthModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_CertAuthMode(TElSSHCustomForwardingHandle _Handle, TSBSSHCertAuthModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_AutoAdjustPriority(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_AutoAdjustPriority(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_AuthAttempts(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_AuthAttempts(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SSHAuthOrder(TElSSHCustomForwardingHandle _Handle, TSBSSHAuthOrderRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SSHAuthOrder(TElSSHCustomForwardingHandle _Handle, TSBSSHAuthOrderRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_TrustedKeys(TElSSHCustomForwardingHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_TrustedKeys(TElSSHCustomForwardingHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_CryptoProviderManager(TElSSHCustomForwardingHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_CryptoProviderManager(TElSSHCustomForwardingHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_DefaultWindowSize(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_DefaultWindowSize(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_MinWindowSize(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_MinWindowSize(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_MaxSSHPacketSize(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_MaxSSHPacketSize(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_FlushCachedDataOnClose(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_FlushCachedDataOnClose(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_IncomingSpeedLimit(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_IncomingSpeedLimit(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OutgoingSpeedLimit(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OutgoingSpeedLimit(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_EstablishShellChannel(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_EstablishShellChannel(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ObfuscateHandshake(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_ObfuscateHandshake(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_ObfuscationPassword(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_ObfuscationPassword(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocketReadBufSize(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocketReadBufSize(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_SocketWriteBufSize(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_SocketWriteBufSize(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_MaxCacheSize(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_MaxCacheSize(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_GSSMechanism(TElSSHCustomForwardingHandle _Handle, TElGSSBaseMechanismHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_GSSMechanism(TElSSHCustomForwardingHandle _Handle, TElGSSBaseMechanismHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_GSSHostName(TElSSHCustomForwardingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_GSSHostName(TElSSHCustomForwardingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_GSSDelegateCredentials(TElSSHCustomForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_GSSDelegateCredentials(TElSSHCustomForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_InactivityPeriod(TElSSHCustomForwardingHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_InactivityPeriod(TElSSHCustomForwardingHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnAuthenticationKeyboard(TElSSHCustomForwardingHandle _Handle, TSSHAuthenticationKeyboardEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnAuthenticationKeyboard(TElSSHCustomForwardingHandle _Handle, TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnAuthenticationFailed(TElSSHCustomForwardingHandle _Handle, TSSHAuthenticationFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnAuthenticationFailed(TElSSHCustomForwardingHandle _Handle, TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnAuthenticationSuccess(TElSSHCustomForwardingHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnAuthenticationSuccess(TElSSHCustomForwardingHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnAuthenticationStart(TElSSHCustomForwardingHandle _Handle, TSSHAuthenticationStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnAuthenticationStart(TElSSHCustomForwardingHandle _Handle, TSSHAuthenticationStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnAuthenticationAttempt(TElSSHCustomForwardingHandle _Handle, TSSHAuthenticationAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnAuthenticationAttempt(TElSSHCustomForwardingHandle _Handle, TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnBanner(TElSSHCustomForwardingHandle _Handle, TSSHBannerEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnBanner(TElSSHCustomForwardingHandle _Handle, TSSHBannerEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnError(TElSSHCustomForwardingHandle _Handle, TSSHErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnError(TElSSHCustomForwardingHandle _Handle, TSSHErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnKeyValidate(TElSSHCustomForwardingHandle _Handle, TSSHKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnKeyValidate(TElSSHCustomForwardingHandle _Handle, TSSHKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnDebugData(TElSSHCustomForwardingHandle _Handle, TSSHDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnDebugData(TElSSHCustomForwardingHandle _Handle, TSSHDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnPrivateKeyNeeded(TElSSHCustomForwardingHandle _Handle, TSSHPrivateKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnPrivateKeyNeeded(TElSSHCustomForwardingHandle _Handle, TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnCiphersNegotiated(TElSSHCustomForwardingHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnCiphersNegotiated(TElSSHCustomForwardingHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnOpen(TElSSHCustomForwardingHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnOpen(TElSSHCustomForwardingHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnClose(TElSSHCustomForwardingHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnClose(TElSSHCustomForwardingHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnConnectionOpen(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnConnectionOpen(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnConnectionClose(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnConnectionClose(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnConnectionChange(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnConnectionChange(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnConnectionError(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnConnectionError(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnConnectionWork(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnConnectionWork(TElSSHCustomForwardingHandle _Handle, TSBSSHConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnTunnelOpen(TElSSHCustomForwardingHandle _Handle, TSBSSHTunnelEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnTunnelOpen(TElSSHCustomForwardingHandle _Handle, TSBSSHTunnelEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnTunnelClose(TElSSHCustomForwardingHandle _Handle, TSBSSHTunnelEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnTunnelClose(TElSSHCustomForwardingHandle _Handle, TSBSSHTunnelEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnPasswordChangeRequest(TElSSHCustomForwardingHandle _Handle, TSSHPasswordChangeRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnPasswordChangeRequest(TElSSHCustomForwardingHandle _Handle, TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnBeforeConnecting(TElSSHCustomForwardingHandle _Handle, TSBSSHBeforeConnectingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnBeforeConnecting(TElSSHCustomForwardingHandle _Handle, TSBSSHBeforeConnectingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnKexInitReceived(TElSSHCustomForwardingHandle _Handle, TSSHKexInitReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnKexInitReceived(TElSSHCustomForwardingHandle _Handle, TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnDNSError(TElSSHCustomForwardingHandle _Handle, TSSHErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnDNSError(TElSSHCustomForwardingHandle _Handle, TSSHErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnDNSKeyNeeded(TElSSHCustomForwardingHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnDNSKeyNeeded(TElSSHCustomForwardingHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnDNSKeyValidate(TElSSHCustomForwardingHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnDNSKeyValidate(TElSSHCustomForwardingHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_get_OnDNSResolve(TElSSHCustomForwardingHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_set_OnDNSResolve(TElSSHCustomForwardingHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomForwarding_Create(TComponentHandle AOwner, TElSSHCustomForwardingHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT
SB_IMPORT uint32_t SB_APIENTRY TElSSHForwardingIntercept_Create(TComponentHandle AOwner, TElSSHForwardingInterceptHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT */

#ifdef SB_USE_CLASS_TELSSHLOCALPORTFORWARDING
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_ForwardedUsingIPv6(TElSSHLocalPortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_ForwardedUseIPv6(TElSSHLocalPortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_set_ForwardedUseIPv6(TElSSHLocalPortForwardingHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_ReportRealClientLocationToServer(TElSSHLocalPortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_set_ReportRealClientLocationToServer(TElSSHLocalPortForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_UseDynamicForwarding(TElSSHLocalPortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_set_UseDynamicForwarding(TElSSHLocalPortForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_ResolveDynamicForwardingAddresses(TElSSHLocalPortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_set_ResolveDynamicForwardingAddresses(TElSSHLocalPortForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_OnAccept(TElSSHLocalPortForwardingHandle _Handle, TSBSSHSocketAcceptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_set_OnAccept(TElSSHLocalPortForwardingHandle _Handle, TSBSSHSocketAcceptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_OnConnectionSocksAuthMethodChoose(TElSSHLocalPortForwardingHandle _Handle, TSBSSHSocksAuthMethodChooseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_set_OnConnectionSocksAuthMethodChoose(TElSSHLocalPortForwardingHandle _Handle, TSBSSHSocksAuthMethodChooseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_OnConnectionSocksAuthPassword(TElSSHLocalPortForwardingHandle _Handle, TSBSSHSocksAuthPasswordEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_set_OnConnectionSocksAuthPassword(TElSSHLocalPortForwardingHandle _Handle, TSBSSHSocksAuthPasswordEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_get_OnConnectionSocksConnect(TElSSHLocalPortForwardingHandle _Handle, TSBSSHSocksConnectEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_set_OnConnectionSocksConnect(TElSSHLocalPortForwardingHandle _Handle, TSBSSHSocksConnectEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwarding_Create(TComponentHandle AOwner, TElSSHCustomForwardingHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHLOCALPORTFORWARDING */

#ifdef SB_USE_CLASS_TELSSHREMOTEPORTFORWARDING
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_get_DestUsingIPv6(TElSSHRemotePortForwardingHandle _Handle, int8_t * OutResult);
#ifndef WINCE
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_get_DestUseDNS(TElSSHRemotePortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_set_DestUseDNS(TElSSHRemotePortForwardingHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_get_DestUseIPv6(TElSSHRemotePortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_set_DestUseIPv6(TElSSHRemotePortForwardingHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_get_UseDefaultBindAddress(TElSSHRemotePortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_set_UseDefaultBindAddress(TElSSHRemotePortForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_get_UseProxySettingsForForwardedConnections(TElSSHRemotePortForwardingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_set_UseProxySettingsForForwardedConnections(TElSSHRemotePortForwardingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwarding_Create(TComponentHandle Owner, TElSSHRemotePortForwardingHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHREMOTEPORTFORWARDING */

#ifdef SB_USE_CLASS_TELSSHTUNNELSTATE
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelState_Create(TElSSHForwardingTunnelHandle Tunnel, TElSSHTunnelStateHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHTUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHLPFLISTENINGTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSSHLPFListeningThread_get_OnAccept(TElSSHLPFListeningThreadHandle _Handle, TSBSSHLPFAcceptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLPFListeningThread_set_OnAccept(TElSSHLPFListeningThreadHandle _Handle, TSBSSHLPFAcceptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLPFListeningThread_get_OnListeningStarted(TElSSHLPFListeningThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHLPFListeningThread_set_OnListeningStarted(TElSSHLPFListeningThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHLPFListeningThread_Create(TElSSHForwardingSessionHandle Owner, const char * pcAddress, int32_t szAddress, int32_t Port, int8_t UseIPv6, TElSSHLPFListeningThreadHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSSHLPFListeningThread_Create(TElSSHForwardingSessionHandle Owner, const char * pcAddress, int32_t szAddress, int32_t Port, TElSSHLPFListeningThreadHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELSSHLPFLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSSHLOCALTUNNELSTATE
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalTunnelState_Create(TElSSHForwardingTunnelHandle Tunnel, TElSSHLocalTunnelStateHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHLOCALTUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHREMOTETUNNELSTATE
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemoteTunnelState_Create(TElSSHForwardingTunnelHandle Tunnel, TElSSHRemoteTunnelStateHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHREMOTETUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHLOCALPORTFORWARDINGSESSION
SB_IMPORT uint32_t SB_APIENTRY TElSSHLocalPortForwardingSession_Create(TElSSHCustomForwardingHandle Owner, TElSSHForwardingSessionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHLOCALPORTFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHREMOTEPORTFORWARDINGSESSION
SB_IMPORT uint32_t SB_APIENTRY TElSSHRemotePortForwardingSession_Create(TElSSHCustomForwardingHandle Owner, TElSSHForwardingSessionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHREMOTEPORTFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHSCHEDULEDSPECIALMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElSSHScheduledSpecialMessage_Create(int32_t Code, const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count, TElSSHScheduledSpecialMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHSCHEDULEDSPECIALMESSAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHForwardedConnection;
typedef TElSSHForwardedConnection ElSSHForwardedConnection;
class TElSSHForwardingTunnel;
class TElSSHForwardingSession;
typedef TElSSHForwardingSession ElSSHForwardingSession;
class TElSSHCustomForwarding;
typedef TElSSHCustomForwarding ElSSHCustomForwarding;
class TElSSHForwardingIntercept;
class TElSSHLocalPortForwarding;
typedef TElSSHLocalPortForwarding ElSSHLocalPortForwarding;
class TElSSHRemotePortForwarding;
typedef TElSSHRemotePortForwarding ElSSHRemotePortForwarding;
class TElSSHTunnelState;
class TElSSHLPFListeningThread;
class TElSSHLocalTunnelState;
class TElSSHRemoteTunnelState;
class TElSSHLocalPortForwardingSession;
typedef TElSSHLocalPortForwardingSession ElSSHLocalPortForwardingSession;
class TElSSHRemotePortForwardingSession;
typedef TElSSHRemotePortForwardingSession ElSSHRemotePortForwardingSession;
class TElSSHScheduledSpecialMessage;

#ifdef SB_USE_CLASS_TELSSHFORWARDEDCONNECTION
class TElSSHForwardedConnection: public TThread
{
	private:
		SB_DISABLE_COPY(TElSSHForwardedConnection)
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */

		void initInstances();

	public:
		void Close();

		virtual bool get_AutoAdjustPriority();

		virtual void set_AutoAdjustPriority(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustPriority, set_AutoAdjustPriority, TElSSHForwardedConnection, AutoAdjustPriority);

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		virtual void set_Socket(TElSocket &Value);

		virtual void set_Socket(TElSocket *Value);

		SB_DECLARE_PROPERTY(TElSocket*, get_Socket, set_Socket, TElSSHForwardedConnection, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		virtual int64_t get_ReceivedFromSocket();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ReceivedFromSocket, TElSSHForwardedConnection, ReceivedFromSocket);

		virtual int64_t get_SentToSocket();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SentToSocket, TElSSHForwardedConnection, SentToSocket);

		virtual int64_t get_ReceivedFromChannel();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ReceivedFromChannel, TElSSHForwardedConnection, ReceivedFromChannel);

		virtual int64_t get_SentToChannel();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SentToChannel, TElSSHForwardedConnection, SentToChannel);

		virtual TSBSSHForwardingSocketState get_SocketState();

		SB_DECLARE_PROPERTY_GET(TSBSSHForwardingSocketState, get_SocketState, TElSSHForwardedConnection, SocketState);

		virtual TSBSSHForwardingChannelState get_ChannelState();

		SB_DECLARE_PROPERTY_GET(TSBSSHForwardingChannelState, get_ChannelState, TElSSHForwardedConnection, ChannelState);

		virtual void * get_Data();

		virtual void set_Data(void * Value);

		SB_DECLARE_PROPERTY(void *, get_Data, set_Data, TElSSHForwardedConnection, Data);

		virtual void get_ForwardedHost(std::string &OutResult);

		virtual int32_t get_ForwardedPort();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ForwardedPort, TElSSHForwardedConnection, ForwardedPort);

		virtual void get_DestHost(std::string &OutResult);

		virtual int32_t get_DestPort();

		SB_DECLARE_PROPERTY_GET(int32_t, get_DestPort, TElSSHForwardedConnection, DestPort);

		virtual int32_t get_BoundPort();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BoundPort, TElSSHForwardedConnection, BoundPort);

		virtual int32_t get_KeepAlivePeriod();

		virtual void set_KeepAlivePeriod(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeepAlivePeriod, set_KeepAlivePeriod, TElSSHForwardedConnection, KeepAlivePeriod);

#ifdef SB_WINDOWS
		virtual bool get_DestUsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_DestUsingIPv6, TElSSHForwardedConnection, DestUsingIPv6);

		virtual bool get_ForwardedUsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_ForwardedUsingIPv6, TElSSHForwardedConnection, ForwardedUsingIPv6);
#endif

		virtual int32_t get_SocketReadBufSize();

		virtual void set_SocketReadBufSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketReadBufSize, set_SocketReadBufSize, TElSSHForwardedConnection, SocketReadBufSize);

		virtual int32_t get_SocketWriteBufSize();

		virtual void set_SocketWriteBufSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketWriteBufSize, set_SocketWriteBufSize, TElSSHForwardedConnection, SocketWriteBufSize);

		virtual int32_t get_MaxCacheSize();

		virtual void set_MaxCacheSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxCacheSize, set_MaxCacheSize, TElSSHForwardedConnection, MaxCacheSize);

		virtual int32_t get_ExitStatus();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExitStatus, TElSSHForwardedConnection, ExitStatus);

		virtual void get_ExitSignal(std::string &OutResult);

		virtual void get_ExitMessage(std::string &OutResult);

		TElSSHForwardedConnection(TElSSHForwardedConnectionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHFORWARDINGSESSION
		explicit TElSSHForwardedConnection(TElSSHForwardingSession &Owner);

		explicit TElSSHForwardedConnection(TElSSHForwardingSession *Owner);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGSESSION */

		virtual ~TElSSHForwardedConnection();

};
#endif /* SB_USE_CLASS_TELSSHFORWARDEDCONNECTION */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
class TElSSHForwardingTunnel: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHForwardingTunnel)
	public:
		void Open();

		void Close();

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSSHForwardingTunnel, Active);

		virtual int32_t get_BoundPort();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BoundPort, TElSSHForwardingTunnel, BoundPort);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElSSHForwardingTunnel, UsingIPv6);
#endif

		virtual void get_ForwardedHost(std::string &OutResult);

		virtual void set_ForwardedHost(const std::string &Value);

		virtual int32_t get_ForwardedPort();

		virtual void set_ForwardedPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ForwardedPort, set_ForwardedPort, TElSSHForwardingTunnel, ForwardedPort);

		virtual void get_DestHost(std::string &OutResult);

		virtual void set_DestHost(const std::string &Value);

		virtual int32_t get_DestPort();

		virtual void set_DestPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DestPort, set_DestPort, TElSSHForwardingTunnel, DestPort);

#ifdef SB_WINDOWS
		virtual bool get_DestUseIPv6();

		virtual void set_DestUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DestUseIPv6, set_DestUseIPv6, TElSSHForwardingTunnel, DestUseIPv6);

		virtual bool get_ForwardedUseIPv6();

		virtual void set_ForwardedUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForwardedUseIPv6, set_ForwardedUseIPv6, TElSSHForwardingTunnel, ForwardedUseIPv6);
#endif

		virtual bool get_UseProxySettingsForForwardedConnections();

		virtual void set_UseProxySettingsForForwardedConnections(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseProxySettingsForForwardedConnections, set_UseProxySettingsForForwardedConnections, TElSSHForwardingTunnel, UseProxySettingsForForwardedConnections);

		virtual bool get_AutoOpen();

		virtual void set_AutoOpen(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoOpen, set_AutoOpen, TElSSHForwardingTunnel, AutoOpen);

		virtual bool get_UseDefaultBindAddress();

		virtual void set_UseDefaultBindAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDefaultBindAddress, set_UseDefaultBindAddress, TElSSHForwardingTunnel, UseDefaultBindAddress);

		virtual bool get_UseDynamicForwarding();

		virtual void set_UseDynamicForwarding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDynamicForwarding, set_UseDynamicForwarding, TElSSHForwardingTunnel, UseDynamicForwarding);

		virtual bool get_ResolveDynamicForwardingAddresses();

		virtual void set_ResolveDynamicForwardingAddresses(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ResolveDynamicForwardingAddresses, set_ResolveDynamicForwardingAddresses, TElSSHForwardingTunnel, ResolveDynamicForwardingAddresses);

		virtual int32_t get_SocketReadBufSize();

		virtual void set_SocketReadBufSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketReadBufSize, set_SocketReadBufSize, TElSSHForwardingTunnel, SocketReadBufSize);

		virtual int32_t get_SocketWriteBufSize();

		virtual void set_SocketWriteBufSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketWriteBufSize, set_SocketWriteBufSize, TElSSHForwardingTunnel, SocketWriteBufSize);

		virtual int32_t get_MaxCacheSize();

		virtual void set_MaxCacheSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxCacheSize, set_MaxCacheSize, TElSSHForwardingTunnel, MaxCacheSize);

		TElSSHForwardingTunnel(TElSSHForwardingTunnelHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
		explicit TElSSHForwardingTunnel(TElSSHCustomForwarding &Owner);

		explicit TElSSHForwardingTunnel(TElSSHCustomForwarding *Owner);
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

};
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGSESSION
class TElSSHForwardingSession: public TThread
{
	private:
		SB_DISABLE_COPY(TElSSHForwardingSession)
	public:
		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_ForwardedPort();

		virtual void set_ForwardedPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ForwardedPort, set_ForwardedPort, TElSSHForwardingSession, ForwardedPort);

		virtual void get_DestHost(std::string &OutResult);

		virtual void set_DestHost(const std::string &Value);

		virtual int32_t get_DestPort();

		virtual void set_DestPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DestPort, set_DestPort, TElSSHForwardingSession, DestPort);

		virtual void get_OnConnectionOpen(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionOpen(TSBSSHConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionChange(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionChange(TSBSSHConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionRemove(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionRemove(TSBSSHConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TSSHReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSSHReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnSend(TSSHSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSSHSendEvent pMethodValue, void * pDataValue);

		TElSSHForwardingSession(TElSSHForwardingSessionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
		explicit TElSSHForwardingSession(TElSSHCustomForwarding &Owner);

		explicit TElSSHForwardingSession(TElSSHCustomForwarding *Owner);
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

};
#endif /* SB_USE_CLASS_TELSSHFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
class TElSSHCustomForwarding: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSHCustomForwarding)
#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
		TElSSHForwardingTunnel* _Inst_Tunnels;
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */
#ifdef SB_USE_CLASS_TELSSHKEY
		TElSSHKey* _Inst_ServerKey;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_KeyStorage;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		TElDNSSettings* _Inst_DNS;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_USE_CLASS_TELPORTKNOCK
		TElPortKnock* _Inst_PortKnock;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_WebTunnelRequestHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_WebTunnelRequestHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		TElSocketSettings* _Inst_SocketSettings;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT
		TElSSHForwardingIntercept* _Inst_Intercept;
#endif /* SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_TrustedKeys;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
		TElGSSBaseMechanism* _Inst_GSSMechanism;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

		void initInstances();

	public:
		void Open();

		void Close();

		void Close(bool Wait);

		void RenegotiateCiphers();

		void SendIgnore(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count);

		int32_t AddTunnel();

		void RemoveTunnel(int32_t Index);

		void ClearTunnels();

		virtual int8_t get_KexAlgorithm();

		SB_DECLARE_PROPERTY_GET(int8_t, get_KexAlgorithm, TElSSHCustomForwarding, KexAlgorithm);

		virtual uint8_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_PublicKeyAlgorithm, TElSSHCustomForwarding, PublicKeyAlgorithm);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

		virtual bool get_EncryptionAlgorithms(uint8_t Index);

		virtual void set_EncryptionAlgorithms(uint8_t Index, bool Value);

		virtual bool get_KexAlgorithms(int8_t Index);

		virtual void set_KexAlgorithms(int8_t Index, bool Value);

		virtual bool get_MacAlgorithms(uint8_t Index);

		virtual void set_MacAlgorithms(uint8_t Index, bool Value);

		virtual bool get_PublicKeyAlgorithms(uint8_t Index);

		virtual void set_PublicKeyAlgorithms(uint8_t Index, bool Value);

		virtual int32_t get_AuthTypePriorities(int32_t Index);

		virtual void set_AuthTypePriorities(int32_t Index, int32_t Value);

		virtual int32_t get_PublicKeyAlgorithmPriorities(uint8_t Index);

		virtual void set_PublicKeyAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_EncryptionAlgorithmPriorities(uint8_t Index);

		virtual void set_EncryptionAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_CompressionAlgorithmPriorities(uint8_t Index);

		virtual void set_CompressionAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_MacAlgorithmPriorities(uint8_t Index);

		virtual void set_MacAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_KexAlgorithmPriorities(int8_t Index);

		virtual void set_KexAlgorithmPriorities(int8_t Index, int32_t Value);

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
		virtual TElSSHForwardingTunnel* get_Tunnels(int32_t Index);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSSHCustomForwarding, Active);

		virtual uint8_t get_CompressionAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithmServerToClient, TElSSHCustomForwarding, CompressionAlgorithmServerToClient);

		virtual uint8_t get_CompressionAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithmClientToServer, TElSSHCustomForwarding, CompressionAlgorithmClientToServer);

		virtual uint8_t get_EncryptionAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_EncryptionAlgorithmServerToClient, TElSSHCustomForwarding, EncryptionAlgorithmServerToClient);

		virtual uint8_t get_EncryptionAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_EncryptionAlgorithmClientToServer, TElSSHCustomForwarding, EncryptionAlgorithmClientToServer);

		virtual uint8_t get_MacAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_MacAlgorithmServerToClient, TElSSHCustomForwarding, MacAlgorithmServerToClient);

		virtual uint8_t get_MacAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_MacAlgorithmClientToServer, TElSSHCustomForwarding, MacAlgorithmClientToServer);

		virtual void get_ServerCloseReason(std::string &OutResult);

		virtual void get_ServerSoftwareName(std::string &OutResult);

		virtual TSSHVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSSHVersion, get_Version, TElSSHCustomForwarding, Version);

		virtual int32_t get_TunnelCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TunnelCount, TElSSHCustomForwarding, TunnelCount);

		virtual void get_KbdIntName(std::string &OutResult);

		virtual void get_KbdIntInstruction(std::string &OutResult);

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual TElSSHKey* get_ServerKey();

		SB_DECLARE_PROPERTY_GET(TElSSHKey*, get_ServerKey, TElSSHCustomForwarding, ServerKey);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual int32_t get_BoundPort();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BoundPort, TElSSHCustomForwarding, BoundPort);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElSSHCustomForwarding, UsingIPv6);
#endif

		virtual int64_t get_TotalBytesSent();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesSent, TElSSHCustomForwarding, TotalBytesSent);

		virtual int64_t get_TotalBytesReceived();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesReceived, TElSSHCustomForwarding, TotalBytesReceived);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual int32_t get_AuthenticationTypes();

		virtual void set_AuthenticationTypes(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthenticationTypes, set_AuthenticationTypes, TElSSHCustomForwarding, AuthenticationTypes);

		virtual bool get_AutoAdjustCiphers();

		virtual void set_AutoAdjustCiphers(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustCiphers, set_AutoAdjustCiphers, TElSSHCustomForwarding, AutoAdjustCiphers);

		virtual void get_ClientHostname(std::string &OutResult);

		virtual void set_ClientHostname(const std::string &Value);

		virtual void get_ClientUsername(std::string &OutResult);

		virtual void set_ClientUsername(const std::string &Value);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElSSHCustomForwarding, CompressionLevel);

		virtual void get_DestHost(std::string &OutResult);

		virtual void set_DestHost(const std::string &Value);

		virtual int32_t get_DestPort();

		virtual void set_DestPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DestPort, set_DestPort, TElSSHCustomForwarding, DestPort);

		virtual bool get_ForceCompression();

		virtual void set_ForceCompression(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCompression, set_ForceCompression, TElSSHCustomForwarding, ForceCompression);

		virtual int32_t get_ForwardedPort();

		virtual void set_ForwardedPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ForwardedPort, set_ForwardedPort, TElSSHCustomForwarding, ForwardedPort);

		virtual void get_ForwardedHost(std::string &OutResult);

		virtual void set_ForwardedHost(const std::string &Value);

		virtual int32_t get_KeepAlivePeriod();

		virtual void set_KeepAlivePeriod(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeepAlivePeriod, set_KeepAlivePeriod, TElSSHCustomForwarding, KeepAlivePeriod);

		virtual int32_t get_GlobalKeepAlivePeriod();

		virtual void set_GlobalKeepAlivePeriod(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_GlobalKeepAlivePeriod, set_GlobalKeepAlivePeriod, TElSSHCustomForwarding, GlobalKeepAlivePeriod);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_KeyStorage();

		virtual void set_KeyStorage(TElSSHCustomKeyStorage &Value);

		virtual void set_KeyStorage(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_KeyStorage, set_KeyStorage, TElSSHCustomForwarding, KeyStorage);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSSHCustomForwarding, Port);

		virtual void get_SoftwareName(std::string &OutResult);

		virtual void set_SoftwareName(const std::string &Value);

		virtual bool get_SynchronizeGUI();

		virtual void set_SynchronizeGUI(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SynchronizeGUI, set_SynchronizeGUI, TElSSHCustomForwarding, SynchronizeGUI);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual TSSHVersions get_Versions();

		virtual void set_Versions(TSSHVersions Value);

		SB_DECLARE_PROPERTY(TSSHVersions, get_Versions, set_Versions, TElSSHCustomForwarding, Versions);

		virtual int32_t get_SocketTimeout();

		virtual void set_SocketTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketTimeout, set_SocketTimeout, TElSSHCustomForwarding, SocketTimeout);

		virtual int32_t get_SessionTimeout();

		virtual void set_SessionTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SessionTimeout, set_SessionTimeout, TElSSHCustomForwarding, SessionTimeout);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElSSHCustomForwarding, UseIPv6);

#ifndef WINCE
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElSSHCustomForwarding, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#endif

#ifdef SB_USE_CLASS_TELPORTKNOCK
		virtual TElPortKnock* get_PortKnock();

		virtual void set_PortKnock(TElPortKnock &Value);

		virtual void set_PortKnock(TElPortKnock *Value);

		SB_DECLARE_PROPERTY(TElPortKnock*, get_PortKnock, set_PortKnock, TElSSHCustomForwarding, PortKnock);
#endif /* SB_USE_CLASS_TELPORTKNOCK */

		virtual TElSocksAuthentication get_SocksAuthentication();

		virtual void set_SocksAuthentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_SocksAuthentication, set_SocksAuthentication, TElSSHCustomForwarding, SocksAuthentication);

		virtual void get_SocksPassword(std::string &OutResult);

		virtual void set_SocksPassword(const std::string &Value);

		virtual int32_t get_SocksPort();

		virtual void set_SocksPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocksPort, set_SocksPort, TElSSHCustomForwarding, SocksPort);

		virtual bool get_SocksResolveAddress();

		virtual void set_SocksResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksResolveAddress, set_SocksResolveAddress, TElSSHCustomForwarding, SocksResolveAddress);

		virtual void get_SocksServer(std::string &OutResult);

		virtual void set_SocksServer(const std::string &Value);

#ifdef SB_WINDOWS
		virtual bool get_SocksUseIPv6();

		virtual void set_SocksUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksUseIPv6, set_SocksUseIPv6, TElSSHCustomForwarding, SocksUseIPv6);
#endif

		virtual void get_SocksUserCode(std::string &OutResult);

		virtual void set_SocksUserCode(const std::string &Value);

		virtual TElSocksVersion get_SocksVersion();

		virtual void set_SocksVersion(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_SocksVersion, set_SocksVersion, TElSSHCustomForwarding, SocksVersion);

		virtual bool get_UseSocks();

		virtual void set_UseSocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSocks, set_UseSocks, TElSSHCustomForwarding, UseSocks);

		virtual bool get_UseWebTunneling();

		virtual void set_UseWebTunneling(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseWebTunneling, set_UseWebTunneling, TElSSHCustomForwarding, UseWebTunneling);

		virtual void get_WebTunnelAddress(std::string &OutResult);

		virtual void set_WebTunnelAddress(const std::string &Value);

		virtual TElWebTunnelAuthentication get_WebTunnelAuthentication();

		virtual void set_WebTunnelAuthentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_WebTunnelAuthentication, set_WebTunnelAuthentication, TElSSHCustomForwarding, WebTunnelAuthentication);

		virtual void get_WebTunnelPassword(std::string &OutResult);

		virtual void set_WebTunnelPassword(const std::string &Value);

		virtual int32_t get_WebTunnelPort();

		virtual void set_WebTunnelPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_WebTunnelPort, set_WebTunnelPort, TElSSHCustomForwarding, WebTunnelPort);

		virtual void get_WebTunnelUserId(std::string &OutResult);

		virtual void set_WebTunnelUserId(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelRequestHeaders, TElSSHCustomForwarding, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelRequestHeaders, TElSSHCustomForwarding, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		virtual TElSocketSettings* get_SocketSettings();

		SB_DECLARE_PROPERTY_GET(TElSocketSettings*, get_SocketSettings, TElSSHCustomForwarding, SocketSettings);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

		virtual TSBSSHForwardingPriority get_Priority();

		virtual void set_Priority(TSBSSHForwardingPriority Value);

		SB_DECLARE_PROPERTY(TSBSSHForwardingPriority, get_Priority, set_Priority, TElSSHCustomForwarding, Priority);

#ifdef SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT
		virtual TElSSHForwardingIntercept* get_Intercept();

		virtual void set_Intercept(TElSSHForwardingIntercept &Value);

		virtual void set_Intercept(TElSSHForwardingIntercept *Value);

		SB_DECLARE_PROPERTY(TElSSHForwardingIntercept*, get_Intercept, set_Intercept, TElSSHCustomForwarding, Intercept);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT */

		virtual bool get_CloseIfNoActiveTunnels();

		virtual void set_CloseIfNoActiveTunnels(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CloseIfNoActiveTunnels, set_CloseIfNoActiveTunnels, TElSSHCustomForwarding, CloseIfNoActiveTunnels);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSSHCustomForwarding, UseUTF8);

		virtual bool get_RequestPasswordChange();

		virtual void set_RequestPasswordChange(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestPasswordChange, set_RequestPasswordChange, TElSSHCustomForwarding, RequestPasswordChange);

		virtual TSBSSHCertAuthMode get_CertAuthMode();

		virtual void set_CertAuthMode(TSBSSHCertAuthMode Value);

		SB_DECLARE_PROPERTY(TSBSSHCertAuthMode, get_CertAuthMode, set_CertAuthMode, TElSSHCustomForwarding, CertAuthMode);

		virtual bool get_AutoAdjustPriority();

		virtual void set_AutoAdjustPriority(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustPriority, set_AutoAdjustPriority, TElSSHCustomForwarding, AutoAdjustPriority);

		virtual int32_t get_AuthAttempts();

		virtual void set_AuthAttempts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthAttempts, set_AuthAttempts, TElSSHCustomForwarding, AuthAttempts);

		virtual TSBSSHAuthOrder get_SSHAuthOrder();

		virtual void set_SSHAuthOrder(TSBSSHAuthOrder Value);

		SB_DECLARE_PROPERTY(TSBSSHAuthOrder, get_SSHAuthOrder, set_SSHAuthOrder, TElSSHCustomForwarding, SSHAuthOrder);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_TrustedKeys();

		virtual void set_TrustedKeys(TElSSHCustomKeyStorage &Value);

		virtual void set_TrustedKeys(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_TrustedKeys, set_TrustedKeys, TElSSHCustomForwarding, TrustedKeys);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSSHCustomForwarding, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual int32_t get_DefaultWindowSize();

		virtual void set_DefaultWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DefaultWindowSize, set_DefaultWindowSize, TElSSHCustomForwarding, DefaultWindowSize);

		virtual int32_t get_MinWindowSize();

		virtual void set_MinWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinWindowSize, set_MinWindowSize, TElSSHCustomForwarding, MinWindowSize);

		virtual int32_t get_MaxSSHPacketSize();

		virtual void set_MaxSSHPacketSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxSSHPacketSize, set_MaxSSHPacketSize, TElSSHCustomForwarding, MaxSSHPacketSize);

		virtual bool get_FlushCachedDataOnClose();

		virtual void set_FlushCachedDataOnClose(bool Value);

		SB_DECLARE_PROPERTY(bool, get_FlushCachedDataOnClose, set_FlushCachedDataOnClose, TElSSHCustomForwarding, FlushCachedDataOnClose);

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElSSHCustomForwarding, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElSSHCustomForwarding, OutgoingSpeedLimit);

		virtual bool get_EstablishShellChannel();

		virtual void set_EstablishShellChannel(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EstablishShellChannel, set_EstablishShellChannel, TElSSHCustomForwarding, EstablishShellChannel);

		virtual bool get_ObfuscateHandshake();

		virtual void set_ObfuscateHandshake(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ObfuscateHandshake, set_ObfuscateHandshake, TElSSHCustomForwarding, ObfuscateHandshake);

		virtual void get_ObfuscationPassword(std::string &OutResult);

		virtual void set_ObfuscationPassword(const std::string &Value);

		virtual int32_t get_SocketReadBufSize();

		virtual void set_SocketReadBufSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketReadBufSize, set_SocketReadBufSize, TElSSHCustomForwarding, SocketReadBufSize);

		virtual int32_t get_SocketWriteBufSize();

		virtual void set_SocketWriteBufSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketWriteBufSize, set_SocketWriteBufSize, TElSSHCustomForwarding, SocketWriteBufSize);

		virtual int32_t get_MaxCacheSize();

		virtual void set_MaxCacheSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxCacheSize, set_MaxCacheSize, TElSSHCustomForwarding, MaxCacheSize);

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
		virtual TElGSSBaseMechanism* get_GSSMechanism();

		virtual void set_GSSMechanism(TElGSSBaseMechanism &Value);

		virtual void set_GSSMechanism(TElGSSBaseMechanism *Value);

		SB_DECLARE_PROPERTY(TElGSSBaseMechanism*, get_GSSMechanism, set_GSSMechanism, TElSSHCustomForwarding, GSSMechanism);
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

		virtual void get_GSSHostName(std::string &OutResult);

		virtual void set_GSSHostName(const std::string &Value);

		virtual bool get_GSSDelegateCredentials();

		virtual void set_GSSDelegateCredentials(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GSSDelegateCredentials, set_GSSDelegateCredentials, TElSSHCustomForwarding, GSSDelegateCredentials);

		virtual int32_t get_InactivityPeriod();

		virtual void set_InactivityPeriod(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_InactivityPeriod, set_InactivityPeriod, TElSSHCustomForwarding, InactivityPeriod);

		virtual void get_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationSuccess(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationSuccess(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationStart(TSSHAuthenticationStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationStart(TSSHAuthenticationStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue);

		virtual void get_OnBanner(TSSHBannerEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBanner(TSSHBannerEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyValidate(TSSHKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyValidate(TSSHKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDebugData(TSSHDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDebugData(TSSHDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpen(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnClose(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionOpen(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionOpen(TSBSSHConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionClose(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionClose(TSBSSHConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionChange(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionChange(TSBSSHConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionError(TSBSSHConnectionErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionError(TSBSSHConnectionErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionWork(TSBSSHConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionWork(TSBSSHConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnTunnelOpen(TSBSSHTunnelEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTunnelOpen(TSBSSHTunnelEvent pMethodValue, void * pDataValue);

		virtual void get_OnTunnelClose(TSBSSHTunnelEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTunnelClose(TSBSSHTunnelEvent pMethodValue, void * pDataValue);

		virtual void get_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeConnecting(TSBSSHBeforeConnectingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeConnecting(TSBSSHBeforeConnectingEvent pMethodValue, void * pDataValue);

		virtual void get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSError(TSSHErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElSSHCustomForwarding(TElSSHCustomForwardingHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHCustomForwarding(TComponent &AOwner);

		explicit TElSSHCustomForwarding(TComponent *AOwner);

		virtual ~TElSSHCustomForwarding();

};
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

#ifdef SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT
class TElSSHForwardingIntercept: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSHForwardingIntercept)
	public:
		TElSSHForwardingIntercept(TElSSHForwardingInterceptHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHForwardingIntercept(TComponent &AOwner);

		explicit TElSSHForwardingIntercept(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSHFORWARDINGINTERCEPT */

#ifdef SB_USE_CLASS_TELSSHLOCALPORTFORWARDING
class TElSSHLocalPortForwarding: public TElSSHCustomForwarding
{
	private:
		SB_DISABLE_COPY(TElSSHLocalPortForwarding)
	public:
#ifdef SB_WINDOWS
		virtual bool get_ForwardedUsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_ForwardedUsingIPv6, TElSSHLocalPortForwarding, ForwardedUsingIPv6);

		virtual bool get_ForwardedUseIPv6();

		virtual void set_ForwardedUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForwardedUseIPv6, set_ForwardedUseIPv6, TElSSHLocalPortForwarding, ForwardedUseIPv6);
#endif

		virtual bool get_ReportRealClientLocationToServer();

		virtual void set_ReportRealClientLocationToServer(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReportRealClientLocationToServer, set_ReportRealClientLocationToServer, TElSSHLocalPortForwarding, ReportRealClientLocationToServer);

		virtual bool get_UseDynamicForwarding();

		virtual void set_UseDynamicForwarding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDynamicForwarding, set_UseDynamicForwarding, TElSSHLocalPortForwarding, UseDynamicForwarding);

		virtual bool get_ResolveDynamicForwardingAddresses();

		virtual void set_ResolveDynamicForwardingAddresses(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ResolveDynamicForwardingAddresses, set_ResolveDynamicForwardingAddresses, TElSSHLocalPortForwarding, ResolveDynamicForwardingAddresses);

		virtual void get_OnAccept(TSBSSHSocketAcceptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAccept(TSBSSHSocketAcceptEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionSocksAuthMethodChoose(TSBSSHSocksAuthMethodChooseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionSocksAuthMethodChoose(TSBSSHSocksAuthMethodChooseEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionSocksAuthPassword(TSBSSHSocksAuthPasswordEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionSocksAuthPassword(TSBSSHSocksAuthPasswordEvent pMethodValue, void * pDataValue);

		virtual void get_OnConnectionSocksConnect(TSBSSHSocksConnectEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConnectionSocksConnect(TSBSSHSocksConnectEvent pMethodValue, void * pDataValue);

		TElSSHLocalPortForwarding(TElSSHLocalPortForwardingHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHLocalPortForwarding(TComponent &AOwner);

		explicit TElSSHLocalPortForwarding(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSHLOCALPORTFORWARDING */

#ifdef SB_USE_CLASS_TELSSHREMOTEPORTFORWARDING
class TElSSHRemotePortForwarding: public TElSSHCustomForwarding
{
	private:
		SB_DISABLE_COPY(TElSSHRemotePortForwarding)
	public:
#ifdef SB_WINDOWS
		virtual bool get_DestUsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_DestUsingIPv6, TElSSHRemotePortForwarding, DestUsingIPv6);
#ifndef WINCE

		virtual bool get_DestUseDNS();

		virtual void set_DestUseDNS(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DestUseDNS, set_DestUseDNS, TElSSHRemotePortForwarding, DestUseDNS);
#endif

		virtual bool get_DestUseIPv6();

		virtual void set_DestUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DestUseIPv6, set_DestUseIPv6, TElSSHRemotePortForwarding, DestUseIPv6);
#endif

		virtual bool get_UseDefaultBindAddress();

		virtual void set_UseDefaultBindAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDefaultBindAddress, set_UseDefaultBindAddress, TElSSHRemotePortForwarding, UseDefaultBindAddress);

		virtual bool get_UseProxySettingsForForwardedConnections();

		virtual void set_UseProxySettingsForForwardedConnections(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseProxySettingsForForwardedConnections, set_UseProxySettingsForForwardedConnections, TElSSHRemotePortForwarding, UseProxySettingsForForwardedConnections);

		TElSSHRemotePortForwarding(TElSSHRemotePortForwardingHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHRemotePortForwarding(TComponent &Owner);

		explicit TElSSHRemotePortForwarding(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELSSHREMOTEPORTFORWARDING */

#ifdef SB_USE_CLASS_TELSSHTUNNELSTATE
class TElSSHTunnelState: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHTunnelState)
	public:
		TElSSHTunnelState(TElSSHTunnelStateHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
		explicit TElSSHTunnelState(TElSSHForwardingTunnel &Tunnel);

		explicit TElSSHTunnelState(TElSSHForwardingTunnel *Tunnel);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

};
#endif /* SB_USE_CLASS_TELSSHTUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHLPFLISTENINGTHREAD
class TElSSHLPFListeningThread: public TThread
{
	private:
		SB_DISABLE_COPY(TElSSHLPFListeningThread)
	public:
		virtual void get_OnAccept(TSBSSHLPFAcceptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAccept(TSBSSHLPFAcceptEvent pMethodValue, void * pDataValue);

		virtual void get_OnListeningStarted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnListeningStarted(TNotifyEvent pMethodValue, void * pDataValue);

		TElSSHLPFListeningThread(TElSSHLPFListeningThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHFORWARDINGSESSION
#ifdef SB_WINDOWS
		TElSSHLPFListeningThread(TElSSHForwardingSession &Owner, const std::string &Address, int32_t Port, bool UseIPv6);
#else
		TElSSHLPFListeningThread(TElSSHForwardingSession &Owner, const std::string &Address, int32_t Port);
#endif

#ifdef SB_WINDOWS
		TElSSHLPFListeningThread(TElSSHForwardingSession *Owner, const std::string &Address, int32_t Port, bool UseIPv6);
#else
		TElSSHLPFListeningThread(TElSSHForwardingSession *Owner, const std::string &Address, int32_t Port);
#endif
#endif /* SB_USE_CLASS_TELSSHFORWARDINGSESSION */

};
#endif /* SB_USE_CLASS_TELSSHLPFLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSSHLOCALTUNNELSTATE
class TElSSHLocalTunnelState: public TElSSHTunnelState
{
	private:
		SB_DISABLE_COPY(TElSSHLocalTunnelState)
	public:
		TElSSHLocalTunnelState(TElSSHLocalTunnelStateHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
		explicit TElSSHLocalTunnelState(TElSSHForwardingTunnel &Tunnel);

		explicit TElSSHLocalTunnelState(TElSSHForwardingTunnel *Tunnel);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

};
#endif /* SB_USE_CLASS_TELSSHLOCALTUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHREMOTETUNNELSTATE
class TElSSHRemoteTunnelState: public TElSSHTunnelState
{
	private:
		SB_DISABLE_COPY(TElSSHRemoteTunnelState)
	public:
		TElSSHRemoteTunnelState(TElSSHRemoteTunnelStateHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHFORWARDINGTUNNEL
		explicit TElSSHRemoteTunnelState(TElSSHForwardingTunnel &Tunnel);

		explicit TElSSHRemoteTunnelState(TElSSHForwardingTunnel *Tunnel);
#endif /* SB_USE_CLASS_TELSSHFORWARDINGTUNNEL */

};
#endif /* SB_USE_CLASS_TELSSHREMOTETUNNELSTATE */

#ifdef SB_USE_CLASS_TELSSHLOCALPORTFORWARDINGSESSION
class TElSSHLocalPortForwardingSession: public TElSSHForwardingSession
{
	private:
		SB_DISABLE_COPY(TElSSHLocalPortForwardingSession)
	public:
		TElSSHLocalPortForwardingSession(TElSSHLocalPortForwardingSessionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
		explicit TElSSHLocalPortForwardingSession(TElSSHCustomForwarding &Owner);

		explicit TElSSHLocalPortForwardingSession(TElSSHCustomForwarding *Owner);
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

};
#endif /* SB_USE_CLASS_TELSSHLOCALPORTFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHREMOTEPORTFORWARDINGSESSION
class TElSSHRemotePortForwardingSession: public TElSSHForwardingSession
{
	private:
		SB_DISABLE_COPY(TElSSHRemotePortForwardingSession)
	public:
		TElSSHRemotePortForwardingSession(TElSSHRemotePortForwardingSessionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSHCUSTOMFORWARDING
		explicit TElSSHRemotePortForwardingSession(TElSSHCustomForwarding &Owner);

		explicit TElSSHRemotePortForwardingSession(TElSSHCustomForwarding *Owner);
#endif /* SB_USE_CLASS_TELSSHCUSTOMFORWARDING */

};
#endif /* SB_USE_CLASS_TELSSHREMOTEPORTFORWARDINGSESSION */

#ifdef SB_USE_CLASS_TELSSHSCHEDULEDSPECIALMESSAGE
class TElSSHScheduledSpecialMessage: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHScheduledSpecialMessage)
	public:
		TElSSHScheduledSpecialMessage(TElSSHScheduledSpecialMessageHandle handle, TElOwnHandle ownHandle);

		TElSSHScheduledSpecialMessage(int32_t Code, const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count);

};
#endif /* SB_USE_CLASS_TELSSHSCHEDULEDSPECIALMESSAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHFORWARDING */
