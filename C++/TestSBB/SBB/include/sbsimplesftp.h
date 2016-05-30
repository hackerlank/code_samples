#ifndef __INC_SBSIMPLESFTP
#define __INC_SBSIMPLESFTP

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
#include "sbstreams.h"
#include "sbstringlist.h"
#include "sbcryptoprov.h"
#include "sbsshcommon.h"
#include "sbsshclient.h"
#include "sbsshkeystorage.h"
#include "sbgssapibase.h"
#include "sbgssapi.h"
#include "sbsshconstants.h"
#include "sbsftp.h"
#include "sbsftpcommon.h"
#include "sbtimer.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#include "sbsharedresource.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbdnssecconsts.h"
#include "sbdnssectypes.h"
#endif
#include "sbsocket.h"
#include "sbportknock.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSimpleSFTPClientHandle;

typedef TElSimpleSFTPClientHandle ElSimpleSFTPClientHandle;

#ifdef SB_USE_CLASS_TELSIMPLESFTPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ExtensionCmd(TElSimpleSFTPClientHandle _Handle, const char * pcExtension, int32_t szExtension, void * DataBuffer, int32_t Size, TStreamHandle ResponseStream);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ExtensionCmd_1(TElSimpleSFTPClientHandle _Handle, const char * pcExtension, int32_t szExtension, TStreamHandle ResponseStream);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_Block(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccessRaw LockMask);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_Unblock(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int64_t Length);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_SendVendorID(TElSimpleSFTPClientHandle _Handle, TElSftpVendorIDExtensionHandle VendorID);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RequestFileHash(TElSimpleSFTPClientHandle _Handle, const char * pcFileName, int32_t szFileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReplyHandle FileHash);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RequestFileHashByHandle(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReplyHandle FileHash);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_QueryAvailableSpace(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpSpaceAvailableReplyHandle AvailSpace);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_QueryStatVFS(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpStatVFSReplyHandle StatVFS);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_QueryHomeDirectory(TElSimpleSFTPClientHandle _Handle, const char * pcUsername, int32_t szUsername, TElSftpFileInfoHandle HomeDir);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_CopyRemoteFile(TElSimpleSFTPClientHandle _Handle, const char * pcSource, int32_t szSource, const char * pcDestination, int32_t szDestination, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_CopyRemoteData(TElSimpleSFTPClientHandle _Handle, const uint8_t pReadFrom[], int32_t szReadFrom, int64_t ReadFromOffset, const uint8_t pWriteTo[], int32_t szWriteTo, int64_t WriteToOffset, int64_t DataLength);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RequestTempFolder(TElSimpleSFTPClientHandle _Handle, TElSftpFileInfoHandle TempFolder);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_MakeTempFolder(TElSimpleSFTPClientHandle _Handle, TElSftpFileInfoHandle TempFolder);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_FileExists(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_GetFileSize(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DirExists(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_Interrupt(TElSimpleSFTPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_Close(TElSimpleSFTPClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_CloseHandle(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_CreateFile(TElSimpleSFTPClientHandle _Handle, const char * pcFilename, int32_t szFilename, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_CreateSymLink(TElSimpleSFTPClientHandle _Handle, const char * pcLinkPath, int32_t szLinkPath, const char * pcTargetPath, int32_t szTargetPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_CreateHardLink(TElSimpleSFTPClientHandle _Handle, const char * pcLinkPath, int32_t szLinkPath, const char * pcTargetPath, int32_t szTargetPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadFiles(TElSimpleSFTPClientHandle _Handle, const char * pcRemotePath, int32_t szRemotePath, const char * pcRemoteMask, int32_t szRemoteMask, const char * pcLocalPath, int32_t szLocalPath, TSBFileTransferModeRaw Mode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadFiles_1(TElSimpleSFTPClientHandle _Handle, const char * pcRemotePath, int32_t szRemotePath, const char * pcRemoteMask, int32_t szRemoteMask, const char * pcLocalPath, int32_t szLocalPath, TSBFileTransferModeRaw Mode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive, int8_t DeleteFiles);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadFiles_2(TElSimpleSFTPClientHandle _Handle, const char * pcRemotePath, int32_t szRemotePath, const char * pcRemoteMask, int32_t szRemoteMask, const char * pcLocalPath, int32_t szLocalPath, TSBFileTransferModeRaw Mode, TSBFileCopyModeRaw CopyMode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadFiles(TElSimpleSFTPClientHandle _Handle, const char * pcLocalPath, int32_t szLocalPath, const char * pcLocalMask, int32_t szLocalMask, const char * pcRemotePath, int32_t szRemotePath, TSBFileTransferModeRaw Mode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadFiles_1(TElSimpleSFTPClientHandle _Handle, const char * pcLocalPath, int32_t szLocalPath, const char * pcLocalMask, int32_t szLocalMask, const char * pcRemotePath, int32_t szRemotePath, TSBFileTransferModeRaw Mode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive, int8_t DeleteFiles);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadFiles_2(TElSimpleSFTPClientHandle _Handle, const char * pcLocalPath, int32_t szLocalPath, const char * pcLocalMask, int32_t szLocalMask, const char * pcRemotePath, int32_t szRemotePath, TSBFileTransferModeRaw Mode, TSBFileCopyModeRaw CopyMode, int8_t CaseSensitive, TSBCaseConversionRaw CaseConversion, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadFile(TElSimpleSFTPClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, const char * pcLocalFileName, int32_t szLocalFileName);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadFile_1(TElSimpleSFTPClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, const char * pcLocalFileName, int32_t szLocalFileName, int8_t SuppressAdditionalOperations);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadFile_2(TElSimpleSFTPClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, const char * pcLocalFileName, int32_t szLocalFileName, TSBFileTransferModeRaw Mode);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadFile_3(TElSimpleSFTPClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, const char * pcLocalFileName, int32_t szLocalFileName, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadFile(TElSimpleSFTPClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcRemoteFileName, int32_t szRemoteFileName);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadFile_1(TElSimpleSFTPClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcRemoteFileName, int32_t szRemoteFileName, int8_t SuppressAdditionalOperations);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadFile_2(TElSimpleSFTPClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcRemoteFileName, int32_t szRemoteFileName, TSBFileTransferModeRaw Mode);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadFile_3(TElSimpleSFTPClientHandle _Handle, const char * pcLocalFileName, int32_t szLocalFileName, const char * pcRemoteFileName, int32_t szRemoteFileName, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadStream(TElSimpleSFTPClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, TStreamHandle LocalStream, TSBFileTransferModeRaw Mode);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadStream_1(TElSimpleSFTPClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, TStreamHandle LocalStream, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_DownloadStream_2(TElSimpleSFTPClientHandle _Handle, const char * pcRemoteFileName, int32_t szRemoteFileName, TStreamHandle LocalStream, int8_t SuppressAdditionalOperations);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadStream(TElSimpleSFTPClientHandle _Handle, TStreamHandle LocalStream, const char * pcRemoteFileName, int32_t szRemoteFileName, TSBFileTransferModeRaw Mode);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadStream_1(TElSimpleSFTPClientHandle _Handle, TStreamHandle LocalStream, const char * pcRemoteFileName, int32_t szRemoteFileName, TSBFileTransferModeRaw Mode, int64_t RestartFrom);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_UploadStream_2(TElSimpleSFTPClientHandle _Handle, TStreamHandle LocalStream, const char * pcRemoteFileName, int32_t szRemoteFileName, int8_t SuppressAdditionalOperations);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_MakeDirectory(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpFileAttributesHandle Attributes);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_CreateDirectoryPath(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_Open(TElSimpleSFTPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_OpenDirectory(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_OpenFile(TElSimpleSFTPClientHandle _Handle, const char * pcFilename, int32_t szFilename, TSBSftpFileOpenModesRaw Modes, TElSftpFileAttributesHandle Attributes, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_OpenFile_1(TElSimpleSFTPClientHandle _Handle, const char * pcFilename, int32_t szFilename, TSBSftpFileOpenModesRaw Modes, TSBSftpFileOpenAccessRaw Access, TElSftpFileAttributesHandle Attributes, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_OpenStream(TElSimpleSFTPClientHandle _Handle, const char * pcFilename, int32_t szFilename, TSBSftpFileOpenModesRaw Modes, TElSftpStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ReadDirectory(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, TListHandle Listing);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ReadDirectory_1(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, TListHandle Listing, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t IncludeFiles, int8_t IncludeDirectories);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ReadDirectory_2(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, TListHandle Listing, const char * pcMask, int32_t szMask, const char * pcDirectoryMask, int32_t szDirectoryMask, int8_t CaseSensitive, int8_t IncludeFiles, int8_t IncludeDirectories);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ReadDirectory_3(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, TListHandle Listing, const char * pcMask, int32_t szMask, const char * pcDirectoryMask, int32_t szDirectoryMask, int8_t CaseSensitive, int8_t IncludeFiles, int8_t IncludeDirectories, int8_t Recursive, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ListDirectory(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TListHandle Listing);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ListDirectory_1(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TListHandle Listing, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ListDirectory_2(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TListHandle Listing, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t IncludeFiles, int8_t IncludeDirectories);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ListDirectory_3(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TListHandle Listing, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t IncludeFiles, int8_t IncludeDirectories, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ReadSymLink(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpFileInfoHandle Info);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_Read(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, void * Buffer, int32_t Length, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RemoveDirectory(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RemoveDirectory_1(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RemoveFile(TElSimpleSFTPClientHandle _Handle, const char * pcFilename, int32_t szFilename);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RemoveFiles(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t Recursive);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RemoveFiles_1(TElSimpleSFTPClientHandle _Handle, TStringsHandle List);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RenameFile(TElSimpleSFTPClientHandle _Handle, const char * pcOldPath, int32_t szOldPath, const char * pcNewPath, int32_t szNewPath);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RequestAbsolutePath(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RequestAbsolutePathEx(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TSBSftpRealpathControlRaw Control, TStringListHandle ComposePath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RequestAttributes(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t FollowSymLinks, TElSftpFileAttributesHandle Attributes);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RequestAttributes_1(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, TElSftpFileAttributesHandle Attributes);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_SetAttributes(TElSimpleSFTPClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpFileAttributesHandle Attributes);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_SetAttributesByHandle(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, TElSftpFileAttributesHandle Attributes);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_Write(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_FinalizeTextWrite(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_TextSeek(TElSimpleSFTPClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t LineNumber);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_RenegotiateCiphers(TElSimpleSFTPClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ExecuteSSHCommand(TElSimpleSFTPClientHandle _Handle, const char * pcCommand, int32_t szCommand, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ExecuteSSHCommand_1(TElSimpleSFTPClientHandle _Handle, const char * pcCommand, int32_t szCommand, int8_t RedirectStdErr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_ExecuteSSHCommand_2(TElSimpleSFTPClientHandle _Handle, const char * pcCommand, int32_t szCommand, uint8_t pStdErrData[], int32_t * szStdErrData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CompressionAlgorithms(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_CompressionAlgorithms(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_EncryptionAlgorithms(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_EncryptionAlgorithms(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_KexAlgorithms(TElSimpleSFTPClientHandle _Handle, int8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_KexAlgorithms(TElSimpleSFTPClientHandle _Handle, int8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_MacAlgorithms(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_MacAlgorithms(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_PublicKeyAlgorithms(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_PublicKeyAlgorithms(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_EncryptionAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_EncryptionAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CompressionAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_CompressionAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_MacAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_MacAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_KexAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, int8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_KexAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, int8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_PublicKeyAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_PublicKeyAlgorithmPriorities(TElSimpleSFTPClientHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_AuthTypePriorities(TElSimpleSFTPClientHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_AuthTypePriorities(TElSimpleSFTPClientHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_Active(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CompressionAlgorithmClientToServer(TElSimpleSFTPClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CompressionAlgorithmServerToClient(TElSimpleSFTPClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_EncryptionAlgorithmClientToServer(TElSimpleSFTPClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_EncryptionAlgorithmServerToClient(TElSimpleSFTPClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_KexAlgorithm(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_LastSyncComment(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_LastSyncError(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_MacAlgorithmClientToServer(TElSimpleSFTPClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_MacAlgorithmServerToClient(TElSimpleSFTPClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocketSettings(TElSimpleSFTPClientHandle _Handle, TElSocketSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_NewLineConvention(TElSimpleSFTPClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_NewLineConvention(TElSimpleSFTPClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_LocalNewLineConvention(TElSimpleSFTPClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_LocalNewLineConvention(TElSimpleSFTPClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_PublicKeyAlgorithm(TElSimpleSFTPClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ServerCloseReason(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ServerSoftwareName(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SFTPExt(TElSimpleSFTPClientHandle _Handle, TSBSftpExtendedAttributeHandle pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SFTPExt(TElSimpleSFTPClientHandle _Handle, const TSBSftpExtendedAttributeHandle pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_Version(TElSimpleSFTPClientHandle _Handle, TSBSftpVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ExtendedProperties(TElSimpleSFTPClientHandle _Handle, TElSftpExtendedPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_KbdIntName(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_KbdIntInstruction(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ServerKey(TElSimpleSFTPClientHandle _Handle, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ProxyResult(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_TotalBytesSent(TElSimpleSFTPClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_TotalBytesReceived(TElSimpleSFTPClientHandle _Handle, int64_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UsingIPv6(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_GSSMechanism(TElSimpleSFTPClientHandle _Handle, TElGSSBaseMechanismHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_GSSMechanism(TElSimpleSFTPClientHandle _Handle, TElGSSBaseMechanismHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_GSSHostName(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_GSSHostName(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_GSSDelegateCredentials(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_GSSDelegateCredentials(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_InternalSocket(TElSimpleSFTPClientHandle _Handle, TElSocketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SecondaryChannelExitStatus(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SecondaryChannelExitSignal(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SecondaryChannelExitMessage(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SSHAuthOrder(TElSimpleSFTPClientHandle _Handle, TSBSSHAuthOrderRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SSHAuthOrder(TElSimpleSFTPClientHandle _Handle, TSBSSHAuthOrderRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_Address(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_Address(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_AutoAdjustCiphers(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_AutoAdjustCiphers(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_AuthenticationTypes(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_AuthenticationTypes(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ASCIIMode(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_ASCIIMode(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ClientHostname(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_ClientHostname(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ClientUsername(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_ClientUsername(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CompressionLevel(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_CompressionLevel(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ForceCompression(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_ForceCompression(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_KeyStorage(TElSimpleSFTPClientHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_KeyStorage(TElSimpleSFTPClientHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CryptoProviderManager(TElSimpleSFTPClientHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_CryptoProviderManager(TElSimpleSFTPClientHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_FileSystemAdapter(TElSimpleSFTPClientHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_FileSystemAdapter(TElSimpleSFTPClientHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_PortKnock(TElSimpleSFTPClientHandle _Handle, TElPortKnockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_PortKnock(TElSimpleSFTPClientHandle _Handle, TElPortKnockHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_DefaultWindowSize(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_DefaultWindowSize(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_MinWindowSize(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_MinWindowSize(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_MaxSSHPacketSize(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_MaxSSHPacketSize(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_TrustedKeys(TElSimpleSFTPClientHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_TrustedKeys(TElSimpleSFTPClientHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ObfuscateHandshake(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_ObfuscateHandshake(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ObfuscationPassword(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_ObfuscationPassword(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CopyEmptyDirs(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_CopyEmptyDirs(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_DeleteFailedDownloads(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_DeleteFailedDownloads(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_Password(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_Password(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_Port(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_Port(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SftpBufferSize(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SftpBufferSize(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocketTimeout(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocketTimeout(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocksAuthentication(TElSimpleSFTPClientHandle _Handle, TElSocksAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocksAuthentication(TElSimpleSFTPClientHandle _Handle, TElSocksAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocksPassword(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocksPassword(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocksPort(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocksPort(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocksResolveAddress(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocksResolveAddress(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocksServer(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocksServer(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocksUserCode(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocksUserCode(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocksVersion(TElSimpleSFTPClientHandle _Handle, TElSocksVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocksVersion(TElSimpleSFTPClientHandle _Handle, TElSocksVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SoftwareName(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SoftwareName(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_AutoAdjustTransferBlock(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_AutoAdjustTransferBlock(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UseInternalSocket(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_UseInternalSocket(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_Username(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_Username(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocksUseIPv6(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocksUseIPv6(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UseIPv6(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_UseIPv6(TElSimpleSFTPClientHandle _Handle, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UseSocks(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_UseSocks(TElSimpleSFTPClientHandle _Handle, int8_t Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_DNS(TElSimpleSFTPClientHandle _Handle, TElDNSSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_DNS(TElSimpleSFTPClientHandle _Handle, TElDNSSettingsHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UseWebTunneling(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_UseWebTunneling(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_Versions(TElSimpleSFTPClientHandle _Handle, TSBSftpVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_Versions(TElSimpleSFTPClientHandle _Handle, TSBSftpVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelAddress(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_WebTunnelAddress(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelAuthentication(TElSimpleSFTPClientHandle _Handle, TElWebTunnelAuthenticationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_WebTunnelAuthentication(TElSimpleSFTPClientHandle _Handle, TElWebTunnelAuthenticationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_LocalAddress(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_LocalAddress(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_LocalPort(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_LocalPort(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_PipelineLength(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_PipelineLength(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_DownloadBlockSize(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_DownloadBlockSize(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UploadBlockSize(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_UploadBlockSize(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UseUTF8(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_UseUTF8(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UseUTF8OnV3(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_UseUTF8OnV3(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_NoCharacterEncoding(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_NoCharacterEncoding(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_LocalCharset(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_LocalCharset(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_RemoteCharset(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_RemoteCharset(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelPassword(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_WebTunnelPassword(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelPort(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_WebTunnelPort(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelUserId(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_WebTunnelUserId(TElSimpleSFTPClientHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelRequestHeaders(TElSimpleSFTPClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelResponseHeaders(TElSimpleSFTPClientHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelRequestHeaders(TElSimpleSFTPClientHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelResponseHeaders(TElSimpleSFTPClientHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_WebTunnelResponseBody(TElSimpleSFTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OperationErrorHandling(TElSimpleSFTPClientHandle _Handle, TSBOperationErrorHandlingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OperationErrorHandling(TElSimpleSFTPClientHandle _Handle, TSBOperationErrorHandlingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_RequestPasswordChange(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_RequestPasswordChange(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CertAuthMode(TElSimpleSFTPClientHandle _Handle, TSBSSHCertAuthModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_CertAuthMode(TElSimpleSFTPClientHandle _Handle, TSBSSHCertAuthModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_AuthAttempts(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_AuthAttempts(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_IncomingSpeedLimit(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_IncomingSpeedLimit(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OutgoingSpeedLimit(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OutgoingSpeedLimit(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SocketBinding(TElSimpleSFTPClientHandle _Handle, TElClientSocketBindingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_SocketBinding(TElSimpleSFTPClientHandle _Handle, TElClientSocketBindingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_KeepAlivePeriod(TElSimpleSFTPClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_KeepAlivePeriod(TElSimpleSFTPClientHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_ThreadSafe(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_ThreadSafe(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_AdjustFileTimes(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_AdjustFileTimes(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_PreserveExistingFileTimes(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_PreserveExistingFileTimes(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_UseTruncateFlagOnUpload(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_UseTruncateFlagOnUpload(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_TreatZeroSizeAsUndefined(TElSimpleSFTPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_TreatZeroSizeAsUndefined(TElSimpleSFTPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_SFTPServerExecutableLocations(TElSimpleSFTPClientHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_CommandTimeout(TElSimpleSFTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_CommandTimeout(TElSimpleSFTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnAuthenticationFailed(TElSimpleSFTPClientHandle _Handle, TSSHAuthenticationFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnAuthenticationFailed(TElSimpleSFTPClientHandle _Handle, TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnAuthenticationKeyboard(TElSimpleSFTPClientHandle _Handle, TSSHAuthenticationKeyboardEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnAuthenticationKeyboard(TElSimpleSFTPClientHandle _Handle, TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnAuthenticationSuccess(TElSimpleSFTPClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnAuthenticationSuccess(TElSimpleSFTPClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnBanner(TElSimpleSFTPClientHandle _Handle, TSSHBannerEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnBanner(TElSimpleSFTPClientHandle _Handle, TSSHBannerEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnCloseConnection(TElSimpleSFTPClientHandle _Handle, TSSHCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnCloseConnection(TElSimpleSFTPClientHandle _Handle, TSSHCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnError(TElSimpleSFTPClientHandle _Handle, TSSHErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnError(TElSimpleSFTPClientHandle _Handle, TSSHErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnKeyValidate(TElSimpleSFTPClientHandle _Handle, TSSHKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnKeyValidate(TElSimpleSFTPClientHandle _Handle, TSSHKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnReceive(TElSimpleSFTPClientHandle _Handle, TSSHReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnReceive(TElSimpleSFTPClientHandle _Handle, TSSHReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnSend(TElSimpleSFTPClientHandle _Handle, TSSHSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnSend(TElSimpleSFTPClientHandle _Handle, TSSHSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnProgress(TElSimpleSFTPClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnProgress(TElSimpleSFTPClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnFileOperation(TElSimpleSFTPClientHandle _Handle, TElSftpFileOperationEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnFileOperation(TElSimpleSFTPClientHandle _Handle, TElSftpFileOperationEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnFileOperationResult(TElSimpleSFTPClientHandle _Handle, TElSftpFileOperationResultEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnFileOperationResult(TElSimpleSFTPClientHandle _Handle, TElSftpFileOperationResultEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnBlockTransferPrepared(TElSimpleSFTPClientHandle _Handle, TSBSftpBlockTransferPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnBlockTransferPrepared(TElSimpleSFTPClientHandle _Handle, TSBSftpBlockTransferPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnCiphersNegotiated(TElSimpleSFTPClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnCiphersNegotiated(TElSimpleSFTPClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnPasswordChangeRequest(TElSimpleSFTPClientHandle _Handle, TSSHPasswordChangeRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnPasswordChangeRequest(TElSimpleSFTPClientHandle _Handle, TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnPrivateKeyNeeded(TElSimpleSFTPClientHandle _Handle, TSSHPrivateKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnPrivateKeyNeeded(TElSimpleSFTPClientHandle _Handle, TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnAuthenticationStart(TElSimpleSFTPClientHandle _Handle, TSSHAuthenticationStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnAuthenticationStart(TElSimpleSFTPClientHandle _Handle, TSSHAuthenticationStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnAuthenticationAttempt(TElSimpleSFTPClientHandle _Handle, TSSHAuthenticationAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnAuthenticationAttempt(TElSimpleSFTPClientHandle _Handle, TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_MessageLoop(TElSimpleSFTPClientHandle _Handle, TSBSftpMessageLoopEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_MessageLoop(TElSimpleSFTPClientHandle _Handle, TSBSftpMessageLoopEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnTunnelOpenFailed(TElSimpleSFTPClientHandle _Handle, TSBSftpTunnelOpenFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnTunnelOpenFailed(TElSimpleSFTPClientHandle _Handle, TSBSftpTunnelOpenFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnSecondaryChannelPrepared(TElSimpleSFTPClientHandle _Handle, TSBSftpSecondaryChannelEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnSecondaryChannelPrepared(TElSimpleSFTPClientHandle _Handle, TSBSftpSecondaryChannelEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnSecondaryChannelOpen(TElSimpleSFTPClientHandle _Handle, TSBSftpSecondaryChannelEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnSecondaryChannelOpen(TElSimpleSFTPClientHandle _Handle, TSBSftpSecondaryChannelEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnSecondaryChannelError(TElSimpleSFTPClientHandle _Handle, TSBSftpSecondaryChannelErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnSecondaryChannelError(TElSimpleSFTPClientHandle _Handle, TSBSftpSecondaryChannelErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnFileNameChangeNeeded(TElSimpleSFTPClientHandle _Handle, TSBSftpFileNameChangeNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnFileNameChangeNeeded(TElSimpleSFTPClientHandle _Handle, TSBSftpFileNameChangeNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnKexInitReceived(TElSimpleSFTPClientHandle _Handle, TSSHKexInitReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnKexInitReceived(TElSimpleSFTPClientHandle _Handle, TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnDNSKeyNeeded(TElSimpleSFTPClientHandle _Handle, TSBDNSKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnDNSKeyNeeded(TElSimpleSFTPClientHandle _Handle, TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnDNSKeyValidate(TElSimpleSFTPClientHandle _Handle, TSBDNSKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnDNSKeyValidate(TElSimpleSFTPClientHandle _Handle, TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_get_OnDNSResolve(TElSimpleSFTPClientHandle _Handle, TSBDNSResolveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_set_OnDNSResolve(TElSimpleSFTPClientHandle _Handle, TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPClient_Create(TComponentHandle AOwner, TElSimpleSFTPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESFTPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSimpleSFTPClient;
typedef TElSimpleSFTPClient ElSimpleSFTPClient;

