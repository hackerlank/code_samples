#include "sbsftp.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSFTPSTREAM

SB_INLINE int32_t TElSftpStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElSftpStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSftpStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElSftpStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSftpStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElSftpStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

void TElSftpStream::get_Handle(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpStream_get_Handle(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1788873458, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElSftpStream::TElSftpStream(TElSftpStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TElSftpStream::TElSftpStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPSTREAM */

#ifdef SB_USE_CLASS_TELSFTPCLIENT

SB_INLINE int32_t TElSftpClient::Read(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Buffer, Size, &OutResult));
	return OutResult;
}

bool TElSftpClient::Read(const std::vector<uint8_t> &Handle, int64_t Offset, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_Read_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSftpClient::ReadSync(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_ReadSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSftpClient::ReadSync(const std::vector<uint8_t> &Handle, int64_t Offset, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_ReadSync_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Size, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSFTPSTREAM
SB_INLINE TElSftpStreamHandle TElSftpClient::OpenStream(const std::string &Filename, TSBSftpFileOpenModes Modes)
{
	TElSftpStreamHandle OutResult;
	SBCheckError(TElSftpClient_OpenStream(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSFTPSTREAM */

bool TElSftpClient::Open()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_Open(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::OpenSync()
{
	SBCheckError(TElSftpClient_OpenSync(_Handle));
}

bool TElSftpClient::CreateFile(const std::string &Filename)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_CreateFile(_Handle, Filename.data(), (int32_t)Filename.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSftpClient::CreateFileSync(const std::string &Filename, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpClient_CreateFileSync(_Handle, Filename.data(), (int32_t)Filename.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-818068478, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
bool TElSftpClient::OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes &Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_OpenFile(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, Attributes.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes *Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_OpenFile(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
bool TElSftpClient::OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes &Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_OpenFile_1(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (TSBSftpFileOpenAccessRaw)Access, Attributes.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::OpenFile(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes *Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_OpenFile_1(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (TSBSftpFileOpenAccessRaw)Access, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
void TElSftpClient::OpenFileSync(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes &Attributes, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpClient_OpenFileSync(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, Attributes.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1489180211, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSftpClient::OpenFileSync(const std::string &Filename, TSBSftpFileOpenModes Modes, TElSftpFileAttributes *Attributes, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpClient_OpenFileSync(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1489180211, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
void TElSftpClient::OpenFileSync(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes &Attributes, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpClient_OpenFileSync_1(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (TSBSftpFileOpenAccessRaw)Access, Attributes.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2085937906, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSftpClient::OpenFileSync(const std::string &Filename, TSBSftpFileOpenModes Modes, TSBSftpFileOpenAccess Access, TElSftpFileAttributes *Attributes, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpClient_OpenFileSync_1(_Handle, Filename.data(), (int32_t)Filename.length(), (TSBSftpFileOpenModesRaw)Modes, (TSBSftpFileOpenAccessRaw)Access, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2085937906, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

bool TElSftpClient::OpenDirectory(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_OpenDirectory(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSftpClient::OpenDirectorySync(const std::string &Path, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpClient_OpenDirectorySync(_Handle, Path.data(), (int32_t)Path.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1717049257, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSftpClient::ReadDirectory(const std::vector<uint8_t> &Handle)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ReadDirectory(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::ReadDirectorySync(const std::vector<uint8_t> &Handle)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ReadDirectorySync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::RemoveFile(const std::string &Filename)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RemoveFile(_Handle, Filename.data(), (int32_t)Filename.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::RemoveFileSync(const std::string &Filename)
{
	SBCheckError(TElSftpClient_RemoveFileSync(_Handle, Filename.data(), (int32_t)Filename.length()));
}

#ifdef SB_USE_CLASS_TSTRINGS
bool TElSftpClient::RemoveFiles(TStrings &Filenames)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RemoveFiles(_Handle, Filenames.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::RemoveFiles(TStrings *Filenames)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RemoveFiles(_Handle, (Filenames != NULL) ? Filenames->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElSftpClient::RemoveFilesSync(TStrings &Filenames)
{
	SBCheckError(TElSftpClient_RemoveFilesSync(_Handle, Filenames.getHandle()));
}

SB_INLINE void TElSftpClient::RemoveFilesSync(TStrings *Filenames)
{
	SBCheckError(TElSftpClient_RemoveFilesSync(_Handle, (Filenames != NULL) ? Filenames->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGS */

bool TElSftpClient::RenameFile(const std::string &OldPath, const std::string &NewPath)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RenameFile(_Handle, OldPath.data(), (int32_t)OldPath.length(), NewPath.data(), (int32_t)NewPath.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::RenameFileSync(const std::string &OldPath, const std::string &NewPath)
{
	SBCheckError(TElSftpClient_RenameFileSync(_Handle, OldPath.data(), (int32_t)OldPath.length(), NewPath.data(), (int32_t)NewPath.length()));
}

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
bool TElSftpClient::MakeDirectory(const std::string &Path, TElSftpFileAttributes &Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_MakeDirectory(_Handle, Path.data(), (int32_t)Path.length(), Attributes.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::MakeDirectory(const std::string &Path, TElSftpFileAttributes *Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_MakeDirectory(_Handle, Path.data(), (int32_t)Path.length(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_INLINE void TElSftpClient::MakeDirectorySync(const std::string &Path, TElSftpFileAttributes &Attributes)
{
	SBCheckError(TElSftpClient_MakeDirectorySync(_Handle, Path.data(), (int32_t)Path.length(), Attributes.getHandle()));
}

SB_INLINE void TElSftpClient::MakeDirectorySync(const std::string &Path, TElSftpFileAttributes *Attributes)
{
	SBCheckError(TElSftpClient_MakeDirectorySync(_Handle, Path.data(), (int32_t)Path.length(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

bool TElSftpClient::RemoveDirectory(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RemoveDirectory(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::RemoveDirectorySync(const std::string &Path)
{
	SBCheckError(TElSftpClient_RemoveDirectorySync(_Handle, Path.data(), (int32_t)Path.length()));
}

bool TElSftpClient::RequestAttributes(const std::string &Path, bool FollowSymLinks)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RequestAttributes(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)FollowSymLinks, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::RequestAttributes(const std::vector<uint8_t> &Handle)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RequestAttributes_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::RequestAttributesSync(const std::string &Path, bool FollowSymLinks)
{
	SBCheckError(TElSftpClient_RequestAttributesSync(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)FollowSymLinks));
}

SB_INLINE void TElSftpClient::RequestAttributesSync(const std::vector<uint8_t> &Handle)
{
	SBCheckError(TElSftpClient_RequestAttributesSync_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size()));
}

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
bool TElSftpClient::SetAttributes(const std::string &Path, TElSftpFileAttributes &Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_SetAttributes(_Handle, Path.data(), (int32_t)Path.length(), Attributes.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::SetAttributes(const std::string &Path, TElSftpFileAttributes *Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_SetAttributes(_Handle, Path.data(), (int32_t)Path.length(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_INLINE void TElSftpClient::SetAttributesSync(const std::string &Path, TElSftpFileAttributes &Attributes)
{
	SBCheckError(TElSftpClient_SetAttributesSync(_Handle, Path.data(), (int32_t)Path.length(), Attributes.getHandle()));
}

SB_INLINE void TElSftpClient::SetAttributesSync(const std::string &Path, TElSftpFileAttributes *Attributes)
{
	SBCheckError(TElSftpClient_SetAttributesSync(_Handle, Path.data(), (int32_t)Path.length(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
bool TElSftpClient::SetAttributesByHandle(const std::vector<uint8_t> &Handle, TElSftpFileAttributes &Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_SetAttributesByHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Attributes.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::SetAttributesByHandle(const std::vector<uint8_t> &Handle, TElSftpFileAttributes *Attributes)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_SetAttributesByHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_INLINE void TElSftpClient::SetAttributesByHandleSync(const std::vector<uint8_t> &Handle, TElSftpFileAttributes &Attributes)
{
	SBCheckError(TElSftpClient_SetAttributesByHandleSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Attributes.getHandle()));
}

SB_INLINE void TElSftpClient::SetAttributesByHandleSync(const std::vector<uint8_t> &Handle, TElSftpFileAttributes *Attributes)
{
	SBCheckError(TElSftpClient_SetAttributesByHandleSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

bool TElSftpClient::ReadSymLink(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ReadSymLink(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::ReadSymLinkSync(const std::string &Path)
{
	SBCheckError(TElSftpClient_ReadSymLinkSync(_Handle, Path.data(), (int32_t)Path.length()));
}

bool TElSftpClient::CreateSymLink(const std::string &LinkPath, const std::string &TargetPath)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_CreateSymLink(_Handle, LinkPath.data(), (int32_t)LinkPath.length(), TargetPath.data(), (int32_t)TargetPath.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::CreateSymLinkSync(const std::string &LinkPath, const std::string &TargetPath)
{
	SBCheckError(TElSftpClient_CreateSymLinkSync(_Handle, LinkPath.data(), (int32_t)LinkPath.length(), TargetPath.data(), (int32_t)TargetPath.length()));
}

bool TElSftpClient::CreateHardLink(const std::string &LinkPath, const std::string &TargetPath)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_CreateHardLink(_Handle, LinkPath.data(), (int32_t)LinkPath.length(), TargetPath.data(), (int32_t)TargetPath.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::CreateHardLinkSync(const std::string &LinkPath, const std::string &TargetPath)
{
	SBCheckError(TElSftpClient_CreateHardLinkSync(_Handle, LinkPath.data(), (int32_t)LinkPath.length(), TargetPath.data(), (int32_t)TargetPath.length()));
}

bool TElSftpClient::RequestAbsolutePath(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RequestAbsolutePath(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSftpClient::RequestAbsolutePathSync(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpClient_RequestAbsolutePathSync(_Handle, Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1350141958, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElSftpClient::RequestAbsolutePathEx(const std::string &Path, TSBSftpRealpathControl Control, TStringList &ComposePath)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RequestAbsolutePathEx(_Handle, Path.data(), (int32_t)Path.length(), (TSBSftpRealpathControlRaw)Control, ComposePath.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::RequestAbsolutePathEx(const std::string &Path, TSBSftpRealpathControl Control, TStringList *ComposePath)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RequestAbsolutePathEx(_Handle, Path.data(), (int32_t)Path.length(), (TSBSftpRealpathControlRaw)Control, (ComposePath != NULL) ? ComposePath->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
void TElSftpClient::RequestAbsolutePathExSync(const std::string &Path, TSBSftpRealpathControl Control, TStringList &ComposePath, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpClient_RequestAbsolutePathExSync(_Handle, Path.data(), (int32_t)Path.length(), (TSBSftpRealpathControlRaw)Control, ComposePath.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(490311621, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSftpClient::RequestAbsolutePathExSync(const std::string &Path, TSBSftpRealpathControl Control, TStringList *ComposePath, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpClient_RequestAbsolutePathExSync(_Handle, Path.data(), (int32_t)Path.length(), (TSBSftpRealpathControlRaw)Control, (ComposePath != NULL) ? ComposePath->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(490311621, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

bool TElSftpClient::Block(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccess LockMask)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_Block(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Length, (TSBSftpFileOpenAccessRaw)LockMask, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::BlockSync(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length, TSBSftpFileOpenAccess LockMask)
{
	SBCheckError(TElSftpClient_BlockSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Length, (TSBSftpFileOpenAccessRaw)LockMask));
}

bool TElSftpClient::Unblock(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_Unblock(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Length, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::UnblockSync(const std::vector<uint8_t> &Handle, int64_t Offset, int64_t Length)
{
	SBCheckError(TElSftpClient_UnblockSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Length));
}

bool TElSftpClient::CloseHandle(const std::vector<uint8_t> &Handle)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_CloseHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::CloseHandleSync(const std::vector<uint8_t> &Handle)
{
	SBCheckError(TElSftpClient_CloseHandleSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size()));
}

bool TElSftpClient::Write(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, uint32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_Write(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::WriteSync(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, uint32_t Size)
{
	SBCheckError(TElSftpClient_WriteSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Buffer, Size));
}

bool TElSftpClient::FinalizeTextWrite(const std::vector<uint8_t> &Handle)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_FinalizeTextWrite(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::FinalizeTextWriteSync(const std::vector<uint8_t> &Handle)
{
	SBCheckError(TElSftpClient_FinalizeTextWriteSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size()));
}

bool TElSftpClient::ExtensionCmd(const std::string &Extension, void * DataBuffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ExtensionCmd(_Handle, Extension.data(), (int32_t)Extension.length(), DataBuffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::ExtensionCmd(const std::string &Extension)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ExtensionCmd_1(_Handle, Extension.data(), (int32_t)Extension.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::ExtensionCmd(const std::string &Extension, const std::vector<uint8_t> &DataBuffer)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ExtensionCmd_2(_Handle, Extension.data(), (int32_t)Extension.length(), SB_STD_VECTOR_FRONT_ADR(DataBuffer), (int32_t)DataBuffer.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::ExtensionCmd(const std::vector<uint8_t> &Extension)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ExtensionCmd_3(_Handle, SB_STD_VECTOR_FRONT_ADR(Extension), (int32_t)Extension.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::ExtensionCmd(const std::vector<uint8_t> &Extension, void * DataBuffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ExtensionCmd_4(_Handle, SB_STD_VECTOR_FRONT_ADR(Extension), (int32_t)Extension.size(), DataBuffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::ExtensionCmd(const std::vector<uint8_t> &Extension, const std::vector<uint8_t> &DataBuffer)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_ExtensionCmd_5(_Handle, SB_STD_VECTOR_FRONT_ADR(Extension), (int32_t)Extension.size(), SB_STD_VECTOR_FRONT_ADR(DataBuffer), (int32_t)DataBuffer.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::ExtensionCmdSync(const std::string &Extension, void * DataBuffer, int32_t Size)
{
	SBCheckError(TElSftpClient_ExtensionCmdSync(_Handle, Extension.data(), (int32_t)Extension.length(), DataBuffer, Size));
}

SB_INLINE void TElSftpClient::ExtensionCmdSync(const std::string &Extension)
{
	SBCheckError(TElSftpClient_ExtensionCmdSync_1(_Handle, Extension.data(), (int32_t)Extension.length()));
}

bool TElSftpClient::TextSeek(const std::vector<uint8_t> &Handle, int64_t LineNumber)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_TextSeek(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), LineNumber, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::TextSeekSync(const std::vector<uint8_t> &Handle, int64_t LineNumber)
{
	SBCheckError(TElSftpClient_TextSeekSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), LineNumber));
}

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
bool TElSftpClient::SendVendorID(TElSftpVendorIDExtension &VendorID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_SendVendorID(_Handle, VendorID.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpClient::SendVendorID(TElSftpVendorIDExtension *VendorID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_SendVendorID(_Handle, (VendorID != NULL) ? VendorID->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
SB_INLINE void TElSftpClient::SendVendorIDSync(TElSftpVendorIDExtension &VendorID)
{
	SBCheckError(TElSftpClient_SendVendorIDSync(_Handle, VendorID.getHandle()));
}

SB_INLINE void TElSftpClient::SendVendorIDSync(TElSftpVendorIDExtension *VendorID)
{
	SBCheckError(TElSftpClient_SendVendorIDSync(_Handle, (VendorID != NULL) ? VendorID->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

bool TElSftpClient::RequestFileHash(const std::string &FileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RequestFileHash(_Handle, FileName.data(), (int32_t)FileName.length(), StartOffset, Length, BlockSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::RequestFileHashSync(const std::string &FileName, int64_t StartOffset, int64_t Length, uint32_t BlockSize)
{
	SBCheckError(TElSftpClient_RequestFileHashSync(_Handle, FileName.data(), (int32_t)FileName.length(), StartOffset, Length, BlockSize));
}

bool TElSftpClient::RequestFileHashByHandle(const std::vector<uint8_t> &Handle, int64_t StartOffset, int64_t Length, uint32_t BlockSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RequestFileHashByHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), StartOffset, Length, BlockSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::RequestFileHashByHandleSync(const std::vector<uint8_t> &Handle, int64_t StartOffset, int64_t Length, uint32_t BlockSize)
{
	SBCheckError(TElSftpClient_RequestFileHashByHandleSync(_Handle, SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), StartOffset, Length, BlockSize));
}

bool TElSftpClient::QueryAvailableSpace(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_QueryAvailableSpace(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::QueryAvailableSpaceSync(const std::string &Path)
{
	SBCheckError(TElSftpClient_QueryAvailableSpaceSync(_Handle, Path.data(), (int32_t)Path.length()));
}

bool TElSftpClient::QueryHomeDirectory(const std::string &Username)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_QueryHomeDirectory(_Handle, Username.data(), (int32_t)Username.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::QueryHomeDirectorySync(const std::string &Username)
{
	SBCheckError(TElSftpClient_QueryHomeDirectorySync(_Handle, Username.data(), (int32_t)Username.length()));
}

bool TElSftpClient::QueryStatVFS(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_QueryStatVFS(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::QueryStatVFSSync(const std::string &Path)
{
	SBCheckError(TElSftpClient_QueryStatVFSSync(_Handle, Path.data(), (int32_t)Path.length()));
}

bool TElSftpClient::CopyRemoteFile(const std::string &Source, const std::string &Destination, bool Overwrite)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_CopyRemoteFile(_Handle, Source.data(), (int32_t)Source.length(), Destination.data(), (int32_t)Destination.length(), (int8_t)Overwrite, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::CopyRemoteFileSync(const std::string &Source, const std::string &Destination, bool Overwrite)
{
	SBCheckError(TElSftpClient_CopyRemoteFileSync(_Handle, Source.data(), (int32_t)Source.length(), Destination.data(), (int32_t)Destination.length(), (int8_t)Overwrite));
}

bool TElSftpClient::CopyRemoteData(const std::vector<uint8_t> &ReadFrom, int64_t ReadFromOffset, const std::vector<uint8_t> &WriteTo, int64_t WriteToOffset, int64_t DataLength)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_CopyRemoteData(_Handle, SB_STD_VECTOR_FRONT_ADR(ReadFrom), (int32_t)ReadFrom.size(), ReadFromOffset, SB_STD_VECTOR_FRONT_ADR(WriteTo), (int32_t)WriteTo.size(), WriteToOffset, DataLength, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::CopyRemoteDataSync(const std::vector<uint8_t> &ReadFrom, int64_t ReadFromOffset, const std::vector<uint8_t> &WriteTo, int64_t WriteToOffset, int64_t DataLength)
{
	SBCheckError(TElSftpClient_CopyRemoteDataSync(_Handle, SB_STD_VECTOR_FRONT_ADR(ReadFrom), (int32_t)ReadFrom.size(), ReadFromOffset, SB_STD_VECTOR_FRONT_ADR(WriteTo), (int32_t)WriteTo.size(), WriteToOffset, DataLength));
}

bool TElSftpClient::RequestTempFolder()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_RequestTempFolder(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::RequestTempFolderSync()
{
	SBCheckError(TElSftpClient_RequestTempFolderSync(_Handle));
}

bool TElSftpClient::MakeTempFolder()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_MakeTempFolder(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::MakeTempFolderSync()
{
	SBCheckError(TElSftpClient_MakeTempFolderSync(_Handle));
}

bool TElSftpClient::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBSftpVersion TElSftpClient::get_Version()
{
	TSBSftpVersionRaw OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_Version(_Handle, &OutResultRaw));
	return (TSBSftpVersion)OutResultRaw;
}

SB_INLINE int32_t TElSftpClient::get_SFTPExtCount()
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_get_SFTPExtCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
TSBSftpExtendedAttribute* TElSftpClient::get_SFTPExt(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpClient_get_SFTPExt(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SFTPExt)
		this->_Inst_SFTPExt = new TSBSftpExtendedAttribute(hOutResult, ohFalse);
	else
		this->_Inst_SFTPExt->updateHandle(hOutResult);
	return this->_Inst_SFTPExt;
}
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */

void TElSftpClient::get_NewLineConvention(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpClient_get_NewLineConvention(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1270699329, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpClient::set_NewLineConvention(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpClient_set_NewLineConvention(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSftpClient::get_LocalNewLineConvention(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpClient_get_LocalNewLineConvention(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1777531718, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpClient::set_LocalNewLineConvention(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpClient_set_LocalNewLineConvention(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSftpClient::get_LastSyncComment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpClient_get_LastSyncComment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1045124271, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSftpClient::get_LastSyncError()
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_get_LastSyncError(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSftpClient::get_LastReadCount()
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_get_LastReadCount(_Handle, &OutResult));
	return OutResult;
}

bool TElSftpClient::get_SBB3Compatible()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_SBB3Compatible(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::set_SBB3Compatible(bool Value)
{
	SBCheckError(TElSftpClient_set_SBB3Compatible(_Handle, (int8_t)Value));
}

bool TElSftpClient::get_SynchronousMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_SynchronousMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::set_SynchronousMode(bool Value)
{
	SBCheckError(TElSftpClient_set_SynchronousMode(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
TElCustomSSHTunnel* TElSftpClient::get_Tunnel()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpClient_get_Tunnel(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tunnel)
		this->_Inst_Tunnel = new TElCustomSSHTunnel(hOutResult, ohFalse);
	else
		this->_Inst_Tunnel->updateHandle(hOutResult);
	return this->_Inst_Tunnel;
}

SB_INLINE void TElSftpClient::set_Tunnel(TElCustomSSHTunnel &Value)
{
	SBCheckError(TElSftpClient_set_Tunnel(_Handle, Value.getHandle()));
}

SB_INLINE void TElSftpClient::set_Tunnel(TElCustomSSHTunnel *Value)
{
	SBCheckError(TElSftpClient_set_Tunnel(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

SB_INLINE int32_t TElSftpClient::get_SftpBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_get_SftpBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpClient::set_SftpBufferSize(int32_t Value)
{
	SBCheckError(TElSftpClient_set_SftpBufferSize(_Handle, Value));
}

bool TElSftpClient::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::set_UseUTF8(bool Value)
{
	SBCheckError(TElSftpClient_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TElSftpClient::get_UseUTF8OnV3()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_UseUTF8OnV3(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::set_UseUTF8OnV3(bool Value)
{
	SBCheckError(TElSftpClient_set_UseUTF8OnV3(_Handle, (int8_t)Value));
}

void TElSftpClient::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpClient_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2046459092, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpClient::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TElSftpClient_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSftpClient::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TElSftpClient_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

void TElSftpClient::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpClient_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1372767036, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpClient::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TElSftpClient_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBSftpVersions TElSftpClient::get_Versions()
{
	TSBSftpVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_Versions(_Handle, &OutResultRaw));
	return (TSBSftpVersions)OutResultRaw;
}

SB_INLINE void TElSftpClient::set_Versions(TSBSftpVersions Value)
{
	SBCheckError(TElSftpClient_set_Versions(_Handle, (TSBSftpVersionsRaw)Value));
}

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
TElSftpExtendedProperties* TElSftpClient::get_ExtendedProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpClient_get_ExtendedProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtendedProperties)
		this->_Inst_ExtendedProperties = new TElSftpExtendedProperties(hOutResult, ohFalse);
	else
		this->_Inst_ExtendedProperties->updateHandle(hOutResult);
	return this->_Inst_ExtendedProperties;
}

SB_INLINE void TElSftpClient::set_ExtendedProperties(TElSftpExtendedProperties &Value)
{
	SBCheckError(TElSftpClient_set_ExtendedProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElSftpClient::set_ExtendedProperties(TElSftpExtendedProperties *Value)
{
	SBCheckError(TElSftpClient_set_ExtendedProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */

SB_INLINE int32_t TElSftpClient::get_UploadBlockSize()
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_get_UploadBlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpClient::set_UploadBlockSize(int32_t Value)
{
	SBCheckError(TElSftpClient_set_UploadBlockSize(_Handle, Value));
}

SB_INLINE int32_t TElSftpClient::get_DownloadBlockSize()
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_get_DownloadBlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpClient::set_DownloadBlockSize(int32_t Value)
{
	SBCheckError(TElSftpClient_set_DownloadBlockSize(_Handle, Value));
}

SB_INLINE int32_t TElSftpClient::get_PipelineLength()
{
	int32_t OutResult;
	SBCheckError(TElSftpClient_get_PipelineLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpClient::set_PipelineLength(int32_t Value)
{
	SBCheckError(TElSftpClient_set_PipelineLength(_Handle, Value));
}

bool TElSftpClient::get_AutoAdjustTransferBlock()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_AutoAdjustTransferBlock(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpClient::set_AutoAdjustTransferBlock(bool Value)
{
	SBCheckError(TElSftpClient_set_AutoAdjustTransferBlock(_Handle, (int8_t)Value));
}

TSBOperationErrorHandling TElSftpClient::get_OperationErrorHandling()
{
	TSBOperationErrorHandlingRaw OutResultRaw = 0;
	SBCheckError(TElSftpClient_get_OperationErrorHandling(_Handle, &OutResultRaw));
	return (TSBOperationErrorHandling)OutResultRaw;
}

SB_INLINE void TElSftpClient::set_OperationErrorHandling(TSBOperationErrorHandling Value)
{
	SBCheckError(TElSftpClient_set_OperationErrorHandling(_Handle, (TSBOperationErrorHandlingRaw)Value));
}

SB_INLINE void TElSftpClient::get_MessageLoop(TSBSftpMessageLoopEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_MessageLoop(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_MessageLoop(TSBSftpMessageLoopEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_MessageLoop(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnOpenConnection(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnOpenConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnOpenConnection(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnOpenConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnCloseConnection(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnCloseConnection(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnOpenFile(TSBSftpFileOpenEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnOpenFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnOpenFile(TSBSftpFileOpenEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnOpenFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnError(TSBSftpErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnError(TSBSftpErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnSuccess(TSBSftpSuccessEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnSuccess(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnSuccess(TSBSftpSuccessEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnSuccess(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnDirectoryListing(TSBSftpDirectoryListingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnDirectoryListing(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnDirectoryListing(TSBSftpDirectoryListingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnDirectoryListing(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnFileAttributes(TSBSftpFileAttributesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnFileAttributes(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnFileAttributes(TSBSftpFileAttributesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnFileAttributes(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnData(TSBSftpDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnData(TSBSftpDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnAbsolutePath(TSBSftpAbsolutePathEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnAbsolutePath(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnAbsolutePath(TSBSftpAbsolutePathEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnAbsolutePath(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnBlockTransferPrepared(TSBSftpBlockTransferPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnBlockTransferPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnBlockTransferPrepared(TSBSftpBlockTransferPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnBlockTransferPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnExtendedReply(TSBSftpDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnExtendedReply(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnExtendedReply(TSBSftpDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnExtendedReply(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnVersionSelect(TSBSftpVersionSelectEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnVersionSelect(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnVersionSelect(TSBSftpVersionSelectEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnVersionSelect(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnFileHash(TSBSftpFileHashEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnFileHash(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnFileHash(TSBSftpFileHashEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnFileHash(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnAvailableSpace(TSBSftpAvailableSpaceEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnAvailableSpace(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnAvailableSpace(TSBSftpAvailableSpaceEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnAvailableSpace(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnName(TSBSftpNameEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnName(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnName(TSBSftpNameEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnName(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnTransferCompleted(TSBSftpTransferCompletedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnTransferCompleted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnTransferCompleted(TSBSftpTransferCompletedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnTransferCompleted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpClient::get_OnStatVFS(TSBSftpStatvfsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpClient_get_OnStatVFS(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpClient::set_OnStatVFS(TSBSftpStatvfsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpClient_set_OnStatVFS(_Handle, pMethodValue, pDataValue));
}

void TElSftpClient::initInstances()
{
#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
	this->_Inst_SFTPExt = NULL;
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
	this->_Inst_Tunnel = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */
#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
	this->_Inst_ExtendedProperties = NULL;
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */
}

TElSftpClient::TElSftpClient(TElSftpClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSftpClient::TElSftpClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpClient_Create(AOwner.getHandle(), &_Handle));
}

TElSftpClient::TElSftpClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSftpClient::~TElSftpClient()
{
#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
	delete this->_Inst_SFTPExt;
	this->_Inst_SFTPExt = NULL;
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
	delete this->_Inst_Tunnel;
	this->_Inst_Tunnel = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */
#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
	delete this->_Inst_ExtendedProperties;
	this->_Inst_ExtendedProperties = NULL;
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */
}
#endif /* SB_USE_CLASS_TELSFTPCLIENT */

};	/* namespace SecureBlackbox */

