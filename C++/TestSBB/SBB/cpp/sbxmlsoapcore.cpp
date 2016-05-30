#include "sbxmlsoapcore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLSOAPELEMENT

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSOAPElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSOAPElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBXMLSOAPVersion TElXMLSOAPElement::get_SOAPVersion()
{
	TSBXMLSOAPVersionRaw OutResultRaw = 0;
	SBCheckError(TElXMLSOAPElement_get_SOAPVersion(_Handle, &OutResultRaw));
	return (TSBXMLSOAPVersion)OutResultRaw;
}

void TElXMLSOAPElement::get_NamespaceURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPElement_get_NamespaceURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1050227845, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPElement::get_NamespaceURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPElement_get_NamespaceURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1050227845, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPElement::TElXMLSOAPElement(TElXMLSOAPElementHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLSOAPElement::TElXMLSOAPElement(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPElement_Create((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPElement::TElXMLSOAPElement(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPElement_Create((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPElement::TElXMLSOAPElement(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPElement_Create_1((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPElement::TElXMLSOAPElement(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPElement_Create_1((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPElement::TElXMLSOAPElement(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPElement_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

TElXMLSOAPElement::TElXMLSOAPElement(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPElement_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPElement::TElXMLSOAPElement(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPElement_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

TElXMLSOAPElement::TElXMLSOAPElement(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPElement_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPElement::TElXMLSOAPElement(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPElement_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLSOAPElement::TElXMLSOAPElement(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPElement_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPElement::TElXMLSOAPElement(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPElement_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLSOAPElement::TElXMLSOAPElement(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPElement_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLSOAPELEMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPHeaderBlock::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPHeaderBlock_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPHeaderBlock::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPHeaderBlock_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSOAPHeaderBlock::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPHeaderBlock_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSOAPHeaderBlock::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPHeaderBlock_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSOAPHeaderBlock::get_Actor(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPHeaderBlock_get_Actor(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1855824044, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPHeaderBlock::get_Actor(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPHeaderBlock_get_Actor(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1855824044, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPHeaderBlock::set_Actor(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPHeaderBlock_set_Actor(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPHeaderBlock::set_Actor(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPHeaderBlock_set_Actor(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPHeaderBlock::get_EncodingStyle(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPHeaderBlock_get_EncodingStyle(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1641507103, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPHeaderBlock::get_EncodingStyle(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPHeaderBlock_get_EncodingStyle(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1641507103, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPHeaderBlock::set_EncodingStyle(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPHeaderBlock_set_EncodingStyle(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPHeaderBlock::set_EncodingStyle(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPHeaderBlock_set_EncodingStyle(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPHeaderBlock::get_Role(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPHeaderBlock_get_Role(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(793490286, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPHeaderBlock::get_Role(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPHeaderBlock_get_Role(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(793490286, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPHeaderBlock::set_Role(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPHeaderBlock_set_Role(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPHeaderBlock::set_Role(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPHeaderBlock_set_Role(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPHeaderBlock::get_MustUnderstand(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPHeaderBlock_get_MustUnderstand(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-24254483, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPHeaderBlock::get_MustUnderstand(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPHeaderBlock_get_MustUnderstand(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-24254483, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPHeaderBlock::set_MustUnderstand(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPHeaderBlock_set_MustUnderstand(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPHeaderBlock::set_MustUnderstand(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPHeaderBlock_set_MustUnderstand(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPHeaderBlock::get_Relay(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPHeaderBlock_get_Relay(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2010256620, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPHeaderBlock::get_Relay(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPHeaderBlock_get_Relay(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2010256620, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPHeaderBlock::set_Relay(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPHeaderBlock_set_Relay(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPHeaderBlock::set_Relay(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPHeaderBlock_set_Relay(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPHeaderBlock::get_SOAPNamespaceURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPHeaderBlock_get_SOAPNamespaceURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(840381326, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPHeaderBlock::get_SOAPNamespaceURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPHeaderBlock_get_SOAPNamespaceURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(840381326, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPHeaderBlock::TElXMLSOAPHeaderBlock(TElXMLSOAPHeaderBlockHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLSOAPHeaderBlock::TElXMLSOAPHeaderBlock(const sb_u16string &ASOAPNamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPHeaderBlock_Create(ASOAPNamespaceURI.data(), (int32_t)ASOAPNamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPHeaderBlock::TElXMLSOAPHeaderBlock(const std::wstring &ASOAPNamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ASOAPNamespaceURI;
	sb_to_u16string(ASOAPNamespaceURI, u16ASOAPNamespaceURI);
	SBCheckError(TElXMLSOAPHeaderBlock_Create(reinterpret_cast<const sb_char16_t*>(u16ASOAPNamespaceURI.data()), (int32_t)u16ASOAPNamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADER

SB_INLINE void TElXMLSOAPHeader::Clear()
{
	SBCheckError(TElXMLSOAPHeader_Clear(_Handle));
}

SB_INLINE void TElXMLSOAPHeader::ReloadBlocks()
{
	SBCheckError(TElXMLSOAPHeader_ReloadBlocks(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPHeader::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPHeader_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPHeader::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPHeader_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPHEADERBLOCK
SB_INLINE TElXMLSOAPHeaderBlockHandle TElXMLSOAPHeader::LoadBlockFromXML(TElXMLDOMElement &Element)
{
	TElXMLSOAPHeaderBlockHandle OutResult;
	SBCheckError(TElXMLSOAPHeader_LoadBlockFromXML(_Handle, Element.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLSOAPHeaderBlockHandle TElXMLSOAPHeader::LoadBlockFromXML(TElXMLDOMElement *Element)
{
	TElXMLSOAPHeaderBlockHandle OutResult;
	SBCheckError(TElXMLSOAPHeader_LoadBlockFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPHEADERBLOCK */

SB_INLINE int32_t TElXMLSOAPHeader::get_BlockCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPHeader_get_BlockCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
TElXMLSOAPHeaderBlock* TElXMLSOAPHeader::get_Blocks(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPHeader_get_Blocks(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Blocks)
		this->_Inst_Blocks = new TElXMLSOAPHeaderBlock(hOutResult, ohFalse);
	else
		this->_Inst_Blocks->updateHandle(hOutResult);
	return this->_Inst_Blocks;
}
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

void TElXMLSOAPHeader::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
	this->_Inst_Blocks = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */
}

TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLSOAPHeaderHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSOAPHeader::TElXMLSOAPHeader(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPHeader_Create((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPHeader::TElXMLSOAPHeader(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPHeader_Create((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPHeader::TElXMLSOAPHeader(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPHeader_Create_1((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPHeader::TElXMLSOAPHeader(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPHeader_Create_1((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPHeader_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPHeader_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPHeader_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPHeader_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPHeader_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPHeader_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPHeader_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLSOAPHeader::TElXMLSOAPHeader(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPHeader_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
TElXMLSOAPHeader::~TElXMLSOAPHeader()
{
#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
	delete this->_Inst_Blocks;
	this->_Inst_Blocks = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */
}
#endif /* SB_USE_CLASS_TELXMLSOAPHEADER */

#ifdef SB_USE_CLASS_TELXMLSOAPBODYENTRY

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBodyEntry::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPBodyEntry_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPBodyEntry::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPBodyEntry_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLSOAPBodyEntry::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPBodyEntry_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLSOAPBodyEntry::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLSOAPBodyEntry_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLSOAPBodyEntry::get_EncodingStyle(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPBodyEntry_get_EncodingStyle(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-371388143, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPBodyEntry::get_EncodingStyle(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPBodyEntry_get_EncodingStyle(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-371388143, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPBodyEntry::set_EncodingStyle(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPBodyEntry_set_EncodingStyle(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPBodyEntry::set_EncodingStyle(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPBodyEntry_set_EncodingStyle(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPBodyEntry::get_NamespaceURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPBodyEntry_get_NamespaceURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2039703240, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPBodyEntry::get_NamespaceURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPBodyEntry_get_NamespaceURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2039703240, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPBodyEntry::TElXMLSOAPBodyEntry(TElXMLSOAPBodyEntryHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLSOAPBodyEntry::TElXMLSOAPBodyEntry(const sb_u16string &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPBodyEntry_Create(ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPBodyEntry::TElXMLSOAPBodyEntry(const std::wstring &ANamespaceURI) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPBodyEntry_Create(reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLSOAPBODYENTRY */

#ifdef SB_USE_CLASS_TELXMLSOAPBODY

SB_INLINE void TElXMLSOAPBody::Clear()
{
	SBCheckError(TElXMLSOAPBody_Clear(_Handle));
}

SB_INLINE void TElXMLSOAPBody::ReloadEntries()
{
	SBCheckError(TElXMLSOAPBody_ReloadEntries(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPBody::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPBody_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPBody::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPBody_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE int32_t TElXMLSOAPBody::get_EntryCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLSOAPBody_get_EntryCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLSOAPBODYENTRY
TElXMLSOAPBodyEntry* TElXMLSOAPBody::get_Entries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPBody_get_Entries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Entries)
		this->_Inst_Entries = new TElXMLSOAPBodyEntry(hOutResult, ohFalse);
	else
		this->_Inst_Entries->updateHandle(hOutResult);
	return this->_Inst_Entries;
}
#endif /* SB_USE_CLASS_TELXMLSOAPBODYENTRY */

void TElXMLSOAPBody::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSOAPBODYENTRY
	this->_Inst_Entries = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPBODYENTRY */
}

TElXMLSOAPBody::TElXMLSOAPBody(TElXMLSOAPBodyHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSOAPBody::TElXMLSOAPBody(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPBody_Create((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPBody::TElXMLSOAPBody(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPBody_Create((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPBody::TElXMLSOAPBody(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPBody_Create_1((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPBody::TElXMLSOAPBody(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPBody_Create_1((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPBody::TElXMLSOAPBody(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPBody_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

TElXMLSOAPBody::TElXMLSOAPBody(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPBody_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPBody::TElXMLSOAPBody(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPBody_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

TElXMLSOAPBody::TElXMLSOAPBody(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPBody_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPBody::TElXMLSOAPBody(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPBody_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLSOAPBody::TElXMLSOAPBody(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPBody_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPBody::TElXMLSOAPBody(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPBody_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLSOAPBody::TElXMLSOAPBody(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPBody_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
TElXMLSOAPBody::~TElXMLSOAPBody()
{
#ifdef SB_USE_CLASS_TELXMLSOAPBODYENTRY
	delete this->_Inst_Entries;
	this->_Inst_Entries = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPBODYENTRY */
}
#endif /* SB_USE_CLASS_TELXMLSOAPBODY */

#ifdef SB_USE_CLASS_TELXMLSOAPENVELOPE

SB_INLINE void TElXMLSOAPEnvelope::Clear()
{
	SBCheckError(TElXMLSOAPEnvelope_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPEnvelope::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLSOAPEnvelope_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLSOAPEnvelope::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLSOAPEnvelope_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE void TElXMLSOAPEnvelope::CreateHeader()
{
	SBCheckError(TElXMLSOAPEnvelope_CreateHeader(_Handle));
}

SB_INLINE void TElXMLSOAPEnvelope::CreateBody()
{
	SBCheckError(TElXMLSOAPEnvelope_CreateBody(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLSOAPHEADER
TElXMLSOAPHeader* TElXMLSOAPEnvelope::get_Header()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPEnvelope_get_Header(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Header)
		this->_Inst_Header = new TElXMLSOAPHeader(hOutResult, ohFalse);
	else
		this->_Inst_Header->updateHandle(hOutResult);
	return this->_Inst_Header;
}
#endif /* SB_USE_CLASS_TELXMLSOAPHEADER */

#ifdef SB_USE_CLASS_TELXMLSOAPBODY
TElXMLSOAPBody* TElXMLSOAPEnvelope::get_Body()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLSOAPEnvelope_get_Body(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Body)
		this->_Inst_Body = new TElXMLSOAPBody(hOutResult, ohFalse);
	else
		this->_Inst_Body->updateHandle(hOutResult);
	return this->_Inst_Body;
}
#endif /* SB_USE_CLASS_TELXMLSOAPBODY */

void TElXMLSOAPEnvelope::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSOAPHEADER
	this->_Inst_Header = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADER */
#ifdef SB_USE_CLASS_TELXMLSOAPBODY
	this->_Inst_Body = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPBODY */
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLSOAPEnvelopeHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPElement(handle, ownHandle)
{
	initInstances();
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPEnvelope_Create((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_1((TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPEnvelope_Create_1((TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPEnvelope_Create_2(ParentElement.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPEnvelope_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPEnvelope_Create_3(ParentElement.getHandle(), BeforeChild.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPEnvelope_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (BeforeChild != NULL) ? BeforeChild->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_4(Document.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_4((Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPEnvelope_Create_4(Document.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	SBCheckError(TElXMLSOAPEnvelope_Create_4((Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_5(Document.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLSOAPEnvelope_Create_5((Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, ANamespaceURI.data(), (int32_t)ANamespaceURI.length(), AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPEnvelope_Create_5(Document.getHandle(), (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLSOAPEnvelope::TElXMLSOAPEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName) : TElXMLSOAPElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16ANamespaceURI;
	sb_to_u16string(ANamespaceURI, u16ANamespaceURI);
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLSOAPEnvelope_Create_5((Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (TSBXMLSOAPVersionRaw)AVersion, reinterpret_cast<const sb_char16_t*>(u16ANamespaceURI.data()), (int32_t)u16ANamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
TElXMLSOAPEnvelope::~TElXMLSOAPEnvelope()
{
#ifdef SB_USE_CLASS_TELXMLSOAPHEADER
	delete this->_Inst_Header;
	this->_Inst_Header = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADER */
#ifdef SB_USE_CLASS_TELXMLSOAPBODY
	delete this->_Inst_Body;
	this->_Inst_Body = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPBODY */
}
#endif /* SB_USE_CLASS_TELXMLSOAPENVELOPE */

#ifdef SB_USE_GLOBAL_PROCS_XMLSOAPCORE

void GetSOAPNamespaceURI(TSBXMLSOAPVersion Version, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSOAPCore_GetSOAPNamespaceURI((TSBXMLSOAPVersionRaw)Version, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(478004102, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetSOAPNamespaceURI(TSBXMLSOAPVersion Version, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLSOAPCore_GetSOAPNamespaceURI((TSBXMLSOAPVersionRaw)Version, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(478004102, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void SOAPSecGetElementId(TElXMLDOMElement &Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSOAPCore_SOAPSecGetElementId(Element.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1524986120, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void SOAPSecGetElementId(TElXMLDOMElement *Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLSOAPCore_SOAPSecGetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1524986120, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void SOAPSecGetElementId(TElXMLDOMElement &Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLSOAPCore_SOAPSecGetElementId(Element.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1524986120, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void SOAPSecGetElementId(TElXMLDOMElement *Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLSOAPCore_SOAPSecGetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1524986120, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void SOAPSecSetElementId(TElXMLDOMElement &Element, const sb_u16string &Value)
{
	SBCheckError(SBXMLSOAPCore_SOAPSecSetElementId(Element.getHandle(), Value.data(), (int32_t)Value.length()));
}
SB_INLINE void SOAPSecSetElementId(TElXMLDOMElement *Element, const sb_u16string &Value)
{
	SBCheckError(SBXMLSOAPCore_SOAPSecSetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Value.data(), (int32_t)Value.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void SOAPSecSetElementId(TElXMLDOMElement &Element, const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(SBXMLSOAPCore_SOAPSecSetElementId(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}
SB_INLINE void SOAPSecSetElementId(TElXMLDOMElement *Element, const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(SBXMLSOAPCore_SOAPSecSetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#endif /* SB_USE_GLOBAL_PROCS_XMLSOAPCORE */

};	/* namespace SecureBlackbox */