#ifdef SB_USE_CLASS_TELSIMPLESFTPCLIENT
class TElSimpleSFTPClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSimpleSFTPClient)
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		TElSocketSettings* _Inst_SocketSettings;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
		TElSftpExtendedProperties* _Inst_ExtendedProperties;
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */
#ifdef SB_USE_CLASS_TELSSHKEY
		TElSSHKey* _Inst_ServerKey;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
		TElGSSBaseMechanism* _Inst_GSSMechanism;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSOCKET
		TElSocket* _Inst_InternalSocket;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_KeyStorage;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELPORTKNOCK
		TElPortKnock* _Inst_PortKnock;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_TrustedKeys;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		TElDNSSettings* _Inst_DNS;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
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
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_SFTPServerExecutableLocations;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void ExtensionCmd(const std::string &Extension, void * DataBuffer, int32_t Size, TStream &ResponseStream);

		void ExtensionCmd(const std::string &Extension, void * DataBuffer, int32_t Size, TStream *ResponseStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ExtensionCmd(const std::string &Extension, TStream &ResponseStream);

		void ExtensionCmd(const std::string &Extension, TStream *ResponseStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Block(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccess LockMask);

		void Unblock(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length);

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
		void SendVendorID(TElSftpVendorIDExtension &VendorID);

		void SendVendorID(TElSftpVendorIDExtension *VendorID);
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEREPLY
		void RequestFileHash(const std::string &FileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReply &FileHash);

		void RequestFileHash(const std::string &FileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReply *FileHash);
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEREPLY */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEREPLY
		void RequestFileHashByHandle(const std::vector<uint8_t> &Handle, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReply &FileHash);

		void RequestFileHashByHandle(const std::vector<uint8_t> &Handle, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReply *FileHash);
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY
		void QueryAvailableSpace(const std::string &Path, TElSftpSpaceAvailableReply &AvailSpace);

		void QueryAvailableSpace(const std::string &Path, TElSftpSpaceAvailableReply *AvailSpace);
#endif /* SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSTATVFSREPLY
		void QueryStatVFS(const std::string &Path, TElSftpStatVFSReply &StatVFS);

		void QueryStatVFS(const std::string &Path, TElSftpStatVFSReply *StatVFS);
#endif /* SB_USE_CLASS_TELSFTPSTATVFSREPLY */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
		void QueryHomeDirectory(const std::string &Username, TElSftpFileInfo &HomeDir);

		void QueryHomeDirectory(const std::string &Username, TElSftpFileInfo *HomeDir);
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

		void CopyRemoteFile(const std::string &Source, const std::string &Destination, bool Overwrite);

		void CopyRemoteData(const std::vector<uint8_t> &ReadFrom, int64_t ReadFromOffset, const std::vector<uint8_t> &WriteTo, int64_t WriteToOffset, int64_t DataLength);

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
		void RequestTempFolder(TElSftpFileInfo &TempFolder);

		void RequestTempFolder(TElSftpFileInfo *TempFolder);
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
		void MakeTempFolder(TElSftpFileInfo &TempFolder);

		void MakeTempFolder(TElSftpFileInfo *TempFolder);
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

		bool FileExists(const std::string &Path);

		int64_t GetFileSize(const std::string &Path);

		bool DirExists(const std::string &Path);

		void Interrupt();

		void Close(bool Silent);

		void CloseHandle(const std::vector<uint8_t> &Handle);

		void CreateFile(const std::string &Filename, std::vector<uint8_t> &OutResult);

		void CreateSymLink(const std::string &LinkPath, const std::string &TargetPath);

		void CreateHardLink(const std::string &LinkPath, const std::string &TargetPath);

		void DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive);

		void DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive, bool DeleteFiles);

		void DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, TSBFileCopyMode CopyMode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive);

		void UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive);

		void UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive, bool DeleteFiles);

		void UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, TSBFileCopyMode CopyMode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive);

		void DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName);

		void DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, bool SuppressAdditionalOperations);

		void DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, TSBFileTransferMode Mode);

		void DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, TSBFileTransferMode Mode, int64_t RestartFrom);

		void UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName);

		void UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, bool SuppressAdditionalOperations);

		void UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, TSBFileTransferMode Mode);

		void UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom);

