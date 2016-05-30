#include "sbchsunicode.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_CHSUNICODE

SB_INLINE void WideUpperCase(sb_char16_t &C)
{
	SBCheckError(SBChSUnicode_WideUpperCase(&C));
}

void WideUpperCase(const sb_u16string &S, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_WideUpperCase_1(S.data(), (int32_t)S.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1090267963, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideUpperCase(const std::wstring &S, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_WideUpperCase_1(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1090267963, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void WideTitleCase(sb_char16_t &C)
{
	SBCheckError(SBChSUnicode_WideTitleCase(&C));
}

void WideTitleCase(const sb_u16string &S, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_WideTitleCase_1(S.data(), (int32_t)S.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-315320298, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideTitleCase(const std::wstring &S, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_WideTitleCase_1(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-315320298, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

TPlCharType GetCharType(sb_char16_t C)
{
	TPlCharTypeRaw OutResultRaw = 0;
	SBCheckError(SBChSUnicode_GetCharType(C, &OutResultRaw));
	return (TPlCharType)OutResultRaw;
}

SB_INLINE void WideLowerCase(sb_char16_t &C)
{
	SBCheckError(SBChSUnicode_WideLowerCase(&C));
}

void WideLowerCase(const sb_u16string &S, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_WideLowerCase_1(S.data(), (int32_t)S.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-662402316, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideLowerCase(const std::wstring &S, std::wstring &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_WideLowerCase_1(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-662402316, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void Normalize_NFD(const sb_u16string &AString, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_Normalize_NFD(AString.data(), (int32_t)AString.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1802691262, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void Normalize_NFD(const std::wstring &AString, std::wstring &OutResult)
{
	std::string u16AString;
	sb_to_u16string(AString, u16AString);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_Normalize_NFD(reinterpret_cast<const sb_char16_t*>(u16AString.data()), (int32_t)u16AString.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1802691262, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void Normalize_NFC(const sb_u16string &AString, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_Normalize_NFC(AString.data(), (int32_t)AString.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-499874324, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void Normalize_NFC(const std::wstring &AString, std::wstring &OutResult)
{
	std::string u16AString;
	sb_to_u16string(AString, u16AString);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_Normalize_NFC(reinterpret_cast<const sb_char16_t*>(u16AString.data()), (int32_t)u16AString.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-499874324, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void Normalize_NFKD(const sb_u16string &AString, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_Normalize_NFKD(AString.data(), (int32_t)AString.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(193978565, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void Normalize_NFKD(const std::wstring &AString, std::wstring &OutResult)
{
	std::string u16AString;
	sb_to_u16string(AString, u16AString);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_Normalize_NFKD(reinterpret_cast<const sb_char16_t*>(u16AString.data()), (int32_t)u16AString.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(193978565, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void Normalize_NFKC(const sb_u16string &AString, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_Normalize_NFKC(AString.data(), (int32_t)AString.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2100721771, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void Normalize_NFKC(const std::wstring &AString, std::wstring &OutResult)
{
	std::string u16AString;
	sb_to_u16string(AString, u16AString);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_Normalize_NFKC(reinterpret_cast<const sb_char16_t*>(u16AString.data()), (int32_t)u16AString.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2100721771, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void CheckProhibit(const sb_u16string &str, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_CheckProhibit(str.data(), (int32_t)str.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(415522769, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void CheckProhibit(const std::wstring &str, std::wstring &OutResult)
{
	std::string u16str;
	sb_to_u16string(str, u16str);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_CheckProhibit(reinterpret_cast<const sb_char16_t*>(u16str.data()), (int32_t)u16str.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(415522769, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void CheckBidi(const sb_u16string &str, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_CheckBidi(str.data(), (int32_t)str.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(499945083, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void CheckBidi(const std::wstring &str, std::wstring &OutResult)
{
	std::string u16str;
	sb_to_u16string(str, u16str);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_CheckBidi(reinterpret_cast<const sb_char16_t*>(u16str.data()), (int32_t)u16str.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(499945083, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t GetCharCode(const sb_u16string &InCh)
{
	int32_t OutResult;
	SBCheckError(SBChSUnicode_GetCharCode(InCh.data(), (int32_t)InCh.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t GetCharCode(const std::wstring &InCh)
{
	int32_t OutResult;
	std::string u16InCh;
	sb_to_u16string(InCh, u16InCh);
	SBCheckError(SBChSUnicode_GetCharCode(reinterpret_cast<const sb_char16_t*>(u16InCh.data()), (int32_t)u16InCh.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

void GetCharValue(uint32_t Code, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBChSUnicode_GetCharValue(Code, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(676923482, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetCharValue(uint32_t Code, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBChSUnicode_GetCharValue(Code, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(676923482, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_CHSUNICODE */

};	/* namespace SecureBlackbox */

