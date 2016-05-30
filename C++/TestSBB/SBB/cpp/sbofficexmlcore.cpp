#include "sbofficexmlcore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLELEMENT

SB_INLINE void TElOfficeOpenXMLElement::Clear()
{
	SBCheckError(TElOfficeOpenXMLElement_Clear(_Handle));
}

bool TElOfficeOpenXMLElement::get_IsModified()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLElement_get_IsModified(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeOpenXMLElement::set_IsModified(bool Value)
{
	SBCheckError(TElOfficeOpenXMLElement_set_IsModified(_Handle, (int8_t)Value));
}

TElOfficeOpenXMLElement::TElOfficeOpenXMLElement(TElOfficeOpenXMLElementHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElOfficeOpenXMLElement::TElOfficeOpenXMLElement() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLELEMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP

SB_INLINE void TElOfficeOpenXMLRelationship::Clear()
{
	SBCheckError(TElOfficeOpenXMLRelationship_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeOpenXMLRelationship::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeOpenXMLRelationship_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLRelationship::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeOpenXMLRelationship_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLRelationship::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationship_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLRelationship::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationship_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeOpenXMLRelationship::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLRelationship_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1988139510, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLRelationship::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLRelationship_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1988139510, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLRelationship::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLRelationship_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLRelationship::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLRelationship_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLRelationship::get_RelationshipType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLRelationship_get_RelationshipType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(658718039, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLRelationship::get_RelationshipType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLRelationship_get_RelationshipType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(658718039, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLRelationship::set_RelationshipType(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLRelationship_set_RelationshipType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLRelationship::set_RelationshipType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLRelationship_set_RelationshipType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLRelationship::get_Target(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLRelationship_get_Target(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1778460431, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLRelationship::get_Target(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLRelationship_get_Target(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1778460431, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLRelationship::set_Target(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLRelationship_set_Target(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLRelationship::set_Target(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLRelationship_set_Target(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TSBOfficeOpenXMLTargetMode TElOfficeOpenXMLRelationship::get_TargetMode()
{
	TSBOfficeOpenXMLTargetModeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationship_get_TargetMode(_Handle, &OutResultRaw));
	return (TSBOfficeOpenXMLTargetMode)OutResultRaw;
}

SB_INLINE void TElOfficeOpenXMLRelationship::set_TargetMode(TSBOfficeOpenXMLTargetMode Value)
{
	SBCheckError(TElOfficeOpenXMLRelationship_set_TargetMode(_Handle, (TSBOfficeOpenXMLTargetModeRaw)Value));
}

TElOfficeOpenXMLRelationship::TElOfficeOpenXMLRelationship(TElOfficeOpenXMLRelationshipHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
}

TElOfficeOpenXMLRelationship::TElOfficeOpenXMLRelationship() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLRelationship_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
SB_INLINE int32_t TElOfficeOpenXMLRelationships::Add(TElOfficeOpenXMLRelationship &ARelationship)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_Add(_Handle, ARelationship.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLRelationships::Add(TElOfficeOpenXMLRelationship *ARelationship)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_Add(_Handle, (ARelationship != NULL) ? ARelationship->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

SB_INLINE int32_t TElOfficeOpenXMLRelationships::Add(const sb_u16string &ID, const sb_u16string &Target, const sb_u16string &RelationshipType)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_Add_1(_Handle, ID.data(), (int32_t)ID.length(), Target.data(), (int32_t)Target.length(), RelationshipType.data(), (int32_t)RelationshipType.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeOpenXMLRelationships::Add(const std::wstring &ID, const std::wstring &Target, const std::wstring &RelationshipType)
{
	int32_t OutResult;
	std::string u16ID;
	sb_to_u16string(ID, u16ID);
	std::string u16Target;
	sb_to_u16string(Target, u16Target);
	std::string u16RelationshipType;
	sb_to_u16string(RelationshipType, u16RelationshipType);
	SBCheckError(TElOfficeOpenXMLRelationships_Add_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16ID.data()), (int32_t)u16ID.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Target.data()), (int32_t)u16Target.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16RelationshipType.data()), (int32_t)u16RelationshipType.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
SB_INLINE void TElOfficeOpenXMLRelationships::Insert(int32_t Index, TElOfficeOpenXMLRelationship &ARelationship)
{
	SBCheckError(TElOfficeOpenXMLRelationships_Insert(_Handle, Index, ARelationship.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLRelationships::Insert(int32_t Index, TElOfficeOpenXMLRelationship *ARelationship)
{
	SBCheckError(TElOfficeOpenXMLRelationships_Insert(_Handle, Index, (ARelationship != NULL) ? ARelationship->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

SB_INLINE void TElOfficeOpenXMLRelationships::Delete(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLRelationships_Delete(_Handle, Index));
}

SB_INLINE void TElOfficeOpenXMLRelationships::Clear()
{
	SBCheckError(TElOfficeOpenXMLRelationships_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
SB_INLINE TElOfficeOpenXMLRelationshipHandle TElOfficeOpenXMLRelationships::CreateRelationship(const sb_u16string &Target, TSBOfficeOpenXMLTargetMode TargetMode, const sb_u16string &RelationshipType, const sb_u16string &ID)
{
	TElOfficeOpenXMLRelationshipHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_CreateRelationship(_Handle, Target.data(), (int32_t)Target.length(), (TSBOfficeOpenXMLTargetModeRaw)TargetMode, RelationshipType.data(), (int32_t)RelationshipType.length(), ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElOfficeOpenXMLRelationshipHandle TElOfficeOpenXMLRelationships::CreateRelationship(const std::wstring &Target, TSBOfficeOpenXMLTargetMode TargetMode, const std::wstring &RelationshipType, const std::wstring &ID)
{
	TElOfficeOpenXMLRelationshipHandle OutResult;
	std::string u16Target;
	sb_to_u16string(Target, u16Target);
	std::string u16RelationshipType;
	sb_to_u16string(RelationshipType, u16RelationshipType);
	std::string u16ID;
	sb_to_u16string(ID, u16ID);
	SBCheckError(TElOfficeOpenXMLRelationships_CreateRelationship(_Handle, reinterpret_cast<const sb_char16_t*>(u16Target.data()), (int32_t)u16Target.length() >> 1, (TSBOfficeOpenXMLTargetModeRaw)TargetMode, reinterpret_cast<const sb_char16_t*>(u16RelationshipType.data()), (int32_t)u16RelationshipType.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16ID.data()), (int32_t)u16ID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
SB_INLINE TElOfficeOpenXMLRelationshipHandle TElOfficeOpenXMLRelationships::GetRelationshipById(const sb_u16string &ID)
{
	TElOfficeOpenXMLRelationshipHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_GetRelationshipById(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElOfficeOpenXMLRelationshipHandle TElOfficeOpenXMLRelationships::GetRelationshipById(const std::wstring &ID)
{
	TElOfficeOpenXMLRelationshipHandle OutResult;
	std::string u16ID;
	sb_to_u16string(ID, u16ID);
	SBCheckError(TElOfficeOpenXMLRelationships_GetRelationshipById(_Handle, reinterpret_cast<const sb_char16_t*>(u16ID.data()), (int32_t)u16ID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
SB_INLINE TElOfficeOpenXMLRelationshipHandle TElOfficeOpenXMLRelationships::GetRelationshipByType(const sb_u16string &RelType)
{
	TElOfficeOpenXMLRelationshipHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_GetRelationshipByType(_Handle, RelType.data(), (int32_t)RelType.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElOfficeOpenXMLRelationshipHandle TElOfficeOpenXMLRelationships::GetRelationshipByType(const std::wstring &RelType)
{
	TElOfficeOpenXMLRelationshipHandle OutResult;
	std::string u16RelType;
	sb_to_u16string(RelType, u16RelType);
	SBCheckError(TElOfficeOpenXMLRelationships_GetRelationshipByType(_Handle, reinterpret_cast<const sb_char16_t*>(u16RelType.data()), (int32_t)u16RelType.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

SB_INLINE void TElOfficeOpenXMLRelationships::SortRelationshipsById()
{
	SBCheckError(TElOfficeOpenXMLRelationships_SortRelationshipsById(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeOpenXMLRelationships::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeOpenXMLRelationships_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLRelationships::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeOpenXMLRelationships_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLRelationships::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLRelationships::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOfficeOpenXMLRelationships::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLRelationships_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
TElOfficeOpenXMLRelationship* TElOfficeOpenXMLRelationships::get_Relationships(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLRelationships_get_Relationships(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Relationships)
		this->_Inst_Relationships = new TElOfficeOpenXMLRelationship(hOutResult, ohFalse);
	else
		this->_Inst_Relationships->updateHandle(hOutResult);
	return this->_Inst_Relationships;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

void TElOfficeOpenXMLRelationships::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
	this->_Inst_Relationships = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */
}

TElOfficeOpenXMLRelationships::TElOfficeOpenXMLRelationships(TElOfficeOpenXMLRelationshipsHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLRelationships::TElOfficeOpenXMLRelationships() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLRelationships_Create(&_Handle));
}

TElOfficeOpenXMLRelationships::~TElOfficeOpenXMLRelationships()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
	delete this->_Inst_Relationships;
	this->_Inst_Relationships = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT

SB_INLINE void TElOfficeOpenXMLDefault::Clear()
{
	SBCheckError(TElOfficeOpenXMLDefault_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeOpenXMLDefault::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeOpenXMLDefault_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLDefault::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeOpenXMLDefault_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLDefault::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLDefault_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLDefault::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLDefault_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeOpenXMLDefault::get_ContentType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLDefault_get_ContentType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-578014713, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLDefault::get_ContentType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLDefault_get_ContentType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-578014713, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLDefault::set_ContentType(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLDefault_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLDefault::set_ContentType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLDefault_set_ContentType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLDefault::get_Extension(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLDefault_get_Extension(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2136707027, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLDefault::get_Extension(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLDefault_get_Extension(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2136707027, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLDefault::set_Extension(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLDefault_set_Extension(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLDefault::set_Extension(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLDefault_set_Extension(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeOpenXMLDefault::TElOfficeOpenXMLDefault(TElOfficeOpenXMLDefaultHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
}

TElOfficeOpenXMLDefault::TElOfficeOpenXMLDefault() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLDefault_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
SB_INLINE int32_t TElOfficeOpenXMLDefaultList::Add(TElOfficeOpenXMLDefault &ADefault)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLDefaultList_Add(_Handle, ADefault.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLDefaultList::Add(TElOfficeOpenXMLDefault *ADefault)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLDefaultList_Add(_Handle, (ADefault != NULL) ? ADefault->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
SB_INLINE void TElOfficeOpenXMLDefaultList::Insert(int32_t Index, TElOfficeOpenXMLDefault &ADefault)
{
	SBCheckError(TElOfficeOpenXMLDefaultList_Insert(_Handle, Index, ADefault.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLDefaultList::Insert(int32_t Index, TElOfficeOpenXMLDefault *ADefault)
{
	SBCheckError(TElOfficeOpenXMLDefaultList_Insert(_Handle, Index, (ADefault != NULL) ? ADefault->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

SB_INLINE void TElOfficeOpenXMLDefaultList::Delete(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLDefaultList_Delete(_Handle, Index));
}

SB_INLINE void TElOfficeOpenXMLDefaultList::Clear()
{
	SBCheckError(TElOfficeOpenXMLDefaultList_Clear(_Handle));
}

SB_INLINE int32_t TElOfficeOpenXMLDefaultList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLDefaultList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
TElOfficeOpenXMLDefault* TElOfficeOpenXMLDefaultList::get_DefaultItems(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLDefaultList_get_DefaultItems(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DefaultItems)
		this->_Inst_DefaultItems = new TElOfficeOpenXMLDefault(hOutResult, ohFalse);
	else
		this->_Inst_DefaultItems->updateHandle(hOutResult);
	return this->_Inst_DefaultItems;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

void TElOfficeOpenXMLDefaultList::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
	this->_Inst_DefaultItems = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */
}

TElOfficeOpenXMLDefaultList::TElOfficeOpenXMLDefaultList(TElOfficeOpenXMLDefaultListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLDefaultList::TElOfficeOpenXMLDefaultList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLDefaultList_Create(&_Handle));
}

TElOfficeOpenXMLDefaultList::~TElOfficeOpenXMLDefaultList()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
	delete this->_Inst_DefaultItems;
	this->_Inst_DefaultItems = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE

SB_INLINE void TElOfficeOpenXMLOverride::Clear()
{
	SBCheckError(TElOfficeOpenXMLOverride_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeOpenXMLOverride::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeOpenXMLOverride_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLOverride::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeOpenXMLOverride_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLOverride::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLOverride_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLOverride::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLOverride_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeOpenXMLOverride::get_ContentType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLOverride_get_ContentType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1381049018, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLOverride::get_ContentType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLOverride_get_ContentType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1381049018, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLOverride::set_ContentType(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLOverride_set_ContentType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLOverride::set_ContentType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLOverride_set_ContentType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLOverride::get_PartName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLOverride_get_PartName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1395948497, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLOverride::get_PartName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLOverride_get_PartName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1395948497, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLOverride::set_PartName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLOverride_set_PartName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLOverride::set_PartName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLOverride_set_PartName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeOpenXMLOverride::TElOfficeOpenXMLOverride(TElOfficeOpenXMLOverrideHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
}

TElOfficeOpenXMLOverride::TElOfficeOpenXMLOverride() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLOverride_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
SB_INLINE int32_t TElOfficeOpenXMLOverrideList::Add(TElOfficeOpenXMLOverride &AOverride)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLOverrideList_Add(_Handle, AOverride.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLOverrideList::Add(TElOfficeOpenXMLOverride *AOverride)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLOverrideList_Add(_Handle, (AOverride != NULL) ? AOverride->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
SB_INLINE void TElOfficeOpenXMLOverrideList::Insert(int32_t Index, TElOfficeOpenXMLOverride &AOverride)
{
	SBCheckError(TElOfficeOpenXMLOverrideList_Insert(_Handle, Index, AOverride.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLOverrideList::Insert(int32_t Index, TElOfficeOpenXMLOverride *AOverride)
{
	SBCheckError(TElOfficeOpenXMLOverrideList_Insert(_Handle, Index, (AOverride != NULL) ? AOverride->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

SB_INLINE void TElOfficeOpenXMLOverrideList::Delete(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLOverrideList_Delete(_Handle, Index));
}

SB_INLINE void TElOfficeOpenXMLOverrideList::Clear()
{
	SBCheckError(TElOfficeOpenXMLOverrideList_Clear(_Handle));
}

SB_INLINE int32_t TElOfficeOpenXMLOverrideList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLOverrideList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
TElOfficeOpenXMLOverride* TElOfficeOpenXMLOverrideList::get_OverrideItems(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLOverrideList_get_OverrideItems(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OverrideItems)
		this->_Inst_OverrideItems = new TElOfficeOpenXMLOverride(hOutResult, ohFalse);
	else
		this->_Inst_OverrideItems->updateHandle(hOutResult);
	return this->_Inst_OverrideItems;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

void TElOfficeOpenXMLOverrideList::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
	this->_Inst_OverrideItems = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */
}

TElOfficeOpenXMLOverrideList::TElOfficeOpenXMLOverrideList(TElOfficeOpenXMLOverrideListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLOverrideList::TElOfficeOpenXMLOverrideList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLOverrideList_Create(&_Handle));
}

TElOfficeOpenXMLOverrideList::~TElOfficeOpenXMLOverrideList()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
	delete this->_Inst_OverrideItems;
	this->_Inst_OverrideItems = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES

SB_INLINE void TElOfficeOpenXMLContentTypes::Clear()
{
	SBCheckError(TElOfficeOpenXMLContentTypes_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeOpenXMLContentTypes::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeOpenXMLContentTypes_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLContentTypes::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeOpenXMLContentTypes_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLContentTypes::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLContentTypes_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLContentTypes::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLContentTypes_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST
TElOfficeOpenXMLDefaultList* TElOfficeOpenXMLContentTypes::get_Defaults()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLContentTypes_get_Defaults(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Defaults)
		this->_Inst_Defaults = new TElOfficeOpenXMLDefaultList(hOutResult, ohFalse);
	else
		this->_Inst_Defaults->updateHandle(hOutResult);
	return this->_Inst_Defaults;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST
TElOfficeOpenXMLOverrideList* TElOfficeOpenXMLContentTypes::get_Overrides()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLContentTypes_get_Overrides(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Overrides)
		this->_Inst_Overrides = new TElOfficeOpenXMLOverrideList(hOutResult, ohFalse);
	else
		this->_Inst_Overrides->updateHandle(hOutResult);
	return this->_Inst_Overrides;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST */

void TElOfficeOpenXMLContentTypes::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST
	this->_Inst_Defaults = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST
	this->_Inst_Overrides = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST */
}

TElOfficeOpenXMLContentTypes::TElOfficeOpenXMLContentTypes(TElOfficeOpenXMLContentTypesHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLContentTypes::TElOfficeOpenXMLContentTypes() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLContentTypes_Create(&_Handle));
}

TElOfficeOpenXMLContentTypes::~TElOfficeOpenXMLContentTypes()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST
	delete this->_Inst_Defaults;
	this->_Inst_Defaults = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST
	delete this->_Inst_Overrides;
	this->_Inst_Overrides = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL

SB_INLINE void TElOfficeXMLDCSimpleLiteral::Clear()
{
	SBCheckError(TElOfficeXMLDCSimpleLiteral_Clear(_Handle));
}

bool TElOfficeXMLDCSimpleLiteral::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeXMLDCSimpleLiteral_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLDCSimpleLiteral::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLDCSimpleLiteral_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLDCSimpleLiteral::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLDCSimpleLiteral_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLDCSimpleLiteral::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLDCSimpleLiteral_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLDCSimpleLiteral::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLDCSimpleLiteral_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeXMLDCSimpleLiteral::get_Language(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLDCSimpleLiteral_get_Language(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1717743294, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLDCSimpleLiteral::set_Language(const std::string &Value)
{
	SBCheckError(TElOfficeXMLDCSimpleLiteral_set_Language(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOfficeXMLDCSimpleLiteral::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLDCSimpleLiteral_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-455273086, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLDCSimpleLiteral::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLDCSimpleLiteral_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-455273086, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLDCSimpleLiteral::set_Value(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLDCSimpleLiteral_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLDCSimpleLiteral::set_Value(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLDCSimpleLiteral_set_Value(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeXMLDCSimpleLiteral::TElOfficeXMLDCSimpleLiteral(TElOfficeXMLDCSimpleLiteralHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
}

TElOfficeXMLDCSimpleLiteral::TElOfficeXMLDCSimpleLiteral(const sb_u16string &AName) : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLDCSimpleLiteral_Create(AName.data(), (int32_t)AName.length(), &_Handle));
}

#ifdef SB_U16STRING_USED
TElOfficeXMLDCSimpleLiteral::TElOfficeXMLDCSimpleLiteral(const std::wstring &AName) : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	std::string u16AName;
	sb_to_u16string(AName, u16AName);
	SBCheckError(TElOfficeXMLDCSimpleLiteral_Create(reinterpret_cast<const sb_char16_t*>(u16AName.data()), (int32_t)u16AName.length() >> 1, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCDATE

SB_INLINE void TElOfficeXMLDCDate::Clear()
{
	SBCheckError(TElOfficeXMLDCDate_Clear(_Handle));
}

bool TElOfficeXMLDCDate::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeXMLDCDate_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLDCDate::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLDCDate_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLDCDate::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLDCDate_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLDCDate::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLDCDate_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLDCDate::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLDCDate_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeXMLDCDate::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLDCDate_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(33401455, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLDCDate::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLDCDate_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(33401455, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLDCDate::set_Value(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLDCDate_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLDCDate::set_Value(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLDCDate_set_Value(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElOfficeXMLDCDate::get_ValueUTC()
{
	int64_t OutResult;
	SBCheckError(TElOfficeXMLDCDate_get_ValueUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLDCDate::set_ValueUTC(int64_t Value)
{
	SBCheckError(TElOfficeXMLDCDate_set_ValueUTC(_Handle, Value));
}

TSBXMLDateTimeFormat TElOfficeXMLDCDate::get_DateTimeFormat()
{
	TSBXMLDateTimeFormatRaw OutResultRaw = 0;
	SBCheckError(TElOfficeXMLDCDate_get_DateTimeFormat(_Handle, &OutResultRaw));
	return (TSBXMLDateTimeFormat)OutResultRaw;
}

SB_INLINE void TElOfficeXMLDCDate::set_DateTimeFormat(TSBXMLDateTimeFormat Value)
{
	SBCheckError(TElOfficeXMLDCDate_set_DateTimeFormat(_Handle, (TSBXMLDateTimeFormatRaw)Value));
}

bool TElOfficeXMLDCDate::get_IncludeTimeZone()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeXMLDCDate_get_IncludeTimeZone(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeXMLDCDate::set_IncludeTimeZone(bool Value)
{
	SBCheckError(TElOfficeXMLDCDate_set_IncludeTimeZone(_Handle, (int8_t)Value));
}

TElOfficeXMLDCDate::TElOfficeXMLDCDate(TElOfficeXMLDCDateHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
}

TElOfficeXMLDCDate::TElOfficeXMLDCDate() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLDCDate_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLDCDATE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES

SB_INLINE void TElOfficeOpenXMLCoreProperties::Clear()
{
	SBCheckError(TElOfficeOpenXMLCoreProperties_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeOpenXMLCoreProperties::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeOpenXMLCoreProperties_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLCoreProperties::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeOpenXMLCoreProperties_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLCoreProperties::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLCoreProperties_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLCoreProperties::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLCoreProperties_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeOpenXMLCoreProperties::get_Category(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_Category(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-827807140, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLCoreProperties::get_Category(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_Category(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-827807140, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_Category(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_Category(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_Category(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_Category(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLCoreProperties::get_ContentStatus(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_ContentStatus(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1357645974, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLCoreProperties::get_ContentStatus(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_ContentStatus(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1357645974, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_ContentStatus(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_ContentStatus(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_ContentStatus(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_ContentStatus(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
TElOfficeXMLDCSimpleLiteral* TElOfficeOpenXMLCoreProperties::get_Creator()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLCoreProperties_get_Creator(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Creator)
		this->_Inst_Creator = new TElOfficeXMLDCSimpleLiteral(hOutResult, ohFalse);
	else
		this->_Inst_Creator->updateHandle(hOutResult);
	return this->_Inst_Creator;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
TElOfficeXMLDCSimpleLiteral* TElOfficeOpenXMLCoreProperties::get_Description()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLCoreProperties_get_Description(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Description)
		this->_Inst_Description = new TElOfficeXMLDCSimpleLiteral(hOutResult, ohFalse);
	else
		this->_Inst_Description->updateHandle(hOutResult);
	return this->_Inst_Description;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
TElOfficeXMLDCSimpleLiteral* TElOfficeOpenXMLCoreProperties::get_Identifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLCoreProperties_get_Identifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Identifier)
		this->_Inst_Identifier = new TElOfficeXMLDCSimpleLiteral(hOutResult, ohFalse);
	else
		this->_Inst_Identifier->updateHandle(hOutResult);
	return this->_Inst_Identifier;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
TElOfficeXMLDCSimpleLiteral* TElOfficeOpenXMLCoreProperties::get_Language()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLCoreProperties_get_Language(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Language)
		this->_Inst_Language = new TElOfficeXMLDCSimpleLiteral(hOutResult, ohFalse);
	else
		this->_Inst_Language->updateHandle(hOutResult);
	return this->_Inst_Language;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

void TElOfficeOpenXMLCoreProperties::get_LastModifiedBy(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_LastModifiedBy(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2014039483, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLCoreProperties::get_LastModifiedBy(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_LastModifiedBy(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2014039483, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_LastModifiedBy(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_LastModifiedBy(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_LastModifiedBy(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_LastModifiedBy(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLCoreProperties::get_Revision(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_Revision(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1517836719, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLCoreProperties::get_Revision(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_Revision(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1517836719, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_Revision(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_Revision(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_Revision(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_Revision(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
TElOfficeXMLDCSimpleLiteral* TElOfficeOpenXMLCoreProperties::get_Subject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLCoreProperties_get_Subject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subject)
		this->_Inst_Subject = new TElOfficeXMLDCSimpleLiteral(hOutResult, ohFalse);
	else
		this->_Inst_Subject->updateHandle(hOutResult);
	return this->_Inst_Subject;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
TElOfficeXMLDCSimpleLiteral* TElOfficeOpenXMLCoreProperties::get_Title()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLCoreProperties_get_Title(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Title)
		this->_Inst_Title = new TElOfficeXMLDCSimpleLiteral(hOutResult, ohFalse);
	else
		this->_Inst_Title->updateHandle(hOutResult);
	return this->_Inst_Title;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

void TElOfficeOpenXMLCoreProperties::get_Version(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_Version(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2087403817, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLCoreProperties::get_Version(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLCoreProperties_get_Version(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2087403817, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_Version(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_Version(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLCoreProperties::set_Version(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLCoreProperties_set_Version(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLCoreProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	this->_Inst_Creator = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	this->_Inst_Description = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	this->_Inst_Identifier = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	this->_Inst_Language = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	this->_Inst_Title = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
}

TElOfficeOpenXMLCoreProperties::TElOfficeOpenXMLCoreProperties(TElOfficeOpenXMLCorePropertiesHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLCoreProperties::TElOfficeOpenXMLCoreProperties() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLCoreProperties_Create(&_Handle));
}

TElOfficeOpenXMLCoreProperties::~TElOfficeOpenXMLCoreProperties()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	delete this->_Inst_Creator;
	this->_Inst_Creator = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	delete this->_Inst_Description;
	this->_Inst_Description = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	delete this->_Inst_Identifier;
	this->_Inst_Identifier = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	delete this->_Inst_Language;
	this->_Inst_Language = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	delete this->_Inst_Subject;
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
	delete this->_Inst_Title;
	this->_Inst_Title = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYDATA

SB_INLINE void TElOfficeXMLKeyData::Clear()
{
	SBCheckError(TElOfficeXMLKeyData_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLKeyData::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLKeyData_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLKeyData::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLKeyData_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLKeyData::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLKeyData_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLKeyData::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLKeyData_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOfficeXMLKeyData::get_SaltSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLKeyData_get_SaltSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLKeyData::set_SaltSize(int32_t Value)
{
	SBCheckError(TElOfficeXMLKeyData_set_SaltSize(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLKeyData::get_BlockSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLKeyData_get_BlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLKeyData::set_BlockSize(int32_t Value)
{
	SBCheckError(TElOfficeXMLKeyData_set_BlockSize(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLKeyData::get_KeyBits()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLKeyData_get_KeyBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLKeyData::set_KeyBits(int32_t Value)
{
	SBCheckError(TElOfficeXMLKeyData_set_KeyBits(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLKeyData::get_HashSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLKeyData_get_HashSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLKeyData::set_HashSize(int32_t Value)
{
	SBCheckError(TElOfficeXMLKeyData_set_HashSize(_Handle, Value));
}

void TElOfficeXMLKeyData::get_CipherAlgorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLKeyData_get_CipherAlgorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1567607358, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLKeyData::get_CipherAlgorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLKeyData_get_CipherAlgorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1567607358, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLKeyData::set_CipherAlgorithm(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLKeyData_set_CipherAlgorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLKeyData::set_CipherAlgorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLKeyData_set_CipherAlgorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLKeyData::get_CipherChaining(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLKeyData_get_CipherChaining(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-755038679, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLKeyData::get_CipherChaining(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLKeyData_get_CipherChaining(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-755038679, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLKeyData::set_CipherChaining(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLKeyData_set_CipherChaining(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLKeyData::set_CipherChaining(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLKeyData_set_CipherChaining(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLKeyData::get_HashAlgorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLKeyData_get_HashAlgorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1399059053, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLKeyData::get_HashAlgorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLKeyData_get_HashAlgorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1399059053, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLKeyData::set_HashAlgorithm(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLKeyData_set_HashAlgorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLKeyData::set_HashAlgorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLKeyData_set_HashAlgorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLKeyData::get_SaltValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLKeyData_get_SaltValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1003988636, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLKeyData::set_SaltValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLKeyData_set_SaltValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficeXMLKeyData::TElOfficeXMLKeyData(TElOfficeXMLKeyDataHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElOfficeXMLKeyData::TElOfficeXMLKeyData() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLKeyData_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLKEYDATA */

#ifdef SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY

SB_INLINE void TElOfficeXMLDataIntegrity::Clear()
{
	SBCheckError(TElOfficeXMLDataIntegrity_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLDataIntegrity::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLDataIntegrity_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLDataIntegrity::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLDataIntegrity_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLDataIntegrity::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLDataIntegrity_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLDataIntegrity::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLDataIntegrity_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeXMLDataIntegrity::get_EncryptedHmacKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLDataIntegrity_get_EncryptedHmacKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2134324377, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLDataIntegrity::set_EncryptedHmacKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLDataIntegrity_set_EncryptedHmacKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeXMLDataIntegrity::get_EncryptedHmacValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLDataIntegrity_get_EncryptedHmacValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1147525899, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLDataIntegrity::set_EncryptedHmacValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLDataIntegrity_set_EncryptedHmacValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficeXMLDataIntegrity::TElOfficeXMLDataIntegrity(TElOfficeXMLDataIntegrityHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElOfficeXMLDataIntegrity::TElOfficeXMLDataIntegrity() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLDataIntegrity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR

void TElOfficeXMLKeyEncryptor::get_URI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLKeyEncryptor_get_URI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-104741397, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLKeyEncryptor::get_URI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLKeyEncryptor_get_URI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-104741397, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElOfficeXMLKeyEncryptor::TElOfficeXMLKeyEncryptor(TElOfficeXMLKeyEncryptorHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElOfficeXMLKeyEncryptor::TElOfficeXMLKeyEncryptor() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLKeyEncryptor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
SB_INLINE int32_t TElOfficeXMLKeyEncryptors::Add(TElOfficeXMLKeyEncryptor &AKeyEncryptor)
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLKeyEncryptors_Add(_Handle, AKeyEncryptor.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeXMLKeyEncryptors::Add(TElOfficeXMLKeyEncryptor *AKeyEncryptor)
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLKeyEncryptors_Add(_Handle, (AKeyEncryptor != NULL) ? AKeyEncryptor->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
SB_INLINE void TElOfficeXMLKeyEncryptors::Insert(int32_t Index, TElOfficeXMLKeyEncryptor &AKeyEncryptor)
{
	SBCheckError(TElOfficeXMLKeyEncryptors_Insert(_Handle, Index, AKeyEncryptor.getHandle()));
}

SB_INLINE void TElOfficeXMLKeyEncryptors::Insert(int32_t Index, TElOfficeXMLKeyEncryptor *AKeyEncryptor)
{
	SBCheckError(TElOfficeXMLKeyEncryptors_Insert(_Handle, Index, (AKeyEncryptor != NULL) ? AKeyEncryptor->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

SB_INLINE void TElOfficeXMLKeyEncryptors::Delete(int32_t Index)
{
	SBCheckError(TElOfficeXMLKeyEncryptors_Delete(_Handle, Index));
}

SB_INLINE void TElOfficeXMLKeyEncryptors::Clear()
{
	SBCheckError(TElOfficeXMLKeyEncryptors_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLKeyEncryptors::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLKeyEncryptors_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLKeyEncryptors::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLKeyEncryptors_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLKeyEncryptors::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLKeyEncryptors_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLKeyEncryptors::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLKeyEncryptors_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOfficeXMLKeyEncryptors::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLKeyEncryptors_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
TElOfficeXMLKeyEncryptor* TElOfficeXMLKeyEncryptors::get_KeyEncryptors(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeXMLKeyEncryptors_get_KeyEncryptors(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyEncryptors)
		this->_Inst_KeyEncryptors = new TElOfficeXMLKeyEncryptor(hOutResult, ohFalse);
	else
		this->_Inst_KeyEncryptors->updateHandle(hOutResult);
	return this->_Inst_KeyEncryptors;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

void TElOfficeXMLKeyEncryptors::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
	this->_Inst_KeyEncryptors = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */
}

TElOfficeXMLKeyEncryptors::TElOfficeXMLKeyEncryptors(TElOfficeXMLKeyEncryptorsHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElOfficeXMLKeyEncryptors::TElOfficeXMLKeyEncryptors() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeXMLKeyEncryptors_Create(&_Handle));
}

TElOfficeXMLKeyEncryptors::~TElOfficeXMLKeyEncryptors()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
	delete this->_Inst_KeyEncryptors;
	this->_Inst_KeyEncryptors = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */
}
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS */

#ifdef SB_USE_CLASS_TELOFFICEXMLPASSWORDKEYENCRYPTOR

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::Clear()
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLPasswordKeyEncryptor::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLPasswordKeyEncryptor::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOfficeXMLPasswordKeyEncryptor::get_SaltSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_get_SaltSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_SaltSize(int32_t Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_SaltSize(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLPasswordKeyEncryptor::get_BlockSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_get_BlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_BlockSize(int32_t Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_BlockSize(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLPasswordKeyEncryptor::get_KeyBits()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_get_KeyBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_KeyBits(int32_t Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_KeyBits(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLPasswordKeyEncryptor::get_HashSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_get_HashSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_HashSize(int32_t Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_HashSize(_Handle, Value));
}

void TElOfficeXMLPasswordKeyEncryptor::get_CipherAlgorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_CipherAlgorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1252187826, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLPasswordKeyEncryptor::get_CipherAlgorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_CipherAlgorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1252187826, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_CipherAlgorithm(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_CipherAlgorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_CipherAlgorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_CipherAlgorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLPasswordKeyEncryptor::get_CipherChaining(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_CipherChaining(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1488995694, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLPasswordKeyEncryptor::get_CipherChaining(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_CipherChaining(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1488995694, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_CipherChaining(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_CipherChaining(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_CipherChaining(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_CipherChaining(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLPasswordKeyEncryptor::get_HashAlgorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_HashAlgorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-166287736, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLPasswordKeyEncryptor::get_HashAlgorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_HashAlgorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-166287736, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_HashAlgorithm(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_HashAlgorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_HashAlgorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_HashAlgorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLPasswordKeyEncryptor::get_SaltValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_SaltValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1900816166, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_SaltValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_SaltValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElOfficeXMLPasswordKeyEncryptor::get_SpinCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_get_SpinCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_SpinCount(int32_t Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_SpinCount(_Handle, Value));
}

void TElOfficeXMLPasswordKeyEncryptor::get_EncryptedVerifierHashInput(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_EncryptedVerifierHashInput(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-204195702, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_EncryptedVerifierHashInput(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_EncryptedVerifierHashInput(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeXMLPasswordKeyEncryptor::get_EncryptedVerifierHashValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_EncryptedVerifierHashValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(915100265, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_EncryptedVerifierHashValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_EncryptedVerifierHashValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeXMLPasswordKeyEncryptor::get_EncryptedKeyValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLPasswordKeyEncryptor_get_EncryptedKeyValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1288739055, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLPasswordKeyEncryptor::set_EncryptedKeyValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_set_EncryptedKeyValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficeXMLPasswordKeyEncryptor::TElOfficeXMLPasswordKeyEncryptor(TElOfficeXMLPasswordKeyEncryptorHandle handle, TElOwnHandle ownHandle) : TElOfficeXMLKeyEncryptor(handle, ownHandle)
{
}

TElOfficeXMLPasswordKeyEncryptor::TElOfficeXMLPasswordKeyEncryptor() : TElOfficeXMLKeyEncryptor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLPasswordKeyEncryptor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLPASSWORDKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEXMLENCRYPTION

SB_INLINE void TElOfficeXMLEncryption::Clear()
{
	SBCheckError(TElOfficeXMLEncryption_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLEncryption::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLEncryption_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLEncryption::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLEncryption_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLEncryption::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLEncryption_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLEncryption::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLEncryption_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY
TElOfficeXMLDataIntegrity* TElOfficeXMLEncryption::get_DataIntegrity()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeXMLEncryption_get_DataIntegrity(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataIntegrity)
		this->_Inst_DataIntegrity = new TElOfficeXMLDataIntegrity(hOutResult, ohFalse);
	else
		this->_Inst_DataIntegrity->updateHandle(hOutResult);
	return this->_Inst_DataIntegrity;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYDATA
TElOfficeXMLKeyData* TElOfficeXMLEncryption::get_KeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeXMLEncryption_get_KeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyData)
		this->_Inst_KeyData = new TElOfficeXMLKeyData(hOutResult, ohFalse);
	else
		this->_Inst_KeyData->updateHandle(hOutResult);
	return this->_Inst_KeyData;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYDATA */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS
TElOfficeXMLKeyEncryptors* TElOfficeXMLEncryption::get_KeyEncryptors()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeXMLEncryption_get_KeyEncryptors(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyEncryptors)
		this->_Inst_KeyEncryptors = new TElOfficeXMLKeyEncryptors(hOutResult, ohFalse);
	else
		this->_Inst_KeyEncryptors->updateHandle(hOutResult);
	return this->_Inst_KeyEncryptors;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS */

void TElOfficeXMLEncryption::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY
	this->_Inst_DataIntegrity = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY */
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYDATA
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYDATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS
	this->_Inst_KeyEncryptors = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS */
}

TElOfficeXMLEncryption::TElOfficeXMLEncryption(TElOfficeXMLEncryptionHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElOfficeXMLEncryption::TElOfficeXMLEncryption() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeXMLEncryption_Create(&_Handle));
}

TElOfficeXMLEncryption::~TElOfficeXMLEncryption()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY
	delete this->_Inst_DataIntegrity;
	this->_Inst_DataIntegrity = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY */
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYDATA
	delete this->_Inst_KeyData;
	this->_Inst_KeyData = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYDATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS
	delete this->_Inst_KeyEncryptors;
	this->_Inst_KeyEncryptors = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS */
}
#endif /* SB_USE_CLASS_TELOFFICEXMLENCRYPTION */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME

SB_INLINE void TElOfficeXMLSignatureTime::Clear()
{
	SBCheckError(TElOfficeXMLSignatureTime_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLSignatureTime::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLSignatureTime_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLSignatureTime::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLSignatureTime_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLSignatureTime::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLSignatureTime_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLSignatureTime::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLSignatureTime_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeXMLSignatureTime::get_Format(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureTime_get_Format(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1483281771, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureTime::get_Format(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureTime_get_Format(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1483281771, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureTime::set_Format(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureTime_set_Format(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureTime::set_Format(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureTime_set_Format(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureTime::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureTime_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-499268069, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureTime::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureTime_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-499268069, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureTime::set_Value(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureTime_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureTime::set_Value(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureTime_set_Value(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElOfficeXMLSignatureTime::get_ValueUTC()
{
	int64_t OutResult;
	SBCheckError(TElOfficeXMLSignatureTime_get_ValueUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSignatureTime::set_ValueUTC(int64_t Value)
{
	SBCheckError(TElOfficeXMLSignatureTime_set_ValueUTC(_Handle, Value));
}

TElOfficeXMLSignatureTime::TElOfficeXMLSignatureTime(TElOfficeXMLSignatureTimeHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElOfficeXMLSignatureTime::TElOfficeXMLSignatureTime() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLSignatureTime_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPTRANSFORM

void TElOfficeOpenXMLRelationshipTransform::GetDefaultTransformAlgorithmURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLRelationshipTransform_GetDefaultTransformAlgorithmURI((sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2060801548, 0, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLRelationshipTransform::GetDefaultTransformAlgorithmURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLRelationshipTransform_GetDefaultTransformAlgorithmURI(NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2060801548, 0, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElOfficeOpenXMLRelationshipTransform::GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLRelationshipTransform_GetDefaultTransformAlgorithmURI_1(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2060801548, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLRelationshipTransform::GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLRelationshipTransform_GetDefaultTransformAlgorithmURI_1(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2060801548, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

bool TElOfficeOpenXMLRelationshipTransform::IsTransformAlgorithmSupported(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_IsTransformAlgorithmSupported(Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElOfficeOpenXMLRelationshipTransform::IsTransformAlgorithmSupported(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_IsTransformAlgorithmSupported(reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElOfficeOpenXMLRelationshipTransform::IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_IsTransformAlgorithmSupported_1(_Handle, Algorithm.data(), (int32_t)Algorithm.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElOfficeOpenXMLRelationshipTransform::IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm)
{
	std::string u16Algorithm;
	sb_to_u16string(Algorithm, u16Algorithm);
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_IsTransformAlgorithmSupported_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Algorithm.data()), (int32_t)u16Algorithm.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElOfficeOpenXMLRelationshipTransform::Clear()
{
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_Clear(_Handle));
}

SB_INLINE int32_t TElOfficeOpenXMLRelationshipTransform::AddSourceId(const sb_u16string &SourceId)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_AddSourceId(_Handle, SourceId.data(), (int32_t)SourceId.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeOpenXMLRelationshipTransform::AddSourceId(const std::wstring &SourceId)
{
	int32_t OutResult;
	std::string u16SourceId;
	sb_to_u16string(SourceId, u16SourceId);
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_AddSourceId(_Handle, reinterpret_cast<const sb_char16_t*>(u16SourceId.data()), (int32_t)u16SourceId.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElOfficeOpenXMLRelationshipTransform::AddSourceType(const sb_u16string &SourceType)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_AddSourceType(_Handle, SourceType.data(), (int32_t)SourceType.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeOpenXMLRelationshipTransform::AddSourceType(const std::wstring &SourceType)
{
	int32_t OutResult;
	std::string u16SourceType;
	sb_to_u16string(SourceType, u16SourceType);
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_AddSourceType(_Handle, reinterpret_cast<const sb_char16_t*>(u16SourceType.data()), (int32_t)u16SourceType.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElOfficeOpenXMLRelationshipTransform::DeleteSourceId(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_DeleteSourceId(_Handle, Index));
}

SB_INLINE void TElOfficeOpenXMLRelationshipTransform::DeleteSourceType(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_DeleteSourceType(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeOpenXMLRelationshipTransform::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLRelationshipTransform::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLRelationshipTransform::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeOpenXMLRelationshipTransform::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

TSBTransformedDataType TElOfficeOpenXMLRelationshipTransform::TransformData(const std::vector<uint8_t> &Data)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_TransformData(_Handle, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TSBTransformedDataType TElOfficeOpenXMLRelationshipTransform::TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_TransformData_1(_Handle, Node.getHandle(), Reference.getHandle(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElOfficeOpenXMLRelationshipTransform::TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_TransformData_1(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, (Reference != NULL) ? Reference->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
TSBTransformedDataType TElOfficeOpenXMLRelationshipTransform::TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_TransformData_2(_Handle, Nodes.getHandle(), SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}

TSBTransformedDataType TElOfficeOpenXMLRelationshipTransform::TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference)
{
	TSBTransformedDataTypeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_TransformData_2(_Handle, (Nodes != NULL) ? Nodes->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Reference), (int32_t)Reference.size(), &OutResultRaw));
	return (TSBTransformedDataType)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElOfficeOpenXMLRelationshipTransform::TransformNode(TElXMLDOMNode &Node)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_TransformNode(_Handle, Node.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElOfficeOpenXMLRelationshipTransform::TransformNode(TElXMLDOMNode *Node)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_TransformNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE TClassHandle TElOfficeOpenXMLRelationshipTransform::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLRelationshipTransform::get_SourceIdCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_get_SourceIdCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLRelationshipTransform::get_SourceTypeCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_get_SourceTypeCount(_Handle, &OutResult));
	return OutResult;
}

void TElOfficeOpenXMLRelationshipTransform::get_SourceIds(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLRelationshipTransform_get_SourceIds(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1766373945, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLRelationshipTransform::get_SourceIds(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLRelationshipTransform_get_SourceIds(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1766373945, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLRelationshipTransform::get_SourceTypes(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLRelationshipTransform_get_SourceTypes(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-933108686, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLRelationshipTransform::get_SourceTypes(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLRelationshipTransform_get_SourceTypes(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-933108686, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElOfficeOpenXMLRelationshipTransform::TElOfficeOpenXMLRelationshipTransform(TElOfficeOpenXMLRelationshipTransformHandle handle, TElOwnHandle ownHandle) : TElXMLTransform(handle, ownHandle)
{
}

TElOfficeOpenXMLRelationshipTransform::TElOfficeOpenXMLRelationshipTransform() : TElXMLTransform(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLRelationshipTransform_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPTRANSFORM */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1

SB_INLINE void TElOfficeXMLSignatureInfoV1::Clear()
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
bool TElOfficeXMLSignatureInfoV1::CheckReferences(TElXMLReferenceList &Refs)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeXMLSignatureInfoV1_CheckReferences(_Handle, Refs.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeXMLSignatureInfoV1::CheckReferences(TElXMLReferenceList *Refs)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeXMLSignatureInfoV1_CheckReferences(_Handle, (Refs != NULL) ? Refs->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
SB_INLINE void TElOfficeXMLSignatureInfoV1::CreateReferences(TElXMLReferenceList &Refs, TElXMLDigestMethod DigestMethod)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_CreateReferences(_Handle, Refs.getHandle(), (TElXMLDigestMethodRaw)DigestMethod));
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::CreateReferences(TElXMLReferenceList *Refs, TElXMLDigestMethod DigestMethod)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_CreateReferences(_Handle, (Refs != NULL) ? Refs->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod));
}
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLOBJECTLIST
SB_INLINE void TElOfficeXMLSignatureInfoV1::CreateObjects(TElXMLObjectList &Objects, const sb_u16string &Target, TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_CreateObjects(_Handle, Objects.getHandle(), Target.data(), (int32_t)Target.length(), Document.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::CreateObjects(TElXMLObjectList *Objects, const sb_u16string &Target, TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_CreateObjects(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, Target.data(), (int32_t)Target.length(), (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::CreateObjects(TElXMLObjectList &Objects, const std::wstring &Target, TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	std::string u16Target;
	sb_to_u16string(Target, u16Target);
	SBCheckError(TElOfficeXMLSignatureInfoV1_CreateObjects(_Handle, Objects.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Target.data()), (int32_t)u16Target.length() >> 1, Document.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::CreateObjects(TElXMLObjectList *Objects, const std::wstring &Target, TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	std::string u16Target;
	sb_to_u16string(Target, u16Target);
	SBCheckError(TElOfficeXMLSignatureInfoV1_CreateObjects(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Target.data()), (int32_t)u16Target.length() >> 1, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLOBJECTLIST */

#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
SB_INLINE void TElOfficeXMLSignatureInfoV1::LoadFromObjectList(TElXMLObjectList &Objects)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_LoadFromObjectList(_Handle, Objects.getHandle()));
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::LoadFromObjectList(TElXMLObjectList *Objects)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_LoadFromObjectList(_Handle, (Objects != NULL) ? Objects->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */

bool TElOfficeXMLSignatureInfoV1::get_Included()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeXMLSignatureInfoV1_get_Included(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_Included(bool Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_Included(_Handle, (int8_t)Value));
}

void TElOfficeXMLSignatureInfoV1::get_ApplicationVersion(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_ApplicationVersion(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1605837511, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_ApplicationVersion(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_ApplicationVersion(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1605837511, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_ApplicationVersion(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_ApplicationVersion(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_ApplicationVersion(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_ApplicationVersion(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElOfficeXMLSignatureInfoV1::get_ColorDepth()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLSignatureInfoV1_get_ColorDepth(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_ColorDepth(int32_t Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_ColorDepth(_Handle, Value));
}

void TElOfficeXMLSignatureInfoV1::get_DelegateSuggestedSigner(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSigner(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-857214124, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_DelegateSuggestedSigner(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSigner(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-857214124, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_DelegateSuggestedSigner(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSigner(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_DelegateSuggestedSigner(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSigner(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureInfoV1::get_DelegateSuggestedSigner2(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSigner2(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1541594210, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_DelegateSuggestedSigner2(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSigner2(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1541594210, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_DelegateSuggestedSigner2(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSigner2(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_DelegateSuggestedSigner2(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSigner2(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureInfoV1::get_DelegateSuggestedSignerEmail(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSignerEmail(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1926441544, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_DelegateSuggestedSignerEmail(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSignerEmail(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1926441544, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_DelegateSuggestedSignerEmail(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSignerEmail(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_DelegateSuggestedSignerEmail(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSignerEmail(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElOfficeXMLSignatureInfoV1::get_HorizontalResolution()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLSignatureInfoV1_get_HorizontalResolution(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_HorizontalResolution(int32_t Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_HorizontalResolution(_Handle, Value));
}

void TElOfficeXMLSignatureInfoV1::get_ManifestHashAlgorithm(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_ManifestHashAlgorithm(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1641202620, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_ManifestHashAlgorithm(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_ManifestHashAlgorithm(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1641202620, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_ManifestHashAlgorithm(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_ManifestHashAlgorithm(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_ManifestHashAlgorithm(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_ManifestHashAlgorithm(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElOfficeXMLSignatureInfoV1::get_Monitors()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLSignatureInfoV1_get_Monitors(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_Monitors(int32_t Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_Monitors(_Handle, Value));
}

void TElOfficeXMLSignatureInfoV1::get_OfficeVersion(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_OfficeVersion(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-366684934, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_OfficeVersion(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_OfficeVersion(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-366684934, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_OfficeVersion(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_OfficeVersion(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_OfficeVersion(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_OfficeVersion(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureInfoV1::get_SetupID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SetupID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-338532916, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_SetupID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SetupID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-338532916, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SetupID(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SetupID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SetupID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SetupID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureInfoV1::get_SignatureComments(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureComments(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-953225723, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_SignatureComments(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureComments(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-953225723, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureComments(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureComments(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureComments(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureComments(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureInfoV1::get_SignatureImage(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureImage(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1916885363, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureImage(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureImage(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElOfficeXMLSignatureInfoV1::get_SignatureProviderDetails()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLSignatureInfoV1_get_SignatureProviderDetails(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureProviderDetails(int32_t Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureProviderDetails(_Handle, Value));
}

void TElOfficeXMLSignatureInfoV1::get_SignatureProviderId(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureProviderId(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(861831050, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_SignatureProviderId(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureProviderId(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(861831050, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureProviderId(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureProviderId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureProviderId(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureProviderId(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureInfoV1::get_SignatureProviderUrl(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureProviderUrl(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1090451185, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_SignatureProviderUrl(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureProviderUrl(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1090451185, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureProviderUrl(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureProviderUrl(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureProviderUrl(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureProviderUrl(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureInfoV1::get_SignatureText(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureText(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-169820001, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_SignatureText(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_SignatureText(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-169820001, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureText(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureText(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureText(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureText(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElOfficeXMLSignatureInfoV1::get_SignatureType()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLSignatureInfoV1_get_SignatureType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_SignatureType(int32_t Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_SignatureType(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLSignatureInfoV1::get_VerticalResolution()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLSignatureInfoV1_get_VerticalResolution(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_VerticalResolution(int32_t Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_VerticalResolution(_Handle, Value));
}

void TElOfficeXMLSignatureInfoV1::get_WindowsVersion(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_WindowsVersion(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-115538176, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureInfoV1::get_WindowsVersion(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_WindowsVersion(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-115538176, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_WindowsVersion(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_WindowsVersion(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureInfoV1::set_WindowsVersion(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_WindowsVersion(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureInfoV1::get_ValidSignatureLnImage(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_ValidSignatureLnImage(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1673339568, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_ValidSignatureLnImage(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_ValidSignatureLnImage(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeXMLSignatureInfoV1::get_InvalidSignatureLnImage(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeXMLSignatureInfoV1_get_InvalidSignatureLnImage(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(517510345, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeXMLSignatureInfoV1::set_InvalidSignatureLnImage(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_set_InvalidSignatureLnImage(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOfficeXMLSignatureInfoV1::TElOfficeXMLSignatureInfoV1(TElOfficeXMLSignatureInfoV1Handle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOfficeXMLSignatureInfoV1::TElOfficeXMLSignatureInfoV1() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLSignatureInfoV1_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */

#ifdef SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION

SB_INLINE void TElOfficeXMLSpotLocation::Clear()
{
	SBCheckError(TElOfficeXMLSpotLocation_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLSpotLocation::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLSpotLocation_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLSpotLocation::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLSpotLocation_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLSpotLocation::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLSpotLocation_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLSpotLocation::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLSpotLocation_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeXMLSpotLocation::get_PageURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSpotLocation_get_PageURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(585057936, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSpotLocation::get_PageURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSpotLocation_get_PageURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(585057936, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSpotLocation::set_PageURI(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSpotLocation_set_PageURI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSpotLocation::set_PageURI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSpotLocation_set_PageURI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE double TElOfficeXMLSpotLocation::get_StartX()
{
	double OutResult;
	SBCheckError(TElOfficeXMLSpotLocation_get_StartX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSpotLocation::set_StartX(double Value)
{
	SBCheckError(TElOfficeXMLSpotLocation_set_StartX(_Handle, Value));
}

SB_INLINE double TElOfficeXMLSpotLocation::get_StartY()
{
	double OutResult;
	SBCheckError(TElOfficeXMLSpotLocation_get_StartY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSpotLocation::set_StartY(double Value)
{
	SBCheckError(TElOfficeXMLSpotLocation_set_StartY(_Handle, Value));
}

TElOfficeXMLSpotLocation::TElOfficeXMLSpotLocation(TElOfficeXMLSpotLocationHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElOfficeXMLSpotLocation::TElOfficeXMLSpotLocation() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLSpotLocation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREDEFINITION

SB_INLINE void TElOfficeXMLSignatureDefinition::Clear()
{
	SBCheckError(TElOfficeXMLSignatureDefinition_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLSignatureDefinition::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLSignatureDefinition_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLSignatureDefinition::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLSignatureDefinition_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLSignatureDefinition::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLSignatureDefinition_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLSignatureDefinition::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLSignatureDefinition_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeXMLSignatureDefinition::get_Intent(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_Intent(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1859872542, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureDefinition::get_Intent(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_Intent(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1859872542, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureDefinition::set_Intent(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureDefinition_set_Intent(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureDefinition::set_Intent(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureDefinition_set_Intent(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureDefinition::get_SignBy(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_SignBy(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-2010094196, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureDefinition::get_SignBy(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_SignBy(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-2010094196, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureDefinition::set_SignBy(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SignBy(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureDefinition::set_SignBy(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SignBy(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElOfficeXMLSignatureDefinition::get_SignByUTC()
{
	int64_t OutResult;
	SBCheckError(TElOfficeXMLSignatureDefinition_get_SignByUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLSignatureDefinition::set_SignByUTC(int64_t Value)
{
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SignByUTC(_Handle, Value));
}

void TElOfficeXMLSignatureDefinition::get_SigningLocation(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_SigningLocation(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-655547144, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureDefinition::get_SigningLocation(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_SigningLocation(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-655547144, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureDefinition::set_SigningLocation(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SigningLocation(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureDefinition::set_SigningLocation(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SigningLocation(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureDefinition::get_SignerName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_SignerName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1738159890, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureDefinition::get_SignerName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_SignerName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1738159890, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureDefinition::set_SignerName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SignerName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureDefinition::set_SignerName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SignerName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeXMLSignatureDefinition::get_SpotID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_SpotID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1973875732, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLSignatureDefinition::get_SpotID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLSignatureDefinition_get_SpotID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1973875732, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLSignatureDefinition::set_SpotID(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SpotID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLSignatureDefinition::set_SpotID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLSignatureDefinition_set_SpotID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION
TElOfficeXMLSpotLocation* TElOfficeXMLSignatureDefinition::get_SpotLocation()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeXMLSignatureDefinition_get_SpotLocation(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SpotLocation)
		this->_Inst_SpotLocation = new TElOfficeXMLSpotLocation(hOutResult, ohFalse);
	else
		this->_Inst_SpotLocation->updateHandle(hOutResult);
	return this->_Inst_SpotLocation;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION */

void TElOfficeXMLSignatureDefinition::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION
	this->_Inst_SpotLocation = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION */
}

TElOfficeXMLSignatureDefinition::TElOfficeXMLSignatureDefinition(TElOfficeXMLSignatureDefinitionHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElOfficeXMLSignatureDefinition::TElOfficeXMLSignatureDefinition() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeXMLSignatureDefinition_Create(&_Handle));
}

TElOfficeXMLSignatureDefinition::~TElOfficeXMLSignatureDefinition()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION
	delete this->_Inst_SpotLocation;
	this->_Inst_SpotLocation = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION */
}
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREDEFINITION */

#ifdef SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENTSEQUENCE

SB_INLINE int32_t TElOfficeXMLFixedDocumentSequence::Add(const sb_u16string &DocRef)
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLFixedDocumentSequence_Add(_Handle, DocRef.data(), (int32_t)DocRef.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeXMLFixedDocumentSequence::Add(const std::wstring &DocRef)
{
	int32_t OutResult;
	std::string u16DocRef;
	sb_to_u16string(DocRef, u16DocRef);
	SBCheckError(TElOfficeXMLFixedDocumentSequence_Add(_Handle, reinterpret_cast<const sb_char16_t*>(u16DocRef.data()), (int32_t)u16DocRef.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElOfficeXMLFixedDocumentSequence::Delete(int32_t Index)
{
	SBCheckError(TElOfficeXMLFixedDocumentSequence_Delete(_Handle, Index));
}

SB_INLINE void TElOfficeXMLFixedDocumentSequence::Clear()
{
	SBCheckError(TElOfficeXMLFixedDocumentSequence_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLFixedDocumentSequence::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLFixedDocumentSequence_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLFixedDocumentSequence::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLFixedDocumentSequence_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLFixedDocumentSequence::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLFixedDocumentSequence_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLFixedDocumentSequence::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLFixedDocumentSequence_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOfficeXMLFixedDocumentSequence::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLFixedDocumentSequence_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElOfficeXMLFixedDocumentSequence::get_DocumentReferences(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLFixedDocumentSequence_get_DocumentReferences(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-625651289, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLFixedDocumentSequence::get_DocumentReferences(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLFixedDocumentSequence_get_DocumentReferences(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-625651289, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElOfficeXMLFixedDocumentSequence::TElOfficeXMLFixedDocumentSequence(TElOfficeXMLFixedDocumentSequenceHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElOfficeXMLFixedDocumentSequence::TElOfficeXMLFixedDocumentSequence() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLFixedDocumentSequence_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENTSEQUENCE */

#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT

SB_INLINE int32_t TElOfficeXMLPageContent::AddLinkTarget(const sb_u16string &Name)
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPageContent_AddLinkTarget(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeXMLPageContent::AddLinkTarget(const std::wstring &Name)
{
	int32_t OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElOfficeXMLPageContent_AddLinkTarget(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElOfficeXMLPageContent::DeleteLinkTarget(int32_t Index)
{
	SBCheckError(TElOfficeXMLPageContent_DeleteLinkTarget(_Handle, Index));
}

SB_INLINE void TElOfficeXMLPageContent::Clear()
{
	SBCheckError(TElOfficeXMLPageContent_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLPageContent::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLPageContent_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLPageContent::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLPageContent_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLPageContent::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLPageContent_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLPageContent::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLPageContent_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOfficeXMLPageContent::get_Source(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLPageContent_get_Source(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1662997969, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLPageContent::get_Source(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLPageContent_get_Source(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1662997969, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeXMLPageContent::set_Source(const sb_u16string &Value)
{
	SBCheckError(TElOfficeXMLPageContent_set_Source(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeXMLPageContent::set_Source(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeXMLPageContent_set_Source(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElOfficeXMLPageContent::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPageContent_get_Width(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLPageContent::set_Width(int32_t Value)
{
	SBCheckError(TElOfficeXMLPageContent_set_Width(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLPageContent::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPageContent_get_Height(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeXMLPageContent::set_Height(int32_t Value)
{
	SBCheckError(TElOfficeXMLPageContent_set_Height(_Handle, Value));
}

SB_INLINE int32_t TElOfficeXMLPageContent::get_LinkTargetCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLPageContent_get_LinkTargetCount(_Handle, &OutResult));
	return OutResult;
}

void TElOfficeXMLPageContent::get_LinkTargets(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeXMLPageContent_get_LinkTargets(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(385774551, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeXMLPageContent::get_LinkTargets(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeXMLPageContent_get_LinkTargets(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(385774551, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElOfficeXMLPageContent::TElOfficeXMLPageContent(TElOfficeXMLPageContentHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
}

TElOfficeXMLPageContent::TElOfficeXMLPageContent() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeXMLPageContent_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */

#ifdef SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENT

#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
SB_INLINE int32_t TElOfficeXMLFixedDocument::Add(TElOfficeXMLPageContent &PageContent)
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLFixedDocument_Add(_Handle, PageContent.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeXMLFixedDocument::Add(TElOfficeXMLPageContent *PageContent)
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLFixedDocument_Add(_Handle, (PageContent != NULL) ? PageContent->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */

SB_INLINE void TElOfficeXMLFixedDocument::Delete(int32_t Index)
{
	SBCheckError(TElOfficeXMLFixedDocument_Delete(_Handle, Index));
}

SB_INLINE void TElOfficeXMLFixedDocument::Clear()
{
	SBCheckError(TElOfficeXMLFixedDocument_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOfficeXMLFixedDocument::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOfficeXMLFixedDocument_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOfficeXMLFixedDocument::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOfficeXMLFixedDocument_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOfficeXMLFixedDocument::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLFixedDocument_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOfficeXMLFixedDocument::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOfficeXMLFixedDocument_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOfficeXMLFixedDocument::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeXMLFixedDocument_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
TElOfficeXMLPageContent* TElOfficeXMLFixedDocument::get_PageContents(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeXMLFixedDocument_get_PageContents(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PageContents)
		this->_Inst_PageContents = new TElOfficeXMLPageContent(hOutResult, ohFalse);
	else
		this->_Inst_PageContents->updateHandle(hOutResult);
	return this->_Inst_PageContents;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */

void TElOfficeXMLFixedDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
	this->_Inst_PageContents = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */
}

TElOfficeXMLFixedDocument::TElOfficeXMLFixedDocument(TElOfficeXMLFixedDocumentHandle handle, TElOwnHandle ownHandle) : TElXMLCustomElement(handle, ownHandle)
{
	initInstances();
}

TElOfficeXMLFixedDocument::TElOfficeXMLFixedDocument() : TElXMLCustomElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeXMLFixedDocument_Create(&_Handle));
}

TElOfficeXMLFixedDocument::~TElOfficeXMLFixedDocument()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
	delete this->_Inst_PageContents;
	this->_Inst_PageContents = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */
}
#endif /* SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENT */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM

SB_INLINE void TElOpenOfficeXMLManifestAlgorithm::Clear()
{
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOpenOfficeXMLManifestAlgorithm::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOpenOfficeXMLManifestAlgorithm::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestAlgorithm::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestAlgorithm::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOpenOfficeXMLManifestAlgorithm::get_AlgorithmName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeXMLManifestAlgorithm_get_AlgorithmName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(286051589, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOpenOfficeXMLManifestAlgorithm::get_AlgorithmName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOpenOfficeXMLManifestAlgorithm_get_AlgorithmName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(286051589, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOpenOfficeXMLManifestAlgorithm::set_AlgorithmName(const sb_u16string &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_set_AlgorithmName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOpenOfficeXMLManifestAlgorithm::set_AlgorithmName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_set_AlgorithmName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOpenOfficeXMLManifestAlgorithm::get_IV(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOpenOfficeXMLManifestAlgorithm_get_IV(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1097412376, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOpenOfficeXMLManifestAlgorithm::set_IV(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_set_IV(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOpenOfficeXMLManifestAlgorithm::TElOpenOfficeXMLManifestAlgorithm(TElOpenOfficeXMLManifestAlgorithmHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
}

TElOpenOfficeXMLManifestAlgorithm::TElOpenOfficeXMLManifestAlgorithm() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeXMLManifestAlgorithm_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION

SB_INLINE void TElOpenOfficeXMLManifestKeyDerivation::Clear()
{
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOpenOfficeXMLManifestKeyDerivation::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOpenOfficeXMLManifestKeyDerivation::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestKeyDerivation::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestKeyDerivation::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOpenOfficeXMLManifestKeyDerivation::get_IterationCount()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_get_IterationCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOpenOfficeXMLManifestKeyDerivation::set_IterationCount(int32_t Value)
{
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_set_IterationCount(_Handle, Value));
}

void TElOpenOfficeXMLManifestKeyDerivation::get_KeyDerivationName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeXMLManifestKeyDerivation_get_KeyDerivationName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1722159515, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOpenOfficeXMLManifestKeyDerivation::get_KeyDerivationName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOpenOfficeXMLManifestKeyDerivation_get_KeyDerivationName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1722159515, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOpenOfficeXMLManifestKeyDerivation::set_KeyDerivationName(const sb_u16string &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_set_KeyDerivationName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOpenOfficeXMLManifestKeyDerivation::set_KeyDerivationName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_set_KeyDerivationName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElOpenOfficeXMLManifestKeyDerivation::get_KeySize()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_get_KeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOpenOfficeXMLManifestKeyDerivation::set_KeySize(int32_t Value)
{
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_set_KeySize(_Handle, Value));
}

void TElOpenOfficeXMLManifestKeyDerivation::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOpenOfficeXMLManifestKeyDerivation_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2094983757, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOpenOfficeXMLManifestKeyDerivation::set_Salt(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_set_Salt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOpenOfficeXMLManifestKeyDerivation::TElOpenOfficeXMLManifestKeyDerivation(TElOpenOfficeXMLManifestKeyDerivationHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
}

TElOpenOfficeXMLManifestKeyDerivation::TElOpenOfficeXMLManifestKeyDerivation() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeXMLManifestKeyDerivation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION

SB_INLINE void TElOpenOfficeXMLManifestStartKeyGeneration::Clear()
{
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOpenOfficeXMLManifestStartKeyGeneration::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOpenOfficeXMLManifestStartKeyGeneration::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestStartKeyGeneration::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestStartKeyGeneration::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOpenOfficeXMLManifestStartKeyGeneration::get_KeySize()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_get_KeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOpenOfficeXMLManifestStartKeyGeneration::set_KeySize(int32_t Value)
{
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_set_KeySize(_Handle, Value));
}

void TElOpenOfficeXMLManifestStartKeyGeneration::get_StartKeyGenerationName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeXMLManifestStartKeyGeneration_get_StartKeyGenerationName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1899420940, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOpenOfficeXMLManifestStartKeyGeneration::get_StartKeyGenerationName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOpenOfficeXMLManifestStartKeyGeneration_get_StartKeyGenerationName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1899420940, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOpenOfficeXMLManifestStartKeyGeneration::set_StartKeyGenerationName(const sb_u16string &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_set_StartKeyGenerationName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOpenOfficeXMLManifestStartKeyGeneration::set_StartKeyGenerationName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_set_StartKeyGenerationName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOpenOfficeXMLManifestStartKeyGeneration::TElOpenOfficeXMLManifestStartKeyGeneration(TElOpenOfficeXMLManifestStartKeyGenerationHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
}

TElOpenOfficeXMLManifestStartKeyGeneration::TElOpenOfficeXMLManifestStartKeyGeneration() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeXMLManifestStartKeyGeneration_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA

SB_INLINE void TElOpenOfficeXMLManifestEncryptionData::Clear()
{
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOpenOfficeXMLManifestEncryptionData::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOpenOfficeXMLManifestEncryptionData::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestEncryptionData::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestEncryptionData::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

void TElOpenOfficeXMLManifestEncryptionData::get_Checksum(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOpenOfficeXMLManifestEncryptionData_get_Checksum(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1421802494, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOpenOfficeXMLManifestEncryptionData::set_Checksum(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_set_Checksum(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOpenOfficeXMLManifestEncryptionData::get_ChecksumType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeXMLManifestEncryptionData_get_ChecksumType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(147735416, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOpenOfficeXMLManifestEncryptionData::get_ChecksumType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOpenOfficeXMLManifestEncryptionData_get_ChecksumType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(147735416, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOpenOfficeXMLManifestEncryptionData::set_ChecksumType(const sb_u16string &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_set_ChecksumType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOpenOfficeXMLManifestEncryptionData::set_ChecksumType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_set_ChecksumType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM
TElOpenOfficeXMLManifestAlgorithm* TElOpenOfficeXMLManifestEncryptionData::get_Algorithm()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_get_Algorithm(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Algorithm)
		this->_Inst_Algorithm = new TElOpenOfficeXMLManifestAlgorithm(hOutResult, ohFalse);
	else
		this->_Inst_Algorithm->updateHandle(hOutResult);
	return this->_Inst_Algorithm;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION
TElOpenOfficeXMLManifestKeyDerivation* TElOpenOfficeXMLManifestEncryptionData::get_KeyDerivation()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_get_KeyDerivation(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyDerivation)
		this->_Inst_KeyDerivation = new TElOpenOfficeXMLManifestKeyDerivation(hOutResult, ohFalse);
	else
		this->_Inst_KeyDerivation->updateHandle(hOutResult);
	return this->_Inst_KeyDerivation;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION
TElOpenOfficeXMLManifestStartKeyGeneration* TElOpenOfficeXMLManifestEncryptionData::get_StartKeyGeneration()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_get_StartKeyGeneration(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StartKeyGeneration)
		this->_Inst_StartKeyGeneration = new TElOpenOfficeXMLManifestStartKeyGeneration(hOutResult, ohFalse);
	else
		this->_Inst_StartKeyGeneration->updateHandle(hOutResult);
	return this->_Inst_StartKeyGeneration;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION */

void TElOpenOfficeXMLManifestEncryptionData::initInstances()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM
	this->_Inst_Algorithm = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM */
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION
	this->_Inst_KeyDerivation = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION */
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION
	this->_Inst_StartKeyGeneration = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION */
}

TElOpenOfficeXMLManifestEncryptionData::TElOpenOfficeXMLManifestEncryptionData(TElOpenOfficeXMLManifestEncryptionDataHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
	initInstances();
}

TElOpenOfficeXMLManifestEncryptionData::TElOpenOfficeXMLManifestEncryptionData() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficeXMLManifestEncryptionData_Create(&_Handle));
}

TElOpenOfficeXMLManifestEncryptionData::~TElOpenOfficeXMLManifestEncryptionData()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM
	delete this->_Inst_Algorithm;
	this->_Inst_Algorithm = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM */
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION
	delete this->_Inst_KeyDerivation;
	this->_Inst_KeyDerivation = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION */
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION
	delete this->_Inst_StartKeyGeneration;
	this->_Inst_StartKeyGeneration = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION */
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY

SB_INLINE void TElOpenOfficeXMLManifestFileEntry::Clear()
{
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOpenOfficeXMLManifestFileEntry::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestFileEntry::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifestFileEntry::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

bool TElOpenOfficeXMLManifestFileEntry::get_IsEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_get_IsEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA
TElOpenOfficeXMLManifestEncryptionData* TElOpenOfficeXMLManifestFileEntry::get_EncryptionData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_get_EncryptionData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionData)
		this->_Inst_EncryptionData = new TElOpenOfficeXMLManifestEncryptionData(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionData->updateHandle(hOutResult);
	return this->_Inst_EncryptionData;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA */

void TElOpenOfficeXMLManifestFileEntry::get_FullPath(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeXMLManifestFileEntry_get_FullPath(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1551237872, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOpenOfficeXMLManifestFileEntry::get_FullPath(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOpenOfficeXMLManifestFileEntry_get_FullPath(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1551237872, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_FullPath(const sb_u16string &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_FullPath(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_FullPath(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_FullPath(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOpenOfficeXMLManifestFileEntry::get_MediaType(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeXMLManifestFileEntry_get_MediaType(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-863833276, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOpenOfficeXMLManifestFileEntry::get_MediaType(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOpenOfficeXMLManifestFileEntry_get_MediaType(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-863833276, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_MediaType(const sb_u16string &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_MediaType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_MediaType(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_MediaType(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOpenOfficeXMLManifestFileEntry::get_PreferredViewMode(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeXMLManifestFileEntry_get_PreferredViewMode(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1023042605, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOpenOfficeXMLManifestFileEntry::get_PreferredViewMode(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOpenOfficeXMLManifestFileEntry_get_PreferredViewMode(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1023042605, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_PreferredViewMode(const sb_u16string &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_PreferredViewMode(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_PreferredViewMode(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_PreferredViewMode(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElOpenOfficeXMLManifestFileEntry::get_Size()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_Size(int32_t Value)
{
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_Size(_Handle, Value));
}

void TElOpenOfficeXMLManifestFileEntry::get_Version(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeXMLManifestFileEntry_get_Version(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1049693767, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOpenOfficeXMLManifestFileEntry::get_Version(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOpenOfficeXMLManifestFileEntry_get_Version(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1049693767, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_Version(const sb_u16string &Value)
{
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_Version(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOpenOfficeXMLManifestFileEntry::set_Version(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_set_Version(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOpenOfficeXMLManifestFileEntry::initInstances()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA
	this->_Inst_EncryptionData = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA */
}

TElOpenOfficeXMLManifestFileEntry::TElOpenOfficeXMLManifestFileEntry(TElOpenOfficeXMLManifestFileEntryHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
	initInstances();
}

TElOpenOfficeXMLManifestFileEntry::TElOpenOfficeXMLManifestFileEntry() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficeXMLManifestFileEntry_Create(&_Handle));
}

TElOpenOfficeXMLManifestFileEntry::~TElOpenOfficeXMLManifestFileEntry()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA
	delete this->_Inst_EncryptionData;
	this->_Inst_EncryptionData = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA */
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
SB_INLINE int32_t TElOpenOfficeXMLManifest::Add(TElOpenOfficeXMLManifestFileEntry &AFileEntry)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeXMLManifest_Add(_Handle, AFileEntry.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOpenOfficeXMLManifest::Add(TElOpenOfficeXMLManifestFileEntry *AFileEntry)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeXMLManifest_Add(_Handle, (AFileEntry != NULL) ? AFileEntry->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

SB_INLINE int32_t TElOpenOfficeXMLManifest::Add(const sb_u16string &FullPath, const sb_u16string &MediaType)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeXMLManifest_Add_1(_Handle, FullPath.data(), (int32_t)FullPath.length(), MediaType.data(), (int32_t)MediaType.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOpenOfficeXMLManifest::Add(const std::wstring &FullPath, const std::wstring &MediaType)
{
	int32_t OutResult;
	std::string u16FullPath;
	sb_to_u16string(FullPath, u16FullPath);
	std::string u16MediaType;
	sb_to_u16string(MediaType, u16MediaType);
	SBCheckError(TElOpenOfficeXMLManifest_Add_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16FullPath.data()), (int32_t)u16FullPath.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16MediaType.data()), (int32_t)u16MediaType.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
SB_INLINE void TElOpenOfficeXMLManifest::Insert(int32_t Index, TElOpenOfficeXMLManifestFileEntry &AFileEntry)
{
	SBCheckError(TElOpenOfficeXMLManifest_Insert(_Handle, Index, AFileEntry.getHandle()));
}

SB_INLINE void TElOpenOfficeXMLManifest::Insert(int32_t Index, TElOpenOfficeXMLManifestFileEntry *AFileEntry)
{
	SBCheckError(TElOpenOfficeXMLManifest_Insert(_Handle, Index, (AFileEntry != NULL) ? AFileEntry->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

SB_INLINE void TElOpenOfficeXMLManifest::Delete(int32_t Index)
{
	SBCheckError(TElOpenOfficeXMLManifest_Delete(_Handle, Index));
}

SB_INLINE void TElOpenOfficeXMLManifest::Clear()
{
	SBCheckError(TElOpenOfficeXMLManifest_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
SB_INLINE TElOpenOfficeXMLManifestFileEntryHandle TElOpenOfficeXMLManifest::GetFileEntryByFullPath(const sb_u16string &FullPath)
{
	TElOpenOfficeXMLManifestFileEntryHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifest_GetFileEntryByFullPath(_Handle, FullPath.data(), (int32_t)FullPath.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElOpenOfficeXMLManifestFileEntryHandle TElOpenOfficeXMLManifest::GetFileEntryByFullPath(const std::wstring &FullPath)
{
	TElOpenOfficeXMLManifestFileEntryHandle OutResult;
	std::string u16FullPath;
	sb_to_u16string(FullPath, u16FullPath);
	SBCheckError(TElOpenOfficeXMLManifest_GetFileEntryByFullPath(_Handle, reinterpret_cast<const sb_char16_t*>(u16FullPath.data()), (int32_t)u16FullPath.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElOpenOfficeXMLManifest::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElOpenOfficeXMLManifest_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElOpenOfficeXMLManifest::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElOpenOfficeXMLManifest_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifest::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifest_SaveToXML(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElOpenOfficeXMLManifest::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElOpenOfficeXMLManifest_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

SB_INLINE int32_t TElOpenOfficeXMLManifest::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeXMLManifest_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
TElOpenOfficeXMLManifestFileEntry* TElOpenOfficeXMLManifest::get_FileEntries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeXMLManifest_get_FileEntries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileEntries)
		this->_Inst_FileEntries = new TElOpenOfficeXMLManifestFileEntry(hOutResult, ohFalse);
	else
		this->_Inst_FileEntries->updateHandle(hOutResult);
	return this->_Inst_FileEntries;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

void TElOpenOfficeXMLManifest::initInstances()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
	this->_Inst_FileEntries = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */
}

TElOpenOfficeXMLManifest::TElOpenOfficeXMLManifest(TElOpenOfficeXMLManifestHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLElement(handle, ownHandle)
{
	initInstances();
}

TElOpenOfficeXMLManifest::TElOpenOfficeXMLManifest() : TElOfficeOpenXMLElement(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficeXMLManifest_Create(&_Handle));
}

TElOpenOfficeXMLManifest::~TElOpenOfficeXMLManifest()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
	delete this->_Inst_FileEntries;
	this->_Inst_FileEntries = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST */

#ifdef SB_USE_GLOBAL_PROCS_OFFICEXMLCORE

bool IsValidPartIRI(const sb_u16string &IRI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBOfficeXMLCore_IsValidPartIRI(IRI.data(), (int32_t)IRI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool IsValidPartIRI(const std::wstring &IRI)
{
	std::string u16IRI;
	sb_to_u16string(IRI, u16IRI);
	int8_t OutResultRaw = 0;
	SBCheckError(SBOfficeXMLCore_IsValidPartIRI(reinterpret_cast<const sb_char16_t*>(u16IRI.data()), (int32_t)u16IRI.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool IsValidPartURI(const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBOfficeXMLCore_IsValidPartURI(URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void ConvertPartIRIToURI(const sb_u16string &IRI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_ConvertPartIRIToURI(IRI.data(), (int32_t)IRI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(801477801, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertPartIRIToURI(const std::wstring &IRI, std::string &OutResult)
{
	std::string u16IRI;
	sb_to_u16string(IRI, u16IRI);
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_ConvertPartIRIToURI(reinterpret_cast<const sb_char16_t*>(u16IRI.data()), (int32_t)u16IRI.length() >> 1, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(801477801, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

void ConvertPartURIToIRI(const std::string &URI, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_ConvertPartURIToIRI(URI.data(), (int32_t)URI.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-9801094, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertPartURIToIRI(const std::string &URI, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_ConvertPartURIToIRI(URI.data(), (int32_t)URI.length(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-9801094, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t ComparePartIRI(const sb_u16string &X, const sb_u16string &Y)
{
	int32_t OutResult;
	SBCheckError(SBOfficeXMLCore_ComparePartIRI(X.data(), (int32_t)X.length(), Y.data(), (int32_t)Y.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t ComparePartIRI(const std::wstring &X, const std::wstring &Y)
{
	int32_t OutResult;
	std::string u16X;
	sb_to_u16string(X, u16X);
	std::string u16Y;
	sb_to_u16string(Y, u16Y);
	SBCheckError(SBOfficeXMLCore_ComparePartIRI(reinterpret_cast<const sb_char16_t*>(u16X.data()), (int32_t)u16X.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Y.data()), (int32_t)u16Y.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t ComparePartURI(const std::string &X, const std::string &Y)
{
	int32_t OutResult;
	SBCheckError(SBOfficeXMLCore_ComparePartURI(X.data(), (int32_t)X.length(), Y.data(), (int32_t)Y.length(), &OutResult));
	return OutResult;
}

void NormalizePartIRI(const sb_u16string &IRI, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_NormalizePartIRI(IRI.data(), (int32_t)IRI.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-37187060, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void NormalizePartIRI(const std::wstring &IRI, std::wstring &OutResult)
{
	std::string u16IRI;
	sb_to_u16string(IRI, u16IRI);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_NormalizePartIRI(reinterpret_cast<const sb_char16_t*>(u16IRI.data()), (int32_t)u16IRI.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-37187060, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void NormalizePartURI(const std::string &URI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_NormalizePartURI(URI.data(), (int32_t)URI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1803625732, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ResolveRelativePartIRI(const sb_u16string &BaseIRI, const sb_u16string &TargetIRI, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_ResolveRelativePartIRI(BaseIRI.data(), (int32_t)BaseIRI.length(), TargetIRI.data(), (int32_t)TargetIRI.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1132668677, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ResolveRelativePartIRI(const std::wstring &BaseIRI, const std::wstring &TargetIRI, std::wstring &OutResult)
{
	std::string u16BaseIRI;
	sb_to_u16string(BaseIRI, u16BaseIRI);
	std::string u16TargetIRI;
	sb_to_u16string(TargetIRI, u16TargetIRI);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_ResolveRelativePartIRI(reinterpret_cast<const sb_char16_t*>(u16BaseIRI.data()), (int32_t)u16BaseIRI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16TargetIRI.data()), (int32_t)u16TargetIRI.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1132668677, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void ResolveRelativePartURI(const std::string &BaseURI, const std::string &TargetURI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_ResolveRelativePartURI(BaseURI.data(), (int32_t)BaseURI.length(), TargetURI.data(), (int32_t)TargetURI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1291373468, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetRelativePartURI(const std::string &URI, const std::string &BaseURI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GetRelativePartURI(URI.data(), (int32_t)URI.length(), BaseURI.data(), (int32_t)BaseURI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-506918966, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetRelationshipURI(const std::string &PartURI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GetRelationshipURI(PartURI.data(), (int32_t)PartURI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(854082343, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetPartURIExtension(const std::string &URI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GetPartURIExtension(URI.data(), (int32_t)URI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1795341552, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetPartURIPath(const std::string &URI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GetPartURIPath(URI.data(), (int32_t)URI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1261753645, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetPartURIName(const std::string &URI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GetPartURIName(URI.data(), (int32_t)URI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1011110045, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetPartURIQueryComponent(const std::string &URI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GetPartURIQueryComponent(URI.data(), (int32_t)URI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1837785038, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void RemovePartURIExtension(const std::string &URI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_RemovePartURIExtension(URI.data(), (int32_t)URI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1570077630, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void RemovePartIRIQueryComponent(const sb_u16string &IRI, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_RemovePartIRIQueryComponent(IRI.data(), (int32_t)IRI.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1733538700, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void RemovePartIRIQueryComponent(const std::wstring &IRI, std::wstring &OutResult)
{
	std::string u16IRI;
	sb_to_u16string(IRI, u16IRI);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_RemovePartIRIQueryComponent(reinterpret_cast<const sb_char16_t*>(u16IRI.data()), (int32_t)u16IRI.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1733538700, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void RemovePartURIQueryComponent(const std::string &URI, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_RemovePartURIQueryComponent(URI.data(), (int32_t)URI.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1249695014, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetValueFromQueryComponent(const std::string &Query, const std::string &Key, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GetValueFromQueryComponent(Query.data(), (int32_t)Query.length(), Key.data(), (int32_t)Key.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1202203801, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool IsLogicalItemSuffixName(const std::string &SuffixName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBOfficeXMLCore_IsLogicalItemSuffixName(SuffixName.data(), (int32_t)SuffixName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

int32_t ParseLogicalItemSuffixName(const std::string &SuffixName, bool &IsLast)
{
	int32_t OutResult;
	int8_t IsLastRaw = (int8_t)IsLast;
	SBCheckError(SBOfficeXMLCore_ParseLogicalItemSuffixName(SuffixName.data(), (int32_t)SuffixName.length(), &IsLastRaw, &OutResult));
	IsLast = (IsLastRaw != 0);
	return OutResult;
}

void FormatLogicalItemSuffixName(int32_t PieceNumber, bool IsLast, bool SkipSlash, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_FormatLogicalItemSuffixName(PieceNumber, (int8_t)IsLast, (int8_t)SkipSlash, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1812580396, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DecodeXMLEntities(const sb_u16string &Str, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_DecodeXMLEntities(Str.data(), (int32_t)Str.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1747653219, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void DecodeXMLEntities(const std::wstring &Str, std::wstring &OutResult)
{
	std::string u16Str;
	sb_to_u16string(Str, u16Str);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_DecodeXMLEntities(reinterpret_cast<const sb_char16_t*>(u16Str.data()), (int32_t)u16Str.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1747653219, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void EncodeXMLEntities(const sb_u16string &Str, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_EncodeXMLEntities(Str.data(), (int32_t)Str.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-601103557, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void EncodeXMLEntities(const std::wstring &Str, std::wstring &OutResult)
{
	std::string u16Str;
	sb_to_u16string(Str, u16Str);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_EncodeXMLEntities(reinterpret_cast<const sb_char16_t*>(u16Str.data()), (int32_t)u16Str.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-601103557, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void DecodeXMLName(const sb_u16string &Str, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_DecodeXMLName(Str.data(), (int32_t)Str.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1816909424, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void DecodeXMLName(const std::wstring &Str, std::wstring &OutResult)
{
	std::string u16Str;
	sb_to_u16string(Str, u16Str);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_DecodeXMLName(reinterpret_cast<const sb_char16_t*>(u16Str.data()), (int32_t)u16Str.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1816909424, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void EncodeXMLNameSimple(const sb_u16string &Str, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_EncodeXMLNameSimple(Str.data(), (int32_t)Str.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1030837033, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void EncodeXMLNameSimple(const std::wstring &Str, std::wstring &OutResult)
{
	std::string u16Str;
	sb_to_u16string(Str, u16Str);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_EncodeXMLNameSimple(reinterpret_cast<const sb_char16_t*>(u16Str.data()), (int32_t)u16Str.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1030837033, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
void GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationships &Relationships, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GenerateUniqueIdForRelationship(Relationships.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(842750698, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationships *Relationships, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOfficeXMLCore_GenerateUniqueIdForRelationship((Relationships != NULL) ? Relationships->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(842750698, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationships &Relationships, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_GenerateUniqueIdForRelationship(Relationships.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(842750698, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
void GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationships *Relationships, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBOfficeXMLCore_GenerateUniqueIdForRelationship((Relationships != NULL) ? Relationships->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(842750698, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

TSBOfficeOpenXMLDocumentType GetOpenXMLDocumentTypeFromContentType(const std::string &ContentType)
{
	TSBOfficeOpenXMLDocumentTypeRaw OutResultRaw = 0;
	SBCheckError(SBOfficeXMLCore_GetOpenXMLDocumentTypeFromContentType(ContentType.data(), (int32_t)ContentType.length(), &OutResultRaw));
	return (TSBOfficeOpenXMLDocumentType)OutResultRaw;
}

TSBOpenOfficeDocumentType GetOpenDocumentTypeFromMimeType(const std::string &MimeType)
{
	TSBOpenOfficeDocumentTypeRaw OutResultRaw = 0;
	SBCheckError(SBOfficeXMLCore_GetOpenDocumentTypeFromMimeType(MimeType.data(), (int32_t)MimeType.length(), &OutResultRaw));
	return (TSBOpenOfficeDocumentType)OutResultRaw;
}

SB_INLINE int32_t WideCompareStrOrdinal(const sb_u16string &S1, const sb_u16string &S2)
{
	int32_t OutResult;
	SBCheckError(SBOfficeXMLCore_WideCompareStrOrdinal(S1.data(), (int32_t)S1.length(), S2.data(), (int32_t)S2.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t WideCompareStrOrdinal(const std::wstring &S1, const std::wstring &S2)
{
	int32_t OutResult;
	std::string u16S1;
	sb_to_u16string(S1, u16S1);
	std::string u16S2;
	sb_to_u16string(S2, u16S2);
	SBCheckError(SBOfficeXMLCore_WideCompareStrOrdinal(reinterpret_cast<const sb_char16_t*>(u16S1.data()), (int32_t)u16S1.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16S2.data()), (int32_t)u16S2.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_OFFICEXMLCORE */

};	/* namespace SecureBlackbox */

