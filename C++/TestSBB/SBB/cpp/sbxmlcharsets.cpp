#include "sbxmlcharsets.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLBUFFERINGSTREAM

SB_INLINE int32_t TElXMLBufferingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElXMLBufferingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLBufferingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElXMLBufferingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLBufferingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElXMLBufferingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElXMLBufferingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElXMLBufferingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLBufferingStream::Flush()
{
	SBCheckError(TElXMLBufferingStream_Flush(_Handle));
}

TStream* TElXMLBufferingStream::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLBufferingStream_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElXMLBufferingStream::set_Stream(TStream &Value)
{
	SBCheckError(TElXMLBufferingStream_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLBufferingStream::set_Stream(TStream *Value)
{
	SBCheckError(TElXMLBufferingStream_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

bool TElXMLBufferingStream::get_EndOfFile()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLBufferingStream_get_EndOfFile(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElXMLBufferingStream::initInstances()
{
	this->_Inst_Stream = NULL;
}

TElXMLBufferingStream::TElXMLBufferingStream(TElXMLBufferingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

TElXMLBufferingStream::TElXMLBufferingStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLBufferingStream_Create(&_Handle));
}

TElXMLBufferingStream::~TElXMLBufferingStream()
{
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
}
#endif /* SB_USE_CLASS_TELXMLBUFFERINGSTREAM */

#ifdef SB_USE_CLASS_TELXMLCODEC

SB_INLINE void TElXMLCodec::MigrateTo(TElXMLCodec &Codec)
{
	SBCheckError(TElXMLCodec_MigrateTo(_Handle, Codec.getHandle()));
}

SB_INLINE void TElXMLCodec::MigrateTo(TElXMLCodec *Codec)
{
	SBCheckError(TElXMLCodec_MigrateTo(_Handle, (Codec != NULL) ? Codec->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElXMLCodec::Flush()
{
	SBCheckError(TElXMLCodec_Flush(_Handle));
}

SB_INLINE sb_char16_t TElXMLCodec::NextChar()
{
	sb_char16_t OutResult;
	SBCheckError(TElXMLCodec_NextChar(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLCodec::WriteChar(sb_char16_t c)
{
	SBCheckError(TElXMLCodec_WriteChar(_Handle, c));
}

SB_INLINE void TElXMLCodec::WriteStartup()
{
	SBCheckError(TElXMLCodec_WriteStartup(_Handle));
}

SB_INLINE TElXMLCodecHandle TElXMLCodec::Detect(const std::string &DefaultEncoding)
{
	TElXMLCodecHandle OutResult;
	SBCheckError(TElXMLCodec_Detect(_Handle, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TElXMLCodecHandle TElXMLCodec::Detect(TStream &aStream, const std::string &DefaultEncoding)
{
	TElXMLCodecHandle OutResult;
	SBCheckError(TElXMLCodec_Detect_1(aStream.getHandle(), DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLCodecHandle TElXMLCodec::Detect(TStream *aStream, const std::string &DefaultEncoding)
{
	TElXMLCodecHandle OutResult;
	SBCheckError(TElXMLCodec_Detect_1((aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TElXMLCodecHandle TElXMLCodec::Detect_Inst(TStream &aStream, const std::string &DefaultEncoding)
{
	TElXMLCodecHandle OutResult;
	SBCheckError(TElXMLCodec_Detect_2(_Handle, aStream.getHandle(), DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLCodecHandle TElXMLCodec::Detect_Inst(TStream *aStream, const std::string &DefaultEncoding)
{
	TElXMLCodecHandle OutResult;
	SBCheckError(TElXMLCodec_Detect_2(_Handle, (aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE TElXMLCodecHandle TElXMLCodec::GetCodec(const std::string &aEnc)
{
	TElXMLCodecHandle OutResult;
	SBCheckError(TElXMLCodec_GetCodec(aEnc.data(), (int32_t)aEnc.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLCodecHandle TElXMLCodec::GetCodec_Inst(const std::string &aEnc)
{
	TElXMLCodecHandle OutResult;
	SBCheckError(TElXMLCodec_GetCodec_1(_Handle, aEnc.data(), (int32_t)aEnc.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElXMLCodec::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCodec_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElXMLCodec::set_Stream(TStream &Value)
{
	SBCheckError(TElXMLCodec_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCodec::set_Stream(TStream *Value)
{
	SBCheckError(TElXMLCodec_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElXMLCodec::get_sEOF()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCodec_get_sEOF(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElXMLCodec::get_sPos()
{
	int64_t OutResult;
	SBCheckError(TElXMLCodec_get_sPos(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLCodec::set_sPos(int64_t Value)
{
	SBCheckError(TElXMLCodec_set_sPos(_Handle, Value));
}

SB_INLINE int64_t TElXMLCodec::get_sSize()
{
	int64_t OutResult;
	SBCheckError(TElXMLCodec_get_sSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLCodec::set_sSize(int64_t Value)
{
	SBCheckError(TElXMLCodec_set_sSize(_Handle, Value));
}

void TElXMLCodec::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLCodec_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1027338626, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElXMLCodec::get_WriteBOM()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLCodec_get_WriteBOM(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLCodec::set_WriteBOM(bool Value)
{
	SBCheckError(TElXMLCodec_set_WriteBOM(_Handle, (int8_t)Value));
}

void TElXMLCodec::initInstances()
{
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElXMLCodec::TElXMLCodec(TElXMLCodecHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLCodec::TElXMLCodec() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCodec_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
TElXMLCodec::TElXMLCodec(TStream &aStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCodec_Create_1(aStream.getHandle(), &_Handle));
}

TElXMLCodec::TElXMLCodec(TStream *aStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCodec_Create_1((aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElXMLCodec::~TElXMLCodec()
{
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELXMLCODEC */

#ifdef SB_USE_CLASS_TELXML8BITCODEC

void TElXML8BitCodec::get_Charset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXML8BitCodec_get_Charset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-36465395, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXML8BitCodec::set_Charset(const std::string &Value)
{
	SBCheckError(TElXML8BitCodec_set_Charset(_Handle, Value.data(), (int32_t)Value.length()));
}

TElXML8BitCodec::TElXML8BitCodec(TElXML8BitCodecHandle handle, TElOwnHandle ownHandle) : TElXMLCodec(handle, ownHandle)
{
}

TElXML8BitCodec::TElXML8BitCodec() : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXML8BitCodec_Create(&_Handle));
}

TElXML8BitCodec::TElXML8BitCodec(const std::string &aEncoding) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXML8BitCodec_Create_1(aEncoding.data(), (int32_t)aEncoding.length(), &_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
TElXML8BitCodec::TElXML8BitCodec(TStream &aStream) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXML8BitCodec_Create_2(aStream.getHandle(), &_Handle));
}

TElXML8BitCodec::TElXML8BitCodec(TStream *aStream) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXML8BitCodec_Create_2((aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELXML8BITCODEC */

#ifdef SB_USE_CLASS_TELXMLUTF8CODEC

TElXMLUTF8Codec::TElXMLUTF8Codec(TElXMLUTF8CodecHandle handle, TElOwnHandle ownHandle) : TElXMLCodec(handle, ownHandle)
{
}

TElXMLUTF8Codec::TElXMLUTF8Codec() : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUTF8Codec_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
TElXMLUTF8Codec::TElXMLUTF8Codec(TStream &aStream) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUTF8Codec_Create_1(aStream.getHandle(), &_Handle));
}

TElXMLUTF8Codec::TElXMLUTF8Codec(TStream *aStream) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUTF8Codec_Create_1((aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELXMLUTF8CODEC */

#ifdef SB_USE_CLASS_TELXMLUNICODECODEC

bool TElXMLUnicodeCodec::get_BigEndian()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLUnicodeCodec_get_BigEndian(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLUnicodeCodec::set_BigEndian(bool Value)
{
	SBCheckError(TElXMLUnicodeCodec_set_BigEndian(_Handle, (int8_t)Value));
}

TElXMLUnicodeCodec::TElXMLUnicodeCodec(TElXMLUnicodeCodecHandle handle, TElOwnHandle ownHandle) : TElXMLCodec(handle, ownHandle)
{
}

TElXMLUnicodeCodec::TElXMLUnicodeCodec() : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUnicodeCodec_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
TElXMLUnicodeCodec::TElXMLUnicodeCodec(TStream &aStream) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUnicodeCodec_Create_1(aStream.getHandle(), &_Handle));
}

TElXMLUnicodeCodec::TElXMLUnicodeCodec(TStream *aStream) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLUnicodeCodec_Create_1((aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELXMLUNICODECODEC */

#ifdef SB_USE_CLASS_TELXMLSTRINGCODEC

SB_INLINE sb_char16_t TElXMLStringCodec::NextChar()
{
	sb_char16_t OutResult;
	SBCheckError(TElXMLStringCodec_NextChar(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLStringCodec::WriteChar(sb_char16_t c)
{
	SBCheckError(TElXMLStringCodec_WriteChar(_Handle, c));
}

SB_INLINE void TElXMLStringCodec::WriteStartup()
{
	SBCheckError(TElXMLStringCodec_WriteStartup(_Handle));
}

void TElXMLStringCodec::get_Data(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLStringCodec_get_Data(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1890962346, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLStringCodec::get_Data(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLStringCodec_get_Data(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1890962346, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLStringCodec::set_Data(const sb_u16string &Value)
{
	SBCheckError(TElXMLStringCodec_set_Data(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLStringCodec::set_Data(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLStringCodec_set_Data(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLStringCodec::TElXMLStringCodec(TElXMLStringCodecHandle handle, TElOwnHandle ownHandle) : TElXMLCodec(handle, ownHandle)
{
}

TElXMLStringCodec::TElXMLStringCodec() : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLStringCodec_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
TElXMLStringCodec::TElXMLStringCodec(TStream &aStream) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLStringCodec_Create_1(aStream.getHandle(), &_Handle));
}

TElXMLStringCodec::TElXMLStringCodec(TStream *aStream) : TElXMLCodec(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLStringCodec_Create_1((aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELXMLSTRINGCODEC */

};	/* namespace SecureBlackbox */

