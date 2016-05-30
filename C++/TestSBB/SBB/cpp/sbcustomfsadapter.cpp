#include "sbcustomfsadapter.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION

SB_INLINE void TElVFSEntryInformation::Assign(TElVFSEntryInformation &Source)
{
	SBCheckError(TElVFSEntryInformation_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElVFSEntryInformation::Assign(TElVFSEntryInformation *Source)
{
	SBCheckError(TElVFSEntryInformation_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElVFSEntryInformation::get_AccessMode()
{
	int32_t OutResult;
	SBCheckError(TElVFSEntryInformation_get_AccessMode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElVFSEntryInformation::set_AccessMode(int32_t Value)
{
	SBCheckError(TElVFSEntryInformation_set_AccessMode(_Handle, Value));
}

SB_INLINE int32_t TElVFSEntryInformation::get_Attributes()
{
	int32_t OutResult;
	SBCheckError(TElVFSEntryInformation_get_Attributes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElVFSEntryInformation::set_Attributes(int32_t Value)
{
	SBCheckError(TElVFSEntryInformation_set_Attributes(_Handle, Value));
}

SB_INLINE int64_t TElVFSEntryInformation::get_DateAccessed()
{
	int64_t OutResult;
	SBCheckError(TElVFSEntryInformation_get_DateAccessed(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElVFSEntryInformation::set_DateAccessed(int64_t Value)
{
	SBCheckError(TElVFSEntryInformation_set_DateAccessed(_Handle, Value));
}

SB_INLINE int64_t TElVFSEntryInformation::get_DateCreated()
{
	int64_t OutResult;
	SBCheckError(TElVFSEntryInformation_get_DateCreated(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElVFSEntryInformation::set_DateCreated(int64_t Value)
{
	SBCheckError(TElVFSEntryInformation_set_DateCreated(_Handle, Value));
}

SB_INLINE int64_t TElVFSEntryInformation::get_DateModified()
{
	int64_t OutResult;
	SBCheckError(TElVFSEntryInformation_get_DateModified(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElVFSEntryInformation::set_DateModified(int64_t Value)
{
	SBCheckError(TElVFSEntryInformation_set_DateModified(_Handle, Value));
}

TSBFileType TElVFSEntryInformation::get_FileType()
{
	TSBFileTypeRaw OutResultRaw = 0;
	SBCheckError(TElVFSEntryInformation_get_FileType(_Handle, &OutResultRaw));
	return (TSBFileType)OutResultRaw;
}

SB_INLINE void TElVFSEntryInformation::set_FileType(TSBFileType Value)
{
	SBCheckError(TElVFSEntryInformation_set_FileType(_Handle, (TSBFileTypeRaw)Value));
}

void TElVFSEntryInformation::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElVFSEntryInformation_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-238316360, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElVFSEntryInformation::set_Name(const std::string &Value)
{
	SBCheckError(TElVFSEntryInformation_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElVFSEntryInformation::get_FullName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElVFSEntryInformation_get_FullName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1727682866, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElVFSEntryInformation::set_FullName(const std::string &Value)
{
	SBCheckError(TElVFSEntryInformation_set_FullName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElVFSEntryInformation::get_OwnerName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElVFSEntryInformation_get_OwnerName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1120409474, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElVFSEntryInformation::set_OwnerName(const std::string &Value)
{
	SBCheckError(TElVFSEntryInformation_set_OwnerName(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElVFSEntryInformation::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElVFSEntryInformation_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElVFSEntryInformation::set_Size(int64_t Value)
{
	SBCheckError(TElVFSEntryInformation_set_Size(_Handle, Value));
}

TElVFSEntryInformation::TElVFSEntryInformation(TElVFSEntryInformationHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElVFSEntryInformation::TElVFSEntryInformation() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElVFSEntryInformation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
SB_INLINE void TElVFSEntryInformationList::Add(TElVFSEntryInformation &Item)
{
	SBCheckError(TElVFSEntryInformationList_Add(_Handle, Item.getHandle()));
}

SB_INLINE void TElVFSEntryInformationList::Add(TElVFSEntryInformation *Item)
{
	SBCheckError(TElVFSEntryInformationList_Add(_Handle, (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

SB_INLINE void TElVFSEntryInformationList::Remove(int32_t Index)
{
	SBCheckError(TElVFSEntryInformationList_Remove(_Handle, Index));
}

SB_INLINE int32_t TElVFSEntryInformationList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElVFSEntryInformationList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
TElVFSEntryInformation* TElVFSEntryInformationList::get_Item(int32_t index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElVFSEntryInformationList_get_Item(_Handle, index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElVFSEntryInformation(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

void TElVFSEntryInformationList::initInstances()
{
#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */
}

TElVFSEntryInformationList::TElVFSEntryInformationList(TElVFSEntryInformationListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElVFSEntryInformationList::TElVFSEntryInformationList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElVFSEntryInformationList_Create(&_Handle));
}

TElVFSEntryInformationList::~TElVFSEntryInformationList()
{
#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER

SB_INLINE TElCustomFileSystemAdapterHandle TElCustomFileSystemAdapter::Clone()
{
	TElCustomFileSystemAdapterHandle OutResult;
	SBCheckError(TElCustomFileSystemAdapter_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElCustomFileSystemAdapter::NameMatchesMask(const std::string &Path, const std::string &Mask)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomFileSystemAdapter_NameMatchesMask(_Handle, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
int32_t TElCustomFileSystemAdapter::GetFileStream(const std::string &Path, uint32_t OpenMode, TSBFileShareMode ShareMode, TStream &FileStream)
{
	int32_t OutResult;
	TElClassHandle hFileStream = FileStream.getHandle();
	SBCheckError(TElCustomFileSystemAdapter_GetFileStream(_Handle, Path.data(), (int32_t)Path.length(), OpenMode, (TSBFileShareModeRaw)ShareMode, &hFileStream, &OutResult));
	FileStream.updateHandle(hFileStream);
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

int32_t TElCustomFileSystemAdapter::FileOpen(const std::string &Path, uint32_t OpenMode, TSBFileShareMode ShareMode, TObject &FileHandle)
{
	int32_t OutResult;
	TElClassHandle hFileHandle = FileHandle.getHandle();
	SBCheckError(TElCustomFileSystemAdapter_FileOpen(_Handle, Path.data(), (int32_t)Path.length(), OpenMode, (TSBFileShareModeRaw)ShareMode, &hFileHandle, &OutResult));
	FileHandle.updateHandle(hFileHandle);
	return OutResult;
}

SB_INLINE void TElCustomFileSystemAdapter::FileClose(TObject &FileHandle)
{
	SBCheckError(TElCustomFileSystemAdapter_FileClose(_Handle, FileHandle.getHandle()));
}

SB_INLINE void TElCustomFileSystemAdapter::FileClose(TObject *FileHandle)
{
	SBCheckError(TElCustomFileSystemAdapter_FileClose(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElCustomFileSystemAdapter::CloseAllFiles()
{
	SBCheckError(TElCustomFileSystemAdapter_CloseAllFiles(_Handle));
}

bool TElCustomFileSystemAdapter::FileExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomFileSystemAdapter_FileExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomFileSystemAdapter::DirectoryExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomFileSystemAdapter_DirectoryExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileRead(TObject &FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileRead(_Handle, FileHandle.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileRead(TObject *FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileRead(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileWrite(TObject &FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileWrite(_Handle, FileHandle.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileWrite(TObject *FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileWrite(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomFileSystemAdapter::FileGetSize(TObject &FileHandle)
{
	int64_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileGetSize(_Handle, FileHandle.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomFileSystemAdapter::FileGetSize(TObject *FileHandle)
{
	int64_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileGetSize(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomFileSystemAdapter::FileSetSize(TObject &FileHandle, int64_t NewSize)
{
	SBCheckError(TElCustomFileSystemAdapter_FileSetSize(_Handle, FileHandle.getHandle(), NewSize));
}

SB_INLINE void TElCustomFileSystemAdapter::FileSetSize(TObject *FileHandle, int64_t NewSize)
{
	SBCheckError(TElCustomFileSystemAdapter_FileSetSize(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, NewSize));
}

SB_INLINE int64_t TElCustomFileSystemAdapter::FileGetPosition(TObject &FileHandle)
{
	int64_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileGetPosition(_Handle, FileHandle.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomFileSystemAdapter::FileGetPosition(TObject *FileHandle)
{
	int64_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileGetPosition(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomFileSystemAdapter::FileSeek(TObject &FileHandle, int64_t Position, TSBFileSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileSeek(_Handle, FileHandle.getHandle(), Position, (TSBFileSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomFileSystemAdapter::FileSeek(TObject *FileHandle, int64_t Position, TSBFileSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileSeek(_Handle, (FileHandle != NULL) ? FileHandle->getHandle() : SB_NULL_HANDLE, Position, (TSBFileSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileGetTimes(const std::string &Path, int64_t &CreationTime, int64_t &ModificationTime, int64_t &LastAccessTime)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileGetTimes(_Handle, Path.data(), (int32_t)Path.length(), &CreationTime, &ModificationTime, &LastAccessTime, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileSetTimes(const std::string &Path, int64_t CreationTime, int64_t ModificationTime, int64_t LastAccessTime)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileSetTimes(_Handle, Path.data(), (int32_t)Path.length(), CreationTime, ModificationTime, LastAccessTime, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileDelete(const std::string &Path)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileDelete(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileMove(const std::string &FromName, const std::string &ToName)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileMove(_Handle, FromName.data(), (int32_t)FromName.length(), ToName.data(), (int32_t)ToName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::FileCopy(const std::string &FromName, const std::string &ToName)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_FileCopy(_Handle, FromName.data(), (int32_t)FromName.length(), ToName.data(), (int32_t)ToName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::WriteFileTag(const std::string &Path, const std::string &TagName, const std::string &TagValue)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_WriteFileTag(_Handle, Path.data(), (int32_t)Path.length(), TagName.data(), (int32_t)TagName.length(), TagValue.data(), (int32_t)TagValue.length(), &OutResult));
	return OutResult;
}

int32_t TElCustomFileSystemAdapter::ReadFileTag(const std::string &Path, const std::string &TagName, std::string &TagValue)
{
	int32_t OutResult;
	int32_t szTagValue = (int32_t)TagValue.length();
	uint32_t _err = TElCustomFileSystemAdapter_ReadFileTag(_Handle, Path.data(), (int32_t)Path.length(), TagName.data(), (int32_t)TagName.length(), (char *)TagValue.data(), &szTagValue, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		TagValue.resize(szTagValue);
		SBCheckError(SBGetLastReturnStringA(1753297687, 3, (char *)TagValue.data(), &szTagValue));
	}
	else
		SBCheckError(_err);

	TagValue.resize(szTagValue);
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::DeleteFileTag(const std::string &Path, const std::string &TagName)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_DeleteFileTag(_Handle, Path.data(), (int32_t)Path.length(), TagName.data(), (int32_t)TagName.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::DirectoryMake(const std::string &Path)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_DirectoryMake(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::DirectoryRemove(const std::string &Path)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_DirectoryRemove(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
int32_t TElCustomFileSystemAdapter::EnumDirectoryEntries(const std::string &Path, const std::string &Mask, bool Recursive, TElVFSEntryInformationList &EntryInfos)
{
	int32_t OutResult;
	TElClassHandle hEntryInfos = SB_NULL_HANDLE;
	SBCheckError(TElCustomFileSystemAdapter_EnumDirectoryEntries(_Handle, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), (int8_t)Recursive, &hEntryInfos, &OutResult));
	EntryInfos.updateHandle(hEntryInfos);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
SB_INLINE int32_t TElCustomFileSystemAdapter::GetEntryInformation(const std::string &Path, TElVFSEntryInformation &EntryInfo)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_GetEntryInformation(_Handle, Path.data(), (int32_t)Path.length(), EntryInfo.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::GetEntryInformation(const std::string &Path, TElVFSEntryInformation *EntryInfo)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_GetEntryInformation(_Handle, Path.data(), (int32_t)Path.length(), (EntryInfo != NULL) ? EntryInfo->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
SB_INLINE int32_t TElCustomFileSystemAdapter::SetEntryInformation(const std::string &Path, TElVFSEntryInformation &EntryInfo, int32_t InfoFlags)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_SetEntryInformation(_Handle, Path.data(), (int32_t)Path.length(), EntryInfo.getHandle(), InfoFlags, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomFileSystemAdapter::SetEntryInformation(const std::string &Path, TElVFSEntryInformation *EntryInfo, int32_t InfoFlags)
{
	int32_t OutResult;
	SBCheckError(TElCustomFileSystemAdapter_SetEntryInformation(_Handle, Path.data(), (int32_t)Path.length(), (EntryInfo != NULL) ? EntryInfo->getHandle() : SB_NULL_HANDLE, InfoFlags, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

bool TElCustomFileSystemAdapter::IsAccessible()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomFileSystemAdapter_IsAccessible(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomFileSystemAdapter::get_CaseSensitive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomFileSystemAdapter_get_CaseSensitive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomFileSystemAdapter::set_CaseSensitive(bool Value)
{
	SBCheckError(TElCustomFileSystemAdapter_set_CaseSensitive(_Handle, (int8_t)Value));
}

void TElCustomFileSystemAdapter::get_BasePath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomFileSystemAdapter_get_BasePath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1559100536, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomFileSystemAdapter::set_BasePath(const std::string &Value)
{
	SBCheckError(TElCustomFileSystemAdapter_set_BasePath(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE char TElCustomFileSystemAdapter::get_PathSeparator()
{
	char OutResult;
	SBCheckError(TElCustomFileSystemAdapter_get_PathSeparator(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomFileSystemAdapter::set_PathSeparator(char Value)
{
	SBCheckError(TElCustomFileSystemAdapter_set_PathSeparator(_Handle, Value));
}

SB_INLINE char TElCustomFileSystemAdapter::get_PathSeparator2()
{
	char OutResult;
	SBCheckError(TElCustomFileSystemAdapter_get_PathSeparator2(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomFileSystemAdapter::set_PathSeparator2(char Value)
{
	SBCheckError(TElCustomFileSystemAdapter_set_PathSeparator2(_Handle, Value));
}

TElCustomFileSystemAdapter::TElCustomFileSystemAdapter(TElCustomFileSystemAdapterHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElCustomFileSystemAdapter::TElCustomFileSystemAdapter(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomFileSystemAdapter_Create(AOwner.getHandle(), &_Handle));
}

TElCustomFileSystemAdapter::TElCustomFileSystemAdapter(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomFileSystemAdapter_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_GLOBAL_PROCS_CUSTOMFSADAPTER

SB_INLINE void RaiseVFSAdapterError(int32_t ErrorCode, const std::string &FileName)
{
	SBCheckError(SBCustomFSAdapter_RaiseVFSAdapterError(ErrorCode, FileName.data(), (int32_t)FileName.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
SB_INLINE void RaiseVFSAdapterErrorEx(TElCustomFileSystemAdapter &Adapter, int32_t ErrorCode, const std::string &FileName)
{
	SBCheckError(SBCustomFSAdapter_RaiseVFSAdapterErrorEx(Adapter.getHandle(), ErrorCode, FileName.data(), (int32_t)FileName.length()));
}
SB_INLINE void RaiseVFSAdapterErrorEx(TElCustomFileSystemAdapter *Adapter, int32_t ErrorCode, const std::string &FileName)
{
	SBCheckError(SBCustomFSAdapter_RaiseVFSAdapterErrorEx((Adapter != NULL) ? Adapter->getHandle() : SB_NULL_HANDLE, ErrorCode, FileName.data(), (int32_t)FileName.length()));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#endif /* SB_USE_GLOBAL_PROCS_CUSTOMFSADAPTER */

};	/* namespace SecureBlackbox */

