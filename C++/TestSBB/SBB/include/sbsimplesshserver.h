#ifndef __INC_SBSIMPLESSHSERVER
#define __INC_SBSIMPLESSHSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrandom.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbsshterm.h"
#include "sbsharedresource.h"
#include "sbsshconstants.h"
#include "sbzlib.h"
#include "sbsshkeystorage.h"
#include "sbsshutils.h"
#include "sbcryptoprov.h"
#include "sbsymmetriccrypto.h"
#include "sbcryptoprovmanager.h"
#include "sbhashfunction.h"
#include "sbsocket.h"
#include "sbsshcommon.h"
#include "sbsshpubkeycommon.h"
#include "sbsshhandlers.h"
#include "sbsshpubkeyhandler.h"
#include "sbsshforwardinghandlers.h"
#include "sbsshserver.h"
#include "sbconstants.h"
#include "sbusers.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SUnsupportedFunction 	"Unsupported"
#define SB_SSetKeyStoaregeError 	"Can not change KeyStorage on active server"
#define SB_SFailedBindSocket 	"Failed to bind server socket"

typedef TElClassHandle TElSimpleSSHServerHandle;

typedef TElClassHandle TElSSHUsersHandle;

typedef TElClassHandle TElCustomSessionThreadHandle;

typedef TElClassHandle TElSimpleSSHServerListeningThreadHandle;

typedef TElClassHandle TElSimpleSSHServerSessionThreadHandle;

typedef TElClassHandle TElSimpleSSHServerForwardingListeningThreadHandle;

typedef TElClassHandle TElSimpleSSHServerForwardingSessionThreadHandle;

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_SocketSettings(TElSimpleSSHServerHandle _Handle, TElSocketSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_Active(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_Active(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_AllowShell(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_AllowShell(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_AllowCommand(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_AllowCommand(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_AllowClientForwarding(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_AllowClientForwarding(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_AllowServerForwarding(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_AllowServerForwarding(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_ForceCompression(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_ForceCompression(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_Host(TElSimpleSSHServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_Host(TElSimpleSSHServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_Port(TElSimpleSSHServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_Port(TElSimpleSSHServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_DataPortRangeFrom(TElSimpleSSHServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_DataPortRangeFrom(TElSimpleSSHServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_DataPortRangeTo(TElSimpleSSHServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_DataPortRangeTo(TElSimpleSSHServerHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_UseIPv6(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_UseIPv6(TElSimpleSSHServerHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_SessionTimeout(TElSimpleSSHServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_SessionTimeout(TElSimpleSSHServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_KeyStorage(TElSimpleSSHServerHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_KeyStorage(TElSimpleSSHServerHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_SSHAuthOrder(TElSimpleSSHServerHandle _Handle, TSBSSHAuthOrderRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_SSHAuthOrder(TElSimpleSSHServerHandle _Handle, TSBSSHAuthOrderRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_SoftwareName(TElSimpleSSHServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_SoftwareName(TElSimpleSSHServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_CompressionLevel(TElSimpleSSHServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_CompressionLevel(TElSimpleSSHServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_AuthenticationTypes(TElSimpleSSHServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_AuthenticationTypes(TElSimpleSSHServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_CloseIfNoActiveTunnels(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_CloseIfNoActiveTunnels(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_UseUTF8(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_UseUTF8(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_CryptoProviderManager(TElSimpleSSHServerHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_CryptoProviderManager(TElSimpleSSHServerHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_NoCharacterEncoding(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_NoCharacterEncoding(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_LocalCharset(TElSimpleSSHServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_LocalCharset(TElSimpleSSHServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_RemoteCharset(TElSimpleSSHServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_RemoteCharset(TElSimpleSSHServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_ObfuscateHandshake(TElSimpleSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_ObfuscateHandshake(TElSimpleSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_ObfuscationPassword(TElSimpleSSHServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_ObfuscationPassword(TElSimpleSSHServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_Users(TElSimpleSSHServerHandle _Handle, TElSSHUsersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthAttempt(TElSimpleSSHServerHandle _Handle, TSSHAuthAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthAttempt(TElSimpleSSHServerHandle _Handle, TSSHAuthAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthFailed(TElSimpleSSHServerHandle _Handle, TSSHAuthenticationFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthFailed(TElSimpleSSHServerHandle _Handle, TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthBanner(TElSimpleSSHServerHandle _Handle, TSSHAuthBannerEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthBanner(TElSimpleSSHServerHandle _Handle, TSSHAuthBannerEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthPassword(TElSimpleSSHServerHandle _Handle, TSSHAuthPasswordEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthPassword(TElSimpleSSHServerHandle _Handle, TSSHAuthPasswordEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthPasswordChange(TElSimpleSSHServerHandle _Handle, TSSHAuthPasswordChangeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthPasswordChange(TElSimpleSSHServerHandle _Handle, TSSHAuthPasswordChangeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthPublicKey(TElSimpleSSHServerHandle _Handle, TSSHAuthPublicKeyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthPublicKey(TElSimpleSSHServerHandle _Handle, TSSHAuthPublicKeyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthHostbased(TElSimpleSSHServerHandle _Handle, TSSHAuthHostbasedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthHostbased(TElSimpleSSHServerHandle _Handle, TSSHAuthHostbasedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthKeyboard(TElSimpleSSHServerHandle _Handle, TSSHAuthKeyboardEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthKeyboard(TElSimpleSSHServerHandle _Handle, TSSHAuthKeyboardEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnAuthKeyboardResponse(TElSimpleSSHServerHandle _Handle, TSSHAuthKeyboardResponseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnAuthKeyboardResponse(TElSimpleSSHServerHandle _Handle, TSSHAuthKeyboardResponseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnFurtherAuthNeeded(TElSimpleSSHServerHandle _Handle, TSSHFurtherAuthNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnFurtherAuthNeeded(TElSimpleSSHServerHandle _Handle, TSSHFurtherAuthNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnBeforeOpenSession(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnBeforeOpenSession(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnBeforeOpenShell(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenShellEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnBeforeOpenShell(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenShellEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnBeforeOpenCommand(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenCommandEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnBeforeOpenCommand(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenCommandEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnBeforeOpenSubsystem(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenSubsystemEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnBeforeOpenSubsystem(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenSubsystemEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnBeforeOpenClientForwarding(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenClientForwardingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnBeforeOpenClientForwarding(TElSimpleSSHServerHandle _Handle, TSSHBeforeOpenClientForwardingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnOpenSession(TElSimpleSSHServerHandle _Handle, TSSHOpenSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnOpenSession(TElSimpleSSHServerHandle _Handle, TSSHOpenSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnOpenShell(TElSimpleSSHServerHandle _Handle, TSSHOpenShellEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnOpenShell(TElSimpleSSHServerHandle _Handle, TSSHOpenShellEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnOpenCommand(TElSimpleSSHServerHandle _Handle, TSSHOpenCommandEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnOpenCommand(TElSimpleSSHServerHandle _Handle, TSSHOpenCommandEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnOpenSubsystem(TElSimpleSSHServerHandle _Handle, TSSHOpenSubsystemEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnOpenSubsystem(TElSimpleSSHServerHandle _Handle, TSSHOpenSubsystemEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnOpenClientForwarding(TElSimpleSSHServerHandle _Handle, TSSHOpenClientForwardingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnOpenClientForwarding(TElSimpleSSHServerHandle _Handle, TSSHOpenClientForwardingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnOpenServerForwarding(TElSimpleSSHServerHandle _Handle, TSSHOpenServerForwardingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnOpenServerForwarding(TElSimpleSSHServerHandle _Handle, TSSHOpenServerForwardingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnServerForwardingFailed(TElSimpleSSHServerHandle _Handle, TSSHServerForwardingFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnServerForwardingFailed(TElSimpleSSHServerHandle _Handle, TSSHServerForwardingFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnServerForwardingRequest(TElSimpleSSHServerHandle _Handle, TSSHServerForwardingRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnServerForwardingRequest(TElSimpleSSHServerHandle _Handle, TSSHServerForwardingRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnServerForwardingCancel(TElSimpleSSHServerHandle _Handle, TSSHServerForwardingCancelEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnServerForwardingCancel(TElSimpleSSHServerHandle _Handle, TSSHServerForwardingCancelEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnSpecialMessageReceived(TElSimpleSSHServerHandle _Handle, TSSHSpecialMessageEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnSpecialMessageReceived(TElSimpleSSHServerHandle _Handle, TSSHSpecialMessageEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnKexInitReceived(TElSimpleSSHServerHandle _Handle, TSSHKexInitReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnKexInitReceived(TElSimpleSSHServerHandle _Handle, TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnOpenConnection(TElSimpleSSHServerHandle _Handle, TSSHOpenConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnOpenConnection(TElSimpleSSHServerHandle _Handle, TSSHOpenConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnCloseConnection(TElSimpleSSHServerHandle _Handle, TSSHCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnCloseConnection(TElSimpleSSHServerHandle _Handle, TSSHCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnError(TElSimpleSSHServerHandle _Handle, TSSHErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnError(TElSimpleSSHServerHandle _Handle, TSSHErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyReceive(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyReceive(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeySend(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeySendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeySend(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeySendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyClose(TElSimpleSSHServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyClose(TElSimpleSSHServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyError(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyError(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyOpen(TElSimpleSSHServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyOpen(TElSimpleSSHServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyStatus(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyStatus(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyAdd(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyAddEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyAdd(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyAddEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyRemove(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyRemoveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyRemove(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyRemoveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyList(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyListEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyList(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyListEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyListAttributes(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyListAttributesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyListAttributes(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyListAttributesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_get_OnPubKeyAttributeSupported(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyAttrubuteSupportedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_set_OnPubKeyAttributeSupported(TElSimpleSSHServerHandle _Handle, TSBSSHPublicKeyAttrubuteSupportedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServer_Create(TComponentHandle AOwner, TElSimpleSSHServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSSHUSERS
SB_IMPORT uint32_t SB_APIENTRY TElSSHUsers_AddSSHUser(TElSSHUsersHandle _Handle, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, TElSSHKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUsers_AddSSHUser_1(TElSSHUsersHandle _Handle, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, TElSSHKeyHandle Key, const char * pcBasePath, int32_t szBasePath);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUsers_UpdateSSHUser(TElSSHUsersHandle _Handle, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, TElSSHKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUsers_FindSSHUser(TElSSHUsersHandle _Handle, const char * pcUserName, int32_t szUserName, TElSSHUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUsers_IsValidSSHKey(TElSSHUsersHandle _Handle, const char * pcUserName, int32_t szUserName, TElSSHKeyHandle Key, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUsers_Create(TComponentHandle AOwner, TElUsersHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHUSERS */

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionThread_get_OnSessionTerminate(TElCustomSessionThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionThread_set_OnSessionTerminate(TElCustomSessionThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionThread_Create(int8_t CreateSuspended, uint32_t StackSize, TThreadHandle * OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERLISTENINGTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerListeningThread_get_Owner(TElSimpleSSHServerListeningThreadHandle _Handle, TElSimpleSSHServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerListeningThread_set_Owner(TElSimpleSSHServerListeningThreadHandle _Handle, TElSimpleSSHServerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerListeningThread_get_Socket(TElSimpleSSHServerListeningThreadHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerListeningThread_set_Socket(TElSimpleSSHServerListeningThreadHandle _Handle, TElSocketHandle Value);
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerListeningThread_Create(int8_t CreateSuspended, uint32_t StackSize, TThreadHandle * OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERSESSIONTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerSessionThread_get_Owner(TElSimpleSSHServerSessionThreadHandle _Handle, TElSimpleSSHServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerSessionThread_set_Owner(TElSimpleSSHServerSessionThreadHandle _Handle, TElSimpleSSHServerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerSessionThread_get_Socket(TElSimpleSSHServerSessionThreadHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerSessionThread_set_Socket(TElSimpleSSHServerSessionThreadHandle _Handle, TElSocketHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerSessionThread_get_SSHServer(TElSimpleSSHServerSessionThreadHandle _Handle, TElSSHServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerSessionThread_Create(TElSimpleSSHServerSessionThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGLISTENINGTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingListeningThread_get_Owner(TElSimpleSSHServerForwardingListeningThreadHandle _Handle, TElSimpleSSHServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingListeningThread_set_Owner(TElSimpleSSHServerForwardingListeningThreadHandle _Handle, TElSimpleSSHServerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingListeningThread_get_Socket(TElSimpleSSHServerForwardingListeningThreadHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingListeningThread_get_SSHServer(TElSimpleSSHServerForwardingListeningThreadHandle _Handle, TElSSHServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingListeningThread_set_SSHServer(TElSimpleSSHServerForwardingListeningThreadHandle _Handle, TElSSHServerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingListeningThread_Create(TElSimpleSSHServerForwardingListeningThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGSESSIONTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingSessionThread_InternalExecute(TElSimpleSSHServerForwardingSessionThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingSessionThread_get_Connection(TElSimpleSSHServerForwardingSessionThreadHandle _Handle, TElSSHTunnelConnectionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingSessionThread_set_Connection(TElSimpleSSHServerForwardingSessionThreadHandle _Handle, TElSSHTunnelConnectionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingSessionThread_get_Handler(TElSimpleSSHServerForwardingSessionThreadHandle _Handle, TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingSessionThread_get_Socket(TElSimpleSSHServerForwardingSessionThreadHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHServerForwardingSessionThread_Create(TElSocketHandle Socket, TElSimpleSSHServerForwardingSessionThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGSESSIONTHREAD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSimpleSSHServer;
class TElSSHUsers;
class TElCustomSessionThread;
class TElSimpleSSHServerListeningThread;
class TElSimpleSSHServerSessionThread;
class TElSimpleSSHServerForwardingListeningThread;
class TElSimpleSSHServerForwardingSessionThread;

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
class TElSimpleSSHServer: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSimpleSSHServer)
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		TElSocketSettings* _Inst_SocketSettings;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_KeyStorage;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELSSHUSERS
		TElSSHUsers* _Inst_Users;
#endif /* SB_USE_CLASS_TELSSHUSERS */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		virtual TElSocketSettings* get_SocketSettings();

		SB_DECLARE_PROPERTY_GET(TElSocketSettings*, get_SocketSettings, TElSimpleSSHServer, SocketSettings);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

		virtual bool get_Active();

		virtual void set_Active(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Active, set_Active, TElSimpleSSHServer, Active);

		virtual bool get_AllowShell();

		virtual void set_AllowShell(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowShell, set_AllowShell, TElSimpleSSHServer, AllowShell);

		virtual bool get_AllowCommand();

		virtual void set_AllowCommand(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowCommand, set_AllowCommand, TElSimpleSSHServer, AllowCommand);

		virtual bool get_AllowClientForwarding();

		virtual void set_AllowClientForwarding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowClientForwarding, set_AllowClientForwarding, TElSimpleSSHServer, AllowClientForwarding);

		virtual bool get_AllowServerForwarding();

		virtual void set_AllowServerForwarding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowServerForwarding, set_AllowServerForwarding, TElSimpleSSHServer, AllowServerForwarding);

		virtual bool get_ForceCompression();

		virtual void set_ForceCompression(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCompression, set_ForceCompression, TElSimpleSSHServer, ForceCompression);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSimpleSSHServer, Port);

		virtual int32_t get_DataPortRangeFrom();

		virtual void set_DataPortRangeFrom(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DataPortRangeFrom, set_DataPortRangeFrom, TElSimpleSSHServer, DataPortRangeFrom);

		virtual int32_t get_DataPortRangeTo();

		virtual void set_DataPortRangeTo(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DataPortRangeTo, set_DataPortRangeTo, TElSimpleSSHServer, DataPortRangeTo);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElSimpleSSHServer, UseIPv6);
#endif

		virtual int32_t get_SessionTimeout();

		virtual void set_SessionTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SessionTimeout, set_SessionTimeout, TElSimpleSSHServer, SessionTimeout);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_KeyStorage();

		virtual void set_KeyStorage(TElSSHCustomKeyStorage &Value);

		virtual void set_KeyStorage(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_KeyStorage, set_KeyStorage, TElSimpleSSHServer, KeyStorage);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

		virtual TSBSSHAuthOrder get_SSHAuthOrder();

		virtual void set_SSHAuthOrder(TSBSSHAuthOrder Value);

		SB_DECLARE_PROPERTY(TSBSSHAuthOrder, get_SSHAuthOrder, set_SSHAuthOrder, TElSimpleSSHServer, SSHAuthOrder);

		virtual void get_SoftwareName(std::string &OutResult);

		virtual void set_SoftwareName(const std::string &Value);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElSimpleSSHServer, CompressionLevel);

		virtual int32_t get_AuthenticationTypes();

		virtual void set_AuthenticationTypes(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthenticationTypes, set_AuthenticationTypes, TElSimpleSSHServer, AuthenticationTypes);

		virtual bool get_CloseIfNoActiveTunnels();

		virtual void set_CloseIfNoActiveTunnels(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CloseIfNoActiveTunnels, set_CloseIfNoActiveTunnels, TElSimpleSSHServer, CloseIfNoActiveTunnels);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSimpleSSHServer, UseUTF8);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSimpleSSHServer, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TElSimpleSSHServer, NoCharacterEncoding);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		virtual bool get_ObfuscateHandshake();

		virtual void set_ObfuscateHandshake(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ObfuscateHandshake, set_ObfuscateHandshake, TElSimpleSSHServer, ObfuscateHandshake);

		virtual void get_ObfuscationPassword(std::string &OutResult);

		virtual void set_ObfuscationPassword(const std::string &Value);

#ifdef SB_USE_CLASS_TELSSHUSERS
		virtual TElSSHUsers* get_Users();

		SB_DECLARE_PROPERTY_GET(TElSSHUsers*, get_Users, TElSimpleSSHServer, Users);
#endif /* SB_USE_CLASS_TELSSHUSERS */

		virtual void get_OnAuthAttempt(TSSHAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthAttempt(TSSHAuthAttemptEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthBanner(TSSHAuthBannerEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthBanner(TSSHAuthBannerEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthPassword(TSSHAuthPasswordEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthPassword(TSSHAuthPasswordEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthPasswordChange(TSSHAuthPasswordChangeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthPasswordChange(TSSHAuthPasswordChangeEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthPublicKey(TSSHAuthPublicKeyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthPublicKey(TSSHAuthPublicKeyEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthHostbased(TSSHAuthHostbasedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthHostbased(TSSHAuthHostbasedEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthKeyboard(TSSHAuthKeyboardEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthKeyboard(TSSHAuthKeyboardEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthKeyboardResponse(TSSHAuthKeyboardResponseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthKeyboardResponse(TSSHAuthKeyboardResponseEvent pMethodValue, void * pDataValue);

		virtual void get_OnFurtherAuthNeeded(TSSHFurtherAuthNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFurtherAuthNeeded(TSSHFurtherAuthNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeOpenSession(TSSHBeforeOpenSessionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeOpenSession(TSSHBeforeOpenSessionEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeOpenShell(TSSHBeforeOpenShellEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeOpenShell(TSSHBeforeOpenShellEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeOpenCommand(TSSHBeforeOpenCommandEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeOpenCommand(TSSHBeforeOpenCommandEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeOpenSubsystem(TSSHBeforeOpenSubsystemEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeOpenSubsystem(TSSHBeforeOpenSubsystemEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeOpenClientForwarding(TSSHBeforeOpenClientForwardingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeOpenClientForwarding(TSSHBeforeOpenClientForwardingEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenSession(TSSHOpenSessionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenSession(TSSHOpenSessionEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenShell(TSSHOpenShellEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenShell(TSSHOpenShellEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenCommand(TSSHOpenCommandEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenCommand(TSSHOpenCommandEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenSubsystem(TSSHOpenSubsystemEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenSubsystem(TSSHOpenSubsystemEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenClientForwarding(TSSHOpenClientForwardingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenClientForwarding(TSSHOpenClientForwardingEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenServerForwarding(TSSHOpenServerForwardingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenServerForwarding(TSSHOpenServerForwardingEvent pMethodValue, void * pDataValue);

		virtual void get_OnServerForwardingFailed(TSSHServerForwardingFailedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnServerForwardingFailed(TSSHServerForwardingFailedEvent pMethodValue, void * pDataValue);

		virtual void get_OnServerForwardingRequest(TSSHServerForwardingRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnServerForwardingRequest(TSSHServerForwardingRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnServerForwardingCancel(TSSHServerForwardingCancelEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnServerForwardingCancel(TSSHServerForwardingCancelEvent pMethodValue, void * pDataValue);

		virtual void get_OnSpecialMessageReceived(TSSHSpecialMessageEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSpecialMessageReceived(TSSHSpecialMessageEvent pMethodValue, void * pDataValue);

		virtual void get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenConnection(TSSHOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenConnection(TSSHOpenConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSSHCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSSHCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyReceive(TSBSSHPublicKeyReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyReceive(TSBSSHPublicKeyReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeySend(TSBSSHPublicKeySendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeySend(TSBSSHPublicKeySendEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyClose(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyError(TSBSSHPublicKeyErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyError(TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyOpen(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyStatus(TSBSSHPublicKeyStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyStatus(TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyAdd(TSBSSHPublicKeyAddEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyAdd(TSBSSHPublicKeyAddEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyRemove(TSBSSHPublicKeyRemoveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyRemove(TSBSSHPublicKeyRemoveEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyList(TSBSSHPublicKeyListEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyList(TSBSSHPublicKeyListEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyListAttributes(TSBSSHPublicKeyListAttributesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyListAttributes(TSBSSHPublicKeyListAttributesEvent pMethodValue, void * pDataValue);

		virtual void get_OnPubKeyAttributeSupported(TSBSSHPublicKeyAttrubuteSupportedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPubKeyAttributeSupported(TSBSSHPublicKeyAttrubuteSupportedEvent pMethodValue, void * pDataValue);

		TElSimpleSSHServer(TElSimpleSSHServerHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleSSHServer(TComponent &AOwner);

		explicit TElSimpleSSHServer(TComponent *AOwner);

		virtual ~TElSimpleSSHServer();

};
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSSHUSERS
class TElSSHUsers: public TElUsers
{
	private:
		SB_DISABLE_COPY(TElSSHUsers)
	public:
#ifdef SB_USE_CLASS_TELSSHKEY
		void AddSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey &Key);

		void AddSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		void AddSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey &Key, const std::string &BasePath);

		void AddSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey *Key, const std::string &BasePath);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		void UpdateSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey &Key);

		void UpdateSSHUser(const std::string &UserName, const std::string &Password, TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHUSER
		TElSSHUserHandle FindSSHUser(const std::string &UserName);
#endif /* SB_USE_CLASS_TELSSHUSER */

#ifdef SB_USE_CLASS_TELSSHKEY
		bool IsValidSSHKey(const std::string &UserName, TElSSHKey &Key);

		bool IsValidSSHKey(const std::string &UserName, TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

		TElSSHUsers(TElSSHUsersHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHUsers(TComponent &AOwner);

		explicit TElSSHUsers(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSHUSERS */

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONTHREAD
class TElCustomSessionThread: public TThread
{
	private:
		SB_DISABLE_COPY(TElCustomSessionThread)
	public:
		virtual void get_OnSessionTerminate(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionTerminate(TNotifyEvent pMethodValue, void * pDataValue);

		TElCustomSessionThread(TElCustomSessionThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		TElCustomSessionThread(bool CreateSuspended, uint32_t StackSize);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

};
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERLISTENINGTHREAD
class TElSimpleSSHServerListeningThread: public TElCustomSessionThread
{
	private:
		SB_DISABLE_COPY(TElSimpleSSHServerListeningThread)
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
		TElSimpleSSHServer* _Inst_Owner;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
		virtual TElSimpleSSHServer* get_Owner();

		virtual void set_Owner(TElSimpleSSHServer &Value);

		virtual void set_Owner(TElSimpleSSHServer *Value);

		SB_DECLARE_PROPERTY(TElSimpleSSHServer*, get_Owner, set_Owner, TElSimpleSSHServerListeningThread, Owner);
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		virtual void set_Socket(TElSocket &Value);

		virtual void set_Socket(TElSocket *Value);

		SB_DECLARE_PROPERTY(TElSocket*, get_Socket, set_Socket, TElSimpleSSHServerListeningThread, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		TElSimpleSSHServerListeningThread(TElSimpleSSHServerListeningThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		TElSimpleSSHServerListeningThread(bool CreateSuspended, uint32_t StackSize);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

		virtual ~TElSimpleSSHServerListeningThread();

};
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERSESSIONTHREAD
class TElSimpleSSHServerSessionThread: public TElCustomSessionThread
{
	private:
		SB_DISABLE_COPY(TElSimpleSSHServerSessionThread)
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
		TElSimpleSSHServer* _Inst_Owner;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHSERVER
		TElSSHServer* _Inst_SSHServer;
#endif /* SB_USE_CLASS_TELSSHSERVER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
		virtual TElSimpleSSHServer* get_Owner();

		virtual void set_Owner(TElSimpleSSHServer &Value);

		virtual void set_Owner(TElSimpleSSHServer *Value);

		SB_DECLARE_PROPERTY(TElSimpleSSHServer*, get_Owner, set_Owner, TElSimpleSSHServerSessionThread, Owner);
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		virtual void set_Socket(TElSocket &Value);

		virtual void set_Socket(TElSocket *Value);

		SB_DECLARE_PROPERTY(TElSocket*, get_Socket, set_Socket, TElSimpleSSHServerSessionThread, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSSHSERVER
		virtual TElSSHServer* get_SSHServer();

		SB_DECLARE_PROPERTY_GET(TElSSHServer*, get_SSHServer, TElSimpleSSHServerSessionThread, SSHServer);
#endif /* SB_USE_CLASS_TELSSHSERVER */

		TElSimpleSSHServerSessionThread(TElSimpleSSHServerSessionThreadHandle handle, TElOwnHandle ownHandle);

		TElSimpleSSHServerSessionThread();

		virtual ~TElSimpleSSHServerSessionThread();

};
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGLISTENINGTHREAD
class TElSimpleSSHServerForwardingListeningThread: public TElCustomSessionThread
{
	private:
		SB_DISABLE_COPY(TElSimpleSSHServerForwardingListeningThread)
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
		TElSimpleSSHServer* _Inst_Owner;
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHSERVER
		TElSSHServer* _Inst_SSHServer;
#endif /* SB_USE_CLASS_TELSSHSERVER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSIMPLESSHSERVER
		virtual TElSimpleSSHServer* get_Owner();

		virtual void set_Owner(TElSimpleSSHServer &Value);

		virtual void set_Owner(TElSimpleSSHServer *Value);

		SB_DECLARE_PROPERTY(TElSimpleSSHServer*, get_Owner, set_Owner, TElSimpleSSHServerForwardingListeningThread, Owner);
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVER */

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_Socket, TElSimpleSSHServerForwardingListeningThread, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSSHSERVER
		virtual TElSSHServer* get_SSHServer();

		virtual void set_SSHServer(TElSSHServer &Value);

		virtual void set_SSHServer(TElSSHServer *Value);

		SB_DECLARE_PROPERTY(TElSSHServer*, get_SSHServer, set_SSHServer, TElSimpleSSHServerForwardingListeningThread, SSHServer);
#endif /* SB_USE_CLASS_TELSSHSERVER */

		TElSimpleSSHServerForwardingListeningThread(TElSimpleSSHServerForwardingListeningThreadHandle handle, TElOwnHandle ownHandle);

		TElSimpleSSHServerForwardingListeningThread();

		virtual ~TElSimpleSSHServerForwardingListeningThread();

};
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGSESSIONTHREAD
class TElSimpleSSHServerForwardingSessionThread: public TElCustomSessionThread
{
	private:
		SB_DISABLE_COPY(TElSimpleSSHServerForwardingSessionThread)
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		TElSSHTunnelConnection* _Inst_Connection;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
#ifdef SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
		TElBuiltinServerTCPForwardingSSHSubsystemHandler* _Inst_Handler;
#endif /* SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */

		void initInstances();

	public:
		virtual void InternalExecute();

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		virtual TElSSHTunnelConnection* get_Connection();

		virtual void set_Connection(TElSSHTunnelConnection &Value);

		virtual void set_Connection(TElSSHTunnelConnection *Value);

		SB_DECLARE_PROPERTY(TElSSHTunnelConnection*, get_Connection, set_Connection, TElSimpleSSHServerForwardingSessionThread, Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER
		virtual TElBuiltinServerTCPForwardingSSHSubsystemHandler* get_Handler();

		SB_DECLARE_PROPERTY_GET(TElBuiltinServerTCPForwardingSSHSubsystemHandler*, get_Handler, TElSimpleSSHServerForwardingSessionThread, Handler);
#endif /* SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_Socket, TElSimpleSSHServerForwardingSessionThread, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		TElSimpleSSHServerForwardingSessionThread(TElSimpleSSHServerForwardingSessionThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSOCKET
		explicit TElSimpleSSHServerForwardingSessionThread(TElSocket &Socket);

		explicit TElSimpleSSHServerForwardingSessionThread(TElSocket *Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		virtual ~TElSimpleSSHServerForwardingSessionThread();

};
#endif /* SB_USE_CLASS_TELSIMPLESSHSERVERFORWARDINGSESSIONTHREAD */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSIMPLESSHSERVER */
