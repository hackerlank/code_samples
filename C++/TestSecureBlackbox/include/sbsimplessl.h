#ifndef __INC_SBSIMPLESSL
#define __INC_SBSIMPLESSL

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbsocket.h"
#include "sbportknock.h"
#include "sbsslclient.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssecconsts.h"
#include "sbdnssectypes.h"
#endif
#include "sbx509.h"
#include "sbcustomcertstorage.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCustomSimpleSSLClientHandle;

typedef TElCustomSimpleSSLClientHandle ElCustomSimpleSSLClientHandle;

typedef TElClassHandle TElSimpleSSLClientHandle;

typedef TElSimpleSSLClientHandle ElSimpleSSLClientHandle;

#ifdef SB_USE_CLASS_TELCUSTOMSIMPLESSLCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_Interrupt(TElCustomSimpleSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_Close(TElCustomSimpleSSLClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_Open(TElCustomSimpleSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_SendText(TElCustomSimpleSSLClientHandle _Handle, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_Join(TElCustomSimpleSSLClientHandle _Handle, TElCustomSimpleSSLClientHandle Client);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_SendData(TElCustomSimpleSSLClientHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_ReceiveData(TElCustomSimpleSSLClientHandle _Handle, void * Buffer, int32_t * Size, int8_t ReadAll);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_SendKeepAlive(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_InternalValidate(TElCustomSimpleSSLClientHandle _Handle, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_CanReceive(TElCustomSimpleSSLClientHandle _Handle, int32_t Timeout, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_RenegotiateCiphers(TElCustomSimpleSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_RemoteHost(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_RemoteIP(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_Active(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_CipherSuite(TElCustomSimpleSSLClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_CipherSuites(TElCustomSimpleSSLClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_CipherSuites(TElCustomSimpleSSLClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_CipherSuitePriorities(TElCustomSimpleSSLClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_CipherSuitePriorities(TElCustomSimpleSSLClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_CompressionAlgorithm(TElCustomSimpleSSLClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_CompressionAlgorithms(TElCustomSimpleSSLClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_CompressionAlgorithms(TElCustomSimpleSSLClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_CurrentVersion(TElCustomSimpleSSLClientHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_Extensions(TElCustomSimpleSSLClientHandle _Handle, TElClientSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_PeerExtensions(TElCustomSimpleSSLClientHandle _Handle, TElCustomSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_TotalBytesSent(TElCustomSimpleSSLClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_TotalBytesReceived(TElCustomSimpleSSLClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_ProxyResult(TElCustomSimpleSSLClientHandle _Handle, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_UsingIPv6(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_InternalSocket(TElCustomSimpleSSLClientHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_Control(TElCustomSimpleSSLClientHandle _Handle, TElSSLClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocketSettings(TElCustomSimpleSSLClientHandle _Handle, TElSocketSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_ConnectionInfo(TElCustomSimpleSSLClientHandle _Handle, TElSSLConnectionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_CertStorage(TElCustomSimpleSSLClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_CertStorage(TElCustomSimpleSSLClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_ClientCertStorage(TElCustomSimpleSSLClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_ClientCertStorage(TElCustomSimpleSSLClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_Client(TElCustomSimpleSSLClientHandle _Handle, TElSSLClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocketTimeout(TElCustomSimpleSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocketTimeout(TElCustomSimpleSSLClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_Versions(TElCustomSimpleSSLClientHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_Versions(TElCustomSimpleSSLClientHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SSLOptions(TElCustomSimpleSSLClientHandle _Handle, TSBSSLOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SSLOptions(TElCustomSimpleSSLClientHandle _Handle, TSBSSLOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_LocalAddress(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_LocalAddress(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_LocalPort(TElCustomSimpleSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_LocalPort(TElCustomSimpleSSLClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_IncomingSpeedLimit(TElCustomSimpleSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_IncomingSpeedLimit(TElCustomSimpleSSLClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_OutgoingSpeedLimit(TElCustomSimpleSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_OutgoingSpeedLimit(TElCustomSimpleSSLClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_UseSSLSessionResumption(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_UseSSLSessionResumption(TElCustomSimpleSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_ForceResumeIfDestinationChanges(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_ForceResumeIfDestinationChanges(TElCustomSimpleSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocksAuthentication(TElCustomSimpleSSLClientHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocksAuthentication(TElCustomSimpleSSLClientHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocksPassword(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocksPassword(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocksPort(TElCustomSimpleSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocksPort(TElCustomSimpleSSLClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocksResolveAddress(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocksResolveAddress(TElCustomSimpleSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocksServer(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocksServer(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocksUserCode(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocksUserCode(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocksVersion(TElCustomSimpleSSLClientHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocksVersion(TElCustomSimpleSSLClientHandle _Handle, TElSocksVersionRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocksUseIPv6(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocksUseIPv6(TElCustomSimpleSSLClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_UseSocks(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_UseSocks(TElCustomSimpleSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_UseWebTunneling(TElCustomSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_UseWebTunneling(TElCustomSimpleSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelAddress(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_WebTunnelAddress(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelAuthentication(TElCustomSimpleSSLClientHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_WebTunnelAuthentication(TElCustomSimpleSSLClientHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelPassword(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_WebTunnelPassword(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelPort(TElCustomSimpleSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_WebTunnelPort(TElCustomSimpleSSLClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelUserId(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_WebTunnelUserId(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelRequestHeaders(TElCustomSimpleSSLClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelResponseHeaders(TElCustomSimpleSSLClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelRequestHeaders(TElCustomSimpleSSLClientHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelResponseHeaders(TElCustomSimpleSSLClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_WebTunnelResponseBody(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SocketBinding(TElCustomSimpleSSLClientHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SocketBinding(TElCustomSimpleSSLClientHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SRPUserName(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SRPUserName(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_SRPPassword(TElCustomSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_SRPPassword(TElCustomSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_RenegotiationAttackPreventionMode(TElCustomSimpleSSLClientHandle _Handle, TSBRenegotiationAttackPreventionModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_RenegotiationAttackPreventionMode(TElCustomSimpleSSLClientHandle _Handle, TSBRenegotiationAttackPreventionModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_PortKnock(TElCustomSimpleSSLClientHandle _Handle, TElPortKnockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_PortKnock(TElCustomSimpleSSLClientHandle _Handle, TElPortKnockHandle Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_DNS(TElCustomSimpleSSLClientHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_DNS(TElCustomSimpleSSLClientHandle _Handle, TElDNSSettingsHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_MessageLoop(TElCustomSimpleSSLClientHandle _Handle, TElMessageLoopEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_MessageLoop(TElCustomSimpleSSLClientHandle _Handle, TElMessageLoopEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_OnDNSKeyNeeded(TElCustomSimpleSSLClientHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_OnDNSKeyNeeded(TElCustomSimpleSSLClientHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_OnDNSKeyValidate(TElCustomSimpleSSLClientHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_OnDNSKeyValidate(TElCustomSimpleSSLClientHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_get_OnDNSResolve(TElCustomSimpleSSLClientHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_set_OnDNSResolve(TElCustomSimpleSSLClientHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCustomSimpleSSLClient_Create(TComponentHandle AOwner, TElCustomSimpleSSLClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSIMPLESSLCLIENT */

#ifdef SB_USE_CLASS_TELSIMPLESSLCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_StartTLS(TElSimpleSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_StopTLS(TElSimpleSSLClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_Address(TElSimpleSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_Address(TElSimpleSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_Enabled(TElSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_Enabled(TElSimpleSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_Port(TElSimpleSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_Port(TElSimpleSSLClientHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_UseIPv6(TElSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_UseIPv6(TElSimpleSSLClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_UseInternalSocket(TElSimpleSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_UseInternalSocket(TElSimpleSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnCertificateChoose(TElSimpleSSLClientHandle _Handle, TSBChooseCertificateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnCertificateChoose(TElSimpleSSLClientHandle _Handle, TSBChooseCertificateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnCertificateNeededEx(TElSimpleSSLClientHandle _Handle, TSBCertificateNeededExEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnCertificateNeededEx(TElSimpleSSLClientHandle _Handle, TSBCertificateNeededExEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnCertificateValidate(TElSimpleSSLClientHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnCertificateValidate(TElSimpleSSLClientHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnCiphersNegotiated(TElSimpleSSLClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnCiphersNegotiated(TElSimpleSSLClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnCloseConnection(TElSimpleSSLClientHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnCloseConnection(TElSimpleSSLClientHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnError(TElSimpleSSLClientHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnError(TElSimpleSSLClientHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnReceive(TElSimpleSSLClientHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnReceive(TElSimpleSSLClientHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnSend(TElSimpleSSLClientHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnSend(TElSimpleSSLClientHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnExtensionsReceived(TElSimpleSSLClientHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnExtensionsReceived(TElSimpleSSLClientHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnExtensionsPrepared(TElSimpleSSLClientHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnExtensionsPrepared(TElSimpleSSLClientHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnCertificateStatus(TElSimpleSSLClientHandle _Handle, TSBCertificateStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnCertificateStatus(TElSimpleSSLClientHandle _Handle, TSBCertificateStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnKeyNeeded(TElSimpleSSLClientHandle _Handle, TSBClientKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnKeyNeeded(TElSimpleSSLClientHandle _Handle, TSBClientKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_get_OnRenegotiationRequest(TElSimpleSSLClientHandle _Handle, TSBRenegotiationRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_set_OnRenegotiationRequest(TElSimpleSSLClientHandle _Handle, TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSLClient_Create(TComponentHandle AOwner, TElCustomSimpleSSLClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESSLCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCustomSimpleSSLClient;
typedef TElCustomSimpleSSLClient ElCustomSimpleSSLClient;
class TElSimpleSSLClient;
typedef TElSimpleSSLClient ElSimpleSSLClient;

