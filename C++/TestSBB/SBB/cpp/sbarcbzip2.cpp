#include "sbarcbzip2.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBZIP2DECOMPRESSINGUNIT

SB_INLINE void TElBZip2DecompressingUnit::InitializeProcessing()
{
	SBCheckError(TElBZip2DecompressingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElBZip2DecompressingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElBZip2DecompressingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElBZip2DecompressingUnit::FinalizeProcessing()
{
	SBCheckError(TElBZip2DecompressingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElBZip2DecompressingUnit::get_Verbosity()
{
	uint32_t OutResult;
	SBCheckError(TElBZip2DecompressingUnit_get_Verbosity(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBZip2DecompressingUnit::set_Verbosity(uint32_t Value)
{
	SBCheckError(TElBZip2DecompressingUnit_set_Verbosity(_Handle, Value));
}

bool TElBZip2DecompressingUnit::get_Small()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBZip2DecompressingUnit_get_Small(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBZip2DecompressingUnit::set_Small(bool Value)
{
	SBCheckError(TElBZip2DecompressingUnit_set_Small(_Handle, (int8_t)Value));
}

TElBZip2DecompressingUnit::TElBZip2DecompressingUnit(TElBZip2DecompressingUnitHandle handle, TElOwnHandle ownHandle) : TElArcProcessingUnit(handle, ownHandle)
{
}

TElBZip2DecompressingUnit::TElBZip2DecompressingUnit() : TElArcProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBZip2DecompressingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBZIP2DECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELBZIP2COMPRESSINGUNIT

SB_INLINE void TElBZip2CompressingUnit::InitializeProcessing()
{
	SBCheckError(TElBZip2CompressingUnit_InitializeProcessing(_Handle));
}

SB_INLINE void TElBZip2CompressingUnit::ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElBZip2CompressingUnit_ProcessBlock(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

SB_INLINE void TElBZip2CompressingUnit::FinalizeProcessing()
{
	SBCheckError(TElBZip2CompressingUnit_FinalizeProcessing(_Handle));
}

SB_INLINE uint32_t TElBZip2CompressingUnit::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElBZip2CompressingUnit_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBZip2CompressingUnit::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElBZip2CompressingUnit_set_CompressionLevel(_Handle, Value));
}

SB_INLINE uint32_t TElBZip2CompressingUnit::get_Verbosity()
{
	uint32_t OutResult;
	SBCheckError(TElBZip2CompressingUnit_get_Verbosity(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBZip2CompressingUnit::set_Verbosity(uint32_t Value)
{
	SBCheckError(TElBZip2CompressingUnit_set_Verbosity(_Handle, Value));
}

SB_INLINE uint32_t TElBZip2CompressingUnit::get_WorkFactor()
{
	uint32_t OutResult;
	SBCheckError(TElBZip2CompressingUnit_get_WorkFactor(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBZip2CompressingUnit::set_WorkFactor(uint32_t Value)
{
	SBCheckError(TElBZip2CompressingUnit_set_WorkFactor(_Handle, Value));
}

TElBZip2CompressingUnit::TElBZip2CompressingUnit(TElBZip2CompressingUnitHandle handle, TElOwnHandle ownHandle) : TElArcProcessingUnit(handle, ownHandle)
{
}

TElBZip2CompressingUnit::TElBZip2CompressingUnit() : TElArcProcessingUnit(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBZip2CompressingUnit_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBZIP2COMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELBZIP2READER

SB_INLINE void TElBZip2Reader::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElBZip2Reader_Open(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBZip2Reader::Open(TStream &Stream)
{
	SBCheckError(TElBZip2Reader_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElBZip2Reader::Open(TStream *Stream)
{
	SBCheckError(TElBZip2Reader_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElBZip2Reader::Close()
{
	SBCheckError(TElBZip2Reader_Close(_Handle));
}

SB_INLINE void TElBZip2Reader::Extract(const std::string &OutputFile)
{
	SBCheckError(TElBZip2Reader_Extract(_Handle, OutputFile.data(), (int32_t)OutputFile.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBZip2Reader::Extract(TStream &Stream)
{
	SBCheckError(TElBZip2Reader_Extract_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElBZip2Reader::Extract(TStream *Stream)
{
	SBCheckError(TElBZip2Reader_Extract_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int64_t TElBZip2Reader::get_CompressedSize()
{
	int64_t OutResult;
	SBCheckError(TElBZip2Reader_get_CompressedSize(_Handle, &OutResult));
	return OutResult;
}

bool TElBZip2Reader::get_Small()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBZip2Reader_get_Small(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBZip2Reader::set_Small(bool Value)
{
	SBCheckError(TElBZip2Reader_set_Small(_Handle, (int8_t)Value));
}

bool TElBZip2Reader::get_IgnoreArchiveErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBZip2Reader_get_IgnoreArchiveErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBZip2Reader::set_IgnoreArchiveErrors(bool Value)
{
	SBCheckError(TElBZip2Reader_set_IgnoreArchiveErrors(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElBZip2Reader::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBZip2Reader_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElBZip2Reader::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElBZip2Reader_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElBZip2Reader::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElBZip2Reader_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

SB_INLINE void TElBZip2Reader::get_OnExtractionStreamNeeded(TSBBZip2ExtractionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElBZip2Reader_get_OnExtractionStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElBZip2Reader::set_OnExtractionStreamNeeded(TSBBZip2ExtractionStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElBZip2Reader_set_OnExtractionStreamNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElBZip2Reader::get_OnProgress(TSBBzip2ProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElBZip2Reader_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElBZip2Reader::set_OnProgress(TSBBzip2ProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElBZip2Reader_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElBZip2Reader::get_OnUserActionNeeded(TSBBzip2UserActionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElBZip2Reader_get_OnUserActionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElBZip2Reader::set_OnUserActionNeeded(TSBBzip2UserActionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElBZip2Reader_set_OnUserActionNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElBZip2Reader::get_OnArchiveError(TSBBZip2ArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElBZip2Reader_get_OnArchiveError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElBZip2Reader::set_OnArchiveError(TSBBZip2ArchiveErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElBZip2Reader_set_OnArchiveError(_Handle, pMethodValue, pDataValue));
}

void TElBZip2Reader::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElBZip2Reader::TElBZip2Reader(TElBZip2ReaderHandle handle, TElOwnHandle ownHandle) : TElBaseArchive(handle, ownHandle)
{
	initInstances();
}

TElBZip2Reader::TElBZip2Reader(TComponent &AOwner) : TElBaseArchive(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBZip2Reader_Create(AOwner.getHandle(), &_Handle));
}

TElBZip2Reader::TElBZip2Reader(TComponent *AOwner) : TElBaseArchive(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBZip2Reader_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElBZip2Reader::~TElBZip2Reader()
{
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELBZIP2READER */

#ifdef SB_USE_CLASS_TELBZIP2WRITER

SB_INLINE void TElBZip2Writer::CreateArchive()
{
	SBCheckError(TElBZip2Writer_CreateArchive(_Handle));
}

SB_INLINE void TElBZip2Writer::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElBZip2Writer_Open(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBZip2Writer::Open(TStream &Stream)
{
	SBCheckError(TElBZip2Writer_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElBZip2Writer::Open(TStream *Stream)
{
	SBCheckError(TElBZip2Writer_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElBZip2Writer::Add(const std::string &FileName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBZip2Writer_Add(_Handle, FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElBZip2Writer::Add(TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBZip2Writer_Add_1(_Handle, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBZip2Writer::Add(TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBZip2Writer_Add_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElBZip2Writer::Compress(TStream &Destination)
{
	SBCheckError(TElBZip2Writer_Compress(_Handle, Destination.getHandle()));
}

SB_INLINE void TElBZip2Writer::Compress(TStream *Destination)
{
	SBCheckError(TElBZip2Writer_Compress(_Handle, (Destination != NULL) ? Destination->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElBZip2Writer::Compress(const std::string &Destination)
{
	SBCheckError(TElBZip2Writer_Compress_1(_Handle, Destination.data(), (int32_t)Destination.length()));
}

SB_INLINE void TElBZip2Writer::Compress()
{
	SBCheckError(TElBZip2Writer_Compress_2(_Handle));
}

SB_INLINE void TElBZip2Writer::Close()
{
	SBCheckError(TElBZip2Writer_Close(_Handle));
}

bool TElBZip2Writer::get_NewArchive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBZip2Writer_get_NewArchive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElBZip2Writer::get_FileSize()
{
	int64_t OutResult;
	SBCheckError(TElBZip2Writer_get_FileSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElBZip2Writer::get_CompressionLevel()
{
	uint32_t OutResult;
	SBCheckError(TElBZip2Writer_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBZip2Writer::set_CompressionLevel(uint32_t Value)
{
	SBCheckError(TElBZip2Writer_set_CompressionLevel(_Handle, Value));
}

SB_INLINE uint32_t TElBZip2Writer::get_WorkFactor()
{
	uint32_t OutResult;
	SBCheckError(TElBZip2Writer_get_WorkFactor(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBZip2Writer::set_WorkFactor(uint32_t Value)
{
	SBCheckError(TElBZip2Writer_set_WorkFactor(_Handle, Value));
}

SB_INLINE void TElBZip2Writer::get_OnCompressionStreamNeeded(TSBBZip2CompressionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElBZip2Writer_get_OnCompressionStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElBZip2Writer::set_OnCompressionStreamNeeded(TSBBZip2CompressionStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElBZip2Writer_set_OnCompressionStreamNeeded(_Handle, pMethodValue, pDataValue));
}

TElBZip2Writer::TElBZip2Writer(TElBZip2WriterHandle handle, TElOwnHandle ownHandle) : TElBZip2Reader(handle, ownHandle)
{
}

TElBZip2Writer::TElBZip2Writer(TComponent &AOwner) : TElBZip2Reader(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBZip2Writer_Create(AOwner.getHandle(), &_Handle));
}

TElBZip2Writer::TElBZip2Writer(TComponent *AOwner) : TElBZip2Reader(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBZip2Writer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELBZIP2WRITER */

};	/* namespace SecureBlackbox */

