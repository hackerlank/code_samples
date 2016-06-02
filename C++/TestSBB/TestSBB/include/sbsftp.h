#ifndef __INC_SBSFTP
#define __INC_SBSFTP

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsshclient.h"
#include "sbsshcommon.h"
#include "sbsshconstants.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbsharedresource.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbsftpcommon.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SResizeNotSupported 	"New file size must be greater or equal than its current size"
#define SB_SFTP_OPTIMAL_UPLOAD_BLOCK_SIZE 	32512
#define SB_SFTP_OPTIMAL_DOWNLOAD_BLOCK_SIZE 	2096896

typedef TElClassHandle TElSftpStreamHandle;

typedef TElSftpStreamHandle ElSftpStreamHandle;

typedef TElClassHandle TElSftpClientHandle;

typedef TElSftpClientHandle ElSftpClientHandle;

#ifdef SB_USE_CLASS_TELSFTPSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElSftpStream_Read(TElSftpStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStream_Write(TElSftpStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStream_Seek(TElSftpStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStream_get_Handle(TElSftpStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPSTREAM */

#ifdef SB_USE_CLASS_TELSFTPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_Read(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_Read_1(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ReadSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ReadSync_1(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_OpenStream(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename, TSBSftpFileOpenModesRaw Modes, TElSftpStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_Open(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_OpenSync(TElSftpClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CreateFile(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CreateFileSync(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_OpenFile(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename, TSBSftpFileOpenModesRaw Modes, TElSftpFileAttributesHandle Attributes, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_OpenFile_1(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename, TSBSftpFileOpenModesRaw Modes, TSBSftpFileOpenAccessRaw Access, TElSftpFileAttributesHandle Attributes, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_OpenFileSync(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename, TSBSftpFileOpenModesRaw Modes, TElSftpFileAttributesHandle Attributes, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_OpenFileSync_1(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename, TSBSftpFileOpenModesRaw Modes, TSBSftpFileOpenAccessRaw Access, TElSftpFileAttributesHandle Attributes, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_OpenDirectory(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_OpenDirectorySync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ReadDirectory(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ReadDirectorySync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RemoveFile(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RemoveFileSync(TElSftpClientHandle _Handle, const char * pcFilename, int32_t szFilename);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RemoveFiles(TElSftpClientHandle _Handle, TStringsHandle Filenames, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RemoveFilesSync(TElSftpClientHandle _Handle, TStringsHandle Filenames);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RenameFile(TElSftpClientHandle _Handle, const char * pcOldPath, int32_t szOldPath, const char * pcNewPath, int32_t szNewPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RenameFileSync(TElSftpClientHandle _Handle, const char * pcOldPath, int32_t szOldPath, const char * pcNewPath, int32_t szNewPath);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_MakeDirectory(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpFileAttributesHandle Attributes, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_MakeDirectorySync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpFileAttributesHandle Attributes);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RemoveDirectory(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RemoveDirectorySync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestAttributes(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t FollowSymLinks, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestAttributes_1(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestAttributesSync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t FollowSymLinks);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestAttributesSync_1(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_SetAttributes(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpFileAttributesHandle Attributes, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_SetAttributesSync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, TElSftpFileAttributesHandle Attributes);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_SetAttributesByHandle(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, TElSftpFileAttributesHandle Attributes, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_SetAttributesByHandleSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, TElSftpFileAttributesHandle Attributes);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ReadSymLink(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ReadSymLinkSync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CreateSymLink(TElSftpClientHandle _Handle, const char * pcLinkPath, int32_t szLinkPath, const char * pcTargetPath, int32_t szTargetPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CreateSymLinkSync(TElSftpClientHandle _Handle, const char * pcLinkPath, int32_t szLinkPath, const char * pcTargetPath, int32_t szTargetPath);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CreateHardLink(TElSftpClientHandle _Handle, const char * pcLinkPath, int32_t szLinkPath, const char * pcTargetPath, int32_t szTargetPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CreateHardLinkSync(TElSftpClientHandle _Handle, const char * pcLinkPath, int32_t szLinkPath, const char * pcTargetPath, int32_t szTargetPath);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestAbsolutePath(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestAbsolutePathSync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestAbsolutePathEx(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, TSBSftpRealpathControlRaw Control, TStringListHandle ComposePath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestAbsolutePathExSync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, TSBSftpRealpathControlRaw Control, TStringListHandle ComposePath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_Block(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccessRaw LockMask, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_BlockSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccessRaw LockMask);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_Unblock(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int64_t Length, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_UnblockSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int64_t Length);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CloseHandle(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CloseHandleSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_Write(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, void * Buffer, uint32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_WriteSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, void * Buffer, uint32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_FinalizeTextWrite(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_FinalizeTextWriteSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ExtensionCmd(TElSftpClientHandle _Handle, const char * pcExtension, int32_t szExtension, void * DataBuffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ExtensionCmd_1(TElSftpClientHandle _Handle, const char * pcExtension, int32_t szExtension, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ExtensionCmd_2(TElSftpClientHandle _Handle, const char * pcExtension, int32_t szExtension, const uint8_t pDataBuffer[], int32_t szDataBuffer, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ExtensionCmd_3(TElSftpClientHandle _Handle, const uint8_t pExtension[], int32_t szExtension, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ExtensionCmd_4(TElSftpClientHandle _Handle, const uint8_t pExtension[], int32_t szExtension, void * DataBuffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ExtensionCmd_5(TElSftpClientHandle _Handle, const uint8_t pExtension[], int32_t szExtension, const uint8_t pDataBuffer[], int32_t szDataBuffer, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ExtensionCmdSync(TElSftpClientHandle _Handle, const char * pcExtension, int32_t szExtension, void * DataBuffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_ExtensionCmdSync_1(TElSftpClientHandle _Handle, const char * pcExtension, int32_t szExtension);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_TextSeek(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t LineNumber, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_TextSeekSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t LineNumber);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_SendVendorID(TElSftpClientHandle _Handle, TElSftpVendorIDExtensionHandle VendorID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_SendVendorIDSync(TElSftpClientHandle _Handle, TElSftpVendorIDExtensionHandle VendorID);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestFileHash(TElSftpClientHandle _Handle, const char * pcFileName, int32_t szFileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestFileHashSync(TElSftpClientHandle _Handle, const char * pcFileName, int32_t szFileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestFileHashByHandle(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t StartOffset, int64_t Length, uint32_t BlockSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestFileHashByHandleSync(TElSftpClientHandle _Handle, const uint8_t pHandle[], int32_t szHandle, int64_t StartOffset, int64_t Length, uint32_t BlockSize);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_QueryAvailableSpace(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_QueryAvailableSpaceSync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_QueryHomeDirectory(TElSftpClientHandle _Handle, const char * pcUsername, int32_t szUsername, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_QueryHomeDirectorySync(TElSftpClientHandle _Handle, const char * pcUsername, int32_t szUsername);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_QueryStatVFS(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_QueryStatVFSSync(TElSftpClientHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CopyRemoteFile(TElSftpClientHandle _Handle, const char * pcSource, int32_t szSource, const char * pcDestination, int32_t szDestination, int8_t Overwrite, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CopyRemoteFileSync(TElSftpClientHandle _Handle, const char * pcSource, int32_t szSource, const char * pcDestination, int32_t szDestination, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CopyRemoteData(TElSftpClientHandle _Handle, const uint8_t pReadFrom[], int32_t szReadFrom, int64_t ReadFromOffset, const uint8_t pWriteTo[], int32_t szWriteTo, int64_t WriteToOffset, int64_t DataLength, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_CopyRemoteDataSync(TElSftpClientHandle _Handle, const uint8_t pReadFrom[], int32_t szReadFrom, int64_t ReadFromOffset, const uint8_t pWriteTo[], int32_t szWriteTo, int64_t WriteToOffset, int64_t DataLength);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestTempFolder(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_RequestTempFolderSync(TElSftpClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_MakeTempFolder(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_MakeTempFolderSync(TElSftpClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_Active(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_Version(TElSftpClientHandle _Handle, TSBSftpVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_SFTPExtCount(TElSftpClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_SFTPExt(TElSftpClientHandle _Handle, int32_t Index, TSBSftpExtendedAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_NewLineConvention(TElSftpClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_NewLineConvention(TElSftpClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_LocalNewLineConvention(TElSftpClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_LocalNewLineConvention(TElSftpClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_LastSyncComment(TElSftpClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_LastSyncError(TElSftpClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_LastReadCount(TElSftpClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_SBB3Compatible(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_SBB3Compatible(TElSftpClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_SynchronousMode(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_SynchronousMode(TElSftpClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_Tunnel(TElSftpClientHandle _Handle, TElCustomSSHTunnelHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_Tunnel(TElSftpClientHandle _Handle, TElCustomSSHTunnelHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_SftpBufferSize(TElSftpClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_SftpBufferSize(TElSftpClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_UseUTF8(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_UseUTF8(TElSftpClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_UseUTF8OnV3(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_UseUTF8OnV3(TElSftpClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_RemoteCharset(TElSftpClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_RemoteCharset(TElSftpClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_NoCharacterEncoding(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_NoCharacterEncoding(TElSftpClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_LocalCharset(TElSftpClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_LocalCharset(TElSftpClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_Versions(TElSftpClientHandle _Handle, TSBSftpVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_Versions(TElSftpClientHandle _Handle, TSBSftpVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_ExtendedProperties(TElSftpClientHandle _Handle, TElSftpExtendedPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_ExtendedProperties(TElSftpClientHandle _Handle, TElSftpExtendedPropertiesHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_UploadBlockSize(TElSftpClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_UploadBlockSize(TElSftpClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_DownloadBlockSize(TElSftpClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_DownloadBlockSize(TElSftpClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_PipelineLength(TElSftpClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_PipelineLength(TElSftpClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_AutoAdjustTransferBlock(TElSftpClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_AutoAdjustTransferBlock(TElSftpClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OperationErrorHandling(TElSftpClientHandle _Handle, TSBOperationErrorHandlingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OperationErrorHandling(TElSftpClientHandle _Handle, TSBOperationErrorHandlingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_MessageLoop(TElSftpClientHandle _Handle, TSBSftpMessageLoopEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_MessageLoop(TElSftpClientHandle _Handle, TSBSftpMessageLoopEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnOpenConnection(TElSftpClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnOpenConnection(TElSftpClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnCloseConnection(TElSftpClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnCloseConnection(TElSftpClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnOpenFile(TElSftpClientHandle _Handle, TSBSftpFileOpenEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnOpenFile(TElSftpClientHandle _Handle, TSBSftpFileOpenEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnError(TElSftpClientHandle _Handle, TSBSftpErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnError(TElSftpClientHandle _Handle, TSBSftpErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnSuccess(TElSftpClientHandle _Handle, TSBSftpSuccessEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnSuccess(TElSftpClientHandle _Handle, TSBSftpSuccessEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnDirectoryListing(TElSftpClientHandle _Handle, TSBSftpDirectoryListingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnDirectoryListing(TElSftpClientHandle _Handle, TSBSftpDirectoryListingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnFileAttributes(TElSftpClientHandle _Handle, TSBSftpFileAttributesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnFileAttributes(TElSftpClientHandle _Handle, TSBSftpFileAttributesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnData(TElSftpClientHandle _Handle, TSBSftpDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnData(TElSftpClientHandle _Handle, TSBSftpDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnAbsolutePath(TElSftpClientHandle _Handle, TSBSftpAbsolutePathEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnAbsolutePath(TElSftpClientHandle _Handle, TSBSftpAbsolutePathEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnBlockTransferPrepared(TElSftpClientHandle _Handle, TSBSftpBlockTransferPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnBlockTransferPrepared(TElSftpClientHandle _Handle, TSBSftpBlockTransferPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnExtendedReply(TElSftpClientHandle _Handle, TSBSftpDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnExtendedReply(TElSftpClientHandle _Handle, TSBSftpDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnVersionSelect(TElSftpClientHandle _Handle, TSBSftpVersionSelectEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnVersionSelect(TElSftpClientHandle _Handle, TSBSftpVersionSelectEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnFileHash(TElSftpClientHandle _Handle, TSBSftpFileHashEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnFileHash(TElSftpClientHandle _Handle, TSBSftpFileHashEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnAvailableSpace(TElSftpClientHandle _Handle, TSBSftpAvailableSpaceEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnAvailableSpace(TElSftpClientHandle _Handle, TSBSftpAvailableSpaceEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnName(TElSftpClientHandle _Handle, TSBSftpNameEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnName(TElSftpClientHandle _Handle, TSBSftpNameEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnTransferCompleted(TElSftpClientHandle _Handle, TSBSftpTransferCompletedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnTransferCompleted(TElSftpClientHandle _Handle, TSBSftpTransferCompletedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnProgress(TElSftpClientHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnProgress(TElSftpClientHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_get_OnStatVFS(TElSftpClientHandle _Handle, TSBSftpStatvfsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_set_OnStatVFS(TElSftpClientHandle _Handle, TSBSftpStatvfsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpClient_Create(TComponentHandle AOwner, TElSftpClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSftpStream;
typedef TElSftpStream ElSftpStream;
class TElSftpClient;
typedef TElSftpClient ElSftpClient;

#ifdef SB_USE_CLASS_TELSFTPSTREAM
class TElSftpStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElSftpStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual void get_Handle(std::vector<uint8_t> &OutResult);

		TElSftpStream(TElSftpStreamHandle handle, TElOwnHandle ownHandle);

		TElSftpStream();

};
#endif /* SB_USE_CLASS_TELSFTPSTREAM */

#ifdef SB_USE_CLASS_TELSFTPCLIENT
class TElSftpClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSftpClient)
#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
		TSBSftpExtendedAttribute* _Inst_SFTPExt;
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
		TElCustomSSHTunnel* _Inst_Tunnel;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */
#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
		TElSftpExtendedProperties* _Inst_ExtendedProperties;
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */

		void initInstances();

	public:
		int32_t Read(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Size);

		bool Read(const std::vector<uint8_t> &Handle, int64_t Offset, int32_t Size);

		int32_t ReadSync(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Size);

		int32_t ReadSync(const std::vector<uint8_t> &Handle, int64_t Offset, int32_t Size);

#ifdef SB_USE_CLASS_TELSFTPSTREAM
		TElSftpStreamHandle OpenStream(const std::string &Filename, TSBSftpFileOpenModes Modes);
#endif /* SB_USE_CLASS_TELSFTPSTREAM */

		bool Open();

		void OpenSync();

		bool CreateFile(const std::string &Filename);

		void CreateFileSync(const std::string &Filename, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		bool OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes &Attributes);

		bool OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		bool OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes &Attributes);

		bool OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void OpenFileSync(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes &Attributes, std::vector<uint8_t> &OutResult);

		void OpenFileSync(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes *Attributes, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void OpenFileSync(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes &Attributes, std::vector<uint8_t> &OutResult);

		void OpenFileSync(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes *Attributes, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

		bool OpenDirectory(const std::string &Path);

		void OpenDirectorySync(const std::string &Path, std::vector<uint8_t> &OutResult);

		bool ReadDirectory(const std::vector<uint8_t> &Handle);

		bool ReadDirectorySync(const std::vector<uint8_t> &Handle);

		bool RemoveFile(const std::string &Filename);

		void RemoveFileSync(const std::string &Filename);

#ifdef SB_USE_CLASS_TSTRINGS
		bool RemoveFiles(TStrings &Filenames);

		bool RemoveFiles(TStrings *Filenames);
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
		void RemoveFilesSync(TStrings &Filenames);

		void RemoveFilesSync(TStrings *Filenames);
#endif /* SB_USE_CLASS_TSTRINGS */

		bool RenameFile(const std::string &OldPath, const std::string &NewPath);

		void RenameFileSync(const std::string &OldPath, const std::string &NewPath);

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		bool MakeDirectory(const std::string &Path, TElSftpFileAttributes &Attributes);

		bool MakeDirectory(const std::string &Path, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void MakeDirectorySync(const std::string &Path, TElSftpFileAttributes &Attributes);

		void MakeDirectorySync(const std::string &Path, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

		bool RemoveDirectory(const std::string &Path);

		void RemoveDirectorySync(const std::string &Path);

		bool RequestAttributes(const std::string &Path, bool FollowSymLinks);

		bool RequestAttributes(const std::vector<uint8_t> &Handle);

		void RequestAttributesSync(const std::string &Path, bool FollowSymLinks);

		void RequestAttributesSync(const std::vector<uint8_t> &Handle);

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		bool SetAttributes(const std::string &Path, TElSftpFileAttributes &Attributes);

		bool SetAttributes(const std::string &Path, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void SetAttributesSync(const std::string &Path, TElSftpFileAttributes &Attributes);

		void SetAttributesSync(const std::string &Path, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		bool SetAttributesByHandle(const std::vector<uint8_t> &Handle, TElSftpFileAttributes &Attributes);

		bool SetAttributesByHandle(const std::vector<uint8_t> &Handle, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		void SetAttributesByHandleSync(const std::vector<uint8_t> &Handle, TElSftpFileAttributes &Attributes);

		void SetAttributesByHandleSync(const std::vector<uint8_t> &Handle, TElSftpFileAttributes *Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

		bool ReadSymLink(const std::string &Path);

		void ReadSymLinkSync(const std::string &Path);

		bool CreateSymLink(const std::string &LinkPath, const std::string &TargetPath);

		void CreateSymLinkSync(const std::string &LinkPath, const std::string &TargetPath);

		bool CreateHardLink(const std::string &LinkPath, const std::string &TargetPath);

		void CreateHardLinkSync(const std::string &LinkPath, const std::string &TargetPath);

		bool RequestAbsolutePath(const std::string &Path);

		void RequestAbsolutePathSync(const std::string &Path, std::string &OutResult);

#ifdef SB_USE_CLASS_TSTRINGLIST
		bool RequestAbsolutePathEx(const std::string &Path, TSBSftpRealpathControl Control, TStringList &ComposePath);

		bool RequestAbsolutePathEx(const std::string &Path, TSBSftpRealpathControl Control, TStringList *ComposePath);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		void RequestAbsolutePathExSync(const std::string &Path, TSBSftpRealpathControl Control, TStringList &ComposePath, std::string &OutResult);

		void RequestAbsolutePathExSync(const std::string &Path, TSBSftpRealpathControl Control, TStringList *ComposePath, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		bool Block(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccess LockMask);

		void BlockSync(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccess LockMask);

		bool Unblock(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length);

		void UnblockSync(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length);

		bool CloseHandle(const std::vector<uint8_t> &Handle);

		void CloseHandleSync(const std::vector<uint8_t> &Handle);

		bool Write(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, uint32_t Size);

		void WriteSync(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, uint32_t Size);

		bool FinalizeTextWrite(const std::vector<uint8_t> &Handle);

		void FinalizeTextWriteSync(const std::vector<uint8_t> &Handle);

		bool ExtensionCmd(const std::string &Extension, void * DataBuffer, int32_t Size);

		bool ExtensionCmd(const std::string &Extension);

		bool ExtensionCmd(const std::string &Extension, const std::vector<uint8_t> &DataBuffer);

		bool ExtensionCmd(const std::vector<uint8_t> &Extension);

		bool ExtensionCmd(const std::vector<uint8_t> &Extension, void * DataBuffer, int32_t Size);

		bool ExtensionCmd(const std::vector<uint8_t> &Extension, const std::vector<uint8_t> &DataBuffer);

		void ExtensionCmdSync(const std::string &Extension, void * DataBuffer, int32_t Size);

		void ExtensionCmdSync(const std::string &Extension);

		bool TextSeek(const std::vector<uint8_t> &Handle, int64_t LineNumber);

		void TextSeekSync(const std::vector<uint8_t> &Handle, int64_t LineNumber);

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
		bool SendVendorID(TElSftpVendorIDExtension &VendorID);

		bool SendVendorID(TElSftpVendorIDExtension *VendorID);
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
		void SendVendorIDSync(TElSftpVendorIDExtension &VendorID);

		void SendVendorIDSync(TElSftpVendorIDExtension *VendorID);
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

		bool RequestFileHash(const std::string &FileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize);

		void RequestFileHashSync(const std::string &FileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize);

		bool RequestFileHashByHandle(const std::vector<uint8_t> &Handle, int64_t StartOffset, int64_t Length, uint32_t BlockSize);

		void RequestFileHashByHandleSync(const std::vector<uint8_t> &Handle, int64_t StartOffset, int64_t Length, uint32_t BlockSize);

		bool QueryAvailableSpace(const std::string &Path);

		void QueryAvailableSpaceSync(const std::string &Path);

		bool QueryHomeDirectory(const std::string &Username);

		void QueryHomeDirectorySync(const std::string &Username);

		bool QueryStatVFS(const std::string &Path);

		void QueryStatVFSSync(const std::string &Path);

		bool CopyRemoteFile(const std::string &Source, const std::string &Destination, bool Overwrite);

		void CopyRemoteFileSync(const std::string &Source, const std::string &Destination, bool Overwrite);

		bool CopyRemoteData(const std::vector<uint8_t> &ReadFrom, int64_t ReadFromOffset, const std::vector<uint8_t> &WriteTo, int64_t WriteToOffset, int64_t DataLength);

		void CopyRemoteDataSync(const std::vector<uint8_t> &ReadFrom, int64_t ReadFromOffset, const std::vector<uint8_t> &WriteTo, int64_t WriteToOffset, int64_t DataLength);

		bool RequestTempFolder();

		void RequestTempFolderSync();

		bool MakeTempFolder();

		void MakeTempFolderSync();

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSftpClient, Active);

		virtual TSBSftpVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSBSftpVersion, get_Version, TElSftpClient, Version);

		virtual int32_t get_SFTPExtCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SFTPExtCount, TElSftpClient, SFTPExtCount);

#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
		virtual TSBSftpExtendedAttribute* get_SFTPExt(int32_t Index);
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */

		virtual void get_NewLineConvention(std::vector<uint8_t> &OutResult);

		virtual void set_NewLineConvention(const std::vector<uint8_t> &Value);

		virtual void get_LocalNewLineConvention(std::vector<uint8_t> &OutResult);

		virtual void set_LocalNewLineConvention(const std::vector<uint8_t> &Value);

		virtual void get_LastSyncComment(std::string &OutResult);

		virtual int32_t get_LastSyncError();

		SB_DECLARE_PROPERTY_GET(int32_t, get_LastSyncError, TElSftpClient, LastSyncError);

		virtual int32_t get_LastReadCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_LastReadCount, TElSftpClient, LastReadCount);

		virtual bool get_SBB3Compatible();

		virtual void set_SBB3Compatible(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SBB3Compatible, set_SBB3Compatible, TElSftpClient, SBB3Compatible);

		virtual bool get_SynchronousMode();

		virtual void set_SynchronousMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SynchronousMode, set_SynchronousMode, TElSftpClient, SynchronousMode);

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
		virtual TElCustomSSHTunnel* get_Tunnel();

		virtual void set_Tunnel(TElCustomSSHTunnel &Value);

		virtual void set_Tunnel(TElCustomSSHTunnel *Value);

		SB_DECLARE_PROPERTY(TElCustomSSHTunnel*, get_Tunnel, set_Tunnel, TElSftpClient, Tunnel);
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

		virtual int32_t get_SftpBufferSize();

		virtual void set_SftpBufferSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SftpBufferSize, set_SftpBufferSize, TElSftpClient, SftpBufferSize);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSftpClient, UseUTF8);

		virtual bool get_UseUTF8OnV3();

		virtual void set_UseUTF8OnV3(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8OnV3, set_UseUTF8OnV3, TElSftpClient, UseUTF8OnV3);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TElSftpClient, NoCharacterEncoding);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

		virtual TSBSftpVersions get_Versions();

		virtual void set_Versions(TSBSftpVersions Value);

		SB_DECLARE_PROPERTY(TSBSftpVersions, get_Versions, set_Versions, TElSftpClient, Versions);

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
		virtual TElSftpExtendedProperties* get_ExtendedProperties();

		virtual void set_ExtendedProperties(TElSftpExtendedProperties &Value);

		virtual void set_ExtendedProperties(TElSftpExtendedProperties *Value);

		SB_DECLARE_PROPERTY(TElSftpExtendedProperties*, get_ExtendedProperties, set_ExtendedProperties, TElSftpClient, ExtendedProperties);
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */

		virtual int32_t get_UploadBlockSize();

		virtual void set_UploadBlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_UploadBlockSize, set_UploadBlockSize, TElSftpClient, UploadBlockSize);

		virtual int32_t get_DownloadBlockSize();

		virtual void set_DownloadBlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DownloadBlockSize, set_DownloadBlockSize, TElSftpClient, DownloadBlockSize);

		virtual int32_t get_PipelineLength();

		virtual void set_PipelineLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PipelineLength, set_PipelineLength, TElSftpClient, PipelineLength);

		virtual bool get_AutoAdjustTransferBlock();

		virtual void set_AutoAdjustTransferBlock(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustTransferBlock, set_AutoAdjustTransferBlock, TElSftpClient, AutoAdjustTransferBlock);

		virtual TSBOperationErrorHandling get_OperationErrorHandling();

		virtual void set_OperationErrorHandling(TSBOperationErrorHandling Value);

		SB_DECLARE_PROPERTY(TSBOperationErrorHandling, get_OperationErrorHandling, set_OperationErrorHandling, TElSftpClient, OperationErrorHandling);

		virtual void get_MessageLoop(TSBSftpMessageLoopEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_MessageLoop(TSBSftpMessageLoopEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenConnection(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenConnection(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenFile(TSBSftpFileOpenEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenFile(TSBSftpFileOpenEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBSftpErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBSftpErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnSuccess(TSBSftpSuccessEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSuccess(TSBSftpSuccessEvent pMethodValue, void * pDataValue);

		virtual void get_OnDirectoryListing(TSBSftpDirectoryListingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDirectoryListing(TSBSftpDirectoryListingEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileAttributes(TSBSftpFileAttributesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileAttributes(TSBSftpFileAttributesEvent pMethodValue, void * pDataValue);

		virtual void get_OnData(TSBSftpDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnData(TSBSftpDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnAbsolutePath(TSBSftpAbsolutePathEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAbsolutePath(TSBSftpAbsolutePathEvent pMethodValue, void * pDataValue);

		virtual void get_OnBlockTransferPrepared(TSBSftpBlockTransferPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBlockTransferPrepared(TSBSftpBlockTransferPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtendedReply(TSBSftpDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtendedReply(TSBSftpDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnVersionSelect(TSBSftpVersionSelectEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVersionSelect(TSBSftpVersionSelectEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileHash(TSBSftpFileHashEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileHash(TSBSftpFileHashEvent pMethodValue, void * pDataValue);

		virtual void get_OnAvailableSpace(TSBSftpAvailableSpaceEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAvailableSpace(TSBSftpAvailableSpaceEvent pMethodValue, void * pDataValue);

		virtual void get_OnName(TSBSftpNameEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnName(TSBSftpNameEvent pMethodValue, void * pDataValue);

		virtual void get_OnTransferCompleted(TSBSftpTransferCompletedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTransferCompleted(TSBSftpTransferCompletedEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnStatVFS(TSBSftpStatvfsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStatVFS(TSBSftpStatvfsEvent pMethodValue, void * pDataValue);

		TElSftpClient(TElSftpClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSftpClient(TComponent &AOwner);

		explicit TElSftpClient(TComponent *AOwner);

		virtual ~TElSftpClient();

};
#endif /* SB_USE_CLASS_TELSFTPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSFTP */

