#include "sbcomprstream.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCUSTOMCOMPRESSINGSTREAM

SB_INLINE int32_t TElCustomCompressingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomCompressingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCompressingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomCompressingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCompressingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElCustomCompressingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomCompressingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElCustomCompressingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TElCustomCompressingStream::TElCustomCompressingStream(TElCustomCompressingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TElCustomCompressingStream::TElCustomCompressingStream(TStream &SourceStream, int64_t Count, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCompressingStream_Create(SourceStream.getHandle(), Count, (int8_t)ReleaseSourceStream, &_Handle));
}

TElCustomCompressingStream::TElCustomCompressingStream(TStream *SourceStream, int64_t Count, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCompressingStream_Create((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, Count, (int8_t)ReleaseSourceStream, &_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMDECOMPRESSINGSTREAM

SB_INLINE void TElCustomDecompressingStream::FinalizeOutput()
{
	SBCheckError(TElCustomDecompressingStream_FinalizeOutput(_Handle));
}

SB_INLINE int32_t TElCustomDecompressingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomDecompressingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomDecompressingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomDecompressingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomDecompressingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElCustomDecompressingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomDecompressingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElCustomDecompressingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TStream* TElCustomDecompressingStream::get_DestStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomDecompressingStream_get_DestStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DestStream)
		this->_Inst_DestStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_DestStream->updateHandle(hOutResult);
	return this->_Inst_DestStream;
}

void TElCustomDecompressingStream::initInstances()
{
	this->_Inst_DestStream = NULL;
}

TElCustomDecompressingStream::TElCustomDecompressingStream(TElCustomDecompressingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElCustomDecompressingStream::TElCustomDecompressingStream(TStream &DestStream, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomDecompressingStream_Create(DestStream.getHandle(), (int8_t)ReleaseDestStream, &_Handle));
}

TElCustomDecompressingStream::TElCustomDecompressingStream(TStream *DestStream, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomDecompressingStream_Create((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseDestStream, &_Handle));
}

TElCustomDecompressingStream::~TElCustomDecompressingStream()
{
	delete this->_Inst_DestStream;
	this->_Inst_DestStream = NULL;
}
#endif /* SB_USE_CLASS_TELCUSTOMDECOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELZLIBCOMPRESSINGSTREAM

TElZlibCompressingStream::TElZlibCompressingStream(TElZlibCompressingStreamHandle handle, TElOwnHandle ownHandle) : TElCustomCompressingStream(handle, ownHandle)
{
}

TElZlibCompressingStream::TElZlibCompressingStream(int32_t CompressionLevel, TStream &SourceStream, int64_t Count, bool ReleaseSourceStream) : TElCustomCompressingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZlibCompressingStream_Create(CompressionLevel, SourceStream.getHandle(), Count, (int8_t)ReleaseSourceStream, &_Handle));
}

TElZlibCompressingStream::TElZlibCompressingStream(int32_t CompressionLevel, TStream *SourceStream, int64_t Count, bool ReleaseSourceStream) : TElCustomCompressingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZlibCompressingStream_Create(CompressionLevel, (SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, Count, (int8_t)ReleaseSourceStream, &_Handle));
}

#endif /* SB_USE_CLASS_TELZLIBCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELZLIBDECOMPRESSINGSTREAM

TElZlibDecompressingStream::TElZlibDecompressingStream(TElZlibDecompressingStreamHandle handle, TElOwnHandle ownHandle) : TElCustomDecompressingStream(handle, ownHandle)
{
}

TElZlibDecompressingStream::TElZlibDecompressingStream(TStream &DestStream, bool ReleaseDestStream) : TElCustomDecompressingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZlibDecompressingStream_Create(DestStream.getHandle(), (int8_t)ReleaseDestStream, &_Handle));
}

TElZlibDecompressingStream::TElZlibDecompressingStream(TStream *DestStream, bool ReleaseDestStream) : TElCustomDecompressingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZlibDecompressingStream_Create((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseDestStream, &_Handle));
}

#endif /* SB_USE_CLASS_TELZLIBDECOMPRESSINGSTREAM */

};	/* namespace SecureBlackbox */

