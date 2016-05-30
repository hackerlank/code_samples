#include "sbmimestream.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCUSTOMMIMESTREAM

SB_INLINE void TElCustomMIMEStream::Flush()
{
	SBCheckError(TElCustomMIMEStream_Flush(_Handle));
}

SB_INLINE int64_t TElCustomMIMEStream::CopyFrom(TStream &SrcStream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMIMEStream_CopyFrom(_Handle, SrcStream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomMIMEStream::CopyFrom(TStream *SrcStream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMIMEStream_CopyFrom(_Handle, (SrcStream != NULL) ? SrcStream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomMIMEStream::_CopyTo(TStream &DestStream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMIMEStream__CopyTo(_Handle, DestStream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomMIMEStream::_CopyTo(TStream *DestStream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMIMEStream__CopyTo(_Handle, (DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomMIMEStream::Squeeze()
{
	SBCheckError(TElCustomMIMEStream_Squeeze(_Handle));
}

SB_INLINE void TElCustomMIMEStream::Reserve(int32_t Count)
{
	SBCheckError(TElCustomMIMEStream_Reserve(_Handle, Count));
}

SB_INLINE int64_t TElCustomMIMEStream::get_Capacity()
{
	int64_t OutResult;
	SBCheckError(TElCustomMIMEStream_get_Capacity(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomMIMEStream::set_Capacity(int64_t Value)
{
	SBCheckError(TElCustomMIMEStream_set_Capacity(_Handle, Value));
}

TElCustomMIMEStream::TElCustomMIMEStream(TElCustomMIMEStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TElCustomMIMEStream::TElCustomMIMEStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomMIMEStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMMIMESTREAM */

#ifdef SB_USE_CLASS_TNULLMIMESTREAM

SB_INLINE int32_t TNullMIMEStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TNullMIMEStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TNullMIMEStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TNullMIMEStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TNullMIMEStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TNullMIMEStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TNullMIMEStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TNullMIMEStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TNullMIMEStream::TNullMIMEStream(TNullMIMEStreamHandle handle, TElOwnHandle ownHandle) : TElCustomMIMEStream(handle, ownHandle)
{
}

TNullMIMEStream::TNullMIMEStream() : TElCustomMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TNullMIMEStream_Create(&_Handle));
}

TNullMIMEStream::TNullMIMEStream(int64_t ASize) : TElCustomMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TNullMIMEStream_Create_1(ASize, &_Handle));
}

#endif /* SB_USE_CLASS_TNULLMIMESTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMMEMORYMIMESTREAM

SB_INLINE void TElCustomMemoryMIMEStream::SetMemory(const std::vector<uint8_t> &Value, int64_t ASize)
{
	SBCheckError(TElCustomMemoryMIMEStream_SetMemory(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), ASize));
}

SB_INLINE int64_t TElCustomMemoryMIMEStream::SaveToStream(TStream &Stream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_SaveToStream(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomMemoryMIMEStream::SaveToStream(TStream *Stream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomMemoryMIMEStream::SaveToFileEx(const sb_u16string &FileName, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_SaveToFileEx(_Handle, FileName.data(), (int32_t)FileName.length(), Count, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int64_t TElCustomMemoryMIMEStream::SaveToFileEx(const std::wstring &FileName, int64_t Count)
{
	int64_t OutResult;
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	SBCheckError(TElCustomMemoryMIMEStream_SaveToFileEx(_Handle, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, Count, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElCustomMemoryMIMEStream::SaveToFile(const sb_u16string &FileName)
{
	SBCheckError(TElCustomMemoryMIMEStream_SaveToFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElCustomMemoryMIMEStream::SaveToFile(const std::wstring &FileName)
{
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	SBCheckError(TElCustomMemoryMIMEStream_SaveToFile(_Handle, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE int64_t TElCustomMemoryMIMEStream::LoadFromStream(TStream &Stream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_LoadFromStream(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomMemoryMIMEStream::LoadFromStream(TStream *Stream, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomMemoryMIMEStream::LoadFromFileEx(const sb_u16string &FileName, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_LoadFromFileEx(_Handle, FileName.data(), (int32_t)FileName.length(), Count, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int64_t TElCustomMemoryMIMEStream::LoadFromFileEx(const std::wstring &FileName, int64_t Count)
{
	int64_t OutResult;
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	SBCheckError(TElCustomMemoryMIMEStream_LoadFromFileEx(_Handle, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, Count, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElCustomMemoryMIMEStream::LoadFromFile(const sb_u16string &FileName)
{
	SBCheckError(TElCustomMemoryMIMEStream_LoadFromFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElCustomMemoryMIMEStream::LoadFromFile(const std::wstring &FileName)
{
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	SBCheckError(TElCustomMemoryMIMEStream_LoadFromFile(_Handle, reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElCustomMemoryMIMEStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomMemoryMIMEStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomMemoryMIMEStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCustomMemoryMIMEStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomMemoryMIMEStream::Clear(int64_t NewCapacity)
{
	SBCheckError(TElCustomMemoryMIMEStream_Clear(_Handle, NewCapacity));
}

SB_INLINE void TElCustomMemoryMIMEStream::Squeeze()
{
	SBCheckError(TElCustomMemoryMIMEStream_Squeeze(_Handle));
}

SB_INLINE void TElCustomMemoryMIMEStream::Reserve(int32_t Count)
{
	SBCheckError(TElCustomMemoryMIMEStream_Reserve(_Handle, Count));
}

SB_INLINE int64_t TElCustomMemoryMIMEStream::SizePos()
{
	int64_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_SizePos(_Handle, &OutResult));
	return OutResult;
}

void TElCustomMemoryMIMEStream::get_Memory(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomMemoryMIMEStream_get_Memory(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-747273016, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomMemoryMIMEStream::set_Memory(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomMemoryMIMEStream_set_Memory(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElCustomMemoryMIMEStream::get_MemoryDelta()
{
	int32_t OutResult;
	SBCheckError(TElCustomMemoryMIMEStream_get_MemoryDelta(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomMemoryMIMEStream::set_MemoryDelta(int32_t Value)
{
	SBCheckError(TElCustomMemoryMIMEStream_set_MemoryDelta(_Handle, Value));
}

TElCustomMemoryMIMEStream::TElCustomMemoryMIMEStream(TElCustomMemoryMIMEStreamHandle handle, TElOwnHandle ownHandle) : TElCustomMIMEStream(handle, ownHandle)
{
}

TElCustomMemoryMIMEStream::TElCustomMemoryMIMEStream() : TElCustomMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomMemoryMIMEStream_Create(&_Handle));
}

TElCustomMemoryMIMEStream::TElCustomMemoryMIMEStream(int64_t ACapacity) : TElCustomMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomMemoryMIMEStream_Create_1(ACapacity, &_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMMEMORYMIMESTREAM */

#ifdef SB_USE_CLASS_TELMEMORYMIMESTREAM

void TElMemoryMIMEStream::get_Memory(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMemoryMIMEStream_get_Memory(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2036445676, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMemoryMIMEStream::set_Memory(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElMemoryMIMEStream_set_Memory(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint8_t TElMemoryMIMEStream::get_Bytes(int64_t Index)
{
	uint8_t OutResult;
	SBCheckError(TElMemoryMIMEStream_get_Bytes(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElMemoryMIMEStream::set_Bytes(int64_t Index, uint8_t Value)
{
	SBCheckError(TElMemoryMIMEStream_set_Bytes(_Handle, Index, Value));
}

SB_INLINE uint16_t TElMemoryMIMEStream::get_Words(int64_t Index)
{
	uint16_t OutResult;
	SBCheckError(TElMemoryMIMEStream_get_Words(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElMemoryMIMEStream::set_Words(int64_t Index, uint16_t Value)
{
	SBCheckError(TElMemoryMIMEStream_set_Words(_Handle, Index, Value));
}

TElMemoryMIMEStream::TElMemoryMIMEStream(TElMemoryMIMEStreamHandle handle, TElOwnHandle ownHandle) : TElCustomMemoryMIMEStream(handle, ownHandle)
{
}

TElMemoryMIMEStream::TElMemoryMIMEStream() : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMemoryMIMEStream_Create(&_Handle));
}

TElMemoryMIMEStream::TElMemoryMIMEStream(int64_t ACapacity) : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMemoryMIMEStream_Create_1(ACapacity, &_Handle));
}

#endif /* SB_USE_CLASS_TELMEMORYMIMESTREAM */

#ifdef SB_USE_CLASS_TANSISTRINGMIMESTREAM

SB_INLINE TAnsiStringMIMEStreamHandle TAnsiStringMIMEStream::GetAnsiStringMIMEStream()
{
	TAnsiStringMIMEStreamHandle OutResult;
	SBCheckError(TAnsiStringMIMEStream_GetAnsiStringMIMEStream(&OutResult));
	return OutResult;
}

SB_INLINE TAnsiStringMIMEStreamHandle TAnsiStringMIMEStream::GetAnsiStringMIMEStream_Inst()
{
	TAnsiStringMIMEStreamHandle OutResult;
	SBCheckError(TAnsiStringMIMEStream_GetAnsiStringMIMEStream_1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TAnsiStringMIMEStream::WriteChar(char ch)
{
	SBCheckError(TAnsiStringMIMEStream_WriteChar(_Handle, ch));
}

SB_INLINE int64_t TAnsiStringMIMEStream::WriteString(const std::string &S)
{
	int64_t OutResult;
	SBCheckError(TAnsiStringMIMEStream_WriteString(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TAnsiStringMIMEStream::get_AnsiLength()
{
	int64_t OutResult;
	SBCheckError(TAnsiStringMIMEStream_get_AnsiLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TAnsiStringMIMEStream::set_AnsiLength(int64_t Value)
{
	SBCheckError(TAnsiStringMIMEStream_set_AnsiLength(_Handle, Value));
}

void TAnsiStringMIMEStream::get_AnsiData(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TAnsiStringMIMEStream_get_AnsiData(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1252582510, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TAnsiStringMIMEStream::set_AnsiData(const std::string &Value)
{
	SBCheckError(TAnsiStringMIMEStream_set_AnsiData(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint8_t TAnsiStringMIMEStream::get_Bytes(int64_t Index)
{
	uint8_t OutResult;
	SBCheckError(TAnsiStringMIMEStream_get_Bytes(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TAnsiStringMIMEStream::set_Bytes(int64_t Index, uint8_t Value)
{
	SBCheckError(TAnsiStringMIMEStream_set_Bytes(_Handle, Index, Value));
}

SB_INLINE char TAnsiStringMIMEStream::get_Chars(int64_t Index)
{
	char OutResult;
	SBCheckError(TAnsiStringMIMEStream_get_Chars(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TAnsiStringMIMEStream::set_Chars(int64_t Index, char Value)
{
	SBCheckError(TAnsiStringMIMEStream_set_Chars(_Handle, Index, Value));
}

TAnsiStringMIMEStream::TAnsiStringMIMEStream(TAnsiStringMIMEStreamHandle handle, TElOwnHandle ownHandle) : TElCustomMemoryMIMEStream(handle, ownHandle)
{
}

TAnsiStringMIMEStream::TAnsiStringMIMEStream() : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TAnsiStringMIMEStream_Create(&_Handle));
}

TAnsiStringMIMEStream::TAnsiStringMIMEStream(const std::string &sValue) : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TAnsiStringMIMEStream_Create_1(sValue.data(), (int32_t)sValue.length(), &_Handle));
}

TAnsiStringMIMEStream::TAnsiStringMIMEStream(int64_t ACapacity) : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TAnsiStringMIMEStream_Create_2(ACapacity, &_Handle));
}

#endif /* SB_USE_CLASS_TANSISTRINGMIMESTREAM */

#ifdef SB_USE_CLASS_TWIDESTRINGMIMESTREAM

SB_INLINE void TWideStringMIMEStream::WriteWChar(sb_char16_t ch)
{
	SBCheckError(TWideStringMIMEStream_WriteWChar(_Handle, ch));
}

SB_INLINE int64_t TWideStringMIMEStream::WriteWString(const sb_u16string &S)
{
	int64_t OutResult;
	SBCheckError(TWideStringMIMEStream_WriteWString(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int64_t TWideStringMIMEStream::WriteWString(const std::wstring &S)
{
	int64_t OutResult;
	std::string u16S;
	sb_to_u16string(S, u16S);
	SBCheckError(TWideStringMIMEStream_WriteWString(_Handle, reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TWideStringMIMEStream::get_CurrentWord()
{
	int32_t OutResult;
	SBCheckError(TWideStringMIMEStream_get_CurrentWord(_Handle, &OutResult));
	return OutResult;
}

void TWideStringMIMEStream::get_WideData(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TWideStringMIMEStream_get_WideData(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-917883751, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TWideStringMIMEStream::get_WideData(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TWideStringMIMEStream_get_WideData(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-917883751, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TWideStringMIMEStream::set_WideData(const sb_u16string &Value)
{
	SBCheckError(TWideStringMIMEStream_set_WideData(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TWideStringMIMEStream::set_WideData(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TWideStringMIMEStream_set_WideData(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TWideStringMIMEStream::get_WideLength()
{
	int64_t OutResult;
	SBCheckError(TWideStringMIMEStream_get_WideLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TWideStringMIMEStream::set_WideLength(int64_t Value)
{
	SBCheckError(TWideStringMIMEStream_set_WideLength(_Handle, Value));
}

SB_INLINE uint16_t TWideStringMIMEStream::get_Words(int64_t Index)
{
	uint16_t OutResult;
	SBCheckError(TWideStringMIMEStream_get_Words(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TWideStringMIMEStream::set_Words(int64_t Index, uint16_t Value)
{
	SBCheckError(TWideStringMIMEStream_set_Words(_Handle, Index, Value));
}

SB_INLINE sb_char16_t TWideStringMIMEStream::get_WChars(int64_t Index)
{
	sb_char16_t OutResult;
	SBCheckError(TWideStringMIMEStream_get_WChars(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TWideStringMIMEStream::set_WChars(int64_t Index, sb_char16_t Value)
{
	SBCheckError(TWideStringMIMEStream_set_WChars(_Handle, Index, Value));
}

TWideStringMIMEStream::TWideStringMIMEStream(TWideStringMIMEStreamHandle handle, TElOwnHandle ownHandle) : TElCustomMemoryMIMEStream(handle, ownHandle)
{
}

TWideStringMIMEStream::TWideStringMIMEStream() : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TWideStringMIMEStream_Create(&_Handle));
}

TWideStringMIMEStream::TWideStringMIMEStream(const sb_u16string &wsValue) : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TWideStringMIMEStream_Create_1(wsValue.data(), (int32_t)wsValue.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TWideStringMIMEStream::TWideStringMIMEStream(const std::wstring &wsValue) : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16wsValue;
	sb_to_u16string(wsValue, u16wsValue);
	SBCheckError(TWideStringMIMEStream_Create_1(reinterpret_cast<const sb_char16_t*>(u16wsValue.data()), (int32_t)u16wsValue.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TWideStringMIMEStream::TWideStringMIMEStream(int64_t ACapacity) : TElCustomMemoryMIMEStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TWideStringMIMEStream_Create_2(ACapacity, &_Handle));
}

#endif /* SB_USE_CLASS_TWIDESTRINGMIMESTREAM */

#ifdef SB_USE_GLOBAL_PROCS_MIMESTREAM

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t WriteStringToStream(const std::vector<uint8_t> &S, TStream &Stream, int64_t LPos, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_WriteStringToStream(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), Stream.getHandle(), LPos, Count, &OutResult));
	return OutResult;
}
SB_INLINE int64_t WriteStringToStream(const std::vector<uint8_t> &S, TStream *Stream, int64_t LPos, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_WriteStringToStream(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, LPos, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t WriteStringToStream(const std::string &S, TStream &Stream, int64_t LPos, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_WriteStringToStream_1(S.data(), (int32_t)S.length(), Stream.getHandle(), LPos, Count, &OutResult));
	return OutResult;
}
SB_INLINE int64_t WriteStringToStream(const std::string &S, TStream *Stream, int64_t LPos, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_WriteStringToStream_1(S.data(), (int32_t)S.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, LPos, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t WriteWideStringToStream(const sb_u16string &S, TStream &Stream)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_WriteWideStringToStream(S.data(), (int32_t)S.length(), Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int64_t WriteWideStringToStream(const sb_u16string &S, TStream *Stream)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_WriteWideStringToStream(S.data(), (int32_t)S.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int64_t WriteWideStringToStream(const std::wstring &S, TStream &Stream)
{
	int64_t OutResult;
	std::string u16S;
	sb_to_u16string(S, u16S);
	SBCheckError(SBMIMEStream_WriteWideStringToStream(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int64_t WriteWideStringToStream(const std::wstring &S, TStream *Stream)
{
	int64_t OutResult;
	std::string u16S;
	sb_to_u16string(S, u16S);
	SBCheckError(SBMIMEStream_WriteWideStringToStream(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t WriteStreamToStream(TStream &Source, TStream &Dest, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_WriteStreamToStream(Source.getHandle(), Dest.getHandle(), Count, &OutResult));
	return OutResult;
}
SB_INLINE int64_t WriteStreamToStream(TStream *Source, TStream *Dest, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_WriteStreamToStream((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool ReadLineFromStream(TStream &Source, TStream &smDest, int32_t &iLineLength, int32_t MaxLineLength, bool bReadLongLine, bool bSeekLongToEOL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIMEStream_ReadLineFromStream(Source.getHandle(), smDest.getHandle(), &iLineLength, MaxLineLength, (int8_t)bReadLongLine, (int8_t)bSeekLongToEOL, &OutResultRaw));
	return (OutResultRaw != 0);
}
bool ReadLineFromStream(TStream *Source, TStream *smDest, int32_t &iLineLength, int32_t MaxLineLength, bool bReadLongLine, bool bSeekLongToEOL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMIMEStream_ReadLineFromStream((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (smDest != NULL) ? smDest->getHandle() : SB_NULL_HANDLE, &iLineLength, MaxLineLength, (int8_t)bReadLongLine, (int8_t)bSeekLongToEOL, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool ReadLineFromStream(TStream &Source, std::string &sDest, int32_t MaxLineLength, bool bReadLongLine, bool bSeekLongToEOL)
{
	int32_t szsDest = (int32_t)sDest.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBMIMEStream_ReadLineFromStream_1(Source.getHandle(), (char *)sDest.data(), &szsDest, MaxLineLength, (int8_t)bReadLongLine, (int8_t)bSeekLongToEOL, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sDest.resize(szsDest);
		SBCheckError(SBGetLastReturnStringA(-1199552189, 1, (char *)sDest.data(), &szsDest));
	}
	else
		SBCheckError(_err);

	sDest.resize(szsDest);
	return (OutResultRaw != 0);
}
bool ReadLineFromStream(TStream *Source, std::string &sDest, int32_t MaxLineLength, bool bReadLongLine, bool bSeekLongToEOL)
{
	int32_t szsDest = (int32_t)sDest.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBMIMEStream_ReadLineFromStream_1((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (char *)sDest.data(), &szsDest, MaxLineLength, (int8_t)bReadLongLine, (int8_t)bSeekLongToEOL, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		sDest.resize(szsDest);
		SBCheckError(SBGetLastReturnStringA(-1199552189, 1, (char *)sDest.data(), &szsDest));
	}
	else
		SBCheckError(_err);

	sDest.resize(szsDest);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t SeekStreamToEnd(TStream &Stream)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_SeekStreamToEnd(Stream.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int64_t SeekStreamToEnd(TStream *Stream)
{
	int64_t OutResult;
	SBCheckError(SBMIMEStream_SeekStreamToEnd((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_MIMESTREAM */

};	/* namespace SecureBlackbox */