#ifdef SB_USE_CLASS_TSTREAM
		void DownloadStream(const std::string &RemoteFileName, TStream &LocalStream, TSBFileTransferMode Mode);

		void DownloadStream(const std::string &RemoteFileName, TStream *LocalStream, TSBFileTransferMode Mode);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void DownloadStream(const std::string &RemoteFileName, TStream &LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom);

		void DownloadStream(const std::string &RemoteFileName, TStream *LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void DownloadStream(const std::string &RemoteFileName, TStream &LocalStream, bool SuppressAdditionalOperations);

		void DownloadStream(const std::string &RemoteFileName, TStream *LocalStream, bool SuppressAdditionalOperations);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void UploadStream(TStream &LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode);

		void UploadStream(TStream *LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void UploadStream(TStream &LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom);

		void UploadStream(TStream *LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void UploadStream(TStream &LocalStream, const std::string &RemoteFileName, bool SuppressAdditionalOperations);

		void UploadStream(TStream *LocalStream, const std::string &RemoteFileName, bool SuppressAdditionalOperations);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void MakeDirectory(const std::string &Path, TElSftpFileAttributes &Attributes);

		void MakeDirectory(const std::string &Path, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

		void CreateDirectoryPath(const std::string &Path);

		void Open();

		void OpenDirectory(const std::string &Path, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes &Attributes, std::vector<uint8_t> &OutResult);

		void OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes *Attributes, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes &Attributes, std::vector<uint8_t> &OutResult);

		void OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes *Attributes, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPSTREAM
		TElSftpStreamHandle OpenStream(const std::string &Filename, TSBSftpFileOpenModes Modes);
#endif /* SB_USE_CLASS_TELSFTPSTREAM */

#ifdef SB_USE_CLASS_TLIST
		void ReadDirectory(const std::vector<uint8_t> &Handle, TList &Listing);

		void ReadDirectory(const std::vector<uint8_t> &Handle, TList *Listing);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ReadDirectory(const std::vector<uint8_t> &Handle, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories);

		void ReadDirectory(const std::vector<uint8_t> &Handle, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ReadDirectory(const std::vector<uint8_t> &Handle, TList &Listing, const std::string &Mask, const std::string &DirectoryMask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories);

		void ReadDirectory(const std::vector<uint8_t> &Handle, TList *Listing, const std::string &Mask, const std::string &DirectoryMask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ReadDirectory(const std::vector<uint8_t> &Handle, TList &Listing, const std::string &Mask, const std::string &DirectoryMask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive, const std::string &Path);

		void ReadDirectory(const std::vector<uint8_t> &Handle, TList *Listing, const std::string &Mask, const std::string &DirectoryMask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive, const std::string &Path);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ListDirectory(const std::string &Path, TList &Listing);

		void ListDirectory(const std::string &Path, TList *Listing);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ListDirectory(const std::string &Path, TList &Listing, bool Recursive);

		void ListDirectory(const std::string &Path, TList *Listing, bool Recursive);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ListDirectory(const std::string &Path, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories);

		void ListDirectory(const std::string &Path, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ListDirectory(const std::string &Path, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive);

		void ListDirectory(const std::string &Path, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
		void ReadSymLink(const std::string &Path, TElSftpFileInfo &Info);

		void ReadSymLink(const std::string &Path, TElSftpFileInfo *Info);
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

		int32_t Read(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Length);

		void RemoveDirectory(const std::string &Path);

		void RemoveDirectory(const std::string &Path, bool Recursive);

		void RemoveFile(const std::string &Filename);

		void RemoveFiles(const std::string &Path, const std::string &Mask, bool CaseSensitive, bool Recursive);

#ifdef SB_USE_CLASS_TSTRINGS
		void RemoveFiles(TStrings &List);

		void RemoveFiles(TStrings *List);
#endif /* SB_USE_CLASS_TSTRINGS */

		void RenameFile(const std::string &OldPath, const std::string &NewPath);

		void RequestAbsolutePath(const std::string &Path, std::string &OutResult);

#ifdef SB_USE_CLASS_TSTRINGLIST
		void RequestAbsolutePathEx(const std::string &Path, TSBSftpRealpathControl Control, TStringList &ComposePath, std::string &OutResult);

		void RequestAbsolutePathEx(const std::string &Path, TSBSftpRealpathControl Control, TStringList *ComposePath, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void RequestAttributes(const std::string &Path, bool FollowSymLinks, TElSftpFileAttributes &Attributes);

		void RequestAttributes(const std::string &Path, bool FollowSymLinks, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void RequestAttributes(const std::vector<uint8_t> &Handle, TElSftpFileAttributes &Attributes);

		void RequestAttributes(const std::vector<uint8_t> &Handle, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void SetAttributes(const std::string &Path, TElSftpFileAttributes &Attributes);

		void SetAttributes(const std::string &Path, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void SetAttributesByHandle(const std::vector<uint8_t> &Handle, TElSftpFileAttributes &Attributes);

		void SetAttributesByHandle(const std::vector<uint8_t> &Handle, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

		void Write(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Size);

		void FinalizeTextWrite(const std::vector<uint8_t> &Handle);

		void TextSeek(const std::vector<uint8_t> &Handle, int64_t LineNumber);

		void RenegotiateCiphers();

		void ExecuteSSHCommand(const std::string &Command, std::vector<uint8_t> &OutResult);

		void ExecuteSSHCommand(const std::string &Command, bool RedirectStdErr, std::vector<uint8_t> &OutResult);

		void ExecuteSSHCommand(const std::string &Command, std::vector<uint8_t> &StdErrData, std::vector<uint8_t> &OutResult);

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

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSimpleSFTPClient, Active);

		virtual uint8_t get_CompressionAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithmClientToServer, TElSimpleSFTPClient, CompressionAlgorithmClientToServer);

		virtual uint8_t get_CompressionAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithmServerToClient, TElSimpleSFTPClient, CompressionAlgorithmServerToClient);

		virtual uint8_t get_EncryptionAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_EncryptionAlgorithmClientToServer, TElSimpleSFTPClient, EncryptionAlgorithmClientToServer);

		virtual uint8_t get_EncryptionAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_EncryptionAlgorithmServerToClient, TElSimpleSFTPClient, EncryptionAlgorithmServerToClient);

		virtual int8_t get_KexAlgorithm();

		SB_DECLARE_PROPERTY_GET(int8_t, get_KexAlgorithm, TElSimpleSFTPClient, KexAlgorithm);

		virtual void get_LastSyncComment(std::string &OutResult);

		virtual int32_t get_LastSyncError();

		SB_DECLARE_PROPERTY_GET(int32_t, get_LastSyncError, TElSimpleSFTPClient, LastSyncError);

		virtual uint8_t get_MacAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_MacAlgorithmClientToServer, TElSimpleSFTPClient, MacAlgorithmClientToServer);

		virtual uint8_t get_MacAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_MacAlgorithmServerToClient, TElSimpleSFTPClient, MacAlgorithmServerToClient);

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
		virtual TElSocketSettings* get_SocketSettings();

		SB_DECLARE_PROPERTY_GET(TElSocketSettings*, get_SocketSettings, TElSimpleSFTPClient, SocketSettings);
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

		virtual void get_NewLineConvention(std::vector<uint8_t> &OutResult);

		virtual void set_NewLineConvention(const std::vector<uint8_t> &Value);

		virtual void get_LocalNewLineConvention(std::vector<uint8_t> &OutResult);

		virtual void set_LocalNewLineConvention(const std::vector<uint8_t> &Value);

		virtual uint8_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_PublicKeyAlgorithm, TElSimpleSFTPClient, PublicKeyAlgorithm);

		virtual void get_ServerCloseReason(std::string &OutResult);

		virtual void get_ServerSoftwareName(std::string &OutResult);

		virtual void get_SFTPExt(std::vector<TSBSftpExtendedAttributeHandle> &OutResult);

		virtual void set_SFTPExt(const std::vector<TSBSftpExtendedAttributeHandle> &Value);

		virtual TSBSftpVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSBSftpVersion, get_Version, TElSimpleSFTPClient, Version);

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
		virtual TElSftpExtendedProperties* get_ExtendedProperties();

		SB_DECLARE_PROPERTY_GET(TElSftpExtendedProperties*, get_ExtendedProperties, TElSimpleSFTPClient, ExtendedProperties);
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */

		virtual void get_KbdIntName(std::string &OutResult);

		virtual void get_KbdIntInstruction(std::string &OutResult);

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual TElSSHKey* get_ServerKey();

		SB_DECLARE_PROPERTY_GET(TElSSHKey*, get_ServerKey, TElSimpleSFTPClient, ServerKey);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual int32_t get_ProxyResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ProxyResult, TElSimpleSFTPClient, ProxyResult);

		virtual int64_t get_TotalBytesSent();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesSent, TElSimpleSFTPClient, TotalBytesSent);

		virtual int64_t get_TotalBytesReceived();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesReceived, TElSimpleSFTPClient, TotalBytesReceived);

