#include "sbarczip.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY

SB_INLINE void TElZipArchiveDirectoryEntry::Clear()
{
	SBCheckError(TElZipArchiveDirectoryEntry_Clear(_Handle));
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipArchiveDirectoryEntry::AddEntry(const std::string &APath)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_AddEntry(_Handle, APath.data(), (int32_t)APath.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipArchiveDirectoryEntry::AddNewEntry(const std::string &APath)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_AddNewEntry(_Handle, APath.data(), (int32_t)APath.length(), &OutResult));
	return OutResult;
}

bool TElZipArchiveDirectoryEntry::RemoveEntry(TElZipArchiveDirectoryEntry &Entry)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_RemoveEntry(_Handle, Entry.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipArchiveDirectoryEntry::RemoveEntry(TElZipArchiveDirectoryEntry *Entry)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_RemoveEntry(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipArchiveDirectoryEntry::RemoveEntry(const std::string &APath)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_RemoveEntry_1(_Handle, APath.data(), (int32_t)APath.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipArchiveDirectoryEntry::RemoveEntry(const std::string &APath, bool CaseSensitive)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_RemoveEntry_2(_Handle, APath.data(), (int32_t)APath.length(), (int8_t)CaseSensitive, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipArchiveDirectoryEntry::ClearEntries()
{
	SBCheckError(TElZipArchiveDirectoryEntry_ClearEntries(_Handle));
}

SB_INLINE int32_t TElZipArchiveDirectoryEntry::RemoveEntries(const std::string &Filter)
{
	int32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_RemoveEntries(_Handle, Filter.data(), (int32_t)Filter.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipArchiveDirectoryEntry::EntryWithName(const std::string &AName)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_EntryWithName(_Handle, AName.data(), (int32_t)AName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipArchiveDirectoryEntry::EntryWithName(const std::string &AName, bool CaseSensitive)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_EntryWithName_1(_Handle, AName.data(), (int32_t)AName.length(), (int8_t)CaseSensitive, &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipArchiveDirectoryEntry::EntryWithPath(const std::string &APath)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_EntryWithPath(_Handle, APath.data(), (int32_t)APath.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipArchiveDirectoryEntry::EntryWithPath(const std::string &APath, bool CaseSensitive)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_EntryWithPath_1(_Handle, APath.data(), (int32_t)APath.length(), (int8_t)CaseSensitive, &OutResult));
	return OutResult;
}

bool TElZipArchiveDirectoryEntry::get_LocalHeaderLoaded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_LocalHeaderLoaded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipArchiveDirectoryEntry::get_CentralHeaderLoaded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_CentralHeaderLoaded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipArchiveDirectoryEntry::get_StrongEncryptionInfoLoaded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_StrongEncryptionInfoLoaded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_StrongEncryptionInfoLoaded(bool Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_StrongEncryptionInfoLoaded(_Handle, (int8_t)Value));
}

TElZipArchiveDirectoryEntry* TElZipArchiveDirectoryEntry::get_Parent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveDirectoryEntry_get_Parent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parent)
		this->_Inst_Parent = new TElZipArchiveDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_Parent->updateHandle(hOutResult);
	return this->_Inst_Parent;
}

TElZipArchiveDirectoryEntry* TElZipArchiveDirectoryEntry::get_Entries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveDirectoryEntry_get_Entries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Entries)
		this->_Inst_Entries = new TElZipArchiveDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_Entries->updateHandle(hOutResult);
	return this->_Inst_Entries;
}

void TElZipArchiveDirectoryEntry::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipArchiveDirectoryEntry_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(670758694, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_Flags()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_Flags(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_Flags(_Handle, Value));
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_CompressionMethod()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_CompressionMethod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_CompressionMethod(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_CompressionMethod(_Handle, Value));
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_CompressionLevel(_Handle, Value));
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_CRC32()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_CRC32(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_CRC32(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_CRC32(_Handle, Value));
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_VersionToExtract()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_VersionToExtract(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_VersionToExtract(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_VersionToExtract(_Handle, Value));
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_VersionMadeBy()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_VersionMadeBy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_VersionMadeBy(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_VersionMadeBy(_Handle, Value));
}

SB_INLINE uint8_t TElZipArchiveDirectoryEntry::get_FileAttributesCompatibility()
{
	uint8_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_FileAttributesCompatibility(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_FileAttributesCompatibility(uint8_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_FileAttributesCompatibility(_Handle, Value));
}

bool TElZipArchiveDirectoryEntry::get_Encrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_Encrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_Encrypted(bool Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_Encrypted(_Handle, (int8_t)Value));
}

bool TElZipArchiveDirectoryEntry::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipArchiveDirectoryEntry::get_StrongEncryption()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_StrongEncryption(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_StrongEncryption(bool Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_StrongEncryption(_Handle, (int8_t)Value));
}

bool TElZipArchiveDirectoryEntry::get_WinZipEncryption()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_WinZipEncryption(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_WinZipEncryption(bool Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_WinZipEncryption(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_WinZipEncryptionVersion()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_WinZipEncryptionVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_WinZipEncryptionVersion(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_WinZipEncryptionVersion(_Handle, Value));
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_WinZipAesKeySize()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_WinZipAesKeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_WinZipAesKeySize(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_WinZipAesKeySize(_Handle, Value));
}

bool TElZipArchiveDirectoryEntry::get_LocalHeaderMasked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_LocalHeaderMasked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_LocalHeaderMasked(bool Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_LocalHeaderMasked(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElZipArchiveDirectoryEntry::get_LocalHeaderOffset()
{
	int64_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_LocalHeaderOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_LocalHeaderOffset(int64_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_LocalHeaderOffset(_Handle, Value));
}

SB_INLINE int64_t TElZipArchiveDirectoryEntry::get_DataOffset()
{
	int64_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_DataOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElZipArchiveDirectoryEntry::get_DiskNumberStart()
{
	uint32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_DiskNumberStart(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_DiskNumberStart(uint32_t Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_DiskNumberStart(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
TElZipStrongEncryptionInfo* TElZipArchiveDirectoryEntry::get_StrongEncryptionInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveDirectoryEntry_get_StrongEncryptionInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StrongEncryptionInfo)
		this->_Inst_StrongEncryptionInfo = new TElZipStrongEncryptionInfo(hOutResult, ohFalse);
	else
		this->_Inst_StrongEncryptionInfo->updateHandle(hOutResult);
	return this->_Inst_StrongEncryptionInfo;
}
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */

SB_INLINE int32_t TElZipArchiveDirectoryEntry::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElZipArchiveDirectoryEntry_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO
TElZipStrongEncryptionSignatureInfo* TElZipArchiveDirectoryEntry::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveDirectoryEntry_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElZipStrongEncryptionSignatureInfo(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO */

bool TElZipArchiveDirectoryEntry::get_Process()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_Process(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_Process(bool Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_Process(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES
TElZipDosFileAttributes* TElZipArchiveDirectoryEntry::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveDirectoryEntry_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElZipDosFileAttributes(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES
TElZipUnixFileAttributes* TElZipArchiveDirectoryEntry::get_UnixAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveDirectoryEntry_get_UnixAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnixAttributes)
		this->_Inst_UnixAttributes = new TElZipUnixFileAttributes(hOutResult, ohFalse);
	else
		this->_Inst_UnixAttributes->updateHandle(hOutResult);
	return this->_Inst_UnixAttributes;
}
#endif /* SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES */

void TElZipArchiveDirectoryEntry::get_ExtractionPath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipArchiveDirectoryEntry_get_ExtractionPath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1908571093, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_ExtractionPath(const std::string &Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_ExtractionPath(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElZipArchiveDirectoryEntry::get_ExtractionStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveDirectoryEntry_get_ExtractionStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtractionStream)
		this->_Inst_ExtractionStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_ExtractionStream->updateHandle(hOutResult);
	return this->_Inst_ExtractionStream;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_ExtractionStream(TStream &Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_ExtractionStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_ExtractionStream(TStream *Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_ExtractionStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElZipArchiveDirectoryEntry::get_InputPath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipArchiveDirectoryEntry_get_InputPath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(596827691, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_InputPath(const std::string &Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_InputPath(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElZipArchiveDirectoryEntry::get_InputStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveDirectoryEntry_get_InputStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InputStream)
		this->_Inst_InputStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_InputStream->updateHandle(hOutResult);
	return this->_Inst_InputStream;
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_InputStream(TStream &Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_InputStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_InputStream(TStream *Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_InputStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElZipArchiveDirectoryEntry::get_InputData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipArchiveDirectoryEntry_get_InputData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2060081593, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_InputData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_InputData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElZipArchiveDirectoryEntry::get_FreeInputStream()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipArchiveDirectoryEntry_get_FreeInputStream(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipArchiveDirectoryEntry::set_FreeInputStream(bool Value)
{
	SBCheckError(TElZipArchiveDirectoryEntry_set_FreeInputStream(_Handle, (int8_t)Value));
}

void TElZipArchiveDirectoryEntry::initInstances()
{
	this->_Inst_Parent = NULL;
	this->_Inst_Entries = NULL;
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
	this->_Inst_StrongEncryptionInfo = NULL;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO */
#ifdef SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES
	this->_Inst_UnixAttributes = NULL;
#endif /* SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_ExtractionStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_InputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElZipArchiveDirectoryEntry::TElZipArchiveDirectoryEntry(TElZipArchiveDirectoryEntryHandle handle, TElOwnHandle ownHandle) : TElArchiveDirectoryEntry(handle, ownHandle)
{
	initInstances();
}

TElZipArchiveDirectoryEntry::TElZipArchiveDirectoryEntry() : TElArchiveDirectoryEntry(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipArchiveDirectoryEntry_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELBASEARCHIVE
TElZipArchiveDirectoryEntry::TElZipArchiveDirectoryEntry(TElBaseArchive &Owner) : TElArchiveDirectoryEntry(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipArchiveDirectoryEntry_Create_1(Owner.getHandle(), &_Handle));
}

TElZipArchiveDirectoryEntry::TElZipArchiveDirectoryEntry(TElBaseArchive *Owner) : TElArchiveDirectoryEntry(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipArchiveDirectoryEntry_Create_1((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBASEARCHIVE */

TElZipArchiveDirectoryEntry::~TElZipArchiveDirectoryEntry()
{
	delete this->_Inst_Parent;
	this->_Inst_Parent = NULL;
	delete this->_Inst_Entries;
	this->_Inst_Entries = NULL;
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
	delete this->_Inst_StrongEncryptionInfo;
	this->_Inst_StrongEncryptionInfo = NULL;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO */
#ifdef SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES
	delete this->_Inst_UnixAttributes;
	this->_Inst_UnixAttributes = NULL;
#endif /* SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_ExtractionStream;
	this->_Inst_ExtractionStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_InputStream;
	this->_Inst_InputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES

SB_INLINE uint8_t TElZipDosFileAttributes::get_RawAttributes()
{
	uint8_t OutResult;
	SBCheckError(TElZipDosFileAttributes_get_RawAttributes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipDosFileAttributes::set_RawAttributes(uint8_t Value)
{
	SBCheckError(TElZipDosFileAttributes_set_RawAttributes(_Handle, Value));
}

SB_INLINE uint32_t TElZipDosFileAttributes::get_RawLastModTime()
{
	uint32_t OutResult;
	SBCheckError(TElZipDosFileAttributes_get_RawLastModTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipDosFileAttributes::set_RawLastModTime(uint32_t Value)
{
	SBCheckError(TElZipDosFileAttributes_set_RawLastModTime(_Handle, Value));
}

SB_INLINE uint32_t TElZipDosFileAttributes::get_RawLastModDate()
{
	uint32_t OutResult;
	SBCheckError(TElZipDosFileAttributes_get_RawLastModDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipDosFileAttributes::set_RawLastModDate(uint32_t Value)
{
	SBCheckError(TElZipDosFileAttributes_set_RawLastModDate(_Handle, Value));
}

bool TElZipDosFileAttributes::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDosFileAttributes_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDosFileAttributes::set_ReadOnly(bool Value)
{
	SBCheckError(TElZipDosFileAttributes_set_ReadOnly(_Handle, (int8_t)Value));
}

bool TElZipDosFileAttributes::get_Hidden()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDosFileAttributes_get_Hidden(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDosFileAttributes::set_Hidden(bool Value)
{
	SBCheckError(TElZipDosFileAttributes_set_Hidden(_Handle, (int8_t)Value));
}

bool TElZipDosFileAttributes::get_System()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDosFileAttributes_get_System(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDosFileAttributes::set_System(bool Value)
{
	SBCheckError(TElZipDosFileAttributes_set_System(_Handle, (int8_t)Value));
}

bool TElZipDosFileAttributes::get_VolumeLabel()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDosFileAttributes_get_VolumeLabel(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDosFileAttributes::set_VolumeLabel(bool Value)
{
	SBCheckError(TElZipDosFileAttributes_set_VolumeLabel(_Handle, (int8_t)Value));
}

bool TElZipDosFileAttributes::get_Directory()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDosFileAttributes_get_Directory(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDosFileAttributes::set_Directory(bool Value)
{
	SBCheckError(TElZipDosFileAttributes_set_Directory(_Handle, (int8_t)Value));
}

bool TElZipDosFileAttributes::get_Archive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDosFileAttributes_get_Archive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDosFileAttributes::set_Archive(bool Value)
{
	SBCheckError(TElZipDosFileAttributes_set_Archive(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElZipDosFileAttributes::get_ModTime()
{
	int64_t OutResult;
	SBCheckError(TElZipDosFileAttributes_get_ModTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipDosFileAttributes::set_ModTime(int64_t Value)
{
	SBCheckError(TElZipDosFileAttributes_set_ModTime(_Handle, Value));
}

TElZipDosFileAttributes::TElZipDosFileAttributes(TElZipDosFileAttributesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElZipDosFileAttributes::TElZipDosFileAttributes() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipDosFileAttributes_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES

SB_INLINE uint32_t TElZipUnixFileAttributes::get_RawAttributes()
{
	uint32_t OutResult;
	SBCheckError(TElZipUnixFileAttributes_get_RawAttributes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipUnixFileAttributes::set_RawAttributes(uint32_t Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_RawAttributes(_Handle, Value));
}

TSBZipUnixFileType TElZipUnixFileAttributes::get_FileType()
{
	TSBZipUnixFileTypeRaw OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_FileType(_Handle, &OutResultRaw));
	return (TSBZipUnixFileType)OutResultRaw;
}

SB_INLINE void TElZipUnixFileAttributes::set_FileType(TSBZipUnixFileType Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_FileType(_Handle, (TSBZipUnixFileTypeRaw)Value));
}

bool TElZipUnixFileAttributes::get_SUID()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_SUID(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_SUID(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_SUID(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_SGID()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_SGID(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_SGID(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_SGID(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_StickyBit()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_StickyBit(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_StickyBit(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_StickyBit(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_OwnerRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_OwnerRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_OwnerRead(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_OwnerRead(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_OwnerWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_OwnerWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_OwnerWrite(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_OwnerWrite(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_OwnerExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_OwnerExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_OwnerExecute(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_OwnerExecute(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_GroupRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_GroupRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_GroupRead(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_GroupRead(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_GroupWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_GroupWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_GroupWrite(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_GroupWrite(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_GroupExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_GroupExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_GroupExecute(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_GroupExecute(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_OtherRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_OtherRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_OtherRead(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_OtherRead(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_OtherWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_OtherWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_OtherWrite(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_OtherWrite(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_OtherExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_OtherExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_OtherExecute(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_OtherExecute(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElZipUnixFileAttributes::get_Permissions()
{
	uint32_t OutResult;
	SBCheckError(TElZipUnixFileAttributes_get_Permissions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipUnixFileAttributes::set_Permissions(uint32_t Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_Permissions(_Handle, Value));
}

SB_INLINE uint8_t TElZipUnixFileAttributes::get_DOSAttributes()
{
	uint8_t OutResult;
	SBCheckError(TElZipUnixFileAttributes_get_DOSAttributes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipUnixFileAttributes::set_DOSAttributes(uint8_t Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_DOSAttributes(_Handle, Value));
}

bool TElZipUnixFileAttributes::get_UIDAndGIDAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_UIDAndGIDAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_UIDAndGIDAvailable(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_UIDAndGIDAvailable(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElZipUnixFileAttributes::get_UID()
{
	uint32_t OutResult;
	SBCheckError(TElZipUnixFileAttributes_get_UID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipUnixFileAttributes::set_UID(uint32_t Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_UID(_Handle, Value));
}

SB_INLINE uint32_t TElZipUnixFileAttributes::get_GID()
{
	uint32_t OutResult;
	SBCheckError(TElZipUnixFileAttributes_get_GID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipUnixFileAttributes::set_GID(uint32_t Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_GID(_Handle, Value));
}

bool TElZipUnixFileAttributes::get_ModifyTimeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_ModifyTimeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_ModifyTimeAvailable(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_ModifyTimeAvailable(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_CreateTimeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_CreateTimeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_CreateTimeAvailable(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_CreateTimeAvailable(_Handle, (int8_t)Value));
}

bool TElZipUnixFileAttributes::get_AccessTimeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipUnixFileAttributes_get_AccessTimeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipUnixFileAttributes::set_AccessTimeAvailable(bool Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_AccessTimeAvailable(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElZipUnixFileAttributes::get_ModifyTime()
{
	int64_t OutResult;
	SBCheckError(TElZipUnixFileAttributes_get_ModifyTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipUnixFileAttributes::set_ModifyTime(int64_t Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_ModifyTime(_Handle, Value));
}

SB_INLINE int64_t TElZipUnixFileAttributes::get_CreateTime()
{
	int64_t OutResult;
	SBCheckError(TElZipUnixFileAttributes_get_CreateTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipUnixFileAttributes::set_CreateTime(int64_t Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_CreateTime(_Handle, Value));
}

SB_INLINE int64_t TElZipUnixFileAttributes::get_AccessTime()
{
	int64_t OutResult;
	SBCheckError(TElZipUnixFileAttributes_get_AccessTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipUnixFileAttributes::set_AccessTime(int64_t Value)
{
	SBCheckError(TElZipUnixFileAttributes_set_AccessTime(_Handle, Value));
}

TElZipUnixFileAttributes::TElZipUnixFileAttributes(TElZipUnixFileAttributesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElZipUnixFileAttributes::TElZipUnixFileAttributes() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipUnixFileAttributes_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO

SB_INLINE void TElZipStrongEncryptionInfo::Assign(TElZipStrongEncryptionInfo &Source)
{
	SBCheckError(TElZipStrongEncryptionInfo_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipStrongEncryptionInfo::Assign(TElZipStrongEncryptionInfo *Source)
{
	SBCheckError(TElZipStrongEncryptionInfo_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint32_t TElZipStrongEncryptionInfo::get_EncryptionAlgorithm()
{
	uint32_t OutResult;
	SBCheckError(TElZipStrongEncryptionInfo_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipStrongEncryptionInfo::set_EncryptionAlgorithm(uint32_t Value)
{
	SBCheckError(TElZipStrongEncryptionInfo_set_EncryptionAlgorithm(_Handle, Value));
}

SB_INLINE uint32_t TElZipStrongEncryptionInfo::get_KeyLength()
{
	uint32_t OutResult;
	SBCheckError(TElZipStrongEncryptionInfo_get_KeyLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipStrongEncryptionInfo::set_KeyLength(uint32_t Value)
{
	SBCheckError(TElZipStrongEncryptionInfo_set_KeyLength(_Handle, Value));
}

bool TElZipStrongEncryptionInfo::get_UsePassword()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionInfo_get_UsePassword(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipStrongEncryptionInfo::set_UsePassword(bool Value)
{
	SBCheckError(TElZipStrongEncryptionInfo_set_UsePassword(_Handle, (int8_t)Value));
}

bool TElZipStrongEncryptionInfo::get_UseCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionInfo_get_UseCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipStrongEncryptionInfo::set_UseCertificates(bool Value)
{
	SBCheckError(TElZipStrongEncryptionInfo_set_UseCertificates(_Handle, (int8_t)Value));
}

bool TElZipStrongEncryptionInfo::get_UseOAEP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionInfo_get_UseOAEP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipStrongEncryptionInfo::set_UseOAEP(bool Value)
{
	SBCheckError(TElZipStrongEncryptionInfo_set_UseOAEP(_Handle, (int8_t)Value));
}

bool TElZipStrongEncryptionInfo::get_Use3DES()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionInfo_get_Use3DES(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipStrongEncryptionInfo::set_Use3DES(bool Value)
{
	SBCheckError(TElZipStrongEncryptionInfo_set_Use3DES(_Handle, (int8_t)Value));
}

TElZipStrongEncryptionInfo::TElZipStrongEncryptionInfo(TElZipStrongEncryptionInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElZipStrongEncryptionInfo::TElZipStrongEncryptionInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipStrongEncryptionInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElZipStrongEncryptionSignatureInfo::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipStrongEncryptionSignatureInfo_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElZipStrongEncryptionSignatureInfo::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipStrongEncryptionSignatureInfo_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-740874000, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElZipStrongEncryptionSignatureInfo::get_SignatureData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipStrongEncryptionSignatureInfo_get_SignatureData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1139348860, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint32_t TElZipStrongEncryptionSignatureInfo::get_HashAlgorithm()
{
	uint32_t OutResult;
	SBCheckError(TElZipStrongEncryptionSignatureInfo_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

void TElZipStrongEncryptionSignatureInfo::get_ContentHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipStrongEncryptionSignatureInfo_get_ContentHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1634167042, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipStrongEncryptionSignatureInfo::set_ContentHash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipStrongEncryptionSignatureInfo_set_ContentHash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElZipStrongEncryptionSignatureInfo::get_SigningCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipStrongEncryptionSignatureInfo_get_SigningCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificate)
		this->_Inst_SigningCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificate->updateHandle(hOutResult);
	return this->_Inst_SigningCertificate;
}

SB_INLINE void TElZipStrongEncryptionSignatureInfo::set_SigningCertificate(TElX509Certificate &Value)
{
	SBCheckError(TElZipStrongEncryptionSignatureInfo_set_SigningCertificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipStrongEncryptionSignatureInfo::set_SigningCertificate(TElX509Certificate *Value)
{
	SBCheckError(TElZipStrongEncryptionSignatureInfo_set_SigningCertificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElZipStrongEncryptionSignatureInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}

TElZipStrongEncryptionSignatureInfo::TElZipStrongEncryptionSignatureInfo(TElZipStrongEncryptionSignatureInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElZipStrongEncryptionSignatureInfo::TElZipStrongEncryptionSignatureInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipStrongEncryptionSignatureInfo_Create(&_Handle));
}

TElZipStrongEncryptionSignatureInfo::~TElZipStrongEncryptionSignatureInfo()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SigningCertificate;
	this->_Inst_SigningCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO */

#ifdef SB_USE_CLASS_TELZIPPROCESSINGUNIT

SB_INLINE void TElZipProcessingUnit::InitializeProcessing()
{
	SBCheckError(TElZipProcessingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipProcessingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipProcessingUnit_FinalizeProcessing(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElZipProcessingUnit::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipProcessingUnit_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElZipProcessingUnit::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElZipProcessingUnit_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipProcessingUnit::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElZipProcessingUnit_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
TElZipArchiveDirectoryEntry* TElZipProcessingUnit::get_ProcessingEntry()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipProcessingUnit_get_ProcessingEntry(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProcessingEntry)
		this->_Inst_ProcessingEntry = new TElZipArchiveDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_ProcessingEntry->updateHandle(hOutResult);
	return this->_Inst_ProcessingEntry;
}

SB_INLINE void TElZipProcessingUnit::set_ProcessingEntry(TElZipArchiveDirectoryEntry &Value)
{
	SBCheckError(TElZipProcessingUnit_set_ProcessingEntry(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipProcessingUnit::set_ProcessingEntry(TElZipArchiveDirectoryEntry *Value)
{
	SBCheckError(TElZipProcessingUnit_set_ProcessingEntry(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

SB_INLINE uint32_t TElZipProcessingUnit::get_CRC32()
{
	uint32_t OutResult;
	SBCheckError(TElZipProcessingUnit_get_CRC32(_Handle, &OutResult));
	return OutResult;
}

void TElZipProcessingUnit::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
	this->_Inst_ProcessingEntry = NULL;
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */
}

TElZipProcessingUnit::TElZipProcessingUnit(TElZipProcessingUnitHandle handle, TElOwnHandle ownHandle) : TElArcProcessingUnit(handle, ownHandle)
{
	initInstances();
}

TElZipProcessingUnit::TElZipProcessingUnit() : TElArcProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipProcessingUnit_Create(&_Handle));
}

TElZipProcessingUnit::~TElZipProcessingUnit()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
	delete this->_Inst_ProcessingEntry;
	this->_Inst_ProcessingEntry = NULL;
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */
}
#endif /* SB_USE_CLASS_TELZIPPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTOREDPROCESSINGUNIT

SB_INLINE void TElZipStoredProcessingUnit::InitializeProcessing()
{
	SBCheckError(TElZipStoredProcessingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipStoredProcessingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipStoredProcessingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipStoredProcessingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipStoredProcessingUnit_FinalizeProcessing(_Handle));
}

TElZipStoredProcessingUnit::TElZipStoredProcessingUnit(TElZipStoredProcessingUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipStoredProcessingUnit::TElZipStoredProcessingUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipStoredProcessingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPSTOREDPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPDEFLATEDECOMPRESSINGUNIT

SB_INLINE void TElZipDeflateDecompressingUnit::InitializeProcessing()
{
	SBCheckError(TElZipDeflateDecompressingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipDeflateDecompressingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipDeflateDecompressingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipDeflateDecompressingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipDeflateDecompressingUnit_FinalizeProcessing(_Handle));
}

bool TElZipDeflateDecompressingUnit::get_Deflate64()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDeflateDecompressingUnit_get_Deflate64(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDeflateDecompressingUnit::set_Deflate64(bool Value)
{
	SBCheckError(TElZipDeflateDecompressingUnit_set_Deflate64(_Handle, (int8_t)Value));
}

TElZipDeflateDecompressingUnit::TElZipDeflateDecompressingUnit(TElZipDeflateDecompressingUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipDeflateDecompressingUnit::TElZipDeflateDecompressingUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipDeflateDecompressingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPDEFLATEDECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPDEFLATECOMPRESSINGUNIT

SB_INLINE void TElZipDeflateCompressingUnit::InitializeProcessing()
{
	SBCheckError(TElZipDeflateCompressingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipDeflateCompressingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipDeflateCompressingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipDeflateCompressingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipDeflateCompressingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElZipDeflateCompressingUnit::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElZipDeflateCompressingUnit_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipDeflateCompressingUnit::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElZipDeflateCompressingUnit_set_CompressionLevel(_Handle, Value));
}

bool TElZipDeflateCompressingUnit::get_Deflate64()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDeflateCompressingUnit_get_Deflate64(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDeflateCompressingUnit::set_Deflate64(bool Value)
{
	SBCheckError(TElZipDeflateCompressingUnit_set_Deflate64(_Handle, (int8_t)Value));
}

TElZipDeflateCompressingUnit::TElZipDeflateCompressingUnit(TElZipDeflateCompressingUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipDeflateCompressingUnit::TElZipDeflateCompressingUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipDeflateCompressingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPDEFLATECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPBZIP2DECOMPRESSINGUNIT

SB_INLINE void TElZipBZip2DecompressingUnit::InitializeProcessing()
{
	SBCheckError(TElZipBZip2DecompressingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipBZip2DecompressingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipBZip2DecompressingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipBZip2DecompressingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipBZip2DecompressingUnit_FinalizeProcessing(_Handle));
}

TElZipBZip2DecompressingUnit::TElZipBZip2DecompressingUnit(TElZipBZip2DecompressingUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipBZip2DecompressingUnit::TElZipBZip2DecompressingUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipBZip2DecompressingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPBZIP2DECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPBZIP2COMPRESSINGUNIT

SB_INLINE void TElZipBZip2CompressingUnit::InitializeProcessing()
{
	SBCheckError(TElZipBZip2CompressingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipBZip2CompressingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipBZip2CompressingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipBZip2CompressingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipBZip2CompressingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElZipBZip2CompressingUnit::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElZipBZip2CompressingUnit_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipBZip2CompressingUnit::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElZipBZip2CompressingUnit_set_CompressionLevel(_Handle, Value));
}

TElZipBZip2CompressingUnit::TElZipBZip2CompressingUnit(TElZipBZip2CompressingUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipBZip2CompressingUnit::TElZipBZip2CompressingUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipBZip2CompressingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPBZIP2COMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPOLDSTYLEENCRYPTINGUNIT

SB_INLINE void TElZipOldStyleEncryptingUnit::InitializeProcessing()
{
	SBCheckError(TElZipOldStyleEncryptingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipOldStyleEncryptingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipOldStyleEncryptingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipOldStyleEncryptingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipOldStyleEncryptingUnit_FinalizeProcessing(_Handle));
}

void TElZipOldStyleEncryptingUnit::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipOldStyleEncryptingUnit_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1947991709, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipOldStyleEncryptingUnit::set_Password(const std::string &Value)
{
	SBCheckError(TElZipOldStyleEncryptingUnit_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElZipOldStyleEncryptingUnit::get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipOldStyleEncryptingUnit_get_OnPasswordNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipOldStyleEncryptingUnit::set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipOldStyleEncryptingUnit_set_OnPasswordNeeded(_Handle, pMethodValue, pDataValue));
}

TElZipOldStyleEncryptingUnit::TElZipOldStyleEncryptingUnit(TElZipOldStyleEncryptingUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipOldStyleEncryptingUnit::TElZipOldStyleEncryptingUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipOldStyleEncryptingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPOLDSTYLEENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPOLDSTYLEDECRYPTINGUNIT

SB_INLINE void TElZipOldStyleDecryptingUnit::InitializeProcessing()
{
	SBCheckError(TElZipOldStyleDecryptingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipOldStyleDecryptingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipOldStyleDecryptingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipOldStyleDecryptingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipOldStyleDecryptingUnit_FinalizeProcessing(_Handle));
}

void TElZipOldStyleDecryptingUnit::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipOldStyleDecryptingUnit_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1108793960, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipOldStyleDecryptingUnit::set_Password(const std::string &Value)
{
	SBCheckError(TElZipOldStyleDecryptingUnit_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElZipOldStyleDecryptingUnit::get_HeaderRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipOldStyleDecryptingUnit_get_HeaderRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipOldStyleDecryptingUnit::get_IgnorePasswordCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipOldStyleDecryptingUnit_get_IgnorePasswordCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipOldStyleDecryptingUnit::set_IgnorePasswordCheck(bool Value)
{
	SBCheckError(TElZipOldStyleDecryptingUnit_set_IgnorePasswordCheck(_Handle, (int8_t)Value));
}

SB_INLINE void TElZipOldStyleDecryptingUnit::get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipOldStyleDecryptingUnit_get_OnPasswordNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipOldStyleDecryptingUnit::set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipOldStyleDecryptingUnit_set_OnPasswordNeeded(_Handle, pMethodValue, pDataValue));
}

TElZipOldStyleDecryptingUnit::TElZipOldStyleDecryptingUnit(TElZipOldStyleDecryptingUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipOldStyleDecryptingUnit::TElZipOldStyleDecryptingUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipOldStyleDecryptingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPOLDSTYLEDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONBASEUNIT

SB_INLINE void TElZipStrongEncryptionBaseUnit::get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipStrongEncryptionBaseUnit_get_OnPasswordNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipStrongEncryptionBaseUnit::set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipStrongEncryptionBaseUnit_set_OnPasswordNeeded(_Handle, pMethodValue, pDataValue));
}

TElZipStrongEncryptionBaseUnit::TElZipStrongEncryptionBaseUnit(TElZipStrongEncryptionBaseUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipStrongEncryptionBaseUnit::TElZipStrongEncryptionBaseUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipStrongEncryptionBaseUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONBASEUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONENCRYPTINGUNIT

SB_INLINE void TElZipStrongEncryptionEncryptingUnit::InitializeProcessing()
{
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipStrongEncryptionEncryptingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipStrongEncryptionEncryptingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElZipStrongEncryptionEncryptingUnit::get_EncryptionAlgorithm()
{
	uint32_t OutResult;
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipStrongEncryptionEncryptingUnit::set_EncryptionAlgorithm(uint32_t Value)
{
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_set_EncryptionAlgorithm(_Handle, Value));
}

SB_INLINE uint32_t TElZipStrongEncryptionEncryptingUnit::get_EncryptionKeySize()
{
	uint32_t OutResult;
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_get_EncryptionKeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipStrongEncryptionEncryptingUnit::set_EncryptionKeySize(uint32_t Value)
{
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_set_EncryptionKeySize(_Handle, Value));
}

void TElZipStrongEncryptionEncryptingUnit::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipStrongEncryptionEncryptingUnit_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2021658764, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipStrongEncryptionEncryptingUnit::set_Password(const std::string &Value)
{
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElZipStrongEncryptionEncryptingUnit::get_UseTripleDES()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_get_UseTripleDES(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipStrongEncryptionEncryptingUnit::set_UseTripleDES(bool Value)
{
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_set_UseTripleDES(_Handle, (int8_t)Value));
}

TElZipStrongEncryptionEncryptingUnit::TElZipStrongEncryptionEncryptingUnit(TElZipStrongEncryptionEncryptingUnitHandle handle, TElOwnHandle ownHandle) : TElZipStrongEncryptionBaseUnit(handle, ownHandle)
{
}

TElZipStrongEncryptionEncryptingUnit::TElZipStrongEncryptionEncryptingUnit() : TElZipStrongEncryptionBaseUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipStrongEncryptionEncryptingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONDECRYPTINGUNIT

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::InitializeProcessing()
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElZipStrongEncryptionDecryptingUnit::get_FileCRC32()
{
	uint32_t OutResult;
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_get_FileCRC32(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::set_FileCRC32(uint32_t Value)
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_set_FileCRC32(_Handle, Value));
}

SB_INLINE int64_t TElZipStrongEncryptionDecryptingUnit::get_FileSize()
{
	int64_t OutResult;
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_get_FileSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::set_FileSize(int64_t Value)
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_set_FileSize(_Handle, Value));
}

void TElZipStrongEncryptionDecryptingUnit::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipStrongEncryptionDecryptingUnit_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1317876849, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::set_Password(const std::string &Value)
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElZipStrongEncryptionDecryptingUnit::get_OAEPUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_get_OAEPUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipStrongEncryptionDecryptingUnit::get_TripleDESUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_get_TripleDESUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipStrongEncryptionDecryptingUnit::get_PasswordUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_get_PasswordUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipStrongEncryptionDecryptingUnit::get_PublicKeyUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_get_PublicKeyUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElZipStrongEncryptionDecryptingUnit::get_Recipient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_get_Recipient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Recipient)
		this->_Inst_Recipient = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Recipient->updateHandle(hOutResult);
	return this->_Inst_Recipient;
}

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::set_Recipient(TElX509Certificate &Value)
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_set_Recipient(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::set_Recipient(TElX509Certificate *Value)
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_set_Recipient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::get_OnPrivateKeyNeeded(TSBZipPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_get_OnPrivateKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipStrongEncryptionDecryptingUnit::set_OnPrivateKeyNeeded(TSBZipPrivateKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_set_OnPrivateKeyNeeded(_Handle, pMethodValue, pDataValue));
}

void TElZipStrongEncryptionDecryptingUnit::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Recipient = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}

TElZipStrongEncryptionDecryptingUnit::TElZipStrongEncryptionDecryptingUnit(TElZipStrongEncryptionDecryptingUnitHandle handle, TElOwnHandle ownHandle) : TElZipStrongEncryptionBaseUnit(handle, ownHandle)
{
	initInstances();
}

TElZipStrongEncryptionDecryptingUnit::TElZipStrongEncryptionDecryptingUnit() : TElZipStrongEncryptionBaseUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipStrongEncryptionDecryptingUnit_Create(&_Handle));
}

TElZipStrongEncryptionDecryptingUnit::~TElZipStrongEncryptionDecryptingUnit()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Recipient;
	this->_Inst_Recipient = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONHASHINGUNIT

SB_INLINE void TElZipStrongEncryptionHashingUnit::ClearHashFunctions()
{
	SBCheckError(TElZipStrongEncryptionHashingUnit_ClearHashFunctions(_Handle));
}

SB_INLINE void TElZipStrongEncryptionHashingUnit::InitializeProcessing()
{
	SBCheckError(TElZipStrongEncryptionHashingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipStrongEncryptionHashingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipStrongEncryptionHashingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipStrongEncryptionHashingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipStrongEncryptionHashingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElZipStrongEncryptionHashingUnit::get_HashAlgorithm()
{
	uint32_t OutResult;
	SBCheckError(TElZipStrongEncryptionHashingUnit_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipStrongEncryptionHashingUnit::set_HashAlgorithm(uint32_t Value)
{
	SBCheckError(TElZipStrongEncryptionHashingUnit_set_HashAlgorithm(_Handle, Value));
}

void TElZipStrongEncryptionHashingUnit::get_Hash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipStrongEncryptionHashingUnit_get_Hash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(362641037, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElZipStrongEncryptionHashingUnit::TElZipStrongEncryptionHashingUnit(TElZipStrongEncryptionHashingUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipStrongEncryptionHashingUnit::TElZipStrongEncryptionHashingUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipStrongEncryptionHashingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONHASHINGUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESBASEUNIT

SB_INLINE void TElZipWinZipAesBaseUnit::InitializeProcessing()
{
	SBCheckError(TElZipWinZipAesBaseUnit_InitializeProcessing(_Handle));
}

void TElZipWinZipAesBaseUnit::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipWinZipAesBaseUnit_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(477075349, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipWinZipAesBaseUnit::set_Password(const std::string &Value)
{
	SBCheckError(TElZipWinZipAesBaseUnit_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElZipWinZipAesBaseUnit::get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipWinZipAesBaseUnit_get_OnPasswordNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipWinZipAesBaseUnit::set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipWinZipAesBaseUnit_set_OnPasswordNeeded(_Handle, pMethodValue, pDataValue));
}

TElZipWinZipAesBaseUnit::TElZipWinZipAesBaseUnit(TElZipWinZipAesBaseUnitHandle handle, TElOwnHandle ownHandle) : TElZipProcessingUnit(handle, ownHandle)
{
}

TElZipWinZipAesBaseUnit::TElZipWinZipAesBaseUnit() : TElZipProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipWinZipAesBaseUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPWINZIPAESBASEUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESDECRYPTINGUNIT

SB_INLINE void TElZipWinZipAesDecryptingUnit::InitializeProcessing()
{
	SBCheckError(TElZipWinZipAesDecryptingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipWinZipAesDecryptingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipWinZipAesDecryptingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipWinZipAesDecryptingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipWinZipAesDecryptingUnit_FinalizeProcessing(_Handle));
}

TElZipWinZipAesDecryptingUnit::TElZipWinZipAesDecryptingUnit(TElZipWinZipAesDecryptingUnitHandle handle, TElOwnHandle ownHandle) : TElZipWinZipAesBaseUnit(handle, ownHandle)
{
}

TElZipWinZipAesDecryptingUnit::TElZipWinZipAesDecryptingUnit() : TElZipWinZipAesBaseUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipWinZipAesDecryptingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPWINZIPAESDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESENCRYPTINGUNIT

SB_INLINE void TElZipWinZipAesEncryptingUnit::InitializeProcessing()
{
	SBCheckError(TElZipWinZipAesEncryptingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElZipWinZipAesEncryptingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipWinZipAesEncryptingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElZipWinZipAesEncryptingUnit::FinalizeProcessing()
{
	SBCheckError(TElZipWinZipAesEncryptingUnit_FinalizeProcessing(_Handle));
}

TElZipWinZipAesEncryptingUnit::TElZipWinZipAesEncryptingUnit(TElZipWinZipAesEncryptingUnitHandle handle, TElOwnHandle ownHandle) : TElZipWinZipAesBaseUnit(handle, ownHandle)
{
}

TElZipWinZipAesEncryptingUnit::TElZipWinZipAesEncryptingUnit() : TElZipWinZipAesBaseUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipWinZipAesEncryptingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPWINZIPAESENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPREADER

SB_INLINE void TElZipReader::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElZipReader_Open(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElZipReader::Open(TStream &Stream)
{
	SBCheckError(TElZipReader_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElZipReader::Open(TStream *Stream)
{
	SBCheckError(TElZipReader_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElZipReader::Close()
{
	SBCheckError(TElZipReader_Close(_Handle));
}

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE void TElZipReader::Extract(TElZipArchiveDirectoryEntry &Entry, const std::string &OutputPath)
{
	SBCheckError(TElZipReader_Extract(_Handle, Entry.getHandle(), OutputPath.data(), (int32_t)OutputPath.length()));
}

SB_INLINE void TElZipReader::Extract(TElZipArchiveDirectoryEntry *Entry, const std::string &OutputPath)
{
	SBCheckError(TElZipReader_Extract(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, OutputPath.data(), (int32_t)OutputPath.length()));
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElZipReader::Extract(TList &Entries, const std::string &OutputPath)
{
	SBCheckError(TElZipReader_Extract_1(_Handle, Entries.getHandle(), OutputPath.data(), (int32_t)OutputPath.length()));
}

SB_INLINE void TElZipReader::Extract(TList *Entries, const std::string &OutputPath)
{
	SBCheckError(TElZipReader_Extract_1(_Handle, (Entries != NULL) ? Entries->getHandle() : SB_NULL_HANDLE, OutputPath.data(), (int32_t)OutputPath.length()));
}
#endif /* SB_USE_CLASS_TLIST */

SB_INLINE void TElZipReader::Extract(const std::string &Mask, const std::string &OutputPath)
{
	SBCheckError(TElZipReader_Extract_2(_Handle, Mask.data(), (int32_t)Mask.length(), OutputPath.data(), (int32_t)OutputPath.length()));
}

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
void TElZipReader::ExtractContents(TElZipArchiveDirectoryEntry &Entry, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipReader_ExtractContents(_Handle, Entry.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1992332420, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElZipReader::ExtractContents(TElZipArchiveDirectoryEntry *Entry, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipReader_ExtractContents(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1992332420, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
bool TElZipReader::ValidateSignature(TElZipArchiveDirectoryEntry &Entry, int32_t SignatureIndex)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_ValidateSignature(_Handle, Entry.getHandle(), SignatureIndex, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipReader::ValidateSignature(TElZipArchiveDirectoryEntry *Entry, int32_t SignatureIndex)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_ValidateSignature(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, SignatureIndex, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

bool TElZipReader::ValidateDirectorySignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_ValidateDirectorySignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
bool TElZipReader::CheckEntry(TElZipArchiveDirectoryEntry &Entry)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_CheckEntry(_Handle, Entry.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipReader::CheckEntry(TElZipArchiveDirectoryEntry *Entry)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_CheckEntry(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

bool TElZipReader::CheckArchive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_CheckArchive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipReader::get_DirectoryCompressed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_get_DirectoryCompressed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipReader::set_DirectoryCompressed(bool Value)
{
	SBCheckError(TElZipReader_set_DirectoryCompressed(_Handle, (int8_t)Value));
}

bool TElZipReader::get_DirectoryEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_get_DirectoryEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipReader::set_DirectoryEncrypted(bool Value)
{
	SBCheckError(TElZipReader_set_DirectoryEncrypted(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
TElZipArchiveDirectoryEntry* TElZipReader::get_Directory()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipReader_get_Directory(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Directory)
		this->_Inst_Directory = new TElZipArchiveDirectoryEntry(hOutResult, ohFalse);
	else
		this->_Inst_Directory->updateHandle(hOutResult);
	return this->_Inst_Directory;
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

void TElZipReader::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipReader_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2082266901, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipReader::set_Password(const std::string &Value)
{
	SBCheckError(TElZipReader_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElZipReader::get_ArchiveComment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipReader_get_ArchiveComment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1711072523, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipReader::set_ArchiveComment(const std::string &Value)
{
	SBCheckError(TElZipReader_set_ArchiveComment(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElZipReader::get_SigningCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipReader_get_SigningCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificates)
		this->_Inst_SigningCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificates->updateHandle(hOutResult);
	return this->_Inst_SigningCertificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElZipReader::get_EncryptingCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipReader_get_EncryptingCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptingCertificates)
		this->_Inst_EncryptingCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_EncryptingCertificates->updateHandle(hOutResult);
	return this->_Inst_EncryptingCertificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElZipReader::get_IgnorePasswordCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_get_IgnorePasswordCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipReader::set_IgnorePasswordCheck(bool Value)
{
	SBCheckError(TElZipReader_set_IgnorePasswordCheck(_Handle, (int8_t)Value));
}

bool TElZipReader::get_RestoreAttributes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_get_RestoreAttributes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipReader::set_RestoreAttributes(bool Value)
{
	SBCheckError(TElZipReader_set_RestoreAttributes(_Handle, (int8_t)Value));
}

void TElZipReader::get_FilenamesCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipReader_get_FilenamesCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1297193628, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipReader::set_FilenamesCharset(const std::string &Value)
{
	SBCheckError(TElZipReader_set_FilenamesCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElZipReader::get_IgnoreArchiveErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_get_IgnoreArchiveErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipReader::set_IgnoreArchiveErrors(bool Value)
{
	SBCheckError(TElZipReader_set_IgnoreArchiveErrors(_Handle, (int8_t)Value));
}

bool TElZipReader::get_CaseSensitiveFilenames()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_get_CaseSensitiveFilenames(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipReader::set_CaseSensitiveFilenames(bool Value)
{
	SBCheckError(TElZipReader_set_CaseSensitiveFilenames(_Handle, (int8_t)Value));
}

void TElZipReader::get_MimeType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipReader_get_MimeType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1859372729, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
void TElZipReader::get_SFXCopyright(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipReader_get_SFXCopyright(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1429643333, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipReader::set_SFXCopyright(const std::string &Value)
{
	SBCheckError(TElZipReader_set_SFXCopyright(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElZipReader::get_SFXEnabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipReader_get_SFXEnabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipReader::set_SFXEnabled(bool Value)
{
	SBCheckError(TElZipReader_set_SFXEnabled(_Handle, (int8_t)Value));
}

void TElZipReader::get_SFXTitle(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipReader_get_SFXTitle(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-437208463, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipReader::set_SFXTitle(const std::string &Value)
{
	SBCheckError(TElZipReader_set_SFXTitle(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElZipReader::get_StubName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipReader_get_StubName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1900843673, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipReader::set_StubName(const std::string &Value)
{
	SBCheckError(TElZipReader_set_StubName(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBZIPStubSource TElZipReader::get_StubSource()
{
	TSBZIPStubSourceRaw OutResultRaw = 0;
	SBCheckError(TElZipReader_get_StubSource(_Handle, &OutResultRaw));
	return (TSBZIPStubSource)OutResultRaw;
}

SB_INLINE void TElZipReader::set_StubSource(TSBZIPStubSource Value)
{
	SBCheckError(TElZipReader_set_StubSource(_Handle, (TSBZIPStubSourceRaw)Value));
}
#endif

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElZipReader::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipReader_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElZipReader::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElZipReader_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipReader::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElZipReader_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElZipReader::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipReader_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElZipReader::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElZipReader_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipReader::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElZipReader_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

SB_INLINE void TElZipReader::get_OnExtractionStreamNeeded(TSBZipExtractionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnExtractionStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnExtractionStreamNeeded(TSBZipExtractionStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnExtractionStreamNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipReader::get_OnExtractionMakeDirectory(TSBZipExtractionMakeDirectoryEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnExtractionMakeDirectory(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnExtractionMakeDirectory(TSBZipExtractionMakeDirectoryEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnExtractionMakeDirectory(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipReader::get_OnProgress(TSBZipProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnProgress(TSBZipProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipReader::get_OnExtractionStart(TSBZipExtractionStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnExtractionStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnExtractionStart(TSBZipExtractionStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnExtractionStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipReader::get_OnExtractionFinished(TSBZipExtractionFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnExtractionFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnExtractionFinished(TSBZipExtractionFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnExtractionFinished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipReader::get_OnUserActionNeeded(TSBZipUserActionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnUserActionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnUserActionNeeded(TSBZipUserActionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnUserActionNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipReader::get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnPasswordNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnPasswordNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipReader::get_OnPrivateKeyNeeded(TSBZipPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnPrivateKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnPrivateKeyNeeded(TSBZipPrivateKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnPrivateKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipReader::get_OnArchiveError(TSBZipArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipReader_get_OnArchiveError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipReader::set_OnArchiveError(TSBZipArchiveErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipReader_set_OnArchiveError(_Handle, pMethodValue, pDataValue));
}

void TElZipReader::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
	this->_Inst_Directory = NULL;
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_EncryptingCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElZipReader::TElZipReader(TElZipReaderHandle handle, TElOwnHandle ownHandle) : TElBaseArchive(handle, ownHandle)
{
	initInstances();
}

TElZipReader::TElZipReader(TComponent &AOwner) : TElBaseArchive(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipReader_Create(AOwner.getHandle(), &_Handle));
}

TElZipReader::TElZipReader(TComponent *AOwner) : TElBaseArchive(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipReader_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElZipReader::~TElZipReader()
{
#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
	delete this->_Inst_Directory;
	this->_Inst_Directory = NULL;
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_SigningCertificates;
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_EncryptingCertificates;
	this->_Inst_EncryptingCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELZIPREADER */

#ifdef SB_USE_CLASS_TELZIPWRITER

SB_INLINE void TElZipWriter::CreateArchive()
{
	SBCheckError(TElZipWriter_CreateArchive(_Handle));
}

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TElZipArchiveDirectoryEntry &Parent, const std::string &Path)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add(_Handle, Parent.getHandle(), Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TElZipArchiveDirectoryEntry *Parent, const std::string &Path)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(const std::string &Path)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_1(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TElZipArchiveDirectoryEntry &Parent, TStream &Stream)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_2(_Handle, Parent.getHandle(), Stream.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TElZipArchiveDirectoryEntry *Parent, TStream *Stream)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_2(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TStream &Stream)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_3(_Handle, Stream.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TStream *Stream)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TElZipArchiveDirectoryEntry &Parent, TStream &Stream, const std::string &FileName)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_4(_Handle, Parent.getHandle(), Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TElZipArchiveDirectoryEntry *Parent, TStream *Stream, const std::string &FileName)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_4(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TStream &Stream, const std::string &FileName)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_5(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TStream *Stream, const std::string &FileName)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_5(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TElZipArchiveDirectoryEntry &Parent, const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_6(_Handle, Parent.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), StartIndex, Count, FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(TElZipArchiveDirectoryEntry *Parent, const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_6(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), StartIndex, Count, FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::Add(const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_Add_7(_Handle, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), StartIndex, Count, FileName.data(), (int32_t)FileName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

SB_INLINE void TElZipWriter::AddDirContents(const std::string &Path)
{
	SBCheckError(TElZipWriter_AddDirContents(_Handle, Path.data(), (int32_t)Path.length()));
}

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE void TElZipWriter::AddDirContents(TElZipArchiveDirectoryEntry &Parent, const std::string &Path)
{
	SBCheckError(TElZipWriter_AddDirContents_1(_Handle, Parent.getHandle(), Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElZipWriter::AddDirContents(TElZipArchiveDirectoryEntry *Parent, const std::string &Path)
{
	SBCheckError(TElZipWriter_AddDirContents_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Path.data(), (int32_t)Path.length()));
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

SB_INLINE void TElZipWriter::AddDirContents(const std::string &Path, const std::string &Mask)
{
	SBCheckError(TElZipWriter_AddDirContents_2(_Handle, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length()));
}

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE void TElZipWriter::AddDirContents(TElZipArchiveDirectoryEntry &Parent, const std::string &Path, const std::string &Mask)
{
	SBCheckError(TElZipWriter_AddDirContents_3(_Handle, Parent.getHandle(), Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length()));
}

SB_INLINE void TElZipWriter::AddDirContents(TElZipArchiveDirectoryEntry *Parent, const std::string &Path, const std::string &Mask)
{
	SBCheckError(TElZipWriter_AddDirContents_3(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length()));
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::MakeDir(const std::string &Path)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_MakeDir(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::MakeDir(TElZipArchiveDirectoryEntry &Parent, const std::string &Path)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_MakeDir_1(_Handle, Parent.getHandle(), Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElZipArchiveDirectoryEntryHandle TElZipWriter::MakeDir(TElZipArchiveDirectoryEntry *Parent, const std::string &Path)
{
	TElZipArchiveDirectoryEntryHandle OutResult;
	SBCheckError(TElZipWriter_MakeDir_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

SB_INLINE void TElZipWriter::Remove(const std::string &Mask)
{
	SBCheckError(TElZipWriter_Remove(_Handle, Mask.data(), (int32_t)Mask.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElZipWriter::BeginCompression(TStream &Destination)
{
	SBCheckError(TElZipWriter_BeginCompression(_Handle, Destination.getHandle()));
}

SB_INLINE void TElZipWriter::BeginCompression(TStream *Destination)
{
	SBCheckError(TElZipWriter_BeginCompression(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElZipWriter::BeginCompression(const std::string &Destination)
{
	SBCheckError(TElZipWriter_BeginCompression_1(_Handle, Destination.data(), (int32_t)Destination.length()));
}

SB_INLINE void TElZipWriter::UpdateCompression()
{
	SBCheckError(TElZipWriter_UpdateCompression(_Handle));
}

SB_INLINE void TElZipWriter::EndCompression()
{
	SBCheckError(TElZipWriter_EndCompression(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElZipWriter::Compress(TStream &Destination)
{
	SBCheckError(TElZipWriter_Compress(_Handle, Destination.getHandle()));
}

SB_INLINE void TElZipWriter::Compress(TStream *Destination)
{
	SBCheckError(TElZipWriter_Compress(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElZipWriter::Compress(const std::string &Destination)
{
	SBCheckError(TElZipWriter_Compress_1(_Handle, Destination.data(), (int32_t)Destination.length()));
}

SB_INLINE void TElZipWriter::Compress()
{
	SBCheckError(TElZipWriter_Compress_2(_Handle));
}

SB_INLINE void TElZipWriter::Close()
{
	SBCheckError(TElZipWriter_Close(_Handle));
}

TSBArcReplaceMode TElZipWriter::get_ReplaceMode()
{
	TSBArcReplaceModeRaw OutResultRaw = 0;
	SBCheckError(TElZipWriter_get_ReplaceMode(_Handle, &OutResultRaw));
	return (TSBArcReplaceMode)OutResultRaw;
}

SB_INLINE void TElZipWriter::set_ReplaceMode(TSBArcReplaceMode Value)
{
	SBCheckError(TElZipWriter_set_ReplaceMode(_Handle, (TSBArcReplaceModeRaw)Value));
}

bool TElZipWriter::get_NewArchive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipWriter_get_NewArchive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElZipWriter::get_CompressionAlgorithm()
{
	uint32_t OutResult;
	SBCheckError(TElZipWriter_get_CompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipWriter::set_CompressionAlgorithm(uint32_t Value)
{
	SBCheckError(TElZipWriter_set_CompressionAlgorithm(_Handle, Value));
}

SB_INLINE uint32_t TElZipWriter::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElZipWriter_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipWriter::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElZipWriter_set_CompressionLevel(_Handle, Value));
}

bool TElZipWriter::get_Encrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipWriter_get_Encrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipWriter::set_Encrypt(bool Value)
{
	SBCheckError(TElZipWriter_set_Encrypt(_Handle, (int8_t)Value));
}

bool TElZipWriter::get_StrongEncryption()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipWriter_get_StrongEncryption(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipWriter::set_StrongEncryption(bool Value)
{
	SBCheckError(TElZipWriter_set_StrongEncryption(_Handle, (int8_t)Value));
}

bool TElZipWriter::get_WinZipEncryption()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipWriter_get_WinZipEncryption(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipWriter::set_WinZipEncryption(bool Value)
{
	SBCheckError(TElZipWriter_set_WinZipEncryption(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElZipWriter::get_WinZipAesKeySize()
{
	uint32_t OutResult;
	SBCheckError(TElZipWriter_get_WinZipAesKeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipWriter::set_WinZipAesKeySize(uint32_t Value)
{
	SBCheckError(TElZipWriter_set_WinZipAesKeySize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
TElZipStrongEncryptionInfo* TElZipWriter::get_StrongEncryptionInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipWriter_get_StrongEncryptionInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StrongEncryptionInfo)
		this->_Inst_StrongEncryptionInfo = new TElZipStrongEncryptionInfo(hOutResult, ohFalse);
	else
		this->_Inst_StrongEncryptionInfo->updateHandle(hOutResult);
	return this->_Inst_StrongEncryptionInfo;
}
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */

bool TElZipWriter::get_UseUTF8Filenames()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipWriter_get_UseUTF8Filenames(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipWriter::set_UseUTF8Filenames(bool Value)
{
	SBCheckError(TElZipWriter_set_UseUTF8Filenames(_Handle, (int8_t)Value));
}

void TElZipWriter::get_MimeType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZipWriter_get_MimeType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1612485505, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipWriter::set_MimeType(const std::string &Value)
{
	SBCheckError(TElZipWriter_set_MimeType(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElZipWriter::get_OnCompressionStreamNeeded(TSBZipCompressionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipWriter_get_OnCompressionStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipWriter::set_OnCompressionStreamNeeded(TSBZipCompressionStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipWriter_set_OnCompressionStreamNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipWriter::get_OnCompressionStart(TSBZipCompressionStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipWriter_get_OnCompressionStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipWriter::set_OnCompressionStart(TSBZipCompressionStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipWriter_set_OnCompressionStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipWriter::get_OnCompressionFinished(TSBZipCompressionFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipWriter_get_OnCompressionFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipWriter::set_OnCompressionFinished(TSBZipCompressionFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipWriter_set_OnCompressionFinished(_Handle, pMethodValue, pDataValue));
#ifndef SB_WINCE_OR_NOT_WINDOWS
}

SB_INLINE void TElZipWriter::get_OnGetStubStream(TSBZIPGetStubStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipWriter_get_OnGetStubStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipWriter::set_OnGetStubStream(TSBZIPGetStubStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipWriter_set_OnGetStubStream(_Handle, pMethodValue, pDataValue));
#endif
}

void TElZipWriter::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
	this->_Inst_StrongEncryptionInfo = NULL;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */
}

TElZipWriter::TElZipWriter(TElZipWriterHandle handle, TElOwnHandle ownHandle) : TElZipReader(handle, ownHandle)
{
	initInstances();
}

TElZipWriter::TElZipWriter(TComponent &AOwner) : TElZipReader(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipWriter_Create(AOwner.getHandle(), &_Handle));
}

TElZipWriter::TElZipWriter(TComponent *AOwner) : TElZipReader(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipWriter_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElZipWriter::~TElZipWriter()
{
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
	delete this->_Inst_StrongEncryptionInfo;
	this->_Inst_StrongEncryptionInfo = NULL;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */
}
#endif /* SB_USE_CLASS_TELZIPWRITER */

};	/* namespace SecureBlackbox */
