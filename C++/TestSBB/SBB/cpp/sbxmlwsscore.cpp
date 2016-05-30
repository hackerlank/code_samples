#include "sbxmlwsscore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLWSSEELEMENT

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSSEElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLWSSEElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLWSSEElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLWSSEElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLWSSEElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLWSSEElement_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLWSSEElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLWSSEElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TElXMLWSSEElement::TElXMLWSSEElement(TElXMLWSSEElementHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLWSSEElement::TElXMLWSSEElement() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEElement_Create(&_Handle));
}

TElXMLWSSEElement::TElXMLWSSEElement(const sb_u16string &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEElement_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEElement::TElXMLWSSEElement(const std::wstring &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEElement_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEElement::TElXMLWSSEElement(TElXMLDOMElement &ParentElement) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEElement_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSSEElement::TElXMLWSSEElement(TElXMLDOMElement *ParentElement) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEElement_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEElement::TElXMLWSSEElement(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEElement_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSSEElement::TElXMLWSSEElement(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEElement_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEElement::TElXMLWSSEElement(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEElement_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSSEElement::TElXMLWSSEElement(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEElement_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLWSSEELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN

void TElXMLWSSEBaseToken::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEBaseToken_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1576179498, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEBaseToken::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEBaseToken_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1576179498, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEBaseToken::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEBaseToken_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEBaseToken::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEBaseToken_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(TElXMLWSSEBaseTokenHandle handle, TElOwnHandle ownHandle) : TElXMLWSSEElement(handle, ownHandle)
{
}

TElXMLWSSEBaseToken::TElXMLWSSEBaseToken() : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBaseToken_Create(&_Handle));
}

TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBaseToken_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEBaseToken_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(TElXMLDOMElement &ParentElement) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBaseToken_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(TElXMLDOMElement *ParentElement) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBaseToken_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBaseToken_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBaseToken_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEBaseToken_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSSEBaseToken::TElXMLWSSEBaseToken(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEBaseToken_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */

#ifdef SB_USE_CLASS_TELXMLWSSETEXTELEMENT

void TElXMLWSSETextElement::get_Data(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSETextElement_get_Data(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1434943960, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSETextElement::get_Data(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSETextElement_get_Data(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1434943960, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSETextElement::set_Data(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSETextElement_set_Data(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSETextElement::set_Data(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSETextElement_set_Data(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLWSSETextElement::TElXMLWSSETextElement(TElXMLWSSETextElementHandle handle, TElOwnHandle ownHandle) : TElXMLWSSEElement(handle, ownHandle)
{
}

TElXMLWSSETextElement::TElXMLWSSETextElement() : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSETextElement_Create(&_Handle));
}

TElXMLWSSETextElement::TElXMLWSSETextElement(const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSETextElement_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSETextElement::TElXMLWSSETextElement(const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSETextElement_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSETextElement::TElXMLWSSETextElement(TElXMLDOMElement &ParentElement) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSETextElement_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSSETextElement::TElXMLWSSETextElement(TElXMLDOMElement *ParentElement) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSETextElement_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSETextElement::TElXMLWSSETextElement(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSETextElement_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSSETextElement::TElXMLWSSETextElement(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSETextElement_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSETextElement::TElXMLWSSETextElement(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSETextElement_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSSETextElement::TElXMLWSSETextElement(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSETextElement_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLWSSETEXTELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSEPASSWORD

void TElXMLWSSEPassword::get_PasswordType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEPassword_get_PasswordType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-730032111, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEPassword::get_PasswordType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEPassword_get_PasswordType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-730032111, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEPassword::set_PasswordType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEPassword_set_PasswordType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEPassword::set_PasswordType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEPassword_set_PasswordType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLWSSEPassword::TElXMLWSSEPassword(TElXMLWSSEPasswordHandle handle, TElOwnHandle ownHandle) : TElXMLWSSETextElement(handle, ownHandle)
{
}

TElXMLWSSEPassword::TElXMLWSSEPassword() : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEPassword_Create(&_Handle));
}

TElXMLWSSEPassword::TElXMLWSSEPassword(const sb_u16string &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEPassword_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEPassword::TElXMLWSSEPassword(const std::wstring &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEPassword_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEPassword::TElXMLWSSEPassword(TElXMLDOMElement &ParentElement) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEPassword_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSSEPassword::TElXMLWSSEPassword(TElXMLDOMElement *ParentElement) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEPassword_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEPassword::TElXMLWSSEPassword(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEPassword_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSSEPassword::TElXMLWSSEPassword(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEPassword_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEPassword::TElXMLWSSEPassword(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEPassword_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSSEPassword::TElXMLWSSEPassword(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEPassword_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLWSSEPASSWORD */

#ifdef SB_USE_CLASS_TELXMLWSSENONCE

void TElXMLWSSENonce::get_EncodingType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSENonce_get_EncodingType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1853011137, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSENonce::get_EncodingType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSENonce_get_EncodingType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1853011137, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSENonce::set_EncodingType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSENonce_set_EncodingType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSENonce::set_EncodingType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSENonce_set_EncodingType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLWSSENonce::TElXMLWSSENonce(TElXMLWSSENonceHandle handle, TElOwnHandle ownHandle) : TElXMLWSSETextElement(handle, ownHandle)
{
}

TElXMLWSSENonce::TElXMLWSSENonce() : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSENonce_Create(&_Handle));
}

TElXMLWSSENonce::TElXMLWSSENonce(const sb_u16string &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSENonce_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSENonce::TElXMLWSSENonce(const std::wstring &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSENonce_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSENonce::TElXMLWSSENonce(TElXMLDOMElement &ParentElement) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSENonce_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSSENonce::TElXMLWSSENonce(TElXMLDOMElement *ParentElement) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSENonce_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSENonce::TElXMLWSSENonce(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSENonce_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSSENonce::TElXMLWSSENonce(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSENonce_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSENonce::TElXMLWSSENonce(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSENonce_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSSENonce::TElXMLWSSENonce(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSETextElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSENonce_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLWSSENONCE */

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME

void TElXMLWSUDateTime::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSUDateTime_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1907181709, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSUDateTime::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSUDateTime_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1907181709, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSUDateTime::set_Value(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSUDateTime_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSUDateTime::set_Value(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSUDateTime_set_Value(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSUDateTime::get_ValueType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSUDateTime_get_ValueType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1354307227, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSUDateTime::get_ValueType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSUDateTime_get_ValueType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1354307227, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSUDateTime::set_ValueType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSUDateTime_set_ValueType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSUDateTime::set_ValueType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSUDateTime_set_ValueType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElXMLWSUDateTime::get_ValueUTC()
{
	int64_t OutResult;
	SBCheckError(TElXMLWSUDateTime_get_ValueUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLWSUDateTime::set_ValueUTC(int64_t Value)
{
	SBCheckError(TElXMLWSUDateTime_set_ValueUTC(_Handle, Value));
}

TElXMLWSUDateTime::TElXMLWSUDateTime(TElXMLWSUDateTimeHandle handle, TElOwnHandle ownHandle) : TElXMLWSSEElement(handle, ownHandle)
{
}

TElXMLWSUDateTime::TElXMLWSUDateTime() : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSUDateTime_Create(&_Handle));
}

TElXMLWSUDateTime::TElXMLWSUDateTime(const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSUDateTime_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSUDateTime::TElXMLWSUDateTime(const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSUDateTime_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSUDateTime::TElXMLWSUDateTime(TElXMLDOMElement &ParentElement) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSUDateTime_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSUDateTime::TElXMLWSUDateTime(TElXMLDOMElement *ParentElement) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSUDateTime_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSUDateTime::TElXMLWSUDateTime(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSUDateTime_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSUDateTime::TElXMLWSUDateTime(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSUDateTime_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSUDateTime::TElXMLWSUDateTime(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSUDateTime_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSUDateTime::TElXMLWSUDateTime(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSUDateTime_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

#ifdef SB_USE_CLASS_TELXMLWSSEUSERNAMETOKEN

SB_INLINE void TElXMLWSSEUsernameToken::Clear()
{
	SBCheckError(TElXMLWSSEUsernameToken_Clear(_Handle));
}

SB_INLINE void TElXMLWSSEUsernameToken::CreateUsername()
{
	SBCheckError(TElXMLWSSEUsernameToken_CreateUsername(_Handle));
}

SB_INLINE void TElXMLWSSEUsernameToken::CreatePassword()
{
	SBCheckError(TElXMLWSSEUsernameToken_CreatePassword(_Handle));
}

SB_INLINE void TElXMLWSSEUsernameToken::CreateNonce()
{
	SBCheckError(TElXMLWSSEUsernameToken_CreateNonce(_Handle));
}

SB_INLINE void TElXMLWSSEUsernameToken::CreateCreated()
{
	SBCheckError(TElXMLWSSEUsernameToken_CreateCreated(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSSEUsernameToken::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLWSSEUsernameToken_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLWSSEUsernameToken::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLWSSEUsernameToken_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSETEXTELEMENT
TElXMLWSSETextElement* TElXMLWSSEUsernameToken::get_Username()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSEUsernameToken_get_Username(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Username)
		this->_Inst_Username = new TElXMLWSSETextElement(hOutResult, ohFalse);
	else
		this->_Inst_Username->updateHandle(hOutResult);
	return this->_Inst_Username;
}
#endif /* SB_USE_CLASS_TELXMLWSSETEXTELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSSEPASSWORD
TElXMLWSSEPassword* TElXMLWSSEUsernameToken::get_Password()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSEUsernameToken_get_Password(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Password)
		this->_Inst_Password = new TElXMLWSSEPassword(hOutResult, ohFalse);
	else
		this->_Inst_Password->updateHandle(hOutResult);
	return this->_Inst_Password;
}
#endif /* SB_USE_CLASS_TELXMLWSSEPASSWORD */

#ifdef SB_USE_CLASS_TELXMLWSSENONCE
TElXMLWSSENonce* TElXMLWSSEUsernameToken::get_Nonce()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSEUsernameToken_get_Nonce(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Nonce)
		this->_Inst_Nonce = new TElXMLWSSENonce(hOutResult, ohFalse);
	else
		this->_Inst_Nonce->updateHandle(hOutResult);
	return this->_Inst_Nonce;
}
#endif /* SB_USE_CLASS_TELXMLWSSENONCE */

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
TElXMLWSUDateTime* TElXMLWSSEUsernameToken::get_Created()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSEUsernameToken_get_Created(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Created)
		this->_Inst_Created = new TElXMLWSUDateTime(hOutResult, ohFalse);
	else
		this->_Inst_Created->updateHandle(hOutResult);
	return this->_Inst_Created;
}
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

SB_INLINE int64_t TElXMLWSSEUsernameToken::get_CreatedUTC()
{
	int64_t OutResult;
	SBCheckError(TElXMLWSSEUsernameToken_get_CreatedUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLWSSEUsernameToken::set_CreatedUTC(int64_t Value)
{
	SBCheckError(TElXMLWSSEUsernameToken_set_CreatedUTC(_Handle, Value));
}

void TElXMLWSSEUsernameToken::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLWSSETEXTELEMENT
	this->_Inst_Username = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSETEXTELEMENT */
#ifdef SB_USE_CLASS_TELXMLWSSEPASSWORD
	this->_Inst_Password = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSEPASSWORD */
#ifdef SB_USE_CLASS_TELXMLWSSENONCE
	this->_Inst_Nonce = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSENONCE */
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
	this->_Inst_Created = NULL;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */
}

TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(TElXMLWSSEUsernameTokenHandle handle, TElOwnHandle ownHandle) : TElXMLWSSEBaseToken(handle, ownHandle)
{
	initInstances();
}

TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken() : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSEUsernameToken_Create(&_Handle));
}

TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSEUsernameToken_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEUsernameToken_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(TElXMLDOMElement &ParentElement) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSEUsernameToken_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(TElXMLDOMElement *ParentElement) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSEUsernameToken_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSEUsernameToken_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSEUsernameToken_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEUsernameToken_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSSEUsernameToken::TElXMLWSSEUsernameToken(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEUsernameToken_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
TElXMLWSSEUsernameToken::~TElXMLWSSEUsernameToken()
{
#ifdef SB_USE_CLASS_TELXMLWSSETEXTELEMENT
	delete this->_Inst_Username;
	this->_Inst_Username = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSETEXTELEMENT */
#ifdef SB_USE_CLASS_TELXMLWSSEPASSWORD
	delete this->_Inst_Password;
	this->_Inst_Password = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSEPASSWORD */
#ifdef SB_USE_CLASS_TELXMLWSSENONCE
	delete this->_Inst_Nonce;
	this->_Inst_Nonce = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSENONCE */
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
	delete this->_Inst_Created;
	this->_Inst_Created = NULL;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */
}
#endif /* SB_USE_CLASS_TELXMLWSSEUSERNAMETOKEN */

#ifdef SB_USE_CLASS_TELXMLWSUTIMESTAMP

SB_INLINE void TElXMLWSUTimestamp::Clear()
{
	SBCheckError(TElXMLWSUTimestamp_Clear(_Handle));
}

SB_INLINE void TElXMLWSUTimestamp::CreateCreated()
{
	SBCheckError(TElXMLWSUTimestamp_CreateCreated(_Handle));
}

SB_INLINE void TElXMLWSUTimestamp::CreateExpires()
{
	SBCheckError(TElXMLWSUTimestamp_CreateExpires(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSUTimestamp::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLWSUTimestamp_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLWSUTimestamp::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLWSUTimestamp_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
TElXMLWSUDateTime* TElXMLWSUTimestamp::get_Created()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSUTimestamp_get_Created(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Created)
		this->_Inst_Created = new TElXMLWSUDateTime(hOutResult, ohFalse);
	else
		this->_Inst_Created->updateHandle(hOutResult);
	return this->_Inst_Created;
}
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

SB_INLINE int64_t TElXMLWSUTimestamp::get_CreatedUTC()
{
	int64_t OutResult;
	SBCheckError(TElXMLWSUTimestamp_get_CreatedUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLWSUTimestamp::set_CreatedUTC(int64_t Value)
{
	SBCheckError(TElXMLWSUTimestamp_set_CreatedUTC(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
TElXMLWSUDateTime* TElXMLWSUTimestamp::get_Expires()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSUTimestamp_get_Expires(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Expires)
		this->_Inst_Expires = new TElXMLWSUDateTime(hOutResult, ohFalse);
	else
		this->_Inst_Expires->updateHandle(hOutResult);
	return this->_Inst_Expires;
}
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */

SB_INLINE int64_t TElXMLWSUTimestamp::get_ExpiresUTC()
{
	int64_t OutResult;
	SBCheckError(TElXMLWSUTimestamp_get_ExpiresUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLWSUTimestamp::set_ExpiresUTC(int64_t Value)
{
	SBCheckError(TElXMLWSUTimestamp_set_ExpiresUTC(_Handle, Value));
}

void TElXMLWSUTimestamp::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
	this->_Inst_Created = NULL;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
	this->_Inst_Expires = NULL;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */
}

TElXMLWSUTimestamp::TElXMLWSUTimestamp(TElXMLWSUTimestampHandle handle, TElOwnHandle ownHandle) : TElXMLWSSEBaseToken(handle, ownHandle)
{
	initInstances();
}

TElXMLWSUTimestamp::TElXMLWSUTimestamp() : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSUTimestamp_Create(&_Handle));
}

TElXMLWSUTimestamp::TElXMLWSUTimestamp(const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSUTimestamp_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSUTimestamp::TElXMLWSUTimestamp(const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSUTimestamp_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSUTimestamp::TElXMLWSUTimestamp(TElXMLDOMElement &ParentElement) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSUTimestamp_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSUTimestamp::TElXMLWSUTimestamp(TElXMLDOMElement *ParentElement) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSUTimestamp_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSUTimestamp::TElXMLWSUTimestamp(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSUTimestamp_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSUTimestamp::TElXMLWSUTimestamp(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSUTimestamp_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSUTimestamp::TElXMLWSUTimestamp(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSUTimestamp_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSUTimestamp::TElXMLWSUTimestamp(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSUTimestamp_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
TElXMLWSUTimestamp::~TElXMLWSUTimestamp()
{
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
	delete this->_Inst_Created;
	this->_Inst_Created = NULL;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */
#ifdef SB_USE_CLASS_TELXMLWSUDATETIME
	delete this->_Inst_Expires;
	this->_Inst_Expires = NULL;
#endif /* SB_USE_CLASS_TELXMLWSUDATETIME */
}
#endif /* SB_USE_CLASS_TELXMLWSUTIMESTAMP */

#ifdef SB_USE_CLASS_TELXMLWSSEBINARYSECURITYTOKEN

SB_INLINE void TElXMLWSSEBinarySecurityToken::Clear()
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSSEBinarySecurityToken::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLWSSEBinarySecurityToken::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLWSSEBinarySecurityToken::ExtractCertificates(TElCustomCertStorage &CertStorage)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_ExtractCertificates(_Handle, CertStorage.getHandle()));
}

SB_INLINE void TElXMLWSSEBinarySecurityToken::ExtractCertificates(TElCustomCertStorage *CertStorage)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_ExtractCertificates(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLWSSEBinarySecurityToken::SetCertificate(TElX509Certificate &Cert)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_SetCertificate(_Handle, Cert.getHandle()));
}

SB_INLINE void TElXMLWSSEBinarySecurityToken::SetCertificate(TElX509Certificate *Cert)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_SetCertificate(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLWSSEBinarySecurityToken::SetCertificate(TElX509Certificate &Cert, TSBXMLWSSETokenType TokenType)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_SetCertificate_1(_Handle, Cert.getHandle(), (TSBXMLWSSETokenTypeRaw)TokenType));
}

SB_INLINE void TElXMLWSSEBinarySecurityToken::SetCertificate(TElX509Certificate *Cert, TSBXMLWSSETokenType TokenType)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_SetCertificate_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSETokenTypeRaw)TokenType));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLWSSEBinarySecurityToken::SetCertificates(TElCustomCertStorage &CertStorage)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_SetCertificates(_Handle, CertStorage.getHandle()));
}

SB_INLINE void TElXMLWSSEBinarySecurityToken::SetCertificates(TElCustomCertStorage *CertStorage)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_SetCertificates(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLWSSEBinarySecurityToken::SetCertificates(TElCustomCertStorage &CertStorage, TSBXMLWSSETokenType TokenType)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_SetCertificates_1(_Handle, CertStorage.getHandle(), (TSBXMLWSSETokenTypeRaw)TokenType));
}

SB_INLINE void TElXMLWSSEBinarySecurityToken::SetCertificates(TElCustomCertStorage *CertStorage, TSBXMLWSSETokenType TokenType)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_SetCertificates_1(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSETokenTypeRaw)TokenType));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElXMLWSSEBinarySecurityToken::get_Data(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEBinarySecurityToken_get_Data(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1654049237, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEBinarySecurityToken::get_Data(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEBinarySecurityToken_get_Data(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1654049237, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEBinarySecurityToken::set_Data(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_set_Data(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEBinarySecurityToken::set_Data(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEBinarySecurityToken_set_Data(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSSEBinarySecurityToken::get_EncodingType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEBinarySecurityToken_get_EncodingType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(853864442, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEBinarySecurityToken::get_EncodingType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEBinarySecurityToken_get_EncodingType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(853864442, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEBinarySecurityToken::set_EncodingType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_set_EncodingType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEBinarySecurityToken::set_EncodingType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEBinarySecurityToken_set_EncodingType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSSEBinarySecurityToken::get_ValueType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEBinarySecurityToken_get_ValueType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-226321803, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEBinarySecurityToken::get_ValueType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEBinarySecurityToken_get_ValueType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-226321803, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEBinarySecurityToken::set_ValueType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_set_ValueType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEBinarySecurityToken::set_ValueType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEBinarySecurityToken_set_ValueType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TSBXMLWSSETokenType TElXMLWSSEBinarySecurityToken::get_TokenType()
{
	TSBXMLWSSETokenTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLWSSEBinarySecurityToken_get_TokenType(_Handle, &OutResultRaw));
	return (TSBXMLWSSETokenType)OutResultRaw;
}

TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(TElXMLWSSEBinarySecurityTokenHandle handle, TElOwnHandle ownHandle) : TElXMLWSSEBaseToken(handle, ownHandle)
{
}

TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken() : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create(&_Handle));
}

TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(TElXMLDOMElement &ParentElement) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(TElXMLDOMElement *ParentElement) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSSEBinarySecurityToken::TElXMLWSSEBinarySecurityToken(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSEBaseToken(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSEBinarySecurityToken_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#endif /* SB_USE_CLASS_TELXMLWSSEBINARYSECURITYTOKEN */

#ifdef SB_USE_CLASS_TELXMLWSSESECURITY

SB_INLINE void TElXMLWSSESecurity::Clear()
{
	SBCheckError(TElXMLWSSESecurity_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSSESecurity::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLWSSESecurity_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLWSSESecurity::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLWSSESecurity_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
SB_INLINE void TElXMLWSSESecurity::LoadFromHeaderBlock(TElXMLSOAPHeaderBlock &AHeaderBlock)
{
	SBCheckError(TElXMLWSSESecurity_LoadFromHeaderBlock(_Handle, AHeaderBlock.getHandle()));
}

SB_INLINE void TElXMLWSSESecurity::LoadFromHeaderBlock(TElXMLSOAPHeaderBlock *AHeaderBlock)
{
	SBCheckError(TElXMLWSSESecurity_LoadFromHeaderBlock(_Handle, (AHeaderBlock != NULL) ? AHeaderBlock->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
SB_INLINE int32_t TElXMLWSSESecurity::AddToken(TElXMLWSSEBaseToken &AToken)
{
	int32_t OutResult;
	SBCheckError(TElXMLWSSESecurity_AddToken(_Handle, AToken.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLWSSESecurity::AddToken(TElXMLWSSEBaseToken *AToken)
{
	int32_t OutResult;
	SBCheckError(TElXMLWSSESecurity_AddToken(_Handle, (AToken != NULL) ? AToken->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
TElXMLSOAPHeaderBlock* TElXMLWSSESecurity::get_HeaderBlock()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSESecurity_get_HeaderBlock(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HeaderBlock)
		this->_Inst_HeaderBlock = new TElXMLSOAPHeaderBlock(hOutResult, ohFalse);
	else
		this->_Inst_HeaderBlock->updateHandle(hOutResult);
	return this->_Inst_HeaderBlock;
}

SB_INLINE void TElXMLWSSESecurity::set_HeaderBlock(TElXMLSOAPHeaderBlock &Value)
{
	SBCheckError(TElXMLWSSESecurity_set_HeaderBlock(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLWSSESecurity::set_HeaderBlock(TElXMLSOAPHeaderBlock *Value)
{
	SBCheckError(TElXMLWSSESecurity_set_HeaderBlock(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

SB_INLINE int32_t TElXMLWSSESecurity::get_TokenCount()
{
	int32_t OutResult;
	SBCheckError(TElXMLWSSESecurity_get_TokenCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
TElXMLWSSEBaseToken* TElXMLWSSESecurity::get_Tokens(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSESecurity_get_Tokens(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tokens)
		this->_Inst_Tokens = new TElXMLWSSEBaseToken(hOutResult, ohFalse);
	else
		this->_Inst_Tokens->updateHandle(hOutResult);
	return this->_Inst_Tokens;
}
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */

void TElXMLWSSESecurity::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
	this->_Inst_HeaderBlock = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */
#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
	this->_Inst_Tokens = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */
}

TElXMLWSSESecurity::TElXMLWSSESecurity(TElXMLWSSESecurityHandle handle, TElOwnHandle ownHandle) : TElXMLWSSEElement(handle, ownHandle)
{
	initInstances();
}

TElXMLWSSESecurity::TElXMLWSSESecurity() : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurity_Create(&_Handle));
}

TElXMLWSSESecurity::TElXMLWSSESecurity(const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurity_Create_1(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSESecurity::TElXMLWSSESecurity(const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSESecurity_Create_1(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSESecurity::TElXMLWSSESecurity(TElXMLDOMElement &ParentElement) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurity_Create_2(ParentElement.getHandle(), &_Handle));
}

TElXMLWSSESecurity::TElXMLWSSESecurity(TElXMLDOMElement *ParentElement) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurity_Create_2((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLWSSESecurity::TElXMLWSSESecurity(TElXMLDOMElement &ParentElement, const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurity_Create_3(ParentElement.getHandle(), AName.data(), (int32_t)AName.length(), &_Handle));
}

TElXMLWSSESecurity::TElXMLWSSESecurity(TElXMLDOMElement *ParentElement, const sb_u16string &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurity_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLWSSESecurity::TElXMLWSSESecurity(TElXMLDOMElement &ParentElement, const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSESecurity_Create_3(ParentElement.getHandle(), reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

TElXMLWSSESecurity::TElXMLWSSESecurity(TElXMLDOMElement *ParentElement, const std::wstring &AName) : TElXMLWSSEElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElXMLWSSESecurity_Create_3((ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
TElXMLWSSESecurity::~TElXMLWSSESecurity()
{
#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
	delete this->_Inst_HeaderBlock;
	this->_Inst_HeaderBlock = NULL;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */
#ifdef SB_USE_CLASS_TELXMLWSSEBASETOKEN
	delete this->_Inst_Tokens;
	this->_Inst_Tokens = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSEBASETOKEN */
}
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

#ifdef SB_USE_CLASS_TELXMLWSSEREFERENCE

SB_INLINE void TElXMLWSSEReference::Clear()
{
	SBCheckError(TElXMLWSSEReference_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSSEReference::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLWSSEReference_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLWSSEReference::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLWSSEReference_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLWSSEReference::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLWSSEReference_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLWSSEReference::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLWSSEReference_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLWSSEReference::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEReference_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-628906287, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEReference::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEReference_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-628906287, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEReference::set_URI(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEReference_set_URI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEReference::set_URI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEReference_set_URI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSSEReference::get_ValueType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEReference_get_ValueType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-249024085, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEReference::get_ValueType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEReference_get_ValueType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-249024085, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEReference::set_ValueType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEReference_set_ValueType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEReference::set_ValueType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEReference_set_ValueType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLWSSEReference::TElXMLWSSEReference(TElXMLWSSEReferenceHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLWSSEReference::TElXMLWSSEReference() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEReference_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLWSSEREFERENCE */

#ifdef SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER

SB_INLINE void TElXMLWSSEKeyIdentifier::Clear()
{
	SBCheckError(TElXMLWSSEKeyIdentifier_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSSEKeyIdentifier::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLWSSEKeyIdentifier_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLWSSEKeyIdentifier::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLWSSEKeyIdentifier_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLWSSEKeyIdentifier::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLWSSEKeyIdentifier_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLWSSEKeyIdentifier::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLWSSEKeyIdentifier_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElXMLWSSEKeyIdentifier::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1400374638, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLWSSEKeyIdentifier::set_Data(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElXMLWSSEKeyIdentifier_set_Data(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElXMLWSSEKeyIdentifier::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(97386810, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEKeyIdentifier::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(97386810, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEKeyIdentifier::set_Value(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEKeyIdentifier_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEKeyIdentifier::set_Value(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEKeyIdentifier_set_Value(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSSEKeyIdentifier::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1822939042, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEKeyIdentifier::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1822939042, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEKeyIdentifier::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEKeyIdentifier_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEKeyIdentifier::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEKeyIdentifier_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSSEKeyIdentifier::get_ValueType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_ValueType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1225827402, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEKeyIdentifier::get_ValueType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_ValueType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1225827402, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEKeyIdentifier::set_ValueType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEKeyIdentifier_set_ValueType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEKeyIdentifier::set_ValueType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEKeyIdentifier_set_ValueType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSSEKeyIdentifier::get_EncodingType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_EncodingType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1089420365, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSEKeyIdentifier::get_EncodingType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSEKeyIdentifier_get_EncodingType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1089420365, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSEKeyIdentifier::set_EncodingType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSEKeyIdentifier_set_EncodingType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSEKeyIdentifier::set_EncodingType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSEKeyIdentifier_set_EncodingType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLWSSEKeyIdentifier::TElXMLWSSEKeyIdentifier(TElXMLWSSEKeyIdentifierHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElXMLWSSEKeyIdentifier::TElXMLWSSEKeyIdentifier() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLWSSEKeyIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLWSSESECURITYTOKENREFERENCE

SB_INLINE void TElXMLWSSESecurityTokenReference::Clear()
{
	SBCheckError(TElXMLWSSESecurityTokenReference_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE void TElXMLWSSESecurityTokenReference::LoadFromXML(TElXMLDOMNode &Element)
{
	SBCheckError(TElXMLWSSESecurityTokenReference_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLWSSESecurityTokenReference::LoadFromXML(TElXMLDOMNode *Element)
{
	SBCheckError(TElXMLWSSESecurityTokenReference_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElXMLWSSESecurityTokenReference::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLWSSESecurityTokenReference_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLWSSESecurityTokenReference::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLWSSESecurityTokenReference_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODE */

void TElXMLWSSESecurityTokenReference::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSESecurityTokenReference_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1505650505, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSESecurityTokenReference::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSESecurityTokenReference_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1505650505, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSESecurityTokenReference::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSESecurityTokenReference_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSESecurityTokenReference::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSESecurityTokenReference_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSSESecurityTokenReference::get_TokenType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSESecurityTokenReference_get_TokenType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(449143255, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSESecurityTokenReference::get_TokenType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSESecurityTokenReference_get_TokenType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(449143255, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSESecurityTokenReference::set_TokenType(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSESecurityTokenReference_set_TokenType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSESecurityTokenReference::set_TokenType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSESecurityTokenReference_set_TokenType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLWSSESecurityTokenReference::get_Usage(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSESecurityTokenReference_get_Usage(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-288364004, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLWSSESecurityTokenReference::get_Usage(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLWSSESecurityTokenReference_get_Usage(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-288364004, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLWSSESecurityTokenReference::set_Usage(const sb_u16string &Value)
{
	SBCheckError(TElXMLWSSESecurityTokenReference_set_Usage(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSESecurityTokenReference::set_Usage(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLWSSESecurityTokenReference_set_Usage(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLWSSESecurityTokenReferenceType TElXMLWSSESecurityTokenReference::get_ReferenceType()
{
	TElXMLWSSESecurityTokenReferenceTypeRaw OutResultRaw = 0;
	SBCheckError(TElXMLWSSESecurityTokenReference_get_ReferenceType(_Handle, &OutResultRaw));
	return (TElXMLWSSESecurityTokenReferenceType)OutResultRaw;
}

SB_INLINE void TElXMLWSSESecurityTokenReference::set_ReferenceType(TElXMLWSSESecurityTokenReferenceType Value)
{
	SBCheckError(TElXMLWSSESecurityTokenReference_set_ReferenceType(_Handle, (TElXMLWSSESecurityTokenReferenceTypeRaw)Value));
}

#ifdef SB_USE_CLASS_TELXMLWSSEREFERENCE
TElXMLWSSEReference* TElXMLWSSESecurityTokenReference::get_Reference()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSESecurityTokenReference_get_Reference(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Reference)
		this->_Inst_Reference = new TElXMLWSSEReference(hOutResult, ohFalse);
	else
		this->_Inst_Reference->updateHandle(hOutResult);
	return this->_Inst_Reference;
}
#endif /* SB_USE_CLASS_TELXMLWSSEREFERENCE */

#ifdef SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER
TElXMLWSSEKeyIdentifier* TElXMLWSSESecurityTokenReference::get_KeyIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSESecurityTokenReference_get_KeyIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyIdentifier)
		this->_Inst_KeyIdentifier = new TElXMLWSSEKeyIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_KeyIdentifier->updateHandle(hOutResult);
	return this->_Inst_KeyIdentifier;
}
#endif /* SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLWSSESecurityTokenReference::get_EmbeddedNode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSESecurityTokenReference_get_EmbeddedNode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EmbeddedNode)
		this->_Inst_EmbeddedNode = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_EmbeddedNode->updateHandle(hOutResult);
	return this->_Inst_EmbeddedNode;
}

SB_INLINE void TElXMLWSSESecurityTokenReference::set_EmbeddedNode(TElXMLDOMNode &Value)
{
	SBCheckError(TElXMLWSSESecurityTokenReference_set_EmbeddedNode(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLWSSESecurityTokenReference::set_EmbeddedNode(TElXMLDOMNode *Value)
{
	SBCheckError(TElXMLWSSESecurityTokenReference_set_EmbeddedNode(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

void TElXMLWSSESecurityTokenReference::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLWSSEREFERENCE
	this->_Inst_Reference = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSEREFERENCE */
#ifdef SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER
	this->_Inst_KeyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_EmbeddedNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElXMLWSSESecurityTokenReference::TElXMLWSSESecurityTokenReference(TElXMLWSSESecurityTokenReferenceHandle handle, TElOwnHandle ownHandle) : TElXMLKeyInfoData(handle, ownHandle)
{
	initInstances();
}

TElXMLWSSESecurityTokenReference::TElXMLWSSESecurityTokenReference(bool OwnResources) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurityTokenReference_Create((int8_t)OwnResources, &_Handle));
}

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElXMLWSSESecurityTokenReference::TElXMLWSSESecurityTokenReference(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurityTokenReference_Create_1((int8_t)AOwnResources, Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElXMLWSSESecurityTokenReference::TElXMLWSSESecurityTokenReference(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElXMLKeyInfoData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSESecurityTokenReference_Create_1((int8_t)AOwnResources, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElXMLWSSESecurityTokenReference::~TElXMLWSSESecurityTokenReference()
{
#ifdef SB_USE_CLASS_TELXMLWSSEREFERENCE
	delete this->_Inst_Reference;
	this->_Inst_Reference = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSEREFERENCE */
#ifdef SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER
	delete this->_Inst_KeyIdentifier;
	this->_Inst_KeyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSEKEYIDENTIFIER */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_EmbeddedNode;
	this->_Inst_EmbeddedNode = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELXMLWSSESECURITYTOKENREFERENCE */

#ifdef SB_USE_GLOBAL_PROCS_XMLWSSCORE

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void WSUGetElementId(TElXMLDOMElement &Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLWSSCore_WSUGetElementId(Element.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2080141626, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void WSUGetElementId(TElXMLDOMElement *Element, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLWSSCore_WSUGetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2080141626, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WSUGetElementId(TElXMLDOMElement &Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLWSSCore_WSUGetElementId(Element.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2080141626, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void WSUGetElementId(TElXMLDOMElement *Element, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLWSSCore_WSUGetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2080141626, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void WSUSetElementId(TElXMLDOMElement &Element, const sb_u16string &Value)
{
	SBCheckError(SBXMLWSSCore_WSUSetElementId(Element.getHandle(), Value.data(), (int32_t)Value.length()));
}
SB_INLINE void WSUSetElementId(TElXMLDOMElement *Element, const sb_u16string &Value)
{
	SBCheckError(SBXMLWSSCore_WSUSetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, Value.data(), (int32_t)Value.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void WSUSetElementId(TElXMLDOMElement &Element, const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(SBXMLWSSCore_WSUSetElementId(Element.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}
SB_INLINE void WSUSetElementId(TElXMLDOMElement *Element, const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(SBXMLWSSCore_WSUSetElementId((Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void WSSETokenTypeToURI(TSBXMLWSSETokenType TokenType, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBXMLWSSCore_WSSETokenTypeToURI((TSBXMLWSSETokenTypeRaw)TokenType, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1189291544, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WSSETokenTypeToURI(TSBXMLWSSETokenType TokenType, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBXMLWSSCore_WSSETokenTypeToURI((TSBXMLWSSETokenTypeRaw)TokenType, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1189291544, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_XMLWSSCORE */

};	/* namespace SecureBlackbox */

