#include "sbdiskfsadapter.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDISKFILESYSTEMADAPTER

void TElDiskFileSystemAdapter::AdjustPath(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDiskFileSystemAdapter_AdjustPath(_Handle, Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(484334838, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElCustomFileSystemAdapterHandle TElDiskFileSystemAdapter::Clone()
{
	TElCustomFileSystemAdapterHandle OutResult;
	SBCheckError(TElDiskFileSystemAdapter_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
int32_t TElDiskFileSystemAdapter::GetFileStream(const std::string &Path, uint32_t OpenMode, TSBFileShareMode ShareMode, TStream &FileStream)
{
	int32_t OutResult;
	TElClassHandle hFileStream = FileStream.getHandle();
	SBCheckError(TElDiskFileSystemAdapter_GetFileStream(_Handle, Path.data(), (int32_t)Path.length(), OpenMode, (TSBFileShareModeRaw)ShareMode, &hFileStream, &OutResult));
	FileStream.updateHandle(hFileStream);
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElDiskFileSystemAdapter::FileExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDiskFileSystemAdapter_FileExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDiskFileSystemAdapter::DirectoryExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDiskFileSystemAdapter_DirectoryExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElDiskFileSystemAdapter::FileDelete(const std::string &Path)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileDelete(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::FileMove(const std::string &FromName, const std::string &ToName)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileMove(_Handle, FromName.data(), (int32_t)FromName.length(), ToName.data(), (int32_t)ToName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::DirectoryRemove(const std::string &Path)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_DirectoryRemove(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::DirectoryMake(const std::string &Path)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_DirectoryMake(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::FileRead(TObject &FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileRead(_Handle, FileHandle.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::FileRead(TObject *FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileRead(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::FileWrite(TObject &FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileWrite(_Handle, FileHandle.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::FileWrite(TObject *FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileWrite(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDiskFileSystemAdapter::FileSeek(TObject &FileHandle, int64_t Position, TSBFileSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileSeek(_Handle, FileHandle.getHandle(), Position, (TSBFileSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDiskFileSystemAdapter::FileSeek(TObject *FileHandle, int64_t Position, TSBFileSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileSeek(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, Position, (TSBFileSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE void TElDiskFileSystemAdapter::FileSetSize(TObject &FileHandle, int64_t NewSize)
{
	SBCheckError(TElDiskFileSystemAdapter_FileSetSize(_Handle, FileHandle.getHandle(), NewSize));
}

SB_INLINE void TElDiskFileSystemAdapter::FileSetSize(TObject *FileHandle, int64_t NewSize)
{
	SBCheckError(TElDiskFileSystemAdapter_FileSetSize(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, NewSize));
}

SB_INLINE int64_t TElDiskFileSystemAdapter::FileGetSize(TObject &FileHandle)
{
	int64_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileGetSize(_Handle, FileHandle.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDiskFileSystemAdapter::FileGetSize(TObject *FileHandle)
{
	int64_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileGetSize(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDiskFileSystemAdapter::FileGetPosition(TObject &FileHandle)
{
	int64_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileGetPosition(_Handle, FileHandle.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDiskFileSystemAdapter::FileGetPosition(TObject *FileHandle)
{
	int64_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileGetPosition(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::WriteFileTag(const std::string &Path, const std::string &TagName, const std::string &TagValue)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_WriteFileTag(_Handle, Path.data(), (int32_t)Path.length(), TagName.data(), (int32_t)TagName.length(), TagValue.data(), (int32_t)TagValue.length(), &OutResult));
	return OutResult;
}

int32_t TElDiskFileSystemAdapter::ReadFileTag(const std::string &Path, const std::string &TagName, std::string &TagValue)
{
	int32_t OutResult;
	int32_t szTagValue = (int32_t)TagValue.length();
	uint32_t _err = TElDiskFileSystemAdapter_ReadFileTag(_Handle, Path.data(), (int32_t)Path.length(), TagName.data(), (int32_t)TagName.length(), (char *)TagValue.data(), &szTagValue, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		TagValue.resize(szTagValue);
		SBCheckError(SBGetLastReturnStringA(1165768749, 3, (char *)TagValue.data(), &szTagValue));
	}
	else
		SBCheckError(_err);

	TagValue.resize(szTagValue);
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::DeleteFileTag(const std::string &Path, const std::string &TagName)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_DeleteFileTag(_Handle, Path.data(), (int32_t)Path.length(), TagName.data(), (int32_t)TagName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::FileGetTimes(const std::string &Path, int64_t &CreationTime, int64_t &ModificationTime, int64_t &LastAccessTime)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_FileGetTimes(_Handle, Path.data(), (int32_t)Path.length(), &CreationTime, &ModificationTime, &LastAccessTime, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
SB_INLINE int32_t TElDiskFileSystemAdapter::GetEntryInformation(const std::string &Path, TElVFSEntryInformation &EntryInfo)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_GetEntryInformation(_Handle, Path.data(), (int32_t)Path.length(), EntryInfo.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::GetEntryInformation(const std::string &Path, TElVFSEntryInformation *EntryInfo)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_GetEntryInformation(_Handle, Path.data(), (int32_t)Path.length(), (EntryInfo != NULL) ? EntryInfo->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
SB_INLINE int32_t TElDiskFileSystemAdapter::SetEntryInformation(const std::string &Path, TElVFSEntryInformation &EntryInfo, int32_t InfoFlags)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_SetEntryInformation(_Handle, Path.data(), (int32_t)Path.length(), EntryInfo.getHandle(), InfoFlags, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDiskFileSystemAdapter::SetEntryInformation(const std::string &Path, TElVFSEntryInformation *EntryInfo, int32_t InfoFlags)
{
	int32_t OutResult;
	SBCheckError(TElDiskFileSystemAdapter_SetEntryInformation(_Handle, Path.data(), (int32_t)Path.length(), (EntryInfo != NULL) ? EntryInfo->getHandle() : SB_NULL_HANDLE, InfoFlags, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

SB_INLINE void TElDiskFileSystemAdapter::get_OnWriteFileTag(TElVFSWriteFileTagEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDiskFileSystemAdapter_get_OnWriteFileTag(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDiskFileSystemAdapter::set_OnWriteFileTag(TElVFSWriteFileTagEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDiskFileSystemAdapter_set_OnWriteFileTag(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDiskFileSystemAdapter::get_OnReadFileTag(TElVFSReadFileTagEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDiskFileSystemAdapter_get_OnReadFileTag(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDiskFileSystemAdapter::set_OnReadFileTag(TElVFSReadFileTagEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDiskFileSystemAdapter_set_OnReadFileTag(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDiskFileSystemAdapter::get_OnDeleteFileTag(TElVFSDeleteFileTagEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDiskFileSystemAdapter_get_OnDeleteFileTag(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDiskFileSystemAdapter::set_OnDeleteFileTag(TElVFSDeleteFileTagEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDiskFileSystemAdapter_set_OnDeleteFileTag(_Handle, pMethodValue, pDataValue));
}

TElDiskFileSystemAdapter::TElDiskFileSystemAdapter(TElDiskFileSystemAdapterHandle handle, TElOwnHandle ownHandle) : TElCustomFileSystemAdapter(handle, ownHandle)
{
}

TElDiskFileSystemAdapter::TElDiskFileSystemAdapter(TComponent &AOwner) : TElCustomFileSystemAdapter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDiskFileSystemAdapter_Create(AOwner.getHandle(), &_Handle));
}

TElDiskFileSystemAdapter::TElDiskFileSystemAdapter(TComponent *AOwner) : TElCustomFileSystemAdapter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDiskFileSystemAdapter_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELDISKFILESYSTEMADAPTER */

};	/* namespace SecureBlackbox */