#ifdef SB_USE_CLASS_TELCUSTOMSIMPLESSLCLIENT
class TElCustomSimpleSSLClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCustomSimpleSSLClient)
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		TElClientSSLExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		TElCustomSSLExtensions* _Inst_PeerExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_InternalSocket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSLCLASS
		TElSSLClass* _Inst_Control;
#endif /* SB_USE_CLASS_TELSSLCLASS */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		TElSocketSettings* _Inst_SocketSettings;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		TElSSLConnectionInfo* _Inst_ConnectionInfo;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSSLCLIENT
		TElSSLClient* _Inst_Client;
#endif /* SB_USE_CLASS_TELSSLCLIENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_WebTunnelRequestHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_WebTunnelResponseHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_WebTunnelRequestHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_WebTunnelResponseHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_SocketBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELPORTKNOCK
		TElPortKnock* _Inst_PortKnock;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		TElDNSSettings* _Inst_DNS;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

		void initInstances();

	public:
		void Interrupt();

		virtual void Close(bool Silent);

		virtual void Open();

		void SendText(const std::string &S);

		void Join(TElCustomSimpleSSLClient &Client);

		void Join(TElCustomSimpleSSLClient *Client);

		void SendData(void * Buffer, int32_t Size);

		void ReceiveData(void * Buffer, int32_t &Size, bool ReadAll);

		bool SendKeepAlive();

		void InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason);

		bool CanReceive(int32_t Timeout);

		void RenegotiateCiphers();

		virtual void get_RemoteHost(std::string &OutResult);

		virtual void get_RemoteIP(std::string &OutResult);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElCustomSimpleSSLClient, Active);

		virtual uint8_t get_CipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CipherSuite, TElCustomSimpleSSLClient, CipherSuite);

		virtual bool get_CipherSuites(uint8_t Index);

		virtual void set_CipherSuites(uint8_t Index, bool Value);

		virtual int32_t get_CipherSuitePriorities(uint8_t Index);

		virtual void set_CipherSuitePriorities(uint8_t Index, int32_t Value);

		virtual uint8_t get_CompressionAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithm, TElCustomSimpleSSLClient, CompressionAlgorithm);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

		virtual TSBVersion get_CurrentVersion();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_CurrentVersion, TElCustomSimpleSSLClient, CurrentVersion);

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		virtual TElClientSSLExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElClientSSLExtensions*, get_Extensions, TElCustomSimpleSSLClient, Extensions);
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		virtual TElCustomSSLExtensions* get_PeerExtensions();

		SB_DECLARE_PROPERTY_GET(TElCustomSSLExtensions*, get_PeerExtensions, TElCustomSimpleSSLClient, PeerExtensions);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

		virtual int64_t get_TotalBytesSent();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesSent, TElCustomSimpleSSLClient, TotalBytesSent);

		virtual int64_t get_TotalBytesReceived();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesReceived, TElCustomSimpleSSLClient, TotalBytesReceived);

		virtual int32_t get_ProxyResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ProxyResult, TElCustomSimpleSSLClient, ProxyResult);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElCustomSimpleSSLClient, UsingIPv6);
#endif

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_InternalSocket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_InternalSocket, TElCustomSimpleSSLClient, InternalSocket);
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSSLCLASS
		virtual TElSSLClass* get_Control();

		SB_DECLARE_PROPERTY_GET(TElSSLClass*, get_Control, TElCustomSimpleSSLClient, Control);
#endif /* SB_USE_CLASS_TELSSLCLASS */

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		virtual TElSocketSettings* get_SocketSettings();

		SB_DECLARE_PROPERTY_GET(TElSocketSettings*, get_SocketSettings, TElCustomSimpleSSLClient, SocketSettings);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		virtual TElSSLConnectionInfo* get_ConnectionInfo();

		SB_DECLARE_PROPERTY_GET(TElSSLConnectionInfo*, get_ConnectionInfo, TElCustomSimpleSSLClient, ConnectionInfo);
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElCustomSimpleSSLClient, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElCustomSimpleSSLClient, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSSLCLIENT
		virtual TElSSLClient* get_Client();

		SB_DECLARE_PROPERTY_GET(TElSSLClient*, get_Client, TElCustomSimpleSSLClient, Client);
#endif /* SB_USE_CLASS_TELSSLCLIENT */

		virtual int32_t get_SocketTimeout();

		virtual void set_SocketTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketTimeout, set_SocketTimeout, TElCustomSimpleSSLClient, SocketTimeout);

		virtual TSBVersions get_Versions();

		virtual void set_Versions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_Versions, set_Versions, TElCustomSimpleSSLClient, Versions);

		virtual TSBSSLOptions get_SSLOptions();

		virtual void set_SSLOptions(TSBSSLOptions Value);

		SB_DECLARE_PROPERTY(TSBSSLOptions, get_SSLOptions, set_SSLOptions, TElCustomSimpleSSLClient, SSLOptions);

		virtual void get_LocalAddress(std::string &OutResult);

		virtual void set_LocalAddress(const std::string &Value);

		virtual int32_t get_LocalPort();

		virtual void set_LocalPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_LocalPort, set_LocalPort, TElCustomSimpleSSLClient, LocalPort);

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElCustomSimpleSSLClient, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElCustomSimpleSSLClient, OutgoingSpeedLimit);

		virtual bool get_UseSSLSessionResumption();

		virtual void set_UseSSLSessionResumption(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSLSessionResumption, set_UseSSLSessionResumption, TElCustomSimpleSSLClient, UseSSLSessionResumption);

		virtual bool get_ForceResumeIfDestinationChanges();

		virtual void set_ForceResumeIfDestinationChanges(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceResumeIfDestinationChanges, set_ForceResumeIfDestinationChanges, TElCustomSimpleSSLClient, ForceResumeIfDestinationChanges);

		virtual TElSocksAuthentication get_SocksAuthentication();

		virtual void set_SocksAuthentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_SocksAuthentication, set_SocksAuthentication, TElCustomSimpleSSLClient, SocksAuthentication);

		virtual void get_SocksPassword(std::string &OutResult);

		virtual void set_SocksPassword(const std::string &Value);

		virtual int32_t get_SocksPort();

		virtual void set_SocksPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocksPort, set_SocksPort, TElCustomSimpleSSLClient, SocksPort);

		virtual bool get_SocksResolveAddress();

		virtual void set_SocksResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksResolveAddress, set_SocksResolveAddress, TElCustomSimpleSSLClient, SocksResolveAddress);

		virtual void get_SocksServer(std::string &OutResult);

		virtual void set_SocksServer(const std::string &Value);

		virtual void get_SocksUserCode(std::string &OutResult);

		virtual void set_SocksUserCode(const std::string &Value);

		virtual TElSocksVersion get_SocksVersion();

		virtual void set_SocksVersion(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_SocksVersion, set_SocksVersion, TElCustomSimpleSSLClient, SocksVersion);

#ifdef SB_WINDOWS
		virtual bool get_SocksUseIPv6();

		virtual void set_SocksUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksUseIPv6, set_SocksUseIPv6, TElCustomSimpleSSLClient, SocksUseIPv6);