#ifdef SB_WINDOWS
		virtual bool get_UsingIPv6();

		SB_DECLARE_PROPERTY_GET(bool, get_UsingIPv6, TElSimpleSFTPClient, UsingIPv6);
#endif

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
		virtual TElGSSBaseMechanism* get_GSSMechanism();

		virtual void set_GSSMechanism(TElGSSBaseMechanism &Value);

		virtual void set_GSSMechanism(TElGSSBaseMechanism *Value);

		SB_DECLARE_PROPERTY(TElGSSBaseMechanism*, get_GSSMechanism, set_GSSMechanism, TElSimpleSFTPClient, GSSMechanism);
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

		virtual void get_GSSHostName(std::string &OutResult);

		virtual void set_GSSHostName(const std::string &Value);

		virtual bool get_GSSDelegateCredentials();

		virtual void set_GSSDelegateCredentials(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GSSDelegateCredentials, set_GSSDelegateCredentials, TElSimpleSFTPClient, GSSDelegateCredentials);

#ifdef SB_USE_CLASS_TELSOCKET
		virtual TElSocket* get_InternalSocket();

		SB_DECLARE_PROPERTY_GET(TElSocket*, get_InternalSocket, TElSimpleSFTPClient, InternalSocket);
#endif /* SB_USE_CLASS_TELSOCKET */

		virtual int32_t get_SecondaryChannelExitStatus();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SecondaryChannelExitStatus, TElSimpleSFTPClient, SecondaryChannelExitStatus);

		virtual void get_SecondaryChannelExitSignal(std::string &OutResult);

		virtual void get_SecondaryChannelExitMessage(std::string &OutResult);

		virtual TSBSSHAuthOrder get_SSHAuthOrder();

		virtual void set_SSHAuthOrder(TSBSSHAuthOrder Value);

		SB_DECLARE_PROPERTY(TSBSSHAuthOrder, get_SSHAuthOrder, set_SSHAuthOrder, TElSimpleSFTPClient, SSHAuthOrder);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual bool get_AutoAdjustCiphers();

		virtual void set_AutoAdjustCiphers(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustCiphers, set_AutoAdjustCiphers, TElSimpleSFTPClient, AutoAdjustCiphers);

		virtual int32_t get_AuthenticationTypes();

		virtual void set_AuthenticationTypes(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthenticationTypes, set_AuthenticationTypes, TElSimpleSFTPClient, AuthenticationTypes);

		virtual bool get_ASCIIMode();

		virtual void set_ASCIIMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ASCIIMode, set_ASCIIMode, TElSimpleSFTPClient, ASCIIMode);

		virtual void get_ClientHostname(std::string &OutResult);

		virtual void set_ClientHostname(const std::string &Value);

		virtual void get_ClientUsername(std::string &OutResult);

		virtual void set_ClientUsername(const std::string &Value);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElSimpleSFTPClient, CompressionLevel);

		virtual bool get_ForceCompression();

		virtual void set_ForceCompression(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCompression, set_ForceCompression, TElSimpleSFTPClient, ForceCompression);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_KeyStorage();

		virtual void set_KeyStorage(TElSSHCustomKeyStorage &Value);

		virtual void set_KeyStorage(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_KeyStorage, set_KeyStorage, TElSimpleSFTPClient, KeyStorage);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSimpleSFTPClient, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElSimpleSFTPClient, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_CLASS_TELPORTKNOCK
		virtual TElPortKnock* get_PortKnock();

		virtual void set_PortKnock(TElPortKnock &Value);

		virtual void set_PortKnock(TElPortKnock *Value);

		SB_DECLARE_PROPERTY(TElPortKnock*, get_PortKnock, set_PortKnock, TElSimpleSFTPClient, PortKnock);
#endif /* SB_USE_CLASS_TELPORTKNOCK */

		virtual int32_t get_DefaultWindowSize();

		virtual void set_DefaultWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DefaultWindowSize, set_DefaultWindowSize, TElSimpleSFTPClient, DefaultWindowSize);

		virtual int32_t get_MinWindowSize();

		virtual void set_MinWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinWindowSize, set_MinWindowSize, TElSimpleSFTPClient, MinWindowSize);

		virtual int32_t get_MaxSSHPacketSize();

		virtual void set_MaxSSHPacketSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxSSHPacketSize, set_MaxSSHPacketSize, TElSimpleSFTPClient, MaxSSHPacketSize);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_TrustedKeys();

		virtual void set_TrustedKeys(TElSSHCustomKeyStorage &Value);

		virtual void set_TrustedKeys(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_TrustedKeys, set_TrustedKeys, TElSimpleSFTPClient, TrustedKeys);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

		virtual bool get_ObfuscateHandshake();

		virtual void set_ObfuscateHandshake(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ObfuscateHandshake, set_ObfuscateHandshake, TElSimpleSFTPClient, ObfuscateHandshake);

		virtual void get_ObfuscationPassword(std::string &OutResult);

		virtual void set_ObfuscationPassword(const std::string &Value);

		virtual bool get_CopyEmptyDirs();

		virtual void set_CopyEmptyDirs(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CopyEmptyDirs, set_CopyEmptyDirs, TElSimpleSFTPClient, CopyEmptyDirs);

		virtual bool get_DeleteFailedDownloads();

		virtual void set_DeleteFailedDownloads(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DeleteFailedDownloads, set_DeleteFailedDownloads, TElSimpleSFTPClient, DeleteFailedDownloads);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElSimpleSFTPClient, Port);

		virtual int32_t get_SftpBufferSize();

		virtual void set_SftpBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SftpBufferSize, set_SftpBufferSize, TElSimpleSFTPClient, SftpBufferSize);

		virtual int32_t get_SocketTimeout();

		virtual void set_SocketTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocketTimeout, set_SocketTimeout, TElSimpleSFTPClient, SocketTimeout);

		virtual TElSocksAuthentication get_SocksAuthentication();

		virtual void set_SocksAuthentication(TElSocksAuthentication Value);

		SB_DECLARE_PROPERTY(TElSocksAuthentication, get_SocksAuthentication, set_SocksAuthentication, TElSimpleSFTPClient, SocksAuthentication);

		virtual void get_SocksPassword(std::string &OutResult);

		virtual void set_SocksPassword(const std::string &Value);

		virtual int32_t get_SocksPort();

		virtual void set_SocksPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SocksPort, set_SocksPort, TElSimpleSFTPClient, SocksPort);

		virtual bool get_SocksResolveAddress();

		virtual void set_SocksResolveAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksResolveAddress, set_SocksResolveAddress, TElSimpleSFTPClient, SocksResolveAddress);

		virtual void get_SocksServer(std::string &OutResult);

		virtual void set_SocksServer(const std::string &Value);

		virtual void get_SocksUserCode(std::string &OutResult);

		virtual void set_SocksUserCode(const std::string &Value);

		virtual TElSocksVersion get_SocksVersion();

		virtual void set_SocksVersion(TElSocksVersion Value);

		SB_DECLARE_PROPERTY(TElSocksVersion, get_SocksVersion, set_SocksVersion, TElSimpleSFTPClient, SocksVersion);

		virtual void get_SoftwareName(std::string &OutResult);

		virtual void set_SoftwareName(const std::string &Value);

		virtual bool get_AutoAdjustTransferBlock();

		virtual void set_AutoAdjustTransferBlock(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustTransferBlock, set_AutoAdjustTransferBlock, TElSimpleSFTPClient, AutoAdjustTransferBlock);

		virtual bool get_UseInternalSocket();

		virtual void set_UseInternalSocket(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseInternalSocket, set_UseInternalSocket, TElSimpleSFTPClient, UseInternalSocket);

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

#ifdef SB_WINDOWS
		virtual bool get_SocksUseIPv6();

		virtual void set_SocksUseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SocksUseIPv6, set_SocksUseIPv6, TElSimpleSFTPClient, SocksUseIPv6);

		virtual bool get_UseIPv6();

		virtual void set_UseIPv6(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseIPv6, set_UseIPv6, TElSimpleSFTPClient, UseIPv6);
#endif

		virtual bool get_UseSocks();

		virtual void set_UseSocks(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSocks, set_UseSocks, TElSimpleSFTPClient, UseSocks);

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
		virtual TElDNSSettings* get_DNS();

		virtual void set_DNS(TElDNSSettings &Value);

		virtual void set_DNS(TElDNSSettings *Value);

		SB_DECLARE_PROPERTY(TElDNSSettings*, get_DNS, set_DNS, TElSimpleSFTPClient, DNS);
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

		virtual bool get_UseWebTunneling();

		virtual void set_UseWebTunneling(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseWebTunneling, set_UseWebTunneling, TElSimpleSFTPClient, UseWebTunneling);

		virtual TSBSftpVersions get_Versions();

		virtual void set_Versions(TSBSftpVersions Value);

		SB_DECLARE_PROPERTY(TSBSftpVersions, get_Versions, set_Versions, TElSimpleSFTPClient, Versions);

		virtual void get_WebTunnelAddress(std::string &OutResult);

		virtual void set_WebTunnelAddress(const std::string &Value);

		virtual TElWebTunnelAuthentication get_WebTunnelAuthentication();

		virtual void set_WebTunnelAuthentication(TElWebTunnelAuthentication Value);

		SB_DECLARE_PROPERTY(TElWebTunnelAuthentication, get_WebTunnelAuthentication, set_WebTunnelAuthentication, TElSimpleSFTPClient, WebTunnelAuthentication);

		virtual void get_LocalAddress(std::string &OutResult);

		virtual void set_LocalAddress(const std::string &Value);

		virtual int32_t get_LocalPort();

		virtual void set_LocalPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_LocalPort, set_LocalPort, TElSimpleSFTPClient, LocalPort);

		virtual int32_t get_PipelineLength();

		virtual void set_PipelineLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PipelineLength, set_PipelineLength, TElSimpleSFTPClient, PipelineLength);

		virtual int32_t get_DownloadBlockSize();

		virtual void set_DownloadBlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DownloadBlockSize, set_DownloadBlockSize, TElSimpleSFTPClient, DownloadBlockSize);

		virtual int32_t get_UploadBlockSize();

		virtual void set_UploadBlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_UploadBlockSize, set_UploadBlockSize, TElSimpleSFTPClient, UploadBlockSize);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSimpleSFTPClient, UseUTF8);

		virtual bool get_UseUTF8OnV3();

		virtual void set_UseUTF8OnV3(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8OnV3, set_UseUTF8OnV3, TElSimpleSFTPClient, UseUTF8OnV3);

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TElSimpleSFTPClient, NoCharacterEncoding);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		virtual void get_WebTunnelPassword(std::string &OutResult);

		virtual void set_WebTunnelPassword(const std::string &Value);

		virtual int32_t get_WebTunnelPort();

		virtual void set_WebTunnelPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_WebTunnelPort, set_WebTunnelPort, TElSimpleSFTPClient, WebTunnelPort);

		virtual void get_WebTunnelUserId(std::string &OutResult);

		virtual void set_WebTunnelUserId(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelRequestHeaders, TElSimpleSFTPClient, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelRequestHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelRequestHeaders, TElSimpleSFTPClient, WebTunnelRequestHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_WebTunnelResponseHeaders, TElSimpleSFTPClient, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_WebTunnelResponseHeaders();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_WebTunnelResponseHeaders, TElSimpleSFTPClient, WebTunnelResponseHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_WebTunnelResponseBody(std::string &OutResult);

		virtual TSBOperationErrorHandling get_OperationErrorHandling();

		virtual void set_OperationErrorHandling(TSBOperationErrorHandling Value);

		SB_DECLARE_PROPERTY(TSBOperationErrorHandling, get_OperationErrorHandling, set_OperationErrorHandling, TElSimpleSFTPClient, OperationErrorHandling);

		virtual bool get_RequestPasswordChange();

		virtual void set_RequestPasswordChange(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestPasswordChange, set_RequestPasswordChange, TElSimpleSFTPClient, RequestPasswordChange);

		virtual TSBSSHCertAuthMode get_CertAuthMode();

		virtual void set_CertAuthMode(TSBSSHCertAuthMode Value);

		SB_DECLARE_PROPERTY(TSBSSHCertAuthMode, get_CertAuthMode, set_CertAuthMode, TElSimpleSFTPClient, CertAuthMode);

		virtual int32_t get_AuthAttempts();

		virtual void set_AuthAttempts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthAttempts, set_AuthAttempts, TElSimpleSFTPClient, AuthAttempts);

		virtual int32_t get_IncomingSpeedLimit();

		virtual void set_IncomingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IncomingSpeedLimit, set_IncomingSpeedLimit, TElSimpleSFTPClient, IncomingSpeedLimit);

		virtual int32_t get_OutgoingSpeedLimit();

		virtual void set_OutgoingSpeedLimit(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OutgoingSpeedLimit, set_OutgoingSpeedLimit, TElSimpleSFTPClient, OutgoingSpeedLimit);

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
		virtual TElClientSocketBinding* get_SocketBinding();

		virtual void set_SocketBinding(TElClientSocketBinding &Value);

		virtual void set_SocketBinding(TElClientSocketBinding *Value);

		SB_DECLARE_PROPERTY(TElClientSocketBinding*, get_SocketBinding, set_SocketBinding, TElSimpleSFTPClient, SocketBinding);
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

		virtual int64_t get_KeepAlivePeriod();

		virtual void set_KeepAlivePeriod(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_KeepAlivePeriod, set_KeepAlivePeriod, TElSimpleSFTPClient, KeepAlivePeriod);

		virtual bool get_ThreadSafe();

		virtual void set_ThreadSafe(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ThreadSafe, set_ThreadSafe, TElSimpleSFTPClient, ThreadSafe);

		virtual bool get_AdjustFileTimes();

		virtual void set_AdjustFileTimes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AdjustFileTimes, set_AdjustFileTimes, TElSimpleSFTPClient, AdjustFileTimes);

		virtual bool get_PreserveExistingFileTimes();

		virtual void set_PreserveExistingFileTimes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveExistingFileTimes, set_PreserveExistingFileTimes, TElSimpleSFTPClient, PreserveExistingFileTimes);

		virtual bool get_UseTruncateFlagOnUpload();

		virtual void set_UseTruncateFlagOnUpload(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseTruncateFlagOnUpload, set_UseTruncateFlagOnUpload, TElSimpleSFTPClient, UseTruncateFlagOnUpload);

		virtual bool get_TreatZeroSizeAsUndefined();

		virtual void set_TreatZeroSizeAsUndefined(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TreatZeroSizeAsUndefined, set_TreatZeroSizeAsUndefined, TElSimpleSFTPClient, TreatZeroSizeAsUndefined);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_SFTPServerExecutableLocations();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_SFTPServerExecutableLocations, TElSimpleSFTPClient, SFTPServerExecutableLocations);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual int32_t get_CommandTimeout();

		virtual void set_CommandTimeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CommandTimeout, set_CommandTimeout, TElSimpleSFTPClient, CommandTimeout);

		virtual void get_OnAuthenticationFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationSuccess(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationSuccess(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnBanner(TSSHBannerEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBanner(TSSHBannerEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSSHCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSSHCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyValidate(TSSHKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyValidate(TSSHKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TSSHReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSSHReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnSend(TSSHSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSSHSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileOperation(TElSftpFileOperationEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileOperation(TElSftpFileOperationEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileOperationResult(TElSftpFileOperationResultEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileOperationResult(TElSftpFileOperationResultEvent pMethodValue, void * pDataValue);

		virtual void get_OnBlockTransferPrepared(TSBSftpBlockTransferPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBlockTransferPrepared(TSBSftpBlockTransferPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationStart(TSSHAuthenticationStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationStart(TSSHAuthenticationStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue);

		virtual void get_MessageLoop(TSBSftpMessageLoopEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_MessageLoop(TSBSftpMessageLoopEvent pMethodValue, void * pDataValue);

		virtual void get_OnTunnelOpenFailed(TSBSftpTunnelOpenFailedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTunnelOpenFailed(TSBSftpTunnelOpenFailedEvent pMethodValue, void * pDataValue);

		virtual void get_OnSecondaryChannelPrepared(TSBSftpSecondaryChannelEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSecondaryChannelPrepared(TSBSftpSecondaryChannelEvent pMethodValue, void * pDataValue);

		virtual void get_OnSecondaryChannelOpen(TSBSftpSecondaryChannelEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSecondaryChannelOpen(TSBSftpSecondaryChannelEvent pMethodValue, void * pDataValue);

		virtual void get_OnSecondaryChannelError(TSBSftpSecondaryChannelErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSecondaryChannelError(TSBSftpSecondaryChannelErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileNameChangeNeeded(TSBSftpFileNameChangeNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileNameChangeNeeded(TSBSftpFileNameChangeNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue);
#endif

		TElSimpleSFTPClient(TElSimpleSFTPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleSFTPClient(TComponent &AOwner);

		explicit TElSimpleSFTPClient(TComponent *AOwner);

		virtual ~TElSimpleSFTPClient();

};
#endif /* SB_USE_CLASS_TELSIMPLESFTPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSIMPLESFTP */
