#include "sbarctar.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY

SB_INLINE void TElTarArchiveDirectoryEntry::Clear()
{
	SBCheckError(TElTarArchiveDirectoryEntry_Clear(_Handle));
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarArchiveDirectoryEntry::AddEntry(const std::string &APath)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarArchiveDirectoryEntry_AddEntry(_Handle, APath.data(), (int32_t)APath.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarArchiveDirectoryEntry::AddNewEntry(const std::string &APath)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarArchiveDirectoryEntry_AddNewEntry(_Handle, APath.data(), (int32_t)APath.length(), &OutResult));
	return OutResult;
}

bool TElTarArchiveDirectoryEntry::RemoveEntry(TElTarArchiveDirectoryEntry &Entry)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarArchiveDirectoryEntry_RemoveEntry(_Handle, Entry.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElTarArchiveDirectoryEntry::RemoveEntry(TElTarArchiveDirectoryEntry *Entry)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarArchiveDirectoryEntry_RemoveEntry(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElTarArchiveDirectoryEntry::RemoveEntry(const std::string &APath)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarArchiveDirectoryEntry_RemoveEntry_1(_Handle, APath.data(), (int32_t)APath.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElTarArchiveDirectoryEntry::RemoveEntry(const std::string &APath, bool CaseSensitive)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarArchiveDirectoryEntry_RemoveEntry_2(_Handle, APath.data(), (int32_t)APath.length(), (int8_t)CaseSensitive, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarArchiveDirectoryEntry::ClearEntries()
{
	SBCheckError(TElTarArchiveDirectoryEntry_ClearEntries(_Handle));
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarArchiveDirectoryEntry::EntryWithName(const std::string &AName)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarArchiveDirectoryEntry_EntryWithName(_Handle, AName.data(), (int32_t)AName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarArchiveDirectoryEntry::EntryWithName(const std::string &AName, bool CaseSensitive)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarArchiveDirectoryEntry_EntryWithName_1(_Handle, AName.data(), (int32_t)AName.length(), (int8_t)CaseSensitive, &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarArchiveDirectoryEntry::EntryWithPath(const std::string &APath)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarArchiveDirectoryEntry_EntryWithPath(_Handle, APath.data(), (int32_t)APath.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarArchiveDirectoryEntry::EntryWithPath(const std::string &APath, bool CaseSensitive)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarArchiveDirectoryEntry_EntryWithPath_1(_Handle, APath.data(), (int32_t)APath.length(), (int8_t)CaseSensitive, &OutResult));
	return OutResult;
}

TElTarArchiveDirectoryEntry* TElTarArchiveDirectoryEntry::get_Parent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarArchiveDirectoryEntry_get_Parent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parent)
		this->_Inst_Parent = new TElTarArchiveDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_Parent->updateHandle(hOutResult);
	return this->_Inst_Parent;
}

TElTarArchiveDirectoryEntry* TElTarArchiveDirectoryEntry::get_Entries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarArchiveDirectoryEntry_get_Entries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Entries)
		this->_Inst_Entries = new TElTarArchiveDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_Entries->updateHandle(hOutResult);
	return this->_Inst_Entries;
}

void TElTarArchiveDirectoryEntry::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarArchiveDirectoryEntry_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-178603070, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElTarArchiveDirectoryEntry::get_LocalHeaderOffset()
{
	int64_t OutResult;
	SBCheckError(TElTarArchiveDirectoryEntry_get_LocalHeaderOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarArchiveDirectoryEntry::set_LocalHeaderOffset(int64_t Value)
{
	SBCheckError(TElTarArchiveDirectoryEntry_set_LocalHeaderOffset(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELTARFILEATTRIBUTES
TElTarFileAttributes* TElTarArchiveDirectoryEntry::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarArchiveDirectoryEntry_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElTarFileAttributes(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELTARFILEATTRIBUTES */

SB_INLINE uint32_t TElTarArchiveDirectoryEntry::get_CheckSum()
{
	uint32_t OutResult;
	SBCheckError(TElTarArchiveDirectoryEntry_get_CheckSum(_Handle, &OutResult));
	return OutResult;
}

bool TElTarArchiveDirectoryEntry::get_Process()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarArchiveDirectoryEntry_get_Process(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarArchiveDirectoryEntry::set_Process(bool Value)
{
	SBCheckError(TElTarArchiveDirectoryEntry_set_Process(_Handle, (int8_t)Value));
}

void TElTarArchiveDirectoryEntry::get_ExtractionPath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarArchiveDirectoryEntry_get_ExtractionPath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-511913171, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTarArchiveDirectoryEntry::set_ExtractionPath(const std::string &Value)
{
	SBCheckError(TElTarArchiveDirectoryEntry_set_ExtractionPath(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElTarArchiveDirectoryEntry::get_ExtractionStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarArchiveDirectoryEntry_get_ExtractionStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtractionStream)
		this->_Inst_ExtractionStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_ExtractionStream->updateHandle(hOutResult);
	return this->_Inst_ExtractionStream;
}

SB_INLINE void TElTarArchiveDirectoryEntry::set_ExtractionStream(TStream &Value)
{
	SBCheckError(TElTarArchiveDirectoryEntry_set_ExtractionStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElTarArchiveDirectoryEntry::set_ExtractionStream(TStream *Value)
{
	SBCheckError(TElTarArchiveDirectoryEntry_set_ExtractionStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElTarArchiveDirectoryEntry::get_InputStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarArchiveDirectoryEntry_get_InputStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InputStream)
		this->_Inst_InputStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_InputStream->updateHandle(hOutResult);
	return this->_Inst_InputStream;
}

SB_INLINE void TElTarArchiveDirectoryEntry::set_InputStream(TStream &Value)
{
	SBCheckError(TElTarArchiveDirectoryEntry_set_InputStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElTarArchiveDirectoryEntry::set_InputStream(TStream *Value)
{
	SBCheckError(TElTarArchiveDirectoryEntry_set_InputStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElTarArchiveDirectoryEntry::initInstances()
{
	this->_Inst_Parent = NULL;
	this->_Inst_Entries = NULL;
#ifdef SB_USE_CLASS_TELTARFILEATTRIBUTES
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELTARFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_ExtractionStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_InputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElTarArchiveDirectoryEntry::TElTarArchiveDirectoryEntry(TElTarArchiveDirectoryEntryHandle handle, TElOwnHandle ownHandle) : TElArchiveDirectoryEntry(handle, ownHandle)
{
	initInstances();
}

TElTarArchiveDirectoryEntry::TElTarArchiveDirectoryEntry() : TElArchiveDirectoryEntry(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTarArchiveDirectoryEntry_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELBASEARCHIVE
TElTarArchiveDirectoryEntry::TElTarArchiveDirectoryEntry(TElBaseArchive &Owner) : TElArchiveDirectoryEntry(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTarArchiveDirectoryEntry_Create_1(Owner.getHandle(), &_Handle));
}

TElTarArchiveDirectoryEntry::TElTarArchiveDirectoryEntry(TElBaseArchive *Owner) : TElArchiveDirectoryEntry(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTarArchiveDirectoryEntry_Create_1((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBASEARCHIVE */

TElTarArchiveDirectoryEntry::~TElTarArchiveDirectoryEntry()
{
	delete this->_Inst_Parent;
	this->_Inst_Parent = NULL;
	delete this->_Inst_Entries;
	this->_Inst_Entries = NULL;
#ifdef SB_USE_CLASS_TELTARFILEATTRIBUTES
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELTARFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_ExtractionStream;
	this->_Inst_ExtractionStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_InputStream;
	this->_Inst_InputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELTARFILEATTRIBUTES

SB_INLINE void TElTarFileAttributes::Assign(TElTarFileAttributes &Source)
{
	SBCheckError(TElTarFileAttributes_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElTarFileAttributes::Assign(TElTarFileAttributes *Source)
{
	SBCheckError(TElTarFileAttributes_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElTarFileAttributes::AssignTo(TElTarFileAttributes &Dest)
{
	SBCheckError(TElTarFileAttributes_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElTarFileAttributes::AssignTo(TElTarFileAttributes *Dest)
{
	SBCheckError(TElTarFileAttributes_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint32_t TElTarFileAttributes::get_Mode()
{
	uint32_t OutResult;
	SBCheckError(TElTarFileAttributes_get_Mode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarFileAttributes::set_Mode(uint32_t Value)
{
	SBCheckError(TElTarFileAttributes_set_Mode(_Handle, Value));
}

SB_INLINE int64_t TElTarFileAttributes::get_FileSize()
{
	int64_t OutResult;
	SBCheckError(TElTarFileAttributes_get_FileSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarFileAttributes::set_FileSize(int64_t Value)
{
	SBCheckError(TElTarFileAttributes_set_FileSize(_Handle, Value));
}

TSBTarFileType TElTarFileAttributes::get_FileType()
{
	TSBTarFileTypeRaw OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_FileType(_Handle, &OutResultRaw));
	return (TSBTarFileType)OutResultRaw;
}

SB_INLINE void TElTarFileAttributes::set_FileType(TSBTarFileType Value)
{
	SBCheckError(TElTarFileAttributes_set_FileType(_Handle, (TSBTarFileTypeRaw)Value));
}

SB_INLINE char TElTarFileAttributes::get_FileTypeCode()
{
	char OutResult;
	SBCheckError(TElTarFileAttributes_get_FileTypeCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarFileAttributes::set_FileTypeCode(char Value)
{
	SBCheckError(TElTarFileAttributes_set_FileTypeCode(_Handle, Value));
}

bool TElTarFileAttributes::get_ModifyTimeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_ModifyTimeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_ModifyTimeAvailable(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_ModifyTimeAvailable(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElTarFileAttributes::get_ModifyTime()
{
	int64_t OutResult;
	SBCheckError(TElTarFileAttributes_get_ModifyTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarFileAttributes::set_ModifyTime(int64_t Value)
{
	SBCheckError(TElTarFileAttributes_set_ModifyTime(_Handle, Value));
}

void TElTarFileAttributes::get_LinkName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarFileAttributes_get_LinkName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-526494548, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTarFileAttributes::set_LinkName(const std::string &Value)
{
	SBCheckError(TElTarFileAttributes_set_LinkName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElTarFileAttributes::get_SUID()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_SUID(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_SUID(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_SUID(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_SGID()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_SGID(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_SGID(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_SGID(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_OwnerRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_OwnerRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_OwnerRead(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_OwnerRead(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_OwnerWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_OwnerWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_OwnerWrite(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_OwnerWrite(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_OwnerExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_OwnerExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_OwnerExecute(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_OwnerExecute(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_GroupRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_GroupRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_GroupRead(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_GroupRead(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_GroupWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_GroupWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_GroupWrite(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_GroupWrite(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_GroupExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_GroupExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_GroupExecute(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_GroupExecute(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_OtherRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_OtherRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_OtherRead(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_OtherRead(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_OtherWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_OtherWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_OtherWrite(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_OtherWrite(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_OtherExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_OtherExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_OtherExecute(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_OtherExecute(_Handle, (int8_t)Value));
}

bool TElTarFileAttributes::get_UIDAndGIDAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_UIDAndGIDAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_UIDAndGIDAvailable(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_UIDAndGIDAvailable(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElTarFileAttributes::get_UID()
{
	uint32_t OutResult;
	SBCheckError(TElTarFileAttributes_get_UID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarFileAttributes::set_UID(uint32_t Value)
{
	SBCheckError(TElTarFileAttributes_set_UID(_Handle, Value));
}

SB_INLINE uint32_t TElTarFileAttributes::get_GID()
{
	uint32_t OutResult;
	SBCheckError(TElTarFileAttributes_get_GID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarFileAttributes::set_GID(uint32_t Value)
{
	SBCheckError(TElTarFileAttributes_set_GID(_Handle, Value));
}

bool TElTarFileAttributes::get_HasUStar()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileAttributes_get_HasUStar(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileAttributes::set_HasUStar(bool Value)
{
	SBCheckError(TElTarFileAttributes_set_HasUStar(_Handle, (int8_t)Value));
}

void TElTarFileAttributes::get_UName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarFileAttributes_get_UName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1588381032, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTarFileAttributes::set_UName(const std::string &Value)
{
	SBCheckError(TElTarFileAttributes_set_UName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElTarFileAttributes::get_GName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarFileAttributes_get_GName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1150026118, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTarFileAttributes::set_GName(const std::string &Value)
{
	SBCheckError(TElTarFileAttributes_set_GName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElTarFileAttributes::get_DevMajor(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarFileAttributes_get_DevMajor(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(272550131, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTarFileAttributes::set_DevMajor(const std::string &Value)
{
	SBCheckError(TElTarFileAttributes_set_DevMajor(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElTarFileAttributes::get_DevMinor(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarFileAttributes_get_DevMinor(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-763148096, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTarFileAttributes::set_DevMinor(const std::string &Value)
{
	SBCheckError(TElTarFileAttributes_set_DevMinor(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElTarFileAttributes::get_Prefix(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarFileAttributes_get_Prefix(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1154137396, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTarFileAttributes::set_Prefix(const std::string &Value)
{
	SBCheckError(TElTarFileAttributes_set_Prefix(_Handle, Value.data(), (int32_t)Value.length()));
}

TElTarFileAttributes::TElTarFileAttributes(TElTarFileAttributesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElTarFileAttributes::TElTarFileAttributes() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTarFileAttributes_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELTARFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELTARPROCESSINGUNIT

SB_INLINE void TElTarProcessingUnit::InitializeProcessing()
{
	SBCheckError(TElTarProcessingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElTarProcessingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElTarProcessingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElTarProcessingUnit::FinalizeProcessing()
{
	SBCheckError(TElTarProcessingUnit_FinalizeProcessing(_Handle));
}

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
TElTarArchiveDirectoryEntry* TElTarProcessingUnit::get_ProcessingEntry()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarProcessingUnit_get_ProcessingEntry(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProcessingEntry)
		this->_Inst_ProcessingEntry = new TElTarArchiveDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_ProcessingEntry->updateHandle(hOutResult);
	return this->_Inst_ProcessingEntry;
}

SB_INLINE void TElTarProcessingUnit::set_ProcessingEntry(TElTarArchiveDirectoryEntry &Value)
{
	SBCheckError(TElTarProcessingUnit_set_ProcessingEntry(_Handle, Value.getHandle()));
}

SB_INLINE void TElTarProcessingUnit::set_ProcessingEntry(TElTarArchiveDirectoryEntry *Value)
{
	SBCheckError(TElTarProcessingUnit_set_ProcessingEntry(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

void TElTarProcessingUnit::initInstances()
{
#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
	this->_Inst_ProcessingEntry = NULL;
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */
}

TElTarProcessingUnit::TElTarProcessingUnit(TElTarProcessingUnitHandle handle, TElOwnHandle ownHandle) : TElArcProcessingUnit(handle, ownHandle)
{
	initInstances();
}

TElTarProcessingUnit::TElTarProcessingUnit() : TElArcProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTarProcessingUnit_Create(&_Handle));
}

TElTarProcessingUnit::~TElTarProcessingUnit()
{
#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
	delete this->_Inst_ProcessingEntry;
	this->_Inst_ProcessingEntry = NULL;
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */
}
#endif /* SB_USE_CLASS_TELTARPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELTARREADER

SB_INLINE void TElTarReader::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElTarReader_Open(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElTarReader::Open(TStream &Stream)
{
	SBCheckError(TElTarReader_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElTarReader::Open(TStream *Stream)
{
	SBCheckError(TElTarReader_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElTarReader::Close()
{
	SBCheckError(TElTarReader_Close(_Handle));
}

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
SB_INLINE void TElTarReader::Extract(TElTarArchiveDirectoryEntry &Entry, const std::string &OutputPath)
{
	SBCheckError(TElTarReader_Extract(_Handle, Entry.getHandle(), OutputPath.data(), (int32_t)OutputPath.length()));
}

SB_INLINE void TElTarReader::Extract(TElTarArchiveDirectoryEntry *Entry, const std::string &OutputPath)
{
	SBCheckError(TElTarReader_Extract(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, OutputPath.data(), (int32_t)OutputPath.length()));
}
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElTarReader::Extract(TList &Entries, const std::string &OutputPath)
{
	SBCheckError(TElTarReader_Extract_1(_Handle, Entries.getHandle(), OutputPath.data(), (int32_t)OutputPath.length()));
}

SB_INLINE void TElTarReader::Extract(TList *Entries, const std::string &OutputPath)
{
	SBCheckError(TElTarReader_Extract_1(_Handle, (Entries != NULL) ? Entries->getHandle() : SB_NULL_HANDLE, OutputPath.data(), (int32_t)OutputPath.length()));
}
#endif /* SB_USE_CLASS_TLIST */

SB_INLINE void TElTarReader::Extract(const std::string &Mask, const std::string &OutputPath)
{
	SBCheckError(TElTarReader_Extract_2(_Handle, Mask.data(), (int32_t)Mask.length(), OutputPath.data(), (int32_t)OutputPath.length()));
}

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
void TElTarReader::ExtractContents(TElTarArchiveDirectoryEntry &Entry, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTarReader_ExtractContents(_Handle, Entry.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-594904169, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElTarReader::ExtractContents(TElTarArchiveDirectoryEntry *Entry, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTarReader_ExtractContents(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-594904169, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
TElTarArchiveDirectoryEntry* TElTarReader::get_Directory()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarReader_get_Directory(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Directory)
		this->_Inst_Directory = new TElTarArchiveDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_Directory->updateHandle(hOutResult);
	return this->_Inst_Directory;
}
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

bool TElTarReader::get_IgnoreArchiveErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarReader_get_IgnoreArchiveErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarReader::set_IgnoreArchiveErrors(bool Value)
{
	SBCheckError(TElTarReader_set_IgnoreArchiveErrors(_Handle, (int8_t)Value));
}

bool TElTarReader::get_CaseSensitiveFilenames()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarReader_get_CaseSensitiveFilenames(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarReader::set_CaseSensitiveFilenames(bool Value)
{
	SBCheckError(TElTarReader_set_CaseSensitiveFilenames(_Handle, (int8_t)Value));
}

void TElTarReader::get_FilenamesCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTarReader_get_FilenamesCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-224115316, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTarReader::set_FilenamesCharset(const std::string &Value)
{
	SBCheckError(TElTarReader_set_FilenamesCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElTarReader::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarReader_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElTarReader::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElTarReader_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElTarReader::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElTarReader_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

TSBTarCompressMethod TElTarReader::get_CompressionMethod()
{
	TSBTarCompressMethodRaw OutResultRaw = 0;
	SBCheckError(TElTarReader_get_CompressionMethod(_Handle, &OutResultRaw));
	return (TSBTarCompressMethod)OutResultRaw;
}

SB_INLINE void TElTarReader::set_CompressionMethod(TSBTarCompressMethod Value)
{
	SBCheckError(TElTarReader_set_CompressionMethod(_Handle, (TSBTarCompressMethodRaw)Value));
}

SB_INLINE void TElTarReader::get_OnExtractionStreamNeeded(TSBTarExtractionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnExtractionStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnExtractionStreamNeeded(TSBTarExtractionStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnExtractionStreamNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnExtractionMakeDirectory(TSBTarExtractionMakeDirectoryEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnExtractionMakeDirectory(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnExtractionMakeDirectory(TSBTarExtractionMakeDirectoryEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnExtractionMakeDirectory(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnProgress(TSBTarProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnProgress(TSBTarProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnExtractionStart(TSBTarExtractionStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnExtractionStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnExtractionStart(TSBTarExtractionStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnExtractionStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnExtractionFinished(TSBTarExtractionFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnExtractionFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnExtractionFinished(TSBTarExtractionFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnExtractionFinished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnUserActionNeeded(TSBTarUserActionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnUserActionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnUserActionNeeded(TSBTarUserActionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnUserActionNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnArchiveError(TSBTarArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnArchiveError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnArchiveError(TSBTarArchiveErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnArchiveError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnUnCompressionTarFromGZipStart(TSBTarUnCompressionTarFromGZipStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnUnCompressionTarFromGZipStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnUnCompressionTarFromGZipStart(TSBTarUnCompressionTarFromGZipStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnUnCompressionTarFromGZipStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnUnCompressionTarFromGZipFinished(TSBTarUnCompressionTarFromGZipFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnUnCompressionTarFromGZipFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnUnCompressionTarFromGZipFinished(TSBTarUnCompressionTarFromGZipFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnUnCompressionTarFromGZipFinished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnUnCompressionTarFromBZip2Start(TSBTarUnCompressionTarFromBZip2StartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnUnCompressionTarFromBZip2Start(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnUnCompressionTarFromBZip2Start(TSBTarUnCompressionTarFromBZip2StartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnUnCompressionTarFromBZip2Start(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarReader::get_OnUnCompressionTarFromBZip2Finished(TSBTarUnCompressionTarFromBZip2FinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarReader_get_OnUnCompressionTarFromBZip2Finished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarReader::set_OnUnCompressionTarFromBZip2Finished(TSBTarUnCompressionTarFromBZip2FinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarReader_set_OnUnCompressionTarFromBZip2Finished(_Handle, pMethodValue, pDataValue));
}

void TElTarReader::initInstances()
{
#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
	this->_Inst_Directory = NULL;
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElTarReader::TElTarReader(TElTarReaderHandle handle, TElOwnHandle ownHandle) : TElBaseArchive(handle, ownHandle)
{
	initInstances();
}

TElTarReader::TElTarReader(TComponent &AOwner) : TElBaseArchive(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTarReader_Create(AOwner.getHandle(), &_Handle));
}

TElTarReader::TElTarReader(TComponent *AOwner) : TElBaseArchive(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTarReader_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElTarReader::~TElTarReader()
{
#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
	delete this->_Inst_Directory;
	this->_Inst_Directory = NULL;
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELTARREADER */

#ifdef SB_USE_CLASS_TELTARWRITER

SB_INLINE void TElTarWriter::CreateArchive()
{
	SBCheckError(TElTarWriter_CreateArchive(_Handle));
}

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TElTarArchiveDirectoryEntry &Parent, const std::string &Path, int32_t Mode, TElUStarTarHeader &USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add(_Handle, Parent.getHandle(), Path.data(), (int32_t)Path.length(), Mode, USTAR.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TElTarArchiveDirectoryEntry *Parent, const std::string &Path, int32_t Mode, TElUStarTarHeader *USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Path.data(), (int32_t)Path.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(const std::string &Path, int32_t Mode, TElUStarTarHeader &USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_1(_Handle, Path.data(), (int32_t)Path.length(), Mode, USTAR.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(const std::string &Path, int32_t Mode, TElUStarTarHeader *USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_1(_Handle, Path.data(), (int32_t)Path.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TElTarArchiveDirectoryEntry &Parent, TStream &Stream, const std::string &FileName, int32_t Mode, TElUStarTarHeader &USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_2(_Handle, Parent.getHandle(), Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), Mode, USTAR.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TElTarArchiveDirectoryEntry *Parent, TStream *Stream, const std::string &FileName, int32_t Mode, TElUStarTarHeader *USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_2(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TElTarArchiveDirectoryEntry &Parent, TStream &Stream, int32_t Mode, TElUStarTarHeader &USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_3(_Handle, Parent.getHandle(), Stream.getHandle(), Mode, USTAR.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TElTarArchiveDirectoryEntry *Parent, TStream *Stream, int32_t Mode, TElUStarTarHeader *USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_3(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TStream &Stream, int32_t Mode, TElUStarTarHeader &USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_4(_Handle, Stream.getHandle(), Mode, USTAR.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TStream *Stream, int32_t Mode, TElUStarTarHeader *USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_4(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TStream &Stream, const std::string &FileName, int32_t Mode, TElUStarTarHeader &USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_5(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), Mode, USTAR.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TStream *Stream, const std::string &FileName, int32_t Mode, TElUStarTarHeader *USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_5(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TElTarArchiveDirectoryEntry &Parent, const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName, int32_t Mode, TElUStarTarHeader &USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_6(_Handle, Parent.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), StartIndex, Count, FileName.data(), (int32_t)FileName.length(), Mode, USTAR.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(TElTarArchiveDirectoryEntry *Parent, const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName, int32_t Mode, TElUStarTarHeader *USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_6(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), StartIndex, Count, FileName.data(), (int32_t)FileName.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName, int32_t Mode, TElUStarTarHeader &USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_7(_Handle, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), StartIndex, Count, FileName.data(), (int32_t)FileName.length(), Mode, USTAR.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::Add(const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName, int32_t Mode, TElUStarTarHeader *USTAR)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_Add_7(_Handle, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), StartIndex, Count, FileName.data(), (int32_t)FileName.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
SB_INLINE void TElTarWriter::AddDirContents(TElTarArchiveDirectoryEntry &Parent, const std::string &Path, int32_t Mode, TElUStarTarHeader &USTAR)
{
	SBCheckError(TElTarWriter_AddDirContents(_Handle, Parent.getHandle(), Path.data(), (int32_t)Path.length(), Mode, USTAR.getHandle()));
}

SB_INLINE void TElTarWriter::AddDirContents(TElTarArchiveDirectoryEntry *Parent, const std::string &Path, int32_t Mode, TElUStarTarHeader *USTAR)
{
	SBCheckError(TElTarWriter_AddDirContents(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Path.data(), (int32_t)Path.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELUSTARTARHEADER
SB_INLINE void TElTarWriter::AddDirContents(const std::string &Path, int32_t Mode, TElUStarTarHeader &USTAR)
{
	SBCheckError(TElTarWriter_AddDirContents_1(_Handle, Path.data(), (int32_t)Path.length(), Mode, USTAR.getHandle()));
}

SB_INLINE void TElTarWriter::AddDirContents(const std::string &Path, int32_t Mode, TElUStarTarHeader *USTAR)
{
	SBCheckError(TElTarWriter_AddDirContents_1(_Handle, Path.data(), (int32_t)Path.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
SB_INLINE void TElTarWriter::AddDirContents(TElTarArchiveDirectoryEntry &Parent, const std::string &Path, const std::string &Mask, int32_t Mode, TElUStarTarHeader &USTAR)
{
	SBCheckError(TElTarWriter_AddDirContents_2(_Handle, Parent.getHandle(), Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), Mode, USTAR.getHandle()));
}

SB_INLINE void TElTarWriter::AddDirContents(TElTarArchiveDirectoryEntry *Parent, const std::string &Path, const std::string &Mask, int32_t Mode, TElUStarTarHeader *USTAR)
{
	SBCheckError(TElTarWriter_AddDirContents_2(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELUSTARTARHEADER
SB_INLINE void TElTarWriter::AddDirContents(const std::string &Path, const std::string &Mask, int32_t Mode, TElUStarTarHeader &USTAR)
{
	SBCheckError(TElTarWriter_AddDirContents_3(_Handle, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), Mode, USTAR.getHandle()));
}

SB_INLINE void TElTarWriter::AddDirContents(const std::string &Path, const std::string &Mask, int32_t Mode, TElUStarTarHeader *USTAR)
{
	SBCheckError(TElTarWriter_AddDirContents_3(_Handle, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), Mode, (USTAR != NULL) ? USTAR->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::MakeDir(const std::string &Path)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_MakeDir(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::MakeDir(TElTarArchiveDirectoryEntry &Parent, const std::string &Path)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_MakeDir_1(_Handle, Parent.getHandle(), Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElTarArchiveDirectoryEntryHandle TElTarWriter::MakeDir(TElTarArchiveDirectoryEntry *Parent, const std::string &Path)
{
	TElTarArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElTarWriter_MakeDir_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

SB_INLINE void TElTarWriter::Remove(const std::string &Mask)
{
	SBCheckError(TElTarWriter_Remove(_Handle, Mask.data(), (int32_t)Mask.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElTarWriter::BeginCompression(TStream &Destination)
{
	SBCheckError(TElTarWriter_BeginCompression(_Handle, Destination.getHandle()));
}

SB_INLINE void TElTarWriter::BeginCompression(TStream *Destination)
{
	SBCheckError(TElTarWriter_BeginCompression(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElTarWriter::BeginCompression(const std::string &Destination)
{
	SBCheckError(TElTarWriter_BeginCompression_1(_Handle, Destination.data(), (int32_t)Destination.length()));
}

SB_INLINE void TElTarWriter::UpdateCompression()
{
	SBCheckError(TElTarWriter_UpdateCompression(_Handle));
}

SB_INLINE void TElTarWriter::EndCompression()
{
	SBCheckError(TElTarWriter_EndCompression(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElTarWriter::Compress(TStream &Destination)
{
	SBCheckError(TElTarWriter_Compress(_Handle, Destination.getHandle()));
}

SB_INLINE void TElTarWriter::Compress(TStream *Destination)
{
	SBCheckError(TElTarWriter_Compress(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElTarWriter::Compress(const std::string &Destination)
{
	SBCheckError(TElTarWriter_Compress_1(_Handle, Destination.data(), (int32_t)Destination.length()));
}

SB_INLINE void TElTarWriter::Compress()
{
	SBCheckError(TElTarWriter_Compress_2(_Handle));
}

SB_INLINE void TElTarWriter::Close()
{
	SBCheckError(TElTarWriter_Close(_Handle));
}

SB_INLINE int32_t TElTarWriter::get_UID()
{
	int32_t OutResult;
	SBCheckError(TElTarWriter_get_UID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarWriter::set_UID(int32_t Value)
{
	SBCheckError(TElTarWriter_set_UID(_Handle, Value));
}

SB_INLINE int32_t TElTarWriter::get_GID()
{
	int32_t OutResult;
	SBCheckError(TElTarWriter_get_GID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarWriter::set_GID(int32_t Value)
{
	SBCheckError(TElTarWriter_set_GID(_Handle, Value));
}

TSBArcReplaceMode TElTarWriter::get_ReplaceMode()
{
	TSBArcReplaceModeRaw OutResultRaw = 0;
	SBCheckError(TElTarWriter_get_ReplaceMode(_Handle, &OutResultRaw));
	return (TSBArcReplaceMode)OutResultRaw;
}

SB_INLINE void TElTarWriter::set_ReplaceMode(TSBArcReplaceMode Value)
{
	SBCheckError(TElTarWriter_set_ReplaceMode(_Handle, (TSBArcReplaceModeRaw)Value));
}

bool TElTarWriter::get_NewArchive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarWriter_get_NewArchive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElTarWriter::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElTarWriter_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarWriter::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElTarWriter_set_CompressionLevel(_Handle, Value));
}

SB_INLINE void TElTarWriter::get_OnCompressionStreamNeeded(TSBTarCompressionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarWriter_get_OnCompressionStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarWriter::set_OnCompressionStreamNeeded(TSBTarCompressionStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarWriter_set_OnCompressionStreamNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarWriter::get_OnCompressionStart(TSBTarCompressionStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarWriter_get_OnCompressionStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarWriter::set_OnCompressionStart(TSBTarCompressionStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarWriter_set_OnCompressionStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarWriter::get_OnCompressionFinished(TSBTarCompressionFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarWriter_get_OnCompressionFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarWriter::set_OnCompressionFinished(TSBTarCompressionFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarWriter_set_OnCompressionFinished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarWriter::get_OnCompressionTarToGZipStart(TSBTarCompressionTarToGZipStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarWriter_get_OnCompressionTarToGZipStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarWriter::set_OnCompressionTarToGZipStart(TSBTarCompressionTarToGZipStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarWriter_set_OnCompressionTarToGZipStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarWriter::get_OnCompressionTarToGZipFinished(TSBTarCompressionTarToGZipFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarWriter_get_OnCompressionTarToGZipFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarWriter::set_OnCompressionTarToGZipFinished(TSBTarCompressionTarToGZipFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarWriter_set_OnCompressionTarToGZipFinished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarWriter::get_OnCompressionTarToBZip2Start(TSBTarCompressionTarToBZip2StartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarWriter_get_OnCompressionTarToBZip2Start(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarWriter::set_OnCompressionTarToBZip2Start(TSBTarCompressionTarToBZip2StartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarWriter_set_OnCompressionTarToBZip2Start(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarWriter::get_OnCompressionTarToBZip2Finished(TSBTarCompressionTarToBZip2FinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarWriter_get_OnCompressionTarToBZip2Finished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarWriter::set_OnCompressionTarToBZip2Finished(TSBTarCompressionTarToBZip2FinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarWriter_set_OnCompressionTarToBZip2Finished(_Handle, pMethodValue, pDataValue));
}

TElTarWriter::TElTarWriter(TElTarWriterHandle handle, TElOwnHandle ownHandle) : TElTarReader(handle, ownHandle)
{
}

TElTarWriter::TElTarWriter(TComponent &AOwner) : TElTarReader(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTarWriter_Create(AOwner.getHandle(), &_Handle));
}

TElTarWriter::TElTarWriter(TComponent *AOwner) : TElTarReader(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTarWriter_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELTARWRITER */

};	/* namespace SecureBlackbox */

