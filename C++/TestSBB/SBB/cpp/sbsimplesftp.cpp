#include "sbsimplesftp.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSIMPLESFTPCLIENT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleSFTPClient::ExtensionCmd(const std::string &Extension, void * DataBuffer, int32_t Size, TStream &ResponseStream)
{
	SBCheckError(TElSimpleSFTPClient_ExtensionCmd(_Handle, Extension.data(), (int32_t)Extension.length(), DataBuffer, Size, ResponseStream.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::ExtensionCmd(const std::string &Extension, void * DataBuffer, int32_t Size, TStream *ResponseStream)
{
	SBCheckError(TElSimpleSFTPClient_ExtensionCmd(_Handle, Extension.data(), (int32_t)Extension.length(), DataBuffer, Size, (ResponseStream != NULL) ? ResponseStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleSFTPClient::ExtensionCmd(const std::string &Extension, TStream &ResponseStream)
{
	SBCheckError(TElSimpleSFTPClient_ExtensionCmd_1(_Handle, Extension.data(), (int32_t)Extension.length(), ResponseStream.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::ExtensionCmd(const std::string &Extension, TStream *ResponseStream)
{
	SBCheckError(TElSimpleSFTPClient_ExtensionCmd_1(_Handle, Extension.data(), (int32_t)Extension.length(), (ResponseStream != NULL) ? ResponseStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElSimpleSFTPClient::Block(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccess LockMask)
{
	SBCheckError(TElSimpleSFTPClient_Block(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Length, (TSBSftpFileOpenAccessRaw)LockMask));
}

SB_INLINE void TElSimpleSFTPClient::Unblock(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length)
{
	SBCheckError(TElSimpleSFTPClient_Unblock(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Length));
}

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
SB_INLINE void TElSimpleSFTPClient::SendVendorID(TElSftpVendorIDExtension &VendorID)
{
	SBCheckError(TElSimpleSFTPClient_SendVendorID(_Handle, VendorID.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::SendVendorID(TElSftpVendorIDExtension *VendorID)
{
	SBCheckError(TElSimpleSFTPClient_SendVendorID(_Handle, (VendorID != NULL) ? VendorID->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEREPLY
SB_INLINE void TElSimpleSFTPClient::RequestFileHash(const std::string &FileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReply &FileHash)
{
	SBCheckError(TElSimpleSFTPClient_RequestFileHash(_Handle, FileName.data(), (int32_t)FileName.length(), StartOffset, Length, BlockSize, FileHash.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::RequestFileHash(const std::string &FileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReply *FileHash)
{
	SBCheckError(TElSimpleSFTPClient_RequestFileHash(_Handle, FileName.data(), (int32_t)FileName.length(), StartOffset, Length, BlockSize, (FileHash != NULL) ? FileHash->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEREPLY */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEREPLY
SB_INLINE void TElSimpleSFTPClient::RequestFileHashByHandle(const std::vector<uint8_t> &Handle, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReply &FileHash)
{
	SBCheckError(TElSimpleSFTPClient_RequestFileHashByHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), StartOffset, Length, BlockSize, FileHash.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::RequestFileHashByHandle(const std::vector<uint8_t> &Handle, int64_t StartOffset, int64_t Length, uint32_t BlockSize, TElSftpCheckFileReply *FileHash)
{
	SBCheckError(TElSimpleSFTPClient_RequestFileHashByHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), StartOffset, Length, BlockSize, (FileHash != NULL) ? FileHash->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY
SB_INLINE void TElSimpleSFTPClient::QueryAvailableSpace(const std::string &Path, TElSftpSpaceAvailableReply &AvailSpace)
{
	SBCheckError(TElSimpleSFTPClient_QueryAvailableSpace(_Handle, Path.data(), (int32_t)Path.length(), AvailSpace.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::QueryAvailableSpace(const std::string &Path, TElSftpSpaceAvailableReply *AvailSpace)
{
	SBCheckError(TElSimpleSFTPClient_QueryAvailableSpace(_Handle, Path.data(), (int32_t)Path.length(), (AvailSpace != NULL) ? AvailSpace->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSTATVFSREPLY
SB_INLINE void TElSimpleSFTPClient::QueryStatVFS(const std::string &Path, TElSftpStatVFSReply &StatVFS)
{
	SBCheckError(TElSimpleSFTPClient_QueryStatVFS(_Handle, Path.data(), (int32_t)Path.length(), StatVFS.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::QueryStatVFS(const std::string &Path, TElSftpStatVFSReply *StatVFS)
{
	SBCheckError(TElSimpleSFTPClient_QueryStatVFS(_Handle, Path.data(), (int32_t)Path.length(), (StatVFS != NULL) ? StatVFS->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPSTATVFSREPLY */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
SB_INLINE void TElSimpleSFTPClient::QueryHomeDirectory(const std::string &Username, TElSftpFileInfo &HomeDir)
{
	SBCheckError(TElSimpleSFTPClient_QueryHomeDirectory(_Handle, Username.data(), (int32_t)Username.length(), HomeDir.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::QueryHomeDirectory(const std::string &Username, TElSftpFileInfo *HomeDir)
{
	SBCheckError(TElSimpleSFTPClient_QueryHomeDirectory(_Handle, Username.data(), (int32_t)Username.length(), (HomeDir != NULL) ? HomeDir->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

SB_INLINE void TElSimpleSFTPClient::CopyRemoteFile(const std::string &Source, const std::string &Destination, bool Overwrite)
{
	SBCheckError(TElSimpleSFTPClient_CopyRemoteFile(_Handle, Source.data(), (int32_t)Source.length(), Destination.data(), (int32_t)Destination.length(), (int8_t)Overwrite));
}

SB_INLINE void TElSimpleSFTPClient::CopyRemoteData(const std::vector<uint8_t> &ReadFrom, int64_t ReadFromOffset, const std::vector<uint8_t> &WriteTo, int64_t WriteToOffset, int64_t DataLength)
{
	SBCheckError(TElSimpleSFTPClient_CopyRemoteData(_Handle, SB_STD_VECTOR_FRONT_ADR(ReadFrom), (int32_t)ReadFrom.size(), ReadFromOffset, SB_STD_VECTOR_FRONT_ADR(WriteTo), (int32_t)WriteTo.size(), WriteToOffset, DataLength));
}

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
SB_INLINE void TElSimpleSFTPClient::RequestTempFolder(TElSftpFileInfo &TempFolder)
{
	SBCheckError(TElSimpleSFTPClient_RequestTempFolder(_Handle, TempFolder.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::RequestTempFolder(TElSftpFileInfo *TempFolder)
{
	SBCheckError(TElSimpleSFTPClient_RequestTempFolder(_Handle, (TempFolder != NULL) ? TempFolder->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
SB_INLINE void TElSimpleSFTPClient::MakeTempFolder(TElSftpFileInfo &TempFolder)
{
	SBCheckError(TElSimpleSFTPClient_MakeTempFolder(_Handle, TempFolder.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::MakeTempFolder(TElSftpFileInfo *TempFolder)
{
	SBCheckError(TElSimpleSFTPClient_MakeTempFolder(_Handle, (TempFolder != NULL) ? TempFolder->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

bool TElSimpleSFTPClient::FileExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_FileExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElSimpleSFTPClient::GetFileSize(const std::string &Path)
{
	int64_t OutResult;
	SBCheckError(TElSimpleSFTPClient_GetFileSize(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

bool TElSimpleSFTPClient::DirExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_DirExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::Interrupt()
{
	SBCheckError(TElSimpleSFTPClient_Interrupt(_Handle));
}

SB_INLINE void TElSimpleSFTPClient::Close(bool Silent)
{
	SBCheckError(TElSimpleSFTPClient_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElSimpleSFTPClient::CloseHandle(const std::vector<uint8_t> &Handle)
{
	SBCheckError(TElSimpleSFTPClient_CloseHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size()));
}

void TElSimpleSFTPClient::CreateFile(const std::string &Filename, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_CreateFile(_Handle, Filename.data(), (int32_t)Filename.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1261218306, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::CreateSymLink(const std::string &LinkPath, const std::string &TargetPath)
{
	SBCheckError(TElSimpleSFTPClient_CreateSymLink(_Handle, LinkPath.data(), (int32_t)LinkPath.length(), TargetPath.data(), (int32_t)TargetPath.length()));
}

SB_INLINE void TElSimpleSFTPClient::CreateHardLink(const std::string &LinkPath, const std::string &TargetPath)
{
	SBCheckError(TElSimpleSFTPClient_CreateHardLink(_Handle, LinkPath.data(), (int32_t)LinkPath.length(), TargetPath.data(), (int32_t)TargetPath.length()));
}

SB_INLINE void TElSimpleSFTPClient::DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_DownloadFiles(_Handle, RemotePath.data(), (int32_t)RemotePath.length(), RemoteMask.data(), (int32_t)RemoteMask.length(), LocalPath.data(), (int32_t)LocalPath.length(), (TSBFileTransferModeRaw)Mode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive));
}

SB_INLINE void TElSimpleSFTPClient::DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive, bool DeleteFiles)
{
	SBCheckError(TElSimpleSFTPClient_DownloadFiles_1(_Handle, RemotePath.data(), (int32_t)RemotePath.length(), RemoteMask.data(), (int32_t)RemoteMask.length(), LocalPath.data(), (int32_t)LocalPath.length(), (TSBFileTransferModeRaw)Mode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive, (int8_t)DeleteFiles));
}

SB_INLINE void TElSimpleSFTPClient::DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, TSBFileCopyMode CopyMode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_DownloadFiles_2(_Handle, RemotePath.data(), (int32_t)RemotePath.length(), RemoteMask.data(), (int32_t)RemoteMask.length(), LocalPath.data(), (int32_t)LocalPath.length(), (TSBFileTransferModeRaw)Mode, (TSBFileCopyModeRaw)CopyMode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive));
}

SB_INLINE void TElSimpleSFTPClient::UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_UploadFiles(_Handle, LocalPath.data(), (int32_t)LocalPath.length(), LocalMask.data(), (int32_t)LocalMask.length(), RemotePath.data(), (int32_t)RemotePath.length(), (TSBFileTransferModeRaw)Mode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive));
}

SB_INLINE void TElSimpleSFTPClient::UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive, bool DeleteFiles)
{
	SBCheckError(TElSimpleSFTPClient_UploadFiles_1(_Handle, LocalPath.data(), (int32_t)LocalPath.length(), LocalMask.data(), (int32_t)LocalMask.length(), RemotePath.data(), (int32_t)RemotePath.length(), (TSBFileTransferModeRaw)Mode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive, (int8_t)DeleteFiles));
}

SB_INLINE void TElSimpleSFTPClient::UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, TSBFileCopyMode CopyMode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_UploadFiles_2(_Handle, LocalPath.data(), (int32_t)LocalPath.length(), LocalMask.data(), (int32_t)LocalMask.length(), RemotePath.data(), (int32_t)RemotePath.length(), (TSBFileTransferModeRaw)Mode, (TSBFileCopyModeRaw)CopyMode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive));
}

SB_INLINE void TElSimpleSFTPClient::DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName)
{
	SBCheckError(TElSimpleSFTPClient_DownloadFile(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalFileName.data(), (int32_t)LocalFileName.length()));
}

SB_INLINE void TElSimpleSFTPClient::DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, bool SuppressAdditionalOperations)
{
	SBCheckError(TElSimpleSFTPClient_DownloadFile_1(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalFileName.data(), (int32_t)LocalFileName.length(), (int8_t)SuppressAdditionalOperations));
}

SB_INLINE void TElSimpleSFTPClient::DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, TSBFileTransferMode Mode)
{
	SBCheckError(TElSimpleSFTPClient_DownloadFile_2(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalFileName.data(), (int32_t)LocalFileName.length(), (TSBFileTransferModeRaw)Mode));
}

SB_INLINE void TElSimpleSFTPClient::DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleSFTPClient_DownloadFile_3(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalFileName.data(), (int32_t)LocalFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

SB_INLINE void TElSimpleSFTPClient::UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName)
{
	SBCheckError(TElSimpleSFTPClient_UploadFile(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), RemoteFileName.data(), (int32_t)RemoteFileName.length()));
}

SB_INLINE void TElSimpleSFTPClient::UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, bool SuppressAdditionalOperations)
{
	SBCheckError(TElSimpleSFTPClient_UploadFile_1(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (int8_t)SuppressAdditionalOperations));
}

SB_INLINE void TElSimpleSFTPClient::UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, TSBFileTransferMode Mode)
{
	SBCheckError(TElSimpleSFTPClient_UploadFile_2(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode));
}

SB_INLINE void TElSimpleSFTPClient::UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleSFTPClient_UploadFile_3(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleSFTPClient::DownloadStream(const std::string &RemoteFileName, TStream &LocalStream, TSBFileTransferMode Mode)
{
	SBCheckError(TElSimpleSFTPClient_DownloadStream(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalStream.getHandle(), (TSBFileTransferModeRaw)Mode));
}

SB_INLINE void TElSimpleSFTPClient::DownloadStream(const std::string &RemoteFileName, TStream *LocalStream, TSBFileTransferMode Mode)
{
	SBCheckError(TElSimpleSFTPClient_DownloadStream(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, (TSBFileTransferModeRaw)Mode));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleSFTPClient::DownloadStream(const std::string &RemoteFileName, TStream &LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleSFTPClient_DownloadStream_1(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalStream.getHandle(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

SB_INLINE void TElSimpleSFTPClient::DownloadStream(const std::string &RemoteFileName, TStream *LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleSFTPClient_DownloadStream_1(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, (TSBFileTransferModeRaw)Mode, RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleSFTPClient::DownloadStream(const std::string &RemoteFileName, TStream &LocalStream, bool SuppressAdditionalOperations)
{
	SBCheckError(TElSimpleSFTPClient_DownloadStream_2(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalStream.getHandle(), (int8_t)SuppressAdditionalOperations));
}

SB_INLINE void TElSimpleSFTPClient::DownloadStream(const std::string &RemoteFileName, TStream *LocalStream, bool SuppressAdditionalOperations)
{
	SBCheckError(TElSimpleSFTPClient_DownloadStream_2(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, (int8_t)SuppressAdditionalOperations));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleSFTPClient::UploadStream(TStream &LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode)
{
	SBCheckError(TElSimpleSFTPClient_UploadStream(_Handle, LocalStream.getHandle(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode));
}

SB_INLINE void TElSimpleSFTPClient::UploadStream(TStream *LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode)
{
	SBCheckError(TElSimpleSFTPClient_UploadStream(_Handle, (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleSFTPClient::UploadStream(TStream &LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleSFTPClient_UploadStream_1(_Handle, LocalStream.getHandle(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

SB_INLINE void TElSimpleSFTPClient::UploadStream(TStream *LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleSFTPClient_UploadStream_1(_Handle, (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleSFTPClient::UploadStream(TStream &LocalStream, const std::string &RemoteFileName, bool SuppressAdditionalOperations)
{
	SBCheckError(TElSimpleSFTPClient_UploadStream_2(_Handle, LocalStream.getHandle(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (int8_t)SuppressAdditionalOperations));
}

SB_INLINE void TElSimpleSFTPClient::UploadStream(TStream *LocalStream, const std::string &RemoteFileName, bool SuppressAdditionalOperations)
{
	SBCheckError(TElSimpleSFTPClient_UploadStream_2(_Handle, (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, RemoteFileName.data(), (int32_t)RemoteFileName.length(), (int8_t)SuppressAdditionalOperations));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_INLINE void TElSimpleSFTPClient::MakeDirectory(const std::string &Path, TElSftpFileAttributes &Attributes)
{
	SBCheckError(TElSimpleSFTPClient_MakeDirectory(_Handle, Path.data(), (int32_t)Path.length(), Attributes.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::MakeDirectory(const std::string &Path, TElSftpFileAttributes *Attributes)
{
	SBCheckError(TElSimpleSFTPClient_MakeDirectory(_Handle, Path.data(), (int32_t)Path.length(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

SB_INLINE void TElSimpleSFTPClient::CreateDirectoryPath(const std::string &Path)
{
	SBCheckError(TElSimpleSFTPClient_CreateDirectoryPath(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElSimpleSFTPClient::Open()
{
	SBCheckError(TElSimpleSFTPClient_Open(_Handle));
}

void TElSimpleSFTPClient::OpenDirectory(const std::string &Path, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_OpenDirectory(_Handle, Path.data(), (int32_t)Path.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1506188162, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
void TElSimpleSFTPClient::OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes &Attributes, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_OpenFile(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, Attributes.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1316307606, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes *Attributes, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_OpenFile(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1316307606, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
void TElSimpleSFTPClient::OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes &Attributes, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_OpenFile_1(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (TSBSftpFileOpenAccessRaw)Access, Attributes.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2032426615, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes *Attributes, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_OpenFile_1(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (TSBSftpFileOpenAccessRaw)Access, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2032426615, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPSTREAM
SB_INLINE TElSftpStreamHandle TElSimpleSFTPClient::OpenStream(const std::string &Filename, TSBSftpFileOpenModes Modes)
{
	TElSftpStreamHandle OutResult;
	SBCheckError(TElSimpleSFTPClient_OpenStream(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSFTPSTREAM */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleSFTPClient::ReadDirectory(const std::vector<uint8_t> &Handle, TList &Listing)
{
	SBCheckError(TElSimpleSFTPClient_ReadDirectory(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Listing.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::ReadDirectory(const std::vector<uint8_t> &Handle, TList *Listing)
{
	SBCheckError(TElSimpleSFTPClient_ReadDirectory(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleSFTPClient::ReadDirectory(const std::vector<uint8_t> &Handle, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories)
{
	SBCheckError(TElSimpleSFTPClient_ReadDirectory_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Listing.getHandle(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories));
}

SB_INLINE void TElSimpleSFTPClient::ReadDirectory(const std::vector<uint8_t> &Handle, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories)
{
	SBCheckError(TElSimpleSFTPClient_ReadDirectory_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE, Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleSFTPClient::ReadDirectory(const std::vector<uint8_t> &Handle, TList &Listing, const std::string &Mask, const std::string &DirectoryMask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories)
{
	SBCheckError(TElSimpleSFTPClient_ReadDirectory_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Listing.getHandle(), Mask.data(), (int32_t)Mask.length(), DirectoryMask.data(), (int32_t)DirectoryMask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories));
}

SB_INLINE void TElSimpleSFTPClient::ReadDirectory(const std::vector<uint8_t> &Handle, TList *Listing, const std::string &Mask, const std::string &DirectoryMask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories)
{
	SBCheckError(TElSimpleSFTPClient_ReadDirectory_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE, Mask.data(), (int32_t)Mask.length(), DirectoryMask.data(), (int32_t)DirectoryMask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleSFTPClient::ReadDirectory(const std::vector<uint8_t> &Handle, TList &Listing, const std::string &Mask, const std::string &DirectoryMask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive, const std::string &Path)
{
	SBCheckError(TElSimpleSFTPClient_ReadDirectory_3(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Listing.getHandle(), Mask.data(), (int32_t)Mask.length(), DirectoryMask.data(), (int32_t)DirectoryMask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories, (int8_t)Recursive, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElSimpleSFTPClient::ReadDirectory(const std::vector<uint8_t> &Handle, TList *Listing, const std::string &Mask, const std::string &DirectoryMask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive, const std::string &Path)
{
	SBCheckError(TElSimpleSFTPClient_ReadDirectory_3(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE, Mask.data(), (int32_t)Mask.length(), DirectoryMask.data(), (int32_t)DirectoryMask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories, (int8_t)Recursive, Path.data(), (int32_t)Path.length()));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleSFTPClient::ListDirectory(const std::string &Path, TList &Listing)
{
	SBCheckError(TElSimpleSFTPClient_ListDirectory(_Handle, Path.data(), (int32_t)Path.length(), Listing.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::ListDirectory(const std::string &Path, TList *Listing)
{
	SBCheckError(TElSimpleSFTPClient_ListDirectory(_Handle, Path.data(), (int32_t)Path.length(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleSFTPClient::ListDirectory(const std::string &Path, TList &Listing, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_ListDirectory_1(_Handle, Path.data(), (int32_t)Path.length(), Listing.getHandle(), (int8_t)Recursive));
}

SB_INLINE void TElSimpleSFTPClient::ListDirectory(const std::string &Path, TList *Listing, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_ListDirectory_1(_Handle, Path.data(), (int32_t)Path.length(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE, (int8_t)Recursive));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleSFTPClient::ListDirectory(const std::string &Path, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories)
{
	SBCheckError(TElSimpleSFTPClient_ListDirectory_2(_Handle, Path.data(), (int32_t)Path.length(), Listing.getHandle(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories));
}

SB_INLINE void TElSimpleSFTPClient::ListDirectory(const std::string &Path, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories)
{
	SBCheckError(TElSimpleSFTPClient_ListDirectory_2(_Handle, Path.data(), (int32_t)Path.length(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE, Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleSFTPClient::ListDirectory(const std::string &Path, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_ListDirectory_3(_Handle, Path.data(), (int32_t)Path.length(), Listing.getHandle(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories, (int8_t)Recursive));
}

SB_INLINE void TElSimpleSFTPClient::ListDirectory(const std::string &Path, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_ListDirectory_3(_Handle, Path.data(), (int32_t)Path.length(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE, Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories, (int8_t)Recursive));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
SB_INLINE void TElSimpleSFTPClient::ReadSymLink(const std::string &Path, TElSftpFileInfo &Info)
{
	SBCheckError(TElSimpleSFTPClient_ReadSymLink(_Handle, Path.data(), (int32_t)Path.length(), Info.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::ReadSymLink(const std::string &Path, TElSftpFileInfo *Info)
{
	SBCheckError(TElSimpleSFTPClient_ReadSymLink(_Handle, Path.data(), (int32_t)Path.length(), (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

SB_INLINE int32_t TElSimpleSFTPClient::Read(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Length)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Buffer, Length, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::RemoveDirectory(const std::string &Path)
{
	SBCheckError(TElSimpleSFTPClient_RemoveDirectory(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElSimpleSFTPClient::RemoveDirectory(const std::string &Path, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_RemoveDirectory_1(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)Recursive));
}

SB_INLINE void TElSimpleSFTPClient::RemoveFile(const std::string &Filename)
{
	SBCheckError(TElSimpleSFTPClient_RemoveFile(_Handle, Filename.data(), (int32_t)Filename.length()));
}

SB_INLINE void TElSimpleSFTPClient::RemoveFiles(const std::string &Path, const std::string &Mask, bool CaseSensitive, bool Recursive)
{
	SBCheckError(TElSimpleSFTPClient_RemoveFiles(_Handle, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)Recursive));
}

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElSimpleSFTPClient::RemoveFiles(TStrings &List)
{
	SBCheckError(TElSimpleSFTPClient_RemoveFiles_1(_Handle, List.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::RemoveFiles(TStrings *List)
{
	SBCheckError(TElSimpleSFTPClient_RemoveFiles_1(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGS */

SB_INLINE void TElSimpleSFTPClient::RenameFile(const std::string &OldPath, const std::string &NewPath)
{
	SBCheckError(TElSimpleSFTPClient_RenameFile(_Handle, OldPath.data(), (int32_t)OldPath.length(), NewPath.data(), (int32_t)NewPath.length()));
}

void TElSimpleSFTPClient::RequestAbsolutePath(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_RequestAbsolutePath(_Handle, Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(678078979, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTRINGLIST
void TElSimpleSFTPClient::RequestAbsolutePathEx(const std::string &Path, TSBSftpRealpathControl Control, TStringList &ComposePath, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_RequestAbsolutePathEx(_Handle, Path.data(), (int32_t)Path.length(), (TSBSftpRealpathControlRaw)Control, ComposePath.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1900426575, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::RequestAbsolutePathEx(const std::string &Path, TSBSftpRealpathControl Control, TStringList *ComposePath, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_RequestAbsolutePathEx(_Handle, Path.data(), (int32_t)Path.length(), (TSBSftpRealpathControlRaw)Control, (ComposePath != NULL) ? ComposePath->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1900426575, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_INLINE void TElSimpleSFTPClient::RequestAttributes(const std::string &Path, bool FollowSymLinks, TElSftpFileAttributes &Attributes)
{
	SBCheckError(TElSimpleSFTPClient_RequestAttributes(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)FollowSymLinks, Attributes.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::RequestAttributes(const std::string &Path, bool FollowSymLinks, TElSftpFileAttributes *Attributes)
{
	SBCheckError(TElSimpleSFTPClient_RequestAttributes(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)FollowSymLinks, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_INLINE void TElSimpleSFTPClient::RequestAttributes(const std::vector<uint8_t> &Handle, TElSftpFileAttributes &Attributes)
{
	SBCheckError(TElSimpleSFTPClient_RequestAttributes_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Attributes.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::RequestAttributes(const std::vector<uint8_t> &Handle, TElSftpFileAttributes *Attributes)
{
	SBCheckError(TElSimpleSFTPClient_RequestAttributes_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_INLINE void TElSimpleSFTPClient::SetAttributes(const std::string &Path, TElSftpFileAttributes &Attributes)
{
	SBCheckError(TElSimpleSFTPClient_SetAttributes(_Handle, Path.data(), (int32_t)Path.length(), Attributes.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::SetAttributes(const std::string &Path, TElSftpFileAttributes *Attributes)
{
	SBCheckError(TElSimpleSFTPClient_SetAttributes(_Handle, Path.data(), (int32_t)Path.length(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_INLINE void TElSimpleSFTPClient::SetAttributesByHandle(const std::vector<uint8_t> &Handle, TElSftpFileAttributes &Attributes)
{
	SBCheckError(TElSimpleSFTPClient_SetAttributesByHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Attributes.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::SetAttributesByHandle(const std::vector<uint8_t> &Handle, TElSftpFileAttributes *Attributes)
{
	SBCheckError(TElSimpleSFTPClient_SetAttributesByHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

SB_INLINE void TElSimpleSFTPClient::Write(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Size)
{
	SBCheckError(TElSimpleSFTPClient_Write(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Buffer, Size));
}

SB_INLINE void TElSimpleSFTPClient::FinalizeTextWrite(const std::vector<uint8_t> &Handle)
{
	SBCheckError(TElSimpleSFTPClient_FinalizeTextWrite(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size()));
}

SB_INLINE void TElSimpleSFTPClient::TextSeek(const std::vector<uint8_t> &Handle, int64_t LineNumber)
{
	SBCheckError(TElSimpleSFTPClient_TextSeek(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), LineNumber));
}

SB_INLINE void TElSimpleSFTPClient::RenegotiateCiphers()
{
	SBCheckError(TElSimpleSFTPClient_RenegotiateCiphers(_Handle));
}

void TElSimpleSFTPClient::ExecuteSSHCommand(const std::string &Command, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_ExecuteSSHCommand(_Handle, Command.data(), (int32_t)Command.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2020387454, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::ExecuteSSHCommand(const std::string &Command, bool RedirectStdErr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_ExecuteSSHCommand_1(_Handle, Command.data(), (int32_t)Command.length(), (int8_t)RedirectStdErr, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1793604571, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::ExecuteSSHCommand(const std::string &Command, std::vector<uint8_t> &StdErrData, std::vector<uint8_t> &OutResult)
{
	int32_t szStdErrData = (int32_t)StdErrData.size();
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_ExecuteSSHCommand_2(_Handle, Command.data(), (int32_t)Command.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(StdErrData), &szStdErrData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		StdErrData.resize(szStdErrData);
		SBCheckError(SBGetLastReturnBuffer(-1437980405, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(StdErrData), &szStdErrData));
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1437980405, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	StdErrData.resize(szStdErrData);
	OutResult.resize(szOutResult);
}

bool TElSimpleSFTPClient::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_EncryptionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_EncryptionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_EncryptionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_EncryptionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_KexAlgorithms(int8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_KexAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_KexAlgorithms(int8_t Index, bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_KexAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_MacAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_MacAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_MacAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_MacAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_PublicKeyAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_PublicKeyAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_PublicKeyAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_PublicKeyAlgorithms(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_EncryptionAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_EncryptionAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_EncryptionAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_EncryptionAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_CompressionAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_CompressionAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_CompressionAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_CompressionAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_MacAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_MacAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_MacAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_MacAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_KexAlgorithmPriorities(int8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_KexAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_KexAlgorithmPriorities(int8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_KexAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_PublicKeyAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_PublicKeyAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_PublicKeyAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_PublicKeyAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_AuthTypePriorities(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_AuthTypePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_AuthTypePriorities(int32_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_AuthTypePriorities(_Handle, Index, Value));
}

bool TElSimpleSFTPClient::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElSimpleSFTPClient::get_CompressionAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_CompressionAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSFTPClient::get_CompressionAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_CompressionAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSFTPClient::get_EncryptionAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_EncryptionAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSFTPClient::get_EncryptionAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_EncryptionAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int8_t TElSimpleSFTPClient::get_KexAlgorithm()
{
	int8_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_KexAlgorithm(_Handle, &OutResult));
	return OutResult;
}

void TElSimpleSFTPClient::get_LastSyncComment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_LastSyncComment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1390759797, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSimpleSFTPClient::get_LastSyncError()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_LastSyncError(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSFTPClient::get_MacAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_MacAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSFTPClient::get_MacAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_MacAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
TElSocketSettings* TElSimpleSFTPClient::get_SocketSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_SocketSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketSettings)
		this->_Inst_SocketSettings = new TElSocketSettings(hOutResult, ohFalse);
	else
		this->_Inst_SocketSettings->updateHandle(hOutResult);
	return this->_Inst_SocketSettings;
}
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

void TElSimpleSFTPClient::get_NewLineConvention(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_get_NewLineConvention(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(489816535, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_NewLineConvention(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_NewLineConvention(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSimpleSFTPClient::get_LocalNewLineConvention(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSFTPClient_get_LocalNewLineConvention(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1968379760, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_LocalNewLineConvention(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_LocalNewLineConvention(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint8_t TElSimpleSFTPClient::get_PublicKeyAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

void TElSimpleSFTPClient::get_ServerCloseReason(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_ServerCloseReason(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1203946763, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::get_ServerSoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_ServerSoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1836244913, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::get_SFTPExt(std::vector<TSBSftpExtendedAttributeHandle> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElSimpleSFTPClient_get_SFTPExt(_Handle, (TSBSftpExtendedAttributeHandle *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-479223378, 1, (TSBSftpExtendedAttributeHandle *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElSimpleSFTPClient::set_SFTPExt(const std::vector<TSBSftpExtendedAttributeHandle> &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SFTPExt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBSftpVersion TElSimpleSFTPClient::get_Version()
{
	TSBSftpVersionRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_Version(_Handle, &OutResultRaw));
	return (TSBSftpVersion)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
TElSftpExtendedProperties* TElSimpleSFTPClient::get_ExtendedProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_ExtendedProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtendedProperties)
		this->_Inst_ExtendedProperties = new TElSftpExtendedProperties(hOutResult, ohFalse);
	else
		this->_Inst_ExtendedProperties->updateHandle(hOutResult);
	return this->_Inst_ExtendedProperties;
}
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */

void TElSimpleSFTPClient::get_KbdIntName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_KbdIntName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1232390112, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::get_KbdIntInstruction(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_KbdIntInstruction(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1071225217, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELSSHKEY
TElSSHKey* TElSimpleSFTPClient::get_ServerKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_ServerKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerKey)
		this->_Inst_ServerKey = new TElSSHKey(hOutResult, ohFalse);
	else
		this->_Inst_ServerKey->updateHandle(hOutResult);
	return this->_Inst_ServerKey;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

SB_INLINE int32_t TElSimpleSFTPClient::get_ProxyResult()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_ProxyResult(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSimpleSFTPClient::get_TotalBytesSent()
{
	int64_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_TotalBytesSent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSimpleSFTPClient::get_TotalBytesReceived()
{
	int64_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_TotalBytesReceived(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
bool TElSimpleSFTPClient::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
TElGSSBaseMechanism* TElSimpleSFTPClient::get_GSSMechanism()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_GSSMechanism(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GSSMechanism)
		this->_Inst_GSSMechanism = new TElGSSBaseMechanism(hOutResult, ohFalse);
	else
		this->_Inst_GSSMechanism->updateHandle(hOutResult);
	return this->_Inst_GSSMechanism;
}

SB_INLINE void TElSimpleSFTPClient::set_GSSMechanism(TElGSSBaseMechanism &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_GSSMechanism(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::set_GSSMechanism(TElGSSBaseMechanism *Value)
{
	SBCheckError(TElSimpleSFTPClient_set_GSSMechanism(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

void TElSimpleSFTPClient::get_GSSHostName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_GSSHostName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1688256332, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_GSSHostName(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_GSSHostName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleSFTPClient::get_GSSDelegateCredentials()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_GSSDelegateCredentials(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_GSSDelegateCredentials(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_GSSDelegateCredentials(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleSFTPClient::get_InternalSocket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_InternalSocket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InternalSocket)
		this->_Inst_InternalSocket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_InternalSocket->updateHandle(hOutResult);
	return this->_Inst_InternalSocket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

SB_INLINE int32_t TElSimpleSFTPClient::get_SecondaryChannelExitStatus()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_SecondaryChannelExitStatus(_Handle, &OutResult));
	return OutResult;
}

void TElSimpleSFTPClient::get_SecondaryChannelExitSignal(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_SecondaryChannelExitSignal(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-816981197, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSFTPClient::get_SecondaryChannelExitMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_SecondaryChannelExitMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(369359161, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBSSHAuthOrder TElSimpleSFTPClient::get_SSHAuthOrder()
{
	TSBSSHAuthOrderRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_SSHAuthOrder(_Handle, &OutResultRaw));
	return (TSBSSHAuthOrder)OutResultRaw;
}

SB_INLINE void TElSimpleSFTPClient::set_SSHAuthOrder(TSBSSHAuthOrder Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SSHAuthOrder(_Handle, (TSBSSHAuthOrderRaw)Value));
}

void TElSimpleSFTPClient::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1215472177, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_Address(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleSFTPClient::get_AutoAdjustCiphers()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_AutoAdjustCiphers(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_AutoAdjustCiphers(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_AutoAdjustCiphers(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_AuthenticationTypes()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_AuthenticationTypes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_AuthenticationTypes(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_AuthenticationTypes(_Handle, Value));
}

bool TElSimpleSFTPClient::get_ASCIIMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_ASCIIMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_ASCIIMode(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_ASCIIMode(_Handle, (int8_t)Value));
}

void TElSimpleSFTPClient::get_ClientHostname(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_ClientHostname(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(650267726, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_ClientHostname(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_ClientHostname(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSFTPClient::get_ClientUsername(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_ClientUsername(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1003325992, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_ClientUsername(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_ClientUsername(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_CompressionLevel(_Handle, Value));
}

bool TElSimpleSFTPClient::get_ForceCompression()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_ForceCompression(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_ForceCompression(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_ForceCompression(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSimpleSFTPClient::get_KeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_KeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyStorage)
		this->_Inst_KeyStorage = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_KeyStorage->updateHandle(hOutResult);
	return this->_Inst_KeyStorage;
}

SB_INLINE void TElSimpleSFTPClient::set_KeyStorage(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_KeyStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::set_KeyStorage(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSimpleSFTPClient_set_KeyStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSimpleSFTPClient::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSimpleSFTPClient::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSimpleSFTPClient_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElSimpleSFTPClient::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElSimpleSFTPClient::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElSimpleSFTPClient_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_CLASS_TELPORTKNOCK
TElPortKnock* TElSimpleSFTPClient::get_PortKnock()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_PortKnock(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PortKnock)
		this->_Inst_PortKnock = new TElPortKnock(hOutResult, ohFalse);
	else
		this->_Inst_PortKnock->updateHandle(hOutResult);
	return this->_Inst_PortKnock;
}

SB_INLINE void TElSimpleSFTPClient::set_PortKnock(TElPortKnock &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_PortKnock(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::set_PortKnock(TElPortKnock *Value)
{
	SBCheckError(TElSimpleSFTPClient_set_PortKnock(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPORTKNOCK */

SB_INLINE int32_t TElSimpleSFTPClient::get_DefaultWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_DefaultWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_DefaultWindowSize(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_DefaultWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_MinWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_MinWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_MinWindowSize(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_MinWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_MaxSSHPacketSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_MaxSSHPacketSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_MaxSSHPacketSize(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_MaxSSHPacketSize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSimpleSFTPClient::get_TrustedKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_TrustedKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedKeys)
		this->_Inst_TrustedKeys = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_TrustedKeys->updateHandle(hOutResult);
	return this->_Inst_TrustedKeys;
}

SB_INLINE void TElSimpleSFTPClient::set_TrustedKeys(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_TrustedKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::set_TrustedKeys(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSimpleSFTPClient_set_TrustedKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

bool TElSimpleSFTPClient::get_ObfuscateHandshake()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_ObfuscateHandshake(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_ObfuscateHandshake(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_ObfuscateHandshake(_Handle, (int8_t)Value));
}

void TElSimpleSFTPClient::get_ObfuscationPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_ObfuscationPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-664817071, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_ObfuscationPassword(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_ObfuscationPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleSFTPClient::get_CopyEmptyDirs()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_CopyEmptyDirs(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_CopyEmptyDirs(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_CopyEmptyDirs(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_DeleteFailedDownloads()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_DeleteFailedDownloads(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_DeleteFailedDownloads(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_DeleteFailedDownloads(_Handle, (int8_t)Value));
}

void TElSimpleSFTPClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1981679357, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_Password(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_Port(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_Port(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_SftpBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_SftpBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_SftpBufferSize(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SftpBufferSize(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_SocketTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_SocketTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_SocketTimeout(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocketTimeout(_Handle, Value));
}

TElSocksAuthentication TElSimpleSFTPClient::get_SocksAuthentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_SocksAuthentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElSimpleSFTPClient::set_SocksAuthentication(TElSocksAuthentication Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocksAuthentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

void TElSimpleSFTPClient::get_SocksPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_SocksPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(558216578, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_SocksPassword(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocksPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_SocksPort()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_SocksPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_SocksPort(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocksPort(_Handle, Value));
}

bool TElSimpleSFTPClient::get_SocksResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_SocksResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_SocksResolveAddress(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocksResolveAddress(_Handle, (int8_t)Value));
}

void TElSimpleSFTPClient::get_SocksServer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_SocksServer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1128562505, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_SocksServer(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocksServer(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSFTPClient::get_SocksUserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_SocksUserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1708987520, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_SocksUserCode(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocksUserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElSimpleSFTPClient::get_SocksVersion()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_SocksVersion(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElSimpleSFTPClient::set_SocksVersion(TElSocksVersion Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocksVersion(_Handle, (TElSocksVersionRaw)Value));
}

void TElSimpleSFTPClient::get_SoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_SoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(799202116, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_SoftwareName(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SoftwareName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleSFTPClient::get_AutoAdjustTransferBlock()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_AutoAdjustTransferBlock(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_AutoAdjustTransferBlock(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_AutoAdjustTransferBlock(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_UseInternalSocket()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_UseInternalSocket(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_UseInternalSocket(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_UseInternalSocket(_Handle, (int8_t)Value));
}

void TElSimpleSFTPClient::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1149090209, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_Username(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
bool TElSimpleSFTPClient::get_SocksUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_SocksUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_SocksUseIPv6(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocksUseIPv6(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_UseIPv6(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSimpleSFTPClient::get_UseSocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_UseSocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_UseSocks(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_UseSocks(_Handle, (int8_t)Value));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElSimpleSFTPClient::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElSimpleSFTPClient::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElSimpleSFTPClient_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

bool TElSimpleSFTPClient::get_UseWebTunneling()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_UseWebTunneling(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_UseWebTunneling(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_UseWebTunneling(_Handle, (int8_t)Value));
}

TSBSftpVersions TElSimpleSFTPClient::get_Versions()
{
	TSBSftpVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_Versions(_Handle, &OutResultRaw));
	return (TSBSftpVersions)OutResultRaw;
}

SB_INLINE void TElSimpleSFTPClient::set_Versions(TSBSftpVersions Value)
{
	SBCheckError(TElSimpleSFTPClient_set_Versions(_Handle, (TSBSftpVersionsRaw)Value));
}

void TElSimpleSFTPClient::get_WebTunnelAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_WebTunnelAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-717076631, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_WebTunnelAddress(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_WebTunnelAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebTunnelAuthentication TElSimpleSFTPClient::get_WebTunnelAuthentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_WebTunnelAuthentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElSimpleSFTPClient::set_WebTunnelAuthentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElSimpleSFTPClient_set_WebTunnelAuthentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

void TElSimpleSFTPClient::get_LocalAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_LocalAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-894247889, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_LocalAddress(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_LocalAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_LocalPort()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_LocalPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_LocalPort(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_LocalPort(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_PipelineLength()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_PipelineLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_PipelineLength(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_PipelineLength(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_DownloadBlockSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_DownloadBlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_DownloadBlockSize(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_DownloadBlockSize(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_UploadBlockSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_UploadBlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_UploadBlockSize(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_UploadBlockSize(_Handle, Value));
}

bool TElSimpleSFTPClient::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_UseUTF8(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_UseUTF8OnV3()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_UseUTF8OnV3(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_UseUTF8OnV3(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_UseUTF8OnV3(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

void TElSimpleSFTPClient::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2019065275, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSFTPClient::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-168812783, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSFTPClient::get_WebTunnelPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_WebTunnelPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1237962554, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_WebTunnelPassword(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_WebTunnelPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_WebTunnelPort()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_WebTunnelPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_WebTunnelPort(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_WebTunnelPort(_Handle, Value));
}

void TElSimpleSFTPClient::get_WebTunnelUserId(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_WebTunnelUserId(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1793003330, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPClient::set_WebTunnelUserId(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_WebTunnelUserId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleSFTPClient::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelRequestHeaders)
		this->_Inst_WebTunnelRequestHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelRequestHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleSFTPClient::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelRequestHeaders)
		this->_Inst_WebTunnelRequestHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelRequestHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleSFTPClient::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelResponseHeaders)
		this->_Inst_WebTunnelResponseHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelResponseHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelResponseHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleSFTPClient::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelResponseHeaders)
		this->_Inst_WebTunnelResponseHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelResponseHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelResponseHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSimpleSFTPClient::get_WebTunnelResponseBody(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPClient_get_WebTunnelResponseBody(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-788976132, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBOperationErrorHandling TElSimpleSFTPClient::get_OperationErrorHandling()
{
	TSBOperationErrorHandlingRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_OperationErrorHandling(_Handle, &OutResultRaw));
	return (TSBOperationErrorHandling)OutResultRaw;
}

SB_INLINE void TElSimpleSFTPClient::set_OperationErrorHandling(TSBOperationErrorHandling Value)
{
	SBCheckError(TElSimpleSFTPClient_set_OperationErrorHandling(_Handle, (TSBOperationErrorHandlingRaw)Value));
}

bool TElSimpleSFTPClient::get_RequestPasswordChange()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_RequestPasswordChange(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_RequestPasswordChange(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_RequestPasswordChange(_Handle, (int8_t)Value));
}

TSBSSHCertAuthMode TElSimpleSFTPClient::get_CertAuthMode()
{
	TSBSSHCertAuthModeRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_CertAuthMode(_Handle, &OutResultRaw));
	return (TSBSSHCertAuthMode)OutResultRaw;
}

SB_INLINE void TElSimpleSFTPClient::set_CertAuthMode(TSBSSHCertAuthMode Value)
{
	SBCheckError(TElSimpleSFTPClient_set_CertAuthMode(_Handle, (TSBSSHCertAuthModeRaw)Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_AuthAttempts()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_AuthAttempts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_AuthAttempts(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_AuthAttempts(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSFTPClient::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_OutgoingSpeedLimit(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElSimpleSFTPClient::get_SocketBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_SocketBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketBinding)
		this->_Inst_SocketBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_SocketBinding->updateHandle(hOutResult);
	return this->_Inst_SocketBinding;
}

SB_INLINE void TElSimpleSFTPClient::set_SocketBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocketBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPClient::set_SocketBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElSimpleSFTPClient_set_SocketBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

SB_INLINE int64_t TElSimpleSFTPClient::get_KeepAlivePeriod()
{
	int64_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_KeepAlivePeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_KeepAlivePeriod(int64_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_KeepAlivePeriod(_Handle, Value));
}

bool TElSimpleSFTPClient::get_ThreadSafe()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_ThreadSafe(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_ThreadSafe(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_ThreadSafe(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_AdjustFileTimes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_AdjustFileTimes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_AdjustFileTimes(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_AdjustFileTimes(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_PreserveExistingFileTimes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_PreserveExistingFileTimes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_PreserveExistingFileTimes(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_PreserveExistingFileTimes(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_UseTruncateFlagOnUpload()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_UseTruncateFlagOnUpload(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_UseTruncateFlagOnUpload(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_UseTruncateFlagOnUpload(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPClient::get_TreatZeroSizeAsUndefined()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPClient_get_TreatZeroSizeAsUndefined(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPClient::set_TreatZeroSizeAsUndefined(bool Value)
{
	SBCheckError(TElSimpleSFTPClient_set_TreatZeroSizeAsUndefined(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleSFTPClient::get_SFTPServerExecutableLocations()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPClient_get_SFTPServerExecutableLocations(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SFTPServerExecutableLocations)
		this->_Inst_SFTPServerExecutableLocations = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_SFTPServerExecutableLocations->updateHandle(hOutResult);
	return this->_Inst_SFTPServerExecutableLocations;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE int32_t TElSimpleSFTPClient::get_CommandTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSFTPClient_get_CommandTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSFTPClient::set_CommandTimeout(int32_t Value)
{
	SBCheckError(TElSimpleSFTPClient_set_CommandTimeout(_Handle, Value));
}

SB_INLINE void TElSimpleSFTPClient::get_OnAuthenticationFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnAuthenticationFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnAuthenticationFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnAuthenticationFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnAuthenticationKeyboard(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnAuthenticationKeyboard(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnAuthenticationSuccess(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnAuthenticationSuccess(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnAuthenticationSuccess(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnAuthenticationSuccess(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnBanner(TSSHBannerEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnBanner(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnBanner(TSSHBannerEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnBanner(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnCloseConnection(TSSHCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnCloseConnection(TSSHCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnKeyValidate(TSSHKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnKeyValidate(TSSHKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnReceive(TSSHReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnReceive(TSSHReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnSend(TSSHSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnSend(TSSHSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnFileOperation(TElSftpFileOperationEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnFileOperation(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnFileOperation(TElSftpFileOperationEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnFileOperation(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnFileOperationResult(TElSftpFileOperationResultEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnFileOperationResult(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnFileOperationResult(TElSftpFileOperationResultEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnFileOperationResult(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnBlockTransferPrepared(TSBSftpBlockTransferPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnBlockTransferPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnBlockTransferPrepared(TSBSftpBlockTransferPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnBlockTransferPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnPasswordChangeRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnPasswordChangeRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnPrivateKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnPrivateKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnAuthenticationStart(TSSHAuthenticationStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnAuthenticationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnAuthenticationStart(TSSHAuthenticationStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnAuthenticationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnAuthenticationAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnAuthenticationAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_MessageLoop(TSBSftpMessageLoopEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_MessageLoop(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_MessageLoop(TSBSftpMessageLoopEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_MessageLoop(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnTunnelOpenFailed(TSBSftpTunnelOpenFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnTunnelOpenFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnTunnelOpenFailed(TSBSftpTunnelOpenFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnTunnelOpenFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnSecondaryChannelPrepared(TSBSftpSecondaryChannelEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnSecondaryChannelPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnSecondaryChannelPrepared(TSBSftpSecondaryChannelEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnSecondaryChannelPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnSecondaryChannelOpen(TSBSftpSecondaryChannelEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnSecondaryChannelOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnSecondaryChannelOpen(TSBSftpSecondaryChannelEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnSecondaryChannelOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnSecondaryChannelError(TSBSftpSecondaryChannelErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnSecondaryChannelError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnSecondaryChannelError(TSBSftpSecondaryChannelErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnSecondaryChannelError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnFileNameChangeNeeded(TSBSftpFileNameChangeNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnFileNameChangeNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnFileNameChangeNeeded(TSBSftpFileNameChangeNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnFileNameChangeNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnKexInitReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnKexInitReceived(_Handle, pMethodValue, pDataValue));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElSimpleSFTPClient::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPClient::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPClient_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPClient::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPClient_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

void TElSimpleSFTPClient::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
	this->_Inst_ExtendedProperties = NULL;
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */
#ifdef SB_USE_CLASS_TELSSHKEY
	this->_Inst_ServerKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
	this->_Inst_GSSMechanism = NULL;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_InternalSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELPORTKNOCK
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_TrustedKeys = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_SocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_SFTPServerExecutableLocations = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElSimpleSFTPClient::TElSimpleSFTPClient(TElSimpleSFTPClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSimpleSFTPClient::TElSimpleSFTPClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSFTPClient_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleSFTPClient::TElSimpleSFTPClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSFTPClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimpleSFTPClient::~TElSimpleSFTPClient()
{
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	delete this->_Inst_SocketSettings;
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
	delete this->_Inst_ExtendedProperties;
	this->_Inst_ExtendedProperties = NULL;
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */
#ifdef SB_USE_CLASS_TELSSHKEY
	delete this->_Inst_ServerKey;
	this->_Inst_ServerKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
	delete this->_Inst_GSSMechanism;
	this->_Inst_GSSMechanism = NULL;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_InternalSocket;
	this->_Inst_InternalSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_KeyStorage;
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELPORTKNOCK
	delete this->_Inst_PortKnock;
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_TrustedKeys;
	this->_Inst_TrustedKeys = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_WebTunnelRequestHeaders;
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_WebTunnelRequestHeaders;
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_WebTunnelResponseHeaders;
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_WebTunnelResponseHeaders;
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_SocketBinding;
	this->_Inst_SocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_SFTPServerExecutableLocations;
	this->_Inst_SFTPServerExecutableLocations = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELSIMPLESFTPCLIENT */

};	/* namespace SecureBlackbox */
