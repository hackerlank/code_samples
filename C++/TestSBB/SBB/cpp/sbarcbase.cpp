#include "sbarcbase.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBASEARCHIVE

SB_INLINE void TElBaseArchive::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElBaseArchive_Open(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBaseArchive::Open(TStream &Stream)
{
	SBCheckError(TElBaseArchive_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElBaseArchive::Open(TStream *Stream)
{
	SBCheckError(TElBaseArchive_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElBaseArchive::Close()
{
	SBCheckError(TElBaseArchive_Close(_Handle));
}

bool TElBaseArchive::get_Opened()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBaseArchive_get_Opened(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBaseArchive::get_IsReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBaseArchive_get_IsReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBaseArchive::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElBaseArchive_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElBaseArchive::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElBaseArchive_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

TElBaseArchive::TElBaseArchive(TElBaseArchiveHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElBaseArchive::TElBaseArchive(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBaseArchive_Create(AOwner.getHandle(), &_Handle));
}

TElBaseArchive::TElBaseArchive(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBaseArchive_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELBASEARCHIVE */

#ifdef SB_USE_CLASS_TELARCHIVEDIRECTORYENTRY

void TElArchiveDirectoryEntry::get_FileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElArchiveDirectoryEntry_get_FileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1319029840, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElArchiveDirectoryEntry::set_FileName(const std::string &Value)
{
	SBCheckError(TElArchiveDirectoryEntry_set_FileName(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElArchiveDirectoryEntry::get_FileSize()
{
	int64_t OutResult;
	SBCheckError(TElArchiveDirectoryEntry_get_FileSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElArchiveDirectoryEntry::set_FileSize(int64_t Value)
{
	SBCheckError(TElArchiveDirectoryEntry_set_FileSize(_Handle, Value));
}

SB_INLINE int64_t TElArchiveDirectoryEntry::get_FileDateCreated()
{
	int64_t OutResult;
	SBCheckError(TElArchiveDirectoryEntry_get_FileDateCreated(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElArchiveDirectoryEntry::set_FileDateCreated(int64_t Value)
{
	SBCheckError(TElArchiveDirectoryEntry_set_FileDateCreated(_Handle, Value));
}

SB_INLINE int64_t TElArchiveDirectoryEntry::get_FileDateModified()
{
	int64_t OutResult;
	SBCheckError(TElArchiveDirectoryEntry_get_FileDateModified(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElArchiveDirectoryEntry::set_FileDateModified(int64_t Value)
{
	SBCheckError(TElArchiveDirectoryEntry_set_FileDateModified(_Handle, Value));
}

SB_INLINE int64_t TElArchiveDirectoryEntry::get_FileDateAccessed()
{
	int64_t OutResult;
	SBCheckError(TElArchiveDirectoryEntry_get_FileDateAccessed(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElArchiveDirectoryEntry::set_FileDateAccessed(int64_t Value)
{
	SBCheckError(TElArchiveDirectoryEntry_set_FileDateAccessed(_Handle, Value));
}

SB_INLINE int64_t TElArchiveDirectoryEntry::get_CompressedSize()
{
	int64_t OutResult;
	SBCheckError(TElArchiveDirectoryEntry_get_CompressedSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElArchiveDirectoryEntry::set_CompressedSize(int64_t Value)
{
	SBCheckError(TElArchiveDirectoryEntry_set_CompressedSize(_Handle, Value));
}

bool TElArchiveDirectoryEntry::get_IsDirectory()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElArchiveDirectoryEntry_get_IsDirectory(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElArchiveDirectoryEntry::set_IsDirectory(bool Value)
{
	SBCheckError(TElArchiveDirectoryEntry_set_IsDirectory(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElArchiveDirectoryEntry::get_EntriesCount()
{
	int32_t OutResult;
	SBCheckError(TElArchiveDirectoryEntry_get_EntriesCount(_Handle, &OutResult));
	return OutResult;
}

TElArchiveDirectoryEntry::TElArchiveDirectoryEntry(TElArchiveDirectoryEntryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElArchiveDirectoryEntry::TElArchiveDirectoryEntry() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElArchiveDirectoryEntry_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELBASEARCHIVE
TElArchiveDirectoryEntry::TElArchiveDirectoryEntry(TElBaseArchive &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElArchiveDirectoryEntry_Create_1(Owner.getHandle(), &_Handle));
}

TElArchiveDirectoryEntry::TElArchiveDirectoryEntry(TElBaseArchive *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElArchiveDirectoryEntry_Create_1((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELBASEARCHIVE */

#endif /* SB_USE_CLASS_TELARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELARCPROCESSINGUNIT

SB_INLINE void TElArcProcessingUnit::InitializeProcessing()
{
	SBCheckError(TElArcProcessingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElArcProcessingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElArcProcessingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElArcProcessingUnit::FinalizeProcessing()
{
	SBCheckError(TElArcProcessingUnit_FinalizeProcessing(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElArcProcessingUnit::get_OutputStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElArcProcessingUnit_get_OutputStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OutputStream)
		this->_Inst_OutputStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_OutputStream->updateHandle(hOutResult);
	return this->_Inst_OutputStream;
}

SB_INLINE void TElArcProcessingUnit::set_OutputStream(TStream &Value)
{
	SBCheckError(TElArcProcessingUnit_set_OutputStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElArcProcessingUnit::set_OutputStream(TStream *Value)
{
	SBCheckError(TElArcProcessingUnit_set_OutputStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElArcProcessingUnit* TElArcProcessingUnit::get_OutputProcessingUnit()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElArcProcessingUnit_get_OutputProcessingUnit(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OutputProcessingUnit)
		this->_Inst_OutputProcessingUnit = new TElArcProcessingUnit(hOutResult, ohFalse);
	else
		this->_Inst_OutputProcessingUnit->updateHandle(hOutResult);
	return this->_Inst_OutputProcessingUnit;
}

SB_INLINE void TElArcProcessingUnit::set_OutputProcessingUnit(TElArcProcessingUnit &Value)
{
	SBCheckError(TElArcProcessingUnit_set_OutputProcessingUnit(_Handle, Value.getHandle()));
}

SB_INLINE void TElArcProcessingUnit::set_OutputProcessingUnit(TElArcProcessingUnit *Value)
{
	SBCheckError(TElArcProcessingUnit_set_OutputProcessingUnit(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int64_t TElArcProcessingUnit::get_ProcessedData()
{
	int64_t OutResult;
	SBCheckError(TElArcProcessingUnit_get_ProcessedData(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElArcProcessingUnit::set_ProcessedData(int64_t Value)
{
	SBCheckError(TElArcProcessingUnit_set_ProcessedData(_Handle, Value));
}

SB_INLINE int64_t TElArcProcessingUnit::get_WrittenData()
{
	int64_t OutResult;
	SBCheckError(TElArcProcessingUnit_get_WrittenData(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElArcProcessingUnit::set_WrittenData(int64_t Value)
{
	SBCheckError(TElArcProcessingUnit_set_WrittenData(_Handle, Value));
}

SB_INLINE void TElArcProcessingUnit::get_OutputEvent(TSBArcWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElArcProcessingUnit_get_OutputEvent(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElArcProcessingUnit::set_OutputEvent(TSBArcWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElArcProcessingUnit_set_OutputEvent(_Handle, pMethodValue, pDataValue));
}

void TElArcProcessingUnit::initInstances()
{
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_OutputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
	this->_Inst_OutputProcessingUnit = NULL;
}

TElArcProcessingUnit::TElArcProcessingUnit(TElArcProcessingUnitHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElArcProcessingUnit::TElArcProcessingUnit() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElArcProcessingUnit_Create(&_Handle));
}

TElArcProcessingUnit::~TElArcProcessingUnit()
{
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_OutputStream;
	this->_Inst_OutputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
	delete this->_Inst_OutputProcessingUnit;
	this->_Inst_OutputProcessingUnit = NULL;
}
#endif /* SB_USE_CLASS_TELARCPROCESSINGUNIT */

};	/* namespace SecureBlackbox */

