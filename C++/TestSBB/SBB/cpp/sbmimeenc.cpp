#include "sbmimeenc.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELMIMEENCODINGSTREAM

SB_INLINE void TElMimeEncodingStream::ReInit(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen)
{
	SBCheckError(TElMimeEncodingStream_ReInit(_Handle, Stream.getHandle(), StreamLen, SplitOnLen));
}

SB_INLINE void TElMimeEncodingStream::ReInit(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen)
{
	SBCheckError(TElMimeEncodingStream_ReInit(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen));
}

SB_INLINE int64_t TElMimeEncodingStream::_CopyTo(TStream &DestStream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElMimeEncodingStream__CopyTo(_Handle, DestStream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElMimeEncodingStream::_CopyTo(TStream *DestStream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElMimeEncodingStream__CopyTo(_Handle, (DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMimeEncodingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElMimeEncodingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElMimeEncodingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElMimeEncodingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

void TElMimeEncodingStream::GetEncodingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMimeEncodingStream_GetEncodingName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(158317961, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElMimeEncodingStream::GetEncodingName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMimeEncodingStream_GetEncodingName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(158317961, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElMimeEncodingStream::GetEncodedSize(int32_t SourceSize)
{
	int32_t OutResult;
	SBCheckError(TElMimeEncodingStream_GetEncodedSize(_Handle, SourceSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMimeEncodingStream::GetDecodedSize(int32_t SourceSize)
{
	int32_t OutResult;
	SBCheckError(TElMimeEncodingStream_GetDecodedSize(_Handle, SourceSize, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElMimeEncodingStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElMimeEncodingStream_ClassType(&OutResult));
	return OutResult;
}

bool TElMimeEncodingStream::get_IsErrorOccured()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMimeEncodingStream_get_IsErrorOccured(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TStream* TElMimeEncodingStream::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMimeEncodingStream_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElMimeEncodingStream::set_Stream(TStream &Value)
{
	SBCheckError(TElMimeEncodingStream_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElMimeEncodingStream::set_Stream(TStream *Value)
{
	SBCheckError(TElMimeEncodingStream_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElMimeEncodingStream::get_SplitOnLen()
{
	int32_t OutResult;
	SBCheckError(TElMimeEncodingStream_get_SplitOnLen(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMimeEncodingStream::set_SplitOnLen(int32_t Value)
{
	SBCheckError(TElMimeEncodingStream_set_SplitOnLen(_Handle, Value));
}

void TElMimeEncodingStream::initInstances()
{
	this->_Inst_Stream = NULL;
}

TElMimeEncodingStream::TElMimeEncodingStream(TElMimeEncodingStreamHandle handle, TElOwnHandle ownHandle) : TElCustomMIMEStream(handle, ownHandle)
{
	initInstances();
}

TElMimeEncodingStream::TElMimeEncodingStream() : TElCustomMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMimeEncodingStream_Create(&_Handle));
}

TElMimeEncodingStream::TElMimeEncodingStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen) : TElCustomMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMimeEncodingStream_Create_1(Stream.getHandle(), StreamLen, SplitOnLen, &_Handle));
}

TElMimeEncodingStream::TElMimeEncodingStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen) : TElCustomMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMimeEncodingStream_Create_1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen, &_Handle));
}

TElMimeEncodingStream::~TElMimeEncodingStream()
{
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
}
#endif /* SB_USE_CLASS_TELMIMEENCODINGSTREAM */

#ifdef SB_USE_CLASS_TELBASE64STREAM

SB_INLINE void TElBase64Stream::ReInit(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen)
{
	SBCheckError(TElBase64Stream_ReInit(_Handle, Stream.getHandle(), StreamLen, SplitOnLen));
}

SB_INLINE void TElBase64Stream::ReInit(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen)
{
	SBCheckError(TElBase64Stream_ReInit(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen));
}

SB_INLINE int32_t TElBase64Stream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElBase64Stream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBase64Stream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElBase64Stream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE void TElBase64Stream::Flush()
{
	SBCheckError(TElBase64Stream_Flush(_Handle));
}

SB_INLINE int32_t TElBase64Stream::GetEncodedSize(int32_t SourceSize)
{
	int32_t OutResult;
	SBCheckError(TElBase64Stream_GetEncodedSize(_Handle, SourceSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElBase64Stream::GetDecodedSize(int32_t SourceSize)
{
	int32_t OutResult;
	SBCheckError(TElBase64Stream_GetDecodedSize(_Handle, SourceSize, &OutResult));
	return OutResult;
}

void TElBase64Stream::GetEncodingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBase64Stream_GetEncodingName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2089751914, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBase64Stream::GetEncodingName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBase64Stream_GetEncodingName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2089751914, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElBase64Stream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBase64Stream_ClassType(&OutResult));
	return OutResult;
}

TElBase64Stream::TElBase64Stream(TElBase64StreamHandle handle, TElOwnHandle ownHandle) : TElMimeEncodingStream(handle, ownHandle)
{
}

TElBase64Stream::TElBase64Stream() : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBase64Stream_Create(&_Handle));
}

TElBase64Stream::TElBase64Stream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen) : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBase64Stream_Create_1(Stream.getHandle(), StreamLen, SplitOnLen, &_Handle));
}

TElBase64Stream::TElBase64Stream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen) : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBase64Stream_Create_1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen, &_Handle));
}

#endif /* SB_USE_CLASS_TELBASE64STREAM */

#ifdef SB_USE_CLASS_TELQUOTEDPRINTABLESTREAM

SB_INLINE int32_t TElQuotedPrintableStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElQuotedPrintableStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElQuotedPrintableStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElQuotedPrintableStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElQuotedPrintableStream::GetEncodedSize(int32_t SourceSize)
{
	int32_t OutResult;
	SBCheckError(TElQuotedPrintableStream_GetEncodedSize(_Handle, SourceSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElQuotedPrintableStream::GetDecodedSize(int32_t SourceSize)
{
	int32_t OutResult;
	SBCheckError(TElQuotedPrintableStream_GetDecodedSize(_Handle, SourceSize, &OutResult));
	return OutResult;
}

void TElQuotedPrintableStream::GetEncodingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElQuotedPrintableStream_GetEncodingName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-76276848, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElQuotedPrintableStream::GetEncodingName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElQuotedPrintableStream_GetEncodingName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-76276848, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElQuotedPrintableStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElQuotedPrintableStream_ClassType(&OutResult));
	return OutResult;
}

TElQuotedPrintableStream::TElQuotedPrintableStream(TElQuotedPrintableStreamHandle handle, TElOwnHandle ownHandle) : TElMimeEncodingStream(handle, ownHandle)
{
}

TElQuotedPrintableStream::TElQuotedPrintableStream() : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElQuotedPrintableStream_Create(&_Handle));
}

TElQuotedPrintableStream::TElQuotedPrintableStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen) : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElQuotedPrintableStream_Create_1(Stream.getHandle(), StreamLen, SplitOnLen, &_Handle));
}

TElQuotedPrintableStream::TElQuotedPrintableStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen) : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElQuotedPrintableStream_Create_1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen, &_Handle));
}

#endif /* SB_USE_CLASS_TELQUOTEDPRINTABLESTREAM */

#ifdef SB_USE_CLASS_TEL7BITSTREAM

SB_INLINE int32_t TEl7BitStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TEl7BitStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TEl7BitStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TEl7BitStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

void TEl7BitStream::GetEncodingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TEl7BitStream_GetEncodingName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1723789240, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TEl7BitStream::GetEncodingName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TEl7BitStream_GetEncodingName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1723789240, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TEl7BitStream::ReInit(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen)
{
	SBCheckError(TEl7BitStream_ReInit(_Handle, Stream.getHandle(), StreamLen, SplitOnLen));
}

SB_INLINE void TEl7BitStream::ReInit(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen)
{
	SBCheckError(TEl7BitStream_ReInit(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen));
}

SB_INLINE TClassHandle TEl7BitStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TEl7BitStream_ClassType(&OutResult));
	return OutResult;
}

bool TEl7BitStream::get_Passthrough()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TEl7BitStream_get_Passthrough(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TEl7BitStream::set_Passthrough(bool Value)
{
	SBCheckError(TEl7BitStream_set_Passthrough(_Handle, (int8_t)Value));
}

TEl7BitStream::TEl7BitStream(TEl7BitStreamHandle handle, TElOwnHandle ownHandle) : TElMimeEncodingStream(handle, ownHandle)
{
}

TEl7BitStream::TEl7BitStream() : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl7BitStream_Create(&_Handle));
}

TEl7BitStream::TEl7BitStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen) : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl7BitStream_Create_1(Stream.getHandle(), StreamLen, SplitOnLen, &_Handle));
}

TEl7BitStream::TEl7BitStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen) : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl7BitStream_Create_1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen, &_Handle));
}

#endif /* SB_USE_CLASS_TEL7BITSTREAM */

#ifdef SB_USE_CLASS_TEL8BITSTREAM

SB_INLINE int32_t TEl8BitStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TEl8BitStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TEl8BitStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TEl8BitStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

void TEl8BitStream::GetEncodingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TEl8BitStream_GetEncodingName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-947394558, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TEl8BitStream::GetEncodingName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TEl8BitStream_GetEncodingName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-947394558, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TEl8BitStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TEl8BitStream_ClassType(&OutResult));
	return OutResult;
}

TEl8BitStream::TEl8BitStream(TEl8BitStreamHandle handle, TElOwnHandle ownHandle) : TElMimeEncodingStream(handle, ownHandle)
{
}

TEl8BitStream::TEl8BitStream() : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl8BitStream_Create(&_Handle));
}

TEl8BitStream::TEl8BitStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen) : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl8BitStream_Create_1(Stream.getHandle(), StreamLen, SplitOnLen, &_Handle));
}

TEl8BitStream::TEl8BitStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen) : TElMimeEncodingStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TEl8BitStream_Create_1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen, &_Handle));
}

#endif /* SB_USE_CLASS_TEL8BITSTREAM */

#ifdef SB_USE_CLASS_TELBINARYSTREAM

void TElBinaryStream::GetEncodingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBinaryStream_GetEncodingName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1115540887, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBinaryStream::GetEncodingName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBinaryStream_GetEncodingName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1115540887, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElBinaryStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBinaryStream_ClassType(&OutResult));
	return OutResult;
}

TElBinaryStream::TElBinaryStream(TElBinaryStreamHandle handle, TElOwnHandle ownHandle) : TEl8BitStream(handle, ownHandle)
{
}

TElBinaryStream::TElBinaryStream() : TEl8BitStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBinaryStream_Create(&_Handle));
}

TElBinaryStream::TElBinaryStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen) : TEl8BitStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBinaryStream_Create_1(Stream.getHandle(), StreamLen, SplitOnLen, &_Handle));
}

TElBinaryStream::TElBinaryStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen) : TEl8BitStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBinaryStream_Create_1((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamLen, SplitOnLen, &_Handle));
}

#endif /* SB_USE_CLASS_TELBINARYSTREAM */

#ifdef SB_USE_GLOBAL_PROCS_MIMEENC

void DecodeHeader(const std::string &EncodedStr, TElEncodingType Encoding, std::string &OutCodePage, std::string &DecodedStr)
{
	int32_t szOutCodePage = (int32_t)OutCodePage.length();
	int32_t szDecodedStr = (int32_t)DecodedStr.length();
	uint32_t _err = SBMIMEEnc_DecodeHeader(EncodedStr.data(), (int32_t)EncodedStr.length(), (TElEncodingTypeRaw)Encoding, (char *)OutCodePage.data(), &szOutCodePage, (char *)DecodedStr.data(), &szDecodedStr);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutCodePage.resize(szOutCodePage);
		SBCheckError(SBGetLastReturnStringA(-598642571, 2, (char *)OutCodePage.data(), &szOutCodePage));
		DecodedStr.resize(szDecodedStr);
		SBCheckError(SBGetLastReturnStringA(-598642571, 3, (char *)DecodedStr.data(), &szDecodedStr));
	}
	else
		SBCheckError(_err);

	OutCodePage.resize(szOutCodePage);
	DecodedStr.resize(szDecodedStr);
}

void EncodeQuotedPrintableBodyForHeader(const std::string &Source, int32_t &Offset, int32_t Max, std::string &Dest)
{
	int32_t szDest = (int32_t)Dest.length();
	uint32_t _err = SBMIMEEnc_EncodeQuotedPrintableBodyForHeader(Source.data(), (int32_t)Source.length(), &Offset, Max, (char *)Dest.data(), &szDest);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringA(-1510317348, 3, (char *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
}

void ToBase64(uint8_t b1, uint8_t b2, uint8_t b3, std::vector<char> &OutCh)
{
	int32_t szOutCh = (int32_t)OutCh.size();
	uint32_t _err = SBMIMEEnc_ToBase64(b1, b2, b3, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutCh.resize(szOutCh);
		SBCheckError(SBGetLastReturnBuffer(967911441, 3, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh));
	}
	else
		SBCheckError(_err);

	OutCh.resize(szOutCh);
}

void ToBase64(uint8_t b1, uint8_t b2, std::vector<char> &OutCh)
{
	int32_t szOutCh = (int32_t)OutCh.size();
	uint32_t _err = SBMIMEEnc_ToBase64_1(b1, b2, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutCh.resize(szOutCh);
		SBCheckError(SBGetLastReturnBuffer(-2126160910, 2, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh));
	}
	else
		SBCheckError(_err);

	OutCh.resize(szOutCh);
}

void ToBase64(uint8_t b1, std::vector<char> &OutCh)
{
	int32_t szOutCh = (int32_t)OutCh.size();
	uint32_t _err = SBMIMEEnc_ToBase64_2(b1, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutCh.resize(szOutCh);
		SBCheckError(SBGetLastReturnBuffer(1351929500, 1, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh));
	}
	else
		SBCheckError(_err);

	OutCh.resize(szOutCh);
}

void ToBase64(std::vector<char> &InpCh, int32_t InpLen, std::vector<char> &OutCh)
{
	int32_t szInpCh = (int32_t)InpCh.size();
	int32_t szOutCh = (int32_t)OutCh.size();
	uint32_t _err = SBMIMEEnc_ToBase64_3((char *)SB_STD_VECTOR_FRONT_ADR(InpCh), &szInpCh, InpLen, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		InpCh.resize(szInpCh);
		SBCheckError(SBGetLastReturnBuffer(1106295912, 0, (char *)SB_STD_VECTOR_FRONT_ADR(InpCh), &szInpCh));
		OutCh.resize(szOutCh);
		SBCheckError(SBGetLastReturnBuffer(1106295912, 2, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh));
	}
	else
		SBCheckError(_err);

	InpCh.resize(szInpCh);
	OutCh.resize(szOutCh);
}

void ToBase64(std::vector<char> &InpCh, int32_t StartIdx, int32_t InpLen, std::vector<char> &OutCh)
{
	int32_t szInpCh = (int32_t)InpCh.size();
	int32_t szOutCh = (int32_t)OutCh.size();
	uint32_t _err = SBMIMEEnc_ToBase64_4((char *)SB_STD_VECTOR_FRONT_ADR(InpCh), &szInpCh, StartIdx, InpLen, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		InpCh.resize(szInpCh);
		SBCheckError(SBGetLastReturnBuffer(-1211078572, 0, (char *)SB_STD_VECTOR_FRONT_ADR(InpCh), &szInpCh));
		OutCh.resize(szOutCh);
		SBCheckError(SBGetLastReturnBuffer(-1211078572, 3, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh));
	}
	else
		SBCheckError(_err);

	InpCh.resize(szInpCh);
	OutCh.resize(szOutCh);
}

void ToBase64(const std::string &InpStr, int32_t SplitOnLen, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBMIMEEnc_ToBase64_5(InpStr.data(), (int32_t)InpStr.length(), SplitOnLen, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1679811782, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool FromBase64(std::vector<char> &InpCh, int32_t InpLen, std::vector<char> &OutCh, int32_t &OutLen)
{
	int32_t szInpCh = (int32_t)InpCh.size();
	int32_t szOutCh = (int32_t)OutCh.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBMIMEEnc_FromBase64((char *)SB_STD_VECTOR_FRONT_ADR(InpCh), &szInpCh, InpLen, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh, &OutLen, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		InpCh.resize(szInpCh);
		SBCheckError(SBGetLastReturnBuffer(268887859, 0, (char *)SB_STD_VECTOR_FRONT_ADR(InpCh), &szInpCh));
		OutCh.resize(szOutCh);
		SBCheckError(SBGetLastReturnBuffer(268887859, 2, (char *)SB_STD_VECTOR_FRONT_ADR(OutCh), &szOutCh));
	}
	else
		SBCheckError(_err);

	InpCh.resize(szInpCh);
	OutCh.resize(szOutCh);
	return (OutResultRaw != 0);
}

bool FromBase64(const std::string &sBase64, std::string &sOutData)
{
	int32_t szsOutData = (int32_t)sOutData.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBMIMEEnc_FromBase64_1(sBase64.data(), (int32_t)sBase64.length(), (char *)sOutData.data(), &szsOutData, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sOutData.resize(szsOutData);
		SBCheckError(SBGetLastReturnStringA(-1271538635, 1, (char *)sOutData.data(), &szsOutData));
	}
	else
		SBCheckError(_err);

	sOutData.resize(szsOutData);
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_MIMEENC */

};	/* namespace SecureBlackbox */

