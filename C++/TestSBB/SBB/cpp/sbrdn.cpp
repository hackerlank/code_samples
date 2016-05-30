#include "sbrdn.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME

SB_INLINE void TElRelativeDistinguishedName::Assign(TPersistent &Source)
{
	SBCheckError(TElRelativeDistinguishedName_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElRelativeDistinguishedName::Assign(TPersistent *Source)
{
	SBCheckError(TElRelativeDistinguishedName_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
bool TElRelativeDistinguishedName::LoadFromTag(TElASN1ConstrainedTag &Tag, bool IgnoreTopSequence)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRelativeDistinguishedName_LoadFromTag(_Handle, Tag.getHandle(), (int8_t)IgnoreTopSequence, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRelativeDistinguishedName::LoadFromTag(TElASN1ConstrainedTag *Tag, bool IgnoreTopSequence)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRelativeDistinguishedName_LoadFromTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (int8_t)IgnoreTopSequence, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

bool TElRelativeDistinguishedName::LoadFromDNString(const std::string &S, bool LiberalMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRelativeDistinguishedName_LoadFromDNString(_Handle, S.data(), (int32_t)S.length(), (int8_t)LiberalMode, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
bool TElRelativeDistinguishedName::SaveToTag(TElASN1ConstrainedTag &Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRelativeDistinguishedName_SaveToTag(_Handle, Tag.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRelativeDistinguishedName::SaveToTag(TElASN1ConstrainedTag *Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRelativeDistinguishedName_SaveToTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

void TElRelativeDistinguishedName::SaveToDNString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRelativeDistinguishedName_SaveToDNString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1835934418, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElRelativeDistinguishedName::Add(const std::vector<uint8_t> &OID, const std::vector<uint8_t> &Value, uint8_t Tag)
{
	int32_t OutResult;
	SBCheckError(TElRelativeDistinguishedName_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), Tag, &OutResult));
	return OutResult;
}

SB_INLINE void TElRelativeDistinguishedName::Remove(int32_t Index)
{
	SBCheckError(TElRelativeDistinguishedName_Remove(_Handle, Index));
}

SB_INLINE int32_t TElRelativeDistinguishedName::IndexOf(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(TElRelativeDistinguishedName_IndexOf(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElRelativeDistinguishedName::Clear()
{
	SBCheckError(TElRelativeDistinguishedName_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
SB_INLINE void TElRelativeDistinguishedName::GetValuesByOID(const std::vector<uint8_t> &OID, TElByteArrayList &Values)
{
	SBCheckError(TElRelativeDistinguishedName_GetValuesByOID(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Values.getHandle()));
}

SB_INLINE void TElRelativeDistinguishedName::GetValuesByOID(const std::vector<uint8_t> &OID, TElByteArrayList *Values)
{
	SBCheckError(TElRelativeDistinguishedName_GetValuesByOID(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Values != NULL) ? Values->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

void TElRelativeDistinguishedName::GetFirstValueByOID(const std::vector<uint8_t> &OID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRelativeDistinguishedName_GetFirstValueByOID(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(287711376, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRelativeDistinguishedName::GetStringValuesByOID(const std::vector<uint8_t> &OID, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRelativeDistinguishedName_GetStringValuesByOID(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-803822683, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRelativeDistinguishedName::GetStringValuesByOID(const std::vector<uint8_t> &OID, const std::string &ValueSeparator, bool EncodeSpecialChars, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRelativeDistinguishedName_GetStringValuesByOID_1(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), ValueSeparator.data(), (int32_t)ValueSeparator.length(), (int8_t)EncodeSpecialChars, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1259119586, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRelativeDistinguishedName::GetFirstStringValueByOID(const std::vector<uint8_t> &OID, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRelativeDistinguishedName_GetFirstStringValueByOID(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1801065931, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRelativeDistinguishedName::GetFirstStringValueByOID(const std::vector<uint8_t> &OID, bool EncodeSpecialChars, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRelativeDistinguishedName_GetFirstStringValueByOID_1(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (int8_t)EncodeSpecialChars, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1813611091, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElRelativeDistinguishedName::Contains(TElRelativeDistinguishedName &RDN, bool IgnoreTags)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRelativeDistinguishedName_Contains(_Handle, RDN.getHandle(), (int8_t)IgnoreTags, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElRelativeDistinguishedName::Contains(TElRelativeDistinguishedName *RDN, bool IgnoreTags)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRelativeDistinguishedName_Contains(_Handle, (RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, (int8_t)IgnoreTags, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElRelativeDistinguishedName::get_Values(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRelativeDistinguishedName_get_Values(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1387381064, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRelativeDistinguishedName::set_Values(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRelativeDistinguishedName_set_Values(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElRelativeDistinguishedName::get_NormValues(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRelativeDistinguishedName_get_NormValues(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-936642720, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElRelativeDistinguishedName::get_NormValues(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElRelativeDistinguishedName_get_NormValues(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-936642720, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElRelativeDistinguishedName::set_NormValues(int32_t Index, const sb_u16string &Value)
{
	SBCheckError(TElRelativeDistinguishedName_set_NormValues(_Handle, Index, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElRelativeDistinguishedName::set_NormValues(int32_t Index, const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElRelativeDistinguishedName_set_NormValues(_Handle, Index, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElRelativeDistinguishedName::get_OIDs(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRelativeDistinguishedName_get_OIDs(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(607574137, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRelativeDistinguishedName::set_OIDs(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRelativeDistinguishedName_set_OIDs(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint8_t TElRelativeDistinguishedName::get_Tags(int32_t Index)
{
	uint8_t OutResult;
	SBCheckError(TElRelativeDistinguishedName_get_Tags(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElRelativeDistinguishedName::set_Tags(int32_t Index, uint8_t Value)
{
	SBCheckError(TElRelativeDistinguishedName_set_Tags(_Handle, Index, Value));
}

SB_INLINE int32_t TElRelativeDistinguishedName::get_Groups(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElRelativeDistinguishedName_get_Groups(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElRelativeDistinguishedName::set_Groups(int32_t Index, int32_t Value)
{
	SBCheckError(TElRelativeDistinguishedName_set_Groups(_Handle, Index, Value));
}

SB_INLINE int32_t TElRelativeDistinguishedName::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElRelativeDistinguishedName_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRelativeDistinguishedName::set_Count(int32_t Value)
{
	SBCheckError(TElRelativeDistinguishedName_set_Count(_Handle, Value));
}

TElRelativeDistinguishedName::TElRelativeDistinguishedName(TElRelativeDistinguishedNameHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElRelativeDistinguishedName::TElRelativeDistinguishedName() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRelativeDistinguishedName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRDNCONVERTER

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void TElRDNConverter::SaveToDNString(TElRelativeDistinguishedName &RDN, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRDNConverter_SaveToDNString(_Handle, RDN.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1737738368, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRDNConverter::SaveToDNString(TElRelativeDistinguishedName *RDN, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRDNConverter_SaveToDNString(_Handle, (RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1737738368, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE void TElRDNConverter::LoadFromDNString(TElRelativeDistinguishedName &RDN, const std::string &S, bool LiberalMode)
{
	SBCheckError(TElRDNConverter_LoadFromDNString(_Handle, RDN.getHandle(), S.data(), (int32_t)S.length(), (int8_t)LiberalMode));
}

SB_INLINE void TElRDNConverter::LoadFromDNString(TElRelativeDistinguishedName *RDN, const std::string &S, bool LiberalMode)
{
	SBCheckError(TElRDNConverter_LoadFromDNString(_Handle, (RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, S.data(), (int32_t)S.length(), (int8_t)LiberalMode));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElRDNConverter::get_Separator(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRDNConverter_get_Separator(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-637289994, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRDNConverter::set_Separator(const std::string &Value)
{
	SBCheckError(TElRDNConverter_set_Separator(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElRDNConverter::get_InsertSeparatorPrefix()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRDNConverter_get_InsertSeparatorPrefix(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRDNConverter::set_InsertSeparatorPrefix(bool Value)
{
	SBCheckError(TElRDNConverter_set_InsertSeparatorPrefix(_Handle, (int8_t)Value));
}

TElRDNConverter::TElRDNConverter(TElRDNConverterHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElRDNConverter::TElRDNConverter() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRDNConverter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRDNCONVERTER */

#ifdef SB_USE_GLOBAL_PROCS_RDN

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void FormatRDN(TElRelativeDistinguishedName &RDN, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_FormatRDN(RDN.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1619204522, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void FormatRDN(TElRelativeDistinguishedName *RDN, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_FormatRDN((RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1619204522, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void MapUnicodeString(const sb_u16string &str, bool CaseIgnore, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_MapUnicodeString(str.data(), (int32_t)str.length(), (int8_t)CaseIgnore, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1789814043, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void MapUnicodeString(const std::wstring &str, bool CaseIgnore, std::wstring &OutResult)
{
	std::string u16str;
	sb_to_u16string(str, u16str);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBRDN_MapUnicodeString(reinterpret_cast<const sb_char16_t*>(u16str.data()), (int32_t)u16str.length() >> 1, (int8_t)CaseIgnore, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1789814043, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void InsignificantSpaceHandling(const sb_u16string &str, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_InsignificantSpaceHandling(str.data(), (int32_t)str.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1413898460, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void InsignificantSpaceHandling(const std::wstring &str, std::wstring &OutResult)
{
	std::string u16str;
	sb_to_u16string(str, u16str);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBRDN_InsignificantSpaceHandling(reinterpret_cast<const sb_char16_t*>(u16str.data()), (int32_t)u16str.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1413898460, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void GetRDNStringValue(const TElRelativeDistinguishedName &RDN, int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_GetRDNStringValue(RDN.getHandle(), Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1651981216, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetRDNStringValue(const TElRelativeDistinguishedName *RDN, int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_GetRDNStringValue((RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1651981216, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetRDNStringValue(const TElRelativeDistinguishedName &RDN, int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBRDN_GetRDNStringValue(RDN.getHandle(), Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1651981216, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void GetRDNStringValue(const TElRelativeDistinguishedName *RDN, int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBRDN_GetRDNStringValue((RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1651981216, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void GetNormalizedRDNStringValue(const TElRelativeDistinguishedName &RDN, int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_GetNormalizedRDNStringValue(RDN.getHandle(), Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1033659806, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetNormalizedRDNStringValue(const TElRelativeDistinguishedName *RDN, int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_GetNormalizedRDNStringValue((RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1033659806, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetNormalizedRDNStringValue(const TElRelativeDistinguishedName &RDN, int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBRDN_GetNormalizedRDNStringValue(RDN.getHandle(), Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1033659806, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void GetNormalizedRDNStringValue(const TElRelativeDistinguishedName *RDN, int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBRDN_GetNormalizedRDNStringValue((RDN != NULL) ? RDN->getHandle() : SB_NULL_HANDLE, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1033659806, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void GetNormalizedRDNString(const sb_u16string &Value, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBRDN_GetNormalizedRDNString(Value.data(), (int32_t)Value.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-987387093, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetNormalizedRDNString(const std::wstring &Value, std::wstring &OutResult)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBRDN_GetNormalizedRDNString(reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-987387093, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool CompareRDN(TElRelativeDistinguishedName &Name1, TElRelativeDistinguishedName &Name2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_CompareRDN(Name1.getHandle(), Name2.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool CompareRDN(TElRelativeDistinguishedName *Name1, TElRelativeDistinguishedName *Name2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_CompareRDN((Name1 != NULL) ? Name1->getHandle() : SB_NULL_HANDLE, (Name2 != NULL) ? Name2->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool CompareRDNAsStrings(TElRelativeDistinguishedName &Name1, TElRelativeDistinguishedName &Name2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_CompareRDNAsStrings(Name1.getHandle(), Name2.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool CompareRDNAsStrings(TElRelativeDistinguishedName *Name1, TElRelativeDistinguishedName *Name2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_CompareRDNAsStrings((Name1 != NULL) ? Name1->getHandle() : SB_NULL_HANDLE, (Name2 != NULL) ? Name2->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool NonstrictCompareRDN(TElRelativeDistinguishedName &InnerRDN, TElRelativeDistinguishedName &OuterRDN)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_NonstrictCompareRDN(InnerRDN.getHandle(), OuterRDN.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool NonstrictCompareRDN(TElRelativeDistinguishedName *InnerRDN, TElRelativeDistinguishedName *OuterRDN)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_NonstrictCompareRDN((InnerRDN != NULL) ? InnerRDN->getHandle() : SB_NULL_HANDLE, (OuterRDN != NULL) ? OuterRDN->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool NonstrictCompareRDNAsStrings(TElRelativeDistinguishedName &InnerRDN, TElRelativeDistinguishedName &OuterRDN)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_NonstrictCompareRDNAsStrings(InnerRDN.getHandle(), OuterRDN.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool NonstrictCompareRDNAsStrings(TElRelativeDistinguishedName *InnerRDN, TElRelativeDistinguishedName *OuterRDN)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_NonstrictCompareRDNAsStrings((InnerRDN != NULL) ? InnerRDN->getHandle() : SB_NULL_HANDLE, (OuterRDN != NULL) ? OuterRDN->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

bool GetIgnoreTagsWhenComparingRDNs()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRDN_GetIgnoreTagsWhenComparingRDNs(&OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void SetIgnoreTagsWhenComparingRDNs(bool Value)
{
	SBCheckError(SBRDN_SetIgnoreTagsWhenComparingRDNs((int8_t)Value));
}

#endif /* SB_USE_GLOBAL_PROCS_RDN */

};	/* namespace SecureBlackbox */

