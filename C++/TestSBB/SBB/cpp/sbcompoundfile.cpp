#include "sbcompoundfile.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE

SB_INLINE void TElCompoundFileStorage::CreateNew(const std::string &FileName, int32_t Version)
{
	SBCheckError(TElCompoundFileStorage_CreateNew(_Handle, FileName.data(), (int32_t)FileName.length(), Version));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCompoundFileStorage::CreateNew(TStream &Stream, int32_t Version)
{
	SBCheckError(TElCompoundFileStorage_CreateNew_1(_Handle, Stream.getHandle(), Version));
}

SB_INLINE void TElCompoundFileStorage::CreateNew(TStream *Stream, int32_t Version)
{
	SBCheckError(TElCompoundFileStorage_CreateNew_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Version));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCompoundFileStorage::CreateNew(TStream &Stream, int32_t Version, bool OwnStream)
{
	SBCheckError(TElCompoundFileStorage_CreateNew_2(_Handle, Stream.getHandle(), Version, (int8_t)OwnStream));
}

SB_INLINE void TElCompoundFileStorage::CreateNew(TStream *Stream, int32_t Version, bool OwnStream)
{
	SBCheckError(TElCompoundFileStorage_CreateNew_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Version, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElCompoundFileStorage::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElCompoundFileStorage_Open(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCompoundFileStorage::Open(TStream &Stream)
{
	SBCheckError(TElCompoundFileStorage_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElCompoundFileStorage::Open(TStream *Stream)
{
	SBCheckError(TElCompoundFileStorage_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCompoundFileStorage::Open(TStream &Stream, bool OwnStream)
{
	SBCheckError(TElCompoundFileStorage_Open_2(_Handle, Stream.getHandle(), (int8_t)OwnStream));
}

SB_INLINE void TElCompoundFileStorage::Open(TStream *Stream, bool OwnStream)
{
	SBCheckError(TElCompoundFileStorage_Open_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCompoundFileStorage::Open(TStream &Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElCompoundFileStorage_Open_3(_Handle, Stream.getHandle(), (int8_t)OwnStream, (int8_t)ReadOnly));
}

SB_INLINE void TElCompoundFileStorage::Open(TStream *Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElCompoundFileStorage_Open_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (int8_t)ReadOnly));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElCompoundFileStorage::Close()
{
	SBCheckError(TElCompoundFileStorage_Close(_Handle));
}

SB_INLINE void TElCompoundFileStorage::Flush()
{
	SBCheckError(TElCompoundFileStorage_Flush(_Handle));
}

SB_INLINE int32_t TElCompoundFileStorage::get_FileVersion()
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileStorage_get_FileVersion(_Handle, &OutResult));
	return OutResult;
}

bool TElCompoundFileStorage::get_IsReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCompoundFileStorage_get_IsReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElCompoundFileStorage::get_SectorSize()
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileStorage_get_SectorSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCompoundFileStorage::get_MiniSectorSize()
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileStorage_get_MiniSectorSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElCompoundFileStorage::get_MiniSectorCutoffSize()
{
	uint32_t OutResult;
	SBCheckError(TElCompoundFileStorage_get_MiniSectorCutoffSize(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
TElCompoundFileStorageEntry* TElCompoundFileStorage::get_RootEntry()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCompoundFileStorage_get_RootEntry(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RootEntry)
		this->_Inst_RootEntry = new TElCompoundFileStorageEntry(hOutResult, ohFalse);
	else
		this->_Inst_RootEntry->updateHandle(hOutResult);
	return this->_Inst_RootEntry;
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

void TElCompoundFileStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
	this->_Inst_RootEntry = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */
}

TElCompoundFileStorage::TElCompoundFileStorage(TElCompoundFileStorageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCompoundFileStorage::TElCompoundFileStorage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCompoundFileStorage_Create(&_Handle));
}

TElCompoundFileStorage::~TElCompoundFileStorage()
{
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
	delete this->_Inst_RootEntry;
	this->_Inst_RootEntry = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILECUSTOMENTRY

void TElCompoundFileCustomEntry::get_Name(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCompoundFileCustomEntry_get_Name(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(398956327, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElCompoundFileCustomEntry::get_Name(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElCompoundFileCustomEntry_get_Name(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(398956327, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElCompoundFileCustomEntry::set_Name(const sb_u16string &Value)
{
	SBCheckError(TElCompoundFileCustomEntry_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElCompoundFileCustomEntry::set_Name(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElCompoundFileCustomEntry_set_Name(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
TElCompoundFileStorageEntry* TElCompoundFileCustomEntry::get_Parent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCompoundFileCustomEntry_get_Parent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parent)
		this->_Inst_Parent = new TElCompoundFileStorageEntry(hOutResult, ohFalse);
	else
		this->_Inst_Parent->updateHandle(hOutResult);
	return this->_Inst_Parent;
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
TElCompoundFileStorage* TElCompoundFileCustomEntry::get_Storage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCompoundFileCustomEntry_get_Storage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Storage)
		this->_Inst_Storage = new TElCompoundFileStorage(hOutResult, ohFalse);
	else
		this->_Inst_Storage->updateHandle(hOutResult);
	return this->_Inst_Storage;
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

void TElCompoundFileCustomEntry::initInstances()
{
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
	this->_Inst_Parent = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */
}

TElCompoundFileCustomEntry::TElCompoundFileCustomEntry(TElCompoundFileCustomEntryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCompoundFileCustomEntry::TElCompoundFileCustomEntry() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCompoundFileCustomEntry_Create(&_Handle));
}

TElCompoundFileCustomEntry::~TElCompoundFileCustomEntry()
{
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
	delete this->_Inst_Parent;
	this->_Inst_Parent = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
	delete this->_Inst_Storage;
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILECUSTOMENTRY */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
SB_INLINE TElCompoundFileStreamEntryHandle TElCompoundFileStorageEntry::CreateStream(const sb_u16string &StreamName)
{
	TElCompoundFileStreamEntryHandle OutResult;
	SBCheckError(TElCompoundFileStorageEntry_CreateStream(_Handle, StreamName.data(), (int32_t)StreamName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElCompoundFileStreamEntryHandle TElCompoundFileStorageEntry::CreateStream(const std::wstring &StreamName)
{
	TElCompoundFileStreamEntryHandle OutResult;
	std::string u16StreamName;
	sb_to_u16string(StreamName, u16StreamName);
	SBCheckError(TElCompoundFileStorageEntry_CreateStream(_Handle, reinterpret_cast<const sb_char16_t*>(u16StreamName.data()), (int32_t)u16StreamName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */

SB_INLINE TElCompoundFileStorageEntryHandle TElCompoundFileStorageEntry::CreateSubStorage(const sb_u16string &StorageName)
{
	TElCompoundFileStorageEntryHandle OutResult;
	SBCheckError(TElCompoundFileStorageEntry_CreateSubStorage(_Handle, StorageName.data(), (int32_t)StorageName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElCompoundFileStorageEntryHandle TElCompoundFileStorageEntry::CreateSubStorage(const std::wstring &StorageName)
{
	TElCompoundFileStorageEntryHandle OutResult;
	std::string u16StorageName;
	sb_to_u16string(StorageName, u16StorageName);
	SBCheckError(TElCompoundFileStorageEntry_CreateSubStorage(_Handle, reinterpret_cast<const sb_char16_t*>(u16StorageName.data()), (int32_t)u16StorageName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElCompoundFileStorageEntry::DeleteStream(const sb_u16string &StreamName)
{
	SBCheckError(TElCompoundFileStorageEntry_DeleteStream(_Handle, StreamName.data(), (int32_t)StreamName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElCompoundFileStorageEntry::DeleteStream(const std::wstring &StreamName)
{
	std::string u16StreamName;
	sb_to_u16string(StreamName, u16StreamName);
	SBCheckError(TElCompoundFileStorageEntry_DeleteStream(_Handle, reinterpret_cast<const sb_char16_t*>(u16StreamName.data()), (int32_t)u16StreamName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElCompoundFileStorageEntry::DeleteSubStorage(const sb_u16string &StorageName)
{
	SBCheckError(TElCompoundFileStorageEntry_DeleteSubStorage(_Handle, StorageName.data(), (int32_t)StorageName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElCompoundFileStorageEntry::DeleteSubStorage(const std::wstring &StorageName)
{
	std::string u16StorageName;
	sb_to_u16string(StorageName, u16StorageName);
	SBCheckError(TElCompoundFileStorageEntry_DeleteSubStorage(_Handle, reinterpret_cast<const sb_char16_t*>(u16StorageName.data()), (int32_t)u16StorageName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
SB_INLINE TElCompoundFileStreamEntryHandle TElCompoundFileStorageEntry::GetStream(const sb_u16string &StreamName)
{
	TElCompoundFileStreamEntryHandle OutResult;
	SBCheckError(TElCompoundFileStorageEntry_GetStream(_Handle, StreamName.data(), (int32_t)StreamName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElCompoundFileStreamEntryHandle TElCompoundFileStorageEntry::GetStream(const std::wstring &StreamName)
{
	TElCompoundFileStreamEntryHandle OutResult;
	std::string u16StreamName;
	sb_to_u16string(StreamName, u16StreamName);
	SBCheckError(TElCompoundFileStorageEntry_GetStream(_Handle, reinterpret_cast<const sb_char16_t*>(u16StreamName.data()), (int32_t)u16StreamName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */

SB_INLINE TElCompoundFileStorageEntryHandle TElCompoundFileStorageEntry::GetSubStorage(const sb_u16string &StorageName)
{
	TElCompoundFileStorageEntryHandle OutResult;
	SBCheckError(TElCompoundFileStorageEntry_GetSubStorage(_Handle, StorageName.data(), (int32_t)StorageName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElCompoundFileStorageEntryHandle TElCompoundFileStorageEntry::GetSubStorage(const std::wstring &StorageName)
{
	TElCompoundFileStorageEntryHandle OutResult;
	std::string u16StorageName;
	sb_to_u16string(StorageName, u16StorageName);
	SBCheckError(TElCompoundFileStorageEntry_GetSubStorage(_Handle, reinterpret_cast<const sb_char16_t*>(u16StorageName.data()), (int32_t)u16StorageName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE TElCompoundFileCustomEntryHandle TElCompoundFileStorageEntry::FindEntryByName(const sb_u16string &EntryName)
{
	TElCompoundFileCustomEntryHandle OutResult;
	SBCheckError(TElCompoundFileStorageEntry_FindEntryByName(_Handle, EntryName.data(), (int32_t)EntryName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElCompoundFileCustomEntryHandle TElCompoundFileStorageEntry::FindEntryByName(const std::wstring &EntryName)
{
	TElCompoundFileCustomEntryHandle OutResult;
	std::string u16EntryName;
	sb_to_u16string(EntryName, u16EntryName);
	SBCheckError(TElCompoundFileStorageEntry_FindEntryByName(_Handle, reinterpret_cast<const sb_char16_t*>(u16EntryName.data()), (int32_t)u16EntryName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

bool TElCompoundFileStorageEntry::StreamExists(const sb_u16string &StreamName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCompoundFileStorageEntry_StreamExists(_Handle, StreamName.data(), (int32_t)StreamName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElCompoundFileStorageEntry::StreamExists(const std::wstring &StreamName)
{
	std::string u16StreamName;
	sb_to_u16string(StreamName, u16StreamName);
	int8_t OutResultRaw = 0;
	SBCheckError(TElCompoundFileStorageEntry_StreamExists(_Handle, reinterpret_cast<const sb_char16_t*>(u16StreamName.data()), (int32_t)u16StreamName.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElCompoundFileStorageEntry::SubStorageExists(const sb_u16string &StorageName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCompoundFileStorageEntry_SubStorageExists(_Handle, StorageName.data(), (int32_t)StorageName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElCompoundFileStorageEntry::SubStorageExists(const std::wstring &StorageName)
{
	std::string u16StorageName;
	sb_to_u16string(StorageName, u16StorageName);
	int8_t OutResultRaw = 0;
	SBCheckError(TElCompoundFileStorageEntry_SubStorageExists(_Handle, reinterpret_cast<const sb_char16_t*>(u16StorageName.data()), (int32_t)u16StorageName.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE TElCompoundFileCustomEntryHandle TElCompoundFileStorageEntry::GetFirstChild()
{
	TElCompoundFileCustomEntryHandle OutResult;
	SBCheckError(TElCompoundFileStorageEntry_GetFirstChild(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElCompoundFileCustomEntryHandle TElCompoundFileStorageEntry::GetNextEntry(TElCompoundFileCustomEntry &Last)
{
	TElCompoundFileCustomEntryHandle OutResult;
	SBCheckError(TElCompoundFileStorageEntry_GetNextEntry(_Handle, Last.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCompoundFileCustomEntryHandle TElCompoundFileStorageEntry::GetNextEntry(TElCompoundFileCustomEntry *Last)
{
	TElCompoundFileCustomEntryHandle OutResult;
	SBCheckError(TElCompoundFileStorageEntry_GetNextEntry(_Handle, (Last != NULL) ? Last->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TElCompoundFileStorageEntry::get_CLSID(TGuid &OutResult)
{
	SBCheckError(TElCompoundFileStorageEntry_get_CLSID(_Handle, &OutResult));
}

SB_INLINE void TElCompoundFileStorageEntry::set_CLSID(TGuid &Value)
{
	SBCheckError(TElCompoundFileStorageEntry_set_CLSID(_Handle, &Value));
}

SB_INLINE int64_t TElCompoundFileStorageEntry::get_CreationTime()
{
	int64_t OutResult;
	SBCheckError(TElCompoundFileStorageEntry_get_CreationTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCompoundFileStorageEntry::set_CreationTime(int64_t Value)
{
	SBCheckError(TElCompoundFileStorageEntry_set_CreationTime(_Handle, Value));
}

SB_INLINE int64_t TElCompoundFileStorageEntry::get_ModifiedTime()
{
	int64_t OutResult;
	SBCheckError(TElCompoundFileStorageEntry_get_ModifiedTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCompoundFileStorageEntry::set_ModifiedTime(int64_t Value)
{
	SBCheckError(TElCompoundFileStorageEntry_set_ModifiedTime(_Handle, Value));
}

TElCompoundFileStorageEntry::TElCompoundFileStorageEntry(TElCompoundFileStorageEntryHandle handle, TElOwnHandle ownHandle) : TElCompoundFileCustomEntry(handle, ownHandle)
{
}

TElCompoundFileStorageEntry::TElCompoundFileStorageEntry() : TElCompoundFileCustomEntry(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileStorageEntry_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM

SB_INLINE void TElCompoundFileVirtualStream::Flush()
{
	SBCheckError(TElCompoundFileVirtualStream_Flush(_Handle));
}

SB_INLINE void TElCompoundFileVirtualStream::Close()
{
	SBCheckError(TElCompoundFileVirtualStream_Close(_Handle));
}

SB_INLINE void TElCompoundFileVirtualStream::Close(bool FlushData)
{
	SBCheckError(TElCompoundFileVirtualStream_Close_1(_Handle, (int8_t)FlushData));
}

SB_INLINE int32_t TElCompoundFileVirtualStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileVirtualStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCompoundFileVirtualStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileVirtualStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCompoundFileVirtualStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileVirtualStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCompoundFileVirtualStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElCompoundFileVirtualStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

bool TElCompoundFileVirtualStream::get_IsMiniStream()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCompoundFileVirtualStream_get_IsMiniStream(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElCompoundFileVirtualStream::TElCompoundFileVirtualStream(TElCompoundFileVirtualStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
TElCompoundFileVirtualStream::TElCompoundFileVirtualStream(TElCompoundFileStorage &Storage) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileVirtualStream_Create(Storage.getHandle(), &_Handle));
}

TElCompoundFileVirtualStream::TElCompoundFileVirtualStream(TElCompoundFileStorage *Storage) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileVirtualStream_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY
TElCompoundFileVirtualStream::TElCompoundFileVirtualStream(TElCompoundFileStorage &Storage, TElCompoundFileStreamEntry &StreamEntry) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileVirtualStream_Create_1(Storage.getHandle(), StreamEntry.getHandle(), &_Handle));
}

TElCompoundFileVirtualStream::TElCompoundFileVirtualStream(TElCompoundFileStorage *Storage, TElCompoundFileStreamEntry *StreamEntry) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileVirtualStream_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, (StreamEntry != NULL) ? StreamEntry->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY */

#endif /* SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILETABLESTREAM

SB_INLINE int32_t TElCompoundFileTableStream::Read(uint32_t &Value)
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileTableStream_Read(_Handle, &Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCompoundFileTableStream::Write(uint32_t Value)
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileTableStream_Write(_Handle, Value, &OutResult));
	return OutResult;
}

TElCompoundFileTableStream::TElCompoundFileTableStream(TElCompoundFileTableStreamHandle handle, TElOwnHandle ownHandle) : TElCompoundFileVirtualStream(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
TElCompoundFileTableStream::TElCompoundFileTableStream(TElCompoundFileStorage &Storage) : TElCompoundFileVirtualStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileTableStream_Create(Storage.getHandle(), &_Handle));
}

TElCompoundFileTableStream::TElCompoundFileTableStream(TElCompoundFileStorage *Storage) : TElCompoundFileVirtualStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileTableStream_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY
TElCompoundFileTableStream::TElCompoundFileTableStream(TElCompoundFileStorage &Storage, TElCompoundFileStreamEntry &StreamEntry) : TElCompoundFileVirtualStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileTableStream_Create_1(Storage.getHandle(), StreamEntry.getHandle(), &_Handle));
}

TElCompoundFileTableStream::TElCompoundFileTableStream(TElCompoundFileStorage *Storage, TElCompoundFileStreamEntry *StreamEntry) : TElCompoundFileVirtualStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileTableStream_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, (StreamEntry != NULL) ? StreamEntry->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY */

#endif /* SB_USE_CLASS_TELCOMPOUNDFILETABLESTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILEDIRECTORYSTREAM

SB_INLINE int32_t TElCompoundFileDirectoryStream::Read(TSBCompoundFileDirectoryEntry &Value)
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileDirectoryStream_Read(_Handle, &Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCompoundFileDirectoryStream::Write(const TSBCompoundFileDirectoryEntry &Value)
{
	int32_t OutResult;
	SBCheckError(TElCompoundFileDirectoryStream_Write(_Handle, &Value, &OutResult));
	return OutResult;
}

TElCompoundFileDirectoryStream::TElCompoundFileDirectoryStream(TElCompoundFileDirectoryStreamHandle handle, TElOwnHandle ownHandle) : TElCompoundFileVirtualStream(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
TElCompoundFileDirectoryStream::TElCompoundFileDirectoryStream(TElCompoundFileStorage &Storage) : TElCompoundFileVirtualStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileDirectoryStream_Create(Storage.getHandle(), &_Handle));
}

TElCompoundFileDirectoryStream::TElCompoundFileDirectoryStream(TElCompoundFileStorage *Storage) : TElCompoundFileVirtualStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileDirectoryStream_Create((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY
TElCompoundFileDirectoryStream::TElCompoundFileDirectoryStream(TElCompoundFileStorage &Storage, TElCompoundFileStreamEntry &StreamEntry) : TElCompoundFileVirtualStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileDirectoryStream_Create_1(Storage.getHandle(), StreamEntry.getHandle(), &_Handle));
}

TElCompoundFileDirectoryStream::TElCompoundFileDirectoryStream(TElCompoundFileStorage *Storage, TElCompoundFileStreamEntry *StreamEntry) : TElCompoundFileVirtualStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCompoundFileDirectoryStream_Create_1((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, (StreamEntry != NULL) ? StreamEntry->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY */

#endif /* SB_USE_CLASS_TELCOMPOUNDFILEDIRECTORYSTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY

#ifdef SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM
TElCompoundFileVirtualStream* TElCompoundFileStreamEntry::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCompoundFileStreamEntry_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TElCompoundFileVirtualStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM */

void TElCompoundFileStreamEntry::initInstances()
{
#ifdef SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM */
}

TElCompoundFileStreamEntry::TElCompoundFileStreamEntry(TElCompoundFileStreamEntryHandle handle, TElOwnHandle ownHandle) : TElCompoundFileCustomEntry(handle, ownHandle)
{
	initInstances();
}

TElCompoundFileStreamEntry::TElCompoundFileStreamEntry() : TElCompoundFileCustomEntry(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCompoundFileStreamEntry_Create(&_Handle));
}

TElCompoundFileStreamEntry::~TElCompoundFileStreamEntry()
{
#ifdef SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM */
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */

#ifdef SB_USE_GLOBAL_PROCS_COMPOUNDFILE

bool IsValidDirectoryEntryName(const sb_u16string &EntryName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCompoundFile_IsValidDirectoryEntryName(EntryName.data(), (int32_t)EntryName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool IsValidDirectoryEntryName(const std::wstring &EntryName)
{
	std::string u16EntryName;
	sb_to_u16string(EntryName, u16EntryName);
	int8_t OutResultRaw = 0;
	SBCheckError(SBCompoundFile_IsValidDirectoryEntryName(reinterpret_cast<const sb_char16_t*>(u16EntryName.data()), (int32_t)u16EntryName.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t CompareDirectoryEntryNames(const sb_u16string &X, const sb_u16string &Y)
{
	int32_t OutResult;
	SBCheckError(SBCompoundFile_CompareDirectoryEntryNames(X.data(), (int32_t)X.length(), Y.data(), (int32_t)Y.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t CompareDirectoryEntryNames(const std::wstring &X, const std::wstring &Y)
{
	int32_t OutResult;
	std::string u16X;
	sb_to_u16string(X, u16X);
	std::string u16Y;
	sb_to_u16string(Y, u16Y);
	SBCheckError(SBCompoundFile_CompareDirectoryEntryNames(reinterpret_cast<const sb_char16_t*>(u16X.data()), (int32_t)u16X.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Y.data()), (int32_t)u16Y.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
SB_INLINE void CopyStorage(TElCompoundFileStorageEntry &SourceStorage, TElCompoundFileStorageEntry &DestStorage)
{
	SBCheckError(SBCompoundFile_CopyStorage(SourceStorage.getHandle(), DestStorage.getHandle()));
}
SB_INLINE void CopyStorage(TElCompoundFileStorageEntry *SourceStorage, TElCompoundFileStorageEntry *DestStorage)
{
	SBCheckError(SBCompoundFile_CopyStorage((SourceStorage != NULL) ? SourceStorage->getHandle() : SB_NULL_HANDLE, (DestStorage != NULL) ? DestStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

#endif /* SB_USE_GLOBAL_PROCS_COMPOUNDFILE */

};	/* namespace SecureBlackbox */

