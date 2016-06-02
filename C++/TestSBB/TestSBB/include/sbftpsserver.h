#ifndef __INC_SBFTPSSERVER
#define __INC_SBFTPSSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbx509.h"
#include "sbcustomfsadapter.h"
#include "sbsharedresource.h"
#include "sbcustomcertstorage.h"
#include "sbftpscommon.h"
#include "sbtimer.h"
#include "sbsslconstants.h"
#include "sbsslcommon.h"
#include "sbsslserver.h"
#include "sbsessionpool.h"
#include "sbsocket.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbusers.h"
#include "sbcustomcrypto.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_FTP_CMD_NOOP 	"NOOP"
#define SB_FTP_CMD_USER 	"USER"
#define SB_FTP_CMD_PASS 	"PASS"
#define SB_FTP_CMD_QUIT 	"QUIT"
#define SB_FTP_CMD_SYST 	"SYST"
#define SB_FTP_CMD_PWD 	"PWD"
#define SB_FTP_CMD_REST 	"REST"
#define SB_FTP_CMD_TYPE 	"TYPE"
#define SB_FTP_CMD_CWD 	"CWD"
#define SB_FTP_CMD_PORT 	"PORT"
#define SB_FTP_CMD_PASV 	"PASV"
#define SB_FTP_CMD_LIST 	"LIST"
#define SB_FTP_CMD_NLST 	"NLST"
#define SB_FTP_CMD_MLST 	"MLST"
#define SB_FTP_CMD_MLSD 	"MLSD"
#define SB_FTP_CMD_RETR 	"RETR"
#define SB_FTP_CMD_ABOR 	"ABOR"
#define SB_FTP_CMD_ALLO 	"ALLO"
#define SB_FTP_CMD_STOR 	"STOR"
#define SB_FTP_CMD_APPE 	"APPE"
#define SB_FTP_CMD_CDUP 	"CDUP"
#define SB_FTP_CMD_SIZE 	"SIZE"
#define SB_FTP_CMD_MDTM 	"MDTM"
#define SB_FTP_CMD_RMD 	"RMD"
#define SB_FTP_CMD_MKD 	"MKD"
#define SB_FTP_CMD_DELE 	"DELE"
#define SB_FTP_CMD_RNFR 	"RNFR"
#define SB_FTP_CMD_RNTO 	"RNTO"
#define SB_FTP_CMD_FEAT 	"FEAT"
#define SB_FTP_CMD_HOST 	"HOST"
#define SB_FTP_CMD_OPTS 	"OPTS"
#define SB_FTP_CMD_STAT 	"STAT"
#define SB_FTP_CMD_HELP 	"HELP"
#define SB_FTP_CMD_AUTH 	"AUTH"
#define SB_FTP_CMD_PBSZ 	"PBSZ"
#define SB_FTP_CMD_PROT 	"PROT"
#define SB_FTP_CMD_CCC 	"CCC"
#define SB_FTP_CMD_REIN 	"REIN"
#define SB_FTP_CMD_MODE 	"MODE"
#define SB_FTP_CMD_EPRT 	"EPRT"
#define SB_FTP_CMD_EPSV 	"EPSV"
#define SB_FTP_CMD_SITE 	"SITE"
#define SB_FTP_CODE_DC_ALREADY_OPEN 	125
#define SB_FTP_CODE_OPENING_DC 	150
#define SB_FTP_CODE_COMMAND_OK 	200
#define SB_FTP_CODE_FEATURES 	211
#define SB_FTP_CODE_DIR_STATUS 	212
#define SB_FTP_CODE_FILE_STATUS 	213
#define SB_FTP_CODE_HELP_MESSAGE 	214
#define SB_FTP_CODE_SYSTEM_TYPE 	215
#define SB_FTP_CODE_SERVICE_READY 	220
#define SB_FTP_CODE_CLOSING_CONNECTION 	221
#define SB_FTP_CODE_ABORT_OK 	225
#define SB_FTP_CODE_CLOSING_DC 	226
#define SB_FTP_CODE_ENTER_PASSIVE_MODE 	227
#define SB_FTP_CODE_ENTER_EXT_PASV_MODE 	229
#define SB_FTP_CODE_LOGGED_IN 	230
#define SB_FTP_CODE_AUTH_COMPLETE 	234
#define SB_FTP_CODE_ACTION_OK 	250
#define SB_FTP_CODE_DIRECTORY_OK 	257
#define SB_FTP_CODE_PASSWORD_NEEDED 	331
#define SB_FTP_CODE_ACCOUNT_NEEDED 	332
#define SB_FTP_CODE_FILE_ACTION_PENDING 	350
#define SB_FTP_CODE_SERVICE_UNAVAILABLE 	421
#define SB_FTP_CODE_CANNOT_OPEN_DC 	425
#define SB_FTP_CODE_TRANSFER_ABORTED 	426
#define SB_FTP_CODE_ACTION_NOT_TAKEN 	450
#define SB_FTP_CODE_PROCESSING_ERROR 	451
#define SB_FTP_CODE_DISK_QUOTA_EXCEEDED 	452
#define SB_FTP_CODE_CMD_NOT_UNDERSTOOD 	500
#define SB_FTP_CODE_PARAMETERS_ERROR 	501
#define SB_FTP_CODE_CMD_NOT_IMPLEMENTED 	502
#define SB_FTP_CODE_BAD_CMD_SEQUENCE 	503
#define SB_FTP_CODE_PARAM_NOT_IMPLEMENTED 	504
#define SB_FTP_CODE_UNKNOWN_PROTOCOL 	522
#define SB_FTP_CODE_NOT_LOGGED_IN 	530
#define SB_FTP_CODE_CMD_NOT_SECURED 	533
#define SB_FTP_CODE_REQUEST_DENIED 	534
#define SB_FTP_CODE_ACTION_UNAVAILABLE 	550
#ifndef WINCE
#define SB_FTP_TRANSFER_BLOCK_SIZE 	262144
#else
#define SB_FTP_TRANSFER_BLOCK_SIZE 	65536
#endif

typedef TElClassHandle TElFTPSServerFileInfoHandle;

typedef TElClassHandle TElFTPSServerMessageTableHandle;

typedef TElClassHandle TElFTPSUserHandle;

typedef TElFTPSServerFileInfoHandle ElFTPSServerFileInfoHandle;

typedef TElClassHandle TElFTPSServerHandle;

typedef TElFTPSServerHandle ElFTPSServerHandle;

typedef TElFTPSServerMessageTableHandle ElFTPSServerMessageTableHandle;

typedef uint8_t TSBFTPSConnectionStatusRaw;

typedef enum
{
	fcsDisconnected = 0,
	fcsPending = 1,
	fcsConnected = 2
} TSBFTPSConnectionStatus;

typedef uint8_t TSBFTPSInternalConnectionStatusRaw;

typedef enum
{
	fcisNotConnected = 0,
	fcisPending = 1,
	fcisEstablishingSSL = 2,
	fcisConnected = 3,
	fcisShuttingDownSSL = 4,
	fcisDisconnected = 5
} TSBFTPSInternalConnectionStatus;

typedef uint8_t TSBFTPSSecurityOptionRaw;

typedef enum
{
	fsoPlainLogin = 0,
	fsoEncryption = 1,
	fsoAuth = 2,
	fsoClearControlChannel = 3,
	fsoClearDataChannel = 4,
	fsoEncryptedDataChannel = 5
} TSBFTPSSecurityOption;

typedef uint32_t TSBFTPSSecurityOptionsRaw;

typedef enum 
{
	f_fsoPlainLogin = 1,
	f_fsoEncryption = 2,
	f_fsoAuth = 4,
	f_fsoClearControlChannel = 8,
	f_fsoClearDataChannel = 16,
	f_fsoEncryptedDataChannel = 32
} TSBFTPSSecurityOptions;

typedef void (SB_CALLBACK *TSBFTPSServerCommandProcessedEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcCommand, int32_t szCommand, int32_t ReplyCode);

typedef void (SB_CALLBACK *TSBFTPSServerDataConnectionCloseEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBFTPSServerEstablishSecureConnectionEvent)(void * _ObjectData, TObjectHandle Sender, TElSSLServerHandle Server);

typedef void (SB_CALLBACK *TSBFTPSServerUsernameReceivedEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcLogin, int32_t szLogin, int8_t * Allow, int8_t * NeedsPassword);

typedef void (SB_CALLBACK *TSBFTPSServerCommandReceivedEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcCommand, int32_t szCommand, const char * pcParameters, int32_t szParameters, int8_t * Ignore);

typedef void (SB_CALLBACK *TSBFTPSServerCommandUnhandledEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcCommand, int32_t szCommand, const char * pcParameters, int32_t szParameters, int8_t * Ignore);

typedef void (SB_CALLBACK *TSBFTPSServerPasswordAuthEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcLogin, int32_t szLogin, const char * pcPassword, int32_t szPassword, int8_t * Allow);

typedef void (SB_CALLBACK *TSBFTPSServerBeforeSendReplyEvent)(void * _ObjectData, TObjectHandle Sender, int32_t * Code, char * pcReply, int32_t * szReply, const char * pcCommand, int32_t szCommand);

typedef void (SB_CALLBACK *TSBFTPSServerDirectoryRequestEvent)(void * _ObjectData, TObjectHandle Sender, char * pcDirectory, int32_t * szDirectory, int32_t * ErrorCode);

typedef void (SB_CALLBACK *TSBFTPSServerRestartTransferRequestEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Offset, int8_t * Success);

typedef void (SB_CALLBACK *TSBFTPSServerDataPortChangeEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcAddress, int32_t szAddress, int32_t Port, int8_t * Success);

typedef void (SB_CALLBACK *TSBFTPSServerPassiveModeRequestEvent)(void * _ObjectData, TObjectHandle Sender, char * pcAddress, int32_t * szAddress, int32_t * Port, int8_t * Success);

typedef void (SB_CALLBACK *TSBFTPSServerDataConnectionNeededEvent)(void * _ObjectData, TObjectHandle Sender, TSBFTPSConnectionStatusRaw * Status);

typedef void (SB_CALLBACK *TSBFTPSServerFileListItemRequestEvent)(void * _ObjectData, TObjectHandle Sender, TElFTPSServerFileInfoHandle Item, int32_t * ErrorCode);

typedef void (SB_CALLBACK *TSBFTPSServerTransferProgressEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Progress, int64_t Total, int8_t * Abort);

typedef void (SB_CALLBACK *TSBFTPSServerFileRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, int32_t * ErrorCode);

typedef void (SB_CALLBACK *TSBFTPSServerFileAllocateEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Size, int8_t * Success);

typedef void (SB_CALLBACK *TSBFTPSServerFileInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, TElFTPSServerFileInfoHandle Info, int32_t * ErrorCode);

typedef void (SB_CALLBACK *TSBFTPSServerFileRenameRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOldName, int32_t szOldName, const char * pcNewName, int32_t szNewName, int32_t * ErrorCode);

typedef void (SB_CALLBACK *TSBFTPSServerInformationRequestEvent)(void * _ObjectData, TObjectHandle Sender, char * pcInformation, int32_t * szInformation);

typedef void (SB_CALLBACK *TSBFTPSServerHostRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcHost, int32_t szHost, int32_t * ErrorCode);

typedef void (SB_CALLBACK *TSBFTPSServerExtPassiveModeRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcProtocol, int32_t szProtocol, int32_t * Port, int8_t * Success);

typedef void (SB_CALLBACK *TSBFTPSServerSiteCommandEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcParameters, int32_t szParameters, int32_t * ErrorCode, char * pcResponse, int32_t * szResponse);

typedef uint8_t TSBFTPSServerFileAttributeRaw;

typedef enum
{
	fsaSize = 0,
	fsaName = 1,
	fsaFileType = 2,
	fsaModificationDate = 3,
	fsaCreationDate = 4,
	fsaUnixPermissions = 5,
	fsaOwner = 6,
	fsaGroup = 7
} TSBFTPSServerFileAttribute;

typedef uint32_t TSBFTPSServerFileAttributesRaw;

typedef enum 
{
	f_fsaSize = 1,
	f_fsaName = 2,
	f_fsaFileType = 4,
	f_fsaModificationDate = 8,
	f_fsaCreationDate = 16,
	f_fsaUnixPermissions = 32,
	f_fsaOwner = 64,
	f_fsaGroup = 128
} TSBFTPSServerFileAttributes;

typedef uint8_t TSBFTPSServerFileTypeRaw;

typedef enum
{
	fstFile = 0,
	fstDirectory = 1,
	fstCurrentDirectory = 2
} TSBFTPSServerFileType;

#ifdef SB_USE_CLASS_TELFTPSSERVERFILEINFO
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_AttributeIncluded(TElFTPSServerFileInfoHandle _Handle, TSBFTPSServerFileAttributeRaw Attribute, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_IncludeAttribute(TElFTPSServerFileInfoHandle _Handle, TSBFTPSServerFileAttributeRaw Attribute);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_ExcludeAttribute(TElFTPSServerFileInfoHandle _Handle, TSBFTPSServerFileAttributeRaw Attribute);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_Size(TElFTPSServerFileInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_Size(TElFTPSServerFileInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_Name(TElFTPSServerFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_Name(TElFTPSServerFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_UnixPermissions(TElFTPSServerFileInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_UnixPermissions(TElFTPSServerFileInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_FileType(TElFTPSServerFileInfoHandle _Handle, TSBFTPSServerFileTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_FileType(TElFTPSServerFileInfoHandle _Handle, TSBFTPSServerFileTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_CreationDate(TElFTPSServerFileInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_CreationDate(TElFTPSServerFileInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_ModificationDate(TElFTPSServerFileInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_ModificationDate(TElFTPSServerFileInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_Owner(TElFTPSServerFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_Owner(TElFTPSServerFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_Group(TElFTPSServerFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_Group(TElFTPSServerFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_get_IncludedAttributes(TElFTPSServerFileInfoHandle _Handle, TSBFTPSServerFileAttributesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_set_IncludedAttributes(TElFTPSServerFileInfoHandle _Handle, TSBFTPSServerFileAttributesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerFileInfo_Create(TElFTPSServerFileInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPSSERVERFILEINFO */

#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerMessageTable_SetDefaults(TElFTPSServerMessageTableHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerMessageTable_Clear(TElFTPSServerMessageTableHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerMessageTable_GetMessage(TElFTPSServerMessageTableHandle _Handle, int32_t Code, const char * pcCommand, int32_t szCommand, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerMessageTable_SetMessage(TElFTPSServerMessageTableHandle _Handle, int32_t Code, const char * pcMsg, int32_t szMsg);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerMessageTable_SetMessage_1(TElFTPSServerMessageTableHandle _Handle, int32_t Code, const char * pcMsg, int32_t szMsg, const char * pcCommand, int32_t szCommand);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerMessageTable_get_Greeting(TElFTPSServerMessageTableHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerMessageTable_set_Greeting(TElFTPSServerMessageTableHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServerMessageTable_Create(TElFTPSServerMessageTableHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */

#ifdef SB_USE_CLASS_TELFTPSUSER
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_GetData(TElFTPSUserHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_SetData(TElFTPSUserHandle _Handle, const uint8_t pValue[], int32_t szValue, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_SetBasePath(TElFTPSUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_SetOutgoingSpeedLimit(TElFTPSUserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_SetIncomingSpeedLimit(TElFTPSUserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_AddUser(TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_AddUser_1(TElFTPSUserHandle _Handle, TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_AddUser_2(TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, const char * pcBasePath, int32_t szBasePath);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_AddUser_3(TElFTPSUserHandle _Handle, TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, const char * pcBasePath, int32_t szBasePath);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_AddUser_4(TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, const char * pcBasePath, int32_t szBasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_AddUser_5(TElFTPSUserHandle _Handle, TElUsersHandle Users, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, const char * pcBasePath, int32_t szBasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_get_BasePath(TElFTPSUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_set_BasePath(TElFTPSUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_get_OutgoingSpeedLimit(TElFTPSUserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_set_OutgoingSpeedLimit(TElFTPSUserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_get_IncomingSpeedLimit(TElFTPSUserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_set_IncomingSpeedLimit(TElFTPSUserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSUser_Create(const char * pcUserName, int32_t szUserName, TElCustomUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPSUSER */

#ifdef SB_USE_CLASS_TELFTPSSERVER
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_Open(TElFTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_Close(TElFTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_CloseDataConnection(TElFTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_TransferDataFinished(TElFTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_DataAvailable(TElFTPSServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_SendCustomReply(TElFTPSServerHandle _Handle, int32_t Code, const char * pcReply, int32_t szReply);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_AssignTLSParamsFromTemplate(TElFTPSServerHandle _Handle, TElSSLServerHandle Tpl);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_ConfigureTLS(TElFTPSServerHandle _Handle, TSBServerSSLPredefinedConfigurationRaw Configuration);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_Active(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ASCIIMode(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_Authenticated(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_Authenticated(TElFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_PassiveMode(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ExtPassiveOnly(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_MessageTable(TElFTPSServerHandle _Handle, TElFTPSServerMessageTableHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_MessageTable(TElFTPSServerHandle _Handle, TElFTPSServerMessageTableHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_LastCommand(TElFTPSServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_LastTransferCommand(TElFTPSServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_TransferInProgress(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ControlChannelEncrypted(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_DataChannelEncrypted(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_CipherSuites(TElFTPSServerHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_CipherSuites(TElFTPSServerHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_CipherSuitePriorities(TElFTPSServerHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_CipherSuitePriorities(TElFTPSServerHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_CompressionAlgorithms(TElFTPSServerHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_CompressionAlgorithms(TElFTPSServerHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_Versions(TElFTPSServerHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_Versions(TElFTPSServerHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ClientAuthentication(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_ClientAuthentication(TElFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_AuthenticationLevel(TElFTPSServerHandle _Handle, TSBAuthenticationLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_AuthenticationLevel(TElFTPSServerHandle _Handle, TSBAuthenticationLevelRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ForceCertificateChain(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_ForceCertificateChain(TElFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ControlChannelCipherSuite(TElFTPSServerHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ControlChannelSSLVersion(TElFTPSServerHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ControlChannelSSLCompressionAlgorithm(TElFTPSServerHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ControlChannelSSLConnectionInfo(TElFTPSServerHandle _Handle, TElSSLConnectionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_DataChannelCipherSuite(TElFTPSServerHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_DataChannelSSLVersion(TElFTPSServerHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_DataChannelSSLCompressionAlgorithm(TElFTPSServerHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_DataChannelSSLConnectionInfo(TElFTPSServerHandle _Handle, TElSSLConnectionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_CertStorage(TElFTPSServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_CertStorage(TElFTPSServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_SessionPool(TElFTPSServerHandle _Handle, TElSessionPoolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_SessionPool(TElFTPSServerHandle _Handle, TElSessionPoolHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ClientCertStorage(TElFTPSServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_ClientCertStorage(TElFTPSServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_SystemType(TElFTPSServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_SystemType(TElFTPSServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_ImplicitSSL(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_ImplicitSSL(TElFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_SecurityOptions(TElFTPSServerHandle _Handle, TSBFTPSSecurityOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_SecurityOptions(TElFTPSServerHandle _Handle, TSBFTPSSecurityOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_UseUTF8(TElFTPSServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_UseUTF8(TElFTPSServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_TransferBlockSize(TElFTPSServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_TransferBlockSize(TElFTPSServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnOpen(TElFTPSServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnOpen(TElFTPSServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnCmdReceive(TElFTPSServerHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnCmdReceive(TElFTPSServerHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnCmdSend(TElFTPSServerHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnCmdSend(TElFTPSServerHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnDataReceive(TElFTPSServerHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnDataReceive(TElFTPSServerHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnDataSend(TElFTPSServerHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnDataSend(TElFTPSServerHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnTransferDataNeeded(TElFTPSServerHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnTransferDataNeeded(TElFTPSServerHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnTransferDataAvailable(TElFTPSServerHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnTransferDataAvailable(TElFTPSServerHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnTransferProgress(TElFTPSServerHandle _Handle, TSBFTPSServerTransferProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnTransferProgress(TElFTPSServerHandle _Handle, TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnTransferCompleted(TElFTPSServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnTransferCompleted(TElFTPSServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnAbortTransfer(TElFTPSServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnAbortTransfer(TElFTPSServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnClose(TElFTPSServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnClose(TElFTPSServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnCommandReceived(TElFTPSServerHandle _Handle, TSBFTPSServerCommandReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnCommandReceived(TElFTPSServerHandle _Handle, TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnCommandUnhandled(TElFTPSServerHandle _Handle, TSBFTPSServerCommandUnhandledEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnCommandUnhandled(TElFTPSServerHandle _Handle, TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnCommandProcessed(TElFTPSServerHandle _Handle, TSBFTPSServerCommandProcessedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnCommandProcessed(TElFTPSServerHandle _Handle, TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnBeforeSendReply(TElFTPSServerHandle _Handle, TSBFTPSServerBeforeSendReplyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnBeforeSendReply(TElFTPSServerHandle _Handle, TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnUsernameReceived(TElFTPSServerHandle _Handle, TSBFTPSServerUsernameReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnUsernameReceived(TElFTPSServerHandle _Handle, TSBFTPSServerUsernameReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnPasswordAuth(TElFTPSServerHandle _Handle, TSBFTPSServerPasswordAuthEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnPasswordAuth(TElFTPSServerHandle _Handle, TSBFTPSServerPasswordAuthEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnWorkingDirectoryRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnWorkingDirectoryRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnMakeDirectoryRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnMakeDirectoryRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnRemoveDirectoryRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnRemoveDirectoryRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnRestartTransferRequest(TElFTPSServerHandle _Handle, TSBFTPSServerRestartTransferRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnRestartTransferRequest(TElFTPSServerHandle _Handle, TSBFTPSServerRestartTransferRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnChangeDirectoryRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnChangeDirectoryRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnDataPortChange(TElFTPSServerHandle _Handle, TSBFTPSServerDataPortChangeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnDataPortChange(TElFTPSServerHandle _Handle, TSBFTPSServerDataPortChangeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnPassiveModeRequest(TElFTPSServerHandle _Handle, TSBFTPSServerPassiveModeRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnPassiveModeRequest(TElFTPSServerHandle _Handle, TSBFTPSServerPassiveModeRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnDataConnectionNeeded(TElFTPSServerHandle _Handle, TSBFTPSServerDataConnectionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnDataConnectionNeeded(TElFTPSServerHandle _Handle, TSBFTPSServerDataConnectionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnDataConnectionClose(TElFTPSServerHandle _Handle, TSBFTPSServerDataConnectionCloseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnDataConnectionClose(TElFTPSServerHandle _Handle, TSBFTPSServerDataConnectionCloseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileListRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileListRequest(TElFTPSServerHandle _Handle, TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileListItemRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileListItemRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileListItemRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileListItemRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileListCompleted(TElFTPSServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileListCompleted(TElFTPSServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileRetrieveRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileRetrieveRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileAllocate(TElFTPSServerHandle _Handle, TSBFTPSServerFileAllocateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileAllocate(TElFTPSServerHandle _Handle, TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileStoreRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileStoreRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileAppendRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileAppendRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileInfoNeeded(TElFTPSServerHandle _Handle, TSBFTPSServerFileInfoNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileInfoNeeded(TElFTPSServerHandle _Handle, TSBFTPSServerFileInfoNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileRemoveRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileRemoveRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnFileRenameRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRenameRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnFileRenameRequest(TElFTPSServerHandle _Handle, TSBFTPSServerFileRenameRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnStatusRequest(TElFTPSServerHandle _Handle, TSBFTPSServerInformationRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnStatusRequest(TElFTPSServerHandle _Handle, TSBFTPSServerInformationRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnVirtualHostRequest(TElFTPSServerHandle _Handle, TSBFTPSServerHostRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnVirtualHostRequest(TElFTPSServerHandle _Handle, TSBFTPSServerHostRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnEstablishSecureConnection(TElFTPSServerHandle _Handle, TSBFTPSServerEstablishSecureConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnEstablishSecureConnection(TElFTPSServerHandle _Handle, TSBFTPSServerEstablishSecureConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnExtPassiveModeRequest(TElFTPSServerHandle _Handle, TSBFTPSServerExtPassiveModeRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnExtPassiveModeRequest(TElFTPSServerHandle _Handle, TSBFTPSServerExtPassiveModeRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_get_OnSiteCommand(TElFTPSServerHandle _Handle, TSBFTPSServerSiteCommandEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_set_OnSiteCommand(TElFTPSServerHandle _Handle, TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSServer_Create(TComponentHandle AOwner, TElFTPSServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPSSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElFTPSServerFileInfo;
class TElFTPSServerMessageTable;
class TElFTPSUser;
typedef TElFTPSServerFileInfo ElFTPSServerFileInfo;
class TElFTPSServer;
typedef TElFTPSServer ElFTPSServer;
typedef TElFTPSServerMessageTable ElFTPSServerMessageTable;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBFTPSSecurityOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBFTPSServerFileAttributes)

#ifdef SB_USE_CLASS_TELFTPSSERVERFILEINFO
class TElFTPSServerFileInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElFTPSServerFileInfo)
	public:
		bool AttributeIncluded(TSBFTPSServerFileAttribute Attribute);

		void IncludeAttribute(TSBFTPSServerFileAttribute Attribute);

		void ExcludeAttribute(TSBFTPSServerFileAttribute Attribute);

		virtual int64_t get_Size();

		virtual void set_Size(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Size, set_Size, TElFTPSServerFileInfo, Size);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual int32_t get_UnixPermissions();

		virtual void set_UnixPermissions(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_UnixPermissions, set_UnixPermissions, TElFTPSServerFileInfo, UnixPermissions);

		virtual TSBFTPSServerFileType get_FileType();

		virtual void set_FileType(TSBFTPSServerFileType Value);

		SB_DECLARE_PROPERTY(TSBFTPSServerFileType, get_FileType, set_FileType, TElFTPSServerFileInfo, FileType);

		virtual int64_t get_CreationDate();

		virtual void set_CreationDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CreationDate, set_CreationDate, TElFTPSServerFileInfo, CreationDate);

		virtual int64_t get_ModificationDate();

		virtual void set_ModificationDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ModificationDate, set_ModificationDate, TElFTPSServerFileInfo, ModificationDate);

		virtual void get_Owner(std::string &OutResult);

		virtual void set_Owner(const std::string &Value);

		virtual void get_Group(std::string &OutResult);

		virtual void set_Group(const std::string &Value);

		virtual TSBFTPSServerFileAttributes get_IncludedAttributes();

		virtual void set_IncludedAttributes(TSBFTPSServerFileAttributes Value);

		SB_DECLARE_PROPERTY(TSBFTPSServerFileAttributes, get_IncludedAttributes, set_IncludedAttributes, TElFTPSServerFileInfo, IncludedAttributes);

		TElFTPSServerFileInfo(TElFTPSServerFileInfoHandle handle, TElOwnHandle ownHandle);

		TElFTPSServerFileInfo();

};
#endif /* SB_USE_CLASS_TELFTPSSERVERFILEINFO */

#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
class TElFTPSServerMessageTable: public TObject
{
	private:
		SB_DISABLE_COPY(TElFTPSServerMessageTable)
	public:
		void SetDefaults();

		void Clear();

		void GetMessage(int32_t Code, const std::string &Command, std::string &OutResult);

		void SetMessage(int32_t Code, const std::string &Msg);

		void SetMessage(int32_t Code, const std::string &Msg, const std::string &Command);

		virtual void get_Greeting(std::string &OutResult);

		virtual void set_Greeting(const std::string &Value);

		TElFTPSServerMessageTable(TElFTPSServerMessageTableHandle handle, TElOwnHandle ownHandle);

		TElFTPSServerMessageTable();

};
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */

#ifdef SB_USE_CLASS_TELFTPSUSER
class TElFTPSUser: public TElCustomUser
{
	private:
		SB_DISABLE_COPY(TElFTPSUser)
	public:
		virtual void GetData(std::vector<uint8_t> &Buffer, int32_t &Size);

		virtual void SetData(const std::vector<uint8_t> &Value, int32_t Size);

		void SetBasePath(const std::string &Value);

		void SetOutgoingSpeedLimit(int32_t Value);

		void SetIncomingSpeedLimit(int32_t Value);

#ifdef SB_USE_CLASS_TELUSERS
		static void AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password);

		static void AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password);
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
		void AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password);

		void AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password);
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
		static void AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password, const std::string &BasePath);

		static void AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password, const std::string &BasePath);
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
		void AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password, const std::string &BasePath);

		void AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password, const std::string &BasePath);
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
		static void AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit);

		static void AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit);
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
		void AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit);

		void AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit);
#endif /* SB_USE_CLASS_TELUSERS */

		static TClassHandle ClassType();

		virtual void get_BasePath(std::string &OutResult);

		virtual void set_BasePath(const std::string &Value);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElFTPSUser, OutgoingSpeedLimit);

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElFTPSUser, IncomingSpeedLimit);

		TElFTPSUser(TElFTPSUserHandle handle, TElOwnHandle ownHandle);

		explicit TElFTPSUser(const std::string &UserName);

};
#endif /* SB_USE_CLASS_TELFTPSUSER */

#ifdef SB_USE_CLASS_TELFTPSSERVER
class TElFTPSServer: public TComponent
{
	private:
		SB_DISABLE_COPY(TElFTPSServer)
#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
		TElFTPSServerMessageTable* _Inst_MessageTable;
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		TElSSLConnectionInfo* _Inst_ControlChannelSSLConnectionInfo;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		TElSSLConnectionInfo* _Inst_DataChannelSSLConnectionInfo;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
		TElSessionPool* _Inst_SessionPool;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		void Open();

		void Close();

		void CloseDataConnection();

		void TransferDataFinished();

		void DataAvailable();

		void SendCustomReply(int32_t Code, const std::string &Reply);

#ifdef SB_USE_CLASS_TELSSLSERVER
		void AssignTLSParamsFromTemplate(TElSSLServer &Tpl);

		void AssignTLSParamsFromTemplate(TElSSLServer *Tpl);
#endif /* SB_USE_CLASS_TELSSLSERVER */

		void ConfigureTLS(TSBServerSSLPredefinedConfiguration Configuration);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElFTPSServer, Active);

		virtual bool get_ASCIIMode();

		SB_DECLARE_PROPERTY_GET(bool, get_ASCIIMode, TElFTPSServer, ASCIIMode);

		virtual bool get_Authenticated();

		virtual void set_Authenticated(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Authenticated, set_Authenticated, TElFTPSServer, Authenticated);

		virtual bool get_PassiveMode();

		SB_DECLARE_PROPERTY_GET(bool, get_PassiveMode, TElFTPSServer, PassiveMode);

		virtual bool get_ExtPassiveOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtPassiveOnly, TElFTPSServer, ExtPassiveOnly);

#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
		virtual TElFTPSServerMessageTable* get_MessageTable();

		virtual void set_MessageTable(TElFTPSServerMessageTable &Value);

		virtual void set_MessageTable(TElFTPSServerMessageTable *Value);

		SB_DECLARE_PROPERTY(TElFTPSServerMessageTable*, get_MessageTable, set_MessageTable, TElFTPSServer, MessageTable);
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */

		virtual void get_LastCommand(std::string &OutResult);

		virtual void get_LastTransferCommand(std::string &OutResult);

		virtual bool get_TransferInProgress();

		SB_DECLARE_PROPERTY_GET(bool, get_TransferInProgress, TElFTPSServer, TransferInProgress);

		virtual bool get_ControlChannelEncrypted();

		SB_DECLARE_PROPERTY_GET(bool, get_ControlChannelEncrypted, TElFTPSServer, ControlChannelEncrypted);

		virtual bool get_DataChannelEncrypted();

		SB_DECLARE_PROPERTY_GET(bool, get_DataChannelEncrypted, TElFTPSServer, DataChannelEncrypted);

		virtual bool get_CipherSuites(uint8_t Index);

		virtual void set_CipherSuites(uint8_t Index, bool Value);

		virtual int32_t get_CipherSuitePriorities(uint8_t Index);

		virtual void set_CipherSuitePriorities(uint8_t Index, int32_t Value);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

		virtual TSBVersions get_Versions();

		virtual void set_Versions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_Versions, set_Versions, TElFTPSServer, Versions);

		virtual bool get_ClientAuthentication();

		virtual void set_ClientAuthentication(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ClientAuthentication, set_ClientAuthentication, TElFTPSServer, ClientAuthentication);

		virtual TSBAuthenticationLevel get_AuthenticationLevel();

		virtual void set_AuthenticationLevel(TSBAuthenticationLevel Value);

		SB_DECLARE_PROPERTY(TSBAuthenticationLevel, get_AuthenticationLevel, set_AuthenticationLevel, TElFTPSServer, AuthenticationLevel);

		virtual bool get_ForceCertificateChain();

		virtual void set_ForceCertificateChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCertificateChain, set_ForceCertificateChain, TElFTPSServer, ForceCertificateChain);

		virtual uint8_t get_ControlChannelCipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_ControlChannelCipherSuite, TElFTPSServer, ControlChannelCipherSuite);

		virtual TSBVersion get_ControlChannelSSLVersion();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_ControlChannelSSLVersion, TElFTPSServer, ControlChannelSSLVersion);

		virtual uint8_t get_ControlChannelSSLCompressionAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_ControlChannelSSLCompressionAlgorithm, TElFTPSServer, ControlChannelSSLCompressionAlgorithm);

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		virtual TElSSLConnectionInfo* get_ControlChannelSSLConnectionInfo();

		SB_DECLARE_PROPERTY_GET(TElSSLConnectionInfo*, get_ControlChannelSSLConnectionInfo, TElFTPSServer, ControlChannelSSLConnectionInfo);
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

		virtual uint8_t get_DataChannelCipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_DataChannelCipherSuite, TElFTPSServer, DataChannelCipherSuite);

		virtual TSBVersion get_DataChannelSSLVersion();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_DataChannelSSLVersion, TElFTPSServer, DataChannelSSLVersion);

		virtual uint8_t get_DataChannelSSLCompressionAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_DataChannelSSLCompressionAlgorithm, TElFTPSServer, DataChannelSSLCompressionAlgorithm);

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		virtual TElSSLConnectionInfo* get_DataChannelSSLConnectionInfo();

		SB_DECLARE_PROPERTY_GET(TElSSLConnectionInfo*, get_DataChannelSSLConnectionInfo, TElFTPSServer, DataChannelSSLConnectionInfo);
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElFTPSServer, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
		virtual TElSessionPool* get_SessionPool();

		virtual void set_SessionPool(TElSessionPool &Value);

		virtual void set_SessionPool(TElSessionPool *Value);

		SB_DECLARE_PROPERTY(TElSessionPool*, get_SessionPool, set_SessionPool, TElFTPSServer, SessionPool);
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElFTPSServer, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_SystemType(std::string &OutResult);

		virtual void set_SystemType(const std::string &Value);

		virtual bool get_ImplicitSSL();

		virtual void set_ImplicitSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ImplicitSSL, set_ImplicitSSL, TElFTPSServer, ImplicitSSL);

		virtual TSBFTPSSecurityOptions get_SecurityOptions();

		virtual void set_SecurityOptions(TSBFTPSSecurityOptions Value);

		SB_DECLARE_PROPERTY(TSBFTPSSecurityOptions, get_SecurityOptions, set_SecurityOptions, TElFTPSServer, SecurityOptions);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElFTPSServer, UseUTF8);

		virtual int32_t get_TransferBlockSize();

		virtual void set_TransferBlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TransferBlockSize, set_TransferBlockSize, TElFTPSServer, TransferBlockSize);

		virtual void get_OnOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpen(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCmdReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCmdReceive(TSBReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnCmdSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCmdSend(TSBSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnDataReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDataReceive(TSBReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnDataSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDataSend(TSBSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferDataNeeded(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferDataNeeded(TSBReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferDataAvailable(TSBSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferDataAvailable(TSBSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferProgress(TSBFTPSServerTransferProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferProgress(TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferCompleted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferCompleted(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnAbortTransfer(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAbortTransfer(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnClose(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandReceived(TSBFTPSServerCommandReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandReceived(TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue);

		virtual void get_OnUsernameReceived(TSBFTPSServerUsernameReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUsernameReceived(TSBFTPSServerUsernameReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnPasswordAuth(TSBFTPSServerPasswordAuthEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordAuth(TSBFTPSServerPasswordAuthEvent pMethodValue, void * pDataValue);

		virtual void get_OnWorkingDirectoryRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWorkingDirectoryRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnMakeDirectoryRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMakeDirectoryRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnRemoveDirectoryRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRemoveDirectoryRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnRestartTransferRequest(TSBFTPSServerRestartTransferRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRestartTransferRequest(TSBFTPSServerRestartTransferRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnChangeDirectoryRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChangeDirectoryRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnDataPortChange(TSBFTPSServerDataPortChangeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDataPortChange(TSBFTPSServerDataPortChangeEvent pMethodValue, void * pDataValue);

		virtual void get_OnPassiveModeRequest(TSBFTPSServerPassiveModeRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPassiveModeRequest(TSBFTPSServerPassiveModeRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnDataConnectionNeeded(TSBFTPSServerDataConnectionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDataConnectionNeeded(TSBFTPSServerDataConnectionNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDataConnectionClose(TSBFTPSServerDataConnectionCloseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDataConnectionClose(TSBFTPSServerDataConnectionCloseEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileListRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileListRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileListItemRequest(TSBFTPSServerFileListItemRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileListItemRequest(TSBFTPSServerFileListItemRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileListCompleted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileListCompleted(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileRetrieveRequest(TSBFTPSServerFileRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileRetrieveRequest(TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileAllocate(TSBFTPSServerFileAllocateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileAllocate(TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileStoreRequest(TSBFTPSServerFileRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileStoreRequest(TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileAppendRequest(TSBFTPSServerFileRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileAppendRequest(TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileInfoNeeded(TSBFTPSServerFileInfoNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileInfoNeeded(TSBFTPSServerFileInfoNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileRemoveRequest(TSBFTPSServerFileRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileRemoveRequest(TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileRenameRequest(TSBFTPSServerFileRenameRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileRenameRequest(TSBFTPSServerFileRenameRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnStatusRequest(TSBFTPSServerInformationRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStatusRequest(TSBFTPSServerInformationRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnVirtualHostRequest(TSBFTPSServerHostRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVirtualHostRequest(TSBFTPSServerHostRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnEstablishSecureConnection(TSBFTPSServerEstablishSecureConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEstablishSecureConnection(TSBFTPSServerEstablishSecureConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtPassiveModeRequest(TSBFTPSServerExtPassiveModeRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtPassiveModeRequest(TSBFTPSServerExtPassiveModeRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnSiteCommand(TSBFTPSServerSiteCommandEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSiteCommand(TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue);

		TElFTPSServer(TElFTPSServerHandle handle, TElOwnHandle ownHandle);

		explicit TElFTPSServer(TComponent &AOwner);

		explicit TElFTPSServer(TComponent *AOwner);

		virtual ~TElFTPSServer();

};
#endif /* SB_USE_CLASS_TELFTPSSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBFTPSSERVER */
