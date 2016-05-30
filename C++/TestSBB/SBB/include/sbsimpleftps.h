#ifndef __INC_SBSIMPLEFTPS
#define __INC_SBSIMPLEFTPS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbmath.h"
#include "sbhashfunction.h"
#include "sbcrc.h"
#include "sbstringlist.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssecconsts.h"
#include "sbdnssectypes.h"
#endif
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbsslclient.h"
#include "sbcmdsslclient.h"
#include "sbconstants.h"
#include "sbsharedresource.h"
#include "sbzlib.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#include "sbsocket.h"
#include "sbportknock.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_FTPS 	114688
#define SB_ERROR_FS_OPERATION_BASE 	2048
#define SB_FTPS_ERROR_CONTROL_CHANNEL_HANGUP 	114689
#define SB_FTPS_ERROR_LOCAL_SOURCE_NOT_FILE 	116737
#define SB_FTPS_ERROR_LOCAL_TARGET_NOT_FILE 	116738
#define SB_FTPS_ERROR_RESUME_OFFSET_TOO_LARGE 	116739
#define SB_FTPS_ERROR_OPERATION_CRITERIA_NOT_MET 	116740
#define SB_FTPS_ERROR_TIMES_NOT_SET 	116741

typedef TElClassHandle TElSimpleFTPSClientHandle;

typedef TElClassHandle TElFTPFileInfoHandle;

typedef TElClassHandle TElFTPProxySettingsHandle;

typedef TElFTPProxySettingsHandle TSBFTPProxySettingsHandle;

typedef TElClassHandle TElFTPSTransferManagerHandle;

typedef TElSimpleFTPSClientHandle ElSimpleFTPSClientHandle;

typedef TElClassHandle TElMultipartStreamAccessHandle;

typedef TElClassHandle TElFTPSTransferChunkHandle;

typedef TElClassHandle TElMultipartStreamPartHandle;

typedef uint8_t TSBFTPSSLStateRaw;

typedef enum
{
	fsPlain = 0,
	fsEncrypted = 1
} TSBFTPSSLState;

typedef uint8_t TSBFTPTransferTypeRaw;

typedef enum
{
	ttASCII = 0,
	ttBinary = 1
} TSBFTPTransferType;

typedef uint8_t TSBFTPAuthCmdRaw;

typedef enum
{
	acAuto = 0,
	acAuthTLS = 1,
	acAuthSSL = 2,
	acAuthTLSP = 3,
	acAuthTLSC = 4
} TSBFTPAuthCmd;

typedef uint8_t TSBFTPProxyTypeRaw;

typedef enum
{
	ptNone = 0,
	ptUserSite = 1,
	ptSite = 2,
	ptOpen = 3,
	ptUserPass = 4,
	ptTransparent = 5
} TSBFTPProxyType;

typedef uint8_t TSBFileEntryFormatRaw;

typedef enum
{
	fefUnknown = 0,
	fefUnix = 1,
	fefWindows = 2,
	fefMLSD = 3
} TSBFileEntryFormat;

typedef uint8_t TSBFileEntryTypeRaw;

typedef enum
{
	fetUnknown = 0,
	fetDirectory = 1,
	fetFile = 2,
	fetSymlink = 3,
	fetSpecial = 4,
	fetCurrentDirectory = 5,
	fetParentDirectory = 6
} TSBFileEntryType;

typedef uint8_t TSBFTPStateRaw;

typedef enum
{
	fsDisconnected = 0,
	fsConnected = 1,
	fsLoggedIn = 2
} TSBFTPState;

typedef uint8_t TSBFTPCheckMethodRaw;

typedef enum
{
	cmCRC = 0,
	cmMD5 = 1,
	cmSHA1 = 2
} TSBFTPCheckMethod;

typedef uint8_t TSBFTPOptionRaw;

typedef enum
{
	foCCCSiteWorkaround = 0,
	foSyncDataChannel = 1,
	foSmartSSLSetup = 2,
	foStreamingASCIIMode = 3,
	foPreallocateStorage = 4
} TSBFTPOption;

typedef uint32_t TSBFTPOptionsRaw;

typedef enum 
{
	f_foCCCSiteWorkaround = 1,
	f_foSyncDataChannel = 2,
	f_foSmartSSLSetup = 4,
	f_foStreamingASCIIMode = 8,
	f_foPreallocateStorage = 16
} TSBFTPOptions;

typedef uint8_t TSBFtpFileOperationRaw;

typedef enum
{
	ffoDownloadFile = 0,
	ffoUploadFile = 1,
	ffoDeleteFile = 2,
	ffoMakeDir = 3
} TSBFtpFileOperation;

typedef void (SB_CALLBACK *TSBFTPSTextDataEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pTextLine[], int32_t szTextLine);

typedef void (SB_CALLBACK *TSBFTPSBinaryDataEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pData[], int32_t szData);

typedef void (SB_CALLBACK *TSBFTPSInnerClientEvent)(void * _ObjectData, TObjectHandle Sender, TElSimpleFTPSClientHandle Client);

typedef void (SB_CALLBACK *TSBFTPSRenegotiationRequestEvent)(void * _ObjectData, TObjectHandle Sender, int8_t DataChannel, int8_t * Allow);

typedef void (SB_CALLBACK *TElFTPFileOperationEvent)(void * _ObjectData, TObjectHandle Sender, TSBFtpFileOperationRaw Operation, const char * pcRemotePath, int32_t szRemotePath, const char * pcLocalPath, int32_t szLocalPath, int8_t * Skip, int8_t * Cancel);

typedef void (SB_CALLBACK *TElFTPFileOperationResultEvent)(void * _ObjectData, TObjectHandle Sender, TSBFtpFileOperationRaw Operation, const char * pcRemotePath, int32_t szRemotePath, const char * pcLocalPath, int32_t szLocalPath, int32_t ErrorCode, const char * pcComment, int32_t szComment, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBFTPSFileNameChangeNeededEvent)(void * _ObjectData, TObjectHandle Sender, char * pcFileName, int32_t * szFileName, int8_t * Force);

#pragma pack(4)
typedef struct 
{
	void * FileName;
	int64_t FileSize;
	TSBFileEntryTypeRaw FileType;
	int8_t _dummy0;
	int16_t _dummy1;
	double FileDate;
	TSBFileEntryFormatRaw EntryFormat;
	int8_t _dummy2;
	int16_t _dummy3;
	void * RawData;
} TSBFTPFileInfo;

typedef uint8_t TSBFTPSTransferChunkStateRaw;

typedef enum
{
	tcsPrepared = 0,
	tcsActive = 1,
	tcsSucceeded = 2,
	tcsFailed = 3
} TSBFTPSTransferChunkState;

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ParseFileListEntry(const char * pcEntry, int32_t szEntry, TSBFTPFileInfo * FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ParseFileListEntry_1(TElSimpleFTPSClientHandle _Handle, const char * pcEntry, int32_t szEntry, TSBFTPFileInfo * FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ParseFileListEntry_2(const char * pcEntry, int32_t szEntry, TElFTPFileInfoHandle FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ParseFileListEntry_3(TElSimpleFTPSClientHandle _Handle, const char * pcEntry, int32_t szEntry, TElFTPFileInfoHandle FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ParseMLSDEntry(const char * pcEntry, int32_t szEntry, TSBFTPFileInfo * FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ParseMLSDEntry_1(TElSimpleFTPSClientHandle _Handle, const char * pcEntry, int32_t szEntry, TSBFTPFileInfo * FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ParseMLSDEntry_2(const char * pcEntry, int32_t szEntry, TElFTPFileInfoHandle FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ParseMLSDEntry_3(TElSimpleFTPSClientHandle _Handle, const char * pcEntry, int32_t szEntry, TElFTPFileInfoHandle FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Abort(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Acct(TElSimpleFTPSClientHandle _Handle, const char * pcAcctInfo, int32_t szAcctInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Allocate(TElSimpleFTPSClientHandle _Handle, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Assign(TElSimpleFTPSClientHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_CDUp(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ClearCommandChannel(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ClearCommandChannel_1(TElSimpleFTPSClientHandle _Handle, int8_t GracefulSSLClosure);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Interrupt(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Close(TElSimpleFTPSClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Cwd(TElSimpleFTPSClientHandle _Handle, const char * pcAPath, int32_t szAPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Delete(TElSimpleFTPSClientHandle _Handle, const char * pcAFilename, int32_t szAFilename);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetCurrentDir(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetServerSystem(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLSD(TElSimpleFTPSClientHandle _Handle);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLSD_1(TElSimpleFTPSClientHandle _Handle, TStringListHandle ResultList);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLSD_1(TElSimpleFTPSClientHandle _Handle, TElStringListHandle ResultList);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLSD_2(TElSimpleFTPSClientHandle _Handle, TListHandle ResultList);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLSD_3(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLSD_4(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath, TStringListHandle ResultList);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLSD_4(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath, TElStringListHandle ResultList);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLSD_5(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath, TListHandle ResultList);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MLST(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath, TElFTPFileInfoHandle FileInfo, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_CreateCompletePath(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_NOOP(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_DirectoryExists(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_FileExists(TElSimpleFTPSClientHandle _Handle, const char * pcAFilename, int32_t szAFilename, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetFileSize(TElSimpleFTPSClientHandle _Handle, const char * pcAFilename, int32_t szAFilename, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetFileTime(TElSimpleFTPSClientHandle _Handle, const char * pcAFilename, int32_t szAFilename, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_SetFileTime(TElSimpleFTPSClientHandle _Handle, const char * pcAFilename, int32_t szAFilename, int64_t NewDate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetRemoteChecksum(TElSimpleFTPSClientHandle _Handle, const char * pcAFileName, int32_t szAFileName, TSBFTPCheckMethodRaw CheckMethod, int64_t StartPoint, int64_t EndPoint, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetLocalChecksum(TElSimpleFTPSClientHandle _Handle, const char * pcAFileName, int32_t szAFileName, TSBFTPCheckMethodRaw CheckMethod, int64_t StartPoint, int64_t EndPoint, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetNameList(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetNameList_1(TElSimpleFTPSClientHandle _Handle, const char * pcParameters, int32_t szParameters);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetFileList(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetFileList_1(TElSimpleFTPSClientHandle _Handle, const char * pcParameters, int32_t szParameters);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetFileList_2(TElSimpleFTPSClientHandle _Handle, const char * pcParameters, int32_t szParameters, TStringListHandle ResultList);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetFileList_2(TElSimpleFTPSClientHandle _Handle, const char * pcParameters, int32_t szParameters, TElStringListHandle ResultList);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_GetFileList_3(TElSimpleFTPSClientHandle _Handle, const char * pcParameters, int32_t szParameters, TListHandle ResultList);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ListDirectory(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath, TListHandle Listing, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t IncludeFiles, int8_t IncludeDirectories);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_ListDirectory_1(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath, TListHandle Listing, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t IncludeFiles, int8_t IncludeDirectories, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Open(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_InternalValidate(TElSimpleFTPSClientHandle _Handle, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_EstablishSSLSession(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Login(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MakeDir(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_MountStruct(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Receive(TElSimpleFTPSClientHandle _Handle, const char * pcFilename, int32_t szFilename, int64_t StartPos, int64_t EndPos);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Receive_1(TElSimpleFTPSClientHandle _Handle, const char * pcFilename, int32_t szFilename, TStreamHandle Stream, int64_t StartPos, int64_t EndPos);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Reinitialize(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_RemoveDir(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Rename(TElSimpleFTPSClientHandle _Handle, const char * pcSourceFile, int32_t szSourceFile, const char * pcDestFile, int32_t szDestFile);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_RenegotiateCiphers(TElSimpleFTPSClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_SendCmd(TElSimpleFTPSClientHandle _Handle, const char * pcCommand, int32_t szCommand, const int16_t pAcceptCodes[], int32_t szAcceptCodes, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_SendCmd_1(TElSimpleFTPSClientHandle _Handle, const char * pcCommand, int32_t szCommand, const int16_t pAcceptCodes[], int32_t szAcceptCodes, const int16_t pIntermediateAcceptCodes[], int32_t szIntermediateAcceptCodes, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Send(TElSimpleFTPSClientHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, int64_t StartPos, int64_t EndPos, int8_t Append, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Send_1(TElSimpleFTPSClientHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Send_2(TElSimpleFTPSClientHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_DownloadFile(TElSimpleFTPSClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, const char * pcLocalFileName, int32_t szLocalFileName);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_DownloadFile_1(TElSimpleFTPSClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, const char * pcLocalFileName, int32_t szLocalFileName, TSBFileTransferModeRaw Mode);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_DownloadFile_2(TElSimpleFTPSClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, const char * pcLocalFileName, int32_t szLocalFileName, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_UploadFile(TElSimpleFTPSClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcRemoteFileName, int32_t szRemoteFileName);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_UploadFile_1(TElSimpleFTPSClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcRemoteFileName, int32_t szRemoteFileName, TSBFileTransferModeRaw Mode);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_UploadFile_2(TElSimpleFTPSClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcRemoteFileName, int32_t szRemoteFileName, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_DownloadStream(TElSimpleFTPSClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, TStreamHandle LocalStream, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_UploadStream(TElSimpleFTPSClientHandle _Handle, TStreamHandle LocalStream, const char * pcRemoteFileName, int32_t szRemoteFileName, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_DownloadFiles(TElSimpleFTPSClientHandle _Handle, const char * pcRemotePath, int32_t szRemotePath, const char * pcRemoteMask, int32_t szRemoteMask, const char * pcLocalPath, int32_t szLocalPath, TSBFileTransferModeRaw Mode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_DownloadFiles_1(TElSimpleFTPSClientHandle _Handle, const char * pcRemotePath, int32_t szRemotePath, const char * pcRemoteMask, int32_t szRemoteMask, const char * pcLocalPath, int32_t szLocalPath, TSBFileTransferModeRaw Mode, TSBFileCopyModeRaw CopyMode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_UploadFiles(TElSimpleFTPSClientHandle _Handle, const char * pcLocalPath, int32_t szLocalPath, const char * pcLocalMask, int32_t szLocalMask, const char * pcRemotePath, int32_t szRemotePath, TSBFileTransferModeRaw Mode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_UploadFiles_1(TElSimpleFTPSClientHandle _Handle, const char * pcLocalPath, int32_t szLocalPath, const char * pcLocalMask, int32_t szLocalMask, const char * pcRemotePath, int32_t szRemotePath, TSBFileTransferModeRaw Mode, TSBFileCopyModeRaw CopyMode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_RemoveFile(TElSimpleFTPSClientHandle _Handle, const char * pcFilename, int32_t szFilename);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_RemoveFiles(TElSimpleFTPSClientHandle _Handle, const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_RemoveFiles_1(TElSimpleFTPSClientHandle _Handle, TStringsHandle List);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_CipherSuite(TElSimpleFTPSClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_CompressionAlgorithm(TElSimpleFTPSClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_CipherSuites(TElSimpleFTPSClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_CipherSuites(TElSimpleFTPSClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_CipherSuitePriorities(TElSimpleFTPSClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_CipherSuitePriorities(TElSimpleFTPSClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_CompressionAlgorithms(TElSimpleFTPSClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_CompressionAlgorithms(TElSimpleFTPSClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Version(TElSimpleFTPSClientHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Active(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_LastReceivedReply(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ModeZSupported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtMLSTSupported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtMDTMSupported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtMFMTSupported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtSIZESupported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtRESTSupported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtXCRCSupported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtXMD5Supported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtXSHA1Supported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtOPTSUTF8Supported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ExtHOSTSupported(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_LocalNewLineConvention(TElSimpleFTPSClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_LocalNewLineConvention(TElSimpleFTPSClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UsingIPv6(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelResult(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_RemoteHost(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_RemoteIP(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_TotalBytesSent(TElSimpleFTPSClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_TotalBytesReceived(TElSimpleFTPSClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_TotalDataBytesSent(TElSimpleFTPSClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_TotalDataBytesReceived(TElSimpleFTPSClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Socket(TElSimpleFTPSClientHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_DataSocket(TElSimpleFTPSClientHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocketSettings(TElSimpleFTPSClientHandle _Handle, TElSocketSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Address(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_Address(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_AuthCmd(TElSimpleFTPSClientHandle _Handle, TSBFTPAuthCmdRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_AuthCmd(TElSimpleFTPSClientHandle _Handle, TSBFTPAuthCmdRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Port(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_Port(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Username(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_Username(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Password(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_Password(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_VirtualHostName(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_VirtualHostName(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_AccountInfo(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_AccountInfo(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_PassiveMode(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_PassiveMode(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SRPUsername(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SRPUsername(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SRPPassword(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SRPPassword(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_TransferType(TElSimpleFTPSClientHandle _Handle, TSBFTPTransferTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_TransferType(TElSimpleFTPSClientHandle _Handle, TSBFTPTransferTypeRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UseIPv6(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_UseIPv6(TElSimpleFTPSClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UseSSL(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_UseSSL(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ModeZ(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_ModeZ(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ModeZLevel(TElSimpleFTPSClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_ModeZLevel(TElSimpleFTPSClientHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Versions(TElSimpleFTPSClientHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_Versions(TElSimpleFTPSClientHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_CertStorage(TElSimpleFTPSClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_CertStorage(TElSimpleFTPSClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ClientCertStorage(TElSimpleFTPSClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_ClientCertStorage(TElSimpleFTPSClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SSLMode(TElSimpleFTPSClientHandle _Handle, TSBSSLModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SSLMode(TElSimpleFTPSClientHandle _Handle, TSBSSLModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_EncryptDataChannel(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_EncryptDataChannel(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_FTPBufferSize(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_FTPBufferSize(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ProxySettings(TElSimpleFTPSClientHandle _Handle, TElFTPProxySettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_ProxySettings(TElSimpleFTPSClientHandle _Handle, TElFTPProxySettingsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_TransferTimeout(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_TransferTimeout(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocketTimeout(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocketTimeout(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Extensions(TElSimpleFTPSClientHandle _Handle, TElClientSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_PeerExtensions(TElSimpleFTPSClientHandle _Handle, TElCustomSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_CommandSocketBinding(TElSimpleFTPSClientHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_CommandSocketBinding(TElSimpleFTPSClientHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_DataSocketBinding(TElSimpleFTPSClientHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_DataSocketBinding(TElSimpleFTPSClientHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_FileSystemAdapter(TElSimpleFTPSClientHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_FileSystemAdapter(TElSimpleFTPSClientHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_PortKnock(TElSimpleFTPSClientHandle _Handle, TElPortKnockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_PortKnock(TElSimpleFTPSClientHandle _Handle, TElPortKnockHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_TransferKeepAliveInterval(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_TransferKeepAliveInterval(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ListenTimeout(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_ListenTimeout(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UseSIZECmd(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_UseSIZECmd(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UseFEATCmd(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_UseFEATCmd(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_AdjustPasvAddress(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_AdjustPasvAddress(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UseSSLSessionResumption(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_UseSSLSessionResumption(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_RenegotiationAttackPreventionMode(TElSimpleFTPSClientHandle _Handle, TSBRenegotiationAttackPreventionModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_RenegotiationAttackPreventionMode(TElSimpleFTPSClientHandle _Handle, TSBRenegotiationAttackPreventionModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_IncomingSpeedLimit(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_IncomingSpeedLimit(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OutgoingSpeedLimit(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OutgoingSpeedLimit(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_ConcurrentConnections(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_ConcurrentConnections(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_MinSizeForConcurrentDownload(TElSimpleFTPSClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_MinSizeForConcurrentDownload(TElSimpleFTPSClientHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_Options(TElSimpleFTPSClientHandle _Handle, TSBFTPOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_Options(TElSimpleFTPSClientHandle _Handle, TSBFTPOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SSLOptions(TElSimpleFTPSClientHandle _Handle, TSBSSLOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SSLOptions(TElSimpleFTPSClientHandle _Handle, TSBSSLOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_QuoteParameters(TElSimpleFTPSClientHandle _Handle, TSBParamQuoteModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_QuoteParameters(TElSimpleFTPSClientHandle _Handle, TSBParamQuoteModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_QuoteParamChar(TElSimpleFTPSClientHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_QuoteParamChar(TElSimpleFTPSClientHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocksAuthentication(TElSimpleFTPSClientHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocksAuthentication(TElSimpleFTPSClientHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocksPassword(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocksPassword(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocksPort(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocksPort(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocksResolveAddress(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocksResolveAddress(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocksServer(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocksServer(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocksUserCode(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocksUserCode(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocksVersion(TElSimpleFTPSClientHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocksVersion(TElSimpleFTPSClientHandle _Handle, TElSocksVersionRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_SocksUseIPv6(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_SocksUseIPv6(TElSimpleFTPSClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UseSocks(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_UseSocks(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UseWebTunneling(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_UseWebTunneling(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelAddress(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_WebTunnelAddress(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelAuthentication(TElSimpleFTPSClientHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_WebTunnelAuthentication(TElSimpleFTPSClientHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelPassword(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_WebTunnelPassword(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelPort(TElSimpleFTPSClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_WebTunnelPort(TElSimpleFTPSClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelUserId(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_WebTunnelUserId(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelRequestHeaders(TElSimpleFTPSClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelResponseHeaders(TElSimpleFTPSClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelRequestHeaders(TElSimpleFTPSClientHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelResponseHeaders(TElSimpleFTPSClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_WebTunnelResponseBody(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_UseProxySettingsForDataChannel(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_UseProxySettingsForDataChannel(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_PreserveExistingFileTimes(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_PreserveExistingFileTimes(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_CopyEmptyDirs(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_CopyEmptyDirs(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_DeleteFailedDownloads(TElSimpleFTPSClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_DeleteFailedDownloads(TElSimpleFTPSClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_RemoteCharset(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_RemoteCharset(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_LocalCharset(TElSimpleFTPSClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_LocalCharset(TElSimpleFTPSClientHandle _Handle, const char * pcValue, int32_t szValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_DNS(TElSimpleFTPSClientHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_DNS(TElSimpleFTPSClientHandle _Handle, TElDNSSettingsHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OperationErrorHandling(TElSimpleFTPSClientHandle _Handle, TSBOperationErrorHandlingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OperationErrorHandling(TElSimpleFTPSClientHandle _Handle, TSBOperationErrorHandlingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnTextDataLine(TElSimpleFTPSClientHandle _Handle, TSBFTPSTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnTextDataLine(TElSimpleFTPSClientHandle _Handle, TSBFTPSTextDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnBinaryData(TElSimpleFTPSClientHandle _Handle, TSBFTPSBinaryDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnBinaryData(TElSimpleFTPSClientHandle _Handle, TSBFTPSBinaryDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnCertificateValidate(TElSimpleFTPSClientHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnCertificateValidate(TElSimpleFTPSClientHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnCertificateNeededEx(TElSimpleFTPSClientHandle _Handle, TSBCertificateNeededExEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnCertificateNeededEx(TElSimpleFTPSClientHandle _Handle, TSBCertificateNeededExEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnCiphersNegotiated(TElSimpleFTPSClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnCiphersNegotiated(TElSimpleFTPSClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnSSLError(TElSimpleFTPSClientHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnSSLError(TElSimpleFTPSClientHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnCertificateStatus(TElSimpleFTPSClientHandle _Handle, TSBCertificateStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnCertificateStatus(TElSimpleFTPSClientHandle _Handle, TSBCertificateStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnExtensionsReceived(TElSimpleFTPSClientHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnExtensionsReceived(TElSimpleFTPSClientHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnExtensionsPrepared(TElSimpleFTPSClientHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnExtensionsPrepared(TElSimpleFTPSClientHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnKeyNeeded(TElSimpleFTPSClientHandle _Handle, TSBClientKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnKeyNeeded(TElSimpleFTPSClientHandle _Handle, TSBClientKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnRenegotiationRequest(TElSimpleFTPSClientHandle _Handle, TSBFTPSRenegotiationRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnRenegotiationRequest(TElSimpleFTPSClientHandle _Handle, TSBFTPSRenegotiationRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnProgress(TElSimpleFTPSClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnProgress(TElSimpleFTPSClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnControlSend(TElSimpleFTPSClientHandle _Handle, TSBFTPSTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnControlSend(TElSimpleFTPSClientHandle _Handle, TSBFTPSTextDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnControlReceive(TElSimpleFTPSClientHandle _Handle, TSBFTPSTextDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnControlReceive(TElSimpleFTPSClientHandle _Handle, TSBFTPSTextDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnInnerClientCreated(TElSimpleFTPSClientHandle _Handle, TSBFTPSInnerClientEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnInnerClientCreated(TElSimpleFTPSClientHandle _Handle, TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnInnerClientLoggedIn(TElSimpleFTPSClientHandle _Handle, TSBFTPSInnerClientEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnInnerClientLoggedIn(TElSimpleFTPSClientHandle _Handle, TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnInnerClientDestroyed(TElSimpleFTPSClientHandle _Handle, TSBFTPSInnerClientEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnInnerClientDestroyed(TElSimpleFTPSClientHandle _Handle, TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnDNSKeyNeeded(TElSimpleFTPSClientHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnDNSKeyNeeded(TElSimpleFTPSClientHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnDNSKeyValidate(TElSimpleFTPSClientHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnDNSKeyValidate(TElSimpleFTPSClientHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnDNSResolve(TElSimpleFTPSClientHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnDNSResolve(TElSimpleFTPSClientHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnFileOperation(TElSimpleFTPSClientHandle _Handle, TElFTPFileOperationEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnFileOperation(TElSimpleFTPSClientHandle _Handle, TElFTPFileOperationEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnFileOperationResult(TElSimpleFTPSClientHandle _Handle, TElFTPFileOperationResultEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnFileOperationResult(TElSimpleFTPSClientHandle _Handle, TElFTPFileOperationResultEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_get_OnFileNameChangeNeeded(TElSimpleFTPSClientHandle _Handle, TSBFTPSFileNameChangeNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_set_OnFileNameChangeNeeded(TElSimpleFTPSClientHandle _Handle, TSBFTPSFileNameChangeNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleFTPSClient_Create(TComponentHandle AOwner, TElSimpleFTPSClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

#ifdef SB_USE_CLASS_TELFTPFILEINFO
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_Assign(TElFTPFileInfoHandle _Handle, TElFTPFileInfoHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_Assign_1(TElFTPFileInfoHandle _Handle, TSBFTPFileInfo * Source);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_get_FileDate(TElFTPFileInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_set_FileDate(TElFTPFileInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_get_FileType(TElFTPFileInfoHandle _Handle, TSBFileEntryTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_set_FileType(TElFTPFileInfoHandle _Handle, TSBFileEntryTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_get_Name(TElFTPFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_set_Name(TElFTPFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_get_Path(TElFTPFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_set_Path(TElFTPFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_get_Size(TElFTPFileInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_set_Size(TElFTPFileInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_get_EntryFormat(TElFTPFileInfoHandle _Handle, TSBFileEntryFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_set_EntryFormat(TElFTPFileInfoHandle _Handle, TSBFileEntryFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_get_RawData(TElFTPFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_set_RawData(TElFTPFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPFileInfo_Create(TElFTPFileInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

#ifdef SB_USE_CLASS_TELFTPPROXYSETTINGS
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_Assign(TElFTPProxySettingsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_get_Host(TElFTPProxySettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_set_Host(TElFTPProxySettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_get_Password(TElFTPProxySettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_set_Password(TElFTPProxySettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_get_Port(TElFTPProxySettingsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_set_Port(TElFTPProxySettingsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_get_ProxyType(TElFTPProxySettingsHandle _Handle, TSBFTPProxyTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_set_ProxyType(TElFTPProxySettingsHandle _Handle, TSBFTPProxyTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_get_Username(TElFTPProxySettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_set_Username(TElFTPProxySettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFTPProxySettings_Create(TElFTPProxySettingsHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPPROXYSETTINGS */

#ifdef SB_USE_CLASS_TELFTPSTRANSFERMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElFTPSTransferManager_Execute(TElFTPSTransferManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSTransferManager_Create(TElSimpleFTPSClientHandle Owner, const char * pcFilename, int32_t szFilename, const char * pcDir, int32_t szDir, TStreamHandle Stream, int64_t StartPos, int64_t EndPos, TElFTPSTransferManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPSTRANSFERMANAGER */

#ifdef SB_USE_CLASS_TELMULTIPARTSTREAMACCESS
SB_IMPORT uint32_t SB_APIENTRY TElMultipartStreamAccess_AcquirePart(TElMultipartStreamAccessHandle _Handle, int64_t StartPos, int64_t Size, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartStreamAccess_ReleasePart(TElMultipartStreamAccessHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartStreamAccess_Create(TStreamHandle Stream, int64_t Size, TElMultipartStreamAccessHandle * OutResult);
#endif /* SB_USE_CLASS_TELMULTIPARTSTREAMACCESS */

#ifdef SB_USE_CLASS_TELFTPSTRANSFERCHUNK
SB_IMPORT uint32_t SB_APIENTRY TElFTPSTransferChunk_Run(TElFTPSTransferChunkHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFTPSTransferChunk_Create(const char * pcFilename, int32_t szFilename, const char * pcDir, int32_t szDir, int64_t StartPos, int64_t EndPos, TElSimpleFTPSClientHandle Client, int8_t CreateCopy, TElMultipartStreamAccessHandle StreamAccess, TElFTPSTransferChunkHandle * OutResult);
#endif /* SB_USE_CLASS_TELFTPSTRANSFERCHUNK */

#ifdef SB_USE_CLASS_TELMULTIPARTSTREAMPART
SB_IMPORT uint32_t SB_APIENTRY TElMultipartStreamPart_Read(TElMultipartStreamPartHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartStreamPart_Write(TElMultipartStreamPartHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartStreamPart_Seek(TElMultipartStreamPartHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartStreamPart_Seek_1(TElMultipartStreamPartHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultipartStreamPart_Create(TElMultipartStreamAccessHandle Owner, TStreamHandle BaseStream, int64_t BaseSize, int64_t StartPos, int64_t Size, TElMultipartStreamPartHandle * OutResult);
#endif /* SB_USE_CLASS_TELMULTIPARTSTREAMPART */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSimpleFTPSClient;
class TElFTPFileInfo;
class TElFTPProxySettings;
typedef TElFTPProxySettings TSBFTPProxySettings;
class TElFTPSTransferManager;
typedef TElSimpleFTPSClient ElSimpleFTPSClient;
class TElMultipartStreamAccess;
class TElFTPSTransferChunk;
class TElMultipartStreamPart;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBFTPOptions)

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT
class TElSimpleFTPSClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSimpleFTPSClient)
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_Socket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_DataSocket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		TElSocketSettings* _Inst_SocketSettings;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELFTPPROXYSETTINGS
		TElFTPProxySettings* _Inst_ProxySettings;
#endif /* SB_USE_CLASS_TELFTPPROXYSETTINGS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		TElClientSSLExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		TElCustomSSLExtensions* _Inst_PeerExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_CommandSocketBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		TElClientSocketBinding* _Inst_DataSocketBinding;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELPORTKNOCK
		TElPortKnock* _Inst_PortKnock;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
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
		static void ParseFileListEntry(const std::string &Entry, TSBFTPFileInfo &FileInfo);

		void ParseFileListEntry_Inst(const std::string &Entry, TSBFTPFileInfo &FileInfo);

#ifdef SB_USE_CLASS_TELFTPFILEINFO
		static void ParseFileListEntry(const std::string &Entry, TElFTPFileInfo &FileInfo);

		static void ParseFileListEntry(const std::string &Entry, TElFTPFileInfo *FileInfo);
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

#ifdef SB_USE_CLASS_TELFTPFILEINFO
		void ParseFileListEntry_Inst(const std::string &Entry, TElFTPFileInfo &FileInfo);

		void ParseFileListEntry_Inst(const std::string &Entry, TElFTPFileInfo *FileInfo);
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

		static void ParseMLSDEntry(const std::string &Entry, TSBFTPFileInfo &FileInfo);

		void ParseMLSDEntry_Inst(const std::string &Entry, TSBFTPFileInfo &FileInfo);

#ifdef SB_USE_CLASS_TELFTPFILEINFO
		static void ParseMLSDEntry(const std::string &Entry, TElFTPFileInfo &FileInfo);

		static void ParseMLSDEntry(const std::string &Entry, TElFTPFileInfo *FileInfo);
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

#ifdef SB_USE_CLASS_TELFTPFILEINFO
		void ParseMLSDEntry_Inst(const std::string &Entry, TElFTPFileInfo &FileInfo);

		void ParseMLSDEntry_Inst(const std::string &Entry, TElFTPFileInfo *FileInfo);
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

		void Abort();

		void Acct(const std::string &AcctInfo);

		void Allocate(int32_t Size);

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void CDUp();

		void ClearCommandChannel();

		void ClearCommandChannel(bool GracefulSSLClosure);

		void Interrupt();

		void Close(bool Silent);

		void Cwd(const std::string &APath);

		void Delete(const std::string &AFilename);

		void GetCurrentDir(std::string &OutResult);

		void GetServerSystem(std::string &OutResult);

		void MLSD();

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void MLSD(TStringList &ResultList);

		void MLSD(TStringList *ResultList);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void MLSD(TElStringList &ResultList);

		void MLSD(TElStringList *ResultList);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
		void MLSD(TList &ResultList);

		void MLSD(TList *ResultList);
#endif /* SB_USE_CLASS_TLIST */

		void MLSD(const std::string &Path);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void MLSD(const std::string &Path, TStringList &ResultList);

		void MLSD(const std::string &Path, TStringList *ResultList);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void MLSD(const std::string &Path, TElStringList &ResultList);

		void MLSD(const std::string &Path, TElStringList *ResultList);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
		void MLSD(const std::string &Path, TList &ResultList);

		void MLSD(const std::string &Path, TList *ResultList);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELFTPFILEINFO
		bool MLST(const std::string &Path, TElFTPFileInfo &FileInfo);

		bool MLST(const std::string &Path, TElFTPFileInfo *FileInfo);
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

		void CreateCompletePath(const std::string &Path);

		void NOOP();

		bool DirectoryExists(const std::string &Path);

		bool FileExists(const std::string &AFilename);

		int64_t GetFileSize(const std::string &AFilename);

		int64_t GetFileTime(const std::string &AFilename);

		bool SetFileTime(const std::string &AFilename, int64_t NewDate);

		void GetRemoteChecksum(const std::string &AFileName, TSBFTPCheckMethod CheckMethod, int64_t StartPoint, int64_t EndPoint, std::string &OutResult);

		void GetLocalChecksum(const std::string &AFileName, TSBFTPCheckMethod CheckMethod, int64_t StartPoint, int64_t EndPoint, std::string &OutResult);

		void GetNameList();

		void GetNameList(const std::string &Parameters);

		void GetFileList();

		void GetFileList(const std::string &Parameters);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetFileList(const std::string &Parameters, TStringList &ResultList);

		void GetFileList(const std::string &Parameters, TStringList *ResultList);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetFileList(const std::string &Parameters, TElStringList &ResultList);

		void GetFileList(const std::string &Parameters, TElStringList *ResultList);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
		void GetFileList(const std::string &Parameters, TList &ResultList);

		void GetFileList(const std::string &Parameters, TList *ResultList);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ListDirectory(const std::string &Path, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories);

		void ListDirectory(const std::string &Path, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ListDirectory(const std::string &Path, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive);

		void ListDirectory(const std::string &Path, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive);
#endif /* SB_USE_CLASS_TLIST */

		void Open();

		void InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason);

		void EstablishSSLSession();

		void Login(std::string &OutResult);

		void MakeDir(const std::string &Path);

		void MountStruct(const std::string &Path);

		void Receive(const std::string &Filename, int64_t StartPos, int64_t EndPos);

#ifdef SB_USE_CLASS_TSTREAM
		void Receive(const std::string &Filename, TStream &Stream, int64_t StartPos, int64_t EndPos);

		void Receive(const std::string &Filename, TStream *Stream, int64_t StartPos, int64_t EndPos);
#endif /* SB_USE_CLASS_TSTREAM */

		void Reinitialize();

		void RemoveDir(const std::string &Path);

		void Rename(const std::string &SourceFile, const std::string &DestFile);

		void RenegotiateCiphers();

		int16_t SendCmd(const std::string &Command, const std::vector<int16_t> &AcceptCodes);

		int16_t SendCmd(const std::string &Command, const std::vector<int16_t> &AcceptCodes, const std::vector<int16_t> &IntermediateAcceptCodes);

#ifdef SB_USE_CLASS_TSTREAM
		void Send(TStream &Stream, const std::string &FileName, int64_t StartPos, int64_t EndPos, bool Append, int64_t RestartFrom);

		void Send(TStream *Stream, const std::string &FileName, int64_t StartPos, int64_t EndPos, bool Append, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Send(TStream &Stream, const std::string &FileName, int64_t RestartFrom);

		void Send(TStream *Stream, const std::string &FileName, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Send(TStream &Stream, const std::string &FileName);

		void Send(TStream *Stream, const std::string &FileName);
#endif /* SB_USE_CLASS_TSTREAM */

		void DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName);

		void DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, TSBFileTransferMode Mode);

		void DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, TSBFileTransferMode Mode, int64_t RestartFrom);

		void UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName);

		void UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, TSBFileTransferMode Mode);

		void UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom);

#ifdef SB_USE_CLASS_TSTREAM
		void DownloadStream(const std::string &RemoteFileName, TStream &LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom);

		void DownloadStream(const std::string &RemoteFileName, TStream *LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void UploadStream(TStream &LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom);

		void UploadStream(TStream *LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

		void DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive);

		void DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, TSBFileCopyMode CopyMode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive);

		void UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive);

		void UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, TSBFileCopyMode CopyMode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive);

		void RemoveFile(const std::string &Filename);

		void RemoveFiles(const std::string &Path, const std::string &Mask, bool CaseSensitive, bool Recursive);

#ifdef SB_USE_CLASS_TSTRINGS
		void RemoveFiles(TStrings &List);

		void RemoveFiles(TStrings *List);
#endif /* SB_USE_CLASS_TSTRINGS */

		virtual uint8_t get_CipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CipherSuite, TElSimpleFTPSClient, CipherSuite);

		virtual uint8_t get_CompressionAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithm, TElSimpleFTPSClient, CompressionAlgorithm);

		virtual bool get_CipherSuites(uint8_t Index);

		virtual void set_CipherSuites(uint8_t Index, bool Value);

		virtual int32_t get_CipherSuitePriorities(uint8_t Index);

		virtual void set_CipherSuitePriorities(uint8_t Index, int32_t Value);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

		virtual TSBVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_Version, TElSimpleFTPSClient, Version);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSimpleFTPSClient, Active);

		virtual void get_LastReceivedReply(std::string &OutResult);

		virtual bool get_ModeZSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ModeZSupported, TElSimpleFTPSClient, ModeZSupported);

		virtual bool get_ExtMLSTSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtMLSTSupported, TElSimpleFTPSClient, ExtMLSTSupported);

		virtual bool get_ExtMDTMSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtMDTMSupported, TElSimpleFTPSClient, ExtMDTMSupported);

		virtual bool get_ExtMFMTSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtMFMTSupported, TElSimpleFTPSClient, ExtMFMTSupported);

		virtual bool get_ExtSIZESupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtSIZESupported, TElSimpleFTPSClient, ExtSIZESupported);

		virtual bool get_ExtRESTSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtRESTSupported, TElSimpleFTPSClient, ExtRESTSupported);

		virtual bool get_ExtXCRCSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtXCRCSupported, TElSimpleFTPSClient, ExtXCRCSupported);

		virtual bool get_ExtXMD5Supported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtXMD5Supported, TElSimpleFTPSClient, ExtXMD5Supported);

		virtual bool get_ExtXSHA1Supported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtXSHA1Supported, TElSimpleFTPSClient, ExtXSHA1Supported);

		virtual bool get_ExtOPTSUTF8Supported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtOPTSUTF8Supported, TElSimpleFTPSClient, ExtOPTSUTF8Supported);

		virtual bool get_ExtHOSTSupported();

		SB_DECLARE_PROPERTY_GET(bool, get_ExtHOSTSupported, TElSimpleFTPSClient, ExtHOSTSupported);

		virtual void get_LocalNewLineConvention(std::vector<uint8_t> &OutResult);

		virtual void set_LocalNewLineConvention(const std::vector<uint8_t> &Value);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElSimpleFTPSClient, UsingIPv6);
#endif

		virtual int32_t get_WebTunnelResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_WebTunnelResult, TElSimpleFTPSClient, WebTunnelResult);

		virtual void get_RemoteHost(std::string &OutResult);

		virtual void get_RemoteIP(std::string &OutResult);

		virtual int64_t get_TotalBytesSent();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesSent, TElSimpleFTPSClient, TotalBytesSent);

		virtual int64_t get_TotalBytesReceived();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesReceived, TElSimpleFTPSClient, TotalBytesReceived);

		virtual int64_t get_TotalDataBytesSent();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalDataBytesSent, TElSimpleFTPSClient, TotalDataBytesSent);

		virtual int64_t get_TotalDataBytesReceived();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalDataBytesReceived, TElSimpleFTPSClient, TotalDataBytesReceived);

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_Socket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_Socket, TElSimpleFTPSClient, Socket);
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_DataSocket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_DataSocket, TElSimpleFTPSClient, DataSocket);
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		virtual TElSocketSettings* get_SocketSettings();

		SB_DECLARE_PROPERTY_GET(TElSocketSettings*, get_SocketSettings, TElSimpleFTPSClient, SocketSettings);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual TSBFTPAuthCmd get_AuthCmd();

		virtual void set_AuthCmd(TSBFTPAuthCmd Value);

		SB_DECLARE_PROPERTY(TSBFTPAuthCmd, get_AuthCmd, set_AuthCmd, TElSimpleFTPSClient, AuthCmd);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSimpleFTPSClient, Port);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_VirtualHostName(std::string &OutResult);

		virtual void set_VirtualHostName(const std::string &Value);

		virtual void get_AccountInfo(std::string &OutResult);

		virtual void set_AccountInfo(const std::string &Value);

		virtual bool get_PassiveMode();

		virtual void set_PassiveMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassiveMode, set_PassiveMode, TElSimpleFTPSClient, PassiveMode);

		virtual void get_SRPUsername(std::string &OutResult);

		virtual void set_SRPUsername(const std::string &Value);

		virtual void get_SRPPassword(std::string &OutResult);

		virtual void set_SRPPassword(const std::string &Value);

		virtual TSBFTPTransferType get_TransferType();

		virtual void set_TransferType(TSBFTPTransferType Value);

		SB_DECLARE_PROPERTY(TSBFTPTransferType, get_TransferType, set_TransferType, TElSimpleFTPSClient, TransferType);

#ifdef SB_WINDOWS
		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElSimpleFTPSClient, UseIPv6);
#endif

		virtual bool get_UseSSL();

		virtual void set_UseSSL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSL, set_UseSSL, TElSimpleFTPSClient, UseSSL);

		virtual bool get_ModeZ();

		virtual void set_ModeZ(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ModeZ, set_ModeZ, TElSimpleFTPSClient, ModeZ);

		virtual uint8_t get_ModeZLevel();

		virtual void set_ModeZLevel(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_ModeZLevel, set_ModeZLevel, TElSimpleFTPSClient, ModeZLevel);

		virtual TSBVersions get_Versions();

		virtual void set_Versions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_Versions, set_Versions, TElSimpleFTPSClient, Versions);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElSimpleFTPSClient, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElSimpleFTPSClient, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual TSBSSLMode get_SSLMode();

		virtual void set_SSLMode(TSBSSLMode Value);

		SB_DECLARE_PROPERTY(TSBSSLMode, get_SSLMode, set_SSLMode, TElSimpleFTPSClient, SSLMode);

		virtual bool get_EncryptDataChannel();

		virtual void set_EncryptDataChannel(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncryptDataChannel, set_EncryptDataChannel, TElSimpleFTPSClient, EncryptDataChannel);

		virtual int32_t get_FTPBufferSize();

		virtual void set_FTPBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FTPBufferSize, set_FTPBufferSize, TElSimpleFTPSClient, FTPBufferSize);

#ifdef SB_USE_CLASS_TELFTPPROXYSETTINGS
		virtual TElFTPProxySettings* get_ProxySettings();

		virtual void set_ProxySettings(TElFTPProxySettings &Value);

		virtual void set_ProxySettings(TElFTPProxySettings *Value);

		SB_DECLARE_PROPERTY(TElFTPProxySettings*, get_ProxySettings, set_ProxySettings, TElSimpleFTPSClient, ProxySettings);
#endif /* SB_USE_CLASS_TELFTPPROXYSETTINGS */

		virtual int32_t get_TransferTimeout();

		virtual void set_TransferTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TransferTimeout, set_TransferTimeout, TElSimpleFTPSClient, TransferTimeout);

		virtual int32_t get_SocketTimeout();

		virtual void set_SocketTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketTimeout, set_SocketTimeout, TElSimpleFTPSClient, SocketTimeout);

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		virtual TElClientSSLExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElClientSSLExtensions*, get_Extensions, TElSimpleFTPSClient, Extensions);
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
		virtual TElCustomSSLExtensions* get_PeerExtensions();

		SB_DECLARE_PROPERTY_GET(TElCustomSSLExtensions*, get_PeerExtensions, TElSimpleFTPSClient, PeerExtensions);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_CommandSocketBinding();

		virtual void set_CommandSocketBinding(TElClientSocketBinding &Value);

		virtual void set_CommandSocketBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_CommandSocketBinding, set_CommandSocketBinding, TElSimpleFTPSClient, CommandSocketBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_DataSocketBinding();

		virtual void set_DataSocketBinding(TElClientSocketBinding &Value);

		virtual void set_DataSocketBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_DataSocketBinding, set_DataSocketBinding, TElSimpleFTPSClient, DataSocketBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElSimpleFTPSClient, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_CLASS_TELPORTKNOCK
		virtual TElPortKnock* get_PortKnock();

		virtual void set_PortKnock(TElPortKnock &Value);

		virtual void set_PortKnock(TElPortKnock *Value);

		SB_DECLARE_PROPERTY(TElPortKnock*, get_PortKnock, set_PortKnock, TElSimpleFTPSClient, PortKnock);
#endif /* SB_USE_CLASS_TELPORTKNOCK */

		virtual int32_t get_TransferKeepAliveInterval();

		virtual void set_TransferKeepAliveInterval(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TransferKeepAliveInterval, set_TransferKeepAliveInterval, TElSimpleFTPSClient, TransferKeepAliveInterval);

		virtual int32_t get_ListenTimeout();

		virtual void set_ListenTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ListenTimeout, set_ListenTimeout, TElSimpleFTPSClient, ListenTimeout);

		virtual bool get_UseSIZECmd();

		virtual void set_UseSIZECmd(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSIZECmd, set_UseSIZECmd, TElSimpleFTPSClient, UseSIZECmd);

		virtual bool get_UseFEATCmd();

		virtual void set_UseFEATCmd(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseFEATCmd, set_UseFEATCmd, TElSimpleFTPSClient, UseFEATCmd);

		virtual bool get_AdjustPasvAddress();

		virtual void set_AdjustPasvAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AdjustPasvAddress, set_AdjustPasvAddress, TElSimpleFTPSClient, AdjustPasvAddress);

		virtual bool get_UseSSLSessionResumption();

		virtual void set_UseSSLSessionResumption(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSSLSessionResumption, set_UseSSLSessionResumption, TElSimpleFTPSClient, UseSSLSessionResumption);

		virtual TSBRenegotiationAttackPreventionMode get_RenegotiationAttackPreventionMode();

		virtual void set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value);

		SB_DECLARE_PROPERTY(TSBRenegotiationAttackPreventionMode, get_RenegotiationAttackPreventionMode, set_RenegotiationAttackPreventionMode, TElSimpleFTPSClient, RenegotiationAttackPreventionMode);

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElSimpleFTPSClient, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElSimpleFTPSClient, OutgoingSpeedLimit);

		virtual int32_t get_ConcurrentConnections();

		virtual void set_ConcurrentConnections(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ConcurrentConnections, set_ConcurrentConnections, TElSimpleFTPSClient, ConcurrentConnections);

		virtual int64_t get_MinSizeForConcurrentDownload();

		virtual void set_MinSizeForConcurrentDownload(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MinSizeForConcurrentDownload, set_MinSizeForConcurrentDownload, TElSimpleFTPSClient, MinSizeForConcurrentDownload);

		virtual TSBFTPOptions get_Options();

		virtual void set_Options(TSBFTPOptions Value);

		SB_DECLARE_PROPERTY(TSBFTPOptions, get_Options, set_Options, TElSimpleFTPSClient, Options);

		virtual TSBSSLOptions get_SSLOptions();

		virtual void set_SSLOptions(TSBSSLOptions Value);

		SB_DECLARE_PROPERTY(TSBSSLOptions, get_SSLOptions, set_SSLOptions, TElSimpleFTPSClient, SSLOptions);

		virtual TSBParamQuoteMode get_QuoteParameters();

		virtual void set_QuoteParameters(TSBParamQuoteMode Value);

		SB_DECLARE_PROPERTY(TSBParamQuoteMode, get_QuoteParameters, set_QuoteParameters, TElSimpleFTPSClient, QuoteParameters);

		virtual char get_QuoteParamChar();

		virtual void set_QuoteParamChar(char Value);

		SB_DECLARE_PROPERTY(char, get_QuoteParamChar, set_QuoteParamChar, TElSimpleFTPSClient, QuoteParamChar);

		virtual TElSocksAuthentication get_SocksAuthentication();

		virtual void set_SocksAuthentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_SocksAuthentication, set_SocksAuthentication, TElSimpleFTPSClient, SocksAuthentication);

		virtual void get_SocksPassword(std::string &OutResult);

		virtual void set_SocksPassword(const std::string &Value);

		virtual int32_t get_SocksPort();

		virtual void set_SocksPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocksPort, set_SocksPort, TElSimpleFTPSClient, SocksPort);

		virtual bool get_SocksResolveAddress();

		virtual void set_SocksResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksResolveAddress, set_SocksResolveAddress, TElSimpleFTPSClient, SocksResolveAddress);

		virtual void get_SocksServer(std::string &OutResult);

		virtual void set_SocksServer(const std::string &Value);

		virtual void get_SocksUserCode(std::string &OutResult);

		virtual void set_SocksUserCode(const std::string &Value);

		virtual TElSocksVersion get_SocksVersion();

		virtual void set_SocksVersion(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_SocksVersion, set_SocksVersion, TElSimpleFTPSClient, SocksVersion);

#ifdef SB_WINDOWS
		virtual bool get_SocksUseIPv6();

		virtual void set_SocksUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksUseIPv6, set_SocksUseIPv6, TElSimpleFTPSClient, SocksUseIPv6);
#endif

		virtual bool get_UseSocks();

		virtual void set_UseSocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSocks, set_UseSocks, TElSimpleFTPSClient, UseSocks);

		virtual bool get_UseWebTunneling();

		virtual void set_UseWebTunneling(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseWebTunneling, set_UseWebTunneling, TElSimpleFTPSClient, UseWebTunneling);

		virtual void get_WebTunnelAddress(std::string &OutResult);

		virtual void set_WebTunnelAddress(const std::string &Value);

		virtual TElWebTunnelAuthentication get_WebTunnelAuthentication();

		virtual void set_WebTunnelAuthentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_WebTunnelAuthentication, set_WebTunnelAuthentication, TElSimpleFTPSClient, WebTunnelAuthentication);

		virtual void get_WebTunnelPassword(std::string &OutResult);

		virtual void set_WebTunnelPassword(const std::string &Value);

		virtual int32_t get_WebTunnelPort();

		virtual void set_WebTunnelPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_WebTunnelPort, set_WebTunnelPort, TElSimpleFTPSClient, WebTunnelPort);

		virtual void get_WebTunnelUserId(std::string &OutResult);

		virtual void set_WebTunnelUserId(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelRequestHeaders, TElSimpleFTPSClient, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelRequestHeaders, TElSimpleFTPSClient, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelResponseHeaders, TElSimpleFTPSClient, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelResponseHeaders, TElSimpleFTPSClient, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_WebTunnelResponseBody(std::string &OutResult);

		virtual bool get_UseProxySettingsForDataChannel();

		virtual void set_UseProxySettingsForDataChannel(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseProxySettingsForDataChannel, set_UseProxySettingsForDataChannel, TElSimpleFTPSClient, UseProxySettingsForDataChannel);

		virtual bool get_PreserveExistingFileTimes();

		virtual void set_PreserveExistingFileTimes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveExistingFileTimes, set_PreserveExistingFileTimes, TElSimpleFTPSClient, PreserveExistingFileTimes);

		virtual bool get_CopyEmptyDirs();

		virtual void set_CopyEmptyDirs(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CopyEmptyDirs, set_CopyEmptyDirs, TElSimpleFTPSClient, CopyEmptyDirs);

		virtual bool get_DeleteFailedDownloads();

		virtual void set_DeleteFailedDownloads(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DeleteFailedDownloads, set_DeleteFailedDownloads, TElSimpleFTPSClient, DeleteFailedDownloads);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElSimpleFTPSClient, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

		virtual TSBOperationErrorHandling get_OperationErrorHandling();

		virtual void set_OperationErrorHandling(TSBOperationErrorHandling Value);

		SB_DECLARE_PROPERTY(TSBOperationErrorHandling, get_OperationErrorHandling, set_OperationErrorHandling, TElSimpleFTPSClient, OperationErrorHandling);

		virtual void get_OnTextDataLine(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTextDataLine(TSBFTPSTextDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnBinaryData(TSBFTPSBinaryDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBinaryData(TSBFTPSBinaryDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenegotiationRequest(TSBFTPSRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenegotiationRequest(TSBFTPSRenegotiationRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnControlSend(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnControlSend(TSBFTPSTextDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnControlReceive(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnControlReceive(TSBFTPSTextDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnInnerClientCreated(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInnerClientCreated(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);

		virtual void get_OnInnerClientLoggedIn(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInnerClientLoggedIn(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);

		virtual void get_OnInnerClientDestroyed(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInnerClientDestroyed(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		virtual void get_OnFileOperation(TElFTPFileOperationEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileOperation(TElFTPFileOperationEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileOperationResult(TElFTPFileOperationResultEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileOperationResult(TElFTPFileOperationResultEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileNameChangeNeeded(TSBFTPSFileNameChangeNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileNameChangeNeeded(TSBFTPSFileNameChangeNeededEvent pMethodValue, void * pDataValue);

		TElSimpleFTPSClient(TElSimpleFTPSClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleFTPSClient(TComponent &AOwner);

		explicit TElSimpleFTPSClient(TComponent *AOwner);

		virtual ~TElSimpleFTPSClient();

};
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

#ifdef SB_USE_CLASS_TELFTPFILEINFO
class TElFTPFileInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElFTPFileInfo)
	public:
		void Assign(TElFTPFileInfo &Source);

		void Assign(TElFTPFileInfo *Source);

		void Assign(TSBFTPFileInfo &Source);

		virtual int64_t get_FileDate();

		virtual void set_FileDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileDate, set_FileDate, TElFTPFileInfo, FileDate);

		virtual TSBFileEntryType get_FileType();

		virtual void set_FileType(TSBFileEntryType Value);

		SB_DECLARE_PROPERTY(TSBFileEntryType, get_FileType, set_FileType, TElFTPFileInfo, FileType);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Path(std::string &OutResult);

		virtual void set_Path(const std::string &Value);

		virtual int64_t get_Size();

		virtual void set_Size(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Size, set_Size, TElFTPFileInfo, Size);

		virtual TSBFileEntryFormat get_EntryFormat();

		virtual void set_EntryFormat(TSBFileEntryFormat Value);

		SB_DECLARE_PROPERTY(TSBFileEntryFormat, get_EntryFormat, set_EntryFormat, TElFTPFileInfo, EntryFormat);

		virtual void get_RawData(std::string &OutResult);

		virtual void set_RawData(const std::string &Value);

		TElFTPFileInfo(TElFTPFileInfoHandle handle, TElOwnHandle ownHandle);

		TElFTPFileInfo();

};
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

#ifdef SB_USE_CLASS_TELFTPPROXYSETTINGS
class TElFTPProxySettings: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElFTPProxySettings)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElFTPProxySettings, Port);

		virtual TSBFTPProxyType get_ProxyType();

		virtual void set_ProxyType(TSBFTPProxyType Value);

		SB_DECLARE_PROPERTY(TSBFTPProxyType, get_ProxyType, set_ProxyType, TElFTPProxySettings, ProxyType);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		TElFTPProxySettings(TElFTPProxySettingsHandle handle, TElOwnHandle ownHandle);

		TElFTPProxySettings();

};
#endif /* SB_USE_CLASS_TELFTPPROXYSETTINGS */

#ifdef SB_USE_CLASS_TELFTPSTRANSFERMANAGER
class TElFTPSTransferManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElFTPSTransferManager)
	public:
		void Execute();

		TElFTPSTransferManager(TElFTPSTransferManagerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASSES_TELSIMPLEFTPSCLIENT_AND_TSTREAM
		TElFTPSTransferManager(TElSimpleFTPSClient &Owner, const std::string &Filename, const std::string &Dir, TStream &Stream, int64_t StartPos, int64_t EndPos);

		TElFTPSTransferManager(TElSimpleFTPSClient *Owner, const std::string &Filename, const std::string &Dir, TStream *Stream, int64_t StartPos, int64_t EndPos);
#endif /* SB_USE_CLASSES_TELSIMPLEFTPSCLIENT_AND_TSTREAM */

};
#endif /* SB_USE_CLASS_TELFTPSTRANSFERMANAGER */

#ifdef SB_USE_CLASS_TELMULTIPARTSTREAMACCESS
class TElMultipartStreamAccess: public TObject
{
	private:
		SB_DISABLE_COPY(TElMultipartStreamAccess)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		TStreamHandle AcquirePart(int64_t StartPos, int64_t Size);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReleasePart(TStream &Stream);

		void ReleasePart(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		TElMultipartStreamAccess(TElMultipartStreamAccessHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTREAM
		TElMultipartStreamAccess(TStream &Stream, int64_t Size);

		TElMultipartStreamAccess(TStream *Stream, int64_t Size);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELMULTIPARTSTREAMACCESS */

#ifdef SB_USE_CLASS_TELFTPSTRANSFERCHUNK
class TElFTPSTransferChunk: public TObject
{
	private:
		SB_DISABLE_COPY(TElFTPSTransferChunk)
	public:
		void Run();

		TElFTPSTransferChunk(TElFTPSTransferChunkHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASSES_TELMULTIPARTSTREAMACCESS_AND_TELSIMPLEFTPSCLIENT
		TElFTPSTransferChunk(const std::string &Filename, const std::string &Dir, int64_t StartPos, int64_t EndPos, TElSimpleFTPSClient &Client, bool CreateCopy, TElMultipartStreamAccess &StreamAccess);

		TElFTPSTransferChunk(const std::string &Filename, const std::string &Dir, int64_t StartPos, int64_t EndPos, TElSimpleFTPSClient *Client, bool CreateCopy, TElMultipartStreamAccess *StreamAccess);
#endif /* SB_USE_CLASSES_TELMULTIPARTSTREAMACCESS_AND_TELSIMPLEFTPSCLIENT */

};
#endif /* SB_USE_CLASS_TELFTPSTRANSFERCHUNK */

#ifdef SB_USE_CLASS_TELMULTIPARTSTREAMPART
class TElMultipartStreamPart: public TStream
{
	private:
		SB_DISABLE_COPY(TElMultipartStreamPart)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		TElMultipartStreamPart(TElMultipartStreamPartHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELMULTIPARTSTREAMACCESS
		TElMultipartStreamPart(TElMultipartStreamAccess &Owner, TStream &BaseStream, int64_t BaseSize, int64_t StartPos, int64_t Size);

		TElMultipartStreamPart(TElMultipartStreamAccess *Owner, TStream *BaseStream, int64_t BaseSize, int64_t StartPos, int64_t Size);
#endif /* SB_USE_CLASS_TELMULTIPARTSTREAMACCESS */

};
#endif /* SB_USE_CLASS_TELMULTIPARTSTREAMPART */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSIMPLEFTPS */
