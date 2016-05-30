#ifndef __INC_SBSIMPLESSH
#define __INC_SBSIMPLESSH

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
#include "sbcryptoprov.h"
#include "sbgssapi.h"
#include "sbsshcommon.h"
#include "sbsshterm.h"
#include "sbsocket.h"
#include "sbportknock.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssecconsts.h"
#include "sbdnssectypes.h"
#endif
#include "sbsshclient.h"
#include "sbsshconstants.h"
#include "sbsshkeystorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSimpleSSHClientHandle;

typedef TElSimpleSSHClientHandle ElSimpleSSHClientHandle;

#ifdef SB_USE_CLASS_TELSIMPLESSHCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_Interrupt(TElSimpleSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_Close(TElSimpleSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_Close_1(TElSimpleSSHClientHandle _Handle, int8_t FlushPendingData);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_Open(TElSimpleSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_RenegotiateCiphers(TElSimpleSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_SendData(TElSimpleSSHClientHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_ReceiveData(TElSimpleSSHClientHandle _Handle, void * Buffer, int32_t * Size, void * StdErrBuffer, int32_t * StdErrSize);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_SendText(TElSimpleSSHClientHandle _Handle, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_ReceiveText(TElSimpleSSHClientHandle _Handle, char * pcText, int32_t * szText, char * pcStdErrText, int32_t * szStdErrText);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_ReceiveText_1(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_CanReceive(TElSimpleSSHClientHandle _Handle, int32_t Timeout, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_SendKeepAlive(TElSimpleSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_ExecuteCommand(TElSimpleSSHClientHandle _Handle, const char * pcCmd, int32_t szCmd, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_ExecuteCommand_1(TElSimpleSSHClientHandle _Handle, const char * pcCmd, int32_t szCmd, int8_t RedirectStdErr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_ExecuteCommand_2(TElSimpleSSHClientHandle _Handle, const char * pcCmd, int32_t szCmd, uint8_t pStdErrData[], int32_t * szStdErrData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_ExecuteCommand_3(TElSimpleSSHClientHandle _Handle, const char * pcCmd, int32_t szCmd, int8_t RedirectStdErr, int8_t KeepConnectionOpen, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_ExecuteCommand_4(TElSimpleSSHClientHandle _Handle, const char * pcCmd, int32_t szCmd, uint8_t pStdErrData[], int32_t * szStdErrData, int8_t KeepConnectionOpen, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_SendEOF(TElSimpleSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_EncryptionAlgorithms(TElSimpleSSHClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_EncryptionAlgorithms(TElSimpleSSHClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_CompressionAlgorithms(TElSimpleSSHClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_CompressionAlgorithms(TElSimpleSSHClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_MacAlgorithms(TElSimpleSSHClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_MacAlgorithms(TElSimpleSSHClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_KexAlgorithms(TElSimpleSSHClientHandle _Handle, int8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_KexAlgorithms(TElSimpleSSHClientHandle _Handle, int8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_PublicKeyAlgorithms(TElSimpleSSHClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_PublicKeyAlgorithms(TElSimpleSSHClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_EncryptionAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_EncryptionAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_CompressionAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_CompressionAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_MacAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_MacAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_KexAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, int8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_KexAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, int8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_PublicKeyAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_PublicKeyAlgorithmPriorities(TElSimpleSSHClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_AuthTypePriorities(TElSimpleSSHClientHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_AuthTypePriorities(TElSimpleSSHClientHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Active(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ServerSoftwareName(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Version(TElSimpleSSHClientHandle _Handle, TSSHVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ServerCloseReason(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_EncryptionAlgorithmServerToClient(TElSimpleSSHClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_EncryptionAlgorithmClientToServer(TElSimpleSSHClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_CompressionAlgorithmServerToClient(TElSimpleSSHClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_CompressionAlgorithmClientToServer(TElSimpleSSHClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_MacAlgorithmServerToClient(TElSimpleSSHClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_MacAlgorithmClientToServer(TElSimpleSSHClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_KexAlgorithm(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_PublicKeyAlgorithm(TElSimpleSSHClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_KeyStorage(TElSimpleSSHClientHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_KeyStorage(TElSimpleSSHClientHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_TerminalInfo(TElSimpleSSHClientHandle _Handle, TElTerminalInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_TerminalInfo(TElSimpleSSHClientHandle _Handle, TElTerminalInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ExitStatus(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ExitSignal(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ExitMessage(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_KbdIntName(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_KbdIntInstruction(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ExtendedDataType(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_RequestPasswordChange(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_RequestPasswordChange(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ServerKey(TElSimpleSSHClientHandle _Handle, TElSSHKeyHandle * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_UsingIPv6(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_TotalBytesSent(TElSimpleSSHClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_TotalBytesReceived(TElSimpleSSHClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_GSSMechanism(TElSimpleSSHClientHandle _Handle, TElGSSBaseMechanismHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_GSSMechanism(TElSimpleSSHClientHandle _Handle, TElGSSBaseMechanismHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_GSSHostName(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_GSSHostName(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_GSSDelegateCredentials(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_GSSDelegateCredentials(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_InternalSocket(TElSimpleSSHClientHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Command(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_Command(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Commands(TElSimpleSSHClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Commands(TElSimpleSSHClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Subsystem(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_Subsystem(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_AuthenticationTypes(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_AuthenticationTypes(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ClientHostname(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_ClientHostname(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ClientUsername(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_ClientUsername(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_CompressionLevel(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_CompressionLevel(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ForceCompression(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_ForceCompression(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SendCommandEOF(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SendCommandEOF(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Password(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_Password(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SoftwareName(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SoftwareName(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Username(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_Username(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Versions(TElSimpleSSHClientHandle _Handle, TSSHVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_Versions(TElSimpleSSHClientHandle _Handle, TSSHVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Address(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_Address(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Environment(TElSimpleSSHClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_RequestTerminal(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_RequestTerminal(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_TrustedKeys(TElSimpleSSHClientHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_TrustedKeys(TElSimpleSSHClientHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_CryptoProviderManager(TElSimpleSSHClientHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_CryptoProviderManager(TElSimpleSSHClientHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_DefaultWindowSize(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_DefaultWindowSize(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_MinWindowSize(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_MinWindowSize(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_MaxSSHPacketSize(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_MaxSSHPacketSize(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ThrottleControl(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_ThrottleControl(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_RaiseExceptionOnCommandTimeout(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_RaiseExceptionOnCommandTimeout(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_RaiseExceptionOnTunnelFailure(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_RaiseExceptionOnTunnelFailure(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocketBinding(TElSimpleSSHClientHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocketBinding(TElSimpleSSHClientHandle _Handle, TElClientSocketBindingHandle Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_DNS(TElSimpleSSHClientHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_DNS(TElSimpleSSHClientHandle _Handle, TElDNSSettingsHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_PortKnock(TElSimpleSSHClientHandle _Handle, TElPortKnockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_PortKnock(TElSimpleSSHClientHandle _Handle, TElPortKnockHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocketSettings(TElSimpleSSHClientHandle _Handle, TElSocketSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_Port(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_Port(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocketTimeout(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocketTimeout(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_CommandTimeout(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_CommandTimeout(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocksAuthentication(TElSimpleSSHClientHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocksAuthentication(TElSimpleSSHClientHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocksPassword(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocksPassword(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocksPort(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocksPort(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocksResolveAddress(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocksResolveAddress(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocksServer(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocksServer(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocksUserCode(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocksUserCode(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocksVersion(TElSimpleSSHClientHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocksVersion(TElSimpleSSHClientHandle _Handle, TElSocksVersionRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SocksUseIPv6(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SocksUseIPv6(TElSimpleSSHClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_UseInternalSocket(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_UseInternalSocket(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_UseSocks(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_UseSocks(TElSimpleSSHClientHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_UseIPv6(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_UseIPv6(TElSimpleSSHClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_UseWebTunneling(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_UseWebTunneling(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelAddress(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_WebTunnelAddress(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelAuthentication(TElSimpleSSHClientHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_WebTunnelAuthentication(TElSimpleSSHClientHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelPassword(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_WebTunnelPassword(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelPort(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_WebTunnelPort(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelUserId(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_WebTunnelUserId(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelRequestHeaders(TElSimpleSSHClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelResponseHeaders(TElSimpleSSHClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelRequestHeaders(TElSimpleSSHClientHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelResponseHeaders(TElSimpleSSHClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_WebTunnelResponseBody(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ProxyResult(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_ErrorString(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_LocalAddress(TElSimpleSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_LocalAddress(TElSimpleSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_LocalPort(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_LocalPort(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_SSHAuthOrder(TElSimpleSSHClientHandle _Handle, TSBSSHAuthOrderRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_SSHAuthOrder(TElSimpleSSHClientHandle _Handle, TSBSSHAuthOrderRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_CertAuthMode(TElSimpleSSHClientHandle _Handle, TSBSSHCertAuthModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_CertAuthMode(TElSimpleSSHClientHandle _Handle, TSBSSHCertAuthModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_AutoAdjustCiphers(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_AutoAdjustCiphers(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_UseUTF8(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_UseUTF8(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_NoCharacterEncoding(TElSimpleSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_NoCharacterEncoding(TElSimpleSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_AuthAttempts(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_AuthAttempts(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_IncomingSpeedLimit(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_IncomingSpeedLimit(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OutgoingSpeedLimit(TElSimpleSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OutgoingSpeedLimit(TElSimpleSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnAuthenticationKeyboard(TElSimpleSSHClientHandle _Handle, TSSHAuthenticationKeyboardEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnAuthenticationKeyboard(TElSimpleSSHClientHandle _Handle, TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnAuthenticationFailed(TElSimpleSSHClientHandle _Handle, TSSHAuthenticationFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnAuthenticationFailed(TElSimpleSSHClientHandle _Handle, TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnAuthenticationSuccess(TElSimpleSSHClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnAuthenticationSuccess(TElSimpleSSHClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnAuthenticationStart(TElSimpleSSHClientHandle _Handle, TSSHAuthenticationStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnAuthenticationStart(TElSimpleSSHClientHandle _Handle, TSSHAuthenticationStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnAuthenticationAttempt(TElSimpleSSHClientHandle _Handle, TSSHAuthenticationAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnAuthenticationAttempt(TElSimpleSSHClientHandle _Handle, TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnBanner(TElSimpleSSHClientHandle _Handle, TSSHBannerEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnBanner(TElSimpleSSHClientHandle _Handle, TSSHBannerEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnCloseConnection(TElSimpleSSHClientHandle _Handle, TSSHCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnCloseConnection(TElSimpleSSHClientHandle _Handle, TSSHCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnError(TElSimpleSSHClientHandle _Handle, TSSHErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnError(TElSimpleSSHClientHandle _Handle, TSSHErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnTunnelError(TElSimpleSSHClientHandle _Handle, TSSHErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnTunnelError(TElSimpleSSHClientHandle _Handle, TSSHErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnKeyValidate(TElSimpleSSHClientHandle _Handle, TSSHKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnKeyValidate(TElSimpleSSHClientHandle _Handle, TSSHKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnReceive(TElSimpleSSHClientHandle _Handle, TSSHReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnReceive(TElSimpleSSHClientHandle _Handle, TSSHReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnSend(TElSimpleSSHClientHandle _Handle, TSSHSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnSend(TElSimpleSSHClientHandle _Handle, TSSHSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnPrivateKeyNeeded(TElSimpleSSHClientHandle _Handle, TSSHPrivateKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnPrivateKeyNeeded(TElSimpleSSHClientHandle _Handle, TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnSendCommandRequest(TElSimpleSSHClientHandle _Handle, TSSHCommandExecutionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnSendCommandRequest(TElSimpleSSHClientHandle _Handle, TSSHCommandExecutionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnCiphersNegotiated(TElSimpleSSHClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnCiphersNegotiated(TElSimpleSSHClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnPasswordChangeRequest(TElSimpleSSHClientHandle _Handle, TSSHPasswordChangeRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnPasswordChangeRequest(TElSimpleSSHClientHandle _Handle, TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnKexInitReceived(TElSimpleSSHClientHandle _Handle, TSSHKexInitReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnKexInitReceived(TElSimpleSSHClientHandle _Handle, TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_MessageLoop(TElSimpleSSHClientHandle _Handle, TSSHMessageLoopEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_MessageLoop(TElSimpleSSHClientHandle _Handle, TSSHMessageLoopEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnDNSKeyNeeded(TElSimpleSSHClientHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnDNSKeyNeeded(TElSimpleSSHClientHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnDNSKeyValidate(TElSimpleSSHClientHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnDNSKeyValidate(TElSimpleSSHClientHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_get_OnDNSResolve(TElSimpleSSHClientHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_set_OnDNSResolve(TElSimpleSSHClientHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHClient_Create(TComponentHandle AOwner, TElSimpleSSHClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESSHCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSimpleSSHClient;
typedef TElSimpleSSHClient ElSimpleSSHClient;

#ifdef SB_USE_CLASS_TELSIMPLESSHCLIENT
class TElSimpleSSHClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSimpleSSHClient)
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_KeyStorage;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELTERMINALINFO
		TElTerminalInfo* _Inst_TerminalInfo;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TELSSHKEY
		TElSSHKey* _Inst_ServerKey;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
		TElGSSBaseMechanism* _Inst_GSSMechanism;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_InternalSocket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Commands;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Commands;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif
#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Environment;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Environment;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_TrustedKeys;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_SocketBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		TElDNSSettings* _Inst_DNS;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_USE_CLASS_TELPORTKNOCK
		TElPortKnock* _Inst_PortKnock;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		TElSocketSettings* _Inst_SocketSettings;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
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

		void initInstances();

	public:
		void Interrupt();

		void Close();

		void Close(bool FlushPendingData);

		void Open();

		void RenegotiateCiphers();

		void SendData(void * Buffer, int32_t Size);

		void ReceiveData(void * Buffer, int32_t &Size, void * StdErrBuffer, int32_t &StdErrSize);

		void SendText(const std::string &S);

		void ReceiveText(std::string &Text, std::string &StdErrText);

		void ReceiveText(std::string &OutResult);

		bool CanReceive(int32_t Timeout);

		void SendKeepAlive();

		void ExecuteCommand(const std::string &Cmd, std::vector<uint8_t> &OutResult);

		void ExecuteCommand(const std::string &Cmd, bool RedirectStdErr, std::vector<uint8_t> &OutResult);

		void ExecuteCommand(const std::string &Cmd, std::vector<uint8_t> &StdErrData, std::vector<uint8_t> &OutResult);

		void ExecuteCommand(const std::string &Cmd, bool RedirectStdErr, bool KeepConnectionOpen, std::vector<uint8_t> &OutResult);

		void ExecuteCommand(const std::string &Cmd, std::vector<uint8_t> &StdErrData, bool KeepConnectionOpen, std::vector<uint8_t> &OutResult);

		void SendEOF();

		virtual bool get_EncryptionAlgorithms(uint8_t Index);

		virtual void set_EncryptionAlgorithms(uint8_t Index, bool Value);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

		virtual bool get_MacAlgorithms(uint8_t Index);

		virtual void set_MacAlgorithms(uint8_t Index, bool Value);

		virtual bool get_KexAlgorithms(int8_t Index);

		virtual void set_KexAlgorithms(int8_t Index, bool Value);

		virtual bool get_PublicKeyAlgorithms(uint8_t Index);

		virtual void set_PublicKeyAlgorithms(uint8_t Index, bool Value);

		virtual int32_t get_EncryptionAlgorithmPriorities(uint8_t Index);

		virtual void set_EncryptionAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_CompressionAlgorithmPriorities(uint8_t Index);

		virtual void set_CompressionAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_MacAlgorithmPriorities(uint8_t Index);

		virtual void set_MacAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_KexAlgorithmPriorities(int8_t Index);

		virtual void set_KexAlgorithmPriorities(int8_t Index, int32_t Value);

		virtual int32_t get_PublicKeyAlgorithmPriorities(uint8_t Index);

		virtual void set_PublicKeyAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_AuthTypePriorities(int32_t Index);

		virtual void set_AuthTypePriorities(int32_t Index, int32_t Value);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSimpleSSHClient, Active);

		virtual void get_ServerSoftwareName(std::string &OutResult);

		virtual TSSHVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSSHVersion, get_Version, TElSimpleSSHClient, Version);

		virtual void get_ServerCloseReason(std::string &OutResult);

		virtual uint8_t get_EncryptionAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_EncryptionAlgorithmServerToClient, TElSimpleSSHClient, EncryptionAlgorithmServerToClient);

		virtual uint8_t get_EncryptionAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_EncryptionAlgorithmClientToServer, TElSimpleSSHClient, EncryptionAlgorithmClientToServer);

		virtual uint8_t get_CompressionAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithmServerToClient, TElSimpleSSHClient, CompressionAlgorithmServerToClient);

		virtual uint8_t get_CompressionAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithmClientToServer, TElSimpleSSHClient, CompressionAlgorithmClientToServer);

		virtual uint8_t get_MacAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_MacAlgorithmServerToClient, TElSimpleSSHClient, MacAlgorithmServerToClient);

		virtual uint8_t get_MacAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_MacAlgorithmClientToServer, TElSimpleSSHClient, MacAlgorithmClientToServer);

		virtual int8_t get_KexAlgorithm();

		SB_DECLARE_PROPERTY_GET(int8_t, get_KexAlgorithm, TElSimpleSSHClient, KexAlgorithm);

		virtual uint8_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_PublicKeyAlgorithm, TElSimpleSSHClient, PublicKeyAlgorithm);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_KeyStorage();

		virtual void set_KeyStorage(TElSSHCustomKeyStorage &Value);

		virtual void set_KeyStorage(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_KeyStorage, set_KeyStorage, TElSimpleSSHClient, KeyStorage);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELTERMINALINFO
		virtual TElTerminalInfo* get_TerminalInfo();

		virtual void set_TerminalInfo(TElTerminalInfo &Value);

		virtual void set_TerminalInfo(TElTerminalInfo *Value);

		SB_DECLARE_PROPERTY(TElTerminalInfo*, get_TerminalInfo, set_TerminalInfo, TElSimpleSSHClient, TerminalInfo);
#endif /* SB_USE_CLASS_TELTERMINALINFO */

		virtual int32_t get_ExitStatus();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExitStatus, TElSimpleSSHClient, ExitStatus);

		virtual void get_ExitSignal(std::string &OutResult);

		virtual void get_ExitMessage(std::string &OutResult);

		virtual void get_KbdIntName(std::string &OutResult);

		virtual void get_KbdIntInstruction(std::string &OutResult);

		virtual int32_t get_ExtendedDataType();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExtendedDataType, TElSimpleSSHClient, ExtendedDataType);

		virtual bool get_RequestPasswordChange();

		virtual void set_RequestPasswordChange(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestPasswordChange, set_RequestPasswordChange, TElSimpleSSHClient, RequestPasswordChange);

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual TElSSHKey* get_ServerKey();

		SB_DECLARE_PROPERTY_GET(TElSSHKey*, get_ServerKey, TElSimpleSSHClient, ServerKey);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElSimpleSSHClient, UsingIPv6);
#endif

		virtual int64_t get_TotalBytesSent();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesSent, TElSimpleSSHClient, TotalBytesSent);

		virtual int64_t get_TotalBytesReceived();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesReceived, TElSimpleSSHClient, TotalBytesReceived);

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
		virtual TElGSSBaseMechanism* get_GSSMechanism();

		virtual void set_GSSMechanism(TElGSSBaseMechanism &Value);

		virtual void set_GSSMechanism(TElGSSBaseMechanism *Value);

		SB_DECLARE_PROPERTY(TElGSSBaseMechanism*, get_GSSMechanism, set_GSSMechanism, TElSimpleSSHClient, GSSMechanism);
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

		virtual void get_GSSHostName(std::string &OutResult);

		virtual void set_GSSHostName(const std::string &Value);

		virtual bool get_GSSDelegateCredentials();

		virtual void set_GSSDelegateCredentials(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GSSDelegateCredentials, set_GSSDelegateCredentials, TElSimpleSSHClient, GSSDelegateCredentials);

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_InternalSocket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_InternalSocket, TElSimpleSSHClient, InternalSocket);
#endif /* SB_USE_CLASS_TELSOCKET */

		virtual void get_Command(std::string &OutResult);

		virtual void set_Command(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Commands();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Commands, TElSimpleSSHClient, Commands);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Commands();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Commands, TElSimpleSSHClient, Commands);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_Subsystem(std::string &OutResult);

		virtual void set_Subsystem(const std::string &Value);

		virtual int32_t get_AuthenticationTypes();

		virtual void set_AuthenticationTypes(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthenticationTypes, set_AuthenticationTypes, TElSimpleSSHClient, AuthenticationTypes);

		virtual void get_ClientHostname(std::string &OutResult);

		virtual void set_ClientHostname(const std::string &Value);

		virtual void get_ClientUsername(std::string &OutResult);

		virtual void set_ClientUsername(const std::string &Value);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElSimpleSSHClient, CompressionLevel);

		virtual bool get_ForceCompression();

		virtual void set_ForceCompression(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCompression, set_ForceCompression, TElSimpleSSHClient, ForceCompression);

		virtual bool get_SendCommandEOF();

		virtual void set_SendCommandEOF(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SendCommandEOF, set_SendCommandEOF, TElSimpleSSHClient, SendCommandEOF);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_SoftwareName(std::string &OutResult);

		virtual void set_SoftwareName(const std::string &Value);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual TSSHVersions get_Versions();

		virtual void set_Versions(TSSHVersions Value);

		SB_DECLARE_PROPERTY(TSSHVersions, get_Versions, set_Versions, TElSimpleSSHClient, Versions);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Environment();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Environment, TElSimpleSSHClient, Environment);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual bool get_RequestTerminal();

		virtual void set_RequestTerminal(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestTerminal, set_RequestTerminal, TElSimpleSSHClient, RequestTerminal);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_TrustedKeys();

		virtual void set_TrustedKeys(TElSSHCustomKeyStorage &Value);

		virtual void set_TrustedKeys(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_TrustedKeys, set_TrustedKeys, TElSimpleSSHClient, TrustedKeys);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSimpleSSHClient, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual int32_t get_DefaultWindowSize();

		virtual void set_DefaultWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DefaultWindowSize, set_DefaultWindowSize, TElSimpleSSHClient, DefaultWindowSize);

		virtual int32_t get_MinWindowSize();

		virtual void set_MinWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinWindowSize, set_MinWindowSize, TElSimpleSSHClient, MinWindowSize);

		virtual int32_t get_MaxSSHPacketSize();

		virtual void set_MaxSSHPacketSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxSSHPacketSize, set_MaxSSHPacketSize, TElSimpleSSHClient, MaxSSHPacketSize);

		virtual bool get_ThrottleControl();

		virtual void set_ThrottleControl(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ThrottleControl, set_ThrottleControl, TElSimpleSSHClient, ThrottleControl);

		virtual bool get_RaiseExceptionOnCommandTimeout();

		virtual void set_RaiseExceptionOnCommandTimeout(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RaiseExceptionOnCommandTimeout, set_RaiseExceptionOnCommandTimeout, TElSimpleSSHClient, RaiseExceptionOnCommandTimeout);

		virtual bool get_RaiseExceptionOnTunnelFailure();

		virtual void set_RaiseExceptionOnTunnelFailure(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RaiseExceptionOnTunnelFailure, set_RaiseExceptionOnTunnelFailure, TElSimpleSSHClient, RaiseExceptionOnTunnelFailure);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_SocketBinding();

		virtual void set_SocketBinding(TElClientSocketBinding &Value);

		virtual void set_SocketBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_SocketBinding, set_SocketBinding, TElSimpleSSHClient, SocketBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElSimpleSSHClient, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

#ifdef SB_USE_CLASS_TELPORTKNOCK
		virtual TElPortKnock* get_PortKnock();

		virtual void set_PortKnock(TElPortKnock &Value);

		virtual void set_PortKnock(TElPortKnock *Value);

		SB_DECLARE_PROPERTY(TElPortKnock*, get_PortKnock, set_PortKnock, TElSimpleSSHClient, PortKnock);
#endif /* SB_USE_CLASS_TELPORTKNOCK */

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		virtual TElSocketSettings* get_SocketSettings();

		SB_DECLARE_PROPERTY_GET(TElSocketSettings*, get_SocketSettings, TElSimpleSSHClient, SocketSettings);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSimpleSSHClient, Port);

		virtual int32_t get_SocketTimeout();

		virtual void set_SocketTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketTimeout, set_SocketTimeout, TElSimpleSSHClient, SocketTimeout);

		virtual int32_t get_CommandTimeout();

		virtual void set_CommandTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CommandTimeout, set_CommandTimeout, TElSimpleSSHClient, CommandTimeout);

		virtual TElSocksAuthentication get_SocksAuthentication();

		virtual void set_SocksAuthentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_SocksAuthentication, set_SocksAuthentication, TElSimpleSSHClient, SocksAuthentication);

		virtual void get_SocksPassword(std::string &OutResult);

		virtual void set_SocksPassword(const std::string &Value);

		virtual int32_t get_SocksPort();

		virtual void set_SocksPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocksPort, set_SocksPort, TElSimpleSSHClient, SocksPort);

		virtual bool get_SocksResolveAddress();

		virtual void set_SocksResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksResolveAddress, set_SocksResolveAddress, TElSimpleSSHClient, SocksResolveAddress);

		virtual void get_SocksServer(std::string &OutResult);

		virtual void set_SocksServer(const std::string &Value);

		virtual void get_SocksUserCode(std::string &OutResult);

		virtual void set_SocksUserCode(const std::string &Value);

		virtual TElSocksVersion get_SocksVersion();

		virtual void set_SocksVersion(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_SocksVersion, set_SocksVersion, TElSimpleSSHClient, SocksVersion);

#ifdef SB_WINDOWS
		virtual bool get_SocksUseIPv6();

		virtual void set_SocksUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksUseIPv6, set_SocksUseIPv6, TElSimpleSSHClient, SocksUseIPv6);
#endif

		virtual bool get_UseInternalSocket();

		virtual void set_UseInternalSocket(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseInternalSocket, set_UseInternalSocket, TElSimpleSSHClient, UseInternalSocket);

		virtual bool get_UseSocks();

		virtual void set_UseSocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSocks, set_UseSocks, TElSimpleSSHClient, UseSocks);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElSimpleSSHClient, UseIPv6);
#endif

		virtual bool get_UseWebTunneling();

		virtual void set_UseWebTunneling(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseWebTunneling, set_UseWebTunneling, TElSimpleSSHClient, UseWebTunneling);

		virtual void get_WebTunnelAddress(std::string &OutResult);

		virtual void set_WebTunnelAddress(const std::string &Value);

		virtual TElWebTunnelAuthentication get_WebTunnelAuthentication();

		virtual void set_WebTunnelAuthentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_WebTunnelAuthentication, set_WebTunnelAuthentication, TElSimpleSSHClient, WebTunnelAuthentication);

		virtual void get_WebTunnelPassword(std::string &OutResult);

		virtual void set_WebTunnelPassword(const std::string &Value);

		virtual int32_t get_WebTunnelPort();

		virtual void set_WebTunnelPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_WebTunnelPort, set_WebTunnelPort, TElSimpleSSHClient, WebTunnelPort);

		virtual void get_WebTunnelUserId(std::string &OutResult);

		virtual void set_WebTunnelUserId(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelRequestHeaders, TElSimpleSSHClient, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelRequestHeaders, TElSimpleSSHClient, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelResponseHeaders, TElSimpleSSHClient, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelResponseHeaders, TElSimpleSSHClient, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_WebTunnelResponseBody(std::string &OutResult);

		virtual int32_t get_ProxyResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ProxyResult, TElSimpleSSHClient, ProxyResult);

		virtual void get_ErrorString(std::string &OutResult);

		virtual void get_LocalAddress(std::string &OutResult);

		virtual void set_LocalAddress(const std::string &Value);

		virtual int32_t get_LocalPort();

		virtual void set_LocalPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_LocalPort, set_LocalPort, TElSimpleSSHClient, LocalPort);

		virtual TSBSSHAuthOrder get_SSHAuthOrder();

		virtual void set_SSHAuthOrder(TSBSSHAuthOrder Value);

		SB_DECLARE_PROPERTY(TSBSSHAuthOrder, get_SSHAuthOrder, set_SSHAuthOrder, TElSimpleSSHClient, SSHAuthOrder);

		virtual TSBSSHCertAuthMode get_CertAuthMode();

		virtual void set_CertAuthMode(TSBSSHCertAuthMode Value);

		SB_DECLARE_PROPERTY(TSBSSHCertAuthMode, get_CertAuthMode, set_CertAuthMode, TElSimpleSSHClient, CertAuthMode);

		virtual bool get_AutoAdjustCiphers();

		virtual void set_AutoAdjustCiphers(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustCiphers, set_AutoAdjustCiphers, TElSimpleSSHClient, AutoAdjustCiphers);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSimpleSSHClient, UseUTF8);

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TElSimpleSSHClient, NoCharacterEncoding);

		virtual int32_t get_AuthAttempts();

		virtual void set_AuthAttempts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthAttempts, set_AuthAttempts, TElSimpleSSHClient, AuthAttempts);

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElSimpleSSHClient, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElSimpleSSHClient, OutgoingSpeedLimit);

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

		virtual void get_OnCloseConnection(TSSHCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSSHCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnTunnelError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTunnelError(TSSHErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyValidate(TSSHKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyValidate(TSSHKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TSSHReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSSHReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnSend(TSSHSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSSHSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSendCommandRequest(TSSHCommandExecutionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSendCommandRequest(TSSHCommandExecutionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_MessageLoop(TSSHMessageLoopEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_MessageLoop(TSSHMessageLoopEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElSimpleSSHClient(TElSimpleSSHClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleSSHClient(TComponent &AOwner);

		explicit TElSimpleSSHClient(TComponent *AOwner);

		virtual ~TElSimpleSSHClient();

};
#endif /* SB_USE_CLASS_TELSIMPLESSHCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSIMPLESSH */
