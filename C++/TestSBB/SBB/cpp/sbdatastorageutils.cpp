#include "sbdatastorageutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPROXYSTREAM

SB_INLINE int32_t TElProxyStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElProxyStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElProxyStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElProxyStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElProxyStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElProxyStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElProxyStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElProxyStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TStream* TElProxyStream::get_ClientStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElProxyStream_get_ClientStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientStream)
		this->_Inst_ClientStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_ClientStream->updateHandle(hOutResult);
	return this->_Inst_ClientStream;
}

SB_INLINE int64_t TElProxyStream::get_TotalRead()
{
	int64_t OutResult;
	SBCheckError(TElProxyStream_get_TotalRead(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElProxyStream::get_OnBeforeRead(TSBProxyStreamReadWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProxyStream_get_OnBeforeRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProxyStream::set_OnBeforeRead(TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProxyStream_set_OnBeforeRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProxyStream::get_OnAfterRead(TSBProxyStreamReadWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProxyStream_get_OnAfterRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProxyStream::set_OnAfterRead(TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProxyStream_set_OnAfterRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProxyStream::get_OnBeforeWrite(TSBProxyStreamBeforeWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProxyStream_get_OnBeforeWrite(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProxyStream::set_OnBeforeWrite(TSBProxyStreamBeforeWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProxyStream_set_OnBeforeWrite(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProxyStream::get_OnAfterWrite(TSBProxyStreamReadWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProxyStream_get_OnAfterWrite(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProxyStream::set_OnAfterWrite(TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProxyStream_set_OnAfterWrite(_Handle, pMethodValue, pDataValue));
}

void TElProxyStream::initInstances()
{
	this->_Inst_ClientStream = NULL;
}

TElProxyStream::TElProxyStream(TElProxyStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElProxyStream::TElProxyStream(TStream &AClientStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProxyStream_Create(AClientStream.getHandle(), &_Handle));
}

TElProxyStream::TElProxyStream(TStream *AClientStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProxyStream_Create((AClientStream != NULL) ? AClientStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElProxyStream::TElProxyStream(TStream &AClientStream, int64_t StartOffset, int64_t Size, bool TreatSizeAsMaxSize) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProxyStream_Create_1(AClientStream.getHandle(), StartOffset, Size, (int8_t)TreatSizeAsMaxSize, &_Handle));
}

TElProxyStream::TElProxyStream(TStream *AClientStream, int64_t StartOffset, int64_t Size, bool TreatSizeAsMaxSize) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProxyStream_Create_1((AClientStream != NULL) ? AClientStream->getHandle() : SB_NULL_HANDLE, StartOffset, Size, (int8_t)TreatSizeAsMaxSize, &_Handle));
}

TElProxyStream::~TElProxyStream()
{
	delete this->_Inst_ClientStream;
	this->_Inst_ClientStream = NULL;
}
#endif /* SB_USE_CLASS_TELPROXYSTREAM */

#ifdef SB_USE_CLASS_TELMETADATACACHE

SB_INLINE void TElMetadataCache::Clear()
{
	SBCheckError(TElMetadataCache_Clear(_Handle));
}

SB_INLINE void TElMetadataCache::Delete(int32_t Count)
{
	SBCheckError(TElMetadataCache_Delete(_Handle, Count));
}

bool TElMetadataCache::GetMetadata(const std::string &AObjectID, std::vector<uint8_t> &AMetadata)
{
	int32_t szAMetadata = (int32_t)AMetadata.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElMetadataCache_GetMetadata(_Handle, AObjectID.data(), (int32_t)AObjectID.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(AMetadata), &szAMetadata, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		AMetadata.resize(szAMetadata);
		SBCheckError(SBGetLastReturnBuffer(1507669838, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(AMetadata), &szAMetadata));
	}
	else
		SBCheckError(_err);

	AMetadata.resize(szAMetadata);
	return (OutResultRaw != 0);
}

bool TElMetadataCache::GetMetadataID(const std::string &AObjectID, std::string &AMetadataID)
{
	int32_t szAMetadataID = (int32_t)AMetadataID.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElMetadataCache_GetMetadataID(_Handle, AObjectID.data(), (int32_t)AObjectID.length(), (char *)AMetadataID.data(), &szAMetadataID, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		AMetadataID.resize(szAMetadataID);
		SBCheckError(SBGetLastReturnStringA(-951079619, 2, (char *)AMetadataID.data(), &szAMetadataID));
	}
	else
		SBCheckError(_err);

	AMetadataID.resize(szAMetadataID);
	return (OutResultRaw != 0);
}

SB_INLINE void TElMetadataCache::SetMetadata(const std::string &AObjectID, const std::vector<uint8_t> &AMetadata)
{
	SBCheckError(TElMetadataCache_SetMetadata(_Handle, AObjectID.data(), (int32_t)AObjectID.length(), SB_STD_VECTOR_FRONT_ADR(AMetadata), (int32_t)AMetadata.size()));
}

SB_INLINE void TElMetadataCache::SetMetadataID(const std::string &AObjectID, const std::string &AMetadataID)
{
	SBCheckError(TElMetadataCache_SetMetadataID(_Handle, AObjectID.data(), (int32_t)AObjectID.length(), AMetadataID.data(), (int32_t)AMetadataID.length()));
}

SB_INLINE int32_t TElMetadataCache::get_MaxEntries()
{
	int32_t OutResult;
	SBCheckError(TElMetadataCache_get_MaxEntries(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMetadataCache::set_MaxEntries(int32_t Value)
{
	SBCheckError(TElMetadataCache_set_MaxEntries(_Handle, Value));
}

TElMetadataCache::TElMetadataCache(TElMetadataCacheHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElMetadataCache::TElMetadataCache(int32_t AMaxEntries) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMetadataCache_Create(AMaxEntries, &_Handle));
}

#endif /* SB_USE_CLASS_TELMETADATACACHE */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTUPLOADSTREAM

SB_INLINE int32_t TElProtectedObjectUploadStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectUploadStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElProtectedObjectUploadStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectUploadStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElProtectedObjectUploadStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectUploadStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElProtectedObjectUploadStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElProtectedObjectUploadStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TObject* TElProtectedObjectUploadStream::get_Tag()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElProtectedObjectUploadStream_get_Tag(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tag)
		this->_Inst_Tag = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Tag->updateHandle(hOutResult);
	return this->_Inst_Tag;
}

SB_INLINE void TElProtectedObjectUploadStream::set_Tag(TObject &Value)
{
	SBCheckError(TElProtectedObjectUploadStream_set_Tag(_Handle, Value.getHandle()));
}

SB_INLINE void TElProtectedObjectUploadStream::set_Tag(TObject *Value)
{
	SBCheckError(TElProtectedObjectUploadStream_set_Tag(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElProtectedObjectUploadStream::get_OnObjectWriteBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectUploadStream_get_OnObjectWriteBegin(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectUploadStream::set_OnObjectWriteBegin(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectUploadStream_set_OnObjectWriteBegin(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectUploadStream::get_OnObjectWriteEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectUploadStream_get_OnObjectWriteEnd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectUploadStream::set_OnObjectWriteEnd(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectUploadStream_set_OnObjectWriteEnd(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectUploadStream::get_OnObjectWrite(TSBProtectedObjectWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectUploadStream_get_OnObjectWrite(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectUploadStream::set_OnObjectWrite(TSBProtectedObjectWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectUploadStream_set_OnObjectWrite(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectUploadStream::get_OnMetadataNeeded(TSBProtectedObjectMetadataNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectUploadStream_get_OnMetadataNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectUploadStream::set_OnMetadataNeeded(TSBProtectedObjectMetadataNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectUploadStream_set_OnMetadataNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectUploadStream::get_OnTrailerNeeded(TSBProtectedObjectMetadataNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectUploadStream_get_OnTrailerNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectUploadStream::set_OnTrailerNeeded(TSBProtectedObjectMetadataNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectUploadStream_set_OnTrailerNeeded(_Handle, pMethodValue, pDataValue));
}

void TElProtectedObjectUploadStream::initInstances()
{
	this->_Inst_Tag = NULL;
}

TElProtectedObjectUploadStream::TElProtectedObjectUploadStream(TElProtectedObjectUploadStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElProtectedObjectUploadStream::TElProtectedObjectUploadStream(TStream &SourceStream, TSBProtectedObjectMetadataLocation MetadataLocation, int32_t MaxPrefixSize, int64_t MaxObjectSize, int32_t MaxPostfixSize, const std::vector<uint8_t> &Metadata, const std::string &ExternalMetadataObjectName, int64_t Count, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProtectedObjectUploadStream_Create(SourceStream.getHandle(), (TSBProtectedObjectMetadataLocationRaw)MetadataLocation, MaxPrefixSize, MaxObjectSize, MaxPostfixSize, SB_STD_VECTOR_FRONT_ADR(Metadata), (int32_t)Metadata.size(), ExternalMetadataObjectName.data(), (int32_t)ExternalMetadataObjectName.length(), Count, (int8_t)ReleaseSourceStream, &_Handle));
}

TElProtectedObjectUploadStream::TElProtectedObjectUploadStream(TStream *SourceStream, TSBProtectedObjectMetadataLocation MetadataLocation, int32_t MaxPrefixSize, int64_t MaxObjectSize, int32_t MaxPostfixSize, const std::vector<uint8_t> &Metadata, const std::string &ExternalMetadataObjectName, int64_t Count, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProtectedObjectUploadStream_Create((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, (TSBProtectedObjectMetadataLocationRaw)MetadataLocation, MaxPrefixSize, MaxObjectSize, MaxPostfixSize, SB_STD_VECTOR_FRONT_ADR(Metadata), (int32_t)Metadata.size(), ExternalMetadataObjectName.data(), (int32_t)ExternalMetadataObjectName.length(), Count, (int8_t)ReleaseSourceStream, &_Handle));
}

TElProtectedObjectUploadStream::~TElProtectedObjectUploadStream()
{
	delete this->_Inst_Tag;
	this->_Inst_Tag = NULL;
}
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTUPLOADSTREAM */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTREADER

SB_INLINE void TElProtectedObjectReader::ReadObjectInfo(TSBProtectedObjectReadStrategy ReadStrategy)
{
	SBCheckError(TElProtectedObjectReader_ReadObjectInfo(_Handle, (TSBProtectedObjectReadStrategyRaw)ReadStrategy));
}

SB_INLINE int32_t TElProtectedObjectReader::Write(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectReader_Write(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE void TElProtectedObjectReader::FlushCachedData()
{
	SBCheckError(TElProtectedObjectReader_FlushCachedData(_Handle));
}

TSBProtectedObjectMetadataLocation TElProtectedObjectReader::get_MetadataLocation()
{
	TSBProtectedObjectMetadataLocationRaw OutResultRaw = 0;
	SBCheckError(TElProtectedObjectReader_get_MetadataLocation(_Handle, &OutResultRaw));
	return (TSBProtectedObjectMetadataLocation)OutResultRaw;
}

void TElProtectedObjectReader::get_Metadata(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElProtectedObjectReader_get_Metadata(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1089604366, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElProtectedObjectReader::get_Trailer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElProtectedObjectReader_get_Trailer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-542634248, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElProtectedObjectReader::get_MaxMetadataSize()
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectReader_get_MaxMetadataSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElProtectedObjectReader::get_MaxObjectSize()
{
	int64_t OutResult;
	SBCheckError(TElProtectedObjectReader_get_MaxObjectSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElProtectedObjectReader::get_ObjectSize()
{
	int64_t OutResult;
	SBCheckError(TElProtectedObjectReader_get_ObjectSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElProtectedObjectReader::get_MaxTrailerSize()
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectReader_get_MaxTrailerSize(_Handle, &OutResult));
	return OutResult;
}

void TElProtectedObjectReader::get_ExternalMetadataObjectName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElProtectedObjectReader_get_ExternalMetadataObjectName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(305526718, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElProtectedObjectReader::get_MetadataLengthThreshold()
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectReader_get_MetadataLengthThreshold(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElProtectedObjectReader::set_MetadataLengthThreshold(int32_t Value)
{
	SBCheckError(TElProtectedObjectReader_set_MetadataLengthThreshold(_Handle, Value));
}

TObject* TElProtectedObjectReader::get_Tag()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElProtectedObjectReader_get_Tag(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tag)
		this->_Inst_Tag = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Tag->updateHandle(hOutResult);
	return this->_Inst_Tag;
}

SB_INLINE void TElProtectedObjectReader::set_Tag(TObject &Value)
{
	SBCheckError(TElProtectedObjectReader_set_Tag(_Handle, Value.getHandle()));
}

SB_INLINE void TElProtectedObjectReader::set_Tag(TObject *Value)
{
	SBCheckError(TElProtectedObjectReader_set_Tag(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElProtectedObjectReader::get_DestStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElProtectedObjectReader_get_DestStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DestStream)
		this->_Inst_DestStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_DestStream->updateHandle(hOutResult);
	return this->_Inst_DestStream;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElProtectedObjectReader::get_ObjectInfoBlockSize()
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectReader_get_ObjectInfoBlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElProtectedObjectReader::set_ObjectInfoBlockSize(int32_t Value)
{
	SBCheckError(TElProtectedObjectReader_set_ObjectInfoBlockSize(_Handle, Value));
}

SB_INLINE void TElProtectedObjectReader::get_OnReadBlock(TSBProtectedObjectBlockReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnReadBlock(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnReadBlock(TSBProtectedObjectBlockReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnReadBlock(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnReadStream(TSBProtectedObjectStreamReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnReadStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnReadStream(TSBProtectedObjectStreamReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnReadStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnHeaderProcessed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnHeaderProcessed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnHeaderProcessed(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnHeaderProcessed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnMetadataReceived(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnMetadataReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnMetadataReceived(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnMetadataReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnMetadataObjectNameReceived(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnMetadataObjectNameReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnMetadataObjectNameReceived(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnMetadataObjectNameReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnTrailerReceived(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnTrailerReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnTrailerReceived(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnTrailerReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnObjectBodyBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnObjectBodyBegin(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnObjectBodyBegin(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnObjectBodyBegin(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnObjectBodyEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnObjectBodyEnd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnObjectBodyEnd(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnObjectBodyEnd(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnObjectBodyBlock(TSBProtectedObjectBodyBlockEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnObjectBodyBlock(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnObjectBodyBlock(TSBProtectedObjectBodyBlockEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnObjectBodyBlock(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectReader::get_OnOutputStreamNeeded(TSBProtectedObjectOutputStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectReader_get_OnOutputStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectReader::set_OnOutputStreamNeeded(TSBProtectedObjectOutputStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectReader_set_OnOutputStreamNeeded(_Handle, pMethodValue, pDataValue));
}

void TElProtectedObjectReader::initInstances()
{
	this->_Inst_Tag = NULL;
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_DestStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElProtectedObjectReader::TElProtectedObjectReader(TElProtectedObjectReaderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElProtectedObjectReader::TElProtectedObjectReader() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProtectedObjectReader_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
TElProtectedObjectReader::TElProtectedObjectReader(TStream &DestStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProtectedObjectReader_Create_1(DestStream.getHandle(), &_Handle));
}

TElProtectedObjectReader::TElProtectedObjectReader(TStream *DestStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProtectedObjectReader_Create_1((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElProtectedObjectReader::~TElProtectedObjectReader()
{
	delete this->_Inst_Tag;
	this->_Inst_Tag = NULL;
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_DestStream;
	this->_Inst_DestStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTREADER */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTDOWNLOADSTREAM

SB_INLINE void TElProtectedObjectDownloadStream::FlushCachedData()
{
	SBCheckError(TElProtectedObjectDownloadStream_FlushCachedData(_Handle));
}

SB_INLINE int32_t TElProtectedObjectDownloadStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectDownloadStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElProtectedObjectDownloadStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectDownloadStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElProtectedObjectDownloadStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElProtectedObjectDownloadStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElProtectedObjectDownloadStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElProtectedObjectDownloadStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TStream* TElProtectedObjectDownloadStream::get_DestStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElProtectedObjectDownloadStream_get_DestStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DestStream)
		this->_Inst_DestStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_DestStream->updateHandle(hOutResult);
	return this->_Inst_DestStream;
}

TObject* TElProtectedObjectDownloadStream::get_Tag()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElProtectedObjectDownloadStream_get_Tag(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tag)
		this->_Inst_Tag = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Tag->updateHandle(hOutResult);
	return this->_Inst_Tag;
}

SB_INLINE void TElProtectedObjectDownloadStream::set_Tag(TObject &Value)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_Tag(_Handle, Value.getHandle()));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_Tag(TObject *Value)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_Tag(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTREADER
TElProtectedObjectReader* TElProtectedObjectDownloadStream::get_Reader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElProtectedObjectDownloadStream_get_Reader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Reader)
		this->_Inst_Reader = new TElProtectedObjectReader(hOutResult, ohFalse);
	else
		this->_Inst_Reader->updateHandle(hOutResult);
	return this->_Inst_Reader;
}
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTREADER */

SB_INLINE void TElProtectedObjectDownloadStream::get_OnHeaderProcessed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectDownloadStream_get_OnHeaderProcessed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_OnHeaderProcessed(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_OnHeaderProcessed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectDownloadStream::get_OnObjectReadBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectDownloadStream_get_OnObjectReadBegin(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_OnObjectReadBegin(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_OnObjectReadBegin(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectDownloadStream::get_OnObjectReadEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectDownloadStream_get_OnObjectReadEnd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_OnObjectReadEnd(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_OnObjectReadEnd(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectDownloadStream::get_OnObjectRead(TSBProtectedObjectReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectDownloadStream_get_OnObjectRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_OnObjectRead(TSBProtectedObjectReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_OnObjectRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectDownloadStream::get_OnMetadataReceived(TSBProtectedObjectMetadataReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectDownloadStream_get_OnMetadataReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_OnMetadataReceived(TSBProtectedObjectMetadataReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_OnMetadataReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectDownloadStream::get_OnMetadataObjectNameReceived(TSBProtectedObjectMetadataObjectNameReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectDownloadStream_get_OnMetadataObjectNameReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_OnMetadataObjectNameReceived(TSBProtectedObjectMetadataObjectNameReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_OnMetadataObjectNameReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectDownloadStream::get_OnTrailerReceived(TSBProtectedObjectMetadataReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectDownloadStream_get_OnTrailerReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_OnTrailerReceived(TSBProtectedObjectMetadataReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_OnTrailerReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElProtectedObjectDownloadStream::get_OnOutputStreamNeeded(TSBProtectedObjectOutputStreamNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElProtectedObjectDownloadStream_get_OnOutputStreamNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElProtectedObjectDownloadStream::set_OnOutputStreamNeeded(TSBProtectedObjectOutputStreamNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElProtectedObjectDownloadStream_set_OnOutputStreamNeeded(_Handle, pMethodValue, pDataValue));
}

void TElProtectedObjectDownloadStream::initInstances()
{
	this->_Inst_DestStream = NULL;
	this->_Inst_Tag = NULL;
#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTREADER
	this->_Inst_Reader = NULL;
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTREADER */
}

TElProtectedObjectDownloadStream::TElProtectedObjectDownloadStream(TElProtectedObjectDownloadStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElProtectedObjectDownloadStream::TElProtectedObjectDownloadStream(TStream &DestStream, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProtectedObjectDownloadStream_Create(DestStream.getHandle(), (int8_t)ReleaseDestStream, &_Handle));
}

TElProtectedObjectDownloadStream::TElProtectedObjectDownloadStream(TStream *DestStream, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElProtectedObjectDownloadStream_Create((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseDestStream, &_Handle));
}

TElProtectedObjectDownloadStream::~TElProtectedObjectDownloadStream()
{
	delete this->_Inst_DestStream;
	this->_Inst_DestStream = NULL;
	delete this->_Inst_Tag;
	this->_Inst_Tag = NULL;
#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTREADER
	delete this->_Inst_Reader;
	this->_Inst_Reader = NULL;
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTREADER */
}
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTDOWNLOADSTREAM */

#ifdef SB_USE_GLOBAL_PROCS_DATASTORAGEUTILS

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t TryGetStreamSize(TStream &Stream)
{
	int64_t OutResult;
	SBCheckError(SBDataStorageUtils_TryGetStreamSize(Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int64_t TryGetStreamSize(TStream *Stream)
{
	int64_t OutResult;
	SBCheckError(SBDataStorageUtils_TryGetStreamSize((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

void PathAddExtension(const std::string &PathName, const std::string &Extension, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBDataStorageUtils_PathAddExtension(PathName.data(), (int32_t)PathName.length(), Extension.data(), (int32_t)Extension.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1368763655, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_DATASTORAGEUTILS */

};	/* namespace SecureBlackbox */

