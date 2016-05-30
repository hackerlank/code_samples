#include "sbxmlutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_XMLUTILS

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle ParseElementFromXMLString(const sb_u16string &Data, const TElXMLDOMDocument &Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_ParseElementFromXMLString(Data.data(), (int32_t)Data.length(), Document.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle ParseElementFromXMLString(const sb_u16string &Data, const TElXMLDOMDocument *Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_ParseElementFromXMLString(Data.data(), (int32_t)Data.length(), (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle ParseElementFromXMLString(const std::wstring &Data, const TElXMLDOMDocument &Document)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(SBXMLUtils_ParseElementFromXMLString(reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, Document.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle ParseElementFromXMLString(const std::wstring &Data, const TElXMLDOMDocument *Document)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(SBXMLUtils_ParseElementFromXMLString(reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODELIST
SB_INLINE TElXMLDOMNodeListHandle ParseNodeListFromXMLString(const sb_u16string &Data, const TElXMLDOMDocument &Document)
{
	TElXMLDOMNodeListHandle OutResult;
	SBCheckError(SBXMLUtils_ParseNodeListFromXMLString(Data.data(), (int32_t)Data.length(), Document.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMNodeListHandle ParseNodeListFromXMLString(const sb_u16string &Data, const TElXMLDOMDocument *Document)
{
	TElXMLDOMNodeListHandle OutResult;
	SBCheckError(SBXMLUtils_ParseNodeListFromXMLString(Data.data(), (int32_t)Data.length(), (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeListHandle ParseNodeListFromXMLString(const std::wstring &Data, const TElXMLDOMDocument &Document)
{
	TElXMLDOMNodeListHandle OutResult;
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(SBXMLUtils_ParseNodeListFromXMLString(reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, Document.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMNodeListHandle ParseNodeListFromXMLString(const std::wstring &Data, const TElXMLDOMDocument *Document)
{
	TElXMLDOMNodeListHandle OutResult;
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(SBXMLUtils_ParseNodeListFromXMLString(reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODELIST */

void ConvertToBase64String(const std::vector<uint8_t> &Buf, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_ConvertToBase64String(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1873312742, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertToBase64String(const std::vector<uint8_t> &Buf, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_ConvertToBase64String(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1873312742, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void ConvertFromBase64String(const sb_u16string &S, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLUtils_ConvertFromBase64String(S.data(), (int32_t)S.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1194684313, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertFromBase64String(const std::wstring &S, std::vector<uint8_t> &OutResult)
{
	std::string u16S;
	sb_to_u16string(S, u16S);
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLUtils_ConvertFromBase64String(reinterpret_cast<const sb_char16_t*>(u16S.data()), (int32_t)u16S.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1194684313, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

void ConvertBinaryToBigInt(const std::vector<uint8_t> &Buf, bool AllowNegativeNumbers, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_ConvertBinaryToBigInt(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (int8_t)AllowNegativeNumbers, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-864556250, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertBinaryToBigInt(const std::vector<uint8_t> &Buf, bool AllowNegativeNumbers, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_ConvertBinaryToBigInt(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (int8_t)AllowNegativeNumbers, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-864556250, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void ConvertBigIntToBinary(const sb_u16string &Value, bool AllowHexNumbers, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLUtils_ConvertBigIntToBinary(Value.data(), (int32_t)Value.length(), (int8_t)AllowHexNumbers, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(556697992, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertBigIntToBinary(const std::wstring &Value, bool AllowHexNumbers, std::vector<uint8_t> &OutResult)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLUtils_ConvertBigIntToBinary(reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (int8_t)AllowHexNumbers, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(556697992, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

void ConvertHexToBinary(const sb_u16string &Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLUtils_ConvertHexToBinary(Value.data(), (int32_t)Value.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(377863171, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertHexToBinary(const std::wstring &Value, std::vector<uint8_t> &OutResult)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBXMLUtils_ConvertHexToBinary(reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(377863171, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void AddTextToXMLElement(const sb_u16string &Text, const TElXMLDOMElement &Element)
{
	SBCheckError(SBXMLUtils_AddTextToXMLElement(Text.data(), (int32_t)Text.length(), Element.getHandle()));
}
SB_INLINE void AddTextToXMLElement(const sb_u16string &Text, const TElXMLDOMElement *Element)
{
	SBCheckError(SBXMLUtils_AddTextToXMLElement(Text.data(), (int32_t)Text.length(), (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void AddTextToXMLElement(const std::wstring &Text, const TElXMLDOMElement &Element)
{
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(SBXMLUtils_AddTextToXMLElement(reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, Element.getHandle()));
}
SB_INLINE void AddTextToXMLElement(const std::wstring &Text, const TElXMLDOMElement *Element)
{
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(SBXMLUtils_AddTextToXMLElement(reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
SB_INLINE void InsertTextBeforeXMLElement(const sb_u16string &Text, TElXMLDOMElement &Element, TElXMLDOMNode &Ref)
{
	SBCheckError(SBXMLUtils_InsertTextBeforeXMLElement(Text.data(), (int32_t)Text.length(), Element.getHandle(), Ref.getHandle()));
}
SB_INLINE void InsertTextBeforeXMLElement(const sb_u16string &Text, TElXMLDOMElement *Element, TElXMLDOMNode *Ref)
{
	SBCheckError(SBXMLUtils_InsertTextBeforeXMLElement(Text.data(), (int32_t)Text.length(), (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (Ref != NULL) ? Ref->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void InsertTextBeforeXMLElement(const std::wstring &Text, TElXMLDOMElement &Element, TElXMLDOMNode &Ref)
{
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(SBXMLUtils_InsertTextBeforeXMLElement(reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, Element.getHandle(), Ref.getHandle()));
}
SB_INLINE void InsertTextBeforeXMLElement(const std::wstring &Text, TElXMLDOMElement *Element, TElXMLDOMNode *Ref)
{
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(SBXMLUtils_InsertTextBeforeXMLElement(reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (Ref != NULL) ? Ref->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void GetTextFromXMLElement(const TElXMLDOMElement &Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_GetTextFromXMLElement(Element.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-64638431, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetTextFromXMLElement(const TElXMLDOMElement *Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_GetTextFromXMLElement((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-64638431, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetTextFromXMLElement(const TElXMLDOMElement &Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_GetTextFromXMLElement(Element.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-64638431, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void GetTextFromXMLElement(const TElXMLDOMElement *Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_GetTextFromXMLElement((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-64638431, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void GetStrictTextFromXMLElement(const TElXMLDOMElement &Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_GetStrictTextFromXMLElement(Element.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1322068759, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetStrictTextFromXMLElement(const TElXMLDOMElement *Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_GetStrictTextFromXMLElement((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1322068759, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetStrictTextFromXMLElement(const TElXMLDOMElement &Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_GetStrictTextFromXMLElement(Element.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1322068759, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void GetStrictTextFromXMLElement(const TElXMLDOMElement *Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_GetStrictTextFromXMLElement((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1322068759, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindChildElementByLocalName(const TElXMLDOMElement &Element, const sb_u16string &LocalName)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindChildElementByLocalName(Element.getHandle(), LocalName.data(), (int32_t)LocalName.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElementByLocalName(const TElXMLDOMElement *Element, const sb_u16string &LocalName)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindChildElementByLocalName((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, LocalName.data(), (int32_t)LocalName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindChildElementByLocalName(const TElXMLDOMElement &Element, const std::wstring &LocalName)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16LocalName;
	sb_to_u16string(LocalName, u16LocalName);
	SBCheckError(SBXMLUtils_FindChildElementByLocalName(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16LocalName.data()), (int32_t)u16LocalName.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElementByLocalName(const TElXMLDOMElement *Element, const std::wstring &LocalName)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16LocalName;
	sb_to_u16string(LocalName, u16LocalName);
	SBCheckError(SBXMLUtils_FindChildElementByLocalName((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16LocalName.data()), (int32_t)u16LocalName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement &Element, const sb_u16string &Name, const sb_u16string &NamespaceURI, const sb_u16string &DefaultPrefix)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindChildElement(Element.getHandle(), Name.data(), (int32_t)Name.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), DefaultPrefix.data(), (int32_t)DefaultPrefix.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement *Element, const sb_u16string &Name, const sb_u16string &NamespaceURI, const sb_u16string &DefaultPrefix)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindChildElement((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), DefaultPrefix.data(), (int32_t)DefaultPrefix.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement &Element, const std::wstring &Name, const std::wstring &NamespaceURI, const std::wstring &DefaultPrefix)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	std::string u16DefaultPrefix;
	sb_to_u16string(DefaultPrefix, u16DefaultPrefix);
	SBCheckError(SBXMLUtils_FindChildElement(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16DefaultPrefix.data()), (int32_t)u16DefaultPrefix.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement *Element, const std::wstring &Name, const std::wstring &NamespaceURI, const std::wstring &DefaultPrefix)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	std::string u16DefaultPrefix;
	sb_to_u16string(DefaultPrefix, u16DefaultPrefix);
	SBCheckError(SBXMLUtils_FindChildElement((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16DefaultPrefix.data()), (int32_t)u16DefaultPrefix.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement &RootElement, const sb_u16string &ID)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindElementById(RootElement.getHandle(), ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement *RootElement, const sb_u16string &ID)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindElementById((RootElement != NULL) ? RootElement->getHandle() : SB_NULL_HANDLE, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement &RootElement, const std::wstring &ID)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16ID;
	sb_to_u16string(ID, u16ID);
	SBCheckError(SBXMLUtils_FindElementById(RootElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16ID.data()), (int32_t)u16ID.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement *RootElement, const std::wstring &ID)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16ID;
	sb_to_u16string(ID, u16ID);
	SBCheckError(SBXMLUtils_FindElementById((RootElement != NULL) ? RootElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16ID.data()), (int32_t)u16ID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement &RootElement, const sb_u16string &ID, const sb_u16string &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindElementById_1(RootElement.getHandle(), ID.data(), (int32_t)ID.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement *RootElement, const sb_u16string &ID, const sb_u16string &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindElementById_1((RootElement != NULL) ? RootElement->getHandle() : SB_NULL_HANDLE, ID.data(), (int32_t)ID.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement &RootElement, const std::wstring &ID, const std::wstring &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16ID;
	sb_to_u16string(ID, u16ID);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLUtils_FindElementById_1(RootElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16ID.data()), (int32_t)u16ID.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement *RootElement, const std::wstring &ID, const std::wstring &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16ID;
	sb_to_u16string(ID, u16ID);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLUtils_FindElementById_1((RootElement != NULL) ? RootElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16ID.data()), (int32_t)u16ID.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle FindElementByName(const TElXMLDOMElement &RootElement, const sb_u16string &Name, const sb_u16string &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindElementByName(RootElement.getHandle(), Name.data(), (int32_t)Name.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindElementByName(const TElXMLDOMElement *RootElement, const sb_u16string &Name, const sb_u16string &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(SBXMLUtils_FindElementByName((RootElement != NULL) ? RootElement->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle FindElementByName(const TElXMLDOMElement &RootElement, const std::wstring &Name, const std::wstring &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLUtils_FindElementByName(RootElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
SB_INLINE TElXMLDOMElementHandle FindElementByName(const TElXMLDOMElement *RootElement, const std::wstring &Name, const std::wstring &NamespaceURI)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLUtils_FindElementByName((RootElement != NULL) ? RootElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void ExtractIdFromLocalURI(const sb_u16string &URI, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_ExtractIdFromLocalURI(URI.data(), (int32_t)URI.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-535855577, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ExtractIdFromLocalURI(const std::wstring &URI, std::wstring &OutResult)
{
	std::string u16URI;
	sb_to_u16string(URI, u16URI);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_ExtractIdFromLocalURI(reinterpret_cast<const sb_char16_t*>(u16URI.data()), (int32_t)u16URI.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-535855577, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool SBXMLUtils_ExtractIdFromLocalURI(const sb_u16string &URI, sb_u16string &Id)
{
	int32_t szId = (int32_t)Id.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBXMLUtils_ExtractIdFromLocalURI_1(URI.data(), (int32_t)URI.length(), (sb_char16_t *)Id.data(), &szId, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Id.resize(szId);
		SBCheckError(SBGetLastReturnStringW(-343439292, 1, (sb_char16_t *)Id.data(), &szId));
	}
	else
		SBCheckError(_err);

	Id.resize(szId);
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool SBXMLUtils_ExtractIdFromLocalURI(const std::wstring &URI, std::wstring &Id)
{
	std::string u16URI;
	sb_to_u16string(URI, u16URI);
	std::string u16Id;
	int32_t szId = 0;
	int8_t OutResultRaw = 0;
	uint32_t _err = SBXMLUtils_ExtractIdFromLocalURI_1(reinterpret_cast<const sb_char16_t*>(u16URI.data()), (int32_t)u16URI.length() >> 1, NULL, &szId, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16Id.resize(szId << 1);
		SBCheckError(SBGetLastReturnStringW(-343439292, 1, reinterpret_cast<sb_char16_t*>((char*)u16Id.data()), &szId));
	}
	else
		SBCheckError(_err);

	u16Id.resize(szId << 1);
	sb_u16_to_wstring(u16Id, Id);
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void GetElementId(TElXMLDOMElement &Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_GetElementId(Element.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-673475204, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetElementId(TElXMLDOMElement *Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_GetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-673475204, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetElementId(TElXMLDOMElement &Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_GetElementId(Element.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-673475204, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void GetElementId(TElXMLDOMElement *Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_GetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-673475204, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void SetElementId(TElXMLDOMElement &Element, const sb_u16string &Value)
{
	SBCheckError(SBXMLUtils_SetElementId(Element.getHandle(), Value.data(), (int32_t)Value.length()));
}
SB_INLINE void SetElementId(TElXMLDOMElement *Element, const sb_u16string &Value)
{
	SBCheckError(SBXMLUtils_SetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Value.data(), (int32_t)Value.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void SetElementId(TElXMLDOMElement &Element, const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(SBXMLUtils_SetElementId(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}
SB_INLINE void SetElementId(TElXMLDOMElement *Element, const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(SBXMLUtils_SetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void CanonicalizationMethodToURI(TElXMLCanonicalizationMethod ACanonicalizationMethod, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_CanonicalizationMethodToURI((TElXMLCanonicalizationMethodRaw)ACanonicalizationMethod, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2117021519, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void CanonicalizationMethodToURI(TElXMLCanonicalizationMethod ACanonicalizationMethod, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_CanonicalizationMethodToURI((TElXMLCanonicalizationMethodRaw)ACanonicalizationMethod, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2117021519, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

TElXMLCanonicalizationMethod URIToCanonicalizationMethod(const sb_u16string &AURI)
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(SBXMLUtils_URIToCanonicalizationMethod(AURI.data(), (int32_t)AURI.length(), &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}
#ifdef SB_U16STRING_USED
TElXMLCanonicalizationMethod URIToCanonicalizationMethod(const std::wstring &AURI)
{
	std::string u16AURI;
	sb_to_u16string(AURI, u16AURI);
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(SBXMLUtils_URIToCanonicalizationMethod(reinterpret_cast<const sb_char16_t*>(u16AURI.data()), (int32_t)u16AURI.length() >> 1, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void AddPrefixes(TElXMLDOMElement &Element, const sb_u16string &Prefixes, const sb_u16string &NamespaceURI)
{
	SBCheckError(SBXMLUtils_AddPrefixes(Element.getHandle(), Prefixes.data(), (int32_t)Prefixes.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length()));
}
SB_INLINE void AddPrefixes(TElXMLDOMElement *Element, const sb_u16string &Prefixes, const sb_u16string &NamespaceURI)
{
	SBCheckError(SBXMLUtils_AddPrefixes((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Prefixes.data(), (int32_t)Prefixes.length(), NamespaceURI.data(), (int32_t)NamespaceURI.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void AddPrefixes(TElXMLDOMElement &Element, const std::wstring &Prefixes, const std::wstring &NamespaceURI)
{
	std::string u16Prefixes;
	sb_to_u16string(Prefixes, u16Prefixes);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLUtils_AddPrefixes(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Prefixes.data()), (int32_t)u16Prefixes.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1));
}
SB_INLINE void AddPrefixes(TElXMLDOMElement *Element, const std::wstring &Prefixes, const std::wstring &NamespaceURI)
{
	std::string u16Prefixes;
	sb_to_u16string(Prefixes, u16Prefixes);
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	SBCheckError(SBXMLUtils_AddPrefixes((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Prefixes.data()), (int32_t)u16Prefixes.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void DateTimeToXMLString(int64_t Value, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_DateTimeToXMLString(Value, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2048501415, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void DateTimeToXMLString(int64_t Value, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_DateTimeToXMLString(Value, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2048501415, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void DateTimeToXMLString(int64_t Value, TSBXMLDateTimeFormat Format, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_DateTimeToXMLString_1(Value, (TSBXMLDateTimeFormatRaw)Format, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-189295739, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void DateTimeToXMLString(int64_t Value, TSBXMLDateTimeFormat Format, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_DateTimeToXMLString_1(Value, (TSBXMLDateTimeFormatRaw)Format, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-189295739, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void DateTimeToXMLString(int64_t Value, TSBXMLDateTimeFormat Format, int32_t TimeZoneOffset, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_DateTimeToXMLString_2(Value, (TSBXMLDateTimeFormatRaw)Format, TimeZoneOffset, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-98225005, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void DateTimeToXMLString(int64_t Value, TSBXMLDateTimeFormat Format, int32_t TimeZoneOffset, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLUtils_DateTimeToXMLString_2(Value, (TSBXMLDateTimeFormatRaw)Format, TimeZoneOffset, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-98225005, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE int64_t XMLStringToDateTime(const sb_u16string &Value)
{
	int64_t OutResult;
	SBCheckError(SBXMLUtils_XMLStringToDateTime(Value.data(), (int32_t)Value.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int64_t XMLStringToDateTime(const std::wstring &Value)
{
	int64_t OutResult;
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(SBXMLUtils_XMLStringToDateTime(reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

void DateTimeFormatToString(TSBXMLDateTimeFormat Format, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLUtils_DateTimeFormatToString((TSBXMLDateTimeFormatRaw)Format, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1097333036, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_XMLUTILS */

};	/* namespace SecureBlackbox */

