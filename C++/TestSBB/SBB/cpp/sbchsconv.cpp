#include "sbchsconv.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCONVERTER

void TPlConverter::Convert(const std::string &Source, std::string &Dest, TPlConvertOptions Options)
{
	int32_t szDest = (int32_t)Dest.length();
	uint32_t _err = TPlConverter_Convert(_Handle, Source.data(), (int32_t)Source.length(), (char *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringA(1001996868, 2, (char *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TPlConverter::Convert(TStream &Source, TStream &Dest, TPlConvertOptions Options, int32_t MaxChars)
{
	SBCheckError(TPlConverter_Convert_1(_Handle, Source.getHandle(), Dest.getHandle(), (TPlConvertOptionsRaw)Options, MaxChars));
}

SB_INLINE void TPlConverter::Convert(TStream *Source, TStream *Dest, TPlConvertOptions Options, int32_t MaxChars)
{
	SBCheckError(TPlConverter_Convert_1(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, (TPlConvertOptionsRaw)Options, MaxChars));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TPlConverter::IsConvert(const std::string &Source, std::string &Dest, TPlConvertOptions Options)
{
	int32_t szDest = (int32_t)Dest.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TPlConverter_IsConvert(_Handle, Source.data(), (int32_t)Source.length(), (char *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringA(2055207206, 2, (char *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TPlConverter::IsConvert(TStream &Source, TStream &Dest, TPlConvertOptions Options, int32_t MaxChars)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlConverter_IsConvert_1(_Handle, Source.getHandle(), Dest.getHandle(), (TPlConvertOptionsRaw)Options, MaxChars, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TPlConverter::IsConvert(TStream *Source, TStream *Dest, TPlConvertOptions Options, int32_t MaxChars)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlConverter_IsConvert_1(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, (TPlConvertOptionsRaw)Options, MaxChars, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

void TPlConverter::ConvertFromUnicode(const sb_u16string &Source, std::string &Dest, TPlConvertOptions Options)
{
	int32_t szDest = (int32_t)Dest.length();
	uint32_t _err = TPlConverter_ConvertFromUnicode(_Handle, Source.data(), (int32_t)Source.length(), (char *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringA(-546920311, 2, (char *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
}
#ifdef SB_U16STRING_USED
void TPlConverter::ConvertFromUnicode(const std::wstring &Source, std::string &Dest, TPlConvertOptions Options)
{
	std::string u16Source;
	sb_to_u16string(Source, u16Source);
	int32_t szDest = (int32_t)Dest.length();
	uint32_t _err = TPlConverter_ConvertFromUnicode(_Handle, reinterpret_cast<const sb_char16_t*>(u16Source.data()), (int32_t)u16Source.length() >> 1, (char *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringA(-546920311, 2, (char *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
}
#endif /* SB_U16STRING_USED */

void TPlConverter::ConvertToUnicode(const std::string &Source, sb_u16string &Dest, TPlConvertOptions Options)
{
	int32_t szDest = (int32_t)Dest.length();
	uint32_t _err = TPlConverter_ConvertToUnicode(_Handle, Source.data(), (int32_t)Source.length(), (sb_char16_t *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringW(1817422112, 2, (sb_char16_t *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
}
#ifdef SB_U16STRING_USED
void TPlConverter::ConvertToUnicode(const std::string &Source, std::wstring &Dest, TPlConvertOptions Options)
{
	std::string u16Dest;
	int32_t szDest = 0;
	uint32_t _err = TPlConverter_ConvertToUnicode(_Handle, Source.data(), (int32_t)Source.length(), NULL, &szDest, (TPlConvertOptionsRaw)Options);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Dest.resize(szDest << 1);
		SBCheckError(SBGetLastReturnStringW(1817422112, 2, reinterpret_cast<sb_char16_t*>((char*)u16Dest.data()), &szDest));
	}
	else
		SBCheckError(_err);

	u16Dest.resize(szDest << 1);
	sb_u16_to_wstring(u16Dest, Dest);
}
#endif /* SB_U16STRING_USED */

bool TPlConverter::IsConvertFromUnicode(const sb_u16string &Source, std::string &Dest, TPlConvertOptions Options)
{
	int32_t szDest = (int32_t)Dest.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TPlConverter_IsConvertFromUnicode(_Handle, Source.data(), (int32_t)Source.length(), (char *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringA(880438118, 2, (char *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TPlConverter::IsConvertFromUnicode(const std::wstring &Source, std::string &Dest, TPlConvertOptions Options)
{
	std::string u16Source;
	sb_to_u16string(Source, u16Source);
	int32_t szDest = (int32_t)Dest.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TPlConverter_IsConvertFromUnicode(_Handle, reinterpret_cast<const sb_char16_t*>(u16Source.data()), (int32_t)u16Source.length() >> 1, (char *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringA(880438118, 2, (char *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TPlConverter::IsConvertToUnicode(const std::string &Source, sb_u16string &Dest, TPlConvertOptions Options)
{
	int32_t szDest = (int32_t)Dest.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TPlConverter_IsConvertToUnicode(_Handle, Source.data(), (int32_t)Source.length(), (sb_char16_t *)Dest.data(), &szDest, (TPlConvertOptionsRaw)Options, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnStringW(101573092, 2, (sb_char16_t *)Dest.data(), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TPlConverter::IsConvertToUnicode(const std::string &Source, std::wstring &Dest, TPlConvertOptions Options)
{
	std::string u16Dest;
	int32_t szDest = 0;
	int8_t OutResultRaw = 0;
	uint32_t _err = TPlConverter_IsConvertToUnicode(_Handle, Source.data(), (int32_t)Source.length(), NULL, &szDest, (TPlConvertOptionsRaw)Options, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Dest.resize(szDest << 1);
		SBCheckError(SBGetLastReturnStringW(101573092, 2, reinterpret_cast<sb_char16_t*>((char*)u16Dest.data()), &szDest));
	}
	else
		SBCheckError(_err);

	u16Dest.resize(szDest << 1);
	sb_u16_to_wstring(u16Dest, Dest);
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_IPLCHARSET
SB_INLINE IPlCharsetHandle TPlConverter::get_DstCharset()
{
	IPlCharsetHandle OutResult;
	SBCheckError(TPlConverter_get_DstCharset(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_IPLCHARSET */

void TPlConverter::get_DstCharsetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlConverter_get_DstCharsetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1992048386, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TPlConverter::set_DstCharsetName(const std::string &Value)
{
	SBCheckError(TPlConverter_set_DstCharsetName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_IPLCHARSET
SB_INLINE IPlCharsetHandle TPlConverter::get_SrcCharset()
{
	IPlCharsetHandle OutResult;
	SBCheckError(TPlConverter_get_SrcCharset(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_IPLCHARSET */

void TPlConverter::get_SrcCharsetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlConverter_get_SrcCharsetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(791317412, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TPlConverter::set_SrcCharsetName(const std::string &Value)
{
	SBCheckError(TPlConverter_set_SrcCharsetName(_Handle, Value.data(), (int32_t)Value.length()));
}

TPlConverter::TPlConverter(TPlConverterHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TPlConverter::TPlConverter() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlConverter_Create(&_Handle));
}

TPlConverter::TPlConverter(const std::string &SrcCharset, const std::string &DstCharset) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlConverter_Create_1(SrcCharset.data(), (int32_t)SrcCharset.length(), DstCharset.data(), (int32_t)DstCharset.length(), &_Handle));
}

#ifdef SB_USE_CLASS_IPLCHARSET
TPlConverter::TPlConverter(IPlCharsetHandle SrcCharset, IPlCharsetHandle DstCharset) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlConverter_Create_2(SrcCharset, DstCharset, &_Handle));
}
#endif /* SB_USE_CLASS_IPLCHARSET */

#endif /* SB_USE_CLASS_TPLCONVERTER */

#ifdef SB_USE_CLASS_TPLCUSTOMUTF

void TPlCustomUTF::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCustomUTF_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1631645591, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCustomUTF::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCustomUTF_ClassType(&OutResult));
	return OutResult;
}

TPlCustomUTF::TPlCustomUTF(TPlCustomUTFHandle handle, TElOwnHandle ownHandle) : TPlCharset(handle, ownHandle)
{
}

TPlCustomUTF::TPlCustomUTF() : TPlCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCustomUTF_Create(&_Handle));
}

TPlCustomUTF TPlCustomUTF::CreateShift(int32_t Shift)
{
	TPlCustomUTFHandle _Handle;
	SBCheckError(TPlCustomUTF_CreateShift(Shift, &_Handle));
	return TPlCustomUTF(_Handle, SB_OWN_HANDLE);
}

TPlCustomUTF TPlCustomUTF::CreateNoInit()
{
	TPlCustomUTFHandle _Handle;
	SBCheckError(TPlCustomUTF_CreateNoInit(&_Handle));
	return TPlCustomUTF(_Handle, SB_OWN_HANDLE);
}

TPlCustomUTF TPlCustomUTF::CreateForFinalize()
{
	TPlCustomUTFHandle _Handle;
	SBCheckError(TPlCustomUTF_CreateForFinalize(&_Handle));
	return TPlCustomUTF(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCUSTOMUTF */

#ifdef SB_USE_CLASS_TPLUTF32

SB_INLINE int32_t TPlUTF32::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF32_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlUTF32::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF32_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlUTF32::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF32_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlUTF32::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF32_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

void TPlUTF32::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF32_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(449190065, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlUTF32::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlUTF32_ClassType(&OutResult));
	return OutResult;
}

TPlUTF32::TPlUTF32(TPlUTF32Handle handle, TElOwnHandle ownHandle) : TPlCustomUTF(handle, ownHandle)
{
}

TPlUTF32::TPlUTF32() : TPlCustomUTF(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlUTF32_Create(&_Handle));
}

TPlUTF32 TPlUTF32::CreateShift(int32_t Shift)
{
	TPlUTF32Handle _Handle;
	SBCheckError(TPlUTF32_CreateShift(Shift, &_Handle));
	return TPlUTF32(_Handle, SB_OWN_HANDLE);
}

TPlUTF32 TPlUTF32::CreateNoInit()
{
	TPlUTF32Handle _Handle;
	SBCheckError(TPlUTF32_CreateNoInit(&_Handle));
	return TPlUTF32(_Handle, SB_OWN_HANDLE);
}

TPlUTF32 TPlUTF32::CreateForFinalize()
{
	TPlUTF32Handle _Handle;
	SBCheckError(TPlUTF32_CreateForFinalize(&_Handle));
	return TPlUTF32(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLUTF32 */

#ifdef SB_USE_CLASS_TPLUTF32BE

void TPlUTF32BE::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF32BE_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1158159909, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlUTF32BE::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlUTF32BE_ClassType(&OutResult));
	return OutResult;
}

TPlUTF32BE::TPlUTF32BE(TPlUTF32BEHandle handle, TElOwnHandle ownHandle) : TPlUTF32(handle, ownHandle)
{
}

TPlUTF32BE::TPlUTF32BE() : TPlUTF32(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlUTF32BE_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLUTF32BE */

#ifdef SB_USE_CLASS_TPLUTF16

SB_INLINE int32_t TPlUTF16::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF16_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlUTF16::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF16_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlUTF16::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF16_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlUTF16::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF16_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

void TPlUTF16::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF16_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1688344979, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlUTF16::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlUTF16_ClassType(&OutResult));
	return OutResult;
}

TPlUTF16::TPlUTF16(TPlUTF16Handle handle, TElOwnHandle ownHandle) : TPlCustomUTF(handle, ownHandle)
{
}

TPlUTF16::TPlUTF16() : TPlCustomUTF(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlUTF16_Create(&_Handle));
}

TPlUTF16 TPlUTF16::CreateShift(int32_t Shift)
{
	TPlUTF16Handle _Handle;
	SBCheckError(TPlUTF16_CreateShift(Shift, &_Handle));
	return TPlUTF16(_Handle, SB_OWN_HANDLE);
}

TPlUTF16 TPlUTF16::CreateNoInit()
{
	TPlUTF16Handle _Handle;
	SBCheckError(TPlUTF16_CreateNoInit(&_Handle));
	return TPlUTF16(_Handle, SB_OWN_HANDLE);
}

TPlUTF16 TPlUTF16::CreateForFinalize()
{
	TPlUTF16Handle _Handle;
	SBCheckError(TPlUTF16_CreateForFinalize(&_Handle));
	return TPlUTF16(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLUTF16 */

#ifdef SB_USE_CLASS_TPLUTF16BE

void TPlUTF16BE::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF16BE_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-805127283, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlUTF16BE::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlUTF16BE_ClassType(&OutResult));
	return OutResult;
}

TPlUTF16BE::TPlUTF16BE(TPlUTF16BEHandle handle, TElOwnHandle ownHandle) : TPlUTF16(handle, ownHandle)
{
}

TPlUTF16BE::TPlUTF16BE() : TPlUTF16(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlUTF16BE_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLUTF16BE */

#ifdef SB_USE_CLASS_TPLUTF8

SB_INLINE int32_t TPlUTF8::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF8_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlUTF8::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF8_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlUTF8::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF8_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlUTF8::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlUTF8_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

void TPlUTF8::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF8_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1603300002, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlUTF8::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF8_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1481134695, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlUTF8::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlUTF8_ClassType(&OutResult));
	return OutResult;
}

TPlUTF8::TPlUTF8(TPlUTF8Handle handle, TElOwnHandle ownHandle) : TPlCharset(handle, ownHandle)
{
}

TPlUTF8::TPlUTF8() : TPlCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlUTF8_Create(&_Handle));
}

TPlUTF8 TPlUTF8::CreateShift(int32_t Shift)
{
	TPlUTF8Handle _Handle;
	SBCheckError(TPlUTF8_CreateShift(Shift, &_Handle));
	return TPlUTF8(_Handle, SB_OWN_HANDLE);
}

TPlUTF8 TPlUTF8::CreateNoInit()
{
	TPlUTF8Handle _Handle;
	SBCheckError(TPlUTF8_CreateNoInit(&_Handle));
	return TPlUTF8(_Handle, SB_OWN_HANDLE);
}

TPlUTF8 TPlUTF8::CreateForFinalize()
{
	TPlUTF8Handle _Handle;
	SBCheckError(TPlUTF8_CreateForFinalize(&_Handle));
	return TPlUTF8(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLUTF8 */

#ifdef SB_USE_CLASS_TPLCUSTOMUTF7

SB_INLINE int32_t TPlCustomUTF7::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomUTF7_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlCustomUTF7::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomUTF7_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlCustomUTF7::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomUTF7_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlCustomUTF7::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomUTF7_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlCustomUTF7::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCustomUTF7_ClassType(&OutResult));
	return OutResult;
}

TPlCustomUTF7::TPlCustomUTF7(TPlCustomUTF7Handle handle, TElOwnHandle ownHandle) : TPlCharset(handle, ownHandle)
{
}

TPlCustomUTF7::TPlCustomUTF7() : TPlCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCustomUTF7_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLCUSTOMUTF7 */

#ifdef SB_USE_CLASS_TPLUTF7

void TPlUTF7::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF7_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1988481810, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlUTF7::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF7_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-472907352, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlUTF7::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlUTF7_ClassType(&OutResult));
	return OutResult;
}

TPlUTF7::TPlUTF7(TPlUTF7Handle handle, TElOwnHandle ownHandle) : TPlCustomUTF7(handle, ownHandle)
{
}

TPlUTF7::TPlUTF7() : TPlCustomUTF7(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlUTF7_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLUTF7 */

#ifdef SB_USE_CLASS_TPLUTF7_IMAP

void TPlUTF7_IMAP::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF7_IMAP_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(339467666, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlUTF7_IMAP::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlUTF7_IMAP_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(131520256, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlUTF7_IMAP::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlUTF7_IMAP_ClassType(&OutResult));
	return OutResult;
}

TPlUTF7_IMAP::TPlUTF7_IMAP(TPlUTF7_IMAPHandle handle, TElOwnHandle ownHandle) : TPlCustomUTF7(handle, ownHandle)
{
}

TPlUTF7_IMAP::TPlUTF7_IMAP() : TPlCustomUTF7(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlUTF7_IMAP_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLUTF7_IMAP */

#ifdef SB_USE_CLASS_TPLCONVBUFFER

#ifdef SB_USE_CLASS_TSTREAM
bool TPlConvBuffer::CheckString(TStream &Stream, const std::string &Str, int32_t Shift)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlConvBuffer_CheckString(_Handle, Stream.getHandle(), Str.data(), (int32_t)Str.length(), Shift, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TPlConvBuffer::CheckString(TStream *Stream, const std::string &Str, int32_t Shift)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlConvBuffer_CheckString(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Str.data(), (int32_t)Str.length(), Shift, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
uint8_t TPlConvBuffer::GetByte(TStream &Stream, bool &Exists)
{
	uint8_t OutResult;
	int8_t ExistsRaw = (int8_t)Exists;
	SBCheckError(TPlConvBuffer_GetByte(_Handle, Stream.getHandle(), &ExistsRaw, &OutResult));
	Exists = (ExistsRaw != 0);
	return OutResult;
}

uint8_t TPlConvBuffer::GetByte(TStream *Stream, bool &Exists)
{
	uint8_t OutResult;
	int8_t ExistsRaw = (int8_t)Exists;
	SBCheckError(TPlConvBuffer_GetByte(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &ExistsRaw, &OutResult));
	Exists = (ExistsRaw != 0);
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
uint16_t TPlConvBuffer::GetWide(TStream &Stream, bool &Exists)
{
	uint16_t OutResult;
	int8_t ExistsRaw = (int8_t)Exists;
	SBCheckError(TPlConvBuffer_GetWide(_Handle, Stream.getHandle(), &ExistsRaw, &OutResult));
	Exists = (ExistsRaw != 0);
	return OutResult;
}

uint16_t TPlConvBuffer::GetWide(TStream *Stream, bool &Exists)
{
	uint16_t OutResult;
	int8_t ExistsRaw = (int8_t)Exists;
	SBCheckError(TPlConvBuffer_GetWide(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &ExistsRaw, &OutResult));
	Exists = (ExistsRaw != 0);
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
uint32_t TPlConvBuffer::GetLong(TStream &Stream, bool &Exists)
{
	uint32_t OutResult;
	int8_t ExistsRaw = (int8_t)Exists;
	SBCheckError(TPlConvBuffer_GetLong(_Handle, Stream.getHandle(), &ExistsRaw, &OutResult));
	Exists = (ExistsRaw != 0);
	return OutResult;
}

uint32_t TPlConvBuffer::GetLong(TStream *Stream, bool &Exists)
{
	uint32_t OutResult;
	int8_t ExistsRaw = (int8_t)Exists;
	SBCheckError(TPlConvBuffer_GetLong(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &ExistsRaw, &OutResult));
	Exists = (ExistsRaw != 0);
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TPlConvBuffer::ReturnByte()
{
	SBCheckError(TPlConvBuffer_ReturnByte(_Handle));
}

SB_INLINE void TPlConvBuffer::ReturnByte(uint8_t Value)
{
	SBCheckError(TPlConvBuffer_ReturnByte_1(_Handle, Value));
}

SB_INLINE void TPlConvBuffer::ReturnBytes(int32_t Count)
{
	SBCheckError(TPlConvBuffer_ReturnBytes(_Handle, Count));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TPlConvBuffer::Flush(TStream &Stream)
{
	SBCheckError(TPlConvBuffer_Flush(_Handle, Stream.getHandle()));
}

SB_INLINE void TPlConvBuffer::Flush(TStream *Stream)
{
	SBCheckError(TPlConvBuffer_Flush(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TPlConvBuffer::Put(const void * Data, int32_t Count)
{
	SBCheckError(TPlConvBuffer_Put(_Handle, Data, Count));
}

SB_INLINE void TPlConvBuffer::PutByte(uint8_t Value)
{
	SBCheckError(TPlConvBuffer_PutByte(_Handle, Value));
}

SB_INLINE void TPlConvBuffer::PutWordLE(uint16_t Value)
{
	SBCheckError(TPlConvBuffer_PutWordLE(_Handle, Value));
}

SB_INLINE uint8_t TPlConvBuffer::RevokeByte()
{
	uint8_t OutResult;
	SBCheckError(TPlConvBuffer_RevokeByte(_Handle, &OutResult));
	return OutResult;
}

TPlConvBuffer::TPlConvBuffer(TPlConvBufferHandle handle, TElOwnHandle ownHandle) : TInterfacedObject(handle, ownHandle)
{
}

TPlConvBuffer::TPlConvBuffer() : TInterfacedObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlConvBuffer_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLCONVBUFFER */

#ifdef SB_USE_CLASS_TPLCUSTOMSTRINGSTREAM

SB_INLINE int32_t TPlCustomStringStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TPlCustomStringStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlCustomStringStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TPlCustomStringStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlCustomStringStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TPlCustomStringStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TPlCustomStringStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TPlCustomStringStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE void TPlCustomStringStream::Clear()
{
	SBCheckError(TPlCustomStringStream_Clear(_Handle));
}

TPlCustomStringStream::TPlCustomStringStream(TPlCustomStringStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TPlCustomStringStream::TPlCustomStringStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCustomStringStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLCUSTOMSTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAM

void TPlAnsiStringStream::get_Data(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlAnsiStringStream_get_Data(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(6513069, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TPlAnsiStringStream::set_Data(const std::string &Value)
{
	SBCheckError(TPlAnsiStringStream_set_Data(_Handle, Value.data(), (int32_t)Value.length()));
}

TPlAnsiStringStream::TPlAnsiStringStream(TPlAnsiStringStreamHandle handle, TElOwnHandle ownHandle) : TPlCustomStringStream(handle, ownHandle)
{
}

TPlAnsiStringStream::TPlAnsiStringStream() : TPlCustomStringStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlAnsiStringStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAM

void TPlWideStringStream::get_Data(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlWideStringStream_get_Data(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1868646672, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TPlWideStringStream::get_Data(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TPlWideStringStream_get_Data(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1868646672, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TPlWideStringStream::set_Data(const sb_u16string &Value)
{
	SBCheckError(TPlWideStringStream_set_Data(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TPlWideStringStream::set_Data(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TPlWideStringStream_set_Data(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TPlWideStringStream::TPlWideStringStream(TPlWideStringStreamHandle handle, TElOwnHandle ownHandle) : TPlCustomStringStream(handle, ownHandle)
{
}

TPlWideStringStream::TPlWideStringStream() : TPlCustomStringStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlWideStringStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLBYTEARRAYSTREAM

TPlByteArrayStream::TPlByteArrayStream(TPlByteArrayStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TPlByteArrayStream::TPlByteArrayStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlByteArrayStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLBYTEARRAYSTREAM */

#ifdef SB_USE_CLASS_TPLCUSTOMSTRINGSTREAMPOOL

TPlCustomStringStreamPool::TPlCustomStringStreamPool(TPlCustomStringStreamPoolHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TPlCustomStringStreamPool::TPlCustomStringStreamPool() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCustomStringStreamPool_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLCUSTOMSTRINGSTREAMPOOL */

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAMPOOL

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAM
SB_INLINE TPlAnsiStringStreamHandle TPlAnsiStringStreamPool::AcquireStream()
{
	TPlAnsiStringStreamHandle OutResult;
	SBCheckError(TPlAnsiStringStreamPool_AcquireStream(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAM
SB_INLINE void TPlAnsiStringStreamPool::ReleaseStream(TPlAnsiStringStream &Stream)
{
	SBCheckError(TPlAnsiStringStreamPool_ReleaseStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TPlAnsiStringStreamPool::ReleaseStream(TPlAnsiStringStream *Stream)
{
	SBCheckError(TPlAnsiStringStreamPool_ReleaseStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAM */

TPlAnsiStringStreamPool::TPlAnsiStringStreamPool(TPlAnsiStringStreamPoolHandle handle, TElOwnHandle ownHandle) : TPlCustomStringStreamPool(handle, ownHandle)
{
}

TPlAnsiStringStreamPool::TPlAnsiStringStreamPool() : TPlCustomStringStreamPool(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlAnsiStringStreamPool_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAMPOOL */

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAMPOOL

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAM
SB_INLINE TPlWideStringStreamHandle TPlWideStringStreamPool::AcquireStream()
{
	TPlWideStringStreamHandle OutResult;
	SBCheckError(TPlWideStringStreamPool_AcquireStream(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAM
SB_INLINE void TPlWideStringStreamPool::ReleaseStream(TPlWideStringStream &Stream)
{
	SBCheckError(TPlWideStringStreamPool_ReleaseStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TPlWideStringStreamPool::ReleaseStream(TPlWideStringStream *Stream)
{
	SBCheckError(TPlWideStringStreamPool_ReleaseStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAM */

TPlWideStringStreamPool::TPlWideStringStreamPool(TPlWideStringStreamPoolHandle handle, TElOwnHandle ownHandle) : TPlCustomStringStreamPool(handle, ownHandle)
{
}

TPlWideStringStreamPool::TPlWideStringStreamPool() : TPlCustomStringStreamPool(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlWideStringStreamPool_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAMPOOL */

#ifdef SB_USE_GLOBAL_PROCS_CHSCONV

SB_INLINE void EnumCharsets(void * EnumProc, void * UserData)
{
	SBCheckError(SBChSConv_EnumCharsets(EnumProc, UserData));
}

#ifdef SB_USE_CLASS_IPLCHARSET
SB_INLINE IPlCharsetHandle CreateCharset(const std::string &Name)
{
	IPlCharsetHandle OutResult;
	SBCheckError(SBChSConv_CreateCharset(Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_IPLCHARSET */

#ifdef SB_USE_CLASS_IPLCHARSET
SB_INLINE IPlCharsetHandle CreateCharsetByDescription(const std::string &ADescription)
{
	IPlCharsetHandle OutResult;
	SBCheckError(SBChSConv_CreateCharsetByDescription(ADescription.data(), (int32_t)ADescription.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_IPLCHARSET */

#ifdef SB_USE_CLASS_IPLCHARSET
SB_INLINE IPlCharsetHandle CreateSystemDefaultCharset()
{
	IPlCharsetHandle OutResult;
	SBCheckError(SBChSConv_CreateSystemDefaultCharset(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_IPLCHARSET */

void GetSystemDefaultCharsetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSConv_GetSystemDefaultCharsetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1743342996, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetCharsetNameByAlias(const std::string &Alias, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSConv_GetCharsetNameByAlias(Alias.data(), (int32_t)Alias.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1138165464, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void InitializeCharsetObjects()
{
	SBCheckError(SBChSConv_InitializeCharsetObjects());
}

#endif /* SB_USE_GLOBAL_PROCS_CHSCONV */

};	/* namespace SecureBlackbox */