#endif

		virtual bool get_UseSocks();

		virtual void set_UseSocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSocks, set_UseSocks, TElCustomSimpleSSLClient, UseSocks);

		virtual bool get_UseWebTunneling();

		virtual void set_UseWebTunneling(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseWebTunneling, set_UseWebTunneling, TElCustomSimpleSSLClient, UseWebTunneling);

		virtual void get_WebTunnelAddress(std::string &OutResult);

		virtual void set_WebTunnelAddress(const std::string &Value);

		virtual TElWebTunnelAuthentication get_WebTunnelAuthentication();

		virtual void set_WebTunnelAuthentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_WebTunnelAuthentication, set_WebTunnelAuthentication, TElCustomSimpleSSLClient, WebTunnelAuthentication);

		virtual void get_WebTunnelPassword(std::string &OutResult);

		virtual void set_WebTunnelPassword(const std::string &Value);

		virtual int32_t get_WebTunnelPort();

		virtual void set_WebTunnelPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_WebTunnelPort, set_WebTunnelPort, TElCustomSimpleSSLClient, WebTunnelPort);

		virtual void get_WebTunnelUserId(std::string &OutResult);

		virtual void set_WebTunnelUserId(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelRequestHeaders, TElCustomSimpleSSLClient, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelRequestHeaders, TElCustomSimpleSSLClient, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelResponseHeaders, TElCustomSimpleSSLClient, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelResponseHeaders, TElCustomSimpleSSLClient, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_WebTunnelResponseBody(std::string &OutResult);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_SocketBinding();

		virtual void set_SocketBinding(TElClientSocketBinding &Value);

		virtual void set_SocketBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_SocketBinding, set_SocketBinding, TElCustomSimpleSSLClient, SocketBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		virtual void get_SRPUserName(std::string &OutResult);

		virtual void set_SRPUserName(const std::string &Value);

		virtual void get_SRPPassword(std::string &OutResult);

		virtual void set_SRPPassword(const std::string &Value);

		virtual TSBRenegotiationAttackPreventionMode get_RenegotiationAttackPreventionMode();

		virtual void set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value);

		SB_DECLARE_PROPERTY(TSBRenegotiationAttackPreventionMode, get_RenegotiationAttackPreventionMode, set_RenegotiationAttackPreventionMode, TElCustomSimpleSSLClient, RenegotiationAttackPreventionMode);

#ifdef SB_USE_CLASS_TELPORTKNOCK
		virtual TElPortKnock* get_PortKnock();

		virtual void set_PortKnock(TElPortKnock &Value);

		virtual void set_PortKnock(TElPortKnock *Value);

		SB_DECLARE_PROPERTY(TElPortKnock*, get_PortKnock, set_PortKnock, TElCustomSimpleSSLClient, PortKnock);
#endif /* SB_USE_CLASS_TELPORTKNOCK */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElCustomSimpleSSLClient, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

		virtual void get_MessageLoop(TElMessageLoopEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_MessageLoop(TElMessageLoopEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElCustomSimpleSSLClient(TElCustomSimpleSSLClientHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomSimpleSSLClient(TComponent &AOwner);

		explicit TElCustomSimpleSSLClient(TComponent *AOwner);

		virtual ~TElCustomSimpleSSLClient();

};
#endif /* SB_USE_CLASS_TELCUSTOMSIMPLESSLCLIENT */

#ifdef SB_USE_CLASS_TELSIMPLESSLCLIENT
class TElSimpleSSLClient: public TElCustomSimpleSSLClient
{
	private:
		SB_DISABLE_COPY(TElSimpleSSLClient)
	public:
		virtual void StartTLS();

		virtual void StopTLS(bool Silent);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElSimpleSSLClient, Enabled);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSimpleSSLClient, Port);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElSimpleSSLClient, UseIPv6);
#endif

		virtual bool get_UseInternalSocket();

		virtual void set_UseInternalSocket(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseInternalSocket, set_UseInternalSocket, TElSimpleSSLClient, UseInternalSocket);

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

		virtual void get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSBSendEvent pMethodValue, void * pDataValue);

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

		TElSimpleSSLClient(TElSimpleSSLClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleSSLClient(TComponent &AOwner);

		explicit TElSimpleSSLClient(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSIMPLESSLCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSIMPLESSL */
