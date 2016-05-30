#ifndef __INC_SBSIMPLEFTPSSERVER
#define __INC_SBSIMPLEFTPSSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#include "sbsharedresource.h"
#include "sbcustomcertstorage.h"
#include "sbftpscommon.h"
#include "sbftpsserver.h"
#include "sbsslconstants.h"
#include "sbsslcommon.h"
#include "sbsslserver.h"
#include "sbsessionpool.h"
#include "sbtimer.h"
#include "sbsocket.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbusers.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSimpleFTPSServerSessionThreadHandle;

typedef TElClassHandle TElSimpleFTPSServerHandle;

typedef TElClassHandle TElSimpleFTPSServerListeningThreadHandle;

typedef TElSimpleFTPSServerListeningThreadHandle ElSimpleFTPSServerListeningThreadHandle;

typedef TElClassHandle TElFTPSUsersHandle;

typedef TElSimpleFTPSServerSessionThreadHandle ElSimpleFTPSServerSessionThreadHandle;

typedef TElSimpleFTPSServerHandle ElSimpleFTPSServerHandle;

typedef void (SB_CALLBACK *TSBSimpleFTPSServerNewConnectionEvent)(void * _ObjectData, TObjectHandle Sender, TElSimpleFTPSServerSessionThreadHandle Session);

typedef void (SB_CALLBACK *TSBSimpleFTPSServerCloseConnectionEvent)(void * _ObjectData, TObjectHandle Sender, TElSimpleFTPSServerSessionThreadHandle Session);

typedef void (SB_CALLBACK *TSBFTPSServerExceptionEvent)(void * _ObjectData, TObjectHandle Sender, TElClassHandle Ex);

typedef void (SB_CALLBACK *TSBSimpleFTPSListenerNewConnectionEvent)(void * _ObjectData, TObjectHandle Sender, TElSocketHandle Socket, int8_t * Reject);

typedef void (SB_CALLBACK *TSBSimpleFTPSServerBeforeNewConnectionEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcRemoteIP, int32_t szRemoteIP, int32_t RemotePort, int8_t * Reject);

typedef void (SB_CALLBACK *TSBSimpleFTPSServerAuthAttemptEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, int8_t * Allow);

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVERSESSIONTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_Socket(TElSimpleFTPSServerSessionThreadHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_FTPSServer(TElSimpleFTPSServerSessionThreadHandle _Handle, TElFTPSServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_ListenAddress(TElSimpleFTPSServerSessionThreadHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_ListenAddress(TElSimpleFTPSServerSessionThreadHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_PassiveModeAddress(TElSimpleFTPSServerSessionThreadHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_PassiveModeAddress(TElSimpleFTPSServerSessionThreadHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_SessionTimeout(TElSimpleFTPSServerSessionThreadHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_SessionTimeout(TElSimpleFTPSServerSessionThreadHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_SocketTimeout(TElSimpleFTPSServerSessionThreadHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_SocketTimeout(TElSimpleFTPSServerSessionThreadHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_IncomingSpeedLimit(TElSimpleFTPSServerSessionThreadHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_IncomingSpeedLimit(TElSimpleFTPSServerSessionThreadHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OutgoingSpeedLimit(TElSimpleFTPSServerSessionThreadHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OutgoingSpeedLimit(TElSimpleFTPSServerSessionThreadHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_DataPortRangeFrom(TElSimpleFTPSServerSessionThreadHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_DataPortRangeFrom(TElSimpleFTPSServerSessionThreadHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_DataPortRangeTo(TElSimpleFTPSServerSessionThreadHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_DataPortRangeTo(TElSimpleFTPSServerSessionThreadHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_AllowAnonymous(TElSimpleFTPSServerSessionThreadHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_AllowAnonymous(TElSimpleFTPSServerSessionThreadHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_RootDirectory(TElSimpleFTPSServerSessionThreadHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_RootDirectory(TElSimpleFTPSServerSessionThreadHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_CurrentDirectory(TElSimpleFTPSServerSessionThreadHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_CurrentDirectory(TElSimpleFTPSServerSessionThreadHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_AnonymousLogin(TElSimpleFTPSServerSessionThreadHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_DataConnectionOpened(TElSimpleFTPSServerSessionThreadHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_FileSystemAdapter(TElSimpleFTPSServerSessionThreadHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_FileSystemAdapter(TElSimpleFTPSServerSessionThreadHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_ReleaseFileSystemAdapter(TElSimpleFTPSServerSessionThreadHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_ReleaseFileSystemAdapter(TElSimpleFTPSServerSessionThreadHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OutgoingLocalBinding(TElSimpleFTPSServerSessionThreadHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OutgoingLocalBinding(TElSimpleFTPSServerSessionThreadHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnAuthAttempt(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBSimpleFTPSServerAuthAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnAuthAttempt(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBSimpleFTPSServerAuthAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnCommandReceived(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerCommandReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnCommandReceived(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnBeforeSendReply(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerBeforeSendReplyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnBeforeSendReply(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnCommandProcessed(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerCommandProcessedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnCommandProcessed(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnTransferProgress(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerTransferProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnTransferProgress(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnTransferCompleted(TElSimpleFTPSServerSessionThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnTransferCompleted(TElSimpleFTPSServerSessionThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnClose(TElSimpleFTPSServerSessionThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnClose(TElSimpleFTPSServerSessionThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnException(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerExceptionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnException(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerExceptionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnCommandUnhandled(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerCommandUnhandledEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnCommandUnhandled(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnSiteCommand(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerSiteCommandEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnSiteCommand(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_get_OnFileAllocate(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerFileAllocateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_set_OnFileAllocate(TElSimpleFTPSServerSessionThreadHandle _Handle, TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerSessionThread_Create(TElSocketHandle Socket, TElSimpleFTPSServerSessionThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVERSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVER
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_Start(TElSimpleFTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_Stop(TElSimpleFTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_AssignTLSParamsFromTemplate(TElSimpleFTPSServerHandle _Handle, TElSSLServerHandle Tpl);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_ConfigureTLS(TElSimpleFTPSServerHandle _Handle, TSBServerSSLPredefinedConfigurationRaw Configuration);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_Active(TElSimpleFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_MessageTable(TElSimpleFTPSServerHandle _Handle, TElFTPSServerMessageTableHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OutgoingLocalBinding(TElSimpleFTPSServerHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OutgoingLocalBinding(TElSimpleFTPSServerHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_SocketSettings(TElSimpleFTPSServerHandle _Handle, TElSocketSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_CipherSuites(TElSimpleFTPSServerHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_CipherSuites(TElSimpleFTPSServerHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_CipherSuitePriorities(TElSimpleFTPSServerHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_CipherSuitePriorities(TElSimpleFTPSServerHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_CompressionAlgorithms(TElSimpleFTPSServerHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_CompressionAlgorithms(TElSimpleFTPSServerHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_Versions(TElSimpleFTPSServerHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_Versions(TElSimpleFTPSServerHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_ClientAuthentication(TElSimpleFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_ClientAuthentication(TElSimpleFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_AuthenticationLevel(TElSimpleFTPSServerHandle _Handle, TSBAuthenticationLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_AuthenticationLevel(TElSimpleFTPSServerHandle _Handle, TSBAuthenticationLevelRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_ForceCertificateChain(TElSimpleFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_ForceCertificateChain(TElSimpleFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_CertStorage(TElSimpleFTPSServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_CertStorage(TElSimpleFTPSServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_SessionPool(TElSimpleFTPSServerHandle _Handle, TElSessionPoolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_SessionPool(TElSimpleFTPSServerHandle _Handle, TElSessionPoolHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_ClientCertStorage(TElSimpleFTPSServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_ClientCertStorage(TElSimpleFTPSServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_Host(TElSimpleFTPSServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_Host(TElSimpleFTPSServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_PassiveModeHost(TElSimpleFTPSServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_PassiveModeHost(TElSimpleFTPSServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_DataHost(TElSimpleFTPSServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_DataHost(TElSimpleFTPSServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_Port(TElSimpleFTPSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_Port(TElSimpleFTPSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_DataPortRangeFrom(TElSimpleFTPSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_DataPortRangeFrom(TElSimpleFTPSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_DataPortRangeTo(TElSimpleFTPSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_DataPortRangeTo(TElSimpleFTPSServerHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_UseIPv6(TElSimpleFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_UseIPv6(TElSimpleFTPSServerHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_SessionTimeout(TElSimpleFTPSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_SessionTimeout(TElSimpleFTPSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_RootDirectory(TElSimpleFTPSServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_RootDirectory(TElSimpleFTPSServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_ReadOnly(TElSimpleFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_ReadOnly(TElSimpleFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_IncomingSpeedLimit(TElSimpleFTPSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_IncomingSpeedLimit(TElSimpleFTPSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OutgoingSpeedLimit(TElSimpleFTPSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OutgoingSpeedLimit(TElSimpleFTPSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_FileSystemAdapter(TElSimpleFTPSServerHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_FileSystemAdapter(TElSimpleFTPSServerHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_AllowAnonymous(TElSimpleFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_AllowAnonymous(TElSimpleFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_ImplicitSSL(TElSimpleFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_ImplicitSSL(TElSimpleFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_UseUTF8(TElSimpleFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_UseUTF8(TElSimpleFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_Users(TElSimpleFTPSServerHandle _Handle, TElFTPSUsersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnBeforeNewConnection(TElSimpleFTPSServerHandle _Handle, TSBSimpleFTPSServerBeforeNewConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnBeforeNewConnection(TElSimpleFTPSServerHandle _Handle, TSBSimpleFTPSServerBeforeNewConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnNewConnection(TElSimpleFTPSServerHandle _Handle, TSBSimpleFTPSServerNewConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnNewConnection(TElSimpleFTPSServerHandle _Handle, TSBSimpleFTPSServerNewConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnCloseConnection(TElSimpleFTPSServerHandle _Handle, TSBSimpleFTPSServerCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnCloseConnection(TElSimpleFTPSServerHandle _Handle, TSBSimpleFTPSServerCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnAuthAttempt(TElSimpleFTPSServerHandle _Handle, TSBSimpleFTPSServerAuthAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnAuthAttempt(TElSimpleFTPSServerHandle _Handle, TSBSimpleFTPSServerAuthAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnCommandReceived(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerCommandReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnCommandReceived(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnBeforeSendReply(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerBeforeSendReplyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnBeforeSendReply(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnCommandProcessed(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerCommandProcessedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnCommandProcessed(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnTransferProgress(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerTransferProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnTransferProgress(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnTransferCompleted(TElSimpleFTPSServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnTransferCompleted(TElSimpleFTPSServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnSessionException(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerExceptionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnSessionException(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerExceptionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnCommandUnhandled(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerCommandUnhandledEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnCommandUnhandled(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnSiteCommand(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerSiteCommandEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnSiteCommand(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_get_OnFileAllocate(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerFileAllocateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_set_OnFileAllocate(TElSimpleFTPSServerHandle _Handle, TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServer_Create(TComponentHandle AOwner, TElSimpleFTPSServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVER */

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVERLISTENINGTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerListeningThread_get_Socket(TElSimpleFTPSServerListeningThreadHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerListeningThread_set_Socket(TElSimpleFTPSServerListeningThreadHandle _Handle, TElSocketHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerListeningThread_get_OnNewConnection(TElSimpleFTPSServerListeningThreadHandle _Handle, TSBSimpleFTPSListenerNewConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerListeningThread_set_OnNewConnection(TElSimpleFTPSServerListeningThreadHandle _Handle, TSBSimpleFTPSListenerNewConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerListeningThread_get_OnClose(TElSimpleFTPSServerListeningThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerListeningThread_set_OnClose(TElSimpleFTPSServerListeningThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSServerListeningThread_Create(TElSimpleFTPSServerHandle Owner, TElSimpleFTPSServerListeningThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVERLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELFTPSUSERS
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUsers_AddFTPSUser(TElFTPSUsersHandle _Handle, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUsers_AddFTPSUser_1(TElFTPSUsersHandle _Handle, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, const char * pcBasePath, int32_t szBasePath);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUsers_AddFTPSUser_2(TElFTPSUsersHandle _Handle, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, const char * pcBasePath, int32_t szBasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUsers_UpdateFTPSUser(TElFTPSUsersHandle _Handle, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUsers_FindFTPSUser(TElFTPSUsersHandle _Handle, const char * pcUserName, int32_t szUserName, TElFTPSUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUsers_get_FTPSUsers(TElFTPSUsersHandle _Handle, int32_t Index, TElFTPSUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUsers_Create(TComponentHandle AOwner, TElUsersHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPSUSERS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSimpleFTPSServerSessionThread;
class TElSimpleFTPSServer;
class TElSimpleFTPSServerListeningThread;
typedef TElSimpleFTPSServerListeningThread ElSimpleFTPSServerListeningThread;
class TElFTPSUsers;
typedef TElSimpleFTPSServerSessionThread ElSimpleFTPSServerSessionThread;
typedef TElSimpleFTPSServer ElSimpleFTPSServer;

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVERSESSIONTHREAD
class TElSimpleFTPSServerSessionThread: public TThread
{
	private:
		SB_DISABLE_COPY(TElSimpleFTPSServerSessionThread)
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELFTPSSERVER
		TElFTPSServer* _Inst_FTPSServer;
#endif /* SB_USE_CLASS_TELFTPSSERVER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_OutgoingLocalBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_Socket, TElSimpleFTPSServerSessionThread, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELFTPSSERVER
		virtual TElFTPSServer* get_FTPSServer();

		SB_DECLARE_PROPERTY_GET(TElFTPSServer*, get_FTPSServer, TElSimpleFTPSServerSessionThread, FTPSServer);
#endif /* SB_USE_CLASS_TELFTPSSERVER */

		virtual void get_ListenAddress(std::string &OutResult);

		virtual void set_ListenAddress(const std::string &Value);

		virtual void get_PassiveModeAddress(std::string &OutResult);

		virtual void set_PassiveModeAddress(const std::string &Value);

		virtual uint32_t get_SessionTimeout();

		virtual void set_SessionTimeout(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_SessionTimeout, set_SessionTimeout, TElSimpleFTPSServerSessionThread, SessionTimeout);

		virtual uint32_t get_SocketTimeout();

		virtual void set_SocketTimeout(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_SocketTimeout, set_SocketTimeout, TElSimpleFTPSServerSessionThread, SocketTimeout);

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElSimpleFTPSServerSessionThread, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElSimpleFTPSServerSessionThread, OutgoingSpeedLimit);

		virtual int32_t get_DataPortRangeFrom();

		virtual void set_DataPortRangeFrom(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DataPortRangeFrom, set_DataPortRangeFrom, TElSimpleFTPSServerSessionThread, DataPortRangeFrom);

		virtual int32_t get_DataPortRangeTo();

		virtual void set_DataPortRangeTo(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DataPortRangeTo, set_DataPortRangeTo, TElSimpleFTPSServerSessionThread, DataPortRangeTo);

		virtual bool get_AllowAnonymous();

		virtual void set_AllowAnonymous(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowAnonymous, set_AllowAnonymous, TElSimpleFTPSServerSessionThread, AllowAnonymous);

		virtual void get_RootDirectory(std::string &OutResult);

		virtual void set_RootDirectory(const std::string &Value);

		virtual void get_CurrentDirectory(std::string &OutResult);

		virtual void set_CurrentDirectory(const std::string &Value);

		virtual bool get_AnonymousLogin();

		SB_DECLARE_PROPERTY_GET(bool, get_AnonymousLogin, TElSimpleFTPSServerSessionThread, AnonymousLogin);

		virtual bool get_DataConnectionOpened();

		SB_DECLARE_PROPERTY_GET(bool, get_DataConnectionOpened, TElSimpleFTPSServerSessionThread, DataConnectionOpened);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElSimpleFTPSServerSessionThread, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual bool get_ReleaseFileSystemAdapter();

		virtual void set_ReleaseFileSystemAdapter(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReleaseFileSystemAdapter, set_ReleaseFileSystemAdapter, TElSimpleFTPSServerSessionThread, ReleaseFileSystemAdapter);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_OutgoingLocalBinding();

		virtual void set_OutgoingLocalBinding(TElClientSocketBinding &Value);

		virtual void set_OutgoingLocalBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_OutgoingLocalBinding, set_OutgoingLocalBinding, TElSimpleFTPSServerSessionThread, OutgoingLocalBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		virtual void get_OnAuthAttempt(TSBSimpleFTPSServerAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthAttempt(TSBSimpleFTPSServerAuthAttemptEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandReceived(TSBFTPSServerCommandReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandReceived(TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferProgress(TSBFTPSServerTransferProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferProgress(TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferCompleted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferCompleted(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnClose(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnException(TSBFTPSServerExceptionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnException(TSBFTPSServerExceptionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue);

		virtual void get_OnSiteCommand(TSBFTPSServerSiteCommandEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSiteCommand(TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileAllocate(TSBFTPSServerFileAllocateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileAllocate(TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue);

		TElSimpleFTPSServerSessionThread(TElSimpleFTPSServerSessionThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSOCKET
		explicit TElSimpleFTPSServerSessionThread(TElSocket &Socket);

		explicit TElSimpleFTPSServerSessionThread(TElSocket *Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		virtual ~TElSimpleFTPSServerSessionThread();

};
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVERSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVER
class TElSimpleFTPSServer: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSimpleFTPSServer)
#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
		TElFTPSServerMessageTable* _Inst_MessageTable;
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_OutgoingLocalBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		TElSocketSettings* _Inst_SocketSettings;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
		TElSessionPool* _Inst_SessionPool;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELFTPSUSERS
		TElFTPSUsers* _Inst_Users;
#endif /* SB_USE_CLASS_TELFTPSUSERS */

		void initInstances();

	public:
		void Start();

		void Stop();

#ifdef SB_USE_CLASS_TELSSLSERVER
		void AssignTLSParamsFromTemplate(TElSSLServer &Tpl);

		void AssignTLSParamsFromTemplate(TElSSLServer *Tpl);
#endif /* SB_USE_CLASS_TELSSLSERVER */

		void ConfigureTLS(TSBServerSSLPredefinedConfiguration Configuration);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSimpleFTPSServer, Active);

#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
		virtual TElFTPSServerMessageTable* get_MessageTable();

		SB_DECLARE_PROPERTY_GET(TElFTPSServerMessageTable*, get_MessageTable, TElSimpleFTPSServer, MessageTable);
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_OutgoingLocalBinding();

		virtual void set_OutgoingLocalBinding(TElClientSocketBinding &Value);

		virtual void set_OutgoingLocalBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_OutgoingLocalBinding, set_OutgoingLocalBinding, TElSimpleFTPSServer, OutgoingLocalBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		virtual TElSocketSettings* get_SocketSettings();

		SB_DECLARE_PROPERTY_GET(TElSocketSettings*, get_SocketSettings, TElSimpleFTPSServer, SocketSettings);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

		virtual bool get_CipherSuites(uint8_t Index);

		virtual void set_CipherSuites(uint8_t Index, bool Value);

		virtual int32_t get_CipherSuitePriorities(uint8_t Index);

		virtual void set_CipherSuitePriorities(uint8_t Index, int32_t Value);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

		virtual TSBVersions get_Versions();

		virtual void set_Versions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_Versions, set_Versions, TElSimpleFTPSServer, Versions);

		virtual bool get_ClientAuthentication();

		virtual void set_ClientAuthentication(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ClientAuthentication, set_ClientAuthentication, TElSimpleFTPSServer, ClientAuthentication);

		virtual TSBAuthenticationLevel get_AuthenticationLevel();

		virtual void set_AuthenticationLevel(TSBAuthenticationLevel Value);

		SB_DECLARE_PROPERTY(TSBAuthenticationLevel, get_AuthenticationLevel, set_AuthenticationLevel, TElSimpleFTPSServer, AuthenticationLevel);

		virtual bool get_ForceCertificateChain();

		virtual void set_ForceCertificateChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCertificateChain, set_ForceCertificateChain, TElSimpleFTPSServer, ForceCertificateChain);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElSimpleFTPSServer, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
		virtual TElSessionPool* get_SessionPool();

		virtual void set_SessionPool(TElSessionPool &Value);

		virtual void set_SessionPool(TElSessionPool *Value);

		SB_DECLARE_PROPERTY(TElSessionPool*, get_SessionPool, set_SessionPool, TElSimpleFTPSServer, SessionPool);
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElSimpleFTPSServer, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_PassiveModeHost(std::string &OutResult);

		virtual void set_PassiveModeHost(const std::string &Value);

		virtual void get_DataHost(std::string &OutResult);

		virtual void set_DataHost(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSimpleFTPSServer, Port);

		virtual int32_t get_DataPortRangeFrom();

		virtual void set_DataPortRangeFrom(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DataPortRangeFrom, set_DataPortRangeFrom, TElSimpleFTPSServer, DataPortRangeFrom);

		virtual int32_t get_DataPortRangeTo();

		virtual void set_DataPortRangeTo(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DataPortRangeTo, set_DataPortRangeTo, TElSimpleFTPSServer, DataPortRangeTo);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElSimpleFTPSServer, UseIPv6);
#endif

		virtual int32_t get_SessionTimeout();

		virtual void set_SessionTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SessionTimeout, set_SessionTimeout, TElSimpleFTPSServer, SessionTimeout);

		virtual void get_RootDirectory(std::string &OutResult);

		virtual void set_RootDirectory(const std::string &Value);

		virtual bool get_ReadOnly();

		virtual void set_ReadOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadOnly, set_ReadOnly, TElSimpleFTPSServer, ReadOnly);

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElSimpleFTPSServer, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElSimpleFTPSServer, OutgoingSpeedLimit);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElSimpleFTPSServer, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual bool get_AllowAnonymous();

		virtual void set_AllowAnonymous(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowAnonymous, set_AllowAnonymous, TElSimpleFTPSServer, AllowAnonymous);

		virtual bool get_ImplicitSSL();

		virtual void set_ImplicitSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ImplicitSSL, set_ImplicitSSL, TElSimpleFTPSServer, ImplicitSSL);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSimpleFTPSServer, UseUTF8);

#ifdef SB_USE_CLASS_TELFTPSUSERS
		virtual TElFTPSUsers* get_Users();

		SB_DECLARE_PROPERTY_GET(TElFTPSUsers*, get_Users, TElSimpleFTPSServer, Users);
#endif /* SB_USE_CLASS_TELFTPSUSERS */

		virtual void get_OnBeforeNewConnection(TSBSimpleFTPSServerBeforeNewConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeNewConnection(TSBSimpleFTPSServerBeforeNewConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnNewConnection(TSBSimpleFTPSServerNewConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnNewConnection(TSBSimpleFTPSServerNewConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBSimpleFTPSServerCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBSimpleFTPSServerCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthAttempt(TSBSimpleFTPSServerAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthAttempt(TSBSimpleFTPSServerAuthAttemptEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandReceived(TSBFTPSServerCommandReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandReceived(TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferProgress(TSBFTPSServerTransferProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferProgress(TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferCompleted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferCompleted(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSessionException(TSBFTPSServerExceptionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionException(TSBFTPSServerExceptionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue);

		virtual void get_OnSiteCommand(TSBFTPSServerSiteCommandEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSiteCommand(TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileAllocate(TSBFTPSServerFileAllocateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileAllocate(TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue);

		TElSimpleFTPSServer(TElSimpleFTPSServerHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleFTPSServer(TComponent &AOwner);

		explicit TElSimpleFTPSServer(TComponent *AOwner);

		virtual ~TElSimpleFTPSServer();

};
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVER */

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVERLISTENINGTHREAD
class TElSimpleFTPSServerListeningThread: public TThread
{
	private:
		SB_DISABLE_COPY(TElSimpleFTPSServerListeningThread)
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		virtual void set_Socket(TElSocket &Value);

		virtual void set_Socket(TElSocket *Value);

		SB_DECLARE_PROPERTY(TElSocket*, get_Socket, set_Socket, TElSimpleFTPSServerListeningThread, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

		virtual void get_OnNewConnection(TSBSimpleFTPSListenerNewConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnNewConnection(TSBSimpleFTPSListenerNewConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnClose(TNotifyEvent pMethodValue, void * pDataValue);

		TElSimpleFTPSServerListeningThread(TElSimpleFTPSServerListeningThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVER
		explicit TElSimpleFTPSServerListeningThread(TElSimpleFTPSServer &Owner);

		explicit TElSimpleFTPSServerListeningThread(TElSimpleFTPSServer *Owner);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVER */

		virtual ~TElSimpleFTPSServerListeningThread();

};
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVERLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELFTPSUSERS
class TElFTPSUsers: public TElUsers
{
	private:
		SB_DISABLE_COPY(TElFTPSUsers)
#ifdef SB_USE_CLASS_TELFTPSUSER
		TElFTPSUser* _Inst_FTPSUsers;
#endif /* SB_USE_CLASS_TELFTPSUSER */

		void initInstances();

	public:
		void AddFTPSUser(const std::string &UserName, const std::string &Password);

		void AddFTPSUser(const std::string &UserName, const std::string &Password, const std::string &BasePath);

		void AddFTPSUser(const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit);

		void UpdateFTPSUser(const std::string &UserName, const std::string &Password);

#ifdef SB_USE_CLASS_TELFTPSUSER
		TElFTPSUserHandle FindFTPSUser(const std::string &UserName);
#endif /* SB_USE_CLASS_TELFTPSUSER */

#ifdef SB_USE_CLASS_TELFTPSUSER
		virtual TElFTPSUser* get_FTPSUsers(int32_t Index);
#endif /* SB_USE_CLASS_TELFTPSUSER */

		TElFTPSUsers(TElFTPSUsersHandle handle, TElOwnHandle ownHandle);

		explicit TElFTPSUsers(TComponent &AOwner);

		explicit TElFTPSUsers(TComponent *AOwner);

		virtual ~TElFTPSUsers();

};
#endif /* SB_USE_CLASS_TELFTPSUSERS */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSIMPLEFTPSSERVER */
