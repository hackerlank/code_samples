#ifndef __INC_SBSSHSERVER
#define __INC_SBSSHSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbcryptoprov.h"
#include "sbcustomcrypto.h"
#include "sbsymmetriccrypto.h"
#include "sbpublickeycrypto.h"
#include "sbsshterm.h"
#include "sbsharedresource.h"
#include "sbsshconstants.h"
#include "sbsshcommon.h"
#include "sbzlib.h"
#include "sbsshkeystorage.h"
#include "sbsshutils.h"
#include "sbecmath.h"
#include "sbusers.h"
#include "sbhashfunction.h"
#include "sbconstants.h"
#include "sbstringlist.h"
#include "sbx509.h"
#include "sbpoly1305.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSSHUserHandle;

typedef TElClassHandle TElSSHServerTunnelConnectionHandle;

typedef TElSSHServerTunnelConnectionHandle ElSSHServerTunnelConnectionHandle;

typedef TElClassHandle TElSSHServerAdditionalSettingsHandle;

typedef TElClassHandle TElSSHServerHandle;

typedef TElSSHServerHandle ElSSHServerHandle;

typedef uint8_t TSSHServerStateRaw;

typedef enum
{
	ssBefore = 0,
	ssIdentificationLineSent = 1,
	ssIdentificationLineReceived = 2
} TSSHServerState;

typedef uint8_t TSSHServerProtServiceRaw;

typedef enum
{
	spsNone = 0,
	spsAuth = 1,
	spsConn = 2
} TSSHServerProtService;

typedef void (SB_CALLBACK *TSSHAuthAttemptEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, int32_t AuthType, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHAuthPublicKeyEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, TElSSHKeyHandle Key, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHAuthHostbasedEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, const char * pcClientUsername, int32_t szClientUsername, const char * pcClientHostname, int32_t szClientHostname, TElSSHKeyHandle Key, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHAuthBannerEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, int32_t AuthType, char * pcBanner, int32_t * szBanner, uint8_t pLanguageTag[], int32_t * szLanguageTag);

typedef void (SB_CALLBACK *TSSHAuthPasswordEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, int8_t * Accept, int8_t * ForceChangePassword);

typedef void (SB_CALLBACK *TSSHAuthPasswordChangeEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, const char * pcOldPassword, int32_t szOldPassword, const char * pcNewPassword, int32_t szNewPassword, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHAuthKeyboardEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, TStringListHandle Submethods, char * pcName, int32_t * szName, char * pcInstruction, int32_t * szInstruction, TStringListHandle Requests, TBitsHandle Echoes);

typedef void (SB_CALLBACK *TSSHAuthKeyboardResponseEvent)(void * _ObjectData, TObjectHandle Sender, TStringListHandle Requests, TStringListHandle Responses, char * pcName, int32_t * szName, char * pcInstruction, int32_t * szInstruction, TStringListHandle NewRequests, TBitsHandle Echoes, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHFurtherAuthNeededEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, int8_t * Needed);

typedef void (SB_CALLBACK *TSSHBeforeOpenSessionEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHBeforeOpenShellEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHBeforeOpenCommandEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection, const char * pcCommand, int32_t szCommand, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHBeforeOpenSubsystemEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcSubsystem, int32_t szSubsystem, TElSSHTunnelConnectionHandle Connection, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHBeforeOpenClientForwardingEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcDestHost, int32_t szDestHost, int32_t DestPort, const char * pcSrcHost, int32_t szSrcHost, int32_t SrcPort, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHBeforeOpenX11ForwardingEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOrigIP, int32_t szOrigIP, int32_t OrigPort, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHOpenSessionEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection);

typedef void (SB_CALLBACK *TSSHOpenShellEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection);

typedef void (SB_CALLBACK *TSSHOpenCommandEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection, const char * pcCommand, int32_t szCommand);

typedef void (SB_CALLBACK *TSSHOpenSubsystemEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection, const char * pcSubsystem, int32_t szSubsystem);

typedef void (SB_CALLBACK *TSSHOpenClientForwardingEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection, const char * pcDestHost, int32_t szDestHost, int32_t DestPort, const char * pcSrcHost, int32_t szSrcHost, int32_t SrcPort);

typedef void (SB_CALLBACK *TSSHOpenServerForwardingEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection);

typedef void (SB_CALLBACK *TSSHOpenX11ForwardingEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection, const char * pcOrigIP, int32_t szOrigIP, int32_t OrigPort);

typedef void (SB_CALLBACK *TSSHServerForwardingFailedEvent)(void * _ObjectData, TObjectHandle Sender, void * Data);

typedef void (SB_CALLBACK *TSSHServerForwardingRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcAddress, int32_t szAddress, int32_t Port, int8_t * Accept, int32_t * RealPort);

typedef void (SB_CALLBACK *TSSHServerForwardingCancelEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcAddress, int32_t szAddress, int32_t Port);

typedef void (SB_CALLBACK *TSSHX11ForwardingRequestEvent)(void * _ObjectData, TObjectHandle Sender, int8_t SingleConnection, const char * pcAuthProtocol, int32_t szAuthProtocol, const char * pcAuthCookie, int32_t szAuthCookie, int32_t ScreenNumber, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHTerminalRequestEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle Connection, TElTerminalInfoHandle Info, int8_t * Accept);

typedef void (SB_CALLBACK *TSSHSpecialMessageEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Code, void * Buffer, int32_t Size);

typedef uint8_t TSBSSHBannerSendStageRaw;

typedef enum
{
	bssBeforeAuth = 0,
	bssAfterSuccess = 1
} TSBSSHBannerSendStage;

#ifdef SB_USE_CLASS_TELSSHUSER
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_GetData(TElSSHUserHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_SetData(TElSSHUserHandle _Handle, const uint8_t pValue[], int32_t szValue, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_SetBasePath(TElSSHUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_SetSSHKey(TElSSHUserHandle _Handle, TElSSHKeyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_AddUser(TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, TElSSHKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_AddUser_1(TElSSHUserHandle _Handle, TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, TElSSHKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_AddUser_2(TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, TElSSHKeyHandle Key, const char * pcBasePath, int32_t szBasePath);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_AddUser_3(TElSSHUserHandle _Handle, TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, TElSSHKeyHandle Key, const char * pcBasePath, int32_t szBasePath);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_IsValidSSHKey(TElSSHUserHandle _Handle, TElSSHKeyHandle Key, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_get_SSHKey(TElSSHUserHandle _Handle, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_set_SSHKey(TElSSHUserHandle _Handle, TElSSHKeyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_get_BasePath(TElSSHUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_set_BasePath(TElSSHUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHUser_Create(const char * pcUserName, int32_t szUserName, TElSSHUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHUSER */

#ifdef SB_USE_CLASS_TELSSHSERVERTUNNELCONNECTION
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerTunnelConnection_SendData(TElSSHServerTunnelConnectionHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerTunnelConnection_SendExtendedData(TElSSHServerTunnelConnectionHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerTunnelConnection_CanSend(TElSSHServerTunnelConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerTunnelConnection_GetWindowBufferLength(TElSSHServerTunnelConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerTunnelConnection_GetExtWindowBufferLength(TElSSHServerTunnelConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerTunnelConnection_Create(TElSSHTunnelConnectionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHSERVERTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerAdditionalSettings_get_OperationStatusCode(TElSSHServerAdditionalSettingsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerAdditionalSettings_set_OperationStatusCode(TElSSHServerAdditionalSettingsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerAdditionalSettings_get_OperationStatusString(TElSSHServerAdditionalSettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerAdditionalSettings_set_OperationStatusString(TElSSHServerAdditionalSettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServerAdditionalSettings_Create(TElSSHServerAdditionalSettingsHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS */

#ifdef SB_USE_CLASS_TELSSHSERVER
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_Close(TElSSHServerHandle _Handle, int8_t Forced);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_Close_1(TElSSHServerHandle _Handle, int32_t ErrorCode, const char * pcReason, int32_t szReason);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_DataAvailable(TElSSHServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_Open(TElSSHServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_OpenServerForwarding(TElSSHServerHandle _Handle, const char * pcAddress, int32_t szAddress, int32_t Port, const char * pcSrcHost, int32_t szSrcHost, int32_t SrcPort, void * Data);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_RenegotiateCiphers(TElSSHServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_ClientCloseReason(TElSSHServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_Username(TElSSHServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_ChangePwdPrompt(TElSSHServerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_ChangePwdPrompt(TElSSHServerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_AuthTypePriorities(TElSSHServerHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_AuthTypePriorities(TElSSHServerHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_DefaultWindowSize(TElSSHServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_DefaultWindowSize(TElSSHServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_MinWindowSize(TElSSHServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_MinWindowSize(TElSSHServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_AdditionalSettings(TElSSHServerHandle _Handle, TElSSHServerAdditionalSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_ClientSoftwareName(TElSSHServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_AllowedSubsystems(TElSSHServerHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_KexKeyStorage(TElSSHServerHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_KexKeyStorage(TElSSHServerHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_ThreadSafe(TElSSHServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_ThreadSafe(TElSSHServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_BannerSendStage(TElSSHServerHandle _Handle, TSBSSHBannerSendStageRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_BannerSendStage(TElSSHServerHandle _Handle, TSBSSHBannerSendStageRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_SSHAuthOrder(TElSSHServerHandle _Handle, TSBSSHAuthOrderRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_SSHAuthOrder(TElSSHServerHandle _Handle, TSBSSHAuthOrderRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthAttempt(TElSSHServerHandle _Handle, TSSHAuthAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthAttempt(TElSSHServerHandle _Handle, TSSHAuthAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthFailed(TElSSHServerHandle _Handle, TSSHAuthenticationFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthFailed(TElSSHServerHandle _Handle, TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthBanner(TElSSHServerHandle _Handle, TSSHAuthBannerEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthBanner(TElSSHServerHandle _Handle, TSSHAuthBannerEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthPassword(TElSSHServerHandle _Handle, TSSHAuthPasswordEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthPassword(TElSSHServerHandle _Handle, TSSHAuthPasswordEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthPasswordChange(TElSSHServerHandle _Handle, TSSHAuthPasswordChangeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthPasswordChange(TElSSHServerHandle _Handle, TSSHAuthPasswordChangeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthPublicKey(TElSSHServerHandle _Handle, TSSHAuthPublicKeyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthPublicKey(TElSSHServerHandle _Handle, TSSHAuthPublicKeyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthHostbased(TElSSHServerHandle _Handle, TSSHAuthHostbasedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthHostbased(TElSSHServerHandle _Handle, TSSHAuthHostbasedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthKeyboard(TElSSHServerHandle _Handle, TSSHAuthKeyboardEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthKeyboard(TElSSHServerHandle _Handle, TSSHAuthKeyboardEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnAuthKeyboardResponse(TElSSHServerHandle _Handle, TSSHAuthKeyboardResponseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnAuthKeyboardResponse(TElSSHServerHandle _Handle, TSSHAuthKeyboardResponseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnFurtherAuthNeeded(TElSSHServerHandle _Handle, TSSHFurtherAuthNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnFurtherAuthNeeded(TElSSHServerHandle _Handle, TSSHFurtherAuthNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnBeforeOpenSession(TElSSHServerHandle _Handle, TSSHBeforeOpenSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnBeforeOpenSession(TElSSHServerHandle _Handle, TSSHBeforeOpenSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnBeforeOpenShell(TElSSHServerHandle _Handle, TSSHBeforeOpenShellEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnBeforeOpenShell(TElSSHServerHandle _Handle, TSSHBeforeOpenShellEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnBeforeOpenCommand(TElSSHServerHandle _Handle, TSSHBeforeOpenCommandEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnBeforeOpenCommand(TElSSHServerHandle _Handle, TSSHBeforeOpenCommandEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnBeforeOpenSubsystem(TElSSHServerHandle _Handle, TSSHBeforeOpenSubsystemEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnBeforeOpenSubsystem(TElSSHServerHandle _Handle, TSSHBeforeOpenSubsystemEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnBeforeOpenClientForwarding(TElSSHServerHandle _Handle, TSSHBeforeOpenClientForwardingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnBeforeOpenClientForwarding(TElSSHServerHandle _Handle, TSSHBeforeOpenClientForwardingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnBeforeOpenX11Forwarding(TElSSHServerHandle _Handle, TSSHBeforeOpenX11ForwardingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnBeforeOpenX11Forwarding(TElSSHServerHandle _Handle, TSSHBeforeOpenX11ForwardingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnOpenSession(TElSSHServerHandle _Handle, TSSHOpenSessionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnOpenSession(TElSSHServerHandle _Handle, TSSHOpenSessionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnOpenShell(TElSSHServerHandle _Handle, TSSHOpenShellEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnOpenShell(TElSSHServerHandle _Handle, TSSHOpenShellEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnOpenCommand(TElSSHServerHandle _Handle, TSSHOpenCommandEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnOpenCommand(TElSSHServerHandle _Handle, TSSHOpenCommandEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnOpenSubsystem(TElSSHServerHandle _Handle, TSSHOpenSubsystemEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnOpenSubsystem(TElSSHServerHandle _Handle, TSSHOpenSubsystemEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnOpenClientForwarding(TElSSHServerHandle _Handle, TSSHOpenClientForwardingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnOpenClientForwarding(TElSSHServerHandle _Handle, TSSHOpenClientForwardingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnOpenServerForwarding(TElSSHServerHandle _Handle, TSSHOpenServerForwardingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnOpenServerForwarding(TElSSHServerHandle _Handle, TSSHOpenServerForwardingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnOpenX11Forwarding(TElSSHServerHandle _Handle, TSSHOpenX11ForwardingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnOpenX11Forwarding(TElSSHServerHandle _Handle, TSSHOpenX11ForwardingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnServerForwardingFailed(TElSSHServerHandle _Handle, TSSHServerForwardingFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnServerForwardingFailed(TElSSHServerHandle _Handle, TSSHServerForwardingFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnServerForwardingRequest(TElSSHServerHandle _Handle, TSSHServerForwardingRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnServerForwardingRequest(TElSSHServerHandle _Handle, TSSHServerForwardingRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnServerForwardingCancel(TElSSHServerHandle _Handle, TSSHServerForwardingCancelEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnServerForwardingCancel(TElSSHServerHandle _Handle, TSSHServerForwardingCancelEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnX11ForwardingRequest(TElSSHServerHandle _Handle, TSSHX11ForwardingRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnX11ForwardingRequest(TElSSHServerHandle _Handle, TSSHX11ForwardingRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnTerminalRequest(TElSSHServerHandle _Handle, TSSHTerminalRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnTerminalRequest(TElSSHServerHandle _Handle, TSSHTerminalRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_get_OnSpecialMessageReceived(TElSSHServerHandle _Handle, TSSHSpecialMessageEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_set_OnSpecialMessageReceived(TElSSHServerHandle _Handle, TSSHSpecialMessageEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHServer_Create(TComponentHandle AOwner, TElSSHServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHUser;
class TElSSHServerTunnelConnection;
typedef TElSSHServerTunnelConnection ElSSHServerTunnelConnection;
class TElSSHServerAdditionalSettings;
class TElSSHServer;
typedef TElSSHServer ElSSHServer;

#ifdef SB_USE_CLASS_TELSSHUSER
class TElSSHUser: public TElCustomUser
{
	private:
		SB_DISABLE_COPY(TElSSHUser)
#ifdef SB_USE_CLASS_TELSSHKEY
		TElSSHKey* _Inst_SSHKey;
#endif /* SB_USE_CLASS_TELSSHKEY */

		void initInstances();

	public:
		virtual void GetData(std::vector<uint8_t> &Buffer, int32_t &Size);

		virtual void SetData(const std::vector<uint8_t> &Value, int32_t Size);

		void SetBasePath(const std::string &Value);

#ifdef SB_USE_CLASS_TELSSHKEY
		void SetSSHKey(TElSSHKey &Value);

		void SetSSHKey(TElSSHKey *Value);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS
		static void AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password, TElSSHKey &Key);

		static void AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password, TElSSHKey *Key);
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS */

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS
		void AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password, TElSSHKey &Key);

		void AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password, TElSSHKey *Key);
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS */

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS
		static void AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password, TElSSHKey &Key, const std::string &BasePath);

		static void AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password, TElSSHKey *Key, const std::string &BasePath);
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS */

#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS
		void AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password, TElSSHKey &Key, const std::string &BasePath);

		void AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password, TElSSHKey *Key, const std::string &BasePath);
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELUSERS */

#ifdef SB_USE_CLASS_TELSSHKEY
		bool IsValidSSHKey(TElSSHKey &Key);

		bool IsValidSSHKey(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual TElSSHKey* get_SSHKey();

		virtual void set_SSHKey(TElSSHKey &Value);

		virtual void set_SSHKey(TElSSHKey *Value);

		SB_DECLARE_PROPERTY(TElSSHKey*, get_SSHKey, set_SSHKey, TElSSHUser, SSHKey);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual void get_BasePath(std::string &OutResult);

		virtual void set_BasePath(const std::string &Value);

		TElSSHUser(TElSSHUserHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHUser(const std::string &UserName);

		virtual ~TElSSHUser();

};
#endif /* SB_USE_CLASS_TELSSHUSER */

#ifdef SB_USE_CLASS_TELSSHSERVERTUNNELCONNECTION
class TElSSHServerTunnelConnection: public TElSSHTunnelConnection
{
	private:
		SB_DISABLE_COPY(TElSSHServerTunnelConnection)
	public:
		virtual void SendData(void * Buffer, int32_t Size);

		virtual void SendExtendedData(void * Buffer, int32_t Size);

		virtual bool CanSend();

		virtual int32_t GetWindowBufferLength();

		virtual int32_t GetExtWindowBufferLength();

		TElSSHServerTunnelConnection(TElSSHServerTunnelConnectionHandle handle, TElOwnHandle ownHandle);

		TElSSHServerTunnelConnection();

};
#endif /* SB_USE_CLASS_TELSSHSERVERTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS
class TElSSHServerAdditionalSettings: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHServerAdditionalSettings)
	public:
		virtual int32_t get_OperationStatusCode();

		virtual void set_OperationStatusCode(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OperationStatusCode, set_OperationStatusCode, TElSSHServerAdditionalSettings, OperationStatusCode);

		virtual void get_OperationStatusString(std::string &OutResult);

		virtual void set_OperationStatusString(const std::string &Value);

		TElSSHServerAdditionalSettings(TElSSHServerAdditionalSettingsHandle handle, TElOwnHandle ownHandle);

		TElSSHServerAdditionalSettings();

};
#endif /* SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS */

#ifdef SB_USE_CLASS_TELSSHSERVER
class TElSSHServer: public TElSSHClass
{
	private:
		SB_DISABLE_COPY(TElSSHServer)
#ifdef SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS
		TElSSHServerAdditionalSettings* _Inst_AdditionalSettings;
#endif /* SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AllowedSubsystems;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_KexKeyStorage;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

		void initInstances();

	public:
		virtual void Close(bool Forced);

		void Close(int32_t ErrorCode, const std::string &Reason);

		void DataAvailable();

		void Open();

		void OpenServerForwarding(const std::string &Address, int32_t Port, const std::string &SrcHost, int32_t SrcPort, void * Data);

		virtual void RenegotiateCiphers();

		virtual void get_ClientCloseReason(std::string &OutResult);

		virtual void get_Username(std::string &OutResult);

		virtual void get_ChangePwdPrompt(std::vector<uint8_t> &OutResult);

		virtual void set_ChangePwdPrompt(const std::vector<uint8_t> &Value);

		virtual int32_t get_AuthTypePriorities(int32_t Index);

		virtual void set_AuthTypePriorities(int32_t Index, int32_t Value);

		virtual int32_t get_DefaultWindowSize();

		virtual void set_DefaultWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DefaultWindowSize, set_DefaultWindowSize, TElSSHServer, DefaultWindowSize);

		virtual int32_t get_MinWindowSize();

		virtual void set_MinWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinWindowSize, set_MinWindowSize, TElSSHServer, MinWindowSize);

#ifdef SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS
		virtual TElSSHServerAdditionalSettings* get_AdditionalSettings();

		SB_DECLARE_PROPERTY_GET(TElSSHServerAdditionalSettings*, get_AdditionalSettings, TElSSHServer, AdditionalSettings);
#endif /* SB_USE_CLASS_TELSSHSERVERADDITIONALSETTINGS */

		virtual void get_ClientSoftwareName(std::string &OutResult);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AllowedSubsystems();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AllowedSubsystems, TElSSHServer, AllowedSubsystems);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_KexKeyStorage();

		virtual void set_KexKeyStorage(TElSSHCustomKeyStorage &Value);

		virtual void set_KexKeyStorage(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_KexKeyStorage, set_KexKeyStorage, TElSSHServer, KexKeyStorage);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

		virtual bool get_ThreadSafe();

		virtual void set_ThreadSafe(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ThreadSafe, set_ThreadSafe, TElSSHServer, ThreadSafe);

		virtual TSBSSHBannerSendStage get_BannerSendStage();

		virtual void set_BannerSendStage(TSBSSHBannerSendStage Value);

		SB_DECLARE_PROPERTY(TSBSSHBannerSendStage, get_BannerSendStage, set_BannerSendStage, TElSSHServer, BannerSendStage);

		virtual TSBSSHAuthOrder get_SSHAuthOrder();

		virtual void set_SSHAuthOrder(TSBSSHAuthOrder Value);

		SB_DECLARE_PROPERTY(TSBSSHAuthOrder, get_SSHAuthOrder, set_SSHAuthOrder, TElSSHServer, SSHAuthOrder);

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

		virtual void get_OnBeforeOpenX11Forwarding(TSSHBeforeOpenX11ForwardingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeOpenX11Forwarding(TSSHBeforeOpenX11ForwardingEvent pMethodValue, void * pDataValue);

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

		virtual void get_OnOpenX11Forwarding(TSSHOpenX11ForwardingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenX11Forwarding(TSSHOpenX11ForwardingEvent pMethodValue, void * pDataValue);

		virtual void get_OnServerForwardingFailed(TSSHServerForwardingFailedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnServerForwardingFailed(TSSHServerForwardingFailedEvent pMethodValue, void * pDataValue);

		virtual void get_OnServerForwardingRequest(TSSHServerForwardingRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnServerForwardingRequest(TSSHServerForwardingRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnServerForwardingCancel(TSSHServerForwardingCancelEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnServerForwardingCancel(TSSHServerForwardingCancelEvent pMethodValue, void * pDataValue);

		virtual void get_OnX11ForwardingRequest(TSSHX11ForwardingRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnX11ForwardingRequest(TSSHX11ForwardingRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnTerminalRequest(TSSHTerminalRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTerminalRequest(TSSHTerminalRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnSpecialMessageReceived(TSSHSpecialMessageEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSpecialMessageReceived(TSSHSpecialMessageEvent pMethodValue, void * pDataValue);

		TElSSHServer(TElSSHServerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHServer(TComponent &AOwner);

		explicit TElSSHServer(TComponent *AOwner);

		virtual ~TElSSHServer();

};
#endif /* SB_USE_CLASS_TELSSHSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHSERVER */

