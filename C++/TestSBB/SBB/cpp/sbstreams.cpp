#include "sbstreams.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELFILESTREAM

SB_INLINE int64_t TElFileStream::get_Position64()
{
	int64_t OutResult;
	SBCheckError(TElFileStream_get_Position64(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFileStream::set_Position64(int64_t Value)
{
	SBCheckError(TElFileStream_set_Position64(_Handle, Value));
}

SB_INLINE int64_t TElFileStream::get_Size64()
{
	int64_t OutResult;
	SBCheckError(TElFileStream_get_Size64(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFileStream::set_Size64(int64_t Value)
{
	SBCheckError(TElFileStream_set_Size64(_Handle, Value));
}

TElFileStream::TElFileStream(TElFileStreamHandle handle, TElOwnHandle ownHandle) : TFileStream(handle, ownHandle)
{
}

TElFileStream::TElFileStream(const std::string &AFileName, uint16_t Mode) : TFileStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileStream_Create(AFileName.data(), (int32_t)AFileName.length(), Mode, &_Handle));
}

TElFileStream::TElFileStream(const std::string &AFileName, uint16_t Mode, uint32_t Rights) : TFileStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileStream_Create_1(AFileName.data(), (int32_t)AFileName.length(), Mode, Rights, &_Handle));
}

#endif /* SB_USE_CLASS_TELFILESTREAM */

#ifdef SB_USE_CLASS_TELDATASTREAM

SB_INLINE int64_t TElDataStream::get_Start()
{
	int64_t OutResult;
	SBCheckError(TElDataStream_get_Start(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElDataStream::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDataStream_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElDataStream::set_Stream(TStream &Value)
{
	SBCheckError(TElDataStream_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElDataStream::set_Stream(TStream *Value)
{
	SBCheckError(TElDataStream_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElDataStream::get_FreeOnSent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDataStream_get_FreeOnSent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDataStream::set_FreeOnSent(bool Value)
{
	SBCheckError(TElDataStream_set_FreeOnSent(_Handle, (int8_t)Value));
}

void TElDataStream::initInstances()
{
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElDataStream::TElDataStream(TElDataStreamHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TSTREAM
TElDataStream::TElDataStream(TStream &LStream, bool LFreeOnSent) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDataStream_Create(LStream.getHandle(), (int8_t)LFreeOnSent, &_Handle));
}

TElDataStream::TElDataStream(TStream *LStream, bool LFreeOnSent) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDataStream_Create((LStream != NULL) ? LStream->getHandle() : SB_NULL_HANDLE, (int8_t)LFreeOnSent, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElDataStream::TElDataStream(const std::vector<uint8_t> &Buffer) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDataStream_Create_1(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &_Handle));
}

TElDataStream::~TElDataStream()
{
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELDATASTREAM */

#ifdef SB_USE_CLASS_TELMULTISTREAM

bool TElMultiStream::AddStream(TStream &AStream, bool FreeStream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiStream_AddStream(_Handle, AStream.getHandle(), (int8_t)FreeStream, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMultiStream::AddStream(TStream *AStream, bool FreeStream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMultiStream_AddStream(_Handle, (AStream != NULL) ? AStream->getHandle() : SB_NULL_HANDLE, (int8_t)FreeStream, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElMultiStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElMultiStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMultiStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElMultiStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMultiStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElMultiStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElMultiStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElMultiStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TElMultiStream::TElMultiStream(TElMultiStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TElMultiStream::TElMultiStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultiStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELMULTISTREAM */

#ifdef SB_USE_CLASS_TELREADCACHINGSTREAM

SB_INLINE int32_t TElReadCachingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElReadCachingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElReadCachingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElReadCachingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElReadCachingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElReadCachingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElReadCachingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElReadCachingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TStream* TElReadCachingStream::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElReadCachingStream_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElReadCachingStream::set_Stream(TStream &Value)
{
	SBCheckError(TElReadCachingStream_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElReadCachingStream::set_Stream(TStream *Value)
{
	SBCheckError(TElReadCachingStream_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElReadCachingStream::get_CacheSize()
{
	int32_t OutResult;
	SBCheckError(TElReadCachingStream_get_CacheSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElReadCachingStream::set_CacheSize(int32_t Value)
{
	SBCheckError(TElReadCachingStream_set_CacheSize(_Handle, Value));
}

void TElReadCachingStream::initInstances()
{
	this->_Inst_Stream = NULL;
}

TElReadCachingStream::TElReadCachingStream(TElReadCachingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElReadCachingStream::TElReadCachingStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElReadCachingStream_Create(&_Handle));
}

TElReadCachingStream::~TElReadCachingStream()
{
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
}
#endif /* SB_USE_CLASS_TELREADCACHINGSTREAM */

#ifdef SB_USE_CLASS_TELWRITECACHINGSTREAM

SB_INLINE int32_t TElWriteCachingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElWriteCachingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElWriteCachingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElWriteCachingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElWriteCachingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElWriteCachingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElWriteCachingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElWriteCachingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE void TElWriteCachingStream::Flush()
{
	SBCheckError(TElWriteCachingStream_Flush(_Handle));
}

TStream* TElWriteCachingStream::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElWriteCachingStream_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElWriteCachingStream::set_Stream(TStream &Value)
{
	SBCheckError(TElWriteCachingStream_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElWriteCachingStream::set_Stream(TStream *Value)
{
	SBCheckError(TElWriteCachingStream_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElWriteCachingStream::get_CacheSize()
{
	int32_t OutResult;
	SBCheckError(TElWriteCachingStream_get_CacheSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElWriteCachingStream::set_CacheSize(int32_t Value)
{
	SBCheckError(TElWriteCachingStream_set_CacheSize(_Handle, Value));
}

void TElWriteCachingStream::initInstances()
{
	this->_Inst_Stream = NULL;
}

TElWriteCachingStream::TElWriteCachingStream(TElWriteCachingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElWriteCachingStream::TElWriteCachingStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElWriteCachingStream_Create(&_Handle));
}

TElWriteCachingStream::~TElWriteCachingStream()
{
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
}
#endif /* SB_USE_CLASS_TELWRITECACHINGSTREAM */

#ifdef SB_USE_GLOBAL_PROCS_STREAMS

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t CopyStream(TStream &SrcStream, TStream &DestStream, int64_t Offset, int64_t Count, bool PreservePosition)
{
	int64_t OutResult;
	SBCheckError(SBStreams_CopyStream(SrcStream.getHandle(), DestStream.getHandle(), Offset, Count, (int8_t)PreservePosition, &OutResult));
	return OutResult;
}
SB_INLINE int64_t CopyStream(TStream *SrcStream, TStream *DestStream, int64_t Offset, int64_t Count, bool PreservePosition)
{
	int64_t OutResult;
	SBCheckError(SBStreams_CopyStream((SrcStream != NULL) ? SrcStream->getHandle() : SB_NULL_HANDLE, (DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, Offset, Count, (int8_t)PreservePosition, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t CopyStream(TStream &Source, TStream &Dest, int64_t Offset, int64_t Count, bool PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent)
{
	int64_t OutResult;
	SBCheckError(SBStreams_CopyStream_1(Source.getHandle(), Dest.getHandle(), Offset, Count, (int8_t)PreservePosition, pMethodProgressEvent, pDataProgressEvent, &OutResult));
	return OutResult;
}
SB_INLINE int64_t CopyStream(TStream *Source, TStream *Dest, int64_t Offset, int64_t Count, bool PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent)
{
	int64_t OutResult;
	SBCheckError(SBStreams_CopyStream_1((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, Offset, Count, (int8_t)PreservePosition, pMethodProgressEvent, pDataProgressEvent, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t StreamPosition(TStream &Stream)
{
	int64_t OutResult;
	SBCheckError(SBStreams_StreamPosition(Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int64_t StreamPosition(TStream *Stream)
{
	int64_t OutResult;
	SBCheckError(SBStreams_StreamPosition((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t StreamSize(TStream &Stream)
{
	int64_t OutResult;
	SBCheckError(SBStreams_StreamSize(Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int64_t StreamSize(TStream *Stream)
{
	int64_t OutResult;
	SBCheckError(SBStreams_StreamSize((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void SetStreamPosition(TStream &Stream, int64_t Position)
{
	SBCheckError(SBStreams_SetStreamPosition(Stream.getHandle(), Position));
}
SB_INLINE void SetStreamPosition(TStream *Stream, int64_t Position)
{
	SBCheckError(SBStreams_SetStreamPosition((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Position));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void StreamSetPosition(TStream &Stream, int64_t NewPosition)
{
	SBCheckError(SBStreams_StreamSetPosition(Stream.getHandle(), NewPosition));
}
SB_INLINE void StreamSetPosition(TStream *Stream, int64_t NewPosition)
{
	SBCheckError(SBStreams_StreamSetPosition((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, NewPosition));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void StreamRewind(TStream &Stream)
{
	SBCheckError(SBStreams_StreamRewind(Stream.getHandle()));
}
SB_INLINE void StreamRewind(TStream *Stream)
{
	SBCheckError(SBStreams_StreamRewind((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamRead(TStream &Stream, std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBStreams_StreamRead(Stream.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Offset, Count);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-59055763, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}
void StreamRead(TStream *Stream, std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBStreams_StreamRead((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Offset, Count);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-59055763, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamReadAll(TStream &Stream, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStreams_StreamReadAll(Stream.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1321483271, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void StreamReadAll(TStream *Stream, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStreams_StreamReadAll((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1321483271, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE uint8_t StreamReadByte(TStream &Stream)
{
	uint8_t OutResult;
	SBCheckError(SBStreams_StreamReadByte(Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE uint8_t StreamReadByte(TStream *Stream)
{
	uint8_t OutResult;
	SBCheckError(SBStreams_StreamReadByte((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void StreamWrite(TStream &Stream, const std::vector<uint8_t> &Buffer)
{
	SBCheckError(SBStreams_StreamWrite(Stream.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}
SB_INLINE void StreamWrite(TStream *Stream, const std::vector<uint8_t> &Buffer)
{
	SBCheckError(SBStreams_StreamWrite((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void StreamWrite(TStream &Stream, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	SBCheckError(SBStreams_StreamWrite_1(Stream.getHandle(), SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count));
}
SB_INLINE void StreamWrite(TStream *Stream, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	SBCheckError(SBStreams_StreamWrite_1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void StreamWriteLn(TStream &Stream, const std::string &Text)
{
	SBCheckError(SBStreams_StreamWriteLn(Stream.getHandle(), Text.data(), (int32_t)Text.length()));
}
SB_INLINE void StreamWriteLn(TStream *Stream, const std::string &Text)
{
	SBCheckError(SBStreams_StreamWriteLn((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Text.data(), (int32_t)Text.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void StreamClear(TStream &Stream)
{
	SBCheckError(SBStreams_StreamClear(Stream.getHandle()));
}
SB_INLINE void StreamClear(TStream *Stream)
{
	SBCheckError(SBStreams_StreamClear((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_STREAMS */

};	/* namespace SecureBlackbox */

