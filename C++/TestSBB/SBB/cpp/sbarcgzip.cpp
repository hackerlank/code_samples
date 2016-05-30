#include "sbarcgzip.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGZIPDECOMPRESSINGUNIT

SB_INLINE void TElGZipDecompressingUnit::InitializeProcessing()
{
	SBCheckError(TElGZipDecompressingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElGZipDecompressingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElGZipDecompressingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElGZipDecompressingUnit::FinalizeProcessing()
{
	SBCheckError(TElGZipDecompressingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElGZipDecompressingUnit::get_CRC32()
{
	uint32_t OutResult;
	SBCheckError(TElGZipDecompressingUnit_get_CRC32(_Handle, &OutResult));
	return OutResult;
}

TElGZipDecompressingUnit::TElGZipDecompressingUnit(TElGZipDecompressingUnitHandle handle, TElOwnHandle ownHandle) : TElArcProcessingUnit(handle, ownHandle)
{
}

TElGZipDecompressingUnit::TElGZipDecompressingUnit() : TElArcProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGZipDecompressingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGZIPDECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELGZIPCOMPRESSINGUNIT

SB_INLINE void TElGZipCompressingUnit::InitializeProcessing()
{
	SBCheckError(TElGZipCompressingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElGZipCompressingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElGZipCompressingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElGZipCompressingUnit::FinalizeProcessing()
{
	SBCheckError(TElGZipCompressingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElGZipCompressingUnit::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElGZipCompressingUnit_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipCompressingUnit::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElGZipCompressingUnit_set_CompressionLevel(_Handle, Value));
}

SB_INLINE uint32_t TElGZipCompressingUnit::get_CRC32()
{
	uint32_t OutResult;
	SBCheckError(TElGZipCompressingUnit_get_CRC32(_Handle, &OutResult));
	return OutResult;
}

TElGZipCompressingUnit::TElGZipCompressingUnit(TElGZipCompressingUnitHandle handle, TElOwnHandle ownHandle) : TElArcProcessingUnit(handle, ownHandle)
{
}

TElGZipCompressingUnit::TElGZipCompressingUnit() : TElArcProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGZipCompressingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGZIPCOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELGZIPFILEATTRIBUTES

SB_INLINE void TElGZipFileAttributes::Assign(TElGZipFileAttributes &Source)
{
	SBCheckError(TElGZipFileAttributes_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGZipFileAttributes::Assign(TElGZipFileAttributes *Source)
{
	SBCheckError(TElGZipFileAttributes_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGZipFileAttributes::AssignTo(TElGZipFileAttributes &Dest)
{
	SBCheckError(TElGZipFileAttributes_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElGZipFileAttributes::AssignTo(TElGZipFileAttributes *Dest)
{
	SBCheckError(TElGZipFileAttributes_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElGZipFileAttributes::get_FileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGZipFileAttributes_get_FileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(442654734, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGZipFileAttributes::set_FileName(const std::string &Value)
{
	SBCheckError(TElGZipFileAttributes_set_FileName(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElGZipFileAttributes::get_ModifyTime()
{
	int64_t OutResult;
	SBCheckError(TElGZipFileAttributes_get_ModifyTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipFileAttributes::set_ModifyTime(int64_t Value)
{
	SBCheckError(TElGZipFileAttributes_set_ModifyTime(_Handle, Value));
}

SB_INLINE int64_t TElGZipFileAttributes::get_FileSize()
{
	int64_t OutResult;
	SBCheckError(TElGZipFileAttributes_get_FileSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipFileAttributes::set_FileSize(int64_t Value)
{
	SBCheckError(TElGZipFileAttributes_set_FileSize(_Handle, Value));
}

SB_INLINE uint8_t TElGZipFileAttributes::get_Flag()
{
	uint8_t OutResult;
	SBCheckError(TElGZipFileAttributes_get_Flag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipFileAttributes::set_Flag(uint8_t Value)
{
	SBCheckError(TElGZipFileAttributes_set_Flag(_Handle, Value));
}

SB_INLINE uint8_t TElGZipFileAttributes::get_ExtraFlag()
{
	uint8_t OutResult;
	SBCheckError(TElGZipFileAttributes_get_ExtraFlag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipFileAttributes::set_ExtraFlag(uint8_t Value)
{
	SBCheckError(TElGZipFileAttributes_set_ExtraFlag(_Handle, Value));
}

SB_INLINE uint32_t TElGZipFileAttributes::get_CRC16()
{
	uint32_t OutResult;
	SBCheckError(TElGZipFileAttributes_get_CRC16(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipFileAttributes::set_CRC16(uint32_t Value)
{
	SBCheckError(TElGZipFileAttributes_set_CRC16(_Handle, Value));
}

SB_INLINE uint32_t TElGZipFileAttributes::get_CRC32()
{
	uint32_t OutResult;
	SBCheckError(TElGZipFileAttributes_get_CRC32(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipFileAttributes::set_CRC32(uint32_t Value)
{
	SBCheckError(TElGZipFileAttributes_set_CRC32(_Handle, Value));
}

void TElGZipFileAttributes::get_ExtraField(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGZipFileAttributes_get_ExtraField(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(125067537, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGZipFileAttributes::set_ExtraField(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGZipFileAttributes_set_ExtraField(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGZipFileAttributes::get_Comment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGZipFileAttributes_get_Comment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(334144410, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGZipFileAttributes::set_Comment(const std::string &Value)
{
	SBCheckError(TElGZipFileAttributes_set_Comment(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBGZipFileSystem TElGZipFileAttributes::get_FileSystem()
{
	TSBGZipFileSystemRaw OutResultRaw = 0;
	SBCheckError(TElGZipFileAttributes_get_FileSystem(_Handle, &OutResultRaw));
	return (TSBGZipFileSystem)OutResultRaw;
}

SB_INLINE void TElGZipFileAttributes::set_FileSystem(TSBGZipFileSystem Value)
{
	SBCheckError(TElGZipFileAttributes_set_FileSystem(_Handle, (TSBGZipFileSystemRaw)Value));
}

SB_INLINE uint8_t TElGZipFileAttributes::get_FileSystemCode()
{
	uint8_t OutResult;
	SBCheckError(TElGZipFileAttributes_get_FileSystemCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipFileAttributes::set_FileSystemCode(uint8_t Value)
{
	SBCheckError(TElGZipFileAttributes_set_FileSystemCode(_Handle, Value));
}

bool TElGZipFileAttributes::get_HasText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipFileAttributes_get_HasText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGZipFileAttributes::set_HasText(bool Value)
{
	SBCheckError(TElGZipFileAttributes_set_HasText(_Handle, (int8_t)Value));
}

bool TElGZipFileAttributes::get_HasCRC()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipFileAttributes_get_HasCRC(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGZipFileAttributes::set_HasCRC(bool Value)
{
	SBCheckError(TElGZipFileAttributes_set_HasCRC(_Handle, (int8_t)Value));
}

bool TElGZipFileAttributes::get_HasExtra()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipFileAttributes_get_HasExtra(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGZipFileAttributes::set_HasExtra(bool Value)
{
	SBCheckError(TElGZipFileAttributes_set_HasExtra(_Handle, (int8_t)Value));
}

bool TElGZipFileAttributes::get_HasName()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipFileAttributes_get_HasName(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGZipFileAttributes::set_HasName(bool Value)
{
	SBCheckError(TElGZipFileAttributes_set_HasName(_Handle, (int8_t)Value));
}

bool TElGZipFileAttributes::get_HasComment()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipFileAttributes_get_HasComment(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGZipFileAttributes::set_HasComment(bool Value)
{
	SBCheckError(TElGZipFileAttributes_set_HasComment(_Handle, (int8_t)Value));
}

TElGZipFileAttributes::TElGZipFileAttributes(TElGZipFileAttributesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGZipFileAttributes::TElGZipFileAttributes() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGZipFileAttributes_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGZIPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELGZIPREADER

SB_INLINE void TElGZipReader::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElGZipReader_Open(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGZipReader::Open(TStream &Stream)
{
	SBCheckError(TElGZipReader_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElGZipReader::Open(TStream *Stream)
{
	SBCheckError(TElGZipReader_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElGZipReader::Close()
{
	SBCheckError(TElGZipReader_Close(_Handle));
}

SB_INLINE void TElGZipReader::Extract(const std::string &OutputPath, const std::string &OutputFile)
{
	SBCheckError(TElGZipReader_Extract(_Handle, OutputPath.data(), (int32_t)OutputPath.length(), OutputFile.data(), (int32_t)OutputFile.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGZipReader::Extract(TStream &Stream)
{
	SBCheckError(TElGZipReader_Extract_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElGZipReader::Extract(TStream *Stream)
{
	SBCheckError(TElGZipReader_Extract_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElGZipReader::CheckArchive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipReader_CheckArchive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElGZipReader::get_CompressedSize()
{
	int64_t OutResult;
	SBCheckError(TElGZipReader_get_CompressedSize(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGZIPFILEATTRIBUTES
TElGZipFileAttributes* TElGZipReader::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGZipReader_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElGZipFileAttributes(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELGZIPFILEATTRIBUTES */

bool TElGZipReader::get_IgnoreArchiveErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipReader_get_IgnoreArchiveErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGZipReader::set_IgnoreArchiveErrors(bool Value)
{
	SBCheckError(TElGZipReader_set_IgnoreArchiveErrors(_Handle, (int8_t)Value));
}

void TElGZipReader::get_FilenamesCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGZipReader_get_FilenamesCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1801482892, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGZipReader::set_FilenamesCharset(const std::string &Value)
{
	SBCheckError(TElGZipReader_set_FilenamesCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElGZipReader::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGZipReader_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElGZipReader::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElGZipReader_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElGZipReader::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElGZipReader_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

SB_INLINE void TElGZipReader::get_OnExtractionStreamNeeded(TSBGZipExtractionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGZipReader_get_OnExtractionStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGZipReader::set_OnExtractionStreamNeeded(TSBGZipExtractionStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGZipReader_set_OnExtractionStreamNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElGZipReader::get_OnProgress(TSBGZipProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGZipReader_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGZipReader::set_OnProgress(TSBGZipProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGZipReader_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElGZipReader::get_OnUserActionNeeded(TSBGZipUserActionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGZipReader_get_OnUserActionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGZipReader::set_OnUserActionNeeded(TSBGZipUserActionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGZipReader_set_OnUserActionNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElGZipReader::get_OnArchiveError(TSBGZipArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGZipReader_get_OnArchiveError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGZipReader::set_OnArchiveError(TSBGZipArchiveErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGZipReader_set_OnArchiveError(_Handle, pMethodValue, pDataValue));
}

void TElGZipReader::initInstances()
{
#ifdef SB_USE_CLASS_TELGZIPFILEATTRIBUTES
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELGZIPFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElGZipReader::TElGZipReader(TElGZipReaderHandle handle, TElOwnHandle ownHandle) : TElBaseArchive(handle, ownHandle)
{
	initInstances();
}

TElGZipReader::TElGZipReader(TComponent &AOwner) : TElBaseArchive(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGZipReader_Create(AOwner.getHandle(), &_Handle));
}

TElGZipReader::TElGZipReader(TComponent *AOwner) : TElBaseArchive(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGZipReader_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElGZipReader::~TElGZipReader()
{
#ifdef SB_USE_CLASS_TELGZIPFILEATTRIBUTES
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELGZIPFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELGZIPREADER */

#ifdef SB_USE_CLASS_TELGZIPWRITER

SB_INLINE void TElGZipWriter::CreateArchive()
{
	SBCheckError(TElGZipWriter_CreateArchive(_Handle));
}

SB_INLINE void TElGZipWriter::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElGZipWriter_Open(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGZipWriter::Open(TStream &Stream)
{
	SBCheckError(TElGZipWriter_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElGZipWriter::Open(TStream *Stream)
{
	SBCheckError(TElGZipWriter_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElGZipWriter::Add(const std::string &FileName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipWriter_Add(_Handle, FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElGZipWriter::Add(TStream &Stream, const std::string &FileName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipWriter_Add_1(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGZipWriter::Add(TStream *Stream, const std::string &FileName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipWriter_Add_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElGZipWriter::Compress(TStream &Destination)
{
	SBCheckError(TElGZipWriter_Compress(_Handle, Destination.getHandle()));
}

SB_INLINE void TElGZipWriter::Compress(TStream *Destination)
{
	SBCheckError(TElGZipWriter_Compress(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElGZipWriter::Compress(const std::string &Destination)
{
	SBCheckError(TElGZipWriter_Compress_1(_Handle, Destination.data(), (int32_t)Destination.length()));
}

SB_INLINE void TElGZipWriter::Compress()
{
	SBCheckError(TElGZipWriter_Compress_2(_Handle));
}

SB_INLINE void TElGZipWriter::Close()
{
	SBCheckError(TElGZipWriter_Close(_Handle));
}

bool TElGZipWriter::get_NewArchive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGZipWriter_get_NewArchive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElGZipWriter::get_FileSize()
{
	int64_t OutResult;
	SBCheckError(TElGZipWriter_get_FileSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElGZipWriter::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElGZipWriter_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipWriter::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElGZipWriter_set_CompressionLevel(_Handle, Value));
}

SB_INLINE uint32_t TElGZipWriter::get_WorkFactor()
{
	uint32_t OutResult;
	SBCheckError(TElGZipWriter_get_WorkFactor(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGZipWriter::set_WorkFactor(uint32_t Value)
{
	SBCheckError(TElGZipWriter_set_WorkFactor(_Handle, Value));
}

SB_INLINE void TElGZipWriter::get_OnCompressionStreamNeeded(TSBGZipCompressionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGZipWriter_get_OnCompressionStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGZipWriter::set_OnCompressionStreamNeeded(TSBGZipCompressionStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGZipWriter_set_OnCompressionStreamNeeded(_Handle, pMethodValue, pDataValue));
}

TElGZipWriter::TElGZipWriter(TElGZipWriterHandle handle, TElOwnHandle ownHandle) : TElGZipReader(handle, ownHandle)
{
}

TElGZipWriter::TElGZipWriter(TComponent &AOwner) : TElGZipReader(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGZipWriter_Create(AOwner.getHandle(), &_Handle));
}

TElGZipWriter::TElGZipWriter(TComponent *AOwner) : TElGZipReader(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGZipWriter_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELGZIPWRITER */

};	/* namespace SecureBlackbox */

