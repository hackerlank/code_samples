#include "sbstrutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSTRINGCONVERTER

void TElStringConverter::StrToUtf8(const std::string &Source, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElStringConverter_StrToUtf8(_Handle, Source.data(), (int32_t)Source.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(533972093, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElStringConverter::Utf8ToStr(const std::vector<uint8_t> &Source, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElStringConverter_Utf8ToStr(_Handle, SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(519888027, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElStringConverter::StrToWideStr(const std::string &Source, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElStringConverter_StrToWideStr(_Handle, Source.data(), (int32_t)Source.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1144506905, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElStringConverter::WideStrToStr(const std::vector<uint8_t> &Source, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElStringConverter_WideStrToStr(_Handle, SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2009635031, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElStringConverter::get_DefCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElStringConverter_get_DefCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-122214887, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElStringConverter::set_DefCharset(const std::string &Value)
{
	SBCheckError(TElStringConverter_set_DefCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TElStringConverter::TElStringConverter(TElStringConverterHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElStringConverter::TElStringConverter() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElStringConverter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSTRINGCONVERTER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELPLATFORMSTRINGCONVERTER

void TElPlatformStringConverter::StrToUtf8(const std::string &Source, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPlatformStringConverter_StrToUtf8(_Handle, Source.data(), (int32_t)Source.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-498992272, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPlatformStringConverter::Utf8ToStr(const std::vector<uint8_t> &Source, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPlatformStringConverter_Utf8ToStr(_Handle, SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1619287258, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPlatformStringConverter::StrToWideStr(const std::string &Source, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPlatformStringConverter_StrToWideStr(_Handle, Source.data(), (int32_t)Source.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1028237718, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPlatformStringConverter::WideStrToStr(const std::vector<uint8_t> &Source, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPlatformStringConverter_WideStrToStr(_Handle, SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1128551901, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPlatformStringConverter::EncodeStr(const std::string &Source, int32_t Encoding, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPlatformStringConverter_EncodeStr(_Handle, Source.data(), (int32_t)Source.length(), Encoding, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1204784620, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPlatformStringConverter::EncodeStr(const std::string &Source, const std::string &Encoding, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPlatformStringConverter_EncodeStr_1(_Handle, Source.data(), (int32_t)Source.length(), Encoding.data(), (int32_t)Encoding.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1814045922, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPlatformStringConverter::DecodeStr(const std::vector<uint8_t> &Source, int32_t Encoding, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPlatformStringConverter_DecodeStr(_Handle, SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), Encoding, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1214949559, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPlatformStringConverter::DecodeStr(const std::vector<uint8_t> &Source, const std::string &Encoding, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPlatformStringConverter_DecodeStr_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), Encoding.data(), (int32_t)Encoding.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-46684779, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPlatformStringConverter::TElPlatformStringConverter(TElPlatformStringConverterHandle handle, TElOwnHandle ownHandle) : TElStringConverter(handle, ownHandle)
{
}

TElPlatformStringConverter::TElPlatformStringConverter() : TElStringConverter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPlatformStringConverter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPLATFORMSTRINGCONVERTER */
#endif

#ifdef SB_USE_GLOBAL_PROCS_STRUTILS

bool StringEndsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringEndsWith(S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StringEndsWith(const std::string &S, const std::string &SubS, bool IgnoreCase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringEndsWith_1(S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), (int8_t)IgnoreCase, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StringEquals(const std::string &S1, const std::string &S2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringEquals(S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StringEquals(const std::string &S1, const std::string &S2, bool IgnoreCase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringEquals_1(S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), (int8_t)IgnoreCase, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StringEquals(const std::string &S1, const std::string &S2, int32_t MaxLength)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringEquals_2(S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), MaxLength, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StringEquals(const std::string &S1, const std::string &S2, int32_t MaxLength, bool IgnoreCase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringEquals_3(S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), MaxLength, (int8_t)IgnoreCase, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StringEquals(const std::string &S1, int32_t Index1, const std::string &S2, int32_t Index2, int32_t MaxLength)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringEquals_4(S1.data(), (int32_t)S1.length(), Index1, S2.data(), (int32_t)S2.length(), Index2, MaxLength, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StringEquals(const std::string &S1, int32_t Index1, const std::string &S2, int32_t Index2, int32_t MaxLength, bool IgnoreCase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringEquals_5(S1.data(), (int32_t)S1.length(), Index1, S2.data(), (int32_t)S2.length(), Index2, MaxLength, (int8_t)IgnoreCase, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t StringIndexOf(const std::string &S, char C)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringIndexOf(S.data(), (int32_t)S.length(), C, &OutResult));
	return OutResult;
}

SB_INLINE int32_t StringIndexOf(const std::string &S, char C, int32_t StartIndex)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringIndexOf_1(S.data(), (int32_t)S.length(), C, StartIndex, &OutResult));
	return OutResult;
}

SB_INLINE int32_t StringIndexOf(const std::string &S, const std::string &SubS)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringIndexOf_2(S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t StringIndexOf(const std::string &S, const std::string &SubS, int32_t StartIndex)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringIndexOf_3(S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), StartIndex, &OutResult));
	return OutResult;
}

SB_INLINE int32_t StringIndexOfU(const sb_u16string &S, sb_char16_t C)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringIndexOfU(S.data(), (int32_t)S.length(), C, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t StringIndexOfU(const std::wstring &S, sb_char16_t C)
{
	int32_t OutResult;
	std::string u16S;
	sb_to_u16string(S, u16S);
	SBCheckError(SBStrUtils_StringIndexOfU(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, C, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

void StringInsert(const sb_u16string &S, int32_t Index, sb_char16_t C, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringInsert(S.data(), (int32_t)S.length(), Index, C, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1645161156, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void StringInsert(const std::wstring &S, int32_t Index, sb_char16_t C, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_StringInsert(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, Index, C, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1645161156, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void StringInsert(const sb_u16string &S, int32_t Index, const sb_u16string &SubS, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringInsert_1(S.data(), (int32_t)S.length(), Index, SubS.data(), (int32_t)SubS.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(102205309, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void StringInsert(const std::wstring &S, int32_t Index, const std::wstring &SubS, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16SubS;
	sb_to_u16string(SubS, u16SubS);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_StringInsert_1(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, Index, reinterpret_cast<const sb_char16_t*>(u16SubS.data()), (int32_t)u16SubS.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(102205309, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void StringInsert(const std::string &S, int32_t Index, char C, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringInsert_2(S.data(), (int32_t)S.length(), Index, C, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1033412616, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringInsert(const std::string &S, int32_t Index, const std::string &SubS, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringInsert_3(S.data(), (int32_t)S.length(), Index, SubS.data(), (int32_t)SubS.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1649382111, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool StringIsEmpty(const std::string &S)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringIsEmpty(S.data(), (int32_t)S.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t StringLastIndexOf(const sb_u16string &S, sb_char16_t C)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringLastIndexOf(S.data(), (int32_t)S.length(), C, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t StringLastIndexOf(const std::wstring &S, sb_char16_t C)
{
	int32_t OutResult;
	std::string u16S;
	sb_to_u16string(S, u16S);
	SBCheckError(SBStrUtils_StringLastIndexOf(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, C, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t StringLastIndexOf(const sb_u16string &S, sb_char16_t C, int32_t StartIndex)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringLastIndexOf_1(S.data(), (int32_t)S.length(), C, StartIndex, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t StringLastIndexOf(const std::wstring &S, sb_char16_t C, int32_t StartIndex)
{
	int32_t OutResult;
	std::string u16S;
	sb_to_u16string(S, u16S);
	SBCheckError(SBStrUtils_StringLastIndexOf_1(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, C, StartIndex, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t StringLastIndexOf(const std::string &S, char C)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringLastIndexOf_2(S.data(), (int32_t)S.length(), C, &OutResult));
	return OutResult;
}

SB_INLINE int32_t StringLastIndexOf(const std::string &S, char C, int32_t StartIndex)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_StringLastIndexOf_3(S.data(), (int32_t)S.length(), C, StartIndex, &OutResult));
	return OutResult;
}

void StringRemove(const sb_u16string &S, int32_t StartIndex, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringRemove(S.data(), (int32_t)S.length(), StartIndex, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(973886018, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void StringRemove(const std::wstring &S, int32_t StartIndex, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_StringRemove(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, StartIndex, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(973886018, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void StringRemove(const sb_u16string &S, int32_t StartIndex, int32_t Count, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringRemove_1(S.data(), (int32_t)S.length(), StartIndex, Count, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-972792946, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void StringRemove(const std::wstring &S, int32_t StartIndex, int32_t Count, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_StringRemove_1(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, StartIndex, Count, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-972792946, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void WideStringRemove(const sb_u16string &S, int32_t StartIndex, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_WideStringRemove(S.data(), (int32_t)S.length(), StartIndex, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1251133819, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideStringRemove(const std::wstring &S, int32_t StartIndex, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_WideStringRemove(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, StartIndex, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1251133819, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void WideStringRemove(const sb_u16string &S, int32_t StartIndex, int32_t Count, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_WideStringRemove_1(S.data(), (int32_t)S.length(), StartIndex, Count, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(964724458, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideStringRemove(const std::wstring &S, int32_t StartIndex, int32_t Count, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_WideStringRemove_1(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, StartIndex, Count, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(964724458, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void AnsiStringRemove(const std::string &S, int32_t StartIndex, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_AnsiStringRemove(S.data(), (int32_t)S.length(), StartIndex, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1212321831, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void AnsiStringRemove(const std::string &S, int32_t StartIndex, int32_t Count, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_AnsiStringRemove_1(S.data(), (int32_t)S.length(), StartIndex, Count, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1154727601, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringToLower(const std::string &S, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringToLower(S.data(), (int32_t)S.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(279017803, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringToLowerInvariant(const std::string &S, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringToLowerInvariant(S.data(), (int32_t)S.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(565969332, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool StringStartsWith(const std::string &S, const std::string &SubS)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringStartsWith(S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StringStartsWith(const std::string &S, const std::string &SubS, bool IgnoreCase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_StringStartsWith_1(S.data(), (int32_t)S.length(), SubS.data(), (int32_t)SubS.length(), (int8_t)IgnoreCase, &OutResultRaw));
	return (OutResultRaw != 0);
}

void StringSubstring(const std::string &S, int32_t StartIndex, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringSubstring(S.data(), (int32_t)S.length(), StartIndex, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2143324377, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringSubstring(const std::string &S, int32_t StartIndex, int32_t Length, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringSubstring_1(S.data(), (int32_t)S.length(), StartIndex, Length, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-334652627, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringSubstring(const sb_u16string &S, int32_t StartIndex, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringSubstring_2(S.data(), (int32_t)S.length(), StartIndex, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1618198151, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void StringSubstring(const std::wstring &S, int32_t StartIndex, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_StringSubstring_2(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, StartIndex, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1618198151, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void StringSubstring(const sb_u16string &S, int32_t StartIndex, int32_t Length, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringSubstring_3(S.data(), (int32_t)S.length(), StartIndex, Length, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1198147904, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void StringSubstring(const std::wstring &S, int32_t StartIndex, int32_t Length, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_StringSubstring_3(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, StartIndex, Length, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1198147904, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void StringTrim(const std::string &S, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringTrim(S.data(), (int32_t)S.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-676069323, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringTrimEnd(const std::string &S, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringTrimEnd(S.data(), (int32_t)S.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1180104044, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringTrimStart(const std::string &S, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringTrimStart(S.data(), (int32_t)S.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1041626105, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringToUpper(const std::string &S, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringToUpper(S.data(), (int32_t)S.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(187952799, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringToUpperInvariant(const std::string &S, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringToUpperInvariant(S.data(), (int32_t)S.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1549023524, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void StringSplit(const std::string &S, char Separator, TStringList &OutResult)
{
	SBCheckError(SBStrUtils_StringSplit(S.data(), (int32_t)S.length(), Separator, OutResult.getHandle()));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void StringSplit(const std::string &S, char Separator, bool RemoveEmptyEntries, TStringList &OutResult)
{
	SBCheckError(SBStrUtils_StringSplit_1(S.data(), (int32_t)S.length(), Separator, (int8_t)RemoveEmptyEntries, OutResult.getHandle()));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

bool StringSplitPV(const std::string &S, std::string &Name, std::string &Value)
{
	int32_t szName = (int32_t)Name.length();
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBStrUtils_StringSplitPV(S.data(), (int32_t)S.length(), (char *)Name.data(), &szName, (char *)Value.data(), &szValue, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Name.resize(szName);
		SBCheckError(SBGetLastReturnStringA(94425039, 1, (char *)Name.data(), &szName));
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringA(94425039, 2, (char *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Name.resize(szName);
	Value.resize(szValue);
	return (OutResultRaw != 0);
}

bool StringSplitPV(const std::string &S, std::string &Name, std::string &Value, char Separator)
{
	int32_t szName = (int32_t)Name.length();
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBStrUtils_StringSplitPV_1(S.data(), (int32_t)S.length(), (char *)Name.data(), &szName, (char *)Value.data(), &szValue, Separator, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Name.resize(szName);
		SBCheckError(SBGetLastReturnStringA(-2077982141, 1, (char *)Name.data(), &szName));
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringA(-2077982141, 2, (char *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Name.resize(szName);
	Value.resize(szValue);
	return (OutResultRaw != 0);
}

bool StringSplitPV(const sb_u16string &S, sb_u16string &Name, sb_u16string &Value)
{
	int32_t szName = (int32_t)Name.length();
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBStrUtils_StringSplitPV_2(S.data(), (int32_t)S.length(), (sb_char16_t *)Name.data(), &szName, (sb_char16_t *)Value.data(), &szValue, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Name.resize(szName);
		SBCheckError(SBGetLastReturnStringW(959801112, 1, (sb_char16_t *)Name.data(), &szName));
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringW(959801112, 2, (sb_char16_t *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Name.resize(szName);
	Value.resize(szValue);
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool StringSplitPV(const std::wstring &S, std::wstring &Name, std::wstring &Value)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16Name;
	int32_t szName = 0;
	std::string u16Value;
	int32_t szValue = 0;
	int8_t OutResultRaw = 0;
	uint32_t _err = SBStrUtils_StringSplitPV_2(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, NULL, &szName, NULL, &szValue, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Name.resize(szName << 1);
		SBCheckError(SBGetLastReturnStringW(959801112, 1, reinterpret_cast<sb_char16_t*>((char*)u16Name.data()), &szName));
		u16Value.resize(szValue << 1);
		SBCheckError(SBGetLastReturnStringW(959801112, 2, reinterpret_cast<sb_char16_t*>((char*)u16Value.data()), &szValue));
	}
	else
		SBCheckError(_err);

	u16Name.resize(szName << 1);
	sb_u16_to_wstring(u16Name, Name);
	u16Value.resize(szValue << 1);
	sb_u16_to_wstring(u16Value, Value);
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool StringSplitPV(const sb_u16string &S, sb_u16string &Name, sb_u16string &Value, sb_char16_t Separator)
{
	int32_t szName = (int32_t)Name.length();
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBStrUtils_StringSplitPV_3(S.data(), (int32_t)S.length(), (sb_char16_t *)Name.data(), &szName, (sb_char16_t *)Value.data(), &szValue, Separator, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Name.resize(szName);
		SBCheckError(SBGetLastReturnStringW(-1466796613, 1, (sb_char16_t *)Name.data(), &szName));
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringW(-1466796613, 2, (sb_char16_t *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Name.resize(szName);
	Value.resize(szValue);
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool StringSplitPV(const std::wstring &S, std::wstring &Name, std::wstring &Value, sb_char16_t Separator)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16Name;
	int32_t szName = 0;
	std::string u16Value;
	int32_t szValue = 0;
	int8_t OutResultRaw = 0;
	uint32_t _err = SBStrUtils_StringSplitPV_3(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, NULL, &szName, NULL, &szValue, Separator, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Name.resize(szName << 1);
		SBCheckError(SBGetLastReturnStringW(-1466796613, 1, reinterpret_cast<sb_char16_t*>((char*)u16Name.data()), &szName));
		u16Value.resize(szValue << 1);
		SBCheckError(SBGetLastReturnStringW(-1466796613, 2, reinterpret_cast<sb_char16_t*>((char*)u16Value.data()), &szValue));
	}
	else
		SBCheckError(_err);

	u16Name.resize(szName << 1);
	sb_u16_to_wstring(u16Name, Name);
	u16Value.resize(szValue << 1);
	sb_u16_to_wstring(u16Value, Value);
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

void StringPadLeft(const std::string &S, char C, int32_t Len, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringPadLeft(S.data(), (int32_t)S.length(), C, Len, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1912659774, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringPadRight(const std::string &S, char C, int32_t Len, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringPadRight(S.data(), (int32_t)S.length(), C, Len, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1231532893, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StrToDefEncoding(const std::string &AStr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_StrToDefEncoding(AStr.data(), (int32_t)AStr.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(592651665, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DefEncodingToStr(const std::vector<uint8_t> &ASrc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_DefEncodingToStr(SB_STD_VECTOR_FRONT_ADR(ASrc), (int32_t)ASrc.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-424341366, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StrToStdEncoding(const std::string &AStr, bool UseUTF8, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_StrToStdEncoding(AStr.data(), (int32_t)AStr.length(), (int8_t)UseUTF8, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1400787785, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StdEncodingToStr(const std::vector<uint8_t> &ASrc, bool UseUTF8, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StdEncodingToStr(SB_STD_VECTOR_FRONT_ADR(ASrc), (int32_t)ASrc.size(), (int8_t)UseUTF8, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1378435676, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBExtractFilePath(const std::string &FileName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SBExtractFilePath(FileName.data(), (int32_t)FileName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1257492946, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBExtractFileName(const std::string &FileName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SBExtractFileName(FileName.data(), (int32_t)FileName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1032016994, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBExtractFileExt(const std::string &FileName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SBExtractFileExt(FileName.data(), (int32_t)FileName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1078876967, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBExtractFileExt(const std::string &FileName, bool IncludeDot, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SBExtractFileExt_1(FileName.data(), (int32_t)FileName.length(), (int8_t)IncludeDot, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2113609023, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ReplaceExt(const std::string &FileName, const std::string &NewExtension, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ReplaceExt(FileName.data(), (int32_t)FileName.length(), NewExtension.data(), (int32_t)NewExtension.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(733186404, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool FilenameMatchesMask(const std::string &Name, const std::string &Mask, bool CaseSensitive)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_FilenameMatchesMask(Name.data(), (int32_t)Name.length(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DomainNameMatchesCertSN(const std::string &DomainName, const std::string &Match)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_DomainNameMatchesCertSN(DomainName.data(), (int32_t)DomainName.length(), Match.data(), (int32_t)Match.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t CountFoldersInPath(const std::string &Path)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_CountFoldersInPath(Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

void ParseURL(const std::string &URL, bool SingleNameIsPage, std::string &Protocol, std::string &Username, std::string &Password, std::string &Host, uint16_t &Port, std::string &Path, std::string &anchor, std::string &Parameters)
{
	int32_t szProtocol = (int32_t)Protocol.length();
	int32_t szUsername = (int32_t)Username.length();
	int32_t szPassword = (int32_t)Password.length();
	int32_t szHost = (int32_t)Host.length();
	int32_t szPath = (int32_t)Path.length();
	int32_t szanchor = (int32_t)anchor.length();
	int32_t szParameters = (int32_t)Parameters.length();
	uint32_t _err = SBStrUtils_ParseURL(URL.data(), (int32_t)URL.length(), (int8_t)SingleNameIsPage, (char *)Protocol.data(), &szProtocol, (char *)Username.data(), &szUsername, (char *)Password.data(), &szPassword, (char *)Host.data(), &szHost, &Port, (char *)Path.data(), &szPath, (char *)anchor.data(), &szanchor, (char *)Parameters.data(), &szParameters);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Protocol.resize(szProtocol);
		SBCheckError(SBGetLastReturnStringA(543693857, 2, (char *)Protocol.data(), &szProtocol));
		Username.resize(szUsername);
		SBCheckError(SBGetLastReturnStringA(543693857, 3, (char *)Username.data(), &szUsername));
		Password.resize(szPassword);
		SBCheckError(SBGetLastReturnStringA(543693857, 4, (char *)Password.data(), &szPassword));
		Host.resize(szHost);
		SBCheckError(SBGetLastReturnStringA(543693857, 5, (char *)Host.data(), &szHost));
		Path.resize(szPath);
		SBCheckError(SBGetLastReturnStringA(543693857, 7, (char *)Path.data(), &szPath));
		anchor.resize(szanchor);
		SBCheckError(SBGetLastReturnStringA(543693857, 8, (char *)anchor.data(), &szanchor));
		Parameters.resize(szParameters);
		SBCheckError(SBGetLastReturnStringA(543693857, 9, (char *)Parameters.data(), &szParameters));
	}
	else
		SBCheckError(_err);

	Protocol.resize(szProtocol);
	Username.resize(szUsername);
	Password.resize(szPassword);
	Host.resize(szHost);
	Path.resize(szPath);
	anchor.resize(szanchor);
	Parameters.resize(szParameters);
}

void ParseURL(const std::string &URL, bool SingleNameIsPage, std::string &Protocol, std::string &Username, std::string &Password, std::string &Host, uint16_t &Port, std::string &Path, std::string &anchor, std::string &Parameters, const std::string &DefaultProtocol)
{
	int32_t szProtocol = (int32_t)Protocol.length();
	int32_t szUsername = (int32_t)Username.length();
	int32_t szPassword = (int32_t)Password.length();
	int32_t szHost = (int32_t)Host.length();
	int32_t szPath = (int32_t)Path.length();
	int32_t szanchor = (int32_t)anchor.length();
	int32_t szParameters = (int32_t)Parameters.length();
	uint32_t _err = SBStrUtils_ParseURL_1(URL.data(), (int32_t)URL.length(), (int8_t)SingleNameIsPage, (char *)Protocol.data(), &szProtocol, (char *)Username.data(), &szUsername, (char *)Password.data(), &szPassword, (char *)Host.data(), &szHost, &Port, (char *)Path.data(), &szPath, (char *)anchor.data(), &szanchor, (char *)Parameters.data(), &szParameters, DefaultProtocol.data(), (int32_t)DefaultProtocol.length());
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Protocol.resize(szProtocol);
		SBCheckError(SBGetLastReturnStringA(422826586, 2, (char *)Protocol.data(), &szProtocol));
		Username.resize(szUsername);
		SBCheckError(SBGetLastReturnStringA(422826586, 3, (char *)Username.data(), &szUsername));
		Password.resize(szPassword);
		SBCheckError(SBGetLastReturnStringA(422826586, 4, (char *)Password.data(), &szPassword));
		Host.resize(szHost);
		SBCheckError(SBGetLastReturnStringA(422826586, 5, (char *)Host.data(), &szHost));
		Path.resize(szPath);
		SBCheckError(SBGetLastReturnStringA(422826586, 7, (char *)Path.data(), &szPath));
		anchor.resize(szanchor);
		SBCheckError(SBGetLastReturnStringA(422826586, 8, (char *)anchor.data(), &szanchor));
		Parameters.resize(szParameters);
		SBCheckError(SBGetLastReturnStringA(422826586, 9, (char *)Parameters.data(), &szParameters));
	}
	else
		SBCheckError(_err);

	Protocol.resize(szProtocol);
	Username.resize(szUsername);
	Password.resize(szPassword);
	Host.resize(szHost);
	Path.resize(szPath);
	anchor.resize(szanchor);
	Parameters.resize(szParameters);
}

void ComposeURL(const std::string &Protocol, const std::string &UserName, const std::string &Password, const std::string &Host, uint16_t Port, const std::string &Path, const std::string &Anchor, const std::string &Parameters, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ComposeURL(Protocol.data(), (int32_t)Protocol.length(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), Host.data(), (int32_t)Host.length(), Port, Path.data(), (int32_t)Path.length(), Anchor.data(), (int32_t)Anchor.length(), Parameters.data(), (int32_t)Parameters.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1399166752, 8, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t SBRightPos(const std::string &Substr, const std::string &Str)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_SBRightPos(Substr.data(), (int32_t)Substr.length(), Str.data(), (int32_t)Str.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t SBPos(const std::string &substr, const std::string &str)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_SBPos(substr.data(), (int32_t)substr.length(), str.data(), (int32_t)str.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t SBPos(const std::vector<uint8_t> &SubP, const std::vector<uint8_t> &P, int32_t StartPos)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_SBPos_1(SB_STD_VECTOR_FRONT_ADR(SubP), (int32_t)SubP.size(), SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), StartPos, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SBPos(const std::string &SubP, const std::vector<uint8_t> &P, int32_t StartPos)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_SBPos_2(SubP.data(), (int32_t)SubP.length(), SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), StartPos, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SBPos(uint8_t SubP, const std::vector<uint8_t> &P)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_SBPos_3(SubP, SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), &OutResult));
	return OutResult;
}

void SBCopy(const std::vector<uint8_t> &str, int32_t Offset, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_SBCopy(SB_STD_VECTOR_FRONT_ADR(str), (int32_t)str.size(), Offset, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1028653569, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBCopy(const std::vector<uint8_t> &str, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_SBCopy_1(SB_STD_VECTOR_FRONT_ADR(str), (int32_t)str.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1553847931, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBConcatAnsiStrings(const std::string &Str1, char Str2, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SBConcatAnsiStrings(Str1.data(), (int32_t)Str1.length(), Str2, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1300119611, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBConcatAnsiStrings(const std::string &Str1, const std::string &Str2, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SBConcatAnsiStrings_1(Str1.data(), (int32_t)Str1.length(), Str2.data(), (int32_t)Str2.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1871730359, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTRINGLIST
void SBConcatAnsiStrings(const TStringList &Strs, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SBConcatAnsiStrings_2(Strs.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(473211872, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

void AnsiStrPas(char * P, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_AnsiStrPas(P, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1270459307, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void OIDToStr(const std::vector<uint8_t> &OID, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_OIDToStr(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1176363489, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StrToOID(const std::string &Str, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_StrToOID(Str.data(), (int32_t)Str.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1715747177, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StrToUTF8(const std::string &AStr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_StrToUTF8(AStr.data(), (int32_t)AStr.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(739672873, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UTF8ToStr(const std::vector<uint8_t> &ASrc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_UTF8ToStr(SB_STD_VECTOR_FRONT_ADR(ASrc), (int32_t)ASrc.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1731110236, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StrToWideStr(const std::string &AStr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_StrToWideStr(AStr.data(), (int32_t)AStr.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-249466642, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WideStrToStr(const std::vector<uint8_t> &ASrc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_WideStrToStr(SB_STD_VECTOR_FRONT_ADR(ASrc), (int32_t)ASrc.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-869117504, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void EncodeString(const std::string &AStr, const std::string &Encoding, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_EncodeString(AStr.data(), (int32_t)AStr.length(), Encoding.data(), (int32_t)Encoding.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1442745325, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DecodeString(const std::vector<uint8_t> &ASrc, const std::string &Encoding, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_DecodeString(SB_STD_VECTOR_FRONT_ADR(ASrc), (int32_t)ASrc.size(), Encoding.data(), (int32_t)Encoding.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(362933983, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UnicodeChangeEndianness(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_UnicodeChangeEndianness(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1047858921, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WideStrToUTF8(const sb_u16string &AStr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_WideStrToUTF8(AStr.data(), (int32_t)AStr.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(362357425, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideStrToUTF8(const std::wstring &AStr, std::vector<uint8_t> &OutResult)
{
	std::string u16AStr;
	sb_to_u16string(AStr, u16AStr);
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_WideStrToUTF8(reinterpret_cast<const sb_char16_t*>(u16AStr.data()), (int32_t)u16AStr.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(362357425, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

void WideStrToUTF8(const void * ASrc, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_WideStrToUTF8_1(ASrc, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1800960671, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UTF8ToWideStr(const std::vector<uint8_t> &Buf, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_UTF8ToWideStr(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2072274432, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void UTF8ToWideStr(const std::vector<uint8_t> &Buf, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_UTF8ToWideStr(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2072274432, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void UTF8ToWideStr(const void * Buf, int32_t Size, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_UTF8ToWideStr_1(Buf, Size, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1616583319, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void UTF8ToWideStr(const void * Buf, int32_t Size, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_UTF8ToWideStr_1(Buf, Size, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1616583319, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

ConversionResult ConvertUTF16toUTF8(const sb_u16string &source, std::vector<uint8_t> &target, ConversionFlags flags, bool BOM)
{
	int32_t sztarget = (int32_t)target.size();
	ConversionResultRaw OutResultRaw = 0;
	uint32_t _err = SBStrUtils_ConvertUTF16toUTF8(source.data(), (int32_t)source.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(target), &sztarget, (ConversionFlagsRaw)flags, (int8_t)BOM, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		target.resize(sztarget);
		SBCheckError(SBGetLastReturnBuffer(1483428958, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(target), &sztarget));
	}
	else
		SBCheckError(_err);

	target.resize(sztarget);
	return (ConversionResult)OutResultRaw;
}
#ifdef SB_U16STRING_USED
ConversionResult ConvertUTF16toUTF8(const std::wstring &source, std::vector<uint8_t> &target, ConversionFlags flags, bool BOM)
{
	std::string u16source;
	sb_to_u16string(source, u16source);
	int32_t sztarget = (int32_t)target.size();
	ConversionResultRaw OutResultRaw = 0;
	uint32_t _err = SBStrUtils_ConvertUTF16toUTF8(reinterpret_cast<const sb_char16_t*>(u16source.data()), (int32_t)u16source.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(target), &sztarget, (ConversionFlagsRaw)flags, (int8_t)BOM, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		target.resize(sztarget);
		SBCheckError(SBGetLastReturnBuffer(1483428958, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(target), &sztarget));
	}
	else
		SBCheckError(_err);

	target.resize(sztarget);
	return (ConversionResult)OutResultRaw;
}
#endif /* SB_U16STRING_USED */

bool isLegalUTF8(const std::vector<uint8_t> &source, uint32_t sourcelen)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_isLegalUTF8(SB_STD_VECTOR_FRONT_ADR(source), (int32_t)source.size(), sourcelen, &OutResultRaw));
	return (OutResultRaw != 0);
}

ConversionResult ConvertUTF8toUTF16(const std::vector<uint8_t> &source, sb_u16string &target, ConversionFlags flags, bool BOM)
{
	int32_t sztarget = (int32_t)target.length();
	ConversionResultRaw OutResultRaw = 0;
	uint32_t _err = SBStrUtils_ConvertUTF8toUTF16(SB_STD_VECTOR_FRONT_ADR(source), (int32_t)source.size(), (sb_char16_t *)target.data(), &sztarget, (ConversionFlagsRaw)flags, (int8_t)BOM, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		target.resize(sztarget);
		SBCheckError(SBGetLastReturnStringW(1241701494, 1, (sb_char16_t *)target.data(), &sztarget));
	}
	else
		SBCheckError(_err);

	target.resize(sztarget);
	return (ConversionResult)OutResultRaw;
}
#ifdef SB_U16STRING_USED
ConversionResult ConvertUTF8toUTF16(const std::vector<uint8_t> &source, std::wstring &target, ConversionFlags flags, bool BOM)
{
	std::string u16target;
	sb_to_u16string(target, u16target);
	int32_t sztarget = (int32_t)u16target.length() >> 1;
	ConversionResultRaw OutResultRaw = 0;
	uint32_t _err = SBStrUtils_ConvertUTF8toUTF16(SB_STD_VECTOR_FRONT_ADR(source), (int32_t)source.size(), reinterpret_cast<sb_char16_t*>((char*)u16target.data()), &sztarget, (ConversionFlagsRaw)flags, (int8_t)BOM, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16target.resize(sztarget << 1);
		SBCheckError(SBGetLastReturnStringW(1241701494, 1, reinterpret_cast<sb_char16_t*>((char*)u16target.data()), &sztarget));
	}
	else
		SBCheckError(_err);

	u16target.resize(sztarget << 1);
	sb_u16_to_wstring(u16target, target);
	return (ConversionResult)OutResultRaw;
}
#endif /* SB_U16STRING_USED */

void ConvertFromUTF8String(const std::vector<uint8_t> &Source, bool CheckBOM, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ConvertFromUTF8String(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (int8_t)CheckBOM, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1001076423, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertFromUTF8String(const std::vector<uint8_t> &Source, bool CheckBOM, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_ConvertFromUTF8String(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (int8_t)CheckBOM, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1001076423, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void ConvertToUTF8String(const sb_u16string &Source, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_ConvertToUTF8String(Source.data(), (int32_t)Source.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(640382488, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertToUTF8String(const std::wstring &Source, std::vector<uint8_t> &OutResult)
{
	std::string u16Source;
	sb_to_u16string(Source, u16Source);
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_ConvertToUTF8String(reinterpret_cast<const sb_char16_t*>(u16Source.data()), (int32_t)u16Source.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(640382488, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

void ConvertFromUTF32String(const std::vector<uint8_t> &Source, bool CheckBOM, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ConvertFromUTF32String(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (int8_t)CheckBOM, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1113134406, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertFromUTF32String(const std::vector<uint8_t> &Source, bool CheckBOM, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_ConvertFromUTF32String(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (int8_t)CheckBOM, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1113134406, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELSTRINGCONVERTER
SB_INLINE void SetGlobalStringConverter(TElStringConverter &Converter)
{
	SBCheckError(SBStrUtils_SetGlobalStringConverter(Converter.getHandle()));
}
SB_INLINE void SetGlobalStringConverter(TElStringConverter *Converter)
{
	SBCheckError(SBStrUtils_SetGlobalStringConverter((Converter != NULL) ? Converter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGCONVERTER */

SB_INLINE void SetDefaultCharset(const std::string &Charset)
{
	SBCheckError(SBStrUtils_SetDefaultCharset(Charset.data(), (int32_t)Charset.length()));
}

SB_INLINE int64_t StrMixToInt64(const std::string &S)
{
	int64_t OutResult;
	SBCheckError(SBStrUtils_StrMixToInt64(S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

void SBTrim(const std::vector<uint8_t> &S, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_SBTrim(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(695529780, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBUppercase(const std::vector<uint8_t> &S, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_SBUppercase(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2048791828, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringReplace(const std::string &Source, const std::string &Entry, const std::string &ReplaceWith, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringReplace(Source.data(), (int32_t)Source.length(), Entry.data(), (int32_t)Entry.length(), ReplaceWith.data(), (int32_t)ReplaceWith.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1638498632, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringReplace(const sb_u16string &Source, const sb_u16string &Entry, const sb_u16string &ReplaceWith, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_StringReplace_1(Source.data(), (int32_t)Source.length(), Entry.data(), (int32_t)Entry.length(), ReplaceWith.data(), (int32_t)ReplaceWith.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(254067259, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void StringReplace(const std::wstring &Source, const std::wstring &Entry, const std::wstring &ReplaceWith, std::wstring &OutResult)
{
	std::string u16Source;
	sb_to_u16string(Source, u16Source);
	std::string u16Entry;
	sb_to_u16string(Entry, u16Entry);
	std::string u16ReplaceWith;
	sb_to_u16string(ReplaceWith, u16ReplaceWith);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_StringReplace_1(reinterpret_cast<const sb_char16_t*>(u16Source.data()), (int32_t)u16Source.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Entry.data()), (int32_t)u16Entry.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ReplaceWith.data()), (int32_t)u16ReplaceWith.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(254067259, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void PAnsiCharToByteArray(const char * P, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBStrUtils_PAnsiCharToByteArray(P, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(552227106, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PrefixString(const std::string &S, int32_t Count, char Value, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PrefixString(S.data(), (int32_t)S.length(), Count, Value, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1584308007, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SuffixString(const std::string &S, int32_t Count, char Value, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SuffixString(S.data(), (int32_t)S.length(), Count, Value, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2116237477, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PathFirstComponent(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PathFirstComponent(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(845708353, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PathLastComponent(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PathLastComponent(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1571233744, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PathCutFirstComponent(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PathCutFirstComponent(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1859081865, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PathCutLastComponent(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PathCutLastComponent(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1239929717, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool PathIsDirectory(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_PathIsDirectory(Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void PathTrim(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PathTrim(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(235212813, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PathConcatenate(const std::string &Path1, const std::string &Path2, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PathConcatenate(Path1.data(), (int32_t)Path1.length(), Path2.data(), (int32_t)Path2.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(924707176, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PathNormalizeSlashes(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PathNormalizeSlashes(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(211776927, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PathReverseSlashes(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_PathReverseSlashes(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(156045233, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool PathMatchesMask(const std::string &Path, const std::string &Mask)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_PathMatchesMask(Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool PathMatchesMask(const std::string &Path, const std::string &Mask, bool CaseSensitive)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_PathMatchesMask_1(Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsFileMask(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_IsFileMask(Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void ExtractPathFromMask(const std::string &Mask, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ExtractPathFromMask(Mask.data(), (int32_t)Mask.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(898834100, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SftpNormalizePath(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_SftpNormalizePath(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1995022207, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipPathFirstComponent(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipPathFirstComponent(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1311314807, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipPathLastComponent(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipPathLastComponent(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-816976089, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipPathCutFirstComponent(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipPathCutFirstComponent(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1393851037, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipPathCutLastComponent(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipPathCutLastComponent(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1161060663, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ZipPathIsDirectory(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_ZipPathIsDirectory(Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void ZipPathTrim(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipPathTrim(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(29693647, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipPathConcatenate(const std::string &Path1, const std::string &Path2, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipPathConcatenate(Path1.data(), (int32_t)Path1.length(), Path2.data(), (int32_t)Path2.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1492092015, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipPathNormalizeSlashes(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipPathNormalizeSlashes(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-5031901, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipPathReverseSlashes(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipPathReverseSlashes(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1963745415, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ZipPathMatchesMask(const std::string &Path, const std::string &Mask)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_ZipPathMatchesMask(Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ZipPathMatchesMask(const std::string &Path, const std::string &Mask, bool CaseSensitive)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_ZipPathMatchesMask_1(Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ZipIsFileMask(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBStrUtils_ZipIsFileMask(Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void ZipExtractPathFromMask(const std::string &Mask, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ZipExtractPathFromMask(Mask.data(), (int32_t)Mask.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1599083866, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t PosExSafe(const std::string &SubStr, const std::string &S, int32_t Offset, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_PosExSafe(SubStr.data(), (int32_t)SubStr.length(), S.data(), (int32_t)S.length(), Offset, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t PosLast(const std::string &SubStr, const std::string &S)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_PosLast(SubStr.data(), (int32_t)SubStr.length(), S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t WidePosEx(const sb_u16string &SubStr, const sb_u16string &S, int32_t Offset, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_WidePosEx(SubStr.data(), (int32_t)SubStr.length(), S.data(), (int32_t)S.length(), Offset, Count, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t WidePosEx(const std::wstring &SubStr, const std::wstring &S, int32_t Offset, int32_t Count)
{
	int32_t OutResult;
	std::string u16SubStr;
	sb_to_u16string(SubStr, u16SubStr);
	std::string u16S;
	sb_to_u16string(S, u16S);
	SBCheckError(SBStrUtils_WidePosEx(reinterpret_cast<const sb_char16_t*>(u16SubStr.data()), (int32_t)u16SubStr.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, Offset, Count, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t WidePosLast(const sb_u16string &SubStr, const sb_u16string &S)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_WidePosLast(SubStr.data(), (int32_t)SubStr.length(), S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t WidePosLast(const std::wstring &SubStr, const std::wstring &S)
{
	int32_t OutResult;
	std::string u16SubStr;
	sb_to_u16string(SubStr, u16SubStr);
	std::string u16S;
	sb_to_u16string(S, u16S);
	SBCheckError(SBStrUtils_WidePosLast(reinterpret_cast<const sb_char16_t*>(u16SubStr.data()), (int32_t)u16SubStr.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

void WideStringToByteString(const sb_u16string &WS, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_WideStringToByteString(WS.data(), (int32_t)WS.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(391137432, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideStringToByteString(const std::wstring &WS, std::string &OutResult)
{
	std::string u16WS;
	sb_to_u16string(WS, u16WS);
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_WideStringToByteString(reinterpret_cast<const sb_char16_t*>(u16WS.data()), (int32_t)u16WS.length() >> 1, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(391137432, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

void AnsiStringToByteWideString(const std::string &S, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_AnsiStringToByteWideString(S.data(), (int32_t)S.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1302548839, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void AnsiStringToByteWideString(const std::string &S, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_AnsiStringToByteWideString(S.data(), (int32_t)S.length(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1302548839, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void IntToStrPadLeft(int32_t Val, int32_t iWidth, sb_char16_t chTemplate, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_IntToStrPadLeft(Val, iWidth, chTemplate, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1500854115, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void IntToStrPadLeft(int32_t Val, int32_t iWidth, sb_char16_t chTemplate, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_IntToStrPadLeft(Val, iWidth, chTemplate, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1500854115, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void GetWideBytesOf(const sb_u16string &Value, std::vector<uint8_t> &B)
{
	int32_t szB = (int32_t)B.size();
	uint32_t _err = SBStrUtils_GetWideBytesOf(Value.data(), (int32_t)Value.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(B), &szB);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		B.resize(szB);
		SBCheckError(SBGetLastReturnBuffer(930524820, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(B), &szB));
	}
	else
		SBCheckError(_err);

	B.resize(szB);
}
#ifdef SB_U16STRING_USED
void GetWideBytesOf(const std::wstring &Value, std::vector<uint8_t> &B)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	int32_t szB = (int32_t)B.size();
	uint32_t _err = SBStrUtils_GetWideBytesOf(reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(B), &szB);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		B.resize(szB);
		SBCheckError(SBGetLastReturnBuffer(930524820, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(B), &szB));
	}
	else
		SBCheckError(_err);

	B.resize(szB);
}
#endif /* SB_U16STRING_USED */

void GetStringOf(const std::vector<uint8_t> &Bytes, std::string &S)
{
	int32_t szS = (int32_t)S.length();
	uint32_t _err = SBStrUtils_GetStringOf(SB_STD_VECTOR_FRONT_ADR(Bytes), (int32_t)Bytes.size(), (char *)S.data(), &szS);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		S.resize(szS);
		SBCheckError(SBGetLastReturnStringA(-1266397000, 1, (char *)S.data(), &szS));
	}
	else
		SBCheckError(_err);

	S.resize(szS);
}

void GetStringOfEx(const std::vector<uint8_t> &Bytes, std::string &S, int64_t LPos, int64_t RPos)
{
	int32_t szS = (int32_t)S.length();
	uint32_t _err = SBStrUtils_GetStringOfEx(SB_STD_VECTOR_FRONT_ADR(Bytes), (int32_t)Bytes.size(), (char *)S.data(), &szS, LPos, RPos);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		S.resize(szS);
		SBCheckError(SBGetLastReturnStringA(840842597, 1, (char *)S.data(), &szS));
	}
	else
		SBCheckError(_err);

	S.resize(szS);
}

void GetWideStringOf(const std::vector<uint8_t> &Bytes, sb_u16string &WS)
{
	int32_t szWS = (int32_t)WS.length();
	uint32_t _err = SBStrUtils_GetWideStringOf(SB_STD_VECTOR_FRONT_ADR(Bytes), (int32_t)Bytes.size(), (sb_char16_t *)WS.data(), &szWS);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		WS.resize(szWS);
		SBCheckError(SBGetLastReturnStringW(-2012488584, 1, (sb_char16_t *)WS.data(), &szWS));
	}
	else
		SBCheckError(_err);

	WS.resize(szWS);
}
#ifdef SB_U16STRING_USED
void GetWideStringOf(const std::vector<uint8_t> &Bytes, std::wstring &WS)
{
	std::string u16WS;
	sb_to_u16string(WS, u16WS);
	int32_t szWS = (int32_t)u16WS.length() >> 1;
	uint32_t _err = SBStrUtils_GetWideStringOf(SB_STD_VECTOR_FRONT_ADR(Bytes), (int32_t)Bytes.size(), reinterpret_cast<sb_char16_t*>((char*)u16WS.data()), &szWS);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16WS.resize(szWS << 1);
		SBCheckError(SBGetLastReturnStringW(-2012488584, 1, reinterpret_cast<sb_char16_t*>((char*)u16WS.data()), &szWS));
	}
	else
		SBCheckError(_err);

	u16WS.resize(szWS << 1);
	sb_u16_to_wstring(u16WS, WS);
}
#endif /* SB_U16STRING_USED */

void TrimEx(std::string &S, bool bTrimLeft, bool bTrimRight)
{
	int32_t szS = (int32_t)S.length();
	uint32_t _err = SBStrUtils_TrimEx((char *)S.data(), &szS, (int8_t)bTrimLeft, (int8_t)bTrimRight);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		S.resize(szS);
		SBCheckError(SBGetLastReturnStringA(519703551, 0, (char *)S.data(), &szS));
	}
	else
		SBCheckError(_err);

	S.resize(szS);
}

void TrimSemicolon(sb_u16string &S)
{
	int32_t szS = (int32_t)S.length();
	uint32_t _err = SBStrUtils_TrimSemicolon((sb_char16_t *)S.data(), &szS);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		S.resize(szS);
		SBCheckError(SBGetLastReturnStringW(-916319805, 0, (sb_char16_t *)S.data(), &szS));
	}
	else
		SBCheckError(_err);

	S.resize(szS);
}
#ifdef SB_U16STRING_USED
void TrimSemicolon(std::wstring &S)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	int32_t szS = (int32_t)u16S.length() >> 1;
	uint32_t _err = SBStrUtils_TrimSemicolon(reinterpret_cast<sb_char16_t*>((char*)u16S.data()), &szS);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16S.resize(szS << 1);
		SBCheckError(SBGetLastReturnStringW(-916319805, 0, reinterpret_cast<sb_char16_t*>((char*)u16S.data()), &szS));
	}
	else
		SBCheckError(_err);

	u16S.resize(szS << 1);
	sb_u16_to_wstring(u16S, S);
}
#endif /* SB_U16STRING_USED */

void ExtractWideFileName(const sb_u16string &FileName, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ExtractWideFileName(FileName.data(), (int32_t)FileName.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1355793112, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ExtractWideFileName(const std::wstring &FileName, std::wstring &OutResult)
{
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_ExtractWideFileName(reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1355793112, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void ExtractFileExtension(const sb_u16string &FileName, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ExtractFileExtension(FileName.data(), (int32_t)FileName.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2146827891, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ExtractFileExtension(const std::wstring &FileName, std::string &OutResult)
{
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ExtractFileExtension(reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2146827891, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

void ExtractWideFileExtension(const sb_u16string &FileName, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_ExtractWideFileExtension(FileName.data(), (int32_t)FileName.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(200869886, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ExtractWideFileExtension(const std::wstring &FileName, std::wstring &OutResult)
{
	std::string u16FileName;
	sb_to_u16string(FileName, u16FileName);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_ExtractWideFileExtension(reinterpret_cast<const sb_char16_t*>(u16FileName.data()), (int32_t)u16FileName.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(200869886, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void WideTrimRight(const sb_u16string &S, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBStrUtils_WideTrimRight(S.data(), (int32_t)S.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2005827768, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideTrimRight(const std::wstring &S, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBStrUtils_WideTrimRight(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2005827768, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void DecodeDateTime(int64_t AValue, uint16_t &AYear, uint16_t &AMonth, uint16_t &ADay, uint16_t &AHour, uint16_t &AMinute, uint16_t &ASecond, uint16_t &AMilliSecond)
{
	SBCheckError(SBStrUtils_DecodeDateTime(AValue, &AYear, &AMonth, &ADay, &AHour, &AMinute, &ASecond, &AMilliSecond));
}

SB_INLINE int32_t SBLength(const std::string &Str)
{
	int32_t OutResult;
	SBCheckError(SBStrUtils_SBLength(Str.data(), (int32_t)Str.length(), &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_STRUTILS */

};	/* namespace SecureBlackbox */
